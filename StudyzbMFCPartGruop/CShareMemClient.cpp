// CShareMemClient.cpp: 实现文件
//

#include "pch.h"
#include "StudyzbMFCPartGruop.h"
#include "CShareMemClient.h"
#include "afxdialogex.h"


// CShareMemClient 对话框

IMPLEMENT_DYNAMIC(CShareMemClient, CDialogEx)

CShareMemClient::CShareMemClient(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_CShareMemClient, pParent)
	, writeStr(_T(""))
	, readStr(_T(""))
{

}

CShareMemClient::~CShareMemClient()
{
}

void CShareMemClient::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_WRITE, writeStr);
	DDX_Text(pDX, IDC_EDIT_READ, readStr);
}


BEGIN_MESSAGE_MAP(CShareMemClient, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CShareMemClient::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CShareMemClient::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CShareMemClient::OnBnClickedButton3)
//	ON_WM_DESTROY()
END_MESSAGE_MAP()


// CShareMemClient 消息处理程序


BOOL CShareMemClient::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	m_hMapFile = NULL;
	m_strMapFileName = "SZBMFCPGShareMemMap";
	m_pBuf = NULL;
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


void CShareMemClient::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	m_hMapFile = ::OpenFileMapping(
		FILE_MAP_ALL_ACCESS,
		FALSE,
		m_strMapFileName);
	if (m_hMapFile == NULL)
	{
		MessageBox("共享内存文件打开失败");
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
	hMutex = OpenMutex(MUTEX_ALL_ACCESS, FALSE, strName);
	if (hMutex == NULL)
	{
		MessageBox("未创建互斥量");
		return;
	}
}


void CShareMemClient::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	if (m_hMapFile == NULL)
	{
		MessageBox("未打开内存映射文件");
		return;
	}
	DWORD mutexSignal;
	mutexSignal = WaitForSingleObject(hMutex, 100);
	if (mutexSignal != WAIT_OBJECT_0)
	{
		switch (mutexSignal)
		{
		case WAIT_TIMEOUT:MessageBox("等待超时"); break;
		case WAIT_ABANDONED:MessageBox("服务端向内存映射文件写后没释放互斥量"); break;
		default:MessageBox("出现错误");
		}
		return;
	}
	UpdateData(true);
	DWORD strLength = writeStr.GetLength();
	::RtlCopyMemory((PVOID)m_pBuf, (LPCTSTR)&strLength, sizeof(strLength));
	::RtlCopyMemory((PVOID)(m_pBuf + sizeof(strLength)), (LPCTSTR)writeStr, strLength);
	//::RtlCopyMemory((PVOID)m_pBuf,(LPCTSTR)writeStr,writeStr.GetLength());
	ReleaseMutex(hMutex);
}


void CShareMemClient::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码
	if (m_hMapFile == NULL)
	{
		MessageBox("未打开内存映射文件");
		return;
	}
	char buff[BUF_SIZE] = { 0 };
	DWORD strLength;
	::RtlCopyMemory((PVOID)&strLength, m_pBuf, sizeof(strLength));
	::RtlCopyMemory((PVOID)buff, m_pBuf + sizeof(strLength), strLength);
	//::RtlCopyMemory((PVOID)buff,m_pBuf, BUF_SIZE);
	readStr = buff;
	UpdateData(false);
}
