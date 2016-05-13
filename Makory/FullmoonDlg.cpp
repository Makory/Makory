// EdittapCtrl.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "Makory.h"
#include "FullmoonDlg.h"
#include "afxdialogex.h"
#include "HotAirBalloon.h"
#include "MainFrm.h"
#include "MakoryDoc.h"
#include "MakoryView.h"

// CFullmoonDlg 대화 상자입니다.

IMPLEMENT_DYNAMIC(CFullmoonDlg, CDialogEx)

CFullmoonDlg::CFullmoonDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CFullmoonDlg::IDD, pParent)
{

}

CFullmoonDlg::~CFullmoonDlg()
{
}

void CFullmoonDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_FULLMOON_RED_SLIDER, mFullmoonRedS);
	DDX_Control(pDX, IDC_FULLMOON_GREEN_SLIDER, mFullmoonGreenS);
	DDX_Control(pDX, IDC_FULLMOON_BLUE_SLIDER, mFullmoonBlueS);
	DDX_Control(pDX, IDC_FULLMOON_VSCROLL, mFullmoonVSlider);
	DDX_Control(pDX, IDC_FULLMOON_HSCROOL, mFullmoonHSlider);
	DDX_Control(pDX, IDC_FULLMOON_RED_VALUE, mFullmoonRedValue);
	DDX_Control(pDX, IDC_FULLMOON_GREEN_VALUE, mFullmoonGreenValue);
	DDX_Control(pDX, IDC_FULLMOON_BLUE_VALUE, mFullmoonBlueValue);
	DDX_Control(pDX, IDC_FULLMOON_V_VALUE, mFullmoonVEdit);
	DDX_Control(pDX, IDC_FULLMOON_H_VALUE, mFullmoonHEdit);
}


BEGIN_MESSAGE_MAP(CFullmoonDlg, CDialogEx)
	ON_EN_CHANGE(IDC_EDIT1, &CFullmoonDlg::OnEnChangeEdit1)
	ON_WM_HSCROLL()
END_MESSAGE_MAP()


// CFullmoonDlg 메시지 처리기입니다.

BOOL CFullmoonDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	//red 슬라이더
	mFullmoonRedS.SetPos(255);//슬라이더 처음 위치
	mFullmoonRedS.SetRange(0, 255); //슬라이더 범위 0 ~ 100으로 함.
	mFullmoonRedS.SetPageSize(10); //슬라이더를 클릭했을 때 움직이는 범위. 
	mFullmoonRedValue.SetWindowTextA("255");//red edit박스 초기값

	//green 슬라이더
	mFullmoonGreenS.SetPos(0);//슬라이더 처음 위치
	mFullmoonGreenS.SetRange(0, 255); //슬라이더 범위 0 ~ 100으로 함.
	mFullmoonGreenS.SetPageSize(10);  //슬라이더를 클릭했을 때 움직이는 범위
	mFullmoonGreenValue.SetWindowTextA("0");//green edit박스 초기값

	//blue 슬라이더
	mFullmoonBlueS.SetPos(0);//슬라이더 처음 위치
	mFullmoonBlueS.SetRange(0, 255); //슬라이더 범위 0 ~ 100으로 함.
	mFullmoonBlueS.SetPageSize(10);  //슬라이더를 클릭했을 때 움직이는 범위
	mFullmoonBlueValue.SetWindowTextA("0");//blue edit박스 초기값

	//수직슬라이더
	mFullmoonVSlider.SetPos(50);//슬라이더 처음 위치
	mFullmoonVSlider.SetRange(0, 100); //슬라이더 범위 0 ~ 100으로 함.
	mFullmoonVSlider.SetPageSize(1);  //슬라이더를 클릭했을 때 움직이는 범위
	mFullmoonVEdit.SetWindowTextA("0");//v edit박스 초기값

	//수평슬라이더
	mFullmoonHSlider.SetPos(50);//슬라이더 처음 위치
	mFullmoonHSlider.SetRange(0, 100); //슬라이더 범위 0 ~ 100으로 함.
	mFullmoonHSlider.SetPageSize(1);  //슬라이더를 클릭했을 때 움직이는 범위
	mFullmoonHEdit.SetWindowTextA("0");//h edit박스 초기값


	return TRUE;  // return TRUE unless you set the focus to a control
	// 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}
void CFullmoonDlg::OnEnChangeEdit1()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CDialogEx::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CFullmoonDlg::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	CMainFrame* pFrame = (CMainFrame*)AfxGetMainWnd();				//View호출
	CMakoryView* pView = (CMakoryView*)pFrame->GetActiveView();		//View호출

	if(pScrollBar)
	{
		// 어떤 슬라이더인지 검사
		//red slider가 움직였을 경우
		if(pScrollBar == (CScrollBar*)&mFullmoonRedS)//balloon red slider인경우
		{
			
			// 슬라이더의 위치를 검사한다.
 			int npos = mFullmoonRedS.GetPos(); //슬라이더 위치 얻어옴
			CString str;
			str.Format(_T("%d"), npos); //형변환
			mFullmoonRedValue.SetWindowTextA(str); //edit 박스에 슬라이더 값 들어감

			dpos = (double)npos * 0.00392156; //슬라이더는 소숫점이 사용이 안됨

			pView->HotAirBalloon.fullmoonred=dpos;//풍선 빨간색값을 바꿔줌
			pView->Invalidate(FALSE);
		}

		//green슬라이더 움직였을 경우
		else if(pScrollBar == (CScrollBar*)&mFullmoonGreenS)//balloon green slider인경우
		{
			
			// 슬라이더의 위치를 검사한다.
 			int npos = mFullmoonGreenS.GetPos(); //슬라이더 위치 얻어옴
			CString str;
			str.Format(_T("%d"), npos); //형변환
			mFullmoonGreenValue.SetWindowTextA(str);// edit 박스에 슬라이더 값 들어감

			dpos = (double)npos * 0.00392156; //슬라이더는 소숫점이 사용이 안됨

			pView->HotAirBalloon.fullmoongreen=dpos; //풍선 녹색값을 바꿔줌
			pView->Invalidate(FALSE);
		}

	

		//blue 슬라이더 움직였을 경우
		else if(pScrollBar == (CScrollBar*)&mFullmoonBlueS)//balloon green slider인경우
		{

			// 슬라이더의 위치를 검사한다.
			int npos = mFullmoonBlueS.GetPos(); //슬라이더 위치 얻어옴
			CString str;
			str.Format(_T("%d"), npos); //형변환
			mFullmoonBlueValue.SetWindowTextA(str); //blue edit 박스에 슬라이더 값 들어감

			dpos = (double)npos * 0.00392156; //슬라이더는 소숫점이 사용이 안됨

			pView->HotAirBalloon.fullmoonblue=dpos; //풍선 파랑색값을 바꿔줌
			pView->Invalidate(FALSE);
		}

		//수직 슬라이더 움직였을 경우
		else if(pScrollBar == (CScrollBar*)&mFullmoonVSlider)//수직 슬라이더인경우
		{

			// 슬라이더의 위치를 검사한다.
			int npos = mFullmoonVSlider.GetPos(); //슬라이더 위치 얻어옴
			CString str;
			str.Format(_T("%d"), npos-50); //형변환
			mFullmoonVEdit.SetWindowTextA(str); //edit 박스에 슬라이더 값 들어감

			
			if(npos <= 50){ //슬라이더가 50이하일때
				dpos = -0.5+((double)npos * 0.01); //왼쪽으로 이동 
			} 
			else if(npos >= 50){  //슬라이더가 50이상일때
				dpos = ((double)npos * 0.01)-0.5; //오른쪽으로 이동
			}

			pView->HotAirBalloon.fullmoony=dpos; //balloony값을 바꿔줌
			pView->Invalidate(FALSE);
		}
		//수평 슬라이더 움직였을 경우
		else if(pScrollBar == (CScrollBar*)&mFullmoonHSlider)//수평 슬라이더인경우
		{

			// 슬라이더의 위치를 검사한다.
			int npos = mFullmoonHSlider.GetPos(); //슬라이더 위치 얻어옴
			
			CString str;
			str.Format(_T("%d"), npos-50); //형변환
			mFullmoonHEdit.SetWindowTextA(str); //edit 박스에 슬라이더 값 들어감

			if(npos <= 50){ //슬라이더가 50이하일때
				dpos = -0.5+((double)npos * 0.01); //위으로 이동 
				
			} 
			else if(npos >= 50){  //슬라이더가 50이상일때
				dpos = ((double)npos * 0.01)-0.5; //아래쪽으로 이동
			}

			pView->HotAirBalloon.fullmoonx=dpos; //balloonx값을 바꿔줌
			pView->Invalidate(FALSE);
		}

	CDialogEx::OnHScroll(nSBCode, nPos, pScrollBar);
	}
}