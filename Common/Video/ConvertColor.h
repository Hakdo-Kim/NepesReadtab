/**************************************************************************************************
*	Project : Eagle Eye Project (Gigabit Ethernet Camera)
*
*
*	
*	File Name : ConvertColor.h 
*	author : hkkim
**************************************************************************************************/
#ifndef __CONVERTCOLOR_H__
#define __CONVERTCOLOR_H__

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

/**************************************************************************************************
*   ConvertColor : Display 하기 위해 입력 영상을 RGB로 변환 한다  
*
*   @param      iPixelFormat, [in] Pixel Format
*   @param      pSrc, [in] 변환할 Source Image (OpenCV의 IplImage*)
*   @param      pDest, [inout] 변환 결과를 넘겨줄 Destination Image  
*   @param      pTemp, [in] 10 bit 이상일 경우 사용할 destination 
*   @param      nWidth, [in] Image Width
*	@param		nHeight, [in] Image Height  
*
*   @return     Error Value
**************************************************************************************************/
void ConvertColor(unsigned int iPixelFormat, IplImage* pSrc, IplImage* pDest, IplImage* pTemp, unsigned int nWidth, unsigned int nHeight);

#endif	//__CONVERTCOLOR_H__