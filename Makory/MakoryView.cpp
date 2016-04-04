
// MakoryView.cpp : CMakoryView 클래스의 구현
//

#include "stdafx.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
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


// CMakoryView

IMPLEMENT_DYNCREATE(CMakoryView, CView)

BEGIN_MESSAGE_MAP(CMakoryView, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CMakoryView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_CREATE()
	ON_WM_DESTROY()
	ON_WM_SIZE()
	ON_WM_ERASEBKGND()
	ON_WM_KEYDOWN()
END_MESSAGE_MAP()

// CMakoryView 생성/소멸

CMakoryView::CMakoryView()
{
	// TODO: 여기에 생성 코드를 추가합니다.
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

CMakoryView::~CMakoryView()
{
}

BOOL CMakoryView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CMakoryView 그리기

void CMakoryView::OnDraw(CDC* /*pDC*/)
{
	int SelectTemplate=1;
	CMakoryDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
	
	if(SelectTemplate==0) {
	DrawGLTitle();		//처음 실행시 타이틀 이미지 보여짐
	} else if(SelectTemplate==1) {
		DrawGLScene();		//선택시 템플릿 보여짐
	}
}


// CMakoryView 인쇄


void CMakoryView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CMakoryView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CMakoryView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CMakoryView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
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


// CMakoryView 진단

#ifdef _DEBUG
void CMakoryView::AssertValid() const
{
	CView::AssertValid();
}

void CMakoryView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMakoryDoc* CMakoryView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMakoryDoc)));
	return (CMakoryDoc*)m_pDocument;
}
#endif //_DEBUG


// CMakoryView 메시지 처리기

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

	
	void CMakoryView::DrawGLTitle() 
	{
		//--------------------OpenCV---------------------
		int _width = 400;
		int _height = 400;
		long count = 0;
		unsigned long lImageSize = _width*3*_height; // RGB 데이터를 저장할 메모리 크기

		char* window_name = "OpenGL to OpenCV";
		glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); // 싱글 버퍼링
		//glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB); // 더블 버퍼링
		glutInitWindowSize(400, 400);  // 창 크기 설정
		glutInitWindowPosition(0, 0);
		IplImage *img = cvCreateImage (cvSize(_width, _height), IPL_DEPTH_8U, 3); // RGB 데이터형
		//glutCreateWindow("OpenGL");
		// clear screen and depth buffer
		//--------------------------------------------------

		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glLoadIdentity();

		// camera view configuration 
		//gluLookAt(0.f, 0.f, 3.f, 0.f, 0.f, 0.f, 0.f, 1.f, 0.f);
		//gluLookAt(pos[0],pos[1],pos[2],lookAt[0],lookAt[1],lookAt[2],upVec[0],upVec[1],upVec[2]);

		// draw 

			BmpToArray->LoadBmp("space/Title_Image.bmp");

	glEnable(GL_TEXTURE_2D);
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glDisable(GL_DEPTH_TEST);
	// Skybox는 다른 색상의 영향을 받으면 안되므로 DECAL
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

		//glFinish(); // 싱글 버퍼 or 더블 버퍼를 사용하는 경우 모두 glReadPixels() 함수 전에 사용
		SwapBuffers(m_hDC);   
		
		glReadPixels (0, 0, _width, _height, GL_BGR_EXT, GL_UNSIGNED_BYTE, img->imageData);
		//cvShowImage (window_name, img);

		waitKey(0);


		//cvReleaseImage (&img);
		//cvDestroyWindow(window_name);
	
	
	}


	void CMakoryView::DrawGLScene() 
	{
		//--------------------OpenCV---------------------
		int _width = 400;
		int _height = 400;
		long count = 0;
		unsigned long lImageSize = _width*3*_height; // RGB 데이터를 저장할 메모리 크기

		char* window_name = "OpenGL to OpenCV";
		glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); // 싱글 버퍼링
		//glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB); // 더블 버퍼링
		glutInitWindowSize(400, 400);  // 창 크기 설정
		glutInitWindowPosition(0, 0);
		IplImage *img = cvCreateImage (cvSize(_width, _height), IPL_DEPTH_8U, 3); // RGB 데이터형
		//glutCreateWindow("OpenGL");
		// clear screen and depth buffer
		//--------------------------------------------------

		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glLoadIdentity();

		// camera view configuration 
		//gluLookAt(0.f, 0.f, 3.f, 0.f, 0.f, 0.f, 0.f, 1.f, 0.f);
		gluLookAt(pos[0],pos[1],pos[2],lookAt[0],lookAt[1],lookAt[2],upVec[0],upVec[1],upVec[2]);

		// draw 

		/*--------하늘 종류 번호------------
			CloudyLightRays : 1
			DarkStormy : 2
			FullMoon : 3
			Mountain : 4
			CloudyLightRays : 5
			ThickCloudsWater : 6
			TropicalSunnyDay : 7
		------------------------------------*/
		int SelectSky=1;		//하늘 선택

		if(SelectSky==1) {
			BmpToArray->LoadBmp("space/CloudyLightRays/front.bmp");
			HotAirBalloon->drawSkyboxfront();
			BmpToArray->LoadBmp("space/CloudyLightRays/back.bmp");
			HotAirBalloon->drawSkyboxback();
			BmpToArray->LoadBmp("space/CloudyLightRays/left.bmp");
			HotAirBalloon->drawSkyboxleft();
			BmpToArray->LoadBmp("space/CloudyLightRays/right.bmp");
			HotAirBalloon->drawSkyboxright();
			BmpToArray->LoadBmp("space/CloudyLightRays/up.bmp");
			HotAirBalloon->drawSkyboxup();
			BmpToArray->LoadBmp("space/CloudyLightRays/down.bmp");
			HotAirBalloon->drawSkyboxdown();
		} else if(SelectSky==2) {
			BmpToArray->LoadBmp("space/DarkStormy/front.bmp");
			HotAirBalloon->drawSkyboxfront();
			BmpToArray->LoadBmp("space/DarkStormy/back.bmp");
			HotAirBalloon->drawSkyboxback();
			BmpToArray->LoadBmp("space/DarkStormy/left.bmp");
			HotAirBalloon->drawSkyboxleft();
			BmpToArray->LoadBmp("space/DarkStormy/right.bmp");
			HotAirBalloon->drawSkyboxright();
			BmpToArray->LoadBmp("space/DarkStormy/up.bmp");
			HotAirBalloon->drawSkyboxup();
			BmpToArray->LoadBmp("space/DarkStormy/down.bmp");
			HotAirBalloon->drawSkyboxdown();
		} else if(SelectSky==3) {
			BmpToArray->LoadBmp("space/FullMoon/front.bmp");
			HotAirBalloon->drawSkyboxfront();
			BmpToArray->LoadBmp("space/FullMoon/back.bmp");
			HotAirBalloon->drawSkyboxback();
			BmpToArray->LoadBmp("space/FullMoon/left.bmp");
			HotAirBalloon->drawSkyboxleft();
			BmpToArray->LoadBmp("space/FullMoon/right.bmp");
			HotAirBalloon->drawSkyboxright();
			BmpToArray->LoadBmp("space/FullMoon/up.bmp");
			HotAirBalloon->drawSkyboxup();
			BmpToArray->LoadBmp("space/FullMoon/down.bmp");
			HotAirBalloon->drawSkyboxdown();
		} else if(SelectSky==4) {
			BmpToArray->LoadBmp("space/Mountain/front.bmp");
			HotAirBalloon->drawSkyboxfront();
			BmpToArray->LoadBmp("space/Mountain/back.bmp");
			HotAirBalloon->drawSkyboxback();
			BmpToArray->LoadBmp("space/Mountain/left.bmp");
			HotAirBalloon->drawSkyboxleft();
			BmpToArray->LoadBmp("space/Mountain/right.bmp");
			HotAirBalloon->drawSkyboxright();
			BmpToArray->LoadBmp("space/Mountain/up.bmp");
			HotAirBalloon->drawSkyboxup();
			BmpToArray->LoadBmp("space/Mountain/down.bmp");
			HotAirBalloon->drawSkyboxdown();
		} else if(SelectSky==5) {
			BmpToArray->LoadBmp("space/SunSet/front.bmp");
			HotAirBalloon->drawSkyboxfront();
			BmpToArray->LoadBmp("space/SunSet/back.bmp");
			HotAirBalloon->drawSkyboxback();
			BmpToArray->LoadBmp("space/SunSet/left.bmp");
			HotAirBalloon->drawSkyboxleft();
			BmpToArray->LoadBmp("space/SunSet/right.bmp");
			HotAirBalloon->drawSkyboxright();
			BmpToArray->LoadBmp("space/SunSet/up.bmp");
			HotAirBalloon->drawSkyboxup();
			BmpToArray->LoadBmp("space/SunSet/down.bmp");
			HotAirBalloon->drawSkyboxdown();
		} else if(SelectSky==6) {
			BmpToArray->LoadBmp("space/ThickCloudsWater/front.bmp");
			HotAirBalloon->drawSkyboxfront();
			BmpToArray->LoadBmp("space/ThickCloudsWater/back.bmp");
			HotAirBalloon->drawSkyboxback();
			BmpToArray->LoadBmp("space/ThickCloudsWater/left.bmp");
			HotAirBalloon->drawSkyboxleft();
			BmpToArray->LoadBmp("space/ThickCloudsWater/right.bmp");
			HotAirBalloon->drawSkyboxright();
			BmpToArray->LoadBmp("space/ThickCloudsWater/up.bmp");
			HotAirBalloon->drawSkyboxup();
			BmpToArray->LoadBmp("space/ThickCloudsWater/down.bmp");
			HotAirBalloon->drawSkyboxdown();
		} else if(SelectSky==7) {
			BmpToArray->LoadBmp("space/TropicalSunnyDay/front.bmp");
			HotAirBalloon->drawSkyboxfront();
			BmpToArray->LoadBmp("space/TropicalSunnyDay/back.bmp");
			HotAirBalloon->drawSkyboxback();
			BmpToArray->LoadBmp("space/TropicalSunnyDay/left.bmp");
			HotAirBalloon->drawSkyboxleft();
			BmpToArray->LoadBmp("space/TropicalSunnyDay/right.bmp");
			HotAirBalloon->drawSkyboxright();
			BmpToArray->LoadBmp("space/TropicalSunnyDay/up.bmp");
			HotAirBalloon->drawSkyboxup();
			BmpToArray->LoadBmp("space/TropicalSunnyDay/down.bmp");
			HotAirBalloon->drawSkyboxdown();
		} else {
			AfxMessageBox("잘못된 접근입니다.");
		}

		//glFinish(); // 싱글 버퍼 or 더블 버퍼를 사용하는 경우 모두 glReadPixels() 함수 전에 사용
		SwapBuffers(m_hDC);   
		
		glReadPixels (0, 0, _width, _height, GL_BGR_EXT, GL_UNSIGNED_BYTE, img->imageData);
		//cvShowImage (window_name, img);

		waitKey(0);


		//cvReleaseImage (&img);
		//cvDestroyWindow(window_name);
	
	
	}


	int CMakoryView::OnCreate(LPCREATESTRUCT lpCreateStruct)
	{
		if (CView::OnCreate(lpCreateStruct) == -1)
			return -1;

		// TODO:  여기에 특수화된 작성 코드를 추가합니다.
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

		// TODO: 여기에 메시지 처리기 코드를 추가합니다.
		// deselect rendering context and delete it

		wglMakeCurrent(m_hDC, NULL);
		wglDeleteContext(m_hglRC);
	}


	void CMakoryView::OnSize(UINT nType, int cx, int cy)
	{
		CView::OnSize(nType, cx, cy);

		// TODO: 여기에 메시지 처리기 코드를 추가합니다.
		ReSizeGLScene(cx, cy);
	}


	BOOL CMakoryView::OnEraseBkgnd(CDC* pDC)
	{
		// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
		
		return TRUE;		//화면 깜박임 제거
		return CView::OnEraseBkgnd(pDC);
	}


	void CMakoryView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
	{
		// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
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
		//벡터화하기
		lookVec[0]=lookAt[0]-pos[0];
		lookVec[1]=lookAt[1]-pos[1];
		lookVec[2]=lookAt[2]-pos[2];

		//단위벡터화하기
		GLfloat root = sqrt(lookVec[0]*lookVec[1] + lookVec[0]*lookVec[1] + lookVec[2]*lookVec[2]);
		lookVec[0]=lookVec[0]/root;
		lookVec[1]=lookVec[1]/root;
		lookVec[2]=lookVec[2]/root;
	}
	
	void CMakoryView::LeftVec() 
	{
		LookVec();		//lookVec설정
		leftVec[0]=(upVec[1]*lookVec[2]) - (upVec[2]*lookVec[1]);
		leftVec[1]=(upVec[2]*lookVec[0]) - (upVec[0]*lookVec[2]);
		leftVec[2]=(upVec[0]*lookVec[1]) - (upVec[1]*lookVec[0]);

		//단위벡터화하기
		GLfloat root = sqrt(leftVec[0]*leftVec[1] + leftVec[0]*leftVec[1] + leftVec[2]*leftVec[2]);
		leftVec[0]=leftVec[0]/root;
		leftVec[1]=leftVec[1]/root;
		leftVec[2]=leftVec[2]/root;
	}