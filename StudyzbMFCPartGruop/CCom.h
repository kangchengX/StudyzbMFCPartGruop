#pragma once
#include "CComSocket.h"

// CCom 对话框

class CCom : public CDialogEx
{
	DECLARE_DYNAMIC(CCom)

public:
	CCom(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CCom();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CCom };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CIPAddressCtrl IPAdress;
	CString sendStr;
	CString recvStr;
	CComSocket chatSocket;
	virtual BOOL OnInitDialog();
	afx_msg void OnClose();
	afx_msg void OnBnClickedButton1();
};
