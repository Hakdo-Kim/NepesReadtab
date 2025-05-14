#pragma once

#define STR_MSG_CAPTION								_T("CAPTURE")
#define STR_MSG_CLOSE								_T("프로그램을 종료합니다.")
#define STR_MSG_WRONGPASSWD							_T("잘못된 입력입니다.")

#define STR_MSG_CAPTUREMODE							_T("정상적인 Capture 동작을 위해, Freerun 설정을 해제하거나 Trigger 설정을 조정해 주세요.\r\n(Camera: Snap-Freerun)")
#define STR_MSG_TRIGGERMODE							_T("정상적인 Capture 동작을 위해, Trigger 설정을 조정합니다.\r\n(Camera: Snap-Freerun)")

#define STR_MSG_DIRLOCATION							_T("파일을 저장할 위치를 확인해 주세요.")

#define STR_MSG_ERROR_SERIAL						_T("Serial Device를 사용할 수 없습니다. COM port를 확인해 주세요")
#ifdef USE_PLC_MXCOMPONENT
#define STR_MSG_ERROR_PLCMXCOMPONENT				_T("PLC Device를 사용할 수 없습니다. 연결 설정을 확인해 주세요")
#endif
#define STR_MSG_ERROR_ETHERNET						_T("Ethernet Device를 사용할 수 없습니다. 연결 설정을 확인해 주세요")
#define STR_MSG_ERROR_STROBE						_T("조명제어에 실패했습니다. 장치를 확인해 주세요")

#define STR_MSG_ECONNECT_CAMERA						_T("Camera 구성이 완료되지 않았습니다. 설정을 확인해 주세요.")
#define STR_MSG_ECONNECT_STROBE						_T("조명 구성이 완료되지 않았습니다. 설정을 확인해 주세요.")
#ifdef USE_PLC_MXCOMPONENT
#define STR_MSG_ECONNECT_PLCMXCOMPONENT				_T("PLC 제어용 통신 구성이 완료되지 않았습니다. 설정을 확인해 주세요.")
#endif
#define STR_MSG_ECONNECT_COMMUNICATE				_T("제어용 통신 구성이 완료되지 않았습니다. 설정을 확인해 주세요.")

#define STR_MSG_EINIT_LIBRARY						_T("검사 라이브러리 초기화에 실패하였습니다.")
#define STR_MSG_ELOAD_IMAGE							_T("검사용 이미지가 없습니다.")

#define STR_MSG_ESTART_INSPECTION					_T("검사를 시작할 수 없습니다.")

#define STR_MSG_FAIL_INSPECTION						_T("검사 실패하였습니다.")
#define STR_MSG_FAIL_SAVE_OPTION					_T("변경된 옵션정보를 파일로 저장하지 못했습니다.")
#define STR_MSG_DEFECT_DETECTED						_T("기준을 초과하는 결함이 검출되었습니다.")

#define STR_MSG_FAIL_LOTID							_T("Lot ID 입력을 확인해주세요. (메인화면)")
#define STR_MSG_FAIL_INPUT_LOTID					_T("입력된 Lot ID를 다시 확인해 주세요.")
#define STR_MSG_FAIL_LOTID_LENGTH64					_T("Lot ID는 64자까지 지원합니다.")
#define STR_MSG_CONTINUE_STARTACTION				_T("검사 시작 작업을 진행하고 있습니다. 완료 후 진행하여 주시기 바랍니다.")
#define STR_MSG_CONTINUE_STOPACTION					_T("검사 멈춤 작업을 진행하고 있습니다. 완료 후 진행하여 주시기 바랍니다.")

#define STR_MSG_ELOAD_INSPECTION					_T("잘못된 파일입니다. 파일 내용을 확인해 주세요.")
#define STR_MSG_ELOAD_FIRSTINSPECTION				_T("두번째 카메라용 설정파일입니다. 다른 파일을 선택해 주세요.")
#define STR_MSG_CHANGE_LOTID						_T("Lot Id를 변경하면, 데이터가 초기화됩니다. 계속하시겠습니까?")

#define STR_MSG_CHANGE_BRIGHTNESS					_T("조명 밝기를 변경하시겠습니까?")
#define STR_MSG_EVALUE_BRIGHTNESS					_T("입력할 수 없는 밝기 설정입니다.")
#define STR_MSG_EREAD_BRIGHTNESS					_T("조명 밝기를 읽어올 수 없습니다. 조명 장치를 확인해 주세요.")
#define STR_MSG_EWRITE_BRIGHTNESS					_T("조명 밝기를 설정할 수 없습니다. 조명 장치를 확인해 주세요.")
#define STR_MSG_MATCH_BRIGHTNESS					_T("지원가능한 조명밝기로 조정합니다.")

#define STR_MSG_SIZE_ELOG							_T("치수 측정 결과를 로그로 남길 수 없습니다.")
#define STR_MSG_CHAR_LENGTH							_T("입력 가능한 문자 개수를 확인해주세요.")
#define STR_MSG_SAMENAME							_T("동일한 이름")

#define STR_MSG_CAMERA_SELECT_FIRST					_T("퍼스트 검사 설정파일을 선택해주세요.")
#define STR_MSG_CAMERA_SELECT_SECOND				_T("세컨드 검사 설정파일을 선택해주세요.")





#define STR_MSG_SCENARIO							_T("동작 시나리오")	//_T("SCENARIO")

#define STR_MSG_FIRSTCAMERA							_T("퍼스트 검사")		//_T("FIRST CAMERA")
#define STR_MSG_SECONDCAMERA						_T("세컨드 검사")		//_T("SECOND CAMERA")
// Version 1.3.6.9
#define STR_MSG_SHAPETOSIZE							_T("치수 불량 처리")		
#define STR_MSG_LINE_TYPE							_T("LINE NUMBER")
#define STR_MSG_LINE_CONF							_T("라인 설정")

#define STR_MSG_NOTREADY							_T("NOT READY")
#define STR_MSG_READY								_T("READY")
#define STR_MSG_STANDBY								_T("INPUT STANDBY")


#define STR_MSG_SERIALPORT							_T("SERIAL PORT")
#define STR_MSG_SERIALSPEED							_T("SPEED")
#define STR_MSG_STROBETEST							_T("STROBE ON/OFF")
#define STR_MSG_STROBEBRIGHTNESS					_T("BRIGHTNESS")

#ifdef USE_PLC_MXCOMPONENT
#define STR_MSG_COMMUNICATEPORT						_T("PLC설정 (장비)")
#else
#define STR_MSG_COMMUNICATEPORT						_T("통신설정 (장비)")
#endif

#define STR_MSG_RESULTIP							_T("IP")
#ifdef USE_PLC_MXCOMPONENT
#define STR_MSG_RESULTPORT							_T("STATION NUMBER")
#else
#define STR_MSG_RESULTPORT							_T("PORT")
#endif
#define STR_MSG_RESULTPROTOCOL						_T("PROTOCOL")
#define STR_MSG_RESULTTYPE							_T("TYPE")


#define STR_PROTOCOL_TCP							_T("TCP")
#define STR_PROTOCOL_UDP							_T("UDP")

#define STR_TYPE_CLIENT								_T("CLIENT")
#define STR_TYPE_SERVER								_T("SERVER")

#define STR_BTN_START								_T("START")
#define STR_BTN_STOP								_T("STOP")


#define STR_IMG_JPG									_T("JPG")
#define STR_IMG_PNG									_T("PNG")
#define STR_IMG_BMP									_T("BMP")


#define STR_CAMERA_NONE								_T("NONE")

#define STR_MSG_SEQUENCE_STEP01						_T("치수")
#define STR_MSG_SEQUENCE_STEP02						_T("얼룩")
#define STR_MSG_SEQUENCE_STEP03						_T("이물")
#define STR_MSG_SEQUENCE_STEP04						_T("기포")
#define STR_MSG_SEQUENCE_STEP05						_T("긁힘")
#define STR_MSG_SEQUENCE_STEP06						_T("찍힘")

#define STR_STROBE_OFF								_T("OFF")
#define STR_STROBE_COAXIAL							_T("COAXIAL")
#define STR_STROBE_RING								_T("RING")
#define STR_STROBE_BAR								_T("BAR")


#define STR_MAINVIEW_SUMMARY						_T("메인")
#define STR_MAINVIEW_SIZE							_T("치수")
#define STR_MAINVIEW_SCENARIO						_T("외관")
//#define STR_MAINVIEW_COUNT							_T("카운트")
#define STR_MAINVIEW_COUNT							_T("모니터링")

#define STR_MAINVIEW_LINE_1							_T("LINE 1")
#define STR_MAINVIEW_LINE_2							_T("LINE 2")

#define STR_MAINVIEW_BTN_ALARAM						_T("알람")
#define STR_MAINVIEW_BTN_SIZE						_T("치수 (테스트)")

#define STR_MAINVIEW_BTN_SIZE_FIRST					_T("치수 (퍼스트)")
#define STR_MAINVIEW_BTN_SIZE_SECOND				_T("치수 (세컨드)")

#define STR_MAINVIEW_BTN_EXTRACT					_T("시료추출")
#define STR_MAINVIEW_BTN_INSPECTION					_T("검사 (카메라별)")

#define STR_TAPVIEW_SAMPLEA							_T("퍼스트")
#define STR_TAPVIEW_SAMPLEB							_T("세컨드")

#define STR_TAPVIEW_SAMPLE_FIRST					_T("퍼스트")
#define STR_TAPVIEW_SAMPLE_SECOND					_T("세컨드")
#define STR_TAPVIEW_SAMPLE_COUNT					_T("개수")

#define STR_TAPVIEW_MEASURE_SAMPLEA					_T("측정값 퍼스트")
#define STR_TAPVIEW_MEASURE_SAMPLEB					_T("측정값 세컨드")
#define STR_TAPVIEW_MEASURE_AB						_T("A-B 측정편차")


#define STR_SIZEMEASURE_01							_T("d")
#define STR_SIZEMEASURE_02							_T("L")
#define STR_SIZEMEASURE_03							_T("W")
#define STR_SIZEMEASURE_04							_T("I1")
#define STR_SIZEMEASURE_05							_T("I2")
#define STR_SIZEMEASURE_06							_T("I3")
#define STR_SIZEMEASURE_07							_T("M1")
#define STR_SIZEMEASURE_08							_T("M2")
#define STR_SIZEMEASURE_09							_T("S1")
#define STR_SIZEMEASURE_10							_T("S2")
#define STR_SIZEMEASURE_11							_T("S3")
#define STR_SIZEMEASURE_12							_T("S4")
#define STR_SIZEMEASURE_13							_T("S5")
#define STR_SIZEMEASURE_14							_T("X1")
#define STR_SIZEMEASURE_15							_T("X2")
// Version 1.3.7.5 R1 ~ R6, SS1 ~ SS3
#define STR_SIZEMEASURE_16							_T("R1")
#define STR_SIZEMEASURE_17							_T("R2")
#define STR_SIZEMEASURE_18							_T("R3")
#define STR_SIZEMEASURE_19							_T("R4")
#define STR_SIZEMEASURE_20							_T("R5")
#define STR_SIZEMEASURE_21							_T("R6")
#define STR_SIZEMEASURE_22							_T("SS1")
#define STR_SIZEMEASURE_23							_T("SS2")
#define STR_SIZEMEASURE_24							_T("SS3")
#define STR_SIZEMEASURE_25							_T("X1-X2")
#define STR_SIZEMEASURE_26							_T("S1-S3")
#define STR_SIZEMEASURE_27							_T("M1-M2")
#define STR_SIZEMEASURE_28							_T("SS1-SS3")
// Version 1.3.8.0 Resin Count Add (First)

#define STR_SIZEVALID_S								_T("S")
#define STR_SIZEVALID_D								_T("d")

#define STR_SIZEMEASURE_COL_TITLE					_T("")
#define STR_SIZEMEASURE_COL_LSL						_T("LSL")
#define STR_SIZEMEASURE_COL_USL						_T("USL")
#define STR_SIZEMEASURE_COL_MEASURE					_T("측정치")
#define STR_SIZEMEASURE_COL_RESULT					_T("판정")
#define STR_SIZEMEASURE_COL_RESULTAB				_T("편차")

#define STR_TAPVIEW_SUMMARY_SAMPLE_COUNT			_T("카운트")
#define STR_TAPVIEW_SUMMARY_SAMPLE_TOTAL			_T("전체")
#define STR_TAPVIEW_SUMMARY_SAMPLEA					_T("퍼스트")
#define STR_TAPVIEW_SUMMARY_SAMPLEB					_T("세컨드")

#define STR_TAPVIEW_SUMMARY_SAMPLE_FIRST			_T("퍼스트")
#define STR_TAPVIEW_SUMMARY_SAMPLE_SECOND			_T("세컨드")

#define STR_TAPVIEW_SUMMARY_ERRORSHAPE_SAMPLEA		_T("외관 불량 항목 (퍼스트 누적수량)")
#define STR_TAPVIEW_SUMMARY_ERRORSHAPE_SAMPLEB		_T("외관 불량 항목 (세컨드 누적수량)")

#define STR_TAPVIEW_SUMMARY_ERRORSIZE_SAMPLEA		_T("치수 불량 항목 (퍼스트 누적수량)")
#define STR_TAPVIEW_SUMMARY_ERRORSIZE_SAMPLEB		_T("치수 불량 항목 (세컨드 누적수량)")

#define STR_TAPVIEW_SUMMARY_ERRORSHAPE_SAMPLE_FIRST		_T("외관 불량 항목 (퍼스트 누적수량)")
#define STR_TAPVIEW_SUMMARY_ERRORSHAPE_SAMPLE_SECOND	_T("외관 불량 항목 (세컨드 누적수량)")

#define STR_TAPVIEW_SUMMARY_ERRORSIZE_SAMPLE_FIRST	_T("치수 불량 항목 (퍼스트 누적수량)")
#define STR_TAPVIEW_SUMMARY_ERRORSIZE_SAMPLE_SECOND	_T("치수 불량 항목 (세컨드 누적수량)")
#define STR_SUMMARY_COL_COUNT						_T("수량")
#define STR_SUMMARY_COL_ERRORRATIO					_T("불량율(%)")
#define STR_SUMMARY_COL_ETC							_T("기타")

#define STR_SUMMARY_ROW_TOTAL						_T("진행수량")
#define STR_SUMMARY_ROW_ERRORSIZE					_T("치수불량")
#define STR_SUMMARY_ROW_ERRORSHAPE					_T("외관불량")

#define STR_SUMMARY_BTN_LOTID						_T("Lot ID")
#define STR_SUMMARY_BTN_CLEAR_QUEUE					_T("시료 추출")

#define STR_OPT_CAPTURE								_T("촬영")
#define STR_OPT_CAPTURE_DELAY						_T("촬영 지연")

#define STR_OPT_ARARM_SAMPLEA						_T("퍼스트 알람")
#define STR_OPT_ARARM_SAMPLEB						_T("세컨드 알람")
#define STR_OPT_ARARM_SIZERANGE						_T("치수 범위 (퍼스트)")
#define STR_OPT_ARARM_SIZERANGE_SECOND				_T("치수 범위 (세컨드)")
#define STR_OPT_ARARM_SIZESPEC						_T("내부 Spec")

#define STR_OPT_ARARM_MINCOUNT						_T("최소 진행 수량")
#define STR_OPT_ARARM_ERRORRATIO					_T("불량율(%)")

#define STR_OPT_STEP_ENABLE							_T("검사 활성화 설정")
#define STR_OPT_STEP_TITLE							_T("검사 명칭 설정")
#define STR_OPT_SIZE_NAME							_T("치수 명칭 설정")

#define STR_SUMMARY_LOG_ERRORSIZE_COUNT				_T("치수불량수량")
#define STR_SUMMARY_LOG_ERRORSIZE_RATIO				_T("치수불량율(%)")

#define STR_SUMMARY_LOG_ERRORSHAPE_COUNT			_T("외관불량수량")
#define STR_SUMMARY_LOG_ERRORSHAPERATIO				_T("외관불량율(%)")

#define STR_SUMMARY_LOG_ERRORSIZE					_T("치수 판정")
#define STR_SUMMARY_LOG_ERRORSHAPE					_T("외관 판정")


// CAMERA
#define STR_CAMERALIST								_T("CAMERA LIST")

#define STR_CAMERAINF_GIGE							_T("INTERFACE - GIGE")
#define STR_CAMERAINF_USB							_T("INTERFACE - USB")
#define STR_CAMERA_GIGE								_T("GIGE CAMERA")
#define STR_CAMERA_USB								_T("USB CAMERA")

#define STR_CAMERA_SELECTCAMERA						_T("SELECT CAMERA")
#define STR_CAMERA_NOTSELECT						_T("NOT SELECT")

#define STR_CAMERA_CONNECTED						_T("카메라 정보를 재구성합니다. 잠시만 기다려주세요.")
#define STR_CAMERA_DISCONNECTED						_T("카메라와의 연결을 해제합니다. 잠시만 기다려주세요.")
#define STR_CAMERA_FREERUN							_T("카메라 설정을 변경합니다. 잠시만 기다려주세요.")

#define STR_INSPECTION_READYSTATE					_T("검사를 위한 환경 구성 작업을 진행하고 있습니다. 잠시만 기다려주세요.")

