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

/*��ʹ�� BlurFilter �ཫģ���Ӿ�Ч��Ӧ������ʾ����ģ��Ч�������ữͼ���ϸ�ڡ�
����������һЩģ��Ч������Χ�Ӵ���һ���ữ�ġ�δ�۽�����۵���˹ģ��������ͨ����͸�������鿴ͼ��һ�������ʵ���ۣ���
�����˾��� quality ��������Ϊ��ʱ�����Ϊ�ữ�ġ�δ�۽�����ۡ��� quality ��������Ϊ��ʱ�������Խӽ���˹ģ���˾���
�����Խ��˾�Ӧ�����κ���ʾ���󣨼����� DisplayObject ��̳еĶ��󣩣����� MovieClip��SimpleButton��TextField �� 
Video �����Լ� BitmapData ���� 
Ҫ�����µ��˾�����ʹ�ù��캯�� new BlurFilter()���˾��ľ���ʹ��ȡ����ҪӦ���˾��Ķ���
Ҫ��ӰƬ�������ı��ֶΡ���ť����ƵӦ���˾�����ʹ�� filters ���ԣ��̳��� DisplayObject����
���ö���� filters ���Բ����޸���Ӧ�Ķ��󣬶���� filters ���Կ���ɾ����Ӧ���˾��� 
Ҫ�� BitmapData ����Ӧ���˾�����ʹ�� BitmapData.applyFilter() ������
�� BitmapData ������� applyFilter() ��ȡ��Դ BitmapData ������˾����󣬲���������һ������ͼ�� 
�������ʾ����Ӧ���˾�����ʾ����� cacheAsBitmap ���Խ�����Ϊ true��
���ɾ�������˾������ָ� cacheAsBitmap ��ԭʼֵ��
���˾�֧����̨���š����ǣ�����֧�ֳ������š���ת����б�������������������ţ�scaleX �� scaleY δ����Ϊ 100%����
�˾�Ч�������������š�ֻ���û�����̨�Ͻ��зŴ�ʱ���Ż����š�
�������ͼ�񳬹����ߴ磬��Ӧ���˾���*/

	class    BlurFilter: public BitmapFilter
	{
	public:
		//��ָ��������ʼ���˾��� BlurFilter
		BlurFilter(Number  blurX= 4.0,Number   blurY= 4.0,int   quality= 1);
		//[override] ���ش��˾�����ĸ����� BlurFilter
		BitmapFilter    clone( );
	private:
		//ˮƽģ������ BlurFilter
		Number blurX;
		//��ֱģ������ BlurFilter
		Number blurY;
		//ִ��ģ���Ĵ����� BlurFilter
		int quality;
		
		

	};
}
