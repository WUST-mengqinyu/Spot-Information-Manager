// NodeList.cpp: 实现文件
//

#include "stdafx.h"
#include "Spot Infomation Manager.h"
#include "NodeList.h"
#include "afxdialogex.h"


// NodeList 对话框

IMPLEMENT_DYNAMIC(NodeList, CDialogEx)

NodeList::NodeList(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_NODE_INFO, pParent)
{

}

NodeList::~NodeList()
{
}

void NodeList::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, NODE_LIST, nodeList);
}


BEGIN_MESSAGE_MAP(NodeList, CDialogEx)
END_MESSAGE_MAP()


// NodeList 消息处理程序
