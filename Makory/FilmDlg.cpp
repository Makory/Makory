// EdittapCtrl.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "Makory.h"
#include "FilmDlg.h"
#include "afxdialogex.h"


// CFilmDlg ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CFilmDlg, CDialogEx)

CFilmDlg::CFilmDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CFilmDlg::IDD, pParent)
{

}

CFilmDlg::~CFilmDlg()
{
}

void CFilmDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CFilmDlg, CDialogEx)
	ON_EN_CHANGE(IDC_EDIT1, &CFilmDlg::OnEnChangeEdit1)
	ON_EN_CHANGE(IDC_FILM_BLUE_VALUE, &CFilmDlg::OnEnChangeFilmBlueValue)
END_MESSAGE_MAP()


// CFilmDlg �޽��� ó�����Դϴ�.


void CFilmDlg::OnEnChangeEdit1()
{
	// TODO:  RICHEDIT ��Ʈ���� ���, �� ��Ʈ����
	// CDialogEx::OnInitDialog() �Լ��� ������ 
	//�ϰ� ����ũ�� OR �����Ͽ� ������ ENM_CHANGE �÷��׸� �����Ͽ� CRichEditCtrl().SetEventMask()�� ȣ������ ������
	// �� �˸� �޽����� ������ �ʽ��ϴ�.

	// TODO:  ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}


void CFilmDlg::OnEnChangeFilmBlueValue()
{
	// TODO:  RICHEDIT ��Ʈ���� ���, �� ��Ʈ����
	// CDialogEx::OnInitDialog() �Լ��� ������ 
	//�ϰ� ����ũ�� OR �����Ͽ� ������ ENM_CHANGE �÷��׸� �����Ͽ� CRichEditCtrl().SetEventMask()�� ȣ������ ������
	// �� �˸� �޽����� ������ �ʽ��ϴ�.

	// TODO:  ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}
