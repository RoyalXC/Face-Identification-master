#pragma once

#include <cv.h>
#include <string>
#include <thread>
#include "arcsoft_fsdk_face_tracking.h"
#include "arcsoft_fsdk_face_recognition.h"

using namespace cv;
using namespace std;

typedef int IDENTIFY_STATUS;

#define SUCCESS			1	//�ɹ�����
#define NO_FACE			2	//δ��⵽����
#define EXCESSIVE_FACE	3	//�����г��ֹ�������
#define NO_INFO			4	//�޴�����Ϣ
#define INSTABLE		5	//�������ȶ�

//RECT�ṹ�� ���ڱ궨��������
typedef struct _FI_Rect
{
	int left, right, top, bottom;
}RECT;

//��Ա��Ϣ�ṹ��
typedef struct _Personal_Information
{
	int ID;
	string Name;
	bool Sex;
	int PersonType;
}PInfo;

//���ӿڷ�����Ϣ�ṹ��
struct FI_RESULT
{
	RECT *FaceRect;
	int NumberOfFace;
	IDENTIFY_STATUS IdentifyStatus;
	PInfo PersonInfo;
};
