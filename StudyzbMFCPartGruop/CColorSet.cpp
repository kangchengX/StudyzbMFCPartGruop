// CColorSet.cpp: 实现文件
//

#include "pch.h"
#include "StudyzbMFCPartGruop.h"
#include "CColorSet.h"
#include "afxdialogex.h"


// CColorSet 对话框

IMPLEMENT_DYNAMIC(CColorSet, CDialogEx)

CColorSet::CColorSet(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_CColorSet, pParent)
	, penColorRed(0)
	, penColorGreen(0)
	, penColorBlue(0)
	, brushColorRed(0)
	, brushColorGreen(0)
	, brushColorBlue(0)
{

}

CColorSet::~CColorSet()
{
}

void CColorSet::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, penColorRed);
	DDX_Text(pDX, IDC_EDIT2, penColorGreen);
	DDX_Text(pDX, IDC_EDIT3, penColorBlue);
	DDX_Text(pDX, IDC_EDIT4, brushColorRed);
	DDX_Text(pDX, IDC_EDIT5, brushColorGreen);
	DDX_Text(pDX, IDC_EDIT6, brushColorBlue);
}


BEGIN_MESSAGE_MAP(CColorSet, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CColorSet::OnBnClickedButton1)
END_MESSAGE_MAP()


// CColorSet 消息处理程序


void CColorSet::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
}


BOOL CColorSet::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	UpdateData(false);
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}
