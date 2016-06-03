// EdittapCtrl.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "Makory.h"
#include "BalloonDlg.h"
#include "afxdialogex.h"
#include "HotAirBalloon.h"
#include "MainFrm.h"
#include "MakoryDoc.h"
#include "MakoryView.h"

// CBalloonDlg 대화 상자입니다.

IMPLEMENT_DYNAMIC(CBalloonDlg, CDialogEx)

CBalloonDlg::CBalloonDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CBalloonDlg::IDD, pParent)
{
			
}

CBalloonDlg::~CBalloonDlg()
{
}

void CBalloonDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_BALLOON_RED_SLIDER, mBalloonRedS);
	DDX_Control(pDX, IDC_BALLOON_RED_VALUE, mBalloonRedValue);
	DDX_Control(pDX, IDC_BALLOON_GREEN_SLIDER, mBalloonGreenS);
	DDX_Control(pDX, IDC_BALLOON_GREEN_VALUE, mBalloonGreenValue);
	DDX_Control(pDX, IDC_BALLOON_BLUE_SLIDER, mBalloonBlueS);
	DDX_Control(pDX, IDC_BALLOON_BLUE_VALUE, mBalloonBlueValue);
	DDX_Control(pDX, IDC_BALLOON_VSCROLL, mBalloonVSlider);
	DDX_Control(pDX, IDC_BALLOON_HSCROOL, mBalloonHSlider);
	DDX_Control(pDX, IDC_BALLOON_V_VALUE, mBalloonVEdit);
	DDX_Control(pDX, IDC_BALLOON_H_VALUE, mBalloonHEdit);
}


BEGIN_MESSAGE_MAP(CBalloonDlg, CDialogEx)
	ON_WM_HSCROLL()
	ON_EN_UPDATE(IDC_BALLOON_RED_VALUE, &CBalloonDlg::OnEnUpdateBalloonRedValue)
	ON_EN_UPDATE(IDC_BALLOON_GREEN_VALUE, &CBalloonDlg::OnEnUpdateBalloonGreenValue)
	ON_EN_UPDATE(IDC_BALLOON_BLUE_VALUE, &CBalloonDlg::OnEnUpdateBalloonBlueValue)
	ON_EN_UPDATE(IDC_BALLOON_V_VALUE, &CBalloonDlg::OnEnUpdateBalloonVEdit)
	ON_EN_UPDATE(IDC_BALLOON_H_VALUE, &CBalloonDlg::OnEnUpdateBalloonHEdit)
END_MESSAGE_MAP()


// CBalloonDlg 메시지 처리기입니다.

BOOL CBalloonDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	//red 슬라이더
	mBalloonRedS.SetPos(255);//슬라이더 처음 위치
	mBalloonRedS.SetRange(0, 255); //슬라이더 범위 0 ~ 100으로 함.
	mBalloonRedS.SetPageSize(10); //슬라이더를 클릭했을 때 움직이는 범위. 
	mBalloonRedValue.SetWindowTextA("255");//red edit박스 초기값

	//green 슬라이더
	mBalloonGreenS.SetPos(0);//슬라이더 처음 위치
	mBalloonGreenS.SetRange(0, 255); //슬라이더 범위 0 ~ 100으로 함.
	mBalloonGreenS.SetPageSize(10);  //슬라이더를 클릭했을 때 움직이는 범위
	mBalloonGreenValue.SetWindowTextA("0");//green edit박스 초기값

	//blue 슬라이더
	mBalloonBlueS.SetPos(0);//슬라이더 처음 위치
	mBalloonBlueS.SetRange(0, 255); //슬라이더 범위 0 ~ 100으로 함.
	mBalloonBlueS.SetPageSize(10);  //슬라이더를 클릭했을 때 움직이는 범위
	mBalloonBlueValue.SetWindowTextA("0");//blue edit박스 초기값

	//수직슬라이더
	mBalloonVSlider.SetPos(50);//슬라이더 처음 위치
	mBalloonVSlider.SetRange(0, 100); //슬라이더 범위 0 ~ 100으로 함.
	mBalloonVSlider.SetPageSize(1);  //슬라이더를 클릭했을 때 움직이는 범위
	mBalloonVEdit.SetWindowTextA("0");//v edit박스 초기값

	//수평슬라이더
	mBalloonHSlider.SetPos(50);//슬라이더 처음 위치
	mBalloonHSlider.SetRange(0, 100); //슬라이더 범위 0 ~ 100으로 함.
	mBalloonHSlider.SetPageSize(1);  //슬라이더를 클릭했을 때 움직이는 범위
	mBalloonHEdit.SetWindowTextA("0");//h edit박스 초기값


	return TRUE;  // return TRUE unless you set the focus to a control
	// 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}

//얘는 필요없을듯...일단 살려놓고 나중에 없애는걸로..
void CBalloonDlg::ChangeScaleTo(int balloonscale)
{	/*
	//int balloonredsliderpos;
	//mBalloonRedS.SetPos(balloonredcolor); //계속 미친듯이 호출됨
	balloonredsliderpos = mBalloonRedS.GetPos();
	CString strredpos;
	strredpos.Format(_T("%d"), balloonredsliderpos); //형변환
	mBalloonRedValue.SetWindowTextA(strredpos);*/
	
}

//슬라이더 움직였을 때
void CBalloonDlg::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	CMainFrame* pFrame = (CMainFrame*)AfxGetMainWnd();				//View호출
	CMakoryView* pView = (CMakoryView*)pFrame->GetActiveView();		//View호출
	
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	if(pScrollBar)
	{
		// 어떤 슬라이더인지 검사
		//red slider가 움직였을 경우
		if(pScrollBar == (CScrollBar*)&mBalloonRedS)//balloon red slider인경우
		{
			
			// 슬라이더의 위치를 검사한다.
 			int npos = mBalloonRedS.GetPos(); //슬라이더 위치 얻어옴
			CString str;
			str.Format(_T("%d"), npos); //형변환
			mBalloonRedValue.SetWindowTextA(str); //edit 박스에 슬라이더 값 들어감

			fpos = (double)npos * 0.00392156; //슬라이더는 소숫점이 사용이 안됨

			pView->HotAirBalloon.balloonred=fpos;//풍선 빨간색값을 바꿔줌
			pView->Invalidate(FALSE);
		}

		//green슬라이더 움직였을 경우
		else if(pScrollBar == (CScrollBar*)&mBalloonGreenS)//balloon green slider인경우
		{
			
			// 슬라이더의 위치를 검사한다.
 			int npos = mBalloonGreenS.GetPos(); //슬라이더 위치 얻어옴
			CString str;
			str.Format(_T("%d"), npos); //형변환
			mBalloonGreenValue.SetWindowTextA(str);// edit 박스에 슬라이더 값 들어감

			fpos = (double)npos * 0.00392156; //슬라이더는 소숫점이 사용이 안됨

			pView->HotAirBalloon.balloongreen=fpos; //풍선 녹색값을 바꿔줌
			pView->Invalidate(FALSE);
		}

	

		//blue 슬라이더 움직였을 경우
		else if(pScrollBar == (CScrollBar*)&mBalloonBlueS)//balloon green slider인경우
		{

			// 슬라이더의 위치를 검사한다.
			int npos = mBalloonBlueS.GetPos(); //슬라이더 위치 얻어옴
			CString str;
			str.Format(_T("%d"), npos); //형변환
			mBalloonBlueValue.SetWindowTextA(str); //blue edit 박스에 슬라이더 값 들어감

			fpos = (double)npos * 0.00392156; //슬라이더는 소숫점이 사용이 안됨

			pView->HotAirBalloon.balloonblue=fpos; //풍선 파랑색값을 바꿔줌
			pView->Invalidate(FALSE);
		}

		//수직 슬라이더 움직였을 경우
		else if(pScrollBar == (CScrollBar*)&mBalloonVSlider)//수직 슬라이더인경우
		{

			// 슬라이더의 위치를 검사한다.
			int npos = mBalloonVSlider.GetPos(); //슬라이더 위치 얻어옴
			CString str;
			str.Format(_T("%d"), npos-50); //형변환
			mBalloonVEdit.SetWindowTextA(str); //edit 박스에 슬라이더 값 들어감

			
			if(npos <= 50){ //슬라이더가 50이하일때
				fpos = 2*(-0.5+((double)npos * 0.01)); //왼쪽으로 이동 
			} 
			else if(npos >= 50){  //슬라이더가 50이상일때
				fpos = 2*(((double)npos * 0.01)-0.5); //오른쪽으로 이동
			}

			pView->HotAirBalloon.balloony=fpos; //balloony값을 바꿔줌
			pView->Invalidate(FALSE);
		}
		//수평 슬라이더 움직였을 경우
		else if(pScrollBar == (CScrollBar*)&mBalloonHSlider)//수평 슬라이더인경우
		{

			// 슬라이더의 위치를 검사한다.
			int npos = mBalloonHSlider.GetPos(); //슬라이더 위치 얻어옴
			
			CString str;
			str.Format(_T("%d"), npos-50); //형변환
			mBalloonHEdit.SetWindowTextA(str); //edit 박스에 슬라이더 값 들어감

			if(npos <= 50){ //슬라이더가 50이하일때
				fpos = 5*(-0.5+((double)npos * 0.01)); //위으로 이동 
				
			} 
			else if(npos >= 50){  //슬라이더가 50이상일때
				fpos = 5*(((double)npos * 0.01)-0.5); //아래쪽으로 이동
			}

			pView->HotAirBalloon.balloonx=fpos; //balloonx값을 바꿔줌
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
void CBalloonDlg::OnEnUpdateBalloonRedValue()
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

		mBalloonRedValue.GetWindowTextA(String);
		ipos = _ttoi(String);
		mBalloonRedS.SetPos(ipos);
		dpos = (double)ipos * 0.00392156; //슬라이더는 소숫점이 사용이 안됨

		pView->HotAirBalloon.balloonred=dpos;//풍선 빨간색값을 바꿔줌
		pView->Invalidate(FALSE);
	}
}

//green edit
void CBalloonDlg::OnEnUpdateBalloonGreenValue()
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

		mBalloonGreenValue.GetWindowTextA(String);
		ipos = _ttoi(String);
		mBalloonGreenS.SetPos(ipos);
		dpos = (double)ipos * 0.00392156; //슬라이더는 소숫점이 사용이 안됨
		pView->HotAirBalloon.balloongreen=dpos;//풍선 빨간색값을 바꿔줌

		pView->Invalidate(FALSE);
	}
}

//blue edit
void CBalloonDlg::OnEnUpdateBalloonBlueValue()
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

		mBalloonBlueValue.GetWindowTextA(String);
		ipos = _ttoi(String);
		mBalloonBlueS.SetPos(ipos);
		dpos = (double)ipos * 0.00392156; //슬라이더는 소숫점이 사용이 안됨
		pView->HotAirBalloon.balloonblue=dpos;//풍선 빨간색값을 바꿔줌

		pView->Invalidate(FALSE);
	}
}

//수평 edit
void CBalloonDlg::OnEnUpdateBalloonHEdit()
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

		mBalloonHEdit.GetWindowTextA(String);

		ipos = _ttoi(String)+50;
		mBalloonHSlider.SetPos(ipos);

		if(ipos <= 50){ //슬라이더가 50이하일때
		
			dpos = 5*(-0.5+((double)ipos * 0.01)); //왼쪽으로 이동 
			
		} 
		else if(ipos >= 50){  //슬라이더가 50이상일때
			dpos = 5*(((double)ipos * 0.01)-0.5); //오른쪽으로 이동
		}

		pView->HotAirBalloon.balloonx=dpos; //balloony값을 바꿔줌
		pView->Invalidate(FALSE);
	}
}
//수직 Edit
void CBalloonDlg::OnEnUpdateBalloonVEdit()
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

		mBalloonVEdit.GetWindowTextA(String);

		ipos =_ttoi(String)+50;

		mBalloonVSlider.SetPos(ipos);

		if(ipos <= 50){ //슬라이더가 50이하일때
		
			dpos = 2*(-0.5+((double)ipos * 0.01)); //왼쪽으로 이동 
			
		} 
		else if(ipos >= 50){  //슬라이더가 50이상일때
			dpos = 2*(((double)ipos * 0.01)-0.5); //오른쪽으로 이동
		}

		pView->HotAirBalloon.balloony=dpos; //balloony값을 바꿔줌
		pView->Invalidate(FALSE);
	}
	

	
}