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

/*��������ʹ�� ActionScript ��ͼӦ�ó����̽ӿ� (API) ��������״��
Shape ����� graphics ���ԣ�������ʹ�����Դ� Graphics ����ʷ����� 
Sprite ��Ҳ���� graphics ���ԣ������������������� Shape ����������ܡ�
���磬Sprite ��������ʾ������������ Shape �����ǣ����Ҳ��ܰ�������ʾ���󣩡�
���ڴ�ԭ��Shape �����Ȱ�����ͬͼ�ε� Sprite �������ĵ��ڴ��١�
���ǣ�Sprite ����֧����굥���¼����� Shape ����֧�֡�*/


	class	Shape: public DisplayObject	//OK
	{
	public:	
		//�����µ� Shape ���� Shape
		Shape( );
	private:
		//[ֻ��] ָ�����ڸ� Shape ����� Graphics ���󣬿�ͨ���˶���ִ��ʸ���滭��� Shape
		Graphics graphics;
	};
}