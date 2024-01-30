
// StudyzbMFCPartGruopDoc.cpp: CStudyzbMFCPartGruopDoc 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "StudyzbMFCPartGruop.h"
#endif

#include "StudyzbMFCPartGruopDoc.h"
#include "CGraph.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CStudyzbMFCPartGruopDoc

IMPLEMENT_DYNCREATE(CStudyzbMFCPartGruopDoc, CDocument)

BEGIN_MESSAGE_MAP(CStudyzbMFCPartGruopDoc, CDocument)
END_MESSAGE_MAP()


// CStudyzbMFCPartGruopDoc 构造/析构

CStudyzbMFCPartGruopDoc::CStudyzbMFCPartGruopDoc() noexcept
{
	// TODO: 在此添加一次性构造代码

}

CStudyzbMFCPartGruopDoc::~CStudyzbMFCPartGruopDoc()
{
}

BOOL CStudyzbMFCPartGruopDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: 在此添加重新初始化代码
	// (SDI 文档将重用该文档)

	return TRUE;
}




// CStudyzbMFCPartGruopDoc 序列化

void CStudyzbMFCPartGruopDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: 在此添加存储代码
		for (int i = 0; i < obArray.GetSize(); i++)
		{
			CGraph* p = (CGraph*)obArray.GetAt(i);
			ar << p->m_nType << p->m_ptStart << p->m_ptEnd<<p->m_npenType<<p->m_npenColor<<p->m_nbrushType<<p->m_nbrushColor;
		}
	}
	else
	{
		// TODO: 在此添加加载代码
		int index = obArray.GetSize();
		while (index--)
		{
			delete (CGraph*)obArray.GetAt(index);//删图元
		}
		obArray.RemoveAll();//删数组
		CFile* pfile = ar.GetFile();
		while (1)
		{
			int nType;
			CPoint ptStart;
			CPoint ptEnd;
			COLORREF npenColor;
			int npenType;
			COLORREF nbrushColor;
			int nbrushType;
			UINT bytes;

			bytes = pfile->Read(&nType, sizeof(nType));
			bytes = pfile->Read(&ptStart, sizeof(ptStart));
			bytes = pfile->Read(&ptEnd, sizeof(ptEnd));
			bytes = pfile->Read(&npenType, sizeof(npenType));
			bytes = pfile->Read(&npenColor, sizeof(npenColor));
			bytes = pfile->Read(&nbrushType, sizeof(nbrushType));
			bytes = pfile->Read(&nbrushColor, sizeof(nbrushColor));

			if (bytes < sizeof(npenColor))
				break;
			CGraph* pGraph = new CGraph(nType, ptStart, ptEnd, npenType, npenColor, nbrushType, nbrushColor);
			obArray.Add(pGraph);
		}
	}
}

#ifdef SHARED_HANDLERS

// 缩略图的支持
void CStudyzbMFCPartGruopDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// 修改此代码以绘制文档数据
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// 搜索处理程序的支持
void CStudyzbMFCPartGruopDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// 从文档数据设置搜索内容。
	// 内容部分应由“;”分隔

	// 例如:     strSearchContent = _T("point;rectangle;circle;ole object;")；
	SetSearchContent(strSearchContent);
}

void CStudyzbMFCPartGruopDoc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = nullptr;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != nullptr)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// CStudyzbMFCPartGruopDoc 诊断

#ifdef _DEBUG
void CStudyzbMFCPartGruopDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CStudyzbMFCPartGruopDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CStudyzbMFCPartGruopDoc 命令


void CStudyzbMFCPartGruopDoc::DeleteContents()
{
	// TODO: 在此添加专用代码和/或调用基类
	int index = obArray.GetSize();
	while (index--)
	{
		delete (CGraph*)obArray.GetAt(index);//删图元
	}
	obArray.RemoveAll();//删数组
	CDocument::DeleteContents();
}
