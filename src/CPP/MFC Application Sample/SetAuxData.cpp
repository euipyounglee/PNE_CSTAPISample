// CSetAuxData.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "MFC Application Sample.h"
#include "MFC Application SampleDlg.h"
#include "SetAuxData.h"
#include "afxdialogex.h"

// CSetAuxData 대화 상자입니다.

IMPLEMENT_DYNAMIC(CSetAuxData, CDialogEx)

CSetAuxData::CSetAuxData(CWnd* pParent /*=NULL*/)
	: CDialogEx(CSetAuxData::IDD, pParent)
{

}

CSetAuxData::~CSetAuxData()
{
}

void CSetAuxData::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);

	DDX_Control(pDX, IDC_EDIT_AUX_DEV_CH, m_eAuxDevChNum);
	DDX_Control(pDX, IDC_EDIT_AUX_CH, m_eAuxChNum);
	DDX_Control(pDX, IDC_EDIT_AUX_SENSOR_NAME, m_eAuxSensorName);
	DDX_Control(pDX, IDC_EDIT_AUX_MAX, m_eAuxMax);
	DDX_Control(pDX, IDC_EDIT_AUX_END_MAX, m_eAuxEndMax);
	DDX_Control(pDX, IDC_EDIT_AUX_MIN, m_eAuxMin);
	DDX_Control(pDX, IDC_EDIT_AUX_END_MIN, m_eAuxEndMin);

	DDX_Control(pDX, IDC_COMBO_AUX_THERMI_TYPE,m_cbAuxThermiType );
	DDX_Control(pDX, IDC_COMBO_AUX_THERMI_TYPE_1, m_cbAuxTherType1);
	DDX_Control(pDX, IDC_COMBO_AUX_THERMI_TYPE_2, m_cbAuxTherType2);
	DDX_Control(pDX, IDC_COMBO_AUX_THERMI_TYPE_3, m_cbAuxTherType3);
	DDX_Control(pDX, IDC_COMBO_AUX_TYPE, m_cbAuxType);

	DDX_Control(pDX, IDC_BUTTON_SET_AUX_DATA, m_btCSetAuxData);
}


BEGIN_MESSAGE_MAP(CSetAuxData, CDialog)
	ON_BN_CLICKED(IDC_BUTTON_SET_AUX_DATA, &CSetAuxData::OnBnClickedButtonCSetAuxData)
	ON_BN_CLICKED(IDC_BUTTON_DEBUG, &CSetAuxData::OnBnClickedButtonDebug)
	ON_BN_CLICKED(IDC_BUTTON_DEBUG2, &CSetAuxData::OnBnClickedButtonDebug2)
END_MESSAGE_MAP()


// CSetAuxData 메시지 처리기입니다.

BOOL CSetAuxData::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO: 여기에 추가 초기화 작업을 추가합니다.
	m_pParent = this->GetTopLevelParent();

	m_eAuxDevChNum.SetWindowTextA("0");
	m_eAuxChNum.SetWindowTextA("0");
	m_eAuxSensorName.SetWindowTextA("Test");
	m_eAuxMax.SetWindowTextA("4.2");
	m_eAuxEndMax.SetWindowTextA("4.3");
	m_eAuxMin.SetWindowTextA("2.4");
	m_eAuxEndMin.SetWindowTextA("2.3");


	m_cbAuxTherType1.SetCurSel(0);
	m_cbAuxTherType2.SetCurSel(0);
	m_cbAuxTherType3.SetCurSel(0);
	m_cbAuxThermiType.SetCurSel(0);
	m_cbAuxType.SetCurSel(0);
	
	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CSetAuxData::GetSavedAuxData(CTS_MD_AUX_SET_DATA* pstAUXdata)
{
	CTS_MD_AUX_INFO_DATA *pAuxInfo = ctsGetAuxInfoData(1);
	if(pAuxInfo == NULL)
		return;

	for(int i = 0 ; i < CTS_MAX_MAPPING_AUX; i++)
	{
		if(pAuxInfo->auxData[i].chNo > 0)
		{
			memcpy(&pstAUXdata[i], &pAuxInfo->auxData[i], sizeof(CTS_MD_AUX_SET_DATA));
		}
	}
}

void CSetAuxData::SetChAuxData(CTS_MD_AUX_SET_DATA* pstAUXdata)
{
	/*CString strOut;
	int nChNum = 0;
	int nAuxChNum = 0;

	m_eAuxDevChNum.GetWindowText(strOut);
	nChNum = atoi(strOut);

	m_eAuxChNum.GetWindowText(strOut);
	nAuxChNum = atoi(strOut);

	pstAUXdata[nChNum].chNo = nChNum;
	pstAUXdata[nChNum].auxChNo = nAuxChNum;

	m_eAuxSensorName.GetWindowText(strOut);
	sprintf(pstAUXdata[nChNum].szName, "%s", strOut);

	m_eAuxMax.GetWindowText(strOut);
	pstAUXdata[nChNum].lMaxData = atof(strOut);

	m_eAuxEndMax.GetWindowText(strOut);
	pstAUXdata[nChNum].lEndMaxData = atof(strOut);

	m_eAuxMin.GetWindowText(strOut);
	pstAUXdata[nChNum].lMinData = atof(strOut);

	m_eAuxEndMin.GetWindowText(strOut);
	pstAUXdata[nChNum].lEndMinData = atof(strOut);

	pstAUXdata[nChNum].auxType = m_cbAuxType.GetCurSel();

	pstAUXdata[nChNum].funtion_division1 = m_cbAuxTherType1.GetCurSel();
	pstAUXdata[nChNum].funtion_division2 = m_cbAuxTherType2.GetCurSel();
	pstAUXdata[nChNum].funtion_division3 = m_cbAuxTherType3.GetCurSel();*/


	CString strOut;
	int nChNum = 0;
	int nAuxChNum = 0;
	int nAuxType = 0;

	m_eAuxDevChNum.GetWindowText(strOut);
	nChNum = atoi(strOut);
	m_eAuxChNum.GetWindowText(strOut);
	nAuxChNum = atoi(strOut);
	nAuxType = m_cbAuxType.GetCurSel();

	for(int nAuxIndex=0; nAuxIndex<512; nAuxIndex++)
	{		
		if((pstAUXdata[nAuxIndex].auxChNo == nAuxChNum) &&pstAUXdata[nAuxIndex].auxType == nAuxType)
		{
			pstAUXdata[nAuxIndex].chNo = nChNum;
			//pstAUXdata[nAuxIndex].auxChNo = nAuxChNum;

			m_eAuxSensorName.GetWindowText(strOut);
			sprintf(pstAUXdata[nAuxIndex].szName, "%s", strOut);

			m_eAuxMax.GetWindowText(strOut);
			pstAUXdata[nAuxIndex].lMaxData = atof(strOut);

			m_eAuxEndMax.GetWindowText(strOut);
			pstAUXdata[nAuxIndex].lEndMaxData = atof(strOut);

			m_eAuxMin.GetWindowText(strOut);
			pstAUXdata[nAuxIndex].lMinData = atof(strOut);

			m_eAuxEndMin.GetWindowText(strOut);
			pstAUXdata[nAuxIndex].lEndMinData = atof(strOut);

			//pstAUXdata[nAuxIndex].auxType = nAuxType;

			pstAUXdata[nAuxIndex].funtion_division1 = m_cbAuxTherType1.GetCurSel();
			pstAUXdata[nAuxIndex].funtion_division2 = m_cbAuxTherType2.GetCurSel();
			pstAUXdata[nAuxIndex].funtion_division3 = m_cbAuxTherType3.GetCurSel();

			break;
		}
		
	}
	
}

void CSetAuxData::OnBnClickedButtonCSetAuxData()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	int nModuleNum = 1;	
	CTS_MD_AUX_SET_DATA mdAuxData[CTS_MAX_MAPPING_AUX];
	ZeroMemory(mdAuxData, sizeof(CTS_MD_AUX_SET_DATA)*CTS_MAX_MAPPING_AUX);
	GetSavedAuxData(mdAuxData);

	SetChAuxData(mdAuxData);

	////////////////////////////////////////////// AUX data 전송
	//int errCode = ctsSendAuxData(nModuleNum, &mdAuxData[0]);
	int errCode = ctsSendAuxData_Org(nModuleNum, &mdAuxData[0]);
	if (errCode != CTS_ACK)
	{
		CString str;
		str.Format("ctsSendAuxData fail [%d]", errCode);
		AfxMessageBox(str);
	}
	else
	{
		((CMFCApplicationSampleDlg*)m_pParent)->AddLog("ctsSendAuxData Success");
	}
}

void CSetAuxData::OnBnClickedButtonDebug()
{
	int nModuleNum = 1;	
	CTS_MD_AUX_SET_DATA mdAuxData[3];
	ZeroMemory(mdAuxData, sizeof(CTS_MD_AUX_SET_DATA)*3);
	
	mdAuxData[0].auxChNo = 2;
	mdAuxData[0].chNo = 1;
	mdAuxData[0].auxType = 0;
	sprintf(mdAuxData[0].szName,"test1");

	mdAuxData[1].auxChNo = 3;
	mdAuxData[1].chNo = 2;
	mdAuxData[1].auxType = 1;
	sprintf(mdAuxData[1].szName,"test2");

	mdAuxData[2].auxChNo = 1;
	mdAuxData[2].chNo = 2;
	mdAuxData[2].auxType = 2;
	mdAuxData[2].lEndMaxData = 80000;
	mdAuxData[2].lEndMinData = 20000;
	mdAuxData[2].lMaxData = 90000;
	mdAuxData[2].lMinData = 10000;
	sprintf(mdAuxData[2].szName,"test3");
	

	////////////////////////////////////////////// AUX data 전송
	int errCode = ctsSendAuxData_V2(nModuleNum, &mdAuxData[0], 3);

	if (errCode != CTS_ACK)
	{
		CString str;
		str.Format("ctsSendAuxData fail [%d]", errCode);
		AfxMessageBox(str);
	}
	else
	{
		((CMFCApplicationSampleDlg*)m_pParent)->AddLog("ctsSendAuxData Success");
	}
}


void CSetAuxData::OnBnClickedButtonDebug2()
{
	/*int nModuleNum = 1;	
	CTS_MD_AUX_SET_DATA mdAuxData[2];
	ZeroMemory(mdAuxData, sizeof(CTS_MD_AUX_SET_DATA)*2);

	mdAuxData[0].auxChNo = 2;
	mdAuxData[0].chNo = 1;
	mdAuxData[0].auxType = 0;
	mdAuxData[0].funtion_division1 = 1;
	mdAuxData[0].funtion_division2 = 2;
	mdAuxData[0].funtion_division3 = 3;
	mdAuxData[0].lEndMaxData = 50000;
	mdAuxData[0].lEndMinData = 1;
	mdAuxData[0].lMaxData = 80000;
	mdAuxData[0].lMinData = 2;
	sprintf(mdAuxData[0].szName,"test3");

	mdAuxData[1].auxChNo = 1;
	mdAuxData[1].chNo = 2;
	mdAuxData[1].auxType = 1;
	mdAuxData[1].funtion_division1 = 1;
	mdAuxData[1].funtion_division2 = 2;
	mdAuxData[1].funtion_division3 = 3;
	mdAuxData[1].lEndMaxData = 50000;
	mdAuxData[1].lEndMinData = 1;
	mdAuxData[1].lMaxData = 80000;
	mdAuxData[1].lMinData = 2;
	sprintf(mdAuxData[1].szName,"test6");


	////////////////////////////////////////////// AUX data 전송
	int errCode = ctsSendAuxData_V2(nModuleNum, &mdAuxData[0],2);

	if (errCode != CTS_ACK)
	{
		CString str;
		str.Format("ctsSendAuxData fail [%d]", errCode);
		AfxMessageBox(str);
	}
	else
	{
		((CMFCApplicationSampleDlg*)m_pParent)->AddLog("ctsSendAuxData Success");
	}*/




	int nModuleNum = 1;	
	CTS_MD_AUX_SET_DATA_16 mdAuxData[3];
	ZeroMemory(mdAuxData, sizeof(CTS_MD_AUX_SET_DATA_16)*3);

	mdAuxData[0].auxChNo = 2;
	mdAuxData[0].chNo = 1;
	mdAuxData[0].auxType = 0;
	sprintf(mdAuxData[0].szName,"111test1");

	mdAuxData[1].auxChNo = 3;
	mdAuxData[1].chNo = 2;
	mdAuxData[1].auxType = 1;
	sprintf(mdAuxData[1].szName,"222test2");

	mdAuxData[2].auxChNo = 1;
	mdAuxData[2].chNo = 2;
	mdAuxData[2].auxType = 2;
	mdAuxData[2].lEndMaxData = 81000;
	mdAuxData[2].lEndMinData = 22000;
	mdAuxData[2].lMaxData = 93000;
	mdAuxData[2].lMinData = 14000;
	sprintf(mdAuxData[2].szName,"333test3");


	////////////////////////////////////////////// AUX data 전송
	int errCode = ctsSendAuxData16_V2(nModuleNum, &mdAuxData[0], 3);

	if (errCode != CTS_ACK)
	{
		CString str;
		str.Format("ctsSendAuxData fail [%d]", errCode);
		AfxMessageBox(str);
	}
	else
	{
		((CMFCApplicationSampleDlg*)m_pParent)->AddLog("ctsSendAuxData Success");
	}
}
