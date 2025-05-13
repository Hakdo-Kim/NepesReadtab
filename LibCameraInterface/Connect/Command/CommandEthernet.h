#ifndef __LP_VIEWER_COMMAND_ETHERNET_H__
#define __LP_VIEWER_COMMAND_ETHERNET_H__

#include "Command.h"

class CCommandEthernet: public CCommand
{
public:
	CCommandEthernet();
	~CCommandEthernet();


	virtual BOOL MuxCommand(const INFO_ARGUMENT& stArg, INFO_COMMAND& stCommand);
	virtual BOOL DemuxCommand(INFO_ARGUMENT& stArg, const INFO_COMMAND& stCommand);


protected:

	BOOL MuxCommandBroadcast(const INFO_ARGUMENT& stArg, INFO_COMMAND& stCommand);
	BOOL DemuxCommandBroadcast(INFO_ARGUMENT& stArg, const INFO_COMMAND& stCommand);


	BOOL MuxCommandWidth(const INFO_ARGUMENT& stArg, INFO_COMMAND& stCommand);
	BOOL DemuxCommandWidth(INFO_ARGUMENT& stArg, const INFO_COMMAND& stCommand);

	BOOL MuxCommandHeight(const INFO_ARGUMENT& stArg, INFO_COMMAND& stCommand);
	BOOL DemuxCommandHeight(INFO_ARGUMENT& stArg, const INFO_COMMAND& stCommand);

	BOOL MuxCommandMaxWidth(const INFO_ARGUMENT& stArg, INFO_COMMAND& stCommand);
	BOOL DemuxCommandMaxWidth(INFO_ARGUMENT& stArg, const INFO_COMMAND& stCommand);

	BOOL MuxCommandMaxHeight(const INFO_ARGUMENT& stArg, INFO_COMMAND& stCommand);
	BOOL DemuxCommandMaxHeight(INFO_ARGUMENT& stArg, const INFO_COMMAND& stCommand);

	BOOL MuxCommandPixelFormat(const INFO_ARGUMENT& stArg, INFO_COMMAND& stCommand);
	BOOL DemuxCommandPixelFormat(INFO_ARGUMENT& stArg, const INFO_COMMAND& stCommand);
	



};




#endif