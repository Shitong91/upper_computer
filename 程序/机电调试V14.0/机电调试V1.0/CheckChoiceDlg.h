#pragma once


// CheckChoiceDlg 对话框

class CheckChoiceDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CheckChoiceDlg)

public:
	CheckChoiceDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CheckChoiceDlg();

// 对话框数据
	enum { IDD = IDD_CheckChoice_DIALOG  };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
private:
	int Selftest_Radio;
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedSelfcheckButton();
};
