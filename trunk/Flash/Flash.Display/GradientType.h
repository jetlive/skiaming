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


#ifndef null
#define null NULL
#endif

#ifndef String
#define String string
#endif

#ifndef Number
#define Number float
#endif

	class	GradientType: public Object
	{
	public:
		static const String LINEAR  = "linear";//[��̬] ����ָ�����Խ�������ֵ�� GradientType 
		static const String RADIAL  = "radial";//[��̬] ����ָ������״��������ֵ�� GradientType 
	};
}