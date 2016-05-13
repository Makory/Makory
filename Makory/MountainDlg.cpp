// EdittapCtrl.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "Makory.h"
#include "MountainDlg.h"
#include "afxdialogex.h"
#include "HotAirBalloon.h"
#include "MainFrm.h"
#include "MakoryDoc.h"
#include "MakoryView.h"

// CMountainlg 대화 상자입니다.

IMPLEMENT_DYNAMIC(CMountainDlg, CDialogEx)

CMountainDlg::CMountainDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMountainDlg::IDD, pParent)
{

}

CMountainDlg::~CMountainDlg()
{
}

void CMountainDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_MOUNTAIN_RED_SLIDER, mMountainRedS);
	DDX_Control(pDX, IDC_MOUNTAIN_GREEN_SLIDER, mMountainGreenS);
	DDX_Control(pDX, IDC_MOUNTAIN_BLUE_SLIDER, mMountainBlueS);
	DDX_Control(pDX, IDC_MOUNTAIN_VSCROLL, mMountainVSlider);
	DDX_Control(pDX, IDC_MOUNTAIN_HSCROOL, mMountainHSlider);
	DDX_Control(pDX, IDC_MOUNTAIN_RED_VALUE, mMountainRedValue);
	DDX_Control(pDX, IDC_MOUNTAIN_GREEN_VALUE, mMountainGreenValue);
	DDX_Control(pDX, IDC_MOUNTAIN_BLUE_VALUE, mMountainBlueValue);
	DDX_Control(pDX, IDC_MOUNTAIN_V_VALUE, mMountainVEdit);
	DDX_Control(pDX, IDC_MOUNTAIN_H_VALUE, mMountainHEdit);
}


BEGIN_MESSAGE_MAP(CMountainDlg, CDialogEx)
	ON_EN_CHANGE(IDC_EDIT1, &CMountainDlg::OnEnChangeEdit1)
	ON_WM_HSCROLL()
END_MESSAGE_MAP()


// CMountainlg 메시지 처리기입니다.

BOOL CMountainDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	//red 슬라이더
	mMountainRedS.SetPos(255);//슬라이더 처음 위치
	mMountainRedS.SetRange(0, 255); //슬라이더 범위 0 ~ 100으로 함.
	mMountainRedS.SetPageSize(10); //슬라이더를 클릭했을 때 움직이는 범위. 
	mMountainRedValue.SetWindowTextA("255");//red edit박스 초기값

	//green 슬라이더
	mMountainGreenS.SetPos(0);//슬라이더 처음 위치
	mMountainGreenS.SetRange(0, 255); //슬라이더 범위 0 ~ 100으로 함.
	mMountainGreenS.SetPageSize(10);  //슬라이더를 클릭했을 때 움직이는 범위
	mMountainGreenValue.SetWindowTextA("0");//green edit박스 초기값

	//blue 슬라이더
	mMountainBlueS.SetPos(0);//슬라이더 처음 위치
	mMountainBlueS.SetRange(0, 255); //슬라이더 범위 0 ~ 100으로 함.
	mMountainBlueS.SetPageSize(10);  //슬라이더를 클릭했을 때 움직이는 범위
	mMountainBlueValue.SetWindowTextA("0");//blue edit박스 초기값

	//수직슬라이더
	mMountainVSlider.SetPos(50);//슬라이더 처음 위치
	mMountainVSlider.SetRange(0, 100); //슬라이더 범위 0 ~ 100으로 함.
	mMountainVSlider.SetPageSize(1);  //슬라이더를 클릭했을 때 움직이는 범위
	mMountainVEdit.SetWindowTextA("0");//v edit박스 초기값

	//수평슬라이더
	mMountainHSlider.SetPos(50);//슬라이더 처음 위치
	mMountainHSlider.SetRange(0, 100); //슬라이더 범위 0 ~ 100으로 함.
	mMountainHSlider.SetPageSize(1);  //슬라이더를 클릭했을 때 움직이는 범위
	mMountainHEdit.SetWindowTextA("0");//h edit박스 초기값


	return TRUE;  // return TRUE unless you set the focus to a control
	// 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}
void CMountainDlg::OnEnChangeEdit1()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CDialogEx::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CMountainDlg::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	CMainFrame* pFrame = (CMainFrame*)AfxGetMainWnd();				//View호출
	CMakoryView* pView = (CMakoryView*)pFrame->GetActiveView();		//View호출

	if(pScrollBar)
	{
		// 어떤 슬라이더인지 검사
		//red slider가 움직였을 경우
		if(pScrollBar == (CScrollBar*)&mMountainRedS)//balloon red slider인경우
		{
			
			// 슬라이더의 위치를 검사한다.
 			int npos = mMountainRedS.GetPos(); //슬라이더 위치 얻어옴
			CString str;
			str.Format(_T("%d"), npos); //형변환
			mMountainRedValue.SetWindowTextA(str); //edit 박스에 슬라이더 값 들어감

			dpos = (double)npos * 0.00392156; //슬라이더는 소숫점이 사용이 안됨

			pView->HotAirBalloon.mountred=dpos;//풍선 빨간색값을 바꿔줌
			pView->Invalidate(FALSE);
		}

		//green슬라이더 움직였을 경우
		else if(pScrollBar == (CScrollBar*)&mMountainGreenS)//balloon green slider인경우
		{
			
			// 슬라이더의 위치를 검사한다.
 			int npos = mMountainGreenS.GetPos(); //슬라이더 위치 얻어옴
			CString str;
			str.Format(_T("%d"), npos); //형변환
			mMountainGreenValue.SetWindowTextA(str);// edit 박스에 슬라이더 값 들어감

			dpos = (double)npos * 0.00392156; //슬라이더는 소숫점이 사용이 안됨

			pView->HotAirBalloon.mountgreen=dpos; //풍선 녹색값을 바꿔줌
			pView->Invalidate(FALSE);
		}

	

		//blue 슬라이더 움직였을 경우
		else if(pScrollBar == (CScrollBar*)&mMountainBlueS)//balloon green slider인경우
		{

			// 슬라이더의 위치를 검사한다.
			int npos = mMountainBlueS.GetPos(); //슬라이더 위치 얻어옴
			CString str;
			str.Format(_T("%d"), npos); //형변환
			mMountainBlueValue.SetWindowTextA(str); //blue edit 박스에 슬라이더 값 들어감

			dpos = (double)npos * 0.00392156; //슬라이더는 소숫점이 사용이 안됨

			pView->HotAirBalloon.mountblue=dpos; //풍선 파랑색값을 바꿔줌
			pView->Invalidate(FALSE);
		}

		//수직 슬라이더 움직였을 경우
		else if(pScrollBar == (CScrollBar*)&mMountainVSlider)//수직 슬라이더인경우
		{

			// 슬라이더의 위치를 검사한다.
			int npos = mMountainVSlider.GetPos(); //슬라이더 위치 얻어옴
			CString str;
			str.Format(_T("%d"), npos-50); //형변환
			mMountainVEdit.SetWindowTextA(str); //edit 박스에 슬라이더 값 들어감

			
			if(npos <= 50){ //슬라이더가 50이하일때
				dpos = -0.5+((double)npos * 0.01); //왼쪽으로 이동 
			} 
			else if(npos >= 50){  //슬라이더가 50이상일때
				dpos = ((double)npos * 0.01)-0.5; //오른쪽으로 이동
			}

			pView->HotAirBalloon.mounty=dpos; //balloony값을 바꿔줌
			pView->Invalidate(FALSE);
		}
		//수평 슬라이더 움직였을 경우
		else if(pScrollBar == (CScrollBar*)&mMountainHSlider)//수평 슬라이더인경우
		{

			// 슬라이더의 위치를 검사한다.
			int npos = mMountainHSlider.GetPos(); //슬라이더 위치 얻어옴
			
			CString str;
			str.Format(_T("%d"), npos-50); //형변환
			mMountainHEdit.SetWindowTextA(str); //edit 박스에 슬라이더 값 들어감

			if(npos <= 50){ //슬라이더가 50이하일때
				dpos = -0.5+((double)npos * 0.01); //위으로 이동 
				
			} 
			else if(npos >= 50){  //슬라이더가 50이상일때
				dpos = ((double)npos * 0.01)-0.5; //아래쪽으로 이동
			}

			pView->HotAirBalloon.mountx=dpos; //balloonx값을 바꿔줌
			pView->Invalidate(FALSE);
		}

	CDialogEx::OnHScroll(nSBCode, nPos, pScrollBar);
	}
}