#pragma once
#include "StdAfx.h"
#include "Object.h"
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
//BitmapFilterQuality ���а�����ֵ�������� BitmapFilter ����ĳ���Ʒ�ʡ� 


	class    BitmapFilterQuality: public Object
	{
	public:
		// [��̬] �����Ʒ���˾����á� BitmapFilterQuality 
		int HIGH = 3
		//[��̬] �����Ʒ���˾����á� BitmapFilterQuality 
		int LOW = 1
		//[��̬] �����е�Ʒ���˾����á� 
		int MEDIUM = 2
	};
}
