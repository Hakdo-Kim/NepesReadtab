/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 5.01.0164 */
/* at Fri Apr 12 12:32:59 2013
 */
/* Compiler settings for D:\GETMODULE\CommunicationSupport2\SW3D5\ACT\Control\ActPcUsb\ActPcUsb.idl:
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

#ifndef __ActPcUsb_h__
#define __ActPcUsb_h__

#ifdef __cplusplus
extern "C"{
#endif 

/* Forward Declarations */ 

#ifndef __IActQCPUQUSB_FWD_DEFINED__
#define __IActQCPUQUSB_FWD_DEFINED__
typedef interface IActQCPUQUSB IActQCPUQUSB;
#endif 	/* __IActQCPUQUSB_FWD_DEFINED__ */


#ifndef __IActQCPUQUSB2_FWD_DEFINED__
#define __IActQCPUQUSB2_FWD_DEFINED__
typedef interface IActQCPUQUSB2 IActQCPUQUSB2;
#endif 	/* __IActQCPUQUSB2_FWD_DEFINED__ */


#ifndef __IActQCPUQUSB3_FWD_DEFINED__
#define __IActQCPUQUSB3_FWD_DEFINED__
typedef interface IActQCPUQUSB3 IActQCPUQUSB3;
#endif 	/* __IActQCPUQUSB3_FWD_DEFINED__ */


#ifndef __IActMLQCPUQUSB_FWD_DEFINED__
#define __IActMLQCPUQUSB_FWD_DEFINED__
typedef interface IActMLQCPUQUSB IActMLQCPUQUSB;
#endif 	/* __IActMLQCPUQUSB_FWD_DEFINED__ */


#ifndef __IActMLQCPUQUSB2_FWD_DEFINED__
#define __IActMLQCPUQUSB2_FWD_DEFINED__
typedef interface IActMLQCPUQUSB2 IActMLQCPUQUSB2;
#endif 	/* __IActMLQCPUQUSB2_FWD_DEFINED__ */


#ifndef __IActMLQCPUQUSB3_FWD_DEFINED__
#define __IActMLQCPUQUSB3_FWD_DEFINED__
typedef interface IActMLQCPUQUSB3 IActMLQCPUQUSB3;
#endif 	/* __IActMLQCPUQUSB3_FWD_DEFINED__ */


#ifndef __IActFXCPUUSB_FWD_DEFINED__
#define __IActFXCPUUSB_FWD_DEFINED__
typedef interface IActFXCPUUSB IActFXCPUUSB;
#endif 	/* __IActFXCPUUSB_FWD_DEFINED__ */


#ifndef __IActFXCPUUSB2_FWD_DEFINED__
#define __IActFXCPUUSB2_FWD_DEFINED__
typedef interface IActFXCPUUSB2 IActFXCPUUSB2;
#endif 	/* __IActFXCPUUSB2_FWD_DEFINED__ */


#ifndef __IActFXCPUUSB3_FWD_DEFINED__
#define __IActFXCPUUSB3_FWD_DEFINED__
typedef interface IActFXCPUUSB3 IActFXCPUUSB3;
#endif 	/* __IActFXCPUUSB3_FWD_DEFINED__ */


#ifndef __IActMLFXCPUUSB_FWD_DEFINED__
#define __IActMLFXCPUUSB_FWD_DEFINED__
typedef interface IActMLFXCPUUSB IActMLFXCPUUSB;
#endif 	/* __IActMLFXCPUUSB_FWD_DEFINED__ */


#ifndef __IActMLFXCPUUSB2_FWD_DEFINED__
#define __IActMLFXCPUUSB2_FWD_DEFINED__
typedef interface IActMLFXCPUUSB2 IActMLFXCPUUSB2;
#endif 	/* __IActMLFXCPUUSB2_FWD_DEFINED__ */


#ifndef __IActMLFXCPUUSB3_FWD_DEFINED__
#define __IActMLFXCPUUSB3_FWD_DEFINED__
typedef interface IActMLFXCPUUSB3 IActMLFXCPUUSB3;
#endif 	/* __IActMLFXCPUUSB3_FWD_DEFINED__ */


#ifndef __IActLCPUUSB_FWD_DEFINED__
#define __IActLCPUUSB_FWD_DEFINED__
typedef interface IActLCPUUSB IActLCPUUSB;
#endif 	/* __IActLCPUUSB_FWD_DEFINED__ */


#ifndef __IActLCPUUSB2_FWD_DEFINED__
#define __IActLCPUUSB2_FWD_DEFINED__
typedef interface IActLCPUUSB2 IActLCPUUSB2;
#endif 	/* __IActLCPUUSB2_FWD_DEFINED__ */


#ifndef __IActLCPUUSB3_FWD_DEFINED__
#define __IActLCPUUSB3_FWD_DEFINED__
typedef interface IActLCPUUSB3 IActLCPUUSB3;
#endif 	/* __IActLCPUUSB3_FWD_DEFINED__ */


#ifndef __IActMLLCPUUSB_FWD_DEFINED__
#define __IActMLLCPUUSB_FWD_DEFINED__
typedef interface IActMLLCPUUSB IActMLLCPUUSB;
#endif 	/* __IActMLLCPUUSB_FWD_DEFINED__ */


#ifndef __IActMLLCPUUSB2_FWD_DEFINED__
#define __IActMLLCPUUSB2_FWD_DEFINED__
typedef interface IActMLLCPUUSB2 IActMLLCPUUSB2;
#endif 	/* __IActMLLCPUUSB2_FWD_DEFINED__ */


#ifndef __IActMLLCPUUSB3_FWD_DEFINED__
#define __IActMLLCPUUSB3_FWD_DEFINED__
typedef interface IActMLLCPUUSB3 IActMLLCPUUSB3;
#endif 	/* __IActMLLCPUUSB3_FWD_DEFINED__ */


#ifndef ___IActQCPUQUSBEvents_FWD_DEFINED__
#define ___IActQCPUQUSBEvents_FWD_DEFINED__
typedef interface _IActQCPUQUSBEvents _IActQCPUQUSBEvents;
#endif 	/* ___IActQCPUQUSBEvents_FWD_DEFINED__ */


#ifndef __ActQCPUQUSB_FWD_DEFINED__
#define __ActQCPUQUSB_FWD_DEFINED__

#ifdef __cplusplus
typedef class ActQCPUQUSB ActQCPUQUSB;
#else
typedef struct ActQCPUQUSB ActQCPUQUSB;
#endif /* __cplusplus */

#endif 	/* __ActQCPUQUSB_FWD_DEFINED__ */


#ifndef ___IActMLQCPUQUSBEvents_FWD_DEFINED__
#define ___IActMLQCPUQUSBEvents_FWD_DEFINED__
typedef interface _IActMLQCPUQUSBEvents _IActMLQCPUQUSBEvents;
#endif 	/* ___IActMLQCPUQUSBEvents_FWD_DEFINED__ */


#ifndef __ActMLQCPUQUSB_FWD_DEFINED__
#define __ActMLQCPUQUSB_FWD_DEFINED__

#ifdef __cplusplus
typedef class ActMLQCPUQUSB ActMLQCPUQUSB;
#else
typedef struct ActMLQCPUQUSB ActMLQCPUQUSB;
#endif /* __cplusplus */

#endif 	/* __ActMLQCPUQUSB_FWD_DEFINED__ */


#ifndef ___IActFXCPUUSBEvents_FWD_DEFINED__
#define ___IActFXCPUUSBEvents_FWD_DEFINED__
typedef interface _IActFXCPUUSBEvents _IActFXCPUUSBEvents;
#endif 	/* ___IActFXCPUUSBEvents_FWD_DEFINED__ */


#ifndef __ActFXCPUUSB_FWD_DEFINED__
#define __ActFXCPUUSB_FWD_DEFINED__

#ifdef __cplusplus
typedef class ActFXCPUUSB ActFXCPUUSB;
#else
typedef struct ActFXCPUUSB ActFXCPUUSB;
#endif /* __cplusplus */

#endif 	/* __ActFXCPUUSB_FWD_DEFINED__ */


#ifndef ___IActMLFXCPUUSBEvents_FWD_DEFINED__
#define ___IActMLFXCPUUSBEvents_FWD_DEFINED__
typedef interface _IActMLFXCPUUSBEvents _IActMLFXCPUUSBEvents;
#endif 	/* ___IActMLFXCPUUSBEvents_FWD_DEFINED__ */


#ifndef __ActMLFXCPUUSB_FWD_DEFINED__
#define __ActMLFXCPUUSB_FWD_DEFINED__

#ifdef __cplusplus
typedef class ActMLFXCPUUSB ActMLFXCPUUSB;
#else
typedef struct ActMLFXCPUUSB ActMLFXCPUUSB;
#endif /* __cplusplus */

#endif 	/* __ActMLFXCPUUSB_FWD_DEFINED__ */


#ifndef ___IActLCPUUSBEvents_FWD_DEFINED__
#define ___IActLCPUUSBEvents_FWD_DEFINED__
typedef interface _IActLCPUUSBEvents _IActLCPUUSBEvents;
#endif 	/* ___IActLCPUUSBEvents_FWD_DEFINED__ */


#ifndef __ActLCPUUSB_FWD_DEFINED__
#define __ActLCPUUSB_FWD_DEFINED__

#ifdef __cplusplus
typedef class ActLCPUUSB ActLCPUUSB;
#else
typedef struct ActLCPUUSB ActLCPUUSB;
#endif /* __cplusplus */

#endif 	/* __ActLCPUUSB_FWD_DEFINED__ */


#ifndef ___IActMLLCPUUSBEvents_FWD_DEFINED__
#define ___IActMLLCPUUSBEvents_FWD_DEFINED__
typedef interface _IActMLLCPUUSBEvents _IActMLLCPUUSBEvents;
#endif 	/* ___IActMLLCPUUSBEvents_FWD_DEFINED__ */


#ifndef __ActMLLCPUUSB_FWD_DEFINED__
#define __ActMLLCPUUSB_FWD_DEFINED__

#ifdef __cplusplus
typedef class ActMLLCPUUSB ActMLLCPUUSB;
#else
typedef struct ActMLLCPUUSB ActMLLCPUUSB;
#endif /* __cplusplus */

#endif 	/* __ActMLLCPUUSB_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

void __RPC_FAR * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void __RPC_FAR * ); 

#ifndef __IActQCPUQUSB_INTERFACE_DEFINED__
#define __IActQCPUQUSB_INTERFACE_DEFINED__

/* interface IActQCPUQUSB */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IActQCPUQUSB;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("B5BDE861-AEA9-11D3-83AE-00A024BDBF2B")
    IActQCPUQUSB : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Open( 
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Close( 
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ReadDeviceBlock( 
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG dwSize,
            /* [size_is][out] */ LONG __RPC_FAR *lpdwData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE WriteDeviceBlock( 
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG dwSize,
            /* [size_is][in] */ LONG __RPC_FAR *lpdwData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ReadDeviceRandom( 
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG dwSize,
            /* [size_is][out] */ LONG __RPC_FAR *lpdwData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE WriteDeviceRandom( 
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG dwSize,
            /* [size_is][in] */ LONG __RPC_FAR *lpdwData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ReadBuffer( 
            /* [in] */ LONG lStartIO,
            /* [in] */ LONG lAddress,
            /* [in] */ LONG lReadSize,
            /* [size_is][out] */ SHORT __RPC_FAR *lpwData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE WriteBuffer( 
            /* [in] */ LONG lStartIO,
            /* [in] */ LONG lAddress,
            /* [in] */ LONG lWriteSize,
            /* [size_is][in] */ SHORT __RPC_FAR *lpwData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetClockData( 
            /* [out] */ SHORT __RPC_FAR *lpwYear,
            /* [out] */ SHORT __RPC_FAR *lpwMonth,
            /* [out] */ SHORT __RPC_FAR *lpwDay,
            /* [out] */ SHORT __RPC_FAR *lpwDayOfWeek,
            /* [out] */ SHORT __RPC_FAR *lpwHour,
            /* [out] */ SHORT __RPC_FAR *lpwMinute,
            /* [out] */ SHORT __RPC_FAR *lpwSecond,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetClockData( 
            /* [in] */ SHORT wYear,
            /* [in] */ SHORT wMonth,
            /* [in] */ SHORT wDay,
            /* [in] */ SHORT wDayOfWeek,
            /* [in] */ SHORT wHour,
            /* [in] */ SHORT wMinute,
            /* [in] */ SHORT wSecond,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetDevice( 
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG dwData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetCpuStatus( 
            /* [in] */ LONG lOperation,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetCpuType( 
            /* [string][out] */ BSTR __RPC_FAR *lpszCpuName,
            /* [out] */ LONG __RPC_FAR *lplCpuType,
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
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetDevice( 
            /* [string][in] */ BSTR szDevice,
            /* [out] */ LONG __RPC_FAR *lpdwData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE CheckDeviceString( 
            /* [in] */ BSTR szDevice,
            /* [in] */ LONG lCheckType,
            /* [in] */ LONG lSize,
            /* [out] */ LONG __RPC_FAR *lplDeviceType,
            /* [string][out] */ BSTR __RPC_FAR *lpszDeviceName,
            /* [out] */ LONG __RPC_FAR *lplDeviceNumber,
            /* [out] */ LONG __RPC_FAR *lplDeviceRadix,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IActQCPUQUSBVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IActQCPUQUSB __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IActQCPUQUSB __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IActQCPUQUSB __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IActQCPUQUSB __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IActQCPUQUSB __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IActQCPUQUSB __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IActQCPUQUSB __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Open )( 
            IActQCPUQUSB __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Close )( 
            IActQCPUQUSB __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceBlock )( 
            IActQCPUQUSB __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG dwSize,
            /* [size_is][out] */ LONG __RPC_FAR *lpdwData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceBlock )( 
            IActQCPUQUSB __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG dwSize,
            /* [size_is][in] */ LONG __RPC_FAR *lpdwData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceRandom )( 
            IActQCPUQUSB __RPC_FAR * This,
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG dwSize,
            /* [size_is][out] */ LONG __RPC_FAR *lpdwData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceRandom )( 
            IActQCPUQUSB __RPC_FAR * This,
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG dwSize,
            /* [size_is][in] */ LONG __RPC_FAR *lpdwData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadBuffer )( 
            IActQCPUQUSB __RPC_FAR * This,
            /* [in] */ LONG lStartIO,
            /* [in] */ LONG lAddress,
            /* [in] */ LONG lReadSize,
            /* [size_is][out] */ SHORT __RPC_FAR *lpwData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteBuffer )( 
            IActQCPUQUSB __RPC_FAR * This,
            /* [in] */ LONG lStartIO,
            /* [in] */ LONG lAddress,
            /* [in] */ LONG lWriteSize,
            /* [size_is][in] */ SHORT __RPC_FAR *lpwData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetClockData )( 
            IActQCPUQUSB __RPC_FAR * This,
            /* [out] */ SHORT __RPC_FAR *lpwYear,
            /* [out] */ SHORT __RPC_FAR *lpwMonth,
            /* [out] */ SHORT __RPC_FAR *lpwDay,
            /* [out] */ SHORT __RPC_FAR *lpwDayOfWeek,
            /* [out] */ SHORT __RPC_FAR *lpwHour,
            /* [out] */ SHORT __RPC_FAR *lpwMinute,
            /* [out] */ SHORT __RPC_FAR *lpwSecond,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetClockData )( 
            IActQCPUQUSB __RPC_FAR * This,
            /* [in] */ SHORT wYear,
            /* [in] */ SHORT wMonth,
            /* [in] */ SHORT wDay,
            /* [in] */ SHORT wDayOfWeek,
            /* [in] */ SHORT wHour,
            /* [in] */ SHORT wMinute,
            /* [in] */ SHORT wSecond,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetDevice )( 
            IActQCPUQUSB __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG dwData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetCpuStatus )( 
            IActQCPUQUSB __RPC_FAR * This,
            /* [in] */ LONG lOperation,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetCpuType )( 
            IActQCPUQUSB __RPC_FAR * This,
            /* [string][out] */ BSTR __RPC_FAR *lpszCpuName,
            /* [out] */ LONG __RPC_FAR *lplCpuType,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActNetworkNumber )( 
            IActQCPUQUSB __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActNetworkNumber )( 
            IActQCPUQUSB __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActStationNumber )( 
            IActQCPUQUSB __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActStationNumber )( 
            IActQCPUQUSB __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActUnitNumber )( 
            IActQCPUQUSB __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActUnitNumber )( 
            IActQCPUQUSB __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActIONumber )( 
            IActQCPUQUSB __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActIONumber )( 
            IActQCPUQUSB __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActCpuType )( 
            IActQCPUQUSB __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActCpuType )( 
            IActQCPUQUSB __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActTimeOut )( 
            IActQCPUQUSB __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActTimeOut )( 
            IActQCPUQUSB __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActDestinationIONumber )( 
            IActQCPUQUSB __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActDestinationIONumber )( 
            IActQCPUQUSB __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActMultiDropChannelNumber )( 
            IActQCPUQUSB __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActMultiDropChannelNumber )( 
            IActQCPUQUSB __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActThroughNetworkType )( 
            IActQCPUQUSB __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActThroughNetworkType )( 
            IActQCPUQUSB __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActIntelligentPreferenceBit )( 
            IActQCPUQUSB __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActIntelligentPreferenceBit )( 
            IActQCPUQUSB __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActDidPropertyBit )( 
            IActQCPUQUSB __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActDidPropertyBit )( 
            IActQCPUQUSB __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActDsidPropertyBit )( 
            IActQCPUQUSB __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActDsidPropertyBit )( 
            IActQCPUQUSB __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetDevice )( 
            IActQCPUQUSB __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [out] */ LONG __RPC_FAR *lpdwData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CheckDeviceString )( 
            IActQCPUQUSB __RPC_FAR * This,
            /* [in] */ BSTR szDevice,
            /* [in] */ LONG lCheckType,
            /* [in] */ LONG lSize,
            /* [out] */ LONG __RPC_FAR *lplDeviceType,
            /* [string][out] */ BSTR __RPC_FAR *lpszDeviceName,
            /* [out] */ LONG __RPC_FAR *lplDeviceNumber,
            /* [out] */ LONG __RPC_FAR *lplDeviceRadix,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        END_INTERFACE
    } IActQCPUQUSBVtbl;

    interface IActQCPUQUSB
    {
        CONST_VTBL struct IActQCPUQUSBVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IActQCPUQUSB_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IActQCPUQUSB_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IActQCPUQUSB_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IActQCPUQUSB_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IActQCPUQUSB_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IActQCPUQUSB_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IActQCPUQUSB_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IActQCPUQUSB_Open(This,lplReturnCode)	\
    (This)->lpVtbl -> Open(This,lplReturnCode)

#define IActQCPUQUSB_Close(This,lplReturnCode)	\
    (This)->lpVtbl -> Close(This,lplReturnCode)

#define IActQCPUQUSB_ReadDeviceBlock(This,szDevice,dwSize,lpdwData,lplReturnCode)	\
    (This)->lpVtbl -> ReadDeviceBlock(This,szDevice,dwSize,lpdwData,lplReturnCode)

#define IActQCPUQUSB_WriteDeviceBlock(This,szDevice,dwSize,lpdwData,lplReturnCode)	\
    (This)->lpVtbl -> WriteDeviceBlock(This,szDevice,dwSize,lpdwData,lplReturnCode)

#define IActQCPUQUSB_ReadDeviceRandom(This,szDeviceList,dwSize,lpdwData,lplReturnCode)	\
    (This)->lpVtbl -> ReadDeviceRandom(This,szDeviceList,dwSize,lpdwData,lplReturnCode)

#define IActQCPUQUSB_WriteDeviceRandom(This,szDeviceList,dwSize,lpdwData,lplReturnCode)	\
    (This)->lpVtbl -> WriteDeviceRandom(This,szDeviceList,dwSize,lpdwData,lplReturnCode)

#define IActQCPUQUSB_ReadBuffer(This,lStartIO,lAddress,lReadSize,lpwData,lplReturnCode)	\
    (This)->lpVtbl -> ReadBuffer(This,lStartIO,lAddress,lReadSize,lpwData,lplReturnCode)

#define IActQCPUQUSB_WriteBuffer(This,lStartIO,lAddress,lWriteSize,lpwData,lplReturnCode)	\
    (This)->lpVtbl -> WriteBuffer(This,lStartIO,lAddress,lWriteSize,lpwData,lplReturnCode)

#define IActQCPUQUSB_GetClockData(This,lpwYear,lpwMonth,lpwDay,lpwDayOfWeek,lpwHour,lpwMinute,lpwSecond,lplReturnCode)	\
    (This)->lpVtbl -> GetClockData(This,lpwYear,lpwMonth,lpwDay,lpwDayOfWeek,lpwHour,lpwMinute,lpwSecond,lplReturnCode)

#define IActQCPUQUSB_SetClockData(This,wYear,wMonth,wDay,wDayOfWeek,wHour,wMinute,wSecond,lplReturnCode)	\
    (This)->lpVtbl -> SetClockData(This,wYear,wMonth,wDay,wDayOfWeek,wHour,wMinute,wSecond,lplReturnCode)

#define IActQCPUQUSB_SetDevice(This,szDevice,dwData,lplReturnCode)	\
    (This)->lpVtbl -> SetDevice(This,szDevice,dwData,lplReturnCode)

#define IActQCPUQUSB_SetCpuStatus(This,lOperation,lplReturnCode)	\
    (This)->lpVtbl -> SetCpuStatus(This,lOperation,lplReturnCode)

#define IActQCPUQUSB_GetCpuType(This,lpszCpuName,lplCpuType,lplReturnCode)	\
    (This)->lpVtbl -> GetCpuType(This,lpszCpuName,lplCpuType,lplReturnCode)

#define IActQCPUQUSB_get_ActNetworkNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActNetworkNumber(This,pVal)

#define IActQCPUQUSB_put_ActNetworkNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActNetworkNumber(This,newVal)

#define IActQCPUQUSB_get_ActStationNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActStationNumber(This,pVal)

#define IActQCPUQUSB_put_ActStationNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActStationNumber(This,newVal)

#define IActQCPUQUSB_get_ActUnitNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActUnitNumber(This,pVal)

#define IActQCPUQUSB_put_ActUnitNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActUnitNumber(This,newVal)

#define IActQCPUQUSB_get_ActIONumber(This,pVal)	\
    (This)->lpVtbl -> get_ActIONumber(This,pVal)

#define IActQCPUQUSB_put_ActIONumber(This,newVal)	\
    (This)->lpVtbl -> put_ActIONumber(This,newVal)

#define IActQCPUQUSB_get_ActCpuType(This,pVal)	\
    (This)->lpVtbl -> get_ActCpuType(This,pVal)

#define IActQCPUQUSB_put_ActCpuType(This,newVal)	\
    (This)->lpVtbl -> put_ActCpuType(This,newVal)

#define IActQCPUQUSB_get_ActTimeOut(This,pVal)	\
    (This)->lpVtbl -> get_ActTimeOut(This,pVal)

#define IActQCPUQUSB_put_ActTimeOut(This,newVal)	\
    (This)->lpVtbl -> put_ActTimeOut(This,newVal)

#define IActQCPUQUSB_get_ActDestinationIONumber(This,pVal)	\
    (This)->lpVtbl -> get_ActDestinationIONumber(This,pVal)

#define IActQCPUQUSB_put_ActDestinationIONumber(This,newVal)	\
    (This)->lpVtbl -> put_ActDestinationIONumber(This,newVal)

#define IActQCPUQUSB_get_ActMultiDropChannelNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActMultiDropChannelNumber(This,pVal)

#define IActQCPUQUSB_put_ActMultiDropChannelNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActMultiDropChannelNumber(This,newVal)

#define IActQCPUQUSB_get_ActThroughNetworkType(This,pVal)	\
    (This)->lpVtbl -> get_ActThroughNetworkType(This,pVal)

#define IActQCPUQUSB_put_ActThroughNetworkType(This,newVal)	\
    (This)->lpVtbl -> put_ActThroughNetworkType(This,newVal)

#define IActQCPUQUSB_get_ActIntelligentPreferenceBit(This,pVal)	\
    (This)->lpVtbl -> get_ActIntelligentPreferenceBit(This,pVal)

#define IActQCPUQUSB_put_ActIntelligentPreferenceBit(This,newVal)	\
    (This)->lpVtbl -> put_ActIntelligentPreferenceBit(This,newVal)

#define IActQCPUQUSB_get_ActDidPropertyBit(This,pVal)	\
    (This)->lpVtbl -> get_ActDidPropertyBit(This,pVal)

#define IActQCPUQUSB_put_ActDidPropertyBit(This,newVal)	\
    (This)->lpVtbl -> put_ActDidPropertyBit(This,newVal)

#define IActQCPUQUSB_get_ActDsidPropertyBit(This,pVal)	\
    (This)->lpVtbl -> get_ActDsidPropertyBit(This,pVal)

#define IActQCPUQUSB_put_ActDsidPropertyBit(This,newVal)	\
    (This)->lpVtbl -> put_ActDsidPropertyBit(This,newVal)

#define IActQCPUQUSB_GetDevice(This,szDevice,lpdwData,lplReturnCode)	\
    (This)->lpVtbl -> GetDevice(This,szDevice,lpdwData,lplReturnCode)

#define IActQCPUQUSB_CheckDeviceString(This,szDevice,lCheckType,lSize,lplDeviceType,lpszDeviceName,lplDeviceNumber,lplDeviceRadix,lplReturnCode)	\
    (This)->lpVtbl -> CheckDeviceString(This,szDevice,lCheckType,lSize,lplDeviceType,lpszDeviceName,lplDeviceNumber,lplDeviceRadix,lplReturnCode)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActQCPUQUSB_Open_Proxy( 
    IActQCPUQUSB __RPC_FAR * This,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActQCPUQUSB_Open_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActQCPUQUSB_Close_Proxy( 
    IActQCPUQUSB __RPC_FAR * This,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActQCPUQUSB_Close_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActQCPUQUSB_ReadDeviceBlock_Proxy( 
    IActQCPUQUSB __RPC_FAR * This,
    /* [string][in] */ BSTR szDevice,
    /* [in] */ LONG dwSize,
    /* [size_is][out] */ LONG __RPC_FAR *lpdwData,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActQCPUQUSB_ReadDeviceBlock_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActQCPUQUSB_WriteDeviceBlock_Proxy( 
    IActQCPUQUSB __RPC_FAR * This,
    /* [string][in] */ BSTR szDevice,
    /* [in] */ LONG dwSize,
    /* [size_is][in] */ LONG __RPC_FAR *lpdwData,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActQCPUQUSB_WriteDeviceBlock_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActQCPUQUSB_ReadDeviceRandom_Proxy( 
    IActQCPUQUSB __RPC_FAR * This,
    /* [string][in] */ BSTR szDeviceList,
    /* [in] */ LONG dwSize,
    /* [size_is][out] */ LONG __RPC_FAR *lpdwData,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActQCPUQUSB_ReadDeviceRandom_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActQCPUQUSB_WriteDeviceRandom_Proxy( 
    IActQCPUQUSB __RPC_FAR * This,
    /* [string][in] */ BSTR szDeviceList,
    /* [in] */ LONG dwSize,
    /* [size_is][in] */ LONG __RPC_FAR *lpdwData,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActQCPUQUSB_WriteDeviceRandom_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActQCPUQUSB_ReadBuffer_Proxy( 
    IActQCPUQUSB __RPC_FAR * This,
    /* [in] */ LONG lStartIO,
    /* [in] */ LONG lAddress,
    /* [in] */ LONG lReadSize,
    /* [size_is][out] */ SHORT __RPC_FAR *lpwData,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActQCPUQUSB_ReadBuffer_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActQCPUQUSB_WriteBuffer_Proxy( 
    IActQCPUQUSB __RPC_FAR * This,
    /* [in] */ LONG lStartIO,
    /* [in] */ LONG lAddress,
    /* [in] */ LONG lWriteSize,
    /* [size_is][in] */ SHORT __RPC_FAR *lpwData,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActQCPUQUSB_WriteBuffer_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActQCPUQUSB_GetClockData_Proxy( 
    IActQCPUQUSB __RPC_FAR * This,
    /* [out] */ SHORT __RPC_FAR *lpwYear,
    /* [out] */ SHORT __RPC_FAR *lpwMonth,
    /* [out] */ SHORT __RPC_FAR *lpwDay,
    /* [out] */ SHORT __RPC_FAR *lpwDayOfWeek,
    /* [out] */ SHORT __RPC_FAR *lpwHour,
    /* [out] */ SHORT __RPC_FAR *lpwMinute,
    /* [out] */ SHORT __RPC_FAR *lpwSecond,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActQCPUQUSB_GetClockData_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActQCPUQUSB_SetClockData_Proxy( 
    IActQCPUQUSB __RPC_FAR * This,
    /* [in] */ SHORT wYear,
    /* [in] */ SHORT wMonth,
    /* [in] */ SHORT wDay,
    /* [in] */ SHORT wDayOfWeek,
    /* [in] */ SHORT wHour,
    /* [in] */ SHORT wMinute,
    /* [in] */ SHORT wSecond,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActQCPUQUSB_SetClockData_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActQCPUQUSB_SetDevice_Proxy( 
    IActQCPUQUSB __RPC_FAR * This,
    /* [string][in] */ BSTR szDevice,
    /* [in] */ LONG dwData,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActQCPUQUSB_SetDevice_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActQCPUQUSB_SetCpuStatus_Proxy( 
    IActQCPUQUSB __RPC_FAR * This,
    /* [in] */ LONG lOperation,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActQCPUQUSB_SetCpuStatus_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActQCPUQUSB_GetCpuType_Proxy( 
    IActQCPUQUSB __RPC_FAR * This,
    /* [string][out] */ BSTR __RPC_FAR *lpszCpuName,
    /* [out] */ LONG __RPC_FAR *lplCpuType,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActQCPUQUSB_GetCpuType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActQCPUQUSB_get_ActNetworkNumber_Proxy( 
    IActQCPUQUSB __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IActQCPUQUSB_get_ActNetworkNumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActQCPUQUSB_put_ActNetworkNumber_Proxy( 
    IActQCPUQUSB __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB IActQCPUQUSB_put_ActNetworkNumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActQCPUQUSB_get_ActStationNumber_Proxy( 
    IActQCPUQUSB __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IActQCPUQUSB_get_ActStationNumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActQCPUQUSB_put_ActStationNumber_Proxy( 
    IActQCPUQUSB __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB IActQCPUQUSB_put_ActStationNumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActQCPUQUSB_get_ActUnitNumber_Proxy( 
    IActQCPUQUSB __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IActQCPUQUSB_get_ActUnitNumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActQCPUQUSB_put_ActUnitNumber_Proxy( 
    IActQCPUQUSB __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB IActQCPUQUSB_put_ActUnitNumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActQCPUQUSB_get_ActIONumber_Proxy( 
    IActQCPUQUSB __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IActQCPUQUSB_get_ActIONumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActQCPUQUSB_put_ActIONumber_Proxy( 
    IActQCPUQUSB __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB IActQCPUQUSB_put_ActIONumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActQCPUQUSB_get_ActCpuType_Proxy( 
    IActQCPUQUSB __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IActQCPUQUSB_get_ActCpuType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActQCPUQUSB_put_ActCpuType_Proxy( 
    IActQCPUQUSB __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB IActQCPUQUSB_put_ActCpuType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActQCPUQUSB_get_ActTimeOut_Proxy( 
    IActQCPUQUSB __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IActQCPUQUSB_get_ActTimeOut_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActQCPUQUSB_put_ActTimeOut_Proxy( 
    IActQCPUQUSB __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB IActQCPUQUSB_put_ActTimeOut_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActQCPUQUSB_get_ActDestinationIONumber_Proxy( 
    IActQCPUQUSB __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IActQCPUQUSB_get_ActDestinationIONumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActQCPUQUSB_put_ActDestinationIONumber_Proxy( 
    IActQCPUQUSB __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB IActQCPUQUSB_put_ActDestinationIONumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActQCPUQUSB_get_ActMultiDropChannelNumber_Proxy( 
    IActQCPUQUSB __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IActQCPUQUSB_get_ActMultiDropChannelNumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActQCPUQUSB_put_ActMultiDropChannelNumber_Proxy( 
    IActQCPUQUSB __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB IActQCPUQUSB_put_ActMultiDropChannelNumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActQCPUQUSB_get_ActThroughNetworkType_Proxy( 
    IActQCPUQUSB __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IActQCPUQUSB_get_ActThroughNetworkType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActQCPUQUSB_put_ActThroughNetworkType_Proxy( 
    IActQCPUQUSB __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB IActQCPUQUSB_put_ActThroughNetworkType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActQCPUQUSB_get_ActIntelligentPreferenceBit_Proxy( 
    IActQCPUQUSB __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IActQCPUQUSB_get_ActIntelligentPreferenceBit_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActQCPUQUSB_put_ActIntelligentPreferenceBit_Proxy( 
    IActQCPUQUSB __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB IActQCPUQUSB_put_ActIntelligentPreferenceBit_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActQCPUQUSB_get_ActDidPropertyBit_Proxy( 
    IActQCPUQUSB __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IActQCPUQUSB_get_ActDidPropertyBit_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActQCPUQUSB_put_ActDidPropertyBit_Proxy( 
    IActQCPUQUSB __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB IActQCPUQUSB_put_ActDidPropertyBit_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActQCPUQUSB_get_ActDsidPropertyBit_Proxy( 
    IActQCPUQUSB __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IActQCPUQUSB_get_ActDsidPropertyBit_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActQCPUQUSB_put_ActDsidPropertyBit_Proxy( 
    IActQCPUQUSB __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB IActQCPUQUSB_put_ActDsidPropertyBit_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActQCPUQUSB_GetDevice_Proxy( 
    IActQCPUQUSB __RPC_FAR * This,
    /* [string][in] */ BSTR szDevice,
    /* [out] */ LONG __RPC_FAR *lpdwData,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActQCPUQUSB_GetDevice_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActQCPUQUSB_CheckDeviceString_Proxy( 
    IActQCPUQUSB __RPC_FAR * This,
    /* [in] */ BSTR szDevice,
    /* [in] */ LONG lCheckType,
    /* [in] */ LONG lSize,
    /* [out] */ LONG __RPC_FAR *lplDeviceType,
    /* [string][out] */ BSTR __RPC_FAR *lpszDeviceName,
    /* [out] */ LONG __RPC_FAR *lplDeviceNumber,
    /* [out] */ LONG __RPC_FAR *lplDeviceRadix,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActQCPUQUSB_CheckDeviceString_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IActQCPUQUSB_INTERFACE_DEFINED__ */


#ifndef __IActQCPUQUSB2_INTERFACE_DEFINED__
#define __IActQCPUQUSB2_INTERFACE_DEFINED__

/* interface IActQCPUQUSB2 */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IActQCPUQUSB2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("A850BB90-C820-11d4-8744-00E0292A4FB4")
    IActQCPUQUSB2 : public IActQCPUQUSB
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE EntryDeviceStatus( 
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG lSize,
            /* [in] */ LONG lMonitorCycle,
            /* [size_is][in] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE FreeDeviceStatus( 
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IActQCPUQUSB2Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IActQCPUQUSB2 __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IActQCPUQUSB2 __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IActQCPUQUSB2 __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IActQCPUQUSB2 __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IActQCPUQUSB2 __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IActQCPUQUSB2 __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IActQCPUQUSB2 __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Open )( 
            IActQCPUQUSB2 __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Close )( 
            IActQCPUQUSB2 __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceBlock )( 
            IActQCPUQUSB2 __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG dwSize,
            /* [size_is][out] */ LONG __RPC_FAR *lpdwData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceBlock )( 
            IActQCPUQUSB2 __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG dwSize,
            /* [size_is][in] */ LONG __RPC_FAR *lpdwData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceRandom )( 
            IActQCPUQUSB2 __RPC_FAR * This,
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG dwSize,
            /* [size_is][out] */ LONG __RPC_FAR *lpdwData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceRandom )( 
            IActQCPUQUSB2 __RPC_FAR * This,
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG dwSize,
            /* [size_is][in] */ LONG __RPC_FAR *lpdwData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadBuffer )( 
            IActQCPUQUSB2 __RPC_FAR * This,
            /* [in] */ LONG lStartIO,
            /* [in] */ LONG lAddress,
            /* [in] */ LONG lReadSize,
            /* [size_is][out] */ SHORT __RPC_FAR *lpwData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteBuffer )( 
            IActQCPUQUSB2 __RPC_FAR * This,
            /* [in] */ LONG lStartIO,
            /* [in] */ LONG lAddress,
            /* [in] */ LONG lWriteSize,
            /* [size_is][in] */ SHORT __RPC_FAR *lpwData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetClockData )( 
            IActQCPUQUSB2 __RPC_FAR * This,
            /* [out] */ SHORT __RPC_FAR *lpwYear,
            /* [out] */ SHORT __RPC_FAR *lpwMonth,
            /* [out] */ SHORT __RPC_FAR *lpwDay,
            /* [out] */ SHORT __RPC_FAR *lpwDayOfWeek,
            /* [out] */ SHORT __RPC_FAR *lpwHour,
            /* [out] */ SHORT __RPC_FAR *lpwMinute,
            /* [out] */ SHORT __RPC_FAR *lpwSecond,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetClockData )( 
            IActQCPUQUSB2 __RPC_FAR * This,
            /* [in] */ SHORT wYear,
            /* [in] */ SHORT wMonth,
            /* [in] */ SHORT wDay,
            /* [in] */ SHORT wDayOfWeek,
            /* [in] */ SHORT wHour,
            /* [in] */ SHORT wMinute,
            /* [in] */ SHORT wSecond,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetDevice )( 
            IActQCPUQUSB2 __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG dwData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetCpuStatus )( 
            IActQCPUQUSB2 __RPC_FAR * This,
            /* [in] */ LONG lOperation,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetCpuType )( 
            IActQCPUQUSB2 __RPC_FAR * This,
            /* [string][out] */ BSTR __RPC_FAR *lpszCpuName,
            /* [out] */ LONG __RPC_FAR *lplCpuType,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActNetworkNumber )( 
            IActQCPUQUSB2 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActNetworkNumber )( 
            IActQCPUQUSB2 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActStationNumber )( 
            IActQCPUQUSB2 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActStationNumber )( 
            IActQCPUQUSB2 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActUnitNumber )( 
            IActQCPUQUSB2 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActUnitNumber )( 
            IActQCPUQUSB2 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActIONumber )( 
            IActQCPUQUSB2 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActIONumber )( 
            IActQCPUQUSB2 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActCpuType )( 
            IActQCPUQUSB2 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActCpuType )( 
            IActQCPUQUSB2 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActTimeOut )( 
            IActQCPUQUSB2 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActTimeOut )( 
            IActQCPUQUSB2 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActDestinationIONumber )( 
            IActQCPUQUSB2 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActDestinationIONumber )( 
            IActQCPUQUSB2 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActMultiDropChannelNumber )( 
            IActQCPUQUSB2 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActMultiDropChannelNumber )( 
            IActQCPUQUSB2 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActThroughNetworkType )( 
            IActQCPUQUSB2 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActThroughNetworkType )( 
            IActQCPUQUSB2 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActIntelligentPreferenceBit )( 
            IActQCPUQUSB2 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActIntelligentPreferenceBit )( 
            IActQCPUQUSB2 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActDidPropertyBit )( 
            IActQCPUQUSB2 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActDidPropertyBit )( 
            IActQCPUQUSB2 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActDsidPropertyBit )( 
            IActQCPUQUSB2 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActDsidPropertyBit )( 
            IActQCPUQUSB2 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetDevice )( 
            IActQCPUQUSB2 __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [out] */ LONG __RPC_FAR *lpdwData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CheckDeviceString )( 
            IActQCPUQUSB2 __RPC_FAR * This,
            /* [in] */ BSTR szDevice,
            /* [in] */ LONG lCheckType,
            /* [in] */ LONG lSize,
            /* [out] */ LONG __RPC_FAR *lplDeviceType,
            /* [string][out] */ BSTR __RPC_FAR *lpszDeviceName,
            /* [out] */ LONG __RPC_FAR *lplDeviceNumber,
            /* [out] */ LONG __RPC_FAR *lplDeviceRadix,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *EntryDeviceStatus )( 
            IActQCPUQUSB2 __RPC_FAR * This,
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG lSize,
            /* [in] */ LONG lMonitorCycle,
            /* [size_is][in] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *FreeDeviceStatus )( 
            IActQCPUQUSB2 __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        END_INTERFACE
    } IActQCPUQUSB2Vtbl;

    interface IActQCPUQUSB2
    {
        CONST_VTBL struct IActQCPUQUSB2Vtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IActQCPUQUSB2_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IActQCPUQUSB2_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IActQCPUQUSB2_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IActQCPUQUSB2_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IActQCPUQUSB2_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IActQCPUQUSB2_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IActQCPUQUSB2_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IActQCPUQUSB2_Open(This,lplReturnCode)	\
    (This)->lpVtbl -> Open(This,lplReturnCode)

#define IActQCPUQUSB2_Close(This,lplReturnCode)	\
    (This)->lpVtbl -> Close(This,lplReturnCode)

#define IActQCPUQUSB2_ReadDeviceBlock(This,szDevice,dwSize,lpdwData,lplReturnCode)	\
    (This)->lpVtbl -> ReadDeviceBlock(This,szDevice,dwSize,lpdwData,lplReturnCode)

#define IActQCPUQUSB2_WriteDeviceBlock(This,szDevice,dwSize,lpdwData,lplReturnCode)	\
    (This)->lpVtbl -> WriteDeviceBlock(This,szDevice,dwSize,lpdwData,lplReturnCode)

#define IActQCPUQUSB2_ReadDeviceRandom(This,szDeviceList,dwSize,lpdwData,lplReturnCode)	\
    (This)->lpVtbl -> ReadDeviceRandom(This,szDeviceList,dwSize,lpdwData,lplReturnCode)

#define IActQCPUQUSB2_WriteDeviceRandom(This,szDeviceList,dwSize,lpdwData,lplReturnCode)	\
    (This)->lpVtbl -> WriteDeviceRandom(This,szDeviceList,dwSize,lpdwData,lplReturnCode)

#define IActQCPUQUSB2_ReadBuffer(This,lStartIO,lAddress,lReadSize,lpwData,lplReturnCode)	\
    (This)->lpVtbl -> ReadBuffer(This,lStartIO,lAddress,lReadSize,lpwData,lplReturnCode)

#define IActQCPUQUSB2_WriteBuffer(This,lStartIO,lAddress,lWriteSize,lpwData,lplReturnCode)	\
    (This)->lpVtbl -> WriteBuffer(This,lStartIO,lAddress,lWriteSize,lpwData,lplReturnCode)

#define IActQCPUQUSB2_GetClockData(This,lpwYear,lpwMonth,lpwDay,lpwDayOfWeek,lpwHour,lpwMinute,lpwSecond,lplReturnCode)	\
    (This)->lpVtbl -> GetClockData(This,lpwYear,lpwMonth,lpwDay,lpwDayOfWeek,lpwHour,lpwMinute,lpwSecond,lplReturnCode)

#define IActQCPUQUSB2_SetClockData(This,wYear,wMonth,wDay,wDayOfWeek,wHour,wMinute,wSecond,lplReturnCode)	\
    (This)->lpVtbl -> SetClockData(This,wYear,wMonth,wDay,wDayOfWeek,wHour,wMinute,wSecond,lplReturnCode)

#define IActQCPUQUSB2_SetDevice(This,szDevice,dwData,lplReturnCode)	\
    (This)->lpVtbl -> SetDevice(This,szDevice,dwData,lplReturnCode)

#define IActQCPUQUSB2_SetCpuStatus(This,lOperation,lplReturnCode)	\
    (This)->lpVtbl -> SetCpuStatus(This,lOperation,lplReturnCode)

#define IActQCPUQUSB2_GetCpuType(This,lpszCpuName,lplCpuType,lplReturnCode)	\
    (This)->lpVtbl -> GetCpuType(This,lpszCpuName,lplCpuType,lplReturnCode)

#define IActQCPUQUSB2_get_ActNetworkNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActNetworkNumber(This,pVal)

#define IActQCPUQUSB2_put_ActNetworkNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActNetworkNumber(This,newVal)

#define IActQCPUQUSB2_get_ActStationNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActStationNumber(This,pVal)

#define IActQCPUQUSB2_put_ActStationNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActStationNumber(This,newVal)

#define IActQCPUQUSB2_get_ActUnitNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActUnitNumber(This,pVal)

#define IActQCPUQUSB2_put_ActUnitNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActUnitNumber(This,newVal)

#define IActQCPUQUSB2_get_ActIONumber(This,pVal)	\
    (This)->lpVtbl -> get_ActIONumber(This,pVal)

#define IActQCPUQUSB2_put_ActIONumber(This,newVal)	\
    (This)->lpVtbl -> put_ActIONumber(This,newVal)

#define IActQCPUQUSB2_get_ActCpuType(This,pVal)	\
    (This)->lpVtbl -> get_ActCpuType(This,pVal)

#define IActQCPUQUSB2_put_ActCpuType(This,newVal)	\
    (This)->lpVtbl -> put_ActCpuType(This,newVal)

#define IActQCPUQUSB2_get_ActTimeOut(This,pVal)	\
    (This)->lpVtbl -> get_ActTimeOut(This,pVal)

#define IActQCPUQUSB2_put_ActTimeOut(This,newVal)	\
    (This)->lpVtbl -> put_ActTimeOut(This,newVal)

#define IActQCPUQUSB2_get_ActDestinationIONumber(This,pVal)	\
    (This)->lpVtbl -> get_ActDestinationIONumber(This,pVal)

#define IActQCPUQUSB2_put_ActDestinationIONumber(This,newVal)	\
    (This)->lpVtbl -> put_ActDestinationIONumber(This,newVal)

#define IActQCPUQUSB2_get_ActMultiDropChannelNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActMultiDropChannelNumber(This,pVal)

#define IActQCPUQUSB2_put_ActMultiDropChannelNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActMultiDropChannelNumber(This,newVal)

#define IActQCPUQUSB2_get_ActThroughNetworkType(This,pVal)	\
    (This)->lpVtbl -> get_ActThroughNetworkType(This,pVal)

#define IActQCPUQUSB2_put_ActThroughNetworkType(This,newVal)	\
    (This)->lpVtbl -> put_ActThroughNetworkType(This,newVal)

#define IActQCPUQUSB2_get_ActIntelligentPreferenceBit(This,pVal)	\
    (This)->lpVtbl -> get_ActIntelligentPreferenceBit(This,pVal)

#define IActQCPUQUSB2_put_ActIntelligentPreferenceBit(This,newVal)	\
    (This)->lpVtbl -> put_ActIntelligentPreferenceBit(This,newVal)

#define IActQCPUQUSB2_get_ActDidPropertyBit(This,pVal)	\
    (This)->lpVtbl -> get_ActDidPropertyBit(This,pVal)

#define IActQCPUQUSB2_put_ActDidPropertyBit(This,newVal)	\
    (This)->lpVtbl -> put_ActDidPropertyBit(This,newVal)

#define IActQCPUQUSB2_get_ActDsidPropertyBit(This,pVal)	\
    (This)->lpVtbl -> get_ActDsidPropertyBit(This,pVal)

#define IActQCPUQUSB2_put_ActDsidPropertyBit(This,newVal)	\
    (This)->lpVtbl -> put_ActDsidPropertyBit(This,newVal)

#define IActQCPUQUSB2_GetDevice(This,szDevice,lpdwData,lplReturnCode)	\
    (This)->lpVtbl -> GetDevice(This,szDevice,lpdwData,lplReturnCode)

#define IActQCPUQUSB2_CheckDeviceString(This,szDevice,lCheckType,lSize,lplDeviceType,lpszDeviceName,lplDeviceNumber,lplDeviceRadix,lplReturnCode)	\
    (This)->lpVtbl -> CheckDeviceString(This,szDevice,lCheckType,lSize,lplDeviceType,lpszDeviceName,lplDeviceNumber,lplDeviceRadix,lplReturnCode)


#define IActQCPUQUSB2_EntryDeviceStatus(This,szDeviceList,lSize,lMonitorCycle,lplData,lplReturnCode)	\
    (This)->lpVtbl -> EntryDeviceStatus(This,szDeviceList,lSize,lMonitorCycle,lplData,lplReturnCode)

#define IActQCPUQUSB2_FreeDeviceStatus(This,lplReturnCode)	\
    (This)->lpVtbl -> FreeDeviceStatus(This,lplReturnCode)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActQCPUQUSB2_EntryDeviceStatus_Proxy( 
    IActQCPUQUSB2 __RPC_FAR * This,
    /* [string][in] */ BSTR szDeviceList,
    /* [in] */ LONG lSize,
    /* [in] */ LONG lMonitorCycle,
    /* [size_is][in] */ LONG __RPC_FAR *lplData,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActQCPUQUSB2_EntryDeviceStatus_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActQCPUQUSB2_FreeDeviceStatus_Proxy( 
    IActQCPUQUSB2 __RPC_FAR * This,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActQCPUQUSB2_FreeDeviceStatus_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IActQCPUQUSB2_INTERFACE_DEFINED__ */


#ifndef __IActQCPUQUSB3_INTERFACE_DEFINED__
#define __IActQCPUQUSB3_INTERFACE_DEFINED__

/* interface IActQCPUQUSB3 */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IActQCPUQUSB3;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("115992F1-6EC2-11d5-9314-009099244EFD")
    IActQCPUQUSB3 : public IActQCPUQUSB2
    {
    public:
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
        
    };
    
#else 	/* C style interface */

    typedef struct IActQCPUQUSB3Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IActQCPUQUSB3 __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IActQCPUQUSB3 __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IActQCPUQUSB3 __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IActQCPUQUSB3 __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IActQCPUQUSB3 __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IActQCPUQUSB3 __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IActQCPUQUSB3 __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Open )( 
            IActQCPUQUSB3 __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Close )( 
            IActQCPUQUSB3 __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceBlock )( 
            IActQCPUQUSB3 __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG dwSize,
            /* [size_is][out] */ LONG __RPC_FAR *lpdwData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceBlock )( 
            IActQCPUQUSB3 __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG dwSize,
            /* [size_is][in] */ LONG __RPC_FAR *lpdwData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceRandom )( 
            IActQCPUQUSB3 __RPC_FAR * This,
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG dwSize,
            /* [size_is][out] */ LONG __RPC_FAR *lpdwData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceRandom )( 
            IActQCPUQUSB3 __RPC_FAR * This,
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG dwSize,
            /* [size_is][in] */ LONG __RPC_FAR *lpdwData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadBuffer )( 
            IActQCPUQUSB3 __RPC_FAR * This,
            /* [in] */ LONG lStartIO,
            /* [in] */ LONG lAddress,
            /* [in] */ LONG lReadSize,
            /* [size_is][out] */ SHORT __RPC_FAR *lpwData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteBuffer )( 
            IActQCPUQUSB3 __RPC_FAR * This,
            /* [in] */ LONG lStartIO,
            /* [in] */ LONG lAddress,
            /* [in] */ LONG lWriteSize,
            /* [size_is][in] */ SHORT __RPC_FAR *lpwData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetClockData )( 
            IActQCPUQUSB3 __RPC_FAR * This,
            /* [out] */ SHORT __RPC_FAR *lpwYear,
            /* [out] */ SHORT __RPC_FAR *lpwMonth,
            /* [out] */ SHORT __RPC_FAR *lpwDay,
            /* [out] */ SHORT __RPC_FAR *lpwDayOfWeek,
            /* [out] */ SHORT __RPC_FAR *lpwHour,
            /* [out] */ SHORT __RPC_FAR *lpwMinute,
            /* [out] */ SHORT __RPC_FAR *lpwSecond,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetClockData )( 
            IActQCPUQUSB3 __RPC_FAR * This,
            /* [in] */ SHORT wYear,
            /* [in] */ SHORT wMonth,
            /* [in] */ SHORT wDay,
            /* [in] */ SHORT wDayOfWeek,
            /* [in] */ SHORT wHour,
            /* [in] */ SHORT wMinute,
            /* [in] */ SHORT wSecond,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetDevice )( 
            IActQCPUQUSB3 __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG dwData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetCpuStatus )( 
            IActQCPUQUSB3 __RPC_FAR * This,
            /* [in] */ LONG lOperation,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetCpuType )( 
            IActQCPUQUSB3 __RPC_FAR * This,
            /* [string][out] */ BSTR __RPC_FAR *lpszCpuName,
            /* [out] */ LONG __RPC_FAR *lplCpuType,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActNetworkNumber )( 
            IActQCPUQUSB3 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActNetworkNumber )( 
            IActQCPUQUSB3 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActStationNumber )( 
            IActQCPUQUSB3 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActStationNumber )( 
            IActQCPUQUSB3 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActUnitNumber )( 
            IActQCPUQUSB3 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActUnitNumber )( 
            IActQCPUQUSB3 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActIONumber )( 
            IActQCPUQUSB3 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActIONumber )( 
            IActQCPUQUSB3 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActCpuType )( 
            IActQCPUQUSB3 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActCpuType )( 
            IActQCPUQUSB3 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActTimeOut )( 
            IActQCPUQUSB3 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActTimeOut )( 
            IActQCPUQUSB3 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActDestinationIONumber )( 
            IActQCPUQUSB3 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActDestinationIONumber )( 
            IActQCPUQUSB3 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActMultiDropChannelNumber )( 
            IActQCPUQUSB3 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActMultiDropChannelNumber )( 
            IActQCPUQUSB3 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActThroughNetworkType )( 
            IActQCPUQUSB3 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActThroughNetworkType )( 
            IActQCPUQUSB3 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActIntelligentPreferenceBit )( 
            IActQCPUQUSB3 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActIntelligentPreferenceBit )( 
            IActQCPUQUSB3 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActDidPropertyBit )( 
            IActQCPUQUSB3 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActDidPropertyBit )( 
            IActQCPUQUSB3 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActDsidPropertyBit )( 
            IActQCPUQUSB3 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActDsidPropertyBit )( 
            IActQCPUQUSB3 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetDevice )( 
            IActQCPUQUSB3 __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [out] */ LONG __RPC_FAR *lpdwData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CheckDeviceString )( 
            IActQCPUQUSB3 __RPC_FAR * This,
            /* [in] */ BSTR szDevice,
            /* [in] */ LONG lCheckType,
            /* [in] */ LONG lSize,
            /* [out] */ LONG __RPC_FAR *lplDeviceType,
            /* [string][out] */ BSTR __RPC_FAR *lpszDeviceName,
            /* [out] */ LONG __RPC_FAR *lplDeviceNumber,
            /* [out] */ LONG __RPC_FAR *lplDeviceRadix,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *EntryDeviceStatus )( 
            IActQCPUQUSB3 __RPC_FAR * This,
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG lSize,
            /* [in] */ LONG lMonitorCycle,
            /* [size_is][in] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *FreeDeviceStatus )( 
            IActQCPUQUSB3 __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceBlock2 )( 
            IActQCPUQUSB3 __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lSize,
            /* [size_is][out] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceBlock2 )( 
            IActQCPUQUSB3 __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lSize,
            /* [size_is][in] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceRandom2 )( 
            IActQCPUQUSB3 __RPC_FAR * This,
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG lSize,
            /* [size_is][out] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceRandom2 )( 
            IActQCPUQUSB3 __RPC_FAR * This,
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG lSize,
            /* [size_is][in] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetDevice2 )( 
            IActQCPUQUSB3 __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [out] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetDevice2 )( 
            IActQCPUQUSB3 __RPC_FAR * This,
            /* [in] */ BSTR szDevice,
            /* [in] */ SHORT sData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        END_INTERFACE
    } IActQCPUQUSB3Vtbl;

    interface IActQCPUQUSB3
    {
        CONST_VTBL struct IActQCPUQUSB3Vtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IActQCPUQUSB3_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IActQCPUQUSB3_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IActQCPUQUSB3_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IActQCPUQUSB3_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IActQCPUQUSB3_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IActQCPUQUSB3_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IActQCPUQUSB3_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IActQCPUQUSB3_Open(This,lplReturnCode)	\
    (This)->lpVtbl -> Open(This,lplReturnCode)

#define IActQCPUQUSB3_Close(This,lplReturnCode)	\
    (This)->lpVtbl -> Close(This,lplReturnCode)

#define IActQCPUQUSB3_ReadDeviceBlock(This,szDevice,dwSize,lpdwData,lplReturnCode)	\
    (This)->lpVtbl -> ReadDeviceBlock(This,szDevice,dwSize,lpdwData,lplReturnCode)

#define IActQCPUQUSB3_WriteDeviceBlock(This,szDevice,dwSize,lpdwData,lplReturnCode)	\
    (This)->lpVtbl -> WriteDeviceBlock(This,szDevice,dwSize,lpdwData,lplReturnCode)

#define IActQCPUQUSB3_ReadDeviceRandom(This,szDeviceList,dwSize,lpdwData,lplReturnCode)	\
    (This)->lpVtbl -> ReadDeviceRandom(This,szDeviceList,dwSize,lpdwData,lplReturnCode)

#define IActQCPUQUSB3_WriteDeviceRandom(This,szDeviceList,dwSize,lpdwData,lplReturnCode)	\
    (This)->lpVtbl -> WriteDeviceRandom(This,szDeviceList,dwSize,lpdwData,lplReturnCode)

#define IActQCPUQUSB3_ReadBuffer(This,lStartIO,lAddress,lReadSize,lpwData,lplReturnCode)	\
    (This)->lpVtbl -> ReadBuffer(This,lStartIO,lAddress,lReadSize,lpwData,lplReturnCode)

#define IActQCPUQUSB3_WriteBuffer(This,lStartIO,lAddress,lWriteSize,lpwData,lplReturnCode)	\
    (This)->lpVtbl -> WriteBuffer(This,lStartIO,lAddress,lWriteSize,lpwData,lplReturnCode)

#define IActQCPUQUSB3_GetClockData(This,lpwYear,lpwMonth,lpwDay,lpwDayOfWeek,lpwHour,lpwMinute,lpwSecond,lplReturnCode)	\
    (This)->lpVtbl -> GetClockData(This,lpwYear,lpwMonth,lpwDay,lpwDayOfWeek,lpwHour,lpwMinute,lpwSecond,lplReturnCode)

#define IActQCPUQUSB3_SetClockData(This,wYear,wMonth,wDay,wDayOfWeek,wHour,wMinute,wSecond,lplReturnCode)	\
    (This)->lpVtbl -> SetClockData(This,wYear,wMonth,wDay,wDayOfWeek,wHour,wMinute,wSecond,lplReturnCode)

#define IActQCPUQUSB3_SetDevice(This,szDevice,dwData,lplReturnCode)	\
    (This)->lpVtbl -> SetDevice(This,szDevice,dwData,lplReturnCode)

#define IActQCPUQUSB3_SetCpuStatus(This,lOperation,lplReturnCode)	\
    (This)->lpVtbl -> SetCpuStatus(This,lOperation,lplReturnCode)

#define IActQCPUQUSB3_GetCpuType(This,lpszCpuName,lplCpuType,lplReturnCode)	\
    (This)->lpVtbl -> GetCpuType(This,lpszCpuName,lplCpuType,lplReturnCode)

#define IActQCPUQUSB3_get_ActNetworkNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActNetworkNumber(This,pVal)

#define IActQCPUQUSB3_put_ActNetworkNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActNetworkNumber(This,newVal)

#define IActQCPUQUSB3_get_ActStationNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActStationNumber(This,pVal)

#define IActQCPUQUSB3_put_ActStationNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActStationNumber(This,newVal)

#define IActQCPUQUSB3_get_ActUnitNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActUnitNumber(This,pVal)

#define IActQCPUQUSB3_put_ActUnitNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActUnitNumber(This,newVal)

#define IActQCPUQUSB3_get_ActIONumber(This,pVal)	\
    (This)->lpVtbl -> get_ActIONumber(This,pVal)

#define IActQCPUQUSB3_put_ActIONumber(This,newVal)	\
    (This)->lpVtbl -> put_ActIONumber(This,newVal)

#define IActQCPUQUSB3_get_ActCpuType(This,pVal)	\
    (This)->lpVtbl -> get_ActCpuType(This,pVal)

#define IActQCPUQUSB3_put_ActCpuType(This,newVal)	\
    (This)->lpVtbl -> put_ActCpuType(This,newVal)

#define IActQCPUQUSB3_get_ActTimeOut(This,pVal)	\
    (This)->lpVtbl -> get_ActTimeOut(This,pVal)

#define IActQCPUQUSB3_put_ActTimeOut(This,newVal)	\
    (This)->lpVtbl -> put_ActTimeOut(This,newVal)

#define IActQCPUQUSB3_get_ActDestinationIONumber(This,pVal)	\
    (This)->lpVtbl -> get_ActDestinationIONumber(This,pVal)

#define IActQCPUQUSB3_put_ActDestinationIONumber(This,newVal)	\
    (This)->lpVtbl -> put_ActDestinationIONumber(This,newVal)

#define IActQCPUQUSB3_get_ActMultiDropChannelNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActMultiDropChannelNumber(This,pVal)

#define IActQCPUQUSB3_put_ActMultiDropChannelNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActMultiDropChannelNumber(This,newVal)

#define IActQCPUQUSB3_get_ActThroughNetworkType(This,pVal)	\
    (This)->lpVtbl -> get_ActThroughNetworkType(This,pVal)

#define IActQCPUQUSB3_put_ActThroughNetworkType(This,newVal)	\
    (This)->lpVtbl -> put_ActThroughNetworkType(This,newVal)

#define IActQCPUQUSB3_get_ActIntelligentPreferenceBit(This,pVal)	\
    (This)->lpVtbl -> get_ActIntelligentPreferenceBit(This,pVal)

#define IActQCPUQUSB3_put_ActIntelligentPreferenceBit(This,newVal)	\
    (This)->lpVtbl -> put_ActIntelligentPreferenceBit(This,newVal)

#define IActQCPUQUSB3_get_ActDidPropertyBit(This,pVal)	\
    (This)->lpVtbl -> get_ActDidPropertyBit(This,pVal)

#define IActQCPUQUSB3_put_ActDidPropertyBit(This,newVal)	\
    (This)->lpVtbl -> put_ActDidPropertyBit(This,newVal)

#define IActQCPUQUSB3_get_ActDsidPropertyBit(This,pVal)	\
    (This)->lpVtbl -> get_ActDsidPropertyBit(This,pVal)

#define IActQCPUQUSB3_put_ActDsidPropertyBit(This,newVal)	\
    (This)->lpVtbl -> put_ActDsidPropertyBit(This,newVal)

#define IActQCPUQUSB3_GetDevice(This,szDevice,lpdwData,lplReturnCode)	\
    (This)->lpVtbl -> GetDevice(This,szDevice,lpdwData,lplReturnCode)

#define IActQCPUQUSB3_CheckDeviceString(This,szDevice,lCheckType,lSize,lplDeviceType,lpszDeviceName,lplDeviceNumber,lplDeviceRadix,lplReturnCode)	\
    (This)->lpVtbl -> CheckDeviceString(This,szDevice,lCheckType,lSize,lplDeviceType,lpszDeviceName,lplDeviceNumber,lplDeviceRadix,lplReturnCode)


#define IActQCPUQUSB3_EntryDeviceStatus(This,szDeviceList,lSize,lMonitorCycle,lplData,lplReturnCode)	\
    (This)->lpVtbl -> EntryDeviceStatus(This,szDeviceList,lSize,lMonitorCycle,lplData,lplReturnCode)

#define IActQCPUQUSB3_FreeDeviceStatus(This,lplReturnCode)	\
    (This)->lpVtbl -> FreeDeviceStatus(This,lplReturnCode)


#define IActQCPUQUSB3_ReadDeviceBlock2(This,szDevice,lSize,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> ReadDeviceBlock2(This,szDevice,lSize,lpsData,lplReturnCode)

#define IActQCPUQUSB3_WriteDeviceBlock2(This,szDevice,lSize,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> WriteDeviceBlock2(This,szDevice,lSize,lpsData,lplReturnCode)

#define IActQCPUQUSB3_ReadDeviceRandom2(This,szDeviceList,lSize,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> ReadDeviceRandom2(This,szDeviceList,lSize,lpsData,lplReturnCode)

#define IActQCPUQUSB3_WriteDeviceRandom2(This,szDeviceList,lSize,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> WriteDeviceRandom2(This,szDeviceList,lSize,lpsData,lplReturnCode)

#define IActQCPUQUSB3_GetDevice2(This,szDevice,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> GetDevice2(This,szDevice,lpsData,lplReturnCode)

#define IActQCPUQUSB3_SetDevice2(This,szDevice,sData,lplReturnCode)	\
    (This)->lpVtbl -> SetDevice2(This,szDevice,sData,lplReturnCode)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActQCPUQUSB3_ReadDeviceBlock2_Proxy( 
    IActQCPUQUSB3 __RPC_FAR * This,
    /* [string][in] */ BSTR szDevice,
    /* [in] */ LONG lSize,
    /* [size_is][out] */ SHORT __RPC_FAR *lpsData,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActQCPUQUSB3_ReadDeviceBlock2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActQCPUQUSB3_WriteDeviceBlock2_Proxy( 
    IActQCPUQUSB3 __RPC_FAR * This,
    /* [string][in] */ BSTR szDevice,
    /* [in] */ LONG lSize,
    /* [size_is][in] */ SHORT __RPC_FAR *lpsData,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActQCPUQUSB3_WriteDeviceBlock2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActQCPUQUSB3_ReadDeviceRandom2_Proxy( 
    IActQCPUQUSB3 __RPC_FAR * This,
    /* [string][in] */ BSTR szDeviceList,
    /* [in] */ LONG lSize,
    /* [size_is][out] */ SHORT __RPC_FAR *lpsData,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActQCPUQUSB3_ReadDeviceRandom2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActQCPUQUSB3_WriteDeviceRandom2_Proxy( 
    IActQCPUQUSB3 __RPC_FAR * This,
    /* [string][in] */ BSTR szDeviceList,
    /* [in] */ LONG lSize,
    /* [size_is][in] */ SHORT __RPC_FAR *lpsData,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActQCPUQUSB3_WriteDeviceRandom2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActQCPUQUSB3_GetDevice2_Proxy( 
    IActQCPUQUSB3 __RPC_FAR * This,
    /* [string][in] */ BSTR szDevice,
    /* [out] */ SHORT __RPC_FAR *lpsData,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActQCPUQUSB3_GetDevice2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActQCPUQUSB3_SetDevice2_Proxy( 
    IActQCPUQUSB3 __RPC_FAR * This,
    /* [in] */ BSTR szDevice,
    /* [in] */ SHORT sData,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActQCPUQUSB3_SetDevice2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IActQCPUQUSB3_INTERFACE_DEFINED__ */


#ifndef __IActMLQCPUQUSB_INTERFACE_DEFINED__
#define __IActMLQCPUQUSB_INTERFACE_DEFINED__

/* interface IActMLQCPUQUSB */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IActMLQCPUQUSB;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("95969871-A954-11D4-910D-009099244EFD")
    IActMLQCPUQUSB : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Open( 
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Close( 
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetDevice( 
            /* [in] */ VARIANT varDevice,
            /* [out] */ VARIANT __RPC_FAR *lpvarData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetDevice( 
            /* [in] */ VARIANT varDevice,
            /* [in] */ VARIANT varData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ReadDeviceBlock( 
            /* [in] */ VARIANT varDevice,
            /* [in] */ VARIANT varSize,
            /* [out] */ VARIANT __RPC_FAR *lpvarData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE WriteDeviceBlock( 
            /* [in] */ VARIANT varDevice,
            /* [in] */ VARIANT varSize,
            /* [in] */ VARIANT varData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ReadDeviceRandom( 
            /* [in] */ VARIANT varDeviceList,
            /* [in] */ VARIANT varSize,
            /* [out] */ VARIANT __RPC_FAR *lpvarData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE WriteDeviceRandom( 
            /* [in] */ VARIANT varDeviceList,
            /* [in] */ VARIANT varSize,
            /* [in] */ VARIANT varData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ReadBuffer( 
            /* [in] */ VARIANT varStartIO,
            /* [in] */ VARIANT varAddress,
            /* [in] */ VARIANT varReadSize,
            /* [out] */ VARIANT __RPC_FAR *lpvarData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE WriteBuffer( 
            /* [in] */ VARIANT varStartIO,
            /* [in] */ VARIANT varAddress,
            /* [in] */ VARIANT varWriteSize,
            /* [in] */ VARIANT varData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetCpuType( 
            /* [out] */ VARIANT __RPC_FAR *lpvarCpuName,
            /* [out] */ VARIANT __RPC_FAR *lpvarCpuType,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetCpuStatus( 
            /* [in] */ VARIANT varOperation,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetClockData( 
            /* [out] */ VARIANT __RPC_FAR *lpvarYear,
            /* [out] */ VARIANT __RPC_FAR *lpvarMonth,
            /* [out] */ VARIANT __RPC_FAR *lpvarDay,
            /* [out] */ VARIANT __RPC_FAR *lpvarDayOfWeek,
            /* [out] */ VARIANT __RPC_FAR *lpvarHour,
            /* [out] */ VARIANT __RPC_FAR *lpvarMinute,
            /* [out] */ VARIANT __RPC_FAR *lpvarSecond,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetClockData( 
            /* [in] */ VARIANT varYear,
            /* [in] */ VARIANT varMonth,
            /* [in] */ VARIANT varDay,
            /* [in] */ VARIANT varDayOfWeek,
            /* [in] */ VARIANT varHour,
            /* [in] */ VARIANT varMinute,
            /* [in] */ VARIANT varSecond,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE EntryDeviceStatus( 
            /* [in] */ VARIANT varDeviceList,
            /* [in] */ VARIANT varSize,
            /* [in] */ VARIANT varMonitorCycle,
            /* [in] */ VARIANT varData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActNetworkNumber( 
            /* [retval][out] */ VARIANT __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActNetworkNumber( 
            /* [in] */ VARIANT newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActStationNumber( 
            /* [retval][out] */ VARIANT __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActStationNumber( 
            /* [in] */ VARIANT newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActUnitNumber( 
            /* [retval][out] */ VARIANT __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActUnitNumber( 
            /* [in] */ VARIANT newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActIONumber( 
            /* [retval][out] */ VARIANT __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActIONumber( 
            /* [in] */ VARIANT newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActCpuType( 
            /* [retval][out] */ VARIANT __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActCpuType( 
            /* [in] */ VARIANT newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActTimeOut( 
            /* [retval][out] */ VARIANT __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActTimeOut( 
            /* [in] */ VARIANT newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActDestinationIONumber( 
            /* [retval][out] */ VARIANT __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActDestinationIONumber( 
            /* [in] */ VARIANT newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActMultiDropChannelNumber( 
            /* [retval][out] */ VARIANT __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActMultiDropChannelNumber( 
            /* [in] */ VARIANT newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActThroughNetworkType( 
            /* [retval][out] */ VARIANT __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActThroughNetworkType( 
            /* [in] */ VARIANT newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActIntelligentPreferenceBit( 
            /* [retval][out] */ VARIANT __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActIntelligentPreferenceBit( 
            /* [in] */ VARIANT newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActDidPropertyBit( 
            /* [retval][out] */ VARIANT __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActDidPropertyBit( 
            /* [in] */ VARIANT newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActDsidPropertyBit( 
            /* [retval][out] */ VARIANT __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActDsidPropertyBit( 
            /* [in] */ VARIANT newVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE FreeDeviceStatus( 
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IActMLQCPUQUSBVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IActMLQCPUQUSB __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IActMLQCPUQUSB __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IActMLQCPUQUSB __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IActMLQCPUQUSB __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IActMLQCPUQUSB __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IActMLQCPUQUSB __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IActMLQCPUQUSB __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Open )( 
            IActMLQCPUQUSB __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Close )( 
            IActMLQCPUQUSB __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetDevice )( 
            IActMLQCPUQUSB __RPC_FAR * This,
            /* [in] */ VARIANT varDevice,
            /* [out] */ VARIANT __RPC_FAR *lpvarData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetDevice )( 
            IActMLQCPUQUSB __RPC_FAR * This,
            /* [in] */ VARIANT varDevice,
            /* [in] */ VARIANT varData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceBlock )( 
            IActMLQCPUQUSB __RPC_FAR * This,
            /* [in] */ VARIANT varDevice,
            /* [in] */ VARIANT varSize,
            /* [out] */ VARIANT __RPC_FAR *lpvarData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceBlock )( 
            IActMLQCPUQUSB __RPC_FAR * This,
            /* [in] */ VARIANT varDevice,
            /* [in] */ VARIANT varSize,
            /* [in] */ VARIANT varData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceRandom )( 
            IActMLQCPUQUSB __RPC_FAR * This,
            /* [in] */ VARIANT varDeviceList,
            /* [in] */ VARIANT varSize,
            /* [out] */ VARIANT __RPC_FAR *lpvarData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceRandom )( 
            IActMLQCPUQUSB __RPC_FAR * This,
            /* [in] */ VARIANT varDeviceList,
            /* [in] */ VARIANT varSize,
            /* [in] */ VARIANT varData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadBuffer )( 
            IActMLQCPUQUSB __RPC_FAR * This,
            /* [in] */ VARIANT varStartIO,
            /* [in] */ VARIANT varAddress,
            /* [in] */ VARIANT varReadSize,
            /* [out] */ VARIANT __RPC_FAR *lpvarData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteBuffer )( 
            IActMLQCPUQUSB __RPC_FAR * This,
            /* [in] */ VARIANT varStartIO,
            /* [in] */ VARIANT varAddress,
            /* [in] */ VARIANT varWriteSize,
            /* [in] */ VARIANT varData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetCpuType )( 
            IActMLQCPUQUSB __RPC_FAR * This,
            /* [out] */ VARIANT __RPC_FAR *lpvarCpuName,
            /* [out] */ VARIANT __RPC_FAR *lpvarCpuType,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetCpuStatus )( 
            IActMLQCPUQUSB __RPC_FAR * This,
            /* [in] */ VARIANT varOperation,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetClockData )( 
            IActMLQCPUQUSB __RPC_FAR * This,
            /* [out] */ VARIANT __RPC_FAR *lpvarYear,
            /* [out] */ VARIANT __RPC_FAR *lpvarMonth,
            /* [out] */ VARIANT __RPC_FAR *lpvarDay,
            /* [out] */ VARIANT __RPC_FAR *lpvarDayOfWeek,
            /* [out] */ VARIANT __RPC_FAR *lpvarHour,
            /* [out] */ VARIANT __RPC_FAR *lpvarMinute,
            /* [out] */ VARIANT __RPC_FAR *lpvarSecond,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetClockData )( 
            IActMLQCPUQUSB __RPC_FAR * This,
            /* [in] */ VARIANT varYear,
            /* [in] */ VARIANT varMonth,
            /* [in] */ VARIANT varDay,
            /* [in] */ VARIANT varDayOfWeek,
            /* [in] */ VARIANT varHour,
            /* [in] */ VARIANT varMinute,
            /* [in] */ VARIANT varSecond,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *EntryDeviceStatus )( 
            IActMLQCPUQUSB __RPC_FAR * This,
            /* [in] */ VARIANT varDeviceList,
            /* [in] */ VARIANT varSize,
            /* [in] */ VARIANT varMonitorCycle,
            /* [in] */ VARIANT varData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActNetworkNumber )( 
            IActMLQCPUQUSB __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActNetworkNumber )( 
            IActMLQCPUQUSB __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActStationNumber )( 
            IActMLQCPUQUSB __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActStationNumber )( 
            IActMLQCPUQUSB __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActUnitNumber )( 
            IActMLQCPUQUSB __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActUnitNumber )( 
            IActMLQCPUQUSB __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActIONumber )( 
            IActMLQCPUQUSB __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActIONumber )( 
            IActMLQCPUQUSB __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActCpuType )( 
            IActMLQCPUQUSB __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActCpuType )( 
            IActMLQCPUQUSB __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActTimeOut )( 
            IActMLQCPUQUSB __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActTimeOut )( 
            IActMLQCPUQUSB __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActDestinationIONumber )( 
            IActMLQCPUQUSB __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActDestinationIONumber )( 
            IActMLQCPUQUSB __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActMultiDropChannelNumber )( 
            IActMLQCPUQUSB __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActMultiDropChannelNumber )( 
            IActMLQCPUQUSB __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActThroughNetworkType )( 
            IActMLQCPUQUSB __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActThroughNetworkType )( 
            IActMLQCPUQUSB __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActIntelligentPreferenceBit )( 
            IActMLQCPUQUSB __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActIntelligentPreferenceBit )( 
            IActMLQCPUQUSB __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActDidPropertyBit )( 
            IActMLQCPUQUSB __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActDidPropertyBit )( 
            IActMLQCPUQUSB __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActDsidPropertyBit )( 
            IActMLQCPUQUSB __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActDsidPropertyBit )( 
            IActMLQCPUQUSB __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *FreeDeviceStatus )( 
            IActMLQCPUQUSB __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        END_INTERFACE
    } IActMLQCPUQUSBVtbl;

    interface IActMLQCPUQUSB
    {
        CONST_VTBL struct IActMLQCPUQUSBVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IActMLQCPUQUSB_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IActMLQCPUQUSB_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IActMLQCPUQUSB_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IActMLQCPUQUSB_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IActMLQCPUQUSB_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IActMLQCPUQUSB_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IActMLQCPUQUSB_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IActMLQCPUQUSB_Open(This,lpvarReturnCode)	\
    (This)->lpVtbl -> Open(This,lpvarReturnCode)

#define IActMLQCPUQUSB_Close(This,lpvarReturnCode)	\
    (This)->lpVtbl -> Close(This,lpvarReturnCode)

#define IActMLQCPUQUSB_GetDevice(This,varDevice,lpvarData,lpvarReturnCode)	\
    (This)->lpVtbl -> GetDevice(This,varDevice,lpvarData,lpvarReturnCode)

#define IActMLQCPUQUSB_SetDevice(This,varDevice,varData,lpvarReturnCode)	\
    (This)->lpVtbl -> SetDevice(This,varDevice,varData,lpvarReturnCode)

#define IActMLQCPUQUSB_ReadDeviceBlock(This,varDevice,varSize,lpvarData,lpvarReturnCode)	\
    (This)->lpVtbl -> ReadDeviceBlock(This,varDevice,varSize,lpvarData,lpvarReturnCode)

#define IActMLQCPUQUSB_WriteDeviceBlock(This,varDevice,varSize,varData,lpvarReturnCode)	\
    (This)->lpVtbl -> WriteDeviceBlock(This,varDevice,varSize,varData,lpvarReturnCode)

#define IActMLQCPUQUSB_ReadDeviceRandom(This,varDeviceList,varSize,lpvarData,lpvarReturnCode)	\
    (This)->lpVtbl -> ReadDeviceRandom(This,varDeviceList,varSize,lpvarData,lpvarReturnCode)

#define IActMLQCPUQUSB_WriteDeviceRandom(This,varDeviceList,varSize,varData,lpvarReturnCode)	\
    (This)->lpVtbl -> WriteDeviceRandom(This,varDeviceList,varSize,varData,lpvarReturnCode)

#define IActMLQCPUQUSB_ReadBuffer(This,varStartIO,varAddress,varReadSize,lpvarData,lpvarReturnCode)	\
    (This)->lpVtbl -> ReadBuffer(This,varStartIO,varAddress,varReadSize,lpvarData,lpvarReturnCode)

#define IActMLQCPUQUSB_WriteBuffer(This,varStartIO,varAddress,varWriteSize,varData,lpvarReturnCode)	\
    (This)->lpVtbl -> WriteBuffer(This,varStartIO,varAddress,varWriteSize,varData,lpvarReturnCode)

#define IActMLQCPUQUSB_GetCpuType(This,lpvarCpuName,lpvarCpuType,lpvarReturnCode)	\
    (This)->lpVtbl -> GetCpuType(This,lpvarCpuName,lpvarCpuType,lpvarReturnCode)

#define IActMLQCPUQUSB_SetCpuStatus(This,varOperation,lpvarReturnCode)	\
    (This)->lpVtbl -> SetCpuStatus(This,varOperation,lpvarReturnCode)

#define IActMLQCPUQUSB_GetClockData(This,lpvarYear,lpvarMonth,lpvarDay,lpvarDayOfWeek,lpvarHour,lpvarMinute,lpvarSecond,lpvarReturnCode)	\
    (This)->lpVtbl -> GetClockData(This,lpvarYear,lpvarMonth,lpvarDay,lpvarDayOfWeek,lpvarHour,lpvarMinute,lpvarSecond,lpvarReturnCode)

#define IActMLQCPUQUSB_SetClockData(This,varYear,varMonth,varDay,varDayOfWeek,varHour,varMinute,varSecond,lpvarReturnCode)	\
    (This)->lpVtbl -> SetClockData(This,varYear,varMonth,varDay,varDayOfWeek,varHour,varMinute,varSecond,lpvarReturnCode)

#define IActMLQCPUQUSB_EntryDeviceStatus(This,varDeviceList,varSize,varMonitorCycle,varData,lpvarReturnCode)	\
    (This)->lpVtbl -> EntryDeviceStatus(This,varDeviceList,varSize,varMonitorCycle,varData,lpvarReturnCode)

#define IActMLQCPUQUSB_get_ActNetworkNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActNetworkNumber(This,pVal)

#define IActMLQCPUQUSB_put_ActNetworkNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActNetworkNumber(This,newVal)

#define IActMLQCPUQUSB_get_ActStationNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActStationNumber(This,pVal)

#define IActMLQCPUQUSB_put_ActStationNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActStationNumber(This,newVal)

#define IActMLQCPUQUSB_get_ActUnitNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActUnitNumber(This,pVal)

#define IActMLQCPUQUSB_put_ActUnitNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActUnitNumber(This,newVal)

#define IActMLQCPUQUSB_get_ActIONumber(This,pVal)	\
    (This)->lpVtbl -> get_ActIONumber(This,pVal)

#define IActMLQCPUQUSB_put_ActIONumber(This,newVal)	\
    (This)->lpVtbl -> put_ActIONumber(This,newVal)

#define IActMLQCPUQUSB_get_ActCpuType(This,pVal)	\
    (This)->lpVtbl -> get_ActCpuType(This,pVal)

#define IActMLQCPUQUSB_put_ActCpuType(This,newVal)	\
    (This)->lpVtbl -> put_ActCpuType(This,newVal)

#define IActMLQCPUQUSB_get_ActTimeOut(This,pVal)	\
    (This)->lpVtbl -> get_ActTimeOut(This,pVal)

#define IActMLQCPUQUSB_put_ActTimeOut(This,newVal)	\
    (This)->lpVtbl -> put_ActTimeOut(This,newVal)

#define IActMLQCPUQUSB_get_ActDestinationIONumber(This,pVal)	\
    (This)->lpVtbl -> get_ActDestinationIONumber(This,pVal)

#define IActMLQCPUQUSB_put_ActDestinationIONumber(This,newVal)	\
    (This)->lpVtbl -> put_ActDestinationIONumber(This,newVal)

#define IActMLQCPUQUSB_get_ActMultiDropChannelNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActMultiDropChannelNumber(This,pVal)

#define IActMLQCPUQUSB_put_ActMultiDropChannelNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActMultiDropChannelNumber(This,newVal)

#define IActMLQCPUQUSB_get_ActThroughNetworkType(This,pVal)	\
    (This)->lpVtbl -> get_ActThroughNetworkType(This,pVal)

#define IActMLQCPUQUSB_put_ActThroughNetworkType(This,newVal)	\
    (This)->lpVtbl -> put_ActThroughNetworkType(This,newVal)

#define IActMLQCPUQUSB_get_ActIntelligentPreferenceBit(This,pVal)	\
    (This)->lpVtbl -> get_ActIntelligentPreferenceBit(This,pVal)

#define IActMLQCPUQUSB_put_ActIntelligentPreferenceBit(This,newVal)	\
    (This)->lpVtbl -> put_ActIntelligentPreferenceBit(This,newVal)

#define IActMLQCPUQUSB_get_ActDidPropertyBit(This,pVal)	\
    (This)->lpVtbl -> get_ActDidPropertyBit(This,pVal)

#define IActMLQCPUQUSB_put_ActDidPropertyBit(This,newVal)	\
    (This)->lpVtbl -> put_ActDidPropertyBit(This,newVal)

#define IActMLQCPUQUSB_get_ActDsidPropertyBit(This,pVal)	\
    (This)->lpVtbl -> get_ActDsidPropertyBit(This,pVal)

#define IActMLQCPUQUSB_put_ActDsidPropertyBit(This,newVal)	\
    (This)->lpVtbl -> put_ActDsidPropertyBit(This,newVal)

#define IActMLQCPUQUSB_FreeDeviceStatus(This,lpvarReturnCode)	\
    (This)->lpVtbl -> FreeDeviceStatus(This,lpvarReturnCode)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActMLQCPUQUSB_Open_Proxy( 
    IActMLQCPUQUSB __RPC_FAR * This,
    /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);


void __RPC_STUB IActMLQCPUQUSB_Open_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActMLQCPUQUSB_Close_Proxy( 
    IActMLQCPUQUSB __RPC_FAR * This,
    /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);


void __RPC_STUB IActMLQCPUQUSB_Close_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActMLQCPUQUSB_GetDevice_Proxy( 
    IActMLQCPUQUSB __RPC_FAR * This,
    /* [in] */ VARIANT varDevice,
    /* [out] */ VARIANT __RPC_FAR *lpvarData,
    /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);


void __RPC_STUB IActMLQCPUQUSB_GetDevice_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActMLQCPUQUSB_SetDevice_Proxy( 
    IActMLQCPUQUSB __RPC_FAR * This,
    /* [in] */ VARIANT varDevice,
    /* [in] */ VARIANT varData,
    /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);


void __RPC_STUB IActMLQCPUQUSB_SetDevice_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActMLQCPUQUSB_ReadDeviceBlock_Proxy( 
    IActMLQCPUQUSB __RPC_FAR * This,
    /* [in] */ VARIANT varDevice,
    /* [in] */ VARIANT varSize,
    /* [out] */ VARIANT __RPC_FAR *lpvarData,
    /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);


void __RPC_STUB IActMLQCPUQUSB_ReadDeviceBlock_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActMLQCPUQUSB_WriteDeviceBlock_Proxy( 
    IActMLQCPUQUSB __RPC_FAR * This,
    /* [in] */ VARIANT varDevice,
    /* [in] */ VARIANT varSize,
    /* [in] */ VARIANT varData,
    /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);


void __RPC_STUB IActMLQCPUQUSB_WriteDeviceBlock_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActMLQCPUQUSB_ReadDeviceRandom_Proxy( 
    IActMLQCPUQUSB __RPC_FAR * This,
    /* [in] */ VARIANT varDeviceList,
    /* [in] */ VARIANT varSize,
    /* [out] */ VARIANT __RPC_FAR *lpvarData,
    /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);


void __RPC_STUB IActMLQCPUQUSB_ReadDeviceRandom_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActMLQCPUQUSB_WriteDeviceRandom_Proxy( 
    IActMLQCPUQUSB __RPC_FAR * This,
    /* [in] */ VARIANT varDeviceList,
    /* [in] */ VARIANT varSize,
    /* [in] */ VARIANT varData,
    /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);


void __RPC_STUB IActMLQCPUQUSB_WriteDeviceRandom_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActMLQCPUQUSB_ReadBuffer_Proxy( 
    IActMLQCPUQUSB __RPC_FAR * This,
    /* [in] */ VARIANT varStartIO,
    /* [in] */ VARIANT varAddress,
    /* [in] */ VARIANT varReadSize,
    /* [out] */ VARIANT __RPC_FAR *lpvarData,
    /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);


void __RPC_STUB IActMLQCPUQUSB_ReadBuffer_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActMLQCPUQUSB_WriteBuffer_Proxy( 
    IActMLQCPUQUSB __RPC_FAR * This,
    /* [in] */ VARIANT varStartIO,
    /* [in] */ VARIANT varAddress,
    /* [in] */ VARIANT varWriteSize,
    /* [in] */ VARIANT varData,
    /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);


void __RPC_STUB IActMLQCPUQUSB_WriteBuffer_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActMLQCPUQUSB_GetCpuType_Proxy( 
    IActMLQCPUQUSB __RPC_FAR * This,
    /* [out] */ VARIANT __RPC_FAR *lpvarCpuName,
    /* [out] */ VARIANT __RPC_FAR *lpvarCpuType,
    /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);


void __RPC_STUB IActMLQCPUQUSB_GetCpuType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActMLQCPUQUSB_SetCpuStatus_Proxy( 
    IActMLQCPUQUSB __RPC_FAR * This,
    /* [in] */ VARIANT varOperation,
    /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);


void __RPC_STUB IActMLQCPUQUSB_SetCpuStatus_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActMLQCPUQUSB_GetClockData_Proxy( 
    IActMLQCPUQUSB __RPC_FAR * This,
    /* [out] */ VARIANT __RPC_FAR *lpvarYear,
    /* [out] */ VARIANT __RPC_FAR *lpvarMonth,
    /* [out] */ VARIANT __RPC_FAR *lpvarDay,
    /* [out] */ VARIANT __RPC_FAR *lpvarDayOfWeek,
    /* [out] */ VARIANT __RPC_FAR *lpvarHour,
    /* [out] */ VARIANT __RPC_FAR *lpvarMinute,
    /* [out] */ VARIANT __RPC_FAR *lpvarSecond,
    /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);


void __RPC_STUB IActMLQCPUQUSB_GetClockData_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActMLQCPUQUSB_SetClockData_Proxy( 
    IActMLQCPUQUSB __RPC_FAR * This,
    /* [in] */ VARIANT varYear,
    /* [in] */ VARIANT varMonth,
    /* [in] */ VARIANT varDay,
    /* [in] */ VARIANT varDayOfWeek,
    /* [in] */ VARIANT varHour,
    /* [in] */ VARIANT varMinute,
    /* [in] */ VARIANT varSecond,
    /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);


void __RPC_STUB IActMLQCPUQUSB_SetClockData_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActMLQCPUQUSB_EntryDeviceStatus_Proxy( 
    IActMLQCPUQUSB __RPC_FAR * This,
    /* [in] */ VARIANT varDeviceList,
    /* [in] */ VARIANT varSize,
    /* [in] */ VARIANT varMonitorCycle,
    /* [in] */ VARIANT varData,
    /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);


void __RPC_STUB IActMLQCPUQUSB_EntryDeviceStatus_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActMLQCPUQUSB_get_ActNetworkNumber_Proxy( 
    IActMLQCPUQUSB __RPC_FAR * This,
    /* [retval][out] */ VARIANT __RPC_FAR *pVal);


void __RPC_STUB IActMLQCPUQUSB_get_ActNetworkNumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActMLQCPUQUSB_put_ActNetworkNumber_Proxy( 
    IActMLQCPUQUSB __RPC_FAR * This,
    /* [in] */ VARIANT newVal);


void __RPC_STUB IActMLQCPUQUSB_put_ActNetworkNumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActMLQCPUQUSB_get_ActStationNumber_Proxy( 
    IActMLQCPUQUSB __RPC_FAR * This,
    /* [retval][out] */ VARIANT __RPC_FAR *pVal);


void __RPC_STUB IActMLQCPUQUSB_get_ActStationNumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActMLQCPUQUSB_put_ActStationNumber_Proxy( 
    IActMLQCPUQUSB __RPC_FAR * This,
    /* [in] */ VARIANT newVal);


void __RPC_STUB IActMLQCPUQUSB_put_ActStationNumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActMLQCPUQUSB_get_ActUnitNumber_Proxy( 
    IActMLQCPUQUSB __RPC_FAR * This,
    /* [retval][out] */ VARIANT __RPC_FAR *pVal);


void __RPC_STUB IActMLQCPUQUSB_get_ActUnitNumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActMLQCPUQUSB_put_ActUnitNumber_Proxy( 
    IActMLQCPUQUSB __RPC_FAR * This,
    /* [in] */ VARIANT newVal);


void __RPC_STUB IActMLQCPUQUSB_put_ActUnitNumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActMLQCPUQUSB_get_ActIONumber_Proxy( 
    IActMLQCPUQUSB __RPC_FAR * This,
    /* [retval][out] */ VARIANT __RPC_FAR *pVal);


void __RPC_STUB IActMLQCPUQUSB_get_ActIONumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActMLQCPUQUSB_put_ActIONumber_Proxy( 
    IActMLQCPUQUSB __RPC_FAR * This,
    /* [in] */ VARIANT newVal);


void __RPC_STUB IActMLQCPUQUSB_put_ActIONumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActMLQCPUQUSB_get_ActCpuType_Proxy( 
    IActMLQCPUQUSB __RPC_FAR * This,
    /* [retval][out] */ VARIANT __RPC_FAR *pVal);


void __RPC_STUB IActMLQCPUQUSB_get_ActCpuType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActMLQCPUQUSB_put_ActCpuType_Proxy( 
    IActMLQCPUQUSB __RPC_FAR * This,
    /* [in] */ VARIANT newVal);


void __RPC_STUB IActMLQCPUQUSB_put_ActCpuType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActMLQCPUQUSB_get_ActTimeOut_Proxy( 
    IActMLQCPUQUSB __RPC_FAR * This,
    /* [retval][out] */ VARIANT __RPC_FAR *pVal);


void __RPC_STUB IActMLQCPUQUSB_get_ActTimeOut_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActMLQCPUQUSB_put_ActTimeOut_Proxy( 
    IActMLQCPUQUSB __RPC_FAR * This,
    /* [in] */ VARIANT newVal);


void __RPC_STUB IActMLQCPUQUSB_put_ActTimeOut_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActMLQCPUQUSB_get_ActDestinationIONumber_Proxy( 
    IActMLQCPUQUSB __RPC_FAR * This,
    /* [retval][out] */ VARIANT __RPC_FAR *pVal);


void __RPC_STUB IActMLQCPUQUSB_get_ActDestinationIONumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActMLQCPUQUSB_put_ActDestinationIONumber_Proxy( 
    IActMLQCPUQUSB __RPC_FAR * This,
    /* [in] */ VARIANT newVal);


void __RPC_STUB IActMLQCPUQUSB_put_ActDestinationIONumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActMLQCPUQUSB_get_ActMultiDropChannelNumber_Proxy( 
    IActMLQCPUQUSB __RPC_FAR * This,
    /* [retval][out] */ VARIANT __RPC_FAR *pVal);


void __RPC_STUB IActMLQCPUQUSB_get_ActMultiDropChannelNumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActMLQCPUQUSB_put_ActMultiDropChannelNumber_Proxy( 
    IActMLQCPUQUSB __RPC_FAR * This,
    /* [in] */ VARIANT newVal);


void __RPC_STUB IActMLQCPUQUSB_put_ActMultiDropChannelNumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActMLQCPUQUSB_get_ActThroughNetworkType_Proxy( 
    IActMLQCPUQUSB __RPC_FAR * This,
    /* [retval][out] */ VARIANT __RPC_FAR *pVal);


void __RPC_STUB IActMLQCPUQUSB_get_ActThroughNetworkType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActMLQCPUQUSB_put_ActThroughNetworkType_Proxy( 
    IActMLQCPUQUSB __RPC_FAR * This,
    /* [in] */ VARIANT newVal);


void __RPC_STUB IActMLQCPUQUSB_put_ActThroughNetworkType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActMLQCPUQUSB_get_ActIntelligentPreferenceBit_Proxy( 
    IActMLQCPUQUSB __RPC_FAR * This,
    /* [retval][out] */ VARIANT __RPC_FAR *pVal);


void __RPC_STUB IActMLQCPUQUSB_get_ActIntelligentPreferenceBit_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActMLQCPUQUSB_put_ActIntelligentPreferenceBit_Proxy( 
    IActMLQCPUQUSB __RPC_FAR * This,
    /* [in] */ VARIANT newVal);


void __RPC_STUB IActMLQCPUQUSB_put_ActIntelligentPreferenceBit_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActMLQCPUQUSB_get_ActDidPropertyBit_Proxy( 
    IActMLQCPUQUSB __RPC_FAR * This,
    /* [retval][out] */ VARIANT __RPC_FAR *pVal);


void __RPC_STUB IActMLQCPUQUSB_get_ActDidPropertyBit_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActMLQCPUQUSB_put_ActDidPropertyBit_Proxy( 
    IActMLQCPUQUSB __RPC_FAR * This,
    /* [in] */ VARIANT newVal);


void __RPC_STUB IActMLQCPUQUSB_put_ActDidPropertyBit_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActMLQCPUQUSB_get_ActDsidPropertyBit_Proxy( 
    IActMLQCPUQUSB __RPC_FAR * This,
    /* [retval][out] */ VARIANT __RPC_FAR *pVal);


void __RPC_STUB IActMLQCPUQUSB_get_ActDsidPropertyBit_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActMLQCPUQUSB_put_ActDsidPropertyBit_Proxy( 
    IActMLQCPUQUSB __RPC_FAR * This,
    /* [in] */ VARIANT newVal);


void __RPC_STUB IActMLQCPUQUSB_put_ActDsidPropertyBit_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActMLQCPUQUSB_FreeDeviceStatus_Proxy( 
    IActMLQCPUQUSB __RPC_FAR * This,
    /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);


void __RPC_STUB IActMLQCPUQUSB_FreeDeviceStatus_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IActMLQCPUQUSB_INTERFACE_DEFINED__ */


#ifndef __IActMLQCPUQUSB2_INTERFACE_DEFINED__
#define __IActMLQCPUQUSB2_INTERFACE_DEFINED__

/* interface IActMLQCPUQUSB2 */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IActMLQCPUQUSB2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("87166060-710B-11d5-9318-009099244EFD")
    IActMLQCPUQUSB2 : public IActMLQCPUQUSB
    {
    public:
    };
    
#else 	/* C style interface */

    typedef struct IActMLQCPUQUSB2Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IActMLQCPUQUSB2 __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IActMLQCPUQUSB2 __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IActMLQCPUQUSB2 __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IActMLQCPUQUSB2 __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IActMLQCPUQUSB2 __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IActMLQCPUQUSB2 __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IActMLQCPUQUSB2 __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Open )( 
            IActMLQCPUQUSB2 __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Close )( 
            IActMLQCPUQUSB2 __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetDevice )( 
            IActMLQCPUQUSB2 __RPC_FAR * This,
            /* [in] */ VARIANT varDevice,
            /* [out] */ VARIANT __RPC_FAR *lpvarData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetDevice )( 
            IActMLQCPUQUSB2 __RPC_FAR * This,
            /* [in] */ VARIANT varDevice,
            /* [in] */ VARIANT varData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceBlock )( 
            IActMLQCPUQUSB2 __RPC_FAR * This,
            /* [in] */ VARIANT varDevice,
            /* [in] */ VARIANT varSize,
            /* [out] */ VARIANT __RPC_FAR *lpvarData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceBlock )( 
            IActMLQCPUQUSB2 __RPC_FAR * This,
            /* [in] */ VARIANT varDevice,
            /* [in] */ VARIANT varSize,
            /* [in] */ VARIANT varData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceRandom )( 
            IActMLQCPUQUSB2 __RPC_FAR * This,
            /* [in] */ VARIANT varDeviceList,
            /* [in] */ VARIANT varSize,
            /* [out] */ VARIANT __RPC_FAR *lpvarData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceRandom )( 
            IActMLQCPUQUSB2 __RPC_FAR * This,
            /* [in] */ VARIANT varDeviceList,
            /* [in] */ VARIANT varSize,
            /* [in] */ VARIANT varData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadBuffer )( 
            IActMLQCPUQUSB2 __RPC_FAR * This,
            /* [in] */ VARIANT varStartIO,
            /* [in] */ VARIANT varAddress,
            /* [in] */ VARIANT varReadSize,
            /* [out] */ VARIANT __RPC_FAR *lpvarData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteBuffer )( 
            IActMLQCPUQUSB2 __RPC_FAR * This,
            /* [in] */ VARIANT varStartIO,
            /* [in] */ VARIANT varAddress,
            /* [in] */ VARIANT varWriteSize,
            /* [in] */ VARIANT varData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetCpuType )( 
            IActMLQCPUQUSB2 __RPC_FAR * This,
            /* [out] */ VARIANT __RPC_FAR *lpvarCpuName,
            /* [out] */ VARIANT __RPC_FAR *lpvarCpuType,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetCpuStatus )( 
            IActMLQCPUQUSB2 __RPC_FAR * This,
            /* [in] */ VARIANT varOperation,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetClockData )( 
            IActMLQCPUQUSB2 __RPC_FAR * This,
            /* [out] */ VARIANT __RPC_FAR *lpvarYear,
            /* [out] */ VARIANT __RPC_FAR *lpvarMonth,
            /* [out] */ VARIANT __RPC_FAR *lpvarDay,
            /* [out] */ VARIANT __RPC_FAR *lpvarDayOfWeek,
            /* [out] */ VARIANT __RPC_FAR *lpvarHour,
            /* [out] */ VARIANT __RPC_FAR *lpvarMinute,
            /* [out] */ VARIANT __RPC_FAR *lpvarSecond,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetClockData )( 
            IActMLQCPUQUSB2 __RPC_FAR * This,
            /* [in] */ VARIANT varYear,
            /* [in] */ VARIANT varMonth,
            /* [in] */ VARIANT varDay,
            /* [in] */ VARIANT varDayOfWeek,
            /* [in] */ VARIANT varHour,
            /* [in] */ VARIANT varMinute,
            /* [in] */ VARIANT varSecond,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *EntryDeviceStatus )( 
            IActMLQCPUQUSB2 __RPC_FAR * This,
            /* [in] */ VARIANT varDeviceList,
            /* [in] */ VARIANT varSize,
            /* [in] */ VARIANT varMonitorCycle,
            /* [in] */ VARIANT varData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActNetworkNumber )( 
            IActMLQCPUQUSB2 __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActNetworkNumber )( 
            IActMLQCPUQUSB2 __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActStationNumber )( 
            IActMLQCPUQUSB2 __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActStationNumber )( 
            IActMLQCPUQUSB2 __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActUnitNumber )( 
            IActMLQCPUQUSB2 __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActUnitNumber )( 
            IActMLQCPUQUSB2 __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActIONumber )( 
            IActMLQCPUQUSB2 __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActIONumber )( 
            IActMLQCPUQUSB2 __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActCpuType )( 
            IActMLQCPUQUSB2 __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActCpuType )( 
            IActMLQCPUQUSB2 __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActTimeOut )( 
            IActMLQCPUQUSB2 __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActTimeOut )( 
            IActMLQCPUQUSB2 __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActDestinationIONumber )( 
            IActMLQCPUQUSB2 __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActDestinationIONumber )( 
            IActMLQCPUQUSB2 __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActMultiDropChannelNumber )( 
            IActMLQCPUQUSB2 __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActMultiDropChannelNumber )( 
            IActMLQCPUQUSB2 __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActThroughNetworkType )( 
            IActMLQCPUQUSB2 __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActThroughNetworkType )( 
            IActMLQCPUQUSB2 __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActIntelligentPreferenceBit )( 
            IActMLQCPUQUSB2 __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActIntelligentPreferenceBit )( 
            IActMLQCPUQUSB2 __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActDidPropertyBit )( 
            IActMLQCPUQUSB2 __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActDidPropertyBit )( 
            IActMLQCPUQUSB2 __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActDsidPropertyBit )( 
            IActMLQCPUQUSB2 __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActDsidPropertyBit )( 
            IActMLQCPUQUSB2 __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *FreeDeviceStatus )( 
            IActMLQCPUQUSB2 __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        END_INTERFACE
    } IActMLQCPUQUSB2Vtbl;

    interface IActMLQCPUQUSB2
    {
        CONST_VTBL struct IActMLQCPUQUSB2Vtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IActMLQCPUQUSB2_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IActMLQCPUQUSB2_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IActMLQCPUQUSB2_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IActMLQCPUQUSB2_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IActMLQCPUQUSB2_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IActMLQCPUQUSB2_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IActMLQCPUQUSB2_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IActMLQCPUQUSB2_Open(This,lpvarReturnCode)	\
    (This)->lpVtbl -> Open(This,lpvarReturnCode)

#define IActMLQCPUQUSB2_Close(This,lpvarReturnCode)	\
    (This)->lpVtbl -> Close(This,lpvarReturnCode)

#define IActMLQCPUQUSB2_GetDevice(This,varDevice,lpvarData,lpvarReturnCode)	\
    (This)->lpVtbl -> GetDevice(This,varDevice,lpvarData,lpvarReturnCode)

#define IActMLQCPUQUSB2_SetDevice(This,varDevice,varData,lpvarReturnCode)	\
    (This)->lpVtbl -> SetDevice(This,varDevice,varData,lpvarReturnCode)

#define IActMLQCPUQUSB2_ReadDeviceBlock(This,varDevice,varSize,lpvarData,lpvarReturnCode)	\
    (This)->lpVtbl -> ReadDeviceBlock(This,varDevice,varSize,lpvarData,lpvarReturnCode)

#define IActMLQCPUQUSB2_WriteDeviceBlock(This,varDevice,varSize,varData,lpvarReturnCode)	\
    (This)->lpVtbl -> WriteDeviceBlock(This,varDevice,varSize,varData,lpvarReturnCode)

#define IActMLQCPUQUSB2_ReadDeviceRandom(This,varDeviceList,varSize,lpvarData,lpvarReturnCode)	\
    (This)->lpVtbl -> ReadDeviceRandom(This,varDeviceList,varSize,lpvarData,lpvarReturnCode)

#define IActMLQCPUQUSB2_WriteDeviceRandom(This,varDeviceList,varSize,varData,lpvarReturnCode)	\
    (This)->lpVtbl -> WriteDeviceRandom(This,varDeviceList,varSize,varData,lpvarReturnCode)

#define IActMLQCPUQUSB2_ReadBuffer(This,varStartIO,varAddress,varReadSize,lpvarData,lpvarReturnCode)	\
    (This)->lpVtbl -> ReadBuffer(This,varStartIO,varAddress,varReadSize,lpvarData,lpvarReturnCode)

#define IActMLQCPUQUSB2_WriteBuffer(This,varStartIO,varAddress,varWriteSize,varData,lpvarReturnCode)	\
    (This)->lpVtbl -> WriteBuffer(This,varStartIO,varAddress,varWriteSize,varData,lpvarReturnCode)

#define IActMLQCPUQUSB2_GetCpuType(This,lpvarCpuName,lpvarCpuType,lpvarReturnCode)	\
    (This)->lpVtbl -> GetCpuType(This,lpvarCpuName,lpvarCpuType,lpvarReturnCode)

#define IActMLQCPUQUSB2_SetCpuStatus(This,varOperation,lpvarReturnCode)	\
    (This)->lpVtbl -> SetCpuStatus(This,varOperation,lpvarReturnCode)

#define IActMLQCPUQUSB2_GetClockData(This,lpvarYear,lpvarMonth,lpvarDay,lpvarDayOfWeek,lpvarHour,lpvarMinute,lpvarSecond,lpvarReturnCode)	\
    (This)->lpVtbl -> GetClockData(This,lpvarYear,lpvarMonth,lpvarDay,lpvarDayOfWeek,lpvarHour,lpvarMinute,lpvarSecond,lpvarReturnCode)

#define IActMLQCPUQUSB2_SetClockData(This,varYear,varMonth,varDay,varDayOfWeek,varHour,varMinute,varSecond,lpvarReturnCode)	\
    (This)->lpVtbl -> SetClockData(This,varYear,varMonth,varDay,varDayOfWeek,varHour,varMinute,varSecond,lpvarReturnCode)

#define IActMLQCPUQUSB2_EntryDeviceStatus(This,varDeviceList,varSize,varMonitorCycle,varData,lpvarReturnCode)	\
    (This)->lpVtbl -> EntryDeviceStatus(This,varDeviceList,varSize,varMonitorCycle,varData,lpvarReturnCode)

#define IActMLQCPUQUSB2_get_ActNetworkNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActNetworkNumber(This,pVal)

#define IActMLQCPUQUSB2_put_ActNetworkNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActNetworkNumber(This,newVal)

#define IActMLQCPUQUSB2_get_ActStationNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActStationNumber(This,pVal)

#define IActMLQCPUQUSB2_put_ActStationNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActStationNumber(This,newVal)

#define IActMLQCPUQUSB2_get_ActUnitNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActUnitNumber(This,pVal)

#define IActMLQCPUQUSB2_put_ActUnitNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActUnitNumber(This,newVal)

#define IActMLQCPUQUSB2_get_ActIONumber(This,pVal)	\
    (This)->lpVtbl -> get_ActIONumber(This,pVal)

#define IActMLQCPUQUSB2_put_ActIONumber(This,newVal)	\
    (This)->lpVtbl -> put_ActIONumber(This,newVal)

#define IActMLQCPUQUSB2_get_ActCpuType(This,pVal)	\
    (This)->lpVtbl -> get_ActCpuType(This,pVal)

#define IActMLQCPUQUSB2_put_ActCpuType(This,newVal)	\
    (This)->lpVtbl -> put_ActCpuType(This,newVal)

#define IActMLQCPUQUSB2_get_ActTimeOut(This,pVal)	\
    (This)->lpVtbl -> get_ActTimeOut(This,pVal)

#define IActMLQCPUQUSB2_put_ActTimeOut(This,newVal)	\
    (This)->lpVtbl -> put_ActTimeOut(This,newVal)

#define IActMLQCPUQUSB2_get_ActDestinationIONumber(This,pVal)	\
    (This)->lpVtbl -> get_ActDestinationIONumber(This,pVal)

#define IActMLQCPUQUSB2_put_ActDestinationIONumber(This,newVal)	\
    (This)->lpVtbl -> put_ActDestinationIONumber(This,newVal)

#define IActMLQCPUQUSB2_get_ActMultiDropChannelNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActMultiDropChannelNumber(This,pVal)

#define IActMLQCPUQUSB2_put_ActMultiDropChannelNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActMultiDropChannelNumber(This,newVal)

#define IActMLQCPUQUSB2_get_ActThroughNetworkType(This,pVal)	\
    (This)->lpVtbl -> get_ActThroughNetworkType(This,pVal)

#define IActMLQCPUQUSB2_put_ActThroughNetworkType(This,newVal)	\
    (This)->lpVtbl -> put_ActThroughNetworkType(This,newVal)

#define IActMLQCPUQUSB2_get_ActIntelligentPreferenceBit(This,pVal)	\
    (This)->lpVtbl -> get_ActIntelligentPreferenceBit(This,pVal)

#define IActMLQCPUQUSB2_put_ActIntelligentPreferenceBit(This,newVal)	\
    (This)->lpVtbl -> put_ActIntelligentPreferenceBit(This,newVal)

#define IActMLQCPUQUSB2_get_ActDidPropertyBit(This,pVal)	\
    (This)->lpVtbl -> get_ActDidPropertyBit(This,pVal)

#define IActMLQCPUQUSB2_put_ActDidPropertyBit(This,newVal)	\
    (This)->lpVtbl -> put_ActDidPropertyBit(This,newVal)

#define IActMLQCPUQUSB2_get_ActDsidPropertyBit(This,pVal)	\
    (This)->lpVtbl -> get_ActDsidPropertyBit(This,pVal)

#define IActMLQCPUQUSB2_put_ActDsidPropertyBit(This,newVal)	\
    (This)->lpVtbl -> put_ActDsidPropertyBit(This,newVal)

#define IActMLQCPUQUSB2_FreeDeviceStatus(This,lpvarReturnCode)	\
    (This)->lpVtbl -> FreeDeviceStatus(This,lpvarReturnCode)


#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IActMLQCPUQUSB2_INTERFACE_DEFINED__ */


#ifndef __IActMLQCPUQUSB3_INTERFACE_DEFINED__
#define __IActMLQCPUQUSB3_INTERFACE_DEFINED__

/* interface IActMLQCPUQUSB3 */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IActMLQCPUQUSB3;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("115992F2-6EC2-11d5-9314-009099244EFD")
    IActMLQCPUQUSB3 : public IActMLQCPUQUSB2
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ReadDeviceBlock2( 
            /* [in] */ VARIANT varDevice,
            /* [in] */ VARIANT varSize,
            /* [out] */ VARIANT __RPC_FAR *lpvarData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE WriteDeviceBlock2( 
            /* [in] */ VARIANT varDevice,
            /* [in] */ VARIANT varSize,
            /* [in] */ VARIANT varData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ReadDeviceRandom2( 
            /* [in] */ VARIANT varDeviceList,
            /* [in] */ VARIANT varSize,
            /* [out] */ VARIANT __RPC_FAR *lpvarData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE WriteDeviceRandom2( 
            /* [in] */ VARIANT varDeviceList,
            /* [in] */ VARIANT varSize,
            /* [in] */ VARIANT varData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetDevice2( 
            /* [in] */ VARIANT varDevice,
            /* [out] */ VARIANT __RPC_FAR *lpvarData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetDevice2( 
            /* [in] */ VARIANT varDevice,
            /* [in] */ VARIANT varData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IActMLQCPUQUSB3Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IActMLQCPUQUSB3 __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IActMLQCPUQUSB3 __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IActMLQCPUQUSB3 __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IActMLQCPUQUSB3 __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IActMLQCPUQUSB3 __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IActMLQCPUQUSB3 __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IActMLQCPUQUSB3 __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Open )( 
            IActMLQCPUQUSB3 __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Close )( 
            IActMLQCPUQUSB3 __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetDevice )( 
            IActMLQCPUQUSB3 __RPC_FAR * This,
            /* [in] */ VARIANT varDevice,
            /* [out] */ VARIANT __RPC_FAR *lpvarData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetDevice )( 
            IActMLQCPUQUSB3 __RPC_FAR * This,
            /* [in] */ VARIANT varDevice,
            /* [in] */ VARIANT varData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceBlock )( 
            IActMLQCPUQUSB3 __RPC_FAR * This,
            /* [in] */ VARIANT varDevice,
            /* [in] */ VARIANT varSize,
            /* [out] */ VARIANT __RPC_FAR *lpvarData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceBlock )( 
            IActMLQCPUQUSB3 __RPC_FAR * This,
            /* [in] */ VARIANT varDevice,
            /* [in] */ VARIANT varSize,
            /* [in] */ VARIANT varData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceRandom )( 
            IActMLQCPUQUSB3 __RPC_FAR * This,
            /* [in] */ VARIANT varDeviceList,
            /* [in] */ VARIANT varSize,
            /* [out] */ VARIANT __RPC_FAR *lpvarData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceRandom )( 
            IActMLQCPUQUSB3 __RPC_FAR * This,
            /* [in] */ VARIANT varDeviceList,
            /* [in] */ VARIANT varSize,
            /* [in] */ VARIANT varData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadBuffer )( 
            IActMLQCPUQUSB3 __RPC_FAR * This,
            /* [in] */ VARIANT varStartIO,
            /* [in] */ VARIANT varAddress,
            /* [in] */ VARIANT varReadSize,
            /* [out] */ VARIANT __RPC_FAR *lpvarData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteBuffer )( 
            IActMLQCPUQUSB3 __RPC_FAR * This,
            /* [in] */ VARIANT varStartIO,
            /* [in] */ VARIANT varAddress,
            /* [in] */ VARIANT varWriteSize,
            /* [in] */ VARIANT varData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetCpuType )( 
            IActMLQCPUQUSB3 __RPC_FAR * This,
            /* [out] */ VARIANT __RPC_FAR *lpvarCpuName,
            /* [out] */ VARIANT __RPC_FAR *lpvarCpuType,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetCpuStatus )( 
            IActMLQCPUQUSB3 __RPC_FAR * This,
            /* [in] */ VARIANT varOperation,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetClockData )( 
            IActMLQCPUQUSB3 __RPC_FAR * This,
            /* [out] */ VARIANT __RPC_FAR *lpvarYear,
            /* [out] */ VARIANT __RPC_FAR *lpvarMonth,
            /* [out] */ VARIANT __RPC_FAR *lpvarDay,
            /* [out] */ VARIANT __RPC_FAR *lpvarDayOfWeek,
            /* [out] */ VARIANT __RPC_FAR *lpvarHour,
            /* [out] */ VARIANT __RPC_FAR *lpvarMinute,
            /* [out] */ VARIANT __RPC_FAR *lpvarSecond,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetClockData )( 
            IActMLQCPUQUSB3 __RPC_FAR * This,
            /* [in] */ VARIANT varYear,
            /* [in] */ VARIANT varMonth,
            /* [in] */ VARIANT varDay,
            /* [in] */ VARIANT varDayOfWeek,
            /* [in] */ VARIANT varHour,
            /* [in] */ VARIANT varMinute,
            /* [in] */ VARIANT varSecond,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *EntryDeviceStatus )( 
            IActMLQCPUQUSB3 __RPC_FAR * This,
            /* [in] */ VARIANT varDeviceList,
            /* [in] */ VARIANT varSize,
            /* [in] */ VARIANT varMonitorCycle,
            /* [in] */ VARIANT varData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActNetworkNumber )( 
            IActMLQCPUQUSB3 __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActNetworkNumber )( 
            IActMLQCPUQUSB3 __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActStationNumber )( 
            IActMLQCPUQUSB3 __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActStationNumber )( 
            IActMLQCPUQUSB3 __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActUnitNumber )( 
            IActMLQCPUQUSB3 __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActUnitNumber )( 
            IActMLQCPUQUSB3 __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActIONumber )( 
            IActMLQCPUQUSB3 __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActIONumber )( 
            IActMLQCPUQUSB3 __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActCpuType )( 
            IActMLQCPUQUSB3 __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActCpuType )( 
            IActMLQCPUQUSB3 __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActTimeOut )( 
            IActMLQCPUQUSB3 __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActTimeOut )( 
            IActMLQCPUQUSB3 __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActDestinationIONumber )( 
            IActMLQCPUQUSB3 __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActDestinationIONumber )( 
            IActMLQCPUQUSB3 __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActMultiDropChannelNumber )( 
            IActMLQCPUQUSB3 __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActMultiDropChannelNumber )( 
            IActMLQCPUQUSB3 __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActThroughNetworkType )( 
            IActMLQCPUQUSB3 __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActThroughNetworkType )( 
            IActMLQCPUQUSB3 __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActIntelligentPreferenceBit )( 
            IActMLQCPUQUSB3 __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActIntelligentPreferenceBit )( 
            IActMLQCPUQUSB3 __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActDidPropertyBit )( 
            IActMLQCPUQUSB3 __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActDidPropertyBit )( 
            IActMLQCPUQUSB3 __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActDsidPropertyBit )( 
            IActMLQCPUQUSB3 __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActDsidPropertyBit )( 
            IActMLQCPUQUSB3 __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *FreeDeviceStatus )( 
            IActMLQCPUQUSB3 __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceBlock2 )( 
            IActMLQCPUQUSB3 __RPC_FAR * This,
            /* [in] */ VARIANT varDevice,
            /* [in] */ VARIANT varSize,
            /* [out] */ VARIANT __RPC_FAR *lpvarData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceBlock2 )( 
            IActMLQCPUQUSB3 __RPC_FAR * This,
            /* [in] */ VARIANT varDevice,
            /* [in] */ VARIANT varSize,
            /* [in] */ VARIANT varData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceRandom2 )( 
            IActMLQCPUQUSB3 __RPC_FAR * This,
            /* [in] */ VARIANT varDeviceList,
            /* [in] */ VARIANT varSize,
            /* [out] */ VARIANT __RPC_FAR *lpvarData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceRandom2 )( 
            IActMLQCPUQUSB3 __RPC_FAR * This,
            /* [in] */ VARIANT varDeviceList,
            /* [in] */ VARIANT varSize,
            /* [in] */ VARIANT varData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetDevice2 )( 
            IActMLQCPUQUSB3 __RPC_FAR * This,
            /* [in] */ VARIANT varDevice,
            /* [out] */ VARIANT __RPC_FAR *lpvarData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetDevice2 )( 
            IActMLQCPUQUSB3 __RPC_FAR * This,
            /* [in] */ VARIANT varDevice,
            /* [in] */ VARIANT varData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        END_INTERFACE
    } IActMLQCPUQUSB3Vtbl;

    interface IActMLQCPUQUSB3
    {
        CONST_VTBL struct IActMLQCPUQUSB3Vtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IActMLQCPUQUSB3_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IActMLQCPUQUSB3_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IActMLQCPUQUSB3_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IActMLQCPUQUSB3_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IActMLQCPUQUSB3_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IActMLQCPUQUSB3_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IActMLQCPUQUSB3_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IActMLQCPUQUSB3_Open(This,lpvarReturnCode)	\
    (This)->lpVtbl -> Open(This,lpvarReturnCode)

#define IActMLQCPUQUSB3_Close(This,lpvarReturnCode)	\
    (This)->lpVtbl -> Close(This,lpvarReturnCode)

#define IActMLQCPUQUSB3_GetDevice(This,varDevice,lpvarData,lpvarReturnCode)	\
    (This)->lpVtbl -> GetDevice(This,varDevice,lpvarData,lpvarReturnCode)

#define IActMLQCPUQUSB3_SetDevice(This,varDevice,varData,lpvarReturnCode)	\
    (This)->lpVtbl -> SetDevice(This,varDevice,varData,lpvarReturnCode)

#define IActMLQCPUQUSB3_ReadDeviceBlock(This,varDevice,varSize,lpvarData,lpvarReturnCode)	\
    (This)->lpVtbl -> ReadDeviceBlock(This,varDevice,varSize,lpvarData,lpvarReturnCode)

#define IActMLQCPUQUSB3_WriteDeviceBlock(This,varDevice,varSize,varData,lpvarReturnCode)	\
    (This)->lpVtbl -> WriteDeviceBlock(This,varDevice,varSize,varData,lpvarReturnCode)

#define IActMLQCPUQUSB3_ReadDeviceRandom(This,varDeviceList,varSize,lpvarData,lpvarReturnCode)	\
    (This)->lpVtbl -> ReadDeviceRandom(This,varDeviceList,varSize,lpvarData,lpvarReturnCode)

#define IActMLQCPUQUSB3_WriteDeviceRandom(This,varDeviceList,varSize,varData,lpvarReturnCode)	\
    (This)->lpVtbl -> WriteDeviceRandom(This,varDeviceList,varSize,varData,lpvarReturnCode)

#define IActMLQCPUQUSB3_ReadBuffer(This,varStartIO,varAddress,varReadSize,lpvarData,lpvarReturnCode)	\
    (This)->lpVtbl -> ReadBuffer(This,varStartIO,varAddress,varReadSize,lpvarData,lpvarReturnCode)

#define IActMLQCPUQUSB3_WriteBuffer(This,varStartIO,varAddress,varWriteSize,varData,lpvarReturnCode)	\
    (This)->lpVtbl -> WriteBuffer(This,varStartIO,varAddress,varWriteSize,varData,lpvarReturnCode)

#define IActMLQCPUQUSB3_GetCpuType(This,lpvarCpuName,lpvarCpuType,lpvarReturnCode)	\
    (This)->lpVtbl -> GetCpuType(This,lpvarCpuName,lpvarCpuType,lpvarReturnCode)

#define IActMLQCPUQUSB3_SetCpuStatus(This,varOperation,lpvarReturnCode)	\
    (This)->lpVtbl -> SetCpuStatus(This,varOperation,lpvarReturnCode)

#define IActMLQCPUQUSB3_GetClockData(This,lpvarYear,lpvarMonth,lpvarDay,lpvarDayOfWeek,lpvarHour,lpvarMinute,lpvarSecond,lpvarReturnCode)	\
    (This)->lpVtbl -> GetClockData(This,lpvarYear,lpvarMonth,lpvarDay,lpvarDayOfWeek,lpvarHour,lpvarMinute,lpvarSecond,lpvarReturnCode)

#define IActMLQCPUQUSB3_SetClockData(This,varYear,varMonth,varDay,varDayOfWeek,varHour,varMinute,varSecond,lpvarReturnCode)	\
    (This)->lpVtbl -> SetClockData(This,varYear,varMonth,varDay,varDayOfWeek,varHour,varMinute,varSecond,lpvarReturnCode)

#define IActMLQCPUQUSB3_EntryDeviceStatus(This,varDeviceList,varSize,varMonitorCycle,varData,lpvarReturnCode)	\
    (This)->lpVtbl -> EntryDeviceStatus(This,varDeviceList,varSize,varMonitorCycle,varData,lpvarReturnCode)

#define IActMLQCPUQUSB3_get_ActNetworkNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActNetworkNumber(This,pVal)

#define IActMLQCPUQUSB3_put_ActNetworkNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActNetworkNumber(This,newVal)

#define IActMLQCPUQUSB3_get_ActStationNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActStationNumber(This,pVal)

#define IActMLQCPUQUSB3_put_ActStationNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActStationNumber(This,newVal)

#define IActMLQCPUQUSB3_get_ActUnitNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActUnitNumber(This,pVal)

#define IActMLQCPUQUSB3_put_ActUnitNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActUnitNumber(This,newVal)

#define IActMLQCPUQUSB3_get_ActIONumber(This,pVal)	\
    (This)->lpVtbl -> get_ActIONumber(This,pVal)

#define IActMLQCPUQUSB3_put_ActIONumber(This,newVal)	\
    (This)->lpVtbl -> put_ActIONumber(This,newVal)

#define IActMLQCPUQUSB3_get_ActCpuType(This,pVal)	\
    (This)->lpVtbl -> get_ActCpuType(This,pVal)

#define IActMLQCPUQUSB3_put_ActCpuType(This,newVal)	\
    (This)->lpVtbl -> put_ActCpuType(This,newVal)

#define IActMLQCPUQUSB3_get_ActTimeOut(This,pVal)	\
    (This)->lpVtbl -> get_ActTimeOut(This,pVal)

#define IActMLQCPUQUSB3_put_ActTimeOut(This,newVal)	\
    (This)->lpVtbl -> put_ActTimeOut(This,newVal)

#define IActMLQCPUQUSB3_get_ActDestinationIONumber(This,pVal)	\
    (This)->lpVtbl -> get_ActDestinationIONumber(This,pVal)

#define IActMLQCPUQUSB3_put_ActDestinationIONumber(This,newVal)	\
    (This)->lpVtbl -> put_ActDestinationIONumber(This,newVal)

#define IActMLQCPUQUSB3_get_ActMultiDropChannelNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActMultiDropChannelNumber(This,pVal)

#define IActMLQCPUQUSB3_put_ActMultiDropChannelNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActMultiDropChannelNumber(This,newVal)

#define IActMLQCPUQUSB3_get_ActThroughNetworkType(This,pVal)	\
    (This)->lpVtbl -> get_ActThroughNetworkType(This,pVal)

#define IActMLQCPUQUSB3_put_ActThroughNetworkType(This,newVal)	\
    (This)->lpVtbl -> put_ActThroughNetworkType(This,newVal)

#define IActMLQCPUQUSB3_get_ActIntelligentPreferenceBit(This,pVal)	\
    (This)->lpVtbl -> get_ActIntelligentPreferenceBit(This,pVal)

#define IActMLQCPUQUSB3_put_ActIntelligentPreferenceBit(This,newVal)	\
    (This)->lpVtbl -> put_ActIntelligentPreferenceBit(This,newVal)

#define IActMLQCPUQUSB3_get_ActDidPropertyBit(This,pVal)	\
    (This)->lpVtbl -> get_ActDidPropertyBit(This,pVal)

#define IActMLQCPUQUSB3_put_ActDidPropertyBit(This,newVal)	\
    (This)->lpVtbl -> put_ActDidPropertyBit(This,newVal)

#define IActMLQCPUQUSB3_get_ActDsidPropertyBit(This,pVal)	\
    (This)->lpVtbl -> get_ActDsidPropertyBit(This,pVal)

#define IActMLQCPUQUSB3_put_ActDsidPropertyBit(This,newVal)	\
    (This)->lpVtbl -> put_ActDsidPropertyBit(This,newVal)

#define IActMLQCPUQUSB3_FreeDeviceStatus(This,lpvarReturnCode)	\
    (This)->lpVtbl -> FreeDeviceStatus(This,lpvarReturnCode)



#define IActMLQCPUQUSB3_ReadDeviceBlock2(This,varDevice,varSize,lpvarData,lpvarReturnCode)	\
    (This)->lpVtbl -> ReadDeviceBlock2(This,varDevice,varSize,lpvarData,lpvarReturnCode)

#define IActMLQCPUQUSB3_WriteDeviceBlock2(This,varDevice,varSize,varData,lpvarReturnCode)	\
    (This)->lpVtbl -> WriteDeviceBlock2(This,varDevice,varSize,varData,lpvarReturnCode)

#define IActMLQCPUQUSB3_ReadDeviceRandom2(This,varDeviceList,varSize,lpvarData,lpvarReturnCode)	\
    (This)->lpVtbl -> ReadDeviceRandom2(This,varDeviceList,varSize,lpvarData,lpvarReturnCode)

#define IActMLQCPUQUSB3_WriteDeviceRandom2(This,varDeviceList,varSize,varData,lpvarReturnCode)	\
    (This)->lpVtbl -> WriteDeviceRandom2(This,varDeviceList,varSize,varData,lpvarReturnCode)

#define IActMLQCPUQUSB3_GetDevice2(This,varDevice,lpvarData,lpvarReturnCode)	\
    (This)->lpVtbl -> GetDevice2(This,varDevice,lpvarData,lpvarReturnCode)

#define IActMLQCPUQUSB3_SetDevice2(This,varDevice,varData,lpvarReturnCode)	\
    (This)->lpVtbl -> SetDevice2(This,varDevice,varData,lpvarReturnCode)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActMLQCPUQUSB3_ReadDeviceBlock2_Proxy( 
    IActMLQCPUQUSB3 __RPC_FAR * This,
    /* [in] */ VARIANT varDevice,
    /* [in] */ VARIANT varSize,
    /* [out] */ VARIANT __RPC_FAR *lpvarData,
    /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);


void __RPC_STUB IActMLQCPUQUSB3_ReadDeviceBlock2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActMLQCPUQUSB3_WriteDeviceBlock2_Proxy( 
    IActMLQCPUQUSB3 __RPC_FAR * This,
    /* [in] */ VARIANT varDevice,
    /* [in] */ VARIANT varSize,
    /* [in] */ VARIANT varData,
    /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);


void __RPC_STUB IActMLQCPUQUSB3_WriteDeviceBlock2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActMLQCPUQUSB3_ReadDeviceRandom2_Proxy( 
    IActMLQCPUQUSB3 __RPC_FAR * This,
    /* [in] */ VARIANT varDeviceList,
    /* [in] */ VARIANT varSize,
    /* [out] */ VARIANT __RPC_FAR *lpvarData,
    /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);


void __RPC_STUB IActMLQCPUQUSB3_ReadDeviceRandom2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActMLQCPUQUSB3_WriteDeviceRandom2_Proxy( 
    IActMLQCPUQUSB3 __RPC_FAR * This,
    /* [in] */ VARIANT varDeviceList,
    /* [in] */ VARIANT varSize,
    /* [in] */ VARIANT varData,
    /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);


void __RPC_STUB IActMLQCPUQUSB3_WriteDeviceRandom2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActMLQCPUQUSB3_GetDevice2_Proxy( 
    IActMLQCPUQUSB3 __RPC_FAR * This,
    /* [in] */ VARIANT varDevice,
    /* [out] */ VARIANT __RPC_FAR *lpvarData,
    /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);


void __RPC_STUB IActMLQCPUQUSB3_GetDevice2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActMLQCPUQUSB3_SetDevice2_Proxy( 
    IActMLQCPUQUSB3 __RPC_FAR * This,
    /* [in] */ VARIANT varDevice,
    /* [in] */ VARIANT varData,
    /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);


void __RPC_STUB IActMLQCPUQUSB3_SetDevice2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IActMLQCPUQUSB3_INTERFACE_DEFINED__ */


#ifndef __IActFXCPUUSB_INTERFACE_DEFINED__
#define __IActFXCPUUSB_INTERFACE_DEFINED__

/* interface IActFXCPUUSB */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IActFXCPUUSB;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("43620827-E04D-4BDA-9B0C-CA6C242E6546")
    IActFXCPUUSB : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Open( 
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Close( 
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetDevice( 
            /* [string][in] */ BSTR szDevice,
            /* [out] */ LONG __RPC_FAR *lpdwData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetDevice( 
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG dwData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ReadDeviceBlock( 
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG dwSize,
            /* [size_is][out] */ LONG __RPC_FAR *lpdwData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE WriteDeviceBlock( 
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG dwSize,
            /* [size_is][in] */ LONG __RPC_FAR *lpdwData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ReadDeviceRandom( 
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG dwSize,
            /* [size_is][out] */ LONG __RPC_FAR *lpdwData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE WriteDeviceRandom( 
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG dwSize,
            /* [size_is][in] */ LONG __RPC_FAR *lpdwData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ReadBuffer( 
            /* [in] */ LONG lStartIO,
            /* [in] */ LONG lAddress,
            /* [in] */ LONG lReadSize,
            /* [out] */ SHORT __RPC_FAR *lpwData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE WriteBuffer( 
            /* [in] */ LONG lStartIO,
            /* [in] */ LONG lAddress,
            /* [in] */ LONG lWriteSize,
            /* [out] */ SHORT __RPC_FAR *lpwData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetClockData( 
            /* [out] */ SHORT __RPC_FAR *lpwYear,
            /* [out] */ SHORT __RPC_FAR *lpwMonth,
            /* [out] */ SHORT __RPC_FAR *lpwDay,
            /* [out] */ SHORT __RPC_FAR *lpwDayOfWeek,
            /* [out] */ SHORT __RPC_FAR *lpwHour,
            /* [out] */ SHORT __RPC_FAR *lpwMinute,
            /* [out] */ SHORT __RPC_FAR *lpwSecond,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetClockData( 
            /* [in] */ SHORT wYear,
            /* [in] */ SHORT wMonth,
            /* [in] */ SHORT wDay,
            /* [in] */ SHORT wDayOfWeek,
            /* [in] */ SHORT wHour,
            /* [in] */ SHORT wMinute,
            /* [in] */ SHORT wSecond,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetCpuStatus( 
            /* [in] */ LONG lOperation,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetCpuType( 
            /* [string][out] */ BSTR __RPC_FAR *lpszCpuName,
            /* [out] */ LONG __RPC_FAR *lplCpuType,
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
            /* [in] */ BSTR szDevice,
            /* [in] */ SHORT sData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActCpuType( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActCpuType( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActTimeOut( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActTimeOut( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE CheckDeviceString( 
            /* [in] */ BSTR szDevice,
            /* [in] */ LONG lCheckType,
            /* [in] */ LONG lSize,
            /* [out] */ LONG __RPC_FAR *lplDeviceType,
            /* [string][out] */ BSTR __RPC_FAR *lpszDeviceName,
            /* [out] */ LONG __RPC_FAR *lplDeviceNumber,
            /* [out] */ LONG __RPC_FAR *lplDeviceRadix,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IActFXCPUUSBVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IActFXCPUUSB __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IActFXCPUUSB __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IActFXCPUUSB __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IActFXCPUUSB __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IActFXCPUUSB __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IActFXCPUUSB __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IActFXCPUUSB __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Open )( 
            IActFXCPUUSB __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Close )( 
            IActFXCPUUSB __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetDevice )( 
            IActFXCPUUSB __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [out] */ LONG __RPC_FAR *lpdwData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetDevice )( 
            IActFXCPUUSB __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG dwData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceBlock )( 
            IActFXCPUUSB __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG dwSize,
            /* [size_is][out] */ LONG __RPC_FAR *lpdwData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceBlock )( 
            IActFXCPUUSB __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG dwSize,
            /* [size_is][in] */ LONG __RPC_FAR *lpdwData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceRandom )( 
            IActFXCPUUSB __RPC_FAR * This,
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG dwSize,
            /* [size_is][out] */ LONG __RPC_FAR *lpdwData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceRandom )( 
            IActFXCPUUSB __RPC_FAR * This,
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG dwSize,
            /* [size_is][in] */ LONG __RPC_FAR *lpdwData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadBuffer )( 
            IActFXCPUUSB __RPC_FAR * This,
            /* [in] */ LONG lStartIO,
            /* [in] */ LONG lAddress,
            /* [in] */ LONG lReadSize,
            /* [out] */ SHORT __RPC_FAR *lpwData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteBuffer )( 
            IActFXCPUUSB __RPC_FAR * This,
            /* [in] */ LONG lStartIO,
            /* [in] */ LONG lAddress,
            /* [in] */ LONG lWriteSize,
            /* [out] */ SHORT __RPC_FAR *lpwData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetClockData )( 
            IActFXCPUUSB __RPC_FAR * This,
            /* [out] */ SHORT __RPC_FAR *lpwYear,
            /* [out] */ SHORT __RPC_FAR *lpwMonth,
            /* [out] */ SHORT __RPC_FAR *lpwDay,
            /* [out] */ SHORT __RPC_FAR *lpwDayOfWeek,
            /* [out] */ SHORT __RPC_FAR *lpwHour,
            /* [out] */ SHORT __RPC_FAR *lpwMinute,
            /* [out] */ SHORT __RPC_FAR *lpwSecond,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetClockData )( 
            IActFXCPUUSB __RPC_FAR * This,
            /* [in] */ SHORT wYear,
            /* [in] */ SHORT wMonth,
            /* [in] */ SHORT wDay,
            /* [in] */ SHORT wDayOfWeek,
            /* [in] */ SHORT wHour,
            /* [in] */ SHORT wMinute,
            /* [in] */ SHORT wSecond,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetCpuStatus )( 
            IActFXCPUUSB __RPC_FAR * This,
            /* [in] */ LONG lOperation,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetCpuType )( 
            IActFXCPUUSB __RPC_FAR * This,
            /* [string][out] */ BSTR __RPC_FAR *lpszCpuName,
            /* [out] */ LONG __RPC_FAR *lplCpuType,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *EntryDeviceStatus )( 
            IActFXCPUUSB __RPC_FAR * This,
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG lSize,
            /* [in] */ LONG lMonitorCycle,
            /* [size_is][in] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *FreeDeviceStatus )( 
            IActFXCPUUSB __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceBlock2 )( 
            IActFXCPUUSB __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lSize,
            /* [size_is][out] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceBlock2 )( 
            IActFXCPUUSB __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lSize,
            /* [size_is][in] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceRandom2 )( 
            IActFXCPUUSB __RPC_FAR * This,
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG lSize,
            /* [size_is][out] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceRandom2 )( 
            IActFXCPUUSB __RPC_FAR * This,
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG lSize,
            /* [size_is][in] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetDevice2 )( 
            IActFXCPUUSB __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [out] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetDevice2 )( 
            IActFXCPUUSB __RPC_FAR * This,
            /* [in] */ BSTR szDevice,
            /* [in] */ SHORT sData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActCpuType )( 
            IActFXCPUUSB __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActCpuType )( 
            IActFXCPUUSB __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActTimeOut )( 
            IActFXCPUUSB __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActTimeOut )( 
            IActFXCPUUSB __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CheckDeviceString )( 
            IActFXCPUUSB __RPC_FAR * This,
            /* [in] */ BSTR szDevice,
            /* [in] */ LONG lCheckType,
            /* [in] */ LONG lSize,
            /* [out] */ LONG __RPC_FAR *lplDeviceType,
            /* [string][out] */ BSTR __RPC_FAR *lpszDeviceName,
            /* [out] */ LONG __RPC_FAR *lplDeviceNumber,
            /* [out] */ LONG __RPC_FAR *lplDeviceRadix,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        END_INTERFACE
    } IActFXCPUUSBVtbl;

    interface IActFXCPUUSB
    {
        CONST_VTBL struct IActFXCPUUSBVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IActFXCPUUSB_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IActFXCPUUSB_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IActFXCPUUSB_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IActFXCPUUSB_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IActFXCPUUSB_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IActFXCPUUSB_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IActFXCPUUSB_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IActFXCPUUSB_Open(This,lplReturnCode)	\
    (This)->lpVtbl -> Open(This,lplReturnCode)

#define IActFXCPUUSB_Close(This,lplReturnCode)	\
    (This)->lpVtbl -> Close(This,lplReturnCode)

#define IActFXCPUUSB_GetDevice(This,szDevice,lpdwData,lplReturnCode)	\
    (This)->lpVtbl -> GetDevice(This,szDevice,lpdwData,lplReturnCode)

#define IActFXCPUUSB_SetDevice(This,szDevice,dwData,lplReturnCode)	\
    (This)->lpVtbl -> SetDevice(This,szDevice,dwData,lplReturnCode)

#define IActFXCPUUSB_ReadDeviceBlock(This,szDevice,dwSize,lpdwData,lplReturnCode)	\
    (This)->lpVtbl -> ReadDeviceBlock(This,szDevice,dwSize,lpdwData,lplReturnCode)

#define IActFXCPUUSB_WriteDeviceBlock(This,szDevice,dwSize,lpdwData,lplReturnCode)	\
    (This)->lpVtbl -> WriteDeviceBlock(This,szDevice,dwSize,lpdwData,lplReturnCode)

#define IActFXCPUUSB_ReadDeviceRandom(This,szDeviceList,dwSize,lpdwData,lplReturnCode)	\
    (This)->lpVtbl -> ReadDeviceRandom(This,szDeviceList,dwSize,lpdwData,lplReturnCode)

#define IActFXCPUUSB_WriteDeviceRandom(This,szDeviceList,dwSize,lpdwData,lplReturnCode)	\
    (This)->lpVtbl -> WriteDeviceRandom(This,szDeviceList,dwSize,lpdwData,lplReturnCode)

#define IActFXCPUUSB_ReadBuffer(This,lStartIO,lAddress,lReadSize,lpwData,lplReturnCode)	\
    (This)->lpVtbl -> ReadBuffer(This,lStartIO,lAddress,lReadSize,lpwData,lplReturnCode)

#define IActFXCPUUSB_WriteBuffer(This,lStartIO,lAddress,lWriteSize,lpwData,lplReturnCode)	\
    (This)->lpVtbl -> WriteBuffer(This,lStartIO,lAddress,lWriteSize,lpwData,lplReturnCode)

#define IActFXCPUUSB_GetClockData(This,lpwYear,lpwMonth,lpwDay,lpwDayOfWeek,lpwHour,lpwMinute,lpwSecond,lplReturnCode)	\
    (This)->lpVtbl -> GetClockData(This,lpwYear,lpwMonth,lpwDay,lpwDayOfWeek,lpwHour,lpwMinute,lpwSecond,lplReturnCode)

#define IActFXCPUUSB_SetClockData(This,wYear,wMonth,wDay,wDayOfWeek,wHour,wMinute,wSecond,lplReturnCode)	\
    (This)->lpVtbl -> SetClockData(This,wYear,wMonth,wDay,wDayOfWeek,wHour,wMinute,wSecond,lplReturnCode)

#define IActFXCPUUSB_SetCpuStatus(This,lOperation,lplReturnCode)	\
    (This)->lpVtbl -> SetCpuStatus(This,lOperation,lplReturnCode)

#define IActFXCPUUSB_GetCpuType(This,lpszCpuName,lplCpuType,lplReturnCode)	\
    (This)->lpVtbl -> GetCpuType(This,lpszCpuName,lplCpuType,lplReturnCode)

#define IActFXCPUUSB_EntryDeviceStatus(This,szDeviceList,lSize,lMonitorCycle,lplData,lplReturnCode)	\
    (This)->lpVtbl -> EntryDeviceStatus(This,szDeviceList,lSize,lMonitorCycle,lplData,lplReturnCode)

#define IActFXCPUUSB_FreeDeviceStatus(This,lplReturnCode)	\
    (This)->lpVtbl -> FreeDeviceStatus(This,lplReturnCode)

#define IActFXCPUUSB_ReadDeviceBlock2(This,szDevice,lSize,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> ReadDeviceBlock2(This,szDevice,lSize,lpsData,lplReturnCode)

#define IActFXCPUUSB_WriteDeviceBlock2(This,szDevice,lSize,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> WriteDeviceBlock2(This,szDevice,lSize,lpsData,lplReturnCode)

#define IActFXCPUUSB_ReadDeviceRandom2(This,szDeviceList,lSize,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> ReadDeviceRandom2(This,szDeviceList,lSize,lpsData,lplReturnCode)

#define IActFXCPUUSB_WriteDeviceRandom2(This,szDeviceList,lSize,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> WriteDeviceRandom2(This,szDeviceList,lSize,lpsData,lplReturnCode)

#define IActFXCPUUSB_GetDevice2(This,szDevice,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> GetDevice2(This,szDevice,lpsData,lplReturnCode)

#define IActFXCPUUSB_SetDevice2(This,szDevice,sData,lplReturnCode)	\
    (This)->lpVtbl -> SetDevice2(This,szDevice,sData,lplReturnCode)

#define IActFXCPUUSB_get_ActCpuType(This,pVal)	\
    (This)->lpVtbl -> get_ActCpuType(This,pVal)

#define IActFXCPUUSB_put_ActCpuType(This,newVal)	\
    (This)->lpVtbl -> put_ActCpuType(This,newVal)

#define IActFXCPUUSB_get_ActTimeOut(This,pVal)	\
    (This)->lpVtbl -> get_ActTimeOut(This,pVal)

#define IActFXCPUUSB_put_ActTimeOut(This,newVal)	\
    (This)->lpVtbl -> put_ActTimeOut(This,newVal)

#define IActFXCPUUSB_CheckDeviceString(This,szDevice,lCheckType,lSize,lplDeviceType,lpszDeviceName,lplDeviceNumber,lplDeviceRadix,lplReturnCode)	\
    (This)->lpVtbl -> CheckDeviceString(This,szDevice,lCheckType,lSize,lplDeviceType,lpszDeviceName,lplDeviceNumber,lplDeviceRadix,lplReturnCode)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActFXCPUUSB_Open_Proxy( 
    IActFXCPUUSB __RPC_FAR * This,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActFXCPUUSB_Open_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActFXCPUUSB_Close_Proxy( 
    IActFXCPUUSB __RPC_FAR * This,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActFXCPUUSB_Close_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActFXCPUUSB_GetDevice_Proxy( 
    IActFXCPUUSB __RPC_FAR * This,
    /* [string][in] */ BSTR szDevice,
    /* [out] */ LONG __RPC_FAR *lpdwData,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActFXCPUUSB_GetDevice_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActFXCPUUSB_SetDevice_Proxy( 
    IActFXCPUUSB __RPC_FAR * This,
    /* [string][in] */ BSTR szDevice,
    /* [in] */ LONG dwData,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActFXCPUUSB_SetDevice_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActFXCPUUSB_ReadDeviceBlock_Proxy( 
    IActFXCPUUSB __RPC_FAR * This,
    /* [string][in] */ BSTR szDevice,
    /* [in] */ LONG dwSize,
    /* [size_is][out] */ LONG __RPC_FAR *lpdwData,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActFXCPUUSB_ReadDeviceBlock_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActFXCPUUSB_WriteDeviceBlock_Proxy( 
    IActFXCPUUSB __RPC_FAR * This,
    /* [string][in] */ BSTR szDevice,
    /* [in] */ LONG dwSize,
    /* [size_is][in] */ LONG __RPC_FAR *lpdwData,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActFXCPUUSB_WriteDeviceBlock_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActFXCPUUSB_ReadDeviceRandom_Proxy( 
    IActFXCPUUSB __RPC_FAR * This,
    /* [string][in] */ BSTR szDeviceList,
    /* [in] */ LONG dwSize,
    /* [size_is][out] */ LONG __RPC_FAR *lpdwData,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActFXCPUUSB_ReadDeviceRandom_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActFXCPUUSB_WriteDeviceRandom_Proxy( 
    IActFXCPUUSB __RPC_FAR * This,
    /* [string][in] */ BSTR szDeviceList,
    /* [in] */ LONG dwSize,
    /* [size_is][in] */ LONG __RPC_FAR *lpdwData,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActFXCPUUSB_WriteDeviceRandom_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActFXCPUUSB_ReadBuffer_Proxy( 
    IActFXCPUUSB __RPC_FAR * This,
    /* [in] */ LONG lStartIO,
    /* [in] */ LONG lAddress,
    /* [in] */ LONG lReadSize,
    /* [out] */ SHORT __RPC_FAR *lpwData,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActFXCPUUSB_ReadBuffer_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActFXCPUUSB_WriteBuffer_Proxy( 
    IActFXCPUUSB __RPC_FAR * This,
    /* [in] */ LONG lStartIO,
    /* [in] */ LONG lAddress,
    /* [in] */ LONG lWriteSize,
    /* [out] */ SHORT __RPC_FAR *lpwData,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActFXCPUUSB_WriteBuffer_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActFXCPUUSB_GetClockData_Proxy( 
    IActFXCPUUSB __RPC_FAR * This,
    /* [out] */ SHORT __RPC_FAR *lpwYear,
    /* [out] */ SHORT __RPC_FAR *lpwMonth,
    /* [out] */ SHORT __RPC_FAR *lpwDay,
    /* [out] */ SHORT __RPC_FAR *lpwDayOfWeek,
    /* [out] */ SHORT __RPC_FAR *lpwHour,
    /* [out] */ SHORT __RPC_FAR *lpwMinute,
    /* [out] */ SHORT __RPC_FAR *lpwSecond,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActFXCPUUSB_GetClockData_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActFXCPUUSB_SetClockData_Proxy( 
    IActFXCPUUSB __RPC_FAR * This,
    /* [in] */ SHORT wYear,
    /* [in] */ SHORT wMonth,
    /* [in] */ SHORT wDay,
    /* [in] */ SHORT wDayOfWeek,
    /* [in] */ SHORT wHour,
    /* [in] */ SHORT wMinute,
    /* [in] */ SHORT wSecond,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActFXCPUUSB_SetClockData_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActFXCPUUSB_SetCpuStatus_Proxy( 
    IActFXCPUUSB __RPC_FAR * This,
    /* [in] */ LONG lOperation,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActFXCPUUSB_SetCpuStatus_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActFXCPUUSB_GetCpuType_Proxy( 
    IActFXCPUUSB __RPC_FAR * This,
    /* [string][out] */ BSTR __RPC_FAR *lpszCpuName,
    /* [out] */ LONG __RPC_FAR *lplCpuType,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActFXCPUUSB_GetCpuType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActFXCPUUSB_EntryDeviceStatus_Proxy( 
    IActFXCPUUSB __RPC_FAR * This,
    /* [string][in] */ BSTR szDeviceList,
    /* [in] */ LONG lSize,
    /* [in] */ LONG lMonitorCycle,
    /* [size_is][in] */ LONG __RPC_FAR *lplData,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActFXCPUUSB_EntryDeviceStatus_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActFXCPUUSB_FreeDeviceStatus_Proxy( 
    IActFXCPUUSB __RPC_FAR * This,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActFXCPUUSB_FreeDeviceStatus_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActFXCPUUSB_ReadDeviceBlock2_Proxy( 
    IActFXCPUUSB __RPC_FAR * This,
    /* [string][in] */ BSTR szDevice,
    /* [in] */ LONG lSize,
    /* [size_is][out] */ SHORT __RPC_FAR *lpsData,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActFXCPUUSB_ReadDeviceBlock2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActFXCPUUSB_WriteDeviceBlock2_Proxy( 
    IActFXCPUUSB __RPC_FAR * This,
    /* [string][in] */ BSTR szDevice,
    /* [in] */ LONG lSize,
    /* [size_is][in] */ SHORT __RPC_FAR *lpsData,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActFXCPUUSB_WriteDeviceBlock2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActFXCPUUSB_ReadDeviceRandom2_Proxy( 
    IActFXCPUUSB __RPC_FAR * This,
    /* [string][in] */ BSTR szDeviceList,
    /* [in] */ LONG lSize,
    /* [size_is][out] */ SHORT __RPC_FAR *lpsData,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActFXCPUUSB_ReadDeviceRandom2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActFXCPUUSB_WriteDeviceRandom2_Proxy( 
    IActFXCPUUSB __RPC_FAR * This,
    /* [string][in] */ BSTR szDeviceList,
    /* [in] */ LONG lSize,
    /* [size_is][in] */ SHORT __RPC_FAR *lpsData,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActFXCPUUSB_WriteDeviceRandom2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActFXCPUUSB_GetDevice2_Proxy( 
    IActFXCPUUSB __RPC_FAR * This,
    /* [string][in] */ BSTR szDevice,
    /* [out] */ SHORT __RPC_FAR *lpsData,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActFXCPUUSB_GetDevice2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActFXCPUUSB_SetDevice2_Proxy( 
    IActFXCPUUSB __RPC_FAR * This,
    /* [in] */ BSTR szDevice,
    /* [in] */ SHORT sData,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActFXCPUUSB_SetDevice2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActFXCPUUSB_get_ActCpuType_Proxy( 
    IActFXCPUUSB __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IActFXCPUUSB_get_ActCpuType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActFXCPUUSB_put_ActCpuType_Proxy( 
    IActFXCPUUSB __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB IActFXCPUUSB_put_ActCpuType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActFXCPUUSB_get_ActTimeOut_Proxy( 
    IActFXCPUUSB __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IActFXCPUUSB_get_ActTimeOut_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActFXCPUUSB_put_ActTimeOut_Proxy( 
    IActFXCPUUSB __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB IActFXCPUUSB_put_ActTimeOut_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActFXCPUUSB_CheckDeviceString_Proxy( 
    IActFXCPUUSB __RPC_FAR * This,
    /* [in] */ BSTR szDevice,
    /* [in] */ LONG lCheckType,
    /* [in] */ LONG lSize,
    /* [out] */ LONG __RPC_FAR *lplDeviceType,
    /* [string][out] */ BSTR __RPC_FAR *lpszDeviceName,
    /* [out] */ LONG __RPC_FAR *lplDeviceNumber,
    /* [out] */ LONG __RPC_FAR *lplDeviceRadix,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActFXCPUUSB_CheckDeviceString_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IActFXCPUUSB_INTERFACE_DEFINED__ */


#ifndef __IActFXCPUUSB2_INTERFACE_DEFINED__
#define __IActFXCPUUSB2_INTERFACE_DEFINED__

/* interface IActFXCPUUSB2 */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IActFXCPUUSB2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("D481165B-FBE4-41d1-B1EF-B3DA6CB018D8")
    IActFXCPUUSB2 : public IActFXCPUUSB
    {
    public:
    };
    
#else 	/* C style interface */

    typedef struct IActFXCPUUSB2Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IActFXCPUUSB2 __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IActFXCPUUSB2 __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IActFXCPUUSB2 __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IActFXCPUUSB2 __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IActFXCPUUSB2 __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IActFXCPUUSB2 __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IActFXCPUUSB2 __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Open )( 
            IActFXCPUUSB2 __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Close )( 
            IActFXCPUUSB2 __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetDevice )( 
            IActFXCPUUSB2 __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [out] */ LONG __RPC_FAR *lpdwData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetDevice )( 
            IActFXCPUUSB2 __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG dwData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceBlock )( 
            IActFXCPUUSB2 __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG dwSize,
            /* [size_is][out] */ LONG __RPC_FAR *lpdwData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceBlock )( 
            IActFXCPUUSB2 __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG dwSize,
            /* [size_is][in] */ LONG __RPC_FAR *lpdwData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceRandom )( 
            IActFXCPUUSB2 __RPC_FAR * This,
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG dwSize,
            /* [size_is][out] */ LONG __RPC_FAR *lpdwData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceRandom )( 
            IActFXCPUUSB2 __RPC_FAR * This,
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG dwSize,
            /* [size_is][in] */ LONG __RPC_FAR *lpdwData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadBuffer )( 
            IActFXCPUUSB2 __RPC_FAR * This,
            /* [in] */ LONG lStartIO,
            /* [in] */ LONG lAddress,
            /* [in] */ LONG lReadSize,
            /* [out] */ SHORT __RPC_FAR *lpwData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteBuffer )( 
            IActFXCPUUSB2 __RPC_FAR * This,
            /* [in] */ LONG lStartIO,
            /* [in] */ LONG lAddress,
            /* [in] */ LONG lWriteSize,
            /* [out] */ SHORT __RPC_FAR *lpwData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetClockData )( 
            IActFXCPUUSB2 __RPC_FAR * This,
            /* [out] */ SHORT __RPC_FAR *lpwYear,
            /* [out] */ SHORT __RPC_FAR *lpwMonth,
            /* [out] */ SHORT __RPC_FAR *lpwDay,
            /* [out] */ SHORT __RPC_FAR *lpwDayOfWeek,
            /* [out] */ SHORT __RPC_FAR *lpwHour,
            /* [out] */ SHORT __RPC_FAR *lpwMinute,
            /* [out] */ SHORT __RPC_FAR *lpwSecond,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetClockData )( 
            IActFXCPUUSB2 __RPC_FAR * This,
            /* [in] */ SHORT wYear,
            /* [in] */ SHORT wMonth,
            /* [in] */ SHORT wDay,
            /* [in] */ SHORT wDayOfWeek,
            /* [in] */ SHORT wHour,
            /* [in] */ SHORT wMinute,
            /* [in] */ SHORT wSecond,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetCpuStatus )( 
            IActFXCPUUSB2 __RPC_FAR * This,
            /* [in] */ LONG lOperation,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetCpuType )( 
            IActFXCPUUSB2 __RPC_FAR * This,
            /* [string][out] */ BSTR __RPC_FAR *lpszCpuName,
            /* [out] */ LONG __RPC_FAR *lplCpuType,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *EntryDeviceStatus )( 
            IActFXCPUUSB2 __RPC_FAR * This,
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG lSize,
            /* [in] */ LONG lMonitorCycle,
            /* [size_is][in] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *FreeDeviceStatus )( 
            IActFXCPUUSB2 __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceBlock2 )( 
            IActFXCPUUSB2 __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lSize,
            /* [size_is][out] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceBlock2 )( 
            IActFXCPUUSB2 __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lSize,
            /* [size_is][in] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceRandom2 )( 
            IActFXCPUUSB2 __RPC_FAR * This,
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG lSize,
            /* [size_is][out] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceRandom2 )( 
            IActFXCPUUSB2 __RPC_FAR * This,
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG lSize,
            /* [size_is][in] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetDevice2 )( 
            IActFXCPUUSB2 __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [out] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetDevice2 )( 
            IActFXCPUUSB2 __RPC_FAR * This,
            /* [in] */ BSTR szDevice,
            /* [in] */ SHORT sData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActCpuType )( 
            IActFXCPUUSB2 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActCpuType )( 
            IActFXCPUUSB2 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActTimeOut )( 
            IActFXCPUUSB2 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActTimeOut )( 
            IActFXCPUUSB2 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CheckDeviceString )( 
            IActFXCPUUSB2 __RPC_FAR * This,
            /* [in] */ BSTR szDevice,
            /* [in] */ LONG lCheckType,
            /* [in] */ LONG lSize,
            /* [out] */ LONG __RPC_FAR *lplDeviceType,
            /* [string][out] */ BSTR __RPC_FAR *lpszDeviceName,
            /* [out] */ LONG __RPC_FAR *lplDeviceNumber,
            /* [out] */ LONG __RPC_FAR *lplDeviceRadix,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        END_INTERFACE
    } IActFXCPUUSB2Vtbl;

    interface IActFXCPUUSB2
    {
        CONST_VTBL struct IActFXCPUUSB2Vtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IActFXCPUUSB2_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IActFXCPUUSB2_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IActFXCPUUSB2_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IActFXCPUUSB2_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IActFXCPUUSB2_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IActFXCPUUSB2_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IActFXCPUUSB2_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IActFXCPUUSB2_Open(This,lplReturnCode)	\
    (This)->lpVtbl -> Open(This,lplReturnCode)

#define IActFXCPUUSB2_Close(This,lplReturnCode)	\
    (This)->lpVtbl -> Close(This,lplReturnCode)

#define IActFXCPUUSB2_GetDevice(This,szDevice,lpdwData,lplReturnCode)	\
    (This)->lpVtbl -> GetDevice(This,szDevice,lpdwData,lplReturnCode)

#define IActFXCPUUSB2_SetDevice(This,szDevice,dwData,lplReturnCode)	\
    (This)->lpVtbl -> SetDevice(This,szDevice,dwData,lplReturnCode)

#define IActFXCPUUSB2_ReadDeviceBlock(This,szDevice,dwSize,lpdwData,lplReturnCode)	\
    (This)->lpVtbl -> ReadDeviceBlock(This,szDevice,dwSize,lpdwData,lplReturnCode)

#define IActFXCPUUSB2_WriteDeviceBlock(This,szDevice,dwSize,lpdwData,lplReturnCode)	\
    (This)->lpVtbl -> WriteDeviceBlock(This,szDevice,dwSize,lpdwData,lplReturnCode)

#define IActFXCPUUSB2_ReadDeviceRandom(This,szDeviceList,dwSize,lpdwData,lplReturnCode)	\
    (This)->lpVtbl -> ReadDeviceRandom(This,szDeviceList,dwSize,lpdwData,lplReturnCode)

#define IActFXCPUUSB2_WriteDeviceRandom(This,szDeviceList,dwSize,lpdwData,lplReturnCode)	\
    (This)->lpVtbl -> WriteDeviceRandom(This,szDeviceList,dwSize,lpdwData,lplReturnCode)

#define IActFXCPUUSB2_ReadBuffer(This,lStartIO,lAddress,lReadSize,lpwData,lplReturnCode)	\
    (This)->lpVtbl -> ReadBuffer(This,lStartIO,lAddress,lReadSize,lpwData,lplReturnCode)

#define IActFXCPUUSB2_WriteBuffer(This,lStartIO,lAddress,lWriteSize,lpwData,lplReturnCode)	\
    (This)->lpVtbl -> WriteBuffer(This,lStartIO,lAddress,lWriteSize,lpwData,lplReturnCode)

#define IActFXCPUUSB2_GetClockData(This,lpwYear,lpwMonth,lpwDay,lpwDayOfWeek,lpwHour,lpwMinute,lpwSecond,lplReturnCode)	\
    (This)->lpVtbl -> GetClockData(This,lpwYear,lpwMonth,lpwDay,lpwDayOfWeek,lpwHour,lpwMinute,lpwSecond,lplReturnCode)

#define IActFXCPUUSB2_SetClockData(This,wYear,wMonth,wDay,wDayOfWeek,wHour,wMinute,wSecond,lplReturnCode)	\
    (This)->lpVtbl -> SetClockData(This,wYear,wMonth,wDay,wDayOfWeek,wHour,wMinute,wSecond,lplReturnCode)

#define IActFXCPUUSB2_SetCpuStatus(This,lOperation,lplReturnCode)	\
    (This)->lpVtbl -> SetCpuStatus(This,lOperation,lplReturnCode)

#define IActFXCPUUSB2_GetCpuType(This,lpszCpuName,lplCpuType,lplReturnCode)	\
    (This)->lpVtbl -> GetCpuType(This,lpszCpuName,lplCpuType,lplReturnCode)

#define IActFXCPUUSB2_EntryDeviceStatus(This,szDeviceList,lSize,lMonitorCycle,lplData,lplReturnCode)	\
    (This)->lpVtbl -> EntryDeviceStatus(This,szDeviceList,lSize,lMonitorCycle,lplData,lplReturnCode)

#define IActFXCPUUSB2_FreeDeviceStatus(This,lplReturnCode)	\
    (This)->lpVtbl -> FreeDeviceStatus(This,lplReturnCode)

#define IActFXCPUUSB2_ReadDeviceBlock2(This,szDevice,lSize,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> ReadDeviceBlock2(This,szDevice,lSize,lpsData,lplReturnCode)

#define IActFXCPUUSB2_WriteDeviceBlock2(This,szDevice,lSize,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> WriteDeviceBlock2(This,szDevice,lSize,lpsData,lplReturnCode)

#define IActFXCPUUSB2_ReadDeviceRandom2(This,szDeviceList,lSize,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> ReadDeviceRandom2(This,szDeviceList,lSize,lpsData,lplReturnCode)

#define IActFXCPUUSB2_WriteDeviceRandom2(This,szDeviceList,lSize,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> WriteDeviceRandom2(This,szDeviceList,lSize,lpsData,lplReturnCode)

#define IActFXCPUUSB2_GetDevice2(This,szDevice,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> GetDevice2(This,szDevice,lpsData,lplReturnCode)

#define IActFXCPUUSB2_SetDevice2(This,szDevice,sData,lplReturnCode)	\
    (This)->lpVtbl -> SetDevice2(This,szDevice,sData,lplReturnCode)

#define IActFXCPUUSB2_get_ActCpuType(This,pVal)	\
    (This)->lpVtbl -> get_ActCpuType(This,pVal)

#define IActFXCPUUSB2_put_ActCpuType(This,newVal)	\
    (This)->lpVtbl -> put_ActCpuType(This,newVal)

#define IActFXCPUUSB2_get_ActTimeOut(This,pVal)	\
    (This)->lpVtbl -> get_ActTimeOut(This,pVal)

#define IActFXCPUUSB2_put_ActTimeOut(This,newVal)	\
    (This)->lpVtbl -> put_ActTimeOut(This,newVal)

#define IActFXCPUUSB2_CheckDeviceString(This,szDevice,lCheckType,lSize,lplDeviceType,lpszDeviceName,lplDeviceNumber,lplDeviceRadix,lplReturnCode)	\
    (This)->lpVtbl -> CheckDeviceString(This,szDevice,lCheckType,lSize,lplDeviceType,lpszDeviceName,lplDeviceNumber,lplDeviceRadix,lplReturnCode)


#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IActFXCPUUSB2_INTERFACE_DEFINED__ */


#ifndef __IActFXCPUUSB3_INTERFACE_DEFINED__
#define __IActFXCPUUSB3_INTERFACE_DEFINED__

/* interface IActFXCPUUSB3 */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IActFXCPUUSB3;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("524E1D1D-995D-401a-8C46-ED79A701B997")
    IActFXCPUUSB3 : public IActFXCPUUSB2
    {
    public:
    };
    
#else 	/* C style interface */

    typedef struct IActFXCPUUSB3Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IActFXCPUUSB3 __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IActFXCPUUSB3 __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IActFXCPUUSB3 __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IActFXCPUUSB3 __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IActFXCPUUSB3 __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IActFXCPUUSB3 __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IActFXCPUUSB3 __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Open )( 
            IActFXCPUUSB3 __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Close )( 
            IActFXCPUUSB3 __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetDevice )( 
            IActFXCPUUSB3 __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [out] */ LONG __RPC_FAR *lpdwData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetDevice )( 
            IActFXCPUUSB3 __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG dwData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceBlock )( 
            IActFXCPUUSB3 __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG dwSize,
            /* [size_is][out] */ LONG __RPC_FAR *lpdwData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceBlock )( 
            IActFXCPUUSB3 __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG dwSize,
            /* [size_is][in] */ LONG __RPC_FAR *lpdwData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceRandom )( 
            IActFXCPUUSB3 __RPC_FAR * This,
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG dwSize,
            /* [size_is][out] */ LONG __RPC_FAR *lpdwData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceRandom )( 
            IActFXCPUUSB3 __RPC_FAR * This,
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG dwSize,
            /* [size_is][in] */ LONG __RPC_FAR *lpdwData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadBuffer )( 
            IActFXCPUUSB3 __RPC_FAR * This,
            /* [in] */ LONG lStartIO,
            /* [in] */ LONG lAddress,
            /* [in] */ LONG lReadSize,
            /* [out] */ SHORT __RPC_FAR *lpwData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteBuffer )( 
            IActFXCPUUSB3 __RPC_FAR * This,
            /* [in] */ LONG lStartIO,
            /* [in] */ LONG lAddress,
            /* [in] */ LONG lWriteSize,
            /* [out] */ SHORT __RPC_FAR *lpwData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetClockData )( 
            IActFXCPUUSB3 __RPC_FAR * This,
            /* [out] */ SHORT __RPC_FAR *lpwYear,
            /* [out] */ SHORT __RPC_FAR *lpwMonth,
            /* [out] */ SHORT __RPC_FAR *lpwDay,
            /* [out] */ SHORT __RPC_FAR *lpwDayOfWeek,
            /* [out] */ SHORT __RPC_FAR *lpwHour,
            /* [out] */ SHORT __RPC_FAR *lpwMinute,
            /* [out] */ SHORT __RPC_FAR *lpwSecond,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetClockData )( 
            IActFXCPUUSB3 __RPC_FAR * This,
            /* [in] */ SHORT wYear,
            /* [in] */ SHORT wMonth,
            /* [in] */ SHORT wDay,
            /* [in] */ SHORT wDayOfWeek,
            /* [in] */ SHORT wHour,
            /* [in] */ SHORT wMinute,
            /* [in] */ SHORT wSecond,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetCpuStatus )( 
            IActFXCPUUSB3 __RPC_FAR * This,
            /* [in] */ LONG lOperation,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetCpuType )( 
            IActFXCPUUSB3 __RPC_FAR * This,
            /* [string][out] */ BSTR __RPC_FAR *lpszCpuName,
            /* [out] */ LONG __RPC_FAR *lplCpuType,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *EntryDeviceStatus )( 
            IActFXCPUUSB3 __RPC_FAR * This,
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG lSize,
            /* [in] */ LONG lMonitorCycle,
            /* [size_is][in] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *FreeDeviceStatus )( 
            IActFXCPUUSB3 __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceBlock2 )( 
            IActFXCPUUSB3 __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lSize,
            /* [size_is][out] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceBlock2 )( 
            IActFXCPUUSB3 __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lSize,
            /* [size_is][in] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceRandom2 )( 
            IActFXCPUUSB3 __RPC_FAR * This,
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG lSize,
            /* [size_is][out] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceRandom2 )( 
            IActFXCPUUSB3 __RPC_FAR * This,
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG lSize,
            /* [size_is][in] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetDevice2 )( 
            IActFXCPUUSB3 __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [out] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetDevice2 )( 
            IActFXCPUUSB3 __RPC_FAR * This,
            /* [in] */ BSTR szDevice,
            /* [in] */ SHORT sData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActCpuType )( 
            IActFXCPUUSB3 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActCpuType )( 
            IActFXCPUUSB3 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActTimeOut )( 
            IActFXCPUUSB3 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActTimeOut )( 
            IActFXCPUUSB3 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CheckDeviceString )( 
            IActFXCPUUSB3 __RPC_FAR * This,
            /* [in] */ BSTR szDevice,
            /* [in] */ LONG lCheckType,
            /* [in] */ LONG lSize,
            /* [out] */ LONG __RPC_FAR *lplDeviceType,
            /* [string][out] */ BSTR __RPC_FAR *lpszDeviceName,
            /* [out] */ LONG __RPC_FAR *lplDeviceNumber,
            /* [out] */ LONG __RPC_FAR *lplDeviceRadix,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        END_INTERFACE
    } IActFXCPUUSB3Vtbl;

    interface IActFXCPUUSB3
    {
        CONST_VTBL struct IActFXCPUUSB3Vtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IActFXCPUUSB3_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IActFXCPUUSB3_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IActFXCPUUSB3_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IActFXCPUUSB3_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IActFXCPUUSB3_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IActFXCPUUSB3_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IActFXCPUUSB3_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IActFXCPUUSB3_Open(This,lplReturnCode)	\
    (This)->lpVtbl -> Open(This,lplReturnCode)

#define IActFXCPUUSB3_Close(This,lplReturnCode)	\
    (This)->lpVtbl -> Close(This,lplReturnCode)

#define IActFXCPUUSB3_GetDevice(This,szDevice,lpdwData,lplReturnCode)	\
    (This)->lpVtbl -> GetDevice(This,szDevice,lpdwData,lplReturnCode)

#define IActFXCPUUSB3_SetDevice(This,szDevice,dwData,lplReturnCode)	\
    (This)->lpVtbl -> SetDevice(This,szDevice,dwData,lplReturnCode)

#define IActFXCPUUSB3_ReadDeviceBlock(This,szDevice,dwSize,lpdwData,lplReturnCode)	\
    (This)->lpVtbl -> ReadDeviceBlock(This,szDevice,dwSize,lpdwData,lplReturnCode)

#define IActFXCPUUSB3_WriteDeviceBlock(This,szDevice,dwSize,lpdwData,lplReturnCode)	\
    (This)->lpVtbl -> WriteDeviceBlock(This,szDevice,dwSize,lpdwData,lplReturnCode)

#define IActFXCPUUSB3_ReadDeviceRandom(This,szDeviceList,dwSize,lpdwData,lplReturnCode)	\
    (This)->lpVtbl -> ReadDeviceRandom(This,szDeviceList,dwSize,lpdwData,lplReturnCode)

#define IActFXCPUUSB3_WriteDeviceRandom(This,szDeviceList,dwSize,lpdwData,lplReturnCode)	\
    (This)->lpVtbl -> WriteDeviceRandom(This,szDeviceList,dwSize,lpdwData,lplReturnCode)

#define IActFXCPUUSB3_ReadBuffer(This,lStartIO,lAddress,lReadSize,lpwData,lplReturnCode)	\
    (This)->lpVtbl -> ReadBuffer(This,lStartIO,lAddress,lReadSize,lpwData,lplReturnCode)

#define IActFXCPUUSB3_WriteBuffer(This,lStartIO,lAddress,lWriteSize,lpwData,lplReturnCode)	\
    (This)->lpVtbl -> WriteBuffer(This,lStartIO,lAddress,lWriteSize,lpwData,lplReturnCode)

#define IActFXCPUUSB3_GetClockData(This,lpwYear,lpwMonth,lpwDay,lpwDayOfWeek,lpwHour,lpwMinute,lpwSecond,lplReturnCode)	\
    (This)->lpVtbl -> GetClockData(This,lpwYear,lpwMonth,lpwDay,lpwDayOfWeek,lpwHour,lpwMinute,lpwSecond,lplReturnCode)

#define IActFXCPUUSB3_SetClockData(This,wYear,wMonth,wDay,wDayOfWeek,wHour,wMinute,wSecond,lplReturnCode)	\
    (This)->lpVtbl -> SetClockData(This,wYear,wMonth,wDay,wDayOfWeek,wHour,wMinute,wSecond,lplReturnCode)

#define IActFXCPUUSB3_SetCpuStatus(This,lOperation,lplReturnCode)	\
    (This)->lpVtbl -> SetCpuStatus(This,lOperation,lplReturnCode)

#define IActFXCPUUSB3_GetCpuType(This,lpszCpuName,lplCpuType,lplReturnCode)	\
    (This)->lpVtbl -> GetCpuType(This,lpszCpuName,lplCpuType,lplReturnCode)

#define IActFXCPUUSB3_EntryDeviceStatus(This,szDeviceList,lSize,lMonitorCycle,lplData,lplReturnCode)	\
    (This)->lpVtbl -> EntryDeviceStatus(This,szDeviceList,lSize,lMonitorCycle,lplData,lplReturnCode)

#define IActFXCPUUSB3_FreeDeviceStatus(This,lplReturnCode)	\
    (This)->lpVtbl -> FreeDeviceStatus(This,lplReturnCode)

#define IActFXCPUUSB3_ReadDeviceBlock2(This,szDevice,lSize,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> ReadDeviceBlock2(This,szDevice,lSize,lpsData,lplReturnCode)

#define IActFXCPUUSB3_WriteDeviceBlock2(This,szDevice,lSize,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> WriteDeviceBlock2(This,szDevice,lSize,lpsData,lplReturnCode)

#define IActFXCPUUSB3_ReadDeviceRandom2(This,szDeviceList,lSize,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> ReadDeviceRandom2(This,szDeviceList,lSize,lpsData,lplReturnCode)

#define IActFXCPUUSB3_WriteDeviceRandom2(This,szDeviceList,lSize,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> WriteDeviceRandom2(This,szDeviceList,lSize,lpsData,lplReturnCode)

#define IActFXCPUUSB3_GetDevice2(This,szDevice,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> GetDevice2(This,szDevice,lpsData,lplReturnCode)

#define IActFXCPUUSB3_SetDevice2(This,szDevice,sData,lplReturnCode)	\
    (This)->lpVtbl -> SetDevice2(This,szDevice,sData,lplReturnCode)

#define IActFXCPUUSB3_get_ActCpuType(This,pVal)	\
    (This)->lpVtbl -> get_ActCpuType(This,pVal)

#define IActFXCPUUSB3_put_ActCpuType(This,newVal)	\
    (This)->lpVtbl -> put_ActCpuType(This,newVal)

#define IActFXCPUUSB3_get_ActTimeOut(This,pVal)	\
    (This)->lpVtbl -> get_ActTimeOut(This,pVal)

#define IActFXCPUUSB3_put_ActTimeOut(This,newVal)	\
    (This)->lpVtbl -> put_ActTimeOut(This,newVal)

#define IActFXCPUUSB3_CheckDeviceString(This,szDevice,lCheckType,lSize,lplDeviceType,lpszDeviceName,lplDeviceNumber,lplDeviceRadix,lplReturnCode)	\
    (This)->lpVtbl -> CheckDeviceString(This,szDevice,lCheckType,lSize,lplDeviceType,lpszDeviceName,lplDeviceNumber,lplDeviceRadix,lplReturnCode)



#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IActFXCPUUSB3_INTERFACE_DEFINED__ */


#ifndef __IActMLFXCPUUSB_INTERFACE_DEFINED__
#define __IActMLFXCPUUSB_INTERFACE_DEFINED__

/* interface IActMLFXCPUUSB */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IActMLFXCPUUSB;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("1315739A-C8C5-4867-B62F-8A8F204A2807")
    IActMLFXCPUUSB : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Open( 
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Close( 
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetDevice( 
            /* [in] */ VARIANT varDevice,
            /* [out] */ VARIANT __RPC_FAR *lpvarData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetDevice( 
            /* [in] */ VARIANT varDevice,
            /* [in] */ VARIANT varData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ReadDeviceBlock( 
            /* [in] */ VARIANT varDevice,
            /* [in] */ VARIANT varSize,
            /* [out] */ VARIANT __RPC_FAR *lpvarData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE WriteDeviceBlock( 
            /* [in] */ VARIANT varDevice,
            /* [in] */ VARIANT varSize,
            /* [in] */ VARIANT varData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ReadDeviceRandom( 
            /* [in] */ VARIANT varDeviceList,
            /* [in] */ VARIANT varSize,
            /* [out] */ VARIANT __RPC_FAR *lpvarData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE WriteDeviceRandom( 
            /* [in] */ VARIANT varDeviceList,
            /* [in] */ VARIANT varSize,
            /* [in] */ VARIANT varData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ReadBuffer( 
            /* [in] */ VARIANT varStartIO,
            /* [in] */ VARIANT varAddress,
            /* [in] */ VARIANT varReadSize,
            /* [out] */ VARIANT __RPC_FAR *lpvarData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE WriteBuffer( 
            /* [in] */ VARIANT varStartIO,
            /* [in] */ VARIANT varAddress,
            /* [in] */ VARIANT varWriteSize,
            /* [in] */ VARIANT varData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetClockData( 
            /* [out] */ VARIANT __RPC_FAR *lpvarYear,
            /* [out] */ VARIANT __RPC_FAR *lpvarMonth,
            /* [out] */ VARIANT __RPC_FAR *lpvarDay,
            /* [out] */ VARIANT __RPC_FAR *lpvarDayOfWeek,
            /* [out] */ VARIANT __RPC_FAR *lpvarHour,
            /* [out] */ VARIANT __RPC_FAR *lpvarMinute,
            /* [out] */ VARIANT __RPC_FAR *lpvarSecond,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetClockData( 
            /* [in] */ VARIANT varYear,
            /* [in] */ VARIANT varMonth,
            /* [in] */ VARIANT varDay,
            /* [in] */ VARIANT varDayOfWeek,
            /* [in] */ VARIANT varHour,
            /* [in] */ VARIANT varMinute,
            /* [in] */ VARIANT varSecond,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetCpuStatus( 
            /* [in] */ VARIANT varOperation,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetCpuType( 
            /* [out] */ VARIANT __RPC_FAR *lpvarCpuName,
            /* [out] */ VARIANT __RPC_FAR *lpvarCpuType,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE EntryDeviceStatus( 
            /* [in] */ VARIANT varDeviceList,
            /* [in] */ VARIANT varSize,
            /* [in] */ VARIANT varMonitorCycle,
            /* [in] */ VARIANT varData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE FreeDeviceStatus( 
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ReadDeviceBlock2( 
            /* [in] */ VARIANT varDevice,
            /* [in] */ VARIANT varSize,
            /* [out] */ VARIANT __RPC_FAR *lpvarData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE WriteDeviceBlock2( 
            /* [in] */ VARIANT varDevice,
            /* [in] */ VARIANT varSize,
            /* [in] */ VARIANT varData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ReadDeviceRandom2( 
            /* [in] */ VARIANT varDeviceList,
            /* [in] */ VARIANT varSize,
            /* [out] */ VARIANT __RPC_FAR *lpvarData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE WriteDeviceRandom2( 
            /* [in] */ VARIANT varDeviceList,
            /* [in] */ VARIANT varSize,
            /* [in] */ VARIANT varData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetDevice2( 
            /* [in] */ VARIANT varDevice,
            /* [out] */ VARIANT __RPC_FAR *lpvarData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetDevice2( 
            /* [in] */ VARIANT varDevice,
            /* [in] */ VARIANT varData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActCpuType( 
            /* [retval][out] */ VARIANT __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActCpuType( 
            /* [in] */ VARIANT newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActTimeOut( 
            /* [retval][out] */ VARIANT __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActTimeOut( 
            /* [in] */ VARIANT newVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IActMLFXCPUUSBVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IActMLFXCPUUSB __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IActMLFXCPUUSB __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IActMLFXCPUUSB __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IActMLFXCPUUSB __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IActMLFXCPUUSB __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IActMLFXCPUUSB __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IActMLFXCPUUSB __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Open )( 
            IActMLFXCPUUSB __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Close )( 
            IActMLFXCPUUSB __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetDevice )( 
            IActMLFXCPUUSB __RPC_FAR * This,
            /* [in] */ VARIANT varDevice,
            /* [out] */ VARIANT __RPC_FAR *lpvarData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetDevice )( 
            IActMLFXCPUUSB __RPC_FAR * This,
            /* [in] */ VARIANT varDevice,
            /* [in] */ VARIANT varData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceBlock )( 
            IActMLFXCPUUSB __RPC_FAR * This,
            /* [in] */ VARIANT varDevice,
            /* [in] */ VARIANT varSize,
            /* [out] */ VARIANT __RPC_FAR *lpvarData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceBlock )( 
            IActMLFXCPUUSB __RPC_FAR * This,
            /* [in] */ VARIANT varDevice,
            /* [in] */ VARIANT varSize,
            /* [in] */ VARIANT varData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceRandom )( 
            IActMLFXCPUUSB __RPC_FAR * This,
            /* [in] */ VARIANT varDeviceList,
            /* [in] */ VARIANT varSize,
            /* [out] */ VARIANT __RPC_FAR *lpvarData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceRandom )( 
            IActMLFXCPUUSB __RPC_FAR * This,
            /* [in] */ VARIANT varDeviceList,
            /* [in] */ VARIANT varSize,
            /* [in] */ VARIANT varData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadBuffer )( 
            IActMLFXCPUUSB __RPC_FAR * This,
            /* [in] */ VARIANT varStartIO,
            /* [in] */ VARIANT varAddress,
            /* [in] */ VARIANT varReadSize,
            /* [out] */ VARIANT __RPC_FAR *lpvarData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteBuffer )( 
            IActMLFXCPUUSB __RPC_FAR * This,
            /* [in] */ VARIANT varStartIO,
            /* [in] */ VARIANT varAddress,
            /* [in] */ VARIANT varWriteSize,
            /* [in] */ VARIANT varData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetClockData )( 
            IActMLFXCPUUSB __RPC_FAR * This,
            /* [out] */ VARIANT __RPC_FAR *lpvarYear,
            /* [out] */ VARIANT __RPC_FAR *lpvarMonth,
            /* [out] */ VARIANT __RPC_FAR *lpvarDay,
            /* [out] */ VARIANT __RPC_FAR *lpvarDayOfWeek,
            /* [out] */ VARIANT __RPC_FAR *lpvarHour,
            /* [out] */ VARIANT __RPC_FAR *lpvarMinute,
            /* [out] */ VARIANT __RPC_FAR *lpvarSecond,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetClockData )( 
            IActMLFXCPUUSB __RPC_FAR * This,
            /* [in] */ VARIANT varYear,
            /* [in] */ VARIANT varMonth,
            /* [in] */ VARIANT varDay,
            /* [in] */ VARIANT varDayOfWeek,
            /* [in] */ VARIANT varHour,
            /* [in] */ VARIANT varMinute,
            /* [in] */ VARIANT varSecond,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetCpuStatus )( 
            IActMLFXCPUUSB __RPC_FAR * This,
            /* [in] */ VARIANT varOperation,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetCpuType )( 
            IActMLFXCPUUSB __RPC_FAR * This,
            /* [out] */ VARIANT __RPC_FAR *lpvarCpuName,
            /* [out] */ VARIANT __RPC_FAR *lpvarCpuType,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *EntryDeviceStatus )( 
            IActMLFXCPUUSB __RPC_FAR * This,
            /* [in] */ VARIANT varDeviceList,
            /* [in] */ VARIANT varSize,
            /* [in] */ VARIANT varMonitorCycle,
            /* [in] */ VARIANT varData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *FreeDeviceStatus )( 
            IActMLFXCPUUSB __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceBlock2 )( 
            IActMLFXCPUUSB __RPC_FAR * This,
            /* [in] */ VARIANT varDevice,
            /* [in] */ VARIANT varSize,
            /* [out] */ VARIANT __RPC_FAR *lpvarData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceBlock2 )( 
            IActMLFXCPUUSB __RPC_FAR * This,
            /* [in] */ VARIANT varDevice,
            /* [in] */ VARIANT varSize,
            /* [in] */ VARIANT varData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceRandom2 )( 
            IActMLFXCPUUSB __RPC_FAR * This,
            /* [in] */ VARIANT varDeviceList,
            /* [in] */ VARIANT varSize,
            /* [out] */ VARIANT __RPC_FAR *lpvarData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceRandom2 )( 
            IActMLFXCPUUSB __RPC_FAR * This,
            /* [in] */ VARIANT varDeviceList,
            /* [in] */ VARIANT varSize,
            /* [in] */ VARIANT varData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetDevice2 )( 
            IActMLFXCPUUSB __RPC_FAR * This,
            /* [in] */ VARIANT varDevice,
            /* [out] */ VARIANT __RPC_FAR *lpvarData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetDevice2 )( 
            IActMLFXCPUUSB __RPC_FAR * This,
            /* [in] */ VARIANT varDevice,
            /* [in] */ VARIANT varData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActCpuType )( 
            IActMLFXCPUUSB __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActCpuType )( 
            IActMLFXCPUUSB __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActTimeOut )( 
            IActMLFXCPUUSB __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActTimeOut )( 
            IActMLFXCPUUSB __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        END_INTERFACE
    } IActMLFXCPUUSBVtbl;

    interface IActMLFXCPUUSB
    {
        CONST_VTBL struct IActMLFXCPUUSBVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IActMLFXCPUUSB_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IActMLFXCPUUSB_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IActMLFXCPUUSB_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IActMLFXCPUUSB_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IActMLFXCPUUSB_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IActMLFXCPUUSB_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IActMLFXCPUUSB_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IActMLFXCPUUSB_Open(This,lpvarReturnCode)	\
    (This)->lpVtbl -> Open(This,lpvarReturnCode)

#define IActMLFXCPUUSB_Close(This,lpvarReturnCode)	\
    (This)->lpVtbl -> Close(This,lpvarReturnCode)

#define IActMLFXCPUUSB_GetDevice(This,varDevice,lpvarData,lpvarReturnCode)	\
    (This)->lpVtbl -> GetDevice(This,varDevice,lpvarData,lpvarReturnCode)

#define IActMLFXCPUUSB_SetDevice(This,varDevice,varData,lpvarReturnCode)	\
    (This)->lpVtbl -> SetDevice(This,varDevice,varData,lpvarReturnCode)

#define IActMLFXCPUUSB_ReadDeviceBlock(This,varDevice,varSize,lpvarData,lpvarReturnCode)	\
    (This)->lpVtbl -> ReadDeviceBlock(This,varDevice,varSize,lpvarData,lpvarReturnCode)

#define IActMLFXCPUUSB_WriteDeviceBlock(This,varDevice,varSize,varData,lpvarReturnCode)	\
    (This)->lpVtbl -> WriteDeviceBlock(This,varDevice,varSize,varData,lpvarReturnCode)

#define IActMLFXCPUUSB_ReadDeviceRandom(This,varDeviceList,varSize,lpvarData,lpvarReturnCode)	\
    (This)->lpVtbl -> ReadDeviceRandom(This,varDeviceList,varSize,lpvarData,lpvarReturnCode)

#define IActMLFXCPUUSB_WriteDeviceRandom(This,varDeviceList,varSize,varData,lpvarReturnCode)	\
    (This)->lpVtbl -> WriteDeviceRandom(This,varDeviceList,varSize,varData,lpvarReturnCode)

#define IActMLFXCPUUSB_ReadBuffer(This,varStartIO,varAddress,varReadSize,lpvarData,lpvarReturnCode)	\
    (This)->lpVtbl -> ReadBuffer(This,varStartIO,varAddress,varReadSize,lpvarData,lpvarReturnCode)

#define IActMLFXCPUUSB_WriteBuffer(This,varStartIO,varAddress,varWriteSize,varData,lpvarReturnCode)	\
    (This)->lpVtbl -> WriteBuffer(This,varStartIO,varAddress,varWriteSize,varData,lpvarReturnCode)

#define IActMLFXCPUUSB_GetClockData(This,lpvarYear,lpvarMonth,lpvarDay,lpvarDayOfWeek,lpvarHour,lpvarMinute,lpvarSecond,lpvarReturnCode)	\
    (This)->lpVtbl -> GetClockData(This,lpvarYear,lpvarMonth,lpvarDay,lpvarDayOfWeek,lpvarHour,lpvarMinute,lpvarSecond,lpvarReturnCode)

#define IActMLFXCPUUSB_SetClockData(This,varYear,varMonth,varDay,varDayOfWeek,varHour,varMinute,varSecond,lpvarReturnCode)	\
    (This)->lpVtbl -> SetClockData(This,varYear,varMonth,varDay,varDayOfWeek,varHour,varMinute,varSecond,lpvarReturnCode)

#define IActMLFXCPUUSB_SetCpuStatus(This,varOperation,lpvarReturnCode)	\
    (This)->lpVtbl -> SetCpuStatus(This,varOperation,lpvarReturnCode)

#define IActMLFXCPUUSB_GetCpuType(This,lpvarCpuName,lpvarCpuType,lpvarReturnCode)	\
    (This)->lpVtbl -> GetCpuType(This,lpvarCpuName,lpvarCpuType,lpvarReturnCode)

#define IActMLFXCPUUSB_EntryDeviceStatus(This,varDeviceList,varSize,varMonitorCycle,varData,lpvarReturnCode)	\
    (This)->lpVtbl -> EntryDeviceStatus(This,varDeviceList,varSize,varMonitorCycle,varData,lpvarReturnCode)

#define IActMLFXCPUUSB_FreeDeviceStatus(This,lpvarReturnCode)	\
    (This)->lpVtbl -> FreeDeviceStatus(This,lpvarReturnCode)

#define IActMLFXCPUUSB_ReadDeviceBlock2(This,varDevice,varSize,lpvarData,lpvarReturnCode)	\
    (This)->lpVtbl -> ReadDeviceBlock2(This,varDevice,varSize,lpvarData,lpvarReturnCode)

#define IActMLFXCPUUSB_WriteDeviceBlock2(This,varDevice,varSize,varData,lpvarReturnCode)	\
    (This)->lpVtbl -> WriteDeviceBlock2(This,varDevice,varSize,varData,lpvarReturnCode)

#define IActMLFXCPUUSB_ReadDeviceRandom2(This,varDeviceList,varSize,lpvarData,lpvarReturnCode)	\
    (This)->lpVtbl -> ReadDeviceRandom2(This,varDeviceList,varSize,lpvarData,lpvarReturnCode)

#define IActMLFXCPUUSB_WriteDeviceRandom2(This,varDeviceList,varSize,varData,lpvarReturnCode)	\
    (This)->lpVtbl -> WriteDeviceRandom2(This,varDeviceList,varSize,varData,lpvarReturnCode)

#define IActMLFXCPUUSB_GetDevice2(This,varDevice,lpvarData,lpvarReturnCode)	\
    (This)->lpVtbl -> GetDevice2(This,varDevice,lpvarData,lpvarReturnCode)

#define IActMLFXCPUUSB_SetDevice2(This,varDevice,varData,lpvarReturnCode)	\
    (This)->lpVtbl -> SetDevice2(This,varDevice,varData,lpvarReturnCode)

#define IActMLFXCPUUSB_get_ActCpuType(This,pVal)	\
    (This)->lpVtbl -> get_ActCpuType(This,pVal)

#define IActMLFXCPUUSB_put_ActCpuType(This,newVal)	\
    (This)->lpVtbl -> put_ActCpuType(This,newVal)

#define IActMLFXCPUUSB_get_ActTimeOut(This,pVal)	\
    (This)->lpVtbl -> get_ActTimeOut(This,pVal)

#define IActMLFXCPUUSB_put_ActTimeOut(This,newVal)	\
    (This)->lpVtbl -> put_ActTimeOut(This,newVal)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActMLFXCPUUSB_Open_Proxy( 
    IActMLFXCPUUSB __RPC_FAR * This,
    /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);


void __RPC_STUB IActMLFXCPUUSB_Open_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActMLFXCPUUSB_Close_Proxy( 
    IActMLFXCPUUSB __RPC_FAR * This,
    /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);


void __RPC_STUB IActMLFXCPUUSB_Close_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActMLFXCPUUSB_GetDevice_Proxy( 
    IActMLFXCPUUSB __RPC_FAR * This,
    /* [in] */ VARIANT varDevice,
    /* [out] */ VARIANT __RPC_FAR *lpvarData,
    /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);


void __RPC_STUB IActMLFXCPUUSB_GetDevice_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActMLFXCPUUSB_SetDevice_Proxy( 
    IActMLFXCPUUSB __RPC_FAR * This,
    /* [in] */ VARIANT varDevice,
    /* [in] */ VARIANT varData,
    /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);


void __RPC_STUB IActMLFXCPUUSB_SetDevice_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActMLFXCPUUSB_ReadDeviceBlock_Proxy( 
    IActMLFXCPUUSB __RPC_FAR * This,
    /* [in] */ VARIANT varDevice,
    /* [in] */ VARIANT varSize,
    /* [out] */ VARIANT __RPC_FAR *lpvarData,
    /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);


void __RPC_STUB IActMLFXCPUUSB_ReadDeviceBlock_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActMLFXCPUUSB_WriteDeviceBlock_Proxy( 
    IActMLFXCPUUSB __RPC_FAR * This,
    /* [in] */ VARIANT varDevice,
    /* [in] */ VARIANT varSize,
    /* [in] */ VARIANT varData,
    /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);


void __RPC_STUB IActMLFXCPUUSB_WriteDeviceBlock_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActMLFXCPUUSB_ReadDeviceRandom_Proxy( 
    IActMLFXCPUUSB __RPC_FAR * This,
    /* [in] */ VARIANT varDeviceList,
    /* [in] */ VARIANT varSize,
    /* [out] */ VARIANT __RPC_FAR *lpvarData,
    /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);


void __RPC_STUB IActMLFXCPUUSB_ReadDeviceRandom_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActMLFXCPUUSB_WriteDeviceRandom_Proxy( 
    IActMLFXCPUUSB __RPC_FAR * This,
    /* [in] */ VARIANT varDeviceList,
    /* [in] */ VARIANT varSize,
    /* [in] */ VARIANT varData,
    /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);


void __RPC_STUB IActMLFXCPUUSB_WriteDeviceRandom_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActMLFXCPUUSB_ReadBuffer_Proxy( 
    IActMLFXCPUUSB __RPC_FAR * This,
    /* [in] */ VARIANT varStartIO,
    /* [in] */ VARIANT varAddress,
    /* [in] */ VARIANT varReadSize,
    /* [out] */ VARIANT __RPC_FAR *lpvarData,
    /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);


void __RPC_STUB IActMLFXCPUUSB_ReadBuffer_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActMLFXCPUUSB_WriteBuffer_Proxy( 
    IActMLFXCPUUSB __RPC_FAR * This,
    /* [in] */ VARIANT varStartIO,
    /* [in] */ VARIANT varAddress,
    /* [in] */ VARIANT varWriteSize,
    /* [in] */ VARIANT varData,
    /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);


void __RPC_STUB IActMLFXCPUUSB_WriteBuffer_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActMLFXCPUUSB_GetClockData_Proxy( 
    IActMLFXCPUUSB __RPC_FAR * This,
    /* [out] */ VARIANT __RPC_FAR *lpvarYear,
    /* [out] */ VARIANT __RPC_FAR *lpvarMonth,
    /* [out] */ VARIANT __RPC_FAR *lpvarDay,
    /* [out] */ VARIANT __RPC_FAR *lpvarDayOfWeek,
    /* [out] */ VARIANT __RPC_FAR *lpvarHour,
    /* [out] */ VARIANT __RPC_FAR *lpvarMinute,
    /* [out] */ VARIANT __RPC_FAR *lpvarSecond,
    /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);


void __RPC_STUB IActMLFXCPUUSB_GetClockData_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActMLFXCPUUSB_SetClockData_Proxy( 
    IActMLFXCPUUSB __RPC_FAR * This,
    /* [in] */ VARIANT varYear,
    /* [in] */ VARIANT varMonth,
    /* [in] */ VARIANT varDay,
    /* [in] */ VARIANT varDayOfWeek,
    /* [in] */ VARIANT varHour,
    /* [in] */ VARIANT varMinute,
    /* [in] */ VARIANT varSecond,
    /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);


void __RPC_STUB IActMLFXCPUUSB_SetClockData_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActMLFXCPUUSB_SetCpuStatus_Proxy( 
    IActMLFXCPUUSB __RPC_FAR * This,
    /* [in] */ VARIANT varOperation,
    /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);


void __RPC_STUB IActMLFXCPUUSB_SetCpuStatus_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActMLFXCPUUSB_GetCpuType_Proxy( 
    IActMLFXCPUUSB __RPC_FAR * This,
    /* [out] */ VARIANT __RPC_FAR *lpvarCpuName,
    /* [out] */ VARIANT __RPC_FAR *lpvarCpuType,
    /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);


void __RPC_STUB IActMLFXCPUUSB_GetCpuType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActMLFXCPUUSB_EntryDeviceStatus_Proxy( 
    IActMLFXCPUUSB __RPC_FAR * This,
    /* [in] */ VARIANT varDeviceList,
    /* [in] */ VARIANT varSize,
    /* [in] */ VARIANT varMonitorCycle,
    /* [in] */ VARIANT varData,
    /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);


void __RPC_STUB IActMLFXCPUUSB_EntryDeviceStatus_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActMLFXCPUUSB_FreeDeviceStatus_Proxy( 
    IActMLFXCPUUSB __RPC_FAR * This,
    /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);


void __RPC_STUB IActMLFXCPUUSB_FreeDeviceStatus_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActMLFXCPUUSB_ReadDeviceBlock2_Proxy( 
    IActMLFXCPUUSB __RPC_FAR * This,
    /* [in] */ VARIANT varDevice,
    /* [in] */ VARIANT varSize,
    /* [out] */ VARIANT __RPC_FAR *lpvarData,
    /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);


void __RPC_STUB IActMLFXCPUUSB_ReadDeviceBlock2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActMLFXCPUUSB_WriteDeviceBlock2_Proxy( 
    IActMLFXCPUUSB __RPC_FAR * This,
    /* [in] */ VARIANT varDevice,
    /* [in] */ VARIANT varSize,
    /* [in] */ VARIANT varData,
    /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);


void __RPC_STUB IActMLFXCPUUSB_WriteDeviceBlock2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActMLFXCPUUSB_ReadDeviceRandom2_Proxy( 
    IActMLFXCPUUSB __RPC_FAR * This,
    /* [in] */ VARIANT varDeviceList,
    /* [in] */ VARIANT varSize,
    /* [out] */ VARIANT __RPC_FAR *lpvarData,
    /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);


void __RPC_STUB IActMLFXCPUUSB_ReadDeviceRandom2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActMLFXCPUUSB_WriteDeviceRandom2_Proxy( 
    IActMLFXCPUUSB __RPC_FAR * This,
    /* [in] */ VARIANT varDeviceList,
    /* [in] */ VARIANT varSize,
    /* [in] */ VARIANT varData,
    /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);


void __RPC_STUB IActMLFXCPUUSB_WriteDeviceRandom2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActMLFXCPUUSB_GetDevice2_Proxy( 
    IActMLFXCPUUSB __RPC_FAR * This,
    /* [in] */ VARIANT varDevice,
    /* [out] */ VARIANT __RPC_FAR *lpvarData,
    /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);


void __RPC_STUB IActMLFXCPUUSB_GetDevice2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActMLFXCPUUSB_SetDevice2_Proxy( 
    IActMLFXCPUUSB __RPC_FAR * This,
    /* [in] */ VARIANT varDevice,
    /* [in] */ VARIANT varData,
    /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);


void __RPC_STUB IActMLFXCPUUSB_SetDevice2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActMLFXCPUUSB_get_ActCpuType_Proxy( 
    IActMLFXCPUUSB __RPC_FAR * This,
    /* [retval][out] */ VARIANT __RPC_FAR *pVal);


void __RPC_STUB IActMLFXCPUUSB_get_ActCpuType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActMLFXCPUUSB_put_ActCpuType_Proxy( 
    IActMLFXCPUUSB __RPC_FAR * This,
    /* [in] */ VARIANT newVal);


void __RPC_STUB IActMLFXCPUUSB_put_ActCpuType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActMLFXCPUUSB_get_ActTimeOut_Proxy( 
    IActMLFXCPUUSB __RPC_FAR * This,
    /* [retval][out] */ VARIANT __RPC_FAR *pVal);


void __RPC_STUB IActMLFXCPUUSB_get_ActTimeOut_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActMLFXCPUUSB_put_ActTimeOut_Proxy( 
    IActMLFXCPUUSB __RPC_FAR * This,
    /* [in] */ VARIANT newVal);


void __RPC_STUB IActMLFXCPUUSB_put_ActTimeOut_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IActMLFXCPUUSB_INTERFACE_DEFINED__ */


#ifndef __IActMLFXCPUUSB2_INTERFACE_DEFINED__
#define __IActMLFXCPUUSB2_INTERFACE_DEFINED__

/* interface IActMLFXCPUUSB2 */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IActMLFXCPUUSB2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("745C12FF-1695-4627-904B-FCC95F2222CF")
    IActMLFXCPUUSB2 : public IActMLFXCPUUSB
    {
    public:
    };
    
#else 	/* C style interface */

    typedef struct IActMLFXCPUUSB2Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IActMLFXCPUUSB2 __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IActMLFXCPUUSB2 __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IActMLFXCPUUSB2 __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IActMLFXCPUUSB2 __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IActMLFXCPUUSB2 __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IActMLFXCPUUSB2 __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IActMLFXCPUUSB2 __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Open )( 
            IActMLFXCPUUSB2 __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Close )( 
            IActMLFXCPUUSB2 __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetDevice )( 
            IActMLFXCPUUSB2 __RPC_FAR * This,
            /* [in] */ VARIANT varDevice,
            /* [out] */ VARIANT __RPC_FAR *lpvarData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetDevice )( 
            IActMLFXCPUUSB2 __RPC_FAR * This,
            /* [in] */ VARIANT varDevice,
            /* [in] */ VARIANT varData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceBlock )( 
            IActMLFXCPUUSB2 __RPC_FAR * This,
            /* [in] */ VARIANT varDevice,
            /* [in] */ VARIANT varSize,
            /* [out] */ VARIANT __RPC_FAR *lpvarData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceBlock )( 
            IActMLFXCPUUSB2 __RPC_FAR * This,
            /* [in] */ VARIANT varDevice,
            /* [in] */ VARIANT varSize,
            /* [in] */ VARIANT varData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceRandom )( 
            IActMLFXCPUUSB2 __RPC_FAR * This,
            /* [in] */ VARIANT varDeviceList,
            /* [in] */ VARIANT varSize,
            /* [out] */ VARIANT __RPC_FAR *lpvarData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceRandom )( 
            IActMLFXCPUUSB2 __RPC_FAR * This,
            /* [in] */ VARIANT varDeviceList,
            /* [in] */ VARIANT varSize,
            /* [in] */ VARIANT varData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadBuffer )( 
            IActMLFXCPUUSB2 __RPC_FAR * This,
            /* [in] */ VARIANT varStartIO,
            /* [in] */ VARIANT varAddress,
            /* [in] */ VARIANT varReadSize,
            /* [out] */ VARIANT __RPC_FAR *lpvarData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteBuffer )( 
            IActMLFXCPUUSB2 __RPC_FAR * This,
            /* [in] */ VARIANT varStartIO,
            /* [in] */ VARIANT varAddress,
            /* [in] */ VARIANT varWriteSize,
            /* [in] */ VARIANT varData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetClockData )( 
            IActMLFXCPUUSB2 __RPC_FAR * This,
            /* [out] */ VARIANT __RPC_FAR *lpvarYear,
            /* [out] */ VARIANT __RPC_FAR *lpvarMonth,
            /* [out] */ VARIANT __RPC_FAR *lpvarDay,
            /* [out] */ VARIANT __RPC_FAR *lpvarDayOfWeek,
            /* [out] */ VARIANT __RPC_FAR *lpvarHour,
            /* [out] */ VARIANT __RPC_FAR *lpvarMinute,
            /* [out] */ VARIANT __RPC_FAR *lpvarSecond,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetClockData )( 
            IActMLFXCPUUSB2 __RPC_FAR * This,
            /* [in] */ VARIANT varYear,
            /* [in] */ VARIANT varMonth,
            /* [in] */ VARIANT varDay,
            /* [in] */ VARIANT varDayOfWeek,
            /* [in] */ VARIANT varHour,
            /* [in] */ VARIANT varMinute,
            /* [in] */ VARIANT varSecond,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetCpuStatus )( 
            IActMLFXCPUUSB2 __RPC_FAR * This,
            /* [in] */ VARIANT varOperation,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetCpuType )( 
            IActMLFXCPUUSB2 __RPC_FAR * This,
            /* [out] */ VARIANT __RPC_FAR *lpvarCpuName,
            /* [out] */ VARIANT __RPC_FAR *lpvarCpuType,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *EntryDeviceStatus )( 
            IActMLFXCPUUSB2 __RPC_FAR * This,
            /* [in] */ VARIANT varDeviceList,
            /* [in] */ VARIANT varSize,
            /* [in] */ VARIANT varMonitorCycle,
            /* [in] */ VARIANT varData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *FreeDeviceStatus )( 
            IActMLFXCPUUSB2 __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceBlock2 )( 
            IActMLFXCPUUSB2 __RPC_FAR * This,
            /* [in] */ VARIANT varDevice,
            /* [in] */ VARIANT varSize,
            /* [out] */ VARIANT __RPC_FAR *lpvarData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceBlock2 )( 
            IActMLFXCPUUSB2 __RPC_FAR * This,
            /* [in] */ VARIANT varDevice,
            /* [in] */ VARIANT varSize,
            /* [in] */ VARIANT varData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceRandom2 )( 
            IActMLFXCPUUSB2 __RPC_FAR * This,
            /* [in] */ VARIANT varDeviceList,
            /* [in] */ VARIANT varSize,
            /* [out] */ VARIANT __RPC_FAR *lpvarData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceRandom2 )( 
            IActMLFXCPUUSB2 __RPC_FAR * This,
            /* [in] */ VARIANT varDeviceList,
            /* [in] */ VARIANT varSize,
            /* [in] */ VARIANT varData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetDevice2 )( 
            IActMLFXCPUUSB2 __RPC_FAR * This,
            /* [in] */ VARIANT varDevice,
            /* [out] */ VARIANT __RPC_FAR *lpvarData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetDevice2 )( 
            IActMLFXCPUUSB2 __RPC_FAR * This,
            /* [in] */ VARIANT varDevice,
            /* [in] */ VARIANT varData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActCpuType )( 
            IActMLFXCPUUSB2 __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActCpuType )( 
            IActMLFXCPUUSB2 __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActTimeOut )( 
            IActMLFXCPUUSB2 __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActTimeOut )( 
            IActMLFXCPUUSB2 __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        END_INTERFACE
    } IActMLFXCPUUSB2Vtbl;

    interface IActMLFXCPUUSB2
    {
        CONST_VTBL struct IActMLFXCPUUSB2Vtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IActMLFXCPUUSB2_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IActMLFXCPUUSB2_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IActMLFXCPUUSB2_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IActMLFXCPUUSB2_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IActMLFXCPUUSB2_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IActMLFXCPUUSB2_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IActMLFXCPUUSB2_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IActMLFXCPUUSB2_Open(This,lpvarReturnCode)	\
    (This)->lpVtbl -> Open(This,lpvarReturnCode)

#define IActMLFXCPUUSB2_Close(This,lpvarReturnCode)	\
    (This)->lpVtbl -> Close(This,lpvarReturnCode)

#define IActMLFXCPUUSB2_GetDevice(This,varDevice,lpvarData,lpvarReturnCode)	\
    (This)->lpVtbl -> GetDevice(This,varDevice,lpvarData,lpvarReturnCode)

#define IActMLFXCPUUSB2_SetDevice(This,varDevice,varData,lpvarReturnCode)	\
    (This)->lpVtbl -> SetDevice(This,varDevice,varData,lpvarReturnCode)

#define IActMLFXCPUUSB2_ReadDeviceBlock(This,varDevice,varSize,lpvarData,lpvarReturnCode)	\
    (This)->lpVtbl -> ReadDeviceBlock(This,varDevice,varSize,lpvarData,lpvarReturnCode)

#define IActMLFXCPUUSB2_WriteDeviceBlock(This,varDevice,varSize,varData,lpvarReturnCode)	\
    (This)->lpVtbl -> WriteDeviceBlock(This,varDevice,varSize,varData,lpvarReturnCode)

#define IActMLFXCPUUSB2_ReadDeviceRandom(This,varDeviceList,varSize,lpvarData,lpvarReturnCode)	\
    (This)->lpVtbl -> ReadDeviceRandom(This,varDeviceList,varSize,lpvarData,lpvarReturnCode)

#define IActMLFXCPUUSB2_WriteDeviceRandom(This,varDeviceList,varSize,varData,lpvarReturnCode)	\
    (This)->lpVtbl -> WriteDeviceRandom(This,varDeviceList,varSize,varData,lpvarReturnCode)

#define IActMLFXCPUUSB2_ReadBuffer(This,varStartIO,varAddress,varReadSize,lpvarData,lpvarReturnCode)	\
    (This)->lpVtbl -> ReadBuffer(This,varStartIO,varAddress,varReadSize,lpvarData,lpvarReturnCode)

#define IActMLFXCPUUSB2_WriteBuffer(This,varStartIO,varAddress,varWriteSize,varData,lpvarReturnCode)	\
    (This)->lpVtbl -> WriteBuffer(This,varStartIO,varAddress,varWriteSize,varData,lpvarReturnCode)

#define IActMLFXCPUUSB2_GetClockData(This,lpvarYear,lpvarMonth,lpvarDay,lpvarDayOfWeek,lpvarHour,lpvarMinute,lpvarSecond,lpvarReturnCode)	\
    (This)->lpVtbl -> GetClockData(This,lpvarYear,lpvarMonth,lpvarDay,lpvarDayOfWeek,lpvarHour,lpvarMinute,lpvarSecond,lpvarReturnCode)

#define IActMLFXCPUUSB2_SetClockData(This,varYear,varMonth,varDay,varDayOfWeek,varHour,varMinute,varSecond,lpvarReturnCode)	\
    (This)->lpVtbl -> SetClockData(This,varYear,varMonth,varDay,varDayOfWeek,varHour,varMinute,varSecond,lpvarReturnCode)

#define IActMLFXCPUUSB2_SetCpuStatus(This,varOperation,lpvarReturnCode)	\
    (This)->lpVtbl -> SetCpuStatus(This,varOperation,lpvarReturnCode)

#define IActMLFXCPUUSB2_GetCpuType(This,lpvarCpuName,lpvarCpuType,lpvarReturnCode)	\
    (This)->lpVtbl -> GetCpuType(This,lpvarCpuName,lpvarCpuType,lpvarReturnCode)

#define IActMLFXCPUUSB2_EntryDeviceStatus(This,varDeviceList,varSize,varMonitorCycle,varData,lpvarReturnCode)	\
    (This)->lpVtbl -> EntryDeviceStatus(This,varDeviceList,varSize,varMonitorCycle,varData,lpvarReturnCode)

#define IActMLFXCPUUSB2_FreeDeviceStatus(This,lpvarReturnCode)	\
    (This)->lpVtbl -> FreeDeviceStatus(This,lpvarReturnCode)

#define IActMLFXCPUUSB2_ReadDeviceBlock2(This,varDevice,varSize,lpvarData,lpvarReturnCode)	\
    (This)->lpVtbl -> ReadDeviceBlock2(This,varDevice,varSize,lpvarData,lpvarReturnCode)

#define IActMLFXCPUUSB2_WriteDeviceBlock2(This,varDevice,varSize,varData,lpvarReturnCode)	\
    (This)->lpVtbl -> WriteDeviceBlock2(This,varDevice,varSize,varData,lpvarReturnCode)

#define IActMLFXCPUUSB2_ReadDeviceRandom2(This,varDeviceList,varSize,lpvarData,lpvarReturnCode)	\
    (This)->lpVtbl -> ReadDeviceRandom2(This,varDeviceList,varSize,lpvarData,lpvarReturnCode)

#define IActMLFXCPUUSB2_WriteDeviceRandom2(This,varDeviceList,varSize,varData,lpvarReturnCode)	\
    (This)->lpVtbl -> WriteDeviceRandom2(This,varDeviceList,varSize,varData,lpvarReturnCode)

#define IActMLFXCPUUSB2_GetDevice2(This,varDevice,lpvarData,lpvarReturnCode)	\
    (This)->lpVtbl -> GetDevice2(This,varDevice,lpvarData,lpvarReturnCode)

#define IActMLFXCPUUSB2_SetDevice2(This,varDevice,varData,lpvarReturnCode)	\
    (This)->lpVtbl -> SetDevice2(This,varDevice,varData,lpvarReturnCode)

#define IActMLFXCPUUSB2_get_ActCpuType(This,pVal)	\
    (This)->lpVtbl -> get_ActCpuType(This,pVal)

#define IActMLFXCPUUSB2_put_ActCpuType(This,newVal)	\
    (This)->lpVtbl -> put_ActCpuType(This,newVal)

#define IActMLFXCPUUSB2_get_ActTimeOut(This,pVal)	\
    (This)->lpVtbl -> get_ActTimeOut(This,pVal)

#define IActMLFXCPUUSB2_put_ActTimeOut(This,newVal)	\
    (This)->lpVtbl -> put_ActTimeOut(This,newVal)


#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IActMLFXCPUUSB2_INTERFACE_DEFINED__ */


#ifndef __IActMLFXCPUUSB3_INTERFACE_DEFINED__
#define __IActMLFXCPUUSB3_INTERFACE_DEFINED__

/* interface IActMLFXCPUUSB3 */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IActMLFXCPUUSB3;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("BE960D4D-7F78-4d6d-AF68-6F5E6914F4BF")
    IActMLFXCPUUSB3 : public IActMLFXCPUUSB2
    {
    public:
    };
    
#else 	/* C style interface */

    typedef struct IActMLFXCPUUSB3Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IActMLFXCPUUSB3 __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IActMLFXCPUUSB3 __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IActMLFXCPUUSB3 __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IActMLFXCPUUSB3 __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IActMLFXCPUUSB3 __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IActMLFXCPUUSB3 __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IActMLFXCPUUSB3 __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Open )( 
            IActMLFXCPUUSB3 __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Close )( 
            IActMLFXCPUUSB3 __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetDevice )( 
            IActMLFXCPUUSB3 __RPC_FAR * This,
            /* [in] */ VARIANT varDevice,
            /* [out] */ VARIANT __RPC_FAR *lpvarData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetDevice )( 
            IActMLFXCPUUSB3 __RPC_FAR * This,
            /* [in] */ VARIANT varDevice,
            /* [in] */ VARIANT varData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceBlock )( 
            IActMLFXCPUUSB3 __RPC_FAR * This,
            /* [in] */ VARIANT varDevice,
            /* [in] */ VARIANT varSize,
            /* [out] */ VARIANT __RPC_FAR *lpvarData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceBlock )( 
            IActMLFXCPUUSB3 __RPC_FAR * This,
            /* [in] */ VARIANT varDevice,
            /* [in] */ VARIANT varSize,
            /* [in] */ VARIANT varData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceRandom )( 
            IActMLFXCPUUSB3 __RPC_FAR * This,
            /* [in] */ VARIANT varDeviceList,
            /* [in] */ VARIANT varSize,
            /* [out] */ VARIANT __RPC_FAR *lpvarData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceRandom )( 
            IActMLFXCPUUSB3 __RPC_FAR * This,
            /* [in] */ VARIANT varDeviceList,
            /* [in] */ VARIANT varSize,
            /* [in] */ VARIANT varData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadBuffer )( 
            IActMLFXCPUUSB3 __RPC_FAR * This,
            /* [in] */ VARIANT varStartIO,
            /* [in] */ VARIANT varAddress,
            /* [in] */ VARIANT varReadSize,
            /* [out] */ VARIANT __RPC_FAR *lpvarData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteBuffer )( 
            IActMLFXCPUUSB3 __RPC_FAR * This,
            /* [in] */ VARIANT varStartIO,
            /* [in] */ VARIANT varAddress,
            /* [in] */ VARIANT varWriteSize,
            /* [in] */ VARIANT varData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetClockData )( 
            IActMLFXCPUUSB3 __RPC_FAR * This,
            /* [out] */ VARIANT __RPC_FAR *lpvarYear,
            /* [out] */ VARIANT __RPC_FAR *lpvarMonth,
            /* [out] */ VARIANT __RPC_FAR *lpvarDay,
            /* [out] */ VARIANT __RPC_FAR *lpvarDayOfWeek,
            /* [out] */ VARIANT __RPC_FAR *lpvarHour,
            /* [out] */ VARIANT __RPC_FAR *lpvarMinute,
            /* [out] */ VARIANT __RPC_FAR *lpvarSecond,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetClockData )( 
            IActMLFXCPUUSB3 __RPC_FAR * This,
            /* [in] */ VARIANT varYear,
            /* [in] */ VARIANT varMonth,
            /* [in] */ VARIANT varDay,
            /* [in] */ VARIANT varDayOfWeek,
            /* [in] */ VARIANT varHour,
            /* [in] */ VARIANT varMinute,
            /* [in] */ VARIANT varSecond,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetCpuStatus )( 
            IActMLFXCPUUSB3 __RPC_FAR * This,
            /* [in] */ VARIANT varOperation,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetCpuType )( 
            IActMLFXCPUUSB3 __RPC_FAR * This,
            /* [out] */ VARIANT __RPC_FAR *lpvarCpuName,
            /* [out] */ VARIANT __RPC_FAR *lpvarCpuType,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *EntryDeviceStatus )( 
            IActMLFXCPUUSB3 __RPC_FAR * This,
            /* [in] */ VARIANT varDeviceList,
            /* [in] */ VARIANT varSize,
            /* [in] */ VARIANT varMonitorCycle,
            /* [in] */ VARIANT varData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *FreeDeviceStatus )( 
            IActMLFXCPUUSB3 __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceBlock2 )( 
            IActMLFXCPUUSB3 __RPC_FAR * This,
            /* [in] */ VARIANT varDevice,
            /* [in] */ VARIANT varSize,
            /* [out] */ VARIANT __RPC_FAR *lpvarData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceBlock2 )( 
            IActMLFXCPUUSB3 __RPC_FAR * This,
            /* [in] */ VARIANT varDevice,
            /* [in] */ VARIANT varSize,
            /* [in] */ VARIANT varData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceRandom2 )( 
            IActMLFXCPUUSB3 __RPC_FAR * This,
            /* [in] */ VARIANT varDeviceList,
            /* [in] */ VARIANT varSize,
            /* [out] */ VARIANT __RPC_FAR *lpvarData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceRandom2 )( 
            IActMLFXCPUUSB3 __RPC_FAR * This,
            /* [in] */ VARIANT varDeviceList,
            /* [in] */ VARIANT varSize,
            /* [in] */ VARIANT varData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetDevice2 )( 
            IActMLFXCPUUSB3 __RPC_FAR * This,
            /* [in] */ VARIANT varDevice,
            /* [out] */ VARIANT __RPC_FAR *lpvarData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetDevice2 )( 
            IActMLFXCPUUSB3 __RPC_FAR * This,
            /* [in] */ VARIANT varDevice,
            /* [in] */ VARIANT varData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActCpuType )( 
            IActMLFXCPUUSB3 __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActCpuType )( 
            IActMLFXCPUUSB3 __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActTimeOut )( 
            IActMLFXCPUUSB3 __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActTimeOut )( 
            IActMLFXCPUUSB3 __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        END_INTERFACE
    } IActMLFXCPUUSB3Vtbl;

    interface IActMLFXCPUUSB3
    {
        CONST_VTBL struct IActMLFXCPUUSB3Vtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IActMLFXCPUUSB3_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IActMLFXCPUUSB3_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IActMLFXCPUUSB3_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IActMLFXCPUUSB3_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IActMLFXCPUUSB3_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IActMLFXCPUUSB3_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IActMLFXCPUUSB3_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IActMLFXCPUUSB3_Open(This,lpvarReturnCode)	\
    (This)->lpVtbl -> Open(This,lpvarReturnCode)

#define IActMLFXCPUUSB3_Close(This,lpvarReturnCode)	\
    (This)->lpVtbl -> Close(This,lpvarReturnCode)

#define IActMLFXCPUUSB3_GetDevice(This,varDevice,lpvarData,lpvarReturnCode)	\
    (This)->lpVtbl -> GetDevice(This,varDevice,lpvarData,lpvarReturnCode)

#define IActMLFXCPUUSB3_SetDevice(This,varDevice,varData,lpvarReturnCode)	\
    (This)->lpVtbl -> SetDevice(This,varDevice,varData,lpvarReturnCode)

#define IActMLFXCPUUSB3_ReadDeviceBlock(This,varDevice,varSize,lpvarData,lpvarReturnCode)	\
    (This)->lpVtbl -> ReadDeviceBlock(This,varDevice,varSize,lpvarData,lpvarReturnCode)

#define IActMLFXCPUUSB3_WriteDeviceBlock(This,varDevice,varSize,varData,lpvarReturnCode)	\
    (This)->lpVtbl -> WriteDeviceBlock(This,varDevice,varSize,varData,lpvarReturnCode)

#define IActMLFXCPUUSB3_ReadDeviceRandom(This,varDeviceList,varSize,lpvarData,lpvarReturnCode)	\
    (This)->lpVtbl -> ReadDeviceRandom(This,varDeviceList,varSize,lpvarData,lpvarReturnCode)

#define IActMLFXCPUUSB3_WriteDeviceRandom(This,varDeviceList,varSize,varData,lpvarReturnCode)	\
    (This)->lpVtbl -> WriteDeviceRandom(This,varDeviceList,varSize,varData,lpvarReturnCode)

#define IActMLFXCPUUSB3_ReadBuffer(This,varStartIO,varAddress,varReadSize,lpvarData,lpvarReturnCode)	\
    (This)->lpVtbl -> ReadBuffer(This,varStartIO,varAddress,varReadSize,lpvarData,lpvarReturnCode)

#define IActMLFXCPUUSB3_WriteBuffer(This,varStartIO,varAddress,varWriteSize,varData,lpvarReturnCode)	\
    (This)->lpVtbl -> WriteBuffer(This,varStartIO,varAddress,varWriteSize,varData,lpvarReturnCode)

#define IActMLFXCPUUSB3_GetClockData(This,lpvarYear,lpvarMonth,lpvarDay,lpvarDayOfWeek,lpvarHour,lpvarMinute,lpvarSecond,lpvarReturnCode)	\
    (This)->lpVtbl -> GetClockData(This,lpvarYear,lpvarMonth,lpvarDay,lpvarDayOfWeek,lpvarHour,lpvarMinute,lpvarSecond,lpvarReturnCode)

#define IActMLFXCPUUSB3_SetClockData(This,varYear,varMonth,varDay,varDayOfWeek,varHour,varMinute,varSecond,lpvarReturnCode)	\
    (This)->lpVtbl -> SetClockData(This,varYear,varMonth,varDay,varDayOfWeek,varHour,varMinute,varSecond,lpvarReturnCode)

#define IActMLFXCPUUSB3_SetCpuStatus(This,varOperation,lpvarReturnCode)	\
    (This)->lpVtbl -> SetCpuStatus(This,varOperation,lpvarReturnCode)

#define IActMLFXCPUUSB3_GetCpuType(This,lpvarCpuName,lpvarCpuType,lpvarReturnCode)	\
    (This)->lpVtbl -> GetCpuType(This,lpvarCpuName,lpvarCpuType,lpvarReturnCode)

#define IActMLFXCPUUSB3_EntryDeviceStatus(This,varDeviceList,varSize,varMonitorCycle,varData,lpvarReturnCode)	\
    (This)->lpVtbl -> EntryDeviceStatus(This,varDeviceList,varSize,varMonitorCycle,varData,lpvarReturnCode)

#define IActMLFXCPUUSB3_FreeDeviceStatus(This,lpvarReturnCode)	\
    (This)->lpVtbl -> FreeDeviceStatus(This,lpvarReturnCode)

#define IActMLFXCPUUSB3_ReadDeviceBlock2(This,varDevice,varSize,lpvarData,lpvarReturnCode)	\
    (This)->lpVtbl -> ReadDeviceBlock2(This,varDevice,varSize,lpvarData,lpvarReturnCode)

#define IActMLFXCPUUSB3_WriteDeviceBlock2(This,varDevice,varSize,varData,lpvarReturnCode)	\
    (This)->lpVtbl -> WriteDeviceBlock2(This,varDevice,varSize,varData,lpvarReturnCode)

#define IActMLFXCPUUSB3_ReadDeviceRandom2(This,varDeviceList,varSize,lpvarData,lpvarReturnCode)	\
    (This)->lpVtbl -> ReadDeviceRandom2(This,varDeviceList,varSize,lpvarData,lpvarReturnCode)

#define IActMLFXCPUUSB3_WriteDeviceRandom2(This,varDeviceList,varSize,varData,lpvarReturnCode)	\
    (This)->lpVtbl -> WriteDeviceRandom2(This,varDeviceList,varSize,varData,lpvarReturnCode)

#define IActMLFXCPUUSB3_GetDevice2(This,varDevice,lpvarData,lpvarReturnCode)	\
    (This)->lpVtbl -> GetDevice2(This,varDevice,lpvarData,lpvarReturnCode)

#define IActMLFXCPUUSB3_SetDevice2(This,varDevice,varData,lpvarReturnCode)	\
    (This)->lpVtbl -> SetDevice2(This,varDevice,varData,lpvarReturnCode)

#define IActMLFXCPUUSB3_get_ActCpuType(This,pVal)	\
    (This)->lpVtbl -> get_ActCpuType(This,pVal)

#define IActMLFXCPUUSB3_put_ActCpuType(This,newVal)	\
    (This)->lpVtbl -> put_ActCpuType(This,newVal)

#define IActMLFXCPUUSB3_get_ActTimeOut(This,pVal)	\
    (This)->lpVtbl -> get_ActTimeOut(This,pVal)

#define IActMLFXCPUUSB3_put_ActTimeOut(This,newVal)	\
    (This)->lpVtbl -> put_ActTimeOut(This,newVal)



#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IActMLFXCPUUSB3_INTERFACE_DEFINED__ */


#ifndef __IActLCPUUSB_INTERFACE_DEFINED__
#define __IActLCPUUSB_INTERFACE_DEFINED__

/* interface IActLCPUUSB */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IActLCPUUSB;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("DAA1019D-6474-4BC9-B103-F9193A5D0A20")
    IActLCPUUSB : public IDispatch
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
        
    };
    
#else 	/* C style interface */

    typedef struct IActLCPUUSBVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IActLCPUUSB __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IActLCPUUSB __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IActLCPUUSB __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IActLCPUUSB __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IActLCPUUSB __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IActLCPUUSB __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IActLCPUUSB __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Open )( 
            IActLCPUUSB __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Close )( 
            IActLCPUUSB __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetDevice )( 
            IActLCPUUSB __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [out] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetDevice )( 
            IActLCPUUSB __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceBlock )( 
            IActLCPUUSB __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lSize,
            /* [size_is][out] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceBlock )( 
            IActLCPUUSB __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lSize,
            /* [size_is][in] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceRandom )( 
            IActLCPUUSB __RPC_FAR * This,
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG lSize,
            /* [size_is][out] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceRandom )( 
            IActLCPUUSB __RPC_FAR * This,
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG lSize,
            /* [size_is][in] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadBuffer )( 
            IActLCPUUSB __RPC_FAR * This,
            /* [in] */ LONG lStartIO,
            /* [in] */ LONG lAddress,
            /* [in] */ LONG lSize,
            /* [size_is][out] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteBuffer )( 
            IActLCPUUSB __RPC_FAR * This,
            /* [in] */ LONG lStartIO,
            /* [in] */ LONG lAddress,
            /* [in] */ LONG lSize,
            /* [size_is][in] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetCpuType )( 
            IActLCPUUSB __RPC_FAR * This,
            /* [string][out] */ BSTR __RPC_FAR *szCpuName,
            /* [out] */ LONG __RPC_FAR *lplCpuCode,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetCpuStatus )( 
            IActLCPUUSB __RPC_FAR * This,
            /* [in] */ LONG lOperation,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetClockData )( 
            IActLCPUUSB __RPC_FAR * This,
            /* [out] */ SHORT __RPC_FAR *lpsYear,
            /* [out] */ SHORT __RPC_FAR *lpsMonth,
            /* [out] */ SHORT __RPC_FAR *lpsDay,
            /* [out] */ SHORT __RPC_FAR *lpsDayOfWeek,
            /* [out] */ SHORT __RPC_FAR *lpsHour,
            /* [out] */ SHORT __RPC_FAR *lpsMinute,
            /* [out] */ SHORT __RPC_FAR *lpsSecond,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetClockData )( 
            IActLCPUUSB __RPC_FAR * This,
            /* [in] */ SHORT sYear,
            /* [in] */ SHORT sMonth,
            /* [in] */ SHORT sDay,
            /* [in] */ SHORT sDayOfWeek,
            /* [in] */ SHORT sHour,
            /* [in] */ SHORT sMinute,
            /* [in] */ SHORT sSecond,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *EntryDeviceStatus )( 
            IActLCPUUSB __RPC_FAR * This,
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG lSize,
            /* [in] */ LONG lMonitorCycle,
            /* [size_is][in] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CheckDeviceString )( 
            IActLCPUUSB __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lCheckType,
            /* [in] */ LONG lSize,
            /* [out] */ LONG __RPC_FAR *lplDeviceType,
            /* [string][out] */ BSTR __RPC_FAR *lpszDeviceName,
            /* [out] */ LONG __RPC_FAR *lplDeviceNumber,
            /* [out] */ LONG __RPC_FAR *lplDeviceRadix,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *FreeDeviceStatus )( 
            IActLCPUUSB __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceBlock2 )( 
            IActLCPUUSB __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lSize,
            /* [size_is][out] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceBlock2 )( 
            IActLCPUUSB __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lSize,
            /* [size_is][in] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceRandom2 )( 
            IActLCPUUSB __RPC_FAR * This,
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG lSize,
            /* [size_is][out] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceRandom2 )( 
            IActLCPUUSB __RPC_FAR * This,
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG lSize,
            /* [size_is][in] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetDevice2 )( 
            IActLCPUUSB __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [out] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetDevice2 )( 
            IActLCPUUSB __RPC_FAR * This,
            /* [in] */ BSTR szDevice,
            /* [in] */ SHORT sData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActNetworkNumber )( 
            IActLCPUUSB __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActNetworkNumber )( 
            IActLCPUUSB __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActStationNumber )( 
            IActLCPUUSB __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActStationNumber )( 
            IActLCPUUSB __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActUnitNumber )( 
            IActLCPUUSB __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActUnitNumber )( 
            IActLCPUUSB __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActIONumber )( 
            IActLCPUUSB __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActIONumber )( 
            IActLCPUUSB __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActCpuType )( 
            IActLCPUUSB __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActCpuType )( 
            IActLCPUUSB __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActTimeOut )( 
            IActLCPUUSB __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActTimeOut )( 
            IActLCPUUSB __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActDestinationIONumber )( 
            IActLCPUUSB __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActDestinationIONumber )( 
            IActLCPUUSB __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActMultiDropChannelNumber )( 
            IActLCPUUSB __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActMultiDropChannelNumber )( 
            IActLCPUUSB __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActThroughNetworkType )( 
            IActLCPUUSB __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActThroughNetworkType )( 
            IActLCPUUSB __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActIntelligentPreferenceBit )( 
            IActLCPUUSB __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActIntelligentPreferenceBit )( 
            IActLCPUUSB __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActDidPropertyBit )( 
            IActLCPUUSB __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActDidPropertyBit )( 
            IActLCPUUSB __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActDsidPropertyBit )( 
            IActLCPUUSB __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActDsidPropertyBit )( 
            IActLCPUUSB __RPC_FAR * This,
            /* [in] */ long newVal);
        
        END_INTERFACE
    } IActLCPUUSBVtbl;

    interface IActLCPUUSB
    {
        CONST_VTBL struct IActLCPUUSBVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IActLCPUUSB_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IActLCPUUSB_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IActLCPUUSB_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IActLCPUUSB_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IActLCPUUSB_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IActLCPUUSB_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IActLCPUUSB_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IActLCPUUSB_Open(This,lplReturnCode)	\
    (This)->lpVtbl -> Open(This,lplReturnCode)

#define IActLCPUUSB_Close(This,lplReturnCode)	\
    (This)->lpVtbl -> Close(This,lplReturnCode)

#define IActLCPUUSB_GetDevice(This,szDevice,lplData,lplReturnCode)	\
    (This)->lpVtbl -> GetDevice(This,szDevice,lplData,lplReturnCode)

#define IActLCPUUSB_SetDevice(This,szDevice,lData,lplReturnCode)	\
    (This)->lpVtbl -> SetDevice(This,szDevice,lData,lplReturnCode)

#define IActLCPUUSB_ReadDeviceBlock(This,szDevice,lSize,lplData,lplReturnCode)	\
    (This)->lpVtbl -> ReadDeviceBlock(This,szDevice,lSize,lplData,lplReturnCode)

#define IActLCPUUSB_WriteDeviceBlock(This,szDevice,lSize,lplData,lplReturnCode)	\
    (This)->lpVtbl -> WriteDeviceBlock(This,szDevice,lSize,lplData,lplReturnCode)

#define IActLCPUUSB_ReadDeviceRandom(This,szDeviceList,lSize,lplData,lplReturnCode)	\
    (This)->lpVtbl -> ReadDeviceRandom(This,szDeviceList,lSize,lplData,lplReturnCode)

#define IActLCPUUSB_WriteDeviceRandom(This,szDeviceList,lSize,lplData,lplReturnCode)	\
    (This)->lpVtbl -> WriteDeviceRandom(This,szDeviceList,lSize,lplData,lplReturnCode)

#define IActLCPUUSB_ReadBuffer(This,lStartIO,lAddress,lSize,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> ReadBuffer(This,lStartIO,lAddress,lSize,lpsData,lplReturnCode)

#define IActLCPUUSB_WriteBuffer(This,lStartIO,lAddress,lSize,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> WriteBuffer(This,lStartIO,lAddress,lSize,lpsData,lplReturnCode)

#define IActLCPUUSB_GetCpuType(This,szCpuName,lplCpuCode,lplReturnCode)	\
    (This)->lpVtbl -> GetCpuType(This,szCpuName,lplCpuCode,lplReturnCode)

#define IActLCPUUSB_SetCpuStatus(This,lOperation,lplReturnCode)	\
    (This)->lpVtbl -> SetCpuStatus(This,lOperation,lplReturnCode)

#define IActLCPUUSB_GetClockData(This,lpsYear,lpsMonth,lpsDay,lpsDayOfWeek,lpsHour,lpsMinute,lpsSecond,lplReturnCode)	\
    (This)->lpVtbl -> GetClockData(This,lpsYear,lpsMonth,lpsDay,lpsDayOfWeek,lpsHour,lpsMinute,lpsSecond,lplReturnCode)

#define IActLCPUUSB_SetClockData(This,sYear,sMonth,sDay,sDayOfWeek,sHour,sMinute,sSecond,lplReturnCode)	\
    (This)->lpVtbl -> SetClockData(This,sYear,sMonth,sDay,sDayOfWeek,sHour,sMinute,sSecond,lplReturnCode)

#define IActLCPUUSB_EntryDeviceStatus(This,szDeviceList,lSize,lMonitorCycle,lplData,lplReturnCode)	\
    (This)->lpVtbl -> EntryDeviceStatus(This,szDeviceList,lSize,lMonitorCycle,lplData,lplReturnCode)

#define IActLCPUUSB_CheckDeviceString(This,szDevice,lCheckType,lSize,lplDeviceType,lpszDeviceName,lplDeviceNumber,lplDeviceRadix,lplReturnCode)	\
    (This)->lpVtbl -> CheckDeviceString(This,szDevice,lCheckType,lSize,lplDeviceType,lpszDeviceName,lplDeviceNumber,lplDeviceRadix,lplReturnCode)

#define IActLCPUUSB_FreeDeviceStatus(This,lplReturnCode)	\
    (This)->lpVtbl -> FreeDeviceStatus(This,lplReturnCode)

#define IActLCPUUSB_ReadDeviceBlock2(This,szDevice,lSize,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> ReadDeviceBlock2(This,szDevice,lSize,lpsData,lplReturnCode)

#define IActLCPUUSB_WriteDeviceBlock2(This,szDevice,lSize,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> WriteDeviceBlock2(This,szDevice,lSize,lpsData,lplReturnCode)

#define IActLCPUUSB_ReadDeviceRandom2(This,szDeviceList,lSize,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> ReadDeviceRandom2(This,szDeviceList,lSize,lpsData,lplReturnCode)

#define IActLCPUUSB_WriteDeviceRandom2(This,szDeviceList,lSize,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> WriteDeviceRandom2(This,szDeviceList,lSize,lpsData,lplReturnCode)

#define IActLCPUUSB_GetDevice2(This,szDevice,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> GetDevice2(This,szDevice,lpsData,lplReturnCode)

#define IActLCPUUSB_SetDevice2(This,szDevice,sData,lplReturnCode)	\
    (This)->lpVtbl -> SetDevice2(This,szDevice,sData,lplReturnCode)

#define IActLCPUUSB_get_ActNetworkNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActNetworkNumber(This,pVal)

#define IActLCPUUSB_put_ActNetworkNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActNetworkNumber(This,newVal)

#define IActLCPUUSB_get_ActStationNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActStationNumber(This,pVal)

#define IActLCPUUSB_put_ActStationNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActStationNumber(This,newVal)

#define IActLCPUUSB_get_ActUnitNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActUnitNumber(This,pVal)

#define IActLCPUUSB_put_ActUnitNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActUnitNumber(This,newVal)

#define IActLCPUUSB_get_ActIONumber(This,pVal)	\
    (This)->lpVtbl -> get_ActIONumber(This,pVal)

#define IActLCPUUSB_put_ActIONumber(This,newVal)	\
    (This)->lpVtbl -> put_ActIONumber(This,newVal)

#define IActLCPUUSB_get_ActCpuType(This,pVal)	\
    (This)->lpVtbl -> get_ActCpuType(This,pVal)

#define IActLCPUUSB_put_ActCpuType(This,newVal)	\
    (This)->lpVtbl -> put_ActCpuType(This,newVal)

#define IActLCPUUSB_get_ActTimeOut(This,pVal)	\
    (This)->lpVtbl -> get_ActTimeOut(This,pVal)

#define IActLCPUUSB_put_ActTimeOut(This,newVal)	\
    (This)->lpVtbl -> put_ActTimeOut(This,newVal)

#define IActLCPUUSB_get_ActDestinationIONumber(This,pVal)	\
    (This)->lpVtbl -> get_ActDestinationIONumber(This,pVal)

#define IActLCPUUSB_put_ActDestinationIONumber(This,newVal)	\
    (This)->lpVtbl -> put_ActDestinationIONumber(This,newVal)

#define IActLCPUUSB_get_ActMultiDropChannelNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActMultiDropChannelNumber(This,pVal)

#define IActLCPUUSB_put_ActMultiDropChannelNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActMultiDropChannelNumber(This,newVal)

#define IActLCPUUSB_get_ActThroughNetworkType(This,pVal)	\
    (This)->lpVtbl -> get_ActThroughNetworkType(This,pVal)

#define IActLCPUUSB_put_ActThroughNetworkType(This,newVal)	\
    (This)->lpVtbl -> put_ActThroughNetworkType(This,newVal)

#define IActLCPUUSB_get_ActIntelligentPreferenceBit(This,pVal)	\
    (This)->lpVtbl -> get_ActIntelligentPreferenceBit(This,pVal)

#define IActLCPUUSB_put_ActIntelligentPreferenceBit(This,newVal)	\
    (This)->lpVtbl -> put_ActIntelligentPreferenceBit(This,newVal)

#define IActLCPUUSB_get_ActDidPropertyBit(This,pVal)	\
    (This)->lpVtbl -> get_ActDidPropertyBit(This,pVal)

#define IActLCPUUSB_put_ActDidPropertyBit(This,newVal)	\
    (This)->lpVtbl -> put_ActDidPropertyBit(This,newVal)

#define IActLCPUUSB_get_ActDsidPropertyBit(This,pVal)	\
    (This)->lpVtbl -> get_ActDsidPropertyBit(This,pVal)

#define IActLCPUUSB_put_ActDsidPropertyBit(This,newVal)	\
    (This)->lpVtbl -> put_ActDsidPropertyBit(This,newVal)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActLCPUUSB_Open_Proxy( 
    IActLCPUUSB __RPC_FAR * This,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActLCPUUSB_Open_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActLCPUUSB_Close_Proxy( 
    IActLCPUUSB __RPC_FAR * This,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActLCPUUSB_Close_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActLCPUUSB_GetDevice_Proxy( 
    IActLCPUUSB __RPC_FAR * This,
    /* [string][in] */ BSTR szDevice,
    /* [out] */ LONG __RPC_FAR *lplData,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActLCPUUSB_GetDevice_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActLCPUUSB_SetDevice_Proxy( 
    IActLCPUUSB __RPC_FAR * This,
    /* [string][in] */ BSTR szDevice,
    /* [in] */ LONG lData,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActLCPUUSB_SetDevice_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActLCPUUSB_ReadDeviceBlock_Proxy( 
    IActLCPUUSB __RPC_FAR * This,
    /* [string][in] */ BSTR szDevice,
    /* [in] */ LONG lSize,
    /* [size_is][out] */ LONG __RPC_FAR *lplData,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActLCPUUSB_ReadDeviceBlock_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActLCPUUSB_WriteDeviceBlock_Proxy( 
    IActLCPUUSB __RPC_FAR * This,
    /* [string][in] */ BSTR szDevice,
    /* [in] */ LONG lSize,
    /* [size_is][in] */ LONG __RPC_FAR *lplData,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActLCPUUSB_WriteDeviceBlock_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActLCPUUSB_ReadDeviceRandom_Proxy( 
    IActLCPUUSB __RPC_FAR * This,
    /* [string][in] */ BSTR szDeviceList,
    /* [in] */ LONG lSize,
    /* [size_is][out] */ LONG __RPC_FAR *lplData,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActLCPUUSB_ReadDeviceRandom_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActLCPUUSB_WriteDeviceRandom_Proxy( 
    IActLCPUUSB __RPC_FAR * This,
    /* [string][in] */ BSTR szDeviceList,
    /* [in] */ LONG lSize,
    /* [size_is][in] */ LONG __RPC_FAR *lplData,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActLCPUUSB_WriteDeviceRandom_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActLCPUUSB_ReadBuffer_Proxy( 
    IActLCPUUSB __RPC_FAR * This,
    /* [in] */ LONG lStartIO,
    /* [in] */ LONG lAddress,
    /* [in] */ LONG lSize,
    /* [size_is][out] */ SHORT __RPC_FAR *lpsData,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActLCPUUSB_ReadBuffer_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActLCPUUSB_WriteBuffer_Proxy( 
    IActLCPUUSB __RPC_FAR * This,
    /* [in] */ LONG lStartIO,
    /* [in] */ LONG lAddress,
    /* [in] */ LONG lSize,
    /* [size_is][in] */ SHORT __RPC_FAR *lpsData,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActLCPUUSB_WriteBuffer_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActLCPUUSB_GetCpuType_Proxy( 
    IActLCPUUSB __RPC_FAR * This,
    /* [string][out] */ BSTR __RPC_FAR *szCpuName,
    /* [out] */ LONG __RPC_FAR *lplCpuCode,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActLCPUUSB_GetCpuType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActLCPUUSB_SetCpuStatus_Proxy( 
    IActLCPUUSB __RPC_FAR * This,
    /* [in] */ LONG lOperation,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActLCPUUSB_SetCpuStatus_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActLCPUUSB_GetClockData_Proxy( 
    IActLCPUUSB __RPC_FAR * This,
    /* [out] */ SHORT __RPC_FAR *lpsYear,
    /* [out] */ SHORT __RPC_FAR *lpsMonth,
    /* [out] */ SHORT __RPC_FAR *lpsDay,
    /* [out] */ SHORT __RPC_FAR *lpsDayOfWeek,
    /* [out] */ SHORT __RPC_FAR *lpsHour,
    /* [out] */ SHORT __RPC_FAR *lpsMinute,
    /* [out] */ SHORT __RPC_FAR *lpsSecond,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActLCPUUSB_GetClockData_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActLCPUUSB_SetClockData_Proxy( 
    IActLCPUUSB __RPC_FAR * This,
    /* [in] */ SHORT sYear,
    /* [in] */ SHORT sMonth,
    /* [in] */ SHORT sDay,
    /* [in] */ SHORT sDayOfWeek,
    /* [in] */ SHORT sHour,
    /* [in] */ SHORT sMinute,
    /* [in] */ SHORT sSecond,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActLCPUUSB_SetClockData_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActLCPUUSB_EntryDeviceStatus_Proxy( 
    IActLCPUUSB __RPC_FAR * This,
    /* [string][in] */ BSTR szDeviceList,
    /* [in] */ LONG lSize,
    /* [in] */ LONG lMonitorCycle,
    /* [size_is][in] */ LONG __RPC_FAR *lplData,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActLCPUUSB_EntryDeviceStatus_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActLCPUUSB_CheckDeviceString_Proxy( 
    IActLCPUUSB __RPC_FAR * This,
    /* [string][in] */ BSTR szDevice,
    /* [in] */ LONG lCheckType,
    /* [in] */ LONG lSize,
    /* [out] */ LONG __RPC_FAR *lplDeviceType,
    /* [string][out] */ BSTR __RPC_FAR *lpszDeviceName,
    /* [out] */ LONG __RPC_FAR *lplDeviceNumber,
    /* [out] */ LONG __RPC_FAR *lplDeviceRadix,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActLCPUUSB_CheckDeviceString_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActLCPUUSB_FreeDeviceStatus_Proxy( 
    IActLCPUUSB __RPC_FAR * This,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActLCPUUSB_FreeDeviceStatus_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActLCPUUSB_ReadDeviceBlock2_Proxy( 
    IActLCPUUSB __RPC_FAR * This,
    /* [string][in] */ BSTR szDevice,
    /* [in] */ LONG lSize,
    /* [size_is][out] */ SHORT __RPC_FAR *lpsData,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActLCPUUSB_ReadDeviceBlock2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActLCPUUSB_WriteDeviceBlock2_Proxy( 
    IActLCPUUSB __RPC_FAR * This,
    /* [string][in] */ BSTR szDevice,
    /* [in] */ LONG lSize,
    /* [size_is][in] */ SHORT __RPC_FAR *lpsData,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActLCPUUSB_WriteDeviceBlock2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActLCPUUSB_ReadDeviceRandom2_Proxy( 
    IActLCPUUSB __RPC_FAR * This,
    /* [string][in] */ BSTR szDeviceList,
    /* [in] */ LONG lSize,
    /* [size_is][out] */ SHORT __RPC_FAR *lpsData,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActLCPUUSB_ReadDeviceRandom2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActLCPUUSB_WriteDeviceRandom2_Proxy( 
    IActLCPUUSB __RPC_FAR * This,
    /* [string][in] */ BSTR szDeviceList,
    /* [in] */ LONG lSize,
    /* [size_is][in] */ SHORT __RPC_FAR *lpsData,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActLCPUUSB_WriteDeviceRandom2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActLCPUUSB_GetDevice2_Proxy( 
    IActLCPUUSB __RPC_FAR * This,
    /* [string][in] */ BSTR szDevice,
    /* [out] */ SHORT __RPC_FAR *lpsData,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActLCPUUSB_GetDevice2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActLCPUUSB_SetDevice2_Proxy( 
    IActLCPUUSB __RPC_FAR * This,
    /* [in] */ BSTR szDevice,
    /* [in] */ SHORT sData,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActLCPUUSB_SetDevice2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActLCPUUSB_get_ActNetworkNumber_Proxy( 
    IActLCPUUSB __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IActLCPUUSB_get_ActNetworkNumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActLCPUUSB_put_ActNetworkNumber_Proxy( 
    IActLCPUUSB __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB IActLCPUUSB_put_ActNetworkNumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActLCPUUSB_get_ActStationNumber_Proxy( 
    IActLCPUUSB __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IActLCPUUSB_get_ActStationNumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActLCPUUSB_put_ActStationNumber_Proxy( 
    IActLCPUUSB __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB IActLCPUUSB_put_ActStationNumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActLCPUUSB_get_ActUnitNumber_Proxy( 
    IActLCPUUSB __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IActLCPUUSB_get_ActUnitNumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActLCPUUSB_put_ActUnitNumber_Proxy( 
    IActLCPUUSB __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB IActLCPUUSB_put_ActUnitNumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActLCPUUSB_get_ActIONumber_Proxy( 
    IActLCPUUSB __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IActLCPUUSB_get_ActIONumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActLCPUUSB_put_ActIONumber_Proxy( 
    IActLCPUUSB __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB IActLCPUUSB_put_ActIONumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActLCPUUSB_get_ActCpuType_Proxy( 
    IActLCPUUSB __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IActLCPUUSB_get_ActCpuType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActLCPUUSB_put_ActCpuType_Proxy( 
    IActLCPUUSB __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB IActLCPUUSB_put_ActCpuType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActLCPUUSB_get_ActTimeOut_Proxy( 
    IActLCPUUSB __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IActLCPUUSB_get_ActTimeOut_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActLCPUUSB_put_ActTimeOut_Proxy( 
    IActLCPUUSB __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB IActLCPUUSB_put_ActTimeOut_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActLCPUUSB_get_ActDestinationIONumber_Proxy( 
    IActLCPUUSB __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IActLCPUUSB_get_ActDestinationIONumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActLCPUUSB_put_ActDestinationIONumber_Proxy( 
    IActLCPUUSB __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB IActLCPUUSB_put_ActDestinationIONumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActLCPUUSB_get_ActMultiDropChannelNumber_Proxy( 
    IActLCPUUSB __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IActLCPUUSB_get_ActMultiDropChannelNumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActLCPUUSB_put_ActMultiDropChannelNumber_Proxy( 
    IActLCPUUSB __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB IActLCPUUSB_put_ActMultiDropChannelNumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActLCPUUSB_get_ActThroughNetworkType_Proxy( 
    IActLCPUUSB __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IActLCPUUSB_get_ActThroughNetworkType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActLCPUUSB_put_ActThroughNetworkType_Proxy( 
    IActLCPUUSB __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB IActLCPUUSB_put_ActThroughNetworkType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActLCPUUSB_get_ActIntelligentPreferenceBit_Proxy( 
    IActLCPUUSB __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IActLCPUUSB_get_ActIntelligentPreferenceBit_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActLCPUUSB_put_ActIntelligentPreferenceBit_Proxy( 
    IActLCPUUSB __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB IActLCPUUSB_put_ActIntelligentPreferenceBit_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActLCPUUSB_get_ActDidPropertyBit_Proxy( 
    IActLCPUUSB __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IActLCPUUSB_get_ActDidPropertyBit_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActLCPUUSB_put_ActDidPropertyBit_Proxy( 
    IActLCPUUSB __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB IActLCPUUSB_put_ActDidPropertyBit_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActLCPUUSB_get_ActDsidPropertyBit_Proxy( 
    IActLCPUUSB __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IActLCPUUSB_get_ActDsidPropertyBit_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActLCPUUSB_put_ActDsidPropertyBit_Proxy( 
    IActLCPUUSB __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB IActLCPUUSB_put_ActDsidPropertyBit_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IActLCPUUSB_INTERFACE_DEFINED__ */


#ifndef __IActLCPUUSB2_INTERFACE_DEFINED__
#define __IActLCPUUSB2_INTERFACE_DEFINED__

/* interface IActLCPUUSB2 */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IActLCPUUSB2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("C7BCF733-1758-46b2-9861-D48753C61B0E")
    IActLCPUUSB2 : public IActLCPUUSB
    {
    public:
    };
    
#else 	/* C style interface */

    typedef struct IActLCPUUSB2Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IActLCPUUSB2 __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IActLCPUUSB2 __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IActLCPUUSB2 __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IActLCPUUSB2 __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IActLCPUUSB2 __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IActLCPUUSB2 __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IActLCPUUSB2 __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Open )( 
            IActLCPUUSB2 __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Close )( 
            IActLCPUUSB2 __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetDevice )( 
            IActLCPUUSB2 __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [out] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetDevice )( 
            IActLCPUUSB2 __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceBlock )( 
            IActLCPUUSB2 __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lSize,
            /* [size_is][out] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceBlock )( 
            IActLCPUUSB2 __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lSize,
            /* [size_is][in] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceRandom )( 
            IActLCPUUSB2 __RPC_FAR * This,
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG lSize,
            /* [size_is][out] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceRandom )( 
            IActLCPUUSB2 __RPC_FAR * This,
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG lSize,
            /* [size_is][in] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadBuffer )( 
            IActLCPUUSB2 __RPC_FAR * This,
            /* [in] */ LONG lStartIO,
            /* [in] */ LONG lAddress,
            /* [in] */ LONG lSize,
            /* [size_is][out] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteBuffer )( 
            IActLCPUUSB2 __RPC_FAR * This,
            /* [in] */ LONG lStartIO,
            /* [in] */ LONG lAddress,
            /* [in] */ LONG lSize,
            /* [size_is][in] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetCpuType )( 
            IActLCPUUSB2 __RPC_FAR * This,
            /* [string][out] */ BSTR __RPC_FAR *szCpuName,
            /* [out] */ LONG __RPC_FAR *lplCpuCode,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetCpuStatus )( 
            IActLCPUUSB2 __RPC_FAR * This,
            /* [in] */ LONG lOperation,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetClockData )( 
            IActLCPUUSB2 __RPC_FAR * This,
            /* [out] */ SHORT __RPC_FAR *lpsYear,
            /* [out] */ SHORT __RPC_FAR *lpsMonth,
            /* [out] */ SHORT __RPC_FAR *lpsDay,
            /* [out] */ SHORT __RPC_FAR *lpsDayOfWeek,
            /* [out] */ SHORT __RPC_FAR *lpsHour,
            /* [out] */ SHORT __RPC_FAR *lpsMinute,
            /* [out] */ SHORT __RPC_FAR *lpsSecond,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetClockData )( 
            IActLCPUUSB2 __RPC_FAR * This,
            /* [in] */ SHORT sYear,
            /* [in] */ SHORT sMonth,
            /* [in] */ SHORT sDay,
            /* [in] */ SHORT sDayOfWeek,
            /* [in] */ SHORT sHour,
            /* [in] */ SHORT sMinute,
            /* [in] */ SHORT sSecond,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *EntryDeviceStatus )( 
            IActLCPUUSB2 __RPC_FAR * This,
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG lSize,
            /* [in] */ LONG lMonitorCycle,
            /* [size_is][in] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CheckDeviceString )( 
            IActLCPUUSB2 __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lCheckType,
            /* [in] */ LONG lSize,
            /* [out] */ LONG __RPC_FAR *lplDeviceType,
            /* [string][out] */ BSTR __RPC_FAR *lpszDeviceName,
            /* [out] */ LONG __RPC_FAR *lplDeviceNumber,
            /* [out] */ LONG __RPC_FAR *lplDeviceRadix,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *FreeDeviceStatus )( 
            IActLCPUUSB2 __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceBlock2 )( 
            IActLCPUUSB2 __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lSize,
            /* [size_is][out] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceBlock2 )( 
            IActLCPUUSB2 __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lSize,
            /* [size_is][in] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceRandom2 )( 
            IActLCPUUSB2 __RPC_FAR * This,
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG lSize,
            /* [size_is][out] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceRandom2 )( 
            IActLCPUUSB2 __RPC_FAR * This,
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG lSize,
            /* [size_is][in] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetDevice2 )( 
            IActLCPUUSB2 __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [out] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetDevice2 )( 
            IActLCPUUSB2 __RPC_FAR * This,
            /* [in] */ BSTR szDevice,
            /* [in] */ SHORT sData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActNetworkNumber )( 
            IActLCPUUSB2 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActNetworkNumber )( 
            IActLCPUUSB2 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActStationNumber )( 
            IActLCPUUSB2 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActStationNumber )( 
            IActLCPUUSB2 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActUnitNumber )( 
            IActLCPUUSB2 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActUnitNumber )( 
            IActLCPUUSB2 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActIONumber )( 
            IActLCPUUSB2 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActIONumber )( 
            IActLCPUUSB2 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActCpuType )( 
            IActLCPUUSB2 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActCpuType )( 
            IActLCPUUSB2 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActTimeOut )( 
            IActLCPUUSB2 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActTimeOut )( 
            IActLCPUUSB2 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActDestinationIONumber )( 
            IActLCPUUSB2 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActDestinationIONumber )( 
            IActLCPUUSB2 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActMultiDropChannelNumber )( 
            IActLCPUUSB2 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActMultiDropChannelNumber )( 
            IActLCPUUSB2 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActThroughNetworkType )( 
            IActLCPUUSB2 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActThroughNetworkType )( 
            IActLCPUUSB2 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActIntelligentPreferenceBit )( 
            IActLCPUUSB2 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActIntelligentPreferenceBit )( 
            IActLCPUUSB2 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActDidPropertyBit )( 
            IActLCPUUSB2 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActDidPropertyBit )( 
            IActLCPUUSB2 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActDsidPropertyBit )( 
            IActLCPUUSB2 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActDsidPropertyBit )( 
            IActLCPUUSB2 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        END_INTERFACE
    } IActLCPUUSB2Vtbl;

    interface IActLCPUUSB2
    {
        CONST_VTBL struct IActLCPUUSB2Vtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IActLCPUUSB2_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IActLCPUUSB2_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IActLCPUUSB2_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IActLCPUUSB2_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IActLCPUUSB2_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IActLCPUUSB2_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IActLCPUUSB2_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IActLCPUUSB2_Open(This,lplReturnCode)	\
    (This)->lpVtbl -> Open(This,lplReturnCode)

#define IActLCPUUSB2_Close(This,lplReturnCode)	\
    (This)->lpVtbl -> Close(This,lplReturnCode)

#define IActLCPUUSB2_GetDevice(This,szDevice,lplData,lplReturnCode)	\
    (This)->lpVtbl -> GetDevice(This,szDevice,lplData,lplReturnCode)

#define IActLCPUUSB2_SetDevice(This,szDevice,lData,lplReturnCode)	\
    (This)->lpVtbl -> SetDevice(This,szDevice,lData,lplReturnCode)

#define IActLCPUUSB2_ReadDeviceBlock(This,szDevice,lSize,lplData,lplReturnCode)	\
    (This)->lpVtbl -> ReadDeviceBlock(This,szDevice,lSize,lplData,lplReturnCode)

#define IActLCPUUSB2_WriteDeviceBlock(This,szDevice,lSize,lplData,lplReturnCode)	\
    (This)->lpVtbl -> WriteDeviceBlock(This,szDevice,lSize,lplData,lplReturnCode)

#define IActLCPUUSB2_ReadDeviceRandom(This,szDeviceList,lSize,lplData,lplReturnCode)	\
    (This)->lpVtbl -> ReadDeviceRandom(This,szDeviceList,lSize,lplData,lplReturnCode)

#define IActLCPUUSB2_WriteDeviceRandom(This,szDeviceList,lSize,lplData,lplReturnCode)	\
    (This)->lpVtbl -> WriteDeviceRandom(This,szDeviceList,lSize,lplData,lplReturnCode)

#define IActLCPUUSB2_ReadBuffer(This,lStartIO,lAddress,lSize,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> ReadBuffer(This,lStartIO,lAddress,lSize,lpsData,lplReturnCode)

#define IActLCPUUSB2_WriteBuffer(This,lStartIO,lAddress,lSize,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> WriteBuffer(This,lStartIO,lAddress,lSize,lpsData,lplReturnCode)

#define IActLCPUUSB2_GetCpuType(This,szCpuName,lplCpuCode,lplReturnCode)	\
    (This)->lpVtbl -> GetCpuType(This,szCpuName,lplCpuCode,lplReturnCode)

#define IActLCPUUSB2_SetCpuStatus(This,lOperation,lplReturnCode)	\
    (This)->lpVtbl -> SetCpuStatus(This,lOperation,lplReturnCode)

#define IActLCPUUSB2_GetClockData(This,lpsYear,lpsMonth,lpsDay,lpsDayOfWeek,lpsHour,lpsMinute,lpsSecond,lplReturnCode)	\
    (This)->lpVtbl -> GetClockData(This,lpsYear,lpsMonth,lpsDay,lpsDayOfWeek,lpsHour,lpsMinute,lpsSecond,lplReturnCode)

#define IActLCPUUSB2_SetClockData(This,sYear,sMonth,sDay,sDayOfWeek,sHour,sMinute,sSecond,lplReturnCode)	\
    (This)->lpVtbl -> SetClockData(This,sYear,sMonth,sDay,sDayOfWeek,sHour,sMinute,sSecond,lplReturnCode)

#define IActLCPUUSB2_EntryDeviceStatus(This,szDeviceList,lSize,lMonitorCycle,lplData,lplReturnCode)	\
    (This)->lpVtbl -> EntryDeviceStatus(This,szDeviceList,lSize,lMonitorCycle,lplData,lplReturnCode)

#define IActLCPUUSB2_CheckDeviceString(This,szDevice,lCheckType,lSize,lplDeviceType,lpszDeviceName,lplDeviceNumber,lplDeviceRadix,lplReturnCode)	\
    (This)->lpVtbl -> CheckDeviceString(This,szDevice,lCheckType,lSize,lplDeviceType,lpszDeviceName,lplDeviceNumber,lplDeviceRadix,lplReturnCode)

#define IActLCPUUSB2_FreeDeviceStatus(This,lplReturnCode)	\
    (This)->lpVtbl -> FreeDeviceStatus(This,lplReturnCode)

#define IActLCPUUSB2_ReadDeviceBlock2(This,szDevice,lSize,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> ReadDeviceBlock2(This,szDevice,lSize,lpsData,lplReturnCode)

#define IActLCPUUSB2_WriteDeviceBlock2(This,szDevice,lSize,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> WriteDeviceBlock2(This,szDevice,lSize,lpsData,lplReturnCode)

#define IActLCPUUSB2_ReadDeviceRandom2(This,szDeviceList,lSize,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> ReadDeviceRandom2(This,szDeviceList,lSize,lpsData,lplReturnCode)

#define IActLCPUUSB2_WriteDeviceRandom2(This,szDeviceList,lSize,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> WriteDeviceRandom2(This,szDeviceList,lSize,lpsData,lplReturnCode)

#define IActLCPUUSB2_GetDevice2(This,szDevice,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> GetDevice2(This,szDevice,lpsData,lplReturnCode)

#define IActLCPUUSB2_SetDevice2(This,szDevice,sData,lplReturnCode)	\
    (This)->lpVtbl -> SetDevice2(This,szDevice,sData,lplReturnCode)

#define IActLCPUUSB2_get_ActNetworkNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActNetworkNumber(This,pVal)

#define IActLCPUUSB2_put_ActNetworkNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActNetworkNumber(This,newVal)

#define IActLCPUUSB2_get_ActStationNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActStationNumber(This,pVal)

#define IActLCPUUSB2_put_ActStationNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActStationNumber(This,newVal)

#define IActLCPUUSB2_get_ActUnitNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActUnitNumber(This,pVal)

#define IActLCPUUSB2_put_ActUnitNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActUnitNumber(This,newVal)

#define IActLCPUUSB2_get_ActIONumber(This,pVal)	\
    (This)->lpVtbl -> get_ActIONumber(This,pVal)

#define IActLCPUUSB2_put_ActIONumber(This,newVal)	\
    (This)->lpVtbl -> put_ActIONumber(This,newVal)

#define IActLCPUUSB2_get_ActCpuType(This,pVal)	\
    (This)->lpVtbl -> get_ActCpuType(This,pVal)

#define IActLCPUUSB2_put_ActCpuType(This,newVal)	\
    (This)->lpVtbl -> put_ActCpuType(This,newVal)

#define IActLCPUUSB2_get_ActTimeOut(This,pVal)	\
    (This)->lpVtbl -> get_ActTimeOut(This,pVal)

#define IActLCPUUSB2_put_ActTimeOut(This,newVal)	\
    (This)->lpVtbl -> put_ActTimeOut(This,newVal)

#define IActLCPUUSB2_get_ActDestinationIONumber(This,pVal)	\
    (This)->lpVtbl -> get_ActDestinationIONumber(This,pVal)

#define IActLCPUUSB2_put_ActDestinationIONumber(This,newVal)	\
    (This)->lpVtbl -> put_ActDestinationIONumber(This,newVal)

#define IActLCPUUSB2_get_ActMultiDropChannelNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActMultiDropChannelNumber(This,pVal)

#define IActLCPUUSB2_put_ActMultiDropChannelNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActMultiDropChannelNumber(This,newVal)

#define IActLCPUUSB2_get_ActThroughNetworkType(This,pVal)	\
    (This)->lpVtbl -> get_ActThroughNetworkType(This,pVal)

#define IActLCPUUSB2_put_ActThroughNetworkType(This,newVal)	\
    (This)->lpVtbl -> put_ActThroughNetworkType(This,newVal)

#define IActLCPUUSB2_get_ActIntelligentPreferenceBit(This,pVal)	\
    (This)->lpVtbl -> get_ActIntelligentPreferenceBit(This,pVal)

#define IActLCPUUSB2_put_ActIntelligentPreferenceBit(This,newVal)	\
    (This)->lpVtbl -> put_ActIntelligentPreferenceBit(This,newVal)

#define IActLCPUUSB2_get_ActDidPropertyBit(This,pVal)	\
    (This)->lpVtbl -> get_ActDidPropertyBit(This,pVal)

#define IActLCPUUSB2_put_ActDidPropertyBit(This,newVal)	\
    (This)->lpVtbl -> put_ActDidPropertyBit(This,newVal)

#define IActLCPUUSB2_get_ActDsidPropertyBit(This,pVal)	\
    (This)->lpVtbl -> get_ActDsidPropertyBit(This,pVal)

#define IActLCPUUSB2_put_ActDsidPropertyBit(This,newVal)	\
    (This)->lpVtbl -> put_ActDsidPropertyBit(This,newVal)


#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IActLCPUUSB2_INTERFACE_DEFINED__ */


#ifndef __IActLCPUUSB3_INTERFACE_DEFINED__
#define __IActLCPUUSB3_INTERFACE_DEFINED__

/* interface IActLCPUUSB3 */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IActLCPUUSB3;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("9A9810EA-EEF2-4cd0-85EF-423D7B7F2780")
    IActLCPUUSB3 : public IActLCPUUSB2
    {
    public:
    };
    
#else 	/* C style interface */

    typedef struct IActLCPUUSB3Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IActLCPUUSB3 __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IActLCPUUSB3 __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IActLCPUUSB3 __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IActLCPUUSB3 __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IActLCPUUSB3 __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IActLCPUUSB3 __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IActLCPUUSB3 __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Open )( 
            IActLCPUUSB3 __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Close )( 
            IActLCPUUSB3 __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetDevice )( 
            IActLCPUUSB3 __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [out] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetDevice )( 
            IActLCPUUSB3 __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceBlock )( 
            IActLCPUUSB3 __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lSize,
            /* [size_is][out] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceBlock )( 
            IActLCPUUSB3 __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lSize,
            /* [size_is][in] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceRandom )( 
            IActLCPUUSB3 __RPC_FAR * This,
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG lSize,
            /* [size_is][out] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceRandom )( 
            IActLCPUUSB3 __RPC_FAR * This,
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG lSize,
            /* [size_is][in] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadBuffer )( 
            IActLCPUUSB3 __RPC_FAR * This,
            /* [in] */ LONG lStartIO,
            /* [in] */ LONG lAddress,
            /* [in] */ LONG lSize,
            /* [size_is][out] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteBuffer )( 
            IActLCPUUSB3 __RPC_FAR * This,
            /* [in] */ LONG lStartIO,
            /* [in] */ LONG lAddress,
            /* [in] */ LONG lSize,
            /* [size_is][in] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetCpuType )( 
            IActLCPUUSB3 __RPC_FAR * This,
            /* [string][out] */ BSTR __RPC_FAR *szCpuName,
            /* [out] */ LONG __RPC_FAR *lplCpuCode,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetCpuStatus )( 
            IActLCPUUSB3 __RPC_FAR * This,
            /* [in] */ LONG lOperation,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetClockData )( 
            IActLCPUUSB3 __RPC_FAR * This,
            /* [out] */ SHORT __RPC_FAR *lpsYear,
            /* [out] */ SHORT __RPC_FAR *lpsMonth,
            /* [out] */ SHORT __RPC_FAR *lpsDay,
            /* [out] */ SHORT __RPC_FAR *lpsDayOfWeek,
            /* [out] */ SHORT __RPC_FAR *lpsHour,
            /* [out] */ SHORT __RPC_FAR *lpsMinute,
            /* [out] */ SHORT __RPC_FAR *lpsSecond,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetClockData )( 
            IActLCPUUSB3 __RPC_FAR * This,
            /* [in] */ SHORT sYear,
            /* [in] */ SHORT sMonth,
            /* [in] */ SHORT sDay,
            /* [in] */ SHORT sDayOfWeek,
            /* [in] */ SHORT sHour,
            /* [in] */ SHORT sMinute,
            /* [in] */ SHORT sSecond,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *EntryDeviceStatus )( 
            IActLCPUUSB3 __RPC_FAR * This,
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG lSize,
            /* [in] */ LONG lMonitorCycle,
            /* [size_is][in] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CheckDeviceString )( 
            IActLCPUUSB3 __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lCheckType,
            /* [in] */ LONG lSize,
            /* [out] */ LONG __RPC_FAR *lplDeviceType,
            /* [string][out] */ BSTR __RPC_FAR *lpszDeviceName,
            /* [out] */ LONG __RPC_FAR *lplDeviceNumber,
            /* [out] */ LONG __RPC_FAR *lplDeviceRadix,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *FreeDeviceStatus )( 
            IActLCPUUSB3 __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceBlock2 )( 
            IActLCPUUSB3 __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lSize,
            /* [size_is][out] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceBlock2 )( 
            IActLCPUUSB3 __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lSize,
            /* [size_is][in] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceRandom2 )( 
            IActLCPUUSB3 __RPC_FAR * This,
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG lSize,
            /* [size_is][out] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceRandom2 )( 
            IActLCPUUSB3 __RPC_FAR * This,
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG lSize,
            /* [size_is][in] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetDevice2 )( 
            IActLCPUUSB3 __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [out] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetDevice2 )( 
            IActLCPUUSB3 __RPC_FAR * This,
            /* [in] */ BSTR szDevice,
            /* [in] */ SHORT sData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActNetworkNumber )( 
            IActLCPUUSB3 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActNetworkNumber )( 
            IActLCPUUSB3 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActStationNumber )( 
            IActLCPUUSB3 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActStationNumber )( 
            IActLCPUUSB3 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActUnitNumber )( 
            IActLCPUUSB3 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActUnitNumber )( 
            IActLCPUUSB3 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActIONumber )( 
            IActLCPUUSB3 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActIONumber )( 
            IActLCPUUSB3 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActCpuType )( 
            IActLCPUUSB3 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActCpuType )( 
            IActLCPUUSB3 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActTimeOut )( 
            IActLCPUUSB3 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActTimeOut )( 
            IActLCPUUSB3 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActDestinationIONumber )( 
            IActLCPUUSB3 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActDestinationIONumber )( 
            IActLCPUUSB3 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActMultiDropChannelNumber )( 
            IActLCPUUSB3 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActMultiDropChannelNumber )( 
            IActLCPUUSB3 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActThroughNetworkType )( 
            IActLCPUUSB3 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActThroughNetworkType )( 
            IActLCPUUSB3 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActIntelligentPreferenceBit )( 
            IActLCPUUSB3 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActIntelligentPreferenceBit )( 
            IActLCPUUSB3 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActDidPropertyBit )( 
            IActLCPUUSB3 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActDidPropertyBit )( 
            IActLCPUUSB3 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActDsidPropertyBit )( 
            IActLCPUUSB3 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActDsidPropertyBit )( 
            IActLCPUUSB3 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        END_INTERFACE
    } IActLCPUUSB3Vtbl;

    interface IActLCPUUSB3
    {
        CONST_VTBL struct IActLCPUUSB3Vtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IActLCPUUSB3_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IActLCPUUSB3_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IActLCPUUSB3_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IActLCPUUSB3_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IActLCPUUSB3_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IActLCPUUSB3_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IActLCPUUSB3_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IActLCPUUSB3_Open(This,lplReturnCode)	\
    (This)->lpVtbl -> Open(This,lplReturnCode)

#define IActLCPUUSB3_Close(This,lplReturnCode)	\
    (This)->lpVtbl -> Close(This,lplReturnCode)

#define IActLCPUUSB3_GetDevice(This,szDevice,lplData,lplReturnCode)	\
    (This)->lpVtbl -> GetDevice(This,szDevice,lplData,lplReturnCode)

#define IActLCPUUSB3_SetDevice(This,szDevice,lData,lplReturnCode)	\
    (This)->lpVtbl -> SetDevice(This,szDevice,lData,lplReturnCode)

#define IActLCPUUSB3_ReadDeviceBlock(This,szDevice,lSize,lplData,lplReturnCode)	\
    (This)->lpVtbl -> ReadDeviceBlock(This,szDevice,lSize,lplData,lplReturnCode)

#define IActLCPUUSB3_WriteDeviceBlock(This,szDevice,lSize,lplData,lplReturnCode)	\
    (This)->lpVtbl -> WriteDeviceBlock(This,szDevice,lSize,lplData,lplReturnCode)

#define IActLCPUUSB3_ReadDeviceRandom(This,szDeviceList,lSize,lplData,lplReturnCode)	\
    (This)->lpVtbl -> ReadDeviceRandom(This,szDeviceList,lSize,lplData,lplReturnCode)

#define IActLCPUUSB3_WriteDeviceRandom(This,szDeviceList,lSize,lplData,lplReturnCode)	\
    (This)->lpVtbl -> WriteDeviceRandom(This,szDeviceList,lSize,lplData,lplReturnCode)

#define IActLCPUUSB3_ReadBuffer(This,lStartIO,lAddress,lSize,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> ReadBuffer(This,lStartIO,lAddress,lSize,lpsData,lplReturnCode)

#define IActLCPUUSB3_WriteBuffer(This,lStartIO,lAddress,lSize,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> WriteBuffer(This,lStartIO,lAddress,lSize,lpsData,lplReturnCode)

#define IActLCPUUSB3_GetCpuType(This,szCpuName,lplCpuCode,lplReturnCode)	\
    (This)->lpVtbl -> GetCpuType(This,szCpuName,lplCpuCode,lplReturnCode)

#define IActLCPUUSB3_SetCpuStatus(This,lOperation,lplReturnCode)	\
    (This)->lpVtbl -> SetCpuStatus(This,lOperation,lplReturnCode)

#define IActLCPUUSB3_GetClockData(This,lpsYear,lpsMonth,lpsDay,lpsDayOfWeek,lpsHour,lpsMinute,lpsSecond,lplReturnCode)	\
    (This)->lpVtbl -> GetClockData(This,lpsYear,lpsMonth,lpsDay,lpsDayOfWeek,lpsHour,lpsMinute,lpsSecond,lplReturnCode)

#define IActLCPUUSB3_SetClockData(This,sYear,sMonth,sDay,sDayOfWeek,sHour,sMinute,sSecond,lplReturnCode)	\
    (This)->lpVtbl -> SetClockData(This,sYear,sMonth,sDay,sDayOfWeek,sHour,sMinute,sSecond,lplReturnCode)

#define IActLCPUUSB3_EntryDeviceStatus(This,szDeviceList,lSize,lMonitorCycle,lplData,lplReturnCode)	\
    (This)->lpVtbl -> EntryDeviceStatus(This,szDeviceList,lSize,lMonitorCycle,lplData,lplReturnCode)

#define IActLCPUUSB3_CheckDeviceString(This,szDevice,lCheckType,lSize,lplDeviceType,lpszDeviceName,lplDeviceNumber,lplDeviceRadix,lplReturnCode)	\
    (This)->lpVtbl -> CheckDeviceString(This,szDevice,lCheckType,lSize,lplDeviceType,lpszDeviceName,lplDeviceNumber,lplDeviceRadix,lplReturnCode)

#define IActLCPUUSB3_FreeDeviceStatus(This,lplReturnCode)	\
    (This)->lpVtbl -> FreeDeviceStatus(This,lplReturnCode)

#define IActLCPUUSB3_ReadDeviceBlock2(This,szDevice,lSize,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> ReadDeviceBlock2(This,szDevice,lSize,lpsData,lplReturnCode)

#define IActLCPUUSB3_WriteDeviceBlock2(This,szDevice,lSize,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> WriteDeviceBlock2(This,szDevice,lSize,lpsData,lplReturnCode)

#define IActLCPUUSB3_ReadDeviceRandom2(This,szDeviceList,lSize,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> ReadDeviceRandom2(This,szDeviceList,lSize,lpsData,lplReturnCode)

#define IActLCPUUSB3_WriteDeviceRandom2(This,szDeviceList,lSize,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> WriteDeviceRandom2(This,szDeviceList,lSize,lpsData,lplReturnCode)

#define IActLCPUUSB3_GetDevice2(This,szDevice,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> GetDevice2(This,szDevice,lpsData,lplReturnCode)

#define IActLCPUUSB3_SetDevice2(This,szDevice,sData,lplReturnCode)	\
    (This)->lpVtbl -> SetDevice2(This,szDevice,sData,lplReturnCode)

#define IActLCPUUSB3_get_ActNetworkNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActNetworkNumber(This,pVal)

#define IActLCPUUSB3_put_ActNetworkNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActNetworkNumber(This,newVal)

#define IActLCPUUSB3_get_ActStationNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActStationNumber(This,pVal)

#define IActLCPUUSB3_put_ActStationNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActStationNumber(This,newVal)

#define IActLCPUUSB3_get_ActUnitNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActUnitNumber(This,pVal)

#define IActLCPUUSB3_put_ActUnitNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActUnitNumber(This,newVal)

#define IActLCPUUSB3_get_ActIONumber(This,pVal)	\
    (This)->lpVtbl -> get_ActIONumber(This,pVal)

#define IActLCPUUSB3_put_ActIONumber(This,newVal)	\
    (This)->lpVtbl -> put_ActIONumber(This,newVal)

#define IActLCPUUSB3_get_ActCpuType(This,pVal)	\
    (This)->lpVtbl -> get_ActCpuType(This,pVal)

#define IActLCPUUSB3_put_ActCpuType(This,newVal)	\
    (This)->lpVtbl -> put_ActCpuType(This,newVal)

#define IActLCPUUSB3_get_ActTimeOut(This,pVal)	\
    (This)->lpVtbl -> get_ActTimeOut(This,pVal)

#define IActLCPUUSB3_put_ActTimeOut(This,newVal)	\
    (This)->lpVtbl -> put_ActTimeOut(This,newVal)

#define IActLCPUUSB3_get_ActDestinationIONumber(This,pVal)	\
    (This)->lpVtbl -> get_ActDestinationIONumber(This,pVal)

#define IActLCPUUSB3_put_ActDestinationIONumber(This,newVal)	\
    (This)->lpVtbl -> put_ActDestinationIONumber(This,newVal)

#define IActLCPUUSB3_get_ActMultiDropChannelNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActMultiDropChannelNumber(This,pVal)

#define IActLCPUUSB3_put_ActMultiDropChannelNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActMultiDropChannelNumber(This,newVal)

#define IActLCPUUSB3_get_ActThroughNetworkType(This,pVal)	\
    (This)->lpVtbl -> get_ActThroughNetworkType(This,pVal)

#define IActLCPUUSB3_put_ActThroughNetworkType(This,newVal)	\
    (This)->lpVtbl -> put_ActThroughNetworkType(This,newVal)

#define IActLCPUUSB3_get_ActIntelligentPreferenceBit(This,pVal)	\
    (This)->lpVtbl -> get_ActIntelligentPreferenceBit(This,pVal)

#define IActLCPUUSB3_put_ActIntelligentPreferenceBit(This,newVal)	\
    (This)->lpVtbl -> put_ActIntelligentPreferenceBit(This,newVal)

#define IActLCPUUSB3_get_ActDidPropertyBit(This,pVal)	\
    (This)->lpVtbl -> get_ActDidPropertyBit(This,pVal)

#define IActLCPUUSB3_put_ActDidPropertyBit(This,newVal)	\
    (This)->lpVtbl -> put_ActDidPropertyBit(This,newVal)

#define IActLCPUUSB3_get_ActDsidPropertyBit(This,pVal)	\
    (This)->lpVtbl -> get_ActDsidPropertyBit(This,pVal)

#define IActLCPUUSB3_put_ActDsidPropertyBit(This,newVal)	\
    (This)->lpVtbl -> put_ActDsidPropertyBit(This,newVal)



#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IActLCPUUSB3_INTERFACE_DEFINED__ */


#ifndef __IActMLLCPUUSB_INTERFACE_DEFINED__
#define __IActMLLCPUUSB_INTERFACE_DEFINED__

/* interface IActMLLCPUUSB */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IActMLLCPUUSB;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("CAD92CF3-71D8-47F1-834D-CDDD89AD9E3B")
    IActMLLCPUUSB : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Open( 
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Close( 
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetDevice( 
            /* [in] */ VARIANT varDevice,
            /* [out] */ VARIANT __RPC_FAR *lpvarData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetDevice( 
            /* [in] */ VARIANT varDevice,
            /* [in] */ VARIANT varData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ReadDeviceBlock( 
            /* [in] */ VARIANT varDevice,
            /* [in] */ VARIANT varSize,
            /* [out] */ VARIANT __RPC_FAR *lpvarData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE WriteDeviceBlock( 
            /* [in] */ VARIANT varDevice,
            /* [in] */ VARIANT varSize,
            /* [in] */ VARIANT varData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ReadDeviceRandom( 
            /* [in] */ VARIANT varDeviceList,
            /* [in] */ VARIANT varSize,
            /* [out] */ VARIANT __RPC_FAR *lpvarData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE WriteDeviceRandom( 
            /* [in] */ VARIANT varDeviceList,
            /* [in] */ VARIANT varSize,
            /* [in] */ VARIANT varData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ReadBuffer( 
            /* [in] */ VARIANT varStartIO,
            /* [in] */ VARIANT varAddress,
            /* [in] */ VARIANT varReadSize,
            /* [out] */ VARIANT __RPC_FAR *lpvarData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE WriteBuffer( 
            /* [in] */ VARIANT varStartIO,
            /* [in] */ VARIANT varAddress,
            /* [in] */ VARIANT varWriteSize,
            /* [in] */ VARIANT varData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetClockData( 
            /* [out] */ VARIANT __RPC_FAR *lpvarYear,
            /* [out] */ VARIANT __RPC_FAR *lpvarMonth,
            /* [out] */ VARIANT __RPC_FAR *lpvarDay,
            /* [out] */ VARIANT __RPC_FAR *lpvarDayOfWeek,
            /* [out] */ VARIANT __RPC_FAR *lpvarHour,
            /* [out] */ VARIANT __RPC_FAR *lpvarMinute,
            /* [out] */ VARIANT __RPC_FAR *lpvarSecond,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetClockData( 
            /* [in] */ VARIANT varYear,
            /* [in] */ VARIANT varMonth,
            /* [in] */ VARIANT varDay,
            /* [in] */ VARIANT varDayOfWeek,
            /* [in] */ VARIANT varHour,
            /* [in] */ VARIANT varMinute,
            /* [in] */ VARIANT varSecond,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetCpuStatus( 
            /* [in] */ VARIANT varOperation,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetCpuType( 
            /* [out] */ VARIANT __RPC_FAR *lpvarCpuName,
            /* [out] */ VARIANT __RPC_FAR *lpvarCpuType,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE EntryDeviceStatus( 
            /* [in] */ VARIANT varDeviceList,
            /* [in] */ VARIANT varSize,
            /* [in] */ VARIANT varMonitorCycle,
            /* [in] */ VARIANT varData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE FreeDeviceStatus( 
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ReadDeviceBlock2( 
            /* [in] */ VARIANT varDevice,
            /* [in] */ VARIANT varSize,
            /* [out] */ VARIANT __RPC_FAR *lpvarData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE WriteDeviceBlock2( 
            /* [in] */ VARIANT varDevice,
            /* [in] */ VARIANT varSize,
            /* [in] */ VARIANT varData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ReadDeviceRandom2( 
            /* [in] */ VARIANT varDeviceList,
            /* [in] */ VARIANT varSize,
            /* [out] */ VARIANT __RPC_FAR *lpvarData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE WriteDeviceRandom2( 
            /* [in] */ VARIANT varDeviceList,
            /* [in] */ VARIANT varSize,
            /* [in] */ VARIANT varData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetDevice2( 
            /* [in] */ VARIANT varDevice,
            /* [out] */ VARIANT __RPC_FAR *lpvarData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetDevice2( 
            /* [in] */ VARIANT varDevice,
            /* [in] */ VARIANT varData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActNetworkNumber( 
            /* [retval][out] */ VARIANT __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActNetworkNumber( 
            /* [in] */ VARIANT newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActStationNumber( 
            /* [retval][out] */ VARIANT __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActStationNumber( 
            /* [in] */ VARIANT newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActUnitNumber( 
            /* [retval][out] */ VARIANT __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActUnitNumber( 
            /* [in] */ VARIANT newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActIONumber( 
            /* [retval][out] */ VARIANT __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActIONumber( 
            /* [in] */ VARIANT newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActCpuType( 
            /* [retval][out] */ VARIANT __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActCpuType( 
            /* [in] */ VARIANT newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActTimeOut( 
            /* [retval][out] */ VARIANT __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActTimeOut( 
            /* [in] */ VARIANT newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActDestinationIONumber( 
            /* [retval][out] */ VARIANT __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActDestinationIONumber( 
            /* [in] */ VARIANT newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActMultiDropChannelNumber( 
            /* [retval][out] */ VARIANT __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActMultiDropChannelNumber( 
            /* [in] */ VARIANT newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActThroughNetworkType( 
            /* [retval][out] */ VARIANT __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActThroughNetworkType( 
            /* [in] */ VARIANT newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActIntelligentPreferenceBit( 
            /* [retval][out] */ VARIANT __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActIntelligentPreferenceBit( 
            /* [in] */ VARIANT newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActDidPropertyBit( 
            /* [retval][out] */ VARIANT __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActDidPropertyBit( 
            /* [in] */ VARIANT newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActDsidPropertyBit( 
            /* [retval][out] */ VARIANT __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActDsidPropertyBit( 
            /* [in] */ VARIANT newVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IActMLLCPUUSBVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IActMLLCPUUSB __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IActMLLCPUUSB __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IActMLLCPUUSB __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IActMLLCPUUSB __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IActMLLCPUUSB __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IActMLLCPUUSB __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IActMLLCPUUSB __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Open )( 
            IActMLLCPUUSB __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Close )( 
            IActMLLCPUUSB __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetDevice )( 
            IActMLLCPUUSB __RPC_FAR * This,
            /* [in] */ VARIANT varDevice,
            /* [out] */ VARIANT __RPC_FAR *lpvarData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetDevice )( 
            IActMLLCPUUSB __RPC_FAR * This,
            /* [in] */ VARIANT varDevice,
            /* [in] */ VARIANT varData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceBlock )( 
            IActMLLCPUUSB __RPC_FAR * This,
            /* [in] */ VARIANT varDevice,
            /* [in] */ VARIANT varSize,
            /* [out] */ VARIANT __RPC_FAR *lpvarData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceBlock )( 
            IActMLLCPUUSB __RPC_FAR * This,
            /* [in] */ VARIANT varDevice,
            /* [in] */ VARIANT varSize,
            /* [in] */ VARIANT varData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceRandom )( 
            IActMLLCPUUSB __RPC_FAR * This,
            /* [in] */ VARIANT varDeviceList,
            /* [in] */ VARIANT varSize,
            /* [out] */ VARIANT __RPC_FAR *lpvarData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceRandom )( 
            IActMLLCPUUSB __RPC_FAR * This,
            /* [in] */ VARIANT varDeviceList,
            /* [in] */ VARIANT varSize,
            /* [in] */ VARIANT varData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadBuffer )( 
            IActMLLCPUUSB __RPC_FAR * This,
            /* [in] */ VARIANT varStartIO,
            /* [in] */ VARIANT varAddress,
            /* [in] */ VARIANT varReadSize,
            /* [out] */ VARIANT __RPC_FAR *lpvarData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteBuffer )( 
            IActMLLCPUUSB __RPC_FAR * This,
            /* [in] */ VARIANT varStartIO,
            /* [in] */ VARIANT varAddress,
            /* [in] */ VARIANT varWriteSize,
            /* [in] */ VARIANT varData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetClockData )( 
            IActMLLCPUUSB __RPC_FAR * This,
            /* [out] */ VARIANT __RPC_FAR *lpvarYear,
            /* [out] */ VARIANT __RPC_FAR *lpvarMonth,
            /* [out] */ VARIANT __RPC_FAR *lpvarDay,
            /* [out] */ VARIANT __RPC_FAR *lpvarDayOfWeek,
            /* [out] */ VARIANT __RPC_FAR *lpvarHour,
            /* [out] */ VARIANT __RPC_FAR *lpvarMinute,
            /* [out] */ VARIANT __RPC_FAR *lpvarSecond,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetClockData )( 
            IActMLLCPUUSB __RPC_FAR * This,
            /* [in] */ VARIANT varYear,
            /* [in] */ VARIANT varMonth,
            /* [in] */ VARIANT varDay,
            /* [in] */ VARIANT varDayOfWeek,
            /* [in] */ VARIANT varHour,
            /* [in] */ VARIANT varMinute,
            /* [in] */ VARIANT varSecond,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetCpuStatus )( 
            IActMLLCPUUSB __RPC_FAR * This,
            /* [in] */ VARIANT varOperation,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetCpuType )( 
            IActMLLCPUUSB __RPC_FAR * This,
            /* [out] */ VARIANT __RPC_FAR *lpvarCpuName,
            /* [out] */ VARIANT __RPC_FAR *lpvarCpuType,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *EntryDeviceStatus )( 
            IActMLLCPUUSB __RPC_FAR * This,
            /* [in] */ VARIANT varDeviceList,
            /* [in] */ VARIANT varSize,
            /* [in] */ VARIANT varMonitorCycle,
            /* [in] */ VARIANT varData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *FreeDeviceStatus )( 
            IActMLLCPUUSB __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceBlock2 )( 
            IActMLLCPUUSB __RPC_FAR * This,
            /* [in] */ VARIANT varDevice,
            /* [in] */ VARIANT varSize,
            /* [out] */ VARIANT __RPC_FAR *lpvarData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceBlock2 )( 
            IActMLLCPUUSB __RPC_FAR * This,
            /* [in] */ VARIANT varDevice,
            /* [in] */ VARIANT varSize,
            /* [in] */ VARIANT varData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceRandom2 )( 
            IActMLLCPUUSB __RPC_FAR * This,
            /* [in] */ VARIANT varDeviceList,
            /* [in] */ VARIANT varSize,
            /* [out] */ VARIANT __RPC_FAR *lpvarData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceRandom2 )( 
            IActMLLCPUUSB __RPC_FAR * This,
            /* [in] */ VARIANT varDeviceList,
            /* [in] */ VARIANT varSize,
            /* [in] */ VARIANT varData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetDevice2 )( 
            IActMLLCPUUSB __RPC_FAR * This,
            /* [in] */ VARIANT varDevice,
            /* [out] */ VARIANT __RPC_FAR *lpvarData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetDevice2 )( 
            IActMLLCPUUSB __RPC_FAR * This,
            /* [in] */ VARIANT varDevice,
            /* [in] */ VARIANT varData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActNetworkNumber )( 
            IActMLLCPUUSB __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActNetworkNumber )( 
            IActMLLCPUUSB __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActStationNumber )( 
            IActMLLCPUUSB __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActStationNumber )( 
            IActMLLCPUUSB __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActUnitNumber )( 
            IActMLLCPUUSB __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActUnitNumber )( 
            IActMLLCPUUSB __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActIONumber )( 
            IActMLLCPUUSB __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActIONumber )( 
            IActMLLCPUUSB __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActCpuType )( 
            IActMLLCPUUSB __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActCpuType )( 
            IActMLLCPUUSB __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActTimeOut )( 
            IActMLLCPUUSB __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActTimeOut )( 
            IActMLLCPUUSB __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActDestinationIONumber )( 
            IActMLLCPUUSB __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActDestinationIONumber )( 
            IActMLLCPUUSB __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActMultiDropChannelNumber )( 
            IActMLLCPUUSB __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActMultiDropChannelNumber )( 
            IActMLLCPUUSB __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActThroughNetworkType )( 
            IActMLLCPUUSB __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActThroughNetworkType )( 
            IActMLLCPUUSB __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActIntelligentPreferenceBit )( 
            IActMLLCPUUSB __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActIntelligentPreferenceBit )( 
            IActMLLCPUUSB __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActDidPropertyBit )( 
            IActMLLCPUUSB __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActDidPropertyBit )( 
            IActMLLCPUUSB __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActDsidPropertyBit )( 
            IActMLLCPUUSB __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActDsidPropertyBit )( 
            IActMLLCPUUSB __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        END_INTERFACE
    } IActMLLCPUUSBVtbl;

    interface IActMLLCPUUSB
    {
        CONST_VTBL struct IActMLLCPUUSBVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IActMLLCPUUSB_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IActMLLCPUUSB_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IActMLLCPUUSB_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IActMLLCPUUSB_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IActMLLCPUUSB_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IActMLLCPUUSB_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IActMLLCPUUSB_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IActMLLCPUUSB_Open(This,lpvarReturnCode)	\
    (This)->lpVtbl -> Open(This,lpvarReturnCode)

#define IActMLLCPUUSB_Close(This,lpvarReturnCode)	\
    (This)->lpVtbl -> Close(This,lpvarReturnCode)

#define IActMLLCPUUSB_GetDevice(This,varDevice,lpvarData,lpvarReturnCode)	\
    (This)->lpVtbl -> GetDevice(This,varDevice,lpvarData,lpvarReturnCode)

#define IActMLLCPUUSB_SetDevice(This,varDevice,varData,lpvarReturnCode)	\
    (This)->lpVtbl -> SetDevice(This,varDevice,varData,lpvarReturnCode)

#define IActMLLCPUUSB_ReadDeviceBlock(This,varDevice,varSize,lpvarData,lpvarReturnCode)	\
    (This)->lpVtbl -> ReadDeviceBlock(This,varDevice,varSize,lpvarData,lpvarReturnCode)

#define IActMLLCPUUSB_WriteDeviceBlock(This,varDevice,varSize,varData,lpvarReturnCode)	\
    (This)->lpVtbl -> WriteDeviceBlock(This,varDevice,varSize,varData,lpvarReturnCode)

#define IActMLLCPUUSB_ReadDeviceRandom(This,varDeviceList,varSize,lpvarData,lpvarReturnCode)	\
    (This)->lpVtbl -> ReadDeviceRandom(This,varDeviceList,varSize,lpvarData,lpvarReturnCode)

#define IActMLLCPUUSB_WriteDeviceRandom(This,varDeviceList,varSize,varData,lpvarReturnCode)	\
    (This)->lpVtbl -> WriteDeviceRandom(This,varDeviceList,varSize,varData,lpvarReturnCode)

#define IActMLLCPUUSB_ReadBuffer(This,varStartIO,varAddress,varReadSize,lpvarData,lpvarReturnCode)	\
    (This)->lpVtbl -> ReadBuffer(This,varStartIO,varAddress,varReadSize,lpvarData,lpvarReturnCode)

#define IActMLLCPUUSB_WriteBuffer(This,varStartIO,varAddress,varWriteSize,varData,lpvarReturnCode)	\
    (This)->lpVtbl -> WriteBuffer(This,varStartIO,varAddress,varWriteSize,varData,lpvarReturnCode)

#define IActMLLCPUUSB_GetClockData(This,lpvarYear,lpvarMonth,lpvarDay,lpvarDayOfWeek,lpvarHour,lpvarMinute,lpvarSecond,lpvarReturnCode)	\
    (This)->lpVtbl -> GetClockData(This,lpvarYear,lpvarMonth,lpvarDay,lpvarDayOfWeek,lpvarHour,lpvarMinute,lpvarSecond,lpvarReturnCode)

#define IActMLLCPUUSB_SetClockData(This,varYear,varMonth,varDay,varDayOfWeek,varHour,varMinute,varSecond,lpvarReturnCode)	\
    (This)->lpVtbl -> SetClockData(This,varYear,varMonth,varDay,varDayOfWeek,varHour,varMinute,varSecond,lpvarReturnCode)

#define IActMLLCPUUSB_SetCpuStatus(This,varOperation,lpvarReturnCode)	\
    (This)->lpVtbl -> SetCpuStatus(This,varOperation,lpvarReturnCode)

#define IActMLLCPUUSB_GetCpuType(This,lpvarCpuName,lpvarCpuType,lpvarReturnCode)	\
    (This)->lpVtbl -> GetCpuType(This,lpvarCpuName,lpvarCpuType,lpvarReturnCode)

#define IActMLLCPUUSB_EntryDeviceStatus(This,varDeviceList,varSize,varMonitorCycle,varData,lpvarReturnCode)	\
    (This)->lpVtbl -> EntryDeviceStatus(This,varDeviceList,varSize,varMonitorCycle,varData,lpvarReturnCode)

#define IActMLLCPUUSB_FreeDeviceStatus(This,lpvarReturnCode)	\
    (This)->lpVtbl -> FreeDeviceStatus(This,lpvarReturnCode)

#define IActMLLCPUUSB_ReadDeviceBlock2(This,varDevice,varSize,lpvarData,lpvarReturnCode)	\
    (This)->lpVtbl -> ReadDeviceBlock2(This,varDevice,varSize,lpvarData,lpvarReturnCode)

#define IActMLLCPUUSB_WriteDeviceBlock2(This,varDevice,varSize,varData,lpvarReturnCode)	\
    (This)->lpVtbl -> WriteDeviceBlock2(This,varDevice,varSize,varData,lpvarReturnCode)

#define IActMLLCPUUSB_ReadDeviceRandom2(This,varDeviceList,varSize,lpvarData,lpvarReturnCode)	\
    (This)->lpVtbl -> ReadDeviceRandom2(This,varDeviceList,varSize,lpvarData,lpvarReturnCode)

#define IActMLLCPUUSB_WriteDeviceRandom2(This,varDeviceList,varSize,varData,lpvarReturnCode)	\
    (This)->lpVtbl -> WriteDeviceRandom2(This,varDeviceList,varSize,varData,lpvarReturnCode)

#define IActMLLCPUUSB_GetDevice2(This,varDevice,lpvarData,lpvarReturnCode)	\
    (This)->lpVtbl -> GetDevice2(This,varDevice,lpvarData,lpvarReturnCode)

#define IActMLLCPUUSB_SetDevice2(This,varDevice,varData,lpvarReturnCode)	\
    (This)->lpVtbl -> SetDevice2(This,varDevice,varData,lpvarReturnCode)

#define IActMLLCPUUSB_get_ActNetworkNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActNetworkNumber(This,pVal)

#define IActMLLCPUUSB_put_ActNetworkNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActNetworkNumber(This,newVal)

#define IActMLLCPUUSB_get_ActStationNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActStationNumber(This,pVal)

#define IActMLLCPUUSB_put_ActStationNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActStationNumber(This,newVal)

#define IActMLLCPUUSB_get_ActUnitNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActUnitNumber(This,pVal)

#define IActMLLCPUUSB_put_ActUnitNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActUnitNumber(This,newVal)

#define IActMLLCPUUSB_get_ActIONumber(This,pVal)	\
    (This)->lpVtbl -> get_ActIONumber(This,pVal)

#define IActMLLCPUUSB_put_ActIONumber(This,newVal)	\
    (This)->lpVtbl -> put_ActIONumber(This,newVal)

#define IActMLLCPUUSB_get_ActCpuType(This,pVal)	\
    (This)->lpVtbl -> get_ActCpuType(This,pVal)

#define IActMLLCPUUSB_put_ActCpuType(This,newVal)	\
    (This)->lpVtbl -> put_ActCpuType(This,newVal)

#define IActMLLCPUUSB_get_ActTimeOut(This,pVal)	\
    (This)->lpVtbl -> get_ActTimeOut(This,pVal)

#define IActMLLCPUUSB_put_ActTimeOut(This,newVal)	\
    (This)->lpVtbl -> put_ActTimeOut(This,newVal)

#define IActMLLCPUUSB_get_ActDestinationIONumber(This,pVal)	\
    (This)->lpVtbl -> get_ActDestinationIONumber(This,pVal)

#define IActMLLCPUUSB_put_ActDestinationIONumber(This,newVal)	\
    (This)->lpVtbl -> put_ActDestinationIONumber(This,newVal)

#define IActMLLCPUUSB_get_ActMultiDropChannelNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActMultiDropChannelNumber(This,pVal)

#define IActMLLCPUUSB_put_ActMultiDropChannelNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActMultiDropChannelNumber(This,newVal)

#define IActMLLCPUUSB_get_ActThroughNetworkType(This,pVal)	\
    (This)->lpVtbl -> get_ActThroughNetworkType(This,pVal)

#define IActMLLCPUUSB_put_ActThroughNetworkType(This,newVal)	\
    (This)->lpVtbl -> put_ActThroughNetworkType(This,newVal)

#define IActMLLCPUUSB_get_ActIntelligentPreferenceBit(This,pVal)	\
    (This)->lpVtbl -> get_ActIntelligentPreferenceBit(This,pVal)

#define IActMLLCPUUSB_put_ActIntelligentPreferenceBit(This,newVal)	\
    (This)->lpVtbl -> put_ActIntelligentPreferenceBit(This,newVal)

#define IActMLLCPUUSB_get_ActDidPropertyBit(This,pVal)	\
    (This)->lpVtbl -> get_ActDidPropertyBit(This,pVal)

#define IActMLLCPUUSB_put_ActDidPropertyBit(This,newVal)	\
    (This)->lpVtbl -> put_ActDidPropertyBit(This,newVal)

#define IActMLLCPUUSB_get_ActDsidPropertyBit(This,pVal)	\
    (This)->lpVtbl -> get_ActDsidPropertyBit(This,pVal)

#define IActMLLCPUUSB_put_ActDsidPropertyBit(This,newVal)	\
    (This)->lpVtbl -> put_ActDsidPropertyBit(This,newVal)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActMLLCPUUSB_Open_Proxy( 
    IActMLLCPUUSB __RPC_FAR * This,
    /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);


void __RPC_STUB IActMLLCPUUSB_Open_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActMLLCPUUSB_Close_Proxy( 
    IActMLLCPUUSB __RPC_FAR * This,
    /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);


void __RPC_STUB IActMLLCPUUSB_Close_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActMLLCPUUSB_GetDevice_Proxy( 
    IActMLLCPUUSB __RPC_FAR * This,
    /* [in] */ VARIANT varDevice,
    /* [out] */ VARIANT __RPC_FAR *lpvarData,
    /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);


void __RPC_STUB IActMLLCPUUSB_GetDevice_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActMLLCPUUSB_SetDevice_Proxy( 
    IActMLLCPUUSB __RPC_FAR * This,
    /* [in] */ VARIANT varDevice,
    /* [in] */ VARIANT varData,
    /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);


void __RPC_STUB IActMLLCPUUSB_SetDevice_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActMLLCPUUSB_ReadDeviceBlock_Proxy( 
    IActMLLCPUUSB __RPC_FAR * This,
    /* [in] */ VARIANT varDevice,
    /* [in] */ VARIANT varSize,
    /* [out] */ VARIANT __RPC_FAR *lpvarData,
    /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);


void __RPC_STUB IActMLLCPUUSB_ReadDeviceBlock_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActMLLCPUUSB_WriteDeviceBlock_Proxy( 
    IActMLLCPUUSB __RPC_FAR * This,
    /* [in] */ VARIANT varDevice,
    /* [in] */ VARIANT varSize,
    /* [in] */ VARIANT varData,
    /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);


void __RPC_STUB IActMLLCPUUSB_WriteDeviceBlock_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActMLLCPUUSB_ReadDeviceRandom_Proxy( 
    IActMLLCPUUSB __RPC_FAR * This,
    /* [in] */ VARIANT varDeviceList,
    /* [in] */ VARIANT varSize,
    /* [out] */ VARIANT __RPC_FAR *lpvarData,
    /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);


void __RPC_STUB IActMLLCPUUSB_ReadDeviceRandom_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActMLLCPUUSB_WriteDeviceRandom_Proxy( 
    IActMLLCPUUSB __RPC_FAR * This,
    /* [in] */ VARIANT varDeviceList,
    /* [in] */ VARIANT varSize,
    /* [in] */ VARIANT varData,
    /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);


void __RPC_STUB IActMLLCPUUSB_WriteDeviceRandom_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActMLLCPUUSB_ReadBuffer_Proxy( 
    IActMLLCPUUSB __RPC_FAR * This,
    /* [in] */ VARIANT varStartIO,
    /* [in] */ VARIANT varAddress,
    /* [in] */ VARIANT varReadSize,
    /* [out] */ VARIANT __RPC_FAR *lpvarData,
    /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);


void __RPC_STUB IActMLLCPUUSB_ReadBuffer_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActMLLCPUUSB_WriteBuffer_Proxy( 
    IActMLLCPUUSB __RPC_FAR * This,
    /* [in] */ VARIANT varStartIO,
    /* [in] */ VARIANT varAddress,
    /* [in] */ VARIANT varWriteSize,
    /* [in] */ VARIANT varData,
    /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);


void __RPC_STUB IActMLLCPUUSB_WriteBuffer_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActMLLCPUUSB_GetClockData_Proxy( 
    IActMLLCPUUSB __RPC_FAR * This,
    /* [out] */ VARIANT __RPC_FAR *lpvarYear,
    /* [out] */ VARIANT __RPC_FAR *lpvarMonth,
    /* [out] */ VARIANT __RPC_FAR *lpvarDay,
    /* [out] */ VARIANT __RPC_FAR *lpvarDayOfWeek,
    /* [out] */ VARIANT __RPC_FAR *lpvarHour,
    /* [out] */ VARIANT __RPC_FAR *lpvarMinute,
    /* [out] */ VARIANT __RPC_FAR *lpvarSecond,
    /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);


void __RPC_STUB IActMLLCPUUSB_GetClockData_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActMLLCPUUSB_SetClockData_Proxy( 
    IActMLLCPUUSB __RPC_FAR * This,
    /* [in] */ VARIANT varYear,
    /* [in] */ VARIANT varMonth,
    /* [in] */ VARIANT varDay,
    /* [in] */ VARIANT varDayOfWeek,
    /* [in] */ VARIANT varHour,
    /* [in] */ VARIANT varMinute,
    /* [in] */ VARIANT varSecond,
    /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);


void __RPC_STUB IActMLLCPUUSB_SetClockData_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActMLLCPUUSB_SetCpuStatus_Proxy( 
    IActMLLCPUUSB __RPC_FAR * This,
    /* [in] */ VARIANT varOperation,
    /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);


void __RPC_STUB IActMLLCPUUSB_SetCpuStatus_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActMLLCPUUSB_GetCpuType_Proxy( 
    IActMLLCPUUSB __RPC_FAR * This,
    /* [out] */ VARIANT __RPC_FAR *lpvarCpuName,
    /* [out] */ VARIANT __RPC_FAR *lpvarCpuType,
    /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);


void __RPC_STUB IActMLLCPUUSB_GetCpuType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActMLLCPUUSB_EntryDeviceStatus_Proxy( 
    IActMLLCPUUSB __RPC_FAR * This,
    /* [in] */ VARIANT varDeviceList,
    /* [in] */ VARIANT varSize,
    /* [in] */ VARIANT varMonitorCycle,
    /* [in] */ VARIANT varData,
    /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);


void __RPC_STUB IActMLLCPUUSB_EntryDeviceStatus_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActMLLCPUUSB_FreeDeviceStatus_Proxy( 
    IActMLLCPUUSB __RPC_FAR * This,
    /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);


void __RPC_STUB IActMLLCPUUSB_FreeDeviceStatus_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActMLLCPUUSB_ReadDeviceBlock2_Proxy( 
    IActMLLCPUUSB __RPC_FAR * This,
    /* [in] */ VARIANT varDevice,
    /* [in] */ VARIANT varSize,
    /* [out] */ VARIANT __RPC_FAR *lpvarData,
    /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);


void __RPC_STUB IActMLLCPUUSB_ReadDeviceBlock2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActMLLCPUUSB_WriteDeviceBlock2_Proxy( 
    IActMLLCPUUSB __RPC_FAR * This,
    /* [in] */ VARIANT varDevice,
    /* [in] */ VARIANT varSize,
    /* [in] */ VARIANT varData,
    /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);


void __RPC_STUB IActMLLCPUUSB_WriteDeviceBlock2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActMLLCPUUSB_ReadDeviceRandom2_Proxy( 
    IActMLLCPUUSB __RPC_FAR * This,
    /* [in] */ VARIANT varDeviceList,
    /* [in] */ VARIANT varSize,
    /* [out] */ VARIANT __RPC_FAR *lpvarData,
    /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);


void __RPC_STUB IActMLLCPUUSB_ReadDeviceRandom2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActMLLCPUUSB_WriteDeviceRandom2_Proxy( 
    IActMLLCPUUSB __RPC_FAR * This,
    /* [in] */ VARIANT varDeviceList,
    /* [in] */ VARIANT varSize,
    /* [in] */ VARIANT varData,
    /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);


void __RPC_STUB IActMLLCPUUSB_WriteDeviceRandom2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActMLLCPUUSB_GetDevice2_Proxy( 
    IActMLLCPUUSB __RPC_FAR * This,
    /* [in] */ VARIANT varDevice,
    /* [out] */ VARIANT __RPC_FAR *lpvarData,
    /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);


void __RPC_STUB IActMLLCPUUSB_GetDevice2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActMLLCPUUSB_SetDevice2_Proxy( 
    IActMLLCPUUSB __RPC_FAR * This,
    /* [in] */ VARIANT varDevice,
    /* [in] */ VARIANT varData,
    /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);


void __RPC_STUB IActMLLCPUUSB_SetDevice2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActMLLCPUUSB_get_ActNetworkNumber_Proxy( 
    IActMLLCPUUSB __RPC_FAR * This,
    /* [retval][out] */ VARIANT __RPC_FAR *pVal);


void __RPC_STUB IActMLLCPUUSB_get_ActNetworkNumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActMLLCPUUSB_put_ActNetworkNumber_Proxy( 
    IActMLLCPUUSB __RPC_FAR * This,
    /* [in] */ VARIANT newVal);


void __RPC_STUB IActMLLCPUUSB_put_ActNetworkNumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActMLLCPUUSB_get_ActStationNumber_Proxy( 
    IActMLLCPUUSB __RPC_FAR * This,
    /* [retval][out] */ VARIANT __RPC_FAR *pVal);


void __RPC_STUB IActMLLCPUUSB_get_ActStationNumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActMLLCPUUSB_put_ActStationNumber_Proxy( 
    IActMLLCPUUSB __RPC_FAR * This,
    /* [in] */ VARIANT newVal);


void __RPC_STUB IActMLLCPUUSB_put_ActStationNumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActMLLCPUUSB_get_ActUnitNumber_Proxy( 
    IActMLLCPUUSB __RPC_FAR * This,
    /* [retval][out] */ VARIANT __RPC_FAR *pVal);


void __RPC_STUB IActMLLCPUUSB_get_ActUnitNumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActMLLCPUUSB_put_ActUnitNumber_Proxy( 
    IActMLLCPUUSB __RPC_FAR * This,
    /* [in] */ VARIANT newVal);


void __RPC_STUB IActMLLCPUUSB_put_ActUnitNumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActMLLCPUUSB_get_ActIONumber_Proxy( 
    IActMLLCPUUSB __RPC_FAR * This,
    /* [retval][out] */ VARIANT __RPC_FAR *pVal);


void __RPC_STUB IActMLLCPUUSB_get_ActIONumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActMLLCPUUSB_put_ActIONumber_Proxy( 
    IActMLLCPUUSB __RPC_FAR * This,
    /* [in] */ VARIANT newVal);


void __RPC_STUB IActMLLCPUUSB_put_ActIONumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActMLLCPUUSB_get_ActCpuType_Proxy( 
    IActMLLCPUUSB __RPC_FAR * This,
    /* [retval][out] */ VARIANT __RPC_FAR *pVal);


void __RPC_STUB IActMLLCPUUSB_get_ActCpuType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActMLLCPUUSB_put_ActCpuType_Proxy( 
    IActMLLCPUUSB __RPC_FAR * This,
    /* [in] */ VARIANT newVal);


void __RPC_STUB IActMLLCPUUSB_put_ActCpuType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActMLLCPUUSB_get_ActTimeOut_Proxy( 
    IActMLLCPUUSB __RPC_FAR * This,
    /* [retval][out] */ VARIANT __RPC_FAR *pVal);


void __RPC_STUB IActMLLCPUUSB_get_ActTimeOut_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActMLLCPUUSB_put_ActTimeOut_Proxy( 
    IActMLLCPUUSB __RPC_FAR * This,
    /* [in] */ VARIANT newVal);


void __RPC_STUB IActMLLCPUUSB_put_ActTimeOut_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActMLLCPUUSB_get_ActDestinationIONumber_Proxy( 
    IActMLLCPUUSB __RPC_FAR * This,
    /* [retval][out] */ VARIANT __RPC_FAR *pVal);


void __RPC_STUB IActMLLCPUUSB_get_ActDestinationIONumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActMLLCPUUSB_put_ActDestinationIONumber_Proxy( 
    IActMLLCPUUSB __RPC_FAR * This,
    /* [in] */ VARIANT newVal);


void __RPC_STUB IActMLLCPUUSB_put_ActDestinationIONumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActMLLCPUUSB_get_ActMultiDropChannelNumber_Proxy( 
    IActMLLCPUUSB __RPC_FAR * This,
    /* [retval][out] */ VARIANT __RPC_FAR *pVal);


void __RPC_STUB IActMLLCPUUSB_get_ActMultiDropChannelNumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActMLLCPUUSB_put_ActMultiDropChannelNumber_Proxy( 
    IActMLLCPUUSB __RPC_FAR * This,
    /* [in] */ VARIANT newVal);


void __RPC_STUB IActMLLCPUUSB_put_ActMultiDropChannelNumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActMLLCPUUSB_get_ActThroughNetworkType_Proxy( 
    IActMLLCPUUSB __RPC_FAR * This,
    /* [retval][out] */ VARIANT __RPC_FAR *pVal);


void __RPC_STUB IActMLLCPUUSB_get_ActThroughNetworkType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActMLLCPUUSB_put_ActThroughNetworkType_Proxy( 
    IActMLLCPUUSB __RPC_FAR * This,
    /* [in] */ VARIANT newVal);


void __RPC_STUB IActMLLCPUUSB_put_ActThroughNetworkType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActMLLCPUUSB_get_ActIntelligentPreferenceBit_Proxy( 
    IActMLLCPUUSB __RPC_FAR * This,
    /* [retval][out] */ VARIANT __RPC_FAR *pVal);


void __RPC_STUB IActMLLCPUUSB_get_ActIntelligentPreferenceBit_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActMLLCPUUSB_put_ActIntelligentPreferenceBit_Proxy( 
    IActMLLCPUUSB __RPC_FAR * This,
    /* [in] */ VARIANT newVal);


void __RPC_STUB IActMLLCPUUSB_put_ActIntelligentPreferenceBit_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActMLLCPUUSB_get_ActDidPropertyBit_Proxy( 
    IActMLLCPUUSB __RPC_FAR * This,
    /* [retval][out] */ VARIANT __RPC_FAR *pVal);


void __RPC_STUB IActMLLCPUUSB_get_ActDidPropertyBit_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActMLLCPUUSB_put_ActDidPropertyBit_Proxy( 
    IActMLLCPUUSB __RPC_FAR * This,
    /* [in] */ VARIANT newVal);


void __RPC_STUB IActMLLCPUUSB_put_ActDidPropertyBit_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActMLLCPUUSB_get_ActDsidPropertyBit_Proxy( 
    IActMLLCPUUSB __RPC_FAR * This,
    /* [retval][out] */ VARIANT __RPC_FAR *pVal);


void __RPC_STUB IActMLLCPUUSB_get_ActDsidPropertyBit_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActMLLCPUUSB_put_ActDsidPropertyBit_Proxy( 
    IActMLLCPUUSB __RPC_FAR * This,
    /* [in] */ VARIANT newVal);


void __RPC_STUB IActMLLCPUUSB_put_ActDsidPropertyBit_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IActMLLCPUUSB_INTERFACE_DEFINED__ */


#ifndef __IActMLLCPUUSB2_INTERFACE_DEFINED__
#define __IActMLLCPUUSB2_INTERFACE_DEFINED__

/* interface IActMLLCPUUSB2 */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IActMLLCPUUSB2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("0CE8E83D-4926-40a3-A232-E62F057D0444")
    IActMLLCPUUSB2 : public IActMLLCPUUSB
    {
    public:
    };
    
#else 	/* C style interface */

    typedef struct IActMLLCPUUSB2Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IActMLLCPUUSB2 __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IActMLLCPUUSB2 __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IActMLLCPUUSB2 __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IActMLLCPUUSB2 __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IActMLLCPUUSB2 __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IActMLLCPUUSB2 __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IActMLLCPUUSB2 __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Open )( 
            IActMLLCPUUSB2 __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Close )( 
            IActMLLCPUUSB2 __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetDevice )( 
            IActMLLCPUUSB2 __RPC_FAR * This,
            /* [in] */ VARIANT varDevice,
            /* [out] */ VARIANT __RPC_FAR *lpvarData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetDevice )( 
            IActMLLCPUUSB2 __RPC_FAR * This,
            /* [in] */ VARIANT varDevice,
            /* [in] */ VARIANT varData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceBlock )( 
            IActMLLCPUUSB2 __RPC_FAR * This,
            /* [in] */ VARIANT varDevice,
            /* [in] */ VARIANT varSize,
            /* [out] */ VARIANT __RPC_FAR *lpvarData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceBlock )( 
            IActMLLCPUUSB2 __RPC_FAR * This,
            /* [in] */ VARIANT varDevice,
            /* [in] */ VARIANT varSize,
            /* [in] */ VARIANT varData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceRandom )( 
            IActMLLCPUUSB2 __RPC_FAR * This,
            /* [in] */ VARIANT varDeviceList,
            /* [in] */ VARIANT varSize,
            /* [out] */ VARIANT __RPC_FAR *lpvarData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceRandom )( 
            IActMLLCPUUSB2 __RPC_FAR * This,
            /* [in] */ VARIANT varDeviceList,
            /* [in] */ VARIANT varSize,
            /* [in] */ VARIANT varData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadBuffer )( 
            IActMLLCPUUSB2 __RPC_FAR * This,
            /* [in] */ VARIANT varStartIO,
            /* [in] */ VARIANT varAddress,
            /* [in] */ VARIANT varReadSize,
            /* [out] */ VARIANT __RPC_FAR *lpvarData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteBuffer )( 
            IActMLLCPUUSB2 __RPC_FAR * This,
            /* [in] */ VARIANT varStartIO,
            /* [in] */ VARIANT varAddress,
            /* [in] */ VARIANT varWriteSize,
            /* [in] */ VARIANT varData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetClockData )( 
            IActMLLCPUUSB2 __RPC_FAR * This,
            /* [out] */ VARIANT __RPC_FAR *lpvarYear,
            /* [out] */ VARIANT __RPC_FAR *lpvarMonth,
            /* [out] */ VARIANT __RPC_FAR *lpvarDay,
            /* [out] */ VARIANT __RPC_FAR *lpvarDayOfWeek,
            /* [out] */ VARIANT __RPC_FAR *lpvarHour,
            /* [out] */ VARIANT __RPC_FAR *lpvarMinute,
            /* [out] */ VARIANT __RPC_FAR *lpvarSecond,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetClockData )( 
            IActMLLCPUUSB2 __RPC_FAR * This,
            /* [in] */ VARIANT varYear,
            /* [in] */ VARIANT varMonth,
            /* [in] */ VARIANT varDay,
            /* [in] */ VARIANT varDayOfWeek,
            /* [in] */ VARIANT varHour,
            /* [in] */ VARIANT varMinute,
            /* [in] */ VARIANT varSecond,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetCpuStatus )( 
            IActMLLCPUUSB2 __RPC_FAR * This,
            /* [in] */ VARIANT varOperation,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetCpuType )( 
            IActMLLCPUUSB2 __RPC_FAR * This,
            /* [out] */ VARIANT __RPC_FAR *lpvarCpuName,
            /* [out] */ VARIANT __RPC_FAR *lpvarCpuType,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *EntryDeviceStatus )( 
            IActMLLCPUUSB2 __RPC_FAR * This,
            /* [in] */ VARIANT varDeviceList,
            /* [in] */ VARIANT varSize,
            /* [in] */ VARIANT varMonitorCycle,
            /* [in] */ VARIANT varData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *FreeDeviceStatus )( 
            IActMLLCPUUSB2 __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceBlock2 )( 
            IActMLLCPUUSB2 __RPC_FAR * This,
            /* [in] */ VARIANT varDevice,
            /* [in] */ VARIANT varSize,
            /* [out] */ VARIANT __RPC_FAR *lpvarData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceBlock2 )( 
            IActMLLCPUUSB2 __RPC_FAR * This,
            /* [in] */ VARIANT varDevice,
            /* [in] */ VARIANT varSize,
            /* [in] */ VARIANT varData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceRandom2 )( 
            IActMLLCPUUSB2 __RPC_FAR * This,
            /* [in] */ VARIANT varDeviceList,
            /* [in] */ VARIANT varSize,
            /* [out] */ VARIANT __RPC_FAR *lpvarData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceRandom2 )( 
            IActMLLCPUUSB2 __RPC_FAR * This,
            /* [in] */ VARIANT varDeviceList,
            /* [in] */ VARIANT varSize,
            /* [in] */ VARIANT varData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetDevice2 )( 
            IActMLLCPUUSB2 __RPC_FAR * This,
            /* [in] */ VARIANT varDevice,
            /* [out] */ VARIANT __RPC_FAR *lpvarData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetDevice2 )( 
            IActMLLCPUUSB2 __RPC_FAR * This,
            /* [in] */ VARIANT varDevice,
            /* [in] */ VARIANT varData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActNetworkNumber )( 
            IActMLLCPUUSB2 __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActNetworkNumber )( 
            IActMLLCPUUSB2 __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActStationNumber )( 
            IActMLLCPUUSB2 __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActStationNumber )( 
            IActMLLCPUUSB2 __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActUnitNumber )( 
            IActMLLCPUUSB2 __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActUnitNumber )( 
            IActMLLCPUUSB2 __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActIONumber )( 
            IActMLLCPUUSB2 __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActIONumber )( 
            IActMLLCPUUSB2 __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActCpuType )( 
            IActMLLCPUUSB2 __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActCpuType )( 
            IActMLLCPUUSB2 __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActTimeOut )( 
            IActMLLCPUUSB2 __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActTimeOut )( 
            IActMLLCPUUSB2 __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActDestinationIONumber )( 
            IActMLLCPUUSB2 __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActDestinationIONumber )( 
            IActMLLCPUUSB2 __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActMultiDropChannelNumber )( 
            IActMLLCPUUSB2 __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActMultiDropChannelNumber )( 
            IActMLLCPUUSB2 __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActThroughNetworkType )( 
            IActMLLCPUUSB2 __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActThroughNetworkType )( 
            IActMLLCPUUSB2 __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActIntelligentPreferenceBit )( 
            IActMLLCPUUSB2 __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActIntelligentPreferenceBit )( 
            IActMLLCPUUSB2 __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActDidPropertyBit )( 
            IActMLLCPUUSB2 __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActDidPropertyBit )( 
            IActMLLCPUUSB2 __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActDsidPropertyBit )( 
            IActMLLCPUUSB2 __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActDsidPropertyBit )( 
            IActMLLCPUUSB2 __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        END_INTERFACE
    } IActMLLCPUUSB2Vtbl;

    interface IActMLLCPUUSB2
    {
        CONST_VTBL struct IActMLLCPUUSB2Vtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IActMLLCPUUSB2_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IActMLLCPUUSB2_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IActMLLCPUUSB2_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IActMLLCPUUSB2_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IActMLLCPUUSB2_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IActMLLCPUUSB2_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IActMLLCPUUSB2_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IActMLLCPUUSB2_Open(This,lpvarReturnCode)	\
    (This)->lpVtbl -> Open(This,lpvarReturnCode)

#define IActMLLCPUUSB2_Close(This,lpvarReturnCode)	\
    (This)->lpVtbl -> Close(This,lpvarReturnCode)

#define IActMLLCPUUSB2_GetDevice(This,varDevice,lpvarData,lpvarReturnCode)	\
    (This)->lpVtbl -> GetDevice(This,varDevice,lpvarData,lpvarReturnCode)

#define IActMLLCPUUSB2_SetDevice(This,varDevice,varData,lpvarReturnCode)	\
    (This)->lpVtbl -> SetDevice(This,varDevice,varData,lpvarReturnCode)

#define IActMLLCPUUSB2_ReadDeviceBlock(This,varDevice,varSize,lpvarData,lpvarReturnCode)	\
    (This)->lpVtbl -> ReadDeviceBlock(This,varDevice,varSize,lpvarData,lpvarReturnCode)

#define IActMLLCPUUSB2_WriteDeviceBlock(This,varDevice,varSize,varData,lpvarReturnCode)	\
    (This)->lpVtbl -> WriteDeviceBlock(This,varDevice,varSize,varData,lpvarReturnCode)

#define IActMLLCPUUSB2_ReadDeviceRandom(This,varDeviceList,varSize,lpvarData,lpvarReturnCode)	\
    (This)->lpVtbl -> ReadDeviceRandom(This,varDeviceList,varSize,lpvarData,lpvarReturnCode)

#define IActMLLCPUUSB2_WriteDeviceRandom(This,varDeviceList,varSize,varData,lpvarReturnCode)	\
    (This)->lpVtbl -> WriteDeviceRandom(This,varDeviceList,varSize,varData,lpvarReturnCode)

#define IActMLLCPUUSB2_ReadBuffer(This,varStartIO,varAddress,varReadSize,lpvarData,lpvarReturnCode)	\
    (This)->lpVtbl -> ReadBuffer(This,varStartIO,varAddress,varReadSize,lpvarData,lpvarReturnCode)

#define IActMLLCPUUSB2_WriteBuffer(This,varStartIO,varAddress,varWriteSize,varData,lpvarReturnCode)	\
    (This)->lpVtbl -> WriteBuffer(This,varStartIO,varAddress,varWriteSize,varData,lpvarReturnCode)

#define IActMLLCPUUSB2_GetClockData(This,lpvarYear,lpvarMonth,lpvarDay,lpvarDayOfWeek,lpvarHour,lpvarMinute,lpvarSecond,lpvarReturnCode)	\
    (This)->lpVtbl -> GetClockData(This,lpvarYear,lpvarMonth,lpvarDay,lpvarDayOfWeek,lpvarHour,lpvarMinute,lpvarSecond,lpvarReturnCode)

#define IActMLLCPUUSB2_SetClockData(This,varYear,varMonth,varDay,varDayOfWeek,varHour,varMinute,varSecond,lpvarReturnCode)	\
    (This)->lpVtbl -> SetClockData(This,varYear,varMonth,varDay,varDayOfWeek,varHour,varMinute,varSecond,lpvarReturnCode)

#define IActMLLCPUUSB2_SetCpuStatus(This,varOperation,lpvarReturnCode)	\
    (This)->lpVtbl -> SetCpuStatus(This,varOperation,lpvarReturnCode)

#define IActMLLCPUUSB2_GetCpuType(This,lpvarCpuName,lpvarCpuType,lpvarReturnCode)	\
    (This)->lpVtbl -> GetCpuType(This,lpvarCpuName,lpvarCpuType,lpvarReturnCode)

#define IActMLLCPUUSB2_EntryDeviceStatus(This,varDeviceList,varSize,varMonitorCycle,varData,lpvarReturnCode)	\
    (This)->lpVtbl -> EntryDeviceStatus(This,varDeviceList,varSize,varMonitorCycle,varData,lpvarReturnCode)

#define IActMLLCPUUSB2_FreeDeviceStatus(This,lpvarReturnCode)	\
    (This)->lpVtbl -> FreeDeviceStatus(This,lpvarReturnCode)

#define IActMLLCPUUSB2_ReadDeviceBlock2(This,varDevice,varSize,lpvarData,lpvarReturnCode)	\
    (This)->lpVtbl -> ReadDeviceBlock2(This,varDevice,varSize,lpvarData,lpvarReturnCode)

#define IActMLLCPUUSB2_WriteDeviceBlock2(This,varDevice,varSize,varData,lpvarReturnCode)	\
    (This)->lpVtbl -> WriteDeviceBlock2(This,varDevice,varSize,varData,lpvarReturnCode)

#define IActMLLCPUUSB2_ReadDeviceRandom2(This,varDeviceList,varSize,lpvarData,lpvarReturnCode)	\
    (This)->lpVtbl -> ReadDeviceRandom2(This,varDeviceList,varSize,lpvarData,lpvarReturnCode)

#define IActMLLCPUUSB2_WriteDeviceRandom2(This,varDeviceList,varSize,varData,lpvarReturnCode)	\
    (This)->lpVtbl -> WriteDeviceRandom2(This,varDeviceList,varSize,varData,lpvarReturnCode)

#define IActMLLCPUUSB2_GetDevice2(This,varDevice,lpvarData,lpvarReturnCode)	\
    (This)->lpVtbl -> GetDevice2(This,varDevice,lpvarData,lpvarReturnCode)

#define IActMLLCPUUSB2_SetDevice2(This,varDevice,varData,lpvarReturnCode)	\
    (This)->lpVtbl -> SetDevice2(This,varDevice,varData,lpvarReturnCode)

#define IActMLLCPUUSB2_get_ActNetworkNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActNetworkNumber(This,pVal)

#define IActMLLCPUUSB2_put_ActNetworkNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActNetworkNumber(This,newVal)

#define IActMLLCPUUSB2_get_ActStationNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActStationNumber(This,pVal)

#define IActMLLCPUUSB2_put_ActStationNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActStationNumber(This,newVal)

#define IActMLLCPUUSB2_get_ActUnitNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActUnitNumber(This,pVal)

#define IActMLLCPUUSB2_put_ActUnitNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActUnitNumber(This,newVal)

#define IActMLLCPUUSB2_get_ActIONumber(This,pVal)	\
    (This)->lpVtbl -> get_ActIONumber(This,pVal)

#define IActMLLCPUUSB2_put_ActIONumber(This,newVal)	\
    (This)->lpVtbl -> put_ActIONumber(This,newVal)

#define IActMLLCPUUSB2_get_ActCpuType(This,pVal)	\
    (This)->lpVtbl -> get_ActCpuType(This,pVal)

#define IActMLLCPUUSB2_put_ActCpuType(This,newVal)	\
    (This)->lpVtbl -> put_ActCpuType(This,newVal)

#define IActMLLCPUUSB2_get_ActTimeOut(This,pVal)	\
    (This)->lpVtbl -> get_ActTimeOut(This,pVal)

#define IActMLLCPUUSB2_put_ActTimeOut(This,newVal)	\
    (This)->lpVtbl -> put_ActTimeOut(This,newVal)

#define IActMLLCPUUSB2_get_ActDestinationIONumber(This,pVal)	\
    (This)->lpVtbl -> get_ActDestinationIONumber(This,pVal)

#define IActMLLCPUUSB2_put_ActDestinationIONumber(This,newVal)	\
    (This)->lpVtbl -> put_ActDestinationIONumber(This,newVal)

#define IActMLLCPUUSB2_get_ActMultiDropChannelNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActMultiDropChannelNumber(This,pVal)

#define IActMLLCPUUSB2_put_ActMultiDropChannelNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActMultiDropChannelNumber(This,newVal)

#define IActMLLCPUUSB2_get_ActThroughNetworkType(This,pVal)	\
    (This)->lpVtbl -> get_ActThroughNetworkType(This,pVal)

#define IActMLLCPUUSB2_put_ActThroughNetworkType(This,newVal)	\
    (This)->lpVtbl -> put_ActThroughNetworkType(This,newVal)

#define IActMLLCPUUSB2_get_ActIntelligentPreferenceBit(This,pVal)	\
    (This)->lpVtbl -> get_ActIntelligentPreferenceBit(This,pVal)

#define IActMLLCPUUSB2_put_ActIntelligentPreferenceBit(This,newVal)	\
    (This)->lpVtbl -> put_ActIntelligentPreferenceBit(This,newVal)

#define IActMLLCPUUSB2_get_ActDidPropertyBit(This,pVal)	\
    (This)->lpVtbl -> get_ActDidPropertyBit(This,pVal)

#define IActMLLCPUUSB2_put_ActDidPropertyBit(This,newVal)	\
    (This)->lpVtbl -> put_ActDidPropertyBit(This,newVal)

#define IActMLLCPUUSB2_get_ActDsidPropertyBit(This,pVal)	\
    (This)->lpVtbl -> get_ActDsidPropertyBit(This,pVal)

#define IActMLLCPUUSB2_put_ActDsidPropertyBit(This,newVal)	\
    (This)->lpVtbl -> put_ActDsidPropertyBit(This,newVal)


#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IActMLLCPUUSB2_INTERFACE_DEFINED__ */


#ifndef __IActMLLCPUUSB3_INTERFACE_DEFINED__
#define __IActMLLCPUUSB3_INTERFACE_DEFINED__

/* interface IActMLLCPUUSB3 */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IActMLLCPUUSB3;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("8B65574B-1985-4366-A5EB-B4790B7C6285")
    IActMLLCPUUSB3 : public IActMLLCPUUSB2
    {
    public:
    };
    
#else 	/* C style interface */

    typedef struct IActMLLCPUUSB3Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IActMLLCPUUSB3 __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IActMLLCPUUSB3 __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IActMLLCPUUSB3 __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IActMLLCPUUSB3 __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IActMLLCPUUSB3 __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IActMLLCPUUSB3 __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IActMLLCPUUSB3 __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Open )( 
            IActMLLCPUUSB3 __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Close )( 
            IActMLLCPUUSB3 __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetDevice )( 
            IActMLLCPUUSB3 __RPC_FAR * This,
            /* [in] */ VARIANT varDevice,
            /* [out] */ VARIANT __RPC_FAR *lpvarData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetDevice )( 
            IActMLLCPUUSB3 __RPC_FAR * This,
            /* [in] */ VARIANT varDevice,
            /* [in] */ VARIANT varData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceBlock )( 
            IActMLLCPUUSB3 __RPC_FAR * This,
            /* [in] */ VARIANT varDevice,
            /* [in] */ VARIANT varSize,
            /* [out] */ VARIANT __RPC_FAR *lpvarData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceBlock )( 
            IActMLLCPUUSB3 __RPC_FAR * This,
            /* [in] */ VARIANT varDevice,
            /* [in] */ VARIANT varSize,
            /* [in] */ VARIANT varData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceRandom )( 
            IActMLLCPUUSB3 __RPC_FAR * This,
            /* [in] */ VARIANT varDeviceList,
            /* [in] */ VARIANT varSize,
            /* [out] */ VARIANT __RPC_FAR *lpvarData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceRandom )( 
            IActMLLCPUUSB3 __RPC_FAR * This,
            /* [in] */ VARIANT varDeviceList,
            /* [in] */ VARIANT varSize,
            /* [in] */ VARIANT varData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadBuffer )( 
            IActMLLCPUUSB3 __RPC_FAR * This,
            /* [in] */ VARIANT varStartIO,
            /* [in] */ VARIANT varAddress,
            /* [in] */ VARIANT varReadSize,
            /* [out] */ VARIANT __RPC_FAR *lpvarData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteBuffer )( 
            IActMLLCPUUSB3 __RPC_FAR * This,
            /* [in] */ VARIANT varStartIO,
            /* [in] */ VARIANT varAddress,
            /* [in] */ VARIANT varWriteSize,
            /* [in] */ VARIANT varData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetClockData )( 
            IActMLLCPUUSB3 __RPC_FAR * This,
            /* [out] */ VARIANT __RPC_FAR *lpvarYear,
            /* [out] */ VARIANT __RPC_FAR *lpvarMonth,
            /* [out] */ VARIANT __RPC_FAR *lpvarDay,
            /* [out] */ VARIANT __RPC_FAR *lpvarDayOfWeek,
            /* [out] */ VARIANT __RPC_FAR *lpvarHour,
            /* [out] */ VARIANT __RPC_FAR *lpvarMinute,
            /* [out] */ VARIANT __RPC_FAR *lpvarSecond,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetClockData )( 
            IActMLLCPUUSB3 __RPC_FAR * This,
            /* [in] */ VARIANT varYear,
            /* [in] */ VARIANT varMonth,
            /* [in] */ VARIANT varDay,
            /* [in] */ VARIANT varDayOfWeek,
            /* [in] */ VARIANT varHour,
            /* [in] */ VARIANT varMinute,
            /* [in] */ VARIANT varSecond,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetCpuStatus )( 
            IActMLLCPUUSB3 __RPC_FAR * This,
            /* [in] */ VARIANT varOperation,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetCpuType )( 
            IActMLLCPUUSB3 __RPC_FAR * This,
            /* [out] */ VARIANT __RPC_FAR *lpvarCpuName,
            /* [out] */ VARIANT __RPC_FAR *lpvarCpuType,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *EntryDeviceStatus )( 
            IActMLLCPUUSB3 __RPC_FAR * This,
            /* [in] */ VARIANT varDeviceList,
            /* [in] */ VARIANT varSize,
            /* [in] */ VARIANT varMonitorCycle,
            /* [in] */ VARIANT varData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *FreeDeviceStatus )( 
            IActMLLCPUUSB3 __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceBlock2 )( 
            IActMLLCPUUSB3 __RPC_FAR * This,
            /* [in] */ VARIANT varDevice,
            /* [in] */ VARIANT varSize,
            /* [out] */ VARIANT __RPC_FAR *lpvarData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceBlock2 )( 
            IActMLLCPUUSB3 __RPC_FAR * This,
            /* [in] */ VARIANT varDevice,
            /* [in] */ VARIANT varSize,
            /* [in] */ VARIANT varData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceRandom2 )( 
            IActMLLCPUUSB3 __RPC_FAR * This,
            /* [in] */ VARIANT varDeviceList,
            /* [in] */ VARIANT varSize,
            /* [out] */ VARIANT __RPC_FAR *lpvarData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceRandom2 )( 
            IActMLLCPUUSB3 __RPC_FAR * This,
            /* [in] */ VARIANT varDeviceList,
            /* [in] */ VARIANT varSize,
            /* [in] */ VARIANT varData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetDevice2 )( 
            IActMLLCPUUSB3 __RPC_FAR * This,
            /* [in] */ VARIANT varDevice,
            /* [out] */ VARIANT __RPC_FAR *lpvarData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetDevice2 )( 
            IActMLLCPUUSB3 __RPC_FAR * This,
            /* [in] */ VARIANT varDevice,
            /* [in] */ VARIANT varData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActNetworkNumber )( 
            IActMLLCPUUSB3 __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActNetworkNumber )( 
            IActMLLCPUUSB3 __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActStationNumber )( 
            IActMLLCPUUSB3 __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActStationNumber )( 
            IActMLLCPUUSB3 __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActUnitNumber )( 
            IActMLLCPUUSB3 __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActUnitNumber )( 
            IActMLLCPUUSB3 __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActIONumber )( 
            IActMLLCPUUSB3 __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActIONumber )( 
            IActMLLCPUUSB3 __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActCpuType )( 
            IActMLLCPUUSB3 __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActCpuType )( 
            IActMLLCPUUSB3 __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActTimeOut )( 
            IActMLLCPUUSB3 __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActTimeOut )( 
            IActMLLCPUUSB3 __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActDestinationIONumber )( 
            IActMLLCPUUSB3 __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActDestinationIONumber )( 
            IActMLLCPUUSB3 __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActMultiDropChannelNumber )( 
            IActMLLCPUUSB3 __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActMultiDropChannelNumber )( 
            IActMLLCPUUSB3 __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActThroughNetworkType )( 
            IActMLLCPUUSB3 __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActThroughNetworkType )( 
            IActMLLCPUUSB3 __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActIntelligentPreferenceBit )( 
            IActMLLCPUUSB3 __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActIntelligentPreferenceBit )( 
            IActMLLCPUUSB3 __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActDidPropertyBit )( 
            IActMLLCPUUSB3 __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActDidPropertyBit )( 
            IActMLLCPUUSB3 __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActDsidPropertyBit )( 
            IActMLLCPUUSB3 __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActDsidPropertyBit )( 
            IActMLLCPUUSB3 __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        END_INTERFACE
    } IActMLLCPUUSB3Vtbl;

    interface IActMLLCPUUSB3
    {
        CONST_VTBL struct IActMLLCPUUSB3Vtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IActMLLCPUUSB3_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IActMLLCPUUSB3_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IActMLLCPUUSB3_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IActMLLCPUUSB3_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IActMLLCPUUSB3_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IActMLLCPUUSB3_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IActMLLCPUUSB3_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IActMLLCPUUSB3_Open(This,lpvarReturnCode)	\
    (This)->lpVtbl -> Open(This,lpvarReturnCode)

#define IActMLLCPUUSB3_Close(This,lpvarReturnCode)	\
    (This)->lpVtbl -> Close(This,lpvarReturnCode)

#define IActMLLCPUUSB3_GetDevice(This,varDevice,lpvarData,lpvarReturnCode)	\
    (This)->lpVtbl -> GetDevice(This,varDevice,lpvarData,lpvarReturnCode)

#define IActMLLCPUUSB3_SetDevice(This,varDevice,varData,lpvarReturnCode)	\
    (This)->lpVtbl -> SetDevice(This,varDevice,varData,lpvarReturnCode)

#define IActMLLCPUUSB3_ReadDeviceBlock(This,varDevice,varSize,lpvarData,lpvarReturnCode)	\
    (This)->lpVtbl -> ReadDeviceBlock(This,varDevice,varSize,lpvarData,lpvarReturnCode)

#define IActMLLCPUUSB3_WriteDeviceBlock(This,varDevice,varSize,varData,lpvarReturnCode)	\
    (This)->lpVtbl -> WriteDeviceBlock(This,varDevice,varSize,varData,lpvarReturnCode)

#define IActMLLCPUUSB3_ReadDeviceRandom(This,varDeviceList,varSize,lpvarData,lpvarReturnCode)	\
    (This)->lpVtbl -> ReadDeviceRandom(This,varDeviceList,varSize,lpvarData,lpvarReturnCode)

#define IActMLLCPUUSB3_WriteDeviceRandom(This,varDeviceList,varSize,varData,lpvarReturnCode)	\
    (This)->lpVtbl -> WriteDeviceRandom(This,varDeviceList,varSize,varData,lpvarReturnCode)

#define IActMLLCPUUSB3_ReadBuffer(This,varStartIO,varAddress,varReadSize,lpvarData,lpvarReturnCode)	\
    (This)->lpVtbl -> ReadBuffer(This,varStartIO,varAddress,varReadSize,lpvarData,lpvarReturnCode)

#define IActMLLCPUUSB3_WriteBuffer(This,varStartIO,varAddress,varWriteSize,varData,lpvarReturnCode)	\
    (This)->lpVtbl -> WriteBuffer(This,varStartIO,varAddress,varWriteSize,varData,lpvarReturnCode)

#define IActMLLCPUUSB3_GetClockData(This,lpvarYear,lpvarMonth,lpvarDay,lpvarDayOfWeek,lpvarHour,lpvarMinute,lpvarSecond,lpvarReturnCode)	\
    (This)->lpVtbl -> GetClockData(This,lpvarYear,lpvarMonth,lpvarDay,lpvarDayOfWeek,lpvarHour,lpvarMinute,lpvarSecond,lpvarReturnCode)

#define IActMLLCPUUSB3_SetClockData(This,varYear,varMonth,varDay,varDayOfWeek,varHour,varMinute,varSecond,lpvarReturnCode)	\
    (This)->lpVtbl -> SetClockData(This,varYear,varMonth,varDay,varDayOfWeek,varHour,varMinute,varSecond,lpvarReturnCode)

#define IActMLLCPUUSB3_SetCpuStatus(This,varOperation,lpvarReturnCode)	\
    (This)->lpVtbl -> SetCpuStatus(This,varOperation,lpvarReturnCode)

#define IActMLLCPUUSB3_GetCpuType(This,lpvarCpuName,lpvarCpuType,lpvarReturnCode)	\
    (This)->lpVtbl -> GetCpuType(This,lpvarCpuName,lpvarCpuType,lpvarReturnCode)

#define IActMLLCPUUSB3_EntryDeviceStatus(This,varDeviceList,varSize,varMonitorCycle,varData,lpvarReturnCode)	\
    (This)->lpVtbl -> EntryDeviceStatus(This,varDeviceList,varSize,varMonitorCycle,varData,lpvarReturnCode)

#define IActMLLCPUUSB3_FreeDeviceStatus(This,lpvarReturnCode)	\
    (This)->lpVtbl -> FreeDeviceStatus(This,lpvarReturnCode)

#define IActMLLCPUUSB3_ReadDeviceBlock2(This,varDevice,varSize,lpvarData,lpvarReturnCode)	\
    (This)->lpVtbl -> ReadDeviceBlock2(This,varDevice,varSize,lpvarData,lpvarReturnCode)

#define IActMLLCPUUSB3_WriteDeviceBlock2(This,varDevice,varSize,varData,lpvarReturnCode)	\
    (This)->lpVtbl -> WriteDeviceBlock2(This,varDevice,varSize,varData,lpvarReturnCode)

#define IActMLLCPUUSB3_ReadDeviceRandom2(This,varDeviceList,varSize,lpvarData,lpvarReturnCode)	\
    (This)->lpVtbl -> ReadDeviceRandom2(This,varDeviceList,varSize,lpvarData,lpvarReturnCode)

#define IActMLLCPUUSB3_WriteDeviceRandom2(This,varDeviceList,varSize,varData,lpvarReturnCode)	\
    (This)->lpVtbl -> WriteDeviceRandom2(This,varDeviceList,varSize,varData,lpvarReturnCode)

#define IActMLLCPUUSB3_GetDevice2(This,varDevice,lpvarData,lpvarReturnCode)	\
    (This)->lpVtbl -> GetDevice2(This,varDevice,lpvarData,lpvarReturnCode)

#define IActMLLCPUUSB3_SetDevice2(This,varDevice,varData,lpvarReturnCode)	\
    (This)->lpVtbl -> SetDevice2(This,varDevice,varData,lpvarReturnCode)

#define IActMLLCPUUSB3_get_ActNetworkNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActNetworkNumber(This,pVal)

#define IActMLLCPUUSB3_put_ActNetworkNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActNetworkNumber(This,newVal)

#define IActMLLCPUUSB3_get_ActStationNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActStationNumber(This,pVal)

#define IActMLLCPUUSB3_put_ActStationNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActStationNumber(This,newVal)

#define IActMLLCPUUSB3_get_ActUnitNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActUnitNumber(This,pVal)

#define IActMLLCPUUSB3_put_ActUnitNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActUnitNumber(This,newVal)

#define IActMLLCPUUSB3_get_ActIONumber(This,pVal)	\
    (This)->lpVtbl -> get_ActIONumber(This,pVal)

#define IActMLLCPUUSB3_put_ActIONumber(This,newVal)	\
    (This)->lpVtbl -> put_ActIONumber(This,newVal)

#define IActMLLCPUUSB3_get_ActCpuType(This,pVal)	\
    (This)->lpVtbl -> get_ActCpuType(This,pVal)

#define IActMLLCPUUSB3_put_ActCpuType(This,newVal)	\
    (This)->lpVtbl -> put_ActCpuType(This,newVal)

#define IActMLLCPUUSB3_get_ActTimeOut(This,pVal)	\
    (This)->lpVtbl -> get_ActTimeOut(This,pVal)

#define IActMLLCPUUSB3_put_ActTimeOut(This,newVal)	\
    (This)->lpVtbl -> put_ActTimeOut(This,newVal)

#define IActMLLCPUUSB3_get_ActDestinationIONumber(This,pVal)	\
    (This)->lpVtbl -> get_ActDestinationIONumber(This,pVal)

#define IActMLLCPUUSB3_put_ActDestinationIONumber(This,newVal)	\
    (This)->lpVtbl -> put_ActDestinationIONumber(This,newVal)

#define IActMLLCPUUSB3_get_ActMultiDropChannelNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActMultiDropChannelNumber(This,pVal)

#define IActMLLCPUUSB3_put_ActMultiDropChannelNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActMultiDropChannelNumber(This,newVal)

#define IActMLLCPUUSB3_get_ActThroughNetworkType(This,pVal)	\
    (This)->lpVtbl -> get_ActThroughNetworkType(This,pVal)

#define IActMLLCPUUSB3_put_ActThroughNetworkType(This,newVal)	\
    (This)->lpVtbl -> put_ActThroughNetworkType(This,newVal)

#define IActMLLCPUUSB3_get_ActIntelligentPreferenceBit(This,pVal)	\
    (This)->lpVtbl -> get_ActIntelligentPreferenceBit(This,pVal)

#define IActMLLCPUUSB3_put_ActIntelligentPreferenceBit(This,newVal)	\
    (This)->lpVtbl -> put_ActIntelligentPreferenceBit(This,newVal)

#define IActMLLCPUUSB3_get_ActDidPropertyBit(This,pVal)	\
    (This)->lpVtbl -> get_ActDidPropertyBit(This,pVal)

#define IActMLLCPUUSB3_put_ActDidPropertyBit(This,newVal)	\
    (This)->lpVtbl -> put_ActDidPropertyBit(This,newVal)

#define IActMLLCPUUSB3_get_ActDsidPropertyBit(This,pVal)	\
    (This)->lpVtbl -> get_ActDsidPropertyBit(This,pVal)

#define IActMLLCPUUSB3_put_ActDsidPropertyBit(This,newVal)	\
    (This)->lpVtbl -> put_ActDsidPropertyBit(This,newVal)



#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IActMLLCPUUSB3_INTERFACE_DEFINED__ */



#ifndef __ACTPCUSBLib_LIBRARY_DEFINED__
#define __ACTPCUSBLib_LIBRARY_DEFINED__

/* library ACTPCUSBLib */
/* [helpstring][version][uuid] */ 


EXTERN_C const IID LIBID_ACTPCUSBLib;

#ifndef ___IActQCPUQUSBEvents_DISPINTERFACE_DEFINED__
#define ___IActQCPUQUSBEvents_DISPINTERFACE_DEFINED__

/* dispinterface _IActQCPUQUSBEvents */
/* [helpstring][uuid] */ 


EXTERN_C const IID DIID__IActQCPUQUSBEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("B5BDE863-AEA9-11D3-83AE-00A024BDBF2B")
    _IActQCPUQUSBEvents : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct _IActQCPUQUSBEventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            _IActQCPUQUSBEvents __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            _IActQCPUQUSBEvents __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            _IActQCPUQUSBEvents __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            _IActQCPUQUSBEvents __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            _IActQCPUQUSBEvents __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            _IActQCPUQUSBEvents __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            _IActQCPUQUSBEvents __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        END_INTERFACE
    } _IActQCPUQUSBEventsVtbl;

    interface _IActQCPUQUSBEvents
    {
        CONST_VTBL struct _IActQCPUQUSBEventsVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _IActQCPUQUSBEvents_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define _IActQCPUQUSBEvents_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define _IActQCPUQUSBEvents_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define _IActQCPUQUSBEvents_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define _IActQCPUQUSBEvents_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define _IActQCPUQUSBEvents_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define _IActQCPUQUSBEvents_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ___IActQCPUQUSBEvents_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_ActQCPUQUSB;

#ifdef __cplusplus

class DECLSPEC_UUID("B5BDE862-AEA9-11D3-83AE-00A024BDBF2B")
ActQCPUQUSB;
#endif

#ifndef ___IActMLQCPUQUSBEvents_DISPINTERFACE_DEFINED__
#define ___IActMLQCPUQUSBEvents_DISPINTERFACE_DEFINED__

/* dispinterface _IActMLQCPUQUSBEvents */
/* [helpstring][uuid] */ 


EXTERN_C const IID DIID__IActMLQCPUQUSBEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("95969873-A954-11D4-910D-009099244EFD")
    _IActMLQCPUQUSBEvents : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct _IActMLQCPUQUSBEventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            _IActMLQCPUQUSBEvents __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            _IActMLQCPUQUSBEvents __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            _IActMLQCPUQUSBEvents __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            _IActMLQCPUQUSBEvents __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            _IActMLQCPUQUSBEvents __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            _IActMLQCPUQUSBEvents __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            _IActMLQCPUQUSBEvents __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        END_INTERFACE
    } _IActMLQCPUQUSBEventsVtbl;

    interface _IActMLQCPUQUSBEvents
    {
        CONST_VTBL struct _IActMLQCPUQUSBEventsVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _IActMLQCPUQUSBEvents_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define _IActMLQCPUQUSBEvents_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define _IActMLQCPUQUSBEvents_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define _IActMLQCPUQUSBEvents_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define _IActMLQCPUQUSBEvents_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define _IActMLQCPUQUSBEvents_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define _IActMLQCPUQUSBEvents_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ___IActMLQCPUQUSBEvents_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_ActMLQCPUQUSB;

#ifdef __cplusplus

class DECLSPEC_UUID("95969872-A954-11D4-910D-009099244EFD")
ActMLQCPUQUSB;
#endif

#ifndef ___IActFXCPUUSBEvents_DISPINTERFACE_DEFINED__
#define ___IActFXCPUUSBEvents_DISPINTERFACE_DEFINED__

/* dispinterface _IActFXCPUUSBEvents */
/* [helpstring][uuid] */ 


EXTERN_C const IID DIID__IActFXCPUUSBEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("9656AF89-CD33-4C7C-A65D-DE68EF4F9717")
    _IActFXCPUUSBEvents : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct _IActFXCPUUSBEventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            _IActFXCPUUSBEvents __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            _IActFXCPUUSBEvents __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            _IActFXCPUUSBEvents __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            _IActFXCPUUSBEvents __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            _IActFXCPUUSBEvents __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            _IActFXCPUUSBEvents __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            _IActFXCPUUSBEvents __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        END_INTERFACE
    } _IActFXCPUUSBEventsVtbl;

    interface _IActFXCPUUSBEvents
    {
        CONST_VTBL struct _IActFXCPUUSBEventsVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _IActFXCPUUSBEvents_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define _IActFXCPUUSBEvents_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define _IActFXCPUUSBEvents_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define _IActFXCPUUSBEvents_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define _IActFXCPUUSBEvents_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define _IActFXCPUUSBEvents_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define _IActFXCPUUSBEvents_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ___IActFXCPUUSBEvents_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_ActFXCPUUSB;

#ifdef __cplusplus

class DECLSPEC_UUID("0FE3736A-155A-492D-925B-B1B11AC4A26C")
ActFXCPUUSB;
#endif

#ifndef ___IActMLFXCPUUSBEvents_DISPINTERFACE_DEFINED__
#define ___IActMLFXCPUUSBEvents_DISPINTERFACE_DEFINED__

/* dispinterface _IActMLFXCPUUSBEvents */
/* [helpstring][uuid] */ 


EXTERN_C const IID DIID__IActMLFXCPUUSBEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("B30DA6C5-8EDC-40C0-B3D3-F7C95A161CDC")
    _IActMLFXCPUUSBEvents : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct _IActMLFXCPUUSBEventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            _IActMLFXCPUUSBEvents __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            _IActMLFXCPUUSBEvents __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            _IActMLFXCPUUSBEvents __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            _IActMLFXCPUUSBEvents __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            _IActMLFXCPUUSBEvents __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            _IActMLFXCPUUSBEvents __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            _IActMLFXCPUUSBEvents __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        END_INTERFACE
    } _IActMLFXCPUUSBEventsVtbl;

    interface _IActMLFXCPUUSBEvents
    {
        CONST_VTBL struct _IActMLFXCPUUSBEventsVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _IActMLFXCPUUSBEvents_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define _IActMLFXCPUUSBEvents_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define _IActMLFXCPUUSBEvents_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define _IActMLFXCPUUSBEvents_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define _IActMLFXCPUUSBEvents_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define _IActMLFXCPUUSBEvents_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define _IActMLFXCPUUSBEvents_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ___IActMLFXCPUUSBEvents_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_ActMLFXCPUUSB;

#ifdef __cplusplus

class DECLSPEC_UUID("2F977269-EF63-448E-B497-559CA366C1E0")
ActMLFXCPUUSB;
#endif

#ifndef ___IActLCPUUSBEvents_DISPINTERFACE_DEFINED__
#define ___IActLCPUUSBEvents_DISPINTERFACE_DEFINED__

/* dispinterface _IActLCPUUSBEvents */
/* [helpstring][uuid] */ 


EXTERN_C const IID DIID__IActLCPUUSBEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("F8C63632-0733-49D8-9349-5EAA8CCEA0AF")
    _IActLCPUUSBEvents : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct _IActLCPUUSBEventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            _IActLCPUUSBEvents __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            _IActLCPUUSBEvents __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            _IActLCPUUSBEvents __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            _IActLCPUUSBEvents __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            _IActLCPUUSBEvents __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            _IActLCPUUSBEvents __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            _IActLCPUUSBEvents __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        END_INTERFACE
    } _IActLCPUUSBEventsVtbl;

    interface _IActLCPUUSBEvents
    {
        CONST_VTBL struct _IActLCPUUSBEventsVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _IActLCPUUSBEvents_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define _IActLCPUUSBEvents_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define _IActLCPUUSBEvents_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define _IActLCPUUSBEvents_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define _IActLCPUUSBEvents_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define _IActLCPUUSBEvents_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define _IActLCPUUSBEvents_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ___IActLCPUUSBEvents_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_ActLCPUUSB;

#ifdef __cplusplus

class DECLSPEC_UUID("514DEE9A-C6F7-46FD-A359-1322DF4D28F3")
ActLCPUUSB;
#endif

#ifndef ___IActMLLCPUUSBEvents_DISPINTERFACE_DEFINED__
#define ___IActMLLCPUUSBEvents_DISPINTERFACE_DEFINED__

/* dispinterface _IActMLLCPUUSBEvents */
/* [helpstring][uuid] */ 


EXTERN_C const IID DIID__IActMLLCPUUSBEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("58B74969-0C83-4421-9BA8-11D1397B84FD")
    _IActMLLCPUUSBEvents : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct _IActMLLCPUUSBEventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            _IActMLLCPUUSBEvents __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            _IActMLLCPUUSBEvents __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            _IActMLLCPUUSBEvents __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            _IActMLLCPUUSBEvents __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            _IActMLLCPUUSBEvents __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            _IActMLLCPUUSBEvents __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            _IActMLLCPUUSBEvents __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        END_INTERFACE
    } _IActMLLCPUUSBEventsVtbl;

    interface _IActMLLCPUUSBEvents
    {
        CONST_VTBL struct _IActMLLCPUUSBEventsVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _IActMLLCPUUSBEvents_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define _IActMLLCPUUSBEvents_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define _IActMLLCPUUSBEvents_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define _IActMLLCPUUSBEvents_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define _IActMLLCPUUSBEvents_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define _IActMLLCPUUSBEvents_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define _IActMLLCPUUSBEvents_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ___IActMLLCPUUSBEvents_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_ActMLLCPUUSB;

#ifdef __cplusplus

class DECLSPEC_UUID("BAE3FB8D-3A50-4AFB-912A-0037F45374FD")
ActMLLCPUUSB;
#endif
#endif /* __ACTPCUSBLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

unsigned long             __RPC_USER  BSTR_UserSize(     unsigned long __RPC_FAR *, unsigned long            , BSTR __RPC_FAR * ); 
unsigned char __RPC_FAR * __RPC_USER  BSTR_UserMarshal(  unsigned long __RPC_FAR *, unsigned char __RPC_FAR *, BSTR __RPC_FAR * ); 
unsigned char __RPC_FAR * __RPC_USER  BSTR_UserUnmarshal(unsigned long __RPC_FAR *, unsigned char __RPC_FAR *, BSTR __RPC_FAR * ); 
void                      __RPC_USER  BSTR_UserFree(     unsigned long __RPC_FAR *, BSTR __RPC_FAR * ); 

unsigned long             __RPC_USER  VARIANT_UserSize(     unsigned long __RPC_FAR *, unsigned long            , VARIANT __RPC_FAR * ); 
unsigned char __RPC_FAR * __RPC_USER  VARIANT_UserMarshal(  unsigned long __RPC_FAR *, unsigned char __RPC_FAR *, VARIANT __RPC_FAR * ); 
unsigned char __RPC_FAR * __RPC_USER  VARIANT_UserUnmarshal(unsigned long __RPC_FAR *, unsigned char __RPC_FAR *, VARIANT __RPC_FAR * ); 
void                      __RPC_USER  VARIANT_UserFree(     unsigned long __RPC_FAR *, VARIANT __RPC_FAR * ); 

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif
