
// MFC Application SampleDlg.cpp : 구현 파일
//

#include "stdafx.h"
#include "MFC Application Sample.h"
#include "MFC Application SampleDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

CWnd* g_pParent;

CTS_MD_SYSTEM_DATA gst_SystemData;

CRITICAL_SECTION cs;

// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMFCApplicationSampleDlg 대화 상자
CMFCApplicationSampleDlg::CMFCApplicationSampleDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMFCApplicationSampleDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_hDll = NULL;
	m_nLoadCount = 0; //ksj 20191213
	m_nUnloadCount = 0; //ksj 20191213
}

void CMFCApplicationSampleDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);

	DDX_Control(pDX, IDC_STATIC_CH1_STATUS, m_StatusCh1);
	DDX_Control(pDX, IDC_STATIC_CH2_STATUS, m_StatusCh2);
	DDX_Control(pDX, IDC_STATIC_CH3_STATUS, m_StatusCh3);
	DDX_Control(pDX, IDC_STATIC_CH4_STATUS, m_StatusCh4);

	DDX_Control(pDX, IDC_BUTTON_CONNECT, m_btConnect);

	DDX_Control(pDX, IDC_BUTTON_SEND_SCHEDULE, m_btSensSchedule);
	DDX_Control(pDX, IDC_BUTTON_AUX_DATA, m_btSetAuxData);
	DDX_Control(pDX, IDC_BUTTON_CAN_REV, m_btSetCANReceive);
	DDX_Control(pDX, IDC_BUTTON_CAN_TRAN, m_btSetCANTrancemit);
	DDX_Control(pDX, IDC_BUTTON_PARALLEL, m_btSetParallel);
	DDX_Control(pDX, IDC_BUTTON_AUX_DATA_GET, m_btSetAuxDataGet);
	DDX_Control(pDX, IDC_BUTTON_AUX_DATA_GET_INFO, m_btSetAuxDataGetInfo);
	DDX_Control(pDX, IDC_BUTTON_CAN_REV_GET, m_btSetCANReceiveGet);
	DDX_Control(pDX, IDC_BUTTON_CAN_TRAN_GET, m_btSetCANTrancemitGet);
	DDX_Control(pDX, IDC_BUTTON_PARALLEL_GET, m_btSetParallelGet);
	DDX_Control(pDX, IDC_BUTTON_LIN_TO_CAN_START, m_btLintoCAN);

	DDX_Control(pDX, IDC_LIST_RECV, m_ListRecv);
		
	DDX_Control(pDX, IDC_EDIT_SEND_SCHEDULE_CH_NUM, m_SendScheduleChNum);
	DDX_Control(pDX, IDC_EDIT_SEND_PARALLEL_MASTER, m_SendParallel1);
	DDX_Control(pDX, IDC_EDIT_SEND_PARALLEL_SLAVE, m_SendParallel2);
}

BEGIN_MESSAGE_MAP(CMFCApplicationSampleDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()

	ON_BN_CLICKED(IDC_BUTTON_TEST, &CMFCApplicationSampleDlg::OnBnClickedButtonTest)
	ON_BN_CLICKED(IDC_BUTTON_CONNECT, &CMFCApplicationSampleDlg::OnBnClickedButtonConnect)
	ON_BN_CLICKED(IDC_BUTTON_SEND_SCHEDULE, &CMFCApplicationSampleDlg::OnBnClickedButtonSendSchedule)
	ON_BN_CLICKED(IDC_BUTTON_AUX_DATA, &CMFCApplicationSampleDlg::OnBnClickedButtonAuxData)
	ON_BN_CLICKED(IDC_BUTTON_CAN_REV, &CMFCApplicationSampleDlg::OnBnClickedButtonCanRev)
	ON_BN_CLICKED(IDC_BUTTON_CAN_TRAN, &CMFCApplicationSampleDlg::OnBnClickedButtonCanTran)
	ON_BN_CLICKED(IDC_BUTTON_PARALLEL, &CMFCApplicationSampleDlg::OnBnClickedButtonParallel)
	ON_BN_CLICKED(IDC_BUTTON_LIN_TO_CAN_START, &CMFCApplicationSampleDlg::OnBnClickedButtonLinToCanStart)

	ON_BN_CLICKED(IDC_BUTTON_AUX_DATA_GET_INFO, &CMFCApplicationSampleDlg::OnBnClickedButtonAuxDataGetInfo)
	ON_BN_CLICKED(IDC_BUTTON_CAN_REV_GET, &CMFCApplicationSampleDlg::OnBnClickedButtonCanRevGet)
	ON_BN_CLICKED(IDC_BUTTON_CAN_TRAN_GET, &CMFCApplicationSampleDlg::OnBnClickedButtonCanTranGet)
	ON_BN_CLICKED(IDC_BUTTON_PARALLEL_GET, &CMFCApplicationSampleDlg::OnBnClickedButtonParallelGet)
	ON_BN_CLICKED(IDC_BUTTON_AUX_DATA_GET, &CMFCApplicationSampleDlg::OnBnClickedButtonAuxDataGet)

	ON_BN_CLICKED(IDOK, &CMFCApplicationSampleDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &CMFCApplicationSampleDlg::OnBnClickedCancel)

	ON_WM_TIMER()
	ON_WM_CLOSE()

#if 0
	ON_MESSAGE(CTS_MODULE_CONNECTED, &CMFCApplicationSampleDlg::OnModuleConnected)
	ON_MESSAGE(CTS_MODULE_CLOSED, &CMFCApplicationSampleDlg::OnModuleClosed)
	ON_MESSAGE(CTS_DATA_NOTIFY, &CMFCApplicationSampleDlg::OnGetChData)
	ON_MESSAGE(CTS_DATA_STACKED_NOTIFY, &CMFCApplicationSampleDlg::OnDataStackedNotify)
	ON_MESSAGE(CTS_TEST_COMPLETE, &CMFCApplicationSampleDlg::OnTestComplete)
	ON_MESSAGE(CTS_MODULE_EMG, &CMFCApplicationSampleDlg::OnEmg)
#endif

	ON_BN_CLICKED(IDC_BUTTON_TEST3, &CMFCApplicationSampleDlg::OnBnClickedButtonTest3)
	ON_BN_CLICKED(IDC_BUTTON_TEST4, &CMFCApplicationSampleDlg::OnBnClickedButtonTest4)
	ON_BN_CLICKED(IDC_BUTTON_TEST5, &CMFCApplicationSampleDlg::OnBnClickedButtonTest5)
	ON_BN_CLICKED(IDC_BUTTON_TEST6, &CMFCApplicationSampleDlg::OnBnClickedButtonTest6)
	ON_BN_CLICKED(IDC_BUTTON_TEST7, &CMFCApplicationSampleDlg::OnBnClickedButtonTest7)
	ON_BN_CLICKED(IDC_BUTTON_TEST8, &CMFCApplicationSampleDlg::OnBnClickedButtonTest8)
	ON_BN_CLICKED(IDC_BUTTON_TEST9, &CMFCApplicationSampleDlg::OnBnClickedButtonTest9)
	ON_BN_CLICKED(IDC_BUTTON_TEST10, &CMFCApplicationSampleDlg::OnBnClickedButtonTest10)
	ON_BN_CLICKED(IDC_BUTTON_TEST11, &CMFCApplicationSampleDlg::OnBnClickedButtonTest11)
	ON_BN_CLICKED(IDC_BUTTON_LOAD_DLL, &CMFCApplicationSampleDlg::OnBnClickedButtonLoadDll)
	ON_BN_CLICKED(IDC_BUTTON_UNLOAD_DLL, &CMFCApplicationSampleDlg::OnBnClickedButtonUnloadDll)
	ON_BN_CLICKED(IDC_BUTTON_DEBUG, &CMFCApplicationSampleDlg::OnBnClickedButtonDebug)
	ON_BN_CLICKED(IDC_BUTTON_AUX_RELEASE, &CMFCApplicationSampleDlg::OnBnClickedButtonAuxRelease)
	ON_BN_CLICKED(IDC_BUTTON_TEST12, &CMFCApplicationSampleDlg::OnBnClickedButtonTest12)
	ON_BN_CLICKED(IDC_BUTTON_ISO, &CMFCApplicationSampleDlg::OnBnClickedButtonIso)
	ON_BN_CLICKED(IDC_BUTTON_NON_ISO, &CMFCApplicationSampleDlg::OnBnClickedButtonNonIso)
	ON_BN_CLICKED(IDC_BUTTON_GET_STEP_COUNT, &CMFCApplicationSampleDlg::OnBnClickedButtonGetStepCount)
	ON_BN_CLICKED(IDC_BUTTON_GET_SCH_STEPINFO, &CMFCApplicationSampleDlg::OnBnClickedButtonGetSchStepinfo)
	ON_BN_CLICKED(IDC_BUTTON_GET_CB_INFO, &CMFCApplicationSampleDlg::OnBnClickedButtonGetCbInfo)
	ON_BN_CLICKED(IDC_BUTTON_CONNECT_THREAD, &CMFCApplicationSampleDlg::OnBnClickedButtonConnectThread)
	ON_BN_CLICKED(IDC_BUTTON_CLOSE_THREAD, &CMFCApplicationSampleDlg::OnBnClickedButtonCloseThread)
	ON_BN_CLICKED(IDC_BUTTON_SEND_SCHEDULE2, &CMFCApplicationSampleDlg::OnBnClickedButtonSendSchedule2)
	ON_BN_CLICKED(IDC_BUTTON_POP_TEST, &CMFCApplicationSampleDlg::OnBnClickedButtonPopTest)
	ON_BN_CLICKED(IDC_BUTTON_SEND_SCHEDULE3, &CMFCApplicationSampleDlg::OnBnClickedButtonSendSchedule3)
END_MESSAGE_MAP()

///////////////////////////////////////////////////////////////////////////
// Callback Function Define
///////////////////////////////////////////////////////////////////////////
void TestCallBackConnected(int test, CTS_MD_SYSTEM_DATA* sysInfo)
{
	//AfxMessageBox("Call Back Success");

	((CMFCApplicationSampleDlg*)g_pParent)->AddLog("Call Back Success");
	((CMFCApplicationSampleDlg*)g_pParent)->KillTimer(1001);
	((CMFCApplicationSampleDlg*)g_pParent)->m_ListRecv.ResetContent();

	int nModuleID = (int)test; //모듈 ID
	CString strAddLog;

	memcpy(&gst_SystemData, (void*)sysInfo,sizeof(CTS_MD_SYSTEM_DATA)); //충방전기 시스템 정보

	strAddLog.Format("ModuleID : %d",nModuleID);
	((CMFCApplicationSampleDlg*)g_pParent)->AddLog(strAddLog);

	strAddLog.Format("Protocol Ver. : 0x%04x\r\n",sysInfo->nProtocolVersion);
	((CMFCApplicationSampleDlg*)g_pParent)->AddLog(strAddLog);

	strAddLog.Format("Installed ch Num : %d\r\n\r\n",sysInfo->nInstalledChCount);
	((CMFCApplicationSampleDlg*)g_pParent)->AddLog(strAddLog);

	((CMFCApplicationSampleDlg*)g_pParent)->UpdateDlg(TRUE);//버튼및 동작 활성화
	
	((CMFCApplicationSampleDlg*)g_pParent)->m_bConnected = TRUE;
}

void TestCallBackGetChData(unsigned int nModIDandChIdex , CTS_VARIABLE_CH_DATA* ChData)
{
#ifdef _DEBUG
	//ksj 20210407 : 콜백함수 호출 주기 추적용.
	SYSTEMTIME time;
	GetSystemTime(&time);
	TRACE("TestCallBackGetChData %02d:%02d:%02d.%03d\n",time.wHour,time.wMinute,time.wSecond,time.wMilliseconds);
#endif
	int nModuleID, nChIndex = 0;
	nChIndex = HIWORD(nModIDandChIdex);
	nModuleID = LOWORD(nModIDandChIdex);

	if (((CMFCApplicationSampleDlg*)g_pParent)->m_bConnected == TRUE)
	{
		if (gst_SystemData.nInstalledChCount != 0) {

			CTS_VARIABLE_CH_DATA sVarChResultData;
			ZeroMemory(&sVarChResultData, sizeof(CTS_VARIABLE_CH_DATA));
			memcpy(&sVarChResultData, ChData, sizeof(CTS_VARIABLE_CH_DATA));

			CString strState;
			switch (sVarChResultData.chData.chState)
			{
			case PS_STATE_LINE_OFF:
				strState = "disconnected";
				break;
			case PS_STATE_LINE_ON:
				strState = "connected";
				break;
			case PS_STATE_READY:
				strState = "ready";
				break;
			case PS_STATE_IDLE:
				strState = "idle";
				break;
			case PS_STATE_STANDBY:
				strState = "standby";
				break;
			case PS_STATE_RUN:
				if (sVarChResultData.chData.chStepType == PS_STEP_NONE)
				{
					strState = "run";
					//str.Format("None [%x]", sVarChResultData.chData.chMode);
				}
				else if (sVarChResultData.chData.chStepType == PS_STEP_CHARGE)
				{
					strState = "Charge";
				}
				else if (sVarChResultData.chData.chStepType == PS_STEP_DISCHARGE)
				{
					strState = "Discharge";
				}
				else if (sVarChResultData.chData.chStepType == PS_STEP_REST)
				{
					strState = "Rest";
				}
				else if (sVarChResultData.chData.chStepType == PS_STEP_OCV)
				{
					strState = "OCV";
				}
				else if (sVarChResultData.chData.chStepType == PS_STEP_IMPEDANCE)
				{
					strState = "Impedance";
				}
				else if (sVarChResultData.chData.chStepType == PS_STEP_END)
				{
					strState = "End";
				}
				else if (sVarChResultData.chData.chStepType == PS_STEP_LOOP)
				{
					strState = "Loop";
				}
				else if (sVarChResultData.chData.chStepType == PS_STEP_PATTERN)
				{
					strState = "Pattern";
				}
				break;
			case PS_STATE_PAUSE:
				strState = "pause";
				break;
			case PS_STATE_MAINTENANCE:
				strState = "maintenance";
				break;
			case PS_STATE_END:
				strState = "Complete";
				break;
			default:
				strState = "disconnected";
				break;
			}

			CString strOut;
			if (sVarChResultData.chData.chNo == 1)
			{
				strOut.Format("State : %s, Voltage : %.3lfV, Current : %.3lfA, Code : %d", \
					strState, sVarChResultData.chData.lVoltage/1000000.0f, sVarChResultData.chData.lCurrent/1000000.0f, sVarChResultData.chData.chCode);
				((CMFCApplicationSampleDlg*)g_pParent)->m_StatusCh1.SetWindowTextA(strOut);
				

				/*strOut.Format("curcyc: %d totcyc: %d State : %s, Voltage : %.3lfV, Current : %.3lfA, Code : %d", \
					sVarChResultData.chData.nCurrentCycleNum, sVarChResultData.chData.nTotalCycleNum, str, sVarChResultData.chData.lVoltage/1000000.0f, sVarChResultData.chData.lCurrent/1000000.0f, sVarChResultData.chData.chCode);
				((CMFCApplicationSampleDlg*)g_pParent)->m_StatusCh1.SetWindowTextA(strOut);*/

			}
			else if (sVarChResultData.chData.chNo == 2)
			{
				strOut.Format("State : %s, Voltage : %.3lfV, Current : %.3lfA, Code : %d", \
					strState, sVarChResultData.chData.lVoltage/1000000.0f, sVarChResultData.chData.lCurrent/1000000.0f, sVarChResultData.chData.chCode);
				((CMFCApplicationSampleDlg*)g_pParent)->m_StatusCh2.SetWindowTextA(strOut);
			}
			else if (sVarChResultData.chData.chNo == 3)
			{
				strOut.Format("State : %s, Voltage : %.3lfV, Current : %.3lfA, Code : %d", \
					strState, sVarChResultData.chData.lVoltage/1000000.0f, sVarChResultData.chData.lCurrent/1000000.0f, sVarChResultData.chData.chCode);
				((CMFCApplicationSampleDlg*)g_pParent)->m_StatusCh3.SetWindowTextA(strOut);
			}
			else if (sVarChResultData.chData.chNo == 4)
			{
				strOut.Format("State : %s, Voltage : %.3lfV, Current : %.3lfA, Code : %d", \
					strState, sVarChResultData.chData.lVoltage/1000000.0f, sVarChResultData.chData.lCurrent/1000000.0f, sVarChResultData.chData.chCode);
				((CMFCApplicationSampleDlg*)g_pParent)->m_StatusCh4.SetWindowTextA(strOut);
			}
		}
	}
}

void TestCallBackGetChDataF(unsigned int nModIDandChIdex , CTS_VARIABLE_CH_DATA_F* ChData)
{
	int nModuleID, nChIndex = 0;
	nChIndex = HIWORD(nModIDandChIdex);
	nModuleID = LOWORD(nModIDandChIdex);

	if (((CMFCApplicationSampleDlg*)g_pParent)->m_bConnected == TRUE)
	{
		if (gst_SystemData.nInstalledChCount != 0) {

			CTS_VARIABLE_CH_DATA sVarChResultData;
			ZeroMemory(&sVarChResultData, sizeof(CTS_VARIABLE_CH_DATA));
			memcpy(&sVarChResultData, ChData, sizeof(CTS_VARIABLE_CH_DATA));

			CString str;
			switch (sVarChResultData.chData.chState)
			{
			case PS_STATE_LINE_OFF:
				str = "disconnected";
				break;
			case PS_STATE_LINE_ON:
				str = "connected";
				break;
			case PS_STATE_READY:
				str = "ready";
				break;
			case PS_STATE_IDLE:
				str = "idle";
				break;
			case PS_STATE_STANDBY:
				str = "standby";
				break;
			case PS_STATE_RUN:
				if (sVarChResultData.chData.chStepType == PS_STEP_NONE)
				{
					str = "run";
					//str.Format("None [%x]", sVarChResultData.chData.chMode);
				}
				else if (sVarChResultData.chData.chStepType == PS_STEP_CHARGE)
				{
					str = "Charge";
				}
				else if (sVarChResultData.chData.chStepType == PS_STEP_DISCHARGE)
				{
					str = "Discharge";
				}
				else if (sVarChResultData.chData.chStepType == PS_STEP_REST)
				{
					str = "Rest";
				}
				else if (sVarChResultData.chData.chStepType == PS_STEP_OCV)
				{
					str = "OCV";
				}
				else if (sVarChResultData.chData.chStepType == PS_STEP_IMPEDANCE)
				{
					str = "Impedance";
				}
				else if (sVarChResultData.chData.chStepType == PS_STEP_END)
				{
					str = "End";
				}
				else if (sVarChResultData.chData.chStepType == PS_STEP_LOOP)
				{
					str = "Loop";
				}
				else if (sVarChResultData.chData.chStepType == PS_STEP_PATTERN)
				{
					str = "Pattern";
				}
				break;
			case PS_STATE_PAUSE:
				str = "pause";
				break;
			case PS_STATE_MAINTENANCE:
				str = "maintenance";
				break;
			case PS_STATE_END:
				str = "Complete";
				break;
			default:
				str = "disconnected";
				break;
			}

			CString strOut;
			if (sVarChResultData.chData.chNo == 1)
			{
				strOut.Format("State : %s, Voltage : %.3lfV, Current : %.3lfA, Code : %d, can : %.3lf", \
					str, sVarChResultData.chData.lVoltage/1000000.0f, sVarChResultData.chData.lCurrent/1000000.0f, sVarChResultData.chData.chCode, sVarChResultData.canData[56].canVal.fVal[0]);
				((CMFCApplicationSampleDlg*)g_pParent)->m_StatusCh1.SetWindowTextA(strOut);
			}
			else if (sVarChResultData.chData.chNo == 2)
			{
				strOut.Format("State : %s, Voltage : %.3lfV, Current : %.3lfA, Code : %d can : %.3lf", \
					str, sVarChResultData.chData.lVoltage/1000000.0f, sVarChResultData.chData.lCurrent/1000000.0f, sVarChResultData.chData.chCode, sVarChResultData.canData[56].canVal.fVal[0]);
				((CMFCApplicationSampleDlg*)g_pParent)->m_StatusCh2.SetWindowTextA(strOut);
			}
			else if (sVarChResultData.chData.chNo == 3)
			{
				strOut.Format("State : %s, Voltage : %.3lfV, Current : %.3lfA, Code : %d, can : %.3lf", \
					str, sVarChResultData.chData.lVoltage/1000000.0f, sVarChResultData.chData.lCurrent/1000000.0f, sVarChResultData.chData.chCode, sVarChResultData.canData[56].canVal.fVal[0]);
				((CMFCApplicationSampleDlg*)g_pParent)->m_StatusCh3.SetWindowTextA(strOut);
			}
			else if (sVarChResultData.chData.chNo == 4)
			{
				strOut.Format("State : %s, Voltage : %.3lfV, Current : %.3lfA, Code : %d, can : %.3lf", \
					str, sVarChResultData.chData.lVoltage/1000000.0f, sVarChResultData.chData.lCurrent/1000000.0f, sVarChResultData.chData.chCode, sVarChResultData.canData[56].canVal.fVal[0]);
				((CMFCApplicationSampleDlg*)g_pParent)->m_StatusCh4.SetWindowTextA(strOut);
			}
		}
	}
}

void TestCallBackGetChDataD(unsigned int nModIDandChIdex , CTS_VARIABLE_CH_DATA_D* ChData)
{
	int nModuleID, nChIndex = 0;
	nChIndex = HIWORD(nModIDandChIdex);
	nModuleID = LOWORD(nModIDandChIdex);

	if (((CMFCApplicationSampleDlg*)g_pParent)->m_bConnected == TRUE)
	{
		if (gst_SystemData.nInstalledChCount != 0) {

			CTS_VARIABLE_CH_DATA sVarChResultData;
			ZeroMemory(&sVarChResultData, sizeof(CTS_VARIABLE_CH_DATA));
			memcpy(&sVarChResultData, ChData, sizeof(CTS_VARIABLE_CH_DATA));

			CString str;
			switch (sVarChResultData.chData.chState)
			{
			case PS_STATE_LINE_OFF:
				str = "disconnected";
				break;
			case PS_STATE_LINE_ON:
				str = "connected";
				break;
			case PS_STATE_READY:
				str = "ready";
				break;
			case PS_STATE_IDLE:
				str = "idle";
				break;
			case PS_STATE_STANDBY:
				str = "standby";
				break;
			case PS_STATE_RUN:
				if (sVarChResultData.chData.chStepType == PS_STEP_NONE)
				{
					str = "run";
					//str.Format("None [%x]", sVarChResultData.chData.chMode);
				}
				else if (sVarChResultData.chData.chStepType == PS_STEP_CHARGE)
				{
					str = "Charge";
				}
				else if (sVarChResultData.chData.chStepType == PS_STEP_DISCHARGE)
				{
					str = "Discharge";
				}
				else if (sVarChResultData.chData.chStepType == PS_STEP_REST)
				{
					str = "Rest";
				}
				else if (sVarChResultData.chData.chStepType == PS_STEP_OCV)
				{
					str = "OCV";
				}
				else if (sVarChResultData.chData.chStepType == PS_STEP_IMPEDANCE)
				{
					str = "Impedance";
				}
				else if (sVarChResultData.chData.chStepType == PS_STEP_END)
				{
					str = "End";
				}
				else if (sVarChResultData.chData.chStepType == PS_STEP_LOOP)
				{
					str = "Loop";
				}
				else if (sVarChResultData.chData.chStepType == PS_STEP_PATTERN)
				{
					str = "Pattern";
				}
				break;
			case PS_STATE_PAUSE:
				str = "pause";
				break;
			case PS_STATE_MAINTENANCE:
				str = "maintenance";
				break;
			case PS_STATE_END:
				str = "Complete";
				break;
			default:
				str = "disconnected";
				break;
			}

			CString strOut;
			if (sVarChResultData.chData.chNo == 1)
			{
				strOut.Format("State : %s, Voltage : %.3lfV, Current : %.3lfA, Code : %d", \
					str, sVarChResultData.chData.lVoltage/1000000.0f, sVarChResultData.chData.lCurrent/1000000.0f, sVarChResultData.chData.chCode);
				((CMFCApplicationSampleDlg*)g_pParent)->m_StatusCh1.SetWindowTextA(strOut);
			}
			else if (sVarChResultData.chData.chNo == 2)
			{
				strOut.Format("State : %s, Voltage : %.3lfV, Current : %.3lfA, Code : %d", \
					str, sVarChResultData.chData.lVoltage/1000000.0f, sVarChResultData.chData.lCurrent/1000000.0f, sVarChResultData.chData.chCode);
				((CMFCApplicationSampleDlg*)g_pParent)->m_StatusCh2.SetWindowTextA(strOut);
			}
			else if (sVarChResultData.chData.chNo == 3)
			{
				strOut.Format("State : %s, Voltage : %.3lfV, Current : %.3lfA, Code : %d", \
					str, sVarChResultData.chData.lVoltage/1000000.0f, sVarChResultData.chData.lCurrent/1000000.0f, sVarChResultData.chData.chCode);
				((CMFCApplicationSampleDlg*)g_pParent)->m_StatusCh3.SetWindowTextA(strOut);
			}
			else if (sVarChResultData.chData.chNo == 4)
			{
				strOut.Format("State : %s, Voltage : %.3lfV, Current : %.3lfA, Code : %d", \
					str, sVarChResultData.chData.lVoltage/1000000.0f, sVarChResultData.chData.lCurrent/1000000.0f, sVarChResultData.chData.chCode);
				((CMFCApplicationSampleDlg*)g_pParent)->m_StatusCh4.SetWindowTextA(strOut);
			}
		}
	}
}

void TestCallBackClosed(int nModuleID)
{
	CString strTemp;

	((CMFCApplicationSampleDlg*)g_pParent)->m_bConnected = FALSE;

	((CMFCApplicationSampleDlg*)g_pParent)->AddLog("========== closed ==========");

	strTemp.Format("ModuleID : %d is Closed",nModuleID);
	((CMFCApplicationSampleDlg*)g_pParent)->AddLog(strTemp);

	((CMFCApplicationSampleDlg*)g_pParent)->AddLog("========== closed ==========");

	((CMFCApplicationSampleDlg*)g_pParent)->UpdateDlg(FALSE);
}

void TestCallBackComplete(int nModuleID, int nChIndex)
{
	CString strOut;

	strOut.Format("Test Complete (ModuleID : %d, Channel : %d)",nModuleID, nChIndex);
	((CMFCApplicationSampleDlg*)g_pParent)->AddLog(strOut);
}

void TestCallStackNotify(int nModuleID, int nChIndex)
{
	CString strOut;
	CTS_VARIABLE_CH_DATA stGetPopData;
	CTS_VARIABLE_CH_DATA stPopData[32];

	ZeroMemory(&stPopData[0],sizeof(CTS_VARIABLE_CH_DATA)*32);

	// stack data popup
	int j = 0;
	int nStackSize = ctsGetStackedDataSize(nModuleID, nChIndex);
	//for (j = 0; j < nStackSize; j++)
	for (j = 0; j < nStackSize && j < 32; j++)
	{
		ZeroMemory(&stGetPopData,sizeof(CTS_VARIABLE_CH_DATA));
		ctsPopSaveData(nModuleID, nChIndex, &stGetPopData);
		memcpy(&stPopData[j], &stGetPopData, sizeof(CTS_VARIABLE_CH_DATA));
	}

	strOut.Format("Stack Notify (ModuleID : %d, Channel : %d, stack size : %d)",nModuleID, nChIndex, nStackSize);
	((CMFCApplicationSampleDlg*)g_pParent)->AddLog(strOut);
}

void TestCallStepEnd(int nModIDandChIdex , int nStepNum)
{
	int nModuleID, nChIndex = 0;
	nModuleID = HIWORD(nModIDandChIdex);
	nChIndex = LOWORD(nModIDandChIdex);

	CString strOut;
	strOut.Format("Step End ch : %d, End step : %d",nChIndex, nStepNum);
	((CMFCApplicationSampleDlg*)g_pParent)->AddLog(strOut);
}

void TestCallEmg(int nModuleID, CTS_EMG_DATA* emgData)
{
	CString strOut;
	strOut.Format("Emergency!!! (module : %d, errCode : %d)",nModuleID, emgData->wCode);
	((CMFCApplicationSampleDlg*)g_pParent)->AddLog(strOut);
}

void TestCallPause(int nModuleID, int nChIndex)
{
	CString strOut;
	strOut.Format("Pause (module : %d, channel : %d)",nModuleID, nChIndex);
	((CMFCApplicationSampleDlg*)g_pParent)->AddLog(strOut);
}
// Callback Function Define End
///////////////////////////////////////////////////////////////////////////


// CMFCApplicationSampleDlg 메시지 처리기
BOOL CMFCApplicationSampleDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 이 대화 상자의 아이콘을 설정합니다. 응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.
	m_pParent = this->GetTopLevelParent();
	g_pParent = this->GetTopLevelParent();
	
	ZeroMemory(&gst_SystemData,sizeof(CTS_MD_SYSTEM_DATA)); //충방전기 시스템 정보
	UpdateDlg(FALSE);										//control button enable/disable
	m_SendScheduleChNum.SetWindowTextA("1");				//default channel number (ex. ch4 스케쥴 전송 시 8로 입력)
	m_SendParallel1.SetWindowTextA("1");					//default Parallel Master (default는 ch1)
	m_SendParallel2.SetWindowTextA("2");					//default Parallel Master (Parallel Slave ch, ex. ch4 Slave시 8로 입력)
	m_iRecvRealTimeChDataCount = 0;
	m_bConnected = FALSE;
	
	InitializeCriticalSection(&cs);

	CallbackConnected(TestCallBackConnected);
	CallbackClosed(TestCallBackClosed);
	CallbackChData(TestCallBackGetChData);
	CallbackChData_D(TestCallBackGetChDataD);
	CallbackChData_F(TestCallBackGetChDataF);
	CallbackTestComplete(TestCallBackComplete);
	CallbackStackNotify(TestCallStackNotify);
	CallbackStepEndDataReceive(TestCallStepEnd);
	CallbackEmergency(TestCallEmg);
	CallbackPause(TestCallPause);

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CMFCApplicationSampleDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다. 문서/뷰 모델을 사용하는 MFC 응용 프로그램의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CMFCApplicationSampleDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CMFCApplicationSampleDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CMFCApplicationSampleDlg::UpdateDlg(BOOL Enable)
{
	m_btSensSchedule.EnableWindow(Enable);//연결이 되면 활성화가 된다.
	m_btSetAuxData.EnableWindow(Enable);
	m_btSetCANReceive.EnableWindow(Enable); 
	m_btSetCANTrancemit.EnableWindow(Enable);
	m_btSetParallel.EnableWindow(Enable);
	m_btSetAuxDataGet.EnableWindow(Enable);
	m_btSetAuxDataGetInfo.EnableWindow(Enable);
	m_btSetCANReceiveGet.EnableWindow(Enable);
	m_btSetCANTrancemitGet.EnableWindow(Enable);
	m_btSetParallelGet.EnableWindow(Enable);
	m_btLintoCAN.EnableWindow(Enable);

	//m_btConnect.EnableWindow(!Enable);
}


///////////////////////////////////////////////////////////////////////////
//					Connect
///////////////////////////////////////////////////////////////////////////
void CMFCApplicationSampleDlg::OnBnClickedButtonConnect()
{
	ctsSetLogPath("c:\\PNE\\Data\\log");				//로그 경로 지정

	//int nRtn = ctsServerCreate(1,this->m_hWnd); //모듈 개수, 윈도우 핸들
	int nRtn = ctsServerCreate(1,NULL); //모듈 개수, 윈도우 핸들
	TRACE("ctsServerCreate rtn : %d\n",nRtn);
	
	nRtn = ctsServerStart();					//서버 시작
	TRACE("ctsServerStart rtn : %d\n",nRtn);

	SetTimer(1001, 1000, NULL);					//연결 중 display 시작
}


///////////////////////////////////////////////////////////////////////////
//					Schedule
///////////////////////////////////////////////////////////////////////////
void CMFCApplicationSampleDlg::OnBnClickedButtonSendSchedule()
{
	int nModuleNum = 1;		
	CString strTemp, strPath;
	int errCode;
	strTemp.Format("csv file(*.%s)|*.%s|All Files(*.*)|*.*|", "sch", "sch");

	CFileDialog pDlg(TRUE, "sch", "", OFN_FILEMUSTEXIST| OFN_HIDEREADONLY, strTemp);
	pDlg.m_ofn.lpstrTitle = "PNE CTSPro file";
	if (IDOK == pDlg.DoModal())
	{
		strPath = pDlg.GetPathName();
		CString strOut;
		m_SendScheduleChNum.GetWindowText(strOut);
		////////////////////////////////////////////// 스케쥴 전송
		errCode = ctsSendSchedule(nModuleNum,atoi(strOut),0,LPSTR(LPCTSTR(strPath)), 0, 0);	

		if (errCode != CTS_ACK)
		{
			CString str;
			str.Format("ctsSendSchedule fail.. errcode : [%d]", errCode);
			AfxMessageBox(str);
		}
		else
		{
			CString str;

			str.Format("ctsSendSchedule Success");
			((CMFCApplicationSampleDlg*)m_pParent)->AddLog(str);
		}
	}
}

///////////////////////////////////////////////////////////////////////////
//					AUX
///////////////////////////////////////////////////////////////////////////
void CMFCApplicationSampleDlg::OnBnClickedButtonAuxData()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CSetAuxData dlgAuxData;
	dlgAuxData.DoModal();
}

void CMFCApplicationSampleDlg::OnBnClickedButtonAuxDataGet()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CString strOut;
	int nModuleNum = 1;			
	int nChNum = 1;

	CTS_AUX_DATA* AuxData;

	////////////////////////////////////////////// Aux data 수신
	AuxData = ctsGetAuxData(nModuleNum, nChNum);

	if(AuxData != NULL)
	{
		strOut.Format("ctsGetAuxData AuxData.lValue %d", AuxData->lValue);
	}
	else
	{
		strOut.Format("ctsGetAuxData AuxData is null");
	}

	((CMFCApplicationSampleDlg*)m_pParent)->AddLog(strOut);
}

void CMFCApplicationSampleDlg::OnBnClickedButtonAuxDataGetInfo()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CString strOut;

	 CTS_MD_AUX_INFO_DATA* AuxInfo;
	//CTS_MD_AUX_INFO_DATA_16* AuxInfo16;
	////////////////////////////////////////////// Aux info 수신
	AuxInfo = ctsGetAuxInfoData(1);

	//AuxInfo16 = ctsGetAuxInfoData16(1);

	CTS_MD_AUX_SET_DATA* pAuxSetInfo = (CTS_MD_AUX_SET_DATA*) AuxInfo->auxData;
	//CTS_MD_AUX_SET_DATA_16* pAuxSetInfo = (CTS_MD_AUX_SET_DATA_16*) AuxInfo16->auxData;

 	if(AuxInfo != NULL)
 	{
 		strOut.Format("ctsGetAuxInfoData auxData[0].szNam %s", AuxInfo->auxData[0].szName);
 	}
// 	if(AuxInfo16 != NULL)
// 	{
// 		strOut.Format("ctsGetAuxInfoData auxData[0].szNam %s", AuxInfo16->auxData[0].szName);
// 	}
	else
	{
		strOut.Format("ctsGetAuxInfoData is null");
	}

	((CMFCApplicationSampleDlg*)m_pParent)->AddLog(strOut);
	//ksj 20200427
	//할당된 aux를 Log창에 출력.
	for(int i=0;i<512;i++)
	{
		if(pAuxSetInfo[i].chNo == 0) continue;
		strOut.Format("=======================");
		((CMFCApplicationSampleDlg*)m_pParent)->AddLog(strOut);
		strOut.Format("chNo : %d",pAuxSetInfo[i].chNo);
		((CMFCApplicationSampleDlg*)m_pParent)->AddLog(strOut);
		strOut.Format("auxTempTableType :%d ",pAuxSetInfo[i].auxTempTableType);
		((CMFCApplicationSampleDlg*)m_pParent)->AddLog(strOut);
		strOut.Format("reserved0 :%d",pAuxSetInfo[i].reserved[0]);
		((CMFCApplicationSampleDlg*)m_pParent)->AddLog(strOut);
		strOut.Format("reserved1 :%d",pAuxSetInfo[i].reserved[1]);
		((CMFCApplicationSampleDlg*)m_pParent)->AddLog(strOut);
		strOut.Format("auxChNo : %d",pAuxSetInfo[i].auxChNo);
		((CMFCApplicationSampleDlg*)m_pParent)->AddLog(strOut);
		strOut.Format("auxType : %d",pAuxSetInfo[i].auxType);
		((CMFCApplicationSampleDlg*)m_pParent)->AddLog(strOut);
		strOut.Format("szName : %s",pAuxSetInfo[i].szName);
		((CMFCApplicationSampleDlg*)m_pParent)->AddLog(strOut);
		strOut.Format("lMaxData : %d",pAuxSetInfo[i].lMaxData);
		((CMFCApplicationSampleDlg*)m_pParent)->AddLog(strOut);
		strOut.Format("lMinData : %d",pAuxSetInfo[i].lMinData);
		((CMFCApplicationSampleDlg*)m_pParent)->AddLog(strOut);
		strOut.Format("lEndMaxData : %d",pAuxSetInfo[i].lEndMaxData);
		((CMFCApplicationSampleDlg*)m_pParent)->AddLog(strOut);
		strOut.Format("lEndMinData : %d",pAuxSetInfo[i].lEndMinData);
		((CMFCApplicationSampleDlg*)m_pParent)->AddLog(strOut);
		strOut.Format("funtion_division1 : %d",pAuxSetInfo[i].funtion_division1);
		((CMFCApplicationSampleDlg*)m_pParent)->AddLog(strOut);
		strOut.Format("funtion_division2 : %d",pAuxSetInfo[i].funtion_division2);
		((CMFCApplicationSampleDlg*)m_pParent)->AddLog(strOut);
		strOut.Format("funtion_division3 : %d",pAuxSetInfo[i].funtion_division3);
		((CMFCApplicationSampleDlg*)m_pParent)->AddLog(strOut);
		strOut.Format("reserved2 : %d",pAuxSetInfo[i].reserved2);
	}
}

///////////////////////////////////////////////////////////////////////////
//					CAN Rx
///////////////////////////////////////////////////////////////////////////
void CMFCApplicationSampleDlg::OnBnClickedButtonCanRev()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	int nModuleNum = 1;			
	int nChNum = 1;
	CString strTemp, strPath;
	int errCode;
	strTemp.Format("csv file(*.%s)|*.%s|All Files(*.*)|*.*|", "csv", "csv");

	CFileDialog pDlg(TRUE, "csv", "", OFN_FILEMUSTEXIST| OFN_HIDEREADONLY, strTemp);
	pDlg.m_ofn.lpstrTitle = "PNE CTSPro file";
	if (IDOK == pDlg.DoModal())
	{
		strPath = pDlg.GetPathName();
		char* pPath = LPSTR(LPCTSTR(strPath));
		////////////////////////////////////////////// CAN Rx data 전송
		errCode = ctsSetRxCANData(nModuleNum, nChNum, pPath, FALSE);

		if (errCode != CTS_ACK)
		{
			CString str;
			str.Format("ctsSetRxCANData fail [%d]", errCode);
			AfxMessageBox(str);
		}
		else
		{
			((CMFCApplicationSampleDlg*)m_pParent)->AddLog("ctsSetRxCANData Success");
		}
	}
}

void CMFCApplicationSampleDlg::OnBnClickedButtonCanRevGet()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CString strOut;
	int nCh = 0;
	int nMappingCAN = 0;

	CTS_MD_CAN_RECV_INFO_DATA* RxCanInfo;

	////////////////////////////////////////////// CAN Rx info 수신
	RxCanInfo = ctsGetCanRxInfoData(1);

	strOut.Format("ctsGetCanRxInfoData canType %s", RxCanInfo->canSetAllData.canSetData[nCh][nMappingCAN].name);

	((CMFCApplicationSampleDlg*)m_pParent)->AddLog(strOut);
}

///////////////////////////////////////////////////////////////////////////
//					CAN Tx
///////////////////////////////////////////////////////////////////////////
void CMFCApplicationSampleDlg::OnBnClickedButtonCanTran()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	int nModuleNum = 1;			
	int nChNum = 1;
	CString strTemp, strPath;
	int errCode;
	strTemp.Format("csv file(*.%s)|*.%s|All Files(*.*)|*.*|", "csv", "csv");

	CFileDialog pDlg(TRUE, "csv", "", OFN_FILEMUSTEXIST| OFN_HIDEREADONLY, strTemp);
	pDlg.m_ofn.lpstrTitle = "PNE CTSPro file";
	if (IDOK == pDlg.DoModal())
	{
		strPath = pDlg.GetPathName();
		char* pPath = LPSTR(LPCTSTR(strPath));
		////////////////////////////////////////////// CAN Tx data 전송
		errCode = ctsSetTxCANData(nModuleNum, nChNum, pPath, FALSE);

		if (errCode != CTS_ACK)
		{
			CString str;
			str.Format("ctsSetTxCANData fail [%d]", errCode);
			AfxMessageBox(str);
		}
		else
		{
			((CMFCApplicationSampleDlg*)m_pParent)->AddLog("ctsSetTxCANData Success");
		}
	}
}

void CMFCApplicationSampleDlg::OnBnClickedButtonCanTranGet()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CString strOut;
	int nCh = 0;
	int nMappingCAN = 0;

	CTS_MD_CAN_TRANS_INFO_DATA* TxCanInfo;

	////////////////////////////////////////////// CAN Rx info 수신
	TxCanInfo = ctsGetCanTxInfoData(1);

	strOut.Format("ctsGetCanTxInfoData canType %s", TxCanInfo->canSetAllData.canSetData[nCh][nMappingCAN].name);

	((CMFCApplicationSampleDlg*)m_pParent)->AddLog(strOut);
}

///////////////////////////////////////////////////////////////////////////
//					Parallel
///////////////////////////////////////////////////////////////////////////
void CMFCApplicationSampleDlg::OnBnClickedButtonParallel()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CString strMaster, strSlave;
	CString str;
	int ParallelOption = 1;						//ParallelOption 0 : 병렬 해제, 1 : 병렬 설정 
	m_SendParallel1.GetWindowText(strMaster);
	m_SendParallel2.GetWindowText(strSlave);

	int errCode = ctsSetParallelData(1, atoi(strMaster), atoi(strSlave), ParallelOption);

	if (errCode != CTS_ACK)
	{
		str.Format("ctsSetParallelData fail.. errcode : [%d]", errCode);
		AfxMessageBox(str);
	}
	else
	{
		str.Format("ctsSetParallelData Success");
		((CMFCApplicationSampleDlg*)m_pParent)->AddLog(str);
	}
}

void CMFCApplicationSampleDlg::OnBnClickedButtonParallelGet()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CString strOut;
	CTS_MD_PARALLEL_DATA parallel[8];
	int parallelCnt = 0;
	ZeroMemory(&parallel, sizeof(CTS_MD_PARALLEL_DATA));

	//////////////////////////////////////////////Parallel info 수신
	memcpy(&parallel, ctsGetParallelData(1), sizeof(CTS_MD_PARALLEL_DATA)*8);

	for (int i = 0; i < 8; i++)
	{
		CString strTmp;
		if (parallel[i].bParallel)
		{
			strTmp.Format("Parallel Master %dch, Slave %dch\n", parallel[i].chNoMaster, parallel[i].chNoSlave[0]);
			strOut+=strTmp;
			parallelCnt++;
		}
	}

	if(parallelCnt == 0)
	{
		strOut.Format("Not paralleled..");
	}

	((CMFCApplicationSampleDlg*)m_pParent)->AddLog(strOut);
}

///////////////////////////////////////////////////////////////////////////
//					LIN
///////////////////////////////////////////////////////////////////////////
void CMFCApplicationSampleDlg::OnBnClickedButtonLinToCanStart()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	int nModuleNum = 1;			
	int nChNum = 1;
	CString strTemp, strPath;
	int errCode;
	strTemp.Format("csv file(*.%s)|*.%s|All Files(*.*)|*.*|", "csv", "csv");

	CFileDialog pDlg(TRUE, "csv", "", OFN_FILEMUSTEXIST| OFN_HIDEREADONLY, strTemp);
	pDlg.m_ofn.lpstrTitle = "PNE CTSPro file";
	if (IDOK == pDlg.DoModal())
	{
		strPath = pDlg.GetPathName();
		char* pPath = LPSTR(LPCTSTR(strPath));
		////////////////////////////////////////////// LIN data 전송
		errCode = ctsSetLINData(nModuleNum, nChNum, pPath);

		if (errCode != CTS_ACK)
		{
			CString str;
			str.Format("ctsSetLINData fail [%d]", errCode);
			AfxMessageBox(str);
		}
		else
		{
			((CMFCApplicationSampleDlg*)m_pParent)->AddLog("ctsSetLINData Success");
		}
	}
}

///////////////////////////////////////////////////////////////////////////
//					Log Display
///////////////////////////////////////////////////////////////////////////
void CMFCApplicationSampleDlg::AddLog(CString strLog)
{
	EnterCriticalSection(&cs);

	int	iTotalTextLength = m_ListRecv.GetWindowTextLength();
	if (iTotalTextLength > 0x3FFF) {
		m_ListRecv.SetWindowText("");
		iTotalTextLength = 0;
	}

	m_ListRecv.AddString(strLog);
	int nSel = m_ListRecv.GetCount();
	m_ListRecv.SetCurSel(nSel-1);

	LeaveCriticalSection(&cs);
}

void CMFCApplicationSampleDlg::OnTimer(UINT_PTR nIDEvent)
{
	if(nIDEvent == 1001)
	{
		// 연결 중..
		AddLog("Connecting..");
	}

	CDialogEx::OnTimer(nIDEvent);
}

void CMFCApplicationSampleDlg::OnBnClickedOk()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	OnClose();
	CDialogEx::OnOK();
}

void CMFCApplicationSampleDlg::OnBnClickedCancel()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

//	OnClose(); 
	CDialogEx::OnCancel();
}

// program end
void CMFCApplicationSampleDlg::OnClose()
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	int nResult = ctsServerClose();

	DeleteCriticalSection(&cs);

	CDialogEx::OnClose();
}


#if 0

//테스트 종료 이벤트 수신
LRESULT CMFCApplicationSampleDlg::OnTestComplete(WPARAM wParam, LPARAM lParam)
{
	int nModuleID = (int)wParam;
	int nChannelNum = (int)lParam;

	CString strOut;

	strOut.Format("Test Complete (ModuleID : %d, Channel : %d)",nModuleID, nChannelNum);
	AddLog(strOut);

	return 0;
}

//Emergency 이벤트 수신
LRESULT CMFCApplicationSampleDlg::OnEmg(WPARAM wParam, LPARAM lParam)
{
	int nModuleID = (int)wParam;
	CTS_EMG_DATA EmgData;
	ZeroMemory(&EmgData, sizeof(CTS_EMG_DATA));

	memcpy(&EmgData, &lParam, sizeof(CTS_EMG_DATA));

	CString strOut;

	strOut.Format("Emergency!! ModuleID : %d, EmgCode : %d)",nModuleID, EmgData.wCode);
	AddLog(strOut);

	return 0;
}

// real time channel data receive
LRESULT CMFCApplicationSampleDlg::OnGetChData(WPARAM wParam, LPARAM lParam)
{
	int nModuleID, nChIndex = 0;
	nChIndex = HIWORD(wParam);
	nModuleID = LOWORD(wParam);

	if (m_bConnected == TRUE)
	{
		if (gst_SystemData.nInstalledChCount != 0) {
			SYSTEMTIME systemTime;   // system time
			::GetLocalTime(&systemTime);

			// 약 100ms 시간으로 ch data 수신
			// 1ch당 100번의 data 수신시 Log 창에 display
			if (((m_iRecvRealTimeChDataCount) % (100 *gst_SystemData.nInstalledChCount)) == 0 ) {
				m_iRecvRealTimeChDataCount = 0;
				CString strOut;
				strOut.Format("[%02d:%02d:%02d:%03d] Receive Real Time Ch data the num of 100.", systemTime.wHour, systemTime.wMinute, systemTime.wSecond, systemTime.wMilliseconds, nModuleID, nChIndex);

				AddLog(strOut);
			}
			m_iRecvRealTimeChDataCount++;
		}
	}

	return 0;
}

//충방전기로부터 데이터 스택 통지 수신
LRESULT CMFCApplicationSampleDlg::OnDataStackedNotify(WPARAM wParam, LPARAM lParam)
{
	int nModuleID = (int)wParam;
	int nChIndex = (int)lParam;

	CString strOut;


	int i = 0;
	CTS_VARIABLE_CH_DATA stPopData[512];
	ZeroMemory(&stPopData,sizeof(CTS_VARIABLE_CH_DATA)*512);

	// stack data popup
	while(ctsPopSaveData(nModuleID, nChIndex, &stPopData[i]))
	{
		i++;
	}

	strOut.Format("Stack Notify (ModuleID : %d, Channel : %d, popsavedata : %d)",nModuleID, nChIndex, i);
	AddLog(strOut);

	return 0;
}

//충방전기 접속 통지
LRESULT CMFCApplicationSampleDlg::OnModuleConnected(WPARAM wParam, LPARAM lParam)
{
	KillTimer(1001);

	m_ListRecv.ResetContent();

	int nModuleID = (int)wParam; //모듈 ID
	CString strAddLog;

	memcpy(&gst_SystemData,(void*)lParam,sizeof(CTS_MD_SYSTEM_DATA)); //충방전기 시스템 정보

	strAddLog.Format("ModuleID : %d",nModuleID);
	AddLog(strAddLog);

	strAddLog.Format("Protocol Ver. : 0x%04x\r\n",gst_SystemData.nProtocolVersion);
	AddLog(strAddLog);

	strAddLog.Format("Installed ch Num : %d\r\n\r\n",gst_SystemData.nInstalledChCount);
	AddLog(strAddLog);

	UpdateDlg(TRUE);

	m_bConnected = TRUE;

	return 0;
}

//충방전기 통신 두절 통지
LRESULT CMFCApplicationSampleDlg::OnModuleClosed(WPARAM wParam, LPARAM lParam)
{
	int nModuleID = (int)wParam;
	CString strTemp;

	m_bConnected = FALSE;

	AddLog("========== closed ==========");

	strTemp.Format("ModuleID : %d is Closed",nModuleID);
	AddLog(strTemp);

	AddLog("========== closed ==========");

	UpdateDlg(FALSE);

	return 0;
}

//실시간 모니터링 데이터이며, 저장 데이터는 별도로 처리해야됨.
int CMFCApplicationSampleDlg::UpdateMonitoringData(int nModuleID)
{
	CString strOut[4];
	int nState[4];
	long nVoltage[4];
	long nCurrent[4];
	long nCode[4];
	long stepType[4];
	if (gst_SystemData.nModuleID != 0)
	{
		for(int i = 0; i < gst_SystemData.nInstalledChCount; i++)
		{
			nState[i] = ctsGetChannelValue(1,i,PS_STATE);
			nVoltage[i] = ctsGetChannelValue(1,i,PS_VOLTAGE);
			nCurrent[i] = ctsGetChannelValue(1,i,PS_CURRENT);
			nCode[i] = ctsGetChannelValue(1,i,PS_CODE);

			CString str;
			switch (nState[i])
			{
			case PS_STATE_LINE_OFF:
				str = "disconnected";
				break;
			case PS_STATE_LINE_ON:
				str = "connected";
				break;
			case PS_STATE_READY:
				str = "ready";
				break;
			case PS_STATE_IDLE:
				str = "idle";
				break;
			case PS_STATE_STANDBY:
				str = "standby";
				break;
			case PS_STATE_RUN:
				//str = "run";S
				stepType[i] = ctsGetChannelValue(1,i,PS_STEP_TYPE);
				if (stepType[i] == PS_STEP_NONE)
				{
					str = "None";
				}
				else if (stepType[i] == PS_STEP_CHARGE)
				{
					str = "Charge";
				}
				else if (stepType[i] == PS_STEP_DISCHARGE)
				{
					str = "Discharge";
				}
				else if (stepType[i] == PS_STEP_REST)
				{
					str = "Rest";
				}
				else if (stepType[i] == PS_STEP_OCV)
				{
					str = "OCV";
				}
				else if (stepType[i] == PS_STEP_IMPEDANCE)
				{
					str = "Impedance";
				}
				else if (stepType[i] == PS_STEP_END)
				{
					str = "End";
				}
				else if (stepType[i] == PS_STEP_LOOP)
				{
					str = "Loop";
				}
				else if (stepType[i] == PS_STEP_PATTERN)
				{
					str = "Pattern";
				}
				break;
			case PS_STATE_PAUSE:
				str = "pause";
				break;
			case PS_STATE_MAINTENANCE:
				str = "maintenance";
				break;
			case PS_STATE_END:
				str = "Complete";
				break;
			default:
				str = "disconnected";
				break;
			}

			strOut[i].Format("State : %s, Voltage : %.3lfV, Current : %.3lfA, Code : %d", str, nVoltage[i]/1000000.0f, nCurrent[i]/1000000.0f, (int)nCode[i]);
		}

		m_StatusCh1.SetWindowTextA(strOut[0]);
		m_StatusCh2.SetWindowTextA(strOut[1]);
		m_StatusCh3.SetWindowTextA(strOut[2]);
		m_StatusCh4.SetWindowTextA(strOut[3]);
	}

	return 0;
}
#endif


///////////////////////////////////////////////////////////////////////////
//					Test Button
///////////////////////////////////////////////////////////////////////////
void CMFCApplicationSampleDlg::OnBnClickedButtonTest()	//DLL 직접 로드.
{
	ctsSendContinue(1,1,0,0);

#if 0
	//ctsSetLogPath("c:\\TEST1\\TEST1\\11");				//로그 경로 지정

	//ctsSendNextStep(1,  2, 0);

	//ctsSendPause(1,2,0,1,5);

	//ctsSendPauseCancel(1,2,0);

	//ctsSendStop(1,2,0,0,0);

	/*typedef BOOL (*TestMsgBox)(char* szMsg);    
	
	TestMsgBox lpTestMsgBox;   //Dll 인스턴스 핸들 설정
	HINSTANCE hDll;              //Dll를 로드한다.

#ifdef _DEBUG
	hDll =AfxLoadLibrary("PSServerAPId.dll");
#else
	hDll =AfxLoadLibrary("PSServerAPI.dll");
#endif	

	if(hDll==NULL)
	{
		AfxMessageBox("Dll이 없습니다.");
		return;
	}

	lpTestMsgBox=(TestMsgBox)GetProcAddress(hDll,"TestMsgBox");  //함수를 얻는다.

	if(lpTestMsgBox==NULL)
	{
		AfxMessageBox("함수가 없습니다. ");
		return;
	}

	lpTestMsgBox("abcd");
    
	AfxFreeLibrary(hDll); //DLL 해제*/
#endif
}

void CMFCApplicationSampleDlg::OnBnClickedButtonTest3()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	ctsSendPause(1,1,0,0,0);
}

void CMFCApplicationSampleDlg::OnBnClickedButtonTest4()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	ctsSendPauseCancel(1,1,0);
}

void CMFCApplicationSampleDlg::OnBnClickedButtonTest5()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	//ctsSendStop(1,1,0,0,0);

	CString strOut;
	m_SendScheduleChNum.GetWindowText(strOut);
	ctsSendStop(1,atoi(strOut),0,0,0);
}

void CMFCApplicationSampleDlg::OnBnClickedButtonTest6()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	ctsSendStopCancel(1,1,0);
}

void CMFCApplicationSampleDlg::OnBnClickedButtonTest7()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	ctsSendNextStep (1,1,0);
}

void CMFCApplicationSampleDlg::OnBnClickedButtonTest8()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	ctsSetLogPath("c:\\Data\\log");				//로그 경로 지정

	//int nRtn = ctsServerCreate(1,this->m_hWnd); //모듈 개수, 윈도우 핸들
	int nRtn = ctsServerCreate(1,NULL); //모듈 개수, 윈도우 핸들
	TRACE("ctsServerCreate rtn : %d\n",nRtn);
	
	nRtn = ctsServerStart();					//서버 시작
	TRACE("ctsServerStart rtn : %d\n",nRtn);

	SetTimer(1001, 1000, NULL);					//연결 중 display 시작
}

void CMFCApplicationSampleDlg::OnBnClickedButtonTest9()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	ctsServerClose();
}

void CMFCApplicationSampleDlg::OnBnClickedButtonTest10()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CTS_VARIABLE_CH_DATA *ch = ctsGetRealChData(1,1);

	CString str;
	str.Format("ctsGetRealChData chReservedCmd : %d",ch->chData.chReservedCmd);
	((CMFCApplicationSampleDlg*)g_pParent)->AddLog(str);
}


void CMFCApplicationSampleDlg::OnBnClickedButtonTest11()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CString strMaster, strSlave;
	CString str;
	int ParallelOption = 0;						//ParallelOption 0 : 병렬 해제, 1 : 병렬 설정 
	m_SendParallel1.GetWindowText(strMaster);
	m_SendParallel2.GetWindowText(strSlave);

	int errCode = ctsSetParallelData(1, atoi(strMaster), atoi(strSlave), ParallelOption);

	if (errCode != CTS_ACK)
	{
		str.Format("ctsSetParallelData fail.. errcode : [%d]", errCode);
		AfxMessageBox(str);
	}
	else
	{
		str.Format("ctsSetParallelData Success");
		((CMFCApplicationSampleDlg*)m_pParent)->AddLog(str);
	}
}

typedef int (*ctsServerCreateFunc)(int,HWND);
typedef int (*ctsServerStartFunc)(void);
typedef int (*ctsServerCloseFunc)(void);
typedef void (*ctsSetLogPathFunc)(char*);

//기본적으로 본 샘플은 DLL 정적 로딩을 사용하고 있으나
//여기서는 DLL 동적 로딩 예제를 추가.
void CMFCApplicationSampleDlg::OnBnClickedButtonLoadDll()
{	
	if(m_hDll)
	{
		AfxMessageBox("이미 dll이 로드 되어있습니다.");
		return;
	}

	m_hDll = LoadLibrary("PSServerAPI.dll");

	if(!m_hDll)
	{
		AfxMessageBox("dll 로드 실패");
		return;
	}


	ctsServerCreateFunc lpCtsServerCreate;
	lpCtsServerCreate = (ctsServerCreateFunc)GetProcAddress(m_hDll,"ctsServerCreate");  //함수를 얻는다.

	if(!lpCtsServerCreate)
	{
		AfxMessageBox(_T("ctsServerCreate 함수에 대한 주소값을 얻어오는데 실패했습니다."));
		return;
	}

	ctsServerStartFunc lpCtsServerStart;
	lpCtsServerStart = (ctsServerStartFunc)GetProcAddress(m_hDll,"ctsServerStart");  //함수를 얻는다.

	if(!lpCtsServerStart)
	{
		AfxMessageBox(_T("ctsServerStart 함수에 대한 주소값을 얻어오는데 실패했습니다."));
		return;
	}

	ctsSetLogPathFunc lpCtsSetLogPath;
	lpCtsSetLogPath = (ctsSetLogPathFunc)GetProcAddress(m_hDll,"ctsSetLogPath");  //함수를 얻는다.

	if(!lpCtsSetLogPath)
	{
		AfxMessageBox(_T("ctsSetLogPath 함수에 대한 주소값을 얻어오는데 실패했습니다."));
		return;
	}
	
	CString strLog;
	int nRtn = 0;
	
	lpCtsSetLogPath("c:\\PNE");

	nRtn = lpCtsServerCreate(1, 0);
	strLog.Format("lpCtsServerCreate rtn : %d",nRtn);
	AddLog(strLog);

	nRtn = lpCtsServerStart();
	strLog.Format("lpCtsServerStart rtn : %d",nRtn);
	AddLog(strLog);

	strLog.Format("DLL 로드 Count : %d",++m_nLoadCount);
	AddLog(strLog);

	SetTimer(1001, 1000, NULL);					//연결 중 display 시작
}

//기본적으로 본 샘플은 DLL 정적 로딩을 사용하고 있으나
//여기서는 DLL 동적 로딩 예제를 추가.
void CMFCApplicationSampleDlg::OnBnClickedButtonUnloadDll()
{
	CString strLog;

	if(m_hDll)
	{
		ctsServerCloseFunc lpCtsServerClose;
		lpCtsServerClose = (ctsServerCloseFunc)GetProcAddress(m_hDll,"ctsServerClose");  //함수를 얻는다.

		if(!lpCtsServerClose)
		{
			AfxMessageBox(_T("ctsServerClose 함수에 대한 주소값을 얻어오는데 실패했습니다."));
			return;
		}

		int nRtn = lpCtsServerClose();
		
	
		strLog.Format("CtsServerClose rtn : %d",nRtn);
		AddLog(strLog);

		KillTimer(1001);
		
		if(FreeLibrary(m_hDll) == 0)
		{			
			DWORD dwLastError = GetLastError();
			strLog.Format("Dll Unload fail. Error Code : 0x%x", dwLastError);
			AfxMessageBox(strLog);

			return;
		}
		m_hDll = NULL;

		strLog.Format("DLL 언로드 Count : %d",++m_nUnloadCount);
		AddLog(strLog);
	}
}


void CMFCApplicationSampleDlg::OnBnClickedButtonDebug()
{
 	CString strTemp;
// 	strTemp.Format("stacked : %d\n",ctsGetStackedDataSize(1,3));
// 	
// 	AddLog(strTemp);

	/*CString strOut;
	CTS_VARIABLE_CH_DATA stGetPopData;
	// stack data popup
	int j = 0;
	int nStackSize = ctsGetStackedDataSize(1, 1);
	for (j = 0; j < nStackSize; j++)
	{
		ZeroMemory(&stGetPopData,sizeof(CTS_VARIABLE_CH_DATA));
		ctsPopSaveData(1, 1, &stGetPopData);
		strTemp.Format("%d",stGetPopData.chData.chCode);
		AddLog(strTemp);
	}*/

	
}


void CMFCApplicationSampleDlg::OnBnClickedButtonAuxRelease()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if(ctsReleaseAllAux(1) != CTS_ACK)
	{
		AfxMessageBox("전송 실패");
	}
}


void CMFCApplicationSampleDlg::OnBnClickedButtonTest12()
{

	AfxBeginThread((AFX_THREADPROC)ThreadTest, (LPVOID)this);

}

UINT CMFCApplicationSampleDlg::ThreadTest(LPVOID pParam)
{
	CString strTemp;
	CMFCApplicationSampleDlg* pDlg = (CMFCApplicationSampleDlg*) pParam;

	for(int i=0;i<100;i++)
	{
		for(int i=1;i<=4;i++)
		{
// 			CTS_VARIABLE_CH_DATA* pData = ctsGetRealChData_V2(1,i);
// 			if(!pData) continue;
// 			strTemp.Format("ctsGetRealChData_V2 [Ch:%d] %d",i, pData->chData.chNo);
// 			pDlg->AddLog(strTemp);

			CTS_VARIABLE_CH_DATA* pData = ctsGetRealChData(1,i);
			if(!pData) continue;
			strTemp.Format("ctsGetRealChData %d %d",i, pData->chData.chNo);
			pDlg->AddLog(strTemp);
		}
		Sleep(10);
	}

	return 0;
}


void CMFCApplicationSampleDlg::OnBnClickedButtonIso()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	//ctsSendIso(1,1,0,0); //절연
	//ctsSendIso(1,1,1); //절연
	ctsSendIsoNormal(1,0,1);

}


void CMFCApplicationSampleDlg::OnBnClickedButtonNonIso()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	//ctsSendIso(1,1,0,1); //비절연
	//ctsSendIso(1,1,0); //비절연
	ctsSendIsoNormal(1,0,0);
}


void CMFCApplicationSampleDlg::OnBnClickedButtonGetStepCount()
{

	CString strTemp, strPath;

	strTemp.Format("csv file(*.%s)|*.%s|All Files(*.*)|*.*|", "sch", "sch");

	CFileDialog pDlg(TRUE, "sch", "", OFN_FILEMUSTEXIST| OFN_HIDEREADONLY, strTemp);
	pDlg.m_ofn.lpstrTitle = "PNE CTSPro file";
	if (IDOK == pDlg.DoModal())
	{
		strPath = pDlg.GetPathName();

		int nCount = ctsGetSchStepCount(LPSTR(LPCTSTR(strPath)));

		CString strTemp;
		strTemp.Format("%d",nCount);
		AfxMessageBox(strTemp);
	}
	
}


void CMFCApplicationSampleDlg::OnBnClickedButtonGetSchStepinfo()
{
	//CTS_DLL_API int ctsGetSchStepInfo(CTS_SCH_STEP_INFO* pStepInfo, char* szSchPath, int nStepIndex);

	CString strTemp, strPath;

	strTemp.Format("csv file(*.%s)|*.%s|All Files(*.*)|*.*|", "sch", "sch");


	CFileDialog pDlg(TRUE, "sch", "", OFN_FILEMUSTEXIST| OFN_HIDEREADONLY, strTemp);
	pDlg.m_ofn.lpstrTitle = "PNE CTSPro file";
	if (IDOK == pDlg.DoModal())
	{
		strPath = pDlg.GetPathName();
		CTS_SCH_STEP_INFO stepinfo;
		int nCount = ctsGetSchStepCount(LPSTR(LPCTSTR(strPath)));

		for(int i=0;i<nCount;i++)
		{
			ZeroMemory(&stepinfo,sizeof(CTS_SCH_STEP_INFO));
			if(ctsGetSchStepInfo(&stepinfo, LPSTR(LPCTSTR(strPath)), i))
			{
				strTemp.Format("step no : %d , type : %d, mode :%d , endt: %d"
					,stepinfo.stepNo
					,stepinfo.nStepType
					,stepinfo.mode
					,stepinfo.ulEndTime
					);

				AddLog(strTemp);
			}
		}
	}
}


void CMFCApplicationSampleDlg::OnBnClickedButtonGetCbInfo()
{
	CString strTemp, strPath;

	strTemp.Format("csv file(*.%s)|*.%s|All Files(*.*)|*.*|", "sch", "sch");
	;

	CFileDialog pDlg(TRUE, "sch", "", OFN_FILEMUSTEXIST| OFN_HIDEREADONLY, strTemp);
	pDlg.m_ofn.lpstrTitle = "PNE CTSPro file";
	if (IDOK == pDlg.DoModal())
	{
		strPath = pDlg.GetPathName();
		CTS_SCH_STEP_INFO stepinfo;
		int nCount = 0;
		CTS_SCH_EXT_CB_INFO* pExtCbInfo = ctsGetSchAllStepCBInfo(LPSTR(LPCTSTR(strPath)) , &nCount);

		if(pExtCbInfo)
		{
			for(int i=0;i<nCount;i++)
			{
					strTemp.Format("step no : %d , %d,%d,%d,%d,%d,%d,%d,%d,%d"
					,pExtCbInfo[i].stepNo
					,pExtCbInfo[i].nCbCircuitRes
					,pExtCbInfo[i].nCbWorkVoltLower
					,pExtCbInfo[i].nCbWorkVoltUpper						
					,pExtCbInfo[i].nCbStartDeltaVolt
					,pExtCbInfo[i].nCbEndDeltaVolt					
					,pExtCbInfo[i].nCbActiveTime 			
					,pExtCbInfo[i].nCbAutoStopTime		
					,pExtCbInfo[i].nCbAutoNextStep
					,pExtCbInfo[i].ulStepEndTime
					);

				AddLog(strTemp);

			}
		}	

		int nRes = ctsReleaseSchAllStepCBInfo(pExtCbInfo);
		strTemp.Format("release res : %d", nRes);
		AddLog(strTemp);
	}
}


UINT CMFCApplicationSampleDlg::ThreadTEST(LPVOID lparam)
{
	CMFCApplicationSampleDlg* pMain = (CMFCApplicationSampleDlg*) lparam;
	pMain->OnBnClickedButtonConnect();
	return 0;
}

UINT CMFCApplicationSampleDlg::ThreadTEST2(LPVOID lparam)
{
	CMFCApplicationSampleDlg* pMain = (CMFCApplicationSampleDlg*) lparam;
	pMain->OnBnClickedButtonTest9();
	return 0;
}

//쓰레드 호출 권장하지 않음
//쓰레드에서 create 후
//또 다른 쓰레드에서 close시 오류 발생한다고 하여 테스트.
void CMFCApplicationSampleDlg::OnBnClickedButtonConnectThread()
{
	AfxBeginThread(ThreadTEST,this);
}


void CMFCApplicationSampleDlg::OnBnClickedButtonCloseThread()
{
	AfxBeginThread(ThreadTEST2,this);
}


void CMFCApplicationSampleDlg::OnBnClickedButtonSendSchedule2()
{
	//OnBnClickedButtonSendSchedule();

	int nModuleNum = 1;		
	CString strTemp, strPath;
	int errCode;
	strTemp.Format("csv file(*.%s)|*.%s|All Files(*.*)|*.*|", "sch", "sch");

	CFileDialog pDlg(TRUE, "sch", "", OFN_FILEMUSTEXIST| OFN_HIDEREADONLY, strTemp);
	pDlg.m_ofn.lpstrTitle = "PNE CTSPro file";
	if (IDOK == pDlg.DoModal())
	{
		strPath = pDlg.GetPathName();
		CString strOut;
		m_SendScheduleChNum.GetWindowText(strOut);
		////////////////////////////////////////////// 스케쥴 전송
		errCode = ctsSendSchedule_V2(nModuleNum,atoi(strOut),0,LPSTR(LPCTSTR(strPath)), 0, 0, 2, 7);	

		if (errCode != CTS_ACK)
		{
			CString str;
			str.Format("ctsSendSchedule fail.. errcode : [%d]", errCode);
			AfxMessageBox(str);
		}
		else
		{
			CString str;

			str.Format("ctsSendSchedule Success");
			((CMFCApplicationSampleDlg*)m_pParent)->AddLog(str);
		}
	}
}


void CMFCApplicationSampleDlg::OnBnClickedButtonPopTest()
{
	CString strOut;
	CTS_VARIABLE_CH_DATA stGetPopData;
	CTS_VARIABLE_CH_DATA stPopData[32];

	ZeroMemory(&stPopData[0],sizeof(CTS_VARIABLE_CH_DATA)*32);

	// stack data popup
	int j = 0;
	int nStackSize = ctsGetStackedDataSize(1, 0);
	/*
	//for (j = 0; j < nStackSize; j++)
	for (j = 0; j < nStackSize && j < 32; j++)
	{
		ZeroMemory(&stGetPopData,sizeof(CTS_VARIABLE_CH_DATA));
		ctsPopSaveData(1, 0, &stGetPopData);
		memcpy(&stPopData[j], &stGetPopData, sizeof(CTS_VARIABLE_CH_DATA));
	}*/

	ctsPopSaveData(1, 0, &stGetPopData);

	strOut.Format("Stack Notify (ModuleID : %d, Channel : %d, stack size : %d)",1, 0, nStackSize);
	((CMFCApplicationSampleDlg*)g_pParent)->AddLog(strOut);
}


void CMFCApplicationSampleDlg::OnBnClickedButtonSendSchedule3()
{
	ctsSetLogPath("C:\\PNE");
	int nModuleNum = 1;		
	CString strTemp;
	int errCode;

	CTS_SIMPLE_TEST_INFO SimpleSch[6];
	int nStepCount = 6;
	ZeroMemory(SimpleSch,sizeof(CTS_SIMPLE_TEST_INFO)*nStepCount);

#if true
	//OCV
	SimpleSch[0].nStepType = PS_STEP_OCV; //OCV

	//휴지 스텝
	SimpleSch[1].nStepType = PS_STEP_REST; //REST
	SimpleSch[1].nRecordTime = 10;
	SimpleSch[1].nCutoffCondTime = 3;

	SimpleSch[2].nStepType = PS_STEP_REST; //REST
	SimpleSch[2].nRecordTime = 1;
	SimpleSch[2].nCutoffCondTime = 3;

	SimpleSch[3].nStepType = PS_STEP_REST; //REST
	SimpleSch[3].nRecordTime = 101;
	SimpleSch[3].nCutoffCondTime = 3;

	SimpleSch[4].nStepType = PS_STEP_REST; //REST
	SimpleSch[4].nRecordTime = 1;
	SimpleSch[4].nCutoffCondTime = 3;

	SimpleSch[5].nStepType = PS_STEP_REST; //REST
	SimpleSch[5].nRecordTime = 205;
	SimpleSch[5].nCutoffCondTime = 3;
	
#else 
	////////////////////////////////////////////////////////////////////
	//충전 스텝
	SimpleSch[2].nStepType = 1;
	SimpleSch[2].nMode = PS_MODE_CCCV;
	SimpleSch[2].nRefVoltage = 4000;
	SimpleSch[2].nRefCurrent = 1500;
	SimpleSch[2].nRecordTime = 1;
	SimpleSch[2].nCutoffCondTime = 10;
	SimpleSch[2].nCutoffCondCurrent = 1000;
	SimpleSch[2].nSafetyCurrentHigh = 1;
	SimpleSch[2].nSafetyCurrentLow = 2;
	SimpleSch[2].nSafetyVoltageHigh = 1;
	SimpleSch[2].nSafetyVoltageLow = 2;
	SimpleSch[2].nSafetyAhHigh = 1;
	SimpleSch[2].nSafetyAhLow = 2;

	//휴지 스텝
	SimpleSch[3].nStepType = PS_STEP_REST; //REST
	SimpleSch[3].nRecordTime = 1;
	SimpleSch[3].nCutoffCondTime = 10;

	//방전 스텝
	SimpleSch[4].nStepType = PS_STEP_DISCHARGE;
	SimpleSch[4].nMode = PS_MODE_CC;
	SimpleSch[4].nRefVoltage = 2800;
	SimpleSch[4].nRefCurrent = 1500;
	SimpleSch[4].nRecordTime = 1;
	SimpleSch[4].nCutoffCondTime = 10;
	SimpleSch[4].nCutoffCondVolt = 3000;

	//휴지 스텝
	SimpleSch[5].nStepType = PS_STEP_REST; //REST
	SimpleSch[5].nRecordTime = 1;
	SimpleSch[5].nCutoffCondTime = 10;
	////////////////////////////////////////////////////////////////////
#endif

	CString strOut;
	m_SendScheduleChNum.GetWindowText(strOut);
	////////////////////////////////////////////// 스케쥴 전송
	errCode = ctsSendSimpleTest(nModuleNum, atoi(strOut),0, nStepCount,SimpleSch);

	if (errCode != CTS_ACK)
	{
		CString str;
		str.Format("ctsSendSimpleTest fail.. errcode : [%d]", errCode);
		AfxMessageBox(str);
	}
	else
	{
		CString str;

		str.Format("ctsSendSimpleTest Success");
		((CMFCApplicationSampleDlg*)m_pParent)->AddLog(str);
	}

}
