// EdittapCtrl.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "Makory.h"
#include "DarkStormyDlg.h"
#include "afxdialogex.h"
#include "HotAirBalloon.h"
#include "MainFrm.h"
#include "MakoryDoc.h"
#include "MakoryView.h"

// CDarkStormyDlg ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CDarkStormyDlg, CDialogEx)

CDarkStormyDlg::CDarkStormyDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDarkStormyDlg::IDD, pParent)
{

}

CDarkStormyDlg::~CDarkStormyDlg()
{
}

void CDarkStormyDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_DARKSTORMY_RED_SLIDER, mDarkStormyRedS);
	DDX_Control(pDX, IDC_DARKSTORMY_GREEN_SLIDER, mDarkStormyGreenS);
	DDX_Control(pDX, IDC_DARKSTORMY_BLUE_SLIDER, mDarkStormyBlueS);
	DDX_Control(pDX, IDC_DARKSTORMY_VSCROLL, mDarkStormyVSlider);
	DDX_Control(pDX, IDC_DARKSTORMY_HSCROOL, mDarkStormyHSlider);
	DDX_Control(pDX, IDC_DARKSTORMY_RED_VALUE, mDarkStormyRedValue);
	DDX_Control(pDX, IDC_DARKSTORMY_GREEN_VALUE, mDarkStormyGreenValue);
	DDX_Control(pDX, IDC_DARKSTORMY_BLUE_VALUE, mDarkStormyBlueValue);
	DDX_Control(pDX, IDC_DARKSTORMY_V_VALUE, mDarkStormyVEdit);
	DDX_Control(pDX, IDC_DARKSTORMY_H_VALUE, mDarkStormyHEdit);
}


BEGIN_MESSAGE_MAP(CDarkStormyDlg, CDialogEx)
	ON_WM_HSCROLL()
	ON_EN_UPDATE(IDC_DARKSTORMY_RED_VALUE, &CDarkStormyDlg::OnEnUpdateDarkStormyRedValue)
	ON_EN_UPDATE(IDC_DARKSTORMY_GREEN_VALUE, &CDarkStormyDlg::OnEnUpdateDarkStormyGreenValue)
	ON_EN_UPDATE(IDC_DARKSTORMY_BLUE_VALUE, &CDarkStormyDlg::OnEnUpdateDarkStormyBlueValue)
	ON_EN_UPDATE(IDC_DARKSTORMY_V_VALUE, &CDarkStormyDlg::OnEnUpdateDarkStormyVEdit)
	ON_EN_UPDATE(IDC_DARKSTORMY_H_VALUE, &CDarkStormyDlg::OnEnUpdateDarkStormyHEdit)
END_MESSAGE_MAP()


// CDarkStormyDlg �޽��� ó�����Դϴ�.

BOOL CDarkStormyDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
	//red �����̴�
	mDarkStormyRedS.SetPos(255);//�����̴� ó�� ��ġ
	mDarkStormyRedS.SetRange(0, 255); //�����̴� ���� 0 ~ 100���� ��.
	mDarkStormyRedS.SetPageSize(10); //�����̴��� Ŭ������ �� �����̴� ����. 
	mDarkStormyRedValue.SetWindowTextA("255");//red edit�ڽ� �ʱⰪ

	//green �����̴�
	mDarkStormyGreenS.SetPos(0);//�����̴� ó�� ��ġ
	mDarkStormyGreenS.SetRange(0, 255); //�����̴� ���� 0 ~ 100���� ��.
	mDarkStormyGreenS.SetPageSize(10);  //�����̴��� Ŭ������ �� �����̴� ����
	mDarkStormyGreenValue.SetWindowTextA("0");//green edit�ڽ� �ʱⰪ

	//blue �����̴�
	mDarkStormyBlueS.SetPos(0);//�����̴� ó�� ��ġ
	mDarkStormyBlueS.SetRange(0, 255); //�����̴� ���� 0 ~ 100���� ��.
	mDarkStormyBlueS.SetPageSize(10);  //�����̴��� Ŭ������ �� �����̴� ����
	mDarkStormyBlueValue.SetWindowTextA("0");//blue edit�ڽ� �ʱⰪ

	//���������̴�
	mDarkStormyVSlider.SetPos(50);//�����̴� ó�� ��ġ
	mDarkStormyVSlider.SetRange(0, 100); //�����̴� ���� 0 ~ 100���� ��.
	mDarkStormyVSlider.SetPageSize(1);  //�����̴��� Ŭ������ �� �����̴� ����
	mDarkStormyVEdit.SetWindowTextA("0");//v edit�ڽ� �ʱⰪ

	//���򽽶��̴�
	mDarkStormyHSlider.SetPos(50);//�����̴� ó�� ��ġ
	mDarkStormyHSlider.SetRange(0, 100); //�����̴� ���� 0 ~ 100���� ��.
	mDarkStormyHSlider.SetPageSize(1);  //�����̴��� Ŭ������ �� �����̴� ����
	mDarkStormyHEdit.SetWindowTextA("0");//h edit�ڽ� �ʱⰪ


	return TRUE;  // return TRUE unless you set the focus to a control
	// ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
}

void CDarkStormyDlg::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	CMainFrame* pFrame = (CMainFrame*)AfxGetMainWnd();				//Viewȣ��
	CMakoryView* pView = (CMakoryView*)pFrame->GetActiveView();		//Viewȣ��

	if(pScrollBar)
	{
		// � �����̴����� �˻�
		//red slider�� �������� ���
		if(pScrollBar == (CScrollBar*)&mDarkStormyRedS)//balloon red slider�ΰ��
		{
			
			// �����̴��� ��ġ�� �˻��Ѵ�.
 			int npos = mDarkStormyRedS.GetPos(); //�����̴� ��ġ ����
			CString str;
			str.Format(_T("%d"), npos); //����ȯ
			mDarkStormyRedValue.SetWindowTextA(str); //edit �ڽ��� �����̴� �� ��

			dpos = (double)npos * 0.00392156; //�����̴��� �Ҽ����� ����� �ȵ�

			pView->HotAirBalloon.darkstormyred=dpos;//ǳ�� ���������� �ٲ���
			pView->Invalidate(FALSE);
		}

		//green�����̴� �������� ���
		else if(pScrollBar == (CScrollBar*)&mDarkStormyGreenS)//balloon green slider�ΰ��
		{
			
			// �����̴��� ��ġ�� �˻��Ѵ�.
 			int npos = mDarkStormyGreenS.GetPos(); //�����̴� ��ġ ����
			CString str;
			str.Format(_T("%d"), npos); //����ȯ
			mDarkStormyGreenValue.SetWindowTextA(str);// edit �ڽ��� �����̴� �� ��

			dpos = (double)npos * 0.00392156; //�����̴��� �Ҽ����� ����� �ȵ�

			pView->HotAirBalloon.darkstormygreen=dpos; //ǳ�� ������� �ٲ���
			pView->Invalidate(FALSE);
		}

	

		//blue �����̴� �������� ���
		else if(pScrollBar == (CScrollBar*)&mDarkStormyBlueS)//balloon green slider�ΰ��
		{

			// �����̴��� ��ġ�� �˻��Ѵ�.
			int npos = mDarkStormyBlueS.GetPos(); //�����̴� ��ġ ����
			CString str;
			str.Format(_T("%d"), npos); //����ȯ
			mDarkStormyBlueValue.SetWindowTextA(str); //blue edit �ڽ��� �����̴� �� ��

			dpos = (double)npos * 0.00392156; //�����̴��� �Ҽ����� ����� �ȵ�

			pView->HotAirBalloon.darkstormyblue=dpos; //ǳ�� �Ķ������� �ٲ���
			pView->Invalidate(FALSE);
		}

		//���� �����̴� �������� ���
		else if(pScrollBar == (CScrollBar*)&mDarkStormyVSlider)//���� �����̴��ΰ��
		{

			// �����̴��� ��ġ�� �˻��Ѵ�.
			int npos = mDarkStormyVSlider.GetPos(); //�����̴� ��ġ ����
			CString str;
			str.Format(_T("%d"), npos-50); //����ȯ
			mDarkStormyVEdit.SetWindowTextA(str); //edit �ڽ��� �����̴� �� ��

			
			if(npos <= 50){ //�����̴��� 50�����϶�
				dpos = 2*(-0.5+((double)npos * 0.01)); //�������� �̵� 
			} 
			else if(npos >= 50){  //�����̴��� 50�̻��϶�
				dpos = 2*(((double)npos * 0.01)-0.5); //���������� �̵�
			}

			pView->HotAirBalloon.darkstormyy=dpos; //balloony���� �ٲ���
			pView->Invalidate(FALSE);
		}
		//���� �����̴� �������� ���
		else if(pScrollBar == (CScrollBar*)&mDarkStormyHSlider)//���� �����̴��ΰ��
		{

			// �����̴��� ��ġ�� �˻��Ѵ�.
			int npos = mDarkStormyHSlider.GetPos(); //�����̴� ��ġ ����
			
			CString str;
			str.Format(_T("%d"), npos-50); //����ȯ
			mDarkStormyHEdit.SetWindowTextA(str); //edit �ڽ��� �����̴� �� ��

			if(npos <= 50){ //�����̴��� 50�����϶�
				dpos = 5*(-0.5+((double)npos * 0.01)); //������ �̵� 
				
			} 
			else if(npos >= 50){  //�����̴��� 50�̻��϶�
				dpos = 5*(((double)npos * 0.01)-0.5); //�Ʒ������� �̵�
			}

			pView->HotAirBalloon.darkstormyx=dpos; //balloonx���� �ٲ���
			pView->Invalidate(FALSE);
		}

	CDialogEx::OnHScroll(nSBCode, nPos, pScrollBar);
	}
}

//RED edit
void CDarkStormyDlg::OnEnUpdateDarkStormyRedValue()
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

		mDarkStormyRedValue.GetWindowTextA(String);
		ipos = _ttoi(String);
		mDarkStormyRedS.SetPos(ipos);
		dpos = (double)ipos * 0.00392156; //�����̴��� �Ҽ����� ����� �ȵ�

		pView->HotAirBalloon.darkstormyred=dpos;//ǳ�� ���������� �ٲ���
		pView->Invalidate(FALSE);
	}
}

//green edit
void CDarkStormyDlg::OnEnUpdateDarkStormyGreenValue()
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

		mDarkStormyGreenValue.GetWindowTextA(String);
		ipos = _ttoi(String);
		mDarkStormyGreenS.SetPos(ipos);
		dpos = (double)ipos * 0.00392156; //�����̴��� �Ҽ����� ����� �ȵ�
		pView->HotAirBalloon.darkstormygreen=dpos;//ǳ�� ���������� �ٲ���

		pView->Invalidate(FALSE);
	}
}

//blue edit
void CDarkStormyDlg::OnEnUpdateDarkStormyBlueValue()
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

		mDarkStormyBlueValue.GetWindowTextA(String);
		ipos = _ttoi(String);
		mDarkStormyBlueS.SetPos(ipos);
		dpos = (double)ipos * 0.00392156; //�����̴��� �Ҽ����� ����� �ȵ�
		pView->HotAirBalloon.darkstormyblue=dpos;//ǳ�� ���������� �ٲ���

		pView->Invalidate(FALSE);
	}
}

//���� edit
void CDarkStormyDlg::OnEnUpdateDarkStormyHEdit()
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

		mDarkStormyHEdit.GetWindowTextA(String);

		ipos = _ttoi(String)+50;
		mDarkStormyHSlider.SetPos(ipos);

		if(ipos <= 50){ //�����̴��� 50�����϶�
		
			dpos = 5*( -0.5+((double)ipos * 0.01)); //�������� �̵� 
			
		} 
		else if(ipos >= 50){  //�����̴��� 50�̻��϶�
			dpos = 5*(((double)ipos * 0.01)-0.5); //���������� �̵�
		}

		pView->HotAirBalloon.darkstormyx=dpos; //balloony���� �ٲ���
		pView->Invalidate(FALSE);
	}


}
//���� Edit
void CDarkStormyDlg::OnEnUpdateDarkStormyVEdit()
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

		mDarkStormyVEdit.GetWindowTextA(String);

		ipos = _ttoi(String)+50;

		mDarkStormyVSlider.SetPos(ipos);

		if(ipos <= 50){ //�����̴��� 50�����϶�
		
			dpos = 2*(-0.5+((double)ipos * 0.01)); //�������� �̵� 
			
		} 
		else if(ipos >= 50){  //�����̴��� 50�̻��϶�
			dpos = 2*(((double)ipos * 0.01)-0.5); //���������� �̵�
		}

		pView->HotAirBalloon.darkstormyy=dpos; //balloony���� �ٲ���
		pView->Invalidate(FALSE);
	}
	
}