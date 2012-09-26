#pragma once
#include "StdAfx.h"
#include "DisplayObject.h"
#include "InteractiveObject.h"
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

/*DisplayObjectContainer ���ǿ�������ʾ�б�����ʾ�������������ж���Ļ��ࡣ
����ʾ�б������ Flash Player �� Adobe AIR ����ʾ�����ж���
ʹ�� DisplayObjectContainer ��������ʾ�б��е���ʾ����ÿ�� DisplayObjectContainer 
�������Լ����Ӽ��б�������֯����� Z ��˳��Z ��˳������ǰ�����˳��
��ȷ���ĸ����������ǰ���ĸ���������ں�ȡ� 
DisplayObject ��һ�ֳ�����ࣻ��ˣ�����ֱ�ӵ��� DisplayObject��
���� new DisplayObject() ������ ArgumentError �쳣��
DisplayObjectContainer ���ǿ��԰����Ӷ�������ж���ĳ�����ࡣ
�޷�ֱ�Ӷ������ʵ���������� new DisplayObjectContainer() ���캯��
������ ArgumentError �쳣��*/
	class	DisplayObjectContainer : public  InteractiveObject 
	{
	public:
		//�����µ� DisplayObjectContainer() ���캯�������� ArgumentError �쳣�� DisplayObjectContainer
		DisplayObjectContainer( );
		//��һ�� DisplayObject ��ʵ����ӵ��� DisplayObjectContainer ʵ���С� DisplayObjectContainer
		DisplayObject    addChild(DisplayObject child);
		//��һ�� DisplayObject ��ʵ����ӵ��� DisplayObjectContainer ʵ���С� DisplayObjectContainer
		DisplayObject    addChildAt(DisplayObject child,int  index);
		//ָʾ��ȫ�����Ƿ�ᵼ�³���������������б��к�����ʹ��ָ�� point ����� DisplayObjectContainer.getObjectsUnderPoint() ����ʱ���ص�������ʾ���� DisplayObjectContainer
		Boolean    areInaccessibleObjectsUnderPoint(Point point);
		//ȷ��ָ����ʾ������ DisplayObjectContainer ʵ��������Ǹ�ʵ������ DisplayObjectContainer
		Boolean    contains(DisplayObject child);
		//����λ��ָ��������������ʾ����ʵ���� DisplayObjectContainer
		DisplayObject    getChildAt(int index);
		//���ؾ���ָ�����Ƶ�����ʾ���� DisplayObjectContainer
		DisplayObject    getChildByName(String name);
		//���� DisplayObject �� child ʵ��������λ�á� DisplayObjectContainer
		int    getChildIndex(DisplayObject child);
		//���ض�������飬��Щ����λ��ָ�����£������Ǹ� DisplayObjectContainer ʵ���������������������ƣ��� DisplayObjectContainer
		Array    getObjectsUnderPoint(Point point);
		//�� DisplayObjectContainer ʵ�������б���ɾ��ָ���� child DisplayObject ʵ���� DisplayObjectContainer
		DisplayObject    removeChild(DisplayObject child);
		//�� DisplayObjectContainer �����б���ָ���� index λ��ɾ���� DisplayObject�� DisplayObjectContainer
		DisplayObject    removeChildAt(int index);
		//����������������ʾ���������е�λ�á� DisplayObjectContainer
		void    setChildIndex(DisplayObject child,int  index);
		//��������ָ���Ӷ���� Z ��˳�򣨴�ǰ����˳�򣩡� DisplayObjectContainer
		void    swapChildren(DisplayObject child1,DisplayObject  child2);
		//���Ӽ��б�������ָ��������λ�ã������Ӷ���� Z ��˳��ǰ��˳�򣩡� DisplayObjectContainer
		void    swapChildrenAt(int index1,int  index2);
	private:
		//ȷ������������Ƿ�֧����ꡣ DisplayObjectContainer
		Boolean mouseChildren;
		//[ֻ��] ���ش˶����������Ŀ�� DisplayObjectContainer
		int numChildren;
		//ȷ������������Ƿ�֧�� Tab ���� DisplayObjectContainer
		Boolean tabChildren;
		//[ֻ��] ���ش� DisplayObjectContainer ʵ���� TextSnapshot ���� DisplayObjectContainer
		flash.text:TextSnapshot textSnapshot;

	};
}