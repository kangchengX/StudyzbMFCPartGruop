
// StudyzbMFCPartGruopView.cpp: CStudyzbMFCPartGruopView 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "StudyzbMFCPartGruop.h"
#endif

#include "StudyzbMFCPartGruopDoc.h"
#include "StudyzbMFCPartGruopView.h"
#include "CGraph.h"
#include "CGraphPro.h"
#include "CCALC.h"
#include "CGlodbach.h"
#include "CShareMemServer.h"
#include "CShareMemClient.h"
#include "CCirFunc.h"
#include "CLightControl.h"
#include "CDraw.h"
#include "CCom.h"
#include "CColorSet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CStudyzbMFCPartGruopView

IMPLEMENT_DYNCREATE(CStudyzbMFCPartGruopView, CView)

BEGIN_MESSAGE_MAP(CStudyzbMFCPartGruopView, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CStudyzbMFCPartGruopView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_COMMAND(ID_TYPE_LINE, &CStudyzbMFCPartGruopView::OnTypeLine)
	ON_UPDATE_COMMAND_UI(ID_TYPE_LINE, &CStudyzbMFCPartGruopView::OnUpdateTypeLine)
	ON_COMMAND(ID_TYPE_RANT, &CStudyzbMFCPartGruopView::OnTypeRant)
	ON_UPDATE_COMMAND_UI(ID_TYPE_RANT, &CStudyzbMFCPartGruopView::OnUpdateTypeRant)
	ON_COMMAND(ID_TYPE_ELL, &CStudyzbMFCPartGruopView::OnTypeEll)
	ON_UPDATE_COMMAND_UI(ID_TYPE_ELL, &CStudyzbMFCPartGruopView::OnUpdateTypeEll)
	ON_COMMAND(ID_PEN_SOLID, &CStudyzbMFCPartGruopView::OnPenSolid)
	ON_UPDATE_COMMAND_UI(ID_PEN_SOLID, &CStudyzbMFCPartGruopView::OnUpdatePenSolid)
	ON_COMMAND(ID_PEN_DASH, &CStudyzbMFCPartGruopView::OnPenDash)
	ON_UPDATE_COMMAND_UI(ID_PEN_DASH, &CStudyzbMFCPartGruopView::OnUpdatePenDash)
	ON_COMMAND(ID_PEN_COLOR, &CStudyzbMFCPartGruopView::OnPenColor)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_COMMAND(ID_DRAW_TRUE, &CStudyzbMFCPartGruopView::OnDrawTrue)
	ON_COMMAND(ID_DRAW_FALSE, &CStudyzbMFCPartGruopView::OnDrawFalse)
	ON_WM_DESTROY()
	ON_WM_RBUTTONDOWN()
	ON_COMMAND(ID_CHANGE_FALSE, &CStudyzbMFCPartGruopView::OnChangeFalse)
	ON_UPDATE_COMMAND_UI(ID_CHANGE_FALSE, &CStudyzbMFCPartGruopView::OnUpdateChangeFalse)
	ON_UPDATE_COMMAND_UI(ID_CHANGE_TRUE, &CStudyzbMFCPartGruopView::OnUpdateChangeTrue)
	ON_COMMAND(ID_CHANGE_TRUE, &CStudyzbMFCPartGruopView::OnChangeTrue)
	ON_UPDATE_COMMAND_UI(ID_DRAW_TRUE, &CStudyzbMFCPartGruopView::OnUpdateDrawTrue)
	ON_UPDATE_COMMAND_UI(ID_DRAW_FALSE, &CStudyzbMFCPartGruopView::OnUpdateDrawFalse)
	ON_COMMAND(ID_POP, &CStudyzbMFCPartGruopView::OnPop)
	ON_COMMAND(ID_BOTTOM, &CStudyzbMFCPartGruopView::OnBottom)
	ON_COMMAND(ID_GRAPH_PRO, &CStudyzbMFCPartGruopView::OnGraphPro)
	ON_COMMAND(IDM_CALC, &CStudyzbMFCPartGruopView::OnCalc)
	ON_COMMAND(ID_GOLDBACH, &CStudyzbMFCPartGruopView::OnGoldbach)
	ON_COMMAND(ID_SHAREMAP_SERVER, &CStudyzbMFCPartGruopView::OnSharemapServer)
	ON_COMMAND(ID_SHAREMAP_CLIENT, &CStudyzbMFCPartGruopView::OnSharemapClient)
	ON_COMMAND(ID_CIR, &CStudyzbMFCPartGruopView::OnCir)
	ON_COMMAND(ID_LIGHT_CTR, &CStudyzbMFCPartGruopView::OnLightCtr)
	ON_COMMAND(ID_DRAW_DLG, &CStudyzbMFCPartGruopView::OnDrawDlg)
	ON_COMMAND(ID_COM, &CStudyzbMFCPartGruopView::OnCom)
	ON_COMMAND(ID_BRUSH_NONE, &CStudyzbMFCPartGruopView::OnBrushNone)
	ON_UPDATE_COMMAND_UI(ID_BRUSH_NONE, &CStudyzbMFCPartGruopView::OnUpdateBrushNone)
	ON_COMMAND(ID_BRUSH_SHUIPING, &CStudyzbMFCPartGruopView::OnBrushShuiping)
	ON_UPDATE_COMMAND_UI(ID_BRUSH_SHUIPING, &CStudyzbMFCPartGruopView::OnUpdateBrushShuiping)
	ON_COMMAND(ID_BRUSH_CHUIZHI, &CStudyzbMFCPartGruopView::OnBrushChuizhi)
	ON_UPDATE_COMMAND_UI(ID_BRUSH_CHUIZHI, &CStudyzbMFCPartGruopView::OnUpdateBrushChuizhi)
	ON_COMMAND(ID_BRUSH_DUIJIOA, &CStudyzbMFCPartGruopView::OnBrushDuijioa)
	ON_UPDATE_COMMAND_UI(ID_BRUSH_DUIJIOA, &CStudyzbMFCPartGruopView::OnUpdateBrushDuijioa)
	ON_COMMAND(ID_BRUSH_FANDUIJIAO, &CStudyzbMFCPartGruopView::OnBrushFanduijiao)
	ON_UPDATE_COMMAND_UI(ID_BRUSH_FANDUIJIAO, &CStudyzbMFCPartGruopView::OnUpdateBrushFanduijiao)
	ON_COMMAND(ID_BRUSH_XIANGJIAO, &CStudyzbMFCPartGruopView::OnBrushXiangjiao)
	ON_UPDATE_COMMAND_UI(ID_BRUSH_XIANGJIAO, &CStudyzbMFCPartGruopView::OnUpdateBrushXiangjiao)
	ON_COMMAND(ID_BRUSH_COLOR, &CStudyzbMFCPartGruopView::OnBrushColor)
	ON_COMMAND(ID_COLOR_SETS, &CStudyzbMFCPartGruopView::OnColorSets)
	ON_COMMAND(ID_COLOR_SET, &CStudyzbMFCPartGruopView::OnColorSet)
	ON_COMMAND(ID_SET_BACKPIC, &CStudyzbMFCPartGruopView::OnSetBackpic)
	ON_COMMAND(ID_BRUSH_PUTONG, &CStudyzbMFCPartGruopView::OnBrushPutong)
	ON_UPDATE_COMMAND_UI(ID_BRUSH_PUTONG, &CStudyzbMFCPartGruopView::OnUpdateBrushPutong)
END_MESSAGE_MAP()

// CStudyzbMFCPartGruopView 构造/析构

CStudyzbMFCPartGruopView::CStudyzbMFCPartGruopView() noexcept
{
	// TODO: 在此处添加构造代码

}

CStudyzbMFCPartGruopView::~CStudyzbMFCPartGruopView()
{
}

BOOL CStudyzbMFCPartGruopView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式
	m_npenType = PS_SOLID;
	m_npenColor = RGB(255, 0, 0);
	m_nbrushType = -2;
	m_nbrushColor = RGB(255, 0, 0);
	/*m_ptStart = CPoint(0, 0);
	m_ptEnd = CPoint(0, 0);*/
	m_nType = 0;
	changeType = 0;
	drawType = 1;
	fileName = "\0";
	//upFlag = 0;
	/*m_MyImage.Create(1, 1, 24);*/

	//在注册表读取颜色设置，或创造注册表
	HKEY m_hKey;
	if (RegOpenKey(HKEY_CURRENT_USER, "software\\StudyzbMFCPartGroup\\画笔", &m_hKey) != 0)
	{
		RegCreateKey(HKEY_CURRENT_USER, "software\\StudyzbMFCPartGroup\\画笔", &m_hKey);
		RegSetValueEx(m_hKey, "颜色", 0, REG_DWORD, (BYTE*)&m_npenColor, sizeof(DWORD));
	}
	else
	{
		DWORD dwSize;
		DWORD dwType = REG_DWORD;
		if (RegQueryValueEx(m_hKey, "颜色", 0, &dwType, (LPBYTE)&m_npenColor, &dwSize) != 0)
			RegSetValueEx(m_hKey, "颜色", 0, REG_DWORD, (BYTE*)&m_npenColor, sizeof(DWORD));
	}

	if (RegOpenKey(HKEY_CURRENT_USER, "software\\StudyzbMFCPartGroup\\画刷", &m_hKey) != 0)
	{
		RegCreateKey(HKEY_CURRENT_USER, "software\\StudyzbMFCPartGroup\\画刷", &m_hKey);
		RegSetValueEx(m_hKey, "颜色", 0, REG_DWORD, (BYTE*)&m_nbrushColor, sizeof(DWORD));
	}
	else
	{
		DWORD dwSize;
		DWORD dwType = REG_DWORD;
		if (RegQueryValueEx(m_hKey, "颜色", 0, &dwType, (LPBYTE)&m_nbrushColor, &dwSize) != 0)
			RegSetValueEx(m_hKey, "颜色", 0, REG_DWORD, (BYTE*)&m_nbrushColor, sizeof(DWORD));
	}
	return CView::PreCreateWindow(cs);
}

// CStudyzbMFCPartGruopView 绘图

void CStudyzbMFCPartGruopView::OnDraw(CDC* pDC)
{
	CStudyzbMFCPartGruopDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	/*m_MyImage.Draw(pDC->m_hDC, 0, 0);*/
	if (fileName != "\0")//在清除后重新画背景图片
	{
		CImage m_MyImage;
		m_MyImage.Load(fileName);
		m_MyImage.Draw(pDC->m_hDC, 0, 0);
	}
	
	for (int i = 0; i < pDoc->obArray.GetSize(); i++)
	{
		CPen pen;
		CBrush brush;
		CGraph* p = (CGraph*)pDoc->obArray.GetAt(i);
		pen.CreatePen(p->m_npenType, 1, p->m_npenColor);
		if (p->m_nbrushType == -2);
		else
		{
			if (p->m_nbrushType == -1)
				brush.CreateSolidBrush(p->m_nbrushColor);
			else
				brush.CreateHatchBrush(p->m_nbrushType, p->m_nbrushColor);
			pDC->SelectObject(brush);
		}
		pDC->SelectObject(pen);	
		switch (p->m_nType)
		{
		case 0:
			pDC->MoveTo(p->m_ptStart);
			pDC->LineTo(p->m_ptEnd);
			break;
		case 1:
			pDC->Rectangle(CRect(p->m_ptStart, p->m_ptEnd)); break;
		case 2:
			pDC->Ellipse(CRect(p->m_ptStart, p->m_ptEnd)); break;//这里必须有CRect
		}
		pen.DeleteObject();
		brush.DeleteObject();
	}
}


//绘图
void CStudyzbMFCPartGruopView::draw()
{
	CStudyzbMFCPartGruopDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	CDC* pDC = GetDC();//CPaintDC dc(this); pDC = &dc 不行 未知
	CPen pen;
	CBrush brush;
	int i = pDoc->obArray.GetSize();
	CGraph* p = (CGraph*)pDoc->obArray.GetAt(i - 1);
	pen.CreatePen(p->m_npenType, 1, p->m_npenColor);
	/*if(!upFlag)*/
	pDC->SetROP2(R2_NOTXORPEN);
	if (p->m_nbrushType == -2);
	else
	{
		if (p->m_nbrushType == -1)
			brush.CreateSolidBrush(p->m_nbrushColor);
		else
			brush.CreateHatchBrush(p->m_nbrushType, p->m_nbrushColor);
		pDC->SelectObject(brush);
	}
	pDC->SelectObject(pen);
	switch (p->m_nType)
	{
	case 0:
		pDC->MoveTo(p->m_ptStart);
		pDC->LineTo(p->m_ptEnd);
		break;
	case 1:
		pDC->Rectangle(CRect(p->m_ptStart, p->m_ptEnd)); break;
	case 2:
		pDC->Ellipse(CRect(p->m_ptStart, p->m_ptEnd)); break;//这里必须有CRect
	}
	pen.DeleteObject();
}

// CStudyzbMFCPartGruopView 打印


void CStudyzbMFCPartGruopView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CStudyzbMFCPartGruopView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CStudyzbMFCPartGruopView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CStudyzbMFCPartGruopView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}

void CStudyzbMFCPartGruopView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CStudyzbMFCPartGruopView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CStudyzbMFCPartGruopView 诊断

#ifdef _DEBUG
void CStudyzbMFCPartGruopView::AssertValid() const
{
	CView::AssertValid();
}

void CStudyzbMFCPartGruopView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CStudyzbMFCPartGruopDoc* CStudyzbMFCPartGruopView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CStudyzbMFCPartGruopDoc)));
	return (CStudyzbMFCPartGruopDoc*)m_pDocument;
}
#endif //_DEBUG


// CStudyzbMFCPartGruopView 消息处理程序


void CStudyzbMFCPartGruopView::OnTypeLine()
{
	// TODO: 在此添加命令处理程序代码
	m_nType = 0;
}


void CStudyzbMFCPartGruopView::OnUpdateTypeLine(CCmdUI* pCmdUI)
{
	// TODO: 在此添加命令更新用户界面处理程序代码
	if (m_nType == 0)
		pCmdUI->SetCheck(true);
	else
		pCmdUI->SetCheck(false);
}


void CStudyzbMFCPartGruopView::OnTypeRant()
{
	// TODO: 在此添加命令处理程序代码
	m_nType = 1;
}


void CStudyzbMFCPartGruopView::OnUpdateTypeRant(CCmdUI* pCmdUI)
{
	// TODO: 在此添加命令更新用户界面处理程序代码
	if (m_nType == 1)
		pCmdUI->SetCheck(true);
	else
		pCmdUI->SetCheck(false);
}


void CStudyzbMFCPartGruopView::OnTypeEll()
{
	// TODO: 在此添加命令处理程序代码
	m_nType = 2;
}


void CStudyzbMFCPartGruopView::OnUpdateTypeEll(CCmdUI* pCmdUI)
{
	// TODO: 在此添加命令更新用户界面处理程序代码
	if (m_nType == 2)
		pCmdUI->SetCheck(true);
	else
		pCmdUI->SetCheck(false);
}


void CStudyzbMFCPartGruopView::OnPenSolid()
{
	// TODO: 在此添加命令处理程序代码
	m_npenType = PS_SOLID;
	if (changeType)
	{
		CStudyzbMFCPartGruopDoc* pDoc = GetDocument();
		ASSERT_VALID(pDoc);
		if (!pDoc)
			return;
		int i = pDoc->obArray.GetSize();
		CGraph* p = (CGraph*)pDoc->obArray.GetAt(i - 1);
		p->m_npenType = m_npenType;
		Invalidate();
	}
}


void CStudyzbMFCPartGruopView::OnUpdatePenSolid(CCmdUI* pCmdUI)
{
	// TODO: 在此添加命令更新用户界面处理程序代码
	if (m_npenType == PS_SOLID)
		pCmdUI->SetCheck(true);
	else
		pCmdUI->SetCheck(false);
}


void CStudyzbMFCPartGruopView::OnPenDash()
{
	// TODO: 在此添加命令处理程序代码
	m_npenType = PS_DASH;
	if (changeType)
	{
		CStudyzbMFCPartGruopDoc* pDoc = GetDocument();
		ASSERT_VALID(pDoc);
		if (!pDoc)
			return;
		int i = pDoc->obArray.GetSize();
		CGraph* p = (CGraph*)pDoc->obArray.GetAt(i - 1);
		p->m_npenType = m_npenType;
		Invalidate();
	}
}


void CStudyzbMFCPartGruopView::OnUpdatePenDash(CCmdUI* pCmdUI)
{
	// TODO: 在此添加命令更新用户界面处理程序代码
	if (m_npenType == PS_DASH)
		pCmdUI->SetCheck(true);
	else
		pCmdUI->SetCheck(false);
}


void CStudyzbMFCPartGruopView::OnPenColor()
{
	// TODO: 在此添加命令处理程序代码
	CColorDialog dlg;
	if (dlg.DoModal() == IDOK)
	{
		m_npenColor = dlg.GetColor();
		if (changeType)
		{
			CStudyzbMFCPartGruopDoc* pDoc = GetDocument();
			ASSERT_VALID(pDoc);
			if (!pDoc)
				return;
			int i = pDoc->obArray.GetSize();
			CGraph* p = (CGraph*)pDoc->obArray.GetAt(i - 1);
			p->m_npenColor = m_npenColor;
			Invalidate();
		}
	}
}


void CStudyzbMFCPartGruopView::OnChangeFalse()
{
	// TODO: 在此添加命令处理程序代码
	changeType = 0;
}


void CStudyzbMFCPartGruopView::OnUpdateChangeFalse(CCmdUI* pCmdUI)
{
	// TODO: 在此添加命令更新用户界面处理程序代码
	if (changeType == 0)
		pCmdUI->SetCheck(true);
	else
		pCmdUI->SetCheck(false);
}

void CStudyzbMFCPartGruopView::OnChangeTrue()
{
	// TODO: 在此添加命令处理程序代码
	changeType = 1;
}


void CStudyzbMFCPartGruopView::OnUpdateChangeTrue(CCmdUI* pCmdUI)
{
	// TODO: 在此添加命令更新用户界面处理程序代码
	if (changeType == 1)
		pCmdUI->SetCheck(true);
	else
		pCmdUI->SetCheck(false);
}


void CStudyzbMFCPartGruopView::OnDrawTrue()
{
	// TODO: 在此添加命令处理程序代码
	drawType = 1;
}


void CStudyzbMFCPartGruopView::OnUpdateDrawTrue(CCmdUI* pCmdUI)
{
	// TODO: 在此添加命令更新用户界面处理程序代码
	if (drawType == 1)
		pCmdUI->SetCheck(true);
	else
		pCmdUI->SetCheck(false);
}



void CStudyzbMFCPartGruopView::OnDrawFalse()
{
	// TODO: 在此添加命令处理程序代码
	drawType = 0;
}


void CStudyzbMFCPartGruopView::OnUpdateDrawFalse(CCmdUI* pCmdUI)
{
	// TODO: 在此添加命令更新用户界面处理程序代码
	if (drawType == 0)
		pCmdUI->SetCheck(true);
	else
		pCmdUI->SetCheck(false);
}


void CStudyzbMFCPartGruopView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if (!drawType)
		return;
	CStudyzbMFCPartGruopDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	if (m_nType < 0 || m_nType>2)
		return;
	//upFlag = 0;
	/*m_ptStart = point;
	m_ptEnd = point;*/
	CGraph* p = new CGraph(m_nType, point, point, m_npenType, m_npenColor,m_nbrushType,m_nbrushColor);
	pDoc->obArray.Add(p);
	CView::OnLButtonDown(nFlags, point);
}


void CStudyzbMFCPartGruopView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if (!drawType)
		return;
	CStudyzbMFCPartGruopDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	if (m_nType < 0 || m_nType>2)
		return;
	//upFlag = 1;
	int i = pDoc->obArray.GetSize();
	CGraph* p = (CGraph*)pDoc->obArray.GetAt(i - 1);
	/*if (point != p->m_ptEnd)
	{
		p->m_ptEnd = point;
		draw();
	}*/
	Invalidate();
	CView::OnLButtonUp(nFlags, point);
}


void CStudyzbMFCPartGruopView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if (!drawType)
		return;
	if (nFlags == MK_LBUTTON)
	{
		CStudyzbMFCPartGruopDoc* pDoc = GetDocument();
		ASSERT_VALID(pDoc);
		if (!pDoc)
			return;
		if (m_nType < 0 || m_nType>2)
			return;
		//draw();
		/*m_ptEnd = point;*/
		int i = pDoc->obArray.GetSize();
		CGraph* p = (CGraph*)pDoc->obArray.GetAt(i - 1);
		p->m_ptEnd = point;
		Invalidate();
		//draw();
		CView::OnMouseMove(nFlags, point);
	}
}

//保存颜色设置至注册表
void CStudyzbMFCPartGruopView::OnDestroy()
{
	CView::OnDestroy();

	// TODO: 在此处添加消息处理程序代码
	HKEY m_hKey;
	if (RegOpenKey(HKEY_CURRENT_USER, "software\\StudyzbMFCPartGroup\\画笔", &m_hKey) != 0)
		RegCreateKey(HKEY_CURRENT_USER, "software\\StudyzbMFCPartGroup\\画笔", &m_hKey);
	RegSetValueEx(m_hKey, "颜色", 0, REG_DWORD, (BYTE*)&m_npenColor, sizeof(DWORD));
	
	if (RegOpenKey(HKEY_CURRENT_USER, "software\\StudyzbMFCPartGroup\\画刷", &m_hKey) != 0)
		RegCreateKey(HKEY_CURRENT_USER, "software\\StudyzbMFCPartGroup\\画刷", &m_hKey);
	RegSetValueEx(m_hKey, "颜色", 0, REG_DWORD, (BYTE*)&m_nbrushColor, sizeof(DWORD));
}


void CStudyzbMFCPartGruopView::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CMenu menu;
	CPoint menuPos = point;

	menu.LoadMenu(IDR_MENU_POPUP);

	CMenu* pPopup = menu.GetSubMenu(0);

	ClientToScreen(&menuPos);
	pPopup->TrackPopupMenu(TPM_LEFTALIGN | TPM_RIGHTBUTTON, menuPos.x, menuPos.y, this);
	CStudyzbMFCPartGruopDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	curGraph = -1;
	for (int i = pDoc->obArray.GetSize() - 1; i >= 0; i--)
	{
		CGraph* p = (CGraph*)pDoc->obArray.GetAt(i);
		int left, top, right, bottom;
		left = p->m_ptStart.x < p->m_ptEnd.x ? p->m_ptStart.x : p->m_ptEnd.x;
		right = p->m_ptStart.x > p->m_ptEnd.x ? p->m_ptStart.x : p->m_ptEnd.x;
		top = p->m_ptStart.y < p->m_ptEnd.y ? p->m_ptStart.y : p->m_ptEnd.y;
		bottom = p->m_ptStart.y > p->m_ptEnd.y ? p->m_ptStart.y : p->m_ptEnd.y;

		if (point.x >= left && point.x <= right && point.y >= top && point.y <= bottom)
		{
			curGraph = i;
			break;
		}
	}

	CView::OnRButtonDown(nFlags, point);
}


void CStudyzbMFCPartGruopView::OnPop()
{
	// TODO: 在此添加命令处理程序代码
	if (curGraph < 0)
		return;
	CStudyzbMFCPartGruopDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	CGraph* p = (CGraph*)pDoc->obArray.GetAt(curGraph);
	pDoc->obArray.RemoveAt(curGraph);
	pDoc->obArray.Add(p);
	Invalidate();
}


void CStudyzbMFCPartGruopView::OnBottom()
{
	// TODO: 在此添加命令处理程序代码
	if (curGraph < 0)
		return;
	CStudyzbMFCPartGruopDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	CGraph* p = (CGraph*)pDoc->obArray.GetAt(curGraph);
	pDoc->obArray.RemoveAt(curGraph);
	pDoc->obArray.InsertAt(0, p);
	Invalidate();
}


void CStudyzbMFCPartGruopView::OnGraphPro()
{
	// TODO: 在此添加命令处理程序代码
	CGraphPro dlg;
	dlg.DoModal();
}


void CStudyzbMFCPartGruopView::OnCalc()
{
	// TODO: 在此添加命令处理程序代码
	CCALC dlg;
	dlg.DoModal();
	/*CCALC *dlg = new CCALC;
	dlg->Create(IDD_CCALC);
	dlg->ShowWindow(SW_SHOWNA);*/
}


void CStudyzbMFCPartGruopView::OnGoldbach()
{
	// TODO: 在此添加命令处理程序代码
	CGlodbach *dlg = new CGlodbach;
	dlg->Create(IDD_CGlodbach);
	dlg->ShowWindow(SW_SHOWNA);
}


void CStudyzbMFCPartGruopView::OnSharemapServer()
{
	// TODO: 在此添加命令处理程序代码
	/*CShareMemServer dlg;
	dlg.DoModal();*/
	CShareMemServer* dlg = new CShareMemServer;
	dlg->Create(IDD_CShareMemServer);
	dlg->ShowWindow(SW_SHOWNA);
}


void CStudyzbMFCPartGruopView::OnSharemapClient()
{
	// TODO: 在此添加命令处理程序代码
	CShareMemClient* dlg = new CShareMemClient;
	dlg->Create(IDD_CShareMemClient);
	dlg->ShowWindow(SW_SHOWNA);
}


void CStudyzbMFCPartGruopView::OnCir()
{
	// TODO: 在此添加命令处理程序代码
	CCirFunc dlg;
	dlg.DoModal();
}


void CStudyzbMFCPartGruopView::OnLightCtr()
{
	// TODO: 在此添加命令处理程序代码
	CLightControl dlg;
	dlg.DoModal();
}


void CStudyzbMFCPartGruopView::OnDrawDlg()
{
	// TODO: 在此添加命令处理程序代码
	CDraw dlg;
	dlg.DoModal();
}


void CStudyzbMFCPartGruopView::OnCom()
{
	// TODO: 在此添加命令处理程序代码
	CCom dlg;
	dlg.DoModal();
}


void CStudyzbMFCPartGruopView::OnBrushNone()
{
	// TODO: 在此添加命令处理程序代码
	m_nbrushType = -2;
	if (changeType)
	{
		CStudyzbMFCPartGruopDoc* pDoc = GetDocument();
		ASSERT_VALID(pDoc);
		if (!pDoc)
			return;
		int i = pDoc->obArray.GetSize();
		CGraph* p = (CGraph*)pDoc->obArray.GetAt(i - 1);
		p->m_nbrushType = m_nbrushType;
		Invalidate();
		//draw();
	}
}


void CStudyzbMFCPartGruopView::OnUpdateBrushNone(CCmdUI* pCmdUI)
{
	// TODO: 在此添加命令更新用户界面处理程序代码
	if (m_nbrushType == -2)
		pCmdUI->SetCheck(true);
	else
		pCmdUI->SetCheck(false);
}


void CStudyzbMFCPartGruopView::OnBrushShuiping()
{
	// TODO: 在此添加命令处理程序代码
	m_nbrushType = HS_HORIZONTAL;
	if (changeType)
	{
		CStudyzbMFCPartGruopDoc* pDoc = GetDocument();
		ASSERT_VALID(pDoc);
		if (!pDoc)
			return;
		int i = pDoc->obArray.GetSize();
		CGraph* p = (CGraph*)pDoc->obArray.GetAt(i - 1);
		p->m_nbrushType = m_nbrushType;
		Invalidate();
		//draw();
	}
}


void CStudyzbMFCPartGruopView::OnUpdateBrushShuiping(CCmdUI* pCmdUI)
{
	// TODO: 在此添加命令更新用户界面处理程序代码
	if (m_nbrushType == HS_HORIZONTAL)
		pCmdUI->SetCheck(true);
	else
		pCmdUI->SetCheck(false);
}


void CStudyzbMFCPartGruopView::OnBrushChuizhi()
{
	// TODO: 在此添加命令处理程序代码
	m_nbrushType = HS_VERTICAL;
	if (changeType)
	{
		CStudyzbMFCPartGruopDoc* pDoc = GetDocument();
		ASSERT_VALID(pDoc);
		if (!pDoc)
			return;
		int i = pDoc->obArray.GetSize();
		CGraph* p = (CGraph*)pDoc->obArray.GetAt(i - 1);
		p->m_nbrushType = m_nbrushType;
		Invalidate();
		//draw();
	}
}


void CStudyzbMFCPartGruopView::OnUpdateBrushChuizhi(CCmdUI* pCmdUI)
{
	// TODO: 在此添加命令更新用户界面处理程序代码
	if (m_nbrushType == HS_VERTICAL)
		pCmdUI->SetCheck(true);
	else
		pCmdUI->SetCheck(false);
}


void CStudyzbMFCPartGruopView::OnBrushDuijioa()
{
	// TODO: 在此添加命令处理程序代码
	m_nbrushType = HS_FDIAGONAL;
	if (changeType)
	{
		CStudyzbMFCPartGruopDoc* pDoc = GetDocument();
		ASSERT_VALID(pDoc);
		if (!pDoc)
			return;
		int i = pDoc->obArray.GetSize();
		CGraph* p = (CGraph*)pDoc->obArray.GetAt(i - 1);
		p->m_nbrushType = m_nbrushType;
		Invalidate();
		//draw();
	}
}


void CStudyzbMFCPartGruopView::OnUpdateBrushDuijioa(CCmdUI* pCmdUI)
{
	// TODO: 在此添加命令更新用户界面处理程序代码
	if (m_nbrushType == HS_FDIAGONAL)
		pCmdUI->SetCheck(true);
	else
		pCmdUI->SetCheck(false);
}


void CStudyzbMFCPartGruopView::OnBrushFanduijiao()
{
	// TODO: 在此添加命令处理程序代码
	m_nbrushType = HS_BDIAGONAL;
	if (changeType)
	{
		CStudyzbMFCPartGruopDoc* pDoc = GetDocument();
		ASSERT_VALID(pDoc);
		if (!pDoc)
			return;
		int i = pDoc->obArray.GetSize();
		CGraph* p = (CGraph*)pDoc->obArray.GetAt(i - 1);
		p->m_nbrushType = m_nbrushType;
		Invalidate();
		//draw();
	}
}


void CStudyzbMFCPartGruopView::OnUpdateBrushFanduijiao(CCmdUI* pCmdUI)
{
	// TODO: 在此添加命令更新用户界面处理程序代码
	if (m_nbrushType == HS_BDIAGONAL)
		pCmdUI->SetCheck(true);
	else
		pCmdUI->SetCheck(false);
}


void CStudyzbMFCPartGruopView::OnBrushXiangjiao()
{
	// TODO: 在此添加命令处理程序代码
	m_nbrushType = HS_CROSS;
	if (changeType)
	{
		CStudyzbMFCPartGruopDoc* pDoc = GetDocument();
		ASSERT_VALID(pDoc);
		if (!pDoc)
			return;
		int i = pDoc->obArray.GetSize();
		CGraph* p = (CGraph*)pDoc->obArray.GetAt(i - 1);
		p->m_nbrushType = m_nbrushType;
		Invalidate();
		//draw();
	}
}


void CStudyzbMFCPartGruopView::OnUpdateBrushXiangjiao(CCmdUI* pCmdUI)
{
	// TODO: 在此添加命令更新用户界面处理程序代码
	if (m_nbrushType == HS_CROSS)
		pCmdUI->SetCheck(true);
	else
		pCmdUI->SetCheck(false);
}


void CStudyzbMFCPartGruopView::OnBrushColor()
{
	// TODO: 在此添加命令处理程序代码
	CColorDialog dlg;
	if (dlg.DoModal() == IDOK)
	{
		m_nbrushColor = dlg.GetColor();
		if (changeType)
		{
			CStudyzbMFCPartGruopDoc* pDoc = GetDocument();
			ASSERT_VALID(pDoc);
			if (!pDoc)
				return;
			int i = pDoc->obArray.GetSize();
			CGraph* p = (CGraph*)pDoc->obArray.GetAt(i - 1);
			p->m_nbrushColor = m_nbrushColor;
			Invalidate();
			//draw();
		}
	}
}


void CStudyzbMFCPartGruopView::OnColorSets()
{
	// TODO: 在此添加命令处理程序代码
	CString msg = "当前设置\r\n";
	CString str;
	str.Format("画笔：红-%4d, 绿-%4d, 蓝-%4d\r\n"
		, GetRValue(m_npenColor), GetGValue(m_npenColor), GetBValue(m_npenColor));
	msg += str;
	str.Format("画刷：红-%4d, 绿-%4d, 蓝-%4d\r\n"
		, GetRValue(m_nbrushColor), GetGValue(m_nbrushColor), GetBValue(m_nbrushColor));
	msg += str;
	MessageBox(msg);
}


void CStudyzbMFCPartGruopView::OnColorSet()
{
	// TODO: 在此添加命令处理程序代码
	CColorSet dlg;
	dlg.penColorRed = GetRValue(m_npenColor);
	dlg.penColorGreen = GetGValue(m_npenColor);
	dlg.penColorBlue = GetBValue(m_npenColor);

	dlg.brushColorRed = GetRValue(m_nbrushColor);
	dlg.brushColorGreen = GetGValue(m_nbrushColor);
	dlg.brushColorBlue = GetBValue(m_nbrushColor);

	dlg.DoModal();

	m_npenColor = RGB(dlg.penColorRed, dlg.penColorGreen, dlg.penColorBlue);
	m_nbrushColor = RGB(dlg.brushColorRed, dlg.brushColorGreen, dlg.brushColorBlue);

	if (changeType)
		Invalidate();
		//draw();
}


void CStudyzbMFCPartGruopView::OnSetBackpic()
{
	// TODO: 在此添加命令处理程序代码
	CString strFilter = "图像文件|*.jpg;*.bmp;*.gif;*.tif;*.png|\
						位图文件|*.bmp|JPEG文件|*.jpg|所有文件|*.*|";
	CFileDialog dlg(true, NULL, NULL, NULL, strFilter);
	if (dlg.DoModal() == IDOK)
	{
		fileName = dlg.GetPathName();
		CImage m_MyImage;
		m_MyImage.Load(fileName);
		CDC* pDC = GetDC();
		m_MyImage.Draw(pDC->m_hDC, 0, 0);
	}
}


void CStudyzbMFCPartGruopView::OnBrushPutong()
{
	// TODO: 在此添加命令处理程序代码
	m_nbrushType = -1;
	if (changeType)
	{
		CStudyzbMFCPartGruopDoc* pDoc = GetDocument();
		ASSERT_VALID(pDoc);
		if (!pDoc)
			return;
		int i = pDoc->obArray.GetSize();
		CGraph* p = (CGraph*)pDoc->obArray.GetAt(i - 1);
		p->m_nbrushType = m_nbrushType;
		Invalidate();
		//draw();
	}
}


void CStudyzbMFCPartGruopView::OnUpdateBrushPutong(CCmdUI* pCmdUI)
{
	// TODO: 在此添加命令更新用户界面处理程序代码
	if (m_nbrushType == -1)
		pCmdUI->SetCheck(true);
	else
		pCmdUI->SetCheck(false);
}
