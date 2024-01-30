#pragma once


// CDraw 对话框

class CDraw : public CDialogEx
{
	DECLARE_DYNAMIC(CDraw)

public:
	CDraw(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CDraw();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CDraw };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	int penType;
	BOOL penColorRed;
	BOOL penColorGreen;
	BOOL penColorBlue;
	int penColorLight;
	int penWidth;
	BOOL brushMod;
	int brushType;
	BOOL brushColorRed;
	BOOL brushColorGreen;
	BOOL brushColorBlue;
	int brushColorLight;
	BOOL backMod;
	BOOL backColorRed;
	BOOL backColorGreen;
	BOOL backColorBlue;
	int backColorLight;
	BOOL fontColorRed;
	BOOL fontColorGreen;
	BOOL fontColorBlue;
	int fontColorLight;
	CString fontType;
	int fontSize;
	CString textString;
	CPen pen;
	CBrush brush;
	CFont font;
	void setupPen();
	void setupBrush();
	void setupFont();
	void setupColor();
	COLORREF color[4];
	afx_msg void OnCbnSelchangeCombo1();
	afx_msg void OnBnClickedCheck12();
	afx_msg void OnBnClickedCheck13();
	afx_msg void OnBnClickedCheck14();
	afx_msg void OnBnClickedRadio2();
	afx_msg void OnBnClickedRadio3();
	afx_msg void OnEnChangeEdit2();
	afx_msg void OnBnClickedCheck1();
	afx_msg void OnCbnSelchangeCombo2();
	afx_msg void OnBnClickedCheck2();
	afx_msg void OnBnClickedCheck3();
	afx_msg void OnBnClickedCheck4();
	afx_msg void OnBnClickedRadio4();
	afx_msg void OnBnClickedRadio5();
	afx_msg void OnBnClickedCheck5();
	afx_msg void OnBnClickedCheck6();
	afx_msg void OnBnClickedCheck7();
	afx_msg void OnBnClickedCheck8();
	afx_msg void OnBnClickedRadio8();
	afx_msg void OnBnClickedRadio9();
	afx_msg void OnBnClickedCheck9();
	afx_msg void OnBnClickedCheck10();
	afx_msg void OnBnClickedCheck11();
	afx_msg void OnBnClickedRadio10();
	afx_msg void OnBnClickedRadio11();
	afx_msg void OnCbnSelchangeCombo3();
	afx_msg void OnEnChangeEdit3();
	afx_msg void OnEnChangeEdit1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton6();
	afx_msg void OnBnClickedButton7();
	afx_msg void OnBnClickedButton8();

	BOOL drawFlag;
	int drawType;
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	CPoint pStart;
	CPoint pEnd;
	void drawClient(BOOL flag);
	void drawPic();
	afx_msg void OnBnClickedButton1();
	CString exTextStr;
	afx_msg void OnEnChangeEdit4();
	CSpinButtonCtrl lineCtr;
	CSpinButtonCtrl fontCtr;
};
