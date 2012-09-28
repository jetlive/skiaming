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
/*
URLRequest ��ɲ��񵥸� HTTP �����е�������Ϣ��URLRequest ���󽫴��ݸ� 
Loader��URLStream �� URLLoader ��� load() �������������ز�����
�Ա����� URL ���ء���Щ���󻹽����ݸ� FileReference ��� upload() �� download() ������ 
ֻ���뱾���ļ�ϵͳ���ݽ�����ɳ���е� SWF �ļ��޷���������ɳ���е���Դ��
���������ݣ�Ҳ�޷�Ϊ����Դ�ṩ���ݡ� 
Ĭ������£�ִ�е��õ� SWF �ļ��ͼ��ص� URL ������ͬһ���С�
���磬λ�� www.adobe.com �� SWF �ļ�ֻ�ܴ�ͬ��λ�� www.adobe.com 
��Դ�м������ݡ�Ҫ�Ӳ�ͬ�����м������ݣ����ڳ������ݵķ������Ϸ���
һ�� URL �����ļ��� 
���� Adobe AIR �У�Ӧ�ó���ȫɳ���е����ݣ��� AIR Ӧ�ó���һ��װ�����ݣ�
������Щ��ȫ���Ƶ�Լ���������� Adobe AIR �����е����ݣ�
Ӧ�ó���ȫɳ���е��ļ����Է���ʹ��������һ URL ������ URL��
Ӧ�ó���ȫ���е��ļ����� AIR Ӧ�ó���һ��װ���ļ�����
����ʹ��������һ URL �������� URL��
http �� https 
file 
app-storage 
app */

	class	URLRequest : public Object
	{
	public:
		//���� URLRequest ���� URLRequest
		URLRequest(String  url= null);
	private:
		//ָ���Ƿ�ӦΪ����������֤��������ǣ���Ϊ true������Ϊ false�� URLRequest
		Boolean authenticate;
		//ָ���Ƿ�ӦΪ�����󻺴�ɹ�����Ӧ���ݡ� URLRequest
		Boolean cacheResponse;
		//data ���������ݵ� MIME �������͡� URLRequest
		String contentType;
		//һ���������������� URL ����һ��������ݡ� URLRequest
		Object data;
		//Ψһ�ر�ʶ���洢�� Flash Player �����У�����м���������ǩ�� Adobe ƽ̨������ַ����� URLRequest
		String digest;
		//ָ���Ƿ�Ҫ��ѭ�ض�������ǣ���Ϊ true������Ϊ false�� URLRequest
		Boolean followRedirects;
		//ָ�� HTTP Э���ջ�Ƿ�Ӧ���������� cookie�� URLRequest
		Boolean manageCookies;
		//���� HTTP ʽ�ύ������ URLRequest
		String method;
		//Ҫ׷�ӵ� HTTP ����� HTTP �����ͷ�����顣 URLRequest
		Array requestHeaders;
		//������� URL�� URLRequest
		String url;
		//ָ���ڴ� URLRequest ��ȡ����֮ǰ�Ƿ�Ӧ��ѯ���ػ��档 URLRequest
		Boolean useCache;
		//ָ��Ҫ�� HTTP ������ʹ�õ��û������ַ����� URLRequest
		String userAgent;
	};
}