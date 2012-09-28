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

/*ʹ�� GlowFilter ����Զ���ʾ����Ӧ�÷���Ч�����ж�����ڷ�����ʽ��ѡ������ڲ෢�����෢���Լ��ڿ�ģʽ��
��ͶӰ�˾��� distance �� angle ��������Ϊ 0 ʱ�������˾���ͶӰ�˾���Ϊ���ơ������Խ��˾�Ӧ�����κ���ʾ
���󣨼����� DisplayObject ��̳еĶ��󣩣����� MovieClip��SimpleButton��TextField �� Video ����
�Լ� BitmapData ���� 
�˾��ľ���ʹ��ȡ����ҪӦ���˾��Ķ���
Ҫ����ʾ����Ӧ���˾�����ʹ�� filters ���ԣ��̳��� DisplayObject�������ö���� filters ���Բ����޸���Ӧ�Ķ���
����� filters ���Կ���ɾ����Ӧ���˾��� 
Ҫ�� BitmapData ����Ӧ���˾�����ʹ�� BitmapData.applyFilter() �������� BitmapData ������� applyFilter() ��ȡ��
Դ BitmapData ������˾����󣬲���������һ������ͼ�� 
�������ʾ����Ӧ���˾�����ʾ����� cacheAsBitmap ���Խ�����Ϊ true��
�����������˾������ָ� cacheAsBitmap ��ԭʼֵ��
���˾�֧����̨���š����ǣ�����֧�ֳ������š���ת����б�������������������ţ������ scaleX �� scaleY 
����Ϊ�� 1.0 ���������ֵ�����˾������������š�ֻ���û�����̨�Ͻ��зŴ�ʱ���Ż����š�
�������ͼ�񳬹����ߴ磬��Ӧ���˾�*/



	class    GlowFilter: public BitmapFilter
	{
	public:
		//��ָ��������ʼ���µ� GlowFilter ʵ���� GlowFilter
		GlowFilter(uint  color= 0xFF0000,Number   alpha= 1.0,Number   blurX= 6.0,Number   blurY= 6.0,Number   strength= 2,int   quality= 1,Boolean   inner= false,Boolean   knockout= false);
		//[override] ���ش��˾�����ĸ����� GlowFilter
		BitmapFilter    clone( );
	private:
		//��ɫ�� Alpha ͸����ֵ�� GlowFilter
		Number alpha;
		//ˮƽģ������ GlowFilter
		Number blurX;
		//��ֱģ������ GlowFilter
		Number blurY;
		//������ɫ�� GlowFilter
		uint color;
		//ָ�������Ƿ�Ϊ�ڲ෢�⡣ GlowFilter
		Boolean inner;
		//ָ�������Ƿ�����ڿ�Ч���� GlowFilter
		Boolean knockout;
		//Ӧ���˾��Ĵ����� GlowFilter
		int quality;
		//ӡ�ǻ��ҳ��ǿ�ȡ� GlowFilter
		Number strength;

	};
}
