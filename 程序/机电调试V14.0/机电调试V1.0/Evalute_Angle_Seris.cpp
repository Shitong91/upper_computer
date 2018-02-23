// Evalute_Angle_Seris.cpp : 实现文件
//

#include "stdafx.h"
#include "机电调试V1.0.h"
#include "Evalute_Angle_Seris.h"
#include "afxdialogex.h"
#include "CTChart.h"
#include "tchart1.h"
#include "CPanel.h"
#include "CGradient.h"
#include "CSeries.h"
#include "CAxes.h"
#include "CAxis.h"
#include "CScroll.h"


// Evalute_Angle_Seris 对话框
double max6=0.0;
IMPLEMENT_DYNAMIC(Evalute_Angle_Seris, CDialogEx)

Evalute_Angle_Seris::Evalute_Angle_Seris(CWnd* pParent /*=NULL*/)
	: CDialogEx(Evalute_Angle_Seris::IDD, pParent)

	, yuzhi(0)
{

}

Evalute_Angle_Seris::~Evalute_Angle_Seris()
{
}

void Evalute_Angle_Seris::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TCHART1, m_chart_EvaluteAngle);
	DDX_Text(pDX, IDC_EDIT_Yuzhi, yuzhi);
	DDX_Control(pDX, IDC_EDIT_Yuzhi, Edit_yuzhi);
}


BEGIN_MESSAGE_MAP(Evalute_Angle_Seris, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_EvaluteStart, &Evalute_Angle_Seris::OnBnClickedButtonEvalutestart)
//	ON_BN_CLICKED(IDC_BUTTON2, &Evalute_Angle_Seris::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON_Yuzhi, &Evalute_Angle_Seris::OnBnClickedButtonYuzhi)
END_MESSAGE_MAP()


// Evalute_Angle_Seris 消息处理程序


BOOL Evalute_Angle_Seris::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	

	// TODO:  在此添加额外的初始化
((CGradient)((CPanel)m_chart_EvaluteAngle.get_Panel()).get_Gradient()).put_Visible(0);
  max6=0.0;
	
	return TRUE;  // return TRUE unless you set the focus to a control

	// 异常: OCX 属性页应返回 FALSE
}
 double yuzhi1=0.0;

void Evalute_Angle_Seris::OnBnClickedButtonEvalutestart()
{
	// TODO: 在此添加控件通知处理程序代码
	CWnd *h,*h2;
	double bia_sum,bia_aver;
	 CString bia_aver_Str;
	h=GetDlgItem(IDC_Evaluate_Result_STATIC);
	h2=GetDlgItem(IDC_Bia_Average_STATIC);
    CString str_Evaluate_Result=_T(" "); 
	CSeries lineSeries = (CSeries) m_chart_EvaluteAngle.Series(0);
    lineSeries.Clear();
	for(int i=0; i<8; i++)  
	 {
		 lineSeries.AddXY(Ang_Cacul[i][1],bia[i], NULL, RGB(255,0,255));
		// bia_sum+=bia[i];
		 if(bia[i]<0)
           bia[i]=- bia[i];
	 }
	//  bia_aver=bia_sum/ 8.0;
	for(int j=0;j<8;j++)
		{
			 //通道采集并得到通道的MV值
			if(max6<=bia[j]){max6=bia[j];} //求出最大值
		//	if(min6>=bia[i]){min6=bia[i];} //求出最小值
		              
		}
	  bia_aver_Str.Format(_T("%f"), max6);
	 // UpdateData(true);  
	h2->SetWindowText(bia_aver_Str);
	 // UpdateData(false);
	UpdateData(true);  
	  if(max6< yuzhi1)
     { str_Evaluate_Result=_T("合格");
	  h->SetWindowText(str_Evaluate_Result);//
	   UpdateData(true);  
	  }
	 else  
		 {str_Evaluate_Result=_T("不合格");
   
	      h->SetWindowText(str_Evaluate_Result);//
		  UpdateData(true);
	  }

}




void Evalute_Angle_Seris::OnBnClickedButtonYuzhi()
{
	// TODO: 在此添加控件通知处理程序代码

	CString tem;
   GetDlgItem(IDC_EDIT_Yuzhi)->GetWindowText(tem) ; 
	
	// Edit_yuzhi.GetWindowText(tem);
	 yuzhi1=_ttof(tem);

} 
