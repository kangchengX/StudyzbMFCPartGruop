#pragma once
#include <afxsock.h> 
//#include <WinSock2.h>
#pragma comment(lib, "ws2_32.lib")

// CComSocket 命令目标

class CComSocket : public CAsyncSocket
{
public:
	CComSocket();
	virtual ~CComSocket();
	virtual void OnReceive(int nErrorCode);
};


