#include "Graphics.h"
#include "SkCanvas.h"
Graphics::Graphics()
{
	m_pCanvas = new SkCanvas();
}
Graphics::~Graphics()
{
	if(m_pCanvas)
		delete m_pCanvas;
	m_pCanvas = NULL;
}
//��λͼͼ������ͼ����
//bitmap:����Ҫ��ʾ��λ��͸����͸��λͼͼ�� 
//matrix: һ�� matrix �������� flash.geom.Matrix �ࣩ��������ʹ������λͼ�϶���ת����
//���磬����ʹ�����¾���λͼ��ת 45 �ȣ�pi/4 ���ȣ��� matrix = new flash.geom.Matrix();matrix.rotate(Math.PI / 4);
//repeat: ���Ϊ true����λͼͼ��ƽ��ģʽ�ظ������Ϊ false��λͼͼ�񲻻��ظ���
//����λͼ��Ե������������չ��λͼ���������
//�� repeat ����Ϊ true ʱ����������ʾ����λͼ��佫�ظ�λͼ��
//repeat ����Ϊfalse ʱ��λͼ��佫��λͼ�ⲿ���������ʹ�ñ�Ե���أ�
//smooth:���Ϊ false����ʹ������ڵ��㷨�����ַŴ��λͼͼ�񣬶��Ҹ�ͼ�����������ػ��ġ�
//���Ϊ true����ʹ��˫�����㷨�����ַŴ��λͼͼ��ʹ������ڵ��㷨���ֽϿ졣 
void beginBitmapFill(const BitmapData &bitmap, const Matrix &matrix = null, Boolean repeat = true, Boolean smooth = false)
{
	
}

/*ָ��һ�ּ򵥵ĵ�һ��ɫ��䣬�ڻ���ʱ����佫����������Graphics �������� lineTo() �� drawCircle()���ĵ�����ʹ��
����佫������Ч��ֱ�������� beginFill()��beginBitmapFill()��beginGradientFill() �� beginShaderFill() ������
���� clear() �����������䡣
ֻҪ���� 3 ���������㣬���ߵ��� endFill() ����ʱ��Ӧ�ó���ͻ�������*/
//color:������ɫ (0xRRGGBB)��  
//alpha:���� Alpha ֵ���� 0.0 �� 1.0����  
void beginFill(const uint color, const Number alpha = 1.0);

/*ָ��һ�ֽ�����䣬���������ö�������� Graphics �������� lineTo() �� drawCircle()����
����佫������Ч��ֱ�������� beginFill()��beginBitmapFill()��beginGradientFill() �� beginShaderFill() ������
���� clear() �����������䡣 
ֻҪ���� 3 ���������㣬���ߵ��� endFill() ����ʱ��Ӧ�ó���ͻ������䡣*/
//type:����ָ��Ҫʹ�����ֽ������͵� GradientType ���ֵ��GradientType.LINEAR �� GradientType.RADIAL��  
//colors:������ʹ�õ� RGB ʮ��������ɫֵ�����飨���磬��ɫΪ 0xFF0000����ɫΪ 0x0000FF���ȵȣ�����������ָ�� 15 ����ɫ������ÿ����ɫ������ alphas �� ratios ������ָ����Ӧֵ��  
//alphas:colors �����ж�Ӧ��ɫ�� alpha ֵ���飻��ЧֵΪ 0 �� 1�����ֵС�� 0����Ĭ��ֵΪ 0�����ֵ���� 1����Ĭ��ֵΪ 1��  
//ratios:��ɫ�ֲ����ʵ����飻��ЧֵΪ 0 �� 255����ֵ���� 100% ��������ɫ����λ�õĿ�Ȱٷֱȡ�ֵ 0 ��ʾ������е����λ�ã�255 ��ʾ������е��Ҳ�λ�á�  
//matrix: һ���� flash.geom.Matrix �ඨ���ת������flash.geom.Matrix ����� createGradientBox() ������
//ͨ���÷������Է�������þ����Ա��� beginGradientFill() ����һ��ʹ�á�  
//spreadMethod:����ָ��Ҫʹ������ spread ������ SpreadMethod ���ֵ��
//SpreadMethod.PAD��SpreadMethod.REFLECT �� SpreadMethod.REPEAT��  
//interpolationMethod:String (default = "rgb") �� ����ָ��Ҫʹ���ĸ�ֵ�� InterpolationMethod ���ֵ��
//InterpolationMethod.LINEAR_RGB �� InterpolationMethod.RGB 
//focalPointRatio:һ�����ƽ���Ľ���λ�õ����֡�0 ��ʾ����λ�����ġ�1 ��ʾ����λ�ڽ���Բ��һ���߽��ϡ�
//-1 ��ʾ����λ�ڽ���Բ����һ���߽��ϡ�С�� -1 ����� 1 ��ֵ������Ϊ -1 �� 1�� 
void beginGradientFill(const String type, const vector<long> &colors, const vector<double> &alphas, const vector<short> &ratios, const Matrix matrix = null, 
	const String &spreadMethod = "pad", const String &interpolationMethod = "rgb", Number focalPointRatio = 0);

/*Ϊ����ָ����ɫ����䣬������������ Graphics �������� lineTo() �� drawCircle()��ʱʹ�á�
����佫������Ч��ֱ�������� beginFill()��beginBitmapFill()��beginGradientFill() �� beginShaderFill() ������
���� clear() �����������䡣 
ֻҪ���� 3 ���������㣬���ߵ��� endFill() ����ʱ��Ӧ�ó���ͻ������䡣*/
//shader:Ҫ����������ɫ������ Shader ʵ������ָ��ͼ�����롣���ǣ��������ɫ����ָ��ͼ�����룬������ֶ��ṩ���롣
//Ҫָ�����룬������ Shader.data ���ԵĶ�Ӧ ShaderInput ���Ե� input ���ԡ� 
//���� Shader ʵ����Ϊ����ʱ�������ڲ�������ɫ������ͼ��������ʹ�ø��ڲ������������Ƕ�ԭʼ��ɫ�������á�
//����ɫ�����е��κθ��ģ�������Ĳ���ֵ��������ֽڴ��룩����Ӧ���������Ƶ�����������ɫ����
//matrix:һ�� matrix �������� flash.geom.Matrix �ࣩ�������ڶ���ɫ������ת����
//���磬����ʹ�����¾�����ɫ����ת 45 �ȣ�pi/4 ���ȣ�: matrix = new flash.geom.Matrix(); matrix.rotate(Math.PI / 4);
//��ɫ�����յ����������Ϊ matrix ����ָ���ľ��󡣶���Ĭ�� (null) ������ɫ���е������ǿ����ڶ���������ľֲ��������ꡣ
void beginShaderFill(cosnt Shader &shader, cosnt Matrix &matrix = null);

//������Ƶ��� Graphics �����ͼ�Σ�����������������ʽ���á� 
void clear();
		
//��Դ Graphics �����е����л滭����Ƶ�ִ�е��õ� Graphics �����С� Graphics 
//sourceGraphics: ���и��ƻ滭����� Graphics ����
void	copyFrom(const Graphics &sourceGraphics);	

/*ͨ���� (controlX, controlY) ָ���Ŀ��Ƶ�,ʹ�õ�ǰ������ʽ����һ���ӵ�ǰ�滭λ�ÿ�ʼ�� (anchorX, anchorY) ���������ߡ�
��ǰ�滭λ���������Ϊ (anchorX, anchorY)������������л��Ƶ�ӰƬ���������� Flash �滭���ߴ��������ݣ�
����� curveTo() �������ڸ�����������л��ơ�����ڵ��� moveTo() ����֮ǰ������ curveTo() ������
��ǰ�滭λ�õ�Ĭ��ֵΪ (0, 0)�����ȱ���κ�һ����������˷�����ʧ�ܣ����ҵ�ǰ�滭λ�ò��ı䡣 
���Ƶ������Ƕ��α��������ߡ����α��������߰�������ê���һ�����Ƶ㡣�������ڲ�������ê�㣬������Ƶ������� */
// controlX:һ�����֣�ָ�����Ƶ�����ڸ���ʾ����ע����ˮƽλ�á�
// controlY:һ�����֣�ָ�����Ƶ�����ڸ���ʾ����ע���Ĵ�ֱλ�á�  
// anchorX:һ�����֣�ָ����һ��ê������ڸ���ʾ����ע����ˮƽλ�á�
// anchorY:һ�����֣�ָ����һ��ê������ڸ���ʾ����ע���Ĵ�ֱλ�á�  
void	curveTo(Number controlX, Number controlY, Number anchorX, Number anchorY);

/*����һ��Բ���ڵ��� drawCircle() ����֮ǰ��ͨ������ linestyle()��lineGradientStyle()��beginFill()��
beginGradientFill() �� beginBitmapFill() ����������������ʽ��/����䡣*/ 
// x:Բ������ڸ���ʾ����ע���� x λ�ã�������Ϊ��λ����  
// y:����ڸ���ʾ����ע����Բ�ĵ� y λ�ã�������Ϊ��λ����  
// radius:Բ�İ뾶��������Ϊ��λ����  
void	drawCircle(Number x, Number y, Number radius);
		
/*����һ����Բ���ڵ��� drawEllipse() ����֮ǰ��ͨ������ linestyle()��lineGradientStyle()��beginFill()��
beginGradientFill() �� beginBitmapFill() ����������������ʽ��/����䡣*/
// x:Number �� ��Բ�߿����Ͻ�����ڸ���ʾ����ע���� x λ�ã�������Ϊ��λ����  
// y:Number �� ��Բ�߿����Ͻ�����ڸ���ʾ����ע���� y λ�ã�������Ϊ��λ����  
// width:Number �� ��Բ�Ŀ�ȣ�������Ϊ��λ����  
// height:Number �� ��Բ�ĸ߶ȣ�������Ϊ��λ����  
void	drawEllipse(Number x, Number y, Number width, Number height);
		
/*�ύһϵ�� IGraphicsData ʵ�������л�ͼ���˷�������һ���������󣨰���·�������ͱʴ�����ʸ����
��Щ����ʵ�� IGraphicsData �ӿڡ����� IGraphicsData ʵ����ʸ������������״��һ���֣�
������һ����������ĸ��������Գ�����������״��
ͼ��·�����԰�������ͼ��·������� graphicsData ʸ������·�������ڴ˲����ڼ佫���ָ�·������������·���� */
//graphicsData:һ������ͼ�ζ����ʸ�������е�ÿ�����󶼱���ʵ�� IGraphicsData �ӿ�
void	drawGraphicsData(const vector<IGraphicsData> &graphicsData);
		
/*�ύһϵ�л������drawPath() ����ʹ��ʸ�������������� moveTo()��lineTo() �� curveTo() ��ͼ����뵽һ�������С�
drawPath() ������������ͼ������ x �� y ����ֵ���Լ���ͼ����ϲ���������ͼ����Ϊ GraphicsPathCommand ���е�ֵ��
x �� y ����ֵ���������е����֣����е�ÿ�����ֶ���һ������λ�á���ͼ����Ϊ GraphicsPathWinding ���е�ֵ�� 
ͨ������ʹ��һϵ�е��� lineTo() �� curveTo() ������ȣ�ʹ�� drawPath() ���ֻ�ͼ���ٶȻ���졣 
drawPath() ����ʹ�ø������㣬�����״����ת�����Ÿ�׼ȷ�����Ի�ø��õĽ�������ǣ�
ͨ��ʹ�� drawPath() �����ύ���������� lineTo() �� curveTo() �������ʹ��ʱ�����ܻ����С�������ض�����
drawPath() ������ʹ�����в�ͬ�Ĺ���������ͻ�����������Щ�����ǣ� 
��Ӧ������Գ���·��ʱ�� ���������� 3 �������·����������ע�⣬�ʴ������Խ���������������ıʴ�������һ�¡��� 
��ʽ�պ�δ�պϵ���·���������㲻���ڿ�ʼ�㣩�� 
��Ӧ�ñʴ��Գ���·��ʱ�� ��·���������κ������ĵ���ɡ� 	�Ӳ���ʽ�պ���·����*/ 
//commands: һ�����������ɵ�ʸ������ʾ�� GraphicsPathCommand �ඨ������
//GraphicsPathCommand �ཫ����ӳ�䵽��ʸ����������ֱ�ʶ����  
//data:һ�������ֹ��ɵ�ʸ�������е�ÿһ�����ֽ�����Ϊһ������λ�ã�һ�� x, y �ԣ���
//x �� y ����ֵ�Բ��� Point ����data ʸ����һϵ�����֣����е�ÿ�����������ֹ��ɵ����ʾһ������λ�á�  
//winding:ʹ�� GraphicsPathWinding ���ж����ֵָ�����ƹ���  
void	drawPath(const vector<int> &commands, const vector<Number> &data, const String &winding = "evenOdd");
		
/*����һ�����Ρ��ڵ��� drawRect() ����֮ǰ��ͨ������ linestyle()��lineGradientStyle()��beginFill()��
beginGradientFill() �� beginBitmapFill() ����������������ʽ��/����䡣 */
//x:Number �� һ����ʾ����ڸ���ʾ����ע����ˮƽλ�õ����֣�������Ϊ��λ����  
// y:Number �� һ����ʾ����ڸ���ʾ����ע���Ĵ�ֱλ�õ����֣�������Ϊ��λ����  
// width:Number �� ���εĿ�ȣ�������Ϊ��λ����  
// height:Number �� ���εĸ߶ȣ�������Ϊ��λ����  	
void	drawRect(Number x, Number y, Number width, Number height);
		
//����һ��Բ�Ǿ��Ρ��ڵ��� drawRoundRect() ����֮ǰ��ͨ������ linestyle()��lineGradientStyle()��beginFill()��
//beginGradientFill() �� beginBitmapFill() ����������������ʽ��/����䡣 
// x:Number �� һ����ʾ����ڸ���ʾ����ע����ˮƽλ�õ����֣�������Ϊ��λ����
// y:Number �� һ����ʾ����ڸ���ʾ����ע���Ĵ�ֱλ�õ����֣�������Ϊ��λ����  
// width:Number �� Բ�Ǿ��εĿ�ȣ�������Ϊ��λ����  
// height:Number �� Բ�Ǿ��εĸ߶ȣ�������Ϊ��λ����  
// ellipseWidth:Number �� ���ڻ���Բ�ǵ���Բ�Ŀ�ȣ�������Ϊ��λ����  
// ellipseHeight:Number (default = NaN) �� ���ڻ���Բ�ǵ���Բ�ĸ߶ȣ�������Ϊ��λ����
//����ѡ�����δָ��ֵ����Ĭ��ֵ��Ϊ ellipseWidth �����ṩ��ֵ��ƥ�䡣  
void drawRoundRect(Number x, Number y, Number width, Number height, 
Number ellipseWidth, Number ellipseHeight = NaN);
		
/*����һ�������Σ�ͨ������Ť��λͼ������Ϊ��ָ����ά��ۡ�
drawTriangles() ����ʹ��һ�� (u,v) ���꽫��ǰ����λͼ���ӳ�䵽�������档 
����ʹ���κ����͵���䣬����������ת�������򽫺��Ը�ת������ 
��ʹ��λͼ���ʱ��uvtData �����ɸ�������ӳ�䡣 */
// vertices:һ�������ֹ��ɵ�ʸ�������е�ÿһ�����ֽ�����Ϊһ������λ�ã�һ�� x, y �ԣ��� vertices �����Ǳ���ġ�
// indices: һ�����������������ɵ�ʸ��������ÿ������������һ�������Ρ���� indexes ����Ϊ null��
// ��ÿ�������㣨vertices ʸ���е� 6 �� x,y������һ�������Ρ�����ÿ������������һ�����㣬
// �� vertices ʸ���е�һ�����֡����磬indexes[1] ���� (vertices[2], vertices[3])��indexes �����ǿ�ѡ�ģ�
// �� indexes ͨ��������ύ���������ͼ������������  
// uvtData:������Ӧ������ӳ��ı�׼���깹�ɵ�ʸ����ÿ������������������λͼ�ϵ�һ���㡣
// ÿ������������һ�� UV ��һ�� UVT ���ꡣ���� UV ���꣬(0,0) ��λͼ�����Ͻǣ�(1,1) ��λͼ�����½ǡ� 
// �����ʸ���ĳ����� vertices ʸ�����ȵ���������ʹ�ñ�׼�����������͸��У���� 
// �����ʸ���ĳ����� vertices ʸ�����ȵ��������򽫵������������Ϊ��t���������ӽǿռ��д��ӵ㵽����ľ��룩��
// �������ڳ�����������ά��ӳ������ʱ��ȷӦ��͸�ӡ�
// ��� uvtData ����Ϊ null����Ӧ����ͨ�����򣨺��κ�������ͣ���
// culling:ָ���Ƿ��������ָ������������Ρ��˲����ɷ�ֹ�����ڵ�ǰ��ͼ�п������������Ρ�
// �˲���������Ϊ�� TriangleCulling �ඨ����κ�ֵ��  
void drawTriangles(const vector<Number> &vertices, const vector<int> &indices = null, const vector<Number> &uvtData = null, 
const String &culling = "none");
		
/*�Դ���һ�ε��� beginFill()��beginGradientFill() �� beginBitmapFill() ����֮����ӵ�ֱ�ߺ�����Ӧ����䡣
Flash ʹ�õ��Ƕ� beginFill()��beginGradientFill() �� beginBitmapFill() ��������ǰ������ָ������䡣
�����ǰ�滭λ�ò����� moveTo() ������ָ������һ��λ�ã����Ҷ�������䣬���������պϸ�·����Ȼ�������䡣*/ 
void endFill();
		
/*ָ��һ��λͼ�����ڻ�������ʱ�������ʴ��� 
λͼ������ʽ���������� lineTo() �� drawCircle() �� Graphics �����ĵ��á�
������ʽ��Ȼ��Ч��ֱ����ʹ�ò�ͬ�Ĳ������� lineStyle() �� lineGradientStyle() �������ٴε��� lineBitmapStyle() ������ 
�����ڻ���·�����м���� lineBitmapStyle() ������Ϊ·���еĲ�ͬ�߶�ָ����ͬ����ʽ�� 
���ڵ��� lineBitmapStyle() ����֮ǰ���� lineStyle() ���������ñʴ�������������ʽ��ֵ��Ϊ undefined��
���� clear() �����Ὣ������ʽ���û� undefined��*/ 
//bitmap ���������ʴ���λͼ��  
// matrix: һ���� flash.geom.Matrix �ඨ��Ŀ�ѡת������
//�þ���������ڽ�λͼӦ����������ʽ֮ǰ����λͼ����������ʽ����λͼ�� 
// repeat: �Ƿ���ƽ�̷�ʽ�ظ�λͼ��  
// smooth:�Ƿ�Ӧ��λͼӦ��ƽ������   	
void	lineBitmapStyle(const BitmapData &bitmap, const Matrix *matrix = null, Boolean repeat = true, Boolean smooth = false);
		

/*ָ��һ�ֽ��䣬���ڻ�������ʱ�ıʴ��� 
����������ʽ���������� lineTo() �� drawCircle() �� Graphics �����ĵ��á�������ʽ��Ȼ��Ч��
ֱ����ʹ�ò�ͬ�Ĳ������� lineStyle() �� lineBitmapStyle() �������ٴε��� lineGradientStyle() ������ 
�����ڻ���·�����м���� lineGradientStyle() ������Ϊ·���еĲ�ͬ�߶�ָ����ͬ����ʽ�� 
���ڵ��� lineGradientStyle() ����֮ǰ���� lineStyle() ���������ñʴ�������������ʽ��ֵ��Ϊ undefined��
���� clear() �����Ὣ������ʽ���û� undefined�� */
// type:String �� ����ָ��Ҫʹ�����ֽ������͵� GradientType ���ֵ��GradientType.LINEAR �� GradientType.RADIAL��  
// colors:Array �� Ҫ�ڽ�����ʹ�õ� RGB ʮ��������ɫֵ���飨���磬��ɫΪ 0xFF0000����ɫΪ 0x0000FF �ȵȣ���  
// alphascolors �����ж�Ӧ��ɫ�� alpha ֵ����;��ЧֵΪ 0 �� 1�����ֵС�� 0,��Ĭ��ֵΪ 0�����ֵ���� 1,��Ĭ��ֵΪ 1��  
// ratios:��ɫ�ֲ����ʵ�����;��ЧֵΪ 0 �� 255����ֵ���� 100% ��������ɫ����λ�õĿ�Ȱٷֱȡ�
// ֵ 0 ��ʾ������е����λ�ã�255 ��ʾ������е��Ҳ�λ�á���ֵ��ʾ������е�λ�ã����������ս��������ռ䣬
// ���ս�����ܻ�Ƚ���������խ��Ϊ colors �����е�ÿ��ֵָ��һ��ֵ��  
// matrix:һ���� flash.geom.Matrix �ඨ���ת������flash.geom.Matrix ����� createGradientBox() ������
// ͨ���÷������Է�������þ����Ա��� lineGradientStyle() ����һ��ʹ�á�  
// spreadMethod:String (default = "pad") �� ����ָ��Ҫʹ������ spread ������ SpreadMethod ���ֵ��  
// interpolationMethod:String (default = "rgb") �� InterpolationMethod ��������ָ��Ҫʹ�õ�ֵ��ֵ��
// focalPointRatio:Number (default = 0) �� һ�����ƽ���Ľ���λ�õ����֡�ֵ 0 ��ʾ����λ�����ġ�
// ֵ 1 ��ʾ����λ�ڽ���Բ��һ���߽��ϡ�ֵ -1 ��ʾ����λ�ڽ���Բ����һ���߽��ϡ�С�� -1 ����� 1 ��ֵ������Ϊ -1 �� 1��
void lineGradientStyle(const String &type, const Array &colors, Array alphas, Array ratios, const Matrix matrix = null, 
String spreadMethod = "pad", String interpolationMethod = "rgb", Number focalPointRatio = 0);
		

/*ָ��һ����ɫ�������ڻ�������ʱ�������ʴ��� 
��ɫ��������ʽ���������� lineTo() �� drawCircle() �� Graphics �����ĵ��á�������ʽ��Ȼ��Ч��
ֱ����ʹ�ò�ͬ�Ĳ������� lineStyle() �� lineGradientStyle() �������ٴε��� lineBitmapStyle() ������ 
�����ڻ���·�����м���� lineShaderStyle() �������Ա�Ϊ·���еĲ�ͬ�߶�ָ����ͬ����ʽ�� 
���ڵ��� lineShaderStyle() ����֮ǰ���� lineStyle() ���������ñʴ�������������ʽ��ֵ��Ϊ undefined��
���� clear() �����Ὣ������ʽ���û� undefined��*/ 
// shader:Shader �� ���������ʴ�����ɫ����  
// matrix:Matrix (default = null) �� һ���� flash.geom.Matrix �ඨ��Ŀ�ѡת������
// �þ���������ڽ�λͼӦ����������ʽ֮ǰ����λͼ����������ʽ����λͼ��  	
void	lineShaderStyle(Shader shader, Matrix matrix = null);
		

/*ָ��һ��������ʽ���������� lineTo() �� drawCircle() �� Graphics �����ĵ��á�
������ʽ��Ȼ��Ч��ֱ����ʹ�ò�ͬ�Ĳ������� lineGradientStyle() ������lineBitmapStyle() ������ lineStyle() ������ 
�����ڻ���·�����м���� lineStyle() ������Ϊ·���еĲ�ͬ�߶�ָ����ͬ����ʽ��
ע�⣺���� clear() �����Ὣ������ʽ���û� undefined��*/
// thickness:һ���������԰�Ϊ��λ��ʾ�����Ĵ�ϸ����ЧֵΪ 0 �� 255�����δָ�����֣�����δ����ò������򲻻���������
// ������ݵ�ֵС�� 0����Ĭ��ֵΪ 0��ֵ 0 ��ʾ��ϸ�Ĵ�ϸ������ϸΪ 255��������ݵ�ֵ���� 255����Ĭ��ֵΪ 255��  
// color:uint (default = 0) �� ������ʮ��������ɫֵ�����磬��ɫΪ 0xFF0000����ɫΪ 0x0000FF �ȣ���
// ���δָ��ֵ����Ĭ��ֵΪ 0x000000����ɫ������ѡ��  
// alpha:Number (default = 1.0) �� ��ʾ������ɫ�� Alpha ֵ�����֣���ЧֵΪ 0 �� 1�����δָ��ֵ����Ĭ��ֵΪ 1����ɫ����
// ���ֵС�� 0����Ĭ��ֵΪ 0�����ֵ���� 1����Ĭ��ֵΪ 1��  
// pixelHinting:Boolean (default = false) �� ����ָ���Ƿ���ʾ�ʴ������������صĲ���ֵ��
// ��ͬʱӰ������ê���λ���Լ������ʴ���С������ pixelHinting ����Ϊ true ������£�������Ȼ�������������ؿ�ȡ�
// �� pixelHinting ����Ϊ false ������£��������ߺ�ֱ�߿��ܻ�����ѽ�.
// ���δ�ṩֵ����������ʹ��������ʾ��
// scaleMode:String (default = "normal") �� ����ָ��Ҫʹ����������ģʽ�� LineScaleMode ���ֵ�� 
// LineScaleMode.NORMAL - �����Ŷ���ʱ�������������Ĵ�ϸ��Ĭ��ֵ���� 
// LineScaleMode.NONE - �Ӳ�����������ϸ�� 
// LineScaleMode.VERTICAL - ����� ��ֱ���Ŷ���������������ϸ��
// LineScaleMode.HORIZONTAL - ����� ˮƽ���Ŷ���������������ϸ��
// caps:String (default = null) �� ����ָ������ĩ�˴��˵����͵� CapsStyle ���ֵ��
// ��ЧֵΪ��CapsStyle.NONE��CapsStyle.ROUND �� CapsStyle.SQUARE�����δָʾֵ���� Flash ʹ��Բͷ�˵㡣  
// joints:String (default = null) �� JointStyle ���ֵ��ָ�����ڹսǵ�������۵����͡�
// ��ЧֵΪ��JointStyle.BEVEL��JointStyle.MITER �� JointStyle.ROUND�����δָʾֵ���� Flash ʹ��Բ�����ӡ� 
// miterLimit:Number (default = 3) �� һ����ʾ�����ĸ�����λ���жϼ�ǵ����֡�
// ��Чֵ�ķ�Χ�� 1 �� 255�������÷�Χ��ֵ������Ϊ 1 �� 255������ֵֻ������ jointStyle ����Ϊ "miter" ������¡�
// miterLimit ֵ��ʾ��������ļ�ǿ��Գ����Ǳ��ཻ���γɵĽ�ϵ�ĳ��ȡ���ֵ��ʾΪ���� thickness �����ӡ�
void lineStyle(Number thickness = NaN, uint color = 0, Number alpha = 1.0, Boolean pixelHinting = false, 
String scaleMode = "normal", String caps = null, String joints = null, Number miterLimit = 3);
		
/*ʹ�õ�ǰ������ʽ����һ���ӵ�ǰ�滭λ�ÿ�ʼ�� (x, y) ������ֱ�ߣ���ǰ�滭λ����������Ϊ (x, y)��
����������л��Ƶ���ʾ��������� Flash �滭���ߴ��������ݣ������ lineTo() �������ڸ�����������л��ơ�
����ڶ� moveTo() ���������κε���֮ǰ������ lineTo()����ǰ�滭��Ĭ��λ��Ϊ (0, 0)�����ȱ���κ�һ��������
��˷�����ʧ�ܣ����ҵ�ǰ�滭λ�ò��ı䡣*/ 
// x:Number �� һ����ʾ����ڸ���ʾ����ע����ˮƽλ�õ����֣�������Ϊ��λ����  
// y:Number �� һ����ʾ����ڸ���ʾ����ע���Ĵ�ֱλ�õ����֣�������Ϊ��λ����  
void	lineTo(Number x, Number y);
		
// ����ǰ�滭λ���ƶ��� (x, y)�����ȱ���κ�һ����������˷�����ʧ�ܣ����ҵ�ǰ�滭λ�ò��ı䡣 
// x:Number �� һ����ʾ����ڸ���ʾ����ע����ˮƽλ�õ����֣�������Ϊ��λ����  
// y:Number �� һ����ʾ����ڸ���ʾ����ע���Ĵ�ֱλ�õ����֣�������Ϊ��λ����  
void	moveTo(Number x, Number y);