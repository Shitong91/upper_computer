#pragma once


// CCheckSelfChoiceDlg 对话框

class CCheckSelfChoiceDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CCheckSelfChoiceDlg)

public:
	CCheckSelfChoiceDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CCheckSelfChoiceDlg();

// 对话框数据
	enum { IDD = IDD_CheckSelfChoice_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
