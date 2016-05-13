// SlateDlg.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "Makory.h"
#include "SlateDlg.h"
#include "afxdialogex.h"


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
}


BEGIN_MESSAGE_MAP(CSlateDlg, CDialogEx)
END_MESSAGE_MAP()


// CSlateDlg 메시지 처리기입니다.
