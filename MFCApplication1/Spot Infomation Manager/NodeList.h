#pragma once


// NodeList 对话框

class NodeList : public CDialogEx
{
	DECLARE_DYNAMIC(NodeList)

public:
	NodeList(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~NodeList();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_NODE_INFO };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	// listCtrl of nodes
	CListCtrl nodeList;
	afx_msg void OnLvnItemchangedList(NMHDR *pNMHDR, LRESULT *pResult);
};
