#pragma once
#include "StdAfx.h"
#include "DisplayObject.h"
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
/*InteractiveObject �����û�����ʹ�����ͼ�����֮������������ʾ����ĳ�����ࡣ 
����ֱ��ʵ���� InteractiveObject �ࡣ���� new InteractiveObject() ���캯����
���� ArgumentError �쳣��
InteractiveObject �౾�������κ���������Ļ�ϳ������ݵ� API�����ڴ�ԭ��
���Ҫ���� InteractiveObject ���һ���Զ������࣬������Ҫ��չ����һ����������Ļ
����ʾ���ݵ� API �����࣬�� Sprite��SimpleButton��TextField �� MovieClip �ࡣ*/


	class	InteractiveObject : public DisplayObject
	{
	public:
		InteractiveObject();	//�����µ� InteractiveObject() ���캯�������� ArgumentError �쳣��
	private:
		NativeMenu contextMenu;	//ָ����˶���������������Ĳ˵��� InteractiveObject 
		Boolean doubleClickEnabled;	//ָ���˶����Ƿ���� doubleClick �¼��� InteractiveObject 
		Object focusRect;	//ָ���˶����Ƿ���ʾ������Ρ� InteractiveObject 
		Boolean tabEnabled;	//ָ���˶����Ƿ���ѭ Tab ��˳�� InteractiveObject 
		int tabIndex;	//ָ�� SWF �ļ��еĶ��� Tab ��˳�����С� InteractiveObject 
	};
}