#pragma once
#include "Step.h"

#ifdef NAVIAI_SUPPORT
#include "NAVIAIMars.h"
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <Windows.h>

class CNAVIAIMarsTester
{
public:
	enum{ MAX_RANGE_VALUE = 256 };
	static void Init();

	CNAVIAIMarsTester();
	~CNAVIAIMarsTester();

	BOOL	Create(const char* license_file_path);
	void	Destroy();

	BOOL	Open(const char* trained_file_path);
	void	Close();

	BOOL	ProcessNShowResult(cv::Mat& input, char* title_name, int x, int y, int w, int h);

	void	threshold_callback();

	NAVIAIError GetLastError() { return last_error; }
private:

	INAVIAIMars *m_pNAVIAIMars;
	NAVIAINetInfo m_net_info;

	int			m_level, m_blobsize;
	cv::Mat		m_raw_result_img;
	cv::Mat		m_result_img;

	cv::Mat		m_input_img;
	cv::Mat		m_view_img;
	std::string	m_cur_title_name;

	static COLORREF	RainbowColorTables[MAX_RANGE_VALUE];

	NAVIAIError last_error;
};
#endif

