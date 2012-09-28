#pragma once
#include "StdAfx.h"
#include "Object.h"
#include <vector>
#include <string>
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
//���� SWF �ļ����� DisplayObject.root ��ʽ��ʾ������������DisplayObjectContainer �����ࣩ��
//��ť��SimpleButton �����ࣩ�Լ��ı���TextField �����ࣩ��


	class	AccessibilityProperties: public Object
	{
	private:
		String description;		//�ڳ��ָ�������ʱΪ����ʾ�����ṩһ��˵���� AccessibilityProperties 
		Boolean forceSimple;		//���Ϊ true����ᵼ�� Flash Player �Ӹ�����ʾ���ų�����ʾ�����ڵ��Ӷ��� AccessibilityProperties 
		String name;		//�ڳ��ָ�������ʱΪ����ʾ�����ṩһ�����ơ� AccessibilityProperties 
		Boolean noAutoLabeling;		//���Ϊ true������� Flash Player ��Ĭ���Զ���ǩϵͳ�� AccessibilityProperties 
		String shortcut;		//ָ�������ʾ��������Ŀ�ݼ��� AccessibilityProperties 
		Boolean silent;		//���Ϊ true�����ڳ��ָ�������ʱ�ų�����ʾ���� AccessibilityProperties 
	};
}