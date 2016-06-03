// Ocean.cpp : ±¸Çö ÆÄÀÏÀÔ´Ï´Ù.
//

#include "stdafx.h"
#include "Makory.h"
#include "Ocean.h"
#include "MainFrm.h"
#include "MakoryDoc.h"
#include "MakoryView.h"


// Ocean

IMPLEMENT_DYNAMIC(Ocean, CWnd)

	Ocean::Ocean()
{
		fishscale=0.0;
	 fishred=1.0;
	 fishgreen=0.0;
	 fishblue=1.0;
	 fishx = 0.0;
	 fishy=0.0;

	 sfishred=1.0;
	 sfishgreen=1.0;
	 sfishblue=0.0;
	 sfishx = 0.0;
	 sfishy =0.0;

	 sfishred2=0.5;
	 sfishgreen2=1.0;
	 sfishblue2=1.0;
	 sfishx2 = 0.0;
	 sfishy2 =0.0;

	 FishScale=0.5;
	 OceanScale=0.5;
	 FishingScale=0.4;
	 FishingVessel=2.5;

	 starred=1.0;
	 stargreen=0.0;
	 starblue=0.0;
	 starx = 0.0;
	 stary=0.0;
	 starscale=0.5;

	 //º¸Æ® ¹Ù´Ú
	 boatred=0.0;
	 boatgreen=0.0;
	 boatblue=1.0;

	 //º¸Æ® ÀüÃ¼
	 boatx=0.0;
	 boaty=0.0;
	 boatcale=0.0;

	 lboatred=0.0;
	 lboatgreen=0.5;
	 lboatblue=1.0;

	 rboatred=0.5;
	 rboatgreen=1.0;
	 rboatblue=1.0;

	fishingpred=0.0;
	fishingpgreen=1.0;
	fishingpblue=0.0;

	fishingred=1.0;
	fishinggreen=1.0;
	fishingblue=1.0;

	fishingx=0.0;
	fishingy=0.0;
	fishingscale=0.0;
	waveimgscale=0.0;
	wavey=0.0;
	oceanimgscale=0.0;
	fishingimgscale=0.0;

	eyescale=0.0;
}

Ocean::~Ocean()
{
}


BEGIN_MESSAGE_MAP(Ocean, CWnd)
END_MESSAGE_MAP()
// Ocean ¸Þ½ÃÁö Ã³¸®±âÀÔ´Ï´Ù.



//ÆÄµµ
void Ocean::wave1(double wave1_x,double wave1_y,double wave1_z,double wave1_r,double wave1_g,double wave1_b) {

	glPushMatrix();
	glScalef(OceanScale,OceanScale,OceanScale);
	glTranslatef(-1,-1-wavey,0);

	GLfloat wave1point[10][3] = 
	{ { -10+wave1_x, 8.5+wave1_y, 0},{ -10+wave1_x, 0+wave1_y, 0},{ -5+wave1_x, 10+wave1_y, 0},
	{ -2+wave1_x, -10+wave1_y, 0}, {1+wave1_x,3+wave1_y,0},{ 2+wave1_x, 0+wave1_y, 0},
	{ 5+wave1_x, 10+wave1_y, 0}, { 8+wave1_x, -10+wave1_y, 0}, {11+wave1_x,3+wave1_y,0}, 
	{11+wave1_x,8.5+wave1_y,0}};
	glMap1f(GL_MAP1_VERTEX_3, 0.0, 1.0, 3, 10, &wave1point[0][0]);
	glEnable(GL_MAP1_VERTEX_3);

	int i;
	//glColor3f(wave1_r,wave1_g,wave1_b);
	glColor3f(0,0,1);
	glLineWidth(20);
	glBegin(GL_POLYGON);
	for (i = 0; i <= 30; i++) 
		glEvalCoord1f((GLfloat) i/30.0);
	glEnd();
	glPopMatrix();

}
void Ocean::WaveTexture(double wavetexture_x,double wavetexture_y){

	glPushMatrix();
	glScalef(OceanScale,OceanScale,OceanScale);
	glTranslatef(-3,5,0);

	glColor3f(1,1,1);			//8x6»çÀÌÁî ÅØ½ºÃ³
	glBegin(GL_POLYGON);
	glTexCoord2f(1.0, 0.0);glVertex2f(2+wavetexture_x-waveimgscale,-2+wavetexture_y+waveimgscale);
	glTexCoord2f(1.0, 1.0);glVertex2f(2+wavetexture_x-waveimgscale,-4.4+wavetexture_y-waveimgscale);
	glTexCoord2f(0.0, 1.0);glVertex2f(5.2+wavetexture_x+waveimgscale,-4.4+wavetexture_y-waveimgscale);
	glTexCoord2f(0.0, 0.0);glVertex2f(5.2+wavetexture_x+waveimgscale,-2+wavetexture_y+waveimgscale);
	glEnd();
	glPopMatrix();

}
void Ocean::CircleFish(double circlefish_x, double circlefish_y){

	glPushMatrix();
	glScalef(FishScale,FishScale,FishScale);
	glTranslatef(-8-fishx,-3-fishy,0);

	glColor3f(fishred,fishgreen,fishblue);
	glBegin(GL_POLYGON); 

	glVertex2f(0.2+circlefish_x-fishscale,0.6+circlefish_y+fishscale);
	glVertex2f(0.2+circlefish_x-fishscale,-0.6+circlefish_y-fishscale);
	glVertex2f(1+circlefish_x+fishscale,0+circlefish_y);

	glEnd();
	glPopMatrix();

	glPushMatrix();//²¿¸®
	glScalef(FishScale,FishScale,FishScale);
	glTranslatef(-8-fishx,-3-fishy,0);

	//glColor3f(1,0,1);
	glColor3f(fishred,fishgreen,fishblue);
	glBegin(GL_POLYGON); 

	glVertex2f(0+circlefish_x-fishscale,0+circlefish_y);
	glVertex2f(-0.2+circlefish_x-2*fishscale,0.2+circlefish_y+fishscale);
	glVertex2f(-0.2+circlefish_x-2*fishscale,-0.2+circlefish_y-fishscale);

	glEnd();
	glPopMatrix();


}
void Ocean::CircleFishEyes(double eyes_x,double eyes_y){

	glPushMatrix();
	glScalef(FishScale,FishScale,FishScale);
	glTranslatef(-8-fishx,-3-fishy,0);


	float PI=3.141592;
	float angle;
	int j,N=100;
	float X=0.65;
	float Y=0;
	float dX=0.7;
	float dY=0.03;
	float R=0.12;
	float S=0.08;
	float T=0.04;


	glColor3f(1,1,1);//´«
	glBegin(GL_POLYGON);

	for(j=0;j<=N;j++)
	{
		angle = 2*PI*j/N;
		glVertex3f((X+eyes_x)+((R+eyescale) * cos(angle)),(Y+eyes_y)+((R+eyescale) * sin(angle)),0);
	}
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glScalef(FishScale,FishScale,FishScale);
	glTranslatef(-8-fishx,-3-fishy,0);

	glColor3f(0,0,0);//´«
	glBegin(GL_POLYGON);

	for(j=0;j<=N;j++)
	{
		angle = 2*PI*j/N;
		glVertex3f((X+eyes_x)+((S+eyescale) * cos(angle)),((Y+eyes_y)+(S+eyescale) * sin(angle)),0);
	}
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glScalef(FishScale,FishScale,FishScale);
	glTranslatef(-8-fishx,-3-fishy,0);

	glColor3f(1,1,1);//´«
	glBegin(GL_POLYGON);

	for(j=0;j<=N;j++)
	{
		angle = 2*PI*j/N;
		glVertex3f((dX+eyes_x)+((T+eyescale) * cos(angle)),(dY+eyes_y)+((T+eyescale) * sin(angle)),0);
	}
	glEnd();
	glPopMatrix();
}

void Ocean::CircleFish1(double circlefish1_x, double circlefish1_y){

	glPushMatrix();
	glScalef(FishScale,FishScale,FishScale);
	glTranslatef(8-fishx,-2-fishy,0);
	glRotatef(180,0,0,1);

	//glColor3f(1,0,1);
	glColor3f(fishred,fishgreen,fishblue);
	glBegin(GL_POLYGON); 
	glVertex2f(0.2+circlefish1_x-fishscale,0.6+circlefish1_y+fishscale);
	glVertex2f(0.2+circlefish1_x-fishscale,-0.6+circlefish1_y-fishscale);
	glVertex2f(1+circlefish1_x+fishscale,0+circlefish1_y);
	glEnd();
	glPopMatrix();

	glPushMatrix();//²¿¸®

	glScalef(FishScale,FishScale,FishScale);
	glTranslatef(8-fishx,-2-fishy,0);
	glRotatef(180,0,0,1);

	//glColor3f(1,0,1);
	glColor3f(fishred,fishgreen,fishblue);
	glBegin(GL_POLYGON); 

	
	glVertex2f(0+circlefish1_x-fishscale,0+circlefish1_y);
	glVertex2f(-0.2+circlefish1_x-2*fishscale,0.2+circlefish1_y+fishscale);
	glVertex2f(-0.2+circlefish1_x-2*fishscale,-0.2+circlefish1_y-fishscale);

	glEnd();
	glPopMatrix();



}
void Ocean::CircleFishEyes1(double eyes_x,double eyes_y){

	glPushMatrix();
	glScalef(FishScale,FishScale,FishScale);
	glTranslatef(8-fishx,-2-fishy,0);
	glRotatef(180,0,0,1);

	float PI=3.141592;
	float angle;
	int j,N=100;
	float X=0.65;
	float Y=0;
	float dX=0.7;
	float dY=0.03;
	float R=0.12;
	float S=0.08;
	float T=0.04;

	glColor3f(1,1,1);//´«
	glBegin(GL_POLYGON);

	for(j=0;j<=N;j++)
	{
		angle = 2*PI*j/N;
		glVertex3f((X+eyes_x)+((R+eyescale) * cos(angle)),(Y+eyes_y)+((R+eyescale) * sin(angle)),0);

	}
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glScalef(FishScale,FishScale,FishScale);
	glTranslatef(8-fishx,-2-fishy,0);
	glRotatef(180,0,0,1);

	glColor3f(0,0,0);//´«
	glBegin(GL_POLYGON);

	for(j=0;j<=N;j++)
	{
		angle = 2*PI*j/N;
		glVertex3f((X+eyes_x)+((S+eyescale) * cos(angle)),(Y+eyes_y)+((S+eyescale) * sin(angle)),0);
	}
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glScalef(FishScale,FishScale,FishScale);
	glTranslatef(8-fishx,-2-fishy,0);
	glRotatef(180,0,0,1);

	glColor3f(1,1,1);//´«
	glBegin(GL_POLYGON);

	for(j=0;j<=N;j++)
	{
		angle = 2*PI*j/N;
		glVertex3f((dX+eyes_x)+((T+eyescale) * cos(angle)),(dY+eyes_y)+((T+eyescale) * sin(angle)),0);
	}
	glEnd();
	glPopMatrix();
}
//º°°¡
void Ocean::StarFish1(double StarFish1_x,double StarFish1_y,double StarFish1_r,double StarFish1_g,double StarFish1_b, double rotate) {//º°°¡
	

	glPushMatrix();
	glLoadIdentity();
	glScalef(OceanScale,OceanScale,OceanScale);
	//glScalef(0.5,0.5,0);
	glTranslatef(1,-2,0);
	glRotatef(rotate,0,0,1);

	glBegin(GL_POLYGON);			//´Ù°¢Çü ±×¸®±â
	glColor3f(starred, stargreen, starblue);	//»ö»ó ¼ÂÆÃ
	// º°À» ±×¸®±â À§ÇÑ ÁÂÇ¥ Á¤º¸ ¼ÂÆÃ
	glVertex2f(0.0+StarFish1_x+starx, -0.5+StarFish1_y+stary);
	glVertex2f(0.5+StarFish1_x+starx, -0.8+StarFish1_y+stary);
	glVertex2f(0.3+StarFish1_x+starx, -0.3+StarFish1_y+stary);
	glVertex2f(0.8+StarFish1_x+starx, 0.1+StarFish1_y+stary);
	glVertex2f(0.2+StarFish1_x+starx, 0.1+StarFish1_y+stary);
	glVertex2f(0.0+StarFish1_x+starx, 0.8+StarFish1_y+stary);
	glVertex2f(-0.2+StarFish1_x+starx, 0.1+StarFish1_y+stary);
	glVertex2f(-0.8+StarFish1_x+starx, 0.1+StarFish1_y+stary);
	glVertex2f(-0.3+StarFish1_x+starx, -0.3+StarFish1_y+stary);
	glVertex2f(-0.5+StarFish1_x+starx, -0.8+StarFish1_y+stary);
	glEnd();
	glPopMatrix();



} //º°°¡//º°°¡
void Ocean::StarFish1eyesL(double StarFish1eyesL_x,double StarFish1eyesL_y, double rotate){

	glPushMatrix();
	//glScalef(OceanScale,OceanScale,OceanScale);
	glScalef(starscale,starscale,0);
	glTranslatef(1+starx,-2,0);
	//glRotatef(rotate,0,0,1);

	float PI=3.141592;
	float angle;
	int j,N=100;
	float X=-0.15;
	float Y=-0.1;
	float dX=-0.16;
	float dY=-0.1;
	float R=0.12;
	float S=0.08;
	float T=0.02;


	glColor3f(1,1,1);//´«
	glBegin(GL_POLYGON);

	for(j=0;j<=N;j++)
	{
		angle = 2*PI*j/N;
		glVertex3f((X+StarFish1eyesL_x+starx)+R * cos(angle),(Y+StarFish1eyesL_y+stary)+R * sin(angle),0);
	}
	glEnd();
	glPopMatrix();



	glPushMatrix();
	//glScalef(OceanScale,OceanScale,OceanScale);
	glScalef(starscale,starscale,0);
	glTranslatef(1+starx,-2,0);
	//glRotatef(rotate,0,0,1);


	glColor3f(0,0,0);//´«
	glBegin(GL_POLYGON);

	for(j=0;j<=N;j++)
	{
		angle = 2*PI*j/N;
		glVertex3f((X+StarFish1eyesL_x+starx)+S * cos(angle),(Y+StarFish1eyesL_y+stary)+S * sin(angle),0);
	}
	glEnd();
	glPopMatrix();




	glPushMatrix();
	//glScalef(OceanScale,OceanScale,OceanScale);
	glScalef(starscale,starscale,0);
	glTranslatef(1+starx,-2,0);
	glRotatef(rotate,0,0,1);

	glColor3f(1,1,1);//´«
	glBegin(GL_POLYGON);

	for(j=0;j<=N;j++)
	{
		angle = 2*PI*j/N;
		glVertex3f((dX+StarFish1eyesL_x+starx)+T * cos(angle),(dY+StarFish1eyesL_y+stary)+T * sin(angle),0);
	}
	glEnd();
	glPopMatrix();



}
//º°°¡´«
void Ocean::StarFish1eyesR(double StarFish1eyesR_x,double StarFish1eyesR_y, double rotate){

	glPushMatrix();
	//glScalef(OceanScale,OceanScale,OceanScale);
	glScalef(starscale,starscale,0);
	glTranslatef(1,-2,0);
	//glRotatef(rotate,0,0,1);

	float PI=3.141592;
	float angle;
	int j,N=100;
	float X=0.15;
	float Y=-0.1;
	float dX=0.16;
	float dY=-0.1;
	float R=0.12;
	float S=0.08;
	float T=0.02;


	glColor3f(1,1,1);//´«
	glBegin(GL_POLYGON);

	for(j=0;j<=N;j++)
	{
		angle = 2*PI*j/N;
		glVertex3f((X+StarFish1eyesR_x+starx)+R * cos(angle),(Y+StarFish1eyesR_y+stary)+R * sin(angle),0);
	}
	glEnd();
	glPopMatrix();



	glPushMatrix();
	//glScalef(OceanScale,OceanScale,OceanScale);
	glScalef(starscale,starscale,0);
	glTranslatef(1,-2,0);
	//glRotatef(rotate,0,0,1);

	glColor3f(0,0,0);//´«
	glBegin(GL_POLYGON);

	for(j=0;j<=N;j++)
	{
		angle = 2*PI*j/N;
		glVertex3f((X+StarFish1eyesR_x+starx)+S * cos(angle),(Y+StarFish1eyesR_y+stary)+S * sin(angle),0);
	}
	glEnd();
	glPopMatrix();


	glPushMatrix();
	//glScalef(OceanScale,OceanScale,OceanScale);
	glScalef(starscale,starscale,0);
	glTranslatef(1,-2,0);
	//glRotatef(rotate,0,0,1);

	glColor3f(1,1,1);//´«
	glBegin(GL_POLYGON);

	for(j=0;j<=N;j++)
	{
		angle = 2*PI*j/N;
		glVertex3f((dX+StarFish1eyesR_x+starx)+T * cos(angle),(dY+StarFish1eyesR_y+stary)+T * sin(angle),0);
	}
	glEnd();
	glPopMatrix();



}//º°°¡´«

//º°°¡ ½ÃÀÛ
void Ocean::StarFish2(double StarFish2_x,double StarFish2_y,double StarFish2_r,double StarFish2_g,double StarFish2_b, double rotate) {

	
	glPushMatrix();
	//glScalef(OceanScale,OceanScale,OceanScale);
	glScalef(starscale,starscale,0);
	glTranslatef(-5+starx,-2,0);
	glRotatef(rotate,0,0,1);

	glBegin(GL_POLYGON);			//´Ù°¢Çü ±×¸®±â
	//glColor3f(1, 0, 0);	//»ö»ó ¼ÂÆÃ
	glColor3f(starred, stargreen, starblue);
	// º°À» ±×¸®±â À§ÇÑ ÁÂÇ¥ Á¤º¸ ¼ÂÆÃ
	glVertex2f(0.0+StarFish2_x, -0.5+StarFish2_y+stary);
	glVertex2f(0.5+StarFish2_x, -0.8+StarFish2_y+stary);
	glVertex2f(0.3+StarFish2_x, -0.3+StarFish2_y+stary);
	glVertex2f(0.8+StarFish2_x, 0.1+StarFish2_y+stary);
	glVertex2f(0.2+StarFish2_x, 0.1+StarFish2_y+stary);
	glVertex2f(0.0+StarFish2_x, 0.8+StarFish2_y+stary);
	glVertex2f(-0.2+StarFish2_x, 0.1+StarFish2_y+stary);
	glVertex2f(-0.8+StarFish2_x, 0.1+StarFish2_y+stary);
	glVertex2f(-0.3+StarFish2_x, -0.3+StarFish2_y+stary);
	glVertex2f(-0.5+StarFish2_x, -0.8+StarFish2_y+stary);
	glEnd();
	glPopMatrix();


} //º°°¡//º°°¡
void Ocean::StarFish2eyesL(double StarFish2eyesL_x,double StarFish2eyesL_y, double rotate){
glPushMatrix();
	//glScalef(OceanScale,OceanScale,OceanScale);
	glScalef(starscale,starscale,0);
	glTranslatef(-5+starx,-2,0);
	glRotatef(rotate,0,0,1);

	float PI=3.141592;
	float angle;
	int j,N=100;
	float X=-0.15;
	float Y=-0.1;
	float dX=-0.16;
	float dY=-0.1;
	float R=0.12;
	float S=0.08;
	float T=0.02;

	glColor3f(1,1,1);//´«
	glBegin(GL_POLYGON);

	for(j=0;j<=N;j++)
	{
		angle = 2*PI*j/N;
		glVertex3f((X+StarFish2eyesL_x)+R * cos(angle),(Y+StarFish2eyesL_y+stary)+R * sin(angle),0);
	}
	glEnd();
	glPopMatrix();

	glPushMatrix();
	//glScalef(OceanScale,OceanScale,OceanScale);
	glScalef(starscale,starscale,0);
	glTranslatef(-5+starx,-2,0);
	glRotatef(rotate,0,0,1);

	glColor3f(0,0,0);//´«
	glBegin(GL_POLYGON);

	for(j=0;j<=N;j++)
	{
		angle = 2*PI*j/N;
		glVertex3f((X+StarFish2eyesL_x)+S * cos(angle),(Y+StarFish2eyesL_y+stary)+S * sin(angle),0);
	}
	glEnd();
	glPopMatrix();


	glPushMatrix();
	//glScalef(OceanScale,OceanScale,OceanScale);
	glScalef(starscale,starscale,0);
	glTranslatef(-5+starx,-2,0);
	glRotatef(rotate,0,0,1);

	glColor3f(1,1,1);//´«
	glBegin(GL_POLYGON);

	for(j=0;j<=N;j++)
	{
		angle = 2*PI*j/N;
		glVertex3f((dX+StarFish2eyesL_x)+T * cos(angle),(dY+StarFish2eyesL_y+stary)+T * sin(angle),0);
	}
	glEnd();
	glPopMatrix();


}//º°°¡´«
void Ocean::StarFish2eyesR(double StarFish2eyesR_x,double StarFish2eyesR_y, double rotate){
	glPushMatrix();
	//glScalef(OceanScale,OceanScale,OceanScale);
	glScalef(starscale,starscale,0);
	glTranslatef(-5+starx,-2,0);
	glRotatef(rotate,0,0,1);

	float PI=3.141592;
	float angle;
	int j,N=100;
	float X=0.15;
	float Y=-0.1;
	float dX=0.16;
	float dY=-0.1;
	float R=0.12;
	float S=0.08;
	float T=0.02;


	glColor3f(1,1,1);//´«
	glBegin(GL_POLYGON);

	for(j=0;j<=N;j++)
	{
		angle = 2*PI*j/N;
		glVertex3f((X+StarFish2eyesR_x)+R * cos(angle),(Y+StarFish2eyesR_y+stary)+R * sin(angle),0);
	}
	glEnd();
	glPopMatrix();


	glPushMatrix();
	//glScalef(OceanScale,OceanScale,OceanScale);
	glScalef(starscale,starscale,0);
	glTranslatef(-5+starx,-2,0);
	glRotatef(rotate,0,0,1);

	glColor3f(0,0,0);//´«
	glBegin(GL_POLYGON);

	for(j=0;j<=N;j++)
	{
		angle = 2*PI*j/N;
		glVertex3f((X+StarFish2eyesR_x)+S * cos(angle),(Y+StarFish2eyesR_y+stary)+S * sin(angle),0);
	}
	glEnd();
	glPopMatrix();


	glPushMatrix();
	//glScalef(OceanScale,OceanScale,OceanScale);
	glScalef(starscale,starscale,0);
	glTranslatef(-5+starx,-2,0);
	glRotatef(rotate,0,0,1);

	glColor3f(1,1,1);//´«
	glBegin(GL_POLYGON);

	for(j=0;j<=N;j++)
	{
		angle = 2*PI*j/N;
		glVertex3f((dX+StarFish2eyesR_x)+T * cos(angle),(dY+StarFish2eyesR_y+stary)+T * sin(angle),0);
	}
	glEnd();
	glPopMatrix();
}//º°°¡´«

void Ocean::Fish2(double Fish2_x,double Fish2_y,double Fish2_z,double Fish2_r,double Fish2_g,double Fish2_b) {

	glPushMatrix();
	glScalef(OceanScale,OceanScale,OceanScale);
	glTranslatef(-4+sfishx,-3+sfishy,0);
	glRotatef(30,0,0,1);

	//glColor3f(1,1,0);//¸öÅë
	glColor3f(sfishred,sfishgreen,sfishblue);
	glBegin(GL_POLYGON); 

	glVertex2f(0+Fish2_x,0+Fish2_y);
	glVertex2f(0.5+Fish2_x,0.3+Fish2_y);
	glVertex2f(1+Fish2_x,0+Fish2_y);
	glVertex2f(0.5+Fish2_x,-0.3+Fish2_y);

	glEnd();
	glPopMatrix();


	glPushMatrix();
	glScalef(OceanScale,OceanScale,OceanScale);
	glTranslatef(-4+sfishx,-3+sfishy,0);
	glRotatef(30,0,0,1);

	glLineWidth(2);//¹«´Ì
	glBegin(GL_LINES);
	glColor3f(1,0,0);
	glVertex2f(0.5+Fish2_x,0.3+Fish2_y);
	glVertex2f(0.5+Fish2_x,-0.3+Fish2_y);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glScalef(OceanScale,OceanScale,OceanScale);
	glTranslatef(-4+sfishx,-3+sfishy,0);
	glRotatef(30,0,0,1);

	glLineWidth(2);//¹«´Ì
	glBegin(GL_LINES);
	glColor3f(1,0,0);
	glVertex2f(0.3+Fish2_x,0.19+Fish2_y);
	glVertex2f(0.3+Fish2_x,-0.19+Fish2_y);
	glEnd();
	glPopMatrix();


	glPushMatrix();
	glScalef(OceanScale,OceanScale,OceanScale);
	glTranslatef(-4+sfishx,-3+sfishy,0);
	glRotatef(30,0,0,1);

	//glColor3f(0.85,0.9,0);//²¿¸®
	glColor3f(sfishred-0.15,sfishgreen-0.5,sfishblue);
	glBegin(GL_POLYGON); 
	glVertex2f(0+Fish2_x,0+Fish2_y);
	glVertex2f(-0.2+Fish2_x,0.2+Fish2_y);
	glVertex2f(-0.2+Fish2_x,-0.2+Fish2_y);
	glEnd();
	glPopMatrix();
}

void Ocean::eyes2(double eyes2_x,double eyes2_y){
	glPushMatrix();
	glScalef(OceanScale,OceanScale,OceanScale);
	glTranslatef(-4+sfishx,-3+sfishy,0);
	glRotatef(30,0,0,1);

	float PI=3.141592;
	float angle;
	int j,N=100;
	float X=0.7;
	float Y=0;
	float dX=0.73;
	float dY=0;
	float R=0.12;
	float S=0.08;
	float T=0.04;


	glColor3f(1,1,1);//´«
	glBegin(GL_POLYGON);

	for(j=0;j<=N;j++)
	{
		angle = 2*PI*j/N;
		glVertex3f((X+eyes2_x)+R * cos(angle),(Y+eyes2_y)+R * sin(angle),0);
	}
	glEnd();
	glPopMatrix();



	glPushMatrix();
	glScalef(OceanScale,OceanScale,OceanScale);
	glTranslatef(-4+sfishx,-3+sfishy,0);
	glRotatef(30,0,0,1);
	glColor3f(0,0,0);//´«
	glBegin(GL_POLYGON);

	for(j=0;j<=N;j++)
	{
		angle = 2*PI*j/N;
		glVertex3f((X+eyes2_x)+S * cos(angle),(Y+eyes2_y)+S * sin(angle),0);
	}
	glEnd();
	glPopMatrix();


	glPushMatrix();
	glScalef(OceanScale,OceanScale,OceanScale);
	glTranslatef(-4+sfishx,-3+sfishy,0);
	glRotatef(30,0,0,1);
	glColor3f(1,1,1);//´«
	glBegin(GL_POLYGON);

	for(j=0;j<=N;j++)
	{
		angle = 2*PI*j/N;
		glVertex3f((dX+eyes2_x)+T * cos(angle),(dY+eyes2_y)+T * sin(angle),0);
	}
	glEnd();
	glPopMatrix();



}

void Ocean::Fish3(double Fish3_x,double Fish3_y,double Fish3_z,double Fish3_r,double Fish3_g,double Fish3_b) {

	glPushMatrix();
	glScalef(OceanScale,OceanScale,OceanScale);
	glTranslatef(4+sfishx2,3+sfishy2,0);
	glRotatef(210,0,0,1);

	//glColor3f(0.5,1,1);//¸öÅë
	glColor3f(sfishred2,sfishgreen2,sfishblue2);
	glBegin(GL_POLYGON); 
	glVertex2f(0+Fish3_x,0+Fish3_y);
	glVertex2f(0.5+Fish3_x,0.3+Fish3_y);
	glVertex2f(1+Fish3_x,0+Fish3_y);
	glVertex2f(0.5+Fish3_x,-0.3+Fish3_y);
	glEnd();
	glPopMatrix();


	glPushMatrix();
	glScalef(OceanScale,OceanScale,OceanScale);
	glTranslatef(4+sfishx2,3+sfishy2,0);
	glRotatef(210,0,0,1);

	glLineWidth(2);//¹«´Ì
	glBegin(GL_LINES);
	glColor3f(1,0,0);
	glVertex2f(0.5+Fish3_x,0.3+Fish3_y);
	glVertex2f(0.5+Fish3_x,-0.3+Fish3_y);
	glEnd();
	glPopMatrix();



	glPushMatrix();
	glScalef(OceanScale,OceanScale,OceanScale);
	glTranslatef(4+sfishx2,3+sfishy2,0);
	glRotatef(210,0,0,1);

	glLineWidth(2);//¹«´Ì
	glBegin(GL_LINES);
	glColor3f(1,0,0);
	glVertex2f(0.3+Fish3_x,0.19+Fish3_y);
	glVertex2f(0.3+Fish3_x,-0.19+Fish3_y);
	glEnd();
	glPopMatrix();


	glPushMatrix();
	glScalef(OceanScale,OceanScale,OceanScale);
	glTranslatef(4+sfishx2,3+sfishy2,0);
	glRotatef(210,0,0,1);

	//glColor3f(0,0.5,1);//²¿¸®
	glColor3f(sfishred2-0.5,sfishgreen2-0.5,sfishblue2);
	glBegin(GL_POLYGON); 
	glVertex2f(0+Fish3_x,0+Fish3_y);
	glVertex2f(-0.2+Fish3_x,0.2+Fish3_y);
	glVertex2f(-0.2+Fish3_x,-0.2+Fish3_y);
	glEnd();
	glPopMatrix();
}
void Ocean::eyes3(double eyes3_x,double eyes3_y){


	glPushMatrix();
	glScalef(OceanScale,OceanScale,OceanScale);
	glTranslatef(4+sfishx2,3+sfishy2,0);
	glRotatef(210,0,0,1);

	float PI=3.141592;
	float angle;
	int j,N=100;
	float X=0.7;
	float Y=0;
	float dX=0.73;
	float dY=0;
	float R=0.12;
	float S=0.08;
	float T=0.04;


	glColor3f(1,1,1);//´«
	glBegin(GL_POLYGON);

	for(j=0;j<=N;j++)
	{
		angle = 2*PI*j/N;
		glVertex3f((X+eyes3_x)+R * cos(angle),(Y+eyes3_y)+R * sin(angle),0);
	}
	glEnd();
	glPopMatrix();


	glPushMatrix();
	glScalef(OceanScale,OceanScale,OceanScale);
	glTranslatef(4+sfishx2,3+sfishy2,0);
	glRotatef(210,0,0,1);

	glColor3f(0,0,0);//´«
	glBegin(GL_POLYGON);

	for(j=0;j<=N;j++)
	{
		angle = 2*PI*j/N;
		glVertex3f((X+eyes3_x)+S * cos(angle),(Y+eyes3_y)+S * sin(angle),0);
	}
	glEnd();
	glPopMatrix();


	glPushMatrix();
	glScalef(OceanScale,OceanScale,OceanScale);
	glTranslatef(4+sfishx2,3+sfishy2,0);
	glRotatef(210,0,0,1);

	glColor3f(1,1,1);//´«
	glBegin(GL_POLYGON);

	for(j=0;j<=N;j++)
	{
		angle = 2*PI*j/N;
		glVertex3f((dX+eyes3_x)+T * cos(angle),(dY+eyes3_y)+T * sin(angle),0);
	}
	glEnd();
	glPopMatrix();

}


void Ocean::OceanTexture(double texture_x,double texture_y,double rotate){


	glEnable(GL_TEXTURE_2D);

	glPushMatrix();
	glScalef(OceanScale,OceanScale,OceanScale);
	glTranslatef(-2,-2,0);
	glRotatef(rotate,0,0,1);

	glColor3f(1,1,1);			//8x6»çÀÌÁî ÅØ½ºÃ³
	glBegin(GL_POLYGON);
	glTexCoord2f(1.0, 1.0);glVertex2f(-1.5+texture_x-oceanimgscale,-1+texture_y-oceanimgscale);				//ÇÊ¸§ »çÁø ³Ö´Â°ø°£ 2
	glTexCoord2f(0.0, 1.0);glVertex2f(1.5+texture_x+oceanimgscale,-1+texture_y-oceanimgscale);
	glTexCoord2f(0.0, 0.0);glVertex2f(1.5+texture_x+oceanimgscale,1+texture_y+oceanimgscale);
	glTexCoord2f(1.0, 0.0);glVertex2f(-1.5+texture_x-oceanimgscale,1+texture_y+oceanimgscale);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();

}

//³¬½Ã  
void Ocean::vessel(double vessel_x, double vessel_y){

	glPushMatrix();
	glScalef(FishingVessel,FishingVessel,FishingVessel);
	glTranslatef(-0.4+fishingx,0.2+fishingy,0);
	//glColor3f(0,0,1);
	glColor3f(boatred,boatgreen,boatblue);
	glBegin(GL_POLYGON);         // ¹è
	glVertex2f(0+vessel_x, 0+vessel_y);
	glVertex2f(0.2+vessel_x, -0.2+vessel_y);
	glVertex2f(0.5+vessel_x, -0.2+vessel_y);
	glVertex2f(0.72+vessel_x, 0+vessel_y);
	glEnd();
	glPopMatrix();


	glPushMatrix();
	glScalef(FishingVessel,FishingVessel,FishingVessel);
	glTranslatef(-0.4+fishingx,0.2+fishingy,0);
	
	//glColor3f(0,0.5,1);
	
	glColor3f(lboatred,lboatgreen,lboatblue);
	glBegin(GL_POLYGON);         // µÀ1
	glVertex2f(0.1+vessel_x, 0.02+vessel_y);
	glVertex2f(0.4+vessel_x, 0.02+vessel_y);
	glVertex2f(0.4+vessel_x, 0.52+vessel_y);
	glEnd();
	glPopMatrix();


	glPushMatrix();
	glScalef(FishingVessel,FishingVessel,FishingVessel);
	glTranslatef(-0.4+fishingx,0.2+fishingy,0);
	//glColor3f(0.5,1,1);
	glColor3f(rboatred,rboatgreen,rboatblue);
	glBegin(GL_POLYGON);         // µÀ2
	glVertex2f(0.42+vessel_x, 0.02+vessel_y);
	glVertex2f(0.42+vessel_x, 0.32+vessel_y);
	glVertex2f(0.62+vessel_x, 0.02+vessel_y);
	glEnd();
	glPopMatrix();
}
void Ocean::fishingrod(double fishingrod_x,double fishingrod_y){

	glPushMatrix(); 

	glScalef(FishingVessel,FishingVessel,FishingVessel);
	glTranslatef(-0.4+fishingx,0.2+fishingy,0);
	glRotatef(30,0,0,1);

	//glColor3f(0,1,0);
	glColor3f(fishingpred,fishingpgreen,fishingpblue);
	glBegin(GL_POLYGON);         // ³¬½Ã´ë
    glVertex2f(0+fishingrod_x,0+fishingrod_y);
	glVertex2f(0.02+fishingrod_x, 0+fishingrod_y);
	glVertex2f(0.02+fishingrod_x, 0.58+fishingrod_y);
	glVertex2f(0+fishingrod_x, 0.58+fishingrod_y);
	glEnd();
	glPopMatrix();
}
	void Ocean::fishingrod1(double fishingrod1_x,double fishingrod1_y){
	
	glPushMatrix();
	glScalef(FishingVessel,FishingVessel,FishingVessel);
	glTranslatef(-0.69+fishingx,0.7+fishingy,0);

	//glColor3f(1,1,1);
	glColor3f(fishingred,fishinggreen,fishingblue);
	glLineWidth(1.0);                    // ³¬½Ã¼± ¼±
	glBegin(GL_LINE_LOOP); 
	glVertex2f(0+fishingrod1_x,0+fishingrod1_y);
	glVertex2f(0+fishingrod1_x,-1.1+fishingrod1_y);
	glEnd();
	glPopMatrix();
}
void Ocean::FishingTexture(double texture_x,double texture_y){

	glPushMatrix();

	glEnable(GL_TEXTURE_2D);


	glPushMatrix();
	glScalef(FishingVessel,FishingVessel,FishingVessel);
	 glTranslatef(-1.4+fishingx,-0.8+fishingy,0);

	glColor3f(1,0,0);			//8x6»çÀÌÁî ÅØ½ºÃ³
	glBegin(GL_POLYGON); 
	 glTexCoord2f(1.0, 1.0);glVertex2f(0+texture_x-fishingimgscale,0+texture_y-fishingimgscale);
   glTexCoord2f(1.0, 0.0);glVertex2f(0+texture_x-fishingimgscale,0.4+texture_y+fishingimgscale);
   glTexCoord2f(0.0, 0.0);glVertex2f(0.4+texture_x+fishingimgscale,0.4+texture_y+fishingimgscale);
   glTexCoord2f(0.0, 1.0);glVertex2f(0.4+texture_x+fishingimgscale,0+texture_y-fishingimgscale);
	glEnd();
	
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();

}
