#pragma once
#include "StdAfx.h"

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
/*Shader ʵ����ʾ ActionScript �е� Pixel Bender ��ɫ���ںˡ�
Ҫ��Ӧ�ó�����ʹ����ɫ������Ϊ������һ�� Shader ʵ����Ȼ��
����Ҫ�����Ч�������ʵ��ķ�ʽʹ�ø� Shader ʵ�������磬
Ҫ����ɫ�������˾����ɽ� Shader ʵ������ ShaderFilter ����� 
shader ���ԡ� 
��ɫ�������ͼ���е���������ִ�еĺ�����һ��һ�����أ���
�Ըú�����ÿ�ε��õĽ������ͼ���и��������괦�������ɫ��
��ɫ������ָ��һ����������ͼ����Щͼ������ݿ�
����ȷ���������������ɫ��������ָ��һ������������
��Щ�����ǿ����ڼ��㺯�����������ֵ���ڵ�һ��ɫ��
ִ���У�����Ͳ���ֵ�ǳ�����Ψһ�����仯����
���أ�����ɫ�Ǻ�������������ꡣ��Զ���������
�������ɫ���������ý�����ִ�У��ԸĽ���ɫ��ִ�����ܡ�*/


	class	ShaderData: public Object
	{
	public:
		ShaderData(ByteArray byteCode);		//���� ShaderData ʵ����
	private:
	};
}