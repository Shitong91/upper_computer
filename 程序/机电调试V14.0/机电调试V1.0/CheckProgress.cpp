// CheckProgress.cpp : 实现文件
//

#include "stdafx.h"
#include "机电调试V1.0.h"
#include "CheckProgress.h"
#include "afxdialogex.h"


// CCheckProgress 对话框

IMPLEMENT_DYNAMIC(CCheckProgress, CDialogEx)

CCheckProgress::CCheckProgress(CWnd* pParent /*=NULL*/)
	: CDialogEx(CCheckProgress::IDD, pParent)
{

}

CCheckProgress::~CCheckProgress()
{
}

void CCheckProgress::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_Check_Progress, m_Check_pro);
	//DDX_Control(pDX, IDC_Check_Progress, m_pp);
}


BEGIN_MESSAGE_MAP(CCheckProgress, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_CheckFinish, &CCheckProgress::OnBnClickedButtonCheckfinish)
END_MESSAGE_MAP()


// CCheckProgress 消息处理程序


BOOL CCheckProgress::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	for(int j=0;j<500;j++) //步进数500
	m_Check_pro.StepIt();

			

		for(int k=0;k<500;k++)//步进数500
			m_Check_pro.StepIt(); //进度条步进函数

		if(m_Check_pro.GetPos()==1000) //进度条步进到顶
		{
			jindu=1;
			CDialogEx::OnCancel();                     //开机自
		}
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}


void CCheckProgress::OnBnClickedButtonCheckfinish()
{
	// TODO: 在此添加控件通知处理程序代码
    CDialogEx::OnCancel();
}
