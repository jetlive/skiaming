
// SkiaTest.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CSkiaTestApp:
// �йش����ʵ�֣������ SkiaTest.cpp
//

class CSkiaTestApp : public CWinApp
{
public:
	CSkiaTestApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CSkiaTestApp theApp;