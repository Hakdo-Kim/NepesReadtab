#include "StdAfx.h"
#include "Command.h"

CCommand::CCommand()
{
	;
}

CCommand::~CCommand()
{
	;
}

void CCommand::MakeArgument(INFO_ARGUMENT& stArg, TYPE_ARGUMENT eType, TYPE_OPCODE eOpcode, void* pIn, int nInLen, void* pOut, int nOutLen)
{
	memset(&stArg, 0x00, sizeof(INFO_ARGUMENT));

	stArg.m_eType	= eType;
	stArg.m_eOpcode	= eOpcode;

	stArg.m_pIn		= pIn;
	stArg.m_nInLen	= nInLen;
	stArg.m_pOut	= pOut;
	stArg.m_nOutLen	= nOutLen;


}