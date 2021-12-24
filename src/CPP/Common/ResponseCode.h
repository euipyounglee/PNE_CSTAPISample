/** 
 *@file		ResponseCode.h
 *@brief	전송한 명령에대한 응답 정의 헤더 파일 입니다.								
 *@author	PNE Solution (Kang se-jun)
 *@date		2019-03-22
 */


/** @defgroup ResponseCode SendCommand Response Code
 *  @ingroup define
 *  @brief
 * SendCommand Response Code\n
 *  @details
 * 충방전기에 전송한 명령에 대한 응답 코드입니다.
 *  @{
 */
//response of command code
#define		CTS_NACK					0x00000000	/*!< 오류 (Error) */
#define		CTS_ACK						0x00000001	/*!< 정상 (Normal) */
#define		CTS_TIMEOUT					0x00000002	/*!< 시간초과 (Time over) */
#define		CTS_SIZE_MISMATCH			0x00000003	/*!< Body Size 불일치 (Size mismatch) */
#define		CTS_RX_BUFF_OVER_FLOW		0x00000004	/*!< 수신 버퍼 오버플로우 (Receive buffer overflow) */
#define		CTS_TX_BUFF_OVER_FLOW		0x00000005	/*!< 송신 버퍼 오버플로우 (Transmit buffer overflow) */
#define		CTS_CONNECTED				0x00000006	/*!< 접속 성공 (Connection success) */
#define		CTS_NOT_CONNECTED			0x00000007	/*!< 접속 되어 있지 않음 (Not connected) */
#define		CTS_FILE_NOT_EXIST			0x00000008	/*!< 해당 경로에 파일이 없음 (Not exist file) */
#define		CTS_FILE_OPENED				0x00000009	/*!< 파일이 Open되어 있음 (File open fail) */
#define		CTS_CAN_LIN_TYPE_INVALID	0x0000000A	/*!< CAN Rx/Tx, LIN File Type이 맞지 않음 (Type mismatch) */
#define		CTS_CHANNEL_RUN				0x0000000B	/*!< 현재 동작중인 채널임 (Channel is running) */
#define		CTS_FAIL					0xFFFFFFFF	/*!< 실패 (Failure) */
/** @} */ //SendCommand ResponseCode 정의 끝


/** @defgroup SendScheduleResponseCode SendSchedule Response Code
 *  @ingroup define
 *  @brief
 * SendSchedule Response Code\n
 *  @details
 * 스케쥴 전송에 대한 응답 코드입니다.
 *  @{
 */
//response of command code
#define		CTS_SCHEDULE_FAIL										0x00000000	/*!< 스케쥴 전송 실패 \n (Schedule transmit fail) */
#define		CTS_SCHEDULE_OK											0x00000001	/*!< 스케쥴 전송 완료 \n (Schedule transmit success) */
#define		CTS_SCHEDULE_NOT_CONNECTED								0x00000002	/*!< 모듈과 연결되어 있지 않음 \n (Not connected module) */
#define		CTS_SCHEDULE_INVALID_CHANNEL							0x00000003	/*!< 잘못 된 채널 설정 \n (Invalid channel) */
#define		CTS_SCHEDULE_FILE_NOT_FOUND								0x00000004	/*!< 스케쥴 파일 경로에 없음 \n (Not exist of schedule file path) */
#define		CTS_SCHEDULE_TEMP_INVALID								0x00000005	/*!< 온도 설정이 잘못되어 작업을 시작 할 수 없음 \n (Unable to start operation due to incorrect temperature setting) */
#define		CTS_SCHEDULE_AUX_INVALID								0x00000006	/*!< 외부센서 안전조건이 잘못되어 작업을 시작 할 수 없음 \n (Unable to start operation due to incorrect safety condition setting) */
#define		CTS_SCHEDULE_STEP_SIZE_INVALID							0x00000007	/*!< 스텝 Size 오류 \n (Step size error) */
#define		CTS_SCHEDULE_CHANNEL_RUN								0x00000008	/*!< 동작중인 채널이므로 작업을 시작 할 수 없음 \n (Unable to start operation due to running channel) */
#define		CTS_SCHEDULE_NOT_SET_SAFTY_COND							0x00000009	/*!< 시험 안전 조건이 설정되어 있지 않음 \n (Not set safety condition) */
#define		CTS_SCHEDULE_VALIDITY_FAIL								0x0000000A	/*!< 스케쥴 Validity check fail \n (Schedule validity check fail) */
#define		CTS_SCHEDULE_IP_ADDRESS_INVALID							0x0000000B	/*!< 접속중인 충방전기 모듈 IP 이상 \n (Module IP address incorrect) */
#define		CTS_SCHEDULE_FTP_CONNECT_FAIL							0x0000000C	/*!< 접속중인 충방전기 FTP Server connect fail \n (FTP server connect fail) */
#define		CTS_SCHEDULE_FTP_FILE_INVALID							0x0000000D	/*!< 접속중인 충방전기 FTP File 이상 \n (FTP server file error) */
#define		CTS_SCHEDULE_FILE_INVALID								0x0000000E	/*!< 전송 할 스케쥴이 없음 \n (No schedule file) */
#define		CTS_SCHEDULE_PATTERN_FILE_INVALID						0x0000000F	/*!< Pattern file 오류 \n (Pattern file failure) */
#define		CTS_SCHEDULE_PATTERN_FILE_CHECKSUM_INVALID				0x00000010	/*!< 스케쥴 file checksum 오류 \n (Schedule file checksum error) */
#define		CTS_SCHEDULE_FTP_CREATE_FOLDER_FAIL						0x00000011	/*!< 스케쥴 전송에 필요한 폴더 생성 실패 \n (Folder creation failed of schedule transmit) */
#define		CTS_SCHEDULE_FTP_CREATE_FILE_FAIL						0x00000012	/*!< 접속중인 충방전기 FTP File create fail \n (FTP file create fail) */
#define		CTS_SCHEDULE_FTP_CHANGE_FOLDER_FAIL						0x00000013	/*!< 접속중인 충방전기 FTP Change directory fail \n (FTP change directory fail) */
#define		CTS_SCHEDULE_FTP_ADD_FAIL								0x00000014	/*!< 접속중인 충방전기 FTP File add fail \n (FTP file add fail) */
#define		CTS_SCHEDULE_FTP_PERMISSION_FAIL						0x00000015	/*!< 접속중인 충방전기 FTP permission fail \n (FTP permission fail) */
#define		CTS_SCHEDULE_NOT_SET_CV									0x00000016	/*!< 충전CV전압이나 방전CV전압이 설정되지 않음 \n (Charging CV voltage or discharging CV voltage not set) */
#define		CTS_SCHEDULE_REF_VOLTAGE_LOW							0x00000017	/*!< 충전전압 설정값이 종료전압H보다 낮음 \n (Charge voltage setting value is lower than end voltage) */
#define		CTS_SCHEDULE_REF_VOLTAGE_HIGH							0x00000018	/*!< 방전전압 설정값이 종료전압L보다 높음 \n (Charge voltage setting value is upper than end voltage)*/
#define		CTS_SCHEDULE_NOT_SET_PATTERN_FILE						0x00000019	/*!< Pattern file 이 지정되지 않았음 \n (Not set pattern file) */
#define		CTS_SCHEDULE_NOT_SET_STEP_END_COND						0x0000001A	/*!< Pattern Step의 종료 조건이 설정되어 있지 않음 \n (End condition of pattern step is not set) */
#define		CTS_SCHEDULE_CHARGE_NOT_SET_STEP_VOLTAGE_INVALID		0x0000001B	/*!< Charge Step의 전압값이 설정 되지 않았거나 범위를 벗어남 \n (Charge step voltage value is not set or out of range) */
#define		CTS_SCHEDULE_CHARGE_STEP_CHANGE_VOLTAGE_HIGH			0x0000001C	/*!< Charge Step의 전압변화 설정값이 너무 큼 \n (Charge step voltage setting too high) */
#define		CTS_SCHEDULE_CHARGE_SET_END_VOLTAGE_HIGH				0x0000001D	/*!< Charge Step의 종료 전압이 설정 전압보다 높음 \n (Charge step end voltage is higher than setting voltage) */
#define		CTS_SCHEDULE_DISCHARGE_SET_END_VOLTAGE_HIGH				0x0000001E	/*!< Discharge Step의 종료 전압이 설정 전압보다 높음 \n (The end voltage of the discharge step is higher than the set voltage) */
#define		CTS_SCHEDULE_NOT_SET_TEMP_START							0x0000001F	/*!< Step의 온도 설정값을 입력하지 않고 시작온도나 종료온도가 설정되었음 \n (Start temperature or end temperature is set without inputting the step temperature setting value)*/
#define		CTS_SCHEDULE_SET_VOLTAGE_INVALID						0x00000020	/*!< Step의 전압 설정값이 범위를 벗어 났음 \n (Step voltage setting is out of range) */
#define		CTS_SCHEDULE_SET_END_VOLTAGE_INVALID					0x00000021	/*!< Step의 종료 전압값이 입력 범위를 벗어났음 \n (Step end voltage value is out of input range) */
#define		CTS_SCHEDULE_SET_END_CURRENT_INVALID					0x00000022	/*!< Step의 종료 전류값이 입력 범위를 벗어났음 \n (The end current of the step is out of the input range) */
#define		CTS_SCHEDULE_SAFTY_SET_VOLTAGE_INVALID					0x00000023	/*!< Step의 안전 전압 하한값이 입력 범위를 벗어났음 \n (Safety voltage lower limit of step is out of input range) */
#define		CTS_SCHEDULE_SAFTY_VOLTAGE_LOW							0x00000024	/*!< Step의 안전 전압 상한값이 하한값보다 작음 \n (Step safety voltage upper limit value is lower than lower limit value) */
#define		CTS_SCHEDULE_SAFTY_CURRENT_LOW							0x00000025	/*!< Step의 안전 전류 상한값이 하한값보다 작음 \n (Step safety current upper limit value is smaller than lower limit value) */
#define		CTS_SCHEDULE_SAFTY_TEMP_LOW								0x00000026	/*!< Step의 안전 온도 상한값이 하한값보다 작음 \n (Step safety temperature upper limit value is lower than lower limit value) */
#define		CTS_SCHEDULE_NOT_SET_CURRENT							0x00000027	/*!< Step의 전류값이 설정 되지 않았거나 범위를 벗어났음 \n (Step current value is not set or out of range) */
#define		CTS_SCHEDULE_NOT_SET_CP_CURRENT							0x00000028	/*!< Step의 CP 전력값 입력 범위가 벗어났음 \n (Step CP power value input range is out of range) */
#define		CTS_SCHEDULE_NOT_SET_CP_POWER							0x00000029	/*!< Step의 CP 전력값 입력 범위가 벗어났음 \n (Step CP power value input range is out of range) */
#define		CTS_SCHEDULE_CHARGE_SET_END_VOLTAGE_HIGH2				0x0000002A	/*!< Charge Step의 종료 전압(High)이 정격 전압에 비해 높게 설정 되었음. 정격전압보다 최소 10mV이하 범위값으로 설정하여야함. \n (Charge Step end voltage (High) is set higher than rated voltage. Must be at least 10mV below rated voltage) */
#define		CTS_SCHEDULE_CHARGE_SET_END_VOLTAGE_LOW					0x0000002B	/*!< Charge Step의 종료 전압(Low)이 정격 전압에 비해 높게 설정 되었음. 정격전압보다 최소 10mV이하 범위값으로 설정하여야함. \n (Charge Step end voltage (Low) is set higher than rated voltage. Must be at least 10mV below rated voltage) */
#define		CTS_SCHEDULE_PATTERN_SET_VOLTAGE_INVALID				0x0000002C	/*!< Pattern Step의 전압 설정값이 범위를 벗어 났음 \n (Voltage set value of Pattern Step is out of range) */
#define		CTS_SCHEDULE_PATTERN_SET_END_VOLTAGE_INVALID			0x0000002D	/*!< Pattern Step의 종료 전압 설정값이 범위를 벗어 났음 \n (End voltage setting value of Pattern Step is out of range) */


#define		CTS_SCHEDULE_SEND_SBC_FAIL								0x0000002E	/*!< sbc로 전송하는 schedule File Size, checksum 실패 \n (schedule File Size, checksum failed to transfer to sbc) */
#define		CTS_SCHEDULE_SBC_TO_FILE_UPLOAD_FAIL					0x0000002F	/*!< sbc로 전송하는 file upload 실패 \n (Failed to upload file to sbc) */
#define		CTS_SCHEDULE_SBC_TO_PATTERN_FILE_UPLOAD_FAIL			0x00000030	/*!< sbc로 전송하는 Pattern file upload 실패 \n (Pattern file upload failed to transfer to sbc) */
#define		CTS_SCHEDULE_SBC_UPLOAD_CHANNEL_INFO_INVALID			0x00000031	/*!< sbc로 전송하는 file의 채널 info 이상 \n (More than channel info of file transmitted by sbc) */




/** @} */ //SendSchedule ResponseCode 정의 끝