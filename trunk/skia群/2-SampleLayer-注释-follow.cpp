#include "SampleCode.h"
#include "SkView.h"
#include "SkCanvas.h"
#include "SkBlurMaskFilter.h"
#include "SkCamera.h"
#include "SkColorFilter.h"
#include "SkColorPriv.h"
#include "SkDevice.h"
#include "SkGradientShader.h"
#include "SkImageDecoder.h"
#include "SkInterpolator.h"
#include "SkMaskFilter.h"
#include "SkPath.h"
#include "SkRegion.h"
#include "SkShader.h"
#include "SkTime.h"
#include "SkTypeface.h"
#include "SkUtils.h"
#include "SkKey.h"
#include "SkXfermode.h"
#include "SkDrawFilter.h"
/*���ڲ������ݻ�������, ���������������*/


/** Layers��     -----------------   ���Բο�photoshop��ͼ���Ӧ����Ч��Ŷ��
����ʹ������ : 1. saveLayer -> ���� -> restore
               2. saveLayer, saveLayer, saveLayer -> ���� -> restore, restore, restore
����ԭ�� : saveLayer������ -> ֮������ڸò�������������, ���л��� -> restore��ݹ�Ľ���������, ��һ����û���ͷŵ�layer��Դcanvas��.
������� : 1. ������ͬ�����layer, �����γ�canvas�� ��ͬ������ֲ�ͬ������, 
            ������canvas.draw(ȫ��, ��Բ), restore���в��, �㽫����һ���ڲ�ͬ������ֲ�ͬ���Ե���Բ(͸��Ч����)
           2. ��ЩЧ��ֻ��layer����ʹ��, ������layer�ϸ���������.
            ����: (1) ����������һ��ʵ��, ��û��layerʱ, setXfermodeMode��Ч�����޷���Ч��
                  (2) ��ϲ������Ƴ� ��5�� ���½������Բ,,,������ò㡫����ΰ쵽`?
*/
/*�������� : onDraw(������1-��5) -> test_fade(��4) */
static void make_paint(SkPaint* paint) {
    /*??????????????????????CreateLiner��������������????*/
    //������Ӱ����
    SkColor colors[] = { 0, SK_ColorWHITE};
    SkPoint pts[] = { { 0, 0 }, { 0, SK_Scalar1*20}};
    SkShader* s = SkGradientShader::CreateLinear(pts, colors, NULL, 2, SkShader::kClamp_TileMode);
    //����Ӱ �ӵ�������
    paint->setShader(s)->unref();
    /*�ص�
    ����Dstͼ����������� ���л��
    �Ѹþ�ע�͵�, ���ͼ�� ���Կ��� :
    Dst�� ������Ƭ ���ڵ���� ��ɫ�������.
    Src�� ֮ǰ���Ƶĺ�Բ
    kDstIn_Mode �� ����Ϊsrc&dst�ཻ��dst����, ��
                   Ҫ��srcͼ���ںϽ���, ����src�Ǹ�͸�������.
    */
    paint->setXfermodeMode(SkXfermode::kDstIn_Mode);
}

static void dump_layers(const char label[], SkCanvas* canvas) {
    SkDebugf("Dump Layers(%s)\n", label);

    SkCanvas::LayerIter iter(canvas, true);
    int index = 0;
    while (!iter.done()) {
        const SkBitmap& bm = iter.device()->accessBitmap(false);
        const SkIRect& clip = iter.clip().getBounds();
        SkDebugf("Layer[%d] bitmap [%d %d] X=%d Y=%d clip=[%d %d %d %d] alpha=%d\n", index++,
                 bm.width(), bm.height(), iter.x(), iter.y(),
                 clip.fLeft, clip.fTop, clip.fRight, clip.fBottom,
                 iter.paint().getAlpha());
        iter.next();
    }
}

// test drawing with strips of fading gradient above and below
static void test_fade(SkCanvas* canvas) {
    /*SkAutoCanvasRestore
      ������2��SkAutoCanvasRestore, 
      ��Ϊ����ᴴ������layer, ��û���ֶ�restore�ͷ�, 
      �������˳�����ʱ, ͨ��������SkAutoCanvasRestore�����������Զ�restore�ͷ�.
      
      ΪʲôҪ��SkAutoCanvasRestore?
      ��Ϊ savelayer�����⴦,         resotreֻ�ܻظ��� savelayerʱ��״̬,
      �ں�����ʼ��ʹ��SkAutoCanvasRestore, ����ʹ�ظ��� ��������ʱ��״̬, ����savelayerʱ�̵�״̬.--------�д���ȶ���һᾡ���һ�£�Ȼ���save��restore��������һ������--ţȺ
      ���ɾ������״̬.
    */
    SkAutoCanvasRestore ar(canvas, true);

    SkRect r;
    
    SkPaint p;
    p.setAlpha(0x88);

    SkAutoCanvasRestore(canvas, false);

    // create the layers
    r.set(0, 0, SkIntToScalar(100), SkIntToScalar(100));
    /*�ص�1 : ��������(��������) : ʹ�ɻ����������Ƴ�clipRect���õĴ�С.
      ȡ��clip����
      1. ������clipRect(r)
      2. canvas.restore()һ��, �ظ���֮ǰ��clip״̬
      3. ???????????????????�к���ֱ��ȡ������clipRect������?-------Ŀǰû�п���ȡ��clip�ĺ���������clipҲ��һ������Ӧ�ÿ��Զ�ȡ��֮ǰ��clip��С�����������á�restore�������ǿ��Խ�һ�����ݽ��лָ�����������clip���������ж��е��ֳ�������ָ�--ţȺ
    */
    canvas->clipRect(r);
    /*���� : ʵ��clip�Ĵ���.*/
    if(false) {
      SkRect r2;
      r2.set(0, 0, SkIntToScalar(200), SkIntToScalar(200));
      SkPaint p2;
      p2.setColor(SK_ColorBLUE);
      p2.setAntiAlias(true);
      canvas->drawOval(r2, p2);
    }

    //������1, �ϰ����
    r.fBottom = SkIntToScalar(20);
    r.fRight = SkIntToScalar(100);
    canvas->saveLayer(&r, NULL, (SkCanvas::SaveFlags)(SkCanvas::kHasAlphaLayer_SaveFlag | SkCanvas::kFullColorLayer_SaveFlag));

    //������2, �°����
    r.fTop = SkIntToScalar(80);
    r.fBottom = SkIntToScalar(100);
    canvas->saveLayer(&r, NULL, (SkCanvas::SaveFlags)(SkCanvas::kHasAlphaLayer_SaveFlag | SkCanvas::kFullColorLayer_SaveFlag));


    /*������������ :
      ǰ�� ����layer,     ����һ��͸��Բ
      ���� ֱ����canvase, ����һ����ɫԲ
    */
    if (false) {
        r.set(0, 0, SkIntToScalar(100), SkIntToScalar(100));
        canvas->saveLayerAlpha(&r, 0x80);

        SkPaint p;
        p.setColor(SK_ColorRED);
        p.setAntiAlias(true);
        canvas->drawOval(r, p);

        dump_layers("inside layer alpha", canvas);
        canvas->restore();
    } else {
        r.set(0, 0, SkIntToScalar(100), SkIntToScalar(100));
        
        SkPaint p;
        p.setColor(SK_ColorRED);
        p.setAntiAlias(true);
        canvas->drawOval(r, p);
    }
    
    dump_layers("outside layer alpha", canvas);

    //��������
    SkPaint paint;
    make_paint(&paint);
    r.set(0, 0, SkIntToScalar(100), SkIntToScalar(20));

//SkDebugf("--------- draw top grad\n");

    //���ϰ�Բ
    canvas->drawRect(r, paint);

    SkMatrix m;
    //�޸���Ӱ
    SkShader* s = paint.getShader();
    /*��(0��0) - (0�� 100)��Χ��, ��xΪ����ֱ��ת. 
     (���ͼΪ : ���ϵ��½������Ӱ, ��Ϊ�˴��µ��Ͻ������Ӱ)*/    //---������ܽ�����Ӱ����������
    m.setScale(SK_Scalar1, -SK_Scalar1);
    m.postTranslate(0, SkIntToScalar(100));
    s->setLocalMatrix(m);
    
    r.fTop = SkIntToScalar(80);
    r.fBottom = SkIntToScalar(100);
//  SkDebugf("--------- draw bot grad\n");
    //���°�Բ
    canvas->drawRect(r, paint);

    //�˳�����ʱ�Զ��ͷ�����restore�� ������saveLayer���Ƶ�canvas���γɽ��.
}

class RedFilter : public SkDrawFilter {
public:
    virtual bool filter(SkCanvas*, SkPaint* p, SkDrawFilter::Type) {
        fColor = p->getColor();
        if (fColor == SK_ColorRED) {
            p->setColor(SK_ColorGREEN);
        }
        return true;
    }
    virtual void restore(SkCanvas*, SkPaint* p, SkDrawFilter::Type) {
        p->setColor(fColor);
    }
    
private:
    SkColor fColor;
};

class LayersView : public SkView {
public:
	LayersView() {}

protected:
    // overrides from SkEventSink
    virtual bool onQuery(SkEvent* evt) {
        if (SampleCode::TitleQ(*evt)) {
            SampleCode::TitleR(evt, "Layers");
            return true;
        }
        return this->INHERITED::onQuery(evt);
    }
    
    void drawBG(SkCanvas* canvas) {
        canvas->drawColor(SK_ColorGRAY);
    }
    
    virtual void onDraw(SkCanvas* canvas) {
        /*������ɫ*/
        this->drawBG(canvas);
        
        /*��1 : ���ϻ��������ص���ͼ��, �����restoreʱһ����Ƶ�canvas��.*/
        if (false) {
            /*����A, ����һ�������*/
            SkRect r;
			      r.set(SkIntToScalar(0), SkIntToScalar(0),
				      SkIntToScalar(220), SkIntToScalar(120));
            SkPaint p;
            canvas->saveLayer(&r, &p);
            canvas->drawColor(0xFFFF0000);
            
            /*�ڲ�A��, ��XfermodeModeģʽ, ��һ������Բ*/
            p.setAlpha(100); 
            p.setColor(0xFF0000FF);
            //Xfermode������Ч��ͼ��:  http://blog.csdn.net/wylwhd/article/details/6180272 
            p.setXfermodeMode(SkXfermode::kSrc_Mode);
            canvas->drawOval(r, p);

            /*�ͷŲ�A : restore�Ὣ��A�ϵ�ͼ��, ����canvasΨһ��bitmap��, �Լ���������δ�ͷŵ�layer���ص��Ĳ��ֻ�������layer��canvas��.*/
            canvas->restore();
            return;
        }
        
        /*��2 : ���ϻ�һ��ͼ��, ��restoreʱ���Ƶ�canvas��, canvas�ٻ���һ�����ص���ͼ��*/
        if (false) {
            SkRect r;
			      r.set(SkIntToScalar(0), SkIntToScalar(0),
				      SkIntToScalar(220), SkIntToScalar(120));
            SkPaint p;
            p.setAlpha(0x88);
            p.setAntiAlias(true);
            
            if (true) {
                canvas->saveLayer(&r, &p);
                p.setColor(0xFFFF0000);
                canvas->drawOval(r, p);
                canvas->restore();
            }

            p.setColor(0xFF0000FF);
            r.offset(SkIntToScalar(20), SkIntToScalar(50));
            canvas->drawOval(r, p);
        }

        /*��3 : ����չʾ�� �� ����Ҫ��һ������:  
          ���ƹ��� : ����͸���� -> ������� �� ԭcanvas���� ��һ��Բ -> ������չʾ�˲������, canvas����չʾ��canvas������
          ���� : ��Ľ���, ֻ��ʹ������ ������Ը���,
        */
        if (false) {
            SkPaint p;
            p.setAlpha(0x44);
            p.setAntiAlias(true);

            canvas->translate(SkIntToScalar(300), 0);

            SkRect r;
			      r.set(SkIntToScalar(0), SkIntToScalar(0),
				          SkIntToScalar(220), SkIntToScalar(60));
   
            canvas->saveLayer(&r, &p, (SkCanvas::SaveFlags)(SkCanvas::kHasAlphaLayer_SaveFlag | SkCanvas::kFullColorLayer_SaveFlag));
//            canvas->clipRect(r, SkRegion::kDifference_Op);
//            canvas->clipRect(r, SkRegion::kIntersect_Op);
            //��Ӵ��� : ���Բ�ĸ���˳�� : �������������Բ, ��Ϊ��һ��������ͷ�ʱ, �ػ��Ĳ��ֵ�ס���������Բ
            if (true) {
              r.set(SkIntToScalar(0), SkIntToScalar(40),
                SkIntToScalar(220), SkIntToScalar(80));
              canvas->saveLayer(&r, &p);
              p.setColor(SK_ColorRED);
              canvas->drawOval(r, p);
              canvas->restore();
            }


			      r.set(SkIntToScalar(0), SkIntToScalar(0),
				          SkIntToScalar(220), SkIntToScalar(120));
            p.setColor(SK_ColorBLUE);
             canvas->drawOval(r, p);
            canvas->restore();
            return;
        }
        
        //canvas->translate(SkIntToScalar(20), SkIntToScalar(20));
        /*��4 : ��1��Բ, ���ò㽫���������ֱ�ɽ���ɫ.*/
         test_fade(canvas);
         return;
        //canvas->setDrawFilter(new RedFilter)->unref();
        
        /*��5 : canvas��һ��ɫ����-> ����, ��һ����Բ-> ���ý��� ���ϰ����Բ����͸�� -> �ͷŲ�*/
        SkRect  r;
        SkPaint p;
        
        canvas->translate(SkIntToScalar(220), SkIntToScalar(20));
        
        //��һ��������
        p.setAntiAlias(true);
        r.set(SkIntToScalar(20), SkIntToScalar(20),
              SkIntToScalar(220), SkIntToScalar(120));
        
        p.setColor(SK_ColorBLUE);
        //ģ�����˾�Ч��
        //p.setMaskFilter(SkBlurMaskFilter::Create(SkIntToScalar(8), SkBlurMaskFilter::kNormal_BlurStyle))->unref();
        canvas->drawRect(r, p);
        //û���˾�Ч��
        p.setMaskFilter(NULL);

        //ȡ��һ����ν�����
        SkRect bounds = r;
        bounds.fBottom = bounds.centerY();
        /*�ص�1 : ����ʵ��:
          ȥ��canvas->saveLayer(&bounds, NULL, SkCanvas::kARGB_NoClipLayer_SaveFlag);
          ȥ��canvas->restore();
          ����.
          ��ᷢ�� p.setAlpha(0x80)��͸��Ч��û��
                   p.setXfermodeMode(SkXfermode::kSrcIn_Mode)�ļ���Ч��û��.-------���������Ч��������������drawDevice���������paint��������й�--ţȺ
          ���� : Alpha, XfermodeMode��Ч��Ҫ����layerʹ��.
        */
        canvas->saveLayer(&bounds, NULL, SkCanvas::kARGB_NoClipLayer_SaveFlag);
        p.setColor(SK_ColorYELLOW);
        canvas->drawOval(r, p);

        p.setAlpha(0x00);
        p.setColor(SK_ColorRED);
        /*�ص�2 : p.setXfermodeMode(SkXfermode::kSrcIn_Mode)
                  ˭��src? ˭��dst?
          ���� :  -> saveLayer
                  ->canvas->drawOval(r, p);
                  -> p.setXfermodeMode(SkXfermode::kSrcIn_Mode) 
                  -> canvas->drawRect(bounds, p);
                  -> restore
                 ǰһ��draw��src, ��һ��draw��dst.
                 �����ڡ�һ�㡱��������һ������, �����γɼ���.  //------�����������������صĻ�����ԣ���֪�������ʲô��ϵ---ţȺ
          ע�� : 1. û�в㲻�ܼ���
                 2. ���˳����canvas->drawOval(r, p)���ڲ���ʱ, ���ܼ���, 
                     ������˳��canvas->drawOval(r, p)��Դcanvase��
                 ->canvas->drawOval(r, p);
                 -> saveLayer
                 -> p.setXfermodeMode(SkXfermode::kSrcIn_Mode) 
                 -> canvas->drawRect(bounds, p);
                 -> restore
        */
        p.setXfermodeMode(SkXfermode::kSrcIn_Mode);
        canvas->drawRect(bounds, p);

        canvas->restore();
    }
    
    virtual SkView::Click* onFindClickHandler(SkScalar x, SkScalar y) {
        this->inval(NULL);
        
        return this->INHERITED::onFindClickHandler(x, y);
    }
    
    virtual bool onClick(Click* click) {
        return this->INHERITED::onClick(click);
    }

	virtual bool handleKey(SkKey key) {
        this->inval(NULL);
        return true;
    }

private:
    typedef SkView INHERITED;
};

//////////////////////////////////////////////////////////////////////////////

static SkView* MyFactory() { return new LayersView; }
static SkViewRegister reg(MyFactory);

