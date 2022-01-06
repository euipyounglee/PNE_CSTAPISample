
// MFC Application SampleDlg.cpp : ���� ����
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

// ���� ���α׷� ������ ���Ǵ� CAboutDlg ��ȭ �����Դϴ�.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

// �����Դϴ�.
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


// CMFCApplicationSampleDlg ��ȭ ����
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

	int nModuleID = (int)test; //��� ID
	CString strAddLog;

	memcpy(&gst_SystemData, (void*)sysInfo,sizeof(CTS_MD_SYSTEM_DATA)); //������� �ý��� ����

	strAddLog.Format("ModuleID : %d",nModuleID);
	((CMFCApplicationSampleDlg*)g_pParent)->AddLog(strAddLog);

	strAddLog.Format("Protocol Ver. : 0x%04x\r\n",sysInfo->nProtocolVersion);
	((CMFCApplicationSampleDlg*)g_pParent)->AddLog(strAddLog);

	strAddLog.Format("Installed ch Num : %d\r\n\r\n",sysInfo->nInstalledChCount);
	((CMFCApplicationSampleDlg*)g_pParent)->AddLog(strAddLog);

	((CMFCApplicationSampleDlg*)g_pParent)->UpdateDlg(TRUE);//��ư�� ���� Ȱ��ȭ
	
	((CMFCApplicationSampleDlg*)g_pParent)->m_bConnected = TRUE;
}

void TestCallBackGetChData(unsigned int nModIDandChIdex , CTS_VARIABLE_CH_DATA* ChData)
{
#ifdef _DEBUG
	//ksj 20210407 : �ݹ��Լ� ȣ�� �ֱ� ������.
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


// CMFCApplicationSampleDlg �޽��� ó����
BOOL CMFCApplicationSampleDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// �ý��� �޴��� "����..." �޴� �׸��� �߰��մϴ�.

	// IDM_ABOUTBOX�� �ý��� ��� ������ �־�� �մϴ�.
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

	// �� ��ȭ ������ �������� �����մϴ�. ���� ���α׷��� �� â�� ��ȭ ���ڰ� �ƴ� ��쿡��
	//  �����ӿ�ũ�� �� �۾��� �ڵ����� �����մϴ�.
	SetIcon(m_hIcon, TRUE);			// ū �������� �����մϴ�.
	SetIcon(m_hIcon, FALSE);		// ���� �������� �����մϴ�.

	// TODO: ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
	m_pParent = this->GetTopLevelParent();
	g_pParent = this->GetTopLevelParent();
	
	ZeroMemory(&gst_SystemData,sizeof(CTS_MD_SYSTEM_DATA)); //������� �ý��� ����
	UpdateDlg(FALSE);										//control button enable/disable
	m_SendScheduleChNum.SetWindowTextA("1");				//default channel number (ex. ch4 ������ ���� �� 8�� �Է�)
	m_SendParallel1.SetWindowTextA("1");					//default Parallel Master (default�� ch1)
	m_SendParallel2.SetWindowTextA("2");					//default Parallel Master (Parallel Slave ch, ex. ch4 Slave�� 8�� �Է�)
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

	return TRUE;  // ��Ŀ���� ��Ʈ�ѿ� �������� ������ TRUE�� ��ȯ�մϴ�.
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

// ��ȭ ���ڿ� �ּ�ȭ ���߸� �߰��� ��� �������� �׸�����
//  �Ʒ� �ڵ尡 �ʿ��մϴ�. ����/�� ���� ����ϴ� MFC ���� ���α׷��� ��쿡��
//  �����ӿ�ũ���� �� �۾��� �ڵ����� �����մϴ�.

void CMFCApplicationSampleDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // �׸��⸦ ���� ����̽� ���ؽ�Ʈ�Դϴ�.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Ŭ���̾�Ʈ �簢������ �������� ����� ����ϴ�.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// �������� �׸��ϴ�.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// ����ڰ� �ּ�ȭ�� â�� ���� ���ȿ� Ŀ���� ǥ�õǵ��� �ý��ۿ���
//  �� �Լ��� ȣ���մϴ�.
HCURSOR CMFCApplicationSampleDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CMFCApplicationSampleDlg::UpdateDlg(BOOL Enable)
{
	m_btSensSchedule.EnableWindow(Enable);//������ �Ǹ� Ȱ��ȭ�� �ȴ�.
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
	ctsSetLogPath("c:\\PNE\\Data\\log");				//�α� ��� ����

	//int nRtn = ctsServerCreate(1,this->m_hWnd); //��� ����, ������ �ڵ�
	int nRtn = ctsServerCreate(1,NULL); //��� ����, ������ �ڵ�
	TRACE("ctsServerCreate rtn : %d\n",nRtn);
	
	nRtn = ctsServerStart();					//���� ����
	TRACE("ctsServerStart rtn : %d\n",nRtn);

	SetTimer(1001, 1000, NULL);					//���� �� display ����
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
		////////////////////////////////////////////// ������ ����
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
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	CSetAuxData dlgAuxData;
	dlgAuxData.DoModal();
}

void CMFCApplicationSampleDlg::OnBnClickedButtonAuxDataGet()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	CString strOut;
	int nModuleNum = 1;			
	int nChNum = 1;

	CTS_AUX_DATA* AuxData;

	////////////////////////////////////////////// Aux data ����
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
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	CString strOut;

	 CTS_MD_AUX_INFO_DATA* AuxInfo;
	//CTS_MD_AUX_INFO_DATA_16* AuxInfo16;
	////////////////////////////////////////////// Aux info ����
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
	//�Ҵ�� aux�� Logâ�� ���.
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
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
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
		////////////////////////////////////////////// CAN Rx data ����
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
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	CString strOut;
	int nCh = 0;
	int nMappingCAN = 0;

	CTS_MD_CAN_RECV_INFO_DATA* RxCanInfo;

	////////////////////////////////////////////// CAN Rx info ����
	RxCanInfo = ctsGetCanRxInfoData(1);

	strOut.Format("ctsGetCanRxInfoData canType %s", RxCanInfo->canSetAllData.canSetData[nCh][nMappingCAN].name);

	((CMFCApplicationSampleDlg*)m_pParent)->AddLog(strOut);
}

///////////////////////////////////////////////////////////////////////////
//					CAN Tx
///////////////////////////////////////////////////////////////////////////
void CMFCApplicationSampleDlg::OnBnClickedButtonCanTran()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
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
		////////////////////////////////////////////// CAN Tx data ����
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
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	CString strOut;
	int nCh = 0;
	int nMappingCAN = 0;

	CTS_MD_CAN_TRANS_INFO_DATA* TxCanInfo;

	////////////////////////////////////////////// CAN Rx info ����
	TxCanInfo = ctsGetCanTxInfoData(1);

	strOut.Format("ctsGetCanTxInfoData canType %s", TxCanInfo->canSetAllData.canSetData[nCh][nMappingCAN].name);

	((CMFCApplicationSampleDlg*)m_pParent)->AddLog(strOut);
}

///////////////////////////////////////////////////////////////////////////
//					Parallel
///////////////////////////////////////////////////////////////////////////
void CMFCApplicationSampleDlg::OnBnClickedButtonParallel()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	CString strMaster, strSlave;
	CString str;
	int ParallelOption = 1;						//ParallelOption 0 : ���� ����, 1 : ���� ���� 
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
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	CString strOut;
	CTS_MD_PARALLEL_DATA parallel[8];
	int parallelCnt = 0;
	ZeroMemory(&parallel, sizeof(CTS_MD_PARALLEL_DATA));

	//////////////////////////////////////////////Parallel info ����
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
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
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
		////////////////////////////////////////////// LIN data ����
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
		// ���� ��..
		AddLog("Connecting..");
	}

	CDialogEx::OnTimer(nIDEvent);
}

void CMFCApplicationSampleDlg::OnBnClickedOk()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	OnClose();
	CDialogEx::OnOK();
}

void CMFCApplicationSampleDlg::OnBnClickedCancel()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.

//	OnClose(); 
	CDialogEx::OnCancel();
}

// program end
void CMFCApplicationSampleDlg::OnClose()
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	int nResult = ctsServerClose();

	DeleteCriticalSection(&cs);

	CDialogEx::OnClose();
}


#if 0

//�׽�Ʈ ���� �̺�Ʈ ����
LRESULT CMFCApplicationSampleDlg::OnTestComplete(WPARAM wParam, LPARAM lParam)
{
	int nModuleID = (int)wParam;
	int nChannelNum = (int)lParam;

	CString strOut;

	strOut.Format("Test Complete (ModuleID : %d, Channel : %d)",nModuleID, nChannelNum);
	AddLog(strOut);

	return 0;
}

//Emergency �̺�Ʈ ����
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

			// �� 100ms �ð����� ch data ����
			// 1ch�� 100���� data ���Ž� Log â�� display
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

//�������κ��� ������ ���� ���� ����
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

//������� ���� ����
LRESULT CMFCApplicationSampleDlg::OnModuleConnected(WPARAM wParam, LPARAM lParam)
{
	KillTimer(1001);

	m_ListRecv.ResetContent();

	int nModuleID = (int)wParam; //��� ID
	CString strAddLog;

	memcpy(&gst_SystemData,(void*)lParam,sizeof(CTS_MD_SYSTEM_DATA)); //������� �ý��� ����

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

//������� ��� ���� ����
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

//�ǽð� ����͸� �������̸�, ���� �����ʹ� ������ ó���ؾߵ�.
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
void CMFCApplicationSampleDlg::OnBnClickedButtonTest()	//DLL ���� �ε�.
{
	ctsSendContinue(1,1,0,0);

#if 0
	//ctsSetLogPath("c:\\TEST1\\TEST1\\11");				//�α� ��� ����

	//ctsSendNextStep(1,  2, 0);

	//ctsSendPause(1,2,0,1,5);

	//ctsSendPauseCancel(1,2,0);

	//ctsSendStop(1,2,0,0,0);

	/*typedef BOOL (*TestMsgBox)(char* szMsg);    
	
	TestMsgBox lpTestMsgBox;   //Dll �ν��Ͻ� �ڵ� ����
	HINSTANCE hDll;              //Dll�� �ε��Ѵ�.

#ifdef _DEBUG
	hDll =AfxLoadLibrary("PSServerAPId.dll");
#else
	hDll =AfxLoadLibrary("PSServerAPI.dll");
#endif	

	if(hDll==NULL)
	{
		AfxMessageBox("Dll�� �����ϴ�.");
		return;
	}

	lpTestMsgBox=(TestMsgBox)GetProcAddress(hDll,"TestMsgBox");  //�Լ��� ��´�.

	if(lpTestMsgBox==NULL)
	{
		AfxMessageBox("�Լ��� �����ϴ�. ");
		return;
	}

	lpTestMsgBox("abcd");
    
	AfxFreeLibrary(hDll); //DLL ����*/
#endif
}

void CMFCApplicationSampleDlg::OnBnClickedButtonTest3()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	ctsSendPause(1,1,0,0,0);
}

void CMFCApplicationSampleDlg::OnBnClickedButtonTest4()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	ctsSendPauseCancel(1,1,0);
}

void CMFCApplicationSampleDlg::OnBnClickedButtonTest5()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	//ctsSendStop(1,1,0,0,0);

	CString strOut;
	m_SendScheduleChNum.GetWindowText(strOut);
	ctsSendStop(1,atoi(strOut),0,0,0);
}

void CMFCApplicationSampleDlg::OnBnClickedButtonTest6()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	ctsSendStopCancel(1,1,0);
}

void CMFCApplicationSampleDlg::OnBnClickedButtonTest7()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	ctsSendNextStep (1,1,0);
}

void CMFCApplicationSampleDlg::OnBnClickedButtonTest8()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	ctsSetLogPath("c:\\Data\\log");				//�α� ��� ����

	//int nRtn = ctsServerCreate(1,this->m_hWnd); //��� ����, ������ �ڵ�
	int nRtn = ctsServerCreate(1,NULL); //��� ����, ������ �ڵ�
	TRACE("ctsServerCreate rtn : %d\n",nRtn);
	
	nRtn = ctsServerStart();					//���� ����
	TRACE("ctsServerStart rtn : %d\n",nRtn);

	SetTimer(1001, 1000, NULL);					//���� �� display ����
}

void CMFCApplicationSampleDlg::OnBnClickedButtonTest9()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	ctsServerClose();
}

void CMFCApplicationSampleDlg::OnBnClickedButtonTest10()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	CTS_VARIABLE_CH_DATA *ch = ctsGetRealChData(1,1);

	CString str;
	str.Format("ctsGetRealChData chReservedCmd : %d",ch->chData.chReservedCmd);
	((CMFCApplicationSampleDlg*)g_pParent)->AddLog(str);
}


void CMFCApplicationSampleDlg::OnBnClickedButtonTest11()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	CString strMaster, strSlave;
	CString str;
	int ParallelOption = 0;						//ParallelOption 0 : ���� ����, 1 : ���� ���� 
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

//�⺻������ �� ������ DLL ���� �ε��� ����ϰ� ������
//���⼭�� DLL ���� �ε� ������ �߰�.
void CMFCApplicationSampleDlg::OnBnClickedButtonLoadDll()
{	
	if(m_hDll)
	{
		AfxMessageBox("�̹� dll�� �ε� �Ǿ��ֽ��ϴ�.");
		return;
	}

	m_hDll = LoadLibrary("PSServerAPI.dll");

	if(!m_hDll)
	{
		AfxMessageBox("dll �ε� ����");
		return;
	}


	ctsServerCreateFunc lpCtsServerCreate;
	lpCtsServerCreate = (ctsServerCreateFunc)GetProcAddress(m_hDll,"ctsServerCreate");  //�Լ��� ��´�.

	if(!lpCtsServerCreate)
	{
		AfxMessageBox(_T("ctsServerCreate �Լ��� ���� �ּҰ��� �����µ� �����߽��ϴ�."));
		return;
	}

	ctsServerStartFunc lpCtsServerStart;
	lpCtsServerStart = (ctsServerStartFunc)GetProcAddress(m_hDll,"ctsServerStart");  //�Լ��� ��´�.

	if(!lpCtsServerStart)
	{
		AfxMessageBox(_T("ctsServerStart �Լ��� ���� �ּҰ��� �����µ� �����߽��ϴ�."));
		return;
	}

	ctsSetLogPathFunc lpCtsSetLogPath;
	lpCtsSetLogPath = (ctsSetLogPathFunc)GetProcAddress(m_hDll,"ctsSetLogPath");  //�Լ��� ��´�.

	if(!lpCtsSetLogPath)
	{
		AfxMessageBox(_T("ctsSetLogPath �Լ��� ���� �ּҰ��� �����µ� �����߽��ϴ�."));
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

	strLog.Format("DLL �ε� Count : %d",++m_nLoadCount);
	AddLog(strLog);

	SetTimer(1001, 1000, NULL);					//���� �� display ����
}

//�⺻������ �� ������ DLL ���� �ε��� ����ϰ� ������
//���⼭�� DLL ���� �ε� ������ �߰�.
void CMFCApplicationSampleDlg::OnBnClickedButtonUnloadDll()
{
	CString strLog;

	if(m_hDll)
	{
		ctsServerCloseFunc lpCtsServerClose;
		lpCtsServerClose = (ctsServerCloseFunc)GetProcAddress(m_hDll,"ctsServerClose");  //�Լ��� ��´�.

		if(!lpCtsServerClose)
		{
			AfxMessageBox(_T("ctsServerClose �Լ��� ���� �ּҰ��� �����µ� �����߽��ϴ�."));
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

		strLog.Format("DLL ��ε� Count : %d",++m_nUnloadCount);
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
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	if(ctsReleaseAllAux(1) != CTS_ACK)
	{
		AfxMessageBox("���� ����");
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
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	//ctsSendIso(1,1,0,0); //����
	//ctsSendIso(1,1,1); //����
	ctsSendIsoNormal(1,0,1);

}


void CMFCApplicationSampleDlg::OnBnClickedButtonNonIso()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	//ctsSendIso(1,1,0,1); //������
	//ctsSendIso(1,1,0); //������
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

//������ ȣ�� �������� ����
//�����忡�� create ��
//�� �ٸ� �����忡�� close�� ���� �߻��Ѵٰ� �Ͽ� �׽�Ʈ.
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
		////////////////////////////////////////////// ������ ����
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

	//���� ����
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
	//���� ����
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

	//���� ����
	SimpleSch[3].nStepType = PS_STEP_REST; //REST
	SimpleSch[3].nRecordTime = 1;
	SimpleSch[3].nCutoffCondTime = 10;

	//���� ����
	SimpleSch[4].nStepType = PS_STEP_DISCHARGE;
	SimpleSch[4].nMode = PS_MODE_CC;
	SimpleSch[4].nRefVoltage = 2800;
	SimpleSch[4].nRefCurrent = 1500;
	SimpleSch[4].nRecordTime = 1;
	SimpleSch[4].nCutoffCondTime = 10;
	SimpleSch[4].nCutoffCondVolt = 3000;

	//���� ����
	SimpleSch[5].nStepType = PS_STEP_REST; //REST
	SimpleSch[5].nRecordTime = 1;
	SimpleSch[5].nCutoffCondTime = 10;
	////////////////////////////////////////////////////////////////////
#endif

	CString strOut;
	m_SendScheduleChNum.GetWindowText(strOut);
	////////////////////////////////////////////// ������ ����
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
