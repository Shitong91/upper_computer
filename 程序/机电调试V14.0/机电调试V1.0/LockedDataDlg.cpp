// LockedDataDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "机电调试V1.0.h"
#include "LockedDataDlg.h"
#include "afxdialogex.h"
#include "GotoNormalTipDlg.h"

// CLockedDataDlg 对话框

IMPLEMENT_DYNAMIC(CLockedDataDlg, CDialogEx)

CLockedDataDlg::CLockedDataDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CLockedDataDlg::IDD, pParent)
	, m_Edit_Locked_vol(0)
	, m_Edit_Locked_Cur(0)
	, m_Edit_Motor_Res(0)
{

}

CLockedDataDlg::~CLockedDataDlg()
{
}

void CLockedDataDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_Locked_Voltage_EDIT, m_Edit_Locked_vol);
	DDX_Text(pDX, IDC_Locked_Current_EDIT, m_Edit_Locked_Cur);
	DDX_Text(pDX, IDC_Motor_Resist_EDIT, m_Edit_Motor_Res);
}


BEGIN_MESSAGE_MAP(CLockedDataDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &CLockedDataDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// CLockedDataDlg 消息处理程序


BOOL CLockedDataDlg::OnInitDialog() //自动调用上次存储的堵转数据
{
	CDialogEx::OnInitDialog();

	
	
	
//	ShellExecute(NULL, _T("open"), _T("堵转初始化数据.txt"), NULL, NULL, SW_SHOW);
	
	CStdioFile file;
	file.Open(L"堵转初始化数据.txt",CFile::modeRead);
	CString strLine,strBuffer1,strBuffer2,strBuffer3;
	int i=0;
	//double freq[100];
	//double val[100];
	for(int j=0;j<1;j++)
    file.ReadString(strLine);//MS这里得跳两行
  while(file.ReadString(strLine))
	{
	
	  i++;
		int nHeadPos = strLine.Find(_T(" "));//找帧头
		if(i==1)
		strBuffer1=strLine.Mid(nHeadPos+3,8);
		if(i==2)
        strBuffer2=strLine.Mid(nHeadPos+3,8);
		if(i==3)
        strBuffer3=strLine.Mid(nHeadPos+3,8);
      
      
	}
    GetDlgItem(IDC_Locked_Voltage_EDIT)->SetWindowText(strBuffer1); //指向控件的caption
    GetDlgItem(IDC_Locked_Current_EDIT)->SetWindowText(strBuffer2); //指向控件的caption
    GetDlgItem(IDC_Motor_Resist_EDIT)->SetWindowText(strBuffer3); //指向控件的caption
    UpdateData(true);  
//h2;//改变按钮名称为打开串口double m_Edit_Locked_vol;
	double m_Edit_Locked_Cur = 0.0;
	double m_Edit_Motor_Res = 0.0;
	 Motor_locked_Vol= m_Edit_Locked_vol;//电机电压
     Motor_locked_Cur= m_Edit_Locked_Cur;//电机电流
     Motor_locked_Res=m_Edit_Motor_Res;//堵转电机电阻

	//file.Close();

	// UpdateData(false);

	
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}


void CLockedDataDlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	Motor_locked_Vol= m_Edit_Locked_vol;//电机电压
    Motor_locked_Cur= m_Edit_Locked_Cur;//电机电流
    Motor_locked_Res=m_Edit_Motor_Res;//堵转电机电阻
	
	CGotoNormalTipDlg  NormalTip;
	
	INT_PTR nRes=NormalTip.DoModal();
	Motor_Resfinish_flg=1;		
	if(nRes==IDOK)
	{	 
		CDialogEx::OnCancel();
	}
		
}
