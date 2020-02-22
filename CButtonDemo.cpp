
#include "CButtonDemo.h"

CMyApp myApp;

BOOL CMyApp::InitInstance()
{
	// TODO: 在此添加专用代码和/或调用基类
	//Creat a window
	this->m_pMainWnd = new CMainWindow; //调用构造函数，所以需要构造函数
	//Show Window
	this->m_pMainWnd->ShowWindow(this->m_nCmdShow);
	//update Window
	this->m_pMainWnd->UpdateWindow();

	return true;

//.	return CWinApp::InitInstance();
}

CMainWindow::CMainWindow()
{
	//在构造函数里面，自己构造窗口类
	//注册窗口类
	CString strWndClass = AfxRegisterWndClass(
		0,//样式
		myApp.LoadStandardCursor(IDC_ARROW), //光标
		(HBRUSH)(COLOR_3DFACE+1),//背景刷，用WIns里面常见的灰色
		myApp.LoadStandardIcon(IDI_WINLOGO)//像标句柄
		);
	//用这个窗口类创建窗口
	CreateEx(
		0,//没有用扩展的窗口样式
		strWndClass,//用刚刚创建的窗口类来创建窗口
		_T("CButtonDemo"), //窗口的标题,窗口名
		WS_OVERLAPPED | WS_SYSMENU | WS_MINIMIZEBOX,//窗口样式
		CW_USEDEFAULT, CW_USEDEFAULT,//位置，为默认的
		CW_USEDEFAULT, CW_USEDEFAULT,//大小，为默认的
		0,//窗口父句柄
		0,//窗口菜单
		0//窗口创建参数
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

	// TODO:  在此添加您专用的创建代码

	CRect rect;
	rect.SetRect(60,60,160,96);
	m_wndPushButton.Create(_T("按钮btn"), //按钮上的文字
		WS_CHILD|WS_VISIBLE|BS_PUSHBUTTON, //按钮的样式，都是子按钮&显示&具体的是pushBtn
		rect,//按钮的位置
		this,//父窗口，即 CMainWindow
		IDC_OK //按钮ID  //IDC_OK ==>IDOK
		);

	CRect rect1;
	rect1.SetRect(60, 130, 180, 156);
	m_wndCheckBoxButton1.Create(_T("checkBox1"), //按钮上的文字
		WS_CHILD | WS_VISIBLE | BS_AUTOCHECKBOX, 
		//复选框CHECKBOX
		//BS_AUTOCHECKBOX和BS_CHECKBOX的区别BS_AUTOCHECKBOX点击会自动勾选或者去勾选
		rect1,//按钮的位置
		this,//父窗口，即 CMainWindow
		IDC_ChBox1 //按钮ID  //IDC_OK ==>IDOK
	);

	rect1.SetRect(60, 160, 180, 176);
	m_wndCheckBoxButton2.Create(_T("checkBox2"), //按钮上的文字
		WS_CHILD | WS_VISIBLE | BS_AUTOCHECKBOX,
		//BS_AUTOCHECKBOX和BS_CHECKBOX的区别BS_AUTOCHECKBOX点击会自动勾选或者去勾选
		rect1,//按钮的位置
		this,//父窗口，即 CMainWindow
		IDC_ChBox2 //按钮ID  //IDC_OK ==>IDOK
	);

	//////////////////////////////////////////
	rect1.SetRect(60, 220, 185, 456);
	m_wndGroupBoxButton.Create(_T("GrpBox"), //按钮上的文字
		WS_GROUP | WS_CHILD | WS_VISIBLE | BS_GROUPBOX,
		//GroupBox 只是一个框框
		rect1,//按钮的位置
		this,//父窗口，即 CMainWindow
		IDC_GrpBox //按钮ID 
	);

	rect1.SetRect(65, 280, 180, 316);
	m_wndRadioButton1.Create(_T("RadioBtn1"), //按钮上的文字
		WS_GROUP|WS_CHILD | WS_VISIBLE | BS_AUTORADIOBUTTON,
		rect1,//按钮的位置
		this,//父窗口，即 CMainWindow
		IDC_RadioBtn1 //按钮ID 
	);
	rect1.SetRect(65, 320, 180, 356);
	m_wndRadioButton2.Create(_T("RadioBtn2"), //按钮上的文字
		WS_CHILD | WS_VISIBLE | BS_AUTORADIOBUTTON,
		rect1,//按钮的位置
		this,//父窗口，即 CMainWindow
		IDC_RadioBtn2 //按钮ID 
	); 
	rect1.SetRect(65, 360, 180, 396);
	m_wndRadioButton3.Create(_T("RadioBtn3"), //按钮上的文字
		WS_CHILD | WS_VISIBLE | BS_AUTORADIOBUTTON,
		rect1,//按钮的位置
		this,//父窗口，即 CMainWindow
		IDC_RadioBtn3 //按钮ID 
	);

	//////////////////////////////////////////
	rect1.SetRect(360, 220, 485, 456);
	m_wndGroupBoxButton2.Create(_T("GrpBox2"), //按钮上的文字
		WS_GROUP | WS_CHILD | WS_VISIBLE | BS_GROUPBOX,
		//GroupBox 只是一个框框
		rect1,//按钮的位置
		this,//父窗口，即 CMainWindow
		IDC_GrpBox2 //按钮ID 
	);

	rect1.SetRect(365, 280, 480, 316);
	m_wndRadioButton4.Create(_T("RadioBtn4"), //按钮上的文字
		WS_GROUP | WS_CHILD | WS_VISIBLE | BS_AUTORADIOBUTTON,
		rect1,//按钮的位置
		this,//父窗口，即 CMainWindow
		IDC_RadioBtn4 //按钮ID 
	);
	rect1.SetRect(365, 320, 480, 356);
	m_wndRadioButton5.Create(_T("RadioBtn5"), //按钮上的文字
		WS_CHILD | WS_VISIBLE | BS_AUTORADIOBUTTON,
		rect1,//按钮的位置
		this,//父窗口，即 CMainWindow
		IDC_RadioBtn5 //按钮ID 
	);
	rect1.SetRect(365, 360, 480, 396);
	m_wndRadioButton6.Create(_T("RadioBtn6"), //按钮上的文字
		WS_CHILD | WS_VISIBLE | BS_AUTORADIOBUTTON,
		rect1,//按钮的位置
		this,//父窗口，即 CMainWindow
		IDC_RadioBtn6 //按钮ID 
	);

	return 0;
}

void CMainWindow::BntPushCLicked()
{
	MessageBox(_T("按钮btn被按下！"));
}

void CMainWindow::BntChkBox1()
{
	if (BST_CHECKED == IsDlgButtonChecked(IDC_ChBox1))
	{
		MessageBox(_T("CheckBox1被选中！"));
	}
	else
	{
		MessageBox(_T("CheckBox1被取消选中！"));
	}
}

void CMainWindow::BntChkBox2()
{
	if (BST_CHECKED == IsDlgButtonChecked(IDC_ChBox2))
	{//由空闲态==》被选中时，触发
		MessageBox(_T("CheckBox2被选中！"));
	}
	else
	{//由被选中==》去选中时，触发
		MessageBox(_T("CheckBox2被取消选中！"));
	}
}

void CMainWindow::RadioBntFn1()
{
	if (m_wndRadioButton1.GetCheck() == BST_CHECKED)
	{
		MessageBox(_T("多选一RadioBnt1被选中！"));
	}
}

void CMainWindow::RadioBntFn2()
{
	if (m_wndRadioButton2.GetCheck() == BST_CHECKED)
	{
		MessageBox(_T("多选一RadioBnt2被选中！"));
	}
}

void CMainWindow::RadioBntFn3()
{
	if (m_wndRadioButton3.GetCheck() == BST_CHECKED)
	{
		MessageBox(_T("多选一RadioBnt3被选中！"));
	}
}

void CMainWindow::RadioBntFn4()
{
	if (m_wndRadioButton4.GetCheck() == BST_CHECKED)
	{
		MessageBox(_T("多选一RadioBnt4被选中！"));
	}
}

void CMainWindow::RadioBntFn5()
{
	if (m_wndRadioButton5.GetCheck() == BST_CHECKED)
	{
		MessageBox(_T("多选一RadioBnt5被选中！"));
	}
}


void CMainWindow::RadioBntFn6()
{
	if (m_wndRadioButton6.GetCheck() == BST_CHECKED)
	{
		MessageBox(_T("多选一RadioBnt6被选中！"));
	}
}



