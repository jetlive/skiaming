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

/*��ʹ�� BevelFilter �����ʾ�������б��Ч����б��Ч��ʹ�����簴ť��������ά��ۡ�
���������ò�ͬ�ļ�����ɫ����Ӱ��ɫ��б���ϵ�ģ������б�ǵĽǶȡ�б�ǵ�λ�ú��ڿ�Ч�����Զ���б�ǵ���ۡ�
�����Խ��˾�Ӧ�����κ���ʾ���󣨼����� DisplayObject ��̳еĶ��󣩣����� MovieClip��SimpleButton��TextField 
�� Video �����Լ� BitmapData ���� 
Ҫ�������˾�����ʹ�ù��캯�� new BevelFilter()���˾��ľ���ʹ��ȡ����ҪӦ���˾��Ķ���
Ҫ��ӰƬ�������ı��ֶΡ���ť����ƵӦ���˾�����ʹ�� filters ���ԣ��̳��� DisplayObject����
���ö���� filters ���Բ����޸���Ӧ�Ķ��󣬶���� filters ���Կ���ɾ����Ӧ���˾��� 
Ҫ�� BitmapData ����Ӧ���˾�����ʹ�� BitmapData.applyFilter() ������
�� BitmapData ������� applyFilter() ��ȡ��Դ BitmapData ������˾����󣬲���������һ������ͼ�� 
�������ʾ����Ӧ���˾�����ö���� cacheAsBitmap ����ֵ������Ϊ true��
���ɾ�������˾������ָ� cacheAsBitmap ��ԭʼֵ��
���˾�֧����̨���š����ǣ�����֧�ֳ������š���ת����б�������������������ţ���� scaleX �� scaleY ����δ��
����Ϊ 100%�������˾����������š�ֻ���û�����̨�Ͻ��зŴ�ʱ���Ż����š�
�������ͼ�񳬹����ߴ磬��Ӧ���˾���*/
	class    BevelFilter: public BitmapFilter
	{
	public:
		BevelFilter(Number  distance= 4.0,Number   angle= 45,uint   highlightColor= 0xFFFFFF,Number   highlightAlpha= 1.0,uint   shadowColor= 0x000000,Number   shadowAlpha= 1.0,Number   blurX= 4.0,Number   blurY= 4.0,Number   strength= 1,int   quality= 1,String   type= "inner",Boolean   knockout= false);
		//[override] ���ش��˾�����ĸ����� BevelFilter
		BitmapFilter    clone( );
	private:
		//б�ǵĽǶȡ� BevelFilter
		Number angle;
		//ˮƽģ������������Ϊ��λ�� BevelFilter
		Number blurX;
		//��ֱģ������������Ϊ��λ�� BevelFilter
		Number blurY;
		//б�ǵ�ƫ�ƾ��롣 BevelFilter
		Number distance;
		//������ɫ�� Alpha ͸����ֵ�� BevelFilter
		Number highlightAlpha;
		//б�ǵļ�����ɫ�� BevelFilter
		uint highlightColor;
		//Ӧ���ڿ�Ч�� (true)���⽫��Ч��ʹ�������ɫ��Ϊ͸��������ʾ�ĵ��ı�����ɫ�� BevelFilter
		Boolean knockout;
		//Ӧ���˾��Ĵ����� BevelFilter
		int quality;
		//��Ӱ��ɫ�� Alpha ͸����ֵ�� BevelFilter
		Number shadowAlpha;
		//б�ǵ���Ӱ��ɫ�� BevelFilter
		uint shadowColor;
		//ӡ�ǻ��ҳ��ǿ�ȡ� BevelFilter
		Number strength;
		//б���ڶ����ϵ�λ�á� BevelFilter
		String type;
		//��ָ��������ʼ���µ� BevelFilter ʵ���� BevelFilter

	};
}
