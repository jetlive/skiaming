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

/*ʹ�� ColorMatrixFilter ����Խ� 4 x 5 ����ת��Ӧ��������ͼ���ϵ�ÿ�����ص� RGBA ��ɫ�� Alpha ֵ��
�����ɾ���һ���µ� RGBA ��ɫ�� Alpha ֵ�Ľ�������������Ͷȸ��ġ�ɫ����ת������Ϊ Alpha �Լ���������Ч����
�����Խ��˾�Ӧ�����κ���ʾ���󣨼����� DisplayObject ��̳еĶ��󣩣����� MovieClip��SimpleButton��
TextField �� Video �����Լ� BitmapData ���� 
ע�⣺���� RGBA ֵ�������Ч�ֽڴ����ɫͨ��ֵ��������Ч�ֽڷֱ������ɫ����ɫ�� Alpha ͨ��ֵ��
Ҫ�����µ���ɫ�����˾�����ʹ�� new ColorMatrixFilter() �﷨���˾��ľ���ʹ��ȡ����ҪӦ���˾��Ķ���
Ҫ��ӰƬ�������ı��ֶΡ���ť����ƵӦ���˾�����ʹ�� filters ���ԣ��̳��� DisplayObject����
���ö���� filters ���Բ����޸���Ӧ�Ķ��󣬶���� filters ���Կ���ɾ����Ӧ���˾��� 
Ҫ�� BitmapData ����Ӧ���˾�����ʹ�� BitmapData.applyFilter() ������
�� BitmapData ������� applyFilter() ��ȡ��Դ BitmapData ������˾����󣬲���������һ������ͼ�� 
�������ʾ����Ӧ���˾�����ʾ����� cacheAsBitmap ���Խ�����Ϊ true��
���ɾ�������˾������ָ� cacheAsBitmap ��ԭʼֵ��
�������ͼ�񳬹����ߴ磬��Ӧ���˾���*/

	class    ColorMatrixFilter: public BitmapFilter
	{
	public:
		//��ָ��������ʼ���µ� ColorMatrixFilter ʵ���� ColorMatrixFilter
		ColorMatrixFilter(Array  matrix= null);
		//[override] ���ش��˾�����ĸ����� ColorMatrixFilter
		BitmapFilter    clone( );
	private:
		//�� 20 ����Ŀ��ɵ����飬������ 4 x 5 ��ɫת���� ColorMatrixFilter
		Array matrix;

	};
}
