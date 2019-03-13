#pragma once

// InfoEditor 对话框

class InfoEditor : public CDialogEx
{
	DECLARE_DYNAMIC(InfoEditor)

public:
	InfoEditor(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~InfoEditor();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_EDIT };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	//const CString files = TEXT("Text File(*.txt)\0*.txt\0");
	const CString openFile = TEXT("Open File");
	const CString saveFile = TEXT("Save File");
	const CString files = TEXT("");
	CEdit nodeInfoEditor;
	CEdit edgeInfoEditor;
	CString nodeFilePath, edgeFilePath;
	//直接的节点和边信息，由回车符分隔
	CString nodeInfo, edgeInfo;
	afx_msg void OnBnClickedButtonOpenFile();
	afx_msg void OnBnClickedButtonOpenFile2();
	afx_msg void OnBnClickedButtonSave();
	afx_msg void OnBnClickedButtonSave2();
	void update();
};
