// LockedMotorDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "机电调试V1.0.h"
#include "LockedMotorDlg.h"
#include "afxdialogex.h"


// CLockedMotorDlg 对话框

IMPLEMENT_DYNAMIC(CLockedMotorDlg, CDialogEx)

CLockedMotorDlg::CLockedMotorDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CLockedMotorDlg::IDD, pParent)
{

}

CLockedMotorDlg::~CLockedMotorDlg()
{
}

void CLockedMotorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CLockedMotorDlg, CDialogEx)
	ON_BN_CLICKED(IDC_Locked_Finish_BUTTON, &CLockedMotorDlg::OnBnClickedLockedFinishButton)
END_MESSAGE_MAP()


// CLockedMotorDlg 消息处理程序


void CLockedMotorDlg::OnBnClickedLockedFinishButton()
{
	// TODO: 在此添加控件通知处理程序代码
	
	CDialogEx::OnCancel();


}
