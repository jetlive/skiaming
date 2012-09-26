#pragma once
#include "StdAfx.h"
#include "Object.h"
#include "Shader.h"
#include "Matrix.h"
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



/*������ɫ����䡣 
�� GraphicsShaderFill ������ Graphics.drawGraphicsData() ����һ��ʹ�á�
���� GraphicsShaderFill ��������� Graphics.beginShaderFill() �����ǵ�Ч�ġ� */
	class	GraphicsShaderFill : public Object	//OK
	{
	public:
		//�����µ� GraphicsShaderFill ���� GraphicsShaderFill
		GraphicsShaderFill(Shader  shader= null,Matrix   matrix= null);
	private:
		//һ�� matrix �������� flash.geom.Matrix �ࣩ�������ڶ���ɫ������ת���� GraphicsShaderFill
		Matrix matrix;
		//Ҫ����������ɫ���� GraphicsShaderFill
		Shader shader;

	};
}