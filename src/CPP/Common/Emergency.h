/** 
 *@file		Emergency.h
 *@brief	PSSeverAPI �� ��� �˶� ���� �����Դϴ�.											
 *@author	PNE Solution (Kang se-jun)
 *@date		2019-03-22
 */



//���� CTSMonPro������ Database���� �����ϴ� ����̳�, APIȭ�ϸ� define ����Ʈ��.
/** @defgroup EmgCode Emergency Code
 *  @ingroup define
 *  @brief 
 * Emergency Code\n
 *  @details
 *	#CTS_MODULE_EMG ���� �̺�Ʈ�� ���� Host App�� ��� �˶� ���¸� �˸��ϴ�.\n
 * ������� ��� �˶� �ڵ��Դϴ�.
 *  @{
 */
#define CTS_EMG_NORMAL					0	/*!< ���� ���� (Normal) \n ���� �����Դϴ�.*/
#define CTS_EMG_POWER_FAIL1				1	/*!< ���� ���� �߻� (Momentary power outages) \n AC �Է� ������ ���������� �߻��Ͽ����ϴ�. */
#define CTS_EMG_POWER_FAIL2				2	/*!< ���� ���� �߻� (Completely power outages) \n AC �Է� ������ ���� ���� �ʽ��ϴ�. �����Է¼��̳� UPS�� Ȯ���Ͻʽÿ�. */
#define CTS_EMG_UPS_FAIL				3	/*!< UPS Battery �̻� �߻� (UPS battery failure) \n UPS ���� Backup�� ���͸� ���°� ���� �ʽ��ϴ�. ���� �� ��ȯ �Ͻʽÿ�. */
#define CTS_EMG_MAIN_EMG_SWITCH			4	/*!< Main EMG Button�� ������ (Main emg button pressed) \n ������ �� ��� ����ġ�� ���Ƚ��ϴ�. ��� ���� ������ ���� �� ������� ����ġ�� ���� NFB�� ����ġ ��Ų �� system�� �ѽñ� �ٶ��ϴ�. */
#define CTS_EMG_SUB_EMG_SWITCH			5	/*!< Sub EMG Button�� ������ (Main emg button pressed) \n ������ ���� ��� ����ġ�� ���Ƚ��ϴ�.  ��� ���� ������ ���� �� ������� ����ġ�� ���� NFB�� ����ġ ��Ų �� system�� �ѽñ� �ٶ��ϴ�. */
#define CTS_EMG_SMPS_FAIL				6	/*!< ����� ���� �̻� �߻� (Control power failure) \n ����� �Ŀ����ö��� ������ ���� ���� �ʽ��ϴ�. ������ Main NFB�� On ���״��� Ȯ�� �� �� �� SMPS�� ����� Ȯ���Ͻʽÿ�. */
#define CTS_EMG_OVER_HEAT				7	/*!< ���� ����(Module) (Equipment overheating) \n ��� �����Ǿ����ϴ�. ��� ���� �߿� ��������� �ð� FAN�� ���� ���� �� ���� Ȯ���� �� �ð� ���� �帧�� �����ϴ� ��Ҹ� ���� �Ͻʽÿ�. */
#define CTS_EMG_POWER_OFF_SWITCH		8	/*!< ������ Power Off Switch ���� (Detect power off switch during operation) \n ��� Run�� Power Off Switch�� ������ */
#define CTS_EMG_NORMAL_POWER_OFF		9	/*!< Normal Power Off ���� (Detect normal power off) \n ���������� Power Off Switch�� ���� */
#define CTS_EMG_POWER_OFF				10	/*!< ��������(Switch) (Force power off(Switch)) \n ���� ����(����� ����)���ε� ���� Power Off�� �ǽ� �Ͽ����ϴ�. �������� �ڷ�� ��� �Ұ� �ǰ� Reset �˴ϴ�. */
#define CTS_EMG_NORMAL_TERM_QUIT1		11	/*!< Normal Terminal Quit ���� (Detect normal terminal quit) \n ���������� Terminal���� Quit�� */
#define CTS_EMG_NORMAL_TERM_QUIT2		12	/*!< ��������(�͹̳�2) (Force power off(Terminal2)) \n ��� Run�� Terminal���� Quit�� */
#define CTS_EMG_NORMAL_TERM_HALT1		13	/*!< Normal Terminal Halt ���� (Detect normal terminal halt) \n ���������� Terminal���� Halt�� */
#define CTS_EMG_NORMAL_TERM_HALT2		14	/*!< ��������(�͹̳�1) (Force power off(Terminal2)) \n ��� Run�� Terminal���� Halt�� */
#define CTS_EMG_CPU_WATCHDOG			15	/*!< CPU Watchdog \n ���� CPU�� ������ �������� �ʰų� ���� S/W������ ���� rebooting �˴ϴ�. �������� �ڷ�� �ʱ�ȭ �˴ϴ�. */
#define CTS_EMG_DMM_COMM_ERROR			16	/*!< ������ DMM�� ��� Error �߻� (Communication error with calibration DMM) \n �ܺ� ������� ��� ������ �߻��Ͽ����ϴ�. ��ż��� Ȯ�� �ٶ��ϴ�. */
#define CTS_EMG_CAL_COMM_ERROR			17	/*!< ������ Tool�� ��� Error �߻� (Communication error with calibration tool) \n �ܺ� ������ġ�� ��� ������ �߻��Ͽ����ϴ�. ��ż��� Ȯ�� �ٶ��ϴ�. */
#define CTS_EMG_FUSE_ERROR				18	/*!< ��� Fuse �ܼ� (Equipment fuse disconnection) \n */
#define CTS_EMG_MAIN_POWER_OVER_VOLT	19	/*!< Main ���� Over Voltage (Main power over voltage) \n */
#define CTS_EMG_MAIN_POWER_UNDER_VOLT	20	/*!< Main ���� Under Voltage (Main power under voltage) \n */
#define CTS_EMG_MAIN_POWER_ERROR		21	/*!< Main ���� �̻� (Main power failure) \n */
#define CTS_EMG_FAN_ERROR				22	/*!< �ð��� �̻� (Cooling fan failure) \n */
#define CTS_EMG_POWER_TRANSF_ERROR		23	/*!< Main Power Transformer ���� (Main power transformer overheating) \n */
#define CTS_EMG_POWER_REACT_ERROR		24	/*!< Main Power Reactor ���� (Main power reactor overheating) \n */
#define CTS_EMG_OUTCTRL_OVER_VOLTAGE	50	/*!< ��� ���� ���� �ʰ� (Output control voltage over) \n ��� ���� �ʰ� */
#define CTS_EMG_OUTCTRL_OVER_CURRNET	51	/*!< ��� ���� ���� �ʰ� (Output control current over) \n ��� ���� �ʰ� */
#define CTS_EMG_RUN_TIME_OVER			52	/*!< Run Time Over \n��ü ���� �ð� �ʰ� */
#define CTS_EMG_DATA_SAVE_ERROR			53	/*!< Data ���� ����(DataSave) (Data save error) \n ������� ���� ���� ���� */
#define CTS_EMG_ADC_ERROR				54	/*!< ADC �̻�(Group) (ADC error(Group)) \n Analog to Digital Converter �̻�(Group) */
#define CTS_EMG_OVERHEAT_GROUP			55	/*!< ���� ����(Group) (Detect overheating(Group)) \n ��� �����Ǿ����ϴ�. ��� ���� �߿� ��������� �ð� FAN�� ���� ���� �� ���� Ȯ���� �� �ð� ���� �帧�� �����ϴ� ��Ҹ� ���� �Ͻʽÿ�. */
#define CTS_EMG_OVERHEAT_BD				100	/*!< ���� ����(BD)\n (Detect overheating(BD)) ��� �����Ǿ����ϴ�. ��� ���� �߿� ��������� �ð� FAN�� ���� ���� �� ���� Ȯ���� �� �ð� ���� �帧�� �����ϴ� ��Ҹ� ���� �Ͻʽÿ�. */
#define CTS_EMG_ADC_ERROR_BD			101	/*!< ADC �̻�(BD) (ADC error(BD)) \n Analog to Digital Converter �̻�(Board) */
/** @} */ //Emergency Code ���� ��
