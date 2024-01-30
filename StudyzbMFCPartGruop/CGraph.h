#pragma once

// CGraph 命令目标

class CGraph : public CObject
{
public:
	CPoint m_ptStart;
	CPoint m_ptEnd;
	int m_nType;
	int m_npenType;
	COLORREF m_npenColor;
	int m_nbrushType;
	COLORREF m_nbrushColor;
	CGraph(int type, CPoint start, CPoint end, int penType, COLORREF penColor, int brushType, COLORREF brushColor);
	virtual ~CGraph();
};


