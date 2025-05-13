/**
* @file StepSize.cpp
* @brief StepSizeCalculation 클래스 정의 파일
* @author Junmock Lee  * @Modified Jongik
* @date 2017-07-25     * @date 2020-07-13
*/
#include "StdAfx.h"
#include "StepSizeCalculation.h"

#include <chrono>

#include "Util/Util.h"
#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

#include <tchar.h> // _vsntprintf
#include "LPGEOMETRY_geometry.h"

//#include "vendor_code.h"

#ifdef _WIN64
#pragma comment (lib, "hasp_windows_x64_98043")
#ifdef _DEBUG
#pragma comment (lib, "libhasp_cpp_windows_x64_mtd_msc10_d")
#pragma comment (lib, "lib/Applicationd.lib")
#else
#pragma comment (lib, "libhasp_cpp_windows_x64_mtd_msc10")
#pragma comment (lib, "lib/Application.lib")
#endif
#else
#pragma comment (lib, "hasp_windows_98043")
#ifdef _DEBUG
#pragma comment (lib, "libhasp_cpp_windows_mtd_msc10_d")
#pragma comment (lib, "lib/Applicationd.lib")
#else
#pragma comment (lib, "libhasp_cpp_windows_mtd_msc10")
#pragma comment (lib, "lib/Application.lib")
#endif
#endif

#define DEF_CALC_VER2		

#define FINDLINE_ROTATERECT // ROI 타입을 회전 사각형으로 강제함
//#define CALIBRATION_THRESHOLD
#define CALIBRATION_PIXELWIDTH 2048 // 4M에 맞춰 픽셀 거리 보정 해상도 고정. TODO: 필요 시 수정

#define HASP_FEATURE 11011

#define L_M_T TYPE_FINDLINE_METAL_TOP
#define L_M_R TYPE_FINDLINE_METAL_RIGHT
#define L_M_B TYPE_FINDLINE_METAL_BOTTOM
#define L_M_L TYPE_FINDLINE_METAL_LEFT
#define L_TL_T TYPE_FINDLINE_TAPE_LEFTWING_TOP
#define L_TL_L TYPE_FINDLINE_TAPE_LEFTWING_LEFT
#define L_TL_B TYPE_FINDLINE_TAPE_LEFTWING_BOTTOM
#define L_TC_T TYPE_FINDLINE_TAPE_CENTER_TOP
#define L_TC_TL TYPE_FINDLINE_TAPE_CENTER_TOPLEFT
#define L_TC_TR TYPE_FINDLINE_TAPE_CENTER_TOPRIGHT
#define L_TC_B TYPE_FINDLINE_TAPE_CENTER_BOTTOM
#define L_TC_BL TYPE_FINDLINE_TAPE_CENTER_BOTTOMLEFT
#define L_TC_BR TYPE_FINDLINE_TAPE_CENTER_BOTTOMRIGHT
#define L_TR_T TYPE_FINDLINE_TAPE_RIGHTWING_TOP
#define L_TR_R TYPE_FINDLINE_TAPE_RIGHTWING_RIGHT
#define L_TR_B TYPE_FINDLINE_TAPE_RIGHTWING_BOTTOM

#define P_M_TR TYPE_GEOMETRY_POINT_METAL_TOPRIGHT
#define P_M_BR TYPE_GEOMETRY_POINT_METAL_BOTTOMRIGHT
#define P_M_BL TYPE_GEOMETRY_POINT_METAL_BOTTOMLEFT
#define P_M_TL TYPE_GEOMETRY_POINT_METAL_TOPLEFT
#define P_TL_B TYPE_GEOMETRY_POINT_TAPE_LEFTWING_BOTTOM
#define P_TL_T TYPE_GEOMETRY_POINT_TAPE_LEFTWING_TOP
#define P_TC_TL TYPE_GEOMETRY_POINT_TAPE_CENTER_TOPLEFT
#define P_TC_TR TYPE_GEOMETRY_POINT_TAPE_CENTER_TOPRIGHT
#define P_TR_T TYPE_GEOMETRY_POINT_TAPE_RIGHTWING_TOP
#define P_TR_B TYPE_GEOMETRY_POINT_TAPE_RIGHTWING_BOTTOM
#define P_TL_TC TYPE_GEOMETRY_POINT_TAPE_LEFTWING_TOP_CENTER
#define P_TR_TC TYPE_GEOMETRY_POINT_TAPE_RIGHTWING_TOP_CENTER

#define D_D		TYPE_GEOMETRY_DISTANCE_D
#define D_L		TYPE_GEOMETRY_DISTANCE_L
#define D_W		TYPE_GEOMETRY_DISTANCE_W
#define D_I1	TYPE_GEOMETRY_DISTANCE_I1
#define D_I2	TYPE_GEOMETRY_DISTANCE_I2
#define D_I3	TYPE_GEOMETRY_DISTANCE_I3
#define D_M1	TYPE_GEOMETRY_DISTANCE_M1
#define D_M2	TYPE_GEOMETRY_DISTANCE_M2
#define D_S1	TYPE_GEOMETRY_DISTANCE_S1
#define D_S2	TYPE_GEOMETRY_DISTANCE_S2
#define D_S3	TYPE_GEOMETRY_DISTANCE_S3
#define D_S4	TYPE_GEOMETRY_DISTANCE_S4
#define D_S5	TYPE_GEOMETRY_DISTANCE_S5
#define D_X1	TYPE_GEOMETRY_DISTANCE_X1
#define D_X2	TYPE_GEOMETRY_DISTANCE_X2
#define D_R1	TYPE_GEOMETRY_DISTANCE_R1
#define D_R2	TYPE_GEOMETRY_DISTANCE_R2
#define D_R3	TYPE_GEOMETRY_DISTANCE_R3
#define D_R4	TYPE_GEOMETRY_DISTANCE_R4
// Version 1.3.7.5 R1 ~ R6, SS1 ~ SS3
#define D_R5	TYPE_GEOMETRY_DISTANCE_R5
#define D_R6	TYPE_GEOMETRY_DISTANCE_R6
#define D_SS1	TYPE_GEOMETRY_DISTANCE_SS1
#define D_SS2	TYPE_GEOMETRY_DISTANCE_SS2
#define D_SS3	TYPE_GEOMETRY_DISTANCE_SS3

#define D_X1X2	TYPE_GEOMETRY_DISTANCE_X1X2
#define D_S1S3	TYPE_GEOMETRY_DISTANCE_S1S3
#define D_M1M2	TYPE_GEOMETRY_DISTANCE_M1M2
// Version 1.3.7.5 R1 ~ R6, SS1 ~ SS3
#define D_SS1SS3 TYPE_GEOMETRY_DISTANCE_SS1SS3

using namespace cv;

/**
* @brief 생성자
*/
CStepSizeCalculation::CStepSizeCalculation()
{
	m_strStepName = "SIZE_CALC";

	memset(&m_stInfoCalc, 0x00, sizeof(INFO_INSPECTION_SIZE_CALC));
	memset(&m_stLogFunc, 0x00, sizeof(INFO_LOGFUNC));

	m_iCalInit = ERR_ERROR;

	m_pCalibrationApp = NULL;

	m_pGeometryApp = NULL;
}

/**
* @brief 소멸자
*/
CStepSizeCalculation::~CStepSizeCalculation()
{
	Deinit();
}

/**
* @brief 초기화 함수
* @return 초기화 성공 여부
* @remark 각 App의 객체를 생성하며, 생성에 성공할 경우 설정 값 초기화
*         생성에 실패할 경우 모두 해제함
*         이후 초기화 성공 여부는 m_bInit으로 확인함
*/
BOOL CStepSizeCalculation::Init(TYPE_CAMERAPOS eCameraPos, INFO_LOGFUNC stLogFunc)
{
	BOOL bResult = TRUE;

	Deinit();

	this->m_eCameraPos = eCameraPos;
	this->m_stLogFunc = stLogFunc;

	if (!(m_pCalibrationApp = LPCreateApp(eAppType_Calibrate)))
		bResult = FALSE;

	for (int i = 0; i < TYPE_FINDLINE_MAX; i++)
	{
		if (!(m_pFindLineApp[i] = LPCreateApp(eAppType_LineFitting)))
			bResult = FALSE;
	}

	if (!(m_pGeometryApp = LPCreateApp(eAppType_Geometry)))
		bResult = FALSE;

	if (bResult)
	{
		Log("Success to Init");
		m_bInit = TRUE;
	}
	else
	{
		Log("Fail to Init");
		Deinit();
	}

	return bResult;
}

/**
* @brief 초기화 해제 함수
* @remark 각 App의 객체 삭제
*/
void CStepSizeCalculation::Deinit()
{
	m_iCalInit = ERR_ERROR;

	m_eCameraPos = TYPE_CAMERAPOS_NONE;
	memset(&m_stLogFunc, 0x00, sizeof(INFO_LOGFUNC));

	if (m_pCalibrationApp)
	{
		delete[] m_pCalibrationApp;
		m_pCalibrationApp = NULL;
	}

	if (m_pGeometryApp)
	{
		delete m_pGeometryApp;
		m_pGeometryApp = NULL;
	}

	m_bInit = FALSE;
}

/**
* @brief 설정 값 Load 함수
* @param INFO_INSPECTION* pstInspection 설정 값 구조체
* @return 설정 성공 여부
* @remark 인자가 NULL 일 경우 설정 값 초기화
*/
BOOL CStepSizeCalculation::Load(INFO_INSPECTION* pstInspection)
{
	BOOL bResult = FALSE;
	if (pstInspection)
	{
		// Load
		bResult = SetInformation(&pstInspection->m_stSizeCalc);
	}
	else
	{
		Log("Load Default Setting");

		INFO_INSPECTION_SIZE_CALC infoSize;
		memset(&infoSize, 0x00, sizeof(INFO_INSPECTION_SIZE_CALC));
		GetDefaultCalcSetting(&infoSize);

		bResult = SetInformation(&infoSize);
	}

	return bResult;
}

/**
* @brief 설정 값 Get 함수
* @param INFO_INSPECTION* pstInspection 설정 값을 받아갈 구조체
* @return 설정 취득 성공 여부
* @remark 이 함수는 쓰이지 않을 수 있음
*/
BOOL CStepSizeCalculation::Get(INFO_INSPECTION* pstInspection)
{
	if (NULL == pstInspection)
		return FALSE;

	memcpy(&pstInspection->m_stSizeCalc, &m_stInfoCalc, sizeof(INFO_INSPECTION_SIZE_CALC));
	return TRUE;
}

/**
* @brief 설정 값 Set 함수
* @param const INFO_INSPECTION* pstInspection 설정 값을 가져올 구조체
* @return 설정 성공 여부
* @remark 이 함수는 쓰이지 않을 수 있음
*/
BOOL CStepSizeCalculation::Set(const INFO_INSPECTION* pstInspection)
{
	if (NULL == pstInspection)
		return FALSE;

	return SetInformation(&pstInspection->m_stSizeCalc);
}


/**
* @brief 설정 값 Get 함수
* @return 설정 값 구조체 포인터
*/
const INFO_INSPECTION_SIZE_CALC* CStepSizeCalculation::GetInformation()
{
	return &m_stInfoCalc;
}

/**
* @brief 설정 값 Set 함수
* @param const INFO_INSPECTION_SIZE_CALC* pInfoSize 설정 값을 가져올 구조체
* @return 설정 성공 여부
* @remark 설정 값을 가져오고 모든 FindLine 객체의 설정 값 변경
*/
BOOL CStepSizeCalculation::SetInformation(const INFO_INSPECTION_SIZE_CALC* pInfoSize)
{
	if (NULL == pInfoSize || !m_bInit)
		return FALSE;

	Log("Set information");

	memcpy(&m_stInfoCalc, pInfoSize, sizeof(INFO_INSPECTION_SIZE_CALC));

	// Calibration 설정
	SetCalibration(&m_stInfoCalc.m_stCalibration);

	// Gain 설정
	SetSizeGain(&m_stInfoCalc.m_stSizeGain);

	return TRUE;
}

/**
* @brief Calibration 객체의 설정 값 Set 함수
* @param const INFO_CALIBRATION* pstInfoCalibration Calibration의 설정 값 구조체
* @return 설정 성공 여부
*/
BOOL CStepSizeCalculation::SetCalibration(const INFO_CALIBRATION* pstInfoCalibration)
{
	// NULL이 아닐 경우 복사, NULL일 경우 현재 멤버 변수를 그대로 사용
	if (NULL != pstInfoCalibration)
		memcpy(&m_stInfoCalc.m_stCalibration, pstInfoCalibration, sizeof(INFO_CALIBRATION));

	if (NULL == m_pCalibrationApp)
		return FALSE;

	Log("Calibration Start");

	int iResult = ERR_SUCCESS;

	stPOINT pt1, pt2;
	double distance = 0;
	switch (m_stInfoCalc.m_stCalibration.m_iMethod)
	{
	case 0:
		// Calibration Type
		m_pCalibrationApp->SetParameter(CALIBRATION_POINT_DISTANCE);
		pt1.m_fX = 0; pt1.m_fY = 0;
		pt2.m_fX = max(m_stInfoCalc.m_stCalibration.m_iImgWidth - 1, 1); pt2.m_fY = max(m_stInfoCalc.m_stCalibration.m_iImgHeight - 1, 1);
		distance = sqrt(m_stInfoCalc.m_stCalibration.m_dWidth * m_stInfoCalc.m_stCalibration.m_dWidth + m_stInfoCalc.m_stCalibration.m_dHeight * m_stInfoCalc.m_stCalibration.m_dHeight);
		m_pCalibrationApp->SetParameter(CALIBRATION_PUSH_POINT, pt1, pt2);
		m_pCalibrationApp->SetParameter(CALIBRATION_REALDISTANCE, distance);
		m_pCalibrationApp->SetParameter(CALIBRATION_MILLIMETER); // m_iPixelUnit 사용하지 않고 mm 고정
		break;
	case 1:
		// Calibration Type
		m_pCalibrationApp->SetParameter(CALIBRATION_DISTORTION);

		// Input Chess Board Image
		for (int i = 0; i < m_stInfoCalc.m_stCalibration.m_nListCount; i++)
		{
			if (strnlen_s(m_stInfoCalc.m_stCalibration.m_pszFilePathList[i], MAX_FILE_PATH_LEN) == 0)
				continue;
#ifndef CALIBRATION_THRESHOLD
			Mat matimg = imread(m_stInfoCalc.m_stCalibration.m_pszFilePathList[i], CV_LOAD_IMAGE_GRAYSCALE);
			if (matimg.empty())
				continue;

			stAPPIMAGEDATA chessboardimg;
			memset(&chessboardimg, 0, sizeof(stAPPIMAGEDATA));
			chessboardimg.m_pSrcImage = matimg.data;
			chessboardimg.m_iChannel = 1;
			chessboardimg.m_iDepth = DEPTH_8U;
			chessboardimg.m_iWidth = matimg.cols;
			chessboardimg.m_iHeight = matimg.rows;
			chessboardimg.m_iWidthStep = matimg.rows * chessboardimg.m_iChannel;
			chessboardimg.m_iImageSize = matimg.cols * matimg.rows * chessboardimg.m_iChannel;
#else
			Mat matimg = imread(m_stInfoCalc.m_stCalibration.m_pszFilePathList[i], CV_LOAD_IMAGE_GRAYSCALE);
			Mat matimg_th;
			threshold(matimg, matimg_th, 128, 255, CV_ADAPTIVE_THRESH_MEAN_C);
			if (matimg_th.empty())
				continue;

			stAPPIMAGEDATA chessboardimg;
			memset(&chessboardimg, 0, sizeof(stAPPIMAGEDATA));
			chessboardimg.m_pSrcImage = matimg_th.data;
			chessboardimg.m_iChannel = 1;
			chessboardimg.m_iDepth = DEPTH_8U;
			chessboardimg.m_iWidth = matimg_th.cols;
			chessboardimg.m_iHeight = matimg_th.rows;
			chessboardimg.m_iWidthStep = matimg_th.rows * chessboardimg.m_iChannel;
			chessboardimg.m_iImageSize = matimg_th.cols * matimg_th.rows * chessboardimg.m_iChannel;
#endif

			m_pCalibrationApp->SetParameter(CALIBRATION_PUSH_IMAGE, chessboardimg);
		}

		m_pCalibrationApp->SetParameter(CALIBRATION_SELECT_REFERENCEIMAGE, m_stInfoCalc.m_stCalibration.m_nIdxReference);

		LPVal rowcolnum(m_stInfoCalc.m_stCalibration.m_iRow, m_stInfoCalc.m_stCalibration.m_iCol);
		m_pCalibrationApp->SetParameter(CALIBRATION_ROWCOLNUM, rowcolnum);
		m_pCalibrationApp->SetParameter(CALIBRATION_SPACING, m_stInfoCalc.m_stCalibration.m_dSpacing);
		m_pCalibrationApp->SetParameter(CALIBRATION_MILLIMETER); // m_iChessUnit 사용하지 않고 mm 고정
		break;
	}
	m_iCalInit = m_pCalibrationApp->SetParameter(CALIBRATION_CALCULATE);
	
	if (m_iCalInit == ERR_SUCCESS)
	{
		Log("Calibration Success");
		iResult = TRUE;
	}
	else
	{
		Log("Calibration Fail");
		iResult = FALSE;
	}

	return iResult;
}

/**
* @brief Gain 설정 값 Set 함수
* @param const INFO_SIZE_GAIN* pstInfoSizeGain Gain 설정 값 구조체
* @return 설정 성공 여부
*/
BOOL CStepSizeCalculation::SetSizeGain(const INFO_SIZE_GAIN* pstInfoSizeGain)
{
	if (NULL == pstInfoSizeGain)
		return FALSE;

	memcpy(&m_stInfoCalc.m_stSizeGain, pstInfoSizeGain, sizeof(INFO_SIZE_GAIN));

	for (int i = 0; i < sizeof(INFO_SIZE_GAIN) / sizeof(double); i++)
	{
		if (m_stInfoCalc.m_stSizeGain.m_dGain[i] <= 0
			|| m_stInfoCalc.m_stSizeGain.m_dGain[i] > 100)
			m_stInfoCalc.m_stSizeGain.m_dGain[i] = 1.0;
	}

	return true;
}

void CStepSizeCalculation::PreProcess(cv::Mat captureImg)
{
	Mat zeroImg = Mat::zeros(captureImg.size(), captureImg.type());
	stAPPIMAGEDATA img;
	memset(&img, 0, sizeof(stAPPIMAGEDATA));

	img.m_pSrcImage = zeroImg.data;;
	img.m_iChannel = zeroImg.channels();
	img.m_iDepth = DEPTH_8U;
	img.m_iWidth = zeroImg.cols;
	img.m_iHeight = zeroImg.rows;
	img.m_iWidthStep = zeroImg.step1();
	img.m_iImageSize = zeroImg.total() * zeroImg.channels();

	// Calibration
	m_pCalibrationApp->SetInput(&img);
	m_pCalibrationApp->Process();

	if (captureImg.channels() == 1)
		m_GrayMat = zeroImg.clone();
	else
		cvtColor(zeroImg, m_GrayMat, COLOR_BGR2GRAY);
}

/**
* @brief Geometry (Line Intersection) 실행 함수
* @param CLPApp *app Geometry 객체 포인터
* @param stAPPIMAGEDATA *img 이미지 구조체 포인터
* @param const stLine &line1 첫번째 Line 구조체
* @param const stLine &line2 두번째 Line 구조체
* @param stPOINT &ptOut Point 위치 결과
* @return Point 취득 성공 여부
* @remark 이미지는 사실상 필요 없음
*/
BOOL CStepSizeCalculation::LineIntersection(stAPPIMAGEDATA *img, const stLine &line1, const stLine &line2, stPOINT &ptOut)
{
	if (NULL == m_pGeometryApp || NULL == img)
		return FALSE;

	if ((line1.m_fStartX == 0 && line1.m_fStartY && line1.m_fEndX && line1.m_fEndY)
		|| (line2.m_fStartX == 0 && line2.m_fStartY && line2.m_fEndX && line2.m_fEndY))
		return FALSE;

	int iResult = ERR_SUCCESS;

	m_pGeometryApp->SetInput(img);

	m_pGeometryApp->SetParameter(GEOMETRY_LINE_INTERSECTION);
	stPOINT stPt1, stPt2, stPt3, stPt4;
	stPt1.m_fX = line1.m_fStartX;
	stPt1.m_fY = line1.m_fStartY;
	stPt2.m_fX = line1.m_fEndX;
	stPt2.m_fY = line1.m_fEndY;
	stPt3.m_fX = line2.m_fStartX;
	stPt3.m_fY = line2.m_fStartY;
	stPt4.m_fX = line2.m_fEndX;
	stPt4.m_fY = line2.m_fEndY;
	m_pGeometryApp->SetParameter(GEOMETRY_PUSH_POINT, stPt1);
	m_pGeometryApp->SetParameter(GEOMETRY_PUSH_POINT, stPt2);
	m_pGeometryApp->SetParameter(GEOMETRY_PUSH_POINT, stPt3);
	m_pGeometryApp->SetParameter(GEOMETRY_PUSH_POINT, stPt4);

	m_pGeometryApp->Process();
	iResult = m_pGeometryApp->GetOutput(GEOMETRY_RESULT_POINT, ptOut);

	iResult = (iResult == ERR_SUCCESS) ? TRUE : FALSE;

	return iResult;
}

/**
* @brief Geometry (Mid Point) 실행 함수
* @param CLPApp *app Geometry 객체 포인터
* @param stAPPIMAGEDATA *img 이미지 구조체 포인터
* @param const stLine &pt1 첫번째 Point 구조체
* @param const stLine &pt2 두번째 Point 구조체
* @param stPOINT &ptOut Point 위치 결과
* @return Point 취득 성공 여부
* @remark 이미지는 사실상 필요 없음
*/
BOOL CStepSizeCalculation::MidPoint(stAPPIMAGEDATA *img, const stPOINT &pt1, const stPOINT &pt2, stPOINT &ptOut)
{
	if (NULL == m_pGeometryApp || NULL == img)
		return FALSE;

	int iResult = ERR_SUCCESS;

	m_pGeometryApp->SetInput(img);

	m_pGeometryApp->SetParameter(GEOMETRY_MIDPOINT);
	m_pGeometryApp->SetParameter(GEOMETRY_PUSH_POINT, pt1);
	m_pGeometryApp->SetParameter(GEOMETRY_PUSH_POINT, pt2);

	m_pGeometryApp->Process();
	iResult = m_pGeometryApp->GetOutput(GEOMETRY_RESULT_POINT, ptOut);

	iResult = (iResult == ERR_SUCCESS) ? TRUE : FALSE;

	return iResult;
}

/**
* @brief Geometry (Line to Line Distance) 실행 함수
* @param CLPApp *app Geometry 객체 포인터
* @param stAPPIMAGEDATA *img Calibration App으로 보정 된 이미지 구조체 포인터
* @param const stLine &line1 첫번째 Line 구조체
* @param const stLine &line2 두번째 Line 구조체
* @param double &distance 거리 측정 결과 값
* @param stLine &distanceLine 거리 측정 결과 표시 선
* @return 거리 계산 성공 여부
* @remark Calibration App process 후 호출해야 함
*/
BOOL CStepSizeCalculation::LinetoLineDistance(stAPPIMAGEDATA *img, const stLine &line1, const stLine &line2, double &distance, stLine &distanceLine)
{
	if (NULL == m_pGeometryApp || NULL == img)
		return FALSE;

	if ((line1.m_fStartX == 0 && line1.m_fStartY && line1.m_fEndX && line1.m_fEndY)
		|| (line2.m_fStartX == 0 && line2.m_fStartY && line2.m_fEndX && line2.m_fEndY))
		return FALSE;

	int iResult = ERR_SUCCESS;
	double pixelDistance = 0;

	m_pGeometryApp->SetInput(img);

	m_pGeometryApp->SetParameter(GEOMETRY_DISTANCE_LINE_LINE);
	stPOINT stPt1, stPt2, stPt3, stPt4;
	stPt1.m_fX = line1.m_fStartX;
	stPt1.m_fY = line1.m_fStartY;
	stPt2.m_fX = line1.m_fEndX;
	stPt2.m_fY = line1.m_fEndY;
	stPt3.m_fX = line2.m_fStartX;
	stPt3.m_fY = line2.m_fStartY;
	stPt4.m_fX = line2.m_fEndX;
	stPt4.m_fY = line2.m_fEndY;
	m_pGeometryApp->SetParameter(GEOMETRY_PUSH_POINT, stPt1);
	m_pGeometryApp->SetParameter(GEOMETRY_PUSH_POINT, stPt2);
	m_pGeometryApp->SetParameter(GEOMETRY_PUSH_POINT, stPt3);
	m_pGeometryApp->SetParameter(GEOMETRY_PUSH_POINT, stPt4);

	m_pGeometryApp->Process();
	iResult = m_pGeometryApp->GetOutput(GEOMETRY_RESULT_DISTANCE, distance);

	if (iResult == ERR_SUCCESS)
	{
		stLPGEO_OUT geoOut;
		m_pGeometryApp->GetOutputdata(&geoOut);

		if (geoOut.m_fDisplayValue.size() == 4)
		{
			distanceLine.m_fStartX = geoOut.m_fDisplayValue.at(0);
			distanceLine.m_fStartY = geoOut.m_fDisplayValue.at(1);
			distanceLine.m_fEndX = geoOut.m_fDisplayValue.at(2);
			distanceLine.m_fEndY = geoOut.m_fDisplayValue.at(3);
		}

		if (m_pCalibrationApp && m_iCalInit == ERR_SUCCESS)
		{
			pixelDistance = distance;
			iResult = m_pCalibrationApp->GetOutput(CALIBRATION_RESULT_DISTANCE, pixelDistance, distance);
		}
	}

	iResult = (iResult == ERR_SUCCESS) ? TRUE : FALSE;

	return iResult;
}

/**
* @brief Geometry (Point to Point Distance) 실행 함수
* @param CLPApp *app Geometry 객체 포인터
* @param stAPPIMAGEDATA *img Calibration App으로 보정 된 이미지 구조체 포인터
* @param const stPOINT &pt1 첫번째 Point 구조체
* @param const stPOINT &pt2 두번째 Point 구조체
* @param double &distance 거리 측정 결과 값
* @param stLine &distanceLine 거리 측정 결과 표시 선
* @return 거리 계산 성공 여부
* @remark Calibration App process 후 호출해야 함
*/
BOOL CStepSizeCalculation::PointtoPointDistance(stAPPIMAGEDATA *img, const stPOINT &pt1, const stPOINT &pt2, double &distance, stLine &distanceLine)
{
	if (NULL == m_pGeometryApp || NULL == img)
		return FALSE;

	if ((pt1.m_fX == 0 && pt1.m_fY == 0)
		|| (pt2.m_fX == 0 && pt2.m_fY == 0))
		return FALSE;

	int iResult = ERR_SUCCESS;
	double pixelDistance = 0;

	m_pGeometryApp->SetInput(img);

	m_pGeometryApp->SetParameter(GEOMETRY_DISTANCE_POINT_POINT);
	m_pGeometryApp->SetParameter(GEOMETRY_PUSH_POINT, pt1);
	m_pGeometryApp->SetParameter(GEOMETRY_PUSH_POINT, pt2);

	m_pGeometryApp->Process();
	iResult = m_pGeometryApp->GetOutput(GEOMETRY_RESULT_DISTANCE, distance);

	if (iResult == ERR_SUCCESS)
	{
		stLPGEO_OUT geoOut;
		m_pGeometryApp->GetOutputdata(&geoOut);

		if (geoOut.m_fDisplayValue.size() == 4)
		{
			distanceLine.m_fStartX = geoOut.m_fDisplayValue.at(0);
			distanceLine.m_fStartY = geoOut.m_fDisplayValue.at(1);
			distanceLine.m_fEndX = geoOut.m_fDisplayValue.at(2);
			distanceLine.m_fEndY = geoOut.m_fDisplayValue.at(3);
		}

		if (m_pCalibrationApp && m_iCalInit == ERR_SUCCESS)
		{
			pixelDistance = distance;
			iResult = m_pCalibrationApp->GetOutput(CALIBRATION_RESULT_DISTANCE, pixelDistance, distance);
		}
	}

	iResult = (iResult == ERR_SUCCESS) ? TRUE : FALSE;

	return iResult;
}

/**
* @brief Geometry (Point to Line Distance) 실행 함수
* @param CLPApp *app Geometry 객체 포인터
* @param stAPPIMAGEDATA *img Calibration App으로 보정 된 이미지 구조체 포인터
* @param const stLine &line Line 구조체
* @param const stPOINT &pt Point 구조체
* @param double &distance 거리 측정 결과 값
* @param stLine &distanceLine 거리 측정 결과 표시 선
* @return 거리 계산 성공 여부
* @remark Calibration App process 후 호출해야 함
*/
BOOL CStepSizeCalculation::PointtoLineDistance(LP_VisionApp::stAPPIMAGEDATA *img, const stLine &line, const stPOINT &pt, double &distance, stLine &distanceLine)
{
	if (NULL == m_pGeometryApp || NULL == img)
		return FALSE;

	if ((line.m_fStartX == 0 && line.m_fStartY == 0 && line.m_fEndX == 0 && line.m_fEndY == 0)
		|| (pt.m_fX == 0 && pt.m_fY == 0))
		return FALSE;

	int iResult = ERR_SUCCESS;
	double pixelDistance = 0;

	m_pGeometryApp->SetInput(img);

	m_pGeometryApp->SetParameter(GEOMETRY_PERPENDICULAR);
	stPOINT stPt_LineStart, stPt_LineEnd;
	stPt_LineStart.m_fX = line.m_fStartX;
	stPt_LineStart.m_fY = line.m_fStartY;
	stPt_LineEnd.m_fX = line.m_fEndX;
	stPt_LineEnd.m_fY = line.m_fEndY;
	m_pGeometryApp->SetParameter(GEOMETRY_PUSH_POINT, stPt_LineStart);
	m_pGeometryApp->SetParameter(GEOMETRY_PUSH_POINT, stPt_LineEnd);
	m_pGeometryApp->SetParameter(GEOMETRY_PUSH_POINT, pt);

	stPOINT ptOut;
	m_pGeometryApp->Process();
	iResult = m_pGeometryApp->GetOutput(GEOMETRY_RESULT_DISTANCE, distance);

	if (iResult == ERR_SUCCESS)
	{
		stLPGEO_OUT geoOut;
		m_pGeometryApp->GetOutputdata(&geoOut);

		if (geoOut.m_fDisplayValue.size() == 6)
		{
			//distance = geoOut.m_fResultValue.at(0);
			distanceLine.m_fStartX = geoOut.m_fDisplayValue.at(0);
			distanceLine.m_fStartY = geoOut.m_fDisplayValue.at(1);
			distanceLine.m_fEndX = geoOut.m_fDisplayValue.at(2);
			distanceLine.m_fEndY = geoOut.m_fDisplayValue.at(3);
		}

		if (m_pCalibrationApp && m_iCalInit == ERR_SUCCESS)
		{
			pixelDistance = distance;
			iResult = m_pCalibrationApp->GetOutput(CALIBRATION_RESULT_DISTANCE, pixelDistance, distance);
		}
	}

	iResult = (iResult == ERR_SUCCESS) ? TRUE : FALSE;

	return iResult;
}

/**
* @brief S1, S2, S3 거리 계산 함수
* @param CLPApp *app Geometry 객체 포인터
* @param stAPPIMAGEDATA *img Calibration App으로 보정 된 이미지 구조체 포인터
* @param const stLine &metalLine Metal 상단의 양 끝 점을 잇는 Line 구조체
* @param const stLine &tapeLineS1 Tape 중앙 좌측 상단의 S1 부분의 Line fitting 결과 Line 구조체
* @param const double metalLineDistance Metal 상단의 길이 (d)
* @param double &s1Distance S1 측정 결과 값
* @param stLine &s1DistanceLine S1 측정 결과 표시 선
* @return 거리 계산 성공 여부
* @remark Calibration App process 후 호출해야 함
*/
BOOL CStepSizeCalculation::S1Distance(LP_VisionApp::stAPPIMAGEDATA *img, const stLine &metalLine, const stLine &tapeLineS1, const double metalLineDistance,
	double &s1Distance, stLine &s1DistanceLine)
{
	if (NULL == m_pGeometryApp || NULL == img || metalLineDistance <= 0)
		return FALSE;

	if ((metalLine.m_fStartX == 0 && metalLine.m_fStartY && metalLine.m_fEndX && metalLine.m_fEndY)
		|| (tapeLineS1.m_fStartX == 0 && tapeLineS1.m_fStartY && tapeLineS1.m_fEndX && tapeLineS1.m_fEndY))
		return FALSE;

	if (metalLineDistance <= S1_MARGIN || metalLineDistance <= S3_MARGIN)
		return FALSE;

	stPOINT metalVector, metalNormalVector;
	metalVector = { metalLine.m_fEndX - metalLine.m_fStartX, metalLine.m_fEndY - metalLine.m_fStartY };
	metalNormalVector = { -1 * metalVector.m_fY, metalVector.m_fX };

	stLine verticalLineS1;
	verticalLineS1.m_fStartX = metalLine.m_fStartX + metalVector.m_fX / metalLineDistance * S1_MARGIN;
	verticalLineS1.m_fStartY = metalLine.m_fStartY + metalVector.m_fY / metalLineDistance * S1_MARGIN;
	verticalLineS1.m_fEndX = verticalLineS1.m_fStartX + metalNormalVector.m_fX;
	verticalLineS1.m_fEndY = verticalLineS1.m_fStartY + metalNormalVector.m_fY;
	stPOINT intersectionMetal = { 0, };
	stPOINT intersectionTape = { 0, };
	LineIntersection(img, verticalLineS1, metalLine, intersectionMetal);
	LineIntersection(img, verticalLineS1, tapeLineS1, intersectionTape);
	PointtoPointDistance(img, intersectionMetal, intersectionTape, s1Distance, s1DistanceLine);

	return TRUE;
}

/**
* @brief S1, S2, S3 거리 계산 함수
* @param CLPApp *app Geometry 객체 포인터
* @param stAPPIMAGEDATA *img Calibration App으로 보정 된 이미지 구조체 포인터
* @param const stLine &metalLine Metal 상단의 양 끝 점을 잇는 Line 구조체
* @param const stLine &tapeLineS2 Tape 중앙 상단의 S2 부분의 Line fitting 결과 Line 구조체
* @param const double metalLineDistance Metal 상단의 길이 (d)
* @param double &s2Distance S2 측정 결과 값
* @param stLine &s2DistanceLine S2 측정 결과 표시 선
* @return 거리 계산 성공 여부
* @remark Calibration App process 후 호출해야 함
*/
BOOL CStepSizeCalculation::S2Distance(LP_VisionApp::stAPPIMAGEDATA *img, const stLine &metalLine, const stLine &tapeLineS2, const double metalLineDistance,
	double &s2Distance, stLine &s2DistanceLine)
{
	if (NULL == m_pGeometryApp || NULL == img || metalLineDistance <= 0)
		return FALSE;

	if ((metalLine.m_fStartX == 0 && metalLine.m_fStartY && metalLine.m_fEndX && metalLine.m_fEndY)
		|| (tapeLineS2.m_fStartX == 0 && tapeLineS2.m_fStartY && tapeLineS2.m_fEndX && tapeLineS2.m_fEndY))
		return FALSE;

	if (metalLineDistance <= S1_MARGIN || metalLineDistance <= S3_MARGIN)
		return FALSE;

	stPOINT metalVector, metalNormalVector;
	metalVector = { metalLine.m_fEndX - metalLine.m_fStartX, metalLine.m_fEndY - metalLine.m_fStartY };
	metalNormalVector = { -1 * metalVector.m_fY, metalVector.m_fX };

	stLine verticalLineCenter;
	verticalLineCenter.m_fStartX = (metalLine.m_fEndX + metalLine.m_fStartX) / 2;
	verticalLineCenter.m_fStartY = (metalLine.m_fEndY + metalLine.m_fStartY) / 2;
	verticalLineCenter.m_fEndX = verticalLineCenter.m_fStartX + metalNormalVector.m_fX;
	verticalLineCenter.m_fEndY = verticalLineCenter.m_fStartY + metalNormalVector.m_fY;
	stPOINT intersectionMetal = { 0, };
	stPOINT intersectionTape = { 0, };
	LineIntersection(img, verticalLineCenter, metalLine, intersectionMetal);
	LineIntersection(img, verticalLineCenter, tapeLineS2, intersectionTape);
	PointtoPointDistance(img, intersectionMetal, intersectionTape, s2Distance, s2DistanceLine);

	return TRUE;
}

/**
* @brief S1, S2, S3 거리 계산 함수
* @param CLPApp *app Geometry 객체 포인터
* @param stAPPIMAGEDATA *img Calibration App으로 보정 된 이미지 구조체 포인터
* @param const stLine &metalLine Metal 상단의 양 끝 점을 잇는 Line 구조체
* @param const stLine &tapeLineS3 Tape 중앙 우측 상단의 S3 부분의 Line fitting 결과 Line 구조체
* @param const double metalLineDistance Metal 상단의 길이 (d)
* @param double &s3Distance S3 측정 결과 값
* @param stLine &s3DistanceLine S3 측정 결과 표시 선
* @return 거리 계산 성공 여부
* @remark Calibration App process 후 호출해야 함
*/
BOOL CStepSizeCalculation::S3Distance(LP_VisionApp::stAPPIMAGEDATA *img, const stLine &metalLine, const stLine &tapeLineS3, const double metalLineDistance,
	double &s3Distance, stLine &s3DistanceLine)
{
	if (NULL == m_pGeometryApp || NULL == img || metalLineDistance <= 0)
		return FALSE;

	if ((metalLine.m_fStartX == 0 && metalLine.m_fStartY && metalLine.m_fEndX && metalLine.m_fEndY)
		|| (tapeLineS3.m_fStartX == 0 && tapeLineS3.m_fStartY && tapeLineS3.m_fEndX && tapeLineS3.m_fEndY))
		return FALSE;

	if (metalLineDistance <= S1_MARGIN || metalLineDistance <= S3_MARGIN)
		return FALSE;

	stPOINT metalVector, metalNormalVector;
	metalVector = { metalLine.m_fEndX - metalLine.m_fStartX, metalLine.m_fEndY - metalLine.m_fStartY };
	metalNormalVector = { -1 * metalVector.m_fY, metalVector.m_fX };

	stLine verticalLineS3;
	verticalLineS3.m_fStartX = metalLine.m_fEndX - metalVector.m_fX / metalLineDistance * S1_MARGIN;
	verticalLineS3.m_fStartY = metalLine.m_fEndY - metalVector.m_fY / metalLineDistance * S1_MARGIN;
	verticalLineS3.m_fEndX = verticalLineS3.m_fStartX + metalNormalVector.m_fX;
	verticalLineS3.m_fEndY = verticalLineS3.m_fStartY + metalNormalVector.m_fY;
	stPOINT intersectionMetal = { 0, };
	stPOINT intersectionTape = { 0, };
	LineIntersection(img, verticalLineS3, metalLine, intersectionMetal);
	LineIntersection(img, verticalLineS3, tapeLineS3, intersectionTape);
	PointtoPointDistance(img, intersectionMetal, intersectionTape, s3Distance, s3DistanceLine);

	return TRUE;
}


BOOL CStepSizeCalculation::S4Distance(LP_VisionApp::stAPPIMAGEDATA *img, const stLine &metalLine, const stPOINT &tapePt1, const stPOINT &tapePt2,
	double &s4Distance, stLine &s4DistanceLine)
{
	if (NULL == m_pGeometryApp || NULL == img)
		return FALSE;

	if ((metalLine.m_fStartX == 0 && metalLine.m_fStartY && metalLine.m_fEndX && metalLine.m_fEndY)
		|| (tapePt1.m_fX == 0 && tapePt1.m_fY && tapePt2.m_fX == 0 && tapePt2.m_fY))
		return FALSE;

	double dist1 = 0., dist2 = 0.;
	stLine line1 = { 0.f, 0.f, 0.f, 0.f }, line2 = { 0.f, 0.f, 0.f, 0.f };

	BOOL success1 = PointtoLineDistance(img, metalLine, tapePt1, dist1, line1);
	BOOL success2 = PointtoLineDistance(img, metalLine, tapePt2, dist2, line2);

	if (success1 == FALSE && success2 == FALSE)
		return FALSE;

	if (dist1 >= dist2)
	{
		s4Distance = dist1;
		s4DistanceLine = line1;
	}
	else
	{
		s4Distance = dist2;
		s4DistanceLine = line2;
	}
	return TRUE;
}

BOOL CStepSizeCalculation::S5Distance(LP_VisionApp::stAPPIMAGEDATA *img, const stLine &metalLine, const stPOINT &tapePt1, const stPOINT &tapePt2,
	double &s5Distance, stLine &s5DistanceLine)
{
	if (NULL == m_pGeometryApp || NULL == img)
		return FALSE;

	if ((metalLine.m_fStartX == 0 && metalLine.m_fStartY && metalLine.m_fEndX && metalLine.m_fEndY)
		|| (tapePt1.m_fX == 0 && tapePt1.m_fY && tapePt2.m_fX == 0 && tapePt2.m_fY))
		return FALSE;

	double dist1 = 0., dist2 = 0.;
	stLine line1 = { 0.f, 0.f, 0.f, 0.f }, line2 = { 0.f, 0.f, 0.f, 0.f };

	BOOL success1 = PointtoLineDistance(img, metalLine, tapePt1, dist1, line1);
	BOOL success2 = PointtoLineDistance(img, metalLine, tapePt2, dist2, line2);

	if (success1 == FALSE && success2 == FALSE)
		return FALSE;

	if (dist1 >= dist2)
	{
		s5Distance = dist1;
		s5DistanceLine = line1;
	}
	else
	{
		s5Distance = dist2;
		s5DistanceLine = line2;
	}
	return TRUE;
}

/**
* @brief 치수 검사 설정 초기 값을 전달하는 함수
* @param INFO_INSPECTION_SIZE *info 초기 값을 받을 구조체 포인터
*/
void CStepSizeCalculation::GetDefaultCalcSetting(INFO_INSPECTION_SIZE_CALC *info)
{
	memset(&info->m_stCalibration, 0, sizeof(INFO_CALIBRATION));

	for (int i = 0; i < sizeof(INFO_SIZE_GAIN_NAME) / sizeof(double); i++)
		info->m_stSizeGain.m_dGain[i] = 1.0;
}

void CStepSizeCalculation::CalcDistance(CSampleSide& sample, cv::Mat captureImg)
{
	memcpy(&sample.m_SizeCalculationResult, &sample.m_SizeResult, sizeof(OUTPUT_SIZE));

	PreProcess(captureImg);
#ifdef DEF_CALC_VER2
	CalcDistanceCompareValues(captureImg, sample);
#else
	CalcDistanceCompareValues(sample);
	CalcDistanceSPoint(sample);
	CalcDistanceRpoint(sample);
#endif
	MultiplyGain(sample);
	DecideResult(sample);
}

void CStepSizeCalculation::CalcDistanceCompareValues(cv::Mat captureImg, CSampleSide& sample)
{
	stAPPIMAGEDATA grayImg;
	memset(&grayImg, 0, sizeof(stAPPIMAGEDATA));
	grayImg.m_pSrcImage = m_GrayMat.data;
	grayImg.m_iChannel = 1;
	grayImg.m_iDepth = DEPTH_8U;
	grayImg.m_iWidth = m_GrayMat.size().width;
	grayImg.m_iHeight = m_GrayMat.size().height;
	grayImg.m_iWidthStep = m_GrayMat.step1();
	grayImg.m_iImageSize = grayImg.m_iWidthStep * grayImg.m_iHeight;

	stPOINT *stFirstPoint = sample.m_SizeResult.m_stResultPoint;
	stLine *stFirstLine = sample.m_SizeResult.m_stResultLine;
	stLine *stSecondLine = sample.m_SizeSecondResult.m_stResultLine;

	OUTPUT_DISTANCE *stDistance = sample.m_SizeCalculationResult.m_stDistance;
	stLine *stDistanceLine = sample.m_SizeCalculationResult.m_stDistanceLine;
	stPOINT *stResultPoint = sample.m_SizeCalculationResult.m_stResultPoint;
	
	bool *bFisrtFindLineResult = sample.m_SizeResult.m_bFindLineResult;
	bool *bSecondFindLineResult = sample.m_SizeSecondResult.m_bFindLineResult;

	LineIntersection(&grayImg, stFirstLine[L_TL_L], stSecondLine[L_TL_B], stResultPoint[P_TL_B]); // 좌하
	LineIntersection(&grayImg, stSecondLine[L_TL_T], stFirstLine[L_TL_L], stResultPoint[P_TL_T]); // 좌상
	LineIntersection(&grayImg, stSecondLine[L_TC_TL], stFirstLine[L_M_L], stResultPoint[P_TC_TL]); // 중좌상
	LineIntersection(&grayImg, stSecondLine[L_TC_TR], stFirstLine[L_M_R], stResultPoint[P_TC_TR]); // 중우상
	LineIntersection(&grayImg, stSecondLine[L_TR_T], stFirstLine[L_TR_R], stResultPoint[P_TR_T]); // 우상
	LineIntersection(&grayImg, stFirstLine[L_TR_R], stSecondLine[L_TR_B], stResultPoint[P_TR_B]); // 우하

	if (bSecondFindLineResult[L_TL_T] && bFisrtFindLineResult[L_TL_L] && bSecondFindLineResult[L_TC_TL] && bFisrtFindLineResult[L_M_L])
		MidPoint(&grayImg, stResultPoint[P_TL_T], stResultPoint[P_TC_TL], stResultPoint[P_TL_TC]); // 테이프 좌상 중심
	if (bSecondFindLineResult[L_TC_TR] && bFisrtFindLineResult[L_M_R] && bSecondFindLineResult[L_TR_T] && bFisrtFindLineResult[L_TR_R])
		MidPoint(&grayImg, stResultPoint[P_TC_TR], stResultPoint[P_TR_T], stResultPoint[P_TR_TC]); // 테이프 우상 중심

	//
	if (bFisrtFindLineResult[L_M_R] && bFisrtFindLineResult[L_M_L])
		LinetoLineDistance(&grayImg, stFirstLine[L_M_R], stFirstLine[L_M_L], stDistance[D_D].m_dValue, stDistanceLine[D_D]); // d
	if (bFisrtFindLineResult[L_M_T] && bFisrtFindLineResult[L_M_B])
		LinetoLineDistance(&grayImg, stFirstLine[L_M_T], stFirstLine[L_M_B], stDistance[D_L].m_dValue, stDistanceLine[D_L]); // L
	if (bFisrtFindLineResult[L_TL_L] && bFisrtFindLineResult[L_TR_R])
		LinetoLineDistance(&grayImg, stFirstLine[L_TL_L], stFirstLine[L_TR_R], stDistance[D_W].m_dValue, stDistanceLine[D_W]); // W
	
	if (bSecondFindLineResult[L_TL_T] && bFisrtFindLineResult[L_TL_L] && bSecondFindLineResult[L_TL_B])
		LinetoLineDistance(&grayImg, stSecondLine[L_TL_T], stSecondLine[L_TL_B], stDistance[D_I1].m_dValue, stDistanceLine[D_I1]); //I1
		//PointtoPointDistance(&grayImg, stResultPoint[P_TL_B], stResultPoint[P_TL_T], stDistance[D_I1].m_dValue, stDistanceLine[D_I1]); // I1 기존. 날개 끝 폭. 교점
	if (bSecondFindLineResult[L_TC_T] && bSecondFindLineResult[L_TC_B])
		LinetoLineDistance(&grayImg, stSecondLine[L_TC_T], stSecondLine[L_TC_B], stDistance[D_I2].m_dValue, stDistanceLine[D_I2]); // I2
	if (bSecondFindLineResult[L_TR_T] && bFisrtFindLineResult[L_TR_R] && bSecondFindLineResult[L_TR_B])
		LinetoLineDistance(&grayImg, stSecondLine[L_TR_T], stSecondLine[L_TR_B], stDistance[D_I3].m_dValue, stDistanceLine[D_I3]); //I3
		//PointtoPointDistance(&grayImg, stResultPoint[P_TR_T], stResultPoint[P_TR_B], stDistance[D_I3].m_dValue, stDistanceLine[D_I3]); // I3 기존. 날개 끝 폭. 교점

	if (bFisrtFindLineResult[L_TL_L] && bFisrtFindLineResult[L_M_L])
		LinetoLineDistance(&grayImg, stFirstLine[L_TL_L], stFirstLine[L_M_L], stDistance[D_M1].m_dValue, stDistanceLine[D_M1]); // M1
	if (bFisrtFindLineResult[L_TR_R] && bFisrtFindLineResult[L_M_R])
		LinetoLineDistance(&grayImg, stFirstLine[L_TR_R], stFirstLine[L_M_R], stDistance[D_M2].m_dValue, stDistanceLine[D_M2]); // M2

	if (bFisrtFindLineResult[L_M_T] && bFisrtFindLineResult[L_M_L] && bFisrtFindLineResult[L_M_R])
	{
		stLine metalTopLine = { stFirstPoint[P_M_TL].m_fX, stFirstPoint[P_M_TL].m_fY, stFirstPoint[P_M_TR].m_fX, stFirstPoint[P_M_TR].m_fY };
		if (bSecondFindLineResult[L_TC_TL])
		S1Distance(&grayImg, metalTopLine, stSecondLine[L_TC_TL], stDistance[D_D].m_dValue * m_stInfoCalc.m_stSizeGain.m_stGainName.m_dd, stDistance[D_S1].m_dValue, stDistanceLine[D_S1]); // S1
		if (bSecondFindLineResult[L_TC_T])
		S2Distance(&grayImg, metalTopLine, stSecondLine[L_TC_T], stDistance[D_D].m_dValue * m_stInfoCalc.m_stSizeGain.m_stGainName.m_dd, stDistance[D_S2].m_dValue, stDistanceLine[D_S2]); // S2
		if (bSecondFindLineResult[L_TC_TR])
		S3Distance(&grayImg, metalTopLine, stSecondLine[L_TC_TR], stDistance[D_D].m_dValue * m_stInfoCalc.m_stSizeGain.m_stGainName.m_dd, stDistance[D_S3].m_dValue, stDistanceLine[D_S3]); // S3
		if (bSecondFindLineResult[L_TL_T] && bFisrtFindLineResult[L_TL_L] && bSecondFindLineResult[L_TC_TL] && bFisrtFindLineResult[L_M_L])
			PointtoLineDistance(&grayImg, metalTopLine, stResultPoint[P_TL_TC], stDistance[D_S4].m_dValue, stDistanceLine[D_S4]); // S4
		if (bSecondFindLineResult[L_TC_TR] && bFisrtFindLineResult[L_M_R] && bSecondFindLineResult[L_TR_T] && bFisrtFindLineResult[L_TR_R])
			PointtoLineDistance(&grayImg, metalTopLine, stResultPoint[P_TR_TC], stDistance[D_S5].m_dValue, stDistanceLine[D_S5]); // S5
	}

	if (bFisrtFindLineResult[L_M_T] && bFisrtFindLineResult[L_M_R] && bFisrtFindLineResult[L_M_B] && bFisrtFindLineResult[L_M_L])
	{
		PointtoPointDistance(&grayImg, stFirstPoint[P_M_BR], stFirstPoint[P_M_TL], stDistance[D_X1].m_dValue, stDistanceLine[D_X1]); // X1
		PointtoPointDistance(&grayImg, stFirstPoint[P_M_TR], stFirstPoint[P_M_BL], stDistance[D_X2].m_dValue, stDistanceLine[D_X2]); // X2
	}

	// Version 1.3.7.5 R1 ~ R6
	// R1 ~ R4 Init ?
	/*for (int i = TYPE_GEOMETRY_DISTANCE_R1; i <= (int)TYPE_GEOMETRY_DISTANCE_R4; i++){
		stDistance[i].m_dValue = 0.0;
		stDistanceLine[i].m_fEndX = 0.0f;
		stDistanceLine[i].m_fEndY = 0.0f;
		stDistanceLine[i].m_fStartX = 0.0f;
		stDistanceLine[i].m_fStartY = 0.0f;
	}*/
	// Version 1.3.7.5 R1 ~ R6
	if (bFisrtFindLineResult[L_TC_TL] && bSecondFindLineResult[L_TC_TL])
		LinetoLineDistance(&grayImg, stFirstLine[L_TC_TL], stSecondLine[L_TC_TL], stDistance[D_R1].m_dValue, stDistanceLine[D_R1]); // R1
	if (bFisrtFindLineResult[L_TC_T] && bSecondFindLineResult[L_TC_T])
		LinetoLineDistance(&grayImg, stFirstLine[L_TC_T],  stSecondLine[L_TC_T],  stDistance[D_R2].m_dValue, stDistanceLine[D_R2]); // R2
	if (bFisrtFindLineResult[L_TC_TR] && bSecondFindLineResult[L_TC_TR])
		LinetoLineDistance(&grayImg, stFirstLine[L_TC_TR], stSecondLine[L_TC_TR], stDistance[D_R3].m_dValue, stDistanceLine[D_R3]); // R3
	if (bFisrtFindLineResult[L_TC_BL] && bSecondFindLineResult[L_TC_BL])
		LinetoLineDistance(&grayImg, stFirstLine[L_TC_BL], stSecondLine[L_TC_BL], stDistance[D_R4].m_dValue, stDistanceLine[D_R4]); // R4
	if (bFisrtFindLineResult[L_TC_B] && bSecondFindLineResult[L_TC_B])
		LinetoLineDistance(&grayImg, stFirstLine[L_TC_B],  stSecondLine[L_TC_B],  stDistance[D_R5].m_dValue, stDistanceLine[D_R5]); // R5
	if (bFisrtFindLineResult[L_TC_BR] && bSecondFindLineResult[L_TC_BR])
		LinetoLineDistance(&grayImg, stFirstLine[L_TC_BR], stSecondLine[L_TC_BR], stDistance[D_R6].m_dValue, stDistanceLine[D_R6]); // R6

	if (bSecondFindLineResult[L_TC_BL] && bSecondFindLineResult[L_M_B])
		LinetoLineDistance(&grayImg, stSecondLine[L_TC_BL], stSecondLine[L_M_B], stDistance[D_SS1].m_dValue, stDistanceLine[D_SS1]); // SS1
	if (bSecondFindLineResult[L_TC_B] && bSecondFindLineResult[L_M_B])
		LinetoLineDistance(&grayImg, stSecondLine[L_TC_B], stSecondLine[L_M_B], stDistance[D_SS2].m_dValue, stDistanceLine[D_SS2]); // SS2
	if (bSecondFindLineResult[L_TC_BR] && bSecondFindLineResult[L_M_B])
		LinetoLineDistance(&grayImg, stSecondLine[L_TC_BR], stSecondLine[L_M_B], stDistance[D_SS3].m_dValue, stDistanceLine[D_SS3]); // SS3


	// Relative ROI Point

	CLPApp **pFindLineApp = NULL;

	pFindLineApp = m_pFindLineApp;

	for (int i = TYPE_FINDLINE_METAL_TOP; i <= TYPE_FINDLINE_METAL_LEFT; i++)
	{
		vector<CLP_ROI> roi;
		pFindLineApp[i]->GetROI(&roi);

		if (roi.size() > 0 && roi.at(0).m_pstPosArray.size() >= 4)
		{
			for (int j = 0; j < 4; j++)
			{
				sample.m_SizeCalculationResult.m_stROIPoint[i].m_pt[j] = m_stCurruntROIPoint[i].m_pt[j] = roi.at(0).m_pstPosArray.at(j);
			}
		}
	}

	for (int i = TYPE_FINDLINE_TAPE_LEFTWING_TOP; i < TYPE_FINDLINE_MAX; i++)
	{
		vector<CLP_ROI> roi;
		pFindLineApp[i]->GetRelativeROI(&roi);

		if (roi.size() > 0 && roi.at(0).m_pstPosArray.size() >= 4)
		{
			for (int j = 0; j < 4; j++)
			{
				sample.m_SizeCalculationResult.m_stROIPoint[i].m_pt[j] = m_stCurruntROIPoint[i].m_pt[j] = roi.at(0).m_pstPosArray.at(j);
			}
		}
		else
		{
			pFindLineApp[i]->GetROI(&roi);

			if (roi.size() > 0 && roi.at(0).m_pstPosArray.size() >= 4)
			{
				for (int j = 0; j < 4; j++)
				{
					sample.m_SizeCalculationResult.m_stROIPoint[i].m_pt[j] = m_stCurruntROIPoint[i].m_pt[j] = roi.at(0).m_pstPosArray.at(j);
				}
			}
		}
	}
}

void CStepSizeCalculation::CalcDistanceCompareValues(CSampleSide& sample)
{
	OUTPUT_SIZE* pResult = &sample.m_SizeCalculationResult;
	OUTPUT_SIZE* pFirst = &sample.m_SizeResult;
	OUTPUT_SIZE* pSecond = &sample.m_SizeSecondResult;
	OUTPUT_SIZE* pSelected = NULL;

	for (int i = 0; i <= (int)TYPE_GEOMETRY_DISTANCE_X2; i++){
		switch (i)
		{
			// 큰 값을 사용하는 부분
			// d, L, W, X
		case TYPE_GEOMETRY_DISTANCE_D:
		case TYPE_GEOMETRY_DISTANCE_L:
		case TYPE_GEOMETRY_DISTANCE_W:
		case TYPE_GEOMETRY_DISTANCE_X1:
		case TYPE_GEOMETRY_DISTANCE_X2:
			if (pFirst->m_stDistance[i].m_dValue >= pSecond->m_stDistance[i].m_dValue)
				pSelected = pFirst;
			else
				pSelected = pSecond;
			pResult->m_stDistance[i] = pSelected->m_stDistance[i];
			pResult->m_stDistanceLine[i] = pSelected->m_stDistanceLine[i];

			if (i == TYPE_GEOMETRY_DISTANCE_D)
			{
				pResult->m_stResultLine[L_M_R] = pSelected->m_stResultLine[L_M_R];
				pResult->m_stResultLine[L_M_L] = pSelected->m_stResultLine[L_M_L];
			}
			else if (i == TYPE_GEOMETRY_DISTANCE_L)
			{
				pResult->m_stResultLine[L_M_T] = pSelected->m_stResultLine[L_M_T];
				pResult->m_stResultLine[L_M_B] = pSelected->m_stResultLine[L_M_B];
			}
			else if (i == TYPE_GEOMETRY_DISTANCE_W)
			{
				pResult->m_stResultLine[L_TL_L] = pSelected->m_stResultLine[L_TL_L];
				pResult->m_stResultLine[L_TR_R] = pSelected->m_stResultLine[L_TR_R];
			}
			break;

			// 작은 값을 사용하는 부분
			// I, M
		case TYPE_GEOMETRY_DISTANCE_I1:
		case TYPE_GEOMETRY_DISTANCE_I2:
		case TYPE_GEOMETRY_DISTANCE_I3:
		case TYPE_GEOMETRY_DISTANCE_M1:
		case TYPE_GEOMETRY_DISTANCE_M2:
			if (pFirst->m_stDistance[i].m_dValue <= pSecond->m_stDistance[i].m_dValue)
			{
				if (pFirst->m_stDistance[i].m_dValue > 0.0)
					pSelected = pFirst;
				else
					pSelected = pSecond;
			}
			else
			{
				if (pSecond->m_stDistance[i].m_dValue > 0.0)
					pSelected = pSecond;
				else
					pSelected = pFirst;
			}
			pResult->m_stDistance[i] = pSelected->m_stDistance[i];
			pResult->m_stDistanceLine[i] = pSelected->m_stDistanceLine[i];

			if (i == TYPE_GEOMETRY_DISTANCE_I1)
			{
				pResult->m_stResultLine[L_TC_TL] = pSelected->m_stResultLine[L_TC_TL];
				pResult->m_stResultLine[L_TC_BL] = pSelected->m_stResultLine[L_TC_BL];
			}
			else if (i == TYPE_GEOMETRY_DISTANCE_I2)
			{
				pResult->m_stResultLine[L_TC_T] = pSelected->m_stResultLine[L_TC_T];
				pResult->m_stResultLine[L_TC_B] = pSelected->m_stResultLine[L_TC_B];
			}
			else if (i == TYPE_GEOMETRY_DISTANCE_I3)
			{
				pResult->m_stResultLine[L_TC_TR] = pSelected->m_stResultLine[L_TC_TR];
				pResult->m_stResultLine[L_TC_BR] = pSelected->m_stResultLine[L_TC_BR];
			}
			break;

		default:
			break;
		}
	}
}

void CStepSizeCalculation::CalcDistanceSPoint(CSampleSide& sample)
{
	// 두 이미지의 결과를 조합

	stAPPIMAGEDATA grayImg;
	memset(&grayImg, 0, sizeof(stAPPIMAGEDATA));
	grayImg.m_pSrcImage = m_GrayMat.data;
	grayImg.m_iChannel = 1;
	grayImg.m_iDepth = DEPTH_8U;
	grayImg.m_iWidth = m_GrayMat.size().width;
	grayImg.m_iHeight = m_GrayMat.size().height;
	grayImg.m_iWidthStep = m_GrayMat.step1();
	grayImg.m_iImageSize = grayImg.m_iWidthStep * grayImg.m_iHeight;

	OUTPUT_DISTANCE *stDistance = sample.m_SizeCalculationResult.m_stDistance;
	stLine *stDistanceLine = sample.m_SizeCalculationResult.m_stDistanceLine;
	stLine *stResultLine = sample.m_SizeCalculationResult.m_stResultLine;

	stLine *stFirstLine = sample.m_SizeResult.m_stResultLine;
	stPOINT *stFirstPt = sample.m_SizeResult.m_stResultPoint;
	stLine *stSecondLine = sample.m_SizeSecondResult.m_stResultLine;
	stPOINT *stSecondPt = sample.m_SizeSecondResult.m_stResultPoint;

	OUTPUT_SIZE* pResult = &sample.m_SizeCalculationResult;

	// Geometry (Line Intersection): Metal
	stPOINT metalStartPt = { 0.f, 0.f }, metalEndPt = { 0.f, 0.f };
	LineIntersection(&grayImg, stResultLine[L_M_T], stResultLine[L_M_L], metalStartPt);
	LineIntersection(&grayImg, stResultLine[L_M_T], stResultLine[L_M_R], metalEndPt);

	{
		stLine metalTopLine = { metalStartPt.m_fX, metalStartPt.m_fY, metalEndPt.m_fX, metalEndPt.m_fY };
		
		S1Distance(&grayImg, metalTopLine, stResultLine[L_TC_TL], stDistance[D_D].m_dValue * m_stInfoCalc.m_stSizeGain.m_stGainName.m_dd,
			stDistance[D_S1].m_dValue, stDistanceLine[D_S1]);
		S2Distance(&grayImg, metalTopLine, stResultLine[L_TC_T], stDistance[D_D].m_dValue * m_stInfoCalc.m_stSizeGain.m_stGainName.m_dd,
			stDistance[D_S2].m_dValue, stDistanceLine[D_S2]);
		S3Distance(&grayImg, metalTopLine, stResultLine[L_TC_TR], stDistance[D_D].m_dValue * m_stInfoCalc.m_stSizeGain.m_stGainName.m_dd,
			stDistance[D_S3].m_dValue, stDistanceLine[D_S3]);

		S4Distance(&grayImg, metalTopLine, stFirstPt[P_TL_TC], stSecondPt[P_TL_TC], stDistance[D_S4].m_dValue, stDistanceLine[D_S4]);
		S5Distance(&grayImg, metalTopLine, stFirstPt[P_TR_TC], stSecondPt[P_TR_TC], stDistance[D_S5].m_dValue, stDistanceLine[D_S5]);
	}
}

void CStepSizeCalculation::CalcDistanceRpoint(CSampleSide& sample)
{
	stAPPIMAGEDATA grayImg;
	memset(&grayImg, 0, sizeof(stAPPIMAGEDATA));
	grayImg.m_pSrcImage = m_GrayMat.data;
	grayImg.m_iChannel = 1;
	grayImg.m_iDepth = DEPTH_8U;
	grayImg.m_iWidth = m_GrayMat.size().width;
	grayImg.m_iHeight = m_GrayMat.size().height;
	grayImg.m_iWidthStep = m_GrayMat.step1();
	grayImg.m_iImageSize = grayImg.m_iWidthStep * grayImg.m_iHeight;

	OUTPUT_DISTANCE *stDistance = sample.m_SizeCalculationResult.m_stDistance;
	stLine *stDistanceLine = sample.m_SizeCalculationResult.m_stDistanceLine;

	stLine *stFirstLine = sample.m_SizeResult.m_stResultLine;
	stLine *stSecondLine = sample.m_SizeSecondResult.m_stResultLine;

	//if (bFindLineResult[L_TC_TL] && bFindLineResult[L_TC_TL])
	LinetoLineDistance(&grayImg, stFirstLine[L_TC_TL], stSecondLine[L_TC_TL], stDistance[D_R1].m_dValue, stDistanceLine[D_R1]); // R1
	LinetoLineDistance(&grayImg, stFirstLine[L_TC_TR], stSecondLine[L_TC_TR], stDistance[D_R2].m_dValue, stDistanceLine[D_R2]); // R2
	LinetoLineDistance(&grayImg, stFirstLine[L_TC_BL], stSecondLine[L_TC_BL], stDistance[D_R3].m_dValue, stDistanceLine[D_R3]); // R3
	LinetoLineDistance(&grayImg, stFirstLine[L_TC_BR], stSecondLine[L_TC_BR], stDistance[D_R4].m_dValue, stDistanceLine[D_R4]); // R4
}

void CStepSizeCalculation::MultiplyGain(CSampleSide& sample)
{
	OUTPUT_DISTANCE *stDistance = sample.m_SizeCalculationResult.m_stDistance;

	// Gain
	// Version 1.3.7.5
	for (int i = 0; i <= D_SS3; i++)
	{
		if (m_stInfoCalc.m_stSizeGain.m_dGain[i] > 0)
			stDistance[i].m_dValue *= m_stInfoCalc.m_stSizeGain.m_dGain[i];
	}
}

// Versio 1.3.7.9 이름 미설정된 치수 -> 무조건 OK 판정
void CStepSizeCalculation::DecideResult(CSampleSide& sample)
{
	//OUTPUT_DISTANCE *stDistance = sample.m_SizeCalculationResult.m_stDistance;
	stDistance = sample.m_SizeCalculationResult.m_stDistance;
	//CCaptureManager* pCaptureManager = CCaptureManager::GetInstance();
	INFO_OPTION m_stOption;

	if (stDistance[D_X1].m_dValue	!= .0 && stDistance[D_X2].m_dValue	!= .0)		stDistance[D_X1X2].m_dValue		= stDistance[D_X1].m_dValue - stDistance[D_X2].m_dValue; // X1 - X2
	if (stDistance[D_S1].m_dValue	!= .0 && stDistance[D_S3].m_dValue	!= .0)		stDistance[D_S1S3].m_dValue		= stDistance[D_S1].m_dValue - stDistance[D_S3].m_dValue; // S1 - S3
	if (stDistance[D_M1].m_dValue	!= .0 && stDistance[D_M2].m_dValue	!= .0)		stDistance[D_M1M2].m_dValue		= stDistance[D_M1].m_dValue - stDistance[D_M2].m_dValue; // M1 - M2
	// Version 1.3.7.5 R1 ~ R6, SS1 ~ SS3
	if (stDistance[D_SS1].m_dValue	!= .0 && stDistance[D_SS3].m_dValue != .0)		stDistance[D_SS1SS3].m_dValue	= stDistance[D_SS1].m_dValue - stDistance[D_SS3].m_dValue; // SS1 - SS3

	// OK/NG
	if (NULL != sample.m_pstRefOptRangeList)
	{
		for (int i = 0; i < sample.m_nRangeCount && i < TYPE_GEOMETRY_DISTANCE_MAX; i++)
		{
			double dMin = sample.m_pstRefOptRangeList[i].m_fMin;
			double dMax = sample.m_pstRefOptRangeList[i].m_fMax;
			stDistance[i].m_bOK = ((stDistance[i].m_dValue >= dMin) && (stDistance[i].m_dValue <= dMax)) ? true : false;
		}
	}

	// Spec
	if (NULL != sample.m_pstRefOptRangeSpecList)
	{
		for (int i = 0; i < sample.m_nRangeCount && i < TYPE_GEOMETRY_DISTANCE_MAX; i++)
		{
			double dMin = sample.m_pstRefOptRangeSpecList[i].m_fMin;
			double dMax = sample.m_pstRefOptRangeSpecList[i].m_fMax;
			stDistance[i].m_bSpec = ((stDistance[i].m_dValue >= dMin) && (stDistance[i].m_dValue <= dMax)) ? true : false;
		}
	}
}

BOOL CStepSizeCalculation::IsInit()
{
	return m_bInit;
}

void CStepSizeCalculation::Log(char* pszLog, ...)
{
	if (m_stLogFunc.m_pFuncTextLog && m_stLogFunc.m_pArg)
	{
		char szLog[MAX_TEXT_LEN] = { 0, };

		va_list arg;
		va_start(arg, pszLog);
		_vsntprintf(szLog, sizeof(szLog), pszLog, arg);
		va_end(arg);

		CUtil::PrintDebugString(_T("%s\r\n"), szLog);
		m_stLogFunc.m_pFuncTextLog(m_stLogFunc.m_pArg, this->m_eCameraPos, m_strStepName.c_str(), szLog);
	}
}
