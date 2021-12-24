/** 
 *@file		struct.h
 *@brief	����ü�� �����մϴ�.								
 *@author	PNE Solution (Kang se-jun)
 *@date		2019-03-22
 */

//SFT_CAN_VALUE
/**
	@brief CAN Value ����ü
	����!! : ����ü�� �ƴ� ����ü�Դϴ�.
	�� ����ü�� Total Size �� 8Bytes �Դϴ�.
*/
union CTS_CAN_VALUE{
	long	lVal[2]; /**< 8 Byte ���� */
	float	fVal[2]; /**< 8 Byte �Ǽ� */
	char	strVal[8]; /**< 8 Byte ���ڿ� */
};

/**
	@brief Aux Data D version ����ü
*/
typedef struct CTS_AUX_DATA_D
{
	short int	chNo;						/**< Aux Channel ��ȣ */
	short int	chType;						/**< Aux Type (0:�µ�, 1:����, 2:�µ�(��̽���)) */	
	long		lValue;						/**< Aux �� */
};

//SFT_CH_DATA
/**
	@brief Channel Data ����ü
*/
struct CTS_CH_DATA		
{
	unsigned char	chNo;					/**< Channel Number	(0-Base, ex. 1�� ä���� ��� 1, 3�� ä���� ��� 3) */
	unsigned char	chState;				/**< ä�� ��� ���� \ref define_state_ch */
	unsigned char	chStepType;				/**< ä�� ���� ���� \ref chStepType */
	unsigned char	chMode;					/**< Step�� ����/���� Mode (���� �� ���� ���� �����ϰ� �Ͽ� ����/�����ϱ� ���� mode) \ref chMode */
	unsigned char	chDataSelect;			/**< data ���� ���(0:For Display Data, 1 or �׿�:For Saving Data (1:Step End, �׿�:raw data) */
	unsigned char	chCode;					/**< ä�� �ڵ�(���� �� ���� ����) \ref ChannelCode */
	unsigned char	chStepNo;				/**< ���� ��ȣ */
	unsigned char	chGradeCode;			/**< ATS �ʿ� ����, Grade Code */
	long			lVoltage;				/**< ���� (uV) */
	long			lCurrent;				/**< ���� (uA) */	
	long			lChargeAh;				/**< �����뷮 (uA) */
	long			lDisChargeAh;			/**< �����뷮 (uA) */
	long			lCapacitance;			/**< Capacitance (uF) */
	long			lWatt;					/**< Watt (mW) */
	
	long			lChargeWh;				/**< Charge Wh (mW) */
	long			lDisChargeWh;			/**< Discharge Wh (mW) */
	unsigned long	ulStepDay;				/**< ���� ���� �ð�(day) */
	unsigned long	ulStepTime;				/**< ���� ���� �ð� (10msec), sec = ulStepTime/100.0f */
	unsigned long	ulTotalDay;				/**< ���� ���� �ð�(day) */
	unsigned long	ulTotalTime;			/**< ���� ���� �ð� (10msec), sec = ulTotalTime/100.0f */
	long			lImpedance;				/**< DC ���װ� (uohm) */
	unsigned char	chReservedCmd;			/**< Ŀ�ǵ� ���� ���� (0:None, 1:Stop, 2:Pause) */
	unsigned char	chCommState;			/**< ��� ���� Bit LSB(0:����, 1:�̻�) 1st bit:Aux �µ� ��� ����, 2nd bit:Aux ���� ��� ����, 3rd bit:CAN Master ��Ż���, 4th bit: CAN Slave ��Ż��� (ex. bit : 0000 0001�̸� Aux �µ� ��� ���� �̻�) */	
	unsigned char	chOutputState;			/**< ATS �ʿ� ����, ��� ���� Bit LSB(0:����, 1:�̻�) 1st bit:keyOn, 2nd bit:ChargeOn, 3rd bit:PackRealyOn */
	unsigned char	chInputState;			/**< ATS �ʿ� ����,�Է� ���� */
	short	 int	nAuxCount;				/**< Aux ���� */
	short	 int	nCanCount;				/**< Can ���� */

	unsigned long	nTotalCycleNum;			/**< ��ü Cycle ���� */
	unsigned long	nCurrentCycleNum;		/**< ���� Cycle �� */
	unsigned long	nAccCycleGroupNum1;		/**< �׷�1 ���� Cycle ���� */
	unsigned long	nAccCycleGroupNum2;		/**< �׷�2 ���� Cycle ���� */
	unsigned long	nAccCycleGroupNum3;		/**< �׷�3 ���� Cycle ���� */
	unsigned long	nAccCycleGroupNum4;		/**< �׷�4 ���� Cycle ���� */
	unsigned long	nAccCycleGroupNum5;		/**< �׷�5 ���� Cycle ���� */
	unsigned long	nMultiCycleGroupNum1;	/**< �׷�1 Multi Cycle ���� */
	unsigned long	nMultiCycleGroupNum2;	/**< �׷�2 Multi Cycle ���� */
	unsigned long	nMultiCycleGroupNum3;	/**< �׷�3 Multi Cycle ���� */
	unsigned long	nMultiCycleGroupNum4;	/**< �׷�4 Multi Cycle ���� */
	unsigned long	nMultiCycleGroupNum5;	/**< �׷�5 Multi Cycle ���� */
	long			lAvgVoltage;			/**< ���� ���� ��� ���� (uV) */
	long			lAvgCurrent;			/**< ���� ���� ��� ���� (uA) */
	long			lSaveSequence;			/**< ��⿡�� �����ϴ� Data�� ���� ��ȣ */
	unsigned long	ulCVDay;				/**< CV �ð�(Day) */
	unsigned long	ulCVTime;				/**< CV �ð� (10msec), sec = ulCVTime/100.0f*/
	long			lSyncTime[2];			/**< ���� �����Ϳ� ���� �ð����� YYYYMMDD HHMMSS.mmm ��ȯ ������ �ð� 20080723 214055.123	 */

	long			lVoltage_Input;			/**< ATS �ʿ� ����, ���� �Է� */
	long			lVoltage_Power;			/**< ATS �ʿ� ����, ���� �Ŀ� */
	long			lVoltage_Bus;			/**< ATS �ʿ� ����, ���� ���� */
	unsigned char	cUsingChamber;			/**< ATS �ʿ� ����, è�� ���� */
	unsigned char	cRecordTimeNo;			/**< ATS �ʿ� ����, (1 base : R1,R2,R3) */
	unsigned char	cOutMuxUse;				/**< ATS �ʿ� ����, �Խ� ��� (0:not use, 1:use) */
	unsigned char	cOutMuxBackup;			/**< ATS �ʿ� ����, �Խ� ���� (0:open, 1:Mux A, 2:Mux B) */
	long			lreserved[6];			/**< ���� */
};

//SFT_AUX_DATA
/**
	@brief Aux Data ����ü (Module�� setting �ϴ� ���̸� Max 512��)
*/
struct CTS_AUX_DATA
{
	short int		auxChNo; /**< Aux Channel ��ȣ */
	unsigned char	auxChType;	/**< Aux Type (0:�µ�, 1:����, 2:�µ�(��̽���)) */	
	unsigned char	auxTempTableType; /**< ��̽��� �µ� ���̺�(��񸶴� ���� ���� �޶� ��񿡼� Ȯ�� �� ����)	 */
	long			lValue; /**< Aux �� (�µ�: 1000 == 1��, Voltage: uV, �µ�: 1000000 == 1��) */
};


//SFT_CAN_DATA
/**
	@brief CAN DATA ����ü (Channel�� setting �ϴ� ���̸� Max 512��)
*/
struct CTS_CAN_DATA {
	unsigned char		canType;			 /**< CAN Ÿ�� (0:master, 1:slave) */
	unsigned char		data_type;			 /**< DATA Ÿ�� (0:signed, 1:unsigned, 2:string) */
	short int			function_division;	 /**< Division Code */
	CTS_CAN_VALUE		canVal;				 /**< Can Value */
};

//SFT_VARIABLE_CH_DATA
//����** SFT_VARIABLE_CH_DATA != CTS_VARIABLE_CH_DATA
/**
	@brief CTS ���� ä�� ������ ����ü
*/
struct CTS_VARIABLE_CH_DATA
{
	CTS_CH_DATA 		chData;								/**< �⺻ ä�� ������ */
	CTS_AUX_DATA		auxData[CTS_MAX_MAPPING_AUX];		/**< Aux Data */
	CTS_CAN_DATA		canData[CTS_MAX_MAPPING_CAN];		/**< Can Data */	
};


//CAN////////////////////////////////////////////////////////////////////

//SFT_CAN_COMMON_DATA
/**
	@brief CAN ��� ���� ������
*/
struct CTS_CAN_COMMON_DATA {
	unsigned char		can_baudrate;			/**< Can ��� Baudrate (0:125k, 1:250k, 2:500k, 3:1M) */
	unsigned char		extended_id;			/**< Ȯ�� ID (0:unused, 1:used) */
	unsigned char		bms_type;				/**< BMS Ÿ�� (ATS���� default:0 ���� ����) */
	unsigned char		bms_sjw;				/**< BMS SJW (ATS���� default:0 ���� ����) */
	
	long				controller_canID;		/**< ��Ʈ�ѷ� Can ID */
	long				mask[2];				/**< Mask */
	long				filter[6];				/**< Filter */

	unsigned char		can_fd_flag;			/**< CAN FD Flag (0:can 2.0B, 1: can_fd) */
	unsigned char		can_datarate;			/**< CAN Data Rate (0:500K, 1:833K, 2:1M, 3:1.5M, 4:2M, 5.3M) */
	unsigned char		terminal_r;				/**< Terminal ���� (0:open, 1:120ohm<default>) */
	unsigned char		crc_type;				/**< CRC Ÿ�� (0:non iso crc, 1:iso crc<default>) */

	unsigned char		can_lin_select;			/**< CAN/LIN ���� (0:can, 1:Lin) */
	unsigned char		c_Reserved[3];			/**< ���� ���� */
	long				l_Reserved_2;				/**< ���� ���� */	

	short int			can_function_division[10];	/**< �з� ��ȣ */
	unsigned char		can_compare_type[10];		/**< CAN �� �� (type 0:��� ����, 1:<, 2:<=, 3:==, 4:>, 5:=>) */
	unsigned char		can_data_type[10];			/**< CAN �� �� (type 0:��� ����, 1:signed, 2:float) */
	float				f_Reserved[10];				/**< ���� ���� */
};

//SFT_CAN_SET_DATA
/**
	@brief CAN ��� ���� ������
*/
struct CTS_CAN_SET_DATA {
	unsigned char		canType;				/**< Can Ÿ�� (0:unused, 1:master, 2:slave) */
	unsigned char		byte_order;				/**< Byte order (0:intel, 1:motolora) */
	unsigned char		data_type;				/**< Data Ÿ�� (0:signed, 1:unsigned, 2:string, 3:float, 4:bit) */
	unsigned char		c_Reserved;				/**< ���� ���� */	

	float				factor_multiply;		/**< ��� �� : ���ϱ�, ���� �� : ������ */
	short int			startBit;				/**< start bit */
	short int			bitCount;				/**< bit count */
	long				canID;					/**< Can ID hex value */
	char				name[128];				/**< �̸� */
	float				fault_upper;			/**< ���� ���� */
	float				fault_lower;			/**< ���� ���� */
	float				end_upper;				/**< ���� ���� */
	float				end_lower;				/**< ���� ���� */
	float				default_fValue;			/**< �⺻ �� ���� */ 
	float				factor_Offset;			/**< ���� ������ */	
	short int			function_division;		/**< �з� �ڵ�(1001 ~ 1200) */
	short int			function_division2;		/**< �з� �ڵ�(1001 ~ 1200) */
	short int			function_division3;		/**< �з� �ڵ�(1001 ~ 1200) */
	short int			ui_Reserved;			/**< ���� ���� */	
	long				sentTime;				/**< ���� �ð� */	
	long				l_Reserved[2];			/**< ���� ���� */	

	short int			startBit2;				/**< start bit2 */	
	short int			bitCount2;				/**< bit count2 */	
	unsigned char		byte_order2;			/**< Byte order (0:intel, 1:motolora) */
	unsigned char		data_type2;				/**< Data Ÿ�� (0:signed, 1:unsigned, 2:string, 3:float, 4:bit) */
	unsigned char		c_Reserved2[2];			/**< ���� ���� */	
	float				default_fValue2;		/**< �⺻ �� ����2 */ 
};

//����** SFT_VARIABLE_CH_DATA_D != CTS_VARIABLE_CH_DATA
/**
	@brief Channel Data D version ����ü
*/
typedef struct CTS_VARIABLE_CH_DATA_D
{
	CTS_CH_DATA 	chData;							/**< �⺻ ä�� ������ */
	CTS_AUX_DATA_D	auxData[CTS_MAX_MAPPING_AUX];	/**< Aux Data */
	CTS_CAN_DATA	canData[CTS_MAX_MAPPING_CAN];	/**< Can Data */	
};

//����** SFT_VARIABLE_CH_DATA_F != CTS_VARIABLE_CH_DATA
/**
	@brief CTS F Version ���� ä�� ������ ����ü
*/
typedef struct CTS_VARIABLE_CH_DATA_F
{			
	CTS_CH_DATA 	chData;							/**< �⺻ ä�� ������ */
	CTS_AUX_DATA	auxData[CTS_MAX_MAPPING_AUX];	/**< Aux Data */
	CTS_CAN_DATA	canData[CTS_MAX_MAPPING_CAN];	/**< Can Data */	
};	

//SFT_RCV_CMD_CAN_SET
/**
	@brief Can ���� ���� ������ ����
*/
struct CTS_RCV_CMD_CAN_SET {
	CTS_CAN_COMMON_DATA	canCommonData[CTS_MAX_INSTALL_CH_COUNT][2];					/**< CAN ���� ���� Data */
	CTS_CAN_SET_DATA	canSetData[CTS_MAX_INSTALL_CH_COUNT][CTS_MAX_MAPPING_CAN];	/**< CAN ���� ���� Data */
} ;


//SFT_RCV_CMD_CHANNEL_CAN_SET
/**
	@brief Can ���� ���� ������ ����(ä�κ�)
*/
struct CTS_RCV_CMD_CHANNEL_CAN_SET{
	CTS_CAN_COMMON_DATA	canCommonData[2];						/**< CAN ���� ���� Data */
	CTS_CAN_SET_DATA	canSetData[CTS_MAX_MAPPING_CAN];		/**< CAN ���� ���� Data */
};

//SFT_MD_CAN_INFO_DATA
/**
	@brief ��ü CAN ���� ���� ������
*/
struct CTS_MD_CAN_INFO_DATA {
	short int installedCanCount[CTS_MAX_INSTALL_CH_COUNT];		/**< ä�κ� ��ġ�� Can �� */
	CTS_RCV_CMD_CAN_SET	canSetAllData;							/**< CAN ���� ���� Data */
};


//CAN Transmit////////////////////////////////////////////////////////
//SFT_CAN_COMMON_TRANS_DATA
//SFT_VARIABLE_CH_DATA
/**
	@brief Can ���� ���� Data
*/
struct CTS_CAN_COMMON_TRANS_DATA {
	unsigned char		can_baudrate;		/**< CAN ��� Baoudrate (0:125k, 1:250k, 2:500k, 3:1M) */
	unsigned char		extended_id;		/**< extended id (0:unused, 1:used) */
	unsigned char		bms_type;			/**< BMS Ÿ�� (ATS���� default:0 ���� ����) */
	unsigned char		bms_sjw;			/**< BMS SJW (ATS���� default:0 ���� ����) */
	long				l_Reserved;			/**< ���� ���� */

	unsigned char		can_fd_flag;		/**< CAN FD Flag (0:can 2.0B, 1:can_fd) */
	unsigned char		can_datarate;		/**< CAN Data Rate (0:500K, 1:833K, 2:1M, 3:1.5M, 4:2M, 5.3M)*/
	unsigned char		terminal_r;			/**< CAN Terminal ���� (0:open, 1:120ohm<default>) */
	unsigned char		crc_type;			/**< CRC Ÿ�� (0:non iso crc, 1:iso crc<default>) */

	unsigned char		can_lin_select;		/**< CAN/LIN ���� (0:can, 1:Lin) */
	unsigned char		c_Reserved[3];		/**< ���� ���� */	

	short int can_function_division[10];	/**< �з� �ڵ� (10010 ~ 10014)*/
	unsigned char can_compare_type[10];		/**< can ���� �񱳴�� -> �� type (0:��� ����, 1:<, 2:<=, 3:==, 4:>, 5:=>)*/
	unsigned char can_data_type[10];		/**< can ���� �񱳴�� -> �� type (0:��� ����, 1:signed, 2:float) */
	float	f_Reserved[10];					/**< ���� ���� */
};

//SFT_CAN_SET_TRANS_DATA
/**
	@brief Can ���� ���� Data
*/
struct CTS_CAN_SET_TRANS_DATA {
	unsigned char		canType;			/**< Can Ÿ�� (0:unused, 1:master, 2:slave) */
	unsigned char		byte_order;			/**< Byte order (0:intel, 1:motolora) */
	unsigned char		data_type;			/**< Data Ÿ�� (0:signed, 1:unsigned, 2:string, 3:float , 4:bit) */
	unsigned char		dlc;				/**< 0 bit : capvtg , 1 bit : mcu temp */  
	float				factor_multiply;	/**< ��� �� : ���ϱ�, ���� �� : ������ */
	float				default_fValue;		/**< �⺻ �� ���� */ 
	short int			startBit;			/**< start bit */
	short int			bitCount;			/**< bit count */
	long				canID;				/**< Can ID hex value */
	long				send_time;			/**< ���ۼӵ�(ms) */
	char				name[128];			/**< �̸� */
	long				l_Reserved;			/**< ���� ���� */	
	
	float				factor_Offset;		/**< ���� ������ */	
	short int			function_division;	/**< �з� �ڵ� (10010 ~ 10014) */
	short int			function_division2;	/**< �з� �ڵ� (10010 ~ 10014) */
	short int			function_division3;	/**< �з� �ڵ� (10010 ~ 10014) */
	short int			ui_Reserved;		/**< ���� ���� */	
	long				l_Reserved2[2];		/**< ���� ���� */	
};



//SFT_TRANS_CMD_CAN_SET
/**
	@brief Can ���� ���� ������ ����
*/
struct CTS_TRANS_CMD_CAN_SET {
	CTS_CAN_COMMON_TRANS_DATA	canCommonData[CTS_MAX_INSTALL_CH_COUNT][2];					/**< CAN ���� ���� Data */
	CTS_CAN_SET_TRANS_DATA	canSetData[CTS_MAX_INSTALL_CH_COUNT][CTS_MAX_MAPPING_CAN];		/**< CAN ���� ���� Data */
};

//SFT_TRANS_CMD_CHANNEL_CAN_SET
/**
	@brief Can ���� ���� ������ ����(ä�κ�)
*/
struct CTS_TRANS_CMD_CHANNEL_CAN_SET {
	CTS_CAN_COMMON_TRANS_DATA	canCommonData[2];					/**< CAN ���� ���� Data */
	CTS_CAN_SET_TRANS_DATA	canSetData[CTS_MAX_MAPPING_CAN];		/**< CAN ���� ���� Data */
};

//SFT_MD_CAN_TRANS_INFO_DATA
/**
	@brief Can ���� ���� ������
*/
struct CTS_MD_CAN_TRANS_INFO_DATA {
	short int installedCanCount[CTS_MAX_INSTALL_CH_COUNT];		/**< ä�� ���庰 ��ġ�� CAN ����*/
	CTS_TRANS_CMD_CAN_SET	canSetAllData;						/**< CAN ���� ���� ������ ���� */
};

//SFT_MD_CAN_INFO_DATA
/**
	@brief Can ���� ���� ������
*/
struct CTS_MD_CAN_RECV_INFO_DATA {
	short int installedCanCount[CTS_MAX_INSTALL_CH_COUNT];		/**< ä�� ���庰 ��ġ�� CAN ����*/
	CTS_RCV_CMD_CAN_SET	canSetAllData;							/**< CAN ���� ���� ������ ���� */
};

//SFT_MD_PARALLEL_DATA
/**
	@brief ���� ��� ���� ������
*/
struct CTS_MD_PARALLEL_DATA{

	unsigned char chNoMaster;			/**< Master Channel Number (1-Base, ex. 1�� ä���� ��� 1, 3�� ä���� ��� 3) */
	unsigned char chNoSlave[3];			/**< Slave Channel Number 3������ Slave ����	(1-Base, ex. 1�� ä���� ��� 1, 3�� ä���� ��� 3) */	
	unsigned char bParallel;			/**< ���� ��� Flag (0:���� ����, 1:���� ����) */	
	unsigned char reserved[3];			/**< ���� ���� */	
	unsigned char reserved2[4];			/**< ���� ���� */	
};

//s_SFT_CMD_INFO_DATA, SFT_CMD_INFO_DATA
/**
	@brief ������� ���� ���� ������
*/
struct CTS_MD_SYSTEM_DATA {
	unsigned int		nModuleID;							/**< ��� ID (Module������ GroupID, Host������ ModuleID) */
	unsigned int		nSystemType;						/**< ���� Ÿ�� (Formation/IROCV/Aging/Grader/Selector) */
	unsigned int		nProtocolVersion;					/**< ����� ��� �������� ���� (Protocol Version) */
	char				szModelName[128];					/**< Module Model Name */
	unsigned int		nOSVersion;							/**< System Version  */
	unsigned short int	wVoltageRange;						/**< ���� Range �� */
	unsigned short int	wCurrentRange;						/**< ���� Range �� */
	unsigned int		nVoltageSpec[5];					/**< ���� Range �� Spec (uV) */
	unsigned int		nCurrentSpec[5];					/**< ���� Range �� Spec (uA) */
	unsigned char		byCanCommType;						/**< CAN ��� Ÿ�� (0:CAN 2.0, 1:CAN FD) */
	unsigned char		byTypeData[7];						/**< ATS �ʿ� ����, Module Location, Line No, Module Type, Etc...	 */
	unsigned short int	wInstalledBoard;					/**< ��ġ ���� �� (Total Board Number in one Module) */
	unsigned short int	wChannelPerBoard;					/**< ����� ä�� �� (Total Channel Per Board) */
	unsigned int		nInstalledChCount;					/**< ��ü ä�� �� */
	unsigned int		nTotalJigNo;						/**< ATS �ʿ� ����, ��ü ���� �� */
	unsigned int		awBdInJig[16];						/**< ATS �ʿ� ����, ���� �� ���� �� */
	unsigned int		reserved[4];						/**< ���� ���� */	
};

// SFT_SYSTEM_PARAM
/**
	@brief ������� �ý��� �Ķ���� ���� ����
*/
struct CTS_SYSTEM_PARAM {			
	char		szIPAddr[CTS_IP_NAME_LENGTH];		/**< IP �ּ� */
	LONG		lModuleType;						/**< ��� Ÿ��*/
	WORD		wVRangeCount;						/**< ���� ������ ���� */
	WORD		wIRangeCount;						/**< ���� ������ ���� */
	LONG		lVSpec[CTS_MAX_VOLTAGE_RANGE];		/**< �������� ���� ���� */
	LONG		lISpec[CTS_MAX_CURRENT_RANGE];		/**< �������� ���� ���� */
	WORD		wInstallChCount;					/**< ��ü ä�� �� */
	BOOL		bAutoProcess;						/**< ATS �ʿ� ����, �ڵ� ���� ����*/
	long		lMaxVoltage;						/**< �ִ� ���� (uV)*/
	long		lMinVoltage;						/**< �ּ� ���� (uV)*/
	long		lMaxCurrent;						/**< �ִ� ���� (uA)*/
	long		lMinCurrent;						/**< �ּ� ���� (uA)*/
	long		lMaxTemp;							/**< ATS �ʿ� ����, �µ� ����ġ */
	BOOL		bUseTempLimit;						/**< ATS �ʿ� ����, �µ� Limit ��� ���� */
	long		lMaxGas;							/**< ATS �ʿ� ����, ���� ����ġ */
	long		bUseGasLimit;						/**< ATS �ʿ� ����, ���� Limit ��� ���� */
	WORD		wModuleType;						/**< ATS �ʿ� ����, Module �� ���� (������/����)==> Tray�� �迭�� ����. */
	WORD		nAutoReportInterval;				/**< ATS �ʿ� ����, �ڵ� ���� �ð� ����  */
};


//STF_MD_AUX_SET_DATA
/**
	@brief Aux ���� ������
*/
struct CTS_MD_AUX_SET_DATA{
	unsigned char chNo;					/**< ������� ä�� ��ȣ (1-Base, ex. 1�� ä���� ��� 1, 3�� ä���� ��� 3) */
	unsigned char auxTempTableType;		/**< Thermistor Type (1:VW_MEB, 2:Volvo_CMA, 3:B10XLR, 4:103AT, 5:TC310F34BPEP, 6:103AT_2) */
	unsigned char reserved[2];			/**< ���� ���� */
	short	auxChNo;					/**< Aux ä�� ��ȣ (1-Base, ex. 1�� ä���� ��� 1, 3�� ä���� ��� 3) */
	short	auxType;					/**< AUX Type (0:�µ�����, 1:Voltage, 2:�µ�����(Thermistor) 3:��������(v1016~))	 */
	char	szName[128];				/**< Aux �̸� */
	long	lMaxData;					/**< ������ ���Ѱ� (�µ�: 1000 == 1��, Voltage: uV, �µ�: 1000000 == 1��) */
	long	lMinData;					/**< ������ ���Ѱ� (�µ�: 1000 == 1��, Voltage: uV, �µ�: 1000000 == 1��) */
	long	lEndMaxData;				/**< ���� ���Ѱ� (�µ�: 1000 == 1��, Voltage: uV, �µ�: 1000000 == 1��) */
	long	lEndMinData;				/**< ���� ���Ѱ� (�µ�: 1000 == 1��, Voltage: uV, �µ�: 1000000 == 1��) */

	short int	funtion_division1;		/**< �з� �ڵ� (2001 ~ 2200) */	
	short int	funtion_division2;		/**< �з� �ڵ� (2001 ~ 2200) */ 
	short int	funtion_division3;		/**< �з� �ڵ� (2001 ~ 2200) */
	short int	reserved2;				/**< ���� ���� */
};


//CTS_MD_AUX_SET_DATA_16
/**
	@brief Aux ���� ������ (V1016 ���� ��� ����ü)
*/
struct CTS_MD_AUX_SET_DATA_16{	
	unsigned char chNo;					/**< ������� ä�� ��ȣ (1-Base, ex. 1�� ä���� ��� 1, 3�� ä���� ��� 3) */
	unsigned char auxTempTableType;		/**< Thermistor Type (1:VW_MEB, 2:Volvo_CMA, 3:B10XLR, 4:103AT, 5:TC310F34BPEP, 6:103AT_2) */
	unsigned char reserved[2];			/**< ���� ���� */
	short	auxChNo;					/**< Aux ä�� ��ȣ (1-Base, ex. 1�� ä���� ��� 1, 3�� ä���� ��� 3) */
	short	auxType;					/**< AUX Type (0:�µ�����, 1:Voltage, 2:�µ�����(Thermistor) 3:��������(v1016~))	 */
	char	szName[128];				/**< Aux �̸� */
	long	lMaxData;					/**< ������ ���Ѱ� (�µ�: 1000 == 1��, Voltage: uV, �µ�TH: 1000000 == 1��, ����: 1000000 == 1%) */
	long	lMinData;					/**< ������ ���Ѱ� (�µ�: 1000 == 1��, Voltage: uV, �µ�TH: 1000000 == 1��, ����: 1000000 == 1%) */
	long	lEndMaxData;				/**< ���� ���Ѱ� (�µ�: 1000 == 1��, Voltage: uV, �µ�TH: 1000000 == 1��, ����: 1000000 == 1%) */
	long	lEndMinData;				/**< ���� ���Ѱ� (�µ�: 1000 == 1��, Voltage: uV, �µ�TH: 1000000 == 1��, ����: 1000000 == 1%) */
	
	long	lVentSafetyMax;				/**< ���� ���� ���� ���� (V1016~), �Ͻ����� �� è�� ����(��� ������), 0�Է½� ���� ���� */
	long	lVentSafetyMin;				/**< ���� ���� ���� ���� (V1016~), �Ͻ����� �� è�� ����(��� ������), 0�Է½� ���� ���� */

	short int	funtion_division1;		/**< �з� �ڵ� (2001 ~ 2200) */	
	short int	funtion_division2;		/**< �з� �ڵ� (2001 ~ 2200) */ 
	short int	funtion_division3;		/**< �з� �ڵ� (2001 ~ 2200) */
	short int	reserved2;				/**< ���� ���� */	
};

		
//s_SFT_AUX_INFO_DATA
/**
	@brief Installed Aux Data Format (V100D ~ V1015)
*/
struct CTS_AUX_INFO_DATA {

	unsigned char chNo;					/**< ������� ä�� ��ȣ (1-Base, ex. 1�� ä���� ��� 1, 3�� ä���� ��� 3) */
	unsigned char reserved[3];			/**< ���� ���� */
	short int	auxChNo;				/**< Aux ä�� ��ȣ (1-Base, ex. 1�� ä���� ��� 1, 3�� ä���� ��� 3) */
	short int	auxType;				/**< AUX Type (0:�µ�����, 1:Voltage, 2:�µ�����(Thermistor) 3:��������(v1016~))	 */
	char		szName[128];			/**< Aux �̸� */
	long		upper_limit;			/**< ������ ���Ѱ� (�µ�: 1000 == 1��, Voltage: uV, �µ�: 1000000 == 1��) */
	long		lower_limit;			/**< ������ ���Ѱ� (�µ�: 1000 == 1��, Voltage: uV, �µ�: 1000000 == 1��) */
	long		reserved1[4];			/**< ���� ���� */
#if 0
	unsigned char chNo;					/**< ������� ä�� ��ȣ (1-Base, ex. 1�� ä���� ��� 1, 3�� ä���� ��� 3) */
	unsigned char auxTempTableType;		/**< Thermistor Type (1:VW_MEB, 2:Volvo_CMA, 3:B10XLR, 4:103AT, 5:TC310F34BPEP, 6:103AT_2, \n ��񸶴� ���� ���� �޶� ��񿡼� Ȯ�� �� �����ؾ� ��)	 */
	unsigned char reserved[2];			/**< ���� ���� */
	short	auxChNo;					/**< Aux ä�� ��ȣ (1-Base, ex. 1�� ä���� ��� 1, 3�� ä���� ��� 3) */
	short	auxType;					/**< AUX Type (0:�µ�����, 1:Voltage, 2:�µ�����(Thermistor))	 */
	char	szName[128];				/**< Aux �̸� */
	long	lMaxData;					/**< ������ ���Ѱ� (�µ�: 1000 == 1��, Voltage: uV, �µ�: 1000000 == 1��) */
	long	lMinData;					/**< ������ ���Ѱ� (�µ�: 1000 == 1��, Voltage: uV, �µ�: 1000000 == 1��) */
	long	lEndMaxData;				/**< ���� ���Ѱ� (�µ�: 1000 == 1��, Voltage: uV, �µ�: 1000000 == 1��) */
	long	lEndMinData;				/**< ���� ���Ѱ� (�µ�: 1000 == 1��, Voltage: uV, �µ�: 1000000 == 1��) */

	short int	funtion_division1;		/**< �з� �ڵ� (2001 ~ 2200) */	
	short int	funtion_division2;		/**< �з� �ڵ� (2001 ~ 2200) */ 
	short int	funtion_division3;		/**< �з� �ڵ� (2001 ~ 2200) */
	short int	reserved2;				/**< ���� ���� */
#endif
};


//s_SFT_AUX_INFO_DATA_TYPE2
/**
	@brief Installed Aux Data Format (V1016~)
*/
struct CTS_AUX_INFO_DATA_16 {
	unsigned char chNo;					/**< ������� ä�� ��ȣ (1-Base, ex. 1�� ä���� ��� 1, 3�� ä���� ��� 3) */
	unsigned char auxTempTableType;		/**< Thermistor Type (1:VW_MEB, 2:Volvo_CMA, 3:B10XLR, 4:103AT, 5:TC310F34BPEP, 6:103AT_2, \n ��񸶴� ���� ���� �޶� ��񿡼� Ȯ�� �� �����ؾ� ��)	 */
	unsigned char vent_use_flag;		/**< ���� ����/���� ���۽� è�� Vent ���� ��� ��� ���� 0: �̻�� 1: ��� */
	unsigned char reserved1;			/**< ���� ���� */
	short	auxChNo;					/**< Aux ä�� ��ȣ (1-Base, ex. 1�� ä���� ��� 1, 3�� ä���� ��� 3) */
	short	auxType;					/**< AUX Type (0:�µ�����, 1:Voltage, 2:�µ�����(Thermistor) 3:��������(v1016~))	 */
	char	szName[128];				/**< Aux �̸� */
	long	upper_limit;				/**< ������ ���Ѱ� (�µ�: 1000 == 1��, Voltage: uV, �µ�: 1000000 == 1��, ����: 1000000 == 1%) */	
	long	lower_limit;				/**< ������ ���Ѱ� (�µ�: 1000 == 1��, Voltage: uV, �µ�: 1000000 == 1��, ����: 1000000 == 1%) */
	long	lEndMaxData;				/**< ���� ���Ѱ� (�µ�: 1000 == 1��, Voltage: uV, �µ�: 1000000 == 1��, ����: 1000000 == 1%) */
	long	lEndMinData;				/**< ���� ���Ѱ� (�µ�: 1000 == 1��, Voltage: uV, �µ�: 1000000 == 1��, ����: 1000000 == 1%) */
	
	long	lVentSafetyMax;				/**< ��� ���� ���� ���� ���Ѱ� (�µ�: 1000 == 1��, Voltage: uV, �µ�: 1000000 == 1��, ����: 1000000 == 1%) , è�� ��� ������ Vent ���� ��� ����*/
	long	lVentSafetyMin;				/**< ��� ���� ���� ���� ���Ѱ� (�µ�: 1000 == 1��, Voltage: uV, �µ�: 1000000 == 1��, ����: 1000000 == 1%) , è�� ��� ������ Vent ���� ��� ����*/

	short int	funtion_division1;		/**< �з� �ڵ� (2001 ~ 2200) */		
	short int	funtion_division2;		/**< �з� �ڵ� (2001 ~ 2200) */	
	short int	funtion_division3;		/**< �з� �ڵ� (2001 ~ 2200) */	
	short int	reserved2;				/**< ���� ���� */
};


//SFT_MD_AUX_INFO_DATA
/**
	@brief �ܺ�(aux) Data ���� ������  (V100D~V1015)
*/
struct CTS_MD_AUX_INFO_DATA
{
	short int	wInstalledTemp;							/**< Aux �µ� ���� */	
	short int	wInstalledVolt;							/**< Aux ���� ���� */	
	short int	wInstalledTempTh;						/**< �µ� Thermistor ���� */	
	short int	reserved;								/**< ���� ���� */	
	CTS_AUX_INFO_DATA auxData[CTS_MAX_MAPPING_AUX];		/**< Aux ä�κ� ���� */	
};

//SFT_MD_AUX_INFO_DATA
/**
	@brief �ܺ�(aux) Data ���� ������ (V100D~V1015)
*/
struct CTS_MD_AUX_INFO_DATA_V2
{
	short int	wInstalledTemp;							/**< Aux �µ� ���� */	
	short int	wInstalledVolt;							/**< Aux ���� ���� */	
	short int	wInstalledTempTh;						/**< �µ� Thermistor ���� */	
	short int	reserved;								/**< ���� ���� */	
	CTS_MD_AUX_SET_DATA auxData[CTS_MAX_MAPPING_AUX];		/**< Aux ä�κ� ���� */	 //CTS_AUX_INFO_DATA�� size ����.
};

//CTS_MD_AUX_INFO_DATA_TYPE2
/**
	@brief �ܺ�(aux) Data ���� ������ (V1016~)
*/
struct CTS_MD_AUX_INFO_DATA_16
{
	short int	wInstalledTemp;							/**< Aux �µ� ���� */	
	short int	wInstalledVolt;							/**< Aux ���� ���� */	
	short int	wInstalledTempTh;						/**< �µ� Thermistor ���� */	
	short int	wInstalledHumi;							/**< ���� ���� Aux ���� */	
	CTS_AUX_INFO_DATA_16 auxData[CTS_MAX_MAPPING_AUX];		/**< Aux ä�κ� ���� */	
};


//SFT_EMG_DATA
/**
	@brief Emergency �˶� ����ü
*/
struct CTS_EMG_DATA
{
	short int	wCode;			/**< EMG �ڵ� \ref EmgCode*/
	short int	wValue;			/**< EMG �� */
	long		reserved;		/**< ���� ���� */
	char		szName[128];	/**< EMG �̸� */
};

/**
	@brief Schedule File�� Step �⺻���� Ȯ�� ����ü
	* ��� ������ ���������� ������, �ֿ� ���� ����� �����Ѵ�.
*/
struct CTS_SCH_STEP_INFO
{
	int			nStepType;				/**< ���� Type */
	BYTE		stepNo;					/**< ���� Step ��ȣ(1 Base) */
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
	@brief Schedule File�� Cell Balancing ���� ���� ���� Ȯ�� ����ü
*/
struct CTS_SCH_EXT_CB_INFO
{
	BYTE	stepNo;						/**< ���� Step ��ȣ(1 Base) */
	BYTE	reserved[3];
	int     nCbCircuitRes;				/**< ȸ�� ���� �Է¹��� 10~100 */
	int     nCbWorkVoltLower;			/**< �뷱�� ���� ���� ���� (mV)*/
	int     nCbWorkVoltUpper;			/**< �뷱�� ���� ���� ���� (mV)*/
	int     nCbStartDeltaVolt;			/**< �뷱�� ���� ���� ���� (mV)*/
	int     nCbEndDeltaVolt;			/**< �뷱�� ���� ���� ���� (mV)*/
	int     nCbActiveTime;				/**< Active Time (3~99��) */
	int     nCbAutoStopTime;			/**< Auto Stop Time (��) */
	int     nCbAutoNextStep;			/**< Auto Next Step (0:�����������ǻ��, 1:�ڵ���������)*/
	ULONG	ulStepEndTime;				/**< ������ �ð� ���� ���� (��) ��: 30��(30),1�ð�30��(3630) 2��1�ð�30��(176430)*/
	int		nReserved[3];				/**< �̻��*/
};


/**
	@brief ��������� API ���� ����ü
*/
struct CTS_SIMPLE_TEST_INFO {			
	//���� ����
	int nStepType;					/**< ����. Charge:1, Discharge:2, Rest:3, OCV:4  */
	int nMode;						/**< ���. CCCV:1, CC:2 CV:3 CP:6 */

	int nRefVoltage;				/**< ���� ���� mV */
	int nRefCurrent;				/**< ���� ���� mA */
	int nRefPower;					/**< ���� �Ŀ� mW */
	int nRecordTime;				/**< ��� �ð� (1/10��) ��) 1��:10 , 20��:200, 0.1��: 1 */

	//���� ����
	int nCutoffCondTime;			/**< ���� �ð� (��) */
	int nCutoffCondVolt;			/**< ���� ���� mV */
	int nCutoffCondCurrent;			/**< ���� ���� mA */
	int nCutoffCondAh;				/**< ���� �뷮 mAh */

	//���� ����
	int nSafetyVoltageHigh;			/**< ���� ���� mV */
	int nSafetyVoltageLow;			/**< ���� ���� mV */
	int nSafetyCurrentHigh;			/**< ���� ���� mA */
	int nSafetyCurrentLow;			/**< ���� ���� mA */
	int nSafetyAhHigh;				/**< �뷮 ���� mAh */
	int nSafetyAhLow;				/**< �뷮 ���� mAh */
	
	int nReserved[12];				/**< �̻�� */
};

//TEST ����ü
struct DEBUG_TEST
{
	int nTest;
	float fTest;
};
