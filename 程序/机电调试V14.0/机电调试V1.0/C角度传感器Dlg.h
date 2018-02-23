#pragma once
#include "tchart1.h"
#include "afxwin.h"


// C角度传感器Dlg 对话框
#define WM_USERMESSAGE WM_USER+101 //WM_USERMESSAGE为自己定义的消息名称
class C角度传感器Dlg : public CDialogEx
{
	DECLARE_DYNAMIC(C角度传感器Dlg)

public:
	C角度传感器Dlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~C角度传感器Dlg();

// 对话框数据
	enum { IDD = IDD_Angle_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()

private:

	/*光电编码器各参数对应变量*/
	CString m_Static_Enc_Angle;//角度
	CString m_Edit_Enc_Qua;//象限
	//CString m_Edit_Enc_Pre;//角位置精度
	CString m_Edit_Enc_P_C;//正反转
	//CString m_Edit_Enc_Eff;//轴系安装效果

	/*圆感应同步器各参数对应变量*/
	CString m_Static_Rou_Angle;//角度
	CString m_Edit_Rou_Qua;//象限
	CString m_Edit_Rou_P_C;//正反转
	//CString m_Edit_Rou_Pre;//角位置精度
	//CString m_Edit_Rou_Eff;//轴系安装效果

	/*多极旋转变压器各参数对应变量*/
	CString m_Static_Mul_Angle;//角度
	CString m_Edit_Mul_Qua;//象限
	CString m_Edit_Mul_P_C;//正反转
	//CString m_Edit_Mul_Pre;//角位置精度
	//CString m_Edit_Mul_Eff;//轴系安装效果

public:

	afx_msg void OnTimer(UINT_PTR nIDEvent);

public:
	virtual BOOL OnInitDialog();

public:
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	CTchart1 m_Tchart1;
	CTchart1 m_Tchart2;
	CTchart1 m_Tchart3;
	
public:
	double Mul_Angle_d;

	double Rou_Angle_d;

	double Enc_Angle_d;

	
	void DataDisplay( UINT IDD,double max,double sum,double min);

public:	
	void GraphDraw();
private:
	CTchart1 m_Chart_Graph;
public:
	
	DECLARE_EVENTSINK_MAP()
	void OnMouseMoveTchartGraph(long Shift, long X, long Y);
	

private:

	CButton m_Check_Rou;
	CButton m_Check_Enc;
	CButton m_Check_Mul;
public:
	//afx_msg void OnEnChangeEncPCEdit();
};
