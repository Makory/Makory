// EdittapCtrl.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "Makory.h"
#include "FishingDlg.h"
#include "afxdialogex.h"
#include "Ocean.h"
#include "MainFrm.h"
#include "MakoryDoc.h"
#include "MakoryView.h"


IMPLEMENT_DYNAMIC(CFishingDlg, CDialogEx)

	CFishingDlg::CFishingDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CFishingDlg::IDD, pParent)
{

}

CFishingDlg::~CFishingDlg()
{
}

void CFishingDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_BOAT_RED_SLIDER, mBoatRedS);
	DDX_Control(pDX, IDC_BOAT_GREEN_SLIDER, mBoatGreenS);
	DDX_Control(pDX, IDC_BOAT_BLUE_SLIDER, mBoatBlueS);

	DDX_Control(pDX, IDC_FISHIHG_RED_SLIDER, mFishingRedS);
	DDX_Control(pDX, IDC_FISHIHG_GREEN_SLIDER, mFishingGreenS);
	DDX_Control(pDX, IDC_FISHIHG_BLUE_SLIDER, mFishingBlueS);

	DDX_Control(pDX, IDC_BOAT_RED_VALUE, mBoatRedValue);
	DDX_Control(pDX, IDC_BOAT_GREEN_VALUE, mBoatGreenValue);
	DDX_Control(pDX, IDC_BOAT_BLUE_VALUE, mBoatBlueValue);

	DDX_Control(pDX, IDC_FISHIHG_RED_VALUE, mFishingRedValue);
	DDX_Control(pDX, IDC_FISHIHG_GREEN_VALUE, mFishingGreenValue);
	DDX_Control(pDX, IDC_FISHIHG_BLUE_VALUE, mFishingBlueValue);

	DDX_Control(pDX, IDC_FISHIHGPOLE_RED_SLIDER, mFishingPRedS);
	DDX_Control(pDX, IDC_FISHIHGPOLE_GREEN_SLIDER, mFishingPGreenS);
	DDX_Control(pDX, IDC_FISHIHGPOLE_BLUE_SLIDER, mFishingPBlueS);

	DDX_Control(pDX, IDC_FISHIHGPOLE_RED_VALUE, mFishingPRedValue);
	DDX_Control(pDX, IDC_FISHIHGPOLE_GREEN_VALUE, mFishingPGreenValue);
	DDX_Control(pDX, IDC_FISHIHGPOLE_BLUE_VALUE, mFishingPBlueValue);

	DDX_Control(pDX, IDC_LBOAT_RED_SLIDER, mLBoatRedS);
	DDX_Control(pDX, IDC_LBOAT_GREEN_SLIDER, mLBoatGreenS);
	DDX_Control(pDX, IDC_LBOAT_BLUE_SLIDER, mLBoatBlueS);

	DDX_Control(pDX, IDC_LBOAT_RED_VALUE, mLBoatRedValue);
	DDX_Control(pDX, IDC_LBOAT_GREEN_VALUE, mLBoatGreenValue);
	DDX_Control(pDX, IDC_LBOAT_BLUE_VALUE, mLBoatBlueValue);
	DDX_Control(pDX, IDC_RBOAT_RED_SLIDER, mRBoatRedS);
	DDX_Control(pDX, IDC_RBOAT_GREEN_SLIDER, mRBoatGreenS);
	DDX_Control(pDX, IDC_RBOAT_BLUE_SLIDER, mRBoatBlueS);
	DDX_Control(pDX, IDC_RBOAT_RED_VALUE, mRBoatRedValue);
	DDX_Control(pDX, IDC_RBOAT_GREEN_VALUE2, mRBoatGreenValue);
	DDX_Control(pDX, IDC_RBOAT_BLUE_VALUE2, mRBoatBlueValue);
	DDX_Control(pDX, IDC_FISHING_COMBO, mFishingCombo);

	DDX_Control(pDX, IDC_FISHING_VSCROLL, mFishingVSlider);
	DDX_Control(pDX, IDC_FISHING_HSCROOL, mFishingHSlider);
	DDX_Control(pDX, IDC_FISHING_SCALE_SLIDER, mFishingScaleS);
	DDX_Control(pDX, IDC_FISHING_SCALE_VALUE, mFishingScaleEdit);
	DDX_Control(pDX, IDC_FISHING_V_VALUE, mFishingVEdit);
	DDX_Control(pDX, IDC_FISHING_H_VALUE, mFishingHEdit);
}


BEGIN_MESSAGE_MAP(CFishingDlg, CDialogEx)
	ON_WM_HSCROLL()

	ON_EN_UPDATE(IDC_BOAT_RED_VALUE, &CFishingDlg::OnEnUpdateBoatRedValue)
	ON_EN_UPDATE(IDC_BOAT_GREEN_VALUE, &CFishingDlg::OnEnUpdateBoatGreenValue)
	ON_EN_UPDATE(IDC_BOAT_BLUE_VALUE, &CFishingDlg::OnEnUpdateBoatBlueValue)

	ON_EN_UPDATE(IDC_LBOAT_RED_VALUE, &CFishingDlg::OnEnUpdateLBoatRedValue)
	ON_EN_UPDATE(IDC_LBOAT_GREEN_VALUE, &CFishingDlg::OnEnUpdateLBoatGreenValue)
	ON_EN_UPDATE(IDC_LBOAT_BLUE_VALUE, &CFishingDlg::OnEnUpdateLBoatBlueValue)

	ON_EN_UPDATE(IDC_RBOAT_RED_VALUE, &CFishingDlg::OnEnUpdateRBoatRedValue)
	ON_EN_UPDATE(IDC_RBOAT_GREEN_VALUE2, &CFishingDlg::OnEnUpdateRBoatGreenValue)
	ON_EN_UPDATE(IDC_RBOAT_BLUE_VALUE2, &CFishingDlg::OnEnUpdateRBoatBlueValue)

	ON_EN_UPDATE(IDC_FISHING_RED_VALUE, &CFishingDlg::OnEnUpdateFishingRedValue)
	ON_EN_UPDATE(IDC_FISHING_GREEN_VALUE, &CFishingDlg::OnEnUpdateFishingGreenValue)
	ON_EN_UPDATE(IDC_FISHING_BLUE_VALUE, &CFishingDlg::OnEnUpdateFishingBlueValue)

	ON_EN_UPDATE(IDC_FISHIHGPOLE_RED_VALUE, &CFishingDlg::OnEnUpdateFishingPRedValue)
	ON_EN_UPDATE(IDC_FISHIHGPOLE_GREEN_VALUE, &CFishingDlg::OnEnUpdateFishingPGreenValue)
	ON_EN_UPDATE(IDC_FISHIHGPOLE_BLUE_VALUE, &CFishingDlg::OnEnUpdateFishingPBlueValue)

	ON_EN_UPDATE(IDC_FISHING_V_VALUE, &CFishingDlg::OnEnUpdateFishingVEdit)
	ON_EN_UPDATE(IDC_FISHING_H_VALUE, &CFishingDlg::OnEnUpdateFishingHEdit)
	ON_EN_UPDATE(IDC_FISHING_SCALE_VALUE, &CFishingDlg::OnEnUpdateFishingScaleEdit)


	ON_CBN_SELCHANGE(IDC_FISHING_COMBO, &CFishingDlg::OnCbnSelchangeOceanCombo)
END_MESSAGE_MAP()


// CFishDlg 메시지 처리기입니다.

BOOL CFishingDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.

	mBoatRedS.ShowWindow(SW_HIDE);
	mBoatGreenS.ShowWindow(SW_HIDE);
	mBoatBlueS.ShowWindow(SW_HIDE);

	mBoatRedValue.ShowWindow(SW_HIDE);
	mBoatGreenValue.ShowWindow(SW_HIDE);
	mBoatBlueValue.ShowWindow(SW_HIDE);

	mFishingRedS.ShowWindow(SW_HIDE);
	mFishingGreenS.ShowWindow(SW_HIDE);
	mFishingBlueS.ShowWindow(SW_HIDE);

	mFishingRedValue.ShowWindow(SW_HIDE);
	mFishingGreenValue.ShowWindow(SW_HIDE);
	mFishingBlueValue.ShowWindow(SW_HIDE);

	mFishingPRedS.ShowWindow(SW_SHOW);
	mFishingPGreenS.ShowWindow(SW_SHOW);
	mFishingPBlueS.ShowWindow(SW_SHOW);

	mFishingPRedValue.ShowWindow(SW_SHOW);
	mFishingPGreenValue.ShowWindow(SW_SHOW);
	mFishingPBlueValue.ShowWindow(SW_SHOW);

	mLBoatRedS.ShowWindow(SW_HIDE);
	mLBoatGreenS.ShowWindow(SW_HIDE);
	mLBoatBlueS.ShowWindow(SW_HIDE);

	mLBoatGreenValue.ShowWindow(SW_HIDE);
	mLBoatBlueValue.ShowWindow(SW_HIDE);
	mLBoatRedValue.ShowWindow(SW_HIDE);

	mRBoatRedS.ShowWindow(SW_HIDE);
	mRBoatGreenS.ShowWindow(SW_HIDE);
	mRBoatBlueS.ShowWindow(SW_HIDE);

	mRBoatRedValue.ShowWindow(SW_HIDE);
	mRBoatGreenValue.ShowWindow(SW_HIDE);
	mRBoatBlueValue.ShowWindow(SW_HIDE);

	mFishingCombo.AddString("보트");
	mFishingCombo.AddString("왼쪽돛");
	mFishingCombo.AddString("오른쪽돛");
	mFishingCombo.AddString("낚시대");
	mFishingCombo.AddString("낚시줄");
	mFishingCombo.SetCurSel(0); //콤보박스 기본 설정 


	//red 슬라이더
	mBoatRedS.SetPos(0);//슬라이더 처음 위치
	mBoatRedS.SetRange(0, 255); //슬라이더 범위 0 ~ 100으로 함.
	mBoatRedS.SetPageSize(10); //슬라이더를 클릭했을 때 움직이는 범위. 
	mBoatRedValue.SetWindowTextA("0");//red edit박스 초기값

	//green 슬라이더
	mBoatGreenS.SetPos(255);//슬라이더 처음 위치
	mBoatGreenS.SetRange(0, 255); //슬라이더 범위 0 ~ 100으로 함.
	mBoatGreenS.SetPageSize(10);  //슬라이더를 클릭했을 때 움직이는 범위
	mBoatGreenValue.SetWindowTextA("0");//green edit박스 초기값

	//blue 슬라이더
	mBoatBlueS.SetPos(255);//슬라이더 처음 위치
	mBoatBlueS.SetRange(0, 255); //슬라이더 범위 0 ~ 100으로 함.
	mBoatBlueS.SetPageSize(10);  //슬라이더를 클릭했을 때 움직이는 범위
	mBoatBlueValue.SetWindowTextA("255");//blue edit박스 초기값

	//왼쪽 돛

	mLBoatRedS.SetPos(0);//슬라이더 처음 위치
	mLBoatRedS.SetRange(0, 255); //슬라이더 범위 0 ~ 100으로 함.
	mLBoatRedS.SetPageSize(10); //슬라이더를 클릭했을 때 움직이는 범위. 
	mLBoatRedValue.SetWindowTextA("0");//red edit박스 초기값

	//green 슬라이더
	mLBoatGreenS.SetPos(127);//슬라이더 처음 위치
	mLBoatGreenS.SetRange(0, 255); //슬라이더 범위 0 ~ 100으로 함.
	mLBoatGreenS.SetPageSize(10);  //슬라이더를 클릭했을 때 움직이는 범위
	mLBoatGreenValue.SetWindowTextA("127");//green edit박스 초기값

	//blue 슬라이더
	mLBoatBlueS.SetPos(255);//슬라이더 처음 위치
	mLBoatBlueS.SetRange(0, 255); //슬라이더 범위 0 ~ 100으로 함.
	mLBoatBlueS.SetPageSize(10);  //슬라이더를 클릭했을 때 움직이는 범위
	mLBoatBlueValue.SetWindowTextA("255");//blue edit박스 초기값

	//오른쪽 돛
	mRBoatRedS.SetPos(127);//슬라이더 처음 위치
	mRBoatRedS.SetRange(0, 255); //슬라이더 범위 0 ~ 100으로 함.
	mRBoatRedS.SetPageSize(10); //슬라이더를 클릭했을 때 움직이는 범위. 
	mRBoatRedValue.SetWindowTextA("127");//red edit박스 초기값

	//green 슬라이더
	mRBoatGreenS.SetPos(255);//슬라이더 처음 위치
	mRBoatGreenS.SetRange(0, 255); //슬라이더 범위 0 ~ 100으로 함.
	mRBoatGreenS.SetPageSize(10);  //슬라이더를 클릭했을 때 움직이는 범위
	mRBoatGreenValue.SetWindowTextA("255");//green edit박스 초기값

	//blue 슬라이더
	mRBoatBlueS.SetPos(255);//슬라이더 처음 위치
	mRBoatBlueS.SetRange(0, 255); //슬라이더 범위 0 ~ 100으로 함.
	mRBoatBlueS.SetPageSize(10);  //슬라이더를 클릭했을 때 움직이는 범위
	mRBoatBlueValue.SetWindowTextA("255");//blue edit박스 초기값

	//낚시대
	mFishingPRedS.SetPos(0);//슬라이더 처음 위치
	mFishingPRedS.SetRange(0, 255); //슬라이더 범위 0 ~ 100으로 함.
	mFishingPRedS.SetPageSize(10); //슬라이더를 클릭했을 때 움직이는 범위. 
	mFishingPRedValue.SetWindowTextA("0");//red edit박스 초기값

	//green 슬라이더
	mFishingPGreenS.SetPos(255);//슬라이더 처음 위치
	mFishingPGreenS.SetRange(0, 255); //슬라이더 범위 0 ~ 100으로 함.
	mFishingPGreenS.SetPageSize(10);  //슬라이더를 클릭했을 때 움직이는 범위
	mFishingPGreenValue.SetWindowTextA("255");//green edit박스 초기값

	//blue 슬라이더
	mFishingPBlueS.SetPos(0);//슬라이더 처음 위치
	mFishingPBlueS.SetRange(0, 255); //슬라이더 범위 0 ~ 100으로 함.
	mFishingPBlueS.SetPageSize(10);  //슬라이더를 클릭했을 때 움직이는 범위
	mFishingPBlueValue.SetWindowTextA("0");//blue edit박스 초기값

	//낚시줄
	mFishingRedS.SetPos(255);//슬라이더 처음 위치
	mFishingRedS.SetRange(0, 255); //슬라이더 범위 0 ~ 100으로 함.
	mFishingRedS.SetPageSize(10); //슬라이더를 클릭했을 때 움직이는 범위. 
	mFishingRedValue.SetWindowTextA("255");//red edit박스 초기값

	//green 슬라이더
	mFishingGreenS.SetPos(255);//슬라이더 처음 위치
	mFishingGreenS.SetRange(0, 255); //슬라이더 범위 0 ~ 100으로 함.
	mFishingGreenS.SetPageSize(10);  //슬라이더를 클릭했을 때 움직이는 범위
	mFishingGreenValue.SetWindowTextA("255");//green edit박스 초기값

	//blue 슬라이더
	mFishingBlueS.SetPos(255);//슬라이더 처음 위치
	mFishingBlueS.SetRange(0, 255); //슬라이더 범위 0 ~ 100으로 함.
	mFishingBlueS.SetPageSize(10);  //슬라이더를 클릭했을 때 움직이는 범위
	mFishingBlueValue.SetWindowTextA("255");//blue edit박스 초기값


	//수직슬라이더
	mFishingVSlider.SetPos(50);//슬라이더 처음 위치
	mFishingVSlider.SetRange(0, 100); //슬라이더 범위 0 ~ 100으로 함.
	mFishingVSlider.SetPageSize(1);  //슬라이더를 클릭했을 때 움직이는 범위
	mFishingVEdit.SetWindowTextA("0");//v edit박스 초기값

	//수평슬라이더
	mFishingHSlider.SetPos(50);//슬라이더 처음 위치
	mFishingHSlider.SetRange(0, 100); //슬라이더 범위 0 ~ 100으로 함.
	mFishingHSlider.SetPageSize(1);  //슬라이더를 클릭했을 때 움직이는 범위
	mFishingHEdit.SetWindowTextA("0");//h edit박스 초기값

	//크기
	mFishingScaleS.SetPos(50);//슬라이더 처음 위치
	mFishingScaleS.SetRange(0, 100); //슬라이더 범위 0 ~ 100으로 함.
	mFishingScaleS.SetPageSize(1);  //슬라이더를 클릭했을 때 움직이는 범위
	mFishingScaleEdit.SetWindowTextA("0");//h edit박스 초기값  

	return TRUE;  // return TRUE unless you set the focus to a control
	// 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}


//슬라이더 움직였을 때
void CFishingDlg::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	CMainFrame* pFrame = (CMainFrame*)AfxGetMainWnd();				//View호출
	CMakoryView* pView = (CMakoryView*)pFrame->GetActiveView();		//View호출

	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	if(pScrollBar)
	{
		// 어떤 슬라이더인지 검사
		//red slider가 움직였을 경우
		if(pScrollBar == (CScrollBar*)&mBoatRedS)//Fish red slider인경우
		{

			// 슬라이더의 위치를 검사한다.
			int npos = mBoatRedS.GetPos(); //슬라이더 위치 얻어옴
			CString str;
			str.Format(_T("%d"), npos); //형변환
			mBoatRedValue.SetWindowTextA(str); //edit 박스에 슬라이더 값 들어감

			fpos = (double)npos * 0.00392156; //슬라이더는 소숫점이 사용이 안됨

			pView->Ocean.boatred=fpos;//풍선 빨간색값을 바꿔줌
			pView->Invalidate(FALSE);
		}

		//green슬라이더 움직였을 경우
		else if(pScrollBar == (CScrollBar*)&mBoatGreenS)//Fish red slider인경우
		{

			// 슬라이더의 위치를 검사한다.
			int npos = mBoatGreenS.GetPos(); //슬라이더 위치 얻어옴
			CString str;
			str.Format(_T("%d"), npos); //형변환
			mBoatGreenValue.SetWindowTextA(str); //edit 박스에 슬라이더 값 들어감

			fpos = (double)npos * 0.00392156; //슬라이더는 소숫점이 사용이 안됨

			pView->Ocean.boatgreen=fpos;//풍선 빨간색값을 바꿔줌
			pView->Invalidate(FALSE);
		}


		//blue 슬라이더 움직였을 경우
		else if(pScrollBar == (CScrollBar*)&mBoatBlueS)//Fish green slider인경우
		{

			// 슬라이더의 위치를 검사한다.
			int npos = mBoatBlueS.GetPos(); //슬라이더 위치 얻어옴
			CString str;
			str.Format(_T("%d"), npos); //형변환
			mBoatBlueValue.SetWindowTextA(str);// edit 박스에 슬라이더 값 들어감

			fpos = (double)npos * 0.00392156; //슬라이더는 소숫점이 사용이 안됨

			pView->Ocean.boatblue=fpos; //풍선 녹색값을 바꿔줌
			pView->Invalidate(FALSE);
		}

		//왼쪽 돛
		if(pScrollBar == (CScrollBar*)&mLBoatRedS)//Fish red slider인경우
		{

			// 슬라이더의 위치를 검사한다.
			int npos = mLBoatRedS.GetPos(); //슬라이더 위치 얻어옴
			CString str;
			str.Format(_T("%d"), npos); //형변환
			mLBoatRedValue.SetWindowTextA(str); //edit 박스에 슬라이더 값 들어감

			fpos = (double)npos * 0.00392156; //슬라이더는 소숫점이 사용이 안됨

			pView->Ocean.lboatred=fpos;//풍선 빨간색값을 바꿔줌
			pView->Invalidate(FALSE);
		}

		//green슬라이더 움직였을 경우
		else if(pScrollBar == (CScrollBar*)&mLBoatGreenS)//Fish red slider인경우
		{

			// 슬라이더의 위치를 검사한다.
			int npos = mLBoatGreenS.GetPos(); //슬라이더 위치 얻어옴
			CString str;
			str.Format(_T("%d"), npos); //형변환
			mLBoatGreenValue.SetWindowTextA(str); //edit 박스에 슬라이더 값 들어감

			fpos = (double)npos * 0.00392156; //슬라이더는 소숫점이 사용이 안됨

			pView->Ocean.lboatgreen=fpos;//풍선 빨간색값을 바꿔줌
			pView->Invalidate(FALSE);
		}


		//blue 슬라이더 움직였을 경우
		else if(pScrollBar == (CScrollBar*)&mLBoatBlueS)//Fish green slider인경우
		{

			// 슬라이더의 위치를 검사한다.
			int npos = mLBoatBlueS.GetPos(); //슬라이더 위치 얻어옴
			CString str;
			str.Format(_T("%d"), npos); //형변환
			mLBoatBlueValue.SetWindowTextA(str);// edit 박스에 슬라이더 값 들어감

			fpos = (double)npos * 0.00392156; //슬라이더는 소숫점이 사용이 안됨

			pView->Ocean.lboatblue=fpos; //풍선 녹색값을 바꿔줌
			pView->Invalidate(FALSE);
		}

		//왼쪽 돛
		if(pScrollBar == (CScrollBar*)&mRBoatRedS)//Fish red slider인경우
		{

			// 슬라이더의 위치를 검사한다.
			int npos = mRBoatRedS.GetPos(); //슬라이더 위치 얻어옴
			CString str;
			str.Format(_T("%d"), npos); //형변환
			mRBoatRedValue.SetWindowTextA(str); //edit 박스에 슬라이더 값 들어감

			fpos = (double)npos * 0.00392156; //슬라이더는 소숫점이 사용이 안됨

			pView->Ocean.rboatred=fpos;//풍선 빨간색값을 바꿔줌
			pView->Invalidate(FALSE);
		}

		//green슬라이더 움직였을 경우
		else if(pScrollBar == (CScrollBar*)&mRBoatGreenS)//Fish red slider인경우
		{

			// 슬라이더의 위치를 검사한다.
			int npos = mRBoatGreenS.GetPos(); //슬라이더 위치 얻어옴
			CString str;
			str.Format(_T("%d"), npos); //형변환
			mRBoatGreenValue.SetWindowTextA(str); //edit 박스에 슬라이더 값 들어감

			fpos = (double)npos * 0.00392156; //슬라이더는 소숫점이 사용이 안됨

			pView->Ocean.rboatgreen=fpos;//풍선 빨간색값을 바꿔줌
			pView->Invalidate(FALSE);
		}


		//blue 슬라이더 움직였을 경우
		else if(pScrollBar == (CScrollBar*)&mRBoatBlueS)//Fish green slider인경우
		{

			// 슬라이더의 위치를 검사한다.
			int npos = mRBoatBlueS.GetPos(); //슬라이더 위치 얻어옴
			CString str;
			str.Format(_T("%d"), npos); //형변환
			mRBoatBlueValue.SetWindowTextA(str);// edit 박스에 슬라이더 값 들어감

			fpos = (double)npos * 0.00392156; //슬라이더는 소숫점이 사용이 안됨

			pView->Ocean.rboatblue=fpos; //풍선 녹색값을 바꿔줌
			pView->Invalidate(FALSE);
		}

		//낚시대
		//red slider가 움직였을 경우
		if(pScrollBar == (CScrollBar*)&mFishingPRedS)//Fish red slider인경우
		{

			// 슬라이더의 위치를 검사한다.
			int npos = mFishingPRedS.GetPos(); //슬라이더 위치 얻어옴
			CString str;
			str.Format(_T("%d"), npos); //형변환
			mFishingPRedValue.SetWindowTextA(str); //edit 박스에 슬라이더 값 들어감

			fpos = (double)npos * 0.00392156; //슬라이더는 소숫점이 사용이 안됨

			pView->Ocean.fishingpred=fpos;//풍선 빨간색값을 바꿔줌
			pView->Invalidate(FALSE);
		}

		//green슬라이더 움직였을 경우
		else if(pScrollBar == (CScrollBar*)&mFishingPGreenS)//Fish red slider인경우
		{

			// 슬라이더의 위치를 검사한다.
			int npos = mFishingPGreenS.GetPos(); //슬라이더 위치 얻어옴
			CString str;
			str.Format(_T("%d"), npos); //형변환
			mFishingPGreenValue.SetWindowTextA(str); //edit 박스에 슬라이더 값 들어감

			fpos = (double)npos * 0.00392156; //슬라이더는 소숫점이 사용이 안됨

			pView->Ocean.fishingpgreen=fpos;//풍선 빨간색값을 바꿔줌
			pView->Invalidate(FALSE);
		}


		//blue 슬라이더 움직였을 경우
		else if(pScrollBar == (CScrollBar*)&mFishingPBlueS)//Fish green slider인경우
		{

			// 슬라이더의 위치를 검사한다.
			int npos = mFishingPBlueS.GetPos(); //슬라이더 위치 얻어옴
			CString str;
			str.Format(_T("%d"), npos); //형변환
			mFishingPBlueValue.SetWindowTextA(str);// edit 박스에 슬라이더 값 들어감

			fpos = (double)npos * 0.00392156; //슬라이더는 소숫점이 사용이 안됨

			pView->Ocean.fishingpblue=fpos; //풍선 녹색값을 바꿔줌
			pView->Invalidate(FALSE);
		}

		//낚시줄

		//red slider가 움직였을 경우
		if(pScrollBar == (CScrollBar*)&mFishingRedS)//Fish red slider인경우
		{

			// 슬라이더의 위치를 검사한다.
			int npos = mFishingRedS.GetPos(); //슬라이더 위치 얻어옴
			CString str;
			str.Format(_T("%d"), npos); //형변환
			mFishingRedValue.SetWindowTextA(str); //edit 박스에 슬라이더 값 들어감

			fpos = (double)npos * 0.00392156; //슬라이더는 소숫점이 사용이 안됨

			pView->Ocean.fishingred=fpos;//풍선 빨간색값을 바꿔줌
			pView->Invalidate(FALSE);
		}

		//green슬라이더 움직였을 경우
		else if(pScrollBar == (CScrollBar*)&mFishingGreenS)//Fish red slider인경우
		{

			// 슬라이더의 위치를 검사한다.
			int npos = mFishingGreenS.GetPos(); //슬라이더 위치 얻어옴
			CString str;
			str.Format(_T("%d"), npos); //형변환
			mFishingGreenValue.SetWindowTextA(str); //edit 박스에 슬라이더 값 들어감

			fpos = (double)npos * 0.00392156; //슬라이더는 소숫점이 사용이 안됨

			pView->Ocean.fishinggreen=fpos;//풍선 빨간색값을 바꿔줌
			pView->Invalidate(FALSE);
		}


		//blue 슬라이더 움직였을 경우
		else if(pScrollBar == (CScrollBar*)&mFishingBlueS)//Fish green slider인경우
		{

			// 슬라이더의 위치를 검사한다.
			int npos = mFishingBlueS.GetPos(); //슬라이더 위치 얻어옴
			CString str;
			str.Format(_T("%d"), npos); //형변환
			mFishingBlueValue.SetWindowTextA(str);// edit 박스에 슬라이더 값 들어감

			fpos = (double)npos * 0.00392156; //슬라이더는 소숫점이 사용이 안됨

			pView->Ocean.fishingblue=fpos; //풍선 녹색값을 바꿔줌
			pView->Invalidate(FALSE);
		}


		//크기 슬라이더 움직였을 경우
		else if(pScrollBar == (CScrollBar*)&mFishingScaleS)//수직 슬라이더인경우
		{
			// 슬라이더의 위치를 검사한다.
			int npos = mFishingScaleS.GetPos(); //슬라이더 위치 얻어옴
			CString str;
			str.Format(_T("%d"), npos-50); //형변환
			mFishingScaleEdit.SetWindowTextA(str); //edit 박스에 슬라이더 값 들어감

			if(npos <= 50){ //슬라이더가 50이하일때
				fpos = 2*(-0.5+((double)npos * 0.01)); //왼쪽으로 이동 
			} 
			else if(npos >= 50){  //슬라이더가 50이상일때
				fpos = 5*(((double)npos * 0.01)-0.5); //오른쪽으로 이동
			}

			pView->Ocean.FishingVessel=2.5+fpos; //filmscale값을 바꿔줌

			pView->Ocean.fishingscale=fpos;
			pView->Invalidate(FALSE);
		}
		//수직 슬라이더 움직였을 경우
		else if(pScrollBar == (CScrollBar*)&mFishingVSlider)//수직 슬라이더인경우
		{

			// 슬라이더의 위치를 검사한다.
			int npos = mFishingVSlider.GetPos(); //슬라이더 위치 얻어옴
			CString str;
			str.Format(_T("%d"), npos-50); //형변환
			mFishingVEdit.SetWindowTextA(str); //edit 박스에 슬라이더 값 들어감


			if(npos <= 50){ //슬라이더가 50이하일때
				fpos = -0.5+((double)npos * 0.01); //왼쪽으로 이동 
			} 
			else if(npos >= 50){  //슬라이더가 50이상일때
				fpos = ((double)npos * 0.01)-0.5; //오른쪽으로 이동
			}

			pView->Ocean.fishingy=fpos; //Fishy값을 바꿔줌

			pView->Invalidate(FALSE);
		}
		//수평 슬라이더 움직였을 경우
		else if(pScrollBar == (CScrollBar*)&mFishingHSlider)//수평 슬라이더인경우
		{

			// 슬라이더의 위치를 검사한다.
			int npos = mFishingHSlider.GetPos(); //슬라이더 위치 얻어옴

			CString str;
			str.Format(_T("%d"), npos-50); //형변환
			mFishingHEdit.SetWindowTextA(str); //edit 박스에 슬라이더 값 들어감

			if(npos <= 50){ //슬라이더가 50이하일때
				fpos = 3*(-0.05+((double)npos * 0.001)); //왼쪽으로 이동 
			} 
			else if(npos >= 50){  //슬라이더가 50이상일때
				fpos = 3*(((double)npos * 0.01)-0.5); //오른쪽으로 이동
			}

			pView->Ocean.fishingx=fpos; //Fishx값을 바꿔줌
			pView->Invalidate(FALSE);
		}


	}

	else
	{
		// CScrollView를 상속받은 뷰의 경우 프래임의 스크롤롤 동작시 pScrollBar이 NULL된다.
	}
	CDialogEx::OnHScroll(nSBCode, nPos, pScrollBar);
}

//보트
//RED edit
void CFishingDlg::OnEnUpdateBoatRedValue()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CDialogEx::OnInitDialog() 함수를 재지정 
	//하여, IParam 마스크에 OR 연산하여 설정된 ENM_SCROLL 플래그를 지정하여 컨트롤에 EM_SETEVENTMASK 메시지를 보내지 않으면
	// 편집 컨트롤이 바뀐 텍스트를 표시하려고 함을 나타냅니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CMainFrame* pFrame = (CMainFrame*)AfxGetMainWnd();            //View호출
	CMakoryView* pView = (CMakoryView*)pFrame->GetActiveView();      //View호출

	if(UpdateData(TRUE)){

		int ipos;
		double dpos;
		CString String;

		mBoatRedValue.GetWindowTextA(String);
		ipos = _ttoi(String);
		mBoatRedS.SetPos(ipos);
		dpos = (double)ipos * 0.00392156; //슬라이더는 소숫점이 사용이 안됨

		pView->Ocean.boatred=dpos;//풍선 빨간색값을 바꿔줌
		pView->Invalidate(FALSE);
	}
}

//green edit
void CFishingDlg::OnEnUpdateBoatGreenValue()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CDialogEx::OnInitDialog() 함수를 재지정 
	//하여, IParam 마스크에 OR 연산하여 설정된 ENM_SCROLL 플래그를 지정하여 컨트롤에 EM_SETEVENTMASK 메시지를 보내지 않으면
	// 편집 컨트롤이 바뀐 텍스트를 표시하려고 함을 나타냅니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CMainFrame* pFrame = (CMainFrame*)AfxGetMainWnd();            //View호출
	CMakoryView* pView = (CMakoryView*)pFrame->GetActiveView();      //View호출

	if(UpdateData(TRUE)){

		int ipos;
		double dpos;
		CString String;

		mBoatGreenValue.GetWindowTextA(String);
		ipos = _ttoi(String);
		mBoatGreenS.SetPos(ipos);
		dpos = (double)ipos * 0.00392156; //슬라이더는 소숫점이 사용이 안됨
		pView->Ocean.boatgreen=dpos;//풍선 빨간색값을 바꿔줌

		pView->Invalidate(FALSE);
	}
}

//blue edit
void CFishingDlg::OnEnUpdateBoatBlueValue()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CDialogEx::OnInitDialog() 함수를 재지정 
	//하여, IParam 마스크에 OR 연산하여 설정된 ENM_SCROLL 플래그를 지정하여 컨트롤에 EM_SETEVENTMASK 메시지를 보내지 않으면
	// 편집 컨트롤이 바뀐 텍스트를 표시하려고 함을 나타냅니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CMainFrame* pFrame = (CMainFrame*)AfxGetMainWnd();            //View호출
	CMakoryView* pView = (CMakoryView*)pFrame->GetActiveView();      //View호출

	if(UpdateData(TRUE)){

		int ipos;
		double dpos;
		CString String;

		mBoatBlueValue.GetWindowTextA(String);
		ipos = _ttoi(String);
		mBoatBlueS.SetPos(ipos);
		dpos = (double)ipos * 0.00392156; //슬라이더는 소숫점이 사용이 안됨
		pView->Ocean.boatblue=dpos;//풍선 빨간색값을 바꿔줌

		pView->Invalidate(FALSE);
	}
}
//왼쪽 돛
//RED edit
void CFishingDlg::OnEnUpdateLBoatRedValue()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CDialogEx::OnInitDialog() 함수를 재지정 
	//하여, IParam 마스크에 OR 연산하여 설정된 ENM_SCROLL 플래그를 지정하여 컨트롤에 EM_SETEVENTMASK 메시지를 보내지 않으면
	// 편집 컨트롤이 바뀐 텍스트를 표시하려고 함을 나타냅니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CMainFrame* pFrame = (CMainFrame*)AfxGetMainWnd();            //View호출
	CMakoryView* pView = (CMakoryView*)pFrame->GetActiveView();      //View호출

	if(UpdateData(TRUE)){

		int ipos;
		double dpos;
		CString String;

		mLBoatRedValue.GetWindowTextA(String);
		ipos = _ttoi(String);
		mLBoatRedS.SetPos(ipos);
		dpos = (double)ipos * 0.00392156; //슬라이더는 소숫점이 사용이 안됨

		pView->Ocean.lboatred=dpos;//풍선 빨간색값을 바꿔줌
		pView->Invalidate(FALSE);
	}
}

//green edit
void CFishingDlg::OnEnUpdateLBoatGreenValue()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CDialogEx::OnInitDialog() 함수를 재지정 
	//하여, IParam 마스크에 OR 연산하여 설정된 ENM_SCROLL 플래그를 지정하여 컨트롤에 EM_SETEVENTMASK 메시지를 보내지 않으면
	// 편집 컨트롤이 바뀐 텍스트를 표시하려고 함을 나타냅니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CMainFrame* pFrame = (CMainFrame*)AfxGetMainWnd();            //View호출
	CMakoryView* pView = (CMakoryView*)pFrame->GetActiveView();      //View호출

	if(UpdateData(TRUE)){

		int ipos;
		double dpos;
		CString String;

		mLBoatGreenValue.GetWindowTextA(String);
		ipos = _ttoi(String);
		mLBoatGreenS.SetPos(ipos);
		dpos = (double)ipos * 0.00392156; //슬라이더는 소숫점이 사용이 안됨
		pView->Ocean.lboatgreen=dpos;//풍선 빨간색값을 바꿔줌

		pView->Invalidate(FALSE);
	}
}

//blue edit
void CFishingDlg::OnEnUpdateLBoatBlueValue()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CDialogEx::OnInitDialog() 함수를 재지정 
	//하여, IParam 마스크에 OR 연산하여 설정된 ENM_SCROLL 플래그를 지정하여 컨트롤에 EM_SETEVENTMASK 메시지를 보내지 않으면
	// 편집 컨트롤이 바뀐 텍스트를 표시하려고 함을 나타냅니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CMainFrame* pFrame = (CMainFrame*)AfxGetMainWnd();            //View호출
	CMakoryView* pView = (CMakoryView*)pFrame->GetActiveView();      //View호출

	if(UpdateData(TRUE)){

		int ipos;
		double dpos;
		CString String;

		mLBoatBlueValue.GetWindowTextA(String);
		ipos = _ttoi(String);
		mLBoatBlueS.SetPos(ipos);
		dpos = (double)ipos * 0.00392156; //슬라이더는 소숫점이 사용이 안됨

		pView->Ocean.lboatblue=dpos;//풍선 빨간색값을 바꿔줌
		pView->Invalidate(FALSE);
	}
}

//오른쪽 돛
//RED edit
void CFishingDlg::OnEnUpdateRBoatRedValue()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CDialogEx::OnInitDialog() 함수를 재지정 
	//하여, IParam 마스크에 OR 연산하여 설정된 ENM_SCROLL 플래그를 지정하여 컨트롤에 EM_SETEVENTMASK 메시지를 보내지 않으면
	// 편집 컨트롤이 바뀐 텍스트를 표시하려고 함을 나타냅니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CMainFrame* pFrame = (CMainFrame*)AfxGetMainWnd();            //View호출
	CMakoryView* pView = (CMakoryView*)pFrame->GetActiveView();      //View호출

	if(UpdateData(TRUE)){

		int ipos;
		double dpos;
		CString String;

		mRBoatRedValue.GetWindowTextA(String);
		ipos = _ttoi(String);
		mRBoatRedS.SetPos(ipos);
		dpos = (double)ipos * 0.00392156; //슬라이더는 소숫점이 사용이 안됨

		pView->Ocean.rboatred=dpos;//풍선 빨간색값을 바꿔줌
		pView->Invalidate(FALSE);
	}
}

//green edit
void CFishingDlg::OnEnUpdateRBoatGreenValue()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CDialogEx::OnInitDialog() 함수를 재지정 
	//하여, IParam 마스크에 OR 연산하여 설정된 ENM_SCROLL 플래그를 지정하여 컨트롤에 EM_SETEVENTMASK 메시지를 보내지 않으면
	// 편집 컨트롤이 바뀐 텍스트를 표시하려고 함을 나타냅니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CMainFrame* pFrame = (CMainFrame*)AfxGetMainWnd();            //View호출
	CMakoryView* pView = (CMakoryView*)pFrame->GetActiveView();      //View호출

	if(UpdateData(TRUE)){

		int ipos;
		double dpos;
		CString String;

		mRBoatGreenValue.GetWindowTextA(String);
		ipos = _ttoi(String);
		mRBoatGreenS.SetPos(ipos);
		dpos = (double)ipos * 0.00392156; //슬라이더는 소숫점이 사용이 안됨
		pView->Ocean.rboatgreen=dpos;//풍선 빨간색값을 바꿔줌

		pView->Invalidate(FALSE);
	}
}

//blue edit
void CFishingDlg::OnEnUpdateRBoatBlueValue()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CDialogEx::OnInitDialog() 함수를 재지정 
	//하여, IParam 마스크에 OR 연산하여 설정된 ENM_SCROLL 플래그를 지정하여 컨트롤에 EM_SETEVENTMASK 메시지를 보내지 않으면
	// 편집 컨트롤이 바뀐 텍스트를 표시하려고 함을 나타냅니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CMainFrame* pFrame = (CMainFrame*)AfxGetMainWnd();            //View호출
	CMakoryView* pView = (CMakoryView*)pFrame->GetActiveView();      //View호출

	if(UpdateData(TRUE)){

		int ipos;
		double dpos;
		CString String;

		mRBoatBlueValue.GetWindowTextA(String);
		ipos = _ttoi(String);
		mRBoatBlueS.SetPos(ipos);
		dpos = (double)ipos * 0.00392156; //슬라이더는 소숫점이 사용이 안됨

		pView->Ocean.rboatblue=dpos;//풍선 빨간색값을 바꿔줌
		pView->Invalidate(FALSE);
	}
}

//낚시줄
void CFishingDlg::OnEnUpdateFishingRedValue()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CDialogEx::OnInitDialog() 함수를 재지정 
	//하여, IParam 마스크에 OR 연산하여 설정된 ENM_SCROLL 플래그를 지정하여 컨트롤에 EM_SETEVENTMASK 메시지를 보내지 않으면
	// 편집 컨트롤이 바뀐 텍스트를 표시하려고 함을 나타냅니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CMainFrame* pFrame = (CMainFrame*)AfxGetMainWnd();            //View호출
	CMakoryView* pView = (CMakoryView*)pFrame->GetActiveView();      //View호출

	if(UpdateData(TRUE)){

		int ipos;
		double dpos;
		CString String;

		mFishingRedValue.GetWindowTextA(String);
		ipos = _ttoi(String);
		mFishingRedS.SetPos(ipos);
		dpos = (double)ipos * 0.00392156; //슬라이더는 소숫점이 사용이 안됨

		pView->Ocean.fishingred=dpos;//풍선 빨간색값을 바꿔줌
		pView->Invalidate(FALSE);
	}
}

//green edit
void CFishingDlg::OnEnUpdateFishingGreenValue()
{
	CMainFrame* pFrame = (CMainFrame*)AfxGetMainWnd();            //View호출
	CMakoryView* pView = (CMakoryView*)pFrame->GetActiveView();      //View호출

	if(UpdateData(TRUE)){

		int ipos;
		double dpos;
		CString String;

		mFishingGreenValue.GetWindowTextA(String);
		ipos = _ttoi(String);
		mFishingGreenS.SetPos(ipos);
		dpos = (double)ipos * 0.00392156; //슬라이더는 소숫점이 사용이 안됨
		pView->Ocean.fishinggreen=dpos;//풍선 빨간색값을 바꿔줌

		pView->Invalidate(FALSE);
	}
}

//blue edit
void CFishingDlg::OnEnUpdateFishingBlueValue()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CDialogEx::OnInitDialog() 함수를 재지정 
	//하여, IParam 마스크에 OR 연산하여 설정된 ENM_SCROLL 플래그를 지정하여 컨트롤에 EM_SETEVENTMASK 메시지를 보내지 않으면
	// 편집 컨트롤이 바뀐 텍스트를 표시하려고 함을 나타냅니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CMainFrame* pFrame = (CMainFrame*)AfxGetMainWnd();            //View호출
	CMakoryView* pView = (CMakoryView*)pFrame->GetActiveView();      //View호출

	if(UpdateData(TRUE)){

		int ipos;
		double dpos;
		CString String;

		mFishingBlueValue.GetWindowTextA(String);
		ipos = _ttoi(String);
		mFishingBlueS.SetPos(ipos);
		dpos = (double)ipos * 0.00392156; //슬라이더는 소숫점이 사용이 안됨

		pView->Ocean.fishingblue=dpos;//풍선 빨간색값을 바꿔줌
		pView->Invalidate(FALSE);
	}
}

//낚시대
void CFishingDlg::OnEnUpdateFishingPRedValue()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CDialogEx::OnInitDialog() 함수를 재지정 
	//하여, IParam 마스크에 OR 연산하여 설정된 ENM_SCROLL 플래그를 지정하여 컨트롤에 EM_SETEVENTMASK 메시지를 보내지 않으면
	// 편집 컨트롤이 바뀐 텍스트를 표시하려고 함을 나타냅니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CMainFrame* pFrame = (CMainFrame*)AfxGetMainWnd();            //View호출
	CMakoryView* pView = (CMakoryView*)pFrame->GetActiveView();      //View호출

	if(UpdateData(TRUE)){

		int ipos;
		double dpos;
		CString String;

		mFishingPRedValue.GetWindowTextA(String);
		ipos = _ttoi(String);
		mFishingPRedS.SetPos(ipos);
		dpos = (double)ipos * 0.00392156; //슬라이더는 소숫점이 사용이 안됨

		pView->Ocean.fishingpred=dpos;//풍선 빨간색값을 바꿔줌
		pView->Invalidate(FALSE);
	}
}

//green edit
void CFishingDlg::OnEnUpdateFishingPGreenValue()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CDialogEx::OnInitDialog() 함수를 재지정 
	//하여, IParam 마스크에 OR 연산하여 설정된 ENM_SCROLL 플래그를 지정하여 컨트롤에 EM_SETEVENTMASK 메시지를 보내지 않으면
	// 편집 컨트롤이 바뀐 텍스트를 표시하려고 함을 나타냅니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CMainFrame* pFrame = (CMainFrame*)AfxGetMainWnd();            //View호출
	CMakoryView* pView = (CMakoryView*)pFrame->GetActiveView();      //View호출

	if(UpdateData(TRUE)){

		int ipos;
		double dpos;
		CString String;

		mFishingPGreenValue.GetWindowTextA(String);
		ipos = _ttoi(String);
		mFishingPGreenS.SetPos(ipos);
		dpos = (double)ipos * 0.00392156; //슬라이더는 소숫점이 사용이 안됨
		pView->Ocean.fishingpgreen=dpos;//풍선 빨간색값을 바꿔줌

		pView->Invalidate(FALSE);
	}
}

//blue edit
void CFishingDlg::OnEnUpdateFishingPBlueValue()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CDialogEx::OnInitDialog() 함수를 재지정 
	//하여, IParam 마스크에 OR 연산하여 설정된 ENM_SCROLL 플래그를 지정하여 컨트롤에 EM_SETEVENTMASK 메시지를 보내지 않으면
	// 편집 컨트롤이 바뀐 텍스트를 표시하려고 함을 나타냅니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CMainFrame* pFrame = (CMainFrame*)AfxGetMainWnd();            //View호출
	CMakoryView* pView = (CMakoryView*)pFrame->GetActiveView();      //View호출

	if(UpdateData(TRUE)){

		int ipos;
		double dpos;
		CString String;

		mFishingPBlueValue.GetWindowTextA(String);
		ipos = _ttoi(String);
		mFishingPBlueS.SetPos(ipos);
		dpos = (double)ipos * 0.00392156; //슬라이더는 소숫점이 사용이 안됨

		pView->Ocean.fishingpblue=dpos;//풍선 빨간색값을 바꿔줌
		pView->Invalidate(FALSE);
	}
}


//수평 edit
void CFishingDlg::OnEnUpdateFishingHEdit()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CDialogEx::OnInitDialog() 함수를 재지정 
	//하여, IParam 마스크에 OR 연산하여 설정된 ENM_SCROLL 플래그를 지정하여 컨트롤에 EM_SETEVENTMASK 메시지를 보내지 않으면
	// 편집 컨트롤이 바뀐 텍스트를 표시하려고 함을 나타냅니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CMainFrame* pFrame = (CMainFrame*)AfxGetMainWnd();            //View호출
	CMakoryView* pView = (CMakoryView*)pFrame->GetActiveView();      //View호출

	if(UpdateData(TRUE)){

		int ipos;
		double dpos;
		CString String;

		mFishingHEdit.GetWindowTextA(String);

		ipos = _ttoi(String)+50;
		mFishingHSlider.SetPos(ipos);

		if(ipos <= 50){ //슬라이더가 50이하일때

			dpos = 3*(-0.5+((double)ipos * 0.01)); //왼쪽으로 이동 

		} 
		else if(ipos >= 50){  //슬라이더가 50이상일때
			dpos = 3*(((double)ipos * 0.01)-0.5); //오른쪽으로 이동
		}
		pView->Ocean.fishingx=dpos; //Fishx값을 바꿔줌

		pView->Invalidate(FALSE);
	}

}
//수직 Edit
void CFishingDlg::OnEnUpdateFishingVEdit()
{

	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CDialogEx::OnInitDialog() 함수를 재지정 
	//하여, IParam 마스크에 OR 연산하여 설정된 ENM_SCROLL 플래그를 지정하여 컨트롤에 EM_SETEVENTMASK 메시지를 보내지 않으면
	// 편집 컨트롤이 바뀐 텍스트를 표시하려고 함을 나타냅니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CMainFrame* pFrame = (CMainFrame*)AfxGetMainWnd();            //View호출
	CMakoryView* pView = (CMakoryView*)pFrame->GetActiveView();      //View호출

	if(UpdateData(TRUE)){

		int ipos;
		double dpos;
		CString String;

		mFishingVEdit.GetWindowTextA(String);

		ipos =_ttoi(String)+50;

		mFishingVSlider.SetPos(ipos);

		if(ipos <= 50){ //슬라이더가 50이하일때

			dpos = -0.5+((double)ipos * 0.01); //왼쪽으로 이동 

		} 
		else if(ipos >= 50){  //슬라이더가 50이상일때
			dpos = ((double)ipos * 0.01)-0.5; //오른쪽으로 이동
		}

		pView->Ocean.fishingy=dpos; //Fishy값을 바꿔줌
		pView->Invalidate(FALSE);
	}
}

//크기 edit
void CFishingDlg::OnEnUpdateFishingScaleEdit()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CDialogEx::OnInitDialog() 함수를 재지정 
	//하여, IParam 마스크에 OR 연산하여 설정된 ENM_SCROLL 플래그를 지정하여 컨트롤에 EM_SETEVENTMASK 메시지를 보내지 않으면
	// 편집 컨트롤이 바뀐 텍스트를 표시하려고 함을 나타냅니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CMainFrame* pFrame = (CMainFrame*)AfxGetMainWnd();            //View호출
	CMakoryView* pView = (CMakoryView*)pFrame->GetActiveView();      //View호출

	if(UpdateData(TRUE)){

		int ipos;
		double dpos;
		CString String;

		mFishingScaleEdit.GetWindowTextA(String);

		ipos = _ttoi(String)+50;
		mFishingScaleS.SetPos(ipos);

		if (ipos<0){
			ipos = 0;
			dpos = 2*(-0.5+((double)ipos * 0.01)); //왼쪽으로 이동 
			pView->Ocean.FishingVessel=2.5+dpos; //filmscale값을 바꿔줌
			pView->Ocean.fishingscale=dpos;
			pView->Invalidate(FALSE);
		}
		else if(ipos<100){
			if(ipos <= 50){ //슬라이더가 50이하일때

				dpos = 2*(-0.5+((double)ipos * 0.01)); //왼쪽으로 이동 

			} 
			else if(ipos >= 50){  //슬라이더가 50이상일때
				dpos = 5*(((double)ipos * 0.01)-0.5); //오른쪽으로 이동
			}


			pView->Ocean.FishingVessel=2.5+dpos; //filmscale값을 바꿔줌
			pView->Ocean.fishingscale=dpos;
			pView->Invalidate(FALSE);
		}
		else if(ipos>100){
			ipos = 100;
			dpos = 5*(((double)ipos * 0.01)-0.5); //오른쪽으로 이동
			pView->Ocean.FishingVessel=2.5+dpos; //filmscale값을 바꿔줌
			pView->Ocean.fishingscale=dpos;
			pView->Invalidate(FALSE);

		}


	}
}

//콤보 박스 선택시
void CFishingDlg::OnCbnSelchangeOceanCombo()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	//물고기선택

	if(mFishingCombo.GetCurSel()==2){//배

		mBoatRedS.ShowWindow(SW_SHOW);
		mBoatGreenS.ShowWindow(SW_SHOW);
		mBoatBlueS.ShowWindow(SW_SHOW);

		mBoatRedValue.ShowWindow(SW_SHOW);
		mBoatGreenValue.ShowWindow(SW_SHOW);
		mBoatBlueValue.ShowWindow(SW_SHOW);

		mLBoatRedS.ShowWindow(SW_HIDE);
		mLBoatGreenS.ShowWindow(SW_HIDE);
		mLBoatBlueS.ShowWindow(SW_HIDE);

		mLBoatRedValue.ShowWindow(SW_HIDE);
		mLBoatGreenValue.ShowWindow(SW_HIDE);
		mLBoatBlueValue.ShowWindow(SW_HIDE);

		mRBoatRedS.ShowWindow(SW_HIDE);
		mRBoatGreenS.ShowWindow(SW_HIDE);
		mRBoatBlueS.ShowWindow(SW_HIDE);

		mRBoatRedValue.ShowWindow(SW_HIDE);
		mRBoatGreenValue.ShowWindow(SW_HIDE);
		mRBoatBlueValue.ShowWindow(SW_HIDE);

		mFishingPRedS.ShowWindow(SW_HIDE);
		mFishingPGreenS.ShowWindow(SW_HIDE);
		mFishingPBlueS.ShowWindow(SW_HIDE);

		mFishingPRedValue.ShowWindow(SW_HIDE);
		mFishingPGreenValue.ShowWindow(SW_HIDE);
		mFishingPBlueValue.ShowWindow(SW_HIDE);

		mFishingRedS.ShowWindow(SW_HIDE);
		mFishingGreenS.ShowWindow(SW_HIDE);
		mFishingBlueS.ShowWindow(SW_HIDE);

		mFishingRedValue.ShowWindow(SW_HIDE);
		mFishingGreenValue.ShowWindow(SW_HIDE);
		mFishingBlueValue.ShowWindow(SW_HIDE);


	}
	else if(mFishingCombo.GetCurSel()==4){ //오른쪽 돛
		mLBoatRedS.ShowWindow(SW_SHOW);
		mLBoatGreenS.ShowWindow(SW_SHOW);
		mLBoatBlueS.ShowWindow(SW_SHOW);

		mLBoatRedValue.ShowWindow(SW_SHOW);
		mLBoatGreenValue.ShowWindow(SW_SHOW);
		mLBoatBlueValue.ShowWindow(SW_SHOW);

		mBoatRedS.ShowWindow(SW_HIDE);
		mBoatGreenS.ShowWindow(SW_HIDE);
		mBoatBlueS.ShowWindow(SW_HIDE);

		mBoatRedValue.ShowWindow(SW_HIDE);
		mBoatGreenValue.ShowWindow(SW_HIDE);
		mBoatBlueValue.ShowWindow(SW_HIDE);

		mRBoatRedS.ShowWindow(SW_HIDE);
		mRBoatGreenS.ShowWindow(SW_HIDE);
		mRBoatBlueS.ShowWindow(SW_HIDE);

		mRBoatRedValue.ShowWindow(SW_HIDE);
		mRBoatGreenValue.ShowWindow(SW_HIDE);
		mRBoatBlueValue.ShowWindow(SW_HIDE);

		mFishingPRedS.ShowWindow(SW_HIDE);
		mFishingPGreenS.ShowWindow(SW_HIDE);
		mFishingPBlueS.ShowWindow(SW_HIDE);

		mFishingPRedValue.ShowWindow(SW_HIDE);
		mFishingPGreenValue.ShowWindow(SW_HIDE);
		mFishingPBlueValue.ShowWindow(SW_HIDE);

		mFishingRedS.ShowWindow(SW_HIDE);
		mFishingGreenS.ShowWindow(SW_HIDE);
		mFishingBlueS.ShowWindow(SW_HIDE);

		mFishingRedValue.ShowWindow(SW_HIDE);
		mFishingGreenValue.ShowWindow(SW_HIDE);
		mFishingBlueValue.ShowWindow(SW_HIDE);


	}
	else if(mFishingCombo.GetCurSel()==3){ //왼쪽돛
		mRBoatRedS.ShowWindow(SW_SHOW);
		mRBoatGreenS.ShowWindow(SW_SHOW);
		mRBoatBlueS.ShowWindow(SW_SHOW);

		mRBoatRedValue.ShowWindow(SW_SHOW);
		mRBoatGreenValue.ShowWindow(SW_SHOW);
		mRBoatBlueValue.ShowWindow(SW_SHOW);

		mLBoatRedS.ShowWindow(SW_HIDE);
		mLBoatGreenS.ShowWindow(SW_HIDE);
		mLBoatBlueS.ShowWindow(SW_HIDE);

		mLBoatRedValue.ShowWindow(SW_HIDE);
		mLBoatGreenValue.ShowWindow(SW_HIDE);
		mLBoatBlueValue.ShowWindow(SW_HIDE);


		mBoatRedS.ShowWindow(SW_HIDE);
		mBoatGreenS.ShowWindow(SW_HIDE);
		mBoatBlueS.ShowWindow(SW_HIDE);

		mBoatRedValue.ShowWindow(SW_HIDE);
		mBoatGreenValue.ShowWindow(SW_HIDE);
		mBoatBlueValue.ShowWindow(SW_HIDE);

		mFishingPRedS.ShowWindow(SW_HIDE);
		mFishingPGreenS.ShowWindow(SW_HIDE);
		mFishingPBlueS.ShowWindow(SW_HIDE);

		mFishingPRedValue.ShowWindow(SW_HIDE);
		mFishingPGreenValue.ShowWindow(SW_HIDE);
		mFishingPBlueValue.ShowWindow(SW_HIDE);

		mFishingRedS.ShowWindow(SW_HIDE);
		mFishingGreenS.ShowWindow(SW_HIDE);
		mFishingBlueS.ShowWindow(SW_HIDE);

		mFishingRedValue.ShowWindow(SW_HIDE);
		mFishingGreenValue.ShowWindow(SW_HIDE);
		mFishingBlueValue.ShowWindow(SW_HIDE);


	}

	else if(mFishingCombo.GetCurSel()==0){ //낚시대

		mFishingPRedS.ShowWindow(SW_SHOW);
		mFishingPGreenS.ShowWindow(SW_SHOW);
		mFishingPBlueS.ShowWindow(SW_SHOW);

		mFishingPRedValue.ShowWindow(SW_SHOW);
		mFishingPGreenValue.ShowWindow(SW_SHOW);
		mFishingPBlueValue.ShowWindow(SW_SHOW);

		mLBoatRedS.ShowWindow(SW_HIDE);
		mLBoatGreenS.ShowWindow(SW_HIDE);
		mLBoatBlueS.ShowWindow(SW_HIDE);

		mLBoatRedValue.ShowWindow(SW_HIDE);
		mLBoatGreenValue.ShowWindow(SW_HIDE);
		mLBoatBlueValue.ShowWindow(SW_HIDE);


		mBoatRedS.ShowWindow(SW_HIDE);
		mBoatGreenS.ShowWindow(SW_HIDE);
		mBoatBlueS.ShowWindow(SW_HIDE);

		mBoatRedValue.ShowWindow(SW_HIDE);
		mBoatGreenValue.ShowWindow(SW_HIDE);
		mBoatBlueValue.ShowWindow(SW_HIDE);

		mRBoatRedS.ShowWindow(SW_HIDE);
		mRBoatGreenS.ShowWindow(SW_HIDE);
		mRBoatBlueS.ShowWindow(SW_HIDE);

		mRBoatRedValue.ShowWindow(SW_HIDE);
		mRBoatGreenValue.ShowWindow(SW_HIDE);
		mRBoatBlueValue.ShowWindow(SW_HIDE);

		mFishingRedS.ShowWindow(SW_HIDE);
		mFishingGreenS.ShowWindow(SW_HIDE);
		mFishingBlueS.ShowWindow(SW_HIDE);

		mFishingRedValue.ShowWindow(SW_HIDE);
		mFishingGreenValue.ShowWindow(SW_HIDE);
		mFishingBlueValue.ShowWindow(SW_HIDE);

	}

	else if(mFishingCombo.GetCurSel()==1){ //낚시줄
		mFishingRedS.ShowWindow(SW_SHOW);
		mFishingGreenS.ShowWindow(SW_SHOW);
		mFishingBlueS.ShowWindow(SW_SHOW);

		mFishingRedValue.ShowWindow(SW_SHOW);
		mFishingGreenValue.ShowWindow(SW_SHOW);
		mFishingBlueValue.ShowWindow(SW_SHOW);

		mFishingPRedS.ShowWindow(SW_HIDE);
		mFishingPGreenS.ShowWindow(SW_HIDE);
		mFishingPBlueS.ShowWindow(SW_HIDE);

		mFishingPRedValue.ShowWindow(SW_HIDE);
		mFishingPGreenValue.ShowWindow(SW_HIDE);
		mFishingPBlueValue.ShowWindow(SW_HIDE);

		mLBoatRedS.ShowWindow(SW_HIDE);
		mLBoatGreenS.ShowWindow(SW_HIDE);
		mLBoatBlueS.ShowWindow(SW_HIDE);

		mLBoatRedValue.ShowWindow(SW_HIDE);
		mLBoatGreenValue.ShowWindow(SW_HIDE);
		mLBoatBlueValue.ShowWindow(SW_HIDE);


		mBoatRedS.ShowWindow(SW_HIDE);
		mBoatGreenS.ShowWindow(SW_HIDE);
		mBoatBlueS.ShowWindow(SW_HIDE);

		mBoatRedValue.ShowWindow(SW_HIDE);
		mBoatGreenValue.ShowWindow(SW_HIDE);
		mBoatBlueValue.ShowWindow(SW_HIDE);

		mRBoatRedS.ShowWindow(SW_HIDE);
		mRBoatGreenS.ShowWindow(SW_HIDE);
		mRBoatBlueS.ShowWindow(SW_HIDE);

		mRBoatRedValue.ShowWindow(SW_HIDE);
		mRBoatGreenValue.ShowWindow(SW_HIDE);
		mRBoatBlueValue.ShowWindow(SW_HIDE);



	}
}
