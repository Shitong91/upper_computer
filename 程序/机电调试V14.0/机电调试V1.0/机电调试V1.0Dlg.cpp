
// 机电调试V1.0Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "机电调试V1.0.h"
#include "机电调试V1.0Dlg.h"
#include "afxdialogex.h"
#include <afx.h>
#include "SerialDlg.h"
#include "C电机Dlg.h"
#include "C角度传感器Dlg.h"
#include "CopyRightDlg.h"
#include "HelpDlg.h"
#include <fstream>
#include "ModeChoiceDlg.h"
#include "DataChoiceDlg.h"
#include "MotorDataSaveDlg.h"
#include "GotoNormalTipDlg.h"
#include "math.h"
#include "CheckChoiceDlg.h"
#include "EvaluateChoiceDlg.h"
#include "Check_ProgresDlg.h"
#include "Angle_Evalu_list.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
   
	int count1=0;
	int count2=0;
	int count3=0;
	int count4=0;
	int count5=0;
	int count6=0;
	int count7=0;
	int count8=0;
	int pmax,pmin=0;
	double max4=0;
	double Mul[100];
	double Rou[100];
	double Enc[100];
	double Para1[100];
	double Para2[100];
	double Para3[100];
	
	double Motor_Vol=0.0;//电机电压
	double Motor_Cur=0.0;//电机电流
	
	double  Motor_Cur_Locked=0.0;
	double  Motor_Vol_Locked=0.0;
    double sum_locked1=0.0;;
	double sum_locked2=0.0;
	 double sum_locked3=0.0;
	double sum_locked4=0.0;
	double sum_Flu=0;
	int MotorLocked_flag=0;
	int Locked_Start=0;
	int Flag_check=0;           //运行除自检以外的程序标志位
	CString AD_Convert=_T("0");//AD转换
	CString Moto_Mul_Flag=_T("A");
   
	CString str_Convert_Start;   //启动运行和停止运行切换
	CWnd *h1; 

	int Flag_clear=0; //控件清零标志位

	CString str_Locked;     //进度条静态文本显示
	CWnd *h2; 

	CString str_Convert_AD;//两片AD工作切换
	CWnd *h3;

	int flag_Eff=0;//轴系安装效果标志位
	
   double Yuan_Angle[2];
   int yu=0;
   double Xuan_Angle[2];
   int xu=0;

   double Guang_Angle[2];
   int gu=0;
	// CProgressCtrl m_Check_pro;
   
C机电调试V10Dlg *C机电调试V10Dlg::motorDialog=NULL;     ////////////////主子对话框数据传送//////////////3也可以放在初始化里
C机电调试V10Dlg *C机电调试V10Dlg::AngleDialog=NULL;     //////////////////////////////3也可以放在初始化里
/*****************************状态栏********************************/
static UINT indicators[] =

{

     IDS_INDICATOR_MESSAGE,       //就绪

     IDS_INDICATOR_TIME,          //显示系统时间

	 IDS_INDICATOR_Software_TIME  //显示软件运行时间

	 

};

/*************************************************************/
// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// C机电调试V10Dlg 对话框
	 CString strVal1=_T("多极旋变");
	 CString strVal2=_T("象限");
	 CString strVal3=_T("正反转");

	 CString strVal4=_T("圆感应");
	 CString strVal5=_T("象限");
	 CString strVal6=_T("正反转");

	 CString strVal7=_T("编码器");
	 CString strVal8=_T("象限");
	 CString strVal9=_T("正反转");

     CString strVal10=_T("启动电压");
	 CString strVal11=_T("反电动势");
	 CString strVal12=_T("力矩系数");

	 CString strVal13=_T("堵转力矩");
	 CString strVal14=_T("电机电流");
	 CString strVal15=_T("滑行时间");

	 CString strVal16=_T("转速");

	 CString Star_Vol_S=_T("0"); 
	 CString Back_Elec_S=_T("0");  
	 CString Tor_Coe_S=_T("0"); 
	 CString Ror_Tor_S=_T("0"); 

C机电调试V10Dlg::C机电调试V10Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(C机电调试V10Dlg::IDD, pParent)
/*******************初始化所有显示栏为0************************/
	/*光电编码器各参数对应变量*/ 
	,Enc_Angle(_T("0.0000"))//角度中间变量
	,Enc_Qua(_T("0"))//象限中间变量
	,Enc_Pre(_T("0"))//角位置精度中间变量
	,Enc_Rev(_T("0"))//转速中间变量
	,Enc_P_C(_T("0"))//正反转中间变量
	,Enc_Eff(_T("0"))//轴系安装效果中间变量

	/*圆感应同步器各参数对应变量*/
	
	,Rou_Angle(_T("0.0000"))//角度中间变量
	,Rou_Qua(_T("0"))//象限中间变量
	,Rou_P_C(_T("0"))//正反转中间变量
	,Rou_Pre(_T("0"))//角位置精度中间变量
	,Rou_Eff(_T("0"))//轴系安装效果中间变量

	/*多极旋转变压器各参数对应变量*/
	,Mul_Angle(_T("0.0000"))//角度中间变量
	,Mul_Qua(_T("0"))//象限中间变量
	,Mul_P_C(_T("0"))//正反转中间变量
	,Mul_Pre(_T("0"))//角位置精度中间变量
	,Mul_Eff(_T("0"))//轴系安装效果中间变量

	,Tor_Coee(_T("0"))//力矩系数中间变量
	,Tor_Pre(_T("0")) //力矩系数精度中间变量
	
	//,Star_Vol_Str(_T("0"))//启动电压中间变量
	,Star_Pre(_T("0"))//启动电压精度中间变量

	 //,Back_Elec(_T("0"))//反电动势中间变量
	 ,Back_Pre(_T("0"))//反电动势精度中间变量

	 ,Slip_Time(_T("0"))//滑行时间中间变量
	 ,Slip_Pre(_T("0"))//滑行时间精度中间变量

	// ,Ror_Tor(_T("0"))//堵转力矩中间变量
	 ,Ror_Pre(_T("0"))//堵转力矩精度中间变量

	 ,Mor_Cur(_T("0"))//电机电流中间变量
	 ,Cur_Pre(_T("0"))//电机电流精度中间变量

	// ,Tor_Flu(_T("0"))//力矩波动性中间变量
	 ,Flu_Pre(_T("0"))//力矩波动性精度中间变量

	 ,Mor_Rev_Str(_T("0"))//电机转速中间变量字符串形式
	 ,Mor_Rev_Direc(_T("0"))//电机转速转向变量字符串形式
	// ,sum_locked(0.0)
    // ,MotorLocked_flag(0)
	 ,Motor_Vol_S(_T("0"))
	 ,Motor_Cur_S(_T("0"))
     ,Motor_Res_S(_T("0"))
	 ,Star_Vol(0.0)//启动电压中间变量
	 ,Back_Elec(0.0)//反电动势参数初始化
	 ,Tor_Coe(0.0)//力矩系数参数初始化
	 ,Mor_Rev(0.0)//串口接收的字符串转浮点转速数据
	 ,Ror_Tor(0.0)//堵转力矩
     ,Tor_Flu(0.0)//输出转矩

{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);//设置软件图标
}

void C机电调试V10Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_MSCOMM1, m_mscom);
	DDX_Control(pDX, IDC_TAB, m_tab);
	DDX_Control(pDX, IDC_PROGRESS1, m_pro);
	DDX_Control(pDX, IDC_Moto_yes, IDC_MOTOR_POWER);
	DDX_Control(pDX, IDC_MOTO_LIMIT, IDC_Moto_Lim);
	DDX_Control(pDX, IDC_Xuanbian_yes, IDC_Xuanbian_Power);
	DDX_Control(pDX, IDC_Xuanbian_LIMIT, IDC_Xuanbian_Angle);
	DDX_Control(pDX, IDC_Guangshan_yes, IDC_Guangshan_Power);
	DDX_Control(pDX, IDC_Guangshan_LIMIT, IDC_Guangshan_Angle);
	DDX_Control(pDX, IDC_Yuangan_yes, IDC_Yuangan_Power);
	DDX_Control(pDX, IDC_Yuangan_LIMIT, IDC_Yuangan_Angle);
}

BEGIN_MESSAGE_MAP(C机电调试V10Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_COMMAND(ID_SET_ABOUT, &C机电调试V10Dlg::OnSetAbout)
	ON_NOTIFY(TCN_SELCHANGE, IDC_TAB, &C机电调试V10Dlg::OnTcnSelchangeTab)
	ON_COMMAND(ID_Call_Serial, &C机电调试V10Dlg::OnCallSerial)
	ON_COMMAND(IDC_Serial_OPEN, &C机电调试V10Dlg::OnSerialOpen)
	ON_COMMAND(IDC_Serial_CLOSE, &C机电调试V10Dlg::OnSerialClose)
	ON_COMMAND(ID_Save_Data, &C机电调试V10Dlg::OnSaveData)
	ON_COMMAND(ID_Copy_Right, &C机电调试V10Dlg::OnCopyRight)
	ON_COMMAND(ID_Open_txt, &C机电调试V10Dlg::OnOpentxt)
	ON_WM_TIMER()
	ON_COMMAND(ID_HELP, &C机电调试V10Dlg::OnHelp)
	ON_COMMAND(ID_Capture_Screen, &C机电调试V10Dlg::OnCaptureScreen)
	ON_COMMAND(ID_Clear_Data, &C机电调试V10Dlg::OnClearData)
	ON_COMMAND(ID_Locked_Data_Calcu, &C机电调试V10Dlg::OnLockedDataCalcu)
	//ON_COMMAND(ID_Motor_BUTTON, &C机电调试V10Dlg::OnMotorButton)
	ON_COMMAND(ID_TEST_OBJ_BUTTON, &C机电调试V10Dlg::OnTestObjButton)
	ON_COMMAND(ID_OPEN_CHECK, &C机电调试V10Dlg::OnOpenCheck)
	ON_COMMAND(ID_Evaluate, &C机电调试V10Dlg::OnEvaluate)
END_MESSAGE_MAP()


// C机电调试V10Dlg 消息处理程序

/*******************************初始化*************************************/
BOOL C机电调试V10Dlg::OnInitDialog() 
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);


	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}


	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码


/*****************************启动运行和停止运行转换初始化********************************/	
	GetDlgItemText(IDC_STATIC_close,str_Convert_Start); 	
	h1=GetDlgItem(IDC_STATIC_close); //指向控件的caption


/*****************************进度条静态文本转换初始化********************************/	
	GetDlgItemText(IDC_STATIC_close,str_Locked); 	
	h2=GetDlgItem(IDC_Locked_Descri_STATIC); //指向控件的caption
	str_Locked=_T("未堵转"); 
	UpdateData(true);  
	h2->SetWindowText(str_Locked);//改变进度条文本


/****************************测量对象转换******************************************/
	GetDlgItemText(IDC_TEST_OBJ_STATIC,str_Convert_AD); 	
	h3=GetDlgItem(IDC_TEST_OBJ_STATIC); //指向控件的caption


/*****************************工具栏********************************/	
if (!m_ToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_TOP | CBRS_GRIPPER 
	| CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC) ||!m_ToolBar.LoadToolBar(IDR_TOOLBAR1))
{
	TRACE0("未能创建工具栏\n");
	return -1;      // 未能创建
}

m_ToolBar.ShowWindow(SW_SHOW);

RepositionBars(AFX_IDW_CONTROLBAR_FIRST,AFX_IDW_CONTROLBAR_LAST,0);
 /****************************************************************/

 
/*****************************状态栏********************************/	
	m_bar.Create(this); //创建状态栏
	m_bar.SetIndicators(indicators,3); //设置状态栏中窗格个数为3

	CRect rect;

	GetClientRect(&rect);

//Size the two panes

	m_bar.SetPaneInfo(0,IDS_INDICATOR_MESSAGE,

    SBPS_NORMAL,rect.Width()-500);   //大小设置  

	//m_bar.GetStatusBarCtrl().SetBkColor(RGB(255,180,180));//设置状态栏颜色

	m_bar.SetPaneInfo(1, IDS_INDICATOR_TIME ,SBPS_NORMAL,300); //系统时间------第一步 //100 表示新的状态显示窗格的宽度. SBPS_NORMAL  表示状态窗格的类型

	m_bar.SetPaneInfo(2, IDS_INDICATOR_Software_TIME  ,SBPS_NORMAL,300);//软件运行时间

	//This is where we actually draw it on the screen

	RepositionBars(AFX_IDW_CONTROLBAR_FIRST,AFX_IDW_CONTROLBAR_LAST,IDS_INDICATOR_TIME);
	
	m_beginTime = CTime::GetCurrentTime();//给予当前软件的启动时间

	SetTimer(1,1000,NULL);
	
/****************************************************************/

	motorDialog=this;  ///////////////////////////////电机标签/////////////////////2//////////
	AngleDialog=this; //////角度传感器标签

/*******************************电机标签初始化********************************/

	CRect tabRect;   // 标签控件客户区的位置和大小   
  
    m_tab.InsertItem(0, _T("电机"));         // 插入第一个标签“电机”   
    m_tab.InsertItem(1, _T("角度传感器"));  // 插入第二个标签“角度传感器”   
    m_motorDlg.Create(IDD_MORTOR_DIALOG, &m_tab);    // 创建第一个标签页   
    m_AngleDlg.Create(IDD_Angle_DIALOG, &m_tab); // 创建第二个标签页   
  
    m_tab.GetClientRect(&tabRect);    // 获取标签控件客户区Rect   

   //调整tabRect，使其覆盖范围适合放置标签页  

    tabRect.left   += 1;                  
    tabRect.right  -= 1;   
    tabRect.top    += 25;    
    tabRect.bottom -= 1;   

	m_motorDlg.SetWindowPos(NULL, tabRect.left, tabRect.top, tabRect.Width(), tabRect.Height(), SWP_SHOWWINDOW);   //显示电机标签
    m_AngleDlg.SetWindowPos(NULL, tabRect.left, tabRect.top, tabRect.Width(), tabRect.Height(), SWP_HIDEWINDOW);   //隐藏角度传感器标签

	/*************************************************************/
	Flag_Stop=1;  //停止运行

	Flag_Save=0;  //保存数据标志位清空

	CStdioFile file;

	file.Open(L"机电调试数据.txt",CFile::modeCreate|CFile::modeNoTruncate|CFile::modeReadWrite);
	char* old_locale = _strdup( setlocale(LC_CTYPE,NULL) );
	setlocale( LC_CTYPE, "chs" );//设定

	file.SeekToEnd();
	CString sDate1;
	//m_EndTime=CTime::GetCurrentTime();
	CTime Today=CTime::GetCurrentTime();
	sDate1=Today.Format(_T("\r\n\r\n\r\n\r\n\r\n%Y年%m月%d日\r\n%H:%M:%S"));
    int week=Today.GetDayOfWeek();
  //获取星期几，1为星期天，7为星期六
    switch(week)
	{
		case 1:{sDate1=sDate1+_T("\r\n星期日");break;}
		case 2:{sDate1=sDate1+_T("\r\n星期一");break;}
		case 3:{sDate1=sDate1+_T("\r\n星期二");break;}
		case 4:{sDate1=sDate1+_T("\r\n星期三");break;}
		case 5:{sDate1=sDate1+_T("\r\n星期四");break;}
		case 6:{sDate1=sDate1+_T("\r\n星期五");break;}
		case 7:{sDate1=sDate1+_T("\r\n星期六");break;}
	} 
	//m_bar.SetPaneText(1,sDate); 	 
	//初始化，给txt文档第一行写上数据名称
	file.WriteString(sDate1+"\n");//正常写入

	file.WriteString(strVal1+" " + " "+" ");//正常写入
	file.WriteString(strVal2+" " + " "+" ");//正常写入
	file.WriteString(strVal3+" " + " "+" ");//正常写入

	file.WriteString(strVal4+" " + " "+" ");//正常写入
	file.WriteString(strVal5+" " + " "+" ");//正常写入
	file.WriteString(strVal6+" " + " "+" ");//正常写入

	file.WriteString(strVal7+" " + " "+" ");//正常写入
	file.WriteString(strVal8+" " + " "+" ");//正常写入
	file.WriteString(strVal9+" " + " "+" ");//正常写入

	file.WriteString(strVal10+" " + " "+" ");//正常写入
	file.WriteString(strVal11+" " + " "+" ");//正常写入
	file.WriteString(strVal12+" " + " "+" ");//正常写入

	file.WriteString(strVal13+" " + " "+" ");//正常写入
	file.WriteString(strVal14+" " + " "+" ");//正常写入
	file.WriteString(strVal15+" " + " "+" ");//正常写入

	file.WriteString(strVal16+" " + " "+" "+"\n");//正常写入
	setlocale( LC_CTYPE, old_locale );
	free( old_locale );//还原区域设定
	file.Close();
	SetTimer(2,50,NULL);
/**************************堵转进度条***********************************/	
	//进度栏初始化， 步进为10，总共步进10次
	m_pro.SetRange(0,1000);
    m_pro.SetStep(1);

/********************************自检图标设置*******************************/
//m_hIcon_yes= (HICON)LoadImage(AfxGetInstanceHandle(),MAKEINTRESOURCE(IDR_MAINFRAME),IMAGE_ICON,40,40,LR_DEFAULTCOLOR);
m_hIcon_no=LoadIcon(AfxGetInstanceHandle(),MAKEINTRESOURCE(IDI_ICON_NO));
m_hIcon_yes=LoadIcon(AfxGetInstanceHandle(),MAKEINTRESOURCE(IDI_ICON_YES));

IDC_MOTOR_POWER.SetIcon(m_hIcon_no);//电机自检是否上电
IDC_Moto_Lim.SetIcon(m_hIcon_no);//电机自检旋转是否不受限

IDC_Yuangan_Power.SetIcon(m_hIcon_no);//圆感应自检是否上电;
IDC_Yuangan_Angle.SetIcon(m_hIcon_no);//圆感应自检是否有角度输出;

IDC_Xuanbian_Power.SetIcon(m_hIcon_no);//多极旋变自检是否上电;
IDC_Xuanbian_Angle.SetIcon(m_hIcon_no);//多极旋变自检是否上电;

IDC_Guangshan_Power.SetIcon(m_hIcon_no);//光栅自检是否上电;
IDC_Guangshan_Angle.SetIcon(m_hIcon_no);//光栅应自检是否上电;
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void C机电调试V10Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void C机电调试V10Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR C机电调试V10Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


BEGIN_EVENTSINK_MAP(C机电调试V10Dlg, CDialogEx)
	ON_EVENT(C机电调试V10Dlg, IDC_MSCOMM1, 1, C机电调试V10Dlg::OnCommMscomm1, VTS_NONE)

END_EVENTSINK_MAP()

int j=0;
void C机电调试V10Dlg::OnCommMscomm1()   //串口控件对应事件处理程序
{

	VARIANT m_varInput;	//定义为VARIANT数据类型
	COleSafeArray m_oleInput;//COleSafeArray类是用于处理任意类型和维数的数组的类
	long length,i;
	char  data[4096]={0};
	CString strtemp;//定义strtemp为字符串型
	if(m_mscom.get_CommEvent()==2)       //事件值为2表示接收缓冲区内有字符  
	{	 
       // seria_Stop=1;    //串口发数标志位
		m_varInput=m_mscom.get_Input();//读缓冲区 
		m_oleInput=m_varInput;//VARIANT型变量转换为ColeSafeArray型变量 
		length=m_oleInput.GetOneDimSize();//得到有效数据长度 
			
		for(i=0;i<length;i++)
		m_oleInput.GetElement(&i,data+i);//转换为BYTE型数组

		for(i=0;i<length;i++)
		{
			BYTE bt=*(char*)(data+i);

			
			strtemp.Format(_T("%c"),bt);//将数据强制转换成字符型


			//接收框接收字符串
			m_shuju+=strtemp;
			//if(i>=50)
		   // {
			  chuli(); 
			 
		//	}
		}
	   m_shuju.Empty();     //清空数据缓存区  
	
	}
		
	//SetTimer(1,10,NULL); //延时10ms
	
	UpdateData(false);   //功能：提取数据有效
	
	
}


void C机电调试V10Dlg::OnTcnSelchangeTab(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: 在此添加控件通知处理程序代码
	*pResult = 0;
	CRect tabRect;   // 标签控件客户区的位置和大小 

	m_tab.GetClientRect(&tabRect);
	tabRect.left += 1;                  
    tabRect.right -= 1;   
    tabRect.top += 25;   
    tabRect.bottom -= 1;   

	switch (m_tab.GetCurSel())   
    {
	case 0:          // 如果标签控件当前选择标签为“电机”，则显示m_motorDlg对话框，隐藏m_AngleDlg对话框  
		m_motorDlg.SetWindowPos(NULL, tabRect.left, tabRect.top, tabRect.Width(), tabRect.Height(), SWP_SHOWWINDOW);   
        m_AngleDlg.SetWindowPos(NULL, tabRect.left, tabRect.top, tabRect.Width(), tabRect.Height(), SWP_HIDEWINDOW); 
		break;
	case 1:         // 如果标签控件当前选择标签为“角度传感器”，则隐藏m_motorDlg对话框，显示m_AngleDlg对话框 
		m_motorDlg.SetWindowPos(NULL, tabRect.left, tabRect.top, tabRect.Width(), tabRect.Height(), SWP_HIDEWINDOW);   
		m_AngleDlg.SetWindowPos(NULL, tabRect.left, tabRect.top, tabRect.Width(), tabRect.Height(), SWP_SHOWWINDOW);  
		break;
	default:
		break;
	}
}

/**************************************调用外部串口******************************/
void C机电调试V10Dlg::OnCallSerial() 
{
	// TODO: 在此添加命令处理程序代码
	WinExec("串口调试工具\\SSCOM32.EXE",SW_SHOWMINIMIZED);
}

/***********************************************************************/

/************************************处理数据***********************************/
void C机电调试V10Dlg::chuli()
{
	double Mul_Angle_d1=0;
	CString strBuffer;      //串口字符串
	int nHeadPos = m_shuju.Find(_T("A"));//找帧头
	if(nHeadPos == -1)
	{
		return;
	}
	
	 strBuffer= m_shuju.Mid(nHeadPos+1,52);
	 if((strBuffer.Right(1))!='B')         //找帧尾
	 {
		return;
	 }
	
	
	if(Flag_clear==1)//控件清零或开机自检时刻，数据不接收
	{ 
		
		Mul_Angle=_T("0"); //多极旋变
		Mul_Qua=_T("0");
		Mul_P_C=_T("0");

		Rou_Angle=_T("0"); //圆感应同步器
		Rou_Qua=_T("0");
		Rou_P_C=_T("0");

		Enc_Angle=_T("0"); //编码器
		Enc_Qua=_T("0");
		Enc_P_C=_T("0");
	  
		sum1=0.0;			//多极旋变角度和
		max1=0.0000;		//多极旋变角度最大值
		min1=370.0000;		//多极旋变角度最小值

		sum2=0.0;			//圆感应同步器角度和
		max2=0.0000;		//圆感应同步器角度最大值
		min2=370.0000;		//圆感应同步器角度最小值

		sum3=0.0;			//编码器角度和
		max3=0.0000;		//编码器角度最大值
		min3=370.0000;		//编码器角度最小值

		Mor_Vol=_T("0");    //电机电压中间变量
		Mor_Cur=_T("0");    //电机电流中间变量
		Mor_Rev_Str=_T("0");//电机转速中间变量
		Mor_Rev_Direc=_T("0");
	 }
      
else{										//各种变量取值
		Mul_Angle=strBuffer.Left(8);		//旋变角度
		Mul_Qua=strBuffer.Mid(8,1);			//旋变象限
		Mul_P_C=strBuffer.Mid(9,1);			//旋变正反转

		Rou_Angle=strBuffer.Mid(10,8);		//圆感应同步器角度
		Rou_Qua=strBuffer.Mid(18,1);		//圆感应同步器象限
		Rou_P_C=strBuffer.Mid(19,1);		//圆感应同步器正反转

		Enc_Angle=strBuffer.Mid(20,8);		//编码器角度
		Enc_Qua=strBuffer.Mid(28,1);		//编码器象限
		Enc_P_C=strBuffer.Mid(29,1);		//编码器正反转

		Mor_Vol=strBuffer.Mid(30,7);        //电机电压中间变量
		Mor_Cur=strBuffer.Mid(37,6);        //电机电流中间变量
		Mor_Rev_Str=strBuffer.Mid(43,7);    //电机转速中间变量
		Mor_Rev_Direc=strBuffer.Mid(50,1);
		Mor_Rev=_ttof(Mor_Rev_Str); //电机转速字符串变量转换成double型


		if(Mor_Rev!=0.0)             //当转速不为0时，轴系安装良好
			flag_Eff=1;

       //DataAnalysis_Mul(); 
		
		 Mul[count1++]=_ttof(Mul_Angle);
	//	 Mul1[count2++]=_ttof(Mul_Angle);	
	if(count1==2)
	{
	   if((Mul[0]- Mul[1])>18.0000&&Mul[0]>180.0)
       Mul_Angle_d1= Mul[0]; 
	   if((Mul[1]- Mul[0])>18.0000&&Mul[0]<180.0)
	   Mul_Angle_d1= Mul[0];
	   else Mul_Angle_d1= Mul[1];
	   Mul_Angle_d1 = floor( Mul_Angle_d1 * 10000.000f + 0.5) / 10000.000f;//力矩系数
	   Mul_Angle_str.Format(_T("%8.4f"),  Mul_Angle_d1);
	   count1=0;
	}

	//if(count2==5)
	//{
	//for(int i=0;i<5;i++)
	//	{
 //            通道采集并得到通道的MV值
	//		if(max1<=Mul1[i]){max1=Mul1[i];pmax=i;} //求出最大值
	//		if(min1>=Mul1[i]){min1=Mul1[i];pmin=i;} //求出最小值
	//		                求和
	//	}
	//Mul_Angle_d1=
	//}
if(Moto_Mul_Flag!=_T("A"))
{
	if(jindu==0)
	{ 
	  INT_PTR nRes;//创建进度条对象
	 Check_ProgresDlg CheckChoiceDlg;//弹出进度条对话框
	 nRes=CheckChoiceDlg.DoModal();
	}

	if( Moto_Mul_Flag==_T("B"))  //电机/旋变自检程序调用标志位 =B 电机圆感应自检
			                                                 //=C 旋转变压器自检
		{
			
			Moto_Mul_Check();//电机/圆感应自检
			
			
         IDC_Xuanbian_Power.SetIcon(m_hIcon_no);;
         IDC_Xuanbian_Angle.SetIcon(m_hIcon_no);;
           
			 
		}
	else if( Moto_Mul_Flag==_T("C")) 
	   {
			
		    Xuanbian_Check();
			
			IDC_MOTOR_POWER.SetIcon(m_hIcon_no);
            IDC_Moto_Lim.SetIcon(m_hIcon_no);
            IDC_Yuangan_Power.SetIcon(m_hIcon_no);;
            IDC_Yuangan_Angle.SetIcon(m_hIcon_no);

	   }
	  Flag_check=1;                      //开机自检结束状态标志位 
    // m_mscom.put_PortOpen(false);//关闭串口
 //  Moto_Mul_Flag==_T("A"); 
  // jindu=0;
}

        Guangshan_Check();
//        /*****************************************/
          
	/****************************************/ 
	//if(Flag_check==1)
 //{
      if((Locked_Start==0)&&(Motor_Resfinish_flg=1)&&(jiaodu_flg==0))
			{
				DataAnalysis_MotorLocked1();
				DataAnalysis_MotorLocked2(); 
			}

	
			if(Locked_Start==1)    //正在堵转
			{  
				count7++;
				double Locked_Para_d3=_ttof(Mor_Vol); //String型转换成double型	
				sum_locked3+= Locked_Para_d3;
				if(count7==2)
				{
					count7=0;
					sum_locked3=sum_locked3/2.0;
					Motor_Vol_Locked=sum_locked3; //堵转时，采集10次电机电压求取平均值
					sum_locked3=0;
				}
		
				count8++;
				double Locked_Para_d4=_ttof(Mor_Cur);	//字符串型转换成double型
				sum_locked4 += Locked_Para_d4;
				if(count8==2)   
				{
					count8 = 0;
					sum_locked4 = sum_locked4/2.0; 
				
					MotorLocked_flag = 1;               //电流值每采10次求取平均值
					Motor_Cur_Locked = sum_locked4;
					sum_locked4 = 0;
				}                                             
			  // DataAnalysis_MotorLocked1();
		       // DataAnalysis_MotorLocked2(); 
				if( MotorLocked_flag==1) //当100个数据上传完，并计算出平均值后，将标志位置1，准备进行电阻计算              
				{	
			
					
					for(int j=0;j<500;j++) //步进数500
					m_pro.StepIt();

					Motor_locked_Vol= Motor_Vol_Locked*5.88;//电机堵转电压 = 采集电压*5.88
					Motor_locked_Cur=Motor_Cur_Locked;	    //电机堵转电流 = 采集电流
	          
					Motor_locked_Res= Motor_locked_Vol/ Motor_locked_Cur; //电机内阻=电机堵转电压/电机堵转电流

					Motor_Vol_S.Format(_T("%f"), Motor_locked_Vol);   //double型转换成字符串型
					Motor_Cur_S.Format(_T("%f"), Motor_locked_Cur);
					Motor_Res_S.Format(_T("%f"),Motor_locked_Res);

				    for(int k=0;k<500;k++)//步进数500
					 m_pro.StepIt(); //进度条步进函数

					if(m_pro.GetPos()==1000) //进度条步进到顶
					{
						MotorLocked_flag=0;//电机堵转结束
						Locked_Start=0;//堵转结束后，显示以下文字“堵转完成”
						str_Locked =_T("堵转完成"); 
						UpdateData(true);  //将控件的状态传给其关联的变量

						h2->SetWindowText(str_Locked);//静态文本文字改变
						//m_mscom.put_PortOpen(false);  //关闭串口
						CMotorDataSaveDlg LockedSaveDataTip;
						////LockedData_SaveTxt(L"堵转初始化数据.txt");
						INT_PTR nRes=LockedSaveDataTip.DoModal(); 
				
						if(nRes==IDOK)
						{
							LockedData_SaveTxt(L"堵转初始化数据.txt");  //保存数据

							Motor_Resfinish_flg=1;            //电机内阻计算完毕
							CGotoNormalTipDlg  NormalTip;      //弹出对话框
							NormalTip.DoModal();
						}
     
					}
				}
			}
	

		if ((jiaodu_flg==1)&&(Flag_check==1))		//开始启动角度程序运行
		{   
			//DataAnalysis_Mul(); //多极旋变角度（和，最大值，最小值）解算
			DataAnalysis_Rou(); //圆感应同步器角度（和，最大值，最小值）解算
			DataAnalysis_Enc(); //编码器角度（和，最大值，最小值）解算
		}
	  		
	}
 //}
}
/***********************************************************************/

/********************************启动运行***************************************/
void C机电调试V10Dlg::OnSerialOpen()
{
	// TODO: 在此添加控件通知处理程序代码
	//mode_choice=0;
	INT_PTR nRes;
	CModeChoiceDlg tipDlg;
	 nRes=tipDlg.DoModal();
	//int AD_Convert_data=_ttoi(AD_Convert);
	if(mode_choice==1)//正常模式
	{
	  if((str_Convert_AD==_T("电机/圆感应"))&&(Motor_Resfinish_flg==1)) 
		{
		
             Flag_Stop=0;
			
		 }
		else if((str_Convert_AD==_T("多极旋变")))
			Flag_Stop=0;
		else
			MessageBox(_T("电机模块运行前必须首先进行堵转操作!"));
	
    }

	 else 
	 {
		CDataChoiceDlg DataDlg;//弹出数据选择对话框
		DataDlg.DoModal(); 
	 }
}
/***********************************************************************/

/*******************************停止显示*********************************/
void C机电调试V10Dlg::OnSerialClose()
{	
	//m_mscom.put_PortOpen(false);          //关闭串口
	Flag_Stop=1;              //停止运行标志位，1表示软件已停止运行
}

/***********************************************************************/

/*******************************串口参数设置（调用对话框实例）********************************/
void C机电调试V10Dlg::OnSetAbout()    //点击菜单栏弹出串口参数设置对话框
{
	CSerialDlg tip;                        //弹出串口设置对话框
	tip.DoModal();
}
/******************************************************************************************/

/******************************版本（调用对话框实例）****************************************/
void C机电调试V10Dlg::OnCopyRight()
{
	// TODO: 在此添加命令处理程序代码
	CCopyRightDlg tip;
	tip.DoModal();
}
/***********************************************************************/

/******************************帮助（调用对话框实例）****************************************/
void C机电调试V10Dlg::OnHelp()
{
	CHelpDlg tip;
	tip.DoModal();
}

/******************************************************************************************/

/******************************打开文本*************************************/
void C机电调试V10Dlg::OnOpentxt()
{
	// TODO: 在此添加命令处理程序代码
	CFileDialog *lpszOpenFile;    //定义一个CfileDialog对象
 
    CStdioFile file;
    CString filePathName;
    CString result;
 
 
    //生成一个对话框
    lpszOpenFile = new CFileDialog
        (TRUE,_T(""),_T(""),OFN_FILEMUSTEXIST |OFN_HIDEREADONLY , _T("文件类型(*.txt)|*.txt|所有文件(*.*)|*.*|"));
     
    if(lpszOpenFile->DoModal() == IDOK )//假如点击对话框确定按钮
    {
        filePathName = lpszOpenFile->GetPathName();//得到打开文件的路径
        SetWindowText(filePathName);//在窗口标题上显示路径
    }
 
    if(filePathName == "") 
		return;
 
    if(!file.Open(filePathName,CFile::modeRead))
    {
        //MessageBox("can not open file!");
        return;
    }
 
	ShellExecute(NULL,_T("open"),filePathName,NULL,NULL,SW_SHOWNORMAL); //弹出文件路径选择对话框
    
     
    delete lpszOpenFile;//释放分配的对话框
}

void C机电调试V10Dlg::OnSaveData()
{	
	if(Flag_Save==1)
	  Flag_Save=0;
	else  Flag_Save=1;
}

/*************************************定时器（显示时间）第二步*****************************************/
void C机电调试V10Dlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
 if(1==nIDEvent)
{   
	CString sDate;
	m_EndTime=CTime::GetCurrentTime();
	CTime Today=CTime::GetCurrentTime();
	sDate=Today.Format(_T("\r\n\r\n\r\n\r\n\r\n%Y年%m月%d日\r\n%H:%M:%S"));
    int week=Today.GetDayOfWeek();
  //获取星期几，1为星期天，7为星期六
    switch(week)
	{
		case 1:{sDate=sDate+_T("\r\n星期日");break;}
		case 2:{sDate=sDate+_T("\r\n星期一");break;}
		case 3:{sDate=sDate+_T("\r\n星期二");break;}
		case 4:{sDate=sDate+_T("\r\n星期三");break;}
		case 5:{sDate=sDate+_T("\r\n星期四");break;}
		case 6:{sDate=sDate+_T("\r\n星期五");break;}
		case 7:{sDate=sDate+_T("\r\n星期六");break;}
	} 
	m_bar.SetPaneText(1,sDate); 	 
         //取得软件从开始到结束经过的秒数   
   CTimeSpan ctSpan = m_EndTime - m_beginTime; 
   CString strTime;  
         //格式化经过的时间  
   // strTime=Today.Format(_T("%H:%M:%S"));
    strTime.Format(_T("软件运行时间：%d时%d分%d秒"),ctSpan.GetHours(),ctSpan.GetMinutes(),ctSpan.GetSeconds());  
         //输出   
	m_bar.SetPaneText(2,strTime); 
	if(Flag_clear==1)
		Flag_clear=0;
	// if(Flag_Save==1)
 }          
  else if(2==nIDEvent)
  {  
	if(Flag_Save==1)//
	SaveTxt(L"机电调试数据.txt");
  }
  CDialogEx::OnTimer(nIDEvent);
}

/*******************************截图***********************************/
void C机电调试V10Dlg::OnCaptureScreen()
{
	 Screen("截图\\机电调试.jpg");
}
/***********************************************************************/

void C机电调试V10Dlg::Screen(char filename[])
{
	
	CWnd *pWnd= AfxGetMainWnd();
	CDC* pDC=pWnd->GetDC();
    int BitPerPixel = pDC->GetDeviceCaps(BITSPIXEL);//获得颜色模式
	CRect rect;
	GetClientRect(&rect);
	int Width = rect.Width();
	int Height = rect.Height();
    //printf("当前屏幕色彩模式为%d位色彩n", BitPerPixel);
   // printf("屏幕宽度：%dn", Width);
    //printf("屏幕高度：%dn", Height);
    
    CDC memDC;//内存DC
    memDC.CreateCompatibleDC(pDC);
    
    CBitmap memBitmap, *oldmemBitmap;//建立和屏幕兼容的bitmap
    memBitmap.CreateCompatibleBitmap(pDC, Width, Height);

    oldmemBitmap = memDC.SelectObject(&memBitmap);//将memBitmap选入内存DC
    memDC.BitBlt(0, 0, Width, Height, pDC, 0, 0, SRCCOPY);//复制屏幕图像到内存DC

    //以下代码保存memDC中的位图到文件
    BITMAP bmp;
    memBitmap.GetBitmap(&bmp);//获得位图信息
    
    FILE *fp = fopen(filename, "w+b");

    BITMAPINFOHEADER bih = {0};//位图信息头
    bih.biBitCount = bmp.bmBitsPixel;//每个像素字节大小
    bih.biCompression = BI_RGB;
    bih.biHeight = bmp.bmHeight;//高度
    bih.biPlanes = 1;
    bih.biSize = sizeof(BITMAPINFOHEADER);
    bih.biSizeImage = bmp.bmWidthBytes * bmp.bmHeight;//图像数据大小
    bih.biWidth = bmp.bmWidth;//宽度
    
    BITMAPFILEHEADER bfh = {0};//位图文件头
    bfh.bfOffBits = sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER);//到位图数据的偏移量
    bfh.bfSize = bfh.bfOffBits + bmp.bmWidthBytes * bmp.bmHeight;//文件总的大小
    bfh.bfType = (WORD)0x4d42;
    
    fwrite(&bfh, 1, sizeof(BITMAPFILEHEADER), fp);//写入位图文件头
    
    fwrite(&bih, 1, sizeof(BITMAPINFOHEADER), fp);//写入位图信息头
    
    byte * p = new byte[bmp.bmWidthBytes * bmp.bmHeight];//申请内存保存位图数据

    GetDIBits(memDC.m_hDC, (HBITMAP) memBitmap.m_hObject, 0, Height, p, 
        (LPBITMAPINFO) &bih, DIB_RGB_COLORS);//获取位图数据

    fwrite(p, 1, bmp.bmWidthBytes * bmp.bmHeight, fp);//写入位图数据

    delete [] p;

    fclose(fp);

    memDC.SelectObject(oldmemBitmap);
	ReleaseDC(pDC);

}

void  C机电调试V10Dlg::SaveTxt(CString filename)
{

	CString strVal;
	CStdioFile file;
	//filename=L"机电调试数据.txt";
	//file.Open(L"C:\\Documents and Settings\\Administrator\\桌面\\机电调试数据.txt",CFile::modeCreate|CFile::modeNoTruncate|CFile::modeReadWrite);
	//char* old_locale = _strdup( setlocale(LC_CTYPE,NULL) );
	//setlocale( LC_CTYPE, "chs" );//设定

	file.Open(filename,CFile::modeCreate|CFile::modeNoTruncate|CFile::modeReadWrite);
	char* old_locale = _strdup( setlocale(LC_CTYPE,NULL) );
	setlocale( LC_CTYPE, "chs" );//设定

	file.SeekToEnd();

	file.WriteString(_T("\n"));//正常写入

	file.WriteString(Mul_Angle+" " + " "+" ");//正常写入
	file.WriteString(Mul_Qua+" " + " "+" ");//正常写入
	file.WriteString(Mul_P_C+" " + " "+" ");//正常写入

	file.WriteString(Rou_Angle+" " + " "+" ");//正常写入
	file.WriteString(Rou_Qua+" " + " "+" ");//正常写入
	file.WriteString(Rou_P_C+" " + " "+" ");//正常写入

	
	file.WriteString(Enc_Angle+" " + " "+" ");//正常写入
	file.WriteString(Enc_Qua+" " + " "+" ");//正常写入
	file.WriteString(Enc_P_C+" " + " "+" ");//正常写入
	

	file.WriteString(Star_Vol_S+" " + " "+" ");//正常写入
	file.WriteString(Back_Elec_S+" " + " "+" ");//正常写入
	file.WriteString(Tor_Coe_S+" " + " "+" ");//正常写
	file.WriteString(Ror_Tor_S+" " + " "+" ");//正常写入
	file.WriteString(Mor_Cur+" " + " "+" ");//正常写入
	file.WriteString(Mor_Rev_Str +" " + " "+" ");//正常写入//滑行时间 暂用电机转速代替
	file.WriteString(Slip_Time+" " + " "+" "+"\n");//正常写入

	
	//file.WriteString(Enc_Qua+" " + " "+" ");//正常写入
	//file.WriteString(Enc_P_C+" " + " "+" "+"\n");//正常写入
//	Motor_Vol_S.Format(_T("%f"), Motor_locked_Vol);
//	 Star_Vol = floor(Star_Vol_l * 10000.000f + 0.5) / 10000.000f;//力矩系数
	//	 Back_Elec = floor(Back_Elec_c * 10000.000f + 0.5) / 10000.000f;
	//	 Tor_Coe = floor(Tor_Coe_e * 10000.000f + 0.5) / 10000.000f;//力矩系数
	//	 Ror_Tor = floor(Ror_Tor_r * 10000.000f + 0.5) / 10000.000f;
	setlocale( LC_CTYPE, old_locale );
	free( old_locale );//还原区域设定
	file.Close();

}
	
/*void C机电调试V10Dlg::DataAnalysis_Mul()
{	
	double Mul_Angle_d2;
	double Mul_Angle_d=_ttof(Mul_Angle_str);	
	Mul[count1++]= Mul_Angle_d;
	if(count1==2)
	{
	   if( (Mul[1]- Mul[2])>45.0)
       Mul_Angle_d2= Mul[2]; 
	   if((Mul[1]- Mul[2])<45.0)
	   Mul_Angle_d2= Mul[1];
	   Mul_Angle.Format(_T("%f"),  Mul_Angle_d2); 
	}

	if(count1==100)
	{
		count1=0;
		for(int i=0;i<100;i++)
		{
             //通道采集并得到通道的MV值
			if(max1<=Mul[i]){max1=Mul[i];pmax=i;} //求出最大值
			if(min1>=Mul[i]){min1=Mul[i];pmin=i;} //求出最小值
			sum1=sum1+Mul[i];                //求和
		}
			sum1=sum1/100.0;
	}

}*/

void C机电调试V10Dlg::DataAnalysis_Rou()
{

	double Rou_Angle_d=_ttof(Rou_Angle);	
	Rou[count2++]= Rou_Angle_d;
	
	if(count2==100)
	{
		count2=0;
		for(int i=0;i<100;i++)
		{
			 //通道采集并得到通道的MV值
			if(max2<=Rou[i]){max2=Rou[i];pmax=i;} //求出最大值
			if(min2>=Rou[i]){min2=Rou[i];pmin=i;} //求出最小值
			sum2=sum2+Rou[i];                //求和
		}
			sum2=sum2/100.0;
	}

}

void C机电调试V10Dlg::DataAnalysis_Enc()
{
	
	double Enc_Angle_d=_ttof(Enc_Angle);	
	Enc[count3++]= Enc_Angle_d;
	
	if(count3==100)
	{
		count3=0;
		for(int i=0;i<100;i++)
		{
			  //通道采集并得到通道的MV值
			if(max3<=Enc[i]){max3=Enc[i];pmax=i;} //求出最大值
			if(min3>=Enc[i]){min3=Enc[i];pmin=i;} //求出最小值
			sum3=sum3+Enc[i];                //求和
		}
			sum3=sum3/100.0;
	}

}
 

void C机电调试V10Dlg::DataAnalysis_MotorLocked1()
{
    count4++;
	double Locked_Para_d1=_ttof(Mor_Vol); //String型转换成double型	
	sum_locked1+= Locked_Para_d1;

	if(count4==10)
	{
		count4=0;
		sum_locked1=sum_locked1/10.0;
		Motor_Vol=sum_locked1; //采集10次电机电压求取平均值
		sum_locked1=0;
	}
}


void C机电调试V10Dlg::DataAnalysis_MotorLocked2()//电机参数计算函数，启动电压，反电动势，力矩系数 ，堵转力矩，输出转矩，力矩波动性
{
	count5++;
	double Locked_Para_d2=_ttof(Mor_Cur);	//字符串型转换成double型
	sum_locked2 += Locked_Para_d2;

	if(count5==10)   
	{
		count5 = 0;
		sum_locked2 = sum_locked2/10.0; 
		//MotorLocked_flag = 1;      //电流值每采10次求取平均值
		Motor_Cur = sum_locked2;
		sum_locked2 = 0;
		if(Flag_Stop == 0)  //软件未停止运行时
		{
	
		  //Motor_Cur= Motor_Cur/100;
			
			double Star_Vol_l  = Motor_Cur* Motor_locked_Res;     //启动电压=电机电流*电机内阻
			double Back_Elec_c = Motor_Vol*6.0 - Star_Vol;        //反电动势=电机电压AD采集值*6.0-启动电压
			double Tor_Coe_e   = (9.08*Back_Elec/Mor_Rev);        //力矩系数=（9.08*反电动势/电机转速）
			double Ror_Tor_r   = Tor_Coe*Motor_locked_Cur;        //堵转力矩=力矩系数*电机堵转电流
			double Tor_Flu_out = Tor_Coe*Motor_Cur;	              //输出转矩=力矩系数*电机电流
	        double Slip_Time_rr=0.12;
			Star_Vol_S.Format(_T("%f"),  Star_Vol);      //double型转换成字符串型
			Back_Elec_S.Format(_T("%f"), Back_Elec); 
			Tor_Coe_S.Format(_T("%f"),  Tor_Coe); 
			Ror_Tor_S.Format(_T("%f"),  Ror_Tor); 
			Slip_Time.Format(_T("%f"),  Slip_Time_rr); 
/*********************力矩波动性计算************************************/
		 //波动性=峰值-平均 
		 //sum_Flu=0;
			Para3[count6++] = Tor_Flu_out;
			if(count6==20)
			{
				count6 = 0;
				for(int i=0;i<20;i++)
				{
				  //通道采集并得到通道的MV值
					if(max4 <= Para3[i])   //采集20次后求出最大值
					{
						max4 = Para3[i];
					}
					
					 sum_Flu += Para3[i];  //求和
				}

				sum_Flu = sum_Flu/20.0;
				double Flu_r = sum_Flu;
				sum_Flu = 0;
	   
			
				Tor_Flu = floor((5- Flu_r) * 10000.000f + 0.5) / 10000.000f; //力矩波动性
			}
/*********************************************************/	

/***************保留小数点后四位*****************************************/
	  
		 Star_Vol = floor(Star_Vol_l * 10000.000f + 0.5) / 10000.000f;//力矩系数
		 Back_Elec = floor(Back_Elec_c * 10000.000f + 0.5) / 10000.000f;
		 Tor_Coe = floor(Tor_Coe_e * 10000.000f + 0.5) / 10000.000f;//力矩系数
		 Ror_Tor = floor(Ror_Tor_r * 10000.000f + 0.5) / 10000.000f;
	}
  }
}

void C机电调试V10Dlg::OnClearData()
{

	    Flag_clear=1;
	    Mul_Angle=_T("0");
		Mul_Qua=_T("0");
		Mul_P_C=_T("0");

		Rou_Angle=_T("0");
		Rou_Qua=_T("0");
		Rou_P_C=_T("0");

		Enc_Angle=_T("0");
		Enc_Qua=_T("0");
		Enc_P_C=_T("0");
	  
		sum1=0.0;
		max1=0.0000;
		min1=370.0000;

		sum2=0.0;
		max2=0.0000;
		min2=370.0000;

		sum3=0.0;
		max3=0.0000;
		min3=370.0000;

		Mor_Vol=_T("0");//电机电压中间变量
		Mor_Cur=_T("0");//电机电流中间变量
		Mor_Rev_Str=_T("0");//电机转速中间变量
}


void C机电调试V10Dlg::OnLockedDataCalcu()
{
	// TODO: 在此添加命令处理程序代码
	
if(mode_choice==0)//电机初始化模式
{	
	//m_mscom.put_PortOpen(false);          //关闭串口
	
	Locked_Start=1;//堵转开始进行
	str_Locked=_T("堵转进行中···"); 
	UpdateData(true);  
	h2->SetWindowText(str_Locked);
/*    CString str,str1,n;	
	//INT_PTR nRes;//定义字符串
	GetDlgItemText(IDC_Serial_OPEN,str);
	CWnd *h1;
	h1=GetDlgItem(IDC_Serial_OPEN);		//指向控件的caption
	if(!m_mscom.get_PortOpen())
	{
		m_mscom.put_CommPort(com);	    //选择串口
		m_mscom.put_InputMode(1);		//设置输入方式为二进制方式
		m_mscom.put_Settings(str5);		//波特率为（波特率组合框）无校验，8数据位，1个停止位
		m_mscom.put_InputLen(1024);		//设置当前接收区数据长度为1024
		m_mscom.put_RThreshold(75);		//缓冲区七十五字符引发事件
		
		//m_mscom.put_RTSEnable(1);		//设置RT允许
			
		m_mscom.put_PortOpen(true);		//打开串口
		
	}
*/
  }

   else MessageBox(_T("请在电机参数初始化模式下运行此功能!"));
}
void  C机电调试V10Dlg::LockedData_SaveTxt(CString filename)
{

	CString strVal;
	CStdioFile file;

	CString strVall1=_T("堵转电压");
	CString strVall2=_T("堵转电流");
	CString strVall3=_T("电机电阻");

	//filename=L"机电调试数据.txt";
	//file.Open(L"C:\\Documents and Settings\\Administrator\\桌面\\机电调试数据.txt",CFile::modeCreate|CFile::modeNoTruncate|CFile::modeReadWrite);
	//char* old_locale = _strdup( setlocale(LC_CTYPE,NULL) );
	//setlocale( LC_CTYPE, "chs" );//设定

	file.Open(filename,CFile::modeCreate|CFile::modeNoTruncate|CFile::modeReadWrite);
	char* old_locale = _strdup( setlocale(LC_CTYPE,NULL) );
	setlocale( LC_CTYPE, "chs" );//设定
	/*file.Open(L"机电调试数据.txt",CFile::modeCreate|CFile::modeNoTruncate|CFile::modeReadWrite);
	char* old_locale = _strdup( setlocale(LC_CTYPE,NULL) );*/
	//file.SeekToEnd();
	file.WriteString(_T("\n"));//正常写入

	file.WriteString( strVall1+ " " + " "+" "+Motor_Vol_S+"\n");//正常写入

	file.WriteString( strVall2+ " " + " "+" "+Motor_Cur_S+"\n");//正常写入
	file.WriteString( strVall3+" " + " "+" "+Motor_Res_S);       //正常写入
	//file.WriteString(Rou_Angle+" " + " "+" ");//正常写入
	//file.WriteString(Rou_Qua+" " + " "+" ");//正常写入
	//file.WriteString(Rou_P_C+" " + " "+" ");//正常写入

	//
	//file.WriteString(Enc_Angle+" " + " "+" ");//正常写入
	//file.WriteString(Enc_Qua+" " + " "+" ");//正常写入
	//file.WriteString(Enc_P_C+" " + " "+" "+"\n");//正常写入
	//
	setlocale( LC_CTYPE, old_locale );
	free( old_locale );//还原区域设定
	file.Close();

}

void C机电调试V10Dlg::OnTestObjButton()
{	
	//改变按钮名称
	int nHeadPos = AD_Convert.Find(_T("1"));
	if( nHeadPos==-1)
	{
		Moto_Mul_Flag=_T("C");
		AD_Convert=_T("1");
		str_Convert_AD=_T("多极旋变"); 
		UpdateData(true);  
		h3->SetWindowText(str_Convert_AD);//改变按钮名称为电机/圆感应
	}
	
	else// if( nHeadPos==1)
	{
		Moto_Mul_Flag=_T("B"); 
		AD_Convert=_T("0");
		str_Convert_AD=_T("电机/圆感应"); 
		UpdateData(true);  
		h3->SetWindowText(str_Convert_AD);//改变按钮名称为电机/圆感应
	}
	m_mscom.put_Output(COleVariant(AD_Convert));


}

/********开机函数（打开串口）***********/
void C机电调试V10Dlg::OnOpenCheck()                  
{
	// TODO: 在此添加命令处理程序代码



	/********开机程序（打开串口）***********/
	if(!m_mscom.get_PortOpen())
	{
		m_mscom.put_CommPort(com);	    //选择串口
		m_mscom.put_InputMode(1);		//设置输入方式为二进制方式
		m_mscom.put_Settings(str5);		//波特率为（波特率组合框）无校验，8数据位，1个停止位
		m_mscom.put_InputLen(1024);		//设置当前接收区数据长度为1024
		m_mscom.put_RThreshold(75);		//缓冲区七十五字符引发事件
		
		//m_mscom.put_RTSEnable(1);		//设置RT允许
			
		m_mscom.put_PortOpen(true);		//打开串口
		
	}

/********调用自检类型选择对话框******************************************************/
/********该对话框完成开机自检类型的选择**********************************************/
	INT_PTR nRes;
	CheckChoiceDlg tipDlg;
	nRes=tipDlg.DoModal();
/************************************************************************************
		上位机给下位机发送命令，从而选择数据采集类型（电机还是旋转变压器）
*************************************************************************************/
	if(Selftest_choice==0)                             //电机圆感应模式
	{
	  
	   Moto_Mul_Flag=_T("B");                          //电机/旋变自检程序调用标志位
	   str_Convert_AD=_T("电机/圆感应"); 
	   UpdateData(true);  
	   h3->SetWindowText(str_Convert_AD);//改变按钮名称为电机/圆感应
	   m_mscom.put_Output(COleVariant(_T("0")));     //程序默认即为此状态，无需发送数据
	}
	else                                                //旋转变压器模式
	{
	   Moto_Mul_Flag=_T("C");
	   str_Convert_AD=_T("多极旋变"); 
	   UpdateData(true);  
	   h3->SetWindowText(str_Convert_AD);               //改变按钮名称为多极旋变
	   m_mscom.put_Output(COleVariant(_T("1")));        //通过串口向下位机发送数据，下位机程序运行旋转变压器的
	  
	}
/************************************************************************************/
}


void C机电调试V10Dlg::OnEvaluate()
{
	
	INT_PTR nRess;
	CEvaluateChoiceDlg EvaluateChoiceDlg; 
	 nRess=EvaluateChoiceDlg.DoModal();
	//int AD_Convert_data=_ttoi(AD_Convert);
	if(Evaluate_Mode_Choice==1)//正常模式
	{
	  Angle_Evalu_list tdlg;
	  tdlg.DoModal();
	
    }

	 else 
	 {
		//CDataChoiceDlg DataDlg;//弹出数据选择对话框
		//DataDlg.DoModal(); 
	 }

}
/*************************************************************************/

//电机/圆感应自检程序
void C机电调试V10Dlg::Moto_Mul_Check()
{
	double Mor_Vol_dd=_ttof(Mor_Vol);//字符串转换成double型

			if(Mor_Vol_dd>2)
			{
				IDC_MOTOR_POWER.SetIcon(m_hIcon_yes);//电机自检上电
			}
			else
			{
				IDC_MOTOR_POWER.SetIcon(m_hIcon_no);
			}
			if((Mor_Vol_dd >2)&&(Mor_Rev<20))
			{
				IDC_Moto_Lim.SetIcon(m_hIcon_yes);//电机自检旋转不受限
			}
			else 
			{
				IDC_Moto_Lim.SetIcon(m_hIcon_no);
			}



    double Yuan_Ang_dd=_ttof(Rou_Angle);//字符串转换成double型

	       if(Yuan_Ang_dd != 0.0)
			{
				IDC_Yuangan_Power.SetIcon(m_hIcon_yes);//圆感应自检上电
			}
			else
			{
				IDC_Yuangan_Power.SetIcon(m_hIcon_no);;
			}
     //   double Yuan_Angle[2];
  
	 Yuan_Angle[yu++]=Yuan_Ang_dd;//字符串转换成double型
	   if(yu==2)
	  {	  yu=0; 
		  double angle1=(  Yuan_Angle[0]- Yuan_Angle[1]);
		         angle1=-angle1;
		  if(angle1 != 0.0)
			{
				IDC_Yuangan_Angle.SetIcon(m_hIcon_yes);//圆感应输出正常
			}
			else
			{
				IDC_Yuangan_Angle.SetIcon(m_hIcon_no);
			}
	   }
}

void C机电调试V10Dlg::Xuanbian_Check()
{
    double Xuan_Ang_dd=_ttof(Mul_Angle);//字符串转换成double型

	       if(Xuan_Ang_dd != 0.0)
			{
				IDC_Xuanbian_Power.SetIcon(m_hIcon_yes);//电机自检上电
			}
			else
			{
				IDC_Xuanbian_Power.SetIcon(m_hIcon_no);;
			}
       
     Xuan_Angle[xu++]= Xuan_Ang_dd;
	
	  if(xu==2)
	   {
		  xu=0;
		   double angle2=(Xuan_Angle[0]-Xuan_Angle[1]);
		         angle2=-angle2;
		  if(angle2 != 0.0)
			{
				//IDC_Xuanbian_Power.SetIcon(m_hIcon_yes);
				IDC_Xuanbian_Angle.SetIcon(m_hIcon_yes);//电机自检上电
			}
			else
			{
				IDC_Xuanbian_Angle.SetIcon(m_hIcon_no);;
			}

       }
}

void C机电调试V10Dlg::Guangshan_Check()
{
    double Guang_Ang_dd=_ttof(Enc_Angle);//字符串转换成double型

	       if(Guang_Ang_dd != 0.0)
			{
				IDC_Guangshan_Power.SetIcon(m_hIcon_yes);//电机自检上电
			}
			else
			{
				IDC_Guangshan_Power.SetIcon(m_hIcon_no);
			}
       
     Guang_Angle[gu++]= Guang_Ang_dd;
	
	  if(gu==2)
	   {
		  gu=0;
		   double angle3=(Guang_Angle[0]-Guang_Angle[1]);
		         angle3=-angle3;
		  if(angle3 != 0.0)
			{
				IDC_Guangshan_Angle.SetIcon(m_hIcon_yes);//电机自检上电
			}
			else
			{
				IDC_Guangshan_Angle.SetIcon(m_hIcon_no);
			}

       }
}

