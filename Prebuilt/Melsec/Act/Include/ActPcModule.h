/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 5.01.0164 */
/* at Fri Apr 12 12:32:48 2013
 */
/* Compiler settings for D:\GETMODULE\CommunicationSupport2\SW3D5\ACT\Control\ActPcModule\ActPcModule.idl:
    Os (OptLev=s), W1, Zp8, env=Win32, ms_ext, c_ext
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

#ifndef __ActPcModule_h__
#define __ActPcModule_h__

#ifdef __cplusplus
extern "C"{
#endif 

/* Forward Declarations */ 

#ifndef __IActQCPUQBus_FWD_DEFINED__
#define __IActQCPUQBus_FWD_DEFINED__
typedef interface IActQCPUQBus IActQCPUQBus;
#endif 	/* __IActQCPUQBus_FWD_DEFINED__ */


#ifndef __IActQCPUQBus2_FWD_DEFINED__
#define __IActQCPUQBus2_FWD_DEFINED__
typedef interface IActQCPUQBus2 IActQCPUQBus2;
#endif 	/* __IActQCPUQBus2_FWD_DEFINED__ */


#ifndef __IActQCPUQBus3_FWD_DEFINED__
#define __IActQCPUQBus3_FWD_DEFINED__
typedef interface IActQCPUQBus3 IActQCPUQBus3;
#endif 	/* __IActQCPUQBus3_FWD_DEFINED__ */


#ifndef __IActMLQCPUQBus_FWD_DEFINED__
#define __IActMLQCPUQBus_FWD_DEFINED__
typedef interface IActMLQCPUQBus IActMLQCPUQBus;
#endif 	/* __IActMLQCPUQBus_FWD_DEFINED__ */


#ifndef __IActMLQCPUQBus2_FWD_DEFINED__
#define __IActMLQCPUQBus2_FWD_DEFINED__
typedef interface IActMLQCPUQBus2 IActMLQCPUQBus2;
#endif 	/* __IActMLQCPUQBus2_FWD_DEFINED__ */


#ifndef __IActMLQCPUQBus3_FWD_DEFINED__
#define __IActMLQCPUQBus3_FWD_DEFINED__
typedef interface IActMLQCPUQBus3 IActMLQCPUQBus3;
#endif 	/* __IActMLQCPUQBus3_FWD_DEFINED__ */


#ifndef __IActQSS_FWD_DEFINED__
#define __IActQSS_FWD_DEFINED__
typedef interface IActQSS IActQSS;
#endif 	/* __IActQSS_FWD_DEFINED__ */


#ifndef __IActQSS2_FWD_DEFINED__
#define __IActQSS2_FWD_DEFINED__
typedef interface IActQSS2 IActQSS2;
#endif 	/* __IActQSS2_FWD_DEFINED__ */


#ifndef __IActQSS3_FWD_DEFINED__
#define __IActQSS3_FWD_DEFINED__
typedef interface IActQSS3 IActQSS3;
#endif 	/* __IActQSS3_FWD_DEFINED__ */


#ifndef __IActMLQSS_FWD_DEFINED__
#define __IActMLQSS_FWD_DEFINED__
typedef interface IActMLQSS IActMLQSS;
#endif 	/* __IActMLQSS_FWD_DEFINED__ */


#ifndef __IActMLQSS2_FWD_DEFINED__
#define __IActMLQSS2_FWD_DEFINED__
typedef interface IActMLQSS2 IActMLQSS2;
#endif 	/* __IActMLQSS2_FWD_DEFINED__ */


#ifndef __IActMLQSS3_FWD_DEFINED__
#define __IActMLQSS3_FWD_DEFINED__
typedef interface IActMLQSS3 IActMLQSS3;
#endif 	/* __IActMLQSS3_FWD_DEFINED__ */


#ifndef ___IActQCPUQBusEvents_FWD_DEFINED__
#define ___IActQCPUQBusEvents_FWD_DEFINED__
typedef interface _IActQCPUQBusEvents _IActQCPUQBusEvents;
#endif 	/* ___IActQCPUQBusEvents_FWD_DEFINED__ */


#ifndef __ActQCPUQBus_FWD_DEFINED__
#define __ActQCPUQBus_FWD_DEFINED__

#ifdef __cplusplus
typedef class ActQCPUQBus ActQCPUQBus;
#else
typedef struct ActQCPUQBus ActQCPUQBus;
#endif /* __cplusplus */

#endif 	/* __ActQCPUQBus_FWD_DEFINED__ */


#ifndef ___IActMLQCPUQBusEvents_FWD_DEFINED__
#define ___IActMLQCPUQBusEvents_FWD_DEFINED__
typedef interface _IActMLQCPUQBusEvents _IActMLQCPUQBusEvents;
#endif 	/* ___IActMLQCPUQBusEvents_FWD_DEFINED__ */


#ifndef __ActMLQCPUQBus_FWD_DEFINED__
#define __ActMLQCPUQBus_FWD_DEFINED__

#ifdef __cplusplus
typedef class ActMLQCPUQBus ActMLQCPUQBus;
#else
typedef struct ActMLQCPUQBus ActMLQCPUQBus;
#endif /* __cplusplus */

#endif 	/* __ActMLQCPUQBus_FWD_DEFINED__ */


#ifndef ___IActQSSEvents_FWD_DEFINED__
#define ___IActQSSEvents_FWD_DEFINED__
typedef interface _IActQSSEvents _IActQSSEvents;
#endif 	/* ___IActQSSEvents_FWD_DEFINED__ */


#ifndef __ActQSS_FWD_DEFINED__
#define __ActQSS_FWD_DEFINED__

#ifdef __cplusplus
typedef class ActQSS ActQSS;
#else
typedef struct ActQSS ActQSS;
#endif /* __cplusplus */

#endif 	/* __ActQSS_FWD_DEFINED__ */


#ifndef ___IActMLQSSEvents_FWD_DEFINED__
#define ___IActMLQSSEvents_FWD_DEFINED__
typedef interface _IActMLQSSEvents _IActMLQSSEvents;
#endif 	/* ___IActMLQSSEvents_FWD_DEFINED__ */


#ifndef __ActMLQSS_FWD_DEFINED__
#define __ActMLQSS_FWD_DEFINED__

#ifdef __cplusplus
typedef class ActMLQSS ActMLQSS;
#else
typedef struct ActMLQSS ActMLQSS;
#endif /* __cplusplus */

#endif 	/* __ActMLQSS_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

void __RPC_FAR * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void __RPC_FAR * ); 

#ifndef __IActQCPUQBus_INTERFACE_DEFINED__
#define __IActQCPUQBus_INTERFACE_DEFINED__

/* interface IActQCPUQBus */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IActQCPUQBus;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("062B9B56-AA34-11D4-910F-009099244EFD")
    IActQCPUQBus : public IDispatch
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
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActIONumber( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActIONumber( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActCpuType( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActCpuType( 
            /* [in] */ long newVal) = 0;
        
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
        
    };
    
#else 	/* C style interface */

    typedef struct IActQCPUQBusVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IActQCPUQBus __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IActQCPUQBus __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IActQCPUQBus __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IActQCPUQBus __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IActQCPUQBus __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IActQCPUQBus __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IActQCPUQBus __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Open )( 
            IActQCPUQBus __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Close )( 
            IActQCPUQBus __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetDevice )( 
            IActQCPUQBus __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [out] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetDevice )( 
            IActQCPUQBus __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceBlock )( 
            IActQCPUQBus __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lSize,
            /* [size_is][out] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceBlock )( 
            IActQCPUQBus __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lSize,
            /* [size_is][in] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceRandom )( 
            IActQCPUQBus __RPC_FAR * This,
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG lSize,
            /* [size_is][out] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceRandom )( 
            IActQCPUQBus __RPC_FAR * This,
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG lSize,
            /* [size_is][in] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadBuffer )( 
            IActQCPUQBus __RPC_FAR * This,
            /* [in] */ LONG lStartIO,
            /* [in] */ LONG lAddress,
            /* [in] */ LONG lReadSize,
            /* [size_is][out] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteBuffer )( 
            IActQCPUQBus __RPC_FAR * This,
            /* [in] */ LONG lStartIO,
            /* [in] */ LONG lAddress,
            /* [in] */ LONG lWriteSize,
            /* [size_is][in] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetCpuType )( 
            IActQCPUQBus __RPC_FAR * This,
            /* [string][out] */ BSTR __RPC_FAR *szCpuName,
            /* [out] */ LONG __RPC_FAR *lplCpuCode,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetCpuStatus )( 
            IActQCPUQBus __RPC_FAR * This,
            /* [in] */ LONG lOperation,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetClockData )( 
            IActQCPUQBus __RPC_FAR * This,
            /* [out] */ SHORT __RPC_FAR *lpsYear,
            /* [out] */ SHORT __RPC_FAR *lpsMonth,
            /* [out] */ SHORT __RPC_FAR *lpsDay,
            /* [out] */ SHORT __RPC_FAR *lpsDayOfWeek,
            /* [out] */ SHORT __RPC_FAR *lpsHour,
            /* [out] */ SHORT __RPC_FAR *lpsMinute,
            /* [out] */ SHORT __RPC_FAR *lpsSecond,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetClockData )( 
            IActQCPUQBus __RPC_FAR * This,
            /* [in] */ SHORT sYear,
            /* [in] */ SHORT sMonth,
            /* [in] */ SHORT sDay,
            /* [in] */ SHORT sDayOfWeek,
            /* [in] */ SHORT sHour,
            /* [in] */ SHORT sMinute,
            /* [in] */ SHORT sSecond,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *EntryDeviceStatus )( 
            IActQCPUQBus __RPC_FAR * This,
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG lSize,
            /* [in] */ LONG lMonitorCycle,
            /* [size_is][in] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActIONumber )( 
            IActQCPUQBus __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActIONumber )( 
            IActQCPUQBus __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActCpuType )( 
            IActQCPUQBus __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActCpuType )( 
            IActQCPUQBus __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CheckDeviceString )( 
            IActQCPUQBus __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lCheckType,
            /* [in] */ LONG lSize,
            /* [out] */ LONG __RPC_FAR *lplDeviceType,
            /* [string][out] */ BSTR __RPC_FAR *lpszDeviceName,
            /* [out] */ LONG __RPC_FAR *lplDeviceNumber,
            /* [out] */ LONG __RPC_FAR *lplDeviceRadix,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *FreeDeviceStatus )( 
            IActQCPUQBus __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        END_INTERFACE
    } IActQCPUQBusVtbl;

    interface IActQCPUQBus
    {
        CONST_VTBL struct IActQCPUQBusVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IActQCPUQBus_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IActQCPUQBus_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IActQCPUQBus_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IActQCPUQBus_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IActQCPUQBus_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IActQCPUQBus_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IActQCPUQBus_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IActQCPUQBus_Open(This,lplReturnCode)	\
    (This)->lpVtbl -> Open(This,lplReturnCode)

#define IActQCPUQBus_Close(This,lplReturnCode)	\
    (This)->lpVtbl -> Close(This,lplReturnCode)

#define IActQCPUQBus_GetDevice(This,szDevice,lplData,lplReturnCode)	\
    (This)->lpVtbl -> GetDevice(This,szDevice,lplData,lplReturnCode)

#define IActQCPUQBus_SetDevice(This,szDevice,lData,lplReturnCode)	\
    (This)->lpVtbl -> SetDevice(This,szDevice,lData,lplReturnCode)

#define IActQCPUQBus_ReadDeviceBlock(This,szDevice,lSize,lplData,lplReturnCode)	\
    (This)->lpVtbl -> ReadDeviceBlock(This,szDevice,lSize,lplData,lplReturnCode)

#define IActQCPUQBus_WriteDeviceBlock(This,szDevice,lSize,lplData,lplReturnCode)	\
    (This)->lpVtbl -> WriteDeviceBlock(This,szDevice,lSize,lplData,lplReturnCode)

#define IActQCPUQBus_ReadDeviceRandom(This,szDeviceList,lSize,lplData,lplReturnCode)	\
    (This)->lpVtbl -> ReadDeviceRandom(This,szDeviceList,lSize,lplData,lplReturnCode)

#define IActQCPUQBus_WriteDeviceRandom(This,szDeviceList,lSize,lplData,lplReturnCode)	\
    (This)->lpVtbl -> WriteDeviceRandom(This,szDeviceList,lSize,lplData,lplReturnCode)

#define IActQCPUQBus_ReadBuffer(This,lStartIO,lAddress,lReadSize,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> ReadBuffer(This,lStartIO,lAddress,lReadSize,lpsData,lplReturnCode)

#define IActQCPUQBus_WriteBuffer(This,lStartIO,lAddress,lWriteSize,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> WriteBuffer(This,lStartIO,lAddress,lWriteSize,lpsData,lplReturnCode)

#define IActQCPUQBus_GetCpuType(This,szCpuName,lplCpuCode,lplReturnCode)	\
    (This)->lpVtbl -> GetCpuType(This,szCpuName,lplCpuCode,lplReturnCode)

#define IActQCPUQBus_SetCpuStatus(This,lOperation,lplReturnCode)	\
    (This)->lpVtbl -> SetCpuStatus(This,lOperation,lplReturnCode)

#define IActQCPUQBus_GetClockData(This,lpsYear,lpsMonth,lpsDay,lpsDayOfWeek,lpsHour,lpsMinute,lpsSecond,lplReturnCode)	\
    (This)->lpVtbl -> GetClockData(This,lpsYear,lpsMonth,lpsDay,lpsDayOfWeek,lpsHour,lpsMinute,lpsSecond,lplReturnCode)

#define IActQCPUQBus_SetClockData(This,sYear,sMonth,sDay,sDayOfWeek,sHour,sMinute,sSecond,lplReturnCode)	\
    (This)->lpVtbl -> SetClockData(This,sYear,sMonth,sDay,sDayOfWeek,sHour,sMinute,sSecond,lplReturnCode)

#define IActQCPUQBus_EntryDeviceStatus(This,szDeviceList,lSize,lMonitorCycle,lplData,lplReturnCode)	\
    (This)->lpVtbl -> EntryDeviceStatus(This,szDeviceList,lSize,lMonitorCycle,lplData,lplReturnCode)

#define IActQCPUQBus_get_ActIONumber(This,pVal)	\
    (This)->lpVtbl -> get_ActIONumber(This,pVal)

#define IActQCPUQBus_put_ActIONumber(This,newVal)	\
    (This)->lpVtbl -> put_ActIONumber(This,newVal)

#define IActQCPUQBus_get_ActCpuType(This,pVal)	\
    (This)->lpVtbl -> get_ActCpuType(This,pVal)

#define IActQCPUQBus_put_ActCpuType(This,newVal)	\
    (This)->lpVtbl -> put_ActCpuType(This,newVal)

#define IActQCPUQBus_CheckDeviceString(This,szDevice,lCheckType,lSize,lplDeviceType,lpszDeviceName,lplDeviceNumber,lplDeviceRadix,lplReturnCode)	\
    (This)->lpVtbl -> CheckDeviceString(This,szDevice,lCheckType,lSize,lplDeviceType,lpszDeviceName,lplDeviceNumber,lplDeviceRadix,lplReturnCode)

#define IActQCPUQBus_FreeDeviceStatus(This,lplReturnCode)	\
    (This)->lpVtbl -> FreeDeviceStatus(This,lplReturnCode)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActQCPUQBus_Open_Proxy( 
    IActQCPUQBus __RPC_FAR * This,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActQCPUQBus_Open_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActQCPUQBus_Close_Proxy( 
    IActQCPUQBus __RPC_FAR * This,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActQCPUQBus_Close_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActQCPUQBus_GetDevice_Proxy( 
    IActQCPUQBus __RPC_FAR * This,
    /* [string][in] */ BSTR szDevice,
    /* [out] */ LONG __RPC_FAR *lplData,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActQCPUQBus_GetDevice_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActQCPUQBus_SetDevice_Proxy( 
    IActQCPUQBus __RPC_FAR * This,
    /* [string][in] */ BSTR szDevice,
    /* [in] */ LONG lData,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActQCPUQBus_SetDevice_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActQCPUQBus_ReadDeviceBlock_Proxy( 
    IActQCPUQBus __RPC_FAR * This,
    /* [string][in] */ BSTR szDevice,
    /* [in] */ LONG lSize,
    /* [size_is][out] */ LONG __RPC_FAR *lplData,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActQCPUQBus_ReadDeviceBlock_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActQCPUQBus_WriteDeviceBlock_Proxy( 
    IActQCPUQBus __RPC_FAR * This,
    /* [string][in] */ BSTR szDevice,
    /* [in] */ LONG lSize,
    /* [size_is][in] */ LONG __RPC_FAR *lplData,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActQCPUQBus_WriteDeviceBlock_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActQCPUQBus_ReadDeviceRandom_Proxy( 
    IActQCPUQBus __RPC_FAR * This,
    /* [string][in] */ BSTR szDeviceList,
    /* [in] */ LONG lSize,
    /* [size_is][out] */ LONG __RPC_FAR *lplData,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActQCPUQBus_ReadDeviceRandom_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActQCPUQBus_WriteDeviceRandom_Proxy( 
    IActQCPUQBus __RPC_FAR * This,
    /* [string][in] */ BSTR szDeviceList,
    /* [in] */ LONG lSize,
    /* [size_is][in] */ LONG __RPC_FAR *lplData,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActQCPUQBus_WriteDeviceRandom_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActQCPUQBus_ReadBuffer_Proxy( 
    IActQCPUQBus __RPC_FAR * This,
    /* [in] */ LONG lStartIO,
    /* [in] */ LONG lAddress,
    /* [in] */ LONG lReadSize,
    /* [size_is][out] */ SHORT __RPC_FAR *lpsData,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActQCPUQBus_ReadBuffer_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActQCPUQBus_WriteBuffer_Proxy( 
    IActQCPUQBus __RPC_FAR * This,
    /* [in] */ LONG lStartIO,
    /* [in] */ LONG lAddress,
    /* [in] */ LONG lWriteSize,
    /* [size_is][in] */ SHORT __RPC_FAR *lpsData,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActQCPUQBus_WriteBuffer_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActQCPUQBus_GetCpuType_Proxy( 
    IActQCPUQBus __RPC_FAR * This,
    /* [string][out] */ BSTR __RPC_FAR *szCpuName,
    /* [out] */ LONG __RPC_FAR *lplCpuCode,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActQCPUQBus_GetCpuType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActQCPUQBus_SetCpuStatus_Proxy( 
    IActQCPUQBus __RPC_FAR * This,
    /* [in] */ LONG lOperation,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActQCPUQBus_SetCpuStatus_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActQCPUQBus_GetClockData_Proxy( 
    IActQCPUQBus __RPC_FAR * This,
    /* [out] */ SHORT __RPC_FAR *lpsYear,
    /* [out] */ SHORT __RPC_FAR *lpsMonth,
    /* [out] */ SHORT __RPC_FAR *lpsDay,
    /* [out] */ SHORT __RPC_FAR *lpsDayOfWeek,
    /* [out] */ SHORT __RPC_FAR *lpsHour,
    /* [out] */ SHORT __RPC_FAR *lpsMinute,
    /* [out] */ SHORT __RPC_FAR *lpsSecond,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActQCPUQBus_GetClockData_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActQCPUQBus_SetClockData_Proxy( 
    IActQCPUQBus __RPC_FAR * This,
    /* [in] */ SHORT sYear,
    /* [in] */ SHORT sMonth,
    /* [in] */ SHORT sDay,
    /* [in] */ SHORT sDayOfWeek,
    /* [in] */ SHORT sHour,
    /* [in] */ SHORT sMinute,
    /* [in] */ SHORT sSecond,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActQCPUQBus_SetClockData_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActQCPUQBus_EntryDeviceStatus_Proxy( 
    IActQCPUQBus __RPC_FAR * This,
    /* [string][in] */ BSTR szDeviceList,
    /* [in] */ LONG lSize,
    /* [in] */ LONG lMonitorCycle,
    /* [size_is][in] */ LONG __RPC_FAR *lplData,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActQCPUQBus_EntryDeviceStatus_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActQCPUQBus_get_ActIONumber_Proxy( 
    IActQCPUQBus __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IActQCPUQBus_get_ActIONumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActQCPUQBus_put_ActIONumber_Proxy( 
    IActQCPUQBus __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB IActQCPUQBus_put_ActIONumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActQCPUQBus_get_ActCpuType_Proxy( 
    IActQCPUQBus __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IActQCPUQBus_get_ActCpuType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActQCPUQBus_put_ActCpuType_Proxy( 
    IActQCPUQBus __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB IActQCPUQBus_put_ActCpuType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActQCPUQBus_CheckDeviceString_Proxy( 
    IActQCPUQBus __RPC_FAR * This,
    /* [string][in] */ BSTR szDevice,
    /* [in] */ LONG lCheckType,
    /* [in] */ LONG lSize,
    /* [out] */ LONG __RPC_FAR *lplDeviceType,
    /* [string][out] */ BSTR __RPC_FAR *lpszDeviceName,
    /* [out] */ LONG __RPC_FAR *lplDeviceNumber,
    /* [out] */ LONG __RPC_FAR *lplDeviceRadix,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActQCPUQBus_CheckDeviceString_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActQCPUQBus_FreeDeviceStatus_Proxy( 
    IActQCPUQBus __RPC_FAR * This,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActQCPUQBus_FreeDeviceStatus_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IActQCPUQBus_INTERFACE_DEFINED__ */


#ifndef __IActQCPUQBus2_INTERFACE_DEFINED__
#define __IActQCPUQBus2_INTERFACE_DEFINED__

/* interface IActQCPUQBus2 */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IActQCPUQBus2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("54B370B0-CA57-11d4-8746-00E0292A4FB4")
    IActQCPUQBus2 : public IActQCPUQBus
    {
    public:
    };
    
#else 	/* C style interface */

    typedef struct IActQCPUQBus2Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IActQCPUQBus2 __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IActQCPUQBus2 __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IActQCPUQBus2 __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IActQCPUQBus2 __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IActQCPUQBus2 __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IActQCPUQBus2 __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IActQCPUQBus2 __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Open )( 
            IActQCPUQBus2 __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Close )( 
            IActQCPUQBus2 __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetDevice )( 
            IActQCPUQBus2 __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [out] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetDevice )( 
            IActQCPUQBus2 __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceBlock )( 
            IActQCPUQBus2 __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lSize,
            /* [size_is][out] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceBlock )( 
            IActQCPUQBus2 __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lSize,
            /* [size_is][in] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceRandom )( 
            IActQCPUQBus2 __RPC_FAR * This,
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG lSize,
            /* [size_is][out] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceRandom )( 
            IActQCPUQBus2 __RPC_FAR * This,
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG lSize,
            /* [size_is][in] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadBuffer )( 
            IActQCPUQBus2 __RPC_FAR * This,
            /* [in] */ LONG lStartIO,
            /* [in] */ LONG lAddress,
            /* [in] */ LONG lReadSize,
            /* [size_is][out] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteBuffer )( 
            IActQCPUQBus2 __RPC_FAR * This,
            /* [in] */ LONG lStartIO,
            /* [in] */ LONG lAddress,
            /* [in] */ LONG lWriteSize,
            /* [size_is][in] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetCpuType )( 
            IActQCPUQBus2 __RPC_FAR * This,
            /* [string][out] */ BSTR __RPC_FAR *szCpuName,
            /* [out] */ LONG __RPC_FAR *lplCpuCode,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetCpuStatus )( 
            IActQCPUQBus2 __RPC_FAR * This,
            /* [in] */ LONG lOperation,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetClockData )( 
            IActQCPUQBus2 __RPC_FAR * This,
            /* [out] */ SHORT __RPC_FAR *lpsYear,
            /* [out] */ SHORT __RPC_FAR *lpsMonth,
            /* [out] */ SHORT __RPC_FAR *lpsDay,
            /* [out] */ SHORT __RPC_FAR *lpsDayOfWeek,
            /* [out] */ SHORT __RPC_FAR *lpsHour,
            /* [out] */ SHORT __RPC_FAR *lpsMinute,
            /* [out] */ SHORT __RPC_FAR *lpsSecond,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetClockData )( 
            IActQCPUQBus2 __RPC_FAR * This,
            /* [in] */ SHORT sYear,
            /* [in] */ SHORT sMonth,
            /* [in] */ SHORT sDay,
            /* [in] */ SHORT sDayOfWeek,
            /* [in] */ SHORT sHour,
            /* [in] */ SHORT sMinute,
            /* [in] */ SHORT sSecond,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *EntryDeviceStatus )( 
            IActQCPUQBus2 __RPC_FAR * This,
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG lSize,
            /* [in] */ LONG lMonitorCycle,
            /* [size_is][in] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActIONumber )( 
            IActQCPUQBus2 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActIONumber )( 
            IActQCPUQBus2 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActCpuType )( 
            IActQCPUQBus2 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActCpuType )( 
            IActQCPUQBus2 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CheckDeviceString )( 
            IActQCPUQBus2 __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lCheckType,
            /* [in] */ LONG lSize,
            /* [out] */ LONG __RPC_FAR *lplDeviceType,
            /* [string][out] */ BSTR __RPC_FAR *lpszDeviceName,
            /* [out] */ LONG __RPC_FAR *lplDeviceNumber,
            /* [out] */ LONG __RPC_FAR *lplDeviceRadix,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *FreeDeviceStatus )( 
            IActQCPUQBus2 __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        END_INTERFACE
    } IActQCPUQBus2Vtbl;

    interface IActQCPUQBus2
    {
        CONST_VTBL struct IActQCPUQBus2Vtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IActQCPUQBus2_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IActQCPUQBus2_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IActQCPUQBus2_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IActQCPUQBus2_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IActQCPUQBus2_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IActQCPUQBus2_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IActQCPUQBus2_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IActQCPUQBus2_Open(This,lplReturnCode)	\
    (This)->lpVtbl -> Open(This,lplReturnCode)

#define IActQCPUQBus2_Close(This,lplReturnCode)	\
    (This)->lpVtbl -> Close(This,lplReturnCode)

#define IActQCPUQBus2_GetDevice(This,szDevice,lplData,lplReturnCode)	\
    (This)->lpVtbl -> GetDevice(This,szDevice,lplData,lplReturnCode)

#define IActQCPUQBus2_SetDevice(This,szDevice,lData,lplReturnCode)	\
    (This)->lpVtbl -> SetDevice(This,szDevice,lData,lplReturnCode)

#define IActQCPUQBus2_ReadDeviceBlock(This,szDevice,lSize,lplData,lplReturnCode)	\
    (This)->lpVtbl -> ReadDeviceBlock(This,szDevice,lSize,lplData,lplReturnCode)

#define IActQCPUQBus2_WriteDeviceBlock(This,szDevice,lSize,lplData,lplReturnCode)	\
    (This)->lpVtbl -> WriteDeviceBlock(This,szDevice,lSize,lplData,lplReturnCode)

#define IActQCPUQBus2_ReadDeviceRandom(This,szDeviceList,lSize,lplData,lplReturnCode)	\
    (This)->lpVtbl -> ReadDeviceRandom(This,szDeviceList,lSize,lplData,lplReturnCode)

#define IActQCPUQBus2_WriteDeviceRandom(This,szDeviceList,lSize,lplData,lplReturnCode)	\
    (This)->lpVtbl -> WriteDeviceRandom(This,szDeviceList,lSize,lplData,lplReturnCode)

#define IActQCPUQBus2_ReadBuffer(This,lStartIO,lAddress,lReadSize,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> ReadBuffer(This,lStartIO,lAddress,lReadSize,lpsData,lplReturnCode)

#define IActQCPUQBus2_WriteBuffer(This,lStartIO,lAddress,lWriteSize,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> WriteBuffer(This,lStartIO,lAddress,lWriteSize,lpsData,lplReturnCode)

#define IActQCPUQBus2_GetCpuType(This,szCpuName,lplCpuCode,lplReturnCode)	\
    (This)->lpVtbl -> GetCpuType(This,szCpuName,lplCpuCode,lplReturnCode)

#define IActQCPUQBus2_SetCpuStatus(This,lOperation,lplReturnCode)	\
    (This)->lpVtbl -> SetCpuStatus(This,lOperation,lplReturnCode)

#define IActQCPUQBus2_GetClockData(This,lpsYear,lpsMonth,lpsDay,lpsDayOfWeek,lpsHour,lpsMinute,lpsSecond,lplReturnCode)	\
    (This)->lpVtbl -> GetClockData(This,lpsYear,lpsMonth,lpsDay,lpsDayOfWeek,lpsHour,lpsMinute,lpsSecond,lplReturnCode)

#define IActQCPUQBus2_SetClockData(This,sYear,sMonth,sDay,sDayOfWeek,sHour,sMinute,sSecond,lplReturnCode)	\
    (This)->lpVtbl -> SetClockData(This,sYear,sMonth,sDay,sDayOfWeek,sHour,sMinute,sSecond,lplReturnCode)

#define IActQCPUQBus2_EntryDeviceStatus(This,szDeviceList,lSize,lMonitorCycle,lplData,lplReturnCode)	\
    (This)->lpVtbl -> EntryDeviceStatus(This,szDeviceList,lSize,lMonitorCycle,lplData,lplReturnCode)

#define IActQCPUQBus2_get_ActIONumber(This,pVal)	\
    (This)->lpVtbl -> get_ActIONumber(This,pVal)

#define IActQCPUQBus2_put_ActIONumber(This,newVal)	\
    (This)->lpVtbl -> put_ActIONumber(This,newVal)

#define IActQCPUQBus2_get_ActCpuType(This,pVal)	\
    (This)->lpVtbl -> get_ActCpuType(This,pVal)

#define IActQCPUQBus2_put_ActCpuType(This,newVal)	\
    (This)->lpVtbl -> put_ActCpuType(This,newVal)

#define IActQCPUQBus2_CheckDeviceString(This,szDevice,lCheckType,lSize,lplDeviceType,lpszDeviceName,lplDeviceNumber,lplDeviceRadix,lplReturnCode)	\
    (This)->lpVtbl -> CheckDeviceString(This,szDevice,lCheckType,lSize,lplDeviceType,lpszDeviceName,lplDeviceNumber,lplDeviceRadix,lplReturnCode)

#define IActQCPUQBus2_FreeDeviceStatus(This,lplReturnCode)	\
    (This)->lpVtbl -> FreeDeviceStatus(This,lplReturnCode)


#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IActQCPUQBus2_INTERFACE_DEFINED__ */


#ifndef __IActQCPUQBus3_INTERFACE_DEFINED__
#define __IActQCPUQBus3_INTERFACE_DEFINED__

/* interface IActQCPUQBus3 */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IActQCPUQBus3;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("115992F3-6EC2-11d5-9314-009099244EFD")
    IActQCPUQBus3 : public IActQCPUQBus2
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

    typedef struct IActQCPUQBus3Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IActQCPUQBus3 __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IActQCPUQBus3 __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IActQCPUQBus3 __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IActQCPUQBus3 __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IActQCPUQBus3 __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IActQCPUQBus3 __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IActQCPUQBus3 __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Open )( 
            IActQCPUQBus3 __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Close )( 
            IActQCPUQBus3 __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetDevice )( 
            IActQCPUQBus3 __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [out] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetDevice )( 
            IActQCPUQBus3 __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceBlock )( 
            IActQCPUQBus3 __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lSize,
            /* [size_is][out] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceBlock )( 
            IActQCPUQBus3 __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lSize,
            /* [size_is][in] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceRandom )( 
            IActQCPUQBus3 __RPC_FAR * This,
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG lSize,
            /* [size_is][out] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceRandom )( 
            IActQCPUQBus3 __RPC_FAR * This,
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG lSize,
            /* [size_is][in] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadBuffer )( 
            IActQCPUQBus3 __RPC_FAR * This,
            /* [in] */ LONG lStartIO,
            /* [in] */ LONG lAddress,
            /* [in] */ LONG lReadSize,
            /* [size_is][out] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteBuffer )( 
            IActQCPUQBus3 __RPC_FAR * This,
            /* [in] */ LONG lStartIO,
            /* [in] */ LONG lAddress,
            /* [in] */ LONG lWriteSize,
            /* [size_is][in] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetCpuType )( 
            IActQCPUQBus3 __RPC_FAR * This,
            /* [string][out] */ BSTR __RPC_FAR *szCpuName,
            /* [out] */ LONG __RPC_FAR *lplCpuCode,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetCpuStatus )( 
            IActQCPUQBus3 __RPC_FAR * This,
            /* [in] */ LONG lOperation,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetClockData )( 
            IActQCPUQBus3 __RPC_FAR * This,
            /* [out] */ SHORT __RPC_FAR *lpsYear,
            /* [out] */ SHORT __RPC_FAR *lpsMonth,
            /* [out] */ SHORT __RPC_FAR *lpsDay,
            /* [out] */ SHORT __RPC_FAR *lpsDayOfWeek,
            /* [out] */ SHORT __RPC_FAR *lpsHour,
            /* [out] */ SHORT __RPC_FAR *lpsMinute,
            /* [out] */ SHORT __RPC_FAR *lpsSecond,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetClockData )( 
            IActQCPUQBus3 __RPC_FAR * This,
            /* [in] */ SHORT sYear,
            /* [in] */ SHORT sMonth,
            /* [in] */ SHORT sDay,
            /* [in] */ SHORT sDayOfWeek,
            /* [in] */ SHORT sHour,
            /* [in] */ SHORT sMinute,
            /* [in] */ SHORT sSecond,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *EntryDeviceStatus )( 
            IActQCPUQBus3 __RPC_FAR * This,
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG lSize,
            /* [in] */ LONG lMonitorCycle,
            /* [size_is][in] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActIONumber )( 
            IActQCPUQBus3 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActIONumber )( 
            IActQCPUQBus3 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActCpuType )( 
            IActQCPUQBus3 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActCpuType )( 
            IActQCPUQBus3 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CheckDeviceString )( 
            IActQCPUQBus3 __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lCheckType,
            /* [in] */ LONG lSize,
            /* [out] */ LONG __RPC_FAR *lplDeviceType,
            /* [string][out] */ BSTR __RPC_FAR *lpszDeviceName,
            /* [out] */ LONG __RPC_FAR *lplDeviceNumber,
            /* [out] */ LONG __RPC_FAR *lplDeviceRadix,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *FreeDeviceStatus )( 
            IActQCPUQBus3 __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceBlock2 )( 
            IActQCPUQBus3 __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lSize,
            /* [size_is][out] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceBlock2 )( 
            IActQCPUQBus3 __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lSize,
            /* [size_is][in] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceRandom2 )( 
            IActQCPUQBus3 __RPC_FAR * This,
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG lSize,
            /* [size_is][out] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceRandom2 )( 
            IActQCPUQBus3 __RPC_FAR * This,
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG lSize,
            /* [size_is][in] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetDevice2 )( 
            IActQCPUQBus3 __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [out] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetDevice2 )( 
            IActQCPUQBus3 __RPC_FAR * This,
            /* [in] */ BSTR szDevice,
            /* [in] */ SHORT sData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        END_INTERFACE
    } IActQCPUQBus3Vtbl;

    interface IActQCPUQBus3
    {
        CONST_VTBL struct IActQCPUQBus3Vtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IActQCPUQBus3_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IActQCPUQBus3_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IActQCPUQBus3_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IActQCPUQBus3_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IActQCPUQBus3_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IActQCPUQBus3_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IActQCPUQBus3_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IActQCPUQBus3_Open(This,lplReturnCode)	\
    (This)->lpVtbl -> Open(This,lplReturnCode)

#define IActQCPUQBus3_Close(This,lplReturnCode)	\
    (This)->lpVtbl -> Close(This,lplReturnCode)

#define IActQCPUQBus3_GetDevice(This,szDevice,lplData,lplReturnCode)	\
    (This)->lpVtbl -> GetDevice(This,szDevice,lplData,lplReturnCode)

#define IActQCPUQBus3_SetDevice(This,szDevice,lData,lplReturnCode)	\
    (This)->lpVtbl -> SetDevice(This,szDevice,lData,lplReturnCode)

#define IActQCPUQBus3_ReadDeviceBlock(This,szDevice,lSize,lplData,lplReturnCode)	\
    (This)->lpVtbl -> ReadDeviceBlock(This,szDevice,lSize,lplData,lplReturnCode)

#define IActQCPUQBus3_WriteDeviceBlock(This,szDevice,lSize,lplData,lplReturnCode)	\
    (This)->lpVtbl -> WriteDeviceBlock(This,szDevice,lSize,lplData,lplReturnCode)

#define IActQCPUQBus3_ReadDeviceRandom(This,szDeviceList,lSize,lplData,lplReturnCode)	\
    (This)->lpVtbl -> ReadDeviceRandom(This,szDeviceList,lSize,lplData,lplReturnCode)

#define IActQCPUQBus3_WriteDeviceRandom(This,szDeviceList,lSize,lplData,lplReturnCode)	\
    (This)->lpVtbl -> WriteDeviceRandom(This,szDeviceList,lSize,lplData,lplReturnCode)

#define IActQCPUQBus3_ReadBuffer(This,lStartIO,lAddress,lReadSize,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> ReadBuffer(This,lStartIO,lAddress,lReadSize,lpsData,lplReturnCode)

#define IActQCPUQBus3_WriteBuffer(This,lStartIO,lAddress,lWriteSize,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> WriteBuffer(This,lStartIO,lAddress,lWriteSize,lpsData,lplReturnCode)

#define IActQCPUQBus3_GetCpuType(This,szCpuName,lplCpuCode,lplReturnCode)	\
    (This)->lpVtbl -> GetCpuType(This,szCpuName,lplCpuCode,lplReturnCode)

#define IActQCPUQBus3_SetCpuStatus(This,lOperation,lplReturnCode)	\
    (This)->lpVtbl -> SetCpuStatus(This,lOperation,lplReturnCode)

#define IActQCPUQBus3_GetClockData(This,lpsYear,lpsMonth,lpsDay,lpsDayOfWeek,lpsHour,lpsMinute,lpsSecond,lplReturnCode)	\
    (This)->lpVtbl -> GetClockData(This,lpsYear,lpsMonth,lpsDay,lpsDayOfWeek,lpsHour,lpsMinute,lpsSecond,lplReturnCode)

#define IActQCPUQBus3_SetClockData(This,sYear,sMonth,sDay,sDayOfWeek,sHour,sMinute,sSecond,lplReturnCode)	\
    (This)->lpVtbl -> SetClockData(This,sYear,sMonth,sDay,sDayOfWeek,sHour,sMinute,sSecond,lplReturnCode)

#define IActQCPUQBus3_EntryDeviceStatus(This,szDeviceList,lSize,lMonitorCycle,lplData,lplReturnCode)	\
    (This)->lpVtbl -> EntryDeviceStatus(This,szDeviceList,lSize,lMonitorCycle,lplData,lplReturnCode)

#define IActQCPUQBus3_get_ActIONumber(This,pVal)	\
    (This)->lpVtbl -> get_ActIONumber(This,pVal)

#define IActQCPUQBus3_put_ActIONumber(This,newVal)	\
    (This)->lpVtbl -> put_ActIONumber(This,newVal)

#define IActQCPUQBus3_get_ActCpuType(This,pVal)	\
    (This)->lpVtbl -> get_ActCpuType(This,pVal)

#define IActQCPUQBus3_put_ActCpuType(This,newVal)	\
    (This)->lpVtbl -> put_ActCpuType(This,newVal)

#define IActQCPUQBus3_CheckDeviceString(This,szDevice,lCheckType,lSize,lplDeviceType,lpszDeviceName,lplDeviceNumber,lplDeviceRadix,lplReturnCode)	\
    (This)->lpVtbl -> CheckDeviceString(This,szDevice,lCheckType,lSize,lplDeviceType,lpszDeviceName,lplDeviceNumber,lplDeviceRadix,lplReturnCode)

#define IActQCPUQBus3_FreeDeviceStatus(This,lplReturnCode)	\
    (This)->lpVtbl -> FreeDeviceStatus(This,lplReturnCode)



#define IActQCPUQBus3_ReadDeviceBlock2(This,szDevice,lSize,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> ReadDeviceBlock2(This,szDevice,lSize,lpsData,lplReturnCode)

#define IActQCPUQBus3_WriteDeviceBlock2(This,szDevice,lSize,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> WriteDeviceBlock2(This,szDevice,lSize,lpsData,lplReturnCode)

#define IActQCPUQBus3_ReadDeviceRandom2(This,szDeviceList,lSize,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> ReadDeviceRandom2(This,szDeviceList,lSize,lpsData,lplReturnCode)

#define IActQCPUQBus3_WriteDeviceRandom2(This,szDeviceList,lSize,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> WriteDeviceRandom2(This,szDeviceList,lSize,lpsData,lplReturnCode)

#define IActQCPUQBus3_GetDevice2(This,szDevice,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> GetDevice2(This,szDevice,lpsData,lplReturnCode)

#define IActQCPUQBus3_SetDevice2(This,szDevice,sData,lplReturnCode)	\
    (This)->lpVtbl -> SetDevice2(This,szDevice,sData,lplReturnCode)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActQCPUQBus3_ReadDeviceBlock2_Proxy( 
    IActQCPUQBus3 __RPC_FAR * This,
    /* [string][in] */ BSTR szDevice,
    /* [in] */ LONG lSize,
    /* [size_is][out] */ SHORT __RPC_FAR *lpsData,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActQCPUQBus3_ReadDeviceBlock2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActQCPUQBus3_WriteDeviceBlock2_Proxy( 
    IActQCPUQBus3 __RPC_FAR * This,
    /* [string][in] */ BSTR szDevice,
    /* [in] */ LONG lSize,
    /* [size_is][in] */ SHORT __RPC_FAR *lpsData,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActQCPUQBus3_WriteDeviceBlock2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActQCPUQBus3_ReadDeviceRandom2_Proxy( 
    IActQCPUQBus3 __RPC_FAR * This,
    /* [string][in] */ BSTR szDeviceList,
    /* [in] */ LONG lSize,
    /* [size_is][out] */ SHORT __RPC_FAR *lpsData,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActQCPUQBus3_ReadDeviceRandom2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActQCPUQBus3_WriteDeviceRandom2_Proxy( 
    IActQCPUQBus3 __RPC_FAR * This,
    /* [string][in] */ BSTR szDeviceList,
    /* [in] */ LONG lSize,
    /* [size_is][in] */ SHORT __RPC_FAR *lpsData,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActQCPUQBus3_WriteDeviceRandom2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActQCPUQBus3_GetDevice2_Proxy( 
    IActQCPUQBus3 __RPC_FAR * This,
    /* [string][in] */ BSTR szDevice,
    /* [out] */ SHORT __RPC_FAR *lpsData,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActQCPUQBus3_GetDevice2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActQCPUQBus3_SetDevice2_Proxy( 
    IActQCPUQBus3 __RPC_FAR * This,
    /* [in] */ BSTR szDevice,
    /* [in] */ SHORT sData,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActQCPUQBus3_SetDevice2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IActQCPUQBus3_INTERFACE_DEFINED__ */


#ifndef __IActMLQCPUQBus_INTERFACE_DEFINED__
#define __IActMLQCPUQBus_INTERFACE_DEFINED__

/* interface IActMLQCPUQBus */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IActMLQCPUQBus;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("062B9B59-AA34-11D4-910F-009099244EFD")
    IActMLQCPUQBus : public IDispatch
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
            /* [in] */ VARIANT varReadSize,
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
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActIONumber( 
            /* [retval][out] */ VARIANT __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActIONumber( 
            /* [in] */ VARIANT newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActCpuType( 
            /* [retval][out] */ VARIANT __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActCpuType( 
            /* [in] */ VARIANT newVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE FreeDeviceStatus( 
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IActMLQCPUQBusVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IActMLQCPUQBus __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IActMLQCPUQBus __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IActMLQCPUQBus __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IActMLQCPUQBus __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IActMLQCPUQBus __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IActMLQCPUQBus __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IActMLQCPUQBus __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Open )( 
            IActMLQCPUQBus __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Close )( 
            IActMLQCPUQBus __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetDevice )( 
            IActMLQCPUQBus __RPC_FAR * This,
            /* [in] */ VARIANT varDevice,
            /* [out] */ VARIANT __RPC_FAR *lpvarData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetDevice )( 
            IActMLQCPUQBus __RPC_FAR * This,
            /* [in] */ VARIANT varDevice,
            /* [in] */ VARIANT varData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceBlock )( 
            IActMLQCPUQBus __RPC_FAR * This,
            /* [in] */ VARIANT varDevice,
            /* [in] */ VARIANT varSize,
            /* [out] */ VARIANT __RPC_FAR *lpvarData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceBlock )( 
            IActMLQCPUQBus __RPC_FAR * This,
            /* [in] */ VARIANT varDevice,
            /* [in] */ VARIANT varSize,
            /* [in] */ VARIANT varData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceRandom )( 
            IActMLQCPUQBus __RPC_FAR * This,
            /* [in] */ VARIANT varDeviceList,
            /* [in] */ VARIANT varSize,
            /* [out] */ VARIANT __RPC_FAR *lpvarData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceRandom )( 
            IActMLQCPUQBus __RPC_FAR * This,
            /* [in] */ VARIANT varDeviceList,
            /* [in] */ VARIANT varSize,
            /* [in] */ VARIANT varData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadBuffer )( 
            IActMLQCPUQBus __RPC_FAR * This,
            /* [in] */ VARIANT varStartIO,
            /* [in] */ VARIANT varAddress,
            /* [in] */ VARIANT varReadSize,
            /* [out] */ VARIANT __RPC_FAR *lpvarData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteBuffer )( 
            IActMLQCPUQBus __RPC_FAR * This,
            /* [in] */ VARIANT varStartIO,
            /* [in] */ VARIANT varAddress,
            /* [in] */ VARIANT varReadSize,
            /* [in] */ VARIANT varData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetCpuType )( 
            IActMLQCPUQBus __RPC_FAR * This,
            /* [out] */ VARIANT __RPC_FAR *lpvarCpuName,
            /* [out] */ VARIANT __RPC_FAR *lpvarCpuType,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetCpuStatus )( 
            IActMLQCPUQBus __RPC_FAR * This,
            /* [in] */ VARIANT varOperation,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetClockData )( 
            IActMLQCPUQBus __RPC_FAR * This,
            /* [out] */ VARIANT __RPC_FAR *lpvarYear,
            /* [out] */ VARIANT __RPC_FAR *lpvarMonth,
            /* [out] */ VARIANT __RPC_FAR *lpvarDay,
            /* [out] */ VARIANT __RPC_FAR *lpvarDayOfWeek,
            /* [out] */ VARIANT __RPC_FAR *lpvarHour,
            /* [out] */ VARIANT __RPC_FAR *lpvarMinute,
            /* [out] */ VARIANT __RPC_FAR *lpvarSecond,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetClockData )( 
            IActMLQCPUQBus __RPC_FAR * This,
            /* [in] */ VARIANT varYear,
            /* [in] */ VARIANT varMonth,
            /* [in] */ VARIANT varDay,
            /* [in] */ VARIANT varDayOfWeek,
            /* [in] */ VARIANT varHour,
            /* [in] */ VARIANT varMinute,
            /* [in] */ VARIANT varSecond,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *EntryDeviceStatus )( 
            IActMLQCPUQBus __RPC_FAR * This,
            /* [in] */ VARIANT varDeviceList,
            /* [in] */ VARIANT varSize,
            /* [in] */ VARIANT varMonitorCycle,
            /* [in] */ VARIANT varData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActIONumber )( 
            IActMLQCPUQBus __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActIONumber )( 
            IActMLQCPUQBus __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActCpuType )( 
            IActMLQCPUQBus __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActCpuType )( 
            IActMLQCPUQBus __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *FreeDeviceStatus )( 
            IActMLQCPUQBus __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        END_INTERFACE
    } IActMLQCPUQBusVtbl;

    interface IActMLQCPUQBus
    {
        CONST_VTBL struct IActMLQCPUQBusVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IActMLQCPUQBus_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IActMLQCPUQBus_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IActMLQCPUQBus_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IActMLQCPUQBus_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IActMLQCPUQBus_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IActMLQCPUQBus_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IActMLQCPUQBus_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IActMLQCPUQBus_Open(This,lpvarReturnCode)	\
    (This)->lpVtbl -> Open(This,lpvarReturnCode)

#define IActMLQCPUQBus_Close(This,lpvarReturnCode)	\
    (This)->lpVtbl -> Close(This,lpvarReturnCode)

#define IActMLQCPUQBus_GetDevice(This,varDevice,lpvarData,lpvarReturnCode)	\
    (This)->lpVtbl -> GetDevice(This,varDevice,lpvarData,lpvarReturnCode)

#define IActMLQCPUQBus_SetDevice(This,varDevice,varData,lpvarReturnCode)	\
    (This)->lpVtbl -> SetDevice(This,varDevice,varData,lpvarReturnCode)

#define IActMLQCPUQBus_ReadDeviceBlock(This,varDevice,varSize,lpvarData,lpvarReturnCode)	\
    (This)->lpVtbl -> ReadDeviceBlock(This,varDevice,varSize,lpvarData,lpvarReturnCode)

#define IActMLQCPUQBus_WriteDeviceBlock(This,varDevice,varSize,varData,lpvarReturnCode)	\
    (This)->lpVtbl -> WriteDeviceBlock(This,varDevice,varSize,varData,lpvarReturnCode)

#define IActMLQCPUQBus_ReadDeviceRandom(This,varDeviceList,varSize,lpvarData,lpvarReturnCode)	\
    (This)->lpVtbl -> ReadDeviceRandom(This,varDeviceList,varSize,lpvarData,lpvarReturnCode)

#define IActMLQCPUQBus_WriteDeviceRandom(This,varDeviceList,varSize,varData,lpvarReturnCode)	\
    (This)->lpVtbl -> WriteDeviceRandom(This,varDeviceList,varSize,varData,lpvarReturnCode)

#define IActMLQCPUQBus_ReadBuffer(This,varStartIO,varAddress,varReadSize,lpvarData,lpvarReturnCode)	\
    (This)->lpVtbl -> ReadBuffer(This,varStartIO,varAddress,varReadSize,lpvarData,lpvarReturnCode)

#define IActMLQCPUQBus_WriteBuffer(This,varStartIO,varAddress,varReadSize,varData,lpvarReturnCode)	\
    (This)->lpVtbl -> WriteBuffer(This,varStartIO,varAddress,varReadSize,varData,lpvarReturnCode)

#define IActMLQCPUQBus_GetCpuType(This,lpvarCpuName,lpvarCpuType,lpvarReturnCode)	\
    (This)->lpVtbl -> GetCpuType(This,lpvarCpuName,lpvarCpuType,lpvarReturnCode)

#define IActMLQCPUQBus_SetCpuStatus(This,varOperation,lpvarReturnCode)	\
    (This)->lpVtbl -> SetCpuStatus(This,varOperation,lpvarReturnCode)

#define IActMLQCPUQBus_GetClockData(This,lpvarYear,lpvarMonth,lpvarDay,lpvarDayOfWeek,lpvarHour,lpvarMinute,lpvarSecond,lpvarReturnCode)	\
    (This)->lpVtbl -> GetClockData(This,lpvarYear,lpvarMonth,lpvarDay,lpvarDayOfWeek,lpvarHour,lpvarMinute,lpvarSecond,lpvarReturnCode)

#define IActMLQCPUQBus_SetClockData(This,varYear,varMonth,varDay,varDayOfWeek,varHour,varMinute,varSecond,lpvarReturnCode)	\
    (This)->lpVtbl -> SetClockData(This,varYear,varMonth,varDay,varDayOfWeek,varHour,varMinute,varSecond,lpvarReturnCode)

#define IActMLQCPUQBus_EntryDeviceStatus(This,varDeviceList,varSize,varMonitorCycle,varData,lpvarReturnCode)	\
    (This)->lpVtbl -> EntryDeviceStatus(This,varDeviceList,varSize,varMonitorCycle,varData,lpvarReturnCode)

#define IActMLQCPUQBus_get_ActIONumber(This,pVal)	\
    (This)->lpVtbl -> get_ActIONumber(This,pVal)

#define IActMLQCPUQBus_put_ActIONumber(This,newVal)	\
    (This)->lpVtbl -> put_ActIONumber(This,newVal)

#define IActMLQCPUQBus_get_ActCpuType(This,pVal)	\
    (This)->lpVtbl -> get_ActCpuType(This,pVal)

#define IActMLQCPUQBus_put_ActCpuType(This,newVal)	\
    (This)->lpVtbl -> put_ActCpuType(This,newVal)

#define IActMLQCPUQBus_FreeDeviceStatus(This,lpvarReturnCode)	\
    (This)->lpVtbl -> FreeDeviceStatus(This,lpvarReturnCode)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActMLQCPUQBus_Open_Proxy( 
    IActMLQCPUQBus __RPC_FAR * This,
    /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);


void __RPC_STUB IActMLQCPUQBus_Open_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActMLQCPUQBus_Close_Proxy( 
    IActMLQCPUQBus __RPC_FAR * This,
    /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);


void __RPC_STUB IActMLQCPUQBus_Close_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActMLQCPUQBus_GetDevice_Proxy( 
    IActMLQCPUQBus __RPC_FAR * This,
    /* [in] */ VARIANT varDevice,
    /* [out] */ VARIANT __RPC_FAR *lpvarData,
    /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);


void __RPC_STUB IActMLQCPUQBus_GetDevice_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActMLQCPUQBus_SetDevice_Proxy( 
    IActMLQCPUQBus __RPC_FAR * This,
    /* [in] */ VARIANT varDevice,
    /* [in] */ VARIANT varData,
    /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);


void __RPC_STUB IActMLQCPUQBus_SetDevice_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActMLQCPUQBus_ReadDeviceBlock_Proxy( 
    IActMLQCPUQBus __RPC_FAR * This,
    /* [in] */ VARIANT varDevice,
    /* [in] */ VARIANT varSize,
    /* [out] */ VARIANT __RPC_FAR *lpvarData,
    /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);


void __RPC_STUB IActMLQCPUQBus_ReadDeviceBlock_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActMLQCPUQBus_WriteDeviceBlock_Proxy( 
    IActMLQCPUQBus __RPC_FAR * This,
    /* [in] */ VARIANT varDevice,
    /* [in] */ VARIANT varSize,
    /* [in] */ VARIANT varData,
    /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);


void __RPC_STUB IActMLQCPUQBus_WriteDeviceBlock_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActMLQCPUQBus_ReadDeviceRandom_Proxy( 
    IActMLQCPUQBus __RPC_FAR * This,
    /* [in] */ VARIANT varDeviceList,
    /* [in] */ VARIANT varSize,
    /* [out] */ VARIANT __RPC_FAR *lpvarData,
    /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);


void __RPC_STUB IActMLQCPUQBus_ReadDeviceRandom_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActMLQCPUQBus_WriteDeviceRandom_Proxy( 
    IActMLQCPUQBus __RPC_FAR * This,
    /* [in] */ VARIANT varDeviceList,
    /* [in] */ VARIANT varSize,
    /* [in] */ VARIANT varData,
    /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);


void __RPC_STUB IActMLQCPUQBus_WriteDeviceRandom_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActMLQCPUQBus_ReadBuffer_Proxy( 
    IActMLQCPUQBus __RPC_FAR * This,
    /* [in] */ VARIANT varStartIO,
    /* [in] */ VARIANT varAddress,
    /* [in] */ VARIANT varReadSize,
    /* [out] */ VARIANT __RPC_FAR *lpvarData,
    /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);


void __RPC_STUB IActMLQCPUQBus_ReadBuffer_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActMLQCPUQBus_WriteBuffer_Proxy( 
    IActMLQCPUQBus __RPC_FAR * This,
    /* [in] */ VARIANT varStartIO,
    /* [in] */ VARIANT varAddress,
    /* [in] */ VARIANT varReadSize,
    /* [in] */ VARIANT varData,
    /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);


void __RPC_STUB IActMLQCPUQBus_WriteBuffer_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActMLQCPUQBus_GetCpuType_Proxy( 
    IActMLQCPUQBus __RPC_FAR * This,
    /* [out] */ VARIANT __RPC_FAR *lpvarCpuName,
    /* [out] */ VARIANT __RPC_FAR *lpvarCpuType,
    /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);


void __RPC_STUB IActMLQCPUQBus_GetCpuType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActMLQCPUQBus_SetCpuStatus_Proxy( 
    IActMLQCPUQBus __RPC_FAR * This,
    /* [in] */ VARIANT varOperation,
    /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);


void __RPC_STUB IActMLQCPUQBus_SetCpuStatus_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActMLQCPUQBus_GetClockData_Proxy( 
    IActMLQCPUQBus __RPC_FAR * This,
    /* [out] */ VARIANT __RPC_FAR *lpvarYear,
    /* [out] */ VARIANT __RPC_FAR *lpvarMonth,
    /* [out] */ VARIANT __RPC_FAR *lpvarDay,
    /* [out] */ VARIANT __RPC_FAR *lpvarDayOfWeek,
    /* [out] */ VARIANT __RPC_FAR *lpvarHour,
    /* [out] */ VARIANT __RPC_FAR *lpvarMinute,
    /* [out] */ VARIANT __RPC_FAR *lpvarSecond,
    /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);


void __RPC_STUB IActMLQCPUQBus_GetClockData_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActMLQCPUQBus_SetClockData_Proxy( 
    IActMLQCPUQBus __RPC_FAR * This,
    /* [in] */ VARIANT varYear,
    /* [in] */ VARIANT varMonth,
    /* [in] */ VARIANT varDay,
    /* [in] */ VARIANT varDayOfWeek,
    /* [in] */ VARIANT varHour,
    /* [in] */ VARIANT varMinute,
    /* [in] */ VARIANT varSecond,
    /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);


void __RPC_STUB IActMLQCPUQBus_SetClockData_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActMLQCPUQBus_EntryDeviceStatus_Proxy( 
    IActMLQCPUQBus __RPC_FAR * This,
    /* [in] */ VARIANT varDeviceList,
    /* [in] */ VARIANT varSize,
    /* [in] */ VARIANT varMonitorCycle,
    /* [in] */ VARIANT varData,
    /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);


void __RPC_STUB IActMLQCPUQBus_EntryDeviceStatus_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActMLQCPUQBus_get_ActIONumber_Proxy( 
    IActMLQCPUQBus __RPC_FAR * This,
    /* [retval][out] */ VARIANT __RPC_FAR *pVal);


void __RPC_STUB IActMLQCPUQBus_get_ActIONumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActMLQCPUQBus_put_ActIONumber_Proxy( 
    IActMLQCPUQBus __RPC_FAR * This,
    /* [in] */ VARIANT newVal);


void __RPC_STUB IActMLQCPUQBus_put_ActIONumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActMLQCPUQBus_get_ActCpuType_Proxy( 
    IActMLQCPUQBus __RPC_FAR * This,
    /* [retval][out] */ VARIANT __RPC_FAR *pVal);


void __RPC_STUB IActMLQCPUQBus_get_ActCpuType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActMLQCPUQBus_put_ActCpuType_Proxy( 
    IActMLQCPUQBus __RPC_FAR * This,
    /* [in] */ VARIANT newVal);


void __RPC_STUB IActMLQCPUQBus_put_ActCpuType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActMLQCPUQBus_FreeDeviceStatus_Proxy( 
    IActMLQCPUQBus __RPC_FAR * This,
    /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);


void __RPC_STUB IActMLQCPUQBus_FreeDeviceStatus_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IActMLQCPUQBus_INTERFACE_DEFINED__ */


#ifndef __IActMLQCPUQBus2_INTERFACE_DEFINED__
#define __IActMLQCPUQBus2_INTERFACE_DEFINED__

/* interface IActMLQCPUQBus2 */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IActMLQCPUQBus2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("87166031-710B-11d5-9318-009099244EFD")
    IActMLQCPUQBus2 : public IActMLQCPUQBus
    {
    public:
    };
    
#else 	/* C style interface */

    typedef struct IActMLQCPUQBus2Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IActMLQCPUQBus2 __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IActMLQCPUQBus2 __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IActMLQCPUQBus2 __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IActMLQCPUQBus2 __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IActMLQCPUQBus2 __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IActMLQCPUQBus2 __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IActMLQCPUQBus2 __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Open )( 
            IActMLQCPUQBus2 __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Close )( 
            IActMLQCPUQBus2 __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetDevice )( 
            IActMLQCPUQBus2 __RPC_FAR * This,
            /* [in] */ VARIANT varDevice,
            /* [out] */ VARIANT __RPC_FAR *lpvarData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetDevice )( 
            IActMLQCPUQBus2 __RPC_FAR * This,
            /* [in] */ VARIANT varDevice,
            /* [in] */ VARIANT varData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceBlock )( 
            IActMLQCPUQBus2 __RPC_FAR * This,
            /* [in] */ VARIANT varDevice,
            /* [in] */ VARIANT varSize,
            /* [out] */ VARIANT __RPC_FAR *lpvarData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceBlock )( 
            IActMLQCPUQBus2 __RPC_FAR * This,
            /* [in] */ VARIANT varDevice,
            /* [in] */ VARIANT varSize,
            /* [in] */ VARIANT varData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceRandom )( 
            IActMLQCPUQBus2 __RPC_FAR * This,
            /* [in] */ VARIANT varDeviceList,
            /* [in] */ VARIANT varSize,
            /* [out] */ VARIANT __RPC_FAR *lpvarData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceRandom )( 
            IActMLQCPUQBus2 __RPC_FAR * This,
            /* [in] */ VARIANT varDeviceList,
            /* [in] */ VARIANT varSize,
            /* [in] */ VARIANT varData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadBuffer )( 
            IActMLQCPUQBus2 __RPC_FAR * This,
            /* [in] */ VARIANT varStartIO,
            /* [in] */ VARIANT varAddress,
            /* [in] */ VARIANT varReadSize,
            /* [out] */ VARIANT __RPC_FAR *lpvarData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteBuffer )( 
            IActMLQCPUQBus2 __RPC_FAR * This,
            /* [in] */ VARIANT varStartIO,
            /* [in] */ VARIANT varAddress,
            /* [in] */ VARIANT varReadSize,
            /* [in] */ VARIANT varData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetCpuType )( 
            IActMLQCPUQBus2 __RPC_FAR * This,
            /* [out] */ VARIANT __RPC_FAR *lpvarCpuName,
            /* [out] */ VARIANT __RPC_FAR *lpvarCpuType,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetCpuStatus )( 
            IActMLQCPUQBus2 __RPC_FAR * This,
            /* [in] */ VARIANT varOperation,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetClockData )( 
            IActMLQCPUQBus2 __RPC_FAR * This,
            /* [out] */ VARIANT __RPC_FAR *lpvarYear,
            /* [out] */ VARIANT __RPC_FAR *lpvarMonth,
            /* [out] */ VARIANT __RPC_FAR *lpvarDay,
            /* [out] */ VARIANT __RPC_FAR *lpvarDayOfWeek,
            /* [out] */ VARIANT __RPC_FAR *lpvarHour,
            /* [out] */ VARIANT __RPC_FAR *lpvarMinute,
            /* [out] */ VARIANT __RPC_FAR *lpvarSecond,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetClockData )( 
            IActMLQCPUQBus2 __RPC_FAR * This,
            /* [in] */ VARIANT varYear,
            /* [in] */ VARIANT varMonth,
            /* [in] */ VARIANT varDay,
            /* [in] */ VARIANT varDayOfWeek,
            /* [in] */ VARIANT varHour,
            /* [in] */ VARIANT varMinute,
            /* [in] */ VARIANT varSecond,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *EntryDeviceStatus )( 
            IActMLQCPUQBus2 __RPC_FAR * This,
            /* [in] */ VARIANT varDeviceList,
            /* [in] */ VARIANT varSize,
            /* [in] */ VARIANT varMonitorCycle,
            /* [in] */ VARIANT varData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActIONumber )( 
            IActMLQCPUQBus2 __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActIONumber )( 
            IActMLQCPUQBus2 __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActCpuType )( 
            IActMLQCPUQBus2 __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActCpuType )( 
            IActMLQCPUQBus2 __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *FreeDeviceStatus )( 
            IActMLQCPUQBus2 __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        END_INTERFACE
    } IActMLQCPUQBus2Vtbl;

    interface IActMLQCPUQBus2
    {
        CONST_VTBL struct IActMLQCPUQBus2Vtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IActMLQCPUQBus2_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IActMLQCPUQBus2_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IActMLQCPUQBus2_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IActMLQCPUQBus2_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IActMLQCPUQBus2_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IActMLQCPUQBus2_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IActMLQCPUQBus2_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IActMLQCPUQBus2_Open(This,lpvarReturnCode)	\
    (This)->lpVtbl -> Open(This,lpvarReturnCode)

#define IActMLQCPUQBus2_Close(This,lpvarReturnCode)	\
    (This)->lpVtbl -> Close(This,lpvarReturnCode)

#define IActMLQCPUQBus2_GetDevice(This,varDevice,lpvarData,lpvarReturnCode)	\
    (This)->lpVtbl -> GetDevice(This,varDevice,lpvarData,lpvarReturnCode)

#define IActMLQCPUQBus2_SetDevice(This,varDevice,varData,lpvarReturnCode)	\
    (This)->lpVtbl -> SetDevice(This,varDevice,varData,lpvarReturnCode)

#define IActMLQCPUQBus2_ReadDeviceBlock(This,varDevice,varSize,lpvarData,lpvarReturnCode)	\
    (This)->lpVtbl -> ReadDeviceBlock(This,varDevice,varSize,lpvarData,lpvarReturnCode)

#define IActMLQCPUQBus2_WriteDeviceBlock(This,varDevice,varSize,varData,lpvarReturnCode)	\
    (This)->lpVtbl -> WriteDeviceBlock(This,varDevice,varSize,varData,lpvarReturnCode)

#define IActMLQCPUQBus2_ReadDeviceRandom(This,varDeviceList,varSize,lpvarData,lpvarReturnCode)	\
    (This)->lpVtbl -> ReadDeviceRandom(This,varDeviceList,varSize,lpvarData,lpvarReturnCode)

#define IActMLQCPUQBus2_WriteDeviceRandom(This,varDeviceList,varSize,varData,lpvarReturnCode)	\
    (This)->lpVtbl -> WriteDeviceRandom(This,varDeviceList,varSize,varData,lpvarReturnCode)

#define IActMLQCPUQBus2_ReadBuffer(This,varStartIO,varAddress,varReadSize,lpvarData,lpvarReturnCode)	\
    (This)->lpVtbl -> ReadBuffer(This,varStartIO,varAddress,varReadSize,lpvarData,lpvarReturnCode)

#define IActMLQCPUQBus2_WriteBuffer(This,varStartIO,varAddress,varReadSize,varData,lpvarReturnCode)	\
    (This)->lpVtbl -> WriteBuffer(This,varStartIO,varAddress,varReadSize,varData,lpvarReturnCode)

#define IActMLQCPUQBus2_GetCpuType(This,lpvarCpuName,lpvarCpuType,lpvarReturnCode)	\
    (This)->lpVtbl -> GetCpuType(This,lpvarCpuName,lpvarCpuType,lpvarReturnCode)

#define IActMLQCPUQBus2_SetCpuStatus(This,varOperation,lpvarReturnCode)	\
    (This)->lpVtbl -> SetCpuStatus(This,varOperation,lpvarReturnCode)

#define IActMLQCPUQBus2_GetClockData(This,lpvarYear,lpvarMonth,lpvarDay,lpvarDayOfWeek,lpvarHour,lpvarMinute,lpvarSecond,lpvarReturnCode)	\
    (This)->lpVtbl -> GetClockData(This,lpvarYear,lpvarMonth,lpvarDay,lpvarDayOfWeek,lpvarHour,lpvarMinute,lpvarSecond,lpvarReturnCode)

#define IActMLQCPUQBus2_SetClockData(This,varYear,varMonth,varDay,varDayOfWeek,varHour,varMinute,varSecond,lpvarReturnCode)	\
    (This)->lpVtbl -> SetClockData(This,varYear,varMonth,varDay,varDayOfWeek,varHour,varMinute,varSecond,lpvarReturnCode)

#define IActMLQCPUQBus2_EntryDeviceStatus(This,varDeviceList,varSize,varMonitorCycle,varData,lpvarReturnCode)	\
    (This)->lpVtbl -> EntryDeviceStatus(This,varDeviceList,varSize,varMonitorCycle,varData,lpvarReturnCode)

#define IActMLQCPUQBus2_get_ActIONumber(This,pVal)	\
    (This)->lpVtbl -> get_ActIONumber(This,pVal)

#define IActMLQCPUQBus2_put_ActIONumber(This,newVal)	\
    (This)->lpVtbl -> put_ActIONumber(This,newVal)

#define IActMLQCPUQBus2_get_ActCpuType(This,pVal)	\
    (This)->lpVtbl -> get_ActCpuType(This,pVal)

#define IActMLQCPUQBus2_put_ActCpuType(This,newVal)	\
    (This)->lpVtbl -> put_ActCpuType(This,newVal)

#define IActMLQCPUQBus2_FreeDeviceStatus(This,lpvarReturnCode)	\
    (This)->lpVtbl -> FreeDeviceStatus(This,lpvarReturnCode)


#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IActMLQCPUQBus2_INTERFACE_DEFINED__ */


#ifndef __IActMLQCPUQBus3_INTERFACE_DEFINED__
#define __IActMLQCPUQBus3_INTERFACE_DEFINED__

/* interface IActMLQCPUQBus3 */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IActMLQCPUQBus3;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("115992F4-6EC2-11d5-9314-009099244EFD")
    IActMLQCPUQBus3 : public IActMLQCPUQBus2
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

    typedef struct IActMLQCPUQBus3Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IActMLQCPUQBus3 __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IActMLQCPUQBus3 __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IActMLQCPUQBus3 __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IActMLQCPUQBus3 __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IActMLQCPUQBus3 __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IActMLQCPUQBus3 __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IActMLQCPUQBus3 __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Open )( 
            IActMLQCPUQBus3 __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Close )( 
            IActMLQCPUQBus3 __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetDevice )( 
            IActMLQCPUQBus3 __RPC_FAR * This,
            /* [in] */ VARIANT varDevice,
            /* [out] */ VARIANT __RPC_FAR *lpvarData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetDevice )( 
            IActMLQCPUQBus3 __RPC_FAR * This,
            /* [in] */ VARIANT varDevice,
            /* [in] */ VARIANT varData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceBlock )( 
            IActMLQCPUQBus3 __RPC_FAR * This,
            /* [in] */ VARIANT varDevice,
            /* [in] */ VARIANT varSize,
            /* [out] */ VARIANT __RPC_FAR *lpvarData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceBlock )( 
            IActMLQCPUQBus3 __RPC_FAR * This,
            /* [in] */ VARIANT varDevice,
            /* [in] */ VARIANT varSize,
            /* [in] */ VARIANT varData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceRandom )( 
            IActMLQCPUQBus3 __RPC_FAR * This,
            /* [in] */ VARIANT varDeviceList,
            /* [in] */ VARIANT varSize,
            /* [out] */ VARIANT __RPC_FAR *lpvarData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceRandom )( 
            IActMLQCPUQBus3 __RPC_FAR * This,
            /* [in] */ VARIANT varDeviceList,
            /* [in] */ VARIANT varSize,
            /* [in] */ VARIANT varData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadBuffer )( 
            IActMLQCPUQBus3 __RPC_FAR * This,
            /* [in] */ VARIANT varStartIO,
            /* [in] */ VARIANT varAddress,
            /* [in] */ VARIANT varReadSize,
            /* [out] */ VARIANT __RPC_FAR *lpvarData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteBuffer )( 
            IActMLQCPUQBus3 __RPC_FAR * This,
            /* [in] */ VARIANT varStartIO,
            /* [in] */ VARIANT varAddress,
            /* [in] */ VARIANT varReadSize,
            /* [in] */ VARIANT varData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetCpuType )( 
            IActMLQCPUQBus3 __RPC_FAR * This,
            /* [out] */ VARIANT __RPC_FAR *lpvarCpuName,
            /* [out] */ VARIANT __RPC_FAR *lpvarCpuType,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetCpuStatus )( 
            IActMLQCPUQBus3 __RPC_FAR * This,
            /* [in] */ VARIANT varOperation,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetClockData )( 
            IActMLQCPUQBus3 __RPC_FAR * This,
            /* [out] */ VARIANT __RPC_FAR *lpvarYear,
            /* [out] */ VARIANT __RPC_FAR *lpvarMonth,
            /* [out] */ VARIANT __RPC_FAR *lpvarDay,
            /* [out] */ VARIANT __RPC_FAR *lpvarDayOfWeek,
            /* [out] */ VARIANT __RPC_FAR *lpvarHour,
            /* [out] */ VARIANT __RPC_FAR *lpvarMinute,
            /* [out] */ VARIANT __RPC_FAR *lpvarSecond,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetClockData )( 
            IActMLQCPUQBus3 __RPC_FAR * This,
            /* [in] */ VARIANT varYear,
            /* [in] */ VARIANT varMonth,
            /* [in] */ VARIANT varDay,
            /* [in] */ VARIANT varDayOfWeek,
            /* [in] */ VARIANT varHour,
            /* [in] */ VARIANT varMinute,
            /* [in] */ VARIANT varSecond,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *EntryDeviceStatus )( 
            IActMLQCPUQBus3 __RPC_FAR * This,
            /* [in] */ VARIANT varDeviceList,
            /* [in] */ VARIANT varSize,
            /* [in] */ VARIANT varMonitorCycle,
            /* [in] */ VARIANT varData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActIONumber )( 
            IActMLQCPUQBus3 __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActIONumber )( 
            IActMLQCPUQBus3 __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActCpuType )( 
            IActMLQCPUQBus3 __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActCpuType )( 
            IActMLQCPUQBus3 __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *FreeDeviceStatus )( 
            IActMLQCPUQBus3 __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceBlock2 )( 
            IActMLQCPUQBus3 __RPC_FAR * This,
            /* [in] */ VARIANT varDevice,
            /* [in] */ VARIANT varSize,
            /* [out] */ VARIANT __RPC_FAR *lpvarData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceBlock2 )( 
            IActMLQCPUQBus3 __RPC_FAR * This,
            /* [in] */ VARIANT varDevice,
            /* [in] */ VARIANT varSize,
            /* [in] */ VARIANT varData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceRandom2 )( 
            IActMLQCPUQBus3 __RPC_FAR * This,
            /* [in] */ VARIANT varDeviceList,
            /* [in] */ VARIANT varSize,
            /* [out] */ VARIANT __RPC_FAR *lpvarData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceRandom2 )( 
            IActMLQCPUQBus3 __RPC_FAR * This,
            /* [in] */ VARIANT varDeviceList,
            /* [in] */ VARIANT varSize,
            /* [in] */ VARIANT varData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetDevice2 )( 
            IActMLQCPUQBus3 __RPC_FAR * This,
            /* [in] */ VARIANT varDevice,
            /* [out] */ VARIANT __RPC_FAR *lpvarData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetDevice2 )( 
            IActMLQCPUQBus3 __RPC_FAR * This,
            /* [in] */ VARIANT varDevice,
            /* [in] */ VARIANT varData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        END_INTERFACE
    } IActMLQCPUQBus3Vtbl;

    interface IActMLQCPUQBus3
    {
        CONST_VTBL struct IActMLQCPUQBus3Vtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IActMLQCPUQBus3_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IActMLQCPUQBus3_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IActMLQCPUQBus3_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IActMLQCPUQBus3_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IActMLQCPUQBus3_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IActMLQCPUQBus3_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IActMLQCPUQBus3_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IActMLQCPUQBus3_Open(This,lpvarReturnCode)	\
    (This)->lpVtbl -> Open(This,lpvarReturnCode)

#define IActMLQCPUQBus3_Close(This,lpvarReturnCode)	\
    (This)->lpVtbl -> Close(This,lpvarReturnCode)

#define IActMLQCPUQBus3_GetDevice(This,varDevice,lpvarData,lpvarReturnCode)	\
    (This)->lpVtbl -> GetDevice(This,varDevice,lpvarData,lpvarReturnCode)

#define IActMLQCPUQBus3_SetDevice(This,varDevice,varData,lpvarReturnCode)	\
    (This)->lpVtbl -> SetDevice(This,varDevice,varData,lpvarReturnCode)

#define IActMLQCPUQBus3_ReadDeviceBlock(This,varDevice,varSize,lpvarData,lpvarReturnCode)	\
    (This)->lpVtbl -> ReadDeviceBlock(This,varDevice,varSize,lpvarData,lpvarReturnCode)

#define IActMLQCPUQBus3_WriteDeviceBlock(This,varDevice,varSize,varData,lpvarReturnCode)	\
    (This)->lpVtbl -> WriteDeviceBlock(This,varDevice,varSize,varData,lpvarReturnCode)

#define IActMLQCPUQBus3_ReadDeviceRandom(This,varDeviceList,varSize,lpvarData,lpvarReturnCode)	\
    (This)->lpVtbl -> ReadDeviceRandom(This,varDeviceList,varSize,lpvarData,lpvarReturnCode)

#define IActMLQCPUQBus3_WriteDeviceRandom(This,varDeviceList,varSize,varData,lpvarReturnCode)	\
    (This)->lpVtbl -> WriteDeviceRandom(This,varDeviceList,varSize,varData,lpvarReturnCode)

#define IActMLQCPUQBus3_ReadBuffer(This,varStartIO,varAddress,varReadSize,lpvarData,lpvarReturnCode)	\
    (This)->lpVtbl -> ReadBuffer(This,varStartIO,varAddress,varReadSize,lpvarData,lpvarReturnCode)

#define IActMLQCPUQBus3_WriteBuffer(This,varStartIO,varAddress,varReadSize,varData,lpvarReturnCode)	\
    (This)->lpVtbl -> WriteBuffer(This,varStartIO,varAddress,varReadSize,varData,lpvarReturnCode)

#define IActMLQCPUQBus3_GetCpuType(This,lpvarCpuName,lpvarCpuType,lpvarReturnCode)	\
    (This)->lpVtbl -> GetCpuType(This,lpvarCpuName,lpvarCpuType,lpvarReturnCode)

#define IActMLQCPUQBus3_SetCpuStatus(This,varOperation,lpvarReturnCode)	\
    (This)->lpVtbl -> SetCpuStatus(This,varOperation,lpvarReturnCode)

#define IActMLQCPUQBus3_GetClockData(This,lpvarYear,lpvarMonth,lpvarDay,lpvarDayOfWeek,lpvarHour,lpvarMinute,lpvarSecond,lpvarReturnCode)	\
    (This)->lpVtbl -> GetClockData(This,lpvarYear,lpvarMonth,lpvarDay,lpvarDayOfWeek,lpvarHour,lpvarMinute,lpvarSecond,lpvarReturnCode)

#define IActMLQCPUQBus3_SetClockData(This,varYear,varMonth,varDay,varDayOfWeek,varHour,varMinute,varSecond,lpvarReturnCode)	\
    (This)->lpVtbl -> SetClockData(This,varYear,varMonth,varDay,varDayOfWeek,varHour,varMinute,varSecond,lpvarReturnCode)

#define IActMLQCPUQBus3_EntryDeviceStatus(This,varDeviceList,varSize,varMonitorCycle,varData,lpvarReturnCode)	\
    (This)->lpVtbl -> EntryDeviceStatus(This,varDeviceList,varSize,varMonitorCycle,varData,lpvarReturnCode)

#define IActMLQCPUQBus3_get_ActIONumber(This,pVal)	\
    (This)->lpVtbl -> get_ActIONumber(This,pVal)

#define IActMLQCPUQBus3_put_ActIONumber(This,newVal)	\
    (This)->lpVtbl -> put_ActIONumber(This,newVal)

#define IActMLQCPUQBus3_get_ActCpuType(This,pVal)	\
    (This)->lpVtbl -> get_ActCpuType(This,pVal)

#define IActMLQCPUQBus3_put_ActCpuType(This,newVal)	\
    (This)->lpVtbl -> put_ActCpuType(This,newVal)

#define IActMLQCPUQBus3_FreeDeviceStatus(This,lpvarReturnCode)	\
    (This)->lpVtbl -> FreeDeviceStatus(This,lpvarReturnCode)



#define IActMLQCPUQBus3_ReadDeviceBlock2(This,varDevice,varSize,lpvarData,lpvarReturnCode)	\
    (This)->lpVtbl -> ReadDeviceBlock2(This,varDevice,varSize,lpvarData,lpvarReturnCode)

#define IActMLQCPUQBus3_WriteDeviceBlock2(This,varDevice,varSize,varData,lpvarReturnCode)	\
    (This)->lpVtbl -> WriteDeviceBlock2(This,varDevice,varSize,varData,lpvarReturnCode)

#define IActMLQCPUQBus3_ReadDeviceRandom2(This,varDeviceList,varSize,lpvarData,lpvarReturnCode)	\
    (This)->lpVtbl -> ReadDeviceRandom2(This,varDeviceList,varSize,lpvarData,lpvarReturnCode)

#define IActMLQCPUQBus3_WriteDeviceRandom2(This,varDeviceList,varSize,varData,lpvarReturnCode)	\
    (This)->lpVtbl -> WriteDeviceRandom2(This,varDeviceList,varSize,varData,lpvarReturnCode)

#define IActMLQCPUQBus3_GetDevice2(This,varDevice,lpvarData,lpvarReturnCode)	\
    (This)->lpVtbl -> GetDevice2(This,varDevice,lpvarData,lpvarReturnCode)

#define IActMLQCPUQBus3_SetDevice2(This,varDevice,varData,lpvarReturnCode)	\
    (This)->lpVtbl -> SetDevice2(This,varDevice,varData,lpvarReturnCode)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActMLQCPUQBus3_ReadDeviceBlock2_Proxy( 
    IActMLQCPUQBus3 __RPC_FAR * This,
    /* [in] */ VARIANT varDevice,
    /* [in] */ VARIANT varSize,
    /* [out] */ VARIANT __RPC_FAR *lpvarData,
    /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);


void __RPC_STUB IActMLQCPUQBus3_ReadDeviceBlock2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActMLQCPUQBus3_WriteDeviceBlock2_Proxy( 
    IActMLQCPUQBus3 __RPC_FAR * This,
    /* [in] */ VARIANT varDevice,
    /* [in] */ VARIANT varSize,
    /* [in] */ VARIANT varData,
    /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);


void __RPC_STUB IActMLQCPUQBus3_WriteDeviceBlock2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActMLQCPUQBus3_ReadDeviceRandom2_Proxy( 
    IActMLQCPUQBus3 __RPC_FAR * This,
    /* [in] */ VARIANT varDeviceList,
    /* [in] */ VARIANT varSize,
    /* [out] */ VARIANT __RPC_FAR *lpvarData,
    /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);


void __RPC_STUB IActMLQCPUQBus3_ReadDeviceRandom2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActMLQCPUQBus3_WriteDeviceRandom2_Proxy( 
    IActMLQCPUQBus3 __RPC_FAR * This,
    /* [in] */ VARIANT varDeviceList,
    /* [in] */ VARIANT varSize,
    /* [in] */ VARIANT varData,
    /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);


void __RPC_STUB IActMLQCPUQBus3_WriteDeviceRandom2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActMLQCPUQBus3_GetDevice2_Proxy( 
    IActMLQCPUQBus3 __RPC_FAR * This,
    /* [in] */ VARIANT varDevice,
    /* [out] */ VARIANT __RPC_FAR *lpvarData,
    /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);


void __RPC_STUB IActMLQCPUQBus3_GetDevice2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActMLQCPUQBus3_SetDevice2_Proxy( 
    IActMLQCPUQBus3 __RPC_FAR * This,
    /* [in] */ VARIANT varDevice,
    /* [in] */ VARIANT varData,
    /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);


void __RPC_STUB IActMLQCPUQBus3_SetDevice2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IActMLQCPUQBus3_INTERFACE_DEFINED__ */


#ifndef __IActQSS_INTERFACE_DEFINED__
#define __IActQSS_INTERFACE_DEFINED__

/* interface IActQSS */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IActQSS;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("A6BE4A91-70EC-11D5-9318-009099244EFD")
    IActQSS : public IDispatch
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

    typedef struct IActQSSVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IActQSS __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IActQSS __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IActQSS __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IActQSS __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IActQSS __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IActQSS __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IActQSS __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Open )( 
            IActQSS __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Close )( 
            IActQSS __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetDevice )( 
            IActQSS __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [out] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetDevice )( 
            IActQSS __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceBlock )( 
            IActQSS __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lSize,
            /* [size_is][out] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceBlock )( 
            IActQSS __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lSize,
            /* [size_is][in] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceRandom )( 
            IActQSS __RPC_FAR * This,
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG lSize,
            /* [size_is][out] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceRandom )( 
            IActQSS __RPC_FAR * This,
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG lSize,
            /* [size_is][in] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadBuffer )( 
            IActQSS __RPC_FAR * This,
            /* [in] */ LONG lStartIO,
            /* [in] */ LONG lAddress,
            /* [in] */ LONG lReadSize,
            /* [size_is][out] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteBuffer )( 
            IActQSS __RPC_FAR * This,
            /* [in] */ LONG lStartIO,
            /* [in] */ LONG lAddress,
            /* [in] */ LONG lWriteSize,
            /* [size_is][in] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetClockData )( 
            IActQSS __RPC_FAR * This,
            /* [out] */ SHORT __RPC_FAR *lpsYear,
            /* [out] */ SHORT __RPC_FAR *lpsMonth,
            /* [out] */ SHORT __RPC_FAR *lpsDay,
            /* [out] */ SHORT __RPC_FAR *lpsDayOfWeek,
            /* [out] */ SHORT __RPC_FAR *lpsHour,
            /* [out] */ SHORT __RPC_FAR *lpsMinute,
            /* [out] */ SHORT __RPC_FAR *lpsSecond,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetClockData )( 
            IActQSS __RPC_FAR * This,
            /* [in] */ SHORT sYear,
            /* [in] */ SHORT sMonth,
            /* [in] */ SHORT sDay,
            /* [in] */ SHORT sDayOfWeek,
            /* [in] */ SHORT sHour,
            /* [in] */ SHORT sMinute,
            /* [in] */ SHORT sSecond,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetCpuType )( 
            IActQSS __RPC_FAR * This,
            /* [string][out] */ BSTR __RPC_FAR *szCpuName,
            /* [out] */ LONG __RPC_FAR *lplCpuCode,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetCpuStatus )( 
            IActQSS __RPC_FAR * This,
            /* [in] */ LONG lOperation,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CheckDeviceString )( 
            IActQSS __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lCheckType,
            /* [in] */ LONG lSize,
            /* [out] */ LONG __RPC_FAR *lplDeviceType,
            /* [string][out] */ BSTR __RPC_FAR *lpszDeviceName,
            /* [out] */ LONG __RPC_FAR *lplDeviceNumber,
            /* [out] */ LONG __RPC_FAR *lplDeviceRadix,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *EntryDeviceStatus )( 
            IActQSS __RPC_FAR * This,
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG lSize,
            /* [in] */ LONG lMonitorCycle,
            /* [size_is][in] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *FreeDeviceStatus )( 
            IActQSS __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceBlock2 )( 
            IActQSS __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lSize,
            /* [size_is][out] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceBlock2 )( 
            IActQSS __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lSize,
            /* [size_is][in] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceRandom2 )( 
            IActQSS __RPC_FAR * This,
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG lSize,
            /* [size_is][out] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceRandom2 )( 
            IActQSS __RPC_FAR * This,
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG lSize,
            /* [size_is][in] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetDevice2 )( 
            IActQSS __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [out] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetDevice2 )( 
            IActQSS __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ SHORT sData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActNetworkNumber )( 
            IActQSS __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActNetworkNumber )( 
            IActQSS __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActStationNumber )( 
            IActQSS __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActStationNumber )( 
            IActQSS __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActUnitNumber )( 
            IActQSS __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActUnitNumber )( 
            IActQSS __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActIONumber )( 
            IActQSS __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActIONumber )( 
            IActQSS __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActCpuType )( 
            IActQSS __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActCpuType )( 
            IActQSS __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActDestinationIONumber )( 
            IActQSS __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActDestinationIONumber )( 
            IActQSS __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActMultiDropChannelNumber )( 
            IActQSS __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActMultiDropChannelNumber )( 
            IActQSS __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActThroughNetworkType )( 
            IActQSS __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActThroughNetworkType )( 
            IActQSS __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActIntelligentPreferenceBit )( 
            IActQSS __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActIntelligentPreferenceBit )( 
            IActQSS __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActDidPropertyBit )( 
            IActQSS __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActDidPropertyBit )( 
            IActQSS __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActDsidPropertyBit )( 
            IActQSS __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActDsidPropertyBit )( 
            IActQSS __RPC_FAR * This,
            /* [in] */ long newVal);
        
        END_INTERFACE
    } IActQSSVtbl;

    interface IActQSS
    {
        CONST_VTBL struct IActQSSVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IActQSS_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IActQSS_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IActQSS_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IActQSS_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IActQSS_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IActQSS_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IActQSS_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IActQSS_Open(This,lplReturnCode)	\
    (This)->lpVtbl -> Open(This,lplReturnCode)

#define IActQSS_Close(This,lplReturnCode)	\
    (This)->lpVtbl -> Close(This,lplReturnCode)

#define IActQSS_GetDevice(This,szDevice,lplData,lplReturnCode)	\
    (This)->lpVtbl -> GetDevice(This,szDevice,lplData,lplReturnCode)

#define IActQSS_SetDevice(This,szDevice,lData,lplReturnCode)	\
    (This)->lpVtbl -> SetDevice(This,szDevice,lData,lplReturnCode)

#define IActQSS_ReadDeviceBlock(This,szDevice,lSize,lplData,lplReturnCode)	\
    (This)->lpVtbl -> ReadDeviceBlock(This,szDevice,lSize,lplData,lplReturnCode)

#define IActQSS_WriteDeviceBlock(This,szDevice,lSize,lplData,lplReturnCode)	\
    (This)->lpVtbl -> WriteDeviceBlock(This,szDevice,lSize,lplData,lplReturnCode)

#define IActQSS_ReadDeviceRandom(This,szDeviceList,lSize,lplData,lplReturnCode)	\
    (This)->lpVtbl -> ReadDeviceRandom(This,szDeviceList,lSize,lplData,lplReturnCode)

#define IActQSS_WriteDeviceRandom(This,szDeviceList,lSize,lplData,lplReturnCode)	\
    (This)->lpVtbl -> WriteDeviceRandom(This,szDeviceList,lSize,lplData,lplReturnCode)

#define IActQSS_ReadBuffer(This,lStartIO,lAddress,lReadSize,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> ReadBuffer(This,lStartIO,lAddress,lReadSize,lpsData,lplReturnCode)

#define IActQSS_WriteBuffer(This,lStartIO,lAddress,lWriteSize,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> WriteBuffer(This,lStartIO,lAddress,lWriteSize,lpsData,lplReturnCode)

#define IActQSS_GetClockData(This,lpsYear,lpsMonth,lpsDay,lpsDayOfWeek,lpsHour,lpsMinute,lpsSecond,lplReturnCode)	\
    (This)->lpVtbl -> GetClockData(This,lpsYear,lpsMonth,lpsDay,lpsDayOfWeek,lpsHour,lpsMinute,lpsSecond,lplReturnCode)

#define IActQSS_SetClockData(This,sYear,sMonth,sDay,sDayOfWeek,sHour,sMinute,sSecond,lplReturnCode)	\
    (This)->lpVtbl -> SetClockData(This,sYear,sMonth,sDay,sDayOfWeek,sHour,sMinute,sSecond,lplReturnCode)

#define IActQSS_GetCpuType(This,szCpuName,lplCpuCode,lplReturnCode)	\
    (This)->lpVtbl -> GetCpuType(This,szCpuName,lplCpuCode,lplReturnCode)

#define IActQSS_SetCpuStatus(This,lOperation,lplReturnCode)	\
    (This)->lpVtbl -> SetCpuStatus(This,lOperation,lplReturnCode)

#define IActQSS_CheckDeviceString(This,szDevice,lCheckType,lSize,lplDeviceType,lpszDeviceName,lplDeviceNumber,lplDeviceRadix,lplReturnCode)	\
    (This)->lpVtbl -> CheckDeviceString(This,szDevice,lCheckType,lSize,lplDeviceType,lpszDeviceName,lplDeviceNumber,lplDeviceRadix,lplReturnCode)

#define IActQSS_EntryDeviceStatus(This,szDeviceList,lSize,lMonitorCycle,lplData,lplReturnCode)	\
    (This)->lpVtbl -> EntryDeviceStatus(This,szDeviceList,lSize,lMonitorCycle,lplData,lplReturnCode)

#define IActQSS_FreeDeviceStatus(This,lplReturnCode)	\
    (This)->lpVtbl -> FreeDeviceStatus(This,lplReturnCode)

#define IActQSS_ReadDeviceBlock2(This,szDevice,lSize,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> ReadDeviceBlock2(This,szDevice,lSize,lpsData,lplReturnCode)

#define IActQSS_WriteDeviceBlock2(This,szDevice,lSize,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> WriteDeviceBlock2(This,szDevice,lSize,lpsData,lplReturnCode)

#define IActQSS_ReadDeviceRandom2(This,szDeviceList,lSize,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> ReadDeviceRandom2(This,szDeviceList,lSize,lpsData,lplReturnCode)

#define IActQSS_WriteDeviceRandom2(This,szDeviceList,lSize,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> WriteDeviceRandom2(This,szDeviceList,lSize,lpsData,lplReturnCode)

#define IActQSS_GetDevice2(This,szDevice,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> GetDevice2(This,szDevice,lpsData,lplReturnCode)

#define IActQSS_SetDevice2(This,szDevice,sData,lplReturnCode)	\
    (This)->lpVtbl -> SetDevice2(This,szDevice,sData,lplReturnCode)

#define IActQSS_get_ActNetworkNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActNetworkNumber(This,pVal)

#define IActQSS_put_ActNetworkNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActNetworkNumber(This,newVal)

#define IActQSS_get_ActStationNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActStationNumber(This,pVal)

#define IActQSS_put_ActStationNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActStationNumber(This,newVal)

#define IActQSS_get_ActUnitNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActUnitNumber(This,pVal)

#define IActQSS_put_ActUnitNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActUnitNumber(This,newVal)

#define IActQSS_get_ActIONumber(This,pVal)	\
    (This)->lpVtbl -> get_ActIONumber(This,pVal)

#define IActQSS_put_ActIONumber(This,newVal)	\
    (This)->lpVtbl -> put_ActIONumber(This,newVal)

#define IActQSS_get_ActCpuType(This,pVal)	\
    (This)->lpVtbl -> get_ActCpuType(This,pVal)

#define IActQSS_put_ActCpuType(This,newVal)	\
    (This)->lpVtbl -> put_ActCpuType(This,newVal)

#define IActQSS_get_ActDestinationIONumber(This,pVal)	\
    (This)->lpVtbl -> get_ActDestinationIONumber(This,pVal)

#define IActQSS_put_ActDestinationIONumber(This,newVal)	\
    (This)->lpVtbl -> put_ActDestinationIONumber(This,newVal)

#define IActQSS_get_ActMultiDropChannelNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActMultiDropChannelNumber(This,pVal)

#define IActQSS_put_ActMultiDropChannelNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActMultiDropChannelNumber(This,newVal)

#define IActQSS_get_ActThroughNetworkType(This,pVal)	\
    (This)->lpVtbl -> get_ActThroughNetworkType(This,pVal)

#define IActQSS_put_ActThroughNetworkType(This,newVal)	\
    (This)->lpVtbl -> put_ActThroughNetworkType(This,newVal)

#define IActQSS_get_ActIntelligentPreferenceBit(This,pVal)	\
    (This)->lpVtbl -> get_ActIntelligentPreferenceBit(This,pVal)

#define IActQSS_put_ActIntelligentPreferenceBit(This,newVal)	\
    (This)->lpVtbl -> put_ActIntelligentPreferenceBit(This,newVal)

#define IActQSS_get_ActDidPropertyBit(This,pVal)	\
    (This)->lpVtbl -> get_ActDidPropertyBit(This,pVal)

#define IActQSS_put_ActDidPropertyBit(This,newVal)	\
    (This)->lpVtbl -> put_ActDidPropertyBit(This,newVal)

#define IActQSS_get_ActDsidPropertyBit(This,pVal)	\
    (This)->lpVtbl -> get_ActDsidPropertyBit(This,pVal)

#define IActQSS_put_ActDsidPropertyBit(This,newVal)	\
    (This)->lpVtbl -> put_ActDsidPropertyBit(This,newVal)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActQSS_Open_Proxy( 
    IActQSS __RPC_FAR * This,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActQSS_Open_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActQSS_Close_Proxy( 
    IActQSS __RPC_FAR * This,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActQSS_Close_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActQSS_GetDevice_Proxy( 
    IActQSS __RPC_FAR * This,
    /* [string][in] */ BSTR szDevice,
    /* [out] */ LONG __RPC_FAR *lplData,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActQSS_GetDevice_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActQSS_SetDevice_Proxy( 
    IActQSS __RPC_FAR * This,
    /* [string][in] */ BSTR szDevice,
    /* [in] */ LONG lData,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActQSS_SetDevice_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActQSS_ReadDeviceBlock_Proxy( 
    IActQSS __RPC_FAR * This,
    /* [string][in] */ BSTR szDevice,
    /* [in] */ LONG lSize,
    /* [size_is][out] */ LONG __RPC_FAR *lplData,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActQSS_ReadDeviceBlock_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActQSS_WriteDeviceBlock_Proxy( 
    IActQSS __RPC_FAR * This,
    /* [string][in] */ BSTR szDevice,
    /* [in] */ LONG lSize,
    /* [size_is][in] */ LONG __RPC_FAR *lplData,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActQSS_WriteDeviceBlock_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActQSS_ReadDeviceRandom_Proxy( 
    IActQSS __RPC_FAR * This,
    /* [string][in] */ BSTR szDeviceList,
    /* [in] */ LONG lSize,
    /* [size_is][out] */ LONG __RPC_FAR *lplData,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActQSS_ReadDeviceRandom_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActQSS_WriteDeviceRandom_Proxy( 
    IActQSS __RPC_FAR * This,
    /* [string][in] */ BSTR szDeviceList,
    /* [in] */ LONG lSize,
    /* [size_is][in] */ LONG __RPC_FAR *lplData,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActQSS_WriteDeviceRandom_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActQSS_ReadBuffer_Proxy( 
    IActQSS __RPC_FAR * This,
    /* [in] */ LONG lStartIO,
    /* [in] */ LONG lAddress,
    /* [in] */ LONG lReadSize,
    /* [size_is][out] */ SHORT __RPC_FAR *lpsData,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActQSS_ReadBuffer_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActQSS_WriteBuffer_Proxy( 
    IActQSS __RPC_FAR * This,
    /* [in] */ LONG lStartIO,
    /* [in] */ LONG lAddress,
    /* [in] */ LONG lWriteSize,
    /* [size_is][in] */ SHORT __RPC_FAR *lpsData,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActQSS_WriteBuffer_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActQSS_GetClockData_Proxy( 
    IActQSS __RPC_FAR * This,
    /* [out] */ SHORT __RPC_FAR *lpsYear,
    /* [out] */ SHORT __RPC_FAR *lpsMonth,
    /* [out] */ SHORT __RPC_FAR *lpsDay,
    /* [out] */ SHORT __RPC_FAR *lpsDayOfWeek,
    /* [out] */ SHORT __RPC_FAR *lpsHour,
    /* [out] */ SHORT __RPC_FAR *lpsMinute,
    /* [out] */ SHORT __RPC_FAR *lpsSecond,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActQSS_GetClockData_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActQSS_SetClockData_Proxy( 
    IActQSS __RPC_FAR * This,
    /* [in] */ SHORT sYear,
    /* [in] */ SHORT sMonth,
    /* [in] */ SHORT sDay,
    /* [in] */ SHORT sDayOfWeek,
    /* [in] */ SHORT sHour,
    /* [in] */ SHORT sMinute,
    /* [in] */ SHORT sSecond,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActQSS_SetClockData_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActQSS_GetCpuType_Proxy( 
    IActQSS __RPC_FAR * This,
    /* [string][out] */ BSTR __RPC_FAR *szCpuName,
    /* [out] */ LONG __RPC_FAR *lplCpuCode,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActQSS_GetCpuType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActQSS_SetCpuStatus_Proxy( 
    IActQSS __RPC_FAR * This,
    /* [in] */ LONG lOperation,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActQSS_SetCpuStatus_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActQSS_CheckDeviceString_Proxy( 
    IActQSS __RPC_FAR * This,
    /* [string][in] */ BSTR szDevice,
    /* [in] */ LONG lCheckType,
    /* [in] */ LONG lSize,
    /* [out] */ LONG __RPC_FAR *lplDeviceType,
    /* [string][out] */ BSTR __RPC_FAR *lpszDeviceName,
    /* [out] */ LONG __RPC_FAR *lplDeviceNumber,
    /* [out] */ LONG __RPC_FAR *lplDeviceRadix,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActQSS_CheckDeviceString_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActQSS_EntryDeviceStatus_Proxy( 
    IActQSS __RPC_FAR * This,
    /* [string][in] */ BSTR szDeviceList,
    /* [in] */ LONG lSize,
    /* [in] */ LONG lMonitorCycle,
    /* [size_is][in] */ LONG __RPC_FAR *lplData,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActQSS_EntryDeviceStatus_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActQSS_FreeDeviceStatus_Proxy( 
    IActQSS __RPC_FAR * This,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActQSS_FreeDeviceStatus_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActQSS_ReadDeviceBlock2_Proxy( 
    IActQSS __RPC_FAR * This,
    /* [string][in] */ BSTR szDevice,
    /* [in] */ LONG lSize,
    /* [size_is][out] */ SHORT __RPC_FAR *lpsData,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActQSS_ReadDeviceBlock2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActQSS_WriteDeviceBlock2_Proxy( 
    IActQSS __RPC_FAR * This,
    /* [string][in] */ BSTR szDevice,
    /* [in] */ LONG lSize,
    /* [size_is][in] */ SHORT __RPC_FAR *lpsData,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActQSS_WriteDeviceBlock2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActQSS_ReadDeviceRandom2_Proxy( 
    IActQSS __RPC_FAR * This,
    /* [string][in] */ BSTR szDeviceList,
    /* [in] */ LONG lSize,
    /* [size_is][out] */ SHORT __RPC_FAR *lpsData,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActQSS_ReadDeviceRandom2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActQSS_WriteDeviceRandom2_Proxy( 
    IActQSS __RPC_FAR * This,
    /* [string][in] */ BSTR szDeviceList,
    /* [in] */ LONG lSize,
    /* [size_is][in] */ SHORT __RPC_FAR *lpsData,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActQSS_WriteDeviceRandom2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActQSS_GetDevice2_Proxy( 
    IActQSS __RPC_FAR * This,
    /* [string][in] */ BSTR szDevice,
    /* [out] */ SHORT __RPC_FAR *lpsData,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActQSS_GetDevice2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActQSS_SetDevice2_Proxy( 
    IActQSS __RPC_FAR * This,
    /* [string][in] */ BSTR szDevice,
    /* [in] */ SHORT sData,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActQSS_SetDevice2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActQSS_get_ActNetworkNumber_Proxy( 
    IActQSS __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IActQSS_get_ActNetworkNumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActQSS_put_ActNetworkNumber_Proxy( 
    IActQSS __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB IActQSS_put_ActNetworkNumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActQSS_get_ActStationNumber_Proxy( 
    IActQSS __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IActQSS_get_ActStationNumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActQSS_put_ActStationNumber_Proxy( 
    IActQSS __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB IActQSS_put_ActStationNumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActQSS_get_ActUnitNumber_Proxy( 
    IActQSS __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IActQSS_get_ActUnitNumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActQSS_put_ActUnitNumber_Proxy( 
    IActQSS __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB IActQSS_put_ActUnitNumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActQSS_get_ActIONumber_Proxy( 
    IActQSS __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IActQSS_get_ActIONumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActQSS_put_ActIONumber_Proxy( 
    IActQSS __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB IActQSS_put_ActIONumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActQSS_get_ActCpuType_Proxy( 
    IActQSS __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IActQSS_get_ActCpuType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActQSS_put_ActCpuType_Proxy( 
    IActQSS __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB IActQSS_put_ActCpuType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActQSS_get_ActDestinationIONumber_Proxy( 
    IActQSS __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IActQSS_get_ActDestinationIONumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActQSS_put_ActDestinationIONumber_Proxy( 
    IActQSS __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB IActQSS_put_ActDestinationIONumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActQSS_get_ActMultiDropChannelNumber_Proxy( 
    IActQSS __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IActQSS_get_ActMultiDropChannelNumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActQSS_put_ActMultiDropChannelNumber_Proxy( 
    IActQSS __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB IActQSS_put_ActMultiDropChannelNumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActQSS_get_ActThroughNetworkType_Proxy( 
    IActQSS __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IActQSS_get_ActThroughNetworkType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActQSS_put_ActThroughNetworkType_Proxy( 
    IActQSS __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB IActQSS_put_ActThroughNetworkType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActQSS_get_ActIntelligentPreferenceBit_Proxy( 
    IActQSS __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IActQSS_get_ActIntelligentPreferenceBit_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActQSS_put_ActIntelligentPreferenceBit_Proxy( 
    IActQSS __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB IActQSS_put_ActIntelligentPreferenceBit_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActQSS_get_ActDidPropertyBit_Proxy( 
    IActQSS __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IActQSS_get_ActDidPropertyBit_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActQSS_put_ActDidPropertyBit_Proxy( 
    IActQSS __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB IActQSS_put_ActDidPropertyBit_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActQSS_get_ActDsidPropertyBit_Proxy( 
    IActQSS __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IActQSS_get_ActDsidPropertyBit_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActQSS_put_ActDsidPropertyBit_Proxy( 
    IActQSS __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB IActQSS_put_ActDsidPropertyBit_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IActQSS_INTERFACE_DEFINED__ */


#ifndef __IActQSS2_INTERFACE_DEFINED__
#define __IActQSS2_INTERFACE_DEFINED__

/* interface IActQSS2 */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IActQSS2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("87166034-710B-11d5-9318-009099244EFD")
    IActQSS2 : public IActQSS
    {
    public:
    };
    
#else 	/* C style interface */

    typedef struct IActQSS2Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IActQSS2 __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IActQSS2 __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IActQSS2 __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IActQSS2 __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IActQSS2 __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IActQSS2 __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IActQSS2 __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Open )( 
            IActQSS2 __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Close )( 
            IActQSS2 __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetDevice )( 
            IActQSS2 __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [out] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetDevice )( 
            IActQSS2 __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceBlock )( 
            IActQSS2 __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lSize,
            /* [size_is][out] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceBlock )( 
            IActQSS2 __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lSize,
            /* [size_is][in] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceRandom )( 
            IActQSS2 __RPC_FAR * This,
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG lSize,
            /* [size_is][out] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceRandom )( 
            IActQSS2 __RPC_FAR * This,
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG lSize,
            /* [size_is][in] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadBuffer )( 
            IActQSS2 __RPC_FAR * This,
            /* [in] */ LONG lStartIO,
            /* [in] */ LONG lAddress,
            /* [in] */ LONG lReadSize,
            /* [size_is][out] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteBuffer )( 
            IActQSS2 __RPC_FAR * This,
            /* [in] */ LONG lStartIO,
            /* [in] */ LONG lAddress,
            /* [in] */ LONG lWriteSize,
            /* [size_is][in] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetClockData )( 
            IActQSS2 __RPC_FAR * This,
            /* [out] */ SHORT __RPC_FAR *lpsYear,
            /* [out] */ SHORT __RPC_FAR *lpsMonth,
            /* [out] */ SHORT __RPC_FAR *lpsDay,
            /* [out] */ SHORT __RPC_FAR *lpsDayOfWeek,
            /* [out] */ SHORT __RPC_FAR *lpsHour,
            /* [out] */ SHORT __RPC_FAR *lpsMinute,
            /* [out] */ SHORT __RPC_FAR *lpsSecond,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetClockData )( 
            IActQSS2 __RPC_FAR * This,
            /* [in] */ SHORT sYear,
            /* [in] */ SHORT sMonth,
            /* [in] */ SHORT sDay,
            /* [in] */ SHORT sDayOfWeek,
            /* [in] */ SHORT sHour,
            /* [in] */ SHORT sMinute,
            /* [in] */ SHORT sSecond,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetCpuType )( 
            IActQSS2 __RPC_FAR * This,
            /* [string][out] */ BSTR __RPC_FAR *szCpuName,
            /* [out] */ LONG __RPC_FAR *lplCpuCode,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetCpuStatus )( 
            IActQSS2 __RPC_FAR * This,
            /* [in] */ LONG lOperation,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CheckDeviceString )( 
            IActQSS2 __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lCheckType,
            /* [in] */ LONG lSize,
            /* [out] */ LONG __RPC_FAR *lplDeviceType,
            /* [string][out] */ BSTR __RPC_FAR *lpszDeviceName,
            /* [out] */ LONG __RPC_FAR *lplDeviceNumber,
            /* [out] */ LONG __RPC_FAR *lplDeviceRadix,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *EntryDeviceStatus )( 
            IActQSS2 __RPC_FAR * This,
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG lSize,
            /* [in] */ LONG lMonitorCycle,
            /* [size_is][in] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *FreeDeviceStatus )( 
            IActQSS2 __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceBlock2 )( 
            IActQSS2 __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lSize,
            /* [size_is][out] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceBlock2 )( 
            IActQSS2 __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lSize,
            /* [size_is][in] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceRandom2 )( 
            IActQSS2 __RPC_FAR * This,
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG lSize,
            /* [size_is][out] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceRandom2 )( 
            IActQSS2 __RPC_FAR * This,
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG lSize,
            /* [size_is][in] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetDevice2 )( 
            IActQSS2 __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [out] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetDevice2 )( 
            IActQSS2 __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ SHORT sData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActNetworkNumber )( 
            IActQSS2 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActNetworkNumber )( 
            IActQSS2 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActStationNumber )( 
            IActQSS2 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActStationNumber )( 
            IActQSS2 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActUnitNumber )( 
            IActQSS2 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActUnitNumber )( 
            IActQSS2 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActIONumber )( 
            IActQSS2 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActIONumber )( 
            IActQSS2 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActCpuType )( 
            IActQSS2 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActCpuType )( 
            IActQSS2 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActDestinationIONumber )( 
            IActQSS2 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActDestinationIONumber )( 
            IActQSS2 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActMultiDropChannelNumber )( 
            IActQSS2 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActMultiDropChannelNumber )( 
            IActQSS2 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActThroughNetworkType )( 
            IActQSS2 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActThroughNetworkType )( 
            IActQSS2 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActIntelligentPreferenceBit )( 
            IActQSS2 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActIntelligentPreferenceBit )( 
            IActQSS2 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActDidPropertyBit )( 
            IActQSS2 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActDidPropertyBit )( 
            IActQSS2 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActDsidPropertyBit )( 
            IActQSS2 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActDsidPropertyBit )( 
            IActQSS2 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        END_INTERFACE
    } IActQSS2Vtbl;

    interface IActQSS2
    {
        CONST_VTBL struct IActQSS2Vtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IActQSS2_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IActQSS2_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IActQSS2_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IActQSS2_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IActQSS2_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IActQSS2_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IActQSS2_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IActQSS2_Open(This,lplReturnCode)	\
    (This)->lpVtbl -> Open(This,lplReturnCode)

#define IActQSS2_Close(This,lplReturnCode)	\
    (This)->lpVtbl -> Close(This,lplReturnCode)

#define IActQSS2_GetDevice(This,szDevice,lplData,lplReturnCode)	\
    (This)->lpVtbl -> GetDevice(This,szDevice,lplData,lplReturnCode)

#define IActQSS2_SetDevice(This,szDevice,lData,lplReturnCode)	\
    (This)->lpVtbl -> SetDevice(This,szDevice,lData,lplReturnCode)

#define IActQSS2_ReadDeviceBlock(This,szDevice,lSize,lplData,lplReturnCode)	\
    (This)->lpVtbl -> ReadDeviceBlock(This,szDevice,lSize,lplData,lplReturnCode)

#define IActQSS2_WriteDeviceBlock(This,szDevice,lSize,lplData,lplReturnCode)	\
    (This)->lpVtbl -> WriteDeviceBlock(This,szDevice,lSize,lplData,lplReturnCode)

#define IActQSS2_ReadDeviceRandom(This,szDeviceList,lSize,lplData,lplReturnCode)	\
    (This)->lpVtbl -> ReadDeviceRandom(This,szDeviceList,lSize,lplData,lplReturnCode)

#define IActQSS2_WriteDeviceRandom(This,szDeviceList,lSize,lplData,lplReturnCode)	\
    (This)->lpVtbl -> WriteDeviceRandom(This,szDeviceList,lSize,lplData,lplReturnCode)

#define IActQSS2_ReadBuffer(This,lStartIO,lAddress,lReadSize,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> ReadBuffer(This,lStartIO,lAddress,lReadSize,lpsData,lplReturnCode)

#define IActQSS2_WriteBuffer(This,lStartIO,lAddress,lWriteSize,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> WriteBuffer(This,lStartIO,lAddress,lWriteSize,lpsData,lplReturnCode)

#define IActQSS2_GetClockData(This,lpsYear,lpsMonth,lpsDay,lpsDayOfWeek,lpsHour,lpsMinute,lpsSecond,lplReturnCode)	\
    (This)->lpVtbl -> GetClockData(This,lpsYear,lpsMonth,lpsDay,lpsDayOfWeek,lpsHour,lpsMinute,lpsSecond,lplReturnCode)

#define IActQSS2_SetClockData(This,sYear,sMonth,sDay,sDayOfWeek,sHour,sMinute,sSecond,lplReturnCode)	\
    (This)->lpVtbl -> SetClockData(This,sYear,sMonth,sDay,sDayOfWeek,sHour,sMinute,sSecond,lplReturnCode)

#define IActQSS2_GetCpuType(This,szCpuName,lplCpuCode,lplReturnCode)	\
    (This)->lpVtbl -> GetCpuType(This,szCpuName,lplCpuCode,lplReturnCode)

#define IActQSS2_SetCpuStatus(This,lOperation,lplReturnCode)	\
    (This)->lpVtbl -> SetCpuStatus(This,lOperation,lplReturnCode)

#define IActQSS2_CheckDeviceString(This,szDevice,lCheckType,lSize,lplDeviceType,lpszDeviceName,lplDeviceNumber,lplDeviceRadix,lplReturnCode)	\
    (This)->lpVtbl -> CheckDeviceString(This,szDevice,lCheckType,lSize,lplDeviceType,lpszDeviceName,lplDeviceNumber,lplDeviceRadix,lplReturnCode)

#define IActQSS2_EntryDeviceStatus(This,szDeviceList,lSize,lMonitorCycle,lplData,lplReturnCode)	\
    (This)->lpVtbl -> EntryDeviceStatus(This,szDeviceList,lSize,lMonitorCycle,lplData,lplReturnCode)

#define IActQSS2_FreeDeviceStatus(This,lplReturnCode)	\
    (This)->lpVtbl -> FreeDeviceStatus(This,lplReturnCode)

#define IActQSS2_ReadDeviceBlock2(This,szDevice,lSize,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> ReadDeviceBlock2(This,szDevice,lSize,lpsData,lplReturnCode)

#define IActQSS2_WriteDeviceBlock2(This,szDevice,lSize,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> WriteDeviceBlock2(This,szDevice,lSize,lpsData,lplReturnCode)

#define IActQSS2_ReadDeviceRandom2(This,szDeviceList,lSize,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> ReadDeviceRandom2(This,szDeviceList,lSize,lpsData,lplReturnCode)

#define IActQSS2_WriteDeviceRandom2(This,szDeviceList,lSize,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> WriteDeviceRandom2(This,szDeviceList,lSize,lpsData,lplReturnCode)

#define IActQSS2_GetDevice2(This,szDevice,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> GetDevice2(This,szDevice,lpsData,lplReturnCode)

#define IActQSS2_SetDevice2(This,szDevice,sData,lplReturnCode)	\
    (This)->lpVtbl -> SetDevice2(This,szDevice,sData,lplReturnCode)

#define IActQSS2_get_ActNetworkNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActNetworkNumber(This,pVal)

#define IActQSS2_put_ActNetworkNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActNetworkNumber(This,newVal)

#define IActQSS2_get_ActStationNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActStationNumber(This,pVal)

#define IActQSS2_put_ActStationNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActStationNumber(This,newVal)

#define IActQSS2_get_ActUnitNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActUnitNumber(This,pVal)

#define IActQSS2_put_ActUnitNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActUnitNumber(This,newVal)

#define IActQSS2_get_ActIONumber(This,pVal)	\
    (This)->lpVtbl -> get_ActIONumber(This,pVal)

#define IActQSS2_put_ActIONumber(This,newVal)	\
    (This)->lpVtbl -> put_ActIONumber(This,newVal)

#define IActQSS2_get_ActCpuType(This,pVal)	\
    (This)->lpVtbl -> get_ActCpuType(This,pVal)

#define IActQSS2_put_ActCpuType(This,newVal)	\
    (This)->lpVtbl -> put_ActCpuType(This,newVal)

#define IActQSS2_get_ActDestinationIONumber(This,pVal)	\
    (This)->lpVtbl -> get_ActDestinationIONumber(This,pVal)

#define IActQSS2_put_ActDestinationIONumber(This,newVal)	\
    (This)->lpVtbl -> put_ActDestinationIONumber(This,newVal)

#define IActQSS2_get_ActMultiDropChannelNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActMultiDropChannelNumber(This,pVal)

#define IActQSS2_put_ActMultiDropChannelNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActMultiDropChannelNumber(This,newVal)

#define IActQSS2_get_ActThroughNetworkType(This,pVal)	\
    (This)->lpVtbl -> get_ActThroughNetworkType(This,pVal)

#define IActQSS2_put_ActThroughNetworkType(This,newVal)	\
    (This)->lpVtbl -> put_ActThroughNetworkType(This,newVal)

#define IActQSS2_get_ActIntelligentPreferenceBit(This,pVal)	\
    (This)->lpVtbl -> get_ActIntelligentPreferenceBit(This,pVal)

#define IActQSS2_put_ActIntelligentPreferenceBit(This,newVal)	\
    (This)->lpVtbl -> put_ActIntelligentPreferenceBit(This,newVal)

#define IActQSS2_get_ActDidPropertyBit(This,pVal)	\
    (This)->lpVtbl -> get_ActDidPropertyBit(This,pVal)

#define IActQSS2_put_ActDidPropertyBit(This,newVal)	\
    (This)->lpVtbl -> put_ActDidPropertyBit(This,newVal)

#define IActQSS2_get_ActDsidPropertyBit(This,pVal)	\
    (This)->lpVtbl -> get_ActDsidPropertyBit(This,pVal)

#define IActQSS2_put_ActDsidPropertyBit(This,newVal)	\
    (This)->lpVtbl -> put_ActDsidPropertyBit(This,newVal)


#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IActQSS2_INTERFACE_DEFINED__ */


#ifndef __IActQSS3_INTERFACE_DEFINED__
#define __IActQSS3_INTERFACE_DEFINED__

/* interface IActQSS3 */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IActQSS3;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("87166035-710B-11d5-9318-009099244EFD")
    IActQSS3 : public IActQSS2
    {
    public:
    };
    
#else 	/* C style interface */

    typedef struct IActQSS3Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IActQSS3 __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IActQSS3 __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IActQSS3 __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IActQSS3 __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IActQSS3 __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IActQSS3 __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IActQSS3 __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Open )( 
            IActQSS3 __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Close )( 
            IActQSS3 __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetDevice )( 
            IActQSS3 __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [out] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetDevice )( 
            IActQSS3 __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceBlock )( 
            IActQSS3 __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lSize,
            /* [size_is][out] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceBlock )( 
            IActQSS3 __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lSize,
            /* [size_is][in] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceRandom )( 
            IActQSS3 __RPC_FAR * This,
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG lSize,
            /* [size_is][out] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceRandom )( 
            IActQSS3 __RPC_FAR * This,
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG lSize,
            /* [size_is][in] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadBuffer )( 
            IActQSS3 __RPC_FAR * This,
            /* [in] */ LONG lStartIO,
            /* [in] */ LONG lAddress,
            /* [in] */ LONG lReadSize,
            /* [size_is][out] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteBuffer )( 
            IActQSS3 __RPC_FAR * This,
            /* [in] */ LONG lStartIO,
            /* [in] */ LONG lAddress,
            /* [in] */ LONG lWriteSize,
            /* [size_is][in] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetClockData )( 
            IActQSS3 __RPC_FAR * This,
            /* [out] */ SHORT __RPC_FAR *lpsYear,
            /* [out] */ SHORT __RPC_FAR *lpsMonth,
            /* [out] */ SHORT __RPC_FAR *lpsDay,
            /* [out] */ SHORT __RPC_FAR *lpsDayOfWeek,
            /* [out] */ SHORT __RPC_FAR *lpsHour,
            /* [out] */ SHORT __RPC_FAR *lpsMinute,
            /* [out] */ SHORT __RPC_FAR *lpsSecond,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetClockData )( 
            IActQSS3 __RPC_FAR * This,
            /* [in] */ SHORT sYear,
            /* [in] */ SHORT sMonth,
            /* [in] */ SHORT sDay,
            /* [in] */ SHORT sDayOfWeek,
            /* [in] */ SHORT sHour,
            /* [in] */ SHORT sMinute,
            /* [in] */ SHORT sSecond,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetCpuType )( 
            IActQSS3 __RPC_FAR * This,
            /* [string][out] */ BSTR __RPC_FAR *szCpuName,
            /* [out] */ LONG __RPC_FAR *lplCpuCode,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetCpuStatus )( 
            IActQSS3 __RPC_FAR * This,
            /* [in] */ LONG lOperation,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CheckDeviceString )( 
            IActQSS3 __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lCheckType,
            /* [in] */ LONG lSize,
            /* [out] */ LONG __RPC_FAR *lplDeviceType,
            /* [string][out] */ BSTR __RPC_FAR *lpszDeviceName,
            /* [out] */ LONG __RPC_FAR *lplDeviceNumber,
            /* [out] */ LONG __RPC_FAR *lplDeviceRadix,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *EntryDeviceStatus )( 
            IActQSS3 __RPC_FAR * This,
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG lSize,
            /* [in] */ LONG lMonitorCycle,
            /* [size_is][in] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *FreeDeviceStatus )( 
            IActQSS3 __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceBlock2 )( 
            IActQSS3 __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lSize,
            /* [size_is][out] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceBlock2 )( 
            IActQSS3 __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lSize,
            /* [size_is][in] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceRandom2 )( 
            IActQSS3 __RPC_FAR * This,
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG lSize,
            /* [size_is][out] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceRandom2 )( 
            IActQSS3 __RPC_FAR * This,
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG lSize,
            /* [size_is][in] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetDevice2 )( 
            IActQSS3 __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [out] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetDevice2 )( 
            IActQSS3 __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ SHORT sData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActNetworkNumber )( 
            IActQSS3 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActNetworkNumber )( 
            IActQSS3 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActStationNumber )( 
            IActQSS3 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActStationNumber )( 
            IActQSS3 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActUnitNumber )( 
            IActQSS3 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActUnitNumber )( 
            IActQSS3 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActIONumber )( 
            IActQSS3 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActIONumber )( 
            IActQSS3 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActCpuType )( 
            IActQSS3 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActCpuType )( 
            IActQSS3 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActDestinationIONumber )( 
            IActQSS3 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActDestinationIONumber )( 
            IActQSS3 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActMultiDropChannelNumber )( 
            IActQSS3 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActMultiDropChannelNumber )( 
            IActQSS3 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActThroughNetworkType )( 
            IActQSS3 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActThroughNetworkType )( 
            IActQSS3 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActIntelligentPreferenceBit )( 
            IActQSS3 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActIntelligentPreferenceBit )( 
            IActQSS3 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActDidPropertyBit )( 
            IActQSS3 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActDidPropertyBit )( 
            IActQSS3 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActDsidPropertyBit )( 
            IActQSS3 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActDsidPropertyBit )( 
            IActQSS3 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        END_INTERFACE
    } IActQSS3Vtbl;

    interface IActQSS3
    {
        CONST_VTBL struct IActQSS3Vtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IActQSS3_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IActQSS3_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IActQSS3_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IActQSS3_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IActQSS3_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IActQSS3_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IActQSS3_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IActQSS3_Open(This,lplReturnCode)	\
    (This)->lpVtbl -> Open(This,lplReturnCode)

#define IActQSS3_Close(This,lplReturnCode)	\
    (This)->lpVtbl -> Close(This,lplReturnCode)

#define IActQSS3_GetDevice(This,szDevice,lplData,lplReturnCode)	\
    (This)->lpVtbl -> GetDevice(This,szDevice,lplData,lplReturnCode)

#define IActQSS3_SetDevice(This,szDevice,lData,lplReturnCode)	\
    (This)->lpVtbl -> SetDevice(This,szDevice,lData,lplReturnCode)

#define IActQSS3_ReadDeviceBlock(This,szDevice,lSize,lplData,lplReturnCode)	\
    (This)->lpVtbl -> ReadDeviceBlock(This,szDevice,lSize,lplData,lplReturnCode)

#define IActQSS3_WriteDeviceBlock(This,szDevice,lSize,lplData,lplReturnCode)	\
    (This)->lpVtbl -> WriteDeviceBlock(This,szDevice,lSize,lplData,lplReturnCode)

#define IActQSS3_ReadDeviceRandom(This,szDeviceList,lSize,lplData,lplReturnCode)	\
    (This)->lpVtbl -> ReadDeviceRandom(This,szDeviceList,lSize,lplData,lplReturnCode)

#define IActQSS3_WriteDeviceRandom(This,szDeviceList,lSize,lplData,lplReturnCode)	\
    (This)->lpVtbl -> WriteDeviceRandom(This,szDeviceList,lSize,lplData,lplReturnCode)

#define IActQSS3_ReadBuffer(This,lStartIO,lAddress,lReadSize,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> ReadBuffer(This,lStartIO,lAddress,lReadSize,lpsData,lplReturnCode)

#define IActQSS3_WriteBuffer(This,lStartIO,lAddress,lWriteSize,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> WriteBuffer(This,lStartIO,lAddress,lWriteSize,lpsData,lplReturnCode)

#define IActQSS3_GetClockData(This,lpsYear,lpsMonth,lpsDay,lpsDayOfWeek,lpsHour,lpsMinute,lpsSecond,lplReturnCode)	\
    (This)->lpVtbl -> GetClockData(This,lpsYear,lpsMonth,lpsDay,lpsDayOfWeek,lpsHour,lpsMinute,lpsSecond,lplReturnCode)

#define IActQSS3_SetClockData(This,sYear,sMonth,sDay,sDayOfWeek,sHour,sMinute,sSecond,lplReturnCode)	\
    (This)->lpVtbl -> SetClockData(This,sYear,sMonth,sDay,sDayOfWeek,sHour,sMinute,sSecond,lplReturnCode)

#define IActQSS3_GetCpuType(This,szCpuName,lplCpuCode,lplReturnCode)	\
    (This)->lpVtbl -> GetCpuType(This,szCpuName,lplCpuCode,lplReturnCode)

#define IActQSS3_SetCpuStatus(This,lOperation,lplReturnCode)	\
    (This)->lpVtbl -> SetCpuStatus(This,lOperation,lplReturnCode)

#define IActQSS3_CheckDeviceString(This,szDevice,lCheckType,lSize,lplDeviceType,lpszDeviceName,lplDeviceNumber,lplDeviceRadix,lplReturnCode)	\
    (This)->lpVtbl -> CheckDeviceString(This,szDevice,lCheckType,lSize,lplDeviceType,lpszDeviceName,lplDeviceNumber,lplDeviceRadix,lplReturnCode)

#define IActQSS3_EntryDeviceStatus(This,szDeviceList,lSize,lMonitorCycle,lplData,lplReturnCode)	\
    (This)->lpVtbl -> EntryDeviceStatus(This,szDeviceList,lSize,lMonitorCycle,lplData,lplReturnCode)

#define IActQSS3_FreeDeviceStatus(This,lplReturnCode)	\
    (This)->lpVtbl -> FreeDeviceStatus(This,lplReturnCode)

#define IActQSS3_ReadDeviceBlock2(This,szDevice,lSize,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> ReadDeviceBlock2(This,szDevice,lSize,lpsData,lplReturnCode)

#define IActQSS3_WriteDeviceBlock2(This,szDevice,lSize,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> WriteDeviceBlock2(This,szDevice,lSize,lpsData,lplReturnCode)

#define IActQSS3_ReadDeviceRandom2(This,szDeviceList,lSize,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> ReadDeviceRandom2(This,szDeviceList,lSize,lpsData,lplReturnCode)

#define IActQSS3_WriteDeviceRandom2(This,szDeviceList,lSize,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> WriteDeviceRandom2(This,szDeviceList,lSize,lpsData,lplReturnCode)

#define IActQSS3_GetDevice2(This,szDevice,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> GetDevice2(This,szDevice,lpsData,lplReturnCode)

#define IActQSS3_SetDevice2(This,szDevice,sData,lplReturnCode)	\
    (This)->lpVtbl -> SetDevice2(This,szDevice,sData,lplReturnCode)

#define IActQSS3_get_ActNetworkNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActNetworkNumber(This,pVal)

#define IActQSS3_put_ActNetworkNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActNetworkNumber(This,newVal)

#define IActQSS3_get_ActStationNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActStationNumber(This,pVal)

#define IActQSS3_put_ActStationNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActStationNumber(This,newVal)

#define IActQSS3_get_ActUnitNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActUnitNumber(This,pVal)

#define IActQSS3_put_ActUnitNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActUnitNumber(This,newVal)

#define IActQSS3_get_ActIONumber(This,pVal)	\
    (This)->lpVtbl -> get_ActIONumber(This,pVal)

#define IActQSS3_put_ActIONumber(This,newVal)	\
    (This)->lpVtbl -> put_ActIONumber(This,newVal)

#define IActQSS3_get_ActCpuType(This,pVal)	\
    (This)->lpVtbl -> get_ActCpuType(This,pVal)

#define IActQSS3_put_ActCpuType(This,newVal)	\
    (This)->lpVtbl -> put_ActCpuType(This,newVal)

#define IActQSS3_get_ActDestinationIONumber(This,pVal)	\
    (This)->lpVtbl -> get_ActDestinationIONumber(This,pVal)

#define IActQSS3_put_ActDestinationIONumber(This,newVal)	\
    (This)->lpVtbl -> put_ActDestinationIONumber(This,newVal)

#define IActQSS3_get_ActMultiDropChannelNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActMultiDropChannelNumber(This,pVal)

#define IActQSS3_put_ActMultiDropChannelNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActMultiDropChannelNumber(This,newVal)

#define IActQSS3_get_ActThroughNetworkType(This,pVal)	\
    (This)->lpVtbl -> get_ActThroughNetworkType(This,pVal)

#define IActQSS3_put_ActThroughNetworkType(This,newVal)	\
    (This)->lpVtbl -> put_ActThroughNetworkType(This,newVal)

#define IActQSS3_get_ActIntelligentPreferenceBit(This,pVal)	\
    (This)->lpVtbl -> get_ActIntelligentPreferenceBit(This,pVal)

#define IActQSS3_put_ActIntelligentPreferenceBit(This,newVal)	\
    (This)->lpVtbl -> put_ActIntelligentPreferenceBit(This,newVal)

#define IActQSS3_get_ActDidPropertyBit(This,pVal)	\
    (This)->lpVtbl -> get_ActDidPropertyBit(This,pVal)

#define IActQSS3_put_ActDidPropertyBit(This,newVal)	\
    (This)->lpVtbl -> put_ActDidPropertyBit(This,newVal)

#define IActQSS3_get_ActDsidPropertyBit(This,pVal)	\
    (This)->lpVtbl -> get_ActDsidPropertyBit(This,pVal)

#define IActQSS3_put_ActDsidPropertyBit(This,newVal)	\
    (This)->lpVtbl -> put_ActDsidPropertyBit(This,newVal)



#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IActQSS3_INTERFACE_DEFINED__ */


#ifndef __IActMLQSS_INTERFACE_DEFINED__
#define __IActMLQSS_INTERFACE_DEFINED__

/* interface IActMLQSS */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IActMLQSS;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("A6BE4A94-70EC-11D5-9318-009099244EFD")
    IActMLQSS : public IDispatch
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
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetCpuType( 
            /* [out] */ VARIANT __RPC_FAR *lpvarCpuName,
            /* [out] */ VARIANT __RPC_FAR *lpvarCpuType,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetCpuStatus( 
            /* [in] */ VARIANT varOperation,
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

    typedef struct IActMLQSSVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IActMLQSS __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IActMLQSS __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IActMLQSS __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IActMLQSS __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IActMLQSS __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IActMLQSS __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IActMLQSS __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Open )( 
            IActMLQSS __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Close )( 
            IActMLQSS __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetDevice )( 
            IActMLQSS __RPC_FAR * This,
            /* [in] */ VARIANT varDevice,
            /* [out] */ VARIANT __RPC_FAR *lpvarData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetDevice )( 
            IActMLQSS __RPC_FAR * This,
            /* [in] */ VARIANT varDevice,
            /* [in] */ VARIANT varData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceBlock )( 
            IActMLQSS __RPC_FAR * This,
            /* [in] */ VARIANT varDevice,
            /* [in] */ VARIANT varSize,
            /* [out] */ VARIANT __RPC_FAR *lpvarData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceBlock )( 
            IActMLQSS __RPC_FAR * This,
            /* [in] */ VARIANT varDevice,
            /* [in] */ VARIANT varSize,
            /* [in] */ VARIANT varData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceRandom )( 
            IActMLQSS __RPC_FAR * This,
            /* [in] */ VARIANT varDeviceList,
            /* [in] */ VARIANT varSize,
            /* [out] */ VARIANT __RPC_FAR *lpvarData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceRandom )( 
            IActMLQSS __RPC_FAR * This,
            /* [in] */ VARIANT varDeviceList,
            /* [in] */ VARIANT varSize,
            /* [in] */ VARIANT varData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadBuffer )( 
            IActMLQSS __RPC_FAR * This,
            /* [in] */ VARIANT varStartIO,
            /* [in] */ VARIANT varAddress,
            /* [in] */ VARIANT varReadSize,
            /* [out] */ VARIANT __RPC_FAR *lpvarData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteBuffer )( 
            IActMLQSS __RPC_FAR * This,
            /* [in] */ VARIANT varStartIO,
            /* [in] */ VARIANT varAddress,
            /* [in] */ VARIANT varWriteSize,
            /* [in] */ VARIANT varData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetClockData )( 
            IActMLQSS __RPC_FAR * This,
            /* [out] */ VARIANT __RPC_FAR *lpvarYear,
            /* [out] */ VARIANT __RPC_FAR *lpvarMonth,
            /* [out] */ VARIANT __RPC_FAR *lpvarDay,
            /* [out] */ VARIANT __RPC_FAR *lpvarDayOfWeek,
            /* [out] */ VARIANT __RPC_FAR *lpvarHour,
            /* [out] */ VARIANT __RPC_FAR *lpvarMinute,
            /* [out] */ VARIANT __RPC_FAR *lpvarSecond,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetClockData )( 
            IActMLQSS __RPC_FAR * This,
            /* [in] */ VARIANT varYear,
            /* [in] */ VARIANT varMonth,
            /* [in] */ VARIANT varDay,
            /* [in] */ VARIANT varDayOfWeek,
            /* [in] */ VARIANT varHour,
            /* [in] */ VARIANT varMinute,
            /* [in] */ VARIANT varSecond,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetCpuType )( 
            IActMLQSS __RPC_FAR * This,
            /* [out] */ VARIANT __RPC_FAR *lpvarCpuName,
            /* [out] */ VARIANT __RPC_FAR *lpvarCpuType,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetCpuStatus )( 
            IActMLQSS __RPC_FAR * This,
            /* [in] */ VARIANT varOperation,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *EntryDeviceStatus )( 
            IActMLQSS __RPC_FAR * This,
            /* [in] */ VARIANT varDeviceList,
            /* [in] */ VARIANT varSize,
            /* [in] */ VARIANT varMonitorCycle,
            /* [in] */ VARIANT varData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *FreeDeviceStatus )( 
            IActMLQSS __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceBlock2 )( 
            IActMLQSS __RPC_FAR * This,
            /* [in] */ VARIANT varDevice,
            /* [in] */ VARIANT varSize,
            /* [out] */ VARIANT __RPC_FAR *lpvarData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceBlock2 )( 
            IActMLQSS __RPC_FAR * This,
            /* [in] */ VARIANT varDevice,
            /* [in] */ VARIANT varSize,
            /* [in] */ VARIANT varData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceRandom2 )( 
            IActMLQSS __RPC_FAR * This,
            /* [in] */ VARIANT varDeviceList,
            /* [in] */ VARIANT varSize,
            /* [out] */ VARIANT __RPC_FAR *lpvarData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceRandom2 )( 
            IActMLQSS __RPC_FAR * This,
            /* [in] */ VARIANT varDeviceList,
            /* [in] */ VARIANT varSize,
            /* [in] */ VARIANT varData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetDevice2 )( 
            IActMLQSS __RPC_FAR * This,
            /* [in] */ VARIANT varDevice,
            /* [out] */ VARIANT __RPC_FAR *lpvarData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetDevice2 )( 
            IActMLQSS __RPC_FAR * This,
            /* [in] */ VARIANT varDevice,
            /* [in] */ VARIANT varData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActNetworkNumber )( 
            IActMLQSS __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActNetworkNumber )( 
            IActMLQSS __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActStationNumber )( 
            IActMLQSS __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActStationNumber )( 
            IActMLQSS __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActUnitNumber )( 
            IActMLQSS __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActUnitNumber )( 
            IActMLQSS __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActIONumber )( 
            IActMLQSS __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActIONumber )( 
            IActMLQSS __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActCpuType )( 
            IActMLQSS __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActCpuType )( 
            IActMLQSS __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActDestinationIONumber )( 
            IActMLQSS __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActDestinationIONumber )( 
            IActMLQSS __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActMultiDropChannelNumber )( 
            IActMLQSS __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActMultiDropChannelNumber )( 
            IActMLQSS __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActThroughNetworkType )( 
            IActMLQSS __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActThroughNetworkType )( 
            IActMLQSS __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActIntelligentPreferenceBit )( 
            IActMLQSS __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActIntelligentPreferenceBit )( 
            IActMLQSS __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActDidPropertyBit )( 
            IActMLQSS __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActDidPropertyBit )( 
            IActMLQSS __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActDsidPropertyBit )( 
            IActMLQSS __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActDsidPropertyBit )( 
            IActMLQSS __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        END_INTERFACE
    } IActMLQSSVtbl;

    interface IActMLQSS
    {
        CONST_VTBL struct IActMLQSSVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IActMLQSS_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IActMLQSS_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IActMLQSS_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IActMLQSS_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IActMLQSS_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IActMLQSS_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IActMLQSS_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IActMLQSS_Open(This,lpvarReturnCode)	\
    (This)->lpVtbl -> Open(This,lpvarReturnCode)

#define IActMLQSS_Close(This,lpvarReturnCode)	\
    (This)->lpVtbl -> Close(This,lpvarReturnCode)

#define IActMLQSS_GetDevice(This,varDevice,lpvarData,lpvarReturnCode)	\
    (This)->lpVtbl -> GetDevice(This,varDevice,lpvarData,lpvarReturnCode)

#define IActMLQSS_SetDevice(This,varDevice,varData,lpvarReturnCode)	\
    (This)->lpVtbl -> SetDevice(This,varDevice,varData,lpvarReturnCode)

#define IActMLQSS_ReadDeviceBlock(This,varDevice,varSize,lpvarData,lpvarReturnCode)	\
    (This)->lpVtbl -> ReadDeviceBlock(This,varDevice,varSize,lpvarData,lpvarReturnCode)

#define IActMLQSS_WriteDeviceBlock(This,varDevice,varSize,varData,lpvarReturnCode)	\
    (This)->lpVtbl -> WriteDeviceBlock(This,varDevice,varSize,varData,lpvarReturnCode)

#define IActMLQSS_ReadDeviceRandom(This,varDeviceList,varSize,lpvarData,lpvarReturnCode)	\
    (This)->lpVtbl -> ReadDeviceRandom(This,varDeviceList,varSize,lpvarData,lpvarReturnCode)

#define IActMLQSS_WriteDeviceRandom(This,varDeviceList,varSize,varData,lpvarReturnCode)	\
    (This)->lpVtbl -> WriteDeviceRandom(This,varDeviceList,varSize,varData,lpvarReturnCode)

#define IActMLQSS_ReadBuffer(This,varStartIO,varAddress,varReadSize,lpvarData,lpvarReturnCode)	\
    (This)->lpVtbl -> ReadBuffer(This,varStartIO,varAddress,varReadSize,lpvarData,lpvarReturnCode)

#define IActMLQSS_WriteBuffer(This,varStartIO,varAddress,varWriteSize,varData,lpvarReturnCode)	\
    (This)->lpVtbl -> WriteBuffer(This,varStartIO,varAddress,varWriteSize,varData,lpvarReturnCode)

#define IActMLQSS_GetClockData(This,lpvarYear,lpvarMonth,lpvarDay,lpvarDayOfWeek,lpvarHour,lpvarMinute,lpvarSecond,lpvarReturnCode)	\
    (This)->lpVtbl -> GetClockData(This,lpvarYear,lpvarMonth,lpvarDay,lpvarDayOfWeek,lpvarHour,lpvarMinute,lpvarSecond,lpvarReturnCode)

#define IActMLQSS_SetClockData(This,varYear,varMonth,varDay,varDayOfWeek,varHour,varMinute,varSecond,lpvarReturnCode)	\
    (This)->lpVtbl -> SetClockData(This,varYear,varMonth,varDay,varDayOfWeek,varHour,varMinute,varSecond,lpvarReturnCode)

#define IActMLQSS_GetCpuType(This,lpvarCpuName,lpvarCpuType,lpvarReturnCode)	\
    (This)->lpVtbl -> GetCpuType(This,lpvarCpuName,lpvarCpuType,lpvarReturnCode)

#define IActMLQSS_SetCpuStatus(This,varOperation,lpvarReturnCode)	\
    (This)->lpVtbl -> SetCpuStatus(This,varOperation,lpvarReturnCode)

#define IActMLQSS_EntryDeviceStatus(This,varDeviceList,varSize,varMonitorCycle,varData,lpvarReturnCode)	\
    (This)->lpVtbl -> EntryDeviceStatus(This,varDeviceList,varSize,varMonitorCycle,varData,lpvarReturnCode)

#define IActMLQSS_FreeDeviceStatus(This,lpvarReturnCode)	\
    (This)->lpVtbl -> FreeDeviceStatus(This,lpvarReturnCode)

#define IActMLQSS_ReadDeviceBlock2(This,varDevice,varSize,lpvarData,lpvarReturnCode)	\
    (This)->lpVtbl -> ReadDeviceBlock2(This,varDevice,varSize,lpvarData,lpvarReturnCode)

#define IActMLQSS_WriteDeviceBlock2(This,varDevice,varSize,varData,lpvarReturnCode)	\
    (This)->lpVtbl -> WriteDeviceBlock2(This,varDevice,varSize,varData,lpvarReturnCode)

#define IActMLQSS_ReadDeviceRandom2(This,varDeviceList,varSize,lpvarData,lpvarReturnCode)	\
    (This)->lpVtbl -> ReadDeviceRandom2(This,varDeviceList,varSize,lpvarData,lpvarReturnCode)

#define IActMLQSS_WriteDeviceRandom2(This,varDeviceList,varSize,varData,lpvarReturnCode)	\
    (This)->lpVtbl -> WriteDeviceRandom2(This,varDeviceList,varSize,varData,lpvarReturnCode)

#define IActMLQSS_GetDevice2(This,varDevice,lpvarData,lpvarReturnCode)	\
    (This)->lpVtbl -> GetDevice2(This,varDevice,lpvarData,lpvarReturnCode)

#define IActMLQSS_SetDevice2(This,varDevice,varData,lpvarReturnCode)	\
    (This)->lpVtbl -> SetDevice2(This,varDevice,varData,lpvarReturnCode)

#define IActMLQSS_get_ActNetworkNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActNetworkNumber(This,pVal)

#define IActMLQSS_put_ActNetworkNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActNetworkNumber(This,newVal)

#define IActMLQSS_get_ActStationNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActStationNumber(This,pVal)

#define IActMLQSS_put_ActStationNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActStationNumber(This,newVal)

#define IActMLQSS_get_ActUnitNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActUnitNumber(This,pVal)

#define IActMLQSS_put_ActUnitNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActUnitNumber(This,newVal)

#define IActMLQSS_get_ActIONumber(This,pVal)	\
    (This)->lpVtbl -> get_ActIONumber(This,pVal)

#define IActMLQSS_put_ActIONumber(This,newVal)	\
    (This)->lpVtbl -> put_ActIONumber(This,newVal)

#define IActMLQSS_get_ActCpuType(This,pVal)	\
    (This)->lpVtbl -> get_ActCpuType(This,pVal)

#define IActMLQSS_put_ActCpuType(This,newVal)	\
    (This)->lpVtbl -> put_ActCpuType(This,newVal)

#define IActMLQSS_get_ActDestinationIONumber(This,pVal)	\
    (This)->lpVtbl -> get_ActDestinationIONumber(This,pVal)

#define IActMLQSS_put_ActDestinationIONumber(This,newVal)	\
    (This)->lpVtbl -> put_ActDestinationIONumber(This,newVal)

#define IActMLQSS_get_ActMultiDropChannelNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActMultiDropChannelNumber(This,pVal)

#define IActMLQSS_put_ActMultiDropChannelNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActMultiDropChannelNumber(This,newVal)

#define IActMLQSS_get_ActThroughNetworkType(This,pVal)	\
    (This)->lpVtbl -> get_ActThroughNetworkType(This,pVal)

#define IActMLQSS_put_ActThroughNetworkType(This,newVal)	\
    (This)->lpVtbl -> put_ActThroughNetworkType(This,newVal)

#define IActMLQSS_get_ActIntelligentPreferenceBit(This,pVal)	\
    (This)->lpVtbl -> get_ActIntelligentPreferenceBit(This,pVal)

#define IActMLQSS_put_ActIntelligentPreferenceBit(This,newVal)	\
    (This)->lpVtbl -> put_ActIntelligentPreferenceBit(This,newVal)

#define IActMLQSS_get_ActDidPropertyBit(This,pVal)	\
    (This)->lpVtbl -> get_ActDidPropertyBit(This,pVal)

#define IActMLQSS_put_ActDidPropertyBit(This,newVal)	\
    (This)->lpVtbl -> put_ActDidPropertyBit(This,newVal)

#define IActMLQSS_get_ActDsidPropertyBit(This,pVal)	\
    (This)->lpVtbl -> get_ActDsidPropertyBit(This,pVal)

#define IActMLQSS_put_ActDsidPropertyBit(This,newVal)	\
    (This)->lpVtbl -> put_ActDsidPropertyBit(This,newVal)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActMLQSS_Open_Proxy( 
    IActMLQSS __RPC_FAR * This,
    /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);


void __RPC_STUB IActMLQSS_Open_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActMLQSS_Close_Proxy( 
    IActMLQSS __RPC_FAR * This,
    /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);


void __RPC_STUB IActMLQSS_Close_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActMLQSS_GetDevice_Proxy( 
    IActMLQSS __RPC_FAR * This,
    /* [in] */ VARIANT varDevice,
    /* [out] */ VARIANT __RPC_FAR *lpvarData,
    /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);


void __RPC_STUB IActMLQSS_GetDevice_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActMLQSS_SetDevice_Proxy( 
    IActMLQSS __RPC_FAR * This,
    /* [in] */ VARIANT varDevice,
    /* [in] */ VARIANT varData,
    /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);


void __RPC_STUB IActMLQSS_SetDevice_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActMLQSS_ReadDeviceBlock_Proxy( 
    IActMLQSS __RPC_FAR * This,
    /* [in] */ VARIANT varDevice,
    /* [in] */ VARIANT varSize,
    /* [out] */ VARIANT __RPC_FAR *lpvarData,
    /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);


void __RPC_STUB IActMLQSS_ReadDeviceBlock_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActMLQSS_WriteDeviceBlock_Proxy( 
    IActMLQSS __RPC_FAR * This,
    /* [in] */ VARIANT varDevice,
    /* [in] */ VARIANT varSize,
    /* [in] */ VARIANT varData,
    /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);


void __RPC_STUB IActMLQSS_WriteDeviceBlock_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActMLQSS_ReadDeviceRandom_Proxy( 
    IActMLQSS __RPC_FAR * This,
    /* [in] */ VARIANT varDeviceList,
    /* [in] */ VARIANT varSize,
    /* [out] */ VARIANT __RPC_FAR *lpvarData,
    /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);


void __RPC_STUB IActMLQSS_ReadDeviceRandom_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActMLQSS_WriteDeviceRandom_Proxy( 
    IActMLQSS __RPC_FAR * This,
    /* [in] */ VARIANT varDeviceList,
    /* [in] */ VARIANT varSize,
    /* [in] */ VARIANT varData,
    /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);


void __RPC_STUB IActMLQSS_WriteDeviceRandom_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActMLQSS_ReadBuffer_Proxy( 
    IActMLQSS __RPC_FAR * This,
    /* [in] */ VARIANT varStartIO,
    /* [in] */ VARIANT varAddress,
    /* [in] */ VARIANT varReadSize,
    /* [out] */ VARIANT __RPC_FAR *lpvarData,
    /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);


void __RPC_STUB IActMLQSS_ReadBuffer_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActMLQSS_WriteBuffer_Proxy( 
    IActMLQSS __RPC_FAR * This,
    /* [in] */ VARIANT varStartIO,
    /* [in] */ VARIANT varAddress,
    /* [in] */ VARIANT varWriteSize,
    /* [in] */ VARIANT varData,
    /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);


void __RPC_STUB IActMLQSS_WriteBuffer_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActMLQSS_GetClockData_Proxy( 
    IActMLQSS __RPC_FAR * This,
    /* [out] */ VARIANT __RPC_FAR *lpvarYear,
    /* [out] */ VARIANT __RPC_FAR *lpvarMonth,
    /* [out] */ VARIANT __RPC_FAR *lpvarDay,
    /* [out] */ VARIANT __RPC_FAR *lpvarDayOfWeek,
    /* [out] */ VARIANT __RPC_FAR *lpvarHour,
    /* [out] */ VARIANT __RPC_FAR *lpvarMinute,
    /* [out] */ VARIANT __RPC_FAR *lpvarSecond,
    /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);


void __RPC_STUB IActMLQSS_GetClockData_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActMLQSS_SetClockData_Proxy( 
    IActMLQSS __RPC_FAR * This,
    /* [in] */ VARIANT varYear,
    /* [in] */ VARIANT varMonth,
    /* [in] */ VARIANT varDay,
    /* [in] */ VARIANT varDayOfWeek,
    /* [in] */ VARIANT varHour,
    /* [in] */ VARIANT varMinute,
    /* [in] */ VARIANT varSecond,
    /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);


void __RPC_STUB IActMLQSS_SetClockData_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActMLQSS_GetCpuType_Proxy( 
    IActMLQSS __RPC_FAR * This,
    /* [out] */ VARIANT __RPC_FAR *lpvarCpuName,
    /* [out] */ VARIANT __RPC_FAR *lpvarCpuType,
    /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);


void __RPC_STUB IActMLQSS_GetCpuType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActMLQSS_SetCpuStatus_Proxy( 
    IActMLQSS __RPC_FAR * This,
    /* [in] */ VARIANT varOperation,
    /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);


void __RPC_STUB IActMLQSS_SetCpuStatus_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActMLQSS_EntryDeviceStatus_Proxy( 
    IActMLQSS __RPC_FAR * This,
    /* [in] */ VARIANT varDeviceList,
    /* [in] */ VARIANT varSize,
    /* [in] */ VARIANT varMonitorCycle,
    /* [in] */ VARIANT varData,
    /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);


void __RPC_STUB IActMLQSS_EntryDeviceStatus_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActMLQSS_FreeDeviceStatus_Proxy( 
    IActMLQSS __RPC_FAR * This,
    /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);


void __RPC_STUB IActMLQSS_FreeDeviceStatus_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActMLQSS_ReadDeviceBlock2_Proxy( 
    IActMLQSS __RPC_FAR * This,
    /* [in] */ VARIANT varDevice,
    /* [in] */ VARIANT varSize,
    /* [out] */ VARIANT __RPC_FAR *lpvarData,
    /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);


void __RPC_STUB IActMLQSS_ReadDeviceBlock2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActMLQSS_WriteDeviceBlock2_Proxy( 
    IActMLQSS __RPC_FAR * This,
    /* [in] */ VARIANT varDevice,
    /* [in] */ VARIANT varSize,
    /* [in] */ VARIANT varData,
    /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);


void __RPC_STUB IActMLQSS_WriteDeviceBlock2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActMLQSS_ReadDeviceRandom2_Proxy( 
    IActMLQSS __RPC_FAR * This,
    /* [in] */ VARIANT varDeviceList,
    /* [in] */ VARIANT varSize,
    /* [out] */ VARIANT __RPC_FAR *lpvarData,
    /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);


void __RPC_STUB IActMLQSS_ReadDeviceRandom2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActMLQSS_WriteDeviceRandom2_Proxy( 
    IActMLQSS __RPC_FAR * This,
    /* [in] */ VARIANT varDeviceList,
    /* [in] */ VARIANT varSize,
    /* [in] */ VARIANT varData,
    /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);


void __RPC_STUB IActMLQSS_WriteDeviceRandom2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActMLQSS_GetDevice2_Proxy( 
    IActMLQSS __RPC_FAR * This,
    /* [in] */ VARIANT varDevice,
    /* [out] */ VARIANT __RPC_FAR *lpvarData,
    /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);


void __RPC_STUB IActMLQSS_GetDevice2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActMLQSS_SetDevice2_Proxy( 
    IActMLQSS __RPC_FAR * This,
    /* [in] */ VARIANT varDevice,
    /* [in] */ VARIANT varData,
    /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);


void __RPC_STUB IActMLQSS_SetDevice2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActMLQSS_get_ActNetworkNumber_Proxy( 
    IActMLQSS __RPC_FAR * This,
    /* [retval][out] */ VARIANT __RPC_FAR *pVal);


void __RPC_STUB IActMLQSS_get_ActNetworkNumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActMLQSS_put_ActNetworkNumber_Proxy( 
    IActMLQSS __RPC_FAR * This,
    /* [in] */ VARIANT newVal);


void __RPC_STUB IActMLQSS_put_ActNetworkNumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActMLQSS_get_ActStationNumber_Proxy( 
    IActMLQSS __RPC_FAR * This,
    /* [retval][out] */ VARIANT __RPC_FAR *pVal);


void __RPC_STUB IActMLQSS_get_ActStationNumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActMLQSS_put_ActStationNumber_Proxy( 
    IActMLQSS __RPC_FAR * This,
    /* [in] */ VARIANT newVal);


void __RPC_STUB IActMLQSS_put_ActStationNumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActMLQSS_get_ActUnitNumber_Proxy( 
    IActMLQSS __RPC_FAR * This,
    /* [retval][out] */ VARIANT __RPC_FAR *pVal);


void __RPC_STUB IActMLQSS_get_ActUnitNumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActMLQSS_put_ActUnitNumber_Proxy( 
    IActMLQSS __RPC_FAR * This,
    /* [in] */ VARIANT newVal);


void __RPC_STUB IActMLQSS_put_ActUnitNumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActMLQSS_get_ActIONumber_Proxy( 
    IActMLQSS __RPC_FAR * This,
    /* [retval][out] */ VARIANT __RPC_FAR *pVal);


void __RPC_STUB IActMLQSS_get_ActIONumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActMLQSS_put_ActIONumber_Proxy( 
    IActMLQSS __RPC_FAR * This,
    /* [in] */ VARIANT newVal);


void __RPC_STUB IActMLQSS_put_ActIONumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActMLQSS_get_ActCpuType_Proxy( 
    IActMLQSS __RPC_FAR * This,
    /* [retval][out] */ VARIANT __RPC_FAR *pVal);


void __RPC_STUB IActMLQSS_get_ActCpuType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActMLQSS_put_ActCpuType_Proxy( 
    IActMLQSS __RPC_FAR * This,
    /* [in] */ VARIANT newVal);


void __RPC_STUB IActMLQSS_put_ActCpuType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActMLQSS_get_ActDestinationIONumber_Proxy( 
    IActMLQSS __RPC_FAR * This,
    /* [retval][out] */ VARIANT __RPC_FAR *pVal);


void __RPC_STUB IActMLQSS_get_ActDestinationIONumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActMLQSS_put_ActDestinationIONumber_Proxy( 
    IActMLQSS __RPC_FAR * This,
    /* [in] */ VARIANT newVal);


void __RPC_STUB IActMLQSS_put_ActDestinationIONumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActMLQSS_get_ActMultiDropChannelNumber_Proxy( 
    IActMLQSS __RPC_FAR * This,
    /* [retval][out] */ VARIANT __RPC_FAR *pVal);


void __RPC_STUB IActMLQSS_get_ActMultiDropChannelNumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActMLQSS_put_ActMultiDropChannelNumber_Proxy( 
    IActMLQSS __RPC_FAR * This,
    /* [in] */ VARIANT newVal);


void __RPC_STUB IActMLQSS_put_ActMultiDropChannelNumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActMLQSS_get_ActThroughNetworkType_Proxy( 
    IActMLQSS __RPC_FAR * This,
    /* [retval][out] */ VARIANT __RPC_FAR *pVal);


void __RPC_STUB IActMLQSS_get_ActThroughNetworkType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActMLQSS_put_ActThroughNetworkType_Proxy( 
    IActMLQSS __RPC_FAR * This,
    /* [in] */ VARIANT newVal);


void __RPC_STUB IActMLQSS_put_ActThroughNetworkType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActMLQSS_get_ActIntelligentPreferenceBit_Proxy( 
    IActMLQSS __RPC_FAR * This,
    /* [retval][out] */ VARIANT __RPC_FAR *pVal);


void __RPC_STUB IActMLQSS_get_ActIntelligentPreferenceBit_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActMLQSS_put_ActIntelligentPreferenceBit_Proxy( 
    IActMLQSS __RPC_FAR * This,
    /* [in] */ VARIANT newVal);


void __RPC_STUB IActMLQSS_put_ActIntelligentPreferenceBit_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActMLQSS_get_ActDidPropertyBit_Proxy( 
    IActMLQSS __RPC_FAR * This,
    /* [retval][out] */ VARIANT __RPC_FAR *pVal);


void __RPC_STUB IActMLQSS_get_ActDidPropertyBit_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActMLQSS_put_ActDidPropertyBit_Proxy( 
    IActMLQSS __RPC_FAR * This,
    /* [in] */ VARIANT newVal);


void __RPC_STUB IActMLQSS_put_ActDidPropertyBit_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActMLQSS_get_ActDsidPropertyBit_Proxy( 
    IActMLQSS __RPC_FAR * This,
    /* [retval][out] */ VARIANT __RPC_FAR *pVal);


void __RPC_STUB IActMLQSS_get_ActDsidPropertyBit_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActMLQSS_put_ActDsidPropertyBit_Proxy( 
    IActMLQSS __RPC_FAR * This,
    /* [in] */ VARIANT newVal);


void __RPC_STUB IActMLQSS_put_ActDsidPropertyBit_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IActMLQSS_INTERFACE_DEFINED__ */


#ifndef __IActMLQSS2_INTERFACE_DEFINED__
#define __IActMLQSS2_INTERFACE_DEFINED__

/* interface IActMLQSS2 */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IActMLQSS2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("87166032-710B-11d5-9318-009099244EFD")
    IActMLQSS2 : public IActMLQSS
    {
    public:
    };
    
#else 	/* C style interface */

    typedef struct IActMLQSS2Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IActMLQSS2 __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IActMLQSS2 __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IActMLQSS2 __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IActMLQSS2 __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IActMLQSS2 __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IActMLQSS2 __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IActMLQSS2 __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Open )( 
            IActMLQSS2 __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Close )( 
            IActMLQSS2 __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetDevice )( 
            IActMLQSS2 __RPC_FAR * This,
            /* [in] */ VARIANT varDevice,
            /* [out] */ VARIANT __RPC_FAR *lpvarData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetDevice )( 
            IActMLQSS2 __RPC_FAR * This,
            /* [in] */ VARIANT varDevice,
            /* [in] */ VARIANT varData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceBlock )( 
            IActMLQSS2 __RPC_FAR * This,
            /* [in] */ VARIANT varDevice,
            /* [in] */ VARIANT varSize,
            /* [out] */ VARIANT __RPC_FAR *lpvarData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceBlock )( 
            IActMLQSS2 __RPC_FAR * This,
            /* [in] */ VARIANT varDevice,
            /* [in] */ VARIANT varSize,
            /* [in] */ VARIANT varData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceRandom )( 
            IActMLQSS2 __RPC_FAR * This,
            /* [in] */ VARIANT varDeviceList,
            /* [in] */ VARIANT varSize,
            /* [out] */ VARIANT __RPC_FAR *lpvarData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceRandom )( 
            IActMLQSS2 __RPC_FAR * This,
            /* [in] */ VARIANT varDeviceList,
            /* [in] */ VARIANT varSize,
            /* [in] */ VARIANT varData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadBuffer )( 
            IActMLQSS2 __RPC_FAR * This,
            /* [in] */ VARIANT varStartIO,
            /* [in] */ VARIANT varAddress,
            /* [in] */ VARIANT varReadSize,
            /* [out] */ VARIANT __RPC_FAR *lpvarData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteBuffer )( 
            IActMLQSS2 __RPC_FAR * This,
            /* [in] */ VARIANT varStartIO,
            /* [in] */ VARIANT varAddress,
            /* [in] */ VARIANT varWriteSize,
            /* [in] */ VARIANT varData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetClockData )( 
            IActMLQSS2 __RPC_FAR * This,
            /* [out] */ VARIANT __RPC_FAR *lpvarYear,
            /* [out] */ VARIANT __RPC_FAR *lpvarMonth,
            /* [out] */ VARIANT __RPC_FAR *lpvarDay,
            /* [out] */ VARIANT __RPC_FAR *lpvarDayOfWeek,
            /* [out] */ VARIANT __RPC_FAR *lpvarHour,
            /* [out] */ VARIANT __RPC_FAR *lpvarMinute,
            /* [out] */ VARIANT __RPC_FAR *lpvarSecond,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetClockData )( 
            IActMLQSS2 __RPC_FAR * This,
            /* [in] */ VARIANT varYear,
            /* [in] */ VARIANT varMonth,
            /* [in] */ VARIANT varDay,
            /* [in] */ VARIANT varDayOfWeek,
            /* [in] */ VARIANT varHour,
            /* [in] */ VARIANT varMinute,
            /* [in] */ VARIANT varSecond,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetCpuType )( 
            IActMLQSS2 __RPC_FAR * This,
            /* [out] */ VARIANT __RPC_FAR *lpvarCpuName,
            /* [out] */ VARIANT __RPC_FAR *lpvarCpuType,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetCpuStatus )( 
            IActMLQSS2 __RPC_FAR * This,
            /* [in] */ VARIANT varOperation,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *EntryDeviceStatus )( 
            IActMLQSS2 __RPC_FAR * This,
            /* [in] */ VARIANT varDeviceList,
            /* [in] */ VARIANT varSize,
            /* [in] */ VARIANT varMonitorCycle,
            /* [in] */ VARIANT varData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *FreeDeviceStatus )( 
            IActMLQSS2 __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceBlock2 )( 
            IActMLQSS2 __RPC_FAR * This,
            /* [in] */ VARIANT varDevice,
            /* [in] */ VARIANT varSize,
            /* [out] */ VARIANT __RPC_FAR *lpvarData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceBlock2 )( 
            IActMLQSS2 __RPC_FAR * This,
            /* [in] */ VARIANT varDevice,
            /* [in] */ VARIANT varSize,
            /* [in] */ VARIANT varData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceRandom2 )( 
            IActMLQSS2 __RPC_FAR * This,
            /* [in] */ VARIANT varDeviceList,
            /* [in] */ VARIANT varSize,
            /* [out] */ VARIANT __RPC_FAR *lpvarData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceRandom2 )( 
            IActMLQSS2 __RPC_FAR * This,
            /* [in] */ VARIANT varDeviceList,
            /* [in] */ VARIANT varSize,
            /* [in] */ VARIANT varData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetDevice2 )( 
            IActMLQSS2 __RPC_FAR * This,
            /* [in] */ VARIANT varDevice,
            /* [out] */ VARIANT __RPC_FAR *lpvarData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetDevice2 )( 
            IActMLQSS2 __RPC_FAR * This,
            /* [in] */ VARIANT varDevice,
            /* [in] */ VARIANT varData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActNetworkNumber )( 
            IActMLQSS2 __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActNetworkNumber )( 
            IActMLQSS2 __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActStationNumber )( 
            IActMLQSS2 __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActStationNumber )( 
            IActMLQSS2 __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActUnitNumber )( 
            IActMLQSS2 __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActUnitNumber )( 
            IActMLQSS2 __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActIONumber )( 
            IActMLQSS2 __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActIONumber )( 
            IActMLQSS2 __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActCpuType )( 
            IActMLQSS2 __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActCpuType )( 
            IActMLQSS2 __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActDestinationIONumber )( 
            IActMLQSS2 __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActDestinationIONumber )( 
            IActMLQSS2 __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActMultiDropChannelNumber )( 
            IActMLQSS2 __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActMultiDropChannelNumber )( 
            IActMLQSS2 __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActThroughNetworkType )( 
            IActMLQSS2 __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActThroughNetworkType )( 
            IActMLQSS2 __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActIntelligentPreferenceBit )( 
            IActMLQSS2 __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActIntelligentPreferenceBit )( 
            IActMLQSS2 __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActDidPropertyBit )( 
            IActMLQSS2 __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActDidPropertyBit )( 
            IActMLQSS2 __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActDsidPropertyBit )( 
            IActMLQSS2 __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActDsidPropertyBit )( 
            IActMLQSS2 __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        END_INTERFACE
    } IActMLQSS2Vtbl;

    interface IActMLQSS2
    {
        CONST_VTBL struct IActMLQSS2Vtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IActMLQSS2_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IActMLQSS2_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IActMLQSS2_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IActMLQSS2_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IActMLQSS2_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IActMLQSS2_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IActMLQSS2_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IActMLQSS2_Open(This,lpvarReturnCode)	\
    (This)->lpVtbl -> Open(This,lpvarReturnCode)

#define IActMLQSS2_Close(This,lpvarReturnCode)	\
    (This)->lpVtbl -> Close(This,lpvarReturnCode)

#define IActMLQSS2_GetDevice(This,varDevice,lpvarData,lpvarReturnCode)	\
    (This)->lpVtbl -> GetDevice(This,varDevice,lpvarData,lpvarReturnCode)

#define IActMLQSS2_SetDevice(This,varDevice,varData,lpvarReturnCode)	\
    (This)->lpVtbl -> SetDevice(This,varDevice,varData,lpvarReturnCode)

#define IActMLQSS2_ReadDeviceBlock(This,varDevice,varSize,lpvarData,lpvarReturnCode)	\
    (This)->lpVtbl -> ReadDeviceBlock(This,varDevice,varSize,lpvarData,lpvarReturnCode)

#define IActMLQSS2_WriteDeviceBlock(This,varDevice,varSize,varData,lpvarReturnCode)	\
    (This)->lpVtbl -> WriteDeviceBlock(This,varDevice,varSize,varData,lpvarReturnCode)

#define IActMLQSS2_ReadDeviceRandom(This,varDeviceList,varSize,lpvarData,lpvarReturnCode)	\
    (This)->lpVtbl -> ReadDeviceRandom(This,varDeviceList,varSize,lpvarData,lpvarReturnCode)

#define IActMLQSS2_WriteDeviceRandom(This,varDeviceList,varSize,varData,lpvarReturnCode)	\
    (This)->lpVtbl -> WriteDeviceRandom(This,varDeviceList,varSize,varData,lpvarReturnCode)

#define IActMLQSS2_ReadBuffer(This,varStartIO,varAddress,varReadSize,lpvarData,lpvarReturnCode)	\
    (This)->lpVtbl -> ReadBuffer(This,varStartIO,varAddress,varReadSize,lpvarData,lpvarReturnCode)

#define IActMLQSS2_WriteBuffer(This,varStartIO,varAddress,varWriteSize,varData,lpvarReturnCode)	\
    (This)->lpVtbl -> WriteBuffer(This,varStartIO,varAddress,varWriteSize,varData,lpvarReturnCode)

#define IActMLQSS2_GetClockData(This,lpvarYear,lpvarMonth,lpvarDay,lpvarDayOfWeek,lpvarHour,lpvarMinute,lpvarSecond,lpvarReturnCode)	\
    (This)->lpVtbl -> GetClockData(This,lpvarYear,lpvarMonth,lpvarDay,lpvarDayOfWeek,lpvarHour,lpvarMinute,lpvarSecond,lpvarReturnCode)

#define IActMLQSS2_SetClockData(This,varYear,varMonth,varDay,varDayOfWeek,varHour,varMinute,varSecond,lpvarReturnCode)	\
    (This)->lpVtbl -> SetClockData(This,varYear,varMonth,varDay,varDayOfWeek,varHour,varMinute,varSecond,lpvarReturnCode)

#define IActMLQSS2_GetCpuType(This,lpvarCpuName,lpvarCpuType,lpvarReturnCode)	\
    (This)->lpVtbl -> GetCpuType(This,lpvarCpuName,lpvarCpuType,lpvarReturnCode)

#define IActMLQSS2_SetCpuStatus(This,varOperation,lpvarReturnCode)	\
    (This)->lpVtbl -> SetCpuStatus(This,varOperation,lpvarReturnCode)

#define IActMLQSS2_EntryDeviceStatus(This,varDeviceList,varSize,varMonitorCycle,varData,lpvarReturnCode)	\
    (This)->lpVtbl -> EntryDeviceStatus(This,varDeviceList,varSize,varMonitorCycle,varData,lpvarReturnCode)

#define IActMLQSS2_FreeDeviceStatus(This,lpvarReturnCode)	\
    (This)->lpVtbl -> FreeDeviceStatus(This,lpvarReturnCode)

#define IActMLQSS2_ReadDeviceBlock2(This,varDevice,varSize,lpvarData,lpvarReturnCode)	\
    (This)->lpVtbl -> ReadDeviceBlock2(This,varDevice,varSize,lpvarData,lpvarReturnCode)

#define IActMLQSS2_WriteDeviceBlock2(This,varDevice,varSize,varData,lpvarReturnCode)	\
    (This)->lpVtbl -> WriteDeviceBlock2(This,varDevice,varSize,varData,lpvarReturnCode)

#define IActMLQSS2_ReadDeviceRandom2(This,varDeviceList,varSize,lpvarData,lpvarReturnCode)	\
    (This)->lpVtbl -> ReadDeviceRandom2(This,varDeviceList,varSize,lpvarData,lpvarReturnCode)

#define IActMLQSS2_WriteDeviceRandom2(This,varDeviceList,varSize,varData,lpvarReturnCode)	\
    (This)->lpVtbl -> WriteDeviceRandom2(This,varDeviceList,varSize,varData,lpvarReturnCode)

#define IActMLQSS2_GetDevice2(This,varDevice,lpvarData,lpvarReturnCode)	\
    (This)->lpVtbl -> GetDevice2(This,varDevice,lpvarData,lpvarReturnCode)

#define IActMLQSS2_SetDevice2(This,varDevice,varData,lpvarReturnCode)	\
    (This)->lpVtbl -> SetDevice2(This,varDevice,varData,lpvarReturnCode)

#define IActMLQSS2_get_ActNetworkNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActNetworkNumber(This,pVal)

#define IActMLQSS2_put_ActNetworkNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActNetworkNumber(This,newVal)

#define IActMLQSS2_get_ActStationNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActStationNumber(This,pVal)

#define IActMLQSS2_put_ActStationNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActStationNumber(This,newVal)

#define IActMLQSS2_get_ActUnitNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActUnitNumber(This,pVal)

#define IActMLQSS2_put_ActUnitNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActUnitNumber(This,newVal)

#define IActMLQSS2_get_ActIONumber(This,pVal)	\
    (This)->lpVtbl -> get_ActIONumber(This,pVal)

#define IActMLQSS2_put_ActIONumber(This,newVal)	\
    (This)->lpVtbl -> put_ActIONumber(This,newVal)

#define IActMLQSS2_get_ActCpuType(This,pVal)	\
    (This)->lpVtbl -> get_ActCpuType(This,pVal)

#define IActMLQSS2_put_ActCpuType(This,newVal)	\
    (This)->lpVtbl -> put_ActCpuType(This,newVal)

#define IActMLQSS2_get_ActDestinationIONumber(This,pVal)	\
    (This)->lpVtbl -> get_ActDestinationIONumber(This,pVal)

#define IActMLQSS2_put_ActDestinationIONumber(This,newVal)	\
    (This)->lpVtbl -> put_ActDestinationIONumber(This,newVal)

#define IActMLQSS2_get_ActMultiDropChannelNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActMultiDropChannelNumber(This,pVal)

#define IActMLQSS2_put_ActMultiDropChannelNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActMultiDropChannelNumber(This,newVal)

#define IActMLQSS2_get_ActThroughNetworkType(This,pVal)	\
    (This)->lpVtbl -> get_ActThroughNetworkType(This,pVal)

#define IActMLQSS2_put_ActThroughNetworkType(This,newVal)	\
    (This)->lpVtbl -> put_ActThroughNetworkType(This,newVal)

#define IActMLQSS2_get_ActIntelligentPreferenceBit(This,pVal)	\
    (This)->lpVtbl -> get_ActIntelligentPreferenceBit(This,pVal)

#define IActMLQSS2_put_ActIntelligentPreferenceBit(This,newVal)	\
    (This)->lpVtbl -> put_ActIntelligentPreferenceBit(This,newVal)

#define IActMLQSS2_get_ActDidPropertyBit(This,pVal)	\
    (This)->lpVtbl -> get_ActDidPropertyBit(This,pVal)

#define IActMLQSS2_put_ActDidPropertyBit(This,newVal)	\
    (This)->lpVtbl -> put_ActDidPropertyBit(This,newVal)

#define IActMLQSS2_get_ActDsidPropertyBit(This,pVal)	\
    (This)->lpVtbl -> get_ActDsidPropertyBit(This,pVal)

#define IActMLQSS2_put_ActDsidPropertyBit(This,newVal)	\
    (This)->lpVtbl -> put_ActDsidPropertyBit(This,newVal)


#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IActMLQSS2_INTERFACE_DEFINED__ */


#ifndef __IActMLQSS3_INTERFACE_DEFINED__
#define __IActMLQSS3_INTERFACE_DEFINED__

/* interface IActMLQSS3 */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IActMLQSS3;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("87166033-710B-11d5-9318-009099244EFD")
    IActMLQSS3 : public IActMLQSS2
    {
    public:
    };
    
#else 	/* C style interface */

    typedef struct IActMLQSS3Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IActMLQSS3 __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IActMLQSS3 __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IActMLQSS3 __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IActMLQSS3 __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IActMLQSS3 __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IActMLQSS3 __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IActMLQSS3 __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Open )( 
            IActMLQSS3 __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Close )( 
            IActMLQSS3 __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetDevice )( 
            IActMLQSS3 __RPC_FAR * This,
            /* [in] */ VARIANT varDevice,
            /* [out] */ VARIANT __RPC_FAR *lpvarData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetDevice )( 
            IActMLQSS3 __RPC_FAR * This,
            /* [in] */ VARIANT varDevice,
            /* [in] */ VARIANT varData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceBlock )( 
            IActMLQSS3 __RPC_FAR * This,
            /* [in] */ VARIANT varDevice,
            /* [in] */ VARIANT varSize,
            /* [out] */ VARIANT __RPC_FAR *lpvarData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceBlock )( 
            IActMLQSS3 __RPC_FAR * This,
            /* [in] */ VARIANT varDevice,
            /* [in] */ VARIANT varSize,
            /* [in] */ VARIANT varData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceRandom )( 
            IActMLQSS3 __RPC_FAR * This,
            /* [in] */ VARIANT varDeviceList,
            /* [in] */ VARIANT varSize,
            /* [out] */ VARIANT __RPC_FAR *lpvarData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceRandom )( 
            IActMLQSS3 __RPC_FAR * This,
            /* [in] */ VARIANT varDeviceList,
            /* [in] */ VARIANT varSize,
            /* [in] */ VARIANT varData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadBuffer )( 
            IActMLQSS3 __RPC_FAR * This,
            /* [in] */ VARIANT varStartIO,
            /* [in] */ VARIANT varAddress,
            /* [in] */ VARIANT varReadSize,
            /* [out] */ VARIANT __RPC_FAR *lpvarData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteBuffer )( 
            IActMLQSS3 __RPC_FAR * This,
            /* [in] */ VARIANT varStartIO,
            /* [in] */ VARIANT varAddress,
            /* [in] */ VARIANT varWriteSize,
            /* [in] */ VARIANT varData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetClockData )( 
            IActMLQSS3 __RPC_FAR * This,
            /* [out] */ VARIANT __RPC_FAR *lpvarYear,
            /* [out] */ VARIANT __RPC_FAR *lpvarMonth,
            /* [out] */ VARIANT __RPC_FAR *lpvarDay,
            /* [out] */ VARIANT __RPC_FAR *lpvarDayOfWeek,
            /* [out] */ VARIANT __RPC_FAR *lpvarHour,
            /* [out] */ VARIANT __RPC_FAR *lpvarMinute,
            /* [out] */ VARIANT __RPC_FAR *lpvarSecond,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetClockData )( 
            IActMLQSS3 __RPC_FAR * This,
            /* [in] */ VARIANT varYear,
            /* [in] */ VARIANT varMonth,
            /* [in] */ VARIANT varDay,
            /* [in] */ VARIANT varDayOfWeek,
            /* [in] */ VARIANT varHour,
            /* [in] */ VARIANT varMinute,
            /* [in] */ VARIANT varSecond,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetCpuType )( 
            IActMLQSS3 __RPC_FAR * This,
            /* [out] */ VARIANT __RPC_FAR *lpvarCpuName,
            /* [out] */ VARIANT __RPC_FAR *lpvarCpuType,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetCpuStatus )( 
            IActMLQSS3 __RPC_FAR * This,
            /* [in] */ VARIANT varOperation,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *EntryDeviceStatus )( 
            IActMLQSS3 __RPC_FAR * This,
            /* [in] */ VARIANT varDeviceList,
            /* [in] */ VARIANT varSize,
            /* [in] */ VARIANT varMonitorCycle,
            /* [in] */ VARIANT varData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *FreeDeviceStatus )( 
            IActMLQSS3 __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceBlock2 )( 
            IActMLQSS3 __RPC_FAR * This,
            /* [in] */ VARIANT varDevice,
            /* [in] */ VARIANT varSize,
            /* [out] */ VARIANT __RPC_FAR *lpvarData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceBlock2 )( 
            IActMLQSS3 __RPC_FAR * This,
            /* [in] */ VARIANT varDevice,
            /* [in] */ VARIANT varSize,
            /* [in] */ VARIANT varData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceRandom2 )( 
            IActMLQSS3 __RPC_FAR * This,
            /* [in] */ VARIANT varDeviceList,
            /* [in] */ VARIANT varSize,
            /* [out] */ VARIANT __RPC_FAR *lpvarData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceRandom2 )( 
            IActMLQSS3 __RPC_FAR * This,
            /* [in] */ VARIANT varDeviceList,
            /* [in] */ VARIANT varSize,
            /* [in] */ VARIANT varData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetDevice2 )( 
            IActMLQSS3 __RPC_FAR * This,
            /* [in] */ VARIANT varDevice,
            /* [out] */ VARIANT __RPC_FAR *lpvarData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetDevice2 )( 
            IActMLQSS3 __RPC_FAR * This,
            /* [in] */ VARIANT varDevice,
            /* [in] */ VARIANT varData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActNetworkNumber )( 
            IActMLQSS3 __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActNetworkNumber )( 
            IActMLQSS3 __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActStationNumber )( 
            IActMLQSS3 __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActStationNumber )( 
            IActMLQSS3 __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActUnitNumber )( 
            IActMLQSS3 __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActUnitNumber )( 
            IActMLQSS3 __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActIONumber )( 
            IActMLQSS3 __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActIONumber )( 
            IActMLQSS3 __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActCpuType )( 
            IActMLQSS3 __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActCpuType )( 
            IActMLQSS3 __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActDestinationIONumber )( 
            IActMLQSS3 __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActDestinationIONumber )( 
            IActMLQSS3 __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActMultiDropChannelNumber )( 
            IActMLQSS3 __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActMultiDropChannelNumber )( 
            IActMLQSS3 __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActThroughNetworkType )( 
            IActMLQSS3 __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActThroughNetworkType )( 
            IActMLQSS3 __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActIntelligentPreferenceBit )( 
            IActMLQSS3 __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActIntelligentPreferenceBit )( 
            IActMLQSS3 __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActDidPropertyBit )( 
            IActMLQSS3 __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActDidPropertyBit )( 
            IActMLQSS3 __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActDsidPropertyBit )( 
            IActMLQSS3 __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActDsidPropertyBit )( 
            IActMLQSS3 __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        END_INTERFACE
    } IActMLQSS3Vtbl;

    interface IActMLQSS3
    {
        CONST_VTBL struct IActMLQSS3Vtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IActMLQSS3_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IActMLQSS3_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IActMLQSS3_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IActMLQSS3_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IActMLQSS3_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IActMLQSS3_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IActMLQSS3_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IActMLQSS3_Open(This,lpvarReturnCode)	\
    (This)->lpVtbl -> Open(This,lpvarReturnCode)

#define IActMLQSS3_Close(This,lpvarReturnCode)	\
    (This)->lpVtbl -> Close(This,lpvarReturnCode)

#define IActMLQSS3_GetDevice(This,varDevice,lpvarData,lpvarReturnCode)	\
    (This)->lpVtbl -> GetDevice(This,varDevice,lpvarData,lpvarReturnCode)

#define IActMLQSS3_SetDevice(This,varDevice,varData,lpvarReturnCode)	\
    (This)->lpVtbl -> SetDevice(This,varDevice,varData,lpvarReturnCode)

#define IActMLQSS3_ReadDeviceBlock(This,varDevice,varSize,lpvarData,lpvarReturnCode)	\
    (This)->lpVtbl -> ReadDeviceBlock(This,varDevice,varSize,lpvarData,lpvarReturnCode)

#define IActMLQSS3_WriteDeviceBlock(This,varDevice,varSize,varData,lpvarReturnCode)	\
    (This)->lpVtbl -> WriteDeviceBlock(This,varDevice,varSize,varData,lpvarReturnCode)

#define IActMLQSS3_ReadDeviceRandom(This,varDeviceList,varSize,lpvarData,lpvarReturnCode)	\
    (This)->lpVtbl -> ReadDeviceRandom(This,varDeviceList,varSize,lpvarData,lpvarReturnCode)

#define IActMLQSS3_WriteDeviceRandom(This,varDeviceList,varSize,varData,lpvarReturnCode)	\
    (This)->lpVtbl -> WriteDeviceRandom(This,varDeviceList,varSize,varData,lpvarReturnCode)

#define IActMLQSS3_ReadBuffer(This,varStartIO,varAddress,varReadSize,lpvarData,lpvarReturnCode)	\
    (This)->lpVtbl -> ReadBuffer(This,varStartIO,varAddress,varReadSize,lpvarData,lpvarReturnCode)

#define IActMLQSS3_WriteBuffer(This,varStartIO,varAddress,varWriteSize,varData,lpvarReturnCode)	\
    (This)->lpVtbl -> WriteBuffer(This,varStartIO,varAddress,varWriteSize,varData,lpvarReturnCode)

#define IActMLQSS3_GetClockData(This,lpvarYear,lpvarMonth,lpvarDay,lpvarDayOfWeek,lpvarHour,lpvarMinute,lpvarSecond,lpvarReturnCode)	\
    (This)->lpVtbl -> GetClockData(This,lpvarYear,lpvarMonth,lpvarDay,lpvarDayOfWeek,lpvarHour,lpvarMinute,lpvarSecond,lpvarReturnCode)

#define IActMLQSS3_SetClockData(This,varYear,varMonth,varDay,varDayOfWeek,varHour,varMinute,varSecond,lpvarReturnCode)	\
    (This)->lpVtbl -> SetClockData(This,varYear,varMonth,varDay,varDayOfWeek,varHour,varMinute,varSecond,lpvarReturnCode)

#define IActMLQSS3_GetCpuType(This,lpvarCpuName,lpvarCpuType,lpvarReturnCode)	\
    (This)->lpVtbl -> GetCpuType(This,lpvarCpuName,lpvarCpuType,lpvarReturnCode)

#define IActMLQSS3_SetCpuStatus(This,varOperation,lpvarReturnCode)	\
    (This)->lpVtbl -> SetCpuStatus(This,varOperation,lpvarReturnCode)

#define IActMLQSS3_EntryDeviceStatus(This,varDeviceList,varSize,varMonitorCycle,varData,lpvarReturnCode)	\
    (This)->lpVtbl -> EntryDeviceStatus(This,varDeviceList,varSize,varMonitorCycle,varData,lpvarReturnCode)

#define IActMLQSS3_FreeDeviceStatus(This,lpvarReturnCode)	\
    (This)->lpVtbl -> FreeDeviceStatus(This,lpvarReturnCode)

#define IActMLQSS3_ReadDeviceBlock2(This,varDevice,varSize,lpvarData,lpvarReturnCode)	\
    (This)->lpVtbl -> ReadDeviceBlock2(This,varDevice,varSize,lpvarData,lpvarReturnCode)

#define IActMLQSS3_WriteDeviceBlock2(This,varDevice,varSize,varData,lpvarReturnCode)	\
    (This)->lpVtbl -> WriteDeviceBlock2(This,varDevice,varSize,varData,lpvarReturnCode)

#define IActMLQSS3_ReadDeviceRandom2(This,varDeviceList,varSize,lpvarData,lpvarReturnCode)	\
    (This)->lpVtbl -> ReadDeviceRandom2(This,varDeviceList,varSize,lpvarData,lpvarReturnCode)

#define IActMLQSS3_WriteDeviceRandom2(This,varDeviceList,varSize,varData,lpvarReturnCode)	\
    (This)->lpVtbl -> WriteDeviceRandom2(This,varDeviceList,varSize,varData,lpvarReturnCode)

#define IActMLQSS3_GetDevice2(This,varDevice,lpvarData,lpvarReturnCode)	\
    (This)->lpVtbl -> GetDevice2(This,varDevice,lpvarData,lpvarReturnCode)

#define IActMLQSS3_SetDevice2(This,varDevice,varData,lpvarReturnCode)	\
    (This)->lpVtbl -> SetDevice2(This,varDevice,varData,lpvarReturnCode)

#define IActMLQSS3_get_ActNetworkNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActNetworkNumber(This,pVal)

#define IActMLQSS3_put_ActNetworkNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActNetworkNumber(This,newVal)

#define IActMLQSS3_get_ActStationNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActStationNumber(This,pVal)

#define IActMLQSS3_put_ActStationNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActStationNumber(This,newVal)

#define IActMLQSS3_get_ActUnitNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActUnitNumber(This,pVal)

#define IActMLQSS3_put_ActUnitNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActUnitNumber(This,newVal)

#define IActMLQSS3_get_ActIONumber(This,pVal)	\
    (This)->lpVtbl -> get_ActIONumber(This,pVal)

#define IActMLQSS3_put_ActIONumber(This,newVal)	\
    (This)->lpVtbl -> put_ActIONumber(This,newVal)

#define IActMLQSS3_get_ActCpuType(This,pVal)	\
    (This)->lpVtbl -> get_ActCpuType(This,pVal)

#define IActMLQSS3_put_ActCpuType(This,newVal)	\
    (This)->lpVtbl -> put_ActCpuType(This,newVal)

#define IActMLQSS3_get_ActDestinationIONumber(This,pVal)	\
    (This)->lpVtbl -> get_ActDestinationIONumber(This,pVal)

#define IActMLQSS3_put_ActDestinationIONumber(This,newVal)	\
    (This)->lpVtbl -> put_ActDestinationIONumber(This,newVal)

#define IActMLQSS3_get_ActMultiDropChannelNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActMultiDropChannelNumber(This,pVal)

#define IActMLQSS3_put_ActMultiDropChannelNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActMultiDropChannelNumber(This,newVal)

#define IActMLQSS3_get_ActThroughNetworkType(This,pVal)	\
    (This)->lpVtbl -> get_ActThroughNetworkType(This,pVal)

#define IActMLQSS3_put_ActThroughNetworkType(This,newVal)	\
    (This)->lpVtbl -> put_ActThroughNetworkType(This,newVal)

#define IActMLQSS3_get_ActIntelligentPreferenceBit(This,pVal)	\
    (This)->lpVtbl -> get_ActIntelligentPreferenceBit(This,pVal)

#define IActMLQSS3_put_ActIntelligentPreferenceBit(This,newVal)	\
    (This)->lpVtbl -> put_ActIntelligentPreferenceBit(This,newVal)

#define IActMLQSS3_get_ActDidPropertyBit(This,pVal)	\
    (This)->lpVtbl -> get_ActDidPropertyBit(This,pVal)

#define IActMLQSS3_put_ActDidPropertyBit(This,newVal)	\
    (This)->lpVtbl -> put_ActDidPropertyBit(This,newVal)

#define IActMLQSS3_get_ActDsidPropertyBit(This,pVal)	\
    (This)->lpVtbl -> get_ActDsidPropertyBit(This,pVal)

#define IActMLQSS3_put_ActDsidPropertyBit(This,newVal)	\
    (This)->lpVtbl -> put_ActDsidPropertyBit(This,newVal)



#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IActMLQSS3_INTERFACE_DEFINED__ */



#ifndef __ACTPCMODULELib_LIBRARY_DEFINED__
#define __ACTPCMODULELib_LIBRARY_DEFINED__

/* library ACTPCMODULELib */
/* [helpstring][version][uuid] */ 


EXTERN_C const IID LIBID_ACTPCMODULELib;

#ifndef ___IActQCPUQBusEvents_DISPINTERFACE_DEFINED__
#define ___IActQCPUQBusEvents_DISPINTERFACE_DEFINED__

/* dispinterface _IActQCPUQBusEvents */
/* [helpstring][uuid] */ 


EXTERN_C const IID DIID__IActQCPUQBusEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("062B9B58-AA34-11D4-910F-009099244EFD")
    _IActQCPUQBusEvents : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct _IActQCPUQBusEventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            _IActQCPUQBusEvents __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            _IActQCPUQBusEvents __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            _IActQCPUQBusEvents __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            _IActQCPUQBusEvents __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            _IActQCPUQBusEvents __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            _IActQCPUQBusEvents __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            _IActQCPUQBusEvents __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        END_INTERFACE
    } _IActQCPUQBusEventsVtbl;

    interface _IActQCPUQBusEvents
    {
        CONST_VTBL struct _IActQCPUQBusEventsVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _IActQCPUQBusEvents_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define _IActQCPUQBusEvents_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define _IActQCPUQBusEvents_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define _IActQCPUQBusEvents_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define _IActQCPUQBusEvents_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define _IActQCPUQBusEvents_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define _IActQCPUQBusEvents_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ___IActQCPUQBusEvents_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_ActQCPUQBus;

#ifdef __cplusplus

class DECLSPEC_UUID("062B9B57-AA34-11D4-910F-009099244EFD")
ActQCPUQBus;
#endif

#ifndef ___IActMLQCPUQBusEvents_DISPINTERFACE_DEFINED__
#define ___IActMLQCPUQBusEvents_DISPINTERFACE_DEFINED__

/* dispinterface _IActMLQCPUQBusEvents */
/* [helpstring][uuid] */ 


EXTERN_C const IID DIID__IActMLQCPUQBusEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("062B9B5B-AA34-11D4-910F-009099244EFD")
    _IActMLQCPUQBusEvents : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct _IActMLQCPUQBusEventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            _IActMLQCPUQBusEvents __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            _IActMLQCPUQBusEvents __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            _IActMLQCPUQBusEvents __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            _IActMLQCPUQBusEvents __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            _IActMLQCPUQBusEvents __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            _IActMLQCPUQBusEvents __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            _IActMLQCPUQBusEvents __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        END_INTERFACE
    } _IActMLQCPUQBusEventsVtbl;

    interface _IActMLQCPUQBusEvents
    {
        CONST_VTBL struct _IActMLQCPUQBusEventsVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _IActMLQCPUQBusEvents_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define _IActMLQCPUQBusEvents_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define _IActMLQCPUQBusEvents_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define _IActMLQCPUQBusEvents_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define _IActMLQCPUQBusEvents_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define _IActMLQCPUQBusEvents_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define _IActMLQCPUQBusEvents_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ___IActMLQCPUQBusEvents_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_ActMLQCPUQBus;

#ifdef __cplusplus

class DECLSPEC_UUID("062B9B5A-AA34-11D4-910F-009099244EFD")
ActMLQCPUQBus;
#endif

#ifndef ___IActQSSEvents_DISPINTERFACE_DEFINED__
#define ___IActQSSEvents_DISPINTERFACE_DEFINED__

/* dispinterface _IActQSSEvents */
/* [helpstring][uuid] */ 


EXTERN_C const IID DIID__IActQSSEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("A6BE4A93-70EC-11D5-9318-009099244EFD")
    _IActQSSEvents : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct _IActQSSEventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            _IActQSSEvents __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            _IActQSSEvents __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            _IActQSSEvents __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            _IActQSSEvents __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            _IActQSSEvents __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            _IActQSSEvents __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            _IActQSSEvents __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        END_INTERFACE
    } _IActQSSEventsVtbl;

    interface _IActQSSEvents
    {
        CONST_VTBL struct _IActQSSEventsVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _IActQSSEvents_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define _IActQSSEvents_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define _IActQSSEvents_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define _IActQSSEvents_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define _IActQSSEvents_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define _IActQSSEvents_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define _IActQSSEvents_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ___IActQSSEvents_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_ActQSS;

#ifdef __cplusplus

class DECLSPEC_UUID("A6BE4A92-70EC-11D5-9318-009099244EFD")
ActQSS;
#endif

#ifndef ___IActMLQSSEvents_DISPINTERFACE_DEFINED__
#define ___IActMLQSSEvents_DISPINTERFACE_DEFINED__

/* dispinterface _IActMLQSSEvents */
/* [helpstring][uuid] */ 


EXTERN_C const IID DIID__IActMLQSSEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("A6BE4A96-70EC-11D5-9318-009099244EFD")
    _IActMLQSSEvents : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct _IActMLQSSEventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            _IActMLQSSEvents __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            _IActMLQSSEvents __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            _IActMLQSSEvents __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            _IActMLQSSEvents __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            _IActMLQSSEvents __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            _IActMLQSSEvents __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            _IActMLQSSEvents __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        END_INTERFACE
    } _IActMLQSSEventsVtbl;

    interface _IActMLQSSEvents
    {
        CONST_VTBL struct _IActMLQSSEventsVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _IActMLQSSEvents_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define _IActMLQSSEvents_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define _IActMLQSSEvents_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define _IActMLQSSEvents_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define _IActMLQSSEvents_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define _IActMLQSSEvents_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define _IActMLQSSEvents_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ___IActMLQSSEvents_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_ActMLQSS;

#ifdef __cplusplus

class DECLSPEC_UUID("A6BE4A95-70EC-11D5-9318-009099244EFD")
ActMLQSS;
#endif
#endif /* __ACTPCMODULELib_LIBRARY_DEFINED__ */

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
