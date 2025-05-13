#ifndef __LP_VIEWER_COMMAND_H__
#define __LP_VIEWER_COMMAND_H__

#include "DefineCommand.h"

class CCommand
{
public:
	CCommand();
	~CCommand();

	virtual void MakeArgument(INFO_ARGUMENT& stArg, TYPE_ARGUMENT eType, TYPE_OPCODE eOpcode, void* pIn, int nInLen, void* pOut, int nOutLen);


	virtual BOOL MuxCommand(const INFO_ARGUMENT& stArg, INFO_COMMAND& stCommand)	= 0;
	virtual BOOL DemuxCommand(INFO_ARGUMENT& stArg, const INFO_COMMAND& stCommand)	= 0;


};




#endif