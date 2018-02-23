#pragma once


// Check_ProgressDlg 对话框

class Check_ProgressDlg : public CDialogEx
{
	DECLARE_DYNAMIC(Check_ProgressDlg)

public:
	Check_ProgressDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~Check_ProgressDlg();

// 对话框数据
	enum { IDD = IDD_DIALOG3 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
};
