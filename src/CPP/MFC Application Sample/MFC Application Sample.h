
// MFC Application Sample.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"		// �� ��ȣ�Դϴ�.


// CMFCApplicationSampleApp:
// �� Ŭ������ ������ ���ؼ��� MFC Application Sample.cpp�� �����Ͻʽÿ�.
//

class CMFCApplicationSampleApp : public CWinApp
{
public:
	CMFCApplicationSampleApp();

// �������Դϴ�.
public:
	virtual BOOL InitInstance();

// �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};

extern CMFCApplicationSampleApp theApp;