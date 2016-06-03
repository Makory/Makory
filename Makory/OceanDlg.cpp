// EdittapCtrl.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "Makory.h"
#include "OceanDlg.h"
#include "afxdialogex.h"
#include "Ocean.h"
#include "MainFrm.h"
#include "MakoryDoc.h"
#include "MakoryView.h"

// CFishDlg 대화 상자입니다.

IMPLEMENT_DYNAMIC(COceanDlg, CDialogEx)

	COceanDlg::COceanDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(COceanDlg::IDD, pParent)
{

}

COceanDlg::~COceanDlg()
{
}

void COceanDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	//삼각 물고기
	DDX_Control(pDX, IDC_FISH1_RED_SLIDER, mFishRedS);
	DDX_Control(pDX, IDC_FISH1_RED_VALUE, mFishRedValue);
	DDX_Control(pDX, IDC_FISH1_GREEN_SLIDER, mFishGreenS);
	DDX_Control(pDX, IDC_FISH1_GREEN_VALUE, mFishGreenValue);
	DDX_Control(pDX, IDC_FISH1_BLUE_SLIDER, mFishBlueS);
	DDX_Control(pDX, IDC_FISH1_BLUE_VALUE, mFishBlueValue);
	DDX_Control(pDX, IDC_FISH1_VSCROLL, mFishVSlider);
	DDX_Control(pDX, IDC_FISH1_HSCROOL, mFishHSlider);
	DDX_Control(pDX, IDC_FISH1_V_VALUE, mFishVEdit);
	DDX_Control(pDX, IDC_FISH1_H_VALUE, mFishHEdit);

	//별가
	DDX_Control(pDX, IDC_OCEAN_COMBO, mOceanCombo);
	DDX_Control(pDX, IDC_STAR_RED_SLIDER, mStarRedS);
	DDX_Control(pDX, IDC_STAR_GREEN_SLIDER, mStarGreenS);
	DDX_Control(pDX, IDC_STAR_BLUE_SLIDER, mStarBlueS);
	DDX_Control(pDX, IDC_STAR_VSCROLL, mStarVSlider);
	DDX_Control(pDX, IDC_STAR_HSCROOL, mStarHSlider);
	DDX_Control(pDX, IDC_STAR_RED_VALUE, mStarRedValue);
	DDX_Control(pDX, IDC_STAR_GREEN_VALUE, mStarGreenValue);
	DDX_Control(pDX, IDC_STAR_BLUE_VALUE, mStarBlueValue);
	DDX_Control(pDX, IDC_STAR_V_VALUE, mStarVEdit);
	DDX_Control(pDX, IDC_STAR_H_VALUE, mStarHEdit);

	//왼쪽에서 등장하는 줄무늬 물고기
	DDX_Control(pDX, IDC_SFISH_RED_SLIDER, mSFishRedS);
	DDX_Control(pDX, IDC_SFISH_GREEN_SLIDER, mSFishGreenS);
	DDX_Control(pDX, IDC_SFISH_BLUE_SLIDER, mSFishBlueS);
	DDX_Control(pDX, IDC_SFISH_VSCROLL, mSFishVSlider);
	DDX_Control(pDX, IDC_SFISH_HSCROOL, mSFishHSlider);
	DDX_Control(pDX, IDC_SFISH_RED_VALUE, mSFishRedValue);
	DDX_Control(pDX, IDC_SFISH_GREEN_VALUE, mSFishGreenValue);
	DDX_Control(pDX, IDC_SFISH_BLUE_VALUE, mSFishBlueValue);
	DDX_Control(pDX, IDC_SFISH_V_VALUE, mSFishVEdit);
	DDX_Control(pDX, IDC_SFISH_H_VALUE, mSFishHEdit);

	//오른쪽에서 등장하는 줄무늬 물고기
	DDX_Control(pDX, IDC_SFISH2_RED_SLIDER, mSFishRedS2);
	DDX_Control(pDX, IDC_SFISH2_GREEN_SLIDER, mSFishGreenS2);
	DDX_Control(pDX, IDC_SFISH2_BLUE_SLIDER, mSFishBlueS2);
	DDX_Control(pDX, IDC_SFISH2_VSCROLL, mSFishVSlider2);
	DDX_Control(pDX, IDC_SFISH2_HSCROOL, mSFishHSlider2);
	DDX_Control(pDX, IDC_SFISH2_RED_VALUE, mSFishRedValue2);
	DDX_Control(pDX, IDC_SFISH2_GREEN_VALUE, mSFishGreenValue2);
	DDX_Control(pDX, IDC_SFISH2_BLUE_VALUE, mSFishBlueValue2);
	DDX_Control(pDX, IDC_SFISH2_V_VALUE, mSFishVEdit2);
	DDX_Control(pDX, IDC_SFISH2_H_VALUE, mSFishHEdit2);
}


BEGIN_MESSAGE_MAP(COceanDlg, CDialogEx)
	ON_WM_HSCROLL()
	ON_EN_UPDATE(IDC_FISH1_RED_VALUE, &COceanDlg::OnEnUpdateFishRedValue)
	ON_EN_UPDATE(IDC_FISH1_GREEN_VALUE, &COceanDlg::OnEnUpdateFishGreenValue)
	ON_EN_UPDATE(IDC_FISH1_BLUE_VALUE, &COceanDlg::OnEnUpdateFishBlueValue)
	ON_EN_UPDATE(IDC_FISH1_V_VALUE, &COceanDlg::OnEnUpdateFishVEdit)
	ON_EN_UPDATE(IDC_FISH1_H_VALUE, &COceanDlg::OnEnUpdateFishHEdit)

	ON_EN_UPDATE(IDC_STAR_RED_VALUE, &COceanDlg::OnEnUpdateStarRedValue)
	ON_EN_UPDATE(IDC_STAR_GREEN_VALUE, &COceanDlg::OnEnUpdateStarGreenValue)
	ON_EN_UPDATE(IDC_STAR_BLUE_VALUE, &COceanDlg::OnEnUpdateStarBlueValue)
	ON_EN_UPDATE(IDC_STAR_V_VALUE, &COceanDlg::OnEnUpdateStarVEdit)
	ON_EN_UPDATE(IDC_STAR_H_VALUE, &COceanDlg::OnEnUpdateStarHEdit)

	ON_EN_UPDATE(IDC_SFISH_RED_VALUE, &COceanDlg::OnEnUpdateSFishRedValue)
	ON_EN_UPDATE(IDC_SFISH_GREEN_VALUE, &COceanDlg::OnEnUpdateSFishGreenValue)
	ON_EN_UPDATE(IDC_SFISH_BLUE_VALUE, &COceanDlg::OnEnUpdateSFishBlueValue)
	ON_EN_UPDATE(IDC_SFISH_V_VALUE, &COceanDlg::OnEnUpdateSFishVEdit)
	ON_EN_UPDATE(IDC_SFISH_H_VALUE, &COceanDlg::OnEnUpdateSFishHEdit)

	ON_EN_UPDATE(IDC_SFISH2_RED_VALUE, &COceanDlg::OnEnUpdateSFishRedValue2)
	ON_EN_UPDATE(IDC_SFISH2_GREEN_VALUE, &COceanDlg::OnEnUpdateSFishGreenValue2)
	ON_EN_UPDATE(IDC_SFISH2_BLUE_VALUE, &COceanDlg::OnEnUpdateSFishBlueValue2)
	ON_EN_UPDATE(IDC_SFISH2_V_VALUE, &COceanDlg::OnEnUpdateSFishVEdit2)
	ON_EN_UPDATE(IDC_SFISH2_H_VALUE, &COceanDlg::OnEnUpdateSFishHEdit2)

	ON_CBN_SELCHANGE(IDC_OCEAN_COMBO, &COceanDlg::OnCbnSelchangeOceanCombo)
END_MESSAGE_MAP()


// CFishDlg 메시지 처리기입니다.

BOOL COceanDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	mFishRedS.ShowWindow(SW_HIDE);
	mFishRedValue.ShowWindow(SW_HIDE);
	mFishGreenS.ShowWindow(SW_HIDE);
	mFishGreenValue.ShowWindow(SW_HIDE);
	mFishBlueS.ShowWindow(SW_HIDE);
	mFishBlueValue.ShowWindow(SW_HIDE);
	mFishVSlider.ShowWindow(SW_HIDE);
	mFishHSlider.ShowWindow(SW_HIDE);
	mFishVEdit.ShowWindow(SW_HIDE);
	mFishHEdit.ShowWindow(SW_HIDE);

	mStarRedS.ShowWindow(SW_SHOW);
	mStarRedValue.ShowWindow(SW_SHOW);
	mStarGreenS.ShowWindow(SW_SHOW);
	mStarGreenValue.ShowWindow(SW_SHOW);
	mStarBlueS.ShowWindow(SW_SHOW);
	mStarBlueValue.ShowWindow(SW_SHOW);
	mStarVSlider.ShowWindow(SW_SHOW);
	mStarHSlider.ShowWindow(SW_SHOW);
	mStarVEdit.ShowWindow(SW_SHOW);
	mStarHEdit.ShowWindow(SW_SHOW);

	mSFishRedS.ShowWindow(SW_HIDE);
	mSFishRedValue.ShowWindow(SW_HIDE);
	mSFishGreenS.ShowWindow(SW_HIDE);
	mSFishGreenValue.ShowWindow(SW_HIDE);
	mSFishBlueS.ShowWindow(SW_HIDE);
	mSFishBlueValue.ShowWindow(SW_HIDE);
	mSFishVSlider.ShowWindow(SW_HIDE);
	mSFishHSlider.ShowWindow(SW_HIDE);
	mSFishVEdit.ShowWindow(SW_HIDE);
	mSFishHEdit.ShowWindow(SW_HIDE);

	mSFishRedS2.ShowWindow(SW_HIDE);
	mSFishRedValue2.ShowWindow(SW_HIDE);
	mSFishGreenS2.ShowWindow(SW_HIDE);
	mSFishGreenValue2.ShowWindow(SW_HIDE);
	mSFishBlueS2.ShowWindow(SW_HIDE);
	mSFishBlueValue2.ShowWindow(SW_HIDE);
	mSFishVSlider2.ShowWindow(SW_HIDE);
	mSFishHSlider2.ShowWindow(SW_HIDE);
	mSFishVEdit2.ShowWindow(SW_HIDE);
	mSFishHEdit2.ShowWindow(SW_HIDE);

	//red 슬라이더
	mFishRedS.SetPos(255);//슬라이더 처음 위치
	mFishRedS.SetRange(0, 255); //슬라이더 범위 0 ~ 100으로 함.
	mFishRedS.SetPageSize(10); //슬라이더를 클릭했을 때 움직이는 범위. 
	mFishRedValue.SetWindowTextA("255");//red edit박스 초기값

	//green 슬라이더
	mFishGreenS.SetPos(0);//슬라이더 처음 위치
	mFishGreenS.SetRange(0, 255); //슬라이더 범위 0 ~ 100으로 함.
	mFishGreenS.SetPageSize(10);  //슬라이더를 클릭했을 때 움직이는 범위
	mFishGreenValue.SetWindowTextA("0");//green edit박스 초기값

	//blue 슬라이더
	mFishBlueS.SetPos(100);//슬라이더 처음 위치
	mFishBlueS.SetRange(0, 255); //슬라이더 범위 0 ~ 100으로 함.
	mFishBlueS.SetPageSize(10);  //슬라이더를 클릭했을 때 움직이는 범위
	mFishBlueValue.SetWindowTextA("255");//blue edit박스 초기값

	//수직슬라이더
	mFishVSlider.SetPos(50);//슬라이더 처음 위치
	mFishVSlider.SetRange(0, 100); //슬라이더 범위 0 ~ 100으로 함.
	mFishVSlider.SetPageSize(1);  //슬라이더를 클릭했을 때 움직이는 범위
	mFishVEdit.SetWindowTextA("0");//v edit박스 초기값

	//수평슬라이더
	mFishHSlider.SetPos(50);//슬라이더 처음 위치
	mFishHSlider.SetRange(0, 100); //슬라이더 범위 0 ~ 100으로 함.
	mFishHSlider.SetPageSize(1);  //슬라이더를 클릭했을 때 움직이는 범위
	mFishHEdit.SetWindowTextA("0");//h edit박스 초기값

	mOceanCombo.AddString("삼각 물고기");
	mOceanCombo.AddString("별가사리");
	mOceanCombo.AddString("줄무늬 물고기1");
	mOceanCombo.AddString("줄무늬 물고기2");
	mOceanCombo.SetCurSel(0); //콤보박스 기본 설정 사선

	//별가사리
	//red 슬라이더
	mStarRedS.SetPos(255);//슬라이더 처음 위치
	mStarRedS.SetRange(0, 255); //슬라이더 범위 0 ~ 100으로 함.
	mStarRedS.SetPageSize(10); //슬라이더를 클릭했을 때 움직이는 범위. 
	mStarRedValue.SetWindowTextA("255");//red edit박스 초기값

	//green 슬라이더
	mStarGreenS.SetPos(0);//슬라이더 처음 위치
	mStarGreenS.SetRange(0, 255); //슬라이더 범위 0 ~ 100으로 함.
	mStarGreenS.SetPageSize(10);  //슬라이더를 클릭했을 때 움직이는 범위
	mStarGreenValue.SetWindowTextA("0");//green edit박스 초기값

	//blue 슬라이더
	mStarBlueS.SetPos(0);//슬라이더 처음 위치
	mStarBlueS.SetRange(0, 255); //슬라이더 범위 0 ~ 100으로 함.
	mStarBlueS.SetPageSize(10);  //슬라이더를 클릭했을 때 움직이는 범위
	mStarBlueValue.SetWindowTextA("0");//blue edit박스 초기값

	//수직슬라이더
	mStarVSlider.SetPos(50);//슬라이더 처음 위치
	mStarVSlider.SetRange(0, 100); //슬라이더 범위 0 ~ 100으로 함.
	mStarVSlider.SetPageSize(1);  //슬라이더를 클릭했을 때 움직이는 범위
	mStarVEdit.SetWindowTextA("0");//v edit박스 초기값

	//수평슬라이더
	mStarHSlider.SetPos(50);//슬라이더 처음 위치
	mStarHSlider.SetRange(0, 100); //슬라이더 범위 0 ~ 100으로 함.
	mStarHSlider.SetPageSize(1);  //슬라이더를 클릭했을 때 움직이는 범위
	mStarHEdit.SetWindowTextA("0");//h edit박스 초기값

	//줄무늬 물고기1

	//red 슬라이더
	mSFishRedS.SetPos(255);//슬라이더 처음 위치
	mSFishRedS.SetRange(0, 255); //슬라이더 범위 0 ~ 100으로 함.
	mSFishRedS.SetPageSize(10); //슬라이더를 클릭했을 때 움직이는 범위. 
	mSFishRedValue.SetWindowTextA("255");//red edit박스 초기값

	//green 슬라이더
	mSFishGreenS.SetPos(0);//슬라이더 처음 위치
	mSFishGreenS.SetRange(0, 255); //슬라이더 범위 0 ~ 100으로 함.
	mSFishGreenS.SetPageSize(10);  //슬라이더를 클릭했을 때 움직이는 범위
	mSFishGreenValue.SetWindowTextA("0");//green edit박스 초기값

	//blue 슬라이더
	mSFishBlueS.SetPos(0);//슬라이더 처음 위치
	mSFishBlueS.SetRange(0, 255); //슬라이더 범위 0 ~ 100으로 함.
	mSFishBlueS.SetPageSize(10);  //슬라이더를 클릭했을 때 움직이는 범위
	mSFishBlueValue.SetWindowTextA("0");//blue edit박스 초기값


	//수직슬라이더
	mSFishVSlider.SetPos(50);//슬라이더 처음 위치
	mSFishVSlider.SetRange(0, 100); //슬라이더 범위 0 ~ 100으로 함.
	mSFishVSlider.SetPageSize(1);  //슬라이더를 클릭했을 때 움직이는 범위
	mSFishVEdit.SetWindowTextA("0");//v edit박스 초기값

	//수평슬라이더
	mSFishHSlider.SetPos(50);//슬라이더 처음 위치
	mSFishHSlider.SetRange(0, 100); //슬라이더 범위 0 ~ 100으로 함.
	mSFishHSlider.SetPageSize(1);  //슬라이더를 클릭했을 때 움직이는 범위
	mSFishHEdit.SetWindowTextA("0");//h edit박스 초기값


	//줄무늬 물고기2
	//red 슬라이더
	mSFishRedS2.SetPos(255);//슬라이더 처음 위치
	mSFishRedS2.SetRange(0, 255); //슬라이더 범위 0 ~ 100으로 함.
	mSFishRedS2.SetPageSize(10); //슬라이더를 클릭했을 때 움직이는 범위. 
	mSFishRedValue2.SetWindowTextA("255");//red edit박스 초기값

	//green 슬라이더
	mSFishGreenS2.SetPos(0);//슬라이더 처음 위치
	mSFishGreenS2.SetRange(0, 255); //슬라이더 범위 0 ~ 100으로 함.
	mSFishGreenS2.SetPageSize(10);  //슬라이더를 클릭했을 때 움직이는 범위
	mSFishGreenValue2.SetWindowTextA("0");//green edit박스 초기값

	//blue 슬라이더
	mSFishBlueS2.SetPos(0);//슬라이더 처음 위치
	mSFishBlueS2.SetRange(0, 255); //슬라이더 범위 0 ~ 100으로 함.
	mSFishBlueS2.SetPageSize(10);  //슬라이더를 클릭했을 때 움직이는 범위
	mSFishBlueValue2.SetWindowTextA("0");//blue edit박스 초기값


	//수직슬라이더
	mSFishVSlider2.SetPos(50);//슬라이더 처음 위치
	mSFishVSlider2.SetRange(0, 100); //슬라이더 범위 0 ~ 100으로 함.
	mSFishVSlider2.SetPageSize(1);  //슬라이더를 클릭했을 때 움직이는 범위
	mSFishVEdit2.SetWindowTextA("0");//v edit박스 초기값

	//수평슬라이더
	mSFishHSlider2.SetPos(50);//슬라이더 처음 위치
	mSFishHSlider2.SetRange(0, 100); //슬라이더 범위 0 ~ 100으로 함.
	mSFishHSlider2.SetPageSize(1);  //슬라이더를 클릭했을 때 움직이는 범위
	mSFishHEdit2.SetWindowTextA("0");//h edit박스 초기값


	return TRUE;  // return TRUE unless you set the focus to a control
	// 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}


//슬라이더 움직였을 때
void COceanDlg::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	CMainFrame* pFrame = (CMainFrame*)AfxGetMainWnd();				//View호출
	CMakoryView* pView = (CMakoryView*)pFrame->GetActiveView();		//View호출

	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	if(pScrollBar)
	{
		// 어떤 슬라이더인지 검사
		//red slider가 움직였을 경우
		if(pScrollBar == (CScrollBar*)&mFishRedS)//Fish red slider인경우
		{

			// 슬라이더의 위치를 검사한다.
			int npos = mFishRedS.GetPos(); //슬라이더 위치 얻어옴
			CString str;
			str.Format(_T("%d"), npos); //형변환
			mFishRedValue.SetWindowTextA(str); //edit 박스에 슬라이더 값 들어감

			fpos = (double)npos * 0.00392156; //슬라이더는 소숫점이 사용이 안됨

			pView->Ocean.fishred=fpos;//풍선 빨간색값을 바꿔줌
			pView->Invalidate(FALSE);
		}

		//green슬라이더 움직였을 경우
		else if(pScrollBar == (CScrollBar*)&mFishGreenS)//Fish green slider인경우
		{

			// 슬라이더의 위치를 검사한다.
			int npos = mFishGreenS.GetPos(); //슬라이더 위치 얻어옴
			CString str;
			str.Format(_T("%d"), npos); //형변환
			mFishGreenValue.SetWindowTextA(str);// edit 박스에 슬라이더 값 들어감

			fpos = (double)npos * 0.00392156; //슬라이더는 소숫점이 사용이 안됨

			pView->Ocean.fishgreen=fpos; //풍선 녹색값을 바꿔줌
			pView->Invalidate(FALSE);
		}

		//blue 슬라이더 움직였을 경우
		else if(pScrollBar == (CScrollBar*)&mFishBlueS)//Fish green slider인경우
		{

			// 슬라이더의 위치를 검사한다.
			int npos = mFishBlueS.GetPos(); //슬라이더 위치 얻어옴
			CString str;
			str.Format(_T("%d"), npos); //형변환
			mFishBlueValue.SetWindowTextA(str);// edit 박스에 슬라이더 값 들어감

			fpos = (double)npos * 0.00392156; //슬라이더는 소숫점이 사용이 안됨

			pView->Ocean.fishblue=fpos; //풍선 녹색값을 바꿔줌
			pView->Invalidate(FALSE);
		}

		
		//수직 슬라이더 움직였을 경우
		else if(pScrollBar == (CScrollBar*)&mFishVSlider)//수직 슬라이더인경우
		{

			// 슬라이더의 위치를 검사한다.
			int npos = mFishVSlider.GetPos(); //슬라이더 위치 얻어옴
			CString str;
			str.Format(_T("%d"), npos-50); //형변환
			mFishVEdit.SetWindowTextA(str); //edit 박스에 슬라이더 값 들어감


			if(npos <= 50){ //슬라이더가 50이하일때
				fpos = -0.5+((double)npos * 0.01); //왼쪽으로 이동 
			} 
			else if(npos >= 50){  //슬라이더가 50이상일때
				fpos = ((double)npos * 0.01)-0.5; //오른쪽으로 이동
			}

			pView->Ocean.fishy=fpos; //Fishy값을 바꿔줌

			pView->Invalidate(FALSE);
		}
		//수평 슬라이더 움직였을 경우
		else if(pScrollBar == (CScrollBar*)&mFishHSlider)//수평 슬라이더인경우
		{

			// 슬라이더의 위치를 검사한다.
			int npos = mFishHSlider.GetPos(); //슬라이더 위치 얻어옴

			CString str;
			str.Format(_T("%d"), npos-50); //형변환
			mFishHEdit.SetWindowTextA(str); //edit 박스에 슬라이더 값 들어감

			if(npos <= 50){ //슬라이더가 50이하일때
				fpos = -0.5+((double)npos * 0.01); //위으로 이동 

			} 
			else if(npos >= 50){  //슬라이더가 50이상일때
				fpos = ((double)npos * 0.01)-0.5; //아래쪽으로 이동
			}

			pView->Ocean.fishx=fpos; //Fishx값을 바꿔줌

			pView->Invalidate(FALSE);
		}

		//별가 

		if(pScrollBar == (CScrollBar*)&mStarRedS)//Fish red slider인경우
		{

			// 슬라이더의 위치를 검사한다.
			int npos = mStarRedS.GetPos(); //슬라이더 위치 얻어옴
			CString str;
			str.Format(_T("%d"), npos); //형변환
			mStarRedValue.SetWindowTextA(str); //edit 박스에 슬라이더 값 들어감

			fpos = (double)npos * 0.00392156; //슬라이더는 소숫점이 사용이 안됨

			pView->Ocean.starred=fpos;//풍선 빨간색값을 바꿔줌
			pView->Invalidate(FALSE);
		}

		//green슬라이더 움직였을 경우
		else if(pScrollBar == (CScrollBar*)&mStarGreenS)//Fish green slider인경우
		{

			// 슬라이더의 위치를 검사한다.
			int npos = mStarGreenS.GetPos(); //슬라이더 위치 얻어옴
			CString str;
			str.Format(_T("%d"), npos); //형변환
			mStarGreenValue.SetWindowTextA(str);// edit 박스에 슬라이더 값 들어감

			fpos = (double)npos * 0.00392156; //슬라이더는 소숫점이 사용이 안됨

			pView->Ocean.stargreen=fpos; //풍선 녹색값을 바꿔줌
			pView->Invalidate(FALSE);
		}



		//blue 슬라이더 움직였을 경우
		else if(pScrollBar == (CScrollBar*)&mStarBlueS)//Fish green slider인경우
		{

			// 슬라이더의 위치를 검사한다.
			int npos = mStarBlueS.GetPos(); //슬라이더 위치 얻어옴
			CString str;
			str.Format(_T("%d"), npos); //형변환
			mStarBlueValue.SetWindowTextA(str); //blue edit 박스에 슬라이더 값 들어감

			fpos = (double)npos * 0.00392156; //슬라이더는 소숫점이 사용이 안됨

			pView->Ocean.starblue=fpos; //풍선 파랑색값을 바꿔줌
			pView->Invalidate(FALSE);
		}



		else if(pScrollBar == (CScrollBar*)&mStarVSlider)//수직 슬라이더인경우
		{

			// 슬라이더의 위치를 검사한다.
			int npos = mStarVSlider.GetPos(); //슬라이더 위치 얻어옴
			CString str;
			str.Format(_T("%d"), npos-50); //형변환
			mStarVEdit.SetWindowTextA(str); //edit 박스에 슬라이더 값 들어감


			if(npos <= 50){ //슬라이더가 50이하일때
				fpos = -0.5+((double)npos * 0.01); //왼쪽으로 이동 
			} 
			else if(npos >= 50){  //슬라이더가 50이상일때
				fpos = ((double)npos * 0.1)-5; //오른쪽으로 이동
			}

			pView->Ocean.stary=fpos; //Fishy값을 바꿔줌

			pView->Invalidate(FALSE);
		}
		//수평 슬라이더 움직였을 경우
		else if(pScrollBar == (CScrollBar*)&mStarHSlider)//수평 슬라이더인경우
		{

			// 슬라이더의 위치를 검사한다.
			int npos = mStarHSlider.GetPos(); //슬라이더 위치 얻어옴

			CString str;
			str.Format(_T("%d"), npos-50); //형변환
			mStarHEdit.SetWindowTextA(str); //edit 박스에 슬라이더 값 들어감

			if(npos <= 50){ //슬라이더가 50이하일때
				fpos = 2*(-0.5+((double)npos * 0.01)); //위으로 이동 

			} 
			else if(npos >= 50){  //슬라이더가 50이상일때
				fpos = 2*(((double)npos * 0.1)-5); //아래쪽으로 이동
			}

			pView->Ocean.starx=fpos; //Fishx값을 바꿔줌

			pView->Invalidate(FALSE);
		}

		//줄무늬 물고기1

		//red slider가 움직였을 경우
		if(pScrollBar == (CScrollBar*)&mSFishRedS)//Fish red slider인경우
		{

			// 슬라이더의 위치를 검사한다.
			int npos = mSFishRedS.GetPos(); //슬라이더 위치 얻어옴
			CString str;
			str.Format(_T("%d"), npos); //형변환
			mSFishRedValue.SetWindowTextA(str); //edit 박스에 슬라이더 값 들어감

			fpos = (double)npos * 0.00392156; //슬라이더는 소숫점이 사용이 안됨

			pView->Ocean.sfishred=fpos;//풍선 빨간색값을 바꿔줌
			pView->Invalidate(FALSE);
		}

		//green슬라이더 움직였을 경우
		else if(pScrollBar == (CScrollBar*)&mSFishGreenS)//Fish green slider인경우
		{

			// 슬라이더의 위치를 검사한다.
			int npos = mSFishGreenS.GetPos(); //슬라이더 위치 얻어옴
			CString str;
			str.Format(_T("%d"), npos); //형변환
			mSFishGreenValue.SetWindowTextA(str);// edit 박스에 슬라이더 값 들어감

			fpos = (double)npos * 0.00392156; //슬라이더는 소숫점이 사용이 안됨

			pView->Ocean.sfishgreen=fpos; //풍선 녹색값을 바꿔줌
			pView->Invalidate(FALSE);
		}

		//blue 슬라이더 움직였을 경우
		else if(pScrollBar == (CScrollBar*)&mSFishBlueS)//Fish green slider인경우
		{

			// 슬라이더의 위치를 검사한다.
			int npos = mSFishBlueS.GetPos(); //슬라이더 위치 얻어옴
			CString str;
			str.Format(_T("%d"), npos); //형변환
			mSFishBlueValue.SetWindowTextA(str); //blue edit 박스에 슬라이더 값 들어감

			fpos = (double)npos * 0.00392156; //슬라이더는 소숫점이 사용이 안됨

			pView->Ocean.sfishblue=fpos; //풍선 파랑색값을 바꿔줌
			pView->Invalidate(FALSE);
		}

		else if(pScrollBar == (CScrollBar*)&mSFishVSlider)//수직 슬라이더인경우
		{

			// 슬라이더의 위치를 검사한다.
			int npos = mSFishVSlider.GetPos(); //슬라이더 위치 얻어옴
			CString str;
			str.Format(_T("%d"), npos-50); //형변환
			mSFishVEdit.SetWindowTextA(str); //edit 박스에 슬라이더 값 들어감


			if(npos <= 50){ //슬라이더가 50이하일때
				fpos = -0.5+((double)npos * 0.01); //왼쪽으로 이동 
			} 
			else if(npos >= 50){  //슬라이더가 50이상일때
				fpos = ((double)npos * 0.01)-0.5; //오른쪽으로 이동
			}

			pView->Ocean.sfishy=fpos; //Fishy값을 바꿔줌

			pView->Invalidate(FALSE);
		}
		//수평 슬라이더 움직였을 경우
		else if(pScrollBar == (CScrollBar*)&mSFishHSlider)//수평 슬라이더인경우
		{

			// 슬라이더의 위치를 검사한다.
			int npos = mSFishHSlider.GetPos(); //슬라이더 위치 얻어옴

			CString str;
			str.Format(_T("%d"), npos-50); //형변환
			mSFishHEdit.SetWindowTextA(str); //edit 박스에 슬라이더 값 들어감

			if(npos <= 50){ //슬라이더가 50이하일때
				fpos = -0.5+((double)npos * 0.01); //위으로 이동 

			} 
			else if(npos >= 50){  //슬라이더가 50이상일때
				fpos = ((double)npos * 0.01)-0.5; //아래쪽으로 이동
			}

			pView->Ocean.sfishx=fpos; //Fishx값을 바꿔줌

			pView->Invalidate(FALSE);
		}

		//줄무늬 물고기2

		//red slider가 움직였을 경우
		if(pScrollBar == (CScrollBar*)&mSFishRedS2)//Fish red slider인경우
		{

			// 슬라이더의 위치를 검사한다.
			int npos = mSFishRedS2.GetPos(); //슬라이더 위치 얻어옴
			CString str;
			str.Format(_T("%d"), npos); //형변환
			mSFishRedValue2.SetWindowTextA(str); //edit 박스에 슬라이더 값 들어감

			fpos = (double)npos * 0.00392156; //슬라이더는 소숫점이 사용이 안됨

			pView->Ocean.sfishred2=fpos;//풍선 빨간색값을 바꿔줌
			pView->Invalidate(FALSE);
		}

		//green슬라이더 움직였을 경우
		else if(pScrollBar == (CScrollBar*)&mSFishGreenS2)//Fish green slider인경우
		{

			// 슬라이더의 위치를 검사한다.
			int npos = mSFishGreenS2.GetPos(); //슬라이더 위치 얻어옴
			CString str;
			str.Format(_T("%d"), npos); //형변환
			mSFishGreenValue2.SetWindowTextA(str);// edit 박스에 슬라이더 값 들어감

			fpos = (double)npos * 0.00392156; //슬라이더는 소숫점이 사용이 안됨

			pView->Ocean.sfishgreen2=fpos; //풍선 녹색값을 바꿔줌
			pView->Invalidate(FALSE);
		}

		//blue 슬라이더 움직였을 경우
		else if(pScrollBar == (CScrollBar*)&mSFishBlueS2)//Fish green slider인경우
		{

			// 슬라이더의 위치를 검사한다.
			int npos = mSFishBlueS2.GetPos(); //슬라이더 위치 얻어옴
			CString str;
			str.Format(_T("%d"), npos); //형변환
			mSFishBlueValue2.SetWindowTextA(str); //blue edit 박스에 슬라이더 값 들어감

			fpos = (double)npos * 0.00392156; //슬라이더는 소숫점이 사용이 안됨

			pView->Ocean.sfishblue2=fpos; //풍선 파랑색값을 바꿔줌
			pView->Invalidate(FALSE);
		}


		else if(pScrollBar == (CScrollBar*)&mSFishVSlider2)//수직 슬라이더인경우
		{

			// 슬라이더의 위치를 검사한다.
			int npos = mSFishVSlider2.GetPos(); //슬라이더 위치 얻어옴
			CString str;
			str.Format(_T("%d"), npos-50); //형변환
			mSFishVEdit2.SetWindowTextA(str); //edit 박스에 슬라이더 값 들어감


			if(npos <= 50){ //슬라이더가 50이하일때
				fpos = -0.5+((double)npos * 0.01); //왼쪽으로 이동 
			} 
			else if(npos >= 50){  //슬라이더가 50이상일때
				fpos = ((double)npos * 0.01)-0.5; //오른쪽으로 이동
			}

			pView->Ocean.sfishy2=fpos; //Fishy값을 바꿔줌

			pView->Invalidate(FALSE);
		}
		//수평 슬라이더 움직였을 경우
		else if(pScrollBar == (CScrollBar*)&mSFishHSlider2)//수평 슬라이더인경우
		{

			// 슬라이더의 위치를 검사한다.
			int npos = mSFishHSlider2.GetPos(); //슬라이더 위치 얻어옴

			CString str;
			str.Format(_T("%d"), npos-50); //형변환
			mSFishHEdit2.SetWindowTextA(str); //edit 박스에 슬라이더 값 들어감

			if(npos <= 50){ //슬라이더가 50이하일때
				fpos = -0.5+((double)npos * 0.01); //위으로 이동 

			} 
			else if(npos >= 50){  //슬라이더가 50이상일때
				fpos = ((double)npos * 0.01)-0.5; //아래쪽으로 이동
			}

			pView->Ocean.sfishx2=fpos; //Fishx값을 바꿔줌

			pView->Invalidate(FALSE);
		}
	}

	else
	{
		// CScrollView를 상속받은 뷰의 경우 프래임의 스크롤롤 동작시 pScrollBar이 NULL된다.
	}
	CDialogEx::OnHScroll(nSBCode, nPos, pScrollBar);
}
//RED edit
void COceanDlg::OnEnUpdateFishRedValue()
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

		mFishRedValue.GetWindowTextA(String);
		ipos = _ttoi(String);
		mFishRedS.SetPos(ipos);
		dpos = (double)ipos * 0.00392156; //슬라이더는 소숫점이 사용이 안됨

		pView->Ocean.fishred=dpos;//풍선 빨간색값을 바꿔줌
		pView->Invalidate(FALSE);
	}
}

//green edit
void COceanDlg::OnEnUpdateFishGreenValue()
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

		mFishGreenValue.GetWindowTextA(String);
		ipos = _ttoi(String);
		mFishGreenS.SetPos(ipos);
		dpos = (double)ipos * 0.00392156; //슬라이더는 소숫점이 사용이 안됨
		pView->Ocean.fishgreen=dpos;//풍선 빨간색값을 바꿔줌

		pView->Invalidate(FALSE);
	}
}

//blue edit
void COceanDlg::OnEnUpdateFishBlueValue()
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

		mFishBlueValue.GetWindowTextA(String);
		ipos = _ttoi(String);
		mFishBlueS.SetPos(ipos);
		dpos = (double)ipos * 0.00392156; //슬라이더는 소숫점이 사용이 안됨
		pView->Ocean.fishblue=dpos;//풍선 빨간색값을 바꿔줌

		pView->Invalidate(FALSE);
	}


}

//수평 edit
void COceanDlg::OnEnUpdateFishHEdit()
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

		mFishHEdit.GetWindowTextA(String);

		ipos = _ttoi(String)+50;
		mFishHSlider.SetPos(ipos);

		if(ipos <= 50){ //슬라이더가 50이하일때

			dpos = -0.5+((double)ipos * 0.05); //왼쪽으로 이동 

		} 
		else if(ipos >= 50){  //슬라이더가 50이상일때
			dpos = ((double)ipos * 0.05)-0.5; //오른쪽으로 이동
		}
		pView->Ocean.fishx=dpos; //Fishx값을 바꿔줌
		pView->Invalidate(FALSE);
	}
}
//수직 Edit
void COceanDlg::OnEnUpdateFishVEdit()
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

		mFishVEdit.GetWindowTextA(String);

		ipos =_ttoi(String)+50;

		mFishVSlider.SetPos(ipos);

		if(ipos <= 50){ //슬라이더가 50이하일때

			dpos = -0.5+((double)ipos * 0.01); //왼쪽으로 이동 

		} 
		else if(ipos >= 50){  //슬라이더가 50이상일때
			dpos = ((double)ipos * 0.01)-0.5; //오른쪽으로 이동
		}

		pView->Ocean.fishy=dpos; //Fishy값을 바꿔줌
		pView->Invalidate(FALSE);
	}
}


//star edit box
//RED edit
void COceanDlg::OnEnUpdateStarRedValue()
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

		mStarRedValue.GetWindowTextA(String);
		ipos = _ttoi(String);
		mStarRedS.SetPos(ipos);
		dpos = (double)ipos * 0.00392156; //슬라이더는 소숫점이 사용이 안됨

		pView->Ocean.starred=dpos;//풍선 빨간색값을 바꿔줌
		pView->Invalidate(FALSE);
	}
}

void COceanDlg::OnEnUpdateStarGreenValue()
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

		mStarGreenValue.GetWindowTextA(String);
		ipos = _ttoi(String);
		mStarGreenS.SetPos(ipos);
		dpos = (double)ipos * 0.00392156; //슬라이더는 소숫점이 사용이 안됨

		pView->Ocean.stargreen=dpos;//풍선 빨간색값을 바꿔줌
		pView->Invalidate(FALSE);
	}
}


//blue edit
void COceanDlg::OnEnUpdateStarBlueValue()
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

		mStarBlueValue.GetWindowTextA(String);
		ipos = _ttoi(String);
		mStarBlueS.SetPos(ipos);
		dpos = (double)ipos * 0.00392156; //슬라이더는 소숫점이 사용이 안됨
		pView->Ocean.starblue=dpos;//풍선 빨간색값을 바꿔줌

		pView->Invalidate(FALSE);
	}
}

//수평 edit
void COceanDlg::OnEnUpdateStarHEdit()
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

		mStarHEdit.GetWindowTextA(String);

		ipos = _ttoi(String)+50;
		mStarHSlider.SetPos(ipos);

		if(ipos <= 50){ //슬라이더가 50이하일때

			dpos = -0.5+((double)ipos * 0.01); //왼쪽으로 이동 

		} 
		else if(ipos >= 50){  //슬라이더가 50이상일때
			dpos = ((double)ipos * 0.1)-5;  //오른쪽으로 이동
		}
		pView->Ocean.starx=dpos; //Fishx값을 바꿔줌

		pView->Invalidate(FALSE);
	}

}
//수직 Edit
void COceanDlg::OnEnUpdateStarVEdit()
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

		mStarVEdit.GetWindowTextA(String);

		ipos =_ttoi(String)+50;

		mStarVSlider.SetPos(ipos);

		if(ipos <= 50){ //슬라이더가 50이하일때

			dpos = -0.5+((double)ipos * 0.01); //왼쪽으로 이동 

		} 
		else if(ipos >= 50){  //슬라이더가 50이상일때
			dpos = ((double)ipos * 0.1)-5; //오른쪽으로 이동
		}

		pView->Ocean.stary=dpos; //Fishy값을 바꿔줌
		pView->Invalidate(FALSE);
	}
}

//줄무늬 물고기
//RED edit
void COceanDlg::OnEnUpdateSFishRedValue()
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

		mSFishRedValue.GetWindowTextA(String);
		ipos = _ttoi(String);
		mSFishRedS.SetPos(ipos);
		dpos = (double)ipos * 0.00392156; //슬라이더는 소숫점이 사용이 안됨

		pView->Ocean.sfishred=dpos;//풍선 빨간색값을 바꿔줌
		pView->Invalidate(FALSE);
	}
}

//green edit
void COceanDlg::OnEnUpdateSFishGreenValue()
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

		mSFishGreenValue.GetWindowTextA(String);
		ipos = _ttoi(String);
		mSFishGreenS.SetPos(ipos);
		dpos = (double)ipos * 0.00392156; //슬라이더는 소숫점이 사용이 안됨
		pView->Ocean.sfishgreen=dpos;//풍선 빨간색값을 바꿔줌

		pView->Invalidate(FALSE);
	}
}

//blue edit
void COceanDlg::OnEnUpdateSFishBlueValue()
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

		mSFishBlueValue.GetWindowTextA(String);
		ipos = _ttoi(String);
		mSFishBlueS.SetPos(ipos);
		dpos = (double)ipos * 0.00392156; //슬라이더는 소숫점이 사용이 안됨
		pView->Ocean.sfishblue=dpos;//풍선 빨간색값을 바꿔줌

		pView->Invalidate(FALSE);
	}


}

//수평 edit
void COceanDlg::OnEnUpdateSFishHEdit()
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

		mSFishHEdit.GetWindowTextA(String);

		ipos = _ttoi(String)+50;
		mSFishHSlider.SetPos(ipos);

		if(ipos <= 50){ //슬라이더가 50이하일때

			dpos = -0.5+((double)ipos * 0.01); //왼쪽으로 이동 

		} 
		else if(ipos >= 50){  //슬라이더가 50이상일때
			dpos = ((double)ipos * 0.01)-0.5; //오른쪽으로 이동
		}
		pView->Ocean.sfishx=dpos; //Fishx값을 바꿔줌

		pView->Invalidate(FALSE);
	}

}
//수직 Edit
void COceanDlg::OnEnUpdateSFishVEdit()
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

		mSFishVEdit.GetWindowTextA(String);

		ipos =_ttoi(String)+50;

		mSFishVSlider.SetPos(ipos);

		if(ipos <= 50){ //슬라이더가 50이하일때

			dpos = -0.5+((double)ipos * 0.01); //왼쪽으로 이동 

		} 
		else if(ipos >= 50){  //슬라이더가 50이상일때
			dpos = ((double)ipos * 0.01)-0.5; //오른쪽으로 이동
		}

		pView->Ocean.sfishy=dpos; //Fishy값을 바꿔줌
		pView->Invalidate(FALSE);
	}
}


//줄무늬2

//RED edit
void COceanDlg::OnEnUpdateSFishRedValue2()
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

		mSFishRedValue2.GetWindowTextA(String);
		ipos = _ttoi(String);
		mSFishRedS2.SetPos(ipos);
		dpos = (double)ipos * 0.00392156; //슬라이더는 소숫점이 사용이 안됨

		pView->Ocean.sfishred2=dpos;//풍선 빨간색값을 바꿔줌
		pView->Invalidate(FALSE);
	}
}

//green edit
void COceanDlg::OnEnUpdateSFishGreenValue2()
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

		mSFishGreenValue2.GetWindowTextA(String);
		ipos = _ttoi(String);
		mSFishGreenS2.SetPos(ipos);
		dpos = (double)ipos * 0.00392156; //슬라이더는 소숫점이 사용이 안됨
		pView->Ocean.sfishgreen2=dpos;//풍선 빨간색값을 바꿔줌

		pView->Invalidate(FALSE);
	}
}

//blue edit
void COceanDlg::OnEnUpdateSFishBlueValue2()
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

		mSFishBlueValue2.GetWindowTextA(String);
		ipos = _ttoi(String);
		mSFishBlueS2.SetPos(ipos);
		dpos = (double)ipos * 0.00392156; //슬라이더는 소숫점이 사용이 안됨
		pView->Ocean.sfishblue2=dpos;//풍선 빨간색값을 바꿔줌

		pView->Invalidate(FALSE);
	}


}

//수평 edit
void COceanDlg::OnEnUpdateSFishHEdit2()
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

		mSFishHEdit2.GetWindowTextA(String);

		ipos = _ttoi(String)+50;
		mSFishHSlider2.SetPos(ipos);

		if(ipos <= 50){ //슬라이더가 50이하일때

			dpos = -0.5+((double)ipos * 0.01); //왼쪽으로 이동 

		} 
		else if(ipos >= 50){  //슬라이더가 50이상일때
			dpos = ((double)ipos * 0.01)-0.5; //오른쪽으로 이동
		}
		pView->Ocean.sfishx2=dpos; //Fishx값을 바꿔줌

		pView->Invalidate(FALSE);
	}

}
//수직 Edit
void COceanDlg::OnEnUpdateSFishVEdit2()
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

		mSFishVEdit2.GetWindowTextA(String);

		ipos =_ttoi(String)+50;

		mSFishVSlider2.SetPos(ipos);

		if(ipos <= 50){ //슬라이더가 50이하일때

			dpos = -0.5+((double)ipos * 0.01); //왼쪽으로 이동 

		} 
		else if(ipos >= 50){  //슬라이더가 50이상일때
			dpos = ((double)ipos * 0.01)-0.5; //오른쪽으로 이동
		}

		pView->Ocean.sfishy2=dpos; //Fishy값을 바꿔줌
		pView->Invalidate(FALSE);
	}
}


//콤보 박스 선택시
void COceanDlg::OnCbnSelchangeOceanCombo()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	//삼각 물고기선택
	if(mOceanCombo.GetCurSel()==1){

		mFishRedS.ShowWindow(SW_SHOW);
		mFishRedValue.ShowWindow(SW_SHOW);
		mFishGreenS.ShowWindow(SW_SHOW);
		mFishGreenValue.ShowWindow(SW_SHOW);
		mFishBlueS.ShowWindow(SW_SHOW);
		mFishBlueValue.ShowWindow(SW_SHOW);
		mFishVSlider.ShowWindow(SW_SHOW);
		mFishHSlider.ShowWindow(SW_SHOW);
		mFishVEdit.ShowWindow(SW_SHOW);
		mFishHEdit.ShowWindow(SW_SHOW);
	

		mStarRedS.ShowWindow(SW_HIDE);
		mStarRedValue.ShowWindow(SW_HIDE);
		mStarGreenS.ShowWindow(SW_HIDE);
		mStarGreenValue.ShowWindow(SW_HIDE);
		mStarBlueS.ShowWindow(SW_HIDE);
		mStarBlueValue.ShowWindow(SW_HIDE);
		mStarVSlider.ShowWindow(SW_HIDE);
		mStarHSlider.ShowWindow(SW_HIDE);
		mStarVEdit.ShowWindow(SW_HIDE);
		mStarHEdit.ShowWindow(SW_HIDE);

		mSFishRedS.ShowWindow(SW_HIDE);
		mSFishRedValue.ShowWindow(SW_HIDE);
		mSFishGreenS.ShowWindow(SW_HIDE);
		mSFishGreenValue.ShowWindow(SW_HIDE);
		mSFishBlueS.ShowWindow(SW_HIDE);
		mSFishBlueValue.ShowWindow(SW_HIDE);
		mSFishVSlider.ShowWindow(SW_HIDE);
		mSFishHSlider.ShowWindow(SW_HIDE);
		mSFishVEdit.ShowWindow(SW_HIDE);
		mSFishHEdit.ShowWindow(SW_HIDE);


		mSFishRedS2.ShowWindow(SW_HIDE);
		mSFishRedValue2.ShowWindow(SW_HIDE);
		mSFishGreenS2.ShowWindow(SW_HIDE);
		mSFishGreenValue2.ShowWindow(SW_HIDE);
		mSFishBlueS2.ShowWindow(SW_HIDE);
		mSFishBlueValue2.ShowWindow(SW_HIDE);
		mSFishVSlider2.ShowWindow(SW_HIDE);
		mSFishHSlider2.ShowWindow(SW_HIDE);
		mSFishVEdit2.ShowWindow(SW_HIDE);
		mSFishHEdit2.ShowWindow(SW_HIDE);
	}
	//별가선택
	else if(mOceanCombo.GetCurSel()==0){
		mStarRedS.ShowWindow(SW_SHOW);
		mStarRedValue.ShowWindow(SW_SHOW);
		mStarGreenS.ShowWindow(SW_SHOW);
		mStarGreenValue.ShowWindow(SW_SHOW);
		mStarBlueS.ShowWindow(SW_SHOW);
		mStarBlueValue.ShowWindow(SW_SHOW);
		mStarVSlider.ShowWindow(SW_SHOW);
		mStarHSlider.ShowWindow(SW_SHOW);
		mStarVEdit.ShowWindow(SW_SHOW);
		mStarHEdit.ShowWindow(SW_SHOW);

		mFishRedS.ShowWindow(SW_HIDE);
		mFishRedValue.ShowWindow(SW_HIDE);
		mFishGreenS.ShowWindow(SW_HIDE);
		mFishGreenValue.ShowWindow(SW_HIDE);
		mFishBlueS.ShowWindow(SW_HIDE);
		mFishBlueValue.ShowWindow(SW_HIDE);
		mFishVSlider.ShowWindow(SW_HIDE);
		mFishHSlider.ShowWindow(SW_HIDE);
		mFishVEdit.ShowWindow(SW_HIDE);
		mFishHEdit.ShowWindow(SW_HIDE);
		mSFishRedS.ShowWindow(SW_HIDE);
		mSFishRedValue.ShowWindow(SW_HIDE);
		mSFishGreenS.ShowWindow(SW_HIDE);
		mSFishGreenValue.ShowWindow(SW_HIDE);
		mSFishBlueS.ShowWindow(SW_HIDE);
		mSFishBlueValue.ShowWindow(SW_HIDE);
		mSFishVSlider.ShowWindow(SW_HIDE);
		mSFishHSlider.ShowWindow(SW_HIDE);
		mSFishVEdit.ShowWindow(SW_HIDE);
		mSFishHEdit.ShowWindow(SW_HIDE);

		mSFishRedS2.ShowWindow(SW_HIDE);
		mSFishRedValue2.ShowWindow(SW_HIDE);
		mSFishGreenS2.ShowWindow(SW_HIDE);
		mSFishGreenValue2.ShowWindow(SW_HIDE);
		mSFishBlueS2.ShowWindow(SW_HIDE);
		mSFishBlueValue2.ShowWindow(SW_HIDE);
		mSFishVSlider2.ShowWindow(SW_HIDE);
		mSFishHSlider2.ShowWindow(SW_HIDE);
		mSFishVEdit2.ShowWindow(SW_HIDE);
		mSFishHEdit2.ShowWindow(SW_HIDE);
	}
	//줄무늬 물고기1 선택
	else if(mOceanCombo.GetCurSel()==2){
		mSFishRedS.ShowWindow(SW_SHOW);
		mSFishRedValue.ShowWindow(SW_SHOW);
		mSFishGreenS.ShowWindow(SW_SHOW);
		mSFishGreenValue.ShowWindow(SW_SHOW);
		mSFishBlueS.ShowWindow(SW_SHOW);
		mSFishBlueValue.ShowWindow(SW_SHOW);
		mSFishVSlider.ShowWindow(SW_SHOW);
		mSFishHSlider.ShowWindow(SW_SHOW);
		mSFishVEdit.ShowWindow(SW_SHOW);
		mSFishHEdit.ShowWindow(SW_SHOW);

		mStarRedS.ShowWindow(SW_HIDE);
		mStarRedValue.ShowWindow(SW_HIDE);
		mStarGreenS.ShowWindow(SW_HIDE);
		mStarGreenValue.ShowWindow(SW_HIDE);
		mStarBlueS.ShowWindow(SW_HIDE);
		mStarBlueValue.ShowWindow(SW_HIDE);
		mStarVSlider.ShowWindow(SW_HIDE);
		mStarHSlider.ShowWindow(SW_HIDE);
		mStarVEdit.ShowWindow(SW_HIDE);
		mStarHEdit.ShowWindow(SW_HIDE);

		mFishRedS.ShowWindow(SW_HIDE);
		mFishRedValue.ShowWindow(SW_HIDE);
		mFishGreenS.ShowWindow(SW_HIDE);
		mFishGreenValue.ShowWindow(SW_HIDE);
		mFishBlueS.ShowWindow(SW_HIDE);
		mFishBlueValue.ShowWindow(SW_HIDE);
		mFishVSlider.ShowWindow(SW_HIDE);
		mFishHSlider.ShowWindow(SW_HIDE);
		mFishVEdit.ShowWindow(SW_HIDE);
		mFishHEdit.ShowWindow(SW_HIDE);

		mSFishRedS2.ShowWindow(SW_HIDE);
		mSFishRedValue2.ShowWindow(SW_HIDE);
		mSFishGreenS2.ShowWindow(SW_HIDE);
		mSFishGreenValue2.ShowWindow(SW_HIDE);
		mSFishBlueS2.ShowWindow(SW_HIDE);
		mSFishBlueValue2.ShowWindow(SW_HIDE);
		mSFishVSlider2.ShowWindow(SW_HIDE);
		mSFishHSlider2.ShowWindow(SW_HIDE);
		mSFishVEdit2.ShowWindow(SW_HIDE);
		mSFishHEdit2.ShowWindow(SW_HIDE);
	}
	else if(mOceanCombo.GetCurSel()==3){
		mSFishRedS2.ShowWindow(SW_SHOW);
		mSFishRedValue2.ShowWindow(SW_SHOW);
		mSFishGreenS2.ShowWindow(SW_SHOW);
		mSFishGreenValue2.ShowWindow(SW_SHOW);
		mSFishBlueS2.ShowWindow(SW_SHOW);
		mSFishBlueValue2.ShowWindow(SW_SHOW);
		mSFishVSlider2.ShowWindow(SW_SHOW);
		mSFishHSlider2.ShowWindow(SW_SHOW);
		mSFishVEdit2.ShowWindow(SW_SHOW);
		mSFishHEdit2.ShowWindow(SW_SHOW);

		mSFishRedS.ShowWindow(SW_HIDE);
		mSFishRedValue.ShowWindow(SW_HIDE);
		mSFishGreenS.ShowWindow(SW_HIDE);
		mSFishGreenValue.ShowWindow(SW_HIDE);
		mSFishBlueS.ShowWindow(SW_HIDE);
		mSFishBlueValue.ShowWindow(SW_HIDE);
		mSFishVSlider.ShowWindow(SW_HIDE);
		mSFishHSlider.ShowWindow(SW_HIDE);
		mSFishVEdit.ShowWindow(SW_HIDE);
		mSFishHEdit.ShowWindow(SW_HIDE);

		mStarRedS.ShowWindow(SW_HIDE);
		mStarRedValue.ShowWindow(SW_HIDE);
		mStarGreenS.ShowWindow(SW_HIDE);
		mStarGreenValue.ShowWindow(SW_HIDE);
		mStarBlueS.ShowWindow(SW_HIDE);
		mStarBlueValue.ShowWindow(SW_HIDE);
		mStarVSlider.ShowWindow(SW_HIDE);
		mStarHSlider.ShowWindow(SW_HIDE);
		mStarVEdit.ShowWindow(SW_HIDE);
		mStarHEdit.ShowWindow(SW_HIDE);

		mFishRedS.ShowWindow(SW_HIDE);
		mFishRedValue.ShowWindow(SW_HIDE);
		mFishGreenS.ShowWindow(SW_HIDE);
		mFishGreenValue.ShowWindow(SW_HIDE);
		mFishBlueS.ShowWindow(SW_HIDE);
		mFishBlueValue.ShowWindow(SW_HIDE);
		mFishVSlider.ShowWindow(SW_HIDE);
		mFishHSlider.ShowWindow(SW_HIDE);
		mFishVEdit.ShowWindow(SW_HIDE);
		mFishHEdit.ShowWindow(SW_HIDE);
	}
}
