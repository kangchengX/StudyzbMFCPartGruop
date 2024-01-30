#pragma once


// CColorSet 对话框

class CColorSet : public CDialogEx
{
	DECLARE_DYNAMIC(CColorSet)

public:
	CColorSet(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CColorSet();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CColorSet };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	int penColorRed;
	int penColorGreen;
	int penColorBlue;
	int brushColorRed;
	int brushColorGreen;
	int brushColorBlue;
	afx_msg void OnBnClickedButton1();
	virtual BOOL OnInitDialog();
};
