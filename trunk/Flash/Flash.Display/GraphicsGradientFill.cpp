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

/*���彥����䡣 
�� GraphicsGradientFill ������ Graphics.drawGraphicsData() ����һ��ʹ�á�
���� GraphicsGradientFill ��������� Graphics.beginGradientFill() �����ǵ�Ч�ġ� */
	class	GraphicsGradientFill : public Object	//OK
	{
	public:
		//�����µ� GraphicsGradientFill ���� GraphicsGradientFill
		GraphicsGradientFill(String  type= "linear",Array   colors= null,Array   alphas= null,Array   ratios= null,*   matrix= null,*   spreadMethod= pad,String   interpolationMethod= "rgb",Number   focalPointRatio= 0.0);
	private:
		//colors �����еĶ�Ӧ��ɫ�� Alpha ֵ�����顣 GraphicsGradientFill
		Array alphas;
		//������ʹ�õ� RGB ʮ��������ɫֵ���顣 GraphicsGradientFill
		Array colors;
		//һ�����ƽ���Ľ���λ�õ����֡� GraphicsGradientFill
		Number focalPointRatio;
		//InterpolationMethod ��������ָ��Ҫʹ�õ�ֵ��ֵ�� GraphicsGradientFill
		String interpolationMethod;
		//һ���� Matrix �ඨ���ת������ GraphicsGradientFill
		Matrix matrix;
		//��ɫ�ֲ����������顣 GraphicsGradientFill
		Array ratios;
		//SpreadMethod ��������ָ��Ҫʹ�õ���չ������ֵ�� GraphicsGradientFill
		String spreadMethod;
		//GradientType ��������ָ��Ҫʹ�õĽ������͵�ֵ�� GraphicsGradientFill
		String type;

	};
}