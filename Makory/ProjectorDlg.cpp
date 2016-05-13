// ProjectorDlg.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "Makory.h"
#include "ProjectorDlg.h"
#include "afxdialogex.h"


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
}


BEGIN_MESSAGE_MAP(CProjectorDlg, CDialogEx)
END_MESSAGE_MAP()


// CProjectorDlg 메시지 처리기입니다.
