/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 5.01.0164 */
/* at Fri Apr 12 12:31:39 2013
 */
/* Compiler settings for D:\GETMODULE\CommunicationSupport2\SW3D5\ACT\Control\ActGOT\ActGOT.idl:
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

#ifndef __ActGOT_h__
#define __ActGOT_h__

#ifdef __cplusplus
extern "C"{
#endif 

/* Forward Declarations */ 

#ifndef __IActGOT_FWD_DEFINED__
#define __IActGOT_FWD_DEFINED__
typedef interface IActGOT IActGOT;
#endif 	/* __IActGOT_FWD_DEFINED__ */


#ifndef __IActGOT2_FWD_DEFINED__
#define __IActGOT2_FWD_DEFINED__
typedef interface IActGOT2 IActGOT2;
#endif 	/* __IActGOT2_FWD_DEFINED__ */


#ifndef __IActGOT3_FWD_DEFINED__
#define __IActGOT3_FWD_DEFINED__
typedef interface IActGOT3 IActGOT3;
#endif 	/* __IActGOT3_FWD_DEFINED__ */


#ifndef __IActMLGOT_FWD_DEFINED__
#define __IActMLGOT_FWD_DEFINED__
typedef interface IActMLGOT IActMLGOT;
#endif 	/* __IActMLGOT_FWD_DEFINED__ */


#ifndef __IActMLGOT2_FWD_DEFINED__
#define __IActMLGOT2_FWD_DEFINED__
typedef interface IActMLGOT2 IActMLGOT2;
#endif 	/* __IActMLGOT2_FWD_DEFINED__ */


#ifndef __IActMLGOT3_FWD_DEFINED__
#define __IActMLGOT3_FWD_DEFINED__
typedef interface IActMLGOT3 IActMLGOT3;
#endif 	/* __IActMLGOT3_FWD_DEFINED__ */


#ifndef __IActGOTTRSP_FWD_DEFINED__
#define __IActGOTTRSP_FWD_DEFINED__
typedef interface IActGOTTRSP IActGOTTRSP;
#endif 	/* __IActGOTTRSP_FWD_DEFINED__ */


#ifndef __IActGOTTRSP2_FWD_DEFINED__
#define __IActGOTTRSP2_FWD_DEFINED__
typedef interface IActGOTTRSP2 IActGOTTRSP2;
#endif 	/* __IActGOTTRSP2_FWD_DEFINED__ */


#ifndef __IActGOTTRSP3_FWD_DEFINED__
#define __IActGOTTRSP3_FWD_DEFINED__
typedef interface IActGOTTRSP3 IActGOTTRSP3;
#endif 	/* __IActGOTTRSP3_FWD_DEFINED__ */


#ifndef __IActMLGOTTRSP_FWD_DEFINED__
#define __IActMLGOTTRSP_FWD_DEFINED__
typedef interface IActMLGOTTRSP IActMLGOTTRSP;
#endif 	/* __IActMLGOTTRSP_FWD_DEFINED__ */


#ifndef __IActMLGOTTRSP2_FWD_DEFINED__
#define __IActMLGOTTRSP2_FWD_DEFINED__
typedef interface IActMLGOTTRSP2 IActMLGOTTRSP2;
#endif 	/* __IActMLGOTTRSP2_FWD_DEFINED__ */


#ifndef __IActMLGOTTRSP3_FWD_DEFINED__
#define __IActMLGOTTRSP3_FWD_DEFINED__
typedef interface IActMLGOTTRSP3 IActMLGOTTRSP3;
#endif 	/* __IActMLGOTTRSP3_FWD_DEFINED__ */


#ifndef ___IActGOTEvents_FWD_DEFINED__
#define ___IActGOTEvents_FWD_DEFINED__
typedef interface _IActGOTEvents _IActGOTEvents;
#endif 	/* ___IActGOTEvents_FWD_DEFINED__ */


#ifndef __ActGOT_FWD_DEFINED__
#define __ActGOT_FWD_DEFINED__

#ifdef __cplusplus
typedef class ActGOT ActGOT;
#else
typedef struct ActGOT ActGOT;
#endif /* __cplusplus */

#endif 	/* __ActGOT_FWD_DEFINED__ */


#ifndef ___IActMLGOTEvents_FWD_DEFINED__
#define ___IActMLGOTEvents_FWD_DEFINED__
typedef interface _IActMLGOTEvents _IActMLGOTEvents;
#endif 	/* ___IActMLGOTEvents_FWD_DEFINED__ */


#ifndef __ActMLGOT_FWD_DEFINED__
#define __ActMLGOT_FWD_DEFINED__

#ifdef __cplusplus
typedef class ActMLGOT ActMLGOT;
#else
typedef struct ActMLGOT ActMLGOT;
#endif /* __cplusplus */

#endif 	/* __ActMLGOT_FWD_DEFINED__ */


#ifndef ___IActGOTTRSPEvents_FWD_DEFINED__
#define ___IActGOTTRSPEvents_FWD_DEFINED__
typedef interface _IActGOTTRSPEvents _IActGOTTRSPEvents;
#endif 	/* ___IActGOTTRSPEvents_FWD_DEFINED__ */


#ifndef __ActGOTTRSP_FWD_DEFINED__
#define __ActGOTTRSP_FWD_DEFINED__

#ifdef __cplusplus
typedef class ActGOTTRSP ActGOTTRSP;
#else
typedef struct ActGOTTRSP ActGOTTRSP;
#endif /* __cplusplus */

#endif 	/* __ActGOTTRSP_FWD_DEFINED__ */


#ifndef ___IActMLGOTTRSPEvents_FWD_DEFINED__
#define ___IActMLGOTTRSPEvents_FWD_DEFINED__
typedef interface _IActMLGOTTRSPEvents _IActMLGOTTRSPEvents;
#endif 	/* ___IActMLGOTTRSPEvents_FWD_DEFINED__ */


#ifndef __ActMLGOTTRSP_FWD_DEFINED__
#define __ActMLGOTTRSP_FWD_DEFINED__

#ifdef __cplusplus
typedef class ActMLGOTTRSP ActMLGOTTRSP;
#else
typedef struct ActMLGOTTRSP ActMLGOTTRSP;
#endif /* __cplusplus */

#endif 	/* __ActMLGOTTRSP_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

void __RPC_FAR * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void __RPC_FAR * ); 

#ifndef __IActGOT_INTERFACE_DEFINED__
#define __IActGOT_INTERFACE_DEFINED__

/* interface IActGOT */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IActGOT;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("FB32741E-7044-11D5-9316-009099244EFD")
    IActGOT : public IDispatch
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
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetCpuType( 
            /* [string][out] */ BSTR __RPC_FAR *szCpuName,
            /* [out] */ LONG __RPC_FAR *lplCpuCode,
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
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActPortNumber( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActPortNumber( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActHostAddress( 
            /* [retval][out] */ BSTR __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActHostAddress( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActTimeOut( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActTimeOut( 
            /* [in] */ long newVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IActGOTVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IActGOT __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IActGOT __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IActGOT __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IActGOT __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IActGOT __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IActGOT __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IActGOT __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Open )( 
            IActGOT __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Close )( 
            IActGOT __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetDevice )( 
            IActGOT __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [out] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetDevice )( 
            IActGOT __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceBlock )( 
            IActGOT __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lSize,
            /* [size_is][out] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceBlock )( 
            IActGOT __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lSize,
            /* [size_is][in] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceRandom )( 
            IActGOT __RPC_FAR * This,
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG lSize,
            /* [size_is][out] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceRandom )( 
            IActGOT __RPC_FAR * This,
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG lSize,
            /* [size_is][in] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetCpuType )( 
            IActGOT __RPC_FAR * This,
            /* [string][out] */ BSTR __RPC_FAR *szCpuName,
            /* [out] */ LONG __RPC_FAR *lplCpuCode,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CheckDeviceString )( 
            IActGOT __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lCheckType,
            /* [in] */ LONG lSize,
            /* [out] */ LONG __RPC_FAR *lplDeviceType,
            /* [string][out] */ BSTR __RPC_FAR *lpszDeviceName,
            /* [out] */ LONG __RPC_FAR *lplDeviceNumber,
            /* [out] */ LONG __RPC_FAR *lplDeviceRadix,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *EntryDeviceStatus )( 
            IActGOT __RPC_FAR * This,
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG lSize,
            /* [in] */ LONG lMonitorCycle,
            /* [size_is][in] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *FreeDeviceStatus )( 
            IActGOT __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceBlock2 )( 
            IActGOT __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lSize,
            /* [size_is][out] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceBlock2 )( 
            IActGOT __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lSize,
            /* [size_is][in] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceRandom2 )( 
            IActGOT __RPC_FAR * This,
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG lSize,
            /* [size_is][out] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceRandom2 )( 
            IActGOT __RPC_FAR * This,
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG lSize,
            /* [size_is][in] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetDevice2 )( 
            IActGOT __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [out] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetDevice2 )( 
            IActGOT __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ SHORT sData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActPortNumber )( 
            IActGOT __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActPortNumber )( 
            IActGOT __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActHostAddress )( 
            IActGOT __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActHostAddress )( 
            IActGOT __RPC_FAR * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActTimeOut )( 
            IActGOT __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActTimeOut )( 
            IActGOT __RPC_FAR * This,
            /* [in] */ long newVal);
        
        END_INTERFACE
    } IActGOTVtbl;

    interface IActGOT
    {
        CONST_VTBL struct IActGOTVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IActGOT_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IActGOT_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IActGOT_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IActGOT_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IActGOT_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IActGOT_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IActGOT_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IActGOT_Open(This,lplReturnCode)	\
    (This)->lpVtbl -> Open(This,lplReturnCode)

#define IActGOT_Close(This,lplReturnCode)	\
    (This)->lpVtbl -> Close(This,lplReturnCode)

#define IActGOT_GetDevice(This,szDevice,lplData,lplReturnCode)	\
    (This)->lpVtbl -> GetDevice(This,szDevice,lplData,lplReturnCode)

#define IActGOT_SetDevice(This,szDevice,lData,lplReturnCode)	\
    (This)->lpVtbl -> SetDevice(This,szDevice,lData,lplReturnCode)

#define IActGOT_ReadDeviceBlock(This,szDevice,lSize,lplData,lplReturnCode)	\
    (This)->lpVtbl -> ReadDeviceBlock(This,szDevice,lSize,lplData,lplReturnCode)

#define IActGOT_WriteDeviceBlock(This,szDevice,lSize,lplData,lplReturnCode)	\
    (This)->lpVtbl -> WriteDeviceBlock(This,szDevice,lSize,lplData,lplReturnCode)

#define IActGOT_ReadDeviceRandom(This,szDeviceList,lSize,lplData,lplReturnCode)	\
    (This)->lpVtbl -> ReadDeviceRandom(This,szDeviceList,lSize,lplData,lplReturnCode)

#define IActGOT_WriteDeviceRandom(This,szDeviceList,lSize,lplData,lplReturnCode)	\
    (This)->lpVtbl -> WriteDeviceRandom(This,szDeviceList,lSize,lplData,lplReturnCode)

#define IActGOT_GetCpuType(This,szCpuName,lplCpuCode,lplReturnCode)	\
    (This)->lpVtbl -> GetCpuType(This,szCpuName,lplCpuCode,lplReturnCode)

#define IActGOT_CheckDeviceString(This,szDevice,lCheckType,lSize,lplDeviceType,lpszDeviceName,lplDeviceNumber,lplDeviceRadix,lplReturnCode)	\
    (This)->lpVtbl -> CheckDeviceString(This,szDevice,lCheckType,lSize,lplDeviceType,lpszDeviceName,lplDeviceNumber,lplDeviceRadix,lplReturnCode)

#define IActGOT_EntryDeviceStatus(This,szDeviceList,lSize,lMonitorCycle,lplData,lplReturnCode)	\
    (This)->lpVtbl -> EntryDeviceStatus(This,szDeviceList,lSize,lMonitorCycle,lplData,lplReturnCode)

#define IActGOT_FreeDeviceStatus(This,lplReturnCode)	\
    (This)->lpVtbl -> FreeDeviceStatus(This,lplReturnCode)

#define IActGOT_ReadDeviceBlock2(This,szDevice,lSize,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> ReadDeviceBlock2(This,szDevice,lSize,lpsData,lplReturnCode)

#define IActGOT_WriteDeviceBlock2(This,szDevice,lSize,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> WriteDeviceBlock2(This,szDevice,lSize,lpsData,lplReturnCode)

#define IActGOT_ReadDeviceRandom2(This,szDeviceList,lSize,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> ReadDeviceRandom2(This,szDeviceList,lSize,lpsData,lplReturnCode)

#define IActGOT_WriteDeviceRandom2(This,szDeviceList,lSize,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> WriteDeviceRandom2(This,szDeviceList,lSize,lpsData,lplReturnCode)

#define IActGOT_GetDevice2(This,szDevice,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> GetDevice2(This,szDevice,lpsData,lplReturnCode)

#define IActGOT_SetDevice2(This,szDevice,sData,lplReturnCode)	\
    (This)->lpVtbl -> SetDevice2(This,szDevice,sData,lplReturnCode)

#define IActGOT_get_ActPortNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActPortNumber(This,pVal)

#define IActGOT_put_ActPortNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActPortNumber(This,newVal)

#define IActGOT_get_ActHostAddress(This,pVal)	\
    (This)->lpVtbl -> get_ActHostAddress(This,pVal)

#define IActGOT_put_ActHostAddress(This,newVal)	\
    (This)->lpVtbl -> put_ActHostAddress(This,newVal)

#define IActGOT_get_ActTimeOut(This,pVal)	\
    (This)->lpVtbl -> get_ActTimeOut(This,pVal)

#define IActGOT_put_ActTimeOut(This,newVal)	\
    (This)->lpVtbl -> put_ActTimeOut(This,newVal)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActGOT_Open_Proxy( 
    IActGOT __RPC_FAR * This,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActGOT_Open_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActGOT_Close_Proxy( 
    IActGOT __RPC_FAR * This,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActGOT_Close_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActGOT_GetDevice_Proxy( 
    IActGOT __RPC_FAR * This,
    /* [string][in] */ BSTR szDevice,
    /* [out] */ LONG __RPC_FAR *lplData,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActGOT_GetDevice_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActGOT_SetDevice_Proxy( 
    IActGOT __RPC_FAR * This,
    /* [string][in] */ BSTR szDevice,
    /* [in] */ LONG lData,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActGOT_SetDevice_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActGOT_ReadDeviceBlock_Proxy( 
    IActGOT __RPC_FAR * This,
    /* [string][in] */ BSTR szDevice,
    /* [in] */ LONG lSize,
    /* [size_is][out] */ LONG __RPC_FAR *lplData,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActGOT_ReadDeviceBlock_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActGOT_WriteDeviceBlock_Proxy( 
    IActGOT __RPC_FAR * This,
    /* [string][in] */ BSTR szDevice,
    /* [in] */ LONG lSize,
    /* [size_is][in] */ LONG __RPC_FAR *lplData,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActGOT_WriteDeviceBlock_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActGOT_ReadDeviceRandom_Proxy( 
    IActGOT __RPC_FAR * This,
    /* [string][in] */ BSTR szDeviceList,
    /* [in] */ LONG lSize,
    /* [size_is][out] */ LONG __RPC_FAR *lplData,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActGOT_ReadDeviceRandom_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActGOT_WriteDeviceRandom_Proxy( 
    IActGOT __RPC_FAR * This,
    /* [string][in] */ BSTR szDeviceList,
    /* [in] */ LONG lSize,
    /* [size_is][in] */ LONG __RPC_FAR *lplData,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActGOT_WriteDeviceRandom_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActGOT_GetCpuType_Proxy( 
    IActGOT __RPC_FAR * This,
    /* [string][out] */ BSTR __RPC_FAR *szCpuName,
    /* [out] */ LONG __RPC_FAR *lplCpuCode,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActGOT_GetCpuType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActGOT_CheckDeviceString_Proxy( 
    IActGOT __RPC_FAR * This,
    /* [string][in] */ BSTR szDevice,
    /* [in] */ LONG lCheckType,
    /* [in] */ LONG lSize,
    /* [out] */ LONG __RPC_FAR *lplDeviceType,
    /* [string][out] */ BSTR __RPC_FAR *lpszDeviceName,
    /* [out] */ LONG __RPC_FAR *lplDeviceNumber,
    /* [out] */ LONG __RPC_FAR *lplDeviceRadix,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActGOT_CheckDeviceString_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActGOT_EntryDeviceStatus_Proxy( 
    IActGOT __RPC_FAR * This,
    /* [string][in] */ BSTR szDeviceList,
    /* [in] */ LONG lSize,
    /* [in] */ LONG lMonitorCycle,
    /* [size_is][in] */ LONG __RPC_FAR *lplData,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActGOT_EntryDeviceStatus_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActGOT_FreeDeviceStatus_Proxy( 
    IActGOT __RPC_FAR * This,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActGOT_FreeDeviceStatus_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActGOT_ReadDeviceBlock2_Proxy( 
    IActGOT __RPC_FAR * This,
    /* [string][in] */ BSTR szDevice,
    /* [in] */ LONG lSize,
    /* [size_is][out] */ SHORT __RPC_FAR *lpsData,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActGOT_ReadDeviceBlock2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActGOT_WriteDeviceBlock2_Proxy( 
    IActGOT __RPC_FAR * This,
    /* [string][in] */ BSTR szDevice,
    /* [in] */ LONG lSize,
    /* [size_is][in] */ SHORT __RPC_FAR *lpsData,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActGOT_WriteDeviceBlock2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActGOT_ReadDeviceRandom2_Proxy( 
    IActGOT __RPC_FAR * This,
    /* [string][in] */ BSTR szDeviceList,
    /* [in] */ LONG lSize,
    /* [size_is][out] */ SHORT __RPC_FAR *lpsData,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActGOT_ReadDeviceRandom2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActGOT_WriteDeviceRandom2_Proxy( 
    IActGOT __RPC_FAR * This,
    /* [string][in] */ BSTR szDeviceList,
    /* [in] */ LONG lSize,
    /* [size_is][in] */ SHORT __RPC_FAR *lpsData,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActGOT_WriteDeviceRandom2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActGOT_GetDevice2_Proxy( 
    IActGOT __RPC_FAR * This,
    /* [string][in] */ BSTR szDevice,
    /* [out] */ SHORT __RPC_FAR *lpsData,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActGOT_GetDevice2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActGOT_SetDevice2_Proxy( 
    IActGOT __RPC_FAR * This,
    /* [string][in] */ BSTR szDevice,
    /* [in] */ SHORT sData,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActGOT_SetDevice2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActGOT_get_ActPortNumber_Proxy( 
    IActGOT __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IActGOT_get_ActPortNumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActGOT_put_ActPortNumber_Proxy( 
    IActGOT __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB IActGOT_put_ActPortNumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActGOT_get_ActHostAddress_Proxy( 
    IActGOT __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *pVal);


void __RPC_STUB IActGOT_get_ActHostAddress_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActGOT_put_ActHostAddress_Proxy( 
    IActGOT __RPC_FAR * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB IActGOT_put_ActHostAddress_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActGOT_get_ActTimeOut_Proxy( 
    IActGOT __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IActGOT_get_ActTimeOut_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActGOT_put_ActTimeOut_Proxy( 
    IActGOT __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB IActGOT_put_ActTimeOut_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IActGOT_INTERFACE_DEFINED__ */


#ifndef __IActGOT2_INTERFACE_DEFINED__
#define __IActGOT2_INTERFACE_DEFINED__

/* interface IActGOT2 */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IActGOT2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("87166046-710B-11d5-9318-009099244EFD")
    IActGOT2 : public IActGOT
    {
    public:
    };
    
#else 	/* C style interface */

    typedef struct IActGOT2Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IActGOT2 __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IActGOT2 __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IActGOT2 __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IActGOT2 __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IActGOT2 __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IActGOT2 __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IActGOT2 __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Open )( 
            IActGOT2 __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Close )( 
            IActGOT2 __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetDevice )( 
            IActGOT2 __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [out] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetDevice )( 
            IActGOT2 __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceBlock )( 
            IActGOT2 __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lSize,
            /* [size_is][out] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceBlock )( 
            IActGOT2 __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lSize,
            /* [size_is][in] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceRandom )( 
            IActGOT2 __RPC_FAR * This,
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG lSize,
            /* [size_is][out] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceRandom )( 
            IActGOT2 __RPC_FAR * This,
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG lSize,
            /* [size_is][in] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetCpuType )( 
            IActGOT2 __RPC_FAR * This,
            /* [string][out] */ BSTR __RPC_FAR *szCpuName,
            /* [out] */ LONG __RPC_FAR *lplCpuCode,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CheckDeviceString )( 
            IActGOT2 __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lCheckType,
            /* [in] */ LONG lSize,
            /* [out] */ LONG __RPC_FAR *lplDeviceType,
            /* [string][out] */ BSTR __RPC_FAR *lpszDeviceName,
            /* [out] */ LONG __RPC_FAR *lplDeviceNumber,
            /* [out] */ LONG __RPC_FAR *lplDeviceRadix,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *EntryDeviceStatus )( 
            IActGOT2 __RPC_FAR * This,
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG lSize,
            /* [in] */ LONG lMonitorCycle,
            /* [size_is][in] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *FreeDeviceStatus )( 
            IActGOT2 __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceBlock2 )( 
            IActGOT2 __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lSize,
            /* [size_is][out] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceBlock2 )( 
            IActGOT2 __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lSize,
            /* [size_is][in] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceRandom2 )( 
            IActGOT2 __RPC_FAR * This,
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG lSize,
            /* [size_is][out] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceRandom2 )( 
            IActGOT2 __RPC_FAR * This,
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG lSize,
            /* [size_is][in] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetDevice2 )( 
            IActGOT2 __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [out] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetDevice2 )( 
            IActGOT2 __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ SHORT sData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActPortNumber )( 
            IActGOT2 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActPortNumber )( 
            IActGOT2 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActHostAddress )( 
            IActGOT2 __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActHostAddress )( 
            IActGOT2 __RPC_FAR * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActTimeOut )( 
            IActGOT2 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActTimeOut )( 
            IActGOT2 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        END_INTERFACE
    } IActGOT2Vtbl;

    interface IActGOT2
    {
        CONST_VTBL struct IActGOT2Vtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IActGOT2_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IActGOT2_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IActGOT2_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IActGOT2_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IActGOT2_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IActGOT2_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IActGOT2_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IActGOT2_Open(This,lplReturnCode)	\
    (This)->lpVtbl -> Open(This,lplReturnCode)

#define IActGOT2_Close(This,lplReturnCode)	\
    (This)->lpVtbl -> Close(This,lplReturnCode)

#define IActGOT2_GetDevice(This,szDevice,lplData,lplReturnCode)	\
    (This)->lpVtbl -> GetDevice(This,szDevice,lplData,lplReturnCode)

#define IActGOT2_SetDevice(This,szDevice,lData,lplReturnCode)	\
    (This)->lpVtbl -> SetDevice(This,szDevice,lData,lplReturnCode)

#define IActGOT2_ReadDeviceBlock(This,szDevice,lSize,lplData,lplReturnCode)	\
    (This)->lpVtbl -> ReadDeviceBlock(This,szDevice,lSize,lplData,lplReturnCode)

#define IActGOT2_WriteDeviceBlock(This,szDevice,lSize,lplData,lplReturnCode)	\
    (This)->lpVtbl -> WriteDeviceBlock(This,szDevice,lSize,lplData,lplReturnCode)

#define IActGOT2_ReadDeviceRandom(This,szDeviceList,lSize,lplData,lplReturnCode)	\
    (This)->lpVtbl -> ReadDeviceRandom(This,szDeviceList,lSize,lplData,lplReturnCode)

#define IActGOT2_WriteDeviceRandom(This,szDeviceList,lSize,lplData,lplReturnCode)	\
    (This)->lpVtbl -> WriteDeviceRandom(This,szDeviceList,lSize,lplData,lplReturnCode)

#define IActGOT2_GetCpuType(This,szCpuName,lplCpuCode,lplReturnCode)	\
    (This)->lpVtbl -> GetCpuType(This,szCpuName,lplCpuCode,lplReturnCode)

#define IActGOT2_CheckDeviceString(This,szDevice,lCheckType,lSize,lplDeviceType,lpszDeviceName,lplDeviceNumber,lplDeviceRadix,lplReturnCode)	\
    (This)->lpVtbl -> CheckDeviceString(This,szDevice,lCheckType,lSize,lplDeviceType,lpszDeviceName,lplDeviceNumber,lplDeviceRadix,lplReturnCode)

#define IActGOT2_EntryDeviceStatus(This,szDeviceList,lSize,lMonitorCycle,lplData,lplReturnCode)	\
    (This)->lpVtbl -> EntryDeviceStatus(This,szDeviceList,lSize,lMonitorCycle,lplData,lplReturnCode)

#define IActGOT2_FreeDeviceStatus(This,lplReturnCode)	\
    (This)->lpVtbl -> FreeDeviceStatus(This,lplReturnCode)

#define IActGOT2_ReadDeviceBlock2(This,szDevice,lSize,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> ReadDeviceBlock2(This,szDevice,lSize,lpsData,lplReturnCode)

#define IActGOT2_WriteDeviceBlock2(This,szDevice,lSize,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> WriteDeviceBlock2(This,szDevice,lSize,lpsData,lplReturnCode)

#define IActGOT2_ReadDeviceRandom2(This,szDeviceList,lSize,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> ReadDeviceRandom2(This,szDeviceList,lSize,lpsData,lplReturnCode)

#define IActGOT2_WriteDeviceRandom2(This,szDeviceList,lSize,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> WriteDeviceRandom2(This,szDeviceList,lSize,lpsData,lplReturnCode)

#define IActGOT2_GetDevice2(This,szDevice,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> GetDevice2(This,szDevice,lpsData,lplReturnCode)

#define IActGOT2_SetDevice2(This,szDevice,sData,lplReturnCode)	\
    (This)->lpVtbl -> SetDevice2(This,szDevice,sData,lplReturnCode)

#define IActGOT2_get_ActPortNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActPortNumber(This,pVal)

#define IActGOT2_put_ActPortNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActPortNumber(This,newVal)

#define IActGOT2_get_ActHostAddress(This,pVal)	\
    (This)->lpVtbl -> get_ActHostAddress(This,pVal)

#define IActGOT2_put_ActHostAddress(This,newVal)	\
    (This)->lpVtbl -> put_ActHostAddress(This,newVal)

#define IActGOT2_get_ActTimeOut(This,pVal)	\
    (This)->lpVtbl -> get_ActTimeOut(This,pVal)

#define IActGOT2_put_ActTimeOut(This,newVal)	\
    (This)->lpVtbl -> put_ActTimeOut(This,newVal)


#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IActGOT2_INTERFACE_DEFINED__ */


#ifndef __IActGOT3_INTERFACE_DEFINED__
#define __IActGOT3_INTERFACE_DEFINED__

/* interface IActGOT3 */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IActGOT3;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("87166047-710B-11d5-9318-009099244EFD")
    IActGOT3 : public IActGOT2
    {
    public:
    };
    
#else 	/* C style interface */

    typedef struct IActGOT3Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IActGOT3 __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IActGOT3 __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IActGOT3 __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IActGOT3 __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IActGOT3 __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IActGOT3 __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IActGOT3 __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Open )( 
            IActGOT3 __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Close )( 
            IActGOT3 __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetDevice )( 
            IActGOT3 __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [out] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetDevice )( 
            IActGOT3 __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceBlock )( 
            IActGOT3 __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lSize,
            /* [size_is][out] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceBlock )( 
            IActGOT3 __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lSize,
            /* [size_is][in] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceRandom )( 
            IActGOT3 __RPC_FAR * This,
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG lSize,
            /* [size_is][out] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceRandom )( 
            IActGOT3 __RPC_FAR * This,
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG lSize,
            /* [size_is][in] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetCpuType )( 
            IActGOT3 __RPC_FAR * This,
            /* [string][out] */ BSTR __RPC_FAR *szCpuName,
            /* [out] */ LONG __RPC_FAR *lplCpuCode,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CheckDeviceString )( 
            IActGOT3 __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lCheckType,
            /* [in] */ LONG lSize,
            /* [out] */ LONG __RPC_FAR *lplDeviceType,
            /* [string][out] */ BSTR __RPC_FAR *lpszDeviceName,
            /* [out] */ LONG __RPC_FAR *lplDeviceNumber,
            /* [out] */ LONG __RPC_FAR *lplDeviceRadix,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *EntryDeviceStatus )( 
            IActGOT3 __RPC_FAR * This,
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG lSize,
            /* [in] */ LONG lMonitorCycle,
            /* [size_is][in] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *FreeDeviceStatus )( 
            IActGOT3 __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceBlock2 )( 
            IActGOT3 __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lSize,
            /* [size_is][out] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceBlock2 )( 
            IActGOT3 __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lSize,
            /* [size_is][in] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceRandom2 )( 
            IActGOT3 __RPC_FAR * This,
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG lSize,
            /* [size_is][out] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceRandom2 )( 
            IActGOT3 __RPC_FAR * This,
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG lSize,
            /* [size_is][in] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetDevice2 )( 
            IActGOT3 __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [out] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetDevice2 )( 
            IActGOT3 __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ SHORT sData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActPortNumber )( 
            IActGOT3 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActPortNumber )( 
            IActGOT3 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActHostAddress )( 
            IActGOT3 __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActHostAddress )( 
            IActGOT3 __RPC_FAR * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActTimeOut )( 
            IActGOT3 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActTimeOut )( 
            IActGOT3 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        END_INTERFACE
    } IActGOT3Vtbl;

    interface IActGOT3
    {
        CONST_VTBL struct IActGOT3Vtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IActGOT3_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IActGOT3_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IActGOT3_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IActGOT3_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IActGOT3_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IActGOT3_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IActGOT3_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IActGOT3_Open(This,lplReturnCode)	\
    (This)->lpVtbl -> Open(This,lplReturnCode)

#define IActGOT3_Close(This,lplReturnCode)	\
    (This)->lpVtbl -> Close(This,lplReturnCode)

#define IActGOT3_GetDevice(This,szDevice,lplData,lplReturnCode)	\
    (This)->lpVtbl -> GetDevice(This,szDevice,lplData,lplReturnCode)

#define IActGOT3_SetDevice(This,szDevice,lData,lplReturnCode)	\
    (This)->lpVtbl -> SetDevice(This,szDevice,lData,lplReturnCode)

#define IActGOT3_ReadDeviceBlock(This,szDevice,lSize,lplData,lplReturnCode)	\
    (This)->lpVtbl -> ReadDeviceBlock(This,szDevice,lSize,lplData,lplReturnCode)

#define IActGOT3_WriteDeviceBlock(This,szDevice,lSize,lplData,lplReturnCode)	\
    (This)->lpVtbl -> WriteDeviceBlock(This,szDevice,lSize,lplData,lplReturnCode)

#define IActGOT3_ReadDeviceRandom(This,szDeviceList,lSize,lplData,lplReturnCode)	\
    (This)->lpVtbl -> ReadDeviceRandom(This,szDeviceList,lSize,lplData,lplReturnCode)

#define IActGOT3_WriteDeviceRandom(This,szDeviceList,lSize,lplData,lplReturnCode)	\
    (This)->lpVtbl -> WriteDeviceRandom(This,szDeviceList,lSize,lplData,lplReturnCode)

#define IActGOT3_GetCpuType(This,szCpuName,lplCpuCode,lplReturnCode)	\
    (This)->lpVtbl -> GetCpuType(This,szCpuName,lplCpuCode,lplReturnCode)

#define IActGOT3_CheckDeviceString(This,szDevice,lCheckType,lSize,lplDeviceType,lpszDeviceName,lplDeviceNumber,lplDeviceRadix,lplReturnCode)	\
    (This)->lpVtbl -> CheckDeviceString(This,szDevice,lCheckType,lSize,lplDeviceType,lpszDeviceName,lplDeviceNumber,lplDeviceRadix,lplReturnCode)

#define IActGOT3_EntryDeviceStatus(This,szDeviceList,lSize,lMonitorCycle,lplData,lplReturnCode)	\
    (This)->lpVtbl -> EntryDeviceStatus(This,szDeviceList,lSize,lMonitorCycle,lplData,lplReturnCode)

#define IActGOT3_FreeDeviceStatus(This,lplReturnCode)	\
    (This)->lpVtbl -> FreeDeviceStatus(This,lplReturnCode)

#define IActGOT3_ReadDeviceBlock2(This,szDevice,lSize,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> ReadDeviceBlock2(This,szDevice,lSize,lpsData,lplReturnCode)

#define IActGOT3_WriteDeviceBlock2(This,szDevice,lSize,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> WriteDeviceBlock2(This,szDevice,lSize,lpsData,lplReturnCode)

#define IActGOT3_ReadDeviceRandom2(This,szDeviceList,lSize,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> ReadDeviceRandom2(This,szDeviceList,lSize,lpsData,lplReturnCode)

#define IActGOT3_WriteDeviceRandom2(This,szDeviceList,lSize,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> WriteDeviceRandom2(This,szDeviceList,lSize,lpsData,lplReturnCode)

#define IActGOT3_GetDevice2(This,szDevice,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> GetDevice2(This,szDevice,lpsData,lplReturnCode)

#define IActGOT3_SetDevice2(This,szDevice,sData,lplReturnCode)	\
    (This)->lpVtbl -> SetDevice2(This,szDevice,sData,lplReturnCode)

#define IActGOT3_get_ActPortNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActPortNumber(This,pVal)

#define IActGOT3_put_ActPortNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActPortNumber(This,newVal)

#define IActGOT3_get_ActHostAddress(This,pVal)	\
    (This)->lpVtbl -> get_ActHostAddress(This,pVal)

#define IActGOT3_put_ActHostAddress(This,newVal)	\
    (This)->lpVtbl -> put_ActHostAddress(This,newVal)

#define IActGOT3_get_ActTimeOut(This,pVal)	\
    (This)->lpVtbl -> get_ActTimeOut(This,pVal)

#define IActGOT3_put_ActTimeOut(This,newVal)	\
    (This)->lpVtbl -> put_ActTimeOut(This,newVal)



#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IActGOT3_INTERFACE_DEFINED__ */


#ifndef __IActMLGOT_INTERFACE_DEFINED__
#define __IActMLGOT_INTERFACE_DEFINED__

/* interface IActMLGOT */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IActMLGOT;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("FB327421-7044-11D5-9316-009099244EFD")
    IActMLGOT : public IDispatch
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
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActPortNumber( 
            /* [retval][out] */ VARIANT __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActPortNumber( 
            /* [in] */ VARIANT newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActHostAddress( 
            /* [retval][out] */ VARIANT __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActHostAddress( 
            /* [in] */ VARIANT newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActTimeOut( 
            /* [retval][out] */ VARIANT __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActTimeOut( 
            /* [in] */ VARIANT newVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IActMLGOTVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IActMLGOT __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IActMLGOT __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IActMLGOT __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IActMLGOT __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IActMLGOT __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IActMLGOT __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IActMLGOT __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Open )( 
            IActMLGOT __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Close )( 
            IActMLGOT __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetDevice )( 
            IActMLGOT __RPC_FAR * This,
            /* [in] */ VARIANT varDevice,
            /* [out] */ VARIANT __RPC_FAR *lpvarData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetDevice )( 
            IActMLGOT __RPC_FAR * This,
            /* [in] */ VARIANT varDevice,
            /* [in] */ VARIANT varData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceBlock )( 
            IActMLGOT __RPC_FAR * This,
            /* [in] */ VARIANT varDevice,
            /* [in] */ VARIANT varSize,
            /* [out] */ VARIANT __RPC_FAR *lpvarData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceBlock )( 
            IActMLGOT __RPC_FAR * This,
            /* [in] */ VARIANT varDevice,
            /* [in] */ VARIANT varSize,
            /* [in] */ VARIANT varData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceRandom )( 
            IActMLGOT __RPC_FAR * This,
            /* [in] */ VARIANT varDeviceList,
            /* [in] */ VARIANT varSize,
            /* [out] */ VARIANT __RPC_FAR *lpvarData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceRandom )( 
            IActMLGOT __RPC_FAR * This,
            /* [in] */ VARIANT varDeviceList,
            /* [in] */ VARIANT varSize,
            /* [in] */ VARIANT varData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetCpuType )( 
            IActMLGOT __RPC_FAR * This,
            /* [out] */ VARIANT __RPC_FAR *lpvarCpuName,
            /* [out] */ VARIANT __RPC_FAR *lpvarCpuType,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *EntryDeviceStatus )( 
            IActMLGOT __RPC_FAR * This,
            /* [in] */ VARIANT varDeviceList,
            /* [in] */ VARIANT varSize,
            /* [in] */ VARIANT varMonitorCycle,
            /* [in] */ VARIANT varData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *FreeDeviceStatus )( 
            IActMLGOT __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceBlock2 )( 
            IActMLGOT __RPC_FAR * This,
            /* [in] */ VARIANT varDevice,
            /* [in] */ VARIANT varSize,
            /* [out] */ VARIANT __RPC_FAR *lpvarData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceBlock2 )( 
            IActMLGOT __RPC_FAR * This,
            /* [in] */ VARIANT varDevice,
            /* [in] */ VARIANT varSize,
            /* [in] */ VARIANT varData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceRandom2 )( 
            IActMLGOT __RPC_FAR * This,
            /* [in] */ VARIANT varDeviceList,
            /* [in] */ VARIANT varSize,
            /* [out] */ VARIANT __RPC_FAR *lpvarData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceRandom2 )( 
            IActMLGOT __RPC_FAR * This,
            /* [in] */ VARIANT varDeviceList,
            /* [in] */ VARIANT varSize,
            /* [in] */ VARIANT varData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetDevice2 )( 
            IActMLGOT __RPC_FAR * This,
            /* [in] */ VARIANT varDevice,
            /* [out] */ VARIANT __RPC_FAR *lpvarData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetDevice2 )( 
            IActMLGOT __RPC_FAR * This,
            /* [in] */ VARIANT varDevice,
            /* [in] */ VARIANT varData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActPortNumber )( 
            IActMLGOT __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActPortNumber )( 
            IActMLGOT __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActHostAddress )( 
            IActMLGOT __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActHostAddress )( 
            IActMLGOT __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActTimeOut )( 
            IActMLGOT __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActTimeOut )( 
            IActMLGOT __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        END_INTERFACE
    } IActMLGOTVtbl;

    interface IActMLGOT
    {
        CONST_VTBL struct IActMLGOTVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IActMLGOT_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IActMLGOT_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IActMLGOT_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IActMLGOT_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IActMLGOT_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IActMLGOT_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IActMLGOT_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IActMLGOT_Open(This,lpvarReturnCode)	\
    (This)->lpVtbl -> Open(This,lpvarReturnCode)

#define IActMLGOT_Close(This,lpvarReturnCode)	\
    (This)->lpVtbl -> Close(This,lpvarReturnCode)

#define IActMLGOT_GetDevice(This,varDevice,lpvarData,lpvarReturnCode)	\
    (This)->lpVtbl -> GetDevice(This,varDevice,lpvarData,lpvarReturnCode)

#define IActMLGOT_SetDevice(This,varDevice,varData,lpvarReturnCode)	\
    (This)->lpVtbl -> SetDevice(This,varDevice,varData,lpvarReturnCode)

#define IActMLGOT_ReadDeviceBlock(This,varDevice,varSize,lpvarData,lpvarReturnCode)	\
    (This)->lpVtbl -> ReadDeviceBlock(This,varDevice,varSize,lpvarData,lpvarReturnCode)

#define IActMLGOT_WriteDeviceBlock(This,varDevice,varSize,varData,lpvarReturnCode)	\
    (This)->lpVtbl -> WriteDeviceBlock(This,varDevice,varSize,varData,lpvarReturnCode)

#define IActMLGOT_ReadDeviceRandom(This,varDeviceList,varSize,lpvarData,lpvarReturnCode)	\
    (This)->lpVtbl -> ReadDeviceRandom(This,varDeviceList,varSize,lpvarData,lpvarReturnCode)

#define IActMLGOT_WriteDeviceRandom(This,varDeviceList,varSize,varData,lpvarReturnCode)	\
    (This)->lpVtbl -> WriteDeviceRandom(This,varDeviceList,varSize,varData,lpvarReturnCode)

#define IActMLGOT_GetCpuType(This,lpvarCpuName,lpvarCpuType,lpvarReturnCode)	\
    (This)->lpVtbl -> GetCpuType(This,lpvarCpuName,lpvarCpuType,lpvarReturnCode)

#define IActMLGOT_EntryDeviceStatus(This,varDeviceList,varSize,varMonitorCycle,varData,lpvarReturnCode)	\
    (This)->lpVtbl -> EntryDeviceStatus(This,varDeviceList,varSize,varMonitorCycle,varData,lpvarReturnCode)

#define IActMLGOT_FreeDeviceStatus(This,lpvarReturnCode)	\
    (This)->lpVtbl -> FreeDeviceStatus(This,lpvarReturnCode)

#define IActMLGOT_ReadDeviceBlock2(This,varDevice,varSize,lpvarData,lpvarReturnCode)	\
    (This)->lpVtbl -> ReadDeviceBlock2(This,varDevice,varSize,lpvarData,lpvarReturnCode)

#define IActMLGOT_WriteDeviceBlock2(This,varDevice,varSize,varData,lpvarReturnCode)	\
    (This)->lpVtbl -> WriteDeviceBlock2(This,varDevice,varSize,varData,lpvarReturnCode)

#define IActMLGOT_ReadDeviceRandom2(This,varDeviceList,varSize,lpvarData,lpvarReturnCode)	\
    (This)->lpVtbl -> ReadDeviceRandom2(This,varDeviceList,varSize,lpvarData,lpvarReturnCode)

#define IActMLGOT_WriteDeviceRandom2(This,varDeviceList,varSize,varData,lpvarReturnCode)	\
    (This)->lpVtbl -> WriteDeviceRandom2(This,varDeviceList,varSize,varData,lpvarReturnCode)

#define IActMLGOT_GetDevice2(This,varDevice,lpvarData,lpvarReturnCode)	\
    (This)->lpVtbl -> GetDevice2(This,varDevice,lpvarData,lpvarReturnCode)

#define IActMLGOT_SetDevice2(This,varDevice,varData,lpvarReturnCode)	\
    (This)->lpVtbl -> SetDevice2(This,varDevice,varData,lpvarReturnCode)

#define IActMLGOT_get_ActPortNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActPortNumber(This,pVal)

#define IActMLGOT_put_ActPortNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActPortNumber(This,newVal)

#define IActMLGOT_get_ActHostAddress(This,pVal)	\
    (This)->lpVtbl -> get_ActHostAddress(This,pVal)

#define IActMLGOT_put_ActHostAddress(This,newVal)	\
    (This)->lpVtbl -> put_ActHostAddress(This,newVal)

#define IActMLGOT_get_ActTimeOut(This,pVal)	\
    (This)->lpVtbl -> get_ActTimeOut(This,pVal)

#define IActMLGOT_put_ActTimeOut(This,newVal)	\
    (This)->lpVtbl -> put_ActTimeOut(This,newVal)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActMLGOT_Open_Proxy( 
    IActMLGOT __RPC_FAR * This,
    /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);


void __RPC_STUB IActMLGOT_Open_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActMLGOT_Close_Proxy( 
    IActMLGOT __RPC_FAR * This,
    /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);


void __RPC_STUB IActMLGOT_Close_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActMLGOT_GetDevice_Proxy( 
    IActMLGOT __RPC_FAR * This,
    /* [in] */ VARIANT varDevice,
    /* [out] */ VARIANT __RPC_FAR *lpvarData,
    /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);


void __RPC_STUB IActMLGOT_GetDevice_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActMLGOT_SetDevice_Proxy( 
    IActMLGOT __RPC_FAR * This,
    /* [in] */ VARIANT varDevice,
    /* [in] */ VARIANT varData,
    /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);


void __RPC_STUB IActMLGOT_SetDevice_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActMLGOT_ReadDeviceBlock_Proxy( 
    IActMLGOT __RPC_FAR * This,
    /* [in] */ VARIANT varDevice,
    /* [in] */ VARIANT varSize,
    /* [out] */ VARIANT __RPC_FAR *lpvarData,
    /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);


void __RPC_STUB IActMLGOT_ReadDeviceBlock_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActMLGOT_WriteDeviceBlock_Proxy( 
    IActMLGOT __RPC_FAR * This,
    /* [in] */ VARIANT varDevice,
    /* [in] */ VARIANT varSize,
    /* [in] */ VARIANT varData,
    /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);


void __RPC_STUB IActMLGOT_WriteDeviceBlock_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActMLGOT_ReadDeviceRandom_Proxy( 
    IActMLGOT __RPC_FAR * This,
    /* [in] */ VARIANT varDeviceList,
    /* [in] */ VARIANT varSize,
    /* [out] */ VARIANT __RPC_FAR *lpvarData,
    /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);


void __RPC_STUB IActMLGOT_ReadDeviceRandom_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActMLGOT_WriteDeviceRandom_Proxy( 
    IActMLGOT __RPC_FAR * This,
    /* [in] */ VARIANT varDeviceList,
    /* [in] */ VARIANT varSize,
    /* [in] */ VARIANT varData,
    /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);


void __RPC_STUB IActMLGOT_WriteDeviceRandom_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActMLGOT_GetCpuType_Proxy( 
    IActMLGOT __RPC_FAR * This,
    /* [out] */ VARIANT __RPC_FAR *lpvarCpuName,
    /* [out] */ VARIANT __RPC_FAR *lpvarCpuType,
    /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);


void __RPC_STUB IActMLGOT_GetCpuType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActMLGOT_EntryDeviceStatus_Proxy( 
    IActMLGOT __RPC_FAR * This,
    /* [in] */ VARIANT varDeviceList,
    /* [in] */ VARIANT varSize,
    /* [in] */ VARIANT varMonitorCycle,
    /* [in] */ VARIANT varData,
    /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);


void __RPC_STUB IActMLGOT_EntryDeviceStatus_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActMLGOT_FreeDeviceStatus_Proxy( 
    IActMLGOT __RPC_FAR * This,
    /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);


void __RPC_STUB IActMLGOT_FreeDeviceStatus_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActMLGOT_ReadDeviceBlock2_Proxy( 
    IActMLGOT __RPC_FAR * This,
    /* [in] */ VARIANT varDevice,
    /* [in] */ VARIANT varSize,
    /* [out] */ VARIANT __RPC_FAR *lpvarData,
    /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);


void __RPC_STUB IActMLGOT_ReadDeviceBlock2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActMLGOT_WriteDeviceBlock2_Proxy( 
    IActMLGOT __RPC_FAR * This,
    /* [in] */ VARIANT varDevice,
    /* [in] */ VARIANT varSize,
    /* [in] */ VARIANT varData,
    /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);


void __RPC_STUB IActMLGOT_WriteDeviceBlock2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActMLGOT_ReadDeviceRandom2_Proxy( 
    IActMLGOT __RPC_FAR * This,
    /* [in] */ VARIANT varDeviceList,
    /* [in] */ VARIANT varSize,
    /* [out] */ VARIANT __RPC_FAR *lpvarData,
    /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);


void __RPC_STUB IActMLGOT_ReadDeviceRandom2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActMLGOT_WriteDeviceRandom2_Proxy( 
    IActMLGOT __RPC_FAR * This,
    /* [in] */ VARIANT varDeviceList,
    /* [in] */ VARIANT varSize,
    /* [in] */ VARIANT varData,
    /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);


void __RPC_STUB IActMLGOT_WriteDeviceRandom2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActMLGOT_GetDevice2_Proxy( 
    IActMLGOT __RPC_FAR * This,
    /* [in] */ VARIANT varDevice,
    /* [out] */ VARIANT __RPC_FAR *lpvarData,
    /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);


void __RPC_STUB IActMLGOT_GetDevice2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActMLGOT_SetDevice2_Proxy( 
    IActMLGOT __RPC_FAR * This,
    /* [in] */ VARIANT varDevice,
    /* [in] */ VARIANT varData,
    /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);


void __RPC_STUB IActMLGOT_SetDevice2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActMLGOT_get_ActPortNumber_Proxy( 
    IActMLGOT __RPC_FAR * This,
    /* [retval][out] */ VARIANT __RPC_FAR *pVal);


void __RPC_STUB IActMLGOT_get_ActPortNumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActMLGOT_put_ActPortNumber_Proxy( 
    IActMLGOT __RPC_FAR * This,
    /* [in] */ VARIANT newVal);


void __RPC_STUB IActMLGOT_put_ActPortNumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActMLGOT_get_ActHostAddress_Proxy( 
    IActMLGOT __RPC_FAR * This,
    /* [retval][out] */ VARIANT __RPC_FAR *pVal);


void __RPC_STUB IActMLGOT_get_ActHostAddress_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActMLGOT_put_ActHostAddress_Proxy( 
    IActMLGOT __RPC_FAR * This,
    /* [in] */ VARIANT newVal);


void __RPC_STUB IActMLGOT_put_ActHostAddress_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActMLGOT_get_ActTimeOut_Proxy( 
    IActMLGOT __RPC_FAR * This,
    /* [retval][out] */ VARIANT __RPC_FAR *pVal);


void __RPC_STUB IActMLGOT_get_ActTimeOut_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActMLGOT_put_ActTimeOut_Proxy( 
    IActMLGOT __RPC_FAR * This,
    /* [in] */ VARIANT newVal);


void __RPC_STUB IActMLGOT_put_ActTimeOut_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IActMLGOT_INTERFACE_DEFINED__ */


#ifndef __IActMLGOT2_INTERFACE_DEFINED__
#define __IActMLGOT2_INTERFACE_DEFINED__

/* interface IActMLGOT2 */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IActMLGOT2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("87166048-710B-11d5-9318-009099244EFD")
    IActMLGOT2 : public IActMLGOT
    {
    public:
    };
    
#else 	/* C style interface */

    typedef struct IActMLGOT2Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IActMLGOT2 __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IActMLGOT2 __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IActMLGOT2 __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IActMLGOT2 __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IActMLGOT2 __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IActMLGOT2 __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IActMLGOT2 __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Open )( 
            IActMLGOT2 __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Close )( 
            IActMLGOT2 __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetDevice )( 
            IActMLGOT2 __RPC_FAR * This,
            /* [in] */ VARIANT varDevice,
            /* [out] */ VARIANT __RPC_FAR *lpvarData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetDevice )( 
            IActMLGOT2 __RPC_FAR * This,
            /* [in] */ VARIANT varDevice,
            /* [in] */ VARIANT varData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceBlock )( 
            IActMLGOT2 __RPC_FAR * This,
            /* [in] */ VARIANT varDevice,
            /* [in] */ VARIANT varSize,
            /* [out] */ VARIANT __RPC_FAR *lpvarData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceBlock )( 
            IActMLGOT2 __RPC_FAR * This,
            /* [in] */ VARIANT varDevice,
            /* [in] */ VARIANT varSize,
            /* [in] */ VARIANT varData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceRandom )( 
            IActMLGOT2 __RPC_FAR * This,
            /* [in] */ VARIANT varDeviceList,
            /* [in] */ VARIANT varSize,
            /* [out] */ VARIANT __RPC_FAR *lpvarData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceRandom )( 
            IActMLGOT2 __RPC_FAR * This,
            /* [in] */ VARIANT varDeviceList,
            /* [in] */ VARIANT varSize,
            /* [in] */ VARIANT varData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetCpuType )( 
            IActMLGOT2 __RPC_FAR * This,
            /* [out] */ VARIANT __RPC_FAR *lpvarCpuName,
            /* [out] */ VARIANT __RPC_FAR *lpvarCpuType,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *EntryDeviceStatus )( 
            IActMLGOT2 __RPC_FAR * This,
            /* [in] */ VARIANT varDeviceList,
            /* [in] */ VARIANT varSize,
            /* [in] */ VARIANT varMonitorCycle,
            /* [in] */ VARIANT varData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *FreeDeviceStatus )( 
            IActMLGOT2 __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceBlock2 )( 
            IActMLGOT2 __RPC_FAR * This,
            /* [in] */ VARIANT varDevice,
            /* [in] */ VARIANT varSize,
            /* [out] */ VARIANT __RPC_FAR *lpvarData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceBlock2 )( 
            IActMLGOT2 __RPC_FAR * This,
            /* [in] */ VARIANT varDevice,
            /* [in] */ VARIANT varSize,
            /* [in] */ VARIANT varData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceRandom2 )( 
            IActMLGOT2 __RPC_FAR * This,
            /* [in] */ VARIANT varDeviceList,
            /* [in] */ VARIANT varSize,
            /* [out] */ VARIANT __RPC_FAR *lpvarData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceRandom2 )( 
            IActMLGOT2 __RPC_FAR * This,
            /* [in] */ VARIANT varDeviceList,
            /* [in] */ VARIANT varSize,
            /* [in] */ VARIANT varData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetDevice2 )( 
            IActMLGOT2 __RPC_FAR * This,
            /* [in] */ VARIANT varDevice,
            /* [out] */ VARIANT __RPC_FAR *lpvarData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetDevice2 )( 
            IActMLGOT2 __RPC_FAR * This,
            /* [in] */ VARIANT varDevice,
            /* [in] */ VARIANT varData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActPortNumber )( 
            IActMLGOT2 __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActPortNumber )( 
            IActMLGOT2 __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActHostAddress )( 
            IActMLGOT2 __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActHostAddress )( 
            IActMLGOT2 __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActTimeOut )( 
            IActMLGOT2 __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActTimeOut )( 
            IActMLGOT2 __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        END_INTERFACE
    } IActMLGOT2Vtbl;

    interface IActMLGOT2
    {
        CONST_VTBL struct IActMLGOT2Vtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IActMLGOT2_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IActMLGOT2_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IActMLGOT2_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IActMLGOT2_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IActMLGOT2_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IActMLGOT2_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IActMLGOT2_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IActMLGOT2_Open(This,lpvarReturnCode)	\
    (This)->lpVtbl -> Open(This,lpvarReturnCode)

#define IActMLGOT2_Close(This,lpvarReturnCode)	\
    (This)->lpVtbl -> Close(This,lpvarReturnCode)

#define IActMLGOT2_GetDevice(This,varDevice,lpvarData,lpvarReturnCode)	\
    (This)->lpVtbl -> GetDevice(This,varDevice,lpvarData,lpvarReturnCode)

#define IActMLGOT2_SetDevice(This,varDevice,varData,lpvarReturnCode)	\
    (This)->lpVtbl -> SetDevice(This,varDevice,varData,lpvarReturnCode)

#define IActMLGOT2_ReadDeviceBlock(This,varDevice,varSize,lpvarData,lpvarReturnCode)	\
    (This)->lpVtbl -> ReadDeviceBlock(This,varDevice,varSize,lpvarData,lpvarReturnCode)

#define IActMLGOT2_WriteDeviceBlock(This,varDevice,varSize,varData,lpvarReturnCode)	\
    (This)->lpVtbl -> WriteDeviceBlock(This,varDevice,varSize,varData,lpvarReturnCode)

#define IActMLGOT2_ReadDeviceRandom(This,varDeviceList,varSize,lpvarData,lpvarReturnCode)	\
    (This)->lpVtbl -> ReadDeviceRandom(This,varDeviceList,varSize,lpvarData,lpvarReturnCode)

#define IActMLGOT2_WriteDeviceRandom(This,varDeviceList,varSize,varData,lpvarReturnCode)	\
    (This)->lpVtbl -> WriteDeviceRandom(This,varDeviceList,varSize,varData,lpvarReturnCode)

#define IActMLGOT2_GetCpuType(This,lpvarCpuName,lpvarCpuType,lpvarReturnCode)	\
    (This)->lpVtbl -> GetCpuType(This,lpvarCpuName,lpvarCpuType,lpvarReturnCode)

#define IActMLGOT2_EntryDeviceStatus(This,varDeviceList,varSize,varMonitorCycle,varData,lpvarReturnCode)	\
    (This)->lpVtbl -> EntryDeviceStatus(This,varDeviceList,varSize,varMonitorCycle,varData,lpvarReturnCode)

#define IActMLGOT2_FreeDeviceStatus(This,lpvarReturnCode)	\
    (This)->lpVtbl -> FreeDeviceStatus(This,lpvarReturnCode)

#define IActMLGOT2_ReadDeviceBlock2(This,varDevice,varSize,lpvarData,lpvarReturnCode)	\
    (This)->lpVtbl -> ReadDeviceBlock2(This,varDevice,varSize,lpvarData,lpvarReturnCode)

#define IActMLGOT2_WriteDeviceBlock2(This,varDevice,varSize,varData,lpvarReturnCode)	\
    (This)->lpVtbl -> WriteDeviceBlock2(This,varDevice,varSize,varData,lpvarReturnCode)

#define IActMLGOT2_ReadDeviceRandom2(This,varDeviceList,varSize,lpvarData,lpvarReturnCode)	\
    (This)->lpVtbl -> ReadDeviceRandom2(This,varDeviceList,varSize,lpvarData,lpvarReturnCode)

#define IActMLGOT2_WriteDeviceRandom2(This,varDeviceList,varSize,varData,lpvarReturnCode)	\
    (This)->lpVtbl -> WriteDeviceRandom2(This,varDeviceList,varSize,varData,lpvarReturnCode)

#define IActMLGOT2_GetDevice2(This,varDevice,lpvarData,lpvarReturnCode)	\
    (This)->lpVtbl -> GetDevice2(This,varDevice,lpvarData,lpvarReturnCode)

#define IActMLGOT2_SetDevice2(This,varDevice,varData,lpvarReturnCode)	\
    (This)->lpVtbl -> SetDevice2(This,varDevice,varData,lpvarReturnCode)

#define IActMLGOT2_get_ActPortNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActPortNumber(This,pVal)

#define IActMLGOT2_put_ActPortNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActPortNumber(This,newVal)

#define IActMLGOT2_get_ActHostAddress(This,pVal)	\
    (This)->lpVtbl -> get_ActHostAddress(This,pVal)

#define IActMLGOT2_put_ActHostAddress(This,newVal)	\
    (This)->lpVtbl -> put_ActHostAddress(This,newVal)

#define IActMLGOT2_get_ActTimeOut(This,pVal)	\
    (This)->lpVtbl -> get_ActTimeOut(This,pVal)

#define IActMLGOT2_put_ActTimeOut(This,newVal)	\
    (This)->lpVtbl -> put_ActTimeOut(This,newVal)


#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IActMLGOT2_INTERFACE_DEFINED__ */


#ifndef __IActMLGOT3_INTERFACE_DEFINED__
#define __IActMLGOT3_INTERFACE_DEFINED__

/* interface IActMLGOT3 */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IActMLGOT3;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("87166049-710B-11d5-9318-009099244EFD")
    IActMLGOT3 : public IActMLGOT2
    {
    public:
    };
    
#else 	/* C style interface */

    typedef struct IActMLGOT3Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IActMLGOT3 __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IActMLGOT3 __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IActMLGOT3 __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IActMLGOT3 __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IActMLGOT3 __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IActMLGOT3 __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IActMLGOT3 __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Open )( 
            IActMLGOT3 __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Close )( 
            IActMLGOT3 __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetDevice )( 
            IActMLGOT3 __RPC_FAR * This,
            /* [in] */ VARIANT varDevice,
            /* [out] */ VARIANT __RPC_FAR *lpvarData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetDevice )( 
            IActMLGOT3 __RPC_FAR * This,
            /* [in] */ VARIANT varDevice,
            /* [in] */ VARIANT varData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceBlock )( 
            IActMLGOT3 __RPC_FAR * This,
            /* [in] */ VARIANT varDevice,
            /* [in] */ VARIANT varSize,
            /* [out] */ VARIANT __RPC_FAR *lpvarData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceBlock )( 
            IActMLGOT3 __RPC_FAR * This,
            /* [in] */ VARIANT varDevice,
            /* [in] */ VARIANT varSize,
            /* [in] */ VARIANT varData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceRandom )( 
            IActMLGOT3 __RPC_FAR * This,
            /* [in] */ VARIANT varDeviceList,
            /* [in] */ VARIANT varSize,
            /* [out] */ VARIANT __RPC_FAR *lpvarData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceRandom )( 
            IActMLGOT3 __RPC_FAR * This,
            /* [in] */ VARIANT varDeviceList,
            /* [in] */ VARIANT varSize,
            /* [in] */ VARIANT varData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetCpuType )( 
            IActMLGOT3 __RPC_FAR * This,
            /* [out] */ VARIANT __RPC_FAR *lpvarCpuName,
            /* [out] */ VARIANT __RPC_FAR *lpvarCpuType,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *EntryDeviceStatus )( 
            IActMLGOT3 __RPC_FAR * This,
            /* [in] */ VARIANT varDeviceList,
            /* [in] */ VARIANT varSize,
            /* [in] */ VARIANT varMonitorCycle,
            /* [in] */ VARIANT varData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *FreeDeviceStatus )( 
            IActMLGOT3 __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceBlock2 )( 
            IActMLGOT3 __RPC_FAR * This,
            /* [in] */ VARIANT varDevice,
            /* [in] */ VARIANT varSize,
            /* [out] */ VARIANT __RPC_FAR *lpvarData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceBlock2 )( 
            IActMLGOT3 __RPC_FAR * This,
            /* [in] */ VARIANT varDevice,
            /* [in] */ VARIANT varSize,
            /* [in] */ VARIANT varData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceRandom2 )( 
            IActMLGOT3 __RPC_FAR * This,
            /* [in] */ VARIANT varDeviceList,
            /* [in] */ VARIANT varSize,
            /* [out] */ VARIANT __RPC_FAR *lpvarData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceRandom2 )( 
            IActMLGOT3 __RPC_FAR * This,
            /* [in] */ VARIANT varDeviceList,
            /* [in] */ VARIANT varSize,
            /* [in] */ VARIANT varData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetDevice2 )( 
            IActMLGOT3 __RPC_FAR * This,
            /* [in] */ VARIANT varDevice,
            /* [out] */ VARIANT __RPC_FAR *lpvarData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetDevice2 )( 
            IActMLGOT3 __RPC_FAR * This,
            /* [in] */ VARIANT varDevice,
            /* [in] */ VARIANT varData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActPortNumber )( 
            IActMLGOT3 __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActPortNumber )( 
            IActMLGOT3 __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActHostAddress )( 
            IActMLGOT3 __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActHostAddress )( 
            IActMLGOT3 __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActTimeOut )( 
            IActMLGOT3 __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActTimeOut )( 
            IActMLGOT3 __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        END_INTERFACE
    } IActMLGOT3Vtbl;

    interface IActMLGOT3
    {
        CONST_VTBL struct IActMLGOT3Vtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IActMLGOT3_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IActMLGOT3_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IActMLGOT3_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IActMLGOT3_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IActMLGOT3_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IActMLGOT3_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IActMLGOT3_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IActMLGOT3_Open(This,lpvarReturnCode)	\
    (This)->lpVtbl -> Open(This,lpvarReturnCode)

#define IActMLGOT3_Close(This,lpvarReturnCode)	\
    (This)->lpVtbl -> Close(This,lpvarReturnCode)

#define IActMLGOT3_GetDevice(This,varDevice,lpvarData,lpvarReturnCode)	\
    (This)->lpVtbl -> GetDevice(This,varDevice,lpvarData,lpvarReturnCode)

#define IActMLGOT3_SetDevice(This,varDevice,varData,lpvarReturnCode)	\
    (This)->lpVtbl -> SetDevice(This,varDevice,varData,lpvarReturnCode)

#define IActMLGOT3_ReadDeviceBlock(This,varDevice,varSize,lpvarData,lpvarReturnCode)	\
    (This)->lpVtbl -> ReadDeviceBlock(This,varDevice,varSize,lpvarData,lpvarReturnCode)

#define IActMLGOT3_WriteDeviceBlock(This,varDevice,varSize,varData,lpvarReturnCode)	\
    (This)->lpVtbl -> WriteDeviceBlock(This,varDevice,varSize,varData,lpvarReturnCode)

#define IActMLGOT3_ReadDeviceRandom(This,varDeviceList,varSize,lpvarData,lpvarReturnCode)	\
    (This)->lpVtbl -> ReadDeviceRandom(This,varDeviceList,varSize,lpvarData,lpvarReturnCode)

#define IActMLGOT3_WriteDeviceRandom(This,varDeviceList,varSize,varData,lpvarReturnCode)	\
    (This)->lpVtbl -> WriteDeviceRandom(This,varDeviceList,varSize,varData,lpvarReturnCode)

#define IActMLGOT3_GetCpuType(This,lpvarCpuName,lpvarCpuType,lpvarReturnCode)	\
    (This)->lpVtbl -> GetCpuType(This,lpvarCpuName,lpvarCpuType,lpvarReturnCode)

#define IActMLGOT3_EntryDeviceStatus(This,varDeviceList,varSize,varMonitorCycle,varData,lpvarReturnCode)	\
    (This)->lpVtbl -> EntryDeviceStatus(This,varDeviceList,varSize,varMonitorCycle,varData,lpvarReturnCode)

#define IActMLGOT3_FreeDeviceStatus(This,lpvarReturnCode)	\
    (This)->lpVtbl -> FreeDeviceStatus(This,lpvarReturnCode)

#define IActMLGOT3_ReadDeviceBlock2(This,varDevice,varSize,lpvarData,lpvarReturnCode)	\
    (This)->lpVtbl -> ReadDeviceBlock2(This,varDevice,varSize,lpvarData,lpvarReturnCode)

#define IActMLGOT3_WriteDeviceBlock2(This,varDevice,varSize,varData,lpvarReturnCode)	\
    (This)->lpVtbl -> WriteDeviceBlock2(This,varDevice,varSize,varData,lpvarReturnCode)

#define IActMLGOT3_ReadDeviceRandom2(This,varDeviceList,varSize,lpvarData,lpvarReturnCode)	\
    (This)->lpVtbl -> ReadDeviceRandom2(This,varDeviceList,varSize,lpvarData,lpvarReturnCode)

#define IActMLGOT3_WriteDeviceRandom2(This,varDeviceList,varSize,varData,lpvarReturnCode)	\
    (This)->lpVtbl -> WriteDeviceRandom2(This,varDeviceList,varSize,varData,lpvarReturnCode)

#define IActMLGOT3_GetDevice2(This,varDevice,lpvarData,lpvarReturnCode)	\
    (This)->lpVtbl -> GetDevice2(This,varDevice,lpvarData,lpvarReturnCode)

#define IActMLGOT3_SetDevice2(This,varDevice,varData,lpvarReturnCode)	\
    (This)->lpVtbl -> SetDevice2(This,varDevice,varData,lpvarReturnCode)

#define IActMLGOT3_get_ActPortNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActPortNumber(This,pVal)

#define IActMLGOT3_put_ActPortNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActPortNumber(This,newVal)

#define IActMLGOT3_get_ActHostAddress(This,pVal)	\
    (This)->lpVtbl -> get_ActHostAddress(This,pVal)

#define IActMLGOT3_put_ActHostAddress(This,newVal)	\
    (This)->lpVtbl -> put_ActHostAddress(This,newVal)

#define IActMLGOT3_get_ActTimeOut(This,pVal)	\
    (This)->lpVtbl -> get_ActTimeOut(This,pVal)

#define IActMLGOT3_put_ActTimeOut(This,newVal)	\
    (This)->lpVtbl -> put_ActTimeOut(This,newVal)



#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IActMLGOT3_INTERFACE_DEFINED__ */


#ifndef __IActGOTTRSP_INTERFACE_DEFINED__
#define __IActGOTTRSP_INTERFACE_DEFINED__

/* interface IActGOTTRSP */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IActGOTTRSP;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("733F02D2-1C16-41DD-AFB2-8C0AC5D72CAE")
    IActGOTTRSP : public IDispatch
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
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActHostAddress( 
            /* [retval][out] */ BSTR __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActHostAddress( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActTimeOut( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActTimeOut( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActSourceNetworkNumber( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActSourceNetworkNumber( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActSourceStationNumber( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActSourceStationNumber( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActDestinationPortNumber( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActDestinationPortNumber( 
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
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActGotTransparentPCIf( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActGotTransparentPCIf( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActGotTransparentPLCIf( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActGotTransparentPLCIf( 
            /* [in] */ long newVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IActGOTTRSPVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IActGOTTRSP __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IActGOTTRSP __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IActGOTTRSP __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IActGOTTRSP __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IActGOTTRSP __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IActGOTTRSP __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IActGOTTRSP __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Open )( 
            IActGOTTRSP __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Close )( 
            IActGOTTRSP __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetDevice )( 
            IActGOTTRSP __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [out] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetDevice )( 
            IActGOTTRSP __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceBlock )( 
            IActGOTTRSP __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lSize,
            /* [size_is][out] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceBlock )( 
            IActGOTTRSP __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lSize,
            /* [size_is][in] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceRandom )( 
            IActGOTTRSP __RPC_FAR * This,
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG lSize,
            /* [size_is][out] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceRandom )( 
            IActGOTTRSP __RPC_FAR * This,
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG lSize,
            /* [size_is][in] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadBuffer )( 
            IActGOTTRSP __RPC_FAR * This,
            /* [in] */ LONG lStartIO,
            /* [in] */ LONG lAddress,
            /* [in] */ LONG lReadSize,
            /* [size_is][out] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteBuffer )( 
            IActGOTTRSP __RPC_FAR * This,
            /* [in] */ LONG lStartIO,
            /* [in] */ LONG lAddress,
            /* [in] */ LONG lWriteSize,
            /* [size_is][in] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetCpuType )( 
            IActGOTTRSP __RPC_FAR * This,
            /* [string][out] */ BSTR __RPC_FAR *szCpuName,
            /* [out] */ LONG __RPC_FAR *lplCpuCode,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetCpuStatus )( 
            IActGOTTRSP __RPC_FAR * This,
            /* [in] */ LONG lOperation,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetClockData )( 
            IActGOTTRSP __RPC_FAR * This,
            /* [out] */ SHORT __RPC_FAR *lpsYear,
            /* [out] */ SHORT __RPC_FAR *lpsMonth,
            /* [out] */ SHORT __RPC_FAR *lpsDay,
            /* [out] */ SHORT __RPC_FAR *lpsDayOfWeek,
            /* [out] */ SHORT __RPC_FAR *lpsHour,
            /* [out] */ SHORT __RPC_FAR *lpsMinute,
            /* [out] */ SHORT __RPC_FAR *lpsSecond,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetClockData )( 
            IActGOTTRSP __RPC_FAR * This,
            /* [in] */ SHORT sYear,
            /* [in] */ SHORT sMonth,
            /* [in] */ SHORT sDay,
            /* [in] */ SHORT sDayOfWeek,
            /* [in] */ SHORT sHour,
            /* [in] */ SHORT sMinute,
            /* [in] */ SHORT sSecond,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *EntryDeviceStatus )( 
            IActGOTTRSP __RPC_FAR * This,
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG lSize,
            /* [in] */ LONG lMonitorCycle,
            /* [size_is][in] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CheckDeviceString )( 
            IActGOTTRSP __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lCheckType,
            /* [in] */ LONG lSize,
            /* [out] */ LONG __RPC_FAR *lplDeviceType,
            /* [string][out] */ BSTR __RPC_FAR *lpszDeviceName,
            /* [out] */ LONG __RPC_FAR *lplDeviceNumber,
            /* [out] */ LONG __RPC_FAR *lplDeviceRadix,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *FreeDeviceStatus )( 
            IActGOTTRSP __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceBlock2 )( 
            IActGOTTRSP __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lSize,
            /* [size_is][out] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceBlock2 )( 
            IActGOTTRSP __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lSize,
            /* [size_is][in] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceRandom2 )( 
            IActGOTTRSP __RPC_FAR * This,
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG lSize,
            /* [size_is][out] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceRandom2 )( 
            IActGOTTRSP __RPC_FAR * This,
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG lSize,
            /* [size_is][in] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetDevice2 )( 
            IActGOTTRSP __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [out] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetDevice2 )( 
            IActGOTTRSP __RPC_FAR * This,
            /* [in] */ BSTR szDevice,
            /* [in] */ SHORT sData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActNetworkNumber )( 
            IActGOTTRSP __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActNetworkNumber )( 
            IActGOTTRSP __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActStationNumber )( 
            IActGOTTRSP __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActStationNumber )( 
            IActGOTTRSP __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActUnitNumber )( 
            IActGOTTRSP __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActUnitNumber )( 
            IActGOTTRSP __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActConnectUnitNumber )( 
            IActGOTTRSP __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActConnectUnitNumber )( 
            IActGOTTRSP __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActIONumber )( 
            IActGOTTRSP __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActIONumber )( 
            IActGOTTRSP __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActCpuType )( 
            IActGOTTRSP __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActCpuType )( 
            IActGOTTRSP __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActPortNumber )( 
            IActGOTTRSP __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActPortNumber )( 
            IActGOTTRSP __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActBaudRate )( 
            IActGOTTRSP __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActBaudRate )( 
            IActGOTTRSP __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActHostAddress )( 
            IActGOTTRSP __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActHostAddress )( 
            IActGOTTRSP __RPC_FAR * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActTimeOut )( 
            IActGOTTRSP __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActTimeOut )( 
            IActGOTTRSP __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActSourceNetworkNumber )( 
            IActGOTTRSP __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActSourceNetworkNumber )( 
            IActGOTTRSP __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActSourceStationNumber )( 
            IActGOTTRSP __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActSourceStationNumber )( 
            IActGOTTRSP __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActDestinationPortNumber )( 
            IActGOTTRSP __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActDestinationPortNumber )( 
            IActGOTTRSP __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActDestinationIONumber )( 
            IActGOTTRSP __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActDestinationIONumber )( 
            IActGOTTRSP __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActMultiDropChannelNumber )( 
            IActGOTTRSP __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActMultiDropChannelNumber )( 
            IActGOTTRSP __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActThroughNetworkType )( 
            IActGOTTRSP __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActThroughNetworkType )( 
            IActGOTTRSP __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActIntelligentPreferenceBit )( 
            IActGOTTRSP __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActIntelligentPreferenceBit )( 
            IActGOTTRSP __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActDidPropertyBit )( 
            IActGOTTRSP __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActDidPropertyBit )( 
            IActGOTTRSP __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActDsidPropertyBit )( 
            IActGOTTRSP __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActDsidPropertyBit )( 
            IActGOTTRSP __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActGotTransparentPCIf )( 
            IActGOTTRSP __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActGotTransparentPCIf )( 
            IActGOTTRSP __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActGotTransparentPLCIf )( 
            IActGOTTRSP __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActGotTransparentPLCIf )( 
            IActGOTTRSP __RPC_FAR * This,
            /* [in] */ long newVal);
        
        END_INTERFACE
    } IActGOTTRSPVtbl;

    interface IActGOTTRSP
    {
        CONST_VTBL struct IActGOTTRSPVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IActGOTTRSP_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IActGOTTRSP_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IActGOTTRSP_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IActGOTTRSP_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IActGOTTRSP_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IActGOTTRSP_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IActGOTTRSP_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IActGOTTRSP_Open(This,lplReturnCode)	\
    (This)->lpVtbl -> Open(This,lplReturnCode)

#define IActGOTTRSP_Close(This,lplReturnCode)	\
    (This)->lpVtbl -> Close(This,lplReturnCode)

#define IActGOTTRSP_GetDevice(This,szDevice,lplData,lplReturnCode)	\
    (This)->lpVtbl -> GetDevice(This,szDevice,lplData,lplReturnCode)

#define IActGOTTRSP_SetDevice(This,szDevice,lData,lplReturnCode)	\
    (This)->lpVtbl -> SetDevice(This,szDevice,lData,lplReturnCode)

#define IActGOTTRSP_ReadDeviceBlock(This,szDevice,lSize,lplData,lplReturnCode)	\
    (This)->lpVtbl -> ReadDeviceBlock(This,szDevice,lSize,lplData,lplReturnCode)

#define IActGOTTRSP_WriteDeviceBlock(This,szDevice,lSize,lplData,lplReturnCode)	\
    (This)->lpVtbl -> WriteDeviceBlock(This,szDevice,lSize,lplData,lplReturnCode)

#define IActGOTTRSP_ReadDeviceRandom(This,szDeviceList,lSize,lplData,lplReturnCode)	\
    (This)->lpVtbl -> ReadDeviceRandom(This,szDeviceList,lSize,lplData,lplReturnCode)

#define IActGOTTRSP_WriteDeviceRandom(This,szDeviceList,lSize,lplData,lplReturnCode)	\
    (This)->lpVtbl -> WriteDeviceRandom(This,szDeviceList,lSize,lplData,lplReturnCode)

#define IActGOTTRSP_ReadBuffer(This,lStartIO,lAddress,lReadSize,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> ReadBuffer(This,lStartIO,lAddress,lReadSize,lpsData,lplReturnCode)

#define IActGOTTRSP_WriteBuffer(This,lStartIO,lAddress,lWriteSize,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> WriteBuffer(This,lStartIO,lAddress,lWriteSize,lpsData,lplReturnCode)

#define IActGOTTRSP_GetCpuType(This,szCpuName,lplCpuCode,lplReturnCode)	\
    (This)->lpVtbl -> GetCpuType(This,szCpuName,lplCpuCode,lplReturnCode)

#define IActGOTTRSP_SetCpuStatus(This,lOperation,lplReturnCode)	\
    (This)->lpVtbl -> SetCpuStatus(This,lOperation,lplReturnCode)

#define IActGOTTRSP_GetClockData(This,lpsYear,lpsMonth,lpsDay,lpsDayOfWeek,lpsHour,lpsMinute,lpsSecond,lplReturnCode)	\
    (This)->lpVtbl -> GetClockData(This,lpsYear,lpsMonth,lpsDay,lpsDayOfWeek,lpsHour,lpsMinute,lpsSecond,lplReturnCode)

#define IActGOTTRSP_SetClockData(This,sYear,sMonth,sDay,sDayOfWeek,sHour,sMinute,sSecond,lplReturnCode)	\
    (This)->lpVtbl -> SetClockData(This,sYear,sMonth,sDay,sDayOfWeek,sHour,sMinute,sSecond,lplReturnCode)

#define IActGOTTRSP_EntryDeviceStatus(This,szDeviceList,lSize,lMonitorCycle,lplData,lplReturnCode)	\
    (This)->lpVtbl -> EntryDeviceStatus(This,szDeviceList,lSize,lMonitorCycle,lplData,lplReturnCode)

#define IActGOTTRSP_CheckDeviceString(This,szDevice,lCheckType,lSize,lplDeviceType,lpszDeviceName,lplDeviceNumber,lplDeviceRadix,lplReturnCode)	\
    (This)->lpVtbl -> CheckDeviceString(This,szDevice,lCheckType,lSize,lplDeviceType,lpszDeviceName,lplDeviceNumber,lplDeviceRadix,lplReturnCode)

#define IActGOTTRSP_FreeDeviceStatus(This,lplReturnCode)	\
    (This)->lpVtbl -> FreeDeviceStatus(This,lplReturnCode)

#define IActGOTTRSP_ReadDeviceBlock2(This,szDevice,lSize,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> ReadDeviceBlock2(This,szDevice,lSize,lpsData,lplReturnCode)

#define IActGOTTRSP_WriteDeviceBlock2(This,szDevice,lSize,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> WriteDeviceBlock2(This,szDevice,lSize,lpsData,lplReturnCode)

#define IActGOTTRSP_ReadDeviceRandom2(This,szDeviceList,lSize,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> ReadDeviceRandom2(This,szDeviceList,lSize,lpsData,lplReturnCode)

#define IActGOTTRSP_WriteDeviceRandom2(This,szDeviceList,lSize,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> WriteDeviceRandom2(This,szDeviceList,lSize,lpsData,lplReturnCode)

#define IActGOTTRSP_GetDevice2(This,szDevice,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> GetDevice2(This,szDevice,lpsData,lplReturnCode)

#define IActGOTTRSP_SetDevice2(This,szDevice,sData,lplReturnCode)	\
    (This)->lpVtbl -> SetDevice2(This,szDevice,sData,lplReturnCode)

#define IActGOTTRSP_get_ActNetworkNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActNetworkNumber(This,pVal)

#define IActGOTTRSP_put_ActNetworkNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActNetworkNumber(This,newVal)

#define IActGOTTRSP_get_ActStationNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActStationNumber(This,pVal)

#define IActGOTTRSP_put_ActStationNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActStationNumber(This,newVal)

#define IActGOTTRSP_get_ActUnitNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActUnitNumber(This,pVal)

#define IActGOTTRSP_put_ActUnitNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActUnitNumber(This,newVal)

#define IActGOTTRSP_get_ActConnectUnitNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActConnectUnitNumber(This,pVal)

#define IActGOTTRSP_put_ActConnectUnitNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActConnectUnitNumber(This,newVal)

#define IActGOTTRSP_get_ActIONumber(This,pVal)	\
    (This)->lpVtbl -> get_ActIONumber(This,pVal)

#define IActGOTTRSP_put_ActIONumber(This,newVal)	\
    (This)->lpVtbl -> put_ActIONumber(This,newVal)

#define IActGOTTRSP_get_ActCpuType(This,pVal)	\
    (This)->lpVtbl -> get_ActCpuType(This,pVal)

#define IActGOTTRSP_put_ActCpuType(This,newVal)	\
    (This)->lpVtbl -> put_ActCpuType(This,newVal)

#define IActGOTTRSP_get_ActPortNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActPortNumber(This,pVal)

#define IActGOTTRSP_put_ActPortNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActPortNumber(This,newVal)

#define IActGOTTRSP_get_ActBaudRate(This,pVal)	\
    (This)->lpVtbl -> get_ActBaudRate(This,pVal)

#define IActGOTTRSP_put_ActBaudRate(This,newVal)	\
    (This)->lpVtbl -> put_ActBaudRate(This,newVal)

#define IActGOTTRSP_get_ActHostAddress(This,pVal)	\
    (This)->lpVtbl -> get_ActHostAddress(This,pVal)

#define IActGOTTRSP_put_ActHostAddress(This,newVal)	\
    (This)->lpVtbl -> put_ActHostAddress(This,newVal)

#define IActGOTTRSP_get_ActTimeOut(This,pVal)	\
    (This)->lpVtbl -> get_ActTimeOut(This,pVal)

#define IActGOTTRSP_put_ActTimeOut(This,newVal)	\
    (This)->lpVtbl -> put_ActTimeOut(This,newVal)

#define IActGOTTRSP_get_ActSourceNetworkNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActSourceNetworkNumber(This,pVal)

#define IActGOTTRSP_put_ActSourceNetworkNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActSourceNetworkNumber(This,newVal)

#define IActGOTTRSP_get_ActSourceStationNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActSourceStationNumber(This,pVal)

#define IActGOTTRSP_put_ActSourceStationNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActSourceStationNumber(This,newVal)

#define IActGOTTRSP_get_ActDestinationPortNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActDestinationPortNumber(This,pVal)

#define IActGOTTRSP_put_ActDestinationPortNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActDestinationPortNumber(This,newVal)

#define IActGOTTRSP_get_ActDestinationIONumber(This,pVal)	\
    (This)->lpVtbl -> get_ActDestinationIONumber(This,pVal)

#define IActGOTTRSP_put_ActDestinationIONumber(This,newVal)	\
    (This)->lpVtbl -> put_ActDestinationIONumber(This,newVal)

#define IActGOTTRSP_get_ActMultiDropChannelNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActMultiDropChannelNumber(This,pVal)

#define IActGOTTRSP_put_ActMultiDropChannelNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActMultiDropChannelNumber(This,newVal)

#define IActGOTTRSP_get_ActThroughNetworkType(This,pVal)	\
    (This)->lpVtbl -> get_ActThroughNetworkType(This,pVal)

#define IActGOTTRSP_put_ActThroughNetworkType(This,newVal)	\
    (This)->lpVtbl -> put_ActThroughNetworkType(This,newVal)

#define IActGOTTRSP_get_ActIntelligentPreferenceBit(This,pVal)	\
    (This)->lpVtbl -> get_ActIntelligentPreferenceBit(This,pVal)

#define IActGOTTRSP_put_ActIntelligentPreferenceBit(This,newVal)	\
    (This)->lpVtbl -> put_ActIntelligentPreferenceBit(This,newVal)

#define IActGOTTRSP_get_ActDidPropertyBit(This,pVal)	\
    (This)->lpVtbl -> get_ActDidPropertyBit(This,pVal)

#define IActGOTTRSP_put_ActDidPropertyBit(This,newVal)	\
    (This)->lpVtbl -> put_ActDidPropertyBit(This,newVal)

#define IActGOTTRSP_get_ActDsidPropertyBit(This,pVal)	\
    (This)->lpVtbl -> get_ActDsidPropertyBit(This,pVal)

#define IActGOTTRSP_put_ActDsidPropertyBit(This,newVal)	\
    (This)->lpVtbl -> put_ActDsidPropertyBit(This,newVal)

#define IActGOTTRSP_get_ActGotTransparentPCIf(This,pVal)	\
    (This)->lpVtbl -> get_ActGotTransparentPCIf(This,pVal)

#define IActGOTTRSP_put_ActGotTransparentPCIf(This,newVal)	\
    (This)->lpVtbl -> put_ActGotTransparentPCIf(This,newVal)

#define IActGOTTRSP_get_ActGotTransparentPLCIf(This,pVal)	\
    (This)->lpVtbl -> get_ActGotTransparentPLCIf(This,pVal)

#define IActGOTTRSP_put_ActGotTransparentPLCIf(This,newVal)	\
    (This)->lpVtbl -> put_ActGotTransparentPLCIf(This,newVal)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActGOTTRSP_Open_Proxy( 
    IActGOTTRSP __RPC_FAR * This,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActGOTTRSP_Open_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActGOTTRSP_Close_Proxy( 
    IActGOTTRSP __RPC_FAR * This,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActGOTTRSP_Close_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActGOTTRSP_GetDevice_Proxy( 
    IActGOTTRSP __RPC_FAR * This,
    /* [string][in] */ BSTR szDevice,
    /* [out] */ LONG __RPC_FAR *lplData,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActGOTTRSP_GetDevice_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActGOTTRSP_SetDevice_Proxy( 
    IActGOTTRSP __RPC_FAR * This,
    /* [string][in] */ BSTR szDevice,
    /* [in] */ LONG lData,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActGOTTRSP_SetDevice_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActGOTTRSP_ReadDeviceBlock_Proxy( 
    IActGOTTRSP __RPC_FAR * This,
    /* [string][in] */ BSTR szDevice,
    /* [in] */ LONG lSize,
    /* [size_is][out] */ LONG __RPC_FAR *lplData,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActGOTTRSP_ReadDeviceBlock_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActGOTTRSP_WriteDeviceBlock_Proxy( 
    IActGOTTRSP __RPC_FAR * This,
    /* [string][in] */ BSTR szDevice,
    /* [in] */ LONG lSize,
    /* [size_is][in] */ LONG __RPC_FAR *lplData,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActGOTTRSP_WriteDeviceBlock_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActGOTTRSP_ReadDeviceRandom_Proxy( 
    IActGOTTRSP __RPC_FAR * This,
    /* [string][in] */ BSTR szDeviceList,
    /* [in] */ LONG lSize,
    /* [size_is][out] */ LONG __RPC_FAR *lplData,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActGOTTRSP_ReadDeviceRandom_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActGOTTRSP_WriteDeviceRandom_Proxy( 
    IActGOTTRSP __RPC_FAR * This,
    /* [string][in] */ BSTR szDeviceList,
    /* [in] */ LONG lSize,
    /* [size_is][in] */ LONG __RPC_FAR *lplData,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActGOTTRSP_WriteDeviceRandom_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActGOTTRSP_ReadBuffer_Proxy( 
    IActGOTTRSP __RPC_FAR * This,
    /* [in] */ LONG lStartIO,
    /* [in] */ LONG lAddress,
    /* [in] */ LONG lReadSize,
    /* [size_is][out] */ SHORT __RPC_FAR *lpsData,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActGOTTRSP_ReadBuffer_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActGOTTRSP_WriteBuffer_Proxy( 
    IActGOTTRSP __RPC_FAR * This,
    /* [in] */ LONG lStartIO,
    /* [in] */ LONG lAddress,
    /* [in] */ LONG lWriteSize,
    /* [size_is][in] */ SHORT __RPC_FAR *lpsData,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActGOTTRSP_WriteBuffer_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActGOTTRSP_GetCpuType_Proxy( 
    IActGOTTRSP __RPC_FAR * This,
    /* [string][out] */ BSTR __RPC_FAR *szCpuName,
    /* [out] */ LONG __RPC_FAR *lplCpuCode,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActGOTTRSP_GetCpuType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActGOTTRSP_SetCpuStatus_Proxy( 
    IActGOTTRSP __RPC_FAR * This,
    /* [in] */ LONG lOperation,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActGOTTRSP_SetCpuStatus_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActGOTTRSP_GetClockData_Proxy( 
    IActGOTTRSP __RPC_FAR * This,
    /* [out] */ SHORT __RPC_FAR *lpsYear,
    /* [out] */ SHORT __RPC_FAR *lpsMonth,
    /* [out] */ SHORT __RPC_FAR *lpsDay,
    /* [out] */ SHORT __RPC_FAR *lpsDayOfWeek,
    /* [out] */ SHORT __RPC_FAR *lpsHour,
    /* [out] */ SHORT __RPC_FAR *lpsMinute,
    /* [out] */ SHORT __RPC_FAR *lpsSecond,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActGOTTRSP_GetClockData_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActGOTTRSP_SetClockData_Proxy( 
    IActGOTTRSP __RPC_FAR * This,
    /* [in] */ SHORT sYear,
    /* [in] */ SHORT sMonth,
    /* [in] */ SHORT sDay,
    /* [in] */ SHORT sDayOfWeek,
    /* [in] */ SHORT sHour,
    /* [in] */ SHORT sMinute,
    /* [in] */ SHORT sSecond,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActGOTTRSP_SetClockData_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActGOTTRSP_EntryDeviceStatus_Proxy( 
    IActGOTTRSP __RPC_FAR * This,
    /* [string][in] */ BSTR szDeviceList,
    /* [in] */ LONG lSize,
    /* [in] */ LONG lMonitorCycle,
    /* [size_is][in] */ LONG __RPC_FAR *lplData,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActGOTTRSP_EntryDeviceStatus_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActGOTTRSP_CheckDeviceString_Proxy( 
    IActGOTTRSP __RPC_FAR * This,
    /* [string][in] */ BSTR szDevice,
    /* [in] */ LONG lCheckType,
    /* [in] */ LONG lSize,
    /* [out] */ LONG __RPC_FAR *lplDeviceType,
    /* [string][out] */ BSTR __RPC_FAR *lpszDeviceName,
    /* [out] */ LONG __RPC_FAR *lplDeviceNumber,
    /* [out] */ LONG __RPC_FAR *lplDeviceRadix,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActGOTTRSP_CheckDeviceString_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActGOTTRSP_FreeDeviceStatus_Proxy( 
    IActGOTTRSP __RPC_FAR * This,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActGOTTRSP_FreeDeviceStatus_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActGOTTRSP_ReadDeviceBlock2_Proxy( 
    IActGOTTRSP __RPC_FAR * This,
    /* [string][in] */ BSTR szDevice,
    /* [in] */ LONG lSize,
    /* [size_is][out] */ SHORT __RPC_FAR *lpsData,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActGOTTRSP_ReadDeviceBlock2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActGOTTRSP_WriteDeviceBlock2_Proxy( 
    IActGOTTRSP __RPC_FAR * This,
    /* [string][in] */ BSTR szDevice,
    /* [in] */ LONG lSize,
    /* [size_is][in] */ SHORT __RPC_FAR *lpsData,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActGOTTRSP_WriteDeviceBlock2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActGOTTRSP_ReadDeviceRandom2_Proxy( 
    IActGOTTRSP __RPC_FAR * This,
    /* [string][in] */ BSTR szDeviceList,
    /* [in] */ LONG lSize,
    /* [size_is][out] */ SHORT __RPC_FAR *lpsData,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActGOTTRSP_ReadDeviceRandom2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActGOTTRSP_WriteDeviceRandom2_Proxy( 
    IActGOTTRSP __RPC_FAR * This,
    /* [string][in] */ BSTR szDeviceList,
    /* [in] */ LONG lSize,
    /* [size_is][in] */ SHORT __RPC_FAR *lpsData,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActGOTTRSP_WriteDeviceRandom2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActGOTTRSP_GetDevice2_Proxy( 
    IActGOTTRSP __RPC_FAR * This,
    /* [string][in] */ BSTR szDevice,
    /* [out] */ SHORT __RPC_FAR *lpsData,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActGOTTRSP_GetDevice2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActGOTTRSP_SetDevice2_Proxy( 
    IActGOTTRSP __RPC_FAR * This,
    /* [in] */ BSTR szDevice,
    /* [in] */ SHORT sData,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActGOTTRSP_SetDevice2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActGOTTRSP_get_ActNetworkNumber_Proxy( 
    IActGOTTRSP __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IActGOTTRSP_get_ActNetworkNumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActGOTTRSP_put_ActNetworkNumber_Proxy( 
    IActGOTTRSP __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB IActGOTTRSP_put_ActNetworkNumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActGOTTRSP_get_ActStationNumber_Proxy( 
    IActGOTTRSP __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IActGOTTRSP_get_ActStationNumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActGOTTRSP_put_ActStationNumber_Proxy( 
    IActGOTTRSP __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB IActGOTTRSP_put_ActStationNumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActGOTTRSP_get_ActUnitNumber_Proxy( 
    IActGOTTRSP __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IActGOTTRSP_get_ActUnitNumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActGOTTRSP_put_ActUnitNumber_Proxy( 
    IActGOTTRSP __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB IActGOTTRSP_put_ActUnitNumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActGOTTRSP_get_ActConnectUnitNumber_Proxy( 
    IActGOTTRSP __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IActGOTTRSP_get_ActConnectUnitNumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActGOTTRSP_put_ActConnectUnitNumber_Proxy( 
    IActGOTTRSP __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB IActGOTTRSP_put_ActConnectUnitNumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActGOTTRSP_get_ActIONumber_Proxy( 
    IActGOTTRSP __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IActGOTTRSP_get_ActIONumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActGOTTRSP_put_ActIONumber_Proxy( 
    IActGOTTRSP __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB IActGOTTRSP_put_ActIONumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActGOTTRSP_get_ActCpuType_Proxy( 
    IActGOTTRSP __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IActGOTTRSP_get_ActCpuType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActGOTTRSP_put_ActCpuType_Proxy( 
    IActGOTTRSP __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB IActGOTTRSP_put_ActCpuType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActGOTTRSP_get_ActPortNumber_Proxy( 
    IActGOTTRSP __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IActGOTTRSP_get_ActPortNumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActGOTTRSP_put_ActPortNumber_Proxy( 
    IActGOTTRSP __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB IActGOTTRSP_put_ActPortNumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActGOTTRSP_get_ActBaudRate_Proxy( 
    IActGOTTRSP __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IActGOTTRSP_get_ActBaudRate_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActGOTTRSP_put_ActBaudRate_Proxy( 
    IActGOTTRSP __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB IActGOTTRSP_put_ActBaudRate_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActGOTTRSP_get_ActHostAddress_Proxy( 
    IActGOTTRSP __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *pVal);


void __RPC_STUB IActGOTTRSP_get_ActHostAddress_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActGOTTRSP_put_ActHostAddress_Proxy( 
    IActGOTTRSP __RPC_FAR * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB IActGOTTRSP_put_ActHostAddress_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActGOTTRSP_get_ActTimeOut_Proxy( 
    IActGOTTRSP __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IActGOTTRSP_get_ActTimeOut_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActGOTTRSP_put_ActTimeOut_Proxy( 
    IActGOTTRSP __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB IActGOTTRSP_put_ActTimeOut_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActGOTTRSP_get_ActSourceNetworkNumber_Proxy( 
    IActGOTTRSP __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IActGOTTRSP_get_ActSourceNetworkNumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActGOTTRSP_put_ActSourceNetworkNumber_Proxy( 
    IActGOTTRSP __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB IActGOTTRSP_put_ActSourceNetworkNumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActGOTTRSP_get_ActSourceStationNumber_Proxy( 
    IActGOTTRSP __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IActGOTTRSP_get_ActSourceStationNumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActGOTTRSP_put_ActSourceStationNumber_Proxy( 
    IActGOTTRSP __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB IActGOTTRSP_put_ActSourceStationNumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActGOTTRSP_get_ActDestinationPortNumber_Proxy( 
    IActGOTTRSP __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IActGOTTRSP_get_ActDestinationPortNumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActGOTTRSP_put_ActDestinationPortNumber_Proxy( 
    IActGOTTRSP __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB IActGOTTRSP_put_ActDestinationPortNumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActGOTTRSP_get_ActDestinationIONumber_Proxy( 
    IActGOTTRSP __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IActGOTTRSP_get_ActDestinationIONumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActGOTTRSP_put_ActDestinationIONumber_Proxy( 
    IActGOTTRSP __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB IActGOTTRSP_put_ActDestinationIONumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActGOTTRSP_get_ActMultiDropChannelNumber_Proxy( 
    IActGOTTRSP __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IActGOTTRSP_get_ActMultiDropChannelNumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActGOTTRSP_put_ActMultiDropChannelNumber_Proxy( 
    IActGOTTRSP __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB IActGOTTRSP_put_ActMultiDropChannelNumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActGOTTRSP_get_ActThroughNetworkType_Proxy( 
    IActGOTTRSP __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IActGOTTRSP_get_ActThroughNetworkType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActGOTTRSP_put_ActThroughNetworkType_Proxy( 
    IActGOTTRSP __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB IActGOTTRSP_put_ActThroughNetworkType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActGOTTRSP_get_ActIntelligentPreferenceBit_Proxy( 
    IActGOTTRSP __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IActGOTTRSP_get_ActIntelligentPreferenceBit_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActGOTTRSP_put_ActIntelligentPreferenceBit_Proxy( 
    IActGOTTRSP __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB IActGOTTRSP_put_ActIntelligentPreferenceBit_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActGOTTRSP_get_ActDidPropertyBit_Proxy( 
    IActGOTTRSP __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IActGOTTRSP_get_ActDidPropertyBit_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActGOTTRSP_put_ActDidPropertyBit_Proxy( 
    IActGOTTRSP __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB IActGOTTRSP_put_ActDidPropertyBit_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActGOTTRSP_get_ActDsidPropertyBit_Proxy( 
    IActGOTTRSP __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IActGOTTRSP_get_ActDsidPropertyBit_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActGOTTRSP_put_ActDsidPropertyBit_Proxy( 
    IActGOTTRSP __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB IActGOTTRSP_put_ActDsidPropertyBit_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActGOTTRSP_get_ActGotTransparentPCIf_Proxy( 
    IActGOTTRSP __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IActGOTTRSP_get_ActGotTransparentPCIf_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActGOTTRSP_put_ActGotTransparentPCIf_Proxy( 
    IActGOTTRSP __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB IActGOTTRSP_put_ActGotTransparentPCIf_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActGOTTRSP_get_ActGotTransparentPLCIf_Proxy( 
    IActGOTTRSP __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IActGOTTRSP_get_ActGotTransparentPLCIf_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActGOTTRSP_put_ActGotTransparentPLCIf_Proxy( 
    IActGOTTRSP __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB IActGOTTRSP_put_ActGotTransparentPLCIf_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IActGOTTRSP_INTERFACE_DEFINED__ */


#ifndef __IActGOTTRSP2_INTERFACE_DEFINED__
#define __IActGOTTRSP2_INTERFACE_DEFINED__

/* interface IActGOTTRSP2 */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IActGOTTRSP2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("95A13658-F8C9-42e8-8DBE-205C9C46DC75")
    IActGOTTRSP2 : public IActGOTTRSP
    {
    public:
    };
    
#else 	/* C style interface */

    typedef struct IActGOTTRSP2Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IActGOTTRSP2 __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IActGOTTRSP2 __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IActGOTTRSP2 __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IActGOTTRSP2 __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IActGOTTRSP2 __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IActGOTTRSP2 __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IActGOTTRSP2 __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Open )( 
            IActGOTTRSP2 __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Close )( 
            IActGOTTRSP2 __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetDevice )( 
            IActGOTTRSP2 __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [out] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetDevice )( 
            IActGOTTRSP2 __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceBlock )( 
            IActGOTTRSP2 __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lSize,
            /* [size_is][out] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceBlock )( 
            IActGOTTRSP2 __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lSize,
            /* [size_is][in] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceRandom )( 
            IActGOTTRSP2 __RPC_FAR * This,
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG lSize,
            /* [size_is][out] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceRandom )( 
            IActGOTTRSP2 __RPC_FAR * This,
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG lSize,
            /* [size_is][in] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadBuffer )( 
            IActGOTTRSP2 __RPC_FAR * This,
            /* [in] */ LONG lStartIO,
            /* [in] */ LONG lAddress,
            /* [in] */ LONG lReadSize,
            /* [size_is][out] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteBuffer )( 
            IActGOTTRSP2 __RPC_FAR * This,
            /* [in] */ LONG lStartIO,
            /* [in] */ LONG lAddress,
            /* [in] */ LONG lWriteSize,
            /* [size_is][in] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetCpuType )( 
            IActGOTTRSP2 __RPC_FAR * This,
            /* [string][out] */ BSTR __RPC_FAR *szCpuName,
            /* [out] */ LONG __RPC_FAR *lplCpuCode,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetCpuStatus )( 
            IActGOTTRSP2 __RPC_FAR * This,
            /* [in] */ LONG lOperation,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetClockData )( 
            IActGOTTRSP2 __RPC_FAR * This,
            /* [out] */ SHORT __RPC_FAR *lpsYear,
            /* [out] */ SHORT __RPC_FAR *lpsMonth,
            /* [out] */ SHORT __RPC_FAR *lpsDay,
            /* [out] */ SHORT __RPC_FAR *lpsDayOfWeek,
            /* [out] */ SHORT __RPC_FAR *lpsHour,
            /* [out] */ SHORT __RPC_FAR *lpsMinute,
            /* [out] */ SHORT __RPC_FAR *lpsSecond,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetClockData )( 
            IActGOTTRSP2 __RPC_FAR * This,
            /* [in] */ SHORT sYear,
            /* [in] */ SHORT sMonth,
            /* [in] */ SHORT sDay,
            /* [in] */ SHORT sDayOfWeek,
            /* [in] */ SHORT sHour,
            /* [in] */ SHORT sMinute,
            /* [in] */ SHORT sSecond,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *EntryDeviceStatus )( 
            IActGOTTRSP2 __RPC_FAR * This,
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG lSize,
            /* [in] */ LONG lMonitorCycle,
            /* [size_is][in] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CheckDeviceString )( 
            IActGOTTRSP2 __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lCheckType,
            /* [in] */ LONG lSize,
            /* [out] */ LONG __RPC_FAR *lplDeviceType,
            /* [string][out] */ BSTR __RPC_FAR *lpszDeviceName,
            /* [out] */ LONG __RPC_FAR *lplDeviceNumber,
            /* [out] */ LONG __RPC_FAR *lplDeviceRadix,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *FreeDeviceStatus )( 
            IActGOTTRSP2 __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceBlock2 )( 
            IActGOTTRSP2 __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lSize,
            /* [size_is][out] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceBlock2 )( 
            IActGOTTRSP2 __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lSize,
            /* [size_is][in] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceRandom2 )( 
            IActGOTTRSP2 __RPC_FAR * This,
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG lSize,
            /* [size_is][out] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceRandom2 )( 
            IActGOTTRSP2 __RPC_FAR * This,
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG lSize,
            /* [size_is][in] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetDevice2 )( 
            IActGOTTRSP2 __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [out] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetDevice2 )( 
            IActGOTTRSP2 __RPC_FAR * This,
            /* [in] */ BSTR szDevice,
            /* [in] */ SHORT sData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActNetworkNumber )( 
            IActGOTTRSP2 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActNetworkNumber )( 
            IActGOTTRSP2 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActStationNumber )( 
            IActGOTTRSP2 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActStationNumber )( 
            IActGOTTRSP2 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActUnitNumber )( 
            IActGOTTRSP2 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActUnitNumber )( 
            IActGOTTRSP2 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActConnectUnitNumber )( 
            IActGOTTRSP2 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActConnectUnitNumber )( 
            IActGOTTRSP2 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActIONumber )( 
            IActGOTTRSP2 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActIONumber )( 
            IActGOTTRSP2 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActCpuType )( 
            IActGOTTRSP2 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActCpuType )( 
            IActGOTTRSP2 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActPortNumber )( 
            IActGOTTRSP2 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActPortNumber )( 
            IActGOTTRSP2 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActBaudRate )( 
            IActGOTTRSP2 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActBaudRate )( 
            IActGOTTRSP2 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActHostAddress )( 
            IActGOTTRSP2 __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActHostAddress )( 
            IActGOTTRSP2 __RPC_FAR * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActTimeOut )( 
            IActGOTTRSP2 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActTimeOut )( 
            IActGOTTRSP2 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActSourceNetworkNumber )( 
            IActGOTTRSP2 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActSourceNetworkNumber )( 
            IActGOTTRSP2 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActSourceStationNumber )( 
            IActGOTTRSP2 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActSourceStationNumber )( 
            IActGOTTRSP2 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActDestinationPortNumber )( 
            IActGOTTRSP2 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActDestinationPortNumber )( 
            IActGOTTRSP2 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActDestinationIONumber )( 
            IActGOTTRSP2 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActDestinationIONumber )( 
            IActGOTTRSP2 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActMultiDropChannelNumber )( 
            IActGOTTRSP2 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActMultiDropChannelNumber )( 
            IActGOTTRSP2 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActThroughNetworkType )( 
            IActGOTTRSP2 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActThroughNetworkType )( 
            IActGOTTRSP2 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActIntelligentPreferenceBit )( 
            IActGOTTRSP2 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActIntelligentPreferenceBit )( 
            IActGOTTRSP2 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActDidPropertyBit )( 
            IActGOTTRSP2 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActDidPropertyBit )( 
            IActGOTTRSP2 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActDsidPropertyBit )( 
            IActGOTTRSP2 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActDsidPropertyBit )( 
            IActGOTTRSP2 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActGotTransparentPCIf )( 
            IActGOTTRSP2 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActGotTransparentPCIf )( 
            IActGOTTRSP2 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActGotTransparentPLCIf )( 
            IActGOTTRSP2 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActGotTransparentPLCIf )( 
            IActGOTTRSP2 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        END_INTERFACE
    } IActGOTTRSP2Vtbl;

    interface IActGOTTRSP2
    {
        CONST_VTBL struct IActGOTTRSP2Vtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IActGOTTRSP2_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IActGOTTRSP2_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IActGOTTRSP2_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IActGOTTRSP2_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IActGOTTRSP2_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IActGOTTRSP2_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IActGOTTRSP2_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IActGOTTRSP2_Open(This,lplReturnCode)	\
    (This)->lpVtbl -> Open(This,lplReturnCode)

#define IActGOTTRSP2_Close(This,lplReturnCode)	\
    (This)->lpVtbl -> Close(This,lplReturnCode)

#define IActGOTTRSP2_GetDevice(This,szDevice,lplData,lplReturnCode)	\
    (This)->lpVtbl -> GetDevice(This,szDevice,lplData,lplReturnCode)

#define IActGOTTRSP2_SetDevice(This,szDevice,lData,lplReturnCode)	\
    (This)->lpVtbl -> SetDevice(This,szDevice,lData,lplReturnCode)

#define IActGOTTRSP2_ReadDeviceBlock(This,szDevice,lSize,lplData,lplReturnCode)	\
    (This)->lpVtbl -> ReadDeviceBlock(This,szDevice,lSize,lplData,lplReturnCode)

#define IActGOTTRSP2_WriteDeviceBlock(This,szDevice,lSize,lplData,lplReturnCode)	\
    (This)->lpVtbl -> WriteDeviceBlock(This,szDevice,lSize,lplData,lplReturnCode)

#define IActGOTTRSP2_ReadDeviceRandom(This,szDeviceList,lSize,lplData,lplReturnCode)	\
    (This)->lpVtbl -> ReadDeviceRandom(This,szDeviceList,lSize,lplData,lplReturnCode)

#define IActGOTTRSP2_WriteDeviceRandom(This,szDeviceList,lSize,lplData,lplReturnCode)	\
    (This)->lpVtbl -> WriteDeviceRandom(This,szDeviceList,lSize,lplData,lplReturnCode)

#define IActGOTTRSP2_ReadBuffer(This,lStartIO,lAddress,lReadSize,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> ReadBuffer(This,lStartIO,lAddress,lReadSize,lpsData,lplReturnCode)

#define IActGOTTRSP2_WriteBuffer(This,lStartIO,lAddress,lWriteSize,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> WriteBuffer(This,lStartIO,lAddress,lWriteSize,lpsData,lplReturnCode)

#define IActGOTTRSP2_GetCpuType(This,szCpuName,lplCpuCode,lplReturnCode)	\
    (This)->lpVtbl -> GetCpuType(This,szCpuName,lplCpuCode,lplReturnCode)

#define IActGOTTRSP2_SetCpuStatus(This,lOperation,lplReturnCode)	\
    (This)->lpVtbl -> SetCpuStatus(This,lOperation,lplReturnCode)

#define IActGOTTRSP2_GetClockData(This,lpsYear,lpsMonth,lpsDay,lpsDayOfWeek,lpsHour,lpsMinute,lpsSecond,lplReturnCode)	\
    (This)->lpVtbl -> GetClockData(This,lpsYear,lpsMonth,lpsDay,lpsDayOfWeek,lpsHour,lpsMinute,lpsSecond,lplReturnCode)

#define IActGOTTRSP2_SetClockData(This,sYear,sMonth,sDay,sDayOfWeek,sHour,sMinute,sSecond,lplReturnCode)	\
    (This)->lpVtbl -> SetClockData(This,sYear,sMonth,sDay,sDayOfWeek,sHour,sMinute,sSecond,lplReturnCode)

#define IActGOTTRSP2_EntryDeviceStatus(This,szDeviceList,lSize,lMonitorCycle,lplData,lplReturnCode)	\
    (This)->lpVtbl -> EntryDeviceStatus(This,szDeviceList,lSize,lMonitorCycle,lplData,lplReturnCode)

#define IActGOTTRSP2_CheckDeviceString(This,szDevice,lCheckType,lSize,lplDeviceType,lpszDeviceName,lplDeviceNumber,lplDeviceRadix,lplReturnCode)	\
    (This)->lpVtbl -> CheckDeviceString(This,szDevice,lCheckType,lSize,lplDeviceType,lpszDeviceName,lplDeviceNumber,lplDeviceRadix,lplReturnCode)

#define IActGOTTRSP2_FreeDeviceStatus(This,lplReturnCode)	\
    (This)->lpVtbl -> FreeDeviceStatus(This,lplReturnCode)

#define IActGOTTRSP2_ReadDeviceBlock2(This,szDevice,lSize,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> ReadDeviceBlock2(This,szDevice,lSize,lpsData,lplReturnCode)

#define IActGOTTRSP2_WriteDeviceBlock2(This,szDevice,lSize,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> WriteDeviceBlock2(This,szDevice,lSize,lpsData,lplReturnCode)

#define IActGOTTRSP2_ReadDeviceRandom2(This,szDeviceList,lSize,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> ReadDeviceRandom2(This,szDeviceList,lSize,lpsData,lplReturnCode)

#define IActGOTTRSP2_WriteDeviceRandom2(This,szDeviceList,lSize,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> WriteDeviceRandom2(This,szDeviceList,lSize,lpsData,lplReturnCode)

#define IActGOTTRSP2_GetDevice2(This,szDevice,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> GetDevice2(This,szDevice,lpsData,lplReturnCode)

#define IActGOTTRSP2_SetDevice2(This,szDevice,sData,lplReturnCode)	\
    (This)->lpVtbl -> SetDevice2(This,szDevice,sData,lplReturnCode)

#define IActGOTTRSP2_get_ActNetworkNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActNetworkNumber(This,pVal)

#define IActGOTTRSP2_put_ActNetworkNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActNetworkNumber(This,newVal)

#define IActGOTTRSP2_get_ActStationNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActStationNumber(This,pVal)

#define IActGOTTRSP2_put_ActStationNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActStationNumber(This,newVal)

#define IActGOTTRSP2_get_ActUnitNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActUnitNumber(This,pVal)

#define IActGOTTRSP2_put_ActUnitNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActUnitNumber(This,newVal)

#define IActGOTTRSP2_get_ActConnectUnitNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActConnectUnitNumber(This,pVal)

#define IActGOTTRSP2_put_ActConnectUnitNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActConnectUnitNumber(This,newVal)

#define IActGOTTRSP2_get_ActIONumber(This,pVal)	\
    (This)->lpVtbl -> get_ActIONumber(This,pVal)

#define IActGOTTRSP2_put_ActIONumber(This,newVal)	\
    (This)->lpVtbl -> put_ActIONumber(This,newVal)

#define IActGOTTRSP2_get_ActCpuType(This,pVal)	\
    (This)->lpVtbl -> get_ActCpuType(This,pVal)

#define IActGOTTRSP2_put_ActCpuType(This,newVal)	\
    (This)->lpVtbl -> put_ActCpuType(This,newVal)

#define IActGOTTRSP2_get_ActPortNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActPortNumber(This,pVal)

#define IActGOTTRSP2_put_ActPortNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActPortNumber(This,newVal)

#define IActGOTTRSP2_get_ActBaudRate(This,pVal)	\
    (This)->lpVtbl -> get_ActBaudRate(This,pVal)

#define IActGOTTRSP2_put_ActBaudRate(This,newVal)	\
    (This)->lpVtbl -> put_ActBaudRate(This,newVal)

#define IActGOTTRSP2_get_ActHostAddress(This,pVal)	\
    (This)->lpVtbl -> get_ActHostAddress(This,pVal)

#define IActGOTTRSP2_put_ActHostAddress(This,newVal)	\
    (This)->lpVtbl -> put_ActHostAddress(This,newVal)

#define IActGOTTRSP2_get_ActTimeOut(This,pVal)	\
    (This)->lpVtbl -> get_ActTimeOut(This,pVal)

#define IActGOTTRSP2_put_ActTimeOut(This,newVal)	\
    (This)->lpVtbl -> put_ActTimeOut(This,newVal)

#define IActGOTTRSP2_get_ActSourceNetworkNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActSourceNetworkNumber(This,pVal)

#define IActGOTTRSP2_put_ActSourceNetworkNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActSourceNetworkNumber(This,newVal)

#define IActGOTTRSP2_get_ActSourceStationNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActSourceStationNumber(This,pVal)

#define IActGOTTRSP2_put_ActSourceStationNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActSourceStationNumber(This,newVal)

#define IActGOTTRSP2_get_ActDestinationPortNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActDestinationPortNumber(This,pVal)

#define IActGOTTRSP2_put_ActDestinationPortNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActDestinationPortNumber(This,newVal)

#define IActGOTTRSP2_get_ActDestinationIONumber(This,pVal)	\
    (This)->lpVtbl -> get_ActDestinationIONumber(This,pVal)

#define IActGOTTRSP2_put_ActDestinationIONumber(This,newVal)	\
    (This)->lpVtbl -> put_ActDestinationIONumber(This,newVal)

#define IActGOTTRSP2_get_ActMultiDropChannelNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActMultiDropChannelNumber(This,pVal)

#define IActGOTTRSP2_put_ActMultiDropChannelNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActMultiDropChannelNumber(This,newVal)

#define IActGOTTRSP2_get_ActThroughNetworkType(This,pVal)	\
    (This)->lpVtbl -> get_ActThroughNetworkType(This,pVal)

#define IActGOTTRSP2_put_ActThroughNetworkType(This,newVal)	\
    (This)->lpVtbl -> put_ActThroughNetworkType(This,newVal)

#define IActGOTTRSP2_get_ActIntelligentPreferenceBit(This,pVal)	\
    (This)->lpVtbl -> get_ActIntelligentPreferenceBit(This,pVal)

#define IActGOTTRSP2_put_ActIntelligentPreferenceBit(This,newVal)	\
    (This)->lpVtbl -> put_ActIntelligentPreferenceBit(This,newVal)

#define IActGOTTRSP2_get_ActDidPropertyBit(This,pVal)	\
    (This)->lpVtbl -> get_ActDidPropertyBit(This,pVal)

#define IActGOTTRSP2_put_ActDidPropertyBit(This,newVal)	\
    (This)->lpVtbl -> put_ActDidPropertyBit(This,newVal)

#define IActGOTTRSP2_get_ActDsidPropertyBit(This,pVal)	\
    (This)->lpVtbl -> get_ActDsidPropertyBit(This,pVal)

#define IActGOTTRSP2_put_ActDsidPropertyBit(This,newVal)	\
    (This)->lpVtbl -> put_ActDsidPropertyBit(This,newVal)

#define IActGOTTRSP2_get_ActGotTransparentPCIf(This,pVal)	\
    (This)->lpVtbl -> get_ActGotTransparentPCIf(This,pVal)

#define IActGOTTRSP2_put_ActGotTransparentPCIf(This,newVal)	\
    (This)->lpVtbl -> put_ActGotTransparentPCIf(This,newVal)

#define IActGOTTRSP2_get_ActGotTransparentPLCIf(This,pVal)	\
    (This)->lpVtbl -> get_ActGotTransparentPLCIf(This,pVal)

#define IActGOTTRSP2_put_ActGotTransparentPLCIf(This,newVal)	\
    (This)->lpVtbl -> put_ActGotTransparentPLCIf(This,newVal)


#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IActGOTTRSP2_INTERFACE_DEFINED__ */


#ifndef __IActGOTTRSP3_INTERFACE_DEFINED__
#define __IActGOTTRSP3_INTERFACE_DEFINED__

/* interface IActGOTTRSP3 */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IActGOTTRSP3;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("21C0FDCF-28EB-458f-9CF9-E9ECF0C4FCAA")
    IActGOTTRSP3 : public IActGOTTRSP2
    {
    public:
    };
    
#else 	/* C style interface */

    typedef struct IActGOTTRSP3Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IActGOTTRSP3 __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IActGOTTRSP3 __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IActGOTTRSP3 __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IActGOTTRSP3 __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IActGOTTRSP3 __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IActGOTTRSP3 __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IActGOTTRSP3 __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Open )( 
            IActGOTTRSP3 __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Close )( 
            IActGOTTRSP3 __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetDevice )( 
            IActGOTTRSP3 __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [out] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetDevice )( 
            IActGOTTRSP3 __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceBlock )( 
            IActGOTTRSP3 __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lSize,
            /* [size_is][out] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceBlock )( 
            IActGOTTRSP3 __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lSize,
            /* [size_is][in] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceRandom )( 
            IActGOTTRSP3 __RPC_FAR * This,
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG lSize,
            /* [size_is][out] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceRandom )( 
            IActGOTTRSP3 __RPC_FAR * This,
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG lSize,
            /* [size_is][in] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadBuffer )( 
            IActGOTTRSP3 __RPC_FAR * This,
            /* [in] */ LONG lStartIO,
            /* [in] */ LONG lAddress,
            /* [in] */ LONG lReadSize,
            /* [size_is][out] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteBuffer )( 
            IActGOTTRSP3 __RPC_FAR * This,
            /* [in] */ LONG lStartIO,
            /* [in] */ LONG lAddress,
            /* [in] */ LONG lWriteSize,
            /* [size_is][in] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetCpuType )( 
            IActGOTTRSP3 __RPC_FAR * This,
            /* [string][out] */ BSTR __RPC_FAR *szCpuName,
            /* [out] */ LONG __RPC_FAR *lplCpuCode,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetCpuStatus )( 
            IActGOTTRSP3 __RPC_FAR * This,
            /* [in] */ LONG lOperation,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetClockData )( 
            IActGOTTRSP3 __RPC_FAR * This,
            /* [out] */ SHORT __RPC_FAR *lpsYear,
            /* [out] */ SHORT __RPC_FAR *lpsMonth,
            /* [out] */ SHORT __RPC_FAR *lpsDay,
            /* [out] */ SHORT __RPC_FAR *lpsDayOfWeek,
            /* [out] */ SHORT __RPC_FAR *lpsHour,
            /* [out] */ SHORT __RPC_FAR *lpsMinute,
            /* [out] */ SHORT __RPC_FAR *lpsSecond,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetClockData )( 
            IActGOTTRSP3 __RPC_FAR * This,
            /* [in] */ SHORT sYear,
            /* [in] */ SHORT sMonth,
            /* [in] */ SHORT sDay,
            /* [in] */ SHORT sDayOfWeek,
            /* [in] */ SHORT sHour,
            /* [in] */ SHORT sMinute,
            /* [in] */ SHORT sSecond,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *EntryDeviceStatus )( 
            IActGOTTRSP3 __RPC_FAR * This,
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG lSize,
            /* [in] */ LONG lMonitorCycle,
            /* [size_is][in] */ LONG __RPC_FAR *lplData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CheckDeviceString )( 
            IActGOTTRSP3 __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lCheckType,
            /* [in] */ LONG lSize,
            /* [out] */ LONG __RPC_FAR *lplDeviceType,
            /* [string][out] */ BSTR __RPC_FAR *lpszDeviceName,
            /* [out] */ LONG __RPC_FAR *lplDeviceNumber,
            /* [out] */ LONG __RPC_FAR *lplDeviceRadix,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *FreeDeviceStatus )( 
            IActGOTTRSP3 __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceBlock2 )( 
            IActGOTTRSP3 __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lSize,
            /* [size_is][out] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceBlock2 )( 
            IActGOTTRSP3 __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lSize,
            /* [size_is][in] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceRandom2 )( 
            IActGOTTRSP3 __RPC_FAR * This,
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG lSize,
            /* [size_is][out] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceRandom2 )( 
            IActGOTTRSP3 __RPC_FAR * This,
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG lSize,
            /* [size_is][in] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetDevice2 )( 
            IActGOTTRSP3 __RPC_FAR * This,
            /* [string][in] */ BSTR szDevice,
            /* [out] */ SHORT __RPC_FAR *lpsData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetDevice2 )( 
            IActGOTTRSP3 __RPC_FAR * This,
            /* [in] */ BSTR szDevice,
            /* [in] */ SHORT sData,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActNetworkNumber )( 
            IActGOTTRSP3 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActNetworkNumber )( 
            IActGOTTRSP3 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActStationNumber )( 
            IActGOTTRSP3 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActStationNumber )( 
            IActGOTTRSP3 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActUnitNumber )( 
            IActGOTTRSP3 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActUnitNumber )( 
            IActGOTTRSP3 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActConnectUnitNumber )( 
            IActGOTTRSP3 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActConnectUnitNumber )( 
            IActGOTTRSP3 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActIONumber )( 
            IActGOTTRSP3 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActIONumber )( 
            IActGOTTRSP3 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActCpuType )( 
            IActGOTTRSP3 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActCpuType )( 
            IActGOTTRSP3 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActPortNumber )( 
            IActGOTTRSP3 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActPortNumber )( 
            IActGOTTRSP3 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActBaudRate )( 
            IActGOTTRSP3 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActBaudRate )( 
            IActGOTTRSP3 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActHostAddress )( 
            IActGOTTRSP3 __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActHostAddress )( 
            IActGOTTRSP3 __RPC_FAR * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActTimeOut )( 
            IActGOTTRSP3 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActTimeOut )( 
            IActGOTTRSP3 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActSourceNetworkNumber )( 
            IActGOTTRSP3 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActSourceNetworkNumber )( 
            IActGOTTRSP3 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActSourceStationNumber )( 
            IActGOTTRSP3 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActSourceStationNumber )( 
            IActGOTTRSP3 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActDestinationPortNumber )( 
            IActGOTTRSP3 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActDestinationPortNumber )( 
            IActGOTTRSP3 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActDestinationIONumber )( 
            IActGOTTRSP3 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActDestinationIONumber )( 
            IActGOTTRSP3 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActMultiDropChannelNumber )( 
            IActGOTTRSP3 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActMultiDropChannelNumber )( 
            IActGOTTRSP3 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActThroughNetworkType )( 
            IActGOTTRSP3 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActThroughNetworkType )( 
            IActGOTTRSP3 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActIntelligentPreferenceBit )( 
            IActGOTTRSP3 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActIntelligentPreferenceBit )( 
            IActGOTTRSP3 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActDidPropertyBit )( 
            IActGOTTRSP3 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActDidPropertyBit )( 
            IActGOTTRSP3 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActDsidPropertyBit )( 
            IActGOTTRSP3 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActDsidPropertyBit )( 
            IActGOTTRSP3 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActGotTransparentPCIf )( 
            IActGOTTRSP3 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActGotTransparentPCIf )( 
            IActGOTTRSP3 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActGotTransparentPLCIf )( 
            IActGOTTRSP3 __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActGotTransparentPLCIf )( 
            IActGOTTRSP3 __RPC_FAR * This,
            /* [in] */ long newVal);
        
        END_INTERFACE
    } IActGOTTRSP3Vtbl;

    interface IActGOTTRSP3
    {
        CONST_VTBL struct IActGOTTRSP3Vtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IActGOTTRSP3_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IActGOTTRSP3_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IActGOTTRSP3_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IActGOTTRSP3_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IActGOTTRSP3_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IActGOTTRSP3_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IActGOTTRSP3_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IActGOTTRSP3_Open(This,lplReturnCode)	\
    (This)->lpVtbl -> Open(This,lplReturnCode)

#define IActGOTTRSP3_Close(This,lplReturnCode)	\
    (This)->lpVtbl -> Close(This,lplReturnCode)

#define IActGOTTRSP3_GetDevice(This,szDevice,lplData,lplReturnCode)	\
    (This)->lpVtbl -> GetDevice(This,szDevice,lplData,lplReturnCode)

#define IActGOTTRSP3_SetDevice(This,szDevice,lData,lplReturnCode)	\
    (This)->lpVtbl -> SetDevice(This,szDevice,lData,lplReturnCode)

#define IActGOTTRSP3_ReadDeviceBlock(This,szDevice,lSize,lplData,lplReturnCode)	\
    (This)->lpVtbl -> ReadDeviceBlock(This,szDevice,lSize,lplData,lplReturnCode)

#define IActGOTTRSP3_WriteDeviceBlock(This,szDevice,lSize,lplData,lplReturnCode)	\
    (This)->lpVtbl -> WriteDeviceBlock(This,szDevice,lSize,lplData,lplReturnCode)

#define IActGOTTRSP3_ReadDeviceRandom(This,szDeviceList,lSize,lplData,lplReturnCode)	\
    (This)->lpVtbl -> ReadDeviceRandom(This,szDeviceList,lSize,lplData,lplReturnCode)

#define IActGOTTRSP3_WriteDeviceRandom(This,szDeviceList,lSize,lplData,lplReturnCode)	\
    (This)->lpVtbl -> WriteDeviceRandom(This,szDeviceList,lSize,lplData,lplReturnCode)

#define IActGOTTRSP3_ReadBuffer(This,lStartIO,lAddress,lReadSize,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> ReadBuffer(This,lStartIO,lAddress,lReadSize,lpsData,lplReturnCode)

#define IActGOTTRSP3_WriteBuffer(This,lStartIO,lAddress,lWriteSize,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> WriteBuffer(This,lStartIO,lAddress,lWriteSize,lpsData,lplReturnCode)

#define IActGOTTRSP3_GetCpuType(This,szCpuName,lplCpuCode,lplReturnCode)	\
    (This)->lpVtbl -> GetCpuType(This,szCpuName,lplCpuCode,lplReturnCode)

#define IActGOTTRSP3_SetCpuStatus(This,lOperation,lplReturnCode)	\
    (This)->lpVtbl -> SetCpuStatus(This,lOperation,lplReturnCode)

#define IActGOTTRSP3_GetClockData(This,lpsYear,lpsMonth,lpsDay,lpsDayOfWeek,lpsHour,lpsMinute,lpsSecond,lplReturnCode)	\
    (This)->lpVtbl -> GetClockData(This,lpsYear,lpsMonth,lpsDay,lpsDayOfWeek,lpsHour,lpsMinute,lpsSecond,lplReturnCode)

#define IActGOTTRSP3_SetClockData(This,sYear,sMonth,sDay,sDayOfWeek,sHour,sMinute,sSecond,lplReturnCode)	\
    (This)->lpVtbl -> SetClockData(This,sYear,sMonth,sDay,sDayOfWeek,sHour,sMinute,sSecond,lplReturnCode)

#define IActGOTTRSP3_EntryDeviceStatus(This,szDeviceList,lSize,lMonitorCycle,lplData,lplReturnCode)	\
    (This)->lpVtbl -> EntryDeviceStatus(This,szDeviceList,lSize,lMonitorCycle,lplData,lplReturnCode)

#define IActGOTTRSP3_CheckDeviceString(This,szDevice,lCheckType,lSize,lplDeviceType,lpszDeviceName,lplDeviceNumber,lplDeviceRadix,lplReturnCode)	\
    (This)->lpVtbl -> CheckDeviceString(This,szDevice,lCheckType,lSize,lplDeviceType,lpszDeviceName,lplDeviceNumber,lplDeviceRadix,lplReturnCode)

#define IActGOTTRSP3_FreeDeviceStatus(This,lplReturnCode)	\
    (This)->lpVtbl -> FreeDeviceStatus(This,lplReturnCode)

#define IActGOTTRSP3_ReadDeviceBlock2(This,szDevice,lSize,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> ReadDeviceBlock2(This,szDevice,lSize,lpsData,lplReturnCode)

#define IActGOTTRSP3_WriteDeviceBlock2(This,szDevice,lSize,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> WriteDeviceBlock2(This,szDevice,lSize,lpsData,lplReturnCode)

#define IActGOTTRSP3_ReadDeviceRandom2(This,szDeviceList,lSize,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> ReadDeviceRandom2(This,szDeviceList,lSize,lpsData,lplReturnCode)

#define IActGOTTRSP3_WriteDeviceRandom2(This,szDeviceList,lSize,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> WriteDeviceRandom2(This,szDeviceList,lSize,lpsData,lplReturnCode)

#define IActGOTTRSP3_GetDevice2(This,szDevice,lpsData,lplReturnCode)	\
    (This)->lpVtbl -> GetDevice2(This,szDevice,lpsData,lplReturnCode)

#define IActGOTTRSP3_SetDevice2(This,szDevice,sData,lplReturnCode)	\
    (This)->lpVtbl -> SetDevice2(This,szDevice,sData,lplReturnCode)

#define IActGOTTRSP3_get_ActNetworkNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActNetworkNumber(This,pVal)

#define IActGOTTRSP3_put_ActNetworkNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActNetworkNumber(This,newVal)

#define IActGOTTRSP3_get_ActStationNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActStationNumber(This,pVal)

#define IActGOTTRSP3_put_ActStationNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActStationNumber(This,newVal)

#define IActGOTTRSP3_get_ActUnitNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActUnitNumber(This,pVal)

#define IActGOTTRSP3_put_ActUnitNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActUnitNumber(This,newVal)

#define IActGOTTRSP3_get_ActConnectUnitNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActConnectUnitNumber(This,pVal)

#define IActGOTTRSP3_put_ActConnectUnitNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActConnectUnitNumber(This,newVal)

#define IActGOTTRSP3_get_ActIONumber(This,pVal)	\
    (This)->lpVtbl -> get_ActIONumber(This,pVal)

#define IActGOTTRSP3_put_ActIONumber(This,newVal)	\
    (This)->lpVtbl -> put_ActIONumber(This,newVal)

#define IActGOTTRSP3_get_ActCpuType(This,pVal)	\
    (This)->lpVtbl -> get_ActCpuType(This,pVal)

#define IActGOTTRSP3_put_ActCpuType(This,newVal)	\
    (This)->lpVtbl -> put_ActCpuType(This,newVal)

#define IActGOTTRSP3_get_ActPortNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActPortNumber(This,pVal)

#define IActGOTTRSP3_put_ActPortNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActPortNumber(This,newVal)

#define IActGOTTRSP3_get_ActBaudRate(This,pVal)	\
    (This)->lpVtbl -> get_ActBaudRate(This,pVal)

#define IActGOTTRSP3_put_ActBaudRate(This,newVal)	\
    (This)->lpVtbl -> put_ActBaudRate(This,newVal)

#define IActGOTTRSP3_get_ActHostAddress(This,pVal)	\
    (This)->lpVtbl -> get_ActHostAddress(This,pVal)

#define IActGOTTRSP3_put_ActHostAddress(This,newVal)	\
    (This)->lpVtbl -> put_ActHostAddress(This,newVal)

#define IActGOTTRSP3_get_ActTimeOut(This,pVal)	\
    (This)->lpVtbl -> get_ActTimeOut(This,pVal)

#define IActGOTTRSP3_put_ActTimeOut(This,newVal)	\
    (This)->lpVtbl -> put_ActTimeOut(This,newVal)

#define IActGOTTRSP3_get_ActSourceNetworkNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActSourceNetworkNumber(This,pVal)

#define IActGOTTRSP3_put_ActSourceNetworkNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActSourceNetworkNumber(This,newVal)

#define IActGOTTRSP3_get_ActSourceStationNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActSourceStationNumber(This,pVal)

#define IActGOTTRSP3_put_ActSourceStationNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActSourceStationNumber(This,newVal)

#define IActGOTTRSP3_get_ActDestinationPortNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActDestinationPortNumber(This,pVal)

#define IActGOTTRSP3_put_ActDestinationPortNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActDestinationPortNumber(This,newVal)

#define IActGOTTRSP3_get_ActDestinationIONumber(This,pVal)	\
    (This)->lpVtbl -> get_ActDestinationIONumber(This,pVal)

#define IActGOTTRSP3_put_ActDestinationIONumber(This,newVal)	\
    (This)->lpVtbl -> put_ActDestinationIONumber(This,newVal)

#define IActGOTTRSP3_get_ActMultiDropChannelNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActMultiDropChannelNumber(This,pVal)

#define IActGOTTRSP3_put_ActMultiDropChannelNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActMultiDropChannelNumber(This,newVal)

#define IActGOTTRSP3_get_ActThroughNetworkType(This,pVal)	\
    (This)->lpVtbl -> get_ActThroughNetworkType(This,pVal)

#define IActGOTTRSP3_put_ActThroughNetworkType(This,newVal)	\
    (This)->lpVtbl -> put_ActThroughNetworkType(This,newVal)

#define IActGOTTRSP3_get_ActIntelligentPreferenceBit(This,pVal)	\
    (This)->lpVtbl -> get_ActIntelligentPreferenceBit(This,pVal)

#define IActGOTTRSP3_put_ActIntelligentPreferenceBit(This,newVal)	\
    (This)->lpVtbl -> put_ActIntelligentPreferenceBit(This,newVal)

#define IActGOTTRSP3_get_ActDidPropertyBit(This,pVal)	\
    (This)->lpVtbl -> get_ActDidPropertyBit(This,pVal)

#define IActGOTTRSP3_put_ActDidPropertyBit(This,newVal)	\
    (This)->lpVtbl -> put_ActDidPropertyBit(This,newVal)

#define IActGOTTRSP3_get_ActDsidPropertyBit(This,pVal)	\
    (This)->lpVtbl -> get_ActDsidPropertyBit(This,pVal)

#define IActGOTTRSP3_put_ActDsidPropertyBit(This,newVal)	\
    (This)->lpVtbl -> put_ActDsidPropertyBit(This,newVal)

#define IActGOTTRSP3_get_ActGotTransparentPCIf(This,pVal)	\
    (This)->lpVtbl -> get_ActGotTransparentPCIf(This,pVal)

#define IActGOTTRSP3_put_ActGotTransparentPCIf(This,newVal)	\
    (This)->lpVtbl -> put_ActGotTransparentPCIf(This,newVal)

#define IActGOTTRSP3_get_ActGotTransparentPLCIf(This,pVal)	\
    (This)->lpVtbl -> get_ActGotTransparentPLCIf(This,pVal)

#define IActGOTTRSP3_put_ActGotTransparentPLCIf(This,newVal)	\
    (This)->lpVtbl -> put_ActGotTransparentPLCIf(This,newVal)



#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IActGOTTRSP3_INTERFACE_DEFINED__ */


#ifndef __IActMLGOTTRSP_INTERFACE_DEFINED__
#define __IActMLGOTTRSP_INTERFACE_DEFINED__

/* interface IActMLGOTTRSP */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IActMLGOTTRSP;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("927AB688-595C-47FE-8B04-FCCB52127C7E")
    IActMLGOTTRSP : public IDispatch
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
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActHostAddress( 
            /* [retval][out] */ VARIANT __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActHostAddress( 
            /* [in] */ VARIANT newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActTimeOut( 
            /* [retval][out] */ VARIANT __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActTimeOut( 
            /* [in] */ VARIANT newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActSourceNetworkNumber( 
            /* [retval][out] */ VARIANT __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActSourceNetworkNumber( 
            /* [in] */ VARIANT newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActSourceStationNumber( 
            /* [retval][out] */ VARIANT __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActSourceStationNumber( 
            /* [in] */ VARIANT newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActDestinationPortNumber( 
            /* [retval][out] */ VARIANT __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActDestinationPortNumber( 
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
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActGotTransparentPCIf( 
            /* [retval][out] */ VARIANT __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActGotTransparentPCIf( 
            /* [in] */ VARIANT newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActGotTransparentPLCIf( 
            /* [retval][out] */ VARIANT __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActGotTransparentPLCIf( 
            /* [in] */ VARIANT newVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IActMLGOTTRSPVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IActMLGOTTRSP __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IActMLGOTTRSP __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IActMLGOTTRSP __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IActMLGOTTRSP __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IActMLGOTTRSP __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IActMLGOTTRSP __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IActMLGOTTRSP __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Open )( 
            IActMLGOTTRSP __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Close )( 
            IActMLGOTTRSP __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetDevice )( 
            IActMLGOTTRSP __RPC_FAR * This,
            /* [in] */ VARIANT varDevice,
            /* [out] */ VARIANT __RPC_FAR *lpvarData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetDevice )( 
            IActMLGOTTRSP __RPC_FAR * This,
            /* [in] */ VARIANT varDevice,
            /* [in] */ VARIANT varData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceBlock )( 
            IActMLGOTTRSP __RPC_FAR * This,
            /* [in] */ VARIANT varDevice,
            /* [in] */ VARIANT varSize,
            /* [out] */ VARIANT __RPC_FAR *lpvarData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceBlock )( 
            IActMLGOTTRSP __RPC_FAR * This,
            /* [in] */ VARIANT varDevice,
            /* [in] */ VARIANT varSize,
            /* [in] */ VARIANT varData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceRandom )( 
            IActMLGOTTRSP __RPC_FAR * This,
            /* [in] */ VARIANT varDeviceList,
            /* [in] */ VARIANT varSize,
            /* [out] */ VARIANT __RPC_FAR *lpvarData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceRandom )( 
            IActMLGOTTRSP __RPC_FAR * This,
            /* [in] */ VARIANT varDeviceList,
            /* [in] */ VARIANT varSize,
            /* [in] */ VARIANT varData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadBuffer )( 
            IActMLGOTTRSP __RPC_FAR * This,
            /* [in] */ VARIANT varStartIO,
            /* [in] */ VARIANT varAddress,
            /* [in] */ VARIANT varReadSize,
            /* [out] */ VARIANT __RPC_FAR *lpvarData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteBuffer )( 
            IActMLGOTTRSP __RPC_FAR * This,
            /* [in] */ VARIANT varStartIO,
            /* [in] */ VARIANT varAddress,
            /* [in] */ VARIANT varWriteSize,
            /* [in] */ VARIANT varData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetClockData )( 
            IActMLGOTTRSP __RPC_FAR * This,
            /* [out] */ VARIANT __RPC_FAR *lpvarYear,
            /* [out] */ VARIANT __RPC_FAR *lpvarMonth,
            /* [out] */ VARIANT __RPC_FAR *lpvarDay,
            /* [out] */ VARIANT __RPC_FAR *lpvarDayOfWeek,
            /* [out] */ VARIANT __RPC_FAR *lpvarHour,
            /* [out] */ VARIANT __RPC_FAR *lpvarMinute,
            /* [out] */ VARIANT __RPC_FAR *lpvarSecond,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetClockData )( 
            IActMLGOTTRSP __RPC_FAR * This,
            /* [in] */ VARIANT varYear,
            /* [in] */ VARIANT varMonth,
            /* [in] */ VARIANT varDay,
            /* [in] */ VARIANT varDayOfWeek,
            /* [in] */ VARIANT varHour,
            /* [in] */ VARIANT varMinute,
            /* [in] */ VARIANT varSecond,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetCpuStatus )( 
            IActMLGOTTRSP __RPC_FAR * This,
            /* [in] */ VARIANT varOperation,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetCpuType )( 
            IActMLGOTTRSP __RPC_FAR * This,
            /* [out] */ VARIANT __RPC_FAR *lpvarCpuName,
            /* [out] */ VARIANT __RPC_FAR *lpvarCpuType,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *EntryDeviceStatus )( 
            IActMLGOTTRSP __RPC_FAR * This,
            /* [in] */ VARIANT varDeviceList,
            /* [in] */ VARIANT varSize,
            /* [in] */ VARIANT varMonitorCycle,
            /* [in] */ VARIANT varData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *FreeDeviceStatus )( 
            IActMLGOTTRSP __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceBlock2 )( 
            IActMLGOTTRSP __RPC_FAR * This,
            /* [in] */ VARIANT varDevice,
            /* [in] */ VARIANT varSize,
            /* [out] */ VARIANT __RPC_FAR *lpvarData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceBlock2 )( 
            IActMLGOTTRSP __RPC_FAR * This,
            /* [in] */ VARIANT varDeviceList,
            /* [in] */ VARIANT varSize,
            /* [in] */ VARIANT varData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceRandom2 )( 
            IActMLGOTTRSP __RPC_FAR * This,
            /* [in] */ VARIANT varDeviceList,
            /* [in] */ VARIANT varSize,
            /* [out] */ VARIANT __RPC_FAR *lpvarData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceRandom2 )( 
            IActMLGOTTRSP __RPC_FAR * This,
            /* [in] */ VARIANT varDeviceList,
            /* [in] */ VARIANT varSize,
            /* [in] */ VARIANT varData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetDevice2 )( 
            IActMLGOTTRSP __RPC_FAR * This,
            /* [in] */ VARIANT varDevice,
            /* [out] */ VARIANT __RPC_FAR *lpvarData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetDevice2 )( 
            IActMLGOTTRSP __RPC_FAR * This,
            /* [in] */ VARIANT varDevice,
            /* [in] */ VARIANT varData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActNetworkNumber )( 
            IActMLGOTTRSP __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActNetworkNumber )( 
            IActMLGOTTRSP __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActStationNumber )( 
            IActMLGOTTRSP __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActStationNumber )( 
            IActMLGOTTRSP __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActUnitNumber )( 
            IActMLGOTTRSP __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActUnitNumber )( 
            IActMLGOTTRSP __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActConnectUnitNumber )( 
            IActMLGOTTRSP __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActConnectUnitNumber )( 
            IActMLGOTTRSP __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActIONumber )( 
            IActMLGOTTRSP __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActIONumber )( 
            IActMLGOTTRSP __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActCpuType )( 
            IActMLGOTTRSP __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActCpuType )( 
            IActMLGOTTRSP __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActPortNumber )( 
            IActMLGOTTRSP __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActPortNumber )( 
            IActMLGOTTRSP __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActBaudRate )( 
            IActMLGOTTRSP __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActBaudRate )( 
            IActMLGOTTRSP __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActHostAddress )( 
            IActMLGOTTRSP __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActHostAddress )( 
            IActMLGOTTRSP __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActTimeOut )( 
            IActMLGOTTRSP __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActTimeOut )( 
            IActMLGOTTRSP __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActSourceNetworkNumber )( 
            IActMLGOTTRSP __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActSourceNetworkNumber )( 
            IActMLGOTTRSP __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActSourceStationNumber )( 
            IActMLGOTTRSP __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActSourceStationNumber )( 
            IActMLGOTTRSP __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActDestinationPortNumber )( 
            IActMLGOTTRSP __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActDestinationPortNumber )( 
            IActMLGOTTRSP __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActDestinationIONumber )( 
            IActMLGOTTRSP __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActDestinationIONumber )( 
            IActMLGOTTRSP __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActMultiDropChannelNumber )( 
            IActMLGOTTRSP __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActMultiDropChannelNumber )( 
            IActMLGOTTRSP __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActThroughNetworkType )( 
            IActMLGOTTRSP __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActThroughNetworkType )( 
            IActMLGOTTRSP __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActIntelligentPreferenceBit )( 
            IActMLGOTTRSP __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActIntelligentPreferenceBit )( 
            IActMLGOTTRSP __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActDidPropertyBit )( 
            IActMLGOTTRSP __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActDidPropertyBit )( 
            IActMLGOTTRSP __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActDsidPropertyBit )( 
            IActMLGOTTRSP __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActDsidPropertyBit )( 
            IActMLGOTTRSP __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActGotTransparentPCIf )( 
            IActMLGOTTRSP __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActGotTransparentPCIf )( 
            IActMLGOTTRSP __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActGotTransparentPLCIf )( 
            IActMLGOTTRSP __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActGotTransparentPLCIf )( 
            IActMLGOTTRSP __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        END_INTERFACE
    } IActMLGOTTRSPVtbl;

    interface IActMLGOTTRSP
    {
        CONST_VTBL struct IActMLGOTTRSPVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IActMLGOTTRSP_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IActMLGOTTRSP_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IActMLGOTTRSP_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IActMLGOTTRSP_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IActMLGOTTRSP_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IActMLGOTTRSP_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IActMLGOTTRSP_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IActMLGOTTRSP_Open(This,lpvarReturnCode)	\
    (This)->lpVtbl -> Open(This,lpvarReturnCode)

#define IActMLGOTTRSP_Close(This,lpvarReturnCode)	\
    (This)->lpVtbl -> Close(This,lpvarReturnCode)

#define IActMLGOTTRSP_GetDevice(This,varDevice,lpvarData,lpvarReturnCode)	\
    (This)->lpVtbl -> GetDevice(This,varDevice,lpvarData,lpvarReturnCode)

#define IActMLGOTTRSP_SetDevice(This,varDevice,varData,lpvarReturnCode)	\
    (This)->lpVtbl -> SetDevice(This,varDevice,varData,lpvarReturnCode)

#define IActMLGOTTRSP_ReadDeviceBlock(This,varDevice,varSize,lpvarData,lpvarReturnCode)	\
    (This)->lpVtbl -> ReadDeviceBlock(This,varDevice,varSize,lpvarData,lpvarReturnCode)

#define IActMLGOTTRSP_WriteDeviceBlock(This,varDevice,varSize,varData,lpvarReturnCode)	\
    (This)->lpVtbl -> WriteDeviceBlock(This,varDevice,varSize,varData,lpvarReturnCode)

#define IActMLGOTTRSP_ReadDeviceRandom(This,varDeviceList,varSize,lpvarData,lpvarReturnCode)	\
    (This)->lpVtbl -> ReadDeviceRandom(This,varDeviceList,varSize,lpvarData,lpvarReturnCode)

#define IActMLGOTTRSP_WriteDeviceRandom(This,varDeviceList,varSize,varData,lpvarReturnCode)	\
    (This)->lpVtbl -> WriteDeviceRandom(This,varDeviceList,varSize,varData,lpvarReturnCode)

#define IActMLGOTTRSP_ReadBuffer(This,varStartIO,varAddress,varReadSize,lpvarData,lpvarReturnCode)	\
    (This)->lpVtbl -> ReadBuffer(This,varStartIO,varAddress,varReadSize,lpvarData,lpvarReturnCode)

#define IActMLGOTTRSP_WriteBuffer(This,varStartIO,varAddress,varWriteSize,varData,lpvarReturnCode)	\
    (This)->lpVtbl -> WriteBuffer(This,varStartIO,varAddress,varWriteSize,varData,lpvarReturnCode)

#define IActMLGOTTRSP_GetClockData(This,lpvarYear,lpvarMonth,lpvarDay,lpvarDayOfWeek,lpvarHour,lpvarMinute,lpvarSecond,lpvarReturnCode)	\
    (This)->lpVtbl -> GetClockData(This,lpvarYear,lpvarMonth,lpvarDay,lpvarDayOfWeek,lpvarHour,lpvarMinute,lpvarSecond,lpvarReturnCode)

#define IActMLGOTTRSP_SetClockData(This,varYear,varMonth,varDay,varDayOfWeek,varHour,varMinute,varSecond,lpvarReturnCode)	\
    (This)->lpVtbl -> SetClockData(This,varYear,varMonth,varDay,varDayOfWeek,varHour,varMinute,varSecond,lpvarReturnCode)

#define IActMLGOTTRSP_SetCpuStatus(This,varOperation,lpvarReturnCode)	\
    (This)->lpVtbl -> SetCpuStatus(This,varOperation,lpvarReturnCode)

#define IActMLGOTTRSP_GetCpuType(This,lpvarCpuName,lpvarCpuType,lpvarReturnCode)	\
    (This)->lpVtbl -> GetCpuType(This,lpvarCpuName,lpvarCpuType,lpvarReturnCode)

#define IActMLGOTTRSP_EntryDeviceStatus(This,varDeviceList,varSize,varMonitorCycle,varData,lpvarReturnCode)	\
    (This)->lpVtbl -> EntryDeviceStatus(This,varDeviceList,varSize,varMonitorCycle,varData,lpvarReturnCode)

#define IActMLGOTTRSP_FreeDeviceStatus(This,lpvarReturnCode)	\
    (This)->lpVtbl -> FreeDeviceStatus(This,lpvarReturnCode)

#define IActMLGOTTRSP_ReadDeviceBlock2(This,varDevice,varSize,lpvarData,lpvarReturnCode)	\
    (This)->lpVtbl -> ReadDeviceBlock2(This,varDevice,varSize,lpvarData,lpvarReturnCode)

#define IActMLGOTTRSP_WriteDeviceBlock2(This,varDeviceList,varSize,varData,lpvarReturnCode)	\
    (This)->lpVtbl -> WriteDeviceBlock2(This,varDeviceList,varSize,varData,lpvarReturnCode)

#define IActMLGOTTRSP_ReadDeviceRandom2(This,varDeviceList,varSize,lpvarData,lpvarReturnCode)	\
    (This)->lpVtbl -> ReadDeviceRandom2(This,varDeviceList,varSize,lpvarData,lpvarReturnCode)

#define IActMLGOTTRSP_WriteDeviceRandom2(This,varDeviceList,varSize,varData,lpvarReturnCode)	\
    (This)->lpVtbl -> WriteDeviceRandom2(This,varDeviceList,varSize,varData,lpvarReturnCode)

#define IActMLGOTTRSP_GetDevice2(This,varDevice,lpvarData,lpvarReturnCode)	\
    (This)->lpVtbl -> GetDevice2(This,varDevice,lpvarData,lpvarReturnCode)

#define IActMLGOTTRSP_SetDevice2(This,varDevice,varData,lpvarReturnCode)	\
    (This)->lpVtbl -> SetDevice2(This,varDevice,varData,lpvarReturnCode)

#define IActMLGOTTRSP_get_ActNetworkNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActNetworkNumber(This,pVal)

#define IActMLGOTTRSP_put_ActNetworkNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActNetworkNumber(This,newVal)

#define IActMLGOTTRSP_get_ActStationNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActStationNumber(This,pVal)

#define IActMLGOTTRSP_put_ActStationNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActStationNumber(This,newVal)

#define IActMLGOTTRSP_get_ActUnitNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActUnitNumber(This,pVal)

#define IActMLGOTTRSP_put_ActUnitNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActUnitNumber(This,newVal)

#define IActMLGOTTRSP_get_ActConnectUnitNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActConnectUnitNumber(This,pVal)

#define IActMLGOTTRSP_put_ActConnectUnitNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActConnectUnitNumber(This,newVal)

#define IActMLGOTTRSP_get_ActIONumber(This,pVal)	\
    (This)->lpVtbl -> get_ActIONumber(This,pVal)

#define IActMLGOTTRSP_put_ActIONumber(This,newVal)	\
    (This)->lpVtbl -> put_ActIONumber(This,newVal)

#define IActMLGOTTRSP_get_ActCpuType(This,pVal)	\
    (This)->lpVtbl -> get_ActCpuType(This,pVal)

#define IActMLGOTTRSP_put_ActCpuType(This,newVal)	\
    (This)->lpVtbl -> put_ActCpuType(This,newVal)

#define IActMLGOTTRSP_get_ActPortNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActPortNumber(This,pVal)

#define IActMLGOTTRSP_put_ActPortNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActPortNumber(This,newVal)

#define IActMLGOTTRSP_get_ActBaudRate(This,pVal)	\
    (This)->lpVtbl -> get_ActBaudRate(This,pVal)

#define IActMLGOTTRSP_put_ActBaudRate(This,newVal)	\
    (This)->lpVtbl -> put_ActBaudRate(This,newVal)

#define IActMLGOTTRSP_get_ActHostAddress(This,pVal)	\
    (This)->lpVtbl -> get_ActHostAddress(This,pVal)

#define IActMLGOTTRSP_put_ActHostAddress(This,newVal)	\
    (This)->lpVtbl -> put_ActHostAddress(This,newVal)

#define IActMLGOTTRSP_get_ActTimeOut(This,pVal)	\
    (This)->lpVtbl -> get_ActTimeOut(This,pVal)

#define IActMLGOTTRSP_put_ActTimeOut(This,newVal)	\
    (This)->lpVtbl -> put_ActTimeOut(This,newVal)

#define IActMLGOTTRSP_get_ActSourceNetworkNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActSourceNetworkNumber(This,pVal)

#define IActMLGOTTRSP_put_ActSourceNetworkNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActSourceNetworkNumber(This,newVal)

#define IActMLGOTTRSP_get_ActSourceStationNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActSourceStationNumber(This,pVal)

#define IActMLGOTTRSP_put_ActSourceStationNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActSourceStationNumber(This,newVal)

#define IActMLGOTTRSP_get_ActDestinationPortNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActDestinationPortNumber(This,pVal)

#define IActMLGOTTRSP_put_ActDestinationPortNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActDestinationPortNumber(This,newVal)

#define IActMLGOTTRSP_get_ActDestinationIONumber(This,pVal)	\
    (This)->lpVtbl -> get_ActDestinationIONumber(This,pVal)

#define IActMLGOTTRSP_put_ActDestinationIONumber(This,newVal)	\
    (This)->lpVtbl -> put_ActDestinationIONumber(This,newVal)

#define IActMLGOTTRSP_get_ActMultiDropChannelNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActMultiDropChannelNumber(This,pVal)

#define IActMLGOTTRSP_put_ActMultiDropChannelNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActMultiDropChannelNumber(This,newVal)

#define IActMLGOTTRSP_get_ActThroughNetworkType(This,pVal)	\
    (This)->lpVtbl -> get_ActThroughNetworkType(This,pVal)

#define IActMLGOTTRSP_put_ActThroughNetworkType(This,newVal)	\
    (This)->lpVtbl -> put_ActThroughNetworkType(This,newVal)

#define IActMLGOTTRSP_get_ActIntelligentPreferenceBit(This,pVal)	\
    (This)->lpVtbl -> get_ActIntelligentPreferenceBit(This,pVal)

#define IActMLGOTTRSP_put_ActIntelligentPreferenceBit(This,newVal)	\
    (This)->lpVtbl -> put_ActIntelligentPreferenceBit(This,newVal)

#define IActMLGOTTRSP_get_ActDidPropertyBit(This,pVal)	\
    (This)->lpVtbl -> get_ActDidPropertyBit(This,pVal)

#define IActMLGOTTRSP_put_ActDidPropertyBit(This,newVal)	\
    (This)->lpVtbl -> put_ActDidPropertyBit(This,newVal)

#define IActMLGOTTRSP_get_ActDsidPropertyBit(This,pVal)	\
    (This)->lpVtbl -> get_ActDsidPropertyBit(This,pVal)

#define IActMLGOTTRSP_put_ActDsidPropertyBit(This,newVal)	\
    (This)->lpVtbl -> put_ActDsidPropertyBit(This,newVal)

#define IActMLGOTTRSP_get_ActGotTransparentPCIf(This,pVal)	\
    (This)->lpVtbl -> get_ActGotTransparentPCIf(This,pVal)

#define IActMLGOTTRSP_put_ActGotTransparentPCIf(This,newVal)	\
    (This)->lpVtbl -> put_ActGotTransparentPCIf(This,newVal)

#define IActMLGOTTRSP_get_ActGotTransparentPLCIf(This,pVal)	\
    (This)->lpVtbl -> get_ActGotTransparentPLCIf(This,pVal)

#define IActMLGOTTRSP_put_ActGotTransparentPLCIf(This,newVal)	\
    (This)->lpVtbl -> put_ActGotTransparentPLCIf(This,newVal)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActMLGOTTRSP_Open_Proxy( 
    IActMLGOTTRSP __RPC_FAR * This,
    /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);


void __RPC_STUB IActMLGOTTRSP_Open_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActMLGOTTRSP_Close_Proxy( 
    IActMLGOTTRSP __RPC_FAR * This,
    /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);


void __RPC_STUB IActMLGOTTRSP_Close_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActMLGOTTRSP_GetDevice_Proxy( 
    IActMLGOTTRSP __RPC_FAR * This,
    /* [in] */ VARIANT varDevice,
    /* [out] */ VARIANT __RPC_FAR *lpvarData,
    /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);


void __RPC_STUB IActMLGOTTRSP_GetDevice_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActMLGOTTRSP_SetDevice_Proxy( 
    IActMLGOTTRSP __RPC_FAR * This,
    /* [in] */ VARIANT varDevice,
    /* [in] */ VARIANT varData,
    /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);


void __RPC_STUB IActMLGOTTRSP_SetDevice_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActMLGOTTRSP_ReadDeviceBlock_Proxy( 
    IActMLGOTTRSP __RPC_FAR * This,
    /* [in] */ VARIANT varDevice,
    /* [in] */ VARIANT varSize,
    /* [out] */ VARIANT __RPC_FAR *lpvarData,
    /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);


void __RPC_STUB IActMLGOTTRSP_ReadDeviceBlock_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActMLGOTTRSP_WriteDeviceBlock_Proxy( 
    IActMLGOTTRSP __RPC_FAR * This,
    /* [in] */ VARIANT varDevice,
    /* [in] */ VARIANT varSize,
    /* [in] */ VARIANT varData,
    /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);


void __RPC_STUB IActMLGOTTRSP_WriteDeviceBlock_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActMLGOTTRSP_ReadDeviceRandom_Proxy( 
    IActMLGOTTRSP __RPC_FAR * This,
    /* [in] */ VARIANT varDeviceList,
    /* [in] */ VARIANT varSize,
    /* [out] */ VARIANT __RPC_FAR *lpvarData,
    /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);


void __RPC_STUB IActMLGOTTRSP_ReadDeviceRandom_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActMLGOTTRSP_WriteDeviceRandom_Proxy( 
    IActMLGOTTRSP __RPC_FAR * This,
    /* [in] */ VARIANT varDeviceList,
    /* [in] */ VARIANT varSize,
    /* [in] */ VARIANT varData,
    /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);


void __RPC_STUB IActMLGOTTRSP_WriteDeviceRandom_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActMLGOTTRSP_ReadBuffer_Proxy( 
    IActMLGOTTRSP __RPC_FAR * This,
    /* [in] */ VARIANT varStartIO,
    /* [in] */ VARIANT varAddress,
    /* [in] */ VARIANT varReadSize,
    /* [out] */ VARIANT __RPC_FAR *lpvarData,
    /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);


void __RPC_STUB IActMLGOTTRSP_ReadBuffer_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActMLGOTTRSP_WriteBuffer_Proxy( 
    IActMLGOTTRSP __RPC_FAR * This,
    /* [in] */ VARIANT varStartIO,
    /* [in] */ VARIANT varAddress,
    /* [in] */ VARIANT varWriteSize,
    /* [in] */ VARIANT varData,
    /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);


void __RPC_STUB IActMLGOTTRSP_WriteBuffer_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActMLGOTTRSP_GetClockData_Proxy( 
    IActMLGOTTRSP __RPC_FAR * This,
    /* [out] */ VARIANT __RPC_FAR *lpvarYear,
    /* [out] */ VARIANT __RPC_FAR *lpvarMonth,
    /* [out] */ VARIANT __RPC_FAR *lpvarDay,
    /* [out] */ VARIANT __RPC_FAR *lpvarDayOfWeek,
    /* [out] */ VARIANT __RPC_FAR *lpvarHour,
    /* [out] */ VARIANT __RPC_FAR *lpvarMinute,
    /* [out] */ VARIANT __RPC_FAR *lpvarSecond,
    /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);


void __RPC_STUB IActMLGOTTRSP_GetClockData_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActMLGOTTRSP_SetClockData_Proxy( 
    IActMLGOTTRSP __RPC_FAR * This,
    /* [in] */ VARIANT varYear,
    /* [in] */ VARIANT varMonth,
    /* [in] */ VARIANT varDay,
    /* [in] */ VARIANT varDayOfWeek,
    /* [in] */ VARIANT varHour,
    /* [in] */ VARIANT varMinute,
    /* [in] */ VARIANT varSecond,
    /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);


void __RPC_STUB IActMLGOTTRSP_SetClockData_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActMLGOTTRSP_SetCpuStatus_Proxy( 
    IActMLGOTTRSP __RPC_FAR * This,
    /* [in] */ VARIANT varOperation,
    /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);


void __RPC_STUB IActMLGOTTRSP_SetCpuStatus_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActMLGOTTRSP_GetCpuType_Proxy( 
    IActMLGOTTRSP __RPC_FAR * This,
    /* [out] */ VARIANT __RPC_FAR *lpvarCpuName,
    /* [out] */ VARIANT __RPC_FAR *lpvarCpuType,
    /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);


void __RPC_STUB IActMLGOTTRSP_GetCpuType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActMLGOTTRSP_EntryDeviceStatus_Proxy( 
    IActMLGOTTRSP __RPC_FAR * This,
    /* [in] */ VARIANT varDeviceList,
    /* [in] */ VARIANT varSize,
    /* [in] */ VARIANT varMonitorCycle,
    /* [in] */ VARIANT varData,
    /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);


void __RPC_STUB IActMLGOTTRSP_EntryDeviceStatus_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActMLGOTTRSP_FreeDeviceStatus_Proxy( 
    IActMLGOTTRSP __RPC_FAR * This,
    /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);


void __RPC_STUB IActMLGOTTRSP_FreeDeviceStatus_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActMLGOTTRSP_ReadDeviceBlock2_Proxy( 
    IActMLGOTTRSP __RPC_FAR * This,
    /* [in] */ VARIANT varDevice,
    /* [in] */ VARIANT varSize,
    /* [out] */ VARIANT __RPC_FAR *lpvarData,
    /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);


void __RPC_STUB IActMLGOTTRSP_ReadDeviceBlock2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActMLGOTTRSP_WriteDeviceBlock2_Proxy( 
    IActMLGOTTRSP __RPC_FAR * This,
    /* [in] */ VARIANT varDeviceList,
    /* [in] */ VARIANT varSize,
    /* [in] */ VARIANT varData,
    /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);


void __RPC_STUB IActMLGOTTRSP_WriteDeviceBlock2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActMLGOTTRSP_ReadDeviceRandom2_Proxy( 
    IActMLGOTTRSP __RPC_FAR * This,
    /* [in] */ VARIANT varDeviceList,
    /* [in] */ VARIANT varSize,
    /* [out] */ VARIANT __RPC_FAR *lpvarData,
    /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);


void __RPC_STUB IActMLGOTTRSP_ReadDeviceRandom2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActMLGOTTRSP_WriteDeviceRandom2_Proxy( 
    IActMLGOTTRSP __RPC_FAR * This,
    /* [in] */ VARIANT varDeviceList,
    /* [in] */ VARIANT varSize,
    /* [in] */ VARIANT varData,
    /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);


void __RPC_STUB IActMLGOTTRSP_WriteDeviceRandom2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActMLGOTTRSP_GetDevice2_Proxy( 
    IActMLGOTTRSP __RPC_FAR * This,
    /* [in] */ VARIANT varDevice,
    /* [out] */ VARIANT __RPC_FAR *lpvarData,
    /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);


void __RPC_STUB IActMLGOTTRSP_GetDevice2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActMLGOTTRSP_SetDevice2_Proxy( 
    IActMLGOTTRSP __RPC_FAR * This,
    /* [in] */ VARIANT varDevice,
    /* [in] */ VARIANT varData,
    /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);


void __RPC_STUB IActMLGOTTRSP_SetDevice2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActMLGOTTRSP_get_ActNetworkNumber_Proxy( 
    IActMLGOTTRSP __RPC_FAR * This,
    /* [retval][out] */ VARIANT __RPC_FAR *pVal);


void __RPC_STUB IActMLGOTTRSP_get_ActNetworkNumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActMLGOTTRSP_put_ActNetworkNumber_Proxy( 
    IActMLGOTTRSP __RPC_FAR * This,
    /* [in] */ VARIANT newVal);


void __RPC_STUB IActMLGOTTRSP_put_ActNetworkNumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActMLGOTTRSP_get_ActStationNumber_Proxy( 
    IActMLGOTTRSP __RPC_FAR * This,
    /* [retval][out] */ VARIANT __RPC_FAR *pVal);


void __RPC_STUB IActMLGOTTRSP_get_ActStationNumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActMLGOTTRSP_put_ActStationNumber_Proxy( 
    IActMLGOTTRSP __RPC_FAR * This,
    /* [in] */ VARIANT newVal);


void __RPC_STUB IActMLGOTTRSP_put_ActStationNumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActMLGOTTRSP_get_ActUnitNumber_Proxy( 
    IActMLGOTTRSP __RPC_FAR * This,
    /* [retval][out] */ VARIANT __RPC_FAR *pVal);


void __RPC_STUB IActMLGOTTRSP_get_ActUnitNumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActMLGOTTRSP_put_ActUnitNumber_Proxy( 
    IActMLGOTTRSP __RPC_FAR * This,
    /* [in] */ VARIANT newVal);


void __RPC_STUB IActMLGOTTRSP_put_ActUnitNumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActMLGOTTRSP_get_ActConnectUnitNumber_Proxy( 
    IActMLGOTTRSP __RPC_FAR * This,
    /* [retval][out] */ VARIANT __RPC_FAR *pVal);


void __RPC_STUB IActMLGOTTRSP_get_ActConnectUnitNumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActMLGOTTRSP_put_ActConnectUnitNumber_Proxy( 
    IActMLGOTTRSP __RPC_FAR * This,
    /* [in] */ VARIANT newVal);


void __RPC_STUB IActMLGOTTRSP_put_ActConnectUnitNumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActMLGOTTRSP_get_ActIONumber_Proxy( 
    IActMLGOTTRSP __RPC_FAR * This,
    /* [retval][out] */ VARIANT __RPC_FAR *pVal);


void __RPC_STUB IActMLGOTTRSP_get_ActIONumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActMLGOTTRSP_put_ActIONumber_Proxy( 
    IActMLGOTTRSP __RPC_FAR * This,
    /* [in] */ VARIANT newVal);


void __RPC_STUB IActMLGOTTRSP_put_ActIONumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActMLGOTTRSP_get_ActCpuType_Proxy( 
    IActMLGOTTRSP __RPC_FAR * This,
    /* [retval][out] */ VARIANT __RPC_FAR *pVal);


void __RPC_STUB IActMLGOTTRSP_get_ActCpuType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActMLGOTTRSP_put_ActCpuType_Proxy( 
    IActMLGOTTRSP __RPC_FAR * This,
    /* [in] */ VARIANT newVal);


void __RPC_STUB IActMLGOTTRSP_put_ActCpuType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActMLGOTTRSP_get_ActPortNumber_Proxy( 
    IActMLGOTTRSP __RPC_FAR * This,
    /* [retval][out] */ VARIANT __RPC_FAR *pVal);


void __RPC_STUB IActMLGOTTRSP_get_ActPortNumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActMLGOTTRSP_put_ActPortNumber_Proxy( 
    IActMLGOTTRSP __RPC_FAR * This,
    /* [in] */ VARIANT newVal);


void __RPC_STUB IActMLGOTTRSP_put_ActPortNumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActMLGOTTRSP_get_ActBaudRate_Proxy( 
    IActMLGOTTRSP __RPC_FAR * This,
    /* [retval][out] */ VARIANT __RPC_FAR *pVal);


void __RPC_STUB IActMLGOTTRSP_get_ActBaudRate_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActMLGOTTRSP_put_ActBaudRate_Proxy( 
    IActMLGOTTRSP __RPC_FAR * This,
    /* [in] */ VARIANT newVal);


void __RPC_STUB IActMLGOTTRSP_put_ActBaudRate_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActMLGOTTRSP_get_ActHostAddress_Proxy( 
    IActMLGOTTRSP __RPC_FAR * This,
    /* [retval][out] */ VARIANT __RPC_FAR *pVal);


void __RPC_STUB IActMLGOTTRSP_get_ActHostAddress_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActMLGOTTRSP_put_ActHostAddress_Proxy( 
    IActMLGOTTRSP __RPC_FAR * This,
    /* [in] */ VARIANT newVal);


void __RPC_STUB IActMLGOTTRSP_put_ActHostAddress_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActMLGOTTRSP_get_ActTimeOut_Proxy( 
    IActMLGOTTRSP __RPC_FAR * This,
    /* [retval][out] */ VARIANT __RPC_FAR *pVal);


void __RPC_STUB IActMLGOTTRSP_get_ActTimeOut_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActMLGOTTRSP_put_ActTimeOut_Proxy( 
    IActMLGOTTRSP __RPC_FAR * This,
    /* [in] */ VARIANT newVal);


void __RPC_STUB IActMLGOTTRSP_put_ActTimeOut_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActMLGOTTRSP_get_ActSourceNetworkNumber_Proxy( 
    IActMLGOTTRSP __RPC_FAR * This,
    /* [retval][out] */ VARIANT __RPC_FAR *pVal);


void __RPC_STUB IActMLGOTTRSP_get_ActSourceNetworkNumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActMLGOTTRSP_put_ActSourceNetworkNumber_Proxy( 
    IActMLGOTTRSP __RPC_FAR * This,
    /* [in] */ VARIANT newVal);


void __RPC_STUB IActMLGOTTRSP_put_ActSourceNetworkNumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActMLGOTTRSP_get_ActSourceStationNumber_Proxy( 
    IActMLGOTTRSP __RPC_FAR * This,
    /* [retval][out] */ VARIANT __RPC_FAR *pVal);


void __RPC_STUB IActMLGOTTRSP_get_ActSourceStationNumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActMLGOTTRSP_put_ActSourceStationNumber_Proxy( 
    IActMLGOTTRSP __RPC_FAR * This,
    /* [in] */ VARIANT newVal);


void __RPC_STUB IActMLGOTTRSP_put_ActSourceStationNumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActMLGOTTRSP_get_ActDestinationPortNumber_Proxy( 
    IActMLGOTTRSP __RPC_FAR * This,
    /* [retval][out] */ VARIANT __RPC_FAR *pVal);


void __RPC_STUB IActMLGOTTRSP_get_ActDestinationPortNumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActMLGOTTRSP_put_ActDestinationPortNumber_Proxy( 
    IActMLGOTTRSP __RPC_FAR * This,
    /* [in] */ VARIANT newVal);


void __RPC_STUB IActMLGOTTRSP_put_ActDestinationPortNumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActMLGOTTRSP_get_ActDestinationIONumber_Proxy( 
    IActMLGOTTRSP __RPC_FAR * This,
    /* [retval][out] */ VARIANT __RPC_FAR *pVal);


void __RPC_STUB IActMLGOTTRSP_get_ActDestinationIONumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActMLGOTTRSP_put_ActDestinationIONumber_Proxy( 
    IActMLGOTTRSP __RPC_FAR * This,
    /* [in] */ VARIANT newVal);


void __RPC_STUB IActMLGOTTRSP_put_ActDestinationIONumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActMLGOTTRSP_get_ActMultiDropChannelNumber_Proxy( 
    IActMLGOTTRSP __RPC_FAR * This,
    /* [retval][out] */ VARIANT __RPC_FAR *pVal);


void __RPC_STUB IActMLGOTTRSP_get_ActMultiDropChannelNumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActMLGOTTRSP_put_ActMultiDropChannelNumber_Proxy( 
    IActMLGOTTRSP __RPC_FAR * This,
    /* [in] */ VARIANT newVal);


void __RPC_STUB IActMLGOTTRSP_put_ActMultiDropChannelNumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActMLGOTTRSP_get_ActThroughNetworkType_Proxy( 
    IActMLGOTTRSP __RPC_FAR * This,
    /* [retval][out] */ VARIANT __RPC_FAR *pVal);


void __RPC_STUB IActMLGOTTRSP_get_ActThroughNetworkType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActMLGOTTRSP_put_ActThroughNetworkType_Proxy( 
    IActMLGOTTRSP __RPC_FAR * This,
    /* [in] */ VARIANT newVal);


void __RPC_STUB IActMLGOTTRSP_put_ActThroughNetworkType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActMLGOTTRSP_get_ActIntelligentPreferenceBit_Proxy( 
    IActMLGOTTRSP __RPC_FAR * This,
    /* [retval][out] */ VARIANT __RPC_FAR *pVal);


void __RPC_STUB IActMLGOTTRSP_get_ActIntelligentPreferenceBit_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActMLGOTTRSP_put_ActIntelligentPreferenceBit_Proxy( 
    IActMLGOTTRSP __RPC_FAR * This,
    /* [in] */ VARIANT newVal);


void __RPC_STUB IActMLGOTTRSP_put_ActIntelligentPreferenceBit_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActMLGOTTRSP_get_ActDidPropertyBit_Proxy( 
    IActMLGOTTRSP __RPC_FAR * This,
    /* [retval][out] */ VARIANT __RPC_FAR *pVal);


void __RPC_STUB IActMLGOTTRSP_get_ActDidPropertyBit_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActMLGOTTRSP_put_ActDidPropertyBit_Proxy( 
    IActMLGOTTRSP __RPC_FAR * This,
    /* [in] */ VARIANT newVal);


void __RPC_STUB IActMLGOTTRSP_put_ActDidPropertyBit_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActMLGOTTRSP_get_ActDsidPropertyBit_Proxy( 
    IActMLGOTTRSP __RPC_FAR * This,
    /* [retval][out] */ VARIANT __RPC_FAR *pVal);


void __RPC_STUB IActMLGOTTRSP_get_ActDsidPropertyBit_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActMLGOTTRSP_put_ActDsidPropertyBit_Proxy( 
    IActMLGOTTRSP __RPC_FAR * This,
    /* [in] */ VARIANT newVal);


void __RPC_STUB IActMLGOTTRSP_put_ActDsidPropertyBit_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActMLGOTTRSP_get_ActGotTransparentPCIf_Proxy( 
    IActMLGOTTRSP __RPC_FAR * This,
    /* [retval][out] */ VARIANT __RPC_FAR *pVal);


void __RPC_STUB IActMLGOTTRSP_get_ActGotTransparentPCIf_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActMLGOTTRSP_put_ActGotTransparentPCIf_Proxy( 
    IActMLGOTTRSP __RPC_FAR * This,
    /* [in] */ VARIANT newVal);


void __RPC_STUB IActMLGOTTRSP_put_ActGotTransparentPCIf_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IActMLGOTTRSP_get_ActGotTransparentPLCIf_Proxy( 
    IActMLGOTTRSP __RPC_FAR * This,
    /* [retval][out] */ VARIANT __RPC_FAR *pVal);


void __RPC_STUB IActMLGOTTRSP_get_ActGotTransparentPLCIf_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IActMLGOTTRSP_put_ActGotTransparentPLCIf_Proxy( 
    IActMLGOTTRSP __RPC_FAR * This,
    /* [in] */ VARIANT newVal);


void __RPC_STUB IActMLGOTTRSP_put_ActGotTransparentPLCIf_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IActMLGOTTRSP_INTERFACE_DEFINED__ */


#ifndef __IActMLGOTTRSP2_INTERFACE_DEFINED__
#define __IActMLGOTTRSP2_INTERFACE_DEFINED__

/* interface IActMLGOTTRSP2 */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IActMLGOTTRSP2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("40ACF976-4A22-4557-85BB-0D0470BE1C8A")
    IActMLGOTTRSP2 : public IActMLGOTTRSP
    {
    public:
    };
    
#else 	/* C style interface */

    typedef struct IActMLGOTTRSP2Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IActMLGOTTRSP2 __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IActMLGOTTRSP2 __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IActMLGOTTRSP2 __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IActMLGOTTRSP2 __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IActMLGOTTRSP2 __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IActMLGOTTRSP2 __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IActMLGOTTRSP2 __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Open )( 
            IActMLGOTTRSP2 __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Close )( 
            IActMLGOTTRSP2 __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetDevice )( 
            IActMLGOTTRSP2 __RPC_FAR * This,
            /* [in] */ VARIANT varDevice,
            /* [out] */ VARIANT __RPC_FAR *lpvarData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetDevice )( 
            IActMLGOTTRSP2 __RPC_FAR * This,
            /* [in] */ VARIANT varDevice,
            /* [in] */ VARIANT varData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceBlock )( 
            IActMLGOTTRSP2 __RPC_FAR * This,
            /* [in] */ VARIANT varDevice,
            /* [in] */ VARIANT varSize,
            /* [out] */ VARIANT __RPC_FAR *lpvarData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceBlock )( 
            IActMLGOTTRSP2 __RPC_FAR * This,
            /* [in] */ VARIANT varDevice,
            /* [in] */ VARIANT varSize,
            /* [in] */ VARIANT varData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceRandom )( 
            IActMLGOTTRSP2 __RPC_FAR * This,
            /* [in] */ VARIANT varDeviceList,
            /* [in] */ VARIANT varSize,
            /* [out] */ VARIANT __RPC_FAR *lpvarData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceRandom )( 
            IActMLGOTTRSP2 __RPC_FAR * This,
            /* [in] */ VARIANT varDeviceList,
            /* [in] */ VARIANT varSize,
            /* [in] */ VARIANT varData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadBuffer )( 
            IActMLGOTTRSP2 __RPC_FAR * This,
            /* [in] */ VARIANT varStartIO,
            /* [in] */ VARIANT varAddress,
            /* [in] */ VARIANT varReadSize,
            /* [out] */ VARIANT __RPC_FAR *lpvarData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteBuffer )( 
            IActMLGOTTRSP2 __RPC_FAR * This,
            /* [in] */ VARIANT varStartIO,
            /* [in] */ VARIANT varAddress,
            /* [in] */ VARIANT varWriteSize,
            /* [in] */ VARIANT varData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetClockData )( 
            IActMLGOTTRSP2 __RPC_FAR * This,
            /* [out] */ VARIANT __RPC_FAR *lpvarYear,
            /* [out] */ VARIANT __RPC_FAR *lpvarMonth,
            /* [out] */ VARIANT __RPC_FAR *lpvarDay,
            /* [out] */ VARIANT __RPC_FAR *lpvarDayOfWeek,
            /* [out] */ VARIANT __RPC_FAR *lpvarHour,
            /* [out] */ VARIANT __RPC_FAR *lpvarMinute,
            /* [out] */ VARIANT __RPC_FAR *lpvarSecond,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetClockData )( 
            IActMLGOTTRSP2 __RPC_FAR * This,
            /* [in] */ VARIANT varYear,
            /* [in] */ VARIANT varMonth,
            /* [in] */ VARIANT varDay,
            /* [in] */ VARIANT varDayOfWeek,
            /* [in] */ VARIANT varHour,
            /* [in] */ VARIANT varMinute,
            /* [in] */ VARIANT varSecond,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetCpuStatus )( 
            IActMLGOTTRSP2 __RPC_FAR * This,
            /* [in] */ VARIANT varOperation,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetCpuType )( 
            IActMLGOTTRSP2 __RPC_FAR * This,
            /* [out] */ VARIANT __RPC_FAR *lpvarCpuName,
            /* [out] */ VARIANT __RPC_FAR *lpvarCpuType,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *EntryDeviceStatus )( 
            IActMLGOTTRSP2 __RPC_FAR * This,
            /* [in] */ VARIANT varDeviceList,
            /* [in] */ VARIANT varSize,
            /* [in] */ VARIANT varMonitorCycle,
            /* [in] */ VARIANT varData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *FreeDeviceStatus )( 
            IActMLGOTTRSP2 __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceBlock2 )( 
            IActMLGOTTRSP2 __RPC_FAR * This,
            /* [in] */ VARIANT varDevice,
            /* [in] */ VARIANT varSize,
            /* [out] */ VARIANT __RPC_FAR *lpvarData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceBlock2 )( 
            IActMLGOTTRSP2 __RPC_FAR * This,
            /* [in] */ VARIANT varDeviceList,
            /* [in] */ VARIANT varSize,
            /* [in] */ VARIANT varData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceRandom2 )( 
            IActMLGOTTRSP2 __RPC_FAR * This,
            /* [in] */ VARIANT varDeviceList,
            /* [in] */ VARIANT varSize,
            /* [out] */ VARIANT __RPC_FAR *lpvarData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceRandom2 )( 
            IActMLGOTTRSP2 __RPC_FAR * This,
            /* [in] */ VARIANT varDeviceList,
            /* [in] */ VARIANT varSize,
            /* [in] */ VARIANT varData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetDevice2 )( 
            IActMLGOTTRSP2 __RPC_FAR * This,
            /* [in] */ VARIANT varDevice,
            /* [out] */ VARIANT __RPC_FAR *lpvarData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetDevice2 )( 
            IActMLGOTTRSP2 __RPC_FAR * This,
            /* [in] */ VARIANT varDevice,
            /* [in] */ VARIANT varData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActNetworkNumber )( 
            IActMLGOTTRSP2 __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActNetworkNumber )( 
            IActMLGOTTRSP2 __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActStationNumber )( 
            IActMLGOTTRSP2 __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActStationNumber )( 
            IActMLGOTTRSP2 __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActUnitNumber )( 
            IActMLGOTTRSP2 __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActUnitNumber )( 
            IActMLGOTTRSP2 __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActConnectUnitNumber )( 
            IActMLGOTTRSP2 __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActConnectUnitNumber )( 
            IActMLGOTTRSP2 __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActIONumber )( 
            IActMLGOTTRSP2 __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActIONumber )( 
            IActMLGOTTRSP2 __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActCpuType )( 
            IActMLGOTTRSP2 __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActCpuType )( 
            IActMLGOTTRSP2 __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActPortNumber )( 
            IActMLGOTTRSP2 __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActPortNumber )( 
            IActMLGOTTRSP2 __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActBaudRate )( 
            IActMLGOTTRSP2 __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActBaudRate )( 
            IActMLGOTTRSP2 __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActHostAddress )( 
            IActMLGOTTRSP2 __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActHostAddress )( 
            IActMLGOTTRSP2 __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActTimeOut )( 
            IActMLGOTTRSP2 __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActTimeOut )( 
            IActMLGOTTRSP2 __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActSourceNetworkNumber )( 
            IActMLGOTTRSP2 __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActSourceNetworkNumber )( 
            IActMLGOTTRSP2 __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActSourceStationNumber )( 
            IActMLGOTTRSP2 __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActSourceStationNumber )( 
            IActMLGOTTRSP2 __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActDestinationPortNumber )( 
            IActMLGOTTRSP2 __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActDestinationPortNumber )( 
            IActMLGOTTRSP2 __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActDestinationIONumber )( 
            IActMLGOTTRSP2 __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActDestinationIONumber )( 
            IActMLGOTTRSP2 __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActMultiDropChannelNumber )( 
            IActMLGOTTRSP2 __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActMultiDropChannelNumber )( 
            IActMLGOTTRSP2 __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActThroughNetworkType )( 
            IActMLGOTTRSP2 __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActThroughNetworkType )( 
            IActMLGOTTRSP2 __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActIntelligentPreferenceBit )( 
            IActMLGOTTRSP2 __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActIntelligentPreferenceBit )( 
            IActMLGOTTRSP2 __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActDidPropertyBit )( 
            IActMLGOTTRSP2 __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActDidPropertyBit )( 
            IActMLGOTTRSP2 __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActDsidPropertyBit )( 
            IActMLGOTTRSP2 __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActDsidPropertyBit )( 
            IActMLGOTTRSP2 __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActGotTransparentPCIf )( 
            IActMLGOTTRSP2 __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActGotTransparentPCIf )( 
            IActMLGOTTRSP2 __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActGotTransparentPLCIf )( 
            IActMLGOTTRSP2 __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActGotTransparentPLCIf )( 
            IActMLGOTTRSP2 __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        END_INTERFACE
    } IActMLGOTTRSP2Vtbl;

    interface IActMLGOTTRSP2
    {
        CONST_VTBL struct IActMLGOTTRSP2Vtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IActMLGOTTRSP2_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IActMLGOTTRSP2_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IActMLGOTTRSP2_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IActMLGOTTRSP2_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IActMLGOTTRSP2_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IActMLGOTTRSP2_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IActMLGOTTRSP2_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IActMLGOTTRSP2_Open(This,lpvarReturnCode)	\
    (This)->lpVtbl -> Open(This,lpvarReturnCode)

#define IActMLGOTTRSP2_Close(This,lpvarReturnCode)	\
    (This)->lpVtbl -> Close(This,lpvarReturnCode)

#define IActMLGOTTRSP2_GetDevice(This,varDevice,lpvarData,lpvarReturnCode)	\
    (This)->lpVtbl -> GetDevice(This,varDevice,lpvarData,lpvarReturnCode)

#define IActMLGOTTRSP2_SetDevice(This,varDevice,varData,lpvarReturnCode)	\
    (This)->lpVtbl -> SetDevice(This,varDevice,varData,lpvarReturnCode)

#define IActMLGOTTRSP2_ReadDeviceBlock(This,varDevice,varSize,lpvarData,lpvarReturnCode)	\
    (This)->lpVtbl -> ReadDeviceBlock(This,varDevice,varSize,lpvarData,lpvarReturnCode)

#define IActMLGOTTRSP2_WriteDeviceBlock(This,varDevice,varSize,varData,lpvarReturnCode)	\
    (This)->lpVtbl -> WriteDeviceBlock(This,varDevice,varSize,varData,lpvarReturnCode)

#define IActMLGOTTRSP2_ReadDeviceRandom(This,varDeviceList,varSize,lpvarData,lpvarReturnCode)	\
    (This)->lpVtbl -> ReadDeviceRandom(This,varDeviceList,varSize,lpvarData,lpvarReturnCode)

#define IActMLGOTTRSP2_WriteDeviceRandom(This,varDeviceList,varSize,varData,lpvarReturnCode)	\
    (This)->lpVtbl -> WriteDeviceRandom(This,varDeviceList,varSize,varData,lpvarReturnCode)

#define IActMLGOTTRSP2_ReadBuffer(This,varStartIO,varAddress,varReadSize,lpvarData,lpvarReturnCode)	\
    (This)->lpVtbl -> ReadBuffer(This,varStartIO,varAddress,varReadSize,lpvarData,lpvarReturnCode)

#define IActMLGOTTRSP2_WriteBuffer(This,varStartIO,varAddress,varWriteSize,varData,lpvarReturnCode)	\
    (This)->lpVtbl -> WriteBuffer(This,varStartIO,varAddress,varWriteSize,varData,lpvarReturnCode)

#define IActMLGOTTRSP2_GetClockData(This,lpvarYear,lpvarMonth,lpvarDay,lpvarDayOfWeek,lpvarHour,lpvarMinute,lpvarSecond,lpvarReturnCode)	\
    (This)->lpVtbl -> GetClockData(This,lpvarYear,lpvarMonth,lpvarDay,lpvarDayOfWeek,lpvarHour,lpvarMinute,lpvarSecond,lpvarReturnCode)

#define IActMLGOTTRSP2_SetClockData(This,varYear,varMonth,varDay,varDayOfWeek,varHour,varMinute,varSecond,lpvarReturnCode)	\
    (This)->lpVtbl -> SetClockData(This,varYear,varMonth,varDay,varDayOfWeek,varHour,varMinute,varSecond,lpvarReturnCode)

#define IActMLGOTTRSP2_SetCpuStatus(This,varOperation,lpvarReturnCode)	\
    (This)->lpVtbl -> SetCpuStatus(This,varOperation,lpvarReturnCode)

#define IActMLGOTTRSP2_GetCpuType(This,lpvarCpuName,lpvarCpuType,lpvarReturnCode)	\
    (This)->lpVtbl -> GetCpuType(This,lpvarCpuName,lpvarCpuType,lpvarReturnCode)

#define IActMLGOTTRSP2_EntryDeviceStatus(This,varDeviceList,varSize,varMonitorCycle,varData,lpvarReturnCode)	\
    (This)->lpVtbl -> EntryDeviceStatus(This,varDeviceList,varSize,varMonitorCycle,varData,lpvarReturnCode)

#define IActMLGOTTRSP2_FreeDeviceStatus(This,lpvarReturnCode)	\
    (This)->lpVtbl -> FreeDeviceStatus(This,lpvarReturnCode)

#define IActMLGOTTRSP2_ReadDeviceBlock2(This,varDevice,varSize,lpvarData,lpvarReturnCode)	\
    (This)->lpVtbl -> ReadDeviceBlock2(This,varDevice,varSize,lpvarData,lpvarReturnCode)

#define IActMLGOTTRSP2_WriteDeviceBlock2(This,varDeviceList,varSize,varData,lpvarReturnCode)	\
    (This)->lpVtbl -> WriteDeviceBlock2(This,varDeviceList,varSize,varData,lpvarReturnCode)

#define IActMLGOTTRSP2_ReadDeviceRandom2(This,varDeviceList,varSize,lpvarData,lpvarReturnCode)	\
    (This)->lpVtbl -> ReadDeviceRandom2(This,varDeviceList,varSize,lpvarData,lpvarReturnCode)

#define IActMLGOTTRSP2_WriteDeviceRandom2(This,varDeviceList,varSize,varData,lpvarReturnCode)	\
    (This)->lpVtbl -> WriteDeviceRandom2(This,varDeviceList,varSize,varData,lpvarReturnCode)

#define IActMLGOTTRSP2_GetDevice2(This,varDevice,lpvarData,lpvarReturnCode)	\
    (This)->lpVtbl -> GetDevice2(This,varDevice,lpvarData,lpvarReturnCode)

#define IActMLGOTTRSP2_SetDevice2(This,varDevice,varData,lpvarReturnCode)	\
    (This)->lpVtbl -> SetDevice2(This,varDevice,varData,lpvarReturnCode)

#define IActMLGOTTRSP2_get_ActNetworkNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActNetworkNumber(This,pVal)

#define IActMLGOTTRSP2_put_ActNetworkNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActNetworkNumber(This,newVal)

#define IActMLGOTTRSP2_get_ActStationNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActStationNumber(This,pVal)

#define IActMLGOTTRSP2_put_ActStationNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActStationNumber(This,newVal)

#define IActMLGOTTRSP2_get_ActUnitNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActUnitNumber(This,pVal)

#define IActMLGOTTRSP2_put_ActUnitNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActUnitNumber(This,newVal)

#define IActMLGOTTRSP2_get_ActConnectUnitNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActConnectUnitNumber(This,pVal)

#define IActMLGOTTRSP2_put_ActConnectUnitNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActConnectUnitNumber(This,newVal)

#define IActMLGOTTRSP2_get_ActIONumber(This,pVal)	\
    (This)->lpVtbl -> get_ActIONumber(This,pVal)

#define IActMLGOTTRSP2_put_ActIONumber(This,newVal)	\
    (This)->lpVtbl -> put_ActIONumber(This,newVal)

#define IActMLGOTTRSP2_get_ActCpuType(This,pVal)	\
    (This)->lpVtbl -> get_ActCpuType(This,pVal)

#define IActMLGOTTRSP2_put_ActCpuType(This,newVal)	\
    (This)->lpVtbl -> put_ActCpuType(This,newVal)

#define IActMLGOTTRSP2_get_ActPortNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActPortNumber(This,pVal)

#define IActMLGOTTRSP2_put_ActPortNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActPortNumber(This,newVal)

#define IActMLGOTTRSP2_get_ActBaudRate(This,pVal)	\
    (This)->lpVtbl -> get_ActBaudRate(This,pVal)

#define IActMLGOTTRSP2_put_ActBaudRate(This,newVal)	\
    (This)->lpVtbl -> put_ActBaudRate(This,newVal)

#define IActMLGOTTRSP2_get_ActHostAddress(This,pVal)	\
    (This)->lpVtbl -> get_ActHostAddress(This,pVal)

#define IActMLGOTTRSP2_put_ActHostAddress(This,newVal)	\
    (This)->lpVtbl -> put_ActHostAddress(This,newVal)

#define IActMLGOTTRSP2_get_ActTimeOut(This,pVal)	\
    (This)->lpVtbl -> get_ActTimeOut(This,pVal)

#define IActMLGOTTRSP2_put_ActTimeOut(This,newVal)	\
    (This)->lpVtbl -> put_ActTimeOut(This,newVal)

#define IActMLGOTTRSP2_get_ActSourceNetworkNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActSourceNetworkNumber(This,pVal)

#define IActMLGOTTRSP2_put_ActSourceNetworkNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActSourceNetworkNumber(This,newVal)

#define IActMLGOTTRSP2_get_ActSourceStationNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActSourceStationNumber(This,pVal)

#define IActMLGOTTRSP2_put_ActSourceStationNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActSourceStationNumber(This,newVal)

#define IActMLGOTTRSP2_get_ActDestinationPortNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActDestinationPortNumber(This,pVal)

#define IActMLGOTTRSP2_put_ActDestinationPortNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActDestinationPortNumber(This,newVal)

#define IActMLGOTTRSP2_get_ActDestinationIONumber(This,pVal)	\
    (This)->lpVtbl -> get_ActDestinationIONumber(This,pVal)

#define IActMLGOTTRSP2_put_ActDestinationIONumber(This,newVal)	\
    (This)->lpVtbl -> put_ActDestinationIONumber(This,newVal)

#define IActMLGOTTRSP2_get_ActMultiDropChannelNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActMultiDropChannelNumber(This,pVal)

#define IActMLGOTTRSP2_put_ActMultiDropChannelNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActMultiDropChannelNumber(This,newVal)

#define IActMLGOTTRSP2_get_ActThroughNetworkType(This,pVal)	\
    (This)->lpVtbl -> get_ActThroughNetworkType(This,pVal)

#define IActMLGOTTRSP2_put_ActThroughNetworkType(This,newVal)	\
    (This)->lpVtbl -> put_ActThroughNetworkType(This,newVal)

#define IActMLGOTTRSP2_get_ActIntelligentPreferenceBit(This,pVal)	\
    (This)->lpVtbl -> get_ActIntelligentPreferenceBit(This,pVal)

#define IActMLGOTTRSP2_put_ActIntelligentPreferenceBit(This,newVal)	\
    (This)->lpVtbl -> put_ActIntelligentPreferenceBit(This,newVal)

#define IActMLGOTTRSP2_get_ActDidPropertyBit(This,pVal)	\
    (This)->lpVtbl -> get_ActDidPropertyBit(This,pVal)

#define IActMLGOTTRSP2_put_ActDidPropertyBit(This,newVal)	\
    (This)->lpVtbl -> put_ActDidPropertyBit(This,newVal)

#define IActMLGOTTRSP2_get_ActDsidPropertyBit(This,pVal)	\
    (This)->lpVtbl -> get_ActDsidPropertyBit(This,pVal)

#define IActMLGOTTRSP2_put_ActDsidPropertyBit(This,newVal)	\
    (This)->lpVtbl -> put_ActDsidPropertyBit(This,newVal)

#define IActMLGOTTRSP2_get_ActGotTransparentPCIf(This,pVal)	\
    (This)->lpVtbl -> get_ActGotTransparentPCIf(This,pVal)

#define IActMLGOTTRSP2_put_ActGotTransparentPCIf(This,newVal)	\
    (This)->lpVtbl -> put_ActGotTransparentPCIf(This,newVal)

#define IActMLGOTTRSP2_get_ActGotTransparentPLCIf(This,pVal)	\
    (This)->lpVtbl -> get_ActGotTransparentPLCIf(This,pVal)

#define IActMLGOTTRSP2_put_ActGotTransparentPLCIf(This,newVal)	\
    (This)->lpVtbl -> put_ActGotTransparentPLCIf(This,newVal)


#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IActMLGOTTRSP2_INTERFACE_DEFINED__ */


#ifndef __IActMLGOTTRSP3_INTERFACE_DEFINED__
#define __IActMLGOTTRSP3_INTERFACE_DEFINED__

/* interface IActMLGOTTRSP3 */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IActMLGOTTRSP3;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("3077E986-2467-4b44-8130-3401517B4E71")
    IActMLGOTTRSP3 : public IActMLGOTTRSP2
    {
    public:
    };
    
#else 	/* C style interface */

    typedef struct IActMLGOTTRSP3Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IActMLGOTTRSP3 __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IActMLGOTTRSP3 __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IActMLGOTTRSP3 __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IActMLGOTTRSP3 __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IActMLGOTTRSP3 __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IActMLGOTTRSP3 __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IActMLGOTTRSP3 __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Open )( 
            IActMLGOTTRSP3 __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Close )( 
            IActMLGOTTRSP3 __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetDevice )( 
            IActMLGOTTRSP3 __RPC_FAR * This,
            /* [in] */ VARIANT varDevice,
            /* [out] */ VARIANT __RPC_FAR *lpvarData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetDevice )( 
            IActMLGOTTRSP3 __RPC_FAR * This,
            /* [in] */ VARIANT varDevice,
            /* [in] */ VARIANT varData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceBlock )( 
            IActMLGOTTRSP3 __RPC_FAR * This,
            /* [in] */ VARIANT varDevice,
            /* [in] */ VARIANT varSize,
            /* [out] */ VARIANT __RPC_FAR *lpvarData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceBlock )( 
            IActMLGOTTRSP3 __RPC_FAR * This,
            /* [in] */ VARIANT varDevice,
            /* [in] */ VARIANT varSize,
            /* [in] */ VARIANT varData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceRandom )( 
            IActMLGOTTRSP3 __RPC_FAR * This,
            /* [in] */ VARIANT varDeviceList,
            /* [in] */ VARIANT varSize,
            /* [out] */ VARIANT __RPC_FAR *lpvarData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceRandom )( 
            IActMLGOTTRSP3 __RPC_FAR * This,
            /* [in] */ VARIANT varDeviceList,
            /* [in] */ VARIANT varSize,
            /* [in] */ VARIANT varData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadBuffer )( 
            IActMLGOTTRSP3 __RPC_FAR * This,
            /* [in] */ VARIANT varStartIO,
            /* [in] */ VARIANT varAddress,
            /* [in] */ VARIANT varReadSize,
            /* [out] */ VARIANT __RPC_FAR *lpvarData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteBuffer )( 
            IActMLGOTTRSP3 __RPC_FAR * This,
            /* [in] */ VARIANT varStartIO,
            /* [in] */ VARIANT varAddress,
            /* [in] */ VARIANT varWriteSize,
            /* [in] */ VARIANT varData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetClockData )( 
            IActMLGOTTRSP3 __RPC_FAR * This,
            /* [out] */ VARIANT __RPC_FAR *lpvarYear,
            /* [out] */ VARIANT __RPC_FAR *lpvarMonth,
            /* [out] */ VARIANT __RPC_FAR *lpvarDay,
            /* [out] */ VARIANT __RPC_FAR *lpvarDayOfWeek,
            /* [out] */ VARIANT __RPC_FAR *lpvarHour,
            /* [out] */ VARIANT __RPC_FAR *lpvarMinute,
            /* [out] */ VARIANT __RPC_FAR *lpvarSecond,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetClockData )( 
            IActMLGOTTRSP3 __RPC_FAR * This,
            /* [in] */ VARIANT varYear,
            /* [in] */ VARIANT varMonth,
            /* [in] */ VARIANT varDay,
            /* [in] */ VARIANT varDayOfWeek,
            /* [in] */ VARIANT varHour,
            /* [in] */ VARIANT varMinute,
            /* [in] */ VARIANT varSecond,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetCpuStatus )( 
            IActMLGOTTRSP3 __RPC_FAR * This,
            /* [in] */ VARIANT varOperation,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetCpuType )( 
            IActMLGOTTRSP3 __RPC_FAR * This,
            /* [out] */ VARIANT __RPC_FAR *lpvarCpuName,
            /* [out] */ VARIANT __RPC_FAR *lpvarCpuType,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *EntryDeviceStatus )( 
            IActMLGOTTRSP3 __RPC_FAR * This,
            /* [in] */ VARIANT varDeviceList,
            /* [in] */ VARIANT varSize,
            /* [in] */ VARIANT varMonitorCycle,
            /* [in] */ VARIANT varData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *FreeDeviceStatus )( 
            IActMLGOTTRSP3 __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceBlock2 )( 
            IActMLGOTTRSP3 __RPC_FAR * This,
            /* [in] */ VARIANT varDevice,
            /* [in] */ VARIANT varSize,
            /* [out] */ VARIANT __RPC_FAR *lpvarData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceBlock2 )( 
            IActMLGOTTRSP3 __RPC_FAR * This,
            /* [in] */ VARIANT varDeviceList,
            /* [in] */ VARIANT varSize,
            /* [in] */ VARIANT varData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDeviceRandom2 )( 
            IActMLGOTTRSP3 __RPC_FAR * This,
            /* [in] */ VARIANT varDeviceList,
            /* [in] */ VARIANT varSize,
            /* [out] */ VARIANT __RPC_FAR *lpvarData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDeviceRandom2 )( 
            IActMLGOTTRSP3 __RPC_FAR * This,
            /* [in] */ VARIANT varDeviceList,
            /* [in] */ VARIANT varSize,
            /* [in] */ VARIANT varData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetDevice2 )( 
            IActMLGOTTRSP3 __RPC_FAR * This,
            /* [in] */ VARIANT varDevice,
            /* [out] */ VARIANT __RPC_FAR *lpvarData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetDevice2 )( 
            IActMLGOTTRSP3 __RPC_FAR * This,
            /* [in] */ VARIANT varDevice,
            /* [in] */ VARIANT varData,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActNetworkNumber )( 
            IActMLGOTTRSP3 __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActNetworkNumber )( 
            IActMLGOTTRSP3 __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActStationNumber )( 
            IActMLGOTTRSP3 __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActStationNumber )( 
            IActMLGOTTRSP3 __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActUnitNumber )( 
            IActMLGOTTRSP3 __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActUnitNumber )( 
            IActMLGOTTRSP3 __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActConnectUnitNumber )( 
            IActMLGOTTRSP3 __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActConnectUnitNumber )( 
            IActMLGOTTRSP3 __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActIONumber )( 
            IActMLGOTTRSP3 __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActIONumber )( 
            IActMLGOTTRSP3 __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActCpuType )( 
            IActMLGOTTRSP3 __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActCpuType )( 
            IActMLGOTTRSP3 __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActPortNumber )( 
            IActMLGOTTRSP3 __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActPortNumber )( 
            IActMLGOTTRSP3 __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActBaudRate )( 
            IActMLGOTTRSP3 __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActBaudRate )( 
            IActMLGOTTRSP3 __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActHostAddress )( 
            IActMLGOTTRSP3 __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActHostAddress )( 
            IActMLGOTTRSP3 __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActTimeOut )( 
            IActMLGOTTRSP3 __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActTimeOut )( 
            IActMLGOTTRSP3 __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActSourceNetworkNumber )( 
            IActMLGOTTRSP3 __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActSourceNetworkNumber )( 
            IActMLGOTTRSP3 __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActSourceStationNumber )( 
            IActMLGOTTRSP3 __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActSourceStationNumber )( 
            IActMLGOTTRSP3 __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActDestinationPortNumber )( 
            IActMLGOTTRSP3 __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActDestinationPortNumber )( 
            IActMLGOTTRSP3 __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActDestinationIONumber )( 
            IActMLGOTTRSP3 __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActDestinationIONumber )( 
            IActMLGOTTRSP3 __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActMultiDropChannelNumber )( 
            IActMLGOTTRSP3 __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActMultiDropChannelNumber )( 
            IActMLGOTTRSP3 __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActThroughNetworkType )( 
            IActMLGOTTRSP3 __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActThroughNetworkType )( 
            IActMLGOTTRSP3 __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActIntelligentPreferenceBit )( 
            IActMLGOTTRSP3 __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActIntelligentPreferenceBit )( 
            IActMLGOTTRSP3 __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActDidPropertyBit )( 
            IActMLGOTTRSP3 __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActDidPropertyBit )( 
            IActMLGOTTRSP3 __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActDsidPropertyBit )( 
            IActMLGOTTRSP3 __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActDsidPropertyBit )( 
            IActMLGOTTRSP3 __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActGotTransparentPCIf )( 
            IActMLGOTTRSP3 __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActGotTransparentPCIf )( 
            IActMLGOTTRSP3 __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActGotTransparentPLCIf )( 
            IActMLGOTTRSP3 __RPC_FAR * This,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActGotTransparentPLCIf )( 
            IActMLGOTTRSP3 __RPC_FAR * This,
            /* [in] */ VARIANT newVal);
        
        END_INTERFACE
    } IActMLGOTTRSP3Vtbl;

    interface IActMLGOTTRSP3
    {
        CONST_VTBL struct IActMLGOTTRSP3Vtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IActMLGOTTRSP3_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IActMLGOTTRSP3_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IActMLGOTTRSP3_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IActMLGOTTRSP3_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IActMLGOTTRSP3_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IActMLGOTTRSP3_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IActMLGOTTRSP3_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IActMLGOTTRSP3_Open(This,lpvarReturnCode)	\
    (This)->lpVtbl -> Open(This,lpvarReturnCode)

#define IActMLGOTTRSP3_Close(This,lpvarReturnCode)	\
    (This)->lpVtbl -> Close(This,lpvarReturnCode)

#define IActMLGOTTRSP3_GetDevice(This,varDevice,lpvarData,lpvarReturnCode)	\
    (This)->lpVtbl -> GetDevice(This,varDevice,lpvarData,lpvarReturnCode)

#define IActMLGOTTRSP3_SetDevice(This,varDevice,varData,lpvarReturnCode)	\
    (This)->lpVtbl -> SetDevice(This,varDevice,varData,lpvarReturnCode)

#define IActMLGOTTRSP3_ReadDeviceBlock(This,varDevice,varSize,lpvarData,lpvarReturnCode)	\
    (This)->lpVtbl -> ReadDeviceBlock(This,varDevice,varSize,lpvarData,lpvarReturnCode)

#define IActMLGOTTRSP3_WriteDeviceBlock(This,varDevice,varSize,varData,lpvarReturnCode)	\
    (This)->lpVtbl -> WriteDeviceBlock(This,varDevice,varSize,varData,lpvarReturnCode)

#define IActMLGOTTRSP3_ReadDeviceRandom(This,varDeviceList,varSize,lpvarData,lpvarReturnCode)	\
    (This)->lpVtbl -> ReadDeviceRandom(This,varDeviceList,varSize,lpvarData,lpvarReturnCode)

#define IActMLGOTTRSP3_WriteDeviceRandom(This,varDeviceList,varSize,varData,lpvarReturnCode)	\
    (This)->lpVtbl -> WriteDeviceRandom(This,varDeviceList,varSize,varData,lpvarReturnCode)

#define IActMLGOTTRSP3_ReadBuffer(This,varStartIO,varAddress,varReadSize,lpvarData,lpvarReturnCode)	\
    (This)->lpVtbl -> ReadBuffer(This,varStartIO,varAddress,varReadSize,lpvarData,lpvarReturnCode)

#define IActMLGOTTRSP3_WriteBuffer(This,varStartIO,varAddress,varWriteSize,varData,lpvarReturnCode)	\
    (This)->lpVtbl -> WriteBuffer(This,varStartIO,varAddress,varWriteSize,varData,lpvarReturnCode)

#define IActMLGOTTRSP3_GetClockData(This,lpvarYear,lpvarMonth,lpvarDay,lpvarDayOfWeek,lpvarHour,lpvarMinute,lpvarSecond,lpvarReturnCode)	\
    (This)->lpVtbl -> GetClockData(This,lpvarYear,lpvarMonth,lpvarDay,lpvarDayOfWeek,lpvarHour,lpvarMinute,lpvarSecond,lpvarReturnCode)

#define IActMLGOTTRSP3_SetClockData(This,varYear,varMonth,varDay,varDayOfWeek,varHour,varMinute,varSecond,lpvarReturnCode)	\
    (This)->lpVtbl -> SetClockData(This,varYear,varMonth,varDay,varDayOfWeek,varHour,varMinute,varSecond,lpvarReturnCode)

#define IActMLGOTTRSP3_SetCpuStatus(This,varOperation,lpvarReturnCode)	\
    (This)->lpVtbl -> SetCpuStatus(This,varOperation,lpvarReturnCode)

#define IActMLGOTTRSP3_GetCpuType(This,lpvarCpuName,lpvarCpuType,lpvarReturnCode)	\
    (This)->lpVtbl -> GetCpuType(This,lpvarCpuName,lpvarCpuType,lpvarReturnCode)

#define IActMLGOTTRSP3_EntryDeviceStatus(This,varDeviceList,varSize,varMonitorCycle,varData,lpvarReturnCode)	\
    (This)->lpVtbl -> EntryDeviceStatus(This,varDeviceList,varSize,varMonitorCycle,varData,lpvarReturnCode)

#define IActMLGOTTRSP3_FreeDeviceStatus(This,lpvarReturnCode)	\
    (This)->lpVtbl -> FreeDeviceStatus(This,lpvarReturnCode)

#define IActMLGOTTRSP3_ReadDeviceBlock2(This,varDevice,varSize,lpvarData,lpvarReturnCode)	\
    (This)->lpVtbl -> ReadDeviceBlock2(This,varDevice,varSize,lpvarData,lpvarReturnCode)

#define IActMLGOTTRSP3_WriteDeviceBlock2(This,varDeviceList,varSize,varData,lpvarReturnCode)	\
    (This)->lpVtbl -> WriteDeviceBlock2(This,varDeviceList,varSize,varData,lpvarReturnCode)

#define IActMLGOTTRSP3_ReadDeviceRandom2(This,varDeviceList,varSize,lpvarData,lpvarReturnCode)	\
    (This)->lpVtbl -> ReadDeviceRandom2(This,varDeviceList,varSize,lpvarData,lpvarReturnCode)

#define IActMLGOTTRSP3_WriteDeviceRandom2(This,varDeviceList,varSize,varData,lpvarReturnCode)	\
    (This)->lpVtbl -> WriteDeviceRandom2(This,varDeviceList,varSize,varData,lpvarReturnCode)

#define IActMLGOTTRSP3_GetDevice2(This,varDevice,lpvarData,lpvarReturnCode)	\
    (This)->lpVtbl -> GetDevice2(This,varDevice,lpvarData,lpvarReturnCode)

#define IActMLGOTTRSP3_SetDevice2(This,varDevice,varData,lpvarReturnCode)	\
    (This)->lpVtbl -> SetDevice2(This,varDevice,varData,lpvarReturnCode)

#define IActMLGOTTRSP3_get_ActNetworkNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActNetworkNumber(This,pVal)

#define IActMLGOTTRSP3_put_ActNetworkNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActNetworkNumber(This,newVal)

#define IActMLGOTTRSP3_get_ActStationNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActStationNumber(This,pVal)

#define IActMLGOTTRSP3_put_ActStationNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActStationNumber(This,newVal)

#define IActMLGOTTRSP3_get_ActUnitNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActUnitNumber(This,pVal)

#define IActMLGOTTRSP3_put_ActUnitNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActUnitNumber(This,newVal)

#define IActMLGOTTRSP3_get_ActConnectUnitNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActConnectUnitNumber(This,pVal)

#define IActMLGOTTRSP3_put_ActConnectUnitNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActConnectUnitNumber(This,newVal)

#define IActMLGOTTRSP3_get_ActIONumber(This,pVal)	\
    (This)->lpVtbl -> get_ActIONumber(This,pVal)

#define IActMLGOTTRSP3_put_ActIONumber(This,newVal)	\
    (This)->lpVtbl -> put_ActIONumber(This,newVal)

#define IActMLGOTTRSP3_get_ActCpuType(This,pVal)	\
    (This)->lpVtbl -> get_ActCpuType(This,pVal)

#define IActMLGOTTRSP3_put_ActCpuType(This,newVal)	\
    (This)->lpVtbl -> put_ActCpuType(This,newVal)

#define IActMLGOTTRSP3_get_ActPortNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActPortNumber(This,pVal)

#define IActMLGOTTRSP3_put_ActPortNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActPortNumber(This,newVal)

#define IActMLGOTTRSP3_get_ActBaudRate(This,pVal)	\
    (This)->lpVtbl -> get_ActBaudRate(This,pVal)

#define IActMLGOTTRSP3_put_ActBaudRate(This,newVal)	\
    (This)->lpVtbl -> put_ActBaudRate(This,newVal)

#define IActMLGOTTRSP3_get_ActHostAddress(This,pVal)	\
    (This)->lpVtbl -> get_ActHostAddress(This,pVal)

#define IActMLGOTTRSP3_put_ActHostAddress(This,newVal)	\
    (This)->lpVtbl -> put_ActHostAddress(This,newVal)

#define IActMLGOTTRSP3_get_ActTimeOut(This,pVal)	\
    (This)->lpVtbl -> get_ActTimeOut(This,pVal)

#define IActMLGOTTRSP3_put_ActTimeOut(This,newVal)	\
    (This)->lpVtbl -> put_ActTimeOut(This,newVal)

#define IActMLGOTTRSP3_get_ActSourceNetworkNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActSourceNetworkNumber(This,pVal)

#define IActMLGOTTRSP3_put_ActSourceNetworkNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActSourceNetworkNumber(This,newVal)

#define IActMLGOTTRSP3_get_ActSourceStationNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActSourceStationNumber(This,pVal)

#define IActMLGOTTRSP3_put_ActSourceStationNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActSourceStationNumber(This,newVal)

#define IActMLGOTTRSP3_get_ActDestinationPortNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActDestinationPortNumber(This,pVal)

#define IActMLGOTTRSP3_put_ActDestinationPortNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActDestinationPortNumber(This,newVal)

#define IActMLGOTTRSP3_get_ActDestinationIONumber(This,pVal)	\
    (This)->lpVtbl -> get_ActDestinationIONumber(This,pVal)

#define IActMLGOTTRSP3_put_ActDestinationIONumber(This,newVal)	\
    (This)->lpVtbl -> put_ActDestinationIONumber(This,newVal)

#define IActMLGOTTRSP3_get_ActMultiDropChannelNumber(This,pVal)	\
    (This)->lpVtbl -> get_ActMultiDropChannelNumber(This,pVal)

#define IActMLGOTTRSP3_put_ActMultiDropChannelNumber(This,newVal)	\
    (This)->lpVtbl -> put_ActMultiDropChannelNumber(This,newVal)

#define IActMLGOTTRSP3_get_ActThroughNetworkType(This,pVal)	\
    (This)->lpVtbl -> get_ActThroughNetworkType(This,pVal)

#define IActMLGOTTRSP3_put_ActThroughNetworkType(This,newVal)	\
    (This)->lpVtbl -> put_ActThroughNetworkType(This,newVal)

#define IActMLGOTTRSP3_get_ActIntelligentPreferenceBit(This,pVal)	\
    (This)->lpVtbl -> get_ActIntelligentPreferenceBit(This,pVal)

#define IActMLGOTTRSP3_put_ActIntelligentPreferenceBit(This,newVal)	\
    (This)->lpVtbl -> put_ActIntelligentPreferenceBit(This,newVal)

#define IActMLGOTTRSP3_get_ActDidPropertyBit(This,pVal)	\
    (This)->lpVtbl -> get_ActDidPropertyBit(This,pVal)

#define IActMLGOTTRSP3_put_ActDidPropertyBit(This,newVal)	\
    (This)->lpVtbl -> put_ActDidPropertyBit(This,newVal)

#define IActMLGOTTRSP3_get_ActDsidPropertyBit(This,pVal)	\
    (This)->lpVtbl -> get_ActDsidPropertyBit(This,pVal)

#define IActMLGOTTRSP3_put_ActDsidPropertyBit(This,newVal)	\
    (This)->lpVtbl -> put_ActDsidPropertyBit(This,newVal)

#define IActMLGOTTRSP3_get_ActGotTransparentPCIf(This,pVal)	\
    (This)->lpVtbl -> get_ActGotTransparentPCIf(This,pVal)

#define IActMLGOTTRSP3_put_ActGotTransparentPCIf(This,newVal)	\
    (This)->lpVtbl -> put_ActGotTransparentPCIf(This,newVal)

#define IActMLGOTTRSP3_get_ActGotTransparentPLCIf(This,pVal)	\
    (This)->lpVtbl -> get_ActGotTransparentPLCIf(This,pVal)

#define IActMLGOTTRSP3_put_ActGotTransparentPLCIf(This,newVal)	\
    (This)->lpVtbl -> put_ActGotTransparentPLCIf(This,newVal)



#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IActMLGOTTRSP3_INTERFACE_DEFINED__ */



#ifndef __ACTGOTLib_LIBRARY_DEFINED__
#define __ACTGOTLib_LIBRARY_DEFINED__

/* library ACTGOTLib */
/* [helpstring][version][uuid] */ 


EXTERN_C const IID LIBID_ACTGOTLib;

#ifndef ___IActGOTEvents_DISPINTERFACE_DEFINED__
#define ___IActGOTEvents_DISPINTERFACE_DEFINED__

/* dispinterface _IActGOTEvents */
/* [helpstring][uuid] */ 


EXTERN_C const IID DIID__IActGOTEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("FB327420-7044-11D5-9316-009099244EFD")
    _IActGOTEvents : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct _IActGOTEventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            _IActGOTEvents __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            _IActGOTEvents __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            _IActGOTEvents __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            _IActGOTEvents __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            _IActGOTEvents __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            _IActGOTEvents __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            _IActGOTEvents __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        END_INTERFACE
    } _IActGOTEventsVtbl;

    interface _IActGOTEvents
    {
        CONST_VTBL struct _IActGOTEventsVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _IActGOTEvents_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define _IActGOTEvents_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define _IActGOTEvents_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define _IActGOTEvents_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define _IActGOTEvents_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define _IActGOTEvents_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define _IActGOTEvents_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ___IActGOTEvents_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_ActGOT;

#ifdef __cplusplus

class DECLSPEC_UUID("FB32741F-7044-11D5-9316-009099244EFD")
ActGOT;
#endif

#ifndef ___IActMLGOTEvents_DISPINTERFACE_DEFINED__
#define ___IActMLGOTEvents_DISPINTERFACE_DEFINED__

/* dispinterface _IActMLGOTEvents */
/* [helpstring][uuid] */ 


EXTERN_C const IID DIID__IActMLGOTEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("FB327423-7044-11D5-9316-009099244EFD")
    _IActMLGOTEvents : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct _IActMLGOTEventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            _IActMLGOTEvents __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            _IActMLGOTEvents __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            _IActMLGOTEvents __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            _IActMLGOTEvents __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            _IActMLGOTEvents __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            _IActMLGOTEvents __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            _IActMLGOTEvents __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        END_INTERFACE
    } _IActMLGOTEventsVtbl;

    interface _IActMLGOTEvents
    {
        CONST_VTBL struct _IActMLGOTEventsVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _IActMLGOTEvents_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define _IActMLGOTEvents_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define _IActMLGOTEvents_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define _IActMLGOTEvents_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define _IActMLGOTEvents_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define _IActMLGOTEvents_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define _IActMLGOTEvents_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ___IActMLGOTEvents_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_ActMLGOT;

#ifdef __cplusplus

class DECLSPEC_UUID("FB327422-7044-11D5-9316-009099244EFD")
ActMLGOT;
#endif

#ifndef ___IActGOTTRSPEvents_DISPINTERFACE_DEFINED__
#define ___IActGOTTRSPEvents_DISPINTERFACE_DEFINED__

/* dispinterface _IActGOTTRSPEvents */
/* [helpstring][uuid] */ 


EXTERN_C const IID DIID__IActGOTTRSPEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("77511BE3-5486-4447-82D6-92D56E7F5BAA")
    _IActGOTTRSPEvents : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct _IActGOTTRSPEventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            _IActGOTTRSPEvents __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            _IActGOTTRSPEvents __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            _IActGOTTRSPEvents __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            _IActGOTTRSPEvents __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            _IActGOTTRSPEvents __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            _IActGOTTRSPEvents __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            _IActGOTTRSPEvents __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        END_INTERFACE
    } _IActGOTTRSPEventsVtbl;

    interface _IActGOTTRSPEvents
    {
        CONST_VTBL struct _IActGOTTRSPEventsVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _IActGOTTRSPEvents_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define _IActGOTTRSPEvents_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define _IActGOTTRSPEvents_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define _IActGOTTRSPEvents_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define _IActGOTTRSPEvents_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define _IActGOTTRSPEvents_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define _IActGOTTRSPEvents_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ___IActGOTTRSPEvents_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_ActGOTTRSP;

#ifdef __cplusplus

class DECLSPEC_UUID("83324001-1A12-435A-A6F9-09A88E160163")
ActGOTTRSP;
#endif

#ifndef ___IActMLGOTTRSPEvents_DISPINTERFACE_DEFINED__
#define ___IActMLGOTTRSPEvents_DISPINTERFACE_DEFINED__

/* dispinterface _IActMLGOTTRSPEvents */
/* [helpstring][uuid] */ 


EXTERN_C const IID DIID__IActMLGOTTRSPEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("CBD89653-56CD-49C9-90BD-1C0CF43899F8")
    _IActMLGOTTRSPEvents : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct _IActMLGOTTRSPEventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            _IActMLGOTTRSPEvents __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            _IActMLGOTTRSPEvents __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            _IActMLGOTTRSPEvents __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            _IActMLGOTTRSPEvents __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            _IActMLGOTTRSPEvents __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            _IActMLGOTTRSPEvents __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            _IActMLGOTTRSPEvents __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        END_INTERFACE
    } _IActMLGOTTRSPEventsVtbl;

    interface _IActMLGOTTRSPEvents
    {
        CONST_VTBL struct _IActMLGOTTRSPEventsVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _IActMLGOTTRSPEvents_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define _IActMLGOTTRSPEvents_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define _IActMLGOTTRSPEvents_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define _IActMLGOTTRSPEvents_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define _IActMLGOTTRSPEvents_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define _IActMLGOTTRSPEvents_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define _IActMLGOTTRSPEvents_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ___IActMLGOTTRSPEvents_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_ActMLGOTTRSP;

#ifdef __cplusplus

class DECLSPEC_UUID("7436116C-7DFF-43AF-A418-DC22034412B3")
ActMLGOTTRSP;
#endif
#endif /* __ACTGOTLib_LIBRARY_DEFINED__ */

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
