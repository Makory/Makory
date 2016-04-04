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

protected:
	DECLARE_MESSAGE_MAP()
};


