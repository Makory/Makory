#pragma once

#include "BalloonDlg.h"
#include "FilmDlg.h"
#include "OceanDlg.h"
#include "SlateDlg.h"
#include "ProjectorDlg.h"
#include "WaveDlg.h"
#include "FishingDlg.h"
#include "ImageEditDlg.h"
#include "DarkStormyDlg.h"
#include "FullmoonDlg.h"
#include "MountainDlg.h"
#include "SunsetDlg.h"
#include "CloudsDlg.h"
#include "TropicalDlg.h"

class CEdittapCtrl : public CDialogEx
{
	DECLARE_DYNAMIC(CEdittapCtrl)

public:
	CEdittapCtrl(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CEdittapCtrl();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_EDITTAP_DIALOG };

	void ChangeContentTo(int templateType);
	void ChangeRedColorTo(int redcolor);

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEnChangeEdit1();

	virtual BOOL OnInitDialog() override;
	
	CBalloonDlg mBalloon;
	CFilmDlg mFilm;
	COceanDlg mOcean;
	CSlateDlg mSlate;
	CWaveDlg mWave;
	CFishingDlg mFishing;
	CImageEditDlg mImagedlg;
	CDarkStormyDlg mdarkdlg;
	CFullmoonDlg mfullmoon;

	CSunsetDlg msunset;
	CTropicalDlg mtropical;
	CCloudsDlg mclouds;
	CMountainDlg mmountain;


};
