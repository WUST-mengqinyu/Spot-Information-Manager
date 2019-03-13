// InfoEditor.cpp: 实现文件
//

#include "stdafx.h"
#include "Spot Infomation Manager.h"
#include "InfoEditor.h"
#include "afxdialogex.h"


// InfoEditor 对话框

IMPLEMENT_DYNAMIC(InfoEditor, CDialogEx)

InfoEditor::InfoEditor(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_EDIT, pParent)
{

}

InfoEditor::~InfoEditor()
{
}

void InfoEditor::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, nodeInfoEditor);
	DDX_Control(pDX, IDC_EDIT2, edgeInfoEditor);
}


BEGIN_MESSAGE_MAP(InfoEditor, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_OPEN_FILE, &InfoEditor::OnBnClickedButtonOpenFile)
	ON_BN_CLICKED(IDC_BUTTON_OPEN_FILE2, &InfoEditor::OnBnClickedButtonOpenFile2)
	ON_BN_CLICKED(IDC_BUTTON_SAVE, &InfoEditor::OnBnClickedButtonSave)
	ON_BN_CLICKED(IDC_BUTTON_SAVE2, &InfoEditor::OnBnClickedButtonSave2)
END_MESSAGE_MAP()


// InfoEditor 消息处理程序

void InfoEditor::OnBnClickedButtonOpenFile()
{
	// TODO: 在此添加控件通知处理程序代码
	CFileDialog OpenDlg(TRUE);
	OpenDlg.m_ofn.lpstrTitle = openFile;
	OpenDlg.m_ofn.lpstrFilter = files;

	if (IDOK == OpenDlg.DoModal())
	{
		CStdioFile File;
		CFileException e;
		//构造文件，同时增加异常处理
		nodeFilePath = OpenDlg.GetPathName();
		if (!File.Open(nodeFilePath, CFile::modeRead, &e))
		{
			CString strErr;
			strErr.Format(_T("File could not be opened %d\n"), e.m_cause);
			MessageBox(strErr);
		}

		CString ss, tmp;

		while (File.ReadString(tmp))
		{
			tmp += TEXT("\r\n");
			ss += tmp;
		}
		File.Close();
		nodeInfoEditor.SetWindowTextA(ss);
		nodeInfo = ss;
	}
}


void InfoEditor::OnBnClickedButtonOpenFile2()
{
	// TODO: 在此添加控件通知处理程序代码
	CFileDialog OpenDlg(TRUE);
	OpenDlg.m_ofn.lpstrTitle = openFile;
	OpenDlg.m_ofn.lpstrFilter = files;

	if (IDOK == OpenDlg.DoModal())
	{
		CStdioFile File;
		CFileException e;
		//构造文件，同时增加异常处理
		edgeFilePath = OpenDlg.GetPathName();
		if (!File.Open(edgeFilePath, CFile::modeRead, &e))
		{
			CString strErr;
			strErr.Format(_T("File could not be opened %d\n"), e.m_cause);
			MessageBox(strErr);
		}

		CString ss, tmp;

		while (File.ReadString(tmp))
		{
			tmp += TEXT("\r\n");
			ss += tmp;
		}
		File.Close();
		edgeInfoEditor.SetWindowTextA(ss);
		edgeInfo = ss;
	}
}

void InfoEditor::OnBnClickedButtonSave()
{
	// TODO: 在此添加控件通知处理程序代码
	CString ss;
	nodeInfoEditor.GetWindowTextA(ss);

	nodeInfo = ss;

	if (nodeFilePath.IsEmpty()) {
		CFileDialog OpenDlg(FALSE);
		OpenDlg.m_ofn.lpstrTitle = saveFile;
		OpenDlg.m_ofn.lpstrFilter = files;

		if (IDOK == OpenDlg.DoModal())
		{
			CStdioFile File;
			CFileException e;
			//构造文件，同时增加异常处理
			nodeFilePath = OpenDlg.GetPathName();
			if (!File.Open(nodeFilePath, CFile::modeCreate | CFile::modeWrite, &e))
			{
				CString strErr;
				strErr.Format(_T("File could not be opened %d\n"), e.m_cause);
				MessageBox(strErr);
			}
			File.Write(ss, ss.GetLength());
			File.Close();
		}
	} else {
		CStdioFile File;
		CFileException e;
		//构造文件，同时增加异常处理
		if (!File.Open(nodeFilePath, CFile::modeCreate | CFile::modeWrite, &e))
		{
			CString strErr;
			strErr.Format(_T("File could not be opened %d\n"), e.m_cause);
			MessageBox(strErr);
		}
		File.Write(ss, ss.GetLength());
		File.Close();
	}
}


void InfoEditor::OnBnClickedButtonSave2()
{	
	// TODO: 在此添加控件通知处理程序代码
	CString ss;
	edgeInfoEditor.GetWindowTextA(ss);

	edgeInfo = ss;

	if (edgeFilePath.IsEmpty()) {
		CFileDialog OpenDlg(FALSE);
		OpenDlg.m_ofn.lpstrTitle = saveFile;
		OpenDlg.m_ofn.lpstrFilter = files;

		if (IDOK == OpenDlg.DoModal())
		{
			CStdioFile File;
			CFileException e;
			//构造文件，同时增加异常处理
			edgeFilePath = OpenDlg.GetPathName();
			if (!File.Open(edgeFilePath, CFile::modeCreate | CFile::modeWrite, &e))
			{
				CString strErr;
				strErr.Format(_T("File could not be opened %d\n"), e.m_cause);
				MessageBox(strErr);
			}
			File.Write(ss, ss.GetLength());
			File.Close();
		}
	}
	else {
		CStdioFile File;
		CFileException e;
		//构造文件，同时增加异常处理
		if (!File.Open(edgeFilePath, CFile::modeCreate | CFile::modeWrite, &e))
		{
			CString strErr;
			strErr.Format(_T("File could not be opened %d\n"), e.m_cause);
			MessageBox(strErr);
		}
		File.Write(ss, ss.GetLength());
		File.Close();
	}
}

void InfoEditor::update()
{
	CString ss;
	edgeInfoEditor.GetWindowTextA(ss);
	edgeInfo = ss;
	nodeInfoEditor.GetWindowTextA(ss);
	nodeInfo = ss;
}
