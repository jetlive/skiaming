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
	//���� AccessibilityProperties ��ɿ��� Flash ���������ܣ�����Ļ�Ķ�������ʾ��
	//���Խ� AccessibilityProperties ���󸽼ӵ��κ���ʾ����
	//���� Flash Player ֻ���ȡ����ĳЩ���͵Ķ���� AccessibilityProperties ����
	//���� SWF �ļ����� DisplayObject.root ��ʽ��ʾ������������ DisplayObjectContainer �����ࣩ��
	//��ť��SimpleButton �����ࣩ�Լ��ı��� TextField �����ࣩ��


	class    IBitmapDrawable: public Object
	{

	};
}
