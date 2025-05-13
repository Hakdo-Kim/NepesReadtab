#include "stdafx.h"
#include <math.h>
#include "util_functions.h"
#include <Windows.h>

using namespace cv;

void makeColorTable_u(int range, COLORREF* pColorTable)
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

bool preprocessImage_u(const char* filepath, cv::Mat& crop_image)
{
	cv::Mat input = cv::imread(filepath, CV_LOAD_IMAGE_GRAYSCALE);
	if (input.data == NULL){
		printf("Can not input [%s]\n", filepath);
		return false;
	}

	crop_image = input;
	return true;
}


void get_blobs_u(cv::Mat &binary, std::vector<BLOB_INFO>& blob_info_list)
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

			BLOB_INFO blob_info;
			blob_info.label = label_count;
			blob_info.rect = rect;
			blob_info.blob = blob;
			blob_info_list.push_back(blob_info);

			label_count++;
		}
	}
}


void remove_small_blobs_u(cv::Mat &binary, cv::Mat &result, int min_blob_size)
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
				cv::rectangle(result, rect, RGB(0, 0, 0), -1);
			}

			label_count++;
		}
	}
}