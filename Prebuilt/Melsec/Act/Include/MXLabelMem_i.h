

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 7.00.0500 */
/* at Thu Jun 16 15:39:56 2016
 */
/* Compiler settings for .\MXLabelMem.idl:
    Oicf, W1, Zp8, env=Win32 (32b run)
    protocol : dce , ms_ext, c_ext, robust
    error checks: stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
//@@MIDL_FILE_HEADING(  )

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

#ifndef __MXLabelMem_i_h__
#define __MXLabelMem_i_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IMXLabelMemControl_FWD_DEFINED__
#define __IMXLabelMemControl_FWD_DEFINED__
typedef interface IMXLabelMemControl IMXLabelMemControl;
#endif 	/* __IMXLabelMemControl_FWD_DEFINED__ */


#ifndef ___IMXLabelMemControlEvents_FWD_DEFINED__
#define ___IMXLabelMemControlEvents_FWD_DEFINED__
typedef interface _IMXLabelMemControlEvents _IMXLabelMemControlEvents;
#endif 	/* ___IMXLabelMemControlEvents_FWD_DEFINED__ */


#ifndef __MXLabelMemControl_FWD_DEFINED__
#define __MXLabelMemControl_FWD_DEFINED__

#ifdef __cplusplus
typedef class MXLabelMemControl MXLabelMemControl;
#else
typedef struct MXLabelMemControl MXLabelMemControl;
#endif /* __cplusplus */

#endif 	/* __MXLabelMemControl_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 


#ifndef __IMXLabelMemControl_INTERFACE_DEFINED__
#define __IMXLabelMemControl_INTERFACE_DEFINED__

/* interface IMXLabelMemControl */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IMXLabelMemControl;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("8FFE1A45-8A1E-4DD8-AB34-E2EB3AEC9049")
    IMXLabelMemControl : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE CreateLabelMemAll( 
            /* [out][in] */ LONG *lplErrCode,
            /* [retval][out] */ LONG *lplReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE CreateLabelMemPart( 
            /* [out][in] */ LONG *lplErrCode,
            /* [retval][out] */ LONG *lplReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetLabelInfoCount( 
            /* [in] */ BSTR szLabelName,
            /* [in] */ LONG lLogicalStationNo,
            /* [out] */ LONG *lplCount,
            /* [out] */ LONG *lplLabelType,
            /* [out] */ LONG *lplDataType,
            /* [out] */ LONG *lplErrCode,
            /* [retval][out] */ LONG *lplReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetLabelInfo( 
            /* [in] */ BSTR szLabelName,
            /* [in] */ LONG lLogicalStationNo,
            /* [out][in] */ LONG *lplCount,
            /* [out] */ BSTR *pszLabelNameRet,
            /* [out] */ BSTR *pszDeviceNameRet,
            /* [out] */ LONG *lplDataType,
            /* [out] */ LONG *lplDataSize,
            /* [out] */ LONG *lplErrCode,
            /* [retval][out] */ LONG *lplReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetLabelUpdateTime( 
            /* [in] */ LONG lLogicalStationNo,
            /* [out] */ LONGLONG *lplUpdateTime,
            /* [out] */ LONG *lplErrCode,
            /* [retval][out] */ LONG *lplReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ServiceStop( 
            /* [out] */ LONG *lplErrCode,
            /* [retval][out] */ LONG *lplReturnCode) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IMXLabelMemControlVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IMXLabelMemControl * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IMXLabelMemControl * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IMXLabelMemControl * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IMXLabelMemControl * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IMXLabelMemControl * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IMXLabelMemControl * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IMXLabelMemControl * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *CreateLabelMemAll )( 
            IMXLabelMemControl * This,
            /* [out][in] */ LONG *lplErrCode,
            /* [retval][out] */ LONG *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *CreateLabelMemPart )( 
            IMXLabelMemControl * This,
            /* [out][in] */ LONG *lplErrCode,
            /* [retval][out] */ LONG *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetLabelInfoCount )( 
            IMXLabelMemControl * This,
            /* [in] */ BSTR szLabelName,
            /* [in] */ LONG lLogicalStationNo,
            /* [out] */ LONG *lplCount,
            /* [out] */ LONG *lplLabelType,
            /* [out] */ LONG *lplDataType,
            /* [out] */ LONG *lplErrCode,
            /* [retval][out] */ LONG *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetLabelInfo )( 
            IMXLabelMemControl * This,
            /* [in] */ BSTR szLabelName,
            /* [in] */ LONG lLogicalStationNo,
            /* [out][in] */ LONG *lplCount,
            /* [out] */ BSTR *pszLabelNameRet,
            /* [out] */ BSTR *pszDeviceNameRet,
            /* [out] */ LONG *lplDataType,
            /* [out] */ LONG *lplDataSize,
            /* [out] */ LONG *lplErrCode,
            /* [retval][out] */ LONG *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetLabelUpdateTime )( 
            IMXLabelMemControl * This,
            /* [in] */ LONG lLogicalStationNo,
            /* [out] */ LONGLONG *lplUpdateTime,
            /* [out] */ LONG *lplErrCode,
            /* [retval][out] */ LONG *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ServiceStop )( 
            IMXLabelMemControl * This,
            /* [out] */ LONG *lplErrCode,
            /* [retval][out] */ LONG *lplReturnCode);
        
        END_INTERFACE
    } IMXLabelMemControlVtbl;

    interface IMXLabelMemControl
    {
        CONST_VTBL struct IMXLabelMemControlVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IMXLabelMemControl_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IMXLabelMemControl_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IMXLabelMemControl_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IMXLabelMemControl_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IMXLabelMemControl_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IMXLabelMemControl_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IMXLabelMemControl_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IMXLabelMemControl_CreateLabelMemAll(This,lplErrCode,lplReturnCode)	\
    ( (This)->lpVtbl -> CreateLabelMemAll(This,lplErrCode,lplReturnCode) ) 

#define IMXLabelMemControl_CreateLabelMemPart(This,lplErrCode,lplReturnCode)	\
    ( (This)->lpVtbl -> CreateLabelMemPart(This,lplErrCode,lplReturnCode) ) 

#define IMXLabelMemControl_GetLabelInfoCount(This,szLabelName,lLogicalStationNo,lplCount,lplLabelType,lplDataType,lplErrCode,lplReturnCode)	\
    ( (This)->lpVtbl -> GetLabelInfoCount(This,szLabelName,lLogicalStationNo,lplCount,lplLabelType,lplDataType,lplErrCode,lplReturnCode) ) 

#define IMXLabelMemControl_GetLabelInfo(This,szLabelName,lLogicalStationNo,lplCount,pszLabelNameRet,pszDeviceNameRet,lplDataType,lplDataSize,lplErrCode,lplReturnCode)	\
    ( (This)->lpVtbl -> GetLabelInfo(This,szLabelName,lLogicalStationNo,lplCount,pszLabelNameRet,pszDeviceNameRet,lplDataType,lplDataSize,lplErrCode,lplReturnCode) ) 

#define IMXLabelMemControl_GetLabelUpdateTime(This,lLogicalStationNo,lplUpdateTime,lplErrCode,lplReturnCode)	\
    ( (This)->lpVtbl -> GetLabelUpdateTime(This,lLogicalStationNo,lplUpdateTime,lplErrCode,lplReturnCode) ) 

#define IMXLabelMemControl_ServiceStop(This,lplErrCode,lplReturnCode)	\
    ( (This)->lpVtbl -> ServiceStop(This,lplErrCode,lplReturnCode) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IMXLabelMemControl_INTERFACE_DEFINED__ */



#ifndef __MXLabelMemLib_LIBRARY_DEFINED__
#define __MXLabelMemLib_LIBRARY_DEFINED__

/* library MXLabelMemLib */
/* [helpstring][version][uuid] */ 


EXTERN_C const IID LIBID_MXLabelMemLib;

#ifndef ___IMXLabelMemControlEvents_DISPINTERFACE_DEFINED__
#define ___IMXLabelMemControlEvents_DISPINTERFACE_DEFINED__

/* dispinterface _IMXLabelMemControlEvents */
/* [helpstring][uuid] */ 


EXTERN_C const IID DIID__IMXLabelMemControlEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("78EFB36D-1CE2-458B-A4EB-844B1300C628")
    _IMXLabelMemControlEvents : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct _IMXLabelMemControlEventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            _IMXLabelMemControlEvents * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            _IMXLabelMemControlEvents * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            _IMXLabelMemControlEvents * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            _IMXLabelMemControlEvents * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            _IMXLabelMemControlEvents * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            _IMXLabelMemControlEvents * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            _IMXLabelMemControlEvents * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        END_INTERFACE
    } _IMXLabelMemControlEventsVtbl;

    interface _IMXLabelMemControlEvents
    {
        CONST_VTBL struct _IMXLabelMemControlEventsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _IMXLabelMemControlEvents_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define _IMXLabelMemControlEvents_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define _IMXLabelMemControlEvents_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define _IMXLabelMemControlEvents_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define _IMXLabelMemControlEvents_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define _IMXLabelMemControlEvents_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define _IMXLabelMemControlEvents_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ___IMXLabelMemControlEvents_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_MXLabelMemControl;

#ifdef __cplusplus

class DECLSPEC_UUID("18B34EAC-5D01-4F57-A96F-EDB00AF35C1F")
MXLabelMemControl;
#endif
#endif /* __MXLabelMemLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

unsigned long             __RPC_USER  BSTR_UserSize(     unsigned long *, unsigned long            , BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserMarshal(  unsigned long *, unsigned char *, BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserUnmarshal(unsigned long *, unsigned char *, BSTR * ); 
void                      __RPC_USER  BSTR_UserFree(     unsigned long *, BSTR * ); 

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


