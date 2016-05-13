#pragma once

#define WIDTHBYTES(bits) (((bits)+31)/32*4)
#define BYTE    unsigned char

// HotAirBalloon

class HotAirBalloon : public CWnd
{
	DECLARE_DYNAMIC(HotAirBalloon)

public:
	HotAirBalloon();
	virtual ~HotAirBalloon();
	void drawSkyboxfront();
	void drawSkyboxback();
	void drawSkyboxleft();
	void drawSkyboxright();
	void drawSkyboxup();
	void drawSkyboxdown();
	void HotBalloonTexture(double hotballoontexture_x,double hotballoontexture_y,double hotballoontexture_z);
	void HotBalloonSphere(double HotBalloonLine_x,double HotBalloonLine_y,double HotBalloonLine_z);
	void HotBalloonLine(double HotBalloonLine_x,double HotBalloonLine_y,double HotBalloonLine_z);
	void HotAirBalloon::HotBalloonColor(double airballoonred, double airballoongreen, double airballoonblue);

	void DarkHotBalloonTexture(double hotballoontexture_x,double hotballoontexture_y,double hotballoontexture_z);
	void DarkHotBalloonSphere(double HotBalloonLine_x,double HotBalloonLine_y,double HotBalloonLine_z);
	void DarkHotBalloonLine(double HotBalloonLine_x,double HotBalloonLine_y,double HotBalloonLine_z);
	
	void FullHotBalloonTexture(double hotballoontexture_x,double hotballoontexture_y,double hotballoontexture_z);
	void FullHotBalloonSphere(double HotBalloonLine_x,double HotBalloonLine_y,double HotBalloonLine_z);
	void FullHotBalloonLine(double HotBalloonLine_x,double HotBalloonLine_y,double HotBalloonLine_z);

	void MountHotBalloonTexture(double hotballoontexture_x,double hotballoontexture_y,double hotballoontexture_z);
	void MountHotBalloonSphere(double HotBalloonLine_x,double HotBalloonLine_y,double HotBalloonLine_z);
	void MountHotBalloonLine(double HotBalloonLine_x,double HotBalloonLine_y,double HotBalloonLine_z);

	void SunsetHotBalloonTexture(double hotballoontexture_x,double hotballoontexture_y,double hotballoontexture_z);
	void SunsetHotBalloonSphere(double HotBalloonLine_x,double HotBalloonLine_y,double HotBalloonLine_z);
	void SunsetHotBalloonLine(double HotBalloonLine_x,double HotBalloonLine_y,double HotBalloonLine_z);

	void CloudsHotBalloonTexture(double hotballoontexture_x,double hotballoontexture_y,double hotballoontexture_z);
	void CloudsHotBalloonSphere(double HotBalloonLine_x,double HotBalloonLine_y,double HotBalloonLine_z);
	void CloudsHotBalloonLine(double HotBalloonLine_x,double HotBalloonLine_y,double HotBalloonLine_z);

	void TropicalHotBalloonTexture(double hotballoontexture_x,double hotballoontexture_y,double hotballoontexture_z);
	void TropicalHotBalloonSphere(double HotBalloonLine_x,double HotBalloonLine_y,double HotBalloonLine_z);
	void TropicalHotBalloonLine(double HotBalloonLine_x,double HotBalloonLine_y,double HotBalloonLine_z);

	double balloonred;
	double balloongreen;
	double balloonblue;

	double balloonx;
	double balloony;
	double balloonscale;

	double darkstormyred;
	double darkstormygreen;
	double darkstormyblue;
	double darkstormyx;
	double darkstormyy;
	double darkstormyscale;

	double fullmoonred;
	double fullmoongreen;
	double fullmoonblue;
	double fullmoonx;
	double fullmoony;
	double fullmoonscale;

	double mountred;
	double mountgreen;
	double mountblue;
	double mountx;
	double mounty;
	double mountscale;

	double sunsetred;
	double sunsetgreen;
	double sunsetblue;
	double sunsetx;
	double sunsety;
	double sunsetscale;

	double cloudsred;
	double cloudsgreen;
	double cloudsblue;
	double cloudsx;
	double cloudsy;
	double cloudsscale;

	double tropicalred;
	double tropicalgreen;
	double tropicalblue;
	double tropicalx;
	double tropicaly;
	double tropicalscale;
protected:
	DECLARE_MESSAGE_MAP()
public:

};


