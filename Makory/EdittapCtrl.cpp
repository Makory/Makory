// EdittapCtrl.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "Makory.h"
#include "EdittapCtrl.h"
#include "afxdialogex.h"


// CEdittapCtrl 대화 상자입니다.

IMPLEMENT_DYNAMIC(CEdittapCtrl, CDialogEx)

	CEdittapCtrl::CEdittapCtrl(CWnd* pParent /*=NULL*/)
	: CDialogEx(CEdittapCtrl::IDD, pParent)
{

}

CEdittapCtrl::~CEdittapCtrl()
{
}

void CEdittapCtrl::ChangeContentTo(int templateType)
{
	if (1 == templateType)
	{
		mBalloon.ShowWindow(SW_SHOW);
		// hide others here
		mFilm.ShowWindow(SW_HIDE);
		mOcean.ShowWindow(SW_HIDE);
		mSlate.ShowWindow(SW_HIDE);
		mWave.ShowWindow(SW_HIDE);
		mFishing.ShowWindow(SW_HIDE);
		mImagedlg.ShowWindow(SW_HIDE);
		mdarkdlg.ShowWindow(SW_HIDE);
		mfullmoon.ShowWindow(SW_HIDE);
		mmountain.ShowWindow(SW_HIDE);
		msunset.ShowWindow(SW_HIDE);
		mtropical.ShowWindow(SW_HIDE);
		mclouds.ShowWindow(SW_HIDE);
		mproj.ShowWindow(SW_HIDE);

	}
	else if (2 == templateType)
	{
		mdarkdlg.ShowWindow(SW_SHOW);
		// hide others here
		mBalloon.ShowWindow(SW_HIDE);
		mOcean.ShowWindow(SW_HIDE);
		mSlate.ShowWindow(SW_HIDE);
		mWave.ShowWindow(SW_HIDE);
		mFishing.ShowWindow(SW_HIDE);
		mImagedlg.ShowWindow(SW_HIDE);
		mFilm.ShowWindow(SW_HIDE);
		mfullmoon.ShowWindow(SW_HIDE);
		mmountain.ShowWindow(SW_HIDE);
		msunset.ShowWindow(SW_HIDE);
		mtropical.ShowWindow(SW_HIDE);
		mclouds.ShowWindow(SW_HIDE);
		mproj.ShowWindow(SW_HIDE);

	}
	else if (3 == templateType)
	{

		mfullmoon.ShowWindow(SW_SHOW);
		// hide others here
		mmountain.ShowWindow(SW_HIDE);
		mBalloon.ShowWindow(SW_HIDE);
		mFilm.ShowWindow(SW_HIDE);
		mSlate.ShowWindow(SW_HIDE);
		mWave.ShowWindow(SW_HIDE);
		mOcean.ShowWindow(SW_HIDE);
		mImagedlg.ShowWindow(SW_HIDE);
		mdarkdlg.ShowWindow(SW_HIDE);
		mFishing.ShowWindow(SW_HIDE);
		msunset.ShowWindow(SW_HIDE);
		mtropical.ShowWindow(SW_HIDE);
		mclouds.ShowWindow(SW_HIDE);
		mproj.ShowWindow(SW_HIDE);

	}
	else if (4 == templateType)
	{

		mmountain.ShowWindow(SW_SHOW);
		// hide others here
		mBalloon.ShowWindow(SW_HIDE);
		mFilm.ShowWindow(SW_HIDE);
		mSlate.ShowWindow(SW_HIDE);
		mWave.ShowWindow(SW_HIDE);
		mOcean.ShowWindow(SW_HIDE);
		mImagedlg.ShowWindow(SW_HIDE);
		mdarkdlg.ShowWindow(SW_HIDE);
		mFishing.ShowWindow(SW_HIDE);
		mfullmoon.ShowWindow(SW_HIDE);
		msunset.ShowWindow(SW_HIDE);
		mtropical.ShowWindow(SW_HIDE);
		mclouds.ShowWindow(SW_HIDE);
		mproj.ShowWindow(SW_HIDE);
	
	}

	else if (5 == templateType)
	{

		msunset.ShowWindow(SW_SHOW);
		// hide others here
		mBalloon.ShowWindow(SW_HIDE);
		mFilm.ShowWindow(SW_HIDE);
		mSlate.ShowWindow(SW_HIDE);
		mWave.ShowWindow(SW_HIDE);
		mOcean.ShowWindow(SW_HIDE);
		mImagedlg.ShowWindow(SW_HIDE);
		mdarkdlg.ShowWindow(SW_HIDE);
		mFishing.ShowWindow(SW_HIDE);
		mfullmoon.ShowWindow(SW_HIDE);
		mmountain.ShowWindow(SW_HIDE);
		mtropical.ShowWindow(SW_HIDE);
		mclouds.ShowWindow(SW_HIDE);
		mproj.ShowWindow(SW_HIDE);
		
	}

	else if (6 == templateType)
	{

		mclouds.ShowWindow(SW_SHOW);
		// hide others here
		mBalloon.ShowWindow(SW_HIDE);
		mFilm.ShowWindow(SW_HIDE);
		mSlate.ShowWindow(SW_HIDE);
		mWave.ShowWindow(SW_HIDE);
		mOcean.ShowWindow(SW_HIDE);
		mImagedlg.ShowWindow(SW_HIDE);
		mdarkdlg.ShowWindow(SW_HIDE);
		mFishing.ShowWindow(SW_HIDE);
		mfullmoon.ShowWindow(SW_HIDE);
		mmountain.ShowWindow(SW_HIDE);
		msunset.ShowWindow(SW_HIDE);
		mtropical.ShowWindow(SW_HIDE);
		mproj.ShowWindow(SW_HIDE);
		

	}
	else if (7 == templateType)
	{

		mtropical.ShowWindow(SW_SHOW);
		// hide others here
		mBalloon.ShowWindow(SW_HIDE);
		mFilm.ShowWindow(SW_HIDE);
		mSlate.ShowWindow(SW_HIDE);
		mWave.ShowWindow(SW_HIDE);
		mOcean.ShowWindow(SW_HIDE);
		mImagedlg.ShowWindow(SW_HIDE);
		mdarkdlg.ShowWindow(SW_HIDE);
		mFishing.ShowWindow(SW_HIDE);
		mfullmoon.ShowWindow(SW_HIDE);
		mmountain.ShowWindow(SW_HIDE);
		msunset.ShowWindow(SW_HIDE);
		mclouds.ShowWindow(SW_HIDE);
		mproj.ShowWindow(SW_HIDE);
		
	}
	else if (8 == templateType) //영사기 
	{
		mproj.ShowWindow(SW_SHOW);
		// hide others here
		mBalloon.ShowWindow(SW_HIDE);
		mFilm.ShowWindow(SW_HIDE);
		mSlate.ShowWindow(SW_HIDE);
		mWave.ShowWindow(SW_HIDE);
		mOcean.ShowWindow(SW_HIDE);
		mImagedlg.ShowWindow(SW_HIDE);
		mdarkdlg.ShowWindow(SW_HIDE);
		mFishing.ShowWindow(SW_HIDE);
		mfullmoon.ShowWindow(SW_HIDE);
		mmountain.ShowWindow(SW_HIDE);
		msunset.ShowWindow(SW_HIDE);
		mclouds.ShowWindow(SW_HIDE);
		mtropical.ShowWindow(SW_HIDE);
		
	}

	else if (9 == templateType) //필름 
	{
		mFilm.ShowWindow(SW_SHOW);
		// hide others here
		mBalloon.ShowWindow(SW_HIDE);
		mSlate.ShowWindow(SW_HIDE);
		mWave.ShowWindow(SW_HIDE);
		mOcean.ShowWindow(SW_HIDE);
		mImagedlg.ShowWindow(SW_HIDE);
		mdarkdlg.ShowWindow(SW_HIDE);
		mFishing.ShowWindow(SW_HIDE);
		mfullmoon.ShowWindow(SW_HIDE);
		mmountain.ShowWindow(SW_HIDE);
		msunset.ShowWindow(SW_HIDE);
		mclouds.ShowWindow(SW_HIDE);
		mtropical.ShowWindow(SW_HIDE);
		mproj.ShowWindow(SW_HIDE);
	
	}
	else if (10 == templateType) //슬레이트 
	{
		mSlate.ShowWindow(SW_SHOW);
		// hide others here
		
		mFilm.ShowWindow(SW_HIDE);
		mBalloon.ShowWindow(SW_HIDE);
		mWave.ShowWindow(SW_HIDE);
		mOcean.ShowWindow(SW_HIDE);
		mImagedlg.ShowWindow(SW_HIDE);
		mdarkdlg.ShowWindow(SW_HIDE);
		mFishing.ShowWindow(SW_HIDE);
		mfullmoon.ShowWindow(SW_HIDE);
		mmountain.ShowWindow(SW_HIDE);
		msunset.ShowWindow(SW_HIDE);
		mclouds.ShowWindow(SW_HIDE);
		mtropical.ShowWindow(SW_HIDE);
		mproj.ShowWindow(SW_HIDE);
	
	}
	else if (11 == templateType) //파도
	{
		mWave.ShowWindow(SW_SHOW);
		// hide others here
		
		mFilm.ShowWindow(SW_HIDE);
		mBalloon.ShowWindow(SW_HIDE);
		mOcean.ShowWindow(SW_HIDE);
		mImagedlg.ShowWindow(SW_HIDE);
		mdarkdlg.ShowWindow(SW_HIDE);
		mFishing.ShowWindow(SW_HIDE);
		mfullmoon.ShowWindow(SW_HIDE);
		mmountain.ShowWindow(SW_HIDE);
		msunset.ShowWindow(SW_HIDE);
		mclouds.ShowWindow(SW_HIDE);
		mtropical.ShowWindow(SW_HIDE);
		mproj.ShowWindow(SW_HIDE);
		mSlate.ShowWindow(SW_HIDE);

	
	}
	else if (12 == templateType) //바다속
	{
		mOcean.ShowWindow(SW_SHOW);
		// hide others here
		
		mFilm.ShowWindow(SW_HIDE);
		mBalloon.ShowWindow(SW_HIDE);
		mWave.ShowWindow(SW_HIDE);
		mImagedlg.ShowWindow(SW_HIDE);
		mdarkdlg.ShowWindow(SW_HIDE);
		mFishing.ShowWindow(SW_HIDE);
		mfullmoon.ShowWindow(SW_HIDE);
		mmountain.ShowWindow(SW_HIDE);
		msunset.ShowWindow(SW_HIDE);
		mclouds.ShowWindow(SW_HIDE);
		mtropical.ShowWindow(SW_HIDE);
		mproj.ShowWindow(SW_HIDE);
		mSlate.ShowWindow(SW_HIDE);
	
	}
	else if (13 == templateType) //낚시
	{
		mFishing.ShowWindow(SW_SHOW);
		// hide others here
		
		mFilm.ShowWindow(SW_HIDE);
		mBalloon.ShowWindow(SW_HIDE);
		mWave.ShowWindow(SW_HIDE);
		mOcean.ShowWindow(SW_HIDE);
		mImagedlg.ShowWindow(SW_HIDE);
		mdarkdlg.ShowWindow(SW_HIDE);
	
		mfullmoon.ShowWindow(SW_HIDE);
		mmountain.ShowWindow(SW_HIDE);
		msunset.ShowWindow(SW_HIDE);
		mclouds.ShowWindow(SW_HIDE);
		mtropical.ShowWindow(SW_HIDE);
		mproj.ShowWindow(SW_HIDE);
		mSlate.ShowWindow(SW_HIDE);
	
	}
	else if (100 == templateType)
	{
		mImagedlg.ShowWindow(SW_SHOW);

		// hide others here
		mBalloon.ShowWindow(SW_HIDE);

		mFilm.ShowWindow(SW_HIDE);
		mSlate.ShowWindow(SW_HIDE);
		mWave.ShowWindow(SW_HIDE);
		mOcean.ShowWindow(SW_HIDE);
		mFishing.ShowWindow(SW_HIDE);
		mdarkdlg.ShowWindow(SW_HIDE);
		mfullmoon.ShowWindow(SW_HIDE);
		mmountain.ShowWindow(SW_HIDE);
		msunset.ShowWindow(SW_HIDE);
		mtropical.ShowWindow(SW_HIDE);
		mclouds.ShowWindow(SW_HIDE);
		mproj.ShowWindow(SW_HIDE);
	
	}

}

void CEdittapCtrl::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CEdittapCtrl, CDialogEx)
	ON_EN_CHANGE(IDC_EDIT1, &CEdittapCtrl::OnEnChangeEdit1)
END_MESSAGE_MAP()


// CEdittapCtrl 메시지 처리기입니다.


void CEdittapCtrl::OnEnChangeEdit1()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CDialogEx::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
}

BOOL CEdittapCtrl::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	mBalloon.Create(CBalloonDlg::IDD, this);
	mFilm.Create(CFilmDlg::IDD, this);
	mOcean.Create(COceanDlg::IDD, this);
	mSlate.Create(CSlateDlg::IDD, this);
	mWave.Create(CWaveDlg::IDD, this);
	mFishing.Create(CFishingDlg::IDD, this);
	mImagedlg.Create(CImageEditDlg::IDD, this);
	mdarkdlg.Create(CDarkStormyDlg::IDD, this);
	mfullmoon.Create(CFullmoonDlg::IDD, this);
	msunset.Create(CSunsetDlg::IDD, this);
	mtropical.Create(CTropicalDlg::IDD, this);
	mclouds.Create(CCloudsDlg::IDD, this);
	mmountain.Create(CMountainDlg::IDD, this);
	mproj.Create(CProjectorDlg::IDD, this);

	CRect rect;
	GetClientRect(&rect);
	mBalloon.MoveWindow(&rect);
	mFilm.MoveWindow(&rect);
	mOcean.MoveWindow(&rect);
	mSlate.MoveWindow(&rect);
	mWave.MoveWindow(&rect);
	mFishing.MoveWindow(&rect);
	mImagedlg.MoveWindow(&rect);
	mdarkdlg.MoveWindow(&rect);
	mfullmoon.MoveWindow(&rect);
	msunset.MoveWindow(&rect);
	mtropical.MoveWindow(&rect);
	mclouds.MoveWindow(&rect);
	mmountain.MoveWindow(&rect);
	mproj.MoveWindow(&rect);


	//mBalloon.ShowWindow(SW_SHOW);
	mFilm.ShowWindow(SW_HIDE); //왜 이걸 해줘야 처음에 안보일까요.....풍선은 안해도 안보이는데
	mOcean.ShowWindow(SW_HIDE);
	mSlate.ShowWindow(SW_HIDE);
	mWave.ShowWindow(SW_HIDE);
	mFishing.ShowWindow(SW_HIDE);
	mImagedlg.ShowWindow(SW_HIDE);
	mdarkdlg.ShowWindow(SW_HIDE);
	mfullmoon.ShowWindow(SW_HIDE);
	msunset.ShowWindow(SW_HIDE);
	mtropical.ShowWindow(SW_HIDE);
	mclouds.ShowWindow(SW_HIDE);
	mmountain.ShowWindow(SW_HIDE);
	mproj.ShowWindow(SW_HIDE);

	return TRUE;
}

void CEdittapCtrl::ChangeImgTo(int imgType){

	mImagedlg.ChangeImgTo(imgType);

}