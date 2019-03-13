#pragma once


// QueryDlg 对话框
#include "UnOrderedGraph.h"

class QueryDlg : public CDialogEx
{
	DECLARE_DYNAMIC(QueryDlg)
	UnOrderedGraph graphnow;

public:
	QueryDlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~QueryDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_QUERY };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEnChangeDijStart();
	CEdit dij_start;
	CEdit dij_end;
	CEdit dij_res;
	afx_msg void OnBnClickedButtonDij();
	void setGraph(UnOrderedGraph _t);
	afx_msg void OnBnClickedButtonMst();
	CEdit mst_res;
	CEdit dfs_res;
	CEdit dfs_start;
	CEdit dfs_end;
	afx_msg void OnBnClickedButton3();
	CEdit dfs_start2_text;
	CEdit dfs_res2_text;
	afx_msg void OnBnClickedButton4();
};
