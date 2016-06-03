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
	ON_EN_UPDATE(IDC_MOUNTAIN_RED_VALUE, &CMountainDlg::OnEnUpdateMountainRedValue)
	ON_EN_UPDATE(IDC_MOUNTAIN_GREEN_VALUE, &CMountainDlg::OnEnUpdateMountainGreenValue)
	ON_EN_UPDATE(IDC_MOUNTAIN_BLUE_VALUE, &CMountainDlg::OnEnUpdateMountainBlueValue)
	ON_EN_UPDATE(IDC_MOUNTAIN_V_VALUE, &CMountainDlg::OnEnUpdateMountainVEdit)
	ON_EN_UPDATE(IDC_MOUNTAIN_H_VALUE, &CMountainDlg::OnEnUpdateMountainHEdit)
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
				dpos = 2*(-0.5+((double)npos * 0.01)); //�������� �̵� 
			} 
			else if(npos >= 50){  //�����̴��� 50�̻��϶�
				dpos = 2*(((double)npos * 0.01)-0.5); //���������� �̵�
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
				dpos = 5*(-0.5+((double)npos * 0.01)); //������ �̵� 
				
			} 
			else if(npos >= 50){  //�����̴��� 50�̻��϶�
				dpos = 5*(((double)npos * 0.01)-0.5); //�Ʒ������� �̵�
			}

			pView->HotAirBalloon.mountx=dpos; //balloonx���� �ٲ���
			pView->Invalidate(FALSE);
		}

	CDialogEx::OnHScroll(nSBCode, nPos, pScrollBar);
	}
}

//RED edit
void CMountainDlg::OnEnUpdateMountainRedValue()
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

		mMountainRedValue.GetWindowTextA(String);
		ipos = _ttoi(String);
		mMountainRedS.SetPos(ipos);
		dpos = (double)ipos * 0.00392156; //�����̴��� �Ҽ����� ����� �ȵ�

		pView->HotAirBalloon.mountred=dpos;//ǳ�� ���������� �ٲ���
		pView->Invalidate(FALSE);
	}
}

//green edit
void CMountainDlg::OnEnUpdateMountainGreenValue()
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

		mMountainGreenValue.GetWindowTextA(String);
		ipos = _ttoi(String);
		mMountainGreenS.SetPos(ipos);
		dpos = (double)ipos * 0.00392156; //�����̴��� �Ҽ����� ����� �ȵ�
		pView->HotAirBalloon.mountgreen=dpos;//ǳ�� ���������� �ٲ���

		pView->Invalidate(FALSE);
	}
}

//blue edit
void CMountainDlg::OnEnUpdateMountainBlueValue()
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

		mMountainBlueValue.GetWindowTextA(String);
		ipos = _ttoi(String);
		mMountainBlueS.SetPos(ipos);
		dpos = (double)ipos * 0.00392156; //�����̴��� �Ҽ����� ����� �ȵ�
		pView->HotAirBalloon.mountblue=dpos;//ǳ�� ���������� �ٲ���

		pView->Invalidate(FALSE);
	}
}

//���� edit
void CMountainDlg::OnEnUpdateMountainHEdit()
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

		mMountainHEdit.GetWindowTextA(String);

		ipos = _ttoi(String)+50;
		mMountainHSlider.SetPos(ipos);

		if(ipos <= 50){ //�����̴��� 50�����϶�
		
			dpos = 5*(-0.5+((double)ipos * 0.01)); //�������� �̵� 
			
		} 
		else if(ipos >= 50){  //�����̴��� 50�̻��϶�
			dpos = 5*(((double)ipos * 0.01)-0.5); //���������� �̵�
		}

		pView->HotAirBalloon.mountx=dpos; //balloony���� �ٲ���
		pView->Invalidate(FALSE);
	}


}
//���� Edit
void CMountainDlg::OnEnUpdateMountainVEdit()
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
		ipos = 0;

		mMountainVEdit.GetWindowTextA(String);

		ipos = _ttoi(String)+50;

		mMountainVSlider.SetPos(ipos);

		if(ipos <= 50){ //�����̴��� 50�����϶�
		
			dpos = 2*(-0.5+((double)ipos * 0.01)); //�������� �̵� 
			
		} 
		else if(ipos >= 50){  //�����̴��� 50�̻��϶�
			dpos = 2*(((double)ipos * 0.01)-0.5); //���������� �̵�
		}

		pView->HotAirBalloon.mounty=dpos; //balloony���� �ٲ���
		pView->Invalidate(FALSE);
	}
	
}