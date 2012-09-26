#pragma once
#include "StdAfx.h"
#include "DisplayObjectContainer.h"
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

/*Sprite ���ǻ�����ʾ�б���飺һ������ʾͼ�β���Ҳ�ɰ����������ʾ�б�ڵ㡣 
Sprite ������ӰƬ�������ƣ���û��ʱ���ᡣSprite �ǲ���Ҫʱ����Ķ������Ӧ���ࡣ
���磬Sprite ����ͨ����ʹ��ʱ������û����� (UI) ������߼����ࡣ
Sprite ���� ActionScript 3.0 ����������ࡣ���ṩ�� MovieClip �๦�ܵ�������ܣ�
��������ܱ����� ActionScript ��ǰ�汾�����й������ṩ�������ԡ�*/


	class	Sprite : public  DisplayObjectContainer
	{
	public:
		//����һ���µ� Sprite ʵ���� Sprite
		Sprite( );
		//�����û��϶�ָ���� Sprite�� Sprite
		void    startDrag(Boolean  lockCenter= false,Rectangle   bounds= null);
		//���� startDrag() ������ Sprite
		void    stopDrag( );
		//ָ���� sprite �İ�ťģʽ�� Sprite
	private:
		Boolean buttonMode;
		//[ֻ��] ָ���϶� sprite ʱ��������ʾ���󣬻���� sprite ����ʾ���� Sprite
		DisplayObject dropTarget;
		//[ֻ��] ָ�����ڴ� sprite �� Graphics �����ڴ� sprite �п�ִ��ʸ���滭��� Sprite
		Graphics graphics;
		//ָ��һ�� sprite ������һ�� sprite �ĵ������ Sprite
		Sprite hitArea;
		//���ƴ� sprite �е������� Sprite
		flash.media:SoundTransform soundTransform;
		//����ֵ��ָʾ����껬���� buttonMode ��������Ϊ true �� sprite ʱ�Ƿ���ʾ��ָ�Σ����ι�꣩�� Sprite
		Boolean useHandCursor;
	};
}