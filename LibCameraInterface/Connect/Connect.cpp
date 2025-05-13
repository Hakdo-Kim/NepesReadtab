
#include "StdAfx.h"
#include "Connect.h"

CConnect::CConnect()
{
	::InitializeCriticalSection(&m_CriticalSection);
	m_eNetwork = TYPE_NETWORK_NONE;
	
}

CConnect::~CConnect()
{
	::DeleteCriticalSection(&m_CriticalSection);
}

const TYPE_NETWORK CConnect::GetNetworkType()
{
	return m_eNetwork;
}

void CConnect::EnterCriticalSection()
{
	::EnterCriticalSection(&m_CriticalSection);
}
void CConnect::LeaveCriticalSection()
{
	::LeaveCriticalSection(&m_CriticalSection);
}