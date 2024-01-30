// CCirFunc.cpp: 实现文件
//

#include "pch.h"
#include "StudyzbMFCPartGruop.h"
#include "CCirFunc.h"
#include "afxdialogex.h"


// CCirFunc 对话框

double A1 = 100.0;
double omega1 = 4;
double theta1 = 0;

double A2 = 50;
double omega2 = 9;
double theta2 = 0;

double drawCir(int x, double A, double omega, double theta)
{
	double dy = rand() % 30 + 15;
	return A * sin(omega * x * 3.14 / 180 + theta) + dy;
}

IMPLEMENT_DYNAMIC(CCirFunc, CDialogEx)

CCirFunc::CCirFunc(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_CCirFunc, pParent)
{

}

CCirFunc::~CCirFunc()
{
}

void CCirFunc::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CCirFunc, CDialogEx)
	ON_WM_TIMER()
	ON_WM_DESTROY()
//	ON_WM_PAINT()
ON_WM_PAINT()
END_MESSAGE_MAP()


// CCirFunc 消息处理程序


void CCirFunc::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CWnd* pWnd1 = GetDlgItem(IDC_PIC);
	CDC* pDC1 = pWnd1->GetDC();

	CRect rect1;
	pWnd1->GetWindowRect(&rect1);

	int x01 = 0, y01 = rect1.Height() / 2;
	int xEnd1 = rect1.Width();
	xEnd1 = xEnd1 > bufSize1 ? bufSize1 : xEnd1;


	CWnd* pWnd2 = GetDlgItem(IDC_PIC);
	CDC* pDC2 = pWnd2->GetDC();

	CRect rect2;
	pWnd2->GetWindowRect(&rect2);

	int x02 = 0, y02 = rect2.Height() / 2;
	int xEnd2 = rect2.Width();
	xEnd2 = xEnd2 > bufSize2 ? bufSize2 : xEnd2;
	if (nIDEvent == 1)
	{
		x1++;
		dataCount1++;
		if (dataCount1 >= xEnd1)
		{
			return;
			//再继续下去一段时间后会报错，未知
			/*dataCount1 = 0;
			data1[dataCount1] = drawCir(x1, A1, omega1, theta1);

			pDC1->Rectangle(0, 0, rect1.Width(), rect1.Height());*/

		}
		else
		{
			data1[dataCount1] = drawCir(x1, A1, omega1, theta1);

			CPen pen1;
			pen1.CreatePen(PS_SOLID, 1, RGB(255, 0, 0));
			pDC1->SelectObject(pen1);
			pDC1->MoveTo(x01 + dataCount1 - 1, y01 - data1[dataCount1 - 1]);
			pDC1->LineTo(x01 + dataCount1, y01 - data1[dataCount1]);
			pen1.DeleteObject();
		}
	}
	if (nIDEvent == 2)
	{
		x2++;
		dataCount2++;
		if (dataCount2 >= xEnd2)
		{
			return;
			/*dataCount2 = 0;
			data2[dataCount2] = drawCir(x2, A2, omega2, theta2);
			pDC2->Rectangle(0, 0, rect2.Width(), rect2.Height());*/

		}
		else
		{
			data2[dataCount2] = drawCir(x2, A2, omega2, theta2);

			CPen pen2;
			pen2.CreatePen(PS_SOLID, 1, RGB(0, 255, 0));
			pDC2->SelectObject(pen2);
			pDC2->MoveTo(x02 + dataCount2 - 1, y02 - data2[dataCount2 - 1]);
			pDC2->LineTo(x02 + dataCount2, y02 - data2[dataCount2]);
			pen2.DeleteObject();
		}
	}
	CDialogEx::OnTimer(nIDEvent);
}


void CCirFunc::OnDestroy()
{
	CDialogEx::OnDestroy();
	delete[]data1;
	delete[]data2;
	// TODO: 在此处添加消息处理程序代码
}


BOOL CCirFunc::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	bufSize1 = 1000;
	data1 = new double[bufSize1];
	dataCount1 = 0;

	x1 = 0;
	y1 = drawCir(x1, A1, omega1, theta1);

	bufSize2 = 1000;
	data2 = new double[bufSize2];
	dataCount2 = 0;

	x2 = 0;
	y2 = drawCir(x2, A2, omega2, theta2);

	//SetTimer(1, 10, NULL);
	//SetTimer(2, 10, NULL);
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


void CCirFunc::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: 在此处添加消息处理程序代码
					   // 不为绘图消息调用 CDialogEx::OnPaint()
	CWnd* pWnd = GetDlgItem(IDC_PIC);
	CDC* pDC = pWnd->GetDC();
	CRect rect;
	pWnd->GetWindowRect(&rect);

	CPen pen;
	pen.CreatePen(PS_SOLID, 1, RGB(0, 0, 0));
	pDC->SelectObject(pen);
	pDC->Rectangle(0, 0, rect.Width(), rect.Height());
	pen.DeleteObject();

	SetTimer(1, 10, NULL);
	SetTimer(2, 10, NULL);
}
