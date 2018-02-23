// Check_ProgressDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "机电调试V1.0.h"
#include "Check_ProgressDlg.h"
#include "afxdialogex.h"


// Check_ProgressDlg 对话框

IMPLEMENT_DYNAMIC(Check_ProgressDlg, CDialogEx)

Check_ProgressDlg::Check_ProgressDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(Check_ProgressDlg::IDD, pParent)
{

}

Check_ProgressDlg::~Check_ProgressDlg()
{
}

void Check_ProgressDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(Check_ProgressDlg, CDialogEx)
END_MESSAGE_MAP()


// Check_ProgressDlg 消息处理程序


BOOL Check_ProgressDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}
