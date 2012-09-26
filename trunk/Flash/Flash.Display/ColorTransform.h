#pragma once
#include "StdAfx.h"
#include "Object.h"
#include <vector>
#include <string>
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

/*��ʹ�� ColorTransform �������ʾ�������ɫֵ�����Խ���ɫ��������ɫת��Ӧ��������
����ͨ������ɫ����ɫ����ɫ�� Alpha ͸���ȡ� 
�� ColorTransform ����Ӧ������ʾ����ʱ���������·���Ϊÿ����ɫͨ��������ֵ��
�º�ɫֵ = (�ɺ�ɫֵ * redMultiplier) + redOffset 
����ɫֵ = (����ɫֵ * greenMultiplier) + greenOffset 
����ɫֵ = (����ɫֵ * blueMultiplier) + blueOffset 
�� Alpha ֵ = (�� Alpha ֵ * alphaMultiplier) + alphaOffset 
���������κ�һ����ɫͨ��ֵ���� 255�����ֵ��������Ϊ 255�������ֵС�� 0��
����������Ϊ 0��
����ͨ�����з�ʽʹ�� ColorTransform ����
�� BitmapData ��� colorTransform() ������ colorTransform ������ 
��Ϊ Transform ���󣨴˶������������ʾ����� transform ���ԣ��� colorTransform ���� 
����ʹ�� new ColorTransform() ���캯������ ColorTransform �����
���ܵ��� ColorTransform ����ķ�����
��ɫת������Ӧ����ӰƬ����������ص� SWF ���󣩵ı���ɫ�����ǽ�Ӧ����
���ӵ�ӰƬ������ͼ�κ�Ԫ����*/


	class	ColorTransform: public Object	//OK
	{
	public:
		//��ָ������ɫͨ��ֵ�� Alpha ֵΪ��ʾ���󴴽� ColorTransform ���� ColorTransform
		ColorTransform(Number  redMultiplier= 1.0,Number   greenMultiplier= 1.0,Number   blueMultiplier= 1.0,Number   alphaMultiplier= 1.0,Number   redOffset= 0,Number   greenOffset= 0,Number   blueOffset= 0,Number   alphaOffset= 0);
		//�� second ����ָ���� ColorTranform �����뵱ǰ ColorTransform �������ӣ�������ǰ��������Ϊ�������������ɫת���������ϡ� ColorTransform
		void    concat(flash.geom:ColorTransform second);
	private:
		//�����ַ�����ʽ�����䷵�أ����ַ������� ColorTransform ������������ԡ� ColorTransform
		String    toString( );
		//�� Alpha ͸����ͨ��ֵ��˵�ʮ����ֵ�� ColorTransform
		Number alphaMultiplier;
		//-255 �� 255 ֮������֣������� alphaMultiplier ֵ��ˣ����� Alpha ͸����ͨ��ֵ��ӡ� ColorTransform
		Number alphaOffset;
		//����ɫͨ��ֵ��˵�ʮ����ֵ�� ColorTransform
		Number blueMultiplier;
		//-255 �� 255 ֮������֣������� blueMultiplier ֵ��ˣ�������ɫͨ��ֵ��ӡ� ColorTransform
		Number blueOffset;
		//ColorTransform ����� RGB ��ɫֵ�� ColorTransform
		uint color;
		//����ɫͨ��ֵ��˵�ʮ����ֵ�� ColorTransform
		Number greenMultiplier;
		//-255 �� 255 ֮������֣������� greenMultiplier ֵ��ˣ�������ɫͨ��ֵ��ӡ� ColorTransform
		Number greenOffset;
		//���ɫͨ��ֵ��˵�ʮ����ֵ�� ColorTransform
		Number redMultiplier;
		//-255 �� 255 ֮������֣������� redMultiplier ֵ��ˣ������ɫͨ��ֵ��ӡ� ColorTransform
		Number redOffset;

	};
}