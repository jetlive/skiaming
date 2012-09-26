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

/*ShaderFilter ��ͨ����Ӧ�����˾��Ķ���ִ����ɫ����Ӧ���˾���Ӧ�����˾��Ķ���������ɫ�����룬
����ɫ������������˾�Ч���� 
Ҫ�����µ��˾�����ʹ�ù��캯�� new ShaderFilter()���˾��ľ���ʹ��ȡ����ҪӦ���˾��Ķ���
Ҫ��ӰƬ�������ı��ֶΡ���ť����ƵӦ���˾�����ʹ�� filters ���ԣ��̳��� DisplayObject����
���ö���� filters ���Բ����޸���Ӧ�Ķ��󣬶���� filters ���Կ���ɾ����Ӧ���˾��� 
Ҫ�� BitmapData ����Ӧ���˾�����ʹ�� BitmapData.applyFilter() �������� BitmapData ������� applyFilter() ��
ȡ��Դ BitmapData ������˾����󣬲���������һ������ͼ�� 
�������ʾ����Ӧ���˾�����ö���� cacheAsBitmap ����ֵ������Ϊ true�����ɾ�������˾���
���ָ� cacheAsBitmap ��ԭʼֵ��
���˾�֧����̨���š����ǣ�����֧�ֳ������š���ת����б�������������������ţ���� scaleX �� scaleY ����
δ������Ϊ 100%�������˾����������š�ֻ���û�����̨�Ͻ��зŴ�ʱ���Ż����š�
�������ͼ�񳬹����ߴ磬��Ӧ���˾���
Ҫָ���� Shader ʵ�������˾����뽫 Shader ʵ����Ϊ�������ݵ� ShaderFilter() ���캯������������Ϊ shader ���Ե�ֵ��
Ҫ������ɫ����������ѹ��˶���ķ�Χ����ʹ�� leftExtension��rightExtension��topExtension �� bottomExtension ���ԡ�*/
	class ShaderFilter: public BitmapFilter
	{
	public:
		//�����µ���ɫ���˾��� ShaderFilter
		ShaderFilter(Shader  shader= null);
	private:
		//Ŀ�����ײ�����������������Ϊ��λ���� ShaderFilter
		int bottomExtension;
		//Ŀ�����������������������Ϊ��λ���� ShaderFilter
		int leftExtension;
		//Ŀ������Ҳ����������������Ϊ��λ���� ShaderFilter
		int rightExtension;
		//ҪΪ���˾�ʹ�õ���ɫ���� ShaderFilter
		Shader shader;
		//Ŀ����󶥲�����������������Ϊ��λ���� ShaderFilter
		int topExtension;
	};
}
