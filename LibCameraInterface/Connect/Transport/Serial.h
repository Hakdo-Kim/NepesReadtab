#pragma once


#include "SerialDef.h"


#define SERIAL_OVERLAPPED
#ifdef SERIAL_OVERLAPPED
#define SERIAL_DEFAULT_OVERLAPPED			true
#else
#define SERIAL_DEFAULT_OVERLAPPED			false
#endif


// Communication event
typedef enum
{
	EEVENT_UNKNOWN		= -1,				// Unknown event
	EEVENT_NONE			= 0,				// Event trigged without cause
	EEVENT_BREK			= EV_BREAK,			// A break was detected on input
	EEVENT_CTS			= EV_CTS,			// The CTS signal changed state
	EEVENT_DSR			= EV_DSR,			// The DSR signal changed state
	EEVENT_ERROR		= EV_ERR,			// A line-status error occurred
	EEVENT_RING			= EV_RING,			// A ring indicator was detected
	EEVENT_RLSD			= EV_RLSD,			// The RLSD signal changed state
	EEVENT_RXCHAR		= EV_RXCHAR,		// Data is received on input
	EEVENT_RXFLAG		= EV_RXFLAG,		// Event character was received on input
	EEVENT_TXEMPTY		= EV_TXEMPTY,		// Last character on output was sent
	EEVENT_PRINTERR		= EV_PERR,			// Printer error occured
	EEVENT_RX80FULL		= EV_RX80FULL,		// Receive buffer is 80 percent full
	EEVENT_EVENT1		= EV_EVENT1,		// Provider specific event 1
	EEVENT_EVENT2		= EV_EVENT2,		// Provider specific event 2
} EEVENT;

// Baudrate
typedef enum
{
	EBAUDRATE_UNKNOWN	= -1,				// Unknown
	EBAUDRATE_110		= CBR_110,			// 110 bits/sec
	EBAUDRATE_300		= CBR_300,			// 300 bits/sec
	EBAUDRATE_600		= CBR_600,			// 600 bits/sec
	EBAUDRATE_1200		= CBR_1200,			// 1200 bits/sec
	EBAUDRATE_2400		= CBR_2400,			// 2400 bits/sec
	EBAUDRATE_4800		= CBR_4800,			// 4800 bits/sec
	EBAUDRATE_9600		= CBR_9600,			// 9600 bits/sec
	EBAUDRATE_14400		= CBR_14400,		// 14400 bits/sec
	EBAUDRATE_19200		= CBR_19200,		// 19200 bits/sec (default)
	EBAUDRATE_38400		= CBR_38400,		// 38400 bits/sec
	EBAUDRATE_56000		= CBR_56000,		// 56000 bits/sec
	EBAUDRATE_57600		= CBR_57600,		// 57600 bits/sec
	EBAUDRATE_115200	= CBR_115200,		// 115200 bits/sec
	EBAUDRATE_128000	= CBR_128000,		// 128000 bits/sec
	EBAUDRATE_256000	= CBR_256000,		// 256000 bits/sec
} EBAUDRATE;

// Data bits (5-8)
typedef enum
{
	EDATABITS_UNKNOWN	= -1,				// Unknown
	EDATABITS_5			= 5,				// 5 bits per byte
	EDATABITS_6			= 6,				// 6 bits per byte
	EDATABITS_7			= 7,				// 7 bits per byte
	EDATABITS_8			= 8					// 8 bits per byte (default)
} EDATABITS;

// Parity scheme
typedef enum
{
	EPARITY_UNKNOWN		= -1,				// Unknown
	EPARITY_NONE		= NOPARITY,			// No parity (default)
	EPARITY_ODD			= ODDPARITY,		// Odd parity
	EPARITY_EVEN		= EVENPARITY,		// Even parity
	EPARITY_MARK		= MARKPARITY,		// Mark parity
	EPARITY_SPACE		= SPACEPARITY		// Space parity
} EPARITY;

// Stop bits
typedef enum
{
	ESTOPBITS_UNKNOWN	= -1,				// Unknown
	ESTOPBITS_1			= ONESTOPBIT,		// 1 stopbit (default)
	ESTOPBITS_1_5		= ONE5STOPBITS,		// 1.5 stopbit
	ESTOPBITS_2			= TWOSTOPBITS		// 2 stopbits
} ESTOPBITS;

// Handshaking
typedef enum
{
	EHANDSHAKE_UNKNOWN	= -1,				// Unknown
	EHANDSHAKE_OFF		=  0,				// No handshaking
	EHANDSHAKE_HARDWARE	=  1,				// Hardware handshaking (RTS/CTS)
	EHANDSHAKE_SOFTWARE	=  2				// Software handshaking (XON/XOFF)
} EHANDSHAKE;

// Timeout settings
typedef enum
{
	EREADTIMEOUT_UNKNOWN	= -1,			// Unknown
	EREADTIMEOUT_NONBLOCK	=  0,			// Always return immediately
	EREADTIMEOUT_BLOCK		=  1			// Block until everything is retrieved
} EREADTIMEOUT;

// Communication errors
typedef enum
{
	EERROR_UNKNOWN			= 0,			// Unknown
	EERROR_BREAK			= CE_BREAK,		// Break condition detected
	EERROR_FRAME			= CE_FRAME,		// Framing error
	EERROR_IOE				= CE_IOE,		// I/O device error
	EERROR_MODE				= CE_MODE,		// Unsupported mode
	EERROR_OVERRUN			= CE_OVERRUN,	// Character buffer overrun, next byte is lost
	EERROR_RXOVER			= CE_RXOVER,	// Input buffer overflow, byte lost
	EERROR_PARITY			= CE_RXPARITY,	// Input parity error
	EERROR_TXFULL			= CE_TXFULL		// Output buffer full
} EERROR;

// Port availability
typedef enum
{
	EPORT_UNKNOWNERR		= -1,		// Unknown error occurred
	EPORT_AVAILABLE			=  0,		// Port is available
	EPORT_NOTAVAILABLE		=  1,		// Port is not present
	EPORT_INUSE				=  2		// Port is in use

} EPORT;

class CSerial
{

public:
	CSerial();
	virtual ~CSerial();

	// Attributes
protected:
	DWORD	m_dwLastError;		// Last serial error
	
	HANDLE	m_hFile;			// File handle
	EEVENT	m_eEvent;			// Event type
	DWORD	m_dwEventMask;		// Event mask

#ifdef SERIAL_OVERLAPPED
	HANDLE	m_hOverlapped;	// Event handle for internal overlapped operations
#endif

public:

	DWORD	GetLastError ();

	BOOL	IsOpen ();

	DWORD	Open (LPCTSTR lpszDevice, 
					DWORD dwInQueue	= 0,
					DWORD dwOutQueue = 0,
					BOOL bOverlapped = SERIAL_DEFAULT_OVERLAPPED);
	DWORD	Close ();

	DWORD	Set (EBAUDRATE eBaudrate = EBAUDRATE_115200,
					EDATABITS eDataBits = EDATABITS_8,
					EPARITY   eParity   = EPARITY_NONE,
					ESTOPBITS eStopBits = ESTOPBITS_1);
	DWORD	SetEventMask (DWORD dwEventMask = EEVENT_BREK|EEVENT_ERROR|EEVENT_RXCHAR);
	DWORD	SetReadTimeouts (EREADTIMEOUT eTimeout);


	DWORD	Write (const void* pData, DWORD dwLen, DWORD* pdwWritten = 0, LPOVERLAPPED lpOverlapped = 0, DWORD dwTimeout = INFINITE);
	DWORD	Read (void* pData, DWORD dwLen, DWORD* pdwRead = 0, LPOVERLAPPED lpOverlapped = 0, DWORD dwTimeout = INFINITE);

	BOOL	CancelIo();
	

	DWORD	Purge ();
	DWORD	Break ();

	HANDLE	GetHandle();


	static EPORT CheckPort(LPCTSTR pszCom);
	static int SearchSerialPort(SERIALPORT_INFO* pstInfo, const int nLen);

protected:
	static int SearchSerialPortWin9x(SERIALPORT_INFO* pstInfo, const int nLen);
	static int SearchSerialPortWin2000(SERIALPORT_INFO* pstInfo, const int nLen);

	static int SearchSerialPort(LPCTSTR lpszEnumPath, SERIALPORT_INFO* pstInfo, const int nLen);


};
