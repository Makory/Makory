// EdittapCtrl.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "Makory.h"
#include "FishingDlg.h"
#include "afxdialogex.h"


// CFishingDlg ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CFishingDlg, CDialogEx)

CFishingDlg::CFishingDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CFishingDlg::IDD, pParent)
{

}

CFishingDlg::~CFishingDlg()
{
}

void CFishingDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CFishingDlg, CDialogEx)
	ON_EN_CHANGE(IDC_EDIT1, &CFishingDlg::OnEnChangeEdit1)
END_MESSAGE_MAP()


// CFishingDlg �޽��� ó�����Դϴ�.


void CFishingDlg::OnEnChangeEdit1()
{
	// TODO:  RICHEDIT ��Ʈ���� ���, �� ��Ʈ����
	// CDialogEx::OnInitDialog() �Լ��� ������ 
	//�ϰ� ����ũ�� OR �����Ͽ� ������ ENM_CHANGE �÷��׸� �����Ͽ� CRichEditCtrl().SetEventMask()�� ȣ������ ������
	// �� �˸� �޽����� ������ �ʽ��ϴ�.

	// TODO:  ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}
