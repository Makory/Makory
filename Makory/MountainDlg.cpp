// EdittapCtrl.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "Makory.h"
#include "MountainDlg.h"
#include "afxdialogex.h"
#include "HotAirBalloon.h"
#include "MainFrm.h"
#include "MakoryDoc.h"
#include "MakoryView.h"

// CMountainlg ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CMountainDlg, CDialogEx)

CMountainDlg::CMountainDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMountainDlg::IDD, pParent)
{

}

CMountainDlg::~CMountainDlg()
{
}

void CMountainDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_MOUNTAIN_RED_SLIDER, mMountainRedS);
	DDX_Control(pDX, IDC_MOUNTAIN_GREEN_SLIDER, mMountainGreenS);
	DDX_Control(pDX, IDC_MOUNTAIN_BLUE_SLIDER, mMountainBlueS);
	DDX_Control(pDX, IDC_MOUNTAIN_VSCROLL, mMountainVSlider);
	DDX_Control(pDX, IDC_MOUNTAIN_HSCROOL, mMountainHSlider);
	DDX_Control(pDX, IDC_MOUNTAIN_RED_VALUE, mMountainRedValue);
	DDX_Control(pDX, IDC_MOUNTAIN_GREEN_VALUE, mMountainGreenValue);
	DDX_Control(pDX, IDC_MOUNTAIN_BLUE_VALUE, mMountainBlueValue);
	DDX_Control(pDX, IDC_MOUNTAIN_V_VALUE, mMountainVEdit);
	DDX_Control(pDX, IDC_MOUNTAIN_H_VALUE, mMountainHEdit);
}


BEGIN_MESSAGE_MAP(CMountainDlg, CDialogEx)
	ON_EN_CHANGE(IDC_EDIT1, &CMountainDlg::OnEnChangeEdit1)
	ON_WM_HSCROLL()
END_MESSAGE_MAP()


// CMountainlg �޽��� ó�����Դϴ�.

BOOL CMountainDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
	//red �����̴�
	mMountainRedS.SetPos(255);//�����̴� ó�� ��ġ
	mMountainRedS.SetRange(0, 255); //�����̴� ���� 0 ~ 100���� ��.
	mMountainRedS.SetPageSize(10); //�����̴��� Ŭ������ �� �����̴� ����. 
	mMountainRedValue.SetWindowTextA("255");//red edit�ڽ� �ʱⰪ

	//green �����̴�
	mMountainGreenS.SetPos(0);//�����̴� ó�� ��ġ
	mMountainGreenS.SetRange(0, 255); //�����̴� ���� 0 ~ 100���� ��.
	mMountainGreenS.SetPageSize(10);  //�����̴��� Ŭ������ �� �����̴� ����
	mMountainGreenValue.SetWindowTextA("0");//green edit�ڽ� �ʱⰪ

	//blue �����̴�
	mMountainBlueS.SetPos(0);//�����̴� ó�� ��ġ
	mMountainBlueS.SetRange(0, 255); //�����̴� ���� 0 ~ 100���� ��.
	mMountainBlueS.SetPageSize(10);  //�����̴��� Ŭ������ �� �����̴� ����
	mMountainBlueValue.SetWindowTextA("0");//blue edit�ڽ� �ʱⰪ

	//���������̴�
	mMountainVSlider.SetPos(50);//�����̴� ó�� ��ġ
	mMountainVSlider.SetRange(0, 100); //�����̴� ���� 0 ~ 100���� ��.
	mMountainVSlider.SetPageSize(1);  //�����̴��� Ŭ������ �� �����̴� ����
	mMountainVEdit.SetWindowTextA("0");//v edit�ڽ� �ʱⰪ

	//���򽽶��̴�
	mMountainHSlider.SetPos(50);//�����̴� ó�� ��ġ
	mMountainHSlider.SetRange(0, 100); //�����̴� ���� 0 ~ 100���� ��.
	mMountainHSlider.SetPageSize(1);  //�����̴��� Ŭ������ �� �����̴� ����
	mMountainHEdit.SetWindowTextA("0");//h edit�ڽ� �ʱⰪ


	return TRUE;  // return TRUE unless you set the focus to a control
	// ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
}
void CMountainDlg::OnEnChangeEdit1()
{
	// TODO:  RICHEDIT ��Ʈ���� ���, �� ��Ʈ����
	// CDialogEx::OnInitDialog() �Լ��� ������ 
	//�ϰ� ����ũ�� OR �����Ͽ� ������ ENM_CHANGE �÷��׸� �����Ͽ� CRichEditCtrl().SetEventMask()�� ȣ������ ������
	// �� �˸� �޽����� ������ �ʽ��ϴ�.

	// TODO:  ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}


void CMountainDlg::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	CMainFrame* pFrame = (CMainFrame*)AfxGetMainWnd();				//Viewȣ��
	CMakoryView* pView = (CMakoryView*)pFrame->GetActiveView();		//Viewȣ��

	if(pScrollBar)
	{
		// � �����̴����� �˻�
		//red slider�� �������� ���
		if(pScrollBar == (CScrollBar*)&mMountainRedS)//balloon red slider�ΰ��
		{
			
			// �����̴��� ��ġ�� �˻��Ѵ�.
 			int npos = mMountainRedS.GetPos(); //�����̴� ��ġ ����
			CString str;
			str.Format(_T("%d"), npos); //����ȯ
			mMountainRedValue.SetWindowTextA(str); //edit �ڽ��� �����̴� �� ��

			dpos = (double)npos * 0.00392156; //�����̴��� �Ҽ����� ����� �ȵ�

			pView->HotAirBalloon.mountred=dpos;//ǳ�� ���������� �ٲ���
			pView->Invalidate(FALSE);
		}

		//green�����̴� �������� ���
		else if(pScrollBar == (CScrollBar*)&mMountainGreenS)//balloon green slider�ΰ��
		{
			
			// �����̴��� ��ġ�� �˻��Ѵ�.
 			int npos = mMountainGreenS.GetPos(); //�����̴� ��ġ ����
			CString str;
			str.Format(_T("%d"), npos); //����ȯ
			mMountainGreenValue.SetWindowTextA(str);// edit �ڽ��� �����̴� �� ��

			dpos = (double)npos * 0.00392156; //�����̴��� �Ҽ����� ����� �ȵ�

			pView->HotAirBalloon.mountgreen=dpos; //ǳ�� ������� �ٲ���
			pView->Invalidate(FALSE);
		}

	

		//blue �����̴� �������� ���
		else if(pScrollBar == (CScrollBar*)&mMountainBlueS)//balloon green slider�ΰ��
		{

			// �����̴��� ��ġ�� �˻��Ѵ�.
			int npos = mMountainBlueS.GetPos(); //�����̴� ��ġ ����
			CString str;
			str.Format(_T("%d"), npos); //����ȯ
			mMountainBlueValue.SetWindowTextA(str); //blue edit �ڽ��� �����̴� �� ��

			dpos = (double)npos * 0.00392156; //�����̴��� �Ҽ����� ����� �ȵ�

			pView->HotAirBalloon.mountblue=dpos; //ǳ�� �Ķ������� �ٲ���
			pView->Invalidate(FALSE);
		}

		//���� �����̴� �������� ���
		else if(pScrollBar == (CScrollBar*)&mMountainVSlider)//���� �����̴��ΰ��
		{

			// �����̴��� ��ġ�� �˻��Ѵ�.
			int npos = mMountainVSlider.GetPos(); //�����̴� ��ġ ����
			CString str;
			str.Format(_T("%d"), npos-50); //����ȯ
			mMountainVEdit.SetWindowTextA(str); //edit �ڽ��� �����̴� �� ��

			
			if(npos <= 50){ //�����̴��� 50�����϶�
				dpos = -0.5+((double)npos * 0.01); //�������� �̵� 
			} 
			else if(npos >= 50){  //�����̴��� 50�̻��϶�
				dpos = ((double)npos * 0.01)-0.5; //���������� �̵�
			}

			pView->HotAirBalloon.mounty=dpos; //balloony���� �ٲ���
			pView->Invalidate(FALSE);
		}
		//���� �����̴� �������� ���
		else if(pScrollBar == (CScrollBar*)&mMountainHSlider)//���� �����̴��ΰ��
		{

			// �����̴��� ��ġ�� �˻��Ѵ�.
			int npos = mMountainHSlider.GetPos(); //�����̴� ��ġ ����
			
			CString str;
			str.Format(_T("%d"), npos-50); //����ȯ
			mMountainHEdit.SetWindowTextA(str); //edit �ڽ��� �����̴� �� ��

			if(npos <= 50){ //�����̴��� 50�����϶�
				dpos = -0.5+((double)npos * 0.01); //������ �̵� 
				
			} 
			else if(npos >= 50){  //�����̴��� 50�̻��϶�
				dpos = ((double)npos * 0.01)-0.5; //�Ʒ������� �̵�
			}

			pView->HotAirBalloon.mountx=dpos; //balloonx���� �ٲ���
			pView->Invalidate(FALSE);
		}

	CDialogEx::OnHScroll(nSBCode, nPos, pScrollBar);
	}
}