
// Spot Infomation ManagerDlg.cpp: 实现文件
//

#include "stdafx.h"
#include "Spot Infomation Manager.h"
#include "Spot Infomation ManagerDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CSpotInfomationManagerDlg 对话框



CSpotInfomationManagerDlg::CSpotInfomationManagerDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_SPOTINFOMATIONMANAGER_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CSpotInfomationManagerDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TAB1, tabCtrl);
	DDX_Control(pDX, IDC_COMBO1, op_cbx);
	DDX_Control(pDX, IDC_INPUT1, input_text_1);
	DDX_Control(pDX, IDC_INPUT2, input_text_2);
	DDX_Control(pDX, IDC_INPUT3, input_text_3);
	DDX_Control(pDX, IDC_EDIT1, input_res1);
	DDX_Control(pDX, IDC_EDIT2, input_res2);
	DDX_Control(pDX, IDC_EDIT3, input_res3);
	DDX_Control(pDX, IDC_BUTTON2, op_btn);
}

BEGIN_MESSAGE_MAP(CSpotInfomationManagerDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_NOTIFY(TCN_SELCHANGE, IDC_TAB1, &CSpotInfomationManagerDlg::OnTcnSelchangeTab1)
	ON_STN_CLICKED(IDC_INPUT2, &CSpotInfomationManagerDlg::OnStnClickedInput2)
	ON_STN_CLICKED(IDC_INPUT1, &CSpotInfomationManagerDlg::OnStnClickedInput1)
	ON_BN_CLICKED(IDC_BUTTON_QUERY, &CSpotInfomationManagerDlg::OnBnClickedButtonQuery)
	ON_BN_CLICKED(IDC_BUTTON_REFRESH, &CSpotInfomationManagerDlg::OnBnClickedButtonRefresh)
	ON_BN_CLICKED(IDC_BUTTON2, &CSpotInfomationManagerDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON1, &CSpotInfomationManagerDlg::OnBnClickedButton1)
	ON_CBN_SELCHANGE(IDC_COMBO1, &CSpotInfomationManagerDlg::OnCbnSelchangeCombo1)
END_MESSAGE_MAP()


// CSpotInfomationManagerDlg 消息处理程序

BOOL CSpotInfomationManagerDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
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

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	tabCtrl.InsertItem(0, TEXT("编辑信息"));
	tabCtrl.InsertItem(1, TEXT("节点信息查看"));


	infoEditor.Create(IDD_EDIT, &tabCtrl);

	// 节点信息初始化
	nodeList.Create(IDD_NODE_INFO, &tabCtrl);
	CString str[] = {
		TEXT("编号"),
		TEXT("景点名称"),
		TEXT("描述")
	};

	CListCtrl &listnow = nodeList.nodeList;

	for (int i = 0; i < 3; ++i) {
		listnow.InsertColumn(i,
			str[i], LVCFMT_LEFT, 100);
	}

	listnow.SetExtendedStyle(listnow.GetExtendedStyle() | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);


	//位置信息改变
	CRect rc, rcTabItem;
	tabCtrl.GetClientRect(&rc);
	tabCtrl.GetItemRect(0, &rcTabItem);
	rc.top += rcTabItem.Height() + 4;
	rc.left += 4;
	rc.bottom -= 4;
	rc.right -= 4;
	infoEditor.MoveWindow(&rc);
	nodeList.MoveWindow(&rc);

	//设置初始位置
	infoEditor.ShowWindow(SW_SHOW);
	nodeList.ShowWindow(SW_HIDE);
	tabCtrl.SetCurFocus(0);

	//queryDlg
	queryDlg.Create(IDD_QUERY);

	//op_now init
	op_now = -1;

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CSpotInfomationManagerDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CSpotInfomationManagerDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CSpotInfomationManagerDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CSpotInfomationManagerDlg::OnTcnSelchangeTab1(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: 在此添加控件通知处理程序代码
	switch (tabCtrl.GetCurSel())
	{
	case 0:
		infoEditor.ShowWindow(SW_SHOW);
		nodeList.ShowWindow(SW_HIDE);
		break;
	case 1:
		infoEditor.ShowWindow(SW_HIDE);
		nodeList.ShowWindow(SW_SHOW);
		break;
	default:
		break;
	}
	*pResult = 0;
}


void CSpotInfomationManagerDlg::OnStnClickedInput2()
{
	// TODO: 在此添加控件通知处理程序代码
}


void CSpotInfomationManagerDlg::OnStnClickedInput1()
{
	// TODO: 在此添加控件通知处理程序代码
}


void CSpotInfomationManagerDlg::OnBnClickedButtonQuery()
{
	// TODO: 在此添加控件通知处理程序代码
	RefreshInfo();
	queryDlg.setGraph(Graphnow);
	queryDlg.ShowWindow(SW_SHOWNORMAL);
}

void CSpotInfomationManagerDlg::RefreshInfo()
{
	infoEditor.update();
	CString str = infoEditor.nodeInfo;
	
	Graphnow.clear();
	
	CString strTmp[4];
	int p = 0, n = 0;
	int len = str.GetLength();
	for (int i = 0; i < len; ++i) {
		if (str.GetAt(i) == ' ' || str.GetAt(i) == '\n' || str.GetAt(i) == '\r') {
			while (i + 1 < len && str.GetAt(i + 1) == ' ' || str.GetAt(i + 1) == '\n' || str.GetAt(i + 1) == '\r') {
				i++;
				continue;
			}
			p++;
			if (p == 3) {
				p = 0;
				n++;
				Graphnow.insertNode(MessageNode(StrToInt(strTmp[0]), strTmp[1], strTmp[2]));
				strTmp[0].Empty();
				strTmp[1].Empty();
				strTmp[2].Empty();
			}
		}
		else {
			strTmp[p] += str.GetAt(i);
		}
	}
	if (p) {
		n++;
		p = 0;
		Graphnow.insertNode(MessageNode(StrToInt(strTmp[0]), strTmp[1], strTmp[2]));
	}
	//Graphnow.N = n;

	n = 0;
	str = infoEditor.edgeInfo;
	len = str.GetLength();
	for (int i = 0; i < len; ++i) {
		if (str.GetAt(i) == ' ' || str.GetAt(i) == '\n' || str.GetAt(i) == '\r') {
			while (i + 1 < len && str.GetAt(i + 1) == ' ' || str.GetAt(i + 1) == '\n' || str.GetAt(i + 1) == '\r') {
				i++;
				continue;
			}
			p++;
			if (p == 3) {
				p = 0;
				n++;
				Graphnow.insertEdges(Graphnow.getIdx(MessageNode(-1, strTmp[0], TEXT(""))),
					Graphnow.getIdx(MessageNode(-1, strTmp[1], TEXT(""))),
					StrToInt(strTmp[2]));
				strTmp[0].Empty();
				strTmp[1].Empty();
				strTmp[2].Empty();
			}
		}
		else {
			strTmp[p] += str.GetAt(i);
		}
	}
	if (p) {
		n++;
		p = 0; 
		Graphnow.insertEdges(Graphnow.getIdx(MessageNode(-1, strTmp[0], TEXT(""))),
			Graphnow.getIdx(MessageNode(-1, strTmp[1], TEXT(""))),
			StrToInt(strTmp[2]));
	}
	Graphnow.M = n;

	CListCtrl &ctrl = nodeList.nodeList;
	ctrl.DeleteAllItems();
	CString tmp;
	for (int i = 0, realI = 0; i <= Graphnow.N; ++i) {
		if (Graphnow.Node[i].idx == -1) continue;
		tmp.Format("%d", Graphnow.Node[i].idx);
		ctrl.InsertItem(realI, tmp);
		ctrl.SetItemText(realI, 1, Graphnow.Node[i].name);
		ctrl.SetItemText(realI, 2, Graphnow.Node[i].desc);
		realI++;
	}
}

void CSpotInfomationManagerDlg::OnBnClickedButtonRefresh()
{
	// TODO: 在此添加控件通知处理程序代码
	RefreshInfo();
}


void CSpotInfomationManagerDlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	RefreshInfo();
	CString s1, s2, s3;
	MessageNode tmp;
	input_res1.GetWindowTextA(s1);
	input_res2.GetWindowTextA(s2);
	input_res3.GetWindowTextA(s3);
	int t1 = StrToInt(s1);
	int t2 = StrToInt(s2);
	int t3 = StrToInt(s3);
	switch (op_now)
	{
	case -1:
		MessageBox(TEXT("请选择一种操作"));
		break;
	case 0:
		tmp.idx = StrToInt(s1);
		tmp.name = s2;
		tmp.desc = s3;
		Graphnow.changeNode(tmp);
		break;
	case 1:
		tmp.idx = StrToInt(s1);
		tmp.name = s2;
		tmp.desc = s3;
		Graphnow.insertNode(tmp);
		break;
	case 2:
		Graphnow.deleteNode(t1);
		break;
	case 3:
		Graphnow.changeEdges(t1, t2, t3);
		break;
	case 4:
		Graphnow.insertEdges(t1, t2, t3);
		break;
	case 5:
		Graphnow.deleteEdges(t1, t2);
		break;
	}
	if (op_now != -1) {
		std::pair<CString, CString> res = Graphnow.toString();
		infoEditor.nodeInfoEditor.SetWindowTextA(res.first);
		infoEditor.edgeInfoEditor.SetWindowTextA(res.second);
		RefreshInfo();
	}
}


void CSpotInfomationManagerDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	input_res1.SetWindowTextA("");
	input_res2.SetWindowTextA("");
	input_res3.SetWindowTextA("");
}


void CSpotInfomationManagerDlg::OnCbnSelchangeCombo1()
{
	// TODO: 在此添加控件通知处理程序代码
	op_now = op_cbx.GetCurSel();
	input_text_1.ShowWindow(SW_SHOWNORMAL);
	input_text_2.ShowWindow(SW_SHOWNORMAL);
	input_text_3.ShowWindow(SW_SHOWNORMAL);
	input_res1.ShowWindow(SW_SHOWNORMAL);
	input_res2.ShowWindow(SW_SHOWNORMAL);
	input_res3.ShowWindow(SW_SHOWNORMAL);
	switch (op_now)
	{
	case -1:
		MessageBox(TEXT("请至少选择一种操作"));
		break;
	case 0:
		input_text_1.SetWindowTextA(TEXT("编号"));
		input_text_2.SetWindowTextA(TEXT("名称"));
		input_text_3.SetWindowTextA(TEXT("描述"));
		break;
	case 1:
		input_text_1.SetWindowTextA(TEXT("编号"));
		input_text_2.SetWindowTextA(TEXT("名称"));
		input_text_3.SetWindowTextA(TEXT("描述"));
		break;
	case 2:
		input_text_1.SetWindowTextA(TEXT("编号"));
		input_text_2.SetWindowTextA(TEXT("名称"));
		input_text_3.SetWindowTextA(TEXT("描述"));
		input_text_2.ShowWindow(SW_HIDE);
		input_res2.ShowWindow(SW_HIDE);
		input_text_3.ShowWindow(SW_HIDE);
		input_res3.ShowWindow(SW_HIDE);
		break;
	case 3:
		input_text_1.SetWindowTextA(TEXT("编号①"));
		input_text_2.SetWindowTextA(TEXT("编号②"));
		input_text_3.SetWindowTextA(TEXT("边长"));
		break;
	case 4:
		input_text_1.SetWindowTextA(TEXT("编号①"));
		input_text_2.SetWindowTextA(TEXT("编号②"));
		input_text_3.SetWindowTextA(TEXT("边长"));
		break;
	case 5:
		input_text_1.SetWindowTextA(TEXT("编号①"));
		input_text_2.SetWindowTextA(TEXT("编号②"));
		input_text_3.SetWindowTextA(TEXT("边长"));
		input_text_3.ShowWindow(SW_HIDE);
		input_res3.ShowWindow(SW_HIDE);
		break;
	}
}
