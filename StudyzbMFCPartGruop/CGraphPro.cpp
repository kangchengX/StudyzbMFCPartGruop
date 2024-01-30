// CGraphPro.cpp: 实现文件
//

#include "pch.h"
#include "StudyzbMFCPartGruop.h"
#include "CGraphPro.h"
#include "afxdialogex.h"


// CGraphPro 对话框

IMPLEMENT_DYNAMIC(CGraphPro, CDialogEx)

CGraphPro::CGraphPro(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_CGraphPro, pParent)
{

}

CGraphPro::~CGraphPro()
{
}

void CGraphPro::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST_FILE, fileList);
}


BEGIN_MESSAGE_MAP(CGraphPro, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CGraphPro::OnBnClickedButton1)
	ON_WM_PAINT()
	ON_BN_CLICKED(IDC_BUTTON2, &CGraphPro::OnBnClickedButton2)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_BN_CLICKED(IDC_BUTTON3, &CGraphPro::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CGraphPro::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &CGraphPro::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON6, &CGraphPro::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON7, &CGraphPro::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON8, &CGraphPro::OnBnClickedButton8)
	ON_LBN_SELCHANGE(IDC_LIST_FILE, &CGraphPro::OnLbnSelchangeListFile)
//	ON_WM_VSCROLL()
ON_BN_CLICKED(IDC_BUTTON9, &CGraphPro::OnBnClickedButton9)
END_MESSAGE_MAP()


// CGraphPro 消息处理程序


BOOL CGraphPro::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	selFlag = false;
	openFlag = false;
	selectFirst = false;
	

	CWnd* pWnd = GetDlgItem(IDC_IMAGE);
	CDC* pDC = pWnd->GetDC();
	pWnd->GetWindowRect(&picRect);
	m_MyImage.Create(picRect.Width(), picRect.Height(), 24);
	m_MyRect = CRect(0, 0, picRect.Width(), picRect.Height());
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


void CGraphPro::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: 在此处添加消息处理程序代码
					   // 不为绘图消息调用 CDialogEx::OnPaint()
	CWnd* pWnd = GetDlgItem(IDC_IMAGE);
	CDC* pDC = pWnd->GetDC();
	m_MyImage.BitBlt(pDC->m_hDC, 0, 0, m_MyRect.Width(), m_MyRect.Height(), 0, 0, WHITENESS);
	/*m_MyImage.Draw(pDC->m_hDC, 0, 0);*/
}


void CGraphPro::draw()
{
	CWnd* pWnd = GetDlgItem(IDC_IMAGE);
	CDC* pDC = pWnd->GetDC();
	m_MyImage.BitBlt(pDC->m_hDC, 0, 0, m_MyRect.Width(), m_MyRect.Height(), 0, 0, SRCCOPY);
}


//打开图片
void CGraphPro::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	CString strFilter = "图像文件|*.jpg;*.bmp;*.gif;*.tif;*.png|\
						位图文件|*.bmp|JPEG文件|*.jpg|所有文件|*.*|";
	CFileDialog dlg(true, NULL, NULL, NULL, strFilter);
	if (dlg.DoModal() == IDOK)
	{
		CString filename = dlg.GetPathName();
		fileList.AddString(filename);
		m_MyImage.Destroy();
		m_MyImage.Load(filename);
		m_MyRect = CRect(0, 0, 
			m_MyImage.GetWidth()<picRect.Width()?m_MyImage.GetWidth():picRect.Width(),
			m_MyImage.GetHeight()<picRect.Height()? m_MyImage.GetHeight(): picRect.Height());
		draw();
	}
	selFlag = false;
	openFlag = true;
}


//开始选择区域
void CGraphPro::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	if (!openFlag)
		return;
	selFlag = true;
}


void CGraphPro::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if (selFlag)
	{
		if (selectFirst)
		{
			CPen pen;
			CWnd* pWnd = GetDlgItem(IDC_IMAGE);
			CDC* pDC = pWnd->GetDC();
			pen.CreatePen(PS_DASH, 1, RGB(255, 0, 0));
			pDC->SelectObject(pen);
			pDC->SetROP2(R2_NOTXORPEN);
			pDC->Rectangle(pStart.x, pStart.y, pEnd.x, pEnd.y);
			pen.DeleteObject();
		}
		pStart.x = point.x - picRect.left;
		pStart.y = point.y - picRect.top;
		pEnd.x = point.x - picRect.left;
		pEnd.y = point.y - picRect.top;
		selectFirst = true;
	}
	CDialogEx::OnLButtonDown(nFlags, point);
}


void CGraphPro::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if (selFlag)
	{
		pEnd.x = point.x - picRect.left;
		pEnd.y = point.y - picRect.top;
	}
	CDialogEx::OnLButtonUp(nFlags, point);
}


void CGraphPro::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if (selFlag)
	{
		if (nFlags == MK_LBUTTON)
		{
			CWnd* pWnd = GetDlgItem(IDC_IMAGE);
			CDC* pDC = pWnd->GetDC();

			CPen pen;
			pen.CreatePen(PS_DASH, 1, RGB(255, 0, 0));
			pDC->SelectObject(pen);
			pDC->SetROP2(R2_NOTXORPEN);

			pDC->Rectangle(pStart.x, pStart.y, pEnd.x, pEnd.y);
			pEnd.x = point.x - picRect.left;
			pEnd.y = point.y - picRect.top;
			pDC->Rectangle(pStart.x, pStart.y, pEnd.x, pEnd.y);
			pen.DeleteObject();
		}
	}
	CDialogEx::OnMouseMove(nFlags, point);
}


//保存图片
void CGraphPro::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码
	if (!openFlag)
		return;
	if (selFlag == false)
	{
		CWnd* pWnd = GetDlgItem(IDC_IMAGE);
		CDC* pDC = pWnd->GetDC();

		pStart.x = 0;
		pStart.y = 0;
		pEnd.x = m_MyImage.GetWidth();
		pEnd.y = m_MyImage.GetHeight();
	}
	CString strFilter = "图像文件|*.jpg;*.bmp;*.gif;*.tif;*.png|\
						位图文件|*.bmp|JPEG文件|*.jpg|所有文件|*.*|";
	CFileDialog dlg(false, "*.jpg", "新建文件", OFN_OVERWRITEPROMPT, strFilter);
	if (dlg.DoModal() == IDOK)
	{
		CString fileName = dlg.GetPathName();
		
		CWnd* pWnd = GetDlgItem(IDC_IMAGE);
		CDC* pDC = pWnd->GetDC();
		CDC memdc;
		memdc.CreateCompatibleDC(pDC);

		if (selFlag)
		{
			selFlag = false;
			CPen pen;
			pen.CreatePen(PS_DASH, 1, RGB(255, 0, 0));
			pDC->SelectObject(pen);
			pDC->SetROP2(R2_NOTXORPEN);

			pDC->Rectangle(pStart.x, pStart.y, pEnd.x, pEnd.y);
			pen.DeleteObject();
		}
		CImage img;

		int w = pEnd.x - pStart.x;
		int h = pEnd.y - pStart.y;
		img.Create(w, h, 24);

		memdc.SelectObject(img);
		memdc.BitBlt(0, 0, w, h, pDC, pStart.x, pStart.y, SRCCOPY);

		img.Save(fileName);
	}
	selFlag = false;
	selectFirst = false;
}


//打开多张图片
void CGraphPro::OnBnClickedButton4()
{
	// TODO: 在此添加控件通知处理程序代码
	CString strFilter = "图像文件|*.jpg;*.bmp;*.gif;*.tif;*.png|\
						位图文件|*.bmp|JPEG文件|*.jpg|所有文件|*.*|";
	CFileDialog dlg(true, NULL, NULL, OFN_ALLOWMULTISELECT, strFilter);
	if (dlg.DoModal() == IDOK)
	{
		CString fileName;

		fileList.ResetContent();
		POSITION pos = dlg.GetStartPosition();
		while (pos != NULL)
		{
			fileName = dlg.GetNextPathName(pos);
			fileList.AddString(fileName);
		}

		pos = dlg.GetStartPosition();
		fileName = dlg.GetNextPathName(pos);
		m_MyImage.Destroy();
		m_MyImage.Load(fileName);
		m_MyRect = CRect(0, 0, m_MyImage.GetWidth(), m_MyImage.GetHeight());
		draw();
	}
	selFlag = false;
	openFlag = true;
}


//图片黑白
void CGraphPro::OnBnClickedButton5()
{
	// TODO: 在此添加控件通知处理程序代码
	if (!openFlag)
		return;
	CWaitCursor WaitCursor;
	int Height = m_MyImage.GetHeight();
	int Width = m_MyImage.GetWidth();
	if (!m_MyImage.IsIndexed())//判断是否为索引//非
	{
		for (int i = 0; i < Width; i++)
		{
			for (int j = 0; j < Height; j++)
			{
				COLORREF pixel = m_MyImage.GetPixel(i, j);
				byte r, g, b, value;
				r = GetRValue(pixel);
				g = GetGValue(pixel);
				b = GetBValue(pixel);
				value = (r + g + b) / 3;
				m_MyImage.SetPixelRGB(i, j, value, value, value);
			}
		}
	}
	else
	{
		int MaxColors = m_MyImage.GetMaxColorTableEntries();
		RGBQUAD* ColorTable = new RGBQUAD[MaxColors];//申请内存
		m_MyImage.GetColorTable(0, MaxColors, ColorTable);
		for (int i = 0; i < MaxColors; i++)
		{
			byte r, g, b, Value;
			r = ColorTable[i].rgbRed;
			g = ColorTable[i].rgbGreen;
			b = ColorTable[i].rgbBlue;
			Value = (r + g + b) / 3;
			ColorTable[i].rgbRed = Value;
			ColorTable[i].rgbGreen = Value;
			ColorTable[i].rgbBlue = Value;
		}
		m_MyImage.SetColorTable(0, MaxColors, ColorTable);
		delete ColorTable;
	}
	draw();
}


//雾化
void CGraphPro::OnBnClickedButton6()
{
	// TODO: 在此添加控件通知处理程序代码
	if (!openFlag)
		return;
	CWaitCursor WaitCursor;
	int Height = m_MyImage.GetHeight();
	int Width = m_MyImage.GetWidth();
	for (int x = 1; x < Width; x++)
	{
		for (int y = 1; y < Height; y++)
		{
			COLORREF pixel;
			double f = RAND_MAX;
			int k = (int)(24 * (rand() / f));
			int dx = x + k % 15;
			int dy = y + k % 15;
			if (dx >= Width)
				dx = Width - 1;
			if (dy >= Height)
				dy = Height - 1;
			pixel = m_MyImage.GetPixel(dx, dy);
			m_MyImage.SetPixel(x, y, pixel);
		}
	}
	draw();
}


//底片化
void CGraphPro::OnBnClickedButton7()
{
	// TODO: 在此添加控件通知处理程序代码
	if (!openFlag)
		return;
	CWaitCursor WaitCursor;
	int Height = m_MyImage.GetHeight();
	int Width = m_MyImage.GetWidth();
	for (int i = 0; i < Width; i++)
	{
		for (int j = 0; j < Height; j++)
		{
			COLORREF pixel = m_MyImage.GetPixel(i, j);
			byte r, g, b;
			r = GetRValue(pixel);
			g = GetGValue(pixel);
			b = GetBValue(pixel);
			m_MyImage.SetPixelRGB(i, j, 255 - r, 255 - g, 255 - b);
		}
	}
	draw();
}


//锐化
void CGraphPro::OnBnClickedButton8()
{
	// TODO: 在此添加控件通知处理程序代码
	if (!openFlag)
		return;
	CWaitCursor WaitCursor;
	int Height = m_MyImage.GetHeight();
	int Width = m_MyImage.GetWidth();
	//拉普拉斯模板
	int Lap[9] = { -1,-1,-1,-1,9,-1,-1,-1,-1 };
	for (int x = 1; x < Width - 1; x++)
	{
		for (int y = 1; y < Height - 1; y++)
		{
			int r = 0, g = 0, b = 0;
			int Index = 0;
			for (int col = -1; col <= 1; col++)
			{
				for (int row = -1; row <= 1; row++)
				{
					COLORREF pixel = m_MyImage.GetPixel(x + row, y + col);
					r += GetRValue(pixel) * Lap[Index];
					g += GetGValue(pixel) * Lap[Index];
					b += GetBValue(pixel) * Lap[Index];
					Index++;
				}
			}
			r = r > 255 ? 255 : r;
			r = r < 0 ? 0 : r;
			g = g > 255 ? 255 : g;
			g = g < 0 ? 0 : g;
			b = b > 255 ? 255 : b;
			b = b < 0 ? 0 : b;
			m_MyImage.SetPixelRGB(x - 1, y - 1, r, g, b);
		}
	}
	draw();
}


void CGraphPro::OnLbnSelchangeListFile()
{
	// TODO: 在此添加控件通知处理程序代码
	CString fileName;
	int i = fileList.GetCurSel();
	fileList.GetText(i, fileName);
	
	m_MyImage.Destroy();
	m_MyImage.Load(fileName);
	m_MyRect = CRect(0, 0, m_MyImage.GetWidth(), m_MyImage.GetHeight());

	draw();

	selFlag = false;
	openFlag = true;
}


//清除
void CGraphPro::OnBnClickedButton9()
{
	// TODO: 在此添加控件通知处理程序代码
	CWnd* pWnd = GetDlgItem(IDC_IMAGE);
	CDC* pDC = pWnd->GetDC();
	int w = m_MyImage.GetWidth();
	int h = m_MyImage.GetHeight();
	m_MyImage.Destroy();
	m_MyImage.Create(w,h,24);
	Invalidate();
}
