#ifndef __LP_VIEWER_DEFINE_COMMAND_H__
#define __LP_VIEWER_DEFINE_COMMAND_H__


#define MAX_REQUEST_BUFFER_LEN			1024
#define MAX_REPONSE_BUFFER_LEN			1024


typedef enum
{
	TYPE_ARGUMENT_NONE,

	TYPE_ARGUMENT_BROADCAST,	// Ethernet
	
	TYPE_ARGUMENT_WIDTH,
	TYPE_ARGUMENT_HEIGHT,

	TYPE_ARGUMENT_MAX_WIDTH,
	TYPE_ARGUMENT_MAX_HEIGHT,

	TYPE_ARGUMENT_PIXEL_FORMAT,





	TYPE_ARGUMENT_MAX,

} TYPE_ARGUMENT;


typedef enum
{
	TYPE_OPCODE_NONE,

	TYPE_OPCODE_READ,
	TYPE_OPCODE_WRITE,
	TYPE_OPCODE_COMMAND,

	TYPE_OPCODE_MAX,

} TYPE_OPCODE;


typedef struct
{
	TYPE_ARGUMENT	m_eType;
	TYPE_OPCODE		m_eOpcode;

	void*	m_pIn;
	int		m_nInLen;

	void*	m_pOut;
	int		m_nOutLen;

} INFO_ARGUMENT;


typedef struct
{
	// Request Buffer
	BYTE		m_Request[MAX_REQUEST_BUFFER_LEN];
	DWORD		m_dwRequestLen;

	// Response Buffer
	BOOL		m_bNoResponse;

	BYTE		m_Reponse[MAX_REPONSE_BUFFER_LEN];
	DWORD		m_dwReponseLen;

	DWORD		m_dwWaitTime;		//msec


} INFO_COMMAND;





#endif