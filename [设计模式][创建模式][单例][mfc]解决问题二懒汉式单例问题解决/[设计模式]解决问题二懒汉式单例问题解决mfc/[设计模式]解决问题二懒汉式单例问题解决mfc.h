
// [���ģʽ]������������ʽ����������mfc.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// C���ģʽ������������ʽ����������mfcApp: 
// �йش����ʵ�֣������ [���ģʽ]������������ʽ����������mfc.cpp
//

class C���ģʽ������������ʽ����������mfcApp : public CWinApp
{
public:
	C���ģʽ������������ʽ����������mfcApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern C���ģʽ������������ʽ����������mfcApp theApp;