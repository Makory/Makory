// Film.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "Makory.h"
#include "Film.h"
#include "MainFrm.h"
#include "MakoryDoc.h"
#include "MakoryView.h"
float FilmScale=2.5;
float SlateScale=3;
float ProjectorScale=2;

// Film

IMPLEMENT_DYNAMIC(Film, CWnd)

Film::Film()
{

}

Film::~Film()
{
}


BEGIN_MESSAGE_MAP(Film, CWnd)
END_MESSAGE_MAP()



// Film �޽��� ó�����Դϴ�.


void Film::FilmCenter2(double filmcenter2_x,double filmcenter2_y, double filmcenter2_r, double filmcenter2_g, double filmcenter2_b){
	
	glEnable(GL_TEXTURE_2D);
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glColor3f(filmcenter2_r,filmcenter2_g,filmcenter2_b);
	glScalef(FilmScale,FilmScale,FilmScale);
	glBegin(GL_POLYGON);
	glVertex2f(0.2+filmcenter2_x,0.79+filmcenter2_y);				//�ʸ� ���� �ִ°��� 2
	glTexCoord2f(0.0, 0.069); glVertex2f(0.25+filmcenter2_x,0.74+filmcenter2_y);
	glTexCoord2f(0.0, 0.931); glVertex2f(0.25+filmcenter2_x,0.26+filmcenter2_y);
	glTexCoord2f(0.09, 1.0); glVertex2f(0.2+filmcenter2_x,0.21+filmcenter2_y);
	glTexCoord2f(0.91, 1.0); glVertex2f(-0.25+filmcenter2_x,0.21+filmcenter2_y);
	glTexCoord2f(1.0, 0.931); glVertex2f(-0.3+filmcenter2_x,0.26+filmcenter2_y);
	glTexCoord2f(1.0, 0.069); glVertex2f(-0.3+filmcenter2_x,0.74+filmcenter2_y);
	glTexCoord2f(0.91, 0.0); glVertex2f(-0.25+filmcenter2_x,0.79+filmcenter2_y);
	glTexCoord2f(0.09, 0.0); glVertex2f(0.2+filmcenter2_x,0.79+filmcenter2_y);
	glEnd();

	glEnable(GL_DEPTH_TEST);
	glPopMatrix();
	glDisable(GL_TEXTURE_2D);
}

void Film::FilmBody(double filmbody_x,double filmbody_y){



	glPushMatrix();
	glColor3f(1,1,1);
	glScalef(FilmScale,FilmScale,FilmScale);
	glBegin(GL_POLYGON);
	glVertex2f(1+filmbody_x,0.2+filmbody_y);				//�׵θ�
	glVertex2f(1+filmbody_x,0.8+filmbody_y);
	glVertex2f(1.3+filmbody_x,0.8+filmbody_y);
	glVertex2f(1.3+filmbody_x,0.5+filmbody_y);
	glVertex2f(1.2+filmbody_x,0.5+filmbody_y);
	glVertex2f(1.2+filmbody_x,0.2+filmbody_y);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glColor3f(0,0,0);
	glScalef(FilmScale,FilmScale,FilmScale);
	glBegin(GL_POLYGON);
	glVertex2f(1+filmbody_x,0.98+filmbody_y);				//�� �׵θ�
	glVertex2f(1+filmbody_x,0.81+filmbody_y);
	glVertex2f(1.3+filmbody_x,0.81+filmbody_y);
	glVertex2f(1.3+filmbody_x,0.98+filmbody_y);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glColor3f(0,0,0);
	glScalef(FilmScale,FilmScale,FilmScale);
	glBegin(GL_POLYGON);
	glVertex2f(1+filmbody_x,0.19+filmbody_y);				//�Ʒ� �׵θ�
	glVertex2f(1+filmbody_x,0.02+filmbody_y);
	glVertex2f(1.2+filmbody_x,0.02+filmbody_y);
	glVertex2f(1.2+filmbody_x,0.19+filmbody_y);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glColor3f(1,1,1);
	glScalef(FilmScale,FilmScale,FilmScale);
	glBegin(GL_POLYGON);
	glVertex2f(1+filmbody_x,0.1+filmbody_y);				//�ʸ� �����簢�� �Ʒ� (x�� 0.16����)
	glVertex2f(1+filmbody_x,0.18+filmbody_y);
	glVertex2f(1.08+filmbody_x,0.18+filmbody_y);
	glVertex2f(1.08+filmbody_x,0.1+filmbody_y);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glColor3f(1,1,1);
	glScalef(FilmScale,FilmScale,FilmScale);
	glBegin(GL_POLYGON);
	glVertex2f(1.16+filmbody_x,0.1+filmbody_y);				//�ʸ� �����簢��(x�� 0.16����)
	glVertex2f(1.16+filmbody_x,0.18+filmbody_y);
	glVertex2f(1.2+filmbody_x,0.18+filmbody_y);
	glVertex2f(1.2+filmbody_x,0.1+filmbody_y);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glColor3f(1,1,1); //�ʸ� �� �����簢��
	glScalef(FilmScale,FilmScale,FilmScale);
	glBegin(GL_POLYGON);
	glVertex2f(1+filmbody_x,0.9+filmbody_y);				
	glVertex2f(1+filmbody_x,0.82+filmbody_y);
	glVertex2f(1.08+filmbody_x,0.82+filmbody_y);
	glVertex2f(1.08+filmbody_x,0.9+filmbody_y);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glColor3f(1,1,1); //�ʸ� �� �����簢��
	glScalef(FilmScale,FilmScale,FilmScale);
	glBegin(GL_POLYGON);
	glVertex2f(1.16+filmbody_x,0.9+filmbody_y);				
	glVertex2f(1.16+filmbody_x,0.82+filmbody_y);
	glVertex2f(1.24+filmbody_x,0.82+filmbody_y);
	glVertex2f(1.24+filmbody_x,0.9+filmbody_y);
	glEnd();
	glPopMatrix();
	//������� �ʸ� ������

	glPushMatrix();
	glColor3f(1,1,1);
	glScalef(FilmScale,FilmScale,FilmScale);
	glBegin(GL_POLYGON);
	glVertex2f(-1+filmbody_x,0.2+filmbody_y);				//�׵θ�
	glVertex2f(-1+filmbody_x,0.8+filmbody_y);
	glVertex2f(-1.3+filmbody_x,0.8+filmbody_y);
	glVertex2f(-1.3+filmbody_x,0.5+filmbody_y);
	glVertex2f(-1.2+filmbody_x,0.5+filmbody_y);
	glVertex2f(-1.2+filmbody_x,0.2+filmbody_y);
	glEnd();
	glPopMatrix();


	glPushMatrix();
	glColor3f(0,0,0);
	glScalef(FilmScale,FilmScale,FilmScale);
	glBegin(GL_POLYGON);
	glVertex2f(-1+filmbody_x,0.98+filmbody_y);				//�� �׵θ�
	glVertex2f(-1+filmbody_x,0.81+filmbody_y);
	glVertex2f(-1.3+filmbody_x,0.81+filmbody_y);
	glVertex2f(-1.3+filmbody_x,0.98+filmbody_y);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glColor3f(0,0,0);
	glScalef(FilmScale,FilmScale,FilmScale);
	glBegin(GL_POLYGON);
	glVertex2f(-1+filmbody_x,0.19+filmbody_y);				//�Ʒ� �׵θ�
	glVertex2f(-1+filmbody_x,0.02+filmbody_y);
	glVertex2f(-1.2+filmbody_x,0.02+filmbody_y);
	glVertex2f(-1.2+filmbody_x,0.19+filmbody_y);
	glEnd();
	glPopMatrix();


	glPushMatrix();
	glColor3f(1,1,1);
	glScalef(FilmScale,FilmScale,FilmScale);
	glBegin(GL_POLYGON);
	glVertex2f(-1+filmbody_x,0.1+filmbody_y);				//�ʸ� �����簢�� �Ʒ� (x�� 0.16����)
	glVertex2f(-1+filmbody_x,0.18+filmbody_y);
	glVertex2f(-1.08+filmbody_x,0.18+filmbody_y);
	glVertex2f(-1.08+filmbody_x,0.1+filmbody_y);
	glEnd();
	glPopMatrix();


	glPushMatrix();
	glColor3f(1,1,1);
	glScalef(FilmScale,FilmScale,FilmScale);
	glBegin(GL_POLYGON);
	glVertex2f(-1.16+filmbody_x,0.1+filmbody_y);				//�ʸ� �����簢��(x�� 0.16����)
	glVertex2f(-1.16+filmbody_x,0.18+filmbody_y);
	glVertex2f(-1.2+filmbody_x,0.18+filmbody_y);
	glVertex2f(-1.2+filmbody_x,0.1+filmbody_y);
	glEnd();
	glPopMatrix();
	

	glPushMatrix();
	glColor3f(1,1,1); //�ʸ� �� �����簢��
	glScalef(FilmScale,FilmScale,FilmScale);
	glBegin(GL_POLYGON);
	glVertex2f(-1+filmbody_x,0.9+filmbody_y);				
	glVertex2f(-1+filmbody_x,0.82+filmbody_y);
	glVertex2f(-1.08+filmbody_x,0.82+filmbody_y);
	glVertex2f(-1.08+filmbody_x,0.9+filmbody_y);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glColor3f(1,1,1); //�ʸ� �� �����簢��
	glScalef(FilmScale,FilmScale,FilmScale);
	glBegin(GL_POLYGON);
	glVertex2f(-1.16+filmbody_x,0.9+filmbody_y);				
	glVertex2f(-1.16+filmbody_x,0.82+filmbody_y);
	glVertex2f(-1.24+filmbody_x,0.82+filmbody_y);
	glVertex2f(-1.24+filmbody_x,0.9+filmbody_y);
	glEnd();
	glPopMatrix();
	//������� �ʸ� ����




	glPushMatrix();
	glColor3f(1,1,1);
	glScalef(FilmScale,FilmScale,FilmScale);
	glBegin(GL_POLYGON);
	glVertex2f(0.9+filmbody_x,0.2+filmbody_y);				//�׵θ�
	glVertex2f(0.9+filmbody_x,0.8+filmbody_y);
	glVertex2f(-0.9+filmbody_x,0.8+filmbody_y);
	glVertex2f(-0.9+filmbody_x,0.2+filmbody_y);
	glEnd();
	glPopMatrix();
	

	glPushMatrix();
	glColor3f(0,0,0);
	glScalef(FilmScale,FilmScale,FilmScale);
	glBegin(GL_POLYGON);
	glVertex2f(0.9+filmbody_x,0.98+filmbody_y);				//�� �׵θ�
	glVertex2f(0.9+filmbody_x,0.81+filmbody_y);
	glVertex2f(-0.9+filmbody_x,0.81+filmbody_y);
	glVertex2f(-0.9+filmbody_x,0.98+filmbody_y);
	glEnd();
	glPopMatrix();


	glPushMatrix();
	glColor3f(0,0,0);
	glScalef(FilmScale,FilmScale,FilmScale);
	glBegin(GL_POLYGON);
	glVertex2f(0.9+filmbody_x,0.19+filmbody_y);				//�Ʒ� �׵θ�
	glVertex2f(0.9+filmbody_x,0.02+filmbody_y);
	glVertex2f(-0.9+filmbody_x,0.02+filmbody_y);
	glVertex2f(-0.9+filmbody_x,0.19+filmbody_y);
	glEnd();
	glPopMatrix();


	glPushMatrix();
	glColor3f(1,1,1);
	glScalef(FilmScale,FilmScale,FilmScale);
	glBegin(GL_POLYGON);
	glVertex2f(0.9+filmbody_x,0.1+filmbody_y);				//�ʸ� �����簢��(x�� 0.16����)
	glVertex2f(0.9+filmbody_x,0.18+filmbody_y);
	glVertex2f(0.82+filmbody_x,0.18+filmbody_y);
	glVertex2f(0.82+filmbody_x,0.1+filmbody_y);
	glEnd();
	glPopMatrix();


	glPushMatrix();
	glColor3f(1,1,1);
	glScalef(FilmScale,FilmScale,FilmScale);
	glBegin(GL_POLYGON);
	glVertex2f(0.74+filmbody_x,0.1+filmbody_y);				//�ʸ� �����簢��
	glVertex2f(0.74+filmbody_x,0.18+filmbody_y);
	glVertex2f(0.66+filmbody_x,0.18+filmbody_y);
	glVertex2f(0.66+filmbody_x,0.1+filmbody_y);
	glEnd();
	glPopMatrix();


	glPushMatrix();
	glColor3f(1,1,1);
	glScalef(FilmScale,FilmScale,FilmScale);
	glBegin(GL_POLYGON);
	glVertex2f(0.58+filmbody_x,0.1+filmbody_y);				//�ʸ� �����簢��
	glVertex2f(0.58+filmbody_x,0.18+filmbody_y);
	glVertex2f(0.5+filmbody_x,0.18+filmbody_y);
	glVertex2f(0.5+filmbody_x,0.1+filmbody_y);
	glEnd();
	glPopMatrix();


	glPushMatrix();
	glColor3f(1,1,1);
	glScalef(FilmScale,FilmScale,FilmScale);
	glBegin(GL_POLYGON);
	glVertex2f(0.42+filmbody_x,0.1+filmbody_y);				//�ʸ� �����簢��
	glVertex2f(0.42+filmbody_x,0.18+filmbody_y);
	glVertex2f(0.34+filmbody_x,0.18+filmbody_y);
	glVertex2f(0.34+filmbody_x,0.1+filmbody_y);
	glEnd();
	glPopMatrix();


	glPushMatrix();
	glColor3f(1,1,1);
	glScalef(FilmScale,FilmScale,FilmScale);
	glBegin(GL_POLYGON);
	glVertex2f(0.26+filmbody_x,0.1+filmbody_y);				//�ʸ� �����簢��
	glVertex2f(0.26+filmbody_x,0.18+filmbody_y);
	glVertex2f(0.18+filmbody_x,0.18+filmbody_y);
	glVertex2f(0.18+filmbody_x,0.1+filmbody_y);
	glEnd();
	glPopMatrix();


	glPushMatrix();
	glColor3f(1,1,1);
	glScalef(FilmScale,FilmScale,FilmScale);
	glBegin(GL_POLYGON);
	glVertex2f(0.1+filmbody_x,0.1+filmbody_y);				//�ʸ� �����簢��
	glVertex2f(0.1+filmbody_x,0.18+filmbody_y);
	glVertex2f(0.02+filmbody_x,0.18+filmbody_y);
	glVertex2f(0.02+filmbody_x,0.1+filmbody_y);
	glEnd();
	glPopMatrix();


	glPushMatrix();
	glColor3f(1,1,1);
	glScalef(FilmScale,FilmScale,FilmScale);
	glBegin(GL_POLYGON);
	glVertex2f(-0.06+filmbody_x,0.1+filmbody_y);				//�ʸ� �����簢��
	glVertex2f(-0.06+filmbody_x,0.18+filmbody_y);
	glVertex2f(-0.14+filmbody_x,0.18+filmbody_y);
	glVertex2f(-0.14+filmbody_x,0.1+filmbody_y);
	glEnd();
	glPopMatrix();
	

	glPushMatrix();
	glColor3f(1,1,1);
	glScalef(FilmScale,FilmScale,FilmScale);
	glBegin(GL_POLYGON);
	glVertex2f(-0.22+filmbody_x,0.1+filmbody_y);				//�ʸ� �����簢��
	glVertex2f(-0.22+filmbody_x,0.18+filmbody_y);
	glVertex2f(-0.3+filmbody_x,0.18+filmbody_y);
	glVertex2f(-0.3+filmbody_x,0.1+filmbody_y);
	glEnd();
	glPopMatrix();
	
	

	glPushMatrix();
	glColor3f(1,1,1);
	glScalef(FilmScale,FilmScale,FilmScale);
	glBegin(GL_POLYGON);
	glVertex2f(-0.38+filmbody_x,0.1+filmbody_y);				//�ʸ� �����簢��
	glVertex2f(-0.38+filmbody_x,0.18+filmbody_y);
	glVertex2f(-0.46+filmbody_x,0.18+filmbody_y);
	glVertex2f(-0.46+filmbody_x,0.1+filmbody_y);
	glEnd();
	glPopMatrix();

	

	glPushMatrix();
	glColor3f(1,1,1);
	glScalef(FilmScale,FilmScale,FilmScale);
	glBegin(GL_POLYGON);
	glVertex2f(-0.54+filmbody_x,0.1+filmbody_y);				//�ʸ� �����簢��
	glVertex2f(-0.54+filmbody_x,0.18+filmbody_y);
	glVertex2f(-0.62+filmbody_x,0.18+filmbody_y);
	glVertex2f(-0.62+filmbody_x,0.1+filmbody_y);
	glEnd();
	glPopMatrix();


	glPushMatrix();
	glColor3f(1,1,1);
	glScalef(FilmScale,FilmScale,FilmScale);
	glBegin(GL_POLYGON);
	glVertex2f(-0.7+filmbody_x,0.1+filmbody_y);				//�ʸ� �����簢��
	glVertex2f(-0.7+filmbody_x,0.18+filmbody_y);
	glVertex2f(-0.78+filmbody_x,0.18+filmbody_y);
	glVertex2f(-0.78+filmbody_x,0.1+filmbody_y);
	glEnd();
	glPopMatrix();


	glPushMatrix();
	glColor3f(1,1,1);
	glScalef(FilmScale,FilmScale,FilmScale);
	glBegin(GL_POLYGON);
	glVertex2f(-0.83+filmbody_x,0.1+filmbody_y);				//�ʸ� �����簢��
	glVertex2f(-0.83+filmbody_x,0.18+filmbody_y);
	glVertex2f(-0.90+filmbody_x,0.18+filmbody_y);
	glVertex2f(-0.90+filmbody_x,0.1+filmbody_y);
	glEnd();
	glPopMatrix();
	
	
	
	glPushMatrix();//���� �ʸ� �簢��
	glColor3f(1,1,1);
	glScalef(FilmScale,FilmScale,FilmScale);
	glBegin(GL_POLYGON);
	glVertex2f(0.9+filmbody_x,0.9+filmbody_y);				
	glVertex2f(0.9+filmbody_x,0.82+filmbody_y);
	glVertex2f(0.82+filmbody_x,0.82+filmbody_y);
	glVertex2f(0.82+filmbody_x,0.9+filmbody_y);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glColor3f(1,1,1);
	glScalef(FilmScale,FilmScale,FilmScale);
	glBegin(GL_POLYGON);
	glVertex2f(0.74+filmbody_x,0.9+filmbody_y);				//�ʸ� �����簢��
	glVertex2f(0.74+filmbody_x,0.82+filmbody_y);
	glVertex2f(0.66+filmbody_x,0.82+filmbody_y);
	glVertex2f(0.66+filmbody_x,0.9+filmbody_y);
	glEnd();
	glPopMatrix();


	glPushMatrix();
	glColor3f(1,1,1);
	glScalef(FilmScale,FilmScale,FilmScale);
	glBegin(GL_POLYGON);
	glVertex2f(0.58+filmbody_x,0.9+filmbody_y);				//�ʸ� �����簢��
	glVertex2f(0.58+filmbody_x,0.82+filmbody_y);
	glVertex2f(0.5+filmbody_x,0.82+filmbody_y);
	glVertex2f(0.5+filmbody_x,0.9+filmbody_y);
	glEnd();
	glPopMatrix();


	glPushMatrix();
	glColor3f(1,1,1);
	glScalef(FilmScale,FilmScale,FilmScale);
	glBegin(GL_POLYGON);
	glVertex2f(0.42+filmbody_x,0.9+filmbody_y);				//�ʸ� �����簢��
	glVertex2f(0.42+filmbody_x,0.82+filmbody_y);
	glVertex2f(0.34+filmbody_x,0.82+filmbody_y);
	glVertex2f(0.34+filmbody_x,0.9+filmbody_y);
	glEnd();
	glPopMatrix();


	glPushMatrix();
	glColor3f(1,1,1);
	glScalef(FilmScale,FilmScale,FilmScale);
	glBegin(GL_POLYGON);
	glVertex2f(0.26+filmbody_x,0.9+filmbody_y);				//�ʸ� �����簢��
	glVertex2f(0.26+filmbody_x,0.82+filmbody_y);
	glVertex2f(0.18+filmbody_x,0.82+filmbody_y);
	glVertex2f(0.18+filmbody_x,0.9+filmbody_y);
	glEnd();
	glPopMatrix();



	glPushMatrix();
	glColor3f(1,1,1);
	glScalef(FilmScale,FilmScale,FilmScale);
	glBegin(GL_POLYGON);
	glVertex2f(0.1+filmbody_x,0.9+filmbody_y);				//�ʸ� �����簢��
	glVertex2f(0.1+filmbody_x,0.82+filmbody_y);
	glVertex2f(0.02+filmbody_x,0.82+filmbody_y);
	glVertex2f(0.02+filmbody_x,0.9+filmbody_y);
	glEnd();
	glPopMatrix();



	glPushMatrix();
	glColor3f(1,1,1);
	glScalef(FilmScale,FilmScale,FilmScale);
	glBegin(GL_POLYGON);
	glVertex2f(-0.06+filmbody_x,0.9+filmbody_y);				//�ʸ� �����簢��
	glVertex2f(-0.06+filmbody_x,0.82+filmbody_y);
	glVertex2f(-0.14+filmbody_x,0.82+filmbody_y);
	glVertex2f(-0.14+filmbody_x,0.9+filmbody_y);
	glEnd();
	glPopMatrix();
	


	glPushMatrix();
	glColor3f(1,1,1);
	glScalef(FilmScale,FilmScale,FilmScale);
	glBegin(GL_POLYGON);
	glVertex2f(-0.22+filmbody_x,0.9+filmbody_y);				//�ʸ� �����簢��
	glVertex2f(-0.22+filmbody_x,0.82+filmbody_y);
	glVertex2f(-0.3+filmbody_x,0.82+filmbody_y);
	glVertex2f(-0.3+filmbody_x,0.9+filmbody_y);
	glEnd();

	glPopMatrix();
	


	glPushMatrix();
	glColor3f(1,1,1);
	glScalef(FilmScale,FilmScale,FilmScale);
	glBegin(GL_POLYGON);
	glVertex2f(-0.38+filmbody_x,0.9+filmbody_y);				//�ʸ� �����簢��
	glVertex2f(-0.38+filmbody_x,0.82+filmbody_y);
	glVertex2f(-0.46+filmbody_x,0.82+filmbody_y);
	glVertex2f(-0.46+filmbody_x,0.9+filmbody_y);
	glEnd();
	glPopMatrix();

	


	glPushMatrix();
	glColor3f(1,1,1);
	glScalef(FilmScale,FilmScale,FilmScale);
	glBegin(GL_POLYGON);
	glVertex2f(-0.54+filmbody_x,0.9+filmbody_y);				//�ʸ� �����簢��
	glVertex2f(-0.54+filmbody_x,0.82+filmbody_y);
	glVertex2f(-0.62+filmbody_x,0.82+filmbody_y);
	glVertex2f(-0.62+filmbody_x,0.9+filmbody_y);
	glEnd();
	glPopMatrix();



	glPushMatrix();
	glColor3f(1,1,1);
	glScalef(FilmScale,FilmScale,FilmScale);
	glBegin(GL_POLYGON);
	glVertex2f(-0.7+filmbody_x,0.9+filmbody_y);				//�ʸ� �����簢��
	glVertex2f(-0.7+filmbody_x,0.82+filmbody_y);
	glVertex2f(-0.78+filmbody_x,0.82+filmbody_y);
	glVertex2f(-0.78+filmbody_x,0.9+filmbody_y);
	glEnd();
	glPopMatrix();




	glPushMatrix();
	glColor3f(1,1,1);
	glScalef(FilmScale,FilmScale,FilmScale);
	glBegin(GL_POLYGON);
	glVertex2f(-0.83+filmbody_x,0.9+filmbody_y);				//�ʸ� �����簢��
	glVertex2f(-0.83+filmbody_x,0.82+filmbody_y);
	glVertex2f(-0.90+filmbody_x,0.82+filmbody_y);
	glVertex2f(-0.90+filmbody_x,0.9+filmbody_y);
	glEnd();
	glPopMatrix();
}





void Film::SlateBody(double slatebody_x,double slatebody_y){


	glPushMatrix();
	glColor3f(0,0,0);			//������Ʈ
	glScalef(SlateScale,SlateScale,SlateScale);
	glBegin(GL_POLYGON);
	glVertex2f(0.0+slatebody_x,0.0+slatebody_y);				
	glVertex2f(0.8+slatebody_x,0.0+slatebody_y);
	glVertex2f(0.8+slatebody_x,0.35+slatebody_y);
	glVertex2f(0.0+slatebody_x,0.35+slatebody_y);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glColor3f(0,0,0);			//������Ʈ ������� �Ʒ�
	glScalef(SlateScale,SlateScale,SlateScale);
	glBegin(GL_POLYGON);
	glVertex2f(0.0+slatebody_x,0.35+slatebody_y);				
	glVertex2f(0.0+slatebody_x,0.5+slatebody_y);
	glVertex2f(0.8+slatebody_x,0.5+slatebody_y);
	glVertex2f(0.8+slatebody_x,0.35+slatebody_y);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glColor3f(1,1,1);			//������Ʈ ���� �� ���簢��
	glScalef(SlateScale,SlateScale,SlateScale);
	glBegin(GL_POLYGON);
	glVertex2f(0.2+slatebody_x,0.35+slatebody_y);				
	glVertex2f(0.35+slatebody_x,0.35+slatebody_y);
	glVertex2f(0.4+slatebody_x,0.5+slatebody_y);
	glVertex2f(0.25+slatebody_x,0.5+slatebody_y);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glColor3f(1,1,1);			//������Ʈ ���� �� ���簢��
	glScalef(SlateScale,SlateScale,SlateScale);
	glBegin(GL_POLYGON);
	glVertex2f(0.5+slatebody_x,0.35+slatebody_y);				
	glVertex2f(0.65+slatebody_x,0.35+slatebody_y);
	glVertex2f(0.7+slatebody_x,0.5+slatebody_y);
	glVertex2f(0.55+slatebody_x,0.5+slatebody_y);
	glEnd();
	glPopMatrix();


	glPushMatrix();
	glColor3f(1,1,1);			//������Ʈ �����
	glScalef(SlateScale,SlateScale,SlateScale);
	glBegin(GL_POLYGON);
	glVertex2f(0.01+slatebody_x,0.4+slatebody_y);				
	glVertex2f(0.16+slatebody_x,0.4+slatebody_y);
	glVertex2f(0.16+slatebody_x,0.45+slatebody_y);
	glVertex2f(0.06+slatebody_x,0.6+slatebody_y);
	glVertex2f(0.01+slatebody_x,0.6+slatebody_y);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glColor3f(0,0,0);			//������Ʈ ����� �� �簢��
	glScalef(SlateScale,SlateScale,SlateScale);
	glBegin(GL_POLYGON);
	glVertex2f(0.02+slatebody_x,0.45+slatebody_y);				
	glVertex2f(0.05+slatebody_x,0.45+slatebody_y);
	glVertex2f(0.05+slatebody_x,0.41+slatebody_y);
	glVertex2f(0.02+slatebody_x,0.41+slatebody_y);
	glEnd();
	glPopMatrix();


	glPushMatrix();
	glColor3f(0,0,0);			//������Ʈ ����� �� �簢��
	glScalef(SlateScale,SlateScale,SlateScale);
	glBegin(GL_POLYGON);
	glVertex2f(0.11+slatebody_x,0.45+slatebody_y);				
	glVertex2f(0.14+slatebody_x,0.45+slatebody_y);
	glVertex2f(0.14+slatebody_x,0.41+slatebody_y);
	glVertex2f(0.11+slatebody_x,0.41+slatebody_y);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glColor3f(0,0,0);			//������Ʈ ����� �� �簢��
	glScalef(SlateScale,SlateScale,SlateScale);
	glBegin(GL_POLYGON);
	glVertex2f(0.02+slatebody_x,0.59+slatebody_y);				
	glVertex2f(0.05+slatebody_x,0.59+slatebody_y);
	glVertex2f(0.05+slatebody_x,0.55+slatebody_y);
	glVertex2f(0.02+slatebody_x,0.55+slatebody_y);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glColor3f(1,1,1);			//�����
	glScalef(SlateScale,SlateScale,SlateScale);
	glLineWidth(5.0);
	glBegin(GL_LINES);
	glVertex2f(0.0+slatebody_x,0.3+slatebody_y);				
	glVertex2f(0.8+slatebody_x,0.3+slatebody_y);
	glEnd();
	glPopMatrix();


	glPushMatrix();
	glColor3f(1,1,1);			//�� �ؼ�
	glScalef(SlateScale,SlateScale,SlateScale);
	glLineWidth(5.0);
	glBegin(GL_LINES);
	glVertex2f(0.0+slatebody_x,0.1+slatebody_y);				
	glVertex2f(0.8+slatebody_x,0.1+slatebody_y);
	glEnd();
	glPopMatrix();
	

	glPushMatrix();
	glColor3f(1,1,1);			//�� �ؼ�
	glScalef(SlateScale,SlateScale,SlateScale);
	glLineWidth(5.0);
	glBegin(GL_LINES);
	glVertex2f(0.4+slatebody_x,0.1+slatebody_y);				
	glVertex2f(0.4+slatebody_x,0.3+slatebody_y);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glColor3f(1,1,1);			//�� �ؼ�
	glScalef(SlateScale,SlateScale,SlateScale);
	glLineWidth(5.0);
	glBegin(GL_LINES);
	glVertex2f(0.0+slatebody_x,0.35+slatebody_y);				
	glVertex2f(0.8+slatebody_x,0.35+slatebody_y);
	glEnd();
	glPopMatrix();

}

void Film::SlateHead(double slatehead_x,double slatehead_y){
	
	glPushMatrix();
	glColor3f(0,0,0);		//������Ʈ ������� ��
	glScalef(SlateScale,SlateScale,SlateScale);
	glTranslatef(0,0,0);
	glBegin(GL_POLYGON);
	glVertex2f(0.0+slatehead_x,0.5+slatehead_y);				
	glVertex2f(-0.015+slatehead_x,0.65+slatehead_y);
	glVertex2f(0.785+slatehead_x,0.8+slatehead_y);
	glVertex2f(0.8+slatehead_x,0.65+slatehead_y);
	glEnd();
	glPopMatrix();
	
	glPushMatrix();
	glColor3f(1,1,1);			//������Ʈ ������� �� ���簢��
	glScalef(SlateScale,SlateScale,SlateScale);
	glTranslatef(0,0,0);
	glBegin(GL_POLYGON);
	glVertex2f(0.2+slatehead_x,0.69+slatehead_y);				
	glVertex2f(0.35+slatehead_x,0.72+slatehead_y);
	glVertex2f(0.4+slatehead_x,0.58+slatehead_y);
	glVertex2f(0.25+slatehead_x,0.55+slatehead_y);
	glEnd();
	glPopMatrix();


	glPushMatrix();	
	glColor3f(1,1,1);			//������Ʈ ������� �� ���簢��
	glScalef(SlateScale,SlateScale,SlateScale);
	glTranslatef(0,0,0);
	glBegin(GL_POLYGON);
	glVertex2f(0.5+slatehead_x,0.745+slatehead_y);				
	glVertex2f(0.65+slatehead_x,0.775+slatehead_y);
	glVertex2f(0.7+slatehead_x,0.635+slatehead_y);
	glVertex2f(0.55+slatehead_x,0.605+slatehead_y);
	glEnd();
	glPopMatrix();

}


void Film::ProjectorBody(double ProjectorBody_x,double ProjectorBody_y,double ProjectorBody_r,double ProjectorBody_g,double ProjectorBody_b){


glPushMatrix();	
glColor3f(ProjectorBody_r,ProjectorBody_g,ProjectorBody_b);
glScalef(ProjectorScale,ProjectorScale,ProjectorScale);
glTranslatef(0,0.3,0);
glBegin(GL_POLYGON);
glVertex2f(-0.25+ProjectorBody_x,0.3+ProjectorBody_y);
glVertex2f(0.45+ProjectorBody_x,0.3+ProjectorBody_y);
glVertex2f(0.45+ProjectorBody_x,-0.2+ProjectorBody_y);
glVertex2f(-0.25+ProjectorBody_x,-0.2+ProjectorBody_y);
glEnd();
glPopMatrix();




glPushMatrix();	
glColor3f(ProjectorBody_r,ProjectorBody_g,ProjectorBody_b);
glScalef(ProjectorScale,ProjectorScale,ProjectorScale);
glTranslatef(0,0.3,0);
glBegin(GL_POLYGON);
glVertex2f(-0.05+ProjectorBody_x,-0.2+ProjectorBody_y);
glVertex2f(0.25+ProjectorBody_x,-0.2+ProjectorBody_y);
glVertex2f(0.25+ProjectorBody_x,-0.25+ProjectorBody_y);
glVertex2f(-0.05+ProjectorBody_x,-0.25+ProjectorBody_y);
glEnd();
glPopMatrix();



glPushMatrix();	
glColor3f(ProjectorBody_r,ProjectorBody_g,ProjectorBody_b);
glScalef(ProjectorScale,ProjectorScale,ProjectorScale);
glTranslatef(0,0.3,0);
glBegin(GL_POLYGON);
glVertex2f(0.45+ProjectorBody_x,0.15+ProjectorBody_y);
glVertex2f(0.45+ProjectorBody_x,-0.05+ProjectorBody_y);
glVertex2f(0.75+ProjectorBody_x,-0.15+ProjectorBody_y);
glVertex2f(0.75+ProjectorBody_x,0.25+ProjectorBody_y);
glEnd();
glPopMatrix();
}


void Film::ProjectorCircle1(double ProjectorCircle1_x,double ProjectorCircle1_y){

glPushMatrix();	

float PI=3.141592;
float angle;
int i,N=100;
float X=0.3;
float Y=0.5;
float R=0.2;
float S=0.06;



glColor3f(1,1,1);
glScalef(ProjectorScale,ProjectorScale,ProjectorScale);
glTranslatef(0,0.3,0);
glBegin(GL_POLYGON);

for(i=0;i<=N;i++)
{
	angle = 2*PI*i/N;
	glVertex3f((X+ProjectorCircle1_x)+R * cos(angle),(Y+ProjectorCircle1_y)+R * sin(angle),0);
}
glEnd();
glPopMatrix();
 


glPushMatrix();	
glColor3f(0,0,0);
glScalef(ProjectorScale,ProjectorScale,ProjectorScale);
glTranslatef(0,0.3,0);
glBegin(GL_POLYGON);

for(i=0;i<=N;i++)
{
	angle = 2*PI*i/N;
	glVertex3f((X+ProjectorCircle1_x)+S * cos(angle),(Y+ProjectorCircle1_x)+S * sin(angle),0);
}
glEnd();
glPopMatrix();
}

void Film::ProjectorCircle2(double ProjectorCircle2_x,double ProjectorCircle2_y){//���� ���� 12�ù��� 3�� 6�� 9�� ���ư��Բ� �������

glPushMatrix();		
float PI=3.141592;
float angle;
int i,N=100;
float X1=-0.1;
float Y1=0.5;
float R=0.2;
float S=0.06;

glColor3f(1,1,1);
glScalef(ProjectorScale,ProjectorScale,ProjectorScale);
glTranslatef(0,0.3,0);
glBegin(GL_POLYGON);

for(i=0;i<=N;i++)
{
	angle = 2*PI*i/N;
	glVertex3f((X1+ProjectorCircle2_x)+R * cos(angle),(Y1+ProjectorCircle2_y)+R * sin(angle),0);
}
glEnd();
glPopMatrix();
 


glPushMatrix();	
glColor3f(0,0,0);
glScalef(ProjectorScale,ProjectorScale,ProjectorScale);
glTranslatef(0,0.3,0);
glBegin(GL_POLYGON);

for(i=0;i<=N;i++)
{
	angle = 2*PI*i/N;
	glVertex3f((X1+ProjectorCircle2_x)+S * cos(angle),(Y1+ProjectorCircle2_y)+S * sin(angle),0);
}
glEnd();
glPopMatrix();


}

