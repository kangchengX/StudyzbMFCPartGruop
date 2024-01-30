#pragma once


// CCALC 对话框

class CCALC : public CDialogEx
{
	DECLARE_DYNAMIC(CCALC)

public:
	CCALC(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CCALC();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CCALC };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString calcStartFirst;
	CString clacStartSecond;
	CString clacEnd;
	int opt;
	afx_msg void OnBnClickedButton1();
};
