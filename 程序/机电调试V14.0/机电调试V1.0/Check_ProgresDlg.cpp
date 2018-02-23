// Check_ProgresDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "机电调试V1.0.h"
#include "Check_ProgresDlg.h"
#include "afxdialogex.h"


// Check_ProgresDlg 对话框

IMPLEMENT_DYNAMIC(Check_ProgresDlg, CDialogEx)

Check_ProgresDlg::Check_ProgresDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(Check_ProgresDlg::IDD, pParent)
{

}

Check_ProgresDlg::~Check_ProgresDlg()
{
}

void Check_ProgresDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_Check_Progress, m_Check_pro);
}


BEGIN_MESSAGE_MAP(Check_ProgresDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_CheckFinish, &Check_ProgresDlg::OnBnClickedButtonCheckfinish)
END_MESSAGE_MAP()


// Check_ProgresDlg 消息处理程序


BOOL Check_ProgresDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
    m_Check_pro.SetRange(0,1000);
    m_Check_pro.SetStep(1);
	// TODO:  在此添加额外的初始化
 if(jindu==0)
{   
	for(int j=0;j<500;j++) //步进数500
	m_Check_pro.StepIt();

			

		for(int k=0;k<500;k++)//步进数500
			m_Check_pro.StepIt(); //进度条步进函数
	//	jindu=1;
		if(m_Check_pro.GetPos()==1000) //进度条步进到顶
		{
			jindu=1;
			//CDialogEx::OnCancel();                     //开机自
		}
 }
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}


void Check_ProgresDlg::OnBnClickedButtonCheckfinish()
{
	// TODO: 在此添加控件通知处理程序代码
	   CDialogEx::OnCancel();  
}
