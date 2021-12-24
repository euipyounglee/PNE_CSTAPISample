
// MFC Application SampleDlg.h : 헤더 파일
//

#pragma once
#include "afxwin.h"
#include "SetAuxData.h"


extern CTS_MD_SYSTEM_DATA gst_SystemData;

// CMFCApplicationSampleDlg 대화 상자
class CMFCApplicationSampleDlg : public CDialogEx
{
// 생성입니다.
public:
	CMFCApplicationSampleDlg(CWnd* pParent = NULL);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
	enum { IDD = IDD_MFCAPPLICATIONSAMPLE_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	CWnd* m_pParent;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()

public:
	static UINT ThreadTEST(LPVOID lparam);
	static UINT ThreadTEST2(LPVOID lparam);


	CStatic m_StatusCh1;
	CStatic m_StatusCh2;
	CStatic m_StatusCh3;
	CStatic m_StatusCh4;

	CButton m_btConnect;

	CButton m_btSensSchedule;
	CButton m_btSetAuxData;
	CButton m_btSetCANReceive;
	CButton m_btSetCANTrancemit;
	CButton m_btSetParallel;
	CButton m_btSetAuxDataGet;
	CButton m_btSetAuxDataGetInfo;
	CButton m_btSetCANReceiveGet;
	CButton m_btSetCANTrancemitGet;
	CButton m_btSetParallelGet;
	CButton m_btLintoCAN;

	CListBox m_ListRecv;

	CEdit m_SendScheduleChNum;
	CEdit m_SendParallel1;
	CEdit m_SendParallel2;

	int m_iRecvRealTimeChDataCount;

	HINSTANCE m_hDll; //ksj 20191213
	int m_nLoadCount; //ksj 20191213
	int m_nUnloadCount; //ksj 20191213

	
	BOOL m_bConnected;

	void UpdateDlg(BOOL Enable);
	void AddLog(CString strLog);
	int UpdateMonitoringData(int nModuleID);
	static UINT ThreadTest(LPVOID pParam);

	afx_msg void OnBnClickedButtonTest();
	afx_msg void OnBnClickedButtonConnect();
	afx_msg void OnBnClickedButtonSendSchedule();
	afx_msg void OnBnClickedButtonAuxData();
	afx_msg void OnBnClickedButtonCanRev();
	afx_msg void OnBnClickedButtonCanTran();

	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnClose();
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
	afx_msg void OnBnClickedButtonParallel();
	afx_msg void OnBnClickedButtonLinToCanStart();
	afx_msg void OnBnClickedButtonAuxDataGetInfo();
	afx_msg void OnBnClickedButtonCanRevGet();
	afx_msg void OnBnClickedButtonCanTranGet();
	afx_msg void OnBnClickedButtonParallelGet();
	afx_msg void OnBnClickedButtonAuxDataGet();

#if 0
	afx_msg LRESULT OnDataStackedNotify(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnModuleConnected(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnModuleClosed(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnGetChData(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnTestComplete(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnEmg(WPARAM wParam, LPARAM lParam);
#endif
	afx_msg void OnBnClickedButtonTest3();
	afx_msg void OnBnClickedButtonTest4();
	afx_msg void OnBnClickedButtonTest5();
	afx_msg void OnBnClickedButtonTest6();
	afx_msg void OnBnClickedButtonTest7();
	afx_msg void OnBnClickedButtonTest8();
	afx_msg void OnBnClickedButtonTest9();
	afx_msg void OnBnClickedButtonTest10();
	afx_msg void OnBnClickedButtonTest11();
	afx_msg void OnBnClickedButtonLoadDll();
	afx_msg void OnBnClickedButtonUnloadDll();
	afx_msg void OnBnClickedButtonDebug();
	afx_msg void OnBnClickedButtonAuxRelease();
	afx_msg void OnBnClickedButtonTest12();
	afx_msg void OnBnClickedButtonIso();
	afx_msg void OnBnClickedButtonNonIso();
	afx_msg void OnBnClickedButtonGetStepCount();
	afx_msg void OnBnClickedButtonGetSchStepinfo();
	afx_msg void OnBnClickedButtonGetCbInfo();
	afx_msg void OnBnClickedButtonConnectThread();
	afx_msg void OnBnClickedButtonCloseThread();
	afx_msg void OnBnClickedButtonSendSchedule2();
	afx_msg void OnBnClickedButtonPopTest();
	afx_msg void OnBnClickedButtonSendSchedule3();
};
