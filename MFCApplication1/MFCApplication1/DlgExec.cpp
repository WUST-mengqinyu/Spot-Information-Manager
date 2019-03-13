// DlgExec.cpp: 实现文件
//

#include "stdafx.h"
#include "MFCApplication1.h"
#include "DlgExec.h"
#include "afxdialogex.h"


// DlgExec 对话框

IMPLEMENT_DYNAMIC(DlgExec, CDialogEx)

DlgExec::DlgExec(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCAPPLICATION1_DIALOG, pParent)
{

}

DlgExec::~DlgExec()
{
}

void DlgExec::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(DlgExec, CDialogEx)
END_MESSAGE_MAP()


// DlgExec 消息处理程序
