// EdittapCtrl.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "Makory.h"
#include "CloudsDlg.h"
#include "afxdialogex.h"
#include "HotAirBalloon.h"
#include "MainFrm.h"
#include "MakoryDoc.h"
#include "MakoryView.h"

// CCloudslg 대화 상자입니다.

IMPLEMENT_DYNAMIC(CCloudsDlg, CDialogEx)

CCloudsDlg::CCloudsDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CCloudsDlg::IDD, pParent)
{

}

CCloudsDlg::~CCloudsDlg()
{
}

void CCloudsDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_CLOUDS_RED_SLIDER, mCloudsRedS);
	DDX_Control(pDX, IDC_CLOUDS_GREEN_SLIDER, mCloudsGreenS);
	DDX_Control(pDX, IDC_CLOUDS_BLUE_SLIDER, mCloudsBlueS);
	DDX_Control(pDX, IDC_CLOUDS_VSCROLL, mCloudsVSlider);
	DDX_Control(pDX, IDC_CLOUDS_HSCROOL, mCloudsHSlider);
	DDX_Control(pDX, IDC_CLOUDS_RED_VALUE, mCloudsRedValue);
	DDX_Control(pDX, IDC_CLOUDS_GREEN_VALUE, mCloudsGreenValue);
	DDX_Control(pDX, IDC_CLOUDS_BLUE_VALUE, mCloudsBlueValue);
	DDX_Control(pDX, IDC_CLOUDS_V_VALUE, mCloudsVEdit);
	DDX_Control(pDX, IDC_CLOUDS_H_VALUE, mCloudsHEdit);
}


BEGIN_MESSAGE_MAP(CCloudsDlg, CDialogEx)
	ON_EN_CHANGE(IDC_EDIT1, &CCloudsDlg::OnEnChangeEdit1)
	ON_WM_HSCROLL()
END_MESSAGE_MAP()


// CCloudslg 메시지 처리기입니다.

BOOL CCloudsDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	//red 슬라이더
	mCloudsRedS.SetPos(255);//슬라이더 처음 위치
	mCloudsRedS.SetRange(0, 255); //슬라이더 범위 0 ~ 100으로 함.
	mCloudsRedS.SetPageSize(10); //슬라이더를 클릭했을 때 움직이는 범위. 
	mCloudsRedValue.SetWindowTextA("255");//red edit박스 초기값

	//green 슬라이더
	mCloudsGreenS.SetPos(0);//슬라이더 처음 위치
	mCloudsGreenS.SetRange(0, 255); //슬라이더 범위 0 ~ 100으로 함.
	mCloudsGreenS.SetPageSize(10);  //슬라이더를 클릭했을 때 움직이는 범위
	mCloudsGreenValue.SetWindowTextA("0");//green edit박스 초기값

	//blue 슬라이더
	mCloudsBlueS.SetPos(0);//슬라이더 처음 위치
	mCloudsBlueS.SetRange(0, 255); //슬라이더 범위 0 ~ 100으로 함.
	mCloudsBlueS.SetPageSize(10);  //슬라이더를 클릭했을 때 움직이는 범위
	mCloudsBlueValue.SetWindowTextA("0");//blue edit박스 초기값

	//수직슬라이더
	mCloudsVSlider.SetPos(50);//슬라이더 처음 위치
	mCloudsVSlider.SetRange(0, 100); //슬라이더 범위 0 ~ 100으로 함.
	mCloudsVSlider.SetPageSize(1);  //슬라이더를 클릭했을 때 움직이는 범위
	mCloudsVEdit.SetWindowTextA("0");//v edit박스 초기값

	//수평슬라이더
	mCloudsHSlider.SetPos(50);//슬라이더 처음 위치
	mCloudsHSlider.SetRange(0, 100); //슬라이더 범위 0 ~ 100으로 함.
	mCloudsHSlider.SetPageSize(1);  //슬라이더를 클릭했을 때 움직이는 범위
	mCloudsHEdit.SetWindowTextA("0");//h edit박스 초기값


	return TRUE;  // return TRUE unless you set the focus to a control
	// 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}
void CCloudsDlg::OnEnChangeEdit1()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CDialogEx::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CCloudsDlg::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	CMainFrame* pFrame = (CMainFrame*)AfxGetMainWnd();				//View호출
	CMakoryView* pView = (CMakoryView*)pFrame->GetActiveView();		//View호출

	if(pScrollBar)
	{
		// 어떤 슬라이더인지 검사
		//red slider가 움직였을 경우
		if(pScrollBar == (CScrollBar*)&mCloudsRedS)//balloon red slider인경우
		{
			
			// 슬라이더의 위치를 검사한다.
 			int npos = mCloudsRedS.GetPos(); //슬라이더 위치 얻어옴
			CString str;
			str.Format(_T("%d"), npos); //형변환
			mCloudsRedValue.SetWindowTextA(str); //edit 박스에 슬라이더 값 들어감

			dpos = (double)npos * 0.00392156; //슬라이더는 소숫점이 사용이 안됨

			pView->HotAirBalloon.cloudsred=dpos;//풍선 빨간색값을 바꿔줌
			pView->Invalidate(FALSE);
		}

		//green슬라이더 움직였을 경우
		else if(pScrollBar == (CScrollBar*)&mCloudsGreenS)//balloon green slider인경우
		{
			
			// 슬라이더의 위치를 검사한다.
 			int npos = mCloudsGreenS.GetPos(); //슬라이더 위치 얻어옴
			CString str;
			str.Format(_T("%d"), npos); //형변환
			mCloudsGreenValue.SetWindowTextA(str);// edit 박스에 슬라이더 값 들어감

			dpos = (double)npos * 0.00392156; //슬라이더는 소숫점이 사용이 안됨

			pView->HotAirBalloon.cloudsgreen=dpos; //풍선 녹색값을 바꿔줌
			pView->Invalidate(FALSE);
		}

	

		//blue 슬라이더 움직였을 경우
		else if(pScrollBar == (CScrollBar*)&mCloudsBlueS)//balloon green slider인경우
		{

			// 슬라이더의 위치를 검사한다.
			int npos = mCloudsBlueS.GetPos(); //슬라이더 위치 얻어옴
			CString str;
			str.Format(_T("%d"), npos); //형변환
			mCloudsBlueValue.SetWindowTextA(str); //blue edit 박스에 슬라이더 값 들어감

			dpos = (double)npos * 0.00392156; //슬라이더는 소숫점이 사용이 안됨

			pView->HotAirBalloon.cloudsblue=dpos; //풍선 파랑색값을 바꿔줌
			pView->Invalidate(FALSE);
		}

		//수직 슬라이더 움직였을 경우
		else if(pScrollBar == (CScrollBar*)&mCloudsVSlider)//수직 슬라이더인경우
		{

			// 슬라이더의 위치를 검사한다.
			int npos = mCloudsVSlider.GetPos(); //슬라이더 위치 얻어옴
			CString str;
			str.Format(_T("%d"), npos-50); //형변환
			mCloudsVEdit.SetWindowTextA(str); //edit 박스에 슬라이더 값 들어감

			
			if(npos <= 50){ //슬라이더가 50이하일때
				dpos = -0.5+((double)npos * 0.01); //왼쪽으로 이동 
			} 
			else if(npos >= 50){  //슬라이더가 50이상일때
				dpos = ((double)npos * 0.01)-0.5; //오른쪽으로 이동
			}

			pView->HotAirBalloon.cloudsy=dpos; //balloony값을 바꿔줌
			pView->Invalidate(FALSE);
		}
		//수평 슬라이더 움직였을 경우
		else if(pScrollBar == (CScrollBar*)&mCloudsHSlider)//수평 슬라이더인경우
		{

			// 슬라이더의 위치를 검사한다.
			int npos = mCloudsHSlider.GetPos(); //슬라이더 위치 얻어옴
			
			CString str;
			str.Format(_T("%d"), npos-50); //형변환
			mCloudsHEdit.SetWindowTextA(str); //edit 박스에 슬라이더 값 들어감

			if(npos <= 50){ //슬라이더가 50이하일때
				dpos = -0.5+((double)npos * 0.01); //위으로 이동 
				
			} 
			else if(npos >= 50){  //슬라이더가 50이상일때
				dpos = ((double)npos * 0.01)-0.5; //아래쪽으로 이동
			}

			pView->HotAirBalloon.cloudsx=dpos; //balloonx값을 바꿔줌
			pView->Invalidate(FALSE);
		}

	CDialogEx::OnHScroll(nSBCode, nPos, pScrollBar);
	}
}