#pragma once
#include "StdAfx.h"
#include "Object.h"
#include "BitmapData.h"
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
	//DisplayObject ���ǿɷ�����ʾ�б��е����ж���Ļ��ࡣ
	//����ʾ�б������Flash Player �� Adobe AIR ����ʾ�����ж���
	//ʹ�� DisplayObjectContainer ��������ʾ�б��е���ʾ����
	//DisplayObjectContainer �������������ʾ���󣬶�������ʾ������ Shape �� TextField �����ǡ�Ҷ���ڵ㣬
	//ֻ�и�����ͬ����û���Ӽ���
	//DisplayObject ��֧�ֻ������ܣ������� x �� y λ�ã���Ҳ֧�ָ��߼��Ķ������ԣ�������ת�����󣩡�
	//DisplayObject ��һ�ֳ�����ࣻ��ˣ�����ֱ�ӵ���DisplayObject������ new DisplayObject() ������ ArgumentError �쳣��
	//������ʾ���󶼼̳��� DisplayObject �ࡣ
	class	EventDispatcher: public Object
	{
	private:
		//�ۺ� EventDispatcher ���ʵ���� EventDispatcher
		EventDispatcher(IEventDispatcher  target= null);
		//ʹ�� EventDispatcher ����ע���¼�������������ʹ�������ܹ������¼�֪ͨ�� EventDispatcher
		void    addEventListener(String type,Function  listener,Boolean   useCapture= false,int   priority= 0,Boolean   useWeakReference= false);
		//���¼����ɵ��¼����С� EventDispatcher
		Boolean    dispatchEvent(Event event);
		//��� EventDispatcher �����Ƿ�Ϊ�ض��¼�����ע�����κ��������� EventDispatcher
		Boolean    hasEventListener(String type);
		//�� EventDispatcher ������ɾ���������� EventDispatcher
		void    removeEventListener(String type,Function  listener,Boolean   useCapture= false);
		//����Ƿ��ô� EventDispatcher ��������κ�ʼ��Ϊָ���¼�����ע�����¼��������� EventDispatcher
		Boolean    willTrigger(String type);

	};
}