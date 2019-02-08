// testdlg.cpp: 实现文件
//

#include "stdafx.h"
#include "MFCApplication1.h"
#include "testdlg.h"
#include "afxdialogex.h"


// testdlg 对话框

IMPLEMENT_DYNAMIC(testdlg, CDialogEx)

testdlg::testdlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG1, pParent)
{

}

testdlg::~testdlg()
{
}

void testdlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, listtest);
}


BEGIN_MESSAGE_MAP(testdlg, CDialogEx)
END_MESSAGE_MAP()


// testdlg 消息处理程序
