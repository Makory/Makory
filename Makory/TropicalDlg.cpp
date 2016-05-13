// EdittapCtrl.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "Makory.h"
#include "TropicalDlg.h"
#include "afxdialogex.h"
#include "HotAirBalloon.h"
#include "MainFrm.h"
#include "MakoryDoc.h"
#include "MakoryView.h"

// CTropicallg ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CTropicalDlg, CDialogEx)

CTropicalDlg::CTropicalDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CTropicalDlg::IDD, pParent)
{

}

CTropicalDlg::~CTropicalDlg()
{
}

void CTropicalDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TROPICAL_RED_SLIDER, mTropicalRedS);
	DDX_Control(pDX, IDC_TROPICAL_GREEN_SLIDER, mTropicalGreenS);
	DDX_Control(pDX, IDC_TROPICAL_BLUE_SLIDER, mTropicalBlueS);
	DDX_Control(pDX, IDC_TROPICAL_VSCROLL, mTropicalVSlider);
	DDX_Control(pDX, IDC_TROPICAL_HSCROOL, mTropicalHSlider);
	DDX_Control(pDX, IDC_TROPICAL_RED_VALUE, mTropicalRedValue);
	DDX_Control(pDX, IDC_TROPICAL_GREEN_VALUE, mTropicalGreenValue);
	DDX_Control(pDX, IDC_TROPICAL_BLUE_VALUE, mTropicalBlueValue);
	DDX_Control(pDX, IDC_TROPICAL_V_VALUE, mTropicalVEdit);
	DDX_Control(pDX, IDC_TROPICAL_H_VALUE, mTropicalHEdit);
}


BEGIN_MESSAGE_MAP(CTropicalDlg, CDialogEx)
	ON_EN_CHANGE(IDC_EDIT1, &CTropicalDlg::OnEnChangeEdit1)
	ON_WM_HSCROLL()
END_MESSAGE_MAP()


// CTropicallg �޽��� ó�����Դϴ�.

BOOL CTropicalDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
	//red �����̴�
	mTropicalRedS.SetPos(255);//�����̴� ó�� ��ġ
	mTropicalRedS.SetRange(0, 255); //�����̴� ���� 0 ~ 100���� ��.
	mTropicalRedS.SetPageSize(10); //�����̴��� Ŭ������ �� �����̴� ����. 
	mTropicalRedValue.SetWindowTextA("255");//red edit�ڽ� �ʱⰪ

	//green �����̴�
	mTropicalGreenS.SetPos(0);//�����̴� ó�� ��ġ
	mTropicalGreenS.SetRange(0, 255); //�����̴� ���� 0 ~ 100���� ��.
	mTropicalGreenS.SetPageSize(10);  //�����̴��� Ŭ������ �� �����̴� ����
	mTropicalGreenValue.SetWindowTextA("0");//green edit�ڽ� �ʱⰪ

	//blue �����̴�
	mTropicalBlueS.SetPos(0);//�����̴� ó�� ��ġ
	mTropicalBlueS.SetRange(0, 255); //�����̴� ���� 0 ~ 100���� ��.
	mTropicalBlueS.SetPageSize(10);  //�����̴��� Ŭ������ �� �����̴� ����
	mTropicalBlueValue.SetWindowTextA("0");//blue edit�ڽ� �ʱⰪ

	//���������̴�
	mTropicalVSlider.SetPos(50);//�����̴� ó�� ��ġ
	mTropicalVSlider.SetRange(0, 100); //�����̴� ���� 0 ~ 100���� ��.
	mTropicalVSlider.SetPageSize(1);  //�����̴��� Ŭ������ �� �����̴� ����
	mTropicalVEdit.SetWindowTextA("0");//v edit�ڽ� �ʱⰪ

	//���򽽶��̴�
	mTropicalHSlider.SetPos(50);//�����̴� ó�� ��ġ
	mTropicalHSlider.SetRange(0, 100); //�����̴� ���� 0 ~ 100���� ��.
	mTropicalHSlider.SetPageSize(1);  //�����̴��� Ŭ������ �� �����̴� ����
	mTropicalHEdit.SetWindowTextA("0");//h edit�ڽ� �ʱⰪ


	return TRUE;  // return TRUE unless you set the focus to a control
	// ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
}
void CTropicalDlg::OnEnChangeEdit1()
{
	// TODO:  RICHEDIT ��Ʈ���� ���, �� ��Ʈ����
	// CDialogEx::OnInitDialog() �Լ��� ������ 
	//�ϰ� ����ũ�� OR �����Ͽ� ������ ENM_CHANGE �÷��׸� �����Ͽ� CRichEditCtrl().SetEventMask()�� ȣ������ ������
	// �� �˸� �޽����� ������ �ʽ��ϴ�.

	// TODO:  ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}


void CTropicalDlg::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	CMainFrame* pFrame = (CMainFrame*)AfxGetMainWnd();				//Viewȣ��
	CMakoryView* pView = (CMakoryView*)pFrame->GetActiveView();		//Viewȣ��

	if(pScrollBar)
	{
		// � �����̴����� �˻�
		//red slider�� �������� ���
		if(pScrollBar == (CScrollBar*)&mTropicalRedS)//balloon red slider�ΰ��
		{
			
			// �����̴��� ��ġ�� �˻��Ѵ�.
 			int npos = mTropicalRedS.GetPos(); //�����̴� ��ġ ����
			CString str;
			str.Format(_T("%d"), npos); //����ȯ
			mTropicalRedValue.SetWindowTextA(str); //edit �ڽ��� �����̴� �� ��

			dpos = (double)npos * 0.00392156; //�����̴��� �Ҽ����� ����� �ȵ�

			pView->HotAirBalloon.tropicalred=dpos;//ǳ�� ���������� �ٲ���
			pView->Invalidate(FALSE);
		}

		//green�����̴� �������� ���
		else if(pScrollBar == (CScrollBar*)&mTropicalGreenS)//balloon green slider�ΰ��
		{
			
			// �����̴��� ��ġ�� �˻��Ѵ�.
 			int npos = mTropicalGreenS.GetPos(); //�����̴� ��ġ ����
			CString str;
			str.Format(_T("%d"), npos); //����ȯ
			mTropicalGreenValue.SetWindowTextA(str);// edit �ڽ��� �����̴� �� ��

			dpos = (double)npos * 0.00392156; //�����̴��� �Ҽ����� ����� �ȵ�

			pView->HotAirBalloon.tropicalgreen=dpos; //ǳ�� ������� �ٲ���
			pView->Invalidate(FALSE);
		}

	

		//blue �����̴� �������� ���
		else if(pScrollBar == (CScrollBar*)&mTropicalBlueS)//balloon green slider�ΰ��
		{

			// �����̴��� ��ġ�� �˻��Ѵ�.
			int npos = mTropicalBlueS.GetPos(); //�����̴� ��ġ ����
			CString str;
			str.Format(_T("%d"), npos); //����ȯ
			mTropicalBlueValue.SetWindowTextA(str); //blue edit �ڽ��� �����̴� �� ��

			dpos = (double)npos * 0.00392156; //�����̴��� �Ҽ����� ����� �ȵ�

			pView->HotAirBalloon.tropicalblue=dpos; //ǳ�� �Ķ������� �ٲ���
			pView->Invalidate(FALSE);
		}

		//���� �����̴� �������� ���
		else if(pScrollBar == (CScrollBar*)&mTropicalVSlider)//���� �����̴��ΰ��
		{

			// �����̴��� ��ġ�� �˻��Ѵ�.
			int npos = mTropicalVSlider.GetPos(); //�����̴� ��ġ ����
			CString str;
			str.Format(_T("%d"), npos-50); //����ȯ
			mTropicalVEdit.SetWindowTextA(str); //edit �ڽ��� �����̴� �� ��

			
			if(npos <= 50){ //�����̴��� 50�����϶�
				dpos = -0.5+((double)npos * 0.01); //�������� �̵� 
			} 
			else if(npos >= 50){  //�����̴��� 50�̻��϶�
				dpos = ((double)npos * 0.01)-0.5; //���������� �̵�
			}

			pView->HotAirBalloon.tropicaly=dpos; //balloony���� �ٲ���
			pView->Invalidate(FALSE);
		}
		//���� �����̴� �������� ���
		else if(pScrollBar == (CScrollBar*)&mTropicalHSlider)//���� �����̴��ΰ��
		{

			// �����̴��� ��ġ�� �˻��Ѵ�.
			int npos = mTropicalHSlider.GetPos(); //�����̴� ��ġ ����
			
			CString str;
			str.Format(_T("%d"), npos-50); //����ȯ
			mTropicalHEdit.SetWindowTextA(str); //edit �ڽ��� �����̴� �� ��

			if(npos <= 50){ //�����̴��� 50�����϶�
				dpos = -0.5+((double)npos * 0.01); //������ �̵� 
				
			} 
			else if(npos >= 50){  //�����̴��� 50�̻��϶�
				dpos = ((double)npos * 0.01)-0.5; //�Ʒ������� �̵�
			}

			pView->HotAirBalloon.tropicalx=dpos; //balloonx���� �ٲ���
			pView->Invalidate(FALSE);
		}

	CDialogEx::OnHScroll(nSBCode, nPos, pScrollBar);
	}
}