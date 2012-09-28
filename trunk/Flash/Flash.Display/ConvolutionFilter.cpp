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

/*ConvolutionFilter ��Ӧ�þ��������˾�Ч�������������ͼ������������ڵ����غϲ�������ͼ��
ͨ�����������ʵ�ִ�����ͼ��Ч��������ģ������Ե��⡢�񻯡������б�ǡ�
�����Խ��˾�Ӧ�����κ���ʾ���󣨼����� DisplayObject ��̳еĶ��󣩣����� MovieClip��SimpleButton��
TextField �� Video �����Լ� BitmapData ���� 
Ҫ��������˾�����ʹ���﷨ new ConvolutionFilter()���˾��ľ���ʹ��ȡ����ҪӦ���˾��Ķ���
Ҫ��ӰƬ�������ı��ֶΡ���ť����ƵӦ���˾�����ʹ�� filters ���ԣ��̳��� DisplayObject����
���ö���� filters ���Բ����޸���Ӧ�Ķ��󣬶���� filters ���Կ���ɾ����Ӧ���˾��� 
Ҫ�� BitmapData ����Ӧ���˾�����ʹ�� BitmapData.applyFilter() ������
�� BitmapData ������� applyFilter() ��ȡ��Դ BitmapData ������˾����󣬲���������һ������ͼ�� 
�������ʾ����Ӧ���˾�����ö���� cacheAsBitmap ����ֵ������Ϊ true��
�����������˾������ָ� cacheAsBitmap ��ԭʼֵ��
�������ͼ�񳬹����ߴ磬��Ӧ���˾���*/



	class ConvolutionFilter: public BitmapFilter
	{
	public:
		//��ָ��������ʼ�� ConvolutionFilter ʵ���� ConvolutionFilter
		ConvolutionFilter(Number  matrixX= 0,Number   matrixY= 0,Array   matrix= null,Number   divisor= 1.0,Number   bias= 0.0,Boolean   preserveAlpha= true,Boolean   clamp= true,uint   color= 0,Number   alpha= 0.0);
		//[override] ���ش��˾�����ĸ����� ConvolutionFilter
		BitmapFilter    clone( );
	private:
		//�滻��ɫ�� Alpha ͸����ֵ�� ConvolutionFilter
		Number alpha;
		//Ҫ��ӵ�����ת������е�ƫ������ ConvolutionFilter
		Number bias;
		//ָʾ�Ƿ�Ӧ����ͼ�� ConvolutionFilter
		Boolean clamp;
		//Ҫ�滻Դͼ��֮������ص�ʮ��������ɫ�� ConvolutionFilter
		uint color;
		//����ת����ʹ�õĳ����� ConvolutionFilter
		Number divisor;
		//���ھ���ת����ֵ�����顣 ConvolutionFilter
		Array matrix;
		//����� x ά�ȣ��������е���Ŀ���� ConvolutionFilter
		Number matrixX;
		//����� y ά�ȣ��������е���Ŀ���� ConvolutionFilter
		Number matrixY;
		//ָʾ�Ƿ��ѱ��� Alpha ͨ�����Ҳ�ʹ���˾�Ч�������Ƿ�� Alpha ͨ���Լ���ɫͨ��Ӧ�þ���˾��� ConvolutionFilter
		Boolean preserveAlpha;

	};
}
