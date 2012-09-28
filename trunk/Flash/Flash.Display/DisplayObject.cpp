#pragma once
#include "StdAfx.h"
#include "Object.h"
#include "AccessibilityProperties.h"
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
	class	DisplayObject: public EventDispatcher
	{
	private:
		AccessibilityProperties accessibilityProperties;	//����ʾ����ĵ�ǰ��������ѡ� DisplayObject
		Number alpha;		//ָʾָ������� Alpha ͸����ֵ�� DisplayObject 
		String blendMode;	//BlendMode ���е�һ��ֵ������ָ��Ҫʹ�õĻ��ģʽ�� DisplayObject 
		Shader blendShader;		 //[ֻд] �������ڻ��ǰ���ͱ�������ɫ���� DisplayObject 
		Boolean cacheAsBitmap;	//�������Ϊ true���� Flash Player �� Adobe AIR ��������ʾ������ڲ�λͼ��ʾ��ʽ�� DisplayObject 
		Array filters;		//������ǰ����ʾ���������ÿ���˾�������������顣 DisplayObject 
		Number height;	//ָʾ��ʾ����ĸ߶ȣ�������Ϊ��λ�� DisplayObject 
		LoaderInfo loaderInfo;	//[ֻ��] ����һ�� LoaderInfo �������а������ش���ʾ�����������ļ��������Ϣ�� DisplayObject 
		DisplayObject mask;		//������ʾ����ָ���� mask �������֡� DisplayObject 
		Number mouseX;		//[ֻ��] ָʾ���λ�õ� x ���꣬������Ϊ��λ�� DisplayObject 
		Number mouseY;		//[ֻ��] ָʾ���λ�õ� y ���꣬������Ϊ��λ�� DisplayObject 
		String name;			//ָʾ DisplayObject ��ʵ�����ơ� DisplayObject 
		Object opaqueBackground;	//ָ����ʾ�����Ƿ����ھ���ĳ�ֱ�����ɫ����͸���� DisplayObject 
		DisplayObjectContainer parent;		//[ֻ��] ָʾ��������ʾ����� DisplayObjectContainer ���� DisplayObject 
		DisplayObject root;	//[ֻ��] ���ڼ��ص� SWF �ļ��е���ʾ����root �����Ǵ� SWF �ļ�����ʾ����ʾ�б����ṹ�����еĶ�����ʾ���� DisplayObject 
		Number rotation;		//ָʾ DisplayObject ʵ������ԭʼ�������ת�̶ȣ��Զ�Ϊ��λ�� DisplayObject 
		Number rotationX;	//ָʾ DisplayObject ʵ������� 3D ������������ԭʼ����� x ����ת���Զ�Ϊ��λ���� DisplayObject 
		Number rotationY;	//ָʾ DisplayObject ʵ������� 3D ������������ԭʼ����� y ����ת���Զ�Ϊ��λ���� DisplayObject 
		Number rotationZ;	//ָʾ DisplayObject ʵ������� 3D ������������ԭʼ����� z ����ת���Զ�Ϊ��λ���� DisplayObject 
		Rectangle scale9Grid;	//��ǰ��Ч���������� DisplayObject 
		Number scaleX;		//ָʾ��ע��㿪ʼӦ�õĶ����ˮƽ���ű������ٷֱȣ��� DisplayObject 
		Number scaleY;		//ָʾ�Ӷ���ע��㿪ʼӦ�õĶ���Ĵ�ֱ���ű������ٷֱȣ��� DisplayObject 
		Number scaleZ;	//ָʾ�Ӷ����ע��㿪ʼӦ�õĶ����������ű������ٷֱȣ��� DisplayObject 
		Rectangle scrollRect;		//��ʾ����Ĺ������η�Χ�� DisplayObject 
		Stage stage;		//[ֻ��] ��ʾ�������̨�� DisplayObject 
		Transform transform;	//һ�����󣬾�������ʾ����ľ�����ɫת�������ط�Χ�йص����ԡ� DisplayObject 
		Boolean visible;			//��ʾ�����Ƿ�ɼ��� DisplayObject 
		Number width;		//ָʾ��ʾ����Ŀ�ȣ�������Ϊ��λ�� DisplayObject 
		Number x;		//ָʾ DisplayObject ʵ������ڸ��� DisplayObjectContainer ��������� x ���ꡣ DisplayObject 
		Number y;		//ָʾ DisplayObject ʵ������ڸ��� DisplayObjectContainer ��������� y ���ꡣ DisplayObject 
		Number z;			//ָʾ DisplayObject ʵ������� 3D �������� z ��� z ����λ�á� 
	};
}