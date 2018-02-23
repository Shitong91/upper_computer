// GotoNormalTipDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "机电调试V1.0.h"
#include "GotoNormalTipDlg.h"
#include "afxdialogex.h"


// CGotoNormalTipDlg 对话框

IMPLEMENT_DYNAMIC(CGotoNormalTipDlg, CDialogEx)

CGotoNormalTipDlg::CGotoNormalTipDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CGotoNormalTipDlg::IDD, pParent)
{

}

CGotoNormalTipDlg::~CGotoNormalTipDlg()
{
}

void CGotoNormalTipDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CGotoNormalTipDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &CGotoNormalTipDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// CGotoNormalTipDlg 消息处理程序


void CGotoNormalTipDlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnOK();
}
