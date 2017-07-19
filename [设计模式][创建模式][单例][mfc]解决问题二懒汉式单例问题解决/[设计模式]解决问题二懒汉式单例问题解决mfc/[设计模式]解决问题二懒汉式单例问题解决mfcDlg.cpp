
// [设计模式]解决问题二懒汉式单例问题解决mfcDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "[设计模式]解决问题二懒汉式单例问题解决mfc.h"
#include "[设计模式]解决问题二懒汉式单例问题解决mfcDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C设计模式解决问题二懒汉式单例问题解决mfcDlg 对话框



C设计模式解决问题二懒汉式单例问题解决mfcDlg::C设计模式解决问题二懒汉式单例问题解决mfcDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(C设计模式解决问题二懒汉式单例问题解决mfcDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void C设计模式解决问题二懒汉式单例问题解决mfcDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(C设计模式解决问题二懒汉式单例问题解决mfcDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &C设计模式解决问题二懒汉式单例问题解决mfcDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// C设计模式解决问题二懒汉式单例问题解决mfcDlg 消息处理程序

BOOL C设计模式解决问题二懒汉式单例问题解决mfcDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO:  在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void C设计模式解决问题二懒汉式单例问题解决mfcDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR C设计模式解决问题二懒汉式单例问题解决mfcDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

static CCriticalSection cs;

class Singelton
{
public:
	static Singelton *GetSingelton()
	{
		if (NULL == Singelton::singel)
		{
			cs.Lock();
			if (NULL == Singelton::singel)
			{
				Singelton::singel = new Singelton;
			}
			cs.Unlock();
		}
		return singel;
	}
	void printS()
	{
		TRACE("num:%d\n", this->num);
	}
protected:
private:
	//
	Singelton()		//1. 
	{
		this->num++;
		TRACE("Singelton begin\n");
		Sleep(1000);
		TRACE("Singelton end\n");
	}
	~Singelton()
	{
		if (NULL != this->singel)
		{
			delete this->singel;
		}
		this->singel = NULL;
	}
private:
	static Singelton *singel;		//2. 
	static int num;
};

Singelton *Singelton::singel = NULL;	//饿汉式单例和懒汉式单例的区别
int Singelton::num = 0;

void threadFunc(void *p)
{
	DWORD id = GetCurrentThreadId();	//DWORD  ==> unsigned long
	Singelton::GetSingelton()->printS();
	TRACE("id:%d\n", id);
	return;
}

int main_1()
{
	int ret = 0;
	int threadnum = 3;
	int i = 0;
	unsigned int threadhal[100];
	/*
	_CRTIMP uintptr_t __cdecl _beginthread (_In_ void (__cdecl * _StartAddress) (void *),
	_In_ unsigned _StackSize, _In_opt_ void * _ArgList);
	*/
	for (i = 0; i < threadnum; i++)
	{
		threadhal[i] = _beginthread(threadFunc, 0, NULL);		//uintptr_t ==> unsigned int
	}
	for (i = 0; i < threadnum; i++)
	{
		WaitForSingleObject((HANDLE)threadhal[i], INFINITE);		//HANDLE == void *
	}
	TRACE("main()\n");
	return ret;
}

void C设计模式解决问题二懒汉式单例问题解决mfcDlg::OnBnClickedButton1()
{
	// TODO:  在此添加控件通知处理程序代码
	main_1();
}
