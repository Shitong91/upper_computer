#pragma once


// CEvaluateChoiceDlg 对话框

class CEvaluateChoiceDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CEvaluateChoiceDlg)

public:
	CEvaluateChoiceDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CEvaluateChoiceDlg();

// 对话框数据
	enum { IDD = IDD_Evaluate_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	//int Motor_Evaluate_Radio;

	afx_msg void OnBnClickedOkButton();
	int Motor_Evaluate_Radio;
};
