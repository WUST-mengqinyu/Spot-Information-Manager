#pragma once


// List 对话框

class List : public CDialogEx
{
	DECLARE_DYNAMIC(List)

public:
	List(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~List();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_LIST };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CListCtrl ListWnd;
};
