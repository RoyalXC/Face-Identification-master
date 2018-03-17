#include "FaceIdentification.h"
 
//构造函数
FaceIdentification::FaceIdentification()
{
	Engine = nullptr;
	Engine_WrokMemory = (MByte *)malloc(WORKBUF_SIZE);
	InputImage.u32PixelArrayFormat = ASVL_PAF_RGB24_B8G8R8;
	InputImage.ppu8Plane[0] = nullptr;

	AFT_FSDK_InitialFaceEngine((char*)APP_ID, (char*)FT_SDK_KEY, Engine_WrokMemory, WORKBUF_SIZE, &Engine, AFT_FSDK_OPF_0_HIGHER_EXT, FaceScale, MaxFaceNumber);

}

//析构函数
FaceIdentification::~FaceIdentification()
{
}

//人脸鉴别 主接口
FI_RESULT FaceIdentification::Identify(Mat &Image)
{
	FI_RESULT Result;
	return Result;
}
