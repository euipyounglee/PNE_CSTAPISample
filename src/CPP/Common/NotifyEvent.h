/** 
 *@file		NotifyEvent.h
 *@brief	���� �̺�Ʈ ���� ��� ���� �Դϴ�.								
 *@author	PNE Solution (Kang se-jun)
 *@date		2019-03-22
 */


/** @defgroup NotifyEvent Notify Event Messages
 *  @ingroup define
 *  @brief 
 *  Notify Event\n
 *  @details
 *	API���� Host�� �����ϴ� �̺�Ʈ Window Message �Դϴ�.\n
  *	@code {.cpp}
 *	CTS_DLL_API int ctsServerCreate  ( int  nInstalledModuleNo,   HWND  hWnd  )  
  *	@endcode
 *  �ʱ�ȭ�� �Էµ� Host App�� Handle(HWND hWnd)�� �̺�Ʈ �߻��� Window Message�� �뺸�մϴ�.
 *	@code {.cpp}
 *	#define WM_USER                         0x0400
 *	@endcode
 *  @{
 */

//Definitions
//Module Window Message

/*! 
   \brief ��� ���� ���� �̺�Ʈ\n
   \details
   ������� ����� ���°� ����Ǿ����� �����մϴ�.
   \param wParam [WPARAM] \n (int) ModuleID �۾��� �Ϸ�� ��������� ModuleID(1-base)
   \param lParam [LPARAM] \n 0. ��� ����.
*/
//#define CTS_MODULE_STATE_CHANGE			WM_USER+2000

/*! 
   \brief ��� ��� ���� �̺�Ʈ\n
   \details
   ������� ����� ���ӵǾ����� �����մϴ�.
   \param wParam [WPARAM] \n (int) ModuleID �۾��� �Ϸ�� ��������� ModuleID(1-base)
   \param lParam [LPARAM] \n (#CTS_MD_SYSTEM_DATA*). �ý��� ���� ����ü�� �ּ�.
*/
#define CTS_MODULE_CONNECTED			WM_USER+2001

/*! 
   \brief ��� ��� ���� �̺�Ʈ\n
   \details
   ������� ����� ����� ����Ǿ����� �����մϴ�.
   \param wParam [WPARAM] \n (int) ModuleID ����� ����� ��������� ModuleID(1-base)
   \param lParam [LPARAM] \n 0. ��� ����.
*/
#define CTS_MODULE_CLOSED				WM_USER+2002

/*! 
   \brief ���� �Ϸ� �̺�Ʈ
   \param wParam [WPARAM] \n
		  (HIWORD) ModuleID ������ �Ϸ�� ��������� ModuleID(1-base)	/  (LOWORD) ChannelIndex ������ �Ϸ�� ��������� ChannelIndex(0-base) \n
   \param lParam [LPARAM] \n 
		  (int) StepNo �Ϸ�� ���� ��ȣ(1-base)
   \details
		  wParam�� 32bit ���� ���� 16bit�� ModuleID ���� �����ϰ� ���� 16bit ���� ChannelIndex�� �����մϴ�.\n
		  ���� 16bit�� �����Ͽ� ModuleID�� ChannelID�� ���ؾ��մϴ�.\n		  
*/
#define CTS_STEP_ENDDATA_RECEIVE		WM_USER+2003


/*! 
   \brief ������� ������ ���� �̺�Ʈ
   \param wParam [WPARAM] \n (int) ModuleID �˶��� �߻��� ��������� ModuleID(1-base)
   \param lParam [LPARAM] \n (#CTS_EMG_DATA*) ���˶� �ڵ� ����ü �ּ�
*/
#define CTS_MODULE_EMG					WM_USER+2006


/*! 
   \brief �۾� �Ϸ� �̺�Ʈ
   \param wParam [WPARAM] \n (int) ModuleID �۾��� �Ϸ�� ��������� ModuleID(1-base)
   \param lParam [LPARAM] \n (int) ChannelIndex �۾��� �Ϸ�� ��������� ChannelIndex(0-base) 
*/
#define CTS_TEST_COMPLETE				WM_USER+2011


//#define CTS_STEP_INFO_DATA				WM_USER+2021		/*!< ���� ���� ���� �̺�Ʈ  */
//#define CTS_SAFETY_INFO_DATA			WM_USER+2022		/*!< ���� ���� ���� �̺�Ʈ  */

/*! 
   \brief ��ó�� ������ ��� �̺�Ʈ\n
   \details
   API ���� �޸�(ť)�� ������ (30��) �̻��� ��ó�� �����Ͱ� ���� ��� Host App�� �����մϴ�.\n
   �� �̺�Ʈ ���� �Ǵ� ���� �ֱ�� ctsGetStackedDataSize(), ctsPopSaveData()�Լ��� ȣ���Ͽ� �����͸� ������ ��ũ ���� �� ������ ó���� ���־���մϴ�.\n
   \param wParam [WPARAM] \n (int) ModuleID �ش� ��������� ModuleID(1-base)
   \param lParam [LPARAM] \n (#CTS_EMG_DATA*) ���˶� �ڵ� ����ü �ּ�
*/
#define CTS_DATA_STACKED_NOTIFY			WM_USER+2015


/*! 
   \brief ������ �̺�Ʈ\n
   \details
   API ���� �����͸� Host App�� �����մϴ�.\n
   �� �̺�Ʈ ������ ctsPopSaveData()�Լ��� �׿� �ִ� data�� popup������ �ʽ��ϴ�.\n
   \param wParam [WPARAM] \n
   (HIWORD) ModuleID ��������� ModuleID(1-base)	/  (LOWORD) ChannelIndex ��������� ChannelIndex(0-base) \n
   \param lParam [LPARAM] \n (#CTS_VARIABLE_CH_DATA*) ���� ä�� ������ ����ü 
*/
#define CTS_DATA_NOTIFY					WM_USER+2012


/*! 
   \brief ������ �̺�Ʈ\n
   \details
   API ���� �����͸� Host App�� �����մϴ�.\n
   �� �̺�Ʈ ������ ctsPopSaveData()�Լ��� �׿� �ִ� data�� popup������ �ʽ��ϴ�.\n
   \param wParam [WPARAM] \n
   (HIWORD) ModuleID ��������� ModuleID(1-base)	/  (LOWORD) ChannelIndex ��������� ChannelIndex(0-base) \n
   \param lParam [LPARAM] \n (#CTS_VARIABLE_CH_DATA_D*) ���� ä�� ������ ����ü 
*/
#define CTS_DATA_NOTIFY_D					WM_USER+2013


/*! 
   \brief ������ �̺�Ʈ\n
   \details
   API ���� �����͸� Host App�� �����մϴ�.\n
   �� �̺�Ʈ ������ ctsPopSaveData()�Լ��� �׿� �ִ� data�� popup������ �ʽ��ϴ�.\n
   \param wParam [WPARAM] \n
   (HIWORD) ModuleID ��������� ModuleID(1-base)	/  (LOWORD) ChannelIndex ��������� ChannelIndex(0-base) \n
   \param lParam [LPARAM] \n (#CTS_VARIABLE_CH_DATA_F*) ���� ä�� ������ ����ü 
*/
#define CTS_DATA_NOTIFY_F					WM_USER+2014

/** @} */ //NotifyEvent ���� ��


