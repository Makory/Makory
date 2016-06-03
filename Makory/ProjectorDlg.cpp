// EdittapCtrl.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "Makory.h"
#include "ProjectorDlg.h"
#include "afxdialogex.h"
#include "Film.h"
#include "MainFrm.h"
#include "MakoryDoc.h"
#include "MakoryView.h"

// CProjectorDlg ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CProjectorDlg, CDialogEx)

CProjectorDlg::CProjectorDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CProjectorDlg::IDD, pParent)
{
			
}

CProjectorDlg::~CProjectorDlg()
{
}

void CProjectorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PROJECTOR_RED_SLIDER, mProjectorRedS);
	DDX_Control(pDX, IDC_PROJECTOR_RED_VALUE, mProjectorRedValue);
	DDX_Control(pDX, IDC_PROJECTOR_GREEN_SLIDER, mProjectorGreenS);
	DDX_Control(pDX, IDC_PROJECTOR_GREEN_VALUE, mProjectorGreenValue);
	DDX_Control(pDX, IDC_PROJECTOR_BLUE_SLIDER, mProjectorBlueS);
	DDX_Control(pDX, IDC_PROJECTOR_BLUE_VALUE, mProjectorBlueValue);
	DDX_Control(pDX, IDC_PROJECTOR_VSCROLL, mProjectorVSlider);
	DDX_Control(pDX, IDC_PROJECTOR_HSCROOL, mProjectorHSlider);
	DDX_Control(pDX, IDC_PROJECTOR_V_VALUE, mProjectorVEdit);
	DDX_Control(pDX, IDC_PROJECTOR_H_VALUE, mProjectorHEdit);
	DDX_Control(pDX, IDC_PROJECTOR_SCALE_SLIDER, mProjectorScaleSlider);
	DDX_Control(pDX, IDC_PROJECTOR_SCALE_VALUE, mProjectorScaleEdit);
}


BEGIN_MESSAGE_MAP(CProjectorDlg, CDialogEx)
	ON_WM_HSCROLL()
	ON_EN_UPDATE(IDC_PROJECTOR_RED_VALUE, &CProjectorDlg::OnEnUpdateProjectorRedValue)
	ON_EN_UPDATE(IDC_PROJECTOR_GREEN_VALUE, &CProjectorDlg::OnEnUpdateProjectorGreenValue)
	ON_EN_UPDATE(IDC_PROJECTOR_BLUE_VALUE, &CProjectorDlg::OnEnUpdateProjectorBlueValue)
	ON_EN_UPDATE(IDC_PROJECTOR_V_VALUE, &CProjectorDlg::OnEnUpdateProjectorVEdit)
	ON_EN_UPDATE(IDC_PROJECTOR_H_VALUE, &CProjectorDlg::OnEnUpdateProjectorHEdit)
	ON_EN_UPDATE(IDC_PROJECTOR_SCALE_VALUE, &CProjectorDlg::OnEnUpdateProjectorScaleEdit)
END_MESSAGE_MAP()


// CProjectorDlg �޽��� ó�����Դϴ�.

BOOL CProjectorDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
	//red �����̴�
	mProjectorRedS.SetPos(255);//�����̴� ó�� ��ġ
	mProjectorRedS.SetRange(0, 255); //�����̴� ���� 0 ~ 100���� ��.
	mProjectorRedS.SetPageSize(10); //�����̴��� Ŭ������ �� �����̴� ����. 
	mProjectorRedValue.SetWindowTextA("255");//red edit�ڽ� �ʱⰪ

	//green �����̴�
	mProjectorGreenS.SetPos(255);//�����̴� ó�� ��ġ
	mProjectorGreenS.SetRange(0, 255); //�����̴� ���� 0 ~ 100���� ��.
	mProjectorGreenS.SetPageSize(10);  //�����̴��� Ŭ������ �� �����̴� ����
	mProjectorGreenValue.SetWindowTextA("255");//green edit�ڽ� �ʱⰪ

	//blue �����̴�
	mProjectorBlueS.SetPos(255);//�����̴� ó�� ��ġ
	mProjectorBlueS.SetRange(0, 255); //�����̴� ���� 0 ~ 100���� ��.
	mProjectorBlueS.SetPageSize(10);  //�����̴��� Ŭ������ �� �����̴� ����
	mProjectorBlueValue.SetWindowTextA("255");//blue edit�ڽ� �ʱⰪ

	//���������̴�
	mProjectorVSlider.SetPos(50);//�����̴� ó�� ��ġ
	mProjectorVSlider.SetRange(0, 100); //�����̴� ���� 0 ~ 100���� ��.
	mProjectorVSlider.SetPageSize(1);  //�����̴��� Ŭ������ �� �����̴� ����
	mProjectorVEdit.SetWindowTextA("0");//v edit�ڽ� �ʱⰪ

	//���򽽶��̴�
	mProjectorHSlider.SetPos(50);//�����̴� ó�� ��ġ
	mProjectorHSlider.SetRange(0, 100); //�����̴� ���� 0 ~ 100���� ��.
	mProjectorHSlider.SetPageSize(1);  //�����̴��� Ŭ������ �� �����̴� ����
	mProjectorHEdit.SetWindowTextA("0");//h edit�ڽ� �ʱⰪ

	//ũ��
	mProjectorScaleSlider.SetPos(50);//�����̴� ó�� ��ġ
	mProjectorScaleSlider.SetRange(0, 100); //�����̴� ���� 0 ~ 100���� ��.
	mProjectorScaleSlider.SetPageSize(1);  //�����̴��� Ŭ������ �� �����̴� ����
	mProjectorScaleEdit.SetWindowTextA("0");//h edit�ڽ� �ʱⰪ


	return TRUE;  // return TRUE unless you set the focus to a control
	// ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
}

//��� �ʿ������...�ϴ� ������� ���߿� ���ִ°ɷ�..
void CProjectorDlg::ChangeScaleTo(int Projectorscale)
{	/*
	//int Projectorredsliderpos;
	//mProjectorRedS.SetPos(Projectorredcolor); //��� ��ģ���� ȣ���
	Projectorredsliderpos = mProjectorRedS.GetPos();
	CString strredpos;
	strredpos.Format(_T("%d"), Projectorredsliderpos); //����ȯ
	mProjectorRedValue.SetWindowTextA(strredpos);*/
	
}

//�����̴� �������� ��
void CProjectorDlg::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	CMainFrame* pFrame = (CMainFrame*)AfxGetMainWnd();				//Viewȣ��
	CMakoryView* pView = (CMakoryView*)pFrame->GetActiveView();		//Viewȣ��
	
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	if(pScrollBar)
	{
		// � �����̴����� �˻�
		//red slider�� �������� ���
		if(pScrollBar == (CScrollBar*)&mProjectorRedS)//Projector red slider�ΰ��
		{
			
			// �����̴��� ��ġ�� �˻��Ѵ�.
 			int npos = mProjectorRedS.GetPos(); //�����̴� ��ġ ����
			CString str;
			str.Format(_T("%d"), npos); //����ȯ
			mProjectorRedValue.SetWindowTextA(str); //edit �ڽ��� �����̴� �� ��

			fpos = (double)npos * 0.00392156; //�����̴��� �Ҽ����� ����� �ȵ�

			pView->Film.projred=fpos;//ǳ�� ���������� �ٲ���
			pView->Invalidate(FALSE);
		}

		//green�����̴� �������� ���
		else if(pScrollBar == (CScrollBar*)&mProjectorGreenS)//Projector green slider�ΰ��
		{
			
			// �����̴��� ��ġ�� �˻��Ѵ�.
 			int npos = mProjectorGreenS.GetPos(); //�����̴� ��ġ ����
			CString str;
			str.Format(_T("%d"), npos); //����ȯ
			mProjectorGreenValue.SetWindowTextA(str);// edit �ڽ��� �����̴� �� ��

			fpos = (double)npos * 0.00392156; //�����̴��� �Ҽ����� ����� �ȵ�

			pView->Film.projgreen=fpos; //ǳ�� ������� �ٲ���
			pView->Invalidate(FALSE);
		}

	

		//blue �����̴� �������� ���
		else if(pScrollBar == (CScrollBar*)&mProjectorBlueS)//Projector green slider�ΰ��
		{

			// �����̴��� ��ġ�� �˻��Ѵ�.
			int npos = mProjectorBlueS.GetPos(); //�����̴� ��ġ ����
			CString str;
			str.Format(_T("%d"), npos); //����ȯ
			mProjectorBlueValue.SetWindowTextA(str); //blue edit �ڽ��� �����̴� �� ��

			fpos = (double)npos * 0.00392156; //�����̴��� �Ҽ����� ����� �ȵ�

			pView->Film.projblue=fpos; //ǳ�� �Ķ������� �ٲ���
			pView->Invalidate(FALSE);
		}

		//ũ�� �����̴� �������� ���
		else if(pScrollBar == (CScrollBar*)&mProjectorScaleSlider)//���� �����̴��ΰ��
		{

			// �����̴��� ��ġ�� �˻��Ѵ�.
			int npos = mProjectorScaleSlider.GetPos(); //�����̴� ��ġ ����
			CString str;
			str.Format(_T("%d"), npos-50); //����ȯ
			mProjectorScaleEdit.SetWindowTextA(str); //edit �ڽ��� �����̴� �� ��

			
			if(npos <= 50){ //�����̴��� 50�����϶�
				fpos = 2*(-0.5+((double)npos * 0.01)); //�������� �̵� 
			} 
			else if(npos >= 50){  //�����̴��� 50�̻��϶�
				fpos = 2*(((double)npos * 0.01)-0.5); //���������� �̵�
			}

			pView->Film.ProjectorScale=2+fpos; //filmscale���� �ٲ���
			pView->Invalidate(FALSE);
		}
		//���� �����̴� �������� ���
		else if(pScrollBar == (CScrollBar*)&mProjectorVSlider)//���� �����̴��ΰ��
		{

			// �����̴��� ��ġ�� �˻��Ѵ�.
			int npos = mProjectorVSlider.GetPos(); //�����̴� ��ġ ����
			CString str;
			str.Format(_T("%d"), npos-50); //����ȯ
			mProjectorVEdit.SetWindowTextA(str); //edit �ڽ��� �����̴� �� ��

			
			if(npos <= 50){ //�����̴��� 50�����϶�
				fpos = -0.5+((double)npos * 0.01); //�������� �̵� 
			} 
			else if(npos >= 50){  //�����̴��� 50�̻��϶�
				fpos = ((double)npos * 0.01)-0.5; //���������� �̵�
			}

			pView->Film.projy=fpos; //Projectory���� �ٲ���

			pView->Invalidate(FALSE);
		}
		//���� �����̴� �������� ���
		else if(pScrollBar == (CScrollBar*)&mProjectorHSlider)//���� �����̴��ΰ��
		{

			// �����̴��� ��ġ�� �˻��Ѵ�.
			int npos = mProjectorHSlider.GetPos(); //�����̴� ��ġ ����
			
			CString str;
			str.Format(_T("%d"), npos-50); //����ȯ
			mProjectorHEdit.SetWindowTextA(str); //edit �ڽ��� �����̴� �� ��

			if(npos <= 50){ //�����̴��� 50�����϶�
				fpos = -0.5+((double)npos * 0.01); //������ �̵� 
				
			} 
			else if(npos >= 50){  //�����̴��� 50�̻��϶�
				fpos = ((double)npos * 0.01)-0.5; //�Ʒ������� �̵�
			}

			
			pView->Film.projx=fpos;
		
			
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
void CProjectorDlg::OnEnUpdateProjectorRedValue()
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

		mProjectorRedValue.GetWindowTextA(String);
		ipos = _ttoi(String);
		mProjectorRedS.SetPos(ipos);
		dpos = (double)ipos * 0.00392156; //�����̴��� �Ҽ����� ����� �ȵ�

		pView->Film.projred=dpos;//ǳ�� ���������� �ٲ���
		pView->Invalidate(FALSE);
	}
}

//green edit
void CProjectorDlg::OnEnUpdateProjectorGreenValue()
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

		mProjectorGreenValue.GetWindowTextA(String);
		ipos = _ttoi(String);
		mProjectorGreenS.SetPos(ipos);
		dpos = (double)ipos * 0.00392156; //�����̴��� �Ҽ����� ����� �ȵ�
		pView->Film.projgreen=dpos;//ǳ�� ���������� �ٲ���

		pView->Invalidate(FALSE);
	}
}

//blue edit
void CProjectorDlg::OnEnUpdateProjectorBlueValue()
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

		mProjectorBlueValue.GetWindowTextA(String);
		ipos = _ttoi(String);
		mProjectorBlueS.SetPos(ipos);
		dpos = (double)ipos * 0.00392156; //�����̴��� �Ҽ����� ����� �ȵ�
		pView->Film.projblue=dpos;//ǳ�� ���������� �ٲ���

		pView->Invalidate(FALSE);
	}
}

//���� edit
void CProjectorDlg::OnEnUpdateProjectorHEdit()
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

		mProjectorHEdit.GetWindowTextA(String);

		ipos = _ttoi(String)+50;
		mProjectorHSlider.SetPos(ipos);

		if(ipos <= 50){ //�����̴��� 50�����϶�
		
			dpos = -0.5+((double)ipos * 0.01); //�������� �̵� 
			
		} 
		else if(ipos >= 50){  //�����̴��� 50�̻��϶�
			dpos = ((double)ipos * 0.01)-0.5; //���������� �̵�
		}

		pView->Film.projx=dpos;
		pView->Invalidate(FALSE);
	}
}

//���� Edit
void CProjectorDlg::OnEnUpdateProjectorVEdit()
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

		mProjectorVEdit.GetWindowTextA(String);

		ipos =_ttoi(String)+50;

		mProjectorVSlider.SetPos(ipos);

		if(ipos <= 50){ //�����̴��� 50�����϶�
		
			dpos = -0.5+((double)ipos * 0.01); //�������� �̵� 
			
		} 
		else if(ipos >= 50){  //�����̴��� 50�̻��϶�
			dpos = ((double)ipos * 0.01)-0.5; //���������� �̵�
		}

		pView->Film.projy=dpos; //Projectory���� �ٲ���
		pView->Invalidate(FALSE);
	}
}

//ũ�� edit
void CProjectorDlg::OnEnUpdateProjectorScaleEdit()
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

		mProjectorScaleEdit.GetWindowTextA(String);

		ipos = _ttoi(String)+50;
		mProjectorScaleSlider.SetPos(ipos);
		if (ipos<0){
			ipos = 0;
			dpos = 2*(-0.5+((double)ipos * 0.01)); //�������� �̵� 
			pView->Film.ProjectorScale=2+dpos; //filmy���� �ٲ���
			pView->Invalidate(FALSE);
		}
		else if(ipos<100){
		if(ipos <= 50){ //�����̴��� 50�����϶�
		
			dpos = 2*(-0.5+((double)ipos * 0.01)); //�������� �̵� 
			
		} 
		else if(ipos >= 50){  //�����̴��� 50�̻��϶�
			dpos = 2*(((double)ipos * 0.01)-0.5); //���������� �̵�
		}

		pView->Film.ProjectorScale=2+dpos; //filmy���� �ٲ���
		pView->Invalidate(FALSE);
		}
		else if(ipos>100){
			ipos = 100;
			dpos = 2*(((double)ipos * 0.01)-0.5); //���������� �̵�
			pView->Film.ProjectorScale=2+dpos; //filmy���� �ٲ���
			pView->Invalidate(FALSE);

		}
	}
}