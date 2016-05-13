// EdittapCtrl.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "Makory.h"
#include "FilmDlg.h"
#include "afxdialogex.h"


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
}


BEGIN_MESSAGE_MAP(CFilmDlg, CDialogEx)
	ON_EN_CHANGE(IDC_EDIT1, &CFilmDlg::OnEnChangeEdit1)
	ON_EN_CHANGE(IDC_FILM_BLUE_VALUE, &CFilmDlg::OnEnChangeFilmBlueValue)
END_MESSAGE_MAP()


// CFilmDlg 메시지 처리기입니다.


void CFilmDlg::OnEnChangeEdit1()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CDialogEx::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CFilmDlg::OnEnChangeFilmBlueValue()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CDialogEx::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
}
