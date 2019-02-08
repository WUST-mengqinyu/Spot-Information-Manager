#pragma once


// DlgShow 对话框

class DlgShow : public CDialogEx
{
	DECLARE_DYNAMIC(DlgShow)

public:
	DlgShow(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~DlgShow();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SHOW };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
private:
	CStatic TestNow;
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	CStatic img;
	afx_msg void OnEnChangeEdit1();
	virtual void OnOK();
	CString static_change_text;
	afx_msg void OnCbnSelchangeCombo1();
	CComboBox combo_box;
};
