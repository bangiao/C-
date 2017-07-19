
// [设计模式]解决问题二懒汉式单例问题解决mfc.h : PROJECT_NAME 应用程序的主头文件
//

#pragma once

#ifndef __AFXWIN_H__
	#error "在包含此文件之前包含“stdafx.h”以生成 PCH 文件"
#endif

#include "resource.h"		// 主符号


// C设计模式解决问题二懒汉式单例问题解决mfcApp: 
// 有关此类的实现，请参阅 [设计模式]解决问题二懒汉式单例问题解决mfc.cpp
//

class C设计模式解决问题二懒汉式单例问题解决mfcApp : public CWinApp
{
public:
	C设计模式解决问题二懒汉式单例问题解决mfcApp();

// 重写
public:
	virtual BOOL InitInstance();

// 实现

	DECLARE_MESSAGE_MAP()
};

extern C设计模式解决问题二懒汉式单例问题解决mfcApp theApp;