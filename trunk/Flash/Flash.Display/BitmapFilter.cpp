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
	//BitmapFilter ��������ͼ���˾�Ч���Ļ��ࡣ 
	//BevelFilter��BlurFilter��ColorMatrixFilter��ConvolutionFilter��DisplacementMapFilter��DropShadowFilter��
	//GlowFilter��GradientBevelFilter �� GradientGlowFilter �඼��չ�� BitmapFilter �ࡣ
	//�����Խ���Щ�˾�Ч��Ӧ�����κ���ʾ����
	//������ֱ��ʵ��������չ BitmapFilter��

	class	BitmapFilter: public Object
	{
	public:
		//���� BitmapFilter ����������ԭʼ BitmapFilter ������ȫ��ͬ�ĸ����� BitmapFilter 
		BitmapFilter clone();
			
	};
}