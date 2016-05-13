// EdittapCtrl.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "Makory.h"
#include "ImageEditDlg.h"
#include "afxdialogex.h"
#include "HotAirBalloon.h"
#include "MainFrm.h"
#include "MakoryDoc.h"
#include "MakoryView.h"

// CImageEditDlg 대화 상자입니다.

IMPLEMENT_DYNAMIC(CImageEditDlg, CDialogEx)

CImageEditDlg::CImageEditDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CImageEditDlg::IDD, pParent)
{

}

CImageEditDlg::~CImageEditDlg()
{
}

void CImageEditDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_IMAGE_SCALE_SLIDER, mImageScaleSlider);
	DDX_Control(pDX, IDC_IMAGE_SCALE_VALUE, mImageScaleValue);
}


BEGIN_MESSAGE_MAP(CImageEditDlg, CDialogEx)
	ON_EN_CHANGE(IDC_EDIT1, &CImageEditDlg::OnEnChangeEdit1)
	ON_WM_HSCROLL()
END_MESSAGE_MAP()


// CImageEditDlg 메시지 처리기입니다.

BOOL CImageEditDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	mImageScaleValue.SetWindowTextA("0");
	return TRUE;  // return TRUE unless you set the focus to a control
	// 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}


void CImageEditDlg::OnEnChangeEdit1()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CDialogEx::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CImageEditDlg::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	CMainFrame* pFrame = (CMainFrame*)AfxGetMainWnd();				//View호출
	CMakoryView* pView = (CMakoryView*)pFrame->GetActiveView();		//View호출
	

	// 슬라이더의 위치를 검사한다.
	int npos = mImageScaleSlider.GetPos(); //슬라이더 위치 얻어옴
	CString str;
	str.Format(_T("%d"), npos); //형변환
	mImageScaleValue.SetWindowTextA(str); //edit 박스에 슬라이더 값 들어감

	fpos = (double)npos * 0.002; //크기값 조절

	pView->HotAirBalloon.balloonscale=fpos;//크기값을 바꿔줌
	pView->HotAirBalloon.darkstormyscale=fpos;
	pView->HotAirBalloon.fullmoonscale=fpos;
	pView->HotAirBalloon.mountscale=fpos;
	pView->HotAirBalloon.sunsetscale=fpos;//크기값을 바꿔줌
	pView->HotAirBalloon.cloudsscale=fpos;
	pView->HotAirBalloon.tropicalscale=fpos;

	pView->Invalidate(FALSE);


	CDialogEx::OnHScroll(nSBCode, nPos, pScrollBar);
}

