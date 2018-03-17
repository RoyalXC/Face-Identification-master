#pragma once

#include "faceidentification_define.h"

class FaceComparison
{
public:
	FaceComparison();
	~FaceComparison();
private:
	const char *APP_ID = "H38Mv4gHhdR1dwKq8r3sjZSDKRpna4JWVRY7un6uhQFC";
	const char *FT_SDK_KEY = "6VMPpuSm7EMfQ8oeTFHWb81EwYXNguit6mLK7ztBQSLh";

	bool IsEngineStart;						//�����Ƿ�����
	MByte *Engine_WrokMemory;				//���湤������ռ�
	MHandle Engine;							//������
	MInt32 FaceScale = 16;					//��С�����ߴ磬��Ч��Χ[2,16]������16
	MInt32 MaxFaceNumber = 2;				//������������������Ч��Χ[1,20]
	ASVLOFFSCREEN InputImage = { 0 };		//����ͼ��
	RECT *FaceRect;							//��������������
};

