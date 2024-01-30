// CDraw.cpp: 实现文件
//

#include "pch.h"
#include "StudyzbMFCPartGruop.h"
#include "CDraw.h"
#include "afxdialogex.h"


// CDraw 对话框

IMPLEMENT_DYNAMIC(CDraw, CDialogEx)

CDraw::CDraw(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_CDraw, pParent)
	, penType(0)
	, penColorRed(TRUE)
	, penColorGreen(FALSE)
	, penColorBlue(FALSE)
	, penColorLight(0)
	, penWidth(3)
	, brushMod(TRUE)
	, brushType(0)
	, brushColorRed(FALSE)
	, brushColorGreen(FALSE)
	, brushColorBlue(TRUE)
	, brushColorLight(0)
	, backMod(TRUE)
	, backColorRed(FALSE)
	, backColorGreen(TRUE)
	, backColorBlue(FALSE)
	, backColorLight(0)
	, fontColorRed(FALSE)
	, fontColorGreen(FALSE)
	, fontColorBlue(FALSE)
	, fontColorLight(0)
	, fontType(_T("楷体"))
	, fontSize(150)
	, textString(_T("你好！"))
	, exTextStr(_T("很好很好"))
{

}

CDraw::~CDraw()
{
}

void CDraw::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_CBIndex(pDX, IDC_COMBO1, penType);
	DDX_Check(pDX, IDC_CHECK12, penColorRed);
	DDX_Check(pDX, IDC_CHECK13, penColorGreen);
	DDX_Check(pDX, IDC_CHECK14, penColorBlue);
	DDX_Radio(pDX, IDC_RADIO2, penColorLight);
	DDX_Text(pDX, IDC_EDIT2, penWidth);
	DDX_Check(pDX, IDC_CHECK1, brushMod);
	DDX_CBIndex(pDX, IDC_COMBO2, brushType);
	DDX_Check(pDX, IDC_CHECK2, brushColorRed);
	DDX_Check(pDX, IDC_CHECK3, brushColorGreen);
	DDX_Check(pDX, IDC_CHECK4, brushColorBlue);
	DDX_Radio(pDX, IDC_RADIO4, brushColorLight);
	DDX_Check(pDX, IDC_CHECK5, backMod);
	DDX_Check(pDX, IDC_CHECK6, backColorRed);
	DDX_Check(pDX, IDC_CHECK7, backColorGreen);
	DDX_Check(pDX, IDC_CHECK8, backColorBlue);
	DDX_Radio(pDX, IDC_RADIO8, backColorLight);
	DDX_Check(pDX, IDC_CHECK9, fontColorRed);
	DDX_Check(pDX, IDC_CHECK10, fontColorGreen);
	DDX_Check(pDX, IDC_CHECK11, fontColorBlue);
	DDX_Radio(pDX, IDC_RADIO10, fontColorLight);
	DDX_CBString(pDX, IDC_COMBO3, fontType);
	DDX_Text(pDX, IDC_EDIT3, fontSize);
	DDX_Text(pDX, IDC_EDIT1, textString);
	DDX_Text(pDX, IDC_EDIT4, exTextStr);
	DDX_Control(pDX, IDC_SPIN1, lineCtr);
	DDX_Control(pDX, IDC_SPIN2, fontCtr);
}


BEGIN_MESSAGE_MAP(CDraw, CDialogEx)
	ON_WM_PAINT()
	ON_CBN_SELCHANGE(IDC_COMBO1, &CDraw::OnCbnSelchangeCombo1)
	ON_BN_CLICKED(IDC_CHECK12, &CDraw::OnBnClickedCheck12)
	ON_BN_CLICKED(IDC_CHECK13, &CDraw::OnBnClickedCheck13)
	ON_BN_CLICKED(IDC_CHECK14, &CDraw::OnBnClickedCheck14)
	ON_BN_CLICKED(IDC_RADIO2, &CDraw::OnBnClickedRadio2)
	ON_BN_CLICKED(IDC_RADIO3, &CDraw::OnBnClickedRadio3)
	ON_EN_CHANGE(IDC_EDIT2, &CDraw::OnEnChangeEdit2)
	ON_BN_CLICKED(IDC_CHECK1, &CDraw::OnBnClickedCheck1)
	ON_CBN_SELCHANGE(IDC_COMBO2, &CDraw::OnCbnSelchangeCombo2)
	ON_BN_CLICKED(IDC_CHECK2, &CDraw::OnBnClickedCheck2)
	ON_BN_CLICKED(IDC_CHECK3, &CDraw::OnBnClickedCheck3)
	ON_BN_CLICKED(IDC_CHECK4, &CDraw::OnBnClickedCheck4)
	ON_BN_CLICKED(IDC_RADIO4, &CDraw::OnBnClickedRadio4)
	ON_BN_CLICKED(IDC_RADIO5, &CDraw::OnBnClickedRadio5)
	ON_BN_CLICKED(IDC_CHECK5, &CDraw::OnBnClickedCheck5)
	ON_BN_CLICKED(IDC_CHECK6, &CDraw::OnBnClickedCheck6)
	ON_BN_CLICKED(IDC_CHECK7, &CDraw::OnBnClickedCheck7)
	ON_BN_CLICKED(IDC_CHECK8, &CDraw::OnBnClickedCheck8)
	ON_BN_CLICKED(IDC_RADIO8, &CDraw::OnBnClickedRadio8)
	ON_BN_CLICKED(IDC_RADIO9, &CDraw::OnBnClickedRadio9)
	ON_BN_CLICKED(IDC_CHECK9, &CDraw::OnBnClickedCheck9)
	ON_BN_CLICKED(IDC_CHECK10, &CDraw::OnBnClickedCheck10)
	ON_BN_CLICKED(IDC_CHECK11, &CDraw::OnBnClickedCheck11)
	ON_BN_CLICKED(IDC_RADIO10, &CDraw::OnBnClickedRadio10)
	ON_BN_CLICKED(IDC_RADIO11, &CDraw::OnBnClickedRadio11)
	ON_CBN_SELCHANGE(IDC_COMBO3, &CDraw::OnCbnSelchangeCombo3)
	ON_EN_CHANGE(IDC_EDIT3, &CDraw::OnEnChangeEdit3)
	ON_EN_CHANGE(IDC_EDIT1, &CDraw::OnEnChangeEdit1)
	ON_BN_CLICKED(IDC_BUTTON2, &CDraw::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CDraw::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CDraw::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &CDraw::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON6, &CDraw::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON7, &CDraw::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON8, &CDraw::OnBnClickedButton8)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_BN_CLICKED(IDC_BUTTON1, &CDraw::OnBnClickedButton1)
	ON_EN_CHANGE(IDC_EDIT4, &CDraw::OnEnChangeEdit4)
END_MESSAGE_MAP()


// CDraw 消息处理程序


BOOL CDraw::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	lineCtr.SetRange(1, 10);
	lineCtr.SetBuddy(GetDlgItem(IDC_EDIT2));

	fontCtr.SetRange(10, 1000);
	fontCtr.SetBuddy(GetDlgItem(IDC_EDIT3));
	setupColor();
	setupPen();
	setupBrush();
	setupFont();
	drawFlag = false;
	drawType = 0;
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


void CDraw::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: 在此处添加消息处理程序代码
					   // 不为绘图消息调用 CDialogEx::OnPaint()
	drawPic();
	/*dc.SelectObject(pen);
	dc.SelectObject(brush);
	switch(drawType)
	{
	case 1:dc.MoveTo(pStart); dc.LineTo(pEnd); break;
	case 2:dc.Ellipse(pStart.x, pStart.y, pEnd.x, pEnd.y); break;
	case 3:dc.Rectangle(pStart.x, pStart.y, pEnd.x, pEnd.y); break;
	case 4:return;
	default:return;
	}*/
}


void CDraw::drawClient(BOOL flag)
{
	CClientDC dc(this);
	dc.SelectObject(pen);
	dc.SelectObject(brush);
	if (flag)
		dc.SetROP2(R2_NOTXORPEN);
	switch (drawType)
	{
	case 1:dc.MoveTo(pStart); dc.LineTo(pEnd); break;
	case 2:dc.Ellipse(pStart.x, pStart.y, pEnd.x, pEnd.y); break;
	case 3:dc.Rectangle(pStart.x, pStart.y, pEnd.x, pEnd.y); break;
	case 4:return;
	default:return;
	}
}

void  CDraw::drawPic()
{
	CWnd* pWnd = GetDlgItem(IDC_PIC_DRAWDLG);
	CDC* pDC = pWnd->GetDC();

	CRect rect;
	pWnd->GetWindowRect(&rect);

	pDC->Rectangle(0, 0, rect.Width(), rect.Height());

	POINT pt[6];

	pt[0].x = rect.Width() / 2 - 100;
	pt[0].y = rect.Height() / 2 - 50;
	pt[1].x = rect.Width() / 2;
	pt[1].y = rect.Height() / 2 - 100;
	pt[2].x = rect.Width() / 2 + 100;
	pt[2].y = rect.Height() / 2 - 50;
	pt[3].x = rect.Width() / 2 + 100;
	pt[3].y = rect.Height() / 2 + 50;
	pt[4].x = rect.Width() / 2;
	pt[4].y = rect.Height() / 2 + 100;
	pt[5].x = rect.Width() / 2 - 100;
	pt[5].y = rect.Height() / 2 + 50;


	pDC->SelectObject(pen);
	pDC->SelectObject(brush);
	pDC->SelectObject(font);

	pDC->Polygon(pt, 6);
	pDC->SetTextColor(color[3]);
	pDC->TextOutA(10, 10, exTextStr);
}


void CDraw::setupColor()
{
	color[0] = RGB(penColorRed * (255 - penColorLight * 127),
		penColorGreen * (255 - penColorLight * 127),
		penColorBlue * (255 - penColorLight * 127));
	color[1] = RGB(brushColorRed * (255 - brushColorLight * 127),
		brushColorGreen * (255 - brushColorLight * 127),
		brushColorBlue * (255 - brushColorLight * 127));
	color[2] = RGB(backColorRed * (255 - backColorLight * 127),
		backColorGreen * (255 - backColorLight * 127),
		backColorBlue * (255 - backColorLight * 127));
	color[3] = RGB(fontColorRed * (255 - fontColorLight * 127),
		fontColorGreen * (255 - fontColorLight * 127),
		fontColorBlue * (255 - fontColorLight * 127));
}


void CDraw::setupPen()
{
	pen.DeleteObject();
	pen.CreatePen(penType, penWidth, color[0]);
}


void CDraw::setupBrush()
{
	brush.DeleteObject();
	if (brushMod)
		brush.CreateHatchBrush(brushType, color[1]);
	else
		brush.CreateSolidBrush(color[1]);
}


void CDraw::setupFont()
{
	font.DeleteObject();
	font.CreatePointFont(fontSize, fontType);
}

void CDraw::OnCbnSelchangeCombo1()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);
	setupPen();
	drawPic();
}


void CDraw::OnBnClickedCheck12()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);
	setupColor();
	setupPen();
	drawPic();
}


void CDraw::OnBnClickedCheck13()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);
	setupColor();
	setupPen();
	drawPic();
}


void CDraw::OnBnClickedCheck14()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);
	setupColor();
	setupPen();
	drawPic();
}


void CDraw::OnBnClickedRadio2()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);
	setupColor();
	setupPen();
	drawPic();
}


void CDraw::OnBnClickedRadio3()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);
	setupColor();
	setupPen();
	drawPic();
}


void CDraw::OnEnChangeEdit2()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
	UpdateData(true);
	setupPen();
	drawPic();
}


void CDraw::OnBnClickedCheck1()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);
	setupBrush();
	drawPic();
}


void CDraw::OnCbnSelchangeCombo2()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);
	setupBrush();
	drawPic();
}


void CDraw::OnBnClickedCheck2()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);
	setupPen();
	setupBrush();
	drawPic();
}


void CDraw::OnBnClickedCheck3()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);
	setupPen();
	setupBrush();
	drawPic();
}


void CDraw::OnBnClickedCheck4()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);
	setupPen();
	setupBrush();
	drawPic();
}


void CDraw::OnBnClickedRadio4()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);
	setupPen();
	setupBrush();
	drawPic();
}


void CDraw::OnBnClickedRadio5()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);
	setupPen();
	setupBrush();
	drawPic();
}


void CDraw::OnBnClickedCheck5()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);
	drawPic();
}


void CDraw::OnBnClickedCheck6()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);
	setupColor();
	drawPic();
}


void CDraw::OnBnClickedCheck7()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);
	setupColor();
	drawPic();
}


void CDraw::OnBnClickedCheck8()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);
	setupColor();
	drawPic();
}


void CDraw::OnBnClickedRadio8()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);
	setupColor();
	drawPic();
}


void CDraw::OnBnClickedRadio9()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);
	setupColor();
	drawPic();
}


void CDraw::OnBnClickedCheck9()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);
	setupColor();
	drawPic();
}


void CDraw::OnBnClickedCheck10()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);
	setupColor();
	drawPic();
}


void CDraw::OnBnClickedCheck11()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);
	setupColor();
	drawPic();
}


void CDraw::OnBnClickedRadio10()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);
	setupColor();
	drawPic();
}


void CDraw::OnBnClickedRadio11()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);
	setupColor();
	drawPic();
}


void CDraw::OnCbnSelchangeCombo3()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);
	setupFont();
	drawPic();
}


void CDraw::OnEnChangeEdit3()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
	UpdateData(true);
	setupFont();
	drawPic();
}


void CDraw::OnEnChangeEdit1()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
	UpdateData(true);
}


void CDraw::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	drawFlag = true;
	drawType = 1;
}


void CDraw::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码
	drawType = 1;
}


void CDraw::OnBnClickedButton4()
{
	// TODO: 在此添加控件通知处理程序代码
	drawType = 2;
}


void CDraw::OnBnClickedButton5()
{
	// TODO: 在此添加控件通知处理程序代码
	drawType = 3;
}


void CDraw::OnBnClickedButton6()
{
	// TODO: 在此添加控件通知处理程序代码
	MessageBox("暂未推出");
	return;
	drawType = 4;
}


void CDraw::OnBnClickedButton7()
{
	// TODO: 在此添加控件通知处理程序代码
	drawType = 5;
}


void CDraw::OnBnClickedButton8()
{
	// TODO: 在此添加控件通知处理程序代码
	drawFlag = FALSE;
	drawType = 0;
}


void CDraw::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if (!drawFlag)
		return;
	pStart = point;
	pEnd = point;
	CDialogEx::OnLButtonDown(nFlags, point);
}


void CDraw::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if (!drawFlag)
		return;
	pEnd = point;
	drawClient(false);
	CDialogEx::OnLButtonUp(nFlags, point);
}


void CDraw::OnMButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if (!drawFlag)
		return;
	if (drawType != 5)
		return;
	CClientDC dc(this);
	if (backMod)
		dc.SetBkMode(TRANSPARENT);
	else
		dc.SetBkMode(OPAQUE);
	dc.SetBkColor(color[2]);
	dc.SetTextColor(color[3]);
	dc.SelectObject(font);
	dc.TextOutA(point.x, point.y, textString);
	CDialogEx::OnMButtonDown(nFlags, point);
}


void CDraw::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if (nFlags == MK_LBUTTON)
	{
		if (!drawFlag)
			return;
		drawClient(true);
		pEnd = point;
		drawClient(true);
	}
	CDialogEx::OnMouseMove(nFlags, point);
}


void CDraw::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	Invalidate();
}


void CDraw::OnEnChangeEdit4()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
	UpdateData(true);
	drawPic();
}
