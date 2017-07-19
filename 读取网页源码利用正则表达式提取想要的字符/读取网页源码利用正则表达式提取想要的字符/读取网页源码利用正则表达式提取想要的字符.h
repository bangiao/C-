
// 读取网页源码利用正则表达式提取想要的字符.h : PROJECT_NAME 应用程序的主头文件
//

#pragma once

#ifndef __AFXWIN_H__
	#error "在包含此文件之前包含“stdafx.h”以生成 PCH 文件"
#endif

#include "resource.h"		// 主符号


// C读取网页源码利用正则表达式提取想要的字符App: 
// 有关此类的实现，请参阅 读取网页源码利用正则表达式提取想要的字符.cpp
//

class C读取网页源码利用正则表达式提取想要的字符App : public CWinApp
{
public:
	C读取网页源码利用正则表达式提取想要的字符App();

// 重写
public:
	virtual BOOL InitInstance();

// 实现

	DECLARE_MESSAGE_MAP()
};

extern C读取网页源码利用正则表达式提取想要的字符App theApp;