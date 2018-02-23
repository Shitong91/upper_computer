#pragma once


// CCopyRightDlg 对话框

class CCopyRightDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CCopyRightDlg)

public:
	CCopyRightDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CCopyRightDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
