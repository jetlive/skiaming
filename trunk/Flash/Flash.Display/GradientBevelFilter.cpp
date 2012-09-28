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

/*ʹ�� GradientBevelFilter ����Զ���ʾ����Ӧ�ý���б��Ч��������б����λ�ڶ����ⲿ���ڲ��򶥲���ʹ�ý���ɫ��ǿ
����б��	�ı�Ե����б��ı�Եʹ���������ά��ۡ������Խ��˾�Ӧ�����κ���ʾ���󣨼����� DisplayObject ��̳�
�Ķ��󣩣����� MovieClip��SimpleButton��TextField �� Video �����Լ� BitmapData ���� 
�˾��ľ���ʹ��ȡ����ҪӦ���˾��Ķ���
Ҫ����ʾ����Ӧ���˾�����ʹ�� filters ���ԡ����ö���� filters ���Բ����޸���Ӧ�Ķ��󣬶���� filters ���Կ���ɾ����Ӧ���˾��� 
Ҫ�� BitmapData ����Ӧ���˾�����ʹ�� BitmapData.applyFilter() �������� BitmapData ����
���� applyFilter() ��ȡ��Դ BitmapData ������˾����󣬲���������һ������ͼ�� 
�������ʾ����Ӧ���˾�����ʾ����� cacheAsBitmap ���Խ�����Ϊ true�������������˾���
���ָ� cacheAsBitmap ��ԭʼֵ��
���˾�֧����̨���š����ǣ�����֧�ֳ������š���ת����б�������������������ţ����
�� scaleX �� scaleY ����Ϊ�� 1.0 ���������ֵ�����˾�Ч�������������š�ֻ���û�����̨�Ͻ��зŴ�ʱ���Ż����š�
�������ͼ�񳬹����ߴ磬��Ӧ���˾���*/


	class GradientBevelFilter: public BitmapFilter
	{
	public:
		//��ָ��������ʼ���˾��� GradientBevelFilter
		GradientBevelFilter(Number  distance= 4.0,Number   angle= 45,Array   colors= null,Array   alphas= null,Array   ratios= null,Number   blurX= 4.0,Number   blurY= 4.0,Number   strength= 1,int   quality= 1,String   type= "inner",Boolean   knockout= false);
		//[override] ���ش��˾�����ĸ����� GradientBevelFilter
		BitmapFilter    clone( );
	private:
		//colors �����ж�Ӧ��ɫ�� Alpha ͸����ֵ�����顣 GradientBevelFilter
		Array alphas;
		//�Ƕȣ��Զ�Ϊ��λ�� GradientBevelFilter
		Number angle;
		//ˮƽģ������ GradientBevelFilter
		Number blurX;
		//��ֱģ������ GradientBevelFilter
		Number blurY;
		//������ʹ�õ� RGB ʮ��������ɫֵ���顣 GradientBevelFilter
		Array colors;
		//ƫ�ƾ��롣 GradientBevelFilter
		Number distance;
		//ָ�������Ƿ�����ڿ�Ч���� GradientBevelFilter
		Boolean knockout;
		//Ӧ���˾��Ĵ����� GradientBevelFilter
		int quality;
		//��Ӧ�� colors ��������ɫ��һ����ɫ�ֲ����ʡ� GradientBevelFilter
		Array ratios;
		//ӡ�ǻ��ҳ��ǿ�ȡ� GradientBevelFilter
		Number strength;
		//б��Ч���ķ��á� GradientBevelFilter
		String type;

	};
}
