// CCALC.cpp: 实现文件
//

#include "pch.h"
#include "StudyzbMFCPartGruop.h"
#include "CCALC.h"
#include "afxdialogex.h"


// CCALC 对话框

IMPLEMENT_DYNAMIC(CCALC, CDialogEx)

CCALC::CCALC(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_CCALC, pParent)
	, calcStartFirst(_T(""))
	, clacStartSecond(_T(""))
	, clacEnd(_T(""))
	, opt(0)
{

}

CCALC::~CCALC()
{
}

void CCALC::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, calcStartFirst);
	DDX_Text(pDX, IDC_EDIT2, clacStartSecond);
	DDX_Text(pDX, IDC_EDIT3, clacEnd);
	DDX_CBIndex(pDX, IDC_COMBO1, opt);
}


BEGIN_MESSAGE_MAP(CCALC, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CCALC::OnBnClickedButton1)
END_MESSAGE_MAP()


// CCALC 消息处理程序


void CCALC::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);
	float clacStartValFirst, clacStartValSecond, calcEndVal;
	clacStartValFirst = atof(calcStartFirst);
	clacStartValSecond = atof(clacStartSecond);
	switch (opt)
	{
	case 0:calcEndVal = clacStartValFirst + clacStartValSecond; break;
	case 1:calcEndVal = clacStartValFirst - clacStartValSecond; break;
	case 2:calcEndVal = clacStartValFirst * clacStartValSecond; break;
	case 3:
		if(clacStartValSecond == 0)
		{
			clacEnd = "ERROR"; 
			UpdateData(false); 
			return;
		}
		calcEndVal = clacStartValFirst / clacStartValSecond; break;
	default: clacEnd = "ERROR"; UpdateData(false); return;
	}
	clacEnd.Format("%.2f", calcEndVal);
	UpdateData(false);
}
