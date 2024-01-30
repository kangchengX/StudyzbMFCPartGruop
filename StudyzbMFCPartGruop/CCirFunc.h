#pragma once


// CCirFunc 对话框

class CCirFunc : public CDialogEx
{
	DECLARE_DYNAMIC(CCirFunc)

public:
	CCirFunc(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CCirFunc();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CCirFunc };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	double* data1;//数据存储空间起始位置
	int bufSize1;//数据存储空间大小
	int dataCount1;//当前存储数据个数
	int x1, y1;//当前数据

	double* data2;
	int bufSize2;
	int dataCount2;
	int x2, y2;
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnDestroy();
	virtual BOOL OnInitDialog();
//	afx_msg void OnPaint();
	afx_msg void OnPaint();
};
