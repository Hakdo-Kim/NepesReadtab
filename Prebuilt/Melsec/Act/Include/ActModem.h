/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 5.01.0164 */
/* at Fri Apr 12 12:33:23 2013
 */
/* Compiler settings for D:\GETMODULE\CommunicationSupport2\SW3D5\ACT\Control\ActModem\ActModem.idl:
    Oicf (OptLev=i2), W1, Zp8, env=Win32, ms_ext, c_ext
    error checks: allocation ref bounds_check enum stub_data 
*/
//@@MIDL_FILE_HEADING(  )


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 440
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif // __RPCNDR_H_VERSION__

#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif /*COM_NO_WINDOWS_H*/

#ifndef __ActModem_h__
#define __ActModem_h__

#ifdef __cplusplus
extern "C"{
#endif 

/* Forward Declarations */ 

#ifndef __IActA6TEL_FWD_DEFINED__
#define __IActA6TEL_FWD_DEFINED__
typedef interface IActA6TEL IActA6TEL;
#endif 	/* __IActA6TEL_FWD_DEFINED__ */


#ifndef __IActA6TEL2_FWD_DEFINED__
#define __IActA6TEL2_FWD_DEFINED__
typedef interface IActA6TEL2 IActA6TEL2;
#endif 	/* __IActA6TEL2_FWD_DEFINED__ */


#ifndef __IActA6TEL3_FWD_DEFINED__
#define __IActA6TEL3_FWD_DEFINED__
typedef interface IActA6TEL3 IActA6TEL3;
#endif 	/* __IActA6TEL3_FWD_DEFINED__ */


#ifndef __IActQ6TEL_FWD_DEFINED__
#define __IActQ6TEL_FWD_DEFINED__
typedef interface IActQ6TEL IActQ6TEL;
#endif 	/* __IActQ6TEL_FWD_DEFINED__ */


#ifndef __IActQ6TEL2_FWD_DEFINED__
#define __IActQ6TEL2_FWD_DEFINED__
typedef interface IActQ6TEL2 IActQ6TEL2;
#endif 	/* __IActQ6TEL2_FWD_DEFINED__ */


#ifndef __IActQ6TEL3_FWD_DEFINED__
#define __IActQ6TEL3_FWD_DEFINED__
typedef interface IActQ6TEL3 IActQ6TEL3;
#endif 	/* __IActQ6TEL3_FWD_DEFINED__ */


#ifndef __IActFXCPUTEL_FWD_DEFINED__
#define __IActFXCPUTEL_FWD_DEFINED__
typedef interface IActFXCPUTEL IActFXCPUTEL;
#endif 	/* __IActFXCPUTEL_FWD_DEFINED__ */


#ifndef __IActFXCPUTEL2_FWD_DEFINED__
#define __IActFXCPUTEL2_FWD_DEFINED__
typedef interface IActFXCPUTEL2 IActFXCPUTEL2;
#endif 	/* __IActFXCPUTEL2_FWD_DEFINED__ */


#ifndef __IActFXCPUTEL3_FWD_DEFINED__
#define __IActFXCPUTEL3_FWD_DEFINED__
typedef interface IActFXCPUTEL3 IActFXCPUTEL3;
#endif 	/* __IActFXCPUTEL3_FWD_DEFINED__ */


#ifndef __IActAJ71QC24TEL_FWD_DEFINED__
#define __IActAJ71QC24TEL_FWD_DEFINED__
typedef interface IActAJ71QC24TEL IActAJ71QC24TEL;
#endif 	/* __IActAJ71QC24TEL_FWD_DEFINED__ */


#ifndef __IActAJ71QC24TEL2_FWD_DEFINED__
#define __IActAJ71QC24TEL2_FWD_DEFINED__
typedef interface IActAJ71QC24TEL2 IActAJ71QC24TEL2;
#endif 	/* __IActAJ71QC24TEL2_FWD_DEFINED__ */


#ifndef __IActAJ71QC24TEL3_FWD_DEFINED__
#define __IActAJ71QC24TEL3_FWD_DEFINED__
typedef interface IActAJ71QC24TEL3 IActAJ71QC24TEL3;
#endif 	/* __IActAJ71QC24TEL3_FWD_DEFINED__ */


#ifndef __IActQJ71C24TEL_FWD_DEFINED__
#define __IActQJ71C24TEL_FWD_DEFINED__
typedef interface IActQJ71C24TEL IActQJ71C24TEL;
#endif 	/* __IActQJ71C24TEL_FWD_DEFINED__ */


#ifndef __IActQJ71C24TEL2_FWD_DEFINED__
#define __IActQJ71C24TEL2_FWD_DEFINED__
typedef interface IActQJ71C24TEL2 IActQJ71C24TEL2;
#endif 	/* __IActQJ71C24TEL2_FWD_DEFINED__ */


#ifndef __IActQJ71C24TEL3_FWD_DEFINED__
#define __IActQJ71C24TEL3_FWD_DEFINED__
typedef interface IActQJ71C24TEL3 IActQJ71C24TEL3;
#endif 	/* __IActQJ71C24TEL3_FWD_DEFINED__ */


#ifndef __IActLJ71C24TEL_FWD_DEFINED__
#define __IActLJ71C24TEL_FWD_DEFINED__
typedef interface IActLJ71C24TEL IActLJ71C24TEL;
#endif 	/* __IActLJ71C24TEL_FWD_DEFINED__ */


#ifndef __IActLJ71C24TEL2_FWD_DEFINED__
#define __IActLJ71C24TEL2_FWD_DEFINED__
typedef interface IActLJ71C24TEL2 IActLJ71C24TEL2;
#endif 	/* __IActLJ71C24TEL2_FWD_DEFINED__ */


#ifndef __IActLJ71C24TEL3_FWD_DEFINED__
#define __IActLJ71C24TEL3_FWD_DEFINED__
typedef interface IActLJ71C24TEL3 IActLJ71C24TEL3;
#endif 	/* __IActLJ71C24TEL3_FWD_DEFINED__ */


#ifndef ___IActA6TELEvents_FWD_DEFINED__
#define ___IActA6TELEvents_FWD_DEFINED__
typedef interface _IActA6TELEvents _IActA6TELEvents;
#endif 	/* ___IActA6TELEvents_FWD_DEFINED__ */


#ifndef __ActA6TEL_FWD_DEFINED__
#define __ActA6TEL_FWD_DEFINED__

#ifdef __cplusplus
typedef class ActA6TEL ActA6TEL;
#else
typedef struct ActA6TEL ActA6TEL;
#endif /* __cplusplus */

#endif 	/* __ActA6TEL_FWD_DEFINED__ */


#ifndef ___IActQ6TELEvents_FWD_DEFINED__
#define ___IActQ6TELEvents_FWD_DEFINED__
typedef interface _IActQ6TELEvents _IActQ6TELEvents;
#endif 	/* ___IActQ6TELEvents_FWD_DEFINED__ */


#ifndef __ActQ6TEL_FWD_DEFINED__
#define __ActQ6TEL_FWD_DEFINED__

#ifdef __cplusplus
typedef class ActQ6TEL ActQ6TEL;
#else
typedef struct ActQ6TEL ActQ6TEL;
#endif /* __cplusplus */

#endif 	/* __ActQ6TEL_FWD_DEFINED__ */


#ifndef ___IActFXCPUTELEvents_FWD_DEFINED__
#define ___IActFXCPUTELEvents_FWD_DEFINED__
typedef interface _IActFXCPUTELEvents _IActFXCPUTELEvents;
#endif 	/* ___IActFXCPUTELEvents_FWD_DEFINED__ */


#ifndef __ActFXCPUTEL_FWD_DEFINED__
#define __ActFXCPUTEL_FWD_DEFINED__

#ifdef __cplusplus
typedef class ActFXCPUTEL ActFXCPUTEL;
#else
typedef struct ActFXCPUTEL ActFXCPUTEL;
#endif /* __cplusplus */

#endif 	/* __ActFXCPUTEL_FWD_DEFINED__ */


#ifndef ___IActAJ71QC24TELEvents_FWD_DEFINED__
#define ___IActAJ71QC24TELEvents_FWD_DEFINED__
typedef interface _IActAJ71QC24TELEvents _IActAJ71QC24TELEvents;
#endif 	/* ___IActAJ71QC24TELEvents_FWD_DEFINED__ */


#ifndef __ActAJ71QC24TEL_FWD_DEFINED__
#define __ActAJ71QC24TEL_FWD_DEFINED__

#ifdef __cplusplus
typedef class ActAJ71QC24TEL ActAJ71QC24TEL;
#else
typedef struct ActAJ71QC24TEL ActAJ71QC24TEL;
#endif /* __cplusplus */

#endif 	/* __ActAJ71QC24TEL_FWD_DEFINED__ */


#ifndef ___IActQJ71C24TELEvents_FWD_DEFINED__
#define ___IActQJ71C24TELEvents_FWD_DEFINED__
typedef interface _IActQJ71C24TELEvents _IActQJ71C24TELEvents;
#endif 	/* ___IActQJ71C24TELEvents_FWD_DEFINED__ */


#ifndef __ActQJ71C24TEL_FWD_DEFINED__
#define __ActQJ71C24TEL_FWD_DEFINED__

#ifdef __cplusplus
typedef class ActQJ71C24TEL ActQJ71C24TEL;
#else
typedef struct ActQJ71C24TEL ActQJ71C24TEL;
#endif /* __cplusplus */

#endif 	/* __ActQJ71C24TEL_FWD_DEFINED__ */


#ifndef ___IActLJ71C24TELEvents_FWD_DEFINED__
#define ___IActLJ71C24TELEvents_FWD_DEFINED__
typedef interface _IActLJ71C24TELEvents _IActLJ71C24TELEvents;
#endif 	/* ___IActLJ71C24TELEvents_FWD_DEFINED__ */


#ifndef __ActLJ71C24TEL_FWD_DEFINED__
#define __ActLJ71C24TEL_FWD_DEFINED__

#ifdef __cplusplus
typedef class ActLJ71C24TEL ActLJ71C24TEL;
#else
typedef struct ActLJ71C24TEL ActLJ71C24TEL;
#endif /* __cplusplus */

#endif 	/* __ActLJ71C24TEL_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

void __RPC_FAR * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void __RPC_FAR * ); 

#ifndef __IActA6TEL_INTERFACE_DEFINED__
#define __IActA6TEL_INTERFACE_DEFINED__

/* interface IActA6TEL */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IActA6TEL;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("5713F072-6F4A-11D5-9315-009099244EFD")
    IActA6TEL : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Open( 
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Close( 
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetDevice( 
            /* [string][in] */ BSTR szDevice,
            /* [out] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetDevice( 
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ReadDeviceBlock( 
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lSize,
            /* [size_is][out] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE WriteDeviceBlock( 
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lSize,
            /* [size_is][in] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ReadDeviceRandom( 
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG lSize,
            /* [size_is][out] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE WriteDeviceRandom( 
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG lSize,
            /* [size_is][in] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ReadBuffer( 
            /* [in] */ LONG lStartIO,
            /* [in] */ LONG lAddress,
            /* [in] */ LONG lReadSize,
            /* [size_is][out] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE WriteBuffer( 
            /* [in] */ LONG lStartIO,
            /* [in] */ LONG lAddress,
            /* [in] */ LONG lWriteSize,
            /* [size_is][in] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetClockData( 
            /* [out] */ SHORT __RPC_FAR *lpsYear,
            /* [out] */ SHORT __RPC_FAR *lpsMonth,
            /* [out] */ SHORT __RPC_FAR *lpsDay,
            /* [out] */ SHORT __RPC_FAR *lpsDayOfWeek,
            /* [out] */ SHORT __RPC_FAR *lpsHour,
            /* [out] */ SHORT __RPC_FAR *lpsMinute,
            /* [out] */ SHORT __RPC_FAR *lpsSecond,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetClockData( 
            /* [in] */ SHORT sYear,
            /* [in] */ SHORT sMonth,
            /* [in] */ SHORT sDay,
            /* [in] */ SHORT sDayOfWeek,
            /* [in] */ SHORT sHour,
            /* [in] */ SHORT sMinute,
            /* [in] */ SHORT sSecond,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetCpuType( 
            /* [string][out] */ BSTR __RPC_FAR *szCpuName,
            /* [out] */ LONG __RPC_FAR *lplCpuCode,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetCpuStatus( 
            /* [in] */ LONG lOperation,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE CheckDeviceString( 
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lCheckType,
            /* [in] */ LONG lSize,
            /* [out] */ LONG __RPC_FAR *lplDeviceType,
            /* [string][out] */ BSTR __RPC_FAR *lpszDeviceName,
            /* [out] */ LONG __RPC_FAR *lplDeviceNumber,
            /* [out] */ LONG __RPC_FAR *lplDeviceRadix,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE EntryDeviceStatus( 
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG lSize,
            /* [in] */ LONG lMonitorCycle,
            /* [size_is][in] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE FreeDeviceStatus( 
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ReadDeviceBlock2( 
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lSize,
            /* [size_is][out] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE WriteDeviceBlock2( 
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lSize,
            /* [size_is][in] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ReadDeviceRandom2( 
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG lSize,
            /* [size_is][out] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE WriteDeviceRandom2( 
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG lSize,
            /* [size_is][in] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetDevice2( 
            /* [string][in] */ BSTR szDevice,
            /* [out] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetDevice2( 
            /* [string][in] */ BSTR szDevice,
            /* [in] */ SHORT sData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Connect( 
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Disconnect( 
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActNetworkNumber( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActNetworkNumber( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActStationNumber( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActStationNumber( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActCpuType( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActCpuType( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActPortNumber( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActPortNumber( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActTimeOut( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActTimeOut( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActATCommand( 
            /* [retval][out] */ BSTR __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActATCommand( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActDialNumber( 
            /* [retval][out] */ BSTR __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActDialNumber( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActLineType( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActLineType( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActPassword( 
            /* [retval][out] */ BSTR __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActPassword( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActConnectionCDWaitTime( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActConnectionCDWaitTime( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActConnectionModemReportWaitTime( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActConnectionModemReportWaitTime( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActDisconnectionCDWaitTime( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActDisconnectionCDWaitTime( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActDisconnectionDelayTime( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActDisconnectionDelayTime( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActTransmissionDelayTime( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActTransmissionDelayTime( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActATCommandResponseWaitTime( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActATCommandResponseWaitTime( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActATCommandPasswordCancelRetryTimes( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActATCommandPasswordCancelRetryTimes( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActOutsideLineNumber( 
            /* [retval][out] */ BSTR __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActOutsideLineNumber( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActPasswordCancelResponseWaitTime( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActPasswordCancelResponseWaitTime( 
            /* [in] */ long newVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IActA6TELVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IActA6TEL __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IActA6TEL __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IActA6TEL __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IActA6TEL __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IActA6TEL __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IActA6TEL __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IActA6TEL __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Open )( 
            IActA6TEL __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Close )( 
            IActA6TEL __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetDevice )( 
            IActA6TEL __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [out] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetDevice )( 
            IActA6TEL __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceBlock )( 
            IActA6TEL __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lSize,
            /* [size_is][out] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceBlock )( 
            IActA6TEL __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lSize,
            /* [size_is][in] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceRandom )( 
            IActA6TEL __RPC_FAR * This,
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG lSize,
            /* [size_is][out] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceRandom )( 
            IActA6TEL __RPC_FAR * This,
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG lSize,
            /* [size_is][in] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadBuffer )( 
            IActA6TEL __RPC_FAR * This,
            /* [in] */ LONG lStartIO,
            /* [in] */ LONG lAddress,
            /* [in] */ LONG lReadSize,
            /* [size_is][out] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteBuffer )( 
            IActA6TEL __RPC_FAR * This,
            /* [in] */ LONG lStartIO,
            /* [in] */ LONG lAddress,
            /* [in] */ LONG lWriteSize,
            /* [size_is][in] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetClockData )( 
            IActA6TEL __RPC_FAR * This,
            /* [out] */ SHORT __RPC_FAR *lpsYear,
            /* [out] */ SHORT __RPC_FAR *lpsMonth,
            /* [out] */ SHORT __RPC_FAR *lpsDay,
            /* [out] */ SHORT __RPC_FAR *lpsDayOfWeek,
            /* [out] */ SHORT __RPC_FAR *lpsHour,
            /* [out] */ SHORT __RPC_FAR *lpsMinute,
            /* [out] */ SHORT __RPC_FAR *lpsSecond,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetClockData )( 
            IActA6TEL __RPC_FAR * This,
            /* [in] */ SHORT sYear,
            /* [in] */ SHORT sMonth,
            /* [in] */ SHORT sDay,
            /* [in] */ SHORT sDayOfWeek,
            /* [in] */ SHORT sHour,
            /* [in] */ SHORT sMinute,
            /* [in] */ SHORT sSecond,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetCpuType )( 
            IActA6TEL __RPC_FAR * This,
            /* [string][out] */ BSTR __RPC_FAR *szCpuName,
            /* [out] */ LONG __RPC_FAR *lplCpuCode,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetCpuStatus )( 
            IActA6TEL __RPC_FAR * This,
            /* [in] */ LONG lOperation,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CheckDeviceString )( 
            IActA6TEL __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lCheckType,
            /* [in] */ LONG lSize,
            /* [out] */ LONG __RPC_FAR *lplDeviceType,
            /* [string][out] */ BSTR __RPC_FAR *lpszDeviceName,
            /* [out] */ LONG __RPC_FAR *lplDeviceNumber,
            /* [out] */ LONG __RPC_FAR *lplDeviceRadix,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *EntryDeviceStatus )( 
            IActA6TEL __RPC_FAR * This,
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG lSize,
            /* [in] */ LONG lMonitorCycle,
            /* [size_is][in] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *FreeDeviceStatus )( 
            IActA6TEL __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceBlock2 )( 
            IActA6TEL __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lSize,
            /* [size_is][out] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceBlock2 )( 
            IActA6TEL __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lSize,
            /* [size_is][in] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceRandom2 )( 
            IActA6TEL __RPC_FAR * This,
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG lSize,
            /* [size_is][out] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceRandom2 )( 
            IActA6TEL __RPC_FAR * This,
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG lSize,
            /* [size_is][in] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetDevice2 )( 
            IActA6TEL __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [out] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetDevice2 )( 
            IActA6TEL __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ SHORT sData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Connect )( 
            IActA6TEL __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Disconnect )( 
            IActA6TEL __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActNetworkNumber )( 
            IActA6TEL __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActNetworkNumber )( 
            IActA6TEL __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActStationNumber )( 
            IActA6TEL __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActStationNumber )( 
            IActA6TEL __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActCpuType )( 
            IActA6TEL __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActCpuType )( 
            IActA6TEL __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActPortNumber )( 
            IActA6TEL __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActPortNumber )( 
            IActA6TEL __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActTimeOut )( 
            IActA6TEL __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActTimeOut )( 
            IActA6TEL __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActATCommand )( 
            IActA6TEL __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActATCommand )( 
            IActA6TEL __RPC_FAR * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActDialNumber )( 
            IActA6TEL __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActDialNumber )( 
            IActA6TEL __RPC_FAR * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActLineType )( 
            IActA6TEL __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActLineType )( 
            IActA6TEL __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActPassword )( 
            IActA6TEL __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActPassword )( 
            IActA6TEL __RPC_FAR * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActConnectionCDWaitTime )( 
            IActA6TEL __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActConnectionCDWaitTime )( 
            IActA6TEL __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActConnectionModemReportWaitTime )( 
            IActA6TEL __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActConnectionModemReportWaitTime )( 
            IActA6TEL __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActDisconnectionCDWaitTime )( 
            IActA6TEL __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActDisconnectionCDWaitTime )( 
            IActA6TEL __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActDisconnectionDelayTime )( 
            IActA6TEL __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActDisconnectionDelayTime )( 
            IActA6TEL __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActTransmissionDelayTime )( 
            IActA6TEL __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActTransmissionDelayTime )( 
            IActA6TEL __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActATCommandResponseWaitTime )( 
            IActA6TEL __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActATCommandResponseWaitTime )( 
            IActA6TEL __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActATCommandPasswordCancelRetryTimes )( 
            IActA6TEL __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActATCommandPasswordCancelRetryTimes )( 
            IActA6TEL __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActOutsideLineNumber )( 
            IActA6TEL __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActOutsideLineNumber )( 
            IActA6TEL __RPC_FAR * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActPasswordCancelResponseWaitTime )( 
            IActA6TEL __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActPasswordCancelResponseWaitTime )( 
            IActA6TEL __RPC_FAR * This,
            /* [in] */ long newVal);
        
        END_INTERFACE
    } IActA6TELVtbl;

    interface IActA6TEL
    {
        CONST_VTBL struct IActA6TELVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IActA6TEL_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IActA6TEL_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IActA6TEL_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IActA6TEL_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IActA6TEL_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IActA6TEL_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IActA6TEL_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IActA6TEL_Open(This,lplReturnCode)	\
    (This)->lpVtbl -> Open(This,lplReturnCode)

#define IActA6TEL_Close(This,lplReturnCode)	\
    (This)->lpVtbl -> Close(This,lplReturnCode)

#define IActA6TEL_GetDevice(This,szDevice,lplData,lplReturnCode)	\
    (This)->lpVtbl -> GetDevice(This,szDevice,lplData,lplReturnCode)

#define IActA6TEL_SetDevice(This,szDevice,lData,lplReturnCode)	\
    (This)->lpVtbl -> SetDevice(This,szDevice,lData,lplReturnCode)

#define IActA6TEL_ReadDeviceBlock(This,szDevice,lSize,lplData,lplReturnCode)	\
    (This)->lpVtbl -> ReadDeviceBlock(This,szDevice,lSize,lplData,lplReturnCode)

#define IActA6TEL_WriteDeviceBlock(This,szDevice,lSize,lplData,lplReturnCode)	\
    (This)->lpVtbl -> WriteDeviceBlock(This,szDevice,lSize,lplData,lplReturnCode)

#define IActA6TEL_ReadDeviceRandom(This,szDeviceList,lSize,lplData,lplReturnCode)	\
    (This)->lpVtbl -> ReadDeviceRandom(This,szDeviceList,lSize,lplData,lplReturnCode)

#define IActA6TEL_WriteDeviceRandom(This,szDeviceList,lSize,lplData,lplReturnCode)	\
    (This)->lpVtbl -> WriteDeviceRandom(This,szDeviceList,lSize,lplData,lplReturnCode)

#define IActA6TEL_ReadBuffer(This,lStartIO,lAddress,lReadSize,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> ReadBuffer(This,lStartIO,lAddress,lReadSize,lpsData,lplReturnCode)

#define IActA6TEL_WriteBuffer(This,lStartIO,lAddress,lWriteSize,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> WriteBuffer(This,lStartIO,lAddress,lWriteSize,lpsData,lplReturnCode)

#define IActA6TEL_GetClockData(This,lpsYear,lpsMonth,lpsDay,lpsDayOfWeek,lpsHour,lpsMinute,lpsSecond,lplReturnCode)	\
    (This)->lpVtbl -> GetClockData(This,lpsYear,lpsMonth,lpsDay,lpsDayOfWeek,lpsHour,lpsMinute,lpsSecond,lplReturnCode)

#define IActA6TEL_SetClockData(This,sYear,sMonth,sDay,sDayOfWeek,sHour,sMinute,sSecond,lplReturnCode)	\
    (This)->lpVtbl -> SetClockData(This,sYear,sMonth,sDay,sDayOfWeek,sHour,sMinute,sSecond,lplReturnCode)

#define IActA6TEL_GetCpuType(This,szCpuName,lplCpuCode,lplReturnCode)	\
    (This)->lpVtbl -> GetCpuType(This,szCpuName,lplCpuCode,lplReturnCode)

#define IActA6TEL_SetCpuStatus(This,lOperation,lplReturnCode)	\
    (This)->lpVtbl -> SetCpuStatus(This,lOperation,lplReturnCode)

#define IActA6TEL_CheckDeviceString(This,szDevice,lCheckType,lSize,lplDeviceType,lpszDeviceName,lplDeviceNumber,lplDeviceRadix,lplReturnCode)	\
    (This)->lpVtbl -> CheckDeviceString(This,szDevice,lCheckType,lSize,lplDeviceType,lpszDeviceName,lplDeviceNumber,lplDeviceRadix,lplReturnCode)

#define IActA6TEL_EntryDeviceStatus(This,szDeviceList,lSize,lMonitorCycle,lplData,lplReturnCode)	\
    (This)->lpVtbl -> EntryDeviceStatus(This,szDeviceList,lSize,lMonitorCycle,lplData,lplReturnCode)

#define IActA6TEL_FreeDeviceStatus(This,lplReturnCode)	\
    (This)->lpVtbl -> FreeDeviceStatus(This,lplReturnCode)

#define IActA6TEL_ReadDeviceBlock2(This,szDevice,lSize,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> ReadDeviceBlock2(This,szDevice,lSize,lpsData,lplReturnCode)

#define IActA6TEL_WriteDeviceBlock2(This,szDevice,lSize,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> WriteDeviceBlock2(This,szDevice,lSize,lpsData,lplReturnCode)

#define IActA6TEL_ReadDeviceRandom2(This,szDeviceList,lSize,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> ReadDeviceRandom2(This,szDeviceList,lSize,lpsData,lplReturnCode)

#define IActA6TEL_WriteDeviceRandom2(This,szDeviceList,lSize,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> WriteDeviceRandom2(This,szDeviceList,lSize,lpsData,lplReturnCode)

#define IActA6TEL_GetDevice2(This,szDevice,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> GetDevice2(This,szDevice,lpsData,lplReturnCode)

#define IActA6TEL_SetDevice2(This,szDevice,sData,lplReturnCode)	\
    (This)->lpVtbl -> SetDevice2(This,szDevice,sData,lplReturnCode)

#define IActA6TEL_Connect(This,lplReturnCode)	\
    (This)->lpVtbl -> Connect(This,lplReturnCode)

#define IActA6TEL_Disconnect(This,lplReturnCode)	\
    (This)->lpVtbl -> Disconnect(This,lplReturnCode)

#define IActA6TEL_get_ActNetworkNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActNetworkNumber(This,pVal)

#define IActA6TEL_put_ActNetworkNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActNetworkNumber(This,newVal)

#define IActA6TEL_get_ActStationNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActStationNumber(This,pVal)

#define IActA6TEL_put_ActStationNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActStationNumber(This,newVal)

#define IActA6TEL_get_ActCpuType(This,pVal)	\
    (This)->lpVtbl -> get_ActCpuType(This,pVal)

#define IActA6TEL_put_ActCpuType(This,newVal)	\
    (This)->lpVtbl -> put_ActCpuType(This,newVal)

#define IActA6TEL_get_ActPortNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActPortNumber(This,pVal)

#define IActA6TEL_put_ActPortNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActPortNumber(This,newVal)

#define IActA6TEL_get_ActTimeOut(This,pVal)	\
    (This)->lpVtbl -> get_ActTimeOut(This,pVal)

#define IActA6TEL_put_ActTimeOut(This,newVal)	\
    (This)->lpVtbl -> put_ActTimeOut(This,newVal)

#define IActA6TEL_get_ActATCommand(This,pVal)	\
    (This)->lpVtbl -> get_ActATCommand(This,pVal)

#define IActA6TEL_put_ActATCommand(This,newVal)	\
    (This)->lpVtbl -> put_ActATCommand(This,newVal)

#define IActA6TEL_get_ActDialNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActDialNumber(This,pVal)

#define IActA6TEL_put_ActDialNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActDialNumber(This,newVal)

#define IActA6TEL_get_ActLineType(This,pVal)	\
    (This)->lpVtbl -> get_ActLineType(This,pVal)

#define IActA6TEL_put_ActLineType(This,newVal)	\
    (This)->lpVtbl -> put_ActLineType(This,newVal)

#define IActA6TEL_get_ActPassword(This,pVal)	\
    (This)->lpVtbl -> get_ActPassword(This,pVal)

#define IActA6TEL_put_ActPassword(This,newVal)	\
    (This)->lpVtbl -> put_ActPassword(This,newVal)

#define IActA6TEL_get_ActConnectionCDWaitTime(This,pVal)	\
    (This)->lpVtbl -> get_ActConnectionCDWaitTime(This,pVal)

#define IActA6TEL_put_ActConnectionCDWaitTime(This,newVal)	\
    (This)->lpVtbl -> put_ActConnectionCDWaitTime(This,newVal)

#define IActA6TEL_get_ActConnectionModemReportWaitTime(This,pVal)	\
    (This)->lpVtbl -> get_ActConnectionModemReportWaitTime(This,pVal)

#define IActA6TEL_put_ActConnectionModemReportWaitTime(This,newVal)	\
    (This)->lpVtbl -> put_ActConnectionModemReportWaitTime(This,newVal)

#define IActA6TEL_get_ActDisconnectionCDWaitTime(This,pVal)	\
    (This)->lpVtbl -> get_ActDisconnectionCDWaitTime(This,pVal)

#define IActA6TEL_put_ActDisconnectionCDWaitTime(This,newVal)	\
    (This)->lpVtbl -> put_ActDisconnectionCDWaitTime(This,newVal)

#define IActA6TEL_get_ActDisconnectionDelayTime(This,pVal)	\
    (This)->lpVtbl -> get_ActDisconnectionDelayTime(This,pVal)

#define IActA6TEL_put_ActDisconnectionDelayTime(This,newVal)	\
    (This)->lpVtbl -> put_ActDisconnectionDelayTime(This,newVal)

#define IActA6TEL_get_ActTransmissionDelayTime(This,pVal)	\
    (This)->lpVtbl -> get_ActTransmissionDelayTime(This,pVal)

#define IActA6TEL_put_ActTransmissionDelayTime(This,newVal)	\
    (This)->lpVtbl -> put_ActTransmissionDelayTime(This,newVal)

#define IActA6TEL_get_ActATCommandResponseWaitTime(This,pVal)	\
    (This)->lpVtbl -> get_ActATCommandResponseWaitTime(This,pVal)

#define IActA6TEL_put_ActATCommandResponseWaitTime(This,newVal)	\
    (This)->lpVtbl -> put_ActATCommandResponseWaitTime(This,newVal)

#define IActA6TEL_get_ActATCommandPasswordCancelRetryTimes(This,pVal)	\
    (This)->lpVtbl -> get_ActATCommandPasswordCancelRetryTimes(This,pVal)

#define IActA6TEL_put_ActATCommandPasswordCancelRetryTimes(This,newVal)	\
    (This)->lpVtbl -> put_ActATCommandPasswordCancelRetryTimes(This,newVal)

#define IActA6TEL_get_ActOutsideLineNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActOutsideLineNumber(This,pVal)

#define IActA6TEL_put_ActOutsideLineNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActOutsideLineNumber(This,newVal)

#define IActA6TEL_get_ActPasswordCancelResponseWaitTime(This,pVal)	\
    (This)->lpVtbl -> get_ActPasswordCancelResponseWaitTime(This,pVal)

#define IActA6TEL_put_ActPasswordCancelResponseWaitTime(This,newVal)	\
    (This)->lpVtbl -> put_ActPasswordCancelResponseWaitTime(This,newVal)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActA6TEL_Open_Proxy( 
    IActA6TEL __RPC_FAR * This,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActA6TEL_Open_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActA6TEL_Close_Proxy( 
    IActA6TEL __RPC_FAR * This,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActA6TEL_Close_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActA6TEL_GetDevice_Proxy( 
    IActA6TEL __RPC_FAR * This,
    /* [string][in] */ BSTR szDevice,
    /* [out] */ LONG __RPC_FAR *lplData,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActA6TEL_GetDevice_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActA6TEL_SetDevice_Proxy( 
    IActA6TEL __RPC_FAR * This,
    /* [string][in] */ BSTR szDevice,
    /* [in] */ LONG lData,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActA6TEL_SetDevice_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActA6TEL_ReadDeviceBlock_Proxy( 
    IActA6TEL __RPC_FAR * This,
    /* [string][in] */ BSTR szDevice,
    /* [in] */ LONG lSize,
    /* [size_is][out] */ LONG __RPC_FAR *lplData,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActA6TEL_ReadDeviceBlock_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActA6TEL_WriteDeviceBlock_Proxy( 
    IActA6TEL __RPC_FAR * This,
    /* [string][in] */ BSTR szDevice,
    /* [in] */ LONG lSize,
    /* [size_is][in] */ LONG __RPC_FAR *lplData,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActA6TEL_WriteDeviceBlock_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActA6TEL_ReadDeviceRandom_Proxy( 
    IActA6TEL __RPC_FAR * This,
    /* [string][in] */ BSTR szDeviceList,
    /* [in] */ LONG lSize,
    /* [size_is][out] */ LONG __RPC_FAR *lplData,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActA6TEL_ReadDeviceRandom_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActA6TEL_WriteDeviceRandom_Proxy( 
    IActA6TEL __RPC_FAR * This,
    /* [string][in] */ BSTR szDeviceList,
    /* [in] */ LONG lSize,
    /* [size_is][in] */ LONG __RPC_FAR *lplData,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActA6TEL_WriteDeviceRandom_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActA6TEL_ReadBuffer_Proxy( 
    IActA6TEL __RPC_FAR * This,
    /* [in] */ LONG lStartIO,
    /* [in] */ LONG lAddress,
    /* [in] */ LONG lReadSize,
    /* [size_is][out] */ SHORT __RPC_FAR *lpsData,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActA6TEL_ReadBuffer_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActA6TEL_WriteBuffer_Proxy( 
    IActA6TEL __RPC_FAR * This,
    /* [in] */ LONG lStartIO,
    /* [in] */ LONG lAddress,
    /* [in] */ LONG lWriteSize,
    /* [size_is][in] */ SHORT __RPC_FAR *lpsData,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActA6TEL_WriteBuffer_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActA6TEL_GetClockData_Proxy( 
    IActA6TEL __RPC_FAR * This,
    /* [out] */ SHORT __RPC_FAR *lpsYear,
    /* [out] */ SHORT __RPC_FAR *lpsMonth,
    /* [out] */ SHORT __RPC_FAR *lpsDay,
    /* [out] */ SHORT __RPC_FAR *lpsDayOfWeek,
    /* [out] */ SHORT __RPC_FAR *lpsHour,
    /* [out] */ SHORT __RPC_FAR *lpsMinute,
    /* [out] */ SHORT __RPC_FAR *lpsSecond,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActA6TEL_GetClockData_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActA6TEL_SetClockData_Proxy( 
    IActA6TEL __RPC_FAR * This,
    /* [in] */ SHORT sYear,
    /* [in] */ SHORT sMonth,
    /* [in] */ SHORT sDay,
    /* [in] */ SHORT sDayOfWeek,
    /* [in] */ SHORT sHour,
    /* [in] */ SHORT sMinute,
    /* [in] */ SHORT sSecond,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActA6TEL_SetClockData_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActA6TEL_GetCpuType_Proxy( 
    IActA6TEL __RPC_FAR * This,
    /* [string][out] */ BSTR __RPC_FAR *szCpuName,
    /* [out] */ LONG __RPC_FAR *lplCpuCode,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActA6TEL_GetCpuType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActA6TEL_SetCpuStatus_Proxy( 
    IActA6TEL __RPC_FAR * This,
    /* [in] */ LONG lOperation,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActA6TEL_SetCpuStatus_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActA6TEL_CheckDeviceString_Proxy( 
    IActA6TEL __RPC_FAR * This,
    /* [string][in] */ BSTR szDevice,
    /* [in] */ LONG lCheckType,
    /* [in] */ LONG lSize,
    /* [out] */ LONG __RPC_FAR *lplDeviceType,
    /* [string][out] */ BSTR __RPC_FAR *lpszDeviceName,
    /* [out] */ LONG __RPC_FAR *lplDeviceNumber,
    /* [out] */ LONG __RPC_FAR *lplDeviceRadix,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActA6TEL_CheckDeviceString_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActA6TEL_EntryDeviceStatus_Proxy( 
    IActA6TEL __RPC_FAR * This,
    /* [string][in] */ BSTR szDeviceList,
    /* [in] */ LONG lSize,
    /* [in] */ LONG lMonitorCycle,
    /* [size_is][in] */ LONG __RPC_FAR *lplData,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActA6TEL_EntryDeviceStatus_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActA6TEL_FreeDeviceStatus_Proxy( 
    IActA6TEL __RPC_FAR * This,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActA6TEL_FreeDeviceStatus_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActA6TEL_ReadDeviceBlock2_Proxy( 
    IActA6TEL __RPC_FAR * This,
    /* [string][in] */ BSTR szDevice,
    /* [in] */ LONG lSize,
    /* [size_is][out] */ SHORT __RPC_FAR *lpsData,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActA6TEL_ReadDeviceBlock2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActA6TEL_WriteDeviceBlock2_Proxy( 
    IActA6TEL __RPC_FAR * This,
    /* [string][in] */ BSTR szDevice,
    /* [in] */ LONG lSize,
    /* [size_is][in] */ SHORT __RPC_FAR *lpsData,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActA6TEL_WriteDeviceBlock2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActA6TEL_ReadDeviceRandom2_Proxy( 
    IActA6TEL __RPC_FAR * This,
    /* [string][in] */ BSTR szDeviceList,
    /* [in] */ LONG lSize,
    /* [size_is][out] */ SHORT __RPC_FAR *lpsData,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActA6TEL_ReadDeviceRandom2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActA6TEL_WriteDeviceRandom2_Proxy( 
    IActA6TEL __RPC_FAR * This,
    /* [string][in] */ BSTR szDeviceList,
    /* [in] */ LONG lSize,
    /* [size_is][in] */ SHORT __RPC_FAR *lpsData,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActA6TEL_WriteDeviceRandom2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActA6TEL_GetDevice2_Proxy( 
    IActA6TEL __RPC_FAR * This,
    /* [string][in] */ BSTR szDevice,
    /* [out] */ SHORT __RPC_FAR *lpsData,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActA6TEL_GetDevice2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActA6TEL_SetDevice2_Proxy( 
    IActA6TEL __RPC_FAR * This,
    /* [string][in] */ BSTR szDevice,
    /* [in] */ SHORT sData,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActA6TEL_SetDevice2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActA6TEL_Connect_Proxy( 
    IActA6TEL __RPC_FAR * This,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActA6TEL_Connect_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActA6TEL_Disconnect_Proxy( 
    IActA6TEL __RPC_FAR * This,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActA6TEL_Disconnect_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActA6TEL_get_ActNetworkNumber_Proxy( 
    IActA6TEL __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IActA6TEL_get_ActNetworkNumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActA6TEL_put_ActNetworkNumber_Proxy( 
    IActA6TEL __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB IActA6TEL_put_ActNetworkNumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActA6TEL_get_ActStationNumber_Proxy( 
    IActA6TEL __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IActA6TEL_get_ActStationNumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActA6TEL_put_ActStationNumber_Proxy( 
    IActA6TEL __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB IActA6TEL_put_ActStationNumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActA6TEL_get_ActCpuType_Proxy( 
    IActA6TEL __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IActA6TEL_get_ActCpuType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActA6TEL_put_ActCpuType_Proxy( 
    IActA6TEL __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB IActA6TEL_put_ActCpuType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActA6TEL_get_ActPortNumber_Proxy( 
    IActA6TEL __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IActA6TEL_get_ActPortNumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActA6TEL_put_ActPortNumber_Proxy( 
    IActA6TEL __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB IActA6TEL_put_ActPortNumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActA6TEL_get_ActTimeOut_Proxy( 
    IActA6TEL __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IActA6TEL_get_ActTimeOut_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActA6TEL_put_ActTimeOut_Proxy( 
    IActA6TEL __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB IActA6TEL_put_ActTimeOut_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActA6TEL_get_ActATCommand_Proxy( 
    IActA6TEL __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *pVal);


void __RPC_STUB IActA6TEL_get_ActATCommand_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActA6TEL_put_ActATCommand_Proxy( 
    IActA6TEL __RPC_FAR * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB IActA6TEL_put_ActATCommand_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActA6TEL_get_ActDialNumber_Proxy( 
    IActA6TEL __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *pVal);


void __RPC_STUB IActA6TEL_get_ActDialNumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActA6TEL_put_ActDialNumber_Proxy( 
    IActA6TEL __RPC_FAR * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB IActA6TEL_put_ActDialNumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActA6TEL_get_ActLineType_Proxy( 
    IActA6TEL __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IActA6TEL_get_ActLineType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActA6TEL_put_ActLineType_Proxy( 
    IActA6TEL __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB IActA6TEL_put_ActLineType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActA6TEL_get_ActPassword_Proxy( 
    IActA6TEL __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *pVal);


void __RPC_STUB IActA6TEL_get_ActPassword_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActA6TEL_put_ActPassword_Proxy( 
    IActA6TEL __RPC_FAR * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB IActA6TEL_put_ActPassword_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActA6TEL_get_ActConnectionCDWaitTime_Proxy( 
    IActA6TEL __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IActA6TEL_get_ActConnectionCDWaitTime_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActA6TEL_put_ActConnectionCDWaitTime_Proxy( 
    IActA6TEL __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB IActA6TEL_put_ActConnectionCDWaitTime_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActA6TEL_get_ActConnectionModemReportWaitTime_Proxy( 
    IActA6TEL __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IActA6TEL_get_ActConnectionModemReportWaitTime_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActA6TEL_put_ActConnectionModemReportWaitTime_Proxy( 
    IActA6TEL __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB IActA6TEL_put_ActConnectionModemReportWaitTime_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActA6TEL_get_ActDisconnectionCDWaitTime_Proxy( 
    IActA6TEL __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IActA6TEL_get_ActDisconnectionCDWaitTime_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActA6TEL_put_ActDisconnectionCDWaitTime_Proxy( 
    IActA6TEL __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB IActA6TEL_put_ActDisconnectionCDWaitTime_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActA6TEL_get_ActDisconnectionDelayTime_Proxy( 
    IActA6TEL __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IActA6TEL_get_ActDisconnectionDelayTime_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActA6TEL_put_ActDisconnectionDelayTime_Proxy( 
    IActA6TEL __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB IActA6TEL_put_ActDisconnectionDelayTime_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActA6TEL_get_ActTransmissionDelayTime_Proxy( 
    IActA6TEL __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IActA6TEL_get_ActTransmissionDelayTime_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActA6TEL_put_ActTransmissionDelayTime_Proxy( 
    IActA6TEL __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB IActA6TEL_put_ActTransmissionDelayTime_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActA6TEL_get_ActATCommandResponseWaitTime_Proxy( 
    IActA6TEL __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IActA6TEL_get_ActATCommandResponseWaitTime_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActA6TEL_put_ActATCommandResponseWaitTime_Proxy( 
    IActA6TEL __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB IActA6TEL_put_ActATCommandResponseWaitTime_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActA6TEL_get_ActATCommandPasswordCancelRetryTimes_Proxy( 
    IActA6TEL __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IActA6TEL_get_ActATCommandPasswordCancelRetryTimes_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActA6TEL_put_ActATCommandPasswordCancelRetryTimes_Proxy( 
    IActA6TEL __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB IActA6TEL_put_ActATCommandPasswordCancelRetryTimes_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActA6TEL_get_ActOutsideLineNumber_Proxy( 
    IActA6TEL __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *pVal);


void __RPC_STUB IActA6TEL_get_ActOutsideLineNumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActA6TEL_put_ActOutsideLineNumber_Proxy( 
    IActA6TEL __RPC_FAR * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB IActA6TEL_put_ActOutsideLineNumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActA6TEL_get_ActPasswordCancelResponseWaitTime_Proxy( 
    IActA6TEL __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IActA6TEL_get_ActPasswordCancelResponseWaitTime_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActA6TEL_put_ActPasswordCancelResponseWaitTime_Proxy( 
    IActA6TEL __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB IActA6TEL_put_ActPasswordCancelResponseWaitTime_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IActA6TEL_INTERFACE_DEFINED__ */


#ifndef __IActA6TEL2_INTERFACE_DEFINED__
#define __IActA6TEL2_INTERFACE_DEFINED__

/* interface IActA6TEL2 */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IActA6TEL2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("87166036-710B-11d5-9318-009099244EFD")
    IActA6TEL2 : public IActA6TEL
    {
    public:
    };
    
#else 	/* C style interface */

    typedef struct IActA6TEL2Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IActA6TEL2 __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IActA6TEL2 __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IActA6TEL2 __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IActA6TEL2 __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IActA6TEL2 __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IActA6TEL2 __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IActA6TEL2 __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Open )( 
            IActA6TEL2 __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Close )( 
            IActA6TEL2 __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetDevice )( 
            IActA6TEL2 __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [out] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetDevice )( 
            IActA6TEL2 __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceBlock )( 
            IActA6TEL2 __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lSize,
            /* [size_is][out] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceBlock )( 
            IActA6TEL2 __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lSize,
            /* [size_is][in] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceRandom )( 
            IActA6TEL2 __RPC_FAR * This,
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG lSize,
            /* [size_is][out] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceRandom )( 
            IActA6TEL2 __RPC_FAR * This,
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG lSize,
            /* [size_is][in] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadBuffer )( 
            IActA6TEL2 __RPC_FAR * This,
            /* [in] */ LONG lStartIO,
            /* [in] */ LONG lAddress,
            /* [in] */ LONG lReadSize,
            /* [size_is][out] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteBuffer )( 
            IActA6TEL2 __RPC_FAR * This,
            /* [in] */ LONG lStartIO,
            /* [in] */ LONG lAddress,
            /* [in] */ LONG lWriteSize,
            /* [size_is][in] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetClockData )( 
            IActA6TEL2 __RPC_FAR * This,
            /* [out] */ SHORT __RPC_FAR *lpsYear,
            /* [out] */ SHORT __RPC_FAR *lpsMonth,
            /* [out] */ SHORT __RPC_FAR *lpsDay,
            /* [out] */ SHORT __RPC_FAR *lpsDayOfWeek,
            /* [out] */ SHORT __RPC_FAR *lpsHour,
            /* [out] */ SHORT __RPC_FAR *lpsMinute,
            /* [out] */ SHORT __RPC_FAR *lpsSecond,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetClockData )( 
            IActA6TEL2 __RPC_FAR * This,
            /* [in] */ SHORT sYear,
            /* [in] */ SHORT sMonth,
            /* [in] */ SHORT sDay,
            /* [in] */ SHORT sDayOfWeek,
            /* [in] */ SHORT sHour,
            /* [in] */ SHORT sMinute,
            /* [in] */ SHORT sSecond,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetCpuType )( 
            IActA6TEL2 __RPC_FAR * This,
            /* [string][out] */ BSTR __RPC_FAR *szCpuName,
            /* [out] */ LONG __RPC_FAR *lplCpuCode,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetCpuStatus )( 
            IActA6TEL2 __RPC_FAR * This,
            /* [in] */ LONG lOperation,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CheckDeviceString )( 
            IActA6TEL2 __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lCheckType,
            /* [in] */ LONG lSize,
            /* [out] */ LONG __RPC_FAR *lplDeviceType,
            /* [string][out] */ BSTR __RPC_FAR *lpszDeviceName,
            /* [out] */ LONG __RPC_FAR *lplDeviceNumber,
            /* [out] */ LONG __RPC_FAR *lplDeviceRadix,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *EntryDeviceStatus )( 
            IActA6TEL2 __RPC_FAR * This,
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG lSize,
            /* [in] */ LONG lMonitorCycle,
            /* [size_is][in] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *FreeDeviceStatus )( 
            IActA6TEL2 __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceBlock2 )( 
            IActA6TEL2 __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lSize,
            /* [size_is][out] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceBlock2 )( 
            IActA6TEL2 __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lSize,
            /* [size_is][in] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceRandom2 )( 
            IActA6TEL2 __RPC_FAR * This,
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG lSize,
            /* [size_is][out] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceRandom2 )( 
            IActA6TEL2 __RPC_FAR * This,
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG lSize,
            /* [size_is][in] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetDevice2 )( 
            IActA6TEL2 __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [out] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetDevice2 )( 
            IActA6TEL2 __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ SHORT sData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Connect )( 
            IActA6TEL2 __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Disconnect )( 
            IActA6TEL2 __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActNetworkNumber )( 
            IActA6TEL2 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActNetworkNumber )( 
            IActA6TEL2 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActStationNumber )( 
            IActA6TEL2 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActStationNumber )( 
            IActA6TEL2 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActCpuType )( 
            IActA6TEL2 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActCpuType )( 
            IActA6TEL2 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActPortNumber )( 
            IActA6TEL2 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActPortNumber )( 
            IActA6TEL2 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActTimeOut )( 
            IActA6TEL2 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActTimeOut )( 
            IActA6TEL2 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActATCommand )( 
            IActA6TEL2 __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActATCommand )( 
            IActA6TEL2 __RPC_FAR * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActDialNumber )( 
            IActA6TEL2 __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActDialNumber )( 
            IActA6TEL2 __RPC_FAR * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActLineType )( 
            IActA6TEL2 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActLineType )( 
            IActA6TEL2 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActPassword )( 
            IActA6TEL2 __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActPassword )( 
            IActA6TEL2 __RPC_FAR * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActConnectionCDWaitTime )( 
            IActA6TEL2 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActConnectionCDWaitTime )( 
            IActA6TEL2 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActConnectionModemReportWaitTime )( 
            IActA6TEL2 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActConnectionModemReportWaitTime )( 
            IActA6TEL2 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActDisconnectionCDWaitTime )( 
            IActA6TEL2 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActDisconnectionCDWaitTime )( 
            IActA6TEL2 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActDisconnectionDelayTime )( 
            IActA6TEL2 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActDisconnectionDelayTime )( 
            IActA6TEL2 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActTransmissionDelayTime )( 
            IActA6TEL2 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActTransmissionDelayTime )( 
            IActA6TEL2 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActATCommandResponseWaitTime )( 
            IActA6TEL2 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActATCommandResponseWaitTime )( 
            IActA6TEL2 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActATCommandPasswordCancelRetryTimes )( 
            IActA6TEL2 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActATCommandPasswordCancelRetryTimes )( 
            IActA6TEL2 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActOutsideLineNumber )( 
            IActA6TEL2 __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActOutsideLineNumber )( 
            IActA6TEL2 __RPC_FAR * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActPasswordCancelResponseWaitTime )( 
            IActA6TEL2 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActPasswordCancelResponseWaitTime )( 
            IActA6TEL2 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        END_INTERFACE
    } IActA6TEL2Vtbl;

    interface IActA6TEL2
    {
        CONST_VTBL struct IActA6TEL2Vtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IActA6TEL2_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IActA6TEL2_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IActA6TEL2_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IActA6TEL2_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IActA6TEL2_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IActA6TEL2_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IActA6TEL2_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IActA6TEL2_Open(This,lplReturnCode)	\
    (This)->lpVtbl -> Open(This,lplReturnCode)

#define IActA6TEL2_Close(This,lplReturnCode)	\
    (This)->lpVtbl -> Close(This,lplReturnCode)

#define IActA6TEL2_GetDevice(This,szDevice,lplData,lplReturnCode)	\
    (This)->lpVtbl -> GetDevice(This,szDevice,lplData,lplReturnCode)

#define IActA6TEL2_SetDevice(This,szDevice,lData,lplReturnCode)	\
    (This)->lpVtbl -> SetDevice(This,szDevice,lData,lplReturnCode)

#define IActA6TEL2_ReadDeviceBlock(This,szDevice,lSize,lplData,lplReturnCode)	\
    (This)->lpVtbl -> ReadDeviceBlock(This,szDevice,lSize,lplData,lplReturnCode)

#define IActA6TEL2_WriteDeviceBlock(This,szDevice,lSize,lplData,lplReturnCode)	\
    (This)->lpVtbl -> WriteDeviceBlock(This,szDevice,lSize,lplData,lplReturnCode)

#define IActA6TEL2_ReadDeviceRandom(This,szDeviceList,lSize,lplData,lplReturnCode)	\
    (This)->lpVtbl -> ReadDeviceRandom(This,szDeviceList,lSize,lplData,lplReturnCode)

#define IActA6TEL2_WriteDeviceRandom(This,szDeviceList,lSize,lplData,lplReturnCode)	\
    (This)->lpVtbl -> WriteDeviceRandom(This,szDeviceList,lSize,lplData,lplReturnCode)

#define IActA6TEL2_ReadBuffer(This,lStartIO,lAddress,lReadSize,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> ReadBuffer(This,lStartIO,lAddress,lReadSize,lpsData,lplReturnCode)

#define IActA6TEL2_WriteBuffer(This,lStartIO,lAddress,lWriteSize,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> WriteBuffer(This,lStartIO,lAddress,lWriteSize,lpsData,lplReturnCode)

#define IActA6TEL2_GetClockData(This,lpsYear,lpsMonth,lpsDay,lpsDayOfWeek,lpsHour,lpsMinute,lpsSecond,lplReturnCode)	\
    (This)->lpVtbl -> GetClockData(This,lpsYear,lpsMonth,lpsDay,lpsDayOfWeek,lpsHour,lpsMinute,lpsSecond,lplReturnCode)

#define IActA6TEL2_SetClockData(This,sYear,sMonth,sDay,sDayOfWeek,sHour,sMinute,sSecond,lplReturnCode)	\
    (This)->lpVtbl -> SetClockData(This,sYear,sMonth,sDay,sDayOfWeek,sHour,sMinute,sSecond,lplReturnCode)

#define IActA6TEL2_GetCpuType(This,szCpuName,lplCpuCode,lplReturnCode)	\
    (This)->lpVtbl -> GetCpuType(This,szCpuName,lplCpuCode,lplReturnCode)

#define IActA6TEL2_SetCpuStatus(This,lOperation,lplReturnCode)	\
    (This)->lpVtbl -> SetCpuStatus(This,lOperation,lplReturnCode)

#define IActA6TEL2_CheckDeviceString(This,szDevice,lCheckType,lSize,lplDeviceType,lpszDeviceName,lplDeviceNumber,lplDeviceRadix,lplReturnCode)	\
    (This)->lpVtbl -> CheckDeviceString(This,szDevice,lCheckType,lSize,lplDeviceType,lpszDeviceName,lplDeviceNumber,lplDeviceRadix,lplReturnCode)

#define IActA6TEL2_EntryDeviceStatus(This,szDeviceList,lSize,lMonitorCycle,lplData,lplReturnCode)	\
    (This)->lpVtbl -> EntryDeviceStatus(This,szDeviceList,lSize,lMonitorCycle,lplData,lplReturnCode)

#define IActA6TEL2_FreeDeviceStatus(This,lplReturnCode)	\
    (This)->lpVtbl -> FreeDeviceStatus(This,lplReturnCode)

#define IActA6TEL2_ReadDeviceBlock2(This,szDevice,lSize,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> ReadDeviceBlock2(This,szDevice,lSize,lpsData,lplReturnCode)

#define IActA6TEL2_WriteDeviceBlock2(This,szDevice,lSize,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> WriteDeviceBlock2(This,szDevice,lSize,lpsData,lplReturnCode)

#define IActA6TEL2_ReadDeviceRandom2(This,szDeviceList,lSize,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> ReadDeviceRandom2(This,szDeviceList,lSize,lpsData,lplReturnCode)

#define IActA6TEL2_WriteDeviceRandom2(This,szDeviceList,lSize,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> WriteDeviceRandom2(This,szDeviceList,lSize,lpsData,lplReturnCode)

#define IActA6TEL2_GetDevice2(This,szDevice,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> GetDevice2(This,szDevice,lpsData,lplReturnCode)

#define IActA6TEL2_SetDevice2(This,szDevice,sData,lplReturnCode)	\
    (This)->lpVtbl -> SetDevice2(This,szDevice,sData,lplReturnCode)

#define IActA6TEL2_Connect(This,lplReturnCode)	\
    (This)->lpVtbl -> Connect(This,lplReturnCode)

#define IActA6TEL2_Disconnect(This,lplReturnCode)	\
    (This)->lpVtbl -> Disconnect(This,lplReturnCode)

#define IActA6TEL2_get_ActNetworkNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActNetworkNumber(This,pVal)

#define IActA6TEL2_put_ActNetworkNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActNetworkNumber(This,newVal)

#define IActA6TEL2_get_ActStationNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActStationNumber(This,pVal)

#define IActA6TEL2_put_ActStationNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActStationNumber(This,newVal)

#define IActA6TEL2_get_ActCpuType(This,pVal)	\
    (This)->lpVtbl -> get_ActCpuType(This,pVal)

#define IActA6TEL2_put_ActCpuType(This,newVal)	\
    (This)->lpVtbl -> put_ActCpuType(This,newVal)

#define IActA6TEL2_get_ActPortNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActPortNumber(This,pVal)

#define IActA6TEL2_put_ActPortNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActPortNumber(This,newVal)

#define IActA6TEL2_get_ActTimeOut(This,pVal)	\
    (This)->lpVtbl -> get_ActTimeOut(This,pVal)

#define IActA6TEL2_put_ActTimeOut(This,newVal)	\
    (This)->lpVtbl -> put_ActTimeOut(This,newVal)

#define IActA6TEL2_get_ActATCommand(This,pVal)	\
    (This)->lpVtbl -> get_ActATCommand(This,pVal)

#define IActA6TEL2_put_ActATCommand(This,newVal)	\
    (This)->lpVtbl -> put_ActATCommand(This,newVal)

#define IActA6TEL2_get_ActDialNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActDialNumber(This,pVal)

#define IActA6TEL2_put_ActDialNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActDialNumber(This,newVal)

#define IActA6TEL2_get_ActLineType(This,pVal)	\
    (This)->lpVtbl -> get_ActLineType(This,pVal)

#define IActA6TEL2_put_ActLineType(This,newVal)	\
    (This)->lpVtbl -> put_ActLineType(This,newVal)

#define IActA6TEL2_get_ActPassword(This,pVal)	\
    (This)->lpVtbl -> get_ActPassword(This,pVal)

#define IActA6TEL2_put_ActPassword(This,newVal)	\
    (This)->lpVtbl -> put_ActPassword(This,newVal)

#define IActA6TEL2_get_ActConnectionCDWaitTime(This,pVal)	\
    (This)->lpVtbl -> get_ActConnectionCDWaitTime(This,pVal)

#define IActA6TEL2_put_ActConnectionCDWaitTime(This,newVal)	\
    (This)->lpVtbl -> put_ActConnectionCDWaitTime(This,newVal)

#define IActA6TEL2_get_ActConnectionModemReportWaitTime(This,pVal)	\
    (This)->lpVtbl -> get_ActConnectionModemReportWaitTime(This,pVal)

#define IActA6TEL2_put_ActConnectionModemReportWaitTime(This,newVal)	\
    (This)->lpVtbl -> put_ActConnectionModemReportWaitTime(This,newVal)

#define IActA6TEL2_get_ActDisconnectionCDWaitTime(This,pVal)	\
    (This)->lpVtbl -> get_ActDisconnectionCDWaitTime(This,pVal)

#define IActA6TEL2_put_ActDisconnectionCDWaitTime(This,newVal)	\
    (This)->lpVtbl -> put_ActDisconnectionCDWaitTime(This,newVal)

#define IActA6TEL2_get_ActDisconnectionDelayTime(This,pVal)	\
    (This)->lpVtbl -> get_ActDisconnectionDelayTime(This,pVal)

#define IActA6TEL2_put_ActDisconnectionDelayTime(This,newVal)	\
    (This)->lpVtbl -> put_ActDisconnectionDelayTime(This,newVal)

#define IActA6TEL2_get_ActTransmissionDelayTime(This,pVal)	\
    (This)->lpVtbl -> get_ActTransmissionDelayTime(This,pVal)

#define IActA6TEL2_put_ActTransmissionDelayTime(This,newVal)	\
    (This)->lpVtbl -> put_ActTransmissionDelayTime(This,newVal)

#define IActA6TEL2_get_ActATCommandResponseWaitTime(This,pVal)	\
    (This)->lpVtbl -> get_ActATCommandResponseWaitTime(This,pVal)

#define IActA6TEL2_put_ActATCommandResponseWaitTime(This,newVal)	\
    (This)->lpVtbl -> put_ActATCommandResponseWaitTime(This,newVal)

#define IActA6TEL2_get_ActATCommandPasswordCancelRetryTimes(This,pVal)	\
    (This)->lpVtbl -> get_ActATCommandPasswordCancelRetryTimes(This,pVal)

#define IActA6TEL2_put_ActATCommandPasswordCancelRetryTimes(This,newVal)	\
    (This)->lpVtbl -> put_ActATCommandPasswordCancelRetryTimes(This,newVal)

#define IActA6TEL2_get_ActOutsideLineNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActOutsideLineNumber(This,pVal)

#define IActA6TEL2_put_ActOutsideLineNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActOutsideLineNumber(This,newVal)

#define IActA6TEL2_get_ActPasswordCancelResponseWaitTime(This,pVal)	\
    (This)->lpVtbl -> get_ActPasswordCancelResponseWaitTime(This,pVal)

#define IActA6TEL2_put_ActPasswordCancelResponseWaitTime(This,newVal)	\
    (This)->lpVtbl -> put_ActPasswordCancelResponseWaitTime(This,newVal)


#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IActA6TEL2_INTERFACE_DEFINED__ */


#ifndef __IActA6TEL3_INTERFACE_DEFINED__
#define __IActA6TEL3_INTERFACE_DEFINED__

/* interface IActA6TEL3 */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IActA6TEL3;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("87166037-710B-11d5-9318-009099244EFD")
    IActA6TEL3 : public IActA6TEL2
    {
    public:
    };
    
#else 	/* C style interface */

    typedef struct IActA6TEL3Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IActA6TEL3 __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IActA6TEL3 __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IActA6TEL3 __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IActA6TEL3 __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IActA6TEL3 __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IActA6TEL3 __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IActA6TEL3 __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Open )( 
            IActA6TEL3 __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Close )( 
            IActA6TEL3 __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetDevice )( 
            IActA6TEL3 __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [out] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetDevice )( 
            IActA6TEL3 __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceBlock )( 
            IActA6TEL3 __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lSize,
            /* [size_is][out] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceBlock )( 
            IActA6TEL3 __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lSize,
            /* [size_is][in] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceRandom )( 
            IActA6TEL3 __RPC_FAR * This,
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG lSize,
            /* [size_is][out] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceRandom )( 
            IActA6TEL3 __RPC_FAR * This,
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG lSize,
            /* [size_is][in] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadBuffer )( 
            IActA6TEL3 __RPC_FAR * This,
            /* [in] */ LONG lStartIO,
            /* [in] */ LONG lAddress,
            /* [in] */ LONG lReadSize,
            /* [size_is][out] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteBuffer )( 
            IActA6TEL3 __RPC_FAR * This,
            /* [in] */ LONG lStartIO,
            /* [in] */ LONG lAddress,
            /* [in] */ LONG lWriteSize,
            /* [size_is][in] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetClockData )( 
            IActA6TEL3 __RPC_FAR * This,
            /* [out] */ SHORT __RPC_FAR *lpsYear,
            /* [out] */ SHORT __RPC_FAR *lpsMonth,
            /* [out] */ SHORT __RPC_FAR *lpsDay,
            /* [out] */ SHORT __RPC_FAR *lpsDayOfWeek,
            /* [out] */ SHORT __RPC_FAR *lpsHour,
            /* [out] */ SHORT __RPC_FAR *lpsMinute,
            /* [out] */ SHORT __RPC_FAR *lpsSecond,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetClockData )( 
            IActA6TEL3 __RPC_FAR * This,
            /* [in] */ SHORT sYear,
            /* [in] */ SHORT sMonth,
            /* [in] */ SHORT sDay,
            /* [in] */ SHORT sDayOfWeek,
            /* [in] */ SHORT sHour,
            /* [in] */ SHORT sMinute,
            /* [in] */ SHORT sSecond,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetCpuType )( 
            IActA6TEL3 __RPC_FAR * This,
            /* [string][out] */ BSTR __RPC_FAR *szCpuName,
            /* [out] */ LONG __RPC_FAR *lplCpuCode,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetCpuStatus )( 
            IActA6TEL3 __RPC_FAR * This,
            /* [in] */ LONG lOperation,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CheckDeviceString )( 
            IActA6TEL3 __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lCheckType,
            /* [in] */ LONG lSize,
            /* [out] */ LONG __RPC_FAR *lplDeviceType,
            /* [string][out] */ BSTR __RPC_FAR *lpszDeviceName,
            /* [out] */ LONG __RPC_FAR *lplDeviceNumber,
            /* [out] */ LONG __RPC_FAR *lplDeviceRadix,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *EntryDeviceStatus )( 
            IActA6TEL3 __RPC_FAR * This,
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG lSize,
            /* [in] */ LONG lMonitorCycle,
            /* [size_is][in] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *FreeDeviceStatus )( 
            IActA6TEL3 __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceBlock2 )( 
            IActA6TEL3 __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lSize,
            /* [size_is][out] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceBlock2 )( 
            IActA6TEL3 __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lSize,
            /* [size_is][in] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceRandom2 )( 
            IActA6TEL3 __RPC_FAR * This,
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG lSize,
            /* [size_is][out] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceRandom2 )( 
            IActA6TEL3 __RPC_FAR * This,
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG lSize,
            /* [size_is][in] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetDevice2 )( 
            IActA6TEL3 __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [out] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetDevice2 )( 
            IActA6TEL3 __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ SHORT sData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Connect )( 
            IActA6TEL3 __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Disconnect )( 
            IActA6TEL3 __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActNetworkNumber )( 
            IActA6TEL3 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActNetworkNumber )( 
            IActA6TEL3 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActStationNumber )( 
            IActA6TEL3 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActStationNumber )( 
            IActA6TEL3 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActCpuType )( 
            IActA6TEL3 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActCpuType )( 
            IActA6TEL3 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActPortNumber )( 
            IActA6TEL3 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActPortNumber )( 
            IActA6TEL3 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActTimeOut )( 
            IActA6TEL3 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActTimeOut )( 
            IActA6TEL3 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActATCommand )( 
            IActA6TEL3 __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActATCommand )( 
            IActA6TEL3 __RPC_FAR * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActDialNumber )( 
            IActA6TEL3 __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActDialNumber )( 
            IActA6TEL3 __RPC_FAR * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActLineType )( 
            IActA6TEL3 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActLineType )( 
            IActA6TEL3 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActPassword )( 
            IActA6TEL3 __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActPassword )( 
            IActA6TEL3 __RPC_FAR * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActConnectionCDWaitTime )( 
            IActA6TEL3 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActConnectionCDWaitTime )( 
            IActA6TEL3 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActConnectionModemReportWaitTime )( 
            IActA6TEL3 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActConnectionModemReportWaitTime )( 
            IActA6TEL3 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActDisconnectionCDWaitTime )( 
            IActA6TEL3 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActDisconnectionCDWaitTime )( 
            IActA6TEL3 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActDisconnectionDelayTime )( 
            IActA6TEL3 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActDisconnectionDelayTime )( 
            IActA6TEL3 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActTransmissionDelayTime )( 
            IActA6TEL3 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActTransmissionDelayTime )( 
            IActA6TEL3 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActATCommandResponseWaitTime )( 
            IActA6TEL3 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActATCommandResponseWaitTime )( 
            IActA6TEL3 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActATCommandPasswordCancelRetryTimes )( 
            IActA6TEL3 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActATCommandPasswordCancelRetryTimes )( 
            IActA6TEL3 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActOutsideLineNumber )( 
            IActA6TEL3 __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActOutsideLineNumber )( 
            IActA6TEL3 __RPC_FAR * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActPasswordCancelResponseWaitTime )( 
            IActA6TEL3 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActPasswordCancelResponseWaitTime )( 
            IActA6TEL3 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        END_INTERFACE
    } IActA6TEL3Vtbl;

    interface IActA6TEL3
    {
        CONST_VTBL struct IActA6TEL3Vtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IActA6TEL3_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IActA6TEL3_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IActA6TEL3_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IActA6TEL3_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IActA6TEL3_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IActA6TEL3_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IActA6TEL3_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IActA6TEL3_Open(This,lplReturnCode)	\
    (This)->lpVtbl -> Open(This,lplReturnCode)

#define IActA6TEL3_Close(This,lplReturnCode)	\
    (This)->lpVtbl -> Close(This,lplReturnCode)

#define IActA6TEL3_GetDevice(This,szDevice,lplData,lplReturnCode)	\
    (This)->lpVtbl -> GetDevice(This,szDevice,lplData,lplReturnCode)

#define IActA6TEL3_SetDevice(This,szDevice,lData,lplReturnCode)	\
    (This)->lpVtbl -> SetDevice(This,szDevice,lData,lplReturnCode)

#define IActA6TEL3_ReadDeviceBlock(This,szDevice,lSize,lplData,lplReturnCode)	\
    (This)->lpVtbl -> ReadDeviceBlock(This,szDevice,lSize,lplData,lplReturnCode)

#define IActA6TEL3_WriteDeviceBlock(This,szDevice,lSize,lplData,lplReturnCode)	\
    (This)->lpVtbl -> WriteDeviceBlock(This,szDevice,lSize,lplData,lplReturnCode)

#define IActA6TEL3_ReadDeviceRandom(This,szDeviceList,lSize,lplData,lplReturnCode)	\
    (This)->lpVtbl -> ReadDeviceRandom(This,szDeviceList,lSize,lplData,lplReturnCode)

#define IActA6TEL3_WriteDeviceRandom(This,szDeviceList,lSize,lplData,lplReturnCode)	\
    (This)->lpVtbl -> WriteDeviceRandom(This,szDeviceList,lSize,lplData,lplReturnCode)

#define IActA6TEL3_ReadBuffer(This,lStartIO,lAddress,lReadSize,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> ReadBuffer(This,lStartIO,lAddress,lReadSize,lpsData,lplReturnCode)

#define IActA6TEL3_WriteBuffer(This,lStartIO,lAddress,lWriteSize,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> WriteBuffer(This,lStartIO,lAddress,lWriteSize,lpsData,lplReturnCode)

#define IActA6TEL3_GetClockData(This,lpsYear,lpsMonth,lpsDay,lpsDayOfWeek,lpsHour,lpsMinute,lpsSecond,lplReturnCode)	\
    (This)->lpVtbl -> GetClockData(This,lpsYear,lpsMonth,lpsDay,lpsDayOfWeek,lpsHour,lpsMinute,lpsSecond,lplReturnCode)

#define IActA6TEL3_SetClockData(This,sYear,sMonth,sDay,sDayOfWeek,sHour,sMinute,sSecond,lplReturnCode)	\
    (This)->lpVtbl -> SetClockData(This,sYear,sMonth,sDay,sDayOfWeek,sHour,sMinute,sSecond,lplReturnCode)

#define IActA6TEL3_GetCpuType(This,szCpuName,lplCpuCode,lplReturnCode)	\
    (This)->lpVtbl -> GetCpuType(This,szCpuName,lplCpuCode,lplReturnCode)

#define IActA6TEL3_SetCpuStatus(This,lOperation,lplReturnCode)	\
    (This)->lpVtbl -> SetCpuStatus(This,lOperation,lplReturnCode)

#define IActA6TEL3_CheckDeviceString(This,szDevice,lCheckType,lSize,lplDeviceType,lpszDeviceName,lplDeviceNumber,lplDeviceRadix,lplReturnCode)	\
    (This)->lpVtbl -> CheckDeviceString(This,szDevice,lCheckType,lSize,lplDeviceType,lpszDeviceName,lplDeviceNumber,lplDeviceRadix,lplReturnCode)

#define IActA6TEL3_EntryDeviceStatus(This,szDeviceList,lSize,lMonitorCycle,lplData,lplReturnCode)	\
    (This)->lpVtbl -> EntryDeviceStatus(This,szDeviceList,lSize,lMonitorCycle,lplData,lplReturnCode)

#define IActA6TEL3_FreeDeviceStatus(This,lplReturnCode)	\
    (This)->lpVtbl -> FreeDeviceStatus(This,lplReturnCode)

#define IActA6TEL3_ReadDeviceBlock2(This,szDevice,lSize,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> ReadDeviceBlock2(This,szDevice,lSize,lpsData,lplReturnCode)

#define IActA6TEL3_WriteDeviceBlock2(This,szDevice,lSize,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> WriteDeviceBlock2(This,szDevice,lSize,lpsData,lplReturnCode)

#define IActA6TEL3_ReadDeviceRandom2(This,szDeviceList,lSize,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> ReadDeviceRandom2(This,szDeviceList,lSize,lpsData,lplReturnCode)

#define IActA6TEL3_WriteDeviceRandom2(This,szDeviceList,lSize,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> WriteDeviceRandom2(This,szDeviceList,lSize,lpsData,lplReturnCode)

#define IActA6TEL3_GetDevice2(This,szDevice,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> GetDevice2(This,szDevice,lpsData,lplReturnCode)

#define IActA6TEL3_SetDevice2(This,szDevice,sData,lplReturnCode)	\
    (This)->lpVtbl -> SetDevice2(This,szDevice,sData,lplReturnCode)

#define IActA6TEL3_Connect(This,lplReturnCode)	\
    (This)->lpVtbl -> Connect(This,lplReturnCode)

#define IActA6TEL3_Disconnect(This,lplReturnCode)	\
    (This)->lpVtbl -> Disconnect(This,lplReturnCode)

#define IActA6TEL3_get_ActNetworkNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActNetworkNumber(This,pVal)

#define IActA6TEL3_put_ActNetworkNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActNetworkNumber(This,newVal)

#define IActA6TEL3_get_ActStationNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActStationNumber(This,pVal)

#define IActA6TEL3_put_ActStationNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActStationNumber(This,newVal)

#define IActA6TEL3_get_ActCpuType(This,pVal)	\
    (This)->lpVtbl -> get_ActCpuType(This,pVal)

#define IActA6TEL3_put_ActCpuType(This,newVal)	\
    (This)->lpVtbl -> put_ActCpuType(This,newVal)

#define IActA6TEL3_get_ActPortNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActPortNumber(This,pVal)

#define IActA6TEL3_put_ActPortNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActPortNumber(This,newVal)

#define IActA6TEL3_get_ActTimeOut(This,pVal)	\
    (This)->lpVtbl -> get_ActTimeOut(This,pVal)

#define IActA6TEL3_put_ActTimeOut(This,newVal)	\
    (This)->lpVtbl -> put_ActTimeOut(This,newVal)

#define IActA6TEL3_get_ActATCommand(This,pVal)	\
    (This)->lpVtbl -> get_ActATCommand(This,pVal)

#define IActA6TEL3_put_ActATCommand(This,newVal)	\
    (This)->lpVtbl -> put_ActATCommand(This,newVal)

#define IActA6TEL3_get_ActDialNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActDialNumber(This,pVal)

#define IActA6TEL3_put_ActDialNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActDialNumber(This,newVal)

#define IActA6TEL3_get_ActLineType(This,pVal)	\
    (This)->lpVtbl -> get_ActLineType(This,pVal)

#define IActA6TEL3_put_ActLineType(This,newVal)	\
    (This)->lpVtbl -> put_ActLineType(This,newVal)

#define IActA6TEL3_get_ActPassword(This,pVal)	\
    (This)->lpVtbl -> get_ActPassword(This,pVal)

#define IActA6TEL3_put_ActPassword(This,newVal)	\
    (This)->lpVtbl -> put_ActPassword(This,newVal)

#define IActA6TEL3_get_ActConnectionCDWaitTime(This,pVal)	\
    (This)->lpVtbl -> get_ActConnectionCDWaitTime(This,pVal)

#define IActA6TEL3_put_ActConnectionCDWaitTime(This,newVal)	\
    (This)->lpVtbl -> put_ActConnectionCDWaitTime(This,newVal)

#define IActA6TEL3_get_ActConnectionModemReportWaitTime(This,pVal)	\
    (This)->lpVtbl -> get_ActConnectionModemReportWaitTime(This,pVal)

#define IActA6TEL3_put_ActConnectionModemReportWaitTime(This,newVal)	\
    (This)->lpVtbl -> put_ActConnectionModemReportWaitTime(This,newVal)

#define IActA6TEL3_get_ActDisconnectionCDWaitTime(This,pVal)	\
    (This)->lpVtbl -> get_ActDisconnectionCDWaitTime(This,pVal)

#define IActA6TEL3_put_ActDisconnectionCDWaitTime(This,newVal)	\
    (This)->lpVtbl -> put_ActDisconnectionCDWaitTime(This,newVal)

#define IActA6TEL3_get_ActDisconnectionDelayTime(This,pVal)	\
    (This)->lpVtbl -> get_ActDisconnectionDelayTime(This,pVal)

#define IActA6TEL3_put_ActDisconnectionDelayTime(This,newVal)	\
    (This)->lpVtbl -> put_ActDisconnectionDelayTime(This,newVal)

#define IActA6TEL3_get_ActTransmissionDelayTime(This,pVal)	\
    (This)->lpVtbl -> get_ActTransmissionDelayTime(This,pVal)

#define IActA6TEL3_put_ActTransmissionDelayTime(This,newVal)	\
    (This)->lpVtbl -> put_ActTransmissionDelayTime(This,newVal)

#define IActA6TEL3_get_ActATCommandResponseWaitTime(This,pVal)	\
    (This)->lpVtbl -> get_ActATCommandResponseWaitTime(This,pVal)

#define IActA6TEL3_put_ActATCommandResponseWaitTime(This,newVal)	\
    (This)->lpVtbl -> put_ActATCommandResponseWaitTime(This,newVal)

#define IActA6TEL3_get_ActATCommandPasswordCancelRetryTimes(This,pVal)	\
    (This)->lpVtbl -> get_ActATCommandPasswordCancelRetryTimes(This,pVal)

#define IActA6TEL3_put_ActATCommandPasswordCancelRetryTimes(This,newVal)	\
    (This)->lpVtbl -> put_ActATCommandPasswordCancelRetryTimes(This,newVal)

#define IActA6TEL3_get_ActOutsideLineNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActOutsideLineNumber(This,pVal)

#define IActA6TEL3_put_ActOutsideLineNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActOutsideLineNumber(This,newVal)

#define IActA6TEL3_get_ActPasswordCancelResponseWaitTime(This,pVal)	\
    (This)->lpVtbl -> get_ActPasswordCancelResponseWaitTime(This,pVal)

#define IActA6TEL3_put_ActPasswordCancelResponseWaitTime(This,newVal)	\
    (This)->lpVtbl -> put_ActPasswordCancelResponseWaitTime(This,newVal)



#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IActA6TEL3_INTERFACE_DEFINED__ */


#ifndef __IActQ6TEL_INTERFACE_DEFINED__
#define __IActQ6TEL_INTERFACE_DEFINED__

/* interface IActQ6TEL */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IActQ6TEL;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("5713F075-6F4A-11D5-9315-009099244EFD")
    IActQ6TEL : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Open( 
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Close( 
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetDevice( 
            /* [string][in] */ BSTR szDevice,
            /* [out] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetDevice( 
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ReadDeviceBlock( 
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lSize,
            /* [size_is][out] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE WriteDeviceBlock( 
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lSize,
            /* [size_is][in] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ReadDeviceRandom( 
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG lSize,
            /* [size_is][out] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE WriteDeviceRandom( 
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG lSize,
            /* [size_is][in] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ReadBuffer( 
            /* [in] */ LONG lStartIO,
            /* [in] */ LONG lAddress,
            /* [in] */ LONG lReadSize,
            /* [size_is][out] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE WriteBuffer( 
            /* [in] */ LONG lStartIO,
            /* [in] */ LONG lAddress,
            /* [in] */ LONG lWriteSize,
            /* [size_is][in] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetClockData( 
            /* [out] */ SHORT __RPC_FAR *lpsYear,
            /* [out] */ SHORT __RPC_FAR *lpsMonth,
            /* [out] */ SHORT __RPC_FAR *lpsDay,
            /* [out] */ SHORT __RPC_FAR *lpsDayOfWeek,
            /* [out] */ SHORT __RPC_FAR *lpsHour,
            /* [out] */ SHORT __RPC_FAR *lpsMinute,
            /* [out] */ SHORT __RPC_FAR *lpsSecond,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetClockData( 
            /* [in] */ SHORT sYear,
            /* [in] */ SHORT sMonth,
            /* [in] */ SHORT sDay,
            /* [in] */ SHORT sDayOfWeek,
            /* [in] */ SHORT sHour,
            /* [in] */ SHORT sMinute,
            /* [in] */ SHORT sSecond,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetCpuType( 
            /* [string][out] */ BSTR __RPC_FAR *szCpuName,
            /* [out] */ LONG __RPC_FAR *lplCpuCode,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetCpuStatus( 
            /* [in] */ LONG lOperation,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE CheckDeviceString( 
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lCheckType,
            /* [in] */ LONG lSize,
            /* [out] */ LONG __RPC_FAR *lplDeviceType,
            /* [string][out] */ BSTR __RPC_FAR *lpszDeviceName,
            /* [out] */ LONG __RPC_FAR *lplDeviceNumber,
            /* [out] */ LONG __RPC_FAR *lplDeviceRadix,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE EntryDeviceStatus( 
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG lSize,
            /* [in] */ LONG lMonitorCycle,
            /* [size_is][in] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE FreeDeviceStatus( 
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ReadDeviceBlock2( 
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lSize,
            /* [size_is][out] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE WriteDeviceBlock2( 
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lSize,
            /* [size_is][in] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ReadDeviceRandom2( 
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG lSize,
            /* [size_is][out] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE WriteDeviceRandom2( 
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG lSize,
            /* [size_is][in] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetDevice2( 
            /* [string][in] */ BSTR szDevice,
            /* [out] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetDevice2( 
            /* [string][in] */ BSTR szDevice,
            /* [in] */ SHORT sData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Connect( 
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Disconnect( 
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActNetworkNumber( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActNetworkNumber( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActStationNumber( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActStationNumber( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActUnitNumber( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActUnitNumber( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActIONumber( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActIONumber( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActCpuType( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActCpuType( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActPortNumber( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActPortNumber( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActTimeOut( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActTimeOut( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActATCommand( 
            /* [retval][out] */ BSTR __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActATCommand( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActDialNumber( 
            /* [retval][out] */ BSTR __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActDialNumber( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActLineType( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActLineType( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActPassword( 
            /* [retval][out] */ BSTR __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActPassword( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActConnectionCDWaitTime( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActConnectionCDWaitTime( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActConnectionModemReportWaitTime( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActConnectionModemReportWaitTime( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActDisconnectionCDWaitTime( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActDisconnectionCDWaitTime( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActDisconnectionDelayTime( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActDisconnectionDelayTime( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActTransmissionDelayTime( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActTransmissionDelayTime( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActATCommandResponseWaitTime( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActATCommandResponseWaitTime( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActATCommandPasswordCancelRetryTimes( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActATCommandPasswordCancelRetryTimes( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActOutsideLineNumber( 
            /* [retval][out] */ BSTR __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActOutsideLineNumber( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActPasswordCancelResponseWaitTime( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActPasswordCancelResponseWaitTime( 
            /* [in] */ long newVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IActQ6TELVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IActQ6TEL __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IActQ6TEL __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IActQ6TEL __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IActQ6TEL __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IActQ6TEL __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IActQ6TEL __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IActQ6TEL __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Open )( 
            IActQ6TEL __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Close )( 
            IActQ6TEL __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetDevice )( 
            IActQ6TEL __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [out] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetDevice )( 
            IActQ6TEL __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceBlock )( 
            IActQ6TEL __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lSize,
            /* [size_is][out] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceBlock )( 
            IActQ6TEL __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lSize,
            /* [size_is][in] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceRandom )( 
            IActQ6TEL __RPC_FAR * This,
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG lSize,
            /* [size_is][out] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceRandom )( 
            IActQ6TEL __RPC_FAR * This,
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG lSize,
            /* [size_is][in] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadBuffer )( 
            IActQ6TEL __RPC_FAR * This,
            /* [in] */ LONG lStartIO,
            /* [in] */ LONG lAddress,
            /* [in] */ LONG lReadSize,
            /* [size_is][out] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteBuffer )( 
            IActQ6TEL __RPC_FAR * This,
            /* [in] */ LONG lStartIO,
            /* [in] */ LONG lAddress,
            /* [in] */ LONG lWriteSize,
            /* [size_is][in] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetClockData )( 
            IActQ6TEL __RPC_FAR * This,
            /* [out] */ SHORT __RPC_FAR *lpsYear,
            /* [out] */ SHORT __RPC_FAR *lpsMonth,
            /* [out] */ SHORT __RPC_FAR *lpsDay,
            /* [out] */ SHORT __RPC_FAR *lpsDayOfWeek,
            /* [out] */ SHORT __RPC_FAR *lpsHour,
            /* [out] */ SHORT __RPC_FAR *lpsMinute,
            /* [out] */ SHORT __RPC_FAR *lpsSecond,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetClockData )( 
            IActQ6TEL __RPC_FAR * This,
            /* [in] */ SHORT sYear,
            /* [in] */ SHORT sMonth,
            /* [in] */ SHORT sDay,
            /* [in] */ SHORT sDayOfWeek,
            /* [in] */ SHORT sHour,
            /* [in] */ SHORT sMinute,
            /* [in] */ SHORT sSecond,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetCpuType )( 
            IActQ6TEL __RPC_FAR * This,
            /* [string][out] */ BSTR __RPC_FAR *szCpuName,
            /* [out] */ LONG __RPC_FAR *lplCpuCode,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetCpuStatus )( 
            IActQ6TEL __RPC_FAR * This,
            /* [in] */ LONG lOperation,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CheckDeviceString )( 
            IActQ6TEL __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lCheckType,
            /* [in] */ LONG lSize,
            /* [out] */ LONG __RPC_FAR *lplDeviceType,
            /* [string][out] */ BSTR __RPC_FAR *lpszDeviceName,
            /* [out] */ LONG __RPC_FAR *lplDeviceNumber,
            /* [out] */ LONG __RPC_FAR *lplDeviceRadix,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *EntryDeviceStatus )( 
            IActQ6TEL __RPC_FAR * This,
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG lSize,
            /* [in] */ LONG lMonitorCycle,
            /* [size_is][in] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *FreeDeviceStatus )( 
            IActQ6TEL __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceBlock2 )( 
            IActQ6TEL __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lSize,
            /* [size_is][out] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceBlock2 )( 
            IActQ6TEL __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lSize,
            /* [size_is][in] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceRandom2 )( 
            IActQ6TEL __RPC_FAR * This,
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG lSize,
            /* [size_is][out] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceRandom2 )( 
            IActQ6TEL __RPC_FAR * This,
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG lSize,
            /* [size_is][in] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetDevice2 )( 
            IActQ6TEL __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [out] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetDevice2 )( 
            IActQ6TEL __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ SHORT sData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Connect )( 
            IActQ6TEL __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Disconnect )( 
            IActQ6TEL __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActNetworkNumber )( 
            IActQ6TEL __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActNetworkNumber )( 
            IActQ6TEL __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActStationNumber )( 
            IActQ6TEL __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActStationNumber )( 
            IActQ6TEL __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActUnitNumber )( 
            IActQ6TEL __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActUnitNumber )( 
            IActQ6TEL __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActIONumber )( 
            IActQ6TEL __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActIONumber )( 
            IActQ6TEL __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActCpuType )( 
            IActQ6TEL __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActCpuType )( 
            IActQ6TEL __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActPortNumber )( 
            IActQ6TEL __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActPortNumber )( 
            IActQ6TEL __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActTimeOut )( 
            IActQ6TEL __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActTimeOut )( 
            IActQ6TEL __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActATCommand )( 
            IActQ6TEL __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActATCommand )( 
            IActQ6TEL __RPC_FAR * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActDialNumber )( 
            IActQ6TEL __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActDialNumber )( 
            IActQ6TEL __RPC_FAR * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActLineType )( 
            IActQ6TEL __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActLineType )( 
            IActQ6TEL __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActPassword )( 
            IActQ6TEL __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActPassword )( 
            IActQ6TEL __RPC_FAR * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActConnectionCDWaitTime )( 
            IActQ6TEL __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActConnectionCDWaitTime )( 
            IActQ6TEL __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActConnectionModemReportWaitTime )( 
            IActQ6TEL __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActConnectionModemReportWaitTime )( 
            IActQ6TEL __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActDisconnectionCDWaitTime )( 
            IActQ6TEL __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActDisconnectionCDWaitTime )( 
            IActQ6TEL __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActDisconnectionDelayTime )( 
            IActQ6TEL __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActDisconnectionDelayTime )( 
            IActQ6TEL __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActTransmissionDelayTime )( 
            IActQ6TEL __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActTransmissionDelayTime )( 
            IActQ6TEL __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActATCommandResponseWaitTime )( 
            IActQ6TEL __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActATCommandResponseWaitTime )( 
            IActQ6TEL __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActATCommandPasswordCancelRetryTimes )( 
            IActQ6TEL __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActATCommandPasswordCancelRetryTimes )( 
            IActQ6TEL __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActOutsideLineNumber )( 
            IActQ6TEL __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActOutsideLineNumber )( 
            IActQ6TEL __RPC_FAR * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActPasswordCancelResponseWaitTime )( 
            IActQ6TEL __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActPasswordCancelResponseWaitTime )( 
            IActQ6TEL __RPC_FAR * This,
            /* [in] */ long newVal);
        
        END_INTERFACE
    } IActQ6TELVtbl;

    interface IActQ6TEL
    {
        CONST_VTBL struct IActQ6TELVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IActQ6TEL_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IActQ6TEL_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IActQ6TEL_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IActQ6TEL_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IActQ6TEL_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IActQ6TEL_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IActQ6TEL_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IActQ6TEL_Open(This,lplReturnCode)	\
    (This)->lpVtbl -> Open(This,lplReturnCode)

#define IActQ6TEL_Close(This,lplReturnCode)	\
    (This)->lpVtbl -> Close(This,lplReturnCode)

#define IActQ6TEL_GetDevice(This,szDevice,lplData,lplReturnCode)	\
    (This)->lpVtbl -> GetDevice(This,szDevice,lplData,lplReturnCode)

#define IActQ6TEL_SetDevice(This,szDevice,lData,lplReturnCode)	\
    (This)->lpVtbl -> SetDevice(This,szDevice,lData,lplReturnCode)

#define IActQ6TEL_ReadDeviceBlock(This,szDevice,lSize,lplData,lplReturnCode)	\
    (This)->lpVtbl -> ReadDeviceBlock(This,szDevice,lSize,lplData,lplReturnCode)

#define IActQ6TEL_WriteDeviceBlock(This,szDevice,lSize,lplData,lplReturnCode)	\
    (This)->lpVtbl -> WriteDeviceBlock(This,szDevice,lSize,lplData,lplReturnCode)

#define IActQ6TEL_ReadDeviceRandom(This,szDeviceList,lSize,lplData,lplReturnCode)	\
    (This)->lpVtbl -> ReadDeviceRandom(This,szDeviceList,lSize,lplData,lplReturnCode)

#define IActQ6TEL_WriteDeviceRandom(This,szDeviceList,lSize,lplData,lplReturnCode)	\
    (This)->lpVtbl -> WriteDeviceRandom(This,szDeviceList,lSize,lplData,lplReturnCode)

#define IActQ6TEL_ReadBuffer(This,lStartIO,lAddress,lReadSize,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> ReadBuffer(This,lStartIO,lAddress,lReadSize,lpsData,lplReturnCode)

#define IActQ6TEL_WriteBuffer(This,lStartIO,lAddress,lWriteSize,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> WriteBuffer(This,lStartIO,lAddress,lWriteSize,lpsData,lplReturnCode)

#define IActQ6TEL_GetClockData(This,lpsYear,lpsMonth,lpsDay,lpsDayOfWeek,lpsHour,lpsMinute,lpsSecond,lplReturnCode)	\
    (This)->lpVtbl -> GetClockData(This,lpsYear,lpsMonth,lpsDay,lpsDayOfWeek,lpsHour,lpsMinute,lpsSecond,lplReturnCode)

#define IActQ6TEL_SetClockData(This,sYear,sMonth,sDay,sDayOfWeek,sHour,sMinute,sSecond,lplReturnCode)	\
    (This)->lpVtbl -> SetClockData(This,sYear,sMonth,sDay,sDayOfWeek,sHour,sMinute,sSecond,lplReturnCode)

#define IActQ6TEL_GetCpuType(This,szCpuName,lplCpuCode,lplReturnCode)	\
    (This)->lpVtbl -> GetCpuType(This,szCpuName,lplCpuCode,lplReturnCode)

#define IActQ6TEL_SetCpuStatus(This,lOperation,lplReturnCode)	\
    (This)->lpVtbl -> SetCpuStatus(This,lOperation,lplReturnCode)

#define IActQ6TEL_CheckDeviceString(This,szDevice,lCheckType,lSize,lplDeviceType,lpszDeviceName,lplDeviceNumber,lplDeviceRadix,lplReturnCode)	\
    (This)->lpVtbl -> CheckDeviceString(This,szDevice,lCheckType,lSize,lplDeviceType,lpszDeviceName,lplDeviceNumber,lplDeviceRadix,lplReturnCode)

#define IActQ6TEL_EntryDeviceStatus(This,szDeviceList,lSize,lMonitorCycle,lplData,lplReturnCode)	\
    (This)->lpVtbl -> EntryDeviceStatus(This,szDeviceList,lSize,lMonitorCycle,lplData,lplReturnCode)

#define IActQ6TEL_FreeDeviceStatus(This,lplReturnCode)	\
    (This)->lpVtbl -> FreeDeviceStatus(This,lplReturnCode)

#define IActQ6TEL_ReadDeviceBlock2(This,szDevice,lSize,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> ReadDeviceBlock2(This,szDevice,lSize,lpsData,lplReturnCode)

#define IActQ6TEL_WriteDeviceBlock2(This,szDevice,lSize,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> WriteDeviceBlock2(This,szDevice,lSize,lpsData,lplReturnCode)

#define IActQ6TEL_ReadDeviceRandom2(This,szDeviceList,lSize,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> ReadDeviceRandom2(This,szDeviceList,lSize,lpsData,lplReturnCode)

#define IActQ6TEL_WriteDeviceRandom2(This,szDeviceList,lSize,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> WriteDeviceRandom2(This,szDeviceList,lSize,lpsData,lplReturnCode)

#define IActQ6TEL_GetDevice2(This,szDevice,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> GetDevice2(This,szDevice,lpsData,lplReturnCode)

#define IActQ6TEL_SetDevice2(This,szDevice,sData,lplReturnCode)	\
    (This)->lpVtbl -> SetDevice2(This,szDevice,sData,lplReturnCode)

#define IActQ6TEL_Connect(This,lplReturnCode)	\
    (This)->lpVtbl -> Connect(This,lplReturnCode)

#define IActQ6TEL_Disconnect(This,lplReturnCode)	\
    (This)->lpVtbl -> Disconnect(This,lplReturnCode)

#define IActQ6TEL_get_ActNetworkNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActNetworkNumber(This,pVal)

#define IActQ6TEL_put_ActNetworkNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActNetworkNumber(This,newVal)

#define IActQ6TEL_get_ActStationNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActStationNumber(This,pVal)

#define IActQ6TEL_put_ActStationNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActStationNumber(This,newVal)

#define IActQ6TEL_get_ActUnitNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActUnitNumber(This,pVal)

#define IActQ6TEL_put_ActUnitNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActUnitNumber(This,newVal)

#define IActQ6TEL_get_ActIONumber(This,pVal)	\
    (This)->lpVtbl -> get_ActIONumber(This,pVal)

#define IActQ6TEL_put_ActIONumber(This,newVal)	\
    (This)->lpVtbl -> put_ActIONumber(This,newVal)

#define IActQ6TEL_get_ActCpuType(This,pVal)	\
    (This)->lpVtbl -> get_ActCpuType(This,pVal)

#define IActQ6TEL_put_ActCpuType(This,newVal)	\
    (This)->lpVtbl -> put_ActCpuType(This,newVal)

#define IActQ6TEL_get_ActPortNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActPortNumber(This,pVal)

#define IActQ6TEL_put_ActPortNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActPortNumber(This,newVal)

#define IActQ6TEL_get_ActTimeOut(This,pVal)	\
    (This)->lpVtbl -> get_ActTimeOut(This,pVal)

#define IActQ6TEL_put_ActTimeOut(This,newVal)	\
    (This)->lpVtbl -> put_ActTimeOut(This,newVal)

#define IActQ6TEL_get_ActATCommand(This,pVal)	\
    (This)->lpVtbl -> get_ActATCommand(This,pVal)

#define IActQ6TEL_put_ActATCommand(This,newVal)	\
    (This)->lpVtbl -> put_ActATCommand(This,newVal)

#define IActQ6TEL_get_ActDialNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActDialNumber(This,pVal)

#define IActQ6TEL_put_ActDialNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActDialNumber(This,newVal)

#define IActQ6TEL_get_ActLineType(This,pVal)	\
    (This)->lpVtbl -> get_ActLineType(This,pVal)

#define IActQ6TEL_put_ActLineType(This,newVal)	\
    (This)->lpVtbl -> put_ActLineType(This,newVal)

#define IActQ6TEL_get_ActPassword(This,pVal)	\
    (This)->lpVtbl -> get_ActPassword(This,pVal)

#define IActQ6TEL_put_ActPassword(This,newVal)	\
    (This)->lpVtbl -> put_ActPassword(This,newVal)

#define IActQ6TEL_get_ActConnectionCDWaitTime(This,pVal)	\
    (This)->lpVtbl -> get_ActConnectionCDWaitTime(This,pVal)

#define IActQ6TEL_put_ActConnectionCDWaitTime(This,newVal)	\
    (This)->lpVtbl -> put_ActConnectionCDWaitTime(This,newVal)

#define IActQ6TEL_get_ActConnectionModemReportWaitTime(This,pVal)	\
    (This)->lpVtbl -> get_ActConnectionModemReportWaitTime(This,pVal)

#define IActQ6TEL_put_ActConnectionModemReportWaitTime(This,newVal)	\
    (This)->lpVtbl -> put_ActConnectionModemReportWaitTime(This,newVal)

#define IActQ6TEL_get_ActDisconnectionCDWaitTime(This,pVal)	\
    (This)->lpVtbl -> get_ActDisconnectionCDWaitTime(This,pVal)

#define IActQ6TEL_put_ActDisconnectionCDWaitTime(This,newVal)	\
    (This)->lpVtbl -> put_ActDisconnectionCDWaitTime(This,newVal)

#define IActQ6TEL_get_ActDisconnectionDelayTime(This,pVal)	\
    (This)->lpVtbl -> get_ActDisconnectionDelayTime(This,pVal)

#define IActQ6TEL_put_ActDisconnectionDelayTime(This,newVal)	\
    (This)->lpVtbl -> put_ActDisconnectionDelayTime(This,newVal)

#define IActQ6TEL_get_ActTransmissionDelayTime(This,pVal)	\
    (This)->lpVtbl -> get_ActTransmissionDelayTime(This,pVal)

#define IActQ6TEL_put_ActTransmissionDelayTime(This,newVal)	\
    (This)->lpVtbl -> put_ActTransmissionDelayTime(This,newVal)

#define IActQ6TEL_get_ActATCommandResponseWaitTime(This,pVal)	\
    (This)->lpVtbl -> get_ActATCommandResponseWaitTime(This,pVal)

#define IActQ6TEL_put_ActATCommandResponseWaitTime(This,newVal)	\
    (This)->lpVtbl -> put_ActATCommandResponseWaitTime(This,newVal)

#define IActQ6TEL_get_ActATCommandPasswordCancelRetryTimes(This,pVal)	\
    (This)->lpVtbl -> get_ActATCommandPasswordCancelRetryTimes(This,pVal)

#define IActQ6TEL_put_ActATCommandPasswordCancelRetryTimes(This,newVal)	\
    (This)->lpVtbl -> put_ActATCommandPasswordCancelRetryTimes(This,newVal)

#define IActQ6TEL_get_ActOutsideLineNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActOutsideLineNumber(This,pVal)

#define IActQ6TEL_put_ActOutsideLineNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActOutsideLineNumber(This,newVal)

#define IActQ6TEL_get_ActPasswordCancelResponseWaitTime(This,pVal)	\
    (This)->lpVtbl -> get_ActPasswordCancelResponseWaitTime(This,pVal)

#define IActQ6TEL_put_ActPasswordCancelResponseWaitTime(This,newVal)	\
    (This)->lpVtbl -> put_ActPasswordCancelResponseWaitTime(This,newVal)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActQ6TEL_Open_Proxy( 
    IActQ6TEL __RPC_FAR * This,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActQ6TEL_Open_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActQ6TEL_Close_Proxy( 
    IActQ6TEL __RPC_FAR * This,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActQ6TEL_Close_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActQ6TEL_GetDevice_Proxy( 
    IActQ6TEL __RPC_FAR * This,
    /* [string][in] */ BSTR szDevice,
    /* [out] */ LONG __RPC_FAR *lplData,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActQ6TEL_GetDevice_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActQ6TEL_SetDevice_Proxy( 
    IActQ6TEL __RPC_FAR * This,
    /* [string][in] */ BSTR szDevice,
    /* [in] */ LONG lData,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActQ6TEL_SetDevice_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActQ6TEL_ReadDeviceBlock_Proxy( 
    IActQ6TEL __RPC_FAR * This,
    /* [string][in] */ BSTR szDevice,
    /* [in] */ LONG lSize,
    /* [size_is][out] */ LONG __RPC_FAR *lplData,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActQ6TEL_ReadDeviceBlock_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActQ6TEL_WriteDeviceBlock_Proxy( 
    IActQ6TEL __RPC_FAR * This,
    /* [string][in] */ BSTR szDevice,
    /* [in] */ LONG lSize,
    /* [size_is][in] */ LONG __RPC_FAR *lplData,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActQ6TEL_WriteDeviceBlock_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActQ6TEL_ReadDeviceRandom_Proxy( 
    IActQ6TEL __RPC_FAR * This,
    /* [string][in] */ BSTR szDeviceList,
    /* [in] */ LONG lSize,
    /* [size_is][out] */ LONG __RPC_FAR *lplData,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActQ6TEL_ReadDeviceRandom_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActQ6TEL_WriteDeviceRandom_Proxy( 
    IActQ6TEL __RPC_FAR * This,
    /* [string][in] */ BSTR szDeviceList,
    /* [in] */ LONG lSize,
    /* [size_is][in] */ LONG __RPC_FAR *lplData,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActQ6TEL_WriteDeviceRandom_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActQ6TEL_ReadBuffer_Proxy( 
    IActQ6TEL __RPC_FAR * This,
    /* [in] */ LONG lStartIO,
    /* [in] */ LONG lAddress,
    /* [in] */ LONG lReadSize,
    /* [size_is][out] */ SHORT __RPC_FAR *lpsData,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActQ6TEL_ReadBuffer_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActQ6TEL_WriteBuffer_Proxy( 
    IActQ6TEL __RPC_FAR * This,
    /* [in] */ LONG lStartIO,
    /* [in] */ LONG lAddress,
    /* [in] */ LONG lWriteSize,
    /* [size_is][in] */ SHORT __RPC_FAR *lpsData,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActQ6TEL_WriteBuffer_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActQ6TEL_GetClockData_Proxy( 
    IActQ6TEL __RPC_FAR * This,
    /* [out] */ SHORT __RPC_FAR *lpsYear,
    /* [out] */ SHORT __RPC_FAR *lpsMonth,
    /* [out] */ SHORT __RPC_FAR *lpsDay,
    /* [out] */ SHORT __RPC_FAR *lpsDayOfWeek,
    /* [out] */ SHORT __RPC_FAR *lpsHour,
    /* [out] */ SHORT __RPC_FAR *lpsMinute,
    /* [out] */ SHORT __RPC_FAR *lpsSecond,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActQ6TEL_GetClockData_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActQ6TEL_SetClockData_Proxy( 
    IActQ6TEL __RPC_FAR * This,
    /* [in] */ SHORT sYear,
    /* [in] */ SHORT sMonth,
    /* [in] */ SHORT sDay,
    /* [in] */ SHORT sDayOfWeek,
    /* [in] */ SHORT sHour,
    /* [in] */ SHORT sMinute,
    /* [in] */ SHORT sSecond,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActQ6TEL_SetClockData_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActQ6TEL_GetCpuType_Proxy( 
    IActQ6TEL __RPC_FAR * This,
    /* [string][out] */ BSTR __RPC_FAR *szCpuName,
    /* [out] */ LONG __RPC_FAR *lplCpuCode,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActQ6TEL_GetCpuType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActQ6TEL_SetCpuStatus_Proxy( 
    IActQ6TEL __RPC_FAR * This,
    /* [in] */ LONG lOperation,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActQ6TEL_SetCpuStatus_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActQ6TEL_CheckDeviceString_Proxy( 
    IActQ6TEL __RPC_FAR * This,
    /* [string][in] */ BSTR szDevice,
    /* [in] */ LONG lCheckType,
    /* [in] */ LONG lSize,
    /* [out] */ LONG __RPC_FAR *lplDeviceType,
    /* [string][out] */ BSTR __RPC_FAR *lpszDeviceName,
    /* [out] */ LONG __RPC_FAR *lplDeviceNumber,
    /* [out] */ LONG __RPC_FAR *lplDeviceRadix,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActQ6TEL_CheckDeviceString_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActQ6TEL_EntryDeviceStatus_Proxy( 
    IActQ6TEL __RPC_FAR * This,
    /* [string][in] */ BSTR szDeviceList,
    /* [in] */ LONG lSize,
    /* [in] */ LONG lMonitorCycle,
    /* [size_is][in] */ LONG __RPC_FAR *lplData,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActQ6TEL_EntryDeviceStatus_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActQ6TEL_FreeDeviceStatus_Proxy( 
    IActQ6TEL __RPC_FAR * This,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActQ6TEL_FreeDeviceStatus_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActQ6TEL_ReadDeviceBlock2_Proxy( 
    IActQ6TEL __RPC_FAR * This,
    /* [string][in] */ BSTR szDevice,
    /* [in] */ LONG lSize,
    /* [size_is][out] */ SHORT __RPC_FAR *lpsData,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActQ6TEL_ReadDeviceBlock2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActQ6TEL_WriteDeviceBlock2_Proxy( 
    IActQ6TEL __RPC_FAR * This,
    /* [string][in] */ BSTR szDevice,
    /* [in] */ LONG lSize,
    /* [size_is][in] */ SHORT __RPC_FAR *lpsData,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActQ6TEL_WriteDeviceBlock2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActQ6TEL_ReadDeviceRandom2_Proxy( 
    IActQ6TEL __RPC_FAR * This,
    /* [string][in] */ BSTR szDeviceList,
    /* [in] */ LONG lSize,
    /* [size_is][out] */ SHORT __RPC_FAR *lpsData,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActQ6TEL_ReadDeviceRandom2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActQ6TEL_WriteDeviceRandom2_Proxy( 
    IActQ6TEL __RPC_FAR * This,
    /* [string][in] */ BSTR szDeviceList,
    /* [in] */ LONG lSize,
    /* [size_is][in] */ SHORT __RPC_FAR *lpsData,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActQ6TEL_WriteDeviceRandom2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActQ6TEL_GetDevice2_Proxy( 
    IActQ6TEL __RPC_FAR * This,
    /* [string][in] */ BSTR szDevice,
    /* [out] */ SHORT __RPC_FAR *lpsData,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActQ6TEL_GetDevice2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActQ6TEL_SetDevice2_Proxy( 
    IActQ6TEL __RPC_FAR * This,
    /* [string][in] */ BSTR szDevice,
    /* [in] */ SHORT sData,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActQ6TEL_SetDevice2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActQ6TEL_Connect_Proxy( 
    IActQ6TEL __RPC_FAR * This,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActQ6TEL_Connect_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActQ6TEL_Disconnect_Proxy( 
    IActQ6TEL __RPC_FAR * This,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActQ6TEL_Disconnect_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActQ6TEL_get_ActNetworkNumber_Proxy( 
    IActQ6TEL __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IActQ6TEL_get_ActNetworkNumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActQ6TEL_put_ActNetworkNumber_Proxy( 
    IActQ6TEL __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB IActQ6TEL_put_ActNetworkNumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActQ6TEL_get_ActStationNumber_Proxy( 
    IActQ6TEL __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IActQ6TEL_get_ActStationNumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActQ6TEL_put_ActStationNumber_Proxy( 
    IActQ6TEL __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB IActQ6TEL_put_ActStationNumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActQ6TEL_get_ActUnitNumber_Proxy( 
    IActQ6TEL __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IActQ6TEL_get_ActUnitNumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActQ6TEL_put_ActUnitNumber_Proxy( 
    IActQ6TEL __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB IActQ6TEL_put_ActUnitNumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActQ6TEL_get_ActIONumber_Proxy( 
    IActQ6TEL __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IActQ6TEL_get_ActIONumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActQ6TEL_put_ActIONumber_Proxy( 
    IActQ6TEL __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB IActQ6TEL_put_ActIONumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActQ6TEL_get_ActCpuType_Proxy( 
    IActQ6TEL __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IActQ6TEL_get_ActCpuType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActQ6TEL_put_ActCpuType_Proxy( 
    IActQ6TEL __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB IActQ6TEL_put_ActCpuType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActQ6TEL_get_ActPortNumber_Proxy( 
    IActQ6TEL __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IActQ6TEL_get_ActPortNumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActQ6TEL_put_ActPortNumber_Proxy( 
    IActQ6TEL __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB IActQ6TEL_put_ActPortNumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActQ6TEL_get_ActTimeOut_Proxy( 
    IActQ6TEL __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IActQ6TEL_get_ActTimeOut_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActQ6TEL_put_ActTimeOut_Proxy( 
    IActQ6TEL __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB IActQ6TEL_put_ActTimeOut_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActQ6TEL_get_ActATCommand_Proxy( 
    IActQ6TEL __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *pVal);


void __RPC_STUB IActQ6TEL_get_ActATCommand_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActQ6TEL_put_ActATCommand_Proxy( 
    IActQ6TEL __RPC_FAR * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB IActQ6TEL_put_ActATCommand_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActQ6TEL_get_ActDialNumber_Proxy( 
    IActQ6TEL __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *pVal);


void __RPC_STUB IActQ6TEL_get_ActDialNumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActQ6TEL_put_ActDialNumber_Proxy( 
    IActQ6TEL __RPC_FAR * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB IActQ6TEL_put_ActDialNumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActQ6TEL_get_ActLineType_Proxy( 
    IActQ6TEL __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IActQ6TEL_get_ActLineType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActQ6TEL_put_ActLineType_Proxy( 
    IActQ6TEL __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB IActQ6TEL_put_ActLineType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActQ6TEL_get_ActPassword_Proxy( 
    IActQ6TEL __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *pVal);


void __RPC_STUB IActQ6TEL_get_ActPassword_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActQ6TEL_put_ActPassword_Proxy( 
    IActQ6TEL __RPC_FAR * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB IActQ6TEL_put_ActPassword_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActQ6TEL_get_ActConnectionCDWaitTime_Proxy( 
    IActQ6TEL __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IActQ6TEL_get_ActConnectionCDWaitTime_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActQ6TEL_put_ActConnectionCDWaitTime_Proxy( 
    IActQ6TEL __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB IActQ6TEL_put_ActConnectionCDWaitTime_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActQ6TEL_get_ActConnectionModemReportWaitTime_Proxy( 
    IActQ6TEL __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IActQ6TEL_get_ActConnectionModemReportWaitTime_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActQ6TEL_put_ActConnectionModemReportWaitTime_Proxy( 
    IActQ6TEL __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB IActQ6TEL_put_ActConnectionModemReportWaitTime_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActQ6TEL_get_ActDisconnectionCDWaitTime_Proxy( 
    IActQ6TEL __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IActQ6TEL_get_ActDisconnectionCDWaitTime_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActQ6TEL_put_ActDisconnectionCDWaitTime_Proxy( 
    IActQ6TEL __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB IActQ6TEL_put_ActDisconnectionCDWaitTime_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActQ6TEL_get_ActDisconnectionDelayTime_Proxy( 
    IActQ6TEL __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IActQ6TEL_get_ActDisconnectionDelayTime_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActQ6TEL_put_ActDisconnectionDelayTime_Proxy( 
    IActQ6TEL __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB IActQ6TEL_put_ActDisconnectionDelayTime_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActQ6TEL_get_ActTransmissionDelayTime_Proxy( 
    IActQ6TEL __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IActQ6TEL_get_ActTransmissionDelayTime_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActQ6TEL_put_ActTransmissionDelayTime_Proxy( 
    IActQ6TEL __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB IActQ6TEL_put_ActTransmissionDelayTime_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActQ6TEL_get_ActATCommandResponseWaitTime_Proxy( 
    IActQ6TEL __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IActQ6TEL_get_ActATCommandResponseWaitTime_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActQ6TEL_put_ActATCommandResponseWaitTime_Proxy( 
    IActQ6TEL __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB IActQ6TEL_put_ActATCommandResponseWaitTime_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActQ6TEL_get_ActATCommandPasswordCancelRetryTimes_Proxy( 
    IActQ6TEL __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IActQ6TEL_get_ActATCommandPasswordCancelRetryTimes_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActQ6TEL_put_ActATCommandPasswordCancelRetryTimes_Proxy( 
    IActQ6TEL __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB IActQ6TEL_put_ActATCommandPasswordCancelRetryTimes_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActQ6TEL_get_ActOutsideLineNumber_Proxy( 
    IActQ6TEL __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *pVal);


void __RPC_STUB IActQ6TEL_get_ActOutsideLineNumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActQ6TEL_put_ActOutsideLineNumber_Proxy( 
    IActQ6TEL __RPC_FAR * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB IActQ6TEL_put_ActOutsideLineNumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActQ6TEL_get_ActPasswordCancelResponseWaitTime_Proxy( 
    IActQ6TEL __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IActQ6TEL_get_ActPasswordCancelResponseWaitTime_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActQ6TEL_put_ActPasswordCancelResponseWaitTime_Proxy( 
    IActQ6TEL __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB IActQ6TEL_put_ActPasswordCancelResponseWaitTime_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IActQ6TEL_INTERFACE_DEFINED__ */


#ifndef __IActQ6TEL2_INTERFACE_DEFINED__
#define __IActQ6TEL2_INTERFACE_DEFINED__

/* interface IActQ6TEL2 */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IActQ6TEL2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("87166038-710B-11d5-9318-009099244EFD")
    IActQ6TEL2 : public IActQ6TEL
    {
    public:
    };
    
#else 	/* C style interface */

    typedef struct IActQ6TEL2Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IActQ6TEL2 __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IActQ6TEL2 __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IActQ6TEL2 __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IActQ6TEL2 __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IActQ6TEL2 __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IActQ6TEL2 __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IActQ6TEL2 __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Open )( 
            IActQ6TEL2 __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Close )( 
            IActQ6TEL2 __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetDevice )( 
            IActQ6TEL2 __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [out] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetDevice )( 
            IActQ6TEL2 __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceBlock )( 
            IActQ6TEL2 __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lSize,
            /* [size_is][out] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceBlock )( 
            IActQ6TEL2 __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lSize,
            /* [size_is][in] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceRandom )( 
            IActQ6TEL2 __RPC_FAR * This,
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG lSize,
            /* [size_is][out] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceRandom )( 
            IActQ6TEL2 __RPC_FAR * This,
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG lSize,
            /* [size_is][in] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadBuffer )( 
            IActQ6TEL2 __RPC_FAR * This,
            /* [in] */ LONG lStartIO,
            /* [in] */ LONG lAddress,
            /* [in] */ LONG lReadSize,
            /* [size_is][out] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteBuffer )( 
            IActQ6TEL2 __RPC_FAR * This,
            /* [in] */ LONG lStartIO,
            /* [in] */ LONG lAddress,
            /* [in] */ LONG lWriteSize,
            /* [size_is][in] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetClockData )( 
            IActQ6TEL2 __RPC_FAR * This,
            /* [out] */ SHORT __RPC_FAR *lpsYear,
            /* [out] */ SHORT __RPC_FAR *lpsMonth,
            /* [out] */ SHORT __RPC_FAR *lpsDay,
            /* [out] */ SHORT __RPC_FAR *lpsDayOfWeek,
            /* [out] */ SHORT __RPC_FAR *lpsHour,
            /* [out] */ SHORT __RPC_FAR *lpsMinute,
            /* [out] */ SHORT __RPC_FAR *lpsSecond,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetClockData )( 
            IActQ6TEL2 __RPC_FAR * This,
            /* [in] */ SHORT sYear,
            /* [in] */ SHORT sMonth,
            /* [in] */ SHORT sDay,
            /* [in] */ SHORT sDayOfWeek,
            /* [in] */ SHORT sHour,
            /* [in] */ SHORT sMinute,
            /* [in] */ SHORT sSecond,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetCpuType )( 
            IActQ6TEL2 __RPC_FAR * This,
            /* [string][out] */ BSTR __RPC_FAR *szCpuName,
            /* [out] */ LONG __RPC_FAR *lplCpuCode,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetCpuStatus )( 
            IActQ6TEL2 __RPC_FAR * This,
            /* [in] */ LONG lOperation,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CheckDeviceString )( 
            IActQ6TEL2 __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lCheckType,
            /* [in] */ LONG lSize,
            /* [out] */ LONG __RPC_FAR *lplDeviceType,
            /* [string][out] */ BSTR __RPC_FAR *lpszDeviceName,
            /* [out] */ LONG __RPC_FAR *lplDeviceNumber,
            /* [out] */ LONG __RPC_FAR *lplDeviceRadix,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *EntryDeviceStatus )( 
            IActQ6TEL2 __RPC_FAR * This,
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG lSize,
            /* [in] */ LONG lMonitorCycle,
            /* [size_is][in] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *FreeDeviceStatus )( 
            IActQ6TEL2 __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceBlock2 )( 
            IActQ6TEL2 __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lSize,
            /* [size_is][out] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceBlock2 )( 
            IActQ6TEL2 __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lSize,
            /* [size_is][in] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceRandom2 )( 
            IActQ6TEL2 __RPC_FAR * This,
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG lSize,
            /* [size_is][out] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceRandom2 )( 
            IActQ6TEL2 __RPC_FAR * This,
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG lSize,
            /* [size_is][in] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetDevice2 )( 
            IActQ6TEL2 __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [out] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetDevice2 )( 
            IActQ6TEL2 __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ SHORT sData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Connect )( 
            IActQ6TEL2 __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Disconnect )( 
            IActQ6TEL2 __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActNetworkNumber )( 
            IActQ6TEL2 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActNetworkNumber )( 
            IActQ6TEL2 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActStationNumber )( 
            IActQ6TEL2 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActStationNumber )( 
            IActQ6TEL2 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActUnitNumber )( 
            IActQ6TEL2 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActUnitNumber )( 
            IActQ6TEL2 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActIONumber )( 
            IActQ6TEL2 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActIONumber )( 
            IActQ6TEL2 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActCpuType )( 
            IActQ6TEL2 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActCpuType )( 
            IActQ6TEL2 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActPortNumber )( 
            IActQ6TEL2 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActPortNumber )( 
            IActQ6TEL2 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActTimeOut )( 
            IActQ6TEL2 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActTimeOut )( 
            IActQ6TEL2 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActATCommand )( 
            IActQ6TEL2 __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActATCommand )( 
            IActQ6TEL2 __RPC_FAR * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActDialNumber )( 
            IActQ6TEL2 __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActDialNumber )( 
            IActQ6TEL2 __RPC_FAR * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActLineType )( 
            IActQ6TEL2 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActLineType )( 
            IActQ6TEL2 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActPassword )( 
            IActQ6TEL2 __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActPassword )( 
            IActQ6TEL2 __RPC_FAR * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActConnectionCDWaitTime )( 
            IActQ6TEL2 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActConnectionCDWaitTime )( 
            IActQ6TEL2 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActConnectionModemReportWaitTime )( 
            IActQ6TEL2 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActConnectionModemReportWaitTime )( 
            IActQ6TEL2 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActDisconnectionCDWaitTime )( 
            IActQ6TEL2 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActDisconnectionCDWaitTime )( 
            IActQ6TEL2 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActDisconnectionDelayTime )( 
            IActQ6TEL2 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActDisconnectionDelayTime )( 
            IActQ6TEL2 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActTransmissionDelayTime )( 
            IActQ6TEL2 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActTransmissionDelayTime )( 
            IActQ6TEL2 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActATCommandResponseWaitTime )( 
            IActQ6TEL2 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActATCommandResponseWaitTime )( 
            IActQ6TEL2 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActATCommandPasswordCancelRetryTimes )( 
            IActQ6TEL2 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActATCommandPasswordCancelRetryTimes )( 
            IActQ6TEL2 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActOutsideLineNumber )( 
            IActQ6TEL2 __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActOutsideLineNumber )( 
            IActQ6TEL2 __RPC_FAR * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActPasswordCancelResponseWaitTime )( 
            IActQ6TEL2 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActPasswordCancelResponseWaitTime )( 
            IActQ6TEL2 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        END_INTERFACE
    } IActQ6TEL2Vtbl;

    interface IActQ6TEL2
    {
        CONST_VTBL struct IActQ6TEL2Vtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IActQ6TEL2_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IActQ6TEL2_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IActQ6TEL2_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IActQ6TEL2_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IActQ6TEL2_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IActQ6TEL2_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IActQ6TEL2_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IActQ6TEL2_Open(This,lplReturnCode)	\
    (This)->lpVtbl -> Open(This,lplReturnCode)

#define IActQ6TEL2_Close(This,lplReturnCode)	\
    (This)->lpVtbl -> Close(This,lplReturnCode)

#define IActQ6TEL2_GetDevice(This,szDevice,lplData,lplReturnCode)	\
    (This)->lpVtbl -> GetDevice(This,szDevice,lplData,lplReturnCode)

#define IActQ6TEL2_SetDevice(This,szDevice,lData,lplReturnCode)	\
    (This)->lpVtbl -> SetDevice(This,szDevice,lData,lplReturnCode)

#define IActQ6TEL2_ReadDeviceBlock(This,szDevice,lSize,lplData,lplReturnCode)	\
    (This)->lpVtbl -> ReadDeviceBlock(This,szDevice,lSize,lplData,lplReturnCode)

#define IActQ6TEL2_WriteDeviceBlock(This,szDevice,lSize,lplData,lplReturnCode)	\
    (This)->lpVtbl -> WriteDeviceBlock(This,szDevice,lSize,lplData,lplReturnCode)

#define IActQ6TEL2_ReadDeviceRandom(This,szDeviceList,lSize,lplData,lplReturnCode)	\
    (This)->lpVtbl -> ReadDeviceRandom(This,szDeviceList,lSize,lplData,lplReturnCode)

#define IActQ6TEL2_WriteDeviceRandom(This,szDeviceList,lSize,lplData,lplReturnCode)	\
    (This)->lpVtbl -> WriteDeviceRandom(This,szDeviceList,lSize,lplData,lplReturnCode)

#define IActQ6TEL2_ReadBuffer(This,lStartIO,lAddress,lReadSize,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> ReadBuffer(This,lStartIO,lAddress,lReadSize,lpsData,lplReturnCode)

#define IActQ6TEL2_WriteBuffer(This,lStartIO,lAddress,lWriteSize,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> WriteBuffer(This,lStartIO,lAddress,lWriteSize,lpsData,lplReturnCode)

#define IActQ6TEL2_GetClockData(This,lpsYear,lpsMonth,lpsDay,lpsDayOfWeek,lpsHour,lpsMinute,lpsSecond,lplReturnCode)	\
    (This)->lpVtbl -> GetClockData(This,lpsYear,lpsMonth,lpsDay,lpsDayOfWeek,lpsHour,lpsMinute,lpsSecond,lplReturnCode)

#define IActQ6TEL2_SetClockData(This,sYear,sMonth,sDay,sDayOfWeek,sHour,sMinute,sSecond,lplReturnCode)	\
    (This)->lpVtbl -> SetClockData(This,sYear,sMonth,sDay,sDayOfWeek,sHour,sMinute,sSecond,lplReturnCode)

#define IActQ6TEL2_GetCpuType(This,szCpuName,lplCpuCode,lplReturnCode)	\
    (This)->lpVtbl -> GetCpuType(This,szCpuName,lplCpuCode,lplReturnCode)

#define IActQ6TEL2_SetCpuStatus(This,lOperation,lplReturnCode)	\
    (This)->lpVtbl -> SetCpuStatus(This,lOperation,lplReturnCode)

#define IActQ6TEL2_CheckDeviceString(This,szDevice,lCheckType,lSize,lplDeviceType,lpszDeviceName,lplDeviceNumber,lplDeviceRadix,lplReturnCode)	\
    (This)->lpVtbl -> CheckDeviceString(This,szDevice,lCheckType,lSize,lplDeviceType,lpszDeviceName,lplDeviceNumber,lplDeviceRadix,lplReturnCode)

#define IActQ6TEL2_EntryDeviceStatus(This,szDeviceList,lSize,lMonitorCycle,lplData,lplReturnCode)	\
    (This)->lpVtbl -> EntryDeviceStatus(This,szDeviceList,lSize,lMonitorCycle,lplData,lplReturnCode)

#define IActQ6TEL2_FreeDeviceStatus(This,lplReturnCode)	\
    (This)->lpVtbl -> FreeDeviceStatus(This,lplReturnCode)

#define IActQ6TEL2_ReadDeviceBlock2(This,szDevice,lSize,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> ReadDeviceBlock2(This,szDevice,lSize,lpsData,lplReturnCode)

#define IActQ6TEL2_WriteDeviceBlock2(This,szDevice,lSize,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> WriteDeviceBlock2(This,szDevice,lSize,lpsData,lplReturnCode)

#define IActQ6TEL2_ReadDeviceRandom2(This,szDeviceList,lSize,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> ReadDeviceRandom2(This,szDeviceList,lSize,lpsData,lplReturnCode)

#define IActQ6TEL2_WriteDeviceRandom2(This,szDeviceList,lSize,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> WriteDeviceRandom2(This,szDeviceList,lSize,lpsData,lplReturnCode)

#define IActQ6TEL2_GetDevice2(This,szDevice,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> GetDevice2(This,szDevice,lpsData,lplReturnCode)

#define IActQ6TEL2_SetDevice2(This,szDevice,sData,lplReturnCode)	\
    (This)->lpVtbl -> SetDevice2(This,szDevice,sData,lplReturnCode)

#define IActQ6TEL2_Connect(This,lplReturnCode)	\
    (This)->lpVtbl -> Connect(This,lplReturnCode)

#define IActQ6TEL2_Disconnect(This,lplReturnCode)	\
    (This)->lpVtbl -> Disconnect(This,lplReturnCode)

#define IActQ6TEL2_get_ActNetworkNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActNetworkNumber(This,pVal)

#define IActQ6TEL2_put_ActNetworkNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActNetworkNumber(This,newVal)

#define IActQ6TEL2_get_ActStationNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActStationNumber(This,pVal)

#define IActQ6TEL2_put_ActStationNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActStationNumber(This,newVal)

#define IActQ6TEL2_get_ActUnitNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActUnitNumber(This,pVal)

#define IActQ6TEL2_put_ActUnitNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActUnitNumber(This,newVal)

#define IActQ6TEL2_get_ActIONumber(This,pVal)	\
    (This)->lpVtbl -> get_ActIONumber(This,pVal)

#define IActQ6TEL2_put_ActIONumber(This,newVal)	\
    (This)->lpVtbl -> put_ActIONumber(This,newVal)

#define IActQ6TEL2_get_ActCpuType(This,pVal)	\
    (This)->lpVtbl -> get_ActCpuType(This,pVal)

#define IActQ6TEL2_put_ActCpuType(This,newVal)	\
    (This)->lpVtbl -> put_ActCpuType(This,newVal)

#define IActQ6TEL2_get_ActPortNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActPortNumber(This,pVal)

#define IActQ6TEL2_put_ActPortNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActPortNumber(This,newVal)

#define IActQ6TEL2_get_ActTimeOut(This,pVal)	\
    (This)->lpVtbl -> get_ActTimeOut(This,pVal)

#define IActQ6TEL2_put_ActTimeOut(This,newVal)	\
    (This)->lpVtbl -> put_ActTimeOut(This,newVal)

#define IActQ6TEL2_get_ActATCommand(This,pVal)	\
    (This)->lpVtbl -> get_ActATCommand(This,pVal)

#define IActQ6TEL2_put_ActATCommand(This,newVal)	\
    (This)->lpVtbl -> put_ActATCommand(This,newVal)

#define IActQ6TEL2_get_ActDialNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActDialNumber(This,pVal)

#define IActQ6TEL2_put_ActDialNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActDialNumber(This,newVal)

#define IActQ6TEL2_get_ActLineType(This,pVal)	\
    (This)->lpVtbl -> get_ActLineType(This,pVal)

#define IActQ6TEL2_put_ActLineType(This,newVal)	\
    (This)->lpVtbl -> put_ActLineType(This,newVal)

#define IActQ6TEL2_get_ActPassword(This,pVal)	\
    (This)->lpVtbl -> get_ActPassword(This,pVal)

#define IActQ6TEL2_put_ActPassword(This,newVal)	\
    (This)->lpVtbl -> put_ActPassword(This,newVal)

#define IActQ6TEL2_get_ActConnectionCDWaitTime(This,pVal)	\
    (This)->lpVtbl -> get_ActConnectionCDWaitTime(This,pVal)

#define IActQ6TEL2_put_ActConnectionCDWaitTime(This,newVal)	\
    (This)->lpVtbl -> put_ActConnectionCDWaitTime(This,newVal)

#define IActQ6TEL2_get_ActConnectionModemReportWaitTime(This,pVal)	\
    (This)->lpVtbl -> get_ActConnectionModemReportWaitTime(This,pVal)

#define IActQ6TEL2_put_ActConnectionModemReportWaitTime(This,newVal)	\
    (This)->lpVtbl -> put_ActConnectionModemReportWaitTime(This,newVal)

#define IActQ6TEL2_get_ActDisconnectionCDWaitTime(This,pVal)	\
    (This)->lpVtbl -> get_ActDisconnectionCDWaitTime(This,pVal)

#define IActQ6TEL2_put_ActDisconnectionCDWaitTime(This,newVal)	\
    (This)->lpVtbl -> put_ActDisconnectionCDWaitTime(This,newVal)

#define IActQ6TEL2_get_ActDisconnectionDelayTime(This,pVal)	\
    (This)->lpVtbl -> get_ActDisconnectionDelayTime(This,pVal)

#define IActQ6TEL2_put_ActDisconnectionDelayTime(This,newVal)	\
    (This)->lpVtbl -> put_ActDisconnectionDelayTime(This,newVal)

#define IActQ6TEL2_get_ActTransmissionDelayTime(This,pVal)	\
    (This)->lpVtbl -> get_ActTransmissionDelayTime(This,pVal)

#define IActQ6TEL2_put_ActTransmissionDelayTime(This,newVal)	\
    (This)->lpVtbl -> put_ActTransmissionDelayTime(This,newVal)

#define IActQ6TEL2_get_ActATCommandResponseWaitTime(This,pVal)	\
    (This)->lpVtbl -> get_ActATCommandResponseWaitTime(This,pVal)

#define IActQ6TEL2_put_ActATCommandResponseWaitTime(This,newVal)	\
    (This)->lpVtbl -> put_ActATCommandResponseWaitTime(This,newVal)

#define IActQ6TEL2_get_ActATCommandPasswordCancelRetryTimes(This,pVal)	\
    (This)->lpVtbl -> get_ActATCommandPasswordCancelRetryTimes(This,pVal)

#define IActQ6TEL2_put_ActATCommandPasswordCancelRetryTimes(This,newVal)	\
    (This)->lpVtbl -> put_ActATCommandPasswordCancelRetryTimes(This,newVal)

#define IActQ6TEL2_get_ActOutsideLineNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActOutsideLineNumber(This,pVal)

#define IActQ6TEL2_put_ActOutsideLineNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActOutsideLineNumber(This,newVal)

#define IActQ6TEL2_get_ActPasswordCancelResponseWaitTime(This,pVal)	\
    (This)->lpVtbl -> get_ActPasswordCancelResponseWaitTime(This,pVal)

#define IActQ6TEL2_put_ActPasswordCancelResponseWaitTime(This,newVal)	\
    (This)->lpVtbl -> put_ActPasswordCancelResponseWaitTime(This,newVal)


#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IActQ6TEL2_INTERFACE_DEFINED__ */


#ifndef __IActQ6TEL3_INTERFACE_DEFINED__
#define __IActQ6TEL3_INTERFACE_DEFINED__

/* interface IActQ6TEL3 */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IActQ6TEL3;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("87166039-710B-11d5-9318-009099244EFD")
    IActQ6TEL3 : public IActQ6TEL2
    {
    public:
    };
    
#else 	/* C style interface */

    typedef struct IActQ6TEL3Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IActQ6TEL3 __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IActQ6TEL3 __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IActQ6TEL3 __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IActQ6TEL3 __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IActQ6TEL3 __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IActQ6TEL3 __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IActQ6TEL3 __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Open )( 
            IActQ6TEL3 __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Close )( 
            IActQ6TEL3 __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetDevice )( 
            IActQ6TEL3 __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [out] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetDevice )( 
            IActQ6TEL3 __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceBlock )( 
            IActQ6TEL3 __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lSize,
            /* [size_is][out] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceBlock )( 
            IActQ6TEL3 __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lSize,
            /* [size_is][in] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceRandom )( 
            IActQ6TEL3 __RPC_FAR * This,
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG lSize,
            /* [size_is][out] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceRandom )( 
            IActQ6TEL3 __RPC_FAR * This,
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG lSize,
            /* [size_is][in] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadBuffer )( 
            IActQ6TEL3 __RPC_FAR * This,
            /* [in] */ LONG lStartIO,
            /* [in] */ LONG lAddress,
            /* [in] */ LONG lReadSize,
            /* [size_is][out] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteBuffer )( 
            IActQ6TEL3 __RPC_FAR * This,
            /* [in] */ LONG lStartIO,
            /* [in] */ LONG lAddress,
            /* [in] */ LONG lWriteSize,
            /* [size_is][in] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetClockData )( 
            IActQ6TEL3 __RPC_FAR * This,
            /* [out] */ SHORT __RPC_FAR *lpsYear,
            /* [out] */ SHORT __RPC_FAR *lpsMonth,
            /* [out] */ SHORT __RPC_FAR *lpsDay,
            /* [out] */ SHORT __RPC_FAR *lpsDayOfWeek,
            /* [out] */ SHORT __RPC_FAR *lpsHour,
            /* [out] */ SHORT __RPC_FAR *lpsMinute,
            /* [out] */ SHORT __RPC_FAR *lpsSecond,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetClockData )( 
            IActQ6TEL3 __RPC_FAR * This,
            /* [in] */ SHORT sYear,
            /* [in] */ SHORT sMonth,
            /* [in] */ SHORT sDay,
            /* [in] */ SHORT sDayOfWeek,
            /* [in] */ SHORT sHour,
            /* [in] */ SHORT sMinute,
            /* [in] */ SHORT sSecond,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetCpuType )( 
            IActQ6TEL3 __RPC_FAR * This,
            /* [string][out] */ BSTR __RPC_FAR *szCpuName,
            /* [out] */ LONG __RPC_FAR *lplCpuCode,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetCpuStatus )( 
            IActQ6TEL3 __RPC_FAR * This,
            /* [in] */ LONG lOperation,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CheckDeviceString )( 
            IActQ6TEL3 __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lCheckType,
            /* [in] */ LONG lSize,
            /* [out] */ LONG __RPC_FAR *lplDeviceType,
            /* [string][out] */ BSTR __RPC_FAR *lpszDeviceName,
            /* [out] */ LONG __RPC_FAR *lplDeviceNumber,
            /* [out] */ LONG __RPC_FAR *lplDeviceRadix,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *EntryDeviceStatus )( 
            IActQ6TEL3 __RPC_FAR * This,
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG lSize,
            /* [in] */ LONG lMonitorCycle,
            /* [size_is][in] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *FreeDeviceStatus )( 
            IActQ6TEL3 __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceBlock2 )( 
            IActQ6TEL3 __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lSize,
            /* [size_is][out] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceBlock2 )( 
            IActQ6TEL3 __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lSize,
            /* [size_is][in] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceRandom2 )( 
            IActQ6TEL3 __RPC_FAR * This,
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG lSize,
            /* [size_is][out] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceRandom2 )( 
            IActQ6TEL3 __RPC_FAR * This,
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG lSize,
            /* [size_is][in] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetDevice2 )( 
            IActQ6TEL3 __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [out] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetDevice2 )( 
            IActQ6TEL3 __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ SHORT sData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Connect )( 
            IActQ6TEL3 __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Disconnect )( 
            IActQ6TEL3 __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActNetworkNumber )( 
            IActQ6TEL3 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActNetworkNumber )( 
            IActQ6TEL3 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActStationNumber )( 
            IActQ6TEL3 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActStationNumber )( 
            IActQ6TEL3 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActUnitNumber )( 
            IActQ6TEL3 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActUnitNumber )( 
            IActQ6TEL3 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActIONumber )( 
            IActQ6TEL3 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActIONumber )( 
            IActQ6TEL3 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActCpuType )( 
            IActQ6TEL3 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActCpuType )( 
            IActQ6TEL3 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActPortNumber )( 
            IActQ6TEL3 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActPortNumber )( 
            IActQ6TEL3 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActTimeOut )( 
            IActQ6TEL3 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActTimeOut )( 
            IActQ6TEL3 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActATCommand )( 
            IActQ6TEL3 __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActATCommand )( 
            IActQ6TEL3 __RPC_FAR * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActDialNumber )( 
            IActQ6TEL3 __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActDialNumber )( 
            IActQ6TEL3 __RPC_FAR * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActLineType )( 
            IActQ6TEL3 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActLineType )( 
            IActQ6TEL3 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActPassword )( 
            IActQ6TEL3 __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActPassword )( 
            IActQ6TEL3 __RPC_FAR * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActConnectionCDWaitTime )( 
            IActQ6TEL3 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActConnectionCDWaitTime )( 
            IActQ6TEL3 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActConnectionModemReportWaitTime )( 
            IActQ6TEL3 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActConnectionModemReportWaitTime )( 
            IActQ6TEL3 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActDisconnectionCDWaitTime )( 
            IActQ6TEL3 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActDisconnectionCDWaitTime )( 
            IActQ6TEL3 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActDisconnectionDelayTime )( 
            IActQ6TEL3 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActDisconnectionDelayTime )( 
            IActQ6TEL3 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActTransmissionDelayTime )( 
            IActQ6TEL3 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActTransmissionDelayTime )( 
            IActQ6TEL3 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActATCommandResponseWaitTime )( 
            IActQ6TEL3 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActATCommandResponseWaitTime )( 
            IActQ6TEL3 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActATCommandPasswordCancelRetryTimes )( 
            IActQ6TEL3 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActATCommandPasswordCancelRetryTimes )( 
            IActQ6TEL3 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActOutsideLineNumber )( 
            IActQ6TEL3 __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActOutsideLineNumber )( 
            IActQ6TEL3 __RPC_FAR * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActPasswordCancelResponseWaitTime )( 
            IActQ6TEL3 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActPasswordCancelResponseWaitTime )( 
            IActQ6TEL3 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        END_INTERFACE
    } IActQ6TEL3Vtbl;

    interface IActQ6TEL3
    {
        CONST_VTBL struct IActQ6TEL3Vtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IActQ6TEL3_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IActQ6TEL3_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IActQ6TEL3_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IActQ6TEL3_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IActQ6TEL3_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IActQ6TEL3_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IActQ6TEL3_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IActQ6TEL3_Open(This,lplReturnCode)	\
    (This)->lpVtbl -> Open(This,lplReturnCode)

#define IActQ6TEL3_Close(This,lplReturnCode)	\
    (This)->lpVtbl -> Close(This,lplReturnCode)

#define IActQ6TEL3_GetDevice(This,szDevice,lplData,lplReturnCode)	\
    (This)->lpVtbl -> GetDevice(This,szDevice,lplData,lplReturnCode)

#define IActQ6TEL3_SetDevice(This,szDevice,lData,lplReturnCode)	\
    (This)->lpVtbl -> SetDevice(This,szDevice,lData,lplReturnCode)

#define IActQ6TEL3_ReadDeviceBlock(This,szDevice,lSize,lplData,lplReturnCode)	\
    (This)->lpVtbl -> ReadDeviceBlock(This,szDevice,lSize,lplData,lplReturnCode)

#define IActQ6TEL3_WriteDeviceBlock(This,szDevice,lSize,lplData,lplReturnCode)	\
    (This)->lpVtbl -> WriteDeviceBlock(This,szDevice,lSize,lplData,lplReturnCode)

#define IActQ6TEL3_ReadDeviceRandom(This,szDeviceList,lSize,lplData,lplReturnCode)	\
    (This)->lpVtbl -> ReadDeviceRandom(This,szDeviceList,lSize,lplData,lplReturnCode)

#define IActQ6TEL3_WriteDeviceRandom(This,szDeviceList,lSize,lplData,lplReturnCode)	\
    (This)->lpVtbl -> WriteDeviceRandom(This,szDeviceList,lSize,lplData,lplReturnCode)

#define IActQ6TEL3_ReadBuffer(This,lStartIO,lAddress,lReadSize,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> ReadBuffer(This,lStartIO,lAddress,lReadSize,lpsData,lplReturnCode)

#define IActQ6TEL3_WriteBuffer(This,lStartIO,lAddress,lWriteSize,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> WriteBuffer(This,lStartIO,lAddress,lWriteSize,lpsData,lplReturnCode)

#define IActQ6TEL3_GetClockData(This,lpsYear,lpsMonth,lpsDay,lpsDayOfWeek,lpsHour,lpsMinute,lpsSecond,lplReturnCode)	\
    (This)->lpVtbl -> GetClockData(This,lpsYear,lpsMonth,lpsDay,lpsDayOfWeek,lpsHour,lpsMinute,lpsSecond,lplReturnCode)

#define IActQ6TEL3_SetClockData(This,sYear,sMonth,sDay,sDayOfWeek,sHour,sMinute,sSecond,lplReturnCode)	\
    (This)->lpVtbl -> SetClockData(This,sYear,sMonth,sDay,sDayOfWeek,sHour,sMinute,sSecond,lplReturnCode)

#define IActQ6TEL3_GetCpuType(This,szCpuName,lplCpuCode,lplReturnCode)	\
    (This)->lpVtbl -> GetCpuType(This,szCpuName,lplCpuCode,lplReturnCode)

#define IActQ6TEL3_SetCpuStatus(This,lOperation,lplReturnCode)	\
    (This)->lpVtbl -> SetCpuStatus(This,lOperation,lplReturnCode)

#define IActQ6TEL3_CheckDeviceString(This,szDevice,lCheckType,lSize,lplDeviceType,lpszDeviceName,lplDeviceNumber,lplDeviceRadix,lplReturnCode)	\
    (This)->lpVtbl -> CheckDeviceString(This,szDevice,lCheckType,lSize,lplDeviceType,lpszDeviceName,lplDeviceNumber,lplDeviceRadix,lplReturnCode)

#define IActQ6TEL3_EntryDeviceStatus(This,szDeviceList,lSize,lMonitorCycle,lplData,lplReturnCode)	\
    (This)->lpVtbl -> EntryDeviceStatus(This,szDeviceList,lSize,lMonitorCycle,lplData,lplReturnCode)

#define IActQ6TEL3_FreeDeviceStatus(This,lplReturnCode)	\
    (This)->lpVtbl -> FreeDeviceStatus(This,lplReturnCode)

#define IActQ6TEL3_ReadDeviceBlock2(This,szDevice,lSize,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> ReadDeviceBlock2(This,szDevice,lSize,lpsData,lplReturnCode)

#define IActQ6TEL3_WriteDeviceBlock2(This,szDevice,lSize,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> WriteDeviceBlock2(This,szDevice,lSize,lpsData,lplReturnCode)

#define IActQ6TEL3_ReadDeviceRandom2(This,szDeviceList,lSize,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> ReadDeviceRandom2(This,szDeviceList,lSize,lpsData,lplReturnCode)

#define IActQ6TEL3_WriteDeviceRandom2(This,szDeviceList,lSize,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> WriteDeviceRandom2(This,szDeviceList,lSize,lpsData,lplReturnCode)

#define IActQ6TEL3_GetDevice2(This,szDevice,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> GetDevice2(This,szDevice,lpsData,lplReturnCode)

#define IActQ6TEL3_SetDevice2(This,szDevice,sData,lplReturnCode)	\
    (This)->lpVtbl -> SetDevice2(This,szDevice,sData,lplReturnCode)

#define IActQ6TEL3_Connect(This,lplReturnCode)	\
    (This)->lpVtbl -> Connect(This,lplReturnCode)

#define IActQ6TEL3_Disconnect(This,lplReturnCode)	\
    (This)->lpVtbl -> Disconnect(This,lplReturnCode)

#define IActQ6TEL3_get_ActNetworkNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActNetworkNumber(This,pVal)

#define IActQ6TEL3_put_ActNetworkNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActNetworkNumber(This,newVal)

#define IActQ6TEL3_get_ActStationNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActStationNumber(This,pVal)

#define IActQ6TEL3_put_ActStationNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActStationNumber(This,newVal)

#define IActQ6TEL3_get_ActUnitNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActUnitNumber(This,pVal)

#define IActQ6TEL3_put_ActUnitNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActUnitNumber(This,newVal)

#define IActQ6TEL3_get_ActIONumber(This,pVal)	\
    (This)->lpVtbl -> get_ActIONumber(This,pVal)

#define IActQ6TEL3_put_ActIONumber(This,newVal)	\
    (This)->lpVtbl -> put_ActIONumber(This,newVal)

#define IActQ6TEL3_get_ActCpuType(This,pVal)	\
    (This)->lpVtbl -> get_ActCpuType(This,pVal)

#define IActQ6TEL3_put_ActCpuType(This,newVal)	\
    (This)->lpVtbl -> put_ActCpuType(This,newVal)

#define IActQ6TEL3_get_ActPortNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActPortNumber(This,pVal)

#define IActQ6TEL3_put_ActPortNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActPortNumber(This,newVal)

#define IActQ6TEL3_get_ActTimeOut(This,pVal)	\
    (This)->lpVtbl -> get_ActTimeOut(This,pVal)

#define IActQ6TEL3_put_ActTimeOut(This,newVal)	\
    (This)->lpVtbl -> put_ActTimeOut(This,newVal)

#define IActQ6TEL3_get_ActATCommand(This,pVal)	\
    (This)->lpVtbl -> get_ActATCommand(This,pVal)

#define IActQ6TEL3_put_ActATCommand(This,newVal)	\
    (This)->lpVtbl -> put_ActATCommand(This,newVal)

#define IActQ6TEL3_get_ActDialNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActDialNumber(This,pVal)

#define IActQ6TEL3_put_ActDialNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActDialNumber(This,newVal)

#define IActQ6TEL3_get_ActLineType(This,pVal)	\
    (This)->lpVtbl -> get_ActLineType(This,pVal)

#define IActQ6TEL3_put_ActLineType(This,newVal)	\
    (This)->lpVtbl -> put_ActLineType(This,newVal)

#define IActQ6TEL3_get_ActPassword(This,pVal)	\
    (This)->lpVtbl -> get_ActPassword(This,pVal)

#define IActQ6TEL3_put_ActPassword(This,newVal)	\
    (This)->lpVtbl -> put_ActPassword(This,newVal)

#define IActQ6TEL3_get_ActConnectionCDWaitTime(This,pVal)	\
    (This)->lpVtbl -> get_ActConnectionCDWaitTime(This,pVal)

#define IActQ6TEL3_put_ActConnectionCDWaitTime(This,newVal)	\
    (This)->lpVtbl -> put_ActConnectionCDWaitTime(This,newVal)

#define IActQ6TEL3_get_ActConnectionModemReportWaitTime(This,pVal)	\
    (This)->lpVtbl -> get_ActConnectionModemReportWaitTime(This,pVal)

#define IActQ6TEL3_put_ActConnectionModemReportWaitTime(This,newVal)	\
    (This)->lpVtbl -> put_ActConnectionModemReportWaitTime(This,newVal)

#define IActQ6TEL3_get_ActDisconnectionCDWaitTime(This,pVal)	\
    (This)->lpVtbl -> get_ActDisconnectionCDWaitTime(This,pVal)

#define IActQ6TEL3_put_ActDisconnectionCDWaitTime(This,newVal)	\
    (This)->lpVtbl -> put_ActDisconnectionCDWaitTime(This,newVal)

#define IActQ6TEL3_get_ActDisconnectionDelayTime(This,pVal)	\
    (This)->lpVtbl -> get_ActDisconnectionDelayTime(This,pVal)

#define IActQ6TEL3_put_ActDisconnectionDelayTime(This,newVal)	\
    (This)->lpVtbl -> put_ActDisconnectionDelayTime(This,newVal)

#define IActQ6TEL3_get_ActTransmissionDelayTime(This,pVal)	\
    (This)->lpVtbl -> get_ActTransmissionDelayTime(This,pVal)

#define IActQ6TEL3_put_ActTransmissionDelayTime(This,newVal)	\
    (This)->lpVtbl -> put_ActTransmissionDelayTime(This,newVal)

#define IActQ6TEL3_get_ActATCommandResponseWaitTime(This,pVal)	\
    (This)->lpVtbl -> get_ActATCommandResponseWaitTime(This,pVal)

#define IActQ6TEL3_put_ActATCommandResponseWaitTime(This,newVal)	\
    (This)->lpVtbl -> put_ActATCommandResponseWaitTime(This,newVal)

#define IActQ6TEL3_get_ActATCommandPasswordCancelRetryTimes(This,pVal)	\
    (This)->lpVtbl -> get_ActATCommandPasswordCancelRetryTimes(This,pVal)

#define IActQ6TEL3_put_ActATCommandPasswordCancelRetryTimes(This,newVal)	\
    (This)->lpVtbl -> put_ActATCommandPasswordCancelRetryTimes(This,newVal)

#define IActQ6TEL3_get_ActOutsideLineNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActOutsideLineNumber(This,pVal)

#define IActQ6TEL3_put_ActOutsideLineNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActOutsideLineNumber(This,newVal)

#define IActQ6TEL3_get_ActPasswordCancelResponseWaitTime(This,pVal)	\
    (This)->lpVtbl -> get_ActPasswordCancelResponseWaitTime(This,pVal)

#define IActQ6TEL3_put_ActPasswordCancelResponseWaitTime(This,newVal)	\
    (This)->lpVtbl -> put_ActPasswordCancelResponseWaitTime(This,newVal)



#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IActQ6TEL3_INTERFACE_DEFINED__ */


#ifndef __IActFXCPUTEL_INTERFACE_DEFINED__
#define __IActFXCPUTEL_INTERFACE_DEFINED__

/* interface IActFXCPUTEL */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IActFXCPUTEL;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("5713F078-6F4A-11D5-9315-009099244EFD")
    IActFXCPUTEL : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Open( 
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Close( 
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetDevice( 
            /* [string][in] */ BSTR szDevice,
            /* [out] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetDevice( 
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ReadDeviceBlock( 
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lSize,
            /* [size_is][out] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE WriteDeviceBlock( 
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lSize,
            /* [size_is][in] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ReadDeviceRandom( 
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG lSize,
            /* [size_is][out] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE WriteDeviceRandom( 
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG lSize,
            /* [size_is][in] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ReadBuffer( 
            /* [in] */ LONG lStartIO,
            /* [in] */ LONG lAddress,
            /* [in] */ LONG lReadSize,
            /* [size_is][out] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE WriteBuffer( 
            /* [in] */ LONG lStartIO,
            /* [in] */ LONG lAddress,
            /* [in] */ LONG lWriteSize,
            /* [size_is][in] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetClockData( 
            /* [out] */ SHORT __RPC_FAR *lpsYear,
            /* [out] */ SHORT __RPC_FAR *lpsMonth,
            /* [out] */ SHORT __RPC_FAR *lpsDay,
            /* [out] */ SHORT __RPC_FAR *lpsDayOfWeek,
            /* [out] */ SHORT __RPC_FAR *lpsHour,
            /* [out] */ SHORT __RPC_FAR *lpsMinute,
            /* [out] */ SHORT __RPC_FAR *lpsSecond,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetClockData( 
            /* [in] */ SHORT sYear,
            /* [in] */ SHORT sMonth,
            /* [in] */ SHORT sDay,
            /* [in] */ SHORT sDayOfWeek,
            /* [in] */ SHORT sHour,
            /* [in] */ SHORT sMinute,
            /* [in] */ SHORT sSecond,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetCpuType( 
            /* [string][out] */ BSTR __RPC_FAR *szCpuName,
            /* [out] */ LONG __RPC_FAR *lplCpuCode,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetCpuStatus( 
            /* [in] */ LONG lOperation,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE CheckDeviceString( 
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lCheckType,
            /* [in] */ LONG lSize,
            /* [out] */ LONG __RPC_FAR *lplDeviceType,
            /* [string][out] */ BSTR __RPC_FAR *lpszDeviceName,
            /* [out] */ LONG __RPC_FAR *lplDeviceNumber,
            /* [out] */ LONG __RPC_FAR *lplDeviceRadix,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE EntryDeviceStatus( 
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG lSize,
            /* [in] */ LONG lMonitorCycle,
            /* [size_is][in] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE FreeDeviceStatus( 
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ReadDeviceBlock2( 
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lSize,
            /* [size_is][out] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE WriteDeviceBlock2( 
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lSize,
            /* [size_is][in] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ReadDeviceRandom2( 
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG lSize,
            /* [size_is][out] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE WriteDeviceRandom2( 
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG lSize,
            /* [size_is][in] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetDevice2( 
            /* [string][in] */ BSTR szDevice,
            /* [out] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetDevice2( 
            /* [string][in] */ BSTR szDevice,
            /* [in] */ SHORT sData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Connect( 
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Disconnect( 
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActCpuType( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActCpuType( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActPortNumber( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActPortNumber( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActTimeOut( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActTimeOut( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActATCommand( 
            /* [retval][out] */ BSTR __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActATCommand( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActDialNumber( 
            /* [retval][out] */ BSTR __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActDialNumber( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActLineType( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActLineType( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActConnectionCDWaitTime( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActConnectionCDWaitTime( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActConnectionModemReportWaitTime( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActConnectionModemReportWaitTime( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActDisconnectionCDWaitTime( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActDisconnectionCDWaitTime( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActDisconnectionDelayTime( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActDisconnectionDelayTime( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActTransmissionDelayTime( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActTransmissionDelayTime( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActATCommandResponseWaitTime( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActATCommandResponseWaitTime( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActATCommandPasswordCancelRetryTimes( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActATCommandPasswordCancelRetryTimes( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActOutsideLineNumber( 
            /* [retval][out] */ BSTR __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActOutsideLineNumber( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActPasswordCancelResponseWaitTime( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActPasswordCancelResponseWaitTime( 
            /* [in] */ long newVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IActFXCPUTELVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IActFXCPUTEL __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IActFXCPUTEL __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IActFXCPUTEL __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IActFXCPUTEL __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IActFXCPUTEL __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IActFXCPUTEL __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IActFXCPUTEL __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Open )( 
            IActFXCPUTEL __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Close )( 
            IActFXCPUTEL __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetDevice )( 
            IActFXCPUTEL __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [out] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetDevice )( 
            IActFXCPUTEL __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceBlock )( 
            IActFXCPUTEL __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lSize,
            /* [size_is][out] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceBlock )( 
            IActFXCPUTEL __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lSize,
            /* [size_is][in] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceRandom )( 
            IActFXCPUTEL __RPC_FAR * This,
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG lSize,
            /* [size_is][out] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceRandom )( 
            IActFXCPUTEL __RPC_FAR * This,
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG lSize,
            /* [size_is][in] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadBuffer )( 
            IActFXCPUTEL __RPC_FAR * This,
            /* [in] */ LONG lStartIO,
            /* [in] */ LONG lAddress,
            /* [in] */ LONG lReadSize,
            /* [size_is][out] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteBuffer )( 
            IActFXCPUTEL __RPC_FAR * This,
            /* [in] */ LONG lStartIO,
            /* [in] */ LONG lAddress,
            /* [in] */ LONG lWriteSize,
            /* [size_is][in] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetClockData )( 
            IActFXCPUTEL __RPC_FAR * This,
            /* [out] */ SHORT __RPC_FAR *lpsYear,
            /* [out] */ SHORT __RPC_FAR *lpsMonth,
            /* [out] */ SHORT __RPC_FAR *lpsDay,
            /* [out] */ SHORT __RPC_FAR *lpsDayOfWeek,
            /* [out] */ SHORT __RPC_FAR *lpsHour,
            /* [out] */ SHORT __RPC_FAR *lpsMinute,
            /* [out] */ SHORT __RPC_FAR *lpsSecond,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetClockData )( 
            IActFXCPUTEL __RPC_FAR * This,
            /* [in] */ SHORT sYear,
            /* [in] */ SHORT sMonth,
            /* [in] */ SHORT sDay,
            /* [in] */ SHORT sDayOfWeek,
            /* [in] */ SHORT sHour,
            /* [in] */ SHORT sMinute,
            /* [in] */ SHORT sSecond,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetCpuType )( 
            IActFXCPUTEL __RPC_FAR * This,
            /* [string][out] */ BSTR __RPC_FAR *szCpuName,
            /* [out] */ LONG __RPC_FAR *lplCpuCode,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetCpuStatus )( 
            IActFXCPUTEL __RPC_FAR * This,
            /* [in] */ LONG lOperation,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CheckDeviceString )( 
            IActFXCPUTEL __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lCheckType,
            /* [in] */ LONG lSize,
            /* [out] */ LONG __RPC_FAR *lplDeviceType,
            /* [string][out] */ BSTR __RPC_FAR *lpszDeviceName,
            /* [out] */ LONG __RPC_FAR *lplDeviceNumber,
            /* [out] */ LONG __RPC_FAR *lplDeviceRadix,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *EntryDeviceStatus )( 
            IActFXCPUTEL __RPC_FAR * This,
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG lSize,
            /* [in] */ LONG lMonitorCycle,
            /* [size_is][in] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *FreeDeviceStatus )( 
            IActFXCPUTEL __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceBlock2 )( 
            IActFXCPUTEL __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lSize,
            /* [size_is][out] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceBlock2 )( 
            IActFXCPUTEL __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lSize,
            /* [size_is][in] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceRandom2 )( 
            IActFXCPUTEL __RPC_FAR * This,
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG lSize,
            /* [size_is][out] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceRandom2 )( 
            IActFXCPUTEL __RPC_FAR * This,
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG lSize,
            /* [size_is][in] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetDevice2 )( 
            IActFXCPUTEL __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [out] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetDevice2 )( 
            IActFXCPUTEL __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ SHORT sData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Connect )( 
            IActFXCPUTEL __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Disconnect )( 
            IActFXCPUTEL __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActCpuType )( 
            IActFXCPUTEL __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActCpuType )( 
            IActFXCPUTEL __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActPortNumber )( 
            IActFXCPUTEL __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActPortNumber )( 
            IActFXCPUTEL __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActTimeOut )( 
            IActFXCPUTEL __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActTimeOut )( 
            IActFXCPUTEL __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActATCommand )( 
            IActFXCPUTEL __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActATCommand )( 
            IActFXCPUTEL __RPC_FAR * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActDialNumber )( 
            IActFXCPUTEL __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActDialNumber )( 
            IActFXCPUTEL __RPC_FAR * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActLineType )( 
            IActFXCPUTEL __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActLineType )( 
            IActFXCPUTEL __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActConnectionCDWaitTime )( 
            IActFXCPUTEL __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActConnectionCDWaitTime )( 
            IActFXCPUTEL __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActConnectionModemReportWaitTime )( 
            IActFXCPUTEL __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActConnectionModemReportWaitTime )( 
            IActFXCPUTEL __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActDisconnectionCDWaitTime )( 
            IActFXCPUTEL __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActDisconnectionCDWaitTime )( 
            IActFXCPUTEL __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActDisconnectionDelayTime )( 
            IActFXCPUTEL __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActDisconnectionDelayTime )( 
            IActFXCPUTEL __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActTransmissionDelayTime )( 
            IActFXCPUTEL __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActTransmissionDelayTime )( 
            IActFXCPUTEL __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActATCommandResponseWaitTime )( 
            IActFXCPUTEL __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActATCommandResponseWaitTime )( 
            IActFXCPUTEL __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActATCommandPasswordCancelRetryTimes )( 
            IActFXCPUTEL __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActATCommandPasswordCancelRetryTimes )( 
            IActFXCPUTEL __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActOutsideLineNumber )( 
            IActFXCPUTEL __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActOutsideLineNumber )( 
            IActFXCPUTEL __RPC_FAR * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActPasswordCancelResponseWaitTime )( 
            IActFXCPUTEL __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActPasswordCancelResponseWaitTime )( 
            IActFXCPUTEL __RPC_FAR * This,
            /* [in] */ long newVal);
        
        END_INTERFACE
    } IActFXCPUTELVtbl;

    interface IActFXCPUTEL
    {
        CONST_VTBL struct IActFXCPUTELVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IActFXCPUTEL_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IActFXCPUTEL_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IActFXCPUTEL_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IActFXCPUTEL_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IActFXCPUTEL_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IActFXCPUTEL_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IActFXCPUTEL_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IActFXCPUTEL_Open(This,lplReturnCode)	\
    (This)->lpVtbl -> Open(This,lplReturnCode)

#define IActFXCPUTEL_Close(This,lplReturnCode)	\
    (This)->lpVtbl -> Close(This,lplReturnCode)

#define IActFXCPUTEL_GetDevice(This,szDevice,lplData,lplReturnCode)	\
    (This)->lpVtbl -> GetDevice(This,szDevice,lplData,lplReturnCode)

#define IActFXCPUTEL_SetDevice(This,szDevice,lData,lplReturnCode)	\
    (This)->lpVtbl -> SetDevice(This,szDevice,lData,lplReturnCode)

#define IActFXCPUTEL_ReadDeviceBlock(This,szDevice,lSize,lplData,lplReturnCode)	\
    (This)->lpVtbl -> ReadDeviceBlock(This,szDevice,lSize,lplData,lplReturnCode)

#define IActFXCPUTEL_WriteDeviceBlock(This,szDevice,lSize,lplData,lplReturnCode)	\
    (This)->lpVtbl -> WriteDeviceBlock(This,szDevice,lSize,lplData,lplReturnCode)

#define IActFXCPUTEL_ReadDeviceRandom(This,szDeviceList,lSize,lplData,lplReturnCode)	\
    (This)->lpVtbl -> ReadDeviceRandom(This,szDeviceList,lSize,lplData,lplReturnCode)

#define IActFXCPUTEL_WriteDeviceRandom(This,szDeviceList,lSize,lplData,lplReturnCode)	\
    (This)->lpVtbl -> WriteDeviceRandom(This,szDeviceList,lSize,lplData,lplReturnCode)

#define IActFXCPUTEL_ReadBuffer(This,lStartIO,lAddress,lReadSize,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> ReadBuffer(This,lStartIO,lAddress,lReadSize,lpsData,lplReturnCode)

#define IActFXCPUTEL_WriteBuffer(This,lStartIO,lAddress,lWriteSize,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> WriteBuffer(This,lStartIO,lAddress,lWriteSize,lpsData,lplReturnCode)

#define IActFXCPUTEL_GetClockData(This,lpsYear,lpsMonth,lpsDay,lpsDayOfWeek,lpsHour,lpsMinute,lpsSecond,lplReturnCode)	\
    (This)->lpVtbl -> GetClockData(This,lpsYear,lpsMonth,lpsDay,lpsDayOfWeek,lpsHour,lpsMinute,lpsSecond,lplReturnCode)

#define IActFXCPUTEL_SetClockData(This,sYear,sMonth,sDay,sDayOfWeek,sHour,sMinute,sSecond,lplReturnCode)	\
    (This)->lpVtbl -> SetClockData(This,sYear,sMonth,sDay,sDayOfWeek,sHour,sMinute,sSecond,lplReturnCode)

#define IActFXCPUTEL_GetCpuType(This,szCpuName,lplCpuCode,lplReturnCode)	\
    (This)->lpVtbl -> GetCpuType(This,szCpuName,lplCpuCode,lplReturnCode)

#define IActFXCPUTEL_SetCpuStatus(This,lOperation,lplReturnCode)	\
    (This)->lpVtbl -> SetCpuStatus(This,lOperation,lplReturnCode)

#define IActFXCPUTEL_CheckDeviceString(This,szDevice,lCheckType,lSize,lplDeviceType,lpszDeviceName,lplDeviceNumber,lplDeviceRadix,lplReturnCode)	\
    (This)->lpVtbl -> CheckDeviceString(This,szDevice,lCheckType,lSize,lplDeviceType,lpszDeviceName,lplDeviceNumber,lplDeviceRadix,lplReturnCode)

#define IActFXCPUTEL_EntryDeviceStatus(This,szDeviceList,lSize,lMonitorCycle,lplData,lplReturnCode)	\
    (This)->lpVtbl -> EntryDeviceStatus(This,szDeviceList,lSize,lMonitorCycle,lplData,lplReturnCode)

#define IActFXCPUTEL_FreeDeviceStatus(This,lplReturnCode)	\
    (This)->lpVtbl -> FreeDeviceStatus(This,lplReturnCode)

#define IActFXCPUTEL_ReadDeviceBlock2(This,szDevice,lSize,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> ReadDeviceBlock2(This,szDevice,lSize,lpsData,lplReturnCode)

#define IActFXCPUTEL_WriteDeviceBlock2(This,szDevice,lSize,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> WriteDeviceBlock2(This,szDevice,lSize,lpsData,lplReturnCode)

#define IActFXCPUTEL_ReadDeviceRandom2(This,szDeviceList,lSize,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> ReadDeviceRandom2(This,szDeviceList,lSize,lpsData,lplReturnCode)

#define IActFXCPUTEL_WriteDeviceRandom2(This,szDeviceList,lSize,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> WriteDeviceRandom2(This,szDeviceList,lSize,lpsData,lplReturnCode)

#define IActFXCPUTEL_GetDevice2(This,szDevice,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> GetDevice2(This,szDevice,lpsData,lplReturnCode)

#define IActFXCPUTEL_SetDevice2(This,szDevice,sData,lplReturnCode)	\
    (This)->lpVtbl -> SetDevice2(This,szDevice,sData,lplReturnCode)

#define IActFXCPUTEL_Connect(This,lplReturnCode)	\
    (This)->lpVtbl -> Connect(This,lplReturnCode)

#define IActFXCPUTEL_Disconnect(This,lplReturnCode)	\
    (This)->lpVtbl -> Disconnect(This,lplReturnCode)

#define IActFXCPUTEL_get_ActCpuType(This,pVal)	\
    (This)->lpVtbl -> get_ActCpuType(This,pVal)

#define IActFXCPUTEL_put_ActCpuType(This,newVal)	\
    (This)->lpVtbl -> put_ActCpuType(This,newVal)

#define IActFXCPUTEL_get_ActPortNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActPortNumber(This,pVal)

#define IActFXCPUTEL_put_ActPortNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActPortNumber(This,newVal)

#define IActFXCPUTEL_get_ActTimeOut(This,pVal)	\
    (This)->lpVtbl -> get_ActTimeOut(This,pVal)

#define IActFXCPUTEL_put_ActTimeOut(This,newVal)	\
    (This)->lpVtbl -> put_ActTimeOut(This,newVal)

#define IActFXCPUTEL_get_ActATCommand(This,pVal)	\
    (This)->lpVtbl -> get_ActATCommand(This,pVal)

#define IActFXCPUTEL_put_ActATCommand(This,newVal)	\
    (This)->lpVtbl -> put_ActATCommand(This,newVal)

#define IActFXCPUTEL_get_ActDialNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActDialNumber(This,pVal)

#define IActFXCPUTEL_put_ActDialNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActDialNumber(This,newVal)

#define IActFXCPUTEL_get_ActLineType(This,pVal)	\
    (This)->lpVtbl -> get_ActLineType(This,pVal)

#define IActFXCPUTEL_put_ActLineType(This,newVal)	\
    (This)->lpVtbl -> put_ActLineType(This,newVal)

#define IActFXCPUTEL_get_ActConnectionCDWaitTime(This,pVal)	\
    (This)->lpVtbl -> get_ActConnectionCDWaitTime(This,pVal)

#define IActFXCPUTEL_put_ActConnectionCDWaitTime(This,newVal)	\
    (This)->lpVtbl -> put_ActConnectionCDWaitTime(This,newVal)

#define IActFXCPUTEL_get_ActConnectionModemReportWaitTime(This,pVal)	\
    (This)->lpVtbl -> get_ActConnectionModemReportWaitTime(This,pVal)

#define IActFXCPUTEL_put_ActConnectionModemReportWaitTime(This,newVal)	\
    (This)->lpVtbl -> put_ActConnectionModemReportWaitTime(This,newVal)

#define IActFXCPUTEL_get_ActDisconnectionCDWaitTime(This,pVal)	\
    (This)->lpVtbl -> get_ActDisconnectionCDWaitTime(This,pVal)

#define IActFXCPUTEL_put_ActDisconnectionCDWaitTime(This,newVal)	\
    (This)->lpVtbl -> put_ActDisconnectionCDWaitTime(This,newVal)

#define IActFXCPUTEL_get_ActDisconnectionDelayTime(This,pVal)	\
    (This)->lpVtbl -> get_ActDisconnectionDelayTime(This,pVal)

#define IActFXCPUTEL_put_ActDisconnectionDelayTime(This,newVal)	\
    (This)->lpVtbl -> put_ActDisconnectionDelayTime(This,newVal)

#define IActFXCPUTEL_get_ActTransmissionDelayTime(This,pVal)	\
    (This)->lpVtbl -> get_ActTransmissionDelayTime(This,pVal)

#define IActFXCPUTEL_put_ActTransmissionDelayTime(This,newVal)	\
    (This)->lpVtbl -> put_ActTransmissionDelayTime(This,newVal)

#define IActFXCPUTEL_get_ActATCommandResponseWaitTime(This,pVal)	\
    (This)->lpVtbl -> get_ActATCommandResponseWaitTime(This,pVal)

#define IActFXCPUTEL_put_ActATCommandResponseWaitTime(This,newVal)	\
    (This)->lpVtbl -> put_ActATCommandResponseWaitTime(This,newVal)

#define IActFXCPUTEL_get_ActATCommandPasswordCancelRetryTimes(This,pVal)	\
    (This)->lpVtbl -> get_ActATCommandPasswordCancelRetryTimes(This,pVal)

#define IActFXCPUTEL_put_ActATCommandPasswordCancelRetryTimes(This,newVal)	\
    (This)->lpVtbl -> put_ActATCommandPasswordCancelRetryTimes(This,newVal)

#define IActFXCPUTEL_get_ActOutsideLineNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActOutsideLineNumber(This,pVal)

#define IActFXCPUTEL_put_ActOutsideLineNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActOutsideLineNumber(This,newVal)

#define IActFXCPUTEL_get_ActPasswordCancelResponseWaitTime(This,pVal)	\
    (This)->lpVtbl -> get_ActPasswordCancelResponseWaitTime(This,pVal)

#define IActFXCPUTEL_put_ActPasswordCancelResponseWaitTime(This,newVal)	\
    (This)->lpVtbl -> put_ActPasswordCancelResponseWaitTime(This,newVal)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActFXCPUTEL_Open_Proxy( 
    IActFXCPUTEL __RPC_FAR * This,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActFXCPUTEL_Open_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActFXCPUTEL_Close_Proxy( 
    IActFXCPUTEL __RPC_FAR * This,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActFXCPUTEL_Close_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActFXCPUTEL_GetDevice_Proxy( 
    IActFXCPUTEL __RPC_FAR * This,
    /* [string][in] */ BSTR szDevice,
    /* [out] */ LONG __RPC_FAR *lplData,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActFXCPUTEL_GetDevice_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActFXCPUTEL_SetDevice_Proxy( 
    IActFXCPUTEL __RPC_FAR * This,
    /* [string][in] */ BSTR szDevice,
    /* [in] */ LONG lData,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActFXCPUTEL_SetDevice_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActFXCPUTEL_ReadDeviceBlock_Proxy( 
    IActFXCPUTEL __RPC_FAR * This,
    /* [string][in] */ BSTR szDevice,
    /* [in] */ LONG lSize,
    /* [size_is][out] */ LONG __RPC_FAR *lplData,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActFXCPUTEL_ReadDeviceBlock_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActFXCPUTEL_WriteDeviceBlock_Proxy( 
    IActFXCPUTEL __RPC_FAR * This,
    /* [string][in] */ BSTR szDevice,
    /* [in] */ LONG lSize,
    /* [size_is][in] */ LONG __RPC_FAR *lplData,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActFXCPUTEL_WriteDeviceBlock_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActFXCPUTEL_ReadDeviceRandom_Proxy( 
    IActFXCPUTEL __RPC_FAR * This,
    /* [string][in] */ BSTR szDeviceList,
    /* [in] */ LONG lSize,
    /* [size_is][out] */ LONG __RPC_FAR *lplData,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActFXCPUTEL_ReadDeviceRandom_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActFXCPUTEL_WriteDeviceRandom_Proxy( 
    IActFXCPUTEL __RPC_FAR * This,
    /* [string][in] */ BSTR szDeviceList,
    /* [in] */ LONG lSize,
    /* [size_is][in] */ LONG __RPC_FAR *lplData,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActFXCPUTEL_WriteDeviceRandom_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActFXCPUTEL_ReadBuffer_Proxy( 
    IActFXCPUTEL __RPC_FAR * This,
    /* [in] */ LONG lStartIO,
    /* [in] */ LONG lAddress,
    /* [in] */ LONG lReadSize,
    /* [size_is][out] */ SHORT __RPC_FAR *lpsData,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActFXCPUTEL_ReadBuffer_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActFXCPUTEL_WriteBuffer_Proxy( 
    IActFXCPUTEL __RPC_FAR * This,
    /* [in] */ LONG lStartIO,
    /* [in] */ LONG lAddress,
    /* [in] */ LONG lWriteSize,
    /* [size_is][in] */ SHORT __RPC_FAR *lpsData,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActFXCPUTEL_WriteBuffer_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActFXCPUTEL_GetClockData_Proxy( 
    IActFXCPUTEL __RPC_FAR * This,
    /* [out] */ SHORT __RPC_FAR *lpsYear,
    /* [out] */ SHORT __RPC_FAR *lpsMonth,
    /* [out] */ SHORT __RPC_FAR *lpsDay,
    /* [out] */ SHORT __RPC_FAR *lpsDayOfWeek,
    /* [out] */ SHORT __RPC_FAR *lpsHour,
    /* [out] */ SHORT __RPC_FAR *lpsMinute,
    /* [out] */ SHORT __RPC_FAR *lpsSecond,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActFXCPUTEL_GetClockData_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActFXCPUTEL_SetClockData_Proxy( 
    IActFXCPUTEL __RPC_FAR * This,
    /* [in] */ SHORT sYear,
    /* [in] */ SHORT sMonth,
    /* [in] */ SHORT sDay,
    /* [in] */ SHORT sDayOfWeek,
    /* [in] */ SHORT sHour,
    /* [in] */ SHORT sMinute,
    /* [in] */ SHORT sSecond,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActFXCPUTEL_SetClockData_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActFXCPUTEL_GetCpuType_Proxy( 
    IActFXCPUTEL __RPC_FAR * This,
    /* [string][out] */ BSTR __RPC_FAR *szCpuName,
    /* [out] */ LONG __RPC_FAR *lplCpuCode,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActFXCPUTEL_GetCpuType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActFXCPUTEL_SetCpuStatus_Proxy( 
    IActFXCPUTEL __RPC_FAR * This,
    /* [in] */ LONG lOperation,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActFXCPUTEL_SetCpuStatus_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActFXCPUTEL_CheckDeviceString_Proxy( 
    IActFXCPUTEL __RPC_FAR * This,
    /* [string][in] */ BSTR szDevice,
    /* [in] */ LONG lCheckType,
    /* [in] */ LONG lSize,
    /* [out] */ LONG __RPC_FAR *lplDeviceType,
    /* [string][out] */ BSTR __RPC_FAR *lpszDeviceName,
    /* [out] */ LONG __RPC_FAR *lplDeviceNumber,
    /* [out] */ LONG __RPC_FAR *lplDeviceRadix,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActFXCPUTEL_CheckDeviceString_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActFXCPUTEL_EntryDeviceStatus_Proxy( 
    IActFXCPUTEL __RPC_FAR * This,
    /* [string][in] */ BSTR szDeviceList,
    /* [in] */ LONG lSize,
    /* [in] */ LONG lMonitorCycle,
    /* [size_is][in] */ LONG __RPC_FAR *lplData,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActFXCPUTEL_EntryDeviceStatus_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActFXCPUTEL_FreeDeviceStatus_Proxy( 
    IActFXCPUTEL __RPC_FAR * This,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActFXCPUTEL_FreeDeviceStatus_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActFXCPUTEL_ReadDeviceBlock2_Proxy( 
    IActFXCPUTEL __RPC_FAR * This,
    /* [string][in] */ BSTR szDevice,
    /* [in] */ LONG lSize,
    /* [size_is][out] */ SHORT __RPC_FAR *lpsData,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActFXCPUTEL_ReadDeviceBlock2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActFXCPUTEL_WriteDeviceBlock2_Proxy( 
    IActFXCPUTEL __RPC_FAR * This,
    /* [string][in] */ BSTR szDevice,
    /* [in] */ LONG lSize,
    /* [size_is][in] */ SHORT __RPC_FAR *lpsData,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActFXCPUTEL_WriteDeviceBlock2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActFXCPUTEL_ReadDeviceRandom2_Proxy( 
    IActFXCPUTEL __RPC_FAR * This,
    /* [string][in] */ BSTR szDeviceList,
    /* [in] */ LONG lSize,
    /* [size_is][out] */ SHORT __RPC_FAR *lpsData,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActFXCPUTEL_ReadDeviceRandom2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActFXCPUTEL_WriteDeviceRandom2_Proxy( 
    IActFXCPUTEL __RPC_FAR * This,
    /* [string][in] */ BSTR szDeviceList,
    /* [in] */ LONG lSize,
    /* [size_is][in] */ SHORT __RPC_FAR *lpsData,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActFXCPUTEL_WriteDeviceRandom2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActFXCPUTEL_GetDevice2_Proxy( 
    IActFXCPUTEL __RPC_FAR * This,
    /* [string][in] */ BSTR szDevice,
    /* [out] */ SHORT __RPC_FAR *lpsData,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActFXCPUTEL_GetDevice2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActFXCPUTEL_SetDevice2_Proxy( 
    IActFXCPUTEL __RPC_FAR * This,
    /* [string][in] */ BSTR szDevice,
    /* [in] */ SHORT sData,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActFXCPUTEL_SetDevice2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActFXCPUTEL_Connect_Proxy( 
    IActFXCPUTEL __RPC_FAR * This,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActFXCPUTEL_Connect_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActFXCPUTEL_Disconnect_Proxy( 
    IActFXCPUTEL __RPC_FAR * This,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActFXCPUTEL_Disconnect_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActFXCPUTEL_get_ActCpuType_Proxy( 
    IActFXCPUTEL __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IActFXCPUTEL_get_ActCpuType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActFXCPUTEL_put_ActCpuType_Proxy( 
    IActFXCPUTEL __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB IActFXCPUTEL_put_ActCpuType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActFXCPUTEL_get_ActPortNumber_Proxy( 
    IActFXCPUTEL __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IActFXCPUTEL_get_ActPortNumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActFXCPUTEL_put_ActPortNumber_Proxy( 
    IActFXCPUTEL __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB IActFXCPUTEL_put_ActPortNumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActFXCPUTEL_get_ActTimeOut_Proxy( 
    IActFXCPUTEL __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IActFXCPUTEL_get_ActTimeOut_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActFXCPUTEL_put_ActTimeOut_Proxy( 
    IActFXCPUTEL __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB IActFXCPUTEL_put_ActTimeOut_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActFXCPUTEL_get_ActATCommand_Proxy( 
    IActFXCPUTEL __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *pVal);


void __RPC_STUB IActFXCPUTEL_get_ActATCommand_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActFXCPUTEL_put_ActATCommand_Proxy( 
    IActFXCPUTEL __RPC_FAR * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB IActFXCPUTEL_put_ActATCommand_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActFXCPUTEL_get_ActDialNumber_Proxy( 
    IActFXCPUTEL __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *pVal);


void __RPC_STUB IActFXCPUTEL_get_ActDialNumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActFXCPUTEL_put_ActDialNumber_Proxy( 
    IActFXCPUTEL __RPC_FAR * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB IActFXCPUTEL_put_ActDialNumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActFXCPUTEL_get_ActLineType_Proxy( 
    IActFXCPUTEL __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IActFXCPUTEL_get_ActLineType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActFXCPUTEL_put_ActLineType_Proxy( 
    IActFXCPUTEL __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB IActFXCPUTEL_put_ActLineType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActFXCPUTEL_get_ActConnectionCDWaitTime_Proxy( 
    IActFXCPUTEL __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IActFXCPUTEL_get_ActConnectionCDWaitTime_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActFXCPUTEL_put_ActConnectionCDWaitTime_Proxy( 
    IActFXCPUTEL __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB IActFXCPUTEL_put_ActConnectionCDWaitTime_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActFXCPUTEL_get_ActConnectionModemReportWaitTime_Proxy( 
    IActFXCPUTEL __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IActFXCPUTEL_get_ActConnectionModemReportWaitTime_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActFXCPUTEL_put_ActConnectionModemReportWaitTime_Proxy( 
    IActFXCPUTEL __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB IActFXCPUTEL_put_ActConnectionModemReportWaitTime_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActFXCPUTEL_get_ActDisconnectionCDWaitTime_Proxy( 
    IActFXCPUTEL __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IActFXCPUTEL_get_ActDisconnectionCDWaitTime_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActFXCPUTEL_put_ActDisconnectionCDWaitTime_Proxy( 
    IActFXCPUTEL __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB IActFXCPUTEL_put_ActDisconnectionCDWaitTime_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActFXCPUTEL_get_ActDisconnectionDelayTime_Proxy( 
    IActFXCPUTEL __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IActFXCPUTEL_get_ActDisconnectionDelayTime_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActFXCPUTEL_put_ActDisconnectionDelayTime_Proxy( 
    IActFXCPUTEL __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB IActFXCPUTEL_put_ActDisconnectionDelayTime_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActFXCPUTEL_get_ActTransmissionDelayTime_Proxy( 
    IActFXCPUTEL __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IActFXCPUTEL_get_ActTransmissionDelayTime_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActFXCPUTEL_put_ActTransmissionDelayTime_Proxy( 
    IActFXCPUTEL __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB IActFXCPUTEL_put_ActTransmissionDelayTime_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActFXCPUTEL_get_ActATCommandResponseWaitTime_Proxy( 
    IActFXCPUTEL __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IActFXCPUTEL_get_ActATCommandResponseWaitTime_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActFXCPUTEL_put_ActATCommandResponseWaitTime_Proxy( 
    IActFXCPUTEL __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB IActFXCPUTEL_put_ActATCommandResponseWaitTime_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActFXCPUTEL_get_ActATCommandPasswordCancelRetryTimes_Proxy( 
    IActFXCPUTEL __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IActFXCPUTEL_get_ActATCommandPasswordCancelRetryTimes_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActFXCPUTEL_put_ActATCommandPasswordCancelRetryTimes_Proxy( 
    IActFXCPUTEL __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB IActFXCPUTEL_put_ActATCommandPasswordCancelRetryTimes_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActFXCPUTEL_get_ActOutsideLineNumber_Proxy( 
    IActFXCPUTEL __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *pVal);


void __RPC_STUB IActFXCPUTEL_get_ActOutsideLineNumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActFXCPUTEL_put_ActOutsideLineNumber_Proxy( 
    IActFXCPUTEL __RPC_FAR * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB IActFXCPUTEL_put_ActOutsideLineNumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActFXCPUTEL_get_ActPasswordCancelResponseWaitTime_Proxy( 
    IActFXCPUTEL __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IActFXCPUTEL_get_ActPasswordCancelResponseWaitTime_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActFXCPUTEL_put_ActPasswordCancelResponseWaitTime_Proxy( 
    IActFXCPUTEL __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB IActFXCPUTEL_put_ActPasswordCancelResponseWaitTime_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IActFXCPUTEL_INTERFACE_DEFINED__ */


#ifndef __IActFXCPUTEL2_INTERFACE_DEFINED__
#define __IActFXCPUTEL2_INTERFACE_DEFINED__

/* interface IActFXCPUTEL2 */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IActFXCPUTEL2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("8716603A-710B-11d5-9318-009099244EFD")
    IActFXCPUTEL2 : public IActFXCPUTEL
    {
    public:
    };
    
#else 	/* C style interface */

    typedef struct IActFXCPUTEL2Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IActFXCPUTEL2 __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IActFXCPUTEL2 __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IActFXCPUTEL2 __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IActFXCPUTEL2 __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IActFXCPUTEL2 __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IActFXCPUTEL2 __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IActFXCPUTEL2 __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Open )( 
            IActFXCPUTEL2 __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Close )( 
            IActFXCPUTEL2 __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetDevice )( 
            IActFXCPUTEL2 __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [out] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetDevice )( 
            IActFXCPUTEL2 __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceBlock )( 
            IActFXCPUTEL2 __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lSize,
            /* [size_is][out] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceBlock )( 
            IActFXCPUTEL2 __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lSize,
            /* [size_is][in] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceRandom )( 
            IActFXCPUTEL2 __RPC_FAR * This,
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG lSize,
            /* [size_is][out] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceRandom )( 
            IActFXCPUTEL2 __RPC_FAR * This,
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG lSize,
            /* [size_is][in] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadBuffer )( 
            IActFXCPUTEL2 __RPC_FAR * This,
            /* [in] */ LONG lStartIO,
            /* [in] */ LONG lAddress,
            /* [in] */ LONG lReadSize,
            /* [size_is][out] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteBuffer )( 
            IActFXCPUTEL2 __RPC_FAR * This,
            /* [in] */ LONG lStartIO,
            /* [in] */ LONG lAddress,
            /* [in] */ LONG lWriteSize,
            /* [size_is][in] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetClockData )( 
            IActFXCPUTEL2 __RPC_FAR * This,
            /* [out] */ SHORT __RPC_FAR *lpsYear,
            /* [out] */ SHORT __RPC_FAR *lpsMonth,
            /* [out] */ SHORT __RPC_FAR *lpsDay,
            /* [out] */ SHORT __RPC_FAR *lpsDayOfWeek,
            /* [out] */ SHORT __RPC_FAR *lpsHour,
            /* [out] */ SHORT __RPC_FAR *lpsMinute,
            /* [out] */ SHORT __RPC_FAR *lpsSecond,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetClockData )( 
            IActFXCPUTEL2 __RPC_FAR * This,
            /* [in] */ SHORT sYear,
            /* [in] */ SHORT sMonth,
            /* [in] */ SHORT sDay,
            /* [in] */ SHORT sDayOfWeek,
            /* [in] */ SHORT sHour,
            /* [in] */ SHORT sMinute,
            /* [in] */ SHORT sSecond,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetCpuType )( 
            IActFXCPUTEL2 __RPC_FAR * This,
            /* [string][out] */ BSTR __RPC_FAR *szCpuName,
            /* [out] */ LONG __RPC_FAR *lplCpuCode,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetCpuStatus )( 
            IActFXCPUTEL2 __RPC_FAR * This,
            /* [in] */ LONG lOperation,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CheckDeviceString )( 
            IActFXCPUTEL2 __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lCheckType,
            /* [in] */ LONG lSize,
            /* [out] */ LONG __RPC_FAR *lplDeviceType,
            /* [string][out] */ BSTR __RPC_FAR *lpszDeviceName,
            /* [out] */ LONG __RPC_FAR *lplDeviceNumber,
            /* [out] */ LONG __RPC_FAR *lplDeviceRadix,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *EntryDeviceStatus )( 
            IActFXCPUTEL2 __RPC_FAR * This,
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG lSize,
            /* [in] */ LONG lMonitorCycle,
            /* [size_is][in] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *FreeDeviceStatus )( 
            IActFXCPUTEL2 __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceBlock2 )( 
            IActFXCPUTEL2 __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lSize,
            /* [size_is][out] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceBlock2 )( 
            IActFXCPUTEL2 __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lSize,
            /* [size_is][in] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceRandom2 )( 
            IActFXCPUTEL2 __RPC_FAR * This,
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG lSize,
            /* [size_is][out] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceRandom2 )( 
            IActFXCPUTEL2 __RPC_FAR * This,
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG lSize,
            /* [size_is][in] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetDevice2 )( 
            IActFXCPUTEL2 __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [out] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetDevice2 )( 
            IActFXCPUTEL2 __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ SHORT sData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Connect )( 
            IActFXCPUTEL2 __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Disconnect )( 
            IActFXCPUTEL2 __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActCpuType )( 
            IActFXCPUTEL2 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActCpuType )( 
            IActFXCPUTEL2 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActPortNumber )( 
            IActFXCPUTEL2 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActPortNumber )( 
            IActFXCPUTEL2 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActTimeOut )( 
            IActFXCPUTEL2 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActTimeOut )( 
            IActFXCPUTEL2 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActATCommand )( 
            IActFXCPUTEL2 __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActATCommand )( 
            IActFXCPUTEL2 __RPC_FAR * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActDialNumber )( 
            IActFXCPUTEL2 __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActDialNumber )( 
            IActFXCPUTEL2 __RPC_FAR * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActLineType )( 
            IActFXCPUTEL2 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActLineType )( 
            IActFXCPUTEL2 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActConnectionCDWaitTime )( 
            IActFXCPUTEL2 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActConnectionCDWaitTime )( 
            IActFXCPUTEL2 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActConnectionModemReportWaitTime )( 
            IActFXCPUTEL2 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActConnectionModemReportWaitTime )( 
            IActFXCPUTEL2 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActDisconnectionCDWaitTime )( 
            IActFXCPUTEL2 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActDisconnectionCDWaitTime )( 
            IActFXCPUTEL2 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActDisconnectionDelayTime )( 
            IActFXCPUTEL2 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActDisconnectionDelayTime )( 
            IActFXCPUTEL2 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActTransmissionDelayTime )( 
            IActFXCPUTEL2 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActTransmissionDelayTime )( 
            IActFXCPUTEL2 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActATCommandResponseWaitTime )( 
            IActFXCPUTEL2 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActATCommandResponseWaitTime )( 
            IActFXCPUTEL2 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActATCommandPasswordCancelRetryTimes )( 
            IActFXCPUTEL2 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActATCommandPasswordCancelRetryTimes )( 
            IActFXCPUTEL2 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActOutsideLineNumber )( 
            IActFXCPUTEL2 __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActOutsideLineNumber )( 
            IActFXCPUTEL2 __RPC_FAR * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActPasswordCancelResponseWaitTime )( 
            IActFXCPUTEL2 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActPasswordCancelResponseWaitTime )( 
            IActFXCPUTEL2 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        END_INTERFACE
    } IActFXCPUTEL2Vtbl;

    interface IActFXCPUTEL2
    {
        CONST_VTBL struct IActFXCPUTEL2Vtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IActFXCPUTEL2_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IActFXCPUTEL2_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IActFXCPUTEL2_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IActFXCPUTEL2_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IActFXCPUTEL2_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IActFXCPUTEL2_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IActFXCPUTEL2_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IActFXCPUTEL2_Open(This,lplReturnCode)	\
    (This)->lpVtbl -> Open(This,lplReturnCode)

#define IActFXCPUTEL2_Close(This,lplReturnCode)	\
    (This)->lpVtbl -> Close(This,lplReturnCode)

#define IActFXCPUTEL2_GetDevice(This,szDevice,lplData,lplReturnCode)	\
    (This)->lpVtbl -> GetDevice(This,szDevice,lplData,lplReturnCode)

#define IActFXCPUTEL2_SetDevice(This,szDevice,lData,lplReturnCode)	\
    (This)->lpVtbl -> SetDevice(This,szDevice,lData,lplReturnCode)

#define IActFXCPUTEL2_ReadDeviceBlock(This,szDevice,lSize,lplData,lplReturnCode)	\
    (This)->lpVtbl -> ReadDeviceBlock(This,szDevice,lSize,lplData,lplReturnCode)

#define IActFXCPUTEL2_WriteDeviceBlock(This,szDevice,lSize,lplData,lplReturnCode)	\
    (This)->lpVtbl -> WriteDeviceBlock(This,szDevice,lSize,lplData,lplReturnCode)

#define IActFXCPUTEL2_ReadDeviceRandom(This,szDeviceList,lSize,lplData,lplReturnCode)	\
    (This)->lpVtbl -> ReadDeviceRandom(This,szDeviceList,lSize,lplData,lplReturnCode)

#define IActFXCPUTEL2_WriteDeviceRandom(This,szDeviceList,lSize,lplData,lplReturnCode)	\
    (This)->lpVtbl -> WriteDeviceRandom(This,szDeviceList,lSize,lplData,lplReturnCode)

#define IActFXCPUTEL2_ReadBuffer(This,lStartIO,lAddress,lReadSize,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> ReadBuffer(This,lStartIO,lAddress,lReadSize,lpsData,lplReturnCode)

#define IActFXCPUTEL2_WriteBuffer(This,lStartIO,lAddress,lWriteSize,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> WriteBuffer(This,lStartIO,lAddress,lWriteSize,lpsData,lplReturnCode)

#define IActFXCPUTEL2_GetClockData(This,lpsYear,lpsMonth,lpsDay,lpsDayOfWeek,lpsHour,lpsMinute,lpsSecond,lplReturnCode)	\
    (This)->lpVtbl -> GetClockData(This,lpsYear,lpsMonth,lpsDay,lpsDayOfWeek,lpsHour,lpsMinute,lpsSecond,lplReturnCode)

#define IActFXCPUTEL2_SetClockData(This,sYear,sMonth,sDay,sDayOfWeek,sHour,sMinute,sSecond,lplReturnCode)	\
    (This)->lpVtbl -> SetClockData(This,sYear,sMonth,sDay,sDayOfWeek,sHour,sMinute,sSecond,lplReturnCode)

#define IActFXCPUTEL2_GetCpuType(This,szCpuName,lplCpuCode,lplReturnCode)	\
    (This)->lpVtbl -> GetCpuType(This,szCpuName,lplCpuCode,lplReturnCode)

#define IActFXCPUTEL2_SetCpuStatus(This,lOperation,lplReturnCode)	\
    (This)->lpVtbl -> SetCpuStatus(This,lOperation,lplReturnCode)

#define IActFXCPUTEL2_CheckDeviceString(This,szDevice,lCheckType,lSize,lplDeviceType,lpszDeviceName,lplDeviceNumber,lplDeviceRadix,lplReturnCode)	\
    (This)->lpVtbl -> CheckDeviceString(This,szDevice,lCheckType,lSize,lplDeviceType,lpszDeviceName,lplDeviceNumber,lplDeviceRadix,lplReturnCode)

#define IActFXCPUTEL2_EntryDeviceStatus(This,szDeviceList,lSize,lMonitorCycle,lplData,lplReturnCode)	\
    (This)->lpVtbl -> EntryDeviceStatus(This,szDeviceList,lSize,lMonitorCycle,lplData,lplReturnCode)

#define IActFXCPUTEL2_FreeDeviceStatus(This,lplReturnCode)	\
    (This)->lpVtbl -> FreeDeviceStatus(This,lplReturnCode)

#define IActFXCPUTEL2_ReadDeviceBlock2(This,szDevice,lSize,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> ReadDeviceBlock2(This,szDevice,lSize,lpsData,lplReturnCode)

#define IActFXCPUTEL2_WriteDeviceBlock2(This,szDevice,lSize,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> WriteDeviceBlock2(This,szDevice,lSize,lpsData,lplReturnCode)

#define IActFXCPUTEL2_ReadDeviceRandom2(This,szDeviceList,lSize,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> ReadDeviceRandom2(This,szDeviceList,lSize,lpsData,lplReturnCode)

#define IActFXCPUTEL2_WriteDeviceRandom2(This,szDeviceList,lSize,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> WriteDeviceRandom2(This,szDeviceList,lSize,lpsData,lplReturnCode)

#define IActFXCPUTEL2_GetDevice2(This,szDevice,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> GetDevice2(This,szDevice,lpsData,lplReturnCode)

#define IActFXCPUTEL2_SetDevice2(This,szDevice,sData,lplReturnCode)	\
    (This)->lpVtbl -> SetDevice2(This,szDevice,sData,lplReturnCode)

#define IActFXCPUTEL2_Connect(This,lplReturnCode)	\
    (This)->lpVtbl -> Connect(This,lplReturnCode)

#define IActFXCPUTEL2_Disconnect(This,lplReturnCode)	\
    (This)->lpVtbl -> Disconnect(This,lplReturnCode)

#define IActFXCPUTEL2_get_ActCpuType(This,pVal)	\
    (This)->lpVtbl -> get_ActCpuType(This,pVal)

#define IActFXCPUTEL2_put_ActCpuType(This,newVal)	\
    (This)->lpVtbl -> put_ActCpuType(This,newVal)

#define IActFXCPUTEL2_get_ActPortNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActPortNumber(This,pVal)

#define IActFXCPUTEL2_put_ActPortNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActPortNumber(This,newVal)

#define IActFXCPUTEL2_get_ActTimeOut(This,pVal)	\
    (This)->lpVtbl -> get_ActTimeOut(This,pVal)

#define IActFXCPUTEL2_put_ActTimeOut(This,newVal)	\
    (This)->lpVtbl -> put_ActTimeOut(This,newVal)

#define IActFXCPUTEL2_get_ActATCommand(This,pVal)	\
    (This)->lpVtbl -> get_ActATCommand(This,pVal)

#define IActFXCPUTEL2_put_ActATCommand(This,newVal)	\
    (This)->lpVtbl -> put_ActATCommand(This,newVal)

#define IActFXCPUTEL2_get_ActDialNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActDialNumber(This,pVal)

#define IActFXCPUTEL2_put_ActDialNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActDialNumber(This,newVal)

#define IActFXCPUTEL2_get_ActLineType(This,pVal)	\
    (This)->lpVtbl -> get_ActLineType(This,pVal)

#define IActFXCPUTEL2_put_ActLineType(This,newVal)	\
    (This)->lpVtbl -> put_ActLineType(This,newVal)

#define IActFXCPUTEL2_get_ActConnectionCDWaitTime(This,pVal)	\
    (This)->lpVtbl -> get_ActConnectionCDWaitTime(This,pVal)

#define IActFXCPUTEL2_put_ActConnectionCDWaitTime(This,newVal)	\
    (This)->lpVtbl -> put_ActConnectionCDWaitTime(This,newVal)

#define IActFXCPUTEL2_get_ActConnectionModemReportWaitTime(This,pVal)	\
    (This)->lpVtbl -> get_ActConnectionModemReportWaitTime(This,pVal)

#define IActFXCPUTEL2_put_ActConnectionModemReportWaitTime(This,newVal)	\
    (This)->lpVtbl -> put_ActConnectionModemReportWaitTime(This,newVal)

#define IActFXCPUTEL2_get_ActDisconnectionCDWaitTime(This,pVal)	\
    (This)->lpVtbl -> get_ActDisconnectionCDWaitTime(This,pVal)

#define IActFXCPUTEL2_put_ActDisconnectionCDWaitTime(This,newVal)	\
    (This)->lpVtbl -> put_ActDisconnectionCDWaitTime(This,newVal)

#define IActFXCPUTEL2_get_ActDisconnectionDelayTime(This,pVal)	\
    (This)->lpVtbl -> get_ActDisconnectionDelayTime(This,pVal)

#define IActFXCPUTEL2_put_ActDisconnectionDelayTime(This,newVal)	\
    (This)->lpVtbl -> put_ActDisconnectionDelayTime(This,newVal)

#define IActFXCPUTEL2_get_ActTransmissionDelayTime(This,pVal)	\
    (This)->lpVtbl -> get_ActTransmissionDelayTime(This,pVal)

#define IActFXCPUTEL2_put_ActTransmissionDelayTime(This,newVal)	\
    (This)->lpVtbl -> put_ActTransmissionDelayTime(This,newVal)

#define IActFXCPUTEL2_get_ActATCommandResponseWaitTime(This,pVal)	\
    (This)->lpVtbl -> get_ActATCommandResponseWaitTime(This,pVal)

#define IActFXCPUTEL2_put_ActATCommandResponseWaitTime(This,newVal)	\
    (This)->lpVtbl -> put_ActATCommandResponseWaitTime(This,newVal)

#define IActFXCPUTEL2_get_ActATCommandPasswordCancelRetryTimes(This,pVal)	\
    (This)->lpVtbl -> get_ActATCommandPasswordCancelRetryTimes(This,pVal)

#define IActFXCPUTEL2_put_ActATCommandPasswordCancelRetryTimes(This,newVal)	\
    (This)->lpVtbl -> put_ActATCommandPasswordCancelRetryTimes(This,newVal)

#define IActFXCPUTEL2_get_ActOutsideLineNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActOutsideLineNumber(This,pVal)

#define IActFXCPUTEL2_put_ActOutsideLineNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActOutsideLineNumber(This,newVal)

#define IActFXCPUTEL2_get_ActPasswordCancelResponseWaitTime(This,pVal)	\
    (This)->lpVtbl -> get_ActPasswordCancelResponseWaitTime(This,pVal)

#define IActFXCPUTEL2_put_ActPasswordCancelResponseWaitTime(This,newVal)	\
    (This)->lpVtbl -> put_ActPasswordCancelResponseWaitTime(This,newVal)


#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IActFXCPUTEL2_INTERFACE_DEFINED__ */


#ifndef __IActFXCPUTEL3_INTERFACE_DEFINED__
#define __IActFXCPUTEL3_INTERFACE_DEFINED__

/* interface IActFXCPUTEL3 */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IActFXCPUTEL3;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("8716603B-710B-11d5-9318-009099244EFD")
    IActFXCPUTEL3 : public IActFXCPUTEL2
    {
    public:
    };
    
#else 	/* C style interface */

    typedef struct IActFXCPUTEL3Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IActFXCPUTEL3 __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IActFXCPUTEL3 __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IActFXCPUTEL3 __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IActFXCPUTEL3 __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IActFXCPUTEL3 __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IActFXCPUTEL3 __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IActFXCPUTEL3 __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Open )( 
            IActFXCPUTEL3 __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Close )( 
            IActFXCPUTEL3 __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetDevice )( 
            IActFXCPUTEL3 __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [out] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetDevice )( 
            IActFXCPUTEL3 __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceBlock )( 
            IActFXCPUTEL3 __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lSize,
            /* [size_is][out] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceBlock )( 
            IActFXCPUTEL3 __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lSize,
            /* [size_is][in] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceRandom )( 
            IActFXCPUTEL3 __RPC_FAR * This,
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG lSize,
            /* [size_is][out] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceRandom )( 
            IActFXCPUTEL3 __RPC_FAR * This,
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG lSize,
            /* [size_is][in] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadBuffer )( 
            IActFXCPUTEL3 __RPC_FAR * This,
            /* [in] */ LONG lStartIO,
            /* [in] */ LONG lAddress,
            /* [in] */ LONG lReadSize,
            /* [size_is][out] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteBuffer )( 
            IActFXCPUTEL3 __RPC_FAR * This,
            /* [in] */ LONG lStartIO,
            /* [in] */ LONG lAddress,
            /* [in] */ LONG lWriteSize,
            /* [size_is][in] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetClockData )( 
            IActFXCPUTEL3 __RPC_FAR * This,
            /* [out] */ SHORT __RPC_FAR *lpsYear,
            /* [out] */ SHORT __RPC_FAR *lpsMonth,
            /* [out] */ SHORT __RPC_FAR *lpsDay,
            /* [out] */ SHORT __RPC_FAR *lpsDayOfWeek,
            /* [out] */ SHORT __RPC_FAR *lpsHour,
            /* [out] */ SHORT __RPC_FAR *lpsMinute,
            /* [out] */ SHORT __RPC_FAR *lpsSecond,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetClockData )( 
            IActFXCPUTEL3 __RPC_FAR * This,
            /* [in] */ SHORT sYear,
            /* [in] */ SHORT sMonth,
            /* [in] */ SHORT sDay,
            /* [in] */ SHORT sDayOfWeek,
            /* [in] */ SHORT sHour,
            /* [in] */ SHORT sMinute,
            /* [in] */ SHORT sSecond,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetCpuType )( 
            IActFXCPUTEL3 __RPC_FAR * This,
            /* [string][out] */ BSTR __RPC_FAR *szCpuName,
            /* [out] */ LONG __RPC_FAR *lplCpuCode,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetCpuStatus )( 
            IActFXCPUTEL3 __RPC_FAR * This,
            /* [in] */ LONG lOperation,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CheckDeviceString )( 
            IActFXCPUTEL3 __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lCheckType,
            /* [in] */ LONG lSize,
            /* [out] */ LONG __RPC_FAR *lplDeviceType,
            /* [string][out] */ BSTR __RPC_FAR *lpszDeviceName,
            /* [out] */ LONG __RPC_FAR *lplDeviceNumber,
            /* [out] */ LONG __RPC_FAR *lplDeviceRadix,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *EntryDeviceStatus )( 
            IActFXCPUTEL3 __RPC_FAR * This,
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG lSize,
            /* [in] */ LONG lMonitorCycle,
            /* [size_is][in] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *FreeDeviceStatus )( 
            IActFXCPUTEL3 __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceBlock2 )( 
            IActFXCPUTEL3 __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lSize,
            /* [size_is][out] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceBlock2 )( 
            IActFXCPUTEL3 __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lSize,
            /* [size_is][in] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceRandom2 )( 
            IActFXCPUTEL3 __RPC_FAR * This,
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG lSize,
            /* [size_is][out] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceRandom2 )( 
            IActFXCPUTEL3 __RPC_FAR * This,
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG lSize,
            /* [size_is][in] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetDevice2 )( 
            IActFXCPUTEL3 __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [out] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetDevice2 )( 
            IActFXCPUTEL3 __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ SHORT sData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Connect )( 
            IActFXCPUTEL3 __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Disconnect )( 
            IActFXCPUTEL3 __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActCpuType )( 
            IActFXCPUTEL3 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActCpuType )( 
            IActFXCPUTEL3 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActPortNumber )( 
            IActFXCPUTEL3 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActPortNumber )( 
            IActFXCPUTEL3 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActTimeOut )( 
            IActFXCPUTEL3 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActTimeOut )( 
            IActFXCPUTEL3 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActATCommand )( 
            IActFXCPUTEL3 __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActATCommand )( 
            IActFXCPUTEL3 __RPC_FAR * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActDialNumber )( 
            IActFXCPUTEL3 __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActDialNumber )( 
            IActFXCPUTEL3 __RPC_FAR * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActLineType )( 
            IActFXCPUTEL3 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActLineType )( 
            IActFXCPUTEL3 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActConnectionCDWaitTime )( 
            IActFXCPUTEL3 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActConnectionCDWaitTime )( 
            IActFXCPUTEL3 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActConnectionModemReportWaitTime )( 
            IActFXCPUTEL3 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActConnectionModemReportWaitTime )( 
            IActFXCPUTEL3 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActDisconnectionCDWaitTime )( 
            IActFXCPUTEL3 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActDisconnectionCDWaitTime )( 
            IActFXCPUTEL3 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActDisconnectionDelayTime )( 
            IActFXCPUTEL3 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActDisconnectionDelayTime )( 
            IActFXCPUTEL3 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActTransmissionDelayTime )( 
            IActFXCPUTEL3 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActTransmissionDelayTime )( 
            IActFXCPUTEL3 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActATCommandResponseWaitTime )( 
            IActFXCPUTEL3 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActATCommandResponseWaitTime )( 
            IActFXCPUTEL3 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActATCommandPasswordCancelRetryTimes )( 
            IActFXCPUTEL3 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActATCommandPasswordCancelRetryTimes )( 
            IActFXCPUTEL3 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActOutsideLineNumber )( 
            IActFXCPUTEL3 __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActOutsideLineNumber )( 
            IActFXCPUTEL3 __RPC_FAR * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActPasswordCancelResponseWaitTime )( 
            IActFXCPUTEL3 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActPasswordCancelResponseWaitTime )( 
            IActFXCPUTEL3 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        END_INTERFACE
    } IActFXCPUTEL3Vtbl;

    interface IActFXCPUTEL3
    {
        CONST_VTBL struct IActFXCPUTEL3Vtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IActFXCPUTEL3_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IActFXCPUTEL3_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IActFXCPUTEL3_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IActFXCPUTEL3_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IActFXCPUTEL3_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IActFXCPUTEL3_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IActFXCPUTEL3_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IActFXCPUTEL3_Open(This,lplReturnCode)	\
    (This)->lpVtbl -> Open(This,lplReturnCode)

#define IActFXCPUTEL3_Close(This,lplReturnCode)	\
    (This)->lpVtbl -> Close(This,lplReturnCode)

#define IActFXCPUTEL3_GetDevice(This,szDevice,lplData,lplReturnCode)	\
    (This)->lpVtbl -> GetDevice(This,szDevice,lplData,lplReturnCode)

#define IActFXCPUTEL3_SetDevice(This,szDevice,lData,lplReturnCode)	\
    (This)->lpVtbl -> SetDevice(This,szDevice,lData,lplReturnCode)

#define IActFXCPUTEL3_ReadDeviceBlock(This,szDevice,lSize,lplData,lplReturnCode)	\
    (This)->lpVtbl -> ReadDeviceBlock(This,szDevice,lSize,lplData,lplReturnCode)

#define IActFXCPUTEL3_WriteDeviceBlock(This,szDevice,lSize,lplData,lplReturnCode)	\
    (This)->lpVtbl -> WriteDeviceBlock(This,szDevice,lSize,lplData,lplReturnCode)

#define IActFXCPUTEL3_ReadDeviceRandom(This,szDeviceList,lSize,lplData,lplReturnCode)	\
    (This)->lpVtbl -> ReadDeviceRandom(This,szDeviceList,lSize,lplData,lplReturnCode)

#define IActFXCPUTEL3_WriteDeviceRandom(This,szDeviceList,lSize,lplData,lplReturnCode)	\
    (This)->lpVtbl -> WriteDeviceRandom(This,szDeviceList,lSize,lplData,lplReturnCode)

#define IActFXCPUTEL3_ReadBuffer(This,lStartIO,lAddress,lReadSize,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> ReadBuffer(This,lStartIO,lAddress,lReadSize,lpsData,lplReturnCode)

#define IActFXCPUTEL3_WriteBuffer(This,lStartIO,lAddress,lWriteSize,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> WriteBuffer(This,lStartIO,lAddress,lWriteSize,lpsData,lplReturnCode)

#define IActFXCPUTEL3_GetClockData(This,lpsYear,lpsMonth,lpsDay,lpsDayOfWeek,lpsHour,lpsMinute,lpsSecond,lplReturnCode)	\
    (This)->lpVtbl -> GetClockData(This,lpsYear,lpsMonth,lpsDay,lpsDayOfWeek,lpsHour,lpsMinute,lpsSecond,lplReturnCode)

#define IActFXCPUTEL3_SetClockData(This,sYear,sMonth,sDay,sDayOfWeek,sHour,sMinute,sSecond,lplReturnCode)	\
    (This)->lpVtbl -> SetClockData(This,sYear,sMonth,sDay,sDayOfWeek,sHour,sMinute,sSecond,lplReturnCode)

#define IActFXCPUTEL3_GetCpuType(This,szCpuName,lplCpuCode,lplReturnCode)	\
    (This)->lpVtbl -> GetCpuType(This,szCpuName,lplCpuCode,lplReturnCode)

#define IActFXCPUTEL3_SetCpuStatus(This,lOperation,lplReturnCode)	\
    (This)->lpVtbl -> SetCpuStatus(This,lOperation,lplReturnCode)

#define IActFXCPUTEL3_CheckDeviceString(This,szDevice,lCheckType,lSize,lplDeviceType,lpszDeviceName,lplDeviceNumber,lplDeviceRadix,lplReturnCode)	\
    (This)->lpVtbl -> CheckDeviceString(This,szDevice,lCheckType,lSize,lplDeviceType,lpszDeviceName,lplDeviceNumber,lplDeviceRadix,lplReturnCode)

#define IActFXCPUTEL3_EntryDeviceStatus(This,szDeviceList,lSize,lMonitorCycle,lplData,lplReturnCode)	\
    (This)->lpVtbl -> EntryDeviceStatus(This,szDeviceList,lSize,lMonitorCycle,lplData,lplReturnCode)

#define IActFXCPUTEL3_FreeDeviceStatus(This,lplReturnCode)	\
    (This)->lpVtbl -> FreeDeviceStatus(This,lplReturnCode)

#define IActFXCPUTEL3_ReadDeviceBlock2(This,szDevice,lSize,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> ReadDeviceBlock2(This,szDevice,lSize,lpsData,lplReturnCode)

#define IActFXCPUTEL3_WriteDeviceBlock2(This,szDevice,lSize,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> WriteDeviceBlock2(This,szDevice,lSize,lpsData,lplReturnCode)

#define IActFXCPUTEL3_ReadDeviceRandom2(This,szDeviceList,lSize,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> ReadDeviceRandom2(This,szDeviceList,lSize,lpsData,lplReturnCode)

#define IActFXCPUTEL3_WriteDeviceRandom2(This,szDeviceList,lSize,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> WriteDeviceRandom2(This,szDeviceList,lSize,lpsData,lplReturnCode)

#define IActFXCPUTEL3_GetDevice2(This,szDevice,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> GetDevice2(This,szDevice,lpsData,lplReturnCode)

#define IActFXCPUTEL3_SetDevice2(This,szDevice,sData,lplReturnCode)	\
    (This)->lpVtbl -> SetDevice2(This,szDevice,sData,lplReturnCode)

#define IActFXCPUTEL3_Connect(This,lplReturnCode)	\
    (This)->lpVtbl -> Connect(This,lplReturnCode)

#define IActFXCPUTEL3_Disconnect(This,lplReturnCode)	\
    (This)->lpVtbl -> Disconnect(This,lplReturnCode)

#define IActFXCPUTEL3_get_ActCpuType(This,pVal)	\
    (This)->lpVtbl -> get_ActCpuType(This,pVal)

#define IActFXCPUTEL3_put_ActCpuType(This,newVal)	\
    (This)->lpVtbl -> put_ActCpuType(This,newVal)

#define IActFXCPUTEL3_get_ActPortNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActPortNumber(This,pVal)

#define IActFXCPUTEL3_put_ActPortNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActPortNumber(This,newVal)

#define IActFXCPUTEL3_get_ActTimeOut(This,pVal)	\
    (This)->lpVtbl -> get_ActTimeOut(This,pVal)

#define IActFXCPUTEL3_put_ActTimeOut(This,newVal)	\
    (This)->lpVtbl -> put_ActTimeOut(This,newVal)

#define IActFXCPUTEL3_get_ActATCommand(This,pVal)	\
    (This)->lpVtbl -> get_ActATCommand(This,pVal)

#define IActFXCPUTEL3_put_ActATCommand(This,newVal)	\
    (This)->lpVtbl -> put_ActATCommand(This,newVal)

#define IActFXCPUTEL3_get_ActDialNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActDialNumber(This,pVal)

#define IActFXCPUTEL3_put_ActDialNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActDialNumber(This,newVal)

#define IActFXCPUTEL3_get_ActLineType(This,pVal)	\
    (This)->lpVtbl -> get_ActLineType(This,pVal)

#define IActFXCPUTEL3_put_ActLineType(This,newVal)	\
    (This)->lpVtbl -> put_ActLineType(This,newVal)

#define IActFXCPUTEL3_get_ActConnectionCDWaitTime(This,pVal)	\
    (This)->lpVtbl -> get_ActConnectionCDWaitTime(This,pVal)

#define IActFXCPUTEL3_put_ActConnectionCDWaitTime(This,newVal)	\
    (This)->lpVtbl -> put_ActConnectionCDWaitTime(This,newVal)

#define IActFXCPUTEL3_get_ActConnectionModemReportWaitTime(This,pVal)	\
    (This)->lpVtbl -> get_ActConnectionModemReportWaitTime(This,pVal)

#define IActFXCPUTEL3_put_ActConnectionModemReportWaitTime(This,newVal)	\
    (This)->lpVtbl -> put_ActConnectionModemReportWaitTime(This,newVal)

#define IActFXCPUTEL3_get_ActDisconnectionCDWaitTime(This,pVal)	\
    (This)->lpVtbl -> get_ActDisconnectionCDWaitTime(This,pVal)

#define IActFXCPUTEL3_put_ActDisconnectionCDWaitTime(This,newVal)	\
    (This)->lpVtbl -> put_ActDisconnectionCDWaitTime(This,newVal)

#define IActFXCPUTEL3_get_ActDisconnectionDelayTime(This,pVal)	\
    (This)->lpVtbl -> get_ActDisconnectionDelayTime(This,pVal)

#define IActFXCPUTEL3_put_ActDisconnectionDelayTime(This,newVal)	\
    (This)->lpVtbl -> put_ActDisconnectionDelayTime(This,newVal)

#define IActFXCPUTEL3_get_ActTransmissionDelayTime(This,pVal)	\
    (This)->lpVtbl -> get_ActTransmissionDelayTime(This,pVal)

#define IActFXCPUTEL3_put_ActTransmissionDelayTime(This,newVal)	\
    (This)->lpVtbl -> put_ActTransmissionDelayTime(This,newVal)

#define IActFXCPUTEL3_get_ActATCommandResponseWaitTime(This,pVal)	\
    (This)->lpVtbl -> get_ActATCommandResponseWaitTime(This,pVal)

#define IActFXCPUTEL3_put_ActATCommandResponseWaitTime(This,newVal)	\
    (This)->lpVtbl -> put_ActATCommandResponseWaitTime(This,newVal)

#define IActFXCPUTEL3_get_ActATCommandPasswordCancelRetryTimes(This,pVal)	\
    (This)->lpVtbl -> get_ActATCommandPasswordCancelRetryTimes(This,pVal)

#define IActFXCPUTEL3_put_ActATCommandPasswordCancelRetryTimes(This,newVal)	\
    (This)->lpVtbl -> put_ActATCommandPasswordCancelRetryTimes(This,newVal)

#define IActFXCPUTEL3_get_ActOutsideLineNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActOutsideLineNumber(This,pVal)

#define IActFXCPUTEL3_put_ActOutsideLineNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActOutsideLineNumber(This,newVal)

#define IActFXCPUTEL3_get_ActPasswordCancelResponseWaitTime(This,pVal)	\
    (This)->lpVtbl -> get_ActPasswordCancelResponseWaitTime(This,pVal)

#define IActFXCPUTEL3_put_ActPasswordCancelResponseWaitTime(This,newVal)	\
    (This)->lpVtbl -> put_ActPasswordCancelResponseWaitTime(This,newVal)



#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IActFXCPUTEL3_INTERFACE_DEFINED__ */


#ifndef __IActAJ71QC24TEL_INTERFACE_DEFINED__
#define __IActAJ71QC24TEL_INTERFACE_DEFINED__

/* interface IActAJ71QC24TEL */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IActAJ71QC24TEL;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("5713F07B-6F4A-11D5-9315-009099244EFD")
    IActAJ71QC24TEL : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Open( 
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Close( 
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetDevice( 
            /* [string][in] */ BSTR szDevice,
            /* [out] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetDevice( 
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ReadDeviceBlock( 
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lSize,
            /* [size_is][out] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE WriteDeviceBlock( 
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lSize,
            /* [size_is][in] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ReadDeviceRandom( 
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG lSize,
            /* [size_is][out] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE WriteDeviceRandom( 
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG lSize,
            /* [size_is][in] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ReadBuffer( 
            /* [in] */ LONG lStartIO,
            /* [in] */ LONG lAddress,
            /* [in] */ LONG lReadSize,
            /* [size_is][out] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE WriteBuffer( 
            /* [in] */ LONG lStartIO,
            /* [in] */ LONG lAddress,
            /* [in] */ LONG lWriteSize,
            /* [size_is][in] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetClockData( 
            /* [out] */ SHORT __RPC_FAR *lpsYear,
            /* [out] */ SHORT __RPC_FAR *lpsMonth,
            /* [out] */ SHORT __RPC_FAR *lpsDay,
            /* [out] */ SHORT __RPC_FAR *lpsDayOfWeek,
            /* [out] */ SHORT __RPC_FAR *lpsHour,
            /* [out] */ SHORT __RPC_FAR *lpsMinute,
            /* [out] */ SHORT __RPC_FAR *lpsSecond,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetClockData( 
            /* [in] */ SHORT sYear,
            /* [in] */ SHORT sMonth,
            /* [in] */ SHORT sDay,
            /* [in] */ SHORT sDayOfWeek,
            /* [in] */ SHORT sHour,
            /* [in] */ SHORT sMinute,
            /* [in] */ SHORT sSecond,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetCpuType( 
            /* [string][out] */ BSTR __RPC_FAR *szCpuName,
            /* [out] */ LONG __RPC_FAR *lplCpuCode,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetCpuStatus( 
            /* [in] */ LONG lOperation,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE CheckDeviceString( 
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lCheckType,
            /* [in] */ LONG lSize,
            /* [out] */ LONG __RPC_FAR *lplDeviceType,
            /* [string][out] */ BSTR __RPC_FAR *lpszDeviceName,
            /* [out] */ LONG __RPC_FAR *lplDeviceNumber,
            /* [out] */ LONG __RPC_FAR *lplDeviceRadix,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE EntryDeviceStatus( 
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG lSize,
            /* [in] */ LONG lMonitorCycle,
            /* [size_is][in] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE FreeDeviceStatus( 
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ReadDeviceBlock2( 
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lSize,
            /* [size_is][out] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE WriteDeviceBlock2( 
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lSize,
            /* [size_is][in] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ReadDeviceRandom2( 
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG lSize,
            /* [size_is][out] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE WriteDeviceRandom2( 
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG lSize,
            /* [size_is][in] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetDevice2( 
            /* [string][in] */ BSTR szDevice,
            /* [out] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetDevice2( 
            /* [string][in] */ BSTR szDevice,
            /* [in] */ SHORT sData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Connect( 
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Disconnect( 
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActNetworkNumber( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActNetworkNumber( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActStationNumber( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActStationNumber( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActUnitNumber( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActUnitNumber( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActConnectUnitNumber( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActConnectUnitNumber( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActIONumber( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActIONumber( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActCpuType( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActCpuType( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActPortNumber( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActPortNumber( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActBaudRate( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActBaudRate( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActTimeOut( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActTimeOut( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActATCommand( 
            /* [retval][out] */ BSTR __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActATCommand( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActDialNumber( 
            /* [retval][out] */ BSTR __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActDialNumber( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActLineType( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActLineType( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActConnectionCDWaitTime( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActConnectionCDWaitTime( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActConnectionModemReportWaitTime( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActConnectionModemReportWaitTime( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActDisconnectionCDWaitTime( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActDisconnectionCDWaitTime( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActDisconnectionDelayTime( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActDisconnectionDelayTime( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActTransmissionDelayTime( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActTransmissionDelayTime( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActATCommandResponseWaitTime( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActATCommandResponseWaitTime( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActATCommandPasswordCancelRetryTimes( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActATCommandPasswordCancelRetryTimes( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActOutsideLineNumber( 
            /* [retval][out] */ BSTR __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActOutsideLineNumber( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActPasswordCancelResponseWaitTime( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActPasswordCancelResponseWaitTime( 
            /* [in] */ long newVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IActAJ71QC24TELVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IActAJ71QC24TEL __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IActAJ71QC24TEL __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IActAJ71QC24TEL __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IActAJ71QC24TEL __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IActAJ71QC24TEL __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IActAJ71QC24TEL __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IActAJ71QC24TEL __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Open )( 
            IActAJ71QC24TEL __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Close )( 
            IActAJ71QC24TEL __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetDevice )( 
            IActAJ71QC24TEL __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [out] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetDevice )( 
            IActAJ71QC24TEL __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceBlock )( 
            IActAJ71QC24TEL __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lSize,
            /* [size_is][out] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceBlock )( 
            IActAJ71QC24TEL __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lSize,
            /* [size_is][in] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceRandom )( 
            IActAJ71QC24TEL __RPC_FAR * This,
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG lSize,
            /* [size_is][out] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceRandom )( 
            IActAJ71QC24TEL __RPC_FAR * This,
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG lSize,
            /* [size_is][in] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadBuffer )( 
            IActAJ71QC24TEL __RPC_FAR * This,
            /* [in] */ LONG lStartIO,
            /* [in] */ LONG lAddress,
            /* [in] */ LONG lReadSize,
            /* [size_is][out] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteBuffer )( 
            IActAJ71QC24TEL __RPC_FAR * This,
            /* [in] */ LONG lStartIO,
            /* [in] */ LONG lAddress,
            /* [in] */ LONG lWriteSize,
            /* [size_is][in] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetClockData )( 
            IActAJ71QC24TEL __RPC_FAR * This,
            /* [out] */ SHORT __RPC_FAR *lpsYear,
            /* [out] */ SHORT __RPC_FAR *lpsMonth,
            /* [out] */ SHORT __RPC_FAR *lpsDay,
            /* [out] */ SHORT __RPC_FAR *lpsDayOfWeek,
            /* [out] */ SHORT __RPC_FAR *lpsHour,
            /* [out] */ SHORT __RPC_FAR *lpsMinute,
            /* [out] */ SHORT __RPC_FAR *lpsSecond,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetClockData )( 
            IActAJ71QC24TEL __RPC_FAR * This,
            /* [in] */ SHORT sYear,
            /* [in] */ SHORT sMonth,
            /* [in] */ SHORT sDay,
            /* [in] */ SHORT sDayOfWeek,
            /* [in] */ SHORT sHour,
            /* [in] */ SHORT sMinute,
            /* [in] */ SHORT sSecond,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetCpuType )( 
            IActAJ71QC24TEL __RPC_FAR * This,
            /* [string][out] */ BSTR __RPC_FAR *szCpuName,
            /* [out] */ LONG __RPC_FAR *lplCpuCode,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetCpuStatus )( 
            IActAJ71QC24TEL __RPC_FAR * This,
            /* [in] */ LONG lOperation,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CheckDeviceString )( 
            IActAJ71QC24TEL __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lCheckType,
            /* [in] */ LONG lSize,
            /* [out] */ LONG __RPC_FAR *lplDeviceType,
            /* [string][out] */ BSTR __RPC_FAR *lpszDeviceName,
            /* [out] */ LONG __RPC_FAR *lplDeviceNumber,
            /* [out] */ LONG __RPC_FAR *lplDeviceRadix,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *EntryDeviceStatus )( 
            IActAJ71QC24TEL __RPC_FAR * This,
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG lSize,
            /* [in] */ LONG lMonitorCycle,
            /* [size_is][in] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *FreeDeviceStatus )( 
            IActAJ71QC24TEL __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceBlock2 )( 
            IActAJ71QC24TEL __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lSize,
            /* [size_is][out] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceBlock2 )( 
            IActAJ71QC24TEL __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lSize,
            /* [size_is][in] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceRandom2 )( 
            IActAJ71QC24TEL __RPC_FAR * This,
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG lSize,
            /* [size_is][out] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceRandom2 )( 
            IActAJ71QC24TEL __RPC_FAR * This,
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG lSize,
            /* [size_is][in] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetDevice2 )( 
            IActAJ71QC24TEL __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [out] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetDevice2 )( 
            IActAJ71QC24TEL __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ SHORT sData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Connect )( 
            IActAJ71QC24TEL __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Disconnect )( 
            IActAJ71QC24TEL __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActNetworkNumber )( 
            IActAJ71QC24TEL __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActNetworkNumber )( 
            IActAJ71QC24TEL __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActStationNumber )( 
            IActAJ71QC24TEL __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActStationNumber )( 
            IActAJ71QC24TEL __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActUnitNumber )( 
            IActAJ71QC24TEL __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActUnitNumber )( 
            IActAJ71QC24TEL __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActConnectUnitNumber )( 
            IActAJ71QC24TEL __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActConnectUnitNumber )( 
            IActAJ71QC24TEL __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActIONumber )( 
            IActAJ71QC24TEL __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActIONumber )( 
            IActAJ71QC24TEL __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActCpuType )( 
            IActAJ71QC24TEL __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActCpuType )( 
            IActAJ71QC24TEL __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActPortNumber )( 
            IActAJ71QC24TEL __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActPortNumber )( 
            IActAJ71QC24TEL __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActBaudRate )( 
            IActAJ71QC24TEL __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActBaudRate )( 
            IActAJ71QC24TEL __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActTimeOut )( 
            IActAJ71QC24TEL __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActTimeOut )( 
            IActAJ71QC24TEL __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActATCommand )( 
            IActAJ71QC24TEL __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActATCommand )( 
            IActAJ71QC24TEL __RPC_FAR * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActDialNumber )( 
            IActAJ71QC24TEL __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActDialNumber )( 
            IActAJ71QC24TEL __RPC_FAR * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActLineType )( 
            IActAJ71QC24TEL __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActLineType )( 
            IActAJ71QC24TEL __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActConnectionCDWaitTime )( 
            IActAJ71QC24TEL __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActConnectionCDWaitTime )( 
            IActAJ71QC24TEL __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActConnectionModemReportWaitTime )( 
            IActAJ71QC24TEL __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActConnectionModemReportWaitTime )( 
            IActAJ71QC24TEL __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActDisconnectionCDWaitTime )( 
            IActAJ71QC24TEL __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActDisconnectionCDWaitTime )( 
            IActAJ71QC24TEL __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActDisconnectionDelayTime )( 
            IActAJ71QC24TEL __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActDisconnectionDelayTime )( 
            IActAJ71QC24TEL __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActTransmissionDelayTime )( 
            IActAJ71QC24TEL __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActTransmissionDelayTime )( 
            IActAJ71QC24TEL __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActATCommandResponseWaitTime )( 
            IActAJ71QC24TEL __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActATCommandResponseWaitTime )( 
            IActAJ71QC24TEL __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActATCommandPasswordCancelRetryTimes )( 
            IActAJ71QC24TEL __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActATCommandPasswordCancelRetryTimes )( 
            IActAJ71QC24TEL __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActOutsideLineNumber )( 
            IActAJ71QC24TEL __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActOutsideLineNumber )( 
            IActAJ71QC24TEL __RPC_FAR * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActPasswordCancelResponseWaitTime )( 
            IActAJ71QC24TEL __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActPasswordCancelResponseWaitTime )( 
            IActAJ71QC24TEL __RPC_FAR * This,
            /* [in] */ long newVal);
        
        END_INTERFACE
    } IActAJ71QC24TELVtbl;

    interface IActAJ71QC24TEL
    {
        CONST_VTBL struct IActAJ71QC24TELVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IActAJ71QC24TEL_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IActAJ71QC24TEL_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IActAJ71QC24TEL_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IActAJ71QC24TEL_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IActAJ71QC24TEL_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IActAJ71QC24TEL_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IActAJ71QC24TEL_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IActAJ71QC24TEL_Open(This,lplReturnCode)	\
    (This)->lpVtbl -> Open(This,lplReturnCode)

#define IActAJ71QC24TEL_Close(This,lplReturnCode)	\
    (This)->lpVtbl -> Close(This,lplReturnCode)

#define IActAJ71QC24TEL_GetDevice(This,szDevice,lplData,lplReturnCode)	\
    (This)->lpVtbl -> GetDevice(This,szDevice,lplData,lplReturnCode)

#define IActAJ71QC24TEL_SetDevice(This,szDevice,lData,lplReturnCode)	\
    (This)->lpVtbl -> SetDevice(This,szDevice,lData,lplReturnCode)

#define IActAJ71QC24TEL_ReadDeviceBlock(This,szDevice,lSize,lplData,lplReturnCode)	\
    (This)->lpVtbl -> ReadDeviceBlock(This,szDevice,lSize,lplData,lplReturnCode)

#define IActAJ71QC24TEL_WriteDeviceBlock(This,szDevice,lSize,lplData,lplReturnCode)	\
    (This)->lpVtbl -> WriteDeviceBlock(This,szDevice,lSize,lplData,lplReturnCode)

#define IActAJ71QC24TEL_ReadDeviceRandom(This,szDeviceList,lSize,lplData,lplReturnCode)	\
    (This)->lpVtbl -> ReadDeviceRandom(This,szDeviceList,lSize,lplData,lplReturnCode)

#define IActAJ71QC24TEL_WriteDeviceRandom(This,szDeviceList,lSize,lplData,lplReturnCode)	\
    (This)->lpVtbl -> WriteDeviceRandom(This,szDeviceList,lSize,lplData,lplReturnCode)

#define IActAJ71QC24TEL_ReadBuffer(This,lStartIO,lAddress,lReadSize,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> ReadBuffer(This,lStartIO,lAddress,lReadSize,lpsData,lplReturnCode)

#define IActAJ71QC24TEL_WriteBuffer(This,lStartIO,lAddress,lWriteSize,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> WriteBuffer(This,lStartIO,lAddress,lWriteSize,lpsData,lplReturnCode)

#define IActAJ71QC24TEL_GetClockData(This,lpsYear,lpsMonth,lpsDay,lpsDayOfWeek,lpsHour,lpsMinute,lpsSecond,lplReturnCode)	\
    (This)->lpVtbl -> GetClockData(This,lpsYear,lpsMonth,lpsDay,lpsDayOfWeek,lpsHour,lpsMinute,lpsSecond,lplReturnCode)

#define IActAJ71QC24TEL_SetClockData(This,sYear,sMonth,sDay,sDayOfWeek,sHour,sMinute,sSecond,lplReturnCode)	\
    (This)->lpVtbl -> SetClockData(This,sYear,sMonth,sDay,sDayOfWeek,sHour,sMinute,sSecond,lplReturnCode)

#define IActAJ71QC24TEL_GetCpuType(This,szCpuName,lplCpuCode,lplReturnCode)	\
    (This)->lpVtbl -> GetCpuType(This,szCpuName,lplCpuCode,lplReturnCode)

#define IActAJ71QC24TEL_SetCpuStatus(This,lOperation,lplReturnCode)	\
    (This)->lpVtbl -> SetCpuStatus(This,lOperation,lplReturnCode)

#define IActAJ71QC24TEL_CheckDeviceString(This,szDevice,lCheckType,lSize,lplDeviceType,lpszDeviceName,lplDeviceNumber,lplDeviceRadix,lplReturnCode)	\
    (This)->lpVtbl -> CheckDeviceString(This,szDevice,lCheckType,lSize,lplDeviceType,lpszDeviceName,lplDeviceNumber,lplDeviceRadix,lplReturnCode)

#define IActAJ71QC24TEL_EntryDeviceStatus(This,szDeviceList,lSize,lMonitorCycle,lplData,lplReturnCode)	\
    (This)->lpVtbl -> EntryDeviceStatus(This,szDeviceList,lSize,lMonitorCycle,lplData,lplReturnCode)

#define IActAJ71QC24TEL_FreeDeviceStatus(This,lplReturnCode)	\
    (This)->lpVtbl -> FreeDeviceStatus(This,lplReturnCode)

#define IActAJ71QC24TEL_ReadDeviceBlock2(This,szDevice,lSize,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> ReadDeviceBlock2(This,szDevice,lSize,lpsData,lplReturnCode)

#define IActAJ71QC24TEL_WriteDeviceBlock2(This,szDevice,lSize,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> WriteDeviceBlock2(This,szDevice,lSize,lpsData,lplReturnCode)

#define IActAJ71QC24TEL_ReadDeviceRandom2(This,szDeviceList,lSize,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> ReadDeviceRandom2(This,szDeviceList,lSize,lpsData,lplReturnCode)

#define IActAJ71QC24TEL_WriteDeviceRandom2(This,szDeviceList,lSize,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> WriteDeviceRandom2(This,szDeviceList,lSize,lpsData,lplReturnCode)

#define IActAJ71QC24TEL_GetDevice2(This,szDevice,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> GetDevice2(This,szDevice,lpsData,lplReturnCode)

#define IActAJ71QC24TEL_SetDevice2(This,szDevice,sData,lplReturnCode)	\
    (This)->lpVtbl -> SetDevice2(This,szDevice,sData,lplReturnCode)

#define IActAJ71QC24TEL_Connect(This,lplReturnCode)	\
    (This)->lpVtbl -> Connect(This,lplReturnCode)

#define IActAJ71QC24TEL_Disconnect(This,lplReturnCode)	\
    (This)->lpVtbl -> Disconnect(This,lplReturnCode)

#define IActAJ71QC24TEL_get_ActNetworkNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActNetworkNumber(This,pVal)

#define IActAJ71QC24TEL_put_ActNetworkNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActNetworkNumber(This,newVal)

#define IActAJ71QC24TEL_get_ActStationNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActStationNumber(This,pVal)

#define IActAJ71QC24TEL_put_ActStationNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActStationNumber(This,newVal)

#define IActAJ71QC24TEL_get_ActUnitNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActUnitNumber(This,pVal)

#define IActAJ71QC24TEL_put_ActUnitNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActUnitNumber(This,newVal)

#define IActAJ71QC24TEL_get_ActConnectUnitNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActConnectUnitNumber(This,pVal)

#define IActAJ71QC24TEL_put_ActConnectUnitNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActConnectUnitNumber(This,newVal)

#define IActAJ71QC24TEL_get_ActIONumber(This,pVal)	\
    (This)->lpVtbl -> get_ActIONumber(This,pVal)

#define IActAJ71QC24TEL_put_ActIONumber(This,newVal)	\
    (This)->lpVtbl -> put_ActIONumber(This,newVal)

#define IActAJ71QC24TEL_get_ActCpuType(This,pVal)	\
    (This)->lpVtbl -> get_ActCpuType(This,pVal)

#define IActAJ71QC24TEL_put_ActCpuType(This,newVal)	\
    (This)->lpVtbl -> put_ActCpuType(This,newVal)

#define IActAJ71QC24TEL_get_ActPortNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActPortNumber(This,pVal)

#define IActAJ71QC24TEL_put_ActPortNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActPortNumber(This,newVal)

#define IActAJ71QC24TEL_get_ActBaudRate(This,pVal)	\
    (This)->lpVtbl -> get_ActBaudRate(This,pVal)

#define IActAJ71QC24TEL_put_ActBaudRate(This,newVal)	\
    (This)->lpVtbl -> put_ActBaudRate(This,newVal)

#define IActAJ71QC24TEL_get_ActTimeOut(This,pVal)	\
    (This)->lpVtbl -> get_ActTimeOut(This,pVal)

#define IActAJ71QC24TEL_put_ActTimeOut(This,newVal)	\
    (This)->lpVtbl -> put_ActTimeOut(This,newVal)

#define IActAJ71QC24TEL_get_ActATCommand(This,pVal)	\
    (This)->lpVtbl -> get_ActATCommand(This,pVal)

#define IActAJ71QC24TEL_put_ActATCommand(This,newVal)	\
    (This)->lpVtbl -> put_ActATCommand(This,newVal)

#define IActAJ71QC24TEL_get_ActDialNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActDialNumber(This,pVal)

#define IActAJ71QC24TEL_put_ActDialNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActDialNumber(This,newVal)

#define IActAJ71QC24TEL_get_ActLineType(This,pVal)	\
    (This)->lpVtbl -> get_ActLineType(This,pVal)

#define IActAJ71QC24TEL_put_ActLineType(This,newVal)	\
    (This)->lpVtbl -> put_ActLineType(This,newVal)

#define IActAJ71QC24TEL_get_ActConnectionCDWaitTime(This,pVal)	\
    (This)->lpVtbl -> get_ActConnectionCDWaitTime(This,pVal)

#define IActAJ71QC24TEL_put_ActConnectionCDWaitTime(This,newVal)	\
    (This)->lpVtbl -> put_ActConnectionCDWaitTime(This,newVal)

#define IActAJ71QC24TEL_get_ActConnectionModemReportWaitTime(This,pVal)	\
    (This)->lpVtbl -> get_ActConnectionModemReportWaitTime(This,pVal)

#define IActAJ71QC24TEL_put_ActConnectionModemReportWaitTime(This,newVal)	\
    (This)->lpVtbl -> put_ActConnectionModemReportWaitTime(This,newVal)

#define IActAJ71QC24TEL_get_ActDisconnectionCDWaitTime(This,pVal)	\
    (This)->lpVtbl -> get_ActDisconnectionCDWaitTime(This,pVal)

#define IActAJ71QC24TEL_put_ActDisconnectionCDWaitTime(This,newVal)	\
    (This)->lpVtbl -> put_ActDisconnectionCDWaitTime(This,newVal)

#define IActAJ71QC24TEL_get_ActDisconnectionDelayTime(This,pVal)	\
    (This)->lpVtbl -> get_ActDisconnectionDelayTime(This,pVal)

#define IActAJ71QC24TEL_put_ActDisconnectionDelayTime(This,newVal)	\
    (This)->lpVtbl -> put_ActDisconnectionDelayTime(This,newVal)

#define IActAJ71QC24TEL_get_ActTransmissionDelayTime(This,pVal)	\
    (This)->lpVtbl -> get_ActTransmissionDelayTime(This,pVal)

#define IActAJ71QC24TEL_put_ActTransmissionDelayTime(This,newVal)	\
    (This)->lpVtbl -> put_ActTransmissionDelayTime(This,newVal)

#define IActAJ71QC24TEL_get_ActATCommandResponseWaitTime(This,pVal)	\
    (This)->lpVtbl -> get_ActATCommandResponseWaitTime(This,pVal)

#define IActAJ71QC24TEL_put_ActATCommandResponseWaitTime(This,newVal)	\
    (This)->lpVtbl -> put_ActATCommandResponseWaitTime(This,newVal)

#define IActAJ71QC24TEL_get_ActATCommandPasswordCancelRetryTimes(This,pVal)	\
    (This)->lpVtbl -> get_ActATCommandPasswordCancelRetryTimes(This,pVal)

#define IActAJ71QC24TEL_put_ActATCommandPasswordCancelRetryTimes(This,newVal)	\
    (This)->lpVtbl -> put_ActATCommandPasswordCancelRetryTimes(This,newVal)

#define IActAJ71QC24TEL_get_ActOutsideLineNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActOutsideLineNumber(This,pVal)

#define IActAJ71QC24TEL_put_ActOutsideLineNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActOutsideLineNumber(This,newVal)

#define IActAJ71QC24TEL_get_ActPasswordCancelResponseWaitTime(This,pVal)	\
    (This)->lpVtbl -> get_ActPasswordCancelResponseWaitTime(This,pVal)

#define IActAJ71QC24TEL_put_ActPasswordCancelResponseWaitTime(This,newVal)	\
    (This)->lpVtbl -> put_ActPasswordCancelResponseWaitTime(This,newVal)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActAJ71QC24TEL_Open_Proxy( 
    IActAJ71QC24TEL __RPC_FAR * This,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActAJ71QC24TEL_Open_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActAJ71QC24TEL_Close_Proxy( 
    IActAJ71QC24TEL __RPC_FAR * This,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActAJ71QC24TEL_Close_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActAJ71QC24TEL_GetDevice_Proxy( 
    IActAJ71QC24TEL __RPC_FAR * This,
    /* [string][in] */ BSTR szDevice,
    /* [out] */ LONG __RPC_FAR *lplData,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActAJ71QC24TEL_GetDevice_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActAJ71QC24TEL_SetDevice_Proxy( 
    IActAJ71QC24TEL __RPC_FAR * This,
    /* [string][in] */ BSTR szDevice,
    /* [in] */ LONG lData,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActAJ71QC24TEL_SetDevice_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActAJ71QC24TEL_ReadDeviceBlock_Proxy( 
    IActAJ71QC24TEL __RPC_FAR * This,
    /* [string][in] */ BSTR szDevice,
    /* [in] */ LONG lSize,
    /* [size_is][out] */ LONG __RPC_FAR *lplData,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActAJ71QC24TEL_ReadDeviceBlock_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActAJ71QC24TEL_WriteDeviceBlock_Proxy( 
    IActAJ71QC24TEL __RPC_FAR * This,
    /* [string][in] */ BSTR szDevice,
    /* [in] */ LONG lSize,
    /* [size_is][in] */ LONG __RPC_FAR *lplData,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActAJ71QC24TEL_WriteDeviceBlock_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActAJ71QC24TEL_ReadDeviceRandom_Proxy( 
    IActAJ71QC24TEL __RPC_FAR * This,
    /* [string][in] */ BSTR szDeviceList,
    /* [in] */ LONG lSize,
    /* [size_is][out] */ LONG __RPC_FAR *lplData,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActAJ71QC24TEL_ReadDeviceRandom_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActAJ71QC24TEL_WriteDeviceRandom_Proxy( 
    IActAJ71QC24TEL __RPC_FAR * This,
    /* [string][in] */ BSTR szDeviceList,
    /* [in] */ LONG lSize,
    /* [size_is][in] */ LONG __RPC_FAR *lplData,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActAJ71QC24TEL_WriteDeviceRandom_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActAJ71QC24TEL_ReadBuffer_Proxy( 
    IActAJ71QC24TEL __RPC_FAR * This,
    /* [in] */ LONG lStartIO,
    /* [in] */ LONG lAddress,
    /* [in] */ LONG lReadSize,
    /* [size_is][out] */ SHORT __RPC_FAR *lpsData,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActAJ71QC24TEL_ReadBuffer_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActAJ71QC24TEL_WriteBuffer_Proxy( 
    IActAJ71QC24TEL __RPC_FAR * This,
    /* [in] */ LONG lStartIO,
    /* [in] */ LONG lAddress,
    /* [in] */ LONG lWriteSize,
    /* [size_is][in] */ SHORT __RPC_FAR *lpsData,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActAJ71QC24TEL_WriteBuffer_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActAJ71QC24TEL_GetClockData_Proxy( 
    IActAJ71QC24TEL __RPC_FAR * This,
    /* [out] */ SHORT __RPC_FAR *lpsYear,
    /* [out] */ SHORT __RPC_FAR *lpsMonth,
    /* [out] */ SHORT __RPC_FAR *lpsDay,
    /* [out] */ SHORT __RPC_FAR *lpsDayOfWeek,
    /* [out] */ SHORT __RPC_FAR *lpsHour,
    /* [out] */ SHORT __RPC_FAR *lpsMinute,
    /* [out] */ SHORT __RPC_FAR *lpsSecond,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActAJ71QC24TEL_GetClockData_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActAJ71QC24TEL_SetClockData_Proxy( 
    IActAJ71QC24TEL __RPC_FAR * This,
    /* [in] */ SHORT sYear,
    /* [in] */ SHORT sMonth,
    /* [in] */ SHORT sDay,
    /* [in] */ SHORT sDayOfWeek,
    /* [in] */ SHORT sHour,
    /* [in] */ SHORT sMinute,
    /* [in] */ SHORT sSecond,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActAJ71QC24TEL_SetClockData_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActAJ71QC24TEL_GetCpuType_Proxy( 
    IActAJ71QC24TEL __RPC_FAR * This,
    /* [string][out] */ BSTR __RPC_FAR *szCpuName,
    /* [out] */ LONG __RPC_FAR *lplCpuCode,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActAJ71QC24TEL_GetCpuType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActAJ71QC24TEL_SetCpuStatus_Proxy( 
    IActAJ71QC24TEL __RPC_FAR * This,
    /* [in] */ LONG lOperation,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActAJ71QC24TEL_SetCpuStatus_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActAJ71QC24TEL_CheckDeviceString_Proxy( 
    IActAJ71QC24TEL __RPC_FAR * This,
    /* [string][in] */ BSTR szDevice,
    /* [in] */ LONG lCheckType,
    /* [in] */ LONG lSize,
    /* [out] */ LONG __RPC_FAR *lplDeviceType,
    /* [string][out] */ BSTR __RPC_FAR *lpszDeviceName,
    /* [out] */ LONG __RPC_FAR *lplDeviceNumber,
    /* [out] */ LONG __RPC_FAR *lplDeviceRadix,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActAJ71QC24TEL_CheckDeviceString_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActAJ71QC24TEL_EntryDeviceStatus_Proxy( 
    IActAJ71QC24TEL __RPC_FAR * This,
    /* [string][in] */ BSTR szDeviceList,
    /* [in] */ LONG lSize,
    /* [in] */ LONG lMonitorCycle,
    /* [size_is][in] */ LONG __RPC_FAR *lplData,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActAJ71QC24TEL_EntryDeviceStatus_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActAJ71QC24TEL_FreeDeviceStatus_Proxy( 
    IActAJ71QC24TEL __RPC_FAR * This,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActAJ71QC24TEL_FreeDeviceStatus_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActAJ71QC24TEL_ReadDeviceBlock2_Proxy( 
    IActAJ71QC24TEL __RPC_FAR * This,
    /* [string][in] */ BSTR szDevice,
    /* [in] */ LONG lSize,
    /* [size_is][out] */ SHORT __RPC_FAR *lpsData,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActAJ71QC24TEL_ReadDeviceBlock2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActAJ71QC24TEL_WriteDeviceBlock2_Proxy( 
    IActAJ71QC24TEL __RPC_FAR * This,
    /* [string][in] */ BSTR szDevice,
    /* [in] */ LONG lSize,
    /* [size_is][in] */ SHORT __RPC_FAR *lpsData,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActAJ71QC24TEL_WriteDeviceBlock2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActAJ71QC24TEL_ReadDeviceRandom2_Proxy( 
    IActAJ71QC24TEL __RPC_FAR * This,
    /* [string][in] */ BSTR szDeviceList,
    /* [in] */ LONG lSize,
    /* [size_is][out] */ SHORT __RPC_FAR *lpsData,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActAJ71QC24TEL_ReadDeviceRandom2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActAJ71QC24TEL_WriteDeviceRandom2_Proxy( 
    IActAJ71QC24TEL __RPC_FAR * This,
    /* [string][in] */ BSTR szDeviceList,
    /* [in] */ LONG lSize,
    /* [size_is][in] */ SHORT __RPC_FAR *lpsData,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActAJ71QC24TEL_WriteDeviceRandom2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActAJ71QC24TEL_GetDevice2_Proxy( 
    IActAJ71QC24TEL __RPC_FAR * This,
    /* [string][in] */ BSTR szDevice,
    /* [out] */ SHORT __RPC_FAR *lpsData,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActAJ71QC24TEL_GetDevice2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActAJ71QC24TEL_SetDevice2_Proxy( 
    IActAJ71QC24TEL __RPC_FAR * This,
    /* [string][in] */ BSTR szDevice,
    /* [in] */ SHORT sData,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActAJ71QC24TEL_SetDevice2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActAJ71QC24TEL_Connect_Proxy( 
    IActAJ71QC24TEL __RPC_FAR * This,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActAJ71QC24TEL_Connect_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActAJ71QC24TEL_Disconnect_Proxy( 
    IActAJ71QC24TEL __RPC_FAR * This,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActAJ71QC24TEL_Disconnect_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActAJ71QC24TEL_get_ActNetworkNumber_Proxy( 
    IActAJ71QC24TEL __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IActAJ71QC24TEL_get_ActNetworkNumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActAJ71QC24TEL_put_ActNetworkNumber_Proxy( 
    IActAJ71QC24TEL __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB IActAJ71QC24TEL_put_ActNetworkNumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActAJ71QC24TEL_get_ActStationNumber_Proxy( 
    IActAJ71QC24TEL __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IActAJ71QC24TEL_get_ActStationNumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActAJ71QC24TEL_put_ActStationNumber_Proxy( 
    IActAJ71QC24TEL __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB IActAJ71QC24TEL_put_ActStationNumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActAJ71QC24TEL_get_ActUnitNumber_Proxy( 
    IActAJ71QC24TEL __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IActAJ71QC24TEL_get_ActUnitNumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActAJ71QC24TEL_put_ActUnitNumber_Proxy( 
    IActAJ71QC24TEL __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB IActAJ71QC24TEL_put_ActUnitNumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActAJ71QC24TEL_get_ActConnectUnitNumber_Proxy( 
    IActAJ71QC24TEL __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IActAJ71QC24TEL_get_ActConnectUnitNumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActAJ71QC24TEL_put_ActConnectUnitNumber_Proxy( 
    IActAJ71QC24TEL __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB IActAJ71QC24TEL_put_ActConnectUnitNumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActAJ71QC24TEL_get_ActIONumber_Proxy( 
    IActAJ71QC24TEL __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IActAJ71QC24TEL_get_ActIONumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActAJ71QC24TEL_put_ActIONumber_Proxy( 
    IActAJ71QC24TEL __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB IActAJ71QC24TEL_put_ActIONumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActAJ71QC24TEL_get_ActCpuType_Proxy( 
    IActAJ71QC24TEL __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IActAJ71QC24TEL_get_ActCpuType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActAJ71QC24TEL_put_ActCpuType_Proxy( 
    IActAJ71QC24TEL __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB IActAJ71QC24TEL_put_ActCpuType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActAJ71QC24TEL_get_ActPortNumber_Proxy( 
    IActAJ71QC24TEL __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IActAJ71QC24TEL_get_ActPortNumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActAJ71QC24TEL_put_ActPortNumber_Proxy( 
    IActAJ71QC24TEL __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB IActAJ71QC24TEL_put_ActPortNumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActAJ71QC24TEL_get_ActBaudRate_Proxy( 
    IActAJ71QC24TEL __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IActAJ71QC24TEL_get_ActBaudRate_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActAJ71QC24TEL_put_ActBaudRate_Proxy( 
    IActAJ71QC24TEL __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB IActAJ71QC24TEL_put_ActBaudRate_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActAJ71QC24TEL_get_ActTimeOut_Proxy( 
    IActAJ71QC24TEL __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IActAJ71QC24TEL_get_ActTimeOut_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActAJ71QC24TEL_put_ActTimeOut_Proxy( 
    IActAJ71QC24TEL __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB IActAJ71QC24TEL_put_ActTimeOut_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActAJ71QC24TEL_get_ActATCommand_Proxy( 
    IActAJ71QC24TEL __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *pVal);


void __RPC_STUB IActAJ71QC24TEL_get_ActATCommand_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActAJ71QC24TEL_put_ActATCommand_Proxy( 
    IActAJ71QC24TEL __RPC_FAR * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB IActAJ71QC24TEL_put_ActATCommand_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActAJ71QC24TEL_get_ActDialNumber_Proxy( 
    IActAJ71QC24TEL __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *pVal);


void __RPC_STUB IActAJ71QC24TEL_get_ActDialNumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActAJ71QC24TEL_put_ActDialNumber_Proxy( 
    IActAJ71QC24TEL __RPC_FAR * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB IActAJ71QC24TEL_put_ActDialNumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActAJ71QC24TEL_get_ActLineType_Proxy( 
    IActAJ71QC24TEL __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IActAJ71QC24TEL_get_ActLineType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActAJ71QC24TEL_put_ActLineType_Proxy( 
    IActAJ71QC24TEL __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB IActAJ71QC24TEL_put_ActLineType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActAJ71QC24TEL_get_ActConnectionCDWaitTime_Proxy( 
    IActAJ71QC24TEL __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IActAJ71QC24TEL_get_ActConnectionCDWaitTime_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActAJ71QC24TEL_put_ActConnectionCDWaitTime_Proxy( 
    IActAJ71QC24TEL __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB IActAJ71QC24TEL_put_ActConnectionCDWaitTime_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActAJ71QC24TEL_get_ActConnectionModemReportWaitTime_Proxy( 
    IActAJ71QC24TEL __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IActAJ71QC24TEL_get_ActConnectionModemReportWaitTime_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActAJ71QC24TEL_put_ActConnectionModemReportWaitTime_Proxy( 
    IActAJ71QC24TEL __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB IActAJ71QC24TEL_put_ActConnectionModemReportWaitTime_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActAJ71QC24TEL_get_ActDisconnectionCDWaitTime_Proxy( 
    IActAJ71QC24TEL __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IActAJ71QC24TEL_get_ActDisconnectionCDWaitTime_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActAJ71QC24TEL_put_ActDisconnectionCDWaitTime_Proxy( 
    IActAJ71QC24TEL __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB IActAJ71QC24TEL_put_ActDisconnectionCDWaitTime_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActAJ71QC24TEL_get_ActDisconnectionDelayTime_Proxy( 
    IActAJ71QC24TEL __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IActAJ71QC24TEL_get_ActDisconnectionDelayTime_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActAJ71QC24TEL_put_ActDisconnectionDelayTime_Proxy( 
    IActAJ71QC24TEL __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB IActAJ71QC24TEL_put_ActDisconnectionDelayTime_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActAJ71QC24TEL_get_ActTransmissionDelayTime_Proxy( 
    IActAJ71QC24TEL __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IActAJ71QC24TEL_get_ActTransmissionDelayTime_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActAJ71QC24TEL_put_ActTransmissionDelayTime_Proxy( 
    IActAJ71QC24TEL __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB IActAJ71QC24TEL_put_ActTransmissionDelayTime_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActAJ71QC24TEL_get_ActATCommandResponseWaitTime_Proxy( 
    IActAJ71QC24TEL __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IActAJ71QC24TEL_get_ActATCommandResponseWaitTime_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActAJ71QC24TEL_put_ActATCommandResponseWaitTime_Proxy( 
    IActAJ71QC24TEL __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB IActAJ71QC24TEL_put_ActATCommandResponseWaitTime_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActAJ71QC24TEL_get_ActATCommandPasswordCancelRetryTimes_Proxy( 
    IActAJ71QC24TEL __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IActAJ71QC24TEL_get_ActATCommandPasswordCancelRetryTimes_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActAJ71QC24TEL_put_ActATCommandPasswordCancelRetryTimes_Proxy( 
    IActAJ71QC24TEL __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB IActAJ71QC24TEL_put_ActATCommandPasswordCancelRetryTimes_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActAJ71QC24TEL_get_ActOutsideLineNumber_Proxy( 
    IActAJ71QC24TEL __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *pVal);


void __RPC_STUB IActAJ71QC24TEL_get_ActOutsideLineNumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActAJ71QC24TEL_put_ActOutsideLineNumber_Proxy( 
    IActAJ71QC24TEL __RPC_FAR * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB IActAJ71QC24TEL_put_ActOutsideLineNumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActAJ71QC24TEL_get_ActPasswordCancelResponseWaitTime_Proxy( 
    IActAJ71QC24TEL __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IActAJ71QC24TEL_get_ActPasswordCancelResponseWaitTime_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActAJ71QC24TEL_put_ActPasswordCancelResponseWaitTime_Proxy( 
    IActAJ71QC24TEL __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB IActAJ71QC24TEL_put_ActPasswordCancelResponseWaitTime_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IActAJ71QC24TEL_INTERFACE_DEFINED__ */


#ifndef __IActAJ71QC24TEL2_INTERFACE_DEFINED__
#define __IActAJ71QC24TEL2_INTERFACE_DEFINED__

/* interface IActAJ71QC24TEL2 */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IActAJ71QC24TEL2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("8716603C-710B-11d5-9318-009099244EFD")
    IActAJ71QC24TEL2 : public IActAJ71QC24TEL
    {
    public:
    };
    
#else 	/* C style interface */

    typedef struct IActAJ71QC24TEL2Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IActAJ71QC24TEL2 __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IActAJ71QC24TEL2 __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IActAJ71QC24TEL2 __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IActAJ71QC24TEL2 __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IActAJ71QC24TEL2 __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IActAJ71QC24TEL2 __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IActAJ71QC24TEL2 __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Open )( 
            IActAJ71QC24TEL2 __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Close )( 
            IActAJ71QC24TEL2 __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetDevice )( 
            IActAJ71QC24TEL2 __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [out] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetDevice )( 
            IActAJ71QC24TEL2 __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceBlock )( 
            IActAJ71QC24TEL2 __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lSize,
            /* [size_is][out] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceBlock )( 
            IActAJ71QC24TEL2 __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lSize,
            /* [size_is][in] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceRandom )( 
            IActAJ71QC24TEL2 __RPC_FAR * This,
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG lSize,
            /* [size_is][out] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceRandom )( 
            IActAJ71QC24TEL2 __RPC_FAR * This,
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG lSize,
            /* [size_is][in] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadBuffer )( 
            IActAJ71QC24TEL2 __RPC_FAR * This,
            /* [in] */ LONG lStartIO,
            /* [in] */ LONG lAddress,
            /* [in] */ LONG lReadSize,
            /* [size_is][out] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteBuffer )( 
            IActAJ71QC24TEL2 __RPC_FAR * This,
            /* [in] */ LONG lStartIO,
            /* [in] */ LONG lAddress,
            /* [in] */ LONG lWriteSize,
            /* [size_is][in] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetClockData )( 
            IActAJ71QC24TEL2 __RPC_FAR * This,
            /* [out] */ SHORT __RPC_FAR *lpsYear,
            /* [out] */ SHORT __RPC_FAR *lpsMonth,
            /* [out] */ SHORT __RPC_FAR *lpsDay,
            /* [out] */ SHORT __RPC_FAR *lpsDayOfWeek,
            /* [out] */ SHORT __RPC_FAR *lpsHour,
            /* [out] */ SHORT __RPC_FAR *lpsMinute,
            /* [out] */ SHORT __RPC_FAR *lpsSecond,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetClockData )( 
            IActAJ71QC24TEL2 __RPC_FAR * This,
            /* [in] */ SHORT sYear,
            /* [in] */ SHORT sMonth,
            /* [in] */ SHORT sDay,
            /* [in] */ SHORT sDayOfWeek,
            /* [in] */ SHORT sHour,
            /* [in] */ SHORT sMinute,
            /* [in] */ SHORT sSecond,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetCpuType )( 
            IActAJ71QC24TEL2 __RPC_FAR * This,
            /* [string][out] */ BSTR __RPC_FAR *szCpuName,
            /* [out] */ LONG __RPC_FAR *lplCpuCode,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetCpuStatus )( 
            IActAJ71QC24TEL2 __RPC_FAR * This,
            /* [in] */ LONG lOperation,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CheckDeviceString )( 
            IActAJ71QC24TEL2 __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lCheckType,
            /* [in] */ LONG lSize,
            /* [out] */ LONG __RPC_FAR *lplDeviceType,
            /* [string][out] */ BSTR __RPC_FAR *lpszDeviceName,
            /* [out] */ LONG __RPC_FAR *lplDeviceNumber,
            /* [out] */ LONG __RPC_FAR *lplDeviceRadix,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *EntryDeviceStatus )( 
            IActAJ71QC24TEL2 __RPC_FAR * This,
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG lSize,
            /* [in] */ LONG lMonitorCycle,
            /* [size_is][in] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *FreeDeviceStatus )( 
            IActAJ71QC24TEL2 __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceBlock2 )( 
            IActAJ71QC24TEL2 __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lSize,
            /* [size_is][out] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceBlock2 )( 
            IActAJ71QC24TEL2 __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lSize,
            /* [size_is][in] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceRandom2 )( 
            IActAJ71QC24TEL2 __RPC_FAR * This,
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG lSize,
            /* [size_is][out] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceRandom2 )( 
            IActAJ71QC24TEL2 __RPC_FAR * This,
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG lSize,
            /* [size_is][in] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetDevice2 )( 
            IActAJ71QC24TEL2 __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [out] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetDevice2 )( 
            IActAJ71QC24TEL2 __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ SHORT sData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Connect )( 
            IActAJ71QC24TEL2 __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Disconnect )( 
            IActAJ71QC24TEL2 __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActNetworkNumber )( 
            IActAJ71QC24TEL2 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActNetworkNumber )( 
            IActAJ71QC24TEL2 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActStationNumber )( 
            IActAJ71QC24TEL2 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActStationNumber )( 
            IActAJ71QC24TEL2 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActUnitNumber )( 
            IActAJ71QC24TEL2 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActUnitNumber )( 
            IActAJ71QC24TEL2 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActConnectUnitNumber )( 
            IActAJ71QC24TEL2 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActConnectUnitNumber )( 
            IActAJ71QC24TEL2 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActIONumber )( 
            IActAJ71QC24TEL2 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActIONumber )( 
            IActAJ71QC24TEL2 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActCpuType )( 
            IActAJ71QC24TEL2 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActCpuType )( 
            IActAJ71QC24TEL2 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActPortNumber )( 
            IActAJ71QC24TEL2 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActPortNumber )( 
            IActAJ71QC24TEL2 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActBaudRate )( 
            IActAJ71QC24TEL2 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActBaudRate )( 
            IActAJ71QC24TEL2 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActTimeOut )( 
            IActAJ71QC24TEL2 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActTimeOut )( 
            IActAJ71QC24TEL2 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActATCommand )( 
            IActAJ71QC24TEL2 __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActATCommand )( 
            IActAJ71QC24TEL2 __RPC_FAR * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActDialNumber )( 
            IActAJ71QC24TEL2 __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActDialNumber )( 
            IActAJ71QC24TEL2 __RPC_FAR * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActLineType )( 
            IActAJ71QC24TEL2 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActLineType )( 
            IActAJ71QC24TEL2 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActConnectionCDWaitTime )( 
            IActAJ71QC24TEL2 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActConnectionCDWaitTime )( 
            IActAJ71QC24TEL2 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActConnectionModemReportWaitTime )( 
            IActAJ71QC24TEL2 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActConnectionModemReportWaitTime )( 
            IActAJ71QC24TEL2 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActDisconnectionCDWaitTime )( 
            IActAJ71QC24TEL2 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActDisconnectionCDWaitTime )( 
            IActAJ71QC24TEL2 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActDisconnectionDelayTime )( 
            IActAJ71QC24TEL2 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActDisconnectionDelayTime )( 
            IActAJ71QC24TEL2 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActTransmissionDelayTime )( 
            IActAJ71QC24TEL2 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActTransmissionDelayTime )( 
            IActAJ71QC24TEL2 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActATCommandResponseWaitTime )( 
            IActAJ71QC24TEL2 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActATCommandResponseWaitTime )( 
            IActAJ71QC24TEL2 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActATCommandPasswordCancelRetryTimes )( 
            IActAJ71QC24TEL2 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActATCommandPasswordCancelRetryTimes )( 
            IActAJ71QC24TEL2 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActOutsideLineNumber )( 
            IActAJ71QC24TEL2 __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActOutsideLineNumber )( 
            IActAJ71QC24TEL2 __RPC_FAR * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActPasswordCancelResponseWaitTime )( 
            IActAJ71QC24TEL2 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActPasswordCancelResponseWaitTime )( 
            IActAJ71QC24TEL2 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        END_INTERFACE
    } IActAJ71QC24TEL2Vtbl;

    interface IActAJ71QC24TEL2
    {
        CONST_VTBL struct IActAJ71QC24TEL2Vtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IActAJ71QC24TEL2_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IActAJ71QC24TEL2_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IActAJ71QC24TEL2_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IActAJ71QC24TEL2_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IActAJ71QC24TEL2_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IActAJ71QC24TEL2_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IActAJ71QC24TEL2_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IActAJ71QC24TEL2_Open(This,lplReturnCode)	\
    (This)->lpVtbl -> Open(This,lplReturnCode)

#define IActAJ71QC24TEL2_Close(This,lplReturnCode)	\
    (This)->lpVtbl -> Close(This,lplReturnCode)

#define IActAJ71QC24TEL2_GetDevice(This,szDevice,lplData,lplReturnCode)	\
    (This)->lpVtbl -> GetDevice(This,szDevice,lplData,lplReturnCode)

#define IActAJ71QC24TEL2_SetDevice(This,szDevice,lData,lplReturnCode)	\
    (This)->lpVtbl -> SetDevice(This,szDevice,lData,lplReturnCode)

#define IActAJ71QC24TEL2_ReadDeviceBlock(This,szDevice,lSize,lplData,lplReturnCode)	\
    (This)->lpVtbl -> ReadDeviceBlock(This,szDevice,lSize,lplData,lplReturnCode)

#define IActAJ71QC24TEL2_WriteDeviceBlock(This,szDevice,lSize,lplData,lplReturnCode)	\
    (This)->lpVtbl -> WriteDeviceBlock(This,szDevice,lSize,lplData,lplReturnCode)

#define IActAJ71QC24TEL2_ReadDeviceRandom(This,szDeviceList,lSize,lplData,lplReturnCode)	\
    (This)->lpVtbl -> ReadDeviceRandom(This,szDeviceList,lSize,lplData,lplReturnCode)

#define IActAJ71QC24TEL2_WriteDeviceRandom(This,szDeviceList,lSize,lplData,lplReturnCode)	\
    (This)->lpVtbl -> WriteDeviceRandom(This,szDeviceList,lSize,lplData,lplReturnCode)

#define IActAJ71QC24TEL2_ReadBuffer(This,lStartIO,lAddress,lReadSize,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> ReadBuffer(This,lStartIO,lAddress,lReadSize,lpsData,lplReturnCode)

#define IActAJ71QC24TEL2_WriteBuffer(This,lStartIO,lAddress,lWriteSize,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> WriteBuffer(This,lStartIO,lAddress,lWriteSize,lpsData,lplReturnCode)

#define IActAJ71QC24TEL2_GetClockData(This,lpsYear,lpsMonth,lpsDay,lpsDayOfWeek,lpsHour,lpsMinute,lpsSecond,lplReturnCode)	\
    (This)->lpVtbl -> GetClockData(This,lpsYear,lpsMonth,lpsDay,lpsDayOfWeek,lpsHour,lpsMinute,lpsSecond,lplReturnCode)

#define IActAJ71QC24TEL2_SetClockData(This,sYear,sMonth,sDay,sDayOfWeek,sHour,sMinute,sSecond,lplReturnCode)	\
    (This)->lpVtbl -> SetClockData(This,sYear,sMonth,sDay,sDayOfWeek,sHour,sMinute,sSecond,lplReturnCode)

#define IActAJ71QC24TEL2_GetCpuType(This,szCpuName,lplCpuCode,lplReturnCode)	\
    (This)->lpVtbl -> GetCpuType(This,szCpuName,lplCpuCode,lplReturnCode)

#define IActAJ71QC24TEL2_SetCpuStatus(This,lOperation,lplReturnCode)	\
    (This)->lpVtbl -> SetCpuStatus(This,lOperation,lplReturnCode)

#define IActAJ71QC24TEL2_CheckDeviceString(This,szDevice,lCheckType,lSize,lplDeviceType,lpszDeviceName,lplDeviceNumber,lplDeviceRadix,lplReturnCode)	\
    (This)->lpVtbl -> CheckDeviceString(This,szDevice,lCheckType,lSize,lplDeviceType,lpszDeviceName,lplDeviceNumber,lplDeviceRadix,lplReturnCode)

#define IActAJ71QC24TEL2_EntryDeviceStatus(This,szDeviceList,lSize,lMonitorCycle,lplData,lplReturnCode)	\
    (This)->lpVtbl -> EntryDeviceStatus(This,szDeviceList,lSize,lMonitorCycle,lplData,lplReturnCode)

#define IActAJ71QC24TEL2_FreeDeviceStatus(This,lplReturnCode)	\
    (This)->lpVtbl -> FreeDeviceStatus(This,lplReturnCode)

#define IActAJ71QC24TEL2_ReadDeviceBlock2(This,szDevice,lSize,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> ReadDeviceBlock2(This,szDevice,lSize,lpsData,lplReturnCode)

#define IActAJ71QC24TEL2_WriteDeviceBlock2(This,szDevice,lSize,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> WriteDeviceBlock2(This,szDevice,lSize,lpsData,lplReturnCode)

#define IActAJ71QC24TEL2_ReadDeviceRandom2(This,szDeviceList,lSize,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> ReadDeviceRandom2(This,szDeviceList,lSize,lpsData,lplReturnCode)

#define IActAJ71QC24TEL2_WriteDeviceRandom2(This,szDeviceList,lSize,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> WriteDeviceRandom2(This,szDeviceList,lSize,lpsData,lplReturnCode)

#define IActAJ71QC24TEL2_GetDevice2(This,szDevice,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> GetDevice2(This,szDevice,lpsData,lplReturnCode)

#define IActAJ71QC24TEL2_SetDevice2(This,szDevice,sData,lplReturnCode)	\
    (This)->lpVtbl -> SetDevice2(This,szDevice,sData,lplReturnCode)

#define IActAJ71QC24TEL2_Connect(This,lplReturnCode)	\
    (This)->lpVtbl -> Connect(This,lplReturnCode)

#define IActAJ71QC24TEL2_Disconnect(This,lplReturnCode)	\
    (This)->lpVtbl -> Disconnect(This,lplReturnCode)

#define IActAJ71QC24TEL2_get_ActNetworkNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActNetworkNumber(This,pVal)

#define IActAJ71QC24TEL2_put_ActNetworkNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActNetworkNumber(This,newVal)

#define IActAJ71QC24TEL2_get_ActStationNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActStationNumber(This,pVal)

#define IActAJ71QC24TEL2_put_ActStationNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActStationNumber(This,newVal)

#define IActAJ71QC24TEL2_get_ActUnitNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActUnitNumber(This,pVal)

#define IActAJ71QC24TEL2_put_ActUnitNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActUnitNumber(This,newVal)

#define IActAJ71QC24TEL2_get_ActConnectUnitNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActConnectUnitNumber(This,pVal)

#define IActAJ71QC24TEL2_put_ActConnectUnitNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActConnectUnitNumber(This,newVal)

#define IActAJ71QC24TEL2_get_ActIONumber(This,pVal)	\
    (This)->lpVtbl -> get_ActIONumber(This,pVal)

#define IActAJ71QC24TEL2_put_ActIONumber(This,newVal)	\
    (This)->lpVtbl -> put_ActIONumber(This,newVal)

#define IActAJ71QC24TEL2_get_ActCpuType(This,pVal)	\
    (This)->lpVtbl -> get_ActCpuType(This,pVal)

#define IActAJ71QC24TEL2_put_ActCpuType(This,newVal)	\
    (This)->lpVtbl -> put_ActCpuType(This,newVal)

#define IActAJ71QC24TEL2_get_ActPortNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActPortNumber(This,pVal)

#define IActAJ71QC24TEL2_put_ActPortNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActPortNumber(This,newVal)

#define IActAJ71QC24TEL2_get_ActBaudRate(This,pVal)	\
    (This)->lpVtbl -> get_ActBaudRate(This,pVal)

#define IActAJ71QC24TEL2_put_ActBaudRate(This,newVal)	\
    (This)->lpVtbl -> put_ActBaudRate(This,newVal)

#define IActAJ71QC24TEL2_get_ActTimeOut(This,pVal)	\
    (This)->lpVtbl -> get_ActTimeOut(This,pVal)

#define IActAJ71QC24TEL2_put_ActTimeOut(This,newVal)	\
    (This)->lpVtbl -> put_ActTimeOut(This,newVal)

#define IActAJ71QC24TEL2_get_ActATCommand(This,pVal)	\
    (This)->lpVtbl -> get_ActATCommand(This,pVal)

#define IActAJ71QC24TEL2_put_ActATCommand(This,newVal)	\
    (This)->lpVtbl -> put_ActATCommand(This,newVal)

#define IActAJ71QC24TEL2_get_ActDialNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActDialNumber(This,pVal)

#define IActAJ71QC24TEL2_put_ActDialNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActDialNumber(This,newVal)

#define IActAJ71QC24TEL2_get_ActLineType(This,pVal)	\
    (This)->lpVtbl -> get_ActLineType(This,pVal)

#define IActAJ71QC24TEL2_put_ActLineType(This,newVal)	\
    (This)->lpVtbl -> put_ActLineType(This,newVal)

#define IActAJ71QC24TEL2_get_ActConnectionCDWaitTime(This,pVal)	\
    (This)->lpVtbl -> get_ActConnectionCDWaitTime(This,pVal)

#define IActAJ71QC24TEL2_put_ActConnectionCDWaitTime(This,newVal)	\
    (This)->lpVtbl -> put_ActConnectionCDWaitTime(This,newVal)

#define IActAJ71QC24TEL2_get_ActConnectionModemReportWaitTime(This,pVal)	\
    (This)->lpVtbl -> get_ActConnectionModemReportWaitTime(This,pVal)

#define IActAJ71QC24TEL2_put_ActConnectionModemReportWaitTime(This,newVal)	\
    (This)->lpVtbl -> put_ActConnectionModemReportWaitTime(This,newVal)

#define IActAJ71QC24TEL2_get_ActDisconnectionCDWaitTime(This,pVal)	\
    (This)->lpVtbl -> get_ActDisconnectionCDWaitTime(This,pVal)

#define IActAJ71QC24TEL2_put_ActDisconnectionCDWaitTime(This,newVal)	\
    (This)->lpVtbl -> put_ActDisconnectionCDWaitTime(This,newVal)

#define IActAJ71QC24TEL2_get_ActDisconnectionDelayTime(This,pVal)	\
    (This)->lpVtbl -> get_ActDisconnectionDelayTime(This,pVal)

#define IActAJ71QC24TEL2_put_ActDisconnectionDelayTime(This,newVal)	\
    (This)->lpVtbl -> put_ActDisconnectionDelayTime(This,newVal)

#define IActAJ71QC24TEL2_get_ActTransmissionDelayTime(This,pVal)	\
    (This)->lpVtbl -> get_ActTransmissionDelayTime(This,pVal)

#define IActAJ71QC24TEL2_put_ActTransmissionDelayTime(This,newVal)	\
    (This)->lpVtbl -> put_ActTransmissionDelayTime(This,newVal)

#define IActAJ71QC24TEL2_get_ActATCommandResponseWaitTime(This,pVal)	\
    (This)->lpVtbl -> get_ActATCommandResponseWaitTime(This,pVal)

#define IActAJ71QC24TEL2_put_ActATCommandResponseWaitTime(This,newVal)	\
    (This)->lpVtbl -> put_ActATCommandResponseWaitTime(This,newVal)

#define IActAJ71QC24TEL2_get_ActATCommandPasswordCancelRetryTimes(This,pVal)	\
    (This)->lpVtbl -> get_ActATCommandPasswordCancelRetryTimes(This,pVal)

#define IActAJ71QC24TEL2_put_ActATCommandPasswordCancelRetryTimes(This,newVal)	\
    (This)->lpVtbl -> put_ActATCommandPasswordCancelRetryTimes(This,newVal)

#define IActAJ71QC24TEL2_get_ActOutsideLineNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActOutsideLineNumber(This,pVal)

#define IActAJ71QC24TEL2_put_ActOutsideLineNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActOutsideLineNumber(This,newVal)

#define IActAJ71QC24TEL2_get_ActPasswordCancelResponseWaitTime(This,pVal)	\
    (This)->lpVtbl -> get_ActPasswordCancelResponseWaitTime(This,pVal)

#define IActAJ71QC24TEL2_put_ActPasswordCancelResponseWaitTime(This,newVal)	\
    (This)->lpVtbl -> put_ActPasswordCancelResponseWaitTime(This,newVal)


#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IActAJ71QC24TEL2_INTERFACE_DEFINED__ */


#ifndef __IActAJ71QC24TEL3_INTERFACE_DEFINED__
#define __IActAJ71QC24TEL3_INTERFACE_DEFINED__

/* interface IActAJ71QC24TEL3 */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IActAJ71QC24TEL3;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("8716603D-710B-11d5-9318-009099244EFD")
    IActAJ71QC24TEL3 : public IActAJ71QC24TEL2
    {
    public:
    };
    
#else 	/* C style interface */

    typedef struct IActAJ71QC24TEL3Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IActAJ71QC24TEL3 __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IActAJ71QC24TEL3 __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IActAJ71QC24TEL3 __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IActAJ71QC24TEL3 __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IActAJ71QC24TEL3 __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IActAJ71QC24TEL3 __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IActAJ71QC24TEL3 __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Open )( 
            IActAJ71QC24TEL3 __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Close )( 
            IActAJ71QC24TEL3 __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetDevice )( 
            IActAJ71QC24TEL3 __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [out] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetDevice )( 
            IActAJ71QC24TEL3 __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceBlock )( 
            IActAJ71QC24TEL3 __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lSize,
            /* [size_is][out] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceBlock )( 
            IActAJ71QC24TEL3 __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lSize,
            /* [size_is][in] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceRandom )( 
            IActAJ71QC24TEL3 __RPC_FAR * This,
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG lSize,
            /* [size_is][out] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceRandom )( 
            IActAJ71QC24TEL3 __RPC_FAR * This,
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG lSize,
            /* [size_is][in] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadBuffer )( 
            IActAJ71QC24TEL3 __RPC_FAR * This,
            /* [in] */ LONG lStartIO,
            /* [in] */ LONG lAddress,
            /* [in] */ LONG lReadSize,
            /* [size_is][out] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteBuffer )( 
            IActAJ71QC24TEL3 __RPC_FAR * This,
            /* [in] */ LONG lStartIO,
            /* [in] */ LONG lAddress,
            /* [in] */ LONG lWriteSize,
            /* [size_is][in] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetClockData )( 
            IActAJ71QC24TEL3 __RPC_FAR * This,
            /* [out] */ SHORT __RPC_FAR *lpsYear,
            /* [out] */ SHORT __RPC_FAR *lpsMonth,
            /* [out] */ SHORT __RPC_FAR *lpsDay,
            /* [out] */ SHORT __RPC_FAR *lpsDayOfWeek,
            /* [out] */ SHORT __RPC_FAR *lpsHour,
            /* [out] */ SHORT __RPC_FAR *lpsMinute,
            /* [out] */ SHORT __RPC_FAR *lpsSecond,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetClockData )( 
            IActAJ71QC24TEL3 __RPC_FAR * This,
            /* [in] */ SHORT sYear,
            /* [in] */ SHORT sMonth,
            /* [in] */ SHORT sDay,
            /* [in] */ SHORT sDayOfWeek,
            /* [in] */ SHORT sHour,
            /* [in] */ SHORT sMinute,
            /* [in] */ SHORT sSecond,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetCpuType )( 
            IActAJ71QC24TEL3 __RPC_FAR * This,
            /* [string][out] */ BSTR __RPC_FAR *szCpuName,
            /* [out] */ LONG __RPC_FAR *lplCpuCode,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetCpuStatus )( 
            IActAJ71QC24TEL3 __RPC_FAR * This,
            /* [in] */ LONG lOperation,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CheckDeviceString )( 
            IActAJ71QC24TEL3 __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lCheckType,
            /* [in] */ LONG lSize,
            /* [out] */ LONG __RPC_FAR *lplDeviceType,
            /* [string][out] */ BSTR __RPC_FAR *lpszDeviceName,
            /* [out] */ LONG __RPC_FAR *lplDeviceNumber,
            /* [out] */ LONG __RPC_FAR *lplDeviceRadix,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *EntryDeviceStatus )( 
            IActAJ71QC24TEL3 __RPC_FAR * This,
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG lSize,
            /* [in] */ LONG lMonitorCycle,
            /* [size_is][in] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *FreeDeviceStatus )( 
            IActAJ71QC24TEL3 __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceBlock2 )( 
            IActAJ71QC24TEL3 __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lSize,
            /* [size_is][out] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceBlock2 )( 
            IActAJ71QC24TEL3 __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lSize,
            /* [size_is][in] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceRandom2 )( 
            IActAJ71QC24TEL3 __RPC_FAR * This,
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG lSize,
            /* [size_is][out] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceRandom2 )( 
            IActAJ71QC24TEL3 __RPC_FAR * This,
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG lSize,
            /* [size_is][in] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetDevice2 )( 
            IActAJ71QC24TEL3 __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [out] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetDevice2 )( 
            IActAJ71QC24TEL3 __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ SHORT sData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Connect )( 
            IActAJ71QC24TEL3 __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Disconnect )( 
            IActAJ71QC24TEL3 __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActNetworkNumber )( 
            IActAJ71QC24TEL3 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActNetworkNumber )( 
            IActAJ71QC24TEL3 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActStationNumber )( 
            IActAJ71QC24TEL3 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActStationNumber )( 
            IActAJ71QC24TEL3 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActUnitNumber )( 
            IActAJ71QC24TEL3 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActUnitNumber )( 
            IActAJ71QC24TEL3 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActConnectUnitNumber )( 
            IActAJ71QC24TEL3 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActConnectUnitNumber )( 
            IActAJ71QC24TEL3 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActIONumber )( 
            IActAJ71QC24TEL3 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActIONumber )( 
            IActAJ71QC24TEL3 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActCpuType )( 
            IActAJ71QC24TEL3 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActCpuType )( 
            IActAJ71QC24TEL3 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActPortNumber )( 
            IActAJ71QC24TEL3 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActPortNumber )( 
            IActAJ71QC24TEL3 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActBaudRate )( 
            IActAJ71QC24TEL3 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActBaudRate )( 
            IActAJ71QC24TEL3 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActTimeOut )( 
            IActAJ71QC24TEL3 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActTimeOut )( 
            IActAJ71QC24TEL3 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActATCommand )( 
            IActAJ71QC24TEL3 __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActATCommand )( 
            IActAJ71QC24TEL3 __RPC_FAR * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActDialNumber )( 
            IActAJ71QC24TEL3 __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActDialNumber )( 
            IActAJ71QC24TEL3 __RPC_FAR * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActLineType )( 
            IActAJ71QC24TEL3 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActLineType )( 
            IActAJ71QC24TEL3 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActConnectionCDWaitTime )( 
            IActAJ71QC24TEL3 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActConnectionCDWaitTime )( 
            IActAJ71QC24TEL3 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActConnectionModemReportWaitTime )( 
            IActAJ71QC24TEL3 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActConnectionModemReportWaitTime )( 
            IActAJ71QC24TEL3 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActDisconnectionCDWaitTime )( 
            IActAJ71QC24TEL3 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActDisconnectionCDWaitTime )( 
            IActAJ71QC24TEL3 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActDisconnectionDelayTime )( 
            IActAJ71QC24TEL3 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActDisconnectionDelayTime )( 
            IActAJ71QC24TEL3 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActTransmissionDelayTime )( 
            IActAJ71QC24TEL3 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActTransmissionDelayTime )( 
            IActAJ71QC24TEL3 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActATCommandResponseWaitTime )( 
            IActAJ71QC24TEL3 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActATCommandResponseWaitTime )( 
            IActAJ71QC24TEL3 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActATCommandPasswordCancelRetryTimes )( 
            IActAJ71QC24TEL3 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActATCommandPasswordCancelRetryTimes )( 
            IActAJ71QC24TEL3 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActOutsideLineNumber )( 
            IActAJ71QC24TEL3 __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActOutsideLineNumber )( 
            IActAJ71QC24TEL3 __RPC_FAR * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActPasswordCancelResponseWaitTime )( 
            IActAJ71QC24TEL3 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActPasswordCancelResponseWaitTime )( 
            IActAJ71QC24TEL3 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        END_INTERFACE
    } IActAJ71QC24TEL3Vtbl;

    interface IActAJ71QC24TEL3
    {
        CONST_VTBL struct IActAJ71QC24TEL3Vtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IActAJ71QC24TEL3_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IActAJ71QC24TEL3_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IActAJ71QC24TEL3_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IActAJ71QC24TEL3_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IActAJ71QC24TEL3_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IActAJ71QC24TEL3_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IActAJ71QC24TEL3_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IActAJ71QC24TEL3_Open(This,lplReturnCode)	\
    (This)->lpVtbl -> Open(This,lplReturnCode)

#define IActAJ71QC24TEL3_Close(This,lplReturnCode)	\
    (This)->lpVtbl -> Close(This,lplReturnCode)

#define IActAJ71QC24TEL3_GetDevice(This,szDevice,lplData,lplReturnCode)	\
    (This)->lpVtbl -> GetDevice(This,szDevice,lplData,lplReturnCode)

#define IActAJ71QC24TEL3_SetDevice(This,szDevice,lData,lplReturnCode)	\
    (This)->lpVtbl -> SetDevice(This,szDevice,lData,lplReturnCode)

#define IActAJ71QC24TEL3_ReadDeviceBlock(This,szDevice,lSize,lplData,lplReturnCode)	\
    (This)->lpVtbl -> ReadDeviceBlock(This,szDevice,lSize,lplData,lplReturnCode)

#define IActAJ71QC24TEL3_WriteDeviceBlock(This,szDevice,lSize,lplData,lplReturnCode)	\
    (This)->lpVtbl -> WriteDeviceBlock(This,szDevice,lSize,lplData,lplReturnCode)

#define IActAJ71QC24TEL3_ReadDeviceRandom(This,szDeviceList,lSize,lplData,lplReturnCode)	\
    (This)->lpVtbl -> ReadDeviceRandom(This,szDeviceList,lSize,lplData,lplReturnCode)

#define IActAJ71QC24TEL3_WriteDeviceRandom(This,szDeviceList,lSize,lplData,lplReturnCode)	\
    (This)->lpVtbl -> WriteDeviceRandom(This,szDeviceList,lSize,lplData,lplReturnCode)

#define IActAJ71QC24TEL3_ReadBuffer(This,lStartIO,lAddress,lReadSize,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> ReadBuffer(This,lStartIO,lAddress,lReadSize,lpsData,lplReturnCode)

#define IActAJ71QC24TEL3_WriteBuffer(This,lStartIO,lAddress,lWriteSize,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> WriteBuffer(This,lStartIO,lAddress,lWriteSize,lpsData,lplReturnCode)

#define IActAJ71QC24TEL3_GetClockData(This,lpsYear,lpsMonth,lpsDay,lpsDayOfWeek,lpsHour,lpsMinute,lpsSecond,lplReturnCode)	\
    (This)->lpVtbl -> GetClockData(This,lpsYear,lpsMonth,lpsDay,lpsDayOfWeek,lpsHour,lpsMinute,lpsSecond,lplReturnCode)

#define IActAJ71QC24TEL3_SetClockData(This,sYear,sMonth,sDay,sDayOfWeek,sHour,sMinute,sSecond,lplReturnCode)	\
    (This)->lpVtbl -> SetClockData(This,sYear,sMonth,sDay,sDayOfWeek,sHour,sMinute,sSecond,lplReturnCode)

#define IActAJ71QC24TEL3_GetCpuType(This,szCpuName,lplCpuCode,lplReturnCode)	\
    (This)->lpVtbl -> GetCpuType(This,szCpuName,lplCpuCode,lplReturnCode)

#define IActAJ71QC24TEL3_SetCpuStatus(This,lOperation,lplReturnCode)	\
    (This)->lpVtbl -> SetCpuStatus(This,lOperation,lplReturnCode)

#define IActAJ71QC24TEL3_CheckDeviceString(This,szDevice,lCheckType,lSize,lplDeviceType,lpszDeviceName,lplDeviceNumber,lplDeviceRadix,lplReturnCode)	\
    (This)->lpVtbl -> CheckDeviceString(This,szDevice,lCheckType,lSize,lplDeviceType,lpszDeviceName,lplDeviceNumber,lplDeviceRadix,lplReturnCode)

#define IActAJ71QC24TEL3_EntryDeviceStatus(This,szDeviceList,lSize,lMonitorCycle,lplData,lplReturnCode)	\
    (This)->lpVtbl -> EntryDeviceStatus(This,szDeviceList,lSize,lMonitorCycle,lplData,lplReturnCode)

#define IActAJ71QC24TEL3_FreeDeviceStatus(This,lplReturnCode)	\
    (This)->lpVtbl -> FreeDeviceStatus(This,lplReturnCode)

#define IActAJ71QC24TEL3_ReadDeviceBlock2(This,szDevice,lSize,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> ReadDeviceBlock2(This,szDevice,lSize,lpsData,lplReturnCode)

#define IActAJ71QC24TEL3_WriteDeviceBlock2(This,szDevice,lSize,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> WriteDeviceBlock2(This,szDevice,lSize,lpsData,lplReturnCode)

#define IActAJ71QC24TEL3_ReadDeviceRandom2(This,szDeviceList,lSize,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> ReadDeviceRandom2(This,szDeviceList,lSize,lpsData,lplReturnCode)

#define IActAJ71QC24TEL3_WriteDeviceRandom2(This,szDeviceList,lSize,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> WriteDeviceRandom2(This,szDeviceList,lSize,lpsData,lplReturnCode)

#define IActAJ71QC24TEL3_GetDevice2(This,szDevice,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> GetDevice2(This,szDevice,lpsData,lplReturnCode)

#define IActAJ71QC24TEL3_SetDevice2(This,szDevice,sData,lplReturnCode)	\
    (This)->lpVtbl -> SetDevice2(This,szDevice,sData,lplReturnCode)

#define IActAJ71QC24TEL3_Connect(This,lplReturnCode)	\
    (This)->lpVtbl -> Connect(This,lplReturnCode)

#define IActAJ71QC24TEL3_Disconnect(This,lplReturnCode)	\
    (This)->lpVtbl -> Disconnect(This,lplReturnCode)

#define IActAJ71QC24TEL3_get_ActNetworkNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActNetworkNumber(This,pVal)

#define IActAJ71QC24TEL3_put_ActNetworkNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActNetworkNumber(This,newVal)

#define IActAJ71QC24TEL3_get_ActStationNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActStationNumber(This,pVal)

#define IActAJ71QC24TEL3_put_ActStationNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActStationNumber(This,newVal)

#define IActAJ71QC24TEL3_get_ActUnitNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActUnitNumber(This,pVal)

#define IActAJ71QC24TEL3_put_ActUnitNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActUnitNumber(This,newVal)

#define IActAJ71QC24TEL3_get_ActConnectUnitNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActConnectUnitNumber(This,pVal)

#define IActAJ71QC24TEL3_put_ActConnectUnitNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActConnectUnitNumber(This,newVal)

#define IActAJ71QC24TEL3_get_ActIONumber(This,pVal)	\
    (This)->lpVtbl -> get_ActIONumber(This,pVal)

#define IActAJ71QC24TEL3_put_ActIONumber(This,newVal)	\
    (This)->lpVtbl -> put_ActIONumber(This,newVal)

#define IActAJ71QC24TEL3_get_ActCpuType(This,pVal)	\
    (This)->lpVtbl -> get_ActCpuType(This,pVal)

#define IActAJ71QC24TEL3_put_ActCpuType(This,newVal)	\
    (This)->lpVtbl -> put_ActCpuType(This,newVal)

#define IActAJ71QC24TEL3_get_ActPortNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActPortNumber(This,pVal)

#define IActAJ71QC24TEL3_put_ActPortNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActPortNumber(This,newVal)

#define IActAJ71QC24TEL3_get_ActBaudRate(This,pVal)	\
    (This)->lpVtbl -> get_ActBaudRate(This,pVal)

#define IActAJ71QC24TEL3_put_ActBaudRate(This,newVal)	\
    (This)->lpVtbl -> put_ActBaudRate(This,newVal)

#define IActAJ71QC24TEL3_get_ActTimeOut(This,pVal)	\
    (This)->lpVtbl -> get_ActTimeOut(This,pVal)

#define IActAJ71QC24TEL3_put_ActTimeOut(This,newVal)	\
    (This)->lpVtbl -> put_ActTimeOut(This,newVal)

#define IActAJ71QC24TEL3_get_ActATCommand(This,pVal)	\
    (This)->lpVtbl -> get_ActATCommand(This,pVal)

#define IActAJ71QC24TEL3_put_ActATCommand(This,newVal)	\
    (This)->lpVtbl -> put_ActATCommand(This,newVal)

#define IActAJ71QC24TEL3_get_ActDialNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActDialNumber(This,pVal)

#define IActAJ71QC24TEL3_put_ActDialNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActDialNumber(This,newVal)

#define IActAJ71QC24TEL3_get_ActLineType(This,pVal)	\
    (This)->lpVtbl -> get_ActLineType(This,pVal)

#define IActAJ71QC24TEL3_put_ActLineType(This,newVal)	\
    (This)->lpVtbl -> put_ActLineType(This,newVal)

#define IActAJ71QC24TEL3_get_ActConnectionCDWaitTime(This,pVal)	\
    (This)->lpVtbl -> get_ActConnectionCDWaitTime(This,pVal)

#define IActAJ71QC24TEL3_put_ActConnectionCDWaitTime(This,newVal)	\
    (This)->lpVtbl -> put_ActConnectionCDWaitTime(This,newVal)

#define IActAJ71QC24TEL3_get_ActConnectionModemReportWaitTime(This,pVal)	\
    (This)->lpVtbl -> get_ActConnectionModemReportWaitTime(This,pVal)

#define IActAJ71QC24TEL3_put_ActConnectionModemReportWaitTime(This,newVal)	\
    (This)->lpVtbl -> put_ActConnectionModemReportWaitTime(This,newVal)

#define IActAJ71QC24TEL3_get_ActDisconnectionCDWaitTime(This,pVal)	\
    (This)->lpVtbl -> get_ActDisconnectionCDWaitTime(This,pVal)

#define IActAJ71QC24TEL3_put_ActDisconnectionCDWaitTime(This,newVal)	\
    (This)->lpVtbl -> put_ActDisconnectionCDWaitTime(This,newVal)

#define IActAJ71QC24TEL3_get_ActDisconnectionDelayTime(This,pVal)	\
    (This)->lpVtbl -> get_ActDisconnectionDelayTime(This,pVal)

#define IActAJ71QC24TEL3_put_ActDisconnectionDelayTime(This,newVal)	\
    (This)->lpVtbl -> put_ActDisconnectionDelayTime(This,newVal)

#define IActAJ71QC24TEL3_get_ActTransmissionDelayTime(This,pVal)	\
    (This)->lpVtbl -> get_ActTransmissionDelayTime(This,pVal)

#define IActAJ71QC24TEL3_put_ActTransmissionDelayTime(This,newVal)	\
    (This)->lpVtbl -> put_ActTransmissionDelayTime(This,newVal)

#define IActAJ71QC24TEL3_get_ActATCommandResponseWaitTime(This,pVal)	\
    (This)->lpVtbl -> get_ActATCommandResponseWaitTime(This,pVal)

#define IActAJ71QC24TEL3_put_ActATCommandResponseWaitTime(This,newVal)	\
    (This)->lpVtbl -> put_ActATCommandResponseWaitTime(This,newVal)

#define IActAJ71QC24TEL3_get_ActATCommandPasswordCancelRetryTimes(This,pVal)	\
    (This)->lpVtbl -> get_ActATCommandPasswordCancelRetryTimes(This,pVal)

#define IActAJ71QC24TEL3_put_ActATCommandPasswordCancelRetryTimes(This,newVal)	\
    (This)->lpVtbl -> put_ActATCommandPasswordCancelRetryTimes(This,newVal)

#define IActAJ71QC24TEL3_get_ActOutsideLineNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActOutsideLineNumber(This,pVal)

#define IActAJ71QC24TEL3_put_ActOutsideLineNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActOutsideLineNumber(This,newVal)

#define IActAJ71QC24TEL3_get_ActPasswordCancelResponseWaitTime(This,pVal)	\
    (This)->lpVtbl -> get_ActPasswordCancelResponseWaitTime(This,pVal)

#define IActAJ71QC24TEL3_put_ActPasswordCancelResponseWaitTime(This,newVal)	\
    (This)->lpVtbl -> put_ActPasswordCancelResponseWaitTime(This,newVal)



#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IActAJ71QC24TEL3_INTERFACE_DEFINED__ */


#ifndef __IActQJ71C24TEL_INTERFACE_DEFINED__
#define __IActQJ71C24TEL_INTERFACE_DEFINED__

/* interface IActQJ71C24TEL */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IActQJ71C24TEL;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("5713F07E-6F4A-11D5-9315-009099244EFD")
    IActQJ71C24TEL : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Open( 
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Close( 
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetDevice( 
            /* [string][in] */ BSTR szDevice,
            /* [out] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetDevice( 
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ReadDeviceBlock( 
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lSize,
            /* [size_is][out] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE WriteDeviceBlock( 
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lSize,
            /* [size_is][in] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ReadDeviceRandom( 
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG lSize,
            /* [size_is][out] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE WriteDeviceRandom( 
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG lSize,
            /* [size_is][in] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ReadBuffer( 
            /* [in] */ LONG lStartIO,
            /* [in] */ LONG lAddress,
            /* [in] */ LONG lReadSize,
            /* [size_is][out] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE WriteBuffer( 
            /* [in] */ LONG lStartIO,
            /* [in] */ LONG lAddress,
            /* [in] */ LONG lWriteSize,
            /* [size_is][in] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetClockData( 
            /* [out] */ SHORT __RPC_FAR *lpsYear,
            /* [out] */ SHORT __RPC_FAR *lpsMonth,
            /* [out] */ SHORT __RPC_FAR *lpsDay,
            /* [out] */ SHORT __RPC_FAR *lpsDayOfWeek,
            /* [out] */ SHORT __RPC_FAR *lpsHour,
            /* [out] */ SHORT __RPC_FAR *lpsMinute,
            /* [out] */ SHORT __RPC_FAR *lpsSecond,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetClockData( 
            /* [in] */ SHORT sYear,
            /* [in] */ SHORT sMonth,
            /* [in] */ SHORT sDay,
            /* [in] */ SHORT sDayOfWeek,
            /* [in] */ SHORT sHour,
            /* [in] */ SHORT sMinute,
            /* [in] */ SHORT sSecond,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetCpuType( 
            /* [string][out] */ BSTR __RPC_FAR *szCpuName,
            /* [out] */ LONG __RPC_FAR *lplCpuCode,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetCpuStatus( 
            /* [in] */ LONG lOperation,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE CheckDeviceString( 
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lCheckType,
            /* [in] */ LONG lSize,
            /* [out] */ LONG __RPC_FAR *lplDeviceType,
            /* [string][out] */ BSTR __RPC_FAR *lpszDeviceName,
            /* [out] */ LONG __RPC_FAR *lplDeviceNumber,
            /* [out] */ LONG __RPC_FAR *lplDeviceRadix,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE EntryDeviceStatus( 
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG lSize,
            /* [in] */ LONG lMonitorCycle,
            /* [size_is][in] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE FreeDeviceStatus( 
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ReadDeviceBlock2( 
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lSize,
            /* [size_is][out] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE WriteDeviceBlock2( 
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lSize,
            /* [size_is][in] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ReadDeviceRandom2( 
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG lSize,
            /* [size_is][out] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE WriteDeviceRandom2( 
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG lSize,
            /* [size_is][in] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetDevice2( 
            /* [string][in] */ BSTR szDevice,
            /* [out] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetDevice2( 
            /* [string][in] */ BSTR szDevice,
            /* [in] */ SHORT sData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Connect( 
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Disconnect( 
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActNetworkNumber( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActNetworkNumber( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActStationNumber( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActStationNumber( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActUnitNumber( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActUnitNumber( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActConnectUnitNumber( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActConnectUnitNumber( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActIONumber( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActIONumber( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActCpuType( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActCpuType( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActPortNumber( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActPortNumber( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActBaudRate( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActBaudRate( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActTimeOut( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActTimeOut( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActDestinationIONumber( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActDestinationIONumber( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActMultiDropChannelNumber( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActMultiDropChannelNumber( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActThroughNetworkType( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActThroughNetworkType( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActIntelligentPreferenceBit( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActIntelligentPreferenceBit( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActDidPropertyBit( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActDidPropertyBit( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActDsidPropertyBit( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActDsidPropertyBit( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActATCommand( 
            /* [retval][out] */ BSTR __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActATCommand( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActDialNumber( 
            /* [retval][out] */ BSTR __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActDialNumber( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActCallbackNumber( 
            /* [retval][out] */ BSTR __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActCallbackNumber( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActLineType( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActLineType( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActPassword( 
            /* [retval][out] */ BSTR __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActPassword( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActConnectionCDWaitTime( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActConnectionCDWaitTime( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActConnectionModemReportWaitTime( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActConnectionModemReportWaitTime( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActDisconnectionCDWaitTime( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActDisconnectionCDWaitTime( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActDisconnectionDelayTime( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActDisconnectionDelayTime( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActTransmissionDelayTime( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActTransmissionDelayTime( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActATCommandResponseWaitTime( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActATCommandResponseWaitTime( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActATCommandPasswordCancelRetryTimes( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActATCommandPasswordCancelRetryTimes( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActCallbackCancelWaitTime( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActCallbackCancelWaitTime( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActCallbackDelayTime( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActCallbackDelayTime( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActConnectWay( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActConnectWay( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActOutsideLineNumber( 
            /* [retval][out] */ BSTR __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActOutsideLineNumber( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActPasswordCancelResponseWaitTime( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActPasswordCancelResponseWaitTime( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActCallbackReceptionWaitingTimeOut( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActCallbackReceptionWaitingTimeOut( 
            /* [in] */ long newVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IActQJ71C24TELVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IActQJ71C24TEL __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IActQJ71C24TEL __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IActQJ71C24TEL __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IActQJ71C24TEL __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IActQJ71C24TEL __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IActQJ71C24TEL __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IActQJ71C24TEL __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Open )( 
            IActQJ71C24TEL __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Close )( 
            IActQJ71C24TEL __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetDevice )( 
            IActQJ71C24TEL __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [out] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetDevice )( 
            IActQJ71C24TEL __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceBlock )( 
            IActQJ71C24TEL __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lSize,
            /* [size_is][out] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceBlock )( 
            IActQJ71C24TEL __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lSize,
            /* [size_is][in] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceRandom )( 
            IActQJ71C24TEL __RPC_FAR * This,
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG lSize,
            /* [size_is][out] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceRandom )( 
            IActQJ71C24TEL __RPC_FAR * This,
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG lSize,
            /* [size_is][in] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadBuffer )( 
            IActQJ71C24TEL __RPC_FAR * This,
            /* [in] */ LONG lStartIO,
            /* [in] */ LONG lAddress,
            /* [in] */ LONG lReadSize,
            /* [size_is][out] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteBuffer )( 
            IActQJ71C24TEL __RPC_FAR * This,
            /* [in] */ LONG lStartIO,
            /* [in] */ LONG lAddress,
            /* [in] */ LONG lWriteSize,
            /* [size_is][in] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetClockData )( 
            IActQJ71C24TEL __RPC_FAR * This,
            /* [out] */ SHORT __RPC_FAR *lpsYear,
            /* [out] */ SHORT __RPC_FAR *lpsMonth,
            /* [out] */ SHORT __RPC_FAR *lpsDay,
            /* [out] */ SHORT __RPC_FAR *lpsDayOfWeek,
            /* [out] */ SHORT __RPC_FAR *lpsHour,
            /* [out] */ SHORT __RPC_FAR *lpsMinute,
            /* [out] */ SHORT __RPC_FAR *lpsSecond,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetClockData )( 
            IActQJ71C24TEL __RPC_FAR * This,
            /* [in] */ SHORT sYear,
            /* [in] */ SHORT sMonth,
            /* [in] */ SHORT sDay,
            /* [in] */ SHORT sDayOfWeek,
            /* [in] */ SHORT sHour,
            /* [in] */ SHORT sMinute,
            /* [in] */ SHORT sSecond,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetCpuType )( 
            IActQJ71C24TEL __RPC_FAR * This,
            /* [string][out] */ BSTR __RPC_FAR *szCpuName,
            /* [out] */ LONG __RPC_FAR *lplCpuCode,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetCpuStatus )( 
            IActQJ71C24TEL __RPC_FAR * This,
            /* [in] */ LONG lOperation,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CheckDeviceString )( 
            IActQJ71C24TEL __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lCheckType,
            /* [in] */ LONG lSize,
            /* [out] */ LONG __RPC_FAR *lplDeviceType,
            /* [string][out] */ BSTR __RPC_FAR *lpszDeviceName,
            /* [out] */ LONG __RPC_FAR *lplDeviceNumber,
            /* [out] */ LONG __RPC_FAR *lplDeviceRadix,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *EntryDeviceStatus )( 
            IActQJ71C24TEL __RPC_FAR * This,
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG lSize,
            /* [in] */ LONG lMonitorCycle,
            /* [size_is][in] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *FreeDeviceStatus )( 
            IActQJ71C24TEL __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceBlock2 )( 
            IActQJ71C24TEL __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lSize,
            /* [size_is][out] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceBlock2 )( 
            IActQJ71C24TEL __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lSize,
            /* [size_is][in] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceRandom2 )( 
            IActQJ71C24TEL __RPC_FAR * This,
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG lSize,
            /* [size_is][out] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceRandom2 )( 
            IActQJ71C24TEL __RPC_FAR * This,
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG lSize,
            /* [size_is][in] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetDevice2 )( 
            IActQJ71C24TEL __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [out] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetDevice2 )( 
            IActQJ71C24TEL __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ SHORT sData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Connect )( 
            IActQJ71C24TEL __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Disconnect )( 
            IActQJ71C24TEL __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActNetworkNumber )( 
            IActQJ71C24TEL __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActNetworkNumber )( 
            IActQJ71C24TEL __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActStationNumber )( 
            IActQJ71C24TEL __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActStationNumber )( 
            IActQJ71C24TEL __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActUnitNumber )( 
            IActQJ71C24TEL __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActUnitNumber )( 
            IActQJ71C24TEL __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActConnectUnitNumber )( 
            IActQJ71C24TEL __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActConnectUnitNumber )( 
            IActQJ71C24TEL __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActIONumber )( 
            IActQJ71C24TEL __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActIONumber )( 
            IActQJ71C24TEL __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActCpuType )( 
            IActQJ71C24TEL __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActCpuType )( 
            IActQJ71C24TEL __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActPortNumber )( 
            IActQJ71C24TEL __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActPortNumber )( 
            IActQJ71C24TEL __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActBaudRate )( 
            IActQJ71C24TEL __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActBaudRate )( 
            IActQJ71C24TEL __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActTimeOut )( 
            IActQJ71C24TEL __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActTimeOut )( 
            IActQJ71C24TEL __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActDestinationIONumber )( 
            IActQJ71C24TEL __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActDestinationIONumber )( 
            IActQJ71C24TEL __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActMultiDropChannelNumber )( 
            IActQJ71C24TEL __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActMultiDropChannelNumber )( 
            IActQJ71C24TEL __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActThroughNetworkType )( 
            IActQJ71C24TEL __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActThroughNetworkType )( 
            IActQJ71C24TEL __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActIntelligentPreferenceBit )( 
            IActQJ71C24TEL __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActIntelligentPreferenceBit )( 
            IActQJ71C24TEL __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActDidPropertyBit )( 
            IActQJ71C24TEL __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActDidPropertyBit )( 
            IActQJ71C24TEL __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActDsidPropertyBit )( 
            IActQJ71C24TEL __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActDsidPropertyBit )( 
            IActQJ71C24TEL __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActATCommand )( 
            IActQJ71C24TEL __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActATCommand )( 
            IActQJ71C24TEL __RPC_FAR * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActDialNumber )( 
            IActQJ71C24TEL __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActDialNumber )( 
            IActQJ71C24TEL __RPC_FAR * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActCallbackNumber )( 
            IActQJ71C24TEL __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActCallbackNumber )( 
            IActQJ71C24TEL __RPC_FAR * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActLineType )( 
            IActQJ71C24TEL __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActLineType )( 
            IActQJ71C24TEL __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActPassword )( 
            IActQJ71C24TEL __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActPassword )( 
            IActQJ71C24TEL __RPC_FAR * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActConnectionCDWaitTime )( 
            IActQJ71C24TEL __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActConnectionCDWaitTime )( 
            IActQJ71C24TEL __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActConnectionModemReportWaitTime )( 
            IActQJ71C24TEL __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActConnectionModemReportWaitTime )( 
            IActQJ71C24TEL __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActDisconnectionCDWaitTime )( 
            IActQJ71C24TEL __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActDisconnectionCDWaitTime )( 
            IActQJ71C24TEL __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActDisconnectionDelayTime )( 
            IActQJ71C24TEL __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActDisconnectionDelayTime )( 
            IActQJ71C24TEL __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActTransmissionDelayTime )( 
            IActQJ71C24TEL __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActTransmissionDelayTime )( 
            IActQJ71C24TEL __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActATCommandResponseWaitTime )( 
            IActQJ71C24TEL __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActATCommandResponseWaitTime )( 
            IActQJ71C24TEL __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActATCommandPasswordCancelRetryTimes )( 
            IActQJ71C24TEL __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActATCommandPasswordCancelRetryTimes )( 
            IActQJ71C24TEL __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActCallbackCancelWaitTime )( 
            IActQJ71C24TEL __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActCallbackCancelWaitTime )( 
            IActQJ71C24TEL __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActCallbackDelayTime )( 
            IActQJ71C24TEL __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActCallbackDelayTime )( 
            IActQJ71C24TEL __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActConnectWay )( 
            IActQJ71C24TEL __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActConnectWay )( 
            IActQJ71C24TEL __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActOutsideLineNumber )( 
            IActQJ71C24TEL __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActOutsideLineNumber )( 
            IActQJ71C24TEL __RPC_FAR * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActPasswordCancelResponseWaitTime )( 
            IActQJ71C24TEL __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActPasswordCancelResponseWaitTime )( 
            IActQJ71C24TEL __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActCallbackReceptionWaitingTimeOut )( 
            IActQJ71C24TEL __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActCallbackReceptionWaitingTimeOut )( 
            IActQJ71C24TEL __RPC_FAR * This,
            /* [in] */ long newVal);
        
        END_INTERFACE
    } IActQJ71C24TELVtbl;

    interface IActQJ71C24TEL
    {
        CONST_VTBL struct IActQJ71C24TELVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IActQJ71C24TEL_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IActQJ71C24TEL_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IActQJ71C24TEL_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IActQJ71C24TEL_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IActQJ71C24TEL_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IActQJ71C24TEL_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IActQJ71C24TEL_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IActQJ71C24TEL_Open(This,lplReturnCode)	\
    (This)->lpVtbl -> Open(This,lplReturnCode)

#define IActQJ71C24TEL_Close(This,lplReturnCode)	\
    (This)->lpVtbl -> Close(This,lplReturnCode)

#define IActQJ71C24TEL_GetDevice(This,szDevice,lplData,lplReturnCode)	\
    (This)->lpVtbl -> GetDevice(This,szDevice,lplData,lplReturnCode)

#define IActQJ71C24TEL_SetDevice(This,szDevice,lData,lplReturnCode)	\
    (This)->lpVtbl -> SetDevice(This,szDevice,lData,lplReturnCode)

#define IActQJ71C24TEL_ReadDeviceBlock(This,szDevice,lSize,lplData,lplReturnCode)	\
    (This)->lpVtbl -> ReadDeviceBlock(This,szDevice,lSize,lplData,lplReturnCode)

#define IActQJ71C24TEL_WriteDeviceBlock(This,szDevice,lSize,lplData,lplReturnCode)	\
    (This)->lpVtbl -> WriteDeviceBlock(This,szDevice,lSize,lplData,lplReturnCode)

#define IActQJ71C24TEL_ReadDeviceRandom(This,szDeviceList,lSize,lplData,lplReturnCode)	\
    (This)->lpVtbl -> ReadDeviceRandom(This,szDeviceList,lSize,lplData,lplReturnCode)

#define IActQJ71C24TEL_WriteDeviceRandom(This,szDeviceList,lSize,lplData,lplReturnCode)	\
    (This)->lpVtbl -> WriteDeviceRandom(This,szDeviceList,lSize,lplData,lplReturnCode)

#define IActQJ71C24TEL_ReadBuffer(This,lStartIO,lAddress,lReadSize,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> ReadBuffer(This,lStartIO,lAddress,lReadSize,lpsData,lplReturnCode)

#define IActQJ71C24TEL_WriteBuffer(This,lStartIO,lAddress,lWriteSize,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> WriteBuffer(This,lStartIO,lAddress,lWriteSize,lpsData,lplReturnCode)

#define IActQJ71C24TEL_GetClockData(This,lpsYear,lpsMonth,lpsDay,lpsDayOfWeek,lpsHour,lpsMinute,lpsSecond,lplReturnCode)	\
    (This)->lpVtbl -> GetClockData(This,lpsYear,lpsMonth,lpsDay,lpsDayOfWeek,lpsHour,lpsMinute,lpsSecond,lplReturnCode)

#define IActQJ71C24TEL_SetClockData(This,sYear,sMonth,sDay,sDayOfWeek,sHour,sMinute,sSecond,lplReturnCode)	\
    (This)->lpVtbl -> SetClockData(This,sYear,sMonth,sDay,sDayOfWeek,sHour,sMinute,sSecond,lplReturnCode)

#define IActQJ71C24TEL_GetCpuType(This,szCpuName,lplCpuCode,lplReturnCode)	\
    (This)->lpVtbl -> GetCpuType(This,szCpuName,lplCpuCode,lplReturnCode)

#define IActQJ71C24TEL_SetCpuStatus(This,lOperation,lplReturnCode)	\
    (This)->lpVtbl -> SetCpuStatus(This,lOperation,lplReturnCode)

#define IActQJ71C24TEL_CheckDeviceString(This,szDevice,lCheckType,lSize,lplDeviceType,lpszDeviceName,lplDeviceNumber,lplDeviceRadix,lplReturnCode)	\
    (This)->lpVtbl -> CheckDeviceString(This,szDevice,lCheckType,lSize,lplDeviceType,lpszDeviceName,lplDeviceNumber,lplDeviceRadix,lplReturnCode)

#define IActQJ71C24TEL_EntryDeviceStatus(This,szDeviceList,lSize,lMonitorCycle,lplData,lplReturnCode)	\
    (This)->lpVtbl -> EntryDeviceStatus(This,szDeviceList,lSize,lMonitorCycle,lplData,lplReturnCode)

#define IActQJ71C24TEL_FreeDeviceStatus(This,lplReturnCode)	\
    (This)->lpVtbl -> FreeDeviceStatus(This,lplReturnCode)

#define IActQJ71C24TEL_ReadDeviceBlock2(This,szDevice,lSize,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> ReadDeviceBlock2(This,szDevice,lSize,lpsData,lplReturnCode)

#define IActQJ71C24TEL_WriteDeviceBlock2(This,szDevice,lSize,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> WriteDeviceBlock2(This,szDevice,lSize,lpsData,lplReturnCode)

#define IActQJ71C24TEL_ReadDeviceRandom2(This,szDeviceList,lSize,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> ReadDeviceRandom2(This,szDeviceList,lSize,lpsData,lplReturnCode)

#define IActQJ71C24TEL_WriteDeviceRandom2(This,szDeviceList,lSize,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> WriteDeviceRandom2(This,szDeviceList,lSize,lpsData,lplReturnCode)

#define IActQJ71C24TEL_GetDevice2(This,szDevice,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> GetDevice2(This,szDevice,lpsData,lplReturnCode)

#define IActQJ71C24TEL_SetDevice2(This,szDevice,sData,lplReturnCode)	\
    (This)->lpVtbl -> SetDevice2(This,szDevice,sData,lplReturnCode)

#define IActQJ71C24TEL_Connect(This,lplReturnCode)	\
    (This)->lpVtbl -> Connect(This,lplReturnCode)

#define IActQJ71C24TEL_Disconnect(This,lplReturnCode)	\
    (This)->lpVtbl -> Disconnect(This,lplReturnCode)

#define IActQJ71C24TEL_get_ActNetworkNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActNetworkNumber(This,pVal)

#define IActQJ71C24TEL_put_ActNetworkNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActNetworkNumber(This,newVal)

#define IActQJ71C24TEL_get_ActStationNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActStationNumber(This,pVal)

#define IActQJ71C24TEL_put_ActStationNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActStationNumber(This,newVal)

#define IActQJ71C24TEL_get_ActUnitNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActUnitNumber(This,pVal)

#define IActQJ71C24TEL_put_ActUnitNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActUnitNumber(This,newVal)

#define IActQJ71C24TEL_get_ActConnectUnitNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActConnectUnitNumber(This,pVal)

#define IActQJ71C24TEL_put_ActConnectUnitNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActConnectUnitNumber(This,newVal)

#define IActQJ71C24TEL_get_ActIONumber(This,pVal)	\
    (This)->lpVtbl -> get_ActIONumber(This,pVal)

#define IActQJ71C24TEL_put_ActIONumber(This,newVal)	\
    (This)->lpVtbl -> put_ActIONumber(This,newVal)

#define IActQJ71C24TEL_get_ActCpuType(This,pVal)	\
    (This)->lpVtbl -> get_ActCpuType(This,pVal)

#define IActQJ71C24TEL_put_ActCpuType(This,newVal)	\
    (This)->lpVtbl -> put_ActCpuType(This,newVal)

#define IActQJ71C24TEL_get_ActPortNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActPortNumber(This,pVal)

#define IActQJ71C24TEL_put_ActPortNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActPortNumber(This,newVal)

#define IActQJ71C24TEL_get_ActBaudRate(This,pVal)	\
    (This)->lpVtbl -> get_ActBaudRate(This,pVal)

#define IActQJ71C24TEL_put_ActBaudRate(This,newVal)	\
    (This)->lpVtbl -> put_ActBaudRate(This,newVal)

#define IActQJ71C24TEL_get_ActTimeOut(This,pVal)	\
    (This)->lpVtbl -> get_ActTimeOut(This,pVal)

#define IActQJ71C24TEL_put_ActTimeOut(This,newVal)	\
    (This)->lpVtbl -> put_ActTimeOut(This,newVal)

#define IActQJ71C24TEL_get_ActDestinationIONumber(This,pVal)	\
    (This)->lpVtbl -> get_ActDestinationIONumber(This,pVal)

#define IActQJ71C24TEL_put_ActDestinationIONumber(This,newVal)	\
    (This)->lpVtbl -> put_ActDestinationIONumber(This,newVal)

#define IActQJ71C24TEL_get_ActMultiDropChannelNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActMultiDropChannelNumber(This,pVal)

#define IActQJ71C24TEL_put_ActMultiDropChannelNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActMultiDropChannelNumber(This,newVal)

#define IActQJ71C24TEL_get_ActThroughNetworkType(This,pVal)	\
    (This)->lpVtbl -> get_ActThroughNetworkType(This,pVal)

#define IActQJ71C24TEL_put_ActThroughNetworkType(This,newVal)	\
    (This)->lpVtbl -> put_ActThroughNetworkType(This,newVal)

#define IActQJ71C24TEL_get_ActIntelligentPreferenceBit(This,pVal)	\
    (This)->lpVtbl -> get_ActIntelligentPreferenceBit(This,pVal)

#define IActQJ71C24TEL_put_ActIntelligentPreferenceBit(This,newVal)	\
    (This)->lpVtbl -> put_ActIntelligentPreferenceBit(This,newVal)

#define IActQJ71C24TEL_get_ActDidPropertyBit(This,pVal)	\
    (This)->lpVtbl -> get_ActDidPropertyBit(This,pVal)

#define IActQJ71C24TEL_put_ActDidPropertyBit(This,newVal)	\
    (This)->lpVtbl -> put_ActDidPropertyBit(This,newVal)

#define IActQJ71C24TEL_get_ActDsidPropertyBit(This,pVal)	\
    (This)->lpVtbl -> get_ActDsidPropertyBit(This,pVal)

#define IActQJ71C24TEL_put_ActDsidPropertyBit(This,newVal)	\
    (This)->lpVtbl -> put_ActDsidPropertyBit(This,newVal)

#define IActQJ71C24TEL_get_ActATCommand(This,pVal)	\
    (This)->lpVtbl -> get_ActATCommand(This,pVal)

#define IActQJ71C24TEL_put_ActATCommand(This,newVal)	\
    (This)->lpVtbl -> put_ActATCommand(This,newVal)

#define IActQJ71C24TEL_get_ActDialNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActDialNumber(This,pVal)

#define IActQJ71C24TEL_put_ActDialNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActDialNumber(This,newVal)

#define IActQJ71C24TEL_get_ActCallbackNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActCallbackNumber(This,pVal)

#define IActQJ71C24TEL_put_ActCallbackNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActCallbackNumber(This,newVal)

#define IActQJ71C24TEL_get_ActLineType(This,pVal)	\
    (This)->lpVtbl -> get_ActLineType(This,pVal)

#define IActQJ71C24TEL_put_ActLineType(This,newVal)	\
    (This)->lpVtbl -> put_ActLineType(This,newVal)

#define IActQJ71C24TEL_get_ActPassword(This,pVal)	\
    (This)->lpVtbl -> get_ActPassword(This,pVal)

#define IActQJ71C24TEL_put_ActPassword(This,newVal)	\
    (This)->lpVtbl -> put_ActPassword(This,newVal)

#define IActQJ71C24TEL_get_ActConnectionCDWaitTime(This,pVal)	\
    (This)->lpVtbl -> get_ActConnectionCDWaitTime(This,pVal)

#define IActQJ71C24TEL_put_ActConnectionCDWaitTime(This,newVal)	\
    (This)->lpVtbl -> put_ActConnectionCDWaitTime(This,newVal)

#define IActQJ71C24TEL_get_ActConnectionModemReportWaitTime(This,pVal)	\
    (This)->lpVtbl -> get_ActConnectionModemReportWaitTime(This,pVal)

#define IActQJ71C24TEL_put_ActConnectionModemReportWaitTime(This,newVal)	\
    (This)->lpVtbl -> put_ActConnectionModemReportWaitTime(This,newVal)

#define IActQJ71C24TEL_get_ActDisconnectionCDWaitTime(This,pVal)	\
    (This)->lpVtbl -> get_ActDisconnectionCDWaitTime(This,pVal)

#define IActQJ71C24TEL_put_ActDisconnectionCDWaitTime(This,newVal)	\
    (This)->lpVtbl -> put_ActDisconnectionCDWaitTime(This,newVal)

#define IActQJ71C24TEL_get_ActDisconnectionDelayTime(This,pVal)	\
    (This)->lpVtbl -> get_ActDisconnectionDelayTime(This,pVal)

#define IActQJ71C24TEL_put_ActDisconnectionDelayTime(This,newVal)	\
    (This)->lpVtbl -> put_ActDisconnectionDelayTime(This,newVal)

#define IActQJ71C24TEL_get_ActTransmissionDelayTime(This,pVal)	\
    (This)->lpVtbl -> get_ActTransmissionDelayTime(This,pVal)

#define IActQJ71C24TEL_put_ActTransmissionDelayTime(This,newVal)	\
    (This)->lpVtbl -> put_ActTransmissionDelayTime(This,newVal)

#define IActQJ71C24TEL_get_ActATCommandResponseWaitTime(This,pVal)	\
    (This)->lpVtbl -> get_ActATCommandResponseWaitTime(This,pVal)

#define IActQJ71C24TEL_put_ActATCommandResponseWaitTime(This,newVal)	\
    (This)->lpVtbl -> put_ActATCommandResponseWaitTime(This,newVal)

#define IActQJ71C24TEL_get_ActATCommandPasswordCancelRetryTimes(This,pVal)	\
    (This)->lpVtbl -> get_ActATCommandPasswordCancelRetryTimes(This,pVal)

#define IActQJ71C24TEL_put_ActATCommandPasswordCancelRetryTimes(This,newVal)	\
    (This)->lpVtbl -> put_ActATCommandPasswordCancelRetryTimes(This,newVal)

#define IActQJ71C24TEL_get_ActCallbackCancelWaitTime(This,pVal)	\
    (This)->lpVtbl -> get_ActCallbackCancelWaitTime(This,pVal)

#define IActQJ71C24TEL_put_ActCallbackCancelWaitTime(This,newVal)	\
    (This)->lpVtbl -> put_ActCallbackCancelWaitTime(This,newVal)

#define IActQJ71C24TEL_get_ActCallbackDelayTime(This,pVal)	\
    (This)->lpVtbl -> get_ActCallbackDelayTime(This,pVal)

#define IActQJ71C24TEL_put_ActCallbackDelayTime(This,newVal)	\
    (This)->lpVtbl -> put_ActCallbackDelayTime(This,newVal)

#define IActQJ71C24TEL_get_ActConnectWay(This,pVal)	\
    (This)->lpVtbl -> get_ActConnectWay(This,pVal)

#define IActQJ71C24TEL_put_ActConnectWay(This,newVal)	\
    (This)->lpVtbl -> put_ActConnectWay(This,newVal)

#define IActQJ71C24TEL_get_ActOutsideLineNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActOutsideLineNumber(This,pVal)

#define IActQJ71C24TEL_put_ActOutsideLineNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActOutsideLineNumber(This,newVal)

#define IActQJ71C24TEL_get_ActPasswordCancelResponseWaitTime(This,pVal)	\
    (This)->lpVtbl -> get_ActPasswordCancelResponseWaitTime(This,pVal)

#define IActQJ71C24TEL_put_ActPasswordCancelResponseWaitTime(This,newVal)	\
    (This)->lpVtbl -> put_ActPasswordCancelResponseWaitTime(This,newVal)

#define IActQJ71C24TEL_get_ActCallbackReceptionWaitingTimeOut(This,pVal)	\
    (This)->lpVtbl -> get_ActCallbackReceptionWaitingTimeOut(This,pVal)

#define IActQJ71C24TEL_put_ActCallbackReceptionWaitingTimeOut(This,newVal)	\
    (This)->lpVtbl -> put_ActCallbackReceptionWaitingTimeOut(This,newVal)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActQJ71C24TEL_Open_Proxy( 
    IActQJ71C24TEL __RPC_FAR * This,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActQJ71C24TEL_Open_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActQJ71C24TEL_Close_Proxy( 
    IActQJ71C24TEL __RPC_FAR * This,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActQJ71C24TEL_Close_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActQJ71C24TEL_GetDevice_Proxy( 
    IActQJ71C24TEL __RPC_FAR * This,
    /* [string][in] */ BSTR szDevice,
    /* [out] */ LONG __RPC_FAR *lplData,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActQJ71C24TEL_GetDevice_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActQJ71C24TEL_SetDevice_Proxy( 
    IActQJ71C24TEL __RPC_FAR * This,
    /* [string][in] */ BSTR szDevice,
    /* [in] */ LONG lData,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActQJ71C24TEL_SetDevice_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActQJ71C24TEL_ReadDeviceBlock_Proxy( 
    IActQJ71C24TEL __RPC_FAR * This,
    /* [string][in] */ BSTR szDevice,
    /* [in] */ LONG lSize,
    /* [size_is][out] */ LONG __RPC_FAR *lplData,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActQJ71C24TEL_ReadDeviceBlock_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActQJ71C24TEL_WriteDeviceBlock_Proxy( 
    IActQJ71C24TEL __RPC_FAR * This,
    /* [string][in] */ BSTR szDevice,
    /* [in] */ LONG lSize,
    /* [size_is][in] */ LONG __RPC_FAR *lplData,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActQJ71C24TEL_WriteDeviceBlock_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActQJ71C24TEL_ReadDeviceRandom_Proxy( 
    IActQJ71C24TEL __RPC_FAR * This,
    /* [string][in] */ BSTR szDeviceList,
    /* [in] */ LONG lSize,
    /* [size_is][out] */ LONG __RPC_FAR *lplData,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActQJ71C24TEL_ReadDeviceRandom_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActQJ71C24TEL_WriteDeviceRandom_Proxy( 
    IActQJ71C24TEL __RPC_FAR * This,
    /* [string][in] */ BSTR szDeviceList,
    /* [in] */ LONG lSize,
    /* [size_is][in] */ LONG __RPC_FAR *lplData,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActQJ71C24TEL_WriteDeviceRandom_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActQJ71C24TEL_ReadBuffer_Proxy( 
    IActQJ71C24TEL __RPC_FAR * This,
    /* [in] */ LONG lStartIO,
    /* [in] */ LONG lAddress,
    /* [in] */ LONG lReadSize,
    /* [size_is][out] */ SHORT __RPC_FAR *lpsData,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActQJ71C24TEL_ReadBuffer_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActQJ71C24TEL_WriteBuffer_Proxy( 
    IActQJ71C24TEL __RPC_FAR * This,
    /* [in] */ LONG lStartIO,
    /* [in] */ LONG lAddress,
    /* [in] */ LONG lWriteSize,
    /* [size_is][in] */ SHORT __RPC_FAR *lpsData,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActQJ71C24TEL_WriteBuffer_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActQJ71C24TEL_GetClockData_Proxy( 
    IActQJ71C24TEL __RPC_FAR * This,
    /* [out] */ SHORT __RPC_FAR *lpsYear,
    /* [out] */ SHORT __RPC_FAR *lpsMonth,
    /* [out] */ SHORT __RPC_FAR *lpsDay,
    /* [out] */ SHORT __RPC_FAR *lpsDayOfWeek,
    /* [out] */ SHORT __RPC_FAR *lpsHour,
    /* [out] */ SHORT __RPC_FAR *lpsMinute,
    /* [out] */ SHORT __RPC_FAR *lpsSecond,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActQJ71C24TEL_GetClockData_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActQJ71C24TEL_SetClockData_Proxy( 
    IActQJ71C24TEL __RPC_FAR * This,
    /* [in] */ SHORT sYear,
    /* [in] */ SHORT sMonth,
    /* [in] */ SHORT sDay,
    /* [in] */ SHORT sDayOfWeek,
    /* [in] */ SHORT sHour,
    /* [in] */ SHORT sMinute,
    /* [in] */ SHORT sSecond,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActQJ71C24TEL_SetClockData_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActQJ71C24TEL_GetCpuType_Proxy( 
    IActQJ71C24TEL __RPC_FAR * This,
    /* [string][out] */ BSTR __RPC_FAR *szCpuName,
    /* [out] */ LONG __RPC_FAR *lplCpuCode,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActQJ71C24TEL_GetCpuType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActQJ71C24TEL_SetCpuStatus_Proxy( 
    IActQJ71C24TEL __RPC_FAR * This,
    /* [in] */ LONG lOperation,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActQJ71C24TEL_SetCpuStatus_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActQJ71C24TEL_CheckDeviceString_Proxy( 
    IActQJ71C24TEL __RPC_FAR * This,
    /* [string][in] */ BSTR szDevice,
    /* [in] */ LONG lCheckType,
    /* [in] */ LONG lSize,
    /* [out] */ LONG __RPC_FAR *lplDeviceType,
    /* [string][out] */ BSTR __RPC_FAR *lpszDeviceName,
    /* [out] */ LONG __RPC_FAR *lplDeviceNumber,
    /* [out] */ LONG __RPC_FAR *lplDeviceRadix,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActQJ71C24TEL_CheckDeviceString_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActQJ71C24TEL_EntryDeviceStatus_Proxy( 
    IActQJ71C24TEL __RPC_FAR * This,
    /* [string][in] */ BSTR szDeviceList,
    /* [in] */ LONG lSize,
    /* [in] */ LONG lMonitorCycle,
    /* [size_is][in] */ LONG __RPC_FAR *lplData,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActQJ71C24TEL_EntryDeviceStatus_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActQJ71C24TEL_FreeDeviceStatus_Proxy( 
    IActQJ71C24TEL __RPC_FAR * This,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActQJ71C24TEL_FreeDeviceStatus_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActQJ71C24TEL_ReadDeviceBlock2_Proxy( 
    IActQJ71C24TEL __RPC_FAR * This,
    /* [string][in] */ BSTR szDevice,
    /* [in] */ LONG lSize,
    /* [size_is][out] */ SHORT __RPC_FAR *lpsData,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActQJ71C24TEL_ReadDeviceBlock2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActQJ71C24TEL_WriteDeviceBlock2_Proxy( 
    IActQJ71C24TEL __RPC_FAR * This,
    /* [string][in] */ BSTR szDevice,
    /* [in] */ LONG lSize,
    /* [size_is][in] */ SHORT __RPC_FAR *lpsData,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActQJ71C24TEL_WriteDeviceBlock2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActQJ71C24TEL_ReadDeviceRandom2_Proxy( 
    IActQJ71C24TEL __RPC_FAR * This,
    /* [string][in] */ BSTR szDeviceList,
    /* [in] */ LONG lSize,
    /* [size_is][out] */ SHORT __RPC_FAR *lpsData,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActQJ71C24TEL_ReadDeviceRandom2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActQJ71C24TEL_WriteDeviceRandom2_Proxy( 
    IActQJ71C24TEL __RPC_FAR * This,
    /* [string][in] */ BSTR szDeviceList,
    /* [in] */ LONG lSize,
    /* [size_is][in] */ SHORT __RPC_FAR *lpsData,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActQJ71C24TEL_WriteDeviceRandom2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActQJ71C24TEL_GetDevice2_Proxy( 
    IActQJ71C24TEL __RPC_FAR * This,
    /* [string][in] */ BSTR szDevice,
    /* [out] */ SHORT __RPC_FAR *lpsData,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActQJ71C24TEL_GetDevice2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActQJ71C24TEL_SetDevice2_Proxy( 
    IActQJ71C24TEL __RPC_FAR * This,
    /* [string][in] */ BSTR szDevice,
    /* [in] */ SHORT sData,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActQJ71C24TEL_SetDevice2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActQJ71C24TEL_Connect_Proxy( 
    IActQJ71C24TEL __RPC_FAR * This,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActQJ71C24TEL_Connect_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActQJ71C24TEL_Disconnect_Proxy( 
    IActQJ71C24TEL __RPC_FAR * This,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActQJ71C24TEL_Disconnect_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActQJ71C24TEL_get_ActNetworkNumber_Proxy( 
    IActQJ71C24TEL __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IActQJ71C24TEL_get_ActNetworkNumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActQJ71C24TEL_put_ActNetworkNumber_Proxy( 
    IActQJ71C24TEL __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB IActQJ71C24TEL_put_ActNetworkNumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActQJ71C24TEL_get_ActStationNumber_Proxy( 
    IActQJ71C24TEL __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IActQJ71C24TEL_get_ActStationNumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActQJ71C24TEL_put_ActStationNumber_Proxy( 
    IActQJ71C24TEL __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB IActQJ71C24TEL_put_ActStationNumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActQJ71C24TEL_get_ActUnitNumber_Proxy( 
    IActQJ71C24TEL __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IActQJ71C24TEL_get_ActUnitNumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActQJ71C24TEL_put_ActUnitNumber_Proxy( 
    IActQJ71C24TEL __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB IActQJ71C24TEL_put_ActUnitNumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActQJ71C24TEL_get_ActConnectUnitNumber_Proxy( 
    IActQJ71C24TEL __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IActQJ71C24TEL_get_ActConnectUnitNumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActQJ71C24TEL_put_ActConnectUnitNumber_Proxy( 
    IActQJ71C24TEL __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB IActQJ71C24TEL_put_ActConnectUnitNumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActQJ71C24TEL_get_ActIONumber_Proxy( 
    IActQJ71C24TEL __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IActQJ71C24TEL_get_ActIONumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActQJ71C24TEL_put_ActIONumber_Proxy( 
    IActQJ71C24TEL __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB IActQJ71C24TEL_put_ActIONumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActQJ71C24TEL_get_ActCpuType_Proxy( 
    IActQJ71C24TEL __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IActQJ71C24TEL_get_ActCpuType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActQJ71C24TEL_put_ActCpuType_Proxy( 
    IActQJ71C24TEL __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB IActQJ71C24TEL_put_ActCpuType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActQJ71C24TEL_get_ActPortNumber_Proxy( 
    IActQJ71C24TEL __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IActQJ71C24TEL_get_ActPortNumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActQJ71C24TEL_put_ActPortNumber_Proxy( 
    IActQJ71C24TEL __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB IActQJ71C24TEL_put_ActPortNumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActQJ71C24TEL_get_ActBaudRate_Proxy( 
    IActQJ71C24TEL __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IActQJ71C24TEL_get_ActBaudRate_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActQJ71C24TEL_put_ActBaudRate_Proxy( 
    IActQJ71C24TEL __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB IActQJ71C24TEL_put_ActBaudRate_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActQJ71C24TEL_get_ActTimeOut_Proxy( 
    IActQJ71C24TEL __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IActQJ71C24TEL_get_ActTimeOut_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActQJ71C24TEL_put_ActTimeOut_Proxy( 
    IActQJ71C24TEL __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB IActQJ71C24TEL_put_ActTimeOut_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActQJ71C24TEL_get_ActDestinationIONumber_Proxy( 
    IActQJ71C24TEL __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IActQJ71C24TEL_get_ActDestinationIONumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActQJ71C24TEL_put_ActDestinationIONumber_Proxy( 
    IActQJ71C24TEL __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB IActQJ71C24TEL_put_ActDestinationIONumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActQJ71C24TEL_get_ActMultiDropChannelNumber_Proxy( 
    IActQJ71C24TEL __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IActQJ71C24TEL_get_ActMultiDropChannelNumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActQJ71C24TEL_put_ActMultiDropChannelNumber_Proxy( 
    IActQJ71C24TEL __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB IActQJ71C24TEL_put_ActMultiDropChannelNumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActQJ71C24TEL_get_ActThroughNetworkType_Proxy( 
    IActQJ71C24TEL __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IActQJ71C24TEL_get_ActThroughNetworkType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActQJ71C24TEL_put_ActThroughNetworkType_Proxy( 
    IActQJ71C24TEL __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB IActQJ71C24TEL_put_ActThroughNetworkType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActQJ71C24TEL_get_ActIntelligentPreferenceBit_Proxy( 
    IActQJ71C24TEL __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IActQJ71C24TEL_get_ActIntelligentPreferenceBit_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActQJ71C24TEL_put_ActIntelligentPreferenceBit_Proxy( 
    IActQJ71C24TEL __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB IActQJ71C24TEL_put_ActIntelligentPreferenceBit_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActQJ71C24TEL_get_ActDidPropertyBit_Proxy( 
    IActQJ71C24TEL __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IActQJ71C24TEL_get_ActDidPropertyBit_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActQJ71C24TEL_put_ActDidPropertyBit_Proxy( 
    IActQJ71C24TEL __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB IActQJ71C24TEL_put_ActDidPropertyBit_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActQJ71C24TEL_get_ActDsidPropertyBit_Proxy( 
    IActQJ71C24TEL __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IActQJ71C24TEL_get_ActDsidPropertyBit_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActQJ71C24TEL_put_ActDsidPropertyBit_Proxy( 
    IActQJ71C24TEL __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB IActQJ71C24TEL_put_ActDsidPropertyBit_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActQJ71C24TEL_get_ActATCommand_Proxy( 
    IActQJ71C24TEL __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *pVal);


void __RPC_STUB IActQJ71C24TEL_get_ActATCommand_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActQJ71C24TEL_put_ActATCommand_Proxy( 
    IActQJ71C24TEL __RPC_FAR * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB IActQJ71C24TEL_put_ActATCommand_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActQJ71C24TEL_get_ActDialNumber_Proxy( 
    IActQJ71C24TEL __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *pVal);


void __RPC_STUB IActQJ71C24TEL_get_ActDialNumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActQJ71C24TEL_put_ActDialNumber_Proxy( 
    IActQJ71C24TEL __RPC_FAR * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB IActQJ71C24TEL_put_ActDialNumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActQJ71C24TEL_get_ActCallbackNumber_Proxy( 
    IActQJ71C24TEL __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *pVal);


void __RPC_STUB IActQJ71C24TEL_get_ActCallbackNumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActQJ71C24TEL_put_ActCallbackNumber_Proxy( 
    IActQJ71C24TEL __RPC_FAR * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB IActQJ71C24TEL_put_ActCallbackNumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActQJ71C24TEL_get_ActLineType_Proxy( 
    IActQJ71C24TEL __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IActQJ71C24TEL_get_ActLineType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActQJ71C24TEL_put_ActLineType_Proxy( 
    IActQJ71C24TEL __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB IActQJ71C24TEL_put_ActLineType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActQJ71C24TEL_get_ActPassword_Proxy( 
    IActQJ71C24TEL __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *pVal);


void __RPC_STUB IActQJ71C24TEL_get_ActPassword_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActQJ71C24TEL_put_ActPassword_Proxy( 
    IActQJ71C24TEL __RPC_FAR * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB IActQJ71C24TEL_put_ActPassword_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActQJ71C24TEL_get_ActConnectionCDWaitTime_Proxy( 
    IActQJ71C24TEL __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IActQJ71C24TEL_get_ActConnectionCDWaitTime_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActQJ71C24TEL_put_ActConnectionCDWaitTime_Proxy( 
    IActQJ71C24TEL __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB IActQJ71C24TEL_put_ActConnectionCDWaitTime_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActQJ71C24TEL_get_ActConnectionModemReportWaitTime_Proxy( 
    IActQJ71C24TEL __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IActQJ71C24TEL_get_ActConnectionModemReportWaitTime_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActQJ71C24TEL_put_ActConnectionModemReportWaitTime_Proxy( 
    IActQJ71C24TEL __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB IActQJ71C24TEL_put_ActConnectionModemReportWaitTime_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActQJ71C24TEL_get_ActDisconnectionCDWaitTime_Proxy( 
    IActQJ71C24TEL __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IActQJ71C24TEL_get_ActDisconnectionCDWaitTime_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActQJ71C24TEL_put_ActDisconnectionCDWaitTime_Proxy( 
    IActQJ71C24TEL __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB IActQJ71C24TEL_put_ActDisconnectionCDWaitTime_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActQJ71C24TEL_get_ActDisconnectionDelayTime_Proxy( 
    IActQJ71C24TEL __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IActQJ71C24TEL_get_ActDisconnectionDelayTime_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActQJ71C24TEL_put_ActDisconnectionDelayTime_Proxy( 
    IActQJ71C24TEL __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB IActQJ71C24TEL_put_ActDisconnectionDelayTime_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActQJ71C24TEL_get_ActTransmissionDelayTime_Proxy( 
    IActQJ71C24TEL __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IActQJ71C24TEL_get_ActTransmissionDelayTime_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActQJ71C24TEL_put_ActTransmissionDelayTime_Proxy( 
    IActQJ71C24TEL __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB IActQJ71C24TEL_put_ActTransmissionDelayTime_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActQJ71C24TEL_get_ActATCommandResponseWaitTime_Proxy( 
    IActQJ71C24TEL __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IActQJ71C24TEL_get_ActATCommandResponseWaitTime_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActQJ71C24TEL_put_ActATCommandResponseWaitTime_Proxy( 
    IActQJ71C24TEL __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB IActQJ71C24TEL_put_ActATCommandResponseWaitTime_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActQJ71C24TEL_get_ActATCommandPasswordCancelRetryTimes_Proxy( 
    IActQJ71C24TEL __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IActQJ71C24TEL_get_ActATCommandPasswordCancelRetryTimes_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActQJ71C24TEL_put_ActATCommandPasswordCancelRetryTimes_Proxy( 
    IActQJ71C24TEL __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB IActQJ71C24TEL_put_ActATCommandPasswordCancelRetryTimes_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActQJ71C24TEL_get_ActCallbackCancelWaitTime_Proxy( 
    IActQJ71C24TEL __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IActQJ71C24TEL_get_ActCallbackCancelWaitTime_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActQJ71C24TEL_put_ActCallbackCancelWaitTime_Proxy( 
    IActQJ71C24TEL __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB IActQJ71C24TEL_put_ActCallbackCancelWaitTime_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActQJ71C24TEL_get_ActCallbackDelayTime_Proxy( 
    IActQJ71C24TEL __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IActQJ71C24TEL_get_ActCallbackDelayTime_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActQJ71C24TEL_put_ActCallbackDelayTime_Proxy( 
    IActQJ71C24TEL __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB IActQJ71C24TEL_put_ActCallbackDelayTime_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActQJ71C24TEL_get_ActConnectWay_Proxy( 
    IActQJ71C24TEL __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IActQJ71C24TEL_get_ActConnectWay_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActQJ71C24TEL_put_ActConnectWay_Proxy( 
    IActQJ71C24TEL __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB IActQJ71C24TEL_put_ActConnectWay_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActQJ71C24TEL_get_ActOutsideLineNumber_Proxy( 
    IActQJ71C24TEL __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *pVal);


void __RPC_STUB IActQJ71C24TEL_get_ActOutsideLineNumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActQJ71C24TEL_put_ActOutsideLineNumber_Proxy( 
    IActQJ71C24TEL __RPC_FAR * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB IActQJ71C24TEL_put_ActOutsideLineNumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActQJ71C24TEL_get_ActPasswordCancelResponseWaitTime_Proxy( 
    IActQJ71C24TEL __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IActQJ71C24TEL_get_ActPasswordCancelResponseWaitTime_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActQJ71C24TEL_put_ActPasswordCancelResponseWaitTime_Proxy( 
    IActQJ71C24TEL __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB IActQJ71C24TEL_put_ActPasswordCancelResponseWaitTime_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActQJ71C24TEL_get_ActCallbackReceptionWaitingTimeOut_Proxy( 
    IActQJ71C24TEL __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IActQJ71C24TEL_get_ActCallbackReceptionWaitingTimeOut_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActQJ71C24TEL_put_ActCallbackReceptionWaitingTimeOut_Proxy( 
    IActQJ71C24TEL __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB IActQJ71C24TEL_put_ActCallbackReceptionWaitingTimeOut_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IActQJ71C24TEL_INTERFACE_DEFINED__ */


#ifndef __IActQJ71C24TEL2_INTERFACE_DEFINED__
#define __IActQJ71C24TEL2_INTERFACE_DEFINED__

/* interface IActQJ71C24TEL2 */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IActQJ71C24TEL2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("8716603E-710B-11d5-9318-009099244EFD")
    IActQJ71C24TEL2 : public IActQJ71C24TEL
    {
    public:
    };
    
#else 	/* C style interface */

    typedef struct IActQJ71C24TEL2Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IActQJ71C24TEL2 __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IActQJ71C24TEL2 __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IActQJ71C24TEL2 __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IActQJ71C24TEL2 __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IActQJ71C24TEL2 __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IActQJ71C24TEL2 __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IActQJ71C24TEL2 __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Open )( 
            IActQJ71C24TEL2 __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Close )( 
            IActQJ71C24TEL2 __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetDevice )( 
            IActQJ71C24TEL2 __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [out] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetDevice )( 
            IActQJ71C24TEL2 __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceBlock )( 
            IActQJ71C24TEL2 __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lSize,
            /* [size_is][out] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceBlock )( 
            IActQJ71C24TEL2 __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lSize,
            /* [size_is][in] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceRandom )( 
            IActQJ71C24TEL2 __RPC_FAR * This,
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG lSize,
            /* [size_is][out] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceRandom )( 
            IActQJ71C24TEL2 __RPC_FAR * This,
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG lSize,
            /* [size_is][in] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadBuffer )( 
            IActQJ71C24TEL2 __RPC_FAR * This,
            /* [in] */ LONG lStartIO,
            /* [in] */ LONG lAddress,
            /* [in] */ LONG lReadSize,
            /* [size_is][out] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteBuffer )( 
            IActQJ71C24TEL2 __RPC_FAR * This,
            /* [in] */ LONG lStartIO,
            /* [in] */ LONG lAddress,
            /* [in] */ LONG lWriteSize,
            /* [size_is][in] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetClockData )( 
            IActQJ71C24TEL2 __RPC_FAR * This,
            /* [out] */ SHORT __RPC_FAR *lpsYear,
            /* [out] */ SHORT __RPC_FAR *lpsMonth,
            /* [out] */ SHORT __RPC_FAR *lpsDay,
            /* [out] */ SHORT __RPC_FAR *lpsDayOfWeek,
            /* [out] */ SHORT __RPC_FAR *lpsHour,
            /* [out] */ SHORT __RPC_FAR *lpsMinute,
            /* [out] */ SHORT __RPC_FAR *lpsSecond,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetClockData )( 
            IActQJ71C24TEL2 __RPC_FAR * This,
            /* [in] */ SHORT sYear,
            /* [in] */ SHORT sMonth,
            /* [in] */ SHORT sDay,
            /* [in] */ SHORT sDayOfWeek,
            /* [in] */ SHORT sHour,
            /* [in] */ SHORT sMinute,
            /* [in] */ SHORT sSecond,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetCpuType )( 
            IActQJ71C24TEL2 __RPC_FAR * This,
            /* [string][out] */ BSTR __RPC_FAR *szCpuName,
            /* [out] */ LONG __RPC_FAR *lplCpuCode,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetCpuStatus )( 
            IActQJ71C24TEL2 __RPC_FAR * This,
            /* [in] */ LONG lOperation,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CheckDeviceString )( 
            IActQJ71C24TEL2 __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lCheckType,
            /* [in] */ LONG lSize,
            /* [out] */ LONG __RPC_FAR *lplDeviceType,
            /* [string][out] */ BSTR __RPC_FAR *lpszDeviceName,
            /* [out] */ LONG __RPC_FAR *lplDeviceNumber,
            /* [out] */ LONG __RPC_FAR *lplDeviceRadix,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *EntryDeviceStatus )( 
            IActQJ71C24TEL2 __RPC_FAR * This,
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG lSize,
            /* [in] */ LONG lMonitorCycle,
            /* [size_is][in] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *FreeDeviceStatus )( 
            IActQJ71C24TEL2 __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceBlock2 )( 
            IActQJ71C24TEL2 __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lSize,
            /* [size_is][out] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceBlock2 )( 
            IActQJ71C24TEL2 __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lSize,
            /* [size_is][in] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceRandom2 )( 
            IActQJ71C24TEL2 __RPC_FAR * This,
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG lSize,
            /* [size_is][out] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceRandom2 )( 
            IActQJ71C24TEL2 __RPC_FAR * This,
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG lSize,
            /* [size_is][in] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetDevice2 )( 
            IActQJ71C24TEL2 __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [out] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetDevice2 )( 
            IActQJ71C24TEL2 __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ SHORT sData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Connect )( 
            IActQJ71C24TEL2 __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Disconnect )( 
            IActQJ71C24TEL2 __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActNetworkNumber )( 
            IActQJ71C24TEL2 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActNetworkNumber )( 
            IActQJ71C24TEL2 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActStationNumber )( 
            IActQJ71C24TEL2 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActStationNumber )( 
            IActQJ71C24TEL2 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActUnitNumber )( 
            IActQJ71C24TEL2 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActUnitNumber )( 
            IActQJ71C24TEL2 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActConnectUnitNumber )( 
            IActQJ71C24TEL2 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActConnectUnitNumber )( 
            IActQJ71C24TEL2 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActIONumber )( 
            IActQJ71C24TEL2 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActIONumber )( 
            IActQJ71C24TEL2 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActCpuType )( 
            IActQJ71C24TEL2 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActCpuType )( 
            IActQJ71C24TEL2 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActPortNumber )( 
            IActQJ71C24TEL2 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActPortNumber )( 
            IActQJ71C24TEL2 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActBaudRate )( 
            IActQJ71C24TEL2 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActBaudRate )( 
            IActQJ71C24TEL2 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActTimeOut )( 
            IActQJ71C24TEL2 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActTimeOut )( 
            IActQJ71C24TEL2 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActDestinationIONumber )( 
            IActQJ71C24TEL2 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActDestinationIONumber )( 
            IActQJ71C24TEL2 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActMultiDropChannelNumber )( 
            IActQJ71C24TEL2 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActMultiDropChannelNumber )( 
            IActQJ71C24TEL2 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActThroughNetworkType )( 
            IActQJ71C24TEL2 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActThroughNetworkType )( 
            IActQJ71C24TEL2 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActIntelligentPreferenceBit )( 
            IActQJ71C24TEL2 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActIntelligentPreferenceBit )( 
            IActQJ71C24TEL2 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActDidPropertyBit )( 
            IActQJ71C24TEL2 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActDidPropertyBit )( 
            IActQJ71C24TEL2 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActDsidPropertyBit )( 
            IActQJ71C24TEL2 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActDsidPropertyBit )( 
            IActQJ71C24TEL2 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActATCommand )( 
            IActQJ71C24TEL2 __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActATCommand )( 
            IActQJ71C24TEL2 __RPC_FAR * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActDialNumber )( 
            IActQJ71C24TEL2 __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActDialNumber )( 
            IActQJ71C24TEL2 __RPC_FAR * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActCallbackNumber )( 
            IActQJ71C24TEL2 __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActCallbackNumber )( 
            IActQJ71C24TEL2 __RPC_FAR * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActLineType )( 
            IActQJ71C24TEL2 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActLineType )( 
            IActQJ71C24TEL2 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActPassword )( 
            IActQJ71C24TEL2 __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActPassword )( 
            IActQJ71C24TEL2 __RPC_FAR * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActConnectionCDWaitTime )( 
            IActQJ71C24TEL2 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActConnectionCDWaitTime )( 
            IActQJ71C24TEL2 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActConnectionModemReportWaitTime )( 
            IActQJ71C24TEL2 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActConnectionModemReportWaitTime )( 
            IActQJ71C24TEL2 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActDisconnectionCDWaitTime )( 
            IActQJ71C24TEL2 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActDisconnectionCDWaitTime )( 
            IActQJ71C24TEL2 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActDisconnectionDelayTime )( 
            IActQJ71C24TEL2 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActDisconnectionDelayTime )( 
            IActQJ71C24TEL2 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActTransmissionDelayTime )( 
            IActQJ71C24TEL2 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActTransmissionDelayTime )( 
            IActQJ71C24TEL2 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActATCommandResponseWaitTime )( 
            IActQJ71C24TEL2 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActATCommandResponseWaitTime )( 
            IActQJ71C24TEL2 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActATCommandPasswordCancelRetryTimes )( 
            IActQJ71C24TEL2 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActATCommandPasswordCancelRetryTimes )( 
            IActQJ71C24TEL2 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActCallbackCancelWaitTime )( 
            IActQJ71C24TEL2 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActCallbackCancelWaitTime )( 
            IActQJ71C24TEL2 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActCallbackDelayTime )( 
            IActQJ71C24TEL2 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActCallbackDelayTime )( 
            IActQJ71C24TEL2 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActConnectWay )( 
            IActQJ71C24TEL2 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActConnectWay )( 
            IActQJ71C24TEL2 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActOutsideLineNumber )( 
            IActQJ71C24TEL2 __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActOutsideLineNumber )( 
            IActQJ71C24TEL2 __RPC_FAR * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActPasswordCancelResponseWaitTime )( 
            IActQJ71C24TEL2 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActPasswordCancelResponseWaitTime )( 
            IActQJ71C24TEL2 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActCallbackReceptionWaitingTimeOut )( 
            IActQJ71C24TEL2 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActCallbackReceptionWaitingTimeOut )( 
            IActQJ71C24TEL2 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        END_INTERFACE
    } IActQJ71C24TEL2Vtbl;

    interface IActQJ71C24TEL2
    {
        CONST_VTBL struct IActQJ71C24TEL2Vtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IActQJ71C24TEL2_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IActQJ71C24TEL2_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IActQJ71C24TEL2_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IActQJ71C24TEL2_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IActQJ71C24TEL2_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IActQJ71C24TEL2_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IActQJ71C24TEL2_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IActQJ71C24TEL2_Open(This,lplReturnCode)	\
    (This)->lpVtbl -> Open(This,lplReturnCode)

#define IActQJ71C24TEL2_Close(This,lplReturnCode)	\
    (This)->lpVtbl -> Close(This,lplReturnCode)

#define IActQJ71C24TEL2_GetDevice(This,szDevice,lplData,lplReturnCode)	\
    (This)->lpVtbl -> GetDevice(This,szDevice,lplData,lplReturnCode)

#define IActQJ71C24TEL2_SetDevice(This,szDevice,lData,lplReturnCode)	\
    (This)->lpVtbl -> SetDevice(This,szDevice,lData,lplReturnCode)

#define IActQJ71C24TEL2_ReadDeviceBlock(This,szDevice,lSize,lplData,lplReturnCode)	\
    (This)->lpVtbl -> ReadDeviceBlock(This,szDevice,lSize,lplData,lplReturnCode)

#define IActQJ71C24TEL2_WriteDeviceBlock(This,szDevice,lSize,lplData,lplReturnCode)	\
    (This)->lpVtbl -> WriteDeviceBlock(This,szDevice,lSize,lplData,lplReturnCode)

#define IActQJ71C24TEL2_ReadDeviceRandom(This,szDeviceList,lSize,lplData,lplReturnCode)	\
    (This)->lpVtbl -> ReadDeviceRandom(This,szDeviceList,lSize,lplData,lplReturnCode)

#define IActQJ71C24TEL2_WriteDeviceRandom(This,szDeviceList,lSize,lplData,lplReturnCode)	\
    (This)->lpVtbl -> WriteDeviceRandom(This,szDeviceList,lSize,lplData,lplReturnCode)

#define IActQJ71C24TEL2_ReadBuffer(This,lStartIO,lAddress,lReadSize,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> ReadBuffer(This,lStartIO,lAddress,lReadSize,lpsData,lplReturnCode)

#define IActQJ71C24TEL2_WriteBuffer(This,lStartIO,lAddress,lWriteSize,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> WriteBuffer(This,lStartIO,lAddress,lWriteSize,lpsData,lplReturnCode)

#define IActQJ71C24TEL2_GetClockData(This,lpsYear,lpsMonth,lpsDay,lpsDayOfWeek,lpsHour,lpsMinute,lpsSecond,lplReturnCode)	\
    (This)->lpVtbl -> GetClockData(This,lpsYear,lpsMonth,lpsDay,lpsDayOfWeek,lpsHour,lpsMinute,lpsSecond,lplReturnCode)

#define IActQJ71C24TEL2_SetClockData(This,sYear,sMonth,sDay,sDayOfWeek,sHour,sMinute,sSecond,lplReturnCode)	\
    (This)->lpVtbl -> SetClockData(This,sYear,sMonth,sDay,sDayOfWeek,sHour,sMinute,sSecond,lplReturnCode)

#define IActQJ71C24TEL2_GetCpuType(This,szCpuName,lplCpuCode,lplReturnCode)	\
    (This)->lpVtbl -> GetCpuType(This,szCpuName,lplCpuCode,lplReturnCode)

#define IActQJ71C24TEL2_SetCpuStatus(This,lOperation,lplReturnCode)	\
    (This)->lpVtbl -> SetCpuStatus(This,lOperation,lplReturnCode)

#define IActQJ71C24TEL2_CheckDeviceString(This,szDevice,lCheckType,lSize,lplDeviceType,lpszDeviceName,lplDeviceNumber,lplDeviceRadix,lplReturnCode)	\
    (This)->lpVtbl -> CheckDeviceString(This,szDevice,lCheckType,lSize,lplDeviceType,lpszDeviceName,lplDeviceNumber,lplDeviceRadix,lplReturnCode)

#define IActQJ71C24TEL2_EntryDeviceStatus(This,szDeviceList,lSize,lMonitorCycle,lplData,lplReturnCode)	\
    (This)->lpVtbl -> EntryDeviceStatus(This,szDeviceList,lSize,lMonitorCycle,lplData,lplReturnCode)

#define IActQJ71C24TEL2_FreeDeviceStatus(This,lplReturnCode)	\
    (This)->lpVtbl -> FreeDeviceStatus(This,lplReturnCode)

#define IActQJ71C24TEL2_ReadDeviceBlock2(This,szDevice,lSize,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> ReadDeviceBlock2(This,szDevice,lSize,lpsData,lplReturnCode)

#define IActQJ71C24TEL2_WriteDeviceBlock2(This,szDevice,lSize,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> WriteDeviceBlock2(This,szDevice,lSize,lpsData,lplReturnCode)

#define IActQJ71C24TEL2_ReadDeviceRandom2(This,szDeviceList,lSize,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> ReadDeviceRandom2(This,szDeviceList,lSize,lpsData,lplReturnCode)

#define IActQJ71C24TEL2_WriteDeviceRandom2(This,szDeviceList,lSize,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> WriteDeviceRandom2(This,szDeviceList,lSize,lpsData,lplReturnCode)

#define IActQJ71C24TEL2_GetDevice2(This,szDevice,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> GetDevice2(This,szDevice,lpsData,lplReturnCode)

#define IActQJ71C24TEL2_SetDevice2(This,szDevice,sData,lplReturnCode)	\
    (This)->lpVtbl -> SetDevice2(This,szDevice,sData,lplReturnCode)

#define IActQJ71C24TEL2_Connect(This,lplReturnCode)	\
    (This)->lpVtbl -> Connect(This,lplReturnCode)

#define IActQJ71C24TEL2_Disconnect(This,lplReturnCode)	\
    (This)->lpVtbl -> Disconnect(This,lplReturnCode)

#define IActQJ71C24TEL2_get_ActNetworkNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActNetworkNumber(This,pVal)

#define IActQJ71C24TEL2_put_ActNetworkNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActNetworkNumber(This,newVal)

#define IActQJ71C24TEL2_get_ActStationNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActStationNumber(This,pVal)

#define IActQJ71C24TEL2_put_ActStationNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActStationNumber(This,newVal)

#define IActQJ71C24TEL2_get_ActUnitNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActUnitNumber(This,pVal)

#define IActQJ71C24TEL2_put_ActUnitNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActUnitNumber(This,newVal)

#define IActQJ71C24TEL2_get_ActConnectUnitNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActConnectUnitNumber(This,pVal)

#define IActQJ71C24TEL2_put_ActConnectUnitNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActConnectUnitNumber(This,newVal)

#define IActQJ71C24TEL2_get_ActIONumber(This,pVal)	\
    (This)->lpVtbl -> get_ActIONumber(This,pVal)

#define IActQJ71C24TEL2_put_ActIONumber(This,newVal)	\
    (This)->lpVtbl -> put_ActIONumber(This,newVal)

#define IActQJ71C24TEL2_get_ActCpuType(This,pVal)	\
    (This)->lpVtbl -> get_ActCpuType(This,pVal)

#define IActQJ71C24TEL2_put_ActCpuType(This,newVal)	\
    (This)->lpVtbl -> put_ActCpuType(This,newVal)

#define IActQJ71C24TEL2_get_ActPortNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActPortNumber(This,pVal)

#define IActQJ71C24TEL2_put_ActPortNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActPortNumber(This,newVal)

#define IActQJ71C24TEL2_get_ActBaudRate(This,pVal)	\
    (This)->lpVtbl -> get_ActBaudRate(This,pVal)

#define IActQJ71C24TEL2_put_ActBaudRate(This,newVal)	\
    (This)->lpVtbl -> put_ActBaudRate(This,newVal)

#define IActQJ71C24TEL2_get_ActTimeOut(This,pVal)	\
    (This)->lpVtbl -> get_ActTimeOut(This,pVal)

#define IActQJ71C24TEL2_put_ActTimeOut(This,newVal)	\
    (This)->lpVtbl -> put_ActTimeOut(This,newVal)

#define IActQJ71C24TEL2_get_ActDestinationIONumber(This,pVal)	\
    (This)->lpVtbl -> get_ActDestinationIONumber(This,pVal)

#define IActQJ71C24TEL2_put_ActDestinationIONumber(This,newVal)	\
    (This)->lpVtbl -> put_ActDestinationIONumber(This,newVal)

#define IActQJ71C24TEL2_get_ActMultiDropChannelNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActMultiDropChannelNumber(This,pVal)

#define IActQJ71C24TEL2_put_ActMultiDropChannelNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActMultiDropChannelNumber(This,newVal)

#define IActQJ71C24TEL2_get_ActThroughNetworkType(This,pVal)	\
    (This)->lpVtbl -> get_ActThroughNetworkType(This,pVal)

#define IActQJ71C24TEL2_put_ActThroughNetworkType(This,newVal)	\
    (This)->lpVtbl -> put_ActThroughNetworkType(This,newVal)

#define IActQJ71C24TEL2_get_ActIntelligentPreferenceBit(This,pVal)	\
    (This)->lpVtbl -> get_ActIntelligentPreferenceBit(This,pVal)

#define IActQJ71C24TEL2_put_ActIntelligentPreferenceBit(This,newVal)	\
    (This)->lpVtbl -> put_ActIntelligentPreferenceBit(This,newVal)

#define IActQJ71C24TEL2_get_ActDidPropertyBit(This,pVal)	\
    (This)->lpVtbl -> get_ActDidPropertyBit(This,pVal)

#define IActQJ71C24TEL2_put_ActDidPropertyBit(This,newVal)	\
    (This)->lpVtbl -> put_ActDidPropertyBit(This,newVal)

#define IActQJ71C24TEL2_get_ActDsidPropertyBit(This,pVal)	\
    (This)->lpVtbl -> get_ActDsidPropertyBit(This,pVal)

#define IActQJ71C24TEL2_put_ActDsidPropertyBit(This,newVal)	\
    (This)->lpVtbl -> put_ActDsidPropertyBit(This,newVal)

#define IActQJ71C24TEL2_get_ActATCommand(This,pVal)	\
    (This)->lpVtbl -> get_ActATCommand(This,pVal)

#define IActQJ71C24TEL2_put_ActATCommand(This,newVal)	\
    (This)->lpVtbl -> put_ActATCommand(This,newVal)

#define IActQJ71C24TEL2_get_ActDialNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActDialNumber(This,pVal)

#define IActQJ71C24TEL2_put_ActDialNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActDialNumber(This,newVal)

#define IActQJ71C24TEL2_get_ActCallbackNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActCallbackNumber(This,pVal)

#define IActQJ71C24TEL2_put_ActCallbackNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActCallbackNumber(This,newVal)

#define IActQJ71C24TEL2_get_ActLineType(This,pVal)	\
    (This)->lpVtbl -> get_ActLineType(This,pVal)

#define IActQJ71C24TEL2_put_ActLineType(This,newVal)	\
    (This)->lpVtbl -> put_ActLineType(This,newVal)

#define IActQJ71C24TEL2_get_ActPassword(This,pVal)	\
    (This)->lpVtbl -> get_ActPassword(This,pVal)

#define IActQJ71C24TEL2_put_ActPassword(This,newVal)	\
    (This)->lpVtbl -> put_ActPassword(This,newVal)

#define IActQJ71C24TEL2_get_ActConnectionCDWaitTime(This,pVal)	\
    (This)->lpVtbl -> get_ActConnectionCDWaitTime(This,pVal)

#define IActQJ71C24TEL2_put_ActConnectionCDWaitTime(This,newVal)	\
    (This)->lpVtbl -> put_ActConnectionCDWaitTime(This,newVal)

#define IActQJ71C24TEL2_get_ActConnectionModemReportWaitTime(This,pVal)	\
    (This)->lpVtbl -> get_ActConnectionModemReportWaitTime(This,pVal)

#define IActQJ71C24TEL2_put_ActConnectionModemReportWaitTime(This,newVal)	\
    (This)->lpVtbl -> put_ActConnectionModemReportWaitTime(This,newVal)

#define IActQJ71C24TEL2_get_ActDisconnectionCDWaitTime(This,pVal)	\
    (This)->lpVtbl -> get_ActDisconnectionCDWaitTime(This,pVal)

#define IActQJ71C24TEL2_put_ActDisconnectionCDWaitTime(This,newVal)	\
    (This)->lpVtbl -> put_ActDisconnectionCDWaitTime(This,newVal)

#define IActQJ71C24TEL2_get_ActDisconnectionDelayTime(This,pVal)	\
    (This)->lpVtbl -> get_ActDisconnectionDelayTime(This,pVal)

#define IActQJ71C24TEL2_put_ActDisconnectionDelayTime(This,newVal)	\
    (This)->lpVtbl -> put_ActDisconnectionDelayTime(This,newVal)

#define IActQJ71C24TEL2_get_ActTransmissionDelayTime(This,pVal)	\
    (This)->lpVtbl -> get_ActTransmissionDelayTime(This,pVal)

#define IActQJ71C24TEL2_put_ActTransmissionDelayTime(This,newVal)	\
    (This)->lpVtbl -> put_ActTransmissionDelayTime(This,newVal)

#define IActQJ71C24TEL2_get_ActATCommandResponseWaitTime(This,pVal)	\
    (This)->lpVtbl -> get_ActATCommandResponseWaitTime(This,pVal)

#define IActQJ71C24TEL2_put_ActATCommandResponseWaitTime(This,newVal)	\
    (This)->lpVtbl -> put_ActATCommandResponseWaitTime(This,newVal)

#define IActQJ71C24TEL2_get_ActATCommandPasswordCancelRetryTimes(This,pVal)	\
    (This)->lpVtbl -> get_ActATCommandPasswordCancelRetryTimes(This,pVal)

#define IActQJ71C24TEL2_put_ActATCommandPasswordCancelRetryTimes(This,newVal)	\
    (This)->lpVtbl -> put_ActATCommandPasswordCancelRetryTimes(This,newVal)

#define IActQJ71C24TEL2_get_ActCallbackCancelWaitTime(This,pVal)	\
    (This)->lpVtbl -> get_ActCallbackCancelWaitTime(This,pVal)

#define IActQJ71C24TEL2_put_ActCallbackCancelWaitTime(This,newVal)	\
    (This)->lpVtbl -> put_ActCallbackCancelWaitTime(This,newVal)

#define IActQJ71C24TEL2_get_ActCallbackDelayTime(This,pVal)	\
    (This)->lpVtbl -> get_ActCallbackDelayTime(This,pVal)

#define IActQJ71C24TEL2_put_ActCallbackDelayTime(This,newVal)	\
    (This)->lpVtbl -> put_ActCallbackDelayTime(This,newVal)

#define IActQJ71C24TEL2_get_ActConnectWay(This,pVal)	\
    (This)->lpVtbl -> get_ActConnectWay(This,pVal)

#define IActQJ71C24TEL2_put_ActConnectWay(This,newVal)	\
    (This)->lpVtbl -> put_ActConnectWay(This,newVal)

#define IActQJ71C24TEL2_get_ActOutsideLineNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActOutsideLineNumber(This,pVal)

#define IActQJ71C24TEL2_put_ActOutsideLineNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActOutsideLineNumber(This,newVal)

#define IActQJ71C24TEL2_get_ActPasswordCancelResponseWaitTime(This,pVal)	\
    (This)->lpVtbl -> get_ActPasswordCancelResponseWaitTime(This,pVal)

#define IActQJ71C24TEL2_put_ActPasswordCancelResponseWaitTime(This,newVal)	\
    (This)->lpVtbl -> put_ActPasswordCancelResponseWaitTime(This,newVal)

#define IActQJ71C24TEL2_get_ActCallbackReceptionWaitingTimeOut(This,pVal)	\
    (This)->lpVtbl -> get_ActCallbackReceptionWaitingTimeOut(This,pVal)

#define IActQJ71C24TEL2_put_ActCallbackReceptionWaitingTimeOut(This,newVal)	\
    (This)->lpVtbl -> put_ActCallbackReceptionWaitingTimeOut(This,newVal)


#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IActQJ71C24TEL2_INTERFACE_DEFINED__ */


#ifndef __IActQJ71C24TEL3_INTERFACE_DEFINED__
#define __IActQJ71C24TEL3_INTERFACE_DEFINED__

/* interface IActQJ71C24TEL3 */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IActQJ71C24TEL3;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("8716603F-710B-11d5-9318-009099244EFD")
    IActQJ71C24TEL3 : public IActQJ71C24TEL2
    {
    public:
    };
    
#else 	/* C style interface */

    typedef struct IActQJ71C24TEL3Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IActQJ71C24TEL3 __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IActQJ71C24TEL3 __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IActQJ71C24TEL3 __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IActQJ71C24TEL3 __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IActQJ71C24TEL3 __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IActQJ71C24TEL3 __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IActQJ71C24TEL3 __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Open )( 
            IActQJ71C24TEL3 __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Close )( 
            IActQJ71C24TEL3 __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetDevice )( 
            IActQJ71C24TEL3 __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [out] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetDevice )( 
            IActQJ71C24TEL3 __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceBlock )( 
            IActQJ71C24TEL3 __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lSize,
            /* [size_is][out] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceBlock )( 
            IActQJ71C24TEL3 __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lSize,
            /* [size_is][in] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceRandom )( 
            IActQJ71C24TEL3 __RPC_FAR * This,
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG lSize,
            /* [size_is][out] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceRandom )( 
            IActQJ71C24TEL3 __RPC_FAR * This,
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG lSize,
            /* [size_is][in] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadBuffer )( 
            IActQJ71C24TEL3 __RPC_FAR * This,
            /* [in] */ LONG lStartIO,
            /* [in] */ LONG lAddress,
            /* [in] */ LONG lReadSize,
            /* [size_is][out] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteBuffer )( 
            IActQJ71C24TEL3 __RPC_FAR * This,
            /* [in] */ LONG lStartIO,
            /* [in] */ LONG lAddress,
            /* [in] */ LONG lWriteSize,
            /* [size_is][in] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetClockData )( 
            IActQJ71C24TEL3 __RPC_FAR * This,
            /* [out] */ SHORT __RPC_FAR *lpsYear,
            /* [out] */ SHORT __RPC_FAR *lpsMonth,
            /* [out] */ SHORT __RPC_FAR *lpsDay,
            /* [out] */ SHORT __RPC_FAR *lpsDayOfWeek,
            /* [out] */ SHORT __RPC_FAR *lpsHour,
            /* [out] */ SHORT __RPC_FAR *lpsMinute,
            /* [out] */ SHORT __RPC_FAR *lpsSecond,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetClockData )( 
            IActQJ71C24TEL3 __RPC_FAR * This,
            /* [in] */ SHORT sYear,
            /* [in] */ SHORT sMonth,
            /* [in] */ SHORT sDay,
            /* [in] */ SHORT sDayOfWeek,
            /* [in] */ SHORT sHour,
            /* [in] */ SHORT sMinute,
            /* [in] */ SHORT sSecond,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetCpuType )( 
            IActQJ71C24TEL3 __RPC_FAR * This,
            /* [string][out] */ BSTR __RPC_FAR *szCpuName,
            /* [out] */ LONG __RPC_FAR *lplCpuCode,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetCpuStatus )( 
            IActQJ71C24TEL3 __RPC_FAR * This,
            /* [in] */ LONG lOperation,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CheckDeviceString )( 
            IActQJ71C24TEL3 __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lCheckType,
            /* [in] */ LONG lSize,
            /* [out] */ LONG __RPC_FAR *lplDeviceType,
            /* [string][out] */ BSTR __RPC_FAR *lpszDeviceName,
            /* [out] */ LONG __RPC_FAR *lplDeviceNumber,
            /* [out] */ LONG __RPC_FAR *lplDeviceRadix,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *EntryDeviceStatus )( 
            IActQJ71C24TEL3 __RPC_FAR * This,
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG lSize,
            /* [in] */ LONG lMonitorCycle,
            /* [size_is][in] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *FreeDeviceStatus )( 
            IActQJ71C24TEL3 __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceBlock2 )( 
            IActQJ71C24TEL3 __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lSize,
            /* [size_is][out] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceBlock2 )( 
            IActQJ71C24TEL3 __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lSize,
            /* [size_is][in] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceRandom2 )( 
            IActQJ71C24TEL3 __RPC_FAR * This,
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG lSize,
            /* [size_is][out] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceRandom2 )( 
            IActQJ71C24TEL3 __RPC_FAR * This,
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG lSize,
            /* [size_is][in] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetDevice2 )( 
            IActQJ71C24TEL3 __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [out] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetDevice2 )( 
            IActQJ71C24TEL3 __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ SHORT sData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Connect )( 
            IActQJ71C24TEL3 __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Disconnect )( 
            IActQJ71C24TEL3 __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActNetworkNumber )( 
            IActQJ71C24TEL3 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActNetworkNumber )( 
            IActQJ71C24TEL3 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActStationNumber )( 
            IActQJ71C24TEL3 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActStationNumber )( 
            IActQJ71C24TEL3 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActUnitNumber )( 
            IActQJ71C24TEL3 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActUnitNumber )( 
            IActQJ71C24TEL3 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActConnectUnitNumber )( 
            IActQJ71C24TEL3 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActConnectUnitNumber )( 
            IActQJ71C24TEL3 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActIONumber )( 
            IActQJ71C24TEL3 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActIONumber )( 
            IActQJ71C24TEL3 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActCpuType )( 
            IActQJ71C24TEL3 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActCpuType )( 
            IActQJ71C24TEL3 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActPortNumber )( 
            IActQJ71C24TEL3 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActPortNumber )( 
            IActQJ71C24TEL3 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActBaudRate )( 
            IActQJ71C24TEL3 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActBaudRate )( 
            IActQJ71C24TEL3 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActTimeOut )( 
            IActQJ71C24TEL3 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActTimeOut )( 
            IActQJ71C24TEL3 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActDestinationIONumber )( 
            IActQJ71C24TEL3 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActDestinationIONumber )( 
            IActQJ71C24TEL3 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActMultiDropChannelNumber )( 
            IActQJ71C24TEL3 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActMultiDropChannelNumber )( 
            IActQJ71C24TEL3 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActThroughNetworkType )( 
            IActQJ71C24TEL3 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActThroughNetworkType )( 
            IActQJ71C24TEL3 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActIntelligentPreferenceBit )( 
            IActQJ71C24TEL3 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActIntelligentPreferenceBit )( 
            IActQJ71C24TEL3 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActDidPropertyBit )( 
            IActQJ71C24TEL3 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActDidPropertyBit )( 
            IActQJ71C24TEL3 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActDsidPropertyBit )( 
            IActQJ71C24TEL3 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActDsidPropertyBit )( 
            IActQJ71C24TEL3 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActATCommand )( 
            IActQJ71C24TEL3 __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActATCommand )( 
            IActQJ71C24TEL3 __RPC_FAR * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActDialNumber )( 
            IActQJ71C24TEL3 __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActDialNumber )( 
            IActQJ71C24TEL3 __RPC_FAR * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActCallbackNumber )( 
            IActQJ71C24TEL3 __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActCallbackNumber )( 
            IActQJ71C24TEL3 __RPC_FAR * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActLineType )( 
            IActQJ71C24TEL3 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActLineType )( 
            IActQJ71C24TEL3 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActPassword )( 
            IActQJ71C24TEL3 __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActPassword )( 
            IActQJ71C24TEL3 __RPC_FAR * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActConnectionCDWaitTime )( 
            IActQJ71C24TEL3 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActConnectionCDWaitTime )( 
            IActQJ71C24TEL3 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActConnectionModemReportWaitTime )( 
            IActQJ71C24TEL3 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActConnectionModemReportWaitTime )( 
            IActQJ71C24TEL3 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActDisconnectionCDWaitTime )( 
            IActQJ71C24TEL3 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActDisconnectionCDWaitTime )( 
            IActQJ71C24TEL3 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActDisconnectionDelayTime )( 
            IActQJ71C24TEL3 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActDisconnectionDelayTime )( 
            IActQJ71C24TEL3 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActTransmissionDelayTime )( 
            IActQJ71C24TEL3 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActTransmissionDelayTime )( 
            IActQJ71C24TEL3 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActATCommandResponseWaitTime )( 
            IActQJ71C24TEL3 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActATCommandResponseWaitTime )( 
            IActQJ71C24TEL3 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActATCommandPasswordCancelRetryTimes )( 
            IActQJ71C24TEL3 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActATCommandPasswordCancelRetryTimes )( 
            IActQJ71C24TEL3 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActCallbackCancelWaitTime )( 
            IActQJ71C24TEL3 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActCallbackCancelWaitTime )( 
            IActQJ71C24TEL3 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActCallbackDelayTime )( 
            IActQJ71C24TEL3 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActCallbackDelayTime )( 
            IActQJ71C24TEL3 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActConnectWay )( 
            IActQJ71C24TEL3 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActConnectWay )( 
            IActQJ71C24TEL3 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActOutsideLineNumber )( 
            IActQJ71C24TEL3 __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActOutsideLineNumber )( 
            IActQJ71C24TEL3 __RPC_FAR * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActPasswordCancelResponseWaitTime )( 
            IActQJ71C24TEL3 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActPasswordCancelResponseWaitTime )( 
            IActQJ71C24TEL3 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActCallbackReceptionWaitingTimeOut )( 
            IActQJ71C24TEL3 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActCallbackReceptionWaitingTimeOut )( 
            IActQJ71C24TEL3 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        END_INTERFACE
    } IActQJ71C24TEL3Vtbl;

    interface IActQJ71C24TEL3
    {
        CONST_VTBL struct IActQJ71C24TEL3Vtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IActQJ71C24TEL3_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IActQJ71C24TEL3_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IActQJ71C24TEL3_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IActQJ71C24TEL3_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IActQJ71C24TEL3_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IActQJ71C24TEL3_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IActQJ71C24TEL3_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IActQJ71C24TEL3_Open(This,lplReturnCode)	\
    (This)->lpVtbl -> Open(This,lplReturnCode)

#define IActQJ71C24TEL3_Close(This,lplReturnCode)	\
    (This)->lpVtbl -> Close(This,lplReturnCode)

#define IActQJ71C24TEL3_GetDevice(This,szDevice,lplData,lplReturnCode)	\
    (This)->lpVtbl -> GetDevice(This,szDevice,lplData,lplReturnCode)

#define IActQJ71C24TEL3_SetDevice(This,szDevice,lData,lplReturnCode)	\
    (This)->lpVtbl -> SetDevice(This,szDevice,lData,lplReturnCode)

#define IActQJ71C24TEL3_ReadDeviceBlock(This,szDevice,lSize,lplData,lplReturnCode)	\
    (This)->lpVtbl -> ReadDeviceBlock(This,szDevice,lSize,lplData,lplReturnCode)

#define IActQJ71C24TEL3_WriteDeviceBlock(This,szDevice,lSize,lplData,lplReturnCode)	\
    (This)->lpVtbl -> WriteDeviceBlock(This,szDevice,lSize,lplData,lplReturnCode)

#define IActQJ71C24TEL3_ReadDeviceRandom(This,szDeviceList,lSize,lplData,lplReturnCode)	\
    (This)->lpVtbl -> ReadDeviceRandom(This,szDeviceList,lSize,lplData,lplReturnCode)

#define IActQJ71C24TEL3_WriteDeviceRandom(This,szDeviceList,lSize,lplData,lplReturnCode)	\
    (This)->lpVtbl -> WriteDeviceRandom(This,szDeviceList,lSize,lplData,lplReturnCode)

#define IActQJ71C24TEL3_ReadBuffer(This,lStartIO,lAddress,lReadSize,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> ReadBuffer(This,lStartIO,lAddress,lReadSize,lpsData,lplReturnCode)

#define IActQJ71C24TEL3_WriteBuffer(This,lStartIO,lAddress,lWriteSize,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> WriteBuffer(This,lStartIO,lAddress,lWriteSize,lpsData,lplReturnCode)

#define IActQJ71C24TEL3_GetClockData(This,lpsYear,lpsMonth,lpsDay,lpsDayOfWeek,lpsHour,lpsMinute,lpsSecond,lplReturnCode)	\
    (This)->lpVtbl -> GetClockData(This,lpsYear,lpsMonth,lpsDay,lpsDayOfWeek,lpsHour,lpsMinute,lpsSecond,lplReturnCode)

#define IActQJ71C24TEL3_SetClockData(This,sYear,sMonth,sDay,sDayOfWeek,sHour,sMinute,sSecond,lplReturnCode)	\
    (This)->lpVtbl -> SetClockData(This,sYear,sMonth,sDay,sDayOfWeek,sHour,sMinute,sSecond,lplReturnCode)

#define IActQJ71C24TEL3_GetCpuType(This,szCpuName,lplCpuCode,lplReturnCode)	\
    (This)->lpVtbl -> GetCpuType(This,szCpuName,lplCpuCode,lplReturnCode)

#define IActQJ71C24TEL3_SetCpuStatus(This,lOperation,lplReturnCode)	\
    (This)->lpVtbl -> SetCpuStatus(This,lOperation,lplReturnCode)

#define IActQJ71C24TEL3_CheckDeviceString(This,szDevice,lCheckType,lSize,lplDeviceType,lpszDeviceName,lplDeviceNumber,lplDeviceRadix,lplReturnCode)	\
    (This)->lpVtbl -> CheckDeviceString(This,szDevice,lCheckType,lSize,lplDeviceType,lpszDeviceName,lplDeviceNumber,lplDeviceRadix,lplReturnCode)

#define IActQJ71C24TEL3_EntryDeviceStatus(This,szDeviceList,lSize,lMonitorCycle,lplData,lplReturnCode)	\
    (This)->lpVtbl -> EntryDeviceStatus(This,szDeviceList,lSize,lMonitorCycle,lplData,lplReturnCode)

#define IActQJ71C24TEL3_FreeDeviceStatus(This,lplReturnCode)	\
    (This)->lpVtbl -> FreeDeviceStatus(This,lplReturnCode)

#define IActQJ71C24TEL3_ReadDeviceBlock2(This,szDevice,lSize,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> ReadDeviceBlock2(This,szDevice,lSize,lpsData,lplReturnCode)

#define IActQJ71C24TEL3_WriteDeviceBlock2(This,szDevice,lSize,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> WriteDeviceBlock2(This,szDevice,lSize,lpsData,lplReturnCode)

#define IActQJ71C24TEL3_ReadDeviceRandom2(This,szDeviceList,lSize,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> ReadDeviceRandom2(This,szDeviceList,lSize,lpsData,lplReturnCode)

#define IActQJ71C24TEL3_WriteDeviceRandom2(This,szDeviceList,lSize,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> WriteDeviceRandom2(This,szDeviceList,lSize,lpsData,lplReturnCode)

#define IActQJ71C24TEL3_GetDevice2(This,szDevice,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> GetDevice2(This,szDevice,lpsData,lplReturnCode)

#define IActQJ71C24TEL3_SetDevice2(This,szDevice,sData,lplReturnCode)	\
    (This)->lpVtbl -> SetDevice2(This,szDevice,sData,lplReturnCode)

#define IActQJ71C24TEL3_Connect(This,lplReturnCode)	\
    (This)->lpVtbl -> Connect(This,lplReturnCode)

#define IActQJ71C24TEL3_Disconnect(This,lplReturnCode)	\
    (This)->lpVtbl -> Disconnect(This,lplReturnCode)

#define IActQJ71C24TEL3_get_ActNetworkNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActNetworkNumber(This,pVal)

#define IActQJ71C24TEL3_put_ActNetworkNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActNetworkNumber(This,newVal)

#define IActQJ71C24TEL3_get_ActStationNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActStationNumber(This,pVal)

#define IActQJ71C24TEL3_put_ActStationNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActStationNumber(This,newVal)

#define IActQJ71C24TEL3_get_ActUnitNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActUnitNumber(This,pVal)

#define IActQJ71C24TEL3_put_ActUnitNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActUnitNumber(This,newVal)

#define IActQJ71C24TEL3_get_ActConnectUnitNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActConnectUnitNumber(This,pVal)

#define IActQJ71C24TEL3_put_ActConnectUnitNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActConnectUnitNumber(This,newVal)

#define IActQJ71C24TEL3_get_ActIONumber(This,pVal)	\
    (This)->lpVtbl -> get_ActIONumber(This,pVal)

#define IActQJ71C24TEL3_put_ActIONumber(This,newVal)	\
    (This)->lpVtbl -> put_ActIONumber(This,newVal)

#define IActQJ71C24TEL3_get_ActCpuType(This,pVal)	\
    (This)->lpVtbl -> get_ActCpuType(This,pVal)

#define IActQJ71C24TEL3_put_ActCpuType(This,newVal)	\
    (This)->lpVtbl -> put_ActCpuType(This,newVal)

#define IActQJ71C24TEL3_get_ActPortNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActPortNumber(This,pVal)

#define IActQJ71C24TEL3_put_ActPortNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActPortNumber(This,newVal)

#define IActQJ71C24TEL3_get_ActBaudRate(This,pVal)	\
    (This)->lpVtbl -> get_ActBaudRate(This,pVal)

#define IActQJ71C24TEL3_put_ActBaudRate(This,newVal)	\
    (This)->lpVtbl -> put_ActBaudRate(This,newVal)

#define IActQJ71C24TEL3_get_ActTimeOut(This,pVal)	\
    (This)->lpVtbl -> get_ActTimeOut(This,pVal)

#define IActQJ71C24TEL3_put_ActTimeOut(This,newVal)	\
    (This)->lpVtbl -> put_ActTimeOut(This,newVal)

#define IActQJ71C24TEL3_get_ActDestinationIONumber(This,pVal)	\
    (This)->lpVtbl -> get_ActDestinationIONumber(This,pVal)

#define IActQJ71C24TEL3_put_ActDestinationIONumber(This,newVal)	\
    (This)->lpVtbl -> put_ActDestinationIONumber(This,newVal)

#define IActQJ71C24TEL3_get_ActMultiDropChannelNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActMultiDropChannelNumber(This,pVal)

#define IActQJ71C24TEL3_put_ActMultiDropChannelNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActMultiDropChannelNumber(This,newVal)

#define IActQJ71C24TEL3_get_ActThroughNetworkType(This,pVal)	\
    (This)->lpVtbl -> get_ActThroughNetworkType(This,pVal)

#define IActQJ71C24TEL3_put_ActThroughNetworkType(This,newVal)	\
    (This)->lpVtbl -> put_ActThroughNetworkType(This,newVal)

#define IActQJ71C24TEL3_get_ActIntelligentPreferenceBit(This,pVal)	\
    (This)->lpVtbl -> get_ActIntelligentPreferenceBit(This,pVal)

#define IActQJ71C24TEL3_put_ActIntelligentPreferenceBit(This,newVal)	\
    (This)->lpVtbl -> put_ActIntelligentPreferenceBit(This,newVal)

#define IActQJ71C24TEL3_get_ActDidPropertyBit(This,pVal)	\
    (This)->lpVtbl -> get_ActDidPropertyBit(This,pVal)

#define IActQJ71C24TEL3_put_ActDidPropertyBit(This,newVal)	\
    (This)->lpVtbl -> put_ActDidPropertyBit(This,newVal)

#define IActQJ71C24TEL3_get_ActDsidPropertyBit(This,pVal)	\
    (This)->lpVtbl -> get_ActDsidPropertyBit(This,pVal)

#define IActQJ71C24TEL3_put_ActDsidPropertyBit(This,newVal)	\
    (This)->lpVtbl -> put_ActDsidPropertyBit(This,newVal)

#define IActQJ71C24TEL3_get_ActATCommand(This,pVal)	\
    (This)->lpVtbl -> get_ActATCommand(This,pVal)

#define IActQJ71C24TEL3_put_ActATCommand(This,newVal)	\
    (This)->lpVtbl -> put_ActATCommand(This,newVal)

#define IActQJ71C24TEL3_get_ActDialNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActDialNumber(This,pVal)

#define IActQJ71C24TEL3_put_ActDialNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActDialNumber(This,newVal)

#define IActQJ71C24TEL3_get_ActCallbackNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActCallbackNumber(This,pVal)

#define IActQJ71C24TEL3_put_ActCallbackNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActCallbackNumber(This,newVal)

#define IActQJ71C24TEL3_get_ActLineType(This,pVal)	\
    (This)->lpVtbl -> get_ActLineType(This,pVal)

#define IActQJ71C24TEL3_put_ActLineType(This,newVal)	\
    (This)->lpVtbl -> put_ActLineType(This,newVal)

#define IActQJ71C24TEL3_get_ActPassword(This,pVal)	\
    (This)->lpVtbl -> get_ActPassword(This,pVal)

#define IActQJ71C24TEL3_put_ActPassword(This,newVal)	\
    (This)->lpVtbl -> put_ActPassword(This,newVal)

#define IActQJ71C24TEL3_get_ActConnectionCDWaitTime(This,pVal)	\
    (This)->lpVtbl -> get_ActConnectionCDWaitTime(This,pVal)

#define IActQJ71C24TEL3_put_ActConnectionCDWaitTime(This,newVal)	\
    (This)->lpVtbl -> put_ActConnectionCDWaitTime(This,newVal)

#define IActQJ71C24TEL3_get_ActConnectionModemReportWaitTime(This,pVal)	\
    (This)->lpVtbl -> get_ActConnectionModemReportWaitTime(This,pVal)

#define IActQJ71C24TEL3_put_ActConnectionModemReportWaitTime(This,newVal)	\
    (This)->lpVtbl -> put_ActConnectionModemReportWaitTime(This,newVal)

#define IActQJ71C24TEL3_get_ActDisconnectionCDWaitTime(This,pVal)	\
    (This)->lpVtbl -> get_ActDisconnectionCDWaitTime(This,pVal)

#define IActQJ71C24TEL3_put_ActDisconnectionCDWaitTime(This,newVal)	\
    (This)->lpVtbl -> put_ActDisconnectionCDWaitTime(This,newVal)

#define IActQJ71C24TEL3_get_ActDisconnectionDelayTime(This,pVal)	\
    (This)->lpVtbl -> get_ActDisconnectionDelayTime(This,pVal)

#define IActQJ71C24TEL3_put_ActDisconnectionDelayTime(This,newVal)	\
    (This)->lpVtbl -> put_ActDisconnectionDelayTime(This,newVal)

#define IActQJ71C24TEL3_get_ActTransmissionDelayTime(This,pVal)	\
    (This)->lpVtbl -> get_ActTransmissionDelayTime(This,pVal)

#define IActQJ71C24TEL3_put_ActTransmissionDelayTime(This,newVal)	\
    (This)->lpVtbl -> put_ActTransmissionDelayTime(This,newVal)

#define IActQJ71C24TEL3_get_ActATCommandResponseWaitTime(This,pVal)	\
    (This)->lpVtbl -> get_ActATCommandResponseWaitTime(This,pVal)

#define IActQJ71C24TEL3_put_ActATCommandResponseWaitTime(This,newVal)	\
    (This)->lpVtbl -> put_ActATCommandResponseWaitTime(This,newVal)

#define IActQJ71C24TEL3_get_ActATCommandPasswordCancelRetryTimes(This,pVal)	\
    (This)->lpVtbl -> get_ActATCommandPasswordCancelRetryTimes(This,pVal)

#define IActQJ71C24TEL3_put_ActATCommandPasswordCancelRetryTimes(This,newVal)	\
    (This)->lpVtbl -> put_ActATCommandPasswordCancelRetryTimes(This,newVal)

#define IActQJ71C24TEL3_get_ActCallbackCancelWaitTime(This,pVal)	\
    (This)->lpVtbl -> get_ActCallbackCancelWaitTime(This,pVal)

#define IActQJ71C24TEL3_put_ActCallbackCancelWaitTime(This,newVal)	\
    (This)->lpVtbl -> put_ActCallbackCancelWaitTime(This,newVal)

#define IActQJ71C24TEL3_get_ActCallbackDelayTime(This,pVal)	\
    (This)->lpVtbl -> get_ActCallbackDelayTime(This,pVal)

#define IActQJ71C24TEL3_put_ActCallbackDelayTime(This,newVal)	\
    (This)->lpVtbl -> put_ActCallbackDelayTime(This,newVal)

#define IActQJ71C24TEL3_get_ActConnectWay(This,pVal)	\
    (This)->lpVtbl -> get_ActConnectWay(This,pVal)

#define IActQJ71C24TEL3_put_ActConnectWay(This,newVal)	\
    (This)->lpVtbl -> put_ActConnectWay(This,newVal)

#define IActQJ71C24TEL3_get_ActOutsideLineNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActOutsideLineNumber(This,pVal)

#define IActQJ71C24TEL3_put_ActOutsideLineNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActOutsideLineNumber(This,newVal)

#define IActQJ71C24TEL3_get_ActPasswordCancelResponseWaitTime(This,pVal)	\
    (This)->lpVtbl -> get_ActPasswordCancelResponseWaitTime(This,pVal)

#define IActQJ71C24TEL3_put_ActPasswordCancelResponseWaitTime(This,newVal)	\
    (This)->lpVtbl -> put_ActPasswordCancelResponseWaitTime(This,newVal)

#define IActQJ71C24TEL3_get_ActCallbackReceptionWaitingTimeOut(This,pVal)	\
    (This)->lpVtbl -> get_ActCallbackReceptionWaitingTimeOut(This,pVal)

#define IActQJ71C24TEL3_put_ActCallbackReceptionWaitingTimeOut(This,newVal)	\
    (This)->lpVtbl -> put_ActCallbackReceptionWaitingTimeOut(This,newVal)



#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IActQJ71C24TEL3_INTERFACE_DEFINED__ */


#ifndef __IActLJ71C24TEL_INTERFACE_DEFINED__
#define __IActLJ71C24TEL_INTERFACE_DEFINED__

/* interface IActLJ71C24TEL */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IActLJ71C24TEL;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("44012BC6-2F69-4FB4-B5D9-BF8B179256A7")
    IActLJ71C24TEL : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Open( 
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Close( 
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetDevice( 
            /* [string][in] */ BSTR szDevice,
            /* [out] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetDevice( 
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ReadDeviceBlock( 
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lSize,
            /* [size_is][out] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE WriteDeviceBlock( 
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lSize,
            /* [size_is][in] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ReadDeviceRandom( 
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG lSize,
            /* [size_is][out] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE WriteDeviceRandom( 
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG lSize,
            /* [size_is][in] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ReadBuffer( 
            /* [in] */ LONG lStartIO,
            /* [in] */ LONG lAddress,
            /* [in] */ LONG lSize,
            /* [size_is][out] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE WriteBuffer( 
            /* [in] */ LONG lStartIO,
            /* [in] */ LONG lAddress,
            /* [in] */ LONG lSize,
            /* [size_is][in] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetCpuType( 
            /* [string][out] */ BSTR __RPC_FAR *szCpuName,
            /* [out] */ LONG __RPC_FAR *lplCpuCode,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetCpuStatus( 
            /* [in] */ LONG lOperation,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetClockData( 
            /* [out] */ SHORT __RPC_FAR *lpsYear,
            /* [out] */ SHORT __RPC_FAR *lpsMonth,
            /* [out] */ SHORT __RPC_FAR *lpsDay,
            /* [out] */ SHORT __RPC_FAR *lpsDayOfWeek,
            /* [out] */ SHORT __RPC_FAR *lpsHour,
            /* [out] */ SHORT __RPC_FAR *lpsMinute,
            /* [out] */ SHORT __RPC_FAR *lpsSecond,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetClockData( 
            /* [in] */ SHORT sYear,
            /* [in] */ SHORT sMonth,
            /* [in] */ SHORT sDay,
            /* [in] */ SHORT sDayOfWeek,
            /* [in] */ SHORT sHour,
            /* [in] */ SHORT sMinute,
            /* [in] */ SHORT sSecond,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE EntryDeviceStatus( 
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG lSize,
            /* [in] */ LONG lMonitorCycle,
            /* [size_is][in] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE CheckDeviceString( 
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lCheckType,
            /* [in] */ LONG lSize,
            /* [out] */ LONG __RPC_FAR *lplDeviceType,
            /* [string][out] */ BSTR __RPC_FAR *lpszDeviceName,
            /* [out] */ LONG __RPC_FAR *lplDeviceNumber,
            /* [out] */ LONG __RPC_FAR *lplDeviceRadix,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE FreeDeviceStatus( 
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ReadDeviceBlock2( 
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lSize,
            /* [size_is][out] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE WriteDeviceBlock2( 
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lSize,
            /* [size_is][in] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ReadDeviceRandom2( 
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG lSize,
            /* [size_is][out] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE WriteDeviceRandom2( 
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG lSize,
            /* [size_is][in] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetDevice2( 
            /* [string][in] */ BSTR szDevice,
            /* [out] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetDevice2( 
            /* [in] */ BSTR szDevice,
            /* [in] */ SHORT sData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Connect( 
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Disconnect( 
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActNetworkNumber( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActNetworkNumber( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActStationNumber( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActStationNumber( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActUnitNumber( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActUnitNumber( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActConnectUnitNumber( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActConnectUnitNumber( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActIONumber( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActIONumber( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActCpuType( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActCpuType( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActPortNumber( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActPortNumber( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActBaudRate( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActBaudRate( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActTimeOut( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActTimeOut( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActDestinationIONumber( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActDestinationIONumber( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActMultiDropChannelNumber( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActMultiDropChannelNumber( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActThroughNetworkType( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActThroughNetworkType( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActIntelligentPreferenceBit( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActIntelligentPreferenceBit( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActDidPropertyBit( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActDidPropertyBit( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActDsidPropertyBit( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActDsidPropertyBit( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActPassword( 
            /* [retval][out] */ BSTR __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActPassword( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActConnectWay( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActConnectWay( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActATCommand( 
            /* [retval][out] */ BSTR __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActATCommand( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActDialNumber( 
            /* [retval][out] */ BSTR __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActDialNumber( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActOutsideLineNumber( 
            /* [retval][out] */ BSTR __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActOutsideLineNumber( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActCallbackNumber( 
            /* [retval][out] */ BSTR __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActCallbackNumber( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActLineType( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActLineType( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActConnectionCDWaitTime( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActConnectionCDWaitTime( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActConnectionModemReportWaitTime( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActConnectionModemReportWaitTime( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActDisconnectionCDWaitTime( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActDisconnectionCDWaitTime( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActDisconnectionDelayTime( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActDisconnectionDelayTime( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActTransmissionDelayTime( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActTransmissionDelayTime( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActATCommandResponseWaitTime( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActATCommandResponseWaitTime( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActPasswordCancelResponseWaitTime( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActPasswordCancelResponseWaitTime( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActATCommandPasswordCancelRetryTimes( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActATCommandPasswordCancelRetryTimes( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActCallbackCancelWaitTime( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActCallbackCancelWaitTime( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActCallbackDelayTime( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActCallbackDelayTime( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActCallbackReceptionWaitingTimeOut( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActCallbackReceptionWaitingTimeOut( 
            /* [in] */ long newVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IActLJ71C24TELVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IActLJ71C24TEL __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IActLJ71C24TEL __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IActLJ71C24TEL __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IActLJ71C24TEL __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IActLJ71C24TEL __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IActLJ71C24TEL __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IActLJ71C24TEL __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Open )( 
            IActLJ71C24TEL __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Close )( 
            IActLJ71C24TEL __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetDevice )( 
            IActLJ71C24TEL __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [out] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetDevice )( 
            IActLJ71C24TEL __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceBlock )( 
            IActLJ71C24TEL __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lSize,
            /* [size_is][out] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceBlock )( 
            IActLJ71C24TEL __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lSize,
            /* [size_is][in] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceRandom )( 
            IActLJ71C24TEL __RPC_FAR * This,
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG lSize,
            /* [size_is][out] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceRandom )( 
            IActLJ71C24TEL __RPC_FAR * This,
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG lSize,
            /* [size_is][in] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadBuffer )( 
            IActLJ71C24TEL __RPC_FAR * This,
            /* [in] */ LONG lStartIO,
            /* [in] */ LONG lAddress,
            /* [in] */ LONG lSize,
            /* [size_is][out] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteBuffer )( 
            IActLJ71C24TEL __RPC_FAR * This,
            /* [in] */ LONG lStartIO,
            /* [in] */ LONG lAddress,
            /* [in] */ LONG lSize,
            /* [size_is][in] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetCpuType )( 
            IActLJ71C24TEL __RPC_FAR * This,
            /* [string][out] */ BSTR __RPC_FAR *szCpuName,
            /* [out] */ LONG __RPC_FAR *lplCpuCode,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetCpuStatus )( 
            IActLJ71C24TEL __RPC_FAR * This,
            /* [in] */ LONG lOperation,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetClockData )( 
            IActLJ71C24TEL __RPC_FAR * This,
            /* [out] */ SHORT __RPC_FAR *lpsYear,
            /* [out] */ SHORT __RPC_FAR *lpsMonth,
            /* [out] */ SHORT __RPC_FAR *lpsDay,
            /* [out] */ SHORT __RPC_FAR *lpsDayOfWeek,
            /* [out] */ SHORT __RPC_FAR *lpsHour,
            /* [out] */ SHORT __RPC_FAR *lpsMinute,
            /* [out] */ SHORT __RPC_FAR *lpsSecond,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetClockData )( 
            IActLJ71C24TEL __RPC_FAR * This,
            /* [in] */ SHORT sYear,
            /* [in] */ SHORT sMonth,
            /* [in] */ SHORT sDay,
            /* [in] */ SHORT sDayOfWeek,
            /* [in] */ SHORT sHour,
            /* [in] */ SHORT sMinute,
            /* [in] */ SHORT sSecond,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *EntryDeviceStatus )( 
            IActLJ71C24TEL __RPC_FAR * This,
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG lSize,
            /* [in] */ LONG lMonitorCycle,
            /* [size_is][in] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CheckDeviceString )( 
            IActLJ71C24TEL __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lCheckType,
            /* [in] */ LONG lSize,
            /* [out] */ LONG __RPC_FAR *lplDeviceType,
            /* [string][out] */ BSTR __RPC_FAR *lpszDeviceName,
            /* [out] */ LONG __RPC_FAR *lplDeviceNumber,
            /* [out] */ LONG __RPC_FAR *lplDeviceRadix,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *FreeDeviceStatus )( 
            IActLJ71C24TEL __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceBlock2 )( 
            IActLJ71C24TEL __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lSize,
            /* [size_is][out] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceBlock2 )( 
            IActLJ71C24TEL __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lSize,
            /* [size_is][in] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceRandom2 )( 
            IActLJ71C24TEL __RPC_FAR * This,
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG lSize,
            /* [size_is][out] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceRandom2 )( 
            IActLJ71C24TEL __RPC_FAR * This,
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG lSize,
            /* [size_is][in] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetDevice2 )( 
            IActLJ71C24TEL __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [out] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetDevice2 )( 
            IActLJ71C24TEL __RPC_FAR * This,
            /* [in] */ BSTR szDevice,
            /* [in] */ SHORT sData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Connect )( 
            IActLJ71C24TEL __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Disconnect )( 
            IActLJ71C24TEL __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActNetworkNumber )( 
            IActLJ71C24TEL __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActNetworkNumber )( 
            IActLJ71C24TEL __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActStationNumber )( 
            IActLJ71C24TEL __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActStationNumber )( 
            IActLJ71C24TEL __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActUnitNumber )( 
            IActLJ71C24TEL __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActUnitNumber )( 
            IActLJ71C24TEL __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActConnectUnitNumber )( 
            IActLJ71C24TEL __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActConnectUnitNumber )( 
            IActLJ71C24TEL __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActIONumber )( 
            IActLJ71C24TEL __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActIONumber )( 
            IActLJ71C24TEL __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActCpuType )( 
            IActLJ71C24TEL __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActCpuType )( 
            IActLJ71C24TEL __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActPortNumber )( 
            IActLJ71C24TEL __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActPortNumber )( 
            IActLJ71C24TEL __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActBaudRate )( 
            IActLJ71C24TEL __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActBaudRate )( 
            IActLJ71C24TEL __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActTimeOut )( 
            IActLJ71C24TEL __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActTimeOut )( 
            IActLJ71C24TEL __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActDestinationIONumber )( 
            IActLJ71C24TEL __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActDestinationIONumber )( 
            IActLJ71C24TEL __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActMultiDropChannelNumber )( 
            IActLJ71C24TEL __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActMultiDropChannelNumber )( 
            IActLJ71C24TEL __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActThroughNetworkType )( 
            IActLJ71C24TEL __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActThroughNetworkType )( 
            IActLJ71C24TEL __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActIntelligentPreferenceBit )( 
            IActLJ71C24TEL __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActIntelligentPreferenceBit )( 
            IActLJ71C24TEL __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActDidPropertyBit )( 
            IActLJ71C24TEL __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActDidPropertyBit )( 
            IActLJ71C24TEL __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActDsidPropertyBit )( 
            IActLJ71C24TEL __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActDsidPropertyBit )( 
            IActLJ71C24TEL __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActPassword )( 
            IActLJ71C24TEL __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActPassword )( 
            IActLJ71C24TEL __RPC_FAR * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActConnectWay )( 
            IActLJ71C24TEL __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActConnectWay )( 
            IActLJ71C24TEL __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActATCommand )( 
            IActLJ71C24TEL __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActATCommand )( 
            IActLJ71C24TEL __RPC_FAR * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActDialNumber )( 
            IActLJ71C24TEL __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActDialNumber )( 
            IActLJ71C24TEL __RPC_FAR * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActOutsideLineNumber )( 
            IActLJ71C24TEL __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActOutsideLineNumber )( 
            IActLJ71C24TEL __RPC_FAR * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActCallbackNumber )( 
            IActLJ71C24TEL __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActCallbackNumber )( 
            IActLJ71C24TEL __RPC_FAR * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActLineType )( 
            IActLJ71C24TEL __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActLineType )( 
            IActLJ71C24TEL __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActConnectionCDWaitTime )( 
            IActLJ71C24TEL __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActConnectionCDWaitTime )( 
            IActLJ71C24TEL __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActConnectionModemReportWaitTime )( 
            IActLJ71C24TEL __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActConnectionModemReportWaitTime )( 
            IActLJ71C24TEL __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActDisconnectionCDWaitTime )( 
            IActLJ71C24TEL __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActDisconnectionCDWaitTime )( 
            IActLJ71C24TEL __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActDisconnectionDelayTime )( 
            IActLJ71C24TEL __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActDisconnectionDelayTime )( 
            IActLJ71C24TEL __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActTransmissionDelayTime )( 
            IActLJ71C24TEL __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActTransmissionDelayTime )( 
            IActLJ71C24TEL __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActATCommandResponseWaitTime )( 
            IActLJ71C24TEL __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActATCommandResponseWaitTime )( 
            IActLJ71C24TEL __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActPasswordCancelResponseWaitTime )( 
            IActLJ71C24TEL __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActPasswordCancelResponseWaitTime )( 
            IActLJ71C24TEL __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActATCommandPasswordCancelRetryTimes )( 
            IActLJ71C24TEL __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActATCommandPasswordCancelRetryTimes )( 
            IActLJ71C24TEL __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActCallbackCancelWaitTime )( 
            IActLJ71C24TEL __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActCallbackCancelWaitTime )( 
            IActLJ71C24TEL __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActCallbackDelayTime )( 
            IActLJ71C24TEL __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActCallbackDelayTime )( 
            IActLJ71C24TEL __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActCallbackReceptionWaitingTimeOut )( 
            IActLJ71C24TEL __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActCallbackReceptionWaitingTimeOut )( 
            IActLJ71C24TEL __RPC_FAR * This,
            /* [in] */ long newVal);
        
        END_INTERFACE
    } IActLJ71C24TELVtbl;

    interface IActLJ71C24TEL
    {
        CONST_VTBL struct IActLJ71C24TELVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IActLJ71C24TEL_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IActLJ71C24TEL_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IActLJ71C24TEL_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IActLJ71C24TEL_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IActLJ71C24TEL_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IActLJ71C24TEL_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IActLJ71C24TEL_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IActLJ71C24TEL_Open(This,lplReturnCode)	\
    (This)->lpVtbl -> Open(This,lplReturnCode)

#define IActLJ71C24TEL_Close(This,lplReturnCode)	\
    (This)->lpVtbl -> Close(This,lplReturnCode)

#define IActLJ71C24TEL_GetDevice(This,szDevice,lplData,lplReturnCode)	\
    (This)->lpVtbl -> GetDevice(This,szDevice,lplData,lplReturnCode)

#define IActLJ71C24TEL_SetDevice(This,szDevice,lData,lplReturnCode)	\
    (This)->lpVtbl -> SetDevice(This,szDevice,lData,lplReturnCode)

#define IActLJ71C24TEL_ReadDeviceBlock(This,szDevice,lSize,lplData,lplReturnCode)	\
    (This)->lpVtbl -> ReadDeviceBlock(This,szDevice,lSize,lplData,lplReturnCode)

#define IActLJ71C24TEL_WriteDeviceBlock(This,szDevice,lSize,lplData,lplReturnCode)	\
    (This)->lpVtbl -> WriteDeviceBlock(This,szDevice,lSize,lplData,lplReturnCode)

#define IActLJ71C24TEL_ReadDeviceRandom(This,szDeviceList,lSize,lplData,lplReturnCode)	\
    (This)->lpVtbl -> ReadDeviceRandom(This,szDeviceList,lSize,lplData,lplReturnCode)

#define IActLJ71C24TEL_WriteDeviceRandom(This,szDeviceList,lSize,lplData,lplReturnCode)	\
    (This)->lpVtbl -> WriteDeviceRandom(This,szDeviceList,lSize,lplData,lplReturnCode)

#define IActLJ71C24TEL_ReadBuffer(This,lStartIO,lAddress,lSize,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> ReadBuffer(This,lStartIO,lAddress,lSize,lpsData,lplReturnCode)

#define IActLJ71C24TEL_WriteBuffer(This,lStartIO,lAddress,lSize,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> WriteBuffer(This,lStartIO,lAddress,lSize,lpsData,lplReturnCode)

#define IActLJ71C24TEL_GetCpuType(This,szCpuName,lplCpuCode,lplReturnCode)	\
    (This)->lpVtbl -> GetCpuType(This,szCpuName,lplCpuCode,lplReturnCode)

#define IActLJ71C24TEL_SetCpuStatus(This,lOperation,lplReturnCode)	\
    (This)->lpVtbl -> SetCpuStatus(This,lOperation,lplReturnCode)

#define IActLJ71C24TEL_GetClockData(This,lpsYear,lpsMonth,lpsDay,lpsDayOfWeek,lpsHour,lpsMinute,lpsSecond,lplReturnCode)	\
    (This)->lpVtbl -> GetClockData(This,lpsYear,lpsMonth,lpsDay,lpsDayOfWeek,lpsHour,lpsMinute,lpsSecond,lplReturnCode)

#define IActLJ71C24TEL_SetClockData(This,sYear,sMonth,sDay,sDayOfWeek,sHour,sMinute,sSecond,lplReturnCode)	\
    (This)->lpVtbl -> SetClockData(This,sYear,sMonth,sDay,sDayOfWeek,sHour,sMinute,sSecond,lplReturnCode)

#define IActLJ71C24TEL_EntryDeviceStatus(This,szDeviceList,lSize,lMonitorCycle,lplData,lplReturnCode)	\
    (This)->lpVtbl -> EntryDeviceStatus(This,szDeviceList,lSize,lMonitorCycle,lplData,lplReturnCode)

#define IActLJ71C24TEL_CheckDeviceString(This,szDevice,lCheckType,lSize,lplDeviceType,lpszDeviceName,lplDeviceNumber,lplDeviceRadix,lplReturnCode)	\
    (This)->lpVtbl -> CheckDeviceString(This,szDevice,lCheckType,lSize,lplDeviceType,lpszDeviceName,lplDeviceNumber,lplDeviceRadix,lplReturnCode)

#define IActLJ71C24TEL_FreeDeviceStatus(This,lplReturnCode)	\
    (This)->lpVtbl -> FreeDeviceStatus(This,lplReturnCode)

#define IActLJ71C24TEL_ReadDeviceBlock2(This,szDevice,lSize,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> ReadDeviceBlock2(This,szDevice,lSize,lpsData,lplReturnCode)

#define IActLJ71C24TEL_WriteDeviceBlock2(This,szDevice,lSize,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> WriteDeviceBlock2(This,szDevice,lSize,lpsData,lplReturnCode)

#define IActLJ71C24TEL_ReadDeviceRandom2(This,szDeviceList,lSize,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> ReadDeviceRandom2(This,szDeviceList,lSize,lpsData,lplReturnCode)

#define IActLJ71C24TEL_WriteDeviceRandom2(This,szDeviceList,lSize,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> WriteDeviceRandom2(This,szDeviceList,lSize,lpsData,lplReturnCode)

#define IActLJ71C24TEL_GetDevice2(This,szDevice,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> GetDevice2(This,szDevice,lpsData,lplReturnCode)

#define IActLJ71C24TEL_SetDevice2(This,szDevice,sData,lplReturnCode)	\
    (This)->lpVtbl -> SetDevice2(This,szDevice,sData,lplReturnCode)

#define IActLJ71C24TEL_Connect(This,lplReturnCode)	\
    (This)->lpVtbl -> Connect(This,lplReturnCode)

#define IActLJ71C24TEL_Disconnect(This,lplReturnCode)	\
    (This)->lpVtbl -> Disconnect(This,lplReturnCode)

#define IActLJ71C24TEL_get_ActNetworkNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActNetworkNumber(This,pVal)

#define IActLJ71C24TEL_put_ActNetworkNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActNetworkNumber(This,newVal)

#define IActLJ71C24TEL_get_ActStationNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActStationNumber(This,pVal)

#define IActLJ71C24TEL_put_ActStationNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActStationNumber(This,newVal)

#define IActLJ71C24TEL_get_ActUnitNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActUnitNumber(This,pVal)

#define IActLJ71C24TEL_put_ActUnitNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActUnitNumber(This,newVal)

#define IActLJ71C24TEL_get_ActConnectUnitNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActConnectUnitNumber(This,pVal)

#define IActLJ71C24TEL_put_ActConnectUnitNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActConnectUnitNumber(This,newVal)

#define IActLJ71C24TEL_get_ActIONumber(This,pVal)	\
    (This)->lpVtbl -> get_ActIONumber(This,pVal)

#define IActLJ71C24TEL_put_ActIONumber(This,newVal)	\
    (This)->lpVtbl -> put_ActIONumber(This,newVal)

#define IActLJ71C24TEL_get_ActCpuType(This,pVal)	\
    (This)->lpVtbl -> get_ActCpuType(This,pVal)

#define IActLJ71C24TEL_put_ActCpuType(This,newVal)	\
    (This)->lpVtbl -> put_ActCpuType(This,newVal)

#define IActLJ71C24TEL_get_ActPortNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActPortNumber(This,pVal)

#define IActLJ71C24TEL_put_ActPortNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActPortNumber(This,newVal)

#define IActLJ71C24TEL_get_ActBaudRate(This,pVal)	\
    (This)->lpVtbl -> get_ActBaudRate(This,pVal)

#define IActLJ71C24TEL_put_ActBaudRate(This,newVal)	\
    (This)->lpVtbl -> put_ActBaudRate(This,newVal)

#define IActLJ71C24TEL_get_ActTimeOut(This,pVal)	\
    (This)->lpVtbl -> get_ActTimeOut(This,pVal)

#define IActLJ71C24TEL_put_ActTimeOut(This,newVal)	\
    (This)->lpVtbl -> put_ActTimeOut(This,newVal)

#define IActLJ71C24TEL_get_ActDestinationIONumber(This,pVal)	\
    (This)->lpVtbl -> get_ActDestinationIONumber(This,pVal)

#define IActLJ71C24TEL_put_ActDestinationIONumber(This,newVal)	\
    (This)->lpVtbl -> put_ActDestinationIONumber(This,newVal)

#define IActLJ71C24TEL_get_ActMultiDropChannelNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActMultiDropChannelNumber(This,pVal)

#define IActLJ71C24TEL_put_ActMultiDropChannelNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActMultiDropChannelNumber(This,newVal)

#define IActLJ71C24TEL_get_ActThroughNetworkType(This,pVal)	\
    (This)->lpVtbl -> get_ActThroughNetworkType(This,pVal)

#define IActLJ71C24TEL_put_ActThroughNetworkType(This,newVal)	\
    (This)->lpVtbl -> put_ActThroughNetworkType(This,newVal)

#define IActLJ71C24TEL_get_ActIntelligentPreferenceBit(This,pVal)	\
    (This)->lpVtbl -> get_ActIntelligentPreferenceBit(This,pVal)

#define IActLJ71C24TEL_put_ActIntelligentPreferenceBit(This,newVal)	\
    (This)->lpVtbl -> put_ActIntelligentPreferenceBit(This,newVal)

#define IActLJ71C24TEL_get_ActDidPropertyBit(This,pVal)	\
    (This)->lpVtbl -> get_ActDidPropertyBit(This,pVal)

#define IActLJ71C24TEL_put_ActDidPropertyBit(This,newVal)	\
    (This)->lpVtbl -> put_ActDidPropertyBit(This,newVal)

#define IActLJ71C24TEL_get_ActDsidPropertyBit(This,pVal)	\
    (This)->lpVtbl -> get_ActDsidPropertyBit(This,pVal)

#define IActLJ71C24TEL_put_ActDsidPropertyBit(This,newVal)	\
    (This)->lpVtbl -> put_ActDsidPropertyBit(This,newVal)

#define IActLJ71C24TEL_get_ActPassword(This,pVal)	\
    (This)->lpVtbl -> get_ActPassword(This,pVal)

#define IActLJ71C24TEL_put_ActPassword(This,newVal)	\
    (This)->lpVtbl -> put_ActPassword(This,newVal)

#define IActLJ71C24TEL_get_ActConnectWay(This,pVal)	\
    (This)->lpVtbl -> get_ActConnectWay(This,pVal)

#define IActLJ71C24TEL_put_ActConnectWay(This,newVal)	\
    (This)->lpVtbl -> put_ActConnectWay(This,newVal)

#define IActLJ71C24TEL_get_ActATCommand(This,pVal)	\
    (This)->lpVtbl -> get_ActATCommand(This,pVal)

#define IActLJ71C24TEL_put_ActATCommand(This,newVal)	\
    (This)->lpVtbl -> put_ActATCommand(This,newVal)

#define IActLJ71C24TEL_get_ActDialNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActDialNumber(This,pVal)

#define IActLJ71C24TEL_put_ActDialNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActDialNumber(This,newVal)

#define IActLJ71C24TEL_get_ActOutsideLineNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActOutsideLineNumber(This,pVal)

#define IActLJ71C24TEL_put_ActOutsideLineNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActOutsideLineNumber(This,newVal)

#define IActLJ71C24TEL_get_ActCallbackNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActCallbackNumber(This,pVal)

#define IActLJ71C24TEL_put_ActCallbackNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActCallbackNumber(This,newVal)

#define IActLJ71C24TEL_get_ActLineType(This,pVal)	\
    (This)->lpVtbl -> get_ActLineType(This,pVal)

#define IActLJ71C24TEL_put_ActLineType(This,newVal)	\
    (This)->lpVtbl -> put_ActLineType(This,newVal)

#define IActLJ71C24TEL_get_ActConnectionCDWaitTime(This,pVal)	\
    (This)->lpVtbl -> get_ActConnectionCDWaitTime(This,pVal)

#define IActLJ71C24TEL_put_ActConnectionCDWaitTime(This,newVal)	\
    (This)->lpVtbl -> put_ActConnectionCDWaitTime(This,newVal)

#define IActLJ71C24TEL_get_ActConnectionModemReportWaitTime(This,pVal)	\
    (This)->lpVtbl -> get_ActConnectionModemReportWaitTime(This,pVal)

#define IActLJ71C24TEL_put_ActConnectionModemReportWaitTime(This,newVal)	\
    (This)->lpVtbl -> put_ActConnectionModemReportWaitTime(This,newVal)

#define IActLJ71C24TEL_get_ActDisconnectionCDWaitTime(This,pVal)	\
    (This)->lpVtbl -> get_ActDisconnectionCDWaitTime(This,pVal)

#define IActLJ71C24TEL_put_ActDisconnectionCDWaitTime(This,newVal)	\
    (This)->lpVtbl -> put_ActDisconnectionCDWaitTime(This,newVal)

#define IActLJ71C24TEL_get_ActDisconnectionDelayTime(This,pVal)	\
    (This)->lpVtbl -> get_ActDisconnectionDelayTime(This,pVal)

#define IActLJ71C24TEL_put_ActDisconnectionDelayTime(This,newVal)	\
    (This)->lpVtbl -> put_ActDisconnectionDelayTime(This,newVal)

#define IActLJ71C24TEL_get_ActTransmissionDelayTime(This,pVal)	\
    (This)->lpVtbl -> get_ActTransmissionDelayTime(This,pVal)

#define IActLJ71C24TEL_put_ActTransmissionDelayTime(This,newVal)	\
    (This)->lpVtbl -> put_ActTransmissionDelayTime(This,newVal)

#define IActLJ71C24TEL_get_ActATCommandResponseWaitTime(This,pVal)	\
    (This)->lpVtbl -> get_ActATCommandResponseWaitTime(This,pVal)

#define IActLJ71C24TEL_put_ActATCommandResponseWaitTime(This,newVal)	\
    (This)->lpVtbl -> put_ActATCommandResponseWaitTime(This,newVal)

#define IActLJ71C24TEL_get_ActPasswordCancelResponseWaitTime(This,pVal)	\
    (This)->lpVtbl -> get_ActPasswordCancelResponseWaitTime(This,pVal)

#define IActLJ71C24TEL_put_ActPasswordCancelResponseWaitTime(This,newVal)	\
    (This)->lpVtbl -> put_ActPasswordCancelResponseWaitTime(This,newVal)

#define IActLJ71C24TEL_get_ActATCommandPasswordCancelRetryTimes(This,pVal)	\
    (This)->lpVtbl -> get_ActATCommandPasswordCancelRetryTimes(This,pVal)

#define IActLJ71C24TEL_put_ActATCommandPasswordCancelRetryTimes(This,newVal)	\
    (This)->lpVtbl -> put_ActATCommandPasswordCancelRetryTimes(This,newVal)

#define IActLJ71C24TEL_get_ActCallbackCancelWaitTime(This,pVal)	\
    (This)->lpVtbl -> get_ActCallbackCancelWaitTime(This,pVal)

#define IActLJ71C24TEL_put_ActCallbackCancelWaitTime(This,newVal)	\
    (This)->lpVtbl -> put_ActCallbackCancelWaitTime(This,newVal)

#define IActLJ71C24TEL_get_ActCallbackDelayTime(This,pVal)	\
    (This)->lpVtbl -> get_ActCallbackDelayTime(This,pVal)

#define IActLJ71C24TEL_put_ActCallbackDelayTime(This,newVal)	\
    (This)->lpVtbl -> put_ActCallbackDelayTime(This,newVal)

#define IActLJ71C24TEL_get_ActCallbackReceptionWaitingTimeOut(This,pVal)	\
    (This)->lpVtbl -> get_ActCallbackReceptionWaitingTimeOut(This,pVal)

#define IActLJ71C24TEL_put_ActCallbackReceptionWaitingTimeOut(This,newVal)	\
    (This)->lpVtbl -> put_ActCallbackReceptionWaitingTimeOut(This,newVal)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActLJ71C24TEL_Open_Proxy( 
    IActLJ71C24TEL __RPC_FAR * This,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActLJ71C24TEL_Open_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActLJ71C24TEL_Close_Proxy( 
    IActLJ71C24TEL __RPC_FAR * This,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActLJ71C24TEL_Close_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActLJ71C24TEL_GetDevice_Proxy( 
    IActLJ71C24TEL __RPC_FAR * This,
    /* [string][in] */ BSTR szDevice,
    /* [out] */ LONG __RPC_FAR *lplData,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActLJ71C24TEL_GetDevice_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActLJ71C24TEL_SetDevice_Proxy( 
    IActLJ71C24TEL __RPC_FAR * This,
    /* [string][in] */ BSTR szDevice,
    /* [in] */ LONG lData,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActLJ71C24TEL_SetDevice_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActLJ71C24TEL_ReadDeviceBlock_Proxy( 
    IActLJ71C24TEL __RPC_FAR * This,
    /* [string][in] */ BSTR szDevice,
    /* [in] */ LONG lSize,
    /* [size_is][out] */ LONG __RPC_FAR *lplData,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActLJ71C24TEL_ReadDeviceBlock_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActLJ71C24TEL_WriteDeviceBlock_Proxy( 
    IActLJ71C24TEL __RPC_FAR * This,
    /* [string][in] */ BSTR szDevice,
    /* [in] */ LONG lSize,
    /* [size_is][in] */ LONG __RPC_FAR *lplData,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActLJ71C24TEL_WriteDeviceBlock_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActLJ71C24TEL_ReadDeviceRandom_Proxy( 
    IActLJ71C24TEL __RPC_FAR * This,
    /* [string][in] */ BSTR szDeviceList,
    /* [in] */ LONG lSize,
    /* [size_is][out] */ LONG __RPC_FAR *lplData,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActLJ71C24TEL_ReadDeviceRandom_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActLJ71C24TEL_WriteDeviceRandom_Proxy( 
    IActLJ71C24TEL __RPC_FAR * This,
    /* [string][in] */ BSTR szDeviceList,
    /* [in] */ LONG lSize,
    /* [size_is][in] */ LONG __RPC_FAR *lplData,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActLJ71C24TEL_WriteDeviceRandom_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActLJ71C24TEL_ReadBuffer_Proxy( 
    IActLJ71C24TEL __RPC_FAR * This,
    /* [in] */ LONG lStartIO,
    /* [in] */ LONG lAddress,
    /* [in] */ LONG lSize,
    /* [size_is][out] */ SHORT __RPC_FAR *lpsData,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActLJ71C24TEL_ReadBuffer_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActLJ71C24TEL_WriteBuffer_Proxy( 
    IActLJ71C24TEL __RPC_FAR * This,
    /* [in] */ LONG lStartIO,
    /* [in] */ LONG lAddress,
    /* [in] */ LONG lSize,
    /* [size_is][in] */ SHORT __RPC_FAR *lpsData,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActLJ71C24TEL_WriteBuffer_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActLJ71C24TEL_GetCpuType_Proxy( 
    IActLJ71C24TEL __RPC_FAR * This,
    /* [string][out] */ BSTR __RPC_FAR *szCpuName,
    /* [out] */ LONG __RPC_FAR *lplCpuCode,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActLJ71C24TEL_GetCpuType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActLJ71C24TEL_SetCpuStatus_Proxy( 
    IActLJ71C24TEL __RPC_FAR * This,
    /* [in] */ LONG lOperation,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActLJ71C24TEL_SetCpuStatus_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActLJ71C24TEL_GetClockData_Proxy( 
    IActLJ71C24TEL __RPC_FAR * This,
    /* [out] */ SHORT __RPC_FAR *lpsYear,
    /* [out] */ SHORT __RPC_FAR *lpsMonth,
    /* [out] */ SHORT __RPC_FAR *lpsDay,
    /* [out] */ SHORT __RPC_FAR *lpsDayOfWeek,
    /* [out] */ SHORT __RPC_FAR *lpsHour,
    /* [out] */ SHORT __RPC_FAR *lpsMinute,
    /* [out] */ SHORT __RPC_FAR *lpsSecond,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActLJ71C24TEL_GetClockData_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActLJ71C24TEL_SetClockData_Proxy( 
    IActLJ71C24TEL __RPC_FAR * This,
    /* [in] */ SHORT sYear,
    /* [in] */ SHORT sMonth,
    /* [in] */ SHORT sDay,
    /* [in] */ SHORT sDayOfWeek,
    /* [in] */ SHORT sHour,
    /* [in] */ SHORT sMinute,
    /* [in] */ SHORT sSecond,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActLJ71C24TEL_SetClockData_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActLJ71C24TEL_EntryDeviceStatus_Proxy( 
    IActLJ71C24TEL __RPC_FAR * This,
    /* [string][in] */ BSTR szDeviceList,
    /* [in] */ LONG lSize,
    /* [in] */ LONG lMonitorCycle,
    /* [size_is][in] */ LONG __RPC_FAR *lplData,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActLJ71C24TEL_EntryDeviceStatus_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActLJ71C24TEL_CheckDeviceString_Proxy( 
    IActLJ71C24TEL __RPC_FAR * This,
    /* [string][in] */ BSTR szDevice,
    /* [in] */ LONG lCheckType,
    /* [in] */ LONG lSize,
    /* [out] */ LONG __RPC_FAR *lplDeviceType,
    /* [string][out] */ BSTR __RPC_FAR *lpszDeviceName,
    /* [out] */ LONG __RPC_FAR *lplDeviceNumber,
    /* [out] */ LONG __RPC_FAR *lplDeviceRadix,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActLJ71C24TEL_CheckDeviceString_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActLJ71C24TEL_FreeDeviceStatus_Proxy( 
    IActLJ71C24TEL __RPC_FAR * This,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActLJ71C24TEL_FreeDeviceStatus_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActLJ71C24TEL_ReadDeviceBlock2_Proxy( 
    IActLJ71C24TEL __RPC_FAR * This,
    /* [string][in] */ BSTR szDevice,
    /* [in] */ LONG lSize,
    /* [size_is][out] */ SHORT __RPC_FAR *lpsData,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActLJ71C24TEL_ReadDeviceBlock2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActLJ71C24TEL_WriteDeviceBlock2_Proxy( 
    IActLJ71C24TEL __RPC_FAR * This,
    /* [string][in] */ BSTR szDevice,
    /* [in] */ LONG lSize,
    /* [size_is][in] */ SHORT __RPC_FAR *lpsData,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActLJ71C24TEL_WriteDeviceBlock2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActLJ71C24TEL_ReadDeviceRandom2_Proxy( 
    IActLJ71C24TEL __RPC_FAR * This,
    /* [string][in] */ BSTR szDeviceList,
    /* [in] */ LONG lSize,
    /* [size_is][out] */ SHORT __RPC_FAR *lpsData,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActLJ71C24TEL_ReadDeviceRandom2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActLJ71C24TEL_WriteDeviceRandom2_Proxy( 
    IActLJ71C24TEL __RPC_FAR * This,
    /* [string][in] */ BSTR szDeviceList,
    /* [in] */ LONG lSize,
    /* [size_is][in] */ SHORT __RPC_FAR *lpsData,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActLJ71C24TEL_WriteDeviceRandom2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActLJ71C24TEL_GetDevice2_Proxy( 
    IActLJ71C24TEL __RPC_FAR * This,
    /* [string][in] */ BSTR szDevice,
    /* [out] */ SHORT __RPC_FAR *lpsData,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActLJ71C24TEL_GetDevice2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActLJ71C24TEL_SetDevice2_Proxy( 
    IActLJ71C24TEL __RPC_FAR * This,
    /* [in] */ BSTR szDevice,
    /* [in] */ SHORT sData,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActLJ71C24TEL_SetDevice2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActLJ71C24TEL_Connect_Proxy( 
    IActLJ71C24TEL __RPC_FAR * This,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActLJ71C24TEL_Connect_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActLJ71C24TEL_Disconnect_Proxy( 
    IActLJ71C24TEL __RPC_FAR * This,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActLJ71C24TEL_Disconnect_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActLJ71C24TEL_get_ActNetworkNumber_Proxy( 
    IActLJ71C24TEL __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IActLJ71C24TEL_get_ActNetworkNumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActLJ71C24TEL_put_ActNetworkNumber_Proxy( 
    IActLJ71C24TEL __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB IActLJ71C24TEL_put_ActNetworkNumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActLJ71C24TEL_get_ActStationNumber_Proxy( 
    IActLJ71C24TEL __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IActLJ71C24TEL_get_ActStationNumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActLJ71C24TEL_put_ActStationNumber_Proxy( 
    IActLJ71C24TEL __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB IActLJ71C24TEL_put_ActStationNumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActLJ71C24TEL_get_ActUnitNumber_Proxy( 
    IActLJ71C24TEL __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IActLJ71C24TEL_get_ActUnitNumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActLJ71C24TEL_put_ActUnitNumber_Proxy( 
    IActLJ71C24TEL __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB IActLJ71C24TEL_put_ActUnitNumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActLJ71C24TEL_get_ActConnectUnitNumber_Proxy( 
    IActLJ71C24TEL __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IActLJ71C24TEL_get_ActConnectUnitNumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActLJ71C24TEL_put_ActConnectUnitNumber_Proxy( 
    IActLJ71C24TEL __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB IActLJ71C24TEL_put_ActConnectUnitNumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActLJ71C24TEL_get_ActIONumber_Proxy( 
    IActLJ71C24TEL __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IActLJ71C24TEL_get_ActIONumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActLJ71C24TEL_put_ActIONumber_Proxy( 
    IActLJ71C24TEL __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB IActLJ71C24TEL_put_ActIONumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActLJ71C24TEL_get_ActCpuType_Proxy( 
    IActLJ71C24TEL __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IActLJ71C24TEL_get_ActCpuType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActLJ71C24TEL_put_ActCpuType_Proxy( 
    IActLJ71C24TEL __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB IActLJ71C24TEL_put_ActCpuType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActLJ71C24TEL_get_ActPortNumber_Proxy( 
    IActLJ71C24TEL __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IActLJ71C24TEL_get_ActPortNumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActLJ71C24TEL_put_ActPortNumber_Proxy( 
    IActLJ71C24TEL __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB IActLJ71C24TEL_put_ActPortNumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActLJ71C24TEL_get_ActBaudRate_Proxy( 
    IActLJ71C24TEL __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IActLJ71C24TEL_get_ActBaudRate_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActLJ71C24TEL_put_ActBaudRate_Proxy( 
    IActLJ71C24TEL __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB IActLJ71C24TEL_put_ActBaudRate_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActLJ71C24TEL_get_ActTimeOut_Proxy( 
    IActLJ71C24TEL __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IActLJ71C24TEL_get_ActTimeOut_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActLJ71C24TEL_put_ActTimeOut_Proxy( 
    IActLJ71C24TEL __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB IActLJ71C24TEL_put_ActTimeOut_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActLJ71C24TEL_get_ActDestinationIONumber_Proxy( 
    IActLJ71C24TEL __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IActLJ71C24TEL_get_ActDestinationIONumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActLJ71C24TEL_put_ActDestinationIONumber_Proxy( 
    IActLJ71C24TEL __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB IActLJ71C24TEL_put_ActDestinationIONumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActLJ71C24TEL_get_ActMultiDropChannelNumber_Proxy( 
    IActLJ71C24TEL __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IActLJ71C24TEL_get_ActMultiDropChannelNumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActLJ71C24TEL_put_ActMultiDropChannelNumber_Proxy( 
    IActLJ71C24TEL __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB IActLJ71C24TEL_put_ActMultiDropChannelNumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActLJ71C24TEL_get_ActThroughNetworkType_Proxy( 
    IActLJ71C24TEL __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IActLJ71C24TEL_get_ActThroughNetworkType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActLJ71C24TEL_put_ActThroughNetworkType_Proxy( 
    IActLJ71C24TEL __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB IActLJ71C24TEL_put_ActThroughNetworkType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActLJ71C24TEL_get_ActIntelligentPreferenceBit_Proxy( 
    IActLJ71C24TEL __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IActLJ71C24TEL_get_ActIntelligentPreferenceBit_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActLJ71C24TEL_put_ActIntelligentPreferenceBit_Proxy( 
    IActLJ71C24TEL __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB IActLJ71C24TEL_put_ActIntelligentPreferenceBit_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActLJ71C24TEL_get_ActDidPropertyBit_Proxy( 
    IActLJ71C24TEL __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IActLJ71C24TEL_get_ActDidPropertyBit_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActLJ71C24TEL_put_ActDidPropertyBit_Proxy( 
    IActLJ71C24TEL __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB IActLJ71C24TEL_put_ActDidPropertyBit_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActLJ71C24TEL_get_ActDsidPropertyBit_Proxy( 
    IActLJ71C24TEL __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IActLJ71C24TEL_get_ActDsidPropertyBit_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActLJ71C24TEL_put_ActDsidPropertyBit_Proxy( 
    IActLJ71C24TEL __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB IActLJ71C24TEL_put_ActDsidPropertyBit_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActLJ71C24TEL_get_ActPassword_Proxy( 
    IActLJ71C24TEL __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *pVal);


void __RPC_STUB IActLJ71C24TEL_get_ActPassword_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActLJ71C24TEL_put_ActPassword_Proxy( 
    IActLJ71C24TEL __RPC_FAR * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB IActLJ71C24TEL_put_ActPassword_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActLJ71C24TEL_get_ActConnectWay_Proxy( 
    IActLJ71C24TEL __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IActLJ71C24TEL_get_ActConnectWay_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActLJ71C24TEL_put_ActConnectWay_Proxy( 
    IActLJ71C24TEL __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB IActLJ71C24TEL_put_ActConnectWay_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActLJ71C24TEL_get_ActATCommand_Proxy( 
    IActLJ71C24TEL __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *pVal);


void __RPC_STUB IActLJ71C24TEL_get_ActATCommand_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActLJ71C24TEL_put_ActATCommand_Proxy( 
    IActLJ71C24TEL __RPC_FAR * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB IActLJ71C24TEL_put_ActATCommand_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActLJ71C24TEL_get_ActDialNumber_Proxy( 
    IActLJ71C24TEL __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *pVal);


void __RPC_STUB IActLJ71C24TEL_get_ActDialNumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActLJ71C24TEL_put_ActDialNumber_Proxy( 
    IActLJ71C24TEL __RPC_FAR * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB IActLJ71C24TEL_put_ActDialNumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActLJ71C24TEL_get_ActOutsideLineNumber_Proxy( 
    IActLJ71C24TEL __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *pVal);


void __RPC_STUB IActLJ71C24TEL_get_ActOutsideLineNumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActLJ71C24TEL_put_ActOutsideLineNumber_Proxy( 
    IActLJ71C24TEL __RPC_FAR * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB IActLJ71C24TEL_put_ActOutsideLineNumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActLJ71C24TEL_get_ActCallbackNumber_Proxy( 
    IActLJ71C24TEL __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *pVal);


void __RPC_STUB IActLJ71C24TEL_get_ActCallbackNumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActLJ71C24TEL_put_ActCallbackNumber_Proxy( 
    IActLJ71C24TEL __RPC_FAR * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB IActLJ71C24TEL_put_ActCallbackNumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActLJ71C24TEL_get_ActLineType_Proxy( 
    IActLJ71C24TEL __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IActLJ71C24TEL_get_ActLineType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActLJ71C24TEL_put_ActLineType_Proxy( 
    IActLJ71C24TEL __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB IActLJ71C24TEL_put_ActLineType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActLJ71C24TEL_get_ActConnectionCDWaitTime_Proxy( 
    IActLJ71C24TEL __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IActLJ71C24TEL_get_ActConnectionCDWaitTime_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActLJ71C24TEL_put_ActConnectionCDWaitTime_Proxy( 
    IActLJ71C24TEL __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB IActLJ71C24TEL_put_ActConnectionCDWaitTime_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActLJ71C24TEL_get_ActConnectionModemReportWaitTime_Proxy( 
    IActLJ71C24TEL __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IActLJ71C24TEL_get_ActConnectionModemReportWaitTime_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActLJ71C24TEL_put_ActConnectionModemReportWaitTime_Proxy( 
    IActLJ71C24TEL __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB IActLJ71C24TEL_put_ActConnectionModemReportWaitTime_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActLJ71C24TEL_get_ActDisconnectionCDWaitTime_Proxy( 
    IActLJ71C24TEL __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IActLJ71C24TEL_get_ActDisconnectionCDWaitTime_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActLJ71C24TEL_put_ActDisconnectionCDWaitTime_Proxy( 
    IActLJ71C24TEL __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB IActLJ71C24TEL_put_ActDisconnectionCDWaitTime_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActLJ71C24TEL_get_ActDisconnectionDelayTime_Proxy( 
    IActLJ71C24TEL __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IActLJ71C24TEL_get_ActDisconnectionDelayTime_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActLJ71C24TEL_put_ActDisconnectionDelayTime_Proxy( 
    IActLJ71C24TEL __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB IActLJ71C24TEL_put_ActDisconnectionDelayTime_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActLJ71C24TEL_get_ActTransmissionDelayTime_Proxy( 
    IActLJ71C24TEL __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IActLJ71C24TEL_get_ActTransmissionDelayTime_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActLJ71C24TEL_put_ActTransmissionDelayTime_Proxy( 
    IActLJ71C24TEL __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB IActLJ71C24TEL_put_ActTransmissionDelayTime_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActLJ71C24TEL_get_ActATCommandResponseWaitTime_Proxy( 
    IActLJ71C24TEL __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IActLJ71C24TEL_get_ActATCommandResponseWaitTime_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActLJ71C24TEL_put_ActATCommandResponseWaitTime_Proxy( 
    IActLJ71C24TEL __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB IActLJ71C24TEL_put_ActATCommandResponseWaitTime_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActLJ71C24TEL_get_ActPasswordCancelResponseWaitTime_Proxy( 
    IActLJ71C24TEL __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IActLJ71C24TEL_get_ActPasswordCancelResponseWaitTime_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActLJ71C24TEL_put_ActPasswordCancelResponseWaitTime_Proxy( 
    IActLJ71C24TEL __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB IActLJ71C24TEL_put_ActPasswordCancelResponseWaitTime_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActLJ71C24TEL_get_ActATCommandPasswordCancelRetryTimes_Proxy( 
    IActLJ71C24TEL __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IActLJ71C24TEL_get_ActATCommandPasswordCancelRetryTimes_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActLJ71C24TEL_put_ActATCommandPasswordCancelRetryTimes_Proxy( 
    IActLJ71C24TEL __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB IActLJ71C24TEL_put_ActATCommandPasswordCancelRetryTimes_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActLJ71C24TEL_get_ActCallbackCancelWaitTime_Proxy( 
    IActLJ71C24TEL __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IActLJ71C24TEL_get_ActCallbackCancelWaitTime_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActLJ71C24TEL_put_ActCallbackCancelWaitTime_Proxy( 
    IActLJ71C24TEL __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB IActLJ71C24TEL_put_ActCallbackCancelWaitTime_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActLJ71C24TEL_get_ActCallbackDelayTime_Proxy( 
    IActLJ71C24TEL __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IActLJ71C24TEL_get_ActCallbackDelayTime_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActLJ71C24TEL_put_ActCallbackDelayTime_Proxy( 
    IActLJ71C24TEL __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB IActLJ71C24TEL_put_ActCallbackDelayTime_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActLJ71C24TEL_get_ActCallbackReceptionWaitingTimeOut_Proxy( 
    IActLJ71C24TEL __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IActLJ71C24TEL_get_ActCallbackReceptionWaitingTimeOut_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActLJ71C24TEL_put_ActCallbackReceptionWaitingTimeOut_Proxy( 
    IActLJ71C24TEL __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB IActLJ71C24TEL_put_ActCallbackReceptionWaitingTimeOut_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IActLJ71C24TEL_INTERFACE_DEFINED__ */


#ifndef __IActLJ71C24TEL2_INTERFACE_DEFINED__
#define __IActLJ71C24TEL2_INTERFACE_DEFINED__

/* interface IActLJ71C24TEL2 */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IActLJ71C24TEL2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("E367C39C-39BD-4df8-8F5E-8D568CEE7917")
    IActLJ71C24TEL2 : public IActLJ71C24TEL
    {
    public:
    };
    
#else 	/* C style interface */

    typedef struct IActLJ71C24TEL2Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IActLJ71C24TEL2 __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IActLJ71C24TEL2 __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IActLJ71C24TEL2 __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IActLJ71C24TEL2 __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IActLJ71C24TEL2 __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IActLJ71C24TEL2 __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IActLJ71C24TEL2 __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Open )( 
            IActLJ71C24TEL2 __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Close )( 
            IActLJ71C24TEL2 __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetDevice )( 
            IActLJ71C24TEL2 __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [out] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetDevice )( 
            IActLJ71C24TEL2 __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceBlock )( 
            IActLJ71C24TEL2 __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lSize,
            /* [size_is][out] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceBlock )( 
            IActLJ71C24TEL2 __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lSize,
            /* [size_is][in] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceRandom )( 
            IActLJ71C24TEL2 __RPC_FAR * This,
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG lSize,
            /* [size_is][out] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceRandom )( 
            IActLJ71C24TEL2 __RPC_FAR * This,
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG lSize,
            /* [size_is][in] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadBuffer )( 
            IActLJ71C24TEL2 __RPC_FAR * This,
            /* [in] */ LONG lStartIO,
            /* [in] */ LONG lAddress,
            /* [in] */ LONG lSize,
            /* [size_is][out] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteBuffer )( 
            IActLJ71C24TEL2 __RPC_FAR * This,
            /* [in] */ LONG lStartIO,
            /* [in] */ LONG lAddress,
            /* [in] */ LONG lSize,
            /* [size_is][in] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetCpuType )( 
            IActLJ71C24TEL2 __RPC_FAR * This,
            /* [string][out] */ BSTR __RPC_FAR *szCpuName,
            /* [out] */ LONG __RPC_FAR *lplCpuCode,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetCpuStatus )( 
            IActLJ71C24TEL2 __RPC_FAR * This,
            /* [in] */ LONG lOperation,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetClockData )( 
            IActLJ71C24TEL2 __RPC_FAR * This,
            /* [out] */ SHORT __RPC_FAR *lpsYear,
            /* [out] */ SHORT __RPC_FAR *lpsMonth,
            /* [out] */ SHORT __RPC_FAR *lpsDay,
            /* [out] */ SHORT __RPC_FAR *lpsDayOfWeek,
            /* [out] */ SHORT __RPC_FAR *lpsHour,
            /* [out] */ SHORT __RPC_FAR *lpsMinute,
            /* [out] */ SHORT __RPC_FAR *lpsSecond,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetClockData )( 
            IActLJ71C24TEL2 __RPC_FAR * This,
            /* [in] */ SHORT sYear,
            /* [in] */ SHORT sMonth,
            /* [in] */ SHORT sDay,
            /* [in] */ SHORT sDayOfWeek,
            /* [in] */ SHORT sHour,
            /* [in] */ SHORT sMinute,
            /* [in] */ SHORT sSecond,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *EntryDeviceStatus )( 
            IActLJ71C24TEL2 __RPC_FAR * This,
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG lSize,
            /* [in] */ LONG lMonitorCycle,
            /* [size_is][in] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CheckDeviceString )( 
            IActLJ71C24TEL2 __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lCheckType,
            /* [in] */ LONG lSize,
            /* [out] */ LONG __RPC_FAR *lplDeviceType,
            /* [string][out] */ BSTR __RPC_FAR *lpszDeviceName,
            /* [out] */ LONG __RPC_FAR *lplDeviceNumber,
            /* [out] */ LONG __RPC_FAR *lplDeviceRadix,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *FreeDeviceStatus )( 
            IActLJ71C24TEL2 __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceBlock2 )( 
            IActLJ71C24TEL2 __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lSize,
            /* [size_is][out] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceBlock2 )( 
            IActLJ71C24TEL2 __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lSize,
            /* [size_is][in] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceRandom2 )( 
            IActLJ71C24TEL2 __RPC_FAR * This,
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG lSize,
            /* [size_is][out] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceRandom2 )( 
            IActLJ71C24TEL2 __RPC_FAR * This,
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG lSize,
            /* [size_is][in] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetDevice2 )( 
            IActLJ71C24TEL2 __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [out] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetDevice2 )( 
            IActLJ71C24TEL2 __RPC_FAR * This,
            /* [in] */ BSTR szDevice,
            /* [in] */ SHORT sData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Connect )( 
            IActLJ71C24TEL2 __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Disconnect )( 
            IActLJ71C24TEL2 __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActNetworkNumber )( 
            IActLJ71C24TEL2 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActNetworkNumber )( 
            IActLJ71C24TEL2 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActStationNumber )( 
            IActLJ71C24TEL2 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActStationNumber )( 
            IActLJ71C24TEL2 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActUnitNumber )( 
            IActLJ71C24TEL2 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActUnitNumber )( 
            IActLJ71C24TEL2 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActConnectUnitNumber )( 
            IActLJ71C24TEL2 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActConnectUnitNumber )( 
            IActLJ71C24TEL2 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActIONumber )( 
            IActLJ71C24TEL2 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActIONumber )( 
            IActLJ71C24TEL2 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActCpuType )( 
            IActLJ71C24TEL2 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActCpuType )( 
            IActLJ71C24TEL2 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActPortNumber )( 
            IActLJ71C24TEL2 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActPortNumber )( 
            IActLJ71C24TEL2 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActBaudRate )( 
            IActLJ71C24TEL2 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActBaudRate )( 
            IActLJ71C24TEL2 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActTimeOut )( 
            IActLJ71C24TEL2 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActTimeOut )( 
            IActLJ71C24TEL2 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActDestinationIONumber )( 
            IActLJ71C24TEL2 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActDestinationIONumber )( 
            IActLJ71C24TEL2 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActMultiDropChannelNumber )( 
            IActLJ71C24TEL2 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActMultiDropChannelNumber )( 
            IActLJ71C24TEL2 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActThroughNetworkType )( 
            IActLJ71C24TEL2 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActThroughNetworkType )( 
            IActLJ71C24TEL2 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActIntelligentPreferenceBit )( 
            IActLJ71C24TEL2 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActIntelligentPreferenceBit )( 
            IActLJ71C24TEL2 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActDidPropertyBit )( 
            IActLJ71C24TEL2 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActDidPropertyBit )( 
            IActLJ71C24TEL2 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActDsidPropertyBit )( 
            IActLJ71C24TEL2 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActDsidPropertyBit )( 
            IActLJ71C24TEL2 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActPassword )( 
            IActLJ71C24TEL2 __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActPassword )( 
            IActLJ71C24TEL2 __RPC_FAR * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActConnectWay )( 
            IActLJ71C24TEL2 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActConnectWay )( 
            IActLJ71C24TEL2 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActATCommand )( 
            IActLJ71C24TEL2 __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActATCommand )( 
            IActLJ71C24TEL2 __RPC_FAR * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActDialNumber )( 
            IActLJ71C24TEL2 __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActDialNumber )( 
            IActLJ71C24TEL2 __RPC_FAR * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActOutsideLineNumber )( 
            IActLJ71C24TEL2 __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActOutsideLineNumber )( 
            IActLJ71C24TEL2 __RPC_FAR * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActCallbackNumber )( 
            IActLJ71C24TEL2 __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActCallbackNumber )( 
            IActLJ71C24TEL2 __RPC_FAR * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActLineType )( 
            IActLJ71C24TEL2 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActLineType )( 
            IActLJ71C24TEL2 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActConnectionCDWaitTime )( 
            IActLJ71C24TEL2 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActConnectionCDWaitTime )( 
            IActLJ71C24TEL2 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActConnectionModemReportWaitTime )( 
            IActLJ71C24TEL2 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActConnectionModemReportWaitTime )( 
            IActLJ71C24TEL2 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActDisconnectionCDWaitTime )( 
            IActLJ71C24TEL2 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActDisconnectionCDWaitTime )( 
            IActLJ71C24TEL2 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActDisconnectionDelayTime )( 
            IActLJ71C24TEL2 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActDisconnectionDelayTime )( 
            IActLJ71C24TEL2 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActTransmissionDelayTime )( 
            IActLJ71C24TEL2 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActTransmissionDelayTime )( 
            IActLJ71C24TEL2 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActATCommandResponseWaitTime )( 
            IActLJ71C24TEL2 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActATCommandResponseWaitTime )( 
            IActLJ71C24TEL2 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActPasswordCancelResponseWaitTime )( 
            IActLJ71C24TEL2 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActPasswordCancelResponseWaitTime )( 
            IActLJ71C24TEL2 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActATCommandPasswordCancelRetryTimes )( 
            IActLJ71C24TEL2 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActATCommandPasswordCancelRetryTimes )( 
            IActLJ71C24TEL2 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActCallbackCancelWaitTime )( 
            IActLJ71C24TEL2 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActCallbackCancelWaitTime )( 
            IActLJ71C24TEL2 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActCallbackDelayTime )( 
            IActLJ71C24TEL2 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActCallbackDelayTime )( 
            IActLJ71C24TEL2 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActCallbackReceptionWaitingTimeOut )( 
            IActLJ71C24TEL2 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActCallbackReceptionWaitingTimeOut )( 
            IActLJ71C24TEL2 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        END_INTERFACE
    } IActLJ71C24TEL2Vtbl;

    interface IActLJ71C24TEL2
    {
        CONST_VTBL struct IActLJ71C24TEL2Vtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IActLJ71C24TEL2_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IActLJ71C24TEL2_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IActLJ71C24TEL2_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IActLJ71C24TEL2_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IActLJ71C24TEL2_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IActLJ71C24TEL2_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IActLJ71C24TEL2_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IActLJ71C24TEL2_Open(This,lplReturnCode)	\
    (This)->lpVtbl -> Open(This,lplReturnCode)

#define IActLJ71C24TEL2_Close(This,lplReturnCode)	\
    (This)->lpVtbl -> Close(This,lplReturnCode)

#define IActLJ71C24TEL2_GetDevice(This,szDevice,lplData,lplReturnCode)	\
    (This)->lpVtbl -> GetDevice(This,szDevice,lplData,lplReturnCode)

#define IActLJ71C24TEL2_SetDevice(This,szDevice,lData,lplReturnCode)	\
    (This)->lpVtbl -> SetDevice(This,szDevice,lData,lplReturnCode)

#define IActLJ71C24TEL2_ReadDeviceBlock(This,szDevice,lSize,lplData,lplReturnCode)	\
    (This)->lpVtbl -> ReadDeviceBlock(This,szDevice,lSize,lplData,lplReturnCode)

#define IActLJ71C24TEL2_WriteDeviceBlock(This,szDevice,lSize,lplData,lplReturnCode)	\
    (This)->lpVtbl -> WriteDeviceBlock(This,szDevice,lSize,lplData,lplReturnCode)

#define IActLJ71C24TEL2_ReadDeviceRandom(This,szDeviceList,lSize,lplData,lplReturnCode)	\
    (This)->lpVtbl -> ReadDeviceRandom(This,szDeviceList,lSize,lplData,lplReturnCode)

#define IActLJ71C24TEL2_WriteDeviceRandom(This,szDeviceList,lSize,lplData,lplReturnCode)	\
    (This)->lpVtbl -> WriteDeviceRandom(This,szDeviceList,lSize,lplData,lplReturnCode)

#define IActLJ71C24TEL2_ReadBuffer(This,lStartIO,lAddress,lSize,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> ReadBuffer(This,lStartIO,lAddress,lSize,lpsData,lplReturnCode)

#define IActLJ71C24TEL2_WriteBuffer(This,lStartIO,lAddress,lSize,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> WriteBuffer(This,lStartIO,lAddress,lSize,lpsData,lplReturnCode)

#define IActLJ71C24TEL2_GetCpuType(This,szCpuName,lplCpuCode,lplReturnCode)	\
    (This)->lpVtbl -> GetCpuType(This,szCpuName,lplCpuCode,lplReturnCode)

#define IActLJ71C24TEL2_SetCpuStatus(This,lOperation,lplReturnCode)	\
    (This)->lpVtbl -> SetCpuStatus(This,lOperation,lplReturnCode)

#define IActLJ71C24TEL2_GetClockData(This,lpsYear,lpsMonth,lpsDay,lpsDayOfWeek,lpsHour,lpsMinute,lpsSecond,lplReturnCode)	\
    (This)->lpVtbl -> GetClockData(This,lpsYear,lpsMonth,lpsDay,lpsDayOfWeek,lpsHour,lpsMinute,lpsSecond,lplReturnCode)

#define IActLJ71C24TEL2_SetClockData(This,sYear,sMonth,sDay,sDayOfWeek,sHour,sMinute,sSecond,lplReturnCode)	\
    (This)->lpVtbl -> SetClockData(This,sYear,sMonth,sDay,sDayOfWeek,sHour,sMinute,sSecond,lplReturnCode)

#define IActLJ71C24TEL2_EntryDeviceStatus(This,szDeviceList,lSize,lMonitorCycle,lplData,lplReturnCode)	\
    (This)->lpVtbl -> EntryDeviceStatus(This,szDeviceList,lSize,lMonitorCycle,lplData,lplReturnCode)

#define IActLJ71C24TEL2_CheckDeviceString(This,szDevice,lCheckType,lSize,lplDeviceType,lpszDeviceName,lplDeviceNumber,lplDeviceRadix,lplReturnCode)	\
    (This)->lpVtbl -> CheckDeviceString(This,szDevice,lCheckType,lSize,lplDeviceType,lpszDeviceName,lplDeviceNumber,lplDeviceRadix,lplReturnCode)

#define IActLJ71C24TEL2_FreeDeviceStatus(This,lplReturnCode)	\
    (This)->lpVtbl -> FreeDeviceStatus(This,lplReturnCode)

#define IActLJ71C24TEL2_ReadDeviceBlock2(This,szDevice,lSize,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> ReadDeviceBlock2(This,szDevice,lSize,lpsData,lplReturnCode)

#define IActLJ71C24TEL2_WriteDeviceBlock2(This,szDevice,lSize,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> WriteDeviceBlock2(This,szDevice,lSize,lpsData,lplReturnCode)

#define IActLJ71C24TEL2_ReadDeviceRandom2(This,szDeviceList,lSize,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> ReadDeviceRandom2(This,szDeviceList,lSize,lpsData,lplReturnCode)

#define IActLJ71C24TEL2_WriteDeviceRandom2(This,szDeviceList,lSize,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> WriteDeviceRandom2(This,szDeviceList,lSize,lpsData,lplReturnCode)

#define IActLJ71C24TEL2_GetDevice2(This,szDevice,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> GetDevice2(This,szDevice,lpsData,lplReturnCode)

#define IActLJ71C24TEL2_SetDevice2(This,szDevice,sData,lplReturnCode)	\
    (This)->lpVtbl -> SetDevice2(This,szDevice,sData,lplReturnCode)

#define IActLJ71C24TEL2_Connect(This,lplReturnCode)	\
    (This)->lpVtbl -> Connect(This,lplReturnCode)

#define IActLJ71C24TEL2_Disconnect(This,lplReturnCode)	\
    (This)->lpVtbl -> Disconnect(This,lplReturnCode)

#define IActLJ71C24TEL2_get_ActNetworkNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActNetworkNumber(This,pVal)

#define IActLJ71C24TEL2_put_ActNetworkNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActNetworkNumber(This,newVal)

#define IActLJ71C24TEL2_get_ActStationNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActStationNumber(This,pVal)

#define IActLJ71C24TEL2_put_ActStationNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActStationNumber(This,newVal)

#define IActLJ71C24TEL2_get_ActUnitNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActUnitNumber(This,pVal)

#define IActLJ71C24TEL2_put_ActUnitNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActUnitNumber(This,newVal)

#define IActLJ71C24TEL2_get_ActConnectUnitNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActConnectUnitNumber(This,pVal)

#define IActLJ71C24TEL2_put_ActConnectUnitNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActConnectUnitNumber(This,newVal)

#define IActLJ71C24TEL2_get_ActIONumber(This,pVal)	\
    (This)->lpVtbl -> get_ActIONumber(This,pVal)

#define IActLJ71C24TEL2_put_ActIONumber(This,newVal)	\
    (This)->lpVtbl -> put_ActIONumber(This,newVal)

#define IActLJ71C24TEL2_get_ActCpuType(This,pVal)	\
    (This)->lpVtbl -> get_ActCpuType(This,pVal)

#define IActLJ71C24TEL2_put_ActCpuType(This,newVal)	\
    (This)->lpVtbl -> put_ActCpuType(This,newVal)

#define IActLJ71C24TEL2_get_ActPortNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActPortNumber(This,pVal)

#define IActLJ71C24TEL2_put_ActPortNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActPortNumber(This,newVal)

#define IActLJ71C24TEL2_get_ActBaudRate(This,pVal)	\
    (This)->lpVtbl -> get_ActBaudRate(This,pVal)

#define IActLJ71C24TEL2_put_ActBaudRate(This,newVal)	\
    (This)->lpVtbl -> put_ActBaudRate(This,newVal)

#define IActLJ71C24TEL2_get_ActTimeOut(This,pVal)	\
    (This)->lpVtbl -> get_ActTimeOut(This,pVal)

#define IActLJ71C24TEL2_put_ActTimeOut(This,newVal)	\
    (This)->lpVtbl -> put_ActTimeOut(This,newVal)

#define IActLJ71C24TEL2_get_ActDestinationIONumber(This,pVal)	\
    (This)->lpVtbl -> get_ActDestinationIONumber(This,pVal)

#define IActLJ71C24TEL2_put_ActDestinationIONumber(This,newVal)	\
    (This)->lpVtbl -> put_ActDestinationIONumber(This,newVal)

#define IActLJ71C24TEL2_get_ActMultiDropChannelNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActMultiDropChannelNumber(This,pVal)

#define IActLJ71C24TEL2_put_ActMultiDropChannelNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActMultiDropChannelNumber(This,newVal)

#define IActLJ71C24TEL2_get_ActThroughNetworkType(This,pVal)	\
    (This)->lpVtbl -> get_ActThroughNetworkType(This,pVal)

#define IActLJ71C24TEL2_put_ActThroughNetworkType(This,newVal)	\
    (This)->lpVtbl -> put_ActThroughNetworkType(This,newVal)

#define IActLJ71C24TEL2_get_ActIntelligentPreferenceBit(This,pVal)	\
    (This)->lpVtbl -> get_ActIntelligentPreferenceBit(This,pVal)

#define IActLJ71C24TEL2_put_ActIntelligentPreferenceBit(This,newVal)	\
    (This)->lpVtbl -> put_ActIntelligentPreferenceBit(This,newVal)

#define IActLJ71C24TEL2_get_ActDidPropertyBit(This,pVal)	\
    (This)->lpVtbl -> get_ActDidPropertyBit(This,pVal)

#define IActLJ71C24TEL2_put_ActDidPropertyBit(This,newVal)	\
    (This)->lpVtbl -> put_ActDidPropertyBit(This,newVal)

#define IActLJ71C24TEL2_get_ActDsidPropertyBit(This,pVal)	\
    (This)->lpVtbl -> get_ActDsidPropertyBit(This,pVal)

#define IActLJ71C24TEL2_put_ActDsidPropertyBit(This,newVal)	\
    (This)->lpVtbl -> put_ActDsidPropertyBit(This,newVal)

#define IActLJ71C24TEL2_get_ActPassword(This,pVal)	\
    (This)->lpVtbl -> get_ActPassword(This,pVal)

#define IActLJ71C24TEL2_put_ActPassword(This,newVal)	\
    (This)->lpVtbl -> put_ActPassword(This,newVal)

#define IActLJ71C24TEL2_get_ActConnectWay(This,pVal)	\
    (This)->lpVtbl -> get_ActConnectWay(This,pVal)

#define IActLJ71C24TEL2_put_ActConnectWay(This,newVal)	\
    (This)->lpVtbl -> put_ActConnectWay(This,newVal)

#define IActLJ71C24TEL2_get_ActATCommand(This,pVal)	\
    (This)->lpVtbl -> get_ActATCommand(This,pVal)

#define IActLJ71C24TEL2_put_ActATCommand(This,newVal)	\
    (This)->lpVtbl -> put_ActATCommand(This,newVal)

#define IActLJ71C24TEL2_get_ActDialNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActDialNumber(This,pVal)

#define IActLJ71C24TEL2_put_ActDialNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActDialNumber(This,newVal)

#define IActLJ71C24TEL2_get_ActOutsideLineNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActOutsideLineNumber(This,pVal)

#define IActLJ71C24TEL2_put_ActOutsideLineNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActOutsideLineNumber(This,newVal)

#define IActLJ71C24TEL2_get_ActCallbackNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActCallbackNumber(This,pVal)

#define IActLJ71C24TEL2_put_ActCallbackNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActCallbackNumber(This,newVal)

#define IActLJ71C24TEL2_get_ActLineType(This,pVal)	\
    (This)->lpVtbl -> get_ActLineType(This,pVal)

#define IActLJ71C24TEL2_put_ActLineType(This,newVal)	\
    (This)->lpVtbl -> put_ActLineType(This,newVal)

#define IActLJ71C24TEL2_get_ActConnectionCDWaitTime(This,pVal)	\
    (This)->lpVtbl -> get_ActConnectionCDWaitTime(This,pVal)

#define IActLJ71C24TEL2_put_ActConnectionCDWaitTime(This,newVal)	\
    (This)->lpVtbl -> put_ActConnectionCDWaitTime(This,newVal)

#define IActLJ71C24TEL2_get_ActConnectionModemReportWaitTime(This,pVal)	\
    (This)->lpVtbl -> get_ActConnectionModemReportWaitTime(This,pVal)

#define IActLJ71C24TEL2_put_ActConnectionModemReportWaitTime(This,newVal)	\
    (This)->lpVtbl -> put_ActConnectionModemReportWaitTime(This,newVal)

#define IActLJ71C24TEL2_get_ActDisconnectionCDWaitTime(This,pVal)	\
    (This)->lpVtbl -> get_ActDisconnectionCDWaitTime(This,pVal)

#define IActLJ71C24TEL2_put_ActDisconnectionCDWaitTime(This,newVal)	\
    (This)->lpVtbl -> put_ActDisconnectionCDWaitTime(This,newVal)

#define IActLJ71C24TEL2_get_ActDisconnectionDelayTime(This,pVal)	\
    (This)->lpVtbl -> get_ActDisconnectionDelayTime(This,pVal)

#define IActLJ71C24TEL2_put_ActDisconnectionDelayTime(This,newVal)	\
    (This)->lpVtbl -> put_ActDisconnectionDelayTime(This,newVal)

#define IActLJ71C24TEL2_get_ActTransmissionDelayTime(This,pVal)	\
    (This)->lpVtbl -> get_ActTransmissionDelayTime(This,pVal)

#define IActLJ71C24TEL2_put_ActTransmissionDelayTime(This,newVal)	\
    (This)->lpVtbl -> put_ActTransmissionDelayTime(This,newVal)

#define IActLJ71C24TEL2_get_ActATCommandResponseWaitTime(This,pVal)	\
    (This)->lpVtbl -> get_ActATCommandResponseWaitTime(This,pVal)

#define IActLJ71C24TEL2_put_ActATCommandResponseWaitTime(This,newVal)	\
    (This)->lpVtbl -> put_ActATCommandResponseWaitTime(This,newVal)

#define IActLJ71C24TEL2_get_ActPasswordCancelResponseWaitTime(This,pVal)	\
    (This)->lpVtbl -> get_ActPasswordCancelResponseWaitTime(This,pVal)

#define IActLJ71C24TEL2_put_ActPasswordCancelResponseWaitTime(This,newVal)	\
    (This)->lpVtbl -> put_ActPasswordCancelResponseWaitTime(This,newVal)

#define IActLJ71C24TEL2_get_ActATCommandPasswordCancelRetryTimes(This,pVal)	\
    (This)->lpVtbl -> get_ActATCommandPasswordCancelRetryTimes(This,pVal)

#define IActLJ71C24TEL2_put_ActATCommandPasswordCancelRetryTimes(This,newVal)	\
    (This)->lpVtbl -> put_ActATCommandPasswordCancelRetryTimes(This,newVal)

#define IActLJ71C24TEL2_get_ActCallbackCancelWaitTime(This,pVal)	\
    (This)->lpVtbl -> get_ActCallbackCancelWaitTime(This,pVal)

#define IActLJ71C24TEL2_put_ActCallbackCancelWaitTime(This,newVal)	\
    (This)->lpVtbl -> put_ActCallbackCancelWaitTime(This,newVal)

#define IActLJ71C24TEL2_get_ActCallbackDelayTime(This,pVal)	\
    (This)->lpVtbl -> get_ActCallbackDelayTime(This,pVal)

#define IActLJ71C24TEL2_put_ActCallbackDelayTime(This,newVal)	\
    (This)->lpVtbl -> put_ActCallbackDelayTime(This,newVal)

#define IActLJ71C24TEL2_get_ActCallbackReceptionWaitingTimeOut(This,pVal)	\
    (This)->lpVtbl -> get_ActCallbackReceptionWaitingTimeOut(This,pVal)

#define IActLJ71C24TEL2_put_ActCallbackReceptionWaitingTimeOut(This,newVal)	\
    (This)->lpVtbl -> put_ActCallbackReceptionWaitingTimeOut(This,newVal)


#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IActLJ71C24TEL2_INTERFACE_DEFINED__ */


#ifndef __IActLJ71C24TEL3_INTERFACE_DEFINED__
#define __IActLJ71C24TEL3_INTERFACE_DEFINED__

/* interface IActLJ71C24TEL3 */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IActLJ71C24TEL3;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("BE96010D-12AE-45be-A2CA-9FB28B4E6D7A")
    IActLJ71C24TEL3 : public IActLJ71C24TEL2
    {
    public:
    };
    
#else 	/* C style interface */

    typedef struct IActLJ71C24TEL3Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IActLJ71C24TEL3 __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IActLJ71C24TEL3 __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IActLJ71C24TEL3 __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IActLJ71C24TEL3 __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IActLJ71C24TEL3 __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IActLJ71C24TEL3 __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IActLJ71C24TEL3 __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Open )( 
            IActLJ71C24TEL3 __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Close )( 
            IActLJ71C24TEL3 __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetDevice )( 
            IActLJ71C24TEL3 __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [out] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetDevice )( 
            IActLJ71C24TEL3 __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceBlock )( 
            IActLJ71C24TEL3 __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lSize,
            /* [size_is][out] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceBlock )( 
            IActLJ71C24TEL3 __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lSize,
            /* [size_is][in] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceRandom )( 
            IActLJ71C24TEL3 __RPC_FAR * This,
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG lSize,
            /* [size_is][out] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceRandom )( 
            IActLJ71C24TEL3 __RPC_FAR * This,
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG lSize,
            /* [size_is][in] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadBuffer )( 
            IActLJ71C24TEL3 __RPC_FAR * This,
            /* [in] */ LONG lStartIO,
            /* [in] */ LONG lAddress,
            /* [in] */ LONG lSize,
            /* [size_is][out] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteBuffer )( 
            IActLJ71C24TEL3 __RPC_FAR * This,
            /* [in] */ LONG lStartIO,
            /* [in] */ LONG lAddress,
            /* [in] */ LONG lSize,
            /* [size_is][in] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetCpuType )( 
            IActLJ71C24TEL3 __RPC_FAR * This,
            /* [string][out] */ BSTR __RPC_FAR *szCpuName,
            /* [out] */ LONG __RPC_FAR *lplCpuCode,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetCpuStatus )( 
            IActLJ71C24TEL3 __RPC_FAR * This,
            /* [in] */ LONG lOperation,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetClockData )( 
            IActLJ71C24TEL3 __RPC_FAR * This,
            /* [out] */ SHORT __RPC_FAR *lpsYear,
            /* [out] */ SHORT __RPC_FAR *lpsMonth,
            /* [out] */ SHORT __RPC_FAR *lpsDay,
            /* [out] */ SHORT __RPC_FAR *lpsDayOfWeek,
            /* [out] */ SHORT __RPC_FAR *lpsHour,
            /* [out] */ SHORT __RPC_FAR *lpsMinute,
            /* [out] */ SHORT __RPC_FAR *lpsSecond,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetClockData )( 
            IActLJ71C24TEL3 __RPC_FAR * This,
            /* [in] */ SHORT sYear,
            /* [in] */ SHORT sMonth,
            /* [in] */ SHORT sDay,
            /* [in] */ SHORT sDayOfWeek,
            /* [in] */ SHORT sHour,
            /* [in] */ SHORT sMinute,
            /* [in] */ SHORT sSecond,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *EntryDeviceStatus )( 
            IActLJ71C24TEL3 __RPC_FAR * This,
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG lSize,
            /* [in] */ LONG lMonitorCycle,
            /* [size_is][in] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CheckDeviceString )( 
            IActLJ71C24TEL3 __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lCheckType,
            /* [in] */ LONG lSize,
            /* [out] */ LONG __RPC_FAR *lplDeviceType,
            /* [string][out] */ BSTR __RPC_FAR *lpszDeviceName,
            /* [out] */ LONG __RPC_FAR *lplDeviceNumber,
            /* [out] */ LONG __RPC_FAR *lplDeviceRadix,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *FreeDeviceStatus )( 
            IActLJ71C24TEL3 __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceBlock2 )( 
            IActLJ71C24TEL3 __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lSize,
            /* [size_is][out] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceBlock2 )( 
            IActLJ71C24TEL3 __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lSize,
            /* [size_is][in] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceRandom2 )( 
            IActLJ71C24TEL3 __RPC_FAR * This,
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG lSize,
            /* [size_is][out] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceRandom2 )( 
            IActLJ71C24TEL3 __RPC_FAR * This,
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG lSize,
            /* [size_is][in] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetDevice2 )( 
            IActLJ71C24TEL3 __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [out] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetDevice2 )( 
            IActLJ71C24TEL3 __RPC_FAR * This,
            /* [in] */ BSTR szDevice,
            /* [in] */ SHORT sData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Connect )( 
            IActLJ71C24TEL3 __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Disconnect )( 
            IActLJ71C24TEL3 __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActNetworkNumber )( 
            IActLJ71C24TEL3 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActNetworkNumber )( 
            IActLJ71C24TEL3 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActStationNumber )( 
            IActLJ71C24TEL3 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActStationNumber )( 
            IActLJ71C24TEL3 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActUnitNumber )( 
            IActLJ71C24TEL3 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActUnitNumber )( 
            IActLJ71C24TEL3 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActConnectUnitNumber )( 
            IActLJ71C24TEL3 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActConnectUnitNumber )( 
            IActLJ71C24TEL3 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActIONumber )( 
            IActLJ71C24TEL3 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActIONumber )( 
            IActLJ71C24TEL3 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActCpuType )( 
            IActLJ71C24TEL3 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActCpuType )( 
            IActLJ71C24TEL3 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActPortNumber )( 
            IActLJ71C24TEL3 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActPortNumber )( 
            IActLJ71C24TEL3 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActBaudRate )( 
            IActLJ71C24TEL3 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActBaudRate )( 
            IActLJ71C24TEL3 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActTimeOut )( 
            IActLJ71C24TEL3 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActTimeOut )( 
            IActLJ71C24TEL3 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActDestinationIONumber )( 
            IActLJ71C24TEL3 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActDestinationIONumber )( 
            IActLJ71C24TEL3 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActMultiDropChannelNumber )( 
            IActLJ71C24TEL3 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActMultiDropChannelNumber )( 
            IActLJ71C24TEL3 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActThroughNetworkType )( 
            IActLJ71C24TEL3 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActThroughNetworkType )( 
            IActLJ71C24TEL3 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActIntelligentPreferenceBit )( 
            IActLJ71C24TEL3 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActIntelligentPreferenceBit )( 
            IActLJ71C24TEL3 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActDidPropertyBit )( 
            IActLJ71C24TEL3 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActDidPropertyBit )( 
            IActLJ71C24TEL3 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActDsidPropertyBit )( 
            IActLJ71C24TEL3 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActDsidPropertyBit )( 
            IActLJ71C24TEL3 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActPassword )( 
            IActLJ71C24TEL3 __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActPassword )( 
            IActLJ71C24TEL3 __RPC_FAR * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActConnectWay )( 
            IActLJ71C24TEL3 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActConnectWay )( 
            IActLJ71C24TEL3 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActATCommand )( 
            IActLJ71C24TEL3 __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActATCommand )( 
            IActLJ71C24TEL3 __RPC_FAR * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActDialNumber )( 
            IActLJ71C24TEL3 __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActDialNumber )( 
            IActLJ71C24TEL3 __RPC_FAR * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActOutsideLineNumber )( 
            IActLJ71C24TEL3 __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActOutsideLineNumber )( 
            IActLJ71C24TEL3 __RPC_FAR * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActCallbackNumber )( 
            IActLJ71C24TEL3 __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActCallbackNumber )( 
            IActLJ71C24TEL3 __RPC_FAR * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActLineType )( 
            IActLJ71C24TEL3 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActLineType )( 
            IActLJ71C24TEL3 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActConnectionCDWaitTime )( 
            IActLJ71C24TEL3 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActConnectionCDWaitTime )( 
            IActLJ71C24TEL3 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActConnectionModemReportWaitTime )( 
            IActLJ71C24TEL3 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActConnectionModemReportWaitTime )( 
            IActLJ71C24TEL3 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActDisconnectionCDWaitTime )( 
            IActLJ71C24TEL3 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActDisconnectionCDWaitTime )( 
            IActLJ71C24TEL3 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActDisconnectionDelayTime )( 
            IActLJ71C24TEL3 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActDisconnectionDelayTime )( 
            IActLJ71C24TEL3 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActTransmissionDelayTime )( 
            IActLJ71C24TEL3 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActTransmissionDelayTime )( 
            IActLJ71C24TEL3 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActATCommandResponseWaitTime )( 
            IActLJ71C24TEL3 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActATCommandResponseWaitTime )( 
            IActLJ71C24TEL3 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActPasswordCancelResponseWaitTime )( 
            IActLJ71C24TEL3 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActPasswordCancelResponseWaitTime )( 
            IActLJ71C24TEL3 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActATCommandPasswordCancelRetryTimes )( 
            IActLJ71C24TEL3 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActATCommandPasswordCancelRetryTimes )( 
            IActLJ71C24TEL3 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActCallbackCancelWaitTime )( 
            IActLJ71C24TEL3 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActCallbackCancelWaitTime )( 
            IActLJ71C24TEL3 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActCallbackDelayTime )( 
            IActLJ71C24TEL3 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActCallbackDelayTime )( 
            IActLJ71C24TEL3 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActCallbackReceptionWaitingTimeOut )( 
            IActLJ71C24TEL3 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActCallbackReceptionWaitingTimeOut )( 
            IActLJ71C24TEL3 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        END_INTERFACE
    } IActLJ71C24TEL3Vtbl;

    interface IActLJ71C24TEL3
    {
        CONST_VTBL struct IActLJ71C24TEL3Vtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IActLJ71C24TEL3_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IActLJ71C24TEL3_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IActLJ71C24TEL3_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IActLJ71C24TEL3_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IActLJ71C24TEL3_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IActLJ71C24TEL3_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IActLJ71C24TEL3_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IActLJ71C24TEL3_Open(This,lplReturnCode)	\
    (This)->lpVtbl -> Open(This,lplReturnCode)

#define IActLJ71C24TEL3_Close(This,lplReturnCode)	\
    (This)->lpVtbl -> Close(This,lplReturnCode)

#define IActLJ71C24TEL3_GetDevice(This,szDevice,lplData,lplReturnCode)	\
    (This)->lpVtbl -> GetDevice(This,szDevice,lplData,lplReturnCode)

#define IActLJ71C24TEL3_SetDevice(This,szDevice,lData,lplReturnCode)	\
    (This)->lpVtbl -> SetDevice(This,szDevice,lData,lplReturnCode)

#define IActLJ71C24TEL3_ReadDeviceBlock(This,szDevice,lSize,lplData,lplReturnCode)	\
    (This)->lpVtbl -> ReadDeviceBlock(This,szDevice,lSize,lplData,lplReturnCode)

#define IActLJ71C24TEL3_WriteDeviceBlock(This,szDevice,lSize,lplData,lplReturnCode)	\
    (This)->lpVtbl -> WriteDeviceBlock(This,szDevice,lSize,lplData,lplReturnCode)

#define IActLJ71C24TEL3_ReadDeviceRandom(This,szDeviceList,lSize,lplData,lplReturnCode)	\
    (This)->lpVtbl -> ReadDeviceRandom(This,szDeviceList,lSize,lplData,lplReturnCode)

#define IActLJ71C24TEL3_WriteDeviceRandom(This,szDeviceList,lSize,lplData,lplReturnCode)	\
    (This)->lpVtbl -> WriteDeviceRandom(This,szDeviceList,lSize,lplData,lplReturnCode)

#define IActLJ71C24TEL3_ReadBuffer(This,lStartIO,lAddress,lSize,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> ReadBuffer(This,lStartIO,lAddress,lSize,lpsData,lplReturnCode)

#define IActLJ71C24TEL3_WriteBuffer(This,lStartIO,lAddress,lSize,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> WriteBuffer(This,lStartIO,lAddress,lSize,lpsData,lplReturnCode)

#define IActLJ71C24TEL3_GetCpuType(This,szCpuName,lplCpuCode,lplReturnCode)	\
    (This)->lpVtbl -> GetCpuType(This,szCpuName,lplCpuCode,lplReturnCode)

#define IActLJ71C24TEL3_SetCpuStatus(This,lOperation,lplReturnCode)	\
    (This)->lpVtbl -> SetCpuStatus(This,lOperation,lplReturnCode)

#define IActLJ71C24TEL3_GetClockData(This,lpsYear,lpsMonth,lpsDay,lpsDayOfWeek,lpsHour,lpsMinute,lpsSecond,lplReturnCode)	\
    (This)->lpVtbl -> GetClockData(This,lpsYear,lpsMonth,lpsDay,lpsDayOfWeek,lpsHour,lpsMinute,lpsSecond,lplReturnCode)

#define IActLJ71C24TEL3_SetClockData(This,sYear,sMonth,sDay,sDayOfWeek,sHour,sMinute,sSecond,lplReturnCode)	\
    (This)->lpVtbl -> SetClockData(This,sYear,sMonth,sDay,sDayOfWeek,sHour,sMinute,sSecond,lplReturnCode)

#define IActLJ71C24TEL3_EntryDeviceStatus(This,szDeviceList,lSize,lMonitorCycle,lplData,lplReturnCode)	\
    (This)->lpVtbl -> EntryDeviceStatus(This,szDeviceList,lSize,lMonitorCycle,lplData,lplReturnCode)

#define IActLJ71C24TEL3_CheckDeviceString(This,szDevice,lCheckType,lSize,lplDeviceType,lpszDeviceName,lplDeviceNumber,lplDeviceRadix,lplReturnCode)	\
    (This)->lpVtbl -> CheckDeviceString(This,szDevice,lCheckType,lSize,lplDeviceType,lpszDeviceName,lplDeviceNumber,lplDeviceRadix,lplReturnCode)

#define IActLJ71C24TEL3_FreeDeviceStatus(This,lplReturnCode)	\
    (This)->lpVtbl -> FreeDeviceStatus(This,lplReturnCode)

#define IActLJ71C24TEL3_ReadDeviceBlock2(This,szDevice,lSize,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> ReadDeviceBlock2(This,szDevice,lSize,lpsData,lplReturnCode)

#define IActLJ71C24TEL3_WriteDeviceBlock2(This,szDevice,lSize,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> WriteDeviceBlock2(This,szDevice,lSize,lpsData,lplReturnCode)

#define IActLJ71C24TEL3_ReadDeviceRandom2(This,szDeviceList,lSize,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> ReadDeviceRandom2(This,szDeviceList,lSize,lpsData,lplReturnCode)

#define IActLJ71C24TEL3_WriteDeviceRandom2(This,szDeviceList,lSize,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> WriteDeviceRandom2(This,szDeviceList,lSize,lpsData,lplReturnCode)

#define IActLJ71C24TEL3_GetDevice2(This,szDevice,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> GetDevice2(This,szDevice,lpsData,lplReturnCode)

#define IActLJ71C24TEL3_SetDevice2(This,szDevice,sData,lplReturnCode)	\
    (This)->lpVtbl -> SetDevice2(This,szDevice,sData,lplReturnCode)

#define IActLJ71C24TEL3_Connect(This,lplReturnCode)	\
    (This)->lpVtbl -> Connect(This,lplReturnCode)

#define IActLJ71C24TEL3_Disconnect(This,lplReturnCode)	\
    (This)->lpVtbl -> Disconnect(This,lplReturnCode)

#define IActLJ71C24TEL3_get_ActNetworkNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActNetworkNumber(This,pVal)

#define IActLJ71C24TEL3_put_ActNetworkNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActNetworkNumber(This,newVal)

#define IActLJ71C24TEL3_get_ActStationNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActStationNumber(This,pVal)

#define IActLJ71C24TEL3_put_ActStationNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActStationNumber(This,newVal)

#define IActLJ71C24TEL3_get_ActUnitNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActUnitNumber(This,pVal)

#define IActLJ71C24TEL3_put_ActUnitNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActUnitNumber(This,newVal)

#define IActLJ71C24TEL3_get_ActConnectUnitNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActConnectUnitNumber(This,pVal)

#define IActLJ71C24TEL3_put_ActConnectUnitNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActConnectUnitNumber(This,newVal)

#define IActLJ71C24TEL3_get_ActIONumber(This,pVal)	\
    (This)->lpVtbl -> get_ActIONumber(This,pVal)

#define IActLJ71C24TEL3_put_ActIONumber(This,newVal)	\
    (This)->lpVtbl -> put_ActIONumber(This,newVal)

#define IActLJ71C24TEL3_get_ActCpuType(This,pVal)	\
    (This)->lpVtbl -> get_ActCpuType(This,pVal)

#define IActLJ71C24TEL3_put_ActCpuType(This,newVal)	\
    (This)->lpVtbl -> put_ActCpuType(This,newVal)

#define IActLJ71C24TEL3_get_ActPortNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActPortNumber(This,pVal)

#define IActLJ71C24TEL3_put_ActPortNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActPortNumber(This,newVal)

#define IActLJ71C24TEL3_get_ActBaudRate(This,pVal)	\
    (This)->lpVtbl -> get_ActBaudRate(This,pVal)

#define IActLJ71C24TEL3_put_ActBaudRate(This,newVal)	\
    (This)->lpVtbl -> put_ActBaudRate(This,newVal)

#define IActLJ71C24TEL3_get_ActTimeOut(This,pVal)	\
    (This)->lpVtbl -> get_ActTimeOut(This,pVal)

#define IActLJ71C24TEL3_put_ActTimeOut(This,newVal)	\
    (This)->lpVtbl -> put_ActTimeOut(This,newVal)

#define IActLJ71C24TEL3_get_ActDestinationIONumber(This,pVal)	\
    (This)->lpVtbl -> get_ActDestinationIONumber(This,pVal)

#define IActLJ71C24TEL3_put_ActDestinationIONumber(This,newVal)	\
    (This)->lpVtbl -> put_ActDestinationIONumber(This,newVal)

#define IActLJ71C24TEL3_get_ActMultiDropChannelNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActMultiDropChannelNumber(This,pVal)

#define IActLJ71C24TEL3_put_ActMultiDropChannelNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActMultiDropChannelNumber(This,newVal)

#define IActLJ71C24TEL3_get_ActThroughNetworkType(This,pVal)	\
    (This)->lpVtbl -> get_ActThroughNetworkType(This,pVal)

#define IActLJ71C24TEL3_put_ActThroughNetworkType(This,newVal)	\
    (This)->lpVtbl -> put_ActThroughNetworkType(This,newVal)

#define IActLJ71C24TEL3_get_ActIntelligentPreferenceBit(This,pVal)	\
    (This)->lpVtbl -> get_ActIntelligentPreferenceBit(This,pVal)

#define IActLJ71C24TEL3_put_ActIntelligentPreferenceBit(This,newVal)	\
    (This)->lpVtbl -> put_ActIntelligentPreferenceBit(This,newVal)

#define IActLJ71C24TEL3_get_ActDidPropertyBit(This,pVal)	\
    (This)->lpVtbl -> get_ActDidPropertyBit(This,pVal)

#define IActLJ71C24TEL3_put_ActDidPropertyBit(This,newVal)	\
    (This)->lpVtbl -> put_ActDidPropertyBit(This,newVal)

#define IActLJ71C24TEL3_get_ActDsidPropertyBit(This,pVal)	\
    (This)->lpVtbl -> get_ActDsidPropertyBit(This,pVal)

#define IActLJ71C24TEL3_put_ActDsidPropertyBit(This,newVal)	\
    (This)->lpVtbl -> put_ActDsidPropertyBit(This,newVal)

#define IActLJ71C24TEL3_get_ActPassword(This,pVal)	\
    (This)->lpVtbl -> get_ActPassword(This,pVal)

#define IActLJ71C24TEL3_put_ActPassword(This,newVal)	\
    (This)->lpVtbl -> put_ActPassword(This,newVal)

#define IActLJ71C24TEL3_get_ActConnectWay(This,pVal)	\
    (This)->lpVtbl -> get_ActConnectWay(This,pVal)

#define IActLJ71C24TEL3_put_ActConnectWay(This,newVal)	\
    (This)->lpVtbl -> put_ActConnectWay(This,newVal)

#define IActLJ71C24TEL3_get_ActATCommand(This,pVal)	\
    (This)->lpVtbl -> get_ActATCommand(This,pVal)

#define IActLJ71C24TEL3_put_ActATCommand(This,newVal)	\
    (This)->lpVtbl -> put_ActATCommand(This,newVal)

#define IActLJ71C24TEL3_get_ActDialNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActDialNumber(This,pVal)

#define IActLJ71C24TEL3_put_ActDialNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActDialNumber(This,newVal)

#define IActLJ71C24TEL3_get_ActOutsideLineNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActOutsideLineNumber(This,pVal)

#define IActLJ71C24TEL3_put_ActOutsideLineNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActOutsideLineNumber(This,newVal)

#define IActLJ71C24TEL3_get_ActCallbackNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActCallbackNumber(This,pVal)

#define IActLJ71C24TEL3_put_ActCallbackNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActCallbackNumber(This,newVal)

#define IActLJ71C24TEL3_get_ActLineType(This,pVal)	\
    (This)->lpVtbl -> get_ActLineType(This,pVal)

#define IActLJ71C24TEL3_put_ActLineType(This,newVal)	\
    (This)->lpVtbl -> put_ActLineType(This,newVal)

#define IActLJ71C24TEL3_get_ActConnectionCDWaitTime(This,pVal)	\
    (This)->lpVtbl -> get_ActConnectionCDWaitTime(This,pVal)

#define IActLJ71C24TEL3_put_ActConnectionCDWaitTime(This,newVal)	\
    (This)->lpVtbl -> put_ActConnectionCDWaitTime(This,newVal)

#define IActLJ71C24TEL3_get_ActConnectionModemReportWaitTime(This,pVal)	\
    (This)->lpVtbl -> get_ActConnectionModemReportWaitTime(This,pVal)

#define IActLJ71C24TEL3_put_ActConnectionModemReportWaitTime(This,newVal)	\
    (This)->lpVtbl -> put_ActConnectionModemReportWaitTime(This,newVal)

#define IActLJ71C24TEL3_get_ActDisconnectionCDWaitTime(This,pVal)	\
    (This)->lpVtbl -> get_ActDisconnectionCDWaitTime(This,pVal)

#define IActLJ71C24TEL3_put_ActDisconnectionCDWaitTime(This,newVal)	\
    (This)->lpVtbl -> put_ActDisconnectionCDWaitTime(This,newVal)

#define IActLJ71C24TEL3_get_ActDisconnectionDelayTime(This,pVal)	\
    (This)->lpVtbl -> get_ActDisconnectionDelayTime(This,pVal)

#define IActLJ71C24TEL3_put_ActDisconnectionDelayTime(This,newVal)	\
    (This)->lpVtbl -> put_ActDisconnectionDelayTime(This,newVal)

#define IActLJ71C24TEL3_get_ActTransmissionDelayTime(This,pVal)	\
    (This)->lpVtbl -> get_ActTransmissionDelayTime(This,pVal)

#define IActLJ71C24TEL3_put_ActTransmissionDelayTime(This,newVal)	\
    (This)->lpVtbl -> put_ActTransmissionDelayTime(This,newVal)

#define IActLJ71C24TEL3_get_ActATCommandResponseWaitTime(This,pVal)	\
    (This)->lpVtbl -> get_ActATCommandResponseWaitTime(This,pVal)

#define IActLJ71C24TEL3_put_ActATCommandResponseWaitTime(This,newVal)	\
    (This)->lpVtbl -> put_ActATCommandResponseWaitTime(This,newVal)

#define IActLJ71C24TEL3_get_ActPasswordCancelResponseWaitTime(This,pVal)	\
    (This)->lpVtbl -> get_ActPasswordCancelResponseWaitTime(This,pVal)

#define IActLJ71C24TEL3_put_ActPasswordCancelResponseWaitTime(This,newVal)	\
    (This)->lpVtbl -> put_ActPasswordCancelResponseWaitTime(This,newVal)

#define IActLJ71C24TEL3_get_ActATCommandPasswordCancelRetryTimes(This,pVal)	\
    (This)->lpVtbl -> get_ActATCommandPasswordCancelRetryTimes(This,pVal)

#define IActLJ71C24TEL3_put_ActATCommandPasswordCancelRetryTimes(This,newVal)	\
    (This)->lpVtbl -> put_ActATCommandPasswordCancelRetryTimes(This,newVal)

#define IActLJ71C24TEL3_get_ActCallbackCancelWaitTime(This,pVal)	\
    (This)->lpVtbl -> get_ActCallbackCancelWaitTime(This,pVal)

#define IActLJ71C24TEL3_put_ActCallbackCancelWaitTime(This,newVal)	\
    (This)->lpVtbl -> put_ActCallbackCancelWaitTime(This,newVal)

#define IActLJ71C24TEL3_get_ActCallbackDelayTime(This,pVal)	\
    (This)->lpVtbl -> get_ActCallbackDelayTime(This,pVal)

#define IActLJ71C24TEL3_put_ActCallbackDelayTime(This,newVal)	\
    (This)->lpVtbl -> put_ActCallbackDelayTime(This,newVal)

#define IActLJ71C24TEL3_get_ActCallbackReceptionWaitingTimeOut(This,pVal)	\
    (This)->lpVtbl -> get_ActCallbackReceptionWaitingTimeOut(This,pVal)

#define IActLJ71C24TEL3_put_ActCallbackReceptionWaitingTimeOut(This,newVal)	\
    (This)->lpVtbl -> put_ActCallbackReceptionWaitingTimeOut(This,newVal)



#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IActLJ71C24TEL3_INTERFACE_DEFINED__ */



#ifndef __ACTMODEMLib_LIBRARY_DEFINED__
#define __ACTMODEMLib_LIBRARY_DEFINED__

/* library ACTMODEMLib */
/* [helpstring][version][uuid] */ 


EXTERN_C const IID LIBID_ACTMODEMLib;

#ifndef ___IActA6TELEvents_DISPINTERFACE_DEFINED__
#define ___IActA6TELEvents_DISPINTERFACE_DEFINED__

/* dispinterface _IActA6TELEvents */
/* [helpstring][uuid] */ 


EXTERN_C const IID DIID__IActA6TELEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("5713F074-6F4A-11D5-9315-009099244EFD")
    _IActA6TELEvents : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct _IActA6TELEventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            _IActA6TELEvents __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            _IActA6TELEvents __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            _IActA6TELEvents __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            _IActA6TELEvents __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            _IActA6TELEvents __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            _IActA6TELEvents __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            _IActA6TELEvents __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        END_INTERFACE
    } _IActA6TELEventsVtbl;

    interface _IActA6TELEvents
    {
        CONST_VTBL struct _IActA6TELEventsVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _IActA6TELEvents_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define _IActA6TELEvents_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define _IActA6TELEvents_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define _IActA6TELEvents_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define _IActA6TELEvents_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define _IActA6TELEvents_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define _IActA6TELEvents_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ___IActA6TELEvents_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_ActA6TEL;

#ifdef __cplusplus

class DECLSPEC_UUID("5713F073-6F4A-11D5-9315-009099244EFD")
ActA6TEL;
#endif

#ifndef ___IActQ6TELEvents_DISPINTERFACE_DEFINED__
#define ___IActQ6TELEvents_DISPINTERFACE_DEFINED__

/* dispinterface _IActQ6TELEvents */
/* [helpstring][uuid] */ 


EXTERN_C const IID DIID__IActQ6TELEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("5713F077-6F4A-11D5-9315-009099244EFD")
    _IActQ6TELEvents : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct _IActQ6TELEventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            _IActQ6TELEvents __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            _IActQ6TELEvents __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            _IActQ6TELEvents __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            _IActQ6TELEvents __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            _IActQ6TELEvents __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            _IActQ6TELEvents __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            _IActQ6TELEvents __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        END_INTERFACE
    } _IActQ6TELEventsVtbl;

    interface _IActQ6TELEvents
    {
        CONST_VTBL struct _IActQ6TELEventsVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _IActQ6TELEvents_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define _IActQ6TELEvents_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define _IActQ6TELEvents_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define _IActQ6TELEvents_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define _IActQ6TELEvents_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define _IActQ6TELEvents_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define _IActQ6TELEvents_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ___IActQ6TELEvents_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_ActQ6TEL;

#ifdef __cplusplus

class DECLSPEC_UUID("5713F076-6F4A-11D5-9315-009099244EFD")
ActQ6TEL;
#endif

#ifndef ___IActFXCPUTELEvents_DISPINTERFACE_DEFINED__
#define ___IActFXCPUTELEvents_DISPINTERFACE_DEFINED__

/* dispinterface _IActFXCPUTELEvents */
/* [helpstring][uuid] */ 


EXTERN_C const IID DIID__IActFXCPUTELEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("5713F07A-6F4A-11D5-9315-009099244EFD")
    _IActFXCPUTELEvents : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct _IActFXCPUTELEventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            _IActFXCPUTELEvents __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            _IActFXCPUTELEvents __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            _IActFXCPUTELEvents __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            _IActFXCPUTELEvents __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            _IActFXCPUTELEvents __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            _IActFXCPUTELEvents __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            _IActFXCPUTELEvents __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        END_INTERFACE
    } _IActFXCPUTELEventsVtbl;

    interface _IActFXCPUTELEvents
    {
        CONST_VTBL struct _IActFXCPUTELEventsVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _IActFXCPUTELEvents_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define _IActFXCPUTELEvents_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define _IActFXCPUTELEvents_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define _IActFXCPUTELEvents_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define _IActFXCPUTELEvents_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define _IActFXCPUTELEvents_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define _IActFXCPUTELEvents_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ___IActFXCPUTELEvents_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_ActFXCPUTEL;

#ifdef __cplusplus

class DECLSPEC_UUID("5713F079-6F4A-11D5-9315-009099244EFD")
ActFXCPUTEL;
#endif

#ifndef ___IActAJ71QC24TELEvents_DISPINTERFACE_DEFINED__
#define ___IActAJ71QC24TELEvents_DISPINTERFACE_DEFINED__

/* dispinterface _IActAJ71QC24TELEvents */
/* [helpstring][uuid] */ 


EXTERN_C const IID DIID__IActAJ71QC24TELEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("5713F07D-6F4A-11D5-9315-009099244EFD")
    _IActAJ71QC24TELEvents : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct _IActAJ71QC24TELEventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            _IActAJ71QC24TELEvents __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            _IActAJ71QC24TELEvents __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            _IActAJ71QC24TELEvents __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            _IActAJ71QC24TELEvents __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            _IActAJ71QC24TELEvents __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            _IActAJ71QC24TELEvents __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            _IActAJ71QC24TELEvents __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        END_INTERFACE
    } _IActAJ71QC24TELEventsVtbl;

    interface _IActAJ71QC24TELEvents
    {
        CONST_VTBL struct _IActAJ71QC24TELEventsVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _IActAJ71QC24TELEvents_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define _IActAJ71QC24TELEvents_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define _IActAJ71QC24TELEvents_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define _IActAJ71QC24TELEvents_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define _IActAJ71QC24TELEvents_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define _IActAJ71QC24TELEvents_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define _IActAJ71QC24TELEvents_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ___IActAJ71QC24TELEvents_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_ActAJ71QC24TEL;

#ifdef __cplusplus

class DECLSPEC_UUID("5713F07C-6F4A-11D5-9315-009099244EFD")
ActAJ71QC24TEL;
#endif

#ifndef ___IActQJ71C24TELEvents_DISPINTERFACE_DEFINED__
#define ___IActQJ71C24TELEvents_DISPINTERFACE_DEFINED__

/* dispinterface _IActQJ71C24TELEvents */
/* [helpstring][uuid] */ 


EXTERN_C const IID DIID__IActQJ71C24TELEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("5713F080-6F4A-11D5-9315-009099244EFD")
    _IActQJ71C24TELEvents : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct _IActQJ71C24TELEventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            _IActQJ71C24TELEvents __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            _IActQJ71C24TELEvents __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            _IActQJ71C24TELEvents __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            _IActQJ71C24TELEvents __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            _IActQJ71C24TELEvents __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            _IActQJ71C24TELEvents __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            _IActQJ71C24TELEvents __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        END_INTERFACE
    } _IActQJ71C24TELEventsVtbl;

    interface _IActQJ71C24TELEvents
    {
        CONST_VTBL struct _IActQJ71C24TELEventsVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _IActQJ71C24TELEvents_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define _IActQJ71C24TELEvents_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define _IActQJ71C24TELEvents_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define _IActQJ71C24TELEvents_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define _IActQJ71C24TELEvents_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define _IActQJ71C24TELEvents_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define _IActQJ71C24TELEvents_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ___IActQJ71C24TELEvents_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_ActQJ71C24TEL;

#ifdef __cplusplus

class DECLSPEC_UUID("5713F07F-6F4A-11D5-9315-009099244EFD")
ActQJ71C24TEL;
#endif

#ifndef ___IActLJ71C24TELEvents_DISPINTERFACE_DEFINED__
#define ___IActLJ71C24TELEvents_DISPINTERFACE_DEFINED__

/* dispinterface _IActLJ71C24TELEvents */
/* [helpstring][uuid] */ 


EXTERN_C const IID DIID__IActLJ71C24TELEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("75C995BC-C301-4555-990D-D0AD4BE132BA")
    _IActLJ71C24TELEvents : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct _IActLJ71C24TELEventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            _IActLJ71C24TELEvents __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            _IActLJ71C24TELEvents __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            _IActLJ71C24TELEvents __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            _IActLJ71C24TELEvents __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            _IActLJ71C24TELEvents __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            _IActLJ71C24TELEvents __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            _IActLJ71C24TELEvents __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        END_INTERFACE
    } _IActLJ71C24TELEventsVtbl;

    interface _IActLJ71C24TELEvents
    {
        CONST_VTBL struct _IActLJ71C24TELEventsVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _IActLJ71C24TELEvents_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define _IActLJ71C24TELEvents_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define _IActLJ71C24TELEvents_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define _IActLJ71C24TELEvents_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define _IActLJ71C24TELEvents_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define _IActLJ71C24TELEvents_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define _IActLJ71C24TELEvents_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ___IActLJ71C24TELEvents_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_ActLJ71C24TEL;

#ifdef __cplusplus

class DECLSPEC_UUID("53CC3D65-FB92-4B53-A1E7-23C7C2809265")
ActLJ71C24TEL;
#endif
#endif /* __ACTMODEMLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

unsigned long             __RPC_USER  BSTR_UserSize(     unsigned long __RPC_FAR *, unsigned long            , BSTR __RPC_FAR * ); 
unsigned char __RPC_FAR * __RPC_USER  BSTR_UserMarshal(  unsigned long __RPC_FAR *, unsigned char __RPC_FAR *, BSTR __RPC_FAR * ); 
unsigned char __RPC_FAR * __RPC_USER  BSTR_UserUnmarshal(unsigned long __RPC_FAR *, unsigned char __RPC_FAR *, BSTR __RPC_FAR * ); 
void                      __RPC_USER  BSTR_UserFree(     unsigned long __RPC_FAR *, BSTR __RPC_FAR * ); 

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif
