// EdittapCtrl.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "Makory.h"
#include "ImageEditDlg.h"
#include "afxdialogex.h"
#include "HotAirBalloon.h"
#include "MainFrm.h"
#include "MakoryDoc.h"
#include "MakoryView.h"
#include "ImageTimelineCtrl.h"
// CImageEditDlg 대화 상자입니다.

IMPLEMENT_DYNAMIC(CImageEditDlg, CDialogEx)

	CImageEditDlg::CImageEditDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CImageEditDlg::IDD, pParent)
{

}

CImageEditDlg::~CImageEditDlg()
{
}

void CImageEditDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_CLOUDY_IMAGE_SCALE_SLIDER, mcloudyImageScaleSlider);
	DDX_Control(pDX, IDC_DARK_IMAGE_SCALE_SLIDER, mdarkImageScaleSlider);
	DDX_Control(pDX, IDC_FULL_IMAGE_SCALE_SLIDER, mfullImageScaleSlider);
	DDX_Control(pDX, IDC_MOUNTAIN_IMAGE_SCALE_SLIDER, mmountainImageScaleSlider);
	DDX_Control(pDX, IDC_SUNSET_IMAGE_SCALE_SLIDER, msunsetImageScaleSlider);
	DDX_Control(pDX, IDC_WATER_IMAGE_SCALE_SLIDER, mwaterImageScaleSlider);
	DDX_Control(pDX, IDC_TROPICAL_IMAGE_SCALE_SLIDER, mtropicalImageScaleSlider);

	DDX_Control(pDX, IDC_FILM_IMAGE_SCALE_SLIDER, mfilmImageScaleSlider);
	DDX_Control(pDX, IDC_SLATE_IMAGE_SCALE_SLIDER, mslateImageScaleSlider);
	DDX_Control(pDX, IDC_PROJECTOR_IMAGE_SCALE_SLIDER, mprojImageScaleSlider);
	DDX_Control(pDX, IDC_OCEAN_IMAGE_SCALE_SLIDER, moceanImageScaleSlider);
	DDX_Control(pDX, IDC_FISHING_IMAGE_SCALE_SLIDER, mfishingImageScaleSlider);
	DDX_Control(pDX, IDC_BOAT_IMAGE_SCALE_SLIDER, mwaveImageScaleSlider);

	DDX_Control(pDX, IDC_CLOUDY_IMAGE_SCALE_VALUE, mcloudyImageScaleValue);
	DDX_Control(pDX, IDC_DARK_IMAGE_SCALE_VALUE, mdarkImageScaleValue);
	DDX_Control(pDX, IDC_FULL_IMAGE_SCALE_VALUE, mfullImageScaleValue);
	DDX_Control(pDX, IDC_MOUNTAIN_IMAGE_SCALE_VALUE, mmountainImageScaleValue);
	DDX_Control(pDX, IDC_SUNSET_IMAGE_SCALE_VALUE, msunsetImageScaleValue);
	DDX_Control(pDX, IDC_WATER_IMAGE_SCALE_VALUE, mwaterImageScaleValue);
	DDX_Control(pDX, IDC_TROPICAL_IMAGE_SCALE_VALUE, mtropicalImageScaleValue);

	DDX_Control(pDX, IDC_FILM_IMAGE_SCALE_VALUE, mfilmImageScaleValue);
	DDX_Control(pDX, IDC_SLATE_IMAGE_SCALE_VALUE, mslateImageScaleValue);
	DDX_Control(pDX, IDC_PROJECTOR_IMAGE_SCALE_VALUE, mprojImageScaleValue);
	DDX_Control(pDX, IDC_OCEAN_IMAGE_SCALE_VALUE, moceanImageScaleValue);
	DDX_Control(pDX, IDC_FISHING_IMAGE_SCALE_VALUE, mfishingImageScaleValue);
	DDX_Control(pDX, IDC_BOAT_IMAGE_SCALE_VALUE,mwaveImageScaleValue);

}


BEGIN_MESSAGE_MAP(CImageEditDlg, CDialogEx)
	ON_WM_HSCROLL()
	ON_EN_UPDATE(IDC_CLOUDY_IMAGE_SCALE_VALUE, &CImageEditDlg::OnEnUpdatecloudyImageScaleValue)
	ON_EN_UPDATE(IDC_DARK_IMAGE_SCALE_VALUE, &CImageEditDlg::OnEnUpdatedarkImageScaleValue)
	ON_EN_UPDATE(IDC_FULL_IMAGE_SCALE_VALUE, &CImageEditDlg::OnEnUpdatefullImageScaleValue)
	ON_EN_UPDATE(IDC_MOUNTAIN_IMAGE_SCALE_VALUE, &CImageEditDlg::OnEnUpdatemountainImageScaleValue)
	ON_EN_UPDATE(IDC_SUNSET_IMAGE_SCALE_VALUE, &CImageEditDlg::OnEnUpdatesunsetImageScaleValue)
	ON_EN_UPDATE(IDC_WATER_IMAGE_SCALE_VALUE, &CImageEditDlg::OnEnUpdatewaterImageScaleValue)
	ON_EN_UPDATE(IDC_TROPICAL_IMAGE_SCALE_VALUE, &CImageEditDlg::OnEnUpdatetropicalImageScaleValue)
	ON_EN_UPDATE(IDC_FILM_IMAGE_SCALE_VALUE, &CImageEditDlg::OnEnUpdatefilmImageScaleValue)
	ON_EN_UPDATE(IDC_SLATE_IMAGE_SCALE_VALUE, &CImageEditDlg::OnEnUpdateslateImageScaleValue)
	ON_EN_UPDATE(IDC_PROJECTOR_IMAGE_SCALE_VALUE, &CImageEditDlg::OnEnUpdateprojImageScaleValue)

	ON_EN_UPDATE(IDC_BOAT_IMAGE_SCALE_VALUE, &CImageEditDlg::OnEnUpdatewaveImageScaleValue)
	ON_EN_UPDATE(IDC_FISHING_IMAGE_SCALE_VALUE, &CImageEditDlg::OnEnUpdatefishingImageScaleValue)
	ON_EN_UPDATE(IDC_OCEAN_IMAGE_SCALE_VALUE, &CImageEditDlg::OnEnUpdateoceanImageScaleValue)
END_MESSAGE_MAP()


// CImageEditDlg 메시지 처리기입니다.

BOOL CImageEditDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.

	mfilmImageScaleSlider.SetPos(50);//슬라이더 처음 위치
	mfilmImageScaleSlider.SetRange(0, 100); //슬라이더 범위 0 ~ 100으로 함.
	mfilmImageScaleSlider.SetPageSize(1);  //슬라이더를 클릭했을 때 움직이는 범위
	mfilmImageScaleValue.SetWindowTextA("0");//h edit박스 초기값

	mslateImageScaleSlider.SetPos(50);
	mslateImageScaleSlider.SetRange(0, 100);
	mslateImageScaleSlider.SetPageSize(1);  //슬라이더를 클릭했을 때 움직이는 범위
	mslateImageScaleValue.SetWindowTextA("0");//h edit박스 초기값

	mwaveImageScaleSlider.SetPos(50);
	mwaveImageScaleSlider.SetRange(0, 100); //슬라이더 범위 0 ~ 100으로 함.
	mwaveImageScaleSlider.SetPageSize(1);  //슬라이더를 클릭했을 때 움직이는 범위
	mwaveImageScaleValue.SetWindowTextA("0");//h edit박스 초기값


		mprojImageScaleSlider.SetPos(50);
	mprojImageScaleSlider.SetRange(0, 100); //슬라이더 범위 0 ~ 100으로 함.
	mprojImageScaleSlider.SetPageSize(1);  //슬라이더를 클릭했을 때 움직이는 범위
	mprojImageScaleValue.SetWindowTextA("0");//h edit박스 초기값

	mfishingImageScaleSlider.SetPos(50);
	mfishingImageScaleSlider.SetRange(0, 100); //슬라이더 범위 0 ~ 100으로 함.
	mfishingImageScaleSlider.SetPageSize(1);  //슬라이더를 클릭했을 때 움직이는 범위
	mfishingImageScaleValue.SetWindowTextA("0");//h edit박스 초기값

	moceanImageScaleSlider.SetPos(50);
	moceanImageScaleSlider.SetRange(0, 100); //슬라이더 범위 0 ~ 100으로 함.
	moceanImageScaleSlider.SetPageSize(1);  //슬라이더를 클릭했을 때 움직이는 범위
	moceanImageScaleValue.SetWindowTextA("0");//h edit박스 초기값

	mcloudyImageScaleValue.SetWindowTextA("0");
	mdarkImageScaleValue.SetWindowTextA("0");
	mfullImageScaleValue.SetWindowTextA("0");
	mmountainImageScaleValue.SetWindowTextA("0");
	msunsetImageScaleValue.SetWindowTextA("0");
	mwaterImageScaleValue.SetWindowTextA("0");
	mtropicalImageScaleValue.SetWindowTextA("0");

	mprojImageScaleValue.SetWindowTextA("0");
	moceanImageScaleValue.SetWindowTextA("0");
	mfishingImageScaleValue.SetWindowTextA("0");
	mwaveImageScaleValue.SetWindowTextA("0");

	return TRUE;  // return TRUE unless you set the focus to a control
	// 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}



void CImageEditDlg::ChangeImgTo(int imgType)
{	
	if( 1==imgType){

		mcloudyImageScaleSlider.ShowWindow(SW_SHOW);
		mcloudyImageScaleValue.ShowWindow(SW_SHOW);

		mdarkImageScaleSlider.ShowWindow(SW_HIDE);
		mdarkImageScaleValue.ShowWindow(SW_HIDE);

		mfullImageScaleSlider.ShowWindow(SW_HIDE);
		mfullImageScaleValue.ShowWindow(SW_HIDE);

		mmountainImageScaleSlider.ShowWindow(SW_HIDE);
		mmountainImageScaleValue.ShowWindow(SW_HIDE);

		msunsetImageScaleSlider.ShowWindow(SW_HIDE);
		msunsetImageScaleValue.ShowWindow(SW_HIDE);

		mwaterImageScaleSlider.ShowWindow(SW_HIDE);
		mwaterImageScaleValue.ShowWindow(SW_HIDE);

		mtropicalImageScaleSlider.ShowWindow(SW_HIDE);
		mtropicalImageScaleValue.ShowWindow(SW_HIDE);

		mfilmImageScaleSlider.ShowWindow(SW_HIDE);
		mfilmImageScaleValue.ShowWindow(SW_HIDE);

		mslateImageScaleSlider.ShowWindow(SW_HIDE);
		mslateImageScaleValue.ShowWindow(SW_HIDE);

		mprojImageScaleSlider.ShowWindow(SW_HIDE);
		mprojImageScaleValue.ShowWindow(SW_HIDE);

		moceanImageScaleSlider.ShowWindow(SW_HIDE);
		moceanImageScaleValue.ShowWindow(SW_HIDE);

		mfishingImageScaleSlider.ShowWindow(SW_HIDE);
		mfishingImageScaleValue.ShowWindow(SW_HIDE);

		mwaveImageScaleSlider.ShowWindow(SW_HIDE);
		mwaveImageScaleValue.ShowWindow(SW_HIDE);

	}

	else if(2==imgType){
		mcloudyImageScaleSlider.ShowWindow(SW_HIDE);
		mcloudyImageScaleValue.ShowWindow(SW_HIDE);

		mdarkImageScaleSlider.ShowWindow(SW_SHOW);
		mdarkImageScaleValue.ShowWindow(SW_SHOW);

		mfullImageScaleSlider.ShowWindow(SW_HIDE);
		mfullImageScaleValue.ShowWindow(SW_HIDE);

		mmountainImageScaleSlider.ShowWindow(SW_HIDE);
		mmountainImageScaleValue.ShowWindow(SW_HIDE);

		msunsetImageScaleSlider.ShowWindow(SW_HIDE);
		msunsetImageScaleValue.ShowWindow(SW_HIDE);

		mwaterImageScaleSlider.ShowWindow(SW_HIDE);
		mwaterImageScaleValue.ShowWindow(SW_HIDE);

		mtropicalImageScaleSlider.ShowWindow(SW_HIDE);
		mtropicalImageScaleValue.ShowWindow(SW_HIDE);

		mfilmImageScaleSlider.ShowWindow(SW_HIDE);
		mfilmImageScaleValue.ShowWindow(SW_HIDE);

		mslateImageScaleSlider.ShowWindow(SW_HIDE);
		mslateImageScaleValue.ShowWindow(SW_HIDE);

		mprojImageScaleSlider.ShowWindow(SW_HIDE);
		mprojImageScaleValue.ShowWindow(SW_HIDE);

		moceanImageScaleSlider.ShowWindow(SW_HIDE);
		moceanImageScaleValue.ShowWindow(SW_HIDE);

		mfishingImageScaleSlider.ShowWindow(SW_HIDE);
		mfishingImageScaleValue.ShowWindow(SW_HIDE);

		mwaveImageScaleSlider.ShowWindow(SW_HIDE);
		mwaveImageScaleValue.ShowWindow(SW_HIDE);
	}

	else if(3==imgType){
		mcloudyImageScaleSlider.ShowWindow(SW_HIDE);
		mcloudyImageScaleValue.ShowWindow(SW_HIDE);

		mdarkImageScaleSlider.ShowWindow(SW_HIDE);
		mdarkImageScaleValue.ShowWindow(SW_HIDE);

		mfullImageScaleSlider.ShowWindow(SW_SHOW);
		mfullImageScaleValue.ShowWindow(SW_SHOW);

		mmountainImageScaleSlider.ShowWindow(SW_HIDE);
		mmountainImageScaleValue.ShowWindow(SW_HIDE);

		msunsetImageScaleSlider.ShowWindow(SW_HIDE);
		msunsetImageScaleValue.ShowWindow(SW_HIDE);

		mwaterImageScaleSlider.ShowWindow(SW_HIDE);
		mwaterImageScaleValue.ShowWindow(SW_HIDE);

		mtropicalImageScaleSlider.ShowWindow(SW_HIDE);
		mtropicalImageScaleValue.ShowWindow(SW_HIDE);

		mfilmImageScaleSlider.ShowWindow(SW_HIDE);
		mfilmImageScaleValue.ShowWindow(SW_HIDE);

		mslateImageScaleSlider.ShowWindow(SW_HIDE);
		mslateImageScaleValue.ShowWindow(SW_HIDE);

		mprojImageScaleSlider.ShowWindow(SW_HIDE);
		mprojImageScaleValue.ShowWindow(SW_HIDE);

		moceanImageScaleSlider.ShowWindow(SW_HIDE);
		moceanImageScaleValue.ShowWindow(SW_HIDE);

		mfishingImageScaleSlider.ShowWindow(SW_HIDE);
		mfishingImageScaleValue.ShowWindow(SW_HIDE);

		mwaveImageScaleSlider.ShowWindow(SW_HIDE);
		mwaveImageScaleValue.ShowWindow(SW_HIDE);
	}
	else if(4==imgType){
	mcloudyImageScaleSlider.ShowWindow(SW_HIDE);
		mcloudyImageScaleValue.ShowWindow(SW_HIDE);

		mdarkImageScaleSlider.ShowWindow(SW_HIDE);
		mdarkImageScaleValue.ShowWindow(SW_HIDE);

		mfullImageScaleSlider.ShowWindow(SW_HIDE);
		mfullImageScaleValue.ShowWindow(SW_HIDE);

		mmountainImageScaleSlider.ShowWindow(SW_SHOW);
		mmountainImageScaleValue.ShowWindow(SW_SHOW);

		msunsetImageScaleSlider.ShowWindow(SW_HIDE);
		msunsetImageScaleValue.ShowWindow(SW_HIDE);

		mwaterImageScaleSlider.ShowWindow(SW_HIDE);
		mwaterImageScaleValue.ShowWindow(SW_HIDE);

		mtropicalImageScaleSlider.ShowWindow(SW_HIDE);
		mtropicalImageScaleValue.ShowWindow(SW_HIDE);

		mfilmImageScaleSlider.ShowWindow(SW_HIDE);
		mfilmImageScaleValue.ShowWindow(SW_HIDE);

		mslateImageScaleSlider.ShowWindow(SW_HIDE);
		mslateImageScaleValue.ShowWindow(SW_HIDE);

		mprojImageScaleSlider.ShowWindow(SW_HIDE);
		mprojImageScaleValue.ShowWindow(SW_HIDE);

		moceanImageScaleSlider.ShowWindow(SW_HIDE);
		moceanImageScaleValue.ShowWindow(SW_HIDE);

		mfishingImageScaleSlider.ShowWindow(SW_HIDE);
		mfishingImageScaleValue.ShowWindow(SW_HIDE);

		mwaveImageScaleSlider.ShowWindow(SW_HIDE);
		mwaveImageScaleValue.ShowWindow(SW_HIDE);
	}
	else if(5==imgType){
			mcloudyImageScaleSlider.ShowWindow(SW_HIDE);
		mcloudyImageScaleValue.ShowWindow(SW_HIDE);

		mdarkImageScaleSlider.ShowWindow(SW_HIDE);
		mdarkImageScaleValue.ShowWindow(SW_HIDE);

		mfullImageScaleSlider.ShowWindow(SW_HIDE);
		mfullImageScaleValue.ShowWindow(SW_HIDE);

		mmountainImageScaleSlider.ShowWindow(SW_HIDE);
		mmountainImageScaleValue.ShowWindow(SW_HIDE);

		msunsetImageScaleSlider.ShowWindow(SW_SHOW);
		msunsetImageScaleValue.ShowWindow(SW_SHOW);

		mwaterImageScaleSlider.ShowWindow(SW_HIDE);
		mwaterImageScaleValue.ShowWindow(SW_HIDE);

		mtropicalImageScaleSlider.ShowWindow(SW_HIDE);
		mtropicalImageScaleValue.ShowWindow(SW_HIDE);

		mfilmImageScaleSlider.ShowWindow(SW_HIDE);
		mfilmImageScaleValue.ShowWindow(SW_HIDE);

		mslateImageScaleSlider.ShowWindow(SW_HIDE);
		mslateImageScaleValue.ShowWindow(SW_HIDE);

		mprojImageScaleSlider.ShowWindow(SW_HIDE);
		mprojImageScaleValue.ShowWindow(SW_HIDE);

		moceanImageScaleSlider.ShowWindow(SW_HIDE);
		moceanImageScaleValue.ShowWindow(SW_HIDE);

		mfishingImageScaleSlider.ShowWindow(SW_HIDE);
		mfishingImageScaleValue.ShowWindow(SW_HIDE);

		mwaveImageScaleSlider.ShowWindow(SW_HIDE);
		mwaveImageScaleValue.ShowWindow(SW_HIDE);
	}
	else if(6==imgType){
					mcloudyImageScaleSlider.ShowWindow(SW_HIDE);
		mcloudyImageScaleValue.ShowWindow(SW_HIDE);

		mdarkImageScaleSlider.ShowWindow(SW_HIDE);
		mdarkImageScaleValue.ShowWindow(SW_HIDE);

		mfullImageScaleSlider.ShowWindow(SW_HIDE);
		mfullImageScaleValue.ShowWindow(SW_HIDE);

		mmountainImageScaleSlider.ShowWindow(SW_HIDE);
		mmountainImageScaleValue.ShowWindow(SW_HIDE);

		msunsetImageScaleSlider.ShowWindow(SW_HIDE);
		msunsetImageScaleValue.ShowWindow(SW_HIDE);

		mwaterImageScaleSlider.ShowWindow(SW_SHOW);
		mwaterImageScaleValue.ShowWindow(SW_SHOW);

		mtropicalImageScaleSlider.ShowWindow(SW_HIDE);
		mtropicalImageScaleValue.ShowWindow(SW_HIDE);

		mfilmImageScaleSlider.ShowWindow(SW_HIDE);
		mfilmImageScaleValue.ShowWindow(SW_HIDE);

		mslateImageScaleSlider.ShowWindow(SW_HIDE);
		mslateImageScaleValue.ShowWindow(SW_HIDE);

		mprojImageScaleSlider.ShowWindow(SW_HIDE);
		mprojImageScaleValue.ShowWindow(SW_HIDE);

		moceanImageScaleSlider.ShowWindow(SW_HIDE);
		moceanImageScaleValue.ShowWindow(SW_HIDE);

		mfishingImageScaleSlider.ShowWindow(SW_HIDE);
		mfishingImageScaleValue.ShowWindow(SW_HIDE);

		mwaveImageScaleSlider.ShowWindow(SW_HIDE);
		mwaveImageScaleValue.ShowWindow(SW_HIDE);
	}
	else if(7==imgType){
		mcloudyImageScaleSlider.ShowWindow(SW_HIDE);
		mcloudyImageScaleValue.ShowWindow(SW_HIDE);

		mdarkImageScaleSlider.ShowWindow(SW_HIDE);
		mdarkImageScaleValue.ShowWindow(SW_HIDE);

		mfullImageScaleSlider.ShowWindow(SW_HIDE);
		mfullImageScaleValue.ShowWindow(SW_HIDE);

		mmountainImageScaleSlider.ShowWindow(SW_HIDE);
		mmountainImageScaleValue.ShowWindow(SW_HIDE);

		msunsetImageScaleSlider.ShowWindow(SW_HIDE);
		msunsetImageScaleValue.ShowWindow(SW_HIDE);

		mwaterImageScaleSlider.ShowWindow(SW_HIDE);
		mwaterImageScaleValue.ShowWindow(SW_HIDE);

		mtropicalImageScaleSlider.ShowWindow(SW_SHOW);
		mtropicalImageScaleValue.ShowWindow(SW_SHOW);

		mfilmImageScaleSlider.ShowWindow(SW_HIDE);
		mfilmImageScaleValue.ShowWindow(SW_HIDE);

		mslateImageScaleSlider.ShowWindow(SW_HIDE);
		mslateImageScaleValue.ShowWindow(SW_HIDE);

		mprojImageScaleSlider.ShowWindow(SW_HIDE);
		mprojImageScaleValue.ShowWindow(SW_HIDE);

		moceanImageScaleSlider.ShowWindow(SW_HIDE);
		moceanImageScaleValue.ShowWindow(SW_HIDE);

		mfishingImageScaleSlider.ShowWindow(SW_HIDE);
		mfishingImageScaleValue.ShowWindow(SW_HIDE);

		mwaveImageScaleSlider.ShowWindow(SW_HIDE);
		mwaveImageScaleValue.ShowWindow(SW_HIDE);
	}
	else if(8==imgType){
		mcloudyImageScaleSlider.ShowWindow(SW_HIDE);
		mcloudyImageScaleValue.ShowWindow(SW_HIDE);

		mdarkImageScaleSlider.ShowWindow(SW_HIDE);
		mdarkImageScaleValue.ShowWindow(SW_HIDE);

		mfullImageScaleSlider.ShowWindow(SW_HIDE);
		mfullImageScaleValue.ShowWindow(SW_HIDE);

		mmountainImageScaleSlider.ShowWindow(SW_HIDE);
		mmountainImageScaleValue.ShowWindow(SW_HIDE);

		msunsetImageScaleSlider.ShowWindow(SW_HIDE);
		msunsetImageScaleValue.ShowWindow(SW_HIDE);

		mwaterImageScaleSlider.ShowWindow(SW_HIDE);
		mwaterImageScaleValue.ShowWindow(SW_HIDE);

		mtropicalImageScaleSlider.ShowWindow(SW_HIDE);
		mtropicalImageScaleValue.ShowWindow(SW_HIDE);

		mfilmImageScaleSlider.ShowWindow(SW_HIDE);
		mfilmImageScaleValue.ShowWindow(SW_HIDE);

		mslateImageScaleSlider.ShowWindow(SW_HIDE);
		mslateImageScaleValue.ShowWindow(SW_HIDE);

		mprojImageScaleSlider.ShowWindow(SW_SHOW);
		mprojImageScaleValue.ShowWindow(SW_SHOW);

		moceanImageScaleSlider.ShowWindow(SW_HIDE);
		moceanImageScaleValue.ShowWindow(SW_HIDE);

		mfishingImageScaleSlider.ShowWindow(SW_HIDE);
		mfishingImageScaleValue.ShowWindow(SW_HIDE);

		mwaveImageScaleSlider.ShowWindow(SW_HIDE);
		mwaveImageScaleValue.ShowWindow(SW_HIDE);

	}
	else if(9==imgType){
			mcloudyImageScaleSlider.ShowWindow(SW_HIDE);
		mcloudyImageScaleValue.ShowWindow(SW_HIDE);

		mdarkImageScaleSlider.ShowWindow(SW_HIDE);
		mdarkImageScaleValue.ShowWindow(SW_HIDE);

		mfullImageScaleSlider.ShowWindow(SW_HIDE);
		mfullImageScaleValue.ShowWindow(SW_HIDE);

		mmountainImageScaleSlider.ShowWindow(SW_HIDE);
		mmountainImageScaleValue.ShowWindow(SW_HIDE);

		msunsetImageScaleSlider.ShowWindow(SW_HIDE);
		msunsetImageScaleValue.ShowWindow(SW_HIDE);

		mwaterImageScaleSlider.ShowWindow(SW_HIDE);
		mwaterImageScaleValue.ShowWindow(SW_HIDE);

		mtropicalImageScaleSlider.ShowWindow(SW_HIDE);
		mtropicalImageScaleValue.ShowWindow(SW_HIDE);

		mfilmImageScaleSlider.ShowWindow(SW_SHOW);
		mfilmImageScaleValue.ShowWindow(SW_SHOW);

		mslateImageScaleSlider.ShowWindow(SW_HIDE);
		mslateImageScaleValue.ShowWindow(SW_HIDE);

		mprojImageScaleSlider.ShowWindow(SW_HIDE);
		mprojImageScaleValue.ShowWindow(SW_HIDE);

		moceanImageScaleSlider.ShowWindow(SW_HIDE);
		moceanImageScaleValue.ShowWindow(SW_HIDE);

		mfishingImageScaleSlider.ShowWindow(SW_HIDE);
		mfishingImageScaleValue.ShowWindow(SW_HIDE);

		mwaveImageScaleSlider.ShowWindow(SW_HIDE);
		mwaveImageScaleValue.ShowWindow(SW_HIDE);
	}
	else if(10==imgType){
					mcloudyImageScaleSlider.ShowWindow(SW_HIDE);
		mcloudyImageScaleValue.ShowWindow(SW_HIDE);

		mdarkImageScaleSlider.ShowWindow(SW_HIDE);
		mdarkImageScaleValue.ShowWindow(SW_HIDE);

		mfullImageScaleSlider.ShowWindow(SW_HIDE);
		mfullImageScaleValue.ShowWindow(SW_HIDE);

		mmountainImageScaleSlider.ShowWindow(SW_HIDE);
		mmountainImageScaleValue.ShowWindow(SW_HIDE);

		msunsetImageScaleSlider.ShowWindow(SW_HIDE);
		msunsetImageScaleValue.ShowWindow(SW_HIDE);

		mwaterImageScaleSlider.ShowWindow(SW_HIDE);
		mwaterImageScaleValue.ShowWindow(SW_HIDE);

		mtropicalImageScaleSlider.ShowWindow(SW_HIDE);
		mtropicalImageScaleValue.ShowWindow(SW_HIDE);

		mfilmImageScaleSlider.ShowWindow(SW_HIDE);
		mfilmImageScaleValue.ShowWindow(SW_HIDE);

		mslateImageScaleSlider.ShowWindow(SW_SHOW);
		mslateImageScaleValue.ShowWindow(SW_SHOW);

		mprojImageScaleSlider.ShowWindow(SW_HIDE);
		mprojImageScaleValue.ShowWindow(SW_HIDE);

		moceanImageScaleSlider.ShowWindow(SW_HIDE);
		moceanImageScaleValue.ShowWindow(SW_HIDE);

		mfishingImageScaleSlider.ShowWindow(SW_HIDE);
		mfishingImageScaleValue.ShowWindow(SW_HIDE);

		mwaveImageScaleSlider.ShowWindow(SW_HIDE);
		mwaveImageScaleValue.ShowWindow(SW_HIDE);
	}
	else if(11==imgType){
					mcloudyImageScaleSlider.ShowWindow(SW_HIDE);
		mcloudyImageScaleValue.ShowWindow(SW_HIDE);

		mdarkImageScaleSlider.ShowWindow(SW_HIDE);
		mdarkImageScaleValue.ShowWindow(SW_HIDE);

		mfullImageScaleSlider.ShowWindow(SW_HIDE);
		mfullImageScaleValue.ShowWindow(SW_HIDE);

		mmountainImageScaleSlider.ShowWindow(SW_HIDE);
		mmountainImageScaleValue.ShowWindow(SW_HIDE);

		msunsetImageScaleSlider.ShowWindow(SW_HIDE);
		msunsetImageScaleValue.ShowWindow(SW_HIDE);

		mwaterImageScaleSlider.ShowWindow(SW_HIDE);
		mwaterImageScaleValue.ShowWindow(SW_HIDE);

		mtropicalImageScaleSlider.ShowWindow(SW_HIDE);
		mtropicalImageScaleValue.ShowWindow(SW_HIDE);

		mfilmImageScaleSlider.ShowWindow(SW_HIDE);
		mfilmImageScaleValue.ShowWindow(SW_HIDE);

		mslateImageScaleSlider.ShowWindow(SW_HIDE);
		mslateImageScaleValue.ShowWindow(SW_HIDE);

		mprojImageScaleSlider.ShowWindow(SW_HIDE);
		mprojImageScaleValue.ShowWindow(SW_HIDE);

		moceanImageScaleSlider.ShowWindow(SW_HIDE);
		moceanImageScaleValue.ShowWindow(SW_HIDE);

		mfishingImageScaleSlider.ShowWindow(SW_HIDE);
		mfishingImageScaleValue.ShowWindow(SW_HIDE);

		mwaveImageScaleSlider.ShowWindow(SW_SHOW);
		mwaveImageScaleValue.ShowWindow(SW_SHOW);
	}
	else if(12==imgType){
							mcloudyImageScaleSlider.ShowWindow(SW_HIDE);
		mcloudyImageScaleValue.ShowWindow(SW_HIDE);

		mdarkImageScaleSlider.ShowWindow(SW_HIDE);
		mdarkImageScaleValue.ShowWindow(SW_HIDE);

		mfullImageScaleSlider.ShowWindow(SW_HIDE);
		mfullImageScaleValue.ShowWindow(SW_HIDE);

		mmountainImageScaleSlider.ShowWindow(SW_HIDE);
		mmountainImageScaleValue.ShowWindow(SW_HIDE);

		msunsetImageScaleSlider.ShowWindow(SW_HIDE);
		msunsetImageScaleValue.ShowWindow(SW_HIDE);

		mwaterImageScaleSlider.ShowWindow(SW_HIDE);
		mwaterImageScaleValue.ShowWindow(SW_HIDE);

		mtropicalImageScaleSlider.ShowWindow(SW_HIDE);
		mtropicalImageScaleValue.ShowWindow(SW_HIDE);

		mfilmImageScaleSlider.ShowWindow(SW_HIDE);
		mfilmImageScaleValue.ShowWindow(SW_HIDE);

		mslateImageScaleSlider.ShowWindow(SW_HIDE);
		mslateImageScaleValue.ShowWindow(SW_HIDE);

		mprojImageScaleSlider.ShowWindow(SW_HIDE);
		mprojImageScaleValue.ShowWindow(SW_HIDE);

		moceanImageScaleSlider.ShowWindow(SW_SHOW);
		moceanImageScaleValue.ShowWindow(SW_SHOW);

		mfishingImageScaleSlider.ShowWindow(SW_HIDE);
		mfishingImageScaleValue.ShowWindow(SW_HIDE);

		mwaveImageScaleSlider.ShowWindow(SW_HIDE);
		mwaveImageScaleValue.ShowWindow(SW_HIDE);
	}
	else if(13==imgType){
									mcloudyImageScaleSlider.ShowWindow(SW_HIDE);
		mcloudyImageScaleValue.ShowWindow(SW_HIDE);

		mdarkImageScaleSlider.ShowWindow(SW_HIDE);
		mdarkImageScaleValue.ShowWindow(SW_HIDE);

		mfullImageScaleSlider.ShowWindow(SW_HIDE);
		mfullImageScaleValue.ShowWindow(SW_HIDE);

		mmountainImageScaleSlider.ShowWindow(SW_HIDE);
		mmountainImageScaleValue.ShowWindow(SW_HIDE);

		msunsetImageScaleSlider.ShowWindow(SW_HIDE);
		msunsetImageScaleValue.ShowWindow(SW_HIDE);

		mwaterImageScaleSlider.ShowWindow(SW_HIDE);
		mwaterImageScaleValue.ShowWindow(SW_HIDE);

		mtropicalImageScaleSlider.ShowWindow(SW_HIDE);
		mtropicalImageScaleValue.ShowWindow(SW_HIDE);

		mfilmImageScaleSlider.ShowWindow(SW_HIDE);
		mfilmImageScaleValue.ShowWindow(SW_HIDE);

		mslateImageScaleSlider.ShowWindow(SW_HIDE);
		mslateImageScaleValue.ShowWindow(SW_HIDE);

		mprojImageScaleSlider.ShowWindow(SW_HIDE);
		mprojImageScaleValue.ShowWindow(SW_HIDE);

		moceanImageScaleSlider.ShowWindow(SW_HIDE);
		moceanImageScaleValue.ShowWindow(SW_HIDE);

		mfishingImageScaleSlider.ShowWindow(SW_SHOW);
		mfishingImageScaleValue.ShowWindow(SW_SHOW);

		mwaveImageScaleSlider.ShowWindow(SW_HIDE);
		mwaveImageScaleValue.ShowWindow(SW_HIDE);
	}

	else if(100==imgType){

		mcloudyImageScaleSlider.ShowWindow(SW_HIDE);
		mcloudyImageScaleValue.ShowWindow(SW_HIDE);

		mdarkImageScaleSlider.ShowWindow(SW_HIDE);
		mdarkImageScaleValue.ShowWindow(SW_HIDE);

		mfullImageScaleSlider.ShowWindow(SW_HIDE);
		mfullImageScaleValue.ShowWindow(SW_HIDE);

		mmountainImageScaleSlider.ShowWindow(SW_HIDE);
		mmountainImageScaleValue.ShowWindow(SW_HIDE);

		msunsetImageScaleSlider.ShowWindow(SW_HIDE);
		msunsetImageScaleValue.ShowWindow(SW_HIDE);

		mwaterImageScaleSlider.ShowWindow(SW_HIDE);
		mwaterImageScaleValue.ShowWindow(SW_HIDE);

		mtropicalImageScaleSlider.ShowWindow(SW_HIDE);
		mtropicalImageScaleValue.ShowWindow(SW_HIDE);

		mfilmImageScaleSlider.ShowWindow(SW_HIDE);
		mfilmImageScaleValue.ShowWindow(SW_HIDE);

		mslateImageScaleSlider.ShowWindow(SW_HIDE);
		mslateImageScaleValue.ShowWindow(SW_HIDE);

		mprojImageScaleSlider.ShowWindow(SW_HIDE);
		mprojImageScaleValue.ShowWindow(SW_HIDE);

		moceanImageScaleSlider.ShowWindow(SW_HIDE);
		moceanImageScaleValue.ShowWindow(SW_HIDE);

		mfishingImageScaleSlider.ShowWindow(SW_HIDE);
		mfishingImageScaleValue.ShowWindow(SW_HIDE);

		mwaveImageScaleSlider.ShowWindow(SW_HIDE);
		mwaveImageScaleValue.ShowWindow(SW_HIDE);
	}

}
void CImageEditDlg::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	CMainFrame* pFrame = (CMainFrame*)AfxGetMainWnd();				//View호출
	CMakoryView* pView = (CMakoryView*)pFrame->GetActiveView();		//View호출

	pView->Invalidate(FALSE);

	if(pScrollBar)
	{
		// 어떤 슬라이더인지 검사
		if(pScrollBar == (CScrollBar*)&mcloudyImageScaleSlider)//balloon red slider인경우
		{

			// 슬라이더의 위치를 검사한다.
			int npos = mcloudyImageScaleSlider.GetPos(); //슬라이더 위치 얻어옴
			CString str;
			str.Format(_T("%d"), npos); //형변환
			mcloudyImageScaleValue.SetWindowTextA(str); //edit 박스에 슬라이더 값 들어감

			scalecloudy = (double)npos * 0.005; //슬라이더는 소숫점이 사용이 안됨

			pView->HotAirBalloon.balloonscale=scalecloudy;//Cloudy Light Rays의 이미지 스케일 바꿔줌
			pView->Invalidate(FALSE);
		}

		else if(pScrollBar == (CScrollBar*)&mdarkImageScaleSlider)
		{

			// 슬라이더의 위치를 검사한다.
			int npos = mdarkImageScaleSlider.GetPos(); //슬라이더 위치 얻어옴
			CString str;
			str.Format(_T("%d"), npos); //형변환
			mdarkImageScaleValue.SetWindowTextA(str); //edit 박스에 슬라이더 값 들어감

			scaledark = (double)npos * 0.005; //슬라이더는 소숫점이 사용이 안됨

			pView->HotAirBalloon.darkstormyscale=scaledark;//Dark Stormy의 이미지 스케일 바꿔줌
			pView->Invalidate(FALSE);

		}
		else if(pScrollBar == (CScrollBar*)&mfullImageScaleSlider)
		{

			// 슬라이더의 위치를 검사한다.
			int npos = mfullImageScaleSlider.GetPos(); //슬라이더 위치 얻어옴
			CString str;
			str.Format(_T("%d"), npos); //형변환
			mfullImageScaleValue.SetWindowTextA(str); //edit 박스에 슬라이더 값 들어감

			scalefull = (double)npos * 0.005; //슬라이더는 소숫점이 사용이 안됨

			pView->HotAirBalloon.fullmoonscale=scalefull;//Dark Stormy의 이미지 스케일 바꿔줌
			pView->Invalidate(FALSE);

		}
		else if(pScrollBar == (CScrollBar*)&mmountainImageScaleSlider)
		{

			// 슬라이더의 위치를 검사한다.
			int npos = mmountainImageScaleSlider.GetPos(); //슬라이더 위치 얻어옴
			CString str;
			str.Format(_T("%d"), npos); //형변환
			mmountainImageScaleValue.SetWindowTextA(str); //edit 박스에 슬라이더 값 들어감

			scalemountain = (double)npos * 0.005; //슬라이더는 소숫점이 사용이 안됨

			pView->HotAirBalloon.mountscale=scalemountain;//Dark Stormy의 이미지 스케일 바꿔줌
			pView->Invalidate(FALSE);

		}

		else if(pScrollBar == (CScrollBar*)&msunsetImageScaleSlider)
		{

			// 슬라이더의 위치를 검사한다.
			int npos = msunsetImageScaleSlider.GetPos(); //슬라이더 위치 얻어옴
			CString str;
			str.Format(_T("%d"), npos); //형변환
			msunsetImageScaleValue.SetWindowTextA(str); //edit 박스에 슬라이더 값 들어감

			scalesunset = (double)npos * 0.005; //슬라이더는 소숫점이 사용이 안됨

			pView->HotAirBalloon.sunsetscale=scalesunset;//Dark Stormy의 이미지 스케일 바꿔줌
			pView->Invalidate(FALSE);

		}

		else if(pScrollBar == (CScrollBar*)&mwaterImageScaleSlider)
		{

			// 슬라이더의 위치를 검사한다.
			int npos = mwaterImageScaleSlider.GetPos(); //슬라이더 위치 얻어옴
			CString str;
			str.Format(_T("%d"), npos); //형변환
			mwaterImageScaleValue.SetWindowTextA(str); //edit 박스에 슬라이더 값 들어감

			scalewater = (double)npos * 0.005; //슬라이더는 소숫점이 사용이 안됨

			pView->HotAirBalloon.cloudsscale=scalewater;//Dark Stormy의 이미지 스케일 바꿔줌
			pView->Invalidate(FALSE);

		}
		else if(pScrollBar == (CScrollBar*)&mtropicalImageScaleSlider)
		{

			// 슬라이더의 위치를 검사한다.
			int npos = mtropicalImageScaleSlider.GetPos(); //슬라이더 위치 얻어옴
			CString str;
			str.Format(_T("%d"), npos); //형변환
			mtropicalImageScaleValue.SetWindowTextA(str); //edit 박스에 슬라이더 값 들어감

			scaletropical= (double)npos * 0.005; //슬라이더는 소숫점이 사용이 안됨

			pView->HotAirBalloon.tropicalscale=scaletropical;//Dark Stormy의 이미지 스케일 바꿔줌
			pView->Invalidate(FALSE);
		}

		else if(pScrollBar == (CScrollBar*)&mprojImageScaleSlider)
		{

			// 슬라이더의 위치를 검사한다.
			int npos = mprojImageScaleSlider.GetPos(); //슬라이더 위치 얻어옴
			CString str;
			str.Format(_T("%d"), npos-50); //형변환

			mprojImageScaleValue.SetWindowTextA(str); //edit 박스에 슬라이더 값 들어감
			if(npos <= 50){ //슬라이더가 50이하일때
				scaleproj = 2*(-0.5+((double)npos * 0.01)); //왼쪽으로 이동 
			} 
			else if(npos >= 50){  //슬라이더가 50이상일때
				scaleproj = 5*(((double)npos * 0.001)-0.05); //오른쪽으로 이동
			}

			pView->projimgscale=scaleproj;//Dark Stormy의 이미지 스케일 바꿔줌
			pView->Invalidate(FALSE);
		}

		else if(pScrollBar == (CScrollBar*)&mfilmImageScaleSlider)
		{

			// 슬라이더의 위치를 검사한다.
			int npos = mfilmImageScaleSlider.GetPos(); //슬라이더 위치 얻어옴
			CString str;
			str.Format(_T("%d"), npos-50); //형변환

			mfilmImageScaleValue.SetWindowTextA(str); //edit 박스에 슬라이더 값 들어감
			if(npos <= 50){ //슬라이더가 50이하일때
				scalefilm = 2*(-0.05+((double)npos * 0.001)); //왼쪽으로 이동 
			} 
			else if(npos >= 50){  //슬라이더가 50이상일때
				scalefilm = ((double)npos * 0.0001)-0.005; //오른쪽으로 이동
			}

			pView->Film.filmimgscale=scalefilm;//Fishy값을 바꿔줌
			pView->Invalidate(FALSE);
		
		}

		else if(pScrollBar == (CScrollBar*)&mslateImageScaleSlider)
		{

			// 슬라이더의 위치를 검사한다.
			int npos = mslateImageScaleSlider.GetPos(); //슬라이더 위치 얻어옴
			CString str;
			str.Format(_T("%d"), npos-50); //형변환

			mslateImageScaleValue.SetWindowTextA(str); //edit 박스에 슬라이더 값 들어감
			if(npos <= 50){ //슬라이더가 50이하일때
				scaleslate = 2*(-0.5+((double)npos * 0.01)); //왼쪽으로 이동 
			} 
			else if(npos >= 50){  //슬라이더가 50이상일때
				scaleslate = 5*(((double)npos * 0.001)-0.05);  //오른쪽으로 이동
			}

			pView->slateimgscale=scaleslate;//Dark Stormy의 이미지 스케일 바꿔줌
			pView->Invalidate(FALSE);
		}

		else if(pScrollBar == (CScrollBar*)&mwaveImageScaleSlider)
		{

			// 슬라이더의 위치를 검사한다.
			int npos = mwaveImageScaleSlider.GetPos(); //슬라이더 위치 얻어옴
			CString str;
			str.Format(_T("%d"), npos-50); //형변환

			mwaveImageScaleValue.SetWindowTextA(str); //edit 박스에 슬라이더 값 들어감
			if(npos <= 50){ //슬라이더가 50이하일때
				scalewave = (-0.5+((double)npos * 0.01)); //왼쪽으로 이동 
			} 
			else if(npos >= 50){  //슬라이더가 50이상일때
				scalewave = ((double)npos * 0.01)-0.5; //오른쪽으로 이동
			}

			pView->Ocean.waveimgscale=scalewave;//Dark Stormy의 이미지 스케일 바꿔줌
			pView->Invalidate(FALSE);


		}
		else if(pScrollBar == (CScrollBar*)&moceanImageScaleSlider)
		{

			// 슬라이더의 위치를 검사한다.
			int npos = moceanImageScaleSlider.GetPos(); //슬라이더 위치 얻어옴
			CString str;
			str.Format(_T("%d"), npos-50); //형변환

			moceanImageScaleValue.SetWindowTextA(str); //edit 박스에 슬라이더 값 들어감
			if(npos <= 50){ //슬라이더가 50이하일때
				scaleocean = (-0.5+((double)npos * 0.01)); //왼쪽으로 이동 
			} 
			else if(npos >= 50){  //슬라이더가 50이상일때
				scaleocean = 2*(((double)npos * 0.01)-0.5); //오른쪽으로 이동
			}

		
			pView->Ocean.oceanimgscale=scaleocean;//Dark Stormy의 이미지 스케일 바꿔줌
			pView->Invalidate(FALSE);
		}
		else if(pScrollBar == (CScrollBar*)&mfishingImageScaleSlider)
		{

		int npos = mfishingImageScaleSlider.GetPos(); //슬라이더 위치 얻어옴
			CString str;
			str.Format(_T("%d"), npos-50); //형변환

			mfishingImageScaleValue.SetWindowTextA(str); //edit 박스에 슬라이더 값 들어감
			if(npos <= 50){ //슬라이더가 50이하일때
				scalefishing = 2*((-0.005+((double)npos * 0.0001))); //왼쪽으로 이동 
			} 
			else if(npos >= 50){  //슬라이더가 50이상일때
				scalefishing = 3*((((double)npos * 0.001)-0.05)); //오른쪽으로 이동
			}
	
			pView->Ocean.fishingimgscale=scalefishing;//Dark Stormy의 이미지 스케일 바꿔줌
			pView->Invalidate(FALSE);
		}
	}
	CDialogEx::OnHScroll(nSBCode, nPos, pScrollBar);
}

//cloudy
void CImageEditDlg::OnEnUpdatecloudyImageScaleValue()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CDialogEx::OnInitDialog() 함수를 재지정 
	//하여, IParam 마스크에 OR 연산하여 설정된 ENM_SCROLL 플래그를 지정하여 컨트롤에 EM_SETEVENTMASK 메시지를 보내지 않으면
	// 편집 컨트롤이 바뀐 텍스트를 표시하려고 함을 나타냅니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CMainFrame* pFrame = (CMainFrame*)AfxGetMainWnd();            //View호출
	CMakoryView* pView = (CMakoryView*)pFrame->GetActiveView();      //View호출

	if(UpdateData(TRUE)){

		int d;
		double ds;
		CString String;

		mcloudyImageScaleValue.GetWindowTextA(String);
		d = _ttoi(String);
		mcloudyImageScaleSlider.SetPos(d);
		if(d<=100){
			ds = (double)d * 0.005; //슬라이더는 소숫점이 사용이 안됨
			pView->HotAirBalloon.balloonscale=ds;//이미지 사이즈 바꿔준다.
			pView->Invalidate(FALSE);
		}
		else if(d>100){
			d = 100;
		}

	}
}

//dark stormy
void CImageEditDlg::OnEnUpdatedarkImageScaleValue()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CDialogEx::OnInitDialog() 함수를 재지정 
	//하여, IParam 마스크에 OR 연산하여 설정된 ENM_SCROLL 플래그를 지정하여 컨트롤에 EM_SETEVENTMASK 메시지를 보내지 않으면
	// 편집 컨트롤이 바뀐 텍스트를 표시하려고 함을 나타냅니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CMainFrame* pFrame = (CMainFrame*)AfxGetMainWnd();            //View호출
	CMakoryView* pView = (CMakoryView*)pFrame->GetActiveView();      //View호출

	if(UpdateData(TRUE)){

		int d;
		double ds;
		CString String;

		mdarkImageScaleValue.GetWindowTextA(String);

		d = _ttoi(String);

		mdarkImageScaleSlider.SetPos(d);
		if(d<=100){
			ds = (double)d * 0.005; //슬라이더는 소숫점이 사용이 안됨
			pView->HotAirBalloon.darkstormyscale=ds;//이미지 사이즈 바꿔준다.
			pView->Invalidate(FALSE);
		}
		else if(d>100){
			d = 100;
		}
		
	}
}

//fullmoon
void CImageEditDlg::OnEnUpdatefullImageScaleValue()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CDialogEx::OnInitDialog() 함수를 재지정 
	//하여, IParam 마스크에 OR 연산하여 설정된 ENM_SCROLL 플래그를 지정하여 컨트롤에 EM_SETEVENTMASK 메시지를 보내지 않으면
	// 편집 컨트롤이 바뀐 텍스트를 표시하려고 함을 나타냅니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CMainFrame* pFrame = (CMainFrame*)AfxGetMainWnd();            //View호출
	CMakoryView* pView = (CMakoryView*)pFrame->GetActiveView();      //View호출

	if(UpdateData(TRUE)){

		int d;
		double ds;
		CString String;

		mfullImageScaleValue.GetWindowTextA(String);
		d = _ttoi(String);
		mfullImageScaleSlider.SetPos(d);
		if(d<=100){
			ds = (double)d * 0.005; //슬라이더는 소숫점이 사용이 안됨
			pView->HotAirBalloon.fullmoonscale=ds;//이미지 사이즈 바꿔준다.
			pView->Invalidate(FALSE);
		}
		else if(d>100){
			d = 100;
		}

	}
}
//mountain
void CImageEditDlg::OnEnUpdatemountainImageScaleValue()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CDialogEx::OnInitDialog() 함수를 재지정 
	//하여, IParam 마스크에 OR 연산하여 설정된 ENM_SCROLL 플래그를 지정하여 컨트롤에 EM_SETEVENTMASK 메시지를 보내지 않으면
	// 편집 컨트롤이 바뀐 텍스트를 표시하려고 함을 나타냅니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CMainFrame* pFrame = (CMainFrame*)AfxGetMainWnd();            //View호출
	CMakoryView* pView = (CMakoryView*)pFrame->GetActiveView();      //View호출

	if(UpdateData(TRUE)){

		int d;
		double ds;
		CString String;

		mmountainImageScaleValue.GetWindowTextA(String);
		d = _ttoi(String);
		mmountainImageScaleSlider.SetPos(d);
		if(d<=100){
			ds = (double)d * 0.005; //슬라이더는 소숫점이 사용이 안됨
			pView->HotAirBalloon.mountscale=ds;//이미지 사이즈 바꿔준다.
			pView->Invalidate(FALSE);
		}
		else if(d>100){
			d = 100;
		}
		
	}
}

//sunset
void CImageEditDlg::OnEnUpdatesunsetImageScaleValue()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CDialogEx::OnInitDialog() 함수를 재지정 
	//하여, IParam 마스크에 OR 연산하여 설정된 ENM_SCROLL 플래그를 지정하여 컨트롤에 EM_SETEVENTMASK 메시지를 보내지 않으면
	// 편집 컨트롤이 바뀐 텍스트를 표시하려고 함을 나타냅니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CMainFrame* pFrame = (CMainFrame*)AfxGetMainWnd();            //View호출
	CMakoryView* pView = (CMakoryView*)pFrame->GetActiveView();      //View호출

	if(UpdateData(TRUE)){

		int d;
		double ds;
		CString String;

		msunsetImageScaleValue.GetWindowTextA(String);
		d = _ttoi(String);
		msunsetImageScaleSlider.SetPos(d);
		if(d<=100){
			ds = (double)d * 0.005; //슬라이더는 소숫점이 사용이 안됨
			pView->HotAirBalloon.sunsetscale=ds;//이미지 사이즈 바꿔준다.
			pView->Invalidate(FALSE);
		}
		else if(d>100){
			d = 100;
		}

	}
}

//clouds water
void CImageEditDlg::OnEnUpdatewaterImageScaleValue()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CDialogEx::OnInitDialog() 함수를 재지정 
	//하여, IParam 마스크에 OR 연산하여 설정된 ENM_SCROLL 플래그를 지정하여 컨트롤에 EM_SETEVENTMASK 메시지를 보내지 않으면
	// 편집 컨트롤이 바뀐 텍스트를 표시하려고 함을 나타냅니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CMainFrame* pFrame = (CMainFrame*)AfxGetMainWnd();            //View호출
	CMakoryView* pView = (CMakoryView*)pFrame->GetActiveView();      //View호출

	if(UpdateData(TRUE)){

		int d;
		double ds;
		CString String;

		mwaterImageScaleValue.GetWindowTextA(String);
		d = _ttoi(String);
		mwaterImageScaleSlider.SetPos(d);

		if(d<=100){
			ds = (double)d * 0.005; //슬라이더는 소숫점이 사용이 안됨
			pView->HotAirBalloon.cloudsscale=ds;//이미지 사이즈 바꿔준다.
			pView->Invalidate(FALSE);
		}
		else if(d>100){
			d = 100;
		}
		
	}
}
//tropical
void CImageEditDlg::OnEnUpdatetropicalImageScaleValue()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CDialogEx::OnInitDialog() 함수를 재지정 
	//하여, IParam 마스크에 OR 연산하여 설정된 ENM_SCROLL 플래그를 지정하여 컨트롤에 EM_SETEVENTMASK 메시지를 보내지 않으면
	// 편집 컨트롤이 바뀐 텍스트를 표시하려고 함을 나타냅니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CMainFrame* pFrame = (CMainFrame*)AfxGetMainWnd();            //View호출
	CMakoryView* pView = (CMakoryView*)pFrame->GetActiveView();      //View호출

	if(UpdateData(TRUE)){

		int d;
		double ds;
		CString String;

		mtropicalImageScaleValue.GetWindowTextA(String);
		d = _ttoi(String);
		mtropicalImageScaleSlider.SetPos(d);
		if(d<=100){
			ds = (double)d * 0.005; //슬라이더는 소숫점이 사용이 안됨
			pView->HotAirBalloon.tropicalscale=ds;//이미지 사이즈 바꿔준다.
			pView->Invalidate(FALSE);
		}
		else if(d>100){
			d = 100;
		}
	}
}

void CImageEditDlg::OnEnUpdatefilmImageScaleValue()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CDialogEx::OnInitDialog() 함수를 재지정 
	//하여, IParam 마스크에 OR 연산하여 설정된 ENM_SCROLL 플래그를 지정하여 컨트롤에 EM_SETEVENTMASK 메시지를 보내지 않으면
	// 편집 컨트롤이 바뀐 텍스트를 표시하려고 함을 나타냅니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CMainFrame* pFrame = (CMainFrame*)AfxGetMainWnd();            //View호출
	CMakoryView* pView = (CMakoryView*)pFrame->GetActiveView();      //View호출

	if(UpdateData(TRUE)){

		int d;
		CString String;
		double ds;
		mfilmImageScaleValue.GetWindowTextA(String);
		d = _ttoi(String)+50;
		mfilmImageScaleSlider.SetPos(d);

		if (d<0){
			d = 0;
			ds = 2*(-0.05+((double)d * 0.001)); //왼쪽으로 이동  
			pView->Film.filmimgscale=ds;//Fishy값을 바꿔줌
			pView->Invalidate(FALSE);
		}

		else if(d<=100){

			if(d <= 50){ //슬라이더가 50이하일때
				ds = 2*(-0.05+((double)d * 0.001)); //왼쪽으로 이동 
			} 
			else if(d <= 100){  //슬라이더가 50이상일때
				ds = ((double)d * 0.0001)-0.005; //오른쪽으로 이동
			}

			pView->Film.filmimgscale=ds;//Fishy값을 바꿔줌
			pView->Invalidate(FALSE);

		}
			else if(d>100){
			d = 100;
			ds = ((double)d * 0.0001)-0.005; //오른쪽으로 이동
			pView->Film.filmimgscale=ds;//Dark Stormy의 이미지 스케일 바꿔줌
			pView->Invalidate(FALSE);
	
		}
	}
}

void CImageEditDlg::OnEnUpdateslateImageScaleValue()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CDialogEx::OnInitDialog() 함수를 재지정 
	//하여, IParam 마스크에 OR 연산하여 설정된 ENM_SCROLL 플래그를 지정하여 컨트롤에 EM_SETEVENTMASK 메시지를 보내지 않으면
	// 편집 컨트롤이 바뀐 텍스트를 표시하려고 함을 나타냅니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CMainFrame* pFrame = (CMainFrame*)AfxGetMainWnd();            //View호출
	CMakoryView* pView = (CMakoryView*)pFrame->GetActiveView();      //View호출

if(UpdateData(TRUE)){

		int d;
		CString String;
		double ds;
		mslateImageScaleValue.GetWindowTextA(String);
		d = _ttoi(String)+50;
		mslateImageScaleSlider.SetPos(d);

		if (d<0){
			d = 0;
			ds = 2*(-0.5+((double)d * 0.01)); //왼쪽으로 이동  
			pView->slateimgscale=ds;//Fishy값을 바꿔줌
			pView->Invalidate(FALSE);
		}
		else if(d<=100){

			if(d <= 50){ //슬라이더가 50이하일때
				ds = 2*(-0.5+((double)d * 0.01));  //왼쪽으로 이동 
			} 
			else if(d >= 50){  //슬라이더가 50이상일때
				ds = 5*(((double)d * 0.001)-0.05);  //오른쪽으로 이동
			}

			pView->slateimgscale=ds;//Fishy값을 바꿔줌
			pView->Invalidate(FALSE);

		}
		else if(d>100){
			d = 100;
			ds = 5*(((double)d * 0.001)-0.05); //오른쪽으로 이동
			pView->slateimgscale=ds;//Dark Stormy의 이미지 스케일 바꿔줌
			pView->Invalidate(FALSE);
	
		}
	}
}

void CImageEditDlg::OnEnUpdateprojImageScaleValue()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	CMainFrame* pFrame = (CMainFrame*)AfxGetMainWnd();            //View호출
	CMakoryView* pView = (CMakoryView*)pFrame->GetActiveView();      //View호출

	if(UpdateData(TRUE)){

				int d;
		CString String;
		double ds;
		mprojImageScaleValue.GetWindowTextA(String);
		d = _ttoi(String)+50;
		mprojImageScaleSlider.SetPos(d);

		if (d<0){
			d = 0;
			ds = 2*(-0.5+((double)d * 0.01));  //왼쪽으로 이동   
			pView->projimgscale=ds;//Fishy값을 바꿔줌
			pView->Invalidate(FALSE);
		}

		else if(d<=100){

			if(d <= 50){ //슬라이더가 50이하일때
				ds = 2*(-0.5+((double)d * 0.01));  //왼쪽으로 이동 
			} 
			else if(d >= 50){  //슬라이더가 50이상일때
				ds = 5*(((double)d * 0.001)-0.05); 
			}

			pView->projimgscale=ds;//Fishy값을 바꿔줌
			pView->Invalidate(FALSE);

		}
		else if(d>100){
			d = 100;
			ds = 5*(((double)d * 0.001)-0.05);  //오른쪽으로 이동
			pView->projimgscale=ds;//Dark Stormy의 이미지 스케일 바꿔줌
			pView->Invalidate(FALSE);
	
		}
	
	}
}


void CImageEditDlg::OnEnUpdateoceanImageScaleValue()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CDialogEx::OnInitDialog() 함수를 재지정 
	//하여, IParam 마스크에 OR 연산하여 설정된 ENM_SCROLL 플래그를 지정하여 컨트롤에 EM_SETEVENTMASK 메시지를 보내지 않으면
	// 편집 컨트롤이 바뀐 텍스트를 표시하려고 함을 나타냅니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CMainFrame* pFrame = (CMainFrame*)AfxGetMainWnd();            //View호출
	CMakoryView* pView = (CMakoryView*)pFrame->GetActiveView();      //View호출

	if(UpdateData(TRUE)){
		int d;
		double ds;
		CString String;

		moceanImageScaleValue.GetWindowTextA(String);
		d = _ttoi(String)+50;
		moceanImageScaleSlider.SetPos(d);

		
		if (d<0){
			d = 0;
			ds =(-0.5+((double)d * 0.01));  //왼쪽으로 이동 //왼쪽으로 이동   
			pView->Ocean.oceanimgscale=ds;//Dark Stormy의 이미지 스케일 바꿔줌
			pView->Invalidate(FALSE);;
		}

		else if(d<=100){

			if(d <= 50){ //슬라이더가 50이하일때
				ds =(-0.5+((double)d * 0.01));  //왼쪽으로 이동 
			} 
			else if(d >= 50){  //슬라이더가 50이상일때
				ds = 2*((-0.5+((double)d * 0.01))); //오른쪽으로 이동
			}

			pView->Ocean.oceanimgscale=ds;//Dark Stormy의 이미지 스케일 바꿔줌
			pView->Invalidate(FALSE);
	

		}
		else if(d>100){
			d = 100;
			ds = 2*((-0.5+((double)d * 0.01))); //오른쪽으로 이동
			pView->Ocean.oceanimgscale=ds;//Dark Stormy의 이미지 스케일 바꿔줌
			pView->Invalidate(FALSE);
	
		}
	}
}

void CImageEditDlg::OnEnUpdatefishingImageScaleValue()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CDialogEx::OnInitDialog() 함수를 재지정 
	//하여, IParam 마스크에 OR 연산하여 설정된 ENM_SCROLL 플래그를 지정하여 컨트롤에 EM_SETEVENTMASK 메시지를 보내지 않으면
	// 편집 컨트롤이 바뀐 텍스트를 표시하려고 함을 나타냅니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CMainFrame* pFrame = (CMainFrame*)AfxGetMainWnd();            //View호출
	CMakoryView* pView = (CMakoryView*)pFrame->GetActiveView();      //View호출


		if(UpdateData(TRUE)){
		int d;
		double ds;
		CString String;

		mfishingImageScaleValue.GetWindowTextA(String);
		d = _ttoi(String)+50;
		mfishingImageScaleSlider.SetPos(d);
				
		if (d<0){
			d = 0;
			ds =2*((((double)d * 0.001)-0.05));   //왼쪽으로 이동 /
				pView->Ocean.fishingimgscale=ds;//Dark Stormy의 이미지 스케일 바꿔줌
			pView->Invalidate(FALSE);
		}
		else if(d<=100){

			if(d <= 50){ //슬라이더가 50이하일때
				ds =2*((-0.005+((double)d * 0.0001)));   //왼쪽으로 이동 
			} 
			else if(d >= 50){  //슬라이더가 50이상일때
				ds = 3*((((double)d * 0.001)-0.05));  //오른쪽으로 이동
			}

			pView->Ocean.fishingimgscale=ds;//Dark Stormy의 이미지 스케일 바꿔줌
			pView->Invalidate(FALSE);
	

		}
		else if(d>100){
			d = 100;
			ds = 5*((((double)d * 0.001)-0.05));  //오른쪽으로 이동
			pView->Ocean.fishingimgscale=ds;//Dark Stormy의 이미지 스케일 바꿔줌
			pView->Invalidate(FALSE);
	
		}

	}
}

void CImageEditDlg::OnEnUpdatewaveImageScaleValue()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	CMainFrame* pFrame = (CMainFrame*)AfxGetMainWnd();            //View호출
	CMakoryView* pView = (CMakoryView*)pFrame->GetActiveView();      //View호출

	if(UpdateData(TRUE)){
		int d;
		double ds;
		CString String;

		mwaveImageScaleValue.GetWindowTextA(String);
		d = _ttoi(String)+50;
		mwaveImageScaleSlider.SetPos(d);
		if (d<0){
			d = 0;
			ds =(-0.5+((double)d * 0.01));  //왼쪽으로 이동 
			pView->Ocean.waveimgscale=ds;//Dark Stormy의 이미지 스케일 바꿔줌
			pView->Invalidate(FALSE);
		}

		if(d<=100){

			if(d <= 50){ //슬라이더가 50이하일때
				ds =(-0.5+((double)d * 0.01));  //왼쪽으로 이동 
			} 
			else if(d >= 50){  //슬라이더가 50이상일때
				ds = (-0.5+((double)d * 0.01)); //오른쪽으로 이동
			}

			pView->Ocean.waveimgscale=ds;//Dark Stormy의 이미지 스케일 바꿔줌
			pView->Invalidate(FALSE);
	

		}
		else if(d>100){
			d = 100;
			ds = (-0.5+((double)d * 0.01)); //오른쪽으로 이동
			pView->Ocean.waveimgscale=ds;//Dark Stormy의 이미지 스케일 바꿔줌
			pView->Invalidate(FALSE);
	
		}
	}
}
