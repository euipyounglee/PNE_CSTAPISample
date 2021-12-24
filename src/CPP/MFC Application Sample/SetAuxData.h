#pragma once


// CSetAuxData 대화 상자입니다.

class CSetAuxData : public CDialogEx
{
	DECLARE_DYNAMIC(CSetAuxData)

public:
	CSetAuxData(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CSetAuxData();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_SETAUXDATA };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()

public:
	virtual BOOL OnInitDialog();

	CWnd* m_pParent;

	/* Control Declare */
	CEdit m_eAuxDevChNum;
	CEdit m_eAuxChNum;
	CEdit m_eAuxSensorName;
	CEdit m_eAuxMax;
	CEdit m_eAuxEndMax;
	CEdit m_eAuxMin;
	CEdit m_eAuxEndMin;

	CComboBox m_cbAuxTherType1;
	CComboBox m_cbAuxTherType2;
	CComboBox m_cbAuxTherType3;
	CComboBox m_cbAuxThermiType;
	CComboBox m_cbAuxType;

	CButton m_btCSetAuxData;

	/* Aux */
	void GetSavedAuxData(CTS_MD_AUX_SET_DATA* pstAUXdata);
	void SetChAuxData(CTS_MD_AUX_SET_DATA* pstAUXdata);


	afx_msg void OnBnClickedButtonCSetAuxData();
	afx_msg void OnBnClickedButtonDebug();
	afx_msg void OnBnClickedButtonDebug2();
};
