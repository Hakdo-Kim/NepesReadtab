

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 7.00.0555 */
/* at Thu Jun 16 15:38:49 2016
 */
/* Compiler settings for ActProgType.idl:
    Oicf, W1, Zp8, env=Win32 (32b run), target_arch=X86 7.00.0555 
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
/* @@MIDL_FILE_HEADING(  ) */

#pragma warning( disable: 4049 )  /* more than 64k source lines */


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 475
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

#ifndef __ActProgType_i_h__
#define __ActProgType_i_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IActProgType_FWD_DEFINED__
#define __IActProgType_FWD_DEFINED__
typedef interface IActProgType IActProgType;
#endif 	/* __IActProgType_FWD_DEFINED__ */


#ifndef __IActMLProgType_FWD_DEFINED__
#define __IActMLProgType_FWD_DEFINED__
typedef interface IActMLProgType IActMLProgType;
#endif 	/* __IActMLProgType_FWD_DEFINED__ */


#ifndef ___IActProgTypeEvents_FWD_DEFINED__
#define ___IActProgTypeEvents_FWD_DEFINED__
typedef interface _IActProgTypeEvents _IActProgTypeEvents;
#endif 	/* ___IActProgTypeEvents_FWD_DEFINED__ */


#ifndef __ActProgType_FWD_DEFINED__
#define __ActProgType_FWD_DEFINED__

#ifdef __cplusplus
typedef class ActProgType ActProgType;
#else
typedef struct ActProgType ActProgType;
#endif /* __cplusplus */

#endif 	/* __ActProgType_FWD_DEFINED__ */


#ifndef ___IActMLProgTypeEvents_FWD_DEFINED__
#define ___IActMLProgTypeEvents_FWD_DEFINED__
typedef interface _IActMLProgTypeEvents _IActMLProgTypeEvents;
#endif 	/* ___IActMLProgTypeEvents_FWD_DEFINED__ */


#ifndef __ActMLProgType_FWD_DEFINED__
#define __ActMLProgType_FWD_DEFINED__

#ifdef __cplusplus
typedef class ActMLProgType ActMLProgType;
#else
typedef struct ActMLProgType ActMLProgType;
#endif /* __cplusplus */

#endif 	/* __ActMLProgType_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 


#ifndef __IActProgType_INTERFACE_DEFINED__
#define __IActProgType_INTERFACE_DEFINED__

/* interface IActProgType */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IActProgType;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("C63A7DDA-64FD-4B97-B167-D31C3CC04E3E")
    IActProgType : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActUnitType( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActUnitType( 
            /* [in] */ LONG newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActProtocolType( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActProtocolType( 
            /* [in] */ LONG newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActNetworkNumber( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActNetworkNumber( 
            /* [in] */ LONG newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActStationNumber( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActStationNumber( 
            /* [in] */ LONG newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActUnitNumber( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActUnitNumber( 
            /* [in] */ LONG newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActConnectUnitNumber( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActConnectUnitNumber( 
            /* [in] */ LONG newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActIONumber( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActIONumber( 
            /* [in] */ LONG newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActCpuType( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActCpuType( 
            /* [in] */ LONG newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActPacketType( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActPacketType( 
            /* [in] */ LONG newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActPortNumber( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActPortNumber( 
            /* [in] */ LONG newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActBaudRate( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActBaudRate( 
            /* [in] */ LONG newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActDataBits( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActDataBits( 
            /* [in] */ LONG newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActParity( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActParity( 
            /* [in] */ LONG newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActStopBits( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActStopBits( 
            /* [in] */ LONG newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActControl( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActControl( 
            /* [in] */ LONG newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActHostAddress( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActHostAddress( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActCpuTimeOut( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActCpuTimeOut( 
            /* [in] */ LONG newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActTimeOut( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActTimeOut( 
            /* [in] */ LONG newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActSumCheck( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActSumCheck( 
            /* [in] */ LONG newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActSourceNetworkNumber( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActSourceNetworkNumber( 
            /* [in] */ LONG newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActSourceStationNumber( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActSourceStationNumber( 
            /* [in] */ LONG newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActDestinationPortNumber( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActDestinationPortNumber( 
            /* [in] */ LONG newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActDestinationIONumber( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActDestinationIONumber( 
            /* [in] */ LONG newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActMultiDropChannelNumber( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActMultiDropChannelNumber( 
            /* [in] */ LONG newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActThroughNetworkType( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActThroughNetworkType( 
            /* [in] */ LONG newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActIntelligentPreferenceBit( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActIntelligentPreferenceBit( 
            /* [in] */ LONG newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActDidPropertyBit( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActDidPropertyBit( 
            /* [in] */ LONG newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActDsidPropertyBit( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActDsidPropertyBit( 
            /* [in] */ LONG newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActPassword( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActPassword( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActTargetSimulator( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActTargetSimulator( 
            /* [in] */ LONG newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActConnectWay( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActConnectWay( 
            /* [in] */ LONG newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActATCommand( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActATCommand( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActDialNumber( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActDialNumber( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActOutsideLineNumber( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActOutsideLineNumber( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActCallbackNumber( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActCallbackNumber( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActLineType( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActLineType( 
            /* [in] */ LONG newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActConnectionCDWaitTime( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActConnectionCDWaitTime( 
            /* [in] */ LONG newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActConnectionModemReportWaitTime( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActConnectionModemReportWaitTime( 
            /* [in] */ LONG newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActDisconnectionCDWaitTime( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActDisconnectionCDWaitTime( 
            /* [in] */ LONG newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActDisconnectionDelayTime( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActDisconnectionDelayTime( 
            /* [in] */ LONG newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActTransmissionDelayTime( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActTransmissionDelayTime( 
            /* [in] */ LONG newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActATCommandResponseWaitTime( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActATCommandResponseWaitTime( 
            /* [in] */ LONG newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActPasswordCancelResponseWaitTime( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActPasswordCancelResponseWaitTime( 
            /* [in] */ LONG newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActATCommandPasswordCancelRetryTimes( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActATCommandPasswordCancelRetryTimes( 
            /* [in] */ LONG newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActCallbackCancelWaitTime( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActCallbackCancelWaitTime( 
            /* [in] */ LONG newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActCallbackDelayTime( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActCallbackDelayTime( 
            /* [in] */ LONG newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActCallbackReceptionWaitingTimeOut( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActCallbackReceptionWaitingTimeOut( 
            /* [in] */ LONG newVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Open( 
            /* [retval][out] */ LONG *lplReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Close( 
            /* [retval][out] */ LONG *lplReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetCpuType( 
            /* [string][out] */ BSTR *szCpuName,
            /* [out] */ LONG *lplCpuCode,
            /* [retval][out] */ LONG *lplReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetCpuStatus( 
            /* [in] */ LONG lOperation,
            /* [retval][out] */ LONG *lplReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ReadDeviceBlock( 
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lSize,
            /* [size_is][out] */ LONG *lplData,
            /* [retval][out] */ LONG *lplReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE WriteDeviceBlock( 
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lSize,
            /* [size_is][in] */ LONG *lplData,
            /* [retval][out] */ LONG *lplReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ReadDeviceRandom( 
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG lSize,
            /* [size_is][out] */ LONG *lplData,
            /* [retval][out] */ LONG *lplReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE WriteDeviceRandom( 
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG lSize,
            /* [size_is][in] */ LONG *lplData,
            /* [retval][out] */ LONG *lplReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ReadBuffer( 
            /* [in] */ LONG lStartIO,
            /* [in] */ LONG lAddress,
            /* [in] */ LONG lSize,
            /* [size_is][out] */ SHORT *lpsData,
            /* [retval][out] */ LONG *lplReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE WriteBuffer( 
            /* [in] */ LONG lStartIO,
            /* [in] */ LONG lAddress,
            /* [in] */ LONG lSize,
            /* [size_is][in] */ SHORT *lpsData,
            /* [retval][out] */ LONG *lplReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetClockData( 
            /* [out] */ SHORT *lpsYear,
            /* [out] */ SHORT *lpsMonth,
            /* [out] */ SHORT *lpsDay,
            /* [out] */ SHORT *lpsDayOfWeek,
            /* [out] */ SHORT *lpsHour,
            /* [out] */ SHORT *lpsMinute,
            /* [out] */ SHORT *lpsSecond,
            /* [retval][out] */ LONG *lplReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetClockData( 
            /* [in] */ SHORT sYear,
            /* [in] */ SHORT sMonth,
            /* [in] */ SHORT sDay,
            /* [in] */ SHORT sDayOfWeek,
            /* [in] */ SHORT sHour,
            /* [in] */ SHORT sMinute,
            /* [in] */ SHORT sSecond,
            /* [retval][out] */ LONG *lplReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetDevice( 
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lData,
            /* [retval][out] */ LONG *lplReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetDevice( 
            /* [string][in] */ BSTR szDevice,
            /* [out] */ LONG *lplData,
            /* [retval][out] */ LONG *lplReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE CheckDeviceString( 
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lCheckType,
            /* [in] */ LONG lSize,
            /* [out] */ LONG *lplDeviceType,
            /* [string][out] */ BSTR *lpszDeviceName,
            /* [out] */ LONG *lplDeviceNumber,
            /* [out] */ LONG *lplDeviceRadix,
            /* [retval][out] */ LONG *lplReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE EntryDeviceStatus( 
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG lSize,
            /* [in] */ LONG lMonitorCycle,
            /* [size_is][in] */ LONG *lplData,
            /* [retval][out] */ LONG *lplReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE FreeDeviceStatus( 
            /* [retval][out] */ LONG *lplReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ReadDeviceBlock2( 
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lSize,
            /* [size_is][out] */ SHORT *lpsData,
            /* [retval][out] */ LONG *lplReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE WriteDeviceBlock2( 
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lSize,
            /* [size_is][in] */ SHORT *lpsData,
            /* [retval][out] */ LONG *lplReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ReadDeviceRandom2( 
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG lSize,
            /* [size_is][out] */ SHORT *lpsData,
            /* [retval][out] */ LONG *lplReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE WriteDeviceRandom2( 
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG lSize,
            /* [size_is][in] */ SHORT *lpsData,
            /* [retval][out] */ LONG *lplReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetDevice2( 
            /* [string][in] */ BSTR szDevice,
            /* [out] */ SHORT *lpsData,
            /* [retval][out] */ LONG *lplReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetDevice2( 
            /* [in] */ BSTR szDevice,
            /* [in] */ SHORT sData,
            /* [retval][out] */ LONG *lplReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Connect( 
            /* [retval][out] */ LONG *lplReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Disconnect( 
            /* [retval][out] */ LONG *lplReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetCpuListOnEther( 
            /* [in] */ LONG lTimeOut,
            /* [in] */ LONG lCpuListSize,
            /* [size_is][out] */ LONG *lplCpuList,
            /* [out] */ LONG *lplCpuListCount,
            /* [retval][out] */ LONG *lplReturnCode) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IActProgTypeVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IActProgType * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IActProgType * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IActProgType * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IActProgType * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IActProgType * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IActProgType * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IActProgType * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ActUnitType )( 
            IActProgType * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ActUnitType )( 
            IActProgType * This,
            /* [in] */ LONG newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ActProtocolType )( 
            IActProgType * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ActProtocolType )( 
            IActProgType * This,
            /* [in] */ LONG newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ActNetworkNumber )( 
            IActProgType * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ActNetworkNumber )( 
            IActProgType * This,
            /* [in] */ LONG newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ActStationNumber )( 
            IActProgType * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ActStationNumber )( 
            IActProgType * This,
            /* [in] */ LONG newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ActUnitNumber )( 
            IActProgType * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ActUnitNumber )( 
            IActProgType * This,
            /* [in] */ LONG newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ActConnectUnitNumber )( 
            IActProgType * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ActConnectUnitNumber )( 
            IActProgType * This,
            /* [in] */ LONG newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ActIONumber )( 
            IActProgType * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ActIONumber )( 
            IActProgType * This,
            /* [in] */ LONG newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ActCpuType )( 
            IActProgType * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ActCpuType )( 
            IActProgType * This,
            /* [in] */ LONG newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ActPacketType )( 
            IActProgType * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ActPacketType )( 
            IActProgType * This,
            /* [in] */ LONG newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ActPortNumber )( 
            IActProgType * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ActPortNumber )( 
            IActProgType * This,
            /* [in] */ LONG newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ActBaudRate )( 
            IActProgType * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ActBaudRate )( 
            IActProgType * This,
            /* [in] */ LONG newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ActDataBits )( 
            IActProgType * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ActDataBits )( 
            IActProgType * This,
            /* [in] */ LONG newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ActParity )( 
            IActProgType * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ActParity )( 
            IActProgType * This,
            /* [in] */ LONG newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ActStopBits )( 
            IActProgType * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ActStopBits )( 
            IActProgType * This,
            /* [in] */ LONG newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ActControl )( 
            IActProgType * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ActControl )( 
            IActProgType * This,
            /* [in] */ LONG newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ActHostAddress )( 
            IActProgType * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ActHostAddress )( 
            IActProgType * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ActCpuTimeOut )( 
            IActProgType * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ActCpuTimeOut )( 
            IActProgType * This,
            /* [in] */ LONG newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ActTimeOut )( 
            IActProgType * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ActTimeOut )( 
            IActProgType * This,
            /* [in] */ LONG newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ActSumCheck )( 
            IActProgType * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ActSumCheck )( 
            IActProgType * This,
            /* [in] */ LONG newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ActSourceNetworkNumber )( 
            IActProgType * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ActSourceNetworkNumber )( 
            IActProgType * This,
            /* [in] */ LONG newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ActSourceStationNumber )( 
            IActProgType * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ActSourceStationNumber )( 
            IActProgType * This,
            /* [in] */ LONG newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ActDestinationPortNumber )( 
            IActProgType * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ActDestinationPortNumber )( 
            IActProgType * This,
            /* [in] */ LONG newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ActDestinationIONumber )( 
            IActProgType * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ActDestinationIONumber )( 
            IActProgType * This,
            /* [in] */ LONG newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ActMultiDropChannelNumber )( 
            IActProgType * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ActMultiDropChannelNumber )( 
            IActProgType * This,
            /* [in] */ LONG newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ActThroughNetworkType )( 
            IActProgType * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ActThroughNetworkType )( 
            IActProgType * This,
            /* [in] */ LONG newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ActIntelligentPreferenceBit )( 
            IActProgType * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ActIntelligentPreferenceBit )( 
            IActProgType * This,
            /* [in] */ LONG newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ActDidPropertyBit )( 
            IActProgType * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ActDidPropertyBit )( 
            IActProgType * This,
            /* [in] */ LONG newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ActDsidPropertyBit )( 
            IActProgType * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ActDsidPropertyBit )( 
            IActProgType * This,
            /* [in] */ LONG newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ActPassword )( 
            IActProgType * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ActPassword )( 
            IActProgType * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ActTargetSimulator )( 
            IActProgType * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ActTargetSimulator )( 
            IActProgType * This,
            /* [in] */ LONG newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ActConnectWay )( 
            IActProgType * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ActConnectWay )( 
            IActProgType * This,
            /* [in] */ LONG newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ActATCommand )( 
            IActProgType * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ActATCommand )( 
            IActProgType * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ActDialNumber )( 
            IActProgType * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ActDialNumber )( 
            IActProgType * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ActOutsideLineNumber )( 
            IActProgType * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ActOutsideLineNumber )( 
            IActProgType * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ActCallbackNumber )( 
            IActProgType * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ActCallbackNumber )( 
            IActProgType * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ActLineType )( 
            IActProgType * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ActLineType )( 
            IActProgType * This,
            /* [in] */ LONG newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ActConnectionCDWaitTime )( 
            IActProgType * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ActConnectionCDWaitTime )( 
            IActProgType * This,
            /* [in] */ LONG newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ActConnectionModemReportWaitTime )( 
            IActProgType * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ActConnectionModemReportWaitTime )( 
            IActProgType * This,
            /* [in] */ LONG newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ActDisconnectionCDWaitTime )( 
            IActProgType * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ActDisconnectionCDWaitTime )( 
            IActProgType * This,
            /* [in] */ LONG newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ActDisconnectionDelayTime )( 
            IActProgType * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ActDisconnectionDelayTime )( 
            IActProgType * This,
            /* [in] */ LONG newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ActTransmissionDelayTime )( 
            IActProgType * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ActTransmissionDelayTime )( 
            IActProgType * This,
            /* [in] */ LONG newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ActATCommandResponseWaitTime )( 
            IActProgType * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ActATCommandResponseWaitTime )( 
            IActProgType * This,
            /* [in] */ LONG newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ActPasswordCancelResponseWaitTime )( 
            IActProgType * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ActPasswordCancelResponseWaitTime )( 
            IActProgType * This,
            /* [in] */ LONG newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ActATCommandPasswordCancelRetryTimes )( 
            IActProgType * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ActATCommandPasswordCancelRetryTimes )( 
            IActProgType * This,
            /* [in] */ LONG newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ActCallbackCancelWaitTime )( 
            IActProgType * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ActCallbackCancelWaitTime )( 
            IActProgType * This,
            /* [in] */ LONG newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ActCallbackDelayTime )( 
            IActProgType * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ActCallbackDelayTime )( 
            IActProgType * This,
            /* [in] */ LONG newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ActCallbackReceptionWaitingTimeOut )( 
            IActProgType * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ActCallbackReceptionWaitingTimeOut )( 
            IActProgType * This,
            /* [in] */ LONG newVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Open )( 
            IActProgType * This,
            /* [retval][out] */ LONG *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Close )( 
            IActProgType * This,
            /* [retval][out] */ LONG *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetCpuType )( 
            IActProgType * This,
            /* [string][out] */ BSTR *szCpuName,
            /* [out] */ LONG *lplCpuCode,
            /* [retval][out] */ LONG *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetCpuStatus )( 
            IActProgType * This,
            /* [in] */ LONG lOperation,
            /* [retval][out] */ LONG *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ReadDeviceBlock )( 
            IActProgType * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lSize,
            /* [size_is][out] */ LONG *lplData,
            /* [retval][out] */ LONG *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *WriteDeviceBlock )( 
            IActProgType * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lSize,
            /* [size_is][in] */ LONG *lplData,
            /* [retval][out] */ LONG *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ReadDeviceRandom )( 
            IActProgType * This,
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG lSize,
            /* [size_is][out] */ LONG *lplData,
            /* [retval][out] */ LONG *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *WriteDeviceRandom )( 
            IActProgType * This,
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG lSize,
            /* [size_is][in] */ LONG *lplData,
            /* [retval][out] */ LONG *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ReadBuffer )( 
            IActProgType * This,
            /* [in] */ LONG lStartIO,
            /* [in] */ LONG lAddress,
            /* [in] */ LONG lSize,
            /* [size_is][out] */ SHORT *lpsData,
            /* [retval][out] */ LONG *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *WriteBuffer )( 
            IActProgType * This,
            /* [in] */ LONG lStartIO,
            /* [in] */ LONG lAddress,
            /* [in] */ LONG lSize,
            /* [size_is][in] */ SHORT *lpsData,
            /* [retval][out] */ LONG *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetClockData )( 
            IActProgType * This,
            /* [out] */ SHORT *lpsYear,
            /* [out] */ SHORT *lpsMonth,
            /* [out] */ SHORT *lpsDay,
            /* [out] */ SHORT *lpsDayOfWeek,
            /* [out] */ SHORT *lpsHour,
            /* [out] */ SHORT *lpsMinute,
            /* [out] */ SHORT *lpsSecond,
            /* [retval][out] */ LONG *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetClockData )( 
            IActProgType * This,
            /* [in] */ SHORT sYear,
            /* [in] */ SHORT sMonth,
            /* [in] */ SHORT sDay,
            /* [in] */ SHORT sDayOfWeek,
            /* [in] */ SHORT sHour,
            /* [in] */ SHORT sMinute,
            /* [in] */ SHORT sSecond,
            /* [retval][out] */ LONG *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetDevice )( 
            IActProgType * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lData,
            /* [retval][out] */ LONG *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetDevice )( 
            IActProgType * This,
            /* [string][in] */ BSTR szDevice,
            /* [out] */ LONG *lplData,
            /* [retval][out] */ LONG *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *CheckDeviceString )( 
            IActProgType * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lCheckType,
            /* [in] */ LONG lSize,
            /* [out] */ LONG *lplDeviceType,
            /* [string][out] */ BSTR *lpszDeviceName,
            /* [out] */ LONG *lplDeviceNumber,
            /* [out] */ LONG *lplDeviceRadix,
            /* [retval][out] */ LONG *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *EntryDeviceStatus )( 
            IActProgType * This,
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG lSize,
            /* [in] */ LONG lMonitorCycle,
            /* [size_is][in] */ LONG *lplData,
            /* [retval][out] */ LONG *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *FreeDeviceStatus )( 
            IActProgType * This,
            /* [retval][out] */ LONG *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ReadDeviceBlock2 )( 
            IActProgType * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lSize,
            /* [size_is][out] */ SHORT *lpsData,
            /* [retval][out] */ LONG *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *WriteDeviceBlock2 )( 
            IActProgType * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lSize,
            /* [size_is][in] */ SHORT *lpsData,
            /* [retval][out] */ LONG *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ReadDeviceRandom2 )( 
            IActProgType * This,
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG lSize,
            /* [size_is][out] */ SHORT *lpsData,
            /* [retval][out] */ LONG *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *WriteDeviceRandom2 )( 
            IActProgType * This,
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG lSize,
            /* [size_is][in] */ SHORT *lpsData,
            /* [retval][out] */ LONG *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetDevice2 )( 
            IActProgType * This,
            /* [string][in] */ BSTR szDevice,
            /* [out] */ SHORT *lpsData,
            /* [retval][out] */ LONG *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetDevice2 )( 
            IActProgType * This,
            /* [in] */ BSTR szDevice,
            /* [in] */ SHORT sData,
            /* [retval][out] */ LONG *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Connect )( 
            IActProgType * This,
            /* [retval][out] */ LONG *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Disconnect )( 
            IActProgType * This,
            /* [retval][out] */ LONG *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetCpuListOnEther )( 
            IActProgType * This,
            /* [in] */ LONG lTimeOut,
            /* [in] */ LONG lCpuListSize,
            /* [size_is][out] */ LONG *lplCpuList,
            /* [out] */ LONG *lplCpuListCount,
            /* [retval][out] */ LONG *lplReturnCode);
        
        END_INTERFACE
    } IActProgTypeVtbl;

    interface IActProgType
    {
        CONST_VTBL struct IActProgTypeVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IActProgType_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IActProgType_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IActProgType_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IActProgType_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IActProgType_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IActProgType_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IActProgType_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IActProgType_get_ActUnitType(This,pVal)	\
    ( (This)->lpVtbl -> get_ActUnitType(This,pVal) ) 

#define IActProgType_put_ActUnitType(This,newVal)	\
    ( (This)->lpVtbl -> put_ActUnitType(This,newVal) ) 

#define IActProgType_get_ActProtocolType(This,pVal)	\
    ( (This)->lpVtbl -> get_ActProtocolType(This,pVal) ) 

#define IActProgType_put_ActProtocolType(This,newVal)	\
    ( (This)->lpVtbl -> put_ActProtocolType(This,newVal) ) 

#define IActProgType_get_ActNetworkNumber(This,pVal)	\
    ( (This)->lpVtbl -> get_ActNetworkNumber(This,pVal) ) 

#define IActProgType_put_ActNetworkNumber(This,newVal)	\
    ( (This)->lpVtbl -> put_ActNetworkNumber(This,newVal) ) 

#define IActProgType_get_ActStationNumber(This,pVal)	\
    ( (This)->lpVtbl -> get_ActStationNumber(This,pVal) ) 

#define IActProgType_put_ActStationNumber(This,newVal)	\
    ( (This)->lpVtbl -> put_ActStationNumber(This,newVal) ) 

#define IActProgType_get_ActUnitNumber(This,pVal)	\
    ( (This)->lpVtbl -> get_ActUnitNumber(This,pVal) ) 

#define IActProgType_put_ActUnitNumber(This,newVal)	\
    ( (This)->lpVtbl -> put_ActUnitNumber(This,newVal) ) 

#define IActProgType_get_ActConnectUnitNumber(This,pVal)	\
    ( (This)->lpVtbl -> get_ActConnectUnitNumber(This,pVal) ) 

#define IActProgType_put_ActConnectUnitNumber(This,newVal)	\
    ( (This)->lpVtbl -> put_ActConnectUnitNumber(This,newVal) ) 

#define IActProgType_get_ActIONumber(This,pVal)	\
    ( (This)->lpVtbl -> get_ActIONumber(This,pVal) ) 

#define IActProgType_put_ActIONumber(This,newVal)	\
    ( (This)->lpVtbl -> put_ActIONumber(This,newVal) ) 

#define IActProgType_get_ActCpuType(This,pVal)	\
    ( (This)->lpVtbl -> get_ActCpuType(This,pVal) ) 

#define IActProgType_put_ActCpuType(This,newVal)	\
    ( (This)->lpVtbl -> put_ActCpuType(This,newVal) ) 

#define IActProgType_get_ActPacketType(This,pVal)	\
    ( (This)->lpVtbl -> get_ActPacketType(This,pVal) ) 

#define IActProgType_put_ActPacketType(This,newVal)	\
    ( (This)->lpVtbl -> put_ActPacketType(This,newVal) ) 

#define IActProgType_get_ActPortNumber(This,pVal)	\
    ( (This)->lpVtbl -> get_ActPortNumber(This,pVal) ) 

#define IActProgType_put_ActPortNumber(This,newVal)	\
    ( (This)->lpVtbl -> put_ActPortNumber(This,newVal) ) 

#define IActProgType_get_ActBaudRate(This,pVal)	\
    ( (This)->lpVtbl -> get_ActBaudRate(This,pVal) ) 

#define IActProgType_put_ActBaudRate(This,newVal)	\
    ( (This)->lpVtbl -> put_ActBaudRate(This,newVal) ) 

#define IActProgType_get_ActDataBits(This,pVal)	\
    ( (This)->lpVtbl -> get_ActDataBits(This,pVal) ) 

#define IActProgType_put_ActDataBits(This,newVal)	\
    ( (This)->lpVtbl -> put_ActDataBits(This,newVal) ) 

#define IActProgType_get_ActParity(This,pVal)	\
    ( (This)->lpVtbl -> get_ActParity(This,pVal) ) 

#define IActProgType_put_ActParity(This,newVal)	\
    ( (This)->lpVtbl -> put_ActParity(This,newVal) ) 

#define IActProgType_get_ActStopBits(This,pVal)	\
    ( (This)->lpVtbl -> get_ActStopBits(This,pVal) ) 

#define IActProgType_put_ActStopBits(This,newVal)	\
    ( (This)->lpVtbl -> put_ActStopBits(This,newVal) ) 

#define IActProgType_get_ActControl(This,pVal)	\
    ( (This)->lpVtbl -> get_ActControl(This,pVal) ) 

#define IActProgType_put_ActControl(This,newVal)	\
    ( (This)->lpVtbl -> put_ActControl(This,newVal) ) 

#define IActProgType_get_ActHostAddress(This,pVal)	\
    ( (This)->lpVtbl -> get_ActHostAddress(This,pVal) ) 

#define IActProgType_put_ActHostAddress(This,newVal)	\
    ( (This)->lpVtbl -> put_ActHostAddress(This,newVal) ) 

#define IActProgType_get_ActCpuTimeOut(This,pVal)	\
    ( (This)->lpVtbl -> get_ActCpuTimeOut(This,pVal) ) 

#define IActProgType_put_ActCpuTimeOut(This,newVal)	\
    ( (This)->lpVtbl -> put_ActCpuTimeOut(This,newVal) ) 

#define IActProgType_get_ActTimeOut(This,pVal)	\
    ( (This)->lpVtbl -> get_ActTimeOut(This,pVal) ) 

#define IActProgType_put_ActTimeOut(This,newVal)	\
    ( (This)->lpVtbl -> put_ActTimeOut(This,newVal) ) 

#define IActProgType_get_ActSumCheck(This,pVal)	\
    ( (This)->lpVtbl -> get_ActSumCheck(This,pVal) ) 

#define IActProgType_put_ActSumCheck(This,newVal)	\
    ( (This)->lpVtbl -> put_ActSumCheck(This,newVal) ) 

#define IActProgType_get_ActSourceNetworkNumber(This,pVal)	\
    ( (This)->lpVtbl -> get_ActSourceNetworkNumber(This,pVal) ) 

#define IActProgType_put_ActSourceNetworkNumber(This,newVal)	\
    ( (This)->lpVtbl -> put_ActSourceNetworkNumber(This,newVal) ) 

#define IActProgType_get_ActSourceStationNumber(This,pVal)	\
    ( (This)->lpVtbl -> get_ActSourceStationNumber(This,pVal) ) 

#define IActProgType_put_ActSourceStationNumber(This,newVal)	\
    ( (This)->lpVtbl -> put_ActSourceStationNumber(This,newVal) ) 

#define IActProgType_get_ActDestinationPortNumber(This,pVal)	\
    ( (This)->lpVtbl -> get_ActDestinationPortNumber(This,pVal) ) 

#define IActProgType_put_ActDestinationPortNumber(This,newVal)	\
    ( (This)->lpVtbl -> put_ActDestinationPortNumber(This,newVal) ) 

#define IActProgType_get_ActDestinationIONumber(This,pVal)	\
    ( (This)->lpVtbl -> get_ActDestinationIONumber(This,pVal) ) 

#define IActProgType_put_ActDestinationIONumber(This,newVal)	\
    ( (This)->lpVtbl -> put_ActDestinationIONumber(This,newVal) ) 

#define IActProgType_get_ActMultiDropChannelNumber(This,pVal)	\
    ( (This)->lpVtbl -> get_ActMultiDropChannelNumber(This,pVal) ) 

#define IActProgType_put_ActMultiDropChannelNumber(This,newVal)	\
    ( (This)->lpVtbl -> put_ActMultiDropChannelNumber(This,newVal) ) 

#define IActProgType_get_ActThroughNetworkType(This,pVal)	\
    ( (This)->lpVtbl -> get_ActThroughNetworkType(This,pVal) ) 

#define IActProgType_put_ActThroughNetworkType(This,newVal)	\
    ( (This)->lpVtbl -> put_ActThroughNetworkType(This,newVal) ) 

#define IActProgType_get_ActIntelligentPreferenceBit(This,pVal)	\
    ( (This)->lpVtbl -> get_ActIntelligentPreferenceBit(This,pVal) ) 

#define IActProgType_put_ActIntelligentPreferenceBit(This,newVal)	\
    ( (This)->lpVtbl -> put_ActIntelligentPreferenceBit(This,newVal) ) 

#define IActProgType_get_ActDidPropertyBit(This,pVal)	\
    ( (This)->lpVtbl -> get_ActDidPropertyBit(This,pVal) ) 

#define IActProgType_put_ActDidPropertyBit(This,newVal)	\
    ( (This)->lpVtbl -> put_ActDidPropertyBit(This,newVal) ) 

#define IActProgType_get_ActDsidPropertyBit(This,pVal)	\
    ( (This)->lpVtbl -> get_ActDsidPropertyBit(This,pVal) ) 

#define IActProgType_put_ActDsidPropertyBit(This,newVal)	\
    ( (This)->lpVtbl -> put_ActDsidPropertyBit(This,newVal) ) 

#define IActProgType_get_ActPassword(This,pVal)	\
    ( (This)->lpVtbl -> get_ActPassword(This,pVal) ) 

#define IActProgType_put_ActPassword(This,newVal)	\
    ( (This)->lpVtbl -> put_ActPassword(This,newVal) ) 

#define IActProgType_get_ActTargetSimulator(This,pVal)	\
    ( (This)->lpVtbl -> get_ActTargetSimulator(This,pVal) ) 

#define IActProgType_put_ActTargetSimulator(This,newVal)	\
    ( (This)->lpVtbl -> put_ActTargetSimulator(This,newVal) ) 

#define IActProgType_get_ActConnectWay(This,pVal)	\
    ( (This)->lpVtbl -> get_ActConnectWay(This,pVal) ) 

#define IActProgType_put_ActConnectWay(This,newVal)	\
    ( (This)->lpVtbl -> put_ActConnectWay(This,newVal) ) 

#define IActProgType_get_ActATCommand(This,pVal)	\
    ( (This)->lpVtbl -> get_ActATCommand(This,pVal) ) 

#define IActProgType_put_ActATCommand(This,newVal)	\
    ( (This)->lpVtbl -> put_ActATCommand(This,newVal) ) 

#define IActProgType_get_ActDialNumber(This,pVal)	\
    ( (This)->lpVtbl -> get_ActDialNumber(This,pVal) ) 

#define IActProgType_put_ActDialNumber(This,newVal)	\
    ( (This)->lpVtbl -> put_ActDialNumber(This,newVal) ) 

#define IActProgType_get_ActOutsideLineNumber(This,pVal)	\
    ( (This)->lpVtbl -> get_ActOutsideLineNumber(This,pVal) ) 

#define IActProgType_put_ActOutsideLineNumber(This,newVal)	\
    ( (This)->lpVtbl -> put_ActOutsideLineNumber(This,newVal) ) 

#define IActProgType_get_ActCallbackNumber(This,pVal)	\
    ( (This)->lpVtbl -> get_ActCallbackNumber(This,pVal) ) 

#define IActProgType_put_ActCallbackNumber(This,newVal)	\
    ( (This)->lpVtbl -> put_ActCallbackNumber(This,newVal) ) 

#define IActProgType_get_ActLineType(This,pVal)	\
    ( (This)->lpVtbl -> get_ActLineType(This,pVal) ) 

#define IActProgType_put_ActLineType(This,newVal)	\
    ( (This)->lpVtbl -> put_ActLineType(This,newVal) ) 

#define IActProgType_get_ActConnectionCDWaitTime(This,pVal)	\
    ( (This)->lpVtbl -> get_ActConnectionCDWaitTime(This,pVal) ) 

#define IActProgType_put_ActConnectionCDWaitTime(This,newVal)	\
    ( (This)->lpVtbl -> put_ActConnectionCDWaitTime(This,newVal) ) 

#define IActProgType_get_ActConnectionModemReportWaitTime(This,pVal)	\
    ( (This)->lpVtbl -> get_ActConnectionModemReportWaitTime(This,pVal) ) 

#define IActProgType_put_ActConnectionModemReportWaitTime(This,newVal)	\
    ( (This)->lpVtbl -> put_ActConnectionModemReportWaitTime(This,newVal) ) 

#define IActProgType_get_ActDisconnectionCDWaitTime(This,pVal)	\
    ( (This)->lpVtbl -> get_ActDisconnectionCDWaitTime(This,pVal) ) 

#define IActProgType_put_ActDisconnectionCDWaitTime(This,newVal)	\
    ( (This)->lpVtbl -> put_ActDisconnectionCDWaitTime(This,newVal) ) 

#define IActProgType_get_ActDisconnectionDelayTime(This,pVal)	\
    ( (This)->lpVtbl -> get_ActDisconnectionDelayTime(This,pVal) ) 

#define IActProgType_put_ActDisconnectionDelayTime(This,newVal)	\
    ( (This)->lpVtbl -> put_ActDisconnectionDelayTime(This,newVal) ) 

#define IActProgType_get_ActTransmissionDelayTime(This,pVal)	\
    ( (This)->lpVtbl -> get_ActTransmissionDelayTime(This,pVal) ) 

#define IActProgType_put_ActTransmissionDelayTime(This,newVal)	\
    ( (This)->lpVtbl -> put_ActTransmissionDelayTime(This,newVal) ) 

#define IActProgType_get_ActATCommandResponseWaitTime(This,pVal)	\
    ( (This)->lpVtbl -> get_ActATCommandResponseWaitTime(This,pVal) ) 

#define IActProgType_put_ActATCommandResponseWaitTime(This,newVal)	\
    ( (This)->lpVtbl -> put_ActATCommandResponseWaitTime(This,newVal) ) 

#define IActProgType_get_ActPasswordCancelResponseWaitTime(This,pVal)	\
    ( (This)->lpVtbl -> get_ActPasswordCancelResponseWaitTime(This,pVal) ) 

#define IActProgType_put_ActPasswordCancelResponseWaitTime(This,newVal)	\
    ( (This)->lpVtbl -> put_ActPasswordCancelResponseWaitTime(This,newVal) ) 

#define IActProgType_get_ActATCommandPasswordCancelRetryTimes(This,pVal)	\
    ( (This)->lpVtbl -> get_ActATCommandPasswordCancelRetryTimes(This,pVal) ) 

#define IActProgType_put_ActATCommandPasswordCancelRetryTimes(This,newVal)	\
    ( (This)->lpVtbl -> put_ActATCommandPasswordCancelRetryTimes(This,newVal) ) 

#define IActProgType_get_ActCallbackCancelWaitTime(This,pVal)	\
    ( (This)->lpVtbl -> get_ActCallbackCancelWaitTime(This,pVal) ) 

#define IActProgType_put_ActCallbackCancelWaitTime(This,newVal)	\
    ( (This)->lpVtbl -> put_ActCallbackCancelWaitTime(This,newVal) ) 

#define IActProgType_get_ActCallbackDelayTime(This,pVal)	\
    ( (This)->lpVtbl -> get_ActCallbackDelayTime(This,pVal) ) 

#define IActProgType_put_ActCallbackDelayTime(This,newVal)	\
    ( (This)->lpVtbl -> put_ActCallbackDelayTime(This,newVal) ) 

#define IActProgType_get_ActCallbackReceptionWaitingTimeOut(This,pVal)	\
    ( (This)->lpVtbl -> get_ActCallbackReceptionWaitingTimeOut(This,pVal) ) 

#define IActProgType_put_ActCallbackReceptionWaitingTimeOut(This,newVal)	\
    ( (This)->lpVtbl -> put_ActCallbackReceptionWaitingTimeOut(This,newVal) ) 

#define IActProgType_Open(This,lplReturnCode)	\
    ( (This)->lpVtbl -> Open(This,lplReturnCode) ) 

#define IActProgType_Close(This,lplReturnCode)	\
    ( (This)->lpVtbl -> Close(This,lplReturnCode) ) 

#define IActProgType_GetCpuType(This,szCpuName,lplCpuCode,lplReturnCode)	\
    ( (This)->lpVtbl -> GetCpuType(This,szCpuName,lplCpuCode,lplReturnCode) ) 

#define IActProgType_SetCpuStatus(This,lOperation,lplReturnCode)	\
    ( (This)->lpVtbl -> SetCpuStatus(This,lOperation,lplReturnCode) ) 

#define IActProgType_ReadDeviceBlock(This,szDevice,lSize,lplData,lplReturnCode)	\
    ( (This)->lpVtbl -> ReadDeviceBlock(This,szDevice,lSize,lplData,lplReturnCode) ) 

#define IActProgType_WriteDeviceBlock(This,szDevice,lSize,lplData,lplReturnCode)	\
    ( (This)->lpVtbl -> WriteDeviceBlock(This,szDevice,lSize,lplData,lplReturnCode) ) 

#define IActProgType_ReadDeviceRandom(This,szDeviceList,lSize,lplData,lplReturnCode)	\
    ( (This)->lpVtbl -> ReadDeviceRandom(This,szDeviceList,lSize,lplData,lplReturnCode) ) 

#define IActProgType_WriteDeviceRandom(This,szDeviceList,lSize,lplData,lplReturnCode)	\
    ( (This)->lpVtbl -> WriteDeviceRandom(This,szDeviceList,lSize,lplData,lplReturnCode) ) 

#define IActProgType_ReadBuffer(This,lStartIO,lAddress,lSize,lpsData,lplReturnCode)	\
    ( (This)->lpVtbl -> ReadBuffer(This,lStartIO,lAddress,lSize,lpsData,lplReturnCode) ) 

#define IActProgType_WriteBuffer(This,lStartIO,lAddress,lSize,lpsData,lplReturnCode)	\
    ( (This)->lpVtbl -> WriteBuffer(This,lStartIO,lAddress,lSize,lpsData,lplReturnCode) ) 

#define IActProgType_GetClockData(This,lpsYear,lpsMonth,lpsDay,lpsDayOfWeek,lpsHour,lpsMinute,lpsSecond,lplReturnCode)	\
    ( (This)->lpVtbl -> GetClockData(This,lpsYear,lpsMonth,lpsDay,lpsDayOfWeek,lpsHour,lpsMinute,lpsSecond,lplReturnCode) ) 

#define IActProgType_SetClockData(This,sYear,sMonth,sDay,sDayOfWeek,sHour,sMinute,sSecond,lplReturnCode)	\
    ( (This)->lpVtbl -> SetClockData(This,sYear,sMonth,sDay,sDayOfWeek,sHour,sMinute,sSecond,lplReturnCode) ) 

#define IActProgType_SetDevice(This,szDevice,lData,lplReturnCode)	\
    ( (This)->lpVtbl -> SetDevice(This,szDevice,lData,lplReturnCode) ) 

#define IActProgType_GetDevice(This,szDevice,lplData,lplReturnCode)	\
    ( (This)->lpVtbl -> GetDevice(This,szDevice,lplData,lplReturnCode) ) 

#define IActProgType_CheckDeviceString(This,szDevice,lCheckType,lSize,lplDeviceType,lpszDeviceName,lplDeviceNumber,lplDeviceRadix,lplReturnCode)	\
    ( (This)->lpVtbl -> CheckDeviceString(This,szDevice,lCheckType,lSize,lplDeviceType,lpszDeviceName,lplDeviceNumber,lplDeviceRadix,lplReturnCode) ) 

#define IActProgType_EntryDeviceStatus(This,szDeviceList,lSize,lMonitorCycle,lplData,lplReturnCode)	\
    ( (This)->lpVtbl -> EntryDeviceStatus(This,szDeviceList,lSize,lMonitorCycle,lplData,lplReturnCode) ) 

#define IActProgType_FreeDeviceStatus(This,lplReturnCode)	\
    ( (This)->lpVtbl -> FreeDeviceStatus(This,lplReturnCode) ) 

#define IActProgType_ReadDeviceBlock2(This,szDevice,lSize,lpsData,lplReturnCode)	\
    ( (This)->lpVtbl -> ReadDeviceBlock2(This,szDevice,lSize,lpsData,lplReturnCode) ) 

#define IActProgType_WriteDeviceBlock2(This,szDevice,lSize,lpsData,lplReturnCode)	\
    ( (This)->lpVtbl -> WriteDeviceBlock2(This,szDevice,lSize,lpsData,lplReturnCode) ) 

#define IActProgType_ReadDeviceRandom2(This,szDeviceList,lSize,lpsData,lplReturnCode)	\
    ( (This)->lpVtbl -> ReadDeviceRandom2(This,szDeviceList,lSize,lpsData,lplReturnCode) ) 

#define IActProgType_WriteDeviceRandom2(This,szDeviceList,lSize,lpsData,lplReturnCode)	\
    ( (This)->lpVtbl -> WriteDeviceRandom2(This,szDeviceList,lSize,lpsData,lplReturnCode) ) 

#define IActProgType_GetDevice2(This,szDevice,lpsData,lplReturnCode)	\
    ( (This)->lpVtbl -> GetDevice2(This,szDevice,lpsData,lplReturnCode) ) 

#define IActProgType_SetDevice2(This,szDevice,sData,lplReturnCode)	\
    ( (This)->lpVtbl -> SetDevice2(This,szDevice,sData,lplReturnCode) ) 

#define IActProgType_Connect(This,lplReturnCode)	\
    ( (This)->lpVtbl -> Connect(This,lplReturnCode) ) 

#define IActProgType_Disconnect(This,lplReturnCode)	\
    ( (This)->lpVtbl -> Disconnect(This,lplReturnCode) ) 

#define IActProgType_GetCpuListOnEther(This,lTimeOut,lCpuListSize,lplCpuList,lplCpuListCount,lplReturnCode)	\
    ( (This)->lpVtbl -> GetCpuListOnEther(This,lTimeOut,lCpuListSize,lplCpuList,lplCpuListCount,lplReturnCode) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IActProgType_INTERFACE_DEFINED__ */


#ifndef __IActMLProgType_INTERFACE_DEFINED__
#define __IActMLProgType_INTERFACE_DEFINED__

/* interface IActMLProgType */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IActMLProgType;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("84181939-A078-42CB-9B07-10E2889D54AE")
    IActMLProgType : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActUnitType( 
            /* [retval][out] */ VARIANT *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActUnitType( 
            /* [in] */ VARIANT newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActProtocolType( 
            /* [retval][out] */ VARIANT *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActProtocolType( 
            /* [in] */ VARIANT newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActNetworkNumber( 
            /* [retval][out] */ VARIANT *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActNetworkNumber( 
            /* [in] */ VARIANT newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActStationNumber( 
            /* [retval][out] */ VARIANT *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActStationNumber( 
            /* [in] */ VARIANT newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActUnitNumber( 
            /* [retval][out] */ VARIANT *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActUnitNumber( 
            /* [in] */ VARIANT newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActConnectUnitNumber( 
            /* [retval][out] */ VARIANT *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActConnectUnitNumber( 
            /* [in] */ VARIANT newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActIONumber( 
            /* [retval][out] */ VARIANT *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActIONumber( 
            /* [in] */ VARIANT newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActCpuType( 
            /* [retval][out] */ VARIANT *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActCpuType( 
            /* [in] */ VARIANT newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActPacketType( 
            /* [retval][out] */ VARIANT *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActPacketType( 
            /* [in] */ VARIANT newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActPortNumber( 
            /* [retval][out] */ VARIANT *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActPortNumber( 
            /* [in] */ VARIANT newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActBaudRate( 
            /* [retval][out] */ VARIANT *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActBaudRate( 
            /* [in] */ VARIANT newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActDataBits( 
            /* [retval][out] */ VARIANT *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActDataBits( 
            /* [in] */ VARIANT newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActParity( 
            /* [retval][out] */ VARIANT *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActParity( 
            /* [in] */ VARIANT newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActStopBits( 
            /* [retval][out] */ VARIANT *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActStopBits( 
            /* [in] */ VARIANT newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActControl( 
            /* [retval][out] */ VARIANT *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActControl( 
            /* [in] */ VARIANT newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActHostAddress( 
            /* [retval][out] */ VARIANT *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActHostAddress( 
            /* [in] */ VARIANT newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActCpuTimeOut( 
            /* [retval][out] */ VARIANT *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActCpuTimeOut( 
            /* [in] */ VARIANT newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActTimeOut( 
            /* [retval][out] */ VARIANT *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActTimeOut( 
            /* [in] */ VARIANT newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActSumCheck( 
            /* [retval][out] */ VARIANT *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActSumCheck( 
            /* [in] */ VARIANT newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActSourceNetworkNumber( 
            /* [retval][out] */ VARIANT *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActSourceNetworkNumber( 
            /* [in] */ VARIANT newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActSourceStationNumber( 
            /* [retval][out] */ VARIANT *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActSourceStationNumber( 
            /* [in] */ VARIANT newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActDestinationPortNumber( 
            /* [retval][out] */ VARIANT *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActDestinationPortNumber( 
            /* [in] */ VARIANT newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActDestinationIONumber( 
            /* [retval][out] */ VARIANT *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActDestinationIONumber( 
            /* [in] */ VARIANT newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActMultiDropChannelNumber( 
            /* [retval][out] */ VARIANT *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActMultiDropChannelNumber( 
            /* [in] */ VARIANT newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActThroughNetworkType( 
            /* [retval][out] */ VARIANT *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActThroughNetworkType( 
            /* [in] */ VARIANT newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActIntelligentPreferenceBit( 
            /* [retval][out] */ VARIANT *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActIntelligentPreferenceBit( 
            /* [in] */ VARIANT newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActDidPropertyBit( 
            /* [retval][out] */ VARIANT *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActDidPropertyBit( 
            /* [in] */ VARIANT newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActDsidPropertyBit( 
            /* [retval][out] */ VARIANT *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActDsidPropertyBit( 
            /* [in] */ VARIANT newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActPassword( 
            /* [retval][out] */ VARIANT *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActPassword( 
            /* [in] */ VARIANT newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActTargetSimulator( 
            /* [retval][out] */ VARIANT *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActTargetSimulator( 
            /* [in] */ VARIANT newVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Open( 
            /* [retval][out] */ VARIANT *lpvarReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Close( 
            /* [retval][out] */ VARIANT *lpvarReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetCpuType( 
            /* [out] */ VARIANT *lpvarCpuName,
            /* [out] */ VARIANT *lpvarCpuCode,
            /* [retval][out] */ VARIANT *lpvarReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetCpuStatus( 
            /* [in] */ VARIANT varOperation,
            /* [retval][out] */ VARIANT *lpvarReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ReadDeviceBlock( 
            /* [in] */ VARIANT varDevice,
            /* [in] */ VARIANT varSize,
            /* [out] */ VARIANT *lpvarData,
            /* [retval][out] */ VARIANT *lpvarReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE WriteDeviceBlock( 
            /* [in] */ VARIANT varDevice,
            /* [in] */ VARIANT varSize,
            /* [in] */ VARIANT varData,
            /* [retval][out] */ VARIANT *lpvarReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ReadDeviceRandom( 
            /* [in] */ VARIANT varDeviceList,
            /* [in] */ VARIANT varSize,
            /* [out] */ VARIANT *lpvarData,
            /* [retval][out] */ VARIANT *lpvarReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE WriteDeviceRandom( 
            /* [in] */ VARIANT varDeviceList,
            /* [in] */ VARIANT varSize,
            /* [in] */ VARIANT varData,
            /* [retval][out] */ VARIANT *lpvarReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ReadBuffer( 
            /* [in] */ VARIANT varStartIO,
            /* [in] */ VARIANT varAddress,
            /* [in] */ VARIANT varReadSize,
            /* [out] */ VARIANT *lpvarData,
            /* [retval][out] */ VARIANT *lpvarReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE WriteBuffer( 
            /* [in] */ VARIANT varStartIO,
            /* [in] */ VARIANT varAddress,
            /* [in] */ VARIANT varWriteSize,
            /* [in] */ VARIANT varData,
            /* [retval][out] */ VARIANT *lpvarReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetClockData( 
            /* [out] */ VARIANT *lpvarYear,
            /* [out] */ VARIANT *lpvarMonth,
            /* [out] */ VARIANT *lpvarDay,
            /* [out] */ VARIANT *lpvarDayOfWeek,
            /* [out] */ VARIANT *lpvarHour,
            /* [out] */ VARIANT *lpvarMinute,
            /* [out] */ VARIANT *lpvarSecond,
            /* [retval][out] */ VARIANT *lpvarReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetClockData( 
            /* [in] */ VARIANT varYear,
            /* [in] */ VARIANT varMonth,
            /* [in] */ VARIANT varDay,
            /* [in] */ VARIANT varDayOfWeek,
            /* [in] */ VARIANT varHour,
            /* [in] */ VARIANT varMinute,
            /* [in] */ VARIANT varSecond,
            /* [retval][out] */ VARIANT *lpvarReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetDevice( 
            /* [in] */ VARIANT varDevice,
            /* [in] */ VARIANT varData,
            /* [retval][out] */ VARIANT *lpvarReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetDevice( 
            /* [in] */ VARIANT varDevice,
            /* [out] */ VARIANT *lpvarData,
            /* [retval][out] */ VARIANT *lpvarReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE EntryDeviceStatus( 
            /* [in] */ VARIANT varDeviceList,
            /* [in] */ VARIANT varSize,
            /* [in] */ VARIANT varMonitorCycle,
            /* [in] */ VARIANT varData,
            /* [retval][out] */ VARIANT *lpvarReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE FreeDeviceStatus( 
            /* [retval][out] */ VARIANT *lpvarReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ReadDeviceBlock2( 
            /* [in] */ VARIANT varDevice,
            /* [in] */ VARIANT varSize,
            /* [out] */ VARIANT *lpvarData,
            /* [retval][out] */ VARIANT *lpvarReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE WriteDeviceBlock2( 
            /* [in] */ VARIANT varDevice,
            /* [in] */ VARIANT varSize,
            /* [in] */ VARIANT varData,
            /* [retval][out] */ VARIANT *lpvarReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ReadDeviceRandom2( 
            /* [in] */ VARIANT varDeviceList,
            /* [in] */ VARIANT varSize,
            /* [out] */ VARIANT *lpvarData,
            /* [retval][out] */ VARIANT *lpvarReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE WriteDeviceRandom2( 
            /* [in] */ VARIANT varDeviceList,
            /* [in] */ VARIANT varSize,
            /* [in] */ VARIANT varData,
            /* [retval][out] */ VARIANT *lpvarReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetDevice2( 
            /* [in] */ VARIANT varDevice,
            /* [out] */ VARIANT *lpvarData,
            /* [retval][out] */ VARIANT *lpvarReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetDevice2( 
            /* [in] */ VARIANT varDevice,
            /* [in] */ VARIANT varData,
            /* [retval][out] */ VARIANT *lpvarReturnCode) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IActMLProgTypeVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IActMLProgType * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IActMLProgType * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IActMLProgType * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IActMLProgType * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IActMLProgType * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IActMLProgType * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IActMLProgType * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ActUnitType )( 
            IActMLProgType * This,
            /* [retval][out] */ VARIANT *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ActUnitType )( 
            IActMLProgType * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ActProtocolType )( 
            IActMLProgType * This,
            /* [retval][out] */ VARIANT *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ActProtocolType )( 
            IActMLProgType * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ActNetworkNumber )( 
            IActMLProgType * This,
            /* [retval][out] */ VARIANT *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ActNetworkNumber )( 
            IActMLProgType * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ActStationNumber )( 
            IActMLProgType * This,
            /* [retval][out] */ VARIANT *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ActStationNumber )( 
            IActMLProgType * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ActUnitNumber )( 
            IActMLProgType * This,
            /* [retval][out] */ VARIANT *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ActUnitNumber )( 
            IActMLProgType * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ActConnectUnitNumber )( 
            IActMLProgType * This,
            /* [retval][out] */ VARIANT *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ActConnectUnitNumber )( 
            IActMLProgType * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ActIONumber )( 
            IActMLProgType * This,
            /* [retval][out] */ VARIANT *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ActIONumber )( 
            IActMLProgType * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ActCpuType )( 
            IActMLProgType * This,
            /* [retval][out] */ VARIANT *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ActCpuType )( 
            IActMLProgType * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ActPacketType )( 
            IActMLProgType * This,
            /* [retval][out] */ VARIANT *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ActPacketType )( 
            IActMLProgType * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ActPortNumber )( 
            IActMLProgType * This,
            /* [retval][out] */ VARIANT *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ActPortNumber )( 
            IActMLProgType * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ActBaudRate )( 
            IActMLProgType * This,
            /* [retval][out] */ VARIANT *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ActBaudRate )( 
            IActMLProgType * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ActDataBits )( 
            IActMLProgType * This,
            /* [retval][out] */ VARIANT *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ActDataBits )( 
            IActMLProgType * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ActParity )( 
            IActMLProgType * This,
            /* [retval][out] */ VARIANT *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ActParity )( 
            IActMLProgType * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ActStopBits )( 
            IActMLProgType * This,
            /* [retval][out] */ VARIANT *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ActStopBits )( 
            IActMLProgType * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ActControl )( 
            IActMLProgType * This,
            /* [retval][out] */ VARIANT *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ActControl )( 
            IActMLProgType * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ActHostAddress )( 
            IActMLProgType * This,
            /* [retval][out] */ VARIANT *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ActHostAddress )( 
            IActMLProgType * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ActCpuTimeOut )( 
            IActMLProgType * This,
            /* [retval][out] */ VARIANT *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ActCpuTimeOut )( 
            IActMLProgType * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ActTimeOut )( 
            IActMLProgType * This,
            /* [retval][out] */ VARIANT *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ActTimeOut )( 
            IActMLProgType * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ActSumCheck )( 
            IActMLProgType * This,
            /* [retval][out] */ VARIANT *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ActSumCheck )( 
            IActMLProgType * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ActSourceNetworkNumber )( 
            IActMLProgType * This,
            /* [retval][out] */ VARIANT *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ActSourceNetworkNumber )( 
            IActMLProgType * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ActSourceStationNumber )( 
            IActMLProgType * This,
            /* [retval][out] */ VARIANT *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ActSourceStationNumber )( 
            IActMLProgType * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ActDestinationPortNumber )( 
            IActMLProgType * This,
            /* [retval][out] */ VARIANT *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ActDestinationPortNumber )( 
            IActMLProgType * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ActDestinationIONumber )( 
            IActMLProgType * This,
            /* [retval][out] */ VARIANT *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ActDestinationIONumber )( 
            IActMLProgType * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ActMultiDropChannelNumber )( 
            IActMLProgType * This,
            /* [retval][out] */ VARIANT *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ActMultiDropChannelNumber )( 
            IActMLProgType * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ActThroughNetworkType )( 
            IActMLProgType * This,
            /* [retval][out] */ VARIANT *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ActThroughNetworkType )( 
            IActMLProgType * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ActIntelligentPreferenceBit )( 
            IActMLProgType * This,
            /* [retval][out] */ VARIANT *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ActIntelligentPreferenceBit )( 
            IActMLProgType * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ActDidPropertyBit )( 
            IActMLProgType * This,
            /* [retval][out] */ VARIANT *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ActDidPropertyBit )( 
            IActMLProgType * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ActDsidPropertyBit )( 
            IActMLProgType * This,
            /* [retval][out] */ VARIANT *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ActDsidPropertyBit )( 
            IActMLProgType * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ActPassword )( 
            IActMLProgType * This,
            /* [retval][out] */ VARIANT *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ActPassword )( 
            IActMLProgType * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ActTargetSimulator )( 
            IActMLProgType * This,
            /* [retval][out] */ VARIANT *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ActTargetSimulator )( 
            IActMLProgType * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Open )( 
            IActMLProgType * This,
            /* [retval][out] */ VARIANT *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Close )( 
            IActMLProgType * This,
            /* [retval][out] */ VARIANT *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetCpuType )( 
            IActMLProgType * This,
            /* [out] */ VARIANT *lpvarCpuName,
            /* [out] */ VARIANT *lpvarCpuCode,
            /* [retval][out] */ VARIANT *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetCpuStatus )( 
            IActMLProgType * This,
            /* [in] */ VARIANT varOperation,
            /* [retval][out] */ VARIANT *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ReadDeviceBlock )( 
            IActMLProgType * This,
            /* [in] */ VARIANT varDevice,
            /* [in] */ VARIANT varSize,
            /* [out] */ VARIANT *lpvarData,
            /* [retval][out] */ VARIANT *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *WriteDeviceBlock )( 
            IActMLProgType * This,
            /* [in] */ VARIANT varDevice,
            /* [in] */ VARIANT varSize,
            /* [in] */ VARIANT varData,
            /* [retval][out] */ VARIANT *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ReadDeviceRandom )( 
            IActMLProgType * This,
            /* [in] */ VARIANT varDeviceList,
            /* [in] */ VARIANT varSize,
            /* [out] */ VARIANT *lpvarData,
            /* [retval][out] */ VARIANT *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *WriteDeviceRandom )( 
            IActMLProgType * This,
            /* [in] */ VARIANT varDeviceList,
            /* [in] */ VARIANT varSize,
            /* [in] */ VARIANT varData,
            /* [retval][out] */ VARIANT *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ReadBuffer )( 
            IActMLProgType * This,
            /* [in] */ VARIANT varStartIO,
            /* [in] */ VARIANT varAddress,
            /* [in] */ VARIANT varReadSize,
            /* [out] */ VARIANT *lpvarData,
            /* [retval][out] */ VARIANT *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *WriteBuffer )( 
            IActMLProgType * This,
            /* [in] */ VARIANT varStartIO,
            /* [in] */ VARIANT varAddress,
            /* [in] */ VARIANT varWriteSize,
            /* [in] */ VARIANT varData,
            /* [retval][out] */ VARIANT *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetClockData )( 
            IActMLProgType * This,
            /* [out] */ VARIANT *lpvarYear,
            /* [out] */ VARIANT *lpvarMonth,
            /* [out] */ VARIANT *lpvarDay,
            /* [out] */ VARIANT *lpvarDayOfWeek,
            /* [out] */ VARIANT *lpvarHour,
            /* [out] */ VARIANT *lpvarMinute,
            /* [out] */ VARIANT *lpvarSecond,
            /* [retval][out] */ VARIANT *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetClockData )( 
            IActMLProgType * This,
            /* [in] */ VARIANT varYear,
            /* [in] */ VARIANT varMonth,
            /* [in] */ VARIANT varDay,
            /* [in] */ VARIANT varDayOfWeek,
            /* [in] */ VARIANT varHour,
            /* [in] */ VARIANT varMinute,
            /* [in] */ VARIANT varSecond,
            /* [retval][out] */ VARIANT *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetDevice )( 
            IActMLProgType * This,
            /* [in] */ VARIANT varDevice,
            /* [in] */ VARIANT varData,
            /* [retval][out] */ VARIANT *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetDevice )( 
            IActMLProgType * This,
            /* [in] */ VARIANT varDevice,
            /* [out] */ VARIANT *lpvarData,
            /* [retval][out] */ VARIANT *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *EntryDeviceStatus )( 
            IActMLProgType * This,
            /* [in] */ VARIANT varDeviceList,
            /* [in] */ VARIANT varSize,
            /* [in] */ VARIANT varMonitorCycle,
            /* [in] */ VARIANT varData,
            /* [retval][out] */ VARIANT *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *FreeDeviceStatus )( 
            IActMLProgType * This,
            /* [retval][out] */ VARIANT *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ReadDeviceBlock2 )( 
            IActMLProgType * This,
            /* [in] */ VARIANT varDevice,
            /* [in] */ VARIANT varSize,
            /* [out] */ VARIANT *lpvarData,
            /* [retval][out] */ VARIANT *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *WriteDeviceBlock2 )( 
            IActMLProgType * This,
            /* [in] */ VARIANT varDevice,
            /* [in] */ VARIANT varSize,
            /* [in] */ VARIANT varData,
            /* [retval][out] */ VARIANT *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ReadDeviceRandom2 )( 
            IActMLProgType * This,
            /* [in] */ VARIANT varDeviceList,
            /* [in] */ VARIANT varSize,
            /* [out] */ VARIANT *lpvarData,
            /* [retval][out] */ VARIANT *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *WriteDeviceRandom2 )( 
            IActMLProgType * This,
            /* [in] */ VARIANT varDeviceList,
            /* [in] */ VARIANT varSize,
            /* [in] */ VARIANT varData,
            /* [retval][out] */ VARIANT *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetDevice2 )( 
            IActMLProgType * This,
            /* [in] */ VARIANT varDevice,
            /* [out] */ VARIANT *lpvarData,
            /* [retval][out] */ VARIANT *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetDevice2 )( 
            IActMLProgType * This,
            /* [in] */ VARIANT varDevice,
            /* [in] */ VARIANT varData,
            /* [retval][out] */ VARIANT *lpvarReturnCode);
        
        END_INTERFACE
    } IActMLProgTypeVtbl;

    interface IActMLProgType
    {
        CONST_VTBL struct IActMLProgTypeVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IActMLProgType_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IActMLProgType_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IActMLProgType_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IActMLProgType_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IActMLProgType_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IActMLProgType_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IActMLProgType_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IActMLProgType_get_ActUnitType(This,pVal)	\
    ( (This)->lpVtbl -> get_ActUnitType(This,pVal) ) 

#define IActMLProgType_put_ActUnitType(This,newVal)	\
    ( (This)->lpVtbl -> put_ActUnitType(This,newVal) ) 

#define IActMLProgType_get_ActProtocolType(This,pVal)	\
    ( (This)->lpVtbl -> get_ActProtocolType(This,pVal) ) 

#define IActMLProgType_put_ActProtocolType(This,newVal)	\
    ( (This)->lpVtbl -> put_ActProtocolType(This,newVal) ) 

#define IActMLProgType_get_ActNetworkNumber(This,pVal)	\
    ( (This)->lpVtbl -> get_ActNetworkNumber(This,pVal) ) 

#define IActMLProgType_put_ActNetworkNumber(This,newVal)	\
    ( (This)->lpVtbl -> put_ActNetworkNumber(This,newVal) ) 

#define IActMLProgType_get_ActStationNumber(This,pVal)	\
    ( (This)->lpVtbl -> get_ActStationNumber(This,pVal) ) 

#define IActMLProgType_put_ActStationNumber(This,newVal)	\
    ( (This)->lpVtbl -> put_ActStationNumber(This,newVal) ) 

#define IActMLProgType_get_ActUnitNumber(This,pVal)	\
    ( (This)->lpVtbl -> get_ActUnitNumber(This,pVal) ) 

#define IActMLProgType_put_ActUnitNumber(This,newVal)	\
    ( (This)->lpVtbl -> put_ActUnitNumber(This,newVal) ) 

#define IActMLProgType_get_ActConnectUnitNumber(This,pVal)	\
    ( (This)->lpVtbl -> get_ActConnectUnitNumber(This,pVal) ) 

#define IActMLProgType_put_ActConnectUnitNumber(This,newVal)	\
    ( (This)->lpVtbl -> put_ActConnectUnitNumber(This,newVal) ) 

#define IActMLProgType_get_ActIONumber(This,pVal)	\
    ( (This)->lpVtbl -> get_ActIONumber(This,pVal) ) 

#define IActMLProgType_put_ActIONumber(This,newVal)	\
    ( (This)->lpVtbl -> put_ActIONumber(This,newVal) ) 

#define IActMLProgType_get_ActCpuType(This,pVal)	\
    ( (This)->lpVtbl -> get_ActCpuType(This,pVal) ) 

#define IActMLProgType_put_ActCpuType(This,newVal)	\
    ( (This)->lpVtbl -> put_ActCpuType(This,newVal) ) 

#define IActMLProgType_get_ActPacketType(This,pVal)	\
    ( (This)->lpVtbl -> get_ActPacketType(This,pVal) ) 

#define IActMLProgType_put_ActPacketType(This,newVal)	\
    ( (This)->lpVtbl -> put_ActPacketType(This,newVal) ) 

#define IActMLProgType_get_ActPortNumber(This,pVal)	\
    ( (This)->lpVtbl -> get_ActPortNumber(This,pVal) ) 

#define IActMLProgType_put_ActPortNumber(This,newVal)	\
    ( (This)->lpVtbl -> put_ActPortNumber(This,newVal) ) 

#define IActMLProgType_get_ActBaudRate(This,pVal)	\
    ( (This)->lpVtbl -> get_ActBaudRate(This,pVal) ) 

#define IActMLProgType_put_ActBaudRate(This,newVal)	\
    ( (This)->lpVtbl -> put_ActBaudRate(This,newVal) ) 

#define IActMLProgType_get_ActDataBits(This,pVal)	\
    ( (This)->lpVtbl -> get_ActDataBits(This,pVal) ) 

#define IActMLProgType_put_ActDataBits(This,newVal)	\
    ( (This)->lpVtbl -> put_ActDataBits(This,newVal) ) 

#define IActMLProgType_get_ActParity(This,pVal)	\
    ( (This)->lpVtbl -> get_ActParity(This,pVal) ) 

#define IActMLProgType_put_ActParity(This,newVal)	\
    ( (This)->lpVtbl -> put_ActParity(This,newVal) ) 

#define IActMLProgType_get_ActStopBits(This,pVal)	\
    ( (This)->lpVtbl -> get_ActStopBits(This,pVal) ) 

#define IActMLProgType_put_ActStopBits(This,newVal)	\
    ( (This)->lpVtbl -> put_ActStopBits(This,newVal) ) 

#define IActMLProgType_get_ActControl(This,pVal)	\
    ( (This)->lpVtbl -> get_ActControl(This,pVal) ) 

#define IActMLProgType_put_ActControl(This,newVal)	\
    ( (This)->lpVtbl -> put_ActControl(This,newVal) ) 

#define IActMLProgType_get_ActHostAddress(This,pVal)	\
    ( (This)->lpVtbl -> get_ActHostAddress(This,pVal) ) 

#define IActMLProgType_put_ActHostAddress(This,newVal)	\
    ( (This)->lpVtbl -> put_ActHostAddress(This,newVal) ) 

#define IActMLProgType_get_ActCpuTimeOut(This,pVal)	\
    ( (This)->lpVtbl -> get_ActCpuTimeOut(This,pVal) ) 

#define IActMLProgType_put_ActCpuTimeOut(This,newVal)	\
    ( (This)->lpVtbl -> put_ActCpuTimeOut(This,newVal) ) 

#define IActMLProgType_get_ActTimeOut(This,pVal)	\
    ( (This)->lpVtbl -> get_ActTimeOut(This,pVal) ) 

#define IActMLProgType_put_ActTimeOut(This,newVal)	\
    ( (This)->lpVtbl -> put_ActTimeOut(This,newVal) ) 

#define IActMLProgType_get_ActSumCheck(This,pVal)	\
    ( (This)->lpVtbl -> get_ActSumCheck(This,pVal) ) 

#define IActMLProgType_put_ActSumCheck(This,newVal)	\
    ( (This)->lpVtbl -> put_ActSumCheck(This,newVal) ) 

#define IActMLProgType_get_ActSourceNetworkNumber(This,pVal)	\
    ( (This)->lpVtbl -> get_ActSourceNetworkNumber(This,pVal) ) 

#define IActMLProgType_put_ActSourceNetworkNumber(This,newVal)	\
    ( (This)->lpVtbl -> put_ActSourceNetworkNumber(This,newVal) ) 

#define IActMLProgType_get_ActSourceStationNumber(This,pVal)	\
    ( (This)->lpVtbl -> get_ActSourceStationNumber(This,pVal) ) 

#define IActMLProgType_put_ActSourceStationNumber(This,newVal)	\
    ( (This)->lpVtbl -> put_ActSourceStationNumber(This,newVal) ) 

#define IActMLProgType_get_ActDestinationPortNumber(This,pVal)	\
    ( (This)->lpVtbl -> get_ActDestinationPortNumber(This,pVal) ) 

#define IActMLProgType_put_ActDestinationPortNumber(This,newVal)	\
    ( (This)->lpVtbl -> put_ActDestinationPortNumber(This,newVal) ) 

#define IActMLProgType_get_ActDestinationIONumber(This,pVal)	\
    ( (This)->lpVtbl -> get_ActDestinationIONumber(This,pVal) ) 

#define IActMLProgType_put_ActDestinationIONumber(This,newVal)	\
    ( (This)->lpVtbl -> put_ActDestinationIONumber(This,newVal) ) 

#define IActMLProgType_get_ActMultiDropChannelNumber(This,pVal)	\
    ( (This)->lpVtbl -> get_ActMultiDropChannelNumber(This,pVal) ) 

#define IActMLProgType_put_ActMultiDropChannelNumber(This,newVal)	\
    ( (This)->lpVtbl -> put_ActMultiDropChannelNumber(This,newVal) ) 

#define IActMLProgType_get_ActThroughNetworkType(This,pVal)	\
    ( (This)->lpVtbl -> get_ActThroughNetworkType(This,pVal) ) 

#define IActMLProgType_put_ActThroughNetworkType(This,newVal)	\
    ( (This)->lpVtbl -> put_ActThroughNetworkType(This,newVal) ) 

#define IActMLProgType_get_ActIntelligentPreferenceBit(This,pVal)	\
    ( (This)->lpVtbl -> get_ActIntelligentPreferenceBit(This,pVal) ) 

#define IActMLProgType_put_ActIntelligentPreferenceBit(This,newVal)	\
    ( (This)->lpVtbl -> put_ActIntelligentPreferenceBit(This,newVal) ) 

#define IActMLProgType_get_ActDidPropertyBit(This,pVal)	\
    ( (This)->lpVtbl -> get_ActDidPropertyBit(This,pVal) ) 

#define IActMLProgType_put_ActDidPropertyBit(This,newVal)	\
    ( (This)->lpVtbl -> put_ActDidPropertyBit(This,newVal) ) 

#define IActMLProgType_get_ActDsidPropertyBit(This,pVal)	\
    ( (This)->lpVtbl -> get_ActDsidPropertyBit(This,pVal) ) 

#define IActMLProgType_put_ActDsidPropertyBit(This,newVal)	\
    ( (This)->lpVtbl -> put_ActDsidPropertyBit(This,newVal) ) 

#define IActMLProgType_get_ActPassword(This,pVal)	\
    ( (This)->lpVtbl -> get_ActPassword(This,pVal) ) 

#define IActMLProgType_put_ActPassword(This,newVal)	\
    ( (This)->lpVtbl -> put_ActPassword(This,newVal) ) 

#define IActMLProgType_get_ActTargetSimulator(This,pVal)	\
    ( (This)->lpVtbl -> get_ActTargetSimulator(This,pVal) ) 

#define IActMLProgType_put_ActTargetSimulator(This,newVal)	\
    ( (This)->lpVtbl -> put_ActTargetSimulator(This,newVal) ) 

#define IActMLProgType_Open(This,lpvarReturnCode)	\
    ( (This)->lpVtbl -> Open(This,lpvarReturnCode) ) 

#define IActMLProgType_Close(This,lpvarReturnCode)	\
    ( (This)->lpVtbl -> Close(This,lpvarReturnCode) ) 

#define IActMLProgType_GetCpuType(This,lpvarCpuName,lpvarCpuCode,lpvarReturnCode)	\
    ( (This)->lpVtbl -> GetCpuType(This,lpvarCpuName,lpvarCpuCode,lpvarReturnCode) ) 

#define IActMLProgType_SetCpuStatus(This,varOperation,lpvarReturnCode)	\
    ( (This)->lpVtbl -> SetCpuStatus(This,varOperation,lpvarReturnCode) ) 

#define IActMLProgType_ReadDeviceBlock(This,varDevice,varSize,lpvarData,lpvarReturnCode)	\
    ( (This)->lpVtbl -> ReadDeviceBlock(This,varDevice,varSize,lpvarData,lpvarReturnCode) ) 

#define IActMLProgType_WriteDeviceBlock(This,varDevice,varSize,varData,lpvarReturnCode)	\
    ( (This)->lpVtbl -> WriteDeviceBlock(This,varDevice,varSize,varData,lpvarReturnCode) ) 

#define IActMLProgType_ReadDeviceRandom(This,varDeviceList,varSize,lpvarData,lpvarReturnCode)	\
    ( (This)->lpVtbl -> ReadDeviceRandom(This,varDeviceList,varSize,lpvarData,lpvarReturnCode) ) 

#define IActMLProgType_WriteDeviceRandom(This,varDeviceList,varSize,varData,lpvarReturnCode)	\
    ( (This)->lpVtbl -> WriteDeviceRandom(This,varDeviceList,varSize,varData,lpvarReturnCode) ) 

#define IActMLProgType_ReadBuffer(This,varStartIO,varAddress,varReadSize,lpvarData,lpvarReturnCode)	\
    ( (This)->lpVtbl -> ReadBuffer(This,varStartIO,varAddress,varReadSize,lpvarData,lpvarReturnCode) ) 

#define IActMLProgType_WriteBuffer(This,varStartIO,varAddress,varWriteSize,varData,lpvarReturnCode)	\
    ( (This)->lpVtbl -> WriteBuffer(This,varStartIO,varAddress,varWriteSize,varData,lpvarReturnCode) ) 

#define IActMLProgType_GetClockData(This,lpvarYear,lpvarMonth,lpvarDay,lpvarDayOfWeek,lpvarHour,lpvarMinute,lpvarSecond,lpvarReturnCode)	\
    ( (This)->lpVtbl -> GetClockData(This,lpvarYear,lpvarMonth,lpvarDay,lpvarDayOfWeek,lpvarHour,lpvarMinute,lpvarSecond,lpvarReturnCode) ) 

#define IActMLProgType_SetClockData(This,varYear,varMonth,varDay,varDayOfWeek,varHour,varMinute,varSecond,lpvarReturnCode)	\
    ( (This)->lpVtbl -> SetClockData(This,varYear,varMonth,varDay,varDayOfWeek,varHour,varMinute,varSecond,lpvarReturnCode) ) 

#define IActMLProgType_SetDevice(This,varDevice,varData,lpvarReturnCode)	\
    ( (This)->lpVtbl -> SetDevice(This,varDevice,varData,lpvarReturnCode) ) 

#define IActMLProgType_GetDevice(This,varDevice,lpvarData,lpvarReturnCode)	\
    ( (This)->lpVtbl -> GetDevice(This,varDevice,lpvarData,lpvarReturnCode) ) 

#define IActMLProgType_EntryDeviceStatus(This,varDeviceList,varSize,varMonitorCycle,varData,lpvarReturnCode)	\
    ( (This)->lpVtbl -> EntryDeviceStatus(This,varDeviceList,varSize,varMonitorCycle,varData,lpvarReturnCode) ) 

#define IActMLProgType_FreeDeviceStatus(This,lpvarReturnCode)	\
    ( (This)->lpVtbl -> FreeDeviceStatus(This,lpvarReturnCode) ) 

#define IActMLProgType_ReadDeviceBlock2(This,varDevice,varSize,lpvarData,lpvarReturnCode)	\
    ( (This)->lpVtbl -> ReadDeviceBlock2(This,varDevice,varSize,lpvarData,lpvarReturnCode) ) 

#define IActMLProgType_WriteDeviceBlock2(This,varDevice,varSize,varData,lpvarReturnCode)	\
    ( (This)->lpVtbl -> WriteDeviceBlock2(This,varDevice,varSize,varData,lpvarReturnCode) ) 

#define IActMLProgType_ReadDeviceRandom2(This,varDeviceList,varSize,lpvarData,lpvarReturnCode)	\
    ( (This)->lpVtbl -> ReadDeviceRandom2(This,varDeviceList,varSize,lpvarData,lpvarReturnCode) ) 

#define IActMLProgType_WriteDeviceRandom2(This,varDeviceList,varSize,varData,lpvarReturnCode)	\
    ( (This)->lpVtbl -> WriteDeviceRandom2(This,varDeviceList,varSize,varData,lpvarReturnCode) ) 

#define IActMLProgType_GetDevice2(This,varDevice,lpvarData,lpvarReturnCode)	\
    ( (This)->lpVtbl -> GetDevice2(This,varDevice,lpvarData,lpvarReturnCode) ) 

#define IActMLProgType_SetDevice2(This,varDevice,varData,lpvarReturnCode)	\
    ( (This)->lpVtbl -> SetDevice2(This,varDevice,varData,lpvarReturnCode) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IActMLProgType_INTERFACE_DEFINED__ */



#ifndef __ActProgTypeLib_LIBRARY_DEFINED__
#define __ActProgTypeLib_LIBRARY_DEFINED__

/* library ActProgTypeLib */
/* [helpstring][version][uuid] */ 


EXTERN_C const IID LIBID_ActProgTypeLib;

#ifndef ___IActProgTypeEvents_DISPINTERFACE_DEFINED__
#define ___IActProgTypeEvents_DISPINTERFACE_DEFINED__

/* dispinterface _IActProgTypeEvents */
/* [helpstring][uuid] */ 


EXTERN_C const IID DIID__IActProgTypeEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("1DA9A278-2C46-4EDE-8D65-7D3BC9592816")
    _IActProgTypeEvents : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct _IActProgTypeEventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            _IActProgTypeEvents * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            _IActProgTypeEvents * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            _IActProgTypeEvents * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            _IActProgTypeEvents * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            _IActProgTypeEvents * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            _IActProgTypeEvents * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            _IActProgTypeEvents * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        END_INTERFACE
    } _IActProgTypeEventsVtbl;

    interface _IActProgTypeEvents
    {
        CONST_VTBL struct _IActProgTypeEventsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _IActProgTypeEvents_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define _IActProgTypeEvents_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define _IActProgTypeEvents_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define _IActProgTypeEvents_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define _IActProgTypeEvents_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define _IActProgTypeEvents_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define _IActProgTypeEvents_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ___IActProgTypeEvents_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_ActProgType;

#ifdef __cplusplus

class DECLSPEC_UUID("78703D55-4042-4046-845D-7BBE83FB2F44")
ActProgType;
#endif

#ifndef ___IActMLProgTypeEvents_DISPINTERFACE_DEFINED__
#define ___IActMLProgTypeEvents_DISPINTERFACE_DEFINED__

/* dispinterface _IActMLProgTypeEvents */
/* [helpstring][uuid] */ 


EXTERN_C const IID DIID__IActMLProgTypeEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("8CA3FFF9-D42E-4782-8F74-6AEAE7F353EC")
    _IActMLProgTypeEvents : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct _IActMLProgTypeEventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            _IActMLProgTypeEvents * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            _IActMLProgTypeEvents * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            _IActMLProgTypeEvents * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            _IActMLProgTypeEvents * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            _IActMLProgTypeEvents * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            _IActMLProgTypeEvents * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            _IActMLProgTypeEvents * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        END_INTERFACE
    } _IActMLProgTypeEventsVtbl;

    interface _IActMLProgTypeEvents
    {
        CONST_VTBL struct _IActMLProgTypeEventsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _IActMLProgTypeEvents_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define _IActMLProgTypeEvents_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define _IActMLProgTypeEvents_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define _IActMLProgTypeEvents_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define _IActMLProgTypeEvents_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define _IActMLProgTypeEvents_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define _IActMLProgTypeEvents_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ___IActMLProgTypeEvents_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_ActMLProgType;

#ifdef __cplusplus

class DECLSPEC_UUID("D10D1FE3-1D76-4B8B-ADFC-CE03F9337CD3")
ActMLProgType;
#endif
#endif /* __ActProgTypeLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

unsigned long             __RPC_USER  BSTR_UserSize(     unsigned long *, unsigned long            , BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserMarshal(  unsigned long *, unsigned char *, BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserUnmarshal(unsigned long *, unsigned char *, BSTR * ); 
void                      __RPC_USER  BSTR_UserFree(     unsigned long *, BSTR * ); 

unsigned long             __RPC_USER  VARIANT_UserSize(     unsigned long *, unsigned long            , VARIANT * ); 
unsigned char * __RPC_USER  VARIANT_UserMarshal(  unsigned long *, unsigned char *, VARIANT * ); 
unsigned char * __RPC_USER  VARIANT_UserUnmarshal(unsigned long *, unsigned char *, VARIANT * ); 
void                      __RPC_USER  VARIANT_UserFree(     unsigned long *, VARIANT * ); 

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


