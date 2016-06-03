// WaveDlg.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "Makory.h"
#include "WaveDlg.h"
#include "afxdialogex.h"
#include "Ocean.h"
#include "MainFrm.h"
#include "MakoryDoc.h"
#include "MakoryView.h"

// CWaveDlg ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CWaveDlg, CDialogEx)

	CWaveDlg::CWaveDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CWaveDlg::IDD, pParent)
{

}

CWaveDlg::~CWaveDlg()
{
}

void CWaveDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_WAVE_SLIDER, mWaveS);
	DDX_Control(pDX, IDC_WAVE_VALUE, mWaveEdit);
}


BEGIN_MESSAGE_MAP(CWaveDlg, CDialogEx)
	ON_WM_HSCROLL()
	ON_EN_UPDATE(IDC_WAVE_VALUE, &CWaveDlg::OnEnUpdateWaveValue)
	
END_MESSAGE_MAP()


// CWaveDlg �޽��� ó�����Դϴ�.
BOOL CWaveDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	// TODO:  ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
	//red �����̴�
	mWaveS.SetPos(0);//�����̴� ó�� ��ġ
	mWaveS.SetRange(0,10); //�����̴� ���� 0 ~ 100���� ��.
	mWaveS.SetPageSize(1); //�����̴��� Ŭ������ �� �����̴� ����. 
	mWaveEdit.SetWindowTextA("0");//red edit�ڽ� �ʱⰪ

	return TRUE;  // return TRUE unless you set the focus to a control
	// ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
}

void CWaveDlg::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	CMainFrame* pFrame = (CMainFrame*)AfxGetMainWnd();				//Viewȣ��
	CMakoryView* pView = (CMakoryView*)pFrame->GetActiveView();		//Viewȣ��

	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	if(pScrollBar)
	{
		// � �����̴����� �˻�
		//red slider�� �������� ���
		if(pScrollBar == (CScrollBar*)&mWaveS)//film red slider�ΰ��
		{
			// �����̴��� ��ġ�� �˻��Ѵ�.
			int npos = mWaveS.GetPos(); //�����̴� ��ġ ����
			CString str;
			str.Format(_T("%d"), npos-5); //����ȯ
			mWaveEdit.SetWindowTextA(str); //edit �ڽ��� �����̴� �� ��

			if(npos <= 5){ //�����̴��� 50�����϶�
				fpos = -0.5+((double)npos * 0.1); //�������� �̵� 
			} 
			else if(npos >= 5){  //�����̴��� 50�̻��϶�
				fpos = ((double)npos * 0.1)-0.5; //���������� �̵�
			}

			pView->Ocean.wavey=fpos; 
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
void CWaveDlg::OnEnUpdateWaveValue()
{

	// TODO:  ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	CMainFrame* pFrame = (CMainFrame*)AfxGetMainWnd();            //Viewȣ��
	CMakoryView* pView = (CMakoryView*)pFrame->GetActiveView();      //Viewȣ��

	if(UpdateData(TRUE)){

	int ipos;
		double dpos;
		CString String;

		mWaveEdit.GetWindowTextA(String);

		ipos =_ttoi(String)+5;

		mWaveS.SetPos(ipos);

	    if (ipos<0){
			ipos = 0;
			dpos = -0.5+((double)ipos * 0.1); //�������� �̵� 
			pView->Ocean.wavey=dpos; 
			pView->Invalidate(FALSE);
		}
		else if(ipos<10){
		if(ipos <= 5){ //�����̴��� 50�����϶�
			dpos = -0.5+((double)ipos * 0.1); //�������� �̵� 
			mWaveS.SetPos(ipos);
		
		} 
		else if(ipos >= 5){  //�����̴��� 50�̻��϶�
			dpos = ((double)ipos * 0.1)-0.5; //���������� �̵�
			mWaveS.SetPos(ipos);
		}
		pView->Ocean.wavey=dpos; 
		pView->Invalidate(FALSE);
		}
		else if(ipos>10){
			ipos = 10;
			dpos = ((double)ipos * 0.1)-0.5; 
			pView->Ocean.wavey=dpos; 
			pView->Invalidate(FALSE);

		}

	}
}