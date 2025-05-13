

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 7.00.0555 */
/* at Thu Jun 16 15:39:24 2016
 */
/* Compiler settings for ActSupportMsg.idl:
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

#ifndef __ActSupportMsg_i_h__
#define __ActSupportMsg_i_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IActSupportMsg_FWD_DEFINED__
#define __IActSupportMsg_FWD_DEFINED__
typedef interface IActSupportMsg IActSupportMsg;
#endif 	/* __IActSupportMsg_FWD_DEFINED__ */


#ifndef __IActMLSupportMsg_FWD_DEFINED__
#define __IActMLSupportMsg_FWD_DEFINED__
typedef interface IActMLSupportMsg IActMLSupportMsg;
#endif 	/* __IActMLSupportMsg_FWD_DEFINED__ */


#ifndef ___IActSupportMsgEvents_FWD_DEFINED__
#define ___IActSupportMsgEvents_FWD_DEFINED__
typedef interface _IActSupportMsgEvents _IActSupportMsgEvents;
#endif 	/* ___IActSupportMsgEvents_FWD_DEFINED__ */


#ifndef __ActSupportMsg_FWD_DEFINED__
#define __ActSupportMsg_FWD_DEFINED__

#ifdef __cplusplus
typedef class ActSupportMsg ActSupportMsg;
#else
typedef struct ActSupportMsg ActSupportMsg;
#endif /* __cplusplus */

#endif 	/* __ActSupportMsg_FWD_DEFINED__ */


#ifndef ___IActMLSupportMsgEvents_FWD_DEFINED__
#define ___IActMLSupportMsgEvents_FWD_DEFINED__
typedef interface _IActMLSupportMsgEvents _IActMLSupportMsgEvents;
#endif 	/* ___IActMLSupportMsgEvents_FWD_DEFINED__ */


#ifndef __ActMLSupportMsg_FWD_DEFINED__
#define __ActMLSupportMsg_FWD_DEFINED__

#ifdef __cplusplus
typedef class ActMLSupportMsg ActMLSupportMsg;
#else
typedef struct ActMLSupportMsg ActMLSupportMsg;
#endif /* __cplusplus */

#endif 	/* __ActMLSupportMsg_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 


#ifndef __IActSupportMsg_INTERFACE_DEFINED__
#define __IActSupportMsg_INTERFACE_DEFINED__

/* interface IActSupportMsg */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IActSupportMsg;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("13D4BA2D-26B4-4194-A965-9B14842DABC8")
    IActSupportMsg : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetErrorMessage( 
            /* [in] */ LONG lErrorCode,
            /* [string][out] */ BSTR *lpszErrorMessage,
            /* [retval][out] */ LONG *lplReturnCode) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IActSupportMsgVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IActSupportMsg * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IActSupportMsg * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IActSupportMsg * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IActSupportMsg * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IActSupportMsg * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IActSupportMsg * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IActSupportMsg * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetErrorMessage )( 
            IActSupportMsg * This,
            /* [in] */ LONG lErrorCode,
            /* [string][out] */ BSTR *lpszErrorMessage,
            /* [retval][out] */ LONG *lplReturnCode);
        
        END_INTERFACE
    } IActSupportMsgVtbl;

    interface IActSupportMsg
    {
        CONST_VTBL struct IActSupportMsgVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IActSupportMsg_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IActSupportMsg_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IActSupportMsg_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IActSupportMsg_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IActSupportMsg_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IActSupportMsg_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IActSupportMsg_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IActSupportMsg_GetErrorMessage(This,lErrorCode,lpszErrorMessage,lplReturnCode)	\
    ( (This)->lpVtbl -> GetErrorMessage(This,lErrorCode,lpszErrorMessage,lplReturnCode) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IActSupportMsg_INTERFACE_DEFINED__ */


#ifndef __IActMLSupportMsg_INTERFACE_DEFINED__
#define __IActMLSupportMsg_INTERFACE_DEFINED__

/* interface IActMLSupportMsg */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IActMLSupportMsg;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("A1D87A6D-E020-4CB7-BC38-BDE4DD84B77B")
    IActMLSupportMsg : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetErrorMessage( 
            /* [in] */ VARIANT varErrorCode,
            /* [out] */ VARIANT *lpvarErrorMessage,
            /* [retval][out] */ VARIANT *lpvarReturnCode) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IActMLSupportMsgVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IActMLSupportMsg * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IActMLSupportMsg * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IActMLSupportMsg * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IActMLSupportMsg * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IActMLSupportMsg * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IActMLSupportMsg * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IActMLSupportMsg * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetErrorMessage )( 
            IActMLSupportMsg * This,
            /* [in] */ VARIANT varErrorCode,
            /* [out] */ VARIANT *lpvarErrorMessage,
            /* [retval][out] */ VARIANT *lpvarReturnCode);
        
        END_INTERFACE
    } IActMLSupportMsgVtbl;

    interface IActMLSupportMsg
    {
        CONST_VTBL struct IActMLSupportMsgVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IActMLSupportMsg_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IActMLSupportMsg_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IActMLSupportMsg_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IActMLSupportMsg_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IActMLSupportMsg_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IActMLSupportMsg_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IActMLSupportMsg_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IActMLSupportMsg_GetErrorMessage(This,varErrorCode,lpvarErrorMessage,lpvarReturnCode)	\
    ( (This)->lpVtbl -> GetErrorMessage(This,varErrorCode,lpvarErrorMessage,lpvarReturnCode) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IActMLSupportMsg_INTERFACE_DEFINED__ */



#ifndef __ActSupportMsgLib_LIBRARY_DEFINED__
#define __ActSupportMsgLib_LIBRARY_DEFINED__

/* library ActSupportMsgLib */
/* [helpstring][version][uuid] */ 


EXTERN_C const IID LIBID_ActSupportMsgLib;

#ifndef ___IActSupportMsgEvents_DISPINTERFACE_DEFINED__
#define ___IActSupportMsgEvents_DISPINTERFACE_DEFINED__

/* dispinterface _IActSupportMsgEvents */
/* [helpstring][uuid] */ 


EXTERN_C const IID DIID__IActSupportMsgEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("226E9B0B-E9FB-46EB-9FDD-0B20C887F45C")
    _IActSupportMsgEvents : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct _IActSupportMsgEventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            _IActSupportMsgEvents * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            _IActSupportMsgEvents * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            _IActSupportMsgEvents * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            _IActSupportMsgEvents * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            _IActSupportMsgEvents * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            _IActSupportMsgEvents * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            _IActSupportMsgEvents * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        END_INTERFACE
    } _IActSupportMsgEventsVtbl;

    interface _IActSupportMsgEvents
    {
        CONST_VTBL struct _IActSupportMsgEventsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _IActSupportMsgEvents_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define _IActSupportMsgEvents_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define _IActSupportMsgEvents_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define _IActSupportMsgEvents_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define _IActSupportMsgEvents_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define _IActSupportMsgEvents_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define _IActSupportMsgEvents_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ___IActSupportMsgEvents_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_ActSupportMsg;

#ifdef __cplusplus

class DECLSPEC_UUID("15C5A7A2-53A5-445C-B294-F383F951AC92")
ActSupportMsg;
#endif

#ifndef ___IActMLSupportMsgEvents_DISPINTERFACE_DEFINED__
#define ___IActMLSupportMsgEvents_DISPINTERFACE_DEFINED__

/* dispinterface _IActMLSupportMsgEvents */
/* [helpstring][uuid] */ 


EXTERN_C const IID DIID__IActMLSupportMsgEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("D3779B1B-1D42-47DA-8DC9-32E9EE60159A")
    _IActMLSupportMsgEvents : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct _IActMLSupportMsgEventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            _IActMLSupportMsgEvents * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            _IActMLSupportMsgEvents * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            _IActMLSupportMsgEvents * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            _IActMLSupportMsgEvents * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            _IActMLSupportMsgEvents * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            _IActMLSupportMsgEvents * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            _IActMLSupportMsgEvents * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        END_INTERFACE
    } _IActMLSupportMsgEventsVtbl;

    interface _IActMLSupportMsgEvents
    {
        CONST_VTBL struct _IActMLSupportMsgEventsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _IActMLSupportMsgEvents_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define _IActMLSupportMsgEvents_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define _IActMLSupportMsgEvents_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define _IActMLSupportMsgEvents_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define _IActMLSupportMsgEvents_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define _IActMLSupportMsgEvents_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define _IActMLSupportMsgEvents_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ___IActMLSupportMsgEvents_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_ActMLSupportMsg;

#ifdef __cplusplus

class DECLSPEC_UUID("AE77FCC7-A9DC-4A11-A25C-04B7C44E32E6")
ActMLSupportMsg;
#endif
#endif /* __ActSupportMsgLib_LIBRARY_DEFINED__ */

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


