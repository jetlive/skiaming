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
	
	class    Scene: public Object
	{
			Array labels;	 //[ֻ��] һ���ɳ����� FrameLabel ������ɵ����顣 Scene 
			String name;	//[ֻ��] ���������ơ� Scene 
			int numFrames;		//[ֻ��] �����е�֡���� Scene 
	};
}
