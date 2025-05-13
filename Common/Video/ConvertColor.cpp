/******************************************************************************
*	Project : Eagle Eye Project (Gigabit Ethernet Camera)
*
*
*	
*	File Name : ConvertColor.cpp 
*	author : hkkim
******************************************************************************/
 
#include "stdafx.h"
#include "ConvertColor.h"
#include "inc/EECvtColorEx.h"
#include "inc/PixelFormat.h"


#if defined(_WIN64)
	#pragma comment(lib, "EECvtColorx64.lib")
#else
	#pragma comment(lib, "EECvtColor.lib")
#endif


/**************************************************************************************************
*   Shift10BitMode : Test 용 -> 10 bit 를 8bit로 shift  
*
*   @param      pImage, [in] Image Pointer
*   @param      nWidth, [in] Image Width
*	@param		nHeight, [in] Image Height  
*
*   @return     Error Value
**************************************************************************************************/
void Shift10BitMode(unsigned char* pImage, unsigned char* pDest, unsigned int nWidth, unsigned int nHeight)
{
	unsigned int i,j,k;
	unsigned int nByteWidth;
	unsigned int *piDest;

	nByteWidth = nWidth * 5 / 4 ;
	piDest = (unsigned int *)pDest;
	nWidth >>= 2;

	for(i=0; i<nHeight; i++)
	{
		for(j=0, k=0; j<nWidth; j++, k+=5)
		{
			 piDest[j] = (pImage[k+3]<<24) +  (pImage[k+2]<<16) +  (pImage[k+1]<<8) +  (pImage[k]);
		}

		piDest += nWidth;
		pImage += nByteWidth;
	}
}

/**************************************************************************************************
*   Shift10BitMode : Test 용 -> 12 bit 를 8bit로 shift  
*
*   @param      pImage, [in] Image Pointer
*   @param      nWidth, [in] Image Width
*	@param		nHeight, [in] Image Height  
*
*   @return     Error Value
**************************************************************************************************/
//void Shift12BitMode(unsigned char* pImage, unsigned char* pDest, unsigned int nWidth, unsigned int nHeight)
//{
//	unsigned int	i,j,k;
//	unsigned int	nByteWidth;
//	unsigned short *psDest;
//
//	nByteWidth = nWidth * 3 / 2 ;
//	psDest = (unsigned short *)pDest;
//	nWidth >>= 1;
//	for(i=0; i<nHeight; i++)
//	{
//		for(j=0, k = 0; j<nWidth; j++,k+=3)
//		{
//			psDest[j] =  (pImage[k+1]<<8) +  (pImage[k]);
//			//psDest[j] =  (pImage[k+1]) +  (pImage[k]<<8);
//		}
//		psDest += nWidth;
//		pImage += nByteWidth;
//	}
//}


void Shift12BitMode(unsigned char* pImage, unsigned char* pDest, unsigned int nWidth, unsigned int nHeight)
{
	unsigned int	i,j,k;
	unsigned int	nByteWidth;
	unsigned short *psDest;

	nByteWidth = nWidth * 3 / 2 ;
	psDest = (unsigned short *)pDest;

    //unsigned short temp1;
    //unsigned short temp2;
    //unsigned short temp3;

	nWidth >>= 1;

	for(i=0; i<nHeight; i++)
	{
		for(j=0, k = 0; j<nWidth; j++,k+=3)
		{
#if 1		
            psDest[j] =  (pImage[k+1]<<8) +  (pImage[k]); // origin
#else          
			//temp1 = pImage[k];
			//temp2 = pImage[k+1];
			//temp3 = pImage[k+2];

			temp1 = (pImage[k]<<2) + ((pImage[k+2]>>6)&0x03);
			temp2 = (pImage[k+1]<<2) + ((pImage[k+2]>>2)&0x03);
			//temp3 = pImage[k+2];
            //psDest[j] =  (temp2<<8)+(temp1);
			psDest[j] = (ImageMappingTable[temp2]<<8) + ImageMappingTable[temp1];
#endif
		}
		psDest += nWidth;
		pImage += nByteWidth;
	}
}



//#define	CONVTIMECHECK

/**************************************************************************************************
*   ConvertColor : Display 하기 위해 입력 영상을 RGB로 변환 한다  
*
*   @param      iPixelFormat, [in] Pixel Format
*   @param      pSrc, [in] 변환할 Source Image (OpenCV의 IplImage*)
*   @param      pDest, [inout] 변환 결과를 넘겨줄 Destination Image   
*   @param      pTemp, [inout] 10bit 이상일 경우 사용하는 Destination Image   
*   @param      nWidth, [in] Image Width
*	@param		nHeight, [in] Image Height  
*
*   @return     Error Value
**************************************************************************************************/
void ConvertColor(unsigned int iPixelFormat, IplImage* pSrc, IplImage* pDest, IplImage* pTemp, unsigned int nWidth, unsigned int nHeight)
{
#ifdef CONVTIMECHECK
	LARGE_INTEGER start, finish;
	LARGE_INTEGER ticksPerSec;
	double timeSec;

	if (!QueryPerformanceFrequency(&ticksPerSec))
	{ 
		return;
	} 
	QueryPerformanceCounter(&start);
#endif
	switch(iPixelFormat)
    {
		case GVSP_PIX_MONO8:
			cvCvtColor(pSrc, pDest, CV_GRAY2RGB);
			break;

		case GVSP_PIX_MONO10_PACKED:
			Shift10BitMode((unsigned char*)pSrc->imageData, (unsigned char*)pTemp->imageData,nWidth, nHeight);
			cvCvtColor(pTemp, pDest, CV_GRAY2RGB);
			break;

		case GVSP_PIX_MONO12_PACKED:
			Shift12BitMode((unsigned char*)pSrc->imageData, (unsigned char*)pTemp->imageData, nWidth, nHeight);
			cvCvtColor(pTemp, pDest, CV_GRAY2RGB);
			break;

		case BAYERGR8:
			cvCvtColor(pSrc, pDest, CV_BayerGR2RGB);  // interpolation  
			break;
		
		case BAYERRG8:
			cvCvtColor(pSrc, pDest, CV_BayerRG2RGB);  // interpolation  
			break;


		case GVSP_PIX_BAYERGR8:
            cvCvtColor( pSrc, pDest, CV_BayerGR2RGB);  // interpolation  
			break;

		case GVSP_PIX_BAYERGB8:
            cvCvtColor( pSrc, pDest, CV_BayerGB2RGB);  // interpolation					
            break;

		case GVSP_PIX_BAYERRG8:
            cvCvtColor( pSrc, pDest, CV_BayerRG2RGB);  // interpolation  
			break;

		case GVSP_PIX_BAYERBG8:
            cvCvtColor( pSrc, pDest, CV_BayerBG2RGB);  // interpolation					
            break;

		case GVSP_PIX_BAYERRG10_PACKED:
			Shift10BitMode((unsigned char*)pSrc->imageData, (unsigned char*)pTemp->imageData, nWidth, nHeight);
			cvCvtColor( pTemp, pDest, CV_BayerRG2RGB);  // interpolation 
			break;

		case GVSP_PIX_BAYERGR10_PACKED:
			Shift10BitMode((unsigned char*)pSrc->imageData, (unsigned char*)pTemp->imageData, nWidth, nHeight);
			cvCvtColor( pTemp, pDest, CV_BayerGR2RGB);  // interpolation 
			break;

		case GVSP_PIX_BAYERBG10_PACKED:
			Shift10BitMode((unsigned char*)pSrc->imageData, (unsigned char*)pTemp->imageData, nWidth, nHeight);
			cvCvtColor( pTemp, pDest, CV_BayerBG2RGB);  // interpolation 
			break;

		case GVSP_PIX_BAYERGB10_PACKED:
			Shift10BitMode((unsigned char*)pSrc->imageData, (unsigned char*)pTemp->imageData, nWidth, nHeight);
			cvCvtColor( pTemp, pDest, CV_BayerGB2RGB);  // interpolation 
			
			break;

		case GVSP_PIX_BAYERGR12_PACKED:
			Shift12BitMode((unsigned char*)pSrc->imageData, (unsigned char*)pTemp->imageData, nWidth, nHeight);
			//Shift12BitMode((unsigned char*)pSrc, (unsigned char*)pTemp, nWidth, nHeight);
			cvCvtColor( pTemp, pDest, CV_BayerGR2RGB);  // interpolation 
			break;

		case GVSP_PIX_BAYERGB12_PACKED:
			Shift12BitMode((unsigned char*)pSrc->imageData, (unsigned char*)pTemp->imageData, nWidth, nHeight);
			cvCvtColor( pTemp, pDest, CV_BayerGB2RGB);  // interpolation 
			break;

		case GVSP_PIX_BAYERRG12_PACKED:
			Shift12BitMode((unsigned char*)pSrc->imageData, (unsigned char*)pTemp->imageData, nWidth, nHeight);
			cvCvtColor( pTemp, pDest, CV_BayerRG2RGB);  // interpolation 
			break;

		case GVSP_PIX_BAYERBG12_PACKED:
			Shift12BitMode((unsigned char*)pSrc->imageData, (unsigned char*)pTemp->imageData, nWidth, nHeight);
			cvCvtColor( pTemp, pDest, CV_BayerBG2RGB);  // interpolation 
			break;

		case GVSP_PIX_YUV422_YUYV_PACKED:
			ConvYUYVtoRGB((unsigned char*)pSrc->imageData, (unsigned char*)pDest->imageData, nWidth, nHeight);				
			break;

		case GVSP_PIX_YUV422_PACKED:
			//TRACE("YUV422 Packed_start\n");
			ConvUYVYtoRGB((unsigned char*)pSrc->imageData, (unsigned char*)pDest->imageData, nWidth, nHeight);
			//TRACE("YUV422 Packed_end\n");
			break;

		//case GVSP_PIX_RGB565:
		//	cvCvtColor( pSrc, pDest, CV_BGR5652BGR);   
		//	break;
		//
		//case GVSP_PIX_BGR565:
		//	cvCvtColor( pSrc, pDest, CV_BGR5652RGB);  
		//	break;

		case GVSP_PIX_RGB8_PACKED:
			//cvCopyImage( pSrc, pDest );
			break;
	
		case GVSP_PIX_BGR8_PACKED:
			cvCvtColor( pSrc, pDest, CV_BGR2RGB);
			break;
       
        default:
            break;
    }
#ifdef CONVTIMECHECK
	QueryPerformanceCounter(&finish);
	// 경과시간 구하기 (초단위)
	timeSec = (finish.QuadPart - start.QuadPart) / (double)ticksPerSec.QuadPart;
	TRACE("Display : %.6f\n", timeSec);
#endif
}