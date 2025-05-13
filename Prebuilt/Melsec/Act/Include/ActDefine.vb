Option Strict Off
Option Explicit On 

Module ActDefine

    Public Const DevX As Short = 1

    ''''CPU TYPE
    ''' QnACPU
    Public Const CPU_Q2ACPU As Short = &H11S ' Q2A
    Public Const CPU_Q2AS1CPU As Short = &H12S ' Q2AS1
    Public Const CPU_Q3ACPU As Short = &H13S ' Q3A
    Public Const CPU_Q4ACPU As Short = &H14S ' Q4A
    ''' QCPU Q
    Public Const CPU_Q02CPU As Short = &H22S ' Q02(H) Q
    Public Const CPU_Q06CPU As Short = &H23S ' Q06H   Q
    Public Const CPU_Q12CPU As Short = &H24S ' Q12H   Q
    Public Const CPU_Q25CPU As Short = &H25S ' Q25H   Q
    Public Const CPU_Q00JCPU As Short = &H30S ' Q00J   Q
    Public Const CPU_Q00CPU As Short = &H31S ' Q00    Q
    Public Const CPU_Q01CPU As Short = &H32S ' Q01    Q
    Public Const CPU_Q12PHCPU As Short = &H41S ' Q12PHCPU Q
    Public Const CPU_Q25PHCPU As Short = &H42S ' Q25PHCPU Q
    Public Const CPU_Q12PRHCPU As Short = &H43S ' Q12PRHCPU Q
    Public Const CPU_Q25PRHCPU As Short = &H44S ' Q25PRHCPU Q
    Public Const CPU_Q25SSCPU As Short = &H55S ' Q25SS
    Public Const CPU_Q03UDCPU As Short = &H70S ' Q03UDCPU  Q
    Public Const CPU_Q04UDHCPU As Short = &H71S ' Q04UDHCPU Q
    Public Const CPU_Q06UDHCPU As Short = &H72S ' Q06UDHCPU Q
    Public Const CPU_Q02UCPU As Short = &H83S ' Q02UCPU   Q
    Public Const CPU_Q03UDECPU As Short = &H90S ' Q03UDECPU   Q
    Public Const CPU_Q04UDEHCPU As Short = &H91S ' Q04UDEHCPU   Q
    Public Const CPU_Q06UDEHCPU As Short = &H92S ' Q06UDEHCPU   Q
    Public Const CPU_Q13UDHCPU As Short = &H73S ' Q13UDHCPU   Q
    Public Const CPU_Q13UDEHCPU As Short = &H93S ' Q13UDEHCPU   Q
    Public Const CPU_Q26UDHCPU As Short = &H74S ' Q26UDHCPU   Q
    Public Const CPU_Q26UDEHCPU As Short = &H94S ' Q26UDEHCPU   Q
    Public Const CPU_Q02PHCPU As Short = &H45S  ' Q02PH  Q
    Public Const CPU_Q06PHCPU As Short = &H46S  ' Q06PH  Q
    Public Const CPU_Q00UJCPU As Short = &H80   ' Q00UJCPU
    Public Const CPU_Q00UCPU As Short = &H81    ' Q00UCPU
    Public Const CPU_Q01UCPU As Short = &H82    ' Q01UCPU
    Public Const CPU_Q10UDHCPU As Short = &H75  ' Q10UDHCPU
    Public Const CPU_Q20UDHCPU As Short = &H76  ' Q20UDHCPU
    Public Const CPU_Q10UDEHCPU As Short = &H95 ' Q10UDEHCPU
    Public Const CPU_Q20UDEHCPU As Short = &H96 ' Q20UDEHCPU
    Public Const CPU_Q50UDEHCPU As Short = &H98 ' Q50UDEHCPU
    Public Const CPU_Q100UDEHCPU As Short = &H9A ' Q100UDEHCPU
    Public Const CPU_Q03UDVCPU As Short = &HD1 ' Q03UDVCPU
    Public Const CPU_Q04UDVCPU As Short = &HD2 ' Q04UDVCPU
    Public Const CPU_Q06UDVCPU As Short = &HD3 ' Q06UDVCPU
    Public Const CPU_Q13UDVCPU As Short = &HD4 ' Q13UDVCPU
    Public Const CPU_Q26UDVCPU As Short = &HD5 ' Q26UDVCPU
    ''' ACPU
    Public Const CPU_A0J2HCPU As Short = &H102S ' A0J2H
    Public Const CPU_A1FXCPU As Short = &H103S ' A1FX
    Public Const CPU_A1SCPU As Short = &H104S ' A1S,A1SJ
    Public Const CPU_A1SHCPU As Short = &H105S ' A1SH,A1SJH
    Public Const CPU_A1NCPU As Short = &H106S ' A1(N)
    Public Const CPU_A2CCPU As Short = &H107S ' A2C,A2CJ
    Public Const CPU_A2NCPU As Short = &H108S ' A2(N),A2S
    Public Const CPU_A2SHCPU As Short = &H109S ' A2SH
    Public Const CPU_A3NCPU As Short = &H10AS ' A3(N)
    Public Const CPU_A2ACPU As Short = &H10CS ' A2A
    Public Const CPU_A3ACPU As Short = &H10DS ' A3A
    Public Const CPU_A2UCPU As Short = &H10ES ' A2U,A2US
    Public Const CPU_A2USHS1CPU As Short = &H10FS ' A2USHS1
    Public Const CPU_A3UCPU As Short = &H110S ' A3U
    Public Const CPU_A4UCPU As Short = &H111S ' A4U
    ''' QCPU A
    Public Const CPU_Q02CPU_A As Short = &H141S ' Q02(H)
    Public Const CPU_Q06CPU_A As Short = &H142S ' Q06H
    ''' LCPU
    Public Const CPU_L02CPU As Short = &HA1S   ' L02CPU
    Public Const CPU_L26CPUBT As Short = &HA2S ' L26CPU-BT
    Public Const CPU_L02SCPU As Short = &HA3S  ' L02SCPU
    Public Const CPU_L26CPU As Short = &HA4S   ' L26CPU
    Public Const CPU_L06CPU As Short = &HA5S   ' L06CPU
    ''' C Controller
    Public Const CPU_Q12DC_V As Short = &H58S   ' Q12DCCPU-V
    Public Const CPU_Q24DHC_V As Short = &H59S  ' Q24DHCCPU-V
    Public Const CPU_Q24DHC_VG As Short = &H5CS ' Q24DHCCPU-VG
    Public Const CPU_Q26DHC_LS As Short = &H5DS ' Q26DHCCPU-LS 
    ''' Q MOTION 	
    Public Const CPU_Q172CPU As Short = &H621S      ' Q172CPU
    Public Const CPU_Q173CPU As Short = &H622S      ' Q173CPU
    Public Const CPU_Q172HCPU As Short = &H621S     ' Q172HCPU
    Public Const CPU_Q173HCPU As Short = &H622S     ' Q173HCPU
    Public Const CPU_Q172DCPU As Short = &H625S     ' Q172DCPU
    Public Const CPU_Q173DCPU As Short = &H626S     ' Q173DCPU
    Public Const CPU_Q172DSCPU As Short = &H62AS    ' Q172DSCPU
    Public Const CPU_Q173DSCPU As Short = &H62BS    ' Q173DSCPU
    ''' QSCPU
    Public Const CPU_QS001CPU As Short = &H60S ' QS001
    ''' FXCPU
    Public Const CPU_FX0CPU As Short = &H201S ' FX0/FX0S
    Public Const CPU_FX0NCPU As Short = &H202S ' FX0N
    Public Const CPU_FX1CPU As Short = &H203S ' FX1
    Public Const CPU_FX2CPU As Short = &H204S ' FX2/FX2C
    Public Const CPU_FX2NCPU As Short = &H205S ' FX2N/FX2NC
    Public Const CPU_FX1SCPU As Short = &H206S ' FX1S
    Public Const CPU_FX1NCPU As Short = &H207S ' FX1N/FX1NC
    Public Const CPU_FX3UCCPU As Short = &H208S ' FX3U/FX3UC
    Public Const CPU_FX3GCPU As Short = &H209   ' FX3G/FX3GC
    ''' BOARD
    Public Const CPU_BOARD As Short = &H401S ' NETWORK BOARD
    ''' MOTION
    Public Const CPU_A171SHCPU As Short = &H601S ' A171SH
    Public Const CPU_A172SHCPU As Short = &H602S ' A172SH
    Public Const CPU_A273UHCPU As Short = &H603S ' A273UH
    Public Const CPU_A173UHCPU As Short = &H604S ' A173UH
    ''' GOT
    Public Const CPU_A900GOT As Short = &H701S ' A900GOT

    ''' iQ-R CPU
    Public Const CPU_R04CPU As Short = &H1001S ' R04CPU
    Public Const CPU_R08CPU As Short = &H1002S ' R08CPU
    Public Const CPU_R16CPU As Short = &H1003S ' R16CPU
    Public Const CPU_R32CPU As Short = &H1004S ' R32CPU
    Public Const CPU_R120CPU As Short = &H1005S ' R120CPU

    ''' iQ-R PROCESS CPU
    Public Const CPU_R08PCPU As Short = &H1102S ' R08PCPU
    Public Const CPU_R16PCPU As Short = &H1103S ' R16PCPU
    Public Const CPU_R32PCPU As Short = &H1104S ' R32PCPU
    Public Const CPU_R120PCPU As Short = &H1105S ' R120PCPU

    ''' iQ-R SAFE CPU
    Public Const CPU_R08SFCPU As Short = &H1122S ' R08SFCPU
    Public Const CPU_R16SFCPU As Short = &H1123S ' R16SFCPU
    Public Const CPU_R32SFCPU As Short = &H1124S ' R32SFCPU
    Public Const CPU_R120SFCPU As Short = &H1125S ' R120SFCPU

    ''' iQ-R EN CPU
    Public Const CPU_R04ENCPU As Short = &H1008S        ' R04ENCPU
    Public Const CPU_R08ENCPU As Short = &H1009S        ' R08ENCPU
    Public Const CPU_R16ENCPU As Short = &H100AS        ' R16ENCPU
    Public Const CPU_R32ENCPU As Short = &H100BS        ' R32ENCPU
    Public Const CPU_R120ENCPU As Short = &H100CS       ' R120ENCPU

    ''' iQ-R Motion
    Public Const CPU_R16MTCPU As Short = &H1011S ' R16MTCPU.
    Public Const CPU_R32MTCPU As Short = &H1012S ' R32MTCPU.

    ''' iQ-R CCONTROLLER
    Public Const CPU_R12CCPU_V As Short = &H1021S ' R12CCPU-V.

    ''' iQ-F CPU
    Public Const CPU_FX5UCPU As Short = &H0210S 	' FX5U CPU

    ''' PORT
    Public Const PORT_1 As Short = &H1S ' CommunicationPort1
    Public Const PORT_2 As Short = &H2S ' CommunicationPort2
    Public Const PORT_3 As Short = &H3S ' CommunicationPort3
    Public Const PORT_4 As Short = &H4S ' CommunicationPort4
    Public Const PORT_5 As Short = &H5S ' CommunicationPort5
    Public Const PORT_6 As Short = &H6S ' CommunicationPort6
    Public Const PORT_7 As Short = &H7S ' CommunicationPort7
    Public Const PORT_8 As Short = &H8S ' CommunicationPort8
    Public Const PORT_9 As Short = &H9S ' CommunicationPort9
    Public Const PORT_10 As Short = &HAS ' CommunicationPort10


    ''' BAUDRATE
    Public Const BAUDRATE_300 As Short = 300 ' 300bps
    Public Const BAUDRATE_600 As Short = 600 ' 600bps
    Public Const BAUDRATE_1200 As Short = 1200 ' 1200bps
    Public Const BAUDRATE_2400 As Short = 2400 ' 2400bps
    Public Const BAUDRATE_4800 As Short = 4800 ' 4800bps
    Public Const BAUDRATE_9600 As Short = 9600 ' 9600bps
    Public Const BAUDRATE_19200 As Short = 19200 ' 19200bps
    Public Const BAUDRATE_38400 As Integer = 38400 ' 38400bps
    Public Const BAUDRATE_57600 As Integer = 57600 ' 57600bps
    Public Const BAUDRATE_115200 As Integer = 115200 ' 115200bps


    ''' DATA BIT
    Public Const DATABIT_7 As Short = 7 ' DATA BIT 7
    Public Const DATABIT_8 As Short = 8 ' DATA BIT 8


    ''' PARITY
    Public Const NO_PARRITY As Short = 0 ' NO PARITY
    Public Const ODD_PARITY As Short = 1 ' ODD PARITY
    Public Const EVEN_PARITY As Short = 2 ' EVEN PARITY


    ''' STOP BITS
    Public Const STOPBIT_ONE As Short = 0 ' 1 STOP BIT
    Public Const STOPBIT_TWO As Short = 2 ' 2 STOP BIT


    ''' SERIAL CONTROL
    Public Const TRC_DTR As Short = &H1S ' DTR
    Public Const TRC_RTS As Short = &H2S ' RTS
    Public Const TRC_DTR_AND_RTS As Short = &H7S ' DTR and RTS
    Public Const TRC_DTR_OR_RTS As Short = &H8S ' DTR or RTS


    ''' SUM CHECK
    Public Const SUM_CHECK As Short = 1 ' Sum Check
    Public Const NO_SUM_CHECK As Short = 0 ' No Sum Check]

    ''' PACKET TYPE
    Public Const PACKET_ASCII As Short = &H2S ' PACKET TYPE ASCII
    Public Const PACKET_BINARY As Short = &H3S ' PACKET TYPE BINARY

    ''' DELIMITER
    Public Const CRLF_NONE As Short = 0 ' CR/LF None
    Public Const CRLF_CR As Short = 1 ' CR ONLY
    Public Const CRLF_CRLF As Short = 2 ' CR/LF

    ''' CONNECT WAY
    Public Const TEL_AUTO_CONNECT As Short = &H0S ' AUTO LINE CONNECT
    Public Const TEL_AUTO_CALLBACK As Short = &H1S ' AUTO LINE CONNECT(CALLBACK FIXATION)
    Public Const TEL_AUTO_CALLBACK_NUMBER As Short = &H2S ' AUTO LINE CONNECT(CALLBACK NUMBER SPECIFICATION)
    Public Const TEL_CALLBACK As Short = &H3S ' CALLBACK CONNECT(FIXATION)
    Public Const TEL_CALLBACK_NUMBER As Short = &H4S ' CALLBACK CONNECT(NUMBER SPECIFICATION)
    Public Const TEL_CALLBACK_REQUEST As Short = &H5S ' CALLBACK REQUEST(FIXATION)
    Public Const TEL_CALLBACK_REQUEST_NUMBER As Short = &H6S ' CALLBACK REQUEST(NUMBER SPECIFICATION)
    Public Const TEL_CALLBACK_WAIT As Short = &H7S ' CALLBACK RECEPTION WAITING

    ''' LINE TYPE
    Public Const LINETYPE_PULSE As Short = &H0S ' PULSE
    Public Const LINETYPE_TONE As Short = &H1S ' TONE
    Public Const LINETYPE_ISDN As Short = &H2S ' ISDN

    ''' GOT TRANSPARENT PC IF
    Public Const GOT_PCIF_USB As Short = 1 ' USB
    Public Const GOT_PCIF_SERIAL As Short = 2 ' SERIAL
    Public Const GOT_PCIF_ETHERNET As Short = 3  ' ETHERNET

    ''' GOT TRANSPARENT PLC IF
    Public Const GOT_PLCIF_SERIAL_QCPUQ As Short = 1 ' SERIAL-QCPU Q
    Public Const GOT_PLCIF_SERIAL_QCPUA As Short = 2 ' SERIAL-QCPU A
    Public Const GOT_PLCIF_SERIAL_QNACPU As Short = 3 ' SERIAL-QnACPU
    Public Const GOT_PLCIF_SERIAL_ACPU As Short = 4 ' SERIAL-ACPU
    Public Const GOT_PLCIF_SERIAL_FXCPU As Short = 5 ' SERIAL-FXCPU
    Public Const GOT_PLCIF_SERIAL_LCPU As Short = 6 ' SERIAL-LCPU
    Public Const GOT_PLCIF_SERIAL_QJ71C24 As Short = 30 ' SERIAL-QJ71C24
    Public Const GOT_PLCIF_SERIAL_LJ71C24 As Short = 31 ' SERIAL-LJ71C24
    Public Const GOT_PLCIF_ETHERNET_QJ71E71 As Short = 50 ' ETHERNET-QJ71E71
    Public Const GOT_PLCIF_ETHERNET_CCIEFADP As Short = 60 ' ETHERNET-CC IE Field adapter
    Public Const GOT_PLCIF_ETHERNET_QCPU As Short = 70 ' ETHERNET-QCPU
    Public Const GOT_PLCIF_ETHERNET_LCPU As Short = 71 ' ETHERNET-LCPU
    Public Const GOT_PLCIF_BUS As Short = 90 ' BUS

    ''' ACTPROGTYPE UNITTYPE
    Public Const UNIT_QNCPU As Short = &H13S ' SERIAL(RS232C)-QCPU Q 
    Public Const UNIT_FXCPU As Short = &HFS ' SERIAL(RS232C)-FXCPU 
    Public Const UNIT_LNCPU As Short = &H50S ' SERIAL(RS232C)-LCPU
    Public Const UNIT_QNMOTION As Short = &H1CS ' SERIAL(RS232C)-QMOTION
    Public Const UNIT_QJ71C24 As Short = &H19S ' SERIAL(C24)-QCPU
    Public Const UNIT_FX485BD As Short = &H24S ' SERIAL(FX485BD)-FXCPU
    Public Const UNIT_LJ71C24 As Short = &H54S ' SERIAL(C24)-LCPU
    Public Const UNIT_QJ71E71 As Short = &H1AS ' Ethernet(QJ71E71)
    Public Const UNIT_FXENET As Short = &H26S ' Ethernet(FXENET)
    Public Const UNIT_FXENET_ADP As Short = &H27S ' Ethernet(FX1N-ENET-ADP)
    Public Const UNIT_QNETHER As Short = &H2CS ' Ethernet(QCPU) IP
    Public Const UNIT_QNETHER_DIRECT As Short = &H2DS ' Ethernet(QCPU) DIRECT
    Public Const UNIT_LNETHER4 As Short = &H52S ' Ethernet(LCPU) IP
    Public Const UNIT_LNETHER_DIRECT As Short = &H53S ' Ethernet(LCPU) DIRECT
    Public Const UNIT_NZ2GF_ETB As Short = &H59S ' NZ2GF-ETB
    Public Const UNIT_NZ2GF_ETB_DIRECT As Short = &H5AS ' NZ2GF-ETB DIRECT
    Public Const UNIT_QNUSB As Short = &H16S ' USB-QCPU 
    Public Const UNIT_LNUSB As Short = &H51S ' USB-LCPU
    Public Const UNIT_QNMOTIONUSB As Short = &H1DS ' USB-QMOTION
    Public Const UNIT_G4QNCPU As Short = &H1BS ' G4-QCPU
    Public Const UNIT_CCLINKBOARD As Short = &HCS ' CC-Link Board 
    Public Const UNIT_MNETHBOARD As Short = &H1ES ' MELSECNET/H Board
    Public Const UNIT_MNETGBOARD As Short = &H2BS ' CC-Link IE Control Board
    Public Const UNIT_CCIEFBOARD As Short = &H2FS ' CC-Link IE Field Board
    Public Const UNIT_SIMULATOR As Short = &HBS ' GX Simulator
    Public Const UNIT_SIMULATOR2 As Short = &H30S ' GX Simulator2
    Public Const UNIT_QBF As Short = &H1FS ' QBF
    Public Const UNIT_QSS As Short = &H20S ' Qn SoftLogic
    Public Const UNIT_A900GOT As Short = &H21S	' GOT
    Public Const UNIT_GOT_QJ71E712 As Short = &H40S ' GOT Transparent QJ71E71
    Public Const UNIT_GOT_QNETHER2 As Short = &H41S ' GOT Transparent Ethernet(QCPU)
    Public Const UNIT_GOT_LNETHER2 As Short = &H55S ' GOT Transparent Ethernet(LCPU)
    Public Const UNIT_GOT_NZ2GF_ETB2 As Short = &H5BS ' GOT Transparent NZ2GF-ETB
    Public Const UNIT_GOTETHER_QNCPU2 As Short = &H56S ' GOT Transparent ETHERNET-QCPU
    Public Const UNIT_GOTETHER_QBUS2 As Short = &H58S ' GOT Transparent ETHERNET-QBUS
    Public Const UNIT_GOTETHER_LNCPU2 As Short = &H57S ' GOT Transparent ETHERNET-LCPU
    Public Const UNIT_FXETHER As Short = &H4AS ' EthernetADP-FXCPU
    Public Const UNIT_FXETHER_DIRECT As Short = &H4BS ' EthernetADP-FXCPU(DIRECT)
    Public Const UNIT_GOTETHER_FXCPU As Short = &H60S ' GOT Transparent Ethernet(FXCPU)
    Public Const UNIT_GOT_FXETHER As Short = &H61S ' GOT Transparent FX3U-ENET-ADP
    Public Const UNIT_GOT_FXENET As Short = &H62S ' GOT FX3U-ENET(-L)
    Public Const UNIT_RJ71C24 As Short = &H1000S ' SERIAL(C24)-RCPU
    Public Const UNIT_RJ71EN71 As Short = &H1001S ' Ethernet(RJ71EN71)
    Public Const UNIT_RETHER As Short = &H1002S ' Ethernet(RCPU) IP
    Public Const UNIT_RETHER_DIRECT As Short = &H1003S ' Ethernet(QCPU) DIRECT
    Public Const UNIT_RUSB As Short = &H1004S ' USB-RCPU
    Public Const UNIT_RJ71EN71_DIRECT As Short = &H1005S ' Ethernet(RJ71EN71) DIRECT
    Public Const UNIT_GOT_RJ71EN71 As Short = &H1051S ' GOT Transparent RJ71EN71
    Public Const UNIT_GOT_RETHER As Short = &H1052S ' GOT Transparent Ethernet(RCPU)
    Public Const UNIT_GOTETHER_RJ71C24 As Short = &H1061S ' GOT Transparent ETHERNET-SERIAL(C24)-RCPU
    Public Const UNIT_FXVCPU As Short = &H2000S ' SERIAL(RS232C)-FX5CPU
    Public Const UNIT_FXVETHER As Short = &H2001S ' Ethernet(FX5CPU) IP
    Public Const UNIT_FXVETHER_DIRECT As Short = &H2002S ' Ethernet(FX5CPU) DIRECT
    Public Const UNIT_SIMULATOR3 As Short = &H31S ' GX Simulator3
    Public Const UNIT_GOT_FXVCPU As Short = &H2005S         ' GOT Transparent SERIAL(FX5U)
    Public Const UNIT_GOTETHER_FXVCPU As Short = &H2006S    ' GOT Transparent Ethernet-FX5U
    Public Const UNIT_GOT_FXVETHER As Short = &H2007S       ' GOT Transparent ETHERNET(FX5U)


    ''' ACTPROGTYPE PROTOCOLTYPE
    Public Const PROTOCOL_SERIAL As Short = &H4S ' Protocol Serial 
    Public Const PROTOCOL_USB As Short = &HDS ' Protocol USB
    Public Const PROTOCOL_TCPIP As Short = &H5S ' Protocol TCP/IP 
    Public Const PROTOCOL_UDPIP As Short = &H8S ' Protocol UDP/IP 
    Public Const PROTOCOL_MNETH As Short = &HFS ' Protocol MELSECNET/H 
    Public Const PROTOCOL_MNETG As Short = &H14S ' Protocol CC IE Control Board
    Public Const PROTOCOL_CCIEF As Short = &H15S ' Protocol CC IE Field Board
    Public Const PROTOCOL_CCLINK As Short = &H7S ' Protocol CC-LINK Board
    Public Const PROTOCOL_SERIALMODEM As Short = &HES ' Protocol MODEM 
    Public Const PROTOCOL_TEL As Short = &HAS ' Protocol TEL
    Public Const PROTOCOL_QBF As Short = &H10S ' Protocol QBF
    Public Const PROTOCOL_QSS As Short = &H11S ' Protocol QSS
    Public Const PROTOCOL_USBGOT As Short = &H13S ' Protocol GOT TRANSPARENT USB
    Public Const PROTOCOL_SHAREDMEMORY As Short = &H6S ' Protocol Simulator

    ''' ACTPROGTYPE INVERTER PROTOCOLTYPE
    Public Const COMM_RS232C As Short = &H0 ' Serial INVERTER
    Public Const COMM_USB As Short = &H1 ' USB INVERTER

    ''' ACTPROGTYPE ROBOTCONTROLLER PROTOCOLTYPE
    Public Const RC_PROTOCOL_SERIAL As Short = &H1	' Serial Robot Controller
    Public Const RC_PROTOCOL_USB As Short = &H4	' USB Robot Controller
    Public Const RC_PROTOCOL_TCPIP As Short = &H2	' TCP/IP Robot Controller
End Module
