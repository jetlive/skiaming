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

/*
һ���ͼ�����Щ�������������� 
�� GraphicsPath ������ Graphics.drawGraphicsData() ����һ��ʹ�á�
���� GraphicsPath ��������� Graphics.drawPath() �����ǵ�Ч�ġ� 
GraphicsPath ������һ���Լ��ķ�����curveTo()��lineTo()��moveTo()��wideLineTo() 
�� wideMoveTo()������Щ������ Graphics �������ڵ��� GraphicsPath.commands 
�� GraphicsPath.data ʸ������ķ������ơ�*/


	class	GraphicsPath : public Object		//OK
	{
	public:
		//�����µ� GraphicsPath ���� GraphicsPath
		GraphicsPath(vector<int>  commands= null,vector<Number>   data= null,String   winding= "evenOdd");
		//���µġ�curveTo��������ӵ� commands ʸ����������������ӵ� data ʸ���� GraphicsPath
		void    curveTo(Number controlX,Number  controlY,Number  anchorX,Number  anchorY);
		//���µġ�lineTo��������ӵ� commands ʸ����������������ӵ� data ʸ���� GraphicsPath
		void    lineTo(Number x,Number  y);
		//���µġ�moveTo��������ӵ� commands ʸ����������������ӵ� data ʸ���� GraphicsPath
		void    moveTo(Number x,Number  y);
		//���µġ�wideLineTo��������ӵ� commands ʸ����������������ӵ� data ʸ���� GraphicsPath
		void    wideLineTo(Number x,Number  y);
		//���µġ�wideMoveTo��������ӵ� commands ʸ����������������ӵ� data ʸ���� GraphicsPath
		void    wideMoveTo(Number x,Number  y);
	private:
		//�ɻ滭����ɵ�ʸ�������е�������ʾ·���� GraphicsPath
		vector<int> commands;
		//�����ֹ��ɵ�ʸ�������а������ͼ����һ��ʹ�õĲ����� GraphicsPath
		vector<Number> data;
		//ʹ�� GraphicsPathWinding ���ж����ֵָ�����ƹ��� GraphicsPath
		String winding;

	};
}