#include "StdAfx.h"
#include "USB.h"
#include "CameraInterfaceDef.h"

#include "inc/UCamLibEx.h"
#include "inc/PixelFormat.h"

#include "Util/Util.h"

#if defined(_WIN64)
	#pragma comment (lib, "UCamLib.lib")
#else
	#pragma comment(lib, "UCamLib.lib")
#endif

CUSB::CUSB()
{
	m_bInit = FALSE;
	m_DeviceCount = 0;

	memset(m_IndexArray, 0xFF, MAX_CAMERA);
	memset(m_SerialArray, 0xFF, sizeof(m_SerialArray));
	memset(m_pLastSWTrigger, 0x00, sizeof(LONGLONG) * MAX_CAMERA);

}

CUSB::~CUSB()
{
	;
}

BOOL CUSB::Open()
{
	UCamGetCameraList(&m_DeviceCount, m_IndexArray);
	if (1 > m_DeviceCount)
		return FALSE;

	UCamGetSerialList(m_SerialArray[0]);
	for (int i = 0; i<m_DeviceCount; i++)
	{
		if (m_IndexArray[i] == 0xFF)
		{
			return FALSE;
		}
		UCamOpenDevice(m_IndexArray[i]);
	}

	m_bInit = TRUE;
	return TRUE;
}

void CUSB::Close()
{
	if(FALSE==IsOpen())
		return;

	for (int i = 0; i<m_DeviceCount; i++)
	{
		if (m_IndexArray[i] == 0xFF)
			continue;

		UCamClose(m_IndexArray[i]);
	}

	memset(m_IndexArray, 0xFF, MAX_CAMERA);
	memset(m_SerialArray, 0xFF, sizeof(m_SerialArray));


	m_bInit = FALSE;
}

BOOL CUSB::IsOpen()
{
	BOOL bOpen = FALSE;
	if( m_bInit )
		bOpen = TRUE;

	return bOpen;
}

BOOL CUSB::FindAllDevice()
{
	int	nErrCode = UCAM_OK;
	unsigned short SensorTypeVal = USBSENSOR_UNKNOWN;

	char szModelU03M[32] = "LPMVC-U03M";
	char szModelU02M[32] = "LPMVC-U2M";
	char szModelU04M[32] = "LPMVC-U4M";
	char szModelU4MC[32] = "LPMVC-U4MC";
	char szModelU0R3M[32] = "LPMVC-3U0R3M";
	char szModelU0R3C[32] = "LPMVC-3U0R3C";
	char szModelU1R2M[32] = "LPMVC-3U1R2M";
	char szModelU1R2C[32] = "LPMVC-3U1R2C";
	char szModelU005M[32] = "LPMVC-3U005M";
	char szModelU010M[32] = "LPMVC-3U010M";
	char szModelUnKnown[32] = "UnKnown Model";

	memset(m_IndexArray, 0xFF, MAX_CAMERA);
	memset(m_SerialArray, 0xFF, sizeof(m_SerialArray));
	m_DeviceCount = 0;
	nErrCode = UCamGetCameraList(&m_DeviceCount, m_IndexArray); // m_IndexArray 는 [0] 부터 채워지고
	if (UCAM_OK!=nErrCode)
	{
		return TRUE;
	}
	CUtil::PumpMessage();

	UCamGetSerialList(m_SerialArray[0]);  // m_SerialArray 는 m_SerialArray[m_IndexArray[0~3] ] 에 대응해서 채운다.

	for (int i = 0; i<m_DeviceCount; i++)
	{
		CUtil::PumpMessage();

		if (m_IndexArray[i] == 0xFF)
		{
			return FALSE;
		}

		m_pstUSBDevInfo[i].m_stUsbDevInfo.Index = m_IndexArray[i];
		memcpy(m_pstUSBDevInfo[i].m_stUsbDevInfo.szSerialNumber, &m_SerialArray[m_IndexArray[i]], 12);

		this->GetSensorType(i, &(m_pstUSBDevInfo[i].SensorType));

		// find model type
		UCamGetSensorType(m_IndexArray[i], &SensorTypeVal);
		if (SensorTypeVal == USBSENSOR_VGA_MONO_CMOSIS)
		{
			memcpy(m_pstUSBDevInfo[i].m_stUsbDevInfo.szModelName, szModelU03M, 32);
		}
		else if (SensorTypeVal == USBSENSOR_4M_MONO)
		{
			memcpy(m_pstUSBDevInfo[i].m_stUsbDevInfo.szModelName, szModelU04M, 32);
		}
		else if (SensorTypeVal == USBSENSOR_2M_MONO)
		{
			memcpy(m_pstUSBDevInfo[i].m_stUsbDevInfo.szModelName, szModelU02M, 32);
		}
		else if (SensorTypeVal == USBSENSOR_4M_COLOR)
		{
			memcpy(m_pstUSBDevInfo[i].m_stUsbDevInfo.szModelName, szModelU4MC, 32);
		}
		else if (SensorTypeVal == USBSENSOR_VGA_MONO_PYTHON)
		{
			memcpy(m_pstUSBDevInfo[i].m_stUsbDevInfo.szModelName, szModelU0R3M, 32);
		}
		else if (SensorTypeVal == USBSENSOR_VGA_COLOR_PYTHON)
		{
			memcpy(m_pstUSBDevInfo[i].m_stUsbDevInfo.szModelName, szModelU0R3C, 32);
		}
		else if (SensorTypeVal == USBSENSOR_1_2M_MONO)
		{
			memcpy(m_pstUSBDevInfo[i].m_stUsbDevInfo.szModelName, szModelU1R2M, 32);
		}
		else if (SensorTypeVal == USBSENSOR_1_2M_COLOR)
		{
			memcpy(m_pstUSBDevInfo[i].m_stUsbDevInfo.szModelName, szModelU1R2C, 32);
		}
		else if (SensorTypeVal == USBSENSOR_5M_MONO)
		{
			memcpy(m_pstUSBDevInfo[i].m_stUsbDevInfo.szModelName, szModelU005M, 32);
		}
		else if (SensorTypeVal == USBSENSOR_10M_MONO)
		{
			memcpy(m_pstUSBDevInfo[i].m_stUsbDevInfo.szModelName, szModelU010M, 32);
		}
		else
		{
			memcpy(m_pstUSBDevInfo[i].m_stUsbDevInfo.szModelName, szModelUnKnown, 32);
		}
		
		UCamOpenDevice(m_IndexArray[i]);
		CUtil::PumpMessage();
	}


	CUtil::PrintDebugString(_T("Search Device: USB \r\n"));
	for (int i = 0; i < m_DeviceCount; i++)
	{
		CUtil::PrintDebugString(_T("  [%d]  %s \r\n"), i, m_pstUSBDevInfo[i].m_stUsbDevInfo.szModelName);
	}
	CUtil::PrintDebugString(_T("Done \r\n"));

	if (1>m_DeviceCount)
		return FALSE;
		
	return TRUE;
}

const int CUSB::GetEnableDeviceCount()
{
	return (int)m_DeviceCount;
}

const INFO_USBDEV* CUSB::GetDeviceModuleInfo(const int nIdx)
{
	const int nCount = GetEnableDeviceCount() ;
	if( nIdx >=  nCount )
		return NULL;

	return &m_pstUSBDevInfo[nIdx];
}

BOOL CUSB::ReadRegAddress(const int nIdx, const UCAM_REG_TYPE eType, const DWORD dwAddress, DWORD* pdwValue)
{
	if (NULL == pdwValue)
		return FALSE;

	BOOL bResult = FALSE;
	unsigned short nValue = 0;

	int nErrCode = UCamReadRegister((char)m_pstUSBDevInfo[nIdx].m_stUsbDevInfo.Index, eType, dwAddress, &nValue);
	if (UCAM_OK == nErrCode)
	{
		bResult = TRUE;
		*pdwValue = nValue;
	}
	return bResult;
}

BOOL CUSB::WriteRegAddress(const int nIdx, const UCAM_REG_TYPE eType, const DWORD dwAddress, DWORD dwValue)
{
	BOOL bResult = FALSE;

	int nErrCode = UCamWriteRegister((char)m_pstUSBDevInfo[nIdx].m_stUsbDevInfo.Index, eType, dwAddress, dwValue);
	if (UCAM_OK == nErrCode)
	{
		bResult = TRUE;
	}
	return bResult;
}

BOOL CUSB::GetX(const int nIdx, DWORD* pdwValue)
{
	const int nCount = GetEnableDeviceCount();
	if (nIdx >= nCount || NULL == pdwValue)
		return FALSE;
	
	BOOL bResult = FALSE;
	WORD data = 0;

	int nErrCode = UCamGetXStart((char)m_pstUSBDevInfo[nIdx].m_stUsbDevInfo.Index, &data);
	if (UCAM_OK == nErrCode)
	{
		bResult = TRUE;
		*pdwValue = data;
	}

	return bResult;
}

BOOL CUSB::GetY(const int nIdx, DWORD* pdwValue)
{
	const int nCount = GetEnableDeviceCount();
	if (nIdx >= nCount || NULL == pdwValue)
		return FALSE;

	BOOL bResult = FALSE;
	WORD data = 0;

	int nErrCode = UCamGetYStart((char)m_pstUSBDevInfo[nIdx].m_stUsbDevInfo.Index, &data);
	if (UCAM_OK == nErrCode)
	{
		bResult = TRUE;
		*pdwValue = data;
	}
	return bResult;
}


BOOL CUSB::GetWidth(const int nIdx, DWORD* pdwValue)
{
	const int nCount = GetEnableDeviceCount();
	if (nIdx >= nCount || NULL == pdwValue)
		return FALSE;

	BOOL bResult = FALSE;
	WORD data = 0;

	int nErrCode = UCamGetWidth((char)m_pstUSBDevInfo[nIdx].m_stUsbDevInfo.Index, &data);
	if (UCAM_OK == nErrCode)
	{
		bResult = TRUE;
		*pdwValue = data;
	}
	return bResult;
}

BOOL CUSB::GetHeight(const int nIdx, DWORD* pdwValue)
{
	const int nCount = GetEnableDeviceCount();
	if (nIdx >= nCount || NULL == pdwValue)
		return FALSE;

	BOOL bResult = FALSE;
	WORD data = 0;

	int nErrCode = UCamGetHeight((char)m_pstUSBDevInfo[nIdx].m_stUsbDevInfo.Index, &data);
	if (UCAM_OK == nErrCode)
	{
		bResult = TRUE;
		*pdwValue = data;
	}
	return bResult;
}

BOOL CUSB::GetMaxWidth(const int nIdx, DWORD* pdwValue)
{
	const int nCount = GetEnableDeviceCount() ;
	if( nIdx >= nCount || NULL==pdwValue)
		return FALSE;

	BOOL bResult = FALSE;
	WORD data = 0;

	int nErrCode = UCamGetMaxWidth((char)m_pstUSBDevInfo[nIdx].m_stUsbDevInfo.Index, &data);
	if (UCAM_OK == nErrCode)
	{
		bResult = TRUE;
		*pdwValue = data;
	}
	return bResult;
}

BOOL CUSB::GetMaxHeight(const int nIdx, DWORD* pdwValue)
{
	const int nCount = GetEnableDeviceCount();
	if (nIdx >= nCount || NULL == pdwValue)
		return FALSE;

	BOOL bResult = FALSE;
	WORD data = 0;

	int nErrCode = UCamGetMaxHeight((char)m_pstUSBDevInfo[nIdx].m_stUsbDevInfo.Index, &data);
	if (UCAM_OK == nErrCode)
	{
		bResult = TRUE;
		*pdwValue = data;
	}
	return bResult;
}

BOOL CUSB::GetUsersetStartNo(const int nIdx, unsigned char* pValue)
{
	const int nCount = GetEnableDeviceCount();
	if (nIdx >= nCount || NULL == pValue)
		return FALSE;

	BOOL bResult = FALSE;
	BYTE data = 0;

	int nErrCode = UCamGetCurrentUserset((char)m_pstUSBDevInfo[nIdx].m_stUsbDevInfo.Index, &data);
	if (UCAM_OK == nErrCode)
	{
		bResult = TRUE;
		*pValue = data;
	}
	return bResult;
}

BOOL CUSB::SetUsersetStartNo(const int nIdx, unsigned char Value)
{
	const int nCount = GetEnableDeviceCount();
	if (nIdx >= nCount )
		return FALSE;

	BOOL bResult = FALSE;
	int nErrCode = UCamSetUsersetStartNumber((char)m_pstUSBDevInfo[nIdx].m_stUsbDevInfo.Index, Value);
	if (UCAM_OK == nErrCode)
	{
		bResult = TRUE;
	}
	return bResult;
}

BOOL CUSB::GetPixelFormat(const int nIdx, DWORD* pdwValue)
{
	unsigned short SensorTypeVal = USBSENSOR_UNKNOWN;

	const int nCount = GetEnableDeviceCount() ;
	if( nIdx >= nCount || NULL==pdwValue )
		return FALSE;

	// find model type
	int nErrCode = UCamGetSensorType((char)m_pstUSBDevInfo[nIdx].m_stUsbDevInfo.Index, &SensorTypeVal);
	if (UCAM_OK != nErrCode)
	{
		return FALSE;
	}
	
	if (SensorTypeVal == USBSENSOR_VGA_MONO_CMOSIS)			// VGA(cmosis) Mono
	{
		*pdwValue = GVSP_PIX_MONO | GVSP_PIX_OCCUPY8BIT;
	}
	else if (SensorTypeVal == USBSENSOR_4M_MONO)			// 4M Mono
	{
		*pdwValue = GVSP_PIX_MONO | GVSP_PIX_OCCUPY8BIT;
	}
	else if (SensorTypeVal == USBSENSOR_2M_MONO)			// 2M Mono
	{
		*pdwValue = GVSP_PIX_MONO | GVSP_PIX_OCCUPY8BIT;
	}
	else if (SensorTypeVal == USBSENSOR_4M_COLOR)			// 4M Color
	{
		*pdwValue = GVSP_PIX_COLOR | GVSP_PIX_OCCUPY8BIT;
	}
	else if (SensorTypeVal == USBSENSOR_VGA_MONO_PYTHON)	// VGA(Python) Mono
	{
		*pdwValue = GVSP_PIX_MONO | GVSP_PIX_OCCUPY8BIT;
	}
	else if (SensorTypeVal == USBSENSOR_VGA_COLOR_PYTHON)	// VGA(Python) Color
	{
		*pdwValue = GVSP_PIX_COLOR | GVSP_PIX_OCCUPY8BIT;
	}
	else if (SensorTypeVal == USBSENSOR_1_2M_MONO)			// 1.2M Mono
	{
		*pdwValue = GVSP_PIX_MONO | GVSP_PIX_OCCUPY8BIT;
	}
	else if (SensorTypeVal == USBSENSOR_1_2M_COLOR)			// 1.2M Color
	{
		*pdwValue = GVSP_PIX_COLOR | GVSP_PIX_OCCUPY8BIT;
	}
	else if (SensorTypeVal == USBSENSOR_5M_MONO)			// 5M Mono
	{
		*pdwValue = GVSP_PIX_MONO | GVSP_PIX_OCCUPY8BIT;
	}
	else if (SensorTypeVal == USBSENSOR_10M_MONO)			// 10M Mono
	{
		*pdwValue = GVSP_PIX_MONO | GVSP_PIX_OCCUPY8BIT;
	}
	else
	{
		*pdwValue = TYPE_CAMCOLOR_NONE;
	}
	return TRUE;
}

BOOL CUSB::GetColorFormat(const int nIdx, DWORD* pdwValue)
{
	unsigned short ColorFormatVal = 0;
	unsigned short SensorTypeVal = 0;

	const int nCount = GetEnableDeviceCount();
	if (nIdx >= nCount || NULL == pdwValue)
		return FALSE;

	// find model type
	int nErrCode = UCamGetColorFormat((char)m_pstUSBDevInfo[nIdx].m_stUsbDevInfo.Index, &ColorFormatVal);
	if (UCAM_OK != nErrCode)
	{
		return FALSE;
	}
	
	*pdwValue = ColorFormatVal; // 3U0R3C ( BAYER : 0, YUV : 1), Others (0 fixed)  
	
	// find model type
	nErrCode = UCamGetSensorType((char)m_pstUSBDevInfo[nIdx].m_stUsbDevInfo.Index, &SensorTypeVal);
	if (UCAM_OK != nErrCode)
	{
		return FALSE;
	}

	if (SensorTypeVal == USBSENSOR_VGA_COLOR_PYTHON)     // 3U0R3C Color
	{
		if (ColorFormatVal)   // YUV
		{
			*pdwValue = TYPE_CAMCOLORFORMAT_YUV;
		}
		else                  // RGB Color
		{
			*pdwValue = TYPE_CAMCOLORFORMAT_BAYER_RG;
		}
	}
	else if (SensorTypeVal == USBSENSOR_1_2M_COLOR)     // 3U1R2C Color
	{
		*pdwValue = TYPE_CAMCOLORFORMAT_BAYER_GR;
	}
	else
	{
		*pdwValue = TYPE_CAMCOLORFORMAT_NONE;
	}

	return TRUE;
}


BOOL CUSB::SetEventCallbackImageAcquisition(const int nIdx, ReceiveCallback pFunc, void* pUserData)   // FuncAcquisitionEvent
{
	const int nCount = GetEnableDeviceCount() ;
	if( nIdx >= nCount || NULL==pFunc )
		return FALSE;

	USBReceiveCallback(pFunc, (char)m_pstUSBDevInfo[nIdx].m_stUsbDevInfo.Index, pUserData);  //   DLLFunction void  WINAPI USBReceiveCallback(ReceiveCallback func);
	return TRUE;
}

BOOL CUSB::IsStart(const int nIdx)
{
	const int nCount = GetEnableDeviceCount();
	if (nIdx >= nCount)
		return FALSE;

	return m_pstUSBDevInfo[nIdx].bStart;
}

BOOL CUSB::Start(const int nIdx, BOOL bSingle)
{
	const int nCount = GetEnableDeviceCount() ;
	if( nIdx >= nCount )
		return FALSE;
	
	Sleep(100);

	int nErrCode = UCamStart((char)m_pstUSBDevInfo[nIdx].m_stUsbDevInfo.Index, 1, 0);  // Index(0~3), receive mode(0:polling, 1:callback, 0:continuos mode 1:trigger mode )
	Sleep(10);
	BOOL bResult = FALSE;
	if (UCAM_OK == nErrCode)
	{
		UCamCameraInit((char)m_pstUSBDevInfo[nIdx].m_stUsbDevInfo.Index);
		bResult = TRUE;
	}

	m_pstUSBDevInfo[nIdx].bStart = bResult;
	return bResult;
}

void CUSB::Stop(const int nIdx)
{
	const int nCount = GetEnableDeviceCount();
	if (nIdx >= nCount)
		return;
	UCamStop((char)m_pstUSBDevInfo[nIdx].m_stUsbDevInfo.Index);  // Index(0~3)

	m_pstUSBDevInfo[nIdx].bStart = FALSE;
}

BOOL CUSB::SetRoi(const int nIdx, const int nX, const int nY, const int nW, const int nH)
{
	const int nCount = GetEnableDeviceCount() ;
	if( nIdx >= nCount )
		return FALSE;

	int nErrCode = UCamSetROISetting((char)m_pstUSBDevInfo[nIdx].m_stUsbDevInfo.Index, nX, nY, nW, nH);
	if (UCAM_OK != nErrCode)
		return FALSE;

	return TRUE;

}

BOOL CUSB::SetGain(const int nIdx, int GainType, int GainValue)
{
	const int nCount = GetEnableDeviceCount();
	if (nIdx >= nCount)
		return FALSE;

	unsigned short value = 0;
	unsigned short SensorTypeVal = USBSENSOR_UNKNOWN;

	int nErrCode = UCamGetSensorType((char)m_pstUSBDevInfo[nIdx].m_stUsbDevInfo.Index, &SensorTypeVal);
	if (UCAM_OK != nErrCode)
	{
		return FALSE;
	}

	if (SensorTypeVal == USBSENSOR_VGA_MONO_CMOSIS)        // U03M Mono
	{
		if (GainType == GAIN_DIGITAL_ADC)         // ADC
		{
			nErrCode = UCamSetADCGain((char)m_pstUSBDevInfo[nIdx].m_stUsbDevInfo.Index, GainValue);
		}
		else if (GainType == GAIN_ANALOG_PGA)    // PGA
		{
			nErrCode = UCamSetPGAGain((char)m_pstUSBDevInfo[nIdx].m_stUsbDevInfo.Index, GainValue);
		}
	}
	else if (SensorTypeVal == USBSENSOR_4M_MONO)     // 4M Mono
	{
		if (GainType == GAIN_DIGITAL_ADC)         // ADC
		{
			nErrCode = UCamSetADCGain((char)m_pstUSBDevInfo[nIdx].m_stUsbDevInfo.Index, GainValue);
		}
		else if (GainType == GAIN_ANALOG_PGA)    // PGA
		{
			nErrCode = UCamSetPGAGain((char)m_pstUSBDevInfo[nIdx].m_stUsbDevInfo.Index, GainValue);
		}
	}
	else if (SensorTypeVal == USBSENSOR_2M_MONO)     // 2M Mono
	{
		if (GainType == GAIN_DIGITAL_ADC)         // ADC
		{
			nErrCode = UCamSetADCGain((char)m_pstUSBDevInfo[nIdx].m_stUsbDevInfo.Index, GainValue);
		}
		else if (GainType == GAIN_ANALOG_PGA)    // PGA
		{
			nErrCode = UCamSetPGAGain((char)m_pstUSBDevInfo[nIdx].m_stUsbDevInfo.Index, GainValue);
		}
	}
	else if (SensorTypeVal == USBSENSOR_4M_COLOR)     // 4M Color
	{

	}
	else if (SensorTypeVal == USBSENSOR_VGA_MONO_PYTHON)     // 0.3M (Python) Mono
	{
		if (GainType == GAIN_DIGITAL_ADC)           // ADC
		{
			nErrCode = UCamSetADCGain((char)m_pstUSBDevInfo[nIdx].m_stUsbDevInfo.Index, GainValue);
		}
	}
	else if (SensorTypeVal == USBSENSOR_VGA_COLOR_PYTHON)     // 0.3M (Python) Color
	{  
		if (GainType == GAIN_DIGITAL_ADC)           // ADC
		{
			nErrCode = UCamSetADCGain((char)m_pstUSBDevInfo[nIdx].m_stUsbDevInfo.Index, GainValue);
		}
	}
	else if (SensorTypeVal == USBSENSOR_1_2M_MONO)     // 1.2M Mono
	{
		if (GainType == GAIN_DIGITAL_ADC)           // ADC
		{
			nErrCode = UCamSetADCGain((char)m_pstUSBDevInfo[nIdx].m_stUsbDevInfo.Index, GainValue);
		}
	}
	else if (SensorTypeVal == USBSENSOR_1_2M_COLOR)     // 1.2M Color
	{
		if (GainType == GAIN_DIGITAL_ADC)           // ADC
		{
			nErrCode = UCamSetADCGain((char)m_pstUSBDevInfo[nIdx].m_stUsbDevInfo.Index, GainValue);
		}
	}
	else if (SensorTypeVal == USBSENSOR_5M_MONO || SensorTypeVal == USBSENSOR_10M_MONO)     // 5M Mono, 10M Mono
	{
		if (GainType == GAIN_DIGITAL_ADC)           // ADC
		{
			nErrCode = UCamSetADCGain((char)m_pstUSBDevInfo[nIdx].m_stUsbDevInfo.Index, GainValue);
		}
	}
	else
	{
	}

	if (UCAM_OK != nErrCode)
		return FALSE;

	return TRUE;
}

BOOL CUSB::GetGain(const int nIdx, int GainType, int* GainValue)
{
	const int nCount = GetEnableDeviceCount();
	if (nIdx >= nCount || NULL == GainValue)
		return FALSE;

	unsigned short value = 0;
	unsigned short SensorTypeVal = USBSENSOR_UNKNOWN;

	int nErrCode = UCamGetSensorType((char)m_pstUSBDevInfo[nIdx].m_stUsbDevInfo.Index, &SensorTypeVal);
	if (UCAM_OK != nErrCode)
	{
		return FALSE;
	}

	if (SensorTypeVal == USBSENSOR_VGA_MONO_CMOSIS)        // U03M Mono
	{
		if (GainType == GAIN_DIGITAL_ADC)         // ADC
		{
			nErrCode = UCamGetADCGain((char)m_pstUSBDevInfo[nIdx].m_stUsbDevInfo.Index, &value);
			*GainValue = value;
		}
		else if (GainType == GAIN_ANALOG_PGA)    // PGA
		{
			nErrCode = UCamGetPGAGain((char)m_pstUSBDevInfo[nIdx].m_stUsbDevInfo.Index, &value);
			*GainValue = value;
		}
	}
	else if (SensorTypeVal == USBSENSOR_4M_MONO)     // 4M Mono
	{
		if (GainType == GAIN_DIGITAL_ADC)         // ADC
		{
			nErrCode = UCamGetADCGain((char)m_pstUSBDevInfo[nIdx].m_stUsbDevInfo.Index, &value);
			*GainValue = value;
		}
		else if (GainType == GAIN_ANALOG_PGA)    // PGA
		{
			nErrCode = UCamGetPGAGain((char)m_pstUSBDevInfo[nIdx].m_stUsbDevInfo.Index, &value);
			*GainValue = value;
		}
	}
	else if (SensorTypeVal == USBSENSOR_2M_MONO)     // 2M Mono
	{
		if (GainType == GAIN_DIGITAL_ADC)         // ADC
		{
			nErrCode = UCamGetADCGain((char)m_pstUSBDevInfo[nIdx].m_stUsbDevInfo.Index, &value);
			*GainValue = value;
		}
		else if (GainType == GAIN_ANALOG_PGA)    // PGA
		{
			nErrCode = UCamGetPGAGain((char)m_pstUSBDevInfo[nIdx].m_stUsbDevInfo.Index, &value);
			*GainValue = value;
		}
	}
	else if (SensorTypeVal == USBSENSOR_4M_COLOR)     // 4M Color : TO DO
	{
		
	}
	else if (SensorTypeVal == USBSENSOR_VGA_MONO_PYTHON)     // 0.3M (Python) Mono
	{
		if (GainType == GAIN_DIGITAL_ADC)         // ADC
		{
			nErrCode = UCamGetADCGain((char)m_pstUSBDevInfo[nIdx].m_stUsbDevInfo.Index, &value);
			*GainValue = value;
		}
	}
	else if (SensorTypeVal == USBSENSOR_VGA_COLOR_PYTHON)     // 0.3M (Python) Color TODO
	{
		if (GainType == GAIN_DIGITAL_ADC)         // ADC
		{
			nErrCode = UCamGetADCGain((char)m_pstUSBDevInfo[nIdx].m_stUsbDevInfo.Index, &value);
			*GainValue = value;
		}
	}
	else if (SensorTypeVal == USBSENSOR_1_2M_MONO)     // 1.2M Mono
	{
		if (GainType == GAIN_DIGITAL_ADC)         // ADC
		{
			nErrCode = UCamGetADCGain((char)m_pstUSBDevInfo[nIdx].m_stUsbDevInfo.Index, &value);
			*GainValue = value;
		}
	}
	else if (SensorTypeVal == USBSENSOR_1_2M_COLOR)     // 1.2M Color  // TO DO
	{
		if (GainType == GAIN_DIGITAL_ADC)         // ADC
		{
			nErrCode = UCamGetADCGain((char)m_pstUSBDevInfo[nIdx].m_stUsbDevInfo.Index, &value);
			*GainValue = value;
		}
	}
	else if (SensorTypeVal == USBSENSOR_5M_MONO || SensorTypeVal == USBSENSOR_10M_MONO)     // 5M Mono, 10M Mono
	{
		if (GainType == GAIN_DIGITAL_ADC)         // ADC
		{
			nErrCode = UCamGetADCGain((char)m_pstUSBDevInfo[nIdx].m_stUsbDevInfo.Index, &value);
			*GainValue = value;
		}
	}
	else
	{
	}

	if (UCAM_OK != nErrCode)
		return FALSE;

	return TRUE;
}

BOOL CUSB::SetFrameRate(const int nIdx, unsigned int FrameRate)
{
	const int nCount = GetEnableDeviceCount();
	if (nIdx >= nCount)
		return FALSE;

	unsigned int value = FrameRate;

	UCamSetFrameRate((char)m_pstUSBDevInfo[nIdx].m_stUsbDevInfo.Index, value);
	return TRUE;
}


BOOL CUSB::GetFrameRate(const int nIdx, unsigned int* FrameRate)
{
	const int nCount = GetEnableDeviceCount();
	if (nIdx >= nCount || NULL == FrameRate)
		return FALSE;

	unsigned int value = 0;

	int nErrCode = UCamGetFrameRate((char)m_pstUSBDevInfo[nIdx].m_stUsbDevInfo.Index, &value);
	if (UCAM_OK != nErrCode)
		return FALSE;

	*FrameRate = value;
	return TRUE;
}

BOOL CUSB::SetExposureTime(const int nIdx, unsigned int ExposureTime)
{
	const int nCount = GetEnableDeviceCount();
	if (nIdx >= nCount)
		return FALSE;

	unsigned int value = ExposureTime;

	int nErrCode = UCamSetExposureTime((char)m_pstUSBDevInfo[nIdx].m_stUsbDevInfo.Index, value);
	if (UCAM_OK != nErrCode)
		return FALSE;

	return TRUE;
}


BOOL CUSB::GetExposureTime(const int nIdx, unsigned int* ExposureTime)
{
	const int nCount = GetEnableDeviceCount();
	if (nIdx >= nCount || NULL == ExposureTime)
		return FALSE;

	unsigned int value = 0;

	int nErrCode = UCamGetExposureTime((char)m_pstUSBDevInfo[nIdx].m_stUsbDevInfo.Index, &value);
	if (UCAM_OK != nErrCode)
		return FALSE;

	*ExposureTime = value;
	return TRUE;
}

BOOL CUSB::GetExposureMaxTime(const int nIdx, unsigned int FrameRate ,unsigned int* ExposureTime)
{
	const int nCount = GetEnableDeviceCount();
	if (nIdx >= nCount || NULL == ExposureTime)
		return FALSE;

	unsigned int value = 0;

	int nErrCode = UCamGetExposureMaxTime((char)m_pstUSBDevInfo[nIdx].m_stUsbDevInfo.Index, FrameRate, &value);
	if (UCAM_OK != nErrCode)
		return FALSE;

	*ExposureTime = value;
	return TRUE;
}

BOOL CUSB::ConvertExposureTime(const int nIdx, DWORD dwStep, double* pfUsec)
{
	const int nCount = GetEnableDeviceCount();
	if (nIdx >= nCount || NULL == pfUsec)
		return FALSE;

	const INFO_USBDEV* pstUsb = GetDeviceModuleInfo(nIdx);
	if (NULL == pstUsb)
		return FALSE;

	if (USBSENSOR_VGA_MONO_PYTHON == pstUsb->SensorType || USBSENSOR_VGA_COLOR_PYTHON == pstUsb->SensorType)
	{
		*pfUsec = dwStep * 0.0139f;
	}
	else if (USBSENSOR_1_2M_MONO == pstUsb->SensorType || USBSENSOR_1_2M_COLOR == pstUsb->SensorType)
	{
		*pfUsec = dwStep * 18.6936f;
	}
	else if (USBSENSOR_5M_MONO == pstUsb->SensorType )
	{
		DWORD dwWidth = 0;
		GetWidth(nIdx, &dwWidth);

		*pfUsec = (dwStep * (dwWidth + 900) / 96 - 4.4375f);
	}
	else if (USBSENSOR_10M_MONO == pstUsb->SensorType)
	{
		DWORD dwHeight = 0;
		GetHeight(nIdx, &dwHeight);

		*pfUsec = (dwStep * dwHeight / 160);
	}
	else
	{
		*pfUsec = dwStep * 0.0512f;
	}

	return TRUE;
}


BOOL CUSB::GetDiag(const int nIdx, INFO_DIAGONOSTICS_USB* pstDiag)
{
	const int nCount = GetEnableDeviceCount();
	if (nIdx >= nCount || NULL == pstDiag)
		return FALSE;

	unsigned int nValue1 = 0;
	float        fValue2 = 0;
	float        fvalue3 = 0;
	unsigned int nValue4 = 0;
	
	int nErrCode = UCamGetDiagnostics((char)m_pstUSBDevInfo[nIdx].m_stUsbDevInfo.Index, &nValue1, &fValue2, &fvalue3, &nValue4);
	if (UCAM_OK != nErrCode)
		return FALSE;

	pstDiag->m_nImageCount = nValue1;
	pstDiag->m_fFrameRate = fValue2;
	pstDiag->m_fBitRate = fvalue3;
	pstDiag->m_nSkipCnt = nValue4;

	return TRUE;
}

BOOL CUSB::SetTriggerMode(const int nIdx, INFO_TRIGGER_PARA stTrigger)
{
	const int nCount = GetEnableDeviceCount();
	if (nIdx >= nCount )
		return FALSE;
	int nErrCode = UCAM_OK;

	unsigned short TriggerMode = 0;
	
	nErrCode = UCamSetSWTriggerMode((char)m_pstUSBDevInfo[nIdx].m_stUsbDevInfo.Index, stTrigger.nTriggerSource);
	if (UCAM_OK != nErrCode)
		return FALSE;

	nErrCode = UCamSetExposureDelay((char)m_pstUSBDevInfo[nIdx].m_stUsbDevInfo.Index, stTrigger.nTriggerDelay);
	if (UCAM_OK != nErrCode)
		return FALSE;

	if (stTrigger.nTriggerTypePolarity == TRIGGER_EDGE_NEGATIVE)        // Edge Active Low
	{ 
		TriggerMode = stTrigger.nTriggerMode;
	}
	else if (stTrigger.nTriggerTypePolarity == TRIGGER_EDGE_POSITIVE)   // Edge Active High
	{
		TriggerMode = stTrigger.nTriggerMode | 0x0010;
	}
	else if (stTrigger.nTriggerTypePolarity == TRIGGER_LEVEL_NEGATIVE)   // Level Active Low
	{
		TriggerMode = stTrigger.nTriggerMode | 0x0100;
	}
	else if (stTrigger.nTriggerTypePolarity == TRIGGER_LEVEL_POSITIVE)   // Level Active High
	{
		TriggerMode = stTrigger.nTriggerMode | 0x0110;
	}

	nErrCode = UCamSetTriggerMode((char)m_pstUSBDevInfo[nIdx].m_stUsbDevInfo.Index, TriggerMode);
	if (UCAM_OK != nErrCode)
		return FALSE;

	return TRUE;
}

BOOL CUSB::GetTriggerMode(const int nIdx, INFO_TRIGGER_PARA* stTrigger)
{
	const int nCount = GetEnableDeviceCount();
	if (nIdx >= nCount || NULL == stTrigger)
		return FALSE;
	int nErrCode = UCAM_OK;

	unsigned short usData1 = 0;
	unsigned int   uiData2 = 0;

	nErrCode = UCamGetSWTriggerMode((char)m_pstUSBDevInfo[nIdx].m_stUsbDevInfo.Index, &usData1);
	if (UCAM_OK != nErrCode)
		return FALSE;
	stTrigger->nTriggerSource = usData1;

	nErrCode = UCamGetExposureDelay((char)m_pstUSBDevInfo[nIdx].m_stUsbDevInfo.Index, &uiData2);
	if (UCAM_OK != nErrCode)
		return FALSE;
	stTrigger->nTriggerDelay = uiData2;

	nErrCode = UCamGetTriggerMode((char)m_pstUSBDevInfo[nIdx].m_stUsbDevInfo.Index, &usData1);
	if (UCAM_OK != nErrCode)
		return FALSE;
	stTrigger->nTriggerMode = usData1 & 0x0001;

	if (0x0100 & usData1)
	{
		if (0x0010 & usData1)
			stTrigger->nTriggerTypePolarity = TRIGGER_LEVEL_POSITIVE;
		else
			stTrigger->nTriggerTypePolarity = TRIGGER_LEVEL_NEGATIVE;
	}
	else
	{
		if (0x0010 & usData1)
			stTrigger->nTriggerTypePolarity = TRIGGER_EDGE_POSITIVE;
		else
			stTrigger->nTriggerTypePolarity = TRIGGER_EDGE_NEGATIVE;
	}

	return TRUE;
}

BOOL CUSB::SetTriggerDelay(const int nIdx, int nDelay)
{
	const int nCount = GetEnableDeviceCount();
	if (nIdx >= nCount )
		return FALSE;

	int nErrCode = UCamSetExposureDelay((char)m_pstUSBDevInfo[nIdx].m_stUsbDevInfo.Index, nDelay);
	if (UCAM_OK != nErrCode)
		return FALSE;

	return TRUE;
}

BOOL CUSB::SetSWTrigger(const int nIdx)
{
	const int nCount = GetEnableDeviceCount();
	if (nIdx >= nCount )
		return FALSE;

	/*//
	const int nMaxWait = 0;
	int nSleep = 0;
	
	const LONGLONG CURTICK = ::GetTickCount64();
	const LONGLONG LASTTRIGGER = m_pLastSWTrigger[nIdx];
	
	m_pLastSWTrigger[nIdx] = CURTICK;
	if (0 == LASTTRIGGER || 0 != LASTTRIGGER && LASTTRIGGER > CURTICK)
	{
		m_pLastSWTrigger[nIdx] = CURTICK;
	}
	else
	{
		LONGLONG delta = CURTICK - LASTTRIGGER;
		if (nMaxWait > delta)
		{
			nSleep = nMaxWait - delta;
			CUtil::Sleep(nMaxWait - delta);
		}
	}
	//*/

	int nErrCode = UCamSetSWTriggerSignal((char)m_pstUSBDevInfo[nIdx].m_stUsbDevInfo.Index);
	if (UCAM_OK != nErrCode)
		return FALSE;
	return TRUE;
}

BOOL CUSB::SaveUserset(const int nIdx, unsigned char nNumber)
{
	const int nCount = GetEnableDeviceCount();
	if (nIdx >= nCount || 0 == nNumber)
		return FALSE;

	int nErrCode = UCamSaveUserSet((char)m_pstUSBDevInfo[nIdx].m_stUsbDevInfo.Index, nNumber);
	if (UCAM_OK != nErrCode)
		return FALSE;
	return TRUE;
}

BOOL CUSB::LoadUserset(const int nIdx, unsigned char nNumber)
{
	const int nCount = GetEnableDeviceCount();
	if (nIdx >= nCount)
		return FALSE;

	int nErrCode = UCamSetPreviewFromUserSet((char)m_pstUSBDevInfo[nIdx].m_stUsbDevInfo.Index, nNumber);
	if (UCAM_OK != nErrCode)
		return FALSE;
	return TRUE;
}


BOOL CUSB::SetStrobeMode(const int nIdx, INFO_STROBE_PARA stStrobe)
{
	const int nCount = GetEnableDeviceCount();
	if (nIdx >= nCount)
		return FALSE;
	int nErrCode = UCAM_OK;

	unsigned short StrobeMode = 0;

	nErrCode = UCamSetStrobeWidth((char)m_pstUSBDevInfo[nIdx].m_stUsbDevInfo.Index, stStrobe.nStrobeWidth);
	if (UCAM_OK != nErrCode)
		return FALSE;

	nErrCode = UCamSetStrobeDelay((char)m_pstUSBDevInfo[nIdx].m_stUsbDevInfo.Index, stStrobe.nStrobeDelay);
	if (UCAM_OK != nErrCode)
		return FALSE;

	if (stStrobe.nStrobePolarity == 0)        // Edge Active Low
	{
		StrobeMode = stStrobe.nStrobeMode;
	}
	else if (stStrobe.nStrobePolarity == 1)   // Edge Active High
	{
		StrobeMode = stStrobe.nStrobeMode | 0x0010;
	}
	
	nErrCode = UCamSetStrobeMode((char)m_pstUSBDevInfo[nIdx].m_stUsbDevInfo.Index, StrobeMode);
	if (UCAM_OK != nErrCode)
		return FALSE;
	
	return TRUE;
}

BOOL CUSB::GetStrobeMode(const int nIdx, INFO_STROBE_PARA* stStrobe)
{
	const int nCount = GetEnableDeviceCount();
	if (nIdx >= nCount || NULL == stStrobe)
		return FALSE;
	int nErrCode = UCAM_OK;

	unsigned short usData1 = 0;
	unsigned int   uiData2 = 0;

	nErrCode = UCamGetStrobeWidth((char)m_pstUSBDevInfo[nIdx].m_stUsbDevInfo.Index, &uiData2);
	if (UCAM_OK != nErrCode)
		return FALSE;
	stStrobe->nStrobeWidth = uiData2;

	nErrCode = UCamGetStrobeDelay((char)m_pstUSBDevInfo[nIdx].m_stUsbDevInfo.Index, &uiData2);
	if (UCAM_OK != nErrCode)
		return FALSE;
	stStrobe->nStrobeDelay = uiData2;

	nErrCode = UCamGetStrobeMode((char)m_pstUSBDevInfo[nIdx].m_stUsbDevInfo.Index, &usData1);
	if (UCAM_OK != nErrCode)
	{
		return FALSE;
	}

	stStrobe->nStrobeMode = usData1 & 0x0001;
	stStrobe->nStrobePolarity = (usData1 & 0x0010) >> 4;
	return TRUE;
}

BOOL CUSB::SetFlipMode(const int nIdx, unsigned short nMode)
{
	const int nCount = GetEnableDeviceCount();
	if (nIdx >= nCount)
		return FALSE;

	int nErrCode = UCamSetFlip((char)m_pstUSBDevInfo[nIdx].m_stUsbDevInfo.Index, nMode);
	if (UCAM_OK != nErrCode)
		return FALSE;

	return TRUE;
}

BOOL CUSB::GetFlipMode(const int nIdx, unsigned short* nMode)
{
	const int nCount = GetEnableDeviceCount();
	if (nIdx >= nCount || NULL == nMode)
		return FALSE;

	WORD data = 0;

	int nErrCode = UCamGetFlip((char)m_pstUSBDevInfo[nIdx].m_stUsbDevInfo.Index, &data);
	if (UCAM_OK != nErrCode)
		return FALSE;

	*nMode = data;
	return TRUE;
}

BOOL CUSB::GetSensorType(const int nIdx, DWORD* pdwType)
{
	const int nCount = GetEnableDeviceCount();
	if (nIdx >= nCount || NULL == pdwType)
		return FALSE;

	unsigned short nType = USBSENSOR_UNKNOWN;

	int nErrCode = UCamGetSensorType((char)m_pstUSBDevInfo[nIdx].m_stUsbDevInfo.Index, &nType);
	if (UCAM_OK != nErrCode)
		return FALSE;

	*pdwType = nType;
	return TRUE;
}

BOOL CUSB::SetDataBit(const int nIdx, unsigned short nDataBit)
{
	const int nCount = GetEnableDeviceCount();
	if (nIdx >= nCount)
		return FALSE;

	unsigned short nBit = 0;
	
	if (10 == nDataBit)			nBit = 1;
	else if (12 == nDataBit)	nBit = 2;
	//else if (8 == nDataBit)	nBit = 0;

	this->Stop(nIdx);

	int nErrCode = UCamSetImageFormat((char)m_pstUSBDevInfo[nIdx].m_stUsbDevInfo.Index, nBit);
	if (UCAM_OK != nErrCode)
		return FALSE;

	this->Start(nIdx);

	return TRUE;
}
BOOL CUSB::GetDataBit(const int nIdx, unsigned short* nDataBit)
{
	const int nCount = GetEnableDeviceCount();
	if (nIdx >= nCount || NULL == nDataBit)
		return FALSE;

	unsigned short nBit = 0;

	int nErrCode = UCamGetImageFormat((char)m_pstUSBDevInfo[nIdx].m_stUsbDevInfo.Index, &nBit);
	if (UCAM_OK != nErrCode)
		return FALSE;
	
	if (0 == nBit)			*nDataBit = 8;
	else if (1 == nBit)		*nDataBit = 10;
	else if (2 == nBit)		*nDataBit = 12;
	else
		return FALSE;
	return TRUE;
}

BOOL CUSB::SetColorMode(const int nIdx, unsigned short nColorMode)
{
	const int nCount = GetEnableDeviceCount();
	if (nIdx >= nCount )
		return FALSE;

	int nErrCode = UCamSetColorFormat((char)m_pstUSBDevInfo[nIdx].m_stUsbDevInfo.Index, nColorMode);
	if (UCAM_OK != nErrCode)
		return FALSE;
	return TRUE;
}
BOOL CUSB::GetColorMode(const int nIdx, unsigned short* pnColorMode)
{
	const int nCount = GetEnableDeviceCount();
	if (nIdx >= nCount || NULL == pnColorMode)
		return FALSE;

	WORD data = 0;

	int nErrCode = UCamGetColorFormat((char)m_pstUSBDevInfo[nIdx].m_stUsbDevInfo.Index, &data);
	if (UCAM_OK != nErrCode)
		return FALSE;
	
	*pnColorMode = data;
	return TRUE;
}

// LUT
BOOL CUSB::SetLutMode(const int nIdx, unsigned short nMode)
{
	const int nCount = GetEnableDeviceCount();
	if (nIdx >= nCount)
		return FALSE;

	int nErrCode = UCamSetLUTMode((char)m_pstUSBDevInfo[nIdx].m_stUsbDevInfo.Index, nMode);
	if (UCAM_OK != nErrCode)
		return FALSE;

	return TRUE;
}
BOOL CUSB::GetLutMode(const int nIdx, unsigned short* pnMode)
{
	const int nCount = GetEnableDeviceCount();
	if (nIdx >= nCount || NULL == pnMode)
		return FALSE;

	unsigned short nLutmode = 0;

	int nErrCode = UCamGetLUTMode((char)m_pstUSBDevInfo[nIdx].m_stUsbDevInfo.Index, &nLutmode);
	if (UCAM_OK != nErrCode)
		return FALSE;

	*pnMode = nLutmode;
	return TRUE;
}

BOOL CUSB::WriteLut(const int nIdx, const INFO_LUT_PARA* pLutList, const int nLen, BOOL bEeprom)
{
	const int nCount = GetEnableDeviceCount();
	if (nIdx >= nCount || NULL == pLutList || 1 > nLen)
		return FALSE;

	DWORD dwSensorType = USBSENSOR_UNKNOWN;
	GetSensorType(nIdx, &dwSensorType);

	unsigned short pLutBuffer[4096] = { 0, };

	for (int i = 0; i < nLen; i++)
	{
		const int nCount = pLutList[i].m_nPointLen;
		for (int j = 0; j < nCount; j++)
		{
			pLutBuffer[j] = (unsigned short)pLutList[i].m_PointList[j].y;
		}

		UCamSaveLUTtoFlash((char)m_pstUSBDevInfo[nIdx].m_stUsbDevInfo.Index, pLutList[i].m_nIndex, pLutBuffer);

		if (USBSENSOR_VGA_MONO_CMOSIS == dwSensorType ||
			USBSENSOR_4M_COLOR == dwSensorType)
		{
			UCamSaveLUTtoCamera((char)m_pstUSBDevInfo[nIdx].m_stUsbDevInfo.Index, pLutList[i].m_nIndex, pLutBuffer);
		}
	}

	int nErrCode = UCamReloadTable((char)m_pstUSBDevInfo[nIdx].m_stUsbDevInfo.Index, 0);
	if (UCAM_OK != nErrCode)
		return FALSE;

	return TRUE;
}


// Effect
BOOL CUSB::SetEffectDPC(const int nIdx, unsigned short nEffect)
{
	const int nCount = GetEnableDeviceCount();
	if (nIdx >= nCount)
		return FALSE;

	int nErrCode = UCamSetDPCMode((char)m_pstUSBDevInfo[nIdx].m_stUsbDevInfo.Index, nEffect);
	if (UCAM_OK != nErrCode)
		return FALSE;

	return TRUE;
}
BOOL CUSB::GetEffectDPC(const int nIdx, unsigned short* pnEffect)
{
	const int nCount = GetEnableDeviceCount();
	if (nIdx >= nCount || NULL == pnEffect)
		return FALSE;

	unsigned short nDPCmode = 0;

	int nErrCode = UCamGetDPCMode((char)m_pstUSBDevInfo[nIdx].m_stUsbDevInfo.Index, &nDPCmode);
	if (UCAM_OK != nErrCode)
		return FALSE;

	*pnEffect = nDPCmode;
	return TRUE;
}

BOOL CUSB::SetEffectSharpen(const int nIdx, unsigned short nEffect)
{
	const int nCount = GetEnableDeviceCount();
	if (nIdx >= nCount)
		return FALSE;

	int nErrCode = UCamSetSharpening((char)m_pstUSBDevInfo[nIdx].m_stUsbDevInfo.Index, nEffect);
	if (UCAM_OK != nErrCode)
		return FALSE;

	return TRUE;
}
BOOL CUSB::GetEffectSharpen(const int nIdx, unsigned short* pnEffect)
{
	const int nCount = GetEnableDeviceCount();
	if (nIdx >= nCount || NULL == pnEffect)
		return FALSE;

	unsigned short nSharpeningCmode = 0;

	int nErrCode = UCamGetSharpening((char)m_pstUSBDevInfo[nIdx].m_stUsbDevInfo.Index, &nSharpeningCmode);
	if (UCAM_OK != nErrCode)
		return FALSE;

	*pnEffect = nSharpeningCmode;
	return TRUE;
}

BOOL CUSB::SetEffectFPN(const int nIdx, unsigned short nEffect)
{
	const int nCount = GetEnableDeviceCount();
	if (nIdx >= nCount)
		return FALSE;

	int nErrCode = UCamSetFPN((char)m_pstUSBDevInfo[nIdx].m_stUsbDevInfo.Index, nEffect);
	if (UCAM_OK != nErrCode)
		return FALSE;

	return TRUE;
}
BOOL CUSB::GetEffectFPN(const int nIdx, unsigned short* pnEffect)
{
	const int nCount = GetEnableDeviceCount();
	if (nIdx >= nCount || NULL == pnEffect)
		return FALSE;

	unsigned short nFPNVal = 0;

	int nErrCode = UCamGetFPN((char)m_pstUSBDevInfo[nIdx].m_stUsbDevInfo.Index, &nFPNVal);
	if (UCAM_OK != nErrCode)
		return FALSE;

	*pnEffect = nFPNVal;
	return TRUE;
}

BOOL CUSB::SetEffectPRNU(const int nIdx, unsigned short nEffect)
{
	const int nCount = GetEnableDeviceCount();
	if (nIdx >= nCount)
		return FALSE;

	int nErrCode = UCamSetPRNUMode((char)m_pstUSBDevInfo[nIdx].m_stUsbDevInfo.Index, nEffect);
	if (UCAM_OK != nErrCode)
		return FALSE;

	return TRUE;
}
BOOL CUSB::GetEffectPRNU(const int nIdx, unsigned short* pnEffect)
{
	const int nCount = GetEnableDeviceCount();
	if (nIdx >= nCount || NULL == pnEffect)
		return FALSE;

	unsigned short nPRNUval = 0;

	int nErrCode = UCamGetPRNUMode((char)m_pstUSBDevInfo[nIdx].m_stUsbDevInfo.Index, &nPRNUval);
	if (UCAM_OK != nErrCode)
		return FALSE;

	*pnEffect = nPRNUval;
	return TRUE;
}
