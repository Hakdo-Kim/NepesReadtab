/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 5.01.0164 */
/* at Fri Apr 12 12:33:51 2013
 */
/* Compiler settings for D:\GETMODULE\CommunicationSupport2\SW3D5\ACT\Control\ActSupport\ActSupport.idl:
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

#ifndef __ActSupport_h__
#define __ActSupport_h__

#ifdef __cplusplus
extern "C"{
#endif 

/* Forward Declarations */ 

#ifndef __IActMLSupport_FWD_DEFINED__
#define __IActMLSupport_FWD_DEFINED__
typedef interface IActMLSupport IActMLSupport;
#endif 	/* __IActMLSupport_FWD_DEFINED__ */


#ifndef __IActMLSupport2_FWD_DEFINED__
#define __IActMLSupport2_FWD_DEFINED__
typedef interface IActMLSupport2 IActMLSupport2;
#endif 	/* __IActMLSupport2_FWD_DEFINED__ */


#ifndef __IActMLSupport3_FWD_DEFINED__
#define __IActMLSupport3_FWD_DEFINED__
typedef interface IActMLSupport3 IActMLSupport3;
#endif 	/* __IActMLSupport3_FWD_DEFINED__ */


#ifndef __IActSupport_FWD_DEFINED__
#define __IActSupport_FWD_DEFINED__
typedef interface IActSupport IActSupport;
#endif 	/* __IActSupport_FWD_DEFINED__ */


#ifndef __IActSupport2_FWD_DEFINED__
#define __IActSupport2_FWD_DEFINED__
typedef interface IActSupport2 IActSupport2;
#endif 	/* __IActSupport2_FWD_DEFINED__ */


#ifndef __IActSupport3_FWD_DEFINED__
#define __IActSupport3_FWD_DEFINED__
typedef interface IActSupport3 IActSupport3;
#endif 	/* __IActSupport3_FWD_DEFINED__ */


#ifndef ___IActMLSupportEvents_FWD_DEFINED__
#define ___IActMLSupportEvents_FWD_DEFINED__
typedef interface _IActMLSupportEvents _IActMLSupportEvents;
#endif 	/* ___IActMLSupportEvents_FWD_DEFINED__ */


#ifndef __ActMLSupport_FWD_DEFINED__
#define __ActMLSupport_FWD_DEFINED__

#ifdef __cplusplus
typedef class ActMLSupport ActMLSupport;
#else
typedef struct ActMLSupport ActMLSupport;
#endif /* __cplusplus */

#endif 	/* __ActMLSupport_FWD_DEFINED__ */


#ifndef ___IActSupportEvents_FWD_DEFINED__
#define ___IActSupportEvents_FWD_DEFINED__
typedef interface _IActSupportEvents _IActSupportEvents;
#endif 	/* ___IActSupportEvents_FWD_DEFINED__ */


#ifndef __ActSupport_FWD_DEFINED__
#define __ActSupport_FWD_DEFINED__

#ifdef __cplusplus
typedef class ActSupport ActSupport;
#else
typedef struct ActSupport ActSupport;
#endif /* __cplusplus */

#endif 	/* __ActSupport_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

void __RPC_FAR * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void __RPC_FAR * ); 

#ifndef __IActMLSupport_INTERFACE_DEFINED__
#define __IActMLSupport_INTERFACE_DEFINED__

/* interface IActMLSupport */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IActMLSupport;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("5713F0A1-6F4A-11D5-9315-009099244EFD")
    IActMLSupport : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetErrorMessage( 
            /* [in] */ VARIANT varErrorCode,
            /* [out] */ VARIANT __RPC_FAR *lpvarErrorMessage,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IActMLSupportVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IActMLSupport __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IActMLSupport __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IActMLSupport __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IActMLSupport __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IActMLSupport __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IActMLSupport __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IActMLSupport __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetErrorMessage )( 
            IActMLSupport __RPC_FAR * This,
            /* [in] */ VARIANT varErrorCode,
            /* [out] */ VARIANT __RPC_FAR *lpvarErrorMessage,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        END_INTERFACE
    } IActMLSupportVtbl;

    interface IActMLSupport
    {
        CONST_VTBL struct IActMLSupportVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IActMLSupport_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IActMLSupport_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IActMLSupport_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IActMLSupport_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IActMLSupport_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IActMLSupport_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IActMLSupport_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IActMLSupport_GetErrorMessage(This,varErrorCode,lpvarErrorMessage,lpvarReturnCode)	\
    (This)->lpVtbl -> GetErrorMessage(This,varErrorCode,lpvarErrorMessage,lpvarReturnCode)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActMLSupport_GetErrorMessage_Proxy( 
    IActMLSupport __RPC_FAR * This,
    /* [in] */ VARIANT varErrorCode,
    /* [out] */ VARIANT __RPC_FAR *lpvarErrorMessage,
    /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);


void __RPC_STUB IActMLSupport_GetErrorMessage_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IActMLSupport_INTERFACE_DEFINED__ */


#ifndef __IActMLSupport2_INTERFACE_DEFINED__
#define __IActMLSupport2_INTERFACE_DEFINED__

/* interface IActMLSupport2 */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IActMLSupport2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("8716604A-710B-11d5-9318-009099244EFD")
    IActMLSupport2 : public IActMLSupport
    {
    public:
    };
    
#else 	/* C style interface */

    typedef struct IActMLSupport2Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IActMLSupport2 __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IActMLSupport2 __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IActMLSupport2 __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IActMLSupport2 __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IActMLSupport2 __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IActMLSupport2 __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IActMLSupport2 __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetErrorMessage )( 
            IActMLSupport2 __RPC_FAR * This,
            /* [in] */ VARIANT varErrorCode,
            /* [out] */ VARIANT __RPC_FAR *lpvarErrorMessage,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        END_INTERFACE
    } IActMLSupport2Vtbl;

    interface IActMLSupport2
    {
        CONST_VTBL struct IActMLSupport2Vtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IActMLSupport2_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IActMLSupport2_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IActMLSupport2_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IActMLSupport2_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IActMLSupport2_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IActMLSupport2_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IActMLSupport2_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IActMLSupport2_GetErrorMessage(This,varErrorCode,lpvarErrorMessage,lpvarReturnCode)	\
    (This)->lpVtbl -> GetErrorMessage(This,varErrorCode,lpvarErrorMessage,lpvarReturnCode)


#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IActMLSupport2_INTERFACE_DEFINED__ */


#ifndef __IActMLSupport3_INTERFACE_DEFINED__
#define __IActMLSupport3_INTERFACE_DEFINED__

/* interface IActMLSupport3 */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IActMLSupport3;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("8716604B-710B-11d5-9318-009099244EFD")
    IActMLSupport3 : public IActMLSupport2
    {
    public:
    };
    
#else 	/* C style interface */

    typedef struct IActMLSupport3Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IActMLSupport3 __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IActMLSupport3 __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IActMLSupport3 __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IActMLSupport3 __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IActMLSupport3 __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IActMLSupport3 __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IActMLSupport3 __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetErrorMessage )( 
            IActMLSupport3 __RPC_FAR * This,
            /* [in] */ VARIANT varErrorCode,
            /* [out] */ VARIANT __RPC_FAR *lpvarErrorMessage,
            /* [retval][out] */ VARIANT __RPC_FAR *lpvarReturnCode);
        
        END_INTERFACE
    } IActMLSupport3Vtbl;

    interface IActMLSupport3
    {
        CONST_VTBL struct IActMLSupport3Vtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IActMLSupport3_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IActMLSupport3_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IActMLSupport3_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IActMLSupport3_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IActMLSupport3_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IActMLSupport3_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IActMLSupport3_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IActMLSupport3_GetErrorMessage(This,varErrorCode,lpvarErrorMessage,lpvarReturnCode)	\
    (This)->lpVtbl -> GetErrorMessage(This,varErrorCode,lpvarErrorMessage,lpvarReturnCode)



#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IActMLSupport3_INTERFACE_DEFINED__ */


#ifndef __IActSupport_INTERFACE_DEFINED__
#define __IActSupport_INTERFACE_DEFINED__

/* interface IActSupport */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IActSupport;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("5713F0A4-6F4A-11D5-9315-009099244EFD")
    IActSupport : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetErrorMessage( 
            /* [in] */ LONG lErrorCode,
            /* [string][out] */ BSTR __RPC_FAR *lpszErrorMessage,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IActSupportVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IActSupport __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IActSupport __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IActSupport __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IActSupport __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IActSupport __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IActSupport __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IActSupport __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetErrorMessage )( 
            IActSupport __RPC_FAR * This,
            /* [in] */ LONG lErrorCode,
            /* [string][out] */ BSTR __RPC_FAR *lpszErrorMessage,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        END_INTERFACE
    } IActSupportVtbl;

    interface IActSupport
    {
        CONST_VTBL struct IActSupportVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IActSupport_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IActSupport_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IActSupport_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IActSupport_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IActSupport_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IActSupport_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IActSupport_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IActSupport_GetErrorMessage(This,lErrorCode,lpszErrorMessage,lplReturnCode)	\
    (This)->lpVtbl -> GetErrorMessage(This,lErrorCode,lpszErrorMessage,lplReturnCode)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IActSupport_GetErrorMessage_Proxy( 
    IActSupport __RPC_FAR * This,
    /* [in] */ LONG lErrorCode,
    /* [string][out] */ BSTR __RPC_FAR *lpszErrorMessage,
    /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);


void __RPC_STUB IActSupport_GetErrorMessage_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IActSupport_INTERFACE_DEFINED__ */


#ifndef __IActSupport2_INTERFACE_DEFINED__
#define __IActSupport2_INTERFACE_DEFINED__

/* interface IActSupport2 */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IActSupport2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("8716604C-710B-11d5-9318-009099244EFD")
    IActSupport2 : public IActSupport
    {
    public:
    };
    
#else 	/* C style interface */

    typedef struct IActSupport2Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IActSupport2 __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IActSupport2 __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IActSupport2 __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IActSupport2 __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IActSupport2 __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IActSupport2 __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IActSupport2 __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetErrorMessage )( 
            IActSupport2 __RPC_FAR * This,
            /* [in] */ LONG lErrorCode,
            /* [string][out] */ BSTR __RPC_FAR *lpszErrorMessage,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        END_INTERFACE
    } IActSupport2Vtbl;

    interface IActSupport2
    {
        CONST_VTBL struct IActSupport2Vtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IActSupport2_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IActSupport2_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IActSupport2_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IActSupport2_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IActSupport2_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IActSupport2_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IActSupport2_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IActSupport2_GetErrorMessage(This,lErrorCode,lpszErrorMessage,lplReturnCode)	\
    (This)->lpVtbl -> GetErrorMessage(This,lErrorCode,lpszErrorMessage,lplReturnCode)


#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IActSupport2_INTERFACE_DEFINED__ */


#ifndef __IActSupport3_INTERFACE_DEFINED__
#define __IActSupport3_INTERFACE_DEFINED__

/* interface IActSupport3 */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IActSupport3;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("8716604D-710B-11d5-9318-009099244EFD")
    IActSupport3 : public IActSupport2
    {
    public:
    };
    
#else 	/* C style interface */

    typedef struct IActSupport3Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IActSupport3 __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IActSupport3 __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IActSupport3 __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IActSupport3 __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IActSupport3 __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IActSupport3 __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IActSupport3 __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetErrorMessage )( 
            IActSupport3 __RPC_FAR * This,
            /* [in] */ LONG lErrorCode,
            /* [string][out] */ BSTR __RPC_FAR *lpszErrorMessage,
            /* [retval][out] */ LONG __RPC_FAR *lplReturnCode);
        
        END_INTERFACE
    } IActSupport3Vtbl;

    interface IActSupport3
    {
        CONST_VTBL struct IActSupport3Vtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IActSupport3_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IActSupport3_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IActSupport3_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IActSupport3_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IActSupport3_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IActSupport3_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IActSupport3_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IActSupport3_GetErrorMessage(This,lErrorCode,lpszErrorMessage,lplReturnCode)	\
    (This)->lpVtbl -> GetErrorMessage(This,lErrorCode,lpszErrorMessage,lplReturnCode)



#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IActSupport3_INTERFACE_DEFINED__ */



#ifndef __ACTSUPPORTLib_LIBRARY_DEFINED__
#define __ACTSUPPORTLib_LIBRARY_DEFINED__

/* library ACTSUPPORTLib */
/* [helpstring][version][uuid] */ 


EXTERN_C const IID LIBID_ACTSUPPORTLib;

#ifndef ___IActMLSupportEvents_DISPINTERFACE_DEFINED__
#define ___IActMLSupportEvents_DISPINTERFACE_DEFINED__

/* dispinterface _IActMLSupportEvents */
/* [helpstring][uuid] */ 


EXTERN_C const IID DIID__IActMLSupportEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("5713F0A3-6F4A-11D5-9315-009099244EFD")
    _IActMLSupportEvents : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct _IActMLSupportEventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            _IActMLSupportEvents __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            _IActMLSupportEvents __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            _IActMLSupportEvents __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            _IActMLSupportEvents __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            _IActMLSupportEvents __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            _IActMLSupportEvents __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            _IActMLSupportEvents __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        END_INTERFACE
    } _IActMLSupportEventsVtbl;

    interface _IActMLSupportEvents
    {
        CONST_VTBL struct _IActMLSupportEventsVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _IActMLSupportEvents_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define _IActMLSupportEvents_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define _IActMLSupportEvents_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define _IActMLSupportEvents_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define _IActMLSupportEvents_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define _IActMLSupportEvents_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define _IActMLSupportEvents_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ___IActMLSupportEvents_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_ActMLSupport;

#ifdef __cplusplus

class DECLSPEC_UUID("5713F0A2-6F4A-11D5-9315-009099244EFD")
ActMLSupport;
#endif

#ifndef ___IActSupportEvents_DISPINTERFACE_DEFINED__
#define ___IActSupportEvents_DISPINTERFACE_DEFINED__

/* dispinterface _IActSupportEvents */
/* [helpstring][uuid] */ 


EXTERN_C const IID DIID__IActSupportEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("5713F0A6-6F4A-11D5-9315-009099244EFD")
    _IActSupportEvents : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct _IActSupportEventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            _IActSupportEvents __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            _IActSupportEvents __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            _IActSupportEvents __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            _IActSupportEvents __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            _IActSupportEvents __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            _IActSupportEvents __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            _IActSupportEvents __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        END_INTERFACE
    } _IActSupportEventsVtbl;

    interface _IActSupportEvents
    {
        CONST_VTBL struct _IActSupportEventsVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _IActSupportEvents_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define _IActSupportEvents_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define _IActSupportEvents_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define _IActSupportEvents_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define _IActSupportEvents_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define _IActSupportEvents_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define _IActSupportEvents_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ___IActSupportEvents_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_ActSupport;

#ifdef __cplusplus

class DECLSPEC_UUID("5713F0A5-6F4A-11D5-9315-009099244EFD")
ActSupport;
#endif
#endif /* __ACTSUPPORTLib_LIBRARY_DEFINED__ */

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
