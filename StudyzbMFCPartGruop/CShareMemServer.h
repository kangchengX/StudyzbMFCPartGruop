#pragma once

#define BUF_SIZE 1024

// CShareMemServer 对话框

class CShareMemServer : public CDialogEx
{
	DECLARE_DYNAMIC(CShareMemServer)

public:
	CShareMemServer(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CShareMemServer();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CShareMemServer };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString writeStr;
	CString readStr;
	HANDLE  m_hMapFile;	//内存映射文件对象句柄
	CString m_strMapFileName;	//内存映射文件名
	LPCTSTR m_pBuf;	//内存映射地址
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	HANDLE hMutex;
	virtual BOOL OnInitDialog();
	afx_msg void OnClose();
	afx_msg void OnBnClickedButton4();
};
