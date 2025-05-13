#include "StdAfx.h"
#include "CommandEthernet.h"

#include "ProtocolEthernet.h"

CCommandEthernet::CCommandEthernet()
{
	;
}

CCommandEthernet::~CCommandEthernet()
{
	;
}


BOOL CCommandEthernet::MuxCommand(const INFO_ARGUMENT& stArg, INFO_COMMAND& stCommand)
{
	BOOL bResult = FALSE;

	memset(&stCommand, 0x00, sizeof(INFO_COMMAND));

	stCommand.m_bNoResponse	= FALSE;
	stCommand.m_dwWaitTime	= 0;

	stCommand.m_dwRequestLen	= MAX_REQUEST_BUFFER_LEN;
	stCommand.m_dwReponseLen	= MAX_REPONSE_BUFFER_LEN;

	if(TYPE_ARGUMENT_BROADCAST==stArg.m_eType)
	{
		bResult = MuxCommandBroadcast(stArg, stCommand);
	}


	return bResult;
}
BOOL CCommandEthernet::DemuxCommand(INFO_ARGUMENT& stArg, const INFO_COMMAND& stCommand)
{
	BOOL bResult = FALSE;

	if(TYPE_ARGUMENT_BROADCAST==stArg.m_eType)
	{
		bResult = DemuxCommandBroadcast(stArg, stCommand);
	}


	return bResult;
}



BOOL CCommandEthernet::MuxCommandBroadcast(const INFO_ARGUMENT& stArg, INFO_COMMAND& stCommand)
{
	BOOL bResult = FALSE;
	int nIdx = 0;

	if(TYPE_OPCODE_READ==stArg.m_eOpcode)
	{
	}
	else if(TYPE_OPCODE_WRITE==stArg.m_eOpcode)
	{
	}
	else if(TYPE_OPCODE_COMMAND==stArg.m_eOpcode)
	{
		stCommand.m_bNoResponse	= TRUE;

		DWORD dwValue = LPBR_CMD_HEADER_STARTMARKER;
		memcpy( &stCommand.m_Request[nIdx], &dwValue, sizeof(DWORD)); nIdx+=sizeof(DWORD);

		stCommand.m_Request[nIdx] = 'L';		nIdx++;
		stCommand.m_Request[nIdx] = 'P';		nIdx++;
		stCommand.m_Request[nIdx] = 'B';		nIdx++;
		stCommand.m_Request[nIdx] = 'R';		nIdx++;

		stCommand.m_dwRequestLen = nIdx;

		bResult = TRUE;
	}

	return bResult;
}
BOOL CCommandEthernet::DemuxCommandBroadcast(INFO_ARGUMENT& stArg, const INFO_COMMAND& stCommand)
{
	BOOL bResult = FALSE;

	if(TYPE_OPCODE_READ==stArg.m_eOpcode)
	{
	}
	else if(TYPE_OPCODE_WRITE==stArg.m_eOpcode)
	{
	}
	else if(TYPE_OPCODE_COMMAND==stArg.m_eOpcode)
	{
	}

	return bResult;
}


BOOL CCommandEthernet::MuxCommandWidth(const INFO_ARGUMENT& stArg, INFO_COMMAND& stCommand)
{
	BOOL bResult = FALSE;

	if(TYPE_OPCODE_READ==stArg.m_eOpcode)
	{
	}
	else if(TYPE_OPCODE_WRITE==stArg.m_eOpcode)
	{
	}
	else if(TYPE_OPCODE_COMMAND==stArg.m_eOpcode)
	{
	}

	return bResult;
}
BOOL CCommandEthernet::DemuxCommandWidth(INFO_ARGUMENT& stArg, const INFO_COMMAND& stCommand)
{
	BOOL bResult = FALSE;

	if(TYPE_OPCODE_READ==stArg.m_eOpcode)
	{
	}
	else if(TYPE_OPCODE_WRITE==stArg.m_eOpcode)
	{
	}
	else if(TYPE_OPCODE_COMMAND==stArg.m_eOpcode)
	{
	}

	return bResult;
}


BOOL CCommandEthernet::MuxCommandHeight(const INFO_ARGUMENT& stArg, INFO_COMMAND& stCommand)
{
	BOOL bResult = FALSE;

	if(TYPE_OPCODE_READ==stArg.m_eOpcode)
	{
	}
	else if(TYPE_OPCODE_WRITE==stArg.m_eOpcode)
	{
	}
	else if(TYPE_OPCODE_COMMAND==stArg.m_eOpcode)
	{
	}

	return bResult;
}
BOOL CCommandEthernet::DemuxCommandHeight(INFO_ARGUMENT& stArg, const INFO_COMMAND& stCommand)
{
	BOOL bResult = FALSE;

	if(TYPE_OPCODE_READ==stArg.m_eOpcode)
	{
	}
	else if(TYPE_OPCODE_WRITE==stArg.m_eOpcode)
	{
	}
	else if(TYPE_OPCODE_COMMAND==stArg.m_eOpcode)
	{
	}

	return bResult;
}


BOOL CCommandEthernet::MuxCommandMaxWidth(const INFO_ARGUMENT& stArg, INFO_COMMAND& stCommand)
{
	BOOL bResult = FALSE;

	if(TYPE_OPCODE_READ==stArg.m_eOpcode)
	{
	}
	else if(TYPE_OPCODE_WRITE==stArg.m_eOpcode)
	{
	}
	else if(TYPE_OPCODE_COMMAND==stArg.m_eOpcode)
	{
	}

	return bResult;
}
BOOL CCommandEthernet::DemuxCommandMaxWidth(INFO_ARGUMENT& stArg, const INFO_COMMAND& stCommand)
{
	BOOL bResult = FALSE;

	if(TYPE_OPCODE_READ==stArg.m_eOpcode)
	{
	}
	else if(TYPE_OPCODE_WRITE==stArg.m_eOpcode)
	{
	}
	else if(TYPE_OPCODE_COMMAND==stArg.m_eOpcode)
	{
	}

	return bResult;
}


BOOL CCommandEthernet::MuxCommandMaxHeight(const INFO_ARGUMENT& stArg, INFO_COMMAND& stCommand)
{
	BOOL bResult = FALSE;

	if(TYPE_OPCODE_READ==stArg.m_eOpcode)
	{
	}
	else if(TYPE_OPCODE_WRITE==stArg.m_eOpcode)
	{
	}
	else if(TYPE_OPCODE_COMMAND==stArg.m_eOpcode)
	{
	}

	return bResult;
}
BOOL CCommandEthernet::DemuxCommandMaxHeight(INFO_ARGUMENT& stArg, const INFO_COMMAND& stCommand)
{
	BOOL bResult = FALSE;

	if(TYPE_OPCODE_READ==stArg.m_eOpcode)
	{
	}
	else if(TYPE_OPCODE_WRITE==stArg.m_eOpcode)
	{
	}
	else if(TYPE_OPCODE_COMMAND==stArg.m_eOpcode)
	{
	}

	return bResult;
}


BOOL CCommandEthernet::MuxCommandPixelFormat(const INFO_ARGUMENT& stArg, INFO_COMMAND& stCommand)
{
	BOOL bResult = FALSE;

	if(TYPE_OPCODE_READ==stArg.m_eOpcode)
	{
	}
	else if(TYPE_OPCODE_WRITE==stArg.m_eOpcode)
	{
	}
	else if(TYPE_OPCODE_COMMAND==stArg.m_eOpcode)
	{
	}

	return bResult;
}
BOOL CCommandEthernet::DemuxCommandPixelFormat(INFO_ARGUMENT& stArg, const INFO_COMMAND& stCommand)
{
	BOOL bResult = FALSE;

	if(TYPE_OPCODE_READ==stArg.m_eOpcode)
	{
	}
	else if(TYPE_OPCODE_WRITE==stArg.m_eOpcode)
	{
	}
	else if(TYPE_OPCODE_COMMAND==stArg.m_eOpcode)
	{
	}

	return bResult;
}



