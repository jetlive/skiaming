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


/*ָʾͼ�����Ľ������� GraphicsEndFill ������ Graphics.drawGraphicsData() 
����һ��ʹ�á� 
���� GraphicsEndFill ��������� Graphics.endFill() �����ǵ�Ч�ġ�*/ 


	class	GraphicsEndFill : public Object	//OK
	{
	public:
		//������ Graphics.drawGraphicsData() ����һ��ʹ�õĶ�������ʽ������䡣 GraphicsEndFill 
		GraphicsEndFill();
			
	};
}