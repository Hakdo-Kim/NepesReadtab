#pragma once
#include <opencv2/core/core.hpp>
#include <direct.h>
#include <stdlib.h>
#include <stdio.h>
#include <chrono>
#include <ctime>
#include <string>
#include <cstring>

void SetTrainFileName(const char* filename);

void makeColorTable(int range, COLORREF* pColorTable);

//crop centor of image
bool preprocessImage(const char* filepath, cv::Mat& input);

void remove_small_blobs(cv::Mat &binary, cv::Mat &result, int min_blob_size);

bool checkBlobSize(cv::Mat &binary, cv::Mat &result, vector<float> vecMaxSize, int maxValue, int processStep, INFO_LOGFUNC stLogFunc, TYPE_CAMERAPOS m_eCameraPos);

float calcSize(int x1, int y1, int x2, int y2);

void saveLogPicture(const char* processStepName, const cv::Mat& input);
// Version 1.3.8.1 Image Log Format (jpg)
void saveLogPicture(const char* processStepName, const cv::Mat& input, bool isCompress);

void Eliminate(char *str);

void currentTime(char*);