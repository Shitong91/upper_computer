#pragma once


// CModeChoiceDlg 对话框

class CModeChoiceDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CModeChoiceDlg)

public:
	CModeChoiceDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CModeChoiceDlg();

// 对话框数据
	enum { IDD = IDD_ModeChoice_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	int Motor_Radio;
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedModeOkButton();
};
