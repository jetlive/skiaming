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

	class	ByteArray: public Object
	{
	public:
		ByteArray();	//����һ����ʾ�����ֽ������ ByteArray ʵ�����Ա�ʹ�ô����еķ������������Ż����ݴ洢��������
	private:
		uint bytesAvailable;	//[ֻ��] �ɴ��ֽ�����ĵ�ǰλ�õ�����ĩβ��ȡ�����ݵ��ֽ����� ByteArray 
		uint defaultObjectEncoding;		//[��̬] ָʾ������ ByteArray ʵ���� ByteArray ���Ĭ�϶�����롣 ByteArray 
		String endian;	//���Ļ��ȡ���ݵ��ֽ�˳��Endian.BIG_ENDIAN �� Endian.LITTLE_ENDIAN�� ByteArray 
		uint length;	//ByteArray ����ĳ��ȣ����ֽ�Ϊ��λ���� ByteArray 
		uint objectEncoding;		//����ȷ����д����ȡ ByteArray ʵ��ʱӦʹ�� ActionScript 3.0��ActionScript 2.0 ���� ActionScript 1.0 ��ʽ�� ByteArray 
		uint position;	//���ļ�ָ��ĵ�ǰλ�ã����ֽ�Ϊ��λ���ƶ��򷵻ص� ByteArray �����С� ByteArray 
	};
}