/** 
 *@file		define.h
 *@brief	define �����Դϴ�.
 *@author	PNE Solution (Kang se-jun)
 *@date		2019-04-08
 */

/** @defgroup define Definitions (����)
 * define\n
 *  @brief 
 * �ֿ� �׸��� �����մϴ�.
 *  @{
 */

/** @} */ //define ��


/** @defgroup define_sub Define
 *  @ingroup define
 * define\n
 * �ֿ� �׸��� �����մϴ�.
 *  @{
 */
#define CTS_MAX_MAPPING_AUX				512 	/*!< Channel �� �ִ� AUX ���� (�µ�(256) + ����(256)) \n (Maximum number of AUX per channel) */
#define CTS_MAX_MAPPING_CAN				512		/*!< Channel �� �ִ� CAN ���� (Master(256) + Slave(256)) \n (Maximum number of CAN per channel)*/
#define CTS_MAX_INSTALL_CH_COUNT		8		/*!< Max Channel ���� (Number of Max channel) */


#define CTS_IP_NAME_LENGTH				16		/*!< IP �ּ� ���� (IP Address length)*/
#define CTS_MAX_VOLTAGE_RANGE			4		/*!< �ִ� ���� ������ ���� (Number of maximum voltage range) */
#define CTS_MAX_CURRENT_RANGE			4		/*!< �ִ� ���� ������ ���� (Number of maximum current range) */
/** @} */ //sub define ��


/** @defgroup define_state Module State Code
 *  @ingroup define
 * State Code\n
 * ��������� ����� ���� �ڵ� �׸��� �����մϴ�.
 *  @{
 */
//PC Part state
#define PS_STATE_LINE_OFF		0x0020				/*!< ��� ���� (Line off) */
#define PS_STATE_LINE_ON		0x0021				/*!< ��� ���� (Line on) */
#define PS_STATE_END			0x0026				/*!< �׽�Ʈ ���� (Test end) */
#define PS_STATE_READY			0x0029				/*!< �غ� (Test ready) */
#define PS_STATE_ERROR			0xFFFF				/*!< Error */

/** @} */ //state define ��

/** @defgroup define_state_ch Channel State Code
 *  @ingroup define
 * State Code\n
 * ��������� ä���� ��� ���� �׸��� �����մϴ�.
 *  @{
 */
//Channel State
#define PS_STATE_IDLE			0x0000				/*!< �ʱ���� (Idle)*/
#define PS_STATE_STANDBY		0x0001				/*!< ��� (Standby) */
#define PS_STATE_RUN			0x0002				/*!< ������ (Run) */
#define PS_STATE_PAUSE			0x0003				/*!< �Ͻ����� (Pause) */
#define PS_STATE_MAINTENANCE	0x0004				/*!< �������� (Maintenance) */

/** @} */ //channel state define ��


/** @defgroup chStepType Channel Step Type
 *  @ingroup define
 * State type\n
 * ��������� ���� ���� ������ Type �׸��� �����մϴ�.
 * ���ǵ��� ���� Step Type�� ������ ���� ǥ�� ���ڷ� �۾���(Operating)���� ǥ�õ˴ϴ�.
 *  @{
 */
//Channel step
#define PS_STEP_NONE			0x00				/*!< None
													*<TABLE><TR><TH> 	 </TH><TH> �ѱ��� </TH><TH> ���� </TH></TR><TR><TD> ������\n����ǥ�ù��� </TD><TD> Idle </TD><TD> Idle </TD></TR></TABLE> */
#define PS_STEP_CHARGE			0x01				/*!< Charge
													*<TABLE><TR><TH> 	 </TH><TH> �ѱ��� </TH><TH> ���� </TH></TR><TR><TD> ������\n����ǥ�ù��� </TD><TD> ���� </TD><TD> Charge </TD></TR></TABLE> */
#define PS_STEP_DISCHARGE		0x02				/*!< Discharge
													*<TABLE><TR><TH> 	 </TH><TH> �ѱ��� </TH><TH> ���� </TH></TR><TR><TD> ������\n����ǥ�ù��� </TD><TD> ���� </TD><TD> Discharge </TD></TR></TABLE> */
#define PS_STEP_REST			0x03				/*!< Rest
													*<TABLE><TR><TH> 	 </TH><TH> �ѱ��� </TH><TH> ���� </TH></TR><TR><TD> ������\n����ǥ�ù��� </TD><TD> ���� </TD><TD> Rest </TD></TR></TABLE> */
#define PS_STEP_OCV				0x04				/*!< OCV
													*<TABLE><TR><TH> 	 </TH><TH> �ѱ��� </TH><TH> ���� </TH></TR><TR><TD> ������\n����ǥ�ù��� </TD><TD> OCV </TD><TD> OCV </TD></TR></TABLE> */
#define PS_STEP_IMPEDANCE		0x05				/*!< Impedance
													*<TABLE><TR><TH> 	 </TH><TH> �ѱ��� </TH><TH> ���� </TH></TR><TR><TD> ������\n����ǥ�ù��� </TD><TD> ���Ǵ��� </TD><TD> Impedance </TD></TR></TABLE> */
#define PS_STEP_END				0x06				/*!< End
													*<TABLE><TR><TH> 	 </TH><TH> �ѱ��� </TH><TH> ���� </TH></TR><TR><TD> ������\n����ǥ�ù��� </TD><TD> �Ϸ� </TD><TD> End </TD></TR></TABLE> */
#define PS_STEP_ADV_CYCLE		0x07				/*!< Cycle
													*<TABLE><TR><TH> 	 </TH><TH> �ѱ��� </TH><TH> ���� </TH></TR><TR><TD> ������\n����ǥ�ù��� </TD><TD> �۾��� </TD><TD> Operating </TD></TR></TABLE> */
#define PS_STEP_LOOP			0x08				/*!< Loop
													*<TABLE><TR><TH> 	 </TH><TH> �ѱ��� </TH><TH> ���� </TH></TR><TR><TD> ������\n����ǥ�ù��� </TD><TD> �۾��� </TD><TD> Operating </TD></TR></TABLE> */
#define PS_STEP_PATTERN			0x09				/*!< Pattern
													*<TABLE><TR><TH> 	 </TH><TH> �ѱ��� </TH><TH> ���� </TH></TR><TR><TD> ������\n����ǥ�ù��� </TD><TD> Pattern </TD><TD> Pattern </TD></TR></TABLE> */

/** @} */ //Channel Step Type ��	


/** @defgroup chMode Channel Mode
 *  @ingroup define
 * Channel Mode \n
 * ��������� ä�� ��� �׸��� �����մϴ�.
 *  @{
 */
//Channel mode
#define		PS_MODE_CCCV			0x01			/*!< ����/���� ���� ��� (Current/Voltage charge mode)*/
#define		PS_MODE_CC				0x02			/*!< ���� ���� ��� (Current charge mode) */
#define		PS_MODE_CV				0x03			/*!< ���� ���� ��� (Voltage charge mode) */
#define		PS_MODE_DCIMP			0x04			/*!< DC ���Ǵ��� ���� ��� (DC impedance charge mode) */
#define		PS_MODE_ACIMP			0x05			/*!< AC ���Ǵ��� ���� ��� (AC impedance charge mode) */
#define		PS_MODE_CP				0x06			/*!< �Ŀ� ���� ��� (Power charge mode) */

/** @} */ //Channel Mode ��	
