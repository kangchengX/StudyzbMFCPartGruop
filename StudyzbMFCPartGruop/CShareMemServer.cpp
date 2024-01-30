// CShareMemServer.cpp: 实现文件
//

#include "pch.h"
#include "StudyzbMFCPartGruop.h"
#include "CShareMemServer.h"
#include "afxdialogex.h"


// CShareMemServer 对话框

IMPLEMENT_DYNAMIC(CShareMemServer, CDialogEx)

CShareMemServer::CShareMemServer(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_CShareMemServer, pParent)
	, writeStr(_T(""))
	, readStr(_T(""))
{

}

CShareMemServer::~CShareMemServer()
{
}

void CShareMemServer::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, writeStr);
	DDX_Text(pDX, IDC_EDIT2, readStr);
}


BEGIN_MESSAGE_MAP(CShareMemServer, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CShareMemServer::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CShareMemServer::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CShareMemServer::OnBnClickedButton3)
	ON_WM_DESTROY()
	ON_WM_CLOSE()
	ON_BN_CLICKED(IDC_BUTTON4, &CShareMemServer::OnBnClickedButton4)
END_MESSAGE_MAP()


// CShareMemServer 消息处理程序


void CShareMemServer::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	m_hMapFile = ::CreateFileMappingA(
		INVALID_HANDLE_VALUE,
		NULL,
		PAGE_READWRITE,
		0,
		BUF_SIZE,
		m_strMapFileName);
	if (m_hMapFile == NULL)
	{
		MessageBox("共享内存文件创建失败");
		return;
	}

	m_pBuf = (LPTSTR) ::MapViewOfFile(
		m_hMapFile,
		FILE_MAP_ALL_ACCESS,
		0,
		0,
		BUF_SIZE);
	if (m_pBuf == NULL)
	{
		MessageBox("文件映射失败");
		return;
	}

	CString strName = "SZBPGShareMemMutex";
	hMutex = ::OpenMutex(MUTEX_ALL_ACCESS, FALSE, strName);
	if (hMutex == NULL)
		hMutex = ::CreateMutex(NULL, NULL, strName);
	/*else
	{
		MessageBox("已有同名互斥量");
		return;
	}*/
}


void CShareMemServer::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	if (m_hMapFile == NULL)
	{
		MessageBox("未创建内存映射文件");
		return;
	}
	DWORD mutexSignal;
	mutexSignal = WaitForSingleObject(hMutex, 100);
	if (mutexSignal != WAIT_OBJECT_0)
	{
		switch (mutexSignal)
		{
		case WAIT_TIMEOUT:MessageBox("等待超时"); break;
		case WAIT_ABANDONED:MessageBox("用户端向内存映射文件写后没释放互斥量"); break;
		default:MessageBox("出现错误");
		}
		return;
	}
	UpdateData(true);
	//::RtlCopyMemory((PVOID)m_pBuf,(LPCTSTR)writeStr,writeStr.GetLength());
	DWORD strLength = writeStr.GetLength();
	::RtlCopyMemory((PVOID)m_pBuf, (LPCTSTR)&strLength, sizeof(strLength));
	::RtlCopyMemory((PVOID)(m_pBuf + sizeof(strLength)), (LPCTSTR)writeStr, strLength);
	ReleaseMutex(hMutex);
}


void CShareMemServer::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码
	if (m_hMapFile == NULL)
	{
		MessageBox("未创建内存映射文件");
		return;
	}
	char buff[BUF_SIZE] = { 0 };//这是因为CString无法转化为PVOID型,同时清除buff里数据
	DWORD strLength;
	::RtlCopyMemory((PVOID)&strLength, m_pBuf, sizeof(strLength));
	::RtlCopyMemory((PVOID)buff, m_pBuf + sizeof(strLength), strLength);
	//::RtlCopyMemory((PVOID)buff,m_pBuf, BUF_SIZE);
	readStr = buff;
	UpdateData(false);
}


BOOL CShareMemServer::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	m_hMapFile = NULL;
	m_strMapFileName = "SZBMFCPGShareMemMap";
	m_pBuf = NULL;
	hMutex = NULL;
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


void CShareMemServer::OnClose()
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CloseHandle(hMutex);
	CDialogEx::OnClose();
}


void CShareMemServer::OnBnClickedButton4()
{
	// TODO: 在此添加控件通知处理程序代码
	/*CloseHandle(hMutex);*/
	CloseHandle(hMutex);
}
