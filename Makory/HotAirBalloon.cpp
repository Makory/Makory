// HotAirBalloon.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "Makory.h"
#include "HotAirBalloon.h"
#include "BalloonDlg.h"
#include "MainFrm.h"
#include "MakoryDoc.h"
#include "MakoryView.h"

#define TEX_SIZE 100
#define GL_CLAMP_TO_EDGE 0x812F

// HotAirBalloon

IMPLEMENT_DYNAMIC(HotAirBalloon, CWnd)

   HotAirBalloon::HotAirBalloon()
{
   balloonred=1.0;
   balloongreen=0.0;
   balloonblue=0.0;
   balloonx=0.0;
   balloony=0.0;
   balloonscale = 0.0;

   darkstormyred=1.0;
   darkstormygreen=0.0;
   darkstormyblue=0.0;
   darkstormyx=0.0;
   darkstormyy=0.0;
   darkstormyscale=0.0;

   fullmoonred=1.0;
   fullmoongreen=0.0;
   fullmoonblue=0.0;
   fullmoonx=0.0;
   fullmoony=0.0;
   fullmoonscale=0.0;

   mountred=1.0;
   mountgreen=0.0;
   mountblue=0.0;
   mountx=0.0;
   mounty=0.0;
   mountscale=0.0;

   sunsetred=1.0;
   sunsetgreen=0.0;
   sunsetblue=0.0;
   sunsetx=0.0;
   sunsety=0.0;
   sunsetscale=0.0;

   cloudsred=1.0;
   cloudsgreen=0.0;
   cloudsblue=0.0;
   cloudsx=0.0;
   cloudsy=0.0;
   cloudsscale=0.0;

   tropicalred=1.0;
   tropicalgreen=0.0;
   tropicalblue=0.0;
   tropicalx=0.0;
   tropicaly=0.0;
   tropicalscale=0.0;

}

HotAirBalloon::~HotAirBalloon()
{
}

void HotAirBalloon::drawSkyboxfront(){
   glEnable(GL_TEXTURE_2D);
   glMatrixMode(GL_MODELVIEW);
   glPushMatrix();
   glDisable(GL_DEPTH_TEST);
   // Skybox는 다른 색상의 영향을 받으면 안되므로 DECAL
   glTexEnvf(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_DECAL);
   glColor3f(0,0,0);


   //front
   glBegin(GL_QUADS);
   glTexCoord2f(1.0, 1.0); glVertex3f(-TEX_SIZE,-TEX_SIZE,-TEX_SIZE);
   glTexCoord2f(0.0, 1.0); glVertex3f(TEX_SIZE,-TEX_SIZE,-TEX_SIZE);
   glTexCoord2f(0.0, 0.0); glVertex3f(TEX_SIZE,TEX_SIZE,-TEX_SIZE);
   glTexCoord2f(1.0, 0.0); glVertex3f(-TEX_SIZE,TEX_SIZE,-TEX_SIZE);
   glEnd();

   glEnable(GL_DEPTH_TEST);
   glPopMatrix();
   glDisable(GL_TEXTURE_2D);
}

void HotAirBalloon::drawSkyboxback(){
   glEnable(GL_TEXTURE_2D);
   glMatrixMode(GL_MODELVIEW);
   glPushMatrix();
   glDisable(GL_DEPTH_TEST);
   // Skybox는 다른 색상의 영향을 받으면 안되므로 DECAL
   glTexEnvf(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_DECAL);
   glColor3f(0,0,0);

   //back
   glBegin(GL_QUADS);
   glTexCoord2f(1.0, 1.0); glVertex3f(TEX_SIZE,-TEX_SIZE,TEX_SIZE);
   glTexCoord2f(0.0, 1.0); glVertex3f(-TEX_SIZE,-TEX_SIZE,TEX_SIZE);
   glTexCoord2f(0.0, 0.0); glVertex3f(-TEX_SIZE,TEX_SIZE,TEX_SIZE);
   glTexCoord2f(1.0, 0.0); glVertex3f(TEX_SIZE,TEX_SIZE,TEX_SIZE);
   glEnd();

   glEnable(GL_DEPTH_TEST);
   glPopMatrix();
   glDisable(GL_TEXTURE_2D);
}

void HotAirBalloon::drawSkyboxleft(){
   glEnable(GL_TEXTURE_2D);
   glMatrixMode(GL_MODELVIEW);
   glPushMatrix();
   glDisable(GL_DEPTH_TEST);
   // Skybox는 다른 색상의 영향을 받으면 안되므로 DECAL
   glTexEnvf(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_DECAL);
   glColor3f(0,0,0);

   //left
   glBegin(GL_QUADS);
   glTexCoord2f(1.0, 1.0); glVertex3f(TEX_SIZE,-TEX_SIZE,-TEX_SIZE);
   glTexCoord2f(0.0, 1.0); glVertex3f(TEX_SIZE,-TEX_SIZE,TEX_SIZE);
   glTexCoord2f(0.0, 0.0); glVertex3f(TEX_SIZE,TEX_SIZE,TEX_SIZE);
   glTexCoord2f(1.0, 0.0); glVertex3f(TEX_SIZE,TEX_SIZE,-TEX_SIZE);
   glEnd();

   glEnable(GL_DEPTH_TEST);
   glPopMatrix();
   glDisable(GL_TEXTURE_2D);
}

void HotAirBalloon::drawSkyboxright(){
   glEnable(GL_TEXTURE_2D);
   glMatrixMode(GL_MODELVIEW);
   glPushMatrix();
   glDisable(GL_DEPTH_TEST);
   // Skybox는 다른 색상의 영향을 받으면 안되므로 DECAL
   glTexEnvf(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_DECAL);
   glColor3f(0,0,0);

   //right
   glBegin(GL_QUADS);
   glTexCoord2f(1.0, 1.0); glVertex3f(-TEX_SIZE,-TEX_SIZE,TEX_SIZE);
   glTexCoord2f(0.0, 1.0); glVertex3f(-TEX_SIZE,-TEX_SIZE,-TEX_SIZE);
   glTexCoord2f(0.0, 0.0); glVertex3f(-TEX_SIZE,TEX_SIZE,-TEX_SIZE);
   glTexCoord2f(1.0, 0.0); glVertex3f(-TEX_SIZE,TEX_SIZE,TEX_SIZE);
   glEnd();

   glEnable(GL_DEPTH_TEST);
   glPopMatrix();
   glDisable(GL_TEXTURE_2D);
}

void HotAirBalloon::drawSkyboxup(){
   glEnable(GL_TEXTURE_2D);
   glMatrixMode(GL_MODELVIEW);
   glPushMatrix();
   glDisable(GL_DEPTH_TEST);
   // Skybox는 다른 색상의 영향을 받으면 안되므로 DECAL
   glTexEnvf(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_DECAL);
   glColor3f(0,0,0);

   //up
   glBegin(GL_QUADS);
   glTexCoord2f(1.0, 1.0); glVertex3f(-TEX_SIZE,TEX_SIZE,-TEX_SIZE);
   glTexCoord2f(0.0, 1.0); glVertex3f(TEX_SIZE,TEX_SIZE,-TEX_SIZE);
   glTexCoord2f(0.0, 0.0); glVertex3f(TEX_SIZE,TEX_SIZE,TEX_SIZE);
   glTexCoord2f(1.0, 0.0); glVertex3f(-TEX_SIZE,TEX_SIZE,TEX_SIZE);
   glEnd();

   glEnable(GL_DEPTH_TEST);
   glPopMatrix();
   glDisable(GL_TEXTURE_2D);
}

void HotAirBalloon::drawSkyboxdown(){
   glEnable(GL_TEXTURE_2D);
   glMatrixMode(GL_MODELVIEW);
   glPushMatrix();
   glDisable(GL_DEPTH_TEST);
   // Skybox는 다른 색상의 영향을 받으면 안되므로 DECAL
   glTexEnvf(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_DECAL);
   glColor3f(0,0,0);

   //down
   glBegin(GL_QUADS);
   glTexCoord2f(1.0, 1.0); glVertex3f(-TEX_SIZE,-TEX_SIZE,TEX_SIZE);
   glTexCoord2f(0.0, 1.0); glVertex3f(TEX_SIZE,-TEX_SIZE,TEX_SIZE);
   glTexCoord2f(0.0, 0.0); glVertex3f(TEX_SIZE,-TEX_SIZE,-TEX_SIZE);
   glTexCoord2f(1.0, 0.0); glVertex3f(-TEX_SIZE,-TEX_SIZE,-TEX_SIZE);
   glEnd();

   glEnable(GL_DEPTH_TEST);
   glPopMatrix();
   glDisable(GL_TEXTURE_2D);
}

//이미지 들어가는 부분
void HotAirBalloon::HotBalloonTexture(double hotballoontexture_x,double hotballoontexture_y,double hotballoontexture_z){
   glEnable(GL_TEXTURE_2D);
   glMatrixMode(GL_MODELVIEW);
   glPushMatrix();
   glDisable(GL_DEPTH_TEST);
   glColor3f(1.0,1.0,1.0);

   glBegin(GL_POLYGON);
      glTexCoord2f(1.0, 1.0);glVertex3f(-0.4+balloonx-balloonscale,-2.1+hotballoontexture_y+balloony-balloonscale,0+hotballoontexture_z); //아래 왼
      glTexCoord2f(0.0, 1.0);glVertex3f(0.4+balloonx+balloonscale,-2.1+hotballoontexture_y+balloony-balloonscale,0+hotballoontexture_z); //아래 오
      glTexCoord2f(0.0, 0.0);glVertex3f(0.4+balloonx+balloonscale,-1.5+hotballoontexture_y+balloony+balloonscale,0+hotballoontexture_z); //위 오
      glTexCoord2f(1.0, 0.0);glVertex3f(-0.4+balloonx-balloonscale,-1.5+hotballoontexture_y+balloony+balloonscale,0+hotballoontexture_z); //위 왼
   glEnd();
   

   glEnable(GL_DEPTH_TEST);
   glPopMatrix();
   glDisable(GL_TEXTURE_2D);
}

void HotAirBalloon::HotBalloonLine(double HotBalloonLine_x,double HotBalloonLine_y,double HotBalloonLine_z) {
   
   glPushMatrix();
   glLineWidth(3);

   glBegin(GL_LINES);
      glColor3f(0.3,0.3,0.3);
      glVertex3f(0.4+HotBalloonLine_x+balloonx,0+HotBalloonLine_y+balloony,0+HotBalloonLine_z);
      glVertex3f(0.4+HotBalloonLine_x+balloonx,-1.5+HotBalloonLine_y+balloony,0+HotBalloonLine_z);
   glEnd();

   glBegin(GL_LINES);
      glColor3f(0.3,0.3,0.3);
      glVertex3f(0.4+HotBalloonLine_x+balloonx,0+HotBalloonLine_y+balloony,0.2+HotBalloonLine_z);
      glVertex3f(0.4+HotBalloonLine_x+balloonx,-1.5+HotBalloonLine_y+balloony,0+HotBalloonLine_z);
   glEnd();

   glBegin(GL_LINES);
      glColor3f(0.3,0.3,0.3);
      glVertex3f(-0.4+HotBalloonLine_x+balloonx,0+HotBalloonLine_y+balloony,0+HotBalloonLine_z);
      glVertex3f(-0.4+HotBalloonLine_x+balloonx,-1.5+HotBalloonLine_y+balloony,0+HotBalloonLine_z);
   glEnd();

   glBegin(GL_LINES);
      glColor3f(0.3,0.3,0.3);
      glVertex3f(-0.4+HotBalloonLine_x+balloonx,0+HotBalloonLine_y+balloony,0.2+HotBalloonLine_z);
      glVertex3f(-0.4+HotBalloonLine_x+balloonx,-1.5+HotBalloonLine_y+balloony,0+HotBalloonLine_z);
   glEnd();
   
   glPopMatrix();
}

void HotAirBalloon::HotBalloonSphere(double HotBalloonLine_x,double HotBalloonLine_y,double HotBalloonLine_z) {
   
   CMainFrame* pFrame = (CMainFrame*)AfxGetMainWnd();            //View호출
   CEditorCtrl* pEidt = pFrame->GetEditorCtrl();

   glMatrixMode(GL_MODELVIEW);
   glDisable(GL_DEPTH_TEST);

//   int bred = balloonred*100; //float -> int
//   pEidt->ChangeBalloonDlgTo(bred); //balloonred 값을 에디터창로 보냄
   
   
    GLfloat mat_specular[] = { 1.0, 1.0f, 1.0f, 1.0f }; //조명색
    GLfloat mat_diffuse[] =  { balloonred, balloongreen, balloonblue, 1.0f }; //공의 색
    GLfloat mat_emission[] = { balloonred/5, balloongreen/5, balloonblue/5, 0.1f }; //주변반사
    GLfloat mat_shininess[] = { 50.0 }; // 반사되어 비치는 정도 정반사조절 예를들면 유리, 코팅된플라스틱등
    GLfloat light_position[] = { 0.0f, 1.0f, -1.0f, 0.0f }; // 조명값지정 0.0은 동차좌표계(2이면 1.0 1.0 1.0이 각각 0.5가된다)
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular); //물질의재질
    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);//물질의재질
    glMaterialfv(GL_FRONT, GL_EMISSION, mat_emission);//물질의재질
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);//물질의재질
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);//조명의 특성 GL_LIGHT0는 0부터 7까지 사용가능
     
    glEnable(GL_LIGHT0);
   
    glEnable(GL_LIGHTING); //조명을 켜는것

   glPushMatrix();
      HotBalloonColor(balloonred, balloongreen, balloonblue);
      glTranslatef(HotBalloonLine_x+balloonx , HotBalloonLine_y+balloony,HotBalloonLine_z);
      glutSolidSphere(0.5+HotBalloonLine_x, 100+HotBalloonLine_y,150+HotBalloonLine_z); //구 크기
   glPopMatrix();
    glDisable(GL_LIGHT0);
    glDisable(GL_LIGHTING); //조명을 켜는것
}

//DarkStormy
//이미지 들어가는 부분
void HotAirBalloon::DarkHotBalloonTexture(double hotballoontexture_x,double hotballoontexture_y,double hotballoontexture_z){
   glEnable(GL_TEXTURE_2D);
   glMatrixMode(GL_MODELVIEW);
   glPushMatrix();
   glDisable(GL_DEPTH_TEST);
   glColor3f(1.0,1.0,1.0);

   glBegin(GL_POLYGON);
      glTexCoord2f(1.0, 1.0);glVertex3f(-0.4+darkstormyx-darkstormyscale,-2.1+hotballoontexture_y+darkstormyy-darkstormyscale,0+hotballoontexture_z); //아래 왼
      glTexCoord2f(0.0, 1.0);glVertex3f(0.4+darkstormyx+darkstormyscale,-2.1+hotballoontexture_y+darkstormyy-darkstormyscale,0+hotballoontexture_z); //아래 오
      glTexCoord2f(0.0, 0.0);glVertex3f(0.4+darkstormyx+darkstormyscale,-1.5+hotballoontexture_y+darkstormyy+darkstormyscale,0+hotballoontexture_z); //위 오
      glTexCoord2f(1.0, 0.0);glVertex3f(-0.4+darkstormyx-darkstormyscale,-1.5+hotballoontexture_y+darkstormyy+darkstormyscale,0+hotballoontexture_z); //위 왼
   glEnd();
   

   glEnable(GL_DEPTH_TEST);
   glPopMatrix();
   glDisable(GL_TEXTURE_2D);
}

void HotAirBalloon::DarkHotBalloonLine(double HotBalloonLine_x,double HotBalloonLine_y,double HotBalloonLine_z) {
   
   glPushMatrix();
   glLineWidth(3);

   glBegin(GL_LINES);
      glColor3f(0.3,0.3,0.3);
      glVertex3f(0.4+HotBalloonLine_x+darkstormyx,0+HotBalloonLine_y+darkstormyy,0+HotBalloonLine_z);
      glVertex3f(0.4+HotBalloonLine_x+darkstormyx,-1.5+HotBalloonLine_y+darkstormyy,0+HotBalloonLine_z);
   glEnd();

   glBegin(GL_LINES);
      glColor3f(0.3,0.3,0.3);
      glVertex3f(0.4+HotBalloonLine_x+darkstormyx,0+HotBalloonLine_y+darkstormyy,0.2+HotBalloonLine_z);
      glVertex3f(0.4+HotBalloonLine_x+darkstormyx,-1.5+HotBalloonLine_y+darkstormyy,0+HotBalloonLine_z);
   glEnd();

   glBegin(GL_LINES);
      glColor3f(0.3,0.3,0.3);
      glVertex3f(-0.4+HotBalloonLine_x+darkstormyx,0+HotBalloonLine_y+darkstormyy,0+HotBalloonLine_z);
      glVertex3f(-0.4+HotBalloonLine_x+darkstormyx,-1.5+HotBalloonLine_y+darkstormyy,0+HotBalloonLine_z);
   glEnd();

   glBegin(GL_LINES);
      glColor3f(0.3,0.3,0.3);
      glVertex3f(-0.4+HotBalloonLine_x+darkstormyx,0+HotBalloonLine_y+darkstormyy,0.2+HotBalloonLine_z);
      glVertex3f(-0.4+HotBalloonLine_x+darkstormyx,-1.5+HotBalloonLine_y+darkstormyy,0+HotBalloonLine_z);
   glEnd();
   
   glPopMatrix();
}

void HotAirBalloon::DarkHotBalloonSphere(double HotBalloonLine_x,double HotBalloonLine_y,double HotBalloonLine_z) {
   
   CMainFrame* pFrame = (CMainFrame*)AfxGetMainWnd();            //View호출
   CEditorCtrl* pEidt = pFrame->GetEditorCtrl();

   glMatrixMode(GL_MODELVIEW);
   glDisable(GL_DEPTH_TEST);

//   int bred = darkstormyred*100; //float -> int
//   pEidt->ChangeBalloonDlgTo(bred); //balloonred 값을 에디터창로 보냄
   
   
    GLfloat mat_specular[] = { 1.0, 1.0f, 1.0f, 1.0f }; //조명색
    GLfloat mat_diffuse[] =  { darkstormyred, darkstormygreen, darkstormyblue, 1.0f }; //공의 색
    GLfloat mat_emission[] = { darkstormyred/5, darkstormygreen/5, darkstormyblue/5, 0.1f }; //주변반사
    GLfloat mat_shininess[] = { 50.0 }; // 반사되어 비치는 정도 정반사조절 예를들면 유리, 코팅된플라스틱등
    GLfloat light_position[] = { 0.0f, 1.0f, -1.0f, 0.0f }; // 조명값지정 0.0은 동차좌표계(2이면 1.0 1.0 1.0이 각각 0.5가된다)
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular); //물질의재질
    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);//물질의재질
    glMaterialfv(GL_FRONT, GL_EMISSION, mat_emission);//물질의재질
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);//물질의재질
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);//조명의 특성 GL_LIGHT0는 0부터 7까지 사용가능
     
    glEnable(GL_LIGHT0);
   
    glEnable(GL_LIGHTING); //조명을 켜는것

   glPushMatrix();
      HotBalloonColor(darkstormyred, darkstormygreen, darkstormyblue);
      glTranslatef(HotBalloonLine_x+darkstormyx , HotBalloonLine_y+darkstormyy,HotBalloonLine_z);
      glutSolidSphere(0.5+HotBalloonLine_x, 100+HotBalloonLine_y,150+HotBalloonLine_z); //구 크기
   glPopMatrix();
    glDisable(GL_LIGHT0);
    glDisable(GL_LIGHTING); //조명을 켜는것
}

//Fullmoon

void HotAirBalloon::FullHotBalloonTexture(double hotballoontexture_x,double hotballoontexture_y,double hotballoontexture_z){
   glEnable(GL_TEXTURE_2D);
   glMatrixMode(GL_MODELVIEW);
   glPushMatrix();
   glDisable(GL_DEPTH_TEST);
   glColor3f(1.0,1.0,1.0);

   glBegin(GL_POLYGON);
      glTexCoord2f(1.0, 1.0);glVertex3f(-0.4+fullmoonx-fullmoonscale,-2.1+hotballoontexture_y+fullmoony-fullmoonscale,0+hotballoontexture_z); //아래 왼
      glTexCoord2f(0.0, 1.0);glVertex3f(0.4+fullmoonx+fullmoonscale,-2.1+hotballoontexture_y+fullmoony-fullmoonscale,0+hotballoontexture_z); //아래 오
      glTexCoord2f(0.0, 0.0);glVertex3f(0.4+fullmoonx+fullmoonscale,-1.5+hotballoontexture_y+fullmoony+fullmoonscale,0+hotballoontexture_z); //위 오
      glTexCoord2f(1.0, 0.0);glVertex3f(-0.4+fullmoonx-fullmoonscale,-1.5+hotballoontexture_y+fullmoony+fullmoonscale,0+hotballoontexture_z); //위 왼
   glEnd();
   

   glEnable(GL_DEPTH_TEST);
   glPopMatrix();
   glDisable(GL_TEXTURE_2D);
}

void HotAirBalloon::FullHotBalloonLine(double HotBalloonLine_x,double HotBalloonLine_y,double HotBalloonLine_z) {
   
   glPushMatrix();
   glLineWidth(3);

   glBegin(GL_LINES);
      glColor3f(0.3,0.3,0.3);
      glVertex3f(0.4+HotBalloonLine_x+fullmoonx,0+HotBalloonLine_y+fullmoony,0+HotBalloonLine_z);
      glVertex3f(0.4+HotBalloonLine_x+fullmoonx,-1.5+HotBalloonLine_y+fullmoony,0+HotBalloonLine_z);
   glEnd();

   glBegin(GL_LINES);
      glColor3f(0.3,0.3,0.3);
      glVertex3f(0.4+HotBalloonLine_x+fullmoonx,0+HotBalloonLine_y+fullmoony,0.2+HotBalloonLine_z);
      glVertex3f(0.4+HotBalloonLine_x+fullmoonx,-1.5+HotBalloonLine_y+fullmoony,0+HotBalloonLine_z);
   glEnd();

   glBegin(GL_LINES);
      glColor3f(0.3,0.3,0.3);
      glVertex3f(-0.4+HotBalloonLine_x+fullmoonx,0+HotBalloonLine_y+fullmoony,0+HotBalloonLine_z);
      glVertex3f(-0.4+HotBalloonLine_x+fullmoonx,-1.5+HotBalloonLine_y+fullmoony,0+HotBalloonLine_z);
   glEnd();

   glBegin(GL_LINES);
      glColor3f(0.3,0.3,0.3);
      glVertex3f(-0.4+HotBalloonLine_x+fullmoonx,0+HotBalloonLine_y+fullmoony,0.2+HotBalloonLine_z);
      glVertex3f(-0.4+HotBalloonLine_x+fullmoonx,-1.5+HotBalloonLine_y+fullmoony,0+HotBalloonLine_z);
   glEnd();
   
   glPopMatrix();
}

void HotAirBalloon::FullHotBalloonSphere(double HotBalloonLine_x,double HotBalloonLine_y,double HotBalloonLine_z) {
   
   CMainFrame* pFrame = (CMainFrame*)AfxGetMainWnd();            //View호출
   CEditorCtrl* pEidt = pFrame->GetEditorCtrl();

   glMatrixMode(GL_MODELVIEW);
   glDisable(GL_DEPTH_TEST);

//   int bred = fullmoonred*100; //float -> int
//   pEidt->ChangeBalloonDlgTo(bred); //balloonred 값을 에디터창로 보냄
   
   
    GLfloat mat_specular[] = { 1.0, 1.0f, 1.0f, 1.0f }; //조명색
    GLfloat mat_diffuse[] =  { fullmoonred, fullmoongreen, fullmoonblue, 1.0f }; //공의 색
    GLfloat mat_emission[] = { fullmoonred/5, fullmoongreen/5, fullmoonblue/5, 0.1f }; //주변반사
    GLfloat mat_shininess[] = { 50.0 }; // 반사되어 비치는 정도 정반사조절 예를들면 유리, 코팅된플라스틱등
    GLfloat light_position[] = { 0.0f, 1.0f, -1.0f, 0.0f }; // 조명값지정 0.0은 동차좌표계(2이면 1.0 1.0 1.0이 각각 0.5가된다)
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular); //물질의재질
    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);//물질의재질
    glMaterialfv(GL_FRONT, GL_EMISSION, mat_emission);//물질의재질
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);//물질의재질
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);//조명의 특성 GL_LIGHT0는 0부터 7까지 사용가능
     
    glEnable(GL_LIGHT0);
   
    glEnable(GL_LIGHTING); //조명을 켜는것

   glPushMatrix();
      HotBalloonColor(fullmoonred, fullmoongreen, fullmoonblue);
      glTranslatef(HotBalloonLine_x+fullmoonx , HotBalloonLine_y+fullmoony,HotBalloonLine_z);
      glutSolidSphere(0.5+HotBalloonLine_x, 100+HotBalloonLine_y,150+HotBalloonLine_z); //구 크기
   glPopMatrix();
    glDisable(GL_LIGHT0);
    glDisable(GL_LIGHTING); //조명을 켜는것
}

//mountain

void HotAirBalloon::MountHotBalloonTexture(double hotballoontexture_x,double hotballoontexture_y,double hotballoontexture_z){
   glEnable(GL_TEXTURE_2D);
   glMatrixMode(GL_MODELVIEW);
   glPushMatrix();
   glDisable(GL_DEPTH_TEST);
   glColor3f(1.0,1.0,1.0);

   glBegin(GL_POLYGON);
      glTexCoord2f(1.0, 1.0);glVertex3f(-0.4+mountx-mountscale,-2.1+hotballoontexture_y+mounty-mountscale,0+hotballoontexture_z); //아래 왼
      glTexCoord2f(0.0, 1.0);glVertex3f(0.4+mountx+mountscale,-2.1+hotballoontexture_y+mounty-mountscale,0+hotballoontexture_z); //아래 오
      glTexCoord2f(0.0, 0.0);glVertex3f(0.4+mountx+mountscale,-1.5+hotballoontexture_y+mounty+mountscale,0+hotballoontexture_z); //위 오
      glTexCoord2f(1.0, 0.0);glVertex3f(-0.4+mountx-mountscale,-1.5+hotballoontexture_y+mounty+mountscale,0+hotballoontexture_z); //위 왼
   glEnd();
   

   glEnable(GL_DEPTH_TEST);
   glPopMatrix();
   glDisable(GL_TEXTURE_2D);
}

void HotAirBalloon::MountHotBalloonLine(double HotBalloonLine_x,double HotBalloonLine_y,double HotBalloonLine_z) {
   
   glPushMatrix();
   glLineWidth(3);

   glBegin(GL_LINES);
      glColor3f(0.3,0.3,0.3);
      glVertex3f(0.4+HotBalloonLine_x+mountx,0+HotBalloonLine_y+mounty,0+HotBalloonLine_z);
      glVertex3f(0.4+HotBalloonLine_x+mountx,-1.5+HotBalloonLine_y+mounty,0+HotBalloonLine_z);
   glEnd();

   glBegin(GL_LINES);
      glColor3f(0.3,0.3,0.3);
      glVertex3f(0.4+HotBalloonLine_x+mountx,0+HotBalloonLine_y+mounty,0.2+HotBalloonLine_z);
      glVertex3f(0.4+HotBalloonLine_x+mountx,-1.5+HotBalloonLine_y+mounty,0+HotBalloonLine_z);
   glEnd();

   glBegin(GL_LINES);
      glColor3f(0.3,0.3,0.3);
      glVertex3f(-0.4+HotBalloonLine_x+mountx,0+HotBalloonLine_y+mounty,0+HotBalloonLine_z);
      glVertex3f(-0.4+HotBalloonLine_x+mountx,-1.5+HotBalloonLine_y+mounty,0+HotBalloonLine_z);
   glEnd();

   glBegin(GL_LINES);
      glColor3f(0.3,0.3,0.3);
      glVertex3f(-0.4+HotBalloonLine_x+mountx,0+HotBalloonLine_y+mounty,0.2+HotBalloonLine_z);
      glVertex3f(-0.4+HotBalloonLine_x+mountx,-1.5+HotBalloonLine_y+mounty,0+HotBalloonLine_z);
   glEnd();
   
   glPopMatrix();
}

void HotAirBalloon::MountHotBalloonSphere(double HotBalloonLine_x,double HotBalloonLine_y,double HotBalloonLine_z) {
   
   CMainFrame* pFrame = (CMainFrame*)AfxGetMainWnd();            //View호출
   CEditorCtrl* pEidt = pFrame->GetEditorCtrl();

   glMatrixMode(GL_MODELVIEW);
   glDisable(GL_DEPTH_TEST);

//   int bred = mountred*100; //float -> int
//   pEidt->ChangeBalloonDlgTo(bred); //balloonred 값을 에디터창로 보냄
   
   
    GLfloat mat_specular[] = { 1.0, 1.0f, 1.0f, 1.0f }; //조명색
    GLfloat mat_diffuse[] =  { mountred, mountgreen, mountblue, 1.0f }; //공의 색
    GLfloat mat_emission[] = { mountred/5, mountgreen/5, mountblue/5, 0.1f }; //주변반사
    GLfloat mat_shininess[] = { 50.0 }; // 반사되어 비치는 정도 정반사조절 예를들면 유리, 코팅된플라스틱등
    GLfloat light_position[] = { 0.0f, 1.0f, -1.0f, 0.0f }; // 조명값지정 0.0은 동차좌표계(2이면 1.0 1.0 1.0이 각각 0.5가된다)
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular); //물질의재질
    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);//물질의재질
    glMaterialfv(GL_FRONT, GL_EMISSION, mat_emission);//물질의재질
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);//물질의재질
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);//조명의 특성 GL_LIGHT0는 0부터 7까지 사용가능
     
    glEnable(GL_LIGHT0);
   
    glEnable(GL_LIGHTING); //조명을 켜는것

   glPushMatrix();
      HotBalloonColor(mountred, mountgreen, mountblue);
      glTranslatef(HotBalloonLine_x+mountx , HotBalloonLine_y+mounty,HotBalloonLine_z);
      glutSolidSphere(0.5+HotBalloonLine_x, 100+HotBalloonLine_y,150+HotBalloonLine_z); //구 크기
   glPopMatrix();
    glDisable(GL_LIGHT0);
    glDisable(GL_LIGHTING); //조명을 켜는것
}

//sunset

void HotAirBalloon::SunsetHotBalloonTexture(double hotballoontexture_x,double hotballoontexture_y,double hotballoontexture_z){
   glEnable(GL_TEXTURE_2D);
   glMatrixMode(GL_MODELVIEW);
   glPushMatrix();
   glDisable(GL_DEPTH_TEST);
   glColor3f(1.0,1.0,1.0);

   glBegin(GL_POLYGON);
      glTexCoord2f(1.0, 1.0);glVertex3f(-0.4+sunsetx-sunsetscale,-2.1+hotballoontexture_y+sunsety-sunsetscale,0+hotballoontexture_z); //아래 왼
      glTexCoord2f(0.0, 1.0);glVertex3f(0.4+sunsetx+sunsetscale,-2.1+hotballoontexture_y+sunsety-sunsetscale,0+hotballoontexture_z); //아래 오
      glTexCoord2f(0.0, 0.0);glVertex3f(0.4+sunsetx+sunsetscale,-1.5+hotballoontexture_y+sunsety+sunsetscale,0+hotballoontexture_z); //위 오
      glTexCoord2f(1.0, 0.0);glVertex3f(-0.4+sunsetx-sunsetscale,-1.5+hotballoontexture_y+sunsety+sunsetscale,0+hotballoontexture_z); //위 왼
   glEnd();
   

   glEnable(GL_DEPTH_TEST);
   glPopMatrix();
   glDisable(GL_TEXTURE_2D);
}

void HotAirBalloon::SunsetHotBalloonLine(double HotBalloonLine_x,double HotBalloonLine_y,double HotBalloonLine_z) {
   
   glPushMatrix();
   glLineWidth(3);

   glBegin(GL_LINES);
      glColor3f(0.3,0.3,0.3);
      glVertex3f(0.4+HotBalloonLine_x+sunsetx,0+HotBalloonLine_y+sunsety,0+HotBalloonLine_z);
      glVertex3f(0.4+HotBalloonLine_x+sunsetx,-1.5+HotBalloonLine_y+sunsety,0+HotBalloonLine_z);
   glEnd();

   glBegin(GL_LINES);
      glColor3f(0.3,0.3,0.3);
      glVertex3f(0.4+HotBalloonLine_x+sunsetx,0+HotBalloonLine_y+sunsety,0.2+HotBalloonLine_z);
      glVertex3f(0.4+HotBalloonLine_x+sunsetx,-1.5+HotBalloonLine_y+sunsety,0+HotBalloonLine_z);
   glEnd();

   glBegin(GL_LINES);
      glColor3f(0.3,0.3,0.3);
      glVertex3f(-0.4+HotBalloonLine_x+sunsetx,0+HotBalloonLine_y+sunsety,0+HotBalloonLine_z);
      glVertex3f(-0.4+HotBalloonLine_x+sunsetx,-1.5+HotBalloonLine_y+sunsety,0+HotBalloonLine_z);
   glEnd();

   glBegin(GL_LINES);
      glColor3f(0.3,0.3,0.3);
      glVertex3f(-0.4+HotBalloonLine_x+sunsetx,0+HotBalloonLine_y+sunsety,0.2+HotBalloonLine_z);
      glVertex3f(-0.4+HotBalloonLine_x+sunsetx,-1.5+HotBalloonLine_y+sunsety,0+HotBalloonLine_z);
   glEnd();
   
   glPopMatrix();
}


void HotAirBalloon::SunsetHotBalloonSphere(double HotBalloonLine_x,double HotBalloonLine_y,double HotBalloonLine_z) {
   
   CMainFrame* pFrame = (CMainFrame*)AfxGetMainWnd();            //View호출
   CEditorCtrl* pEidt = pFrame->GetEditorCtrl();

   glMatrixMode(GL_MODELVIEW);
   glDisable(GL_DEPTH_TEST);

//   int bred = sunsetred*100; //float -> int
//   pEidt->ChangeBalloonDlgTo(bred); //balloonred 값을 에디터창로 보냄
   
   
    GLfloat mat_specular[] = { 1.0, 1.0f, 1.0f, 1.0f }; //조명색
    GLfloat mat_diffuse[] =  { sunsetred, sunsetgreen, sunsetblue, 1.0f }; //공의 색
    GLfloat mat_emission[] = { sunsetred/5, sunsetgreen/5, sunsetblue/5, 0.1f }; //주변반사
    GLfloat mat_shininess[] = { 50.0 }; // 반사되어 비치는 정도 정반사조절 예를들면 유리, 코팅된플라스틱등
    GLfloat light_position[] = { 0.0f, 1.0f, -1.0f, 0.0f }; // 조명값지정 0.0은 동차좌표계(2이면 1.0 1.0 1.0이 각각 0.5가된다)
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular); //물질의재질
    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);//물질의재질
    glMaterialfv(GL_FRONT, GL_EMISSION, mat_emission);//물질의재질
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);//물질의재질
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);//조명의 특성 GL_LIGHT0는 0부터 7까지 사용가능
     
    glEnable(GL_LIGHT0);
   
    glEnable(GL_LIGHTING); //조명을 켜는것

   glPushMatrix();
      HotBalloonColor(sunsetred, sunsetgreen, sunsetblue);
      glTranslatef(HotBalloonLine_x+sunsetx , HotBalloonLine_y+sunsety,HotBalloonLine_z);
      glutSolidSphere(0.5+HotBalloonLine_x, 100+HotBalloonLine_y,150+HotBalloonLine_z); //구 크기
   glPopMatrix();
    glDisable(GL_LIGHT0);
    glDisable(GL_LIGHTING); //조명을 켜는것
}

//clouds 

void HotAirBalloon::CloudsHotBalloonTexture(double hotballoontexture_x,double hotballoontexture_y,double hotballoontexture_z){
   glEnable(GL_TEXTURE_2D);
   glMatrixMode(GL_MODELVIEW);
   glPushMatrix();
   glDisable(GL_DEPTH_TEST);
   glColor3f(1.0,1.0,1.0);

   glBegin(GL_POLYGON);
      glTexCoord2f(1.0, 1.0);glVertex3f(-0.4+cloudsx-cloudsscale,-2.1+hotballoontexture_y+cloudsy-cloudsscale,0+hotballoontexture_z); //아래 왼
      glTexCoord2f(0.0, 1.0);glVertex3f(0.4+cloudsx+cloudsscale,-2.1+hotballoontexture_y+cloudsy-cloudsscale,0+hotballoontexture_z); //아래 오
      glTexCoord2f(0.0, 0.0);glVertex3f(0.4+cloudsx+cloudsscale,-1.5+hotballoontexture_y+cloudsy+cloudsscale,0+hotballoontexture_z); //위 오
      glTexCoord2f(1.0, 0.0);glVertex3f(-0.4+cloudsx-cloudsscale,-1.5+hotballoontexture_y+cloudsy+cloudsscale,0+hotballoontexture_z); //위 왼
   glEnd();
   

   glEnable(GL_DEPTH_TEST);
   glPopMatrix();
   glDisable(GL_TEXTURE_2D);
}

void HotAirBalloon::CloudsHotBalloonLine(double HotBalloonLine_x,double HotBalloonLine_y,double HotBalloonLine_z) {
   
   glPushMatrix();
   glLineWidth(3);

   glBegin(GL_LINES);
      glColor3f(0.3,0.3,0.3);
      glVertex3f(0.4+HotBalloonLine_x+cloudsx,0+HotBalloonLine_y+cloudsy,0+HotBalloonLine_z);
      glVertex3f(0.4+HotBalloonLine_x+cloudsx,-1.5+HotBalloonLine_y+cloudsy,0+HotBalloonLine_z);
   glEnd();

   glBegin(GL_LINES);
      glColor3f(0.3,0.3,0.3);
      glVertex3f(0.4+HotBalloonLine_x+cloudsx,0+HotBalloonLine_y+cloudsy,0.2+HotBalloonLine_z);
      glVertex3f(0.4+HotBalloonLine_x+cloudsx,-1.5+HotBalloonLine_y+cloudsy,0+HotBalloonLine_z);
   glEnd();

   glBegin(GL_LINES);
      glColor3f(0.3,0.3,0.3);
      glVertex3f(-0.4+HotBalloonLine_x+cloudsx,0+HotBalloonLine_y+cloudsy,0+HotBalloonLine_z);
      glVertex3f(-0.4+HotBalloonLine_x+cloudsx,-1.5+HotBalloonLine_y+cloudsy,0+HotBalloonLine_z);
   glEnd();

   glBegin(GL_LINES);
      glColor3f(0.3,0.3,0.3);
      glVertex3f(-0.4+HotBalloonLine_x+cloudsx,0+HotBalloonLine_y+cloudsy,0.2+HotBalloonLine_z);
      glVertex3f(-0.4+HotBalloonLine_x+cloudsx,-1.5+HotBalloonLine_y+cloudsy,0+HotBalloonLine_z);
   glEnd();
   
   glPopMatrix();
}

void HotAirBalloon::CloudsHotBalloonSphere(double HotBalloonLine_x,double HotBalloonLine_y,double HotBalloonLine_z) {
   
   CMainFrame* pFrame = (CMainFrame*)AfxGetMainWnd();            //View호출
   CEditorCtrl* pEidt = pFrame->GetEditorCtrl();

   glMatrixMode(GL_MODELVIEW);
   glDisable(GL_DEPTH_TEST);

//   int bred = cloudsred*100; //float -> int
//   pEidt->ChangeBalloonDlgTo(bred); //balloonred 값을 에디터창로 보냄
   
   
    GLfloat mat_specular[] = { 1.0, 1.0f, 1.0f, 1.0f }; //조명색
    GLfloat mat_diffuse[] =  { cloudsred, cloudsgreen, cloudsblue, 1.0f }; //공의 색
    GLfloat mat_emission[] = { cloudsred/5, cloudsgreen/5, cloudsblue/5, 0.1f }; //주변반사
    GLfloat mat_shininess[] = { 50.0 }; // 반사되어 비치는 정도 정반사조절 예를들면 유리, 코팅된플라스틱등
    GLfloat light_position[] = { 0.0f, 1.0f, -1.0f, 0.0f }; // 조명값지정 0.0은 동차좌표계(2이면 1.0 1.0 1.0이 각각 0.5가된다)
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular); //물질의재질
    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);//물질의재질
    glMaterialfv(GL_FRONT, GL_EMISSION, mat_emission);//물질의재질
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);//물질의재질
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);//조명의 특성 GL_LIGHT0는 0부터 7까지 사용가능
     
    glEnable(GL_LIGHT0);
   
    glEnable(GL_LIGHTING); //조명을 켜는것

   glPushMatrix();
      HotBalloonColor(cloudsred, cloudsgreen, cloudsblue);
      glTranslatef(HotBalloonLine_x+cloudsx , HotBalloonLine_y+cloudsy,HotBalloonLine_z);
      glutSolidSphere(0.5+HotBalloonLine_x, 100+HotBalloonLine_y,150+HotBalloonLine_z); //구 크기
   glPopMatrix();
    glDisable(GL_LIGHT0);
    glDisable(GL_LIGHTING); //조명을 켜는것
}


//tropical


void HotAirBalloon::TropicalHotBalloonTexture(double hotballoontexture_x,double hotballoontexture_y,double hotballoontexture_z){
   glEnable(GL_TEXTURE_2D);
   glMatrixMode(GL_MODELVIEW);
   glPushMatrix();
   glDisable(GL_DEPTH_TEST);
   glColor3f(1.0,1.0,1.0);

   glBegin(GL_POLYGON);
      glTexCoord2f(1.0, 1.0);glVertex3f(-0.4+tropicalx-tropicalscale,-2.1+hotballoontexture_y+tropicaly-tropicalscale,0+hotballoontexture_z); //아래 왼
      glTexCoord2f(0.0, 1.0);glVertex3f(0.4+tropicalx+tropicalscale,-2.1+hotballoontexture_y+tropicaly-tropicalscale,0+hotballoontexture_z); //아래 오
      glTexCoord2f(0.0, 0.0);glVertex3f(0.4+tropicalx+tropicalscale,-1.5+hotballoontexture_y+tropicaly+tropicalscale,0+hotballoontexture_z); //위 오
      glTexCoord2f(1.0, 0.0);glVertex3f(-0.4+tropicalx-tropicalscale,-1.5+hotballoontexture_y+tropicaly+tropicalscale,0+hotballoontexture_z); //위 왼
   glEnd();
   

   glEnable(GL_DEPTH_TEST);
   glPopMatrix();
   glDisable(GL_TEXTURE_2D);
}

void HotAirBalloon::TropicalHotBalloonLine(double HotBalloonLine_x,double HotBalloonLine_y,double HotBalloonLine_z) {
   
   glPushMatrix();
   glLineWidth(3);

   glBegin(GL_LINES);
      glColor3f(0.3,0.3,0.3);
      glVertex3f(0.4+HotBalloonLine_x+tropicalx,0+HotBalloonLine_y+tropicaly,0+HotBalloonLine_z);
      glVertex3f(0.4+HotBalloonLine_x+tropicalx,-1.5+HotBalloonLine_y+tropicaly,0+HotBalloonLine_z);
   glEnd();

   glBegin(GL_LINES);
      glColor3f(0.3,0.3,0.3);
      glVertex3f(0.4+HotBalloonLine_x+tropicalx,0+HotBalloonLine_y+tropicaly,0.2+HotBalloonLine_z);
      glVertex3f(0.4+HotBalloonLine_x+tropicalx,-1.5+HotBalloonLine_y+tropicaly,0+HotBalloonLine_z);
   glEnd();

   glBegin(GL_LINES);
      glColor3f(0.3,0.3,0.3);
      glVertex3f(-0.4+HotBalloonLine_x+tropicalx,0+HotBalloonLine_y+tropicaly,0+HotBalloonLine_z);
      glVertex3f(-0.4+HotBalloonLine_x+tropicalx,-1.5+HotBalloonLine_y+tropicaly,0+HotBalloonLine_z);
   glEnd();

   glBegin(GL_LINES);
      glColor3f(0.3,0.3,0.3);
      glVertex3f(-0.4+HotBalloonLine_x+tropicalx,0+HotBalloonLine_y+tropicaly,0.2+HotBalloonLine_z);
      glVertex3f(-0.4+HotBalloonLine_x+tropicalx,-1.5+HotBalloonLine_y+tropicaly,0+HotBalloonLine_z);
   glEnd();
   
   glPopMatrix();
}

void HotAirBalloon::TropicalHotBalloonSphere(double HotBalloonLine_x,double HotBalloonLine_y,double HotBalloonLine_z) {
   
   CMainFrame* pFrame = (CMainFrame*)AfxGetMainWnd();            //View호출
   CEditorCtrl* pEidt = pFrame->GetEditorCtrl();

   glMatrixMode(GL_MODELVIEW);
   glDisable(GL_DEPTH_TEST);

//   int bred = tropicalred*100; //float -> int
//   pEidt->ChangeBalloonDlgTo(bred); //balloonred 값을 에디터창로 보냄
   
   glPushMatrix();
   
    GLfloat mat_specular[] = { 1.0, 1.0f, 1.0f, 1.0f }; //조명색
    GLfloat mat_diffuse[] =  { tropicalred, tropicalgreen, tropicalblue, 1.0f }; //공의 색
    GLfloat mat_emission[] = { tropicalred/5, tropicalgreen/5, tropicalblue/5, 0.1f }; //주변반사
    GLfloat mat_shininess[] = { 50.0 }; // 반사되어 비치는 정도 정반사조절 예를들면 유리, 코팅된플라스틱등
    GLfloat light_position[] = { 0.0f, 1.0f, -1.0f, 0.0f }; // 조명값지정 0.0은 동차좌표계(2이면 1.0 1.0 1.0이 각각 0.5가된다)
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular); //물질의재질
    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);//물질의재질
    glMaterialfv(GL_FRONT, GL_EMISSION, mat_emission);//물질의재질
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);//물질의재질
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);//조명의 특성 GL_LIGHT0는 0부터 7까지 사용가능
     
    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHTING); //조명을 켜는것

      HotBalloonColor(tropicalred, tropicalgreen, tropicalblue);
      glTranslatef(HotBalloonLine_x+tropicalx , HotBalloonLine_y+tropicaly,HotBalloonLine_z);
      glutSolidSphere(0.5+HotBalloonLine_x, 100+HotBalloonLine_y,150+HotBalloonLine_z); //구 크기
   glPopMatrix();
   
    glDisable(GL_LIGHT0);
    glDisable(GL_LIGHTING); //조명을 켜는것
}




//풍선색 함수   
void HotAirBalloon::HotBalloonColor(double airballoonred, double airballoongreen, double airballoonblue) {
   
   glColor3f(airballoonred,airballoongreen,airballoonblue); // 풍선색

}
   

BEGIN_MESSAGE_MAP(HotAirBalloon, CWnd)
END_MESSAGE_MAP()



// HotAirBalloon 메시지 처리기입니다.

