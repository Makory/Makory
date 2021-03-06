
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
#include "MainFrm.h"

using namespace std;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

static const UINT TIMER_ID_ANIMATION = 1000;

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
      ON_WM_TIMER()
   END_MESSAGE_MAP()

   // CMakoryView 생성/소멸

   CMakoryView::CMakoryView()
   {
      // TODO: 여기에 생성 코드를 추가합니다.
      filmimgscale=0.0;
   projimgscale=0.0;
   slateimgscale=0.0;

   fishingimgscale=0.0;
   spacescale=0.0;
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
      ExportNum=0;

      MainFrm = nullptr;
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
      //SelectTemplate=ImageTimeline->NonTitle;
      CMakoryDoc* pDoc = GetDocument();
      ASSERT_VALID(pDoc);
      if (!pDoc)
         return;

      // TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.

      if(SelectTemplate<=0) {
         DrawGLTitle(SelectTemplate);      //처음 실행시 타이틀 이미지 보여짐
      } else {
         DrawGLScene(SelectTemplate);      //선택시 템플릿 보여짐
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

      glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB); // 더블 버퍼링
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
      glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
      glLoadIdentity();

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
      SwapBuffers(m_hDC);   

   }

   void CMakoryView::StartAnimation()
   {
      Initialization();
      SetTimer(TIMER_ID_ANIMATION, 30/*in milisecond*/, nullptr);

      Invalidate(FALSE);
   }
   void CMakoryView::BallonStartAnimation()
   {
      BallonInitialization();
      SetTimer(TIMER_ID_ANIMATION, 30/*in milisecond*/, nullptr);

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
            if(SelectTemplate>=1&&SelectTemplate<=7) {
               BalloonAnimation();
            } else if(SelectTemplate==8) {
               ProjectorAnimation();
            } else if(SelectTemplate==9) {
               FilmAnimation();
            } else if(SelectTemplate==10) {
               SlateAnimation();
            } else if(SelectTemplate==11) {
               WaveAnimation();
            } else if(SelectTemplate==12) {
               OceanAnimation();
            } else if(SelectTemplate==13) {
               FishingAnimation();
            }
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
      time+=0.1;

      if(time>=42.4) {
         KillTimer(TIMER_ID_ANIMATION);
         if(IsItKey<=1){
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

      if(ExportNum==1){
         if (MainFrm == nullptr)
         {
            MainFrm = static_cast<CMainFrame*>(theApp.m_pMainWnd);
         }
         MainFrm->ReadingPixel();
      }
   }




   void CMakoryView::ProjectorAnimation()
   { 
      //영사기 애니
      time+=0.08;

      if(time>=7) {
         KillTimer(TIMER_ID_ANIMATION);
         if(IsItKey<=1){
            ImageTimeline->OnAnimationFinished();
         }
      }
      else if(time>=4){
         r+=40;
      } else {
         r1-=30;
      }
      if(ExportNum==1){
         if (MainFrm == nullptr)
         {
            MainFrm = static_cast<CMainFrame*>(theApp.m_pMainWnd);
         }
         MainFrm->ReadingPixel();
      }
   }

   void CMakoryView::FilmAnimation()
   {


      //필름 애니
      time+=0.01;
      if(time>=5) {
         KillTimer(TIMER_ID_ANIMATION);
         if(IsItKey<=1){
            ImageTimeline->OnAnimationFinished();
         }
      }else {
         x-=0.007;
      }
      if(ExportNum==1){
         if (MainFrm == nullptr)
         {
            MainFrm = static_cast<CMainFrame*>(theApp.m_pMainWnd);
         }
         MainFrm->ReadingPixel();
      }
   }

   void CMakoryView::SlateAnimation()
   {
      time+=0.08;
      //슬레이트 애니

      if(time>=6.9) {
         KillTimer(TIMER_ID_ANIMATION);
         if(IsItKey<=1){
            ImageTimeline->OnAnimationFinished();
         }
      }
      else if(time>=3.5){
         r-=1;
      } else {
         r+=1;
      }

      if(ExportNum==1){
         if (MainFrm == nullptr)
         {
            MainFrm = static_cast<CMainFrame*>(theApp.m_pMainWnd);
         }
         MainFrm->ReadingPixel();
      }
   }

   void CMakoryView::WaveAnimation()
   {
      time+=0.03;
      //파도
      if(time>=8) {
         KillTimer(TIMER_ID_ANIMATION);
         if(IsItKey<=1){
            ImageTimeline->OnAnimationFinished();
         }
      }else if(time>=6){   //파도 이미지 올라감
         y+=0.025;
         y1+=0.025;
      }else if(time>=4){   //파도만 내려옴
         y-=0.07;
      }else if(time>=2){   //파도만 올라감
         y+=0.07;
      }else {         //파도 이미지 내려옴
         y-=0.03;
         y1-=0.03;

      }
   }

   void CMakoryView::OceanAnimation()
   {         
      time+=0.05;
      //바다속
      if(time>=15) {
         KillTimer(TIMER_ID_ANIMATION);
         if(IsItKey<=1){
            ImageTimeline->OnAnimationFinished();
         }
      }else {
         x+=0.05;
         y+=0.01;
         y1+=0.03;
         r+=0.06;
      }

      if(ExportNum==1){
         if (MainFrm == nullptr)
         {
            MainFrm = static_cast<CMainFrame*>(theApp.m_pMainWnd);
         }
         MainFrm->ReadingPixel();
      }

   }

   void CMakoryView::FishingAnimation()
   {
      //낚시 애니
     time+=0.1;
      if(time>=18) {
         KillTimer(TIMER_ID_ANIMATION);
         if(IsItKey<=1){
            ImageTimeline->OnAnimationFinished();
         }
      }
      else if(time>=9){
            y-=0.005;
      } else {
        y+=0.005;
      }

      if(ExportNum==1){
         if (MainFrm == nullptr)
         {
            MainFrm = static_cast<CMainFrame*>(theApp.m_pMainWnd);
         }
         MainFrm->ReadingPixel();
      }
   }

   void CMakoryView::DrawGLScene(int SelectTemplete) 
   {
      glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
      glLoadIdentity();

      gluLookAt(pos[0],pos[1],pos[2],lookAt[0],lookAt[1],lookAt[2],upVec[0],upVec[1],upVec[2]);

      // draw 


      //열기구

      /*--------하늘 종류 번호------------
      CloudyLightRays : 1
      DarkStormy : 2
      FullMoon : 3
      Mountain : 4
      CloudyLightRays : 5
      ThickCloudsWater : 6
      TropicalSunnyDay : 7
      ------------------------------------*/
      if(SelectTemplete==1) {
         //Invalidate(FALSE);
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

         HotAirBalloon.HotBalloonLine(0,y,0);
         HotAirBalloon.HotBalloonSphere(0,y,0);
         BmpToArray.LoadBmp(SelectImage);
         HotAirBalloon.HotBalloonTexture(0,y,0);
      }
      else if(SelectTemplete==2) {
         //Invalidate(FALSE);
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

         HotAirBalloon.DarkHotBalloonLine(0,y,0);
         HotAirBalloon.DarkHotBalloonSphere(0,y,0);
         BmpToArray.LoadBmp(SelectImage);
         HotAirBalloon.DarkHotBalloonTexture(0,y,0);
      }
      else if(SelectTemplete==3) {
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

         HotAirBalloon.FullHotBalloonLine(0,y,0);
         HotAirBalloon.FullHotBalloonSphere(0,y,0);
         BmpToArray.LoadBmp(SelectImage);
         HotAirBalloon.FullHotBalloonTexture(0,y,0);
      }
      else if(SelectTemplete==4) {
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

         HotAirBalloon.MountHotBalloonLine(0,y,0);
         HotAirBalloon.MountHotBalloonSphere(0,y,0);
         BmpToArray.LoadBmp(SelectImage);
         HotAirBalloon.MountHotBalloonTexture(0,y,0);
      }
      else if(SelectTemplete==5) {
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

         HotAirBalloon.SunsetHotBalloonLine(0,y,0);
         HotAirBalloon.SunsetHotBalloonSphere(0,y,0);
         BmpToArray.LoadBmp(SelectImage);
         HotAirBalloon.SunsetHotBalloonTexture(0,y,0);

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

         HotAirBalloon.CloudsHotBalloonLine(0,y,0);
         HotAirBalloon.CloudsHotBalloonSphere(0,y,0);
         BmpToArray.LoadBmp(SelectImage);
         HotAirBalloon.CloudsHotBalloonTexture(0,y,0);

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

         HotAirBalloon.TropicalHotBalloonLine(0,y,0);
         HotAirBalloon.TropicalHotBalloonSphere(0,y,0);
         BmpToArray.LoadBmp(SelectImage);
         HotAirBalloon.TropicalHotBalloonTexture(0,y,0);
      }
      else if(SelectTemplete==8) {
         BmpToArray.LoadBmp(SelectImage);
         glEnable(GL_TEXTURE_2D);
         glMatrixMode(GL_MODELVIEW);
         glPushMatrix();
         glDisable(GL_DEPTH_TEST);

         glTexEnvf(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_DECAL);
         glColor3f(0,0,0);

         //front
         glBegin(GL_QUADS);
         glTexCoord2f(1.0, 1.0); glVertex3f(-3-projimgscale,-2-projimgscale,-1);
         glTexCoord2f(0.0, 1.0); glVertex3f(3+projimgscale,-2-projimgscale,-1);
         glTexCoord2f(0.0, 0.0); glVertex3f(3+projimgscale,2+projimgscale,-1);
         glTexCoord2f(1.0, 0.0); glVertex3f(-3-projimgscale,2+projimgscale,-1);
         glEnd();

         glEnable(GL_DEPTH_TEST);
         glPopMatrix();

         glDisable(GL_TEXTURE_2D);

         Film.ProjectorBody(-0.4,-0.5,1,1,1);
         Film.ProjectorCircle1(-0.4,-0.5,r);
         Film.ProjectorCircle2(-0.4,-0.5,r1);


      } else if(SelectTemplete==9) {
         glPushMatrix();
         BmpToArray.LoadBmp("space/FilmBK.BMP");
         glEnable(GL_TEXTURE_2D);
         glMatrixMode(GL_MODELVIEW);
         glDisable(GL_DEPTH_TEST);

         glTexEnvf(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_DECAL);
         glColor3f(0,0,0);


         //front
         glBegin(GL_QUADS);
         glTexCoord2f(1.0, 1.0); glVertex3f(-3,-2,-1);
         glTexCoord2f(0.0, 1.0); glVertex3f(3,-2,-1);
         glTexCoord2f(0.0, 0.0); glVertex3f(3,2,-1);
         glTexCoord2f(1.0, 0.0); glVertex3f(-3,2,-1);
         glEnd();

         glEnable(GL_DEPTH_TEST);
         glDisable(GL_TEXTURE_2D);
         glPopMatrix();

         Film.FilmBody(x+1.7,-0.5);
         BmpToArray.LoadBmp(SelectImage);
         Film.FilmCenter2(x-3.25,-0.5,0,0,0);//사용자가 넣을사진


      } else if(SelectTemplete==10) {
         BmpToArray.LoadBmp(SelectImage);
         glEnable(GL_TEXTURE_2D);
         glMatrixMode(GL_MODELVIEW);
         glPushMatrix();
         glDisable(GL_DEPTH_TEST);

         glTexEnvf(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_DECAL);
         glColor3f(0,0,0);


         //front
         glBegin(GL_QUADS);
         glTexCoord2f(1.0, 1.0); glVertex3f(-3-slateimgscale,-2-slateimgscale,-1);
         glTexCoord2f(0.0, 1.0); glVertex3f(3+slateimgscale,-2-slateimgscale,-1);
         glTexCoord2f(0.0, 0.0); glVertex3f(3+slateimgscale,2+slateimgscale,-1);
         glTexCoord2f(1.0, 0.0); glVertex3f(-3-slateimgscale,2+slateimgscale,-1);
         glEnd();

         glEnable(GL_DEPTH_TEST);
         glPopMatrix();

         glDisable(GL_TEXTURE_2D);

         Film.SlateHead(-0.4,-0.5,r);
         Film.SlateBody(-0.4,-0.5);


         //바다

      } else if(SelectTemplete==11) {
         BmpToArray.LoadBmp("space/sandy.bmp");
         glEnable(GL_TEXTURE_2D);
         glMatrixMode(GL_MODELVIEW);
         glPushMatrix();
         glDisable(GL_DEPTH_TEST);

         glTexEnvf(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_DECAL);
         glColor3f(0,0,0);


         //front
         glBegin(GL_QUADS);
         glTexCoord2f(1.0, 1.0); glVertex3f(-100,-100,-100);
         glTexCoord2f(0.0, 1.0); glVertex3f(100,-100,-100);
         glTexCoord2f(0.0, 0.0); glVertex3f(100,100,-100);
         glTexCoord2f(1.0, 0.0); glVertex3f(-100,100,-100);
         glEnd();

         glEnable(GL_DEPTH_TEST);
         glPopMatrix();

         glDisable(GL_TEXTURE_2D);

         Ocean.wave1(0,y,0,0,0,1);
         BmpToArray.LoadBmp(SelectImage);
         Ocean.WaveTexture(0,y1);//텍스처가 먼저나온게 더 보기좋네요


      } else if(SelectTemplete==12) {
         BmpToArray.LoadBmp("space/Ocean.bmp");
         glEnable(GL_TEXTURE_2D);
         glMatrixMode(GL_MODELVIEW);
         glPushMatrix();
         glDisable(GL_DEPTH_TEST);

         glTexEnvf(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_DECAL);
         glColor3f(0,0,0);


         //front
         glBegin(GL_QUADS);
         glTexCoord2f(1.0, 1.0); glVertex3f(-100,-100,-100);
         glTexCoord2f(0.0, 1.0); glVertex3f(100,-100,-100);
         glTexCoord2f(0.0, 0.0); glVertex3f(100,100,-100);
         glTexCoord2f(1.0, 0.0); glVertex3f(-100,100,-100);
         glEnd();

         glEnable(GL_DEPTH_TEST);
         glPopMatrix();

         glDisable(GL_TEXTURE_2D);

         Ocean.CircleFish(x,y);//삼각물고기
         Ocean.CircleFishEyes(x,y);
         Ocean.CircleFish(x+0.2+spacescale,y+0.7+spacescale);//삼각물고기
         Ocean.CircleFishEyes(x+0.2+spacescale,y+0.7+spacescale);


         Ocean.CircleFish1(x,-y);//삼각물고기
         Ocean.CircleFishEyes1(x,-y);
         Ocean.CircleFish1(x+0.2+spacescale,-y+0.7+spacescale);//삼물
         Ocean.CircleFishEyes1(x+0.2+spacescale,-y+0.7+spacescale);

         Ocean.StarFish2(2,0.5,0,0,0,0);//별가
         Ocean.StarFish2eyesR(2,0.5,0);//별가 눈
         Ocean.StarFish2eyesL(2,0.5,0);//별가 눈

         Ocean.Fish2(x,y,0,0,0,0);//물고기 1
         Ocean.eyes2(x,y);//물고기 1 눈
         Ocean.Fish2(x,-y,0,0,0,0);//물고기 1
         Ocean.eyes2(x,-y);//물고기 1 눈
         Ocean.Fish2(x,0,0,0,0,0);//물고기 1
         Ocean.eyes2(x,0);//물고기 1 눈

         Ocean.Fish3(x,y,0,0,0,0);//물고기 1
         Ocean.eyes3(x,y);//물고기 1 눈
         Ocean.Fish3(x,-y,0,0,0,0);//물고기 1
         Ocean.eyes3(x,-y);//물고기 1 눈
         Ocean.Fish3(x,0,0,0,0,0);//물고기 1
         Ocean.eyes3(x,0);//물고기 1 눈

         BmpToArray.LoadBmp(SelectImage);
         Ocean.OceanTexture(1.5,1.5*y1-1.5,r);//텍스쳐 위치는 아직 못 결정함


      } else if(SelectTemplete==13) {
         BmpToArray.LoadBmp("space/sea.BMP");
         glEnable(GL_TEXTURE_2D);
         glMatrixMode(GL_MODELVIEW);
         glPushMatrix();
         glDisable(GL_DEPTH_TEST);

         glTexEnvf(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_DECAL);
         glColor3f(0,0,0);


         //front
         glBegin(GL_QUADS);
         glTexCoord2f(1.0, 1.0); glVertex3f(-100,-100,-100);
         glTexCoord2f(0.0, 1.0); glVertex3f(100,-100,-100);
         glTexCoord2f(0.0, 0.0); glVertex3f(100,100,-100);
         glTexCoord2f(1.0, 0.0); glVertex3f(-100,100,-100);
         glEnd();

         glEnable(GL_DEPTH_TEST);
         glPopMatrix();

         glDisable(GL_TEXTURE_2D);

        Ocean.vessel(0,0);//배
      Ocean.fishingrod(0,0);//낚시대
      Ocean.fishingrod1(0,0);//낚시선
        BmpToArray.LoadBmp(SelectImage);
      Ocean.FishingTexture(0.5,y);


      } else {
        // AfxMessageBox("잘못된 접근입니다.");
      BmpToArray.LoadBmp("space/NoTemplete.bmp");

      glEnable(GL_TEXTURE_2D);
      glMatrixMode(GL_MODELVIEW);
      glPushMatrix();
      glDisable(GL_DEPTH_TEST);
      // Skybox는 다른 색상의 영향을 받으면 안되므로 DECAL
      glTexEnvf(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_DECAL);
      glColor3f(0,0,0);


      //front
      glBegin(GL_QUADS);
      glTexCoord2f(1.0, 1.0); glVertex2f(-1.25,-1);
      glTexCoord2f(0.0, 1.0); glVertex2f(1.25,-1);
      glTexCoord2f(0.0, 0.0); glVertex2f(1.25,1);
      glTexCoord2f(1.0, 0.0); glVertex2f(-1.25,1);
      glEnd();

      glEnable(GL_DEPTH_TEST);
      glPopMatrix();

      glDisable(GL_TEXTURE_2D);
      }

      SwapBuffers(m_hDC);   
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

      return TRUE;      //화면 깜박임 제거
      return CView::OnEraseBkgnd(pDC);
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
      LookVec();      //lookVec설정
      leftVec[0]=(upVec[1]*lookVec[2]) - (upVec[2]*lookVec[1]);
      leftVec[1]=(upVec[2]*lookVec[0]) - (upVec[0]*lookVec[2]);
      leftVec[2]=(upVec[0]*lookVec[1]) - (upVec[1]*lookVec[0]);

      //단위벡터화하기
      GLfloat root = sqrt(leftVec[0]*leftVec[1] + leftVec[0]*leftVec[1] + leftVec[2]*leftVec[2]);
      leftVec[0]=leftVec[0]/root;
      leftVec[1]=leftVec[1]/root;
      leftVec[2]=leftVec[2]/root;
   }


   void CMakoryView::Initialization(){
      x=0;
      y=0;
      y1=0;
      z=0;
      r=0;
      r1=0;
      time=0;
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
      time=0;
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