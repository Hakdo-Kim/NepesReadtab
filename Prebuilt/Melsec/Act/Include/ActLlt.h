/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 5.01.0164 */
/* at Fri Apr 12 12:31:51 2013
 */
/* Compiler settings for D:\GETMODULE\CommunicationSupport2\SW3D5\ACT\Control\ActLlt\ActLlt.idl:
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

#ifndef __ActLlt_h__
#define __ActLlt_h__

#ifdef __cplusplus
extern "C"{
#endif 

/* Forward Declarations */ 

#ifndef __IActLLT_FWD_DEFINED__
#define __IActLLT_FWD_DEFINED__
typedef interface IActLLT IActLLT;
#endif 	/* __IActLLT_FWD_DEFINED__ */


#ifndef __IActLLT2_FWD_DEFINED__
#define __IActLLT2_FWD_DEFINED__
typedef interface IActLLT2 IActLLT2;
#endif 	/* __IActLLT2_FWD_DEFINED__ */


#ifndef __IActLLT3_FWD_DEFINED__
#define __IActLLT3_FWD_DEFINED__
typedef interface IActLLT3 IActLLT3;
#endif 	/* __IActLLT3_FWD_DEFINED__ */


#ifndef __IActMLLLT_FWD_DEFINED__
#define __IActMLLLT_FWD_DEFINED__
typedef interface IActMLLLT IActMLLLT;
#endif 	/* __IActMLLLT_FWD_DEFINED__ */


#ifndef __IActMLLLT2_FWD_DEFINED__
#define __IActMLLLT2_FWD_DEFINED__
typedef interface IActMLLLT2 IActMLLLT2;
#endif 	/* __IActMLLLT2_FWD_DEFINED__ */


#ifndef __IActMLLLT3_FWD_DEFINED__
#define __IActMLLLT3_FWD_DEFINED__
typedef interface IActMLLLT3 IActMLLLT3;
#endif 	/* __IActMLLLT3_FWD_DEFINED__ */


#ifndef __IActSIM_FWD_DEFINED__
#define __IActSIM_FWD_DEFINED__
typedef interface IActSIM IActSIM;
#endif 	/* __IActSIM_FWD_DEFINED__ */


#ifndef __IActSIM2_FWD_DEFINED__
#define __IActSIM2_FWD_DEFINED__
typedef interface IActSIM2 IActSIM2;
#endif 	/* __IActSIM2_FWD_DEFINED__ */


#ifndef __IActSIM3_FWD_DEFINED__
#define __IActSIM3_FWD_DEFINED__
typedef interface IActSIM3 IActSIM3;
#endif 	/* __IActSIM3_FWD_DEFINED__ */


#ifndef __IActMLSIM_FWD_DEFINED__
#define __IActMLSIM_FWD_DEFINED__
typedef interface IActMLSIM IActMLSIM;
#endif 	/* __IActMLSIM_FWD_DEFINED__ */


#ifndef __IActMLSIM2_FWD_DEFINED__
#define __IActMLSIM2_FWD_DEFINED__
typedef interface IActMLSIM2 IActMLSIM2;
#endif 	/* __IActMLSIM2_FWD_DEFINED__ */


#ifndef __IActMLSIM3_FWD_DEFINED__
#define __IActMLSIM3_FWD_DEFINED__
typedef interface IActMLSIM3 IActMLSIM3;
#endif 	/* __IActMLSIM3_FWD_DEFINED__ */


#ifndef ___IActLLTEvents_FWD_DEFINED__
#define ___IActLLTEvents_FWD_DEFINED__
typedef interface _IActLLTEvents _IActLLTEvents;
#endif 	/* ___IActLLTEvents_FWD_DEFINED__ */


#ifndef __ActLLT_FWD_DEFINED__
#define __ActLLT_FWD_DEFINED__

#ifdef __cplusplus
typedef class ActLLT ActLLT;
#else
typedef struct ActLLT ActLLT;
#endif /* __cplusplus */

#endif 	/* __ActLLT_FWD_DEFINED__ */


#ifndef ___IActMLLLTEvents_FWD_DEFINED__
#define ___IActMLLLTEvents_FWD_DEFINED__
typedef interface _IActMLLLTEvents _IActMLLLTEvents;
#endif 	/* ___IActMLLLTEvents_FWD_DEFINED__ */


#ifndef __ActMLLLT_FWD_DEFINED__
#define __ActMLLLT_FWD_DEFINED__

#ifdef __cplusplus
typedef class ActMLLLT ActMLLLT;
#else
typedef struct ActMLLLT ActMLLLT;
#endif /* __cplusplus */

#endif 	/* __ActMLLLT_FWD_DEFINED__ */


#ifndef ___IActSIMEvents_FWD_DEFINED__
#define ___IActSIMEvents_FWD_DEFINED__
typedef interface _IActSIMEvents _IActSIMEvents;
#endif 	/* ___IActSIMEvents_FWD_DEFINED__ */


#ifndef __ActSIM_FWD_DEFINED__
#define __ActSIM_FWD_DEFINED__

#ifdef __cplusplus
typedef class ActSIM ActSIM;
#else
typedef struct ActSIM ActSIM;
#endif /* __cplusplus */

#endif 	/* __ActSIM_FWD_DEFINED__ */


#ifndef ___IActMLSIMEvents_FWD_DEFINED__
#define ___IActMLSIMEvents_FWD_DEFINED__
typedef interface _IActMLSIMEvents _IActMLSIMEvents;
#endif 	/* ___IActMLSIMEvents_FWD_DEFINED__ */


#ifndef __ActMLSIM_FWD_DEFINED__
#define __ActMLSIM_FWD_DEFINED__

#ifdef __cplusplus
typedef class ActMLSIM ActMLSIM;
#else
typedef struct ActMLSIM ActMLSIM;
#endif /* __cplusplus */

#endif 	/* __ActMLSIM_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

void __RPC_FAR * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void __RPC_FAR * ); 

#ifndef __IActLLT_INTERFACE_DEFINED__
#define __IActLLT_INTERFACE_DEFINED__

/* interface IActLLT */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IActLLT;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("235CFC01-AE9E-11D3-83AE-00A024BDBF2B")
    IActLLT : public IDispatch
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
            /* [in] */ BSTR szDevice,
            /* [in] */ LONG lData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActCpuType( 
            /* [retval][out] */ LONG __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActCpuType( 
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

    typedef struct IActLLTVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IActLLT __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IActLLT __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IActLLT __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IActLLT __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IActLLT __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IActLLT __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IActLLT __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Open )( 
            IActLLT __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Close )( 
            IActLLT __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetCpuType )( 
            IActLLT __RPC_FAR * This,
            /* [string][out] */ BSTR __RPC_FAR *szCpuName,
            /* [out] */ LONG __RPC_FAR *lplCpuCode,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetCpuStatus )( 
            IActLLT __RPC_FAR * This,
            /* [in] */ LONG lOperation,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceBlock )( 
            IActLLT __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lSize,
            /* [size_is][out] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceBlock )( 
            IActLLT __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lSize,
            /* [size_is][in] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceRandom )( 
            IActLLT __RPC_FAR * This,
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG lSize,
            /* [size_is][out] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceRandom )( 
            IActLLT __RPC_FAR * This,
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG lSize,
            /* [size_is][in] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadBuffer )( 
            IActLLT __RPC_FAR * This,
            /* [in] */ LONG lStartIO,
            /* [in] */ LONG lAddress,
            /* [in] */ LONG lSize,
            /* [size_is][out] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteBuffer )( 
            IActLLT __RPC_FAR * This,
            /* [in] */ LONG lStartIO,
            /* [in] */ LONG lAddress,
            /* [in] */ LONG lSize,
            /* [size_is][in] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetClockData )( 
            IActLLT __RPC_FAR * This,
            /* [out] */ SHORT __RPC_FAR *lpsYear,
            /* [out] */ SHORT __RPC_FAR *lpsMonth,
            /* [out] */ SHORT __RPC_FAR *lpsDay,
            /* [out] */ SHORT __RPC_FAR *lpsDayOfWeek,
            /* [out] */ SHORT __RPC_FAR *lpsHour,
            /* [out] */ SHORT __RPC_FAR *lpsMinute,
            /* [out] */ SHORT __RPC_FAR *lpsSecond,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetClockData )( 
            IActLLT __RPC_FAR * This,
            /* [in] */ SHORT sYear,
            /* [in] */ SHORT sMonth,
            /* [in] */ SHORT sDay,
            /* [in] */ SHORT sDayOfWeek,
            /* [in] */ SHORT sHour,
            /* [in] */ SHORT sMinute,
            /* [in] */ SHORT sSecond,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetDevice )( 
            IActLLT __RPC_FAR * This,
            /* [in] */ BSTR szDevice,
            /* [in] */ LONG lData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActCpuType )( 
            IActLLT __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActCpuType )( 
            IActLLT __RPC_FAR * This,
            /* [in] */ LONG newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActTimeOut )( 
            IActLLT __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActTimeOut )( 
            IActLLT __RPC_FAR * This,
            /* [in] */ LONG newVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetDevice )( 
            IActLLT __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [out] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CheckDeviceString )( 
            IActLLT __RPC_FAR * This,
            /* [in] */ BSTR szDevice,
            /* [in] */ LONG lCheckType,
            /* [in] */ LONG lSize,
            /* [out] */ LONG __RPC_FAR *lplDeviceType,
            /* [string][out] */ BSTR __RPC_FAR *lpszDeviceName,
            /* [out] */ LONG __RPC_FAR *lplDeviceNumber,
            /* [out] */ LONG __RPC_FAR *lplDeviceRadix,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        END_INTERFACE
    } IActLLTVtbl;

    interface IActLLT
    {
        CONST_VTBL struct IActLLTVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IActLLT_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IActLLT_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IActLLT_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IActLLT_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IActLLT_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IActLLT_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IActLLT_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IActLLT_Open(This,lplReturnCode)	\
    (This)->lpVtbl -> Open(This,lplReturnCode)

#define IActLLT_Close(This,lplReturnCode)	\
    (This)->lpVtbl -> Close(This,lplReturnCode)

#define IActLLT_GetCpuType(This,szCpuName,lplCpuCode,lplReturnCode)	\
    (This)->lpVtbl -> GetCpuType(This,szCpuName,lplCpuCode,lplReturnCode)

#define IActLLT_SetCpuStatus(This,lOperation,lplReturnCode)	\
    (This)->lpVtbl -> SetCpuStatus(This,lOperation,lplReturnCode)

#define IActLLT_ReadDeviceBlock(This,szDevice,lSize,lplData,lplReturnCode)	\
    (This)->lpVtbl -> ReadDeviceBlock(This,szDevice,lSize,lplData,lplReturnCode)

#define IActLLT_WriteDeviceBlock(This,szDevice,lSize,lplData,lplReturnCode)	\
    (This)->lpVtbl -> WriteDeviceBlock(This,szDevice,lSize,lplData,lplReturnCode)

#define IActLLT_ReadDeviceRandom(This,szDeviceList,lSize,lplData,lplReturnCode)	\
    (This)->lpVtbl -> ReadDeviceRandom(This,szDeviceList,lSize,lplData,lplReturnCode)

#define IActLLT_WriteDeviceRandom(This,szDeviceList,lSize,lplData,lplReturnCode)	\
    (This)->lpVtbl -> WriteDeviceRandom(This,szDeviceList,lSize,lplData,lplReturnCode)

#define IActLLT_ReadBuffer(This,lStartIO,lAddress,lSize,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> ReadBuffer(This,lStartIO,lAddress,lSize,lpsData,lplReturnCode)

#define IActLLT_WriteBuffer(This,lStartIO,lAddress,lSize,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> WriteBuffer(This,lStartIO,lAddress,lSize,lpsData,lplReturnCode)

#define IActLLT_GetClockData(This,lpsYear,lpsMonth,lpsDay,lpsDayOfWeek,lpsHour,lpsMinute,lpsSecond,lplReturnCode)	\
    (This)->lpVtbl -> GetClockData(This,lpsYear,lpsMonth,lpsDay,lpsDayOfWeek,lpsHour,lpsMinute,lpsSecond,lplReturnCode)

#define IActLLT_SetClockData(This,sYear,sMonth,sDay,sDayOfWeek,sHour,sMinute,sSecond,lplReturnCode)	\
    (This)->lpVtbl -> SetClockData(This,sYear,sMonth,sDay,sDayOfWeek,sHour,sMinute,sSecond,lplReturnCode)

#define IActLLT_SetDevice(This,szDevice,lData,lplReturnCode)	\
    (This)->lpVtbl -> SetDevice(This,szDevice,lData,lplReturnCode)

#define IActLLT_get_ActCpuType(This,pVal)	\
    (This)->lpVtbl -> get_ActCpuType(This,pVal)

#define IActLLT_put_ActCpuType(This,newVal)	\
    (This)->lpVtbl -> put_ActCpuType(This,newVal)

#define IActLLT_get_ActTimeOut(This,pVal)	\
    (This)->lpVtbl -> get_ActTimeOut(This,pVal)

#define IActLLT_put_ActTimeOut(This,newVal)	\
    (This)->lpVtbl -> put_ActTimeOut(This,newVal)

#define IActLLT_GetDevice(This,szDevice,lplData,lplReturnCode)	\
    (This)->lpVtbl -> GetDevice(This,szDevice,lplData,lplReturnCode)

#define IActLLT_CheckDeviceString(This,szDevice,lCheckType,lSize,lplDeviceType,lpszDeviceName,lplDeviceNumber,lplDeviceRadix,lplReturnCode)	\
    (This)->lpVtbl -> CheckDeviceString(This,szDevice,lCheckType,lSize,lplDeviceType,lpszDeviceName,lplDeviceNumber,lplDeviceRadix,lplReturnCode)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActLLT_Open_Proxy( 
    IActLLT __RPC_FAR * This,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActLLT_Open_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActLLT_Close_Proxy( 
    IActLLT __RPC_FAR * This,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActLLT_Close_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActLLT_GetCpuType_Proxy( 
    IActLLT __RPC_FAR * This,
    /* [string][out] */ BSTR __RPC_FAR *szCpuName,
    /* [out] */ LONG __RPC_FAR *lplCpuCode,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActLLT_GetCpuType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActLLT_SetCpuStatus_Proxy( 
    IActLLT __RPC_FAR * This,
    /* [in] */ LONG lOperation,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActLLT_SetCpuStatus_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActLLT_ReadDeviceBlock_Proxy( 
    IActLLT __RPC_FAR * This,
    /* [string][in] */ BSTR szDevice,
    /* [in] */ LONG lSize,
    /* [size_is][out] */ LONG __RPC_FAR *lplData,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActLLT_ReadDeviceBlock_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActLLT_WriteDeviceBlock_Proxy( 
    IActLLT __RPC_FAR * This,
    /* [string][in] */ BSTR szDevice,
    /* [in] */ LONG lSize,
    /* [size_is][in] */ LONG __RPC_FAR *lplData,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActLLT_WriteDeviceBlock_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActLLT_ReadDeviceRandom_Proxy( 
    IActLLT __RPC_FAR * This,
    /* [string][in] */ BSTR szDeviceList,
    /* [in] */ LONG lSize,
    /* [size_is][out] */ LONG __RPC_FAR *lplData,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActLLT_ReadDeviceRandom_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActLLT_WriteDeviceRandom_Proxy( 
    IActLLT __RPC_FAR * This,
    /* [string][in] */ BSTR szDeviceList,
    /* [in] */ LONG lSize,
    /* [size_is][in] */ LONG __RPC_FAR *lplData,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActLLT_WriteDeviceRandom_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActLLT_ReadBuffer_Proxy( 
    IActLLT __RPC_FAR * This,
    /* [in] */ LONG lStartIO,
    /* [in] */ LONG lAddress,
    /* [in] */ LONG lSize,
    /* [size_is][out] */ SHORT __RPC_FAR *lpsData,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActLLT_ReadBuffer_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActLLT_WriteBuffer_Proxy( 
    IActLLT __RPC_FAR * This,
    /* [in] */ LONG lStartIO,
    /* [in] */ LONG lAddress,
    /* [in] */ LONG lSize,
    /* [size_is][in] */ SHORT __RPC_FAR *lpsData,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActLLT_WriteBuffer_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActLLT_GetClockData_Proxy( 
    IActLLT __RPC_FAR * This,
    /* [out] */ SHORT __RPC_FAR *lpsYear,
    /* [out] */ SHORT __RPC_FAR *lpsMonth,
    /* [out] */ SHORT __RPC_FAR *lpsDay,
    /* [out] */ SHORT __RPC_FAR *lpsDayOfWeek,
    /* [out] */ SHORT __RPC_FAR *lpsHour,
    /* [out] */ SHORT __RPC_FAR *lpsMinute,
    /* [out] */ SHORT __RPC_FAR *lpsSecond,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActLLT_GetClockData_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActLLT_SetClockData_Proxy( 
    IActLLT __RPC_FAR * This,
    /* [in] */ SHORT sYear,
    /* [in] */ SHORT sMonth,
    /* [in] */ SHORT sDay,
    /* [in] */ SHORT sDayOfWeek,
    /* [in] */ SHORT sHour,
    /* [in] */ SHORT sMinute,
    /* [in] */ SHORT sSecond,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActLLT_SetClockData_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActLLT_SetDevice_Proxy( 
    IActLLT __RPC_FAR * This,
    /* [in] */ BSTR szDevice,
    /* [in] */ LONG lData,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActLLT_SetDevice_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActLLT_get_ActCpuType_Proxy( 
    IActLLT __RPC_FAR * This,
    /* [retval][out] */ LONG __RPC_FAR *pVal);


void __RPC_STUB IActLLT_get_ActCpuType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActLLT_put_ActCpuType_Proxy( 
    IActLLT __RPC_FAR * This,
    /* [in] */ LONG newVal);


void __RPC_STUB IActLLT_put_ActCpuType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActLLT_get_ActTimeOut_Proxy( 
    IActLLT __RPC_FAR * This,
    /* [retval][out] */ LONG __RPC_FAR *pVal);


void __RPC_STUB IActLLT_get_ActTimeOut_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActLLT_put_ActTimeOut_Proxy( 
    IActLLT __RPC_FAR * This,
    /* [in] */ LONG newVal);


void __RPC_STUB IActLLT_put_ActTimeOut_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActLLT_GetDevice_Proxy( 
    IActLLT __RPC_FAR * This,
    /* [string][in] */ BSTR szDevice,
    /* [out] */ LONG __RPC_FAR *lplData,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActLLT_GetDevice_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActLLT_CheckDeviceString_Proxy( 
    IActLLT __RPC_FAR * This,
    /* [in] */ BSTR szDevice,
    /* [in] */ LONG lCheckType,
    /* [in] */ LONG lSize,
    /* [out] */ LONG __RPC_FAR *lplDeviceType,
    /* [string][out] */ BSTR __RPC_FAR *lpszDeviceName,
    /* [out] */ LONG __RPC_FAR *lplDeviceNumber,
    /* [out] */ LONG __RPC_FAR *lplDeviceRadix,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActLLT_CheckDeviceString_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IActLLT_INTERFACE_DEFINED__ */


#ifndef __IActLLT2_INTERFACE_DEFINED__
#define __IActLLT2_INTERFACE_DEFINED__

/* interface IActLLT2 */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IActLLT2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("949316D0-C720-11d4-8743-00E0292A4FB4")
    IActLLT2 : public IActLLT
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

    typedef struct IActLLT2Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IActLLT2 __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IActLLT2 __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IActLLT2 __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IActLLT2 __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IActLLT2 __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IActLLT2 __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IActLLT2 __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Open )( 
            IActLLT2 __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Close )( 
            IActLLT2 __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetCpuType )( 
            IActLLT2 __RPC_FAR * This,
            /* [string][out] */ BSTR __RPC_FAR *szCpuName,
            /* [out] */ LONG __RPC_FAR *lplCpuCode,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetCpuStatus )( 
            IActLLT2 __RPC_FAR * This,
            /* [in] */ LONG lOperation,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceBlock )( 
            IActLLT2 __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lSize,
            /* [size_is][out] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceBlock )( 
            IActLLT2 __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lSize,
            /* [size_is][in] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceRandom )( 
            IActLLT2 __RPC_FAR * This,
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG lSize,
            /* [size_is][out] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceRandom )( 
            IActLLT2 __RPC_FAR * This,
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG lSize,
            /* [size_is][in] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadBuffer )( 
            IActLLT2 __RPC_FAR * This,
            /* [in] */ LONG lStartIO,
            /* [in] */ LONG lAddress,
            /* [in] */ LONG lSize,
            /* [size_is][out] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteBuffer )( 
            IActLLT2 __RPC_FAR * This,
            /* [in] */ LONG lStartIO,
            /* [in] */ LONG lAddress,
            /* [in] */ LONG lSize,
            /* [size_is][in] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetClockData )( 
            IActLLT2 __RPC_FAR * This,
            /* [out] */ SHORT __RPC_FAR *lpsYear,
            /* [out] */ SHORT __RPC_FAR *lpsMonth,
            /* [out] */ SHORT __RPC_FAR *lpsDay,
            /* [out] */ SHORT __RPC_FAR *lpsDayOfWeek,
            /* [out] */ SHORT __RPC_FAR *lpsHour,
            /* [out] */ SHORT __RPC_FAR *lpsMinute,
            /* [out] */ SHORT __RPC_FAR *lpsSecond,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetClockData )( 
            IActLLT2 __RPC_FAR * This,
            /* [in] */ SHORT sYear,
            /* [in] */ SHORT sMonth,
            /* [in] */ SHORT sDay,
            /* [in] */ SHORT sDayOfWeek,
            /* [in] */ SHORT sHour,
            /* [in] */ SHORT sMinute,
            /* [in] */ SHORT sSecond,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetDevice )( 
            IActLLT2 __RPC_FAR * This,
            /* [in] */ BSTR szDevice,
            /* [in] */ LONG lData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActCpuType )( 
            IActLLT2 __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActCpuType )( 
            IActLLT2 __RPC_FAR * This,
            /* [in] */ LONG newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActTimeOut )( 
            IActLLT2 __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActTimeOut )( 
            IActLLT2 __RPC_FAR * This,
            /* [in] */ LONG newVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetDevice )( 
            IActLLT2 __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [out] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CheckDeviceString )( 
            IActLLT2 __RPC_FAR * This,
            /* [in] */ BSTR szDevice,
            /* [in] */ LONG lCheckType,
            /* [in] */ LONG lSize,
            /* [out] */ LONG __RPC_FAR *lplDeviceType,
            /* [string][out] */ BSTR __RPC_FAR *lpszDeviceName,
            /* [out] */ LONG __RPC_FAR *lplDeviceNumber,
            /* [out] */ LONG __RPC_FAR *lplDeviceRadix,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *EntryDeviceStatus )( 
            IActLLT2 __RPC_FAR * This,
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG lSize,
            /* [in] */ LONG lMonitorCycle,
            /* [size_is][in] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *FreeDeviceStatus )( 
            IActLLT2 __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        END_INTERFACE
    } IActLLT2Vtbl;

    interface IActLLT2
    {
        CONST_VTBL struct IActLLT2Vtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IActLLT2_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IActLLT2_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IActLLT2_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IActLLT2_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IActLLT2_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IActLLT2_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IActLLT2_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IActLLT2_Open(This,lplReturnCode)	\
    (This)->lpVtbl -> Open(This,lplReturnCode)

#define IActLLT2_Close(This,lplReturnCode)	\
    (This)->lpVtbl -> Close(This,lplReturnCode)

#define IActLLT2_GetCpuType(This,szCpuName,lplCpuCode,lplReturnCode)	\
    (This)->lpVtbl -> GetCpuType(This,szCpuName,lplCpuCode,lplReturnCode)

#define IActLLT2_SetCpuStatus(This,lOperation,lplReturnCode)	\
    (This)->lpVtbl -> SetCpuStatus(This,lOperation,lplReturnCode)

#define IActLLT2_ReadDeviceBlock(This,szDevice,lSize,lplData,lplReturnCode)	\
    (This)->lpVtbl -> ReadDeviceBlock(This,szDevice,lSize,lplData,lplReturnCode)

#define IActLLT2_WriteDeviceBlock(This,szDevice,lSize,lplData,lplReturnCode)	\
    (This)->lpVtbl -> WriteDeviceBlock(This,szDevice,lSize,lplData,lplReturnCode)

#define IActLLT2_ReadDeviceRandom(This,szDeviceList,lSize,lplData,lplReturnCode)	\
    (This)->lpVtbl -> ReadDeviceRandom(This,szDeviceList,lSize,lplData,lplReturnCode)

#define IActLLT2_WriteDeviceRandom(This,szDeviceList,lSize,lplData,lplReturnCode)	\
    (This)->lpVtbl -> WriteDeviceRandom(This,szDeviceList,lSize,lplData,lplReturnCode)

#define IActLLT2_ReadBuffer(This,lStartIO,lAddress,lSize,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> ReadBuffer(This,lStartIO,lAddress,lSize,lpsData,lplReturnCode)

#define IActLLT2_WriteBuffer(This,lStartIO,lAddress,lSize,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> WriteBuffer(This,lStartIO,lAddress,lSize,lpsData,lplReturnCode)

#define IActLLT2_GetClockData(This,lpsYear,lpsMonth,lpsDay,lpsDayOfWeek,lpsHour,lpsMinute,lpsSecond,lplReturnCode)	\
    (This)->lpVtbl -> GetClockData(This,lpsYear,lpsMonth,lpsDay,lpsDayOfWeek,lpsHour,lpsMinute,lpsSecond,lplReturnCode)

#define IActLLT2_SetClockData(This,sYear,sMonth,sDay,sDayOfWeek,sHour,sMinute,sSecond,lplReturnCode)	\
    (This)->lpVtbl -> SetClockData(This,sYear,sMonth,sDay,sDayOfWeek,sHour,sMinute,sSecond,lplReturnCode)

#define IActLLT2_SetDevice(This,szDevice,lData,lplReturnCode)	\
    (This)->lpVtbl -> SetDevice(This,szDevice,lData,lplReturnCode)

#define IActLLT2_get_ActCpuType(This,pVal)	\
    (This)->lpVtbl -> get_ActCpuType(This,pVal)

#define IActLLT2_put_ActCpuType(This,newVal)	\
    (This)->lpVtbl -> put_ActCpuType(This,newVal)

#define IActLLT2_get_ActTimeOut(This,pVal)	\
    (This)->lpVtbl -> get_ActTimeOut(This,pVal)

#define IActLLT2_put_ActTimeOut(This,newVal)	\
    (This)->lpVtbl -> put_ActTimeOut(This,newVal)

#define IActLLT2_GetDevice(This,szDevice,lplData,lplReturnCode)	\
    (This)->lpVtbl -> GetDevice(This,szDevice,lplData,lplReturnCode)

#define IActLLT2_CheckDeviceString(This,szDevice,lCheckType,lSize,lplDeviceType,lpszDeviceName,lplDeviceNumber,lplDeviceRadix,lplReturnCode)	\
    (This)->lpVtbl -> CheckDeviceString(This,szDevice,lCheckType,lSize,lplDeviceType,lpszDeviceName,lplDeviceNumber,lplDeviceRadix,lplReturnCode)


#define IActLLT2_EntryDeviceStatus(This,szDeviceList,lSize,lMonitorCycle,lplData,lplReturnCode)	\
    (This)->lpVtbl -> EntryDeviceStatus(This,szDeviceList,lSize,lMonitorCycle,lplData,lplReturnCode)

#define IActLLT2_FreeDeviceStatus(This,lplReturnCode)	\
    (This)->lpVtbl -> FreeDeviceStatus(This,lplReturnCode)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActLLT2_EntryDeviceStatus_Proxy( 
    IActLLT2 __RPC_FAR * This,
    /* [string][in] */ BSTR szDeviceList,
    /* [in] */ LONG lSize,
    /* [in] */ LONG lMonitorCycle,
    /* [size_is][in] */ LONG __RPC_FAR *lplData,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActLLT2_EntryDeviceStatus_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActLLT2_FreeDeviceStatus_Proxy( 
    IActLLT2 __RPC_FAR * This,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActLLT2_FreeDeviceStatus_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IActLLT2_INTERFACE_DEFINED__ */


#ifndef __IActLLT3_INTERFACE_DEFINED__
#define __IActLLT3_INTERFACE_DEFINED__

/* interface IActLLT3 */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IActLLT3;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("36BE3030-6B93-11d5-9311-009099244EFD")
    IActLLT3 : public IActLLT2
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
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActNetworkNumber( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActNetworkNumber( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActStationNumber( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActStationNumber( 
            /* [in] */ long newVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IActLLT3Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IActLLT3 __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IActLLT3 __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IActLLT3 __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IActLLT3 __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IActLLT3 __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IActLLT3 __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IActLLT3 __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Open )( 
            IActLLT3 __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Close )( 
            IActLLT3 __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetCpuType )( 
            IActLLT3 __RPC_FAR * This,
            /* [string][out] */ BSTR __RPC_FAR *szCpuName,
            /* [out] */ LONG __RPC_FAR *lplCpuCode,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetCpuStatus )( 
            IActLLT3 __RPC_FAR * This,
            /* [in] */ LONG lOperation,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceBlock )( 
            IActLLT3 __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lSize,
            /* [size_is][out] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceBlock )( 
            IActLLT3 __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lSize,
            /* [size_is][in] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceRandom )( 
            IActLLT3 __RPC_FAR * This,
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG lSize,
            /* [size_is][out] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceRandom )( 
            IActLLT3 __RPC_FAR * This,
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG lSize,
            /* [size_is][in] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadBuffer )( 
            IActLLT3 __RPC_FAR * This,
            /* [in] */ LONG lStartIO,
            /* [in] */ LONG lAddress,
            /* [in] */ LONG lSize,
            /* [size_is][out] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteBuffer )( 
            IActLLT3 __RPC_FAR * This,
            /* [in] */ LONG lStartIO,
            /* [in] */ LONG lAddress,
            /* [in] */ LONG lSize,
            /* [size_is][in] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetClockData )( 
            IActLLT3 __RPC_FAR * This,
            /* [out] */ SHORT __RPC_FAR *lpsYear,
            /* [out] */ SHORT __RPC_FAR *lpsMonth,
            /* [out] */ SHORT __RPC_FAR *lpsDay,
            /* [out] */ SHORT __RPC_FAR *lpsDayOfWeek,
            /* [out] */ SHORT __RPC_FAR *lpsHour,
            /* [out] */ SHORT __RPC_FAR *lpsMinute,
            /* [out] */ SHORT __RPC_FAR *lpsSecond,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetClockData )( 
            IActLLT3 __RPC_FAR * This,
            /* [in] */ SHORT sYear,
            /* [in] */ SHORT sMonth,
            /* [in] */ SHORT sDay,
            /* [in] */ SHORT sDayOfWeek,
            /* [in] */ SHORT sHour,
            /* [in] */ SHORT sMinute,
            /* [in] */ SHORT sSecond,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetDevice )( 
            IActLLT3 __RPC_FAR * This,
            /* [in] */ BSTR szDevice,
            /* [in] */ LONG lData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActCpuType )( 
            IActLLT3 __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActCpuType )( 
            IActLLT3 __RPC_FAR * This,
            /* [in] */ LONG newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActTimeOut )( 
            IActLLT3 __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActTimeOut )( 
            IActLLT3 __RPC_FAR * This,
            /* [in] */ LONG newVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetDevice )( 
            IActLLT3 __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [out] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CheckDeviceString )( 
            IActLLT3 __RPC_FAR * This,
            /* [in] */ BSTR szDevice,
            /* [in] */ LONG lCheckType,
            /* [in] */ LONG lSize,
            /* [out] */ LONG __RPC_FAR *lplDeviceType,
            /* [string][out] */ BSTR __RPC_FAR *lpszDeviceName,
            /* [out] */ LONG __RPC_FAR *lplDeviceNumber,
            /* [out] */ LONG __RPC_FAR *lplDeviceRadix,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *EntryDeviceStatus )( 
            IActLLT3 __RPC_FAR * This,
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG lSize,
            /* [in] */ LONG lMonitorCycle,
            /* [size_is][in] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *FreeDeviceStatus )( 
            IActLLT3 __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceBlock2 )( 
            IActLLT3 __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lSize,
            /* [size_is][out] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceBlock2 )( 
            IActLLT3 __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lSize,
            /* [size_is][in] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceRandom2 )( 
            IActLLT3 __RPC_FAR * This,
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG lSize,
            /* [size_is][out] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceRandom2 )( 
            IActLLT3 __RPC_FAR * This,
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG lSize,
            /* [size_is][in] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetDevice2 )( 
            IActLLT3 __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [out] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetDevice2 )( 
            IActLLT3 __RPC_FAR * This,
            /* [in] */ BSTR szDevice,
            /* [in] */ SHORT sData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActNetworkNumber )( 
            IActLLT3 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActNetworkNumber )( 
            IActLLT3 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActStationNumber )( 
            IActLLT3 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActStationNumber )( 
            IActLLT3 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        END_INTERFACE
    } IActLLT3Vtbl;

    interface IActLLT3
    {
        CONST_VTBL struct IActLLT3Vtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IActLLT3_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IActLLT3_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IActLLT3_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IActLLT3_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IActLLT3_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IActLLT3_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IActLLT3_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IActLLT3_Open(This,lplReturnCode)	\
    (This)->lpVtbl -> Open(This,lplReturnCode)

#define IActLLT3_Close(This,lplReturnCode)	\
    (This)->lpVtbl -> Close(This,lplReturnCode)

#define IActLLT3_GetCpuType(This,szCpuName,lplCpuCode,lplReturnCode)	\
    (This)->lpVtbl -> GetCpuType(This,szCpuName,lplCpuCode,lplReturnCode)

#define IActLLT3_SetCpuStatus(This,lOperation,lplReturnCode)	\
    (This)->lpVtbl -> SetCpuStatus(This,lOperation,lplReturnCode)

#define IActLLT3_ReadDeviceBlock(This,szDevice,lSize,lplData,lplReturnCode)	\
    (This)->lpVtbl -> ReadDeviceBlock(This,szDevice,lSize,lplData,lplReturnCode)

#define IActLLT3_WriteDeviceBlock(This,szDevice,lSize,lplData,lplReturnCode)	\
    (This)->lpVtbl -> WriteDeviceBlock(This,szDevice,lSize,lplData,lplReturnCode)

#define IActLLT3_ReadDeviceRandom(This,szDeviceList,lSize,lplData,lplReturnCode)	\
    (This)->lpVtbl -> ReadDeviceRandom(This,szDeviceList,lSize,lplData,lplReturnCode)

#define IActLLT3_WriteDeviceRandom(This,szDeviceList,lSize,lplData,lplReturnCode)	\
    (This)->lpVtbl -> WriteDeviceRandom(This,szDeviceList,lSize,lplData,lplReturnCode)

#define IActLLT3_ReadBuffer(This,lStartIO,lAddress,lSize,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> ReadBuffer(This,lStartIO,lAddress,lSize,lpsData,lplReturnCode)

#define IActLLT3_WriteBuffer(This,lStartIO,lAddress,lSize,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> WriteBuffer(This,lStartIO,lAddress,lSize,lpsData,lplReturnCode)

#define IActLLT3_GetClockData(This,lpsYear,lpsMonth,lpsDay,lpsDayOfWeek,lpsHour,lpsMinute,lpsSecond,lplReturnCode)	\
    (This)->lpVtbl -> GetClockData(This,lpsYear,lpsMonth,lpsDay,lpsDayOfWeek,lpsHour,lpsMinute,lpsSecond,lplReturnCode)

#define IActLLT3_SetClockData(This,sYear,sMonth,sDay,sDayOfWeek,sHour,sMinute,sSecond,lplReturnCode)	\
    (This)->lpVtbl -> SetClockData(This,sYear,sMonth,sDay,sDayOfWeek,sHour,sMinute,sSecond,lplReturnCode)

#define IActLLT3_SetDevice(This,szDevice,lData,lplReturnCode)	\
    (This)->lpVtbl -> SetDevice(This,szDevice,lData,lplReturnCode)

#define IActLLT3_get_ActCpuType(This,pVal)	\
    (This)->lpVtbl -> get_ActCpuType(This,pVal)

#define IActLLT3_put_ActCpuType(This,newVal)	\
    (This)->lpVtbl -> put_ActCpuType(This,newVal)

#define IActLLT3_get_ActTimeOut(This,pVal)	\
    (This)->lpVtbl -> get_ActTimeOut(This,pVal)

#define IActLLT3_put_ActTimeOut(This,newVal)	\
    (This)->lpVtbl -> put_ActTimeOut(This,newVal)

#define IActLLT3_GetDevice(This,szDevice,lplData,lplReturnCode)	\
    (This)->lpVtbl -> GetDevice(This,szDevice,lplData,lplReturnCode)

#define IActLLT3_CheckDeviceString(This,szDevice,lCheckType,lSize,lplDeviceType,lpszDeviceName,lplDeviceNumber,lplDeviceRadix,lplReturnCode)	\
    (This)->lpVtbl -> CheckDeviceString(This,szDevice,lCheckType,lSize,lplDeviceType,lpszDeviceName,lplDeviceNumber,lplDeviceRadix,lplReturnCode)


#define IActLLT3_EntryDeviceStatus(This,szDeviceList,lSize,lMonitorCycle,lplData,lplReturnCode)	\
    (This)->lpVtbl -> EntryDeviceStatus(This,szDeviceList,lSize,lMonitorCycle,lplData,lplReturnCode)

#define IActLLT3_FreeDeviceStatus(This,lplReturnCode)	\
    (This)->lpVtbl -> FreeDeviceStatus(This,lplReturnCode)


#define IActLLT3_ReadDeviceBlock2(This,szDevice,lSize,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> ReadDeviceBlock2(This,szDevice,lSize,lpsData,lplReturnCode)

#define IActLLT3_WriteDeviceBlock2(This,szDevice,lSize,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> WriteDeviceBlock2(This,szDevice,lSize,lpsData,lplReturnCode)

#define IActLLT3_ReadDeviceRandom2(This,szDeviceList,lSize,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> ReadDeviceRandom2(This,szDeviceList,lSize,lpsData,lplReturnCode)

#define IActLLT3_WriteDeviceRandom2(This,szDeviceList,lSize,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> WriteDeviceRandom2(This,szDeviceList,lSize,lpsData,lplReturnCode)

#define IActLLT3_GetDevice2(This,szDevice,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> GetDevice2(This,szDevice,lpsData,lplReturnCode)

#define IActLLT3_SetDevice2(This,szDevice,sData,lplReturnCode)	\
    (This)->lpVtbl -> SetDevice2(This,szDevice,sData,lplReturnCode)

#define IActLLT3_get_ActNetworkNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActNetworkNumber(This,pVal)

#define IActLLT3_put_ActNetworkNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActNetworkNumber(This,newVal)

#define IActLLT3_get_ActStationNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActStationNumber(This,pVal)

#define IActLLT3_put_ActStationNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActStationNumber(This,newVal)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActLLT3_ReadDeviceBlock2_Proxy( 
    IActLLT3 __RPC_FAR * This,
    /* [string][in] */ BSTR szDevice,
    /* [in] */ LONG lSize,
    /* [size_is][out] */ SHORT __RPC_FAR *lpsData,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActLLT3_ReadDeviceBlock2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActLLT3_WriteDeviceBlock2_Proxy( 
    IActLLT3 __RPC_FAR * This,
    /* [string][in] */ BSTR szDevice,
    /* [in] */ LONG lSize,
    /* [size_is][in] */ SHORT __RPC_FAR *lpsData,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActLLT3_WriteDeviceBlock2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActLLT3_ReadDeviceRandom2_Proxy( 
    IActLLT3 __RPC_FAR * This,
    /* [string][in] */ BSTR szDeviceList,
    /* [in] */ LONG lSize,
    /* [size_is][out] */ SHORT __RPC_FAR *lpsData,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActLLT3_ReadDeviceRandom2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActLLT3_WriteDeviceRandom2_Proxy( 
    IActLLT3 __RPC_FAR * This,
    /* [string][in] */ BSTR szDeviceList,
    /* [in] */ LONG lSize,
    /* [size_is][in] */ SHORT __RPC_FAR *lpsData,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActLLT3_WriteDeviceRandom2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActLLT3_GetDevice2_Proxy( 
    IActLLT3 __RPC_FAR * This,
    /* [string][in] */ BSTR szDevice,
    /* [out] */ SHORT __RPC_FAR *lpsData,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActLLT3_GetDevice2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActLLT3_SetDevice2_Proxy( 
    IActLLT3 __RPC_FAR * This,
    /* [in] */ BSTR szDevice,
    /* [in] */ SHORT sData,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActLLT3_SetDevice2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActLLT3_get_ActNetworkNumber_Proxy( 
    IActLLT3 __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IActLLT3_get_ActNetworkNumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActLLT3_put_ActNetworkNumber_Proxy( 
    IActLLT3 __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB IActLLT3_put_ActNetworkNumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActLLT3_get_ActStationNumber_Proxy( 
    IActLLT3 __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IActLLT3_get_ActStationNumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActLLT3_put_ActStationNumber_Proxy( 
    IActLLT3 __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB IActLLT3_put_ActStationNumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IActLLT3_INTERFACE_DEFINED__ */


#ifndef __IActMLLLT_INTERFACE_DEFINED__
#define __IActMLLLT_INTERFACE_DEFINED__

/* interface IActMLLLT */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IActMLLLT;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("0742D5C1-A98C-11D4-910D-009099244EFD")
    IActMLLLT : public IDispatch
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
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActCpuType( 
            /* [retval][out] */ VARIANT __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActCpuType( 
            /* [in] */ VARIANT newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActTimeOut( 
            /* [retval][out] */ VARIANT __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActTimeOut( 
            /* [in] */ VARIANT newVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE FreeDeviceStatus( 
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IActMLLLTVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IActMLLLT __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IActMLLLT __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IActMLLLT __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IActMLLLT __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IActMLLLT __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IActMLLLT __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IActMLLLT __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Open )( 
            IActMLLLT __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Close )( 
            IActMLLLT __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetDevice )( 
            IActMLLLT __RPC_FAR * This,
            /* [in] */ VARIANT varDevice,
            /* [out] */ VARIANT __RPC_FAR *lpvarData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetDevice )( 
            IActMLLLT __RPC_FAR * This,
            /* [in] */ VARIANT varDevice,
            /* [in] */ VARIANT varData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceBlock )( 
            IActMLLLT __RPC_FAR * This,
            /* [in] */ VARIANT varDevice,
            /* [in] */ VARIANT varSize,
            /* [out] */ VARIANT __RPC_FAR *lpvarData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceBlock )( 
            IActMLLLT __RPC_FAR * This,
            /* [in] */ VARIANT varDevice,
            /* [in] */ VARIANT varSize,
            /* [in] */ VARIANT varData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceRandom )( 
            IActMLLLT __RPC_FAR * This,
            /* [in] */ VARIANT varDeviceList,
            /* [in] */ VARIANT varSize,
            /* [out] */ VARIANT __RPC_FAR *lpvarData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceRandom )( 
            IActMLLLT __RPC_FAR * This,
            /* [in] */ VARIANT varDeviceList,
            /* [in] */ VARIANT varSize,
            /* [in] */ VARIANT varData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadBuffer )( 
            IActMLLLT __RPC_FAR * This,
            /* [in] */ VARIANT varStartIO,
            /* [in] */ VARIANT varAddress,
            /* [in] */ VARIANT varReadSize,
            /* [out] */ VARIANT __RPC_FAR *lpvarData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteBuffer )( 
            IActMLLLT __RPC_FAR * This,
            /* [in] */ VARIANT varStartIO,
            /* [in] */ VARIANT varAddress,
            /* [in] */ VARIANT varWriteSize,
            /* [in] */ VARIANT varData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetCpuType )( 
            IActMLLLT __RPC_FAR * This,
            /* [out] */ VARIANT __RPC_FAR *lpvarCpuName,
            /* [out] */ VARIANT __RPC_FAR *lpvarCpuType,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetCpuStatus )( 
            IActMLLLT __RPC_FAR * This,
            /* [in] */ VARIANT varOperation,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetClockData )( 
            IActMLLLT __RPC_FAR * This,
            /* [out] */ VARIANT __RPC_FAR *lpvarYear,
            /* [out] */ VARIANT __RPC_FAR *lpvarMonth,
            /* [out] */ VARIANT __RPC_FAR *lpvarDay,
            /* [out] */ VARIANT __RPC_FAR *lpvarDayOfWeek,
            /* [out] */ VARIANT __RPC_FAR *lpvarHour,
            /* [out] */ VARIANT __RPC_FAR *lpvarMinute,
            /* [out] */ VARIANT __RPC_FAR *lpvarSecond,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetClockData )( 
            IActMLLLT __RPC_FAR * This,
            /* [in] */ VARIANT varYear,
            /* [in] */ VARIANT varMonth,
            /* [in] */ VARIANT varDay,
            /* [in] */ VARIANT varDayOfWeek,
            /* [in] */ VARIANT varHour,
            /* [in] */ VARIANT varMinute,
            /* [in] */ VARIANT varSecond,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *EntryDeviceStatus )( 
            IActMLLLT __RPC_FAR * This,
            /* [in] */ VARIANT varDeviceList,
            /* [in] */ VARIANT varSize,
            /* [in] */ VARIANT varMonitorCycle,
            /* [in] */ VARIANT varData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActCpuType )( 
            IActMLLLT __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActCpuType )( 
            IActMLLLT __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActTimeOut )( 
            IActMLLLT __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActTimeOut )( 
            IActMLLLT __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *FreeDeviceStatus )( 
            IActMLLLT __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        END_INTERFACE
    } IActMLLLTVtbl;

    interface IActMLLLT
    {
        CONST_VTBL struct IActMLLLTVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IActMLLLT_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IActMLLLT_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IActMLLLT_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IActMLLLT_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IActMLLLT_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IActMLLLT_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IActMLLLT_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IActMLLLT_Open(This,lpvarReturnCode)	\
    (This)->lpVtbl -> Open(This,lpvarReturnCode)

#define IActMLLLT_Close(This,lpvarReturnCode)	\
    (This)->lpVtbl -> Close(This,lpvarReturnCode)

#define IActMLLLT_GetDevice(This,varDevice,lpvarData,lpvarReturnCode)	\
    (This)->lpVtbl -> GetDevice(This,varDevice,lpvarData,lpvarReturnCode)

#define IActMLLLT_SetDevice(This,varDevice,varData,lpvarReturnCode)	\
    (This)->lpVtbl -> SetDevice(This,varDevice,varData,lpvarReturnCode)

#define IActMLLLT_ReadDeviceBlock(This,varDevice,varSize,lpvarData,lpvarReturnCode)	\
    (This)->lpVtbl -> ReadDeviceBlock(This,varDevice,varSize,lpvarData,lpvarReturnCode)

#define IActMLLLT_WriteDeviceBlock(This,varDevice,varSize,varData,lpvarReturnCode)	\
    (This)->lpVtbl -> WriteDeviceBlock(This,varDevice,varSize,varData,lpvarReturnCode)

#define IActMLLLT_ReadDeviceRandom(This,varDeviceList,varSize,lpvarData,lpvarReturnCode)	\
    (This)->lpVtbl -> ReadDeviceRandom(This,varDeviceList,varSize,lpvarData,lpvarReturnCode)

#define IActMLLLT_WriteDeviceRandom(This,varDeviceList,varSize,varData,lpvarReturnCode)	\
    (This)->lpVtbl -> WriteDeviceRandom(This,varDeviceList,varSize,varData,lpvarReturnCode)

#define IActMLLLT_ReadBuffer(This,varStartIO,varAddress,varReadSize,lpvarData,lpvarReturnCode)	\
    (This)->lpVtbl -> ReadBuffer(This,varStartIO,varAddress,varReadSize,lpvarData,lpvarReturnCode)

#define IActMLLLT_WriteBuffer(This,varStartIO,varAddress,varWriteSize,varData,lpvarReturnCode)	\
    (This)->lpVtbl -> WriteBuffer(This,varStartIO,varAddress,varWriteSize,varData,lpvarReturnCode)

#define IActMLLLT_GetCpuType(This,lpvarCpuName,lpvarCpuType,lpvarReturnCode)	\
    (This)->lpVtbl -> GetCpuType(This,lpvarCpuName,lpvarCpuType,lpvarReturnCode)

#define IActMLLLT_SetCpuStatus(This,varOperation,lpvarReturnCode)	\
    (This)->lpVtbl -> SetCpuStatus(This,varOperation,lpvarReturnCode)

#define IActMLLLT_GetClockData(This,lpvarYear,lpvarMonth,lpvarDay,lpvarDayOfWeek,lpvarHour,lpvarMinute,lpvarSecond,lpvarReturnCode)	\
    (This)->lpVtbl -> GetClockData(This,lpvarYear,lpvarMonth,lpvarDay,lpvarDayOfWeek,lpvarHour,lpvarMinute,lpvarSecond,lpvarReturnCode)

#define IActMLLLT_SetClockData(This,varYear,varMonth,varDay,varDayOfWeek,varHour,varMinute,varSecond,lpvarReturnCode)	\
    (This)->lpVtbl -> SetClockData(This,varYear,varMonth,varDay,varDayOfWeek,varHour,varMinute,varSecond,lpvarReturnCode)

#define IActMLLLT_EntryDeviceStatus(This,varDeviceList,varSize,varMonitorCycle,varData,lpvarReturnCode)	\
    (This)->lpVtbl -> EntryDeviceStatus(This,varDeviceList,varSize,varMonitorCycle,varData,lpvarReturnCode)

#define IActMLLLT_get_ActCpuType(This,pVal)	\
    (This)->lpVtbl -> get_ActCpuType(This,pVal)

#define IActMLLLT_put_ActCpuType(This,newVal)	\
    (This)->lpVtbl -> put_ActCpuType(This,newVal)

#define IActMLLLT_get_ActTimeOut(This,pVal)	\
    (This)->lpVtbl -> get_ActTimeOut(This,pVal)

#define IActMLLLT_put_ActTimeOut(This,newVal)	\
    (This)->lpVtbl -> put_ActTimeOut(This,newVal)

#define IActMLLLT_FreeDeviceStatus(This,lpvarReturnCode)	\
    (This)->lpVtbl -> FreeDeviceStatus(This,lpvarReturnCode)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActMLLLT_Open_Proxy( 
    IActMLLLT __RPC_FAR * This,
    /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);


void __RPC_STUB IActMLLLT_Open_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActMLLLT_Close_Proxy( 
    IActMLLLT __RPC_FAR * This,
    /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);


void __RPC_STUB IActMLLLT_Close_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActMLLLT_GetDevice_Proxy( 
    IActMLLLT __RPC_FAR * This,
    /* [in] */ VARIANT varDevice,
    /* [out] */ VARIANT __RPC_FAR *lpvarData,
    /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);


void __RPC_STUB IActMLLLT_GetDevice_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActMLLLT_SetDevice_Proxy( 
    IActMLLLT __RPC_FAR * This,
    /* [in] */ VARIANT varDevice,
    /* [in] */ VARIANT varData,
    /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);


void __RPC_STUB IActMLLLT_SetDevice_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActMLLLT_ReadDeviceBlock_Proxy( 
    IActMLLLT __RPC_FAR * This,
    /* [in] */ VARIANT varDevice,
    /* [in] */ VARIANT varSize,
    /* [out] */ VARIANT __RPC_FAR *lpvarData,
    /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);


void __RPC_STUB IActMLLLT_ReadDeviceBlock_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActMLLLT_WriteDeviceBlock_Proxy( 
    IActMLLLT __RPC_FAR * This,
    /* [in] */ VARIANT varDevice,
    /* [in] */ VARIANT varSize,
    /* [in] */ VARIANT varData,
    /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);


void __RPC_STUB IActMLLLT_WriteDeviceBlock_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActMLLLT_ReadDeviceRandom_Proxy( 
    IActMLLLT __RPC_FAR * This,
    /* [in] */ VARIANT varDeviceList,
    /* [in] */ VARIANT varSize,
    /* [out] */ VARIANT __RPC_FAR *lpvarData,
    /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);


void __RPC_STUB IActMLLLT_ReadDeviceRandom_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActMLLLT_WriteDeviceRandom_Proxy( 
    IActMLLLT __RPC_FAR * This,
    /* [in] */ VARIANT varDeviceList,
    /* [in] */ VARIANT varSize,
    /* [in] */ VARIANT varData,
    /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);


void __RPC_STUB IActMLLLT_WriteDeviceRandom_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActMLLLT_ReadBuffer_Proxy( 
    IActMLLLT __RPC_FAR * This,
    /* [in] */ VARIANT varStartIO,
    /* [in] */ VARIANT varAddress,
    /* [in] */ VARIANT varReadSize,
    /* [out] */ VARIANT __RPC_FAR *lpvarData,
    /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);


void __RPC_STUB IActMLLLT_ReadBuffer_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActMLLLT_WriteBuffer_Proxy( 
    IActMLLLT __RPC_FAR * This,
    /* [in] */ VARIANT varStartIO,
    /* [in] */ VARIANT varAddress,
    /* [in] */ VARIANT varWriteSize,
    /* [in] */ VARIANT varData,
    /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);


void __RPC_STUB IActMLLLT_WriteBuffer_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActMLLLT_GetCpuType_Proxy( 
    IActMLLLT __RPC_FAR * This,
    /* [out] */ VARIANT __RPC_FAR *lpvarCpuName,
    /* [out] */ VARIANT __RPC_FAR *lpvarCpuType,
    /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);


void __RPC_STUB IActMLLLT_GetCpuType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActMLLLT_SetCpuStatus_Proxy( 
    IActMLLLT __RPC_FAR * This,
    /* [in] */ VARIANT varOperation,
    /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);


void __RPC_STUB IActMLLLT_SetCpuStatus_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActMLLLT_GetClockData_Proxy( 
    IActMLLLT __RPC_FAR * This,
    /* [out] */ VARIANT __RPC_FAR *lpvarYear,
    /* [out] */ VARIANT __RPC_FAR *lpvarMonth,
    /* [out] */ VARIANT __RPC_FAR *lpvarDay,
    /* [out] */ VARIANT __RPC_FAR *lpvarDayOfWeek,
    /* [out] */ VARIANT __RPC_FAR *lpvarHour,
    /* [out] */ VARIANT __RPC_FAR *lpvarMinute,
    /* [out] */ VARIANT __RPC_FAR *lpvarSecond,
    /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);


void __RPC_STUB IActMLLLT_GetClockData_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActMLLLT_SetClockData_Proxy( 
    IActMLLLT __RPC_FAR * This,
    /* [in] */ VARIANT varYear,
    /* [in] */ VARIANT varMonth,
    /* [in] */ VARIANT varDay,
    /* [in] */ VARIANT varDayOfWeek,
    /* [in] */ VARIANT varHour,
    /* [in] */ VARIANT varMinute,
    /* [in] */ VARIANT varSecond,
    /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);


void __RPC_STUB IActMLLLT_SetClockData_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActMLLLT_EntryDeviceStatus_Proxy( 
    IActMLLLT __RPC_FAR * This,
    /* [in] */ VARIANT varDeviceList,
    /* [in] */ VARIANT varSize,
    /* [in] */ VARIANT varMonitorCycle,
    /* [in] */ VARIANT varData,
    /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);


void __RPC_STUB IActMLLLT_EntryDeviceStatus_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActMLLLT_get_ActCpuType_Proxy( 
    IActMLLLT __RPC_FAR * This,
    /* [retval][out] */ VARIANT __RPC_FAR *pVal);


void __RPC_STUB IActMLLLT_get_ActCpuType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActMLLLT_put_ActCpuType_Proxy( 
    IActMLLLT __RPC_FAR * This,
    /* [in] */ VARIANT newVal);


void __RPC_STUB IActMLLLT_put_ActCpuType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActMLLLT_get_ActTimeOut_Proxy( 
    IActMLLLT __RPC_FAR * This,
    /* [retval][out] */ VARIANT __RPC_FAR *pVal);


void __RPC_STUB IActMLLLT_get_ActTimeOut_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActMLLLT_put_ActTimeOut_Proxy( 
    IActMLLLT __RPC_FAR * This,
    /* [in] */ VARIANT newVal);


void __RPC_STUB IActMLLLT_put_ActTimeOut_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActMLLLT_FreeDeviceStatus_Proxy( 
    IActMLLLT __RPC_FAR * This,
    /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);


void __RPC_STUB IActMLLLT_FreeDeviceStatus_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IActMLLLT_INTERFACE_DEFINED__ */


#ifndef __IActMLLLT2_INTERFACE_DEFINED__
#define __IActMLLLT2_INTERFACE_DEFINED__

/* interface IActMLLLT2 */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IActMLLLT2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("96771A91-705A-11d5-9317-009099244EFD")
    IActMLLLT2 : public IActMLLLT
    {
    public:
    };
    
#else 	/* C style interface */

    typedef struct IActMLLLT2Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IActMLLLT2 __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IActMLLLT2 __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IActMLLLT2 __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IActMLLLT2 __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IActMLLLT2 __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IActMLLLT2 __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IActMLLLT2 __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Open )( 
            IActMLLLT2 __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Close )( 
            IActMLLLT2 __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetDevice )( 
            IActMLLLT2 __RPC_FAR * This,
            /* [in] */ VARIANT varDevice,
            /* [out] */ VARIANT __RPC_FAR *lpvarData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetDevice )( 
            IActMLLLT2 __RPC_FAR * This,
            /* [in] */ VARIANT varDevice,
            /* [in] */ VARIANT varData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceBlock )( 
            IActMLLLT2 __RPC_FAR * This,
            /* [in] */ VARIANT varDevice,
            /* [in] */ VARIANT varSize,
            /* [out] */ VARIANT __RPC_FAR *lpvarData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceBlock )( 
            IActMLLLT2 __RPC_FAR * This,
            /* [in] */ VARIANT varDevice,
            /* [in] */ VARIANT varSize,
            /* [in] */ VARIANT varData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceRandom )( 
            IActMLLLT2 __RPC_FAR * This,
            /* [in] */ VARIANT varDeviceList,
            /* [in] */ VARIANT varSize,
            /* [out] */ VARIANT __RPC_FAR *lpvarData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceRandom )( 
            IActMLLLT2 __RPC_FAR * This,
            /* [in] */ VARIANT varDeviceList,
            /* [in] */ VARIANT varSize,
            /* [in] */ VARIANT varData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadBuffer )( 
            IActMLLLT2 __RPC_FAR * This,
            /* [in] */ VARIANT varStartIO,
            /* [in] */ VARIANT varAddress,
            /* [in] */ VARIANT varReadSize,
            /* [out] */ VARIANT __RPC_FAR *lpvarData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteBuffer )( 
            IActMLLLT2 __RPC_FAR * This,
            /* [in] */ VARIANT varStartIO,
            /* [in] */ VARIANT varAddress,
            /* [in] */ VARIANT varWriteSize,
            /* [in] */ VARIANT varData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetCpuType )( 
            IActMLLLT2 __RPC_FAR * This,
            /* [out] */ VARIANT __RPC_FAR *lpvarCpuName,
            /* [out] */ VARIANT __RPC_FAR *lpvarCpuType,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetCpuStatus )( 
            IActMLLLT2 __RPC_FAR * This,
            /* [in] */ VARIANT varOperation,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetClockData )( 
            IActMLLLT2 __RPC_FAR * This,
            /* [out] */ VARIANT __RPC_FAR *lpvarYear,
            /* [out] */ VARIANT __RPC_FAR *lpvarMonth,
            /* [out] */ VARIANT __RPC_FAR *lpvarDay,
            /* [out] */ VARIANT __RPC_FAR *lpvarDayOfWeek,
            /* [out] */ VARIANT __RPC_FAR *lpvarHour,
            /* [out] */ VARIANT __RPC_FAR *lpvarMinute,
            /* [out] */ VARIANT __RPC_FAR *lpvarSecond,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetClockData )( 
            IActMLLLT2 __RPC_FAR * This,
            /* [in] */ VARIANT varYear,
            /* [in] */ VARIANT varMonth,
            /* [in] */ VARIANT varDay,
            /* [in] */ VARIANT varDayOfWeek,
            /* [in] */ VARIANT varHour,
            /* [in] */ VARIANT varMinute,
            /* [in] */ VARIANT varSecond,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *EntryDeviceStatus )( 
            IActMLLLT2 __RPC_FAR * This,
            /* [in] */ VARIANT varDeviceList,
            /* [in] */ VARIANT varSize,
            /* [in] */ VARIANT varMonitorCycle,
            /* [in] */ VARIANT varData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActCpuType )( 
            IActMLLLT2 __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActCpuType )( 
            IActMLLLT2 __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActTimeOut )( 
            IActMLLLT2 __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActTimeOut )( 
            IActMLLLT2 __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *FreeDeviceStatus )( 
            IActMLLLT2 __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        END_INTERFACE
    } IActMLLLT2Vtbl;

    interface IActMLLLT2
    {
        CONST_VTBL struct IActMLLLT2Vtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IActMLLLT2_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IActMLLLT2_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IActMLLLT2_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IActMLLLT2_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IActMLLLT2_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IActMLLLT2_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IActMLLLT2_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IActMLLLT2_Open(This,lpvarReturnCode)	\
    (This)->lpVtbl -> Open(This,lpvarReturnCode)

#define IActMLLLT2_Close(This,lpvarReturnCode)	\
    (This)->lpVtbl -> Close(This,lpvarReturnCode)

#define IActMLLLT2_GetDevice(This,varDevice,lpvarData,lpvarReturnCode)	\
    (This)->lpVtbl -> GetDevice(This,varDevice,lpvarData,lpvarReturnCode)

#define IActMLLLT2_SetDevice(This,varDevice,varData,lpvarReturnCode)	\
    (This)->lpVtbl -> SetDevice(This,varDevice,varData,lpvarReturnCode)

#define IActMLLLT2_ReadDeviceBlock(This,varDevice,varSize,lpvarData,lpvarReturnCode)	\
    (This)->lpVtbl -> ReadDeviceBlock(This,varDevice,varSize,lpvarData,lpvarReturnCode)

#define IActMLLLT2_WriteDeviceBlock(This,varDevice,varSize,varData,lpvarReturnCode)	\
    (This)->lpVtbl -> WriteDeviceBlock(This,varDevice,varSize,varData,lpvarReturnCode)

#define IActMLLLT2_ReadDeviceRandom(This,varDeviceList,varSize,lpvarData,lpvarReturnCode)	\
    (This)->lpVtbl -> ReadDeviceRandom(This,varDeviceList,varSize,lpvarData,lpvarReturnCode)

#define IActMLLLT2_WriteDeviceRandom(This,varDeviceList,varSize,varData,lpvarReturnCode)	\
    (This)->lpVtbl -> WriteDeviceRandom(This,varDeviceList,varSize,varData,lpvarReturnCode)

#define IActMLLLT2_ReadBuffer(This,varStartIO,varAddress,varReadSize,lpvarData,lpvarReturnCode)	\
    (This)->lpVtbl -> ReadBuffer(This,varStartIO,varAddress,varReadSize,lpvarData,lpvarReturnCode)

#define IActMLLLT2_WriteBuffer(This,varStartIO,varAddress,varWriteSize,varData,lpvarReturnCode)	\
    (This)->lpVtbl -> WriteBuffer(This,varStartIO,varAddress,varWriteSize,varData,lpvarReturnCode)

#define IActMLLLT2_GetCpuType(This,lpvarCpuName,lpvarCpuType,lpvarReturnCode)	\
    (This)->lpVtbl -> GetCpuType(This,lpvarCpuName,lpvarCpuType,lpvarReturnCode)

#define IActMLLLT2_SetCpuStatus(This,varOperation,lpvarReturnCode)	\
    (This)->lpVtbl -> SetCpuStatus(This,varOperation,lpvarReturnCode)

#define IActMLLLT2_GetClockData(This,lpvarYear,lpvarMonth,lpvarDay,lpvarDayOfWeek,lpvarHour,lpvarMinute,lpvarSecond,lpvarReturnCode)	\
    (This)->lpVtbl -> GetClockData(This,lpvarYear,lpvarMonth,lpvarDay,lpvarDayOfWeek,lpvarHour,lpvarMinute,lpvarSecond,lpvarReturnCode)

#define IActMLLLT2_SetClockData(This,varYear,varMonth,varDay,varDayOfWeek,varHour,varMinute,varSecond,lpvarReturnCode)	\
    (This)->lpVtbl -> SetClockData(This,varYear,varMonth,varDay,varDayOfWeek,varHour,varMinute,varSecond,lpvarReturnCode)

#define IActMLLLT2_EntryDeviceStatus(This,varDeviceList,varSize,varMonitorCycle,varData,lpvarReturnCode)	\
    (This)->lpVtbl -> EntryDeviceStatus(This,varDeviceList,varSize,varMonitorCycle,varData,lpvarReturnCode)

#define IActMLLLT2_get_ActCpuType(This,pVal)	\
    (This)->lpVtbl -> get_ActCpuType(This,pVal)

#define IActMLLLT2_put_ActCpuType(This,newVal)	\
    (This)->lpVtbl -> put_ActCpuType(This,newVal)

#define IActMLLLT2_get_ActTimeOut(This,pVal)	\
    (This)->lpVtbl -> get_ActTimeOut(This,pVal)

#define IActMLLLT2_put_ActTimeOut(This,newVal)	\
    (This)->lpVtbl -> put_ActTimeOut(This,newVal)

#define IActMLLLT2_FreeDeviceStatus(This,lpvarReturnCode)	\
    (This)->lpVtbl -> FreeDeviceStatus(This,lpvarReturnCode)


#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IActMLLLT2_INTERFACE_DEFINED__ */


#ifndef __IActMLLLT3_INTERFACE_DEFINED__
#define __IActMLLLT3_INTERFACE_DEFINED__

/* interface IActMLLLT3 */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IActMLLLT3;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("36BE3031-6B93-11d5-9311-009099244EFD")
    IActMLLLT3 : public IActMLLLT2
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
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActNetworkNumber( 
            /* [retval][out] */ VARIANT __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActNetworkNumber( 
            /* [in] */ VARIANT newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActStationNumber( 
            /* [retval][out] */ VARIANT __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActStationNumber( 
            /* [in] */ VARIANT newVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IActMLLLT3Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IActMLLLT3 __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IActMLLLT3 __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IActMLLLT3 __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IActMLLLT3 __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IActMLLLT3 __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IActMLLLT3 __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IActMLLLT3 __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Open )( 
            IActMLLLT3 __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Close )( 
            IActMLLLT3 __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetDevice )( 
            IActMLLLT3 __RPC_FAR * This,
            /* [in] */ VARIANT varDevice,
            /* [out] */ VARIANT __RPC_FAR *lpvarData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetDevice )( 
            IActMLLLT3 __RPC_FAR * This,
            /* [in] */ VARIANT varDevice,
            /* [in] */ VARIANT varData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceBlock )( 
            IActMLLLT3 __RPC_FAR * This,
            /* [in] */ VARIANT varDevice,
            /* [in] */ VARIANT varSize,
            /* [out] */ VARIANT __RPC_FAR *lpvarData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceBlock )( 
            IActMLLLT3 __RPC_FAR * This,
            /* [in] */ VARIANT varDevice,
            /* [in] */ VARIANT varSize,
            /* [in] */ VARIANT varData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceRandom )( 
            IActMLLLT3 __RPC_FAR * This,
            /* [in] */ VARIANT varDeviceList,
            /* [in] */ VARIANT varSize,
            /* [out] */ VARIANT __RPC_FAR *lpvarData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceRandom )( 
            IActMLLLT3 __RPC_FAR * This,
            /* [in] */ VARIANT varDeviceList,
            /* [in] */ VARIANT varSize,
            /* [in] */ VARIANT varData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadBuffer )( 
            IActMLLLT3 __RPC_FAR * This,
            /* [in] */ VARIANT varStartIO,
            /* [in] */ VARIANT varAddress,
            /* [in] */ VARIANT varReadSize,
            /* [out] */ VARIANT __RPC_FAR *lpvarData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteBuffer )( 
            IActMLLLT3 __RPC_FAR * This,
            /* [in] */ VARIANT varStartIO,
            /* [in] */ VARIANT varAddress,
            /* [in] */ VARIANT varWriteSize,
            /* [in] */ VARIANT varData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetCpuType )( 
            IActMLLLT3 __RPC_FAR * This,
            /* [out] */ VARIANT __RPC_FAR *lpvarCpuName,
            /* [out] */ VARIANT __RPC_FAR *lpvarCpuType,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetCpuStatus )( 
            IActMLLLT3 __RPC_FAR * This,
            /* [in] */ VARIANT varOperation,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetClockData )( 
            IActMLLLT3 __RPC_FAR * This,
            /* [out] */ VARIANT __RPC_FAR *lpvarYear,
            /* [out] */ VARIANT __RPC_FAR *lpvarMonth,
            /* [out] */ VARIANT __RPC_FAR *lpvarDay,
            /* [out] */ VARIANT __RPC_FAR *lpvarDayOfWeek,
            /* [out] */ VARIANT __RPC_FAR *lpvarHour,
            /* [out] */ VARIANT __RPC_FAR *lpvarMinute,
            /* [out] */ VARIANT __RPC_FAR *lpvarSecond,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetClockData )( 
            IActMLLLT3 __RPC_FAR * This,
            /* [in] */ VARIANT varYear,
            /* [in] */ VARIANT varMonth,
            /* [in] */ VARIANT varDay,
            /* [in] */ VARIANT varDayOfWeek,
            /* [in] */ VARIANT varHour,
            /* [in] */ VARIANT varMinute,
            /* [in] */ VARIANT varSecond,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *EntryDeviceStatus )( 
            IActMLLLT3 __RPC_FAR * This,
            /* [in] */ VARIANT varDeviceList,
            /* [in] */ VARIANT varSize,
            /* [in] */ VARIANT varMonitorCycle,
            /* [in] */ VARIANT varData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActCpuType )( 
            IActMLLLT3 __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActCpuType )( 
            IActMLLLT3 __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActTimeOut )( 
            IActMLLLT3 __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActTimeOut )( 
            IActMLLLT3 __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *FreeDeviceStatus )( 
            IActMLLLT3 __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceBlock2 )( 
            IActMLLLT3 __RPC_FAR * This,
            /* [in] */ VARIANT varDevice,
            /* [in] */ VARIANT varSize,
            /* [out] */ VARIANT __RPC_FAR *lpvarData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceBlock2 )( 
            IActMLLLT3 __RPC_FAR * This,
            /* [in] */ VARIANT varDevice,
            /* [in] */ VARIANT varSize,
            /* [in] */ VARIANT varData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceRandom2 )( 
            IActMLLLT3 __RPC_FAR * This,
            /* [in] */ VARIANT varDeviceList,
            /* [in] */ VARIANT varSize,
            /* [out] */ VARIANT __RPC_FAR *lpvarData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceRandom2 )( 
            IActMLLLT3 __RPC_FAR * This,
            /* [in] */ VARIANT varDeviceList,
            /* [in] */ VARIANT varSize,
            /* [in] */ VARIANT varData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetDevice2 )( 
            IActMLLLT3 __RPC_FAR * This,
            /* [in] */ VARIANT varDevice,
            /* [out] */ VARIANT __RPC_FAR *lpvarData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetDevice2 )( 
            IActMLLLT3 __RPC_FAR * This,
            /* [in] */ VARIANT varDevice,
            /* [in] */ VARIANT varData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActNetworkNumber )( 
            IActMLLLT3 __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActNetworkNumber )( 
            IActMLLLT3 __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActStationNumber )( 
            IActMLLLT3 __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActStationNumber )( 
            IActMLLLT3 __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        END_INTERFACE
    } IActMLLLT3Vtbl;

    interface IActMLLLT3
    {
        CONST_VTBL struct IActMLLLT3Vtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IActMLLLT3_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IActMLLLT3_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IActMLLLT3_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IActMLLLT3_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IActMLLLT3_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IActMLLLT3_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IActMLLLT3_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IActMLLLT3_Open(This,lpvarReturnCode)	\
    (This)->lpVtbl -> Open(This,lpvarReturnCode)

#define IActMLLLT3_Close(This,lpvarReturnCode)	\
    (This)->lpVtbl -> Close(This,lpvarReturnCode)

#define IActMLLLT3_GetDevice(This,varDevice,lpvarData,lpvarReturnCode)	\
    (This)->lpVtbl -> GetDevice(This,varDevice,lpvarData,lpvarReturnCode)

#define IActMLLLT3_SetDevice(This,varDevice,varData,lpvarReturnCode)	\
    (This)->lpVtbl -> SetDevice(This,varDevice,varData,lpvarReturnCode)

#define IActMLLLT3_ReadDeviceBlock(This,varDevice,varSize,lpvarData,lpvarReturnCode)	\
    (This)->lpVtbl -> ReadDeviceBlock(This,varDevice,varSize,lpvarData,lpvarReturnCode)

#define IActMLLLT3_WriteDeviceBlock(This,varDevice,varSize,varData,lpvarReturnCode)	\
    (This)->lpVtbl -> WriteDeviceBlock(This,varDevice,varSize,varData,lpvarReturnCode)

#define IActMLLLT3_ReadDeviceRandom(This,varDeviceList,varSize,lpvarData,lpvarReturnCode)	\
    (This)->lpVtbl -> ReadDeviceRandom(This,varDeviceList,varSize,lpvarData,lpvarReturnCode)

#define IActMLLLT3_WriteDeviceRandom(This,varDeviceList,varSize,varData,lpvarReturnCode)	\
    (This)->lpVtbl -> WriteDeviceRandom(This,varDeviceList,varSize,varData,lpvarReturnCode)

#define IActMLLLT3_ReadBuffer(This,varStartIO,varAddress,varReadSize,lpvarData,lpvarReturnCode)	\
    (This)->lpVtbl -> ReadBuffer(This,varStartIO,varAddress,varReadSize,lpvarData,lpvarReturnCode)

#define IActMLLLT3_WriteBuffer(This,varStartIO,varAddress,varWriteSize,varData,lpvarReturnCode)	\
    (This)->lpVtbl -> WriteBuffer(This,varStartIO,varAddress,varWriteSize,varData,lpvarReturnCode)

#define IActMLLLT3_GetCpuType(This,lpvarCpuName,lpvarCpuType,lpvarReturnCode)	\
    (This)->lpVtbl -> GetCpuType(This,lpvarCpuName,lpvarCpuType,lpvarReturnCode)

#define IActMLLLT3_SetCpuStatus(This,varOperation,lpvarReturnCode)	\
    (This)->lpVtbl -> SetCpuStatus(This,varOperation,lpvarReturnCode)

#define IActMLLLT3_GetClockData(This,lpvarYear,lpvarMonth,lpvarDay,lpvarDayOfWeek,lpvarHour,lpvarMinute,lpvarSecond,lpvarReturnCode)	\
    (This)->lpVtbl -> GetClockData(This,lpvarYear,lpvarMonth,lpvarDay,lpvarDayOfWeek,lpvarHour,lpvarMinute,lpvarSecond,lpvarReturnCode)

#define IActMLLLT3_SetClockData(This,varYear,varMonth,varDay,varDayOfWeek,varHour,varMinute,varSecond,lpvarReturnCode)	\
    (This)->lpVtbl -> SetClockData(This,varYear,varMonth,varDay,varDayOfWeek,varHour,varMinute,varSecond,lpvarReturnCode)

#define IActMLLLT3_EntryDeviceStatus(This,varDeviceList,varSize,varMonitorCycle,varData,lpvarReturnCode)	\
    (This)->lpVtbl -> EntryDeviceStatus(This,varDeviceList,varSize,varMonitorCycle,varData,lpvarReturnCode)

#define IActMLLLT3_get_ActCpuType(This,pVal)	\
    (This)->lpVtbl -> get_ActCpuType(This,pVal)

#define IActMLLLT3_put_ActCpuType(This,newVal)	\
    (This)->lpVtbl -> put_ActCpuType(This,newVal)

#define IActMLLLT3_get_ActTimeOut(This,pVal)	\
    (This)->lpVtbl -> get_ActTimeOut(This,pVal)

#define IActMLLLT3_put_ActTimeOut(This,newVal)	\
    (This)->lpVtbl -> put_ActTimeOut(This,newVal)

#define IActMLLLT3_FreeDeviceStatus(This,lpvarReturnCode)	\
    (This)->lpVtbl -> FreeDeviceStatus(This,lpvarReturnCode)



#define IActMLLLT3_ReadDeviceBlock2(This,varDevice,varSize,lpvarData,lpvarReturnCode)	\
    (This)->lpVtbl -> ReadDeviceBlock2(This,varDevice,varSize,lpvarData,lpvarReturnCode)

#define IActMLLLT3_WriteDeviceBlock2(This,varDevice,varSize,varData,lpvarReturnCode)	\
    (This)->lpVtbl -> WriteDeviceBlock2(This,varDevice,varSize,varData,lpvarReturnCode)

#define IActMLLLT3_ReadDeviceRandom2(This,varDeviceList,varSize,lpvarData,lpvarReturnCode)	\
    (This)->lpVtbl -> ReadDeviceRandom2(This,varDeviceList,varSize,lpvarData,lpvarReturnCode)

#define IActMLLLT3_WriteDeviceRandom2(This,varDeviceList,varSize,varData,lpvarReturnCode)	\
    (This)->lpVtbl -> WriteDeviceRandom2(This,varDeviceList,varSize,varData,lpvarReturnCode)

#define IActMLLLT3_GetDevice2(This,varDevice,lpvarData,lpvarReturnCode)	\
    (This)->lpVtbl -> GetDevice2(This,varDevice,lpvarData,lpvarReturnCode)

#define IActMLLLT3_SetDevice2(This,varDevice,varData,lpvarReturnCode)	\
    (This)->lpVtbl -> SetDevice2(This,varDevice,varData,lpvarReturnCode)

#define IActMLLLT3_get_ActNetworkNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActNetworkNumber(This,pVal)

#define IActMLLLT3_put_ActNetworkNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActNetworkNumber(This,newVal)

#define IActMLLLT3_get_ActStationNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActStationNumber(This,pVal)

#define IActMLLLT3_put_ActStationNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActStationNumber(This,newVal)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActMLLLT3_ReadDeviceBlock2_Proxy( 
    IActMLLLT3 __RPC_FAR * This,
    /* [in] */ VARIANT varDevice,
    /* [in] */ VARIANT varSize,
    /* [out] */ VARIANT __RPC_FAR *lpvarData,
    /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);


void __RPC_STUB IActMLLLT3_ReadDeviceBlock2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActMLLLT3_WriteDeviceBlock2_Proxy( 
    IActMLLLT3 __RPC_FAR * This,
    /* [in] */ VARIANT varDevice,
    /* [in] */ VARIANT varSize,
    /* [in] */ VARIANT varData,
    /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);


void __RPC_STUB IActMLLLT3_WriteDeviceBlock2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActMLLLT3_ReadDeviceRandom2_Proxy( 
    IActMLLLT3 __RPC_FAR * This,
    /* [in] */ VARIANT varDeviceList,
    /* [in] */ VARIANT varSize,
    /* [out] */ VARIANT __RPC_FAR *lpvarData,
    /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);


void __RPC_STUB IActMLLLT3_ReadDeviceRandom2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActMLLLT3_WriteDeviceRandom2_Proxy( 
    IActMLLLT3 __RPC_FAR * This,
    /* [in] */ VARIANT varDeviceList,
    /* [in] */ VARIANT varSize,
    /* [in] */ VARIANT varData,
    /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);


void __RPC_STUB IActMLLLT3_WriteDeviceRandom2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActMLLLT3_GetDevice2_Proxy( 
    IActMLLLT3 __RPC_FAR * This,
    /* [in] */ VARIANT varDevice,
    /* [out] */ VARIANT __RPC_FAR *lpvarData,
    /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);


void __RPC_STUB IActMLLLT3_GetDevice2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActMLLLT3_SetDevice2_Proxy( 
    IActMLLLT3 __RPC_FAR * This,
    /* [in] */ VARIANT varDevice,
    /* [in] */ VARIANT varData,
    /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);


void __RPC_STUB IActMLLLT3_SetDevice2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActMLLLT3_get_ActNetworkNumber_Proxy( 
    IActMLLLT3 __RPC_FAR * This,
    /* [retval][out] */ VARIANT __RPC_FAR *pVal);


void __RPC_STUB IActMLLLT3_get_ActNetworkNumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActMLLLT3_put_ActNetworkNumber_Proxy( 
    IActMLLLT3 __RPC_FAR * This,
    /* [in] */ VARIANT newVal);


void __RPC_STUB IActMLLLT3_put_ActNetworkNumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActMLLLT3_get_ActStationNumber_Proxy( 
    IActMLLLT3 __RPC_FAR * This,
    /* [retval][out] */ VARIANT __RPC_FAR *pVal);


void __RPC_STUB IActMLLLT3_get_ActStationNumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActMLLLT3_put_ActStationNumber_Proxy( 
    IActMLLLT3 __RPC_FAR * This,
    /* [in] */ VARIANT newVal);


void __RPC_STUB IActMLLLT3_put_ActStationNumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IActMLLLT3_INTERFACE_DEFINED__ */


#ifndef __IActSIM_INTERFACE_DEFINED__
#define __IActSIM_INTERFACE_DEFINED__

/* interface IActSIM */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IActSIM;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("E43A5066-E58F-4F29-BA6B-495D5A611046")
    IActSIM : public IDispatch
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
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActTargetSimulator( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActTargetSimulator( 
            /* [in] */ long newVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IActSIMVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IActSIM __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IActSIM __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IActSIM __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IActSIM __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IActSIM __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IActSIM __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IActSIM __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Open )( 
            IActSIM __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Close )( 
            IActSIM __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetDevice )( 
            IActSIM __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [out] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetDevice )( 
            IActSIM __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceBlock )( 
            IActSIM __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lSize,
            /* [size_is][out] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceBlock )( 
            IActSIM __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lSize,
            /* [size_is][in] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceRandom )( 
            IActSIM __RPC_FAR * This,
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG lSize,
            /* [size_is][out] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceRandom )( 
            IActSIM __RPC_FAR * This,
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG lSize,
            /* [size_is][in] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadBuffer )( 
            IActSIM __RPC_FAR * This,
            /* [in] */ LONG lStartIO,
            /* [in] */ LONG lAddress,
            /* [in] */ LONG lReadSize,
            /* [size_is][out] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteBuffer )( 
            IActSIM __RPC_FAR * This,
            /* [in] */ LONG lStartIO,
            /* [in] */ LONG lAddress,
            /* [in] */ LONG lWriteSize,
            /* [size_is][in] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetCpuType )( 
            IActSIM __RPC_FAR * This,
            /* [string][out] */ BSTR __RPC_FAR *szCpuName,
            /* [out] */ LONG __RPC_FAR *lplCpuCode,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetCpuStatus )( 
            IActSIM __RPC_FAR * This,
            /* [in] */ LONG lOperation,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetClockData )( 
            IActSIM __RPC_FAR * This,
            /* [out] */ SHORT __RPC_FAR *lpsYear,
            /* [out] */ SHORT __RPC_FAR *lpsMonth,
            /* [out] */ SHORT __RPC_FAR *lpsDay,
            /* [out] */ SHORT __RPC_FAR *lpsDayOfWeek,
            /* [out] */ SHORT __RPC_FAR *lpsHour,
            /* [out] */ SHORT __RPC_FAR *lpsMinute,
            /* [out] */ SHORT __RPC_FAR *lpsSecond,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *EntryDeviceStatus )( 
            IActSIM __RPC_FAR * This,
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG lSize,
            /* [in] */ LONG lMonitorCycle,
            /* [size_is][in] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CheckDeviceString )( 
            IActSIM __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lCheckType,
            /* [in] */ LONG lSize,
            /* [out] */ LONG __RPC_FAR *lplDeviceType,
            /* [string][out] */ BSTR __RPC_FAR *lpszDeviceName,
            /* [out] */ LONG __RPC_FAR *lplDeviceNumber,
            /* [out] */ LONG __RPC_FAR *lplDeviceRadix,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *FreeDeviceStatus )( 
            IActSIM __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceBlock2 )( 
            IActSIM __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lSize,
            /* [size_is][out] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceBlock2 )( 
            IActSIM __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lSize,
            /* [size_is][in] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceRandom2 )( 
            IActSIM __RPC_FAR * This,
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG lSize,
            /* [size_is][out] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceRandom2 )( 
            IActSIM __RPC_FAR * This,
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG lSize,
            /* [size_is][in] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetDevice2 )( 
            IActSIM __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [out] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetDevice2 )( 
            IActSIM __RPC_FAR * This,
            /* [in] */ BSTR szDevice,
            /* [in] */ SHORT sData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActTargetSimulator )( 
            IActSIM __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActTargetSimulator )( 
            IActSIM __RPC_FAR * This,
            /* [in] */ long newVal);
        
        END_INTERFACE
    } IActSIMVtbl;

    interface IActSIM
    {
        CONST_VTBL struct IActSIMVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IActSIM_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IActSIM_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IActSIM_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IActSIM_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IActSIM_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IActSIM_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IActSIM_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IActSIM_Open(This,lplReturnCode)	\
    (This)->lpVtbl -> Open(This,lplReturnCode)

#define IActSIM_Close(This,lplReturnCode)	\
    (This)->lpVtbl -> Close(This,lplReturnCode)

#define IActSIM_GetDevice(This,szDevice,lplData,lplReturnCode)	\
    (This)->lpVtbl -> GetDevice(This,szDevice,lplData,lplReturnCode)

#define IActSIM_SetDevice(This,szDevice,lData,lplReturnCode)	\
    (This)->lpVtbl -> SetDevice(This,szDevice,lData,lplReturnCode)

#define IActSIM_ReadDeviceBlock(This,szDevice,lSize,lplData,lplReturnCode)	\
    (This)->lpVtbl -> ReadDeviceBlock(This,szDevice,lSize,lplData,lplReturnCode)

#define IActSIM_WriteDeviceBlock(This,szDevice,lSize,lplData,lplReturnCode)	\
    (This)->lpVtbl -> WriteDeviceBlock(This,szDevice,lSize,lplData,lplReturnCode)

#define IActSIM_ReadDeviceRandom(This,szDeviceList,lSize,lplData,lplReturnCode)	\
    (This)->lpVtbl -> ReadDeviceRandom(This,szDeviceList,lSize,lplData,lplReturnCode)

#define IActSIM_WriteDeviceRandom(This,szDeviceList,lSize,lplData,lplReturnCode)	\
    (This)->lpVtbl -> WriteDeviceRandom(This,szDeviceList,lSize,lplData,lplReturnCode)

#define IActSIM_ReadBuffer(This,lStartIO,lAddress,lReadSize,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> ReadBuffer(This,lStartIO,lAddress,lReadSize,lpsData,lplReturnCode)

#define IActSIM_WriteBuffer(This,lStartIO,lAddress,lWriteSize,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> WriteBuffer(This,lStartIO,lAddress,lWriteSize,lpsData,lplReturnCode)

#define IActSIM_GetCpuType(This,szCpuName,lplCpuCode,lplReturnCode)	\
    (This)->lpVtbl -> GetCpuType(This,szCpuName,lplCpuCode,lplReturnCode)

#define IActSIM_SetCpuStatus(This,lOperation,lplReturnCode)	\
    (This)->lpVtbl -> SetCpuStatus(This,lOperation,lplReturnCode)

#define IActSIM_GetClockData(This,lpsYear,lpsMonth,lpsDay,lpsDayOfWeek,lpsHour,lpsMinute,lpsSecond,lplReturnCode)	\
    (This)->lpVtbl -> GetClockData(This,lpsYear,lpsMonth,lpsDay,lpsDayOfWeek,lpsHour,lpsMinute,lpsSecond,lplReturnCode)

#define IActSIM_EntryDeviceStatus(This,szDeviceList,lSize,lMonitorCycle,lplData,lplReturnCode)	\
    (This)->lpVtbl -> EntryDeviceStatus(This,szDeviceList,lSize,lMonitorCycle,lplData,lplReturnCode)

#define IActSIM_CheckDeviceString(This,szDevice,lCheckType,lSize,lplDeviceType,lpszDeviceName,lplDeviceNumber,lplDeviceRadix,lplReturnCode)	\
    (This)->lpVtbl -> CheckDeviceString(This,szDevice,lCheckType,lSize,lplDeviceType,lpszDeviceName,lplDeviceNumber,lplDeviceRadix,lplReturnCode)

#define IActSIM_FreeDeviceStatus(This,lplReturnCode)	\
    (This)->lpVtbl -> FreeDeviceStatus(This,lplReturnCode)

#define IActSIM_ReadDeviceBlock2(This,szDevice,lSize,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> ReadDeviceBlock2(This,szDevice,lSize,lpsData,lplReturnCode)

#define IActSIM_WriteDeviceBlock2(This,szDevice,lSize,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> WriteDeviceBlock2(This,szDevice,lSize,lpsData,lplReturnCode)

#define IActSIM_ReadDeviceRandom2(This,szDeviceList,lSize,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> ReadDeviceRandom2(This,szDeviceList,lSize,lpsData,lplReturnCode)

#define IActSIM_WriteDeviceRandom2(This,szDeviceList,lSize,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> WriteDeviceRandom2(This,szDeviceList,lSize,lpsData,lplReturnCode)

#define IActSIM_GetDevice2(This,szDevice,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> GetDevice2(This,szDevice,lpsData,lplReturnCode)

#define IActSIM_SetDevice2(This,szDevice,sData,lplReturnCode)	\
    (This)->lpVtbl -> SetDevice2(This,szDevice,sData,lplReturnCode)

#define IActSIM_get_ActTargetSimulator(This,pVal)	\
    (This)->lpVtbl -> get_ActTargetSimulator(This,pVal)

#define IActSIM_put_ActTargetSimulator(This,newVal)	\
    (This)->lpVtbl -> put_ActTargetSimulator(This,newVal)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActSIM_Open_Proxy( 
    IActSIM __RPC_FAR * This,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActSIM_Open_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActSIM_Close_Proxy( 
    IActSIM __RPC_FAR * This,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActSIM_Close_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActSIM_GetDevice_Proxy( 
    IActSIM __RPC_FAR * This,
    /* [string][in] */ BSTR szDevice,
    /* [out] */ LONG __RPC_FAR *lplData,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActSIM_GetDevice_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActSIM_SetDevice_Proxy( 
    IActSIM __RPC_FAR * This,
    /* [string][in] */ BSTR szDevice,
    /* [in] */ LONG lData,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActSIM_SetDevice_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActSIM_ReadDeviceBlock_Proxy( 
    IActSIM __RPC_FAR * This,
    /* [string][in] */ BSTR szDevice,
    /* [in] */ LONG lSize,
    /* [size_is][out] */ LONG __RPC_FAR *lplData,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActSIM_ReadDeviceBlock_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActSIM_WriteDeviceBlock_Proxy( 
    IActSIM __RPC_FAR * This,
    /* [string][in] */ BSTR szDevice,
    /* [in] */ LONG lSize,
    /* [size_is][in] */ LONG __RPC_FAR *lplData,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActSIM_WriteDeviceBlock_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActSIM_ReadDeviceRandom_Proxy( 
    IActSIM __RPC_FAR * This,
    /* [string][in] */ BSTR szDeviceList,
    /* [in] */ LONG lSize,
    /* [size_is][out] */ LONG __RPC_FAR *lplData,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActSIM_ReadDeviceRandom_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActSIM_WriteDeviceRandom_Proxy( 
    IActSIM __RPC_FAR * This,
    /* [string][in] */ BSTR szDeviceList,
    /* [in] */ LONG lSize,
    /* [size_is][in] */ LONG __RPC_FAR *lplData,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActSIM_WriteDeviceRandom_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActSIM_ReadBuffer_Proxy( 
    IActSIM __RPC_FAR * This,
    /* [in] */ LONG lStartIO,
    /* [in] */ LONG lAddress,
    /* [in] */ LONG lReadSize,
    /* [size_is][out] */ SHORT __RPC_FAR *lpsData,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActSIM_ReadBuffer_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActSIM_WriteBuffer_Proxy( 
    IActSIM __RPC_FAR * This,
    /* [in] */ LONG lStartIO,
    /* [in] */ LONG lAddress,
    /* [in] */ LONG lWriteSize,
    /* [size_is][in] */ SHORT __RPC_FAR *lpsData,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActSIM_WriteBuffer_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActSIM_GetCpuType_Proxy( 
    IActSIM __RPC_FAR * This,
    /* [string][out] */ BSTR __RPC_FAR *szCpuName,
    /* [out] */ LONG __RPC_FAR *lplCpuCode,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActSIM_GetCpuType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActSIM_SetCpuStatus_Proxy( 
    IActSIM __RPC_FAR * This,
    /* [in] */ LONG lOperation,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActSIM_SetCpuStatus_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActSIM_GetClockData_Proxy( 
    IActSIM __RPC_FAR * This,
    /* [out] */ SHORT __RPC_FAR *lpsYear,
    /* [out] */ SHORT __RPC_FAR *lpsMonth,
    /* [out] */ SHORT __RPC_FAR *lpsDay,
    /* [out] */ SHORT __RPC_FAR *lpsDayOfWeek,
    /* [out] */ SHORT __RPC_FAR *lpsHour,
    /* [out] */ SHORT __RPC_FAR *lpsMinute,
    /* [out] */ SHORT __RPC_FAR *lpsSecond,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActSIM_GetClockData_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActSIM_EntryDeviceStatus_Proxy( 
    IActSIM __RPC_FAR * This,
    /* [string][in] */ BSTR szDeviceList,
    /* [in] */ LONG lSize,
    /* [in] */ LONG lMonitorCycle,
    /* [size_is][in] */ LONG __RPC_FAR *lplData,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActSIM_EntryDeviceStatus_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActSIM_CheckDeviceString_Proxy( 
    IActSIM __RPC_FAR * This,
    /* [string][in] */ BSTR szDevice,
    /* [in] */ LONG lCheckType,
    /* [in] */ LONG lSize,
    /* [out] */ LONG __RPC_FAR *lplDeviceType,
    /* [string][out] */ BSTR __RPC_FAR *lpszDeviceName,
    /* [out] */ LONG __RPC_FAR *lplDeviceNumber,
    /* [out] */ LONG __RPC_FAR *lplDeviceRadix,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActSIM_CheckDeviceString_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActSIM_FreeDeviceStatus_Proxy( 
    IActSIM __RPC_FAR * This,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActSIM_FreeDeviceStatus_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActSIM_ReadDeviceBlock2_Proxy( 
    IActSIM __RPC_FAR * This,
    /* [string][in] */ BSTR szDevice,
    /* [in] */ LONG lSize,
    /* [size_is][out] */ SHORT __RPC_FAR *lpsData,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActSIM_ReadDeviceBlock2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActSIM_WriteDeviceBlock2_Proxy( 
    IActSIM __RPC_FAR * This,
    /* [string][in] */ BSTR szDevice,
    /* [in] */ LONG lSize,
    /* [size_is][in] */ SHORT __RPC_FAR *lpsData,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActSIM_WriteDeviceBlock2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActSIM_ReadDeviceRandom2_Proxy( 
    IActSIM __RPC_FAR * This,
    /* [string][in] */ BSTR szDeviceList,
    /* [in] */ LONG lSize,
    /* [size_is][out] */ SHORT __RPC_FAR *lpsData,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActSIM_ReadDeviceRandom2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActSIM_WriteDeviceRandom2_Proxy( 
    IActSIM __RPC_FAR * This,
    /* [string][in] */ BSTR szDeviceList,
    /* [in] */ LONG lSize,
    /* [size_is][in] */ SHORT __RPC_FAR *lpsData,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActSIM_WriteDeviceRandom2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActSIM_GetDevice2_Proxy( 
    IActSIM __RPC_FAR * This,
    /* [string][in] */ BSTR szDevice,
    /* [out] */ SHORT __RPC_FAR *lpsData,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActSIM_GetDevice2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActSIM_SetDevice2_Proxy( 
    IActSIM __RPC_FAR * This,
    /* [in] */ BSTR szDevice,
    /* [in] */ SHORT sData,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActSIM_SetDevice2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActSIM_get_ActTargetSimulator_Proxy( 
    IActSIM __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IActSIM_get_ActTargetSimulator_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActSIM_put_ActTargetSimulator_Proxy( 
    IActSIM __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB IActSIM_put_ActTargetSimulator_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IActSIM_INTERFACE_DEFINED__ */


#ifndef __IActSIM2_INTERFACE_DEFINED__
#define __IActSIM2_INTERFACE_DEFINED__

/* interface IActSIM2 */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IActSIM2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("E73F293F-896C-49db-ACB1-E49BDE35AE19")
    IActSIM2 : public IActSIM
    {
    public:
    };
    
#else 	/* C style interface */

    typedef struct IActSIM2Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IActSIM2 __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IActSIM2 __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IActSIM2 __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IActSIM2 __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IActSIM2 __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IActSIM2 __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IActSIM2 __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Open )( 
            IActSIM2 __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Close )( 
            IActSIM2 __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetDevice )( 
            IActSIM2 __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [out] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetDevice )( 
            IActSIM2 __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceBlock )( 
            IActSIM2 __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lSize,
            /* [size_is][out] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceBlock )( 
            IActSIM2 __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lSize,
            /* [size_is][in] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceRandom )( 
            IActSIM2 __RPC_FAR * This,
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG lSize,
            /* [size_is][out] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceRandom )( 
            IActSIM2 __RPC_FAR * This,
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG lSize,
            /* [size_is][in] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadBuffer )( 
            IActSIM2 __RPC_FAR * This,
            /* [in] */ LONG lStartIO,
            /* [in] */ LONG lAddress,
            /* [in] */ LONG lReadSize,
            /* [size_is][out] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteBuffer )( 
            IActSIM2 __RPC_FAR * This,
            /* [in] */ LONG lStartIO,
            /* [in] */ LONG lAddress,
            /* [in] */ LONG lWriteSize,
            /* [size_is][in] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetCpuType )( 
            IActSIM2 __RPC_FAR * This,
            /* [string][out] */ BSTR __RPC_FAR *szCpuName,
            /* [out] */ LONG __RPC_FAR *lplCpuCode,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetCpuStatus )( 
            IActSIM2 __RPC_FAR * This,
            /* [in] */ LONG lOperation,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetClockData )( 
            IActSIM2 __RPC_FAR * This,
            /* [out] */ SHORT __RPC_FAR *lpsYear,
            /* [out] */ SHORT __RPC_FAR *lpsMonth,
            /* [out] */ SHORT __RPC_FAR *lpsDay,
            /* [out] */ SHORT __RPC_FAR *lpsDayOfWeek,
            /* [out] */ SHORT __RPC_FAR *lpsHour,
            /* [out] */ SHORT __RPC_FAR *lpsMinute,
            /* [out] */ SHORT __RPC_FAR *lpsSecond,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *EntryDeviceStatus )( 
            IActSIM2 __RPC_FAR * This,
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG lSize,
            /* [in] */ LONG lMonitorCycle,
            /* [size_is][in] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CheckDeviceString )( 
            IActSIM2 __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lCheckType,
            /* [in] */ LONG lSize,
            /* [out] */ LONG __RPC_FAR *lplDeviceType,
            /* [string][out] */ BSTR __RPC_FAR *lpszDeviceName,
            /* [out] */ LONG __RPC_FAR *lplDeviceNumber,
            /* [out] */ LONG __RPC_FAR *lplDeviceRadix,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *FreeDeviceStatus )( 
            IActSIM2 __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceBlock2 )( 
            IActSIM2 __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lSize,
            /* [size_is][out] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceBlock2 )( 
            IActSIM2 __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lSize,
            /* [size_is][in] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceRandom2 )( 
            IActSIM2 __RPC_FAR * This,
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG lSize,
            /* [size_is][out] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceRandom2 )( 
            IActSIM2 __RPC_FAR * This,
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG lSize,
            /* [size_is][in] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetDevice2 )( 
            IActSIM2 __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [out] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetDevice2 )( 
            IActSIM2 __RPC_FAR * This,
            /* [in] */ BSTR szDevice,
            /* [in] */ SHORT sData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActTargetSimulator )( 
            IActSIM2 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActTargetSimulator )( 
            IActSIM2 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        END_INTERFACE
    } IActSIM2Vtbl;

    interface IActSIM2
    {
        CONST_VTBL struct IActSIM2Vtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IActSIM2_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IActSIM2_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IActSIM2_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IActSIM2_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IActSIM2_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IActSIM2_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IActSIM2_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IActSIM2_Open(This,lplReturnCode)	\
    (This)->lpVtbl -> Open(This,lplReturnCode)

#define IActSIM2_Close(This,lplReturnCode)	\
    (This)->lpVtbl -> Close(This,lplReturnCode)

#define IActSIM2_GetDevice(This,szDevice,lplData,lplReturnCode)	\
    (This)->lpVtbl -> GetDevice(This,szDevice,lplData,lplReturnCode)

#define IActSIM2_SetDevice(This,szDevice,lData,lplReturnCode)	\
    (This)->lpVtbl -> SetDevice(This,szDevice,lData,lplReturnCode)

#define IActSIM2_ReadDeviceBlock(This,szDevice,lSize,lplData,lplReturnCode)	\
    (This)->lpVtbl -> ReadDeviceBlock(This,szDevice,lSize,lplData,lplReturnCode)

#define IActSIM2_WriteDeviceBlock(This,szDevice,lSize,lplData,lplReturnCode)	\
    (This)->lpVtbl -> WriteDeviceBlock(This,szDevice,lSize,lplData,lplReturnCode)

#define IActSIM2_ReadDeviceRandom(This,szDeviceList,lSize,lplData,lplReturnCode)	\
    (This)->lpVtbl -> ReadDeviceRandom(This,szDeviceList,lSize,lplData,lplReturnCode)

#define IActSIM2_WriteDeviceRandom(This,szDeviceList,lSize,lplData,lplReturnCode)	\
    (This)->lpVtbl -> WriteDeviceRandom(This,szDeviceList,lSize,lplData,lplReturnCode)

#define IActSIM2_ReadBuffer(This,lStartIO,lAddress,lReadSize,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> ReadBuffer(This,lStartIO,lAddress,lReadSize,lpsData,lplReturnCode)

#define IActSIM2_WriteBuffer(This,lStartIO,lAddress,lWriteSize,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> WriteBuffer(This,lStartIO,lAddress,lWriteSize,lpsData,lplReturnCode)

#define IActSIM2_GetCpuType(This,szCpuName,lplCpuCode,lplReturnCode)	\
    (This)->lpVtbl -> GetCpuType(This,szCpuName,lplCpuCode,lplReturnCode)

#define IActSIM2_SetCpuStatus(This,lOperation,lplReturnCode)	\
    (This)->lpVtbl -> SetCpuStatus(This,lOperation,lplReturnCode)

#define IActSIM2_GetClockData(This,lpsYear,lpsMonth,lpsDay,lpsDayOfWeek,lpsHour,lpsMinute,lpsSecond,lplReturnCode)	\
    (This)->lpVtbl -> GetClockData(This,lpsYear,lpsMonth,lpsDay,lpsDayOfWeek,lpsHour,lpsMinute,lpsSecond,lplReturnCode)

#define IActSIM2_EntryDeviceStatus(This,szDeviceList,lSize,lMonitorCycle,lplData,lplReturnCode)	\
    (This)->lpVtbl -> EntryDeviceStatus(This,szDeviceList,lSize,lMonitorCycle,lplData,lplReturnCode)

#define IActSIM2_CheckDeviceString(This,szDevice,lCheckType,lSize,lplDeviceType,lpszDeviceName,lplDeviceNumber,lplDeviceRadix,lplReturnCode)	\
    (This)->lpVtbl -> CheckDeviceString(This,szDevice,lCheckType,lSize,lplDeviceType,lpszDeviceName,lplDeviceNumber,lplDeviceRadix,lplReturnCode)

#define IActSIM2_FreeDeviceStatus(This,lplReturnCode)	\
    (This)->lpVtbl -> FreeDeviceStatus(This,lplReturnCode)

#define IActSIM2_ReadDeviceBlock2(This,szDevice,lSize,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> ReadDeviceBlock2(This,szDevice,lSize,lpsData,lplReturnCode)

#define IActSIM2_WriteDeviceBlock2(This,szDevice,lSize,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> WriteDeviceBlock2(This,szDevice,lSize,lpsData,lplReturnCode)

#define IActSIM2_ReadDeviceRandom2(This,szDeviceList,lSize,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> ReadDeviceRandom2(This,szDeviceList,lSize,lpsData,lplReturnCode)

#define IActSIM2_WriteDeviceRandom2(This,szDeviceList,lSize,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> WriteDeviceRandom2(This,szDeviceList,lSize,lpsData,lplReturnCode)

#define IActSIM2_GetDevice2(This,szDevice,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> GetDevice2(This,szDevice,lpsData,lplReturnCode)

#define IActSIM2_SetDevice2(This,szDevice,sData,lplReturnCode)	\
    (This)->lpVtbl -> SetDevice2(This,szDevice,sData,lplReturnCode)

#define IActSIM2_get_ActTargetSimulator(This,pVal)	\
    (This)->lpVtbl -> get_ActTargetSimulator(This,pVal)

#define IActSIM2_put_ActTargetSimulator(This,newVal)	\
    (This)->lpVtbl -> put_ActTargetSimulator(This,newVal)


#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IActSIM2_INTERFACE_DEFINED__ */


#ifndef __IActSIM3_INTERFACE_DEFINED__
#define __IActSIM3_INTERFACE_DEFINED__

/* interface IActSIM3 */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IActSIM3;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("E222BE18-F1EF-4572-873C-8A6DA73322D1")
    IActSIM3 : public IActSIM2
    {
    public:
    };
    
#else 	/* C style interface */

    typedef struct IActSIM3Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IActSIM3 __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IActSIM3 __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IActSIM3 __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IActSIM3 __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IActSIM3 __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IActSIM3 __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IActSIM3 __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Open )( 
            IActSIM3 __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Close )( 
            IActSIM3 __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetDevice )( 
            IActSIM3 __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [out] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetDevice )( 
            IActSIM3 __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceBlock )( 
            IActSIM3 __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lSize,
            /* [size_is][out] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceBlock )( 
            IActSIM3 __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lSize,
            /* [size_is][in] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceRandom )( 
            IActSIM3 __RPC_FAR * This,
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG lSize,
            /* [size_is][out] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceRandom )( 
            IActSIM3 __RPC_FAR * This,
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG lSize,
            /* [size_is][in] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadBuffer )( 
            IActSIM3 __RPC_FAR * This,
            /* [in] */ LONG lStartIO,
            /* [in] */ LONG lAddress,
            /* [in] */ LONG lReadSize,
            /* [size_is][out] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteBuffer )( 
            IActSIM3 __RPC_FAR * This,
            /* [in] */ LONG lStartIO,
            /* [in] */ LONG lAddress,
            /* [in] */ LONG lWriteSize,
            /* [size_is][in] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetCpuType )( 
            IActSIM3 __RPC_FAR * This,
            /* [string][out] */ BSTR __RPC_FAR *szCpuName,
            /* [out] */ LONG __RPC_FAR *lplCpuCode,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetCpuStatus )( 
            IActSIM3 __RPC_FAR * This,
            /* [in] */ LONG lOperation,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetClockData )( 
            IActSIM3 __RPC_FAR * This,
            /* [out] */ SHORT __RPC_FAR *lpsYear,
            /* [out] */ SHORT __RPC_FAR *lpsMonth,
            /* [out] */ SHORT __RPC_FAR *lpsDay,
            /* [out] */ SHORT __RPC_FAR *lpsDayOfWeek,
            /* [out] */ SHORT __RPC_FAR *lpsHour,
            /* [out] */ SHORT __RPC_FAR *lpsMinute,
            /* [out] */ SHORT __RPC_FAR *lpsSecond,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *EntryDeviceStatus )( 
            IActSIM3 __RPC_FAR * This,
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG lSize,
            /* [in] */ LONG lMonitorCycle,
            /* [size_is][in] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CheckDeviceString )( 
            IActSIM3 __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lCheckType,
            /* [in] */ LONG lSize,
            /* [out] */ LONG __RPC_FAR *lplDeviceType,
            /* [string][out] */ BSTR __RPC_FAR *lpszDeviceName,
            /* [out] */ LONG __RPC_FAR *lplDeviceNumber,
            /* [out] */ LONG __RPC_FAR *lplDeviceRadix,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *FreeDeviceStatus )( 
            IActSIM3 __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceBlock2 )( 
            IActSIM3 __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lSize,
            /* [size_is][out] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceBlock2 )( 
            IActSIM3 __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lSize,
            /* [size_is][in] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceRandom2 )( 
            IActSIM3 __RPC_FAR * This,
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG lSize,
            /* [size_is][out] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceRandom2 )( 
            IActSIM3 __RPC_FAR * This,
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG lSize,
            /* [size_is][in] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetDevice2 )( 
            IActSIM3 __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [out] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetDevice2 )( 
            IActSIM3 __RPC_FAR * This,
            /* [in] */ BSTR szDevice,
            /* [in] */ SHORT sData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActTargetSimulator )( 
            IActSIM3 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActTargetSimulator )( 
            IActSIM3 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        END_INTERFACE
    } IActSIM3Vtbl;

    interface IActSIM3
    {
        CONST_VTBL struct IActSIM3Vtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IActSIM3_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IActSIM3_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IActSIM3_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IActSIM3_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IActSIM3_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IActSIM3_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IActSIM3_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IActSIM3_Open(This,lplReturnCode)	\
    (This)->lpVtbl -> Open(This,lplReturnCode)

#define IActSIM3_Close(This,lplReturnCode)	\
    (This)->lpVtbl -> Close(This,lplReturnCode)

#define IActSIM3_GetDevice(This,szDevice,lplData,lplReturnCode)	\
    (This)->lpVtbl -> GetDevice(This,szDevice,lplData,lplReturnCode)

#define IActSIM3_SetDevice(This,szDevice,lData,lplReturnCode)	\
    (This)->lpVtbl -> SetDevice(This,szDevice,lData,lplReturnCode)

#define IActSIM3_ReadDeviceBlock(This,szDevice,lSize,lplData,lplReturnCode)	\
    (This)->lpVtbl -> ReadDeviceBlock(This,szDevice,lSize,lplData,lplReturnCode)

#define IActSIM3_WriteDeviceBlock(This,szDevice,lSize,lplData,lplReturnCode)	\
    (This)->lpVtbl -> WriteDeviceBlock(This,szDevice,lSize,lplData,lplReturnCode)

#define IActSIM3_ReadDeviceRandom(This,szDeviceList,lSize,lplData,lplReturnCode)	\
    (This)->lpVtbl -> ReadDeviceRandom(This,szDeviceList,lSize,lplData,lplReturnCode)

#define IActSIM3_WriteDeviceRandom(This,szDeviceList,lSize,lplData,lplReturnCode)	\
    (This)->lpVtbl -> WriteDeviceRandom(This,szDeviceList,lSize,lplData,lplReturnCode)

#define IActSIM3_ReadBuffer(This,lStartIO,lAddress,lReadSize,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> ReadBuffer(This,lStartIO,lAddress,lReadSize,lpsData,lplReturnCode)

#define IActSIM3_WriteBuffer(This,lStartIO,lAddress,lWriteSize,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> WriteBuffer(This,lStartIO,lAddress,lWriteSize,lpsData,lplReturnCode)

#define IActSIM3_GetCpuType(This,szCpuName,lplCpuCode,lplReturnCode)	\
    (This)->lpVtbl -> GetCpuType(This,szCpuName,lplCpuCode,lplReturnCode)

#define IActSIM3_SetCpuStatus(This,lOperation,lplReturnCode)	\
    (This)->lpVtbl -> SetCpuStatus(This,lOperation,lplReturnCode)

#define IActSIM3_GetClockData(This,lpsYear,lpsMonth,lpsDay,lpsDayOfWeek,lpsHour,lpsMinute,lpsSecond,lplReturnCode)	\
    (This)->lpVtbl -> GetClockData(This,lpsYear,lpsMonth,lpsDay,lpsDayOfWeek,lpsHour,lpsMinute,lpsSecond,lplReturnCode)

#define IActSIM3_EntryDeviceStatus(This,szDeviceList,lSize,lMonitorCycle,lplData,lplReturnCode)	\
    (This)->lpVtbl -> EntryDeviceStatus(This,szDeviceList,lSize,lMonitorCycle,lplData,lplReturnCode)

#define IActSIM3_CheckDeviceString(This,szDevice,lCheckType,lSize,lplDeviceType,lpszDeviceName,lplDeviceNumber,lplDeviceRadix,lplReturnCode)	\
    (This)->lpVtbl -> CheckDeviceString(This,szDevice,lCheckType,lSize,lplDeviceType,lpszDeviceName,lplDeviceNumber,lplDeviceRadix,lplReturnCode)

#define IActSIM3_FreeDeviceStatus(This,lplReturnCode)	\
    (This)->lpVtbl -> FreeDeviceStatus(This,lplReturnCode)

#define IActSIM3_ReadDeviceBlock2(This,szDevice,lSize,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> ReadDeviceBlock2(This,szDevice,lSize,lpsData,lplReturnCode)

#define IActSIM3_WriteDeviceBlock2(This,szDevice,lSize,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> WriteDeviceBlock2(This,szDevice,lSize,lpsData,lplReturnCode)

#define IActSIM3_ReadDeviceRandom2(This,szDeviceList,lSize,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> ReadDeviceRandom2(This,szDeviceList,lSize,lpsData,lplReturnCode)

#define IActSIM3_WriteDeviceRandom2(This,szDeviceList,lSize,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> WriteDeviceRandom2(This,szDeviceList,lSize,lpsData,lplReturnCode)

#define IActSIM3_GetDevice2(This,szDevice,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> GetDevice2(This,szDevice,lpsData,lplReturnCode)

#define IActSIM3_SetDevice2(This,szDevice,sData,lplReturnCode)	\
    (This)->lpVtbl -> SetDevice2(This,szDevice,sData,lplReturnCode)

#define IActSIM3_get_ActTargetSimulator(This,pVal)	\
    (This)->lpVtbl -> get_ActTargetSimulator(This,pVal)

#define IActSIM3_put_ActTargetSimulator(This,newVal)	\
    (This)->lpVtbl -> put_ActTargetSimulator(This,newVal)



#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IActSIM3_INTERFACE_DEFINED__ */


#ifndef __IActMLSIM_INTERFACE_DEFINED__
#define __IActMLSIM_INTERFACE_DEFINED__

/* interface IActMLSIM */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IActMLSIM;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("FBD0A696-9BD0-4068-9C9D-BDC1D391165C")
    IActMLSIM : public IDispatch
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
            /* [in] */ VARIANT varDeviceList,
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
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActTargetSimulator( 
            /* [retval][out] */ VARIANT __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActTargetSimulator( 
            /* [in] */ VARIANT newVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IActMLSIMVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IActMLSIM __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IActMLSIM __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IActMLSIM __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IActMLSIM __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IActMLSIM __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IActMLSIM __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IActMLSIM __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Open )( 
            IActMLSIM __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Close )( 
            IActMLSIM __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetDevice )( 
            IActMLSIM __RPC_FAR * This,
            /* [in] */ VARIANT varDevice,
            /* [out] */ VARIANT __RPC_FAR *lpvarData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetDevice )( 
            IActMLSIM __RPC_FAR * This,
            /* [in] */ VARIANT varDevice,
            /* [in] */ VARIANT varData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceBlock )( 
            IActMLSIM __RPC_FAR * This,
            /* [in] */ VARIANT varDevice,
            /* [in] */ VARIANT varSize,
            /* [out] */ VARIANT __RPC_FAR *lpvarData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceBlock )( 
            IActMLSIM __RPC_FAR * This,
            /* [in] */ VARIANT varDevice,
            /* [in] */ VARIANT varSize,
            /* [in] */ VARIANT varData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceRandom )( 
            IActMLSIM __RPC_FAR * This,
            /* [in] */ VARIANT varDeviceList,
            /* [in] */ VARIANT varSize,
            /* [out] */ VARIANT __RPC_FAR *lpvarData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceRandom )( 
            IActMLSIM __RPC_FAR * This,
            /* [in] */ VARIANT varDeviceList,
            /* [in] */ VARIANT varSize,
            /* [in] */ VARIANT varData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadBuffer )( 
            IActMLSIM __RPC_FAR * This,
            /* [in] */ VARIANT varStartIO,
            /* [in] */ VARIANT varAddress,
            /* [in] */ VARIANT varReadSize,
            /* [out] */ VARIANT __RPC_FAR *lpvarData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteBuffer )( 
            IActMLSIM __RPC_FAR * This,
            /* [in] */ VARIANT varStartIO,
            /* [in] */ VARIANT varAddress,
            /* [in] */ VARIANT varWriteSize,
            /* [in] */ VARIANT varData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetClockData )( 
            IActMLSIM __RPC_FAR * This,
            /* [out] */ VARIANT __RPC_FAR *lpvarYear,
            /* [out] */ VARIANT __RPC_FAR *lpvarMonth,
            /* [out] */ VARIANT __RPC_FAR *lpvarDay,
            /* [out] */ VARIANT __RPC_FAR *lpvarDayOfWeek,
            /* [out] */ VARIANT __RPC_FAR *lpvarHour,
            /* [out] */ VARIANT __RPC_FAR *lpvarMinute,
            /* [out] */ VARIANT __RPC_FAR *lpvarSecond,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetCpuStatus )( 
            IActMLSIM __RPC_FAR * This,
            /* [in] */ VARIANT varOperation,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetCpuType )( 
            IActMLSIM __RPC_FAR * This,
            /* [out] */ VARIANT __RPC_FAR *lpvarCpuName,
            /* [out] */ VARIANT __RPC_FAR *lpvarCpuType,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *EntryDeviceStatus )( 
            IActMLSIM __RPC_FAR * This,
            /* [in] */ VARIANT varDeviceList,
            /* [in] */ VARIANT varSize,
            /* [in] */ VARIANT varMonitorCycle,
            /* [in] */ VARIANT varData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *FreeDeviceStatus )( 
            IActMLSIM __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceBlock2 )( 
            IActMLSIM __RPC_FAR * This,
            /* [in] */ VARIANT varDevice,
            /* [in] */ VARIANT varSize,
            /* [out] */ VARIANT __RPC_FAR *lpvarData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceBlock2 )( 
            IActMLSIM __RPC_FAR * This,
            /* [in] */ VARIANT varDeviceList,
            /* [in] */ VARIANT varSize,
            /* [in] */ VARIANT varData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceRandom2 )( 
            IActMLSIM __RPC_FAR * This,
            /* [in] */ VARIANT varDeviceList,
            /* [in] */ VARIANT varSize,
            /* [out] */ VARIANT __RPC_FAR *lpvarData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceRandom2 )( 
            IActMLSIM __RPC_FAR * This,
            /* [in] */ VARIANT varDeviceList,
            /* [in] */ VARIANT varSize,
            /* [in] */ VARIANT varData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetDevice2 )( 
            IActMLSIM __RPC_FAR * This,
            /* [in] */ VARIANT varDevice,
            /* [out] */ VARIANT __RPC_FAR *lpvarData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetDevice2 )( 
            IActMLSIM __RPC_FAR * This,
            /* [in] */ VARIANT varDevice,
            /* [in] */ VARIANT varData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActTargetSimulator )( 
            IActMLSIM __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActTargetSimulator )( 
            IActMLSIM __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        END_INTERFACE
    } IActMLSIMVtbl;

    interface IActMLSIM
    {
        CONST_VTBL struct IActMLSIMVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IActMLSIM_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IActMLSIM_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IActMLSIM_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IActMLSIM_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IActMLSIM_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IActMLSIM_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IActMLSIM_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IActMLSIM_Open(This,lpvarReturnCode)	\
    (This)->lpVtbl -> Open(This,lpvarReturnCode)

#define IActMLSIM_Close(This,lpvarReturnCode)	\
    (This)->lpVtbl -> Close(This,lpvarReturnCode)

#define IActMLSIM_GetDevice(This,varDevice,lpvarData,lpvarReturnCode)	\
    (This)->lpVtbl -> GetDevice(This,varDevice,lpvarData,lpvarReturnCode)

#define IActMLSIM_SetDevice(This,varDevice,varData,lpvarReturnCode)	\
    (This)->lpVtbl -> SetDevice(This,varDevice,varData,lpvarReturnCode)

#define IActMLSIM_ReadDeviceBlock(This,varDevice,varSize,lpvarData,lpvarReturnCode)	\
    (This)->lpVtbl -> ReadDeviceBlock(This,varDevice,varSize,lpvarData,lpvarReturnCode)

#define IActMLSIM_WriteDeviceBlock(This,varDevice,varSize,varData,lpvarReturnCode)	\
    (This)->lpVtbl -> WriteDeviceBlock(This,varDevice,varSize,varData,lpvarReturnCode)

#define IActMLSIM_ReadDeviceRandom(This,varDeviceList,varSize,lpvarData,lpvarReturnCode)	\
    (This)->lpVtbl -> ReadDeviceRandom(This,varDeviceList,varSize,lpvarData,lpvarReturnCode)

#define IActMLSIM_WriteDeviceRandom(This,varDeviceList,varSize,varData,lpvarReturnCode)	\
    (This)->lpVtbl -> WriteDeviceRandom(This,varDeviceList,varSize,varData,lpvarReturnCode)

#define IActMLSIM_ReadBuffer(This,varStartIO,varAddress,varReadSize,lpvarData,lpvarReturnCode)	\
    (This)->lpVtbl -> ReadBuffer(This,varStartIO,varAddress,varReadSize,lpvarData,lpvarReturnCode)

#define IActMLSIM_WriteBuffer(This,varStartIO,varAddress,varWriteSize,varData,lpvarReturnCode)	\
    (This)->lpVtbl -> WriteBuffer(This,varStartIO,varAddress,varWriteSize,varData,lpvarReturnCode)

#define IActMLSIM_GetClockData(This,lpvarYear,lpvarMonth,lpvarDay,lpvarDayOfWeek,lpvarHour,lpvarMinute,lpvarSecond,lpvarReturnCode)	\
    (This)->lpVtbl -> GetClockData(This,lpvarYear,lpvarMonth,lpvarDay,lpvarDayOfWeek,lpvarHour,lpvarMinute,lpvarSecond,lpvarReturnCode)

#define IActMLSIM_SetCpuStatus(This,varOperation,lpvarReturnCode)	\
    (This)->lpVtbl -> SetCpuStatus(This,varOperation,lpvarReturnCode)

#define IActMLSIM_GetCpuType(This,lpvarCpuName,lpvarCpuType,lpvarReturnCode)	\
    (This)->lpVtbl -> GetCpuType(This,lpvarCpuName,lpvarCpuType,lpvarReturnCode)

#define IActMLSIM_EntryDeviceStatus(This,varDeviceList,varSize,varMonitorCycle,varData,lpvarReturnCode)	\
    (This)->lpVtbl -> EntryDeviceStatus(This,varDeviceList,varSize,varMonitorCycle,varData,lpvarReturnCode)

#define IActMLSIM_FreeDeviceStatus(This,lpvarReturnCode)	\
    (This)->lpVtbl -> FreeDeviceStatus(This,lpvarReturnCode)

#define IActMLSIM_ReadDeviceBlock2(This,varDevice,varSize,lpvarData,lpvarReturnCode)	\
    (This)->lpVtbl -> ReadDeviceBlock2(This,varDevice,varSize,lpvarData,lpvarReturnCode)

#define IActMLSIM_WriteDeviceBlock2(This,varDeviceList,varSize,varData,lpvarReturnCode)	\
    (This)->lpVtbl -> WriteDeviceBlock2(This,varDeviceList,varSize,varData,lpvarReturnCode)

#define IActMLSIM_ReadDeviceRandom2(This,varDeviceList,varSize,lpvarData,lpvarReturnCode)	\
    (This)->lpVtbl -> ReadDeviceRandom2(This,varDeviceList,varSize,lpvarData,lpvarReturnCode)

#define IActMLSIM_WriteDeviceRandom2(This,varDeviceList,varSize,varData,lpvarReturnCode)	\
    (This)->lpVtbl -> WriteDeviceRandom2(This,varDeviceList,varSize,varData,lpvarReturnCode)

#define IActMLSIM_GetDevice2(This,varDevice,lpvarData,lpvarReturnCode)	\
    (This)->lpVtbl -> GetDevice2(This,varDevice,lpvarData,lpvarReturnCode)

#define IActMLSIM_SetDevice2(This,varDevice,varData,lpvarReturnCode)	\
    (This)->lpVtbl -> SetDevice2(This,varDevice,varData,lpvarReturnCode)

#define IActMLSIM_get_ActTargetSimulator(This,pVal)	\
    (This)->lpVtbl -> get_ActTargetSimulator(This,pVal)

#define IActMLSIM_put_ActTargetSimulator(This,newVal)	\
    (This)->lpVtbl -> put_ActTargetSimulator(This,newVal)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActMLSIM_Open_Proxy( 
    IActMLSIM __RPC_FAR * This,
    /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);


void __RPC_STUB IActMLSIM_Open_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActMLSIM_Close_Proxy( 
    IActMLSIM __RPC_FAR * This,
    /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);


void __RPC_STUB IActMLSIM_Close_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActMLSIM_GetDevice_Proxy( 
    IActMLSIM __RPC_FAR * This,
    /* [in] */ VARIANT varDevice,
    /* [out] */ VARIANT __RPC_FAR *lpvarData,
    /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);


void __RPC_STUB IActMLSIM_GetDevice_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActMLSIM_SetDevice_Proxy( 
    IActMLSIM __RPC_FAR * This,
    /* [in] */ VARIANT varDevice,
    /* [in] */ VARIANT varData,
    /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);


void __RPC_STUB IActMLSIM_SetDevice_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActMLSIM_ReadDeviceBlock_Proxy( 
    IActMLSIM __RPC_FAR * This,
    /* [in] */ VARIANT varDevice,
    /* [in] */ VARIANT varSize,
    /* [out] */ VARIANT __RPC_FAR *lpvarData,
    /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);


void __RPC_STUB IActMLSIM_ReadDeviceBlock_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActMLSIM_WriteDeviceBlock_Proxy( 
    IActMLSIM __RPC_FAR * This,
    /* [in] */ VARIANT varDevice,
    /* [in] */ VARIANT varSize,
    /* [in] */ VARIANT varData,
    /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);


void __RPC_STUB IActMLSIM_WriteDeviceBlock_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActMLSIM_ReadDeviceRandom_Proxy( 
    IActMLSIM __RPC_FAR * This,
    /* [in] */ VARIANT varDeviceList,
    /* [in] */ VARIANT varSize,
    /* [out] */ VARIANT __RPC_FAR *lpvarData,
    /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);


void __RPC_STUB IActMLSIM_ReadDeviceRandom_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActMLSIM_WriteDeviceRandom_Proxy( 
    IActMLSIM __RPC_FAR * This,
    /* [in] */ VARIANT varDeviceList,
    /* [in] */ VARIANT varSize,
    /* [in] */ VARIANT varData,
    /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);


void __RPC_STUB IActMLSIM_WriteDeviceRandom_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActMLSIM_ReadBuffer_Proxy( 
    IActMLSIM __RPC_FAR * This,
    /* [in] */ VARIANT varStartIO,
    /* [in] */ VARIANT varAddress,
    /* [in] */ VARIANT varReadSize,
    /* [out] */ VARIANT __RPC_FAR *lpvarData,
    /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);


void __RPC_STUB IActMLSIM_ReadBuffer_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActMLSIM_WriteBuffer_Proxy( 
    IActMLSIM __RPC_FAR * This,
    /* [in] */ VARIANT varStartIO,
    /* [in] */ VARIANT varAddress,
    /* [in] */ VARIANT varWriteSize,
    /* [in] */ VARIANT varData,
    /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);


void __RPC_STUB IActMLSIM_WriteBuffer_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActMLSIM_GetClockData_Proxy( 
    IActMLSIM __RPC_FAR * This,
    /* [out] */ VARIANT __RPC_FAR *lpvarYear,
    /* [out] */ VARIANT __RPC_FAR *lpvarMonth,
    /* [out] */ VARIANT __RPC_FAR *lpvarDay,
    /* [out] */ VARIANT __RPC_FAR *lpvarDayOfWeek,
    /* [out] */ VARIANT __RPC_FAR *lpvarHour,
    /* [out] */ VARIANT __RPC_FAR *lpvarMinute,
    /* [out] */ VARIANT __RPC_FAR *lpvarSecond,
    /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);


void __RPC_STUB IActMLSIM_GetClockData_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActMLSIM_SetCpuStatus_Proxy( 
    IActMLSIM __RPC_FAR * This,
    /* [in] */ VARIANT varOperation,
    /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);


void __RPC_STUB IActMLSIM_SetCpuStatus_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActMLSIM_GetCpuType_Proxy( 
    IActMLSIM __RPC_FAR * This,
    /* [out] */ VARIANT __RPC_FAR *lpvarCpuName,
    /* [out] */ VARIANT __RPC_FAR *lpvarCpuType,
    /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);


void __RPC_STUB IActMLSIM_GetCpuType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActMLSIM_EntryDeviceStatus_Proxy( 
    IActMLSIM __RPC_FAR * This,
    /* [in] */ VARIANT varDeviceList,
    /* [in] */ VARIANT varSize,
    /* [in] */ VARIANT varMonitorCycle,
    /* [in] */ VARIANT varData,
    /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);


void __RPC_STUB IActMLSIM_EntryDeviceStatus_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActMLSIM_FreeDeviceStatus_Proxy( 
    IActMLSIM __RPC_FAR * This,
    /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);


void __RPC_STUB IActMLSIM_FreeDeviceStatus_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActMLSIM_ReadDeviceBlock2_Proxy( 
    IActMLSIM __RPC_FAR * This,
    /* [in] */ VARIANT varDevice,
    /* [in] */ VARIANT varSize,
    /* [out] */ VARIANT __RPC_FAR *lpvarData,
    /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);


void __RPC_STUB IActMLSIM_ReadDeviceBlock2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActMLSIM_WriteDeviceBlock2_Proxy( 
    IActMLSIM __RPC_FAR * This,
    /* [in] */ VARIANT varDeviceList,
    /* [in] */ VARIANT varSize,
    /* [in] */ VARIANT varData,
    /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);


void __RPC_STUB IActMLSIM_WriteDeviceBlock2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActMLSIM_ReadDeviceRandom2_Proxy( 
    IActMLSIM __RPC_FAR * This,
    /* [in] */ VARIANT varDeviceList,
    /* [in] */ VARIANT varSize,
    /* [out] */ VARIANT __RPC_FAR *lpvarData,
    /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);


void __RPC_STUB IActMLSIM_ReadDeviceRandom2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActMLSIM_WriteDeviceRandom2_Proxy( 
    IActMLSIM __RPC_FAR * This,
    /* [in] */ VARIANT varDeviceList,
    /* [in] */ VARIANT varSize,
    /* [in] */ VARIANT varData,
    /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);


void __RPC_STUB IActMLSIM_WriteDeviceRandom2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActMLSIM_GetDevice2_Proxy( 
    IActMLSIM __RPC_FAR * This,
    /* [in] */ VARIANT varDevice,
    /* [out] */ VARIANT __RPC_FAR *lpvarData,
    /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);


void __RPC_STUB IActMLSIM_GetDevice2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActMLSIM_SetDevice2_Proxy( 
    IActMLSIM __RPC_FAR * This,
    /* [in] */ VARIANT varDevice,
    /* [in] */ VARIANT varData,
    /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);


void __RPC_STUB IActMLSIM_SetDevice2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActMLSIM_get_ActTargetSimulator_Proxy( 
    IActMLSIM __RPC_FAR * This,
    /* [retval][out] */ VARIANT __RPC_FAR *pVal);


void __RPC_STUB IActMLSIM_get_ActTargetSimulator_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActMLSIM_put_ActTargetSimulator_Proxy( 
    IActMLSIM __RPC_FAR * This,
    /* [in] */ VARIANT newVal);


void __RPC_STUB IActMLSIM_put_ActTargetSimulator_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IActMLSIM_INTERFACE_DEFINED__ */


#ifndef __IActMLSIM2_INTERFACE_DEFINED__
#define __IActMLSIM2_INTERFACE_DEFINED__

/* interface IActMLSIM2 */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IActMLSIM2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("162FD970-7CF2-4061-9764-720559910B4B")
    IActMLSIM2 : public IActMLSIM
    {
    public:
    };
    
#else 	/* C style interface */

    typedef struct IActMLSIM2Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IActMLSIM2 __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IActMLSIM2 __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IActMLSIM2 __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IActMLSIM2 __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IActMLSIM2 __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IActMLSIM2 __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IActMLSIM2 __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Open )( 
            IActMLSIM2 __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Close )( 
            IActMLSIM2 __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetDevice )( 
            IActMLSIM2 __RPC_FAR * This,
            /* [in] */ VARIANT varDevice,
            /* [out] */ VARIANT __RPC_FAR *lpvarData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetDevice )( 
            IActMLSIM2 __RPC_FAR * This,
            /* [in] */ VARIANT varDevice,
            /* [in] */ VARIANT varData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceBlock )( 
            IActMLSIM2 __RPC_FAR * This,
            /* [in] */ VARIANT varDevice,
            /* [in] */ VARIANT varSize,
            /* [out] */ VARIANT __RPC_FAR *lpvarData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceBlock )( 
            IActMLSIM2 __RPC_FAR * This,
            /* [in] */ VARIANT varDevice,
            /* [in] */ VARIANT varSize,
            /* [in] */ VARIANT varData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceRandom )( 
            IActMLSIM2 __RPC_FAR * This,
            /* [in] */ VARIANT varDeviceList,
            /* [in] */ VARIANT varSize,
            /* [out] */ VARIANT __RPC_FAR *lpvarData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceRandom )( 
            IActMLSIM2 __RPC_FAR * This,
            /* [in] */ VARIANT varDeviceList,
            /* [in] */ VARIANT varSize,
            /* [in] */ VARIANT varData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadBuffer )( 
            IActMLSIM2 __RPC_FAR * This,
            /* [in] */ VARIANT varStartIO,
            /* [in] */ VARIANT varAddress,
            /* [in] */ VARIANT varReadSize,
            /* [out] */ VARIANT __RPC_FAR *lpvarData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteBuffer )( 
            IActMLSIM2 __RPC_FAR * This,
            /* [in] */ VARIANT varStartIO,
            /* [in] */ VARIANT varAddress,
            /* [in] */ VARIANT varWriteSize,
            /* [in] */ VARIANT varData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetClockData )( 
            IActMLSIM2 __RPC_FAR * This,
            /* [out] */ VARIANT __RPC_FAR *lpvarYear,
            /* [out] */ VARIANT __RPC_FAR *lpvarMonth,
            /* [out] */ VARIANT __RPC_FAR *lpvarDay,
            /* [out] */ VARIANT __RPC_FAR *lpvarDayOfWeek,
            /* [out] */ VARIANT __RPC_FAR *lpvarHour,
            /* [out] */ VARIANT __RPC_FAR *lpvarMinute,
            /* [out] */ VARIANT __RPC_FAR *lpvarSecond,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetCpuStatus )( 
            IActMLSIM2 __RPC_FAR * This,
            /* [in] */ VARIANT varOperation,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetCpuType )( 
            IActMLSIM2 __RPC_FAR * This,
            /* [out] */ VARIANT __RPC_FAR *lpvarCpuName,
            /* [out] */ VARIANT __RPC_FAR *lpvarCpuType,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *EntryDeviceStatus )( 
            IActMLSIM2 __RPC_FAR * This,
            /* [in] */ VARIANT varDeviceList,
            /* [in] */ VARIANT varSize,
            /* [in] */ VARIANT varMonitorCycle,
            /* [in] */ VARIANT varData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *FreeDeviceStatus )( 
            IActMLSIM2 __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceBlock2 )( 
            IActMLSIM2 __RPC_FAR * This,
            /* [in] */ VARIANT varDevice,
            /* [in] */ VARIANT varSize,
            /* [out] */ VARIANT __RPC_FAR *lpvarData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceBlock2 )( 
            IActMLSIM2 __RPC_FAR * This,
            /* [in] */ VARIANT varDeviceList,
            /* [in] */ VARIANT varSize,
            /* [in] */ VARIANT varData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceRandom2 )( 
            IActMLSIM2 __RPC_FAR * This,
            /* [in] */ VARIANT varDeviceList,
            /* [in] */ VARIANT varSize,
            /* [out] */ VARIANT __RPC_FAR *lpvarData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceRandom2 )( 
            IActMLSIM2 __RPC_FAR * This,
            /* [in] */ VARIANT varDeviceList,
            /* [in] */ VARIANT varSize,
            /* [in] */ VARIANT varData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetDevice2 )( 
            IActMLSIM2 __RPC_FAR * This,
            /* [in] */ VARIANT varDevice,
            /* [out] */ VARIANT __RPC_FAR *lpvarData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetDevice2 )( 
            IActMLSIM2 __RPC_FAR * This,
            /* [in] */ VARIANT varDevice,
            /* [in] */ VARIANT varData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActTargetSimulator )( 
            IActMLSIM2 __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActTargetSimulator )( 
            IActMLSIM2 __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        END_INTERFACE
    } IActMLSIM2Vtbl;

    interface IActMLSIM2
    {
        CONST_VTBL struct IActMLSIM2Vtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IActMLSIM2_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IActMLSIM2_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IActMLSIM2_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IActMLSIM2_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IActMLSIM2_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IActMLSIM2_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IActMLSIM2_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IActMLSIM2_Open(This,lpvarReturnCode)	\
    (This)->lpVtbl -> Open(This,lpvarReturnCode)

#define IActMLSIM2_Close(This,lpvarReturnCode)	\
    (This)->lpVtbl -> Close(This,lpvarReturnCode)

#define IActMLSIM2_GetDevice(This,varDevice,lpvarData,lpvarReturnCode)	\
    (This)->lpVtbl -> GetDevice(This,varDevice,lpvarData,lpvarReturnCode)

#define IActMLSIM2_SetDevice(This,varDevice,varData,lpvarReturnCode)	\
    (This)->lpVtbl -> SetDevice(This,varDevice,varData,lpvarReturnCode)

#define IActMLSIM2_ReadDeviceBlock(This,varDevice,varSize,lpvarData,lpvarReturnCode)	\
    (This)->lpVtbl -> ReadDeviceBlock(This,varDevice,varSize,lpvarData,lpvarReturnCode)

#define IActMLSIM2_WriteDeviceBlock(This,varDevice,varSize,varData,lpvarReturnCode)	\
    (This)->lpVtbl -> WriteDeviceBlock(This,varDevice,varSize,varData,lpvarReturnCode)

#define IActMLSIM2_ReadDeviceRandom(This,varDeviceList,varSize,lpvarData,lpvarReturnCode)	\
    (This)->lpVtbl -> ReadDeviceRandom(This,varDeviceList,varSize,lpvarData,lpvarReturnCode)

#define IActMLSIM2_WriteDeviceRandom(This,varDeviceList,varSize,varData,lpvarReturnCode)	\
    (This)->lpVtbl -> WriteDeviceRandom(This,varDeviceList,varSize,varData,lpvarReturnCode)

#define IActMLSIM2_ReadBuffer(This,varStartIO,varAddress,varReadSize,lpvarData,lpvarReturnCode)	\
    (This)->lpVtbl -> ReadBuffer(This,varStartIO,varAddress,varReadSize,lpvarData,lpvarReturnCode)

#define IActMLSIM2_WriteBuffer(This,varStartIO,varAddress,varWriteSize,varData,lpvarReturnCode)	\
    (This)->lpVtbl -> WriteBuffer(This,varStartIO,varAddress,varWriteSize,varData,lpvarReturnCode)

#define IActMLSIM2_GetClockData(This,lpvarYear,lpvarMonth,lpvarDay,lpvarDayOfWeek,lpvarHour,lpvarMinute,lpvarSecond,lpvarReturnCode)	\
    (This)->lpVtbl -> GetClockData(This,lpvarYear,lpvarMonth,lpvarDay,lpvarDayOfWeek,lpvarHour,lpvarMinute,lpvarSecond,lpvarReturnCode)

#define IActMLSIM2_SetCpuStatus(This,varOperation,lpvarReturnCode)	\
    (This)->lpVtbl -> SetCpuStatus(This,varOperation,lpvarReturnCode)

#define IActMLSIM2_GetCpuType(This,lpvarCpuName,lpvarCpuType,lpvarReturnCode)	\
    (This)->lpVtbl -> GetCpuType(This,lpvarCpuName,lpvarCpuType,lpvarReturnCode)

#define IActMLSIM2_EntryDeviceStatus(This,varDeviceList,varSize,varMonitorCycle,varData,lpvarReturnCode)	\
    (This)->lpVtbl -> EntryDeviceStatus(This,varDeviceList,varSize,varMonitorCycle,varData,lpvarReturnCode)

#define IActMLSIM2_FreeDeviceStatus(This,lpvarReturnCode)	\
    (This)->lpVtbl -> FreeDeviceStatus(This,lpvarReturnCode)

#define IActMLSIM2_ReadDeviceBlock2(This,varDevice,varSize,lpvarData,lpvarReturnCode)	\
    (This)->lpVtbl -> ReadDeviceBlock2(This,varDevice,varSize,lpvarData,lpvarReturnCode)

#define IActMLSIM2_WriteDeviceBlock2(This,varDeviceList,varSize,varData,lpvarReturnCode)	\
    (This)->lpVtbl -> WriteDeviceBlock2(This,varDeviceList,varSize,varData,lpvarReturnCode)

#define IActMLSIM2_ReadDeviceRandom2(This,varDeviceList,varSize,lpvarData,lpvarReturnCode)	\
    (This)->lpVtbl -> ReadDeviceRandom2(This,varDeviceList,varSize,lpvarData,lpvarReturnCode)

#define IActMLSIM2_WriteDeviceRandom2(This,varDeviceList,varSize,varData,lpvarReturnCode)	\
    (This)->lpVtbl -> WriteDeviceRandom2(This,varDeviceList,varSize,varData,lpvarReturnCode)

#define IActMLSIM2_GetDevice2(This,varDevice,lpvarData,lpvarReturnCode)	\
    (This)->lpVtbl -> GetDevice2(This,varDevice,lpvarData,lpvarReturnCode)

#define IActMLSIM2_SetDevice2(This,varDevice,varData,lpvarReturnCode)	\
    (This)->lpVtbl -> SetDevice2(This,varDevice,varData,lpvarReturnCode)

#define IActMLSIM2_get_ActTargetSimulator(This,pVal)	\
    (This)->lpVtbl -> get_ActTargetSimulator(This,pVal)

#define IActMLSIM2_put_ActTargetSimulator(This,newVal)	\
    (This)->lpVtbl -> put_ActTargetSimulator(This,newVal)


#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IActMLSIM2_INTERFACE_DEFINED__ */


#ifndef __IActMLSIM3_INTERFACE_DEFINED__
#define __IActMLSIM3_INTERFACE_DEFINED__

/* interface IActMLSIM3 */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IActMLSIM3;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("655554DB-37F8-4439-89B2-0DDB1CC6BC71")
    IActMLSIM3 : public IActMLSIM2
    {
    public:
    };
    
#else 	/* C style interface */

    typedef struct IActMLSIM3Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IActMLSIM3 __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IActMLSIM3 __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IActMLSIM3 __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IActMLSIM3 __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IActMLSIM3 __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IActMLSIM3 __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IActMLSIM3 __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Open )( 
            IActMLSIM3 __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Close )( 
            IActMLSIM3 __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetDevice )( 
            IActMLSIM3 __RPC_FAR * This,
            /* [in] */ VARIANT varDevice,
            /* [out] */ VARIANT __RPC_FAR *lpvarData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetDevice )( 
            IActMLSIM3 __RPC_FAR * This,
            /* [in] */ VARIANT varDevice,
            /* [in] */ VARIANT varData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceBlock )( 
            IActMLSIM3 __RPC_FAR * This,
            /* [in] */ VARIANT varDevice,
            /* [in] */ VARIANT varSize,
            /* [out] */ VARIANT __RPC_FAR *lpvarData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceBlock )( 
            IActMLSIM3 __RPC_FAR * This,
            /* [in] */ VARIANT varDevice,
            /* [in] */ VARIANT varSize,
            /* [in] */ VARIANT varData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceRandom )( 
            IActMLSIM3 __RPC_FAR * This,
            /* [in] */ VARIANT varDeviceList,
            /* [in] */ VARIANT varSize,
            /* [out] */ VARIANT __RPC_FAR *lpvarData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceRandom )( 
            IActMLSIM3 __RPC_FAR * This,
            /* [in] */ VARIANT varDeviceList,
            /* [in] */ VARIANT varSize,
            /* [in] */ VARIANT varData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadBuffer )( 
            IActMLSIM3 __RPC_FAR * This,
            /* [in] */ VARIANT varStartIO,
            /* [in] */ VARIANT varAddress,
            /* [in] */ VARIANT varReadSize,
            /* [out] */ VARIANT __RPC_FAR *lpvarData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteBuffer )( 
            IActMLSIM3 __RPC_FAR * This,
            /* [in] */ VARIANT varStartIO,
            /* [in] */ VARIANT varAddress,
            /* [in] */ VARIANT varWriteSize,
            /* [in] */ VARIANT varData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetClockData )( 
            IActMLSIM3 __RPC_FAR * This,
            /* [out] */ VARIANT __RPC_FAR *lpvarYear,
            /* [out] */ VARIANT __RPC_FAR *lpvarMonth,
            /* [out] */ VARIANT __RPC_FAR *lpvarDay,
            /* [out] */ VARIANT __RPC_FAR *lpvarDayOfWeek,
            /* [out] */ VARIANT __RPC_FAR *lpvarHour,
            /* [out] */ VARIANT __RPC_FAR *lpvarMinute,
            /* [out] */ VARIANT __RPC_FAR *lpvarSecond,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetCpuStatus )( 
            IActMLSIM3 __RPC_FAR * This,
            /* [in] */ VARIANT varOperation,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetCpuType )( 
            IActMLSIM3 __RPC_FAR * This,
            /* [out] */ VARIANT __RPC_FAR *lpvarCpuName,
            /* [out] */ VARIANT __RPC_FAR *lpvarCpuType,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *EntryDeviceStatus )( 
            IActMLSIM3 __RPC_FAR * This,
            /* [in] */ VARIANT varDeviceList,
            /* [in] */ VARIANT varSize,
            /* [in] */ VARIANT varMonitorCycle,
            /* [in] */ VARIANT varData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *FreeDeviceStatus )( 
            IActMLSIM3 __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceBlock2 )( 
            IActMLSIM3 __RPC_FAR * This,
            /* [in] */ VARIANT varDevice,
            /* [in] */ VARIANT varSize,
            /* [out] */ VARIANT __RPC_FAR *lpvarData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceBlock2 )( 
            IActMLSIM3 __RPC_FAR * This,
            /* [in] */ VARIANT varDeviceList,
            /* [in] */ VARIANT varSize,
            /* [in] */ VARIANT varData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceRandom2 )( 
            IActMLSIM3 __RPC_FAR * This,
            /* [in] */ VARIANT varDeviceList,
            /* [in] */ VARIANT varSize,
            /* [out] */ VARIANT __RPC_FAR *lpvarData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceRandom2 )( 
            IActMLSIM3 __RPC_FAR * This,
            /* [in] */ VARIANT varDeviceList,
            /* [in] */ VARIANT varSize,
            /* [in] */ VARIANT varData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetDevice2 )( 
            IActMLSIM3 __RPC_FAR * This,
            /* [in] */ VARIANT varDevice,
            /* [out] */ VARIANT __RPC_FAR *lpvarData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetDevice2 )( 
            IActMLSIM3 __RPC_FAR * This,
            /* [in] */ VARIANT varDevice,
            /* [in] */ VARIANT varData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActTargetSimulator )( 
            IActMLSIM3 __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActTargetSimulator )( 
            IActMLSIM3 __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        END_INTERFACE
    } IActMLSIM3Vtbl;

    interface IActMLSIM3
    {
        CONST_VTBL struct IActMLSIM3Vtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IActMLSIM3_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IActMLSIM3_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IActMLSIM3_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IActMLSIM3_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IActMLSIM3_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IActMLSIM3_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IActMLSIM3_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IActMLSIM3_Open(This,lpvarReturnCode)	\
    (This)->lpVtbl -> Open(This,lpvarReturnCode)

#define IActMLSIM3_Close(This,lpvarReturnCode)	\
    (This)->lpVtbl -> Close(This,lpvarReturnCode)

#define IActMLSIM3_GetDevice(This,varDevice,lpvarData,lpvarReturnCode)	\
    (This)->lpVtbl -> GetDevice(This,varDevice,lpvarData,lpvarReturnCode)

#define IActMLSIM3_SetDevice(This,varDevice,varData,lpvarReturnCode)	\
    (This)->lpVtbl -> SetDevice(This,varDevice,varData,lpvarReturnCode)

#define IActMLSIM3_ReadDeviceBlock(This,varDevice,varSize,lpvarData,lpvarReturnCode)	\
    (This)->lpVtbl -> ReadDeviceBlock(This,varDevice,varSize,lpvarData,lpvarReturnCode)

#define IActMLSIM3_WriteDeviceBlock(This,varDevice,varSize,varData,lpvarReturnCode)	\
    (This)->lpVtbl -> WriteDeviceBlock(This,varDevice,varSize,varData,lpvarReturnCode)

#define IActMLSIM3_ReadDeviceRandom(This,varDeviceList,varSize,lpvarData,lpvarReturnCode)	\
    (This)->lpVtbl -> ReadDeviceRandom(This,varDeviceList,varSize,lpvarData,lpvarReturnCode)

#define IActMLSIM3_WriteDeviceRandom(This,varDeviceList,varSize,varData,lpvarReturnCode)	\
    (This)->lpVtbl -> WriteDeviceRandom(This,varDeviceList,varSize,varData,lpvarReturnCode)

#define IActMLSIM3_ReadBuffer(This,varStartIO,varAddress,varReadSize,lpvarData,lpvarReturnCode)	\
    (This)->lpVtbl -> ReadBuffer(This,varStartIO,varAddress,varReadSize,lpvarData,lpvarReturnCode)

#define IActMLSIM3_WriteBuffer(This,varStartIO,varAddress,varWriteSize,varData,lpvarReturnCode)	\
    (This)->lpVtbl -> WriteBuffer(This,varStartIO,varAddress,varWriteSize,varData,lpvarReturnCode)

#define IActMLSIM3_GetClockData(This,lpvarYear,lpvarMonth,lpvarDay,lpvarDayOfWeek,lpvarHour,lpvarMinute,lpvarSecond,lpvarReturnCode)	\
    (This)->lpVtbl -> GetClockData(This,lpvarYear,lpvarMonth,lpvarDay,lpvarDayOfWeek,lpvarHour,lpvarMinute,lpvarSecond,lpvarReturnCode)

#define IActMLSIM3_SetCpuStatus(This,varOperation,lpvarReturnCode)	\
    (This)->lpVtbl -> SetCpuStatus(This,varOperation,lpvarReturnCode)

#define IActMLSIM3_GetCpuType(This,lpvarCpuName,lpvarCpuType,lpvarReturnCode)	\
    (This)->lpVtbl -> GetCpuType(This,lpvarCpuName,lpvarCpuType,lpvarReturnCode)

#define IActMLSIM3_EntryDeviceStatus(This,varDeviceList,varSize,varMonitorCycle,varData,lpvarReturnCode)	\
    (This)->lpVtbl -> EntryDeviceStatus(This,varDeviceList,varSize,varMonitorCycle,varData,lpvarReturnCode)

#define IActMLSIM3_FreeDeviceStatus(This,lpvarReturnCode)	\
    (This)->lpVtbl -> FreeDeviceStatus(This,lpvarReturnCode)

#define IActMLSIM3_ReadDeviceBlock2(This,varDevice,varSize,lpvarData,lpvarReturnCode)	\
    (This)->lpVtbl -> ReadDeviceBlock2(This,varDevice,varSize,lpvarData,lpvarReturnCode)

#define IActMLSIM3_WriteDeviceBlock2(This,varDeviceList,varSize,varData,lpvarReturnCode)	\
    (This)->lpVtbl -> WriteDeviceBlock2(This,varDeviceList,varSize,varData,lpvarReturnCode)

#define IActMLSIM3_ReadDeviceRandom2(This,varDeviceList,varSize,lpvarData,lpvarReturnCode)	\
    (This)->lpVtbl -> ReadDeviceRandom2(This,varDeviceList,varSize,lpvarData,lpvarReturnCode)

#define IActMLSIM3_WriteDeviceRandom2(This,varDeviceList,varSize,varData,lpvarReturnCode)	\
    (This)->lpVtbl -> WriteDeviceRandom2(This,varDeviceList,varSize,varData,lpvarReturnCode)

#define IActMLSIM3_GetDevice2(This,varDevice,lpvarData,lpvarReturnCode)	\
    (This)->lpVtbl -> GetDevice2(This,varDevice,lpvarData,lpvarReturnCode)

#define IActMLSIM3_SetDevice2(This,varDevice,varData,lpvarReturnCode)	\
    (This)->lpVtbl -> SetDevice2(This,varDevice,varData,lpvarReturnCode)

#define IActMLSIM3_get_ActTargetSimulator(This,pVal)	\
    (This)->lpVtbl -> get_ActTargetSimulator(This,pVal)

#define IActMLSIM3_put_ActTargetSimulator(This,newVal)	\
    (This)->lpVtbl -> put_ActTargetSimulator(This,newVal)



#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IActMLSIM3_INTERFACE_DEFINED__ */



#ifndef __ACTLLTLib_LIBRARY_DEFINED__
#define __ACTLLTLib_LIBRARY_DEFINED__

/* library ACTLLTLib */
/* [helpstring][version][uuid] */ 


EXTERN_C const IID LIBID_ACTLLTLib;

#ifndef ___IActLLTEvents_DISPINTERFACE_DEFINED__
#define ___IActLLTEvents_DISPINTERFACE_DEFINED__

/* dispinterface _IActLLTEvents */
/* [helpstring][uuid] */ 


EXTERN_C const IID DIID__IActLLTEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("235CFC03-AE9E-11D3-83AE-00A024BDBF2B")
    _IActLLTEvents : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct _IActLLTEventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            _IActLLTEvents __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            _IActLLTEvents __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            _IActLLTEvents __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            _IActLLTEvents __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            _IActLLTEvents __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            _IActLLTEvents __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            _IActLLTEvents __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        END_INTERFACE
    } _IActLLTEventsVtbl;

    interface _IActLLTEvents
    {
        CONST_VTBL struct _IActLLTEventsVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _IActLLTEvents_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define _IActLLTEvents_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define _IActLLTEvents_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define _IActLLTEvents_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define _IActLLTEvents_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define _IActLLTEvents_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define _IActLLTEvents_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ___IActLLTEvents_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_ActLLT;

#ifdef __cplusplus

class DECLSPEC_UUID("235CFC02-AE9E-11D3-83AE-00A024BDBF2B")
ActLLT;
#endif

#ifndef ___IActMLLLTEvents_DISPINTERFACE_DEFINED__
#define ___IActMLLLTEvents_DISPINTERFACE_DEFINED__

/* dispinterface _IActMLLLTEvents */
/* [helpstring][uuid] */ 


EXTERN_C const IID DIID__IActMLLLTEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("0742D5C3-A98C-11D4-910D-009099244EFD")
    _IActMLLLTEvents : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct _IActMLLLTEventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            _IActMLLLTEvents __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            _IActMLLLTEvents __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            _IActMLLLTEvents __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            _IActMLLLTEvents __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            _IActMLLLTEvents __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            _IActMLLLTEvents __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            _IActMLLLTEvents __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        END_INTERFACE
    } _IActMLLLTEventsVtbl;

    interface _IActMLLLTEvents
    {
        CONST_VTBL struct _IActMLLLTEventsVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _IActMLLLTEvents_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define _IActMLLLTEvents_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define _IActMLLLTEvents_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define _IActMLLLTEvents_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define _IActMLLLTEvents_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define _IActMLLLTEvents_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define _IActMLLLTEvents_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ___IActMLLLTEvents_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_ActMLLLT;

#ifdef __cplusplus

class DECLSPEC_UUID("0742D5C2-A98C-11D4-910D-009099244EFD")
ActMLLLT;
#endif

#ifndef ___IActSIMEvents_DISPINTERFACE_DEFINED__
#define ___IActSIMEvents_DISPINTERFACE_DEFINED__

/* dispinterface _IActSIMEvents */
/* [helpstring][uuid] */ 


EXTERN_C const IID DIID__IActSIMEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("D8D3D4FE-2E70-4654-BCF8-1805749D0525")
    _IActSIMEvents : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct _IActSIMEventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            _IActSIMEvents __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            _IActSIMEvents __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            _IActSIMEvents __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            _IActSIMEvents __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            _IActSIMEvents __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            _IActSIMEvents __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            _IActSIMEvents __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        END_INTERFACE
    } _IActSIMEventsVtbl;

    interface _IActSIMEvents
    {
        CONST_VTBL struct _IActSIMEventsVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _IActSIMEvents_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define _IActSIMEvents_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define _IActSIMEvents_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define _IActSIMEvents_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define _IActSIMEvents_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define _IActSIMEvents_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define _IActSIMEvents_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ___IActSIMEvents_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_ActSIM;

#ifdef __cplusplus

class DECLSPEC_UUID("89A558D1-D377-4653-A19B-9D03481908A0")
ActSIM;
#endif

#ifndef ___IActMLSIMEvents_DISPINTERFACE_DEFINED__
#define ___IActMLSIMEvents_DISPINTERFACE_DEFINED__

/* dispinterface _IActMLSIMEvents */
/* [helpstring][uuid] */ 


EXTERN_C const IID DIID__IActMLSIMEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("F4DDF11F-3914-4C9E-9D63-867CA7C179DA")
    _IActMLSIMEvents : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct _IActMLSIMEventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            _IActMLSIMEvents __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            _IActMLSIMEvents __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            _IActMLSIMEvents __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            _IActMLSIMEvents __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            _IActMLSIMEvents __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            _IActMLSIMEvents __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            _IActMLSIMEvents __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        END_INTERFACE
    } _IActMLSIMEventsVtbl;

    interface _IActMLSIMEvents
    {
        CONST_VTBL struct _IActMLSIMEventsVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _IActMLSIMEvents_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define _IActMLSIMEvents_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define _IActMLSIMEvents_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define _IActMLSIMEvents_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define _IActMLSIMEvents_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define _IActMLSIMEvents_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define _IActMLSIMEvents_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ___IActMLSIMEvents_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_ActMLSIM;

#ifdef __cplusplus

class DECLSPEC_UUID("CF317B9B-82CF-4803-99C0-7BB906E0C737")
ActMLSIM;
#endif
#endif /* __ACTLLTLib_LIBRARY_DEFINED__ */

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
