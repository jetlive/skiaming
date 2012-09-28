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
//Shader ʵ����ʾ ActionScript �е� Pixel Bender ��ɫ���ںˡ�
//Ҫ��Ӧ�ó�����ʹ����ɫ������Ϊ������һ�� Shader ʵ����Ȼ�󣬸���Ҫ�����Ч�������ʵ��ķ�ʽʹ�ø� Shader ʵ����
//���磬Ҫ����ɫ�������˾����ɽ� Shader ʵ������ ShaderFilter ����� shader ���ԡ�
	class	Shader: public Object	//OK
	{
	public:
		Shader(ByteArray code = null);		//����һ���µ� Shader ʵ����
	private:
		ByteArray byteCode;		//[ֻд] �� Shader ʵ����ԭʼ��ɫ���ֽڴ��롣 Shader 
		ShaderData data;		//�ṩ�� Shader ʵ���Ĳ���������ͼ���Ԫ���ݵķ��ʡ� Shader 
		String precisionHint;		//��ɫ����ִ����ѧ����ľ��ȡ� 
	};
}