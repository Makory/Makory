// EdittapCtrl.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "Makory.h"
#include "FullmoonDlg.h"
#include "afxdialogex.h"
#include "HotAirBalloon.h"
#include "MainFrm.h"
#include "MakoryDoc.h"
#include "MakoryView.h"

// CFullmoonDlg ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CFullmoonDlg, CDialogEx)

CFullmoonDlg::CFullmoonDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CFullmoonDlg::IDD, pParent)
{

}

CFullmoonDlg::~CFullmoonDlg()
{
}

void CFullmoonDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_FULLMOON_RED_SLIDER, mFullmoonRedS);
	DDX_Control(pDX, IDC_FULLMOON_GREEN_SLIDER, mFullmoonGreenS);
	DDX_Control(pDX, IDC_FULLMOON_BLUE_SLIDER, mFullmoonBlueS);
	DDX_Control(pDX, IDC_FULLMOON_VSCROLL, mFullmoonVSlider);
	DDX_Control(pDX, IDC_FULLMOON_HSCROOL, mFullmoonHSlider);
	DDX_Control(pDX, IDC_FULLMOON_RED_VALUE, mFullmoonRedValue);
	DDX_Control(pDX, IDC_FULLMOON_GREEN_VALUE, mFullmoonGreenValue);
	DDX_Control(pDX, IDC_FULLMOON_BLUE_VALUE, mFullmoonBlueValue);
	DDX_Control(pDX, IDC_FULLMOON_V_VALUE, mFullmoonVEdit);
	DDX_Control(pDX, IDC_FULLMOON_H_VALUE, mFullmoonHEdit);
}


BEGIN_MESSAGE_MAP(CFullmoonDlg, CDialogEx)
	ON_EN_CHANGE(IDC_EDIT1, &CFullmoonDlg::OnEnChangeEdit1)
	ON_WM_HSCROLL()
END_MESSAGE_MAP()


// CFullmoonDlg �޽��� ó�����Դϴ�.

BOOL CFullmoonDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
	//red �����̴�
	mFullmoonRedS.SetPos(255);//�����̴� ó�� ��ġ
	mFullmoonRedS.SetRange(0, 255); //�����̴� ���� 0 ~ 100���� ��.
	mFullmoonRedS.SetPageSize(10); //�����̴��� Ŭ������ �� �����̴� ����. 
	mFullmoonRedValue.SetWindowTextA("255");//red edit�ڽ� �ʱⰪ

	//green �����̴�
	mFullmoonGreenS.SetPos(0);//�����̴� ó�� ��ġ
	mFullmoonGreenS.SetRange(0, 255); //�����̴� ���� 0 ~ 100���� ��.
	mFullmoonGreenS.SetPageSize(10);  //�����̴��� Ŭ������ �� �����̴� ����
	mFullmoonGreenValue.SetWindowTextA("0");//green edit�ڽ� �ʱⰪ

	//blue �����̴�
	mFullmoonBlueS.SetPos(0);//�����̴� ó�� ��ġ
	mFullmoonBlueS.SetRange(0, 255); //�����̴� ���� 0 ~ 100���� ��.
	mFullmoonBlueS.SetPageSize(10);  //�����̴��� Ŭ������ �� �����̴� ����
	mFullmoonBlueValue.SetWindowTextA("0");//blue edit�ڽ� �ʱⰪ

	//���������̴�
	mFullmoonVSlider.SetPos(50);//�����̴� ó�� ��ġ
	mFullmoonVSlider.SetRange(0, 100); //�����̴� ���� 0 ~ 100���� ��.
	mFullmoonVSlider.SetPageSize(1);  //�����̴��� Ŭ������ �� �����̴� ����
	mFullmoonVEdit.SetWindowTextA("0");//v edit�ڽ� �ʱⰪ

	//���򽽶��̴�
	mFullmoonHSlider.SetPos(50);//�����̴� ó�� ��ġ
	mFullmoonHSlider.SetRange(0, 100); //�����̴� ���� 0 ~ 100���� ��.
	mFullmoonHSlider.SetPageSize(1);  //�����̴��� Ŭ������ �� �����̴� ����
	mFullmoonHEdit.SetWindowTextA("0");//h edit�ڽ� �ʱⰪ


	return TRUE;  // return TRUE unless you set the focus to a control
	// ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
}
void CFullmoonDlg::OnEnChangeEdit1()
{
	// TODO:  RICHEDIT ��Ʈ���� ���, �� ��Ʈ����
	// CDialogEx::OnInitDialog() �Լ��� ������ 
	//�ϰ� ����ũ�� OR �����Ͽ� ������ ENM_CHANGE �÷��׸� �����Ͽ� CRichEditCtrl().SetEventMask()�� ȣ������ ������
	// �� �˸� �޽����� ������ �ʽ��ϴ�.

	// TODO:  ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}


void CFullmoonDlg::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	CMainFrame* pFrame = (CMainFrame*)AfxGetMainWnd();				//Viewȣ��
	CMakoryView* pView = (CMakoryView*)pFrame->GetActiveView();		//Viewȣ��

	if(pScrollBar)
	{
		// � �����̴����� �˻�
		//red slider�� �������� ���
		if(pScrollBar == (CScrollBar*)&mFullmoonRedS)//balloon red slider�ΰ��
		{
			
			// �����̴��� ��ġ�� �˻��Ѵ�.
 			int npos = mFullmoonRedS.GetPos(); //�����̴� ��ġ ����
			CString str;
			str.Format(_T("%d"), npos); //����ȯ
			mFullmoonRedValue.SetWindowTextA(str); //edit �ڽ��� �����̴� �� ��

			dpos = (double)npos * 0.00392156; //�����̴��� �Ҽ����� ����� �ȵ�

			pView->HotAirBalloon.fullmoonred=dpos;//ǳ�� ���������� �ٲ���
			pView->Invalidate(FALSE);
		}

		//green�����̴� �������� ���
		else if(pScrollBar == (CScrollBar*)&mFullmoonGreenS)//balloon green slider�ΰ��
		{
			
			// �����̴��� ��ġ�� �˻��Ѵ�.
 			int npos = mFullmoonGreenS.GetPos(); //�����̴� ��ġ ����
			CString str;
			str.Format(_T("%d"), npos); //����ȯ
			mFullmoonGreenValue.SetWindowTextA(str);// edit �ڽ��� �����̴� �� ��

			dpos = (double)npos * 0.00392156; //�����̴��� �Ҽ����� ����� �ȵ�

			pView->HotAirBalloon.fullmoongreen=dpos; //ǳ�� ������� �ٲ���
			pView->Invalidate(FALSE);
		}

	

		//blue �����̴� �������� ���
		else if(pScrollBar == (CScrollBar*)&mFullmoonBlueS)//balloon green slider�ΰ��
		{

			// �����̴��� ��ġ�� �˻��Ѵ�.
			int npos = mFullmoonBlueS.GetPos(); //�����̴� ��ġ ����
			CString str;
			str.Format(_T("%d"), npos); //����ȯ
			mFullmoonBlueValue.SetWindowTextA(str); //blue edit �ڽ��� �����̴� �� ��

			dpos = (double)npos * 0.00392156; //�����̴��� �Ҽ����� ����� �ȵ�

			pView->HotAirBalloon.fullmoonblue=dpos; //ǳ�� �Ķ������� �ٲ���
			pView->Invalidate(FALSE);
		}

		//���� �����̴� �������� ���
		else if(pScrollBar == (CScrollBar*)&mFullmoonVSlider)//���� �����̴��ΰ��
		{

			// �����̴��� ��ġ�� �˻��Ѵ�.
			int npos = mFullmoonVSlider.GetPos(); //�����̴� ��ġ ����
			CString str;
			str.Format(_T("%d"), npos-50); //����ȯ
			mFullmoonVEdit.SetWindowTextA(str); //edit �ڽ��� �����̴� �� ��

			
			if(npos <= 50){ //�����̴��� 50�����϶�
				dpos = -0.5+((double)npos * 0.01); //�������� �̵� 
			} 
			else if(npos >= 50){  //�����̴��� 50�̻��϶�
				dpos = ((double)npos * 0.01)-0.5; //���������� �̵�
			}

			pView->HotAirBalloon.fullmoony=dpos; //balloony���� �ٲ���
			pView->Invalidate(FALSE);
		}
		//���� �����̴� �������� ���
		else if(pScrollBar == (CScrollBar*)&mFullmoonHSlider)//���� �����̴��ΰ��
		{

			// �����̴��� ��ġ�� �˻��Ѵ�.
			int npos = mFullmoonHSlider.GetPos(); //�����̴� ��ġ ����
			
			CString str;
			str.Format(_T("%d"), npos-50); //����ȯ
			mFullmoonHEdit.SetWindowTextA(str); //edit �ڽ��� �����̴� �� ��

			if(npos <= 50){ //�����̴��� 50�����϶�
				dpos = -0.5+((double)npos * 0.01); //������ �̵� 
				
			} 
			else if(npos >= 50){  //�����̴��� 50�̻��϶�
				dpos = ((double)npos * 0.01)-0.5; //�Ʒ������� �̵�
			}

			pView->HotAirBalloon.fullmoonx=dpos; //balloonx���� �ٲ���
			pView->Invalidate(FALSE);
		}

	CDialogEx::OnHScroll(nSBCode, nPos, pScrollBar);
	}
}