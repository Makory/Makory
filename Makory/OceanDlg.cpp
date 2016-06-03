// EdittapCtrl.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "Makory.h"
#include "OceanDlg.h"
#include "afxdialogex.h"
#include "Ocean.h"
#include "MainFrm.h"
#include "MakoryDoc.h"
#include "MakoryView.h"

// CFishDlg ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(COceanDlg, CDialogEx)

	COceanDlg::COceanDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(COceanDlg::IDD, pParent)
{

}

COceanDlg::~COceanDlg()
{
}

void COceanDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	//�ﰢ �����
	DDX_Control(pDX, IDC_FISH1_RED_SLIDER, mFishRedS);
	DDX_Control(pDX, IDC_FISH1_RED_VALUE, mFishRedValue);
	DDX_Control(pDX, IDC_FISH1_GREEN_SLIDER, mFishGreenS);
	DDX_Control(pDX, IDC_FISH1_GREEN_VALUE, mFishGreenValue);
	DDX_Control(pDX, IDC_FISH1_BLUE_SLIDER, mFishBlueS);
	DDX_Control(pDX, IDC_FISH1_BLUE_VALUE, mFishBlueValue);
	DDX_Control(pDX, IDC_FISH1_VSCROLL, mFishVSlider);
	DDX_Control(pDX, IDC_FISH1_HSCROOL, mFishHSlider);
	DDX_Control(pDX, IDC_FISH1_V_VALUE, mFishVEdit);
	DDX_Control(pDX, IDC_FISH1_H_VALUE, mFishHEdit);

	//����
	DDX_Control(pDX, IDC_OCEAN_COMBO, mOceanCombo);
	DDX_Control(pDX, IDC_STAR_RED_SLIDER, mStarRedS);
	DDX_Control(pDX, IDC_STAR_GREEN_SLIDER, mStarGreenS);
	DDX_Control(pDX, IDC_STAR_BLUE_SLIDER, mStarBlueS);
	DDX_Control(pDX, IDC_STAR_VSCROLL, mStarVSlider);
	DDX_Control(pDX, IDC_STAR_HSCROOL, mStarHSlider);
	DDX_Control(pDX, IDC_STAR_RED_VALUE, mStarRedValue);
	DDX_Control(pDX, IDC_STAR_GREEN_VALUE, mStarGreenValue);
	DDX_Control(pDX, IDC_STAR_BLUE_VALUE, mStarBlueValue);
	DDX_Control(pDX, IDC_STAR_V_VALUE, mStarVEdit);
	DDX_Control(pDX, IDC_STAR_H_VALUE, mStarHEdit);

	//���ʿ��� �����ϴ� �ٹ��� �����
	DDX_Control(pDX, IDC_SFISH_RED_SLIDER, mSFishRedS);
	DDX_Control(pDX, IDC_SFISH_GREEN_SLIDER, mSFishGreenS);
	DDX_Control(pDX, IDC_SFISH_BLUE_SLIDER, mSFishBlueS);
	DDX_Control(pDX, IDC_SFISH_VSCROLL, mSFishVSlider);
	DDX_Control(pDX, IDC_SFISH_HSCROOL, mSFishHSlider);
	DDX_Control(pDX, IDC_SFISH_RED_VALUE, mSFishRedValue);
	DDX_Control(pDX, IDC_SFISH_GREEN_VALUE, mSFishGreenValue);
	DDX_Control(pDX, IDC_SFISH_BLUE_VALUE, mSFishBlueValue);
	DDX_Control(pDX, IDC_SFISH_V_VALUE, mSFishVEdit);
	DDX_Control(pDX, IDC_SFISH_H_VALUE, mSFishHEdit);

	//�����ʿ��� �����ϴ� �ٹ��� �����
	DDX_Control(pDX, IDC_SFISH2_RED_SLIDER, mSFishRedS2);
	DDX_Control(pDX, IDC_SFISH2_GREEN_SLIDER, mSFishGreenS2);
	DDX_Control(pDX, IDC_SFISH2_BLUE_SLIDER, mSFishBlueS2);
	DDX_Control(pDX, IDC_SFISH2_VSCROLL, mSFishVSlider2);
	DDX_Control(pDX, IDC_SFISH2_HSCROOL, mSFishHSlider2);
	DDX_Control(pDX, IDC_SFISH2_RED_VALUE, mSFishRedValue2);
	DDX_Control(pDX, IDC_SFISH2_GREEN_VALUE, mSFishGreenValue2);
	DDX_Control(pDX, IDC_SFISH2_BLUE_VALUE, mSFishBlueValue2);
	DDX_Control(pDX, IDC_SFISH2_V_VALUE, mSFishVEdit2);
	DDX_Control(pDX, IDC_SFISH2_H_VALUE, mSFishHEdit2);
}


BEGIN_MESSAGE_MAP(COceanDlg, CDialogEx)
	ON_WM_HSCROLL()
	ON_EN_UPDATE(IDC_FISH1_RED_VALUE, &COceanDlg::OnEnUpdateFishRedValue)
	ON_EN_UPDATE(IDC_FISH1_GREEN_VALUE, &COceanDlg::OnEnUpdateFishGreenValue)
	ON_EN_UPDATE(IDC_FISH1_BLUE_VALUE, &COceanDlg::OnEnUpdateFishBlueValue)
	ON_EN_UPDATE(IDC_FISH1_V_VALUE, &COceanDlg::OnEnUpdateFishVEdit)
	ON_EN_UPDATE(IDC_FISH1_H_VALUE, &COceanDlg::OnEnUpdateFishHEdit)

	ON_EN_UPDATE(IDC_STAR_RED_VALUE, &COceanDlg::OnEnUpdateStarRedValue)
	ON_EN_UPDATE(IDC_STAR_GREEN_VALUE, &COceanDlg::OnEnUpdateStarGreenValue)
	ON_EN_UPDATE(IDC_STAR_BLUE_VALUE, &COceanDlg::OnEnUpdateStarBlueValue)
	ON_EN_UPDATE(IDC_STAR_V_VALUE, &COceanDlg::OnEnUpdateStarVEdit)
	ON_EN_UPDATE(IDC_STAR_H_VALUE, &COceanDlg::OnEnUpdateStarHEdit)

	ON_EN_UPDATE(IDC_SFISH_RED_VALUE, &COceanDlg::OnEnUpdateSFishRedValue)
	ON_EN_UPDATE(IDC_SFISH_GREEN_VALUE, &COceanDlg::OnEnUpdateSFishGreenValue)
	ON_EN_UPDATE(IDC_SFISH_BLUE_VALUE, &COceanDlg::OnEnUpdateSFishBlueValue)
	ON_EN_UPDATE(IDC_SFISH_V_VALUE, &COceanDlg::OnEnUpdateSFishVEdit)
	ON_EN_UPDATE(IDC_SFISH_H_VALUE, &COceanDlg::OnEnUpdateSFishHEdit)

	ON_EN_UPDATE(IDC_SFISH2_RED_VALUE, &COceanDlg::OnEnUpdateSFishRedValue2)
	ON_EN_UPDATE(IDC_SFISH2_GREEN_VALUE, &COceanDlg::OnEnUpdateSFishGreenValue2)
	ON_EN_UPDATE(IDC_SFISH2_BLUE_VALUE, &COceanDlg::OnEnUpdateSFishBlueValue2)
	ON_EN_UPDATE(IDC_SFISH2_V_VALUE, &COceanDlg::OnEnUpdateSFishVEdit2)
	ON_EN_UPDATE(IDC_SFISH2_H_VALUE, &COceanDlg::OnEnUpdateSFishHEdit2)

	ON_CBN_SELCHANGE(IDC_OCEAN_COMBO, &COceanDlg::OnCbnSelchangeOceanCombo)
END_MESSAGE_MAP()


// CFishDlg �޽��� ó�����Դϴ�.

BOOL COceanDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
	mFishRedS.ShowWindow(SW_HIDE);
	mFishRedValue.ShowWindow(SW_HIDE);
	mFishGreenS.ShowWindow(SW_HIDE);
	mFishGreenValue.ShowWindow(SW_HIDE);
	mFishBlueS.ShowWindow(SW_HIDE);
	mFishBlueValue.ShowWindow(SW_HIDE);
	mFishVSlider.ShowWindow(SW_HIDE);
	mFishHSlider.ShowWindow(SW_HIDE);
	mFishVEdit.ShowWindow(SW_HIDE);
	mFishHEdit.ShowWindow(SW_HIDE);

	mStarRedS.ShowWindow(SW_SHOW);
	mStarRedValue.ShowWindow(SW_SHOW);
	mStarGreenS.ShowWindow(SW_SHOW);
	mStarGreenValue.ShowWindow(SW_SHOW);
	mStarBlueS.ShowWindow(SW_SHOW);
	mStarBlueValue.ShowWindow(SW_SHOW);
	mStarVSlider.ShowWindow(SW_SHOW);
	mStarHSlider.ShowWindow(SW_SHOW);
	mStarVEdit.ShowWindow(SW_SHOW);
	mStarHEdit.ShowWindow(SW_SHOW);

	mSFishRedS.ShowWindow(SW_HIDE);
	mSFishRedValue.ShowWindow(SW_HIDE);
	mSFishGreenS.ShowWindow(SW_HIDE);
	mSFishGreenValue.ShowWindow(SW_HIDE);
	mSFishBlueS.ShowWindow(SW_HIDE);
	mSFishBlueValue.ShowWindow(SW_HIDE);
	mSFishVSlider.ShowWindow(SW_HIDE);
	mSFishHSlider.ShowWindow(SW_HIDE);
	mSFishVEdit.ShowWindow(SW_HIDE);
	mSFishHEdit.ShowWindow(SW_HIDE);

	mSFishRedS2.ShowWindow(SW_HIDE);
	mSFishRedValue2.ShowWindow(SW_HIDE);
	mSFishGreenS2.ShowWindow(SW_HIDE);
	mSFishGreenValue2.ShowWindow(SW_HIDE);
	mSFishBlueS2.ShowWindow(SW_HIDE);
	mSFishBlueValue2.ShowWindow(SW_HIDE);
	mSFishVSlider2.ShowWindow(SW_HIDE);
	mSFishHSlider2.ShowWindow(SW_HIDE);
	mSFishVEdit2.ShowWindow(SW_HIDE);
	mSFishHEdit2.ShowWindow(SW_HIDE);

	//red �����̴�
	mFishRedS.SetPos(255);//�����̴� ó�� ��ġ
	mFishRedS.SetRange(0, 255); //�����̴� ���� 0 ~ 100���� ��.
	mFishRedS.SetPageSize(10); //�����̴��� Ŭ������ �� �����̴� ����. 
	mFishRedValue.SetWindowTextA("255");//red edit�ڽ� �ʱⰪ

	//green �����̴�
	mFishGreenS.SetPos(0);//�����̴� ó�� ��ġ
	mFishGreenS.SetRange(0, 255); //�����̴� ���� 0 ~ 100���� ��.
	mFishGreenS.SetPageSize(10);  //�����̴��� Ŭ������ �� �����̴� ����
	mFishGreenValue.SetWindowTextA("0");//green edit�ڽ� �ʱⰪ

	//blue �����̴�
	mFishBlueS.SetPos(100);//�����̴� ó�� ��ġ
	mFishBlueS.SetRange(0, 255); //�����̴� ���� 0 ~ 100���� ��.
	mFishBlueS.SetPageSize(10);  //�����̴��� Ŭ������ �� �����̴� ����
	mFishBlueValue.SetWindowTextA("255");//blue edit�ڽ� �ʱⰪ

	//���������̴�
	mFishVSlider.SetPos(50);//�����̴� ó�� ��ġ
	mFishVSlider.SetRange(0, 100); //�����̴� ���� 0 ~ 100���� ��.
	mFishVSlider.SetPageSize(1);  //�����̴��� Ŭ������ �� �����̴� ����
	mFishVEdit.SetWindowTextA("0");//v edit�ڽ� �ʱⰪ

	//���򽽶��̴�
	mFishHSlider.SetPos(50);//�����̴� ó�� ��ġ
	mFishHSlider.SetRange(0, 100); //�����̴� ���� 0 ~ 100���� ��.
	mFishHSlider.SetPageSize(1);  //�����̴��� Ŭ������ �� �����̴� ����
	mFishHEdit.SetWindowTextA("0");//h edit�ڽ� �ʱⰪ

	mOceanCombo.AddString("�ﰢ �����");
	mOceanCombo.AddString("�����縮");
	mOceanCombo.AddString("�ٹ��� �����1");
	mOceanCombo.AddString("�ٹ��� �����2");
	mOceanCombo.SetCurSel(0); //�޺��ڽ� �⺻ ���� �缱

	//�����縮
	//red �����̴�
	mStarRedS.SetPos(255);//�����̴� ó�� ��ġ
	mStarRedS.SetRange(0, 255); //�����̴� ���� 0 ~ 100���� ��.
	mStarRedS.SetPageSize(10); //�����̴��� Ŭ������ �� �����̴� ����. 
	mStarRedValue.SetWindowTextA("255");//red edit�ڽ� �ʱⰪ

	//green �����̴�
	mStarGreenS.SetPos(0);//�����̴� ó�� ��ġ
	mStarGreenS.SetRange(0, 255); //�����̴� ���� 0 ~ 100���� ��.
	mStarGreenS.SetPageSize(10);  //�����̴��� Ŭ������ �� �����̴� ����
	mStarGreenValue.SetWindowTextA("0");//green edit�ڽ� �ʱⰪ

	//blue �����̴�
	mStarBlueS.SetPos(0);//�����̴� ó�� ��ġ
	mStarBlueS.SetRange(0, 255); //�����̴� ���� 0 ~ 100���� ��.
	mStarBlueS.SetPageSize(10);  //�����̴��� Ŭ������ �� �����̴� ����
	mStarBlueValue.SetWindowTextA("0");//blue edit�ڽ� �ʱⰪ

	//���������̴�
	mStarVSlider.SetPos(50);//�����̴� ó�� ��ġ
	mStarVSlider.SetRange(0, 100); //�����̴� ���� 0 ~ 100���� ��.
	mStarVSlider.SetPageSize(1);  //�����̴��� Ŭ������ �� �����̴� ����
	mStarVEdit.SetWindowTextA("0");//v edit�ڽ� �ʱⰪ

	//���򽽶��̴�
	mStarHSlider.SetPos(50);//�����̴� ó�� ��ġ
	mStarHSlider.SetRange(0, 100); //�����̴� ���� 0 ~ 100���� ��.
	mStarHSlider.SetPageSize(1);  //�����̴��� Ŭ������ �� �����̴� ����
	mStarHEdit.SetWindowTextA("0");//h edit�ڽ� �ʱⰪ

	//�ٹ��� �����1

	//red �����̴�
	mSFishRedS.SetPos(255);//�����̴� ó�� ��ġ
	mSFishRedS.SetRange(0, 255); //�����̴� ���� 0 ~ 100���� ��.
	mSFishRedS.SetPageSize(10); //�����̴��� Ŭ������ �� �����̴� ����. 
	mSFishRedValue.SetWindowTextA("255");//red edit�ڽ� �ʱⰪ

	//green �����̴�
	mSFishGreenS.SetPos(0);//�����̴� ó�� ��ġ
	mSFishGreenS.SetRange(0, 255); //�����̴� ���� 0 ~ 100���� ��.
	mSFishGreenS.SetPageSize(10);  //�����̴��� Ŭ������ �� �����̴� ����
	mSFishGreenValue.SetWindowTextA("0");//green edit�ڽ� �ʱⰪ

	//blue �����̴�
	mSFishBlueS.SetPos(0);//�����̴� ó�� ��ġ
	mSFishBlueS.SetRange(0, 255); //�����̴� ���� 0 ~ 100���� ��.
	mSFishBlueS.SetPageSize(10);  //�����̴��� Ŭ������ �� �����̴� ����
	mSFishBlueValue.SetWindowTextA("0");//blue edit�ڽ� �ʱⰪ


	//���������̴�
	mSFishVSlider.SetPos(50);//�����̴� ó�� ��ġ
	mSFishVSlider.SetRange(0, 100); //�����̴� ���� 0 ~ 100���� ��.
	mSFishVSlider.SetPageSize(1);  //�����̴��� Ŭ������ �� �����̴� ����
	mSFishVEdit.SetWindowTextA("0");//v edit�ڽ� �ʱⰪ

	//���򽽶��̴�
	mSFishHSlider.SetPos(50);//�����̴� ó�� ��ġ
	mSFishHSlider.SetRange(0, 100); //�����̴� ���� 0 ~ 100���� ��.
	mSFishHSlider.SetPageSize(1);  //�����̴��� Ŭ������ �� �����̴� ����
	mSFishHEdit.SetWindowTextA("0");//h edit�ڽ� �ʱⰪ


	//�ٹ��� �����2
	//red �����̴�
	mSFishRedS2.SetPos(255);//�����̴� ó�� ��ġ
	mSFishRedS2.SetRange(0, 255); //�����̴� ���� 0 ~ 100���� ��.
	mSFishRedS2.SetPageSize(10); //�����̴��� Ŭ������ �� �����̴� ����. 
	mSFishRedValue2.SetWindowTextA("255");//red edit�ڽ� �ʱⰪ

	//green �����̴�
	mSFishGreenS2.SetPos(0);//�����̴� ó�� ��ġ
	mSFishGreenS2.SetRange(0, 255); //�����̴� ���� 0 ~ 100���� ��.
	mSFishGreenS2.SetPageSize(10);  //�����̴��� Ŭ������ �� �����̴� ����
	mSFishGreenValue2.SetWindowTextA("0");//green edit�ڽ� �ʱⰪ

	//blue �����̴�
	mSFishBlueS2.SetPos(0);//�����̴� ó�� ��ġ
	mSFishBlueS2.SetRange(0, 255); //�����̴� ���� 0 ~ 100���� ��.
	mSFishBlueS2.SetPageSize(10);  //�����̴��� Ŭ������ �� �����̴� ����
	mSFishBlueValue2.SetWindowTextA("0");//blue edit�ڽ� �ʱⰪ


	//���������̴�
	mSFishVSlider2.SetPos(50);//�����̴� ó�� ��ġ
	mSFishVSlider2.SetRange(0, 100); //�����̴� ���� 0 ~ 100���� ��.
	mSFishVSlider2.SetPageSize(1);  //�����̴��� Ŭ������ �� �����̴� ����
	mSFishVEdit2.SetWindowTextA("0");//v edit�ڽ� �ʱⰪ

	//���򽽶��̴�
	mSFishHSlider2.SetPos(50);//�����̴� ó�� ��ġ
	mSFishHSlider2.SetRange(0, 100); //�����̴� ���� 0 ~ 100���� ��.
	mSFishHSlider2.SetPageSize(1);  //�����̴��� Ŭ������ �� �����̴� ����
	mSFishHEdit2.SetWindowTextA("0");//h edit�ڽ� �ʱⰪ


	return TRUE;  // return TRUE unless you set the focus to a control
	// ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
}


//�����̴� �������� ��
void COceanDlg::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	CMainFrame* pFrame = (CMainFrame*)AfxGetMainWnd();				//Viewȣ��
	CMakoryView* pView = (CMakoryView*)pFrame->GetActiveView();		//Viewȣ��

	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	if(pScrollBar)
	{
		// � �����̴����� �˻�
		//red slider�� �������� ���
		if(pScrollBar == (CScrollBar*)&mFishRedS)//Fish red slider�ΰ��
		{

			// �����̴��� ��ġ�� �˻��Ѵ�.
			int npos = mFishRedS.GetPos(); //�����̴� ��ġ ����
			CString str;
			str.Format(_T("%d"), npos); //����ȯ
			mFishRedValue.SetWindowTextA(str); //edit �ڽ��� �����̴� �� ��

			fpos = (double)npos * 0.00392156; //�����̴��� �Ҽ����� ����� �ȵ�

			pView->Ocean.fishred=fpos;//ǳ�� ���������� �ٲ���
			pView->Invalidate(FALSE);
		}

		//green�����̴� �������� ���
		else if(pScrollBar == (CScrollBar*)&mFishGreenS)//Fish green slider�ΰ��
		{

			// �����̴��� ��ġ�� �˻��Ѵ�.
			int npos = mFishGreenS.GetPos(); //�����̴� ��ġ ����
			CString str;
			str.Format(_T("%d"), npos); //����ȯ
			mFishGreenValue.SetWindowTextA(str);// edit �ڽ��� �����̴� �� ��

			fpos = (double)npos * 0.00392156; //�����̴��� �Ҽ����� ����� �ȵ�

			pView->Ocean.fishgreen=fpos; //ǳ�� ������� �ٲ���
			pView->Invalidate(FALSE);
		}

		//blue �����̴� �������� ���
		else if(pScrollBar == (CScrollBar*)&mFishBlueS)//Fish green slider�ΰ��
		{

			// �����̴��� ��ġ�� �˻��Ѵ�.
			int npos = mFishBlueS.GetPos(); //�����̴� ��ġ ����
			CString str;
			str.Format(_T("%d"), npos); //����ȯ
			mFishBlueValue.SetWindowTextA(str);// edit �ڽ��� �����̴� �� ��

			fpos = (double)npos * 0.00392156; //�����̴��� �Ҽ����� ����� �ȵ�

			pView->Ocean.fishblue=fpos; //ǳ�� ������� �ٲ���
			pView->Invalidate(FALSE);
		}

		
		//���� �����̴� �������� ���
		else if(pScrollBar == (CScrollBar*)&mFishVSlider)//���� �����̴��ΰ��
		{

			// �����̴��� ��ġ�� �˻��Ѵ�.
			int npos = mFishVSlider.GetPos(); //�����̴� ��ġ ����
			CString str;
			str.Format(_T("%d"), npos-50); //����ȯ
			mFishVEdit.SetWindowTextA(str); //edit �ڽ��� �����̴� �� ��


			if(npos <= 50){ //�����̴��� 50�����϶�
				fpos = -0.5+((double)npos * 0.01); //�������� �̵� 
			} 
			else if(npos >= 50){  //�����̴��� 50�̻��϶�
				fpos = ((double)npos * 0.01)-0.5; //���������� �̵�
			}

			pView->Ocean.fishy=fpos; //Fishy���� �ٲ���

			pView->Invalidate(FALSE);
		}
		//���� �����̴� �������� ���
		else if(pScrollBar == (CScrollBar*)&mFishHSlider)//���� �����̴��ΰ��
		{

			// �����̴��� ��ġ�� �˻��Ѵ�.
			int npos = mFishHSlider.GetPos(); //�����̴� ��ġ ����

			CString str;
			str.Format(_T("%d"), npos-50); //����ȯ
			mFishHEdit.SetWindowTextA(str); //edit �ڽ��� �����̴� �� ��

			if(npos <= 50){ //�����̴��� 50�����϶�
				fpos = -0.5+((double)npos * 0.01); //������ �̵� 

			} 
			else if(npos >= 50){  //�����̴��� 50�̻��϶�
				fpos = ((double)npos * 0.01)-0.5; //�Ʒ������� �̵�
			}

			pView->Ocean.fishx=fpos; //Fishx���� �ٲ���

			pView->Invalidate(FALSE);
		}

		//���� 

		if(pScrollBar == (CScrollBar*)&mStarRedS)//Fish red slider�ΰ��
		{

			// �����̴��� ��ġ�� �˻��Ѵ�.
			int npos = mStarRedS.GetPos(); //�����̴� ��ġ ����
			CString str;
			str.Format(_T("%d"), npos); //����ȯ
			mStarRedValue.SetWindowTextA(str); //edit �ڽ��� �����̴� �� ��

			fpos = (double)npos * 0.00392156; //�����̴��� �Ҽ����� ����� �ȵ�

			pView->Ocean.starred=fpos;//ǳ�� ���������� �ٲ���
			pView->Invalidate(FALSE);
		}

		//green�����̴� �������� ���
		else if(pScrollBar == (CScrollBar*)&mStarGreenS)//Fish green slider�ΰ��
		{

			// �����̴��� ��ġ�� �˻��Ѵ�.
			int npos = mStarGreenS.GetPos(); //�����̴� ��ġ ����
			CString str;
			str.Format(_T("%d"), npos); //����ȯ
			mStarGreenValue.SetWindowTextA(str);// edit �ڽ��� �����̴� �� ��

			fpos = (double)npos * 0.00392156; //�����̴��� �Ҽ����� ����� �ȵ�

			pView->Ocean.stargreen=fpos; //ǳ�� ������� �ٲ���
			pView->Invalidate(FALSE);
		}



		//blue �����̴� �������� ���
		else if(pScrollBar == (CScrollBar*)&mStarBlueS)//Fish green slider�ΰ��
		{

			// �����̴��� ��ġ�� �˻��Ѵ�.
			int npos = mStarBlueS.GetPos(); //�����̴� ��ġ ����
			CString str;
			str.Format(_T("%d"), npos); //����ȯ
			mStarBlueValue.SetWindowTextA(str); //blue edit �ڽ��� �����̴� �� ��

			fpos = (double)npos * 0.00392156; //�����̴��� �Ҽ����� ����� �ȵ�

			pView->Ocean.starblue=fpos; //ǳ�� �Ķ������� �ٲ���
			pView->Invalidate(FALSE);
		}



		else if(pScrollBar == (CScrollBar*)&mStarVSlider)//���� �����̴��ΰ��
		{

			// �����̴��� ��ġ�� �˻��Ѵ�.
			int npos = mStarVSlider.GetPos(); //�����̴� ��ġ ����
			CString str;
			str.Format(_T("%d"), npos-50); //����ȯ
			mStarVEdit.SetWindowTextA(str); //edit �ڽ��� �����̴� �� ��


			if(npos <= 50){ //�����̴��� 50�����϶�
				fpos = -0.5+((double)npos * 0.01); //�������� �̵� 
			} 
			else if(npos >= 50){  //�����̴��� 50�̻��϶�
				fpos = ((double)npos * 0.1)-5; //���������� �̵�
			}

			pView->Ocean.stary=fpos; //Fishy���� �ٲ���

			pView->Invalidate(FALSE);
		}
		//���� �����̴� �������� ���
		else if(pScrollBar == (CScrollBar*)&mStarHSlider)//���� �����̴��ΰ��
		{

			// �����̴��� ��ġ�� �˻��Ѵ�.
			int npos = mStarHSlider.GetPos(); //�����̴� ��ġ ����

			CString str;
			str.Format(_T("%d"), npos-50); //����ȯ
			mStarHEdit.SetWindowTextA(str); //edit �ڽ��� �����̴� �� ��

			if(npos <= 50){ //�����̴��� 50�����϶�
				fpos = 2*(-0.5+((double)npos * 0.01)); //������ �̵� 

			} 
			else if(npos >= 50){  //�����̴��� 50�̻��϶�
				fpos = 2*(((double)npos * 0.1)-5); //�Ʒ������� �̵�
			}

			pView->Ocean.starx=fpos; //Fishx���� �ٲ���

			pView->Invalidate(FALSE);
		}

		//�ٹ��� �����1

		//red slider�� �������� ���
		if(pScrollBar == (CScrollBar*)&mSFishRedS)//Fish red slider�ΰ��
		{

			// �����̴��� ��ġ�� �˻��Ѵ�.
			int npos = mSFishRedS.GetPos(); //�����̴� ��ġ ����
			CString str;
			str.Format(_T("%d"), npos); //����ȯ
			mSFishRedValue.SetWindowTextA(str); //edit �ڽ��� �����̴� �� ��

			fpos = (double)npos * 0.00392156; //�����̴��� �Ҽ����� ����� �ȵ�

			pView->Ocean.sfishred=fpos;//ǳ�� ���������� �ٲ���
			pView->Invalidate(FALSE);
		}

		//green�����̴� �������� ���
		else if(pScrollBar == (CScrollBar*)&mSFishGreenS)//Fish green slider�ΰ��
		{

			// �����̴��� ��ġ�� �˻��Ѵ�.
			int npos = mSFishGreenS.GetPos(); //�����̴� ��ġ ����
			CString str;
			str.Format(_T("%d"), npos); //����ȯ
			mSFishGreenValue.SetWindowTextA(str);// edit �ڽ��� �����̴� �� ��

			fpos = (double)npos * 0.00392156; //�����̴��� �Ҽ����� ����� �ȵ�

			pView->Ocean.sfishgreen=fpos; //ǳ�� ������� �ٲ���
			pView->Invalidate(FALSE);
		}

		//blue �����̴� �������� ���
		else if(pScrollBar == (CScrollBar*)&mSFishBlueS)//Fish green slider�ΰ��
		{

			// �����̴��� ��ġ�� �˻��Ѵ�.
			int npos = mSFishBlueS.GetPos(); //�����̴� ��ġ ����
			CString str;
			str.Format(_T("%d"), npos); //����ȯ
			mSFishBlueValue.SetWindowTextA(str); //blue edit �ڽ��� �����̴� �� ��

			fpos = (double)npos * 0.00392156; //�����̴��� �Ҽ����� ����� �ȵ�

			pView->Ocean.sfishblue=fpos; //ǳ�� �Ķ������� �ٲ���
			pView->Invalidate(FALSE);
		}

		else if(pScrollBar == (CScrollBar*)&mSFishVSlider)//���� �����̴��ΰ��
		{

			// �����̴��� ��ġ�� �˻��Ѵ�.
			int npos = mSFishVSlider.GetPos(); //�����̴� ��ġ ����
			CString str;
			str.Format(_T("%d"), npos-50); //����ȯ
			mSFishVEdit.SetWindowTextA(str); //edit �ڽ��� �����̴� �� ��


			if(npos <= 50){ //�����̴��� 50�����϶�
				fpos = -0.5+((double)npos * 0.01); //�������� �̵� 
			} 
			else if(npos >= 50){  //�����̴��� 50�̻��϶�
				fpos = ((double)npos * 0.01)-0.5; //���������� �̵�
			}

			pView->Ocean.sfishy=fpos; //Fishy���� �ٲ���

			pView->Invalidate(FALSE);
		}
		//���� �����̴� �������� ���
		else if(pScrollBar == (CScrollBar*)&mSFishHSlider)//���� �����̴��ΰ��
		{

			// �����̴��� ��ġ�� �˻��Ѵ�.
			int npos = mSFishHSlider.GetPos(); //�����̴� ��ġ ����

			CString str;
			str.Format(_T("%d"), npos-50); //����ȯ
			mSFishHEdit.SetWindowTextA(str); //edit �ڽ��� �����̴� �� ��

			if(npos <= 50){ //�����̴��� 50�����϶�
				fpos = -0.5+((double)npos * 0.01); //������ �̵� 

			} 
			else if(npos >= 50){  //�����̴��� 50�̻��϶�
				fpos = ((double)npos * 0.01)-0.5; //�Ʒ������� �̵�
			}

			pView->Ocean.sfishx=fpos; //Fishx���� �ٲ���

			pView->Invalidate(FALSE);
		}

		//�ٹ��� �����2

		//red slider�� �������� ���
		if(pScrollBar == (CScrollBar*)&mSFishRedS2)//Fish red slider�ΰ��
		{

			// �����̴��� ��ġ�� �˻��Ѵ�.
			int npos = mSFishRedS2.GetPos(); //�����̴� ��ġ ����
			CString str;
			str.Format(_T("%d"), npos); //����ȯ
			mSFishRedValue2.SetWindowTextA(str); //edit �ڽ��� �����̴� �� ��

			fpos = (double)npos * 0.00392156; //�����̴��� �Ҽ����� ����� �ȵ�

			pView->Ocean.sfishred2=fpos;//ǳ�� ���������� �ٲ���
			pView->Invalidate(FALSE);
		}

		//green�����̴� �������� ���
		else if(pScrollBar == (CScrollBar*)&mSFishGreenS2)//Fish green slider�ΰ��
		{

			// �����̴��� ��ġ�� �˻��Ѵ�.
			int npos = mSFishGreenS2.GetPos(); //�����̴� ��ġ ����
			CString str;
			str.Format(_T("%d"), npos); //����ȯ
			mSFishGreenValue2.SetWindowTextA(str);// edit �ڽ��� �����̴� �� ��

			fpos = (double)npos * 0.00392156; //�����̴��� �Ҽ����� ����� �ȵ�

			pView->Ocean.sfishgreen2=fpos; //ǳ�� ������� �ٲ���
			pView->Invalidate(FALSE);
		}

		//blue �����̴� �������� ���
		else if(pScrollBar == (CScrollBar*)&mSFishBlueS2)//Fish green slider�ΰ��
		{

			// �����̴��� ��ġ�� �˻��Ѵ�.
			int npos = mSFishBlueS2.GetPos(); //�����̴� ��ġ ����
			CString str;
			str.Format(_T("%d"), npos); //����ȯ
			mSFishBlueValue2.SetWindowTextA(str); //blue edit �ڽ��� �����̴� �� ��

			fpos = (double)npos * 0.00392156; //�����̴��� �Ҽ����� ����� �ȵ�

			pView->Ocean.sfishblue2=fpos; //ǳ�� �Ķ������� �ٲ���
			pView->Invalidate(FALSE);
		}


		else if(pScrollBar == (CScrollBar*)&mSFishVSlider2)//���� �����̴��ΰ��
		{

			// �����̴��� ��ġ�� �˻��Ѵ�.
			int npos = mSFishVSlider2.GetPos(); //�����̴� ��ġ ����
			CString str;
			str.Format(_T("%d"), npos-50); //����ȯ
			mSFishVEdit2.SetWindowTextA(str); //edit �ڽ��� �����̴� �� ��


			if(npos <= 50){ //�����̴��� 50�����϶�
				fpos = -0.5+((double)npos * 0.01); //�������� �̵� 
			} 
			else if(npos >= 50){  //�����̴��� 50�̻��϶�
				fpos = ((double)npos * 0.01)-0.5; //���������� �̵�
			}

			pView->Ocean.sfishy2=fpos; //Fishy���� �ٲ���

			pView->Invalidate(FALSE);
		}
		//���� �����̴� �������� ���
		else if(pScrollBar == (CScrollBar*)&mSFishHSlider2)//���� �����̴��ΰ��
		{

			// �����̴��� ��ġ�� �˻��Ѵ�.
			int npos = mSFishHSlider2.GetPos(); //�����̴� ��ġ ����

			CString str;
			str.Format(_T("%d"), npos-50); //����ȯ
			mSFishHEdit2.SetWindowTextA(str); //edit �ڽ��� �����̴� �� ��

			if(npos <= 50){ //�����̴��� 50�����϶�
				fpos = -0.5+((double)npos * 0.01); //������ �̵� 

			} 
			else if(npos >= 50){  //�����̴��� 50�̻��϶�
				fpos = ((double)npos * 0.01)-0.5; //�Ʒ������� �̵�
			}

			pView->Ocean.sfishx2=fpos; //Fishx���� �ٲ���

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
void COceanDlg::OnEnUpdateFishRedValue()
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

		mFishRedValue.GetWindowTextA(String);
		ipos = _ttoi(String);
		mFishRedS.SetPos(ipos);
		dpos = (double)ipos * 0.00392156; //�����̴��� �Ҽ����� ����� �ȵ�

		pView->Ocean.fishred=dpos;//ǳ�� ���������� �ٲ���
		pView->Invalidate(FALSE);
	}
}

//green edit
void COceanDlg::OnEnUpdateFishGreenValue()
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

		mFishGreenValue.GetWindowTextA(String);
		ipos = _ttoi(String);
		mFishGreenS.SetPos(ipos);
		dpos = (double)ipos * 0.00392156; //�����̴��� �Ҽ����� ����� �ȵ�
		pView->Ocean.fishgreen=dpos;//ǳ�� ���������� �ٲ���

		pView->Invalidate(FALSE);
	}
}

//blue edit
void COceanDlg::OnEnUpdateFishBlueValue()
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

		mFishBlueValue.GetWindowTextA(String);
		ipos = _ttoi(String);
		mFishBlueS.SetPos(ipos);
		dpos = (double)ipos * 0.00392156; //�����̴��� �Ҽ����� ����� �ȵ�
		pView->Ocean.fishblue=dpos;//ǳ�� ���������� �ٲ���

		pView->Invalidate(FALSE);
	}


}

//���� edit
void COceanDlg::OnEnUpdateFishHEdit()
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

		mFishHEdit.GetWindowTextA(String);

		ipos = _ttoi(String)+50;
		mFishHSlider.SetPos(ipos);

		if(ipos <= 50){ //�����̴��� 50�����϶�

			dpos = -0.5+((double)ipos * 0.05); //�������� �̵� 

		} 
		else if(ipos >= 50){  //�����̴��� 50�̻��϶�
			dpos = ((double)ipos * 0.05)-0.5; //���������� �̵�
		}
		pView->Ocean.fishx=dpos; //Fishx���� �ٲ���
		pView->Invalidate(FALSE);
	}
}
//���� Edit
void COceanDlg::OnEnUpdateFishVEdit()
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

		mFishVEdit.GetWindowTextA(String);

		ipos =_ttoi(String)+50;

		mFishVSlider.SetPos(ipos);

		if(ipos <= 50){ //�����̴��� 50�����϶�

			dpos = -0.5+((double)ipos * 0.01); //�������� �̵� 

		} 
		else if(ipos >= 50){  //�����̴��� 50�̻��϶�
			dpos = ((double)ipos * 0.01)-0.5; //���������� �̵�
		}

		pView->Ocean.fishy=dpos; //Fishy���� �ٲ���
		pView->Invalidate(FALSE);
	}
}


//star edit box
//RED edit
void COceanDlg::OnEnUpdateStarRedValue()
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

		mStarRedValue.GetWindowTextA(String);
		ipos = _ttoi(String);
		mStarRedS.SetPos(ipos);
		dpos = (double)ipos * 0.00392156; //�����̴��� �Ҽ����� ����� �ȵ�

		pView->Ocean.starred=dpos;//ǳ�� ���������� �ٲ���
		pView->Invalidate(FALSE);
	}
}

void COceanDlg::OnEnUpdateStarGreenValue()
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

		mStarGreenValue.GetWindowTextA(String);
		ipos = _ttoi(String);
		mStarGreenS.SetPos(ipos);
		dpos = (double)ipos * 0.00392156; //�����̴��� �Ҽ����� ����� �ȵ�

		pView->Ocean.stargreen=dpos;//ǳ�� ���������� �ٲ���
		pView->Invalidate(FALSE);
	}
}


//blue edit
void COceanDlg::OnEnUpdateStarBlueValue()
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

		mStarBlueValue.GetWindowTextA(String);
		ipos = _ttoi(String);
		mStarBlueS.SetPos(ipos);
		dpos = (double)ipos * 0.00392156; //�����̴��� �Ҽ����� ����� �ȵ�
		pView->Ocean.starblue=dpos;//ǳ�� ���������� �ٲ���

		pView->Invalidate(FALSE);
	}
}

//���� edit
void COceanDlg::OnEnUpdateStarHEdit()
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

		mStarHEdit.GetWindowTextA(String);

		ipos = _ttoi(String)+50;
		mStarHSlider.SetPos(ipos);

		if(ipos <= 50){ //�����̴��� 50�����϶�

			dpos = -0.5+((double)ipos * 0.01); //�������� �̵� 

		} 
		else if(ipos >= 50){  //�����̴��� 50�̻��϶�
			dpos = ((double)ipos * 0.1)-5;  //���������� �̵�
		}
		pView->Ocean.starx=dpos; //Fishx���� �ٲ���

		pView->Invalidate(FALSE);
	}

}
//���� Edit
void COceanDlg::OnEnUpdateStarVEdit()
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

		mStarVEdit.GetWindowTextA(String);

		ipos =_ttoi(String)+50;

		mStarVSlider.SetPos(ipos);

		if(ipos <= 50){ //�����̴��� 50�����϶�

			dpos = -0.5+((double)ipos * 0.01); //�������� �̵� 

		} 
		else if(ipos >= 50){  //�����̴��� 50�̻��϶�
			dpos = ((double)ipos * 0.1)-5; //���������� �̵�
		}

		pView->Ocean.stary=dpos; //Fishy���� �ٲ���
		pView->Invalidate(FALSE);
	}
}

//�ٹ��� �����
//RED edit
void COceanDlg::OnEnUpdateSFishRedValue()
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

		mSFishRedValue.GetWindowTextA(String);
		ipos = _ttoi(String);
		mSFishRedS.SetPos(ipos);
		dpos = (double)ipos * 0.00392156; //�����̴��� �Ҽ����� ����� �ȵ�

		pView->Ocean.sfishred=dpos;//ǳ�� ���������� �ٲ���
		pView->Invalidate(FALSE);
	}
}

//green edit
void COceanDlg::OnEnUpdateSFishGreenValue()
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

		mSFishGreenValue.GetWindowTextA(String);
		ipos = _ttoi(String);
		mSFishGreenS.SetPos(ipos);
		dpos = (double)ipos * 0.00392156; //�����̴��� �Ҽ����� ����� �ȵ�
		pView->Ocean.sfishgreen=dpos;//ǳ�� ���������� �ٲ���

		pView->Invalidate(FALSE);
	}
}

//blue edit
void COceanDlg::OnEnUpdateSFishBlueValue()
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

		mSFishBlueValue.GetWindowTextA(String);
		ipos = _ttoi(String);
		mSFishBlueS.SetPos(ipos);
		dpos = (double)ipos * 0.00392156; //�����̴��� �Ҽ����� ����� �ȵ�
		pView->Ocean.sfishblue=dpos;//ǳ�� ���������� �ٲ���

		pView->Invalidate(FALSE);
	}


}

//���� edit
void COceanDlg::OnEnUpdateSFishHEdit()
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

		mSFishHEdit.GetWindowTextA(String);

		ipos = _ttoi(String)+50;
		mSFishHSlider.SetPos(ipos);

		if(ipos <= 50){ //�����̴��� 50�����϶�

			dpos = -0.5+((double)ipos * 0.01); //�������� �̵� 

		} 
		else if(ipos >= 50){  //�����̴��� 50�̻��϶�
			dpos = ((double)ipos * 0.01)-0.5; //���������� �̵�
		}
		pView->Ocean.sfishx=dpos; //Fishx���� �ٲ���

		pView->Invalidate(FALSE);
	}

}
//���� Edit
void COceanDlg::OnEnUpdateSFishVEdit()
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

		mSFishVEdit.GetWindowTextA(String);

		ipos =_ttoi(String)+50;

		mSFishVSlider.SetPos(ipos);

		if(ipos <= 50){ //�����̴��� 50�����϶�

			dpos = -0.5+((double)ipos * 0.01); //�������� �̵� 

		} 
		else if(ipos >= 50){  //�����̴��� 50�̻��϶�
			dpos = ((double)ipos * 0.01)-0.5; //���������� �̵�
		}

		pView->Ocean.sfishy=dpos; //Fishy���� �ٲ���
		pView->Invalidate(FALSE);
	}
}


//�ٹ���2

//RED edit
void COceanDlg::OnEnUpdateSFishRedValue2()
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

		mSFishRedValue2.GetWindowTextA(String);
		ipos = _ttoi(String);
		mSFishRedS2.SetPos(ipos);
		dpos = (double)ipos * 0.00392156; //�����̴��� �Ҽ����� ����� �ȵ�

		pView->Ocean.sfishred2=dpos;//ǳ�� ���������� �ٲ���
		pView->Invalidate(FALSE);
	}
}

//green edit
void COceanDlg::OnEnUpdateSFishGreenValue2()
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

		mSFishGreenValue2.GetWindowTextA(String);
		ipos = _ttoi(String);
		mSFishGreenS2.SetPos(ipos);
		dpos = (double)ipos * 0.00392156; //�����̴��� �Ҽ����� ����� �ȵ�
		pView->Ocean.sfishgreen2=dpos;//ǳ�� ���������� �ٲ���

		pView->Invalidate(FALSE);
	}
}

//blue edit
void COceanDlg::OnEnUpdateSFishBlueValue2()
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

		mSFishBlueValue2.GetWindowTextA(String);
		ipos = _ttoi(String);
		mSFishBlueS2.SetPos(ipos);
		dpos = (double)ipos * 0.00392156; //�����̴��� �Ҽ����� ����� �ȵ�
		pView->Ocean.sfishblue2=dpos;//ǳ�� ���������� �ٲ���

		pView->Invalidate(FALSE);
	}


}

//���� edit
void COceanDlg::OnEnUpdateSFishHEdit2()
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

		mSFishHEdit2.GetWindowTextA(String);

		ipos = _ttoi(String)+50;
		mSFishHSlider2.SetPos(ipos);

		if(ipos <= 50){ //�����̴��� 50�����϶�

			dpos = -0.5+((double)ipos * 0.01); //�������� �̵� 

		} 
		else if(ipos >= 50){  //�����̴��� 50�̻��϶�
			dpos = ((double)ipos * 0.01)-0.5; //���������� �̵�
		}
		pView->Ocean.sfishx2=dpos; //Fishx���� �ٲ���

		pView->Invalidate(FALSE);
	}

}
//���� Edit
void COceanDlg::OnEnUpdateSFishVEdit2()
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

		mSFishVEdit2.GetWindowTextA(String);

		ipos =_ttoi(String)+50;

		mSFishVSlider2.SetPos(ipos);

		if(ipos <= 50){ //�����̴��� 50�����϶�

			dpos = -0.5+((double)ipos * 0.01); //�������� �̵� 

		} 
		else if(ipos >= 50){  //�����̴��� 50�̻��϶�
			dpos = ((double)ipos * 0.01)-0.5; //���������� �̵�
		}

		pView->Ocean.sfishy2=dpos; //Fishy���� �ٲ���
		pView->Invalidate(FALSE);
	}
}


//�޺� �ڽ� ���ý�
void COceanDlg::OnCbnSelchangeOceanCombo()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.

	//�ﰢ ����⼱��
	if(mOceanCombo.GetCurSel()==1){

		mFishRedS.ShowWindow(SW_SHOW);
		mFishRedValue.ShowWindow(SW_SHOW);
		mFishGreenS.ShowWindow(SW_SHOW);
		mFishGreenValue.ShowWindow(SW_SHOW);
		mFishBlueS.ShowWindow(SW_SHOW);
		mFishBlueValue.ShowWindow(SW_SHOW);
		mFishVSlider.ShowWindow(SW_SHOW);
		mFishHSlider.ShowWindow(SW_SHOW);
		mFishVEdit.ShowWindow(SW_SHOW);
		mFishHEdit.ShowWindow(SW_SHOW);
	

		mStarRedS.ShowWindow(SW_HIDE);
		mStarRedValue.ShowWindow(SW_HIDE);
		mStarGreenS.ShowWindow(SW_HIDE);
		mStarGreenValue.ShowWindow(SW_HIDE);
		mStarBlueS.ShowWindow(SW_HIDE);
		mStarBlueValue.ShowWindow(SW_HIDE);
		mStarVSlider.ShowWindow(SW_HIDE);
		mStarHSlider.ShowWindow(SW_HIDE);
		mStarVEdit.ShowWindow(SW_HIDE);
		mStarHEdit.ShowWindow(SW_HIDE);

		mSFishRedS.ShowWindow(SW_HIDE);
		mSFishRedValue.ShowWindow(SW_HIDE);
		mSFishGreenS.ShowWindow(SW_HIDE);
		mSFishGreenValue.ShowWindow(SW_HIDE);
		mSFishBlueS.ShowWindow(SW_HIDE);
		mSFishBlueValue.ShowWindow(SW_HIDE);
		mSFishVSlider.ShowWindow(SW_HIDE);
		mSFishHSlider.ShowWindow(SW_HIDE);
		mSFishVEdit.ShowWindow(SW_HIDE);
		mSFishHEdit.ShowWindow(SW_HIDE);


		mSFishRedS2.ShowWindow(SW_HIDE);
		mSFishRedValue2.ShowWindow(SW_HIDE);
		mSFishGreenS2.ShowWindow(SW_HIDE);
		mSFishGreenValue2.ShowWindow(SW_HIDE);
		mSFishBlueS2.ShowWindow(SW_HIDE);
		mSFishBlueValue2.ShowWindow(SW_HIDE);
		mSFishVSlider2.ShowWindow(SW_HIDE);
		mSFishHSlider2.ShowWindow(SW_HIDE);
		mSFishVEdit2.ShowWindow(SW_HIDE);
		mSFishHEdit2.ShowWindow(SW_HIDE);
	}
	//��������
	else if(mOceanCombo.GetCurSel()==0){
		mStarRedS.ShowWindow(SW_SHOW);
		mStarRedValue.ShowWindow(SW_SHOW);
		mStarGreenS.ShowWindow(SW_SHOW);
		mStarGreenValue.ShowWindow(SW_SHOW);
		mStarBlueS.ShowWindow(SW_SHOW);
		mStarBlueValue.ShowWindow(SW_SHOW);
		mStarVSlider.ShowWindow(SW_SHOW);
		mStarHSlider.ShowWindow(SW_SHOW);
		mStarVEdit.ShowWindow(SW_SHOW);
		mStarHEdit.ShowWindow(SW_SHOW);

		mFishRedS.ShowWindow(SW_HIDE);
		mFishRedValue.ShowWindow(SW_HIDE);
		mFishGreenS.ShowWindow(SW_HIDE);
		mFishGreenValue.ShowWindow(SW_HIDE);
		mFishBlueS.ShowWindow(SW_HIDE);
		mFishBlueValue.ShowWindow(SW_HIDE);
		mFishVSlider.ShowWindow(SW_HIDE);
		mFishHSlider.ShowWindow(SW_HIDE);
		mFishVEdit.ShowWindow(SW_HIDE);
		mFishHEdit.ShowWindow(SW_HIDE);
		mSFishRedS.ShowWindow(SW_HIDE);
		mSFishRedValue.ShowWindow(SW_HIDE);
		mSFishGreenS.ShowWindow(SW_HIDE);
		mSFishGreenValue.ShowWindow(SW_HIDE);
		mSFishBlueS.ShowWindow(SW_HIDE);
		mSFishBlueValue.ShowWindow(SW_HIDE);
		mSFishVSlider.ShowWindow(SW_HIDE);
		mSFishHSlider.ShowWindow(SW_HIDE);
		mSFishVEdit.ShowWindow(SW_HIDE);
		mSFishHEdit.ShowWindow(SW_HIDE);

		mSFishRedS2.ShowWindow(SW_HIDE);
		mSFishRedValue2.ShowWindow(SW_HIDE);
		mSFishGreenS2.ShowWindow(SW_HIDE);
		mSFishGreenValue2.ShowWindow(SW_HIDE);
		mSFishBlueS2.ShowWindow(SW_HIDE);
		mSFishBlueValue2.ShowWindow(SW_HIDE);
		mSFishVSlider2.ShowWindow(SW_HIDE);
		mSFishHSlider2.ShowWindow(SW_HIDE);
		mSFishVEdit2.ShowWindow(SW_HIDE);
		mSFishHEdit2.ShowWindow(SW_HIDE);
	}
	//�ٹ��� �����1 ����
	else if(mOceanCombo.GetCurSel()==2){
		mSFishRedS.ShowWindow(SW_SHOW);
		mSFishRedValue.ShowWindow(SW_SHOW);
		mSFishGreenS.ShowWindow(SW_SHOW);
		mSFishGreenValue.ShowWindow(SW_SHOW);
		mSFishBlueS.ShowWindow(SW_SHOW);
		mSFishBlueValue.ShowWindow(SW_SHOW);
		mSFishVSlider.ShowWindow(SW_SHOW);
		mSFishHSlider.ShowWindow(SW_SHOW);
		mSFishVEdit.ShowWindow(SW_SHOW);
		mSFishHEdit.ShowWindow(SW_SHOW);

		mStarRedS.ShowWindow(SW_HIDE);
		mStarRedValue.ShowWindow(SW_HIDE);
		mStarGreenS.ShowWindow(SW_HIDE);
		mStarGreenValue.ShowWindow(SW_HIDE);
		mStarBlueS.ShowWindow(SW_HIDE);
		mStarBlueValue.ShowWindow(SW_HIDE);
		mStarVSlider.ShowWindow(SW_HIDE);
		mStarHSlider.ShowWindow(SW_HIDE);
		mStarVEdit.ShowWindow(SW_HIDE);
		mStarHEdit.ShowWindow(SW_HIDE);

		mFishRedS.ShowWindow(SW_HIDE);
		mFishRedValue.ShowWindow(SW_HIDE);
		mFishGreenS.ShowWindow(SW_HIDE);
		mFishGreenValue.ShowWindow(SW_HIDE);
		mFishBlueS.ShowWindow(SW_HIDE);
		mFishBlueValue.ShowWindow(SW_HIDE);
		mFishVSlider.ShowWindow(SW_HIDE);
		mFishHSlider.ShowWindow(SW_HIDE);
		mFishVEdit.ShowWindow(SW_HIDE);
		mFishHEdit.ShowWindow(SW_HIDE);

		mSFishRedS2.ShowWindow(SW_HIDE);
		mSFishRedValue2.ShowWindow(SW_HIDE);
		mSFishGreenS2.ShowWindow(SW_HIDE);
		mSFishGreenValue2.ShowWindow(SW_HIDE);
		mSFishBlueS2.ShowWindow(SW_HIDE);
		mSFishBlueValue2.ShowWindow(SW_HIDE);
		mSFishVSlider2.ShowWindow(SW_HIDE);
		mSFishHSlider2.ShowWindow(SW_HIDE);
		mSFishVEdit2.ShowWindow(SW_HIDE);
		mSFishHEdit2.ShowWindow(SW_HIDE);
	}
	else if(mOceanCombo.GetCurSel()==3){
		mSFishRedS2.ShowWindow(SW_SHOW);
		mSFishRedValue2.ShowWindow(SW_SHOW);
		mSFishGreenS2.ShowWindow(SW_SHOW);
		mSFishGreenValue2.ShowWindow(SW_SHOW);
		mSFishBlueS2.ShowWindow(SW_SHOW);
		mSFishBlueValue2.ShowWindow(SW_SHOW);
		mSFishVSlider2.ShowWindow(SW_SHOW);
		mSFishHSlider2.ShowWindow(SW_SHOW);
		mSFishVEdit2.ShowWindow(SW_SHOW);
		mSFishHEdit2.ShowWindow(SW_SHOW);

		mSFishRedS.ShowWindow(SW_HIDE);
		mSFishRedValue.ShowWindow(SW_HIDE);
		mSFishGreenS.ShowWindow(SW_HIDE);
		mSFishGreenValue.ShowWindow(SW_HIDE);
		mSFishBlueS.ShowWindow(SW_HIDE);
		mSFishBlueValue.ShowWindow(SW_HIDE);
		mSFishVSlider.ShowWindow(SW_HIDE);
		mSFishHSlider.ShowWindow(SW_HIDE);
		mSFishVEdit.ShowWindow(SW_HIDE);
		mSFishHEdit.ShowWindow(SW_HIDE);

		mStarRedS.ShowWindow(SW_HIDE);
		mStarRedValue.ShowWindow(SW_HIDE);
		mStarGreenS.ShowWindow(SW_HIDE);
		mStarGreenValue.ShowWindow(SW_HIDE);
		mStarBlueS.ShowWindow(SW_HIDE);
		mStarBlueValue.ShowWindow(SW_HIDE);
		mStarVSlider.ShowWindow(SW_HIDE);
		mStarHSlider.ShowWindow(SW_HIDE);
		mStarVEdit.ShowWindow(SW_HIDE);
		mStarHEdit.ShowWindow(SW_HIDE);

		mFishRedS.ShowWindow(SW_HIDE);
		mFishRedValue.ShowWindow(SW_HIDE);
		mFishGreenS.ShowWindow(SW_HIDE);
		mFishGreenValue.ShowWindow(SW_HIDE);
		mFishBlueS.ShowWindow(SW_HIDE);
		mFishBlueValue.ShowWindow(SW_HIDE);
		mFishVSlider.ShowWindow(SW_HIDE);
		mFishHSlider.ShowWindow(SW_HIDE);
		mFishVEdit.ShowWindow(SW_HIDE);
		mFishHEdit.ShowWindow(SW_HIDE);
	}
}
