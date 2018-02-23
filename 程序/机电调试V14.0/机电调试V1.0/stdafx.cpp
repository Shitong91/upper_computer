
// stdafx.cpp : 只包括标准包含文件的源文件
// 机电调试V1.0.pch 将作为预编译头
// stdafx.obj 将包含预编译类型信息

#include "stdafx.h"


short com;

CString str5;
int Flag_Stop; //停止运行标志位

double sum1=0.0;
double max1=0.0000;
double min1=370.0000;

double sum2=0.0;
double max2=0.0000;
double min2=370.0000;

double sum3=0.0;
double max3=0.0000;
double min3=370.0000;
int  mode_choice=1;
int  Motor_Resfinish_flg=0; // 电机内阻计算完成标志位

double Motor_locked_Vol=0.0;//电机电压
double Motor_locked_Cur=0.0;//电机电流
double Motor_locked_Res=0.0;//堵转电机电阻

int jiaodu_flg=0;            //角度程序运行标志位
//int seria_Stop=0;
int Selftest_choice=0;
int  Evaluate_Mode_Choice=0;
int jindu=0;
double Ang_Cacul[8][4];
double bia[8];