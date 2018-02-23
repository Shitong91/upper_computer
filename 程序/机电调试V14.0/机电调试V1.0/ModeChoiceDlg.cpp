// ModeChoiceDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "机电调试V1.0.h"
#include "ModeChoiceDlg.h"
#include "afxdialogex.h"


// CModeChoiceDlg 对话框

IMPLEMENT_DYNAMIC(CModeChoiceDlg, CDialogEx)

CModeChoiceDlg::CModeChoiceDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CModeChoiceDlg::IDD, pParent)
	, Motor_Radio(0)
{

}

CModeChoiceDlg::~CModeChoiceDlg()
{
}

void CModeChoiceDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Radio(pDX, IDC_Motor_Init_RADIO, Motor_Radio);
}


BEGIN_MESSAGE_MAP(CModeChoiceDlg, CDialogEx)
	ON_BN_CLICKED(IDC_Mode_OK_BUTTON, &CModeChoiceDlg::OnBnClickedModeOkButton)
END_MESSAGE_MAP()


// CModeChoiceDlg 消息处理程序


BOOL CModeChoiceDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	Motor_Radio=1;
    UpdateData(false);
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}


void CModeChoiceDlg::OnBnClickedModeOkButton()
{
	// TODO: 在此添加控件通知处理程序代码
   UpdateData(true);
	mode_choice=Motor_Radio;
	CDialogEx::OnCancel(); 
}
