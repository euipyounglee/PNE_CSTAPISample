/** 
 *@file		Emergency.h
 *@brief	PSSeverAPI 의 비상 알람 정의 파일입니다.											
 *@author	PNE Solution (Kang se-jun)
 *@date		2019-03-22
 */



//기존 CTSMonPro에서는 Database에서 관리하던 목록이나, API화하며 define 리스트업.
/** @defgroup EmgCode Emergency Code
 *  @ingroup define
 *  @brief 
 * Emergency Code\n
 *  @details
 *	#CTS_MODULE_EMG 통지 이벤트를 통해 Host App에 비상 알람 상태를 알립니다.\n
 * 충방전기 비상 알람 코드입니다.
 *  @{
 */
#define CTS_EMG_NORMAL					0	/*!< 정상 상태 (Normal) \n 정상 상태입니다.*/
#define CTS_EMG_POWER_FAIL1				1	/*!< 순간 정전 발생 (Momentary power outages) \n AC 입력 전원이 순간정전이 발생하였습니다. */
#define CTS_EMG_POWER_FAIL2				2	/*!< 완전 정전 발생 (Completely power outages) \n AC 입력 전원이 감지 되지 않습니다. 전원입력선이나 UPS를 확인하십시요. */
#define CTS_EMG_UPS_FAIL				3	/*!< UPS Battery 이상 발생 (UPS battery failure) \n UPS 내부 Backup용 배터리 상태가 좋지 않습니다. 점검 후 교환 하십시요. */
#define CTS_EMG_MAIN_EMG_SWITCH			4	/*!< Main EMG Button이 눌려짐 (Main emg button pressed) \n 설비의 주 비상 스위치가 눌렸습니다. 비상 정지 원인을 제거 후 비상정지 스위치와 전원 NFB를 원위치 시킨 후 system을 켜시기 바랍니다. */
#define CTS_EMG_SUB_EMG_SWITCH			5	/*!< Sub EMG Button이 눌려짐 (Main emg button pressed) \n 설비의 보조 비상 스위치가 눌렸습니다.  비상 정지 원인을 제거 후 비상정지 스위치와 전원 NFB를 원위치 시킨 후 system을 켜시기 바랍니다. */
#define CTS_EMG_SMPS_FAIL				6	/*!< 제어용 전원 이상 발생 (Control power failure) \n 제어용 파워서플라이 전원이 감지 되지 않습니다. 설비의 Main NFB를 On 시켰는지 확인 한 후 각 SMPS의 출력을 확인하십시요. */
#define CTS_EMG_OVER_HEAT				7	/*!< 과열 감지(Module) (Equipment overheating) \n 장비가 과열되었습니다. 장비 동작 중에 충방전기의 냉각 FAN이 정상 동작 중 인지 확인한 후 냉각 공기 흐름을 방해하는 요소를 제거 하십시요. */
#define CTS_EMG_POWER_OFF_SWITCH		8	/*!< 동작중 Power Off Switch 감지 (Detect power off switch during operation) \n 장비 Run중 Power Off Switch를 눌렀음 */
#define CTS_EMG_NORMAL_POWER_OFF		9	/*!< Normal Power Off 감지 (Detect normal power off) \n 정상적으로 Power Off Switch를 누름 */
#define CTS_EMG_POWER_OFF				10	/*!< 강제종료(Switch) (Force power off(Switch)) \n 설비가 동작(충방전 진행)중인데 강제 Power Off를 실시 하였습니다. 진행중인 자료는 모두 잃게 되고 Reset 됩니다. */
#define CTS_EMG_NORMAL_TERM_QUIT1		11	/*!< Normal Terminal Quit 감지 (Detect normal terminal quit) \n 정상적으로 Terminal에서 Quit됨 */
#define CTS_EMG_NORMAL_TERM_QUIT2		12	/*!< 강제종료(터미널2) (Force power off(Terminal2)) \n 장비 Run중 Terminal에서 Quit됨 */
#define CTS_EMG_NORMAL_TERM_HALT1		13	/*!< Normal Terminal Halt 감지 (Detect normal terminal halt) \n 정상적으로 Terminal에서 Halt됨 */
#define CTS_EMG_NORMAL_TERM_HALT2		14	/*!< 강제종료(터미널1) (Force power off(Terminal2)) \n 장비 Run중 Terminal에서 Halt됨 */
#define CTS_EMG_CPU_WATCHDOG			15	/*!< CPU Watchdog \n 제어 CPU의 동작이 정상적이 않거나 내부 S/W오류에 의해 rebooting 됩니다. 진행중인 자료는 초기화 됩니다. */
#define CTS_EMG_DMM_COMM_ERROR			16	/*!< 교정용 DMM과 통신 Error 발생 (Communication error with calibration DMM) \n 외부 계측기와 통신 오류가 발생하였습니다. 통신선을 확인 바랍니다. */
#define CTS_EMG_CAL_COMM_ERROR			17	/*!< 교정용 Tool과 통신 Error 발생 (Communication error with calibration tool) \n 외부 교정장치와 통신 오류가 발생하였습니다. 통신선을 확인 바랍니다. */
#define CTS_EMG_FUSE_ERROR				18	/*!< 장비 Fuse 단선 (Equipment fuse disconnection) \n */
#define CTS_EMG_MAIN_POWER_OVER_VOLT	19	/*!< Main 전원 Over Voltage (Main power over voltage) \n */
#define CTS_EMG_MAIN_POWER_UNDER_VOLT	20	/*!< Main 전원 Under Voltage (Main power under voltage) \n */
#define CTS_EMG_MAIN_POWER_ERROR		21	/*!< Main 전원 이상 (Main power failure) \n */
#define CTS_EMG_FAN_ERROR				22	/*!< 냉각팬 이상 (Cooling fan failure) \n */
#define CTS_EMG_POWER_TRANSF_ERROR		23	/*!< Main Power Transformer 과열 (Main power transformer overheating) \n */
#define CTS_EMG_POWER_REACT_ERROR		24	/*!< Main Power Reactor 과열 (Main power reactor overheating) \n */
#define CTS_EMG_OUTCTRL_OVER_VOLTAGE	50	/*!< 출력 제어 전압 초과 (Output control voltage over) \n 출력 전압 초과 */
#define CTS_EMG_OUTCTRL_OVER_CURRNET	51	/*!< 출력 제어 전류 초과 (Output control current over) \n 출력 전류 초과 */
#define CTS_EMG_RUN_TIME_OVER			52	/*!< Run Time Over \n전체 동작 시간 초과 */
#define CTS_EMG_DATA_SAVE_ERROR			53	/*!< Data 저장 오류(DataSave) (Data save error) \n 충방전기 내부 저장 실패 */
#define CTS_EMG_ADC_ERROR				54	/*!< ADC 이상(Group) (ADC error(Group)) \n Analog to Digital Converter 이상(Group) */
#define CTS_EMG_OVERHEAT_GROUP			55	/*!< 과열 감지(Group) (Detect overheating(Group)) \n 장비가 과열되었습니다. 장비 동작 중에 충방전기의 냉각 FAN이 정상 동작 중 인지 확인한 후 냉각 공기 흐름을 방해하는 요소를 제거 하십시요. */
#define CTS_EMG_OVERHEAT_BD				100	/*!< 과열 감지(BD)\n (Detect overheating(BD)) 장비가 과열되었습니다. 장비 동작 중에 충방전기의 냉각 FAN이 정상 동작 중 인지 확인한 후 냉각 공기 흐름을 방해하는 요소를 제거 하십시요. */
#define CTS_EMG_ADC_ERROR_BD			101	/*!< ADC 이상(BD) (ADC error(BD)) \n Analog to Digital Converter 이상(Board) */
/** @} */ //Emergency Code 정의 끝
