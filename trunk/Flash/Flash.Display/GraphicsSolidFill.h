#pragma once
#include "StdAfx.h"

namespace splght{
#ifndef Boolean
#define Boolean bool
#endif

#ifndef unit
#define uint unsigned int
#endif

#ifndef NaN
#define NaN -1
#endif

	//#define BitmapData SkBitmap	
#ifndef null
#define null NULL
#endif

#ifndef String
#define String string
#endif

#ifndef Number
#define Number float
#endif

/*
����ʵ����䡣 
�� GraphicsSolidFill ������ Graphics.drawGraphicsData() ����һ��ʹ�á�
���� GraphicsSolidFill ��������� Graphics.beginFill() �����ǵ�Ч�ġ�*/

	class	GraphicsSolidFill : public Object	//OK
	{
		//�����µ� GraphicsSolidFill ���� GraphicsSolidFill
		GraphicsSolidFill(uint  color= 0,Number   alpha= 1.0);
		//ָʾ���� Alpha ͸����ֵ�� GraphicsSolidFill
		Number alpha = 1.0 ;
		//������ɫ�� GraphicsSolidFill
		uint color = 0;
	};
}