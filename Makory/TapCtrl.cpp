// TapCtrl.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "Makory.h"
#include "TapCtrl.h"
#include "afxdialogex.h"


// CTapCtrl ��ȭ �����Դϴ�.

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


// CTapCtrl �޽��� ó�����Դϴ�.
