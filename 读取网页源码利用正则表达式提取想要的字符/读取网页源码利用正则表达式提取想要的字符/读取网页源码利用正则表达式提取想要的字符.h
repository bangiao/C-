
// ��ȡ��ҳԴ������������ʽ��ȡ��Ҫ���ַ�.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// C��ȡ��ҳԴ������������ʽ��ȡ��Ҫ���ַ�App: 
// �йش����ʵ�֣������ ��ȡ��ҳԴ������������ʽ��ȡ��Ҫ���ַ�.cpp
//

class C��ȡ��ҳԴ������������ʽ��ȡ��Ҫ���ַ�App : public CWinApp
{
public:
	C��ȡ��ҳԴ������������ʽ��ȡ��Ҫ���ַ�App();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern C��ȡ��ҳԴ������������ʽ��ȡ��Ҫ���ַ�App theApp;