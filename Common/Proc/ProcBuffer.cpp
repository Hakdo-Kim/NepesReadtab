
#include "StdAfx.h"
#include "ProcBuffer.h"

CProcBuffer::CProcBuffer()
{
	::InitializeCriticalSection(&m_CriticalSection);
	m_nIndex = -1;
	
}

CProcBuffer::~CProcBuffer()
{
	DestoryBuffer();

	//
	::DeleteCriticalSection(&m_CriticalSection);
}

BOOL CProcBuffer::CreateBuffer(const INFO_FRAME* pstFrame, const int nMaxCount)
{
	if (NULL == pstFrame || 1 > nMaxCount)
		return FALSE;

	::EnterCriticalSection(&m_CriticalSection);
	DestoryBuffer();

	{
		INFO_IMAGE* pImageInfo = NULL;

		int nBit = 8;
		if (TYPE_DATABIT_08 == pstFrame->m_eDataBit)		nBit = 8;
		else if (TYPE_DATABIT_12 == pstFrame->m_eDataBit)	nBit = 12;
		else if (TYPE_DATABIT_16 == pstFrame->m_eDataBit)	nBit = 16;
		else if (TYPE_DATABIT_24 == pstFrame->m_eDataBit)	nBit = 24;
		else if (TYPE_DATABIT_32 == pstFrame->m_eDataBit)	nBit = 32;
		else if (TYPE_DATABIT_36 == pstFrame->m_eDataBit)	nBit = 36;
		else if (TYPE_DATABIT_48 == pstFrame->m_eDataBit)	nBit = 48;

		int nByte = nBit / 8;
		if (nBit % 8)
			nByte++;

		const int nBufferSize = pstFrame->m_dwMaxPitch * pstFrame->m_dwMaxHeight;
		for (int i = 0; i < nMaxCount; i++)
		{
			pImageInfo = new INFO_IMAGE;
			memset(pImageInfo, 0x00, sizeof(INFO_IMAGE));
			memcpy(&(pImageInfo->m_stFrame), pstFrame, sizeof(INFO_FRAME));

			pImageInfo->m_eFrameState = TYPE_FRAMESTATE_NONE;
			pImageInfo->m_pBuffer = new BYTE[nBufferSize];
			if (pImageInfo->m_pBuffer)
			{
				pImageInfo->m_nBufLen = nBufferSize;
				pImageInfo->m_nLen = nBufferSize;
				memset(pImageInfo->m_pBuffer, 0x00, sizeof(BYTE)*nBufferSize);
			}
			m_BufferList.push_back(pImageInfo);
		}

		m_nIndex = 0;
		m_bEnable = TRUE;
	}
	::LeaveCriticalSection(&m_CriticalSection);

	return TRUE;
}

BOOL CProcBuffer::CreateBuffer(const int nMaxCount)
{
	if (1 > nMaxCount)
		return FALSE;

	::EnterCriticalSection(&m_CriticalSection);
	DestoryBuffer();

	{
		INFO_IMAGE* pImageInfo = NULL;

		for (int i = 0; i < nMaxCount; i++)
		{
			pImageInfo = new INFO_IMAGE;
			memset(pImageInfo, 0x00, sizeof(INFO_IMAGE));

			m_BufferList.push_back(pImageInfo);
		}

		m_nIndex = 0;
		m_bEnable = TRUE;
	}
	::LeaveCriticalSection(&m_CriticalSection);

	return TRUE;
}

void CProcBuffer::DestoryBuffer()
{
	::EnterCriticalSection(&m_CriticalSection);
	{
		const int nSize = m_BufferList.size();
		for (int i = 0; i < nSize; i++)
		{
			if (NULL == m_BufferList[i])
				continue;

			if (m_BufferList[i]->m_pBuffer)
				delete[] m_BufferList[i]->m_pBuffer;
			if (m_BufferList[i]->m_pReserved)
				delete m_BufferList[i]->m_pReserved;

			delete m_BufferList[i];
		}

		m_BufferList.clear();

		m_nIndex = 0;
		m_bEnable = FALSE;
	}
	::LeaveCriticalSection(&m_CriticalSection);
}

void CProcBuffer::ResetBuffer()
{
	::EnterCriticalSection(&m_CriticalSection);
	{
		const int nSize = m_BufferList.size();
		for (int i = 0; i < nSize; i++)
		{
			m_BufferList[i]->m_eFrameState = TYPE_FRAMESTATE_NONE;
		}

		m_nIndex = 0;
	}
	::LeaveCriticalSection(&m_CriticalSection);

}


INFO_IMAGE* CProcBuffer::AllocBuffer(const int nMininum)
{
	const int nSize = m_BufferList.size();
	if (1 > nSize || 0 > m_nIndex || nSize <= m_nIndex)
		return NULL;

	INFO_IMAGE* pInfo = NULL;

	::EnterCriticalSection(&m_CriticalSection);
	{
		pInfo = m_BufferList[m_nIndex];
		if (TYPE_FRAMESTATE_NONE != pInfo->m_eFrameState)
		{
			::LeaveCriticalSection(&m_CriticalSection);
			return NULL;
		}
		pInfo->m_eFrameState = TYPE_FRAMESTATE_READ;

		// Check Minimum Length
		if (-1 != nMininum)
		{
			if (nMininum > pInfo->m_nBufLen)
			{
				if (pInfo->m_pBuffer)
					delete[] pInfo->m_pBuffer;
				pInfo->m_pBuffer = new BYTE[nMininum];
				if (pInfo->m_pBuffer)
				{
					pInfo->m_nBufLen = nMininum;
					pInfo->m_nLen = nMininum;
				}
				else
				{
					pInfo->m_nBufLen = 0;
					pInfo->m_nLen = 0;
				}
			}
		}

		m_nIndex++;
		if (m_nIndex >= nSize)
			m_nIndex = 0;
	}
	::LeaveCriticalSection(&m_CriticalSection);

	return pInfo;
}

void CProcBuffer::ReleaseBuffer(INFO_IMAGE* pstBuf)
{
	if (NULL == pstBuf)
		return;

	::EnterCriticalSection(&m_CriticalSection);
	{
		pstBuf->m_eFrameState = TYPE_FRAMESTATE_NONE;
	}
	::LeaveCriticalSection(&m_CriticalSection);
}


BOOL CProcBuffer::IsEnable()
{
	return m_bEnable;
}