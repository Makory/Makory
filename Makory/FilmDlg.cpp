// EdittapCtrl.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "Makory.h"
#include "FilmDlg.h"
#include "afxdialogex.h"
#include "Film.h"
#include "MainFrm.h"
#include "MakoryDoc.h"
#include "MakoryView.h"

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
	DDX_Control(pDX, IDC_FILM_RED_SLIDER, mFilmRedS);
	DDX_Control(pDX, IDC_FILM_RED_VALUE, mFilmRedValue);
	DDX_Control(pDX, IDC_FILM_GREEN_SLIDER, mFilmGreenS);
	DDX_Control(pDX, IDC_FILM_GREEN_VALUE, mFilmGreenValue);
	DDX_Control(pDX, IDC_FILM_BLUE_SLIDER, mFilmBlueS);
	DDX_Control(pDX, IDC_FILM_BLUE_VALUE, mFilmBlueValue);
	DDX_Control(pDX, IDC_FILM_SCALE_SLIDER, mFilmScaleSlider);
	DDX_Control(pDX, IDC_FILM_SCALE_VALUE, mFilmScaleEdit);
}


BEGIN_MESSAGE_MAP(CFilmDlg, CDialogEx)
	ON_WM_HSCROLL()
	ON_EN_UPDATE(IDC_FILM_RED_VALUE, &CFilmDlg::OnEnUpdateFilmRedValue)
	ON_EN_UPDATE(IDC_FILM_GREEN_VALUE, &CFilmDlg::OnEnUpdateFilmGreenValue)
	ON_EN_UPDATE(IDC_FILM_BLUE_VALUE, &CFilmDlg::OnEnUpdateFilmBlueValue)
	ON_EN_UPDATE(IDC_FILM_SCALE_VALUE, &CFilmDlg::OnEnUpdateFilmScaleEdit)
	
END_MESSAGE_MAP()


// CFilmDlg �޽��� ó�����Դϴ�.

BOOL CFilmDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
	//red �����̴�
	mFilmRedS.SetPos(255);//�����̴� ó�� ��ġ
	mFilmRedS.SetRange(0, 255); //�����̴� ���� 0 ~ 100���� ��.
	mFilmRedS.SetPageSize(10); //�����̴��� Ŭ������ �� �����̴� ����. 
	mFilmRedValue.SetWindowTextA("255");//red edit�ڽ� �ʱⰪ

	//green �����̴�
	mFilmGreenS.SetPos(255);//�����̴� ó�� ��ġ
	mFilmGreenS.SetRange(0, 255); //�����̴� ���� 0 ~ 100���� ��.
	mFilmGreenS.SetPageSize(10);  //�����̴��� Ŭ������ �� �����̴� ����
	mFilmGreenValue.SetWindowTextA("255");//green edit�ڽ� �ʱⰪ

	//blue �����̴�
	mFilmBlueS.SetPos(255);//�����̴� ó�� ��ġ
	mFilmBlueS.SetRange(0, 255); //�����̴� ���� 0 ~ 100���� ��.
	mFilmBlueS.SetPageSize(10);  //�����̴��� Ŭ������ �� �����̴� ����
	mFilmBlueValue.SetWindowTextA("255");//blue edit�ڽ� �ʱⰪ

	//ũ�� �����̴�
	mFilmScaleSlider.SetPos(50);//�����̴� ó�� ��ġ
	mFilmScaleSlider.SetRange(0, 100); //�����̴� ���� 0 ~ 100���� ��.
	mFilmScaleSlider.SetPageSize(1);  //�����̴��� Ŭ������ �� �����̴� ����
	mFilmScaleEdit.SetWindowTextA("0");//v edit�ڽ� �ʱⰪ



	return TRUE;  // return TRUE unless you set the focus to a control
	// ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
}


//�����̴� �������� ��
void CFilmDlg::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	CMainFrame* pFrame = (CMainFrame*)AfxGetMainWnd();				//Viewȣ��
	CMakoryView* pView = (CMakoryView*)pFrame->GetActiveView();		//Viewȣ��
	
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	if(pScrollBar)
	{
		// � �����̴����� �˻�
		//red slider�� �������� ���
		if(pScrollBar == (CScrollBar*)&mFilmRedS)//film red slider�ΰ��
		{
			
			// �����̴��� ��ġ�� �˻��Ѵ�.
 			int npos = mFilmRedS.GetPos(); //�����̴� ��ġ ����
			CString str;
			str.Format(_T("%d"), npos); //����ȯ
			mFilmRedValue.SetWindowTextA(str); //edit �ڽ��� �����̴� �� ��

			fpos = (double)npos * 0.00392156; //�����̴��� �Ҽ����� ����� �ȵ�

			pView->Film.filmred=fpos;//ǳ�� ���������� �ٲ���
			pView->Invalidate(FALSE);
		}

		//green�����̴� �������� ���
		else if(pScrollBar == (CScrollBar*)&mFilmGreenS)//film green slider�ΰ��
		{
			
			// �����̴��� ��ġ�� �˻��Ѵ�.
 			int npos = mFilmGreenS.GetPos(); //�����̴� ��ġ ����
			CString str;
			str.Format(_T("%d"), npos); //����ȯ
			mFilmGreenValue.SetWindowTextA(str);// edit �ڽ��� �����̴� �� ��

			fpos = (double)npos * 0.00392156; //�����̴��� �Ҽ����� ����� �ȵ�

			pView->Film.filmgreen=fpos; //ǳ�� ������� �ٲ���
			pView->Invalidate(FALSE);
		}

	

		//blue �����̴� �������� ���
		else if(pScrollBar == (CScrollBar*)&mFilmBlueS)//film green slider�ΰ��
		{

			// �����̴��� ��ġ�� �˻��Ѵ�.
			int npos = mFilmBlueS.GetPos(); //�����̴� ��ġ ����
			CString str;
			str.Format(_T("%d"), npos); //����ȯ
			mFilmBlueValue.SetWindowTextA(str); //blue edit �ڽ��� �����̴� �� ��

			fpos = (double)npos * 0.00392156; //�����̴��� �Ҽ����� ����� �ȵ�

			pView->Film.filmblue=fpos; //ǳ�� �Ķ������� �ٲ���
			pView->Invalidate(FALSE);
		}

		//ũ�� �����̴� �������� ���
		else if(pScrollBar == (CScrollBar*)&mFilmScaleSlider)//���� �����̴��ΰ��
		{

			// �����̴��� ��ġ�� �˻��Ѵ�.
			int npos = mFilmScaleSlider.GetPos(); //�����̴� ��ġ ����
			CString str;
			str.Format(_T("%d"), npos-50); //����ȯ
			mFilmScaleEdit.SetWindowTextA(str); //edit �ڽ��� �����̴� �� ��

			
			if(npos <= 50){ //�����̴��� 50�����϶�
				fpos = 2*(-0.5+((double)npos * 0.01)); //�������� �̵� 
			} 
			else if(npos >= 50){  //�����̴��� 50�̻��϶�
				fpos = ((double)npos * 0.01)-0.5; //���������� �̵�
			}

			pView->Film.FilmScale=2.5+fpos; //filmscale���� �ٲ���
			pView->Invalidate(FALSE);
		}
		
	}

	else
	{
	// CScrollView�� ��ӹ��� ���� ��� �������� ��ũ�ѷ� ���۽� pScrollBar�� NULL�ȴ�.
	}
	CDialogEx::OnHScroll(nSBCode, nPos, pScrollBar);
}

//RED edit
void CFilmDlg::OnEnUpdateFilmRedValue()
{
	// TODO:  RICHEDIT ��Ʈ���� ���, �� ��Ʈ����
	// CDialogEx::OnInitDialog() �Լ��� ������ 
	//�Ͽ�, IParam ����ũ�� OR �����Ͽ� ������ ENM_SCROLL �÷��׸� �����Ͽ� ��Ʈ�ѿ� EM_SETEVENTMASK �޽����� ������ ������
	// ���� ��Ʈ���� �ٲ� �ؽ�Ʈ�� ǥ���Ϸ��� ���� ��Ÿ���ϴ�.

	// TODO:  ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	CMainFrame* pFrame = (CMainFrame*)AfxGetMainWnd();            //Viewȣ��
	CMakoryView* pView = (CMakoryView*)pFrame->GetActiveView();      //Viewȣ��

	if(UpdateData(TRUE)){

		int ipos;
		double dpos;
		CString String;

		mFilmRedValue.GetWindowTextA(String);
		ipos = _ttoi(String);
		mFilmRedS.SetPos(ipos);
		dpos = (double)ipos * 0.00392156; //�����̴��� �Ҽ����� ����� �ȵ�

		pView->Film.filmred=dpos;//ǳ�� ���������� �ٲ���
		pView->Invalidate(FALSE);
	}
}

//green edit
void CFilmDlg::OnEnUpdateFilmGreenValue()
{
	// TODO:  RICHEDIT ��Ʈ���� ���, �� ��Ʈ����
	// CDialogEx::OnInitDialog() �Լ��� ������ 
	//�Ͽ�, IParam ����ũ�� OR �����Ͽ� ������ ENM_SCROLL �÷��׸� �����Ͽ� ��Ʈ�ѿ� EM_SETEVENTMASK �޽����� ������ ������
	// ���� ��Ʈ���� �ٲ� �ؽ�Ʈ�� ǥ���Ϸ��� ���� ��Ÿ���ϴ�.

	// TODO:  ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	CMainFrame* pFrame = (CMainFrame*)AfxGetMainWnd();            //Viewȣ��
	CMakoryView* pView = (CMakoryView*)pFrame->GetActiveView();      //Viewȣ��

	if(UpdateData(TRUE)){

		int ipos;
		double dpos;
		CString String;

		mFilmGreenValue.GetWindowTextA(String);
		ipos = _ttoi(String);
		mFilmGreenS.SetPos(ipos);
		dpos = (double)ipos * 0.00392156; //�����̴��� �Ҽ����� ����� �ȵ�
		pView->Film.filmgreen=dpos;//ǳ�� ���������� �ٲ���

		pView->Invalidate(FALSE);
	}
}

//blue edit
void CFilmDlg::OnEnUpdateFilmBlueValue()
{
	// TODO:  RICHEDIT ��Ʈ���� ���, �� ��Ʈ����
	// CDialogEx::OnInitDialog() �Լ��� ������ 
	//�Ͽ�, IParam ����ũ�� OR �����Ͽ� ������ ENM_SCROLL �÷��׸� �����Ͽ� ��Ʈ�ѿ� EM_SETEVENTMASK �޽����� ������ ������
	// ���� ��Ʈ���� �ٲ� �ؽ�Ʈ�� ǥ���Ϸ��� ���� ��Ÿ���ϴ�.

	// TODO:  ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	CMainFrame* pFrame = (CMainFrame*)AfxGetMainWnd();            //Viewȣ��
	CMakoryView* pView = (CMakoryView*)pFrame->GetActiveView();      //Viewȣ��

	if(UpdateData(TRUE)){

		int ipos;
		double dpos;
		CString String;

		mFilmBlueValue.GetWindowTextA(String);
		ipos = _ttoi(String);
		mFilmBlueS.SetPos(ipos);
		dpos = (double)ipos * 0.00392156; //�����̴��� �Ҽ����� ����� �ȵ�
		pView->Film.filmblue=dpos;//ǳ�� ���������� �ٲ���

		pView->Invalidate(FALSE);
	}
}

//ũ�� edit
void CFilmDlg::OnEnUpdateFilmScaleEdit()
{
	// TODO:  RICHEDIT ��Ʈ���� ���, �� ��Ʈ����
	// CDialogEx::OnInitDialog() �Լ��� ������ 
	//�Ͽ�, IParam ����ũ�� OR �����Ͽ� ������ ENM_SCROLL �÷��׸� �����Ͽ� ��Ʈ�ѿ� EM_SETEVENTMASK �޽����� ������ ������
	// ���� ��Ʈ���� �ٲ� �ؽ�Ʈ�� ǥ���Ϸ��� ���� ��Ÿ���ϴ�.

	// TODO:  ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	CMainFrame* pFrame = (CMainFrame*)AfxGetMainWnd();            //Viewȣ��
	CMakoryView* pView = (CMakoryView*)pFrame->GetActiveView();      //Viewȣ��

	if(UpdateData(TRUE)){

		int ipos;
		double dpos;
		CString String;

		mFilmScaleEdit.GetWindowTextA(String);

		ipos = _ttoi(String)+50;
		mFilmScaleSlider.SetPos(ipos);

		if (ipos<0){
			ipos = 0;
			dpos = 2*(-0.5+((double)ipos * 0.01)); //�������� �̵� 
			pView->Film.FilmScale=2.5+dpos; //filmy���� �ٲ���
			pView->Invalidate(FALSE);
		}
		else if(ipos<=100){
			if(ipos <= 50){ //�����̴��� 50�����϶�

				dpos = 2*(-0.5+((double)ipos * 0.01)); //�������� �̵� 

			} 
			else if(ipos >= 50){  //�����̴��� 50�̻��϶�
				dpos = ((double)ipos * 0.01)-0.5; //���������� �̵�
			}

			pView->Film.FilmScale=2.5+dpos; //filmy���� �ٲ���
			pView->Invalidate(FALSE);
		}

		else if(ipos>100){
			ipos = 100;
			dpos = ((double)ipos * 0.01)-0.5; //���������� �̵�
			pView->Film.FilmScale=2.5+dpos; //filmy���� �ٲ���
			pView->Invalidate(FALSE);

		}

	}
}
