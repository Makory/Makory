// EdittapCtrl.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "Makory.h"
#include "FilmDlg.h"
#include "afxdialogex.h"
#include "Film.h"
#include "MainFrm.h"
#include "MakoryDoc.h"
#include "MakoryView.h"

// CFilmDlg 대화 상자입니다.

IMPLEMENT_DYNAMIC(CFilmDlg, CDialogEx)

CFilmDlg::CFilmDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CFilmDlg::IDD, pParent)
{
			
}

CFilmDlg::~CFilmDlg()
{
}

void CFilmDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_FILM_RED_SLIDER, mFilmRedS);
	DDX_Control(pDX, IDC_FILM_RED_VALUE, mFilmRedValue);
	DDX_Control(pDX, IDC_FILM_GREEN_SLIDER, mFilmGreenS);
	DDX_Control(pDX, IDC_FILM_GREEN_VALUE, mFilmGreenValue);
	DDX_Control(pDX, IDC_FILM_BLUE_SLIDER, mFilmBlueS);
	DDX_Control(pDX, IDC_FILM_BLUE_VALUE, mFilmBlueValue);
	DDX_Control(pDX, IDC_FILM_SCALE_SLIDER, mFilmScaleSlider);
	DDX_Control(pDX, IDC_FILM_SCALE_VALUE, mFilmScaleEdit);
}


BEGIN_MESSAGE_MAP(CFilmDlg, CDialogEx)
	ON_WM_HSCROLL()
	ON_EN_UPDATE(IDC_FILM_RED_VALUE, &CFilmDlg::OnEnUpdateFilmRedValue)
	ON_EN_UPDATE(IDC_FILM_GREEN_VALUE, &CFilmDlg::OnEnUpdateFilmGreenValue)
	ON_EN_UPDATE(IDC_FILM_BLUE_VALUE, &CFilmDlg::OnEnUpdateFilmBlueValue)
	ON_EN_UPDATE(IDC_FILM_SCALE_VALUE, &CFilmDlg::OnEnUpdateFilmScaleEdit)
	
END_MESSAGE_MAP()


// CFilmDlg 메시지 처리기입니다.

BOOL CFilmDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	//red 슬라이더
	mFilmRedS.SetPos(255);//슬라이더 처음 위치
	mFilmRedS.SetRange(0, 255); //슬라이더 범위 0 ~ 100으로 함.
	mFilmRedS.SetPageSize(10); //슬라이더를 클릭했을 때 움직이는 범위. 
	mFilmRedValue.SetWindowTextA("255");//red edit박스 초기값

	//green 슬라이더
	mFilmGreenS.SetPos(255);//슬라이더 처음 위치
	mFilmGreenS.SetRange(0, 255); //슬라이더 범위 0 ~ 100으로 함.
	mFilmGreenS.SetPageSize(10);  //슬라이더를 클릭했을 때 움직이는 범위
	mFilmGreenValue.SetWindowTextA("255");//green edit박스 초기값

	//blue 슬라이더
	mFilmBlueS.SetPos(255);//슬라이더 처음 위치
	mFilmBlueS.SetRange(0, 255); //슬라이더 범위 0 ~ 100으로 함.
	mFilmBlueS.SetPageSize(10);  //슬라이더를 클릭했을 때 움직이는 범위
	mFilmBlueValue.SetWindowTextA("255");//blue edit박스 초기값

	//크기 슬라이더
	mFilmScaleSlider.SetPos(50);//슬라이더 처음 위치
	mFilmScaleSlider.SetRange(0, 100); //슬라이더 범위 0 ~ 100으로 함.
	mFilmScaleSlider.SetPageSize(1);  //슬라이더를 클릭했을 때 움직이는 범위
	mFilmScaleEdit.SetWindowTextA("0");//v edit박스 초기값



	return TRUE;  // return TRUE unless you set the focus to a control
	// 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}


//슬라이더 움직였을 때
void CFilmDlg::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	CMainFrame* pFrame = (CMainFrame*)AfxGetMainWnd();				//View호출
	CMakoryView* pView = (CMakoryView*)pFrame->GetActiveView();		//View호출
	
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	if(pScrollBar)
	{
		// 어떤 슬라이더인지 검사
		//red slider가 움직였을 경우
		if(pScrollBar == (CScrollBar*)&mFilmRedS)//film red slider인경우
		{
			
			// 슬라이더의 위치를 검사한다.
 			int npos = mFilmRedS.GetPos(); //슬라이더 위치 얻어옴
			CString str;
			str.Format(_T("%d"), npos); //형변환
			mFilmRedValue.SetWindowTextA(str); //edit 박스에 슬라이더 값 들어감

			fpos = (double)npos * 0.00392156; //슬라이더는 소숫점이 사용이 안됨

			pView->Film.filmred=fpos;//풍선 빨간색값을 바꿔줌
			pView->Invalidate(FALSE);
		}

		//green슬라이더 움직였을 경우
		else if(pScrollBar == (CScrollBar*)&mFilmGreenS)//film green slider인경우
		{
			
			// 슬라이더의 위치를 검사한다.
 			int npos = mFilmGreenS.GetPos(); //슬라이더 위치 얻어옴
			CString str;
			str.Format(_T("%d"), npos); //형변환
			mFilmGreenValue.SetWindowTextA(str);// edit 박스에 슬라이더 값 들어감

			fpos = (double)npos * 0.00392156; //슬라이더는 소숫점이 사용이 안됨

			pView->Film.filmgreen=fpos; //풍선 녹색값을 바꿔줌
			pView->Invalidate(FALSE);
		}

	

		//blue 슬라이더 움직였을 경우
		else if(pScrollBar == (CScrollBar*)&mFilmBlueS)//film green slider인경우
		{

			// 슬라이더의 위치를 검사한다.
			int npos = mFilmBlueS.GetPos(); //슬라이더 위치 얻어옴
			CString str;
			str.Format(_T("%d"), npos); //형변환
			mFilmBlueValue.SetWindowTextA(str); //blue edit 박스에 슬라이더 값 들어감

			fpos = (double)npos * 0.00392156; //슬라이더는 소숫점이 사용이 안됨

			pView->Film.filmblue=fpos; //풍선 파랑색값을 바꿔줌
			pView->Invalidate(FALSE);
		}

		//크기 슬라이더 움직였을 경우
		else if(pScrollBar == (CScrollBar*)&mFilmScaleSlider)//수직 슬라이더인경우
		{

			// 슬라이더의 위치를 검사한다.
			int npos = mFilmScaleSlider.GetPos(); //슬라이더 위치 얻어옴
			CString str;
			str.Format(_T("%d"), npos-50); //형변환
			mFilmScaleEdit.SetWindowTextA(str); //edit 박스에 슬라이더 값 들어감

			
			if(npos <= 50){ //슬라이더가 50이하일때
				fpos = 2*(-0.5+((double)npos * 0.01)); //왼쪽으로 이동 
			} 
			else if(npos >= 50){  //슬라이더가 50이상일때
				fpos = ((double)npos * 0.01)-0.5; //오른쪽으로 이동
			}

			pView->Film.FilmScale=2.5+fpos; //filmscale값을 바꿔줌
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
void CFilmDlg::OnEnUpdateFilmRedValue()
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

		mFilmRedValue.GetWindowTextA(String);
		ipos = _ttoi(String);
		mFilmRedS.SetPos(ipos);
		dpos = (double)ipos * 0.00392156; //슬라이더는 소숫점이 사용이 안됨

		pView->Film.filmred=dpos;//풍선 빨간색값을 바꿔줌
		pView->Invalidate(FALSE);
	}
}

//green edit
void CFilmDlg::OnEnUpdateFilmGreenValue()
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

		mFilmGreenValue.GetWindowTextA(String);
		ipos = _ttoi(String);
		mFilmGreenS.SetPos(ipos);
		dpos = (double)ipos * 0.00392156; //슬라이더는 소숫점이 사용이 안됨
		pView->Film.filmgreen=dpos;//풍선 빨간색값을 바꿔줌

		pView->Invalidate(FALSE);
	}
}

//blue edit
void CFilmDlg::OnEnUpdateFilmBlueValue()
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

		mFilmBlueValue.GetWindowTextA(String);
		ipos = _ttoi(String);
		mFilmBlueS.SetPos(ipos);
		dpos = (double)ipos * 0.00392156; //슬라이더는 소숫점이 사용이 안됨
		pView->Film.filmblue=dpos;//풍선 빨간색값을 바꿔줌

		pView->Invalidate(FALSE);
	}
}

//크기 edit
void CFilmDlg::OnEnUpdateFilmScaleEdit()
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

		mFilmScaleEdit.GetWindowTextA(String);

		ipos = _ttoi(String)+50;
		mFilmScaleSlider.SetPos(ipos);

		if (ipos<0){
			ipos = 0;
			dpos = 2*(-0.5+((double)ipos * 0.01)); //왼쪽으로 이동 
			pView->Film.FilmScale=2.5+dpos; //filmy값을 바꿔줌
			pView->Invalidate(FALSE);
		}
		else if(ipos<=100){
			if(ipos <= 50){ //슬라이더가 50이하일때

				dpos = 2*(-0.5+((double)ipos * 0.01)); //왼쪽으로 이동 

			} 
			else if(ipos >= 50){  //슬라이더가 50이상일때
				dpos = ((double)ipos * 0.01)-0.5; //오른쪽으로 이동
			}

			pView->Film.FilmScale=2.5+dpos; //filmy값을 바꿔줌
			pView->Invalidate(FALSE);
		}

		else if(ipos>100){
			ipos = 100;
			dpos = ((double)ipos * 0.01)-0.5; //오른쪽으로 이동
			pView->Film.FilmScale=2.5+dpos; //filmy값을 바꿔줌
			pView->Invalidate(FALSE);

		}

	}
}
