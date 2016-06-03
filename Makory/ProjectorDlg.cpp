// EdittapCtrl.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "Makory.h"
#include "ProjectorDlg.h"
#include "afxdialogex.h"
#include "Film.h"
#include "MainFrm.h"
#include "MakoryDoc.h"
#include "MakoryView.h"

// CProjectorDlg 대화 상자입니다.

IMPLEMENT_DYNAMIC(CProjectorDlg, CDialogEx)

CProjectorDlg::CProjectorDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CProjectorDlg::IDD, pParent)
{
			
}

CProjectorDlg::~CProjectorDlg()
{
}

void CProjectorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PROJECTOR_RED_SLIDER, mProjectorRedS);
	DDX_Control(pDX, IDC_PROJECTOR_RED_VALUE, mProjectorRedValue);
	DDX_Control(pDX, IDC_PROJECTOR_GREEN_SLIDER, mProjectorGreenS);
	DDX_Control(pDX, IDC_PROJECTOR_GREEN_VALUE, mProjectorGreenValue);
	DDX_Control(pDX, IDC_PROJECTOR_BLUE_SLIDER, mProjectorBlueS);
	DDX_Control(pDX, IDC_PROJECTOR_BLUE_VALUE, mProjectorBlueValue);
	DDX_Control(pDX, IDC_PROJECTOR_VSCROLL, mProjectorVSlider);
	DDX_Control(pDX, IDC_PROJECTOR_HSCROOL, mProjectorHSlider);
	DDX_Control(pDX, IDC_PROJECTOR_V_VALUE, mProjectorVEdit);
	DDX_Control(pDX, IDC_PROJECTOR_H_VALUE, mProjectorHEdit);
	DDX_Control(pDX, IDC_PROJECTOR_SCALE_SLIDER, mProjectorScaleSlider);
	DDX_Control(pDX, IDC_PROJECTOR_SCALE_VALUE, mProjectorScaleEdit);
}


BEGIN_MESSAGE_MAP(CProjectorDlg, CDialogEx)
	ON_WM_HSCROLL()
	ON_EN_UPDATE(IDC_PROJECTOR_RED_VALUE, &CProjectorDlg::OnEnUpdateProjectorRedValue)
	ON_EN_UPDATE(IDC_PROJECTOR_GREEN_VALUE, &CProjectorDlg::OnEnUpdateProjectorGreenValue)
	ON_EN_UPDATE(IDC_PROJECTOR_BLUE_VALUE, &CProjectorDlg::OnEnUpdateProjectorBlueValue)
	ON_EN_UPDATE(IDC_PROJECTOR_V_VALUE, &CProjectorDlg::OnEnUpdateProjectorVEdit)
	ON_EN_UPDATE(IDC_PROJECTOR_H_VALUE, &CProjectorDlg::OnEnUpdateProjectorHEdit)
	ON_EN_UPDATE(IDC_PROJECTOR_SCALE_VALUE, &CProjectorDlg::OnEnUpdateProjectorScaleEdit)
END_MESSAGE_MAP()


// CProjectorDlg 메시지 처리기입니다.

BOOL CProjectorDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	//red 슬라이더
	mProjectorRedS.SetPos(255);//슬라이더 처음 위치
	mProjectorRedS.SetRange(0, 255); //슬라이더 범위 0 ~ 100으로 함.
	mProjectorRedS.SetPageSize(10); //슬라이더를 클릭했을 때 움직이는 범위. 
	mProjectorRedValue.SetWindowTextA("255");//red edit박스 초기값

	//green 슬라이더
	mProjectorGreenS.SetPos(255);//슬라이더 처음 위치
	mProjectorGreenS.SetRange(0, 255); //슬라이더 범위 0 ~ 100으로 함.
	mProjectorGreenS.SetPageSize(10);  //슬라이더를 클릭했을 때 움직이는 범위
	mProjectorGreenValue.SetWindowTextA("255");//green edit박스 초기값

	//blue 슬라이더
	mProjectorBlueS.SetPos(255);//슬라이더 처음 위치
	mProjectorBlueS.SetRange(0, 255); //슬라이더 범위 0 ~ 100으로 함.
	mProjectorBlueS.SetPageSize(10);  //슬라이더를 클릭했을 때 움직이는 범위
	mProjectorBlueValue.SetWindowTextA("255");//blue edit박스 초기값

	//수직슬라이더
	mProjectorVSlider.SetPos(50);//슬라이더 처음 위치
	mProjectorVSlider.SetRange(0, 100); //슬라이더 범위 0 ~ 100으로 함.
	mProjectorVSlider.SetPageSize(1);  //슬라이더를 클릭했을 때 움직이는 범위
	mProjectorVEdit.SetWindowTextA("0");//v edit박스 초기값

	//수평슬라이더
	mProjectorHSlider.SetPos(50);//슬라이더 처음 위치
	mProjectorHSlider.SetRange(0, 100); //슬라이더 범위 0 ~ 100으로 함.
	mProjectorHSlider.SetPageSize(1);  //슬라이더를 클릭했을 때 움직이는 범위
	mProjectorHEdit.SetWindowTextA("0");//h edit박스 초기값

	//크기
	mProjectorScaleSlider.SetPos(50);//슬라이더 처음 위치
	mProjectorScaleSlider.SetRange(0, 100); //슬라이더 범위 0 ~ 100으로 함.
	mProjectorScaleSlider.SetPageSize(1);  //슬라이더를 클릭했을 때 움직이는 범위
	mProjectorScaleEdit.SetWindowTextA("0");//h edit박스 초기값


	return TRUE;  // return TRUE unless you set the focus to a control
	// 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}

//얘는 필요없을듯...일단 살려놓고 나중에 없애는걸로..
void CProjectorDlg::ChangeScaleTo(int Projectorscale)
{	/*
	//int Projectorredsliderpos;
	//mProjectorRedS.SetPos(Projectorredcolor); //계속 미친듯이 호출됨
	Projectorredsliderpos = mProjectorRedS.GetPos();
	CString strredpos;
	strredpos.Format(_T("%d"), Projectorredsliderpos); //형변환
	mProjectorRedValue.SetWindowTextA(strredpos);*/
	
}

//슬라이더 움직였을 때
void CProjectorDlg::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	CMainFrame* pFrame = (CMainFrame*)AfxGetMainWnd();				//View호출
	CMakoryView* pView = (CMakoryView*)pFrame->GetActiveView();		//View호출
	
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	if(pScrollBar)
	{
		// 어떤 슬라이더인지 검사
		//red slider가 움직였을 경우
		if(pScrollBar == (CScrollBar*)&mProjectorRedS)//Projector red slider인경우
		{
			
			// 슬라이더의 위치를 검사한다.
 			int npos = mProjectorRedS.GetPos(); //슬라이더 위치 얻어옴
			CString str;
			str.Format(_T("%d"), npos); //형변환
			mProjectorRedValue.SetWindowTextA(str); //edit 박스에 슬라이더 값 들어감

			fpos = (double)npos * 0.00392156; //슬라이더는 소숫점이 사용이 안됨

			pView->Film.projred=fpos;//풍선 빨간색값을 바꿔줌
			pView->Invalidate(FALSE);
		}

		//green슬라이더 움직였을 경우
		else if(pScrollBar == (CScrollBar*)&mProjectorGreenS)//Projector green slider인경우
		{
			
			// 슬라이더의 위치를 검사한다.
 			int npos = mProjectorGreenS.GetPos(); //슬라이더 위치 얻어옴
			CString str;
			str.Format(_T("%d"), npos); //형변환
			mProjectorGreenValue.SetWindowTextA(str);// edit 박스에 슬라이더 값 들어감

			fpos = (double)npos * 0.00392156; //슬라이더는 소숫점이 사용이 안됨

			pView->Film.projgreen=fpos; //풍선 녹색값을 바꿔줌
			pView->Invalidate(FALSE);
		}

	

		//blue 슬라이더 움직였을 경우
		else if(pScrollBar == (CScrollBar*)&mProjectorBlueS)//Projector green slider인경우
		{

			// 슬라이더의 위치를 검사한다.
			int npos = mProjectorBlueS.GetPos(); //슬라이더 위치 얻어옴
			CString str;
			str.Format(_T("%d"), npos); //형변환
			mProjectorBlueValue.SetWindowTextA(str); //blue edit 박스에 슬라이더 값 들어감

			fpos = (double)npos * 0.00392156; //슬라이더는 소숫점이 사용이 안됨

			pView->Film.projblue=fpos; //풍선 파랑색값을 바꿔줌
			pView->Invalidate(FALSE);
		}

		//크기 슬라이더 움직였을 경우
		else if(pScrollBar == (CScrollBar*)&mProjectorScaleSlider)//수직 슬라이더인경우
		{

			// 슬라이더의 위치를 검사한다.
			int npos = mProjectorScaleSlider.GetPos(); //슬라이더 위치 얻어옴
			CString str;
			str.Format(_T("%d"), npos-50); //형변환
			mProjectorScaleEdit.SetWindowTextA(str); //edit 박스에 슬라이더 값 들어감

			
			if(npos <= 50){ //슬라이더가 50이하일때
				fpos = 2*(-0.5+((double)npos * 0.01)); //왼쪽으로 이동 
			} 
			else if(npos >= 50){  //슬라이더가 50이상일때
				fpos = 2*(((double)npos * 0.01)-0.5); //오른쪽으로 이동
			}

			pView->Film.ProjectorScale=2+fpos; //filmscale값을 바꿔줌
			pView->Invalidate(FALSE);
		}
		//수직 슬라이더 움직였을 경우
		else if(pScrollBar == (CScrollBar*)&mProjectorVSlider)//수직 슬라이더인경우
		{

			// 슬라이더의 위치를 검사한다.
			int npos = mProjectorVSlider.GetPos(); //슬라이더 위치 얻어옴
			CString str;
			str.Format(_T("%d"), npos-50); //형변환
			mProjectorVEdit.SetWindowTextA(str); //edit 박스에 슬라이더 값 들어감

			
			if(npos <= 50){ //슬라이더가 50이하일때
				fpos = -0.5+((double)npos * 0.01); //왼쪽으로 이동 
			} 
			else if(npos >= 50){  //슬라이더가 50이상일때
				fpos = ((double)npos * 0.01)-0.5; //오른쪽으로 이동
			}

			pView->Film.projy=fpos; //Projectory값을 바꿔줌

			pView->Invalidate(FALSE);
		}
		//수평 슬라이더 움직였을 경우
		else if(pScrollBar == (CScrollBar*)&mProjectorHSlider)//수평 슬라이더인경우
		{

			// 슬라이더의 위치를 검사한다.
			int npos = mProjectorHSlider.GetPos(); //슬라이더 위치 얻어옴
			
			CString str;
			str.Format(_T("%d"), npos-50); //형변환
			mProjectorHEdit.SetWindowTextA(str); //edit 박스에 슬라이더 값 들어감

			if(npos <= 50){ //슬라이더가 50이하일때
				fpos = -0.5+((double)npos * 0.01); //위으로 이동 
				
			} 
			else if(npos >= 50){  //슬라이더가 50이상일때
				fpos = ((double)npos * 0.01)-0.5; //아래쪽으로 이동
			}

			
			pView->Film.projx=fpos;
		
			
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
void CProjectorDlg::OnEnUpdateProjectorRedValue()
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

		mProjectorRedValue.GetWindowTextA(String);
		ipos = _ttoi(String);
		mProjectorRedS.SetPos(ipos);
		dpos = (double)ipos * 0.00392156; //슬라이더는 소숫점이 사용이 안됨

		pView->Film.projred=dpos;//풍선 빨간색값을 바꿔줌
		pView->Invalidate(FALSE);
	}
}

//green edit
void CProjectorDlg::OnEnUpdateProjectorGreenValue()
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

		mProjectorGreenValue.GetWindowTextA(String);
		ipos = _ttoi(String);
		mProjectorGreenS.SetPos(ipos);
		dpos = (double)ipos * 0.00392156; //슬라이더는 소숫점이 사용이 안됨
		pView->Film.projgreen=dpos;//풍선 빨간색값을 바꿔줌

		pView->Invalidate(FALSE);
	}
}

//blue edit
void CProjectorDlg::OnEnUpdateProjectorBlueValue()
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

		mProjectorBlueValue.GetWindowTextA(String);
		ipos = _ttoi(String);
		mProjectorBlueS.SetPos(ipos);
		dpos = (double)ipos * 0.00392156; //슬라이더는 소숫점이 사용이 안됨
		pView->Film.projblue=dpos;//풍선 빨간색값을 바꿔줌

		pView->Invalidate(FALSE);
	}
}

//수평 edit
void CProjectorDlg::OnEnUpdateProjectorHEdit()
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

		mProjectorHEdit.GetWindowTextA(String);

		ipos = _ttoi(String)+50;
		mProjectorHSlider.SetPos(ipos);

		if(ipos <= 50){ //슬라이더가 50이하일때
		
			dpos = -0.5+((double)ipos * 0.01); //왼쪽으로 이동 
			
		} 
		else if(ipos >= 50){  //슬라이더가 50이상일때
			dpos = ((double)ipos * 0.01)-0.5; //오른쪽으로 이동
		}

		pView->Film.projx=dpos;
		pView->Invalidate(FALSE);
	}
}

//수직 Edit
void CProjectorDlg::OnEnUpdateProjectorVEdit()
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

		mProjectorVEdit.GetWindowTextA(String);

		ipos =_ttoi(String)+50;

		mProjectorVSlider.SetPos(ipos);

		if(ipos <= 50){ //슬라이더가 50이하일때
		
			dpos = -0.5+((double)ipos * 0.01); //왼쪽으로 이동 
			
		} 
		else if(ipos >= 50){  //슬라이더가 50이상일때
			dpos = ((double)ipos * 0.01)-0.5; //오른쪽으로 이동
		}

		pView->Film.projy=dpos; //Projectory값을 바꿔줌
		pView->Invalidate(FALSE);
	}
}

//크기 edit
void CProjectorDlg::OnEnUpdateProjectorScaleEdit()
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

		mProjectorScaleEdit.GetWindowTextA(String);

		ipos = _ttoi(String)+50;
		mProjectorScaleSlider.SetPos(ipos);
		if (ipos<0){
			ipos = 0;
			dpos = 2*(-0.5+((double)ipos * 0.01)); //왼쪽으로 이동 
			pView->Film.ProjectorScale=2+dpos; //filmy값을 바꿔줌
			pView->Invalidate(FALSE);
		}
		else if(ipos<100){
		if(ipos <= 50){ //슬라이더가 50이하일때
		
			dpos = 2*(-0.5+((double)ipos * 0.01)); //왼쪽으로 이동 
			
		} 
		else if(ipos >= 50){  //슬라이더가 50이상일때
			dpos = 2*(((double)ipos * 0.01)-0.5); //오른쪽으로 이동
		}

		pView->Film.ProjectorScale=2+dpos; //filmy값을 바꿔줌
		pView->Invalidate(FALSE);
		}
		else if(ipos>100){
			ipos = 100;
			dpos = 2*(((double)ipos * 0.01)-0.5); //오른쪽으로 이동
			pView->Film.ProjectorScale=2+dpos; //filmy값을 바꿔줌
			pView->Invalidate(FALSE);

		}
	}
}