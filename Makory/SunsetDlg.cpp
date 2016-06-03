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
	ON_EN_UPDATE(IDC_SUNSET_RED_VALUE, &CSunsetDlg::OnEnUpdateSunsetRedValue)
	ON_EN_UPDATE(IDC_SUNSET_GREEN_VALUE, &CSunsetDlg::OnEnUpdateSunsetGreenValue)
	ON_EN_UPDATE(IDC_SUNSET_BLUE_VALUE, &CSunsetDlg::OnEnUpdateSunsetBlueValue)
	ON_EN_UPDATE(IDC_SUNSET_V_VALUE, &CSunsetDlg::OnEnUpdateSunsetVEdit)
	ON_EN_UPDATE(IDC_SUNSET_H_VALUE, &CSunsetDlg::OnEnUpdateSunsetHEdit)
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
				dpos = 2*(-0.5+((double)npos * 0.01)); //�������� �̵� 
			} 
			else if(npos >= 50){  //�����̴��� 50�̻��϶�
				dpos = 2*(((double)npos * 0.01)-0.5); //���������� �̵�
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
				dpos = 5*(-0.5+((double)npos * 0.01)); //������ �̵� 
				
			} 
			else if(npos >= 50){  //�����̴��� 50�̻��϶�
				dpos = 5*(((double)npos * 0.01)-0.5); //�Ʒ������� �̵�
			}

			pView->HotAirBalloon.sunsetx=dpos; //balloonx���� �ٲ���
			pView->Invalidate(FALSE);
		}

	CDialogEx::OnHScroll(nSBCode, nPos, pScrollBar);
	}
}

//RED edit
void CSunsetDlg::OnEnUpdateSunsetRedValue()
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

		mSunsetRedValue.GetWindowTextA(String);
		ipos = _ttoi(String);
		mSunsetRedS.SetPos(ipos);
		dpos = (double)ipos * 0.00392156; //�����̴��� �Ҽ����� ����� �ȵ�

		pView->HotAirBalloon.sunsetred=dpos;//ǳ�� ���������� �ٲ���
		pView->Invalidate(FALSE);
	}
}

//green edit
void CSunsetDlg::OnEnUpdateSunsetGreenValue()
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

		mSunsetGreenValue.GetWindowTextA(String);
		ipos = _ttoi(String);
		mSunsetGreenS.SetPos(ipos);
		dpos = (double)ipos * 0.00392156; //�����̴��� �Ҽ����� ����� �ȵ�
		pView->HotAirBalloon.sunsetgreen=dpos;//ǳ�� ���������� �ٲ���

		pView->Invalidate(FALSE);
	}
}

//blue edit
void CSunsetDlg::OnEnUpdateSunsetBlueValue()
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

		mSunsetBlueValue.GetWindowTextA(String);
		ipos = _ttoi(String);
		mSunsetBlueS.SetPos(ipos);
		dpos = (double)ipos * 0.00392156; //�����̴��� �Ҽ����� ����� �ȵ�
		pView->HotAirBalloon.sunsetblue=dpos;//ǳ�� ���������� �ٲ���

		pView->Invalidate(FALSE);
	}
}

//���� edit
void CSunsetDlg::OnEnUpdateSunsetHEdit()
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

		mSunsetHEdit.GetWindowTextA(String);

		ipos = _ttoi(String)+50;
		mSunsetHSlider.SetPos(ipos);

		if(ipos <= 50){ //�����̴��� 50�����϶�
		
			dpos = 5*(-0.5+((double)ipos * 0.01)); //�������� �̵� 
			
		} 
		else if(ipos >= 50){  //�����̴��� 50�̻��϶�
			dpos = 5*(((double)ipos * 0.01)-0.5); //���������� �̵�
		}

		pView->HotAirBalloon.sunsetx=dpos; //balloony���� �ٲ���
		pView->Invalidate(FALSE);
	}


}
//���� Edit
void CSunsetDlg::OnEnUpdateSunsetVEdit()
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

		mSunsetVEdit.GetWindowTextA(String);

		ipos = _ttoi(String)+50;

		mSunsetVSlider.SetPos(ipos);

		if(ipos <= 50){ //�����̴��� 50�����϶�
		
			dpos = 2*(-0.5+((double)ipos * 0.01)); //�������� �̵� 
			
		} 
		else if(ipos >= 50){  //�����̴��� 50�̻��϶�
			dpos = 2*(((double)ipos * 0.01)-0.5); //���������� �̵�
		}

		pView->HotAirBalloon.sunsety=dpos; //balloony���� �ٲ���
		pView->Invalidate(FALSE);
	}
	
}

