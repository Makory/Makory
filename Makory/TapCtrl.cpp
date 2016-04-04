// TapCtrl.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "Makory.h"
#include "TapCtrl.h"
#include "afxdialogex.h"


// CTapCtrl 대화 상자입니다.

IMPLEMENT_DYNAMIC(CTapCtrl, CDialogEx)

CTapCtrl::CTapCtrl(CWnd* pParent /*=NULL*/)
	: CDialogEx(CTapCtrl::IDD, pParent)
{

}

CTapCtrl::~CTapCtrl()
{
}

void CTapCtrl::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CTapCtrl, CDialogEx)
END_MESSAGE_MAP()


// CTapCtrl 메시지 처리기입니다.
