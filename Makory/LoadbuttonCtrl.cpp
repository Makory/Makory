// LoadbuttonCtrl.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "Makory.h"
#include "LoadbuttonCtrl.h"
#include "afxdialogex.h"


// CLoadbuttonCtrl 대화 상자입니다.

IMPLEMENT_DYNAMIC(CLoadbuttonCtrl, CDialogEx)

CLoadbuttonCtrl::CLoadbuttonCtrl(CWnd* pParent /*=NULL*/)
	: CDialogEx(CLoadbuttonCtrl::IDD, pParent)
{

}

CLoadbuttonCtrl::~CLoadbuttonCtrl()
{
}

void CLoadbuttonCtrl::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CLoadbuttonCtrl, CDialogEx)
END_MESSAGE_MAP()


// CLoadbuttonCtrl 메시지 처리기입니다.
