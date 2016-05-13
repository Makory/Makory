// Ocean.cpp : ±∏«ˆ ∆ƒ¿œ¿‘¥œ¥Ÿ.
//

#include "stdafx.h"
#include "Makory.h"
#include "Ocean.h"
#include "MainFrm.h"
#include "MakoryDoc.h"
#include "MakoryView.h"
float OceanScale=0.6;

// Ocean

IMPLEMENT_DYNAMIC(Ocean, CWnd)

Ocean::Ocean()
{

}

Ocean::~Ocean()
{
}


BEGIN_MESSAGE_MAP(Ocean, CWnd)
END_MESSAGE_MAP()
// Ocean ∏ﬁΩ√¡ˆ √≥∏Æ±‚¿‘¥œ¥Ÿ.



 
   void Ocean::wave1(double wave1_x,double wave1_y,double wave1_z,double wave1_r,double wave1_g,double wave1_b) {
	
	glPushMatrix();
	glScalef(OceanScale,OceanScale,OceanScale);
	glTranslatef(0,0,0);

	GLfloat wave1point[6][3] = 
	{{ 0+wave1_x, -8+wave1_y, 0+wave1_z},{ 4+wave1_x, -6+wave1_y, 0+wave1_z},{ 0+wave1_x, -4+wave1_y, 0+wave1_z}, { -4+wave1_x, -2+wave1_y, 0+wave1_z}, { 0+wave1_x, 0+wave1_y, 0+wave1_z} };//«ÿ√ 

   glMap1f(GL_MAP1_VERTEX_3, 0.0, 1.0, 3, 6, &wave1point[0][0]);
   glEnable(GL_MAP1_VERTEX_3);

   int i;
   glColor3f(wave1_r,wave1_g,wave1_b);
    glLineWidth(20);
   glBegin(GL_LINE_STRIP);
      for (i = 0; i <= 30; i++) 
         glEvalCoord1f((GLfloat) i/30.0);
   glEnd();
   glPopMatrix();

   }
   



   void Ocean::wave2(double wave2_x,double wave2_y,double wave2_z,double wave2_r,double wave2_g,double wave2_b) {
	
	glPushMatrix();
	glScalef(OceanScale,OceanScale,OceanScale);
	glTranslatef(0,0,0);
	GLfloat wave2point[6][3] = 
	 {{ 0+wave2_x, -9+wave2_y, 0+wave2_z},{ 4+wave2_x, -7+wave2_y, 0+wave2_z},{ 0+wave2_x, -5+wave2_y, 0+wave2_z}, { -4+wave2_x, -3+wave2_y, 0+wave2_z}, { 0+wave2_x, 0+wave2_y, 0+wave2_z} };//«ÿ√ 
 

   glMap1f(GL_MAP1_VERTEX_3, 0.0, 1.0, 3, 6, &wave2point[0][0]);
   glEnable(GL_MAP1_VERTEX_3);

   int i;
   glColor3f(wave2_r,wave2_g,wave2_b);
    glLineWidth(20);
   glBegin(GL_LINE_STRIP);
      for (i = 0; i <= 30; i++) 
         glEvalCoord1f((GLfloat) i/30.0);
   glEnd();
   glPopMatrix();
   }
  
   
   void Ocean::wave3(double wave3_x,double wave3_y,double wave3_z,double wave3_r,double wave3_g,double wave3_b) {
	
	glPushMatrix();
	glScalef(OceanScale,OceanScale,OceanScale);
	glTranslatef(1,0,0);

	GLfloat wave3point[6][3] = 
	{{ 0+wave3_x, -8+wave3_y, 0+wave3_z},{ 4+wave3_x, -6+wave3_y, 0+wave3_z},{ 0+wave3_x, -4+wave3_y, 0+wave3_z}, { -4+wave3_x, -2+wave3_y, 0+wave3_z}, { 0+wave3_x, 0+wave3_y, 0+wave3_z} };//«ÿ√ 

   glMap1f(GL_MAP1_VERTEX_3, 0.0, 1.0, 3, 6, &wave3point[0][0]);
   glEnable(GL_MAP1_VERTEX_3);

   int i;
   glColor3f(wave3_r,wave3_g,wave3_b);
    glLineWidth(20);
   glBegin(GL_LINE_STRIP);
      for (i = 0; i <= 30; i++) 
         glEvalCoord1f((GLfloat) i/30.0);
   glEnd();
   glPopMatrix();

   }
   



   void Ocean::wave4(double wave4_x,double wave4_y,double wave4_z,double wave4_r,double wave4_g,double wave4_b) {
	
	glPushMatrix();
	glScalef(OceanScale,OceanScale,OceanScale);
	glTranslatef(1,0,0);
	GLfloat wave2point[6][3] = 
	 {{ 0+wave4_x, -9+wave4_y, 0+wave4_z},{ 4+wave4_x, -7+wave4_y, 0+wave4_z},{ 0+wave4_x, -5+wave4_y, 0+wave4_z}, { -4+wave4_x, -3+wave4_y, 0+wave4_z}, { 0+wave4_x, 0+wave4_y, 0+wave4_z} };//«ÿ√ 
 

   glMap1f(GL_MAP1_VERTEX_3, 0.0, 1.0, 3, 6, &wave2point[0][0]);
   glEnable(GL_MAP1_VERTEX_3);

   int i;
   glColor3f(wave4_r,wave4_g,wave4_b);
    glLineWidth(20);
   glBegin(GL_LINE_STRIP);
      for (i = 0; i <= 30; i++) 
         glEvalCoord1f((GLfloat) i/30.0);
   glEnd();
   glPopMatrix();
   }


    void Ocean::wave5(double wave5_x,double wave5_y,double wave5_z,double wave5_r,double wave5_g,double wave5_b) {
	
	glPushMatrix();
	glScalef(OceanScale,OceanScale,OceanScale);
	glTranslatef(2,0,0);

	GLfloat wave5point[6][3] = 
	{{ 0+wave5_x, -8+wave5_y, 0+wave5_z},{ 4+wave5_x, -6+wave5_y, 0+wave5_z},{ 0+wave5_x, -4+wave5_y, 0+wave5_z}, { -4+wave5_x, -2+wave5_y, 0+wave5_z}, { 0+wave5_x, 0+wave5_y, 0+wave5_z} };//«ÿ√ 

   glMap1f(GL_MAP1_VERTEX_3, 0.0, 1.0, 3, 6, &wave5point[0][0]);
   glEnable(GL_MAP1_VERTEX_3);

   int i;
   glColor3f(wave5_r,wave5_g,wave5_b);
    glLineWidth(20);
   glBegin(GL_LINE_STRIP);
      for (i = 0; i <= 30; i++) 
         glEvalCoord1f((GLfloat) i/30.0);
   glEnd();
   glPopMatrix();

   }
   



   void Ocean::wave6(double wave6_x,double wave6_y,double wave6_z,double wave6_r,double wave6_g,double wave6_b) {
	
	glPushMatrix();
	glScalef(OceanScale,OceanScale,OceanScale);
	glTranslatef(2,0,0);
	GLfloat wave2point[6][3] = 
	 {{ 0+wave6_x, -9+wave6_y, 0+wave6_z},{ 4+wave6_x, -7+wave6_y, 0+wave6_z},{ 0+wave6_x, -5+wave6_y, 0+wave6_z}, { -4+wave6_x, -3+wave6_y, 0+wave6_z}, { 0+wave6_x, 0+wave6_y, 0+wave6_z} };//«ÿ√ 
 

   glMap1f(GL_MAP1_VERTEX_3, 0.0, 1.0, 3, 6, &wave2point[0][0]);
   glEnable(GL_MAP1_VERTEX_3);

   int i;
   glColor3f(wave6_r,wave6_g,wave6_b);
    glLineWidth(20);
   glBegin(GL_LINE_STRIP);
      for (i = 0; i <= 30; i++) 
         glEvalCoord1f((GLfloat) i/30.0);
   glEnd();
   glPopMatrix();
   }



void Ocean::Fish2(double Fish2_x,double Fish2_y,double Fish2_z,double Fish2_r,double Fish2_g,double Fish2_b) {
	
	glPushMatrix();
	glScalef(OceanScale,OceanScale,OceanScale);
	glColor3f(1,1,0);//∏ˆ≈Î
	glBegin(GL_POLYGON); 
	glVertex2f(0+Fish2_x,0+Fish2_y);
	glVertex2f(0.5+Fish2_x,0.3+Fish2_y);
	glVertex2f(1+Fish2_x,0+Fish2_y);
	glVertex2f(0.5+Fish2_x,-0.3+Fish2_y);
	glEnd();
	glPopMatrix();


	glPushMatrix();
	glScalef(OceanScale,OceanScale,OceanScale);
	glLineWidth(2);//π´¥Ã
    glBegin(GL_LINES);
    glColor3f(1,0,0);
    glVertex2f(0.5+Fish2_x,0.3+Fish2_y);
    glVertex2f(0.5+Fish2_x,-0.3+Fish2_y);
	glEnd();
	glPopMatrix();



	glPushMatrix();
	glScalef(OceanScale,OceanScale,OceanScale);
	glLineWidth(2);//π´¥Ã
    glBegin(GL_LINES);
    glColor3f(1,0,0);
    glVertex2f(0.3+Fish2_x,0.19+Fish2_y);
    glVertex2f(0.3+Fish2_x,-0.19+Fish2_y);
	glEnd();
	glPopMatrix();




	glPushMatrix();
	glScalef(OceanScale,OceanScale,OceanScale);
	glColor3f(1,1,0);//≤ø∏Æ
	glBegin(GL_POLYGON); 
	glVertex2f(0+Fish2_x,0+Fish2_y);
	glVertex2f(-0.2+Fish2_x,0.2+Fish2_y);
	glVertex2f(-0.2+Fish2_x,-0.2+Fish2_y);
	glEnd();
	glPopMatrix();
	}

void Ocean::eyes(double eyes_x,double eyes_y){
	glPushMatrix();
	glScalef(OceanScale,OceanScale,OceanScale);

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


	   	glColor3f(1,1,1);//¥´
glBegin(GL_POLYGON);

for(j=0;j<=N;j++)
{
	angle = 2*PI*j/N;
	glVertex3f((X+eyes_x)+R * cos(angle),(Y+eyes_y)+R * sin(angle),0);
}
glEnd();
glPopMatrix();
 


glPushMatrix();
	glScalef(OceanScale,OceanScale,OceanScale);
glColor3f(0,0,0);//¥´
glBegin(GL_POLYGON);

for(j=0;j<=N;j++)
{
	angle = 2*PI*j/N;
	glVertex3f((X+eyes_x)+S * cos(angle),(Y+eyes_y)+S * sin(angle),0);
}
glEnd();
glPopMatrix();


glPushMatrix();
glScalef(OceanScale,OceanScale,OceanScale);
glColor3f(1,1,1);//¥´
glBegin(GL_POLYGON);

for(j=0;j<=N;j++)
{
	angle = 2*PI*j/N;
	glVertex3f((dX+eyes_x)+T * cos(angle),(dY+eyes_y)+T * sin(angle),0);
}
glEnd();
glPopMatrix();



   }

void Ocean::Fish3(double Fish3_x,double Fish3_y,double Fish3_z,double Fish3_r,double Fish3_g,double Fish3_b) {
	
	glPushMatrix();
	glScalef(OceanScale,OceanScale,OceanScale);
	glTranslatef(0,1,0);
	glColor3f(1,1,0);//∏ˆ≈Î
	glBegin(GL_POLYGON); 
	glVertex2f(0+Fish3_x,0+Fish3_y);
	glVertex2f(0.5+Fish3_x,0.3+Fish3_y);
	glVertex2f(1+Fish3_x,0+Fish3_y);
	glVertex2f(0.5+Fish3_x,-0.3+Fish3_y);
	glEnd();
	glPopMatrix();


	glPushMatrix();
	glScalef(OceanScale,OceanScale,OceanScale);
	glTranslatef(0,1,0);
	glLineWidth(2);//π´¥Ã
    glBegin(GL_LINES);
    glColor3f(1,0,0);
    glVertex2f(0.5+Fish3_x,0.3+Fish3_y);
    glVertex2f(0.5+Fish3_x,-0.3+Fish3_y);
	glEnd();
	glPopMatrix();



	glPushMatrix();
	glScalef(OceanScale,OceanScale,OceanScale);
	glTranslatef(0,1,0);
	glLineWidth(2);//π´¥Ã
    glBegin(GL_LINES);
    glColor3f(1,0,0);
    glVertex2f(0.3+Fish3_x,0.19+Fish3_y);
    glVertex2f(0.3+Fish3_x,-0.19+Fish3_y);
	glEnd();
	glPopMatrix();




	glPushMatrix();
	glScalef(OceanScale,OceanScale,OceanScale);
	glTranslatef(0,1,0);
	glColor3f(1,1,0);//≤ø∏Æ
	glBegin(GL_POLYGON); 
	glVertex2f(0+Fish3_x,0+Fish3_y);
	glVertex2f(-0.2+Fish3_x,0.2+Fish3_y);
	glVertex2f(-0.2+Fish3_x,-0.2+Fish3_y);
	glEnd();
	glPopMatrix();
	}

void Ocean::eyes2(double eyes2_x,double eyes2_y){
	glPushMatrix();
	glScalef(OceanScale,OceanScale,OceanScale);
	glTranslatef(0,1,0);

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


	   	glColor3f(1,1,1);//¥´
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
	glTranslatef(0,1,0);
glColor3f(0,0,0);//¥´
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
glTranslatef(0,1,0);
glColor3f(1,1,1);//¥´
glBegin(GL_POLYGON);

for(j=0;j<=N;j++)
{
	angle = 2*PI*j/N;
	glVertex3f((dX+eyes2_x)+T * cos(angle),(dY+eyes2_y)+T * sin(angle),0);
}
glEnd();
glPopMatrix();



   }






   void Ocean::Fish1(double Fish1_x,double Fish1_y,double Fish1_r,double Fish1_g,double Fish1_b) {


	glPushMatrix();
	glScalef(OceanScale,OceanScale,OceanScale);
	glBegin(GL_POLYGON);			//¥Ÿ∞¢«¸ ±◊∏Æ±‚
		glColor3f(1, 0, 0);	//ªˆªÛ º¬∆√
		// ∫∞¿ª ±◊∏Æ±‚ ¿ß«— ¡¬«• ¡§∫∏ º¬∆√
			glVertex2f(0.0+Fish1_x, -0.5+Fish1_y);
			glVertex2f(0.5+Fish1_x, -0.8+Fish1_y);
			glVertex2f(0.3+Fish1_x, -0.3+Fish1_y);
			glVertex2f(0.8+Fish1_x, 0.1+Fish1_y);
			glVertex2f(0.2+Fish1_x, 0.1+Fish1_y);
			glVertex2f(0.0+Fish1_x, 0.8+Fish1_y);
			glVertex2f(-0.2+Fish1_x, 0.1+Fish1_y);
			glVertex2f(-0.8+Fish1_x, 0.1+Fish1_y);
			glVertex2f(-0.3+Fish1_x, -0.3+Fish1_y);
			glVertex2f(-0.5+Fish1_x, -0.8+Fish1_y);
		glEnd();
		glPopMatrix();



   }

    
   void Ocean::eyesL(double eyes_x,double eyes_y){

	   glPushMatrix();
	glScalef(OceanScale,OceanScale,OceanScale);
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


	   	glColor3f(1,1,1);//¥´
glBegin(GL_POLYGON);

for(j=0;j<=N;j++)
{
	angle = 2*PI*j/N;
	glVertex3f((X+eyes_x)+R * cos(angle),(Y+eyes_y)+R * sin(angle),0);
}
glEnd();
glPopMatrix();
 


glPushMatrix();
glScalef(OceanScale,OceanScale,OceanScale);

glColor3f(0,0,0);//¥´
glBegin(GL_POLYGON);

for(j=0;j<=N;j++)
{
	angle = 2*PI*j/N;
	glVertex3f((X+eyes_x)+S * cos(angle),(Y+eyes_y)+S * sin(angle),0);
}
glEnd();
glPopMatrix();




glPushMatrix();
	glScalef(OceanScale,OceanScale,OceanScale);
glColor3f(1,1,1);//¥´
glBegin(GL_POLYGON);

for(j=0;j<=N;j++)
{
	angle = 2*PI*j/N;
	glVertex3f((dX+eyes_x)+T * cos(angle),(dY+eyes_y)+T * sin(angle),0);
}
glEnd();
glPopMatrix();



   }
   void Ocean::eyesR(double eyes_x,double eyes_y){

	   glPushMatrix();
	glScalef(OceanScale,OceanScale,OceanScale);
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


	   	glColor3f(1,1,1);//¥´
glBegin(GL_POLYGON);

for(j=0;j<=N;j++)
{
	angle = 2*PI*j/N;
	glVertex3f((X+eyes_x)+R * cos(angle),(Y+eyes_y)+R * sin(angle),0);
}
glEnd();
glPopMatrix();
 


glPushMatrix();
	glScalef(OceanScale,OceanScale,OceanScale);
glColor3f(0,0,0);//¥´
glBegin(GL_POLYGON);

for(j=0;j<=N;j++)
{
	angle = 2*PI*j/N;
	glVertex3f((X+eyes_x)+S * cos(angle),(Y+eyes_y)+S * sin(angle),0);
}
glEnd();
glPopMatrix();


glPushMatrix();
	glScalef(OceanScale,OceanScale,OceanScale);
glColor3f(1,1,1);//¥´
glBegin(GL_POLYGON);

for(j=0;j<=N;j++)
{
	angle = 2*PI*j/N;
	glVertex3f((dX+eyes_x)+T * cos(angle),(dY+eyes_y)+T * sin(angle),0);
}
glEnd();
glPopMatrix();



   }

   void Ocean::OceanTexture(double texture_x,double texture_y){


	

	glColor3f(1,1,1);			//8x6ªÁ¿Ã¡Ó ≈ÿΩ∫√≥
	glBegin(GL_POLYGON);
	glVertex2f(0+texture_x,0+texture_y);				//« ∏ß ªÁ¡¯ ≥÷¥¬∞¯∞£ 2
	glVertex2f(1+texture_x,0+texture_y);
	glVertex2f(1+texture_x,1+texture_y);
	glVertex2f(0+texture_x,1+texture_y);
	glEnd();

}




   
 void Ocean::Ship(double Ship_x,double Ship_y ,double Ship_r,double Ship_g,double Ship_b) {

	 glPushMatrix();
	glScalef(OceanScale,OceanScale,OceanScale);

	 GLfloat wavepoint1[6][3] = 
	{{ -10+Ship_x, 0+Ship_y, 0},{ -8+Ship_x, 0+Ship_y, 0},{ -7+Ship_x, -4+Ship_y, 0}, { -8.5+Ship_x, -6+Ship_y, 0}};//πË º±√º

   glMap1f(GL_MAP1_VERTEX_3, 0.0, 1.0, 3, 6, &wavepoint1[0][0]);
   glEnable(GL_MAP1_VERTEX_3);

   int i;
   glColor3f(Ship_r,Ship_g,Ship_b);
    glLineWidth(20);
   glBegin(GL_POLYGON);
      for (i = 0; i <= 30; i++) 
         glEvalCoord1f((GLfloat) i/30.0);
   glEnd();
   glPopMatrix();
   
   

   glPushMatrix();
	glScalef(OceanScale,OceanScale,OceanScale);
   
glColor3f(0,1,1);			//πË ¿ß¬ 
glBegin(GL_POLYGON); 
glVertex2f(-8+Ship_x,0+Ship_y);
glVertex2f(-8+Ship_x,2.4+Ship_y);
glVertex2f(-2.2+Ship_x,2.4+Ship_y);
glVertex2f(-2.2+Ship_x,0+Ship_y);
glEnd();
glPopMatrix();




glPushMatrix();
	glScalef(OceanScale,OceanScale,OceanScale);
glColor3f(0,1,0);	
glLineWidth(10.0);     //≥¨Ω√¥Î
glBegin(GL_LINE_STRIP); 
glVertex2f(-4+Ship_x,0+Ship_y);
glVertex2f(4+Ship_x,5.2+Ship_y);
glEnd();
glPopMatrix();


glPushMatrix();
	glScalef(OceanScale,OceanScale,OceanScale);
glColor3f(0,1,0);	
glLineWidth(3.0);     //≥¨Ω√πŸ¥√
glBegin(GL_LINE_STRIP); 
glVertex2f(4+Ship_x,5.2+Ship_y);
glVertex2f(4+Ship_x,-2.4+Ship_y);
glEnd();
glPopMatrix();
  }

 void Ocean::FishingTexture(double texture_x,double texture_y){
	

glColor3f(1,0,0);			//8x6ªÁ¿Ã¡Ó ≈ÿΩ∫√≥
glBegin(GL_POLYGON); 
glVertex2f(2+texture_x,-2+texture_y);
glVertex2f(2+texture_x,-4.4+texture_y);
glVertex2f(5.2+texture_x,-4.4+texture_y);
glVertex2f(5.2+texture_x,-2+texture_y);
glEnd();

}
   