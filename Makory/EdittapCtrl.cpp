// EdittapCtrl.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "Makory.h"
#include "EdittapCtrl.h"
#include "afxdialogex.h"


// CEdittapCtrl ��ȭ �����Դϴ�.

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


// CEdittapCtrl �޽��� ó�����Դϴ�.


void CEdittapCtrl::OnEnChangeEdit1()
{
	// TODO:  RICHEDIT ��Ʈ���� ���, �� ��Ʈ����
	// CDialogEx::OnInitDialog() �Լ��� ������ 
	//�ϰ� ����ũ�� OR �����Ͽ� ������ ENM_CHANGE �÷��׸� �����Ͽ� CRichEditCtrl().SetEventMask()�� ȣ������ ������
	// �� �˸� �޽����� ������ �ʽ��ϴ�.

	// TODO:  ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}
