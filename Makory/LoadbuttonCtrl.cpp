// LoadbuttonCtrl.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "Makory.h"
#include "LoadbuttonCtrl.h"
#include "afxdialogex.h"


// CLoadbuttonCtrl ��ȭ �����Դϴ�.

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


// CLoadbuttonCtrl �޽��� ó�����Դϴ�.
