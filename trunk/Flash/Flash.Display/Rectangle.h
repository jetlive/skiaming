#pragma once
#include "StdAfx.h"
#include "Object.h"

#include <vector>
#include <string>
namespace splght{
#ifndef LX_Boolean
#define LX_Boolean bool
#endif

#ifndef LX_UNIT
#define LX_UNIT unsigned int
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
typedef struct
{
	float x;
	float y;
}Point, *PPOINT;
//Rectangle �����ǰ���λ�ã��������Ͻǵĵ� (x, y) ȷ�����Լ���Ⱥ͸߶ȶ�������� 
//Rectangle ��� x��y��width �� height �����໥����������һ�����Ե�ֵ����Ӱ���������ԡ�
//���ǣ�right �� bottom ���������ĸ�������������صġ����磬������� right ���Ե�ֵ���� width ���Ե�ֵ�������仯��
//������� bottom ���ԣ��� height ���Ե�ֵ�������仯�� 


	class	Rectangle: public Object
	{
	public:
		//����һ���� Rectangle ���������Ͻ��� x �� y ����ָ����������ָ���� width �� height ������ Rectangle
		Rectangle(Number  x= 0,Number   y= 0,Number   width= 0,Number   height= 0);
		//����һ���µ� Rectangle ������ x��y��width �� height ���Ե�ֵ��ԭʼ Rectangle ����Ķ�Ӧֵ��ͬ�� Rectangle
		Rectangle    clone( );
		//ȷ���ɴ� Rectangle ������ľ����������Ƿ����ָ���ĵ㡣 Rectangle
		Boolean    contains(Number x,Number  y);
		//ȷ���ɴ� Rectangle ������ľ����������Ƿ����ָ���ĵ㡣 Rectangle
		Boolean    containsPoint(Point point);
		//ȷ���� Rectangle �������Ƿ������ rect ����ָ���� Rectangle ���� Rectangle
		Boolean    containsRect(Rectangle rect);
		//ȷ���� toCompare ������ָ���Ķ����Ƿ���ڴ� Rectangle ���� Rectangle
		Boolean    equals(Rectangle toCompare);
		//��ָ�������� Rectangle ����Ĵ�С��������Ϊ��λ���� Rectangle
		void    inflate(Number dx,Number  dy);
		//���� Rectangle ����Ĵ�С�� Rectangle
		void    inflatePoint(Point point);
		//����� toIntersect ������ָ���� Rectangle ������� Rectangle �����ཻ���򷵻ؽ���������Ϊ Rectangle ���� Rectangle
		Rectangle    intersection(Rectangle toIntersect);
		//ȷ���� toIntersect ������ָ���Ķ����Ƿ���� Rectangle �����ཻ�� Rectangle
		Boolean    intersects(Rectangle toIntersect);
		//ȷ���� Rectangle �����Ƿ�Ϊ�ա� Rectangle
		Boolean    isEmpty( );
		//��ָ�������� Rectangle �����λ�ã��������Ͻ�ȷ������ Rectangle
		void    offset(Number dx,Number  dy);
		//�� Point ������������������ Rectangle �����λ�á� Rectangle
		void    offsetPoint(Point point);
		//�� Rectangle �����������������Ϊ 0�� Rectangle
		void    setEmpty( );
		//���ɲ�����һ���ַ��������ַ����г� Rectangle �����ˮƽλ�úʹ�ֱλ���Լ��߶ȺͿ�ȡ� Rectangle
		String    toString( );
		//ͨ�������������֮���ˮƽ�ʹ�ֱ�ռ䣬�����������������һ���Դ���һ���µ� Rectangle ���� Rectangle
		Rectangle GetUnion(Rectangle toUnion);
	private:
		//y �� height ���Եĺ͡� Rectangle
		Number bottom;
		//�� right �� bottom ���Ե�ֵȷ���� Rectangle ��������½ǵ�λ�á� Rectangle
		Point bottomRight;
		//���εĸ߶ȣ�������Ϊ��λ���� Rectangle
		Number height;
		//�������Ͻǵ� x ���ꡣ Rectangle
		Number left;
		//x �� width ���Եĺ͡� Rectangle
		Number right;
		//Rectangle ����Ĵ�С���ö����ʾΪ���� width �� height ���Ե�ֵ�� Point ���� Rectangle
		Point size;
		//�������Ͻǵ� y ���ꡣ Rectangle
		Number top;
		//�ɸõ�� x �� y ����ȷ���� Rectangle �������Ͻǵ�λ�á� Rectangle
		Point topLeft;
		//���εĿ�ȣ�������Ϊ��λ���� Rectangle
		Number width;
		//�������Ͻǵ� x ���ꡣ Rectangle
		Number x;
		//�������Ͻǵ� y ���ꡣ Rectangle
		Number y;
	
	};
}