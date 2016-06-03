// Film.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "Makory.h"
#include "Film.h"
#include "MainFrm.h"
#include "MakoryDoc.h"
#include "MakoryView.h"


// Film

IMPLEMENT_DYNAMIC(Film, CWnd)

	Film::Film()
{
	

	FilmScale=2.5;
	SlateScale=3;
	ProjectorScale=2;
	Projector1Scale=0.2;

	filmred=1.0;
	filmgreen=1.0;
	filmblue=1.0;

	slatered=1.0;
	slategreen=1.0;
	slateblue=1.0;
	
	slatered2=1.0;
	slategreen2=1.0;
	slateblue2=0.0;

	slatex=0.0;
	slatey=0.0;
	
	slatex2=0.0;
	slatey2=0.0;

	projred=1.0;
	projgreen=1.0;
	projblue=1.0;

	projx=0.0;
	projy=0.0;

	filmimgscale=0.0;
}

Film::~Film()
{
}


BEGIN_MESSAGE_MAP(Film, CWnd)
END_MESSAGE_MAP()



// Film 메시지 처리기입니다.


void Film::FilmCenter2(double filmcenter2_x,double filmcenter2_y, double filmcenter2_r, double filmcenter2_g, double filmcenter2_b){

	glEnable(GL_TEXTURE_2D);
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glColor3f(filmred,filmgreen,filmblue);
	//glColor3f(filmcenter2_r,filmcenter2_g,filmcenter2_b);
	glScalef(FilmScale,FilmScale,FilmScale);
	glTranslatef(5,0,0);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0, 0.069); glVertex2f(0.25+filmcenter2_x+filmimgscale,0.74+filmcenter2_y+filmimgscale);
	glTexCoord2f(0.0, 0.931); glVertex2f(0.25+filmcenter2_x+filmimgscale,0.26+filmcenter2_y-filmimgscale);
	glTexCoord2f(0.09, 1.0); glVertex2f(0.2+filmcenter2_x+filmimgscale,0.21+filmcenter2_y-filmimgscale);
	glTexCoord2f(0.91, 1.0); glVertex2f(-0.25+filmcenter2_x-filmimgscale,0.21+filmcenter2_y-filmimgscale);

	glTexCoord2f(1.0, 0.931); glVertex2f(-0.3+filmcenter2_x-filmimgscale,0.26+filmcenter2_y-filmimgscale);
	glTexCoord2f(1.0, 0.069); glVertex2f(-0.3+filmcenter2_x-filmimgscale,0.74+filmcenter2_y+filmimgscale);
	glTexCoord2f(0.91, 0.0); glVertex2f(-0.25+filmcenter2_x-filmimgscale,0.79+filmcenter2_y+filmimgscale);
	glTexCoord2f(0.09, 0.0); glVertex2f(0.2+filmcenter2_x+filmimgscale,0.79+filmcenter2_y+filmimgscale);
	glEnd();

	glEnable(GL_DEPTH_TEST);
	glPopMatrix();
	glDisable(GL_TEXTURE_2D);
}


void Film::FilmBody(double filmbody_x,double filmbody_y){



	glPushMatrix();
	//glColor3f(1,1,1);
	glColor3f(filmred,filmgreen,filmblue);
	glScalef(FilmScale,FilmScale,FilmScale);

	glTranslatef(-0.51,0,0);
	glBegin(GL_POLYGON);
	glVertex2f(1+filmbody_x,0.2+filmbody_y);				//테두리
	glVertex2f(1+filmbody_x,0.8+filmbody_y);
	glVertex2f(1.3+filmbody_x,0.8+filmbody_y);
	glVertex2f(1.3+filmbody_x,0.5+filmbody_y);
	glVertex2f(1.2+filmbody_x,0.5+filmbody_y);
	glVertex2f(1.2+filmbody_x,0.2+filmbody_y);
	glEnd();
	glPopMatrix();


	//여기까지 필름 오른쪽

	glPushMatrix();
	//glColor3f(1,1,1);
	glColor3f(filmred,filmgreen,filmblue);
	glScalef(FilmScale,FilmScale,FilmScale);
	glTranslatef(0.55,0,0);
	glBegin(GL_POLYGON);
	glVertex2f(-1+filmbody_x,0.2+filmbody_y);				//테두리
	glVertex2f(-1+filmbody_x,0.8+filmbody_y);
	glVertex2f(-1.3+filmbody_x,0.8+filmbody_y);
	glVertex2f(-1.3+filmbody_x,0.5+filmbody_y);
	glVertex2f(-1.2+filmbody_x,0.5+filmbody_y);
	glVertex2f(-1.2+filmbody_x,0.2+filmbody_y);
	glEnd();
	glPopMatrix();

	//여기까지 필름 왼쪽

	glPushMatrix();
	//glColor3f(1,1,1);
	glColor3f(filmred,filmgreen,filmblue);
	glScalef(FilmScale,FilmScale,FilmScale);
	glBegin(GL_POLYGON);
	glVertex2f(0.5+filmbody_x,0.2+filmbody_y);				//테두리
	glVertex2f(0.5+filmbody_x,0.8+filmbody_y);
	glVertex2f(-0.5+filmbody_x,0.8+filmbody_y);
	glVertex2f(-0.5+filmbody_x,0.2+filmbody_y);
	glEnd();
	glPopMatrix();


	glPushMatrix();
	//glColor3f(1,1,1);
	glColor3f(filmred,filmgreen,filmblue);
	glScalef(FilmScale,FilmScale,FilmScale);
	glTranslatef(-0.05,0,0);
	glBegin(GL_POLYGON);
	glVertex2f(0.74+filmbody_x,0.1+filmbody_y);				//필름 작은사각형
	glVertex2f(0.74+filmbody_x,0.18+filmbody_y);
	glVertex2f(0.66+filmbody_x,0.18+filmbody_y);
	glVertex2f(0.66+filmbody_x,0.1+filmbody_y);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	//glColor3f(1,1,1);
	glColor3f(filmred,filmgreen,filmblue);
	glScalef(FilmScale,FilmScale,FilmScale);
	glTranslatef(-0.19,0,0);
	glBegin(GL_POLYGON);
	glVertex2f(0.74+filmbody_x,0.1+filmbody_y);				//필름 작은사각형
	glVertex2f(0.74+filmbody_x,0.18+filmbody_y);
	glVertex2f(0.66+filmbody_x,0.18+filmbody_y);
	glVertex2f(0.66+filmbody_x,0.1+filmbody_y);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	//glColor3f(1,1,1);
	glColor3f(filmred,filmgreen,filmblue);
	glScalef(FilmScale,FilmScale,FilmScale);
	glTranslatef(-0.33,0,0);
	glBegin(GL_POLYGON);
	glVertex2f(0.74+filmbody_x,0.1+filmbody_y);				//필름 작은사각형
	glVertex2f(0.74+filmbody_x,0.18+filmbody_y);
	glVertex2f(0.66+filmbody_x,0.18+filmbody_y);
	glVertex2f(0.66+filmbody_x,0.1+filmbody_y);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	//glColor3f(1,1,1);
	glColor3f(filmred,filmgreen,filmblue);
	glScalef(FilmScale,FilmScale,FilmScale);
	glTranslatef(-0.47,0,0);
	glBegin(GL_POLYGON);
	glVertex2f(0.74+filmbody_x,0.1+filmbody_y);				//필름 작은사각형
	glVertex2f(0.74+filmbody_x,0.18+filmbody_y);
	glVertex2f(0.66+filmbody_x,0.18+filmbody_y);
	glVertex2f(0.66+filmbody_x,0.1+filmbody_y);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	//glColor3f(1,1,1);
	glColor3f(filmred,filmgreen,filmblue);
	glScalef(FilmScale,FilmScale,FilmScale);
	glTranslatef(-0.61,0,0);
	glBegin(GL_POLYGON);
	glVertex2f(0.74+filmbody_x,0.1+filmbody_y);				//필름 작은사각형
	glVertex2f(0.74+filmbody_x,0.18+filmbody_y);
	glVertex2f(0.66+filmbody_x,0.18+filmbody_y);
	glVertex2f(0.66+filmbody_x,0.1+filmbody_y);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	//glColor3f(1,1,1);
	glColor3f(filmred,filmgreen,filmblue);
	glScalef(FilmScale,FilmScale,FilmScale);
	glTranslatef(-0.75,0,0);
	glBegin(GL_POLYGON);
	glVertex2f(0.74+filmbody_x,0.1+filmbody_y);				//필름 작은사각형
	glVertex2f(0.74+filmbody_x,0.18+filmbody_y);
	glVertex2f(0.66+filmbody_x,0.18+filmbody_y);
	glVertex2f(0.66+filmbody_x,0.1+filmbody_y);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	//glColor3f(1,1,1);
	glColor3f(filmred,filmgreen,filmblue);
	glScalef(FilmScale,FilmScale,FilmScale);
	glTranslatef(-0.89,0,0);
	glBegin(GL_POLYGON);
	glVertex2f(0.74+filmbody_x,0.1+filmbody_y);				//필름 작은사각형
	glVertex2f(0.74+filmbody_x,0.18+filmbody_y);
	glVertex2f(0.66+filmbody_x,0.18+filmbody_y);
	glVertex2f(0.66+filmbody_x,0.1+filmbody_y);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	//glColor3f(1,1,1);
	glColor3f(filmred,filmgreen,filmblue);
	glScalef(FilmScale,FilmScale,FilmScale);
	glTranslatef(-1.03,0,0);
	glBegin(GL_POLYGON);
	glVertex2f(0.74+filmbody_x,0.1+filmbody_y);				//필름 작은사각형
	glVertex2f(0.74+filmbody_x,0.18+filmbody_y);
	glVertex2f(0.66+filmbody_x,0.18+filmbody_y);
	glVertex2f(0.66+filmbody_x,0.1+filmbody_y);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	//glColor3f(1,1,1);
	glColor3f(filmred,filmgreen,filmblue);
	glScalef(FilmScale,FilmScale,FilmScale);
	glTranslatef(-1.17,0,0);
	glBegin(GL_POLYGON);
	glVertex2f(0.74+filmbody_x,0.1+filmbody_y);				//필름 작은사각형
	glVertex2f(0.74+filmbody_x,0.18+filmbody_y);
	glVertex2f(0.66+filmbody_x,0.18+filmbody_y);
	glVertex2f(0.66+filmbody_x,0.1+filmbody_y);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	//glColor3f(1,1,1);
	glColor3f(filmred,filmgreen,filmblue);
	glScalef(FilmScale,FilmScale,FilmScale);
	glTranslatef(-1.31,0,0);
	glBegin(GL_POLYGON);
	glVertex2f(0.74+filmbody_x,0.1+filmbody_y);				//필름 작은사각형
	glVertex2f(0.74+filmbody_x,0.18+filmbody_y);
	glVertex2f(0.66+filmbody_x,0.18+filmbody_y);
	glVertex2f(0.66+filmbody_x,0.1+filmbody_y);
	glEnd();
	glPopMatrix();


	
	//여기까지 아래 필름 작은사각형

	glPushMatrix();
	//glColor3f(1,1,1);
	glColor3f(filmred,filmgreen,filmblue);
	glScalef(FilmScale,FilmScale,FilmScale);
	glTranslatef(0.1,0.72,0);
	glBegin(GL_POLYGON);
	glVertex2f(0.7+filmbody_x,0.1+filmbody_y);				//필름 작은사각형
	glVertex2f(0.7+filmbody_x,0.18+filmbody_y);
	glVertex2f(0.66+filmbody_x,0.18+filmbody_y);
	glVertex2f(0.66+filmbody_x,0.1+filmbody_y);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	//glColor3f(1,1,1);
	glColor3f(filmred,filmgreen,filmblue);
	glScalef(FilmScale,FilmScale,FilmScale);
	glTranslatef(-0.05,0.72,0);
	glBegin(GL_POLYGON);
	glVertex2f(0.74+filmbody_x,0.1+filmbody_y);				//필름 작은사각형
	glVertex2f(0.74+filmbody_x,0.18+filmbody_y);
	glVertex2f(0.66+filmbody_x,0.18+filmbody_y);
	glVertex2f(0.66+filmbody_x,0.1+filmbody_y);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	//glColor3f(1,1,1);
	glColor3f(filmred,filmgreen,filmblue);
	glScalef(FilmScale,FilmScale,FilmScale);
	glTranslatef(-0.2,0.72,0);
	glBegin(GL_POLYGON);
	glVertex2f(0.74+filmbody_x,0.1+filmbody_y);				//필름 작은사각형
	glVertex2f(0.74+filmbody_x,0.18+filmbody_y);
	glVertex2f(0.66+filmbody_x,0.18+filmbody_y);
	glVertex2f(0.66+filmbody_x,0.1+filmbody_y);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	//glColor3f(1,1,1);
	glColor3f(filmred,filmgreen,filmblue);
	glScalef(FilmScale,FilmScale,FilmScale);
	glTranslatef(-0.35,0.72,0);
	glBegin(GL_POLYGON);
	glVertex2f(0.74+filmbody_x,0.1+filmbody_y);				//필름 작은사각형
	glVertex2f(0.74+filmbody_x,0.18+filmbody_y);
	glVertex2f(0.66+filmbody_x,0.18+filmbody_y);
	glVertex2f(0.66+filmbody_x,0.1+filmbody_y);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	//glColor3f(1,1,1);
	glColor3f(filmred,filmgreen,filmblue);
	glScalef(FilmScale,FilmScale,FilmScale);
	glTranslatef(-0.5,0.72,0);
	glBegin(GL_POLYGON);
	glVertex2f(0.74+filmbody_x,0.1+filmbody_y);				//필름 작은사각형
	glVertex2f(0.74+filmbody_x,0.18+filmbody_y);
	glVertex2f(0.66+filmbody_x,0.18+filmbody_y);
	glVertex2f(0.66+filmbody_x,0.1+filmbody_y);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	//glColor3f(1,1,1);
	glColor3f(filmred,filmgreen,filmblue);
	glScalef(FilmScale,FilmScale,FilmScale);
	glTranslatef(-0.65,0.72,0);
	glBegin(GL_POLYGON);
	glVertex2f(0.74+filmbody_x,0.1+filmbody_y);				//필름 작은사각형
	glVertex2f(0.74+filmbody_x,0.18+filmbody_y);
	glVertex2f(0.66+filmbody_x,0.18+filmbody_y);
	glVertex2f(0.66+filmbody_x,0.1+filmbody_y);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	//glColor3f(1,1,1);
	glColor3f(filmred,filmgreen,filmblue);
	glScalef(FilmScale,FilmScale,FilmScale);
	glTranslatef(-0.8,0.72,0);
	glBegin(GL_POLYGON);
	glVertex2f(0.74+filmbody_x,0.1+filmbody_y);				//필름 작은사각형
	glVertex2f(0.74+filmbody_x,0.18+filmbody_y);
	glVertex2f(0.66+filmbody_x,0.18+filmbody_y);
	glVertex2f(0.66+filmbody_x,0.1+filmbody_y);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	//glColor3f(1,1,1);
	glColor3f(filmred,filmgreen,filmblue);
	glScalef(FilmScale,FilmScale,FilmScale);
	glTranslatef(-0.95,0.72,0);
	glBegin(GL_POLYGON);
	glVertex2f(0.74+filmbody_x,0.1+filmbody_y);				//필름 작은사각형
	glVertex2f(0.74+filmbody_x,0.18+filmbody_y);
	glVertex2f(0.66+filmbody_x,0.18+filmbody_y);
	glVertex2f(0.66+filmbody_x,0.1+filmbody_y);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	//glColor3f(1,1,1);
	glColor3f(filmred,filmgreen,filmblue);
	glScalef(FilmScale,FilmScale,FilmScale);
	glTranslatef(-1.1,0.72,0);
	glBegin(GL_POLYGON);
	glVertex2f(0.74+filmbody_x,0.1+filmbody_y);				//필름 작은사각형
	glVertex2f(0.74+filmbody_x,0.18+filmbody_y);
	glVertex2f(0.66+filmbody_x,0.18+filmbody_y);
	glVertex2f(0.66+filmbody_x,0.1+filmbody_y);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	//glColor3f(1,1,1);
	glColor3f(filmred,filmgreen,filmblue);
	glScalef(FilmScale,FilmScale,FilmScale);
	glTranslatef(-1.25,0.72,0);
	glBegin(GL_POLYGON);
	glVertex2f(0.74+filmbody_x,0.1+filmbody_y);				//필름 작은사각형
	glVertex2f(0.74+filmbody_x,0.18+filmbody_y);
	glVertex2f(0.66+filmbody_x,0.18+filmbody_y);
	glVertex2f(0.66+filmbody_x,0.1+filmbody_y);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	//glColor3f(1,1,1);
	glColor3f(filmred,filmgreen,filmblue);
	glScalef(FilmScale,FilmScale,FilmScale);
	glTranslatef(-1.4,0.72,0);
	glBegin(GL_POLYGON);
	glVertex2f(0.74+filmbody_x,0.1+filmbody_y);				//필름 작은사각형
	glVertex2f(0.74+filmbody_x,0.18+filmbody_y);
	glVertex2f(0.66+filmbody_x,0.18+filmbody_y);
	glVertex2f(0.66+filmbody_x,0.1+filmbody_y);
	glEnd();
	glPopMatrix();

}




void Film::SlateBody(double slatebody_x,double slatebody_y){

	glPushMatrix();
	glColor3f(0.0,0.0,0.0);			//슬레이트
	glScalef(SlateScale,SlateScale,SlateScale);
	glBegin(GL_POLYGON);
	glVertex2f(0.0+slatebody_x+slatex,0.0+slatebody_y+slatey);				
	glVertex2f(0.8+slatebody_x+slatex,0.0+slatebody_y+slatey);
	glVertex2f(0.8+slatebody_x+slatex,0.35+slatebody_y+slatey);
	glVertex2f(0.0+slatebody_x+slatex,0.35+slatebody_y+slatey);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	//glColor3f(1,1,0);			//슬레이트 가위모양 아래
	glColor3f(slatered2,slategreen2,slateblue2);	
	glScalef(SlateScale,SlateScale,SlateScale);
	glBegin(GL_POLYGON);
	glVertex2f(0.0+slatebody_x+slatex,0.35+slatebody_y+slatey);				
	glVertex2f(0.0+slatebody_x+slatex,0.5+slatebody_y+slatey);
	glVertex2f(0.8+slatebody_x+slatex,0.5+slatebody_y+slatey);
	glVertex2f(0.8+slatebody_x+slatex,0.35+slatebody_y+slatey);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glColor3f(slatered,slategreen,slateblue);			//슬레이트 가위 안 직사각형
	glScalef(SlateScale,SlateScale,SlateScale);
	glBegin(GL_POLYGON);
	glVertex2f(0.2+slatebody_x+slatex,0.35+slatebody_y+slatey);				
	glVertex2f(0.35+slatebody_x+slatex,0.35+slatebody_y+slatey);
	glVertex2f(0.4+slatebody_x+slatex,0.5+slatebody_y+slatey);
	glVertex2f(0.25+slatebody_x+slatex,0.5+slatebody_y+slatey);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glColor3f(slatered,slategreen,slateblue);				//슬레이트 가위 안 직사각형
	glScalef(SlateScale,SlateScale,SlateScale);
	glBegin(GL_POLYGON);
	glVertex2f(0.5+slatebody_x+slatex,0.35+slatebody_y+slatey);				
	glVertex2f(0.65+slatebody_x+slatex,0.35+slatebody_y+slatey);
	glVertex2f(0.7+slatebody_x+slatex,0.5+slatebody_y+slatey);
	glVertex2f(0.55+slatebody_x+slatex,0.5+slatebody_y+slatey);
	glEnd();
	glPopMatrix();


	glPushMatrix();
	glColor3f(slatered,slategreen,slateblue);				//슬레이트 연결고리
	glScalef(SlateScale,SlateScale,SlateScale);
	glBegin(GL_POLYGON);
	glVertex2f(0.01+slatebody_x+slatex,0.4+slatebody_y+slatey);				
	glVertex2f(0.16+slatebody_x+slatex,0.4+slatebody_y+slatey);
	glVertex2f(0.16+slatebody_x+slatex,0.45+slatebody_y+slatey);
	glVertex2f(0.06+slatebody_x+slatex,0.6+slatebody_y+slatey);
	glVertex2f(0.01+slatebody_x+slatex,0.6+slatebody_y+slatey);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glColor3f(0,0,0);			//슬레이트 연결고리 안 사각형
	glScalef(SlateScale,SlateScale,SlateScale);
	glBegin(GL_POLYGON);
	glVertex2f(0.02+slatebody_x+slatex,0.45+slatebody_y+slatey);				
	glVertex2f(0.05+slatebody_x+slatex,0.45+slatebody_y+slatey);
	glVertex2f(0.05+slatebody_x+slatex,0.41+slatebody_y+slatey);
	glVertex2f(0.02+slatebody_x+slatex,0.41+slatebody_y+slatey);
	glEnd();
	glPopMatrix();


	glPushMatrix();
	glColor3f(0,0,0);			//슬레이트 연결고리 안 사각형
	glScalef(SlateScale,SlateScale,SlateScale);
	glBegin(GL_POLYGON);
	glVertex2f(0.11+slatebody_x+slatex,0.45+slatebody_y+slatey);				
	glVertex2f(0.14+slatebody_x+slatex,0.45+slatebody_y+slatey);
	glVertex2f(0.14+slatebody_x+slatex,0.41+slatebody_y+slatey);
	glVertex2f(0.11+slatebody_x+slatex,0.41+slatebody_y+slatey);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glColor3f(0,0,0);			//슬레이트 연결고리 안 사각형
	glScalef(SlateScale,SlateScale,SlateScale);
	glBegin(GL_POLYGON);
	glVertex2f(0.02+slatebody_x+slatex,0.59+slatebody_y+slatey);				
	glVertex2f(0.05+slatebody_x+slatex,0.59+slatebody_y+slatey);
	glVertex2f(0.05+slatebody_x+slatex,0.55+slatebody_y+slatey);
	glVertex2f(0.02+slatebody_x+slatex,0.55+slatebody_y+slatey);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glColor3f(slatered,slategreen,slateblue);				//가운데선
	glScalef(SlateScale,SlateScale,SlateScale);
	glLineWidth(5.0);
	glBegin(GL_LINES);
	glVertex2f(0.0+slatebody_x+slatex,0.3+slatebody_y+slatey);				
	glVertex2f(0.8+slatebody_x+slatex,0.3+slatebody_y+slatey);
	glEnd();
	glPopMatrix();


	glPushMatrix();
	glColor3f(slatered,slategreen,slateblue);				//맨 밑선
	glScalef(SlateScale,SlateScale,SlateScale);
	glLineWidth(5.0);
	glBegin(GL_LINES);
	glVertex2f(0.0+slatebody_x+slatex,0.1+slatebody_y+slatey);				
	glVertex2f(0.8+slatebody_x+slatex,0.1+slatebody_y+slatey);
	

	glEnd();
	glPopMatrix();


	glPushMatrix();
	glColor3f(slatered,slategreen,slateblue);			//맨 밑선
	glScalef(SlateScale,SlateScale,SlateScale);
	glLineWidth(5.0);
	glBegin(GL_LINES);
	glVertex2f(0.4+slatebody_x+slatex,0.1+slatebody_y+slatey);				
	glVertex2f(0.4+slatebody_x+slatex,0.3+slatebody_y+slatey);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glColor3f(slatered,slategreen,slateblue);	//맨 밑선
	glScalef(SlateScale,SlateScale,SlateScale);
	glLineWidth(5.0);
	glBegin(GL_LINES);
	glVertex2f(0.0+slatebody_x+slatex,0.35+slatebody_y+slatey);				
	glVertex2f(0.8+slatebody_x+slatex,0.35+slatebody_y+slatey);
	glEnd();
	glPopMatrix();

}

void Film::SlateHead(double slatehead_x,double slatehead_y, double rotate){//주석부문 지우면 슬레이트가위 열어짐

	glPushMatrix();


	//glColor3f(1,1,0);		//슬레이트 가위모양 위
	glColor3f(slatered2,slategreen2,slateblue2);	
	glScalef(SlateScale,SlateScale,SlateScale);
	glTranslatef(-0.4+slatex2,0+slatey2,0);
	glRotatef(rotate,0,0,1);

	glBegin(GL_POLYGON);
	glVertex2f(0.4+slatehead_x,0.5+slatehead_y);		
	glVertex2f(0.4+slatehead_x,0.65+slatehead_y);
	glVertex2f(1.2+slatehead_x,0.65+slatehead_y);
	glVertex2f(1.2+slatehead_x,0.5+slatehead_y);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glColor3f(slatered,slategreen,slateblue);				//슬레이트 가위모양 위 직사각형
	glScalef(SlateScale,SlateScale,SlateScale);
	glTranslatef(-0.4+slatex2,0+slatey2,0);

	glRotatef(rotate,0,0,1);
	glBegin(GL_POLYGON);
	glVertex2f(0.65+slatehead_x,0.5+slatehead_y);//-0.4 ,-0.5				
	glVertex2f(0.8+slatehead_x,0.5+slatehead_y);
	glVertex2f(0.75+slatehead_x,0.65+slatehead_y);
	glVertex2f(0.6+slatehead_x,0.65+slatehead_y);
	glEnd();
	glPopMatrix();


	glPushMatrix();
	glColor3f(slatered,slategreen,slateblue);	//슬레이트 가위모양 위 직사각형
	glScalef(SlateScale,SlateScale,SlateScale);
	glTranslatef(-0.4+slatex2,0+slatey2,0);
	
	glRotatef(rotate,0,0,1);
	glBegin(GL_POLYGON);
	glVertex2f(0.95+slatehead_x,0.5+slatehead_y);				
	glVertex2f(1.1+slatehead_x,0.5+slatehead_y);
	glVertex2f(1.05+slatehead_x,0.65+slatehead_y);
	glVertex2f(0.9+slatehead_x,0.65+slatehead_y);
	glEnd();
	glPopMatrix();

}


void Film::ProjectorBody(double ProjectorBody_x,double ProjectorBody_y,double ProjectorBody_r,double ProjectorBody_g,double ProjectorBody_b){

	glPushMatrix();	
	glColor3f(ProjectorBody_r,ProjectorBody_g,ProjectorBody_b);
	glColor3f(projred,projgreen,projblue);
	glScalef(ProjectorScale,ProjectorScale,ProjectorScale);
	glTranslatef(0+projx,0.3+projy,0);
	glBegin(GL_POLYGON);
	glVertex2f(-0.25+ProjectorBody_x,0.3+ProjectorBody_y);
	glVertex2f(0.45+ProjectorBody_x,0.3+ProjectorBody_y);
	glVertex2f(0.45+ProjectorBody_x,-0.2+ProjectorBody_y);
	glVertex2f(-0.25+ProjectorBody_x,-0.2+ProjectorBody_y);
	glEnd();
	glPopMatrix();

	glPushMatrix();	
	glColor3f(ProjectorBody_r,ProjectorBody_g,ProjectorBody_b);
	glColor3f(projred,projgreen,projblue);
	glScalef(ProjectorScale,ProjectorScale,ProjectorScale);
	glTranslatef(0+projx,0.3+projy,0);
	glBegin(GL_POLYGON);
	glVertex2f(-0.05+ProjectorBody_x,-0.2+ProjectorBody_y);
	glVertex2f(0.25+ProjectorBody_x,-0.2+ProjectorBody_y);
	glVertex2f(0.25+ProjectorBody_x,-0.25+ProjectorBody_y);
	glVertex2f(-0.05+ProjectorBody_x,-0.25+ProjectorBody_y);
	glEnd();
	glPopMatrix();



	glPushMatrix();	
	glColor3f(ProjectorBody_r,ProjectorBody_g,ProjectorBody_b);
	glColor3f(projred,projgreen,projblue);
	glScalef(ProjectorScale,ProjectorScale,ProjectorScale);
	glTranslatef(0+projx,0.3+projy,0);
	glBegin(GL_POLYGON);
	glVertex2f(0.45+ProjectorBody_x,0.15+ProjectorBody_y);
	glVertex2f(0.45+ProjectorBody_x,-0.05+ProjectorBody_y);
	glVertex2f(0.75+ProjectorBody_x,-0.15+ProjectorBody_y);
	glVertex2f(0.75+ProjectorBody_x,0.25+ProjectorBody_y);
	glEnd();
	glPopMatrix();
}


void Film::ProjectorCircle1(double ProjectorCircle1_x,double ProjectorCircle1_y,double Circle1rotate){

	glPushMatrix();	

	float PI=3.141592;
	float angle;
	int i,N=100;
	float X=0.4;
	float Y=0.5;
	float R=0.2;
	float S=0.06;



	glColor3f(projred,projgreen,projblue);

	glScalef(ProjectorScale,ProjectorScale,ProjectorScale);
	glTranslatef(-0.1+projx,0.3+projy,0);
	glBegin(GL_POLYGON);

	for(i=0;i<=N;i++)
	{
		angle = 2*PI*i/N;
		glVertex3f((X+ProjectorCircle1_x)+R * cos(angle),(Y+ProjectorCircle1_y)+R * sin(angle),0);
	}
	glEnd();
	glPopMatrix();



	glPushMatrix();	
	glScalef(ProjectorScale,ProjectorScale,ProjectorScale);
	glTranslatef(-0.1+projx,0.3+projy,0);
	glRotatef(Circle1rotate,0,0,1);

	glLineWidth(5.0); 
	glColor3f(0,0,0);
	glBegin(GL_LINE_STRIP);

	for(i=0;i<=N;i++)
	{
		angle = 2*PI*i/N;
		glVertex3f((X+ProjectorCircle1_x)+S * cos(angle),(Y+ProjectorCircle1_x)+S * sin(angle),0);
	}
	glEnd();
	glPopMatrix();
}

void Film::ProjectorCircle2(double ProjectorCircle2_x,double ProjectorCircle2_y,double Circle2rotate){//이쪽 원이 12시방향 3시 6시 9시 돌아가게끔 만들고픔

	glPushMatrix();		
	float PI=3.141592;
	float angle;
	int i,N=100;
	float X1=0.4;
	float Y1=0.5;
	float R=0.2;//큰 원
	float S=0.06;//작은 원


	glColor3f(projred,projgreen,projblue);
	glScalef(ProjectorScale,ProjectorScale,ProjectorScale);
	glTranslatef(-0.5+projx,0.3+projy,0);
	glBegin(GL_POLYGON);

	for(i=0;i<=N;i++)
	{
		angle = 2*PI*i/N;
		glVertex3f((X1+ProjectorCircle2_x)+R * cos(angle),(Y1+ProjectorCircle2_y)+R * sin(angle),0);
	}
	glEnd();
	glPopMatrix();



	glPushMatrix();	
	glScalef(ProjectorScale,ProjectorScale,ProjectorScale);
	glTranslatef(-0.5+projx,0.3+projy,0);
	glRotatef(Circle2rotate,0,0,1);

	glLineWidth(5.0); 
	glColor3f(0,0,0);
	glBegin(GL_LINE_STRIP);

	for(i=0;i<=N;i++)
	{
		angle = 2*PI*i/N;
		glVertex3f((X1+ProjectorCircle2_x)+S * cos(angle),(Y1+ProjectorCircle2_x)+S * sin(angle),0);
	}
	glEnd();
	glPopMatrix();
}



