#pragma once


// CLockedMotorDlg 对话框

class CLockedMotorDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CLockedMotorDlg)

public:
	CLockedMotorDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CLockedMotorDlg();

// 对话框数据
	enum { IDD = IDD_Locked_Motor_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedLockedFinishButton();
};
