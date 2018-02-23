#pragma once


// CLockedDataDlg 对话框

class CLockedDataDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CLockedDataDlg)

public:
	CLockedDataDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CLockedDataDlg();

// 对话框数据
	enum { IDD = IDD_Locked_Data_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	double m_Edit_Locked_vol;
	double m_Edit_Locked_Cur;
	double m_Edit_Motor_Res;
	//afx_msg void OnBnClickedUseDataButton();
	afx_msg void OnBnClickedOk();
};
