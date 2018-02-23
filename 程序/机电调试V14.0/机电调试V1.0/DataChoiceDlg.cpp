// DataChoiceDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "机电调试V1.0.h"
#include "DataChoiceDlg.h"
#include "afxdialogex.h"
#include "LockedMotorDlg.h"
#include "LockedDataDlg.h"
// CDataChoiceDlg 对话框

IMPLEMENT_DYNAMIC(CDataChoiceDlg, CDialogEx)

CDataChoiceDlg::CDataChoiceDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDataChoiceDlg::IDD, pParent)
{

}

CDataChoiceDlg::~CDataChoiceDlg()
{
}

void CDataChoiceDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDataChoiceDlg, CDialogEx)
	ON_BN_CLICKED(IDC_This_Data_BUTTON, &CDataChoiceDlg::OnBnClickedThisDataButton)
	ON_BN_CLICKED(IDC_Last_Data_BUTTON, &CDataChoiceDlg::OnBnClickedLastDataButton)
END_MESSAGE_MAP()


// CDataChoiceDlg 消息处理程序


void CDataChoiceDlg::OnBnClickedThisDataButton()
{
	// TODO: 在此添加控件通知处理程序代码
		 
	 CLockedMotorDlg ClickedThisDlg;
	 ClickedThisDlg.DoModal(); 
    CDialogEx::OnCancel(); 

}


void CDataChoiceDlg::OnBnClickedLastDataButton()
{
	// TODO: 在此添加控件通知处理程序代码

	 CLockedDataDlg CLockedThisDlg;
	 CLockedThisDlg.DoModal(); 


	 CDialogEx::OnCancel(); 
}
