// CheckChoiceDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "机电调试V1.0.h"
#include "CheckChoiceDlg.h"
#include "afxdialogex.h"


// CheckChoiceDlg 对话框

IMPLEMENT_DYNAMIC(CheckChoiceDlg, CDialogEx)

CheckChoiceDlg::CheckChoiceDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CheckChoiceDlg::IDD, pParent)
	, Selftest_Radio(0)
{

}

CheckChoiceDlg::~CheckChoiceDlg()
{
}

void CheckChoiceDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Radio(pDX, IDC_Check_Moto_RADIO, Selftest_Radio);
}


BEGIN_MESSAGE_MAP(CheckChoiceDlg, CDialogEx)
	ON_BN_CLICKED(IDC_SelfCheck_BUTTON, &CheckChoiceDlg::OnBnClickedSelfcheckButton)
END_MESSAGE_MAP()


// CheckChoiceDlg 消息处理程序


BOOL CheckChoiceDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	Selftest_Radio=0;            //初始化状态下，电机圆感应自检状态
    UpdateData(false);
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}


void CheckChoiceDlg::OnBnClickedSelfcheckButton()
{
	// TODO: 在此添加控件通知处理程序代码
	 UpdateData(true);
	Selftest_choice=Selftest_Radio;
	CDialogEx::OnCancel(); 
}
