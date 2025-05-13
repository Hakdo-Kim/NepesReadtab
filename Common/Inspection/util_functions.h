#pragma once

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>


void makeColorTable_u(int range, COLORREF* pColorTable);

//crop centor of image
bool preprocessImage_u(const char* filepath, cv::Mat& input);

typedef struct
{
	int			label;
	cv::Rect	rect;
	std::vector <cv::Point2i> blob;
}BLOB_INFO;

void get_blobs_u(cv::Mat &binary, std::vector<BLOB_INFO>& blobs);

