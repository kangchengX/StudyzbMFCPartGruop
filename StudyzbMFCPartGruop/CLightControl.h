#pragma once


// CLightControl 对话框

class CLightControl : public CDialogEx
{
	DECLARE_DYNAMIC(CLightControl)

public:
	CLightControl(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CLightControl();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CLightControl };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CStatic picRed;
	CStatic picYellow;
	CStatic picGreen;
	int tRed;
	int tYellow;
	int tGreen;
	CBitmap bitmapRed;
	HBITMAP hBmpRed;
	CBitmap bitmapYellow;
	HBITMAP hBmpYellow;
	CBitmap bitmapGreen;
	HBITMAP hBmpGreen;
	CBitmap bitmapGray;
	HBITMAP hBmpGray;
	afx_msg void OnEnChangeEdit1();
	afx_msg void OnEnChangeEdit2();
	afx_msg void OnEnChangeEdit3();
	afx_msg void OnBnClickedRadio1();
	afx_msg void OnBnClickedRadio2();
	afx_msg void OnBnClickedRadio3();
	int state;
	int tCorrent;
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	int mode;
	virtual BOOL OnInitDialog();
};
