// WaveDlg.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "Makory.h"
#include "WaveDlg.h"
#include "afxdialogex.h"


// CWaveDlg 대화 상자입니다.

IMPLEMENT_DYNAMIC(CWaveDlg, CDialogEx)

CWaveDlg::CWaveDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CWaveDlg::IDD, pParent)
{

}

CWaveDlg::~CWaveDlg()
{
}

void CWaveDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CWaveDlg, CDialogEx)
END_MESSAGE_MAP()


// CWaveDlg 메시지 처리기입니다.
