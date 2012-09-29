#pragma once
#include "StdAfx.h"
#include "Object.h"
#include "BitmapData.h"
#include "DisplayObject.h"
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
//Bitmap ���ʾ���ڱ�ʾλͼͼ�����ʾ������Щͼ�������ʹ�� flash.display.Loader ����ص�ͼ��
//Ҳ������ʹ�� Bitmap() ���캯��������ͼ��
//���� Bitmap() ���캯�������Դ��������� BitmapData ��������õ� Bitmap ����
//������ Bitmap �����ʹ�ø� DisplayObjectContainer ʵ���� addChild() �� addChildAt() ������λͼ������ʾ�б��С�

	class	Bitmap: public DisplayObject	//OK
	{
	public:
		//��ʼ�� Bitmap ����������ָ���� BitmapData ���� Bitmap
		Bitmap(BitmapData bitmapData= null, String pixelSnapping= "auto", Boolean smoothing= false);
		~Bitmap();
	private:
		//�����õ� BitmapData ���� Bitmap
		BitmapData bitmapData;
		//���� Bitmap �����Ƿ���������������ء� Bitmap
		String pixelSnapping;
		//����������ʱ�Ƿ��λͼ����ƽ������ Bitmap
		Boolean smoothing;
	};
}