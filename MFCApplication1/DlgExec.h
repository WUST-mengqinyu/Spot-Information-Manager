#pragma once


// DlgExec 对话框

class DlgExec : public CDialogEx
{
	DECLARE_DYNAMIC(DlgExec)

public:
	DlgExec(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~DlgExec();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_EXEC };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
