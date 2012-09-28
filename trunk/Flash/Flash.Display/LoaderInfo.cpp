#pragma once
#include "StdAfx.h"

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

/*LoaderInfo ����ṩ�й��Ѽ��ص� SWF �ļ���ͼ���ļ���JPEG��GIF �� PNG������Ϣ��
LoaderInfo ����������κ���ʾ�����ṩ����Ϣ�������ؽ��ȡ����س���� URL ��
�������ݡ�ý����ֽ������Լ�ý��ı�ʾ�ĸ߶ȺͿ�ȡ� 
flash.display.Loader ����� contentLoaderInfo ���� - contentLoaderInfo ����ʼ��
�������κ� Loader ���󡣶�����δ���� load() �� loadBytes() ������������δ���
���ص� Loader �����ڳ��Է��� contentLoaderInfo ���ԵĶ������ʱ������������ 
��ʾ����� loaderInfo ���ԡ� 
Loader ����� contentLoaderInfo �����ṩ�й� Loader �������ڼ��ص����ݵ���Ϣ��
�� DisplayObject �� loaderInfo �����ṩ�йظ���ʾ����ĸ� SWF �ļ�����Ϣ�� 
��ʹ�� Loader ���������ʾ������ SWF �ļ���λͼ��ʱ����ʾ����� loaderInfo ����
�� Loader ���� (DisplayObject.loaderInfo = Loader.contentLoaderInfo) �� 
contentLoaderInfo ������ͬ������ SWF �ļ��������ʵ��û�� Loader ����
��� loaderInfo �����Ƿ��� SWF �ļ�����ʵ���� LoaderInfo ��Ψһ������*/


	class	LoaderInfo: public  EventDispatcher
	{
	public:
		//[��̬] �����붨��Ϊ����� SWF �ļ�������� LoaderInfo ���� LoaderInfo
		LoaderInfo getLoaderInfoByDefinition(Object object);
	private:
		//[ֻ��] �����ص� SWF �ļ��� ActionScript �汾�� LoaderInfo
		uint actionScriptVersion;
		//[ֻ��] �����ⲿ SWF �ļ��󣬰������Ѽ������е����� ActionScript 3.0 ���彫�洢�� applicationDomain �����С� LoaderInfo
		ApplicationDomain applicationDomain;
		//[ֻ��] �� LoaderInfo ������������ֽ����� LoaderInfo
		ByteArray bytes;
		//[ֻ��] ý���Ѽ��ص��ֽ����� LoaderInfo
		uint bytesLoaded;
		//[ֻ��] ����ý���ļ���ѹ�����ֽ����� LoaderInfo
		uint bytesTotal;
		//[ֻ��] ��ʾ���ݣ��Ӽ����Լ����ߣ������������ι�ϵ�� LoaderInfo
		Boolean childAllowsParent;
		//һ������������ͨ�����������ݵĴ�����������Թ��������� Loader �����ɳ���еĴ�����ʵ����Ժͷ����� LoaderInfo
		Object childSandboxBridge;
		//[ֻ��] ��� LoaderInfo ����������Ѽ��ض��� LoaderInfo
		DisplayObject content;
		//[ֻ��] �������ļ��� MIME ���͡� LoaderInfo
		String contentType;
		//[ֻ��] �����ص� SWF �ļ��ı�ʾ��֡���ʣ���ÿ��֡��Ϊ��λ�� LoaderInfo
		Number frameRate;
		//[ֻ��] �����ļ��ı�ʾ�ĸ߶ȡ� LoaderInfo
		int height;
		//[ֻ��] ��� LoaderInfo ��������� Loader ���� LoaderInfo
		Loader loader;
		//[ֻ��] SWF �ļ��� URL���� SWF �ļ������Դ� LoaderInfo ������������ý��ļ��ء� LoaderInfo
		String loaderURL;
		//[ֻ��] ��������-ֵ�ԵĶ��󣬱�ʾΪ�����ص� SWF �ļ��ṩ�Ĳ����� LoaderInfo
		Object parameters;
		//[ֻ��] ��ʾ�����ߣ������������ݣ��Ӽ��������ι�ϵ�� LoaderInfo
		Boolean parentAllowsChild;
		//һ�������������� Loader �����ɳ����ͨ��������������Թ������������������ݵĴ�����ʵ����Ժͷ����� LoaderInfo
		Object parentSandboxBridge;
		//[ֻ��] ��ʾ�����ߺ�����֮������ϵ��������Ǿ�����ͬ��ԭʼ����Ϊ true������Ϊ false�� LoaderInfo
		Boolean sameDomain;
		//[ֻ��] EventDispatcher ʵ���������ڿ簲ȫ�߽罻���¼��� LoaderInfo
		EventDispatcher sharedEvents;
		//[ֻ��] �Ѽ��ص� SWF �ļ����ļ���ʽ�汾�� LoaderInfo
		uint swfVersion;
		//[ֻ��] ������ý��� URL�� LoaderInfo
		String url;
		//[ֻ��] ���������ݵı�ʾ�Ŀ�ȡ� LoaderInfo
		int width;
	};
}