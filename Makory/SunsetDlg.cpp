// EdittapCtrl.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "Makory.h"
#include "SunsetDlg.h"
#include "afxdialogex.h"
#include "HotAirBalloon.h"
#include "MainFrm.h"
#include "MakoryDoc.h"
#include "MakoryView.h"

// CSunsetlg ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CSunsetDlg, CDialogEx)

CSunsetDlg::CSunsetDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CSunsetDlg::IDD, pParent)
{

}

CSunsetDlg::~CSunsetDlg()
{
}

void CSunsetDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_SUNSET_RED_SLIDER, mSunsetRedS);
	DDX_Control(pDX, IDC_SUNSET_GREEN_SLIDER, mSunsetGreenS);
	DDX_Control(pDX, IDC_SUNSET_BLUE_SLIDER, mSunsetBlueS);
	DDX_Control(pDX, IDC_SUNSET_VSCROLL, mSunsetVSlider);
	DDX_Control(pDX, IDC_SUNSET_HSCROOL, mSunsetHSlider);
	DDX_Control(pDX, IDC_SUNSET_RED_VALUE, mSunsetRedValue);
	DDX_Control(pDX, IDC_SUNSET_GREEN_VALUE, mSunsetGreenValue);
	DDX_Control(pDX, IDC_SUNSET_BLUE_VALUE, mSunsetBlueValue);
	DDX_Control(pDX, IDC_SUNSET_V_VALUE, mSunsetVEdit);
	DDX_Control(pDX, IDC_SUNSET_H_VALUE, mSunsetHEdit);
}


BEGIN_MESSAGE_MAP(CSunsetDlg, CDialogEx)
	ON_EN_CHANGE(IDC_EDIT1, &CSunsetDlg::OnEnChangeEdit1)
	ON_WM_HSCROLL()
END_MESSAGE_MAP()


// CSunsetlg �޽��� ó�����Դϴ�.

BOOL CSunsetDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
	//red �����̴�
	mSunsetRedS.SetPos(255);//�����̴� ó�� ��ġ
	mSunsetRedS.SetRange(0, 255); //�����̴� ���� 0 ~ 100���� ��.
	mSunsetRedS.SetPageSize(10); //�����̴��� Ŭ������ �� �����̴� ����. 
	mSunsetRedValue.SetWindowTextA("255");//red edit�ڽ� �ʱⰪ

	//green �����̴�
	mSunsetGreenS.SetPos(0);//�����̴� ó�� ��ġ
	mSunsetGreenS.SetRange(0, 255); //�����̴� ���� 0 ~ 100���� ��.
	mSunsetGreenS.SetPageSize(10);  //�����̴��� Ŭ������ �� �����̴� ����
	mSunsetGreenValue.SetWindowTextA("0");//green edit�ڽ� �ʱⰪ

	//blue �����̴�
	mSunsetBlueS.SetPos(0);//�����̴� ó�� ��ġ
	mSunsetBlueS.SetRange(0, 255); //�����̴� ���� 0 ~ 100���� ��.
	mSunsetBlueS.SetPageSize(10);  //�����̴��� Ŭ������ �� �����̴� ����
	mSunsetBlueValue.SetWindowTextA("0");//blue edit�ڽ� �ʱⰪ

	//���������̴�
	mSunsetVSlider.SetPos(50);//�����̴� ó�� ��ġ
	mSunsetVSlider.SetRange(0, 100); //�����̴� ���� 0 ~ 100���� ��.
	mSunsetVSlider.SetPageSize(1);  //�����̴��� Ŭ������ �� �����̴� ����
	mSunsetVEdit.SetWindowTextA("0");//v edit�ڽ� �ʱⰪ

	//���򽽶��̴�
	mSunsetHSlider.SetPos(50);//�����̴� ó�� ��ġ
	mSunsetHSlider.SetRange(0, 100); //�����̴� ���� 0 ~ 100���� ��.
	mSunsetHSlider.SetPageSize(1);  //�����̴��� Ŭ������ �� �����̴� ����
	mSunsetHEdit.SetWindowTextA("0");//h edit�ڽ� �ʱⰪ


	return TRUE;  // return TRUE unless you set the focus to a control
	// ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
}
void CSunsetDlg::OnEnChangeEdit1()
{
	// TODO:  RICHEDIT ��Ʈ���� ���, �� ��Ʈ����
	// CDialogEx::OnInitDialog() �Լ��� ������ 
	//�ϰ� ����ũ�� OR �����Ͽ� ������ ENM_CHANGE �÷��׸� �����Ͽ� CRichEditCtrl().SetEventMask()�� ȣ������ ������
	// �� �˸� �޽����� ������ �ʽ��ϴ�.

	// TODO:  ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}


void CSunsetDlg::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	CMainFrame* pFrame = (CMainFrame*)AfxGetMainWnd();				//Viewȣ��
	CMakoryView* pView = (CMakoryView*)pFrame->GetActiveView();		//Viewȣ��

	if(pScrollBar)
	{
		// � �����̴����� �˻�
		//red slider�� �������� ���
		if(pScrollBar == (CScrollBar*)&mSunsetRedS)//balloon red slider�ΰ��
		{
			
			// �����̴��� ��ġ�� �˻��Ѵ�.
 			int npos = mSunsetRedS.GetPos(); //�����̴� ��ġ ����
			CString str;
			str.Format(_T("%d"), npos); //����ȯ
			mSunsetRedValue.SetWindowTextA(str); //edit �ڽ��� �����̴� �� ��

			dpos = (double)npos * 0.00392156; //�����̴��� �Ҽ����� ����� �ȵ�

			pView->HotAirBalloon.sunsetred=dpos;//ǳ�� ���������� �ٲ���
			pView->Invalidate(FALSE);
		}

		//green�����̴� �������� ���
		else if(pScrollBar == (CScrollBar*)&mSunsetGreenS)//balloon green slider�ΰ��
		{
			
			// �����̴��� ��ġ�� �˻��Ѵ�.
 			int npos = mSunsetGreenS.GetPos(); //�����̴� ��ġ ����
			CString str;
			str.Format(_T("%d"), npos); //����ȯ
			mSunsetGreenValue.SetWindowTextA(str);// edit �ڽ��� �����̴� �� ��

			dpos = (double)npos * 0.00392156; //�����̴��� �Ҽ����� ����� �ȵ�

			pView->HotAirBalloon.sunsetgreen=dpos; //ǳ�� ������� �ٲ���
			pView->Invalidate(FALSE);
		}

	

		//blue �����̴� �������� ���
		else if(pScrollBar == (CScrollBar*)&mSunsetBlueS)//balloon green slider�ΰ��
		{

			// �����̴��� ��ġ�� �˻��Ѵ�.
			int npos = mSunsetBlueS.GetPos(); //�����̴� ��ġ ����
			CString str;
			str.Format(_T("%d"), npos); //����ȯ
			mSunsetBlueValue.SetWindowTextA(str); //blue edit �ڽ��� �����̴� �� ��

			dpos = (double)npos * 0.00392156; //�����̴��� �Ҽ����� ����� �ȵ�

			pView->HotAirBalloon.sunsetblue=dpos; //ǳ�� �Ķ������� �ٲ���
			pView->Invalidate(FALSE);
		}

		//���� �����̴� �������� ���
		else if(pScrollBar == (CScrollBar*)&mSunsetVSlider)//���� �����̴��ΰ��
		{

			// �����̴��� ��ġ�� �˻��Ѵ�.
			int npos = mSunsetVSlider.GetPos(); //�����̴� ��ġ ����
			CString str;
			str.Format(_T("%d"), npos-50); //����ȯ
			mSunsetVEdit.SetWindowTextA(str); //edit �ڽ��� �����̴� �� ��

			
			if(npos <= 50){ //�����̴��� 50�����϶�
				dpos = -0.5+((double)npos * 0.01); //�������� �̵� 
			} 
			else if(npos >= 50){  //�����̴��� 50�̻��϶�
				dpos = ((double)npos * 0.01)-0.5; //���������� �̵�
			}

			pView->HotAirBalloon.sunsety=dpos; //balloony���� �ٲ���
			pView->Invalidate(FALSE);
		}
		//���� �����̴� �������� ���
		else if(pScrollBar == (CScrollBar*)&mSunsetHSlider)//���� �����̴��ΰ��
		{

			// �����̴��� ��ġ�� �˻��Ѵ�.
			int npos = mSunsetHSlider.GetPos(); //�����̴� ��ġ ����
			
			CString str;
			str.Format(_T("%d"), npos-50); //����ȯ
			mSunsetHEdit.SetWindowTextA(str); //edit �ڽ��� �����̴� �� ��

			if(npos <= 50){ //�����̴��� 50�����϶�
				dpos = -0.5+((double)npos * 0.01); //������ �̵� 
				
			} 
			else if(npos >= 50){  //�����̴��� 50�̻��϶�
				dpos = ((double)npos * 0.01)-0.5; //�Ʒ������� �̵�
			}

			pView->HotAirBalloon.sunsetx=dpos; //balloonx���� �ٲ���
			pView->Invalidate(FALSE);
		}

	CDialogEx::OnHScroll(nSBCode, nPos, pScrollBar);
	}
}