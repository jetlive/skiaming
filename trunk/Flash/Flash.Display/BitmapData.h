#pragma once
#include "StdAfx.h"
#include "Object.h"
#include "Rectangle.h"
#include <vector>
#include <string>
#include "SKBitmap.h"
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

/*ʹ�� BitmapData ����Դ��� Bitmap �����λͼͼ������ݣ����أ�������ʹ�� BitmapData ��ķ������������С��͸����͸��
λͼͼ�񣬲�������ʱ���ö��ַ�ʽ������Щͼ��Ҳ���Է���ʹ�� flash.display.Loader ����ص�λͼͼ��� BitmapData�� 
������������λͼ���ֲ����� Flash Player ���ڲ���ʾ�������̷ָ�������ͨ��ֱ�Ӳ��� BitmapData ����
�����Դ������ӵ�ͼ�񣬲������������»���ʸ�����ݵ����ݶ�����ÿ֡������
BitmapData ��ķ���֧��ͨ�������ڷ�λͼ��ʾ������˾��޷��õ���Ч����
BitmapData ��������������ݵ����顣�����ݿ��Ա�ʾ��ȫ��͸����λͼ�����ʾ���� Alpha ͨ�����ݵ�͸��λͼ��
������һ���͵� BitmapData ������Ϊ 32 λ�����Ļ��������д洢��ÿ�� 32 λ����ȷ��λͼ�е������ص����ԡ�
ÿ�� 32 λ���������ĸ� 8 λͨ��ֵ���� 0 �� 255������ϣ���Щֵ�������ص� Alpha ͸�����Լ���ɫ����ɫ����ɫ (ARGB) ֵ��
������ ARGB ֵ�������Ч�ֽڴ��� Alpha ͨ��ֵ��������Ч�ֽڷֱ�����ɫ����ɫ����ɫͨ��ֵ����
�����ĸ�ͨ����Alpha����ɫ����ɫ����ɫ���� BitmapData.copyChannel() ������ 
DisplacementMapFilter.componentX �� DisplacementMapFilter.componentY ����һ��ʹ��ʱ��
��Щͨ����������ʽ��ʾ��������Щ������ BitmapDataChannel ���������³�����ʾ��
BitmapDataChannel.ALPHA 
BitmapDataChannel.RED 
BitmapDataChannel.GREEN 
BitmapDataChannel.BLUE 
ͨ��ʹ�� Bitmap ����� bitmapData ���ԣ����Խ� BitmapData ���󸽼ӵ� Bitmap ����
����ʹ�� Graphics.beginBitmapFill() ������ BitmapData ������� Graphics ����
��� BitmapData ������Ч�����磬������� height == 0 �� width == 0����������ͨ�� dispose() �����˸ö���
��� BitmapData ������κη��������Եĵ��ö������� ArgumentError ���� */
	class	BitmapData: public Object
	{
	private:
		SkBitmap m_pBitmap;
	public:
		/*����һ������ָ���Ŀ�Ⱥ͸߶ȵ� BitmapData �������Ϊ fillColor ����ָ��һ��ֵ����λͼ�е�ÿ�����ض���
		����Ϊ����ɫ�� 
		Ĭ������£���λͼ����Ϊ͸��λͼ��������Ϊ transparent ��������ֵ false�������˲�͸��λͼ��
		���޷��������Ϊ͸��λͼ����͸��λͼ�е�ÿ�����ؽ�ʹ�� 24 λ����ɫͨ����Ϣ�������λͼ����Ϊ͸����
		��ÿ�����ؽ�ʹ�� 32 λ����ɫͨ����Ϣ�����а��� Alpha ͸����ͨ����*/
		// width:int �� λͼͼ��Ŀ�ȣ�������Ϊ��λ��  
		// height:int �� λͼͼ��ĸ߶ȣ�������Ϊ��λ��  
		// transparent:Boolean (default = true) �� ָ��λͼͼ���Ƿ�֧��ÿ�����ؾ��в�ͬ��͸���ȡ�Ĭ��ֵΪ true��͸������
		// Ҫ������ȫ͸����λͼ���뽫 transparent ������ֵ����Ϊ true���� fillColor ������ֵ����Ϊ 0x00000000��������Ϊ 0����
		// �� transparent ��������Ϊ false ������΢�����������ܡ�  
		// fillColor:uint (default = 0xFFFFFFFF) �� �������λͼͼ������� 32 λ ARGB ��ɫֵ��Ĭ��ֵΪ 0xFFFFFFFF������ɫ����
		BitmapData(int width,int  height,bool transparent= true, unsigned int fillColor= 0xFFFFFFFF);

		/*ȡ��һ��Դͼ���һ���˾����󣬲����ɹ��˵�ͼ��;
		�˷��������������˾��������Ϊ����Щ����ȷ��������Դ����Ӱ���Ŀ����Ρ�;
		Ӧ���˾��󣬽��ͼ����ܻ��������ͼ��;
		��� sourceBitmapData ������ sourceRect �������ڲ�����,���˾���ʹ�� sourceRect �����ⲿ��Դ����������Ŀ����Ρ�;
		��� BitmapData �����ָ��Ϊ sourceBitmapData �����Ķ�����ͬһ����Ӧ�ó���ʹ�øö������ʱ������ִ���˾���;
		Ϊ�˻��������ܣ���������������*/
		// sourceBitmapData:Ҫʹ�õ�����λͼͼ��Դͼ���������һ�� BitmapData ����Ҳ�������õ�ǰ BitmapData ʵ��;
		// sourceRect:Rectangle �� ����Ҫ���������Դͼ������ľ���;
		// destPoint:Point �� Ŀ��ͼ�񣨵�ǰ BitmapData ʵ��������Դ���ε����ϽǶ�Ӧ�ĵ�;
		// filter:BitmapFilter �� ����ִ�й��˲������˾�����ÿ���˾�����ĳЩҪ��������ʾ�� 
		// BlurFilter �� ���˾���ʹ�ò�͸����͸����Դͼ���Ŀ��ͼ�����������ͼ��ĸ�ʽ��ƥ��;
		// ���ڹ��˹��������ɵ�Դͼ�񸱱�����Ŀ��ͼ��ĸ�ʽƥ�䡣 
		// BevelFilter��DropShadowFilter��GlowFilter��ChromeFilter �� ��Щ�˾���Ŀ��ͼ�������͸��ͼ��
		// ���� DropShadowFilter �� GlowFilter �ᴴ������ͶӰ�򷢹�� Alpha ͨ�����ݵ�ͼ��
		// ��������Ŀ��ͼ���ϴ���ͶӰ���������Щ�˾��е��κ��˾����ڲ�͸����Ŀ��ͼ�񣬽��������쳣�� 
		// ConvolutionFilter �� ���˾���ʹ�ò�͸����͸����Դͼ���Ŀ��ͼ��;
		// ColorMatrixFilter �� ���˾���ʹ�ò�͸����͸����Դͼ���Ŀ��ͼ�� 
		// DisplacementMapFilter �� ���˾���ʹ�ò�͸����͸����Դͼ���Ŀ��ͼ�񣬵�Դͼ���Ŀ��ͼ��ĸ�ʽ������ͬ��
		void    applyFilter(BitmapData sourceBitmapData,Rectangle  sourceRect,Point  destPoint,BitmapFilter  filter);

		//����һ���µ� BitmapData �������Ƕ�ԭʼʵ���Ŀ�¡��������ԭʼʵ������λͼ��ȫ��ͬ�ĸ����� BitmapData
		BitmapData clone();
		//ʹ�� ColorTransform �������λͼͼ���ָ�������е���ɫֵ�� BitmapData
		void    colorTransform(Rectangle rect,flash.geom:ColorTransform  colorTransform);
		//�Ƚ����� BitmapData ���� BitmapData
		Object    compare(BitmapData otherBitmapData);
		//�����ݴ���һ�� BitmapData �����ǰ BitmapData �����һ��ͨ�����䵽��ǰ BitmapData �����ĳ��ͨ���С� BitmapData
		void    copyChannel(BitmapData sourceBitmapData,Rectangle  sourceRect,Point  destPoint,uint  sourceChannel,uint  destChannel);
		//Ϊû�����졢��ת��ɫ��Ч����ͼ��֮������ش����ṩһ���������̡� BitmapData
		void    copyPixels(BitmapData sourceBitmapData,Rectangle  sourceRect,Point  destPoint,BitmapData   alphaBitmapData= null,Point   alphaPoint= null,Boolean   mergeAlpha= false);
		//�ͷ������洢 BitmapData ������ڴ档 BitmapData
		void    dispose( );
		//ʹ�� Flash Player �� AIR ʸ����Ⱦ����λͼͼ���ϻ��� source ��ʾ���� BitmapData
		void    draw(IBitmapDrawable source,Matrix   matrix= null,flash.geom:ColorTransform   colorTransform= null,String   blendMode= null,Rectangle   clipRect= null,Boolean   smoothing= false);
		//ʹ��ָ���� ARGB ��ɫ���һ�������������� BitmapData
		void    fillRect(Rectangle rect,uint  color);
		//��ͼ��ִ���㵹���������� (x, y) ���꿪ʼ�����һ���ض�����ɫ�� BitmapData
		void    floodFill(int x,int  y,uint  color);
		//��֪ BitmapData ����Դ���κ��˾�����ȷ�� applyFilter() ����������Ӱ���Ŀ����Ρ� BitmapData
		Rectangle    generateFilterRect(Rectangle sourceRect,BitmapFilter  filter);
		//ȷ�����������ǽ�λͼͼ����ָ����ɫ������������ȫ��������������� findColor ��������Ϊ true�������ǽ�������ָ����ɫ������������ȫ��������������� findColor ��������Ϊ false���� BitmapData
		Rectangle    getColorBoundsRect(uint mask,uint  color,Boolean   findColor= true);
		//����һ������������ʾ BitmapData ���������ض��� (x, y) ���� RGB ����ֵ�� BitmapData
		uint    getPixel(int x,int  y);
		//����һ�� ARGB ��ɫֵ�������� Alpha ͨ�����ݺ� RGB ���ݡ� BitmapData
		uint    getPixel32(int x,int  y);
		//���������ݵľ�����������һ���ֽ����顣 BitmapData
		ByteArray    getPixels(Rectangle rect);
		//���������ݵľ�����������һ��ʸ�����顣 BitmapData
		vector<uint>    getVector(Rectangle rect);
		//���� BitmapData ����� 256 ֵ��������ֱ��ͼ�� BitmapData
		vector<vector<Number>>    histogram(Rectangle  hRect= null);
		//��һ��λͼͼ����һ���㡢���λ�����λͼͼ��֮��ִ�����ؼ��ĵ����⡣ BitmapData
		Boolean    hitTest(Point firstPoint,uint  firstAlphaThreshold,Object  secondObject,Point   secondBitmapDataPoint= null,uint   secondAlphaThreshold= 1);
		//����ͼ����ʹ���� BitmapData ������κζ����� Bitmap �����ڴ� BitmapData �������ʱ������¡� BitmapData
		void    lock( );
		//��ÿ��ͨ��ִ�д�Դͼ����Ŀ��ͼ��Ļ�ϡ� BitmapData
		void    merge(BitmapData sourceBitmapData,Rectangle  sourceRect,Point  destPoint,uint  redMultiplier,uint  greenMultiplier,uint  blueMultiplier,uint  alphaMultiplier);
		//ʹ�ñ�ʾ����ӵ���������ͼ�� BitmapData
		void    noise(int randomSeed,uint   low= 0,uint   high= 255,uint   channelOptions= 7,Boolean   grayScale= false);
		//����ӳ��һ��������������ɫ�����ݣ�ÿ��ͨ��һ�飩��ͼ���е���ɫͨ��ֵ�� BitmapData
		void    paletteMap(BitmapData sourceBitmapData,Rectangle  sourceRect,Point  destPoint,Array   redArray= null,Array   greenArray= null,Array   blueArray= null,Array   alphaArray= null);
		//���� Perlin �ӵ�ͼ�� BitmapData
		void    perlinNoise(Number baseX,Number  baseY,uint  numOctaves,int  randomSeed,Boolean  stitch,Boolean  fractalNoise,uint   channelOptions= 7,Boolean   grayScale= false,Array   offsets= null);
		//ִ��Դͼ��Ŀ��ͼ��������ܽ⣬��ʹ��ͬһͼ��ִ�������ܽ⡣ BitmapData
		int    pixelDissolve(BitmapData sourceBitmapData,Rectangle  sourceRect,Point  destPoint,int   randomSeed= 0,int   numPixels= 0,uint   fillColor= 0);
		//��ĳһ (x, y) ����������ͼ�� BitmapData
		void    scroll(int x,int  y);
		//���� BitmapData ����ĵ������ء� BitmapData
		void    setPixel(int x,int  y,uint  color);
		//���� BitmapData ���󵥸����ص���ɫ�� Alpha ͸����ֵ�� BitmapData
		void    setPixel32(int x,int  y,uint  color);
		//���ֽ�����ת��Ϊ�������ݵľ������� BitmapData
		void    setPixels(Rectangle rect,ByteArray  inputByteArray);
		//�� Vector ת��Ϊ�������ݵľ������� BitmapData
		void    setVector(Rectangle rect,vector<uint>  inputVector);
		//����ָ������ֵ����ͼ���е�����ֵ������ͨ�����Ե���������Ϊ�µ���ɫֵ�� BitmapData
		uint threshold(BitmapData sourceBitmapData,Rectangle  sourceRect,Point  destPoint,String  operation,uint  threshold,uint   color= 0,uint   mask= 0xFFFFFFFF,Boolean   copySource= false);
		//�������ͼ����ʹ���� BitmapData ������κζ����� Bitmap �����ڴ� BitmapData �������ʱ���¡� BitmapData
		void    unlock(Rectangle  changeRect= null);
	private:
		//[ֻ��] λͼͼ��ĸ߶ȣ�������Ϊ��λ�� BitmapData
		int height;
		//[ֻ��] ����λͼͼ���С��λ�õľ��Ρ����εĶ��������Ϊ�㣻��Ⱥ͸߶ȵ��� BitmapData ����Ŀ�Ⱥ͸߶�(������Ϊ��λ) BitmapData
		Rectangle rect;
		//[ֻ��] ����λͼͼ���Ƿ�֧��ÿ�����ؾ��в�ͬ��͸����.ֻ�е�ͨ��Ϊ���캯���� transparent �������� true ������ BitmapData ����ʱ���������ô�ֵ BitmapData
		Boolean transparent;
		//[ֻ��] λͼͼ��Ŀ�ȣ�������Ϊ��λ�� BitmapData
		int width;
	};
}