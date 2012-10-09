#pragma once
#include "splght.h"
#include <vector>
#include <string>
namespace splght{
typedef struct
{
	LX_float x;
	LX_float y;
}Point, *PPOINT;
//Rectangle �����ǰ���λ�ã��������Ͻǵĵ� (x, y) ȷ�����Լ���Ⱥ͸߶ȶ�������� 
//Rectangle ��� x��y��width �� height �����໥����������һ�����Ե�ֵ����Ӱ���������ԡ�
//���ǣ�right �� bottom ���������ĸ�������������صġ����磬������� right ���Ե�ֵ���� width ���Ե�ֵ�������仯��
//������� bottom ���ԣ��� height ���Ե�ֵ�������仯�� 

	class	Rectangle/*: public Object*/
	{
	public:
		//����һ���� Rectangle ���������Ͻ��� x �� y ����ָ����������ָ���� width �� height ������ Rectangle
		Rectangle(LX_float x= 0, LX_float y= 0, LX_float width= 0, LX_float height= 0);
		//����һ���µ� Rectangle ������ x��y��width �� height ���Ե�ֵ��ԭʼ Rectangle ����Ķ�Ӧֵ��ͬ�� Rectangle
		//Rectangle    clone( );
		//ȷ���ɴ� Rectangle ������ľ����������Ƿ����ָ���ĵ㡣 Rectangle
		//Boolean    contains(Number x,Number  y);
		//ȷ���ɴ� Rectangle ������ľ����������Ƿ����ָ���ĵ㡣 Rectangle
		//Boolean    containsPoint(Point point);
		//ȷ���� Rectangle �������Ƿ������ rect ����ָ���� Rectangle ���� Rectangle
		//Boolean    containsRect(Rectangle rect);
		//ȷ���� toCompare ������ָ���Ķ����Ƿ���ڴ� Rectangle ���� Rectangle
		//Boolean    equals(Rectangle toCompare);
		//��ָ�������� Rectangle ����Ĵ�С��������Ϊ��λ���� Rectangle
		//void    inflate(Number dx,Number  dy);
		//���� Rectangle ����Ĵ�С�� Rectangle
		//void    inflatePoint(Point point);
		//����� toIntersect ������ָ���� Rectangle ������� Rectangle �����ཻ���򷵻ؽ���������Ϊ Rectangle ���� Rectangle
		//Rectangle    intersection(Rectangle toIntersect);
		//ȷ���� toIntersect ������ָ���Ķ����Ƿ���� Rectangle �����ཻ�� Rectangle
		//Boolean    intersects(Rectangle toIntersect);
		//ȷ���� Rectangle �����Ƿ�Ϊ�ա� Rectangle
		//Boolean    isEmpty( );
		//��ָ�������� Rectangle �����λ�ã��������Ͻ�ȷ������ Rectangle
		//void    offset(Number dx,Number  dy);
		//�� Point ������������������ Rectangle �����λ�á� Rectangle
		//void    offsetPoint(Point point);
		//�� Rectangle �����������������Ϊ 0�� Rectangle
		//void    setEmpty( );
		//���ɲ�����һ���ַ��������ַ����г� Rectangle �����ˮƽλ�úʹ�ֱλ���Լ��߶ȺͿ�ȡ� Rectangle
		//String    toString( );
		//ͨ�������������֮���ˮƽ�ʹ�ֱ�ռ䣬�����������������һ���Դ���һ���µ� Rectangle ���� Rectangle
		//Rectangle GetUnion(Rectangle toUnion);
	private:
		//y �� height ���Եĺ͡� Rectangle
		//LX_float m_fBottom;
		//�� right �� bottom ���Ե�ֵȷ���� Rectangle ��������½ǵ�λ�á� Rectangle
		//Point m_bottomRight;
		//���εĸ߶ȣ�������Ϊ��λ���� Rectangle
		LX_float m_fHeight;
		//�������Ͻǵ� x ���ꡣ Rectangle
		//LX_float m_fLeft;
		//x �� width ���Եĺ͡� Rectangle
		//LX_float m_fRight;
		//Rectangle ����Ĵ�С���ö����ʾΪ���� width �� height ���Ե�ֵ�� Point ���� Rectangle
		//Point size;
		//�������Ͻǵ� y ���ꡣ Rectangle
		//LX_float top;
		//�ɸõ�� x �� y ����ȷ���� Rectangle �������Ͻǵ�λ�á� Rectangle
		//Point topLeft;
		//���εĿ�ȣ�������Ϊ��λ���� Rectangle
		LX_float m_fWidth;
		//�������Ͻǵ� x ���ꡣ Rectangle
		LX_float m_fX;
		//�������Ͻǵ� y ���ꡣ Rectangle
		LX_float m_fY;
	
	};
}