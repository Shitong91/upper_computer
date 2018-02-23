// C角度传感器Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "机电调试V1.0.h"
#include "C角度传感器Dlg.h"
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


// C角度传感器Dlg 对话框

IMPLEMENT_DYNAMIC(C角度传感器Dlg, CDialogEx)

C角度传感器Dlg::C角度传感器Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(C角度传感器Dlg::IDD, pParent)

	, m_Edit_Enc_P_C(_T("0"))
	//, m_Edit_Enc_Eff(_T("0"))
	, m_Edit_Enc_Qua(_T("0"))
	//, m_Edit_Enc_Pre(_T("0"))

	

	, m_Edit_Rou_Qua(_T("0"))
	, m_Edit_Rou_P_C(_T("0"))
	//, m_Edit_Rou_Pre(_T("0"))
	//, m_Edit_Rou_Eff(_T("0"))

	, m_Edit_Mul_Qua(_T("0"))
	, m_Edit_Mul_P_C(_T("0"))
	//, m_Edit_Mul_Pre(_T("0"))
	//, m_Edit_Mul_Eff(_T("0"))
	//, m_Tchart1()
	//, m_Tchart2()
	//, m_Tchart3()

	, m_Static_Mul_Angle(_T("0.0000"))
	, m_Static_Rou_Angle(_T("0.0000"))
	, m_Static_Enc_Angle(_T("0.0000"))
//	, m_Chart_Graph(0)
{

}

C角度传感器Dlg::~C角度传感器Dlg()
{
}

void C角度传感器Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_Enc_Qua_EDIT, m_Edit_Enc_Qua);
	//DDX_Text(pDX, IDC_Enc_Pre_EDIT, m_Edit_Enc_Pre);
	DDX_Text(pDX, IDC_Enc_P_C_EDIT, m_Edit_Enc_P_C);
	//DDX_Text(pDX, IDC_Enc_Eff_EDIT, m_Edit_Enc_Eff);

	DDX_Text(pDX, IDC_Rou_Qua_EDIT, m_Edit_Rou_Qua);
	DDX_Text(pDX, IDC_Rou_P_C_EDIT, m_Edit_Rou_P_C);
	//DDX_Text(pDX, IDC_Rou_Pre_EDIT, m_Edit_Rou_Pre);
	//DDX_Text(pDX, IDC_Rou_Eff_EDIT, m_Edit_Rou_Eff);


	DDX_Text(pDX, IDC_Mul_Qua_EDIT, m_Edit_Mul_Qua);
	DDX_Text(pDX, IDC_Mul_P_C_EDIT, m_Edit_Mul_P_C);
	//DDX_Text(pDX, IDC_Mul_Pre_EDIT, m_Edit_Mul_Pre);
	//DDX_Text(pDX, IDC_Mul_Eff_EDIT, m_Edit_Mul_Eff);
	DDX_Control(pDX, IDC_TCHART1, m_Tchart1);
	DDX_Control(pDX, IDC_TCHART2, m_Tchart2);
	DDX_Control(pDX, IDC_TCHART3, m_Tchart3);
	DDX_Text(pDX, IDC_Mul_Angle_Static, m_Static_Mul_Angle);
	DDX_Text(pDX, IDC_Rou_Angle_Static, m_Static_Rou_Angle);
	DDX_Text(pDX, IDC_Enc_Angle_Static, m_Static_Enc_Angle);
	DDX_Control(pDX, IDC_TCHART_Graph, m_Chart_Graph);

	DDX_Control(pDX, IDC_Rou_CHECK, m_Check_Rou);
	DDX_Control(pDX, IDC_Enc_CHECK, m_Check_Enc);
	DDX_Control(pDX, IDC_Mul_CHECK, m_Check_Mul);
}


BEGIN_MESSAGE_MAP(C角度传感器Dlg, CDialogEx)
	
	// 添加自定义消息映射
	
//	ON_WM_ACTIVATE()
ON_WM_TIMER()

ON_WM_MOUSEMOVE()
ON_WM_LBUTTONDOWN()

//ON_EN_CHANGE(IDC_Enc_P_C_EDIT, &C角度传感器Dlg::OnEnChangeEncPCEdit)
END_MESSAGE_MAP()


// C角度传感器Dlg 消息处理程序
/**************************************定时器*************************************/
void C角度传感器Dlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	C机电调试V10Dlg *pDib=C机电调试V10Dlg::AngleDialog;
	if(Flag_Stop==0) //打开串口
	{
		
		
		m_Static_Mul_Angle=pDib->Mul_Angle_str;
		Mul_Angle_d=_ttof(m_Static_Mul_Angle);
	
	
		((CSeries)m_Tchart1.Series(0)).Add(Mul_Angle_d,_T(""),0);

		m_Static_Rou_Angle=pDib->Rou_Angle;
		Rou_Angle_d=_ttof(m_Static_Rou_Angle);
	
		((CSeries)m_Tchart2.Series(0)).Add(Rou_Angle_d,_T(""),0);

		m_Static_Enc_Angle=pDib->Enc_Angle;
		Enc_Angle_d=_ttof(m_Static_Enc_Angle);
	
		((CSeries)m_Tchart3.Series(0)).Add(Enc_Angle_d,_T(""),0);
    
		GraphDraw(); //绘图函数
	
		DataDisplay( IDC_Mul_Jump,max1,sum1,min1);
		DataDisplay( IDC_Rou_Jump,max2,sum2,min2);
		DataDisplay( IDC_Enc_Jump,max3,sum3,min3);

	
		m_Edit_Mul_Qua=pDib->Mul_Qua;
		m_Edit_Mul_P_C=pDib->Mul_P_C;
		//m_Edit_Mul_Pre=pDib->Mul_Pre;
		//m_Edit_Mul_Eff=pDib->Mul_Eff; 
	
		m_Edit_Rou_Qua=pDib->Rou_Qua;
		m_Edit_Rou_P_C=pDib->Rou_P_C;
		//m_Edit_Rou_Pre=pDib->Rou_Pre;
		//m_Edit_Rou_Eff=pDib->Rou_Eff;
	
		m_Edit_Enc_Qua=pDib->Enc_Qua;
		//m_Edit_Enc_Pre=pDib->Enc_Pre;
		m_Edit_Enc_P_C=pDib->Enc_P_C;
		//m_Edit_Enc_Eff=pDib->Enc_Eff;
		UpdateData(false); 
	}
	CDialogEx::OnTimer(nIDEvent);
}


BOOL C角度传感器Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化

	((CGradient)((CPanel)m_Tchart1.get_Panel()).get_Gradient()).put_Visible(0);
	((CGradient)((CPanel)m_Tchart2.get_Panel()).get_Gradient()).put_Visible(0);
	((CGradient)((CPanel)m_Tchart3.get_Panel()).get_Gradient()).put_Visible(0); 

	 
((CGradient)((CPanel)m_Tchart2.get_Panel()).get_Gradient()).put_StartColor(RGB(192,192,192));  
((CGradient)((CPanel)m_Tchart2.get_Panel()).get_Gradient()).put_EndColor(RGB(255,255,255));

//m_Tchart2.Series(0).SetColor(RGB(255,0,0));//颜色  
//m_chart.Series(0).GetAsLine().GetLinePen().SetWidth(2); //线型宽度  
//CSeries(m_Chart_Graph.Series(0))..GetAsLine().GetLinePen().SetWidth(2);//绘制曲线

	SetTimer(1,1, NULL);

	m_Check_Rou.SetCheck(1);
	m_Check_Enc.SetCheck(1);
	m_Check_Mul.SetCheck(1);
	jiaodu_flg=1;   //角度程序执行标志位
	//Motor_Resfinish_flg=1;
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}

/**************************************绘制曲线*********************************/
void C角度传感器Dlg::GraphDraw()
{
	//	CString sDate;
	
	//sDate=Today.Format(_T("\r\n\r\n\r\n\r\n\r\n%Y年%m月%d日\r\n%H:%M:%S"));
 //   int week=Today.GetDayOfWeek();

	//COleDateTime CurTime = COleDateTime::GetCurrentTime();  
	//COleDateTimeSpan tmSpan = COleDateTimeSpan(0,0,1,0); //1s  
	//CString csTime ;  
	//csTime= CurTime.Format(_T("%H:%M:%S")); //获取当前时间  
	//CurTime+= tmSpan;

	if(1==m_Check_Mul.GetCheck())
	CSeries(m_Chart_Graph.Series(0)).Add(Mul_Angle_d,_T(""),1);//绘制曲线
	else 
		CSeries(m_Chart_Graph.Series(0)).Add(0,_T(""),1);//绘制曲线

	if(1==m_Check_Rou.GetCheck())
	CSeries(m_Chart_Graph.Series(1)).Add(Rou_Angle_d,_T(""),1);//绘制曲线
	else 
		CSeries(m_Chart_Graph.Series(1)).Add(0,_T(""),1);//绘制曲线

	if(1==m_Check_Enc.GetCheck())
	CSeries(m_Chart_Graph.Series(2)).Add(Enc_Angle_d,_T(""),1);//绘制曲线
	else 
		CSeries(m_Chart_Graph.Series(2)).Add(0,_T(""),1);//绘制曲线

    if (((CSeries)m_Chart_Graph.Series(0)).get_Count()>500)
     ((CSeries)m_Chart_Graph.Series(0)).Clear();

	  if (((CSeries)m_Chart_Graph.Series(1)).get_Count()>500)
     ((CSeries)m_Chart_Graph.Series(1)).Clear();

  if (((CSeries)m_Chart_Graph.Series(2)).get_Count()>500)
     ((CSeries)m_Chart_Graph.Series(2)).Clear();

 //  ((CSeries)m_Chart_Graph.Series(1)).RefreshSeries();  
	//if(((CSeries)m_Chart_Graph.Series(1)).get_Count() > 500)  
	//{  
	//  ((CAxis)((CAxes)m_Chart_Graph.get_Axis()).get_Bottom()).Scroll(1.0,true); //x坐标轴一次移动1格  
	//}  
	//((CAxis)((CAxes)m_Chart_Graph.get_Axis()).get_Bottom()).Scroll(1.0,TRUE); //曲线向左推动

}
		
//触发鼠标响应

BEGIN_EVENTSINK_MAP(C角度传感器Dlg, CDialogEx)
	ON_EVENT(C角度传感器Dlg, IDC_TCHART_Graph, 20, C角度传感器Dlg::OnMouseMoveTchartGraph, VTS_I4 VTS_I4 VTS_I4)
END_EVENTSINK_MAP()


void C角度传感器Dlg::OnMouseMoveTchartGraph(long Shift, long X, long Y)
{
	// TODO: 在此处添加消息处理程序代码
	 m_Chart_Graph.Repaint(); 

    double posX,posY;  
    posX = ((CAxis)((CAxes)m_Chart_Graph.get_Axis()).get_Bottom()).CalcPosPoint(X)+1; //显示鼠标位置
    posY = ((CAxis)((CAxes)m_Chart_Graph.get_Axis()).get_Left()).CalcPosPoint(Y); 


    CString cs; 
    cs.Format(_T("posX:%f\tposY:%f\r\n"),posX,posY); 
    TRACE(cs); 
    SetDlgItemText(IDC_STATIC_X,cs); 

}

/*************************************最大值、最小值、平均值显示**************************/
void C角度传感器Dlg::DataDisplay( UINT IDD,double max,double sum,double min)
{
	CString CJumpVar; 
	CJumpVar.Format(_T("最大值:%f\t平均值:%f\t最小值:%f\r\n"),max,sum,min); 
	TRACE( CJumpVar); 
	SetDlgItemText(IDD, CJumpVar); 
}
