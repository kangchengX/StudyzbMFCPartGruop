// CComSocket.cpp: 实现文件
//

#include "pch.h"
#include "StudyzbMFCPartGruop.h"
#include "CComSocket.h"
#include "CCom.h"

// CComSocket

CComSocket::CComSocket()
{
}

CComSocket::~CComSocket()
{
}


// CComSocket 成员函数


void CComSocket::OnReceive(int nErrorCode)
{
	// TODO: 在此添加专用代码和/或调用基类
	char buf[1024] = { 0 };
	CString remoteIP;
	UINT remotePort;

	ReceiveFrom(buf, 1023, remoteIP, remotePort);

	CCom* pDlg = (CCom*)AfxGetMainWnd();
	pDlg->recvStr = buf;
	pDlg->UpdateData(false);
	CAsyncSocket::OnReceive(nErrorCode);
}
