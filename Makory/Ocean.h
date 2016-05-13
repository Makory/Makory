#pragma once


// Ocean

class Ocean : public CWnd
{
	DECLARE_DYNAMIC(Ocean)

public:
	Ocean();
	virtual ~Ocean();

	void wave1(double wave1_x,double wave1_y,double wave1_z,double wave1_r,double wave1_g,double wave1_b);
	void wave2(double wave2_x,double wave2_y,double wave2_z,double wave2_r,double wave2_g,double wave2_b);
	void wave3(double wave3_x,double wave3_y,double wave3_z,double wave3_r,double wave3_g,double wave3_b);
	void wave4(double wave4_x,double wave4_y,double wave4_z,double wave4_r,double wave4_g,double wave4_b);
	void wave5(double wave5_x,double wave5_y,double wave5_z,double wave5_r,double wave5_g,double wave5_b);
	void wave6(double wave6_x,double wave6_y,double wave6_z,double wave6_r,double wave6_g,double wave6_b);

	void Fish2(double Fish2_x,double Fish2_y,double Fish2_z,double Fish2_r,double Fish2_g,double Fish2_b);
	void Fish3(double Fish3_x,double Fish3_y,double Fish3_z,double Fish3_r,double Fish3_g,double Fish3_b);
	void eyes2(double eyes2_x,double eyes2_y);


	void Fish1(double Fish1_x,double Fish1_y,double Fish1_r,double Fish1_g,double Fish1_b);
	void eyesR(double eyes_x,double eyes_y);
	void eyesL(double eyes_x,double eyes_y);
	void eyes(double eyes_x,double eyes_y);
	void OceanTexture(double texture_x,double texture_y);
	
	void Ship(double Ship_x,double Ship_y ,double Ship_r,double Ship_g,double Ship_b);
	void FishingTexture(double texture_x,double texture_y);

protected:
	DECLARE_MESSAGE_MAP()
};


