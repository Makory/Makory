#pragma once


// Film

class Film : public CWnd
{
	DECLARE_DYNAMIC(Film)

public:
	Film();
	virtual ~Film();

	
	void FilmCenter2(double filmcenter2_x,double filmcenter2_y, double filmcenter2_r, double filmcenter2_g, double filmcenter2_b);
	
	void FilmBody(double filmbody_x,double filmbody_y);
	
	void SlateBody(double slatebody_x,double slatebody_y);
	void SlateHead(double slatehead_x,double slatehead_y);

	void ProjectorBody(double ProjectorBody_x,double ProjectorBody_y,double ProjectorBody_r,double ProjectorBody_g,double ProjectorBody_b);
	void ProjectorCircle1(double ProjectorCircle1_x,double ProjectorCircle1_y);
	void ProjectorCircle2(double ProjectorCircle2_x,double ProjectorCircle2_y);

protected:
	DECLARE_MESSAGE_MAP()
};


