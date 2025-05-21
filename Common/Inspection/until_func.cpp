#include "stdafx.h"
#include <math.h>
#include "StepStain.h"
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include "Util/Util.h"
#include "until_func.h"


using namespace std;
using namespace cv;

float calcSize(int x1, int y1, int x2, int y2){
	float result;
	result = sqrt(abs(x1 - x2)*abs(x1 - x2) + abs(y1 - y2)*abs(y1 - y2));
	return result;
}

void makeColorTable(int range, COLORREF* pColorTable)
{
	int r = 0; int g = 0; int b = 0;
	float a;
	int X, Y;
	for (int i = 0; i < range; i++){
		a = (1.0f - (float)i / (float)range) / 0.25f;
		X = (int)floor(a);
		Y = (int)floor(range * (a - (float)X));

		switch (X){
		case 0:
			r = 255; g = Y; b = 0;
			break;
		case 1:
			r = 255 - Y; g = 255; b = 0;
			break;
		case 2:
			r = 0; g = 255; b = Y;
			break;
		case 3:
			r = 0; g = 255 - Y; b = 255;
			break;
		case 4:
			r = 0; g = 0; b = 255;
			break;
		}
		pColorTable[i] = RGB(r, g, b);
	}
}


bool preprocessImage(const char* filepath, cv::Mat& crop_image)
{
	cv::Mat input = cv::imread(filepath, CV_LOAD_IMAGE_GRAYSCALE);
	if (input.data == NULL){
		printf("Can not input [%s]\n", filepath);
		return false;
	}

	int f = 10;  // f is the factor that value is used in center point evaluating process
	Size size_tmp(input.size().width / f, input.size().height / f);
	Mat tmp_img;
	resize(input, tmp_img, size_tmp);

	GaussianBlur(tmp_img, tmp_img, Size(9, 9), 2, 2);

	vector<Vec3f> circles;
	/// Apply the Hough Transform to find the circles
	HoughCircles(tmp_img, circles, CV_HOUGH_GRADIENT, 1, tmp_img.rows / 2, 80, 20, 0, 0);
	if (circles.size() == 0){
		printf("Can not find centor [%s]\n", filepath);
		return false;
	}

	//find big circle and centor 
	Vec3f centor;
	centor[2] = 0;
	for (int i = 0; i < circles.size(); i++){
		if (circles[i][2] > centor[2]){
			centor = circles[i];
		}
	}

	//Add margin 
	centor[2] += int(centor[2] * 0.05f);

	centor *= f;
	Rect crop_rect;
	crop_rect.x = int(centor[0] - centor[2]);
	crop_rect.y = int(centor[1] - centor[2]);
	crop_rect.width = int (centor[2] *2);
	crop_rect.height = int (centor[2] *2);

	crop_image = input(crop_rect);

	return true;
}


void remove_small_blobs(cv::Mat &binary, cv::Mat &result, int min_blob_size)
{
	int label_count = 2;
	//add morphoize 
	cv::Mat kernel = cv::Mat::ones(3, 3, CV_8UC1);
	cv::dilate(binary, binary, kernel);


	for (int y = 0; y < binary.rows; y++) {
		unsigned char *row = (unsigned char*)binary.ptr(y);
		for (int x = 0; x < binary.cols; x++) {
			if (row[x] != 1) {
				continue;
			}

			cv::Rect rect;
			cv::floodFill(binary, cv::Point(x, y), label_count, &rect, 0, 0, 4);
			std::vector <cv::Point2i> blob;

			for (int i = rect.y; i < (rect.y + rect.height); i++) {
				unsigned char *row2 = (unsigned char*)binary.ptr(i);
				for (int j = rect.x; j < (rect.x + rect.width); j++) {
					if (row2[j] != label_count) {
						continue;
					}

					blob.push_back(cv::Point2i(j, i));
				}
			}

			if (blob.size() < min_blob_size){
				cv::rectangle(result, rect, RGB(0,0,0), -1);
			}

			label_count++;
		}
	}
}


bool checkBlobSize(cv::Mat &binary, cv::Mat &resultImg, vector<float> vecMaxSize, int maxValue, int processStep, INFO_LOGFUNC m_stLogFunc, TYPE_CAMERAPOS m_eCameraPos)
{
	int label_count = 2;
	char* stepLogName = "";
	if (processStep == 2){
		stepLogName = "STAIN";
	}
	else if (processStep == 3){
		stepLogName = "DIFFER";
	}
	else if (processStep == 4){
		stepLogName = "BUBBLE";
	}
	else if (processStep == 5){
		stepLogName = "SCRATCH";
	}
	else if (processStep == 6){
		stepLogName = "STAMP";
	}


	//add morphoize 
	cv::Mat kernel = cv::Mat::ones(3, 3, CV_8UC1);
	cv::dilate(binary, binary, kernel);
	bool result = TRUE;
	CString total_defect1, total_defect2, total_defect3, defectNum;
	float lineSize;
	CString big_defect;

	total_defect1.Format(_T("Calculated in ROI AXIS"));

	for (int y = 0; y < binary.rows; y++) {
		unsigned char *row = (unsigned char*)binary.ptr(y);
		for (int x = 0; x < binary.cols; x++) {
			if (row[x] != 1) {
				continue;
			}

			cv::Rect rect;
			cv::floodFill(binary, cv::Point(x, y), label_count, &rect, 0, 0, 4);
			std::vector <cv::Point2i> blob;

			for (int i = rect.y; i < (rect.y + rect.height); i++) {
				unsigned char *row2 = (unsigned char*)binary.ptr(i);
				for (int j = rect.x; j < (rect.x + rect.width); j++) {
					if (row2[j] != label_count) {
						continue;
					}
					blob.push_back(cv::Point2i(j, i));
				}
			}

			if (blob.size() < 1)
				continue;

			lineSize = calcSize(blob[0].x, blob[0].y, blob[blob.size() - 1].x, blob[blob.size() - 1].y);

			// 기준
			if (lineSize > maxValue){
				total_defect1.Format(_T("blob area : %d \t (x1,y1) : (%d, %d) \n "), blob.size(), blob[0].x, blob[0].y);
				total_defect2.Format(_T("\t (x2,y2) : (%d, %d) \n "), blob[blob.size() - 1].x, blob[blob.size() - 1].y);
				total_defect3.Format(_T("blob line size : %f \n\n"), lineSize);

				m_stLogFunc.m_pFuncTextLog(m_stLogFunc.m_pArg, m_eCameraPos, stepLogName, "(x1,y1) : (%d, %d), (x2,y2) : (%d, %d),  blob line size : %f", blob[0].x, blob[0].y, blob[blob.size() - 1].x, blob[blob.size() - 1].y, lineSize);

				CUtil::PrintDebugString(total_defect1);
				CUtil::PrintDebugString(total_defect2);
				CUtil::PrintDebugString(total_defect3);

				vecMaxSize.push_back(lineSize);
			}
			else{
				cv::rectangle(resultImg, rect, RGB(0, 0, 0), -1);
			}

			label_count++;
		}
	}	
	defectNum.Format(_T("the Number of defects : %d \n"), vecMaxSize.size());
	CUtil::PrintDebugString(defectNum);
	switch (processStep)
	{
		// vecMaxSize : 검사시 max value보다 큰 결함크기를 원소로 가지고 있는 벡터
		// vecMaxSize.size() : 검사시 max value보다 큰 결함크기의 원소 갯수
		// max value = 결함의 크기
	case 2:
		// stain 얼룩 check(기준 없음 정해야함)
		result = vecMaxSize.size() > 0 ? FALSE : TRUE;
		break;
	case 3:
		// Differ 이물 check(0.5mm이하 면적 0.2mm이하 없을 것 => 학습후 maxValue 0.5mm 조정 필요)
		result = vecMaxSize.size() > 0 ? FALSE : TRUE;
		break;
	case 4:
		// Bubble 기포 check(0.3mm이하 2개 허용 / 0.3~0.5mm 1개 허용 =>maxValue 0.1mm 조정 후 조건문에서 그보다 작은 결함은 조건부 Pass)
		result = vecMaxSize.size() > 0 ? FALSE : TRUE;
		if (result == TRUE){
			if (vecMaxSize.size() == 1){
				result = (vecMaxSize[0] < 50) ? TRUE : FALSE;
			}
			else if (vecMaxSize.size() == 2){
				result = (vecMaxSize[0] < 30 && vecMaxSize[1] < 30) ? TRUE : FALSE;
			}
		}
		break;
	case 5:
		// Scratch 스크래치 check(20mm이하 3개 허용=> maxValue 20mm 이후 조건부 Pass)
		// maxValue 10 (1mm)로 설정
		result = vecMaxSize.size() > 0 ? FALSE : TRUE;
		if (result == TRUE){
			if (vecMaxSize.size() == 1){
				result = (vecMaxSize[0] < 20) ? TRUE : FALSE;
			}
			else if (vecMaxSize.size() == 2){
				result = (vecMaxSize[0] < 20 && vecMaxSize[1] < 20) ? TRUE : FALSE;
			}
			else if (vecMaxSize.size() == 3){
				result = (vecMaxSize[0] < 20 && vecMaxSize[1] < 20 && vecMaxSize[2] < 20) ? TRUE : FALSE;
			}
		}
		break;
	case 6:
		// Stamp 찍힘/휨 check(1mm이하 3개 허용=> maxValue 1mm 이후 조건부 Pass)
		result = vecMaxSize.size() > 0 ? FALSE : TRUE;
		if (result == TRUE){
			if (vecMaxSize.size() == 1){
				result = (vecMaxSize[0] < 10) ? TRUE : FALSE;
			}
			else if (vecMaxSize.size() == 2){
				result = (vecMaxSize[0] < 10 && vecMaxSize[1] < 20) ? TRUE : FALSE;
			}
			else if (vecMaxSize.size() == 3){
				result = (vecMaxSize[0] < 10 && vecMaxSize[1] < 10 && vecMaxSize[2] < 10) ? TRUE : FALSE;
			}
		}
		break;
	}
	m_stLogFunc.m_pFuncTextLog(m_stLogFunc.m_pArg, m_eCameraPos, stepLogName, "Result(1:true, 0:false) : %d", result);
	return result;
}

static int stain_int;
static int differ_int;
static int bubble_int;
static int scratch_int;
static int stamp_int;

void saveLogPicture(const char* processStepName, const cv::Mat& input){
			
	int cnt;
	if (!strcmp(processStepName, "firstStep")){
		cnt = stain_int++;
	}
	else if (!strcmp(processStepName, "secondStep")){
		cnt = differ_int++;
	}
	else if (!strcmp(processStepName, "thirdStep")){
		cnt = bubble_int++;
	}
	else if (!strcmp(processStepName, "forthStep")){
		cnt = scratch_int++;
	}
	else if (!strcmp(processStepName, "fifthStep")){
		cnt = stamp_int++;
	}

	char tmpString[70] = "../";
	
	strcat_s(tmpString, "Picture_Data");
	if (_mkdir(tmpString) == 0){}
	else{
	}
	strcat_s(tmpString, "/");

	strcat_s(tmpString, processStepName);

	if (_mkdir(tmpString) == 0){
	}else{
	}
	//std::cout << "Directory is created" << std::endl;
	char picturePath[50] = "";
	strcat_s(tmpString, "/");
	strcat_s(picturePath, tmpString);
	char pictureName[30] = "";
	sprintf(pictureName, "%d.png", cnt);
	strcat_s(picturePath, processStepName);
	strcat_s(picturePath, pictureName);
	cv::imwrite(picturePath, input);
}

// Version 1.3.8.1 Image Log Format (jpg)
void saveLogPicture(const char* processStepName, const cv::Mat& input, bool isCompress)
{
	int cnt;
	//if (!strcmp(processStepName, "firstStep")){
	//	cnt = stain_int++;
	//}
	//else if (!strcmp(processStepName, "secondStep")){
	//	cnt = differ_int++;
	//}
	//else if (!strcmp(processStepName, "thirdStep")){
	//	cnt = bubble_int++;
	//}
	//else if (!strcmp(processStepName, "forthStep")){
	//	cnt = scratch_int++;
	//}
	//else if (!strcmp(processStepName, "fifthStep")){
	//	cnt = stamp_int++;
	//}
	
	// 이름 중복 방지를 위한 시간 데이터로 변경 - yyyyMMdd_HHmmss
	SYSTEMTIME stTime;
	::GetLocalTime(&stTime);

	char szString[30] = { 0, };
	sprintf(szString, _T("%04d%02d%02d_%02d%02d%02d"),
		stTime.wYear, stTime.wMonth, stTime.wDay,
		stTime.wHour, stTime.wMinute, stTime.wSecond);

	char tmpString[70] = "../";

	strcat_s(tmpString, "Picture_Data");
	if (_mkdir(tmpString) == 0){}
	else{
	}
	strcat_s(tmpString, "/");

	strcat_s(tmpString, processStepName);

	if (_mkdir(tmpString) == 0){
	}
	else{
	}
	//std::cout << "Directory is created" << std::endl;
	char picturePath[70] = "";
	strcat_s(tmpString, "/");
	strcat_s(picturePath, tmpString);
	char pictureName[30] = "";
	if (!isCompress)
		sprintf(pictureName, "%s.png", szString);
	else
		sprintf(pictureName, "%s.jpg", szString);

	strcat_s(picturePath, processStepName);
	strcat_s(picturePath, pictureName);
	cv::imwrite(picturePath, input);
}
