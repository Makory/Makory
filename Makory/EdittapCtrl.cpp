// EdittapCtrl.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "Makory.h"
#include "EdittapCtrl.h"
#include "afxdialogex.h"


// CEdittapCtrl 대화 상자입니다.

IMPLEMENT_DYNAMIC(CEdittapCtrl, CDialogEx)

CEdittapCtrl::CEdittapCtrl(CWnd* pParent /*=NULL*/)
	: CDialogEx(CEdittapCtrl::IDD, pParent)
{

}

CEdittapCtrl::~CEdittapCtrl()
{
}

void CEdittapCtrl::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CEdittapCtrl, CDialogEx)
	ON_EN_CHANGE(IDC_EDIT1, &CEdittapCtrl::OnEnChangeEdit1)
END_MESSAGE_MAP()


// CEdittapCtrl 메시지 처리기입니다.


void CEdittapCtrl::OnEnChangeEdit1()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CDialogEx::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
}
