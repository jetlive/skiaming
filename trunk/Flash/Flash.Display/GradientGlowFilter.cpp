#pragma once
#include "StdAfx.h"
#include "Object.h"
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
/*��ʹ�� GradientGlowFilter �����ʾ����Ӧ�ý��䷢��Ч�������䷢����һ�ַǳ�����ķ���Ч���������Կ�����ɫ���䡣
�����ڶ������Ե����Ե����Χ���߶���Ķ���Ӧ�ý��䷢�⡣�����Խ��˾�Ӧ�����κ���ʾ���󣨼����� DisplayObject 
��̳еĶ��󣩣����� MovieClip��SimpleButton��TextField �� Video �����Լ� BitmapData ���� 
�˾��ľ���ʹ��ȡ����ҪӦ���˾��Ķ���
Ҫ����ʾ����Ӧ���˾�����ʹ�� filters ���ԡ����ö���� filters ���Բ����޸���Ӧ�Ķ��󣬶���� filters ���Կ���ɾ����Ӧ���˾��� 
Ҫ�� BitmapData ����Ӧ���˾�����ʹ�� BitmapData.applyFilter() �������� BitmapData ������� applyFilter() ��
ȡ��Դ BitmapData ������˾����󣬲���������һ������ͼ�� 
�������ʾ����Ӧ���˾�����ʾ����� cacheAsBitmap ���Խ�����Ϊ true�������������˾������ָ� cacheAsBitmap ��ԭʼֵ��
���˾�֧����̨���š����ǣ�����֧�ֳ������š���ת����б�������������������ţ������ scaleX �� scaleY 
����Ϊ�� 1.0 ���������ֵ�����˾�Ч�������������š�ֻ���û�����̨�Ͻ��зŴ�ʱ���Ż����š�
�������ͼ�񳬹����ߴ磬��Ӧ���˾���*/
	class GradientGlowFilter: public BitmapFilter
	{
	public:
		//��ָ��������ʼ���˾��� GradientGlowFilter
		GradientGlowFilter(Number  distance= 4.0,Number   angle= 45,Array   colors= null,Array   alphas= null,Array   ratios= null,Number   blurX= 4.0,Number   blurY= 4.0,Number   strength= 1,int   quality= 1,String   type= "inner",Boolean   knockout= false);
		//[override] ���ش��˾�����ĸ����� GradientGlowFilter
		BitmapFilter    clone( );
	private:
		//colors �����ж�Ӧ��ɫ�� Alpha ͸����ֵ�����顣 GradientGlowFilter
		Array alphas;
		//�Ƕȣ��Զ�Ϊ��λ�� GradientGlowFilter
		Number angle;
		//ˮƽģ������ GradientGlowFilter
		Number blurX;
		//��ֱģ������ GradientGlowFilter
		Number blurY;
		//���彥�����ɫ���顣 GradientGlowFilter
		Array colors;
		//���ε�ƫ�ƾ��롣 GradientGlowFilter
		Number distance;
		//ָ�������Ƿ�����ڿ�Ч���� GradientGlowFilter
		Boolean knockout;
		//Ӧ���˾��Ĵ����� GradientGlowFilter
		int quality;
		//��Ӧ�� colors ��������ɫ��һ����ɫ�ֲ����ʡ� GradientGlowFilter
		Array ratios;
		//ӡ�ǻ��ҳ��ǿ�ȡ� GradientGlowFilter
		Number strength;
		//�˾�Ч���ķ��á� GradientGlowFilter
		String type;
	};
}
