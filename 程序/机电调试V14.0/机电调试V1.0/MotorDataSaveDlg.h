#pragma once


// CMotorDataSaveDlg 对话框

class CMotorDataSaveDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CMotorDataSaveDlg)

public:
	CMotorDataSaveDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CMotorDataSaveDlg();

// 对话框数据
	enum { IDD = IDD_MotorData_Save_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedSaveOkButton();
	afx_msg void OnBnClickedSaveNoButton();
	afx_msg void OnBnClickedOk();
};
