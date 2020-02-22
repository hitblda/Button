#pragma once
#include <afxwin.h>

#define   IDC_OK  100
#define IDC_ChBox1 101
#define IDC_ChBox2 102
#define IDC_GrpBox 103
#define IDC_RadioBtn1 104
#define IDC_RadioBtn2 105
#define IDC_RadioBtn3 106

#define IDC_GrpBox2 203
#define IDC_RadioBtn4 204
#define IDC_RadioBtn5 205
#define IDC_RadioBtn6 206

class CMyApp:public CWinApp
{


public:
	virtual BOOL InitInstance();
};

class CMainWindow :public CWnd
{
public:
	CMainWindow();

protected:
	CButton m_wndPushButton;
	CButton	m_wndCheckBoxButton1;
	CButton	m_wndCheckBoxButton2;
	CButton m_wndGroupBoxButton;
	CButton m_wndRadioButton1;
	CButton m_wndRadioButton2;
	CButton m_wndRadioButton3;
	CButton m_wndGroupBoxButton2;
	CButton m_wndRadioButton4;
	CButton m_wndRadioButton5;
	CButton m_wndRadioButton6;

public:
	DECLARE_MESSAGE_MAP()
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void BntPushCLicked();
	afx_msg void BntChkBox1();
	afx_msg void BntChkBox2();
	afx_msg void RadioBntFn1();
	afx_msg void RadioBntFn2();
	afx_msg void RadioBntFn3();
	afx_msg void RadioBntFn4();
	afx_msg void RadioBntFn5();
	afx_msg void RadioBntFn6();

};