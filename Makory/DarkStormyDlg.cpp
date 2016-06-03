// EdittapCtrl.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "Makory.h"
#include "DarkStormyDlg.h"
#include "afxdialogex.h"
#include "HotAirBalloon.h"
#include "MainFrm.h"
#include "MakoryDoc.h"
#include "MakoryView.h"

// CDarkStormyDlg 대화 상자입니다.

IMPLEMENT_DYNAMIC(CDarkStormyDlg, CDialogEx)

CDarkStormyDlg::CDarkStormyDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDarkStormyDlg::IDD, pParent)
{

}

CDarkStormyDlg::~CDarkStormyDlg()
{
}

void CDarkStormyDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_DARKSTORMY_RED_SLIDER, mDarkStormyRedS);
	DDX_Control(pDX, IDC_DARKSTORMY_GREEN_SLIDER, mDarkStormyGreenS);
	DDX_Control(pDX, IDC_DARKSTORMY_BLUE_SLIDER, mDarkStormyBlueS);
	DDX_Control(pDX, IDC_DARKSTORMY_VSCROLL, mDarkStormyVSlider);
	DDX_Control(pDX, IDC_DARKSTORMY_HSCROOL, mDarkStormyHSlider);
	DDX_Control(pDX, IDC_DARKSTORMY_RED_VALUE, mDarkStormyRedValue);
	DDX_Control(pDX, IDC_DARKSTORMY_GREEN_VALUE, mDarkStormyGreenValue);
	DDX_Control(pDX, IDC_DARKSTORMY_BLUE_VALUE, mDarkStormyBlueValue);
	DDX_Control(pDX, IDC_DARKSTORMY_V_VALUE, mDarkStormyVEdit);
	DDX_Control(pDX, IDC_DARKSTORMY_H_VALUE, mDarkStormyHEdit);
}


BEGIN_MESSAGE_MAP(CDarkStormyDlg, CDialogEx)
	ON_WM_HSCROLL()
	ON_EN_UPDATE(IDC_DARKSTORMY_RED_VALUE, &CDarkStormyDlg::OnEnUpdateDarkStormyRedValue)
	ON_EN_UPDATE(IDC_DARKSTORMY_GREEN_VALUE, &CDarkStormyDlg::OnEnUpdateDarkStormyGreenValue)
	ON_EN_UPDATE(IDC_DARKSTORMY_BLUE_VALUE, &CDarkStormyDlg::OnEnUpdateDarkStormyBlueValue)
	ON_EN_UPDATE(IDC_DARKSTORMY_V_VALUE, &CDarkStormyDlg::OnEnUpdateDarkStormyVEdit)
	ON_EN_UPDATE(IDC_DARKSTORMY_H_VALUE, &CDarkStormyDlg::OnEnUpdateDarkStormyHEdit)
END_MESSAGE_MAP()


// CDarkStormyDlg 메시지 처리기입니다.

BOOL CDarkStormyDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	//red 슬라이더
	mDarkStormyRedS.SetPos(255);//슬라이더 처음 위치
	mDarkStormyRedS.SetRange(0, 255); //슬라이더 범위 0 ~ 100으로 함.
	mDarkStormyRedS.SetPageSize(10); //슬라이더를 클릭했을 때 움직이는 범위. 
	mDarkStormyRedValue.SetWindowTextA("255");//red edit박스 초기값

	//green 슬라이더
	mDarkStormyGreenS.SetPos(0);//슬라이더 처음 위치
	mDarkStormyGreenS.SetRange(0, 255); //슬라이더 범위 0 ~ 100으로 함.
	mDarkStormyGreenS.SetPageSize(10);  //슬라이더를 클릭했을 때 움직이는 범위
	mDarkStormyGreenValue.SetWindowTextA("0");//green edit박스 초기값

	//blue 슬라이더
	mDarkStormyBlueS.SetPos(0);//슬라이더 처음 위치
	mDarkStormyBlueS.SetRange(0, 255); //슬라이더 범위 0 ~ 100으로 함.
	mDarkStormyBlueS.SetPageSize(10);  //슬라이더를 클릭했을 때 움직이는 범위
	mDarkStormyBlueValue.SetWindowTextA("0");//blue edit박스 초기값

	//수직슬라이더
	mDarkStormyVSlider.SetPos(50);//슬라이더 처음 위치
	mDarkStormyVSlider.SetRange(0, 100); //슬라이더 범위 0 ~ 100으로 함.
	mDarkStormyVSlider.SetPageSize(1);  //슬라이더를 클릭했을 때 움직이는 범위
	mDarkStormyVEdit.SetWindowTextA("0");//v edit박스 초기값

	//수평슬라이더
	mDarkStormyHSlider.SetPos(50);//슬라이더 처음 위치
	mDarkStormyHSlider.SetRange(0, 100); //슬라이더 범위 0 ~ 100으로 함.
	mDarkStormyHSlider.SetPageSize(1);  //슬라이더를 클릭했을 때 움직이는 범위
	mDarkStormyHEdit.SetWindowTextA("0");//h edit박스 초기값


	return TRUE;  // return TRUE unless you set the focus to a control
	// 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}

void CDarkStormyDlg::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	CMainFrame* pFrame = (CMainFrame*)AfxGetMainWnd();				//View호출
	CMakoryView* pView = (CMakoryView*)pFrame->GetActiveView();		//View호출

	if(pScrollBar)
	{
		// 어떤 슬라이더인지 검사
		//red slider가 움직였을 경우
		if(pScrollBar == (CScrollBar*)&mDarkStormyRedS)//balloon red slider인경우
		{
			
			// 슬라이더의 위치를 검사한다.
 			int npos = mDarkStormyRedS.GetPos(); //슬라이더 위치 얻어옴
			CString str;
			str.Format(_T("%d"), npos); //형변환
			mDarkStormyRedValue.SetWindowTextA(str); //edit 박스에 슬라이더 값 들어감

			dpos = (double)npos * 0.00392156; //슬라이더는 소숫점이 사용이 안됨

			pView->HotAirBalloon.darkstormyred=dpos;//풍선 빨간색값을 바꿔줌
			pView->Invalidate(FALSE);
		}

		//green슬라이더 움직였을 경우
		else if(pScrollBar == (CScrollBar*)&mDarkStormyGreenS)//balloon green slider인경우
		{
			
			// 슬라이더의 위치를 검사한다.
 			int npos = mDarkStormyGreenS.GetPos(); //슬라이더 위치 얻어옴
			CString str;
			str.Format(_T("%d"), npos); //형변환
			mDarkStormyGreenValue.SetWindowTextA(str);// edit 박스에 슬라이더 값 들어감

			dpos = (double)npos * 0.00392156; //슬라이더는 소숫점이 사용이 안됨

			pView->HotAirBalloon.darkstormygreen=dpos; //풍선 녹색값을 바꿔줌
			pView->Invalidate(FALSE);
		}

	

		//blue 슬라이더 움직였을 경우
		else if(pScrollBar == (CScrollBar*)&mDarkStormyBlueS)//balloon green slider인경우
		{

			// 슬라이더의 위치를 검사한다.
			int npos = mDarkStormyBlueS.GetPos(); //슬라이더 위치 얻어옴
			CString str;
			str.Format(_T("%d"), npos); //형변환
			mDarkStormyBlueValue.SetWindowTextA(str); //blue edit 박스에 슬라이더 값 들어감

			dpos = (double)npos * 0.00392156; //슬라이더는 소숫점이 사용이 안됨

			pView->HotAirBalloon.darkstormyblue=dpos; //풍선 파랑색값을 바꿔줌
			pView->Invalidate(FALSE);
		}

		//수직 슬라이더 움직였을 경우
		else if(pScrollBar == (CScrollBar*)&mDarkStormyVSlider)//수직 슬라이더인경우
		{

			// 슬라이더의 위치를 검사한다.
			int npos = mDarkStormyVSlider.GetPos(); //슬라이더 위치 얻어옴
			CString str;
			str.Format(_T("%d"), npos-50); //형변환
			mDarkStormyVEdit.SetWindowTextA(str); //edit 박스에 슬라이더 값 들어감

			
			if(npos <= 50){ //슬라이더가 50이하일때
				dpos = 2*(-0.5+((double)npos * 0.01)); //왼쪽으로 이동 
			} 
			else if(npos >= 50){  //슬라이더가 50이상일때
				dpos = 2*(((double)npos * 0.01)-0.5); //오른쪽으로 이동
			}

			pView->HotAirBalloon.darkstormyy=dpos; //balloony값을 바꿔줌
			pView->Invalidate(FALSE);
		}
		//수평 슬라이더 움직였을 경우
		else if(pScrollBar == (CScrollBar*)&mDarkStormyHSlider)//수평 슬라이더인경우
		{

			// 슬라이더의 위치를 검사한다.
			int npos = mDarkStormyHSlider.GetPos(); //슬라이더 위치 얻어옴
			
			CString str;
			str.Format(_T("%d"), npos-50); //형변환
			mDarkStormyHEdit.SetWindowTextA(str); //edit 박스에 슬라이더 값 들어감

			if(npos <= 50){ //슬라이더가 50이하일때
				dpos = 5*(-0.5+((double)npos * 0.01)); //위으로 이동 
				
			} 
			else if(npos >= 50){  //슬라이더가 50이상일때
				dpos = 5*(((double)npos * 0.01)-0.5); //아래쪽으로 이동
			}

			pView->HotAirBalloon.darkstormyx=dpos; //balloonx값을 바꿔줌
			pView->Invalidate(FALSE);
		}

	CDialogEx::OnHScroll(nSBCode, nPos, pScrollBar);
	}
}

//RED edit
void CDarkStormyDlg::OnEnUpdateDarkStormyRedValue()
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

		mDarkStormyRedValue.GetWindowTextA(String);
		ipos = _ttoi(String);
		mDarkStormyRedS.SetPos(ipos);
		dpos = (double)ipos * 0.00392156; //슬라이더는 소숫점이 사용이 안됨

		pView->HotAirBalloon.darkstormyred=dpos;//풍선 빨간색값을 바꿔줌
		pView->Invalidate(FALSE);
	}
}

//green edit
void CDarkStormyDlg::OnEnUpdateDarkStormyGreenValue()
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

		mDarkStormyGreenValue.GetWindowTextA(String);
		ipos = _ttoi(String);
		mDarkStormyGreenS.SetPos(ipos);
		dpos = (double)ipos * 0.00392156; //슬라이더는 소숫점이 사용이 안됨
		pView->HotAirBalloon.darkstormygreen=dpos;//풍선 빨간색값을 바꿔줌

		pView->Invalidate(FALSE);
	}
}

//blue edit
void CDarkStormyDlg::OnEnUpdateDarkStormyBlueValue()
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

		mDarkStormyBlueValue.GetWindowTextA(String);
		ipos = _ttoi(String);
		mDarkStormyBlueS.SetPos(ipos);
		dpos = (double)ipos * 0.00392156; //슬라이더는 소숫점이 사용이 안됨
		pView->HotAirBalloon.darkstormyblue=dpos;//풍선 빨간색값을 바꿔줌

		pView->Invalidate(FALSE);
	}
}

//수평 edit
void CDarkStormyDlg::OnEnUpdateDarkStormyHEdit()
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

		mDarkStormyHEdit.GetWindowTextA(String);

		ipos = _ttoi(String)+50;
		mDarkStormyHSlider.SetPos(ipos);

		if(ipos <= 50){ //슬라이더가 50이하일때
		
			dpos = 5*( -0.5+((double)ipos * 0.01)); //왼쪽으로 이동 
			
		} 
		else if(ipos >= 50){  //슬라이더가 50이상일때
			dpos = 5*(((double)ipos * 0.01)-0.5); //오른쪽으로 이동
		}

		pView->HotAirBalloon.darkstormyx=dpos; //balloony값을 바꿔줌
		pView->Invalidate(FALSE);
	}


}
//수직 Edit
void CDarkStormyDlg::OnEnUpdateDarkStormyVEdit()
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

		mDarkStormyVEdit.GetWindowTextA(String);

		ipos = _ttoi(String)+50;

		mDarkStormyVSlider.SetPos(ipos);

		if(ipos <= 50){ //슬라이더가 50이하일때
		
			dpos = 2*(-0.5+((double)ipos * 0.01)); //왼쪽으로 이동 
			
		} 
		else if(ipos >= 50){  //슬라이더가 50이상일때
			dpos = 2*(((double)ipos * 0.01)-0.5); //오른쪽으로 이동
		}

		pView->HotAirBalloon.darkstormyy=dpos; //balloony값을 바꿔줌
		pView->Invalidate(FALSE);
	}
	
}