#pragma once

#include "faceidentification_define.h"


#define WORKBUF_SIZE        (40*1024*1024)	//引擎工作缓存空间大小


class FaceIdentification
{
public:
	FaceIdentification();
	~FaceIdentification();

	FI_RESULT Identify(Mat &Image);

private:
	const char *APP_ID = "H38Mv4gHhdR1dwKq8r3sjZSDKRpna4JWVRY7un6uhQFC";
	const char *FT_SDK_KEY = "6VMPpuSm7EMfQ8oeTFHWb817n9G9yJgDCX6R5DnmnJ4J";

	bool IsEngineStart;						//引擎是否启动
	MByte *Engine_WrokMemory;				//引擎工作缓存空间
	MHandle Engine;							//引擎句柄
	MInt32 FaceScale = 16;					//最小人脸尺寸，有效范围[2,16]，建议16
	MInt32 MaxFaceNumber = 2;				//最多检测出人脸数量，有效范围[1,20]
	ASVLOFFSCREEN InputImage = { 0 };		//输入图像
	RECT *FaceRect;							//检测出的人脸区域
};

