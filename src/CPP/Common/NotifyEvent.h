/** 
 *@file		NotifyEvent.h
 *@brief	통지 이벤트 정의 헤더 파일 입니다.								
 *@author	PNE Solution (Kang se-jun)
 *@date		2019-03-22
 */


/** @defgroup NotifyEvent Notify Event Messages
 *  @ingroup define
 *  @brief 
 *  Notify Event\n
 *  @details
 *	API에서 Host에 통지하는 이벤트 Window Message 입니다.\n
  *	@code {.cpp}
 *	CTS_DLL_API int ctsServerCreate  ( int  nInstalledModuleNo,   HWND  hWnd  )  
  *	@endcode
 *  초기화시 입력된 Host App의 Handle(HWND hWnd)에 이벤트 발생시 Window Message를 통보합니다.
 *	@code {.cpp}
 *	#define WM_USER                         0x0400
 *	@endcode
 *  @{
 */

//Definitions
//Module Window Message

/*! 
   \brief 모듈 상태 변경 이벤트\n
   \details
   충방전기 모듈의 상태가 변경되었음을 통지합니다.
   \param wParam [WPARAM] \n (int) ModuleID 작업이 완료된 충방전기의 ModuleID(1-base)
   \param lParam [LPARAM] \n 0. 사용 안함.
*/
//#define CTS_MODULE_STATE_CHANGE			WM_USER+2000

/*! 
   \brief 모듈 통신 접속 이벤트\n
   \details
   충방전기 모듈이 접속되었음을 통지합니다.
   \param wParam [WPARAM] \n (int) ModuleID 작업이 완료된 충방전기의 ModuleID(1-base)
   \param lParam [LPARAM] \n (#CTS_MD_SYSTEM_DATA*). 시스템 정보 구조체의 주소.
*/
#define CTS_MODULE_CONNECTED			WM_USER+2001

/*! 
   \brief 모듈 통신 종료 이벤트\n
   \details
   충방전기 모듈의 통신이 종료되었음을 통지합니다.
   \param wParam [WPARAM] \n (int) ModuleID 통신이 종료된 충방전기의 ModuleID(1-base)
   \param lParam [LPARAM] \n 0. 사용 안함.
*/
#define CTS_MODULE_CLOSED				WM_USER+2002

/*! 
   \brief 스텝 완료 이벤트
   \param wParam [WPARAM] \n
		  (HIWORD) ModuleID 스텝이 완료된 충방전기의 ModuleID(1-base)	/  (LOWORD) ChannelIndex 스텝이 완료된 충방전기의 ChannelIndex(0-base) \n
   \param lParam [LPARAM] \n 
		  (int) StepNo 완료된 스텝 번호(1-base)
   \details
		  wParam의 32bit 값중 상위 16bit는 ModuleID 값을 포함하고 하위 16bit 값은 ChannelIndex를 포함합니다.\n
		  각각 16bit씩 분할하여 ModuleID와 ChannelID를 취해야합니다.\n		  
*/
#define CTS_STEP_ENDDATA_RECEIVE		WM_USER+2003


/*! 
   \brief 충방전기 비상상태 통지 이벤트
   \param wParam [WPARAM] \n (int) ModuleID 알람이 발생한 충방전기의 ModuleID(1-base)
   \param lParam [LPARAM] \n (#CTS_EMG_DATA*) 비상알람 코드 구조체 주소
*/
#define CTS_MODULE_EMG					WM_USER+2006


/*! 
   \brief 작업 완료 이벤트
   \param wParam [WPARAM] \n (int) ModuleID 작업이 완료된 충방전기의 ModuleID(1-base)
   \param lParam [LPARAM] \n (int) ChannelIndex 작업이 완료된 충방전기의 ChannelIndex(0-base) 
*/
#define CTS_TEST_COMPLETE				WM_USER+2011


//#define CTS_STEP_INFO_DATA				WM_USER+2021		/*!< 스텝 정보 수신 이벤트  */
//#define CTS_SAFETY_INFO_DATA			WM_USER+2022		/*!< 안전 조건 수신 이벤트  */

/*! 
   \brief 미처리 데이터 경고 이벤트\n
   \details
   API 내부 메모리(큐)에 일정량 (30개) 이상의 미처리 데이터가 쌓인 경우 Host App에 통지합니다.\n
   본 이벤트 수신 또는 일정 주기로 ctsGetStackedDataSize(), ctsPopSaveData()함수를 호출하여 데이터를 꺼내어 디스크 저장 등 별도의 처리를 해주어야합니다.\n
   \param wParam [WPARAM] \n (int) ModuleID 해당 충방전기의 ModuleID(1-base)
   \param lParam [LPARAM] \n (#CTS_EMG_DATA*) 비상알람 코드 구조체 주소
*/
#define CTS_DATA_STACKED_NOTIFY			WM_USER+2015


/*! 
   \brief 데이터 이벤트\n
   \details
   API 내부 데이터를 Host App에 통지합니다.\n
   본 이벤트 수신은 ctsPopSaveData()함수에 쌓여 있는 data를 popup하지는 않습니다.\n
   \param wParam [WPARAM] \n
   (HIWORD) ModuleID 충방전기의 ModuleID(1-base)	/  (LOWORD) ChannelIndex 충방전기의 ChannelIndex(0-base) \n
   \param lParam [LPARAM] \n (#CTS_VARIABLE_CH_DATA*) 종합 채널 데이터 구조체 
*/
#define CTS_DATA_NOTIFY					WM_USER+2012


/*! 
   \brief 데이터 이벤트\n
   \details
   API 내부 데이터를 Host App에 통지합니다.\n
   본 이벤트 수신은 ctsPopSaveData()함수에 쌓여 있는 data를 popup하지는 않습니다.\n
   \param wParam [WPARAM] \n
   (HIWORD) ModuleID 충방전기의 ModuleID(1-base)	/  (LOWORD) ChannelIndex 충방전기의 ChannelIndex(0-base) \n
   \param lParam [LPARAM] \n (#CTS_VARIABLE_CH_DATA_D*) 종합 채널 데이터 구조체 
*/
#define CTS_DATA_NOTIFY_D					WM_USER+2013


/*! 
   \brief 데이터 이벤트\n
   \details
   API 내부 데이터를 Host App에 통지합니다.\n
   본 이벤트 수신은 ctsPopSaveData()함수에 쌓여 있는 data를 popup하지는 않습니다.\n
   \param wParam [WPARAM] \n
   (HIWORD) ModuleID 충방전기의 ModuleID(1-base)	/  (LOWORD) ChannelIndex 충방전기의 ChannelIndex(0-base) \n
   \param lParam [LPARAM] \n (#CTS_VARIABLE_CH_DATA_F*) 종합 채널 데이터 구조체 
*/
#define CTS_DATA_NOTIFY_F					WM_USER+2014

/** @} */ //NotifyEvent 정의 끝


