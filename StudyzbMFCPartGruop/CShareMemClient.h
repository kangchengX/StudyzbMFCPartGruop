#pragma once

#define BUF_SIZE 1024

// CShareMemClient 对话框

class CShareMemClient : public CDialogEx
{
	DECLARE_DYNAMIC(CShareMemClient)

public:
	CShareMemClient(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CShareMemClient();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CShareMemClient };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString writeStr;
	CString readStr;
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	HANDLE  m_hMapFile;	//内存映射文件句柄
	CString m_strMapFileName;	//内存映射文件名
	LPCTSTR m_pBuf;	//内存映射地址
	HANDLE hMutex;
//	afx_msg void OnDestroy();
};
