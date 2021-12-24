/** 
 *@file		ChannelItem.h
 *@brief	PSSeverAPI 채널아이템 정의 파일입니다.											
 *@author	PNE Solution (Kang se-jun)
 *@date		2019-03-22
 */

/** @defgroup ChannelItem Channel Item
 *  @ingroup define
 *  @brief 
 * Channel Item Code List\n
*  @details
*  ctsGetChannelState() 의 return 값에 대한 정의입니다.
 *  @{
 */
//각 data 항목의 Index
#define		PS_STATE			0x00	/*!< 상태 (State)*/
#define		PS_VOLTAGE			0x01	/*!< 전압 (Voltage)*/
#define		PS_CURRENT			0x02	/*!< 전류 (Current)*/
#define		PS_CAPACITY			0x03	/*!< 용량 합계 (Total capacity)*/
#define		PS_IMPEDANCE		0x04	/*!< 임피던스 (Impedance)*/
#define		PS_CODE				0x05	/*!< 채널코드 (Channel code)*/
#define		PS_STEP_TIME		0x06	/*!< 스텝 경과 시간 (Step elapsed time)*/
#define		PS_TOT_TIME			0x07	/*!< 시험 경과 시간 (Test elapsed time)*/
#define		PS_GRADE_CODE		0x08	/*!< 등급 판정 (Grade code)*/
#define		PS_STEP_NO			0x09	/*!< 현재 스텝 번호 (Step Number)*/
#define		PS_WATT				0x0A	/*!< Watt */
#define		PS_WATT_HOUR		0x0B	/*!< Watt Hour */
#define		PS_STEP_TYPE		0x0E	/*!< 스텝 형식 (충전,방전 등, Step Type) */
#define		PS_CUR_CYCLE		0x0F	/*!< 현재 Cycle (Current cycle)*/
#define		PS_TOT_CYCLE		0x10	/*!< 전체 Cycle (Total cycle)*/
#define		PS_TEST_NAME		0x11	/*!< 시험명 (Test name)*/
#define		PS_CHANNEL_NO		0x13	/*!< 채널 번호 (Channel number)*/
#define		PS_DATA_SEQ			0x16	/*!< 데이터 순서 (Data sequence)*/
#define		PS_AVG_CURRENT		0x17	/*!< 평균 전류 (Average current)*/
#define		PS_AVG_VOLTAGE		0x18	/*!< 평균 전압 (Average voltage)*/
#define		PS_CHARGE_CAP		0x1a	/*!< 충전 용량 (Charge capacity)*/
#define		PS_DISCHARGE_CAP	0x1b	/*!< 방전 용량 (Discharge capacity)*/
/** @} */ //ChannelItem 정의 끝