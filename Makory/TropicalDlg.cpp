// EdittapCtrl.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "Makory.h"
#include "TropicalDlg.h"
#include "afxdialogex.h"
#include "HotAirBalloon.h"
#include "MainFrm.h"
#include "MakoryDoc.h"
#include "MakoryView.h"

// CTropicallg 대화 상자입니다.

IMPLEMENT_DYNAMIC(CTropicalDlg, CDialogEx)

CTropicalDlg::CTropicalDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CTropicalDlg::IDD, pParent)
{

}

CTropicalDlg::~CTropicalDlg()
{
}

void CTropicalDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TROPICAL_RED_SLIDER, mTropicalRedS);
	DDX_Control(pDX, IDC_TROPICAL_GREEN_SLIDER, mTropicalGreenS);
	DDX_Control(pDX, IDC_TROPICAL_BLUE_SLIDER, mTropicalBlueS);
	DDX_Control(pDX, IDC_TROPICAL_VSCROLL, mTropicalVSlider);
	DDX_Control(pDX, IDC_TROPICAL_HSCROOL, mTropicalHSlider);
	DDX_Control(pDX, IDC_TROPICAL_RED_VALUE, mTropicalRedValue);
	DDX_Control(pDX, IDC_TROPICAL_GREEN_VALUE, mTropicalGreenValue);
	DDX_Control(pDX, IDC_TROPICAL_BLUE_VALUE, mTropicalBlueValue);
	DDX_Control(pDX, IDC_TROPICAL_V_VALUE, mTropicalVEdit);
	DDX_Control(pDX, IDC_TROPICAL_H_VALUE, mTropicalHEdit);
}


BEGIN_MESSAGE_MAP(CTropicalDlg, CDialogEx)
	ON_EN_CHANGE(IDC_EDIT1, &CTropicalDlg::OnEnChangeEdit1)
	ON_WM_HSCROLL()
END_MESSAGE_MAP()


// CTropicallg 메시지 처리기입니다.

BOOL CTropicalDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	//red 슬라이더
	mTropicalRedS.SetPos(255);//슬라이더 처음 위치
	mTropicalRedS.SetRange(0, 255); //슬라이더 범위 0 ~ 100으로 함.
	mTropicalRedS.SetPageSize(10); //슬라이더를 클릭했을 때 움직이는 범위. 
	mTropicalRedValue.SetWindowTextA("255");//red edit박스 초기값

	//green 슬라이더
	mTropicalGreenS.SetPos(0);//슬라이더 처음 위치
	mTropicalGreenS.SetRange(0, 255); //슬라이더 범위 0 ~ 100으로 함.
	mTropicalGreenS.SetPageSize(10);  //슬라이더를 클릭했을 때 움직이는 범위
	mTropicalGreenValue.SetWindowTextA("0");//green edit박스 초기값

	//blue 슬라이더
	mTropicalBlueS.SetPos(0);//슬라이더 처음 위치
	mTropicalBlueS.SetRange(0, 255); //슬라이더 범위 0 ~ 100으로 함.
	mTropicalBlueS.SetPageSize(10);  //슬라이더를 클릭했을 때 움직이는 범위
	mTropicalBlueValue.SetWindowTextA("0");//blue edit박스 초기값

	//수직슬라이더
	mTropicalVSlider.SetPos(50);//슬라이더 처음 위치
	mTropicalVSlider.SetRange(0, 100); //슬라이더 범위 0 ~ 100으로 함.
	mTropicalVSlider.SetPageSize(1);  //슬라이더를 클릭했을 때 움직이는 범위
	mTropicalVEdit.SetWindowTextA("0");//v edit박스 초기값

	//수평슬라이더
	mTropicalHSlider.SetPos(50);//슬라이더 처음 위치
	mTropicalHSlider.SetRange(0, 100); //슬라이더 범위 0 ~ 100으로 함.
	mTropicalHSlider.SetPageSize(1);  //슬라이더를 클릭했을 때 움직이는 범위
	mTropicalHEdit.SetWindowTextA("0");//h edit박스 초기값


	return TRUE;  // return TRUE unless you set the focus to a control
	// 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}
void CTropicalDlg::OnEnChangeEdit1()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CDialogEx::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CTropicalDlg::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	CMainFrame* pFrame = (CMainFrame*)AfxGetMainWnd();				//View호출
	CMakoryView* pView = (CMakoryView*)pFrame->GetActiveView();		//View호출

	if(pScrollBar)
	{
		// 어떤 슬라이더인지 검사
		//red slider가 움직였을 경우
		if(pScrollBar == (CScrollBar*)&mTropicalRedS)//balloon red slider인경우
		{
			
			// 슬라이더의 위치를 검사한다.
 			int npos = mTropicalRedS.GetPos(); //슬라이더 위치 얻어옴
			CString str;
			str.Format(_T("%d"), npos); //형변환
			mTropicalRedValue.SetWindowTextA(str); //edit 박스에 슬라이더 값 들어감

			dpos = (double)npos * 0.00392156; //슬라이더는 소숫점이 사용이 안됨

			pView->HotAirBalloon.tropicalred=dpos;//풍선 빨간색값을 바꿔줌
			pView->Invalidate(FALSE);
		}

		//green슬라이더 움직였을 경우
		else if(pScrollBar == (CScrollBar*)&mTropicalGreenS)//balloon green slider인경우
		{
			
			// 슬라이더의 위치를 검사한다.
 			int npos = mTropicalGreenS.GetPos(); //슬라이더 위치 얻어옴
			CString str;
			str.Format(_T("%d"), npos); //형변환
			mTropicalGreenValue.SetWindowTextA(str);// edit 박스에 슬라이더 값 들어감

			dpos = (double)npos * 0.00392156; //슬라이더는 소숫점이 사용이 안됨

			pView->HotAirBalloon.tropicalgreen=dpos; //풍선 녹색값을 바꿔줌
			pView->Invalidate(FALSE);
		}

	

		//blue 슬라이더 움직였을 경우
		else if(pScrollBar == (CScrollBar*)&mTropicalBlueS)//balloon green slider인경우
		{

			// 슬라이더의 위치를 검사한다.
			int npos = mTropicalBlueS.GetPos(); //슬라이더 위치 얻어옴
			CString str;
			str.Format(_T("%d"), npos); //형변환
			mTropicalBlueValue.SetWindowTextA(str); //blue edit 박스에 슬라이더 값 들어감

			dpos = (double)npos * 0.00392156; //슬라이더는 소숫점이 사용이 안됨

			pView->HotAirBalloon.tropicalblue=dpos; //풍선 파랑색값을 바꿔줌
			pView->Invalidate(FALSE);
		}

		//수직 슬라이더 움직였을 경우
		else if(pScrollBar == (CScrollBar*)&mTropicalVSlider)//수직 슬라이더인경우
		{

			// 슬라이더의 위치를 검사한다.
			int npos = mTropicalVSlider.GetPos(); //슬라이더 위치 얻어옴
			CString str;
			str.Format(_T("%d"), npos-50); //형변환
			mTropicalVEdit.SetWindowTextA(str); //edit 박스에 슬라이더 값 들어감

			
			if(npos <= 50){ //슬라이더가 50이하일때
				dpos = -0.5+((double)npos * 0.01); //왼쪽으로 이동 
			} 
			else if(npos >= 50){  //슬라이더가 50이상일때
				dpos = ((double)npos * 0.01)-0.5; //오른쪽으로 이동
			}

			pView->HotAirBalloon.tropicaly=dpos; //balloony값을 바꿔줌
			pView->Invalidate(FALSE);
		}
		//수평 슬라이더 움직였을 경우
		else if(pScrollBar == (CScrollBar*)&mTropicalHSlider)//수평 슬라이더인경우
		{

			// 슬라이더의 위치를 검사한다.
			int npos = mTropicalHSlider.GetPos(); //슬라이더 위치 얻어옴
			
			CString str;
			str.Format(_T("%d"), npos-50); //형변환
			mTropicalHEdit.SetWindowTextA(str); //edit 박스에 슬라이더 값 들어감

			if(npos <= 50){ //슬라이더가 50이하일때
				dpos = -0.5+((double)npos * 0.01); //위으로 이동 
				
			} 
			else if(npos >= 50){  //슬라이더가 50이상일때
				dpos = ((double)npos * 0.01)-0.5; //아래쪽으로 이동
			}

			pView->HotAirBalloon.tropicalx=dpos; //balloonx값을 바꿔줌
			pView->Invalidate(FALSE);
		}

	CDialogEx::OnHScroll(nSBCode, nPos, pScrollBar);
	}
}