// Exec.cpp: 实现文件
//

#include "stdafx.h"
#include "MFCApplication1.h"
#include "Exec.h"
#include "afxdialogex.h"


// Exec 对话框

IMPLEMENT_DYNAMIC(Exec, CDialogEx)

Exec::Exec(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_EXEC, pParent)
{

}

Exec::~Exec()
{
}

void Exec::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(Exec, CDialogEx)
END_MESSAGE_MAP()


// Exec 消息处理程序
