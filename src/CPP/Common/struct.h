/** 
 *@file		struct.h
 *@brief	구조체를 정의합니다.								
 *@author	PNE Solution (Kang se-jun)
 *@date		2019-03-22
 */

//SFT_CAN_VALUE
/**
	@brief CAN Value 공용체
	주의!! : 구조체가 아닌 공용체입니다.
	이 공용체의 Total Size 는 8Bytes 입니다.
*/
union CTS_CAN_VALUE{
	long	lVal[2]; /**< 8 Byte 정수 */
	float	fVal[2]; /**< 8 Byte 실수 */
	char	strVal[8]; /**< 8 Byte 문자열 */
};

/**
	@brief Aux Data D version 구조체
*/
typedef struct CTS_AUX_DATA_D
{
	short int	chNo;						/**< Aux Channel 번호 */
	short int	chType;						/**< Aux Type (0:온도, 1:전압, 2:온도(써미스터)) */	
	long		lValue;						/**< Aux 값 */
};

//SFT_CH_DATA
/**
	@brief Channel Data 구조체
*/
struct CTS_CH_DATA		
{
	unsigned char	chNo;					/**< Channel Number	(0-Base, ex. 1번 채널일 경우 1, 3번 채널일 경우 3) */
	unsigned char	chState;				/**< 채널 운용 상태 \ref define_state_ch */
	unsigned char	chStepType;				/**< 채널 동작 상태 \ref chStepType */
	unsigned char	chMode;					/**< Step의 충전/방전 Mode (저항 및 전압 값을 일정하게 하여 충전/방전하기 위한 mode) \ref chMode */
	unsigned char	chDataSelect;			/**< data 저장 방식(0:For Display Data, 1 or 그외:For Saving Data (1:Step End, 그외:raw data) */
	unsigned char	chCode;					/**< 채널 코드(정상 및 오류 상태) \ref ChannelCode */
	unsigned char	chStepNo;				/**< 스텝 번호 */
	unsigned char	chGradeCode;			/**< ATS 필요 없음, Grade Code */
	long			lVoltage;				/**< 전압 (uV) */
	long			lCurrent;				/**< 전류 (uA) */	
	long			lChargeAh;				/**< 충전용량 (uA) */
	long			lDisChargeAh;			/**< 방전용량 (uA) */
	long			lCapacitance;			/**< Capacitance (uF) */
	long			lWatt;					/**< Watt (mW) */
	
	long			lChargeWh;				/**< Charge Wh (mW) */
	long			lDisChargeWh;			/**< Discharge Wh (mW) */
	unsigned long	ulStepDay;				/**< 스텝 진행 시간(day) */
	unsigned long	ulStepTime;				/**< 스텝 진행 시간 (10msec), sec = ulStepTime/100.0f */
	unsigned long	ulTotalDay;				/**< 시험 진행 시간(day) */
	unsigned long	ulTotalTime;			/**< 시험 진행 시간 (10msec), sec = ulTotalTime/100.0f */
	long			lImpedance;				/**< DC 저항값 (uohm) */
	unsigned char	chReservedCmd;			/**< 커맨드 예약 상태 (0:None, 1:Stop, 2:Pause) */
	unsigned char	chCommState;			/**< 통신 상태 Bit LSB(0:정상, 1:이상) 1st bit:Aux 온도 통신 상태, 2nd bit:Aux 전압 통신 상태, 3rd bit:CAN Master 통신상태, 4th bit: CAN Slave 통신상태 (ex. bit : 0000 0001이면 Aux 온도 통신 상태 이상) */	
	unsigned char	chOutputState;			/**< ATS 필요 없음, 출력 상태 Bit LSB(0:정상, 1:이상) 1st bit:keyOn, 2nd bit:ChargeOn, 3rd bit:PackRealyOn */
	unsigned char	chInputState;			/**< ATS 필요 없음,입력 상태 */
	short	 int	nAuxCount;				/**< Aux 개수 */
	short	 int	nCanCount;				/**< Can 개수 */

	unsigned long	nTotalCycleNum;			/**< 전체 Cycle 개수 */
	unsigned long	nCurrentCycleNum;		/**< 현재 Cycle 수 */
	unsigned long	nAccCycleGroupNum1;		/**< 그룹1 누적 Cycle 갯수 */
	unsigned long	nAccCycleGroupNum2;		/**< 그룹2 누적 Cycle 갯수 */
	unsigned long	nAccCycleGroupNum3;		/**< 그룹3 누적 Cycle 갯수 */
	unsigned long	nAccCycleGroupNum4;		/**< 그룹4 누적 Cycle 갯수 */
	unsigned long	nAccCycleGroupNum5;		/**< 그룹5 누적 Cycle 갯수 */
	unsigned long	nMultiCycleGroupNum1;	/**< 그룹1 Multi Cycle 갯수 */
	unsigned long	nMultiCycleGroupNum2;	/**< 그룹2 Multi Cycle 갯수 */
	unsigned long	nMultiCycleGroupNum3;	/**< 그룹3 Multi Cycle 갯수 */
	unsigned long	nMultiCycleGroupNum4;	/**< 그룹4 Multi Cycle 갯수 */
	unsigned long	nMultiCycleGroupNum5;	/**< 그룹5 Multi Cycle 갯수 */
	long			lAvgVoltage;			/**< 현재 스텝 평균 전압 (uV) */
	long			lAvgCurrent;			/**< 현재 스텝 평균 전류 (uA) */
	long			lSaveSequence;			/**< 모듈에서 저장하는 Data의 순서 번호 */
	unsigned long	ulCVDay;				/**< CV 시간(Day) */
	unsigned long	ulCVTime;				/**< CV 시간 (10msec), sec = ulCVTime/100.0f*/
	long			lSyncTime[2];			/**< 현재 데이터에 대한 시간정보 YYYYMMDD HHMMSS.mmm 변환 가능한 시간 20080723 214055.123	 */

	long			lVoltage_Input;			/**< ATS 필요 없음, 전압 입력 */
	long			lVoltage_Power;			/**< ATS 필요 없음, 전압 파워 */
	long			lVoltage_Bus;			/**< ATS 필요 없음, 전압 버스 */
	unsigned char	cUsingChamber;			/**< ATS 필요 없음, 챔버 연동 */
	unsigned char	cRecordTimeNo;			/**< ATS 필요 없음, (1 base : R1,R2,R3) */
	unsigned char	cOutMuxUse;				/**< ATS 필요 없음, 먹스 사용 (0:not use, 1:use) */
	unsigned char	cOutMuxBackup;			/**< ATS 필요 없음, 먹스 설정 (0:open, 1:Mux A, 2:Mux B) */
	long			lreserved[6];			/**< 예비 */
};

//SFT_AUX_DATA
/**
	@brief Aux Data 구조체 (Module에 setting 하는 값이며 Max 512개)
*/
struct CTS_AUX_DATA
{
	short int		auxChNo; /**< Aux Channel 번호 */
	unsigned char	auxChType;	/**< Aux Type (0:온도, 1:전압, 2:온도(써미스터)) */	
	unsigned char	auxTempTableType; /**< 써미스터 온도 테이블(장비마다 설정 값이 달라 장비에서 확인 후 설정)	 */
	long			lValue; /**< Aux 값 (온도: 1000 == 1℃, Voltage: uV, 온도: 1000000 == 1℃) */
};


//SFT_CAN_DATA
/**
	@brief CAN DATA 구조체 (Channel에 setting 하는 값이며 Max 512개)
*/
struct CTS_CAN_DATA {
	unsigned char		canType;			 /**< CAN 타입 (0:master, 1:slave) */
	unsigned char		data_type;			 /**< DATA 타입 (0:signed, 1:unsigned, 2:string) */
	short int			function_division;	 /**< Division Code */
	CTS_CAN_VALUE		canVal;				 /**< Can Value */
};

//SFT_VARIABLE_CH_DATA
//주의** SFT_VARIABLE_CH_DATA != CTS_VARIABLE_CH_DATA
/**
	@brief CTS 종합 채널 데이터 구조체
*/
struct CTS_VARIABLE_CH_DATA
{
	CTS_CH_DATA 		chData;								/**< 기본 채널 데이터 */
	CTS_AUX_DATA		auxData[CTS_MAX_MAPPING_AUX];		/**< Aux Data */
	CTS_CAN_DATA		canData[CTS_MAX_MAPPING_CAN];		/**< Can Data */	
};


//CAN////////////////////////////////////////////////////////////////////

//SFT_CAN_COMMON_DATA
/**
	@brief CAN 통신 공통 데이터
*/
struct CTS_CAN_COMMON_DATA {
	unsigned char		can_baudrate;			/**< Can 통신 Baudrate (0:125k, 1:250k, 2:500k, 3:1M) */
	unsigned char		extended_id;			/**< 확장 ID (0:unused, 1:used) */
	unsigned char		bms_type;				/**< BMS 타입 (ATS에서 default:0 으로 설정) */
	unsigned char		bms_sjw;				/**< BMS SJW (ATS에서 default:0 으로 설정) */
	
	long				controller_canID;		/**< 컨트롤러 Can ID */
	long				mask[2];				/**< Mask */
	long				filter[6];				/**< Filter */

	unsigned char		can_fd_flag;			/**< CAN FD Flag (0:can 2.0B, 1: can_fd) */
	unsigned char		can_datarate;			/**< CAN Data Rate (0:500K, 1:833K, 2:1M, 3:1.5M, 4:2M, 5.3M) */
	unsigned char		terminal_r;				/**< Terminal 저항 (0:open, 1:120ohm<default>) */
	unsigned char		crc_type;				/**< CRC 타입 (0:non iso crc, 1:iso crc<default>) */

	unsigned char		can_lin_select;			/**< CAN/LIN 선택 (0:can, 1:Lin) */
	unsigned char		c_Reserved[3];			/**< 예비 공간 */
	long				l_Reserved_2;				/**< 예비 공간 */	

	short int			can_function_division[10];	/**< 분류 번호 */
	unsigned char		can_compare_type[10];		/**< CAN 값 비교 (type 0:사용 안함, 1:<, 2:<=, 3:==, 4:>, 5:=>) */
	unsigned char		can_data_type[10];			/**< CAN 값 비교 (type 0:사용 안함, 1:signed, 2:float) */
	float				f_Reserved[10];				/**< 예비 공간 */
};

//SFT_CAN_SET_DATA
/**
	@brief CAN 통신 공통 데이터
*/
struct CTS_CAN_SET_DATA {
	unsigned char		canType;				/**< Can 타입 (0:unused, 1:master, 2:slave) */
	unsigned char		byte_order;				/**< Byte order (0:intel, 1:motolora) */
	unsigned char		data_type;				/**< Data 타입 (0:signed, 1:unsigned, 2:string, 3:float, 4:bit) */
	unsigned char		c_Reserved;				/**< 예비 공간 */	

	float				factor_multiply;		/**< 양수 값 : 곱하기, 음수 값 : 나누기 */
	short int			startBit;				/**< start bit */
	short int			bitCount;				/**< bit count */
	long				canID;					/**< Can ID hex value */
	char				name[128];				/**< 이름 */
	float				fault_upper;			/**< 실패 상한 */
	float				fault_lower;			/**< 실패 하한 */
	float				end_upper;				/**< 종료 상한 */
	float				end_lower;				/**< 종료 하한 */
	float				default_fValue;			/**< 기본 값 설정 */ 
	float				factor_Offset;			/**< 팩터 오프셋 */	
	short int			function_division;		/**< 분류 코드(1001 ~ 1200) */
	short int			function_division2;		/**< 분류 코드(1001 ~ 1200) */
	short int			function_division3;		/**< 분류 코드(1001 ~ 1200) */
	short int			ui_Reserved;			/**< 예비 공간 */	
	long				sentTime;				/**< 전송 시간 */	
	long				l_Reserved[2];			/**< 예비 공간 */	

	short int			startBit2;				/**< start bit2 */	
	short int			bitCount2;				/**< bit count2 */	
	unsigned char		byte_order2;			/**< Byte order (0:intel, 1:motolora) */
	unsigned char		data_type2;				/**< Data 타입 (0:signed, 1:unsigned, 2:string, 3:float, 4:bit) */
	unsigned char		c_Reserved2[2];			/**< 예비 공간 */	
	float				default_fValue2;		/**< 기본 값 설정2 */ 
};

//주의** SFT_VARIABLE_CH_DATA_D != CTS_VARIABLE_CH_DATA
/**
	@brief Channel Data D version 구조체
*/
typedef struct CTS_VARIABLE_CH_DATA_D
{
	CTS_CH_DATA 	chData;							/**< 기본 채널 데이터 */
	CTS_AUX_DATA_D	auxData[CTS_MAX_MAPPING_AUX];	/**< Aux Data */
	CTS_CAN_DATA	canData[CTS_MAX_MAPPING_CAN];	/**< Can Data */	
};

//주의** SFT_VARIABLE_CH_DATA_F != CTS_VARIABLE_CH_DATA
/**
	@brief CTS F Version 종합 채널 데이터 구조체
*/
typedef struct CTS_VARIABLE_CH_DATA_F
{			
	CTS_CH_DATA 	chData;							/**< 기본 채널 데이터 */
	CTS_AUX_DATA	auxData[CTS_MAX_MAPPING_AUX];	/**< Aux Data */
	CTS_CAN_DATA	canData[CTS_MAX_MAPPING_CAN];	/**< Can Data */	
};	

//SFT_RCV_CMD_CAN_SET
/**
	@brief Can 수신 설정 데이터 묶음
*/
struct CTS_RCV_CMD_CAN_SET {
	CTS_CAN_COMMON_DATA	canCommonData[CTS_MAX_INSTALL_CH_COUNT][2];					/**< CAN 공통 수신 Data */
	CTS_CAN_SET_DATA	canSetData[CTS_MAX_INSTALL_CH_COUNT][CTS_MAX_MAPPING_CAN];	/**< CAN 설정 수신 Data */
} ;


//SFT_RCV_CMD_CHANNEL_CAN_SET
/**
	@brief Can 수신 설정 데이터 묶음(채널별)
*/
struct CTS_RCV_CMD_CHANNEL_CAN_SET{
	CTS_CAN_COMMON_DATA	canCommonData[2];						/**< CAN 공통 수신 Data */
	CTS_CAN_SET_DATA	canSetData[CTS_MAX_MAPPING_CAN];		/**< CAN 설정 수신 Data */
};

//SFT_MD_CAN_INFO_DATA
/**
	@brief 전체 CAN 수신 설정 데이터
*/
struct CTS_MD_CAN_INFO_DATA {
	short int installedCanCount[CTS_MAX_INSTALL_CH_COUNT];		/**< 채널별 설치된 Can 수 */
	CTS_RCV_CMD_CAN_SET	canSetAllData;							/**< CAN 수신 설정 Data */
};


//CAN Transmit////////////////////////////////////////////////////////
//SFT_CAN_COMMON_TRANS_DATA
//SFT_VARIABLE_CH_DATA
/**
	@brief Can 공통 전송 Data
*/
struct CTS_CAN_COMMON_TRANS_DATA {
	unsigned char		can_baudrate;		/**< CAN 통신 Baoudrate (0:125k, 1:250k, 2:500k, 3:1M) */
	unsigned char		extended_id;		/**< extended id (0:unused, 1:used) */
	unsigned char		bms_type;			/**< BMS 타입 (ATS에서 default:0 으로 설정) */
	unsigned char		bms_sjw;			/**< BMS SJW (ATS에서 default:0 으로 설정) */
	long				l_Reserved;			/**< 예비 공간 */

	unsigned char		can_fd_flag;		/**< CAN FD Flag (0:can 2.0B, 1:can_fd) */
	unsigned char		can_datarate;		/**< CAN Data Rate (0:500K, 1:833K, 2:1M, 3:1.5M, 4:2M, 5.3M)*/
	unsigned char		terminal_r;			/**< CAN Terminal 저항 (0:open, 1:120ohm<default>) */
	unsigned char		crc_type;			/**< CRC 타입 (0:non iso crc, 1:iso crc<default>) */

	unsigned char		can_lin_select;		/**< CAN/LIN 선택 (0:can, 1:Lin) */
	unsigned char		c_Reserved[3];		/**< 예비 공간 */	

	short int can_function_division[10];	/**< 분류 코드 (10010 ~ 10014)*/
	unsigned char can_compare_type[10];		/**< can 값이 비교대상 -> 비교 type (0:사용 안함, 1:<, 2:<=, 3:==, 4:>, 5:=>)*/
	unsigned char can_data_type[10];		/**< can 값이 비교대상 -> 비교 type (0:사용 안함, 1:signed, 2:float) */
	float	f_Reserved[10];					/**< 예비 공간 */
};

//SFT_CAN_SET_TRANS_DATA
/**
	@brief Can 전송 설정 Data
*/
struct CTS_CAN_SET_TRANS_DATA {
	unsigned char		canType;			/**< Can 타입 (0:unused, 1:master, 2:slave) */
	unsigned char		byte_order;			/**< Byte order (0:intel, 1:motolora) */
	unsigned char		data_type;			/**< Data 타입 (0:signed, 1:unsigned, 2:string, 3:float , 4:bit) */
	unsigned char		dlc;				/**< 0 bit : capvtg , 1 bit : mcu temp */  
	float				factor_multiply;	/**< 양수 값 : 곱하기, 음수 값 : 나누기 */
	float				default_fValue;		/**< 기본 값 설정 */ 
	short int			startBit;			/**< start bit */
	short int			bitCount;			/**< bit count */
	long				canID;				/**< Can ID hex value */
	long				send_time;			/**< 전송속도(ms) */
	char				name[128];			/**< 이름 */
	long				l_Reserved;			/**< 예비 공간 */	
	
	float				factor_Offset;		/**< 팩터 오프셋 */	
	short int			function_division;	/**< 분류 코드 (10010 ~ 10014) */
	short int			function_division2;	/**< 분류 코드 (10010 ~ 10014) */
	short int			function_division3;	/**< 분류 코드 (10010 ~ 10014) */
	short int			ui_Reserved;		/**< 예비 공간 */	
	long				l_Reserved2[2];		/**< 예비 공간 */	
};



//SFT_TRANS_CMD_CAN_SET
/**
	@brief Can 전송 설정 데이터 묶음
*/
struct CTS_TRANS_CMD_CAN_SET {
	CTS_CAN_COMMON_TRANS_DATA	canCommonData[CTS_MAX_INSTALL_CH_COUNT][2];					/**< CAN 공통 전송 Data */
	CTS_CAN_SET_TRANS_DATA	canSetData[CTS_MAX_INSTALL_CH_COUNT][CTS_MAX_MAPPING_CAN];		/**< CAN 전송 설정 Data */
};

//SFT_TRANS_CMD_CHANNEL_CAN_SET
/**
	@brief Can 전송 설정 데이터 묶음(채널별)
*/
struct CTS_TRANS_CMD_CHANNEL_CAN_SET {
	CTS_CAN_COMMON_TRANS_DATA	canCommonData[2];					/**< CAN 공통 전송 Data */
	CTS_CAN_SET_TRANS_DATA	canSetData[CTS_MAX_MAPPING_CAN];		/**< CAN 전송 설정 Data */
};

//SFT_MD_CAN_TRANS_INFO_DATA
/**
	@brief Can 전송 정보 데이터
*/
struct CTS_MD_CAN_TRANS_INFO_DATA {
	short int installedCanCount[CTS_MAX_INSTALL_CH_COUNT];		/**< 채널 보드별 설치된 CAN 개수*/
	CTS_TRANS_CMD_CAN_SET	canSetAllData;						/**< CAN 전송 설정 데이터 묶음 */
};

//SFT_MD_CAN_INFO_DATA
/**
	@brief Can 수신 정보 데이터
*/
struct CTS_MD_CAN_RECV_INFO_DATA {
	short int installedCanCount[CTS_MAX_INSTALL_CH_COUNT];		/**< 채널 보드별 설치된 CAN 개수*/
	CTS_RCV_CMD_CAN_SET	canSetAllData;							/**< CAN 수신 설정 데이터 묶음 */
};

//SFT_MD_PARALLEL_DATA
/**
	@brief 병렬 모드 설정 데이터
*/
struct CTS_MD_PARALLEL_DATA{

	unsigned char chNoMaster;			/**< Master Channel Number (1-Base, ex. 1번 채널일 경우 1, 3번 채널일 경우 3) */
	unsigned char chNoSlave[3];			/**< Slave Channel Number 3개까지 Slave 가능	(1-Base, ex. 1번 채널일 경우 1, 3번 채널일 경우 3) */	
	unsigned char bParallel;			/**< 병렬 모드 Flag (0:병렬 해제, 1:병렬 설정) */	
	unsigned char reserved[3];			/**< 예비 공간 */	
	unsigned char reserved2[4];			/**< 예비 공간 */	
};

//s_SFT_CMD_INFO_DATA, SFT_CMD_INFO_DATA
/**
	@brief 충방전기 버전 정보 데이터
*/
struct CTS_MD_SYSTEM_DATA {
	unsigned int		nModuleID;							/**< 모듈 ID (Module에서는 GroupID, Host에서는 ModuleID) */
	unsigned int		nSystemType;						/**< 설비 타입 (Formation/IROCV/Aging/Grader/Selector) */
	unsigned int		nProtocolVersion;					/**< 충방전 통신 프로토콜 버전 (Protocol Version) */
	char				szModelName[128];					/**< Module Model Name */
	unsigned int		nOSVersion;							/**< System Version  */
	unsigned short int	wVoltageRange;						/**< 전압 Range 수 */
	unsigned short int	wCurrentRange;						/**< 전류 Range 수 */
	unsigned int		nVoltageSpec[5];					/**< 전압 Range 별 Spec (uV) */
	unsigned int		nCurrentSpec[5];					/**< 전류 Range 별 Spec (uA) */
	unsigned char		byCanCommType;						/**< CAN 통신 타입 (0:CAN 2.0, 1:CAN FD) */
	unsigned char		byTypeData[7];						/**< ATS 필요 없음, Module Location, Line No, Module Type, Etc...	 */
	unsigned short int	wInstalledBoard;					/**< 설치 보드 수 (Total Board Number in one Module) */
	unsigned short int	wChannelPerBoard;					/**< 보드당 채널 수 (Total Channel Per Board) */
	unsigned int		nInstalledChCount;					/**< 전체 채널 수 */
	unsigned int		nTotalJigNo;						/**< ATS 필요 없음, 전체 지그 수 */
	unsigned int		awBdInJig[16];						/**< ATS 필요 없음, 보드 별 지그 수 */
	unsigned int		reserved[4];						/**< 예비 공간 */	
};

// SFT_SYSTEM_PARAM
/**
	@brief 충방전기 시스템 파라미터 설정 정보
*/
struct CTS_SYSTEM_PARAM {			
	char		szIPAddr[CTS_IP_NAME_LENGTH];		/**< IP 주소 */
	LONG		lModuleType;						/**< 모듈 타입*/
	WORD		wVRangeCount;						/**< 전압 레인지 개수 */
	WORD		wIRangeCount;						/**< 전류 레인지 개수 */
	LONG		lVSpec[CTS_MAX_VOLTAGE_RANGE];		/**< 레인지별 전압 스펙 */
	LONG		lISpec[CTS_MAX_CURRENT_RANGE];		/**< 레인지별 전류 스펙 */
	WORD		wInstallChCount;					/**< 전체 채널 수 */
	BOOL		bAutoProcess;						/**< ATS 필요 없음, 자동 공정 여부*/
	long		lMaxVoltage;						/**< 최대 전압 (uV)*/
	long		lMinVoltage;						/**< 최소 전압 (uV)*/
	long		lMaxCurrent;						/**< 최대 전류 (uA)*/
	long		lMinCurrent;						/**< 최소 전류 (uA)*/
	long		lMaxTemp;							/**< ATS 필요 없음, 온도 상한치 */
	BOOL		bUseTempLimit;						/**< ATS 필요 없음, 온도 Limit 사용 여부 */
	long		lMaxGas;							/**< ATS 필요 없음, 가스 상한치 */
	long		bUseGasLimit;						/**< ATS 필요 없음, 가스 Limit 사용 여부 */
	WORD		wModuleType;						/**< ATS 필요 없음, Module 의 형태 (원통형/각형)==> Tray의 배열과 같다. */
	WORD		nAutoReportInterval;				/**< ATS 필요 없음, 자동 보고 시간 간격  */
};


//STF_MD_AUX_SET_DATA
/**
	@brief Aux 설정 데이터
*/
struct CTS_MD_AUX_SET_DATA{
	unsigned char chNo;					/**< 충방전기 채널 번호 (1-Base, ex. 1번 채널일 경우 1, 3번 채널일 경우 3) */
	unsigned char auxTempTableType;		/**< Thermistor Type (1:VW_MEB, 2:Volvo_CMA, 3:B10XLR, 4:103AT, 5:TC310F34BPEP, 6:103AT_2) */
	unsigned char reserved[2];			/**< 예비 공간 */
	short	auxChNo;					/**< Aux 채널 번호 (1-Base, ex. 1번 채널일 경우 1, 3번 채널일 경우 3) */
	short	auxType;					/**< AUX Type (0:온도센서, 1:Voltage, 2:온도센서(Thermistor) 3:습도센서(v1016~))	 */
	char	szName[128];				/**< Aux 이름 */
	long	lMaxData;					/**< 센서의 상한값 (온도: 1000 == 1℃, Voltage: uV, 온도: 1000000 == 1℃) */
	long	lMinData;					/**< 센서의 하한값 (온도: 1000 == 1℃, Voltage: uV, 온도: 1000000 == 1℃) */
	long	lEndMaxData;				/**< 종료 상한값 (온도: 1000 == 1℃, Voltage: uV, 온도: 1000000 == 1℃) */
	long	lEndMinData;				/**< 종료 하한값 (온도: 1000 == 1℃, Voltage: uV, 온도: 1000000 == 1℃) */

	short int	funtion_division1;		/**< 분류 코드 (2001 ~ 2200) */	
	short int	funtion_division2;		/**< 분류 코드 (2001 ~ 2200) */ 
	short int	funtion_division3;		/**< 분류 코드 (2001 ~ 2200) */
	short int	reserved2;				/**< 예비 공간 */
};


//CTS_MD_AUX_SET_DATA_16
/**
	@brief Aux 설정 데이터 (V1016 이후 사용 구조체)
*/
struct CTS_MD_AUX_SET_DATA_16{	
	unsigned char chNo;					/**< 충방전기 채널 번호 (1-Base, ex. 1번 채널일 경우 1, 3번 채널일 경우 3) */
	unsigned char auxTempTableType;		/**< Thermistor Type (1:VW_MEB, 2:Volvo_CMA, 3:B10XLR, 4:103AT, 5:TC310F34BPEP, 6:103AT_2) */
	unsigned char reserved[2];			/**< 예비 공간 */
	short	auxChNo;					/**< Aux 채널 번호 (1-Base, ex. 1번 채널일 경우 1, 3번 채널일 경우 3) */
	short	auxType;					/**< AUX Type (0:온도센서, 1:Voltage, 2:온도센서(Thermistor) 3:습도센서(v1016~))	 */
	char	szName[128];				/**< Aux 이름 */
	long	lMaxData;					/**< 센서의 상한값 (온도: 1000 == 1℃, Voltage: uV, 온도TH: 1000000 == 1℃, 습도: 1000000 == 1%) */
	long	lMinData;					/**< 센서의 하한값 (온도: 1000 == 1℃, Voltage: uV, 온도TH: 1000000 == 1℃, 습도: 1000000 == 1%) */
	long	lEndMaxData;				/**< 종료 상한값 (온도: 1000 == 1℃, Voltage: uV, 온도TH: 1000000 == 1℃, 습도: 1000000 == 1%) */
	long	lEndMinData;				/**< 종료 하한값 (온도: 1000 == 1℃, Voltage: uV, 온도TH: 1000000 == 1℃, 습도: 1000000 == 1%) */
	
	long	lVentSafetyMax;				/**< 고정 상한 안전 조건 (V1016~), 일시정지 및 챔버 배출(사양 지원시), 0입력시 동작 안함 */
	long	lVentSafetyMin;				/**< 고정 하한 안전 조건 (V1016~), 일시정지 및 챔버 배출(사양 지원시), 0입력시 동작 안함 */

	short int	funtion_division1;		/**< 분류 코드 (2001 ~ 2200) */	
	short int	funtion_division2;		/**< 분류 코드 (2001 ~ 2200) */ 
	short int	funtion_division3;		/**< 분류 코드 (2001 ~ 2200) */
	short int	reserved2;				/**< 예비 공간 */	
};

		
//s_SFT_AUX_INFO_DATA
/**
	@brief Installed Aux Data Format (V100D ~ V1015)
*/
struct CTS_AUX_INFO_DATA {

	unsigned char chNo;					/**< 충방전기 채널 번호 (1-Base, ex. 1번 채널일 경우 1, 3번 채널일 경우 3) */
	unsigned char reserved[3];			/**< 예비 공간 */
	short int	auxChNo;				/**< Aux 채널 번호 (1-Base, ex. 1번 채널일 경우 1, 3번 채널일 경우 3) */
	short int	auxType;				/**< AUX Type (0:온도센서, 1:Voltage, 2:온도센서(Thermistor) 3:습도센서(v1016~))	 */
	char		szName[128];			/**< Aux 이름 */
	long		upper_limit;			/**< 센서의 상한값 (온도: 1000 == 1℃, Voltage: uV, 온도: 1000000 == 1℃) */
	long		lower_limit;			/**< 센서의 하한값 (온도: 1000 == 1℃, Voltage: uV, 온도: 1000000 == 1℃) */
	long		reserved1[4];			/**< 예비 공간 */
#if 0
	unsigned char chNo;					/**< 충방전기 채널 번호 (1-Base, ex. 1번 채널일 경우 1, 3번 채널일 경우 3) */
	unsigned char auxTempTableType;		/**< Thermistor Type (1:VW_MEB, 2:Volvo_CMA, 3:B10XLR, 4:103AT, 5:TC310F34BPEP, 6:103AT_2, \n 장비마다 설정 값이 달라 장비에서 확인 후 설정해야 함)	 */
	unsigned char reserved[2];			/**< 예비 공간 */
	short	auxChNo;					/**< Aux 채널 번호 (1-Base, ex. 1번 채널일 경우 1, 3번 채널일 경우 3) */
	short	auxType;					/**< AUX Type (0:온도센서, 1:Voltage, 2:온도센서(Thermistor))	 */
	char	szName[128];				/**< Aux 이름 */
	long	lMaxData;					/**< 센서의 상한값 (온도: 1000 == 1℃, Voltage: uV, 온도: 1000000 == 1℃) */
	long	lMinData;					/**< 센서의 하한값 (온도: 1000 == 1℃, Voltage: uV, 온도: 1000000 == 1℃) */
	long	lEndMaxData;				/**< 종료 상한값 (온도: 1000 == 1℃, Voltage: uV, 온도: 1000000 == 1℃) */
	long	lEndMinData;				/**< 종료 하한값 (온도: 1000 == 1℃, Voltage: uV, 온도: 1000000 == 1℃) */

	short int	funtion_division1;		/**< 분류 코드 (2001 ~ 2200) */	
	short int	funtion_division2;		/**< 분류 코드 (2001 ~ 2200) */ 
	short int	funtion_division3;		/**< 분류 코드 (2001 ~ 2200) */
	short int	reserved2;				/**< 예비 공간 */
#endif
};


//s_SFT_AUX_INFO_DATA_TYPE2
/**
	@brief Installed Aux Data Format (V1016~)
*/
struct CTS_AUX_INFO_DATA_16 {
	unsigned char chNo;					/**< 충방전기 채널 번호 (1-Base, ex. 1번 채널일 경우 1, 3번 채널일 경우 3) */
	unsigned char auxTempTableType;		/**< Thermistor Type (1:VW_MEB, 2:Volvo_CMA, 3:B10XLR, 4:103AT, 5:TC310F34BPEP, 6:103AT_2, \n 장비마다 설정 값이 달라 장비에서 확인 후 설정해야 함)	 */
	unsigned char vent_use_flag;		/**< 안전 상한/하한 동작시 챔버 Vent 안전 기능 사용 여부 0: 미사용 1: 사용 */
	unsigned char reserved1;			/**< 예비 공간 */
	short	auxChNo;					/**< Aux 채널 번호 (1-Base, ex. 1번 채널일 경우 1, 3번 채널일 경우 3) */
	short	auxType;					/**< AUX Type (0:온도센서, 1:Voltage, 2:온도센서(Thermistor) 3:습도센서(v1016~))	 */
	char	szName[128];				/**< Aux 이름 */
	long	upper_limit;				/**< 센서의 상한값 (온도: 1000 == 1℃, Voltage: uV, 온도: 1000000 == 1℃, 습도: 1000000 == 1%) */	
	long	lower_limit;				/**< 센서의 하한값 (온도: 1000 == 1℃, Voltage: uV, 온도: 1000000 == 1℃, 습도: 1000000 == 1%) */
	long	lEndMaxData;				/**< 종료 상한값 (온도: 1000 == 1℃, Voltage: uV, 온도: 1000000 == 1℃, 습도: 1000000 == 1%) */
	long	lEndMinData;				/**< 종료 하한값 (온도: 1000 == 1℃, Voltage: uV, 온도: 1000000 == 1℃, 습도: 1000000 == 1%) */
	
	long	lVentSafetyMax;				/**< 상시 감시 안전 조건 상한값 (온도: 1000 == 1℃, Voltage: uV, 온도: 1000000 == 1℃, 습도: 1000000 == 1%) , 챔버 사양 지원시 Vent 안전 기능 동작*/
	long	lVentSafetyMin;				/**< 상시 감시 안전 조건 하한값 (온도: 1000 == 1℃, Voltage: uV, 온도: 1000000 == 1℃, 습도: 1000000 == 1%) , 챔버 사양 지원시 Vent 안전 기능 동작*/

	short int	funtion_division1;		/**< 분류 코드 (2001 ~ 2200) */		
	short int	funtion_division2;		/**< 분류 코드 (2001 ~ 2200) */	
	short int	funtion_division3;		/**< 분류 코드 (2001 ~ 2200) */	
	short int	reserved2;				/**< 예비 공간 */
};


//SFT_MD_AUX_INFO_DATA
/**
	@brief 외부(aux) Data 설정 데이터  (V100D~V1015)
*/
struct CTS_MD_AUX_INFO_DATA
{
	short int	wInstalledTemp;							/**< Aux 온도 개수 */	
	short int	wInstalledVolt;							/**< Aux 전압 개수 */	
	short int	wInstalledTempTh;						/**< 온도 Thermistor 개수 */	
	short int	reserved;								/**< 예비 공간 */	
	CTS_AUX_INFO_DATA auxData[CTS_MAX_MAPPING_AUX];		/**< Aux 채널별 정보 */	
};

//SFT_MD_AUX_INFO_DATA
/**
	@brief 외부(aux) Data 설정 데이터 (V100D~V1015)
*/
struct CTS_MD_AUX_INFO_DATA_V2
{
	short int	wInstalledTemp;							/**< Aux 온도 개수 */	
	short int	wInstalledVolt;							/**< Aux 전압 개수 */	
	short int	wInstalledTempTh;						/**< 온도 Thermistor 개수 */	
	short int	reserved;								/**< 예비 공간 */	
	CTS_MD_AUX_SET_DATA auxData[CTS_MAX_MAPPING_AUX];		/**< Aux 채널별 정보 */	 //CTS_AUX_INFO_DATA와 size 동일.
};

//CTS_MD_AUX_INFO_DATA_TYPE2
/**
	@brief 외부(aux) Data 설정 데이터 (V1016~)
*/
struct CTS_MD_AUX_INFO_DATA_16
{
	short int	wInstalledTemp;							/**< Aux 온도 개수 */	
	short int	wInstalledVolt;							/**< Aux 전압 개수 */	
	short int	wInstalledTempTh;						/**< 온도 Thermistor 개수 */	
	short int	wInstalledHumi;							/**< 습도 센서 Aux 개수 */	
	CTS_AUX_INFO_DATA_16 auxData[CTS_MAX_MAPPING_AUX];		/**< Aux 채널별 정보 */	
};


//SFT_EMG_DATA
/**
	@brief Emergency 알람 구조체
*/
struct CTS_EMG_DATA
{
	short int	wCode;			/**< EMG 코드 \ref EmgCode*/
	short int	wValue;			/**< EMG 값 */
	long		reserved;		/**< 예비 공간 */
	char		szName[128];	/**< EMG 이름 */
};

/**
	@brief Schedule File의 Step 기본정보 확인 구조체
	* 모든 정보를 포함하지는 않으며, 주요 정보 몇가지만 포함한다.
*/
struct CTS_SCH_STEP_INFO
{
	int			nStepType;				/**< 스텝 Type */
	BYTE		stepNo;					/**< 진행 Step 번호(1 Base) */
	BYTE		mode;					/**< CC/CV, CP , CR ... */
	BYTE		reserved[2];

	long		lVref_Charge;			/**< Charge Voltage Referance */
	long		lVref_DisCharge;		/**< Discharge Voltage Referance */
	long		lIref;					/**< Current Referance */
	long		lPref;					/**< Power Referance */	

	ULONG		ulEndTimeDay;			/**< End time Day	*/
	ULONG		ulEndTime;				/**< End time */
	long		lEndV_H;				/**< End Voltage High */
	long		lEndV_L;				/**< End Voltage Low */
	long		lEndI;					/**< End Current */			
	long		lEndC;					/**< End Capacity */
	long		lEndWatt;				/**< End Watt */
	long		lEndWattHour;			/**< End WattHour */
	ULONG		ulCVTimeDay;			/**< CV Time Day */
	ULONG		ulCVTime;				/**< CV Time */
};


/**
	@brief Schedule File의 Cell Balancing 연동 스텝 정보 확인 구조체
*/
struct CTS_SCH_EXT_CB_INFO
{
	BYTE	stepNo;						/**< 진행 Step 번호(1 Base) */
	BYTE	reserved[3];
	int     nCbCircuitRes;				/**< 회로 저항 입력범위 10~100 */
	int     nCbWorkVoltLower;			/**< 밸런싱 진행 전압 하한 (mV)*/
	int     nCbWorkVoltUpper;			/**< 밸런싱 진행 전압 상한 (mV)*/
	int     nCbStartDeltaVolt;			/**< 밸런싱 시작 전압 편차 (mV)*/
	int     nCbEndDeltaVolt;			/**< 밸런싱 종료 전압 편차 (mV)*/
	int     nCbActiveTime;				/**< Active Time (3~99초) */
	int     nCbAutoStopTime;			/**< Auto Stop Time (초) */
	int     nCbAutoNextStep;			/**< Auto Next Step (0:스텝종료조건사용, 1:자동다음스텝)*/
	ULONG	ulStepEndTime;				/**< 스텝의 시간 종료 조건 (초) 예: 30초(30),1시간30초(3630) 2일1시간30초(176430)*/
	int		nReserved[3];				/**< 미사용*/
};


/**
	@brief 간이충방전 API 전달 구조체
*/
struct CTS_SIMPLE_TEST_INFO {			
	//시험 조건
	int nStepType;					/**< 스텝. Charge:1, Discharge:2, Rest:3, OCV:4  */
	int nMode;						/**< 모드. CCCV:1, CC:2 CV:3 CP:6 */

	int nRefVoltage;				/**< 설정 전압 mV */
	int nRefCurrent;				/**< 설정 전압 mA */
	int nRefPower;					/**< 설정 파워 mW */
	int nRecordTime;				/**< 기록 시간 (1/10초) 예) 1초:10 , 20초:200, 0.1초: 1 */

	//종료 조건
	int nCutoffCondTime;			/**< 종료 시간 (초) */
	int nCutoffCondVolt;			/**< 종료 전압 mV */
	int nCutoffCondCurrent;			/**< 종료 전류 mA */
	int nCutoffCondAh;				/**< 종료 용량 mAh */

	//안전 조건
	int nSafetyVoltageHigh;			/**< 전압 상한 mV */
	int nSafetyVoltageLow;			/**< 전압 하한 mV */
	int nSafetyCurrentHigh;			/**< 전류 상한 mA */
	int nSafetyCurrentLow;			/**< 전류 하한 mA */
	int nSafetyAhHigh;				/**< 용량 상한 mAh */
	int nSafetyAhLow;				/**< 용량 하한 mAh */
	
	int nReserved[12];				/**< 미사용 */
};

//TEST 구조체
struct DEBUG_TEST
{
	int nTest;
	float fTest;
};
