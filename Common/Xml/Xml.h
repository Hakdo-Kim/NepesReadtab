#pragma once

#include "Common.h"
#include "CommonCapture.h"

#ifdef DEF_LPAPP
#include "Sequence/NAVI_APP_define.h"
#include "User/UserConfig.h"
#endif

#include "Camera/CameraDevice.h"
#include "Xml/XmlNode.h"

class CXml
{
public:
	CXml();
	~CXml();

#ifdef DEF_LPAPP
	stSequenceManager* Load(TCHAR* pszPath);
	BOOL Save(TCHAR* pszPath, stSequenceManager* pstSequence);

	stProgramSetting* LoadSetting(TCHAR* pszPath);
	BOOL SaveSetting(TCHAR* pszPath, stProgramSetting* pstSetting);

	stStat_SequenceManager* LoadStat(TCHAR* pszPath);
	BOOL SaveStat(TCHAR* pszPath, stStat_SequenceManager* pstStat);

	// User Config.
	BOOL LoadUserConfig(TCHAR* pszPath, CUserConfig& UserConfig);
	BOOL SaveUserConfig(TCHAR* pszPath, CUserConfig& UserConfig);
#endif

	BOOL LoadDefCamera(TCHAR* pszPath, CCameraDevice& DefDevice);
	
	BOOL LoadCameraUserConfig(TCHAR* pszPath, CCameraDevice& DefDevice);
	BOOL SaveCameraUserConfig(TCHAR* pszPath, CCameraDevice& DefDevice);

	BOOL LoadOption(TCHAR* pszPath, INFO_OPTION& stOpt);
	BOOL SaveOption(TCHAR* pszPath, INFO_OPTION& stOpt);

	BOOL LoadInspection(TCHAR* pszPath, INFO_INSPECTION& stInspection);
	BOOL SaveInspection(TCHAR* pszPath, INFO_INSPECTION& stInspection, TYPE_CAMERAPOS ePos);

protected:

#ifdef DEF_LPAPP
	//
	BOOL LoadXml(CUserConfig& UserConfig, CXmlNode* pXmlNode);
	CXmlNode* SaveXml(CUserConfig& UserConfig);

	BOOL LoadOutputConfigList(CUserConfig& UserConfig, CXmlNode* pXmlNode);
	BOOL LoadOutputConfig(INFO_OUTPUTCONFIG& stConfig, CXmlNode* pXmlNode);

	BOOL LoadOutputText(INFO_OUTPUTTEXT& stText, CXmlNode* pXmlNode);
	BOOL LoadOutputPen(INFO_OUTPUTPEN& stPen, CXmlNode* pXmlNode);
	BOOL LoadOutputBrush(INFO_OUTPUTBRUSH& stBrush, CXmlNode* pXmlNode);
	BOOL LoadOutputOption(INFO_OUTPUTCONFIG& stConfig, CXmlNode* pXmlNode);


	CXmlNode* SaveOutputConfigList(CXmlNode* pParentNode, CUserConfig& UserConfig);
	CXmlNode* SaveOutputConfig(CXmlNode* pParentNode, TYPE_OUTPUT eType, INFO_OUTPUTCONFIG& stConfig);
	
	CXmlNode* SaveOutputText(CXmlNode* pParentNode, INFO_OUTPUTTEXT& stText);
	CXmlNode* SaveOutputPen(CXmlNode* pParentNode, INFO_OUTPUTPEN& stPen);
	CXmlNode* SaveOutputBrush(CXmlNode* pParentNode, INFO_OUTPUTBRUSH& stBrush);
	CXmlNode* SaveOutputOption(CXmlNode* pParentNode, INFO_OUTPUTCONFIG& stConfig);



	//
	BOOL LoadXml(stStat_SequenceManager* pstStat, CXmlNode* pXmlNode);
	CXmlNode* SaveXml(stStat_SequenceManager* pstStat);

	BOOL LoadStatSequence(CXmlNode* pXmlNode, stStat_Sequence& stStatSeq);
	BOOL LoadStatSeqStat(CXmlNode* pXmlNode, stStat_Sequence& stStatSeq);
	BOOL LoadStatApplication(CXmlNode* pXmlNode, stStat_Application& stStatApp);
	BOOL LoadStatAppStat(CXmlNode* pXmlNode, stStat_Application& stStatApp);

	CXmlNode* SaveStatSequence(CXmlNode* pParentNode, stStat_Sequence& stStatSeq);
	CXmlNode* SaveStatSeqStat(CXmlNode* pParentNode, stStat_Sequence& stStatSeq);
	CXmlNode* SaveStatAppliction(CXmlNode* pParentNode, stStat_Application& stStatApp);
	CXmlNode* SaveStatAppStat(CXmlNode* pParentNode, stStat_Application& stStatApp);


	
	//
	BOOL LoadXml(stProgramSetting* pstSetting, CXmlNode* pXmlNode);
	CXmlNode* SaveXml(stProgramSetting* pstSetting);

	//
	BOOL LoadSettingAuth(CXmlNode* pXmlNode, stProgramSetting& stSetting);
	BOOL LoadSettingLicense(CXmlNode* pXmlNode, stProgramSetting& stSetting);
	BOOL LoadSettingPath(CXmlNode* pXmlNode, stProgramSetting& stSetting);
	BOOL LoadSettingConfigProject(CXmlNode* pXmlNode, stProgramSetting& stSetting);
	BOOL LoadSettingInspectProject(CXmlNode* pXmlNode, stProgramSetting& stSetting);
	BOOL LoadSettingTransferData(CXmlNode* pXmlNode, stProgramSetting& stSetting);
	BOOL LoadSettingTransferDataSerial(CXmlNode* pXmlNode, stProgramSetting& stSetting);
	BOOL LoadSettingTransferDataEthernet(CXmlNode* pXmlNode, stProgramSetting& stSetting);
	BOOL LoadSettingTransferDataEthernetServerConnected(CXmlNode* pXmlNode, stProgramSetting& stSetting);
	BOOL LoadSettingTransferDataEthernetServerItems(CXmlNode* pXmlNode, stProgramSetting& stSetting);
	BOOL LoadSettingTransferDataEthernetClientItems(CXmlNode* pXmlNode, stProgramSetting& stSetting);

	BOOL LoadSettingLogging(CXmlNode* pXmlNode, stProgramSetting& stSetting);
	BOOL LoadSettingLoggingFile(CXmlNode* pXmlNode, stProgramSetting& stSetting);
	BOOL LoadSettingLoggingFileAutoDelete(CXmlNode* pXmlNode, stProgramSetting& stSetting);
	BOOL LoadSettingLoggingImage(CXmlNode* pXmlNode, stProgramSetting& stSetting);
	BOOL LoadSettingLoggingImageOriginal(CXmlNode* pXmlNode, stProgramSetting& stSetting);
	BOOL LoadSettingLoggingImageOriginalPass(CXmlNode* pXmlNode, stProgramSetting& stSetting);
	BOOL LoadSettingLoggingImageOriginalFail(CXmlNode* pXmlNode, stProgramSetting& stSetting);
	BOOL LoadSettingLoggingImageResult(CXmlNode* pXmlNode, stProgramSetting& stSetting);
	BOOL LoadSettingLoggingImageResultPass(CXmlNode* pXmlNode, stProgramSetting& stSetting);
	BOOL LoadSettingLoggingImageResultFail(CXmlNode* pXmlNode, stProgramSetting& stSetting);


	CXmlNode* SaveSettingAuth(CXmlNode* pParentNode, stProgramSetting& stSetting);
	CXmlNode* SaveSettingLicense(CXmlNode* pParentNode, stProgramSetting& stSetting);
	CXmlNode* SaveSettingPath(CXmlNode* pParentNode, stProgramSetting& stSetting);
	CXmlNode* SaveSettingConfigProject(CXmlNode* pParentNode, stProgramSetting& stSetting);
	CXmlNode* SaveSettingInspectProject(CXmlNode* pParentNode, stProgramSetting& stSetting);
	CXmlNode* SaveSettingTransferData(CXmlNode* pParentNode, stProgramSetting& stSetting);
	CXmlNode* SaveSettingTransferDataSerial(CXmlNode* pParentNode, stProgramSetting& stSetting);
	CXmlNode* SaveSettingTransferDataEthernet(CXmlNode* pParentNode, stProgramSetting& stSetting);

	CXmlNode* SaveSettingLogging(CXmlNode* pParentNode, stProgramSetting& stSetting);
	CXmlNode* SaveSettingLoggingFile(CXmlNode* pParentNode, stProgramSetting& stSetting);
	CXmlNode* SaveSettingLoggingImage(CXmlNode* pParentNode, stProgramSetting& stSetting);

	CXmlNode* SaveSettingLoggingFileAutoDelete(CXmlNode* pParentNode, stProgramSetting& stSetting);
	CXmlNode* SaveSettingLoggingImageOriginal(CXmlNode* pParentNode, stProgramSetting& stSetting);
	CXmlNode* SaveSettingLoggingImageOriginalPass(CXmlNode* pParentNode, stProgramSetting& stSetting);
	CXmlNode* SaveSettingLoggingImageOriginalFail(CXmlNode* pParentNode, stProgramSetting& stSetting);
	CXmlNode* SaveSettingLoggingImageResult(CXmlNode* pParentNode, stProgramSetting& stSetting);
	CXmlNode* SaveSettingLoggingImageResultPass(CXmlNode* pParentNode, stProgramSetting& stSetting);
	CXmlNode* SaveSettingLoggingImageResultFail(CXmlNode* pParentNode, stProgramSetting& stSetting);



	//
	BOOL LoadXml(stSequenceManager* pstSequence, CXmlNode* pXmlNode);
	
	stSequence* LoadSequence(CXmlNode* pXmlNode);
	stApplication* LoadApplication(CXmlNode* pXmlNode);

	BOOL LoadApplicationInfo(CXmlNode* pXmlNode, stAPPINFO& stAppInfo);
	BOOL LoadApplicationImageList(CXmlNode* pXmlNode, stAPPINFO& stAppInfo);
	BOOL LoadApplicationConfigList(CXmlNode* pXmlNode, stAPPINFO& stAppInfo);

	BOOL LoadApplicationRoiList(CXmlNode* pXmlNode, stAPPINFO& stAppInfo);
	BOOL LoadApplicationRoiInfo(CXmlNode* pXmlNode, CLP_ROI& stCLRoi);
	BOOL LoadApplicationRoiPos(CXmlNode* pXmlNode, CLP_ROI& stCLRoi);
	BOOL LoadApplicationRoiOption(CXmlNode* pXmlNode, CLP_ROI& stCLRoi);
	BOOL LoadApplicationRoiRingOption(CXmlNode* pXmlNode, CLP_ROI& stCLRoi);
	BOOL LoadApplicationRoiCriteriaOption(CXmlNode* pXmlNode, CLP_ROI& stCLRoi);

	BOOL LoadApplicationFilter(CXmlNode* pXmlNode, stAPPFILTER& stAppFilter);
	

	//
	CXmlNode* SaveXml(stSequenceManager* pstSequence);

	CXmlNode* SaveSequence(CXmlNode* pParentNode, stSequence* pstSequence);
	CXmlNode* SaveApplication(CXmlNode* pParentNode, stApplication* pstApp);
	CXmlNode* SaveApplicationInfo(CXmlNode* pParentNode, stAPPINFO* pstAppInfo);
	CXmlNode* SaveApplicationFilter(CXmlNode* pParentNode, stAPPFILTER* pstAppFilter);

	CXmlNode* SaveRoiInfo(CXmlNode* pParentNode, CLP_ROI* pRoi);

#endif


	//
	BOOL LoadXml(CCameraDevice& DefDevice, CXmlNode* pXmlNode);

	BOOL LoadCamera(CXmlNode* pXmlNode, TYPE_NETWORK eNetwork, CCameraDevice& DefDevice);
	BOOL LoadCamera(CXmlNode* pXmlNode, INFO_DEFDEV* pstDefDev);

	BOOL LoadCameraCL(CXmlNode* pXmlNode, TYPE_NETWORK eNetwork, CCameraDevice& DefDevice);
	BOOL LoadCameraCL(CXmlNode* pXmlNode, INFO_DEFDEV_CL* pstDefDev);

	BOOL LoadFramegrabber(CXmlNode* pXmlNode, CCameraDevice& DefDevice);
	BOOL LoadGrabber(CXmlNode* pXmlNode, CCameraDevice& DefDevice);
	BOOL LoadCamfile(CXmlNode* pXmlNode, INFO_FRAMEGRABBER_CAMFILE* pstGrabber);
	BOOL LoadCamfileFromTrigger(CXmlNode* pXmlNode, INFO_FRAMEGRABBER_CAMFILE* pstGrabber);


	BOOL LoadCameraDataBits(CXmlNode* pXmlNode, INFO_DEFDEV* pstDefDev);
	BOOL LoadCameraBit(CXmlNode* pXmlNode, INFO_DEFDATABIT* pstDefDataBit);

	BOOL LoadCameraColor(CXmlNode* pXmlNode, INFO_DEFDEV* pstDefDev);
	BOOL LoadCameraColorFormat(CXmlNode* pXmlNode, INFO_DEFCOLORFORMAT* pstDefColorFormat);
	BOOL LoadCameraPixelFormat(CXmlNode* pXmlNode, INFO_DEFPIXELFORMAT* pstDefPixelFormat);
	BOOL LoadCameraPixel(CXmlNode* pXmlNode, INFO_DEFPIXELFORMAT* pstDefPixelFormat);
	BOOL LoadCameraPixelItem(CXmlNode* pXmlNode, INFO_DEFPIXEL* pstDefPixel);
	BOOL LoadCameraPixelRgbGain(CXmlNode* pXmlNode, INFO_DEFCOLORGAIN* pstDefColorGain);
	BOOL LoadCameraPixelGain(CXmlNode* pXmlNode, INFO_DEFGAIN* pstDefGain);
	

	BOOL LoadCameraMTU(CXmlNode* pXmlNode, INFO_DEFDEV* pstDefDev);


	BOOL LoadCameraRoi(CXmlNode* pXmlNode, INFO_DEFDEV* pstDefDev);
	BOOL LoadCameraGain(CXmlNode* pXmlNode, INFO_DEFDEV* pstDefDev);
	BOOL LoadCameraExposure(CXmlNode* pXmlNode, INFO_DEFDEV* pstDefDev);
	BOOL LoadCameraFramerate(CXmlNode* pXmlNode, INFO_DEFDEV* pstDefDev);

	BOOL LoadCameraTrigger(CXmlNode* pXmlNode, INFO_DEFDEV* pstDefDev);
	BOOL LoadCameraTriggerDelay(CXmlNode* pXmlNode, INFO_DEFDEV* pstDefDev);
	BOOL LoadCameraTriggerType(CXmlNode* pXmlNode, INFO_DEFDEV* pstDefDev);

	BOOL LoadCameraStrobe(CXmlNode* pXmlNode, INFO_DEFDEV* pstDefDev);
	BOOL LoadCameraStrobeSync(CXmlNode* pXmlNode, INFO_DEFDEV* pstDefDev);
	BOOL LoadCameraStrobeDelay(CXmlNode* pXmlNode, INFO_DEFDEV* pstDefDev);
	BOOL LoadCameraStrobeWidth(CXmlNode* pXmlNode, INFO_DEFDEV* pstDefDev);
	BOOL LoadCameraSymmetry(CXmlNode* pXmlNode, INFO_DEFDEV* pstDefDev);
	BOOL LoadCameraLut(CXmlNode* pXmlNode, INFO_DEFDEV* pstDefDev);
	BOOL LoadCameraUserset(CXmlNode* pXmlNode, INFO_DEFDEV* pstDefEffect);
	BOOL LoadCameraUsersetStartup(CXmlNode* pXmlNode, INFO_DEFUSERSET* pstDefUserset);

	BOOL LoadCameraEffect(CXmlNode* pXmlNode, INFO_DEFDEV* pstDefDev);
	BOOL LoadCameraEffectNR(CXmlNode* pXmlNode, INFO_DEFEFFECT* pstDefEffect);
	BOOL LoadCameraEffectGC(CXmlNode* pXmlNode, INFO_DEFEFFECT* pstDefEffect);
	BOOL LoadCameraEffectCM(CXmlNode* pXmlNode, INFO_DEFEFFECT* pstDefEffect);
	BOOL LoadCameraEffectAWB(CXmlNode* pXmlNode, INFO_DEFEFFECT* pstDefEffect);
	BOOL LoadCameraEffectFPN(CXmlNode* pXmlNode, INFO_DEFEFFECT* pstDefEffect);
	BOOL LoadCameraEffectPRNU(CXmlNode* pXmlNode, INFO_DEFEFFECT* pstDefEffect);
	BOOL LoadCameraEffectDPC(CXmlNode* pXmlNode, INFO_DEFEFFECT* pstDefEffect);
	BOOL LoadCameraEffectSmoth(CXmlNode* pXmlNode, INFO_DEFEFFECT* pstDefEffect);
	BOOL LoadCameraEffectSharpen(CXmlNode* pXmlNode, INFO_DEFEFFECT* pstDefEffect);
	
	
	BOOL LoadCameraImageTaps(CXmlNode* pXmlNode, INFO_DEFDEV_CL* pstDefDev);
	BOOL LoadCameraCLTap(CXmlNode* pXmlNode, INFO_DEFDEV_CL* pstDefDev);
	BOOL LoadCameraDataBits(CXmlNode* pXmlNode, INFO_CLIMGTAP* pstImgTap);
	BOOL LoadCameraCLBit(CXmlNode* pXmlNode, INFO_CLIMGTAP* pstImgTap);
	BOOL LoadCameraRange(CXmlNode* pXmlNode, INFO_DEFRANGE* pstRange);


	//
	CXmlNode* CreateNode(CXmlNode* pParentNode, TCHAR* pTitle, TYPE_XML_VALUE eType, void* pData, int nDataLen);
	CXmlNode* CreateNodeString(CXmlNode* pParentNode, TCHAR* pTitle, CString szValue);
	CXmlNode* CreateNodeInt(CXmlNode* pParentNode, TCHAR* pTitle, int nValue);
	CXmlNode* CreateNodeUnsignedInt(CXmlNode* pParentNode, TCHAR* pTitle, DWORD dwValue);
	CXmlNode* CreateNodeDouble(CXmlNode* pParentNode, TCHAR* pTitle, double fValue);

	BOOL AddAttributeString(CXmlNode* pNode, TCHAR* pTitle, CString szValue);
	BOOL AddAttributeInt(CXmlNode* pNode, TCHAR* pTitle, int nValue);
	BOOL AddAttributeUnsignedInt(CXmlNode* pNode, TCHAR* pTitle, DWORD dwValue);
	BOOL AddAttributeDouble(CXmlNode* pNode, TCHAR* pTitle, double fValue);


#ifdef DEF_LPAPP
	//
	BOOL GetApplicationType(eAPPLICATION_TYPE& eType, const TCHAR* pTxt);
	BOOL SetApplicationType(eAPPLICATION_TYPE eType, TCHAR* pTxt, int nLen);
	
	BOOL GetRoiType(eROITYPE& eType, const TCHAR* pTxt);
	BOOL SetRoiType(eROITYPE eType, TCHAR* pTxt, int nLen);

	BOOL GetRoiFaceType(eROIFACE& eType, const TCHAR* pTxt);
	BOOL SetRoiFaceType(eROIFACE eType, TCHAR* pTxt, int nLen);


	BOOL GetRoi4DirType(eROI4DIR& eType, const TCHAR* pTxt);
	BOOL SetRoi4DirType(eROI4DIR eType, TCHAR* pTxt, int nLen);

	BOOL GetRoi2DirType(eROI2DIR& eType, const TCHAR* pTxt);
	BOOL SetRoi2DirType(eROI2DIR eType, TCHAR* pTxt, int nLen);
#endif

	BOOL GetBoolean(BOOL& bBool, const TCHAR* pTxt);
	BOOL SetBoolean(BOOL bBool, TCHAR* pTxt, int nLen);

	BOOL GetDataBit(TYPE_DATABIT& eDataBit, int nBit);


	BOOL LoadXml(INFO_DEFDEV_USERCONFIG& stUserConfig, CXmlNode* pXmlNode);
	CXmlNode* SaveXml(const INFO_DEFDEV_USERCONFIG& stUserConfig);

	BOOL LoadCameraUserCommon(CXmlNode* pXmlNode, INFO_DEFDEV_USERCONFIG& stUserConfig);
	BOOL LoadCameraUserCommonTimeOut(CXmlNode* pXmlNode, INFO_TIMEOUT& stTimeOut);
	BOOL LoadCameraUserCommonTimeOutRange(CXmlNode* pXmlNode, INFO_TIMEOUT& stTimeOut);
	BOOL LoadCameraUserGigE(CXmlNode* pXmlNode, INFO_USERGIGE& stUserGigE);
	BOOL LoadCameraUserGigEMtu(CXmlNode* pXmlNode, INFO_MTU& stMtu);

	CXmlNode* SaveCameraUserCommon(CXmlNode* pParentNode, const INFO_DEFDEV_USERCONFIG& stUserConfig);
	CXmlNode* SaveCameraUserCommonTimeOut(CXmlNode* pParentNode, const INFO_TIMEOUT& stTimeOut);
	CXmlNode* SaveCameraUserCommonTimeOutRange(CXmlNode* pParentNode, const INFO_TIMEOUT& stTimeOut);
	CXmlNode* SaveCameraUserGigE(CXmlNode* pParentNode, const INFO_USERGIGE& stUserGigE);
	CXmlNode* SaveCameraUserGigEMtu(CXmlNode* pParentNode, const INFO_MTU& stMtu);



	//
	BOOL LoadOption(INFO_OPTION& stOpt, CXmlNode* pXmlNode);
	CXmlNode* SaveOption(const  INFO_OPTION& stOpt);


	
	//
	BOOL LoadInspection(INFO_INSPECTION& stInspection, CXmlNode* pXmlNode);
	BOOL LoadInspectionStepSize(INFO_INSPECTION_SIZE& stSize, CXmlNode* pXmlNode);
	BOOL LoadInspectionStepSizeCalibrate(INFO_CALIBRATION& stSize, CXmlNode* pXmlNode);
	BOOL LoadInspectionStepSizeGain(INFO_SIZE_GAIN& stSize, CXmlNode* pXmlNode);
	BOOL LoadInspectionStepSizeRoi(INFO_INSPECTION_SIZE& stSize, CXmlNode* pXmlNode);
	BOOL LoadInspectionStepSizeSample(INFO_INSPECTION_SIZE& stSize, CXmlNode* pXmlNode);
	BOOL LoadInspectionStepStain(INFO_INSPECTION_STAIN& stStain, CXmlNode* pXmlNode);
	BOOL LoadInspectionStepDiffer(INFO_INSPECTION_DIFFER& stDiffeer, CXmlNode* pXmlNode);
	BOOL LoadInspectionStepBubble(INFO_INSPECTION_BUBBLE& stBubble, CXmlNode* pXmlNode);
	BOOL LoadInspectionStepScratch(INFO_INSPECTION_SCRATCH& stScratch, CXmlNode* pXmlNode);
	BOOL LoadInspectionStepStamp(INFO_INSPECTION_STAMP& stStamp, CXmlNode* pXmlNode);
	BOOL LoadInspectionCalc(INFO_INSPECTION_SIZE_CALC& stCalc, CXmlNode* pXmlNode);

	BOOL LoadStepRectRoi(INFO_RECT_ROI& stRectRoi, CXmlNode* pXmlNode);
	BOOL LoadStepMarsParam(INFO_MARS_PARA& stMarsParam, CXmlNode* pXmlNode);
	BOOL LoadStepCalibParam(INFO_CALIB_PARA& stCalibParam, CXmlNode* pXmlNode);
	BOOL LoadStepJudgmentsParam(INFO_JUDGMENT_PARA& stJudgParam, CXmlNode* pXmlNode);
	

	

	CXmlNode* SaveInspection(const INFO_INSPECTION& stInspection, TYPE_CAMERAPOS ePos);
	CXmlNode* SaveInspectionCam(const int& nCameranum, TYPE_CAMERAPOS ePos);
	CXmlNode* SaveInspectionSize(const INFO_INSPECTION_SIZE& stSize);
	CXmlNode* SaveInspectionStain(const INFO_INSPECTION_STAIN& stStain);
	CXmlNode* SaveInspectionDiffer(const INFO_INSPECTION_DIFFER& stDiffeer);
	CXmlNode* SaveInspectionBubble(const INFO_INSPECTION_BUBBLE& stBubble);
	CXmlNode* SaveInspectionScratch(const INFO_INSPECTION_SCRATCH& stScratch);
	CXmlNode* SaveInspectionStamp(const INFO_INSPECTION_STAMP& stStamp);
	CXmlNode* SaveInspectionSizeSecond(const INFO_INSPECTION_SIZE& stSize);
	CXmlNode* SaveInspectionCalc(const INFO_INSPECTION_SIZE_CALC& stCalc);

	CXmlNode* SaveStepRectRoi(const INFO_RECT_ROI& stRectRoi);
	CXmlNode* SaveStepMarsParam(const INFO_MARS_PARA& stMarsParam);
	CXmlNode* SaveStepCalibParam(const INFO_CALIB_PARA& stCalibParam);
	CXmlNode* SaveStepJudgmentsParam(const INFO_JUDGMENT_PARA& stJudgParam);


	
};