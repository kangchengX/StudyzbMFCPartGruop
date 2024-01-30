// CGraph.cpp: 实现文件
//

#include "pch.h"
#include "StudyzbMFCPartGruop.h"
#include "CGraph.h"


// CGraph

CGraph::CGraph(int type, CPoint start, CPoint end, int penType, COLORREF penColor, int brushType, COLORREF brushColor)
{
	m_nType = type;
	m_ptStart = start;
	m_ptEnd = end;
	m_npenType = penType;
	m_npenColor = penColor;
	m_nbrushType = brushType;
	m_nbrushColor = brushColor;
}

CGraph::~CGraph()
{
}


// CGraph 成员函数
