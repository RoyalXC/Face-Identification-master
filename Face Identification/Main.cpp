#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <Windows.h>
#include "arcsoft_fsdk_face_detection.h"
#include "merror.h"
#include <opencv2/opencv.hpp> 
#include <cv.h>
#include "arcsoft_fsdk_face_tracking.h"
#include <thread>

using namespace cv;
using namespace std;

#define WORKBUF_SIZE        (40*1024*1024)
#define APPID		(char*)"H38Mv4gHhdR1dwKq8r3sjZSDKRpna4JWVRY7un6uhQFC"			//APPID
#define SDKKey		(char*)"6VMPpuSm7EMfQ8oeTFHWb817n9G9yJgDCX6R5DnmnJ4J"			//SDKKey

int main()
{
	MRESULT nRet = MERR_UNKNOWN;
	MHandle hEngine = nullptr;
	MInt32 nScale = 16;
	MInt32 nMaxFace = 2;
	MByte *pWorkMem = (MByte *)malloc(WORKBUF_SIZE);
	if (pWorkMem == nullptr)
	{
		return -1;
	}
	nRet = AFD_FSDK_InitialFaceEngine(APPID, SDKKey, pWorkMem, WORKBUF_SIZE, &hEngine, AFD_FSDK_OPF_0_HIGHER_EXT, nScale, nMaxFace);
	if (nRet != MOK)
	{
		return -1;
	}

	MHandle FTEngine = nullptr;
	MByte *TpWorkMem = (MByte *)malloc(WORKBUF_SIZE);
	AFT_FSDK_InitialFaceEngine(APPID, (char*)"6VMPpuSm7EMfQ8oeTFHWb7zzck11GcdVXxyNNmoYjCbU", TpWorkMem, WORKBUF_SIZE, &FTEngine, AFT_FSDK_OPF_0_HIGHER_EXT, nScale, nMaxFace);

	ASVLOFFSCREEN offInput = { 0 };
	offInput.u32PixelArrayFormat = ASVL_PAF_RGB24_B8G8R8;
	offInput.ppu8Plane[0] = nullptr;

	VideoCapture capture("E:\\1\\1.mp4");
	Mat gray;
	Mat edges;

	while (1)
	{
		Mat frame;
		capture >> frame;

		//Mat Result(frame.size(), CV_8UC3, Scalar(120, 120, 120));
		Mat Result = frame;

		//flip(frame, frame, 1);
		if (frame.empty())
		{
			printf("--(!) No captured frame -- Break!");
			break;
		}
		else
		{
			offInput.i32Width = frame.cols;
			offInput.i32Height = frame.rows;
			offInput.ppu8Plane[0] = frame.data;
			offInput.pi32Pitch[0] = offInput.i32Width * 3;

			LPAFD_FSDK_FACERES	FaceRes = nullptr;
			nRet = AFD_FSDK_StillImageFaceDetection(hEngine, &offInput, &FaceRes);

			LPAFT_FSDK_FACERES	TFaceRes = nullptr;

			AFT_FSDK_FaceFeatureDetect(FTEngine, &offInput, &TFaceRes);


			if (nRet != MOK)
			{
				fprintf(stderr, "Face Detection failed, error code: %d\n", nRet);
			}
			else
			{
				for (int i = 0; i < FaceRes->nFace; ++i)
				{
					Point p1, p2;
					p1.x = FaceRes->rcFace[i].left;
					p1.y = FaceRes->rcFace[i].top;

					p2.x = FaceRes->rcFace[i].right;
					p2.y = FaceRes->rcFace[i].bottom;

					rectangle(Result, p1, p2, CV_RGB(0, 255, 0), 2);

					p1.x = TFaceRes->rcFace[i].left;
					p1.y = TFaceRes->rcFace[i].top;

					p2.x = TFaceRes->rcFace[i].right;
					p2.y = TFaceRes->rcFace[i].bottom;

					rectangle(Result, p1, p2, CV_RGB(255, 0, 0), 2);
					//fprintf(stdout, "Face[%d]: rect[%d,%d,%d,%d], Face orient: %d\n", i, FaceRes->rcFace[i].left, FaceRes->rcFace[i].top, FaceRes->rcFace[i].right, FaceRes->rcFace[i].bottom, FaceRes->lfaceOrient[i]);
				}
			}
			imshow("Result", Result);
		}

		waitKey(23);
	}

	nRet = AFD_FSDK_UninitialFaceEngine(hEngine);
	if (nRet != MOK)
	{
		fprintf(stderr, "UninitialFaceEngine failed , errorcode is %d \n", nRet);
	}
	free(offInput.ppu8Plane[0]);
	free(pWorkMem);
	return 0;
}