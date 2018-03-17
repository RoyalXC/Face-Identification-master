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

	bool IsEngineStart;						//引擎是否启动
	MByte *Engine_WrokMemory;				//引擎工作缓存空间
	MHandle Engine;							//引擎句柄
	MInt32 FaceScale = 16;					//最小人脸尺寸，有效范围[2,16]，建议16
	MInt32 MaxFaceNumber = 2;				//最多检测出人脸数量，有效范围[1,20]
	ASVLOFFSCREEN InputImage = { 0 };		//输入图像
	RECT *FaceRect;							//检测出的人脸区域
};

