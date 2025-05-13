#pragma once
#include "stdafx.h"
#include "NAVIAIMarsTester.h"
#include "util_functions.h"

#include "Util\Util.h"

#ifdef NAVIAI_SUPPORT
inline int	Normalize(float input, float range_min, float range_max, int max_value)
{
	return int((input * max_value) / (range_max - range_min));
}


void threshold_callback_wrap(int value, void* instance)
{
	CNAVIAIMarsTester* pNAVIAIMarsTester = (CNAVIAIMarsTester*)instance;
	pNAVIAIMarsTester->threshold_callback();
}


COLORREF	CNAVIAIMarsTester::RainbowColorTables[CNAVIAIMarsTester::MAX_RANGE_VALUE];

void CNAVIAIMarsTester::Init()
{
	makeColorTable_u(MAX_RANGE_VALUE, RainbowColorTables);
}


CNAVIAIMarsTester::CNAVIAIMarsTester()
{
	m_pNAVIAIMars = NULL;
	memset(&m_net_info, 0, sizeof(m_net_info));
	last_error = NAVIAIError_Success;
}


CNAVIAIMarsTester::~CNAVIAIMarsTester()
{
	Destroy();
}


BOOL	CNAVIAIMarsTester::Create(const char* license_file_path)
{
	if (m_pNAVIAIMars != NULL) return TRUE;

	m_pNAVIAIMars = CreateNAVIAIMars();
	NAVIAIError result = m_pNAVIAIMars->Init(NAVIAIBrewMode_GPU_CUDA, 0, license_file_path);
	if (NAVIAIError_Success != result){
		last_error = result;
		Destroy();
		return FALSE;
	}

	return TRUE;
}
void	CNAVIAIMarsTester::Destroy()
{
	Close();
	if (m_pNAVIAIMars)
	{
		m_pNAVIAIMars->DestroySelf();
		m_pNAVIAIMars = NULL;
	}
}

BOOL	CNAVIAIMarsTester::Open(const char* trained_file_path)
{
	if (m_pNAVIAIMars == NULL) return FALSE;

	Close();
	NAVIAIError result = m_pNAVIAIMars->Open(trained_file_path, &m_net_info);
	if (NAVIAIError_Success != result){
		last_error = result;
		return FALSE;
	}

	CUtil::PrintDebugString(_T("Train File[%s]\n Info Input Resize Mode[%s] [%d:%d:%d] Class Count[%d] \n"),
		trained_file_path, (m_net_info.mode == NAVIAIResizeMode_IMAGE) ? "IMAGE" : "NETWORK",
		m_net_info.width, m_net_info.height, m_net_info.channel, m_net_info.class_cnt);
	if (m_net_info.threshold){
		for (int i = 0; i < m_net_info.class_cnt; i++){
			CUtil::PrintDebugString(_T("Threshold [%d] [%f - %f] \n"), i, m_net_info.threshold[i].min, m_net_info.threshold[i].max);
		}
	}

	return TRUE;
}


void	CNAVIAIMarsTester::Close()
{
	if (m_pNAVIAIMars == NULL) return;
	m_pNAVIAIMars->Close();
	memset(&m_net_info, 0, sizeof(m_net_info));
}

BOOL	CNAVIAIMarsTester::ProcessNShowResult(cv::Mat& input, char* title_name, int x, int y, int w, int h)
{
	if (m_pNAVIAIMars == NULL || m_net_info.version == 0) return FALSE;

	int nLayerCnt = 0;
	float* output;
	NAVIAIError result = m_pNAVIAIMars->Process(m_net_info.mode, input.channels(), input.cols, input.rows, (int)input.step[0], NAVIAIInputType_8U, input.data, &nLayerCnt, &output);
	if (NAVIAIError_Success != result){
		last_error = result;
		return FALSE;
	}

	//Show result
	float* background = output;
	float* defect = output + m_net_info.height * m_net_info.width;
	m_raw_result_img = cv::Mat::zeros(m_net_info.height, m_net_info.width, CV_8UC1);

	int pos;
	for (int i = 0; i < m_net_info.height; i++) {
		for (int j = 0; j < m_net_info.width; j++) {
			pos = i * m_net_info.width + j;
			if (defect[pos] > background[pos]){
				m_raw_result_img.data[pos] = Normalize((defect[pos] - background[pos]), m_net_info.threshold[1].min, m_net_info.threshold[1].max, MAX_RANGE_VALUE);
			}
		}
	}

	cv::Size network_size(m_net_info.width, m_net_info.height);
	cv::resize(input, m_input_img, network_size);
	if (input.channels() == 1) cv::cvtColor(m_input_img, m_input_img, CV_GRAY2BGR);

	m_cur_title_name = title_name;

	cv::namedWindow(m_cur_title_name.c_str(), CV_WINDOW_NORMAL);
	cv::resizeWindow(m_cur_title_name.c_str(), w, h);
	cv::moveWindow(m_cur_title_name.c_str(), x, y);

	m_level = m_blobsize = 0;
	cv::createTrackbar("Level ", m_cur_title_name.c_str(), &m_level, MAX_RANGE_VALUE, threshold_callback_wrap, this);
	cv::createTrackbar("Blob(10x)", m_cur_title_name.c_str(), &m_blobsize, 100, threshold_callback_wrap, this);

	threshold_callback();

	return TRUE;
}


void CNAVIAIMarsTester::threshold_callback()
{
	CUtil::PrintDebugString(_T("%s : change level value [%d] blob size [%d] \n"), m_cur_title_name.c_str(), m_level, m_blobsize);

	//find blob
	std::vector<std::vector<cv::Point> > contours;
	std::vector<cv::Point2f>center(contours.size());
	std::vector<float>radius(contours.size());

	m_raw_result_img.copyTo(m_result_img);
	cv::Mat threshold_output;
	threshold(m_result_img, threshold_output, m_level, 1, cv::THRESH_BINARY);

	std::vector<BLOB_INFO> blobs;
	get_blobs_u(threshold_output, blobs);

	//filter small blobs
	if (m_blobsize != 0){
		for (int i = 0; i < blobs.size(); i++){
			if (m_blobsize * 10 > blobs[i].blob.size()){
				cv::rectangle(m_result_img, blobs[i].rect, RGB(0, 0, 0), -1);
			}
		}
	}

	m_input_img.copyTo(m_view_img);
	bool found_bad_pixel = false;
	for (int i = 0; i < m_result_img.rows; i++) {
		for (int j = 0; j < m_result_img.cols; j++) {
			int value = m_result_img.data[i * m_result_img.cols + j];

			if (value > m_level){
				m_view_img.at<cv::Vec3b>(i, j)[0] = GetBValue(RainbowColorTables[value]);
				m_view_img.at<cv::Vec3b>(i, j)[1] = GetGValue(RainbowColorTables[value]);
				m_view_img.at<cv::Vec3b>(i, j)[2] = GetRValue(RainbowColorTables[value]);

				found_bad_pixel = true;
			}
		}
	}


	for (int i = 0; i < blobs.size(); i++){
		if (m_blobsize * 10 < blobs[i].blob.size()){
			//cv::rectangle(m_view_img, blobs[i].rect, RGB(0, 0, 255), 1);
		}
	}

	cv::imshow(m_cur_title_name.c_str(), m_view_img);
}
#endif
