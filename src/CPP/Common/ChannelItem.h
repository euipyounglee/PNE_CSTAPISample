/** 
 *@file		ChannelItem.h
 *@brief	PSSeverAPI ä�ξ����� ���� �����Դϴ�.											
 *@author	PNE Solution (Kang se-jun)
 *@date		2019-03-22
 */

/** @defgroup ChannelItem Channel Item
 *  @ingroup define
 *  @brief 
 * Channel Item Code List\n
*  @details
*  ctsGetChannelState() �� return ���� ���� �����Դϴ�.
 *  @{
 */
//�� data �׸��� Index
#define		PS_STATE			0x00	/*!< ���� (State)*/
#define		PS_VOLTAGE			0x01	/*!< ���� (Voltage)*/
#define		PS_CURRENT			0x02	/*!< ���� (Current)*/
#define		PS_CAPACITY			0x03	/*!< �뷮 �հ� (Total capacity)*/
#define		PS_IMPEDANCE		0x04	/*!< ���Ǵ��� (Impedance)*/
#define		PS_CODE				0x05	/*!< ä���ڵ� (Channel code)*/
#define		PS_STEP_TIME		0x06	/*!< ���� ��� �ð� (Step elapsed time)*/
#define		PS_TOT_TIME			0x07	/*!< ���� ��� �ð� (Test elapsed time)*/
#define		PS_GRADE_CODE		0x08	/*!< ��� ���� (Grade code)*/
#define		PS_STEP_NO			0x09	/*!< ���� ���� ��ȣ (Step Number)*/
#define		PS_WATT				0x0A	/*!< Watt */
#define		PS_WATT_HOUR		0x0B	/*!< Watt Hour */
#define		PS_STEP_TYPE		0x0E	/*!< ���� ���� (����,���� ��, Step Type) */
#define		PS_CUR_CYCLE		0x0F	/*!< ���� Cycle (Current cycle)*/
#define		PS_TOT_CYCLE		0x10	/*!< ��ü Cycle (Total cycle)*/
#define		PS_TEST_NAME		0x11	/*!< ����� (Test name)*/
#define		PS_CHANNEL_NO		0x13	/*!< ä�� ��ȣ (Channel number)*/
#define		PS_DATA_SEQ			0x16	/*!< ������ ���� (Data sequence)*/
#define		PS_AVG_CURRENT		0x17	/*!< ��� ���� (Average current)*/
#define		PS_AVG_VOLTAGE		0x18	/*!< ��� ���� (Average voltage)*/
#define		PS_CHARGE_CAP		0x1a	/*!< ���� �뷮 (Charge capacity)*/
#define		PS_DISCHARGE_CAP	0x1b	/*!< ���� �뷮 (Discharge capacity)*/
/** @} */ //ChannelItem ���� ��