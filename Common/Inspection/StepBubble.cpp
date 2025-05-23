#include "StdAfx.h"
#include "StepBubble.h"
#include "until_func.h"
#include "Util/Util.h"

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>


CStepBubble::CStepBubble()
	: CStep("BUBBLE")
{
	memset(&m_stInfoBubble, 0x00, sizeof(INFO_INSPECTION_BUBBLE));
	for (int i = 0; i < MAX_STEPSTROBE_LIST; i++)
	{
		m_stInfoBubble.m_pstStepStrobe[i].m_eStrobeType = TYPE_STROBE_OFF;
		m_stInfoBubble.m_pstStepStrobe[i].m_nStrobeBrightness = 0;
	}

#ifdef NAVIAI_SUPPORT
	if (gNAVIAIMars1)
		gNAVIAIMars1 = NULL;
	if (gNAVIAIMars2)
		gNAVIAIMars2 = NULL;
#endif
}

CStepBubble::~CStepBubble()
{
	Deinit();
}

BOOL CStepBubble::Init(TYPE_CAMERAPOS eCameraPos, INFO_LOGFUNC stLogFunc)
{
	BOOL bResult = TRUE;
	Deinit();

	this->m_eCameraPos = eCameraPos;
	this->m_stLogFunc = stLogFunc;

#ifdef NAVIAI_SUPPORT
	makeColorTable(256, RainbowColorTable);

	// Initilize Mars
	gNAVIAIMars2 = CreateNAVIAIMars();
	NAVIAIError result2 = gNAVIAIMars2->Init(NAVIAIBrewMode_GPU_CUDA, 0, "License.lpla");

	if (NAVIAIError_Success != result2){
		Log("NAVIAIMars Init fail Error Code [%d]", result2);
		Deinit();
	}

	// Open Model File
	if (NAVIAIError_Success == result2)
	{
		char *trained_file2 = "step3.dat";
		result2 = gNAVIAIMars2->Open(trained_file2, &net_info2);
		if (NAVIAIError_Success != result2 || NAVIAIError_Success != result2){
			Log("NAVIAIMars Open Failed [%s] Error Code [%d]", trained_file2, result2);
			Deinit();
		}
	}

	bResult = (NAVIAIError_Success == result2) ? TRUE : FALSE;
#endif

	m_bInit = bResult;

	return bResult;
}

void CStepBubble::Deinit()
{
	m_eCameraPos = TYPE_CAMERAPOS_NONE;
	memset(&m_stLogFunc, 0x00, sizeof(INFO_LOGFUNC));

#ifdef NAVIAI_SUPPORT
	if (gNAVIAIMars2)
	{
		gNAVIAIMars2->DestroySelf();
		gNAVIAIMars2 = NULL;
	}

	if (gNAVIAIMars1)
	{
		gNAVIAIMars1->DestroySelf();
		gNAVIAIMars1 = NULL;
	}
#endif

}

BOOL CStepBubble::Process(CSampleSide& sample)
{
	BOOL bResult = TRUE;

	Log("Process Start");

#ifdef NAVIAI_SUPPORT
	INAVIAIMars* gNAVIAIMars = NULL;

	gNAVIAIMars = gNAVIAIMars2;
	net_info = net_info2;

#ifdef USE_BASLER_CAMERA
	// 抗寇贸府
	if (!m_bInit ||
		gNAVIAIMars == NULL ||
		sample.m_pRefImage == NULL ||
		sample.m_pRefImage->m_pBuffer == NULL ||
		sample.m_pRefImage->m_stFrame.m_eColor != TYPE_CAMCOLOR_COLOR ||
		sample.m_pRefImage->m_stFrame.m_eDataBit != TYPE_DATABIT_08)
	{
		Log("Initialize/Image Error");
#if 1 // test code
		if (!m_bInit)
			Log("Initialize Error");
		else if (gNAVIAIMars == NULL)
			Log("gNAVIAIMars Error");
		else if (sample.m_pRefImage == NULL)
			Log("Image == NULL Error");
		else if (sample.m_pRefImage->m_pBuffer == NULL)
			Log("Buffer == NULL Error");
		else if (sample.m_pRefImage->m_stFrame.m_eColor != TYPE_CAMCOLOR_COLOR)
			Log("Color != TYPE_CAMCOLOR_COLOR Error");
		else if (sample.m_pRefImage->m_stFrame.m_eDataBit != TYPE_DATABIT_08)
			Log("DataBit != TYPE_DATABIT_08 Error");
		else
			Log("Undefined Error");
#endif

		cv::Mat camera_input(sample.m_pRefImage->m_stFrame.m_dwHeight,
			sample.m_pRefImage->m_stFrame.m_dwWidth,
			(sample.m_pRefImage->m_stFrame.m_eColor == TYPE_CAMCOLOR_COLOR) ? CV_8UC3 : CV_8UC1,
			sample.m_pRefImage->m_pBuffer,
			sample.m_pRefImage->m_stFrame.m_dwPitch);
		camera_input.copyTo(sample.m_BubbleResult.m_pProbImage);
		if (sample.m_BubbleResult.m_pProbImage.channels() == 1)
			cv::cvtColor(sample.m_BubbleResult.m_pProbImage, sample.m_BubbleResult.m_pProbImage, CV_GRAY2BGR);

		return FALSE;
	}
#else
	// 抗寇贸府
	if (!m_bInit ||
		gNAVIAIMars == NULL ||
		sample.m_pRefImage->m_pBuffer == NULL ||
		sample.m_pRefImage->m_stFrame.m_eColor != TYPE_CAMCOLOR_MONO ||
		sample.m_pRefImage->m_stFrame.m_eDataBit != TYPE_DATABIT_08)
	{
		Log("Initialize/Image Error");

		cv::Mat camera_input(sample.m_pRefImage->m_stFrame.m_dwHeight,
			sample.m_pRefImage->m_stFrame.m_dwWidth,
			(sample.m_pRefImage->m_stFrame.m_eDataBit == TYPE_DATABIT_24) ? CV_8UC3 : CV_8UC1,
			sample.m_pRefImage->m_pBuffer,
			sample.m_pRefImage->m_stFrame.m_dwWidth);
		camera_input.copyTo(sample.m_BubbleResult.m_pProbImage);
		if (sample.m_BubbleResult.m_pProbImage.channels() == 1)
			cv::cvtColor(sample.m_BubbleResult.m_pProbImage, sample.m_BubbleResult.m_pProbImage, CV_GRAY2BGR);

		return FALSE;
	}
#endif

	const char *input_image = "wheel_0726.png";
	cv::Rect roi;
	// width and height are depend on net_info(trained data due to .dat file)
	roi.width = AI_ROI_WIDTH;
	roi.height = AI_ROI_HEIGHT;

	roi.x = m_stInfoBubble.m_stRoi.m_rtRoi.left;
	if (roi.x < 0){
		roi.x = 0;
	}
	else if (roi.x > sample.m_pRefImage->m_stFrame.m_dwWidth - AI_ROI_WIDTH){
		roi.x = sample.m_pRefImage->m_stFrame.m_dwWidth - AI_ROI_WIDTH;
	}

	roi.y = m_stInfoBubble.m_stRoi.m_rtRoi.top;
	if (roi.y < 0){
		roi.y = 0;
	}
	else if (roi.y > sample.m_pRefImage->m_stFrame.m_dwHeight - AI_ROI_HEIGHT){
		roi.y = sample.m_pRefImage->m_stFrame.m_dwHeight - AI_ROI_HEIGHT;
	}

	cv::Mat input2;
	//  input2 : same size with camera input
#ifdef USE_BASLER_CAMERA
	input2 = cv::Mat(sample.m_pRefImage->m_stFrame.m_dwHeight, sample.m_pRefImage->m_stFrame.m_dwWidth, CV_8UC3, sample.m_pRefImage->m_pBuffer, sample.m_pRefImage->m_stFrame.m_dwPitch);
#else
	input2 = cv::Mat(sample.m_pRefImage->m_stFrame.m_dwHeight, sample.m_pRefImage->m_stFrame.m_dwWidth, CV_8UC1, sample.m_pRefImage->m_pBuffer, sample.m_pRefImage->m_stFrame.m_dwWidth);
#endif

	cv::Mat input;
	cv::Size temp_size(net_info.width, net_info.height);
	cv::resize(input2(roi), input, temp_size);

	if (input.data == NULL){
		printf("Can not input [%s]\n", input_image);
	}
	else{
		if (m_bImgLog){
			//saveLogPicture("thirdStep", input);
			// Version 1.3.8.1 Image Log Format (jpg)
			saveLogPicture("thirdStep", input, m_bImgCompress);
		}
	}

	// Mars Process
	NAVIAIError result;
	int nLayerCnt = 0;
	float* output;
#ifdef USE_BASLER_CAMERA
	result = gNAVIAIMars->Process(net_info.mode, input.channels(), input.cols, input.rows, input.step[0], NAVIAIInputType_8U, input.data, &nLayerCnt, &output);
#else
	result = gNAVIAIMars->Process(net_info.mode, input.channels(), input.cols, input.rows, input.step[0], NAVIAIInputType_8U, input.data, &nLayerCnt, &output);
#endif
	if (NAVIAIError_Success != result){
		Log("NAVIAIMars Process Fail Error Code [%d] \n", result);

		input2.copyTo(sample.m_BubbleResult.m_pProbImage);
		if (sample.m_BubbleResult.m_pProbImage.channels() == 1)
			cv::cvtColor(sample.m_BubbleResult.m_pProbImage, sample.m_BubbleResult.m_pProbImage, CV_GRAY2BGR);

		return FALSE;
	}

	//Show result
	float* background = output;
	float* defect = output + net_info.height * net_info.width;
	g_raw_result_img = cv::Mat::zeros(net_info.height, net_info.width, CV_8UC1);

	int pos;
	for (int i = 0; i < net_info.height; i++) {
		for (int j = 0; j < net_info.width; j++) {
			pos = i * net_info.width + j;
			if (defect[pos] > background[pos]){
				g_raw_result_img.data[pos] = Normalize((defect[pos] - background[pos]), net_info.threshold[1].min, net_info.threshold[1].max, MAX_RANGE_VALUE);
			}
		}
	}
	// for visualization in input2(camera input), belowing process is to make Mat img as result with input2 size
	cv::Size network_size(input2.size().width, input2.size().height);
	cv::resize(input2, g_input_img, network_size);
	if (input2.channels() == 1) cv::cvtColor(g_input_img, g_input_img, CV_GRAY2BGR);

	//find blob
	std::vector<std::vector<cv::Point> > contours;
	std::vector<cv::Point2f>center(contours.size());
	std::vector<float>radius(contours.size());

	g_raw_result_img.copyTo(g_result_img);

	cv::Mat threshold_output;
	std::vector<cv::Vec4i> hierarchy;
	threshold(g_result_img, threshold_output, m_stInfoBubble.m_stParaBubble.prob_thres, 1, cv::THRESH_BINARY);

	// Log Test
	//  defect size check
	bResult = checkBlobSize(threshold_output, g_result_img, sample.m_BubbleResult.m_fMaxDefectSize, m_stInfoBubble.m_stParaBubble.blobSize_thres, 4, m_stLogFunc, m_eCameraPos);

	// for visualization
	g_input_img.copyTo(g_view_img);
	bool found_bad_pixel = false;

	float ratio_H_netroi = (float)net_info.height / (float)roi.height;
	float ratio_W_netroi = (float)net_info.width / (float)roi.width;
	// init point is (m_stInfoStain.m_stRoi.m_rtRoi.left, m_stInfoStain.m_stRoi.m_rtRoi.top) due to roi setting
	for (int y = roi.y; y < roi.y + roi.height; y++) {
		for (int x = roi.x; x < roi.x + roi.width; x++) {
			int value = g_result_img.data[(int)((float)(y - roi.y)*(float)(ratio_H_netroi)) * g_result_img.cols + (int)((float)(x - roi.x)*ratio_W_netroi)];
			if (value > m_stInfoBubble.m_stParaBubble.prob_thres){
				g_view_img.at<cv::Vec3b>(y, x)[0] = GetBValue(RainbowColorTable[value]);
				g_view_img.at<cv::Vec3b>(y, x)[1] = GetGValue(RainbowColorTable[value]);
				g_view_img.at<cv::Vec3b>(y, x)[2] = GetRValue(RainbowColorTable[value]);
				found_bad_pixel = true;
			}
		}
	}

	cv::Size size = { input2.cols, input2.rows };
	// matching result on input2 with output setting on this tool
	cv::resize(g_view_img, sample.m_BubbleResult.m_pProbImage, size);

#endif
	sample.m_BubbleResult.m_bResult = bResult;
	Log("Process End");
	return TRUE;
}

BOOL CStepBubble::Process(CSampleSide& sample, cv::Mat captureImg)
{
	BOOL bResult = TRUE;

	Log("Process Start");

#ifdef NAVIAI_SUPPORT
	INAVIAIMars* gNAVIAIMars = NULL;

	gNAVIAIMars = gNAVIAIMars2;
	net_info = net_info2;

#ifdef USE_BASLER_CAMERA
	// 抗寇贸府
//	if (!m_bInit ||
//		gNAVIAIMars == NULL ||
//		sample.m_pRefImage == NULL ||
//		sample.m_pRefImage->m_pBuffer == NULL ||
//		sample.m_pRefImage->m_stFrame.m_eColor != TYPE_CAMCOLOR_COLOR ||
//		sample.m_pRefImage->m_stFrame.m_eDataBit != TYPE_DATABIT_08)
//	{
	
	if (!m_bInit ||
		gNAVIAIMars == NULL ||
		captureImg.data == NULL ||
		captureImg.channels() != 3 ||
		captureImg.depth() != CV_8U)
	{
		Log("Initialize/Image Error");
#if 1 // test code
//		if (!m_bInit)
//			Log("Initialize Error");
//		else if (gNAVIAIMars == NULL)
//			Log("gNAVIAIMars Error");
//		else if (sample.m_pRefImage == NULL)
//			Log("Image == NULL Error");
//		else if (sample.m_pRefImage->m_pBuffer == NULL)
//			Log("Buffer == NULL Error");
//		else if (sample.m_pRefImage->m_stFrame.m_eColor != TYPE_CAMCOLOR_COLOR)
//			Log("Color != TYPE_CAMCOLOR_COLOR Error");
//		else if (sample.m_pRefImage->m_stFrame.m_eDataBit != TYPE_DATABIT_08)
//			Log("DataBit != TYPE_DATABIT_08 Error");
//		else
//			Log("Undefined Error");
		if (!m_bInit)
			Log("Initialize Error");
		else if (gNAVIAIMars == NULL)
			Log("gNAVIAIMars Error");
		//else if (sample.m_pRefImage == NULL)
		//	Log("Image == NULL Error");
		else if (captureImg.data == NULL)
			Log("captureImg.data == NULL Error");
		else if (captureImg.channels() != 3)
			Log("captureImg.channels != 3 Error");
		else if (captureImg.depth() != CV_8U)
			Log("captureImg.depth != CV_8U Error");
		else
			Log("Undefined Error");
#endif

		/*cv::Mat camera_input(sample.m_pRefImage->m_stFrame.m_dwHeight,
			sample.m_pRefImage->m_stFrame.m_dwWidth,
			(sample.m_pRefImage->m_stFrame.m_eColor == TYPE_CAMCOLOR_COLOR) ? CV_8UC3 : CV_8UC1,
			sample.m_pRefImage->m_pBuffer,
			sample.m_pRefImage->m_stFrame.m_dwPitch);*/

		/*cv::Mat camera_input(captureImg.rows,
			captureImg.cols,
			captureImg.TYPE_MASK,
			captureImg.data,
			0Ui64)*/;

		cv::Mat camera_input = captureImg.clone();		
		camera_input.copyTo(sample.m_BubbleResult.m_pProbImage);
		if (sample.m_BubbleResult.m_pProbImage.channels() == 1)
			cv::cvtColor(sample.m_BubbleResult.m_pProbImage, sample.m_BubbleResult.m_pProbImage, CV_GRAY2BGR);

		return FALSE;
	}


#else
	// 抗寇贸府
	if (!m_bInit ||
		gNAVIAIMars == NULL ||
		sample.m_pRefImage->m_pBuffer == NULL ||
		sample.m_pRefImage->m_stFrame.m_eColor != TYPE_CAMCOLOR_MONO ||
		sample.m_pRefImage->m_stFrame.m_eDataBit != TYPE_DATABIT_08)
	{
		Log("Initialize/Image Error");

		cv::Mat camera_input(sample.m_pRefImage->m_stFrame.m_dwHeight,
			sample.m_pRefImage->m_stFrame.m_dwWidth,
			(sample.m_pRefImage->m_stFrame.m_eDataBit == TYPE_DATABIT_24) ? CV_8UC3 : CV_8UC1,
			sample.m_pRefImage->m_pBuffer,
			sample.m_pRefImage->m_stFrame.m_dwWidth);
		camera_input.copyTo(sample.m_BubbleResult.m_pProbImage);
		if (sample.m_BubbleResult.m_pProbImage.channels() == 1)
			cv::cvtColor(sample.m_BubbleResult.m_pProbImage, sample.m_BubbleResult.m_pProbImage, CV_GRAY2BGR);

		return FALSE;
	}
#endif

	const char *input_image = "wheel_0726.png";
	cv::Rect roi;
	// width and height are depend on net_info(trained data due to .dat file)
	roi.width = AI_ROI_WIDTH;
	roi.height = AI_ROI_HEIGHT;

	roi.x = m_stInfoBubble.m_stRoi.m_rtRoi.left;
	if (roi.x < 0){
		roi.x = 0;
	}
	else if (roi.x > captureImg.cols - AI_ROI_WIDTH){
		roi.x = captureImg.cols - AI_ROI_WIDTH;
	}

	roi.y = m_stInfoBubble.m_stRoi.m_rtRoi.top;
	if (roi.y < 0){
		roi.y = 0;
	}
	else if (roi.y > captureImg.rows - AI_ROI_HEIGHT){
		roi.y = captureImg.rows - AI_ROI_HEIGHT;
	}

	sample.m_BubbleResult.m_pInputImage = captureImg;
	cv::Mat input2;
	//  input2 : same size with camera input
#ifdef USE_BASLER_CAMERA
	//input2 = cv::Mat(captureImg.rows, captureImg.cols, CV_8UC3, captureImg.data, captureImg.step1());
	input2 = captureImg.clone();
#else
	input2 = cv::Mat(sample.m_pRefImage->m_stFrame.m_dwHeight, sample.m_pRefImage->m_stFrame.m_dwWidth, CV_8UC1, sample.m_pRefImage->m_pBuffer, sample.m_pRefImage->m_stFrame.m_dwWidth);
#endif

	cv::Mat input;
	cv::Size temp_size(net_info.width, net_info.height);
	cv::resize(input2(roi), input, temp_size);

	if (input.data == NULL){
		printf("Can not input [%s]\n", input_image);
	}
	else{
		if (m_bImgLog){
			//saveLogPicture("thirdStep", input);
			// Version 1.3.8.1 Image Log Format (jpg)
			saveLogPicture("thirdStep", input, m_bImgCompress);
		}
	}

	// Mars Process
	NAVIAIError result;
	int nLayerCnt = 0;
	float* output;
#ifdef USE_BASLER_CAMERA
	result = gNAVIAIMars->Process(net_info.mode, input.channels(), input.cols, input.rows, input.step[0], NAVIAIInputType_8U, input.data, &nLayerCnt, &output);
#else
	result = gNAVIAIMars->Process(net_info.mode, input.channels(), input.cols, input.rows, input.step[0], NAVIAIInputType_8U, input.data, &nLayerCnt, &output);
#endif
	if (NAVIAIError_Success != result){
		Log("NAVIAIMars Process Fail Error Code [%d] \n", result);

		input2.copyTo(sample.m_BubbleResult.m_pProbImage);
		if (sample.m_BubbleResult.m_pProbImage.channels() == 1)
			cv::cvtColor(sample.m_BubbleResult.m_pProbImage, sample.m_BubbleResult.m_pProbImage, CV_GRAY2BGR);

		return FALSE;
	}

	//Show result
	float* background = output;
	float* defect = output + net_info.height * net_info.width;
	g_raw_result_img = cv::Mat::zeros(net_info.height, net_info.width, CV_8UC1);

	int pos;
	for (int i = 0; i < net_info.height; i++) {
		for (int j = 0; j < net_info.width; j++) {
			pos = i * net_info.width + j;
			if (defect[pos] > background[pos]){
				g_raw_result_img.data[pos] = Normalize((defect[pos] - background[pos]), net_info.threshold[1].min, net_info.threshold[1].max, MAX_RANGE_VALUE);
			}
		}
	}
	// for visualization in input2(camera input), belowing process is to make Mat img as result with input2 size
	cv::Size network_size(input2.size().width, input2.size().height);
	cv::resize(input2, g_input_img, network_size);
	if (input2.channels() == 1) cv::cvtColor(g_input_img, g_input_img, CV_GRAY2BGR);

	//find blob
	std::vector<std::vector<cv::Point> > contours;
	std::vector<cv::Point2f>center(contours.size());
	std::vector<float>radius(contours.size());

	g_raw_result_img.copyTo(g_result_img);

	cv::Mat threshold_output;
	std::vector<cv::Vec4i> hierarchy;
	threshold(g_result_img, threshold_output, m_stInfoBubble.m_stParaBubble.prob_thres, 1, cv::THRESH_BINARY);

	// Log Test
	//  defect size check
	bResult = checkBlobSize(threshold_output, g_result_img, sample.m_BubbleResult.m_fMaxDefectSize, m_stInfoBubble.m_stParaBubble.blobSize_thres, 4, m_stLogFunc, m_eCameraPos);

	// for visualization
	g_input_img.copyTo(g_view_img);
	bool found_bad_pixel = false;

	float ratio_H_netroi = (float)net_info.height / (float)roi.height;
	float ratio_W_netroi = (float)net_info.width / (float)roi.width;
	// init point is (m_stInfoStain.m_stRoi.m_rtRoi.left, m_stInfoStain.m_stRoi.m_rtRoi.top) due to roi setting
	for (int y = roi.y; y < roi.y + roi.height; y++) {
		for (int x = roi.x; x < roi.x + roi.width; x++) {
			int value = g_result_img.data[(int)((float)(y - roi.y)*(float)(ratio_H_netroi)) * g_result_img.cols + (int)((float)(x - roi.x)*ratio_W_netroi)];
			if (value > m_stInfoBubble.m_stParaBubble.prob_thres){
				g_view_img.at<cv::Vec3b>(y, x)[0] = GetBValue(RainbowColorTable[value]);
				g_view_img.at<cv::Vec3b>(y, x)[1] = GetGValue(RainbowColorTable[value]);
				g_view_img.at<cv::Vec3b>(y, x)[2] = GetRValue(RainbowColorTable[value]);
				found_bad_pixel = true;
			}
		}
	}


	cv::Size size = { input2.cols, input2.rows };
	// matching result on input2 with output setting on this tool
	cv::resize(g_view_img, sample.m_BubbleResult.m_pProbImage, size);
#endif
	sample.m_BubbleResult.m_bResult = bResult;
	Log("Process End");
	return TRUE;
}

BOOL CStepBubble::Load(INFO_INSPECTION* pstInspection)
{
	BOOL bResult = FALSE;
	if (pstInspection)
	{
		bResult = SetInformation(&pstInspection->m_stBubble);
	}
	else
	{
		// Default setting
		m_stInfoBubble.m_pstStepStrobe[0].m_eStrobeType = TYPE_STROBE_COXIAL;
		m_stInfoBubble.m_pstStepStrobe[0].m_nStrobeBrightness = 15;
		m_stInfoBubble.m_pstStepStrobe[1].m_eStrobeType = TYPE_STROBE_OFF;
		m_stInfoBubble.m_pstStepStrobe[1].m_nStrobeBrightness = 0;


		// Roi
		m_stInfoBubble.m_stRoi.m_eTrackerType = TYPE_TRACKER_RECT;
		m_stInfoBubble.m_stRoi.m_rtRoi.left = ROI_S;
		m_stInfoBubble.m_stRoi.m_rtRoi.top = ROI_S;
		m_stInfoBubble.m_stRoi.m_rtRoi.right = ROI_E;
		m_stInfoBubble.m_stRoi.m_rtRoi.bottom = ROI_E;

		bResult = TRUE;
	}

	return bResult;
}

BOOL CStepBubble::Get(INFO_INSPECTION* pstInspection)
{
	if (NULL == pstInspection)
		return FALSE;

	pstInspection->m_stBubble = m_stInfoBubble;
	return TRUE;
}

BOOL CStepBubble::Set(const INFO_INSPECTION* pstInspection)
{
	if (NULL == pstInspection)
		return FALSE;

	SetInformation(&pstInspection->m_stBubble);
	return TRUE;
}

const INFO_INSPECTION_BUBBLE* CStepBubble::GetInformation()
{
	return &m_stInfoBubble;
}

BOOL CStepBubble::SetInformation(const INFO_INSPECTION_BUBBLE* pInfoSize)
{
	if (NULL == pInfoSize)
		return FALSE;

	memcpy(&m_stInfoBubble, pInfoSize, sizeof(INFO_INSPECTION_BUBBLE));
	return TRUE;
}