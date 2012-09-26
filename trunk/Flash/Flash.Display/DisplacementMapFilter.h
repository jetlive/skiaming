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

/*DisplacementMapFilter ��ʹ��ָ���� BitmapData ���󣨳�Ϊ�û�ͼͼ�񣩵�����ִֵ�ж����û���
������ʹ�ô��˾���Ť����ߵ�Ч��Ӧ���ڴ� DisplayObject ���м̳е��κζ������� MovieClip��SimpleButton��
TextField �� Video �����Լ� BitmapData ���� 
�˾��ľ���ʹ��ȡ����ҪӦ���˾��Ķ���
Ҫ���˾�Ӧ������ʾ������ʹ����ʾ����� filters ���ԡ����ö���� filters ���Բ����޸���Ӧ�Ķ���
����� filters ���Կ���ɾ����Ӧ���˾��� 
Ҫ�� BitmapData ����Ӧ���˾�����ʹ�� BitmapData.applyFilter() �������� BitmapData ������� applyFilter() 
��ȡ��Դ BitmapData ������˾����󣬲�����һ�����˺��ͼ�� 
�������ʾ����Ӧ���˾��������ʾ����� cacheAsBitmap ����ֵ������Ϊ true��
�����������˾������ָ� cacheAsBitmap ��ԭʼֵ��
���˾�ʹ�����¹�ʽ��
dstPixel[x, y] = srcPixel[x + ((componentX(x, y) - 128) * scaleX) / 256, y + ((componentY(x, y) - 128) *scaleY) / 256)
���У�componentX(x, y) �� mapBitmap ���Ի�� (x - mapPoint.x ,y - mapPoint.y) ���� componentX ������ɫֵ��
�˾�ʹ�õ�ӳ��ͼ���������ţ���ƥ����̨���ű����������������һ���ı���ʱ��������������š�
���˾�֧����̨���š�����֧�ֳ������š���ת����б�������������������ţ������ scaleX �� scaleY ��������Ϊ
�� 1.0 ���������ֵ�����˾�Ч�������������š�ֻ���û�����̨�Ͻ��зŴ�ʱ���Ż����š�*/
	class    DisplacementMapFilter: public BitmapFilter
	{
	public:
		//��ָ��������ʼ�� DisplacementMapFilter ʵ���� DisplacementMapFilter
		DisplacementMapFilter(BitmapData  mapBitmap= null,Point   mapPoint= null,uint   componentX= 0,uint   componentY= 0,Number   scaleX= 0.0,Number   scaleY= 0.0,String   mode= "wrap",uint   color= 0,Number   alpha= 0.0);
		//[override] ���ش��˾�����ĸ����� DisplacementMapFilter
		BitmapFilter    clone( );
	private:
		//ָ�����ڳ�����Χ���滻Ӧ�õ� Alpha ͸����ֵ�� DisplacementMapFilter
		Number alpha;
		//ָ�����ڳ�����Χ���滻Ӧ��ʲô��ɫ�� DisplacementMapFilter
		uint color;
		//˵����ӳ��ͼ����ʹ���ĸ���ɫͨ�����û� x ����� DisplacementMapFilter
		uint componentX;
		//˵����ӳ��ͼ����ʹ���ĸ���ɫͨ�����û� y ����� DisplacementMapFilter
		uint componentY;
		//�����û�ӳ�����ݵ� BitmapData ���� DisplacementMapFilter
		BitmapData mapBitmap;
		//һ��ֵ��������Ŀ����ʾ��������Ͻ������ӳ��ͼ�����Ͻǵ�ƫ������ DisplacementMapFilter
		Point mapPoint;
		//�˾�ģʽ�� DisplacementMapFilter
		String mode;
		//��������ӳ������ x �û�����ĳ����� DisplacementMapFilter
		Number scaleX;
		//��������ӳ������ y �û�����ĳ����� DisplacementMapFilter
		Number scaleY;

	};
}
