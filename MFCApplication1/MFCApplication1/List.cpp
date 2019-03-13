// List.cpp: 实现文件
//

#include "stdafx.h"
#include "MFCApplication1.h"
#include "List.h"
#include "afxdialogex.h"


// List 对话框

IMPLEMENT_DYNAMIC(List, CDialogEx)

List::List(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_LIST, pParent)
{

}

List::~List()
{
}

void List::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, LIST, ListWnd);
}


BEGIN_MESSAGE_MAP(List, CDialogEx)
END_MESSAGE_MAP()


// List 消息处理程序
