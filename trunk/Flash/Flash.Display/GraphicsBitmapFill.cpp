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

/*����λͼ��䡣�ɶ�λͼ����ƽ�������ظ�λͼ��ƽ��λͼ���������
��ʹ��ת��������λͼ�� 
�� GraphicsBitmapFill ������ Graphics.drawGraphicsData() ����һ��ʹ�á�
���� GraphicsBitmapFill ��������� Graphics.beginBitmapFill() �����ǵ�Ч�ġ�*/

	class	GraphicsBitmapFill : public Object	//OK
	{
	public:
		//�����µ� GraphicsBitmapFill ���� GraphicsBitmapFill
		GraphicsBitmapFill(BitmapData  bitmapData= null,Matrix   matrix= null,Boolean   repeat= true,Boolean   smooth= false);
	private:
		//͸���Ļ�͸����λͼͼ�� GraphicsBitmapFill
		BitmapData bitmapData;
		//һ�����ڶ���λͼ�ϵ�ת���� Matrix �������� flash.geom.Matrix �ࣩ�� GraphicsBitmapFill
		Matrix matrix;
		//ָ���Ƿ���ƽ��ģʽ�ظ�λͼͼ�� GraphicsBitmapFill
		Boolean repeat;
		//ָ���Ƿ�ƽ�������㷨Ӧ����λͼͼ�� GraphicsBitmapFill
		Boolean smooth;

	};
}