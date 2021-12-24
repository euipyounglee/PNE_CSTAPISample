/** 
 *@file		ResponseCode.h
 *@brief	������ ��ɿ����� ���� ���� ��� ���� �Դϴ�.								
 *@author	PNE Solution (Kang se-jun)
 *@date		2019-03-22
 */


/** @defgroup ResponseCode SendCommand Response Code
 *  @ingroup define
 *  @brief
 * SendCommand Response Code\n
 *  @details
 * ������⿡ ������ ��ɿ� ���� ���� �ڵ��Դϴ�.
 *  @{
 */
//response of command code
#define		CTS_NACK					0x00000000	/*!< ���� (Error) */
#define		CTS_ACK						0x00000001	/*!< ���� (Normal) */
#define		CTS_TIMEOUT					0x00000002	/*!< �ð��ʰ� (Time over) */
#define		CTS_SIZE_MISMATCH			0x00000003	/*!< Body Size ����ġ (Size mismatch) */
#define		CTS_RX_BUFF_OVER_FLOW		0x00000004	/*!< ���� ���� �����÷ο� (Receive buffer overflow) */
#define		CTS_TX_BUFF_OVER_FLOW		0x00000005	/*!< �۽� ���� �����÷ο� (Transmit buffer overflow) */
#define		CTS_CONNECTED				0x00000006	/*!< ���� ���� (Connection success) */
#define		CTS_NOT_CONNECTED			0x00000007	/*!< ���� �Ǿ� ���� ���� (Not connected) */
#define		CTS_FILE_NOT_EXIST			0x00000008	/*!< �ش� ��ο� ������ ���� (Not exist file) */
#define		CTS_FILE_OPENED				0x00000009	/*!< ������ Open�Ǿ� ���� (File open fail) */
#define		CTS_CAN_LIN_TYPE_INVALID	0x0000000A	/*!< CAN Rx/Tx, LIN File Type�� ���� ���� (Type mismatch) */
#define		CTS_CHANNEL_RUN				0x0000000B	/*!< ���� �������� ä���� (Channel is running) */
#define		CTS_FAIL					0xFFFFFFFF	/*!< ���� (Failure) */
/** @} */ //SendCommand ResponseCode ���� ��


/** @defgroup SendScheduleResponseCode SendSchedule Response Code
 *  @ingroup define
 *  @brief
 * SendSchedule Response Code\n
 *  @details
 * ������ ���ۿ� ���� ���� �ڵ��Դϴ�.
 *  @{
 */
//response of command code
#define		CTS_SCHEDULE_FAIL										0x00000000	/*!< ������ ���� ���� \n (Schedule transmit fail) */
#define		CTS_SCHEDULE_OK											0x00000001	/*!< ������ ���� �Ϸ� \n (Schedule transmit success) */
#define		CTS_SCHEDULE_NOT_CONNECTED								0x00000002	/*!< ���� ����Ǿ� ���� ���� \n (Not connected module) */
#define		CTS_SCHEDULE_INVALID_CHANNEL							0x00000003	/*!< �߸� �� ä�� ���� \n (Invalid channel) */
#define		CTS_SCHEDULE_FILE_NOT_FOUND								0x00000004	/*!< ������ ���� ��ο� ���� \n (Not exist of schedule file path) */
#define		CTS_SCHEDULE_TEMP_INVALID								0x00000005	/*!< �µ� ������ �߸��Ǿ� �۾��� ���� �� �� ���� \n (Unable to start operation due to incorrect temperature setting) */
#define		CTS_SCHEDULE_AUX_INVALID								0x00000006	/*!< �ܺμ��� ���������� �߸��Ǿ� �۾��� ���� �� �� ���� \n (Unable to start operation due to incorrect safety condition setting) */
#define		CTS_SCHEDULE_STEP_SIZE_INVALID							0x00000007	/*!< ���� Size ���� \n (Step size error) */
#define		CTS_SCHEDULE_CHANNEL_RUN								0x00000008	/*!< �������� ä���̹Ƿ� �۾��� ���� �� �� ���� \n (Unable to start operation due to running channel) */
#define		CTS_SCHEDULE_NOT_SET_SAFTY_COND							0x00000009	/*!< ���� ���� ������ �����Ǿ� ���� ���� \n (Not set safety condition) */
#define		CTS_SCHEDULE_VALIDITY_FAIL								0x0000000A	/*!< ������ Validity check fail \n (Schedule validity check fail) */
#define		CTS_SCHEDULE_IP_ADDRESS_INVALID							0x0000000B	/*!< �������� ������� ��� IP �̻� \n (Module IP address incorrect) */
#define		CTS_SCHEDULE_FTP_CONNECT_FAIL							0x0000000C	/*!< �������� ������� FTP Server connect fail \n (FTP server connect fail) */
#define		CTS_SCHEDULE_FTP_FILE_INVALID							0x0000000D	/*!< �������� ������� FTP File �̻� \n (FTP server file error) */
#define		CTS_SCHEDULE_FILE_INVALID								0x0000000E	/*!< ���� �� �������� ���� \n (No schedule file) */
#define		CTS_SCHEDULE_PATTERN_FILE_INVALID						0x0000000F	/*!< Pattern file ���� \n (Pattern file failure) */
#define		CTS_SCHEDULE_PATTERN_FILE_CHECKSUM_INVALID				0x00000010	/*!< ������ file checksum ���� \n (Schedule file checksum error) */
#define		CTS_SCHEDULE_FTP_CREATE_FOLDER_FAIL						0x00000011	/*!< ������ ���ۿ� �ʿ��� ���� ���� ���� \n (Folder creation failed of schedule transmit) */
#define		CTS_SCHEDULE_FTP_CREATE_FILE_FAIL						0x00000012	/*!< �������� ������� FTP File create fail \n (FTP file create fail) */
#define		CTS_SCHEDULE_FTP_CHANGE_FOLDER_FAIL						0x00000013	/*!< �������� ������� FTP Change directory fail \n (FTP change directory fail) */
#define		CTS_SCHEDULE_FTP_ADD_FAIL								0x00000014	/*!< �������� ������� FTP File add fail \n (FTP file add fail) */
#define		CTS_SCHEDULE_FTP_PERMISSION_FAIL						0x00000015	/*!< �������� ������� FTP permission fail \n (FTP permission fail) */
#define		CTS_SCHEDULE_NOT_SET_CV									0x00000016	/*!< ����CV�����̳� ����CV������ �������� ���� \n (Charging CV voltage or discharging CV voltage not set) */
#define		CTS_SCHEDULE_REF_VOLTAGE_LOW							0x00000017	/*!< �������� �������� ��������H���� ���� \n (Charge voltage setting value is lower than end voltage) */
#define		CTS_SCHEDULE_REF_VOLTAGE_HIGH							0x00000018	/*!< �������� �������� ��������L���� ���� \n (Charge voltage setting value is upper than end voltage)*/
#define		CTS_SCHEDULE_NOT_SET_PATTERN_FILE						0x00000019	/*!< Pattern file �� �������� �ʾ��� \n (Not set pattern file) */
#define		CTS_SCHEDULE_NOT_SET_STEP_END_COND						0x0000001A	/*!< Pattern Step�� ���� ������ �����Ǿ� ���� ���� \n (End condition of pattern step is not set) */
#define		CTS_SCHEDULE_CHARGE_NOT_SET_STEP_VOLTAGE_INVALID		0x0000001B	/*!< Charge Step�� ���а��� ���� ���� �ʾҰų� ������ ��� \n (Charge step voltage value is not set or out of range) */
#define		CTS_SCHEDULE_CHARGE_STEP_CHANGE_VOLTAGE_HIGH			0x0000001C	/*!< Charge Step�� ���к�ȭ �������� �ʹ� ŭ \n (Charge step voltage setting too high) */
#define		CTS_SCHEDULE_CHARGE_SET_END_VOLTAGE_HIGH				0x0000001D	/*!< Charge Step�� ���� ������ ���� ���к��� ���� \n (Charge step end voltage is higher than setting voltage) */
#define		CTS_SCHEDULE_DISCHARGE_SET_END_VOLTAGE_HIGH				0x0000001E	/*!< Discharge Step�� ���� ������ ���� ���к��� ���� \n (The end voltage of the discharge step is higher than the set voltage) */
#define		CTS_SCHEDULE_NOT_SET_TEMP_START							0x0000001F	/*!< Step�� �µ� �������� �Է����� �ʰ� ���ۿµ��� ����µ��� �����Ǿ��� \n (Start temperature or end temperature is set without inputting the step temperature setting value)*/
#define		CTS_SCHEDULE_SET_VOLTAGE_INVALID						0x00000020	/*!< Step�� ���� �������� ������ ���� ���� \n (Step voltage setting is out of range) */
#define		CTS_SCHEDULE_SET_END_VOLTAGE_INVALID					0x00000021	/*!< Step�� ���� ���а��� �Է� ������ ����� \n (Step end voltage value is out of input range) */
#define		CTS_SCHEDULE_SET_END_CURRENT_INVALID					0x00000022	/*!< Step�� ���� �������� �Է� ������ ����� \n (The end current of the step is out of the input range) */
#define		CTS_SCHEDULE_SAFTY_SET_VOLTAGE_INVALID					0x00000023	/*!< Step�� ���� ���� ���Ѱ��� �Է� ������ ����� \n (Safety voltage lower limit of step is out of input range) */
#define		CTS_SCHEDULE_SAFTY_VOLTAGE_LOW							0x00000024	/*!< Step�� ���� ���� ���Ѱ��� ���Ѱ����� ���� \n (Step safety voltage upper limit value is lower than lower limit value) */
#define		CTS_SCHEDULE_SAFTY_CURRENT_LOW							0x00000025	/*!< Step�� ���� ���� ���Ѱ��� ���Ѱ����� ���� \n (Step safety current upper limit value is smaller than lower limit value) */
#define		CTS_SCHEDULE_SAFTY_TEMP_LOW								0x00000026	/*!< Step�� ���� �µ� ���Ѱ��� ���Ѱ����� ���� \n (Step safety temperature upper limit value is lower than lower limit value) */
#define		CTS_SCHEDULE_NOT_SET_CURRENT							0x00000027	/*!< Step�� �������� ���� ���� �ʾҰų� ������ ����� \n (Step current value is not set or out of range) */
#define		CTS_SCHEDULE_NOT_SET_CP_CURRENT							0x00000028	/*!< Step�� CP ���°� �Է� ������ ����� \n (Step CP power value input range is out of range) */
#define		CTS_SCHEDULE_NOT_SET_CP_POWER							0x00000029	/*!< Step�� CP ���°� �Է� ������ ����� \n (Step CP power value input range is out of range) */
#define		CTS_SCHEDULE_CHARGE_SET_END_VOLTAGE_HIGH2				0x0000002A	/*!< Charge Step�� ���� ����(High)�� ���� ���п� ���� ���� ���� �Ǿ���. �������к��� �ּ� 10mV���� ���������� �����Ͽ�����. \n (Charge Step end voltage (High) is set higher than rated voltage. Must be at least 10mV below rated voltage) */
#define		CTS_SCHEDULE_CHARGE_SET_END_VOLTAGE_LOW					0x0000002B	/*!< Charge Step�� ���� ����(Low)�� ���� ���п� ���� ���� ���� �Ǿ���. �������к��� �ּ� 10mV���� ���������� �����Ͽ�����. \n (Charge Step end voltage (Low) is set higher than rated voltage. Must be at least 10mV below rated voltage) */
#define		CTS_SCHEDULE_PATTERN_SET_VOLTAGE_INVALID				0x0000002C	/*!< Pattern Step�� ���� �������� ������ ���� ���� \n (Voltage set value of Pattern Step is out of range) */
#define		CTS_SCHEDULE_PATTERN_SET_END_VOLTAGE_INVALID			0x0000002D	/*!< Pattern Step�� ���� ���� �������� ������ ���� ���� \n (End voltage setting value of Pattern Step is out of range) */


#define		CTS_SCHEDULE_SEND_SBC_FAIL								0x0000002E	/*!< sbc�� �����ϴ� schedule File Size, checksum ���� \n (schedule File Size, checksum failed to transfer to sbc) */
#define		CTS_SCHEDULE_SBC_TO_FILE_UPLOAD_FAIL					0x0000002F	/*!< sbc�� �����ϴ� file upload ���� \n (Failed to upload file to sbc) */
#define		CTS_SCHEDULE_SBC_TO_PATTERN_FILE_UPLOAD_FAIL			0x00000030	/*!< sbc�� �����ϴ� Pattern file upload ���� \n (Pattern file upload failed to transfer to sbc) */
#define		CTS_SCHEDULE_SBC_UPLOAD_CHANNEL_INFO_INVALID			0x00000031	/*!< sbc�� �����ϴ� file�� ä�� info �̻� \n (More than channel info of file transmitted by sbc) */




/** @} */ //SendSchedule ResponseCode ���� ��