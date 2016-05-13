// EdittapCtrl.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "Makory.h"
#include "ImageEditDlg.h"
#include "afxdialogex.h"
#include "HotAirBalloon.h"
#include "MainFrm.h"
#include "MakoryDoc.h"
#include "MakoryView.h"

// CImageEditDlg ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CImageEditDlg, CDialogEx)

CImageEditDlg::CImageEditDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CImageEditDlg::IDD, pParent)
{

}

CImageEditDlg::~CImageEditDlg()
{
}

void CImageEditDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_IMAGE_SCALE_SLIDER, mImageScaleSlider);
	DDX_Control(pDX, IDC_IMAGE_SCALE_VALUE, mImageScaleValue);
}


BEGIN_MESSAGE_MAP(CImageEditDlg, CDialogEx)
	ON_EN_CHANGE(IDC_EDIT1, &CImageEditDlg::OnEnChangeEdit1)
	ON_WM_HSCROLL()
END_MESSAGE_MAP()


// CImageEditDlg �޽��� ó�����Դϴ�.

BOOL CImageEditDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
	mImageScaleValue.SetWindowTextA("0");
	return TRUE;  // return TRUE unless you set the focus to a control
	// ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
}


void CImageEditDlg::OnEnChangeEdit1()
{
	// TODO:  RICHEDIT ��Ʈ���� ���, �� ��Ʈ����
	// CDialogEx::OnInitDialog() �Լ��� ������ 
	//�ϰ� ����ũ�� OR �����Ͽ� ������ ENM_CHANGE �÷��׸� �����Ͽ� CRichEditCtrl().SetEventMask()�� ȣ������ ������
	// �� �˸� �޽����� ������ �ʽ��ϴ�.

	// TODO:  ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}


void CImageEditDlg::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.

	CMainFrame* pFrame = (CMainFrame*)AfxGetMainWnd();				//Viewȣ��
	CMakoryView* pView = (CMakoryView*)pFrame->GetActiveView();		//Viewȣ��
	

	// �����̴��� ��ġ�� �˻��Ѵ�.
	int npos = mImageScaleSlider.GetPos(); //�����̴� ��ġ ����
	CString str;
	str.Format(_T("%d"), npos); //����ȯ
	mImageScaleValue.SetWindowTextA(str); //edit �ڽ��� �����̴� �� ��

	fpos = (double)npos * 0.002; //ũ�Ⱚ ����

	pView->HotAirBalloon.balloonscale=fpos;//ũ�Ⱚ�� �ٲ���
	pView->HotAirBalloon.darkstormyscale=fpos;
	pView->HotAirBalloon.fullmoonscale=fpos;
	pView->HotAirBalloon.mountscale=fpos;
	pView->HotAirBalloon.sunsetscale=fpos;//ũ�Ⱚ�� �ٲ���
	pView->HotAirBalloon.cloudsscale=fpos;
	pView->HotAirBalloon.tropicalscale=fpos;

	pView->Invalidate(FALSE);


	CDialogEx::OnHScroll(nSBCode, nPos, pScrollBar);
}

