#pragma once


// Exec 对话框

class Exec : public CDialogEx
{
	DECLARE_DYNAMIC(Exec)

public:
	Exec(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~Exec();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_EXEC };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
