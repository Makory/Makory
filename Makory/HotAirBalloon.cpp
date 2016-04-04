// HotAirBalloon.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "Makory.h"
#include "HotAirBalloon.h"

#define TEX_SIZE 100
#define GL_CLAMP_TO_EDGE 0x812F

// HotAirBalloon

IMPLEMENT_DYNAMIC(HotAirBalloon, CWnd)

HotAirBalloon::HotAirBalloon()
{

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

BEGIN_MESSAGE_MAP(HotAirBalloon, CWnd)
END_MESSAGE_MAP()



// HotAirBalloon 메시지 처리기입니다.


