// EdittapCtrl.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "Makory.h"
#include "CloudsDlg.h"
#include "afxdialogex.h"
#include "HotAirBalloon.h"
#include "MainFrm.h"
#include "MakoryDoc.h"
#include "MakoryView.h"

// CCloudslg ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CCloudsDlg, CDialogEx)

CCloudsDlg::CCloudsDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CCloudsDlg::IDD, pParent)
{

}

CCloudsDlg::~CCloudsDlg()
{
}

void CCloudsDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_CLOUDS_RED_SLIDER, mCloudsRedS);
	DDX_Control(pDX, IDC_CLOUDS_GREEN_SLIDER, mCloudsGreenS);
	DDX_Control(pDX, IDC_CLOUDS_BLUE_SLIDER, mCloudsBlueS);
	DDX_Control(pDX, IDC_CLOUDS_VSCROLL, mCloudsVSlider);
	DDX_Control(pDX, IDC_CLOUDS_HSCROOL, mCloudsHSlider);
	DDX_Control(pDX, IDC_CLOUDS_RED_VALUE, mCloudsRedValue);
	DDX_Control(pDX, IDC_CLOUDS_GREEN_VALUE, mCloudsGreenValue);
	DDX_Control(pDX, IDC_CLOUDS_BLUE_VALUE, mCloudsBlueValue);
	DDX_Control(pDX, IDC_CLOUDS_V_VALUE, mCloudsVEdit);
	DDX_Control(pDX, IDC_CLOUDS_H_VALUE, mCloudsHEdit);
}


BEGIN_MESSAGE_MAP(CCloudsDlg, CDialogEx)
	ON_EN_CHANGE(IDC_EDIT1, &CCloudsDlg::OnEnChangeEdit1)
	ON_WM_HSCROLL()
END_MESSAGE_MAP()


// CCloudslg �޽��� ó�����Դϴ�.

BOOL CCloudsDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
	//red �����̴�
	mCloudsRedS.SetPos(255);//�����̴� ó�� ��ġ
	mCloudsRedS.SetRange(0, 255); //�����̴� ���� 0 ~ 100���� ��.
	mCloudsRedS.SetPageSize(10); //�����̴��� Ŭ������ �� �����̴� ����. 
	mCloudsRedValue.SetWindowTextA("255");//red edit�ڽ� �ʱⰪ

	//green �����̴�
	mCloudsGreenS.SetPos(0);//�����̴� ó�� ��ġ
	mCloudsGreenS.SetRange(0, 255); //�����̴� ���� 0 ~ 100���� ��.
	mCloudsGreenS.SetPageSize(10);  //�����̴��� Ŭ������ �� �����̴� ����
	mCloudsGreenValue.SetWindowTextA("0");//green edit�ڽ� �ʱⰪ

	//blue �����̴�
	mCloudsBlueS.SetPos(0);//�����̴� ó�� ��ġ
	mCloudsBlueS.SetRange(0, 255); //�����̴� ���� 0 ~ 100���� ��.
	mCloudsBlueS.SetPageSize(10);  //�����̴��� Ŭ������ �� �����̴� ����
	mCloudsBlueValue.SetWindowTextA("0");//blue edit�ڽ� �ʱⰪ

	//���������̴�
	mCloudsVSlider.SetPos(50);//�����̴� ó�� ��ġ
	mCloudsVSlider.SetRange(0, 100); //�����̴� ���� 0 ~ 100���� ��.
	mCloudsVSlider.SetPageSize(1);  //�����̴��� Ŭ������ �� �����̴� ����
	mCloudsVEdit.SetWindowTextA("0");//v edit�ڽ� �ʱⰪ

	//���򽽶��̴�
	mCloudsHSlider.SetPos(50);//�����̴� ó�� ��ġ
	mCloudsHSlider.SetRange(0, 100); //�����̴� ���� 0 ~ 100���� ��.
	mCloudsHSlider.SetPageSize(1);  //�����̴��� Ŭ������ �� �����̴� ����
	mCloudsHEdit.SetWindowTextA("0");//h edit�ڽ� �ʱⰪ


	return TRUE;  // return TRUE unless you set the focus to a control
	// ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
}
void CCloudsDlg::OnEnChangeEdit1()
{
	// TODO:  RICHEDIT ��Ʈ���� ���, �� ��Ʈ����
	// CDialogEx::OnInitDialog() �Լ��� ������ 
	//�ϰ� ����ũ�� OR �����Ͽ� ������ ENM_CHANGE �÷��׸� �����Ͽ� CRichEditCtrl().SetEventMask()�� ȣ������ ������
	// �� �˸� �޽����� ������ �ʽ��ϴ�.

	// TODO:  ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}


void CCloudsDlg::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	CMainFrame* pFrame = (CMainFrame*)AfxGetMainWnd();				//Viewȣ��
	CMakoryView* pView = (CMakoryView*)pFrame->GetActiveView();		//Viewȣ��

	if(pScrollBar)
	{
		// � �����̴����� �˻�
		//red slider�� �������� ���
		if(pScrollBar == (CScrollBar*)&mCloudsRedS)//balloon red slider�ΰ��
		{
			
			// �����̴��� ��ġ�� �˻��Ѵ�.
 			int npos = mCloudsRedS.GetPos(); //�����̴� ��ġ ����
			CString str;
			str.Format(_T("%d"), npos); //����ȯ
			mCloudsRedValue.SetWindowTextA(str); //edit �ڽ��� �����̴� �� ��

			dpos = (double)npos * 0.00392156; //�����̴��� �Ҽ����� ����� �ȵ�

			pView->HotAirBalloon.cloudsred=dpos;//ǳ�� ���������� �ٲ���
			pView->Invalidate(FALSE);
		}

		//green�����̴� �������� ���
		else if(pScrollBar == (CScrollBar*)&mCloudsGreenS)//balloon green slider�ΰ��
		{
			
			// �����̴��� ��ġ�� �˻��Ѵ�.
 			int npos = mCloudsGreenS.GetPos(); //�����̴� ��ġ ����
			CString str;
			str.Format(_T("%d"), npos); //����ȯ
			mCloudsGreenValue.SetWindowTextA(str);// edit �ڽ��� �����̴� �� ��

			dpos = (double)npos * 0.00392156; //�����̴��� �Ҽ����� ����� �ȵ�

			pView->HotAirBalloon.cloudsgreen=dpos; //ǳ�� ������� �ٲ���
			pView->Invalidate(FALSE);
		}

	

		//blue �����̴� �������� ���
		else if(pScrollBar == (CScrollBar*)&mCloudsBlueS)//balloon green slider�ΰ��
		{

			// �����̴��� ��ġ�� �˻��Ѵ�.
			int npos = mCloudsBlueS.GetPos(); //�����̴� ��ġ ����
			CString str;
			str.Format(_T("%d"), npos); //����ȯ
			mCloudsBlueValue.SetWindowTextA(str); //blue edit �ڽ��� �����̴� �� ��

			dpos = (double)npos * 0.00392156; //�����̴��� �Ҽ����� ����� �ȵ�

			pView->HotAirBalloon.cloudsblue=dpos; //ǳ�� �Ķ������� �ٲ���
			pView->Invalidate(FALSE);
		}

		//���� �����̴� �������� ���
		else if(pScrollBar == (CScrollBar*)&mCloudsVSlider)//���� �����̴��ΰ��
		{

			// �����̴��� ��ġ�� �˻��Ѵ�.
			int npos = mCloudsVSlider.GetPos(); //�����̴� ��ġ ����
			CString str;
			str.Format(_T("%d"), npos-50); //����ȯ
			mCloudsVEdit.SetWindowTextA(str); //edit �ڽ��� �����̴� �� ��

			
			if(npos <= 50){ //�����̴��� 50�����϶�
				dpos = -0.5+((double)npos * 0.01); //�������� �̵� 
			} 
			else if(npos >= 50){  //�����̴��� 50�̻��϶�
				dpos = ((double)npos * 0.01)-0.5; //���������� �̵�
			}

			pView->HotAirBalloon.cloudsy=dpos; //balloony���� �ٲ���
			pView->Invalidate(FALSE);
		}
		//���� �����̴� �������� ���
		else if(pScrollBar == (CScrollBar*)&mCloudsHSlider)//���� �����̴��ΰ��
		{

			// �����̴��� ��ġ�� �˻��Ѵ�.
			int npos = mCloudsHSlider.GetPos(); //�����̴� ��ġ ����
			
			CString str;
			str.Format(_T("%d"), npos-50); //����ȯ
			mCloudsHEdit.SetWindowTextA(str); //edit �ڽ��� �����̴� �� ��

			if(npos <= 50){ //�����̴��� 50�����϶�
				dpos = -0.5+((double)npos * 0.01); //������ �̵� 
				
			} 
			else if(npos >= 50){  //�����̴��� 50�̻��϶�
				dpos = ((double)npos * 0.01)-0.5; //�Ʒ������� �̵�
			}

			pView->HotAirBalloon.cloudsx=dpos; //balloonx���� �ٲ���
			pView->Invalidate(FALSE);
		}

	CDialogEx::OnHScroll(nSBCode, nPos, pScrollBar);
	}
}