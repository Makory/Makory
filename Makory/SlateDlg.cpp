// EdittapCtrl.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "Makory.h"
#include "SlateDlg.h"
#include "afxdialogex.h"
#include "Film.h"
#include "MainFrm.h"
#include "MakoryDoc.h"
#include "MakoryView.h"

// CSlateDlg ��ȭ �����Դϴ�.

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
	DDX_Control(pDX, IDC_SLATE_RED_SLIDER, mSlateRedS);
	DDX_Control(pDX, IDC_SLATE_RED_VALUE, mSlateRedValue);
	DDX_Control(pDX, IDC_SLATE_GREEN_SLIDER, mSlateGreenS);
	DDX_Control(pDX, IDC_SLATE_GREEN_VALUE, mSlateGreenValue);
	DDX_Control(pDX, IDC_SLATE_BLUE_SLIDER, mSlateBlueS);
	DDX_Control(pDX, IDC_SLATE_BLUE_VALUE, mSlateBlueValue);
	DDX_Control(pDX, IDC_SLATE_VSCROLL, mSlateVSlider);
	DDX_Control(pDX, IDC_SLATE_HSCROOL, mSlateHSlider);
	DDX_Control(pDX, IDC_SLATE_V_VALUE, mSlateVEdit);
	DDX_Control(pDX, IDC_SLATE_H_VALUE, mSlateHEdit);
	DDX_Control(pDX, IDC_SLATE_SCALE_SLIDER, mSlateScaleSlider);
	DDX_Control(pDX, IDC_SLATE_SCALE_VALUE, mSlateScaleEdit);

	//2�� ������Ʈ �缱�� ���� �͵�

	DDX_Control(pDX, IDC_SLATE_RED_SLIDER2, mSlateRedS2);
	DDX_Control(pDX, IDC_SLATE_RED_VALUE2, mSlateRedValue2);
	DDX_Control(pDX, IDC_SLATE_GREEN_SLIDER2, mSlateGreenS2);
	DDX_Control(pDX, IDC_SLATE_GREEN_VALUE2, mSlateGreenValue2);
	DDX_Control(pDX, IDC_SLATE_BLUE_SLIDER2, mSlateBlueS2);
	DDX_Control(pDX, IDC_SLATE_BLUE_VALUE2, mSlateBlueValue2);
	DDX_Control(pDX, IDC_SLATE_COMBO, mSlateCombo);
}


BEGIN_MESSAGE_MAP(CSlateDlg, CDialogEx)
	ON_WM_HSCROLL()
	ON_EN_UPDATE(IDC_SLATE_RED_VALUE, &CSlateDlg::OnEnUpdateSlateRedValue)
	ON_EN_UPDATE(IDC_SLATE_GREEN_VALUE, &CSlateDlg::OnEnUpdateSlateGreenValue)
	ON_EN_UPDATE(IDC_SLATE_BLUE_VALUE, &CSlateDlg::OnEnUpdateSlateBlueValue)
	ON_EN_UPDATE(IDC_SLATE_V_VALUE, &CSlateDlg::OnEnUpdateSlateVEdit)
	ON_EN_UPDATE(IDC_SLATE_H_VALUE, &CSlateDlg::OnEnUpdateSlateHEdit)
	ON_EN_UPDATE(IDC_SLATE_SCALE_VALUE, &CSlateDlg::OnEnUpdateSlateScaleEdit)
	ON_EN_UPDATE(IDC_SLATE_RED_VALUE2, &CSlateDlg::OnEnUpdateSlateRedValue2)
	ON_EN_UPDATE(IDC_SLATE_GREEN_VALUE2, &CSlateDlg::OnEnUpdateSlateGreenValue2)
	ON_EN_UPDATE(IDC_SLATE_BLUE_VALUE2, &CSlateDlg::OnEnUpdateSlateBlueValue2)
	ON_CBN_SELCHANGE(IDC_SLATE_COMBO, &CSlateDlg::OnCbnSelchangeSlateCombo)
END_MESSAGE_MAP()


// CSlateDlg �޽��� ó�����Դϴ�.

BOOL CSlateDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
	mSlateRedS2.ShowWindow(SW_SHOW);
	mSlateRedValue2.ShowWindow(SW_SHOW);
	mSlateGreenS2.ShowWindow(SW_SHOW);
	mSlateGreenValue2.ShowWindow(SW_SHOW);
	mSlateBlueS2.ShowWindow(SW_SHOW);
	mSlateBlueValue2.ShowWindow(SW_SHOW);

	mSlateRedS.ShowWindow(SW_HIDE);
	mSlateRedValue.ShowWindow(SW_HIDE);
	mSlateGreenS.ShowWindow(SW_HIDE);
	mSlateGreenValue.ShowWindow(SW_HIDE);
	mSlateBlueS.ShowWindow(SW_HIDE);
	mSlateBlueValue.ShowWindow(SW_HIDE);


	//red �����̴�
	mSlateRedS.SetPos(255);//�����̴� ó�� ��ġ
	mSlateRedS.SetRange(0, 255); //�����̴� ���� 0 ~ 100���� ��.
	mSlateRedS.SetPageSize(10); //�����̴��� Ŭ������ �� �����̴� ����. 
	mSlateRedValue.SetWindowTextA("255");//red edit�ڽ� �ʱⰪ

	//green �����̴�
	mSlateGreenS.SetPos(255);//�����̴� ó�� ��ġ
	mSlateGreenS.SetRange(0, 255); //�����̴� ���� 0 ~ 100���� ��.
	mSlateGreenS.SetPageSize(10);  //�����̴��� Ŭ������ �� �����̴� ����
	mSlateGreenValue.SetWindowTextA("255");//green edit�ڽ� �ʱⰪ

	//blue �����̴�
	mSlateBlueS.SetPos(255);//�����̴� ó�� ��ġ
	mSlateBlueS.SetRange(0, 255); //�����̴� ���� 0 ~ 100���� ��.
	mSlateBlueS.SetPageSize(10);  //�����̴��� Ŭ������ �� �����̴� ����
	mSlateBlueValue.SetWindowTextA("255");//blue edit�ڽ� �ʱⰪ

	//���������̴�
	mSlateVSlider.SetPos(50);//�����̴� ó�� ��ġ
	mSlateVSlider.SetRange(0, 100); //�����̴� ���� 0 ~ 100���� ��.
	mSlateVSlider.SetPageSize(1);  //�����̴��� Ŭ������ �� �����̴� ����
	mSlateVEdit.SetWindowTextA("0");//v edit�ڽ� �ʱⰪ

	//���򽽶��̴�
	mSlateHSlider.SetPos(50);//�����̴� ó�� ��ġ
	mSlateHSlider.SetRange(0, 100); //�����̴� ���� 0 ~ 100���� ��.
	mSlateHSlider.SetPageSize(1);  //�����̴��� Ŭ������ �� �����̴� ����
	mSlateHEdit.SetWindowTextA("0");//h edit�ڽ� �ʱⰪ

	//ũ��
	mSlateScaleSlider.SetPos(50);//�����̴� ó�� ��ġ
	mSlateScaleSlider.SetRange(0, 100); //�����̴� ���� 0 ~ 100���� ��.
	mSlateScaleSlider.SetPageSize(1);  //�����̴��� Ŭ������ �� �����̴� ����
	mSlateScaleEdit.SetWindowTextA("0");//h edit�ڽ� �ʱⰪ  

	//�޺��ڽ� 
	mSlateCombo.AddString("�׵θ�");
	mSlateCombo.AddString("�缱");
	mSlateCombo.SetCurSel(0); //�޺��ڽ� �⺻ ���� �缱

	//red �����̴�
	mSlateRedS2.SetPos(255);//�����̴� ó�� ��ġ
	mSlateRedS2.SetRange(0, 255); //�����̴� ���� 0 ~ 100���� ��.
	mSlateRedS2.SetPageSize(10); //�����̴��� Ŭ������ �� �����̴� ����. 
	mSlateRedValue2.SetWindowTextA("255");//red edit�ڽ� �ʱⰪ

	//green �����̴�
	mSlateGreenS2.SetPos(255);//�����̴� ó�� ��ġ
	mSlateGreenS2.SetRange(0, 255); //�����̴� ���� 0 ~ 100���� ��.
	mSlateGreenS2.SetPageSize(10);  //�����̴��� Ŭ������ �� �����̴� ����
	mSlateGreenValue2.SetWindowTextA("255");//green edit�ڽ� �ʱⰪ

	//blue �����̴�
	mSlateBlueS2.SetPos(0);//�����̴� ó�� ��ġ
	mSlateBlueS2.SetRange(0, 255); //�����̴� ���� 0 ~ 100���� ��.
	mSlateBlueS2.SetPageSize(10);  //�����̴��� Ŭ������ �� �����̴� ����
	mSlateBlueValue2.SetWindowTextA("0");//blue edit�ڽ� �ʱⰪ

	return TRUE;  // return TRUE unless you set the focus to a control
	// ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
}

//��� �ʿ������...�ϴ� ������� ���߿� ���ִ°ɷ�..
void CSlateDlg::ChangeScaleTo(int Slatescale)
{	/*
	//int Slateredsliderpos;
	//mSlateRedS.SetPos(Slateredcolor); //��� ��ģ���� ȣ���
	Slateredsliderpos = mSlateRedS.GetPos();
	CString strredpos;
	strredpos.Format(_T("%d"), Slateredsliderpos); //����ȯ
	mSlateRedValue.SetWindowTextA(strredpos);*/

}

//�����̴� �������� ��
void CSlateDlg::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	CMainFrame* pFrame = (CMainFrame*)AfxGetMainWnd();				//Viewȣ��
	CMakoryView* pView = (CMakoryView*)pFrame->GetActiveView();		//Viewȣ��

	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	if(pScrollBar)
	{
		// � �����̴����� �˻�
		//red slider�� �������� ���
		if(pScrollBar == (CScrollBar*)&mSlateRedS)//Slate red slider�ΰ��
		{

			// �����̴��� ��ġ�� �˻��Ѵ�.
			int npos = mSlateRedS.GetPos(); //�����̴� ��ġ ����
			CString str;
			str.Format(_T("%d"), npos); //����ȯ
			mSlateRedValue.SetWindowTextA(str); //edit �ڽ��� �����̴� �� ��

			fpos = (double)npos * 0.00392156; //�����̴��� �Ҽ����� ����� �ȵ�

			pView->Film.slatered=fpos;//ǳ�� ���������� �ٲ���
			pView->Invalidate(FALSE);
		}

		//green�����̴� �������� ���
		else if(pScrollBar == (CScrollBar*)&mSlateGreenS)//Slate green slider�ΰ��
		{

			// �����̴��� ��ġ�� �˻��Ѵ�.
			int npos = mSlateGreenS.GetPos(); //�����̴� ��ġ ����
			CString str;
			str.Format(_T("%d"), npos); //����ȯ
			mSlateGreenValue.SetWindowTextA(str);// edit �ڽ��� �����̴� �� ��

			fpos = (double)npos * 0.00392156; //�����̴��� �Ҽ����� ����� �ȵ�

			pView->Film.slategreen=fpos; //ǳ�� ������� �ٲ���
			pView->Invalidate(FALSE);
		}



		//blue �����̴� �������� ���
		else if(pScrollBar == (CScrollBar*)&mSlateBlueS)//Slate green slider�ΰ��
		{

			// �����̴��� ��ġ�� �˻��Ѵ�.
			int npos = mSlateBlueS.GetPos(); //�����̴� ��ġ ����
			CString str;
			str.Format(_T("%d"), npos); //����ȯ
			mSlateBlueValue.SetWindowTextA(str); //blue edit �ڽ��� �����̴� �� ��

			fpos = (double)npos * 0.00392156; //�����̴��� �Ҽ����� ����� �ȵ�

			pView->Film.slateblue=fpos; //ǳ�� �Ķ������� �ٲ���
			pView->Invalidate(FALSE);
		}

		//ũ�� �����̴� �������� ���
		else if(pScrollBar == (CScrollBar*)&mSlateScaleSlider)//���� �����̴��ΰ��
		{

			// �����̴��� ��ġ�� �˻��Ѵ�.
			int npos = mSlateScaleSlider.GetPos(); //�����̴� ��ġ ����
			CString str;
			str.Format(_T("%d"), npos-50); //����ȯ
			mSlateScaleEdit.SetWindowTextA(str); //edit �ڽ��� �����̴� �� ��


			if(npos <= 50){ //�����̴��� 50�����϶�
				fpos = 4*(-0.5+((double)npos * 0.01)); //�������� �̵� 
			} 
			else if(npos >= 50){  //�����̴��� 50�̻��϶�
				fpos = 4*(((double)npos * 0.01)-0.5); //���������� �̵�
			}

			pView->Film.SlateScale=3.0+fpos; //filmscale���� �ٲ���
			pView->Invalidate(FALSE);
		}

		//���� �����̴� �������� ���
		else if(pScrollBar == (CScrollBar*)&mSlateVSlider)//���� �����̴��ΰ��
		{

			// �����̴��� ��ġ�� �˻��Ѵ�.
			int npos = mSlateVSlider.GetPos(); //�����̴� ��ġ ����
			CString str;
			str.Format(_T("%d"), npos-50); //����ȯ
			mSlateVEdit.SetWindowTextA(str); //edit �ڽ��� �����̴� �� ��


			if(npos <= 50){ //�����̴��� 50�����϶�
				fpos = -0.5+((double)npos * 0.01); //�������� �̵� 
			} 
			else if(npos >= 50){  //�����̴��� 50�̻��϶�
				fpos = ((double)npos * 0.01)-0.5; //���������� �̵�
			}

			pView->Film.slatey2=fpos; //Slatey���� �ٲ���
			pView->Film.slatey=fpos; //Slatey���� �ٲ���
			pView->Invalidate(FALSE);
		}
		//���� �����̴� �������� ���
		else if(pScrollBar == (CScrollBar*)&mSlateHSlider)//���� �����̴��ΰ��
		{

			// �����̴��� ��ġ�� �˻��Ѵ�.
			int npos = mSlateHSlider.GetPos(); //�����̴� ��ġ ����

			CString str;
			str.Format(_T("%d"), npos-50); //����ȯ
			mSlateHEdit.SetWindowTextA(str); //edit �ڽ��� �����̴� �� ��

			if(npos <= 50){ //�����̴��� 50�����϶�
				fpos = 2*(-0.5+((double)npos * 0.01)); //������ �̵� 

			} 
			else if(npos >= 50){  //�����̴��� 50�̻��϶�
				fpos = 2*(((double)npos * 0.01)-0.5); //�Ʒ������� �̵�
			}

			pView->Film.slatex2=fpos; //Slatex���� �ٲ���
			pView->Film.slatex=fpos;


			pView->Invalidate(FALSE);
		}

		//������Ʈ �缱
		//red slider�� �������� ���
		if(pScrollBar == (CScrollBar*)&mSlateRedS2)//Slate red slider�ΰ��
		{

			// �����̴��� ��ġ�� �˻��Ѵ�.
			int npos = mSlateRedS2.GetPos(); //�����̴� ��ġ ����
			CString str;
			str.Format(_T("%d"), npos); //����ȯ
			mSlateRedValue2.SetWindowTextA(str); //edit �ڽ��� �����̴� �� ��

			fpos = (double)npos * 0.00392156; //�����̴��� �Ҽ����� ����� �ȵ�

			pView->Film.slatered2=fpos;//ǳ�� ���������� �ٲ���
			pView->Invalidate(FALSE);
		}

		//green�����̴� �������� ���
		else if(pScrollBar == (CScrollBar*)&mSlateGreenS2)//Slate green slider�ΰ��
		{

			// �����̴��� ��ġ�� �˻��Ѵ�.
			int npos = mSlateGreenS2.GetPos(); //�����̴� ��ġ ����
			CString str;
			str.Format(_T("%d"), npos); //����ȯ
			mSlateGreenValue2.SetWindowTextA(str);// edit �ڽ��� �����̴� �� ��

			fpos = (double)npos * 0.00392156; //�����̴��� �Ҽ����� ����� �ȵ�

			pView->Film.slategreen2=fpos; //ǳ�� ������� �ٲ���
			pView->Invalidate(FALSE);
		}



		//blue �����̴� �������� ���
		else if(pScrollBar == (CScrollBar*)&mSlateBlueS2)//Slate green slider�ΰ��
		{

			// �����̴��� ��ġ�� �˻��Ѵ�.
			int npos = mSlateBlueS2.GetPos(); //�����̴� ��ġ ����
			CString str;
			str.Format(_T("%d"), npos); //����ȯ
			mSlateBlueValue2.SetWindowTextA(str); //blue edit �ڽ��� �����̴� �� ��

			fpos = (double)npos * 0.00392156; //�����̴��� �Ҽ����� ����� �ȵ�

			pView->Film.slateblue2=fpos; //ǳ�� �Ķ������� �ٲ���
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
void CSlateDlg::OnEnUpdateSlateRedValue()
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

		mSlateRedValue.GetWindowTextA(String);
		ipos = _ttoi(String);
		mSlateRedS.SetPos(ipos);
		dpos = (double)ipos * 0.00392156; //�����̴��� �Ҽ����� ����� �ȵ�

		pView->Film.slatered=dpos;//ǳ�� ���������� �ٲ���
		pView->Invalidate(FALSE);
	}
}

//green edit
void CSlateDlg::OnEnUpdateSlateGreenValue()
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

		mSlateGreenValue.GetWindowTextA(String);
		ipos = _ttoi(String);
		mSlateGreenS.SetPos(ipos);
		dpos = (double)ipos * 0.00392156; //�����̴��� �Ҽ����� ����� �ȵ�
		pView->Film.slategreen=dpos;//ǳ�� ���������� �ٲ���

		pView->Invalidate(FALSE);
	}
}

//blue edit
void CSlateDlg::OnEnUpdateSlateBlueValue()
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

		mSlateBlueValue.GetWindowTextA(String);
		ipos = _ttoi(String);
		mSlateBlueS.SetPos(ipos);
		dpos = (double)ipos * 0.00392156; //�����̴��� �Ҽ����� ����� �ȵ�
		pView->Film.slateblue=dpos;//ǳ�� ���������� �ٲ���

		pView->Invalidate(FALSE);
	}


}

//���� edit
void CSlateDlg::OnEnUpdateSlateHEdit()
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

		mSlateHEdit.GetWindowTextA(String);

		ipos = _ttoi(String)+50;
		mSlateHSlider.SetPos(ipos);

		if(ipos <= 50){ //�����̴��� 50�����϶�

			dpos = 2*(-0.5+((double)ipos * 0.01)); //�������� �̵� 

		} 
		else if(ipos >= 50){  //�����̴��� 50�̻��϶�
			dpos = 2*(((double)ipos * 0.01)-0.5); //���������� �̵�
		}
		pView->Film.slatex=dpos; //Slatex���� �ٲ���
		pView->Film.slatex2=dpos; //Slatex���� �ٲ���
		pView->Invalidate(FALSE);
	}

}
//���� Edit
void CSlateDlg::OnEnUpdateSlateVEdit()
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

		mSlateVEdit.GetWindowTextA(String);

		ipos =_ttoi(String)+50;

		mSlateVSlider.SetPos(ipos);

		if(ipos <= 50){ //�����̴��� 50�����϶�

			dpos = -0.5+((double)ipos * 0.01); //�������� �̵� 

		} 
		else if(ipos >= 50){  //�����̴��� 50�̻��϶�
			dpos = ((double)ipos * 0.01)-0.5; //���������� �̵�
		}

		pView->Film.slatey2=dpos; //Slatey���� �ٲ���
		pView->Film.slatey=dpos; //Slatey���� �ٲ���
		pView->Invalidate(FALSE);
	}
}

//ũ�� edit
void CSlateDlg::OnEnUpdateSlateScaleEdit()
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

		mSlateScaleEdit.GetWindowTextA(String);

		ipos = _ttoi(String)+50;
		mSlateScaleSlider.SetPos(ipos);
		if (ipos<0){
			ipos = 0;
			dpos = 4*(-0.5+((double)ipos * 0.01)); //�������� �̵� //�������� �̵� 
			pView->Film.SlateScale=3.0+dpos; //filmy���� �ٲ���
			pView->Invalidate(FALSE);
		}
		else if(ipos<100){
			if(ipos <= 50){ //�����̴��� 50�����϶�

				dpos = 4*(-0.5+((double)ipos * 0.01)); //�������� �̵� 

			} 
			else if(ipos >= 50){  //�����̴��� 50�̻��϶�
				dpos = 4*(((double)ipos * 0.01)-0.5); //���������� �̵�
			}

			pView->Film.SlateScale=3.0+dpos; //filmy���� �ٲ���
			pView->Invalidate(FALSE);
		}

		else if(ipos>100){
			ipos = 100;
			dpos = 4*(((double)ipos * 0.01)-0.5); //���������� �̵�
			pView->Film.SlateScale=3.0+dpos; //filmy���� �ٲ���
			pView->Invalidate(FALSE);

		}
	}
}

//�缱 edit

//RED edit
void CSlateDlg::OnEnUpdateSlateRedValue2()
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

		mSlateRedValue2.GetWindowTextA(String);
		ipos = _ttoi(String);
		mSlateRedS2.SetPos(ipos);
		dpos = (double)ipos * 0.00392156; //�����̴��� �Ҽ����� ����� �ȵ�

		pView->Film.slatered2=dpos;//ǳ�� ���������� �ٲ���
		pView->Invalidate(FALSE);
	}
}

//green edit
void CSlateDlg::OnEnUpdateSlateGreenValue2()
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

		mSlateGreenValue2.GetWindowTextA(String);
		ipos = _ttoi(String);
		mSlateGreenS2.SetPos(ipos);
		dpos = (double)ipos * 0.00392156; //�����̴��� �Ҽ����� ����� �ȵ�
		pView->Film.slategreen2=dpos;//ǳ�� ���������� �ٲ���

		pView->Invalidate(FALSE);
	}
}

//blue edit
void CSlateDlg::OnEnUpdateSlateBlueValue2()
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

		mSlateBlueValue2.GetWindowTextA(String);
		ipos = _ttoi(String);
		mSlateBlueS2.SetPos(ipos);
		dpos = (double)ipos * 0.00392156; //�����̴��� �Ҽ����� ����� �ȵ�
		pView->Film.slateblue2=dpos;//ǳ�� ���������� �ٲ���

		pView->Invalidate(FALSE);
	}


}

//�޺� �ڽ� ���ý�
void CSlateDlg::OnCbnSelchangeSlateCombo()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	//�׵θ�����
	if(mSlateCombo.GetCurSel()==1){

		mSlateRedS.ShowWindow(SW_SHOW);
		mSlateRedValue.ShowWindow(SW_SHOW);
		mSlateGreenS.ShowWindow(SW_SHOW);
		mSlateGreenValue.ShowWindow(SW_SHOW);
		mSlateBlueS.ShowWindow(SW_SHOW);
		mSlateBlueValue.ShowWindow(SW_SHOW);
		mSlateRedS2.ShowWindow(SW_HIDE);
		mSlateRedValue2.ShowWindow(SW_HIDE);
		mSlateGreenS2.ShowWindow(SW_HIDE);
		mSlateGreenValue2.ShowWindow(SW_HIDE);
		//mSlateBlueS2.ShowWindow(SW_HIDE);
		//mSlateBlueValue2.ShowWindow(SW_HIDE);
	}
	//�缱 ���� 
	else if(mSlateCombo.GetCurSel()==0){
		mSlateRedS2.ShowWindow(SW_SHOW);
		mSlateRedValue2.ShowWindow(SW_SHOW);
		mSlateGreenS2.ShowWindow(SW_SHOW);
		mSlateGreenValue2.ShowWindow(SW_SHOW);
		mSlateBlueS2.ShowWindow(SW_SHOW);
		mSlateBlueValue2.ShowWindow(SW_SHOW);
		mSlateRedS.ShowWindow(SW_HIDE);
		mSlateRedValue.ShowWindow(SW_HIDE);
		mSlateGreenS.ShowWindow(SW_HIDE);
		mSlateGreenValue.ShowWindow(SW_HIDE);
		//mSlateBlueS.ShowWindow(SW_HIDE);
		//mSlateBlueValue.ShowWindow(SW_HIDE);
	}

}
