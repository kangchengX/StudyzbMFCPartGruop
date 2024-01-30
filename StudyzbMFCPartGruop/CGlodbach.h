#pragma once

#define   WM_USER_THREAD_FINISHED   WM_USER+100

// CGlodbach 对话框

class CGlodbach : public CDialogEx
{
	DECLARE_DYNAMIC(CGlodbach)

public:
	CGlodbach(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CGlodbach();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CGlodbach };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	int m_iOddNum;
	CEdit m_GoldbachResultCtrl;
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedButton1();
	int m_iWorkerNum;
	LRESULT  OnThreadFinished(WPARAM wParam, LPARAM lParam);
};
