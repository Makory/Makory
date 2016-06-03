// EdittapCtrl.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "Makory.h"
#include "SlateDlg.h"
#include "afxdialogex.h"
#include "Film.h"
#include "MainFrm.h"
#include "MakoryDoc.h"
#include "MakoryView.h"

// CSlateDlg 대화 상자입니다.

IMPLEMENT_DYNAMIC(CSlateDlg, CDialogEx)

	CSlateDlg::CSlateDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CSlateDlg::IDD, pParent)
{

}

CSlateDlg::~CSlateDlg()
{
}

void CSlateDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_SLATE_RED_SLIDER, mSlateRedS);
	DDX_Control(pDX, IDC_SLATE_RED_VALUE, mSlateRedValue);
	DDX_Control(pDX, IDC_SLATE_GREEN_SLIDER, mSlateGreenS);
	DDX_Control(pDX, IDC_SLATE_GREEN_VALUE, mSlateGreenValue);
	DDX_Control(pDX, IDC_SLATE_BLUE_SLIDER, mSlateBlueS);
	DDX_Control(pDX, IDC_SLATE_BLUE_VALUE, mSlateBlueValue);
	DDX_Control(pDX, IDC_SLATE_VSCROLL, mSlateVSlider);
	DDX_Control(pDX, IDC_SLATE_HSCROOL, mSlateHSlider);
	DDX_Control(pDX, IDC_SLATE_V_VALUE, mSlateVEdit);
	DDX_Control(pDX, IDC_SLATE_H_VALUE, mSlateHEdit);
	DDX_Control(pDX, IDC_SLATE_SCALE_SLIDER, mSlateScaleSlider);
	DDX_Control(pDX, IDC_SLATE_SCALE_VALUE, mSlateScaleEdit);

	//2는 슬레이트 사선에 대한 것들

	DDX_Control(pDX, IDC_SLATE_RED_SLIDER2, mSlateRedS2);
	DDX_Control(pDX, IDC_SLATE_RED_VALUE2, mSlateRedValue2);
	DDX_Control(pDX, IDC_SLATE_GREEN_SLIDER2, mSlateGreenS2);
	DDX_Control(pDX, IDC_SLATE_GREEN_VALUE2, mSlateGreenValue2);
	DDX_Control(pDX, IDC_SLATE_BLUE_SLIDER2, mSlateBlueS2);
	DDX_Control(pDX, IDC_SLATE_BLUE_VALUE2, mSlateBlueValue2);
	DDX_Control(pDX, IDC_SLATE_COMBO, mSlateCombo);
}


BEGIN_MESSAGE_MAP(CSlateDlg, CDialogEx)
	ON_WM_HSCROLL()
	ON_EN_UPDATE(IDC_SLATE_RED_VALUE, &CSlateDlg::OnEnUpdateSlateRedValue)
	ON_EN_UPDATE(IDC_SLATE_GREEN_VALUE, &CSlateDlg::OnEnUpdateSlateGreenValue)
	ON_EN_UPDATE(IDC_SLATE_BLUE_VALUE, &CSlateDlg::OnEnUpdateSlateBlueValue)
	ON_EN_UPDATE(IDC_SLATE_V_VALUE, &CSlateDlg::OnEnUpdateSlateVEdit)
	ON_EN_UPDATE(IDC_SLATE_H_VALUE, &CSlateDlg::OnEnUpdateSlateHEdit)
	ON_EN_UPDATE(IDC_SLATE_SCALE_VALUE, &CSlateDlg::OnEnUpdateSlateScaleEdit)
	ON_EN_UPDATE(IDC_SLATE_RED_VALUE2, &CSlateDlg::OnEnUpdateSlateRedValue2)
	ON_EN_UPDATE(IDC_SLATE_GREEN_VALUE2, &CSlateDlg::OnEnUpdateSlateGreenValue2)
	ON_EN_UPDATE(IDC_SLATE_BLUE_VALUE2, &CSlateDlg::OnEnUpdateSlateBlueValue2)
	ON_CBN_SELCHANGE(IDC_SLATE_COMBO, &CSlateDlg::OnCbnSelchangeSlateCombo)
END_MESSAGE_MAP()


// CSlateDlg 메시지 처리기입니다.

BOOL CSlateDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	mSlateRedS2.ShowWindow(SW_SHOW);
	mSlateRedValue2.ShowWindow(SW_SHOW);
	mSlateGreenS2.ShowWindow(SW_SHOW);
	mSlateGreenValue2.ShowWindow(SW_SHOW);
	mSlateBlueS2.ShowWindow(SW_SHOW);
	mSlateBlueValue2.ShowWindow(SW_SHOW);

	mSlateRedS.ShowWindow(SW_HIDE);
	mSlateRedValue.ShowWindow(SW_HIDE);
	mSlateGreenS.ShowWindow(SW_HIDE);
	mSlateGreenValue.ShowWindow(SW_HIDE);
	mSlateBlueS.ShowWindow(SW_HIDE);
	mSlateBlueValue.ShowWindow(SW_HIDE);


	//red 슬라이더
	mSlateRedS.SetPos(255);//슬라이더 처음 위치
	mSlateRedS.SetRange(0, 255); //슬라이더 범위 0 ~ 100으로 함.
	mSlateRedS.SetPageSize(10); //슬라이더를 클릭했을 때 움직이는 범위. 
	mSlateRedValue.SetWindowTextA("255");//red edit박스 초기값

	//green 슬라이더
	mSlateGreenS.SetPos(255);//슬라이더 처음 위치
	mSlateGreenS.SetRange(0, 255); //슬라이더 범위 0 ~ 100으로 함.
	mSlateGreenS.SetPageSize(10);  //슬라이더를 클릭했을 때 움직이는 범위
	mSlateGreenValue.SetWindowTextA("255");//green edit박스 초기값

	//blue 슬라이더
	mSlateBlueS.SetPos(255);//슬라이더 처음 위치
	mSlateBlueS.SetRange(0, 255); //슬라이더 범위 0 ~ 100으로 함.
	mSlateBlueS.SetPageSize(10);  //슬라이더를 클릭했을 때 움직이는 범위
	mSlateBlueValue.SetWindowTextA("255");//blue edit박스 초기값

	//수직슬라이더
	mSlateVSlider.SetPos(50);//슬라이더 처음 위치
	mSlateVSlider.SetRange(0, 100); //슬라이더 범위 0 ~ 100으로 함.
	mSlateVSlider.SetPageSize(1);  //슬라이더를 클릭했을 때 움직이는 범위
	mSlateVEdit.SetWindowTextA("0");//v edit박스 초기값

	//수평슬라이더
	mSlateHSlider.SetPos(50);//슬라이더 처음 위치
	mSlateHSlider.SetRange(0, 100); //슬라이더 범위 0 ~ 100으로 함.
	mSlateHSlider.SetPageSize(1);  //슬라이더를 클릭했을 때 움직이는 범위
	mSlateHEdit.SetWindowTextA("0");//h edit박스 초기값

	//크기
	mSlateScaleSlider.SetPos(50);//슬라이더 처음 위치
	mSlateScaleSlider.SetRange(0, 100); //슬라이더 범위 0 ~ 100으로 함.
	mSlateScaleSlider.SetPageSize(1);  //슬라이더를 클릭했을 때 움직이는 범위
	mSlateScaleEdit.SetWindowTextA("0");//h edit박스 초기값  

	//콤보박스 
	mSlateCombo.AddString("테두리");
	mSlateCombo.AddString("사선");
	mSlateCombo.SetCurSel(0); //콤보박스 기본 설정 사선

	//red 슬라이더
	mSlateRedS2.SetPos(255);//슬라이더 처음 위치
	mSlateRedS2.SetRange(0, 255); //슬라이더 범위 0 ~ 100으로 함.
	mSlateRedS2.SetPageSize(10); //슬라이더를 클릭했을 때 움직이는 범위. 
	mSlateRedValue2.SetWindowTextA("255");//red edit박스 초기값

	//green 슬라이더
	mSlateGreenS2.SetPos(255);//슬라이더 처음 위치
	mSlateGreenS2.SetRange(0, 255); //슬라이더 범위 0 ~ 100으로 함.
	mSlateGreenS2.SetPageSize(10);  //슬라이더를 클릭했을 때 움직이는 범위
	mSlateGreenValue2.SetWindowTextA("255");//green edit박스 초기값

	//blue 슬라이더
	mSlateBlueS2.SetPos(0);//슬라이더 처음 위치
	mSlateBlueS2.SetRange(0, 255); //슬라이더 범위 0 ~ 100으로 함.
	mSlateBlueS2.SetPageSize(10);  //슬라이더를 클릭했을 때 움직이는 범위
	mSlateBlueValue2.SetWindowTextA("0");//blue edit박스 초기값

	return TRUE;  // return TRUE unless you set the focus to a control
	// 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}

//얘는 필요없을듯...일단 살려놓고 나중에 없애는걸로..
void CSlateDlg::ChangeScaleTo(int Slatescale)
{	/*
	//int Slateredsliderpos;
	//mSlateRedS.SetPos(Slateredcolor); //계속 미친듯이 호출됨
	Slateredsliderpos = mSlateRedS.GetPos();
	CString strredpos;
	strredpos.Format(_T("%d"), Slateredsliderpos); //형변환
	mSlateRedValue.SetWindowTextA(strredpos);*/

}

//슬라이더 움직였을 때
void CSlateDlg::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	CMainFrame* pFrame = (CMainFrame*)AfxGetMainWnd();				//View호출
	CMakoryView* pView = (CMakoryView*)pFrame->GetActiveView();		//View호출

	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	if(pScrollBar)
	{
		// 어떤 슬라이더인지 검사
		//red slider가 움직였을 경우
		if(pScrollBar == (CScrollBar*)&mSlateRedS)//Slate red slider인경우
		{

			// 슬라이더의 위치를 검사한다.
			int npos = mSlateRedS.GetPos(); //슬라이더 위치 얻어옴
			CString str;
			str.Format(_T("%d"), npos); //형변환
			mSlateRedValue.SetWindowTextA(str); //edit 박스에 슬라이더 값 들어감

			fpos = (double)npos * 0.00392156; //슬라이더는 소숫점이 사용이 안됨

			pView->Film.slatered=fpos;//풍선 빨간색값을 바꿔줌
			pView->Invalidate(FALSE);
		}

		//green슬라이더 움직였을 경우
		else if(pScrollBar == (CScrollBar*)&mSlateGreenS)//Slate green slider인경우
		{

			// 슬라이더의 위치를 검사한다.
			int npos = mSlateGreenS.GetPos(); //슬라이더 위치 얻어옴
			CString str;
			str.Format(_T("%d"), npos); //형변환
			mSlateGreenValue.SetWindowTextA(str);// edit 박스에 슬라이더 값 들어감

			fpos = (double)npos * 0.00392156; //슬라이더는 소숫점이 사용이 안됨

			pView->Film.slategreen=fpos; //풍선 녹색값을 바꿔줌
			pView->Invalidate(FALSE);
		}



		//blue 슬라이더 움직였을 경우
		else if(pScrollBar == (CScrollBar*)&mSlateBlueS)//Slate green slider인경우
		{

			// 슬라이더의 위치를 검사한다.
			int npos = mSlateBlueS.GetPos(); //슬라이더 위치 얻어옴
			CString str;
			str.Format(_T("%d"), npos); //형변환
			mSlateBlueValue.SetWindowTextA(str); //blue edit 박스에 슬라이더 값 들어감

			fpos = (double)npos * 0.00392156; //슬라이더는 소숫점이 사용이 안됨

			pView->Film.slateblue=fpos; //풍선 파랑색값을 바꿔줌
			pView->Invalidate(FALSE);
		}

		//크기 슬라이더 움직였을 경우
		else if(pScrollBar == (CScrollBar*)&mSlateScaleSlider)//수직 슬라이더인경우
		{

			// 슬라이더의 위치를 검사한다.
			int npos = mSlateScaleSlider.GetPos(); //슬라이더 위치 얻어옴
			CString str;
			str.Format(_T("%d"), npos-50); //형변환
			mSlateScaleEdit.SetWindowTextA(str); //edit 박스에 슬라이더 값 들어감


			if(npos <= 50){ //슬라이더가 50이하일때
				fpos = 4*(-0.5+((double)npos * 0.01)); //왼쪽으로 이동 
			} 
			else if(npos >= 50){  //슬라이더가 50이상일때
				fpos = 4*(((double)npos * 0.01)-0.5); //오른쪽으로 이동
			}

			pView->Film.SlateScale=3.0+fpos; //filmscale값을 바꿔줌
			pView->Invalidate(FALSE);
		}

		//수직 슬라이더 움직였을 경우
		else if(pScrollBar == (CScrollBar*)&mSlateVSlider)//수직 슬라이더인경우
		{

			// 슬라이더의 위치를 검사한다.
			int npos = mSlateVSlider.GetPos(); //슬라이더 위치 얻어옴
			CString str;
			str.Format(_T("%d"), npos-50); //형변환
			mSlateVEdit.SetWindowTextA(str); //edit 박스에 슬라이더 값 들어감


			if(npos <= 50){ //슬라이더가 50이하일때
				fpos = -0.5+((double)npos * 0.01); //왼쪽으로 이동 
			} 
			else if(npos >= 50){  //슬라이더가 50이상일때
				fpos = ((double)npos * 0.01)-0.5; //오른쪽으로 이동
			}

			pView->Film.slatey2=fpos; //Slatey값을 바꿔줌
			pView->Film.slatey=fpos; //Slatey값을 바꿔줌
			pView->Invalidate(FALSE);
		}
		//수평 슬라이더 움직였을 경우
		else if(pScrollBar == (CScrollBar*)&mSlateHSlider)//수평 슬라이더인경우
		{

			// 슬라이더의 위치를 검사한다.
			int npos = mSlateHSlider.GetPos(); //슬라이더 위치 얻어옴

			CString str;
			str.Format(_T("%d"), npos-50); //형변환
			mSlateHEdit.SetWindowTextA(str); //edit 박스에 슬라이더 값 들어감

			if(npos <= 50){ //슬라이더가 50이하일때
				fpos = 2*(-0.5+((double)npos * 0.01)); //위으로 이동 

			} 
			else if(npos >= 50){  //슬라이더가 50이상일때
				fpos = 2*(((double)npos * 0.01)-0.5); //아래쪽으로 이동
			}

			pView->Film.slatex2=fpos; //Slatex값을 바꿔줌
			pView->Film.slatex=fpos;


			pView->Invalidate(FALSE);
		}

		//슬레이트 사선
		//red slider가 움직였을 경우
		if(pScrollBar == (CScrollBar*)&mSlateRedS2)//Slate red slider인경우
		{

			// 슬라이더의 위치를 검사한다.
			int npos = mSlateRedS2.GetPos(); //슬라이더 위치 얻어옴
			CString str;
			str.Format(_T("%d"), npos); //형변환
			mSlateRedValue2.SetWindowTextA(str); //edit 박스에 슬라이더 값 들어감

			fpos = (double)npos * 0.00392156; //슬라이더는 소숫점이 사용이 안됨

			pView->Film.slatered2=fpos;//풍선 빨간색값을 바꿔줌
			pView->Invalidate(FALSE);
		}

		//green슬라이더 움직였을 경우
		else if(pScrollBar == (CScrollBar*)&mSlateGreenS2)//Slate green slider인경우
		{

			// 슬라이더의 위치를 검사한다.
			int npos = mSlateGreenS2.GetPos(); //슬라이더 위치 얻어옴
			CString str;
			str.Format(_T("%d"), npos); //형변환
			mSlateGreenValue2.SetWindowTextA(str);// edit 박스에 슬라이더 값 들어감

			fpos = (double)npos * 0.00392156; //슬라이더는 소숫점이 사용이 안됨

			pView->Film.slategreen2=fpos; //풍선 녹색값을 바꿔줌
			pView->Invalidate(FALSE);
		}



		//blue 슬라이더 움직였을 경우
		else if(pScrollBar == (CScrollBar*)&mSlateBlueS2)//Slate green slider인경우
		{

			// 슬라이더의 위치를 검사한다.
			int npos = mSlateBlueS2.GetPos(); //슬라이더 위치 얻어옴
			CString str;
			str.Format(_T("%d"), npos); //형변환
			mSlateBlueValue2.SetWindowTextA(str); //blue edit 박스에 슬라이더 값 들어감

			fpos = (double)npos * 0.00392156; //슬라이더는 소숫점이 사용이 안됨

			pView->Film.slateblue2=fpos; //풍선 파랑색값을 바꿔줌
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
void CSlateDlg::OnEnUpdateSlateRedValue()
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

		mSlateRedValue.GetWindowTextA(String);
		ipos = _ttoi(String);
		mSlateRedS.SetPos(ipos);
		dpos = (double)ipos * 0.00392156; //슬라이더는 소숫점이 사용이 안됨

		pView->Film.slatered=dpos;//풍선 빨간색값을 바꿔줌
		pView->Invalidate(FALSE);
	}
}

//green edit
void CSlateDlg::OnEnUpdateSlateGreenValue()
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

		mSlateGreenValue.GetWindowTextA(String);
		ipos = _ttoi(String);
		mSlateGreenS.SetPos(ipos);
		dpos = (double)ipos * 0.00392156; //슬라이더는 소숫점이 사용이 안됨
		pView->Film.slategreen=dpos;//풍선 빨간색값을 바꿔줌

		pView->Invalidate(FALSE);
	}
}

//blue edit
void CSlateDlg::OnEnUpdateSlateBlueValue()
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

		mSlateBlueValue.GetWindowTextA(String);
		ipos = _ttoi(String);
		mSlateBlueS.SetPos(ipos);
		dpos = (double)ipos * 0.00392156; //슬라이더는 소숫점이 사용이 안됨
		pView->Film.slateblue=dpos;//풍선 빨간색값을 바꿔줌

		pView->Invalidate(FALSE);
	}


}

//수평 edit
void CSlateDlg::OnEnUpdateSlateHEdit()
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

		mSlateHEdit.GetWindowTextA(String);

		ipos = _ttoi(String)+50;
		mSlateHSlider.SetPos(ipos);

		if(ipos <= 50){ //슬라이더가 50이하일때

			dpos = 2*(-0.5+((double)ipos * 0.01)); //왼쪽으로 이동 

		} 
		else if(ipos >= 50){  //슬라이더가 50이상일때
			dpos = 2*(((double)ipos * 0.01)-0.5); //오른쪽으로 이동
		}
		pView->Film.slatex=dpos; //Slatex값을 바꿔줌
		pView->Film.slatex2=dpos; //Slatex값을 바꿔줌
		pView->Invalidate(FALSE);
	}

}
//수직 Edit
void CSlateDlg::OnEnUpdateSlateVEdit()
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

		mSlateVEdit.GetWindowTextA(String);

		ipos =_ttoi(String)+50;

		mSlateVSlider.SetPos(ipos);

		if(ipos <= 50){ //슬라이더가 50이하일때

			dpos = -0.5+((double)ipos * 0.01); //왼쪽으로 이동 

		} 
		else if(ipos >= 50){  //슬라이더가 50이상일때
			dpos = ((double)ipos * 0.01)-0.5; //오른쪽으로 이동
		}

		pView->Film.slatey2=dpos; //Slatey값을 바꿔줌
		pView->Film.slatey=dpos; //Slatey값을 바꿔줌
		pView->Invalidate(FALSE);
	}
}

//크기 edit
void CSlateDlg::OnEnUpdateSlateScaleEdit()
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

		mSlateScaleEdit.GetWindowTextA(String);

		ipos = _ttoi(String)+50;
		mSlateScaleSlider.SetPos(ipos);
		if (ipos<0){
			ipos = 0;
			dpos = 4*(-0.5+((double)ipos * 0.01)); //왼쪽으로 이동 //왼쪽으로 이동 
			pView->Film.SlateScale=3.0+dpos; //filmy값을 바꿔줌
			pView->Invalidate(FALSE);
		}
		else if(ipos<100){
			if(ipos <= 50){ //슬라이더가 50이하일때

				dpos = 4*(-0.5+((double)ipos * 0.01)); //왼쪽으로 이동 

			} 
			else if(ipos >= 50){  //슬라이더가 50이상일때
				dpos = 4*(((double)ipos * 0.01)-0.5); //오른쪽으로 이동
			}

			pView->Film.SlateScale=3.0+dpos; //filmy값을 바꿔줌
			pView->Invalidate(FALSE);
		}

		else if(ipos>100){
			ipos = 100;
			dpos = 4*(((double)ipos * 0.01)-0.5); //오른쪽으로 이동
			pView->Film.SlateScale=3.0+dpos; //filmy값을 바꿔줌
			pView->Invalidate(FALSE);

		}
	}
}

//사선 edit

//RED edit
void CSlateDlg::OnEnUpdateSlateRedValue2()
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

		mSlateRedValue2.GetWindowTextA(String);
		ipos = _ttoi(String);
		mSlateRedS2.SetPos(ipos);
		dpos = (double)ipos * 0.00392156; //슬라이더는 소숫점이 사용이 안됨

		pView->Film.slatered2=dpos;//풍선 빨간색값을 바꿔줌
		pView->Invalidate(FALSE);
	}
}

//green edit
void CSlateDlg::OnEnUpdateSlateGreenValue2()
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

		mSlateGreenValue2.GetWindowTextA(String);
		ipos = _ttoi(String);
		mSlateGreenS2.SetPos(ipos);
		dpos = (double)ipos * 0.00392156; //슬라이더는 소숫점이 사용이 안됨
		pView->Film.slategreen2=dpos;//풍선 빨간색값을 바꿔줌

		pView->Invalidate(FALSE);
	}
}

//blue edit
void CSlateDlg::OnEnUpdateSlateBlueValue2()
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

		mSlateBlueValue2.GetWindowTextA(String);
		ipos = _ttoi(String);
		mSlateBlueS2.SetPos(ipos);
		dpos = (double)ipos * 0.00392156; //슬라이더는 소숫점이 사용이 안됨
		pView->Film.slateblue2=dpos;//풍선 빨간색값을 바꿔줌

		pView->Invalidate(FALSE);
	}


}

//콤보 박스 선택시
void CSlateDlg::OnCbnSelchangeSlateCombo()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	//테두리선택
	if(mSlateCombo.GetCurSel()==1){

		mSlateRedS.ShowWindow(SW_SHOW);
		mSlateRedValue.ShowWindow(SW_SHOW);
		mSlateGreenS.ShowWindow(SW_SHOW);
		mSlateGreenValue.ShowWindow(SW_SHOW);
		mSlateBlueS.ShowWindow(SW_SHOW);
		mSlateBlueValue.ShowWindow(SW_SHOW);
		mSlateRedS2.ShowWindow(SW_HIDE);
		mSlateRedValue2.ShowWindow(SW_HIDE);
		mSlateGreenS2.ShowWindow(SW_HIDE);
		mSlateGreenValue2.ShowWindow(SW_HIDE);
		//mSlateBlueS2.ShowWindow(SW_HIDE);
		//mSlateBlueValue2.ShowWindow(SW_HIDE);
	}
	//사선 선택 
	else if(mSlateCombo.GetCurSel()==0){
		mSlateRedS2.ShowWindow(SW_SHOW);
		mSlateRedValue2.ShowWindow(SW_SHOW);
		mSlateGreenS2.ShowWindow(SW_SHOW);
		mSlateGreenValue2.ShowWindow(SW_SHOW);
		mSlateBlueS2.ShowWindow(SW_SHOW);
		mSlateBlueValue2.ShowWindow(SW_SHOW);
		mSlateRedS.ShowWindow(SW_HIDE);
		mSlateRedValue.ShowWindow(SW_HIDE);
		mSlateGreenS.ShowWindow(SW_HIDE);
		mSlateGreenValue.ShowWindow(SW_HIDE);
		//mSlateBlueS.ShowWindow(SW_HIDE);
		//mSlateBlueValue.ShowWindow(SW_HIDE);
	}

}
