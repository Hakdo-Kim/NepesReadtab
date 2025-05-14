#pragma once

#define STR_MSG_CAPTION								_T("CAPTURE")
#define STR_MSG_CLOSE								_T("���α׷��� �����մϴ�.")
#define STR_MSG_WRONGPASSWD							_T("�߸��� �Է��Դϴ�.")

#define STR_MSG_CAPTUREMODE							_T("�������� Capture ������ ����, Freerun ������ �����ϰų� Trigger ������ ������ �ּ���.\r\n(Camera: Snap-Freerun)")
#define STR_MSG_TRIGGERMODE							_T("�������� Capture ������ ����, Trigger ������ �����մϴ�.\r\n(Camera: Snap-Freerun)")

#define STR_MSG_DIRLOCATION							_T("������ ������ ��ġ�� Ȯ���� �ּ���.")

#define STR_MSG_ERROR_SERIAL						_T("Serial Device�� ����� �� �����ϴ�. COM port�� Ȯ���� �ּ���")
#ifdef USE_PLC_MXCOMPONENT
#define STR_MSG_ERROR_PLCMXCOMPONENT				_T("PLC Device�� ����� �� �����ϴ�. ���� ������ Ȯ���� �ּ���")
#endif
#define STR_MSG_ERROR_ETHERNET						_T("Ethernet Device�� ����� �� �����ϴ�. ���� ������ Ȯ���� �ּ���")
#define STR_MSG_ERROR_STROBE						_T("������� �����߽��ϴ�. ��ġ�� Ȯ���� �ּ���")

#define STR_MSG_ECONNECT_CAMERA						_T("Camera ������ �Ϸ���� �ʾҽ��ϴ�. ������ Ȯ���� �ּ���.")
#define STR_MSG_ECONNECT_STROBE						_T("���� ������ �Ϸ���� �ʾҽ��ϴ�. ������ Ȯ���� �ּ���.")
#ifdef USE_PLC_MXCOMPONENT
#define STR_MSG_ECONNECT_PLCMXCOMPONENT				_T("PLC ����� ��� ������ �Ϸ���� �ʾҽ��ϴ�. ������ Ȯ���� �ּ���.")
#endif
#define STR_MSG_ECONNECT_COMMUNICATE				_T("����� ��� ������ �Ϸ���� �ʾҽ��ϴ�. ������ Ȯ���� �ּ���.")

#define STR_MSG_EINIT_LIBRARY						_T("�˻� ���̺귯�� �ʱ�ȭ�� �����Ͽ����ϴ�.")
#define STR_MSG_ELOAD_IMAGE							_T("�˻�� �̹����� �����ϴ�.")

#define STR_MSG_ESTART_INSPECTION					_T("�˻縦 ������ �� �����ϴ�.")

#define STR_MSG_FAIL_INSPECTION						_T("�˻� �����Ͽ����ϴ�.")
#define STR_MSG_FAIL_SAVE_OPTION					_T("����� �ɼ������� ���Ϸ� �������� ���߽��ϴ�.")
#define STR_MSG_DEFECT_DETECTED						_T("������ �ʰ��ϴ� ������ ����Ǿ����ϴ�.")

#define STR_MSG_FAIL_LOTID							_T("Lot ID �Է��� Ȯ�����ּ���. (����ȭ��)")
#define STR_MSG_FAIL_INPUT_LOTID					_T("�Էµ� Lot ID�� �ٽ� Ȯ���� �ּ���.")
#define STR_MSG_FAIL_LOTID_LENGTH64					_T("Lot ID�� 64�ڱ��� �����մϴ�.")
#define STR_MSG_CONTINUE_STARTACTION				_T("�˻� ���� �۾��� �����ϰ� �ֽ��ϴ�. �Ϸ� �� �����Ͽ� �ֽñ� �ٶ��ϴ�.")
#define STR_MSG_CONTINUE_STOPACTION					_T("�˻� ���� �۾��� �����ϰ� �ֽ��ϴ�. �Ϸ� �� �����Ͽ� �ֽñ� �ٶ��ϴ�.")

#define STR_MSG_ELOAD_INSPECTION					_T("�߸��� �����Դϴ�. ���� ������ Ȯ���� �ּ���.")
#define STR_MSG_ELOAD_FIRSTINSPECTION				_T("�ι�° ī�޶�� ���������Դϴ�. �ٸ� ������ ������ �ּ���.")
#define STR_MSG_CHANGE_LOTID						_T("Lot Id�� �����ϸ�, �����Ͱ� �ʱ�ȭ�˴ϴ�. ����Ͻðڽ��ϱ�?")

#define STR_MSG_CHANGE_BRIGHTNESS					_T("���� ��⸦ �����Ͻðڽ��ϱ�?")
#define STR_MSG_EVALUE_BRIGHTNESS					_T("�Է��� �� ���� ��� �����Դϴ�.")
#define STR_MSG_EREAD_BRIGHTNESS					_T("���� ��⸦ �о�� �� �����ϴ�. ���� ��ġ�� Ȯ���� �ּ���.")
#define STR_MSG_EWRITE_BRIGHTNESS					_T("���� ��⸦ ������ �� �����ϴ�. ���� ��ġ�� Ȯ���� �ּ���.")
#define STR_MSG_MATCH_BRIGHTNESS					_T("���������� ������� �����մϴ�.")

#define STR_MSG_SIZE_ELOG							_T("ġ�� ���� ����� �α׷� ���� �� �����ϴ�.")
#define STR_MSG_CHAR_LENGTH							_T("�Է� ������ ���� ������ Ȯ�����ּ���.")
#define STR_MSG_SAMENAME							_T("������ �̸�")

#define STR_MSG_CAMERA_SELECT_FIRST					_T("�۽�Ʈ �˻� ���������� �������ּ���.")
#define STR_MSG_CAMERA_SELECT_SECOND				_T("������ �˻� ���������� �������ּ���.")





#define STR_MSG_SCENARIO							_T("���� �ó�����")	//_T("SCENARIO")

#define STR_MSG_FIRSTCAMERA							_T("�۽�Ʈ �˻�")		//_T("FIRST CAMERA")
#define STR_MSG_SECONDCAMERA						_T("������ �˻�")		//_T("SECOND CAMERA")
// Version 1.3.6.9
#define STR_MSG_SHAPETOSIZE							_T("ġ�� �ҷ� ó��")		
#define STR_MSG_LINE_TYPE							_T("LINE NUMBER")
#define STR_MSG_LINE_CONF							_T("���� ����")

#define STR_MSG_NOTREADY							_T("NOT READY")
#define STR_MSG_READY								_T("READY")
#define STR_MSG_STANDBY								_T("INPUT STANDBY")


#define STR_MSG_SERIALPORT							_T("SERIAL PORT")
#define STR_MSG_SERIALSPEED							_T("SPEED")
#define STR_MSG_STROBETEST							_T("STROBE ON/OFF")
#define STR_MSG_STROBEBRIGHTNESS					_T("BRIGHTNESS")

#ifdef USE_PLC_MXCOMPONENT
#define STR_MSG_COMMUNICATEPORT						_T("PLC���� (���)")
#else
#define STR_MSG_COMMUNICATEPORT						_T("��ż��� (���)")
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

#define STR_MSG_SEQUENCE_STEP01						_T("ġ��")
#define STR_MSG_SEQUENCE_STEP02						_T("���")
#define STR_MSG_SEQUENCE_STEP03						_T("�̹�")
#define STR_MSG_SEQUENCE_STEP04						_T("����")
#define STR_MSG_SEQUENCE_STEP05						_T("����")
#define STR_MSG_SEQUENCE_STEP06						_T("����")

#define STR_STROBE_OFF								_T("OFF")
#define STR_STROBE_COAXIAL							_T("COAXIAL")
#define STR_STROBE_RING								_T("RING")
#define STR_STROBE_BAR								_T("BAR")


#define STR_MAINVIEW_SUMMARY						_T("����")
#define STR_MAINVIEW_SIZE							_T("ġ��")
#define STR_MAINVIEW_SCENARIO						_T("�ܰ�")
//#define STR_MAINVIEW_COUNT							_T("ī��Ʈ")
#define STR_MAINVIEW_COUNT							_T("����͸�")

#define STR_MAINVIEW_LINE_1							_T("LINE 1")
#define STR_MAINVIEW_LINE_2							_T("LINE 2")

#define STR_MAINVIEW_BTN_ALARAM						_T("�˶�")
#define STR_MAINVIEW_BTN_SIZE						_T("ġ�� (�׽�Ʈ)")

#define STR_MAINVIEW_BTN_SIZE_FIRST					_T("ġ�� (�۽�Ʈ)")
#define STR_MAINVIEW_BTN_SIZE_SECOND				_T("ġ�� (������)")

#define STR_MAINVIEW_BTN_EXTRACT					_T("�÷�����")
#define STR_MAINVIEW_BTN_INSPECTION					_T("�˻� (ī�޶�)")

#define STR_TAPVIEW_SAMPLEA							_T("�۽�Ʈ")
#define STR_TAPVIEW_SAMPLEB							_T("������")

#define STR_TAPVIEW_SAMPLE_FIRST					_T("�۽�Ʈ")
#define STR_TAPVIEW_SAMPLE_SECOND					_T("������")
#define STR_TAPVIEW_SAMPLE_COUNT					_T("����")

#define STR_TAPVIEW_MEASURE_SAMPLEA					_T("������ �۽�Ʈ")
#define STR_TAPVIEW_MEASURE_SAMPLEB					_T("������ ������")
#define STR_TAPVIEW_MEASURE_AB						_T("A-B ��������")


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
#define STR_SIZEMEASURE_COL_MEASURE					_T("����ġ")
#define STR_SIZEMEASURE_COL_RESULT					_T("����")
#define STR_SIZEMEASURE_COL_RESULTAB				_T("����")

#define STR_TAPVIEW_SUMMARY_SAMPLE_COUNT			_T("ī��Ʈ")
#define STR_TAPVIEW_SUMMARY_SAMPLE_TOTAL			_T("��ü")
#define STR_TAPVIEW_SUMMARY_SAMPLEA					_T("�۽�Ʈ")
#define STR_TAPVIEW_SUMMARY_SAMPLEB					_T("������")

#define STR_TAPVIEW_SUMMARY_SAMPLE_FIRST			_T("�۽�Ʈ")
#define STR_TAPVIEW_SUMMARY_SAMPLE_SECOND			_T("������")

#define STR_TAPVIEW_SUMMARY_ERRORSHAPE_SAMPLEA		_T("�ܰ� �ҷ� �׸� (�۽�Ʈ ��������)")
#define STR_TAPVIEW_SUMMARY_ERRORSHAPE_SAMPLEB		_T("�ܰ� �ҷ� �׸� (������ ��������)")

#define STR_TAPVIEW_SUMMARY_ERRORSIZE_SAMPLEA		_T("ġ�� �ҷ� �׸� (�۽�Ʈ ��������)")
#define STR_TAPVIEW_SUMMARY_ERRORSIZE_SAMPLEB		_T("ġ�� �ҷ� �׸� (������ ��������)")

#define STR_TAPVIEW_SUMMARY_ERRORSHAPE_SAMPLE_FIRST		_T("�ܰ� �ҷ� �׸� (�۽�Ʈ ��������)")
#define STR_TAPVIEW_SUMMARY_ERRORSHAPE_SAMPLE_SECOND	_T("�ܰ� �ҷ� �׸� (������ ��������)")

#define STR_TAPVIEW_SUMMARY_ERRORSIZE_SAMPLE_FIRST	_T("ġ�� �ҷ� �׸� (�۽�Ʈ ��������)")
#define STR_TAPVIEW_SUMMARY_ERRORSIZE_SAMPLE_SECOND	_T("ġ�� �ҷ� �׸� (������ ��������)")
#define STR_SUMMARY_COL_COUNT						_T("����")
#define STR_SUMMARY_COL_ERRORRATIO					_T("�ҷ���(%)")
#define STR_SUMMARY_COL_ETC							_T("��Ÿ")

#define STR_SUMMARY_ROW_TOTAL						_T("�������")
#define STR_SUMMARY_ROW_ERRORSIZE					_T("ġ���ҷ�")
#define STR_SUMMARY_ROW_ERRORSHAPE					_T("�ܰ��ҷ�")

#define STR_SUMMARY_BTN_LOTID						_T("Lot ID")
#define STR_SUMMARY_BTN_CLEAR_QUEUE					_T("�÷� ����")

#define STR_OPT_CAPTURE								_T("�Կ�")
#define STR_OPT_CAPTURE_DELAY						_T("�Կ� ����")

#define STR_OPT_ARARM_SAMPLEA						_T("�۽�Ʈ �˶�")
#define STR_OPT_ARARM_SAMPLEB						_T("������ �˶�")
#define STR_OPT_ARARM_SIZERANGE						_T("ġ�� ���� (�۽�Ʈ)")
#define STR_OPT_ARARM_SIZERANGE_SECOND				_T("ġ�� ���� (������)")
#define STR_OPT_ARARM_SIZESPEC						_T("���� Spec")

#define STR_OPT_ARARM_MINCOUNT						_T("�ּ� ���� ����")
#define STR_OPT_ARARM_ERRORRATIO					_T("�ҷ���(%)")

#define STR_OPT_STEP_ENABLE							_T("�˻� Ȱ��ȭ ����")
#define STR_OPT_STEP_TITLE							_T("�˻� ��Ī ����")
#define STR_OPT_SIZE_NAME							_T("ġ�� ��Ī ����")

#define STR_SUMMARY_LOG_ERRORSIZE_COUNT				_T("ġ���ҷ�����")
#define STR_SUMMARY_LOG_ERRORSIZE_RATIO				_T("ġ���ҷ���(%)")

#define STR_SUMMARY_LOG_ERRORSHAPE_COUNT			_T("�ܰ��ҷ�����")
#define STR_SUMMARY_LOG_ERRORSHAPERATIO				_T("�ܰ��ҷ���(%)")

#define STR_SUMMARY_LOG_ERRORSIZE					_T("ġ�� ����")
#define STR_SUMMARY_LOG_ERRORSHAPE					_T("�ܰ� ����")


// CAMERA
#define STR_CAMERALIST								_T("CAMERA LIST")

#define STR_CAMERAINF_GIGE							_T("INTERFACE - GIGE")
#define STR_CAMERAINF_USB							_T("INTERFACE - USB")
#define STR_CAMERA_GIGE								_T("GIGE CAMERA")
#define STR_CAMERA_USB								_T("USB CAMERA")

#define STR_CAMERA_SELECTCAMERA						_T("SELECT CAMERA")
#define STR_CAMERA_NOTSELECT						_T("NOT SELECT")

#define STR_CAMERA_CONNECTED						_T("ī�޶� ������ �籸���մϴ�. ��ø� ��ٷ��ּ���.")
#define STR_CAMERA_DISCONNECTED						_T("ī�޶���� ������ �����մϴ�. ��ø� ��ٷ��ּ���.")
#define STR_CAMERA_FREERUN							_T("ī�޶� ������ �����մϴ�. ��ø� ��ٷ��ּ���.")

#define STR_INSPECTION_READYSTATE					_T("�˻縦 ���� ȯ�� ���� �۾��� �����ϰ� �ֽ��ϴ�. ��ø� ��ٷ��ּ���.")

