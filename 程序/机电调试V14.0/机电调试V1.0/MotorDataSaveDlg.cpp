// MotorDataSaveDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "机电调试V1.0.h"
#include "MotorDataSaveDlg.h"
#include "afxdialogex.h"


// CMotorDataSaveDlg 对话框

IMPLEMENT_DYNAMIC(CMotorDataSaveDlg, CDialogEx)

CMotorDataSaveDlg::CMotorDataSaveDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMotorDataSaveDlg::IDD, pParent)
{

}

CMotorDataSaveDlg::~CMotorDataSaveDlg()
{
}

void CMotorDataSaveDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CMotorDataSaveDlg, CDialogEx)
	ON_BN_CLICKED(IDC_Save_OK_BUTTON, &CMotorDataSaveDlg::OnBnClickedSaveOkButton)
	ON_BN_CLICKED(IDC_Save_NO_BUTTON, &CMotorDataSaveDlg::OnBnClickedSaveNoButton)
	ON_BN_CLICKED(IDOK, &CMotorDataSaveDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// CMotorDataSaveDlg 消息处理程序


void CMotorDataSaveDlg::OnBnClickedSaveOkButton()
{
	// TODO: 在此添加控件通知处理程序代码

CDialogEx::OnOK(); 

}


void CMotorDataSaveDlg::OnBnClickedSaveNoButton()
{
	// TODO: 在此添加控件通知处理程序代码
}


void CMotorDataSaveDlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnOK();
}
