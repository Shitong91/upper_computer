#pragma once
#include "afxcmn.h"


// Check_ProgresDlg 对话框

class Check_ProgresDlg : public CDialogEx
{
	DECLARE_DYNAMIC(Check_ProgresDlg)

public:
	Check_ProgresDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~Check_ProgresDlg();

// 对话框数据
	enum { IDD = IDD_DIALOG_Check_Progress };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	CProgressCtrl m_Check_pro;
	afx_msg void OnBnClickedButtonCheckfinish();
};
