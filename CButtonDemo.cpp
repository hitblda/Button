
#include "CButtonDemo.h"

CMyApp myApp;

BOOL CMyApp::InitInstance()
{
	// TODO: �ڴ����ר�ô����/����û���
	//Creat a window
	this->m_pMainWnd = new CMainWindow; //���ù��캯����������Ҫ���캯��
	//Show Window
	this->m_pMainWnd->ShowWindow(this->m_nCmdShow);
	//update Window
	this->m_pMainWnd->UpdateWindow();

	return true;

//.	return CWinApp::InitInstance();
}

CMainWindow::CMainWindow()
{
	//�ڹ��캯�����棬�Լ����촰����
	//ע�ᴰ����
	CString strWndClass = AfxRegisterWndClass(
		0,//��ʽ
		myApp.LoadStandardCursor(IDC_ARROW), //���
		(HBRUSH)(COLOR_3DFACE+1),//����ˢ����WIns���泣���Ļ�ɫ
		myApp.LoadStandardIcon(IDI_WINLOGO)//�����
		);
	//����������ഴ������
	CreateEx(
		0,//û������չ�Ĵ�����ʽ
		strWndClass,//�øոմ����Ĵ���������������
		_T("CButtonDemo"), //���ڵı���,������
		WS_OVERLAPPED | WS_SYSMENU | WS_MINIMIZEBOX,//������ʽ
		CW_USEDEFAULT, CW_USEDEFAULT,//λ�ã�ΪĬ�ϵ�
		CW_USEDEFAULT, CW_USEDEFAULT,//��С��ΪĬ�ϵ�
		0,//���ڸ����
		0,//���ڲ˵�
		0//���ڴ�������
	);
}
BEGIN_MESSAGE_MAP(CMainWindow, CWnd)
	ON_WM_CREATE()
	ON_BN_CLICKED(IDC_OK,BntPushCLicked)
	ON_BN_CLICKED(IDC_ChBox1, BntChkBox1)
	ON_BN_CLICKED(IDC_ChBox2, BntChkBox2)
	ON_BN_CLICKED(IDC_RadioBtn1, RadioBntFn1)
	ON_BN_CLICKED(IDC_RadioBtn2, RadioBntFn2)
	ON_BN_CLICKED(IDC_RadioBtn3, RadioBntFn3)
	ON_BN_CLICKED(IDC_RadioBtn4, RadioBntFn4)
	ON_BN_CLICKED(IDC_RadioBtn5, RadioBntFn5)
	ON_BN_CLICKED(IDC_RadioBtn6, RadioBntFn6)

END_MESSAGE_MAP()


int CMainWindow::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  �ڴ������ר�õĴ�������

	CRect rect;
	rect.SetRect(60,60,160,96);
	m_wndPushButton.Create(_T("��ťbtn"), //��ť�ϵ�����
		WS_CHILD|WS_VISIBLE|BS_PUSHBUTTON, //��ť����ʽ�������Ӱ�ť&��ʾ&�������pushBtn
		rect,//��ť��λ��
		this,//�����ڣ��� CMainWindow
		IDC_OK //��ťID  //IDC_OK ==>IDOK
		);

	CRect rect1;
	rect1.SetRect(60, 130, 180, 156);
	m_wndCheckBoxButton1.Create(_T("checkBox1"), //��ť�ϵ�����
		WS_CHILD | WS_VISIBLE | BS_AUTOCHECKBOX, 
		//��ѡ��CHECKBOX
		//BS_AUTOCHECKBOX��BS_CHECKBOX������BS_AUTOCHECKBOX������Զ���ѡ����ȥ��ѡ
		rect1,//��ť��λ��
		this,//�����ڣ��� CMainWindow
		IDC_ChBox1 //��ťID  //IDC_OK ==>IDOK
	);

	rect1.SetRect(60, 160, 180, 176);
	m_wndCheckBoxButton2.Create(_T("checkBox2"), //��ť�ϵ�����
		WS_CHILD | WS_VISIBLE | BS_AUTOCHECKBOX,
		//BS_AUTOCHECKBOX��BS_CHECKBOX������BS_AUTOCHECKBOX������Զ���ѡ����ȥ��ѡ
		rect1,//��ť��λ��
		this,//�����ڣ��� CMainWindow
		IDC_ChBox2 //��ťID  //IDC_OK ==>IDOK
	);

	//////////////////////////////////////////
	rect1.SetRect(60, 220, 185, 456);
	m_wndGroupBoxButton.Create(_T("GrpBox"), //��ť�ϵ�����
		WS_GROUP | WS_CHILD | WS_VISIBLE | BS_GROUPBOX,
		//GroupBox ֻ��һ�����
		rect1,//��ť��λ��
		this,//�����ڣ��� CMainWindow
		IDC_GrpBox //��ťID 
	);

	rect1.SetRect(65, 280, 180, 316);
	m_wndRadioButton1.Create(_T("RadioBtn1"), //��ť�ϵ�����
		WS_GROUP|WS_CHILD | WS_VISIBLE | BS_AUTORADIOBUTTON,
		rect1,//��ť��λ��
		this,//�����ڣ��� CMainWindow
		IDC_RadioBtn1 //��ťID 
	);
	rect1.SetRect(65, 320, 180, 356);
	m_wndRadioButton2.Create(_T("RadioBtn2"), //��ť�ϵ�����
		WS_CHILD | WS_VISIBLE | BS_AUTORADIOBUTTON,
		rect1,//��ť��λ��
		this,//�����ڣ��� CMainWindow
		IDC_RadioBtn2 //��ťID 
	); 
	rect1.SetRect(65, 360, 180, 396);
	m_wndRadioButton3.Create(_T("RadioBtn3"), //��ť�ϵ�����
		WS_CHILD | WS_VISIBLE | BS_AUTORADIOBUTTON,
		rect1,//��ť��λ��
		this,//�����ڣ��� CMainWindow
		IDC_RadioBtn3 //��ťID 
	);

	//////////////////////////////////////////
	rect1.SetRect(360, 220, 485, 456);
	m_wndGroupBoxButton2.Create(_T("GrpBox2"), //��ť�ϵ�����
		WS_GROUP | WS_CHILD | WS_VISIBLE | BS_GROUPBOX,
		//GroupBox ֻ��һ�����
		rect1,//��ť��λ��
		this,//�����ڣ��� CMainWindow
		IDC_GrpBox2 //��ťID 
	);

	rect1.SetRect(365, 280, 480, 316);
	m_wndRadioButton4.Create(_T("RadioBtn4"), //��ť�ϵ�����
		WS_GROUP | WS_CHILD | WS_VISIBLE | BS_AUTORADIOBUTTON,
		rect1,//��ť��λ��
		this,//�����ڣ��� CMainWindow
		IDC_RadioBtn4 //��ťID 
	);
	rect1.SetRect(365, 320, 480, 356);
	m_wndRadioButton5.Create(_T("RadioBtn5"), //��ť�ϵ�����
		WS_CHILD | WS_VISIBLE | BS_AUTORADIOBUTTON,
		rect1,//��ť��λ��
		this,//�����ڣ��� CMainWindow
		IDC_RadioBtn5 //��ťID 
	);
	rect1.SetRect(365, 360, 480, 396);
	m_wndRadioButton6.Create(_T("RadioBtn6"), //��ť�ϵ�����
		WS_CHILD | WS_VISIBLE | BS_AUTORADIOBUTTON,
		rect1,//��ť��λ��
		this,//�����ڣ��� CMainWindow
		IDC_RadioBtn6 //��ťID 
	);

	return 0;
}

void CMainWindow::BntPushCLicked()
{
	MessageBox(_T("��ťbtn�����£�"));
}

void CMainWindow::BntChkBox1()
{
	if (BST_CHECKED == IsDlgButtonChecked(IDC_ChBox1))
	{
		MessageBox(_T("CheckBox1��ѡ�У�"));
	}
	else
	{
		MessageBox(_T("CheckBox1��ȡ��ѡ�У�"));
	}
}

void CMainWindow::BntChkBox2()
{
	if (BST_CHECKED == IsDlgButtonChecked(IDC_ChBox2))
	{//�ɿ���̬==����ѡ��ʱ������
		MessageBox(_T("CheckBox2��ѡ�У�"));
	}
	else
	{//�ɱ�ѡ��==��ȥѡ��ʱ������
		MessageBox(_T("CheckBox2��ȡ��ѡ�У�"));
	}
}

void CMainWindow::RadioBntFn1()
{
	if (m_wndRadioButton1.GetCheck() == BST_CHECKED)
	{
		MessageBox(_T("��ѡһRadioBnt1��ѡ�У�"));
	}
}

void CMainWindow::RadioBntFn2()
{
	if (m_wndRadioButton2.GetCheck() == BST_CHECKED)
	{
		MessageBox(_T("��ѡһRadioBnt2��ѡ�У�"));
	}
}

void CMainWindow::RadioBntFn3()
{
	if (m_wndRadioButton3.GetCheck() == BST_CHECKED)
	{
		MessageBox(_T("��ѡһRadioBnt3��ѡ�У�"));
	}
}

void CMainWindow::RadioBntFn4()
{
	if (m_wndRadioButton4.GetCheck() == BST_CHECKED)
	{
		MessageBox(_T("��ѡһRadioBnt4��ѡ�У�"));
	}
}

void CMainWindow::RadioBntFn5()
{
	if (m_wndRadioButton5.GetCheck() == BST_CHECKED)
	{
		MessageBox(_T("��ѡһRadioBnt5��ѡ�У�"));
	}
}


void CMainWindow::RadioBntFn6()
{
	if (m_wndRadioButton6.GetCheck() == BST_CHECKED)
	{
		MessageBox(_T("��ѡһRadioBnt6��ѡ�У�"));
	}
}



