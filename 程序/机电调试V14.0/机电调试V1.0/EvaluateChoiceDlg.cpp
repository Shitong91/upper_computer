// EvaluateChoiceDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "机电调试V1.0.h"
#include "EvaluateChoiceDlg.h"
#include "afxdialogex.h"


// CEvaluateChoiceDlg 对话框

IMPLEMENT_DYNAMIC(CEvaluateChoiceDlg, CDialogEx)

CEvaluateChoiceDlg::CEvaluateChoiceDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CEvaluateChoiceDlg::IDD, pParent)
	//, Motor_Evaluate_Radio(0)
	, Motor_Evaluate_Radio(0)
{

}

CEvaluateChoiceDlg::~CEvaluateChoiceDlg()
{
}

void CEvaluateChoiceDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Radio(pDX, IDC_Motor_Evaluate, Motor_Evaluate_Radio);
}


BEGIN_MESSAGE_MAP(CEvaluateChoiceDlg, CDialogEx)

	ON_BN_CLICKED(IDC_OK_BUTTON, &CEvaluateChoiceDlg::OnBnClickedOkButton)
END_MESSAGE_MAP()


// CEvaluateChoiceDlg 消息处理程序



BOOL CEvaluateChoiceDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	Motor_Evaluate_Radio=0;
	//((CButton *)GetDlgItem(IDC_Motor_Evaluate))->SetCheck(TRUE);
    UpdateData(false);

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}

//评估选择确认
void CEvaluateChoiceDlg::OnBnClickedOkButton()
{

    UpdateData(true);
	Evaluate_Mode_Choice = Motor_Evaluate_Radio;
	

	CDialogEx::OnCancel(); 

}
