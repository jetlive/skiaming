#pragma once
#include "StdAfx.h"
#include "DisplayObjectContainer.h"
#include "LoaderInfo.h"
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
//Loader ������ڼ��� SWF �ļ���ͼ��JPG��PNG �� GIF���ļ���ʹ�� load() �������������ء�
//�����ص���ʾ������Ϊ Loader ������Ӽ���ӡ�
//ʹ�� URLLoader ������ı�����������ݡ�
	class	Loader : public  DisplayObjectContainer 
	{
	public:
		//����һ�������ڼ����ļ����� SWF��JPEG��GIF �� PNG �ļ����� Loader ���� Loader
		Loader( );
		//ȡ����ǰ���ڶ� Loader ʵ��ִ�е� load() ���������� Loader
		void    close( );
		//�� SWF��JPEG������ʽ JPEG���Ƕ��� GIF �� PNG �ļ����ص��� Loader ������Ӷ����С� Loader
		void    load(URLRequest request,LoaderContext   context= null);
		//�� ByteArray ���������洢�Ķ����������м��ء� Loader
		void    loadBytes(ByteArray bytes,LoaderContext   context= null);
		//ɾ���� Loader ������ʹ�� load() �������ص���� Loader
		void    unload( );
		//����ж���� SWF �ļ����ݲ�ִֹͣ���Ѽ��ص� SWF �ļ��е���� Loader
		void    unloadAndStop(Boolean  gc= true);
		
	private:
		//[ֻ��] ����ʹ�� load() �� loadBytes() �������ص� SWF �ļ���ͼ��JPG��PNG �� GIF���ļ��ĸ���ʾ���� Loader
		DisplayObject content;
		//[ֻ��] ���������ڼ��صĶ������Ӧ�� LoaderInfo ���� Loader
		LoaderInfo contentLoaderInfo;

	};
}