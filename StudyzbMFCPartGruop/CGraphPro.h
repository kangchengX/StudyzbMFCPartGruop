#pragma once


// CGraphPro 对话框

class CGraphPro : public CDialogEx
{
	DECLARE_DYNAMIC(CGraphPro)

public:
	CGraphPro(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CGraphPro();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CGraphPro };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CListBox fileList;
	afx_msg void OnBnClickedButton1();
	BOOL selFlag;
	BOOL openFlag;
	CPoint pStart, pEnd;
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
	CImage m_MyImage;
	CRect m_MyRect;
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton6();
	afx_msg void OnBnClickedButton7();
	afx_msg void OnBnClickedButton8();
	afx_msg void OnLbnSelchangeListFile();

	CRect picRect;
	BOOL selectFirst;
	afx_msg void OnBnClickedButton9();
	void draw();
};
