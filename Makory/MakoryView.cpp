
// MakoryView.cpp : CMakoryView Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
#ifndef SHARED_HANDLERS
#include "Makory.h"
#endif

#include "MakoryDoc.h"
#include "MakoryView.h"

using namespace std;
using namespace cv;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

static const UINT TIMER_ID_ANIMATION = 1000;

IMPLEMENT_DYNCREATE(CMakoryView, CView)

	BEGIN_MESSAGE_MAP(CMakoryView, CView)
		// ǥ�� �μ� ����Դϴ�.
		ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
		ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
		ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CMakoryView::OnFilePrintPreview)
		ON_WM_CONTEXTMENU()
		ON_WM_RBUTTONUP()
		ON_WM_CREATE()
		ON_WM_DESTROY()
		ON_WM_SIZE()
		ON_WM_ERASEBKGND()
		//ON_WM_KEYDOWN()
		ON_WM_TIMER()
	END_MESSAGE_MAP()

	// CMakoryView ����/�Ҹ�

	CMakoryView::CMakoryView()
	{
		// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.
		pos[0]=0.f;
		pos[1]=0.f;
		pos[2]=3.f;

		lookAt[0]=0.f;
		lookAt[1]=0.f;
		lookAt[2]=0.f;

		upVec[0]=0.f;
		upVec[1]=1.f;
		upVec[2]=0.f;

		SelectTemplate=0;
		IsItKey=0;
	}

	CMakoryView::~CMakoryView()
	{
	}


	BOOL CMakoryView::PreCreateWindow(CREATESTRUCT& cs)
	{
		// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
		//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

		return CView::PreCreateWindow(cs);
	}

	// CMakoryView �׸���

	void CMakoryView::OnDraw(CDC* /*pDC*/)
	{
		//SelectTemplate=ImageTimeline->NonTitle;
		CMakoryDoc* pDoc = GetDocument();
		ASSERT_VALID(pDoc);
		if (!pDoc)
			return;

		// TODO: ���⿡ ���� �����Ϳ� ���� �׸��� �ڵ带 �߰��մϴ�.

		if(SelectTemplate<=0) {
			DrawGLTitle(SelectTemplate);		//ó�� ����� Ÿ��Ʋ �̹��� ������
		} else {
			DrawGLScene(SelectTemplate);		//���ý� ���ø� ������
		}
	}


	// CMakoryView �μ�


	void CMakoryView::OnFilePrintPreview()
	{
#ifndef SHARED_HANDLERS
		AFXPrintPreview(this);
#endif
	}

	BOOL CMakoryView::OnPreparePrinting(CPrintInfo* pInfo)
	{
		// �⺻���� �غ�
		return DoPreparePrinting(pInfo);
	}

	void CMakoryView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
	{
		// TODO: �μ��ϱ� ���� �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
	}

	void CMakoryView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
	{
		// TODO: �μ� �� ���� �۾��� �߰��մϴ�.
	}

	void CMakoryView::OnRButtonUp(UINT /* nFlags */, CPoint point)
	{
		ClientToScreen(&point);
		OnContextMenu(this, point);
	}

	void CMakoryView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
	{
#ifndef SHARED_HANDLERS
		theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
	}


	// CMakoryView ����

#ifdef _DEBUG
	void CMakoryView::AssertValid() const
	{
		CView::AssertValid();
	}

	void CMakoryView::Dump(CDumpContext& dc) const
	{
		CView::Dump(dc);
	}

	CMakoryDoc* CMakoryView::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
	{
		ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMakoryDoc)));
		return (CMakoryDoc*)m_pDocument;
	}
#endif //_DEBUG


	// CMakoryView �޽��� ó����

	BOOL CMakoryView::SetPixelformat(HDC hdc) 
	{
		int pixelformat;

		PIXELFORMATDESCRIPTOR pfd = { 
			sizeof(PIXELFORMATDESCRIPTOR), // size of this pfd 
			1, // default version
			PFD_DRAW_TO_WINDOW | // support window 
			PFD_SUPPORT_OPENGL | // support OpenGL 
			PFD_GENERIC_FORMAT |
			PFD_DOUBLEBUFFER, // double buffered 
			PFD_TYPE_RGBA, // RGBA type 
			32, // 32-bit color depth 
			0, 0, 0, 0, 0, 0, // color bits ignored 
			8, // no alpha buffer 
			0, // shift bit ignored 
			8, // no accumulation buffer 
			0, 0, 0, 0, // accum bits ignored 
			16, // 16-bit z-buffer
			0, // no stencil buffer 
			0, // no auxiliary buffer 
			PFD_MAIN_PLANE, // main layer 
			0, // reserved 
			0, 0, 0 // layer masks ignored 
		}; 

		// choose best matching pixel format

		if ( (pixelformat = ChoosePixelFormat(hdc, &pfd)) == FALSE ) { 
			//MessageBox( "ChoosePixelFormat failed", "Error", MB_OK); 
			return FALSE; 
		} 



		// set pixel format to device context

		if (SetPixelFormat(hdc, pixelformat, &pfd) == FALSE) { 
			//MessageBox( "SetPixelFormat failed", "Error", MB_OK); 
			return FALSE;
		} 
		return TRUE; 
	}

	void CMakoryView::InitGL() 
	{

		glClearColor(0.0f, 0.0f, 0.0f, 0.5f);
		glClearDepth(1.0f);
		glEnable(GL_DEPTH_TEST);
		glDepthFunc(GL_LEQUAL);
		glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

		glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB); // ���� ���۸�
	}

	void CMakoryView::ReSizeGLScene(GLsizei width, GLsizei height) 
	{
		// don't want a divede by zero
		if (height==0) {
			height=1;
		}
		// reset the viewport to new dimensions
		glViewport(0,0,width,height);
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();

		// calculate aspect ratio of the window
		gluPerspective(45.0f,(GLfloat)width/(GLfloat)height,0.1f,1000.0f);

		// set modelvew matrix
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
	}


	void CMakoryView::DrawGLTitle(int SelectTemplate) 
	{
		//--------------------OpenCV---------------------
		int _width = 400;
		int _height = 400;
		long count = 0;
		unsigned long lImageSize = _width*3*_height; // RGB �����͸� ������ �޸� ũ��

		char* window_name = "OpenGL to OpenCV";
		glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); // �̱� ���۸�
		//glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB); // ���� ���۸�
		glutInitWindowSize(400, 400);  // â ũ�� ����
		glutInitWindowPosition(0, 0);
		IplImage *img = cvCreateImage (cvSize(_width, _height), IPL_DEPTH_8U, 3); // RGB ��������
		//glutCreateWindow("OpenGL");
		// clear screen and depth buffer
		//--------------------------------------------------

		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glLoadIdentity();

		// camera view configuration 
		//gluLookAt(0.f, 0.f, 3.f, 0.f, 0.f, 0.f, 0.f, 1.f, 0.f);
		//gluLookAt(pos[0],pos[1],pos[2],lookAt[0],lookAt[1],lookAt[2],upVec[0],upVec[1],upVec[2]);

		// draw 
		if(SelectTemplate==0){
			BmpToArray.LoadBmp("space/Title_Image.bmp");
		} else if(SelectTemplate==-1){
			BmpToArray.LoadBmp("space/NoTemplete.bmp");
		}

		glEnable(GL_TEXTURE_2D);
		glMatrixMode(GL_MODELVIEW);
		glPushMatrix();
		glDisable(GL_DEPTH_TEST);
		// Skybox�� �ٸ� ������ ������ ������ �ȵǹǷ� DECAL
		glTexEnvf(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_DECAL);
		glColor3f(0,0,0);


		//front
		glBegin(GL_QUADS);
		glTexCoord2f(1.0, 1.0); glVertex3f(-0.3,-0.2,-0.48);
		glTexCoord2f(0.0, 1.0); glVertex3f(0.3,-0.2,-0.48);
		glTexCoord2f(0.0, 0.0); glVertex3f(0.3,0.2,-0.48);
		glTexCoord2f(1.0, 0.0); glVertex3f(-0.3,0.2,-0.48);
		glEnd();

		glEnable(GL_DEPTH_TEST);
		glPopMatrix();

		glDisable(GL_TEXTURE_2D);
		//HotAirBalloon->drawSkyboxfront();

		//glFinish(); // �̱� ���� or ���� ���۸� ����ϴ� ��� ��� glReadPixels() �Լ� ���� ���
		SwapBuffers(m_hDC);   

		//glReadPixels (0, 0, _width, _height, GL_BGR_EXT, GL_UNSIGNED_BYTE, img->imageData);
		//cvShowImage (window_name, img);

		//waitKey(0);


		//cvReleaseImage (&img);
		//cvDestroyWindow(window_name);


	}

	void CMakoryView::StartAnimation()
	{
		Initialization();
		SetTimer(TIMER_ID_ANIMATION, 100/*in milisecond*/, nullptr);

		Invalidate(FALSE);
	}
	void CMakoryView::BallonStartAnimation()
	{
		BallonInitialization();
		SetTimer(TIMER_ID_ANIMATION, 100/*in milisecond*/, nullptr);

		Invalidate(FALSE);
	}

	void CMakoryView::OnTimer(UINT_PTR nIDEvent)
	{
		if (TIMER_ID_ANIMATION == nIDEvent)
		{
			if (0 == SelectTemplate)
			{
				KillTimer(TIMER_ID_ANIMATION);
			}
			else
			{
				DrawGLScene(SelectTemplate) ;
			}
		}
		else
		{
			CView::OnTimer(nIDEvent);
		}
	}

	void CMakoryView::BalloonAnimation()
	{
			if(lookAt[1]<-30 && pos[1]<-30) {
				KillTimer(TIMER_ID_ANIMATION);
				if(IsItKey==1) {
				BallonInitialization();
					ImageTimeline->OnAnimationFinished();
				}
			}
		else if (y>=45) {
			y+=0.2;	
			if(pos[1] > lookAt[1]) {
				pos[1]-=1.0;
				lookAt[1]-=1.01;
			}else {
				pos[1]-=1.0;
				lookAt[1]=pos[1];

			}

		}else if(y>=40){
			y+=0.2;	
			pos[1]-=0.5;
			lookAt[1]-=0.49;	
		}else if (y>=37){
			y+=0.25;	
			pos[1]+=0.2;
			lookAt[1]+=0.21;	
		} else if (y>=-12){
			y+=0.2;	
			if(pos[1]<=lookAt[1])
			{
				pos[1]+=0.2;
				lookAt[1]+=0.20;
			} else {
				pos[1]+=0.2;
				lookAt[1]+=0.21;	
			}
		}else {
			y+=0.25;	 
			pos[1]+=0.2;
			lookAt[1]+=0.19;	
		}

		Invalidate(FALSE);

			if(SelectTemplate == 1){
			HotAirBalloon.HotBalloonLine(0,y,0);
			HotAirBalloon.HotBalloonSphere(0,y,0);
			BmpToArray.LoadBmp(SelectImage);
			HotAirBalloon.HotBalloonTexture(0,y,0);
		}
		if(SelectTemplate == 2){
			HotAirBalloon.DarkHotBalloonLine(0,y,0);
			HotAirBalloon.DarkHotBalloonSphere(0,y,0);
			BmpToArray.LoadBmp(SelectImage);
			HotAirBalloon.DarkHotBalloonTexture(0,y,0);
		}

		if(SelectTemplate == 3){
			HotAirBalloon.FullHotBalloonLine(0,y,0);
			HotAirBalloon.FullHotBalloonSphere(0,y,0);
			BmpToArray.LoadBmp(SelectImage);
			HotAirBalloon.FullHotBalloonTexture(0,y,0);
		}

		if(SelectTemplate == 4){
			HotAirBalloon.MountHotBalloonLine(0,y,0);
			HotAirBalloon.MountHotBalloonSphere(0,y,0);
			BmpToArray.LoadBmp(SelectImage);
			HotAirBalloon.MountHotBalloonTexture(0,y,0);
		}

		if(SelectTemplate == 5){
			HotAirBalloon.SunsetHotBalloonLine(0,y,0);
			HotAirBalloon.SunsetHotBalloonSphere(0,y,0);
			BmpToArray.LoadBmp(SelectImage);
			HotAirBalloon.SunsetHotBalloonTexture(0,y,0);
		}

		if(SelectTemplate == 6){
			HotAirBalloon.CloudsHotBalloonLine(0,y,0);
			HotAirBalloon.CloudsHotBalloonSphere(0,y,0);
			BmpToArray.LoadBmp(SelectImage);
			HotAirBalloon.CloudsHotBalloonTexture(0,y,0);
		}
		if(SelectTemplate == 7){
			HotAirBalloon.TropicalHotBalloonLine(0,y,0);
			HotAirBalloon.TropicalHotBalloonSphere(0,y,0);
			BmpToArray.LoadBmp(SelectImage);
			HotAirBalloon.TropicalHotBalloonTexture(0,y,0);
		}


	}




	void CMakoryView::ProjectorAnimation()
	{ 
		//����� �ִ�
		if(x>=10) {
			KillTimer(TIMER_ID_ANIMATION);
			if(IsItKey==1) {
				ImageTimeline->OnAnimationFinished();
			}
			} else if (x>=7){
				x=-0.4;
				y=-0.5;
			} else if (x>=3){
				x=-0.4;
				y=-0.5;
			}
			  else {
				x=-0.4;
				y=-0.5;
			}
			  
		Invalidate(FALSE);

			Film.ProjectorBody(x,y,1,1,1);
			Film.ProjectorCircle1(x,y);
			Film.ProjectorCircle2(x,y);
	}

	void CMakoryView::FilmAnimation()
	{
		//�ʸ� �ִ�
		if(x<=-1) {
			KillTimer(TIMER_ID_ANIMATION);
			if(IsItKey==1) {
				ImageTimeline->OnAnimationFinished();
			}
		}else {
			x-=0.006;
			y=-0.5;
		}


		Invalidate(FALSE);

		Film.FilmBody(x,y);
		BmpToArray.LoadBmp(SelectImage);
		Film.FilmCenter2(x,y,0,0,0);//����ڰ� ��������
	}

	void CMakoryView::SlateAnimation()
	{
		//������Ʈ �ִ�
		if(x>=10) {
			KillTimer(TIMER_ID_ANIMATION);
			if(IsItKey==1) {
				ImageTimeline->OnAnimationFinished();
			}
		} else if (x>=7){
			x=-0.4;
			y=-0.5;
		} else if (x>=3){
			x=-0.4;
			y=-0.5;
		}
		else {
			x=-0.4;
			y=-0.5;
		}

		Invalidate(FALSE);

		Film.SlateHead(x,y);
		Film.SlateBody(x,y);

	}

	void CMakoryView::WaveAnimation()
	{
		//�ĵ� �ִ�
	}

	void CMakoryView::OceanAnimation()
	{			
			if(x>=10) {
			KillTimer(TIMER_ID_ANIMATION);
			if(IsItKey==1) {
				ImageTimeline->OnAnimationFinished();
			}
			} else if (x>=7){
				x+=0.005;	
			} else if (x>=3){
				x+=0.005;	
			}else {
				x+=0.005;	 
			}
			
		Invalidate(FALSE);

			Ocean.wave1(0,1.5,0,1,0,1);//����
			Ocean.wave2(0,1.5,0,1,0,1);//����

			Ocean.wave3(0,1.5,0,0,0,1);//����
			Ocean.wave4(0,1.5,0,0,0,1);//����

			Ocean.wave5(0,1.5,0,0,1,0);//����
			Ocean.wave6(0,1.5,0,0,1,0);//����

			
			
			Ocean.Fish3(-2,-1,0,0,0,0);//����� 2
			Ocean.Fish2(-2,-1,0,0,0,0);//����� 1
			Ocean.Fish1(0,-1,0,0,0);//����
			Ocean.eyesR(0,-1);//���� ��
			Ocean.eyesL(0,-1);//���� ��
			Ocean.eyes(-2,-1);//����� 1 ��
			Ocean.eyes2(-2,-1);//����� 2 ��
			Ocean.OceanTexture(1.5,-1);//�ؽ���


	}

	void CMakoryView::FishingAnimation()
	{
		//���� �ִ�
		if(x>=10) {
			KillTimer(TIMER_ID_ANIMATION);
			if(IsItKey==1) {
				ImageTimeline->OnAnimationFinished();
			}
		} else if (x>=5){
			x+=0;	
			pos[0]+=0;
			lookAt[0]+=0;
		} 
		else {
			x+=0.005;	 
			pos[0]-=0.005;
			lookAt[0]-=0.005;
		}

		Invalidate(FALSE);

		Ocean.Ship(0,0,1,1,0);//��
		Ocean.FishingTexture(0,0);
	}

	void CMakoryView::DrawGLScene(int SelectTemplete) 
	{
		//--------------------OpenCV---------------------
		int _width = 400;
		int _height = 400;
		long count = 0;
		unsigned long lImageSize = _width*3*_height; // RGB �����͸� ������ �޸� ũ��

		char* window_name = "OpenGL to OpenCV";
		//glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); // �̱� ���۸�

		//glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB); // ���� ���۸�
		//glutInitWindowSize(400, 400);  // â ũ�� ����
		//glutInitWindowPosition(0, 0);

		//IplImage *img = cvCreateImage (cvSize(_width, _height), IPL_DEPTH_8U, 3); // RGB ��������
		//glutCreateWindow("OpenGL");
		// clear screen and depth buffer
		//--------------------------------------------------

		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glLoadIdentity();

		// camera view configuration 
		//gluLookAt(0.f, 0.f, 3.f, 0.f, 0.f, 0.f, 0.f, 1.f, 0.f);
		gluLookAt(pos[0],pos[1],pos[2],lookAt[0],lookAt[1],lookAt[2],upVec[0],upVec[1],upVec[2]);

		// draw 


		//���ⱸ

		/*--------�ϴ� ���� ��ȣ------------
		CloudyLightRays : 1
		DarkStormy : 2
		FullMoon : 3
		Mountain : 4
		CloudyLightRays : 5
		ThickCloudsWater : 6
		TropicalSunnyDay : 7
		------------------------------------*/
		if(SelectTemplete==1) {
			BmpToArray.LoadBmp("space/CloudyLightRays/front.bmp");
			HotAirBalloon.drawSkyboxfront();
			BmpToArray.LoadBmp("space/CloudyLightRays/back.bmp");
			HotAirBalloon.drawSkyboxback();
			BmpToArray.LoadBmp("space/CloudyLightRays/left.bmp");
			HotAirBalloon.drawSkyboxleft();
			BmpToArray.LoadBmp("space/CloudyLightRays/right.bmp");
			HotAirBalloon.drawSkyboxright();
			BmpToArray.LoadBmp("space/CloudyLightRays/up.bmp");
			HotAirBalloon.drawSkyboxup();
			BmpToArray.LoadBmp("space/CloudyLightRays/down.bmp");
			HotAirBalloon.drawSkyboxdown();
			BalloonAnimation();


		} else if(SelectTemplete==2) {
			BmpToArray.LoadBmp("space/DarkStormy/front.bmp");
			HotAirBalloon.drawSkyboxfront();
			BmpToArray.LoadBmp("space/DarkStormy/back.bmp");
			HotAirBalloon.drawSkyboxback();
			BmpToArray.LoadBmp("space/DarkStormy/left.bmp");
			HotAirBalloon.drawSkyboxleft();
			BmpToArray.LoadBmp("space/DarkStormy/right.bmp");
			HotAirBalloon.drawSkyboxright();
			BmpToArray.LoadBmp("space/DarkStormy/up.bmp");
			HotAirBalloon.drawSkyboxup();
			BmpToArray.LoadBmp("space/DarkStormy/down.bmp");
			HotAirBalloon.drawSkyboxdown();
			BalloonAnimation();


		} else if(SelectTemplete==3) {
			BmpToArray.LoadBmp("space/FullMoon/front.bmp");
			HotAirBalloon.drawSkyboxfront();
			BmpToArray.LoadBmp("space/FullMoon/back.bmp");
			HotAirBalloon.drawSkyboxback();
			BmpToArray.LoadBmp("space/FullMoon/left.bmp");
			HotAirBalloon.drawSkyboxleft();
			BmpToArray.LoadBmp("space/FullMoon/right.bmp");
			HotAirBalloon.drawSkyboxright();
			BmpToArray.LoadBmp("space/FullMoon/up.bmp");
			HotAirBalloon.drawSkyboxup();
			BmpToArray.LoadBmp("space/FullMoon/down.bmp");
			HotAirBalloon.drawSkyboxdown();
			BalloonAnimation();


		} else if(SelectTemplete==4) {
			BmpToArray.LoadBmp("space/Mountain/front.bmp");
			HotAirBalloon.drawSkyboxfront();
			BmpToArray.LoadBmp("space/Mountain/back.bmp");
			HotAirBalloon.drawSkyboxback();
			BmpToArray.LoadBmp("space/Mountain/left.bmp");
			HotAirBalloon.drawSkyboxleft();
			BmpToArray.LoadBmp("space/Mountain/right.bmp");
			HotAirBalloon.drawSkyboxright();
			BmpToArray.LoadBmp("space/Mountain/up.bmp");
			HotAirBalloon.drawSkyboxup();
			BmpToArray.LoadBmp("space/Mountain/down.bmp");
			HotAirBalloon.drawSkyboxdown();
			BalloonAnimation();

		} else if(SelectTemplete==5) {
			BmpToArray.LoadBmp("space/SunSet/front.bmp");
			HotAirBalloon.drawSkyboxfront();
			BmpToArray.LoadBmp("space/SunSet/back.bmp");
			HotAirBalloon.drawSkyboxback();
			BmpToArray.LoadBmp("space/SunSet/left.bmp");
			HotAirBalloon.drawSkyboxleft();
			BmpToArray.LoadBmp("space/SunSet/right.bmp");
			HotAirBalloon.drawSkyboxright();
			BmpToArray.LoadBmp("space/SunSet/up.bmp");
			HotAirBalloon.drawSkyboxup();
			BmpToArray.LoadBmp("space/SunSet/down.bmp");
			HotAirBalloon.drawSkyboxdown();
			BalloonAnimation();

		} else if(SelectTemplete==6) {
			BmpToArray.LoadBmp("space/ThickCloudsWater/front.bmp");
			HotAirBalloon.drawSkyboxfront();
			BmpToArray.LoadBmp("space/ThickCloudsWater/back.bmp");
			HotAirBalloon.drawSkyboxback();
			BmpToArray.LoadBmp("space/ThickCloudsWater/left.bmp");
			HotAirBalloon.drawSkyboxleft();
			BmpToArray.LoadBmp("space/ThickCloudsWater/right.bmp");
			HotAirBalloon.drawSkyboxright();
			BmpToArray.LoadBmp("space/ThickCloudsWater/up.bmp");
			HotAirBalloon.drawSkyboxup();
			BmpToArray.LoadBmp("space/ThickCloudsWater/down.bmp");
			HotAirBalloon.drawSkyboxdown();
			BalloonAnimation();

		} else if(SelectTemplete==7) {
			BmpToArray.LoadBmp("space/TropicalSunnyDay/front.bmp");
			HotAirBalloon.drawSkyboxfront();
			BmpToArray.LoadBmp("space/TropicalSunnyDay/back.bmp");
			HotAirBalloon.drawSkyboxback();
			BmpToArray.LoadBmp("space/TropicalSunnyDay/left.bmp");
			HotAirBalloon.drawSkyboxleft();
			BmpToArray.LoadBmp("space/TropicalSunnyDay/right.bmp");
			HotAirBalloon.drawSkyboxright();
			BmpToArray.LoadBmp("space/TropicalSunnyDay/up.bmp");
			HotAirBalloon.drawSkyboxup();
			BmpToArray.LoadBmp("space/TropicalSunnyDay/down.bmp");
			HotAirBalloon.drawSkyboxdown();
			BalloonAnimation();

			//�ʸ�

		} else if(SelectTemplete==8) {
			ProjectorAnimation();

		} else if(SelectTemplete==9) {
			FilmAnimation();

		} else if(SelectTemplete==10) {
			SlateAnimation();

			//�ٴ�

		} else if(SelectTemplete==11) {
			WaveAnimation();

		} else if(SelectTemplete==12) {
			OceanAnimation();

		} else if(SelectTemplete==13) {
			FishingAnimation();

		} else {
			AfxMessageBox("�߸��� �����Դϴ�.");
		}

		//	Invalidate(); // initialize the screen
		//glFinish(); // �̱� ���� or ���� ���۸� ����ϴ� ��� ��� glReadPixels() �Լ� ���� ���
		SwapBuffers(m_hDC);   

		//glReadPixels (0, 0, _width, _height, GL_BGR_EXT, GL_UNSIGNED_BYTE, img->imageData);
		//cvShowImage (window_name, img);

		//waitKey(0);

		//cvReleaseImage (&img);
		//cvDestroyWindow(window_name);


	}


	int CMakoryView::OnCreate(LPCREATESTRUCT lpCreateStruct)
	{
		if (CView::OnCreate(lpCreateStruct) == -1)
			return -1;

		// TODO:  ���⿡ Ư��ȭ�� �ۼ� �ڵ带 �߰��մϴ�.
		m_hDC = GetDC()->m_hDC ;

		// set the pixel format
		if(!SetPixelformat(m_hDC)) {
			return -1;
		}

		// create rendering context and make it current
		m_hglRC = wglCreateContext(m_hDC);
		wglMakeCurrent(m_hDC,m_hglRC);

		InitGL();

		return 0;
	}


	void CMakoryView::OnDestroy()
	{
		CView::OnDestroy();

		// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
		// deselect rendering context and delete it

		wglMakeCurrent(m_hDC, NULL);
		wglDeleteContext(m_hglRC);
	}


	void CMakoryView::OnSize(UINT nType, int cx, int cy)
	{
		CView::OnSize(nType, cx, cy);

		// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
		ReSizeGLScene(cx, cy);
	}


	BOOL CMakoryView::OnEraseBkgnd(CDC* pDC)
	{
		// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.

		return TRUE;		//ȭ�� ������ ����
		return CView::OnEraseBkgnd(pDC);
	}


	void CMakoryView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
	{
		// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
		switch(nChar){
		case 'W':
			LookVec();
			pos[1]+=0.5;
			lookAt[1]+=0.5;
			break;
		case 'S':
			LookVec();
			pos[1]-=0.5;
			lookAt[1]-=0.5;
			break;
		case 'A':
			LeftVec();
			pos[0]-=0.5;
			lookAt[0]-=0.5;
			break;
		case 'D':
			LeftVec();
			pos[0]+=0.5;
			lookAt[0]+=0.5;
			break;
		case 'Z':
			LeftVec();
			pos[2]+=0.5;
			lookAt[2]+=0.5;
			break;
		case 'X':
			LeftVec();
			pos[2]-=0.5;
			lookAt[2]-=0.5;
			break;
		case VK_UP:
			LookVec();
			lookAt[1]+=0.1;
			break;
		case VK_DOWN:
			LookVec();
			lookAt[1]-=0.1;
			break;
		case VK_LEFT:
			LeftVec();
			lookAt[0]-=0.1;
			break;
		case VK_RIGHT:
			LeftVec();
			lookAt[0]+=0.1;
			break;
		}

		InvalidateRect(NULL, FALSE); // initialize the screen

		CView::OnKeyDown(nChar, nRepCnt, nFlags);
	}

	void CMakoryView::LookVec() 
	{
		//����ȭ�ϱ�
		lookVec[0]=lookAt[0]-pos[0];
		lookVec[1]=lookAt[1]-pos[1];
		lookVec[2]=lookAt[2]-pos[2];

		//��������ȭ�ϱ�
		GLfloat root = sqrt(lookVec[0]*lookVec[1] + lookVec[0]*lookVec[1] + lookVec[2]*lookVec[2]);
		lookVec[0]=lookVec[0]/root;
		lookVec[1]=lookVec[1]/root;
		lookVec[2]=lookVec[2]/root;
	}

	void CMakoryView::LeftVec() 
	{
		LookVec();		//lookVec����
		leftVec[0]=(upVec[1]*lookVec[2]) - (upVec[2]*lookVec[1]);
		leftVec[1]=(upVec[2]*lookVec[0]) - (upVec[0]*lookVec[2]);
		leftVec[2]=(upVec[0]*lookVec[1]) - (upVec[1]*lookVec[0]);

		//��������ȭ�ϱ�
		GLfloat root = sqrt(leftVec[0]*leftVec[1] + leftVec[0]*leftVec[1] + leftVec[2]*leftVec[2]);
		leftVec[0]=leftVec[0]/root;
		leftVec[1]=leftVec[1]/root;
		leftVec[2]=leftVec[2]/root;
	}


	void CMakoryView::Initialization(){
		x=0;
		y=0;
		z=0;
		pos[0]=0.f;
		pos[1]=0.f;
		pos[2]=3.f;
		lookAt[0]=0.f;
		lookAt[1]=0.f;
		lookAt[2]=0.f;
		upVec[0]=0.f;
		upVec[1]=1.f;
		upVec[2]=0.f;
	}

	void CMakoryView::BallonInitialization(){
		x=0;
		y=-33;
		z=0;
		pos[0]=0.f;
		pos[1]=-30.f;
		pos[2]=3.f;
		lookAt[0]=0.f;
		lookAt[1]=-30.f;
		lookAt[2]=0.f;
		upVec[0]=0.f;
		upVec[1]=1.f;
		upVec[2]=0.f;
	}
