// CLightControl.cpp: 实现文件
//

#include "pch.h"
#include "StudyzbMFCPartGruop.h"
#include "CLightControl.h"
#include "afxdialogex.h"


// CLightControl 对话框

IMPLEMENT_DYNAMIC(CLightControl, CDialogEx)

CLightControl::CLightControl(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_CLightControl, pParent)
	, tRed(5000)
	, tYellow(2000)
	, tGreen(3000)
	, mode(2)
{

}

CLightControl::~CLightControl()
{
}

void CLightControl::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_RED, picRed);
	DDX_Control(pDX, IDC_YELLOW, picYellow);
	DDX_Control(pDX, IDC_GREEN, picGreen);
	DDX_Text(pDX, IDC_EDIT1, tRed);
	DDX_Text(pDX, IDC_EDIT2, tYellow);
	DDX_Text(pDX, IDC_EDIT3, tGreen);
	DDX_Radio(pDX, IDC_RADIO1, mode);
}


BEGIN_MESSAGE_MAP(CLightControl, CDialogEx)
	ON_EN_CHANGE(IDC_EDIT1, &CLightControl::OnEnChangeEdit1)
	ON_EN_CHANGE(IDC_EDIT2, &CLightControl::OnEnChangeEdit2)
	ON_EN_CHANGE(IDC_EDIT3, &CLightControl::OnEnChangeEdit3)
	ON_BN_CLICKED(IDC_RADIO1, &CLightControl::OnBnClickedRadio1)
	ON_BN_CLICKED(IDC_RADIO2, &CLightControl::OnBnClickedRadio2)
	ON_BN_CLICKED(IDC_RADIO3, &CLightControl::OnBnClickedRadio3)
	ON_WM_TIMER()
END_MESSAGE_MAP()


// CLightControl 消息处理程序


void CLightControl::OnEnChangeEdit1()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
	UpdateData(true);
}


void CLightControl::OnEnChangeEdit2()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
	UpdateData(true);
}


void CLightControl::OnEnChangeEdit3()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
	UpdateData(true);
}


void CLightControl::OnBnClickedRadio1()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);
	SetTimer(0, 0, NULL);
}


void CLightControl::OnBnClickedRadio2()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);
	KillTimer(0);
	picRed.SetBitmap(hBmpGray);
	picGreen.SetBitmap(hBmpGreen);
	picYellow.SetBitmap(hBmpGray);
	state = 1;
}


void CLightControl::OnBnClickedRadio3()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);
	KillTimer(0);
	picRed.SetBitmap(hBmpRed);
	picGreen.SetBitmap(hBmpGray);
	picYellow.SetBitmap(hBmpGray);
	state = 1;
}


void CLightControl::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if (state == 1)
	{
		state = 2;
		picRed.SetBitmap(hBmpGray);
		picGreen.SetBitmap(hBmpGreen);
		picYellow.SetBitmap(hBmpGray);
		//改变计时器延时
		KillTimer(0);
		tCorrent = tGreen;
		SetTimer(0, tCorrent, NULL);

	}
	else if (state == 2)
	{
		state = 3;
		picRed.SetBitmap(hBmpGray);
		picGreen.SetBitmap(hBmpGray);
		picYellow.SetBitmap(hBmpGray);
		KillTimer(0);
		tCorrent = 500;//绿灯闪烁延时
		SetTimer(0, tCorrent, NULL);
	}
	else if (state == 3)
	{
		state = 4;
		picRed.SetBitmap(hBmpGray);
		picGreen.SetBitmap(hBmpGreen);
		picYellow.SetBitmap(hBmpGray);
	}
	else if (state == 4)
	{
		state = 5;
		picRed.SetBitmap(hBmpGray);
		picGreen.SetBitmap(hBmpGray);
		picYellow.SetBitmap(hBmpGray);
	}
	else if (state == 5)
	{
		state = 6;
		picRed.SetBitmap(hBmpGray);
		picGreen.SetBitmap(hBmpGreen);
		picYellow.SetBitmap(hBmpGray);
	}
	else if (state == 6)
	{
		state = 7;
		picRed.SetBitmap(hBmpGray);
		picGreen.SetBitmap(hBmpGray);
		picYellow.SetBitmap(hBmpGray);
	}
	else if (state == 7)
	{
		state = 8;
		picRed.SetBitmap(hBmpGray);
		picGreen.SetBitmap(hBmpGreen);
		picYellow.SetBitmap(hBmpGray);
	}
	else if (state == 8)
	{
		state = 9;
		picRed.SetBitmap(hBmpGray);
		picGreen.SetBitmap(hBmpGray);
		picYellow.SetBitmap(hBmpGray);
	}
	else if (state == 9)
	{
		state = 10;
		picRed.SetBitmap(hBmpGray);
		picGreen.SetBitmap(hBmpGray);
		picYellow.SetBitmap(hBmpYellow);
		KillTimer(0);
		tCorrent = tYellow;
		SetTimer(0, tCorrent, NULL);
	}
	else if (state == 10)
	{
		state = 11;
		picRed.SetBitmap(hBmpGray);
		picGreen.SetBitmap(hBmpGray);
		picYellow.SetBitmap(hBmpGray);
		KillTimer(0);
		tCorrent = 500;
		SetTimer(0, tCorrent, NULL);
	}
	else if (state == 11)
	{
		state = 12;
		picRed.SetBitmap(hBmpRed);
		picGreen.SetBitmap(hBmpGray);
		picYellow.SetBitmap(hBmpGray);
		KillTimer(0);
		tCorrent = tRed;
		SetTimer(0, tCorrent, NULL);
	}
	else if (state == 12)
	{
		state = 1;
		picRed.SetBitmap(hBmpGray);
		picGreen.SetBitmap(hBmpGray);
		picYellow.SetBitmap(hBmpGray);
		KillTimer(0);
		tCorrent = 500;
		SetTimer(0, tCorrent, NULL);
	}
	CDialogEx::OnTimer(nIDEvent);
}


BOOL CLightControl::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	bitmapRed.LoadBitmapA(IDB_BITMAP_RED);
	hBmpRed = (HBITMAP)bitmapRed.GetSafeHandle();

	bitmapYellow.LoadBitmapA(IDB_BITMAP_YELLOW);
	hBmpYellow = (HBITMAP)bitmapYellow.GetSafeHandle();

	bitmapGreen.LoadBitmapA(IDB_BITMAP_GREEN);
	hBmpGreen = (HBITMAP)bitmapGreen.GetSafeHandle();

	bitmapGray.LoadBitmapA(IDB_BITMAP_GRAY);
	hBmpGray = (HBITMAP)bitmapGray.GetSafeHandle();

	state = 1;
	tCorrent = 0;

	picRed.SetBitmap(hBmpRed);
	picGreen.SetBitmap(hBmpGray);
	picYellow.SetBitmap(hBmpGray);
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}
