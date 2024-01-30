// CCom.cpp: 实现文件
//

#include "pch.h"
#include "StudyzbMFCPartGruop.h"
#include "CCom.h"
#include "afxdialogex.h"


// CCom 对话框

IMPLEMENT_DYNAMIC(CCom, CDialogEx)

CCom::CCom(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_CCom, pParent)
	, sendStr(_T(""))
	, recvStr(_T(""))
{

}

CCom::~CCom()
{
}

void CCom::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_IPADDRESS1, IPAdress);
	DDX_Text(pDX, IDC_EDIT1, sendStr);
	DDX_Text(pDX, IDC_EDIT2, recvStr);
}


BEGIN_MESSAGE_MAP(CCom, CDialogEx)
	ON_WM_CLOSE()
	ON_BN_CLICKED(IDC_BUTTON1, &CCom::OnBnClickedButton1)
END_MESSAGE_MAP()


// CCom 消息处理程序


BOOL CCom::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	chatSocket.Create(4000, SOCK_DGRAM); // 端口为4000，使用数据报套接字
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


void CCom::OnClose()
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	chatSocket.Close();
	CDialogEx::OnClose();
}


void CCom::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);

	CString strIP;
	IPAdress.GetWindowTextA(strIP);

	chatSocket.SendTo(sendStr, sendStr.GetLength(), 4000, strIP);
}
