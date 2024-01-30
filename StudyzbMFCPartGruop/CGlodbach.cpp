// CGlodbach.cpp: 实现文件
//

#include "pch.h"
#include "StudyzbMFCPartGruop.h"
#include "CGlodbach.h"
#include "afxdialogex.h"


CCriticalSection  g_critSect;
int  g_iWorkerNum = 0;


struct Goldbach_Result
{
	unsigned int oddNum;
	unsigned int p1, p2, p3;
};


struct ThreadParam
{
	unsigned int oddNum;
	HWND hWnd;
};



BOOL IsPrime(unsigned int n);


void GetGoldbachResult(unsigned int oddNum, Goldbach_Result* pResult);


UINT ThreadFunc(LPVOID pParam)
{
	ThreadParam* ptp = (ThreadParam*)pParam;
	unsigned oddNum = ptp->oddNum;
	HWND hWnd = ptp->hWnd;
	delete ptp;

	Goldbach_Result* pResult = new Goldbach_Result;

	GetGoldbachResult(oddNum, pResult);

	g_critSect.Lock();
	g_iWorkerNum--;
	g_critSect.Unlock();


	::PostMessageA(hWnd, WM_USER_THREAD_FINISHED, (WPARAM)pResult, NULL);

	return 0;
}


void GetGoldbachResult(unsigned oddNum, Goldbach_Result* pResult)
{
	pResult->oddNum = oddNum;
	CArray<unsigned, unsigned&>littlePrime;
	CArray<unsigned, unsigned&>middlePrime;
	CArray<unsigned, unsigned&>largePrime;

	unsigned testNum = 3;
	while (testNum <= oddNum / 3)
	{
		if (IsPrime(testNum))
			littlePrime.Add(testNum);
		testNum += 2;
	}

	while (testNum <= 2 * oddNum / 3)
	{
		if (IsPrime(testNum))
			middlePrime.Add(testNum);
		testNum += 2;
	}

	while (testNum <= oddNum)
	{
		if (IsPrime(testNum))
			largePrime.Add(testNum);
		testNum += 2;
	}

	int i, j, k;
	//小，小，中；小，小，大；
	for (i = 0; i < littlePrime.GetSize(); i++)
	{
		for (j = 0; j < littlePrime.GetSize(); j++)
		{
			for (k = 0; k < middlePrime.GetSize(); k++)
			{
				if (oddNum == littlePrime.GetAt(i) + littlePrime.GetAt(j) + middlePrime.GetAt(k))
				{
					pResult->p1 = littlePrime.GetAt(i);
					pResult->p2 = littlePrime.GetAt(j);
					pResult->p3 = middlePrime.GetAt(k);
				}
			}
			for (k = 0; k < largePrime.GetSize(); k++)
			{
				if (oddNum == littlePrime.GetAt(i) + littlePrime.GetAt(j) + largePrime.GetAt(k))
				{
					pResult->p1 = littlePrime.GetAt(i);
					pResult->p2 = littlePrime.GetAt(j);
					pResult->p3 = largePrime.GetAt(k);
				}
			}
		}
		//小，中，中；小，中，大；
		for (j = 0; j < middlePrime.GetSize(); j++)
		{
			for (k = 0; k < middlePrime.GetSize(); k++)
			{
				if (oddNum == littlePrime.GetAt(i) + middlePrime.GetAt(j) + middlePrime.GetAt(k))
				{
					pResult->p1 = littlePrime.GetAt(i);
					pResult->p2 = middlePrime.GetAt(j);
					pResult->p3 = middlePrime.GetAt(k);
				}
			}
			for (k = 0; k < largePrime.GetSize(); k++)
			{
				if (oddNum == littlePrime.GetAt(i) + middlePrime.GetAt(j) + largePrime.GetAt(k))
				{
					pResult->p1 = littlePrime.GetAt(i);
					pResult->p2 = middlePrime.GetAt(j);
					pResult->p3 = largePrime.GetAt(k);
				}
			}
		}
	}
}


BOOL IsPrime(unsigned int n)
{
	if (n < 2)
		return FALSE;
	for (int i = 2; i < n; i++)
		if (n % i == 0)
			return FALSE;
	return TRUE;
};


// CGlodbach 对话框

IMPLEMENT_DYNAMIC(CGlodbach, CDialogEx)

CGlodbach::CGlodbach(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_CGlodbach, pParent)
	, m_iOddNum(0)
	, m_iWorkerNum(0)
{

}

CGlodbach::~CGlodbach()
{
}

void CGlodbach::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_ODDNUM, m_iOddNum);
	DDX_Control(pDX, IDC_GOLDBACHRESULT, m_GoldbachResultCtrl);
	DDX_Text(pDX, IDC_EDIT_WORKERNUM, m_iWorkerNum);
}


BEGIN_MESSAGE_MAP(CGlodbach, CDialogEx)
	ON_MESSAGE(WM_USER_THREAD_FINISHED, &CGlodbach::OnThreadFinished)//自己定义的消息映射
	ON_BN_CLICKED(IDC_BUTTON1, &CGlodbach::OnBnClickedButton1)
END_MESSAGE_MAP()


//线程结束消息映射函数定义
LRESULT  CGlodbach::OnThreadFinished(WPARAM wParam, LPARAM lParam)
{
	Goldbach_Result* pResult = (Goldbach_Result*)wParam;

	CString outputText;
	m_GoldbachResultCtrl.GetWindowTextA(outputText);

	CString strResult;

	strResult.Format("%u=%u+%u+%u\r\n",
		pResult->oddNum, pResult->p1, pResult->p2, pResult->p3);

	outputText += strResult;
	m_GoldbachResultCtrl.SetWindowTextA(outputText);

	delete pResult;

	g_critSect.Lock();
	m_iWorkerNum = g_iWorkerNum;
	g_critSect.Unlock();
	UpdateData(false);

	return 0;
}


// CGlodbach 消息处理程序


BOOL CGlodbach::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	g_critSect.Lock();
	m_iWorkerNum = g_iWorkerNum;
	g_critSect.Unlock();
	UpdateData(false);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


void CGlodbach::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);
	CString outputText;
	m_GoldbachResultCtrl.GetWindowTextA(outputText);
	//输入值不合法
	if (m_iOddNum % 2 == 0 || m_iOddNum < 9)
	{
		outputText = outputText + "输入错误：要求输入>=9的奇数\r\n";
		m_GoldbachResultCtrl.SetWindowTextA(outputText);
		return;
	}

	g_critSect.Lock();
	g_iWorkerNum++;
	m_iWorkerNum = g_iWorkerNum;
	g_critSect.Unlock();
	UpdateData(false);

	ThreadParam* ptp = new ThreadParam;
	ptp->oddNum = m_iOddNum;
	ptp->hWnd = this->m_hWnd;

	AfxBeginThread(ThreadFunc, ptp);
}
