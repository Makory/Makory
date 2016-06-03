// WaveDlg.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "Makory.h"
#include "WaveDlg.h"
#include "afxdialogex.h"
#include "Ocean.h"
#include "MainFrm.h"
#include "MakoryDoc.h"
#include "MakoryView.h"

// CWaveDlg 대화 상자입니다.

IMPLEMENT_DYNAMIC(CWaveDlg, CDialogEx)

	CWaveDlg::CWaveDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CWaveDlg::IDD, pParent)
{

}

CWaveDlg::~CWaveDlg()
{
}

void CWaveDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_WAVE_SLIDER, mWaveS);
	DDX_Control(pDX, IDC_WAVE_VALUE, mWaveEdit);
}


BEGIN_MESSAGE_MAP(CWaveDlg, CDialogEx)
	ON_WM_HSCROLL()
	ON_EN_UPDATE(IDC_WAVE_VALUE, &CWaveDlg::OnEnUpdateWaveValue)
	
END_MESSAGE_MAP()


// CWaveDlg 메시지 처리기입니다.
BOOL CWaveDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	//red 슬라이더
	mWaveS.SetPos(0);//슬라이더 처음 위치
	mWaveS.SetRange(0,10); //슬라이더 범위 0 ~ 100으로 함.
	mWaveS.SetPageSize(1); //슬라이더를 클릭했을 때 움직이는 범위. 
	mWaveEdit.SetWindowTextA("0");//red edit박스 초기값

	return TRUE;  // return TRUE unless you set the focus to a control
	// 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}

void CWaveDlg::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	CMainFrame* pFrame = (CMainFrame*)AfxGetMainWnd();				//View호출
	CMakoryView* pView = (CMakoryView*)pFrame->GetActiveView();		//View호출

	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	if(pScrollBar)
	{
		// 어떤 슬라이더인지 검사
		//red slider가 움직였을 경우
		if(pScrollBar == (CScrollBar*)&mWaveS)//film red slider인경우
		{
			// 슬라이더의 위치를 검사한다.
			int npos = mWaveS.GetPos(); //슬라이더 위치 얻어옴
			CString str;
			str.Format(_T("%d"), npos-5); //형변환
			mWaveEdit.SetWindowTextA(str); //edit 박스에 슬라이더 값 들어감

			if(npos <= 5){ //슬라이더가 50이하일때
				fpos = -0.5+((double)npos * 0.1); //왼쪽으로 이동 
			} 
			else if(npos >= 5){  //슬라이더가 50이상일때
				fpos = ((double)npos * 0.1)-0.5; //오른쪽으로 이동
			}

			pView->Ocean.wavey=fpos; 
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
void CWaveDlg::OnEnUpdateWaveValue()
{

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CMainFrame* pFrame = (CMainFrame*)AfxGetMainWnd();            //View호출
	CMakoryView* pView = (CMakoryView*)pFrame->GetActiveView();      //View호출

	if(UpdateData(TRUE)){

	int ipos;
		double dpos;
		CString String;

		mWaveEdit.GetWindowTextA(String);

		ipos =_ttoi(String)+5;

		mWaveS.SetPos(ipos);

	    if (ipos<0){
			ipos = 0;
			dpos = -0.5+((double)ipos * 0.1); //왼쪽으로 이동 
			pView->Ocean.wavey=dpos; 
			pView->Invalidate(FALSE);
		}
		else if(ipos<10){
		if(ipos <= 5){ //슬라이더가 50이하일때
			dpos = -0.5+((double)ipos * 0.1); //왼쪽으로 이동 
			mWaveS.SetPos(ipos);
		
		} 
		else if(ipos >= 5){  //슬라이더가 50이상일때
			dpos = ((double)ipos * 0.1)-0.5; //오른쪽으로 이동
			mWaveS.SetPos(ipos);
		}
		pView->Ocean.wavey=dpos; 
		pView->Invalidate(FALSE);
		}
		else if(ipos>10){
			ipos = 10;
			dpos = ((double)ipos * 0.1)-0.5; 
			pView->Ocean.wavey=dpos; 
			pView->Invalidate(FALSE);

		}

	}
}