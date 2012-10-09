#pragma once
#include "splght.h"
class BitmapData;
namespace splght{
//Bitmap ���ʾ���ڱ�ʾλͼͼ�����ʾ������Щͼ�������ʹ�� flash.display.Loader ����ص�ͼ��
//Ҳ������ʹ�� Bitmap() ���캯��������ͼ��
//���� Bitmap() ���캯�������Դ��������� BitmapData ��������õ� Bitmap ����
//������ Bitmap �����ʹ�ø� DisplayObjectContainer ʵ���� addChild() �� addChildAt() ������λͼ������ʾ�б��С�

	class	Bitmap/*: public DisplayObject*/	//OK
	{
	public:
		//��ʼ�� Bitmap ����������ָ���� BitmapData ���� Bitmap
		Bitmap(const BitmapData& bitmapData, LX_String sPixelSnapping= "auto", LX_BOOL bSmoothing= false);
		~Bitmap();
	private:
		//�����õ� BitmapData ���� Bitmap
		BitmapData bitmapData;
		//���� Bitmap �����Ƿ���������������ء� Bitmap
		LX_String m_sPixelSnapping;
		//����������ʱ�Ƿ��λͼ����ƽ������ Bitmap
		LX_BOOL m_bSmoothing;
	};
}