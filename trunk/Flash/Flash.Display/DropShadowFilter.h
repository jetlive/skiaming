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

/*��ʹ�� DropShadowFilter ������ʾ�������ͶӰ����Ӱ�㷨����ģ���˾�ʹ�õ�ͬһ�������˾���ͶӰ��ʽ�ж��ѡ�
�����ڲ�������Ӱ���ڿ�ģʽ�������Խ��˾�Ӧ�����κ���ʾ���󣨼����� DisplayObject ��̳еĶ���),
���� MovieClip��SimpleButton��TextField �� Video �����Լ� BitmapData ���� 
�˾��ľ���ʹ��ȡ����ҪӦ���˾��Ķ���
Ҫ����ʾ����Ӧ���˾�����ʹ�� filters ���ԣ��̳��� DisplayObject�������ö���� filters ���Բ����޸���Ӧ�Ķ���
����� filters ���Կ���ɾ����Ӧ���˾��� 
Ҫ�� BitmapData ����Ӧ���˾�����ʹ�� BitmapData.applyFilter() �������� BitmapData ������� applyFilter() ��ȡ��
Դ BitmapData ������˾����󣬲���������һ������ͼ�� 
�������ʾ����Ӧ���˾��������ʾ����� cacheAsBitmap ����ֵ������Ϊ true�������������˾���
���ָ� cacheAsBitmap ��ԭʼֵ��
���˾�֧����̨���š����ǣ�����֧�ֳ������š���ת����б�������������������ţ������ scaleX �� scaleY 
����Ϊ�� 1.0 ���������ֵ�����˾������������š�ֻ���û�����̨�Ͻ��зŴ�ʱ���Ż����š�
�������ͼ�񳬹����ߴ磬��Ӧ���˾���*/


	class    DropShadowFilter: public BitmapFilter
	{
	public:
		//��ָ�����������µ� DropShadowFilter ʵ���� DropShadowFilter
		DropShadowFilter(Number  distance= 4.0,Number   angle= 45,uint   color= 0,Number   alpha= 1.0,Number   blurX= 4.0,Number   blurY= 4.0,Number   strength= 1.0,int   quality= 1,Boolean   inner= false,Boolean   knockout= false,Boolean   hideObject= false);
		//[override] ���ش��˾�����ĸ����� DropShadowFilter
		BitmapFilter    clone( );
	private:
		//��Ӱ��ɫ�� Alpha ͸����ֵ�� DropShadowFilter
		Number alpha;
		//��Ӱ�ĽǶȡ� DropShadowFilter
		Number angle;
		//ˮƽģ������ DropShadowFilter
		Number blurX;
		//��ֱģ������ DropShadowFilter
		Number blurY;
		//��Ӱ����ɫ�� DropShadowFilter
		uint color;
		//��Ӱ��ƫ�ƾ��룬������Ϊ��λ�� DropShadowFilter
		Number distance;
		//��ʾ�Ƿ����ض��� DropShadowFilter
		Boolean hideObject;
		//��ʾ��Ӱ�Ƿ�Ϊ�ڲ���Ӱ�� DropShadowFilter
		Boolean inner;
		//Ӧ���ڿ�Ч�� (true)���⽫��Ч��ʹ�������ɫ��Ϊ͸��������ʾ�ĵ��ı�����ɫ�� DropShadowFilter
		Boolean knockout;
		//Ӧ���˾��Ĵ����� DropShadowFilter
		int quality;
		//ӡ�ǻ��ҳ��ǿ�ȡ� DropShadowFilter
		Number strength;

	};
}
