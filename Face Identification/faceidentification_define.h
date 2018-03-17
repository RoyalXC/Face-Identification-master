#pragma once

#include <cv.h>
#include <string>
#include <thread>
#include "arcsoft_fsdk_face_tracking.h"
#include "arcsoft_fsdk_face_recognition.h"

using namespace cv;
using namespace std;

typedef int IDENTIFY_STATUS;

#define SUCCESS			1	//成功鉴别
#define NO_FACE			2	//未检测到人脸
#define EXCESSIVE_FACE	3	//画面中出现过多人脸
#define NO_INFO			4	//无此人信息
#define INSTABLE		5	//人脸不稳定

//RECT结构体 用于标定矩形区域
typedef struct _FI_Rect
{
	int left, right, top, bottom;
}RECT;

//人员信息结构体
typedef struct _Personal_Information
{
	int ID;
	string Name;
	bool Sex;
	int PersonType;
}PInfo;

//主接口返回信息结构体
struct FI_RESULT
{
	RECT *FaceRect;
	int NumberOfFace;
	IDENTIFY_STATUS IdentifyStatus;
	PInfo PersonInfo;
};
