/**
* @file StepSize.cpp
* @brief StepSizeSecond 클래스 정의 파일
* @author Junmock Lee  * @Modified Jongik
* @date 2017-07-25     * @date 2020-07-13
*/
#include "StdAfx.h"
#include "StepSizeSecond.h"

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

#define D_D TYPE_GEOMETRY_DISTANCE_D
#define D_L TYPE_GEOMETRY_DISTANCE_L
#define D_W TYPE_GEOMETRY_DISTANCE_W
#define D_I1 TYPE_GEOMETRY_DISTANCE_I1
#define D_I2 TYPE_GEOMETRY_DISTANCE_I2
#define D_I3 TYPE_GEOMETRY_DISTANCE_I3
#define D_M1 TYPE_GEOMETRY_DISTANCE_M1
#define D_M2 TYPE_GEOMETRY_DISTANCE_M2
#define D_S1 TYPE_GEOMETRY_DISTANCE_S1
#define D_S2 TYPE_GEOMETRY_DISTANCE_S2
#define D_S3 TYPE_GEOMETRY_DISTANCE_S3
#define D_S4 TYPE_GEOMETRY_DISTANCE_S4
#define D_S5 TYPE_GEOMETRY_DISTANCE_S5
#define D_X1 TYPE_GEOMETRY_DISTANCE_X1
#define D_X2 TYPE_GEOMETRY_DISTANCE_X2
#define D_R1 TYPE_GEOMETRY_DISTANCE_R1
#define D_R2 TYPE_GEOMETRY_DISTANCE_R2
#define D_R3 TYPE_GEOMETRY_DISTANCE_R3
#define D_R4 TYPE_GEOMETRY_DISTANCE_R4
#define D_X1X2 TYPE_GEOMETRY_DISTANCE_X1X2
#define D_S1S3 TYPE_GEOMETRY_DISTANCE_S1S3
#define D_M1M2 TYPE_GEOMETRY_DISTANCE_M1M2

using namespace cv;


const int CStepSizeSecond::m_iDefaultDirection[TYPE_FINDLINE_MAX] = { 0, 2, 1, 3, 0, 3, 1, 0, 0, 0, 1, 1, 1, 0, 2, 1 };
const int CStepSizeSecond::m_iDefaultPolarity[TYPE_FINDLINE_MAX] = { 2, 2, 2, 2, 2, 2, 2, 0, 0, 0, 0, 0, 0, 2, 2, 2 };
const int CStepSizeSecond::m_iDefaultLookFor[TYPE_FINDLINE_MAX] = { 0, };
const int CStepSizeSecond::m_iDefaultStrengthThreshold[TYPE_FINDLINE_MAX] = { 60, 60, 60, 60, 10, 10, 10, 20, 20, 20, 20, 20, 20, 10, 10, 10 };
const int CStepSizeSecond::m_iDefaultSampling[TYPE_FINDLINE_MAX] = { 50, 50, 50, 50, 10, 10, 10, 20, 20, 20, 20, 20, 20, 10, 10, 10 };
const int CStepSizeSecond::m_iDefaultKernelSize[TYPE_FINDLINE_MAX] = { 3, 3, 3, 3, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7 };

/**
* @brief 생성자
*/
CStepSizeSecond::CStepSizeSecond()
	: CStep("SIZE_2")
{
	memset(&m_stInfoSize, 0x00, sizeof(INFO_INSPECTION_SIZE));
	for (int i = 0; i < MAX_STEPSTROBE_LIST; i++)
	{
		m_stInfoSize.m_pstStepStrobe[i].m_eStrobeType = TYPE_STROBE_OFF;
		m_stInfoSize.m_pstStepStrobe[i].m_nStrobeBrightness = 0;
	}


	m_iCalInit = ERR_ERROR;
	memset(m_stCurruntROIPoint, 0, sizeof(OUTPUT_ROI) * TYPE_FINDLINE_MAX);

	m_pCalibrationApp = NULL;

	for (int i = 0; i < TYPE_FINDLINE_MAX; i++)
		m_pFindLineApp[i] = NULL;

	m_pGeometryApp = NULL;
}

/**
* @brief 소멸자
*/
CStepSizeSecond::~CStepSizeSecond()
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
BOOL CStepSizeSecond::Init(TYPE_CAMERAPOS eCameraPos, INFO_LOGFUNC stLogFunc)
{
	BOOL bResult = TRUE;

	Deinit();

	DongleLogin();

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
void CStepSizeSecond::Deinit()
{
	DongleLogout();

	m_iCalInit = ERR_ERROR;

	m_eCameraPos = TYPE_CAMERAPOS_NONE;
	memset(&m_stLogFunc, 0x00, sizeof(INFO_LOGFUNC));

	if (m_pCalibrationApp)
	{
		delete[] m_pCalibrationApp;
		m_pCalibrationApp = NULL;
	}

	for (int i = 0; i < TYPE_FINDLINE_MAX; i++)
	{
		if (m_pFindLineApp[i])
		{
			delete[] m_pFindLineApp[i];
			m_pFindLineApp[i] = NULL;
		}
	}

	if (m_pGeometryApp)
	{
		delete m_pGeometryApp;
		m_pGeometryApp = NULL;
	}

	m_bInit = FALSE;
}

/**
* @brief 검사 Process 수행 함수
* @param CSampleSide& sample 입력 이미지와 출력 데이터를 포함한 구조체
* @return 검사 완료 여부
*/
BOOL CStepSizeSecond::Process(CSampleSide& sample)
{
	auto starttime = chrono::high_resolution_clock::now();

	if (!DongleCheck())
	{
		Log("Fail to check dongle");

		if (!DongleLogin())
		{
#ifdef USE_BASLER_CAMERA
			m_OutputImage = Mat(Size(sample.m_pRefImage->m_stFrame.m_dwWidth, sample.m_pRefImage->m_stFrame.m_dwHeight), CV_8UC3, sample.m_pRefImage->m_pBuffer).clone();
#else
			m_OutputImage = Mat(Size(sample.m_pRefImage->m_stFrame.m_dwWidth, sample.m_pRefImage->m_stFrame.m_dwHeight), CV_8UC1, sample.m_pRefImage->m_pBuffer).clone();
#endif

			stAPPIMAGEDATA img;
			memset(&img, 0, sizeof(stAPPIMAGEDATA));
			img.m_pSrcImage = m_OutputImage.data;
			img.m_iChannel = m_OutputImage.channels();
			img.m_iDepth = DEPTH_8U;
			img.m_iWidth = m_OutputImage.size().width;
			img.m_iHeight = m_OutputImage.size().height;
			img.m_iWidthStep = m_OutputImage.step1();
			img.m_iImageSize = m_OutputImage.total() * m_OutputImage.channels();

			memcpy(&sample.m_SizeSecondResult.m_stCalibratedImage, &img, sizeof(stAPPIMAGEDATA));

			return FALSE;
		}
	}

	Log("Process Start");

	CLPApp **pFindLineApp = NULL;

	pFindLineApp = m_pFindLineApp;

#ifdef USE_BASLER_CAMERA
	// 예외처리
	if (!m_bInit ||
		pFindLineApp == NULL ||
		sample.m_pRefImage == NULL ||
		sample.m_pRefImage->m_pBuffer == NULL ||
		sample.m_pRefImage->m_stFrame.m_eColor != TYPE_CAMCOLOR_COLOR ||
		sample.m_pRefImage->m_stFrame.m_eDataBit != TYPE_DATABIT_08)
	{
		Log("Initialize/Image Error");
#if 1 // test code
		if (!m_bInit)
			Log("StepSize Initialize Error");
		else if (pFindLineApp == NULL)
			Log("StepSize pFindLineApp Error");
		else if (sample.m_pRefImage == NULL)
			Log("StepSize Image == NULL Error");
		else if (sample.m_pRefImage->m_pBuffer == NULL)
			Log("StepSize Buffer == NULL Error");
		else if (sample.m_pRefImage->m_stFrame.m_eColor != TYPE_CAMCOLOR_COLOR)
			Log("StepSize Color != TYPE_CAMCOLOR_COLOR Error");
		else if (sample.m_pRefImage->m_stFrame.m_eDataBit != TYPE_DATABIT_08)
			Log("StepSize DataBit != TYPE_DATABIT_08 Error");
		else
			Log("StepSize Undefined Error");
#endif
		return FALSE;
	}
#else
	// 예외처리
	if (!m_bInit ||
		pFindLineApp == NULL ||
		sample.m_pRefImage->m_pBuffer == NULL ||
		sample.m_pRefImage->m_stFrame.m_eColor != TYPE_CAMCOLOR_MONO ||
		sample.m_pRefImage->m_stFrame.m_eDataBit != TYPE_DATABIT_08)
	{
		Log("Initialize/Image Error");
#if 1 // test code
		if (!m_bInit)
			Log("StepSize Initialize Error");
		else if (pFindLineApp == NULL)
			Log("StepSize pFindLineApp Error");
		else if (sample.m_pRefImage == NULL)
			Log("StepSize Image == NULL Error");
		else if (sample.m_pRefImage->m_stFrame.m_eColor != TYPE_CAMCOLOR_MONO)
			Log("StepSize Color != TYPE_CAMCOLOR_COLOR Error");
		else if (sample.m_pRefImage->m_stFrame.m_eDataBit != TYPE_DATABIT_08)
			Log("StepSize DataBit != TYPE_DATABIT_08 Error");
		else
			Log("StepSize Undefined Error");
#endif
		return FALSE;
	}
#endif

	stLine *stResultLine = sample.m_SizeSecondResult.m_stResultLine;
	stPOINT *stResultPoint = sample.m_SizeSecondResult.m_stResultPoint;

	stAPPIMAGEDATA img, calibratedImg;
	memset(&img, 0, sizeof(stAPPIMAGEDATA));
	memset(&calibratedImg, 0, sizeof(stAPPIMAGEDATA));
	img.m_pSrcImage = sample.m_pRefImage->m_pBuffer;
#ifdef USE_BASLER_CAMERA
	img.m_iChannel = 3;
	img.m_iDepth = DEPTH_8U;
	img.m_iWidth = sample.m_pRefImage->m_stFrame.m_dwWidth;
	img.m_iHeight = sample.m_pRefImage->m_stFrame.m_dwHeight;
	img.m_iWidthStep = sample.m_pRefImage->m_stFrame.m_dwPitch;
	img.m_iImageSize = sample.m_pRefImage->m_nBufLen;
#else
	img.m_iChannel = 1;
	img.m_iDepth = DEPTH_8U;
	img.m_iWidth = sample.m_pRefImage->m_stFrame.m_dwWidth;
	img.m_iHeight = sample.m_pRefImage->m_stFrame.m_dwHeight;
	img.m_iWidthStep = img.m_iWidth * img.m_iChannel;
	img.m_iImageSize = sample.m_pRefImage->m_nBufLen;
#endif

	// Calibration
	m_pCalibrationApp->SetInput(&img);
	m_pCalibrationApp->Process();
	m_pCalibrationApp->GetOutput(CALIBRATION_RESULT_IMAGE, calibratedImg);
	// Calibration 실패 시 img 사용
	if (NULL == calibratedImg.m_pSrcImage)
		memcpy(&calibratedImg, &img, sizeof(stAPPIMAGEDATA));

#ifdef USE_BASLER_CAMERA
	Mat calibratedMat(calibratedImg.m_iHeight, calibratedImg.m_iWidth, CV_8UC3, calibratedImg.m_pSrcImage, calibratedImg.m_iWidthStep);
	cvtColor(calibratedMat, m_GrayMat, COLOR_BGR2GRAY);
	if (m_GrayMat.empty())
	{
#ifdef USE_BASLER_CAMERA
		m_OutputImage = Mat(Size(sample.m_pRefImage->m_stFrame.m_dwWidth, sample.m_pRefImage->m_stFrame.m_dwHeight), CV_8UC3, sample.m_pRefImage->m_pBuffer).clone();
#else
		m_OutputImage = Mat(Size(sample.m_pRefImage->m_stFrame.m_dwWidth, sample.m_pRefImage->m_stFrame.m_dwHeight), CV_8UC1, sample.m_pRefImage->m_pBuffer).clone();
#endif

		stAPPIMAGEDATA img;
		memset(&img, 0, sizeof(stAPPIMAGEDATA));
		img.m_pSrcImage = m_OutputImage.data;
		img.m_iChannel = m_OutputImage.channels();
		img.m_iDepth = DEPTH_8U;
		img.m_iWidth = m_OutputImage.size().width;
		img.m_iHeight = m_OutputImage.size().height;
		img.m_iWidthStep = m_OutputImage.step1();
		img.m_iImageSize = m_OutputImage.total() * m_OutputImage.channels();

		memcpy(&sample.m_SizeSecondResult.m_stCalibratedImage, &img, sizeof(stAPPIMAGEDATA));

		return FALSE;
	}

	stAPPIMAGEDATA grayImg;
	memset(&grayImg, 0, sizeof(stAPPIMAGEDATA));
	grayImg.m_pSrcImage = m_GrayMat.data;
	grayImg.m_iChannel = 1;
	grayImg.m_iDepth = DEPTH_8U;
	grayImg.m_iWidth = m_GrayMat.size().width;
	grayImg.m_iHeight = m_GrayMat.size().height;
	grayImg.m_iWidthStep = m_GrayMat.step1();
	grayImg.m_iImageSize = grayImg.m_iWidthStep * grayImg.m_iHeight;
#endif
	// FindLine: Metal
	double dAngle;
	bool bFindLineResult[TYPE_FINDLINE_MAX] = { false, };
	for (int i = TYPE_FINDLINE_METAL_TOP; i <= TYPE_FINDLINE_METAL_LEFT; i++)
	{
		if (pFindLineApp[i])
		{
#ifndef USE_BASLER_CAMERA
			pFindLineApp[i]->SetInput(&calibratedImg);
#else
			pFindLineApp[i]->SetInput(&grayImg);
#endif
			pFindLineApp[i]->Process();
			bFindLineResult[i] = (ERR_SUCCESS == pFindLineApp[i]->GetOutput(FINDLINE_LINE, stResultLine[i])) ? true : false;
			if (!bFindLineResult[i])
			{
				stResultLine[i] = { 0, 0, 0, 0 };
				Log("Cannot Find Line #%d", i);
			}
		}
	}
	if (pFindLineApp[0])
	{
		pFindLineApp[0]->GetOutput(FINDLINE_ANGLE, dAngle); // 첫번째 FindLine의 Angle 사용
		dAngle -= this->m_stInfoSize.m_pstFindLineROI[0].m_dAngle;
	}

	// Geometry (Line Intersection): Metal
	for (int i = TYPE_FINDLINE_METAL_TOP; i <= TYPE_FINDLINE_METAL_LEFT; i++)
	{
		if (bFindLineResult[i] && bFindLineResult[(i + 1) % FINDLINE_METAL_COUNT])
#ifndef USE_BASLER_CAMERA
			LineIntersection(&calibratedImg, stResultLine[i], stResultLine[(i + 1) % FINDLINE_METAL_COUNT], stResultPoint[i]);
#else
			LineIntersection(&grayImg, stResultLine[i], stResultLine[(i + 1) % FINDLINE_METAL_COUNT], stResultPoint[i]);
#endif
	}

	if (bFindLineResult[L_M_T] && bFindLineResult[L_M_L])
	{
		// FindLine: Tape
		for (int i = TYPE_FINDLINE_TAPE_LEFTWING_TOP; i < TYPE_FINDLINE_MAX; i++)
		{
			if (pFindLineApp[i])
			{
#ifndef USE_BASLER_CAMERA
				pFindLineApp[i]->SetInput(&calibratedImg);
#else
				pFindLineApp[i]->SetInput(&grayImg);
#endif
				pFindLineApp[i]->SetCurrentLocation(stResultPoint[P_M_TL], dAngle); // Metal 좌상단 점과 각도 기준. 이 부분 변경 시 SetInfoFindLineROI도 변경
				pFindLineApp[i]->Process();
				bFindLineResult[i] = (ERR_SUCCESS == pFindLineApp[i]->GetOutput(FINDLINE_LINE, stResultLine[i])) ? true : false;
				if (!bFindLineResult[i])
				{
					stResultLine[i] = { 0, 0, 0, 0 };
					Log("Cannot Find Line #%d", i);
				}
			}
		}

		// Geometry (Line Intersection): Tape
#ifndef USE_BASLER_CAMERA
		LineIntersection(&calibratedImg, stResultLine[L_TL_L], stResultLine[L_TL_B], stResultPoint[P_TL_B]); // 좌하
		LineIntersection(&calibratedImg, stResultLine[L_TL_T], stResultLine[L_TL_L], stResultPoint[P_TL_T]); // 좌상
		LineIntersection(&calibratedImg, stResultLine[L_TC_TL], stResultLine[L_M_L], stResultPoint[P_TC_TL]); // 중좌상
		LineIntersection(&calibratedImg, stResultLine[L_TC_TR], stResultLine[L_M_R], stResultPoint[P_TC_TR]); // 중우상
		LineIntersection(&calibratedImg, stResultLine[L_TR_T], stResultLine[L_TR_R], stResultPoint[P_TR_T]); // 우상
		LineIntersection(&calibratedImg, stResultLine[L_TR_R], stResultLine[L_TR_B], stResultPoint[P_TR_B]); // 우하

		if (bFindLineResult[L_TL_T] && bFindLineResult[L_TL_L] && bFindLineResult[L_TC_TL] && bFindLineResult[L_M_L])
			MidPoint(&calibratedImg, stResultPoint[P_TL_T], stResultPoint[P_TC_TL], stResultPoint[P_TL_TC]); // 테이프 좌상 중심
		if (bFindLineResult[L_TC_TR] && bFindLineResult[L_M_R] && bFindLineResult[L_TR_T] && bFindLineResult[L_TR_R])
			MidPoint(&calibratedImg, stResultPoint[P_TC_TR], stResultPoint[P_TR_T], stResultPoint[P_TR_TC]); // 테이프 우상 중심
#else
		LineIntersection(&grayImg, stResultLine[L_TL_L], stResultLine[L_TL_B], stResultPoint[P_TL_B]); // 좌하
		LineIntersection(&grayImg, stResultLine[L_TL_T], stResultLine[L_TL_L], stResultPoint[P_TL_T]); // 좌상
		LineIntersection(&grayImg, stResultLine[L_TC_TL], stResultLine[L_M_L], stResultPoint[P_TC_TL]); // 중좌상
		LineIntersection(&grayImg, stResultLine[L_TC_TR], stResultLine[L_M_R], stResultPoint[P_TC_TR]); // 중우상
		LineIntersection(&grayImg, stResultLine[L_TR_T], stResultLine[L_TR_R], stResultPoint[P_TR_T]); // 우상
		LineIntersection(&grayImg, stResultLine[L_TR_R], stResultLine[L_TR_B], stResultPoint[P_TR_B]); // 우하

		if (bFindLineResult[L_TL_T] && bFindLineResult[L_TL_L] && bFindLineResult[L_TC_TL] && bFindLineResult[L_M_L])
			MidPoint(&grayImg, stResultPoint[P_TL_T], stResultPoint[P_TC_TL], stResultPoint[P_TL_TC]); // 테이프 좌상 중심
		if (bFindLineResult[L_TC_TR] && bFindLineResult[L_M_R] && bFindLineResult[L_TR_T] && bFindLineResult[L_TR_R])
			MidPoint(&grayImg, stResultPoint[P_TC_TR], stResultPoint[P_TR_T], stResultPoint[P_TR_TC]); // 테이프 우상 중심
#endif
	}
	else
	{
		// Metal 기준점 찾지 못할 경우 Tape 찾지 않음
		Log("Cannot Find Metal Criteria");
	}

	// Geometry (Distance)
	OUTPUT_DISTANCE *stDistance = sample.m_SizeSecondResult.m_stDistance;
	stLine *stDistanceLine = sample.m_SizeSecondResult.m_stDistanceLine;

#ifndef USE_BASLER_CAMERA
	if (bFindLineResult[L_M_R] && bFindLineResult[L_M_L]) 
		LinetoLineDistance(&calibratedImg, stResultLine[L_M_R], stResultLine[L_M_L], stDistance[D_D].m_dValue, stDistanceLine[D_D]); // d
	if (bFindLineResult[L_M_T] && bFindLineResult[L_M_B])
		LinetoLineDistance(&calibratedImg, stResultLine[L_M_T], stResultLine[L_M_B], stDistance[D_L].m_dValue, stDistanceLine[D_L]); // L
	if (bFindLineResult[L_TL_L] && bFindLineResult[L_TR_R])
		LinetoLineDistance(&calibratedImg, stResultLine[L_TL_L], stResultLine[L_TR_R], stDistance[D_W].m_dValue, stDistanceLine[D_W]); // W

	if (bFindLineResult[L_TL_T] && bFindLineResult[L_TL_L] && bFindLineResult[L_TL_B])
		PointtoPointDistance(&calibratedImg, stResultPoint[P_TL_B], stResultPoint[P_TL_T], stDistance[D_I1].m_dValue, stDistanceLine[D_I1]); // I1
	if (bFindLineResult[L_TC_T] && bFindLineResult[L_TC_B])
		LinetoLineDistance(&calibratedImg, stResultLine[L_TC_T], stResultLine[L_TC_B], stDistance[D_I2].m_dValue, stDistanceLine[D_I2]); // I2
	if (bFindLineResult[L_TR_T] && bFindLineResult[L_TR_R] && bFindLineResult[L_TR_B])
		PointtoPointDistance(&calibratedImg, stResultPoint[P_TR_T], stResultPoint[P_TR_B], stDistance[D_I3].m_dValue, stDistanceLine[D_I3]); // I3

	if (bFindLineResult[L_TL_L] && bFindLineResult[L_M_L])
		LinetoLineDistance(&calibratedImg, stResultLine[L_TL_L], stResultLine[L_M_L], stDistance[D_M1].m_dValue, stDistanceLine[D_M1]); // M1
	if (bFindLineResult[L_TR_R] && bFindLineResult[L_M_R])
		LinetoLineDistance(&calibratedImg, stResultLine[L_TR_R], stResultLine[L_M_R], stDistance[D_M2].m_dValue, stDistanceLine[D_M2]); // M2

	if (bFindLineResult[L_M_T] && bFindLineResult[L_M_L] && bFindLineResult[L_M_R])
	{
		stLine metalTopLine = { stResultPoint[P_M_TL].m_fX, stResultPoint[P_M_TL].m_fY, stResultPoint[P_M_TR].m_fX, stResultPoint[P_M_TR].m_fY };
		if (bFindLineResult[L_TC_TL])
			S1Distance(&calibratedImg, metalTopLine, stResultLine[L_TC_TL], stDistance[D_D].m_dValue * m_stInfoSize.m_stSizeGain.m_stGainName.m_dd,
				stDistance[D_S1].m_dValue, stDistanceLine[D_S1]); // S1
		if (bFindLineResult[L_TC_T])
			S2Distance( &calibratedImg, metalTopLine, stResultLine[L_TC_T], stDistance[D_D].m_dValue * m_stInfoSize.m_stSizeGain.m_stGainName.m_dd,
				stDistance[D_S2].m_dValue, stDistanceLine[D_S2]); // S2
		if (bFindLineResult[L_TC_TR])
			S3Distance(&calibratedImg, metalTopLine, stResultLine[L_TC_TR], stDistance[D_D].m_dValue * m_stInfoSize.m_stSizeGain.m_stGainName.m_dd,
				stDistance[D_S3].m_dValue, stDistanceLine[D_S3]); // S3

		if (bFindLineResult[L_TL_T] && bFindLineResult[L_TL_L] && bFindLineResult[L_TC_TL] && bFindLineResult[L_M_L])
			PointtoLineDistance(&calibratedImg, metalTopLine, stResultPoint[P_TL_TC], stDistance[D_S4].m_dValue, stDistanceLine[D_S4]); // S4
		if (bFindLineResult[L_TC_TR] && bFindLineResult[L_M_R] && bFindLineResult[L_TR_T] && bFindLineResult[L_TR_R])
			PointtoLineDistance(&calibratedImg, metalTopLine, stResultPoint[P_TR_TC], stDistance[D_S5].m_dValue, stDistanceLine[D_S5]); // S5
	}
	
	if (bFindLineResult[L_M_T] && bFindLineResult[L_M_R] && bFindLineResult[L_M_B] && bFindLineResult[L_M_L])
	{
		PointtoPointDistance(&calibratedImg, stResultPoint[P_M_BR], stResultPoint[P_M_TL], stDistance[D_X1].m_dValue, stDistanceLine[D_X1]); // X1
		PointtoPointDistance(&calibratedImg, stResultPoint[P_M_TR], stResultPoint[P_M_BL], stDistance[D_X2].m_dValue, stDistanceLine[D_X2]); // X2
	}
#else
	if (bFindLineResult[L_M_R] && bFindLineResult[L_M_L])
		LinetoLineDistance(&grayImg, stResultLine[L_M_R], stResultLine[L_M_L], stDistance[D_D].m_dValue, stDistanceLine[D_D]); // d

	if (bFindLineResult[L_M_T] && bFindLineResult[L_M_B])
		LinetoLineDistance(&grayImg, stResultLine[L_M_T], stResultLine[L_M_B], stDistance[D_L].m_dValue, stDistanceLine[D_L]); // L
	if (bFindLineResult[L_TL_L] && bFindLineResult[L_TR_R])
		LinetoLineDistance(&grayImg, stResultLine[L_TL_L], stResultLine[L_TR_R], stDistance[D_W].m_dValue, stDistanceLine[D_W]); // W

	if (bFindLineResult[L_TL_T] && bFindLineResult[L_TL_L] && bFindLineResult[L_TL_B])
		PointtoPointDistance(&grayImg, stResultPoint[P_TL_B], stResultPoint[P_TL_T], stDistance[D_I1].m_dValue, stDistanceLine[D_I1]); // I1
	if (bFindLineResult[L_TC_T] && bFindLineResult[L_TC_B])
		LinetoLineDistance(&grayImg, stResultLine[L_TC_T], stResultLine[L_TC_B], stDistance[D_I2].m_dValue, stDistanceLine[D_I2]); // I2
	if (bFindLineResult[L_TR_T] && bFindLineResult[L_TR_R] && bFindLineResult[L_TR_B])
		PointtoPointDistance(&grayImg, stResultPoint[P_TR_T], stResultPoint[P_TR_B], stDistance[D_I3].m_dValue, stDistanceLine[D_I3]); // I3

	if (bFindLineResult[L_TL_L] && bFindLineResult[L_M_L])
		LinetoLineDistance(&grayImg, stResultLine[L_TL_L], stResultLine[L_M_L], stDistance[D_M1].m_dValue, stDistanceLine[D_M1]); // M1
	if (bFindLineResult[L_TR_R] && bFindLineResult[L_M_R])
		LinetoLineDistance(&grayImg, stResultLine[L_TR_R], stResultLine[L_M_R], stDistance[D_M2].m_dValue, stDistanceLine[D_M2]); // M2

	if (bFindLineResult[L_M_T] && bFindLineResult[L_M_L] && bFindLineResult[L_M_R])
	{
		stLine metalTopLine = { stResultPoint[P_M_TL].m_fX, stResultPoint[P_M_TL].m_fY, stResultPoint[P_M_TR].m_fX, stResultPoint[P_M_TR].m_fY };
		if (bFindLineResult[L_TC_TL])
			S1Distance(&grayImg, metalTopLine, stResultLine[L_TC_TL], stDistance[D_D].m_dValue * m_stInfoSize.m_stSizeGain.m_stGainName.m_dd,
			stDistance[D_S1].m_dValue, stDistanceLine[D_S1]); // S1
		if (bFindLineResult[L_TC_T])
			S2Distance(&grayImg, metalTopLine, stResultLine[L_TC_T], stDistance[D_D].m_dValue * m_stInfoSize.m_stSizeGain.m_stGainName.m_dd,
			stDistance[D_S2].m_dValue, stDistanceLine[D_S2]); // S2
		if (bFindLineResult[L_TC_TR])
			S3Distance(&grayImg, metalTopLine, stResultLine[L_TC_TR], stDistance[D_D].m_dValue * m_stInfoSize.m_stSizeGain.m_stGainName.m_dd,
			stDistance[D_S3].m_dValue, stDistanceLine[D_S3]); // S3

		if (bFindLineResult[L_TL_T] && bFindLineResult[L_TL_L] && bFindLineResult[L_TC_TL] && bFindLineResult[L_M_L])
			PointtoLineDistance(&grayImg, metalTopLine, stResultPoint[P_TL_TC], stDistance[D_S4].m_dValue, stDistanceLine[D_S4]); // S4
		if (bFindLineResult[L_TC_TR] && bFindLineResult[L_M_R] && bFindLineResult[L_TR_T] && bFindLineResult[L_TR_R])
			PointtoLineDistance(&grayImg, metalTopLine, stResultPoint[P_TR_TC], stDistance[D_S5].m_dValue, stDistanceLine[D_S5]); // S5
	}

	if (bFindLineResult[L_M_T] && bFindLineResult[L_M_R] && bFindLineResult[L_M_B] && bFindLineResult[L_M_L])
	{
		PointtoPointDistance(&grayImg, stResultPoint[P_M_BR], stResultPoint[P_M_TL], stDistance[D_X1].m_dValue, stDistanceLine[D_X1]); // X1
		PointtoPointDistance( &grayImg, stResultPoint[P_M_TR], stResultPoint[P_M_BL], stDistance[D_X2].m_dValue, stDistanceLine[D_X2]); // X2
	}
#endif

	for (int i = 0; i < sizeof(INFO_SIZE_GAIN) / sizeof(double); i++)
	{
		if (m_stInfoSize.m_stSizeGain.m_dGain[i] > 0)
			stDistance[i].m_dValue *= m_stInfoSize.m_stSizeGain.m_dGain[i];
	}

	if (stDistance[D_X1].m_dValue != .0 && stDistance[D_X2].m_dValue != .0)
		stDistance[D_X1X2].m_dValue = stDistance[D_X1].m_dValue - stDistance[D_X2].m_dValue; // X1 - X2
	if (stDistance[D_S1].m_dValue != .0 && stDistance[D_S3].m_dValue != .0)
		stDistance[D_S1S3].m_dValue = stDistance[D_S1].m_dValue - stDistance[D_S3].m_dValue; // S1 - S3
	if (stDistance[D_M1].m_dValue != .0 && stDistance[D_M2].m_dValue != .0)
		stDistance[D_M1M2].m_dValue = stDistance[D_M1].m_dValue - stDistance[D_M2].m_dValue; // M1 - M2

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

	// Calibrated Image
#ifdef USE_BASLER_CAMERA
	m_OutputImage = Mat(Size(calibratedImg.m_iWidth, calibratedImg.m_iHeight), CV_8UC3, calibratedImg.m_pSrcImage, calibratedImg.m_iWidthStep).clone();
#else
	m_OutputImage = Mat(Size(calibratedImg.m_iWidth, calibratedImg.m_iHeight), CV_8UC1, calibratedImg.m_pSrcImage, calibratedImg.m_iWidthStep).clone();
#endif

	stAPPIMAGEDATA outputImg;
	memset(&outputImg, 0, sizeof(stAPPIMAGEDATA));
	outputImg.m_pSrcImage = m_OutputImage.data;
	outputImg.m_iChannel = m_OutputImage.channels();
	outputImg.m_iDepth = DEPTH_8U;
	outputImg.m_iWidth = m_OutputImage.size().width;
	outputImg.m_iHeight = m_OutputImage.size().height;
	outputImg.m_iWidthStep = m_OutputImage.step1();
	outputImg.m_iImageSize = m_OutputImage.total() * m_OutputImage.channels();
	memcpy(&sample.m_SizeSecondResult.m_stCalibratedImage, &outputImg, sizeof(stAPPIMAGEDATA));

	// Relative ROI Point
	for (int i = TYPE_FINDLINE_METAL_TOP; i <= TYPE_FINDLINE_METAL_LEFT; i++)
	{
		vector<CLP_ROI> roi;
		pFindLineApp[i]->GetROI(&roi);

		if (roi.size() > 0 && roi.at(0).m_pstPosArray.size() >= 4)
		{
			for (int j = 0; j < 4; j++)
			{
				sample.m_SizeSecondResult.m_stROIPoint[i].m_pt[j] = m_stCurruntROIPoint[i].m_pt[j] = roi.at(0).m_pstPosArray.at(j);
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
				sample.m_SizeSecondResult.m_stROIPoint[i].m_pt[j] = m_stCurruntROIPoint[i].m_pt[j] = roi.at(0).m_pstPosArray.at(j);
			}
		}
		else
		{
			pFindLineApp[i]->GetROI(&roi);

			if (roi.size() > 0 && roi.at(0).m_pstPosArray.size() >= 4)
			{
				for (int j = 0; j < 4; j++)
				{
					sample.m_SizeSecondResult.m_stROIPoint[i].m_pt[j] = m_stCurruntROIPoint[i].m_pt[j] = roi.at(0).m_pstPosArray.at(j);
				}
			}
		}
	}

	auto endtime = chrono::high_resolution_clock::now();
	chrono::duration<double, milli> elapsedtime = endtime - starttime;

	Log("Process End (%fms)", elapsedtime.count());

	return TRUE;
}

BOOL CStepSizeSecond::Process(CSampleSide& sample, cv::Mat captureImg)
{
	auto starttime = chrono::high_resolution_clock::now();

	if (!DongleCheck())
	{
		Log("Fail to check dongle");

		if (!DongleLogin())
		{
#ifdef USE_BASLER_CAMERA
			m_OutputImage = Mat(Size(sample.m_pRefImage->m_stFrame.m_dwWidth, sample.m_pRefImage->m_stFrame.m_dwHeight), CV_8UC3, sample.m_pRefImage->m_pBuffer).clone();
#else
			m_OutputImage = Mat(Size(sample.m_pRefImage->m_stFrame.m_dwWidth, sample.m_pRefImage->m_stFrame.m_dwHeight), CV_8UC1, sample.m_pRefImage->m_pBuffer).clone();
#endif

			stAPPIMAGEDATA img;
			memset(&img, 0, sizeof(stAPPIMAGEDATA));
			img.m_pSrcImage = m_OutputImage.data;
			img.m_iChannel = m_OutputImage.channels();
			img.m_iDepth = DEPTH_8U;
			img.m_iWidth = m_OutputImage.size().width;
			img.m_iHeight = m_OutputImage.size().height;
			img.m_iWidthStep = m_OutputImage.step1();
			img.m_iImageSize = m_OutputImage.total() * m_OutputImage.channels();

			memcpy(&sample.m_SizeSecondResult.m_stCalibratedImage, &img, sizeof(stAPPIMAGEDATA)); // TODO: 버퍼 안정성 검토

			return FALSE;
		}
	}

	Log("Process Start");

	CLPApp **pFindLineApp = NULL;

	pFindLineApp = m_pFindLineApp;

#ifdef USE_BASLER_CAMERA
	// 예외처리
	if (!m_bInit ||
		pFindLineApp == NULL ||
		//sample.m_pRefImage == NULL ||
		//sample.m_pRefImage->m_pBuffer == NULL ||
		//sample.m_pRefImage->m_stFrame.m_eColor != TYPE_CAMCOLOR_COLOR ||
		//sample.m_pRefImage->m_stFrame.m_eDataBit != TYPE_DATABIT_08)
		captureImg.data == NULL ||
		captureImg.channels() != 3)
	{
		Log("Initialize/Image Error");
#if 1 // test code
		if (!m_bInit)
			Log("StepSize Initialize Error");
		else if (pFindLineApp == NULL)
			Log("StepSize pFindLineApp Error");
		//else if (sample.m_pRefImage == NULL)
		//	Log("StepSize Image == NULL Error");
		//else if (sample.m_pRefImage->m_pBuffer == NULL)
		else if (captureImg.data == NULL)
			Log("StepSize captureImg.data == NULL Error");
		//else if (sample.m_pRefImage->m_stFrame.m_eColor != TYPE_CAMCOLOR_COLOR)
		else if (captureImg.channels() != 3)
			Log("StepSize captureImg.channels != 3 Error");
		else if (captureImg.depth() != CV_8U)
			Log("StepSize captureImg.depth != CV_8U Error");
		else
			Log("StepSize Undefined Error");
	
#endif
		return FALSE;
	}
#else
	// 예외처리
	if (!m_bInit ||
		pFindLineApp == NULL ||
		sample.m_pRefImage->m_pBuffer == NULL ||
		sample.m_pRefImage->m_stFrame.m_eColor != TYPE_CAMCOLOR_MONO ||
		sample.m_pRefImage->m_stFrame.m_eDataBit != TYPE_DATABIT_08)
	{
		Log("Initialize/Image Error");
#if 1 // test code
		if (!m_bInit)
			Log("StepSize Initialize Error");
		else if (pFindLineApp == NULL)
			Log("StepSize pFindLineApp Error");
		else if (sample.m_pRefImage == NULL)
			Log("StepSize Image == NULL Error");
		else if (sample.m_pRefImage->m_stFrame.m_eColor != TYPE_CAMCOLOR_MONO)
			Log("StepSize Color != TYPE_CAMCOLOR_COLOR Error");
		else if (sample.m_pRefImage->m_stFrame.m_eDataBit != TYPE_DATABIT_08)
			Log("StepSize DataBit != TYPE_DATABIT_08 Error");
		else
			Log("StepSize Undefined Error");
#endif
		return FALSE;
	}
#endif

	stLine *stResultLine = sample.m_SizeSecondResult.m_stResultLine;
	stPOINT *stResultPoint = sample.m_SizeSecondResult.m_stResultPoint;

	stAPPIMAGEDATA img, calibratedImg;
	memset(&img, 0, sizeof(stAPPIMAGEDATA));
	memset(&calibratedImg, 0, sizeof(stAPPIMAGEDATA));
	//img.m_pSrcImage = sample.m_pRefImage->m_pBuffer;
	img.m_pSrcImage = captureImg.data;;
#ifdef USE_BASLER_CAMERA
	/*img.m_iChannel = 3;
	img.m_iDepth = DEPTH_8U;
	img.m_iWidth = sample.m_pRefImage->m_stFrame.m_dwWidth;
	img.m_iHeight = sample.m_pRefImage->m_stFrame.m_dwHeight;
	img.m_iWidthStep = sample.m_pRefImage->m_stFrame.m_dwPitch;
	img.m_iImageSize = sample.m_pRefImage->m_nBufLen;*/
	img.m_iChannel = captureImg.channels();
	//img.m_iDepth = (captureImg.depth() == CV_8U) ? DEPTH_8U : DEPTH_8U;
	img.m_iDepth = DEPTH_8U;
	img.m_iWidth = captureImg.cols;
	img.m_iHeight = captureImg.rows;
	img.m_iWidthStep = captureImg.step1();
	img.m_iImageSize = captureImg.total() * captureImg.channels();

#else
	img.m_iChannel = 1;
	img.m_iDepth = DEPTH_8U;
	img.m_iWidth = sample.m_pRefImage->m_stFrame.m_dwWidth;
	img.m_iHeight = sample.m_pRefImage->m_stFrame.m_dwHeight;
	img.m_iWidthStep = img.m_iWidth * img.m_iChannel;
	img.m_iImageSize = sample.m_pRefImage->m_nBufLen;
#endif

	// Calibration
	m_pCalibrationApp->SetInput(&img);
	m_pCalibrationApp->Process();
	m_pCalibrationApp->GetOutput(CALIBRATION_RESULT_IMAGE, calibratedImg);
	// Calibration 실패 시 img 사용
	if (NULL == calibratedImg.m_pSrcImage)
		memcpy(&calibratedImg, &img, sizeof(stAPPIMAGEDATA));

#ifdef USE_BASLER_CAMERA
	Mat calibratedMat(calibratedImg.m_iHeight, calibratedImg.m_iWidth, CV_8UC3, calibratedImg.m_pSrcImage, calibratedImg.m_iWidthStep);
	cvtColor(calibratedMat, m_GrayMat, COLOR_BGR2GRAY);
	if (m_GrayMat.empty())
	{
#ifdef USE_BASLER_CAMERA
		m_OutputImage = Mat(Size(sample.m_pRefImage->m_stFrame.m_dwWidth, sample.m_pRefImage->m_stFrame.m_dwHeight), CV_8UC3, sample.m_pRefImage->m_pBuffer).clone();
#else
		m_OutputImage = Mat(Size(sample.m_pRefImage->m_stFrame.m_dwWidth, sample.m_pRefImage->m_stFrame.m_dwHeight), CV_8UC1, sample.m_pRefImage->m_pBuffer).clone();
#endif

		stAPPIMAGEDATA img;
		memset(&img, 0, sizeof(stAPPIMAGEDATA));
		img.m_pSrcImage = m_OutputImage.data;
		img.m_iChannel = m_OutputImage.channels();
		img.m_iDepth = DEPTH_8U;
		img.m_iWidth = m_OutputImage.size().width;
		img.m_iHeight = m_OutputImage.size().height;
		img.m_iWidthStep = m_OutputImage.step1();
		img.m_iImageSize = m_OutputImage.total() * m_OutputImage.channels();

		memcpy(&sample.m_SizeSecondResult.m_stCalibratedImage, &img, sizeof(stAPPIMAGEDATA));

		return FALSE;
	}

	stAPPIMAGEDATA grayImg;
	memset(&grayImg, 0, sizeof(stAPPIMAGEDATA));
	grayImg.m_pSrcImage = m_GrayMat.data;
	grayImg.m_iChannel = 1;
	grayImg.m_iDepth = DEPTH_8U;
	grayImg.m_iWidth = m_GrayMat.size().width;
	grayImg.m_iHeight = m_GrayMat.size().height;
	grayImg.m_iWidthStep = m_GrayMat.step1();
	grayImg.m_iImageSize = grayImg.m_iWidthStep * grayImg.m_iHeight;
#endif
	// FindLine: Metal
	double dAngle;
	bool bFindLineResult[TYPE_FINDLINE_MAX] = { false, };
	for (int i = TYPE_FINDLINE_METAL_TOP; i <= TYPE_FINDLINE_METAL_LEFT; i++)
	{
		if (pFindLineApp[i])
		{
#ifndef USE_BASLER_CAMERA
			pFindLineApp[i]->SetInput(&calibratedImg);
#else
			pFindLineApp[i]->SetInput(&grayImg);
#endif
			pFindLineApp[i]->Process();
			bFindLineResult[i] = (ERR_SUCCESS == pFindLineApp[i]->GetOutput(FINDLINE_LINE, stResultLine[i])) ? true : false;
			if (!bFindLineResult[i])
			{
				stResultLine[i] = { 0, 0, 0, 0 };
				Log("Cannot Find Line #%d", i);
			}
		}
	}
	if (pFindLineApp[0])
	{
		pFindLineApp[0]->GetOutput(FINDLINE_ANGLE, dAngle); // 첫번째 FindLine의 Angle 사용
		dAngle -= this->m_stInfoSize.m_pstFindLineROI[0].m_dAngle;
	}

	// Geometry (Line Intersection): Metal
	for (int i = TYPE_FINDLINE_METAL_TOP; i <= TYPE_FINDLINE_METAL_LEFT; i++)
	{
		if (bFindLineResult[i] && bFindLineResult[(i + 1) % FINDLINE_METAL_COUNT])
#ifndef USE_BASLER_CAMERA
			LineIntersection(&calibratedImg, stResultLine[i], stResultLine[(i + 1) % FINDLINE_METAL_COUNT], stResultPoint[i]);
#else
			LineIntersection(&grayImg, stResultLine[i], stResultLine[(i + 1) % FINDLINE_METAL_COUNT], stResultPoint[i]);
#endif
	}

	if (bFindLineResult[L_M_T] && bFindLineResult[L_M_L])
	{
		// FindLine: Tape
		for (int i = TYPE_FINDLINE_TAPE_LEFTWING_TOP; i < TYPE_FINDLINE_MAX; i++)
		{
			if (pFindLineApp[i])
			{
#ifndef USE_BASLER_CAMERA
				pFindLineApp[i]->SetInput(&calibratedImg);
#else
				pFindLineApp[i]->SetInput(&grayImg);
#endif
				pFindLineApp[i]->SetCurrentLocation(stResultPoint[P_M_TL], dAngle); // Metal 좌상단 점과 각도 기준. 이 부분 변경 시 SetInfoFindLineROI도 변경
				pFindLineApp[i]->Process();
				bFindLineResult[i] = (ERR_SUCCESS == pFindLineApp[i]->GetOutput(FINDLINE_LINE, stResultLine[i])) ? true : false;
				if (!bFindLineResult[i])
				{
					stResultLine[i] = { 0, 0, 0, 0 };
					Log("Cannot Find Line #%d", i);
				}
			}
		}

		for (int i = TYPE_FINDLINE_METAL_TOP; i < TYPE_FINDLINE_MAX; i++)
			sample.m_SizeSecondResult.m_bFindLineResult[i] = bFindLineResult[i];

		// Geometry (Line Intersection): Tape
#ifndef USE_BASLER_CAMERA
		LineIntersection(&calibratedImg, stResultLine[L_TL_L], stResultLine[L_TL_B], stResultPoint[P_TL_B]); // 좌하
		LineIntersection(&calibratedImg, stResultLine[L_TL_T], stResultLine[L_TL_L], stResultPoint[P_TL_T]); // 좌상
		LineIntersection(&calibratedImg, stResultLine[L_TC_TL], stResultLine[L_M_L], stResultPoint[P_TC_TL]); // 중좌상
		LineIntersection(&calibratedImg, stResultLine[L_TC_TR], stResultLine[L_M_R], stResultPoint[P_TC_TR]); // 중우상
		LineIntersection(&calibratedImg, stResultLine[L_TR_T], stResultLine[L_TR_R], stResultPoint[P_TR_T]); // 우상
		LineIntersection(&calibratedImg, stResultLine[L_TR_R], stResultLine[L_TR_B], stResultPoint[P_TR_B]); // 우하

		if (bFindLineResult[L_TL_T] && bFindLineResult[L_TL_L] && bFindLineResult[L_TC_TL] && bFindLineResult[L_M_L])
			MidPoint(&calibratedImg, stResultPoint[P_TL_T], stResultPoint[P_TC_TL], stResultPoint[P_TL_TC]); // 테이프 좌상 중심
		if (bFindLineResult[L_TC_TR] && bFindLineResult[L_M_R] && bFindLineResult[L_TR_T] && bFindLineResult[L_TR_R])
			MidPoint(&calibratedImg, stResultPoint[P_TC_TR], stResultPoint[P_TR_T], stResultPoint[P_TR_TC]); // 테이프 우상 중심
#else
		LineIntersection(&grayImg, stResultLine[L_TL_L], stResultLine[L_TL_B], stResultPoint[P_TL_B]); // 좌하
		LineIntersection(&grayImg, stResultLine[L_TL_T], stResultLine[L_TL_L], stResultPoint[P_TL_T]); // 좌상
		LineIntersection(&grayImg, stResultLine[L_TC_TL], stResultLine[L_M_L], stResultPoint[P_TC_TL]); // 중좌상
		LineIntersection(&grayImg, stResultLine[L_TC_TR], stResultLine[L_M_R], stResultPoint[P_TC_TR]); // 중우상
		LineIntersection(&grayImg, stResultLine[L_TR_T], stResultLine[L_TR_R], stResultPoint[P_TR_T]); // 우상
		LineIntersection(&grayImg, stResultLine[L_TR_R], stResultLine[L_TR_B], stResultPoint[P_TR_B]); // 우하

		if (bFindLineResult[L_TL_T] && bFindLineResult[L_TL_L] && bFindLineResult[L_TC_TL] && bFindLineResult[L_M_L])
			MidPoint(&grayImg, stResultPoint[P_TL_T], stResultPoint[P_TC_TL], stResultPoint[P_TL_TC]); // 테이프 좌상 중심
		if (bFindLineResult[L_TC_TR] && bFindLineResult[L_M_R] && bFindLineResult[L_TR_T] && bFindLineResult[L_TR_R])
			MidPoint(&grayImg, stResultPoint[P_TC_TR], stResultPoint[P_TR_T], stResultPoint[P_TR_TC]); // 테이프 우상 중심
#endif
	}
	else
	{
		// Metal 기준점 찾지 못할 경우 Tape 찾지 않음
		Log("Cannot Find Metal Criteria");
	}

	// Geometry (Distance)
	OUTPUT_DISTANCE *stDistance = sample.m_SizeSecondResult.m_stDistance;
	stLine *stDistanceLine = sample.m_SizeSecondResult.m_stDistanceLine;

#ifndef USE_BASLER_CAMERA
	if (bFindLineResult[L_M_R] && bFindLineResult[L_M_L])
		LinetoLineDistance(&calibratedImg, stResultLine[L_M_R], stResultLine[L_M_L], stDistance[D_D].m_dValue, stDistanceLine[D_D]); // d
	if (bFindLineResult[L_M_T] && bFindLineResult[L_M_B])
		LinetoLineDistance(&calibratedImg, stResultLine[L_M_T], stResultLine[L_M_B], stDistance[D_L].m_dValue, stDistanceLine[D_L]); // L
	if (bFindLineResult[L_TL_L] && bFindLineResult[L_TR_R])
		LinetoLineDistance(&calibratedImg, stResultLine[L_TL_L], stResultLine[L_TR_R], stDistance[D_W].m_dValue, stDistanceLine[D_W]); // W

	if (bFindLineResult[L_TL_T] && bFindLineResult[L_TL_L] && bFindLineResult[L_TL_B])
		PointtoPointDistance(&calibratedImg, stResultPoint[P_TL_B], stResultPoint[P_TL_T], stDistance[D_I1].m_dValue, stDistanceLine[D_I1]); // I1
	if (bFindLineResult[L_TC_T] && bFindLineResult[L_TC_B])
		LinetoLineDistance(&calibratedImg, stResultLine[L_TC_T], stResultLine[L_TC_B], stDistance[D_I2].m_dValue, stDistanceLine[D_I2]); // I2
	if (bFindLineResult[L_TR_T] && bFindLineResult[L_TR_R] && bFindLineResult[L_TR_B])
		PointtoPointDistance(&calibratedImg, stResultPoint[P_TR_T], stResultPoint[P_TR_B], stDistance[D_I3].m_dValue, stDistanceLine[D_I3]); // I3

	if (bFindLineResult[L_TL_L] && bFindLineResult[L_M_L])
		LinetoLineDistance(&calibratedImg, stResultLine[L_TL_L], stResultLine[L_M_L], stDistance[D_M1].m_dValue, stDistanceLine[D_M1]); // M1
	if (bFindLineResult[L_TR_R] && bFindLineResult[L_M_R])
		LinetoLineDistance(&calibratedImg, stResultLine[L_TR_R], stResultLine[L_M_R], stDistance[D_M2].m_dValue, stDistanceLine[D_M2]); // M2

	if (bFindLineResult[L_M_T] && bFindLineResult[L_M_L] && bFindLineResult[L_M_R])
	{
		stLine metalTopLine = { stResultPoint[P_M_TL].m_fX, stResultPoint[P_M_TL].m_fY, stResultPoint[P_M_TR].m_fX, stResultPoint[P_M_TR].m_fY };
		if (bFindLineResult[L_TC_TL])
			S1Distance(&calibratedImg, metalTopLine, stResultLine[L_TC_TL], stDistance[D_D].m_dValue * m_stInfoSize.m_stSizeGain.m_stGainName.m_dd,
			stDistance[D_S1].m_dValue, stDistanceLine[D_S1]); // S1
		if (bFindLineResult[L_TC_T])
			S2Distance(&calibratedImg, metalTopLine, stResultLine[L_TC_T], stDistance[D_D].m_dValue * m_stInfoSize.m_stSizeGain.m_stGainName.m_dd,
			stDistance[D_S2].m_dValue, stDistanceLine[D_S2]); // S2
		if (bFindLineResult[L_TC_TR])
			S3Distance(&calibratedImg, metalTopLine, stResultLine[L_TC_TR], stDistance[D_D].m_dValue * m_stInfoSize.m_stSizeGain.m_stGainName.m_dd,
			stDistance[D_S3].m_dValue, stDistanceLine[D_S3]); // S3

		if (bFindLineResult[L_TL_T] && bFindLineResult[L_TL_L] && bFindLineResult[L_TC_TL] && bFindLineResult[L_M_L])
			PointtoLineDistance(&calibratedImg, metalTopLine, stResultPoint[P_TL_TC], stDistance[D_S4].m_dValue, stDistanceLine[D_S4]); // S4
		if (bFindLineResult[L_TC_TR] && bFindLineResult[L_M_R] && bFindLineResult[L_TR_T] && bFindLineResult[L_TR_R])
			PointtoLineDistance(&calibratedImg, metalTopLine, stResultPoint[P_TR_TC], stDistance[D_S5].m_dValue, stDistanceLine[D_S5]); // S5
	}

	if (bFindLineResult[L_M_T] && bFindLineResult[L_M_R] && bFindLineResult[L_M_B] && bFindLineResult[L_M_L])
	{
		PointtoPointDistance(&calibratedImg, stResultPoint[P_M_BR], stResultPoint[P_M_TL], stDistance[D_X1].m_dValue, stDistanceLine[D_X1]); // X1
		PointtoPointDistance(&calibratedImg, stResultPoint[P_M_TR], stResultPoint[P_M_BL], stDistance[D_X2].m_dValue, stDistanceLine[D_X2]); // X2
	}
#else
	if (bFindLineResult[L_M_R] && bFindLineResult[L_M_L])
		LinetoLineDistance(&grayImg, stResultLine[L_M_R], stResultLine[L_M_L], stDistance[D_D].m_dValue, stDistanceLine[D_D]); // d
	if (bFindLineResult[L_M_T] && bFindLineResult[L_M_B])
		LinetoLineDistance(&grayImg, stResultLine[L_M_T], stResultLine[L_M_B], stDistance[D_L].m_dValue, stDistanceLine[D_L]); // L
	if (bFindLineResult[L_TL_L] && bFindLineResult[L_TR_R])
		LinetoLineDistance(&grayImg, stResultLine[L_TL_L], stResultLine[L_TR_R], stDistance[D_W].m_dValue, stDistanceLine[D_W]); // W

	if (bFindLineResult[L_TL_T] && bFindLineResult[L_TL_L] && bFindLineResult[L_TL_B])
		PointtoPointDistance(&grayImg, stResultPoint[P_TL_B], stResultPoint[P_TL_T], stDistance[D_I1].m_dValue, stDistanceLine[D_I1]); // I1
	if (bFindLineResult[L_TC_T] && bFindLineResult[L_TC_B])
		LinetoLineDistance(&grayImg, stResultLine[L_TC_T], stResultLine[L_TC_B], stDistance[D_I2].m_dValue, stDistanceLine[D_I2]); // I2
	if (bFindLineResult[L_TR_T] && bFindLineResult[L_TR_R] && bFindLineResult[L_TR_B])
		PointtoPointDistance( &grayImg, stResultPoint[P_TR_T], stResultPoint[P_TR_B], stDistance[D_I3].m_dValue, stDistanceLine[D_I3]); // I3

	if (bFindLineResult[L_TL_L] && bFindLineResult[L_M_L])
		LinetoLineDistance(&grayImg, stResultLine[L_TL_L], stResultLine[L_M_L], stDistance[D_M1].m_dValue, stDistanceLine[D_M1]); // M1
	if (bFindLineResult[L_TR_R] && bFindLineResult[L_M_R])
		LinetoLineDistance(&grayImg, stResultLine[L_TR_R], stResultLine[L_M_R], stDistance[D_M2].m_dValue, stDistanceLine[D_M2]); // M2

	if (bFindLineResult[L_M_T] && bFindLineResult[L_M_L] && bFindLineResult[L_M_R])
	{
		stLine metalTopLine = { stResultPoint[P_M_TL].m_fX, stResultPoint[P_M_TL].m_fY, stResultPoint[P_M_TR].m_fX, stResultPoint[P_M_TR].m_fY };
		if (bFindLineResult[L_TC_TL])
			S1Distance(&grayImg, metalTopLine, stResultLine[L_TC_TL], stDistance[D_D].m_dValue * m_stInfoSize.m_stSizeGain.m_stGainName.m_dd,
			stDistance[D_S1].m_dValue, stDistanceLine[D_S1]); // S1
		if (bFindLineResult[L_TC_T])
			S2Distance(&grayImg, metalTopLine, stResultLine[L_TC_T], stDistance[D_D].m_dValue * m_stInfoSize.m_stSizeGain.m_stGainName.m_dd,
			stDistance[D_S2].m_dValue, stDistanceLine[D_S2]); // S2
		if (bFindLineResult[L_TC_TR])
			S3Distance(&grayImg, metalTopLine, stResultLine[L_TC_TR], stDistance[D_D].m_dValue * m_stInfoSize.m_stSizeGain.m_stGainName.m_dd,
			stDistance[D_S3].m_dValue, stDistanceLine[D_S3]); // S3

		if (bFindLineResult[L_TL_T] && bFindLineResult[L_TL_L] && bFindLineResult[L_TC_TL] && bFindLineResult[L_M_L])
			PointtoLineDistance(&grayImg, metalTopLine, stResultPoint[P_TL_TC], stDistance[D_S4].m_dValue, stDistanceLine[D_S4]); // S4
		if (bFindLineResult[L_TC_TR] && bFindLineResult[L_M_R] && bFindLineResult[L_TR_T] && bFindLineResult[L_TR_R])
			PointtoLineDistance(&grayImg, metalTopLine, stResultPoint[P_TR_TC], stDistance[D_S5].m_dValue, stDistanceLine[D_S5]); // S5
	}

	if (bFindLineResult[L_M_T] && bFindLineResult[L_M_R] && bFindLineResult[L_M_B] && bFindLineResult[L_M_L])
	{
		PointtoPointDistance(&grayImg, stResultPoint[P_M_BR], stResultPoint[P_M_TL], stDistance[D_X1].m_dValue, stDistanceLine[D_X1]); // X1
		PointtoPointDistance(&grayImg, stResultPoint[P_M_TR], stResultPoint[P_M_BL], stDistance[D_X2].m_dValue, stDistanceLine[D_X2]); // X2
	}
#endif

	// TODO: 동작 확인 후 삭제
	/*for (int i = 0; i < sizeof(INFO_SIZE_GAIN) / sizeof(double); i++)
	{
		if (m_stInfoSize.m_stSizeGain.m_dGain[i] > 0)
			stDistance[i].m_dValue *= m_stInfoSize.m_stSizeGain.m_dGain[i];
	}

	if (stDistance[D_X1].m_dValue != .0 && stDistance[D_X2].m_dValue != .0)
		stDistance[D_X1X2].m_dValue = stDistance[D_X1].m_dValue - stDistance[D_X2].m_dValue; // X1 - X2
	if (stDistance[D_S1].m_dValue != .0 && stDistance[D_S3].m_dValue != .0)
		stDistance[D_S1S3].m_dValue = stDistance[D_S1].m_dValue - stDistance[D_S3].m_dValue; // S1 - S3
	if (stDistance[D_M1].m_dValue != .0 && stDistance[D_M2].m_dValue != .0)
		stDistance[D_M1M2].m_dValue = stDistance[D_M1].m_dValue - stDistance[D_M2].m_dValue; // M1 - M2

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
	}*/

	// Calibrated Image
#ifdef USE_BASLER_CAMERA
	m_OutputImage = Mat(Size(calibratedImg.m_iWidth, calibratedImg.m_iHeight), CV_8UC3, calibratedImg.m_pSrcImage, calibratedImg.m_iWidthStep).clone();
#else
	m_OutputImage = Mat(Size(calibratedImg.m_iWidth, calibratedImg.m_iHeight), CV_8UC1, calibratedImg.m_pSrcImage, calibratedImg.m_iWidthStep).clone();
#endif

	stAPPIMAGEDATA outputImg;
	memset(&outputImg, 0, sizeof(stAPPIMAGEDATA));
	outputImg.m_pSrcImage = m_OutputImage.data;
	outputImg.m_iChannel = m_OutputImage.channels();
	outputImg.m_iDepth = DEPTH_8U;
	outputImg.m_iWidth = m_OutputImage.size().width;
	outputImg.m_iHeight = m_OutputImage.size().height;
	outputImg.m_iWidthStep = m_OutputImage.step1();
	outputImg.m_iImageSize = m_OutputImage.total() * m_OutputImage.channels();
	memcpy(&sample.m_SizeSecondResult.m_stCalibratedImage, &outputImg, sizeof(stAPPIMAGEDATA));

	// Relative ROI Point
	for (int i = TYPE_FINDLINE_METAL_TOP; i <= TYPE_FINDLINE_METAL_LEFT; i++)
	{
		vector<CLP_ROI> roi;
		pFindLineApp[i]->GetROI(&roi);

		if (roi.size() > 0 && roi.at(0).m_pstPosArray.size() >= 4)
		{
			for (int j = 0; j < 4; j++)
			{
				sample.m_SizeSecondResult.m_stROIPoint[i].m_pt[j] = m_stCurruntROIPoint[i].m_pt[j] = roi.at(0).m_pstPosArray.at(j);
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
				sample.m_SizeSecondResult.m_stROIPoint[i].m_pt[j] = m_stCurruntROIPoint[i].m_pt[j] = roi.at(0).m_pstPosArray.at(j);
			}
		}
		else
		{
			pFindLineApp[i]->GetROI(&roi);

			if (roi.size() > 0 && roi.at(0).m_pstPosArray.size() >= 4)
			{
				for (int j = 0; j < 4; j++)
				{
					sample.m_SizeSecondResult.m_stROIPoint[i].m_pt[j] = m_stCurruntROIPoint[i].m_pt[j] = roi.at(0).m_pstPosArray.at(j);
				}
			}
		}
	}

	auto endtime = chrono::high_resolution_clock::now();
	chrono::duration<double, milli> elapsedtime = endtime - starttime;

	Log("Process End (%fms)", elapsedtime.count());

	return TRUE;
}
/**
* @brief 설정 값 Load 함수
* @param INFO_INSPECTION* pstInspection 설정 값 구조체
* @return 설정 성공 여부
* @remark 인자가 NULL 일 경우 설정 값 초기화
*/
BOOL CStepSizeSecond::Load(INFO_INSPECTION* pstInspection)
{
	BOOL bResult = FALSE;
	if (pstInspection)
	{
		// Load
		bResult = SetInformation(&pstInspection->m_stSizeSecond);
	}
	else
	{
		Log("Load Default Setting");

		INFO_INSPECTION_SIZE infoSize;
		memset(&infoSize, 0x00, sizeof(INFO_INSPECTION_SIZE));
		GetDefaultSizeSetting(&infoSize);

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
BOOL CStepSizeSecond::Get(INFO_INSPECTION* pstInspection)
{
	if (NULL == pstInspection)
		return FALSE;

	memcpy(&pstInspection->m_stSizeSecond, &m_stInfoSize, sizeof(INFO_INSPECTION_SIZE));
	return TRUE;
}

/**
* @brief 설정 값 Set 함수
* @param const INFO_INSPECTION* pstInspection 설정 값을 가져올 구조체
* @return 설정 성공 여부
* @remark 이 함수는 쓰이지 않을 수 있음
*/
BOOL CStepSizeSecond::Set(const INFO_INSPECTION* pstInspection)
{
	if (NULL == pstInspection)
		return FALSE;

	return SetInformation(&pstInspection->m_stSizeSecond);
}


/**
* @brief 설정 값 Get 함수
* @return 설정 값 구조체 포인터
*/
const INFO_INSPECTION_SIZE* CStepSizeSecond::GetInformation()
{
	return &m_stInfoSize;
}

/**
* @brief 설정 값 Set 함수
* @param const INFO_INSPECTION_SIZE* pInfoSize 설정 값을 가져올 구조체
* @return 설정 성공 여부
* @remark 설정 값을 가져오고 모든 FindLine 객체의 설정 값 변경
*/
BOOL CStepSizeSecond::SetInformation(const INFO_INSPECTION_SIZE* pInfoSize)
{
	if (NULL == pInfoSize || !m_bInit)
		return FALSE;

	Log("Set information");

	memcpy(&m_stInfoSize, pInfoSize, sizeof(INFO_INSPECTION_SIZE));

#ifdef FINDLINE_ROTATERECT
	for (int i = 0; i < TYPE_FINDLINE_MAX; i++)
	{
		m_stInfoSize.m_pstFindLineROI[i].m_eTrackerType = TYPE_TRACKER_RECT_ROTATE;
	}
#endif

	// Calibration 설정
	SetCalibration(&m_stInfoSize.m_stCalibration);

	// Gain 설정
	SetSizeGain(&m_stInfoSize.m_stSizeGain);

	// 각 FindLine의 ROI 변경
	for (int i = TYPE_FINDLINE_METAL_TOP; i <= TYPE_FINDLINE_METAL_LEFT; i++)
	{
		SetFindLineAppROI(m_pFindLineApp[i], &m_stInfoSize.m_pstFindLineROI[i]);
	}
	for (int i = TYPE_FINDLINE_TAPE_LEFTWING_TOP; i < TYPE_FINDLINE_MAX; i++)
	{
		SetFindLineAppROI(m_pFindLineApp[i], &m_stInfoSize.m_pstFindLineROI[i], true, m_stInfoSize.m_pstFindLineROI[i].m_ptCriteria, m_stInfoSize.m_pstFindLineROI[i].m_dAngleCriteria);
	}

	// 각 FindLine의 설정 값 변경
	for (int i = 0; i < TYPE_FINDLINE_MAX; i++)
	{
		SetFindLineAppParameter(m_pFindLineApp[i], m_stInfoSize.m_pstFindLineParameter[i]);
	}


	return TRUE;
}

/**
* @brief FindLine의 ROI Set 함수
* @param INFO_FINDLINE_PARAMETER* pInfoLine 설정 값을 가져올 구조체
* @param const INFO_IMAGE* pRefImage 이미지 포인터
* @param const int iIndex FindLine의 Index
* @return 설정 성공 여부
* @remark iIndex가 FINDLINE_METAL_COUNT(4)이상일 경우(Tape 변경일 경우), 상대 ROI 기준 점도 변경
*         ROI 변경 시 Parameter 변경 될 수 있으므로 SetInfoFindLineParameter를 호출함
*         pInfoLine의 m_ptCriteria와 m_dAngleCriteria는 무시
*/
BOOL CStepSizeSecond::SetInfoFindLineROI(const INFO_FINDLINE_ROI* pInfoLine, const INFO_IMAGE* pRefImage, const int iIndex)
{
	if (NULL == pInfoLine || NULL == pRefImage || iIndex >= TYPE_FINDLINE_MAX || !m_bInit)
		return FALSE;

	memcpy(&m_stInfoSize.m_pstFindLineROI[iIndex], pInfoLine, sizeof(INFO_FINDLINE_ROI));

	if (iIndex <= TYPE_FINDLINE_METAL_LEFT)
	{
		// Metal 부분 ROI 변경
		m_stInfoSize.m_pstFindLineROI[iIndex].m_ptCriteria = { 0., 0. };
		m_stInfoSize.m_pstFindLineROI[iIndex].m_dAngleCriteria = 0.;
		SetFindLineAppROI(m_pFindLineApp[iIndex], &m_stInfoSize.m_pstFindLineROI[iIndex]);
	}
	else
	{
		// Tape 부분 ROI 변경

#ifndef USE_BASLER_CAMERA
		// FindLine 0,1의 교차점, 각도 구하여 다음 FindLine의 기준점 설정
		stAPPIMAGEDATA img, calibratedImg;
		memset(&img, 0, sizeof(stAPPIMAGEDATA));
		memset(&calibratedImg, 0, sizeof(stAPPIMAGEDATA));
		img.m_pSrcImage = pRefImage->m_pBuffer;
		img.m_iChannel = 1;
		img.m_iDepth = DEPTH_8U;
		img.m_iWidth = pRefImage->m_stFrame.m_dwWidth;
		img.m_iHeight = pRefImage->m_stFrame.m_dwHeight;
		img.m_iWidthStep = img.m_iWidth * img.m_iChannel;
		img.m_iImageSize = pRefImage->m_nBufLen;

		// Calibration
		if (m_iCalInit == ERR_SUCCESS)
		{
			m_pCalibrationApp->SetInput(&img);
			m_pCalibrationApp->Process();
			m_pCalibrationApp->GetOutput(CALIBRATION_RESULT_IMAGE, calibratedImg);
			
			// Calibration 실패 시 img 사용
			if (NULL == calibratedImg.m_pSrcImage)
				memcpy(&calibratedImg, &img, sizeof(stAPPIMAGEDATA));
		}

		// Calibration 실패 시 img 사용
		if (NULL == calibratedImg.m_pSrcImage)
			memcpy(&calibratedImg, &img, sizeof(stAPPIMAGEDATA));
#else
		stAPPIMAGEDATA img, calibratedImg;
		memset(&img, 0, sizeof(stAPPIMAGEDATA));
		memset(&calibratedImg, 0, sizeof(stAPPIMAGEDATA));
		img.m_pSrcImage = pRefImage->m_pBuffer;
		img.m_iChannel = 3;
		img.m_iDepth = DEPTH_8U;
		img.m_iWidth = pRefImage->m_stFrame.m_dwWidth;
		img.m_iHeight = pRefImage->m_stFrame.m_dwHeight;
		img.m_iWidthStep = pRefImage->m_stFrame.m_dwPitch;
		img.m_iImageSize = pRefImage->m_nBufLen;

		// Calibration
		m_pCalibrationApp->SetInput(&img);
		m_pCalibrationApp->Process();
		m_pCalibrationApp->GetOutput(CALIBRATION_RESULT_IMAGE, calibratedImg);

		// Calibration 실패 시 img 사용
		if (NULL == calibratedImg.m_pSrcImage)
			memcpy(&calibratedImg, &img, sizeof(stAPPIMAGEDATA));

		Mat calibratedMat(calibratedImg.m_iHeight, calibratedImg.m_iWidth, CV_8UC3, calibratedImg.m_pSrcImage, calibratedImg.m_iWidthStep);
		cvtColor(calibratedMat, m_GrayMat, COLOR_BGR2GRAY);
		if (m_GrayMat.empty())
		{
			return FALSE;
		}

		stAPPIMAGEDATA grayImg;
		memset(&grayImg, 0, sizeof(stAPPIMAGEDATA));
		grayImg.m_pSrcImage = m_GrayMat.data;
		grayImg.m_iChannel = 1;
		grayImg.m_iDepth = DEPTH_8U;
		grayImg.m_iWidth = m_GrayMat.size().width;
		grayImg.m_iHeight = m_GrayMat.size().height;
		grayImg.m_iWidthStep = m_GrayMat.step1();
		grayImg.m_iImageSize = grayImg.m_iWidthStep * grayImg.m_iHeight;
#endif

		// FindLine: Metal
		stLine stMetalLine[FINDLINE_METAL_COUNT];
		double dAngle = 0.;
		int iFindLineResult[FINDLINE_METAL_COUNT] = { 0, };
		memset(stMetalLine, 0, sizeof(stMetalLine));

		for (int i = 0; i < sizeof(stMetalLine) / sizeof(stLine); i++)
		{
			if (m_pFindLineApp[i])
			{
#ifndef USE_BASLER_CAMERA
				m_pFindLineApp[i]->SetInput(&calibratedImg);
#else
				m_pFindLineApp[i]->SetInput(&grayImg);
#endif
				m_pFindLineApp[i]->Process();
				iFindLineResult[i] = m_pFindLineApp[i]->GetOutput(FINDLINE_LINE, stMetalLine[i]);
			}
		}
		// 첫번째 FindLine의 Angle 사용
		if (m_pFindLineApp[0])
		{
			m_pFindLineApp[0]->GetOutput(FINDLINE_ANGLE, dAngle);
			dAngle -= this->m_stInfoSize.m_pstFindLineROI[0].m_dAngle;
		}

		// Geometry (Line Intersection): Metal
		stPOINT stMetalPoint[FINDLINE_METAL_COUNT];
		memset(stMetalPoint, 0, sizeof(stMetalPoint));
		for (int i = 0; i < sizeof(stMetalPoint) / sizeof(stPOINT); i++)
		{
#ifndef USE_BASLER_CAMERA
			LineIntersection(&calibratedImg, stMetalLine[i], stMetalLine[(i + 1) % FINDLINE_METAL_COUNT], stMetalPoint[i]);
#else
			LineIntersection(&grayImg, stMetalLine[i], stMetalLine[(i + 1) % FINDLINE_METAL_COUNT], stMetalPoint[i]);
#endif
		}

		// FindLine의 ROI 변경
		if (ERR_SUCCESS == iFindLineResult[0] && ERR_SUCCESS == iFindLineResult[3])
		{
			m_stInfoSize.m_pstFindLineROI[iIndex].m_ptCriteria = stMetalPoint[3];
			m_stInfoSize.m_pstFindLineROI[iIndex].m_dAngleCriteria = dAngle;
			SetFindLineAppROI(m_pFindLineApp[iIndex], &m_stInfoSize.m_pstFindLineROI[iIndex], true, stMetalPoint[3], dAngle);
		}
		else
		{
			Log("Set Find Line ROI - Cannot Find Criteria Point");
			// 교차점 찾지 못했을 경우 ROI Clear
			m_stInfoSize.m_pstFindLineROI[iIndex].m_ptCriteria = { 0., 0. };
			m_stInfoSize.m_pstFindLineROI[iIndex].m_dAngleCriteria = 0.;
			SetFindLineAppROI(m_pFindLineApp[iIndex], NULL);
		}
	}

	// ROI 변경 후 Parameter 변경 될 수 있으므로 Parameter 다시 설정
	SetInfoFindLineParameter(&m_stInfoSize.m_pstFindLineParameter[iIndex], iIndex);

	return TRUE;
}

/**
* @brief FineLine의 Parameter Set 함수
* @param const INFO_FINDLINE_PARAMETER* pInfoLine 설정 값을 가져올 구조체
* @param const int iSample FindLine의 시료 타입 (A, B 구분)
* @param const int iIndex FindLine의 Index
* @return 설정 성공 여부
* @remark 설정 값을 가져오고 모든 FindLine 객체의 설정 값 변경
*/
BOOL CStepSizeSecond::SetInfoFindLineParameter(const INFO_FINDLINE_PARAMETER* pInfoLine, const int iIndex)
{
	if (NULL == pInfoLine || iIndex >= TYPE_FINDLINE_MAX || !m_bInit)
		return FALSE;

	memcpy(&m_stInfoSize.m_pstFindLineParameter[iIndex], pInfoLine, sizeof(INFO_FINDLINE_PARAMETER));

	SetFindLineAppParameter(m_pFindLineApp[iIndex], m_stInfoSize.m_pstFindLineParameter[iIndex]);

	return TRUE;
}

/**
* @brief FindLine 객체의 설정 값 Set 함수
* @param CLPApp *app 설정할 FindLine 객체의 포인터
* @param const string &direction FindLine 방향. lib_define.h의 FINDLINE_DIRECTION_...매크로 사용
* @param const INFO_FINDLINE_PARAMETER info FindLine의 설정 값 구조체
* @return 설정 성공 여부
*/
BOOL CStepSizeSecond::SetFindLineAppParameter(CLPApp *app, const INFO_FINDLINE_PARAMETER info)
{
	if (NULL == app)
		return FALSE;

	switch (info.m_iDirection)
	{
	case 0:
		app->SetParameter(FINDLINE_DIRECTION_LEFT_TO_RIGHT);
		break;
	case 1:
		app->SetParameter(FINDLINE_DIRECTION_RIGHT_TO_LEFT);
		break;
	case 2:
		app->SetParameter(FINDLINE_DIRECTION_UP_TO_BOTTOM);
		break;
	case 3:
		app->SetParameter(FINDLINE_DIRECTION_BOTTOM_TO_UP);
		break;
	default:
		app->SetParameter(FINDLINE_DIRECTION_LEFT_TO_RIGHT);
		break;
	}

	switch (info.m_iPolarity)
	{
	case 0:
		app->SetParameter(FINDLINE_POLARITY_BRIGHT_TO_DARK);
		break;
	case 1:
		app->SetParameter(FINDLINE_POLARITY_ALL);
		break;
	case 2:
		app->SetParameter(FINDLINE_POLARITY_DARK_TO_BRIGHT);
		break;
	default:
		app->SetParameter(FINDLINE_POLARITY_ALL);
		break;
	}

	switch (info.m_iLookFor)
	{
	case 0:
		app->SetParameter(FINDLINE_LOOKFOR_FIRST);
		break;
	case 1:
		app->SetParameter(FINDLINE_LOOKFOR_BEST);
		break;
	default:
		app->SetParameter(FINDLINE_LOOKFOR_FIRST);
		break;
	}

	app->SetParameter(FINDLINE_AUTOSETUP, DISABLE_PARAMETER);

	app->SetParameter(FINDLINE_STRENGTH_THRESHOLD, info.m_iStrengthThreshold);
	app->SetParameter(FINDLINE_SAMPLING, info.m_iSampling);
	app->SetParameter(FINDLINE_KERNELSIZE, info.m_iKernelSize);

	BOOL enableAngle = (info.m_bSearchAngle) ? TRUE : FALSE;
	app->SetParameter(FINDLINE_ENABLE_ANGLERANGE, enableAngle);
	app->SetParameter(FINDLINE_MINANGLE, info.m_iMinAngle);
	app->SetParameter(FINDLINE_MAXANGLE, info.m_iMaxAngle);

	app->SetParameter(FINDLINE_DISTANCE_THRESHOLD, static_cast<double>(info.m_iDistanceThreshold));

	return TRUE;
}

/**
* @brief FindLine 객체의 ROI Set 함수
* @param CLPApp *app 설정할 FindLine 객체의 포인터
* @param const INFO_FINDLINE_ROI *info FindLine의 ROI 설정 값 구조체의 포인터. NULL일 경우 ROI Clear
* @param const bool enableRefROI 상대 ROI 설정 여부
* @param const stPOINT refPt 상대 ROI 설정 시 기준 점
* @param const double refAngle 상대 ROI 설정 시 기준 각도
* @return 설정 성공 여부
* @remark info가 NULL일 경우 빈 ROI 벡터를 Set 하고 TRUE 반환
*/
BOOL CStepSizeSecond::SetFindLineAppROI(CLPApp *app, const INFO_FINDLINE_ROI *info, const bool enableRefROI, const stPOINT refPt, const double refAngle)
{
	if (NULL == app)
		return FALSE;
	
	vector<CLP_ROI> vecROI;

	// info가 NULL일 경우 빈 ROI 벡터를 Set 하고 TRUE 반환
	if (NULL == info)
	{
		app->SetROI(&vecROI);
		return TRUE;
	}

	eROITYPE roiType;
	switch (info->m_eTrackerType)
	{
	case TYPE_TRACKER_RECT:
	{
		roiType = eROIType_Rectangular;
		CLP_ROI roi(roiType,
			static_cast<int>(info->m_stCenterPt.m_fX - (info->m_fWidth / 2)),
			static_cast<int>(info->m_stCenterPt.m_fY - (info->m_fHeight / 2)),
			static_cast<int>(info->m_stCenterPt.m_fX + (info->m_fWidth / 2)),
			static_cast<int>(info->m_stCenterPt.m_fY + (info->m_fHeight / 2)));
		vecROI.push_back(roi);
	}
		break;
	case TYPE_TRACKER_RECT_ROTATE:
	{
		roiType = eROIType_RectangularRotate;
		CLP_ROI roi(roiType,
			static_cast<int>(info->m_stCenterPt.m_fX),
			static_cast<int>(info->m_stCenterPt.m_fY),
			info->m_dAngle,
			static_cast<int>(info->m_fWidth),
			static_cast<int>(info->m_fHeight));
		vecROI.push_back(roi);
	}
		break;
	default:
		break;
	}

	app->SetROI(&vecROI);

	if (enableRefROI &&vecROI.size() > 0)
	{
		app->SetCriteria(refPt, refAngle);
	}

	return TRUE;
}

/**
* @brief Calibration 객체의 설정 값 Set 함수
* @param const INFO_CALIBRATION* pstInfoCalibration Calibration의 설정 값 구조체
* @return 설정 성공 여부
*/
BOOL CStepSizeSecond::SetCalibration(const INFO_CALIBRATION* pstInfoCalibration)
{
	// NULL이 아닐 경우 복사, NULL일 경우 현재 멤버 변수를 그대로 사용
	if (NULL != pstInfoCalibration)
		memcpy(&m_stInfoSize.m_stCalibration, pstInfoCalibration, sizeof(INFO_CALIBRATION));

	if (NULL == m_pCalibrationApp)
		return FALSE;

	Log("Calibration Start");

	int iResult = ERR_SUCCESS;

	stPOINT pt1, pt2;
	double distance = 0;
	switch (m_stInfoSize.m_stCalibration.m_iMethod)
	{
	case 0:
		// Calibration Type
		m_pCalibrationApp->SetParameter(CALIBRATION_POINT_DISTANCE);
		pt1.m_fX = 0; pt1.m_fY = 0;
		pt2.m_fX = max(m_stInfoSize.m_stCalibration.m_iImgWidth - 1, 1); pt2.m_fY = max(m_stInfoSize.m_stCalibration.m_iImgHeight - 1, 1);
		distance = sqrt(m_stInfoSize.m_stCalibration.m_dWidth * m_stInfoSize.m_stCalibration.m_dWidth + m_stInfoSize.m_stCalibration.m_dHeight * m_stInfoSize.m_stCalibration.m_dHeight);
		m_pCalibrationApp->SetParameter(CALIBRATION_PUSH_POINT, pt1, pt2);
		m_pCalibrationApp->SetParameter(CALIBRATION_REALDISTANCE, distance);
		m_pCalibrationApp->SetParameter(CALIBRATION_MILLIMETER); // m_iPixelUnit 사용하지 않고 mm 고정
		break;
	case 1:
		// Calibration Type
		m_pCalibrationApp->SetParameter(CALIBRATION_DISTORTION);

		// Input Chess Board Image
		for (int i = 0; i < m_stInfoSize.m_stCalibration.m_nListCount; i++)
		{
			if (strnlen_s(m_stInfoSize.m_stCalibration.m_pszFilePathList[i], MAX_FILE_PATH_LEN) == 0)
				continue;
#ifndef CALIBRATION_THRESHOLD
			Mat matimg = imread(m_stInfoSize.m_stCalibration.m_pszFilePathList[i], CV_LOAD_IMAGE_GRAYSCALE);
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
			Mat matimg = imread(m_stInfoSize.m_stCalibration.m_pszFilePathList[i], CV_LOAD_IMAGE_GRAYSCALE);
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

		m_pCalibrationApp->SetParameter(CALIBRATION_SELECT_REFERENCEIMAGE, m_stInfoSize.m_stCalibration.m_nIdxReference);

		LPVal rowcolnum(m_stInfoSize.m_stCalibration.m_iRow, m_stInfoSize.m_stCalibration.m_iCol);
		m_pCalibrationApp->SetParameter(CALIBRATION_ROWCOLNUM, rowcolnum);
		m_pCalibrationApp->SetParameter(CALIBRATION_SPACING, m_stInfoSize.m_stCalibration.m_dSpacing);
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
BOOL CStepSizeSecond::SetSizeGain(const INFO_SIZE_GAIN* pstInfoSizeGain)
{
	if (NULL == pstInfoSizeGain)
		return FALSE;

	memcpy(&m_stInfoSize.m_stSizeGain, pstInfoSizeGain, sizeof(INFO_SIZE_GAIN));

	for (int i = 0; i < sizeof(INFO_SIZE_GAIN) / sizeof(double); i++)
	{
		if (m_stInfoSize.m_stSizeGain.m_dGain[i] <= 0
			|| m_stInfoSize.m_stSizeGain.m_dGain[i] > 100)
			m_stInfoSize.m_stSizeGain.m_dGain[i] = 1.0;
	}

	return true;
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
BOOL CStepSizeSecond::LineIntersection(stAPPIMAGEDATA *img, const stLine &line1, const stLine &line2, stPOINT &ptOut)
{
	if (NULL == m_pGeometryApp || NULL == img)
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
BOOL CStepSizeSecond::MidPoint(stAPPIMAGEDATA *img, const stPOINT &pt1, const stPOINT &pt2, stPOINT &ptOut)
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
BOOL CStepSizeSecond::LinetoLineDistance(stAPPIMAGEDATA *img, const stLine &line1, const stLine &line2, double &distance, stLine &distanceLine)
{
	if (NULL == m_pGeometryApp || NULL == img)
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
BOOL CStepSizeSecond::PointtoPointDistance(stAPPIMAGEDATA *img, const stPOINT &pt1, const stPOINT &pt2, double &distance, stLine &distanceLine)
{
	if (NULL == m_pGeometryApp || NULL == img)
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
BOOL CStepSizeSecond::PointtoLineDistance(LP_VisionApp::stAPPIMAGEDATA *img, const stLine &line, const stPOINT &pt, double &distance, stLine &distanceLine)
{
	if (NULL == m_pGeometryApp || NULL == img)
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
	else
	{
		iResult = FALSE;
	}

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
BOOL CStepSizeSecond::S1Distance(LP_VisionApp::stAPPIMAGEDATA *img, const stLine &metalLine, const stLine &tapeLineS1, const double metalLineDistance,
	double &s1Distance, stLine &s1DistanceLine)
{
	if (NULL == m_pGeometryApp || NULL == img || metalLineDistance <= 0)
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
BOOL CStepSizeSecond::S2Distance(LP_VisionApp::stAPPIMAGEDATA *img, const stLine &metalLine, const stLine &tapeLineS2, const double metalLineDistance,
	double &s2Distance, stLine &s2DistanceLine)
{
	if (NULL == m_pGeometryApp || NULL == img || metalLineDistance <= 0)
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
BOOL CStepSizeSecond::S3Distance(LP_VisionApp::stAPPIMAGEDATA *img, const stLine &metalLine, const stLine &tapeLineS3, const double metalLineDistance,
	double &s3Distance, stLine &s3DistanceLine)
{
	if (NULL == m_pGeometryApp || NULL == img || metalLineDistance <= 0)
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

/**
* @brief 치수 검사 설정 초기 값을 전달하는 함수
* @param INFO_INSPECTION_SIZE *info 초기 값을 받을 구조체 포인터
*/
void CStepSizeSecond::GetDefaultSizeSetting(INFO_INSPECTION_SIZE *info)
{
	info->m_pstStepStrobe[0].m_eStrobeType = TYPE_STROBE_COXIAL;
	info->m_pstStepStrobe[0].m_nStrobeBrightness = STROBE_MAX_BRIGHT_COAX;
	info->m_pstStepStrobe[1].m_eStrobeType = TYPE_STROBE_OFF;
	info->m_pstStepStrobe[1].m_nStrobeBrightness = 0;

	// Metal ROI
	for (int j = TYPE_FINDLINE_METAL_TOP; j <= TYPE_FINDLINE_METAL_LEFT; j++)
	{
		info->m_pstFindLineROI[j].m_eTrackerType = TYPE_TRACKER_RECT_ROTATE;
		info->m_pstFindLineROI[j].m_stCenterPt = { 1024.0, 1024.0 };
		info->m_pstFindLineROI[j].m_fWidth = 2008; // 2048 - 20 - 20 (상하좌우 20 pixel 제외)
		info->m_pstFindLineROI[j].m_fHeight = 2008;
		info->m_pstFindLineROI[j].m_dAngle = 0;
		info->m_pstFindLineROI[j].m_ptCriteria = { 0., 0. };
		info->m_pstFindLineROI[j].m_dAngleCriteria = 0.;
	}
	// Tape ROI (Left)
	for (int j = TYPE_FINDLINE_TAPE_LEFTWING_TOP; j <= TYPE_FINDLINE_TAPE_LEFTWING_BOTTOM; j++)
	{
		info->m_pstFindLineROI[j].m_eTrackerType = TYPE_TRACKER_RECT_ROTATE;
		info->m_pstFindLineROI[j].m_stCenterPt = { 844., 1474. }; // m_ptCriteria + { 70 + m_fWidth/2, + m_fHeight/2 }
		info->m_pstFindLineROI[j].m_fWidth = 250;
		info->m_pstFindLineROI[j].m_fHeight = 150;
		info->m_pstFindLineROI[j].m_dAngle = 0;
		info->m_pstFindLineROI[j].m_ptCriteria = { 649., 1399. }; // 2048/2 - 750/2, 2048/2 + 750/2
		info->m_pstFindLineROI[j].m_dAngleCriteria = 270.;
	}
	// Tape ROI (Center)
	{
		int j = TYPE_FINDLINE_TAPE_CENTER_TOP;
		{
			info->m_pstFindLineROI[j].m_eTrackerType = TYPE_TRACKER_RECT_ROTATE;
			info->m_pstFindLineROI[j].m_stCenterPt = { 844., 1024. }; // { m_ptCriteria.m_fX + 70 + m_fWidth/2, 1024.0 }
			info->m_pstFindLineROI[j].m_fWidth = 250;
			info->m_pstFindLineROI[j].m_fHeight = 250;
			info->m_pstFindLineROI[j].m_dAngle = 0;
			info->m_pstFindLineROI[j].m_ptCriteria = { 649., 1399. }; // 2048/2 - 750/2, 2048/2 + 750/2
			info->m_pstFindLineROI[j].m_dAngleCriteria = 270.;
		}

		j = TYPE_FINDLINE_TAPE_CENTER_TOPLEFT;
		{
			info->m_pstFindLineROI[j].m_eTrackerType = TYPE_TRACKER_RECT_ROTATE;
			info->m_pstFindLineROI[j].m_stCenterPt = { 844., 1274. }; // { m_ptCriteria.m_fX + 70 + m_fWidth/2, 1024.0 + m_fHeight }
			info->m_pstFindLineROI[j].m_fWidth = 250;
			info->m_pstFindLineROI[j].m_fHeight = 250;
			info->m_pstFindLineROI[j].m_dAngle = 0;
			info->m_pstFindLineROI[j].m_ptCriteria = { 649., 1399. }; // 2048/2 - 750/2, 2048/2 + 750/2
			info->m_pstFindLineROI[j].m_dAngleCriteria = 270.;
		}

		j = TYPE_FINDLINE_TAPE_CENTER_TOPRIGHT;
		{
			info->m_pstFindLineROI[j].m_eTrackerType = TYPE_TRACKER_RECT_ROTATE;
			info->m_pstFindLineROI[j].m_stCenterPt = { 844., 774. }; // { m_ptCriteria.m_fX + 70 + m_fWidth/2, 1024.0 - m_fHeight }
			info->m_pstFindLineROI[j].m_fWidth = 250;
			info->m_pstFindLineROI[j].m_fHeight = 250;
			info->m_pstFindLineROI[j].m_dAngle = 0;
			info->m_pstFindLineROI[j].m_ptCriteria = { 649., 1399. }; // 2048/2 - 750/2, 2048/2 + 750/2
			info->m_pstFindLineROI[j].m_dAngleCriteria = 270.;
		}

		j = TYPE_FINDLINE_TAPE_CENTER_BOTTOM;
		{
			info->m_pstFindLineROI[j].m_eTrackerType = TYPE_TRACKER_RECT_ROTATE;
			info->m_pstFindLineROI[j].m_stCenterPt = { 844., 1024. }; // { m_ptCriteria.m_fX + 70 + m_fWidth/2, 1024.0 }
			info->m_pstFindLineROI[j].m_fWidth = 250;
			info->m_pstFindLineROI[j].m_fHeight = 250;
			info->m_pstFindLineROI[j].m_dAngle = 0;
			info->m_pstFindLineROI[j].m_ptCriteria = { 649., 1399. }; // 2048/2 - 750/2, 2048/2 + 750/2
			info->m_pstFindLineROI[j].m_dAngleCriteria = 270.;
		}

		j = TYPE_FINDLINE_TAPE_CENTER_BOTTOMLEFT;
		{
			info->m_pstFindLineROI[j].m_eTrackerType = TYPE_TRACKER_RECT_ROTATE;
			info->m_pstFindLineROI[j].m_stCenterPt = { 844., 1274. }; // { m_ptCriteria.m_fX + 70 + m_fWidth/2, 1024.0 + m_fHeight }
			info->m_pstFindLineROI[j].m_fWidth = 250;
			info->m_pstFindLineROI[j].m_fHeight = 250;
			info->m_pstFindLineROI[j].m_dAngle = 0;
			info->m_pstFindLineROI[j].m_ptCriteria = { 649., 1399. }; // 2048/2 - 750/2, 2048/2 + 750/2
			info->m_pstFindLineROI[j].m_dAngleCriteria = 270.;
		}

		j = TYPE_FINDLINE_TAPE_CENTER_BOTTOMRIGHT;
		{
			info->m_pstFindLineROI[j].m_eTrackerType = TYPE_TRACKER_RECT_ROTATE;
			info->m_pstFindLineROI[j].m_stCenterPt = { 844., 774. }; // { m_ptCriteria.m_fX + 70 + m_fWidth/2, 1024.0 - m_fHeight }
			info->m_pstFindLineROI[j].m_fWidth = 250;
			info->m_pstFindLineROI[j].m_fHeight = 250;
			info->m_pstFindLineROI[j].m_dAngle = 0;
			info->m_pstFindLineROI[j].m_ptCriteria = { 649., 1399. }; // 2048/2 - 750/2, 2048/2 + 750/2
			info->m_pstFindLineROI[j].m_dAngleCriteria = 270.;
		}

	}
	// Tape ROI (Right)
	for (int j = TYPE_FINDLINE_TAPE_RIGHTWING_TOP; j <= TYPE_FINDLINE_TAPE_RIGHTWING_BOTTOM; j++)
	{
		info->m_pstFindLineROI[j].m_eTrackerType = TYPE_TRACKER_RECT_ROTATE;
		info->m_pstFindLineROI[j].m_stCenterPt = { 844., 574. }; // m_ptCriteria + { 70 + m_fWidth/2, - m_fHeight/2 }
		info->m_pstFindLineROI[j].m_fWidth = 250;
		info->m_pstFindLineROI[j].m_fHeight = 150;
		info->m_pstFindLineROI[j].m_dAngle = 0;
		info->m_pstFindLineROI[j].m_ptCriteria = { 649., 1399. }; // 2048/2 - 750/2, 2048/2 + 750/2
		info->m_pstFindLineROI[j].m_dAngleCriteria = 270.;
	}

	// Parameters
	for (int i = 0; i < TYPE_FINDLINE_MAX; i++)
	{
		info->m_pstFindLineParameter[i].m_iDirection = m_iDefaultDirection[i];
		info->m_pstFindLineParameter[i].m_iPolarity = m_iDefaultPolarity[i];
		info->m_pstFindLineParameter[i].m_iLookFor = m_iDefaultLookFor[i];
		info->m_pstFindLineParameter[i].m_iStrengthThreshold = m_iDefaultStrengthThreshold[i];
		info->m_pstFindLineParameter[i].m_iSampling = m_iDefaultSampling[i];
		info->m_pstFindLineParameter[i].m_iKernelSize = m_iDefaultKernelSize[i];

		info->m_pstFindLineParameter[i].m_bSearchAngle = false;
		info->m_pstFindLineParameter[i].m_iMinAngle = 0;
		info->m_pstFindLineParameter[i].m_iMaxAngle = 180;

		info->m_pstFindLineParameter[i].m_iDistanceThreshold = 2;
	}

	memset(&info->m_stCalibration, 0, sizeof(INFO_CALIBRATION));

	for (int i = 0; i < sizeof(INFO_SIZE_GAIN_NAME) / sizeof(double); i++)
		info->m_stSizeGain.m_dGain[i] = 1.0;
}

bool CStepSizeSecond::DongleLogin()
{
	/*DongleLogout();

	ChaspFeature haspFeature = ChaspFeature::fromFeature(static_cast<hasp_u32_t>(HASP_FEATURE));
	Chasp hasp_temp(haspFeature);
	haspStatus status = hasp_temp.login(vendorCode);
	if (HASP_SUCCEEDED(status))
	{
		hasp = hasp_temp;
		return true;
	}
	else
	{
		Log("Fail to login to dongle");
		return false;
	}

	return false;*/

	return true;
}

bool CStepSizeSecond::DongleCheck()
{
	/*hasp_size_t size = 0;
	ChaspFile mainFile = hasp.getFile(ChaspFile::fileReadOnly);
	haspStatus status = mainFile.getFileSize(size);

	if (HASP_SUCCEEDED(status))
		return true;

	return false;*/
	return true;
}

void CStepSizeSecond::DongleLogout()
{
	if (hasp.isLoggedIn())
		hasp.logout();
}