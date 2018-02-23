#pragma once
#include "afxcmn.h"
#include "afxwin.h"
#include "tchart1.h"



// Angle_Evalu_list 对话框

class Angle_Evalu_list : public CDialogEx
{
	DECLARE_DYNAMIC(Angle_Evalu_list)

public:
	Angle_Evalu_list(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~Angle_Evalu_list();

// 对话框数据
	enum { IDD = IDD_Evaluate_List_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CListCtrl Angle_list;
	virtual BOOL OnInitDialog();
	afx_msg void OnNMClickAngleList(NMHDR *pNMHDR, LRESULT *pResult);
	CEdit m_Angle_list;
	afx_msg void OnEnKillfocusEdit2();
	afx_msg void OnBnClickedStartButton();
	afx_msg void OnBnClickedbiaButton();
	


	CTchart1 m_Tchart_Angle;
};
