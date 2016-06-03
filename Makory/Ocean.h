#pragma once


// Ocean

class Ocean : public CWnd
{
	DECLARE_DYNAMIC(Ocean)

public:
	Ocean();
	virtual ~Ocean();

	void wave1(double wave1_x,double wave1_y,double wave1_z,double wave1_r,double wave1_g,double wave1_b);
	void WaveTexture(double texture_x,double texture_y);


	void CircleFishEyes(double eyes_x,double eyes_y);
	void CircleFish(double circlefish_x, double circlefish_y);

	void CircleFishEyes1(double eyes_x,double eyes_y);
	void CircleFish1(double circlefish_x, double circlefish_y);

	void StarFish1(double StarFish1_x,double StarFish1_y,double StarFish1_r,double StarFish1_g,double StarFish1_b, double rotate);
	void StarFish1eyesR(double StarFish1eyesR_x,double StarFish1eyesR_y, double rotate);
	void StarFish1eyesL(double StarFish1eyesL_x,double StarFish1eyesL_y, double rotate);

	void StarFish2(double StarFish2_x,double StarFish2_y,double StarFish2_r,double StarFish2_g,double StarFish2_b, double rotate);
	void StarFish2eyesR(double StarFish2eyesR_x,double StarFish2eyesR_y, double rotate);
	void StarFish2eyesL(double StarFish2eyesL_x,double StarFish2eyesL_y, double rotate);

	void Fish2(double Fish2_x,double Fish2_y,double Fish2_z,double Fish2_r,double Fish2_g,double Fish2_b);
	void eyes2(double eyes2_x,double eyes2_y);

	void Fish3(double Fish3_x,double Fish3_y,double Fish3_z,double Fish3_r,double Fish3_g,double Fish3_b);
	void eyes3(double eyes3_x,double eyes3_y);
	void OceanTexture(double texture_x,double texture_y,double rotate);
	
	void vessel(double vessel_x, double vessel_y);
	void fishingrod(double fishingrod_x,double fishingrod_y);
	void fishingrod1(double fishingrod1_x,double fishingrod1_y);
	void FishingTexture(double texture_x,double texture_y);

public:

	double fishred;
	double fishgreen;
	double fishblue;
	double fishx;
	double fishy;
	double FishScale;

	double sfishred;
	double sfishgreen;
	double sfishblue;
	double sfishx;
	double sfishy;
	double sfishscale;

	double sfishred2;
	double sfishgreen2;
	double sfishblue2;
	double sfishx2;
	double sfishy2;
	double sfishscale2;

	double starred;
	double stargreen;
	double starblue;
	double starx;
	double stary;
	double starscale;

	double boatred;
	double boatgreen;
	double boatblue;
	double boatx;
	double boaty;
	double boatcale;

	double lboatred;
	double lboatgreen;
	double lboatblue;

	double rboatred;
	double rboatgreen;
	double rboatblue;

	double fishingpred;
	double fishingpgreen;
	double fishingpblue;

	double fishingred;
	double fishinggreen;
	double fishingblue;

	double fishingx;
	double fishingy;

	float OceanScale;
	float FishingScale;
	float FishingVessel;
	double fishingscale;
	double wavey;
	double fishscale;
	double waveimgscale;
	double oceanimgscale;
	double fishingimgscale;
	double eyescale;
protected:
	DECLARE_MESSAGE_MAP()
};


