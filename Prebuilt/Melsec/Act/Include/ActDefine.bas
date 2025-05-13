Global Const DevX = 1


''''CPU TYPE
''' QnACPU
Global Const CPU_Q2ACPU = &H11                                          ' Q2A
Global Const CPU_Q2AS1CPU = &H12                                        ' Q2AS1
Global Const CPU_Q3ACPU = &H13                                          ' Q3A
Global Const CPU_Q4ACPU = &H14                                          ' Q4A
''' QCPU Q
Global Const CPU_Q02CPU = &H22                                          ' Q02(H) Q
Global Const CPU_Q06CPU = &H23                                          ' Q06H   Q
Global Const CPU_Q12CPU = &H24                                          ' Q12H   Q
Global Const CPU_Q25CPU = &H25                                          ' Q25H   Q
Global Const CPU_Q00JCPU = &H30                                         ' Q00J   Q
Global Const CPU_Q00CPU = &H31                                          ' Q00    Q
Global Const CPU_Q01CPU = &H32                                          ' Q01    Q
Global Const CPU_Q12PHCPU = &H41                                        ' Q12PHCPU Q
Global Const CPU_Q25PHCPU = &H42                                        ' Q25PHCPU Q
Global Const CPU_Q12PRHCPU = &H43                                       ' Q12PRHCPU Q
Global Const CPU_Q25PRHCPU = &H44                                       ' Q25PRHCPU Q
Global Const CPU_Q25SSCPU = &H55                                        ' Q25SS
Global Const CPU_Q03UDCPU = &H70                                        ' Q03UD  Q
Global Const CPU_Q04UDHCPU = &H71                                       ' Q04UDH Q
Global Const CPU_Q06UDHCPU = &H72                                       ' Q06UDH Q
Global Const CPU_Q02UCPU = &H83                                         ' Q02U   Q
Global Const CPU_Q03UDECPU = &H90                                       ' Q03UDECPU Q
Global Const CPU_Q04UDEHCPU = &H91                                      ' Q04UDEHCPU Q
Global Const CPU_Q06UDEHCPU = &H92                                      ' Q06UDEHCPU Q
Global Const CPU_Q13UDHCPU = &H73                                       ' Q13UDHCPU Q
Global Const CPU_Q13UDEHCPU = &H93                                      ' Q13UDEHCPU Q
Global Const CPU_Q26UDHCPU = &H74                                       ' Q26UDHCPU Q
Global Const CPU_Q26UDEHCPU = &H94                                      ' Q26UDEHCPU Q
Global Const CPU_Q02PHCPU = &H45                                        ' Q02PH  Q
Global Const CPU_Q06PHCPU = &H46                                        ' Q06PH  Q
Global Const CPU_Q00UJCPU = &H80                                        ' Q00UJCPU
Global Const CPU_Q00UCPU = &H81                                         ' Q00UCPU
Global Const CPU_Q01UCPU = &H82                                         ' Q01UCPU
Global Const CPU_Q10UDHCPU = &H75                                       ' Q10UDHCPU
Global Const CPU_Q20UDHCPU = &H76                                       ' Q20UDHCPU
Global Const CPU_Q10UDEHCPU = &H95                                      ' Q10UDEHCPU
Global Const CPU_Q20UDEHCPU = &H96                                      ' Q20UDEHCPU
Global Const CPU_Q50UDEHCPU = &H98                                      ' Q50UDEHCPU 
Global Const CPU_Q100UDEHCPU = &H9A                                     ' Q100UDEHCPU 

''' ACPU
Global Const CPU_A0J2HCPU = &H102                                       ' A0J2H
Global Const CPU_A1FXCPU = &H103                                        ' A1FX
Global Const CPU_A1SCPU = &H104                                         ' A1S,A1SJ
Global Const CPU_A1SHCPU = &H105                                        ' A1SH,A1SJH
Global Const CPU_A1NCPU = &H106                                         ' A1(N)
Global Const CPU_A2CCPU = &H107                                         ' A2C,A2CJ
Global Const CPU_A2NCPU = &H108                                         ' A2(N),A2S
Global Const CPU_A2SHCPU = &H109                                        ' A2SH
Global Const CPU_A3NCPU = &H10A                                         ' A3(N)
Global Const CPU_A2ACPU = &H10C                                         ' A2A
Global Const CPU_A3ACPU = &H10D                                         ' A3A
Global Const CPU_A2UCPU = &H10E                                         ' A2U,A2US
Global Const CPU_A2USHS1CPU = &H10F                                     ' A2USHS1
Global Const CPU_A3UCPU = &H110                                         ' A3U
Global Const CPU_A4UCPU = &H111                                         ' A4U
''' QCPU A
Global Const CPU_Q02CPU_A = &H141                                       ' Q02(H)
Global Const CPU_Q06CPU_A = &H142                                       ' Q06H
''' LCPU
Global Const CPU_L02CPU = &HA1                                          ' L02CPU
Global Const CPU_L26CPUBT = &HA2                                        ' L26CPU-BT
''' C Controller
Global Const CPU_Q12DC_V = &H58                                         ' Q12DCCPU-V
''' QSCPU
Global Const CPU_QS001CPU = &H60                                        ' QS001
''' FXCPU
Global Const CPU_FX0CPU = &H201                                         ' FX0/FX0S
Global Const CPU_FX0NCPU = &H202                                        ' FX0N
Global Const CPU_FX1CPU = &H203                                         ' FX1
Global Const CPU_FX2CPU = &H204                                         ' FX2/FX2C
Global Const CPU_FX2NCPU = &H205                                        ' FX2N/FX2NC
Global Const CPU_FX1SCPU = &H206                                        ' FX1S
Global Const CPU_FX1NCPU = &H207                                        ' FX1N
Global Const CPU_FX3UCCPU = &H208                                       ' FX3U/FX3UC
Global Const CPU_FX3GCPU = &H209                                        ' FX3GCPU
''' BOARD
Global Const CPU_BOARD = &H401                                          ' NETWORK BOARD
''' MOTION
Global Const CPU_A171SHCPU = &H601                                      ' A171SH
Global Const CPU_A172SHCPU = &H602                                      ' A172SH
Global Const CPU_A273UHCPU = &H603                                      ' A273UH
Global Const CPU_A173UHCPU = &H604                                      ' A173UH
''' GOT
Global Const CPU_A900GOT = &H701                                        ' A900GOT


''' PORT
Global Const PORT_1 = &H1                                               ' CommunicationPort1
Global Const PORT_2 = &H2                                               ' CommunicationPort2
Global Const PORT_3 = &H3                                               ' CommunicationPort3
Global Const PORT_4 = &H4                                               ' CommunicationPort4
Global Const PORT_5 = &H5                                               ' CommunicationPort5
Global Const PORT_6 = &H6                                               ' CommunicationPort6
Global Const PORT_7 = &H7                                               ' CommunicationPort7
Global Const PORT_8 = &H8                                               ' CommunicationPort8
Global Const PORT_9 = &H9                                               ' CommunicationPort9
Global Const PORT_10 = &HA                                              ' CommunicationPort10


''' BAUDRATE
Global Const BAUDRATE_300 = 300                                         ' 300bps
Global Const BAUDRATE_600 = 600                                         ' 600bps
Global Const BAUDRATE_1200 = 1200                                       ' 1200bps
Global Const BAUDRATE_2400 = 2400                                       ' 2400bps
Global Const BAUDRATE_4800 = 4800                                       ' 4800bps
Global Const BAUDRATE_9600 = 9600                                       ' 9600bps
Global Const BAUDRATE_19200 = 19200                                     ' 19200bps
Global Const BAUDRATE_38400 = 38400                                     ' 38400bps
Global Const BAUDRATE_57600 = 57600                                     ' 57600bps
Global Const BAUDRATE_115200 = 115200                                   ' 115200bps


''' DATA BIT
Global Const DATABIT_7 = 7                                              ' DATA BIT 7
Global Const DATABIT_8 = 8                                              ' DATA BIT 8


''' PARITY
Global Const NO_PARRITY = 0                                             ' NO PARITY
Global Const ODD_PARITY = 1                                             ' ODD PARITY
Global Const EVEN_PARITY = 2                                            ' EVEN PARITY


''' STOP BITS
Global Const STOPBIT_ONE = 0                                            ' 1 STOP BIT
Global Const STOPBIT_TWO = 2                                            ' 2 STOP BIT


''' SERIAL CONTROL
Global Const TRC_DTR = &H1                                              ' DTR
Global Const TRC_RTS = &H2                                              ' RTS
Global Const TRC_DTR_AND_RTS = &H7                                      ' DTR and RTS
Global Const TRC_DTR_OR_RTS = &H8                                       ' DTR or RTS


''' SUM CHECK
Global Const SUM_CHECK = 1                                              ' Sum Check
Global Const NO_SUM_CHECK = 0                                           ' No Sum Check]

''' PACKET TYPE
Global Const PACKET_ASCII = &H2                                         ' PACKET TYPE ASCII
Global Const PACKET_BINARY = &H3                                        ' PACKET TYPE BINARY

''' CONNECT WAY
Global Const TEL_AUTO_CONNECT = &H0                                     ' AUTO LINE CONNECT
Global Const TEL_AUTO_CALLBACK = &H1                                    ' AUTO LINE CONNECT(CALLBACK FIXATION)
Global Const TEL_AUTO_CALLBACK_NUMBER = &H2                             ' AUTO LINE CONNECT(CALLBACK NUMBER SPECIFICATION)
Global Const TEL_CALLBACK = &H3                                         ' CALLBACK CONNECT(FIXATION)
Global Const TEL_CALLBACK_NUMBER = &H4                                  ' CALLBACK CONNECT(NUMBER SPECIFICATION)
Global Const TEL_CALLBACK_REQUEST = &H5                                 ' CALLBACK REQUEST(FIXATION)
Global Const TEL_CALLBACK_REQUEST_NUMBER = &H6                          ' CALLBACK REQUEST(NUMBER SPECIFICATION)
Global Const TEL_CALLBACK_WAIT = &H7                                    ' CALLBACK RECEPTION WAITING

''' LINE TYPE
Global Const LINETYPE_PULSE = &H0                                       ' PULSE
Global Const LINETYPE_TONE = &H1                                        ' TONE
Global Const LINETYPE_ISDN = &H2                                        ' ISDN

''' GOT TRANSPARENT PC IF
Global Const GOT_PCIF_USB = 1                                           ' USB
Global Const GOT_PCIF_SERIAL = 2                                        ' SERIAL
Global Const GOT_PCIF_ETHERNET = 3                                      ' ETHERNET

''' GOT TRANSPARENT PLC IF
Global Const GOT_PLCIF_SERIAL_QCPUQ = 1                                 ' SERIAL-QCPU Q
Global Const GOT_PLCIF_SERIAL_QCPUA = 2                                 ' SERIAL-QCPU A
Global Const GOT_PLCIF_SERIAL_QNACPU = 3                                ' SERIAL-QnACPU
Global Const GOT_PLCIF_SERIAL_ACPU = 4                                  ' SERIAL-ACPU
Global Const GOT_PLCIF_SERIAL_FXCPU = 5                                 ' SERIAL-FXCPU
Global Const GOT_PLCIF_SERIAL_LCPU = 6                                  ' SERIAL-LCPU
Global Const GOT_PLCIF_SERIAL_QJ71C24 = 30                              ' SERIAL-QJ71C24
Global Const GOT_PLCIF_SERIAL_LJ71C24 = 31                              ' SERIAL-LJ71C24
Global Const GOT_PLCIF_ETHERNET_QJ71E71 = 50                            ' ETHERNET-QJ71E71
Global Const GOT_PLCIF_ETHERNET_CCIEFADP = 60                           ' ETHERNET-CC IE Field adapter
Global Const GOT_PLCIF_ETHERNET_QCPU = 70                               ' ETHERNET-QCPU
Global Const GOT_PLCIF_ETHERNET_LCPU = 71                               ' ETHERNET-LCPU
Global Const GOT_PLCIF_BUS = 90                                         ' BUS
