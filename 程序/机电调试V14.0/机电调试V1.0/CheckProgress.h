#pragma once
#include "afxcmn.h"


// CCheckProgress 对话框

class CCheckProgress : public CDialogEx
{
	DECLARE_DYNAMIC(CCheckProgress)

public:
	CCheckProgress(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CCheckProgress();

// 对话框数据
	enum { IDD = IDD_DIALOG3 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	 CProgressCtrl m_Check_pro;
	//CProgressCtrl m_pp;
	 virtual BOOL OnInitDialog();
	 afx_msg void OnBnClickedButtonCheckfinish();
};
