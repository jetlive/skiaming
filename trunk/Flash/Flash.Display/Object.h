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

	class	Object
	{
	public:
		Object();
		bool hasOwnProperty(char* name);
		bool  isPrototypeOf(Object theClass);
		bool propertyIsEnumerable(char* name);
		void setPropertyIsEnumerable(char*name, bool isEnum = true);
		char* toLocaleString();
		Object valueOf();
		virtual String Prototypename();
	private:
		Object constructor;	//���������������ʵ���Ĺ��캯�������á� Object 
		Object prototype;		//[��̬] ������������ԭ�Ͷ�������á� Object

	};
}