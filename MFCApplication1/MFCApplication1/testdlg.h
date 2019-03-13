#pragma once


// testdlg 对话框

class testdlg : public CDialogEx
{
	DECLARE_DYNAMIC(testdlg)

public:
	testdlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~testdlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CListCtrl listtest;
};
