// EdittapCtrl.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "Makory.h"
#include "FishingDlg.h"
#include "afxdialogex.h"
#include "Ocean.h"
#include "MainFrm.h"
#include "MakoryDoc.h"
#include "MakoryView.h"


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
	DDX_Control(pDX, IDC_BOAT_RED_SLIDER, mBoatRedS);
	DDX_Control(pDX, IDC_BOAT_GREEN_SLIDER, mBoatGreenS);
	DDX_Control(pDX, IDC_BOAT_BLUE_SLIDER, mBoatBlueS);

	DDX_Control(pDX, IDC_FISHIHG_RED_SLIDER, mFishingRedS);
	DDX_Control(pDX, IDC_FISHIHG_GREEN_SLIDER, mFishingGreenS);
	DDX_Control(pDX, IDC_FISHIHG_BLUE_SLIDER, mFishingBlueS);

	DDX_Control(pDX, IDC_BOAT_RED_VALUE, mBoatRedValue);
	DDX_Control(pDX, IDC_BOAT_GREEN_VALUE, mBoatGreenValue);
	DDX_Control(pDX, IDC_BOAT_BLUE_VALUE, mBoatBlueValue);

	DDX_Control(pDX, IDC_FISHIHG_RED_VALUE, mFishingRedValue);
	DDX_Control(pDX, IDC_FISHIHG_GREEN_VALUE, mFishingGreenValue);
	DDX_Control(pDX, IDC_FISHIHG_BLUE_VALUE, mFishingBlueValue);

	DDX_Control(pDX, IDC_FISHIHGPOLE_RED_SLIDER, mFishingPRedS);
	DDX_Control(pDX, IDC_FISHIHGPOLE_GREEN_SLIDER, mFishingPGreenS);
	DDX_Control(pDX, IDC_FISHIHGPOLE_BLUE_SLIDER, mFishingPBlueS);

	DDX_Control(pDX, IDC_FISHIHGPOLE_RED_VALUE, mFishingPRedValue);
	DDX_Control(pDX, IDC_FISHIHGPOLE_GREEN_VALUE, mFishingPGreenValue);
	DDX_Control(pDX, IDC_FISHIHGPOLE_BLUE_VALUE, mFishingPBlueValue);

	DDX_Control(pDX, IDC_LBOAT_RED_SLIDER, mLBoatRedS);
	DDX_Control(pDX, IDC_LBOAT_GREEN_SLIDER, mLBoatGreenS);
	DDX_Control(pDX, IDC_LBOAT_BLUE_SLIDER, mLBoatBlueS);

	DDX_Control(pDX, IDC_LBOAT_RED_VALUE, mLBoatRedValue);
	DDX_Control(pDX, IDC_LBOAT_GREEN_VALUE, mLBoatGreenValue);
	DDX_Control(pDX, IDC_LBOAT_BLUE_VALUE, mLBoatBlueValue);
	DDX_Control(pDX, IDC_RBOAT_RED_SLIDER, mRBoatRedS);
	DDX_Control(pDX, IDC_RBOAT_GREEN_SLIDER, mRBoatGreenS);
	DDX_Control(pDX, IDC_RBOAT_BLUE_SLIDER, mRBoatBlueS);
	DDX_Control(pDX, IDC_RBOAT_RED_VALUE, mRBoatRedValue);
	DDX_Control(pDX, IDC_RBOAT_GREEN_VALUE2, mRBoatGreenValue);
	DDX_Control(pDX, IDC_RBOAT_BLUE_VALUE2, mRBoatBlueValue);
	DDX_Control(pDX, IDC_FISHING_COMBO, mFishingCombo);

	DDX_Control(pDX, IDC_FISHING_VSCROLL, mFishingVSlider);
	DDX_Control(pDX, IDC_FISHING_HSCROOL, mFishingHSlider);
	DDX_Control(pDX, IDC_FISHING_SCALE_SLIDER, mFishingScaleS);
	DDX_Control(pDX, IDC_FISHING_SCALE_VALUE, mFishingScaleEdit);
	DDX_Control(pDX, IDC_FISHING_V_VALUE, mFishingVEdit);
	DDX_Control(pDX, IDC_FISHING_H_VALUE, mFishingHEdit);
}


BEGIN_MESSAGE_MAP(CFishingDlg, CDialogEx)
	ON_WM_HSCROLL()

	ON_EN_UPDATE(IDC_BOAT_RED_VALUE, &CFishingDlg::OnEnUpdateBoatRedValue)
	ON_EN_UPDATE(IDC_BOAT_GREEN_VALUE, &CFishingDlg::OnEnUpdateBoatGreenValue)
	ON_EN_UPDATE(IDC_BOAT_BLUE_VALUE, &CFishingDlg::OnEnUpdateBoatBlueValue)

	ON_EN_UPDATE(IDC_LBOAT_RED_VALUE, &CFishingDlg::OnEnUpdateLBoatRedValue)
	ON_EN_UPDATE(IDC_LBOAT_GREEN_VALUE, &CFishingDlg::OnEnUpdateLBoatGreenValue)
	ON_EN_UPDATE(IDC_LBOAT_BLUE_VALUE, &CFishingDlg::OnEnUpdateLBoatBlueValue)

	ON_EN_UPDATE(IDC_RBOAT_RED_VALUE, &CFishingDlg::OnEnUpdateRBoatRedValue)
	ON_EN_UPDATE(IDC_RBOAT_GREEN_VALUE2, &CFishingDlg::OnEnUpdateRBoatGreenValue)
	ON_EN_UPDATE(IDC_RBOAT_BLUE_VALUE2, &CFishingDlg::OnEnUpdateRBoatBlueValue)

	ON_EN_UPDATE(IDC_FISHING_RED_VALUE, &CFishingDlg::OnEnUpdateFishingRedValue)
	ON_EN_UPDATE(IDC_FISHING_GREEN_VALUE, &CFishingDlg::OnEnUpdateFishingGreenValue)
	ON_EN_UPDATE(IDC_FISHING_BLUE_VALUE, &CFishingDlg::OnEnUpdateFishingBlueValue)

	ON_EN_UPDATE(IDC_FISHIHGPOLE_RED_VALUE, &CFishingDlg::OnEnUpdateFishingPRedValue)
	ON_EN_UPDATE(IDC_FISHIHGPOLE_GREEN_VALUE, &CFishingDlg::OnEnUpdateFishingPGreenValue)
	ON_EN_UPDATE(IDC_FISHIHGPOLE_BLUE_VALUE, &CFishingDlg::OnEnUpdateFishingPBlueValue)

	ON_EN_UPDATE(IDC_FISHING_V_VALUE, &CFishingDlg::OnEnUpdateFishingVEdit)
	ON_EN_UPDATE(IDC_FISHING_H_VALUE, &CFishingDlg::OnEnUpdateFishingHEdit)
	ON_EN_UPDATE(IDC_FISHING_SCALE_VALUE, &CFishingDlg::OnEnUpdateFishingScaleEdit)


	ON_CBN_SELCHANGE(IDC_FISHING_COMBO, &CFishingDlg::OnCbnSelchangeOceanCombo)
END_MESSAGE_MAP()


// CFishDlg �޽��� ó�����Դϴ�.

BOOL CFishingDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.

	mBoatRedS.ShowWindow(SW_HIDE);
	mBoatGreenS.ShowWindow(SW_HIDE);
	mBoatBlueS.ShowWindow(SW_HIDE);

	mBoatRedValue.ShowWindow(SW_HIDE);
	mBoatGreenValue.ShowWindow(SW_HIDE);
	mBoatBlueValue.ShowWindow(SW_HIDE);

	mFishingRedS.ShowWindow(SW_HIDE);
	mFishingGreenS.ShowWindow(SW_HIDE);
	mFishingBlueS.ShowWindow(SW_HIDE);

	mFishingRedValue.ShowWindow(SW_HIDE);
	mFishingGreenValue.ShowWindow(SW_HIDE);
	mFishingBlueValue.ShowWindow(SW_HIDE);

	mFishingPRedS.ShowWindow(SW_SHOW);
	mFishingPGreenS.ShowWindow(SW_SHOW);
	mFishingPBlueS.ShowWindow(SW_SHOW);

	mFishingPRedValue.ShowWindow(SW_SHOW);
	mFishingPGreenValue.ShowWindow(SW_SHOW);
	mFishingPBlueValue.ShowWindow(SW_SHOW);

	mLBoatRedS.ShowWindow(SW_HIDE);
	mLBoatGreenS.ShowWindow(SW_HIDE);
	mLBoatBlueS.ShowWindow(SW_HIDE);

	mLBoatGreenValue.ShowWindow(SW_HIDE);
	mLBoatBlueValue.ShowWindow(SW_HIDE);
	mLBoatRedValue.ShowWindow(SW_HIDE);

	mRBoatRedS.ShowWindow(SW_HIDE);
	mRBoatGreenS.ShowWindow(SW_HIDE);
	mRBoatBlueS.ShowWindow(SW_HIDE);

	mRBoatRedValue.ShowWindow(SW_HIDE);
	mRBoatGreenValue.ShowWindow(SW_HIDE);
	mRBoatBlueValue.ShowWindow(SW_HIDE);

	mFishingCombo.AddString("��Ʈ");
	mFishingCombo.AddString("���ʵ�");
	mFishingCombo.AddString("�����ʵ�");
	mFishingCombo.AddString("���ô�");
	mFishingCombo.AddString("������");
	mFishingCombo.SetCurSel(0); //�޺��ڽ� �⺻ ���� 


	//red �����̴�
	mBoatRedS.SetPos(0);//�����̴� ó�� ��ġ
	mBoatRedS.SetRange(0, 255); //�����̴� ���� 0 ~ 100���� ��.
	mBoatRedS.SetPageSize(10); //�����̴��� Ŭ������ �� �����̴� ����. 
	mBoatRedValue.SetWindowTextA("0");//red edit�ڽ� �ʱⰪ

	//green �����̴�
	mBoatGreenS.SetPos(255);//�����̴� ó�� ��ġ
	mBoatGreenS.SetRange(0, 255); //�����̴� ���� 0 ~ 100���� ��.
	mBoatGreenS.SetPageSize(10);  //�����̴��� Ŭ������ �� �����̴� ����
	mBoatGreenValue.SetWindowTextA("0");//green edit�ڽ� �ʱⰪ

	//blue �����̴�
	mBoatBlueS.SetPos(255);//�����̴� ó�� ��ġ
	mBoatBlueS.SetRange(0, 255); //�����̴� ���� 0 ~ 100���� ��.
	mBoatBlueS.SetPageSize(10);  //�����̴��� Ŭ������ �� �����̴� ����
	mBoatBlueValue.SetWindowTextA("255");//blue edit�ڽ� �ʱⰪ

	//���� ��

	mLBoatRedS.SetPos(0);//�����̴� ó�� ��ġ
	mLBoatRedS.SetRange(0, 255); //�����̴� ���� 0 ~ 100���� ��.
	mLBoatRedS.SetPageSize(10); //�����̴��� Ŭ������ �� �����̴� ����. 
	mLBoatRedValue.SetWindowTextA("0");//red edit�ڽ� �ʱⰪ

	//green �����̴�
	mLBoatGreenS.SetPos(127);//�����̴� ó�� ��ġ
	mLBoatGreenS.SetRange(0, 255); //�����̴� ���� 0 ~ 100���� ��.
	mLBoatGreenS.SetPageSize(10);  //�����̴��� Ŭ������ �� �����̴� ����
	mLBoatGreenValue.SetWindowTextA("127");//green edit�ڽ� �ʱⰪ

	//blue �����̴�
	mLBoatBlueS.SetPos(255);//�����̴� ó�� ��ġ
	mLBoatBlueS.SetRange(0, 255); //�����̴� ���� 0 ~ 100���� ��.
	mLBoatBlueS.SetPageSize(10);  //�����̴��� Ŭ������ �� �����̴� ����
	mLBoatBlueValue.SetWindowTextA("255");//blue edit�ڽ� �ʱⰪ

	//������ ��
	mRBoatRedS.SetPos(127);//�����̴� ó�� ��ġ
	mRBoatRedS.SetRange(0, 255); //�����̴� ���� 0 ~ 100���� ��.
	mRBoatRedS.SetPageSize(10); //�����̴��� Ŭ������ �� �����̴� ����. 
	mRBoatRedValue.SetWindowTextA("127");//red edit�ڽ� �ʱⰪ

	//green �����̴�
	mRBoatGreenS.SetPos(255);//�����̴� ó�� ��ġ
	mRBoatGreenS.SetRange(0, 255); //�����̴� ���� 0 ~ 100���� ��.
	mRBoatGreenS.SetPageSize(10);  //�����̴��� Ŭ������ �� �����̴� ����
	mRBoatGreenValue.SetWindowTextA("255");//green edit�ڽ� �ʱⰪ

	//blue �����̴�
	mRBoatBlueS.SetPos(255);//�����̴� ó�� ��ġ
	mRBoatBlueS.SetRange(0, 255); //�����̴� ���� 0 ~ 100���� ��.
	mRBoatBlueS.SetPageSize(10);  //�����̴��� Ŭ������ �� �����̴� ����
	mRBoatBlueValue.SetWindowTextA("255");//blue edit�ڽ� �ʱⰪ

	//���ô�
	mFishingPRedS.SetPos(0);//�����̴� ó�� ��ġ
	mFishingPRedS.SetRange(0, 255); //�����̴� ���� 0 ~ 100���� ��.
	mFishingPRedS.SetPageSize(10); //�����̴��� Ŭ������ �� �����̴� ����. 
	mFishingPRedValue.SetWindowTextA("0");//red edit�ڽ� �ʱⰪ

	//green �����̴�
	mFishingPGreenS.SetPos(255);//�����̴� ó�� ��ġ
	mFishingPGreenS.SetRange(0, 255); //�����̴� ���� 0 ~ 100���� ��.
	mFishingPGreenS.SetPageSize(10);  //�����̴��� Ŭ������ �� �����̴� ����
	mFishingPGreenValue.SetWindowTextA("255");//green edit�ڽ� �ʱⰪ

	//blue �����̴�
	mFishingPBlueS.SetPos(0);//�����̴� ó�� ��ġ
	mFishingPBlueS.SetRange(0, 255); //�����̴� ���� 0 ~ 100���� ��.
	mFishingPBlueS.SetPageSize(10);  //�����̴��� Ŭ������ �� �����̴� ����
	mFishingPBlueValue.SetWindowTextA("0");//blue edit�ڽ� �ʱⰪ

	//������
	mFishingRedS.SetPos(255);//�����̴� ó�� ��ġ
	mFishingRedS.SetRange(0, 255); //�����̴� ���� 0 ~ 100���� ��.
	mFishingRedS.SetPageSize(10); //�����̴��� Ŭ������ �� �����̴� ����. 
	mFishingRedValue.SetWindowTextA("255");//red edit�ڽ� �ʱⰪ

	//green �����̴�
	mFishingGreenS.SetPos(255);//�����̴� ó�� ��ġ
	mFishingGreenS.SetRange(0, 255); //�����̴� ���� 0 ~ 100���� ��.
	mFishingGreenS.SetPageSize(10);  //�����̴��� Ŭ������ �� �����̴� ����
	mFishingGreenValue.SetWindowTextA("255");//green edit�ڽ� �ʱⰪ

	//blue �����̴�
	mFishingBlueS.SetPos(255);//�����̴� ó�� ��ġ
	mFishingBlueS.SetRange(0, 255); //�����̴� ���� 0 ~ 100���� ��.
	mFishingBlueS.SetPageSize(10);  //�����̴��� Ŭ������ �� �����̴� ����
	mFishingBlueValue.SetWindowTextA("255");//blue edit�ڽ� �ʱⰪ


	//���������̴�
	mFishingVSlider.SetPos(50);//�����̴� ó�� ��ġ
	mFishingVSlider.SetRange(0, 100); //�����̴� ���� 0 ~ 100���� ��.
	mFishingVSlider.SetPageSize(1);  //�����̴��� Ŭ������ �� �����̴� ����
	mFishingVEdit.SetWindowTextA("0");//v edit�ڽ� �ʱⰪ

	//���򽽶��̴�
	mFishingHSlider.SetPos(50);//�����̴� ó�� ��ġ
	mFishingHSlider.SetRange(0, 100); //�����̴� ���� 0 ~ 100���� ��.
	mFishingHSlider.SetPageSize(1);  //�����̴��� Ŭ������ �� �����̴� ����
	mFishingHEdit.SetWindowTextA("0");//h edit�ڽ� �ʱⰪ

	//ũ��
	mFishingScaleS.SetPos(50);//�����̴� ó�� ��ġ
	mFishingScaleS.SetRange(0, 100); //�����̴� ���� 0 ~ 100���� ��.
	mFishingScaleS.SetPageSize(1);  //�����̴��� Ŭ������ �� �����̴� ����
	mFishingScaleEdit.SetWindowTextA("0");//h edit�ڽ� �ʱⰪ  

	return TRUE;  // return TRUE unless you set the focus to a control
	// ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
}


//�����̴� �������� ��
void CFishingDlg::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	CMainFrame* pFrame = (CMainFrame*)AfxGetMainWnd();				//Viewȣ��
	CMakoryView* pView = (CMakoryView*)pFrame->GetActiveView();		//Viewȣ��

	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	if(pScrollBar)
	{
		// � �����̴����� �˻�
		//red slider�� �������� ���
		if(pScrollBar == (CScrollBar*)&mBoatRedS)//Fish red slider�ΰ��
		{

			// �����̴��� ��ġ�� �˻��Ѵ�.
			int npos = mBoatRedS.GetPos(); //�����̴� ��ġ ����
			CString str;
			str.Format(_T("%d"), npos); //����ȯ
			mBoatRedValue.SetWindowTextA(str); //edit �ڽ��� �����̴� �� ��

			fpos = (double)npos * 0.00392156; //�����̴��� �Ҽ����� ����� �ȵ�

			pView->Ocean.boatred=fpos;//ǳ�� ���������� �ٲ���
			pView->Invalidate(FALSE);
		}

		//green�����̴� �������� ���
		else if(pScrollBar == (CScrollBar*)&mBoatGreenS)//Fish red slider�ΰ��
		{

			// �����̴��� ��ġ�� �˻��Ѵ�.
			int npos = mBoatGreenS.GetPos(); //�����̴� ��ġ ����
			CString str;
			str.Format(_T("%d"), npos); //����ȯ
			mBoatGreenValue.SetWindowTextA(str); //edit �ڽ��� �����̴� �� ��

			fpos = (double)npos * 0.00392156; //�����̴��� �Ҽ����� ����� �ȵ�

			pView->Ocean.boatgreen=fpos;//ǳ�� ���������� �ٲ���
			pView->Invalidate(FALSE);
		}


		//blue �����̴� �������� ���
		else if(pScrollBar == (CScrollBar*)&mBoatBlueS)//Fish green slider�ΰ��
		{

			// �����̴��� ��ġ�� �˻��Ѵ�.
			int npos = mBoatBlueS.GetPos(); //�����̴� ��ġ ����
			CString str;
			str.Format(_T("%d"), npos); //����ȯ
			mBoatBlueValue.SetWindowTextA(str);// edit �ڽ��� �����̴� �� ��

			fpos = (double)npos * 0.00392156; //�����̴��� �Ҽ����� ����� �ȵ�

			pView->Ocean.boatblue=fpos; //ǳ�� ������� �ٲ���
			pView->Invalidate(FALSE);
		}

		//���� ��
		if(pScrollBar == (CScrollBar*)&mLBoatRedS)//Fish red slider�ΰ��
		{

			// �����̴��� ��ġ�� �˻��Ѵ�.
			int npos = mLBoatRedS.GetPos(); //�����̴� ��ġ ����
			CString str;
			str.Format(_T("%d"), npos); //����ȯ
			mLBoatRedValue.SetWindowTextA(str); //edit �ڽ��� �����̴� �� ��

			fpos = (double)npos * 0.00392156; //�����̴��� �Ҽ����� ����� �ȵ�

			pView->Ocean.lboatred=fpos;//ǳ�� ���������� �ٲ���
			pView->Invalidate(FALSE);
		}

		//green�����̴� �������� ���
		else if(pScrollBar == (CScrollBar*)&mLBoatGreenS)//Fish red slider�ΰ��
		{

			// �����̴��� ��ġ�� �˻��Ѵ�.
			int npos = mLBoatGreenS.GetPos(); //�����̴� ��ġ ����
			CString str;
			str.Format(_T("%d"), npos); //����ȯ
			mLBoatGreenValue.SetWindowTextA(str); //edit �ڽ��� �����̴� �� ��

			fpos = (double)npos * 0.00392156; //�����̴��� �Ҽ����� ����� �ȵ�

			pView->Ocean.lboatgreen=fpos;//ǳ�� ���������� �ٲ���
			pView->Invalidate(FALSE);
		}


		//blue �����̴� �������� ���
		else if(pScrollBar == (CScrollBar*)&mLBoatBlueS)//Fish green slider�ΰ��
		{

			// �����̴��� ��ġ�� �˻��Ѵ�.
			int npos = mLBoatBlueS.GetPos(); //�����̴� ��ġ ����
			CString str;
			str.Format(_T("%d"), npos); //����ȯ
			mLBoatBlueValue.SetWindowTextA(str);// edit �ڽ��� �����̴� �� ��

			fpos = (double)npos * 0.00392156; //�����̴��� �Ҽ����� ����� �ȵ�

			pView->Ocean.lboatblue=fpos; //ǳ�� ������� �ٲ���
			pView->Invalidate(FALSE);
		}

		//���� ��
		if(pScrollBar == (CScrollBar*)&mRBoatRedS)//Fish red slider�ΰ��
		{

			// �����̴��� ��ġ�� �˻��Ѵ�.
			int npos = mRBoatRedS.GetPos(); //�����̴� ��ġ ����
			CString str;
			str.Format(_T("%d"), npos); //����ȯ
			mRBoatRedValue.SetWindowTextA(str); //edit �ڽ��� �����̴� �� ��

			fpos = (double)npos * 0.00392156; //�����̴��� �Ҽ����� ����� �ȵ�

			pView->Ocean.rboatred=fpos;//ǳ�� ���������� �ٲ���
			pView->Invalidate(FALSE);
		}

		//green�����̴� �������� ���
		else if(pScrollBar == (CScrollBar*)&mRBoatGreenS)//Fish red slider�ΰ��
		{

			// �����̴��� ��ġ�� �˻��Ѵ�.
			int npos = mRBoatGreenS.GetPos(); //�����̴� ��ġ ����
			CString str;
			str.Format(_T("%d"), npos); //����ȯ
			mRBoatGreenValue.SetWindowTextA(str); //edit �ڽ��� �����̴� �� ��

			fpos = (double)npos * 0.00392156; //�����̴��� �Ҽ����� ����� �ȵ�

			pView->Ocean.rboatgreen=fpos;//ǳ�� ���������� �ٲ���
			pView->Invalidate(FALSE);
		}


		//blue �����̴� �������� ���
		else if(pScrollBar == (CScrollBar*)&mRBoatBlueS)//Fish green slider�ΰ��
		{

			// �����̴��� ��ġ�� �˻��Ѵ�.
			int npos = mRBoatBlueS.GetPos(); //�����̴� ��ġ ����
			CString str;
			str.Format(_T("%d"), npos); //����ȯ
			mRBoatBlueValue.SetWindowTextA(str);// edit �ڽ��� �����̴� �� ��

			fpos = (double)npos * 0.00392156; //�����̴��� �Ҽ����� ����� �ȵ�

			pView->Ocean.rboatblue=fpos; //ǳ�� ������� �ٲ���
			pView->Invalidate(FALSE);
		}

		//���ô�
		//red slider�� �������� ���
		if(pScrollBar == (CScrollBar*)&mFishingPRedS)//Fish red slider�ΰ��
		{

			// �����̴��� ��ġ�� �˻��Ѵ�.
			int npos = mFishingPRedS.GetPos(); //�����̴� ��ġ ����
			CString str;
			str.Format(_T("%d"), npos); //����ȯ
			mFishingPRedValue.SetWindowTextA(str); //edit �ڽ��� �����̴� �� ��

			fpos = (double)npos * 0.00392156; //�����̴��� �Ҽ����� ����� �ȵ�

			pView->Ocean.fishingpred=fpos;//ǳ�� ���������� �ٲ���
			pView->Invalidate(FALSE);
		}

		//green�����̴� �������� ���
		else if(pScrollBar == (CScrollBar*)&mFishingPGreenS)//Fish red slider�ΰ��
		{

			// �����̴��� ��ġ�� �˻��Ѵ�.
			int npos = mFishingPGreenS.GetPos(); //�����̴� ��ġ ����
			CString str;
			str.Format(_T("%d"), npos); //����ȯ
			mFishingPGreenValue.SetWindowTextA(str); //edit �ڽ��� �����̴� �� ��

			fpos = (double)npos * 0.00392156; //�����̴��� �Ҽ����� ����� �ȵ�

			pView->Ocean.fishingpgreen=fpos;//ǳ�� ���������� �ٲ���
			pView->Invalidate(FALSE);
		}


		//blue �����̴� �������� ���
		else if(pScrollBar == (CScrollBar*)&mFishingPBlueS)//Fish green slider�ΰ��
		{

			// �����̴��� ��ġ�� �˻��Ѵ�.
			int npos = mFishingPBlueS.GetPos(); //�����̴� ��ġ ����
			CString str;
			str.Format(_T("%d"), npos); //����ȯ
			mFishingPBlueValue.SetWindowTextA(str);// edit �ڽ��� �����̴� �� ��

			fpos = (double)npos * 0.00392156; //�����̴��� �Ҽ����� ����� �ȵ�

			pView->Ocean.fishingpblue=fpos; //ǳ�� ������� �ٲ���
			pView->Invalidate(FALSE);
		}

		//������

		//red slider�� �������� ���
		if(pScrollBar == (CScrollBar*)&mFishingRedS)//Fish red slider�ΰ��
		{

			// �����̴��� ��ġ�� �˻��Ѵ�.
			int npos = mFishingRedS.GetPos(); //�����̴� ��ġ ����
			CString str;
			str.Format(_T("%d"), npos); //����ȯ
			mFishingRedValue.SetWindowTextA(str); //edit �ڽ��� �����̴� �� ��

			fpos = (double)npos * 0.00392156; //�����̴��� �Ҽ����� ����� �ȵ�

			pView->Ocean.fishingred=fpos;//ǳ�� ���������� �ٲ���
			pView->Invalidate(FALSE);
		}

		//green�����̴� �������� ���
		else if(pScrollBar == (CScrollBar*)&mFishingGreenS)//Fish red slider�ΰ��
		{

			// �����̴��� ��ġ�� �˻��Ѵ�.
			int npos = mFishingGreenS.GetPos(); //�����̴� ��ġ ����
			CString str;
			str.Format(_T("%d"), npos); //����ȯ
			mFishingGreenValue.SetWindowTextA(str); //edit �ڽ��� �����̴� �� ��

			fpos = (double)npos * 0.00392156; //�����̴��� �Ҽ����� ����� �ȵ�

			pView->Ocean.fishinggreen=fpos;//ǳ�� ���������� �ٲ���
			pView->Invalidate(FALSE);
		}


		//blue �����̴� �������� ���
		else if(pScrollBar == (CScrollBar*)&mFishingBlueS)//Fish green slider�ΰ��
		{

			// �����̴��� ��ġ�� �˻��Ѵ�.
			int npos = mFishingBlueS.GetPos(); //�����̴� ��ġ ����
			CString str;
			str.Format(_T("%d"), npos); //����ȯ
			mFishingBlueValue.SetWindowTextA(str);// edit �ڽ��� �����̴� �� ��

			fpos = (double)npos * 0.00392156; //�����̴��� �Ҽ����� ����� �ȵ�

			pView->Ocean.fishingblue=fpos; //ǳ�� ������� �ٲ���
			pView->Invalidate(FALSE);
		}


		//ũ�� �����̴� �������� ���
		else if(pScrollBar == (CScrollBar*)&mFishingScaleS)//���� �����̴��ΰ��
		{
			// �����̴��� ��ġ�� �˻��Ѵ�.
			int npos = mFishingScaleS.GetPos(); //�����̴� ��ġ ����
			CString str;
			str.Format(_T("%d"), npos-50); //����ȯ
			mFishingScaleEdit.SetWindowTextA(str); //edit �ڽ��� �����̴� �� ��

			if(npos <= 50){ //�����̴��� 50�����϶�
				fpos = 2*(-0.5+((double)npos * 0.01)); //�������� �̵� 
			} 
			else if(npos >= 50){  //�����̴��� 50�̻��϶�
				fpos = 5*(((double)npos * 0.01)-0.5); //���������� �̵�
			}

			pView->Ocean.FishingVessel=2.5+fpos; //filmscale���� �ٲ���

			pView->Ocean.fishingscale=fpos;
			pView->Invalidate(FALSE);
		}
		//���� �����̴� �������� ���
		else if(pScrollBar == (CScrollBar*)&mFishingVSlider)//���� �����̴��ΰ��
		{

			// �����̴��� ��ġ�� �˻��Ѵ�.
			int npos = mFishingVSlider.GetPos(); //�����̴� ��ġ ����
			CString str;
			str.Format(_T("%d"), npos-50); //����ȯ
			mFishingVEdit.SetWindowTextA(str); //edit �ڽ��� �����̴� �� ��


			if(npos <= 50){ //�����̴��� 50�����϶�
				fpos = -0.5+((double)npos * 0.01); //�������� �̵� 
			} 
			else if(npos >= 50){  //�����̴��� 50�̻��϶�
				fpos = ((double)npos * 0.01)-0.5; //���������� �̵�
			}

			pView->Ocean.fishingy=fpos; //Fishy���� �ٲ���

			pView->Invalidate(FALSE);
		}
		//���� �����̴� �������� ���
		else if(pScrollBar == (CScrollBar*)&mFishingHSlider)//���� �����̴��ΰ��
		{

			// �����̴��� ��ġ�� �˻��Ѵ�.
			int npos = mFishingHSlider.GetPos(); //�����̴� ��ġ ����

			CString str;
			str.Format(_T("%d"), npos-50); //����ȯ
			mFishingHEdit.SetWindowTextA(str); //edit �ڽ��� �����̴� �� ��

			if(npos <= 50){ //�����̴��� 50�����϶�
				fpos = 3*(-0.05+((double)npos * 0.001)); //�������� �̵� 
			} 
			else if(npos >= 50){  //�����̴��� 50�̻��϶�
				fpos = 3*(((double)npos * 0.01)-0.5); //���������� �̵�
			}

			pView->Ocean.fishingx=fpos; //Fishx���� �ٲ���
			pView->Invalidate(FALSE);
		}


	}

	else
	{
		// CScrollView�� ��ӹ��� ���� ��� �������� ��ũ�ѷ� ���۽� pScrollBar�� NULL�ȴ�.
	}
	CDialogEx::OnHScroll(nSBCode, nPos, pScrollBar);
}

//��Ʈ
//RED edit
void CFishingDlg::OnEnUpdateBoatRedValue()
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

		mBoatRedValue.GetWindowTextA(String);
		ipos = _ttoi(String);
		mBoatRedS.SetPos(ipos);
		dpos = (double)ipos * 0.00392156; //�����̴��� �Ҽ����� ����� �ȵ�

		pView->Ocean.boatred=dpos;//ǳ�� ���������� �ٲ���
		pView->Invalidate(FALSE);
	}
}

//green edit
void CFishingDlg::OnEnUpdateBoatGreenValue()
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

		mBoatGreenValue.GetWindowTextA(String);
		ipos = _ttoi(String);
		mBoatGreenS.SetPos(ipos);
		dpos = (double)ipos * 0.00392156; //�����̴��� �Ҽ����� ����� �ȵ�
		pView->Ocean.boatgreen=dpos;//ǳ�� ���������� �ٲ���

		pView->Invalidate(FALSE);
	}
}

//blue edit
void CFishingDlg::OnEnUpdateBoatBlueValue()
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

		mBoatBlueValue.GetWindowTextA(String);
		ipos = _ttoi(String);
		mBoatBlueS.SetPos(ipos);
		dpos = (double)ipos * 0.00392156; //�����̴��� �Ҽ����� ����� �ȵ�
		pView->Ocean.boatblue=dpos;//ǳ�� ���������� �ٲ���

		pView->Invalidate(FALSE);
	}
}
//���� ��
//RED edit
void CFishingDlg::OnEnUpdateLBoatRedValue()
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

		mLBoatRedValue.GetWindowTextA(String);
		ipos = _ttoi(String);
		mLBoatRedS.SetPos(ipos);
		dpos = (double)ipos * 0.00392156; //�����̴��� �Ҽ����� ����� �ȵ�

		pView->Ocean.lboatred=dpos;//ǳ�� ���������� �ٲ���
		pView->Invalidate(FALSE);
	}
}

//green edit
void CFishingDlg::OnEnUpdateLBoatGreenValue()
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

		mLBoatGreenValue.GetWindowTextA(String);
		ipos = _ttoi(String);
		mLBoatGreenS.SetPos(ipos);
		dpos = (double)ipos * 0.00392156; //�����̴��� �Ҽ����� ����� �ȵ�
		pView->Ocean.lboatgreen=dpos;//ǳ�� ���������� �ٲ���

		pView->Invalidate(FALSE);
	}
}

//blue edit
void CFishingDlg::OnEnUpdateLBoatBlueValue()
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

		mLBoatBlueValue.GetWindowTextA(String);
		ipos = _ttoi(String);
		mLBoatBlueS.SetPos(ipos);
		dpos = (double)ipos * 0.00392156; //�����̴��� �Ҽ����� ����� �ȵ�

		pView->Ocean.lboatblue=dpos;//ǳ�� ���������� �ٲ���
		pView->Invalidate(FALSE);
	}
}

//������ ��
//RED edit
void CFishingDlg::OnEnUpdateRBoatRedValue()
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

		mRBoatRedValue.GetWindowTextA(String);
		ipos = _ttoi(String);
		mRBoatRedS.SetPos(ipos);
		dpos = (double)ipos * 0.00392156; //�����̴��� �Ҽ����� ����� �ȵ�

		pView->Ocean.rboatred=dpos;//ǳ�� ���������� �ٲ���
		pView->Invalidate(FALSE);
	}
}

//green edit
void CFishingDlg::OnEnUpdateRBoatGreenValue()
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

		mRBoatGreenValue.GetWindowTextA(String);
		ipos = _ttoi(String);
		mRBoatGreenS.SetPos(ipos);
		dpos = (double)ipos * 0.00392156; //�����̴��� �Ҽ����� ����� �ȵ�
		pView->Ocean.rboatgreen=dpos;//ǳ�� ���������� �ٲ���

		pView->Invalidate(FALSE);
	}
}

//blue edit
void CFishingDlg::OnEnUpdateRBoatBlueValue()
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

		mRBoatBlueValue.GetWindowTextA(String);
		ipos = _ttoi(String);
		mRBoatBlueS.SetPos(ipos);
		dpos = (double)ipos * 0.00392156; //�����̴��� �Ҽ����� ����� �ȵ�

		pView->Ocean.rboatblue=dpos;//ǳ�� ���������� �ٲ���
		pView->Invalidate(FALSE);
	}
}

//������
void CFishingDlg::OnEnUpdateFishingRedValue()
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

		mFishingRedValue.GetWindowTextA(String);
		ipos = _ttoi(String);
		mFishingRedS.SetPos(ipos);
		dpos = (double)ipos * 0.00392156; //�����̴��� �Ҽ����� ����� �ȵ�

		pView->Ocean.fishingred=dpos;//ǳ�� ���������� �ٲ���
		pView->Invalidate(FALSE);
	}
}

//green edit
void CFishingDlg::OnEnUpdateFishingGreenValue()
{
	CMainFrame* pFrame = (CMainFrame*)AfxGetMainWnd();            //Viewȣ��
	CMakoryView* pView = (CMakoryView*)pFrame->GetActiveView();      //Viewȣ��

	if(UpdateData(TRUE)){

		int ipos;
		double dpos;
		CString String;

		mFishingGreenValue.GetWindowTextA(String);
		ipos = _ttoi(String);
		mFishingGreenS.SetPos(ipos);
		dpos = (double)ipos * 0.00392156; //�����̴��� �Ҽ����� ����� �ȵ�
		pView->Ocean.fishinggreen=dpos;//ǳ�� ���������� �ٲ���

		pView->Invalidate(FALSE);
	}
}

//blue edit
void CFishingDlg::OnEnUpdateFishingBlueValue()
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

		mFishingBlueValue.GetWindowTextA(String);
		ipos = _ttoi(String);
		mFishingBlueS.SetPos(ipos);
		dpos = (double)ipos * 0.00392156; //�����̴��� �Ҽ����� ����� �ȵ�

		pView->Ocean.fishingblue=dpos;//ǳ�� ���������� �ٲ���
		pView->Invalidate(FALSE);
	}
}

//���ô�
void CFishingDlg::OnEnUpdateFishingPRedValue()
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

		mFishingPRedValue.GetWindowTextA(String);
		ipos = _ttoi(String);
		mFishingPRedS.SetPos(ipos);
		dpos = (double)ipos * 0.00392156; //�����̴��� �Ҽ����� ����� �ȵ�

		pView->Ocean.fishingpred=dpos;//ǳ�� ���������� �ٲ���
		pView->Invalidate(FALSE);
	}
}

//green edit
void CFishingDlg::OnEnUpdateFishingPGreenValue()
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

		mFishingPGreenValue.GetWindowTextA(String);
		ipos = _ttoi(String);
		mFishingPGreenS.SetPos(ipos);
		dpos = (double)ipos * 0.00392156; //�����̴��� �Ҽ����� ����� �ȵ�
		pView->Ocean.fishingpgreen=dpos;//ǳ�� ���������� �ٲ���

		pView->Invalidate(FALSE);
	}
}

//blue edit
void CFishingDlg::OnEnUpdateFishingPBlueValue()
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

		mFishingPBlueValue.GetWindowTextA(String);
		ipos = _ttoi(String);
		mFishingPBlueS.SetPos(ipos);
		dpos = (double)ipos * 0.00392156; //�����̴��� �Ҽ����� ����� �ȵ�

		pView->Ocean.fishingpblue=dpos;//ǳ�� ���������� �ٲ���
		pView->Invalidate(FALSE);
	}
}


//���� edit
void CFishingDlg::OnEnUpdateFishingHEdit()
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

		mFishingHEdit.GetWindowTextA(String);

		ipos = _ttoi(String)+50;
		mFishingHSlider.SetPos(ipos);

		if(ipos <= 50){ //�����̴��� 50�����϶�

			dpos = 3*(-0.5+((double)ipos * 0.01)); //�������� �̵� 

		} 
		else if(ipos >= 50){  //�����̴��� 50�̻��϶�
			dpos = 3*(((double)ipos * 0.01)-0.5); //���������� �̵�
		}
		pView->Ocean.fishingx=dpos; //Fishx���� �ٲ���

		pView->Invalidate(FALSE);
	}

}
//���� Edit
void CFishingDlg::OnEnUpdateFishingVEdit()
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

		mFishingVEdit.GetWindowTextA(String);

		ipos =_ttoi(String)+50;

		mFishingVSlider.SetPos(ipos);

		if(ipos <= 50){ //�����̴��� 50�����϶�

			dpos = -0.5+((double)ipos * 0.01); //�������� �̵� 

		} 
		else if(ipos >= 50){  //�����̴��� 50�̻��϶�
			dpos = ((double)ipos * 0.01)-0.5; //���������� �̵�
		}

		pView->Ocean.fishingy=dpos; //Fishy���� �ٲ���
		pView->Invalidate(FALSE);
	}
}

//ũ�� edit
void CFishingDlg::OnEnUpdateFishingScaleEdit()
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

		mFishingScaleEdit.GetWindowTextA(String);

		ipos = _ttoi(String)+50;
		mFishingScaleS.SetPos(ipos);

		if (ipos<0){
			ipos = 0;
			dpos = 2*(-0.5+((double)ipos * 0.01)); //�������� �̵� 
			pView->Ocean.FishingVessel=2.5+dpos; //filmscale���� �ٲ���
			pView->Ocean.fishingscale=dpos;
			pView->Invalidate(FALSE);
		}
		else if(ipos<100){
			if(ipos <= 50){ //�����̴��� 50�����϶�

				dpos = 2*(-0.5+((double)ipos * 0.01)); //�������� �̵� 

			} 
			else if(ipos >= 50){  //�����̴��� 50�̻��϶�
				dpos = 5*(((double)ipos * 0.01)-0.5); //���������� �̵�
			}


			pView->Ocean.FishingVessel=2.5+dpos; //filmscale���� �ٲ���
			pView->Ocean.fishingscale=dpos;
			pView->Invalidate(FALSE);
		}
		else if(ipos>100){
			ipos = 100;
			dpos = 5*(((double)ipos * 0.01)-0.5); //���������� �̵�
			pView->Ocean.FishingVessel=2.5+dpos; //filmscale���� �ٲ���
			pView->Ocean.fishingscale=dpos;
			pView->Invalidate(FALSE);

		}


	}
}

//�޺� �ڽ� ���ý�
void CFishingDlg::OnCbnSelchangeOceanCombo()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	//����⼱��

	if(mFishingCombo.GetCurSel()==2){//��

		mBoatRedS.ShowWindow(SW_SHOW);
		mBoatGreenS.ShowWindow(SW_SHOW);
		mBoatBlueS.ShowWindow(SW_SHOW);

		mBoatRedValue.ShowWindow(SW_SHOW);
		mBoatGreenValue.ShowWindow(SW_SHOW);
		mBoatBlueValue.ShowWindow(SW_SHOW);

		mLBoatRedS.ShowWindow(SW_HIDE);
		mLBoatGreenS.ShowWindow(SW_HIDE);
		mLBoatBlueS.ShowWindow(SW_HIDE);

		mLBoatRedValue.ShowWindow(SW_HIDE);
		mLBoatGreenValue.ShowWindow(SW_HIDE);
		mLBoatBlueValue.ShowWindow(SW_HIDE);

		mRBoatRedS.ShowWindow(SW_HIDE);
		mRBoatGreenS.ShowWindow(SW_HIDE);
		mRBoatBlueS.ShowWindow(SW_HIDE);

		mRBoatRedValue.ShowWindow(SW_HIDE);
		mRBoatGreenValue.ShowWindow(SW_HIDE);
		mRBoatBlueValue.ShowWindow(SW_HIDE);

		mFishingPRedS.ShowWindow(SW_HIDE);
		mFishingPGreenS.ShowWindow(SW_HIDE);
		mFishingPBlueS.ShowWindow(SW_HIDE);

		mFishingPRedValue.ShowWindow(SW_HIDE);
		mFishingPGreenValue.ShowWindow(SW_HIDE);
		mFishingPBlueValue.ShowWindow(SW_HIDE);

		mFishingRedS.ShowWindow(SW_HIDE);
		mFishingGreenS.ShowWindow(SW_HIDE);
		mFishingBlueS.ShowWindow(SW_HIDE);

		mFishingRedValue.ShowWindow(SW_HIDE);
		mFishingGreenValue.ShowWindow(SW_HIDE);
		mFishingBlueValue.ShowWindow(SW_HIDE);


	}
	else if(mFishingCombo.GetCurSel()==4){ //������ ��
		mLBoatRedS.ShowWindow(SW_SHOW);
		mLBoatGreenS.ShowWindow(SW_SHOW);
		mLBoatBlueS.ShowWindow(SW_SHOW);

		mLBoatRedValue.ShowWindow(SW_SHOW);
		mLBoatGreenValue.ShowWindow(SW_SHOW);
		mLBoatBlueValue.ShowWindow(SW_SHOW);

		mBoatRedS.ShowWindow(SW_HIDE);
		mBoatGreenS.ShowWindow(SW_HIDE);
		mBoatBlueS.ShowWindow(SW_HIDE);

		mBoatRedValue.ShowWindow(SW_HIDE);
		mBoatGreenValue.ShowWindow(SW_HIDE);
		mBoatBlueValue.ShowWindow(SW_HIDE);

		mRBoatRedS.ShowWindow(SW_HIDE);
		mRBoatGreenS.ShowWindow(SW_HIDE);
		mRBoatBlueS.ShowWindow(SW_HIDE);

		mRBoatRedValue.ShowWindow(SW_HIDE);
		mRBoatGreenValue.ShowWindow(SW_HIDE);
		mRBoatBlueValue.ShowWindow(SW_HIDE);

		mFishingPRedS.ShowWindow(SW_HIDE);
		mFishingPGreenS.ShowWindow(SW_HIDE);
		mFishingPBlueS.ShowWindow(SW_HIDE);

		mFishingPRedValue.ShowWindow(SW_HIDE);
		mFishingPGreenValue.ShowWindow(SW_HIDE);
		mFishingPBlueValue.ShowWindow(SW_HIDE);

		mFishingRedS.ShowWindow(SW_HIDE);
		mFishingGreenS.ShowWindow(SW_HIDE);
		mFishingBlueS.ShowWindow(SW_HIDE);

		mFishingRedValue.ShowWindow(SW_HIDE);
		mFishingGreenValue.ShowWindow(SW_HIDE);
		mFishingBlueValue.ShowWindow(SW_HIDE);


	}
	else if(mFishingCombo.GetCurSel()==3){ //���ʵ�
		mRBoatRedS.ShowWindow(SW_SHOW);
		mRBoatGreenS.ShowWindow(SW_SHOW);
		mRBoatBlueS.ShowWindow(SW_SHOW);

		mRBoatRedValue.ShowWindow(SW_SHOW);
		mRBoatGreenValue.ShowWindow(SW_SHOW);
		mRBoatBlueValue.ShowWindow(SW_SHOW);

		mLBoatRedS.ShowWindow(SW_HIDE);
		mLBoatGreenS.ShowWindow(SW_HIDE);
		mLBoatBlueS.ShowWindow(SW_HIDE);

		mLBoatRedValue.ShowWindow(SW_HIDE);
		mLBoatGreenValue.ShowWindow(SW_HIDE);
		mLBoatBlueValue.ShowWindow(SW_HIDE);


		mBoatRedS.ShowWindow(SW_HIDE);
		mBoatGreenS.ShowWindow(SW_HIDE);
		mBoatBlueS.ShowWindow(SW_HIDE);

		mBoatRedValue.ShowWindow(SW_HIDE);
		mBoatGreenValue.ShowWindow(SW_HIDE);
		mBoatBlueValue.ShowWindow(SW_HIDE);

		mFishingPRedS.ShowWindow(SW_HIDE);
		mFishingPGreenS.ShowWindow(SW_HIDE);
		mFishingPBlueS.ShowWindow(SW_HIDE);

		mFishingPRedValue.ShowWindow(SW_HIDE);
		mFishingPGreenValue.ShowWindow(SW_HIDE);
		mFishingPBlueValue.ShowWindow(SW_HIDE);

		mFishingRedS.ShowWindow(SW_HIDE);
		mFishingGreenS.ShowWindow(SW_HIDE);
		mFishingBlueS.ShowWindow(SW_HIDE);

		mFishingRedValue.ShowWindow(SW_HIDE);
		mFishingGreenValue.ShowWindow(SW_HIDE);
		mFishingBlueValue.ShowWindow(SW_HIDE);


	}

	else if(mFishingCombo.GetCurSel()==0){ //���ô�

		mFishingPRedS.ShowWindow(SW_SHOW);
		mFishingPGreenS.ShowWindow(SW_SHOW);
		mFishingPBlueS.ShowWindow(SW_SHOW);

		mFishingPRedValue.ShowWindow(SW_SHOW);
		mFishingPGreenValue.ShowWindow(SW_SHOW);
		mFishingPBlueValue.ShowWindow(SW_SHOW);

		mLBoatRedS.ShowWindow(SW_HIDE);
		mLBoatGreenS.ShowWindow(SW_HIDE);
		mLBoatBlueS.ShowWindow(SW_HIDE);

		mLBoatRedValue.ShowWindow(SW_HIDE);
		mLBoatGreenValue.ShowWindow(SW_HIDE);
		mLBoatBlueValue.ShowWindow(SW_HIDE);


		mBoatRedS.ShowWindow(SW_HIDE);
		mBoatGreenS.ShowWindow(SW_HIDE);
		mBoatBlueS.ShowWindow(SW_HIDE);

		mBoatRedValue.ShowWindow(SW_HIDE);
		mBoatGreenValue.ShowWindow(SW_HIDE);
		mBoatBlueValue.ShowWindow(SW_HIDE);

		mRBoatRedS.ShowWindow(SW_HIDE);
		mRBoatGreenS.ShowWindow(SW_HIDE);
		mRBoatBlueS.ShowWindow(SW_HIDE);

		mRBoatRedValue.ShowWindow(SW_HIDE);
		mRBoatGreenValue.ShowWindow(SW_HIDE);
		mRBoatBlueValue.ShowWindow(SW_HIDE);

		mFishingRedS.ShowWindow(SW_HIDE);
		mFishingGreenS.ShowWindow(SW_HIDE);
		mFishingBlueS.ShowWindow(SW_HIDE);

		mFishingRedValue.ShowWindow(SW_HIDE);
		mFishingGreenValue.ShowWindow(SW_HIDE);
		mFishingBlueValue.ShowWindow(SW_HIDE);

	}

	else if(mFishingCombo.GetCurSel()==1){ //������
		mFishingRedS.ShowWindow(SW_SHOW);
		mFishingGreenS.ShowWindow(SW_SHOW);
		mFishingBlueS.ShowWindow(SW_SHOW);

		mFishingRedValue.ShowWindow(SW_SHOW);
		mFishingGreenValue.ShowWindow(SW_SHOW);
		mFishingBlueValue.ShowWindow(SW_SHOW);

		mFishingPRedS.ShowWindow(SW_HIDE);
		mFishingPGreenS.ShowWindow(SW_HIDE);
		mFishingPBlueS.ShowWindow(SW_HIDE);

		mFishingPRedValue.ShowWindow(SW_HIDE);
		mFishingPGreenValue.ShowWindow(SW_HIDE);
		mFishingPBlueValue.ShowWindow(SW_HIDE);

		mLBoatRedS.ShowWindow(SW_HIDE);
		mLBoatGreenS.ShowWindow(SW_HIDE);
		mLBoatBlueS.ShowWindow(SW_HIDE);

		mLBoatRedValue.ShowWindow(SW_HIDE);
		mLBoatGreenValue.ShowWindow(SW_HIDE);
		mLBoatBlueValue.ShowWindow(SW_HIDE);


		mBoatRedS.ShowWindow(SW_HIDE);
		mBoatGreenS.ShowWindow(SW_HIDE);
		mBoatBlueS.ShowWindow(SW_HIDE);

		mBoatRedValue.ShowWindow(SW_HIDE);
		mBoatGreenValue.ShowWindow(SW_HIDE);
		mBoatBlueValue.ShowWindow(SW_HIDE);

		mRBoatRedS.ShowWindow(SW_HIDE);
		mRBoatGreenS.ShowWindow(SW_HIDE);
		mRBoatBlueS.ShowWindow(SW_HIDE);

		mRBoatRedValue.ShowWindow(SW_HIDE);
		mRBoatGreenValue.ShowWindow(SW_HIDE);
		mRBoatBlueValue.ShowWindow(SW_HIDE);



	}
}
