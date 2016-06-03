// EdittapCtrl.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "Makory.h"
#include "SunsetDlg.h"
#include "afxdialogex.h"
#include "HotAirBalloon.h"
#include "MainFrm.h"
#include "MakoryDoc.h"
#include "MakoryView.h"

// CSunsetlg 대화 상자입니다.

IMPLEMENT_DYNAMIC(CSunsetDlg, CDialogEx)

CSunsetDlg::CSunsetDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CSunsetDlg::IDD, pParent)
{

}

CSunsetDlg::~CSunsetDlg()
{
}

void CSunsetDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_SUNSET_RED_SLIDER, mSunsetRedS);
	DDX_Control(pDX, IDC_SUNSET_GREEN_SLIDER, mSunsetGreenS);
	DDX_Control(pDX, IDC_SUNSET_BLUE_SLIDER, mSunsetBlueS);
	DDX_Control(pDX, IDC_SUNSET_VSCROLL, mSunsetVSlider);
	DDX_Control(pDX, IDC_SUNSET_HSCROOL, mSunsetHSlider);
	DDX_Control(pDX, IDC_SUNSET_RED_VALUE, mSunsetRedValue);
	DDX_Control(pDX, IDC_SUNSET_GREEN_VALUE, mSunsetGreenValue);
	DDX_Control(pDX, IDC_SUNSET_BLUE_VALUE, mSunsetBlueValue);
	DDX_Control(pDX, IDC_SUNSET_V_VALUE, mSunsetVEdit);
	DDX_Control(pDX, IDC_SUNSET_H_VALUE, mSunsetHEdit);
}

BEGIN_MESSAGE_MAP(CSunsetDlg, CDialogEx)
	ON_EN_UPDATE(IDC_SUNSET_RED_VALUE, &CSunsetDlg::OnEnUpdateSunsetRedValue)
	ON_EN_UPDATE(IDC_SUNSET_GREEN_VALUE, &CSunsetDlg::OnEnUpdateSunsetGreenValue)
	ON_EN_UPDATE(IDC_SUNSET_BLUE_VALUE, &CSunsetDlg::OnEnUpdateSunsetBlueValue)
	ON_EN_UPDATE(IDC_SUNSET_V_VALUE, &CSunsetDlg::OnEnUpdateSunsetVEdit)
	ON_EN_UPDATE(IDC_SUNSET_H_VALUE, &CSunsetDlg::OnEnUpdateSunsetHEdit)
	ON_WM_HSCROLL()
END_MESSAGE_MAP()


// CSunsetlg 메시지 처리기입니다.

BOOL CSunsetDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	//red 슬라이더
	mSunsetRedS.SetPos(255);//슬라이더 처음 위치
	mSunsetRedS.SetRange(0, 255); //슬라이더 범위 0 ~ 100으로 함.
	mSunsetRedS.SetPageSize(10); //슬라이더를 클릭했을 때 움직이는 범위. 
	mSunsetRedValue.SetWindowTextA("255");//red edit박스 초기값

	//green 슬라이더
	mSunsetGreenS.SetPos(0);//슬라이더 처음 위치
	mSunsetGreenS.SetRange(0, 255); //슬라이더 범위 0 ~ 100으로 함.
	mSunsetGreenS.SetPageSize(10);  //슬라이더를 클릭했을 때 움직이는 범위
	mSunsetGreenValue.SetWindowTextA("0");//green edit박스 초기값

	//blue 슬라이더
	mSunsetBlueS.SetPos(0);//슬라이더 처음 위치
	mSunsetBlueS.SetRange(0, 255); //슬라이더 범위 0 ~ 100으로 함.
	mSunsetBlueS.SetPageSize(10);  //슬라이더를 클릭했을 때 움직이는 범위
	mSunsetBlueValue.SetWindowTextA("0");//blue edit박스 초기값

	//수직슬라이더
	mSunsetVSlider.SetPos(50);//슬라이더 처음 위치
	mSunsetVSlider.SetRange(0, 100); //슬라이더 범위 0 ~ 100으로 함.
	mSunsetVSlider.SetPageSize(1);  //슬라이더를 클릭했을 때 움직이는 범위
	mSunsetVEdit.SetWindowTextA("0");//v edit박스 초기값

	//수평슬라이더
	mSunsetHSlider.SetPos(50);//슬라이더 처음 위치
	mSunsetHSlider.SetRange(0, 100); //슬라이더 범위 0 ~ 100으로 함.
	mSunsetHSlider.SetPageSize(1);  //슬라이더를 클릭했을 때 움직이는 범위
	mSunsetHEdit.SetWindowTextA("0");//h edit박스 초기값


	return TRUE;  // return TRUE unless you set the focus to a control
	// 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}

void CSunsetDlg::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	CMainFrame* pFrame = (CMainFrame*)AfxGetMainWnd();				//View호출
	CMakoryView* pView = (CMakoryView*)pFrame->GetActiveView();		//View호출

	if(pScrollBar)
	{
		// 어떤 슬라이더인지 검사
		//red slider가 움직였을 경우
		if(pScrollBar == (CScrollBar*)&mSunsetRedS)//balloon red slider인경우
		{
			
			// 슬라이더의 위치를 검사한다.
 			int npos = mSunsetRedS.GetPos(); //슬라이더 위치 얻어옴
			CString str;
			str.Format(_T("%d"), npos); //형변환
			mSunsetRedValue.SetWindowTextA(str); //edit 박스에 슬라이더 값 들어감

			dpos = (double)npos * 0.00392156; //슬라이더는 소숫점이 사용이 안됨

			pView->HotAirBalloon.sunsetred=dpos;//풍선 빨간색값을 바꿔줌
			pView->Invalidate(FALSE);
		}

		//green슬라이더 움직였을 경우
		else if(pScrollBar == (CScrollBar*)&mSunsetGreenS)//balloon green slider인경우
		{
			
			// 슬라이더의 위치를 검사한다.
 			int npos = mSunsetGreenS.GetPos(); //슬라이더 위치 얻어옴
			CString str;
			str.Format(_T("%d"), npos); //형변환
			mSunsetGreenValue.SetWindowTextA(str);// edit 박스에 슬라이더 값 들어감

			dpos = (double)npos * 0.00392156; //슬라이더는 소숫점이 사용이 안됨

			pView->HotAirBalloon.sunsetgreen=dpos; //풍선 녹색값을 바꿔줌
			pView->Invalidate(FALSE);
		}

	

		//blue 슬라이더 움직였을 경우
		else if(pScrollBar == (CScrollBar*)&mSunsetBlueS)//balloon green slider인경우
		{

			// 슬라이더의 위치를 검사한다.
			int npos = mSunsetBlueS.GetPos(); //슬라이더 위치 얻어옴
			CString str;
			str.Format(_T("%d"), npos); //형변환
			mSunsetBlueValue.SetWindowTextA(str); //blue edit 박스에 슬라이더 값 들어감

			dpos = (double)npos * 0.00392156; //슬라이더는 소숫점이 사용이 안됨

			pView->HotAirBalloon.sunsetblue=dpos; //풍선 파랑색값을 바꿔줌
			pView->Invalidate(FALSE);
		}

		//수직 슬라이더 움직였을 경우
		else if(pScrollBar == (CScrollBar*)&mSunsetVSlider)//수직 슬라이더인경우
		{

			// 슬라이더의 위치를 검사한다.
			int npos = mSunsetVSlider.GetPos(); //슬라이더 위치 얻어옴
			CString str;
			str.Format(_T("%d"), npos-50); //형변환
			mSunsetVEdit.SetWindowTextA(str); //edit 박스에 슬라이더 값 들어감

			
			if(npos <= 50){ //슬라이더가 50이하일때
				dpos = 2*(-0.5+((double)npos * 0.01)); //왼쪽으로 이동 
			} 
			else if(npos >= 50){  //슬라이더가 50이상일때
				dpos = 2*(((double)npos * 0.01)-0.5); //오른쪽으로 이동
			}

			pView->HotAirBalloon.sunsety=dpos; //balloony값을 바꿔줌
			pView->Invalidate(FALSE);
		}
		//수평 슬라이더 움직였을 경우
		else if(pScrollBar == (CScrollBar*)&mSunsetHSlider)//수평 슬라이더인경우
		{

			// 슬라이더의 위치를 검사한다.
			int npos = mSunsetHSlider.GetPos(); //슬라이더 위치 얻어옴
			
			CString str;
			str.Format(_T("%d"), npos-50); //형변환
			mSunsetHEdit.SetWindowTextA(str); //edit 박스에 슬라이더 값 들어감

			if(npos <= 50){ //슬라이더가 50이하일때
				dpos = 5*(-0.5+((double)npos * 0.01)); //위으로 이동 
				
			} 
			else if(npos >= 50){  //슬라이더가 50이상일때
				dpos = 5*(((double)npos * 0.01)-0.5); //아래쪽으로 이동
			}

			pView->HotAirBalloon.sunsetx=dpos; //balloonx값을 바꿔줌
			pView->Invalidate(FALSE);
		}

	CDialogEx::OnHScroll(nSBCode, nPos, pScrollBar);
	}
}

//RED edit
void CSunsetDlg::OnEnUpdateSunsetRedValue()
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

		mSunsetRedValue.GetWindowTextA(String);
		ipos = _ttoi(String);
		mSunsetRedS.SetPos(ipos);
		dpos = (double)ipos * 0.00392156; //슬라이더는 소숫점이 사용이 안됨

		pView->HotAirBalloon.sunsetred=dpos;//풍선 빨간색값을 바꿔줌
		pView->Invalidate(FALSE);
	}
}

//green edit
void CSunsetDlg::OnEnUpdateSunsetGreenValue()
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

		mSunsetGreenValue.GetWindowTextA(String);
		ipos = _ttoi(String);
		mSunsetGreenS.SetPos(ipos);
		dpos = (double)ipos * 0.00392156; //슬라이더는 소숫점이 사용이 안됨
		pView->HotAirBalloon.sunsetgreen=dpos;//풍선 빨간색값을 바꿔줌

		pView->Invalidate(FALSE);
	}
}

//blue edit
void CSunsetDlg::OnEnUpdateSunsetBlueValue()
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

		mSunsetBlueValue.GetWindowTextA(String);
		ipos = _ttoi(String);
		mSunsetBlueS.SetPos(ipos);
		dpos = (double)ipos * 0.00392156; //슬라이더는 소숫점이 사용이 안됨
		pView->HotAirBalloon.sunsetblue=dpos;//풍선 빨간색값을 바꿔줌

		pView->Invalidate(FALSE);
	}
}

//수평 edit
void CSunsetDlg::OnEnUpdateSunsetHEdit()
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

		mSunsetHEdit.GetWindowTextA(String);

		ipos = _ttoi(String)+50;
		mSunsetHSlider.SetPos(ipos);

		if(ipos <= 50){ //슬라이더가 50이하일때
		
			dpos = 5*(-0.5+((double)ipos * 0.01)); //왼쪽으로 이동 
			
		} 
		else if(ipos >= 50){  //슬라이더가 50이상일때
			dpos = 5*(((double)ipos * 0.01)-0.5); //오른쪽으로 이동
		}

		pView->HotAirBalloon.sunsetx=dpos; //balloony값을 바꿔줌
		pView->Invalidate(FALSE);
	}


}
//수직 Edit
void CSunsetDlg::OnEnUpdateSunsetVEdit()
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
		ipos = 0;

		mSunsetVEdit.GetWindowTextA(String);

		ipos = _ttoi(String)+50;

		mSunsetVSlider.SetPos(ipos);

		if(ipos <= 50){ //슬라이더가 50이하일때
		
			dpos = 2*(-0.5+((double)ipos * 0.01)); //왼쪽으로 이동 
			
		} 
		else if(ipos >= 50){  //슬라이더가 50이상일때
			dpos = 2*(((double)ipos * 0.01)-0.5); //오른쪽으로 이동
		}

		pView->HotAirBalloon.sunsety=dpos; //balloony값을 바꿔줌
		pView->Invalidate(FALSE);
	}
	
}

