// DlgShow.cpp: 实现文件
//

#include "stdafx.h"
#include "MFCApplication1.h"
#include "DlgShow.h"
#include "afxdialogex.h"


// DlgShow 对话框

IMPLEMENT_DYNAMIC(DlgShow, CDialogEx)

DlgShow::DlgShow(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_SHOW, pParent)
	, static_change_text(_T(""))
{

}

DlgShow::~DlgShow()
{
}

void DlgShow::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TEXT, TestNow);
	DDX_Control(pDX, IDC_PIC, img);
	DDX_Text(pDX, IDC_PIC, static_change_text);
	DDX_Control(pDX, IDC_COMBO1, combo_box);
}


BEGIN_MESSAGE_MAP(DlgShow, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &DlgShow::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &DlgShow::OnBnClickedButton2)
	ON_EN_CHANGE(IDC_EDIT1, &DlgShow::OnEnChangeEdit1)
	ON_CBN_SELCHANGE(IDC_COMBO1, &DlgShow::OnCbnSelchangeCombo1)
END_MESSAGE_MAP()


// DlgShow 消息处理程序


void DlgShow::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	TestNow.SetWindowTextW(TEXT("not so good"));
}

void DlgShow::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	CString str;
	TestNow.GetWindowTextW(str);
	MessageBox(str);
}



void DlgShow::OnEnChangeEdit1()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void DlgShow::OnOK()
{
	// TODO: 在此添加专用代码和/或调用基类

	//CDialogEx::OnOK();
}


void DlgShow::OnCbnSelchangeCombo1()
{
	// TODO: 在此添加控件通知处理程序代码
}
