
// Spot Infomation ManagerDlg.h: 头文件
//

#pragma once

#include "InfoEditor.h"
#include "NodeList.h"
#include "QueryDlg.h"
#include <vector>

// CSpotInfomationManagerDlg 对话框
class CSpotInfomationManagerDlg : public CDialogEx
{
// 构造
public:
	CSpotInfomationManagerDlg(CWnd* pParent = nullptr);	// 标准构造函数
	UnOrderedGraph Graphnow = UnOrderedGraph();
	int op_now;

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SPOTINFOMATIONMANAGER_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CTabCtrl tabCtrl;
	InfoEditor infoEditor;
	NodeList nodeList;
	QueryDlg queryDlg;
	afx_msg void OnTcnSelchangeTab1(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnStnClickedInput2();
	afx_msg void OnStnClickedInput1();
	afx_msg void OnBnClickedButtonQuery();
	void RefreshInfo();
	afx_msg void OnBnClickedButtonRefresh();
	CComboBox op_cbx;
	CStatic input_text_1;
	CStatic input_text_2;
	CStatic input_text_3;
	CEdit input_res1;
	CEdit input_res2;
	CEdit input_res3;
	CButton op_btn;
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnCbnSelchangeCombo1();
};
