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
/*
����������ʽ��ʴ��� 
�� GraphicsStroke ������ Graphics.drawGraphicsData() ����һ��ʹ�á�
���� GraphicsStroke �������������������ʽ�� Graphics ��ķ���֮һ
������ Graphics.lineStyle() ������Graphics.lineBitmapStyle() ������ 
Graphics.lineGradientStyle() �������ǵ�Ч�ġ� */


	class	GraphicsStroke: public Object	//OK
	{
	public:
		//�����µ� GraphicsStroke ���� GraphicsStroke
		GraphicsStroke(Number  thickness= NaN,Boolean   pixelHinting= false,String   scaleMode= "normal",String   caps= "none",String   joints= "round",Number   miterLimit= 3.0,IGraphicsFill   fill= null);
	private:
		//ָ��������β���Ķ˵�����͡� GraphicsStroke
		String caps;
		//ָ�������������ʴ������ݵ�ʵ���� GraphicsStroke
		IGraphicsFill fill;
		//ָ���սǴ�ʹ�õ�������۵����͡� GraphicsStroke
		String joints;
		//ָʾ�����ĸ�����λ���жϼ�ǡ� GraphicsStroke
		Number miterLimit;
		//ָ���Ƿ���ʾ�ʴ������������ء� GraphicsStroke
		Boolean pixelHinting;
		//ָ���ʴ���ϸ���š� GraphicsStroke
		String scaleMode;
		//ָʾ�԰�Ϊ��λ��������ϸ����ЧֵΪ 0 �� 255�� GraphicsStroke
		Number thickness;

	};
}