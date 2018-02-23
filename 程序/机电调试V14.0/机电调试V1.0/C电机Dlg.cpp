// C电机Dlg.cpp : 实现文件

#include "stdafx.h"
#include "机电调试V1.0.h"
#include "C电机Dlg.h"
#include "afxdialogex.h"
#include "机电调试V1.0Dlg.h"
#include "CTChart.h"
#include "tchart1.h"
#include "CPanel.h"
#include "CGradient.h"
#include "CSeries.h"
#include "CAxes.h"
#include "CAxis.h"
#include "CScroll.h"


int flag_cal_Mor=0;

// C电机Dlg 对话框

IMPLEMENT_DYNAMIC(C电机Dlg, CDialogEx)

C电机Dlg::C电机Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(C电机Dlg::IDD, pParent)
	
	//, m_Edit_Tor_Pre(_T("0"))


	//, m_Edit_Star_Pre(_T("0"))

	
	//, m_Edit_Back_Pre(_T("0"))

	, m_Edit_Slip_Time(_T("0"))
	//, m_Edit_Slip_Pre(_T("0"))

	
	//, m_Edit_Ror_Pre(_T("0"))

	, m_Edit_Mor_Cur1(_T("0"))
	//, m_Edit_Cur_Pre1(_T("0"))
	, m_Edit_Mor_Cur2(_T("0"))
	//, m_Edit_Cur_Pre2(_T("0"))


	, m_Edit_Mor_Rev2(0)
	, m_Edit_Direc(_T("0"))

	, m_Edit_Star_Vol(0)
	, m_Edit_Back_Elec(0)
	, m_Edit_Mor_Rev1(0)
	, m_Edit_Tor_Coe(0)
	, m_Edit_Ror_Tor(0)
	, Edit_tor_Flu(0)
	
	, m_Edit_Mor_Eff(_T(""))
{

}

C电机Dlg::~C电机Dlg()
{
}

void C电机Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);




	//DDX_Text(pDX, IDC_Tor_Pre_EDIT, m_Edit_Tor_Pre);


	//DDX_Text(pDX, IDC_Star_Pre_EDIT, m_Edit_Star_Pre);

	//DDX_Text(pDX, IDC_Back_Elec_EDIT, m_Edit_Back_Elec);
	//DDX_Text(pDX, IDC_Back_Pre_EDIT, m_Edit_Back_Pre);

	DDX_Text(pDX, IDC_Slip_Time_EDIT, m_Edit_Slip_Time);
	//DDX_Text(pDX, IDC_Slip_Pre_EDIT, m_Edit_Slip_Pre);

	//DDX_Text(pDX, IDC_Ror_Tor_EDIT, m_Edit_Ror_Tor);
	//DDX_Text(pDX, IDC_Ror_Pre_EDIT, m_Edit_Ror_Pre);

	DDX_Text(pDX, IDC_Mor_Cur1_EDIT, m_Edit_Mor_Cur1);
	//DDX_Text(pDX, IDC_Cur_Pre1_EDIT, m_Edit_Cur_Pre1);

	DDX_Text(pDX, IDC_Mor_Cur2_EDIT, m_Edit_Mor_Cur2);
	//DDX_Text(pDX, IDC_Cur_Pre2_EDIT, m_Edit_Cur_Pre2);

	//DDX_Text(pDX, IDC_Mor_Rev1_EDIT, m_Edit_Mor_Rev1);
	DDX_Text(pDX, IDC_Mor_Rev2_EDIT, m_Edit_Mor_Rev2);

	//DDX_Text(pDX, IDC_Tor_Flu_Pro_EDIT, m_Edit_Tor_Flu_Pro);
	//DDX_Text(pDX, IDC_Flu_Pre_EDIT, m_Edit_Flu_Pre);

	DDX_Control(pDX, IDC_Star_Vol_TCHART, m_Tchart_Star_Vol);//计
	DDX_Control(pDX, IDC_Tor_Coe_TCHART, m_Tchart_Tor_Coe);
	DDX_Control(pDX, IDC_Back_Elec_TCHART, m_Tchart_Back_Elec);
	DDX_Control(pDX, IDC_Slip_Time_TCHART, m_Tchart_Slip_Time);
	DDX_Control(pDX, IDC_Ror_Tor_TCHART, m_Tchart_Ror_Tor);
	DDX_Control(pDX, IDC_Mor_Cur1_TCHART, m_Tchart_Mor_Cur1);
	DDX_Control(pDX, IDC_Mor_Rev1_TCHART, m_Tchart_Mor_Rev1);

	DDX_Control(pDX, IDC_Mor_Rev_TCHART, m_Tchart_Mor_Rev2);//曲线
	DDX_Control(pDX, IDC_Mor_Cur2_TCHART, m_Tchart_Mor_Cur2);
	DDX_Control(pDX, IDC_Tor_Flu_Pro_TCHART, m_Tchart_Tor_Flu_Pro);
	DDX_Text(pDX, IDC_Star_Vol_EDIT, m_Edit_Star_Vol);
	DDX_Text(pDX, IDC_Back_Elec_EDIT, m_Edit_Back_Elec);
	DDX_Text(pDX, IDC_Mor_Rev1_EDIT, m_Edit_Mor_Rev1);
	DDX_Text(pDX, IDC_Tor_Coe_EDIT, m_Edit_Tor_Coe);
	DDX_Text(pDX, IDC_Ror_Tor_EDIT, m_Edit_Ror_Tor);
	DDX_Text(pDX, IDC_Tor_Flu_Pro_EDIT, Edit_tor_Flu);
	DDX_Text(pDX, IDC_Mor_Rev_Direc, m_Edit_Direc);
	DDX_Text(pDX, IDC_Mor_Eff_EDIT, m_Edit_Mor_Eff);
}


BEGIN_MESSAGE_MAP(C电机Dlg, CDialogEx)

	ON_WM_TIMER()
	
//	ON_STN_CLICKED(IDC_Tor_Flu_Pro_EDIT, &C电机Dlg::OnStnClickedTorFluProEdit)
//	ON_STN_CLICKED(IDC_Mor_Rev2_EDIT, &C电机Dlg::OnStnClickedMorRev2Edit)
END_MESSAGE_MAP()


// C电机Dlg 消息处理程序



/************************************初始化*********************************************/
BOOL C电机Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	((CGradient)((CPanel)m_Tchart_Tor_Coe.get_Panel()).get_Gradient()).put_Visible(0);
	((CGradient)((CPanel)m_Tchart_Star_Vol.get_Panel()).get_Gradient()).put_Visible(0);
	((CGradient)((CPanel)m_Tchart_Back_Elec.get_Panel()).get_Gradient()).put_Visible(0); 
	((CGradient)((CPanel)m_Tchart_Slip_Time.get_Panel()).get_Gradient()).put_Visible(0);
	((CGradient)((CPanel)m_Tchart_Ror_Tor.get_Panel()).get_Gradient()).put_Visible(0);
	((CGradient)((CPanel)m_Tchart_Mor_Cur1.get_Panel()).get_Gradient()).put_Visible(0); 
	((CGradient)((CPanel)m_Tchart_Mor_Cur2.get_Panel()).get_Gradient()).put_Visible(0);
	((CGradient)((CPanel)m_Tchart_Tor_Flu_Pro.get_Panel()).get_Gradient()).put_Visible(0); 
	((CGradient)((CPanel)m_Tchart_Mor_Rev1.get_Panel()).get_Gradient()).put_Visible(0);
	((CGradient)((CPanel)m_Tchart_Mor_Rev2.get_Panel()).get_Gradient()).put_Visible(0); 
	jiaodu_flg=0;     //角度程序暂不执行；
	SetTimer(1, 1, NULL);
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}

/*****************************************定时器******************************************/
void C电机Dlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	CDialogEx::OnTimer(nIDEvent);
		//C机电调试V10Dlg *pDia=C机电调试V10Dlg::motorDialog;
	
	if(Flag_Stop==0)//打开串口
	{  
	 
	  
	   MortorDataDisplay();//电机数据显示
       UpdateData(false);
	   GraphDraw_Motor();
      
	}
	 
}

void C电机Dlg::MortorDataDisplay()
{
	C机电调试V10Dlg *pDia=C机电调试V10Dlg::motorDialog;
	
	m_Edit_Tor_Coe= pDia->Tor_Coe; //力矩系数
	Tor_Coe_d= m_Edit_Tor_Coe;

    ((CSeries)m_Tchart_Tor_Coe.Series(0)).Add(Tor_Coe_d,_T(""),0);

 
	
	//Star_Vol_Str

    m_Edit_Star_Vol=pDia->Star_Vol; //启动电压
	Star_Vol_d=m_Edit_Star_Vol;
	((CSeries)m_Tchart_Star_Vol.Series(0)).Add(Star_Vol_d,_T(""),0);




	m_Edit_Back_Elec=pDia->Back_Elec;//反电动势
	Back_Elec_d=m_Edit_Back_Elec;
	((CSeries)m_Tchart_Back_Elec.Series(0)).Add(Back_Elec_d,_T(""),0);

	//m_Edit_Back_Pre=pDia->Back_Pre;//反电动势精度


	m_Edit_Slip_Time=pDia->Slip_Time;//滑行时间
	Slip_Time_d=_ttof(m_Edit_Slip_Time);
	((CSeries)m_Tchart_Slip_Time.Series(0)).Add(Slip_Time_d,_T(""),0);

	//m_Edit_Slip_Pre=pDia->Slip_Pre;//滑行时间精度


	m_Edit_Ror_Tor=pDia->Ror_Tor;//堵转力矩
	Ror_Tor_d=m_Edit_Ror_Tor;
	((CSeries)m_Tchart_Ror_Tor.Series(0)).Add(Ror_Tor_d,_T(""),0);

	//m_Edit_Ror_Pre=pDia->Ror_Pre;//堵转力矩精度

	
	m_Edit_Mor_Cur1=pDia->Mor_Cur;//电机电流
	Mor_Cur_d=_ttof(m_Edit_Mor_Cur1);
   ((CSeries)m_Tchart_Mor_Cur1.Series(0)).Add(Mor_Cur_d,_T(""),0);
	//m_Edit_Cur_Pre1=pDia->Cur_Pre;//电机电流精度

	//m_Edit_Cur_Pre2=pDia->Cur_Pre;


	Edit_tor_Flu=pDia->Tor_Flu;//力矩波动性
	Tor_Flu_d=Edit_tor_Flu;
	//((CSeries)m_Tchart_Tor_Flu_Pro.Series(0)).Add(Tor_Flu_d,_T(""),0);
	

//m_Edit_Flu_Pre=pDia->Flu_Pre;//力矩波动性精度


	m_Edit_Mor_Rev1=pDia->Mor_Rev;//电机转速
	Mor_Rev_d=m_Edit_Mor_Rev1;
	((CSeries)m_Tchart_Mor_Rev1.Series(0)).Add(Mor_Rev_d,_T(""),0);

	m_Edit_Direc=pDia->Mor_Rev_Direc;//电机转向
	m_Edit_Mor_Rev2=m_Edit_Mor_Rev1;    
	//Mor_Rev_d=_ttof(m_Edit_Mor_Rev2);

	if(flag_Eff==1)   //当转速不为0时，轴系安装良好
	{
		m_Edit_Mor_Eff=_T("良好");
	}
	else
		m_Edit_Mor_Eff=_T("差");
	
}

void C电机Dlg::GraphDraw_Motor()
{
 
	((CSeries)m_Tchart_Mor_Cur2.Series(0)).Add(Mor_Cur_d,_T(""),0);//绘制曲线
	//((CAxis)((CAxes)m_Tchart_Mor_Cur2.get_Axis()).get_Bottom()).Scroll(1.0,TRUE); //曲线向左推动
	if (((CSeries)m_Tchart_Mor_Cur2.Series(0)).get_Count()>500)
     ((CSeries)m_Tchart_Mor_Cur2.Series(0)).Clear();

	((CSeries)m_Tchart_Tor_Flu_Pro.Series(0)).Add(Tor_Flu_d,_T(""),0);//绘制曲线
	//((CAxis)((CAxes)m_Tchart_Tor_Flu_Pro.get_Axis()).get_Bottom()).Scroll(1.0,TRUE); //曲线向左推动
	if (((CSeries)m_Tchart_Tor_Flu_Pro.Series(0)).get_Count()>500)
     ((CSeries)m_Tchart_Tor_Flu_Pro.Series(0)).Clear();
	
	((CSeries)m_Tchart_Mor_Rev2.Series(0)).Add(Mor_Rev_d,_T(""),0);//绘制曲线
	//((CAxis)((CAxes)m_Tchart_Mor_Rev2.get_Axis()).get_Bottom()).Scroll(1.0,TRUE); //曲线向左推动
 
    if (((CSeries)m_Tchart_Mor_Rev2.Series(0)).get_Count()>500)
     ((CSeries)m_Tchart_Mor_Rev2.Series(0)).Clear();
}




