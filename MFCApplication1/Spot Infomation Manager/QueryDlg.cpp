// QueryDlg.cpp: 实现文件
//

#include "stdafx.h"
#include "Spot Infomation Manager.h"
#include "QueryDlg.h"
#include "afxdialogex.h"


// QueryDlg 对话框

IMPLEMENT_DYNAMIC(QueryDlg, CDialogEx)

QueryDlg::QueryDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_QUERY, pParent)
{

}

QueryDlg::~QueryDlg()
{
}

void QueryDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_DIJ_START, dij_start);
	DDX_Control(pDX, IDC_DIJ_END, dij_end);
	DDX_Control(pDX, IDC_DIJ_RES, dij_res);
	DDX_Control(pDX, IDC_MST_RES, mst_res);
	DDX_Control(pDX, IDC_DFS_RES, dfs_res);
	DDX_Control(pDX, IDC_DFS_START, dfs_start);
	DDX_Control(pDX, IDC_DFS_END, dfs_end);
	DDX_Control(pDX, IDC_DFS_START2, dfs_start2_text);
	DDX_Control(pDX, IDC_DFS_RES2, dfs_res2_text);
}


BEGIN_MESSAGE_MAP(QueryDlg, CDialogEx)
	ON_EN_CHANGE(IDC_DIJ_START, &QueryDlg::OnEnChangeDijStart)
	ON_BN_CLICKED(IDC_BUTTON_DIJ, &QueryDlg::OnBnClickedButtonDij)
	ON_BN_CLICKED(IDC_BUTTON_MST, &QueryDlg::OnBnClickedButtonMst)
	ON_BN_CLICKED(IDC_BUTTON3, &QueryDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &QueryDlg::OnBnClickedButton4)
END_MESSAGE_MAP()


// QueryDlg 消息处理程序


void QueryDlg::OnEnChangeDijStart()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}

int isNum(CString x) {
	int len = x.GetLength();
	int res = 0;
	for (int i = 0; i < len; ++i) {
		if (x.GetAt(i) <= '9' && x.GetAt(i) >= '0') {
			res *= 10;
			res += x.GetAt(i) - '0';
		}
		else {
			return -1;
		}
	}
	return res;
}

void QueryDlg::OnBnClickedButtonDij()
{
	CString ss, ee;
	dij_start.GetWindowTextA(ss);
	dij_end.GetWindowTextA(ee);
	int s = isNum(ss);
	int e = isNum(ee);
	s = graphnow.getIdx(MessageNode(-1, ss, ""));
	e = graphnow.getIdx(MessageNode(-1, ee, ""));
	if (s == -1 || e == -1) MessageBox(TEXT("无效或非法输入"));
	else {
		CString res = "", tmp;
		std::pair<std::vector<int>, int> rest = graphnow.distance(s, e);
		tmp.Format("最短总距离 %3d\r\n", rest.second);
		res += tmp;
		for (unsigned long j = 0; j < rest.first.size(); ++j) {
			int i = rest.first[j];
			tmp.Format("%s", i == e ? "" : "->");
			tmp = graphnow.Node[i].name + tmp;
			res += tmp;
		}
		dij_res.SetWindowTextA(res);
	}
	// TODO: 在此添加控件通知处理程序代码
}

void QueryDlg::setGraph(UnOrderedGraph _t)
{
	graphnow = _t;
}


void QueryDlg::OnBnClickedButtonMst()
{
	// TODO: 在此添加控件通知处理程序代码
	CString ss, tmp;
	std::pair<std::vector<IntEdge>, int> rest = graphnow.MST();
	tmp.Format("最短总距离 %3d\r\n", rest.second);
	ss += tmp;
	for (auto i : rest.first) {
		tmp.Format("%d", i.w);
		tmp = graphnow.Node[i.u].name + TEXT(" ") + graphnow.Node[i.v].name + " " + tmp + "\r\n";
		ss += tmp;
	}
	mst_res.SetWindowTextA(ss);
}


void QueryDlg::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码
	CString ss, ee;
	dfs_start.GetWindowTextA(ss);
	dfs_end.GetWindowTextA(ee);
	int s, e;
	s = graphnow.getIdx(MessageNode(-1, ss, ""));
	e = graphnow.getIdx(MessageNode(-1, ee, ""));
	if (s == -1 || e == -1) MessageBox(TEXT("无效或非法输入"));
	std::vector<std::vector<int> > rest = graphnow.dfs(s, e);
	CString res, tmp;
	res.Format("共 %3d 种方案\r\n", rest.size());
	for (auto t : rest) {
		tmp.Empty();
		for (int i = 0; i < t.size(); ++i) {
			if (i != 0) tmp += TEXT("->");
			tmp += graphnow.Node[t[i]].name;
		}
		res += tmp + TEXT("\r\n");
	}
	dfs_res.SetWindowTextA(res);
}


void QueryDlg::OnBnClickedButton4()
{
	// TODO: 在此添加控件通知处理程序代码
	CString ss;
	dfs_start2_text.GetWindowTextA(ss);
	int s;
	s = graphnow.getIdx(MessageNode(-1, ss, ""));
	if (s == -1) MessageBox(TEXT("无效或非法输入"));
	std::vector<std::vector<int> > rest = graphnow.dfs2(s);
	CString res, tmp;
	res.Format("共 %3d 种方案\r\n", rest.size());
	for (auto t : rest) {
		tmp.Empty();
		for (int i = 0; i < t.size(); ++i) {
			if (i != 0) tmp += TEXT("->");
			tmp += graphnow.Node[t[i]].name;
		}
		res += tmp + TEXT("\r\n");
	}
	dfs_res2_text.SetWindowTextA(res);
}
