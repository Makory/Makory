// EdittapCtrl.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "Makory.h"
#include "EdittapCtrl.h"
#include "afxdialogex.h"


// CEdittapCtrl ��ȭ �����Դϴ�.

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
	else if (8 == templateType) //����� 
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

	else if (9 == templateType) //�ʸ� 
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
	else if (10 == templateType) //������Ʈ 
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
	else if (11 == templateType) //�ĵ�
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
	else if (12 == templateType) //�ٴټ�
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
	else if (13 == templateType) //����
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


// CEdittapCtrl �޽��� ó�����Դϴ�.


void CEdittapCtrl::OnEnChangeEdit1()
{
	// TODO:  RICHEDIT ��Ʈ���� ���, �� ��Ʈ����
	// CDialogEx::OnInitDialog() �Լ��� ������ 
	//�ϰ� ����ũ�� OR �����Ͽ� ������ ENM_CHANGE �÷��׸� �����Ͽ� CRichEditCtrl().SetEventMask()�� ȣ������ ������
	// �� �˸� �޽����� ������ �ʽ��ϴ�.

	// TODO:  ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
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
	mFilm.ShowWindow(SW_HIDE); //�� �̰� ����� ó���� �Ⱥ��ϱ��.....ǳ���� ���ص� �Ⱥ��̴µ�
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