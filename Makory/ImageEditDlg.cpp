// EdittapCtrl.cpp : ���� �����Դϴ�.
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
// CImageEditDlg ��ȭ �����Դϴ�.

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


// CImageEditDlg �޽��� ó�����Դϴ�.

BOOL CImageEditDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.

	mfilmImageScaleSlider.SetPos(50);//�����̴� ó�� ��ġ
	mfilmImageScaleSlider.SetRange(0, 100); //�����̴� ���� 0 ~ 100���� ��.
	mfilmImageScaleSlider.SetPageSize(1);  //�����̴��� Ŭ������ �� �����̴� ����
	mfilmImageScaleValue.SetWindowTextA("0");//h edit�ڽ� �ʱⰪ

	mslateImageScaleSlider.SetPos(50);
	mslateImageScaleSlider.SetRange(0, 100);
	mslateImageScaleSlider.SetPageSize(1);  //�����̴��� Ŭ������ �� �����̴� ����
	mslateImageScaleValue.SetWindowTextA("0");//h edit�ڽ� �ʱⰪ

	mwaveImageScaleSlider.SetPos(50);
	mwaveImageScaleSlider.SetRange(0, 100); //�����̴� ���� 0 ~ 100���� ��.
	mwaveImageScaleSlider.SetPageSize(1);  //�����̴��� Ŭ������ �� �����̴� ����
	mwaveImageScaleValue.SetWindowTextA("0");//h edit�ڽ� �ʱⰪ


		mprojImageScaleSlider.SetPos(50);
	mprojImageScaleSlider.SetRange(0, 100); //�����̴� ���� 0 ~ 100���� ��.
	mprojImageScaleSlider.SetPageSize(1);  //�����̴��� Ŭ������ �� �����̴� ����
	mprojImageScaleValue.SetWindowTextA("0");//h edit�ڽ� �ʱⰪ

	mfishingImageScaleSlider.SetPos(50);
	mfishingImageScaleSlider.SetRange(0, 100); //�����̴� ���� 0 ~ 100���� ��.
	mfishingImageScaleSlider.SetPageSize(1);  //�����̴��� Ŭ������ �� �����̴� ����
	mfishingImageScaleValue.SetWindowTextA("0");//h edit�ڽ� �ʱⰪ

	moceanImageScaleSlider.SetPos(50);
	moceanImageScaleSlider.SetRange(0, 100); //�����̴� ���� 0 ~ 100���� ��.
	moceanImageScaleSlider.SetPageSize(1);  //�����̴��� Ŭ������ �� �����̴� ����
	moceanImageScaleValue.SetWindowTextA("0");//h edit�ڽ� �ʱⰪ

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
	// ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
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
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.

	CMainFrame* pFrame = (CMainFrame*)AfxGetMainWnd();				//Viewȣ��
	CMakoryView* pView = (CMakoryView*)pFrame->GetActiveView();		//Viewȣ��

	pView->Invalidate(FALSE);

	if(pScrollBar)
	{
		// � �����̴����� �˻�
		if(pScrollBar == (CScrollBar*)&mcloudyImageScaleSlider)//balloon red slider�ΰ��
		{

			// �����̴��� ��ġ�� �˻��Ѵ�.
			int npos = mcloudyImageScaleSlider.GetPos(); //�����̴� ��ġ ����
			CString str;
			str.Format(_T("%d"), npos); //����ȯ
			mcloudyImageScaleValue.SetWindowTextA(str); //edit �ڽ��� �����̴� �� ��

			scalecloudy = (double)npos * 0.005; //�����̴��� �Ҽ����� ����� �ȵ�

			pView->HotAirBalloon.balloonscale=scalecloudy;//Cloudy Light Rays�� �̹��� ������ �ٲ���
			pView->Invalidate(FALSE);
		}

		else if(pScrollBar == (CScrollBar*)&mdarkImageScaleSlider)
		{

			// �����̴��� ��ġ�� �˻��Ѵ�.
			int npos = mdarkImageScaleSlider.GetPos(); //�����̴� ��ġ ����
			CString str;
			str.Format(_T("%d"), npos); //����ȯ
			mdarkImageScaleValue.SetWindowTextA(str); //edit �ڽ��� �����̴� �� ��

			scaledark = (double)npos * 0.005; //�����̴��� �Ҽ����� ����� �ȵ�

			pView->HotAirBalloon.darkstormyscale=scaledark;//Dark Stormy�� �̹��� ������ �ٲ���
			pView->Invalidate(FALSE);

		}
		else if(pScrollBar == (CScrollBar*)&mfullImageScaleSlider)
		{

			// �����̴��� ��ġ�� �˻��Ѵ�.
			int npos = mfullImageScaleSlider.GetPos(); //�����̴� ��ġ ����
			CString str;
			str.Format(_T("%d"), npos); //����ȯ
			mfullImageScaleValue.SetWindowTextA(str); //edit �ڽ��� �����̴� �� ��

			scalefull = (double)npos * 0.005; //�����̴��� �Ҽ����� ����� �ȵ�

			pView->HotAirBalloon.fullmoonscale=scalefull;//Dark Stormy�� �̹��� ������ �ٲ���
			pView->Invalidate(FALSE);

		}
		else if(pScrollBar == (CScrollBar*)&mmountainImageScaleSlider)
		{

			// �����̴��� ��ġ�� �˻��Ѵ�.
			int npos = mmountainImageScaleSlider.GetPos(); //�����̴� ��ġ ����
			CString str;
			str.Format(_T("%d"), npos); //����ȯ
			mmountainImageScaleValue.SetWindowTextA(str); //edit �ڽ��� �����̴� �� ��

			scalemountain = (double)npos * 0.005; //�����̴��� �Ҽ����� ����� �ȵ�

			pView->HotAirBalloon.mountscale=scalemountain;//Dark Stormy�� �̹��� ������ �ٲ���
			pView->Invalidate(FALSE);

		}

		else if(pScrollBar == (CScrollBar*)&msunsetImageScaleSlider)
		{

			// �����̴��� ��ġ�� �˻��Ѵ�.
			int npos = msunsetImageScaleSlider.GetPos(); //�����̴� ��ġ ����
			CString str;
			str.Format(_T("%d"), npos); //����ȯ
			msunsetImageScaleValue.SetWindowTextA(str); //edit �ڽ��� �����̴� �� ��

			scalesunset = (double)npos * 0.005; //�����̴��� �Ҽ����� ����� �ȵ�

			pView->HotAirBalloon.sunsetscale=scalesunset;//Dark Stormy�� �̹��� ������ �ٲ���
			pView->Invalidate(FALSE);

		}

		else if(pScrollBar == (CScrollBar*)&mwaterImageScaleSlider)
		{

			// �����̴��� ��ġ�� �˻��Ѵ�.
			int npos = mwaterImageScaleSlider.GetPos(); //�����̴� ��ġ ����
			CString str;
			str.Format(_T("%d"), npos); //����ȯ
			mwaterImageScaleValue.SetWindowTextA(str); //edit �ڽ��� �����̴� �� ��

			scalewater = (double)npos * 0.005; //�����̴��� �Ҽ����� ����� �ȵ�

			pView->HotAirBalloon.cloudsscale=scalewater;//Dark Stormy�� �̹��� ������ �ٲ���
			pView->Invalidate(FALSE);

		}
		else if(pScrollBar == (CScrollBar*)&mtropicalImageScaleSlider)
		{

			// �����̴��� ��ġ�� �˻��Ѵ�.
			int npos = mtropicalImageScaleSlider.GetPos(); //�����̴� ��ġ ����
			CString str;
			str.Format(_T("%d"), npos); //����ȯ
			mtropicalImageScaleValue.SetWindowTextA(str); //edit �ڽ��� �����̴� �� ��

			scaletropical= (double)npos * 0.005; //�����̴��� �Ҽ����� ����� �ȵ�

			pView->HotAirBalloon.tropicalscale=scaletropical;//Dark Stormy�� �̹��� ������ �ٲ���
			pView->Invalidate(FALSE);
		}

		else if(pScrollBar == (CScrollBar*)&mprojImageScaleSlider)
		{

			// �����̴��� ��ġ�� �˻��Ѵ�.
			int npos = mprojImageScaleSlider.GetPos(); //�����̴� ��ġ ����
			CString str;
			str.Format(_T("%d"), npos-50); //����ȯ

			mprojImageScaleValue.SetWindowTextA(str); //edit �ڽ��� �����̴� �� ��
			if(npos <= 50){ //�����̴��� 50�����϶�
				scaleproj = 2*(-0.5+((double)npos * 0.01)); //�������� �̵� 
			} 
			else if(npos >= 50){  //�����̴��� 50�̻��϶�
				scaleproj = 5*(((double)npos * 0.001)-0.05); //���������� �̵�
			}

			pView->projimgscale=scaleproj;//Dark Stormy�� �̹��� ������ �ٲ���
			pView->Invalidate(FALSE);
		}

		else if(pScrollBar == (CScrollBar*)&mfilmImageScaleSlider)
		{

			// �����̴��� ��ġ�� �˻��Ѵ�.
			int npos = mfilmImageScaleSlider.GetPos(); //�����̴� ��ġ ����
			CString str;
			str.Format(_T("%d"), npos-50); //����ȯ

			mfilmImageScaleValue.SetWindowTextA(str); //edit �ڽ��� �����̴� �� ��
			if(npos <= 50){ //�����̴��� 50�����϶�
				scalefilm = 2*(-0.05+((double)npos * 0.001)); //�������� �̵� 
			} 
			else if(npos >= 50){  //�����̴��� 50�̻��϶�
				scalefilm = ((double)npos * 0.0001)-0.005; //���������� �̵�
			}

			pView->Film.filmimgscale=scalefilm;//Fishy���� �ٲ���
			pView->Invalidate(FALSE);
		
		}

		else if(pScrollBar == (CScrollBar*)&mslateImageScaleSlider)
		{

			// �����̴��� ��ġ�� �˻��Ѵ�.
			int npos = mslateImageScaleSlider.GetPos(); //�����̴� ��ġ ����
			CString str;
			str.Format(_T("%d"), npos-50); //����ȯ

			mslateImageScaleValue.SetWindowTextA(str); //edit �ڽ��� �����̴� �� ��
			if(npos <= 50){ //�����̴��� 50�����϶�
				scaleslate = 2*(-0.5+((double)npos * 0.01)); //�������� �̵� 
			} 
			else if(npos >= 50){  //�����̴��� 50�̻��϶�
				scaleslate = 5*(((double)npos * 0.001)-0.05);  //���������� �̵�
			}

			pView->slateimgscale=scaleslate;//Dark Stormy�� �̹��� ������ �ٲ���
			pView->Invalidate(FALSE);
		}

		else if(pScrollBar == (CScrollBar*)&mwaveImageScaleSlider)
		{

			// �����̴��� ��ġ�� �˻��Ѵ�.
			int npos = mwaveImageScaleSlider.GetPos(); //�����̴� ��ġ ����
			CString str;
			str.Format(_T("%d"), npos-50); //����ȯ

			mwaveImageScaleValue.SetWindowTextA(str); //edit �ڽ��� �����̴� �� ��
			if(npos <= 50){ //�����̴��� 50�����϶�
				scalewave = (-0.5+((double)npos * 0.01)); //�������� �̵� 
			} 
			else if(npos >= 50){  //�����̴��� 50�̻��϶�
				scalewave = ((double)npos * 0.01)-0.5; //���������� �̵�
			}

			pView->Ocean.waveimgscale=scalewave;//Dark Stormy�� �̹��� ������ �ٲ���
			pView->Invalidate(FALSE);


		}
		else if(pScrollBar == (CScrollBar*)&moceanImageScaleSlider)
		{

			// �����̴��� ��ġ�� �˻��Ѵ�.
			int npos = moceanImageScaleSlider.GetPos(); //�����̴� ��ġ ����
			CString str;
			str.Format(_T("%d"), npos-50); //����ȯ

			moceanImageScaleValue.SetWindowTextA(str); //edit �ڽ��� �����̴� �� ��
			if(npos <= 50){ //�����̴��� 50�����϶�
				scaleocean = (-0.5+((double)npos * 0.01)); //�������� �̵� 
			} 
			else if(npos >= 50){  //�����̴��� 50�̻��϶�
				scaleocean = 2*(((double)npos * 0.01)-0.5); //���������� �̵�
			}

		
			pView->Ocean.oceanimgscale=scaleocean;//Dark Stormy�� �̹��� ������ �ٲ���
			pView->Invalidate(FALSE);
		}
		else if(pScrollBar == (CScrollBar*)&mfishingImageScaleSlider)
		{

		int npos = mfishingImageScaleSlider.GetPos(); //�����̴� ��ġ ����
			CString str;
			str.Format(_T("%d"), npos-50); //����ȯ

			mfishingImageScaleValue.SetWindowTextA(str); //edit �ڽ��� �����̴� �� ��
			if(npos <= 50){ //�����̴��� 50�����϶�
				scalefishing = 2*((-0.005+((double)npos * 0.0001))); //�������� �̵� 
			} 
			else if(npos >= 50){  //�����̴��� 50�̻��϶�
				scalefishing = 3*((((double)npos * 0.001)-0.05)); //���������� �̵�
			}
	
			pView->Ocean.fishingimgscale=scalefishing;//Dark Stormy�� �̹��� ������ �ٲ���
			pView->Invalidate(FALSE);
		}
	}
	CDialogEx::OnHScroll(nSBCode, nPos, pScrollBar);
}

//cloudy
void CImageEditDlg::OnEnUpdatecloudyImageScaleValue()
{
	// TODO:  RICHEDIT ��Ʈ���� ���, �� ��Ʈ����
	// CDialogEx::OnInitDialog() �Լ��� ������ 
	//�Ͽ�, IParam ����ũ�� OR �����Ͽ� ������ ENM_SCROLL �÷��׸� �����Ͽ� ��Ʈ�ѿ� EM_SETEVENTMASK �޽����� ������ ������
	// ���� ��Ʈ���� �ٲ� �ؽ�Ʈ�� ǥ���Ϸ��� ���� ��Ÿ���ϴ�.

	// TODO:  ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	CMainFrame* pFrame = (CMainFrame*)AfxGetMainWnd();            //Viewȣ��
	CMakoryView* pView = (CMakoryView*)pFrame->GetActiveView();      //Viewȣ��

	if(UpdateData(TRUE)){

		int d;
		double ds;
		CString String;

		mcloudyImageScaleValue.GetWindowTextA(String);
		d = _ttoi(String);
		mcloudyImageScaleSlider.SetPos(d);
		if(d<=100){
			ds = (double)d * 0.005; //�����̴��� �Ҽ����� ����� �ȵ�
			pView->HotAirBalloon.balloonscale=ds;//�̹��� ������ �ٲ��ش�.
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
	// TODO:  RICHEDIT ��Ʈ���� ���, �� ��Ʈ����
	// CDialogEx::OnInitDialog() �Լ��� ������ 
	//�Ͽ�, IParam ����ũ�� OR �����Ͽ� ������ ENM_SCROLL �÷��׸� �����Ͽ� ��Ʈ�ѿ� EM_SETEVENTMASK �޽����� ������ ������
	// ���� ��Ʈ���� �ٲ� �ؽ�Ʈ�� ǥ���Ϸ��� ���� ��Ÿ���ϴ�.

	// TODO:  ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	CMainFrame* pFrame = (CMainFrame*)AfxGetMainWnd();            //Viewȣ��
	CMakoryView* pView = (CMakoryView*)pFrame->GetActiveView();      //Viewȣ��

	if(UpdateData(TRUE)){

		int d;
		double ds;
		CString String;

		mdarkImageScaleValue.GetWindowTextA(String);

		d = _ttoi(String);

		mdarkImageScaleSlider.SetPos(d);
		if(d<=100){
			ds = (double)d * 0.005; //�����̴��� �Ҽ����� ����� �ȵ�
			pView->HotAirBalloon.darkstormyscale=ds;//�̹��� ������ �ٲ��ش�.
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
	// TODO:  RICHEDIT ��Ʈ���� ���, �� ��Ʈ����
	// CDialogEx::OnInitDialog() �Լ��� ������ 
	//�Ͽ�, IParam ����ũ�� OR �����Ͽ� ������ ENM_SCROLL �÷��׸� �����Ͽ� ��Ʈ�ѿ� EM_SETEVENTMASK �޽����� ������ ������
	// ���� ��Ʈ���� �ٲ� �ؽ�Ʈ�� ǥ���Ϸ��� ���� ��Ÿ���ϴ�.

	// TODO:  ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	CMainFrame* pFrame = (CMainFrame*)AfxGetMainWnd();            //Viewȣ��
	CMakoryView* pView = (CMakoryView*)pFrame->GetActiveView();      //Viewȣ��

	if(UpdateData(TRUE)){

		int d;
		double ds;
		CString String;

		mfullImageScaleValue.GetWindowTextA(String);
		d = _ttoi(String);
		mfullImageScaleSlider.SetPos(d);
		if(d<=100){
			ds = (double)d * 0.005; //�����̴��� �Ҽ����� ����� �ȵ�
			pView->HotAirBalloon.fullmoonscale=ds;//�̹��� ������ �ٲ��ش�.
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
	// TODO:  RICHEDIT ��Ʈ���� ���, �� ��Ʈ����
	// CDialogEx::OnInitDialog() �Լ��� ������ 
	//�Ͽ�, IParam ����ũ�� OR �����Ͽ� ������ ENM_SCROLL �÷��׸� �����Ͽ� ��Ʈ�ѿ� EM_SETEVENTMASK �޽����� ������ ������
	// ���� ��Ʈ���� �ٲ� �ؽ�Ʈ�� ǥ���Ϸ��� ���� ��Ÿ���ϴ�.

	// TODO:  ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	CMainFrame* pFrame = (CMainFrame*)AfxGetMainWnd();            //Viewȣ��
	CMakoryView* pView = (CMakoryView*)pFrame->GetActiveView();      //Viewȣ��

	if(UpdateData(TRUE)){

		int d;
		double ds;
		CString String;

		mmountainImageScaleValue.GetWindowTextA(String);
		d = _ttoi(String);
		mmountainImageScaleSlider.SetPos(d);
		if(d<=100){
			ds = (double)d * 0.005; //�����̴��� �Ҽ����� ����� �ȵ�
			pView->HotAirBalloon.mountscale=ds;//�̹��� ������ �ٲ��ش�.
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
	// TODO:  RICHEDIT ��Ʈ���� ���, �� ��Ʈ����
	// CDialogEx::OnInitDialog() �Լ��� ������ 
	//�Ͽ�, IParam ����ũ�� OR �����Ͽ� ������ ENM_SCROLL �÷��׸� �����Ͽ� ��Ʈ�ѿ� EM_SETEVENTMASK �޽����� ������ ������
	// ���� ��Ʈ���� �ٲ� �ؽ�Ʈ�� ǥ���Ϸ��� ���� ��Ÿ���ϴ�.

	// TODO:  ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	CMainFrame* pFrame = (CMainFrame*)AfxGetMainWnd();            //Viewȣ��
	CMakoryView* pView = (CMakoryView*)pFrame->GetActiveView();      //Viewȣ��

	if(UpdateData(TRUE)){

		int d;
		double ds;
		CString String;

		msunsetImageScaleValue.GetWindowTextA(String);
		d = _ttoi(String);
		msunsetImageScaleSlider.SetPos(d);
		if(d<=100){
			ds = (double)d * 0.005; //�����̴��� �Ҽ����� ����� �ȵ�
			pView->HotAirBalloon.sunsetscale=ds;//�̹��� ������ �ٲ��ش�.
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
	// TODO:  RICHEDIT ��Ʈ���� ���, �� ��Ʈ����
	// CDialogEx::OnInitDialog() �Լ��� ������ 
	//�Ͽ�, IParam ����ũ�� OR �����Ͽ� ������ ENM_SCROLL �÷��׸� �����Ͽ� ��Ʈ�ѿ� EM_SETEVENTMASK �޽����� ������ ������
	// ���� ��Ʈ���� �ٲ� �ؽ�Ʈ�� ǥ���Ϸ��� ���� ��Ÿ���ϴ�.

	// TODO:  ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	CMainFrame* pFrame = (CMainFrame*)AfxGetMainWnd();            //Viewȣ��
	CMakoryView* pView = (CMakoryView*)pFrame->GetActiveView();      //Viewȣ��

	if(UpdateData(TRUE)){

		int d;
		double ds;
		CString String;

		mwaterImageScaleValue.GetWindowTextA(String);
		d = _ttoi(String);
		mwaterImageScaleSlider.SetPos(d);

		if(d<=100){
			ds = (double)d * 0.005; //�����̴��� �Ҽ����� ����� �ȵ�
			pView->HotAirBalloon.cloudsscale=ds;//�̹��� ������ �ٲ��ش�.
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
	// TODO:  RICHEDIT ��Ʈ���� ���, �� ��Ʈ����
	// CDialogEx::OnInitDialog() �Լ��� ������ 
	//�Ͽ�, IParam ����ũ�� OR �����Ͽ� ������ ENM_SCROLL �÷��׸� �����Ͽ� ��Ʈ�ѿ� EM_SETEVENTMASK �޽����� ������ ������
	// ���� ��Ʈ���� �ٲ� �ؽ�Ʈ�� ǥ���Ϸ��� ���� ��Ÿ���ϴ�.

	// TODO:  ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	CMainFrame* pFrame = (CMainFrame*)AfxGetMainWnd();            //Viewȣ��
	CMakoryView* pView = (CMakoryView*)pFrame->GetActiveView();      //Viewȣ��

	if(UpdateData(TRUE)){

		int d;
		double ds;
		CString String;

		mtropicalImageScaleValue.GetWindowTextA(String);
		d = _ttoi(String);
		mtropicalImageScaleSlider.SetPos(d);
		if(d<=100){
			ds = (double)d * 0.005; //�����̴��� �Ҽ����� ����� �ȵ�
			pView->HotAirBalloon.tropicalscale=ds;//�̹��� ������ �ٲ��ش�.
			pView->Invalidate(FALSE);
		}
		else if(d>100){
			d = 100;
		}
	}
}

void CImageEditDlg::OnEnUpdatefilmImageScaleValue()
{
	// TODO:  RICHEDIT ��Ʈ���� ���, �� ��Ʈ����
	// CDialogEx::OnInitDialog() �Լ��� ������ 
	//�Ͽ�, IParam ����ũ�� OR �����Ͽ� ������ ENM_SCROLL �÷��׸� �����Ͽ� ��Ʈ�ѿ� EM_SETEVENTMASK �޽����� ������ ������
	// ���� ��Ʈ���� �ٲ� �ؽ�Ʈ�� ǥ���Ϸ��� ���� ��Ÿ���ϴ�.

	// TODO:  ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	CMainFrame* pFrame = (CMainFrame*)AfxGetMainWnd();            //Viewȣ��
	CMakoryView* pView = (CMakoryView*)pFrame->GetActiveView();      //Viewȣ��

	if(UpdateData(TRUE)){

		int d;
		CString String;
		double ds;
		mfilmImageScaleValue.GetWindowTextA(String);
		d = _ttoi(String)+50;
		mfilmImageScaleSlider.SetPos(d);

		if (d<0){
			d = 0;
			ds = 2*(-0.05+((double)d * 0.001)); //�������� �̵�  
			pView->Film.filmimgscale=ds;//Fishy���� �ٲ���
			pView->Invalidate(FALSE);
		}

		else if(d<=100){

			if(d <= 50){ //�����̴��� 50�����϶�
				ds = 2*(-0.05+((double)d * 0.001)); //�������� �̵� 
			} 
			else if(d <= 100){  //�����̴��� 50�̻��϶�
				ds = ((double)d * 0.0001)-0.005; //���������� �̵�
			}

			pView->Film.filmimgscale=ds;//Fishy���� �ٲ���
			pView->Invalidate(FALSE);

		}
			else if(d>100){
			d = 100;
			ds = ((double)d * 0.0001)-0.005; //���������� �̵�
			pView->Film.filmimgscale=ds;//Dark Stormy�� �̹��� ������ �ٲ���
			pView->Invalidate(FALSE);
	
		}
	}
}

void CImageEditDlg::OnEnUpdateslateImageScaleValue()
{
	// TODO:  RICHEDIT ��Ʈ���� ���, �� ��Ʈ����
	// CDialogEx::OnInitDialog() �Լ��� ������ 
	//�Ͽ�, IParam ����ũ�� OR �����Ͽ� ������ ENM_SCROLL �÷��׸� �����Ͽ� ��Ʈ�ѿ� EM_SETEVENTMASK �޽����� ������ ������
	// ���� ��Ʈ���� �ٲ� �ؽ�Ʈ�� ǥ���Ϸ��� ���� ��Ÿ���ϴ�.

	// TODO:  ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	CMainFrame* pFrame = (CMainFrame*)AfxGetMainWnd();            //Viewȣ��
	CMakoryView* pView = (CMakoryView*)pFrame->GetActiveView();      //Viewȣ��

if(UpdateData(TRUE)){

		int d;
		CString String;
		double ds;
		mslateImageScaleValue.GetWindowTextA(String);
		d = _ttoi(String)+50;
		mslateImageScaleSlider.SetPos(d);

		if (d<0){
			d = 0;
			ds = 2*(-0.5+((double)d * 0.01)); //�������� �̵�  
			pView->slateimgscale=ds;//Fishy���� �ٲ���
			pView->Invalidate(FALSE);
		}
		else if(d<=100){

			if(d <= 50){ //�����̴��� 50�����϶�
				ds = 2*(-0.5+((double)d * 0.01));  //�������� �̵� 
			} 
			else if(d >= 50){  //�����̴��� 50�̻��϶�
				ds = 5*(((double)d * 0.001)-0.05);  //���������� �̵�
			}

			pView->slateimgscale=ds;//Fishy���� �ٲ���
			pView->Invalidate(FALSE);

		}
		else if(d>100){
			d = 100;
			ds = 5*(((double)d * 0.001)-0.05); //���������� �̵�
			pView->slateimgscale=ds;//Dark Stormy�� �̹��� ������ �ٲ���
			pView->Invalidate(FALSE);
	
		}
	}
}

void CImageEditDlg::OnEnUpdateprojImageScaleValue()
{
	// TODO:  RICHEDIT ��Ʈ���� ���, �� ��Ʈ����
	CMainFrame* pFrame = (CMainFrame*)AfxGetMainWnd();            //Viewȣ��
	CMakoryView* pView = (CMakoryView*)pFrame->GetActiveView();      //Viewȣ��

	if(UpdateData(TRUE)){

				int d;
		CString String;
		double ds;
		mprojImageScaleValue.GetWindowTextA(String);
		d = _ttoi(String)+50;
		mprojImageScaleSlider.SetPos(d);

		if (d<0){
			d = 0;
			ds = 2*(-0.5+((double)d * 0.01));  //�������� �̵�   
			pView->projimgscale=ds;//Fishy���� �ٲ���
			pView->Invalidate(FALSE);
		}

		else if(d<=100){

			if(d <= 50){ //�����̴��� 50�����϶�
				ds = 2*(-0.5+((double)d * 0.01));  //�������� �̵� 
			} 
			else if(d >= 50){  //�����̴��� 50�̻��϶�
				ds = 5*(((double)d * 0.001)-0.05); 
			}

			pView->projimgscale=ds;//Fishy���� �ٲ���
			pView->Invalidate(FALSE);

		}
		else if(d>100){
			d = 100;
			ds = 5*(((double)d * 0.001)-0.05);  //���������� �̵�
			pView->projimgscale=ds;//Dark Stormy�� �̹��� ������ �ٲ���
			pView->Invalidate(FALSE);
	
		}
	
	}
}


void CImageEditDlg::OnEnUpdateoceanImageScaleValue()
{
	// TODO:  RICHEDIT ��Ʈ���� ���, �� ��Ʈ����
	// CDialogEx::OnInitDialog() �Լ��� ������ 
	//�Ͽ�, IParam ����ũ�� OR �����Ͽ� ������ ENM_SCROLL �÷��׸� �����Ͽ� ��Ʈ�ѿ� EM_SETEVENTMASK �޽����� ������ ������
	// ���� ��Ʈ���� �ٲ� �ؽ�Ʈ�� ǥ���Ϸ��� ���� ��Ÿ���ϴ�.

	// TODO:  ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	CMainFrame* pFrame = (CMainFrame*)AfxGetMainWnd();            //Viewȣ��
	CMakoryView* pView = (CMakoryView*)pFrame->GetActiveView();      //Viewȣ��

	if(UpdateData(TRUE)){
		int d;
		double ds;
		CString String;

		moceanImageScaleValue.GetWindowTextA(String);
		d = _ttoi(String)+50;
		moceanImageScaleSlider.SetPos(d);

		
		if (d<0){
			d = 0;
			ds =(-0.5+((double)d * 0.01));  //�������� �̵� //�������� �̵�   
			pView->Ocean.oceanimgscale=ds;//Dark Stormy�� �̹��� ������ �ٲ���
			pView->Invalidate(FALSE);;
		}

		else if(d<=100){

			if(d <= 50){ //�����̴��� 50�����϶�
				ds =(-0.5+((double)d * 0.01));  //�������� �̵� 
			} 
			else if(d >= 50){  //�����̴��� 50�̻��϶�
				ds = 2*((-0.5+((double)d * 0.01))); //���������� �̵�
			}

			pView->Ocean.oceanimgscale=ds;//Dark Stormy�� �̹��� ������ �ٲ���
			pView->Invalidate(FALSE);
	

		}
		else if(d>100){
			d = 100;
			ds = 2*((-0.5+((double)d * 0.01))); //���������� �̵�
			pView->Ocean.oceanimgscale=ds;//Dark Stormy�� �̹��� ������ �ٲ���
			pView->Invalidate(FALSE);
	
		}
	}
}

void CImageEditDlg::OnEnUpdatefishingImageScaleValue()
{
	// TODO:  RICHEDIT ��Ʈ���� ���, �� ��Ʈ����
	// CDialogEx::OnInitDialog() �Լ��� ������ 
	//�Ͽ�, IParam ����ũ�� OR �����Ͽ� ������ ENM_SCROLL �÷��׸� �����Ͽ� ��Ʈ�ѿ� EM_SETEVENTMASK �޽����� ������ ������
	// ���� ��Ʈ���� �ٲ� �ؽ�Ʈ�� ǥ���Ϸ��� ���� ��Ÿ���ϴ�.

	// TODO:  ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	CMainFrame* pFrame = (CMainFrame*)AfxGetMainWnd();            //Viewȣ��
	CMakoryView* pView = (CMakoryView*)pFrame->GetActiveView();      //Viewȣ��


		if(UpdateData(TRUE)){
		int d;
		double ds;
		CString String;

		mfishingImageScaleValue.GetWindowTextA(String);
		d = _ttoi(String)+50;
		mfishingImageScaleSlider.SetPos(d);
				
		if (d<0){
			d = 0;
			ds =2*((((double)d * 0.001)-0.05));   //�������� �̵� /
				pView->Ocean.fishingimgscale=ds;//Dark Stormy�� �̹��� ������ �ٲ���
			pView->Invalidate(FALSE);
		}
		else if(d<=100){

			if(d <= 50){ //�����̴��� 50�����϶�
				ds =2*((-0.005+((double)d * 0.0001)));   //�������� �̵� 
			} 
			else if(d >= 50){  //�����̴��� 50�̻��϶�
				ds = 3*((((double)d * 0.001)-0.05));  //���������� �̵�
			}

			pView->Ocean.fishingimgscale=ds;//Dark Stormy�� �̹��� ������ �ٲ���
			pView->Invalidate(FALSE);
	

		}
		else if(d>100){
			d = 100;
			ds = 5*((((double)d * 0.001)-0.05));  //���������� �̵�
			pView->Ocean.fishingimgscale=ds;//Dark Stormy�� �̹��� ������ �ٲ���
			pView->Invalidate(FALSE);
	
		}

	}
}

void CImageEditDlg::OnEnUpdatewaveImageScaleValue()
{
	// TODO:  RICHEDIT ��Ʈ���� ���, �� ��Ʈ����
	CMainFrame* pFrame = (CMainFrame*)AfxGetMainWnd();            //Viewȣ��
	CMakoryView* pView = (CMakoryView*)pFrame->GetActiveView();      //Viewȣ��

	if(UpdateData(TRUE)){
		int d;
		double ds;
		CString String;

		mwaveImageScaleValue.GetWindowTextA(String);
		d = _ttoi(String)+50;
		mwaveImageScaleSlider.SetPos(d);
		if (d<0){
			d = 0;
			ds =(-0.5+((double)d * 0.01));  //�������� �̵� 
			pView->Ocean.waveimgscale=ds;//Dark Stormy�� �̹��� ������ �ٲ���
			pView->Invalidate(FALSE);
		}

		if(d<=100){

			if(d <= 50){ //�����̴��� 50�����϶�
				ds =(-0.5+((double)d * 0.01));  //�������� �̵� 
			} 
			else if(d >= 50){  //�����̴��� 50�̻��϶�
				ds = (-0.5+((double)d * 0.01)); //���������� �̵�
			}

			pView->Ocean.waveimgscale=ds;//Dark Stormy�� �̹��� ������ �ٲ���
			pView->Invalidate(FALSE);
	

		}
		else if(d>100){
			d = 100;
			ds = (-0.5+((double)d * 0.01)); //���������� �̵�
			pView->Ocean.waveimgscale=ds;//Dark Stormy�� �̹��� ������ �ٲ���
			pView->Invalidate(FALSE);
	
		}
	}
}
