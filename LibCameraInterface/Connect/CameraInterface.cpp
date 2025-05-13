#include "StdAfx.h"

#include "CameraInterface.h"

#include "Connect/ConnectGigE.h"
#ifdef USE_BASLER_CAMERA
#include "ConnectBasler.h"
#endif 

#include "Util/Util.h"



HCAMERA InitCamera(TYPE_NETWORK eNetwork)
{
	CConnect* pConnect = NULL;

#ifdef USE_BASLER_CAMERA
	if (TYPE_NETWORK_BASLER == eNetwork)
		pConnect = new CConnectBasler();
#endif

#ifdef USE_GIGE_CAMERA
	if (TYPE_NETWORK_GIGE == eNetwork)
		pConnect = new CConnectGigE();
#endif

	if (NULL == pConnect)
		return NULL;

	BOOL bResult = pConnect->Open(eNetwork);
	if (FALSE == bResult)
	{
		DeinitCamera((HCAMERA)pConnect);
		return NULL;
	}

	return (HCAMERA) pConnect;
}

void DeinitCamera(HCAMERA hCamera)
{
	if (NULL == hCamera)
		return;

	CConnect* pConnect = (CConnect*)hCamera;
	pConnect->Close();
	delete pConnect;
}

const TYPE_NETWORK GetNetworkType(HCAMERA hCamera)
{
	if (NULL == hCamera)
		return TYPE_NETWORK_NONE;

	CConnect* pConnect = (CConnect*)hCamera;
	return pConnect->GetNetworkType();
}
BOOL IsConnected(HCAMERA hCamera)
{
	if (NULL == hCamera)
		return FALSE;

	CConnect* pConnect = (CConnect*)hCamera;
	return pConnect->IsConnected();
}

int GetDeviceCount(HCAMERA hCamera)
{
	if (NULL == hCamera)
		return 0;

	CConnect* pConnect = (CConnect*)hCamera;
	return pConnect->GetDeviceCount();
}
int GetDeviceIndex(HCAMERA hCamera, const INFO_CONNECT_DEV* pDev)
{
	if (NULL == hCamera)
		return 0;

	CConnect* pConnect = (CConnect*)hCamera;
	return pConnect->GetDeviceIndex(pDev);
}
int GetDeviceID(HCAMERA hCamera, const TCHAR* pName)
{
	if (NULL == hCamera || NULL == pName)
		return -1;

	CConnect* pConnect = (CConnect*)hCamera;
	return pConnect->GetDeviceID(pName);

}

BOOL GetDeviceInfo(HCAMERA hCamera, int nIdx, INFO_CONNECT_DEV* pstDevice)
{
	if (NULL == hCamera)
		return FALSE;

	CConnect* pConnect = (CConnect*)hCamera;
	return pConnect->GetDeviceInfo(nIdx, pstDevice);
}

BOOL ResearchDeviceInfo(HCAMERA hCamera)
{
	if (NULL == hCamera)
		return FALSE;

	CConnect* pConnect = (CConnect*)hCamera;
	return pConnect->ResearchDeviceInfo();
}

// Device Information
BOOL GetFrameInfo(HCAMERA hCamera, const int nIdx, INFO_FRAME* pstFrame)
{
	if (NULL == hCamera)
		return FALSE;

	CConnect* pConnect = (CConnect*)hCamera;
	return pConnect->GetFrameInfo(nIdx, pstFrame);
}
BOOL SetEventFunc(HCAMERA hCamera, const int nIdx, FuncAcquisitionEvent pFunc, void* pUserData)
{
	if (NULL == hCamera)
		return FALSE;

	CConnect* pConnect = (CConnect*)hCamera;
	return pConnect->SetEventFunc(nIdx, pFunc, pUserData);
}

BOOL StartCamera(HCAMERA hCamera, const int nIdx, BOOL bSingle)
{
	if (NULL == hCamera)
		return FALSE;

	CConnect* pConnect = (CConnect*)hCamera;
	return pConnect->Start(nIdx, bSingle);
}

void StopCamera(HCAMERA hCamera, const int nIdx)
{
	if (NULL == hCamera)
		return;

	CConnect* pConnect = (CConnect*)hCamera;
	return pConnect->Stop(nIdx);
}

BOOL IsOpenCamera(HCAMERA hCamera, const int nIdx)
{
	if (NULL == hCamera)
		return FALSE;

	CConnect* pConnect = (CConnect*)hCamera;
	return pConnect->IsOpen(nIdx);
}
BOOL OpenCamera(HCAMERA hCamera, const int nIdx)
{
	if (NULL == hCamera)
		return FALSE;

	CConnect* pConnect = (CConnect*)hCamera;
	return pConnect->Open(nIdx);
}
void CloseCamera(HCAMERA hCamera, const int nIdx)
{
	if (NULL == hCamera)
		return;

	CConnect* pConnect = (CConnect*)hCamera;
	return pConnect->Close(nIdx);
}

// Command Function
BOOL SetRegister(HCAMERA hCamera, const int nIdx, const DWORD dwAddress, const DWORD dwValue, DWORD dwReserved)
{
	if (NULL == hCamera)
		return FALSE;

	CConnect* pConnect = (CConnect*)hCamera;
	return pConnect->SetRegister(nIdx, dwAddress, dwValue, dwReserved);
}
BOOL GetRegister(HCAMERA hCamera, const int nIdx, const DWORD dwAddress, DWORD* pdwValue, DWORD dwReserved)
{
	if (NULL == hCamera)
		return FALSE;

	CConnect* pConnect = (CConnect*)hCamera;
	return pConnect->GetRegister(nIdx, dwAddress, pdwValue, dwReserved);
}



//
BOOL SetGain(HCAMERA hCamera, const int nIdx, const int nGainType, const int nGainValue)
{
	if (NULL == hCamera)
		return FALSE;

	CConnect* pConnect = (CConnect*)hCamera;
	BOOL bResult = pConnect->SetGain(nIdx, nGainType, nGainValue);

	return bResult;
}
BOOL GetGain(HCAMERA hCamera, const int nIdx, const int nGainType, int* pnGainValue)
{
	if (NULL == hCamera)
		return FALSE;

	CConnect* pConnect = (CConnect*)hCamera;
	BOOL bResult = pConnect->GetGain(nIdx, nGainType, pnGainValue);

	return bResult;
}

BOOL SetEnableFrameRate(HCAMERA hCamera, const int nIdx, const unsigned int nEnable)
{
	if (NULL == hCamera)
		return FALSE;

	CConnect* pConnect = (CConnect*)hCamera;
	BOOL bResult = pConnect->SetEnableFrameRate(nIdx, nEnable);

	return bResult;
}
BOOL GetEnableFrameRate(HCAMERA hCamera, const int nIdx, unsigned int* pnEnable)
{
	if (NULL == hCamera)
		return FALSE;

	CConnect* pConnect = (CConnect*)hCamera;
	BOOL bResult = pConnect->GetEnableFrameRate(nIdx, pnEnable);

	return bResult;
}


BOOL SetFrameRate(HCAMERA hCamera, const int nIdx, const unsigned int nFrameRate)
{
	if (NULL == hCamera)
		return FALSE;

	CConnect* pConnect = (CConnect*)hCamera;
	BOOL bResult = pConnect->SetFrameRate(nIdx, nFrameRate);

	return bResult;
}
BOOL GetFrameRate(HCAMERA hCamera, const int nIdx, unsigned int* pnFrameRate)
{
	if (NULL == hCamera)
		return FALSE;

	CConnect* pConnect = (CConnect*)hCamera;
	BOOL bResult = pConnect->GetFrameRate(nIdx, pnFrameRate);

	return bResult;
}
BOOL GetMaxFrameRate(HCAMERA hCamera, const int nIdx, unsigned int* pnFrameRate)
{
	if (NULL == hCamera)
		return FALSE;

	CConnect* pConnect = (CConnect*)hCamera;
	BOOL bResult = pConnect->GetMaxFrameRate(nIdx, pnFrameRate);

	return bResult;
}

BOOL SetExposureTime(HCAMERA hCamera, const int nIdx, const unsigned int nSetExposureTime)
{
	if (NULL == hCamera)
		return FALSE;

	CConnect* pConnect = (CConnect*)hCamera;
	BOOL bResult = pConnect->SetExposureTime(nIdx, nSetExposureTime);

	return bResult;
}
BOOL GetExposureTime(HCAMERA hCamera, const int nIdx, unsigned int* pnSetExposureTime)
{
	if (NULL == hCamera)
		return FALSE;

	CConnect* pConnect = (CConnect*)hCamera;
	BOOL bResult = pConnect->GetExposureTime(nIdx, pnSetExposureTime);

	return bResult;
}
BOOL GetExposureMaxTime(HCAMERA hCamera, const int nIdx, unsigned int nFrameRate, unsigned int* pnExposureTime)
{
	if (NULL == hCamera)
		return FALSE;

	CConnect* pConnect = (CConnect*)hCamera;
	BOOL bResult = pConnect->GetExposureMaxTime(nIdx, nFrameRate, pnExposureTime);
	return bResult;
}
BOOL ConvertExposureTime(HCAMERA hCamera, const int nIdx, unsigned int nStep, double* pfUSec)
{
	if (NULL == hCamera)
		return FALSE;

	CConnect* pConnect = (CConnect*)hCamera;
	BOOL bResult = pConnect->ConvertExposureTime(nIdx, nStep, pfUSec);
	return bResult;
}


BOOL SetTriggerMode(HCAMERA hCamera, const int nIdx, INFO_TRIGGER_PARA stTrigger)
{
	if (NULL == hCamera)
		return FALSE;

	CConnect* pConnect = (CConnect*)hCamera;
	BOOL bResult = pConnect->SetTriggerMode(nIdx, stTrigger);

	return bResult;
}
BOOL GetTriggerMode(HCAMERA hCamera, const int nIdx, INFO_TRIGGER_PARA* pstTrigger)
{
	if (NULL == hCamera)
		return FALSE;

	CConnect* pConnect = (CConnect*)hCamera;
	BOOL bResult = pConnect->GetTriggerMode(nIdx, pstTrigger);

	return bResult;
}

BOOL SetTriggerDelay(HCAMERA hCamera, const int nIdx, int nDelay)
{
	if (NULL == hCamera)
		return FALSE;

	CConnect* pConnect = (CConnect*)hCamera;
	BOOL bResult = pConnect->SetTriggerDelay(nIdx, nDelay);

	return bResult;
}

BOOL SaveUserset(HCAMERA hCamera, const int nIdx, unsigned int nNumber)
{
	if (NULL == hCamera)
		return FALSE;

	CConnect* pConnect = (CConnect*)hCamera;
	BOOL bResult = pConnect->SaveUserset(nIdx, nNumber);

	return bResult;
}
BOOL LoadUserset(HCAMERA hCamera, const int nIdx, unsigned int nNumber)
{
	if (NULL == hCamera)
		return FALSE;

	CConnect* pConnect = (CConnect*)hCamera;
	BOOL bResult = pConnect->LoadUserset(nIdx, nNumber);

	return bResult;
}

BOOL SetStrobeMode(HCAMERA hCamera, const int nIdx, INFO_STROBE_PARA stStrobe)
{
	if (NULL == hCamera)
		return FALSE;

	CConnect* pConnect = (CConnect*)hCamera;
	BOOL bResult = pConnect->SetStrobeMode(nIdx, stStrobe);

	return bResult;
}
BOOL GetStrobeMode(HCAMERA hCamera, const int nIdx, INFO_STROBE_PARA* pstStrobe)
{
	if (NULL == hCamera)
		return FALSE;

	CConnect* pConnect = (CConnect*)hCamera;
	BOOL bResult = pConnect->GetStrobeMode(nIdx, pstStrobe);

	return bResult;
}

BOOL SetFlipMode(HCAMERA hCamera, const int nIdx, unsigned short nMode)
{
	if (NULL == hCamera)
		return FALSE;

	CConnect* pConnect = (CConnect*)hCamera;
	BOOL bResult = pConnect->SetFlipMode(nIdx, nMode);

	return bResult;
}
BOOL GetFlipMode(HCAMERA hCamera, const int nIdx, unsigned short* pnMode)
{
	if (NULL == hCamera)
		return FALSE;

	CConnect* pConnect = (CConnect*)hCamera;
	BOOL bResult = pConnect->GetFlipMode(nIdx, pnMode);

	return bResult;
}

BOOL SetROI(HCAMERA hCamera, const int nIdx, INFO_ROI_PARA stROI)
{
	if (NULL == hCamera)
		return FALSE;

	CConnect* pConnect = (CConnect*)hCamera;
	BOOL bResult = pConnect->SetROI(nIdx, stROI);

	return bResult;
}
BOOL GetROI(HCAMERA hCamera, const int nIdx, INFO_ROI_PARA* pstROI)
{
	if (NULL == hCamera)
		return FALSE;

	CConnect* pConnect = (CConnect*)hCamera;
	BOOL bResult = pConnect->GetROI(nIdx, pstROI);

	return bResult;
}

BOOL SetUsersetStartNo(HCAMERA hCamera, const int nIdx, unsigned char nUsersetStartNo)
{
	if (NULL == hCamera)
		return FALSE;

	CConnect* pConnect = (CConnect*)hCamera;
	BOOL bResult = pConnect->SetUsersetStartNo(nIdx, nUsersetStartNo);

	return bResult;
}
BOOL GetUsersetStartNo(HCAMERA hCamera, const int nIdx, unsigned char* pnUsersetStartNo)
{
	if (NULL == hCamera)
		return FALSE;

	CConnect* pConnect = (CConnect*)hCamera;
	BOOL bResult = pConnect->GetUsersetStartNo(nIdx, pnUsersetStartNo);

	return bResult;
}

BOOL SetDataBits(HCAMERA hCamera, const int nIdx, unsigned short nDataBit)
{
	if (NULL == hCamera)
		return FALSE;

	CConnect* pConnect = (CConnect*)hCamera;
	BOOL bResult = pConnect->SetDataBit(nIdx, nDataBit);

	return bResult;
}

BOOL GetDataBits(HCAMERA hCamera, const int nIdx, unsigned short* pnDataBit)
{
	if (NULL == hCamera)
		return FALSE;

	CConnect* pConnect = (CConnect*)hCamera;
	BOOL bResult = pConnect->GetDataBit(nIdx, pnDataBit);

	return bResult;
}

BOOL SetColorMode(HCAMERA hCamera, const int nIdx, unsigned short nColorMode)	// 0:Bayer,1:YUV
{
	if (NULL == hCamera)
		return FALSE;

	CConnect* pConnect = (CConnect*)hCamera;
	BOOL bResult = pConnect->SetColorMode(nIdx, nColorMode);

	return bResult;
}

BOOL GetColorMode(HCAMERA hCamera, const int nIdx, unsigned short* pnColorMode)
{
	if (NULL == hCamera)
		return FALSE;

	CConnect* pConnect = (CConnect*)hCamera;
	BOOL bResult = pConnect->GetColorMode(nIdx, pnColorMode);

	return bResult;
}

BOOL SetMtu(HCAMERA hCamera, const int nIdx, unsigned int nMTU)
{
	if (NULL == hCamera)
		return FALSE;

	CConnect* pConnect = (CConnect*)hCamera;
	BOOL bResult = pConnect->SetMTU(nIdx, nMTU);

	return bResult;
}

BOOL GetMtu(HCAMERA hCamera, const int nIdx, unsigned int* pnMTU)
{
	if (NULL == hCamera)
		return FALSE;

	CConnect* pConnect = (CConnect*)hCamera;
	BOOL bResult = pConnect->GetMTU(nIdx, pnMTU);

	return bResult;
}



BOOL GetDiag(HCAMERA hCamera, const int nIdx, void* pstDiag, const int nLen)
{
	if (NULL == hCamera)
		return FALSE;

	CConnect* pConnect = (CConnect*)hCamera;
	BOOL bResult = pConnect->GetDiag(nIdx, pstDiag, nLen);

	return bResult;
}

BOOL SetSWTrigger(HCAMERA hCamera, const int nIdx)
{
	if (NULL == hCamera)
		return FALSE;

	CConnect* pConnect = (CConnect*)hCamera;
	BOOL bResult = pConnect->SetSWTrigger(nIdx);

	return bResult;
}





// LUT
BOOL SetLutMode(HCAMERA hCamera, const int nIdx, unsigned short nMode)
{
	if (NULL == hCamera)
		return FALSE;

	CConnect* pConnect = (CConnect*)hCamera;
	BOOL bResult = pConnect->SetLutMode(nIdx, nMode);

	return bResult;
}

BOOL GetLutMode(HCAMERA hCamera, const int nIdx, unsigned short* pnMode)
{
	if (NULL == hCamera)
		return FALSE;

	CConnect* pConnect = (CConnect*)hCamera;
	BOOL bResult = pConnect->GetLutMode(nIdx, pnMode);

	return bResult;
}

BOOL WriteLut(HCAMERA hCamera, const int nIdx, const INFO_LUT_PARA* pLutList, const int nLen, BOOL bEeprom)
{
	if (NULL == hCamera)
		return FALSE;

	CConnect* pConnect = (CConnect*)hCamera;
	BOOL bResult = pConnect->WriteLut(nIdx, pLutList, nLen, bEeprom);

	return bResult;
}


// Effect
BOOL SetEffectNR(HCAMERA hCamera, const int nIdx, unsigned short nEffect)
{
	if (NULL == hCamera)
		return FALSE;

	CConnect* pConnect = (CConnect*)hCamera;
	BOOL bResult = pConnect->SetEffectNR(nIdx, nEffect);

	return bResult;
}
BOOL GetEffectNR(HCAMERA hCamera, const int nIdx, unsigned short* pnEffect)
{
	if (NULL == hCamera)
		return FALSE;

	CConnect* pConnect = (CConnect*)hCamera;
	BOOL bResult = pConnect->GetEffectNR(nIdx, pnEffect);

	return bResult;
}

BOOL SetEffectGC(HCAMERA hCamera, const int nIdx, unsigned short nEffect)
{
	if (NULL == hCamera)
		return FALSE;

	CConnect* pConnect = (CConnect*)hCamera;
	BOOL bResult = pConnect->SetEffectGC(nIdx, nEffect);

	return bResult;
}
BOOL GetEffectGC(HCAMERA hCamera, const int nIdx, unsigned short* pnEffect)
{
	if (NULL == hCamera)
		return FALSE;

	CConnect* pConnect = (CConnect*)hCamera;
	BOOL bResult = pConnect->GetEffectGC(nIdx, pnEffect);

	return bResult;
}

BOOL SetEffectCM(HCAMERA hCamera, const int nIdx, unsigned short nEffect)
{
	if (NULL == hCamera)
		return FALSE;

	CConnect* pConnect = (CConnect*)hCamera;
	BOOL bResult = pConnect->SetEffectCM(nIdx, nEffect);

	return bResult;
}
BOOL GetEffectCM(HCAMERA hCamera, const int nIdx, unsigned short* pnEffect)
{
	if (NULL == hCamera)
		return FALSE;

	CConnect* pConnect = (CConnect*)hCamera;
	BOOL bResult = pConnect->GetEffectCM(nIdx, pnEffect);

	return bResult;
}

BOOL SetEffectAWB(HCAMERA hCamera, const int nIdx, unsigned short nEffect)
{
	if (NULL == hCamera)
		return FALSE;

	CConnect* pConnect = (CConnect*)hCamera;
	BOOL bResult = pConnect->SetEffectAWB(nIdx, nEffect);

	return bResult;
}
BOOL GetEffectAWB(HCAMERA hCamera, const int nIdx, unsigned short* pnEffect)
{
	if (NULL == hCamera)
		return FALSE;

	CConnect* pConnect = (CConnect*)hCamera;
	BOOL bResult = pConnect->GetEffectAWB(nIdx, pnEffect);

	return bResult;
}


BOOL SetEffectSmooth(HCAMERA hCamera, const int nIdx, unsigned short nEffect)
{
	if (NULL == hCamera)
		return FALSE;

	CConnect* pConnect = (CConnect*)hCamera;
	BOOL bResult = pConnect->SetEffectSmooth(nIdx, nEffect);

	return bResult;
}
BOOL GetEffectSmooth(HCAMERA hCamera, const int nIdx, unsigned short* pnEffect)
{
	if (NULL == hCamera)
		return FALSE;

	CConnect* pConnect = (CConnect*)hCamera;
	BOOL bResult = pConnect->GetEffectSmooth(nIdx, pnEffect);

	return bResult;
}

BOOL SetEffectSharpen(HCAMERA hCamera, const int nIdx, unsigned short nEffect)
{
	if (NULL == hCamera)
		return FALSE;

	CConnect* pConnect = (CConnect*)hCamera;
	BOOL bResult = pConnect->SetEffectSharpen(nIdx, nEffect);

	return bResult;
}
BOOL GetEffectSharpen(HCAMERA hCamera, const int nIdx, unsigned short* pnEffect)
{
	if (NULL == hCamera)
		return FALSE;

	CConnect* pConnect = (CConnect*)hCamera;
	BOOL bResult = pConnect->GetEffectSharpen(nIdx, pnEffect);

	return bResult;
}

BOOL SetEffectFPN(HCAMERA hCamera, const int nIdx, unsigned short nEffect)
{
	if (NULL == hCamera)
		return FALSE;

	CConnect* pConnect = (CConnect*)hCamera;
	BOOL bResult = pConnect->SetEffectFPN(nIdx, nEffect);

	return bResult;
}
BOOL GetEffectFPN(HCAMERA hCamera, const int nIdx, unsigned short* pnEffect)
{
	if (NULL == hCamera)
		return FALSE;

	CConnect* pConnect = (CConnect*)hCamera;
	BOOL bResult = pConnect->GetEffectFPN(nIdx, pnEffect);

	return bResult;
}

BOOL SetEffectPRNU(HCAMERA hCamera, const int nIdx, unsigned short nEffect)
{
	if (NULL == hCamera)
		return FALSE;

	CConnect* pConnect = (CConnect*)hCamera;
	BOOL bResult = pConnect->SetEffectPRNU(nIdx, nEffect);

	return bResult;
}
BOOL GetEffectPRNU(HCAMERA hCamera, const int nIdx, unsigned short* pnEffect)
{
	if (NULL == hCamera)
		return FALSE;

	CConnect* pConnect = (CConnect*)hCamera;
	BOOL bResult = pConnect->GetEffectPRNU(nIdx, pnEffect);

	return bResult;
}

BOOL SetEffectDPC(HCAMERA hCamera, const int nIdx, unsigned short nEffect)
{
	if (NULL == hCamera)
		return FALSE;

	CConnect* pConnect = (CConnect*)hCamera;
	BOOL bResult = pConnect->SetEffectDPC(nIdx, nEffect);

	return bResult;
}
BOOL GetEffectDPC(HCAMERA hCamera, const int nIdx, unsigned short* pnEffect)
{
	if (NULL == hCamera)
		return FALSE;

	CConnect* pConnect = (CConnect*)hCamera;
	BOOL bResult = pConnect->GetEffectDPC(nIdx, pnEffect);

	return bResult;
}

BOOL SetColorGain(HCAMERA hCamera, const int nIdx, const int nGainType, int nGainVal)
{
	if (NULL == hCamera)
		return FALSE;

	CConnect* pConnect = (CConnect*)hCamera;
	BOOL bResult = pConnect->SetColorGain(nIdx, nGainType, nGainVal);

	return bResult;
}
BOOL GetColorGain(HCAMERA hCamera, const int nIdx, const int nGainType, int* pnGainVal)
{
	if (NULL == hCamera)
		return FALSE;

	CConnect* pConnect = (CConnect*)hCamera;
	BOOL bResult = pConnect->GetColorGain(nIdx, nGainType, pnGainVal);

	return bResult;
}


// Some Camera Model...
BOOL CalculateMaxFrameRate(const INFO_DEFDEV* pstDefDev, const int nWidth, const int nHeight, DWORD* pdwMaxFps)
{
	if (NULL == pstDefDev || NULL==pdwMaxFps)
		return FALSE;

	int nFps = -1;

	if (TYPE_NETWORK_GIGE == pstDefDev->m_eNetwork)
	{
	}
	else if (TYPE_NETWORK_BASLER == pstDefDev->m_eNetwork)
	{
	}
	else if (TYPE_NETWORK_ETHERNET == pstDefDev->m_eNetwork)
	{
	}
	else if (TYPE_NETWORK_USB == pstDefDev->m_eNetwork)
	{
		DWORD dwSensorType = USBSENSOR_UNKNOWN;

		if (CUtil::StringICompare((LPTSTR)pstDefDev->m_szName, _T("LPMVC-U03M")))
			dwSensorType = USBSENSOR_VGA_MONO_CMOSIS;
		else if (CUtil::StringICompare((LPTSTR)pstDefDev->m_szName, _T("LPMVC-U4M")))
			dwSensorType = USBSENSOR_4M_MONO;
		else if (CUtil::StringICompare((LPTSTR)pstDefDev->m_szName, _T("LPMVC-U2M")))
			dwSensorType = USBSENSOR_2M_MONO;
		else if (CUtil::StringICompare((LPTSTR)pstDefDev->m_szName, _T("LPMVC-U4MC")))
			dwSensorType = USBSENSOR_4M_COLOR;
		else if (CUtil::StringICompare((LPTSTR)pstDefDev->m_szName, _T("LPMVC-3U0R3M")))
			dwSensorType = USBSENSOR_VGA_MONO_PYTHON;
		else if (CUtil::StringICompare((LPTSTR)pstDefDev->m_szName, _T("LPMVC-3U0R3C")))
			dwSensorType = USBSENSOR_VGA_COLOR_PYTHON;
		else if (CUtil::StringICompare((LPTSTR)pstDefDev->m_szName, _T("LPMVC-3U1R2M")))
			dwSensorType = USBSENSOR_1_2M_MONO;
		else if (CUtil::StringICompare((LPTSTR)pstDefDev->m_szName, _T("LPMVC-3U1R2C")))
			dwSensorType = USBSENSOR_1_2M_COLOR;
		else if (CUtil::StringICompare((LPTSTR)pstDefDev->m_szName, _T("LPMVC-3U005M")))
			dwSensorType = USBSENSOR_5M_MONO;
		else if (CUtil::StringICompare((LPTSTR)pstDefDev->m_szName, _T("LPMVC-3U010M")))
			dwSensorType = USBSENSOR_10M_MONO;
		
		// _T("LPMVC-U03M")
		if (USBSENSOR_VGA_MONO_CMOSIS == dwSensorType)
		{
			nFps = (int)(300.0f * (480.0f / nHeight));
		}

		// _T("LPMVC-U4M")
		else if (USBSENSOR_4M_MONO == dwSensorType)
		{
			unsigned int U4M_FPS[15] = { 356, 370, 385, 400, 418, 430, 460, 480, 510, 535, 562, 600, 640, 695, 720 };
			if (nHeight <= 400)
			{
				int idx = (400 - nHeight) >> 4;
				if (idx >= 14)
					idx = 13;
				nFps = U4M_FPS[idx];
			}
			else
			{
				nFps = (int)(70 * (2048.0f / nHeight));
			}
		}

		// _T("LPMVC-U2M")
		else if (USBSENSOR_2M_MONO == dwSensorType)
		{
			unsigned int U4M_FPS[15] = { 356, 370, 385, 400, 418, 430, 460, 480, 510, 535, 562, 600, 640, 695, 720 };
			if (nHeight <= 400)
			{
				int idx = (400 - nHeight) >> 4;
				if (idx >= 14)
					idx = 13;
				nFps = U4M_FPS[idx];
			}
			else
			{
				nFps = (int)(131.0f * (1088.0f / nHeight));
			}
		}

		// _T("LPMVC-U4MC")
		//else if (USBSENSOR_4M_COLOR == dwSensorType)
		//{
		//}

		// _T("LPMVC-3U0R3M") & _T("LPMVC-3U0R3C")
		else if (USBSENSOR_VGA_MONO_PYTHON == dwSensorType ||
			USBSENSOR_VGA_COLOR_PYTHON == dwSensorType)
		{
			float fA = 0.0000015f;
			float fB = (55.0f + (100.0f * nWidth) / 29.0f) / 1000000000.0f;
			if (fB > fA)
				fA = fB;
			nFps = (int)((1 / (fA*(nHeight + 12) + 0.00005))+0.2);
		}

		// _T("LPMVC-3U1R2M") & _T("LPMVC-3U1R2C")
		else if (USBSENSOR_1_2M_MONO == dwSensorType ||
			USBSENSOR_1_2M_COLOR == dwSensorType)
		{
			nFps = (74250000 / (40264 + (1388 * nHeight) + nWidth));
		}

		// _T("LPMVC-3U005M")
		else if (USBSENSOR_5M_MONO == dwSensorType)
		{
			nFps = (int)(96000000.0f / ((nHeight + 9.0f)*(nWidth + 900.0f)));
		}

		// _T("LPMVC-3U010M")
		else if (USBSENSOR_10M_MONO == dwSensorType)
		{
			if (777 < nWidth)
				nFps = (int)(160000000.0f / ((nWidth * 2.0f + 94.0f)*(nHeight + 143.0f)));
			else
				nFps = (int)(160000000.0f / (1648.0f * (nHeight + 143.0f)));
		}

		
	}

	if (0 > nFps)
		return FALSE;

	*pdwMaxFps = nFps;

	return TRUE;
}


#if defined(ENABLE_CAMERA_LIBRARY_BASLER)
BOOL GetCameraInformation(HCAMERA hCamera, const int nIdx, INFO_OTHER_CATEGORY* pstRootCategory)
{
	if (NULL == hCamera || NULL == pstRootCategory)
		return FALSE;
	CConnectBasler* pBasler = dynamic_cast<CConnectBasler*> ((CConnect*)hCamera);
	if (NULL == pBasler)
		return FALSE;

	BOOL bResult = pBasler->GetCameraInformation(nIdx, pstRootCategory);
	return bResult;
}

const INFO_OTHER_IF* GetCameraInfoFromName(HCAMERA hCamera, const int nIdx, const TCHAR* pszName)
{
	if (NULL == hCamera || NULL == pszName)
		return NULL;
	CConnectBasler* pBasler = dynamic_cast<CConnectBasler*> ((CConnect*)hCamera);
	if (NULL == pBasler)
		return NULL;

	const INFO_OTHER_IF* pOther = pBasler->GetCameraInformation(nIdx, pszName);
	return pOther;
}

BOOL GetCameraValue(HCAMERA hCamera, const int nIdx, const INFO_OTHER_IF* pstInfo, VALUE_OTHER* pstValue)
{
	if (NULL == hCamera || NULL == pstValue)
		return FALSE;
	CConnectBasler* pBasler = dynamic_cast<CConnectBasler*> ((CConnect*)hCamera);
	if (NULL == pBasler)
		return FALSE;

	BOOL bResult = pBasler->GetCameraValue(nIdx, pstInfo, pstValue);
	return bResult;
}

BOOL SetCameraValue(HCAMERA hCamera, const int nIdx, const INFO_OTHER_IF* pstInfo, VALUE_OTHER* pstValue)
{
	if (NULL == hCamera || NULL == pstValue)
		return FALSE;
	CConnectBasler* pBasler = dynamic_cast<CConnectBasler*> ((CConnect*)hCamera);
	if (NULL == pBasler)
		return FALSE;

	BOOL bResult = pBasler->SetCameraValue(nIdx, pstInfo, pstValue);
	return bResult;
}

#endif