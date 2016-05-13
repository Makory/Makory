// EdittapCtrl.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "Makory.h"
#include "BalloonDlg.h"
#include "afxdialogex.h"
#include "HotAirBalloon.h"
#include "MainFrm.h"
#include "MakoryDoc.h"
#include "MakoryView.h"

// CBalloonDlg ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CBalloonDlg, CDialogEx)

CBalloonDlg::CBalloonDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CBalloonDlg::IDD, pParent)
{

}

CBalloonDlg::~CBalloonDlg()
{
}

void CBalloonDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_BALLOON_RED_SLIDER, mBalloonRedS);
	DDX_Control(pDX, IDC_BALLOON_RED_VALUE, mBalloonRedValue);
	DDX_Control(pDX, IDC_BALLOON_GREEN_SLIDER, mBalloonGreenS);
	DDX_Control(pDX, IDC_BALLOON_GREEN_VALUE, mBalloonGreenValue);
	DDX_Control(pDX, IDC_BALLOON_BLUE_SLIDER, mBalloonBlueS);
	DDX_Control(pDX, IDC_BALLOON_BLUE_VALUE, mBalloonBlueValue);
	DDX_Control(pDX, IDC_BALLOON_VSCROLL, mBalloonVSlider);
	DDX_Control(pDX, IDC_BALLOON_HSCROOL, mBalloonHSlider);
	DDX_Control(pDX, IDC_BALLOON_V_VALUE, mBalloonVEdit);
	DDX_Control(pDX, IDC_BALLOON_H_VALUE, mBalloonHEdit);
}


BEGIN_MESSAGE_MAP(CBalloonDlg, CDialogEx)

	ON_WM_HSCROLL()
	ON_EN_CHANGE(IDC_BALLOON_RED_VALUE, &CBalloonDlg::OnEnChangeBalloonRedValue)
END_MESSAGE_MAP()


// CBalloonDlg �޽��� ó�����Դϴ�.

BOOL CBalloonDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
	//red �����̴�
	mBalloonRedS.SetPos(255);//�����̴� ó�� ��ġ
	mBalloonRedS.SetRange(0, 255); //�����̴� ���� 0 ~ 100���� ��.
	mBalloonRedS.SetPageSize(10); //�����̴��� Ŭ������ �� �����̴� ����. 
	mBalloonRedValue.SetWindowTextA("255");//red edit�ڽ� �ʱⰪ

	//green �����̴�
	mBalloonGreenS.SetPos(0);//�����̴� ó�� ��ġ
	mBalloonGreenS.SetRange(0, 255); //�����̴� ���� 0 ~ 100���� ��.
	mBalloonGreenS.SetPageSize(10);  //�����̴��� Ŭ������ �� �����̴� ����
	mBalloonGreenValue.SetWindowTextA("0");//green edit�ڽ� �ʱⰪ

	//blue �����̴�
	mBalloonBlueS.SetPos(0);//�����̴� ó�� ��ġ
	mBalloonBlueS.SetRange(0, 255); //�����̴� ���� 0 ~ 100���� ��.
	mBalloonBlueS.SetPageSize(10);  //�����̴��� Ŭ������ �� �����̴� ����
	mBalloonBlueValue.SetWindowTextA("0");//blue edit�ڽ� �ʱⰪ

	//���������̴�
	mBalloonVSlider.SetPos(50);//�����̴� ó�� ��ġ
	mBalloonVSlider.SetRange(0, 100); //�����̴� ���� 0 ~ 100���� ��.
	mBalloonVSlider.SetPageSize(1);  //�����̴��� Ŭ������ �� �����̴� ����
	mBalloonVEdit.SetWindowTextA("0");//v edit�ڽ� �ʱⰪ

	//���򽽶��̴�
	mBalloonHSlider.SetPos(50);//�����̴� ó�� ��ġ
	mBalloonHSlider.SetRange(0, 100); //�����̴� ���� 0 ~ 100���� ��.
	mBalloonHSlider.SetPageSize(1);  //�����̴��� Ŭ������ �� �����̴� ����
	mBalloonHEdit.SetWindowTextA("0");//h edit�ڽ� �ʱⰪ


	return TRUE;  // return TRUE unless you set the focus to a control
	// ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
}

//��� �ʿ������...�ϴ� ������� ���߿� ���ִ°ɷ�..
void CBalloonDlg::ChangeColorTo(int balloonredcolor)
{	/*
	//int balloonredsliderpos;
	//mBalloonRedS.SetPos(balloonredcolor); //��� ��ģ���� ȣ���
	balloonredsliderpos = mBalloonRedS.GetPos();
	CString strredpos;
	strredpos.Format(_T("%d"), balloonredsliderpos); //����ȯ
	mBalloonRedValue.SetWindowTextA(strredpos);*/
	
}

//�����̴� �������� ��
void CBalloonDlg::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	CMainFrame* pFrame = (CMainFrame*)AfxGetMainWnd();				//Viewȣ��
	CMakoryView* pView = (CMakoryView*)pFrame->GetActiveView();		//Viewȣ��
	
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	if(pScrollBar)
	{
		// � �����̴����� �˻�
		//red slider�� �������� ���
		if(pScrollBar == (CScrollBar*)&mBalloonRedS)//balloon red slider�ΰ��
		{
			
			// �����̴��� ��ġ�� �˻��Ѵ�.
 			int npos = mBalloonRedS.GetPos(); //�����̴� ��ġ ����
			CString str;
			str.Format(_T("%d"), npos); //����ȯ
			mBalloonRedValue.SetWindowTextA(str); //edit �ڽ��� �����̴� �� ��

			fpos = (double)npos * 0.00392156; //�����̴��� �Ҽ����� ����� �ȵ�

			pView->HotAirBalloon.balloonred=fpos;//ǳ�� ���������� �ٲ���
			pView->Invalidate(FALSE);
		}

		//green�����̴� �������� ���
		else if(pScrollBar == (CScrollBar*)&mBalloonGreenS)//balloon green slider�ΰ��
		{
			
			// �����̴��� ��ġ�� �˻��Ѵ�.
 			int npos = mBalloonGreenS.GetPos(); //�����̴� ��ġ ����
			CString str;
			str.Format(_T("%d"), npos); //����ȯ
			mBalloonGreenValue.SetWindowTextA(str);// edit �ڽ��� �����̴� �� ��

			fpos = (double)npos * 0.00392156; //�����̴��� �Ҽ����� ����� �ȵ�

			pView->HotAirBalloon.balloongreen=fpos; //ǳ�� ������� �ٲ���
			pView->Invalidate(FALSE);
		}

	

		//blue �����̴� �������� ���
		else if(pScrollBar == (CScrollBar*)&mBalloonBlueS)//balloon green slider�ΰ��
		{

			// �����̴��� ��ġ�� �˻��Ѵ�.
			int npos = mBalloonBlueS.GetPos(); //�����̴� ��ġ ����
			CString str;
			str.Format(_T("%d"), npos); //����ȯ
			mBalloonBlueValue.SetWindowTextA(str); //blue edit �ڽ��� �����̴� �� ��

			fpos = (double)npos * 0.00392156; //�����̴��� �Ҽ����� ����� �ȵ�

			pView->HotAirBalloon.balloonblue=fpos; //ǳ�� �Ķ������� �ٲ���
			pView->Invalidate(FALSE);
		}

		//���� �����̴� �������� ���
		else if(pScrollBar == (CScrollBar*)&mBalloonVSlider)//���� �����̴��ΰ��
		{

			// �����̴��� ��ġ�� �˻��Ѵ�.
			int npos = mBalloonVSlider.GetPos(); //�����̴� ��ġ ����
			CString str;
			str.Format(_T("%d"), npos-50); //����ȯ
			mBalloonVEdit.SetWindowTextA(str); //edit �ڽ��� �����̴� �� ��

			
			if(npos <= 50){ //�����̴��� 50�����϶�
				fpos = -0.5+((double)npos * 0.01); //�������� �̵� 
			} 
			else if(npos >= 50){  //�����̴��� 50�̻��϶�
				fpos = ((double)npos * 0.01)-0.5; //���������� �̵�
			}

			pView->HotAirBalloon.balloony=fpos; //balloony���� �ٲ���
			pView->Invalidate(FALSE);
		}
		//���� �����̴� �������� ���
		else if(pScrollBar == (CScrollBar*)&mBalloonHSlider)//���� �����̴��ΰ��
		{

			// �����̴��� ��ġ�� �˻��Ѵ�.
			int npos = mBalloonHSlider.GetPos(); //�����̴� ��ġ ����
			
			CString str;
			str.Format(_T("%d"), npos-50); //����ȯ
			mBalloonHEdit.SetWindowTextA(str); //edit �ڽ��� �����̴� �� ��

			if(npos <= 50){ //�����̴��� 50�����϶�
				fpos = -0.5+((double)npos * 0.01); //������ �̵� 
				
			} 
			else if(npos >= 50){  //�����̴��� 50�̻��϶�
				fpos = ((double)npos * 0.01)-0.5; //�Ʒ������� �̵�
			}

			pView->HotAirBalloon.balloonx=fpos; //balloonx���� �ٲ���
			pView->Invalidate(FALSE);
		}

		
	}
	

	else

	{
		// CScrollView�� ��ӹ��� ���� ��� �������� ��ũ�ѷ� ���۽� pScrollBar�� NULL�ȴ�.
	}
	CDialogEx::OnHScroll(nSBCode, nPos, pScrollBar);
}



//������ �ڽ��� �ٲ��� ���
void CBalloonDlg::OnEnChangeBalloonRedValue()
{
	// TODO:  RICHEDIT ��Ʈ���� ���, �� ��Ʈ����
	// CDialogEx::OnInitDialog() �Լ��� ������ 
	//�ϰ� ����ũ�� OR �����Ͽ� ������ ENM_CHANGE �÷��׸� �����Ͽ� CRichEditCtrl().SetEventMask()�� ȣ������ ������
	// �� �˸� �޽����� ������ �ʽ��ϴ�.

	// TODO:  ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	 if(UpdateData(TRUE)){
		 
         //mBalloonRedS.SetPos(mBalloonRedValue); //����ȯ �ʿ�...���߿�..
	 }
}