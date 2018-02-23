#pragma once
#include "tchart1.h"


// C电机Dlg 对话框

class C电机Dlg : public CDialogEx
{
	DECLARE_DYNAMIC(C电机Dlg)

public:
	C电机Dlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~C电机Dlg();

// 对话框数据
	enum { IDD = IDD_MORTOR_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()

//public:
//	afx_msg void OnBnClickedUpdateButton();
//	afx_msg void OnEnChangeRorPreEdit();

	
//	CString m_Edit_Mor_Eff;
	//轴系安装效果

	
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
private:
	//CString m_Edit_Tor_Coe;	//力矩系数
	//CString m_Edit_Tor_Pre;//力矩系数精度

	//CString m_Edit_Star_Vol;	//启动电压
	//CString m_Edit_Star_Pre;//启动电压精度

	//CString m_Edit_Back_Elec;//反电动势
	//CString m_Edit_Back_Pre;//反电动势精度

	CString m_Edit_Slip_Time;//滑行时间
	//CString m_Edit_Slip_Pre;//滑行时间精度

	//CString m_Edit_Ror_Tor;//堵转力矩
	//CString m_Edit_Ror_Pre;//堵转力矩精度

	CString m_Edit_Mor_Cur1;//电机电流1
	//CString m_Edit_Cur_Pre1;//电机电流1精度

	CString m_Edit_Mor_Cur2;//电机电流2
	//CString m_Edit_Cur_Pre2;//电机电流2精度

	//CString m_Edit_Mor_Rev1;//电机转速1
	//CString m_Edit_Mor_Rev2;//电机转速2
	
	//CString m_Edit_Tor_Flu_Pro;//力矩波动性
	//CString m_Edit_Flu_Pre;//力矩波动性精度
	CString m_Edit_Mor_Eff;//电机轴系安装效果

	CTchart1 m_Tchart_Tor_Coe;//力矩系数计
	CTchart1 m_Tchart_Star_Vol;//启动电压计
	CTchart1 m_Tchart_Back_Elec;//反电动势计
	CTchart1 m_Tchart_Slip_Time;//滑行时间计
	CTchart1 m_Tchart_Ror_Tor;//堵转力矩计
	CTchart1 m_Tchart_Mor_Cur1;//电机电流1计
	CTchart1 m_Tchart_Mor_Rev1;//电机转速1计

	CTchart1 m_Tchart_Mor_Rev2;//电机转速2曲线
	CTchart1 m_Tchart_Mor_Cur2;//电机电流2曲线
	CTchart1 m_Tchart_Tor_Flu_Pro;//力矩波动性曲线

public:

	double Tor_Coe_d;//力矩系数
	double Star_Vol_d;//启动电压
	
//	double Star_Pre_d;//启动电压精度

	double Back_Elec_d;//反电动势
	//double Back_Pre_d;//反电动势精度

	double Ror_Tor_d;//堵转力矩
//	double Ror_Pre_d;//堵转力矩精度

	double Slip_Time_d;//滑行时间
//	double Slip_Pre_d;//滑行时间精度

	double Mor_Cur_d;//电机电流
//	double Cur_Pre1_d;//电机电流精度
//	double Cur_Pre2_d;//电机电流精度

	double Mor_Rev_d;//电机转速
	
	double Tor_Flu_d;//力矩波动性
	//double Flu_Pre_d;//力矩波动性精度

public:
	void MortorDataDisplay();
	void GraphDraw_Motor();
	double m_Edit_Star_Vol;        
	double m_Edit_Back_Elec;
	double m_Edit_Mor_Rev1;
	double m_Edit_Mor_Rev2;//电机转速2
	double m_Edit_Tor_Coe;
	double m_Edit_Ror_Tor;
	double Edit_tor_Flu;

	CString m_Edit_Direc;


	//afx_msg void OnStnClickedTorFluProEdit();
	//afx_msg void OnStnClickedMorRev2Edit();
};
