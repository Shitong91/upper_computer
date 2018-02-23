// Angle_Evalu_list.cpp : 实现文件
//

#include "stdafx.h"
#include "机电调试V1.0.h"
#include "Angle_Evalu_list.h"
#include "afxdialogex.h"
#include "Evalute_Angle_Seris.h"
CString str_Eva;	
// Angle_Evalu_list 对话框

IMPLEMENT_DYNAMIC(Angle_Evalu_list, CDialogEx)

Angle_Evalu_list::Angle_Evalu_list(CWnd* pParent /*=NULL*/)
	: CDialogEx(Angle_Evalu_list::IDD, pParent)

	
{

}

Angle_Evalu_list::~Angle_Evalu_list()
{
}

void Angle_Evalu_list::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_Angle_LIST, Angle_list);
	DDX_Control(pDX, IDC_EDIT2, m_Angle_list);



	//DDX_Control(pDX, IDC_Eva_An_TCHART3, m_Tchart_Angle);
	//DDX_Control(pDX, IDC_TCHART5, m_Tchart_Angle);
}


BEGIN_MESSAGE_MAP(Angle_Evalu_list, CDialogEx)
	ON_NOTIFY(NM_DBLCLK, IDC_Angle_LIST, &Angle_Evalu_list::OnNMClickAngleList)

	ON_EN_KILLFOCUS(IDC_EDIT2, &Angle_Evalu_list::OnEnKillfocusEdit2)
	ON_BN_CLICKED(IDC_Start_BUTTON, &Angle_Evalu_list::OnBnClickedStartButton)
	ON_BN_CLICKED(IDC_bia_BUTTON, &Angle_Evalu_list::OnBnClickedbiaButton)
END_MESSAGE_MAP()


// Angle_Evalu_list 消息处理程序


BOOL Angle_Evalu_list::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化

	str_Eva=_T("暂停");
	CRect rect;   
  
    // 获取编程语言列表视图控件的位置和大小   
    Angle_list.GetClientRect(&rect);   
  
    // 为列表视图控件添加全行选中和栅格风格   
    Angle_list.SetExtendedStyle(Angle_list.GetExtendedStyle() | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);   
  
    // 为列表视图控件添加三列   
    Angle_list.InsertColumn(0, _T("序号"), LVCFMT_CENTER, rect.Width()/5, 0);   
    Angle_list.InsertColumn(1, _T("给定角"), LVCFMT_CENTER, rect.Width()/5, 1);   
    Angle_list.InsertColumn(2, _T("测定角"), LVCFMT_CENTER, rect.Width()/5, 2); 
	Angle_list.InsertColumn(3, _T("准自直"), LVCFMT_CENTER, rect.Width()/5, 3);   
    Angle_list.InsertColumn(4, _T("误差角"), LVCFMT_CENTER, rect.Width()/5, 4);
  
    // 在列表视图控件中插入列表项，并设置列表子项文本   
    Angle_list.InsertItem(0, _T("1"));   
   // m_programLangList.SetItemText(0, 1, _T("1"));   
    //m_programLangList.SetItemText(0, 2, _T("1"));   
   Angle_list.InsertItem(1, _T("2"));   
   // m_programLangList.SetItemText(1, 1, _T("2"));   
   // m_programLangList.SetItemText(1, 2, _T("2"));   
    Angle_list.InsertItem(2, _T("3"));   
   // m_programLangList.SetItemText(2, 1, _T("3"));   
   // m_programLangList.SetItemText(2, 2, _T("6"));   
   Angle_list.InsertItem(3, _T("4"));   
  //  m_programLangList.SetItemText(3, 1, _T("4"));   
   // m_programLangList.SetItemText(3, 2, _T("3"))
   Angle_list.InsertItem(4, _T("5")); 

   Angle_list.InsertItem(5, _T("6")); 
   Angle_list.InsertItem(6, _T("7"));
   Angle_list.InsertItem(7, _T("8")); 
  // Angle_list.InsertItem(7, _T("9")); 
   
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}

 int  m_Row  ; 
   int  m_Col;
void Angle_Evalu_list::OnNMClickAngleList(NMHDR *pNMHDR, LRESULT *pResult)
{

	NM_LISTVIEW* pNMListView=(NM_LISTVIEW*)pNMHDR;  
    CRect rc;  
     m_Row = pNMListView->iItem;//获得选中的行  
     m_Col = pNMListView->iSubItem;//获得选中列  
  
  
    if   (pNMListView->iSubItem != 0) //如果选择的是子项;  
    {  
        Angle_list.GetSubItemRect(m_Row,m_Col,LVIR_LABEL,rc);//获得子项的RECT；  
        m_Angle_list.SetParent(&Angle_list);//转换坐标为列表框中的坐标  
        m_Angle_list.MoveWindow(rc);//移动Edit到RECT坐在的位置;  
        m_Angle_list.SetWindowText(Angle_list.GetItemText(m_Row,m_Col));//将该子项中的值放在Edit控件中；  
        m_Angle_list.ShowWindow(SW_SHOW);//显示Edit控件；  
        m_Angle_list.SetFocus();//设置Edit焦点  
        m_Angle_list.ShowCaret();//显示光标  
        m_Angle_list.SetSel(-1);//将光标移动到最后  
  
  
    }  
  
	*pResult = 0;
}




void Angle_Evalu_list::OnEnKillfocusEdit2()
{
	// TODO: 在此添加控件通知处理程序代码
	CString tem;  
    m_Angle_list.GetWindowText(tem);    //得到用户输入的新的内容  
    Angle_list.SetItemText(m_Row,m_Col,tem);   //设置编辑框的新内容  
    m_Angle_list.ShowWindow(SW_HIDE); 
}


void Angle_Evalu_list::OnBnClickedStartButton()
{
	// TODO: 在此添加控件通知处理程序代码
	GetDlgItemText(IDC_Start_BUTTON,str_Eva);
	CWnd *h1;
	h1=GetDlgItem(IDC_Start_BUTTON);		//指向控件的caption
  if(str_Eva==_T("暂停"))
	{ 
		str_Eva=_T("开始");
		Flag_Stop=1;
		UpdateData(true);
	h1->SetWindowText(str_Eva);
	}
  else if(str_Eva==_T("开始"))
	{
	    str_Eva=_T("暂停");
		Flag_Stop=0;
	UpdateData(true);
	h1->SetWindowText(str_Eva);
	}
	
	
	
	///UpdateData(true);
	//h1->SetWindowText(str_Eva);			//改变按钮名称为‘’关闭串口”
	
}

CString Angle;
void Angle_Evalu_list::OnBnClickedbiaButton()
{
	// TODO: 在此添加控件通知处理程序代码
	
	CString bia_str[8];
    int i=0;
	for(i=0;i<=7;i++)
	  for(int j=1;j<=3;j++)
	{
	  
		CString Angle =  Angle_list.GetItemText(i,j);
		Ang_Cacul[i][j]=_ttof(Angle);
	}
	
	  for(int k=0;k<=7;k++)
      //for(int l=1;l<=3;l++)
	  {  bia[k]=Ang_Cacul[k][1]-Ang_Cacul[k][2]-Ang_Cacul[k][3];
	    // Angle_list.InsertItem(k,3 _T("6"));
	     bia_str[k].Format(_T("%f"),  bia[k]);
		 Angle_list.SetItemText(k,4,(bia_str[k]));
		 
	  }
	  Evalute_Angle_Seris dlg;
	  dlg.DoModal();

	//((CSeries)Evalu_Angle_chart.Series(0)).Add(,_T(""),0);
	//for(int i=0; i<8; i++)  
   //((CSeries)Evalu_Angle_chart.Series(0)).AddXY(Ang_Cacul[i][1],bia[i], NULL, RGB(255,0,255));  //AddXY函数中第一个参数是X轴的数据，第二个参数是Y轴的数据，  
//第三个参数是X轴标记，第四个参数表示线条的颜色，rand()%10,表示生成10以内的随机数  
}
