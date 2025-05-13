/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 5.01.0164 */
/* at Fri Apr 12 12:30:17 2013
 */
/* Compiler settings for D:\GETMODULE\CommunicationSupport2\SW3D5\ACT\Control\ActCcG4\ActCcG4.idl:
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

#ifndef __ActCcG4_h__
#define __ActCcG4_h__

#ifdef __cplusplus
extern "C"{
#endif 

/* Forward Declarations */ 

#ifndef __IActCCG4QnA_FWD_DEFINED__
#define __IActCCG4QnA_FWD_DEFINED__
typedef interface IActCCG4QnA IActCCG4QnA;
#endif 	/* __IActCCG4QnA_FWD_DEFINED__ */


#ifndef __IActCCG4QnA2_FWD_DEFINED__
#define __IActCCG4QnA2_FWD_DEFINED__
typedef interface IActCCG4QnA2 IActCCG4QnA2;
#endif 	/* __IActCCG4QnA2_FWD_DEFINED__ */


#ifndef __IActCCG4QnA3_FWD_DEFINED__
#define __IActCCG4QnA3_FWD_DEFINED__
typedef interface IActCCG4QnA3 IActCCG4QnA3;
#endif 	/* __IActCCG4QnA3_FWD_DEFINED__ */


#ifndef __IActCCG4A_FWD_DEFINED__
#define __IActCCG4A_FWD_DEFINED__
typedef interface IActCCG4A IActCCG4A;
#endif 	/* __IActCCG4A_FWD_DEFINED__ */


#ifndef __IActCCG4A2_FWD_DEFINED__
#define __IActCCG4A2_FWD_DEFINED__
typedef interface IActCCG4A2 IActCCG4A2;
#endif 	/* __IActCCG4A2_FWD_DEFINED__ */


#ifndef __IActCCG4A3_FWD_DEFINED__
#define __IActCCG4A3_FWD_DEFINED__
typedef interface IActCCG4A3 IActCCG4A3;
#endif 	/* __IActCCG4A3_FWD_DEFINED__ */


#ifndef __IActMLCCG4A_FWD_DEFINED__
#define __IActMLCCG4A_FWD_DEFINED__
typedef interface IActMLCCG4A IActMLCCG4A;
#endif 	/* __IActMLCCG4A_FWD_DEFINED__ */


#ifndef __IActMLCCG4A2_FWD_DEFINED__
#define __IActMLCCG4A2_FWD_DEFINED__
typedef interface IActMLCCG4A2 IActMLCCG4A2;
#endif 	/* __IActMLCCG4A2_FWD_DEFINED__ */


#ifndef __IActMLCCG4A3_FWD_DEFINED__
#define __IActMLCCG4A3_FWD_DEFINED__
typedef interface IActMLCCG4A3 IActMLCCG4A3;
#endif 	/* __IActMLCCG4A3_FWD_DEFINED__ */


#ifndef __IActMLCCG4QnA_FWD_DEFINED__
#define __IActMLCCG4QnA_FWD_DEFINED__
typedef interface IActMLCCG4QnA IActMLCCG4QnA;
#endif 	/* __IActMLCCG4QnA_FWD_DEFINED__ */


#ifndef __IActMLCCG4QnA2_FWD_DEFINED__
#define __IActMLCCG4QnA2_FWD_DEFINED__
typedef interface IActMLCCG4QnA2 IActMLCCG4QnA2;
#endif 	/* __IActMLCCG4QnA2_FWD_DEFINED__ */


#ifndef __IActMLCCG4QnA3_FWD_DEFINED__
#define __IActMLCCG4QnA3_FWD_DEFINED__
typedef interface IActMLCCG4QnA3 IActMLCCG4QnA3;
#endif 	/* __IActMLCCG4QnA3_FWD_DEFINED__ */


#ifndef __IActCCG4Q_FWD_DEFINED__
#define __IActCCG4Q_FWD_DEFINED__
typedef interface IActCCG4Q IActCCG4Q;
#endif 	/* __IActCCG4Q_FWD_DEFINED__ */


#ifndef __IActCCG4Q2_FWD_DEFINED__
#define __IActCCG4Q2_FWD_DEFINED__
typedef interface IActCCG4Q2 IActCCG4Q2;
#endif 	/* __IActCCG4Q2_FWD_DEFINED__ */


#ifndef __IActCCG4Q3_FWD_DEFINED__
#define __IActCCG4Q3_FWD_DEFINED__
typedef interface IActCCG4Q3 IActCCG4Q3;
#endif 	/* __IActCCG4Q3_FWD_DEFINED__ */


#ifndef __IActMLCCG4Q_FWD_DEFINED__
#define __IActMLCCG4Q_FWD_DEFINED__
typedef interface IActMLCCG4Q IActMLCCG4Q;
#endif 	/* __IActMLCCG4Q_FWD_DEFINED__ */


#ifndef __IActMLCCG4Q2_FWD_DEFINED__
#define __IActMLCCG4Q2_FWD_DEFINED__
typedef interface IActMLCCG4Q2 IActMLCCG4Q2;
#endif 	/* __IActMLCCG4Q2_FWD_DEFINED__ */


#ifndef __IActMLCCG4Q3_FWD_DEFINED__
#define __IActMLCCG4Q3_FWD_DEFINED__
typedef interface IActMLCCG4Q3 IActMLCCG4Q3;
#endif 	/* __IActMLCCG4Q3_FWD_DEFINED__ */


#ifndef ___IActCCG4QnAEvents_FWD_DEFINED__
#define ___IActCCG4QnAEvents_FWD_DEFINED__
typedef interface _IActCCG4QnAEvents _IActCCG4QnAEvents;
#endif 	/* ___IActCCG4QnAEvents_FWD_DEFINED__ */


#ifndef __ActCCG4QnA_FWD_DEFINED__
#define __ActCCG4QnA_FWD_DEFINED__

#ifdef __cplusplus
typedef class ActCCG4QnA ActCCG4QnA;
#else
typedef struct ActCCG4QnA ActCCG4QnA;
#endif /* __cplusplus */

#endif 	/* __ActCCG4QnA_FWD_DEFINED__ */


#ifndef ___IActCCG4AEvents_FWD_DEFINED__
#define ___IActCCG4AEvents_FWD_DEFINED__
typedef interface _IActCCG4AEvents _IActCCG4AEvents;
#endif 	/* ___IActCCG4AEvents_FWD_DEFINED__ */


#ifndef __ActCCG4A_FWD_DEFINED__
#define __ActCCG4A_FWD_DEFINED__

#ifdef __cplusplus
typedef class ActCCG4A ActCCG4A;
#else
typedef struct ActCCG4A ActCCG4A;
#endif /* __cplusplus */

#endif 	/* __ActCCG4A_FWD_DEFINED__ */


#ifndef ___IActMLCCG4AEvents_FWD_DEFINED__
#define ___IActMLCCG4AEvents_FWD_DEFINED__
typedef interface _IActMLCCG4AEvents _IActMLCCG4AEvents;
#endif 	/* ___IActMLCCG4AEvents_FWD_DEFINED__ */


#ifndef __ActMLCCG4A_FWD_DEFINED__
#define __ActMLCCG4A_FWD_DEFINED__

#ifdef __cplusplus
typedef class ActMLCCG4A ActMLCCG4A;
#else
typedef struct ActMLCCG4A ActMLCCG4A;
#endif /* __cplusplus */

#endif 	/* __ActMLCCG4A_FWD_DEFINED__ */


#ifndef ___IActMLCCG4QnAEvents_FWD_DEFINED__
#define ___IActMLCCG4QnAEvents_FWD_DEFINED__
typedef interface _IActMLCCG4QnAEvents _IActMLCCG4QnAEvents;
#endif 	/* ___IActMLCCG4QnAEvents_FWD_DEFINED__ */


#ifndef __ActMLCCG4QnA_FWD_DEFINED__
#define __ActMLCCG4QnA_FWD_DEFINED__

#ifdef __cplusplus
typedef class ActMLCCG4QnA ActMLCCG4QnA;
#else
typedef struct ActMLCCG4QnA ActMLCCG4QnA;
#endif /* __cplusplus */

#endif 	/* __ActMLCCG4QnA_FWD_DEFINED__ */


#ifndef ___IActCCG4QEvents_FWD_DEFINED__
#define ___IActCCG4QEvents_FWD_DEFINED__
typedef interface _IActCCG4QEvents _IActCCG4QEvents;
#endif 	/* ___IActCCG4QEvents_FWD_DEFINED__ */


#ifndef __ActCCG4Q_FWD_DEFINED__
#define __ActCCG4Q_FWD_DEFINED__

#ifdef __cplusplus
typedef class ActCCG4Q ActCCG4Q;
#else
typedef struct ActCCG4Q ActCCG4Q;
#endif /* __cplusplus */

#endif 	/* __ActCCG4Q_FWD_DEFINED__ */


#ifndef ___IActMLCCG4QEvents_FWD_DEFINED__
#define ___IActMLCCG4QEvents_FWD_DEFINED__
typedef interface _IActMLCCG4QEvents _IActMLCCG4QEvents;
#endif 	/* ___IActMLCCG4QEvents_FWD_DEFINED__ */


#ifndef __ActMLCCG4Q_FWD_DEFINED__
#define __ActMLCCG4Q_FWD_DEFINED__

#ifdef __cplusplus
typedef class ActMLCCG4Q ActMLCCG4Q;
#else
typedef struct ActMLCCG4Q ActMLCCG4Q;
#endif /* __cplusplus */

#endif 	/* __ActMLCCG4Q_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

void __RPC_FAR * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void __RPC_FAR * ); 

#ifndef __IActCCG4QnA_INTERFACE_DEFINED__
#define __IActCCG4QnA_INTERFACE_DEFINED__

/* interface IActCCG4QnA */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IActCCG4QnA;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("8215E4F1-AE9D-11D3-83AE-00A024BDBF2B")
    IActCCG4QnA : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Open( 
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Close( 
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetCpuType( 
            /* [string][out] */ BSTR __RPC_FAR *szCpuName,
            /* [out] */ LONG __RPC_FAR *lplCpuCode,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetCpuStatus( 
            /* [in] */ LONG lOperation,
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
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetDevice( 
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActNetworkNumber( 
            /* [retval][out] */ LONG __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActNetworkNumber( 
            /* [in] */ LONG newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActStationNumber( 
            /* [retval][out] */ LONG __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActStationNumber( 
            /* [in] */ LONG newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActUnitNumber( 
            /* [retval][out] */ LONG __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActUnitNumber( 
            /* [in] */ LONG newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActConnectUnitNumber( 
            /* [retval][out] */ LONG __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActConnectUnitNumber( 
            /* [in] */ LONG newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActIONumber( 
            /* [retval][out] */ LONG __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActIONumber( 
            /* [in] */ LONG newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActCpuType( 
            /* [retval][out] */ LONG __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActCpuType( 
            /* [in] */ LONG newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActPortNumber( 
            /* [retval][out] */ LONG __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActPortNumber( 
            /* [in] */ LONG newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActBaudRate( 
            /* [retval][out] */ LONG __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActBaudRate( 
            /* [in] */ LONG newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActControl( 
            /* [retval][out] */ LONG __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActControl( 
            /* [in] */ LONG newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActTimeOut( 
            /* [retval][out] */ LONG __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActTimeOut( 
            /* [in] */ LONG newVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetDevice( 
            /* [string][in] */ BSTR szDevice,
            /* [out] */ LONG __RPC_FAR *lplData,
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

    typedef struct IActCCG4QnAVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IActCCG4QnA __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IActCCG4QnA __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IActCCG4QnA __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IActCCG4QnA __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IActCCG4QnA __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IActCCG4QnA __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IActCCG4QnA __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Open )( 
            IActCCG4QnA __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Close )( 
            IActCCG4QnA __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetCpuType )( 
            IActCCG4QnA __RPC_FAR * This,
            /* [string][out] */ BSTR __RPC_FAR *szCpuName,
            /* [out] */ LONG __RPC_FAR *lplCpuCode,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetCpuStatus )( 
            IActCCG4QnA __RPC_FAR * This,
            /* [in] */ LONG lOperation,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceBlock )( 
            IActCCG4QnA __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lSize,
            /* [size_is][out] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceBlock )( 
            IActCCG4QnA __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lSize,
            /* [size_is][in] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceRandom )( 
            IActCCG4QnA __RPC_FAR * This,
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG lSize,
            /* [size_is][out] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceRandom )( 
            IActCCG4QnA __RPC_FAR * This,
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG lSize,
            /* [size_is][in] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadBuffer )( 
            IActCCG4QnA __RPC_FAR * This,
            /* [in] */ LONG lStartIO,
            /* [in] */ LONG lAddress,
            /* [in] */ LONG lSize,
            /* [size_is][out] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteBuffer )( 
            IActCCG4QnA __RPC_FAR * This,
            /* [in] */ LONG lStartIO,
            /* [in] */ LONG lAddress,
            /* [in] */ LONG lSize,
            /* [size_is][in] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetClockData )( 
            IActCCG4QnA __RPC_FAR * This,
            /* [out] */ SHORT __RPC_FAR *lpsYear,
            /* [out] */ SHORT __RPC_FAR *lpsMonth,
            /* [out] */ SHORT __RPC_FAR *lpsDay,
            /* [out] */ SHORT __RPC_FAR *lpsDayOfWeek,
            /* [out] */ SHORT __RPC_FAR *lpsHour,
            /* [out] */ SHORT __RPC_FAR *lpsMinute,
            /* [out] */ SHORT __RPC_FAR *lpsSecond,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetClockData )( 
            IActCCG4QnA __RPC_FAR * This,
            /* [in] */ SHORT sYear,
            /* [in] */ SHORT sMonth,
            /* [in] */ SHORT sDay,
            /* [in] */ SHORT sDayOfWeek,
            /* [in] */ SHORT sHour,
            /* [in] */ SHORT sMinute,
            /* [in] */ SHORT sSecond,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetDevice )( 
            IActCCG4QnA __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActNetworkNumber )( 
            IActCCG4QnA __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActNetworkNumber )( 
            IActCCG4QnA __RPC_FAR * This,
            /* [in] */ LONG newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActStationNumber )( 
            IActCCG4QnA __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActStationNumber )( 
            IActCCG4QnA __RPC_FAR * This,
            /* [in] */ LONG newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActUnitNumber )( 
            IActCCG4QnA __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActUnitNumber )( 
            IActCCG4QnA __RPC_FAR * This,
            /* [in] */ LONG newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActConnectUnitNumber )( 
            IActCCG4QnA __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActConnectUnitNumber )( 
            IActCCG4QnA __RPC_FAR * This,
            /* [in] */ LONG newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActIONumber )( 
            IActCCG4QnA __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActIONumber )( 
            IActCCG4QnA __RPC_FAR * This,
            /* [in] */ LONG newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActCpuType )( 
            IActCCG4QnA __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActCpuType )( 
            IActCCG4QnA __RPC_FAR * This,
            /* [in] */ LONG newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActPortNumber )( 
            IActCCG4QnA __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActPortNumber )( 
            IActCCG4QnA __RPC_FAR * This,
            /* [in] */ LONG newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActBaudRate )( 
            IActCCG4QnA __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActBaudRate )( 
            IActCCG4QnA __RPC_FAR * This,
            /* [in] */ LONG newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActControl )( 
            IActCCG4QnA __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActControl )( 
            IActCCG4QnA __RPC_FAR * This,
            /* [in] */ LONG newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActTimeOut )( 
            IActCCG4QnA __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActTimeOut )( 
            IActCCG4QnA __RPC_FAR * This,
            /* [in] */ LONG newVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetDevice )( 
            IActCCG4QnA __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [out] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CheckDeviceString )( 
            IActCCG4QnA __RPC_FAR * This,
            /* [in] */ BSTR szDevice,
            /* [in] */ LONG lCheckType,
            /* [in] */ LONG lSize,
            /* [out] */ LONG __RPC_FAR *lplDeviceType,
            /* [string][out] */ BSTR __RPC_FAR *lpszDeviceName,
            /* [out] */ LONG __RPC_FAR *lplDeviceNumber,
            /* [out] */ LONG __RPC_FAR *lplDeviceRadix,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        END_INTERFACE
    } IActCCG4QnAVtbl;

    interface IActCCG4QnA
    {
        CONST_VTBL struct IActCCG4QnAVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IActCCG4QnA_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IActCCG4QnA_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IActCCG4QnA_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IActCCG4QnA_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IActCCG4QnA_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IActCCG4QnA_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IActCCG4QnA_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IActCCG4QnA_Open(This,lplReturnCode)	\
    (This)->lpVtbl -> Open(This,lplReturnCode)

#define IActCCG4QnA_Close(This,lplReturnCode)	\
    (This)->lpVtbl -> Close(This,lplReturnCode)

#define IActCCG4QnA_GetCpuType(This,szCpuName,lplCpuCode,lplReturnCode)	\
    (This)->lpVtbl -> GetCpuType(This,szCpuName,lplCpuCode,lplReturnCode)

#define IActCCG4QnA_SetCpuStatus(This,lOperation,lplReturnCode)	\
    (This)->lpVtbl -> SetCpuStatus(This,lOperation,lplReturnCode)

#define IActCCG4QnA_ReadDeviceBlock(This,szDevice,lSize,lplData,lplReturnCode)	\
    (This)->lpVtbl -> ReadDeviceBlock(This,szDevice,lSize,lplData,lplReturnCode)

#define IActCCG4QnA_WriteDeviceBlock(This,szDevice,lSize,lplData,lplReturnCode)	\
    (This)->lpVtbl -> WriteDeviceBlock(This,szDevice,lSize,lplData,lplReturnCode)

#define IActCCG4QnA_ReadDeviceRandom(This,szDeviceList,lSize,lplData,lplReturnCode)	\
    (This)->lpVtbl -> ReadDeviceRandom(This,szDeviceList,lSize,lplData,lplReturnCode)

#define IActCCG4QnA_WriteDeviceRandom(This,szDeviceList,lSize,lplData,lplReturnCode)	\
    (This)->lpVtbl -> WriteDeviceRandom(This,szDeviceList,lSize,lplData,lplReturnCode)

#define IActCCG4QnA_ReadBuffer(This,lStartIO,lAddress,lSize,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> ReadBuffer(This,lStartIO,lAddress,lSize,lpsData,lplReturnCode)

#define IActCCG4QnA_WriteBuffer(This,lStartIO,lAddress,lSize,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> WriteBuffer(This,lStartIO,lAddress,lSize,lpsData,lplReturnCode)

#define IActCCG4QnA_GetClockData(This,lpsYear,lpsMonth,lpsDay,lpsDayOfWeek,lpsHour,lpsMinute,lpsSecond,lplReturnCode)	\
    (This)->lpVtbl -> GetClockData(This,lpsYear,lpsMonth,lpsDay,lpsDayOfWeek,lpsHour,lpsMinute,lpsSecond,lplReturnCode)

#define IActCCG4QnA_SetClockData(This,sYear,sMonth,sDay,sDayOfWeek,sHour,sMinute,sSecond,lplReturnCode)	\
    (This)->lpVtbl -> SetClockData(This,sYear,sMonth,sDay,sDayOfWeek,sHour,sMinute,sSecond,lplReturnCode)

#define IActCCG4QnA_SetDevice(This,szDevice,lData,lplReturnCode)	\
    (This)->lpVtbl -> SetDevice(This,szDevice,lData,lplReturnCode)

#define IActCCG4QnA_get_ActNetworkNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActNetworkNumber(This,pVal)

#define IActCCG4QnA_put_ActNetworkNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActNetworkNumber(This,newVal)

#define IActCCG4QnA_get_ActStationNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActStationNumber(This,pVal)

#define IActCCG4QnA_put_ActStationNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActStationNumber(This,newVal)

#define IActCCG4QnA_get_ActUnitNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActUnitNumber(This,pVal)

#define IActCCG4QnA_put_ActUnitNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActUnitNumber(This,newVal)

#define IActCCG4QnA_get_ActConnectUnitNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActConnectUnitNumber(This,pVal)

#define IActCCG4QnA_put_ActConnectUnitNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActConnectUnitNumber(This,newVal)

#define IActCCG4QnA_get_ActIONumber(This,pVal)	\
    (This)->lpVtbl -> get_ActIONumber(This,pVal)

#define IActCCG4QnA_put_ActIONumber(This,newVal)	\
    (This)->lpVtbl -> put_ActIONumber(This,newVal)

#define IActCCG4QnA_get_ActCpuType(This,pVal)	\
    (This)->lpVtbl -> get_ActCpuType(This,pVal)

#define IActCCG4QnA_put_ActCpuType(This,newVal)	\
    (This)->lpVtbl -> put_ActCpuType(This,newVal)

#define IActCCG4QnA_get_ActPortNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActPortNumber(This,pVal)

#define IActCCG4QnA_put_ActPortNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActPortNumber(This,newVal)

#define IActCCG4QnA_get_ActBaudRate(This,pVal)	\
    (This)->lpVtbl -> get_ActBaudRate(This,pVal)

#define IActCCG4QnA_put_ActBaudRate(This,newVal)	\
    (This)->lpVtbl -> put_ActBaudRate(This,newVal)

#define IActCCG4QnA_get_ActControl(This,pVal)	\
    (This)->lpVtbl -> get_ActControl(This,pVal)

#define IActCCG4QnA_put_ActControl(This,newVal)	\
    (This)->lpVtbl -> put_ActControl(This,newVal)

#define IActCCG4QnA_get_ActTimeOut(This,pVal)	\
    (This)->lpVtbl -> get_ActTimeOut(This,pVal)

#define IActCCG4QnA_put_ActTimeOut(This,newVal)	\
    (This)->lpVtbl -> put_ActTimeOut(This,newVal)

#define IActCCG4QnA_GetDevice(This,szDevice,lplData,lplReturnCode)	\
    (This)->lpVtbl -> GetDevice(This,szDevice,lplData,lplReturnCode)

#define IActCCG4QnA_CheckDeviceString(This,szDevice,lCheckType,lSize,lplDeviceType,lpszDeviceName,lplDeviceNumber,lplDeviceRadix,lplReturnCode)	\
    (This)->lpVtbl -> CheckDeviceString(This,szDevice,lCheckType,lSize,lplDeviceType,lpszDeviceName,lplDeviceNumber,lplDeviceRadix,lplReturnCode)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActCCG4QnA_Open_Proxy( 
    IActCCG4QnA __RPC_FAR * This,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActCCG4QnA_Open_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActCCG4QnA_Close_Proxy( 
    IActCCG4QnA __RPC_FAR * This,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActCCG4QnA_Close_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActCCG4QnA_GetCpuType_Proxy( 
    IActCCG4QnA __RPC_FAR * This,
    /* [string][out] */ BSTR __RPC_FAR *szCpuName,
    /* [out] */ LONG __RPC_FAR *lplCpuCode,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActCCG4QnA_GetCpuType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActCCG4QnA_SetCpuStatus_Proxy( 
    IActCCG4QnA __RPC_FAR * This,
    /* [in] */ LONG lOperation,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActCCG4QnA_SetCpuStatus_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActCCG4QnA_ReadDeviceBlock_Proxy( 
    IActCCG4QnA __RPC_FAR * This,
    /* [string][in] */ BSTR szDevice,
    /* [in] */ LONG lSize,
    /* [size_is][out] */ LONG __RPC_FAR *lplData,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActCCG4QnA_ReadDeviceBlock_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActCCG4QnA_WriteDeviceBlock_Proxy( 
    IActCCG4QnA __RPC_FAR * This,
    /* [string][in] */ BSTR szDevice,
    /* [in] */ LONG lSize,
    /* [size_is][in] */ LONG __RPC_FAR *lplData,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActCCG4QnA_WriteDeviceBlock_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActCCG4QnA_ReadDeviceRandom_Proxy( 
    IActCCG4QnA __RPC_FAR * This,
    /* [string][in] */ BSTR szDeviceList,
    /* [in] */ LONG lSize,
    /* [size_is][out] */ LONG __RPC_FAR *lplData,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActCCG4QnA_ReadDeviceRandom_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActCCG4QnA_WriteDeviceRandom_Proxy( 
    IActCCG4QnA __RPC_FAR * This,
    /* [string][in] */ BSTR szDeviceList,
    /* [in] */ LONG lSize,
    /* [size_is][in] */ LONG __RPC_FAR *lplData,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActCCG4QnA_WriteDeviceRandom_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActCCG4QnA_ReadBuffer_Proxy( 
    IActCCG4QnA __RPC_FAR * This,
    /* [in] */ LONG lStartIO,
    /* [in] */ LONG lAddress,
    /* [in] */ LONG lSize,
    /* [size_is][out] */ SHORT __RPC_FAR *lpsData,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActCCG4QnA_ReadBuffer_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActCCG4QnA_WriteBuffer_Proxy( 
    IActCCG4QnA __RPC_FAR * This,
    /* [in] */ LONG lStartIO,
    /* [in] */ LONG lAddress,
    /* [in] */ LONG lSize,
    /* [size_is][in] */ SHORT __RPC_FAR *lpsData,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActCCG4QnA_WriteBuffer_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActCCG4QnA_GetClockData_Proxy( 
    IActCCG4QnA __RPC_FAR * This,
    /* [out] */ SHORT __RPC_FAR *lpsYear,
    /* [out] */ SHORT __RPC_FAR *lpsMonth,
    /* [out] */ SHORT __RPC_FAR *lpsDay,
    /* [out] */ SHORT __RPC_FAR *lpsDayOfWeek,
    /* [out] */ SHORT __RPC_FAR *lpsHour,
    /* [out] */ SHORT __RPC_FAR *lpsMinute,
    /* [out] */ SHORT __RPC_FAR *lpsSecond,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActCCG4QnA_GetClockData_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActCCG4QnA_SetClockData_Proxy( 
    IActCCG4QnA __RPC_FAR * This,
    /* [in] */ SHORT sYear,
    /* [in] */ SHORT sMonth,
    /* [in] */ SHORT sDay,
    /* [in] */ SHORT sDayOfWeek,
    /* [in] */ SHORT sHour,
    /* [in] */ SHORT sMinute,
    /* [in] */ SHORT sSecond,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActCCG4QnA_SetClockData_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActCCG4QnA_SetDevice_Proxy( 
    IActCCG4QnA __RPC_FAR * This,
    /* [string][in] */ BSTR szDevice,
    /* [in] */ LONG lData,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActCCG4QnA_SetDevice_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActCCG4QnA_get_ActNetworkNumber_Proxy( 
    IActCCG4QnA __RPC_FAR * This,
    /* [retval][out] */ LONG __RPC_FAR *pVal);


void __RPC_STUB IActCCG4QnA_get_ActNetworkNumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActCCG4QnA_put_ActNetworkNumber_Proxy( 
    IActCCG4QnA __RPC_FAR * This,
    /* [in] */ LONG newVal);


void __RPC_STUB IActCCG4QnA_put_ActNetworkNumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActCCG4QnA_get_ActStationNumber_Proxy( 
    IActCCG4QnA __RPC_FAR * This,
    /* [retval][out] */ LONG __RPC_FAR *pVal);


void __RPC_STUB IActCCG4QnA_get_ActStationNumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActCCG4QnA_put_ActStationNumber_Proxy( 
    IActCCG4QnA __RPC_FAR * This,
    /* [in] */ LONG newVal);


void __RPC_STUB IActCCG4QnA_put_ActStationNumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActCCG4QnA_get_ActUnitNumber_Proxy( 
    IActCCG4QnA __RPC_FAR * This,
    /* [retval][out] */ LONG __RPC_FAR *pVal);


void __RPC_STUB IActCCG4QnA_get_ActUnitNumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActCCG4QnA_put_ActUnitNumber_Proxy( 
    IActCCG4QnA __RPC_FAR * This,
    /* [in] */ LONG newVal);


void __RPC_STUB IActCCG4QnA_put_ActUnitNumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActCCG4QnA_get_ActConnectUnitNumber_Proxy( 
    IActCCG4QnA __RPC_FAR * This,
    /* [retval][out] */ LONG __RPC_FAR *pVal);


void __RPC_STUB IActCCG4QnA_get_ActConnectUnitNumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActCCG4QnA_put_ActConnectUnitNumber_Proxy( 
    IActCCG4QnA __RPC_FAR * This,
    /* [in] */ LONG newVal);


void __RPC_STUB IActCCG4QnA_put_ActConnectUnitNumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActCCG4QnA_get_ActIONumber_Proxy( 
    IActCCG4QnA __RPC_FAR * This,
    /* [retval][out] */ LONG __RPC_FAR *pVal);


void __RPC_STUB IActCCG4QnA_get_ActIONumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActCCG4QnA_put_ActIONumber_Proxy( 
    IActCCG4QnA __RPC_FAR * This,
    /* [in] */ LONG newVal);


void __RPC_STUB IActCCG4QnA_put_ActIONumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActCCG4QnA_get_ActCpuType_Proxy( 
    IActCCG4QnA __RPC_FAR * This,
    /* [retval][out] */ LONG __RPC_FAR *pVal);


void __RPC_STUB IActCCG4QnA_get_ActCpuType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActCCG4QnA_put_ActCpuType_Proxy( 
    IActCCG4QnA __RPC_FAR * This,
    /* [in] */ LONG newVal);


void __RPC_STUB IActCCG4QnA_put_ActCpuType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActCCG4QnA_get_ActPortNumber_Proxy( 
    IActCCG4QnA __RPC_FAR * This,
    /* [retval][out] */ LONG __RPC_FAR *pVal);


void __RPC_STUB IActCCG4QnA_get_ActPortNumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActCCG4QnA_put_ActPortNumber_Proxy( 
    IActCCG4QnA __RPC_FAR * This,
    /* [in] */ LONG newVal);


void __RPC_STUB IActCCG4QnA_put_ActPortNumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActCCG4QnA_get_ActBaudRate_Proxy( 
    IActCCG4QnA __RPC_FAR * This,
    /* [retval][out] */ LONG __RPC_FAR *pVal);


void __RPC_STUB IActCCG4QnA_get_ActBaudRate_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActCCG4QnA_put_ActBaudRate_Proxy( 
    IActCCG4QnA __RPC_FAR * This,
    /* [in] */ LONG newVal);


void __RPC_STUB IActCCG4QnA_put_ActBaudRate_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActCCG4QnA_get_ActControl_Proxy( 
    IActCCG4QnA __RPC_FAR * This,
    /* [retval][out] */ LONG __RPC_FAR *pVal);


void __RPC_STUB IActCCG4QnA_get_ActControl_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActCCG4QnA_put_ActControl_Proxy( 
    IActCCG4QnA __RPC_FAR * This,
    /* [in] */ LONG newVal);


void __RPC_STUB IActCCG4QnA_put_ActControl_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActCCG4QnA_get_ActTimeOut_Proxy( 
    IActCCG4QnA __RPC_FAR * This,
    /* [retval][out] */ LONG __RPC_FAR *pVal);


void __RPC_STUB IActCCG4QnA_get_ActTimeOut_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActCCG4QnA_put_ActTimeOut_Proxy( 
    IActCCG4QnA __RPC_FAR * This,
    /* [in] */ LONG newVal);


void __RPC_STUB IActCCG4QnA_put_ActTimeOut_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActCCG4QnA_GetDevice_Proxy( 
    IActCCG4QnA __RPC_FAR * This,
    /* [string][in] */ BSTR szDevice,
    /* [out] */ LONG __RPC_FAR *lplData,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActCCG4QnA_GetDevice_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActCCG4QnA_CheckDeviceString_Proxy( 
    IActCCG4QnA __RPC_FAR * This,
    /* [in] */ BSTR szDevice,
    /* [in] */ LONG lCheckType,
    /* [in] */ LONG lSize,
    /* [out] */ LONG __RPC_FAR *lplDeviceType,
    /* [string][out] */ BSTR __RPC_FAR *lpszDeviceName,
    /* [out] */ LONG __RPC_FAR *lplDeviceNumber,
    /* [out] */ LONG __RPC_FAR *lplDeviceRadix,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActCCG4QnA_CheckDeviceString_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IActCCG4QnA_INTERFACE_DEFINED__ */


#ifndef __IActCCG4QnA2_INTERFACE_DEFINED__
#define __IActCCG4QnA2_INTERFACE_DEFINED__

/* interface IActCCG4QnA2 */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IActCCG4QnA2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("8E29CCC0-C6A6-11d4-8741-00E0292A4FB4")
    IActCCG4QnA2 : public IActCCG4QnA
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

    typedef struct IActCCG4QnA2Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IActCCG4QnA2 __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IActCCG4QnA2 __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IActCCG4QnA2 __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IActCCG4QnA2 __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IActCCG4QnA2 __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IActCCG4QnA2 __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IActCCG4QnA2 __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Open )( 
            IActCCG4QnA2 __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Close )( 
            IActCCG4QnA2 __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetCpuType )( 
            IActCCG4QnA2 __RPC_FAR * This,
            /* [string][out] */ BSTR __RPC_FAR *szCpuName,
            /* [out] */ LONG __RPC_FAR *lplCpuCode,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetCpuStatus )( 
            IActCCG4QnA2 __RPC_FAR * This,
            /* [in] */ LONG lOperation,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceBlock )( 
            IActCCG4QnA2 __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lSize,
            /* [size_is][out] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceBlock )( 
            IActCCG4QnA2 __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lSize,
            /* [size_is][in] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceRandom )( 
            IActCCG4QnA2 __RPC_FAR * This,
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG lSize,
            /* [size_is][out] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceRandom )( 
            IActCCG4QnA2 __RPC_FAR * This,
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG lSize,
            /* [size_is][in] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadBuffer )( 
            IActCCG4QnA2 __RPC_FAR * This,
            /* [in] */ LONG lStartIO,
            /* [in] */ LONG lAddress,
            /* [in] */ LONG lSize,
            /* [size_is][out] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteBuffer )( 
            IActCCG4QnA2 __RPC_FAR * This,
            /* [in] */ LONG lStartIO,
            /* [in] */ LONG lAddress,
            /* [in] */ LONG lSize,
            /* [size_is][in] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetClockData )( 
            IActCCG4QnA2 __RPC_FAR * This,
            /* [out] */ SHORT __RPC_FAR *lpsYear,
            /* [out] */ SHORT __RPC_FAR *lpsMonth,
            /* [out] */ SHORT __RPC_FAR *lpsDay,
            /* [out] */ SHORT __RPC_FAR *lpsDayOfWeek,
            /* [out] */ SHORT __RPC_FAR *lpsHour,
            /* [out] */ SHORT __RPC_FAR *lpsMinute,
            /* [out] */ SHORT __RPC_FAR *lpsSecond,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetClockData )( 
            IActCCG4QnA2 __RPC_FAR * This,
            /* [in] */ SHORT sYear,
            /* [in] */ SHORT sMonth,
            /* [in] */ SHORT sDay,
            /* [in] */ SHORT sDayOfWeek,
            /* [in] */ SHORT sHour,
            /* [in] */ SHORT sMinute,
            /* [in] */ SHORT sSecond,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetDevice )( 
            IActCCG4QnA2 __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActNetworkNumber )( 
            IActCCG4QnA2 __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActNetworkNumber )( 
            IActCCG4QnA2 __RPC_FAR * This,
            /* [in] */ LONG newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActStationNumber )( 
            IActCCG4QnA2 __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActStationNumber )( 
            IActCCG4QnA2 __RPC_FAR * This,
            /* [in] */ LONG newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActUnitNumber )( 
            IActCCG4QnA2 __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActUnitNumber )( 
            IActCCG4QnA2 __RPC_FAR * This,
            /* [in] */ LONG newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActConnectUnitNumber )( 
            IActCCG4QnA2 __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActConnectUnitNumber )( 
            IActCCG4QnA2 __RPC_FAR * This,
            /* [in] */ LONG newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActIONumber )( 
            IActCCG4QnA2 __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActIONumber )( 
            IActCCG4QnA2 __RPC_FAR * This,
            /* [in] */ LONG newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActCpuType )( 
            IActCCG4QnA2 __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActCpuType )( 
            IActCCG4QnA2 __RPC_FAR * This,
            /* [in] */ LONG newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActPortNumber )( 
            IActCCG4QnA2 __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActPortNumber )( 
            IActCCG4QnA2 __RPC_FAR * This,
            /* [in] */ LONG newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActBaudRate )( 
            IActCCG4QnA2 __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActBaudRate )( 
            IActCCG4QnA2 __RPC_FAR * This,
            /* [in] */ LONG newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActControl )( 
            IActCCG4QnA2 __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActControl )( 
            IActCCG4QnA2 __RPC_FAR * This,
            /* [in] */ LONG newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActTimeOut )( 
            IActCCG4QnA2 __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActTimeOut )( 
            IActCCG4QnA2 __RPC_FAR * This,
            /* [in] */ LONG newVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetDevice )( 
            IActCCG4QnA2 __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [out] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CheckDeviceString )( 
            IActCCG4QnA2 __RPC_FAR * This,
            /* [in] */ BSTR szDevice,
            /* [in] */ LONG lCheckType,
            /* [in] */ LONG lSize,
            /* [out] */ LONG __RPC_FAR *lplDeviceType,
            /* [string][out] */ BSTR __RPC_FAR *lpszDeviceName,
            /* [out] */ LONG __RPC_FAR *lplDeviceNumber,
            /* [out] */ LONG __RPC_FAR *lplDeviceRadix,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *EntryDeviceStatus )( 
            IActCCG4QnA2 __RPC_FAR * This,
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG lSize,
            /* [in] */ LONG lMonitorCycle,
            /* [size_is][in] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *FreeDeviceStatus )( 
            IActCCG4QnA2 __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        END_INTERFACE
    } IActCCG4QnA2Vtbl;

    interface IActCCG4QnA2
    {
        CONST_VTBL struct IActCCG4QnA2Vtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IActCCG4QnA2_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IActCCG4QnA2_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IActCCG4QnA2_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IActCCG4QnA2_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IActCCG4QnA2_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IActCCG4QnA2_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IActCCG4QnA2_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IActCCG4QnA2_Open(This,lplReturnCode)	\
    (This)->lpVtbl -> Open(This,lplReturnCode)

#define IActCCG4QnA2_Close(This,lplReturnCode)	\
    (This)->lpVtbl -> Close(This,lplReturnCode)

#define IActCCG4QnA2_GetCpuType(This,szCpuName,lplCpuCode,lplReturnCode)	\
    (This)->lpVtbl -> GetCpuType(This,szCpuName,lplCpuCode,lplReturnCode)

#define IActCCG4QnA2_SetCpuStatus(This,lOperation,lplReturnCode)	\
    (This)->lpVtbl -> SetCpuStatus(This,lOperation,lplReturnCode)

#define IActCCG4QnA2_ReadDeviceBlock(This,szDevice,lSize,lplData,lplReturnCode)	\
    (This)->lpVtbl -> ReadDeviceBlock(This,szDevice,lSize,lplData,lplReturnCode)

#define IActCCG4QnA2_WriteDeviceBlock(This,szDevice,lSize,lplData,lplReturnCode)	\
    (This)->lpVtbl -> WriteDeviceBlock(This,szDevice,lSize,lplData,lplReturnCode)

#define IActCCG4QnA2_ReadDeviceRandom(This,szDeviceList,lSize,lplData,lplReturnCode)	\
    (This)->lpVtbl -> ReadDeviceRandom(This,szDeviceList,lSize,lplData,lplReturnCode)

#define IActCCG4QnA2_WriteDeviceRandom(This,szDeviceList,lSize,lplData,lplReturnCode)	\
    (This)->lpVtbl -> WriteDeviceRandom(This,szDeviceList,lSize,lplData,lplReturnCode)

#define IActCCG4QnA2_ReadBuffer(This,lStartIO,lAddress,lSize,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> ReadBuffer(This,lStartIO,lAddress,lSize,lpsData,lplReturnCode)

#define IActCCG4QnA2_WriteBuffer(This,lStartIO,lAddress,lSize,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> WriteBuffer(This,lStartIO,lAddress,lSize,lpsData,lplReturnCode)

#define IActCCG4QnA2_GetClockData(This,lpsYear,lpsMonth,lpsDay,lpsDayOfWeek,lpsHour,lpsMinute,lpsSecond,lplReturnCode)	\
    (This)->lpVtbl -> GetClockData(This,lpsYear,lpsMonth,lpsDay,lpsDayOfWeek,lpsHour,lpsMinute,lpsSecond,lplReturnCode)

#define IActCCG4QnA2_SetClockData(This,sYear,sMonth,sDay,sDayOfWeek,sHour,sMinute,sSecond,lplReturnCode)	\
    (This)->lpVtbl -> SetClockData(This,sYear,sMonth,sDay,sDayOfWeek,sHour,sMinute,sSecond,lplReturnCode)

#define IActCCG4QnA2_SetDevice(This,szDevice,lData,lplReturnCode)	\
    (This)->lpVtbl -> SetDevice(This,szDevice,lData,lplReturnCode)

#define IActCCG4QnA2_get_ActNetworkNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActNetworkNumber(This,pVal)

#define IActCCG4QnA2_put_ActNetworkNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActNetworkNumber(This,newVal)

#define IActCCG4QnA2_get_ActStationNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActStationNumber(This,pVal)

#define IActCCG4QnA2_put_ActStationNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActStationNumber(This,newVal)

#define IActCCG4QnA2_get_ActUnitNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActUnitNumber(This,pVal)

#define IActCCG4QnA2_put_ActUnitNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActUnitNumber(This,newVal)

#define IActCCG4QnA2_get_ActConnectUnitNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActConnectUnitNumber(This,pVal)

#define IActCCG4QnA2_put_ActConnectUnitNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActConnectUnitNumber(This,newVal)

#define IActCCG4QnA2_get_ActIONumber(This,pVal)	\
    (This)->lpVtbl -> get_ActIONumber(This,pVal)

#define IActCCG4QnA2_put_ActIONumber(This,newVal)	\
    (This)->lpVtbl -> put_ActIONumber(This,newVal)

#define IActCCG4QnA2_get_ActCpuType(This,pVal)	\
    (This)->lpVtbl -> get_ActCpuType(This,pVal)

#define IActCCG4QnA2_put_ActCpuType(This,newVal)	\
    (This)->lpVtbl -> put_ActCpuType(This,newVal)

#define IActCCG4QnA2_get_ActPortNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActPortNumber(This,pVal)

#define IActCCG4QnA2_put_ActPortNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActPortNumber(This,newVal)

#define IActCCG4QnA2_get_ActBaudRate(This,pVal)	\
    (This)->lpVtbl -> get_ActBaudRate(This,pVal)

#define IActCCG4QnA2_put_ActBaudRate(This,newVal)	\
    (This)->lpVtbl -> put_ActBaudRate(This,newVal)

#define IActCCG4QnA2_get_ActControl(This,pVal)	\
    (This)->lpVtbl -> get_ActControl(This,pVal)

#define IActCCG4QnA2_put_ActControl(This,newVal)	\
    (This)->lpVtbl -> put_ActControl(This,newVal)

#define IActCCG4QnA2_get_ActTimeOut(This,pVal)	\
    (This)->lpVtbl -> get_ActTimeOut(This,pVal)

#define IActCCG4QnA2_put_ActTimeOut(This,newVal)	\
    (This)->lpVtbl -> put_ActTimeOut(This,newVal)

#define IActCCG4QnA2_GetDevice(This,szDevice,lplData,lplReturnCode)	\
    (This)->lpVtbl -> GetDevice(This,szDevice,lplData,lplReturnCode)

#define IActCCG4QnA2_CheckDeviceString(This,szDevice,lCheckType,lSize,lplDeviceType,lpszDeviceName,lplDeviceNumber,lplDeviceRadix,lplReturnCode)	\
    (This)->lpVtbl -> CheckDeviceString(This,szDevice,lCheckType,lSize,lplDeviceType,lpszDeviceName,lplDeviceNumber,lplDeviceRadix,lplReturnCode)


#define IActCCG4QnA2_EntryDeviceStatus(This,szDeviceList,lSize,lMonitorCycle,lplData,lplReturnCode)	\
    (This)->lpVtbl -> EntryDeviceStatus(This,szDeviceList,lSize,lMonitorCycle,lplData,lplReturnCode)

#define IActCCG4QnA2_FreeDeviceStatus(This,lplReturnCode)	\
    (This)->lpVtbl -> FreeDeviceStatus(This,lplReturnCode)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActCCG4QnA2_EntryDeviceStatus_Proxy( 
    IActCCG4QnA2 __RPC_FAR * This,
    /* [string][in] */ BSTR szDeviceList,
    /* [in] */ LONG lSize,
    /* [in] */ LONG lMonitorCycle,
    /* [size_is][in] */ LONG __RPC_FAR *lplData,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActCCG4QnA2_EntryDeviceStatus_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActCCG4QnA2_FreeDeviceStatus_Proxy( 
    IActCCG4QnA2 __RPC_FAR * This,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActCCG4QnA2_FreeDeviceStatus_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IActCCG4QnA2_INTERFACE_DEFINED__ */


#ifndef __IActCCG4QnA3_INTERFACE_DEFINED__
#define __IActCCG4QnA3_INTERFACE_DEFINED__

/* interface IActCCG4QnA3 */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IActCCG4QnA3;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("115992F5-6EC2-11d5-9314-009099244EFD")
    IActCCG4QnA3 : public IActCCG4QnA2
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

    typedef struct IActCCG4QnA3Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IActCCG4QnA3 __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IActCCG4QnA3 __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IActCCG4QnA3 __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IActCCG4QnA3 __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IActCCG4QnA3 __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IActCCG4QnA3 __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IActCCG4QnA3 __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Open )( 
            IActCCG4QnA3 __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Close )( 
            IActCCG4QnA3 __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetCpuType )( 
            IActCCG4QnA3 __RPC_FAR * This,
            /* [string][out] */ BSTR __RPC_FAR *szCpuName,
            /* [out] */ LONG __RPC_FAR *lplCpuCode,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetCpuStatus )( 
            IActCCG4QnA3 __RPC_FAR * This,
            /* [in] */ LONG lOperation,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceBlock )( 
            IActCCG4QnA3 __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lSize,
            /* [size_is][out] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceBlock )( 
            IActCCG4QnA3 __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lSize,
            /* [size_is][in] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceRandom )( 
            IActCCG4QnA3 __RPC_FAR * This,
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG lSize,
            /* [size_is][out] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceRandom )( 
            IActCCG4QnA3 __RPC_FAR * This,
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG lSize,
            /* [size_is][in] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadBuffer )( 
            IActCCG4QnA3 __RPC_FAR * This,
            /* [in] */ LONG lStartIO,
            /* [in] */ LONG lAddress,
            /* [in] */ LONG lSize,
            /* [size_is][out] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteBuffer )( 
            IActCCG4QnA3 __RPC_FAR * This,
            /* [in] */ LONG lStartIO,
            /* [in] */ LONG lAddress,
            /* [in] */ LONG lSize,
            /* [size_is][in] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetClockData )( 
            IActCCG4QnA3 __RPC_FAR * This,
            /* [out] */ SHORT __RPC_FAR *lpsYear,
            /* [out] */ SHORT __RPC_FAR *lpsMonth,
            /* [out] */ SHORT __RPC_FAR *lpsDay,
            /* [out] */ SHORT __RPC_FAR *lpsDayOfWeek,
            /* [out] */ SHORT __RPC_FAR *lpsHour,
            /* [out] */ SHORT __RPC_FAR *lpsMinute,
            /* [out] */ SHORT __RPC_FAR *lpsSecond,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetClockData )( 
            IActCCG4QnA3 __RPC_FAR * This,
            /* [in] */ SHORT sYear,
            /* [in] */ SHORT sMonth,
            /* [in] */ SHORT sDay,
            /* [in] */ SHORT sDayOfWeek,
            /* [in] */ SHORT sHour,
            /* [in] */ SHORT sMinute,
            /* [in] */ SHORT sSecond,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetDevice )( 
            IActCCG4QnA3 __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActNetworkNumber )( 
            IActCCG4QnA3 __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActNetworkNumber )( 
            IActCCG4QnA3 __RPC_FAR * This,
            /* [in] */ LONG newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActStationNumber )( 
            IActCCG4QnA3 __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActStationNumber )( 
            IActCCG4QnA3 __RPC_FAR * This,
            /* [in] */ LONG newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActUnitNumber )( 
            IActCCG4QnA3 __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActUnitNumber )( 
            IActCCG4QnA3 __RPC_FAR * This,
            /* [in] */ LONG newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActConnectUnitNumber )( 
            IActCCG4QnA3 __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActConnectUnitNumber )( 
            IActCCG4QnA3 __RPC_FAR * This,
            /* [in] */ LONG newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActIONumber )( 
            IActCCG4QnA3 __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActIONumber )( 
            IActCCG4QnA3 __RPC_FAR * This,
            /* [in] */ LONG newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActCpuType )( 
            IActCCG4QnA3 __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActCpuType )( 
            IActCCG4QnA3 __RPC_FAR * This,
            /* [in] */ LONG newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActPortNumber )( 
            IActCCG4QnA3 __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActPortNumber )( 
            IActCCG4QnA3 __RPC_FAR * This,
            /* [in] */ LONG newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActBaudRate )( 
            IActCCG4QnA3 __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActBaudRate )( 
            IActCCG4QnA3 __RPC_FAR * This,
            /* [in] */ LONG newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActControl )( 
            IActCCG4QnA3 __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActControl )( 
            IActCCG4QnA3 __RPC_FAR * This,
            /* [in] */ LONG newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActTimeOut )( 
            IActCCG4QnA3 __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActTimeOut )( 
            IActCCG4QnA3 __RPC_FAR * This,
            /* [in] */ LONG newVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetDevice )( 
            IActCCG4QnA3 __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [out] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CheckDeviceString )( 
            IActCCG4QnA3 __RPC_FAR * This,
            /* [in] */ BSTR szDevice,
            /* [in] */ LONG lCheckType,
            /* [in] */ LONG lSize,
            /* [out] */ LONG __RPC_FAR *lplDeviceType,
            /* [string][out] */ BSTR __RPC_FAR *lpszDeviceName,
            /* [out] */ LONG __RPC_FAR *lplDeviceNumber,
            /* [out] */ LONG __RPC_FAR *lplDeviceRadix,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *EntryDeviceStatus )( 
            IActCCG4QnA3 __RPC_FAR * This,
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG lSize,
            /* [in] */ LONG lMonitorCycle,
            /* [size_is][in] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *FreeDeviceStatus )( 
            IActCCG4QnA3 __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceBlock2 )( 
            IActCCG4QnA3 __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lSize,
            /* [size_is][out] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceBlock2 )( 
            IActCCG4QnA3 __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lSize,
            /* [size_is][in] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceRandom2 )( 
            IActCCG4QnA3 __RPC_FAR * This,
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG lSize,
            /* [size_is][out] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceRandom2 )( 
            IActCCG4QnA3 __RPC_FAR * This,
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG lSize,
            /* [size_is][in] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetDevice2 )( 
            IActCCG4QnA3 __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [out] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetDevice2 )( 
            IActCCG4QnA3 __RPC_FAR * This,
            /* [in] */ BSTR szDevice,
            /* [in] */ SHORT sData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        END_INTERFACE
    } IActCCG4QnA3Vtbl;

    interface IActCCG4QnA3
    {
        CONST_VTBL struct IActCCG4QnA3Vtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IActCCG4QnA3_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IActCCG4QnA3_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IActCCG4QnA3_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IActCCG4QnA3_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IActCCG4QnA3_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IActCCG4QnA3_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IActCCG4QnA3_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IActCCG4QnA3_Open(This,lplReturnCode)	\
    (This)->lpVtbl -> Open(This,lplReturnCode)

#define IActCCG4QnA3_Close(This,lplReturnCode)	\
    (This)->lpVtbl -> Close(This,lplReturnCode)

#define IActCCG4QnA3_GetCpuType(This,szCpuName,lplCpuCode,lplReturnCode)	\
    (This)->lpVtbl -> GetCpuType(This,szCpuName,lplCpuCode,lplReturnCode)

#define IActCCG4QnA3_SetCpuStatus(This,lOperation,lplReturnCode)	\
    (This)->lpVtbl -> SetCpuStatus(This,lOperation,lplReturnCode)

#define IActCCG4QnA3_ReadDeviceBlock(This,szDevice,lSize,lplData,lplReturnCode)	\
    (This)->lpVtbl -> ReadDeviceBlock(This,szDevice,lSize,lplData,lplReturnCode)

#define IActCCG4QnA3_WriteDeviceBlock(This,szDevice,lSize,lplData,lplReturnCode)	\
    (This)->lpVtbl -> WriteDeviceBlock(This,szDevice,lSize,lplData,lplReturnCode)

#define IActCCG4QnA3_ReadDeviceRandom(This,szDeviceList,lSize,lplData,lplReturnCode)	\
    (This)->lpVtbl -> ReadDeviceRandom(This,szDeviceList,lSize,lplData,lplReturnCode)

#define IActCCG4QnA3_WriteDeviceRandom(This,szDeviceList,lSize,lplData,lplReturnCode)	\
    (This)->lpVtbl -> WriteDeviceRandom(This,szDeviceList,lSize,lplData,lplReturnCode)

#define IActCCG4QnA3_ReadBuffer(This,lStartIO,lAddress,lSize,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> ReadBuffer(This,lStartIO,lAddress,lSize,lpsData,lplReturnCode)

#define IActCCG4QnA3_WriteBuffer(This,lStartIO,lAddress,lSize,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> WriteBuffer(This,lStartIO,lAddress,lSize,lpsData,lplReturnCode)

#define IActCCG4QnA3_GetClockData(This,lpsYear,lpsMonth,lpsDay,lpsDayOfWeek,lpsHour,lpsMinute,lpsSecond,lplReturnCode)	\
    (This)->lpVtbl -> GetClockData(This,lpsYear,lpsMonth,lpsDay,lpsDayOfWeek,lpsHour,lpsMinute,lpsSecond,lplReturnCode)

#define IActCCG4QnA3_SetClockData(This,sYear,sMonth,sDay,sDayOfWeek,sHour,sMinute,sSecond,lplReturnCode)	\
    (This)->lpVtbl -> SetClockData(This,sYear,sMonth,sDay,sDayOfWeek,sHour,sMinute,sSecond,lplReturnCode)

#define IActCCG4QnA3_SetDevice(This,szDevice,lData,lplReturnCode)	\
    (This)->lpVtbl -> SetDevice(This,szDevice,lData,lplReturnCode)

#define IActCCG4QnA3_get_ActNetworkNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActNetworkNumber(This,pVal)

#define IActCCG4QnA3_put_ActNetworkNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActNetworkNumber(This,newVal)

#define IActCCG4QnA3_get_ActStationNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActStationNumber(This,pVal)

#define IActCCG4QnA3_put_ActStationNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActStationNumber(This,newVal)

#define IActCCG4QnA3_get_ActUnitNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActUnitNumber(This,pVal)

#define IActCCG4QnA3_put_ActUnitNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActUnitNumber(This,newVal)

#define IActCCG4QnA3_get_ActConnectUnitNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActConnectUnitNumber(This,pVal)

#define IActCCG4QnA3_put_ActConnectUnitNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActConnectUnitNumber(This,newVal)

#define IActCCG4QnA3_get_ActIONumber(This,pVal)	\
    (This)->lpVtbl -> get_ActIONumber(This,pVal)

#define IActCCG4QnA3_put_ActIONumber(This,newVal)	\
    (This)->lpVtbl -> put_ActIONumber(This,newVal)

#define IActCCG4QnA3_get_ActCpuType(This,pVal)	\
    (This)->lpVtbl -> get_ActCpuType(This,pVal)

#define IActCCG4QnA3_put_ActCpuType(This,newVal)	\
    (This)->lpVtbl -> put_ActCpuType(This,newVal)

#define IActCCG4QnA3_get_ActPortNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActPortNumber(This,pVal)

#define IActCCG4QnA3_put_ActPortNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActPortNumber(This,newVal)

#define IActCCG4QnA3_get_ActBaudRate(This,pVal)	\
    (This)->lpVtbl -> get_ActBaudRate(This,pVal)

#define IActCCG4QnA3_put_ActBaudRate(This,newVal)	\
    (This)->lpVtbl -> put_ActBaudRate(This,newVal)

#define IActCCG4QnA3_get_ActControl(This,pVal)	\
    (This)->lpVtbl -> get_ActControl(This,pVal)

#define IActCCG4QnA3_put_ActControl(This,newVal)	\
    (This)->lpVtbl -> put_ActControl(This,newVal)

#define IActCCG4QnA3_get_ActTimeOut(This,pVal)	\
    (This)->lpVtbl -> get_ActTimeOut(This,pVal)

#define IActCCG4QnA3_put_ActTimeOut(This,newVal)	\
    (This)->lpVtbl -> put_ActTimeOut(This,newVal)

#define IActCCG4QnA3_GetDevice(This,szDevice,lplData,lplReturnCode)	\
    (This)->lpVtbl -> GetDevice(This,szDevice,lplData,lplReturnCode)

#define IActCCG4QnA3_CheckDeviceString(This,szDevice,lCheckType,lSize,lplDeviceType,lpszDeviceName,lplDeviceNumber,lplDeviceRadix,lplReturnCode)	\
    (This)->lpVtbl -> CheckDeviceString(This,szDevice,lCheckType,lSize,lplDeviceType,lpszDeviceName,lplDeviceNumber,lplDeviceRadix,lplReturnCode)


#define IActCCG4QnA3_EntryDeviceStatus(This,szDeviceList,lSize,lMonitorCycle,lplData,lplReturnCode)	\
    (This)->lpVtbl -> EntryDeviceStatus(This,szDeviceList,lSize,lMonitorCycle,lplData,lplReturnCode)

#define IActCCG4QnA3_FreeDeviceStatus(This,lplReturnCode)	\
    (This)->lpVtbl -> FreeDeviceStatus(This,lplReturnCode)


#define IActCCG4QnA3_ReadDeviceBlock2(This,szDevice,lSize,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> ReadDeviceBlock2(This,szDevice,lSize,lpsData,lplReturnCode)

#define IActCCG4QnA3_WriteDeviceBlock2(This,szDevice,lSize,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> WriteDeviceBlock2(This,szDevice,lSize,lpsData,lplReturnCode)

#define IActCCG4QnA3_ReadDeviceRandom2(This,szDeviceList,lSize,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> ReadDeviceRandom2(This,szDeviceList,lSize,lpsData,lplReturnCode)

#define IActCCG4QnA3_WriteDeviceRandom2(This,szDeviceList,lSize,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> WriteDeviceRandom2(This,szDeviceList,lSize,lpsData,lplReturnCode)

#define IActCCG4QnA3_GetDevice2(This,szDevice,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> GetDevice2(This,szDevice,lpsData,lplReturnCode)

#define IActCCG4QnA3_SetDevice2(This,szDevice,sData,lplReturnCode)	\
    (This)->lpVtbl -> SetDevice2(This,szDevice,sData,lplReturnCode)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActCCG4QnA3_ReadDeviceBlock2_Proxy( 
    IActCCG4QnA3 __RPC_FAR * This,
    /* [string][in] */ BSTR szDevice,
    /* [in] */ LONG lSize,
    /* [size_is][out] */ SHORT __RPC_FAR *lpsData,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActCCG4QnA3_ReadDeviceBlock2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActCCG4QnA3_WriteDeviceBlock2_Proxy( 
    IActCCG4QnA3 __RPC_FAR * This,
    /* [string][in] */ BSTR szDevice,
    /* [in] */ LONG lSize,
    /* [size_is][in] */ SHORT __RPC_FAR *lpsData,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActCCG4QnA3_WriteDeviceBlock2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActCCG4QnA3_ReadDeviceRandom2_Proxy( 
    IActCCG4QnA3 __RPC_FAR * This,
    /* [string][in] */ BSTR szDeviceList,
    /* [in] */ LONG lSize,
    /* [size_is][out] */ SHORT __RPC_FAR *lpsData,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActCCG4QnA3_ReadDeviceRandom2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActCCG4QnA3_WriteDeviceRandom2_Proxy( 
    IActCCG4QnA3 __RPC_FAR * This,
    /* [string][in] */ BSTR szDeviceList,
    /* [in] */ LONG lSize,
    /* [size_is][in] */ SHORT __RPC_FAR *lpsData,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActCCG4QnA3_WriteDeviceRandom2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActCCG4QnA3_GetDevice2_Proxy( 
    IActCCG4QnA3 __RPC_FAR * This,
    /* [string][in] */ BSTR szDevice,
    /* [out] */ SHORT __RPC_FAR *lpsData,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActCCG4QnA3_GetDevice2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActCCG4QnA3_SetDevice2_Proxy( 
    IActCCG4QnA3 __RPC_FAR * This,
    /* [in] */ BSTR szDevice,
    /* [in] */ SHORT sData,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActCCG4QnA3_SetDevice2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IActCCG4QnA3_INTERFACE_DEFINED__ */


#ifndef __IActCCG4A_INTERFACE_DEFINED__
#define __IActCCG4A_INTERFACE_DEFINED__

/* interface IActCCG4A */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IActCCG4A;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("8215E4F4-AE9D-11D3-83AE-00A024BDBF2B")
    IActCCG4A : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Open( 
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Close( 
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetCpuType( 
            /* [string][out] */ BSTR __RPC_FAR *szCpuName,
            /* [out] */ LONG __RPC_FAR *lplCpuCode,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetCpuStatus( 
            /* [in] */ LONG lOperation,
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
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetDevice( 
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActStationNumber( 
            /* [retval][out] */ LONG __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActStationNumber( 
            /* [in] */ LONG newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActCpuType( 
            /* [retval][out] */ LONG __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActCpuType( 
            /* [in] */ LONG newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActPortNumber( 
            /* [retval][out] */ LONG __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActPortNumber( 
            /* [in] */ LONG newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActControl( 
            /* [retval][out] */ LONG __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActControl( 
            /* [in] */ LONG newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActTimeOut( 
            /* [retval][out] */ LONG __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActTimeOut( 
            /* [in] */ LONG newVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetDevice( 
            /* [string][in] */ BSTR szDevice,
            /* [out] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplRetrunCode) = 0;
        
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

    typedef struct IActCCG4AVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IActCCG4A __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IActCCG4A __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IActCCG4A __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IActCCG4A __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IActCCG4A __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IActCCG4A __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IActCCG4A __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Open )( 
            IActCCG4A __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Close )( 
            IActCCG4A __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetCpuType )( 
            IActCCG4A __RPC_FAR * This,
            /* [string][out] */ BSTR __RPC_FAR *szCpuName,
            /* [out] */ LONG __RPC_FAR *lplCpuCode,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetCpuStatus )( 
            IActCCG4A __RPC_FAR * This,
            /* [in] */ LONG lOperation,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceBlock )( 
            IActCCG4A __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lSize,
            /* [size_is][out] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceBlock )( 
            IActCCG4A __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lSize,
            /* [size_is][in] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceRandom )( 
            IActCCG4A __RPC_FAR * This,
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG lSize,
            /* [size_is][out] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceRandom )( 
            IActCCG4A __RPC_FAR * This,
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG lSize,
            /* [size_is][in] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadBuffer )( 
            IActCCG4A __RPC_FAR * This,
            /* [in] */ LONG lStartIO,
            /* [in] */ LONG lAddress,
            /* [in] */ LONG lSize,
            /* [size_is][out] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteBuffer )( 
            IActCCG4A __RPC_FAR * This,
            /* [in] */ LONG lStartIO,
            /* [in] */ LONG lAddress,
            /* [in] */ LONG lSize,
            /* [size_is][in] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetClockData )( 
            IActCCG4A __RPC_FAR * This,
            /* [out] */ SHORT __RPC_FAR *lpsYear,
            /* [out] */ SHORT __RPC_FAR *lpsMonth,
            /* [out] */ SHORT __RPC_FAR *lpsDay,
            /* [out] */ SHORT __RPC_FAR *lpsDayOfWeek,
            /* [out] */ SHORT __RPC_FAR *lpsHour,
            /* [out] */ SHORT __RPC_FAR *lpsMinute,
            /* [out] */ SHORT __RPC_FAR *lpsSecond,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetClockData )( 
            IActCCG4A __RPC_FAR * This,
            /* [in] */ SHORT sYear,
            /* [in] */ SHORT sMonth,
            /* [in] */ SHORT sDay,
            /* [in] */ SHORT sDayOfWeek,
            /* [in] */ SHORT sHour,
            /* [in] */ SHORT sMinute,
            /* [in] */ SHORT sSecond,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetDevice )( 
            IActCCG4A __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActStationNumber )( 
            IActCCG4A __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActStationNumber )( 
            IActCCG4A __RPC_FAR * This,
            /* [in] */ LONG newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActCpuType )( 
            IActCCG4A __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActCpuType )( 
            IActCCG4A __RPC_FAR * This,
            /* [in] */ LONG newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActPortNumber )( 
            IActCCG4A __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActPortNumber )( 
            IActCCG4A __RPC_FAR * This,
            /* [in] */ LONG newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActControl )( 
            IActCCG4A __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActControl )( 
            IActCCG4A __RPC_FAR * This,
            /* [in] */ LONG newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActTimeOut )( 
            IActCCG4A __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActTimeOut )( 
            IActCCG4A __RPC_FAR * This,
            /* [in] */ LONG newVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetDevice )( 
            IActCCG4A __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [out] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplRetrunCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CheckDeviceString )( 
            IActCCG4A __RPC_FAR * This,
            /* [in] */ BSTR szDevice,
            /* [in] */ LONG lCheckType,
            /* [in] */ LONG lSize,
            /* [out] */ LONG __RPC_FAR *lplDeviceType,
            /* [string][out] */ BSTR __RPC_FAR *lpszDeviceName,
            /* [out] */ LONG __RPC_FAR *lplDeviceNumber,
            /* [out] */ LONG __RPC_FAR *lplDeviceRadix,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        END_INTERFACE
    } IActCCG4AVtbl;

    interface IActCCG4A
    {
        CONST_VTBL struct IActCCG4AVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IActCCG4A_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IActCCG4A_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IActCCG4A_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IActCCG4A_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IActCCG4A_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IActCCG4A_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IActCCG4A_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IActCCG4A_Open(This,lplReturnCode)	\
    (This)->lpVtbl -> Open(This,lplReturnCode)

#define IActCCG4A_Close(This,lplReturnCode)	\
    (This)->lpVtbl -> Close(This,lplReturnCode)

#define IActCCG4A_GetCpuType(This,szCpuName,lplCpuCode,lplReturnCode)	\
    (This)->lpVtbl -> GetCpuType(This,szCpuName,lplCpuCode,lplReturnCode)

#define IActCCG4A_SetCpuStatus(This,lOperation,lplReturnCode)	\
    (This)->lpVtbl -> SetCpuStatus(This,lOperation,lplReturnCode)

#define IActCCG4A_ReadDeviceBlock(This,szDevice,lSize,lplData,lplReturnCode)	\
    (This)->lpVtbl -> ReadDeviceBlock(This,szDevice,lSize,lplData,lplReturnCode)

#define IActCCG4A_WriteDeviceBlock(This,szDevice,lSize,lplData,lplReturnCode)	\
    (This)->lpVtbl -> WriteDeviceBlock(This,szDevice,lSize,lplData,lplReturnCode)

#define IActCCG4A_ReadDeviceRandom(This,szDeviceList,lSize,lplData,lplReturnCode)	\
    (This)->lpVtbl -> ReadDeviceRandom(This,szDeviceList,lSize,lplData,lplReturnCode)

#define IActCCG4A_WriteDeviceRandom(This,szDeviceList,lSize,lplData,lplReturnCode)	\
    (This)->lpVtbl -> WriteDeviceRandom(This,szDeviceList,lSize,lplData,lplReturnCode)

#define IActCCG4A_ReadBuffer(This,lStartIO,lAddress,lSize,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> ReadBuffer(This,lStartIO,lAddress,lSize,lpsData,lplReturnCode)

#define IActCCG4A_WriteBuffer(This,lStartIO,lAddress,lSize,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> WriteBuffer(This,lStartIO,lAddress,lSize,lpsData,lplReturnCode)

#define IActCCG4A_GetClockData(This,lpsYear,lpsMonth,lpsDay,lpsDayOfWeek,lpsHour,lpsMinute,lpsSecond,lplReturnCode)	\
    (This)->lpVtbl -> GetClockData(This,lpsYear,lpsMonth,lpsDay,lpsDayOfWeek,lpsHour,lpsMinute,lpsSecond,lplReturnCode)

#define IActCCG4A_SetClockData(This,sYear,sMonth,sDay,sDayOfWeek,sHour,sMinute,sSecond,lplReturnCode)	\
    (This)->lpVtbl -> SetClockData(This,sYear,sMonth,sDay,sDayOfWeek,sHour,sMinute,sSecond,lplReturnCode)

#define IActCCG4A_SetDevice(This,szDevice,lData,lplReturnCode)	\
    (This)->lpVtbl -> SetDevice(This,szDevice,lData,lplReturnCode)

#define IActCCG4A_get_ActStationNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActStationNumber(This,pVal)

#define IActCCG4A_put_ActStationNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActStationNumber(This,newVal)

#define IActCCG4A_get_ActCpuType(This,pVal)	\
    (This)->lpVtbl -> get_ActCpuType(This,pVal)

#define IActCCG4A_put_ActCpuType(This,newVal)	\
    (This)->lpVtbl -> put_ActCpuType(This,newVal)

#define IActCCG4A_get_ActPortNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActPortNumber(This,pVal)

#define IActCCG4A_put_ActPortNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActPortNumber(This,newVal)

#define IActCCG4A_get_ActControl(This,pVal)	\
    (This)->lpVtbl -> get_ActControl(This,pVal)

#define IActCCG4A_put_ActControl(This,newVal)	\
    (This)->lpVtbl -> put_ActControl(This,newVal)

#define IActCCG4A_get_ActTimeOut(This,pVal)	\
    (This)->lpVtbl -> get_ActTimeOut(This,pVal)

#define IActCCG4A_put_ActTimeOut(This,newVal)	\
    (This)->lpVtbl -> put_ActTimeOut(This,newVal)

#define IActCCG4A_GetDevice(This,szDevice,lplData,lplRetrunCode)	\
    (This)->lpVtbl -> GetDevice(This,szDevice,lplData,lplRetrunCode)

#define IActCCG4A_CheckDeviceString(This,szDevice,lCheckType,lSize,lplDeviceType,lpszDeviceName,lplDeviceNumber,lplDeviceRadix,lplReturnCode)	\
    (This)->lpVtbl -> CheckDeviceString(This,szDevice,lCheckType,lSize,lplDeviceType,lpszDeviceName,lplDeviceNumber,lplDeviceRadix,lplReturnCode)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActCCG4A_Open_Proxy( 
    IActCCG4A __RPC_FAR * This,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActCCG4A_Open_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActCCG4A_Close_Proxy( 
    IActCCG4A __RPC_FAR * This,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActCCG4A_Close_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActCCG4A_GetCpuType_Proxy( 
    IActCCG4A __RPC_FAR * This,
    /* [string][out] */ BSTR __RPC_FAR *szCpuName,
    /* [out] */ LONG __RPC_FAR *lplCpuCode,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActCCG4A_GetCpuType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActCCG4A_SetCpuStatus_Proxy( 
    IActCCG4A __RPC_FAR * This,
    /* [in] */ LONG lOperation,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActCCG4A_SetCpuStatus_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActCCG4A_ReadDeviceBlock_Proxy( 
    IActCCG4A __RPC_FAR * This,
    /* [string][in] */ BSTR szDevice,
    /* [in] */ LONG lSize,
    /* [size_is][out] */ LONG __RPC_FAR *lplData,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActCCG4A_ReadDeviceBlock_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActCCG4A_WriteDeviceBlock_Proxy( 
    IActCCG4A __RPC_FAR * This,
    /* [string][in] */ BSTR szDevice,
    /* [in] */ LONG lSize,
    /* [size_is][in] */ LONG __RPC_FAR *lplData,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActCCG4A_WriteDeviceBlock_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActCCG4A_ReadDeviceRandom_Proxy( 
    IActCCG4A __RPC_FAR * This,
    /* [string][in] */ BSTR szDeviceList,
    /* [in] */ LONG lSize,
    /* [size_is][out] */ LONG __RPC_FAR *lplData,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActCCG4A_ReadDeviceRandom_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActCCG4A_WriteDeviceRandom_Proxy( 
    IActCCG4A __RPC_FAR * This,
    /* [string][in] */ BSTR szDeviceList,
    /* [in] */ LONG lSize,
    /* [size_is][in] */ LONG __RPC_FAR *lplData,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActCCG4A_WriteDeviceRandom_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActCCG4A_ReadBuffer_Proxy( 
    IActCCG4A __RPC_FAR * This,
    /* [in] */ LONG lStartIO,
    /* [in] */ LONG lAddress,
    /* [in] */ LONG lSize,
    /* [size_is][out] */ SHORT __RPC_FAR *lpsData,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActCCG4A_ReadBuffer_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActCCG4A_WriteBuffer_Proxy( 
    IActCCG4A __RPC_FAR * This,
    /* [in] */ LONG lStartIO,
    /* [in] */ LONG lAddress,
    /* [in] */ LONG lSize,
    /* [size_is][in] */ SHORT __RPC_FAR *lpsData,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActCCG4A_WriteBuffer_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActCCG4A_GetClockData_Proxy( 
    IActCCG4A __RPC_FAR * This,
    /* [out] */ SHORT __RPC_FAR *lpsYear,
    /* [out] */ SHORT __RPC_FAR *lpsMonth,
    /* [out] */ SHORT __RPC_FAR *lpsDay,
    /* [out] */ SHORT __RPC_FAR *lpsDayOfWeek,
    /* [out] */ SHORT __RPC_FAR *lpsHour,
    /* [out] */ SHORT __RPC_FAR *lpsMinute,
    /* [out] */ SHORT __RPC_FAR *lpsSecond,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActCCG4A_GetClockData_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActCCG4A_SetClockData_Proxy( 
    IActCCG4A __RPC_FAR * This,
    /* [in] */ SHORT sYear,
    /* [in] */ SHORT sMonth,
    /* [in] */ SHORT sDay,
    /* [in] */ SHORT sDayOfWeek,
    /* [in] */ SHORT sHour,
    /* [in] */ SHORT sMinute,
    /* [in] */ SHORT sSecond,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActCCG4A_SetClockData_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActCCG4A_SetDevice_Proxy( 
    IActCCG4A __RPC_FAR * This,
    /* [string][in] */ BSTR szDevice,
    /* [in] */ LONG lData,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActCCG4A_SetDevice_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActCCG4A_get_ActStationNumber_Proxy( 
    IActCCG4A __RPC_FAR * This,
    /* [retval][out] */ LONG __RPC_FAR *pVal);


void __RPC_STUB IActCCG4A_get_ActStationNumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActCCG4A_put_ActStationNumber_Proxy( 
    IActCCG4A __RPC_FAR * This,
    /* [in] */ LONG newVal);


void __RPC_STUB IActCCG4A_put_ActStationNumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActCCG4A_get_ActCpuType_Proxy( 
    IActCCG4A __RPC_FAR * This,
    /* [retval][out] */ LONG __RPC_FAR *pVal);


void __RPC_STUB IActCCG4A_get_ActCpuType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActCCG4A_put_ActCpuType_Proxy( 
    IActCCG4A __RPC_FAR * This,
    /* [in] */ LONG newVal);


void __RPC_STUB IActCCG4A_put_ActCpuType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActCCG4A_get_ActPortNumber_Proxy( 
    IActCCG4A __RPC_FAR * This,
    /* [retval][out] */ LONG __RPC_FAR *pVal);


void __RPC_STUB IActCCG4A_get_ActPortNumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActCCG4A_put_ActPortNumber_Proxy( 
    IActCCG4A __RPC_FAR * This,
    /* [in] */ LONG newVal);


void __RPC_STUB IActCCG4A_put_ActPortNumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActCCG4A_get_ActControl_Proxy( 
    IActCCG4A __RPC_FAR * This,
    /* [retval][out] */ LONG __RPC_FAR *pVal);


void __RPC_STUB IActCCG4A_get_ActControl_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActCCG4A_put_ActControl_Proxy( 
    IActCCG4A __RPC_FAR * This,
    /* [in] */ LONG newVal);


void __RPC_STUB IActCCG4A_put_ActControl_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActCCG4A_get_ActTimeOut_Proxy( 
    IActCCG4A __RPC_FAR * This,
    /* [retval][out] */ LONG __RPC_FAR *pVal);


void __RPC_STUB IActCCG4A_get_ActTimeOut_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActCCG4A_put_ActTimeOut_Proxy( 
    IActCCG4A __RPC_FAR * This,
    /* [in] */ LONG newVal);


void __RPC_STUB IActCCG4A_put_ActTimeOut_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActCCG4A_GetDevice_Proxy( 
    IActCCG4A __RPC_FAR * This,
    /* [string][in] */ BSTR szDevice,
    /* [out] */ LONG __RPC_FAR *lplData,
    /* [retval][out] */ LONG __RPC_FAR *lplRetrunCode);


void __RPC_STUB IActCCG4A_GetDevice_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActCCG4A_CheckDeviceString_Proxy( 
    IActCCG4A __RPC_FAR * This,
    /* [in] */ BSTR szDevice,
    /* [in] */ LONG lCheckType,
    /* [in] */ LONG lSize,
    /* [out] */ LONG __RPC_FAR *lplDeviceType,
    /* [string][out] */ BSTR __RPC_FAR *lpszDeviceName,
    /* [out] */ LONG __RPC_FAR *lplDeviceNumber,
    /* [out] */ LONG __RPC_FAR *lplDeviceRadix,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActCCG4A_CheckDeviceString_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IActCCG4A_INTERFACE_DEFINED__ */


#ifndef __IActCCG4A2_INTERFACE_DEFINED__
#define __IActCCG4A2_INTERFACE_DEFINED__

/* interface IActCCG4A2 */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IActCCG4A2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("8E29CCC1-C6A6-11d4-8741-00E0292A4FB4")
    IActCCG4A2 : public IActCCG4A
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

    typedef struct IActCCG4A2Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IActCCG4A2 __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IActCCG4A2 __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IActCCG4A2 __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IActCCG4A2 __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IActCCG4A2 __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IActCCG4A2 __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IActCCG4A2 __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Open )( 
            IActCCG4A2 __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Close )( 
            IActCCG4A2 __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetCpuType )( 
            IActCCG4A2 __RPC_FAR * This,
            /* [string][out] */ BSTR __RPC_FAR *szCpuName,
            /* [out] */ LONG __RPC_FAR *lplCpuCode,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetCpuStatus )( 
            IActCCG4A2 __RPC_FAR * This,
            /* [in] */ LONG lOperation,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceBlock )( 
            IActCCG4A2 __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lSize,
            /* [size_is][out] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceBlock )( 
            IActCCG4A2 __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lSize,
            /* [size_is][in] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceRandom )( 
            IActCCG4A2 __RPC_FAR * This,
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG lSize,
            /* [size_is][out] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceRandom )( 
            IActCCG4A2 __RPC_FAR * This,
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG lSize,
            /* [size_is][in] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadBuffer )( 
            IActCCG4A2 __RPC_FAR * This,
            /* [in] */ LONG lStartIO,
            /* [in] */ LONG lAddress,
            /* [in] */ LONG lSize,
            /* [size_is][out] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteBuffer )( 
            IActCCG4A2 __RPC_FAR * This,
            /* [in] */ LONG lStartIO,
            /* [in] */ LONG lAddress,
            /* [in] */ LONG lSize,
            /* [size_is][in] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetClockData )( 
            IActCCG4A2 __RPC_FAR * This,
            /* [out] */ SHORT __RPC_FAR *lpsYear,
            /* [out] */ SHORT __RPC_FAR *lpsMonth,
            /* [out] */ SHORT __RPC_FAR *lpsDay,
            /* [out] */ SHORT __RPC_FAR *lpsDayOfWeek,
            /* [out] */ SHORT __RPC_FAR *lpsHour,
            /* [out] */ SHORT __RPC_FAR *lpsMinute,
            /* [out] */ SHORT __RPC_FAR *lpsSecond,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetClockData )( 
            IActCCG4A2 __RPC_FAR * This,
            /* [in] */ SHORT sYear,
            /* [in] */ SHORT sMonth,
            /* [in] */ SHORT sDay,
            /* [in] */ SHORT sDayOfWeek,
            /* [in] */ SHORT sHour,
            /* [in] */ SHORT sMinute,
            /* [in] */ SHORT sSecond,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetDevice )( 
            IActCCG4A2 __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActStationNumber )( 
            IActCCG4A2 __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActStationNumber )( 
            IActCCG4A2 __RPC_FAR * This,
            /* [in] */ LONG newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActCpuType )( 
            IActCCG4A2 __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActCpuType )( 
            IActCCG4A2 __RPC_FAR * This,
            /* [in] */ LONG newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActPortNumber )( 
            IActCCG4A2 __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActPortNumber )( 
            IActCCG4A2 __RPC_FAR * This,
            /* [in] */ LONG newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActControl )( 
            IActCCG4A2 __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActControl )( 
            IActCCG4A2 __RPC_FAR * This,
            /* [in] */ LONG newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActTimeOut )( 
            IActCCG4A2 __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActTimeOut )( 
            IActCCG4A2 __RPC_FAR * This,
            /* [in] */ LONG newVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetDevice )( 
            IActCCG4A2 __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [out] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplRetrunCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CheckDeviceString )( 
            IActCCG4A2 __RPC_FAR * This,
            /* [in] */ BSTR szDevice,
            /* [in] */ LONG lCheckType,
            /* [in] */ LONG lSize,
            /* [out] */ LONG __RPC_FAR *lplDeviceType,
            /* [string][out] */ BSTR __RPC_FAR *lpszDeviceName,
            /* [out] */ LONG __RPC_FAR *lplDeviceNumber,
            /* [out] */ LONG __RPC_FAR *lplDeviceRadix,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *EntryDeviceStatus )( 
            IActCCG4A2 __RPC_FAR * This,
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG lSize,
            /* [in] */ LONG lMonitorCycle,
            /* [size_is][in] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *FreeDeviceStatus )( 
            IActCCG4A2 __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        END_INTERFACE
    } IActCCG4A2Vtbl;

    interface IActCCG4A2
    {
        CONST_VTBL struct IActCCG4A2Vtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IActCCG4A2_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IActCCG4A2_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IActCCG4A2_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IActCCG4A2_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IActCCG4A2_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IActCCG4A2_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IActCCG4A2_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IActCCG4A2_Open(This,lplReturnCode)	\
    (This)->lpVtbl -> Open(This,lplReturnCode)

#define IActCCG4A2_Close(This,lplReturnCode)	\
    (This)->lpVtbl -> Close(This,lplReturnCode)

#define IActCCG4A2_GetCpuType(This,szCpuName,lplCpuCode,lplReturnCode)	\
    (This)->lpVtbl -> GetCpuType(This,szCpuName,lplCpuCode,lplReturnCode)

#define IActCCG4A2_SetCpuStatus(This,lOperation,lplReturnCode)	\
    (This)->lpVtbl -> SetCpuStatus(This,lOperation,lplReturnCode)

#define IActCCG4A2_ReadDeviceBlock(This,szDevice,lSize,lplData,lplReturnCode)	\
    (This)->lpVtbl -> ReadDeviceBlock(This,szDevice,lSize,lplData,lplReturnCode)

#define IActCCG4A2_WriteDeviceBlock(This,szDevice,lSize,lplData,lplReturnCode)	\
    (This)->lpVtbl -> WriteDeviceBlock(This,szDevice,lSize,lplData,lplReturnCode)

#define IActCCG4A2_ReadDeviceRandom(This,szDeviceList,lSize,lplData,lplReturnCode)	\
    (This)->lpVtbl -> ReadDeviceRandom(This,szDeviceList,lSize,lplData,lplReturnCode)

#define IActCCG4A2_WriteDeviceRandom(This,szDeviceList,lSize,lplData,lplReturnCode)	\
    (This)->lpVtbl -> WriteDeviceRandom(This,szDeviceList,lSize,lplData,lplReturnCode)

#define IActCCG4A2_ReadBuffer(This,lStartIO,lAddress,lSize,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> ReadBuffer(This,lStartIO,lAddress,lSize,lpsData,lplReturnCode)

#define IActCCG4A2_WriteBuffer(This,lStartIO,lAddress,lSize,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> WriteBuffer(This,lStartIO,lAddress,lSize,lpsData,lplReturnCode)

#define IActCCG4A2_GetClockData(This,lpsYear,lpsMonth,lpsDay,lpsDayOfWeek,lpsHour,lpsMinute,lpsSecond,lplReturnCode)	\
    (This)->lpVtbl -> GetClockData(This,lpsYear,lpsMonth,lpsDay,lpsDayOfWeek,lpsHour,lpsMinute,lpsSecond,lplReturnCode)

#define IActCCG4A2_SetClockData(This,sYear,sMonth,sDay,sDayOfWeek,sHour,sMinute,sSecond,lplReturnCode)	\
    (This)->lpVtbl -> SetClockData(This,sYear,sMonth,sDay,sDayOfWeek,sHour,sMinute,sSecond,lplReturnCode)

#define IActCCG4A2_SetDevice(This,szDevice,lData,lplReturnCode)	\
    (This)->lpVtbl -> SetDevice(This,szDevice,lData,lplReturnCode)

#define IActCCG4A2_get_ActStationNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActStationNumber(This,pVal)

#define IActCCG4A2_put_ActStationNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActStationNumber(This,newVal)

#define IActCCG4A2_get_ActCpuType(This,pVal)	\
    (This)->lpVtbl -> get_ActCpuType(This,pVal)

#define IActCCG4A2_put_ActCpuType(This,newVal)	\
    (This)->lpVtbl -> put_ActCpuType(This,newVal)

#define IActCCG4A2_get_ActPortNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActPortNumber(This,pVal)

#define IActCCG4A2_put_ActPortNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActPortNumber(This,newVal)

#define IActCCG4A2_get_ActControl(This,pVal)	\
    (This)->lpVtbl -> get_ActControl(This,pVal)

#define IActCCG4A2_put_ActControl(This,newVal)	\
    (This)->lpVtbl -> put_ActControl(This,newVal)

#define IActCCG4A2_get_ActTimeOut(This,pVal)	\
    (This)->lpVtbl -> get_ActTimeOut(This,pVal)

#define IActCCG4A2_put_ActTimeOut(This,newVal)	\
    (This)->lpVtbl -> put_ActTimeOut(This,newVal)

#define IActCCG4A2_GetDevice(This,szDevice,lplData,lplRetrunCode)	\
    (This)->lpVtbl -> GetDevice(This,szDevice,lplData,lplRetrunCode)

#define IActCCG4A2_CheckDeviceString(This,szDevice,lCheckType,lSize,lplDeviceType,lpszDeviceName,lplDeviceNumber,lplDeviceRadix,lplReturnCode)	\
    (This)->lpVtbl -> CheckDeviceString(This,szDevice,lCheckType,lSize,lplDeviceType,lpszDeviceName,lplDeviceNumber,lplDeviceRadix,lplReturnCode)


#define IActCCG4A2_EntryDeviceStatus(This,szDeviceList,lSize,lMonitorCycle,lplData,lplReturnCode)	\
    (This)->lpVtbl -> EntryDeviceStatus(This,szDeviceList,lSize,lMonitorCycle,lplData,lplReturnCode)

#define IActCCG4A2_FreeDeviceStatus(This,lplReturnCode)	\
    (This)->lpVtbl -> FreeDeviceStatus(This,lplReturnCode)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActCCG4A2_EntryDeviceStatus_Proxy( 
    IActCCG4A2 __RPC_FAR * This,
    /* [string][in] */ BSTR szDeviceList,
    /* [in] */ LONG lSize,
    /* [in] */ LONG lMonitorCycle,
    /* [size_is][in] */ LONG __RPC_FAR *lplData,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActCCG4A2_EntryDeviceStatus_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActCCG4A2_FreeDeviceStatus_Proxy( 
    IActCCG4A2 __RPC_FAR * This,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActCCG4A2_FreeDeviceStatus_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IActCCG4A2_INTERFACE_DEFINED__ */


#ifndef __IActCCG4A3_INTERFACE_DEFINED__
#define __IActCCG4A3_INTERFACE_DEFINED__

/* interface IActCCG4A3 */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IActCCG4A3;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("115992F6-6EC2-11d5-9314-009099244EFD")
    IActCCG4A3 : public IActCCG4A2
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

    typedef struct IActCCG4A3Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IActCCG4A3 __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IActCCG4A3 __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IActCCG4A3 __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IActCCG4A3 __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IActCCG4A3 __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IActCCG4A3 __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IActCCG4A3 __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Open )( 
            IActCCG4A3 __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Close )( 
            IActCCG4A3 __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetCpuType )( 
            IActCCG4A3 __RPC_FAR * This,
            /* [string][out] */ BSTR __RPC_FAR *szCpuName,
            /* [out] */ LONG __RPC_FAR *lplCpuCode,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetCpuStatus )( 
            IActCCG4A3 __RPC_FAR * This,
            /* [in] */ LONG lOperation,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceBlock )( 
            IActCCG4A3 __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lSize,
            /* [size_is][out] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceBlock )( 
            IActCCG4A3 __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lSize,
            /* [size_is][in] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceRandom )( 
            IActCCG4A3 __RPC_FAR * This,
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG lSize,
            /* [size_is][out] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceRandom )( 
            IActCCG4A3 __RPC_FAR * This,
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG lSize,
            /* [size_is][in] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadBuffer )( 
            IActCCG4A3 __RPC_FAR * This,
            /* [in] */ LONG lStartIO,
            /* [in] */ LONG lAddress,
            /* [in] */ LONG lSize,
            /* [size_is][out] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteBuffer )( 
            IActCCG4A3 __RPC_FAR * This,
            /* [in] */ LONG lStartIO,
            /* [in] */ LONG lAddress,
            /* [in] */ LONG lSize,
            /* [size_is][in] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetClockData )( 
            IActCCG4A3 __RPC_FAR * This,
            /* [out] */ SHORT __RPC_FAR *lpsYear,
            /* [out] */ SHORT __RPC_FAR *lpsMonth,
            /* [out] */ SHORT __RPC_FAR *lpsDay,
            /* [out] */ SHORT __RPC_FAR *lpsDayOfWeek,
            /* [out] */ SHORT __RPC_FAR *lpsHour,
            /* [out] */ SHORT __RPC_FAR *lpsMinute,
            /* [out] */ SHORT __RPC_FAR *lpsSecond,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetClockData )( 
            IActCCG4A3 __RPC_FAR * This,
            /* [in] */ SHORT sYear,
            /* [in] */ SHORT sMonth,
            /* [in] */ SHORT sDay,
            /* [in] */ SHORT sDayOfWeek,
            /* [in] */ SHORT sHour,
            /* [in] */ SHORT sMinute,
            /* [in] */ SHORT sSecond,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetDevice )( 
            IActCCG4A3 __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActStationNumber )( 
            IActCCG4A3 __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActStationNumber )( 
            IActCCG4A3 __RPC_FAR * This,
            /* [in] */ LONG newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActCpuType )( 
            IActCCG4A3 __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActCpuType )( 
            IActCCG4A3 __RPC_FAR * This,
            /* [in] */ LONG newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActPortNumber )( 
            IActCCG4A3 __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActPortNumber )( 
            IActCCG4A3 __RPC_FAR * This,
            /* [in] */ LONG newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActControl )( 
            IActCCG4A3 __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActControl )( 
            IActCCG4A3 __RPC_FAR * This,
            /* [in] */ LONG newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActTimeOut )( 
            IActCCG4A3 __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActTimeOut )( 
            IActCCG4A3 __RPC_FAR * This,
            /* [in] */ LONG newVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetDevice )( 
            IActCCG4A3 __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [out] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplRetrunCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CheckDeviceString )( 
            IActCCG4A3 __RPC_FAR * This,
            /* [in] */ BSTR szDevice,
            /* [in] */ LONG lCheckType,
            /* [in] */ LONG lSize,
            /* [out] */ LONG __RPC_FAR *lplDeviceType,
            /* [string][out] */ BSTR __RPC_FAR *lpszDeviceName,
            /* [out] */ LONG __RPC_FAR *lplDeviceNumber,
            /* [out] */ LONG __RPC_FAR *lplDeviceRadix,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *EntryDeviceStatus )( 
            IActCCG4A3 __RPC_FAR * This,
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG lSize,
            /* [in] */ LONG lMonitorCycle,
            /* [size_is][in] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *FreeDeviceStatus )( 
            IActCCG4A3 __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceBlock2 )( 
            IActCCG4A3 __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lSize,
            /* [size_is][out] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceBlock2 )( 
            IActCCG4A3 __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lSize,
            /* [size_is][in] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceRandom2 )( 
            IActCCG4A3 __RPC_FAR * This,
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG lSize,
            /* [size_is][out] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceRandom2 )( 
            IActCCG4A3 __RPC_FAR * This,
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG lSize,
            /* [size_is][in] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetDevice2 )( 
            IActCCG4A3 __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [out] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetDevice2 )( 
            IActCCG4A3 __RPC_FAR * This,
            /* [in] */ BSTR szDevice,
            /* [in] */ SHORT sData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        END_INTERFACE
    } IActCCG4A3Vtbl;

    interface IActCCG4A3
    {
        CONST_VTBL struct IActCCG4A3Vtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IActCCG4A3_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IActCCG4A3_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IActCCG4A3_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IActCCG4A3_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IActCCG4A3_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IActCCG4A3_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IActCCG4A3_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IActCCG4A3_Open(This,lplReturnCode)	\
    (This)->lpVtbl -> Open(This,lplReturnCode)

#define IActCCG4A3_Close(This,lplReturnCode)	\
    (This)->lpVtbl -> Close(This,lplReturnCode)

#define IActCCG4A3_GetCpuType(This,szCpuName,lplCpuCode,lplReturnCode)	\
    (This)->lpVtbl -> GetCpuType(This,szCpuName,lplCpuCode,lplReturnCode)

#define IActCCG4A3_SetCpuStatus(This,lOperation,lplReturnCode)	\
    (This)->lpVtbl -> SetCpuStatus(This,lOperation,lplReturnCode)

#define IActCCG4A3_ReadDeviceBlock(This,szDevice,lSize,lplData,lplReturnCode)	\
    (This)->lpVtbl -> ReadDeviceBlock(This,szDevice,lSize,lplData,lplReturnCode)

#define IActCCG4A3_WriteDeviceBlock(This,szDevice,lSize,lplData,lplReturnCode)	\
    (This)->lpVtbl -> WriteDeviceBlock(This,szDevice,lSize,lplData,lplReturnCode)

#define IActCCG4A3_ReadDeviceRandom(This,szDeviceList,lSize,lplData,lplReturnCode)	\
    (This)->lpVtbl -> ReadDeviceRandom(This,szDeviceList,lSize,lplData,lplReturnCode)

#define IActCCG4A3_WriteDeviceRandom(This,szDeviceList,lSize,lplData,lplReturnCode)	\
    (This)->lpVtbl -> WriteDeviceRandom(This,szDeviceList,lSize,lplData,lplReturnCode)

#define IActCCG4A3_ReadBuffer(This,lStartIO,lAddress,lSize,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> ReadBuffer(This,lStartIO,lAddress,lSize,lpsData,lplReturnCode)

#define IActCCG4A3_WriteBuffer(This,lStartIO,lAddress,lSize,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> WriteBuffer(This,lStartIO,lAddress,lSize,lpsData,lplReturnCode)

#define IActCCG4A3_GetClockData(This,lpsYear,lpsMonth,lpsDay,lpsDayOfWeek,lpsHour,lpsMinute,lpsSecond,lplReturnCode)	\
    (This)->lpVtbl -> GetClockData(This,lpsYear,lpsMonth,lpsDay,lpsDayOfWeek,lpsHour,lpsMinute,lpsSecond,lplReturnCode)

#define IActCCG4A3_SetClockData(This,sYear,sMonth,sDay,sDayOfWeek,sHour,sMinute,sSecond,lplReturnCode)	\
    (This)->lpVtbl -> SetClockData(This,sYear,sMonth,sDay,sDayOfWeek,sHour,sMinute,sSecond,lplReturnCode)

#define IActCCG4A3_SetDevice(This,szDevice,lData,lplReturnCode)	\
    (This)->lpVtbl -> SetDevice(This,szDevice,lData,lplReturnCode)

#define IActCCG4A3_get_ActStationNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActStationNumber(This,pVal)

#define IActCCG4A3_put_ActStationNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActStationNumber(This,newVal)

#define IActCCG4A3_get_ActCpuType(This,pVal)	\
    (This)->lpVtbl -> get_ActCpuType(This,pVal)

#define IActCCG4A3_put_ActCpuType(This,newVal)	\
    (This)->lpVtbl -> put_ActCpuType(This,newVal)

#define IActCCG4A3_get_ActPortNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActPortNumber(This,pVal)

#define IActCCG4A3_put_ActPortNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActPortNumber(This,newVal)

#define IActCCG4A3_get_ActControl(This,pVal)	\
    (This)->lpVtbl -> get_ActControl(This,pVal)

#define IActCCG4A3_put_ActControl(This,newVal)	\
    (This)->lpVtbl -> put_ActControl(This,newVal)

#define IActCCG4A3_get_ActTimeOut(This,pVal)	\
    (This)->lpVtbl -> get_ActTimeOut(This,pVal)

#define IActCCG4A3_put_ActTimeOut(This,newVal)	\
    (This)->lpVtbl -> put_ActTimeOut(This,newVal)

#define IActCCG4A3_GetDevice(This,szDevice,lplData,lplRetrunCode)	\
    (This)->lpVtbl -> GetDevice(This,szDevice,lplData,lplRetrunCode)

#define IActCCG4A3_CheckDeviceString(This,szDevice,lCheckType,lSize,lplDeviceType,lpszDeviceName,lplDeviceNumber,lplDeviceRadix,lplReturnCode)	\
    (This)->lpVtbl -> CheckDeviceString(This,szDevice,lCheckType,lSize,lplDeviceType,lpszDeviceName,lplDeviceNumber,lplDeviceRadix,lplReturnCode)


#define IActCCG4A3_EntryDeviceStatus(This,szDeviceList,lSize,lMonitorCycle,lplData,lplReturnCode)	\
    (This)->lpVtbl -> EntryDeviceStatus(This,szDeviceList,lSize,lMonitorCycle,lplData,lplReturnCode)

#define IActCCG4A3_FreeDeviceStatus(This,lplReturnCode)	\
    (This)->lpVtbl -> FreeDeviceStatus(This,lplReturnCode)


#define IActCCG4A3_ReadDeviceBlock2(This,szDevice,lSize,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> ReadDeviceBlock2(This,szDevice,lSize,lpsData,lplReturnCode)

#define IActCCG4A3_WriteDeviceBlock2(This,szDevice,lSize,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> WriteDeviceBlock2(This,szDevice,lSize,lpsData,lplReturnCode)

#define IActCCG4A3_ReadDeviceRandom2(This,szDeviceList,lSize,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> ReadDeviceRandom2(This,szDeviceList,lSize,lpsData,lplReturnCode)

#define IActCCG4A3_WriteDeviceRandom2(This,szDeviceList,lSize,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> WriteDeviceRandom2(This,szDeviceList,lSize,lpsData,lplReturnCode)

#define IActCCG4A3_GetDevice2(This,szDevice,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> GetDevice2(This,szDevice,lpsData,lplReturnCode)

#define IActCCG4A3_SetDevice2(This,szDevice,sData,lplReturnCode)	\
    (This)->lpVtbl -> SetDevice2(This,szDevice,sData,lplReturnCode)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActCCG4A3_ReadDeviceBlock2_Proxy( 
    IActCCG4A3 __RPC_FAR * This,
    /* [string][in] */ BSTR szDevice,
    /* [in] */ LONG lSize,
    /* [size_is][out] */ SHORT __RPC_FAR *lpsData,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActCCG4A3_ReadDeviceBlock2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActCCG4A3_WriteDeviceBlock2_Proxy( 
    IActCCG4A3 __RPC_FAR * This,
    /* [string][in] */ BSTR szDevice,
    /* [in] */ LONG lSize,
    /* [size_is][in] */ SHORT __RPC_FAR *lpsData,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActCCG4A3_WriteDeviceBlock2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActCCG4A3_ReadDeviceRandom2_Proxy( 
    IActCCG4A3 __RPC_FAR * This,
    /* [string][in] */ BSTR szDeviceList,
    /* [in] */ LONG lSize,
    /* [size_is][out] */ SHORT __RPC_FAR *lpsData,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActCCG4A3_ReadDeviceRandom2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActCCG4A3_WriteDeviceRandom2_Proxy( 
    IActCCG4A3 __RPC_FAR * This,
    /* [string][in] */ BSTR szDeviceList,
    /* [in] */ LONG lSize,
    /* [size_is][in] */ SHORT __RPC_FAR *lpsData,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActCCG4A3_WriteDeviceRandom2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActCCG4A3_GetDevice2_Proxy( 
    IActCCG4A3 __RPC_FAR * This,
    /* [string][in] */ BSTR szDevice,
    /* [out] */ SHORT __RPC_FAR *lpsData,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActCCG4A3_GetDevice2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActCCG4A3_SetDevice2_Proxy( 
    IActCCG4A3 __RPC_FAR * This,
    /* [in] */ BSTR szDevice,
    /* [in] */ SHORT sData,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActCCG4A3_SetDevice2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IActCCG4A3_INTERFACE_DEFINED__ */


#ifndef __IActMLCCG4A_INTERFACE_DEFINED__
#define __IActMLCCG4A_INTERFACE_DEFINED__

/* interface IActMLCCG4A */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IActMLCCG4A;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("29BD6542-A98F-11D4-910D-009099244EFD")
    IActMLCCG4A : public IDispatch
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
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActStationNumber( 
            /* [retval][out] */ VARIANT __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActStationNumber( 
            /* [in] */ VARIANT newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActCpuType( 
            /* [retval][out] */ VARIANT __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActCpuType( 
            /* [in] */ VARIANT newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActPortNumber( 
            /* [retval][out] */ VARIANT __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActPortNumber( 
            /* [in] */ VARIANT newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActControl( 
            /* [retval][out] */ VARIANT __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActControl( 
            /* [in] */ VARIANT newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActTimeOut( 
            /* [retval][out] */ VARIANT __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActTimeOut( 
            /* [in] */ VARIANT newVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE FreeDeviceStatus( 
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IActMLCCG4AVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IActMLCCG4A __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IActMLCCG4A __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IActMLCCG4A __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IActMLCCG4A __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IActMLCCG4A __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IActMLCCG4A __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IActMLCCG4A __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Open )( 
            IActMLCCG4A __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Close )( 
            IActMLCCG4A __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetDevice )( 
            IActMLCCG4A __RPC_FAR * This,
            /* [in] */ VARIANT varDevice,
            /* [out] */ VARIANT __RPC_FAR *lpvarData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetDevice )( 
            IActMLCCG4A __RPC_FAR * This,
            /* [in] */ VARIANT varDevice,
            /* [in] */ VARIANT varData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceBlock )( 
            IActMLCCG4A __RPC_FAR * This,
            /* [in] */ VARIANT varDevice,
            /* [in] */ VARIANT varSize,
            /* [out] */ VARIANT __RPC_FAR *lpvarData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceBlock )( 
            IActMLCCG4A __RPC_FAR * This,
            /* [in] */ VARIANT varDevice,
            /* [in] */ VARIANT varSize,
            /* [in] */ VARIANT varData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceRandom )( 
            IActMLCCG4A __RPC_FAR * This,
            /* [in] */ VARIANT varDeviceList,
            /* [in] */ VARIANT varSize,
            /* [out] */ VARIANT __RPC_FAR *lpvarData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceRandom )( 
            IActMLCCG4A __RPC_FAR * This,
            /* [in] */ VARIANT varDeviceList,
            /* [in] */ VARIANT varSize,
            /* [in] */ VARIANT varData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadBuffer )( 
            IActMLCCG4A __RPC_FAR * This,
            /* [in] */ VARIANT varStartIO,
            /* [in] */ VARIANT varAddress,
            /* [in] */ VARIANT varReadSize,
            /* [out] */ VARIANT __RPC_FAR *lpvarData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteBuffer )( 
            IActMLCCG4A __RPC_FAR * This,
            /* [in] */ VARIANT varStartIO,
            /* [in] */ VARIANT varAddress,
            /* [in] */ VARIANT varWriteSize,
            /* [in] */ VARIANT varData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetCpuType )( 
            IActMLCCG4A __RPC_FAR * This,
            /* [out] */ VARIANT __RPC_FAR *lpvarCpuName,
            /* [out] */ VARIANT __RPC_FAR *lpvarCpuType,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetCpuStatus )( 
            IActMLCCG4A __RPC_FAR * This,
            /* [in] */ VARIANT varOperation,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetClockData )( 
            IActMLCCG4A __RPC_FAR * This,
            /* [out] */ VARIANT __RPC_FAR *lpvarYear,
            /* [out] */ VARIANT __RPC_FAR *lpvarMonth,
            /* [out] */ VARIANT __RPC_FAR *lpvarDay,
            /* [out] */ VARIANT __RPC_FAR *lpvarDayOfWeek,
            /* [out] */ VARIANT __RPC_FAR *lpvarHour,
            /* [out] */ VARIANT __RPC_FAR *lpvarMinute,
            /* [out] */ VARIANT __RPC_FAR *lpvarSecond,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetClockData )( 
            IActMLCCG4A __RPC_FAR * This,
            /* [in] */ VARIANT varYear,
            /* [in] */ VARIANT varMonth,
            /* [in] */ VARIANT varDay,
            /* [in] */ VARIANT varDayOfWeek,
            /* [in] */ VARIANT varHour,
            /* [in] */ VARIANT varMinute,
            /* [in] */ VARIANT varSecond,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *EntryDeviceStatus )( 
            IActMLCCG4A __RPC_FAR * This,
            /* [in] */ VARIANT varDeviceList,
            /* [in] */ VARIANT varSize,
            /* [in] */ VARIANT varMonitorCycle,
            /* [in] */ VARIANT varData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActStationNumber )( 
            IActMLCCG4A __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActStationNumber )( 
            IActMLCCG4A __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActCpuType )( 
            IActMLCCG4A __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActCpuType )( 
            IActMLCCG4A __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActPortNumber )( 
            IActMLCCG4A __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActPortNumber )( 
            IActMLCCG4A __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActControl )( 
            IActMLCCG4A __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActControl )( 
            IActMLCCG4A __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActTimeOut )( 
            IActMLCCG4A __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActTimeOut )( 
            IActMLCCG4A __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *FreeDeviceStatus )( 
            IActMLCCG4A __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        END_INTERFACE
    } IActMLCCG4AVtbl;

    interface IActMLCCG4A
    {
        CONST_VTBL struct IActMLCCG4AVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IActMLCCG4A_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IActMLCCG4A_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IActMLCCG4A_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IActMLCCG4A_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IActMLCCG4A_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IActMLCCG4A_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IActMLCCG4A_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IActMLCCG4A_Open(This,lpvarReturnCode)	\
    (This)->lpVtbl -> Open(This,lpvarReturnCode)

#define IActMLCCG4A_Close(This,lpvarReturnCode)	\
    (This)->lpVtbl -> Close(This,lpvarReturnCode)

#define IActMLCCG4A_GetDevice(This,varDevice,lpvarData,lpvarReturnCode)	\
    (This)->lpVtbl -> GetDevice(This,varDevice,lpvarData,lpvarReturnCode)

#define IActMLCCG4A_SetDevice(This,varDevice,varData,lpvarReturnCode)	\
    (This)->lpVtbl -> SetDevice(This,varDevice,varData,lpvarReturnCode)

#define IActMLCCG4A_ReadDeviceBlock(This,varDevice,varSize,lpvarData,lpvarReturnCode)	\
    (This)->lpVtbl -> ReadDeviceBlock(This,varDevice,varSize,lpvarData,lpvarReturnCode)

#define IActMLCCG4A_WriteDeviceBlock(This,varDevice,varSize,varData,lpvarReturnCode)	\
    (This)->lpVtbl -> WriteDeviceBlock(This,varDevice,varSize,varData,lpvarReturnCode)

#define IActMLCCG4A_ReadDeviceRandom(This,varDeviceList,varSize,lpvarData,lpvarReturnCode)	\
    (This)->lpVtbl -> ReadDeviceRandom(This,varDeviceList,varSize,lpvarData,lpvarReturnCode)

#define IActMLCCG4A_WriteDeviceRandom(This,varDeviceList,varSize,varData,lpvarReturnCode)	\
    (This)->lpVtbl -> WriteDeviceRandom(This,varDeviceList,varSize,varData,lpvarReturnCode)

#define IActMLCCG4A_ReadBuffer(This,varStartIO,varAddress,varReadSize,lpvarData,lpvarReturnCode)	\
    (This)->lpVtbl -> ReadBuffer(This,varStartIO,varAddress,varReadSize,lpvarData,lpvarReturnCode)

#define IActMLCCG4A_WriteBuffer(This,varStartIO,varAddress,varWriteSize,varData,lpvarReturnCode)	\
    (This)->lpVtbl -> WriteBuffer(This,varStartIO,varAddress,varWriteSize,varData,lpvarReturnCode)

#define IActMLCCG4A_GetCpuType(This,lpvarCpuName,lpvarCpuType,lpvarReturnCode)	\
    (This)->lpVtbl -> GetCpuType(This,lpvarCpuName,lpvarCpuType,lpvarReturnCode)

#define IActMLCCG4A_SetCpuStatus(This,varOperation,lpvarReturnCode)	\
    (This)->lpVtbl -> SetCpuStatus(This,varOperation,lpvarReturnCode)

#define IActMLCCG4A_GetClockData(This,lpvarYear,lpvarMonth,lpvarDay,lpvarDayOfWeek,lpvarHour,lpvarMinute,lpvarSecond,lpvarReturnCode)	\
    (This)->lpVtbl -> GetClockData(This,lpvarYear,lpvarMonth,lpvarDay,lpvarDayOfWeek,lpvarHour,lpvarMinute,lpvarSecond,lpvarReturnCode)

#define IActMLCCG4A_SetClockData(This,varYear,varMonth,varDay,varDayOfWeek,varHour,varMinute,varSecond,lpvarReturnCode)	\
    (This)->lpVtbl -> SetClockData(This,varYear,varMonth,varDay,varDayOfWeek,varHour,varMinute,varSecond,lpvarReturnCode)

#define IActMLCCG4A_EntryDeviceStatus(This,varDeviceList,varSize,varMonitorCycle,varData,lpvarReturnCode)	\
    (This)->lpVtbl -> EntryDeviceStatus(This,varDeviceList,varSize,varMonitorCycle,varData,lpvarReturnCode)

#define IActMLCCG4A_get_ActStationNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActStationNumber(This,pVal)

#define IActMLCCG4A_put_ActStationNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActStationNumber(This,newVal)

#define IActMLCCG4A_get_ActCpuType(This,pVal)	\
    (This)->lpVtbl -> get_ActCpuType(This,pVal)

#define IActMLCCG4A_put_ActCpuType(This,newVal)	\
    (This)->lpVtbl -> put_ActCpuType(This,newVal)

#define IActMLCCG4A_get_ActPortNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActPortNumber(This,pVal)

#define IActMLCCG4A_put_ActPortNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActPortNumber(This,newVal)

#define IActMLCCG4A_get_ActControl(This,pVal)	\
    (This)->lpVtbl -> get_ActControl(This,pVal)

#define IActMLCCG4A_put_ActControl(This,newVal)	\
    (This)->lpVtbl -> put_ActControl(This,newVal)

#define IActMLCCG4A_get_ActTimeOut(This,pVal)	\
    (This)->lpVtbl -> get_ActTimeOut(This,pVal)

#define IActMLCCG4A_put_ActTimeOut(This,newVal)	\
    (This)->lpVtbl -> put_ActTimeOut(This,newVal)

#define IActMLCCG4A_FreeDeviceStatus(This,lpvarReturnCode)	\
    (This)->lpVtbl -> FreeDeviceStatus(This,lpvarReturnCode)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActMLCCG4A_Open_Proxy( 
    IActMLCCG4A __RPC_FAR * This,
    /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);


void __RPC_STUB IActMLCCG4A_Open_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActMLCCG4A_Close_Proxy( 
    IActMLCCG4A __RPC_FAR * This,
    /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);


void __RPC_STUB IActMLCCG4A_Close_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActMLCCG4A_GetDevice_Proxy( 
    IActMLCCG4A __RPC_FAR * This,
    /* [in] */ VARIANT varDevice,
    /* [out] */ VARIANT __RPC_FAR *lpvarData,
    /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);


void __RPC_STUB IActMLCCG4A_GetDevice_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActMLCCG4A_SetDevice_Proxy( 
    IActMLCCG4A __RPC_FAR * This,
    /* [in] */ VARIANT varDevice,
    /* [in] */ VARIANT varData,
    /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);


void __RPC_STUB IActMLCCG4A_SetDevice_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActMLCCG4A_ReadDeviceBlock_Proxy( 
    IActMLCCG4A __RPC_FAR * This,
    /* [in] */ VARIANT varDevice,
    /* [in] */ VARIANT varSize,
    /* [out] */ VARIANT __RPC_FAR *lpvarData,
    /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);


void __RPC_STUB IActMLCCG4A_ReadDeviceBlock_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActMLCCG4A_WriteDeviceBlock_Proxy( 
    IActMLCCG4A __RPC_FAR * This,
    /* [in] */ VARIANT varDevice,
    /* [in] */ VARIANT varSize,
    /* [in] */ VARIANT varData,
    /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);


void __RPC_STUB IActMLCCG4A_WriteDeviceBlock_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActMLCCG4A_ReadDeviceRandom_Proxy( 
    IActMLCCG4A __RPC_FAR * This,
    /* [in] */ VARIANT varDeviceList,
    /* [in] */ VARIANT varSize,
    /* [out] */ VARIANT __RPC_FAR *lpvarData,
    /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);


void __RPC_STUB IActMLCCG4A_ReadDeviceRandom_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActMLCCG4A_WriteDeviceRandom_Proxy( 
    IActMLCCG4A __RPC_FAR * This,
    /* [in] */ VARIANT varDeviceList,
    /* [in] */ VARIANT varSize,
    /* [in] */ VARIANT varData,
    /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);


void __RPC_STUB IActMLCCG4A_WriteDeviceRandom_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActMLCCG4A_ReadBuffer_Proxy( 
    IActMLCCG4A __RPC_FAR * This,
    /* [in] */ VARIANT varStartIO,
    /* [in] */ VARIANT varAddress,
    /* [in] */ VARIANT varReadSize,
    /* [out] */ VARIANT __RPC_FAR *lpvarData,
    /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);


void __RPC_STUB IActMLCCG4A_ReadBuffer_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActMLCCG4A_WriteBuffer_Proxy( 
    IActMLCCG4A __RPC_FAR * This,
    /* [in] */ VARIANT varStartIO,
    /* [in] */ VARIANT varAddress,
    /* [in] */ VARIANT varWriteSize,
    /* [in] */ VARIANT varData,
    /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);


void __RPC_STUB IActMLCCG4A_WriteBuffer_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActMLCCG4A_GetCpuType_Proxy( 
    IActMLCCG4A __RPC_FAR * This,
    /* [out] */ VARIANT __RPC_FAR *lpvarCpuName,
    /* [out] */ VARIANT __RPC_FAR *lpvarCpuType,
    /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);


void __RPC_STUB IActMLCCG4A_GetCpuType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActMLCCG4A_SetCpuStatus_Proxy( 
    IActMLCCG4A __RPC_FAR * This,
    /* [in] */ VARIANT varOperation,
    /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);


void __RPC_STUB IActMLCCG4A_SetCpuStatus_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActMLCCG4A_GetClockData_Proxy( 
    IActMLCCG4A __RPC_FAR * This,
    /* [out] */ VARIANT __RPC_FAR *lpvarYear,
    /* [out] */ VARIANT __RPC_FAR *lpvarMonth,
    /* [out] */ VARIANT __RPC_FAR *lpvarDay,
    /* [out] */ VARIANT __RPC_FAR *lpvarDayOfWeek,
    /* [out] */ VARIANT __RPC_FAR *lpvarHour,
    /* [out] */ VARIANT __RPC_FAR *lpvarMinute,
    /* [out] */ VARIANT __RPC_FAR *lpvarSecond,
    /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);


void __RPC_STUB IActMLCCG4A_GetClockData_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActMLCCG4A_SetClockData_Proxy( 
    IActMLCCG4A __RPC_FAR * This,
    /* [in] */ VARIANT varYear,
    /* [in] */ VARIANT varMonth,
    /* [in] */ VARIANT varDay,
    /* [in] */ VARIANT varDayOfWeek,
    /* [in] */ VARIANT varHour,
    /* [in] */ VARIANT varMinute,
    /* [in] */ VARIANT varSecond,
    /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);


void __RPC_STUB IActMLCCG4A_SetClockData_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActMLCCG4A_EntryDeviceStatus_Proxy( 
    IActMLCCG4A __RPC_FAR * This,
    /* [in] */ VARIANT varDeviceList,
    /* [in] */ VARIANT varSize,
    /* [in] */ VARIANT varMonitorCycle,
    /* [in] */ VARIANT varData,
    /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);


void __RPC_STUB IActMLCCG4A_EntryDeviceStatus_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActMLCCG4A_get_ActStationNumber_Proxy( 
    IActMLCCG4A __RPC_FAR * This,
    /* [retval][out] */ VARIANT __RPC_FAR *pVal);


void __RPC_STUB IActMLCCG4A_get_ActStationNumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActMLCCG4A_put_ActStationNumber_Proxy( 
    IActMLCCG4A __RPC_FAR * This,
    /* [in] */ VARIANT newVal);


void __RPC_STUB IActMLCCG4A_put_ActStationNumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActMLCCG4A_get_ActCpuType_Proxy( 
    IActMLCCG4A __RPC_FAR * This,
    /* [retval][out] */ VARIANT __RPC_FAR *pVal);


void __RPC_STUB IActMLCCG4A_get_ActCpuType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActMLCCG4A_put_ActCpuType_Proxy( 
    IActMLCCG4A __RPC_FAR * This,
    /* [in] */ VARIANT newVal);


void __RPC_STUB IActMLCCG4A_put_ActCpuType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActMLCCG4A_get_ActPortNumber_Proxy( 
    IActMLCCG4A __RPC_FAR * This,
    /* [retval][out] */ VARIANT __RPC_FAR *pVal);


void __RPC_STUB IActMLCCG4A_get_ActPortNumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActMLCCG4A_put_ActPortNumber_Proxy( 
    IActMLCCG4A __RPC_FAR * This,
    /* [in] */ VARIANT newVal);


void __RPC_STUB IActMLCCG4A_put_ActPortNumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActMLCCG4A_get_ActControl_Proxy( 
    IActMLCCG4A __RPC_FAR * This,
    /* [retval][out] */ VARIANT __RPC_FAR *pVal);


void __RPC_STUB IActMLCCG4A_get_ActControl_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActMLCCG4A_put_ActControl_Proxy( 
    IActMLCCG4A __RPC_FAR * This,
    /* [in] */ VARIANT newVal);


void __RPC_STUB IActMLCCG4A_put_ActControl_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActMLCCG4A_get_ActTimeOut_Proxy( 
    IActMLCCG4A __RPC_FAR * This,
    /* [retval][out] */ VARIANT __RPC_FAR *pVal);


void __RPC_STUB IActMLCCG4A_get_ActTimeOut_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActMLCCG4A_put_ActTimeOut_Proxy( 
    IActMLCCG4A __RPC_FAR * This,
    /* [in] */ VARIANT newVal);


void __RPC_STUB IActMLCCG4A_put_ActTimeOut_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActMLCCG4A_FreeDeviceStatus_Proxy( 
    IActMLCCG4A __RPC_FAR * This,
    /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);


void __RPC_STUB IActMLCCG4A_FreeDeviceStatus_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IActMLCCG4A_INTERFACE_DEFINED__ */


#ifndef __IActMLCCG4A2_INTERFACE_DEFINED__
#define __IActMLCCG4A2_INTERFACE_DEFINED__

/* interface IActMLCCG4A2 */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IActMLCCG4A2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("87166040-710B-11d5-9318-009099244EFD")
    IActMLCCG4A2 : public IActMLCCG4A
    {
    public:
    };
    
#else 	/* C style interface */

    typedef struct IActMLCCG4A2Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IActMLCCG4A2 __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IActMLCCG4A2 __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IActMLCCG4A2 __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IActMLCCG4A2 __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IActMLCCG4A2 __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IActMLCCG4A2 __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IActMLCCG4A2 __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Open )( 
            IActMLCCG4A2 __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Close )( 
            IActMLCCG4A2 __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetDevice )( 
            IActMLCCG4A2 __RPC_FAR * This,
            /* [in] */ VARIANT varDevice,
            /* [out] */ VARIANT __RPC_FAR *lpvarData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetDevice )( 
            IActMLCCG4A2 __RPC_FAR * This,
            /* [in] */ VARIANT varDevice,
            /* [in] */ VARIANT varData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceBlock )( 
            IActMLCCG4A2 __RPC_FAR * This,
            /* [in] */ VARIANT varDevice,
            /* [in] */ VARIANT varSize,
            /* [out] */ VARIANT __RPC_FAR *lpvarData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceBlock )( 
            IActMLCCG4A2 __RPC_FAR * This,
            /* [in] */ VARIANT varDevice,
            /* [in] */ VARIANT varSize,
            /* [in] */ VARIANT varData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceRandom )( 
            IActMLCCG4A2 __RPC_FAR * This,
            /* [in] */ VARIANT varDeviceList,
            /* [in] */ VARIANT varSize,
            /* [out] */ VARIANT __RPC_FAR *lpvarData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceRandom )( 
            IActMLCCG4A2 __RPC_FAR * This,
            /* [in] */ VARIANT varDeviceList,
            /* [in] */ VARIANT varSize,
            /* [in] */ VARIANT varData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadBuffer )( 
            IActMLCCG4A2 __RPC_FAR * This,
            /* [in] */ VARIANT varStartIO,
            /* [in] */ VARIANT varAddress,
            /* [in] */ VARIANT varReadSize,
            /* [out] */ VARIANT __RPC_FAR *lpvarData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteBuffer )( 
            IActMLCCG4A2 __RPC_FAR * This,
            /* [in] */ VARIANT varStartIO,
            /* [in] */ VARIANT varAddress,
            /* [in] */ VARIANT varWriteSize,
            /* [in] */ VARIANT varData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetCpuType )( 
            IActMLCCG4A2 __RPC_FAR * This,
            /* [out] */ VARIANT __RPC_FAR *lpvarCpuName,
            /* [out] */ VARIANT __RPC_FAR *lpvarCpuType,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetCpuStatus )( 
            IActMLCCG4A2 __RPC_FAR * This,
            /* [in] */ VARIANT varOperation,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetClockData )( 
            IActMLCCG4A2 __RPC_FAR * This,
            /* [out] */ VARIANT __RPC_FAR *lpvarYear,
            /* [out] */ VARIANT __RPC_FAR *lpvarMonth,
            /* [out] */ VARIANT __RPC_FAR *lpvarDay,
            /* [out] */ VARIANT __RPC_FAR *lpvarDayOfWeek,
            /* [out] */ VARIANT __RPC_FAR *lpvarHour,
            /* [out] */ VARIANT __RPC_FAR *lpvarMinute,
            /* [out] */ VARIANT __RPC_FAR *lpvarSecond,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetClockData )( 
            IActMLCCG4A2 __RPC_FAR * This,
            /* [in] */ VARIANT varYear,
            /* [in] */ VARIANT varMonth,
            /* [in] */ VARIANT varDay,
            /* [in] */ VARIANT varDayOfWeek,
            /* [in] */ VARIANT varHour,
            /* [in] */ VARIANT varMinute,
            /* [in] */ VARIANT varSecond,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *EntryDeviceStatus )( 
            IActMLCCG4A2 __RPC_FAR * This,
            /* [in] */ VARIANT varDeviceList,
            /* [in] */ VARIANT varSize,
            /* [in] */ VARIANT varMonitorCycle,
            /* [in] */ VARIANT varData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActStationNumber )( 
            IActMLCCG4A2 __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActStationNumber )( 
            IActMLCCG4A2 __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActCpuType )( 
            IActMLCCG4A2 __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActCpuType )( 
            IActMLCCG4A2 __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActPortNumber )( 
            IActMLCCG4A2 __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActPortNumber )( 
            IActMLCCG4A2 __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActControl )( 
            IActMLCCG4A2 __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActControl )( 
            IActMLCCG4A2 __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActTimeOut )( 
            IActMLCCG4A2 __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActTimeOut )( 
            IActMLCCG4A2 __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *FreeDeviceStatus )( 
            IActMLCCG4A2 __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        END_INTERFACE
    } IActMLCCG4A2Vtbl;

    interface IActMLCCG4A2
    {
        CONST_VTBL struct IActMLCCG4A2Vtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IActMLCCG4A2_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IActMLCCG4A2_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IActMLCCG4A2_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IActMLCCG4A2_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IActMLCCG4A2_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IActMLCCG4A2_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IActMLCCG4A2_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IActMLCCG4A2_Open(This,lpvarReturnCode)	\
    (This)->lpVtbl -> Open(This,lpvarReturnCode)

#define IActMLCCG4A2_Close(This,lpvarReturnCode)	\
    (This)->lpVtbl -> Close(This,lpvarReturnCode)

#define IActMLCCG4A2_GetDevice(This,varDevice,lpvarData,lpvarReturnCode)	\
    (This)->lpVtbl -> GetDevice(This,varDevice,lpvarData,lpvarReturnCode)

#define IActMLCCG4A2_SetDevice(This,varDevice,varData,lpvarReturnCode)	\
    (This)->lpVtbl -> SetDevice(This,varDevice,varData,lpvarReturnCode)

#define IActMLCCG4A2_ReadDeviceBlock(This,varDevice,varSize,lpvarData,lpvarReturnCode)	\
    (This)->lpVtbl -> ReadDeviceBlock(This,varDevice,varSize,lpvarData,lpvarReturnCode)

#define IActMLCCG4A2_WriteDeviceBlock(This,varDevice,varSize,varData,lpvarReturnCode)	\
    (This)->lpVtbl -> WriteDeviceBlock(This,varDevice,varSize,varData,lpvarReturnCode)

#define IActMLCCG4A2_ReadDeviceRandom(This,varDeviceList,varSize,lpvarData,lpvarReturnCode)	\
    (This)->lpVtbl -> ReadDeviceRandom(This,varDeviceList,varSize,lpvarData,lpvarReturnCode)

#define IActMLCCG4A2_WriteDeviceRandom(This,varDeviceList,varSize,varData,lpvarReturnCode)	\
    (This)->lpVtbl -> WriteDeviceRandom(This,varDeviceList,varSize,varData,lpvarReturnCode)

#define IActMLCCG4A2_ReadBuffer(This,varStartIO,varAddress,varReadSize,lpvarData,lpvarReturnCode)	\
    (This)->lpVtbl -> ReadBuffer(This,varStartIO,varAddress,varReadSize,lpvarData,lpvarReturnCode)

#define IActMLCCG4A2_WriteBuffer(This,varStartIO,varAddress,varWriteSize,varData,lpvarReturnCode)	\
    (This)->lpVtbl -> WriteBuffer(This,varStartIO,varAddress,varWriteSize,varData,lpvarReturnCode)

#define IActMLCCG4A2_GetCpuType(This,lpvarCpuName,lpvarCpuType,lpvarReturnCode)	\
    (This)->lpVtbl -> GetCpuType(This,lpvarCpuName,lpvarCpuType,lpvarReturnCode)

#define IActMLCCG4A2_SetCpuStatus(This,varOperation,lpvarReturnCode)	\
    (This)->lpVtbl -> SetCpuStatus(This,varOperation,lpvarReturnCode)

#define IActMLCCG4A2_GetClockData(This,lpvarYear,lpvarMonth,lpvarDay,lpvarDayOfWeek,lpvarHour,lpvarMinute,lpvarSecond,lpvarReturnCode)	\
    (This)->lpVtbl -> GetClockData(This,lpvarYear,lpvarMonth,lpvarDay,lpvarDayOfWeek,lpvarHour,lpvarMinute,lpvarSecond,lpvarReturnCode)

#define IActMLCCG4A2_SetClockData(This,varYear,varMonth,varDay,varDayOfWeek,varHour,varMinute,varSecond,lpvarReturnCode)	\
    (This)->lpVtbl -> SetClockData(This,varYear,varMonth,varDay,varDayOfWeek,varHour,varMinute,varSecond,lpvarReturnCode)

#define IActMLCCG4A2_EntryDeviceStatus(This,varDeviceList,varSize,varMonitorCycle,varData,lpvarReturnCode)	\
    (This)->lpVtbl -> EntryDeviceStatus(This,varDeviceList,varSize,varMonitorCycle,varData,lpvarReturnCode)

#define IActMLCCG4A2_get_ActStationNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActStationNumber(This,pVal)

#define IActMLCCG4A2_put_ActStationNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActStationNumber(This,newVal)

#define IActMLCCG4A2_get_ActCpuType(This,pVal)	\
    (This)->lpVtbl -> get_ActCpuType(This,pVal)

#define IActMLCCG4A2_put_ActCpuType(This,newVal)	\
    (This)->lpVtbl -> put_ActCpuType(This,newVal)

#define IActMLCCG4A2_get_ActPortNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActPortNumber(This,pVal)

#define IActMLCCG4A2_put_ActPortNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActPortNumber(This,newVal)

#define IActMLCCG4A2_get_ActControl(This,pVal)	\
    (This)->lpVtbl -> get_ActControl(This,pVal)

#define IActMLCCG4A2_put_ActControl(This,newVal)	\
    (This)->lpVtbl -> put_ActControl(This,newVal)

#define IActMLCCG4A2_get_ActTimeOut(This,pVal)	\
    (This)->lpVtbl -> get_ActTimeOut(This,pVal)

#define IActMLCCG4A2_put_ActTimeOut(This,newVal)	\
    (This)->lpVtbl -> put_ActTimeOut(This,newVal)

#define IActMLCCG4A2_FreeDeviceStatus(This,lpvarReturnCode)	\
    (This)->lpVtbl -> FreeDeviceStatus(This,lpvarReturnCode)


#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IActMLCCG4A2_INTERFACE_DEFINED__ */


#ifndef __IActMLCCG4A3_INTERFACE_DEFINED__
#define __IActMLCCG4A3_INTERFACE_DEFINED__

/* interface IActMLCCG4A3 */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IActMLCCG4A3;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("115992F7-6EC2-11d5-9314-009099244EFD")
    IActMLCCG4A3 : public IActMLCCG4A2
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

    typedef struct IActMLCCG4A3Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IActMLCCG4A3 __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IActMLCCG4A3 __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IActMLCCG4A3 __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IActMLCCG4A3 __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IActMLCCG4A3 __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IActMLCCG4A3 __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IActMLCCG4A3 __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Open )( 
            IActMLCCG4A3 __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Close )( 
            IActMLCCG4A3 __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetDevice )( 
            IActMLCCG4A3 __RPC_FAR * This,
            /* [in] */ VARIANT varDevice,
            /* [out] */ VARIANT __RPC_FAR *lpvarData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetDevice )( 
            IActMLCCG4A3 __RPC_FAR * This,
            /* [in] */ VARIANT varDevice,
            /* [in] */ VARIANT varData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceBlock )( 
            IActMLCCG4A3 __RPC_FAR * This,
            /* [in] */ VARIANT varDevice,
            /* [in] */ VARIANT varSize,
            /* [out] */ VARIANT __RPC_FAR *lpvarData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceBlock )( 
            IActMLCCG4A3 __RPC_FAR * This,
            /* [in] */ VARIANT varDevice,
            /* [in] */ VARIANT varSize,
            /* [in] */ VARIANT varData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceRandom )( 
            IActMLCCG4A3 __RPC_FAR * This,
            /* [in] */ VARIANT varDeviceList,
            /* [in] */ VARIANT varSize,
            /* [out] */ VARIANT __RPC_FAR *lpvarData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceRandom )( 
            IActMLCCG4A3 __RPC_FAR * This,
            /* [in] */ VARIANT varDeviceList,
            /* [in] */ VARIANT varSize,
            /* [in] */ VARIANT varData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadBuffer )( 
            IActMLCCG4A3 __RPC_FAR * This,
            /* [in] */ VARIANT varStartIO,
            /* [in] */ VARIANT varAddress,
            /* [in] */ VARIANT varReadSize,
            /* [out] */ VARIANT __RPC_FAR *lpvarData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteBuffer )( 
            IActMLCCG4A3 __RPC_FAR * This,
            /* [in] */ VARIANT varStartIO,
            /* [in] */ VARIANT varAddress,
            /* [in] */ VARIANT varWriteSize,
            /* [in] */ VARIANT varData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetCpuType )( 
            IActMLCCG4A3 __RPC_FAR * This,
            /* [out] */ VARIANT __RPC_FAR *lpvarCpuName,
            /* [out] */ VARIANT __RPC_FAR *lpvarCpuType,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetCpuStatus )( 
            IActMLCCG4A3 __RPC_FAR * This,
            /* [in] */ VARIANT varOperation,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetClockData )( 
            IActMLCCG4A3 __RPC_FAR * This,
            /* [out] */ VARIANT __RPC_FAR *lpvarYear,
            /* [out] */ VARIANT __RPC_FAR *lpvarMonth,
            /* [out] */ VARIANT __RPC_FAR *lpvarDay,
            /* [out] */ VARIANT __RPC_FAR *lpvarDayOfWeek,
            /* [out] */ VARIANT __RPC_FAR *lpvarHour,
            /* [out] */ VARIANT __RPC_FAR *lpvarMinute,
            /* [out] */ VARIANT __RPC_FAR *lpvarSecond,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetClockData )( 
            IActMLCCG4A3 __RPC_FAR * This,
            /* [in] */ VARIANT varYear,
            /* [in] */ VARIANT varMonth,
            /* [in] */ VARIANT varDay,
            /* [in] */ VARIANT varDayOfWeek,
            /* [in] */ VARIANT varHour,
            /* [in] */ VARIANT varMinute,
            /* [in] */ VARIANT varSecond,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *EntryDeviceStatus )( 
            IActMLCCG4A3 __RPC_FAR * This,
            /* [in] */ VARIANT varDeviceList,
            /* [in] */ VARIANT varSize,
            /* [in] */ VARIANT varMonitorCycle,
            /* [in] */ VARIANT varData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActStationNumber )( 
            IActMLCCG4A3 __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActStationNumber )( 
            IActMLCCG4A3 __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActCpuType )( 
            IActMLCCG4A3 __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActCpuType )( 
            IActMLCCG4A3 __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActPortNumber )( 
            IActMLCCG4A3 __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActPortNumber )( 
            IActMLCCG4A3 __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActControl )( 
            IActMLCCG4A3 __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActControl )( 
            IActMLCCG4A3 __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActTimeOut )( 
            IActMLCCG4A3 __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActTimeOut )( 
            IActMLCCG4A3 __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *FreeDeviceStatus )( 
            IActMLCCG4A3 __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceBlock2 )( 
            IActMLCCG4A3 __RPC_FAR * This,
            /* [in] */ VARIANT varDevice,
            /* [in] */ VARIANT varSize,
            /* [out] */ VARIANT __RPC_FAR *lpvarData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceBlock2 )( 
            IActMLCCG4A3 __RPC_FAR * This,
            /* [in] */ VARIANT varDevice,
            /* [in] */ VARIANT varSize,
            /* [in] */ VARIANT varData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceRandom2 )( 
            IActMLCCG4A3 __RPC_FAR * This,
            /* [in] */ VARIANT varDeviceList,
            /* [in] */ VARIANT varSize,
            /* [out] */ VARIANT __RPC_FAR *lpvarData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceRandom2 )( 
            IActMLCCG4A3 __RPC_FAR * This,
            /* [in] */ VARIANT varDeviceList,
            /* [in] */ VARIANT varSize,
            /* [in] */ VARIANT varData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetDevice2 )( 
            IActMLCCG4A3 __RPC_FAR * This,
            /* [in] */ VARIANT varDevice,
            /* [out] */ VARIANT __RPC_FAR *lpvarData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetDevice2 )( 
            IActMLCCG4A3 __RPC_FAR * This,
            /* [in] */ VARIANT varDevice,
            /* [in] */ VARIANT varData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        END_INTERFACE
    } IActMLCCG4A3Vtbl;

    interface IActMLCCG4A3
    {
        CONST_VTBL struct IActMLCCG4A3Vtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IActMLCCG4A3_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IActMLCCG4A3_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IActMLCCG4A3_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IActMLCCG4A3_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IActMLCCG4A3_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IActMLCCG4A3_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IActMLCCG4A3_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IActMLCCG4A3_Open(This,lpvarReturnCode)	\
    (This)->lpVtbl -> Open(This,lpvarReturnCode)

#define IActMLCCG4A3_Close(This,lpvarReturnCode)	\
    (This)->lpVtbl -> Close(This,lpvarReturnCode)

#define IActMLCCG4A3_GetDevice(This,varDevice,lpvarData,lpvarReturnCode)	\
    (This)->lpVtbl -> GetDevice(This,varDevice,lpvarData,lpvarReturnCode)

#define IActMLCCG4A3_SetDevice(This,varDevice,varData,lpvarReturnCode)	\
    (This)->lpVtbl -> SetDevice(This,varDevice,varData,lpvarReturnCode)

#define IActMLCCG4A3_ReadDeviceBlock(This,varDevice,varSize,lpvarData,lpvarReturnCode)	\
    (This)->lpVtbl -> ReadDeviceBlock(This,varDevice,varSize,lpvarData,lpvarReturnCode)

#define IActMLCCG4A3_WriteDeviceBlock(This,varDevice,varSize,varData,lpvarReturnCode)	\
    (This)->lpVtbl -> WriteDeviceBlock(This,varDevice,varSize,varData,lpvarReturnCode)

#define IActMLCCG4A3_ReadDeviceRandom(This,varDeviceList,varSize,lpvarData,lpvarReturnCode)	\
    (This)->lpVtbl -> ReadDeviceRandom(This,varDeviceList,varSize,lpvarData,lpvarReturnCode)

#define IActMLCCG4A3_WriteDeviceRandom(This,varDeviceList,varSize,varData,lpvarReturnCode)	\
    (This)->lpVtbl -> WriteDeviceRandom(This,varDeviceList,varSize,varData,lpvarReturnCode)

#define IActMLCCG4A3_ReadBuffer(This,varStartIO,varAddress,varReadSize,lpvarData,lpvarReturnCode)	\
    (This)->lpVtbl -> ReadBuffer(This,varStartIO,varAddress,varReadSize,lpvarData,lpvarReturnCode)

#define IActMLCCG4A3_WriteBuffer(This,varStartIO,varAddress,varWriteSize,varData,lpvarReturnCode)	\
    (This)->lpVtbl -> WriteBuffer(This,varStartIO,varAddress,varWriteSize,varData,lpvarReturnCode)

#define IActMLCCG4A3_GetCpuType(This,lpvarCpuName,lpvarCpuType,lpvarReturnCode)	\
    (This)->lpVtbl -> GetCpuType(This,lpvarCpuName,lpvarCpuType,lpvarReturnCode)

#define IActMLCCG4A3_SetCpuStatus(This,varOperation,lpvarReturnCode)	\
    (This)->lpVtbl -> SetCpuStatus(This,varOperation,lpvarReturnCode)

#define IActMLCCG4A3_GetClockData(This,lpvarYear,lpvarMonth,lpvarDay,lpvarDayOfWeek,lpvarHour,lpvarMinute,lpvarSecond,lpvarReturnCode)	\
    (This)->lpVtbl -> GetClockData(This,lpvarYear,lpvarMonth,lpvarDay,lpvarDayOfWeek,lpvarHour,lpvarMinute,lpvarSecond,lpvarReturnCode)

#define IActMLCCG4A3_SetClockData(This,varYear,varMonth,varDay,varDayOfWeek,varHour,varMinute,varSecond,lpvarReturnCode)	\
    (This)->lpVtbl -> SetClockData(This,varYear,varMonth,varDay,varDayOfWeek,varHour,varMinute,varSecond,lpvarReturnCode)

#define IActMLCCG4A3_EntryDeviceStatus(This,varDeviceList,varSize,varMonitorCycle,varData,lpvarReturnCode)	\
    (This)->lpVtbl -> EntryDeviceStatus(This,varDeviceList,varSize,varMonitorCycle,varData,lpvarReturnCode)

#define IActMLCCG4A3_get_ActStationNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActStationNumber(This,pVal)

#define IActMLCCG4A3_put_ActStationNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActStationNumber(This,newVal)

#define IActMLCCG4A3_get_ActCpuType(This,pVal)	\
    (This)->lpVtbl -> get_ActCpuType(This,pVal)

#define IActMLCCG4A3_put_ActCpuType(This,newVal)	\
    (This)->lpVtbl -> put_ActCpuType(This,newVal)

#define IActMLCCG4A3_get_ActPortNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActPortNumber(This,pVal)

#define IActMLCCG4A3_put_ActPortNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActPortNumber(This,newVal)

#define IActMLCCG4A3_get_ActControl(This,pVal)	\
    (This)->lpVtbl -> get_ActControl(This,pVal)

#define IActMLCCG4A3_put_ActControl(This,newVal)	\
    (This)->lpVtbl -> put_ActControl(This,newVal)

#define IActMLCCG4A3_get_ActTimeOut(This,pVal)	\
    (This)->lpVtbl -> get_ActTimeOut(This,pVal)

#define IActMLCCG4A3_put_ActTimeOut(This,newVal)	\
    (This)->lpVtbl -> put_ActTimeOut(This,newVal)

#define IActMLCCG4A3_FreeDeviceStatus(This,lpvarReturnCode)	\
    (This)->lpVtbl -> FreeDeviceStatus(This,lpvarReturnCode)



#define IActMLCCG4A3_ReadDeviceBlock2(This,varDevice,varSize,lpvarData,lpvarReturnCode)	\
    (This)->lpVtbl -> ReadDeviceBlock2(This,varDevice,varSize,lpvarData,lpvarReturnCode)

#define IActMLCCG4A3_WriteDeviceBlock2(This,varDevice,varSize,varData,lpvarReturnCode)	\
    (This)->lpVtbl -> WriteDeviceBlock2(This,varDevice,varSize,varData,lpvarReturnCode)

#define IActMLCCG4A3_ReadDeviceRandom2(This,varDeviceList,varSize,lpvarData,lpvarReturnCode)	\
    (This)->lpVtbl -> ReadDeviceRandom2(This,varDeviceList,varSize,lpvarData,lpvarReturnCode)

#define IActMLCCG4A3_WriteDeviceRandom2(This,varDeviceList,varSize,varData,lpvarReturnCode)	\
    (This)->lpVtbl -> WriteDeviceRandom2(This,varDeviceList,varSize,varData,lpvarReturnCode)

#define IActMLCCG4A3_GetDevice2(This,varDevice,lpvarData,lpvarReturnCode)	\
    (This)->lpVtbl -> GetDevice2(This,varDevice,lpvarData,lpvarReturnCode)

#define IActMLCCG4A3_SetDevice2(This,varDevice,varData,lpvarReturnCode)	\
    (This)->lpVtbl -> SetDevice2(This,varDevice,varData,lpvarReturnCode)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActMLCCG4A3_ReadDeviceBlock2_Proxy( 
    IActMLCCG4A3 __RPC_FAR * This,
    /* [in] */ VARIANT varDevice,
    /* [in] */ VARIANT varSize,
    /* [out] */ VARIANT __RPC_FAR *lpvarData,
    /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);


void __RPC_STUB IActMLCCG4A3_ReadDeviceBlock2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActMLCCG4A3_WriteDeviceBlock2_Proxy( 
    IActMLCCG4A3 __RPC_FAR * This,
    /* [in] */ VARIANT varDevice,
    /* [in] */ VARIANT varSize,
    /* [in] */ VARIANT varData,
    /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);


void __RPC_STUB IActMLCCG4A3_WriteDeviceBlock2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActMLCCG4A3_ReadDeviceRandom2_Proxy( 
    IActMLCCG4A3 __RPC_FAR * This,
    /* [in] */ VARIANT varDeviceList,
    /* [in] */ VARIANT varSize,
    /* [out] */ VARIANT __RPC_FAR *lpvarData,
    /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);


void __RPC_STUB IActMLCCG4A3_ReadDeviceRandom2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActMLCCG4A3_WriteDeviceRandom2_Proxy( 
    IActMLCCG4A3 __RPC_FAR * This,
    /* [in] */ VARIANT varDeviceList,
    /* [in] */ VARIANT varSize,
    /* [in] */ VARIANT varData,
    /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);


void __RPC_STUB IActMLCCG4A3_WriteDeviceRandom2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActMLCCG4A3_GetDevice2_Proxy( 
    IActMLCCG4A3 __RPC_FAR * This,
    /* [in] */ VARIANT varDevice,
    /* [out] */ VARIANT __RPC_FAR *lpvarData,
    /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);


void __RPC_STUB IActMLCCG4A3_GetDevice2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActMLCCG4A3_SetDevice2_Proxy( 
    IActMLCCG4A3 __RPC_FAR * This,
    /* [in] */ VARIANT varDevice,
    /* [in] */ VARIANT varData,
    /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);


void __RPC_STUB IActMLCCG4A3_SetDevice2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IActMLCCG4A3_INTERFACE_DEFINED__ */


#ifndef __IActMLCCG4QnA_INTERFACE_DEFINED__
#define __IActMLCCG4QnA_INTERFACE_DEFINED__

/* interface IActMLCCG4QnA */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IActMLCCG4QnA;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("29BD6548-A98F-11D4-910D-009099244EFD")
    IActMLCCG4QnA : public IDispatch
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
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActConnectUnitNumber( 
            /* [retval][out] */ VARIANT __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActConnectUnitNumber( 
            /* [in] */ VARIANT newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActIONumber( 
            /* [retval][out] */ VARIANT __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActIONumber( 
            /* [in] */ VARIANT newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActCpuType( 
            /* [retval][out] */ VARIANT __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActCpuType( 
            /* [in] */ VARIANT newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActPortNumber( 
            /* [retval][out] */ VARIANT __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActPortNumber( 
            /* [in] */ VARIANT newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActBaudRate( 
            /* [retval][out] */ VARIANT __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActBaudRate( 
            /* [in] */ VARIANT newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActControl( 
            /* [retval][out] */ VARIANT __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActControl( 
            /* [in] */ VARIANT newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActTimeOut( 
            /* [retval][out] */ VARIANT __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActTimeOut( 
            /* [in] */ VARIANT newVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE FreeDeviceStatus( 
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IActMLCCG4QnAVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IActMLCCG4QnA __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IActMLCCG4QnA __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IActMLCCG4QnA __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IActMLCCG4QnA __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IActMLCCG4QnA __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IActMLCCG4QnA __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IActMLCCG4QnA __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Open )( 
            IActMLCCG4QnA __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Close )( 
            IActMLCCG4QnA __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetDevice )( 
            IActMLCCG4QnA __RPC_FAR * This,
            /* [in] */ VARIANT varDevice,
            /* [out] */ VARIANT __RPC_FAR *lpvarData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetDevice )( 
            IActMLCCG4QnA __RPC_FAR * This,
            /* [in] */ VARIANT varDevice,
            /* [in] */ VARIANT varData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceBlock )( 
            IActMLCCG4QnA __RPC_FAR * This,
            /* [in] */ VARIANT varDevice,
            /* [in] */ VARIANT varSize,
            /* [out] */ VARIANT __RPC_FAR *lpvarData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceBlock )( 
            IActMLCCG4QnA __RPC_FAR * This,
            /* [in] */ VARIANT varDevice,
            /* [in] */ VARIANT varSize,
            /* [in] */ VARIANT varData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceRandom )( 
            IActMLCCG4QnA __RPC_FAR * This,
            /* [in] */ VARIANT varDeviceList,
            /* [in] */ VARIANT varSize,
            /* [out] */ VARIANT __RPC_FAR *lpvarData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceRandom )( 
            IActMLCCG4QnA __RPC_FAR * This,
            /* [in] */ VARIANT varDeviceList,
            /* [in] */ VARIANT varSize,
            /* [in] */ VARIANT varData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadBuffer )( 
            IActMLCCG4QnA __RPC_FAR * This,
            /* [in] */ VARIANT varStartIO,
            /* [in] */ VARIANT varAddress,
            /* [in] */ VARIANT varReadSize,
            /* [out] */ VARIANT __RPC_FAR *lpvarData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteBuffer )( 
            IActMLCCG4QnA __RPC_FAR * This,
            /* [in] */ VARIANT varStartIO,
            /* [in] */ VARIANT varAddress,
            /* [in] */ VARIANT varWriteSize,
            /* [in] */ VARIANT varData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetCpuType )( 
            IActMLCCG4QnA __RPC_FAR * This,
            /* [out] */ VARIANT __RPC_FAR *lpvarCpuName,
            /* [out] */ VARIANT __RPC_FAR *lpvarCpuType,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetCpuStatus )( 
            IActMLCCG4QnA __RPC_FAR * This,
            /* [in] */ VARIANT varOperation,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetClockData )( 
            IActMLCCG4QnA __RPC_FAR * This,
            /* [out] */ VARIANT __RPC_FAR *lpvarYear,
            /* [out] */ VARIANT __RPC_FAR *lpvarMonth,
            /* [out] */ VARIANT __RPC_FAR *lpvarDay,
            /* [out] */ VARIANT __RPC_FAR *lpvarDayOfWeek,
            /* [out] */ VARIANT __RPC_FAR *lpvarHour,
            /* [out] */ VARIANT __RPC_FAR *lpvarMinute,
            /* [out] */ VARIANT __RPC_FAR *lpvarSecond,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetClockData )( 
            IActMLCCG4QnA __RPC_FAR * This,
            /* [in] */ VARIANT varYear,
            /* [in] */ VARIANT varMonth,
            /* [in] */ VARIANT varDay,
            /* [in] */ VARIANT varDayOfWeek,
            /* [in] */ VARIANT varHour,
            /* [in] */ VARIANT varMinute,
            /* [in] */ VARIANT varSecond,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *EntryDeviceStatus )( 
            IActMLCCG4QnA __RPC_FAR * This,
            /* [in] */ VARIANT varDeviceList,
            /* [in] */ VARIANT varSize,
            /* [in] */ VARIANT varMonitorCycle,
            /* [in] */ VARIANT varData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActNetworkNumber )( 
            IActMLCCG4QnA __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActNetworkNumber )( 
            IActMLCCG4QnA __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActStationNumber )( 
            IActMLCCG4QnA __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActStationNumber )( 
            IActMLCCG4QnA __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActUnitNumber )( 
            IActMLCCG4QnA __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActUnitNumber )( 
            IActMLCCG4QnA __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActConnectUnitNumber )( 
            IActMLCCG4QnA __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActConnectUnitNumber )( 
            IActMLCCG4QnA __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActIONumber )( 
            IActMLCCG4QnA __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActIONumber )( 
            IActMLCCG4QnA __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActCpuType )( 
            IActMLCCG4QnA __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActCpuType )( 
            IActMLCCG4QnA __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActPortNumber )( 
            IActMLCCG4QnA __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActPortNumber )( 
            IActMLCCG4QnA __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActBaudRate )( 
            IActMLCCG4QnA __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActBaudRate )( 
            IActMLCCG4QnA __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActControl )( 
            IActMLCCG4QnA __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActControl )( 
            IActMLCCG4QnA __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActTimeOut )( 
            IActMLCCG4QnA __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActTimeOut )( 
            IActMLCCG4QnA __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *FreeDeviceStatus )( 
            IActMLCCG4QnA __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        END_INTERFACE
    } IActMLCCG4QnAVtbl;

    interface IActMLCCG4QnA
    {
        CONST_VTBL struct IActMLCCG4QnAVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IActMLCCG4QnA_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IActMLCCG4QnA_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IActMLCCG4QnA_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IActMLCCG4QnA_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IActMLCCG4QnA_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IActMLCCG4QnA_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IActMLCCG4QnA_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IActMLCCG4QnA_Open(This,lpvarReturnCode)	\
    (This)->lpVtbl -> Open(This,lpvarReturnCode)

#define IActMLCCG4QnA_Close(This,lpvarReturnCode)	\
    (This)->lpVtbl -> Close(This,lpvarReturnCode)

#define IActMLCCG4QnA_GetDevice(This,varDevice,lpvarData,lpvarReturnCode)	\
    (This)->lpVtbl -> GetDevice(This,varDevice,lpvarData,lpvarReturnCode)

#define IActMLCCG4QnA_SetDevice(This,varDevice,varData,lpvarReturnCode)	\
    (This)->lpVtbl -> SetDevice(This,varDevice,varData,lpvarReturnCode)

#define IActMLCCG4QnA_ReadDeviceBlock(This,varDevice,varSize,lpvarData,lpvarReturnCode)	\
    (This)->lpVtbl -> ReadDeviceBlock(This,varDevice,varSize,lpvarData,lpvarReturnCode)

#define IActMLCCG4QnA_WriteDeviceBlock(This,varDevice,varSize,varData,lpvarReturnCode)	\
    (This)->lpVtbl -> WriteDeviceBlock(This,varDevice,varSize,varData,lpvarReturnCode)

#define IActMLCCG4QnA_ReadDeviceRandom(This,varDeviceList,varSize,lpvarData,lpvarReturnCode)	\
    (This)->lpVtbl -> ReadDeviceRandom(This,varDeviceList,varSize,lpvarData,lpvarReturnCode)

#define IActMLCCG4QnA_WriteDeviceRandom(This,varDeviceList,varSize,varData,lpvarReturnCode)	\
    (This)->lpVtbl -> WriteDeviceRandom(This,varDeviceList,varSize,varData,lpvarReturnCode)

#define IActMLCCG4QnA_ReadBuffer(This,varStartIO,varAddress,varReadSize,lpvarData,lpvarReturnCode)	\
    (This)->lpVtbl -> ReadBuffer(This,varStartIO,varAddress,varReadSize,lpvarData,lpvarReturnCode)

#define IActMLCCG4QnA_WriteBuffer(This,varStartIO,varAddress,varWriteSize,varData,lpvarReturnCode)	\
    (This)->lpVtbl -> WriteBuffer(This,varStartIO,varAddress,varWriteSize,varData,lpvarReturnCode)

#define IActMLCCG4QnA_GetCpuType(This,lpvarCpuName,lpvarCpuType,lpvarReturnCode)	\
    (This)->lpVtbl -> GetCpuType(This,lpvarCpuName,lpvarCpuType,lpvarReturnCode)

#define IActMLCCG4QnA_SetCpuStatus(This,varOperation,lpvarReturnCode)	\
    (This)->lpVtbl -> SetCpuStatus(This,varOperation,lpvarReturnCode)

#define IActMLCCG4QnA_GetClockData(This,lpvarYear,lpvarMonth,lpvarDay,lpvarDayOfWeek,lpvarHour,lpvarMinute,lpvarSecond,lpvarReturnCode)	\
    (This)->lpVtbl -> GetClockData(This,lpvarYear,lpvarMonth,lpvarDay,lpvarDayOfWeek,lpvarHour,lpvarMinute,lpvarSecond,lpvarReturnCode)

#define IActMLCCG4QnA_SetClockData(This,varYear,varMonth,varDay,varDayOfWeek,varHour,varMinute,varSecond,lpvarReturnCode)	\
    (This)->lpVtbl -> SetClockData(This,varYear,varMonth,varDay,varDayOfWeek,varHour,varMinute,varSecond,lpvarReturnCode)

#define IActMLCCG4QnA_EntryDeviceStatus(This,varDeviceList,varSize,varMonitorCycle,varData,lpvarReturnCode)	\
    (This)->lpVtbl -> EntryDeviceStatus(This,varDeviceList,varSize,varMonitorCycle,varData,lpvarReturnCode)

#define IActMLCCG4QnA_get_ActNetworkNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActNetworkNumber(This,pVal)

#define IActMLCCG4QnA_put_ActNetworkNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActNetworkNumber(This,newVal)

#define IActMLCCG4QnA_get_ActStationNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActStationNumber(This,pVal)

#define IActMLCCG4QnA_put_ActStationNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActStationNumber(This,newVal)

#define IActMLCCG4QnA_get_ActUnitNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActUnitNumber(This,pVal)

#define IActMLCCG4QnA_put_ActUnitNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActUnitNumber(This,newVal)

#define IActMLCCG4QnA_get_ActConnectUnitNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActConnectUnitNumber(This,pVal)

#define IActMLCCG4QnA_put_ActConnectUnitNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActConnectUnitNumber(This,newVal)

#define IActMLCCG4QnA_get_ActIONumber(This,pVal)	\
    (This)->lpVtbl -> get_ActIONumber(This,pVal)

#define IActMLCCG4QnA_put_ActIONumber(This,newVal)	\
    (This)->lpVtbl -> put_ActIONumber(This,newVal)

#define IActMLCCG4QnA_get_ActCpuType(This,pVal)	\
    (This)->lpVtbl -> get_ActCpuType(This,pVal)

#define IActMLCCG4QnA_put_ActCpuType(This,newVal)	\
    (This)->lpVtbl -> put_ActCpuType(This,newVal)

#define IActMLCCG4QnA_get_ActPortNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActPortNumber(This,pVal)

#define IActMLCCG4QnA_put_ActPortNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActPortNumber(This,newVal)

#define IActMLCCG4QnA_get_ActBaudRate(This,pVal)	\
    (This)->lpVtbl -> get_ActBaudRate(This,pVal)

#define IActMLCCG4QnA_put_ActBaudRate(This,newVal)	\
    (This)->lpVtbl -> put_ActBaudRate(This,newVal)

#define IActMLCCG4QnA_get_ActControl(This,pVal)	\
    (This)->lpVtbl -> get_ActControl(This,pVal)

#define IActMLCCG4QnA_put_ActControl(This,newVal)	\
    (This)->lpVtbl -> put_ActControl(This,newVal)

#define IActMLCCG4QnA_get_ActTimeOut(This,pVal)	\
    (This)->lpVtbl -> get_ActTimeOut(This,pVal)

#define IActMLCCG4QnA_put_ActTimeOut(This,newVal)	\
    (This)->lpVtbl -> put_ActTimeOut(This,newVal)

#define IActMLCCG4QnA_FreeDeviceStatus(This,lpvarReturnCode)	\
    (This)->lpVtbl -> FreeDeviceStatus(This,lpvarReturnCode)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActMLCCG4QnA_Open_Proxy( 
    IActMLCCG4QnA __RPC_FAR * This,
    /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);


void __RPC_STUB IActMLCCG4QnA_Open_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActMLCCG4QnA_Close_Proxy( 
    IActMLCCG4QnA __RPC_FAR * This,
    /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);


void __RPC_STUB IActMLCCG4QnA_Close_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActMLCCG4QnA_GetDevice_Proxy( 
    IActMLCCG4QnA __RPC_FAR * This,
    /* [in] */ VARIANT varDevice,
    /* [out] */ VARIANT __RPC_FAR *lpvarData,
    /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);


void __RPC_STUB IActMLCCG4QnA_GetDevice_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActMLCCG4QnA_SetDevice_Proxy( 
    IActMLCCG4QnA __RPC_FAR * This,
    /* [in] */ VARIANT varDevice,
    /* [in] */ VARIANT varData,
    /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);


void __RPC_STUB IActMLCCG4QnA_SetDevice_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActMLCCG4QnA_ReadDeviceBlock_Proxy( 
    IActMLCCG4QnA __RPC_FAR * This,
    /* [in] */ VARIANT varDevice,
    /* [in] */ VARIANT varSize,
    /* [out] */ VARIANT __RPC_FAR *lpvarData,
    /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);


void __RPC_STUB IActMLCCG4QnA_ReadDeviceBlock_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActMLCCG4QnA_WriteDeviceBlock_Proxy( 
    IActMLCCG4QnA __RPC_FAR * This,
    /* [in] */ VARIANT varDevice,
    /* [in] */ VARIANT varSize,
    /* [in] */ VARIANT varData,
    /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);


void __RPC_STUB IActMLCCG4QnA_WriteDeviceBlock_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActMLCCG4QnA_ReadDeviceRandom_Proxy( 
    IActMLCCG4QnA __RPC_FAR * This,
    /* [in] */ VARIANT varDeviceList,
    /* [in] */ VARIANT varSize,
    /* [out] */ VARIANT __RPC_FAR *lpvarData,
    /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);


void __RPC_STUB IActMLCCG4QnA_ReadDeviceRandom_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActMLCCG4QnA_WriteDeviceRandom_Proxy( 
    IActMLCCG4QnA __RPC_FAR * This,
    /* [in] */ VARIANT varDeviceList,
    /* [in] */ VARIANT varSize,
    /* [in] */ VARIANT varData,
    /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);


void __RPC_STUB IActMLCCG4QnA_WriteDeviceRandom_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActMLCCG4QnA_ReadBuffer_Proxy( 
    IActMLCCG4QnA __RPC_FAR * This,
    /* [in] */ VARIANT varStartIO,
    /* [in] */ VARIANT varAddress,
    /* [in] */ VARIANT varReadSize,
    /* [out] */ VARIANT __RPC_FAR *lpvarData,
    /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);


void __RPC_STUB IActMLCCG4QnA_ReadBuffer_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActMLCCG4QnA_WriteBuffer_Proxy( 
    IActMLCCG4QnA __RPC_FAR * This,
    /* [in] */ VARIANT varStartIO,
    /* [in] */ VARIANT varAddress,
    /* [in] */ VARIANT varWriteSize,
    /* [in] */ VARIANT varData,
    /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);


void __RPC_STUB IActMLCCG4QnA_WriteBuffer_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActMLCCG4QnA_GetCpuType_Proxy( 
    IActMLCCG4QnA __RPC_FAR * This,
    /* [out] */ VARIANT __RPC_FAR *lpvarCpuName,
    /* [out] */ VARIANT __RPC_FAR *lpvarCpuType,
    /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);


void __RPC_STUB IActMLCCG4QnA_GetCpuType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActMLCCG4QnA_SetCpuStatus_Proxy( 
    IActMLCCG4QnA __RPC_FAR * This,
    /* [in] */ VARIANT varOperation,
    /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);


void __RPC_STUB IActMLCCG4QnA_SetCpuStatus_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActMLCCG4QnA_GetClockData_Proxy( 
    IActMLCCG4QnA __RPC_FAR * This,
    /* [out] */ VARIANT __RPC_FAR *lpvarYear,
    /* [out] */ VARIANT __RPC_FAR *lpvarMonth,
    /* [out] */ VARIANT __RPC_FAR *lpvarDay,
    /* [out] */ VARIANT __RPC_FAR *lpvarDayOfWeek,
    /* [out] */ VARIANT __RPC_FAR *lpvarHour,
    /* [out] */ VARIANT __RPC_FAR *lpvarMinute,
    /* [out] */ VARIANT __RPC_FAR *lpvarSecond,
    /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);


void __RPC_STUB IActMLCCG4QnA_GetClockData_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActMLCCG4QnA_SetClockData_Proxy( 
    IActMLCCG4QnA __RPC_FAR * This,
    /* [in] */ VARIANT varYear,
    /* [in] */ VARIANT varMonth,
    /* [in] */ VARIANT varDay,
    /* [in] */ VARIANT varDayOfWeek,
    /* [in] */ VARIANT varHour,
    /* [in] */ VARIANT varMinute,
    /* [in] */ VARIANT varSecond,
    /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);


void __RPC_STUB IActMLCCG4QnA_SetClockData_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActMLCCG4QnA_EntryDeviceStatus_Proxy( 
    IActMLCCG4QnA __RPC_FAR * This,
    /* [in] */ VARIANT varDeviceList,
    /* [in] */ VARIANT varSize,
    /* [in] */ VARIANT varMonitorCycle,
    /* [in] */ VARIANT varData,
    /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);


void __RPC_STUB IActMLCCG4QnA_EntryDeviceStatus_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActMLCCG4QnA_get_ActNetworkNumber_Proxy( 
    IActMLCCG4QnA __RPC_FAR * This,
    /* [retval][out] */ VARIANT __RPC_FAR *pVal);


void __RPC_STUB IActMLCCG4QnA_get_ActNetworkNumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActMLCCG4QnA_put_ActNetworkNumber_Proxy( 
    IActMLCCG4QnA __RPC_FAR * This,
    /* [in] */ VARIANT newVal);


void __RPC_STUB IActMLCCG4QnA_put_ActNetworkNumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActMLCCG4QnA_get_ActStationNumber_Proxy( 
    IActMLCCG4QnA __RPC_FAR * This,
    /* [retval][out] */ VARIANT __RPC_FAR *pVal);


void __RPC_STUB IActMLCCG4QnA_get_ActStationNumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActMLCCG4QnA_put_ActStationNumber_Proxy( 
    IActMLCCG4QnA __RPC_FAR * This,
    /* [in] */ VARIANT newVal);


void __RPC_STUB IActMLCCG4QnA_put_ActStationNumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActMLCCG4QnA_get_ActUnitNumber_Proxy( 
    IActMLCCG4QnA __RPC_FAR * This,
    /* [retval][out] */ VARIANT __RPC_FAR *pVal);


void __RPC_STUB IActMLCCG4QnA_get_ActUnitNumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActMLCCG4QnA_put_ActUnitNumber_Proxy( 
    IActMLCCG4QnA __RPC_FAR * This,
    /* [in] */ VARIANT newVal);


void __RPC_STUB IActMLCCG4QnA_put_ActUnitNumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActMLCCG4QnA_get_ActConnectUnitNumber_Proxy( 
    IActMLCCG4QnA __RPC_FAR * This,
    /* [retval][out] */ VARIANT __RPC_FAR *pVal);


void __RPC_STUB IActMLCCG4QnA_get_ActConnectUnitNumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActMLCCG4QnA_put_ActConnectUnitNumber_Proxy( 
    IActMLCCG4QnA __RPC_FAR * This,
    /* [in] */ VARIANT newVal);


void __RPC_STUB IActMLCCG4QnA_put_ActConnectUnitNumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActMLCCG4QnA_get_ActIONumber_Proxy( 
    IActMLCCG4QnA __RPC_FAR * This,
    /* [retval][out] */ VARIANT __RPC_FAR *pVal);


void __RPC_STUB IActMLCCG4QnA_get_ActIONumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActMLCCG4QnA_put_ActIONumber_Proxy( 
    IActMLCCG4QnA __RPC_FAR * This,
    /* [in] */ VARIANT newVal);


void __RPC_STUB IActMLCCG4QnA_put_ActIONumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActMLCCG4QnA_get_ActCpuType_Proxy( 
    IActMLCCG4QnA __RPC_FAR * This,
    /* [retval][out] */ VARIANT __RPC_FAR *pVal);


void __RPC_STUB IActMLCCG4QnA_get_ActCpuType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActMLCCG4QnA_put_ActCpuType_Proxy( 
    IActMLCCG4QnA __RPC_FAR * This,
    /* [in] */ VARIANT newVal);


void __RPC_STUB IActMLCCG4QnA_put_ActCpuType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActMLCCG4QnA_get_ActPortNumber_Proxy( 
    IActMLCCG4QnA __RPC_FAR * This,
    /* [retval][out] */ VARIANT __RPC_FAR *pVal);


void __RPC_STUB IActMLCCG4QnA_get_ActPortNumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActMLCCG4QnA_put_ActPortNumber_Proxy( 
    IActMLCCG4QnA __RPC_FAR * This,
    /* [in] */ VARIANT newVal);


void __RPC_STUB IActMLCCG4QnA_put_ActPortNumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActMLCCG4QnA_get_ActBaudRate_Proxy( 
    IActMLCCG4QnA __RPC_FAR * This,
    /* [retval][out] */ VARIANT __RPC_FAR *pVal);


void __RPC_STUB IActMLCCG4QnA_get_ActBaudRate_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActMLCCG4QnA_put_ActBaudRate_Proxy( 
    IActMLCCG4QnA __RPC_FAR * This,
    /* [in] */ VARIANT newVal);


void __RPC_STUB IActMLCCG4QnA_put_ActBaudRate_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActMLCCG4QnA_get_ActControl_Proxy( 
    IActMLCCG4QnA __RPC_FAR * This,
    /* [retval][out] */ VARIANT __RPC_FAR *pVal);


void __RPC_STUB IActMLCCG4QnA_get_ActControl_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActMLCCG4QnA_put_ActControl_Proxy( 
    IActMLCCG4QnA __RPC_FAR * This,
    /* [in] */ VARIANT newVal);


void __RPC_STUB IActMLCCG4QnA_put_ActControl_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActMLCCG4QnA_get_ActTimeOut_Proxy( 
    IActMLCCG4QnA __RPC_FAR * This,
    /* [retval][out] */ VARIANT __RPC_FAR *pVal);


void __RPC_STUB IActMLCCG4QnA_get_ActTimeOut_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActMLCCG4QnA_put_ActTimeOut_Proxy( 
    IActMLCCG4QnA __RPC_FAR * This,
    /* [in] */ VARIANT newVal);


void __RPC_STUB IActMLCCG4QnA_put_ActTimeOut_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActMLCCG4QnA_FreeDeviceStatus_Proxy( 
    IActMLCCG4QnA __RPC_FAR * This,
    /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);


void __RPC_STUB IActMLCCG4QnA_FreeDeviceStatus_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IActMLCCG4QnA_INTERFACE_DEFINED__ */


#ifndef __IActMLCCG4QnA2_INTERFACE_DEFINED__
#define __IActMLCCG4QnA2_INTERFACE_DEFINED__

/* interface IActMLCCG4QnA2 */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IActMLCCG4QnA2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("87166041-710B-11d5-9318-009099244EFD")
    IActMLCCG4QnA2 : public IActMLCCG4QnA
    {
    public:
    };
    
#else 	/* C style interface */

    typedef struct IActMLCCG4QnA2Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IActMLCCG4QnA2 __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IActMLCCG4QnA2 __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IActMLCCG4QnA2 __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IActMLCCG4QnA2 __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IActMLCCG4QnA2 __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IActMLCCG4QnA2 __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IActMLCCG4QnA2 __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Open )( 
            IActMLCCG4QnA2 __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Close )( 
            IActMLCCG4QnA2 __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetDevice )( 
            IActMLCCG4QnA2 __RPC_FAR * This,
            /* [in] */ VARIANT varDevice,
            /* [out] */ VARIANT __RPC_FAR *lpvarData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetDevice )( 
            IActMLCCG4QnA2 __RPC_FAR * This,
            /* [in] */ VARIANT varDevice,
            /* [in] */ VARIANT varData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceBlock )( 
            IActMLCCG4QnA2 __RPC_FAR * This,
            /* [in] */ VARIANT varDevice,
            /* [in] */ VARIANT varSize,
            /* [out] */ VARIANT __RPC_FAR *lpvarData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceBlock )( 
            IActMLCCG4QnA2 __RPC_FAR * This,
            /* [in] */ VARIANT varDevice,
            /* [in] */ VARIANT varSize,
            /* [in] */ VARIANT varData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceRandom )( 
            IActMLCCG4QnA2 __RPC_FAR * This,
            /* [in] */ VARIANT varDeviceList,
            /* [in] */ VARIANT varSize,
            /* [out] */ VARIANT __RPC_FAR *lpvarData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceRandom )( 
            IActMLCCG4QnA2 __RPC_FAR * This,
            /* [in] */ VARIANT varDeviceList,
            /* [in] */ VARIANT varSize,
            /* [in] */ VARIANT varData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadBuffer )( 
            IActMLCCG4QnA2 __RPC_FAR * This,
            /* [in] */ VARIANT varStartIO,
            /* [in] */ VARIANT varAddress,
            /* [in] */ VARIANT varReadSize,
            /* [out] */ VARIANT __RPC_FAR *lpvarData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteBuffer )( 
            IActMLCCG4QnA2 __RPC_FAR * This,
            /* [in] */ VARIANT varStartIO,
            /* [in] */ VARIANT varAddress,
            /* [in] */ VARIANT varWriteSize,
            /* [in] */ VARIANT varData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetCpuType )( 
            IActMLCCG4QnA2 __RPC_FAR * This,
            /* [out] */ VARIANT __RPC_FAR *lpvarCpuName,
            /* [out] */ VARIANT __RPC_FAR *lpvarCpuType,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetCpuStatus )( 
            IActMLCCG4QnA2 __RPC_FAR * This,
            /* [in] */ VARIANT varOperation,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetClockData )( 
            IActMLCCG4QnA2 __RPC_FAR * This,
            /* [out] */ VARIANT __RPC_FAR *lpvarYear,
            /* [out] */ VARIANT __RPC_FAR *lpvarMonth,
            /* [out] */ VARIANT __RPC_FAR *lpvarDay,
            /* [out] */ VARIANT __RPC_FAR *lpvarDayOfWeek,
            /* [out] */ VARIANT __RPC_FAR *lpvarHour,
            /* [out] */ VARIANT __RPC_FAR *lpvarMinute,
            /* [out] */ VARIANT __RPC_FAR *lpvarSecond,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetClockData )( 
            IActMLCCG4QnA2 __RPC_FAR * This,
            /* [in] */ VARIANT varYear,
            /* [in] */ VARIANT varMonth,
            /* [in] */ VARIANT varDay,
            /* [in] */ VARIANT varDayOfWeek,
            /* [in] */ VARIANT varHour,
            /* [in] */ VARIANT varMinute,
            /* [in] */ VARIANT varSecond,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *EntryDeviceStatus )( 
            IActMLCCG4QnA2 __RPC_FAR * This,
            /* [in] */ VARIANT varDeviceList,
            /* [in] */ VARIANT varSize,
            /* [in] */ VARIANT varMonitorCycle,
            /* [in] */ VARIANT varData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActNetworkNumber )( 
            IActMLCCG4QnA2 __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActNetworkNumber )( 
            IActMLCCG4QnA2 __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActStationNumber )( 
            IActMLCCG4QnA2 __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActStationNumber )( 
            IActMLCCG4QnA2 __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActUnitNumber )( 
            IActMLCCG4QnA2 __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActUnitNumber )( 
            IActMLCCG4QnA2 __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActConnectUnitNumber )( 
            IActMLCCG4QnA2 __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActConnectUnitNumber )( 
            IActMLCCG4QnA2 __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActIONumber )( 
            IActMLCCG4QnA2 __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActIONumber )( 
            IActMLCCG4QnA2 __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActCpuType )( 
            IActMLCCG4QnA2 __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActCpuType )( 
            IActMLCCG4QnA2 __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActPortNumber )( 
            IActMLCCG4QnA2 __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActPortNumber )( 
            IActMLCCG4QnA2 __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActBaudRate )( 
            IActMLCCG4QnA2 __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActBaudRate )( 
            IActMLCCG4QnA2 __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActControl )( 
            IActMLCCG4QnA2 __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActControl )( 
            IActMLCCG4QnA2 __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActTimeOut )( 
            IActMLCCG4QnA2 __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActTimeOut )( 
            IActMLCCG4QnA2 __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *FreeDeviceStatus )( 
            IActMLCCG4QnA2 __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        END_INTERFACE
    } IActMLCCG4QnA2Vtbl;

    interface IActMLCCG4QnA2
    {
        CONST_VTBL struct IActMLCCG4QnA2Vtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IActMLCCG4QnA2_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IActMLCCG4QnA2_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IActMLCCG4QnA2_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IActMLCCG4QnA2_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IActMLCCG4QnA2_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IActMLCCG4QnA2_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IActMLCCG4QnA2_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IActMLCCG4QnA2_Open(This,lpvarReturnCode)	\
    (This)->lpVtbl -> Open(This,lpvarReturnCode)

#define IActMLCCG4QnA2_Close(This,lpvarReturnCode)	\
    (This)->lpVtbl -> Close(This,lpvarReturnCode)

#define IActMLCCG4QnA2_GetDevice(This,varDevice,lpvarData,lpvarReturnCode)	\
    (This)->lpVtbl -> GetDevice(This,varDevice,lpvarData,lpvarReturnCode)

#define IActMLCCG4QnA2_SetDevice(This,varDevice,varData,lpvarReturnCode)	\
    (This)->lpVtbl -> SetDevice(This,varDevice,varData,lpvarReturnCode)

#define IActMLCCG4QnA2_ReadDeviceBlock(This,varDevice,varSize,lpvarData,lpvarReturnCode)	\
    (This)->lpVtbl -> ReadDeviceBlock(This,varDevice,varSize,lpvarData,lpvarReturnCode)

#define IActMLCCG4QnA2_WriteDeviceBlock(This,varDevice,varSize,varData,lpvarReturnCode)	\
    (This)->lpVtbl -> WriteDeviceBlock(This,varDevice,varSize,varData,lpvarReturnCode)

#define IActMLCCG4QnA2_ReadDeviceRandom(This,varDeviceList,varSize,lpvarData,lpvarReturnCode)	\
    (This)->lpVtbl -> ReadDeviceRandom(This,varDeviceList,varSize,lpvarData,lpvarReturnCode)

#define IActMLCCG4QnA2_WriteDeviceRandom(This,varDeviceList,varSize,varData,lpvarReturnCode)	\
    (This)->lpVtbl -> WriteDeviceRandom(This,varDeviceList,varSize,varData,lpvarReturnCode)

#define IActMLCCG4QnA2_ReadBuffer(This,varStartIO,varAddress,varReadSize,lpvarData,lpvarReturnCode)	\
    (This)->lpVtbl -> ReadBuffer(This,varStartIO,varAddress,varReadSize,lpvarData,lpvarReturnCode)

#define IActMLCCG4QnA2_WriteBuffer(This,varStartIO,varAddress,varWriteSize,varData,lpvarReturnCode)	\
    (This)->lpVtbl -> WriteBuffer(This,varStartIO,varAddress,varWriteSize,varData,lpvarReturnCode)

#define IActMLCCG4QnA2_GetCpuType(This,lpvarCpuName,lpvarCpuType,lpvarReturnCode)	\
    (This)->lpVtbl -> GetCpuType(This,lpvarCpuName,lpvarCpuType,lpvarReturnCode)

#define IActMLCCG4QnA2_SetCpuStatus(This,varOperation,lpvarReturnCode)	\
    (This)->lpVtbl -> SetCpuStatus(This,varOperation,lpvarReturnCode)

#define IActMLCCG4QnA2_GetClockData(This,lpvarYear,lpvarMonth,lpvarDay,lpvarDayOfWeek,lpvarHour,lpvarMinute,lpvarSecond,lpvarReturnCode)	\
    (This)->lpVtbl -> GetClockData(This,lpvarYear,lpvarMonth,lpvarDay,lpvarDayOfWeek,lpvarHour,lpvarMinute,lpvarSecond,lpvarReturnCode)

#define IActMLCCG4QnA2_SetClockData(This,varYear,varMonth,varDay,varDayOfWeek,varHour,varMinute,varSecond,lpvarReturnCode)	\
    (This)->lpVtbl -> SetClockData(This,varYear,varMonth,varDay,varDayOfWeek,varHour,varMinute,varSecond,lpvarReturnCode)

#define IActMLCCG4QnA2_EntryDeviceStatus(This,varDeviceList,varSize,varMonitorCycle,varData,lpvarReturnCode)	\
    (This)->lpVtbl -> EntryDeviceStatus(This,varDeviceList,varSize,varMonitorCycle,varData,lpvarReturnCode)

#define IActMLCCG4QnA2_get_ActNetworkNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActNetworkNumber(This,pVal)

#define IActMLCCG4QnA2_put_ActNetworkNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActNetworkNumber(This,newVal)

#define IActMLCCG4QnA2_get_ActStationNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActStationNumber(This,pVal)

#define IActMLCCG4QnA2_put_ActStationNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActStationNumber(This,newVal)

#define IActMLCCG4QnA2_get_ActUnitNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActUnitNumber(This,pVal)

#define IActMLCCG4QnA2_put_ActUnitNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActUnitNumber(This,newVal)

#define IActMLCCG4QnA2_get_ActConnectUnitNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActConnectUnitNumber(This,pVal)

#define IActMLCCG4QnA2_put_ActConnectUnitNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActConnectUnitNumber(This,newVal)

#define IActMLCCG4QnA2_get_ActIONumber(This,pVal)	\
    (This)->lpVtbl -> get_ActIONumber(This,pVal)

#define IActMLCCG4QnA2_put_ActIONumber(This,newVal)	\
    (This)->lpVtbl -> put_ActIONumber(This,newVal)

#define IActMLCCG4QnA2_get_ActCpuType(This,pVal)	\
    (This)->lpVtbl -> get_ActCpuType(This,pVal)

#define IActMLCCG4QnA2_put_ActCpuType(This,newVal)	\
    (This)->lpVtbl -> put_ActCpuType(This,newVal)

#define IActMLCCG4QnA2_get_ActPortNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActPortNumber(This,pVal)

#define IActMLCCG4QnA2_put_ActPortNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActPortNumber(This,newVal)

#define IActMLCCG4QnA2_get_ActBaudRate(This,pVal)	\
    (This)->lpVtbl -> get_ActBaudRate(This,pVal)

#define IActMLCCG4QnA2_put_ActBaudRate(This,newVal)	\
    (This)->lpVtbl -> put_ActBaudRate(This,newVal)

#define IActMLCCG4QnA2_get_ActControl(This,pVal)	\
    (This)->lpVtbl -> get_ActControl(This,pVal)

#define IActMLCCG4QnA2_put_ActControl(This,newVal)	\
    (This)->lpVtbl -> put_ActControl(This,newVal)

#define IActMLCCG4QnA2_get_ActTimeOut(This,pVal)	\
    (This)->lpVtbl -> get_ActTimeOut(This,pVal)

#define IActMLCCG4QnA2_put_ActTimeOut(This,newVal)	\
    (This)->lpVtbl -> put_ActTimeOut(This,newVal)

#define IActMLCCG4QnA2_FreeDeviceStatus(This,lpvarReturnCode)	\
    (This)->lpVtbl -> FreeDeviceStatus(This,lpvarReturnCode)


#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IActMLCCG4QnA2_INTERFACE_DEFINED__ */


#ifndef __IActMLCCG4QnA3_INTERFACE_DEFINED__
#define __IActMLCCG4QnA3_INTERFACE_DEFINED__

/* interface IActMLCCG4QnA3 */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IActMLCCG4QnA3;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("115992F8-6EC2-11d5-9314-009099244EFD")
    IActMLCCG4QnA3 : public IActMLCCG4QnA2
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

    typedef struct IActMLCCG4QnA3Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IActMLCCG4QnA3 __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IActMLCCG4QnA3 __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IActMLCCG4QnA3 __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IActMLCCG4QnA3 __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IActMLCCG4QnA3 __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IActMLCCG4QnA3 __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IActMLCCG4QnA3 __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Open )( 
            IActMLCCG4QnA3 __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Close )( 
            IActMLCCG4QnA3 __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetDevice )( 
            IActMLCCG4QnA3 __RPC_FAR * This,
            /* [in] */ VARIANT varDevice,
            /* [out] */ VARIANT __RPC_FAR *lpvarData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetDevice )( 
            IActMLCCG4QnA3 __RPC_FAR * This,
            /* [in] */ VARIANT varDevice,
            /* [in] */ VARIANT varData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceBlock )( 
            IActMLCCG4QnA3 __RPC_FAR * This,
            /* [in] */ VARIANT varDevice,
            /* [in] */ VARIANT varSize,
            /* [out] */ VARIANT __RPC_FAR *lpvarData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceBlock )( 
            IActMLCCG4QnA3 __RPC_FAR * This,
            /* [in] */ VARIANT varDevice,
            /* [in] */ VARIANT varSize,
            /* [in] */ VARIANT varData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceRandom )( 
            IActMLCCG4QnA3 __RPC_FAR * This,
            /* [in] */ VARIANT varDeviceList,
            /* [in] */ VARIANT varSize,
            /* [out] */ VARIANT __RPC_FAR *lpvarData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceRandom )( 
            IActMLCCG4QnA3 __RPC_FAR * This,
            /* [in] */ VARIANT varDeviceList,
            /* [in] */ VARIANT varSize,
            /* [in] */ VARIANT varData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadBuffer )( 
            IActMLCCG4QnA3 __RPC_FAR * This,
            /* [in] */ VARIANT varStartIO,
            /* [in] */ VARIANT varAddress,
            /* [in] */ VARIANT varReadSize,
            /* [out] */ VARIANT __RPC_FAR *lpvarData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteBuffer )( 
            IActMLCCG4QnA3 __RPC_FAR * This,
            /* [in] */ VARIANT varStartIO,
            /* [in] */ VARIANT varAddress,
            /* [in] */ VARIANT varWriteSize,
            /* [in] */ VARIANT varData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetCpuType )( 
            IActMLCCG4QnA3 __RPC_FAR * This,
            /* [out] */ VARIANT __RPC_FAR *lpvarCpuName,
            /* [out] */ VARIANT __RPC_FAR *lpvarCpuType,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetCpuStatus )( 
            IActMLCCG4QnA3 __RPC_FAR * This,
            /* [in] */ VARIANT varOperation,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetClockData )( 
            IActMLCCG4QnA3 __RPC_FAR * This,
            /* [out] */ VARIANT __RPC_FAR *lpvarYear,
            /* [out] */ VARIANT __RPC_FAR *lpvarMonth,
            /* [out] */ VARIANT __RPC_FAR *lpvarDay,
            /* [out] */ VARIANT __RPC_FAR *lpvarDayOfWeek,
            /* [out] */ VARIANT __RPC_FAR *lpvarHour,
            /* [out] */ VARIANT __RPC_FAR *lpvarMinute,
            /* [out] */ VARIANT __RPC_FAR *lpvarSecond,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetClockData )( 
            IActMLCCG4QnA3 __RPC_FAR * This,
            /* [in] */ VARIANT varYear,
            /* [in] */ VARIANT varMonth,
            /* [in] */ VARIANT varDay,
            /* [in] */ VARIANT varDayOfWeek,
            /* [in] */ VARIANT varHour,
            /* [in] */ VARIANT varMinute,
            /* [in] */ VARIANT varSecond,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *EntryDeviceStatus )( 
            IActMLCCG4QnA3 __RPC_FAR * This,
            /* [in] */ VARIANT varDeviceList,
            /* [in] */ VARIANT varSize,
            /* [in] */ VARIANT varMonitorCycle,
            /* [in] */ VARIANT varData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActNetworkNumber )( 
            IActMLCCG4QnA3 __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActNetworkNumber )( 
            IActMLCCG4QnA3 __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActStationNumber )( 
            IActMLCCG4QnA3 __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActStationNumber )( 
            IActMLCCG4QnA3 __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActUnitNumber )( 
            IActMLCCG4QnA3 __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActUnitNumber )( 
            IActMLCCG4QnA3 __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActConnectUnitNumber )( 
            IActMLCCG4QnA3 __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActConnectUnitNumber )( 
            IActMLCCG4QnA3 __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActIONumber )( 
            IActMLCCG4QnA3 __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActIONumber )( 
            IActMLCCG4QnA3 __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActCpuType )( 
            IActMLCCG4QnA3 __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActCpuType )( 
            IActMLCCG4QnA3 __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActPortNumber )( 
            IActMLCCG4QnA3 __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActPortNumber )( 
            IActMLCCG4QnA3 __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActBaudRate )( 
            IActMLCCG4QnA3 __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActBaudRate )( 
            IActMLCCG4QnA3 __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActControl )( 
            IActMLCCG4QnA3 __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActControl )( 
            IActMLCCG4QnA3 __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActTimeOut )( 
            IActMLCCG4QnA3 __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActTimeOut )( 
            IActMLCCG4QnA3 __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *FreeDeviceStatus )( 
            IActMLCCG4QnA3 __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceBlock2 )( 
            IActMLCCG4QnA3 __RPC_FAR * This,
            /* [in] */ VARIANT varDevice,
            /* [in] */ VARIANT varSize,
            /* [out] */ VARIANT __RPC_FAR *lpvarData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceBlock2 )( 
            IActMLCCG4QnA3 __RPC_FAR * This,
            /* [in] */ VARIANT varDevice,
            /* [in] */ VARIANT varSize,
            /* [in] */ VARIANT varData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceRandom2 )( 
            IActMLCCG4QnA3 __RPC_FAR * This,
            /* [in] */ VARIANT varDeviceList,
            /* [in] */ VARIANT varSize,
            /* [out] */ VARIANT __RPC_FAR *lpvarData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceRandom2 )( 
            IActMLCCG4QnA3 __RPC_FAR * This,
            /* [in] */ VARIANT varDeviceList,
            /* [in] */ VARIANT varSize,
            /* [in] */ VARIANT varData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetDevice2 )( 
            IActMLCCG4QnA3 __RPC_FAR * This,
            /* [in] */ VARIANT varDevice,
            /* [out] */ VARIANT __RPC_FAR *lpvarData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetDevice2 )( 
            IActMLCCG4QnA3 __RPC_FAR * This,
            /* [in] */ VARIANT varDevice,
            /* [in] */ VARIANT varData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        END_INTERFACE
    } IActMLCCG4QnA3Vtbl;

    interface IActMLCCG4QnA3
    {
        CONST_VTBL struct IActMLCCG4QnA3Vtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IActMLCCG4QnA3_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IActMLCCG4QnA3_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IActMLCCG4QnA3_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IActMLCCG4QnA3_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IActMLCCG4QnA3_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IActMLCCG4QnA3_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IActMLCCG4QnA3_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IActMLCCG4QnA3_Open(This,lpvarReturnCode)	\
    (This)->lpVtbl -> Open(This,lpvarReturnCode)

#define IActMLCCG4QnA3_Close(This,lpvarReturnCode)	\
    (This)->lpVtbl -> Close(This,lpvarReturnCode)

#define IActMLCCG4QnA3_GetDevice(This,varDevice,lpvarData,lpvarReturnCode)	\
    (This)->lpVtbl -> GetDevice(This,varDevice,lpvarData,lpvarReturnCode)

#define IActMLCCG4QnA3_SetDevice(This,varDevice,varData,lpvarReturnCode)	\
    (This)->lpVtbl -> SetDevice(This,varDevice,varData,lpvarReturnCode)

#define IActMLCCG4QnA3_ReadDeviceBlock(This,varDevice,varSize,lpvarData,lpvarReturnCode)	\
    (This)->lpVtbl -> ReadDeviceBlock(This,varDevice,varSize,lpvarData,lpvarReturnCode)

#define IActMLCCG4QnA3_WriteDeviceBlock(This,varDevice,varSize,varData,lpvarReturnCode)	\
    (This)->lpVtbl -> WriteDeviceBlock(This,varDevice,varSize,varData,lpvarReturnCode)

#define IActMLCCG4QnA3_ReadDeviceRandom(This,varDeviceList,varSize,lpvarData,lpvarReturnCode)	\
    (This)->lpVtbl -> ReadDeviceRandom(This,varDeviceList,varSize,lpvarData,lpvarReturnCode)

#define IActMLCCG4QnA3_WriteDeviceRandom(This,varDeviceList,varSize,varData,lpvarReturnCode)	\
    (This)->lpVtbl -> WriteDeviceRandom(This,varDeviceList,varSize,varData,lpvarReturnCode)

#define IActMLCCG4QnA3_ReadBuffer(This,varStartIO,varAddress,varReadSize,lpvarData,lpvarReturnCode)	\
    (This)->lpVtbl -> ReadBuffer(This,varStartIO,varAddress,varReadSize,lpvarData,lpvarReturnCode)

#define IActMLCCG4QnA3_WriteBuffer(This,varStartIO,varAddress,varWriteSize,varData,lpvarReturnCode)	\
    (This)->lpVtbl -> WriteBuffer(This,varStartIO,varAddress,varWriteSize,varData,lpvarReturnCode)

#define IActMLCCG4QnA3_GetCpuType(This,lpvarCpuName,lpvarCpuType,lpvarReturnCode)	\
    (This)->lpVtbl -> GetCpuType(This,lpvarCpuName,lpvarCpuType,lpvarReturnCode)

#define IActMLCCG4QnA3_SetCpuStatus(This,varOperation,lpvarReturnCode)	\
    (This)->lpVtbl -> SetCpuStatus(This,varOperation,lpvarReturnCode)

#define IActMLCCG4QnA3_GetClockData(This,lpvarYear,lpvarMonth,lpvarDay,lpvarDayOfWeek,lpvarHour,lpvarMinute,lpvarSecond,lpvarReturnCode)	\
    (This)->lpVtbl -> GetClockData(This,lpvarYear,lpvarMonth,lpvarDay,lpvarDayOfWeek,lpvarHour,lpvarMinute,lpvarSecond,lpvarReturnCode)

#define IActMLCCG4QnA3_SetClockData(This,varYear,varMonth,varDay,varDayOfWeek,varHour,varMinute,varSecond,lpvarReturnCode)	\
    (This)->lpVtbl -> SetClockData(This,varYear,varMonth,varDay,varDayOfWeek,varHour,varMinute,varSecond,lpvarReturnCode)

#define IActMLCCG4QnA3_EntryDeviceStatus(This,varDeviceList,varSize,varMonitorCycle,varData,lpvarReturnCode)	\
    (This)->lpVtbl -> EntryDeviceStatus(This,varDeviceList,varSize,varMonitorCycle,varData,lpvarReturnCode)

#define IActMLCCG4QnA3_get_ActNetworkNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActNetworkNumber(This,pVal)

#define IActMLCCG4QnA3_put_ActNetworkNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActNetworkNumber(This,newVal)

#define IActMLCCG4QnA3_get_ActStationNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActStationNumber(This,pVal)

#define IActMLCCG4QnA3_put_ActStationNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActStationNumber(This,newVal)

#define IActMLCCG4QnA3_get_ActUnitNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActUnitNumber(This,pVal)

#define IActMLCCG4QnA3_put_ActUnitNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActUnitNumber(This,newVal)

#define IActMLCCG4QnA3_get_ActConnectUnitNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActConnectUnitNumber(This,pVal)

#define IActMLCCG4QnA3_put_ActConnectUnitNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActConnectUnitNumber(This,newVal)

#define IActMLCCG4QnA3_get_ActIONumber(This,pVal)	\
    (This)->lpVtbl -> get_ActIONumber(This,pVal)

#define IActMLCCG4QnA3_put_ActIONumber(This,newVal)	\
    (This)->lpVtbl -> put_ActIONumber(This,newVal)

#define IActMLCCG4QnA3_get_ActCpuType(This,pVal)	\
    (This)->lpVtbl -> get_ActCpuType(This,pVal)

#define IActMLCCG4QnA3_put_ActCpuType(This,newVal)	\
    (This)->lpVtbl -> put_ActCpuType(This,newVal)

#define IActMLCCG4QnA3_get_ActPortNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActPortNumber(This,pVal)

#define IActMLCCG4QnA3_put_ActPortNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActPortNumber(This,newVal)

#define IActMLCCG4QnA3_get_ActBaudRate(This,pVal)	\
    (This)->lpVtbl -> get_ActBaudRate(This,pVal)

#define IActMLCCG4QnA3_put_ActBaudRate(This,newVal)	\
    (This)->lpVtbl -> put_ActBaudRate(This,newVal)

#define IActMLCCG4QnA3_get_ActControl(This,pVal)	\
    (This)->lpVtbl -> get_ActControl(This,pVal)

#define IActMLCCG4QnA3_put_ActControl(This,newVal)	\
    (This)->lpVtbl -> put_ActControl(This,newVal)

#define IActMLCCG4QnA3_get_ActTimeOut(This,pVal)	\
    (This)->lpVtbl -> get_ActTimeOut(This,pVal)

#define IActMLCCG4QnA3_put_ActTimeOut(This,newVal)	\
    (This)->lpVtbl -> put_ActTimeOut(This,newVal)

#define IActMLCCG4QnA3_FreeDeviceStatus(This,lpvarReturnCode)	\
    (This)->lpVtbl -> FreeDeviceStatus(This,lpvarReturnCode)



#define IActMLCCG4QnA3_ReadDeviceBlock2(This,varDevice,varSize,lpvarData,lpvarReturnCode)	\
    (This)->lpVtbl -> ReadDeviceBlock2(This,varDevice,varSize,lpvarData,lpvarReturnCode)

#define IActMLCCG4QnA3_WriteDeviceBlock2(This,varDevice,varSize,varData,lpvarReturnCode)	\
    (This)->lpVtbl -> WriteDeviceBlock2(This,varDevice,varSize,varData,lpvarReturnCode)

#define IActMLCCG4QnA3_ReadDeviceRandom2(This,varDeviceList,varSize,lpvarData,lpvarReturnCode)	\
    (This)->lpVtbl -> ReadDeviceRandom2(This,varDeviceList,varSize,lpvarData,lpvarReturnCode)

#define IActMLCCG4QnA3_WriteDeviceRandom2(This,varDeviceList,varSize,varData,lpvarReturnCode)	\
    (This)->lpVtbl -> WriteDeviceRandom2(This,varDeviceList,varSize,varData,lpvarReturnCode)

#define IActMLCCG4QnA3_GetDevice2(This,varDevice,lpvarData,lpvarReturnCode)	\
    (This)->lpVtbl -> GetDevice2(This,varDevice,lpvarData,lpvarReturnCode)

#define IActMLCCG4QnA3_SetDevice2(This,varDevice,varData,lpvarReturnCode)	\
    (This)->lpVtbl -> SetDevice2(This,varDevice,varData,lpvarReturnCode)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActMLCCG4QnA3_ReadDeviceBlock2_Proxy( 
    IActMLCCG4QnA3 __RPC_FAR * This,
    /* [in] */ VARIANT varDevice,
    /* [in] */ VARIANT varSize,
    /* [out] */ VARIANT __RPC_FAR *lpvarData,
    /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);


void __RPC_STUB IActMLCCG4QnA3_ReadDeviceBlock2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActMLCCG4QnA3_WriteDeviceBlock2_Proxy( 
    IActMLCCG4QnA3 __RPC_FAR * This,
    /* [in] */ VARIANT varDevice,
    /* [in] */ VARIANT varSize,
    /* [in] */ VARIANT varData,
    /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);


void __RPC_STUB IActMLCCG4QnA3_WriteDeviceBlock2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActMLCCG4QnA3_ReadDeviceRandom2_Proxy( 
    IActMLCCG4QnA3 __RPC_FAR * This,
    /* [in] */ VARIANT varDeviceList,
    /* [in] */ VARIANT varSize,
    /* [out] */ VARIANT __RPC_FAR *lpvarData,
    /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);


void __RPC_STUB IActMLCCG4QnA3_ReadDeviceRandom2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActMLCCG4QnA3_WriteDeviceRandom2_Proxy( 
    IActMLCCG4QnA3 __RPC_FAR * This,
    /* [in] */ VARIANT varDeviceList,
    /* [in] */ VARIANT varSize,
    /* [in] */ VARIANT varData,
    /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);


void __RPC_STUB IActMLCCG4QnA3_WriteDeviceRandom2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActMLCCG4QnA3_GetDevice2_Proxy( 
    IActMLCCG4QnA3 __RPC_FAR * This,
    /* [in] */ VARIANT varDevice,
    /* [out] */ VARIANT __RPC_FAR *lpvarData,
    /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);


void __RPC_STUB IActMLCCG4QnA3_GetDevice2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActMLCCG4QnA3_SetDevice2_Proxy( 
    IActMLCCG4QnA3 __RPC_FAR * This,
    /* [in] */ VARIANT varDevice,
    /* [in] */ VARIANT varData,
    /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);


void __RPC_STUB IActMLCCG4QnA3_SetDevice2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IActMLCCG4QnA3_INTERFACE_DEFINED__ */


#ifndef __IActCCG4Q_INTERFACE_DEFINED__
#define __IActCCG4Q_INTERFACE_DEFINED__

/* interface IActCCG4Q */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IActCCG4Q;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("3555ACF3-70DB-11D5-9318-009099244EFD")
    IActCCG4Q : public IDispatch
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
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActControl( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActControl( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActTimeOut( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActTimeOut( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActThroughNetworkType( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActThroughNetworkType( 
            /* [in] */ long newVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IActCCG4QVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IActCCG4Q __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IActCCG4Q __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IActCCG4Q __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IActCCG4Q __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IActCCG4Q __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IActCCG4Q __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IActCCG4Q __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Open )( 
            IActCCG4Q __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Close )( 
            IActCCG4Q __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetDevice )( 
            IActCCG4Q __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [out] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetDevice )( 
            IActCCG4Q __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceBlock )( 
            IActCCG4Q __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lSize,
            /* [size_is][out] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceBlock )( 
            IActCCG4Q __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lSize,
            /* [size_is][in] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceRandom )( 
            IActCCG4Q __RPC_FAR * This,
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG lSize,
            /* [size_is][out] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceRandom )( 
            IActCCG4Q __RPC_FAR * This,
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG lSize,
            /* [size_is][in] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadBuffer )( 
            IActCCG4Q __RPC_FAR * This,
            /* [in] */ LONG lStartIO,
            /* [in] */ LONG lAddress,
            /* [in] */ LONG lReadSize,
            /* [size_is][out] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteBuffer )( 
            IActCCG4Q __RPC_FAR * This,
            /* [in] */ LONG lStartIO,
            /* [in] */ LONG lAddress,
            /* [in] */ LONG lWriteSize,
            /* [size_is][in] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetClockData )( 
            IActCCG4Q __RPC_FAR * This,
            /* [out] */ SHORT __RPC_FAR *lpsYear,
            /* [out] */ SHORT __RPC_FAR *lpsMonth,
            /* [out] */ SHORT __RPC_FAR *lpsDay,
            /* [out] */ SHORT __RPC_FAR *lpsDayOfWeek,
            /* [out] */ SHORT __RPC_FAR *lpsHour,
            /* [out] */ SHORT __RPC_FAR *lpsMinute,
            /* [out] */ SHORT __RPC_FAR *lpsSecond,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetClockData )( 
            IActCCG4Q __RPC_FAR * This,
            /* [in] */ SHORT sYear,
            /* [in] */ SHORT sMonth,
            /* [in] */ SHORT sDay,
            /* [in] */ SHORT sDayOfWeek,
            /* [in] */ SHORT sHour,
            /* [in] */ SHORT sMinute,
            /* [in] */ SHORT sSecond,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetCpuType )( 
            IActCCG4Q __RPC_FAR * This,
            /* [string][out] */ BSTR __RPC_FAR *szCpuName,
            /* [out] */ LONG __RPC_FAR *lplCpuCode,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetCpuStatus )( 
            IActCCG4Q __RPC_FAR * This,
            /* [in] */ LONG lOperation,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CheckDeviceString )( 
            IActCCG4Q __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lCheckType,
            /* [in] */ LONG lSize,
            /* [out] */ LONG __RPC_FAR *lplDeviceType,
            /* [string][out] */ BSTR __RPC_FAR *lpszDeviceName,
            /* [out] */ LONG __RPC_FAR *lplDeviceNumber,
            /* [out] */ LONG __RPC_FAR *lplDeviceRadix,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *EntryDeviceStatus )( 
            IActCCG4Q __RPC_FAR * This,
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG lSize,
            /* [in] */ LONG lMonitorCycle,
            /* [size_is][in] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *FreeDeviceStatus )( 
            IActCCG4Q __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceBlock2 )( 
            IActCCG4Q __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lSize,
            /* [size_is][out] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceBlock2 )( 
            IActCCG4Q __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lSize,
            /* [size_is][in] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceRandom2 )( 
            IActCCG4Q __RPC_FAR * This,
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG lSize,
            /* [size_is][out] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceRandom2 )( 
            IActCCG4Q __RPC_FAR * This,
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG lSize,
            /* [size_is][in] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetDevice2 )( 
            IActCCG4Q __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [out] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetDevice2 )( 
            IActCCG4Q __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ SHORT sData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActNetworkNumber )( 
            IActCCG4Q __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActNetworkNumber )( 
            IActCCG4Q __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActStationNumber )( 
            IActCCG4Q __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActStationNumber )( 
            IActCCG4Q __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActUnitNumber )( 
            IActCCG4Q __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActUnitNumber )( 
            IActCCG4Q __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActConnectUnitNumber )( 
            IActCCG4Q __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActConnectUnitNumber )( 
            IActCCG4Q __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActIONumber )( 
            IActCCG4Q __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActIONumber )( 
            IActCCG4Q __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActCpuType )( 
            IActCCG4Q __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActCpuType )( 
            IActCCG4Q __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActPortNumber )( 
            IActCCG4Q __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActPortNumber )( 
            IActCCG4Q __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActBaudRate )( 
            IActCCG4Q __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActBaudRate )( 
            IActCCG4Q __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActControl )( 
            IActCCG4Q __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActControl )( 
            IActCCG4Q __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActTimeOut )( 
            IActCCG4Q __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActTimeOut )( 
            IActCCG4Q __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActThroughNetworkType )( 
            IActCCG4Q __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActThroughNetworkType )( 
            IActCCG4Q __RPC_FAR * This,
            /* [in] */ long newVal);
        
        END_INTERFACE
    } IActCCG4QVtbl;

    interface IActCCG4Q
    {
        CONST_VTBL struct IActCCG4QVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IActCCG4Q_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IActCCG4Q_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IActCCG4Q_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IActCCG4Q_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IActCCG4Q_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IActCCG4Q_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IActCCG4Q_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IActCCG4Q_Open(This,lplReturnCode)	\
    (This)->lpVtbl -> Open(This,lplReturnCode)

#define IActCCG4Q_Close(This,lplReturnCode)	\
    (This)->lpVtbl -> Close(This,lplReturnCode)

#define IActCCG4Q_GetDevice(This,szDevice,lplData,lplReturnCode)	\
    (This)->lpVtbl -> GetDevice(This,szDevice,lplData,lplReturnCode)

#define IActCCG4Q_SetDevice(This,szDevice,lData,lplReturnCode)	\
    (This)->lpVtbl -> SetDevice(This,szDevice,lData,lplReturnCode)

#define IActCCG4Q_ReadDeviceBlock(This,szDevice,lSize,lplData,lplReturnCode)	\
    (This)->lpVtbl -> ReadDeviceBlock(This,szDevice,lSize,lplData,lplReturnCode)

#define IActCCG4Q_WriteDeviceBlock(This,szDevice,lSize,lplData,lplReturnCode)	\
    (This)->lpVtbl -> WriteDeviceBlock(This,szDevice,lSize,lplData,lplReturnCode)

#define IActCCG4Q_ReadDeviceRandom(This,szDeviceList,lSize,lplData,lplReturnCode)	\
    (This)->lpVtbl -> ReadDeviceRandom(This,szDeviceList,lSize,lplData,lplReturnCode)

#define IActCCG4Q_WriteDeviceRandom(This,szDeviceList,lSize,lplData,lplReturnCode)	\
    (This)->lpVtbl -> WriteDeviceRandom(This,szDeviceList,lSize,lplData,lplReturnCode)

#define IActCCG4Q_ReadBuffer(This,lStartIO,lAddress,lReadSize,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> ReadBuffer(This,lStartIO,lAddress,lReadSize,lpsData,lplReturnCode)

#define IActCCG4Q_WriteBuffer(This,lStartIO,lAddress,lWriteSize,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> WriteBuffer(This,lStartIO,lAddress,lWriteSize,lpsData,lplReturnCode)

#define IActCCG4Q_GetClockData(This,lpsYear,lpsMonth,lpsDay,lpsDayOfWeek,lpsHour,lpsMinute,lpsSecond,lplReturnCode)	\
    (This)->lpVtbl -> GetClockData(This,lpsYear,lpsMonth,lpsDay,lpsDayOfWeek,lpsHour,lpsMinute,lpsSecond,lplReturnCode)

#define IActCCG4Q_SetClockData(This,sYear,sMonth,sDay,sDayOfWeek,sHour,sMinute,sSecond,lplReturnCode)	\
    (This)->lpVtbl -> SetClockData(This,sYear,sMonth,sDay,sDayOfWeek,sHour,sMinute,sSecond,lplReturnCode)

#define IActCCG4Q_GetCpuType(This,szCpuName,lplCpuCode,lplReturnCode)	\
    (This)->lpVtbl -> GetCpuType(This,szCpuName,lplCpuCode,lplReturnCode)

#define IActCCG4Q_SetCpuStatus(This,lOperation,lplReturnCode)	\
    (This)->lpVtbl -> SetCpuStatus(This,lOperation,lplReturnCode)

#define IActCCG4Q_CheckDeviceString(This,szDevice,lCheckType,lSize,lplDeviceType,lpszDeviceName,lplDeviceNumber,lplDeviceRadix,lplReturnCode)	\
    (This)->lpVtbl -> CheckDeviceString(This,szDevice,lCheckType,lSize,lplDeviceType,lpszDeviceName,lplDeviceNumber,lplDeviceRadix,lplReturnCode)

#define IActCCG4Q_EntryDeviceStatus(This,szDeviceList,lSize,lMonitorCycle,lplData,lplReturnCode)	\
    (This)->lpVtbl -> EntryDeviceStatus(This,szDeviceList,lSize,lMonitorCycle,lplData,lplReturnCode)

#define IActCCG4Q_FreeDeviceStatus(This,lplReturnCode)	\
    (This)->lpVtbl -> FreeDeviceStatus(This,lplReturnCode)

#define IActCCG4Q_ReadDeviceBlock2(This,szDevice,lSize,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> ReadDeviceBlock2(This,szDevice,lSize,lpsData,lplReturnCode)

#define IActCCG4Q_WriteDeviceBlock2(This,szDevice,lSize,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> WriteDeviceBlock2(This,szDevice,lSize,lpsData,lplReturnCode)

#define IActCCG4Q_ReadDeviceRandom2(This,szDeviceList,lSize,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> ReadDeviceRandom2(This,szDeviceList,lSize,lpsData,lplReturnCode)

#define IActCCG4Q_WriteDeviceRandom2(This,szDeviceList,lSize,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> WriteDeviceRandom2(This,szDeviceList,lSize,lpsData,lplReturnCode)

#define IActCCG4Q_GetDevice2(This,szDevice,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> GetDevice2(This,szDevice,lpsData,lplReturnCode)

#define IActCCG4Q_SetDevice2(This,szDevice,sData,lplReturnCode)	\
    (This)->lpVtbl -> SetDevice2(This,szDevice,sData,lplReturnCode)

#define IActCCG4Q_get_ActNetworkNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActNetworkNumber(This,pVal)

#define IActCCG4Q_put_ActNetworkNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActNetworkNumber(This,newVal)

#define IActCCG4Q_get_ActStationNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActStationNumber(This,pVal)

#define IActCCG4Q_put_ActStationNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActStationNumber(This,newVal)

#define IActCCG4Q_get_ActUnitNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActUnitNumber(This,pVal)

#define IActCCG4Q_put_ActUnitNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActUnitNumber(This,newVal)

#define IActCCG4Q_get_ActConnectUnitNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActConnectUnitNumber(This,pVal)

#define IActCCG4Q_put_ActConnectUnitNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActConnectUnitNumber(This,newVal)

#define IActCCG4Q_get_ActIONumber(This,pVal)	\
    (This)->lpVtbl -> get_ActIONumber(This,pVal)

#define IActCCG4Q_put_ActIONumber(This,newVal)	\
    (This)->lpVtbl -> put_ActIONumber(This,newVal)

#define IActCCG4Q_get_ActCpuType(This,pVal)	\
    (This)->lpVtbl -> get_ActCpuType(This,pVal)

#define IActCCG4Q_put_ActCpuType(This,newVal)	\
    (This)->lpVtbl -> put_ActCpuType(This,newVal)

#define IActCCG4Q_get_ActPortNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActPortNumber(This,pVal)

#define IActCCG4Q_put_ActPortNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActPortNumber(This,newVal)

#define IActCCG4Q_get_ActBaudRate(This,pVal)	\
    (This)->lpVtbl -> get_ActBaudRate(This,pVal)

#define IActCCG4Q_put_ActBaudRate(This,newVal)	\
    (This)->lpVtbl -> put_ActBaudRate(This,newVal)

#define IActCCG4Q_get_ActControl(This,pVal)	\
    (This)->lpVtbl -> get_ActControl(This,pVal)

#define IActCCG4Q_put_ActControl(This,newVal)	\
    (This)->lpVtbl -> put_ActControl(This,newVal)

#define IActCCG4Q_get_ActTimeOut(This,pVal)	\
    (This)->lpVtbl -> get_ActTimeOut(This,pVal)

#define IActCCG4Q_put_ActTimeOut(This,newVal)	\
    (This)->lpVtbl -> put_ActTimeOut(This,newVal)

#define IActCCG4Q_get_ActThroughNetworkType(This,pVal)	\
    (This)->lpVtbl -> get_ActThroughNetworkType(This,pVal)

#define IActCCG4Q_put_ActThroughNetworkType(This,newVal)	\
    (This)->lpVtbl -> put_ActThroughNetworkType(This,newVal)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActCCG4Q_Open_Proxy( 
    IActCCG4Q __RPC_FAR * This,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActCCG4Q_Open_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActCCG4Q_Close_Proxy( 
    IActCCG4Q __RPC_FAR * This,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActCCG4Q_Close_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActCCG4Q_GetDevice_Proxy( 
    IActCCG4Q __RPC_FAR * This,
    /* [string][in] */ BSTR szDevice,
    /* [out] */ LONG __RPC_FAR *lplData,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActCCG4Q_GetDevice_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActCCG4Q_SetDevice_Proxy( 
    IActCCG4Q __RPC_FAR * This,
    /* [string][in] */ BSTR szDevice,
    /* [in] */ LONG lData,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActCCG4Q_SetDevice_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActCCG4Q_ReadDeviceBlock_Proxy( 
    IActCCG4Q __RPC_FAR * This,
    /* [string][in] */ BSTR szDevice,
    /* [in] */ LONG lSize,
    /* [size_is][out] */ LONG __RPC_FAR *lplData,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActCCG4Q_ReadDeviceBlock_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActCCG4Q_WriteDeviceBlock_Proxy( 
    IActCCG4Q __RPC_FAR * This,
    /* [string][in] */ BSTR szDevice,
    /* [in] */ LONG lSize,
    /* [size_is][in] */ LONG __RPC_FAR *lplData,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActCCG4Q_WriteDeviceBlock_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActCCG4Q_ReadDeviceRandom_Proxy( 
    IActCCG4Q __RPC_FAR * This,
    /* [string][in] */ BSTR szDeviceList,
    /* [in] */ LONG lSize,
    /* [size_is][out] */ LONG __RPC_FAR *lplData,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActCCG4Q_ReadDeviceRandom_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActCCG4Q_WriteDeviceRandom_Proxy( 
    IActCCG4Q __RPC_FAR * This,
    /* [string][in] */ BSTR szDeviceList,
    /* [in] */ LONG lSize,
    /* [size_is][in] */ LONG __RPC_FAR *lplData,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActCCG4Q_WriteDeviceRandom_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActCCG4Q_ReadBuffer_Proxy( 
    IActCCG4Q __RPC_FAR * This,
    /* [in] */ LONG lStartIO,
    /* [in] */ LONG lAddress,
    /* [in] */ LONG lReadSize,
    /* [size_is][out] */ SHORT __RPC_FAR *lpsData,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActCCG4Q_ReadBuffer_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActCCG4Q_WriteBuffer_Proxy( 
    IActCCG4Q __RPC_FAR * This,
    /* [in] */ LONG lStartIO,
    /* [in] */ LONG lAddress,
    /* [in] */ LONG lWriteSize,
    /* [size_is][in] */ SHORT __RPC_FAR *lpsData,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActCCG4Q_WriteBuffer_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActCCG4Q_GetClockData_Proxy( 
    IActCCG4Q __RPC_FAR * This,
    /* [out] */ SHORT __RPC_FAR *lpsYear,
    /* [out] */ SHORT __RPC_FAR *lpsMonth,
    /* [out] */ SHORT __RPC_FAR *lpsDay,
    /* [out] */ SHORT __RPC_FAR *lpsDayOfWeek,
    /* [out] */ SHORT __RPC_FAR *lpsHour,
    /* [out] */ SHORT __RPC_FAR *lpsMinute,
    /* [out] */ SHORT __RPC_FAR *lpsSecond,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActCCG4Q_GetClockData_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActCCG4Q_SetClockData_Proxy( 
    IActCCG4Q __RPC_FAR * This,
    /* [in] */ SHORT sYear,
    /* [in] */ SHORT sMonth,
    /* [in] */ SHORT sDay,
    /* [in] */ SHORT sDayOfWeek,
    /* [in] */ SHORT sHour,
    /* [in] */ SHORT sMinute,
    /* [in] */ SHORT sSecond,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActCCG4Q_SetClockData_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActCCG4Q_GetCpuType_Proxy( 
    IActCCG4Q __RPC_FAR * This,
    /* [string][out] */ BSTR __RPC_FAR *szCpuName,
    /* [out] */ LONG __RPC_FAR *lplCpuCode,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActCCG4Q_GetCpuType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActCCG4Q_SetCpuStatus_Proxy( 
    IActCCG4Q __RPC_FAR * This,
    /* [in] */ LONG lOperation,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActCCG4Q_SetCpuStatus_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActCCG4Q_CheckDeviceString_Proxy( 
    IActCCG4Q __RPC_FAR * This,
    /* [string][in] */ BSTR szDevice,
    /* [in] */ LONG lCheckType,
    /* [in] */ LONG lSize,
    /* [out] */ LONG __RPC_FAR *lplDeviceType,
    /* [string][out] */ BSTR __RPC_FAR *lpszDeviceName,
    /* [out] */ LONG __RPC_FAR *lplDeviceNumber,
    /* [out] */ LONG __RPC_FAR *lplDeviceRadix,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActCCG4Q_CheckDeviceString_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActCCG4Q_EntryDeviceStatus_Proxy( 
    IActCCG4Q __RPC_FAR * This,
    /* [string][in] */ BSTR szDeviceList,
    /* [in] */ LONG lSize,
    /* [in] */ LONG lMonitorCycle,
    /* [size_is][in] */ LONG __RPC_FAR *lplData,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActCCG4Q_EntryDeviceStatus_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActCCG4Q_FreeDeviceStatus_Proxy( 
    IActCCG4Q __RPC_FAR * This,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActCCG4Q_FreeDeviceStatus_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActCCG4Q_ReadDeviceBlock2_Proxy( 
    IActCCG4Q __RPC_FAR * This,
    /* [string][in] */ BSTR szDevice,
    /* [in] */ LONG lSize,
    /* [size_is][out] */ SHORT __RPC_FAR *lpsData,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActCCG4Q_ReadDeviceBlock2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActCCG4Q_WriteDeviceBlock2_Proxy( 
    IActCCG4Q __RPC_FAR * This,
    /* [string][in] */ BSTR szDevice,
    /* [in] */ LONG lSize,
    /* [size_is][in] */ SHORT __RPC_FAR *lpsData,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActCCG4Q_WriteDeviceBlock2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActCCG4Q_ReadDeviceRandom2_Proxy( 
    IActCCG4Q __RPC_FAR * This,
    /* [string][in] */ BSTR szDeviceList,
    /* [in] */ LONG lSize,
    /* [size_is][out] */ SHORT __RPC_FAR *lpsData,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActCCG4Q_ReadDeviceRandom2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActCCG4Q_WriteDeviceRandom2_Proxy( 
    IActCCG4Q __RPC_FAR * This,
    /* [string][in] */ BSTR szDeviceList,
    /* [in] */ LONG lSize,
    /* [size_is][in] */ SHORT __RPC_FAR *lpsData,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActCCG4Q_WriteDeviceRandom2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActCCG4Q_GetDevice2_Proxy( 
    IActCCG4Q __RPC_FAR * This,
    /* [string][in] */ BSTR szDevice,
    /* [out] */ SHORT __RPC_FAR *lpsData,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActCCG4Q_GetDevice2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActCCG4Q_SetDevice2_Proxy( 
    IActCCG4Q __RPC_FAR * This,
    /* [string][in] */ BSTR szDevice,
    /* [in] */ SHORT sData,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActCCG4Q_SetDevice2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActCCG4Q_get_ActNetworkNumber_Proxy( 
    IActCCG4Q __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IActCCG4Q_get_ActNetworkNumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActCCG4Q_put_ActNetworkNumber_Proxy( 
    IActCCG4Q __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB IActCCG4Q_put_ActNetworkNumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActCCG4Q_get_ActStationNumber_Proxy( 
    IActCCG4Q __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IActCCG4Q_get_ActStationNumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActCCG4Q_put_ActStationNumber_Proxy( 
    IActCCG4Q __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB IActCCG4Q_put_ActStationNumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActCCG4Q_get_ActUnitNumber_Proxy( 
    IActCCG4Q __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IActCCG4Q_get_ActUnitNumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActCCG4Q_put_ActUnitNumber_Proxy( 
    IActCCG4Q __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB IActCCG4Q_put_ActUnitNumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActCCG4Q_get_ActConnectUnitNumber_Proxy( 
    IActCCG4Q __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IActCCG4Q_get_ActConnectUnitNumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActCCG4Q_put_ActConnectUnitNumber_Proxy( 
    IActCCG4Q __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB IActCCG4Q_put_ActConnectUnitNumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActCCG4Q_get_ActIONumber_Proxy( 
    IActCCG4Q __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IActCCG4Q_get_ActIONumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActCCG4Q_put_ActIONumber_Proxy( 
    IActCCG4Q __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB IActCCG4Q_put_ActIONumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActCCG4Q_get_ActCpuType_Proxy( 
    IActCCG4Q __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IActCCG4Q_get_ActCpuType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActCCG4Q_put_ActCpuType_Proxy( 
    IActCCG4Q __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB IActCCG4Q_put_ActCpuType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActCCG4Q_get_ActPortNumber_Proxy( 
    IActCCG4Q __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IActCCG4Q_get_ActPortNumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActCCG4Q_put_ActPortNumber_Proxy( 
    IActCCG4Q __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB IActCCG4Q_put_ActPortNumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActCCG4Q_get_ActBaudRate_Proxy( 
    IActCCG4Q __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IActCCG4Q_get_ActBaudRate_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActCCG4Q_put_ActBaudRate_Proxy( 
    IActCCG4Q __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB IActCCG4Q_put_ActBaudRate_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActCCG4Q_get_ActControl_Proxy( 
    IActCCG4Q __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IActCCG4Q_get_ActControl_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActCCG4Q_put_ActControl_Proxy( 
    IActCCG4Q __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB IActCCG4Q_put_ActControl_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActCCG4Q_get_ActTimeOut_Proxy( 
    IActCCG4Q __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IActCCG4Q_get_ActTimeOut_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActCCG4Q_put_ActTimeOut_Proxy( 
    IActCCG4Q __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB IActCCG4Q_put_ActTimeOut_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActCCG4Q_get_ActThroughNetworkType_Proxy( 
    IActCCG4Q __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IActCCG4Q_get_ActThroughNetworkType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActCCG4Q_put_ActThroughNetworkType_Proxy( 
    IActCCG4Q __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB IActCCG4Q_put_ActThroughNetworkType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IActCCG4Q_INTERFACE_DEFINED__ */


#ifndef __IActCCG4Q2_INTERFACE_DEFINED__
#define __IActCCG4Q2_INTERFACE_DEFINED__

/* interface IActCCG4Q2 */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IActCCG4Q2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("87166042-710B-11d5-9318-009099244EFD")
    IActCCG4Q2 : public IActCCG4Q
    {
    public:
    };
    
#else 	/* C style interface */

    typedef struct IActCCG4Q2Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IActCCG4Q2 __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IActCCG4Q2 __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IActCCG4Q2 __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IActCCG4Q2 __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IActCCG4Q2 __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IActCCG4Q2 __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IActCCG4Q2 __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Open )( 
            IActCCG4Q2 __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Close )( 
            IActCCG4Q2 __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetDevice )( 
            IActCCG4Q2 __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [out] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetDevice )( 
            IActCCG4Q2 __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceBlock )( 
            IActCCG4Q2 __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lSize,
            /* [size_is][out] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceBlock )( 
            IActCCG4Q2 __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lSize,
            /* [size_is][in] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceRandom )( 
            IActCCG4Q2 __RPC_FAR * This,
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG lSize,
            /* [size_is][out] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceRandom )( 
            IActCCG4Q2 __RPC_FAR * This,
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG lSize,
            /* [size_is][in] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadBuffer )( 
            IActCCG4Q2 __RPC_FAR * This,
            /* [in] */ LONG lStartIO,
            /* [in] */ LONG lAddress,
            /* [in] */ LONG lReadSize,
            /* [size_is][out] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteBuffer )( 
            IActCCG4Q2 __RPC_FAR * This,
            /* [in] */ LONG lStartIO,
            /* [in] */ LONG lAddress,
            /* [in] */ LONG lWriteSize,
            /* [size_is][in] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetClockData )( 
            IActCCG4Q2 __RPC_FAR * This,
            /* [out] */ SHORT __RPC_FAR *lpsYear,
            /* [out] */ SHORT __RPC_FAR *lpsMonth,
            /* [out] */ SHORT __RPC_FAR *lpsDay,
            /* [out] */ SHORT __RPC_FAR *lpsDayOfWeek,
            /* [out] */ SHORT __RPC_FAR *lpsHour,
            /* [out] */ SHORT __RPC_FAR *lpsMinute,
            /* [out] */ SHORT __RPC_FAR *lpsSecond,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetClockData )( 
            IActCCG4Q2 __RPC_FAR * This,
            /* [in] */ SHORT sYear,
            /* [in] */ SHORT sMonth,
            /* [in] */ SHORT sDay,
            /* [in] */ SHORT sDayOfWeek,
            /* [in] */ SHORT sHour,
            /* [in] */ SHORT sMinute,
            /* [in] */ SHORT sSecond,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetCpuType )( 
            IActCCG4Q2 __RPC_FAR * This,
            /* [string][out] */ BSTR __RPC_FAR *szCpuName,
            /* [out] */ LONG __RPC_FAR *lplCpuCode,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetCpuStatus )( 
            IActCCG4Q2 __RPC_FAR * This,
            /* [in] */ LONG lOperation,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CheckDeviceString )( 
            IActCCG4Q2 __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lCheckType,
            /* [in] */ LONG lSize,
            /* [out] */ LONG __RPC_FAR *lplDeviceType,
            /* [string][out] */ BSTR __RPC_FAR *lpszDeviceName,
            /* [out] */ LONG __RPC_FAR *lplDeviceNumber,
            /* [out] */ LONG __RPC_FAR *lplDeviceRadix,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *EntryDeviceStatus )( 
            IActCCG4Q2 __RPC_FAR * This,
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG lSize,
            /* [in] */ LONG lMonitorCycle,
            /* [size_is][in] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *FreeDeviceStatus )( 
            IActCCG4Q2 __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceBlock2 )( 
            IActCCG4Q2 __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lSize,
            /* [size_is][out] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceBlock2 )( 
            IActCCG4Q2 __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lSize,
            /* [size_is][in] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceRandom2 )( 
            IActCCG4Q2 __RPC_FAR * This,
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG lSize,
            /* [size_is][out] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceRandom2 )( 
            IActCCG4Q2 __RPC_FAR * This,
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG lSize,
            /* [size_is][in] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetDevice2 )( 
            IActCCG4Q2 __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [out] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetDevice2 )( 
            IActCCG4Q2 __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ SHORT sData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActNetworkNumber )( 
            IActCCG4Q2 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActNetworkNumber )( 
            IActCCG4Q2 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActStationNumber )( 
            IActCCG4Q2 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActStationNumber )( 
            IActCCG4Q2 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActUnitNumber )( 
            IActCCG4Q2 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActUnitNumber )( 
            IActCCG4Q2 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActConnectUnitNumber )( 
            IActCCG4Q2 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActConnectUnitNumber )( 
            IActCCG4Q2 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActIONumber )( 
            IActCCG4Q2 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActIONumber )( 
            IActCCG4Q2 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActCpuType )( 
            IActCCG4Q2 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActCpuType )( 
            IActCCG4Q2 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActPortNumber )( 
            IActCCG4Q2 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActPortNumber )( 
            IActCCG4Q2 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActBaudRate )( 
            IActCCG4Q2 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActBaudRate )( 
            IActCCG4Q2 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActControl )( 
            IActCCG4Q2 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActControl )( 
            IActCCG4Q2 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActTimeOut )( 
            IActCCG4Q2 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActTimeOut )( 
            IActCCG4Q2 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActThroughNetworkType )( 
            IActCCG4Q2 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActThroughNetworkType )( 
            IActCCG4Q2 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        END_INTERFACE
    } IActCCG4Q2Vtbl;

    interface IActCCG4Q2
    {
        CONST_VTBL struct IActCCG4Q2Vtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IActCCG4Q2_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IActCCG4Q2_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IActCCG4Q2_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IActCCG4Q2_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IActCCG4Q2_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IActCCG4Q2_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IActCCG4Q2_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IActCCG4Q2_Open(This,lplReturnCode)	\
    (This)->lpVtbl -> Open(This,lplReturnCode)

#define IActCCG4Q2_Close(This,lplReturnCode)	\
    (This)->lpVtbl -> Close(This,lplReturnCode)

#define IActCCG4Q2_GetDevice(This,szDevice,lplData,lplReturnCode)	\
    (This)->lpVtbl -> GetDevice(This,szDevice,lplData,lplReturnCode)

#define IActCCG4Q2_SetDevice(This,szDevice,lData,lplReturnCode)	\
    (This)->lpVtbl -> SetDevice(This,szDevice,lData,lplReturnCode)

#define IActCCG4Q2_ReadDeviceBlock(This,szDevice,lSize,lplData,lplReturnCode)	\
    (This)->lpVtbl -> ReadDeviceBlock(This,szDevice,lSize,lplData,lplReturnCode)

#define IActCCG4Q2_WriteDeviceBlock(This,szDevice,lSize,lplData,lplReturnCode)	\
    (This)->lpVtbl -> WriteDeviceBlock(This,szDevice,lSize,lplData,lplReturnCode)

#define IActCCG4Q2_ReadDeviceRandom(This,szDeviceList,lSize,lplData,lplReturnCode)	\
    (This)->lpVtbl -> ReadDeviceRandom(This,szDeviceList,lSize,lplData,lplReturnCode)

#define IActCCG4Q2_WriteDeviceRandom(This,szDeviceList,lSize,lplData,lplReturnCode)	\
    (This)->lpVtbl -> WriteDeviceRandom(This,szDeviceList,lSize,lplData,lplReturnCode)

#define IActCCG4Q2_ReadBuffer(This,lStartIO,lAddress,lReadSize,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> ReadBuffer(This,lStartIO,lAddress,lReadSize,lpsData,lplReturnCode)

#define IActCCG4Q2_WriteBuffer(This,lStartIO,lAddress,lWriteSize,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> WriteBuffer(This,lStartIO,lAddress,lWriteSize,lpsData,lplReturnCode)

#define IActCCG4Q2_GetClockData(This,lpsYear,lpsMonth,lpsDay,lpsDayOfWeek,lpsHour,lpsMinute,lpsSecond,lplReturnCode)	\
    (This)->lpVtbl -> GetClockData(This,lpsYear,lpsMonth,lpsDay,lpsDayOfWeek,lpsHour,lpsMinute,lpsSecond,lplReturnCode)

#define IActCCG4Q2_SetClockData(This,sYear,sMonth,sDay,sDayOfWeek,sHour,sMinute,sSecond,lplReturnCode)	\
    (This)->lpVtbl -> SetClockData(This,sYear,sMonth,sDay,sDayOfWeek,sHour,sMinute,sSecond,lplReturnCode)

#define IActCCG4Q2_GetCpuType(This,szCpuName,lplCpuCode,lplReturnCode)	\
    (This)->lpVtbl -> GetCpuType(This,szCpuName,lplCpuCode,lplReturnCode)

#define IActCCG4Q2_SetCpuStatus(This,lOperation,lplReturnCode)	\
    (This)->lpVtbl -> SetCpuStatus(This,lOperation,lplReturnCode)

#define IActCCG4Q2_CheckDeviceString(This,szDevice,lCheckType,lSize,lplDeviceType,lpszDeviceName,lplDeviceNumber,lplDeviceRadix,lplReturnCode)	\
    (This)->lpVtbl -> CheckDeviceString(This,szDevice,lCheckType,lSize,lplDeviceType,lpszDeviceName,lplDeviceNumber,lplDeviceRadix,lplReturnCode)

#define IActCCG4Q2_EntryDeviceStatus(This,szDeviceList,lSize,lMonitorCycle,lplData,lplReturnCode)	\
    (This)->lpVtbl -> EntryDeviceStatus(This,szDeviceList,lSize,lMonitorCycle,lplData,lplReturnCode)

#define IActCCG4Q2_FreeDeviceStatus(This,lplReturnCode)	\
    (This)->lpVtbl -> FreeDeviceStatus(This,lplReturnCode)

#define IActCCG4Q2_ReadDeviceBlock2(This,szDevice,lSize,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> ReadDeviceBlock2(This,szDevice,lSize,lpsData,lplReturnCode)

#define IActCCG4Q2_WriteDeviceBlock2(This,szDevice,lSize,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> WriteDeviceBlock2(This,szDevice,lSize,lpsData,lplReturnCode)

#define IActCCG4Q2_ReadDeviceRandom2(This,szDeviceList,lSize,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> ReadDeviceRandom2(This,szDeviceList,lSize,lpsData,lplReturnCode)

#define IActCCG4Q2_WriteDeviceRandom2(This,szDeviceList,lSize,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> WriteDeviceRandom2(This,szDeviceList,lSize,lpsData,lplReturnCode)

#define IActCCG4Q2_GetDevice2(This,szDevice,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> GetDevice2(This,szDevice,lpsData,lplReturnCode)

#define IActCCG4Q2_SetDevice2(This,szDevice,sData,lplReturnCode)	\
    (This)->lpVtbl -> SetDevice2(This,szDevice,sData,lplReturnCode)

#define IActCCG4Q2_get_ActNetworkNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActNetworkNumber(This,pVal)

#define IActCCG4Q2_put_ActNetworkNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActNetworkNumber(This,newVal)

#define IActCCG4Q2_get_ActStationNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActStationNumber(This,pVal)

#define IActCCG4Q2_put_ActStationNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActStationNumber(This,newVal)

#define IActCCG4Q2_get_ActUnitNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActUnitNumber(This,pVal)

#define IActCCG4Q2_put_ActUnitNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActUnitNumber(This,newVal)

#define IActCCG4Q2_get_ActConnectUnitNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActConnectUnitNumber(This,pVal)

#define IActCCG4Q2_put_ActConnectUnitNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActConnectUnitNumber(This,newVal)

#define IActCCG4Q2_get_ActIONumber(This,pVal)	\
    (This)->lpVtbl -> get_ActIONumber(This,pVal)

#define IActCCG4Q2_put_ActIONumber(This,newVal)	\
    (This)->lpVtbl -> put_ActIONumber(This,newVal)

#define IActCCG4Q2_get_ActCpuType(This,pVal)	\
    (This)->lpVtbl -> get_ActCpuType(This,pVal)

#define IActCCG4Q2_put_ActCpuType(This,newVal)	\
    (This)->lpVtbl -> put_ActCpuType(This,newVal)

#define IActCCG4Q2_get_ActPortNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActPortNumber(This,pVal)

#define IActCCG4Q2_put_ActPortNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActPortNumber(This,newVal)

#define IActCCG4Q2_get_ActBaudRate(This,pVal)	\
    (This)->lpVtbl -> get_ActBaudRate(This,pVal)

#define IActCCG4Q2_put_ActBaudRate(This,newVal)	\
    (This)->lpVtbl -> put_ActBaudRate(This,newVal)

#define IActCCG4Q2_get_ActControl(This,pVal)	\
    (This)->lpVtbl -> get_ActControl(This,pVal)

#define IActCCG4Q2_put_ActControl(This,newVal)	\
    (This)->lpVtbl -> put_ActControl(This,newVal)

#define IActCCG4Q2_get_ActTimeOut(This,pVal)	\
    (This)->lpVtbl -> get_ActTimeOut(This,pVal)

#define IActCCG4Q2_put_ActTimeOut(This,newVal)	\
    (This)->lpVtbl -> put_ActTimeOut(This,newVal)

#define IActCCG4Q2_get_ActThroughNetworkType(This,pVal)	\
    (This)->lpVtbl -> get_ActThroughNetworkType(This,pVal)

#define IActCCG4Q2_put_ActThroughNetworkType(This,newVal)	\
    (This)->lpVtbl -> put_ActThroughNetworkType(This,newVal)


#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IActCCG4Q2_INTERFACE_DEFINED__ */


#ifndef __IActCCG4Q3_INTERFACE_DEFINED__
#define __IActCCG4Q3_INTERFACE_DEFINED__

/* interface IActCCG4Q3 */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IActCCG4Q3;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("87166043-710B-11d5-9318-009099244EFD")
    IActCCG4Q3 : public IActCCG4Q2
    {
    public:
    };
    
#else 	/* C style interface */

    typedef struct IActCCG4Q3Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IActCCG4Q3 __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IActCCG4Q3 __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IActCCG4Q3 __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IActCCG4Q3 __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IActCCG4Q3 __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IActCCG4Q3 __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IActCCG4Q3 __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Open )( 
            IActCCG4Q3 __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Close )( 
            IActCCG4Q3 __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetDevice )( 
            IActCCG4Q3 __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [out] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetDevice )( 
            IActCCG4Q3 __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceBlock )( 
            IActCCG4Q3 __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lSize,
            /* [size_is][out] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceBlock )( 
            IActCCG4Q3 __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lSize,
            /* [size_is][in] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceRandom )( 
            IActCCG4Q3 __RPC_FAR * This,
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG lSize,
            /* [size_is][out] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceRandom )( 
            IActCCG4Q3 __RPC_FAR * This,
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG lSize,
            /* [size_is][in] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadBuffer )( 
            IActCCG4Q3 __RPC_FAR * This,
            /* [in] */ LONG lStartIO,
            /* [in] */ LONG lAddress,
            /* [in] */ LONG lReadSize,
            /* [size_is][out] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteBuffer )( 
            IActCCG4Q3 __RPC_FAR * This,
            /* [in] */ LONG lStartIO,
            /* [in] */ LONG lAddress,
            /* [in] */ LONG lWriteSize,
            /* [size_is][in] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetClockData )( 
            IActCCG4Q3 __RPC_FAR * This,
            /* [out] */ SHORT __RPC_FAR *lpsYear,
            /* [out] */ SHORT __RPC_FAR *lpsMonth,
            /* [out] */ SHORT __RPC_FAR *lpsDay,
            /* [out] */ SHORT __RPC_FAR *lpsDayOfWeek,
            /* [out] */ SHORT __RPC_FAR *lpsHour,
            /* [out] */ SHORT __RPC_FAR *lpsMinute,
            /* [out] */ SHORT __RPC_FAR *lpsSecond,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetClockData )( 
            IActCCG4Q3 __RPC_FAR * This,
            /* [in] */ SHORT sYear,
            /* [in] */ SHORT sMonth,
            /* [in] */ SHORT sDay,
            /* [in] */ SHORT sDayOfWeek,
            /* [in] */ SHORT sHour,
            /* [in] */ SHORT sMinute,
            /* [in] */ SHORT sSecond,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetCpuType )( 
            IActCCG4Q3 __RPC_FAR * This,
            /* [string][out] */ BSTR __RPC_FAR *szCpuName,
            /* [out] */ LONG __RPC_FAR *lplCpuCode,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetCpuStatus )( 
            IActCCG4Q3 __RPC_FAR * This,
            /* [in] */ LONG lOperation,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CheckDeviceString )( 
            IActCCG4Q3 __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lCheckType,
            /* [in] */ LONG lSize,
            /* [out] */ LONG __RPC_FAR *lplDeviceType,
            /* [string][out] */ BSTR __RPC_FAR *lpszDeviceName,
            /* [out] */ LONG __RPC_FAR *lplDeviceNumber,
            /* [out] */ LONG __RPC_FAR *lplDeviceRadix,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *EntryDeviceStatus )( 
            IActCCG4Q3 __RPC_FAR * This,
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG lSize,
            /* [in] */ LONG lMonitorCycle,
            /* [size_is][in] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *FreeDeviceStatus )( 
            IActCCG4Q3 __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceBlock2 )( 
            IActCCG4Q3 __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lSize,
            /* [size_is][out] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceBlock2 )( 
            IActCCG4Q3 __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lSize,
            /* [size_is][in] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceRandom2 )( 
            IActCCG4Q3 __RPC_FAR * This,
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG lSize,
            /* [size_is][out] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceRandom2 )( 
            IActCCG4Q3 __RPC_FAR * This,
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG lSize,
            /* [size_is][in] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetDevice2 )( 
            IActCCG4Q3 __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [out] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetDevice2 )( 
            IActCCG4Q3 __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ SHORT sData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActNetworkNumber )( 
            IActCCG4Q3 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActNetworkNumber )( 
            IActCCG4Q3 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActStationNumber )( 
            IActCCG4Q3 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActStationNumber )( 
            IActCCG4Q3 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActUnitNumber )( 
            IActCCG4Q3 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActUnitNumber )( 
            IActCCG4Q3 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActConnectUnitNumber )( 
            IActCCG4Q3 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActConnectUnitNumber )( 
            IActCCG4Q3 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActIONumber )( 
            IActCCG4Q3 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActIONumber )( 
            IActCCG4Q3 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActCpuType )( 
            IActCCG4Q3 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActCpuType )( 
            IActCCG4Q3 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActPortNumber )( 
            IActCCG4Q3 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActPortNumber )( 
            IActCCG4Q3 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActBaudRate )( 
            IActCCG4Q3 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActBaudRate )( 
            IActCCG4Q3 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActControl )( 
            IActCCG4Q3 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActControl )( 
            IActCCG4Q3 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActTimeOut )( 
            IActCCG4Q3 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActTimeOut )( 
            IActCCG4Q3 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActThroughNetworkType )( 
            IActCCG4Q3 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActThroughNetworkType )( 
            IActCCG4Q3 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        END_INTERFACE
    } IActCCG4Q3Vtbl;

    interface IActCCG4Q3
    {
        CONST_VTBL struct IActCCG4Q3Vtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IActCCG4Q3_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IActCCG4Q3_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IActCCG4Q3_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IActCCG4Q3_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IActCCG4Q3_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IActCCG4Q3_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IActCCG4Q3_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IActCCG4Q3_Open(This,lplReturnCode)	\
    (This)->lpVtbl -> Open(This,lplReturnCode)

#define IActCCG4Q3_Close(This,lplReturnCode)	\
    (This)->lpVtbl -> Close(This,lplReturnCode)

#define IActCCG4Q3_GetDevice(This,szDevice,lplData,lplReturnCode)	\
    (This)->lpVtbl -> GetDevice(This,szDevice,lplData,lplReturnCode)

#define IActCCG4Q3_SetDevice(This,szDevice,lData,lplReturnCode)	\
    (This)->lpVtbl -> SetDevice(This,szDevice,lData,lplReturnCode)

#define IActCCG4Q3_ReadDeviceBlock(This,szDevice,lSize,lplData,lplReturnCode)	\
    (This)->lpVtbl -> ReadDeviceBlock(This,szDevice,lSize,lplData,lplReturnCode)

#define IActCCG4Q3_WriteDeviceBlock(This,szDevice,lSize,lplData,lplReturnCode)	\
    (This)->lpVtbl -> WriteDeviceBlock(This,szDevice,lSize,lplData,lplReturnCode)

#define IActCCG4Q3_ReadDeviceRandom(This,szDeviceList,lSize,lplData,lplReturnCode)	\
    (This)->lpVtbl -> ReadDeviceRandom(This,szDeviceList,lSize,lplData,lplReturnCode)

#define IActCCG4Q3_WriteDeviceRandom(This,szDeviceList,lSize,lplData,lplReturnCode)	\
    (This)->lpVtbl -> WriteDeviceRandom(This,szDeviceList,lSize,lplData,lplReturnCode)

#define IActCCG4Q3_ReadBuffer(This,lStartIO,lAddress,lReadSize,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> ReadBuffer(This,lStartIO,lAddress,lReadSize,lpsData,lplReturnCode)

#define IActCCG4Q3_WriteBuffer(This,lStartIO,lAddress,lWriteSize,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> WriteBuffer(This,lStartIO,lAddress,lWriteSize,lpsData,lplReturnCode)

#define IActCCG4Q3_GetClockData(This,lpsYear,lpsMonth,lpsDay,lpsDayOfWeek,lpsHour,lpsMinute,lpsSecond,lplReturnCode)	\
    (This)->lpVtbl -> GetClockData(This,lpsYear,lpsMonth,lpsDay,lpsDayOfWeek,lpsHour,lpsMinute,lpsSecond,lplReturnCode)

#define IActCCG4Q3_SetClockData(This,sYear,sMonth,sDay,sDayOfWeek,sHour,sMinute,sSecond,lplReturnCode)	\
    (This)->lpVtbl -> SetClockData(This,sYear,sMonth,sDay,sDayOfWeek,sHour,sMinute,sSecond,lplReturnCode)

#define IActCCG4Q3_GetCpuType(This,szCpuName,lplCpuCode,lplReturnCode)	\
    (This)->lpVtbl -> GetCpuType(This,szCpuName,lplCpuCode,lplReturnCode)

#define IActCCG4Q3_SetCpuStatus(This,lOperation,lplReturnCode)	\
    (This)->lpVtbl -> SetCpuStatus(This,lOperation,lplReturnCode)

#define IActCCG4Q3_CheckDeviceString(This,szDevice,lCheckType,lSize,lplDeviceType,lpszDeviceName,lplDeviceNumber,lplDeviceRadix,lplReturnCode)	\
    (This)->lpVtbl -> CheckDeviceString(This,szDevice,lCheckType,lSize,lplDeviceType,lpszDeviceName,lplDeviceNumber,lplDeviceRadix,lplReturnCode)

#define IActCCG4Q3_EntryDeviceStatus(This,szDeviceList,lSize,lMonitorCycle,lplData,lplReturnCode)	\
    (This)->lpVtbl -> EntryDeviceStatus(This,szDeviceList,lSize,lMonitorCycle,lplData,lplReturnCode)

#define IActCCG4Q3_FreeDeviceStatus(This,lplReturnCode)	\
    (This)->lpVtbl -> FreeDeviceStatus(This,lplReturnCode)

#define IActCCG4Q3_ReadDeviceBlock2(This,szDevice,lSize,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> ReadDeviceBlock2(This,szDevice,lSize,lpsData,lplReturnCode)

#define IActCCG4Q3_WriteDeviceBlock2(This,szDevice,lSize,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> WriteDeviceBlock2(This,szDevice,lSize,lpsData,lplReturnCode)

#define IActCCG4Q3_ReadDeviceRandom2(This,szDeviceList,lSize,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> ReadDeviceRandom2(This,szDeviceList,lSize,lpsData,lplReturnCode)

#define IActCCG4Q3_WriteDeviceRandom2(This,szDeviceList,lSize,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> WriteDeviceRandom2(This,szDeviceList,lSize,lpsData,lplReturnCode)

#define IActCCG4Q3_GetDevice2(This,szDevice,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> GetDevice2(This,szDevice,lpsData,lplReturnCode)

#define IActCCG4Q3_SetDevice2(This,szDevice,sData,lplReturnCode)	\
    (This)->lpVtbl -> SetDevice2(This,szDevice,sData,lplReturnCode)

#define IActCCG4Q3_get_ActNetworkNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActNetworkNumber(This,pVal)

#define IActCCG4Q3_put_ActNetworkNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActNetworkNumber(This,newVal)

#define IActCCG4Q3_get_ActStationNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActStationNumber(This,pVal)

#define IActCCG4Q3_put_ActStationNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActStationNumber(This,newVal)

#define IActCCG4Q3_get_ActUnitNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActUnitNumber(This,pVal)

#define IActCCG4Q3_put_ActUnitNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActUnitNumber(This,newVal)

#define IActCCG4Q3_get_ActConnectUnitNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActConnectUnitNumber(This,pVal)

#define IActCCG4Q3_put_ActConnectUnitNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActConnectUnitNumber(This,newVal)

#define IActCCG4Q3_get_ActIONumber(This,pVal)	\
    (This)->lpVtbl -> get_ActIONumber(This,pVal)

#define IActCCG4Q3_put_ActIONumber(This,newVal)	\
    (This)->lpVtbl -> put_ActIONumber(This,newVal)

#define IActCCG4Q3_get_ActCpuType(This,pVal)	\
    (This)->lpVtbl -> get_ActCpuType(This,pVal)

#define IActCCG4Q3_put_ActCpuType(This,newVal)	\
    (This)->lpVtbl -> put_ActCpuType(This,newVal)

#define IActCCG4Q3_get_ActPortNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActPortNumber(This,pVal)

#define IActCCG4Q3_put_ActPortNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActPortNumber(This,newVal)

#define IActCCG4Q3_get_ActBaudRate(This,pVal)	\
    (This)->lpVtbl -> get_ActBaudRate(This,pVal)

#define IActCCG4Q3_put_ActBaudRate(This,newVal)	\
    (This)->lpVtbl -> put_ActBaudRate(This,newVal)

#define IActCCG4Q3_get_ActControl(This,pVal)	\
    (This)->lpVtbl -> get_ActControl(This,pVal)

#define IActCCG4Q3_put_ActControl(This,newVal)	\
    (This)->lpVtbl -> put_ActControl(This,newVal)

#define IActCCG4Q3_get_ActTimeOut(This,pVal)	\
    (This)->lpVtbl -> get_ActTimeOut(This,pVal)

#define IActCCG4Q3_put_ActTimeOut(This,newVal)	\
    (This)->lpVtbl -> put_ActTimeOut(This,newVal)

#define IActCCG4Q3_get_ActThroughNetworkType(This,pVal)	\
    (This)->lpVtbl -> get_ActThroughNetworkType(This,pVal)

#define IActCCG4Q3_put_ActThroughNetworkType(This,newVal)	\
    (This)->lpVtbl -> put_ActThroughNetworkType(This,newVal)



#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IActCCG4Q3_INTERFACE_DEFINED__ */


#ifndef __IActMLCCG4Q_INTERFACE_DEFINED__
#define __IActMLCCG4Q_INTERFACE_DEFINED__

/* interface IActMLCCG4Q */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IActMLCCG4Q;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("EA97CD61-70EB-11D5-9318-009099244EFD")
    IActMLCCG4Q : public IDispatch
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
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActConnectUnitNumber( 
            /* [retval][out] */ VARIANT __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActConnectUnitNumber( 
            /* [in] */ VARIANT newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActIONumber( 
            /* [retval][out] */ VARIANT __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActIONumber( 
            /* [in] */ VARIANT newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActCpuType( 
            /* [retval][out] */ VARIANT __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActCpuType( 
            /* [in] */ VARIANT newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActPortNumber( 
            /* [retval][out] */ VARIANT __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActPortNumber( 
            /* [in] */ VARIANT newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActBaudRate( 
            /* [retval][out] */ VARIANT __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActBaudRate( 
            /* [in] */ VARIANT newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActControl( 
            /* [retval][out] */ VARIANT __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActControl( 
            /* [in] */ VARIANT newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActTimeOut( 
            /* [retval][out] */ VARIANT __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActTimeOut( 
            /* [in] */ VARIANT newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActThroughNetworkType( 
            /* [retval][out] */ VARIANT __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActThroughNetworkType( 
            /* [in] */ VARIANT newVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IActMLCCG4QVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IActMLCCG4Q __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IActMLCCG4Q __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IActMLCCG4Q __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IActMLCCG4Q __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IActMLCCG4Q __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IActMLCCG4Q __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IActMLCCG4Q __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Open )( 
            IActMLCCG4Q __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Close )( 
            IActMLCCG4Q __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetDevice )( 
            IActMLCCG4Q __RPC_FAR * This,
            /* [in] */ VARIANT varDevice,
            /* [out] */ VARIANT __RPC_FAR *lpvarData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetDevice )( 
            IActMLCCG4Q __RPC_FAR * This,
            /* [in] */ VARIANT varDevice,
            /* [in] */ VARIANT varData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceBlock )( 
            IActMLCCG4Q __RPC_FAR * This,
            /* [in] */ VARIANT varDevice,
            /* [in] */ VARIANT varSize,
            /* [out] */ VARIANT __RPC_FAR *lpvarData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceBlock )( 
            IActMLCCG4Q __RPC_FAR * This,
            /* [in] */ VARIANT varDevice,
            /* [in] */ VARIANT varSize,
            /* [in] */ VARIANT varData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceRandom )( 
            IActMLCCG4Q __RPC_FAR * This,
            /* [in] */ VARIANT varDeviceList,
            /* [in] */ VARIANT varSize,
            /* [out] */ VARIANT __RPC_FAR *lpvarData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceRandom )( 
            IActMLCCG4Q __RPC_FAR * This,
            /* [in] */ VARIANT varDeviceList,
            /* [in] */ VARIANT varSize,
            /* [in] */ VARIANT varData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadBuffer )( 
            IActMLCCG4Q __RPC_FAR * This,
            /* [in] */ VARIANT varStartIO,
            /* [in] */ VARIANT varAddress,
            /* [in] */ VARIANT varReadSize,
            /* [out] */ VARIANT __RPC_FAR *lpvarData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteBuffer )( 
            IActMLCCG4Q __RPC_FAR * This,
            /* [in] */ VARIANT varStartIO,
            /* [in] */ VARIANT varAddress,
            /* [in] */ VARIANT varWriteSize,
            /* [in] */ VARIANT varData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetClockData )( 
            IActMLCCG4Q __RPC_FAR * This,
            /* [out] */ VARIANT __RPC_FAR *lpvarYear,
            /* [out] */ VARIANT __RPC_FAR *lpvarMonth,
            /* [out] */ VARIANT __RPC_FAR *lpvarDay,
            /* [out] */ VARIANT __RPC_FAR *lpvarDayOfWeek,
            /* [out] */ VARIANT __RPC_FAR *lpvarHour,
            /* [out] */ VARIANT __RPC_FAR *lpvarMinute,
            /* [out] */ VARIANT __RPC_FAR *lpvarSecond,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetClockData )( 
            IActMLCCG4Q __RPC_FAR * This,
            /* [in] */ VARIANT varYear,
            /* [in] */ VARIANT varMonth,
            /* [in] */ VARIANT varDay,
            /* [in] */ VARIANT varDayOfWeek,
            /* [in] */ VARIANT varHour,
            /* [in] */ VARIANT varMinute,
            /* [in] */ VARIANT varSecond,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetCpuType )( 
            IActMLCCG4Q __RPC_FAR * This,
            /* [out] */ VARIANT __RPC_FAR *lpvarCpuName,
            /* [out] */ VARIANT __RPC_FAR *lpvarCpuType,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetCpuStatus )( 
            IActMLCCG4Q __RPC_FAR * This,
            /* [in] */ VARIANT varOperation,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *EntryDeviceStatus )( 
            IActMLCCG4Q __RPC_FAR * This,
            /* [in] */ VARIANT varDeviceList,
            /* [in] */ VARIANT varSize,
            /* [in] */ VARIANT varMonitorCycle,
            /* [in] */ VARIANT varData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *FreeDeviceStatus )( 
            IActMLCCG4Q __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceBlock2 )( 
            IActMLCCG4Q __RPC_FAR * This,
            /* [in] */ VARIANT varDevice,
            /* [in] */ VARIANT varSize,
            /* [out] */ VARIANT __RPC_FAR *lpvarData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceBlock2 )( 
            IActMLCCG4Q __RPC_FAR * This,
            /* [in] */ VARIANT varDevice,
            /* [in] */ VARIANT varSize,
            /* [in] */ VARIANT varData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceRandom2 )( 
            IActMLCCG4Q __RPC_FAR * This,
            /* [in] */ VARIANT varDeviceList,
            /* [in] */ VARIANT varSize,
            /* [out] */ VARIANT __RPC_FAR *lpvarData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceRandom2 )( 
            IActMLCCG4Q __RPC_FAR * This,
            /* [in] */ VARIANT varDeviceList,
            /* [in] */ VARIANT varSize,
            /* [in] */ VARIANT varData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetDevice2 )( 
            IActMLCCG4Q __RPC_FAR * This,
            /* [in] */ VARIANT varDevice,
            /* [out] */ VARIANT __RPC_FAR *lpvarData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetDevice2 )( 
            IActMLCCG4Q __RPC_FAR * This,
            /* [in] */ VARIANT varDevice,
            /* [in] */ VARIANT varData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActNetworkNumber )( 
            IActMLCCG4Q __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActNetworkNumber )( 
            IActMLCCG4Q __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActStationNumber )( 
            IActMLCCG4Q __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActStationNumber )( 
            IActMLCCG4Q __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActUnitNumber )( 
            IActMLCCG4Q __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActUnitNumber )( 
            IActMLCCG4Q __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActConnectUnitNumber )( 
            IActMLCCG4Q __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActConnectUnitNumber )( 
            IActMLCCG4Q __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActIONumber )( 
            IActMLCCG4Q __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActIONumber )( 
            IActMLCCG4Q __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActCpuType )( 
            IActMLCCG4Q __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActCpuType )( 
            IActMLCCG4Q __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActPortNumber )( 
            IActMLCCG4Q __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActPortNumber )( 
            IActMLCCG4Q __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActBaudRate )( 
            IActMLCCG4Q __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActBaudRate )( 
            IActMLCCG4Q __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActControl )( 
            IActMLCCG4Q __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActControl )( 
            IActMLCCG4Q __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActTimeOut )( 
            IActMLCCG4Q __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActTimeOut )( 
            IActMLCCG4Q __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActThroughNetworkType )( 
            IActMLCCG4Q __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActThroughNetworkType )( 
            IActMLCCG4Q __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        END_INTERFACE
    } IActMLCCG4QVtbl;

    interface IActMLCCG4Q
    {
        CONST_VTBL struct IActMLCCG4QVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IActMLCCG4Q_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IActMLCCG4Q_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IActMLCCG4Q_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IActMLCCG4Q_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IActMLCCG4Q_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IActMLCCG4Q_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IActMLCCG4Q_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IActMLCCG4Q_Open(This,lpvarReturnCode)	\
    (This)->lpVtbl -> Open(This,lpvarReturnCode)

#define IActMLCCG4Q_Close(This,lpvarReturnCode)	\
    (This)->lpVtbl -> Close(This,lpvarReturnCode)

#define IActMLCCG4Q_GetDevice(This,varDevice,lpvarData,lpvarReturnCode)	\
    (This)->lpVtbl -> GetDevice(This,varDevice,lpvarData,lpvarReturnCode)

#define IActMLCCG4Q_SetDevice(This,varDevice,varData,lpvarReturnCode)	\
    (This)->lpVtbl -> SetDevice(This,varDevice,varData,lpvarReturnCode)

#define IActMLCCG4Q_ReadDeviceBlock(This,varDevice,varSize,lpvarData,lpvarReturnCode)	\
    (This)->lpVtbl -> ReadDeviceBlock(This,varDevice,varSize,lpvarData,lpvarReturnCode)

#define IActMLCCG4Q_WriteDeviceBlock(This,varDevice,varSize,varData,lpvarReturnCode)	\
    (This)->lpVtbl -> WriteDeviceBlock(This,varDevice,varSize,varData,lpvarReturnCode)

#define IActMLCCG4Q_ReadDeviceRandom(This,varDeviceList,varSize,lpvarData,lpvarReturnCode)	\
    (This)->lpVtbl -> ReadDeviceRandom(This,varDeviceList,varSize,lpvarData,lpvarReturnCode)

#define IActMLCCG4Q_WriteDeviceRandom(This,varDeviceList,varSize,varData,lpvarReturnCode)	\
    (This)->lpVtbl -> WriteDeviceRandom(This,varDeviceList,varSize,varData,lpvarReturnCode)

#define IActMLCCG4Q_ReadBuffer(This,varStartIO,varAddress,varReadSize,lpvarData,lpvarReturnCode)	\
    (This)->lpVtbl -> ReadBuffer(This,varStartIO,varAddress,varReadSize,lpvarData,lpvarReturnCode)

#define IActMLCCG4Q_WriteBuffer(This,varStartIO,varAddress,varWriteSize,varData,lpvarReturnCode)	\
    (This)->lpVtbl -> WriteBuffer(This,varStartIO,varAddress,varWriteSize,varData,lpvarReturnCode)

#define IActMLCCG4Q_GetClockData(This,lpvarYear,lpvarMonth,lpvarDay,lpvarDayOfWeek,lpvarHour,lpvarMinute,lpvarSecond,lpvarReturnCode)	\
    (This)->lpVtbl -> GetClockData(This,lpvarYear,lpvarMonth,lpvarDay,lpvarDayOfWeek,lpvarHour,lpvarMinute,lpvarSecond,lpvarReturnCode)

#define IActMLCCG4Q_SetClockData(This,varYear,varMonth,varDay,varDayOfWeek,varHour,varMinute,varSecond,lpvarReturnCode)	\
    (This)->lpVtbl -> SetClockData(This,varYear,varMonth,varDay,varDayOfWeek,varHour,varMinute,varSecond,lpvarReturnCode)

#define IActMLCCG4Q_GetCpuType(This,lpvarCpuName,lpvarCpuType,lpvarReturnCode)	\
    (This)->lpVtbl -> GetCpuType(This,lpvarCpuName,lpvarCpuType,lpvarReturnCode)

#define IActMLCCG4Q_SetCpuStatus(This,varOperation,lpvarReturnCode)	\
    (This)->lpVtbl -> SetCpuStatus(This,varOperation,lpvarReturnCode)

#define IActMLCCG4Q_EntryDeviceStatus(This,varDeviceList,varSize,varMonitorCycle,varData,lpvarReturnCode)	\
    (This)->lpVtbl -> EntryDeviceStatus(This,varDeviceList,varSize,varMonitorCycle,varData,lpvarReturnCode)

#define IActMLCCG4Q_FreeDeviceStatus(This,lpvarReturnCode)	\
    (This)->lpVtbl -> FreeDeviceStatus(This,lpvarReturnCode)

#define IActMLCCG4Q_ReadDeviceBlock2(This,varDevice,varSize,lpvarData,lpvarReturnCode)	\
    (This)->lpVtbl -> ReadDeviceBlock2(This,varDevice,varSize,lpvarData,lpvarReturnCode)

#define IActMLCCG4Q_WriteDeviceBlock2(This,varDevice,varSize,varData,lpvarReturnCode)	\
    (This)->lpVtbl -> WriteDeviceBlock2(This,varDevice,varSize,varData,lpvarReturnCode)

#define IActMLCCG4Q_ReadDeviceRandom2(This,varDeviceList,varSize,lpvarData,lpvarReturnCode)	\
    (This)->lpVtbl -> ReadDeviceRandom2(This,varDeviceList,varSize,lpvarData,lpvarReturnCode)

#define IActMLCCG4Q_WriteDeviceRandom2(This,varDeviceList,varSize,varData,lpvarReturnCode)	\
    (This)->lpVtbl -> WriteDeviceRandom2(This,varDeviceList,varSize,varData,lpvarReturnCode)

#define IActMLCCG4Q_GetDevice2(This,varDevice,lpvarData,lpvarReturnCode)	\
    (This)->lpVtbl -> GetDevice2(This,varDevice,lpvarData,lpvarReturnCode)

#define IActMLCCG4Q_SetDevice2(This,varDevice,varData,lpvarReturnCode)	\
    (This)->lpVtbl -> SetDevice2(This,varDevice,varData,lpvarReturnCode)

#define IActMLCCG4Q_get_ActNetworkNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActNetworkNumber(This,pVal)

#define IActMLCCG4Q_put_ActNetworkNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActNetworkNumber(This,newVal)

#define IActMLCCG4Q_get_ActStationNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActStationNumber(This,pVal)

#define IActMLCCG4Q_put_ActStationNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActStationNumber(This,newVal)

#define IActMLCCG4Q_get_ActUnitNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActUnitNumber(This,pVal)

#define IActMLCCG4Q_put_ActUnitNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActUnitNumber(This,newVal)

#define IActMLCCG4Q_get_ActConnectUnitNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActConnectUnitNumber(This,pVal)

#define IActMLCCG4Q_put_ActConnectUnitNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActConnectUnitNumber(This,newVal)

#define IActMLCCG4Q_get_ActIONumber(This,pVal)	\
    (This)->lpVtbl -> get_ActIONumber(This,pVal)

#define IActMLCCG4Q_put_ActIONumber(This,newVal)	\
    (This)->lpVtbl -> put_ActIONumber(This,newVal)

#define IActMLCCG4Q_get_ActCpuType(This,pVal)	\
    (This)->lpVtbl -> get_ActCpuType(This,pVal)

#define IActMLCCG4Q_put_ActCpuType(This,newVal)	\
    (This)->lpVtbl -> put_ActCpuType(This,newVal)

#define IActMLCCG4Q_get_ActPortNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActPortNumber(This,pVal)

#define IActMLCCG4Q_put_ActPortNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActPortNumber(This,newVal)

#define IActMLCCG4Q_get_ActBaudRate(This,pVal)	\
    (This)->lpVtbl -> get_ActBaudRate(This,pVal)

#define IActMLCCG4Q_put_ActBaudRate(This,newVal)	\
    (This)->lpVtbl -> put_ActBaudRate(This,newVal)

#define IActMLCCG4Q_get_ActControl(This,pVal)	\
    (This)->lpVtbl -> get_ActControl(This,pVal)

#define IActMLCCG4Q_put_ActControl(This,newVal)	\
    (This)->lpVtbl -> put_ActControl(This,newVal)

#define IActMLCCG4Q_get_ActTimeOut(This,pVal)	\
    (This)->lpVtbl -> get_ActTimeOut(This,pVal)

#define IActMLCCG4Q_put_ActTimeOut(This,newVal)	\
    (This)->lpVtbl -> put_ActTimeOut(This,newVal)

#define IActMLCCG4Q_get_ActThroughNetworkType(This,pVal)	\
    (This)->lpVtbl -> get_ActThroughNetworkType(This,pVal)

#define IActMLCCG4Q_put_ActThroughNetworkType(This,newVal)	\
    (This)->lpVtbl -> put_ActThroughNetworkType(This,newVal)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActMLCCG4Q_Open_Proxy( 
    IActMLCCG4Q __RPC_FAR * This,
    /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);


void __RPC_STUB IActMLCCG4Q_Open_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActMLCCG4Q_Close_Proxy( 
    IActMLCCG4Q __RPC_FAR * This,
    /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);


void __RPC_STUB IActMLCCG4Q_Close_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActMLCCG4Q_GetDevice_Proxy( 
    IActMLCCG4Q __RPC_FAR * This,
    /* [in] */ VARIANT varDevice,
    /* [out] */ VARIANT __RPC_FAR *lpvarData,
    /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);


void __RPC_STUB IActMLCCG4Q_GetDevice_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActMLCCG4Q_SetDevice_Proxy( 
    IActMLCCG4Q __RPC_FAR * This,
    /* [in] */ VARIANT varDevice,
    /* [in] */ VARIANT varData,
    /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);


void __RPC_STUB IActMLCCG4Q_SetDevice_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActMLCCG4Q_ReadDeviceBlock_Proxy( 
    IActMLCCG4Q __RPC_FAR * This,
    /* [in] */ VARIANT varDevice,
    /* [in] */ VARIANT varSize,
    /* [out] */ VARIANT __RPC_FAR *lpvarData,
    /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);


void __RPC_STUB IActMLCCG4Q_ReadDeviceBlock_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActMLCCG4Q_WriteDeviceBlock_Proxy( 
    IActMLCCG4Q __RPC_FAR * This,
    /* [in] */ VARIANT varDevice,
    /* [in] */ VARIANT varSize,
    /* [in] */ VARIANT varData,
    /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);


void __RPC_STUB IActMLCCG4Q_WriteDeviceBlock_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActMLCCG4Q_ReadDeviceRandom_Proxy( 
    IActMLCCG4Q __RPC_FAR * This,
    /* [in] */ VARIANT varDeviceList,
    /* [in] */ VARIANT varSize,
    /* [out] */ VARIANT __RPC_FAR *lpvarData,
    /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);


void __RPC_STUB IActMLCCG4Q_ReadDeviceRandom_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActMLCCG4Q_WriteDeviceRandom_Proxy( 
    IActMLCCG4Q __RPC_FAR * This,
    /* [in] */ VARIANT varDeviceList,
    /* [in] */ VARIANT varSize,
    /* [in] */ VARIANT varData,
    /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);


void __RPC_STUB IActMLCCG4Q_WriteDeviceRandom_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActMLCCG4Q_ReadBuffer_Proxy( 
    IActMLCCG4Q __RPC_FAR * This,
    /* [in] */ VARIANT varStartIO,
    /* [in] */ VARIANT varAddress,
    /* [in] */ VARIANT varReadSize,
    /* [out] */ VARIANT __RPC_FAR *lpvarData,
    /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);


void __RPC_STUB IActMLCCG4Q_ReadBuffer_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActMLCCG4Q_WriteBuffer_Proxy( 
    IActMLCCG4Q __RPC_FAR * This,
    /* [in] */ VARIANT varStartIO,
    /* [in] */ VARIANT varAddress,
    /* [in] */ VARIANT varWriteSize,
    /* [in] */ VARIANT varData,
    /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);


void __RPC_STUB IActMLCCG4Q_WriteBuffer_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActMLCCG4Q_GetClockData_Proxy( 
    IActMLCCG4Q __RPC_FAR * This,
    /* [out] */ VARIANT __RPC_FAR *lpvarYear,
    /* [out] */ VARIANT __RPC_FAR *lpvarMonth,
    /* [out] */ VARIANT __RPC_FAR *lpvarDay,
    /* [out] */ VARIANT __RPC_FAR *lpvarDayOfWeek,
    /* [out] */ VARIANT __RPC_FAR *lpvarHour,
    /* [out] */ VARIANT __RPC_FAR *lpvarMinute,
    /* [out] */ VARIANT __RPC_FAR *lpvarSecond,
    /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);


void __RPC_STUB IActMLCCG4Q_GetClockData_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActMLCCG4Q_SetClockData_Proxy( 
    IActMLCCG4Q __RPC_FAR * This,
    /* [in] */ VARIANT varYear,
    /* [in] */ VARIANT varMonth,
    /* [in] */ VARIANT varDay,
    /* [in] */ VARIANT varDayOfWeek,
    /* [in] */ VARIANT varHour,
    /* [in] */ VARIANT varMinute,
    /* [in] */ VARIANT varSecond,
    /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);


void __RPC_STUB IActMLCCG4Q_SetClockData_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActMLCCG4Q_GetCpuType_Proxy( 
    IActMLCCG4Q __RPC_FAR * This,
    /* [out] */ VARIANT __RPC_FAR *lpvarCpuName,
    /* [out] */ VARIANT __RPC_FAR *lpvarCpuType,
    /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);


void __RPC_STUB IActMLCCG4Q_GetCpuType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActMLCCG4Q_SetCpuStatus_Proxy( 
    IActMLCCG4Q __RPC_FAR * This,
    /* [in] */ VARIANT varOperation,
    /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);


void __RPC_STUB IActMLCCG4Q_SetCpuStatus_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActMLCCG4Q_EntryDeviceStatus_Proxy( 
    IActMLCCG4Q __RPC_FAR * This,
    /* [in] */ VARIANT varDeviceList,
    /* [in] */ VARIANT varSize,
    /* [in] */ VARIANT varMonitorCycle,
    /* [in] */ VARIANT varData,
    /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);


void __RPC_STUB IActMLCCG4Q_EntryDeviceStatus_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActMLCCG4Q_FreeDeviceStatus_Proxy( 
    IActMLCCG4Q __RPC_FAR * This,
    /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);


void __RPC_STUB IActMLCCG4Q_FreeDeviceStatus_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActMLCCG4Q_ReadDeviceBlock2_Proxy( 
    IActMLCCG4Q __RPC_FAR * This,
    /* [in] */ VARIANT varDevice,
    /* [in] */ VARIANT varSize,
    /* [out] */ VARIANT __RPC_FAR *lpvarData,
    /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);


void __RPC_STUB IActMLCCG4Q_ReadDeviceBlock2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActMLCCG4Q_WriteDeviceBlock2_Proxy( 
    IActMLCCG4Q __RPC_FAR * This,
    /* [in] */ VARIANT varDevice,
    /* [in] */ VARIANT varSize,
    /* [in] */ VARIANT varData,
    /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);


void __RPC_STUB IActMLCCG4Q_WriteDeviceBlock2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActMLCCG4Q_ReadDeviceRandom2_Proxy( 
    IActMLCCG4Q __RPC_FAR * This,
    /* [in] */ VARIANT varDeviceList,
    /* [in] */ VARIANT varSize,
    /* [out] */ VARIANT __RPC_FAR *lpvarData,
    /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);


void __RPC_STUB IActMLCCG4Q_ReadDeviceRandom2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActMLCCG4Q_WriteDeviceRandom2_Proxy( 
    IActMLCCG4Q __RPC_FAR * This,
    /* [in] */ VARIANT varDeviceList,
    /* [in] */ VARIANT varSize,
    /* [in] */ VARIANT varData,
    /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);


void __RPC_STUB IActMLCCG4Q_WriteDeviceRandom2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActMLCCG4Q_GetDevice2_Proxy( 
    IActMLCCG4Q __RPC_FAR * This,
    /* [in] */ VARIANT varDevice,
    /* [out] */ VARIANT __RPC_FAR *lpvarData,
    /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);


void __RPC_STUB IActMLCCG4Q_GetDevice2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActMLCCG4Q_SetDevice2_Proxy( 
    IActMLCCG4Q __RPC_FAR * This,
    /* [in] */ VARIANT varDevice,
    /* [in] */ VARIANT varData,
    /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);


void __RPC_STUB IActMLCCG4Q_SetDevice2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActMLCCG4Q_get_ActNetworkNumber_Proxy( 
    IActMLCCG4Q __RPC_FAR * This,
    /* [retval][out] */ VARIANT __RPC_FAR *pVal);


void __RPC_STUB IActMLCCG4Q_get_ActNetworkNumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActMLCCG4Q_put_ActNetworkNumber_Proxy( 
    IActMLCCG4Q __RPC_FAR * This,
    /* [in] */ VARIANT newVal);


void __RPC_STUB IActMLCCG4Q_put_ActNetworkNumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActMLCCG4Q_get_ActStationNumber_Proxy( 
    IActMLCCG4Q __RPC_FAR * This,
    /* [retval][out] */ VARIANT __RPC_FAR *pVal);


void __RPC_STUB IActMLCCG4Q_get_ActStationNumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActMLCCG4Q_put_ActStationNumber_Proxy( 
    IActMLCCG4Q __RPC_FAR * This,
    /* [in] */ VARIANT newVal);


void __RPC_STUB IActMLCCG4Q_put_ActStationNumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActMLCCG4Q_get_ActUnitNumber_Proxy( 
    IActMLCCG4Q __RPC_FAR * This,
    /* [retval][out] */ VARIANT __RPC_FAR *pVal);


void __RPC_STUB IActMLCCG4Q_get_ActUnitNumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActMLCCG4Q_put_ActUnitNumber_Proxy( 
    IActMLCCG4Q __RPC_FAR * This,
    /* [in] */ VARIANT newVal);


void __RPC_STUB IActMLCCG4Q_put_ActUnitNumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActMLCCG4Q_get_ActConnectUnitNumber_Proxy( 
    IActMLCCG4Q __RPC_FAR * This,
    /* [retval][out] */ VARIANT __RPC_FAR *pVal);


void __RPC_STUB IActMLCCG4Q_get_ActConnectUnitNumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActMLCCG4Q_put_ActConnectUnitNumber_Proxy( 
    IActMLCCG4Q __RPC_FAR * This,
    /* [in] */ VARIANT newVal);


void __RPC_STUB IActMLCCG4Q_put_ActConnectUnitNumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActMLCCG4Q_get_ActIONumber_Proxy( 
    IActMLCCG4Q __RPC_FAR * This,
    /* [retval][out] */ VARIANT __RPC_FAR *pVal);


void __RPC_STUB IActMLCCG4Q_get_ActIONumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActMLCCG4Q_put_ActIONumber_Proxy( 
    IActMLCCG4Q __RPC_FAR * This,
    /* [in] */ VARIANT newVal);


void __RPC_STUB IActMLCCG4Q_put_ActIONumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActMLCCG4Q_get_ActCpuType_Proxy( 
    IActMLCCG4Q __RPC_FAR * This,
    /* [retval][out] */ VARIANT __RPC_FAR *pVal);


void __RPC_STUB IActMLCCG4Q_get_ActCpuType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActMLCCG4Q_put_ActCpuType_Proxy( 
    IActMLCCG4Q __RPC_FAR * This,
    /* [in] */ VARIANT newVal);


void __RPC_STUB IActMLCCG4Q_put_ActCpuType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActMLCCG4Q_get_ActPortNumber_Proxy( 
    IActMLCCG4Q __RPC_FAR * This,
    /* [retval][out] */ VARIANT __RPC_FAR *pVal);


void __RPC_STUB IActMLCCG4Q_get_ActPortNumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActMLCCG4Q_put_ActPortNumber_Proxy( 
    IActMLCCG4Q __RPC_FAR * This,
    /* [in] */ VARIANT newVal);


void __RPC_STUB IActMLCCG4Q_put_ActPortNumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActMLCCG4Q_get_ActBaudRate_Proxy( 
    IActMLCCG4Q __RPC_FAR * This,
    /* [retval][out] */ VARIANT __RPC_FAR *pVal);


void __RPC_STUB IActMLCCG4Q_get_ActBaudRate_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActMLCCG4Q_put_ActBaudRate_Proxy( 
    IActMLCCG4Q __RPC_FAR * This,
    /* [in] */ VARIANT newVal);


void __RPC_STUB IActMLCCG4Q_put_ActBaudRate_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActMLCCG4Q_get_ActControl_Proxy( 
    IActMLCCG4Q __RPC_FAR * This,
    /* [retval][out] */ VARIANT __RPC_FAR *pVal);


void __RPC_STUB IActMLCCG4Q_get_ActControl_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActMLCCG4Q_put_ActControl_Proxy( 
    IActMLCCG4Q __RPC_FAR * This,
    /* [in] */ VARIANT newVal);


void __RPC_STUB IActMLCCG4Q_put_ActControl_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActMLCCG4Q_get_ActTimeOut_Proxy( 
    IActMLCCG4Q __RPC_FAR * This,
    /* [retval][out] */ VARIANT __RPC_FAR *pVal);


void __RPC_STUB IActMLCCG4Q_get_ActTimeOut_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActMLCCG4Q_put_ActTimeOut_Proxy( 
    IActMLCCG4Q __RPC_FAR * This,
    /* [in] */ VARIANT newVal);


void __RPC_STUB IActMLCCG4Q_put_ActTimeOut_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActMLCCG4Q_get_ActThroughNetworkType_Proxy( 
    IActMLCCG4Q __RPC_FAR * This,
    /* [retval][out] */ VARIANT __RPC_FAR *pVal);


void __RPC_STUB IActMLCCG4Q_get_ActThroughNetworkType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActMLCCG4Q_put_ActThroughNetworkType_Proxy( 
    IActMLCCG4Q __RPC_FAR * This,
    /* [in] */ VARIANT newVal);


void __RPC_STUB IActMLCCG4Q_put_ActThroughNetworkType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IActMLCCG4Q_INTERFACE_DEFINED__ */


#ifndef __IActMLCCG4Q2_INTERFACE_DEFINED__
#define __IActMLCCG4Q2_INTERFACE_DEFINED__

/* interface IActMLCCG4Q2 */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IActMLCCG4Q2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("87166044-710B-11d5-9318-009099244EFD")
    IActMLCCG4Q2 : public IActMLCCG4Q
    {
    public:
    };
    
#else 	/* C style interface */

    typedef struct IActMLCCG4Q2Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IActMLCCG4Q2 __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IActMLCCG4Q2 __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IActMLCCG4Q2 __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IActMLCCG4Q2 __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IActMLCCG4Q2 __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IActMLCCG4Q2 __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IActMLCCG4Q2 __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Open )( 
            IActMLCCG4Q2 __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Close )( 
            IActMLCCG4Q2 __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetDevice )( 
            IActMLCCG4Q2 __RPC_FAR * This,
            /* [in] */ VARIANT varDevice,
            /* [out] */ VARIANT __RPC_FAR *lpvarData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetDevice )( 
            IActMLCCG4Q2 __RPC_FAR * This,
            /* [in] */ VARIANT varDevice,
            /* [in] */ VARIANT varData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceBlock )( 
            IActMLCCG4Q2 __RPC_FAR * This,
            /* [in] */ VARIANT varDevice,
            /* [in] */ VARIANT varSize,
            /* [out] */ VARIANT __RPC_FAR *lpvarData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceBlock )( 
            IActMLCCG4Q2 __RPC_FAR * This,
            /* [in] */ VARIANT varDevice,
            /* [in] */ VARIANT varSize,
            /* [in] */ VARIANT varData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceRandom )( 
            IActMLCCG4Q2 __RPC_FAR * This,
            /* [in] */ VARIANT varDeviceList,
            /* [in] */ VARIANT varSize,
            /* [out] */ VARIANT __RPC_FAR *lpvarData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceRandom )( 
            IActMLCCG4Q2 __RPC_FAR * This,
            /* [in] */ VARIANT varDeviceList,
            /* [in] */ VARIANT varSize,
            /* [in] */ VARIANT varData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadBuffer )( 
            IActMLCCG4Q2 __RPC_FAR * This,
            /* [in] */ VARIANT varStartIO,
            /* [in] */ VARIANT varAddress,
            /* [in] */ VARIANT varReadSize,
            /* [out] */ VARIANT __RPC_FAR *lpvarData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteBuffer )( 
            IActMLCCG4Q2 __RPC_FAR * This,
            /* [in] */ VARIANT varStartIO,
            /* [in] */ VARIANT varAddress,
            /* [in] */ VARIANT varWriteSize,
            /* [in] */ VARIANT varData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetClockData )( 
            IActMLCCG4Q2 __RPC_FAR * This,
            /* [out] */ VARIANT __RPC_FAR *lpvarYear,
            /* [out] */ VARIANT __RPC_FAR *lpvarMonth,
            /* [out] */ VARIANT __RPC_FAR *lpvarDay,
            /* [out] */ VARIANT __RPC_FAR *lpvarDayOfWeek,
            /* [out] */ VARIANT __RPC_FAR *lpvarHour,
            /* [out] */ VARIANT __RPC_FAR *lpvarMinute,
            /* [out] */ VARIANT __RPC_FAR *lpvarSecond,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetClockData )( 
            IActMLCCG4Q2 __RPC_FAR * This,
            /* [in] */ VARIANT varYear,
            /* [in] */ VARIANT varMonth,
            /* [in] */ VARIANT varDay,
            /* [in] */ VARIANT varDayOfWeek,
            /* [in] */ VARIANT varHour,
            /* [in] */ VARIANT varMinute,
            /* [in] */ VARIANT varSecond,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetCpuType )( 
            IActMLCCG4Q2 __RPC_FAR * This,
            /* [out] */ VARIANT __RPC_FAR *lpvarCpuName,
            /* [out] */ VARIANT __RPC_FAR *lpvarCpuType,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetCpuStatus )( 
            IActMLCCG4Q2 __RPC_FAR * This,
            /* [in] */ VARIANT varOperation,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *EntryDeviceStatus )( 
            IActMLCCG4Q2 __RPC_FAR * This,
            /* [in] */ VARIANT varDeviceList,
            /* [in] */ VARIANT varSize,
            /* [in] */ VARIANT varMonitorCycle,
            /* [in] */ VARIANT varData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *FreeDeviceStatus )( 
            IActMLCCG4Q2 __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceBlock2 )( 
            IActMLCCG4Q2 __RPC_FAR * This,
            /* [in] */ VARIANT varDevice,
            /* [in] */ VARIANT varSize,
            /* [out] */ VARIANT __RPC_FAR *lpvarData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceBlock2 )( 
            IActMLCCG4Q2 __RPC_FAR * This,
            /* [in] */ VARIANT varDevice,
            /* [in] */ VARIANT varSize,
            /* [in] */ VARIANT varData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceRandom2 )( 
            IActMLCCG4Q2 __RPC_FAR * This,
            /* [in] */ VARIANT varDeviceList,
            /* [in] */ VARIANT varSize,
            /* [out] */ VARIANT __RPC_FAR *lpvarData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceRandom2 )( 
            IActMLCCG4Q2 __RPC_FAR * This,
            /* [in] */ VARIANT varDeviceList,
            /* [in] */ VARIANT varSize,
            /* [in] */ VARIANT varData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetDevice2 )( 
            IActMLCCG4Q2 __RPC_FAR * This,
            /* [in] */ VARIANT varDevice,
            /* [out] */ VARIANT __RPC_FAR *lpvarData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetDevice2 )( 
            IActMLCCG4Q2 __RPC_FAR * This,
            /* [in] */ VARIANT varDevice,
            /* [in] */ VARIANT varData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActNetworkNumber )( 
            IActMLCCG4Q2 __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActNetworkNumber )( 
            IActMLCCG4Q2 __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActStationNumber )( 
            IActMLCCG4Q2 __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActStationNumber )( 
            IActMLCCG4Q2 __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActUnitNumber )( 
            IActMLCCG4Q2 __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActUnitNumber )( 
            IActMLCCG4Q2 __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActConnectUnitNumber )( 
            IActMLCCG4Q2 __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActConnectUnitNumber )( 
            IActMLCCG4Q2 __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActIONumber )( 
            IActMLCCG4Q2 __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActIONumber )( 
            IActMLCCG4Q2 __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActCpuType )( 
            IActMLCCG4Q2 __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActCpuType )( 
            IActMLCCG4Q2 __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActPortNumber )( 
            IActMLCCG4Q2 __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActPortNumber )( 
            IActMLCCG4Q2 __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActBaudRate )( 
            IActMLCCG4Q2 __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActBaudRate )( 
            IActMLCCG4Q2 __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActControl )( 
            IActMLCCG4Q2 __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActControl )( 
            IActMLCCG4Q2 __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActTimeOut )( 
            IActMLCCG4Q2 __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActTimeOut )( 
            IActMLCCG4Q2 __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActThroughNetworkType )( 
            IActMLCCG4Q2 __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActThroughNetworkType )( 
            IActMLCCG4Q2 __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        END_INTERFACE
    } IActMLCCG4Q2Vtbl;

    interface IActMLCCG4Q2
    {
        CONST_VTBL struct IActMLCCG4Q2Vtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IActMLCCG4Q2_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IActMLCCG4Q2_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IActMLCCG4Q2_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IActMLCCG4Q2_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IActMLCCG4Q2_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IActMLCCG4Q2_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IActMLCCG4Q2_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IActMLCCG4Q2_Open(This,lpvarReturnCode)	\
    (This)->lpVtbl -> Open(This,lpvarReturnCode)

#define IActMLCCG4Q2_Close(This,lpvarReturnCode)	\
    (This)->lpVtbl -> Close(This,lpvarReturnCode)

#define IActMLCCG4Q2_GetDevice(This,varDevice,lpvarData,lpvarReturnCode)	\
    (This)->lpVtbl -> GetDevice(This,varDevice,lpvarData,lpvarReturnCode)

#define IActMLCCG4Q2_SetDevice(This,varDevice,varData,lpvarReturnCode)	\
    (This)->lpVtbl -> SetDevice(This,varDevice,varData,lpvarReturnCode)

#define IActMLCCG4Q2_ReadDeviceBlock(This,varDevice,varSize,lpvarData,lpvarReturnCode)	\
    (This)->lpVtbl -> ReadDeviceBlock(This,varDevice,varSize,lpvarData,lpvarReturnCode)

#define IActMLCCG4Q2_WriteDeviceBlock(This,varDevice,varSize,varData,lpvarReturnCode)	\
    (This)->lpVtbl -> WriteDeviceBlock(This,varDevice,varSize,varData,lpvarReturnCode)

#define IActMLCCG4Q2_ReadDeviceRandom(This,varDeviceList,varSize,lpvarData,lpvarReturnCode)	\
    (This)->lpVtbl -> ReadDeviceRandom(This,varDeviceList,varSize,lpvarData,lpvarReturnCode)

#define IActMLCCG4Q2_WriteDeviceRandom(This,varDeviceList,varSize,varData,lpvarReturnCode)	\
    (This)->lpVtbl -> WriteDeviceRandom(This,varDeviceList,varSize,varData,lpvarReturnCode)

#define IActMLCCG4Q2_ReadBuffer(This,varStartIO,varAddress,varReadSize,lpvarData,lpvarReturnCode)	\
    (This)->lpVtbl -> ReadBuffer(This,varStartIO,varAddress,varReadSize,lpvarData,lpvarReturnCode)

#define IActMLCCG4Q2_WriteBuffer(This,varStartIO,varAddress,varWriteSize,varData,lpvarReturnCode)	\
    (This)->lpVtbl -> WriteBuffer(This,varStartIO,varAddress,varWriteSize,varData,lpvarReturnCode)

#define IActMLCCG4Q2_GetClockData(This,lpvarYear,lpvarMonth,lpvarDay,lpvarDayOfWeek,lpvarHour,lpvarMinute,lpvarSecond,lpvarReturnCode)	\
    (This)->lpVtbl -> GetClockData(This,lpvarYear,lpvarMonth,lpvarDay,lpvarDayOfWeek,lpvarHour,lpvarMinute,lpvarSecond,lpvarReturnCode)

#define IActMLCCG4Q2_SetClockData(This,varYear,varMonth,varDay,varDayOfWeek,varHour,varMinute,varSecond,lpvarReturnCode)	\
    (This)->lpVtbl -> SetClockData(This,varYear,varMonth,varDay,varDayOfWeek,varHour,varMinute,varSecond,lpvarReturnCode)

#define IActMLCCG4Q2_GetCpuType(This,lpvarCpuName,lpvarCpuType,lpvarReturnCode)	\
    (This)->lpVtbl -> GetCpuType(This,lpvarCpuName,lpvarCpuType,lpvarReturnCode)

#define IActMLCCG4Q2_SetCpuStatus(This,varOperation,lpvarReturnCode)	\
    (This)->lpVtbl -> SetCpuStatus(This,varOperation,lpvarReturnCode)

#define IActMLCCG4Q2_EntryDeviceStatus(This,varDeviceList,varSize,varMonitorCycle,varData,lpvarReturnCode)	\
    (This)->lpVtbl -> EntryDeviceStatus(This,varDeviceList,varSize,varMonitorCycle,varData,lpvarReturnCode)

#define IActMLCCG4Q2_FreeDeviceStatus(This,lpvarReturnCode)	\
    (This)->lpVtbl -> FreeDeviceStatus(This,lpvarReturnCode)

#define IActMLCCG4Q2_ReadDeviceBlock2(This,varDevice,varSize,lpvarData,lpvarReturnCode)	\
    (This)->lpVtbl -> ReadDeviceBlock2(This,varDevice,varSize,lpvarData,lpvarReturnCode)

#define IActMLCCG4Q2_WriteDeviceBlock2(This,varDevice,varSize,varData,lpvarReturnCode)	\
    (This)->lpVtbl -> WriteDeviceBlock2(This,varDevice,varSize,varData,lpvarReturnCode)

#define IActMLCCG4Q2_ReadDeviceRandom2(This,varDeviceList,varSize,lpvarData,lpvarReturnCode)	\
    (This)->lpVtbl -> ReadDeviceRandom2(This,varDeviceList,varSize,lpvarData,lpvarReturnCode)

#define IActMLCCG4Q2_WriteDeviceRandom2(This,varDeviceList,varSize,varData,lpvarReturnCode)	\
    (This)->lpVtbl -> WriteDeviceRandom2(This,varDeviceList,varSize,varData,lpvarReturnCode)

#define IActMLCCG4Q2_GetDevice2(This,varDevice,lpvarData,lpvarReturnCode)	\
    (This)->lpVtbl -> GetDevice2(This,varDevice,lpvarData,lpvarReturnCode)

#define IActMLCCG4Q2_SetDevice2(This,varDevice,varData,lpvarReturnCode)	\
    (This)->lpVtbl -> SetDevice2(This,varDevice,varData,lpvarReturnCode)

#define IActMLCCG4Q2_get_ActNetworkNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActNetworkNumber(This,pVal)

#define IActMLCCG4Q2_put_ActNetworkNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActNetworkNumber(This,newVal)

#define IActMLCCG4Q2_get_ActStationNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActStationNumber(This,pVal)

#define IActMLCCG4Q2_put_ActStationNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActStationNumber(This,newVal)

#define IActMLCCG4Q2_get_ActUnitNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActUnitNumber(This,pVal)

#define IActMLCCG4Q2_put_ActUnitNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActUnitNumber(This,newVal)

#define IActMLCCG4Q2_get_ActConnectUnitNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActConnectUnitNumber(This,pVal)

#define IActMLCCG4Q2_put_ActConnectUnitNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActConnectUnitNumber(This,newVal)

#define IActMLCCG4Q2_get_ActIONumber(This,pVal)	\
    (This)->lpVtbl -> get_ActIONumber(This,pVal)

#define IActMLCCG4Q2_put_ActIONumber(This,newVal)	\
    (This)->lpVtbl -> put_ActIONumber(This,newVal)

#define IActMLCCG4Q2_get_ActCpuType(This,pVal)	\
    (This)->lpVtbl -> get_ActCpuType(This,pVal)

#define IActMLCCG4Q2_put_ActCpuType(This,newVal)	\
    (This)->lpVtbl -> put_ActCpuType(This,newVal)

#define IActMLCCG4Q2_get_ActPortNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActPortNumber(This,pVal)

#define IActMLCCG4Q2_put_ActPortNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActPortNumber(This,newVal)

#define IActMLCCG4Q2_get_ActBaudRate(This,pVal)	\
    (This)->lpVtbl -> get_ActBaudRate(This,pVal)

#define IActMLCCG4Q2_put_ActBaudRate(This,newVal)	\
    (This)->lpVtbl -> put_ActBaudRate(This,newVal)

#define IActMLCCG4Q2_get_ActControl(This,pVal)	\
    (This)->lpVtbl -> get_ActControl(This,pVal)

#define IActMLCCG4Q2_put_ActControl(This,newVal)	\
    (This)->lpVtbl -> put_ActControl(This,newVal)

#define IActMLCCG4Q2_get_ActTimeOut(This,pVal)	\
    (This)->lpVtbl -> get_ActTimeOut(This,pVal)

#define IActMLCCG4Q2_put_ActTimeOut(This,newVal)	\
    (This)->lpVtbl -> put_ActTimeOut(This,newVal)

#define IActMLCCG4Q2_get_ActThroughNetworkType(This,pVal)	\
    (This)->lpVtbl -> get_ActThroughNetworkType(This,pVal)

#define IActMLCCG4Q2_put_ActThroughNetworkType(This,newVal)	\
    (This)->lpVtbl -> put_ActThroughNetworkType(This,newVal)


#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IActMLCCG4Q2_INTERFACE_DEFINED__ */


#ifndef __IActMLCCG4Q3_INTERFACE_DEFINED__
#define __IActMLCCG4Q3_INTERFACE_DEFINED__

/* interface IActMLCCG4Q3 */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IActMLCCG4Q3;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("87166045-710B-11d5-9318-009099244EFD")
    IActMLCCG4Q3 : public IActMLCCG4Q2
    {
    public:
    };
    
#else 	/* C style interface */

    typedef struct IActMLCCG4Q3Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IActMLCCG4Q3 __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IActMLCCG4Q3 __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IActMLCCG4Q3 __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IActMLCCG4Q3 __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IActMLCCG4Q3 __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IActMLCCG4Q3 __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IActMLCCG4Q3 __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Open )( 
            IActMLCCG4Q3 __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Close )( 
            IActMLCCG4Q3 __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetDevice )( 
            IActMLCCG4Q3 __RPC_FAR * This,
            /* [in] */ VARIANT varDevice,
            /* [out] */ VARIANT __RPC_FAR *lpvarData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetDevice )( 
            IActMLCCG4Q3 __RPC_FAR * This,
            /* [in] */ VARIANT varDevice,
            /* [in] */ VARIANT varData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceBlock )( 
            IActMLCCG4Q3 __RPC_FAR * This,
            /* [in] */ VARIANT varDevice,
            /* [in] */ VARIANT varSize,
            /* [out] */ VARIANT __RPC_FAR *lpvarData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceBlock )( 
            IActMLCCG4Q3 __RPC_FAR * This,
            /* [in] */ VARIANT varDevice,
            /* [in] */ VARIANT varSize,
            /* [in] */ VARIANT varData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceRandom )( 
            IActMLCCG4Q3 __RPC_FAR * This,
            /* [in] */ VARIANT varDeviceList,
            /* [in] */ VARIANT varSize,
            /* [out] */ VARIANT __RPC_FAR *lpvarData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceRandom )( 
            IActMLCCG4Q3 __RPC_FAR * This,
            /* [in] */ VARIANT varDeviceList,
            /* [in] */ VARIANT varSize,
            /* [in] */ VARIANT varData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadBuffer )( 
            IActMLCCG4Q3 __RPC_FAR * This,
            /* [in] */ VARIANT varStartIO,
            /* [in] */ VARIANT varAddress,
            /* [in] */ VARIANT varReadSize,
            /* [out] */ VARIANT __RPC_FAR *lpvarData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteBuffer )( 
            IActMLCCG4Q3 __RPC_FAR * This,
            /* [in] */ VARIANT varStartIO,
            /* [in] */ VARIANT varAddress,
            /* [in] */ VARIANT varWriteSize,
            /* [in] */ VARIANT varData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetClockData )( 
            IActMLCCG4Q3 __RPC_FAR * This,
            /* [out] */ VARIANT __RPC_FAR *lpvarYear,
            /* [out] */ VARIANT __RPC_FAR *lpvarMonth,
            /* [out] */ VARIANT __RPC_FAR *lpvarDay,
            /* [out] */ VARIANT __RPC_FAR *lpvarDayOfWeek,
            /* [out] */ VARIANT __RPC_FAR *lpvarHour,
            /* [out] */ VARIANT __RPC_FAR *lpvarMinute,
            /* [out] */ VARIANT __RPC_FAR *lpvarSecond,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetClockData )( 
            IActMLCCG4Q3 __RPC_FAR * This,
            /* [in] */ VARIANT varYear,
            /* [in] */ VARIANT varMonth,
            /* [in] */ VARIANT varDay,
            /* [in] */ VARIANT varDayOfWeek,
            /* [in] */ VARIANT varHour,
            /* [in] */ VARIANT varMinute,
            /* [in] */ VARIANT varSecond,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetCpuType )( 
            IActMLCCG4Q3 __RPC_FAR * This,
            /* [out] */ VARIANT __RPC_FAR *lpvarCpuName,
            /* [out] */ VARIANT __RPC_FAR *lpvarCpuType,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetCpuStatus )( 
            IActMLCCG4Q3 __RPC_FAR * This,
            /* [in] */ VARIANT varOperation,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *EntryDeviceStatus )( 
            IActMLCCG4Q3 __RPC_FAR * This,
            /* [in] */ VARIANT varDeviceList,
            /* [in] */ VARIANT varSize,
            /* [in] */ VARIANT varMonitorCycle,
            /* [in] */ VARIANT varData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *FreeDeviceStatus )( 
            IActMLCCG4Q3 __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceBlock2 )( 
            IActMLCCG4Q3 __RPC_FAR * This,
            /* [in] */ VARIANT varDevice,
            /* [in] */ VARIANT varSize,
            /* [out] */ VARIANT __RPC_FAR *lpvarData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceBlock2 )( 
            IActMLCCG4Q3 __RPC_FAR * This,
            /* [in] */ VARIANT varDevice,
            /* [in] */ VARIANT varSize,
            /* [in] */ VARIANT varData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceRandom2 )( 
            IActMLCCG4Q3 __RPC_FAR * This,
            /* [in] */ VARIANT varDeviceList,
            /* [in] */ VARIANT varSize,
            /* [out] */ VARIANT __RPC_FAR *lpvarData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceRandom2 )( 
            IActMLCCG4Q3 __RPC_FAR * This,
            /* [in] */ VARIANT varDeviceList,
            /* [in] */ VARIANT varSize,
            /* [in] */ VARIANT varData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetDevice2 )( 
            IActMLCCG4Q3 __RPC_FAR * This,
            /* [in] */ VARIANT varDevice,
            /* [out] */ VARIANT __RPC_FAR *lpvarData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetDevice2 )( 
            IActMLCCG4Q3 __RPC_FAR * This,
            /* [in] */ VARIANT varDevice,
            /* [in] */ VARIANT varData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActNetworkNumber )( 
            IActMLCCG4Q3 __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActNetworkNumber )( 
            IActMLCCG4Q3 __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActStationNumber )( 
            IActMLCCG4Q3 __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActStationNumber )( 
            IActMLCCG4Q3 __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActUnitNumber )( 
            IActMLCCG4Q3 __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActUnitNumber )( 
            IActMLCCG4Q3 __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActConnectUnitNumber )( 
            IActMLCCG4Q3 __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActConnectUnitNumber )( 
            IActMLCCG4Q3 __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActIONumber )( 
            IActMLCCG4Q3 __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActIONumber )( 
            IActMLCCG4Q3 __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActCpuType )( 
            IActMLCCG4Q3 __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActCpuType )( 
            IActMLCCG4Q3 __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActPortNumber )( 
            IActMLCCG4Q3 __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActPortNumber )( 
            IActMLCCG4Q3 __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActBaudRate )( 
            IActMLCCG4Q3 __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActBaudRate )( 
            IActMLCCG4Q3 __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActControl )( 
            IActMLCCG4Q3 __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActControl )( 
            IActMLCCG4Q3 __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActTimeOut )( 
            IActMLCCG4Q3 __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActTimeOut )( 
            IActMLCCG4Q3 __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActThroughNetworkType )( 
            IActMLCCG4Q3 __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActThroughNetworkType )( 
            IActMLCCG4Q3 __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        END_INTERFACE
    } IActMLCCG4Q3Vtbl;

    interface IActMLCCG4Q3
    {
        CONST_VTBL struct IActMLCCG4Q3Vtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IActMLCCG4Q3_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IActMLCCG4Q3_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IActMLCCG4Q3_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IActMLCCG4Q3_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IActMLCCG4Q3_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IActMLCCG4Q3_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IActMLCCG4Q3_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IActMLCCG4Q3_Open(This,lpvarReturnCode)	\
    (This)->lpVtbl -> Open(This,lpvarReturnCode)

#define IActMLCCG4Q3_Close(This,lpvarReturnCode)	\
    (This)->lpVtbl -> Close(This,lpvarReturnCode)

#define IActMLCCG4Q3_GetDevice(This,varDevice,lpvarData,lpvarReturnCode)	\
    (This)->lpVtbl -> GetDevice(This,varDevice,lpvarData,lpvarReturnCode)

#define IActMLCCG4Q3_SetDevice(This,varDevice,varData,lpvarReturnCode)	\
    (This)->lpVtbl -> SetDevice(This,varDevice,varData,lpvarReturnCode)

#define IActMLCCG4Q3_ReadDeviceBlock(This,varDevice,varSize,lpvarData,lpvarReturnCode)	\
    (This)->lpVtbl -> ReadDeviceBlock(This,varDevice,varSize,lpvarData,lpvarReturnCode)

#define IActMLCCG4Q3_WriteDeviceBlock(This,varDevice,varSize,varData,lpvarReturnCode)	\
    (This)->lpVtbl -> WriteDeviceBlock(This,varDevice,varSize,varData,lpvarReturnCode)

#define IActMLCCG4Q3_ReadDeviceRandom(This,varDeviceList,varSize,lpvarData,lpvarReturnCode)	\
    (This)->lpVtbl -> ReadDeviceRandom(This,varDeviceList,varSize,lpvarData,lpvarReturnCode)

#define IActMLCCG4Q3_WriteDeviceRandom(This,varDeviceList,varSize,varData,lpvarReturnCode)	\
    (This)->lpVtbl -> WriteDeviceRandom(This,varDeviceList,varSize,varData,lpvarReturnCode)

#define IActMLCCG4Q3_ReadBuffer(This,varStartIO,varAddress,varReadSize,lpvarData,lpvarReturnCode)	\
    (This)->lpVtbl -> ReadBuffer(This,varStartIO,varAddress,varReadSize,lpvarData,lpvarReturnCode)

#define IActMLCCG4Q3_WriteBuffer(This,varStartIO,varAddress,varWriteSize,varData,lpvarReturnCode)	\
    (This)->lpVtbl -> WriteBuffer(This,varStartIO,varAddress,varWriteSize,varData,lpvarReturnCode)

#define IActMLCCG4Q3_GetClockData(This,lpvarYear,lpvarMonth,lpvarDay,lpvarDayOfWeek,lpvarHour,lpvarMinute,lpvarSecond,lpvarReturnCode)	\
    (This)->lpVtbl -> GetClockData(This,lpvarYear,lpvarMonth,lpvarDay,lpvarDayOfWeek,lpvarHour,lpvarMinute,lpvarSecond,lpvarReturnCode)

#define IActMLCCG4Q3_SetClockData(This,varYear,varMonth,varDay,varDayOfWeek,varHour,varMinute,varSecond,lpvarReturnCode)	\
    (This)->lpVtbl -> SetClockData(This,varYear,varMonth,varDay,varDayOfWeek,varHour,varMinute,varSecond,lpvarReturnCode)

#define IActMLCCG4Q3_GetCpuType(This,lpvarCpuName,lpvarCpuType,lpvarReturnCode)	\
    (This)->lpVtbl -> GetCpuType(This,lpvarCpuName,lpvarCpuType,lpvarReturnCode)

#define IActMLCCG4Q3_SetCpuStatus(This,varOperation,lpvarReturnCode)	\
    (This)->lpVtbl -> SetCpuStatus(This,varOperation,lpvarReturnCode)

#define IActMLCCG4Q3_EntryDeviceStatus(This,varDeviceList,varSize,varMonitorCycle,varData,lpvarReturnCode)	\
    (This)->lpVtbl -> EntryDeviceStatus(This,varDeviceList,varSize,varMonitorCycle,varData,lpvarReturnCode)

#define IActMLCCG4Q3_FreeDeviceStatus(This,lpvarReturnCode)	\
    (This)->lpVtbl -> FreeDeviceStatus(This,lpvarReturnCode)

#define IActMLCCG4Q3_ReadDeviceBlock2(This,varDevice,varSize,lpvarData,lpvarReturnCode)	\
    (This)->lpVtbl -> ReadDeviceBlock2(This,varDevice,varSize,lpvarData,lpvarReturnCode)

#define IActMLCCG4Q3_WriteDeviceBlock2(This,varDevice,varSize,varData,lpvarReturnCode)	\
    (This)->lpVtbl -> WriteDeviceBlock2(This,varDevice,varSize,varData,lpvarReturnCode)

#define IActMLCCG4Q3_ReadDeviceRandom2(This,varDeviceList,varSize,lpvarData,lpvarReturnCode)	\
    (This)->lpVtbl -> ReadDeviceRandom2(This,varDeviceList,varSize,lpvarData,lpvarReturnCode)

#define IActMLCCG4Q3_WriteDeviceRandom2(This,varDeviceList,varSize,varData,lpvarReturnCode)	\
    (This)->lpVtbl -> WriteDeviceRandom2(This,varDeviceList,varSize,varData,lpvarReturnCode)

#define IActMLCCG4Q3_GetDevice2(This,varDevice,lpvarData,lpvarReturnCode)	\
    (This)->lpVtbl -> GetDevice2(This,varDevice,lpvarData,lpvarReturnCode)

#define IActMLCCG4Q3_SetDevice2(This,varDevice,varData,lpvarReturnCode)	\
    (This)->lpVtbl -> SetDevice2(This,varDevice,varData,lpvarReturnCode)

#define IActMLCCG4Q3_get_ActNetworkNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActNetworkNumber(This,pVal)

#define IActMLCCG4Q3_put_ActNetworkNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActNetworkNumber(This,newVal)

#define IActMLCCG4Q3_get_ActStationNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActStationNumber(This,pVal)

#define IActMLCCG4Q3_put_ActStationNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActStationNumber(This,newVal)

#define IActMLCCG4Q3_get_ActUnitNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActUnitNumber(This,pVal)

#define IActMLCCG4Q3_put_ActUnitNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActUnitNumber(This,newVal)

#define IActMLCCG4Q3_get_ActConnectUnitNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActConnectUnitNumber(This,pVal)

#define IActMLCCG4Q3_put_ActConnectUnitNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActConnectUnitNumber(This,newVal)

#define IActMLCCG4Q3_get_ActIONumber(This,pVal)	\
    (This)->lpVtbl -> get_ActIONumber(This,pVal)

#define IActMLCCG4Q3_put_ActIONumber(This,newVal)	\
    (This)->lpVtbl -> put_ActIONumber(This,newVal)

#define IActMLCCG4Q3_get_ActCpuType(This,pVal)	\
    (This)->lpVtbl -> get_ActCpuType(This,pVal)

#define IActMLCCG4Q3_put_ActCpuType(This,newVal)	\
    (This)->lpVtbl -> put_ActCpuType(This,newVal)

#define IActMLCCG4Q3_get_ActPortNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActPortNumber(This,pVal)

#define IActMLCCG4Q3_put_ActPortNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActPortNumber(This,newVal)

#define IActMLCCG4Q3_get_ActBaudRate(This,pVal)	\
    (This)->lpVtbl -> get_ActBaudRate(This,pVal)

#define IActMLCCG4Q3_put_ActBaudRate(This,newVal)	\
    (This)->lpVtbl -> put_ActBaudRate(This,newVal)

#define IActMLCCG4Q3_get_ActControl(This,pVal)	\
    (This)->lpVtbl -> get_ActControl(This,pVal)

#define IActMLCCG4Q3_put_ActControl(This,newVal)	\
    (This)->lpVtbl -> put_ActControl(This,newVal)

#define IActMLCCG4Q3_get_ActTimeOut(This,pVal)	\
    (This)->lpVtbl -> get_ActTimeOut(This,pVal)

#define IActMLCCG4Q3_put_ActTimeOut(This,newVal)	\
    (This)->lpVtbl -> put_ActTimeOut(This,newVal)

#define IActMLCCG4Q3_get_ActThroughNetworkType(This,pVal)	\
    (This)->lpVtbl -> get_ActThroughNetworkType(This,pVal)

#define IActMLCCG4Q3_put_ActThroughNetworkType(This,newVal)	\
    (This)->lpVtbl -> put_ActThroughNetworkType(This,newVal)



#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IActMLCCG4Q3_INTERFACE_DEFINED__ */



#ifndef __ACTCCG4Lib_LIBRARY_DEFINED__
#define __ACTCCG4Lib_LIBRARY_DEFINED__

/* library ACTCCG4Lib */
/* [helpstring][version][uuid] */ 


EXTERN_C const IID LIBID_ACTCCG4Lib;

#ifndef ___IActCCG4QnAEvents_DISPINTERFACE_DEFINED__
#define ___IActCCG4QnAEvents_DISPINTERFACE_DEFINED__

/* dispinterface _IActCCG4QnAEvents */
/* [helpstring][uuid] */ 


EXTERN_C const IID DIID__IActCCG4QnAEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("8215E4F3-AE9D-11D3-83AE-00A024BDBF2B")
    _IActCCG4QnAEvents : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct _IActCCG4QnAEventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            _IActCCG4QnAEvents __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            _IActCCG4QnAEvents __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            _IActCCG4QnAEvents __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            _IActCCG4QnAEvents __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            _IActCCG4QnAEvents __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            _IActCCG4QnAEvents __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            _IActCCG4QnAEvents __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        END_INTERFACE
    } _IActCCG4QnAEventsVtbl;

    interface _IActCCG4QnAEvents
    {
        CONST_VTBL struct _IActCCG4QnAEventsVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _IActCCG4QnAEvents_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define _IActCCG4QnAEvents_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define _IActCCG4QnAEvents_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define _IActCCG4QnAEvents_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define _IActCCG4QnAEvents_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define _IActCCG4QnAEvents_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define _IActCCG4QnAEvents_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ___IActCCG4QnAEvents_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_ActCCG4QnA;

#ifdef __cplusplus

class DECLSPEC_UUID("8215E4F2-AE9D-11D3-83AE-00A024BDBF2B")
ActCCG4QnA;
#endif

#ifndef ___IActCCG4AEvents_DISPINTERFACE_DEFINED__
#define ___IActCCG4AEvents_DISPINTERFACE_DEFINED__

/* dispinterface _IActCCG4AEvents */
/* [helpstring][uuid] */ 


EXTERN_C const IID DIID__IActCCG4AEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("8215E4F6-AE9D-11D3-83AE-00A024BDBF2B")
    _IActCCG4AEvents : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct _IActCCG4AEventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            _IActCCG4AEvents __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            _IActCCG4AEvents __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            _IActCCG4AEvents __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            _IActCCG4AEvents __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            _IActCCG4AEvents __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            _IActCCG4AEvents __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            _IActCCG4AEvents __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        END_INTERFACE
    } _IActCCG4AEventsVtbl;

    interface _IActCCG4AEvents
    {
        CONST_VTBL struct _IActCCG4AEventsVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _IActCCG4AEvents_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define _IActCCG4AEvents_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define _IActCCG4AEvents_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define _IActCCG4AEvents_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define _IActCCG4AEvents_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define _IActCCG4AEvents_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define _IActCCG4AEvents_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ___IActCCG4AEvents_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_ActCCG4A;

#ifdef __cplusplus

class DECLSPEC_UUID("8215E4F5-AE9D-11D3-83AE-00A024BDBF2B")
ActCCG4A;
#endif

#ifndef ___IActMLCCG4AEvents_DISPINTERFACE_DEFINED__
#define ___IActMLCCG4AEvents_DISPINTERFACE_DEFINED__

/* dispinterface _IActMLCCG4AEvents */
/* [helpstring][uuid] */ 


EXTERN_C const IID DIID__IActMLCCG4AEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("29BD6544-A98F-11D4-910D-009099244EFD")
    _IActMLCCG4AEvents : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct _IActMLCCG4AEventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            _IActMLCCG4AEvents __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            _IActMLCCG4AEvents __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            _IActMLCCG4AEvents __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            _IActMLCCG4AEvents __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            _IActMLCCG4AEvents __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            _IActMLCCG4AEvents __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            _IActMLCCG4AEvents __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        END_INTERFACE
    } _IActMLCCG4AEventsVtbl;

    interface _IActMLCCG4AEvents
    {
        CONST_VTBL struct _IActMLCCG4AEventsVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _IActMLCCG4AEvents_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define _IActMLCCG4AEvents_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define _IActMLCCG4AEvents_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define _IActMLCCG4AEvents_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define _IActMLCCG4AEvents_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define _IActMLCCG4AEvents_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define _IActMLCCG4AEvents_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ___IActMLCCG4AEvents_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_ActMLCCG4A;

#ifdef __cplusplus

class DECLSPEC_UUID("29BD6543-A98F-11D4-910D-009099244EFD")
ActMLCCG4A;
#endif

#ifndef ___IActMLCCG4QnAEvents_DISPINTERFACE_DEFINED__
#define ___IActMLCCG4QnAEvents_DISPINTERFACE_DEFINED__

/* dispinterface _IActMLCCG4QnAEvents */
/* [helpstring][uuid] */ 


EXTERN_C const IID DIID__IActMLCCG4QnAEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("29BD654A-A98F-11D4-910D-009099244EFD")
    _IActMLCCG4QnAEvents : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct _IActMLCCG4QnAEventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            _IActMLCCG4QnAEvents __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            _IActMLCCG4QnAEvents __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            _IActMLCCG4QnAEvents __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            _IActMLCCG4QnAEvents __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            _IActMLCCG4QnAEvents __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            _IActMLCCG4QnAEvents __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            _IActMLCCG4QnAEvents __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        END_INTERFACE
    } _IActMLCCG4QnAEventsVtbl;

    interface _IActMLCCG4QnAEvents
    {
        CONST_VTBL struct _IActMLCCG4QnAEventsVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _IActMLCCG4QnAEvents_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define _IActMLCCG4QnAEvents_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define _IActMLCCG4QnAEvents_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define _IActMLCCG4QnAEvents_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define _IActMLCCG4QnAEvents_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define _IActMLCCG4QnAEvents_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define _IActMLCCG4QnAEvents_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ___IActMLCCG4QnAEvents_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_ActMLCCG4QnA;

#ifdef __cplusplus

class DECLSPEC_UUID("29BD6549-A98F-11D4-910D-009099244EFD")
ActMLCCG4QnA;
#endif

#ifndef ___IActCCG4QEvents_DISPINTERFACE_DEFINED__
#define ___IActCCG4QEvents_DISPINTERFACE_DEFINED__

/* dispinterface _IActCCG4QEvents */
/* [helpstring][uuid] */ 


EXTERN_C const IID DIID__IActCCG4QEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("3555ACF5-70DB-11D5-9318-009099244EFD")
    _IActCCG4QEvents : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct _IActCCG4QEventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            _IActCCG4QEvents __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            _IActCCG4QEvents __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            _IActCCG4QEvents __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            _IActCCG4QEvents __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            _IActCCG4QEvents __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            _IActCCG4QEvents __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            _IActCCG4QEvents __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        END_INTERFACE
    } _IActCCG4QEventsVtbl;

    interface _IActCCG4QEvents
    {
        CONST_VTBL struct _IActCCG4QEventsVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _IActCCG4QEvents_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define _IActCCG4QEvents_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define _IActCCG4QEvents_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define _IActCCG4QEvents_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define _IActCCG4QEvents_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define _IActCCG4QEvents_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define _IActCCG4QEvents_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ___IActCCG4QEvents_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_ActCCG4Q;

#ifdef __cplusplus

class DECLSPEC_UUID("3555ACF4-70DB-11D5-9318-009099244EFD")
ActCCG4Q;
#endif

#ifndef ___IActMLCCG4QEvents_DISPINTERFACE_DEFINED__
#define ___IActMLCCG4QEvents_DISPINTERFACE_DEFINED__

/* dispinterface _IActMLCCG4QEvents */
/* [helpstring][uuid] */ 


EXTERN_C const IID DIID__IActMLCCG4QEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("EA97CD63-70EB-11D5-9318-009099244EFD")
    _IActMLCCG4QEvents : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct _IActMLCCG4QEventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            _IActMLCCG4QEvents __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            _IActMLCCG4QEvents __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            _IActMLCCG4QEvents __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            _IActMLCCG4QEvents __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            _IActMLCCG4QEvents __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            _IActMLCCG4QEvents __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            _IActMLCCG4QEvents __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        END_INTERFACE
    } _IActMLCCG4QEventsVtbl;

    interface _IActMLCCG4QEvents
    {
        CONST_VTBL struct _IActMLCCG4QEventsVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _IActMLCCG4QEvents_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define _IActMLCCG4QEvents_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define _IActMLCCG4QEvents_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define _IActMLCCG4QEvents_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define _IActMLCCG4QEvents_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define _IActMLCCG4QEvents_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define _IActMLCCG4QEvents_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ___IActMLCCG4QEvents_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_ActMLCCG4Q;

#ifdef __cplusplus

class DECLSPEC_UUID("EA97CD62-70EB-11D5-9318-009099244EFD")
ActMLCCG4Q;
#endif
#endif /* __ACTCCG4Lib_LIBRARY_DEFINED__ */

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
