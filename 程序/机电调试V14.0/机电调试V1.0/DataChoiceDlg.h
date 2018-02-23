#pragma once


// CDataChoiceDlg 对话框

class CDataChoiceDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CDataChoiceDlg)

public:
	CDataChoiceDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CDataChoiceDlg();

// 对话框数据
	enum { IDD = IDD_DataChoice_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedThisDataButton();
	afx_msg void OnBnClickedLastDataButton();
};
