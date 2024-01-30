
// StudyzbMFCPartGruopView.h: CStudyzbMFCPartGruopView 类的接口
//

#pragma once


class CStudyzbMFCPartGruopView : public CView
{
protected: // 仅从序列化创建
	CStudyzbMFCPartGruopView() noexcept;
	DECLARE_DYNCREATE(CStudyzbMFCPartGruopView)

// 特性
public:
	CStudyzbMFCPartGruopDoc* GetDocument() const;
	/*CPoint m_ptStart;
	CPoint m_ptEnd;*///不需要，因为point会被obarray“存储”，就不需要了（和sdgn不同）
	int m_nType;
	int m_npenType;
	COLORREF m_npenColor;
	int m_nbrushType;
	COLORREF m_nbrushColor;
	int changeType;
	bool drawType;
	int curGraph;
	CString fileName;
	//BOOL upFlag;
	/*CImage m_MyImage;*/

// 操作
public:
	void draw();

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 实现
public:
	virtual ~CStudyzbMFCPartGruopView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnTypeLine();
	afx_msg void OnUpdateTypeLine(CCmdUI* pCmdUI);
	afx_msg void OnTypeRant();
	afx_msg void OnUpdateTypeRant(CCmdUI* pCmdUI);
	afx_msg void OnTypeEll();
	afx_msg void OnUpdateTypeEll(CCmdUI* pCmdUI);
	afx_msg void OnPenSolid();
	afx_msg void OnUpdatePenSolid(CCmdUI* pCmdUI);
	afx_msg void OnPenDash();
	afx_msg void OnUpdatePenDash(CCmdUI* pCmdUI);
	afx_msg void OnPenColor();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnDrawTrue();
	afx_msg void OnDrawFalse();
	afx_msg void OnDestroy();
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnChangeFalse();
	afx_msg void OnUpdateChangeFalse(CCmdUI* pCmdUI);
	afx_msg void OnUpdateChangeTrue(CCmdUI* pCmdUI);
	afx_msg void OnChangeTrue();
	afx_msg void OnUpdateDrawTrue(CCmdUI* pCmdUI);
	afx_msg void OnUpdateDrawFalse(CCmdUI* pCmdUI);
	afx_msg void OnPop();
	afx_msg void OnBottom();
	afx_msg void OnGraphPro();
	afx_msg void OnCalc();
	afx_msg void OnGoldbach();
	afx_msg void OnSharemapServer();
	afx_msg void OnSharemapClient();
	afx_msg void OnCir();
	afx_msg void OnLightCtr();
	afx_msg void OnDrawDlg();
	afx_msg void OnCom();
	afx_msg void OnBrushNone();
	afx_msg void OnUpdateBrushNone(CCmdUI* pCmdUI);
	afx_msg void OnBrushShuiping();
	afx_msg void OnUpdateBrushShuiping(CCmdUI* pCmdUI);
	afx_msg void OnBrushChuizhi();
	afx_msg void OnUpdateBrushChuizhi(CCmdUI* pCmdUI);
	afx_msg void OnBrushDuijioa();
	afx_msg void OnUpdateBrushDuijioa(CCmdUI* pCmdUI);
	afx_msg void OnBrushFanduijiao();
	afx_msg void OnUpdateBrushFanduijiao(CCmdUI* pCmdUI);
	afx_msg void OnBrushXiangjiao();
	afx_msg void OnUpdateBrushXiangjiao(CCmdUI* pCmdUI);
	afx_msg void OnBrushColor();
	afx_msg void OnColorSets();
	afx_msg void OnColorSet();
	afx_msg void OnSetBackpic();
	afx_msg void OnBrushPutong();
	afx_msg void OnUpdateBrushPutong(CCmdUI* pCmdUI);
};

#ifndef _DEBUG  // StudyzbMFCPartGruopView.cpp 中的调试版本
inline CStudyzbMFCPartGruopDoc* CStudyzbMFCPartGruopView::GetDocument() const
   { return reinterpret_cast<CStudyzbMFCPartGruopDoc*>(m_pDocument); }
#endif

