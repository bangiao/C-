
// [���ģʽ]������������ʽ����������mfcDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "[���ģʽ]������������ʽ����������mfc.h"
#include "[���ģʽ]������������ʽ����������mfcDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C���ģʽ������������ʽ����������mfcDlg �Ի���



C���ģʽ������������ʽ����������mfcDlg::C���ģʽ������������ʽ����������mfcDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(C���ģʽ������������ʽ����������mfcDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void C���ģʽ������������ʽ����������mfcDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(C���ģʽ������������ʽ����������mfcDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &C���ģʽ������������ʽ����������mfcDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// C���ģʽ������������ʽ����������mfcDlg ��Ϣ�������

BOOL C���ģʽ������������ʽ����������mfcDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO:  �ڴ���Ӷ���ĳ�ʼ������

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void C���ģʽ������������ʽ����������mfcDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR C���ģʽ������������ʽ����������mfcDlg::OnQueryDragIcon()
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

Singelton *Singelton::singel = NULL;	//����ʽ����������ʽ����������
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

void C���ģʽ������������ʽ����������mfcDlg::OnBnClickedButton1()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	main_1();
}
