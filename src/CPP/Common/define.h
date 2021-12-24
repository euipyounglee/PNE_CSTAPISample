/** 
 *@file		define.h
 *@brief	define 파일입니다.
 *@author	PNE Solution (Kang se-jun)
 *@date		2019-04-08
 */

/** @defgroup define Definitions (정의)
 * define\n
 *  @brief 
 * 주요 항목을 정의합니다.
 *  @{
 */

/** @} */ //define 끝


/** @defgroup define_sub Define
 *  @ingroup define
 * define\n
 * 주요 항목을 정의합니다.
 *  @{
 */
#define CTS_MAX_MAPPING_AUX				512 	/*!< Channel 당 최대 AUX 갯수 (온도(256) + 전압(256)) \n (Maximum number of AUX per channel) */
#define CTS_MAX_MAPPING_CAN				512		/*!< Channel 당 최대 CAN 갯수 (Master(256) + Slave(256)) \n (Maximum number of CAN per channel)*/
#define CTS_MAX_INSTALL_CH_COUNT		8		/*!< Max Channel 개수 (Number of Max channel) */


#define CTS_IP_NAME_LENGTH				16		/*!< IP 주소 길이 (IP Address length)*/
#define CTS_MAX_VOLTAGE_RANGE			4		/*!< 최대 전압 레인지 개수 (Number of maximum voltage range) */
#define CTS_MAX_CURRENT_RANGE			4		/*!< 최대 전류 레인지 개수 (Number of maximum current range) */
/** @} */ //sub define 끝


/** @defgroup define_state Module State Code
 *  @ingroup define
 * State Code\n
 * 충방전기의 모듈의 상태 코드 항목을 정의합니다.
 *  @{
 */
//PC Part state
#define PS_STATE_LINE_OFF		0x0020				/*!< 통신 두절 (Line off) */
#define PS_STATE_LINE_ON		0x0021				/*!< 통신 연결 (Line on) */
#define PS_STATE_END			0x0026				/*!< 테스트 종료 (Test end) */
#define PS_STATE_READY			0x0029				/*!< 준비 (Test ready) */
#define PS_STATE_ERROR			0xFFFF				/*!< Error */

/** @} */ //state define 끝

/** @defgroup define_state_ch Channel State Code
 *  @ingroup define
 * State Code\n
 * 충방전기의 채널의 운용 상태 항목을 정의합니다.
 *  @{
 */
//Channel State
#define PS_STATE_IDLE			0x0000				/*!< 초기상태 (Idle)*/
#define PS_STATE_STANDBY		0x0001				/*!< 대기 (Standby) */
#define PS_STATE_RUN			0x0002				/*!< 가동중 (Run) */
#define PS_STATE_PAUSE			0x0003				/*!< 일시정지 (Pause) */
#define PS_STATE_MAINTENANCE	0x0004				/*!< 유지보수 (Maintenance) */

/** @} */ //channel state define 끝


/** @defgroup chStepType Channel Step Type
 *  @ingroup define
 * State type\n
 * 충방전기의 스텝 동작 상태의 Type 항목을 정의합니다.
 * 정의되지 않은 Step Type은 공정중 상태 표시 문자로 작업중(Operating)으로 표시됩니다.
 *  @{
 */
//Channel step
#define PS_STEP_NONE			0x00				/*!< None
													*<TABLE><TR><TH> 	 </TH><TH> 한국어 </TH><TH> 영어 </TH></TR><TR><TD> 공정중\n상태표시문자 </TD><TD> Idle </TD><TD> Idle </TD></TR></TABLE> */
#define PS_STEP_CHARGE			0x01				/*!< Charge
													*<TABLE><TR><TH> 	 </TH><TH> 한국어 </TH><TH> 영어 </TH></TR><TR><TD> 공정중\n상태표시문자 </TD><TD> 충전 </TD><TD> Charge </TD></TR></TABLE> */
#define PS_STEP_DISCHARGE		0x02				/*!< Discharge
													*<TABLE><TR><TH> 	 </TH><TH> 한국어 </TH><TH> 영어 </TH></TR><TR><TD> 공정중\n상태표시문자 </TD><TD> 방전 </TD><TD> Discharge </TD></TR></TABLE> */
#define PS_STEP_REST			0x03				/*!< Rest
													*<TABLE><TR><TH> 	 </TH><TH> 한국어 </TH><TH> 영어 </TH></TR><TR><TD> 공정중\n상태표시문자 </TD><TD> 휴지 </TD><TD> Rest </TD></TR></TABLE> */
#define PS_STEP_OCV				0x04				/*!< OCV
													*<TABLE><TR><TH> 	 </TH><TH> 한국어 </TH><TH> 영어 </TH></TR><TR><TD> 공정중\n상태표시문자 </TD><TD> OCV </TD><TD> OCV </TD></TR></TABLE> */
#define PS_STEP_IMPEDANCE		0x05				/*!< Impedance
													*<TABLE><TR><TH> 	 </TH><TH> 한국어 </TH><TH> 영어 </TH></TR><TR><TD> 공정중\n상태표시문자 </TD><TD> 임피던스 </TD><TD> Impedance </TD></TR></TABLE> */
#define PS_STEP_END				0x06				/*!< End
													*<TABLE><TR><TH> 	 </TH><TH> 한국어 </TH><TH> 영어 </TH></TR><TR><TD> 공정중\n상태표시문자 </TD><TD> 완료 </TD><TD> End </TD></TR></TABLE> */
#define PS_STEP_ADV_CYCLE		0x07				/*!< Cycle
													*<TABLE><TR><TH> 	 </TH><TH> 한국어 </TH><TH> 영어 </TH></TR><TR><TD> 공정중\n상태표시문자 </TD><TD> 작업중 </TD><TD> Operating </TD></TR></TABLE> */
#define PS_STEP_LOOP			0x08				/*!< Loop
													*<TABLE><TR><TH> 	 </TH><TH> 한국어 </TH><TH> 영어 </TH></TR><TR><TD> 공정중\n상태표시문자 </TD><TD> 작업중 </TD><TD> Operating </TD></TR></TABLE> */
#define PS_STEP_PATTERN			0x09				/*!< Pattern
													*<TABLE><TR><TH> 	 </TH><TH> 한국어 </TH><TH> 영어 </TH></TR><TR><TD> 공정중\n상태표시문자 </TD><TD> Pattern </TD><TD> Pattern </TD></TR></TABLE> */

/** @} */ //Channel Step Type 끝	


/** @defgroup chMode Channel Mode
 *  @ingroup define
 * Channel Mode \n
 * 충방전기의 채널 모드 항목을 정의합니다.
 *  @{
 */
//Channel mode
#define		PS_MODE_CCCV			0x01			/*!< 전류/전압 충전 모드 (Current/Voltage charge mode)*/
#define		PS_MODE_CC				0x02			/*!< 전류 충전 모드 (Current charge mode) */
#define		PS_MODE_CV				0x03			/*!< 전압 충전 모드 (Voltage charge mode) */
#define		PS_MODE_DCIMP			0x04			/*!< DC 임피던스 충전 모드 (DC impedance charge mode) */
#define		PS_MODE_ACIMP			0x05			/*!< AC 임피던스 충전 모드 (AC impedance charge mode) */
#define		PS_MODE_CP				0x06			/*!< 파워 충전 모드 (Power charge mode) */

/** @} */ //Channel Mode 끝	
