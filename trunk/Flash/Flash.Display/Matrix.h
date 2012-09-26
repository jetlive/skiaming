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
	/*Matrix ���ʾһ��ת��������ȷ����ν����һ������ռ�ӳ�䵽��һ������ռ䡣
	�����Զ�һ����ʾ����ִ�в�ͬ��ͼ��ת�������������� Matrix ��������ԣ�
	���� Matrix ����Ӧ���� Transform ����� matrix ���ԣ�Ȼ��Ӧ�ø� Transform ������Ϊ��ʾ����� transform ���ԡ�
	��Щת����������ƽ�ƣ�x �� y ���¶�λ������ת�����ź���б�� */

	class	Matrix: public Object	//OK
	{
	public:
		//ʹ��ָ�����������µ� Matrix ���� Matrix
		Matrix(Number  a= 1,Number   b= 0,Number   c= 0,Number   d= 1,Number   tx= 0,Number   ty= 0);
		//����һ���µ� Matrix �������Ǵ˾���Ŀ�¡������������������ȫ��ͬ�ĸ����� Matrix
		Matrix    clone( );
		//��ĳ�������뵱ǰ�������ӣ��Ӷ�������������ļ���Ч����Ч�ؽ����һ�� Matrix
		void    concat(Matrix m);
		//�����������š���ת��ת���Ĳ����� Matrix
		void    createBox(Number scaleX,Number  scaleY,Number   rotation= 0,Number   tx= 0,Number   ty= 0);
		//���� Graphics ��� beginGradientFill() �� lineGradientStyle() ��������ľ�����ض���ʽ�� Matrix
		void    createGradientBox(Number width,Number  height,Number   rotation= 0,Number   tx= 0,Number   ty= 0);
		//�������Ԥת������ռ��еĵ㣬��˷������ط���ת����õ�����ꡣ Matrix
		Point    deltaTransformPoint(Point point);
		//Ϊÿ��������������һ��ֵ����ֵ������ null ת���� Matrix
		void    identity( );
		//ִ��ԭʼ�������ת���� Matrix
		void    invert( );
		//�� Matrix ����Ӧ����תת���� Matrix
		void    rotate(Number angle);
		//�Ծ���Ӧ������ת���� Matrix
		void    scale(Number sx,Number  sy);
		//�����г��� Matrix �������Ե��ı�ֵ�� Matrix
		String    toString( );
		//���ؽ� Matrix �����ʾ�ļ���ת��Ӧ����ָ�����������Ľ���� Matrix
		Point    transformPoint(Point point);
		//�� x �� y ��ƽ�ƾ����� dx �� dy ����ָ���� Matrix
		void    translate(Number dx,Number  dy);
	private:
		//���Ż���תͼ��ʱӰ�������� x �ᶨλ��ֵ�� Matrix
		Number a;
		//��ת����бͼ��ʱӰ�������� y �ᶨλ��ֵ�� Matrix
		Number b;
		//��ת����бͼ��ʱӰ�������� x �ᶨλ��ֵ�� Matrix
		Number c;
		//���Ż���תͼ��ʱӰ�������� y �ᶨλ��ֵ�� Matrix
		Number d;
		//�� x ��ƽ��ÿ����ľ��롣 Matrix
		Number tx;
		//�� y ��ƽ��ÿ����ľ��롣 Matrix
		Number ty;

	};
}