
// 机电调试V1.0Dlg.h : 头文件
//

#pragma once
#include "afxwin.h"
#include "mscomm1.h"
#include "afxcmn.h"
#include "C电机Dlg.h"
#include "C角度传感器Dlg.h"
 
#define WM_USERMESSAGE WM_USER+101 //WM_USERMESSAGE为自己定义的消息名称
// C机电调试V10Dlg 对话框
class C机电调试V10Dlg : public CDialogEx
{
// 构造
public:
	C机电调试V10Dlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_V10_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
private:

	CComboBox m_comb1;
	CComboBox m_comb2;
public:
	CMscomm1 m_mscom;

	//afx_msg void OnBnClickedButtonOpen();
	//afx_msg void OnBnClickedButtonSend();
//	afx_msg void OnBnClickedButtonClear();
	DECLARE_EVENTSINK_MAP()
	void OnCommMscomm1();
	afx_msg void OnSetAbout();

	CTabCtrl m_tab;
	C电机Dlg m_motorDlg;//电机界面tab的成员变量
	C角度传感器Dlg m_AngleDlg;//角度传感器界面tab的成员变量
	CStatusBar m_bar;
public:

	CString Tor_Coee;//力矩系数中间变量
	CString Tor_Pre; //力矩系数精度中间变量

	CString Star_Vol_Str;//启动电压中间变量
	CString Star_Pre;//启动电压精度中间变量
	CString Star_Voll;////////////////////////////////////
	//CString Back_Elec;//反电动势中间变量
	CString Back_Pre;//反电动势精度中间变量

	CString Slip_Time;//滑行时间中间变量
	CString Slip_Pre;//滑行时间精度中间变量

	CString Ror_Tor_Str;//堵转力矩中间变量
	CString Ror_Pre;//堵转力矩精度中间变量

	CString Mor_Cur;//电机电流中间变量
	CString Cur_Pre;//电机电流精度中间变量

	CString Tor_Flu_Str;//力矩波动性中间变量
	CString Flu_Pre;//力矩波动性精度中间变量

	CString Mor_Rev_Str;//电机转速中间变量
	CString Mor_Rev_Direc;
	int    Flag_Save;   //保存数据
	double Star_Vol; //启动电压
	double Back_Elec;//反电动势
	double Tor_Coe;  //力矩系数
	double Mor_Rev;  //电机转速
	double Ror_Tor;    //堵转力矩
	double Tor_Flu;    //输出转矩
	CString Mor_Vol;//电机电压中间变量

public:

	CToolBar m_ToolBar;
	static C机电调试V10Dlg *motorDialog;  ////////////////////////1//定义指针  
	void chuli();
	void Screen(char filename[]);
	void  SaveTxt(CString filename);
	void  LockedData_SaveTxt(CString filename);

	void DataAnalysis_Mul();
	void DataAnalysis_Rou();
	void DataAnalysis_Enc();
    void DataAnalysis_MotorLocked1();
	void DataAnalysis_MotorLocked2();
	void Moto_Mul_Check();
	void Xuanbian_Check();
    void Guangshan_Check();
public:

	/*光电编码器各参数对应变量*/
	
	CString  Enc_Angle;//角度中间变量
	CString  Enc_Qua;//象限中间变量
	CString  Enc_Pre;//角位置精度中间变量
	CString  Enc_Rev;//转速中间变量
	CString  Enc_P_C;//正反转中间变量
	CString  Enc_Eff;//轴系安装效果中间变量

	/*圆感应同步器各参数对应变量*/
	
	CString Rou_Angle;//角度中间变量
	CString Rou_Qua;//象限中间变量
	CString Rou_P_C;//正反转中间变量
	CString Rou_Pre;//角位置精度中间变量
	CString Rou_Eff;//轴系安装效果中间变量

	/*多极旋转变压器各参数对应变量*/
	CString Mul_Angle_str;
	CString Mul_Angle;//角度中间变量
	CString Mul_Qua;//象限中间变量
	CString Mul_P_C;//正反转中间变量
	CString Mul_Pre;//角位置精度中间变量
	CString Mul_Eff;//轴系安装效果中间变量

public:

	CString m_shuju;
	static C机电调试V10Dlg *AngleDialog;  ////////////////////////1//定义指针  
	CTime m_beginTime;//软件启动时间
    CTime m_EndTime;//软件结束时间

public:
	afx_msg void OnTcnSelchangeTab(NMHDR *pNMHDR, LRESULT *pResult);

	afx_msg void OnCallSerial();
	afx_msg void OnSerialOpen();
	afx_msg void OnSerialClose();
	afx_msg void OnSaveData();
	afx_msg void OnCopyRight();
	afx_msg void OnOpentxt();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnClose();
	afx_msg void OnHelp();
	afx_msg void OnStnClickedStatic2();
	void OnAfterDrawTchart4();

//public:
//    CString Mul_Angle;
//
//	CString Rou_Angle;
//	CString Enc_Angle;


	afx_msg void OnCaptureScreen();
	afx_msg void OnClearData();
	afx_msg void OnLockedDataCalcu();
	CProgressCtrl m_pro;

public:


	CString  Motor_Vol_S;
	CString  Motor_Cur_S;
	CString  Motor_Res_S;
	//double Motor_Vol;//堵转电机电压
	//double Motor_Cur;//堵转电机电流
	//double Motor_Res;//堵转电机电阻
	//afx_msg void OnMotorButton();
	afx_msg void OnTestObjButton();
	HICON m_hIcon_yes;

    HICON m_hIcon_no;

	
	CStatic IDC_MOTOR_POWER;
	
	CStatic IDC_Moto_Lim;
	afx_msg void OnOpenCheck();
	afx_msg void OnEvaluate();
	//CStatic IDC_Yuangan_POWER;
	//CStatic IDC_Yuangan_Angle;

	CStatic IDC_Xuanbian_Power;
	CStatic IDC_Xuanbian_Angle;
	CStatic IDC_Guangshan_Power;
	CStatic IDC_Guangshan_Angle;
	CStatic IDC_Yuangan_Power;
	CStatic IDC_Yuangan_Angle;
};
