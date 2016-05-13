// EditorCtrl.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "Makory.h"
#include "EditorCtrl.h"
#include "afxdialogex.h"
#include "ImageTimelineCtrl.h"
#include "MainFrm.h"
#include "MakoryDoc.h"
#include "MakoryView.h"
// CEditorCtrl ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CEditorCtrl, CDialogEx)

CEditorCtrl::CEditorCtrl(CWnd* pParent /*=NULL*/)
	: CDialogEx(CEditorCtrl::IDD, pParent)
{
	m_pwndShow = NULL;
}

CEditorCtrl::~CEditorCtrl()
{
}

void CEditorCtrl::ChangeEditDlgTo(int templateType)
{
	m_ctrlEdittap.ChangeContentTo(templateType);
}

void CEditorCtrl::ChangeBalloonDlgTo(int redcolor)
{
	m_ctrlEdittap.ChangeRedColorTo(redcolor);
}

void CEditorCtrl::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TAB, m_ctrTab);
}


BEGIN_MESSAGE_MAP(CEditorCtrl, CDialogEx)
	ON_NOTIFY(TCN_SELCHANGE, IDC_TAB, &CEditorCtrl::OnTcnSelchangeTab)
	END_MESSAGE_MAP()


// CEditorCtrl �޽��� ó�����Դϴ�.


BOOL CEditorCtrl::OnInitDialog()
{
	CDialogEx::OnInitDialog();


	// TODO:  ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
	//������ �� �̸� ����
	CString    strOne = _T("�̹��� ����");
	CString    strTwo = _T("���ø� ����");
	CString    strThree = _T("����â");

	
	//������ �� �߰� 
	//m_ctrTab = ������ �� �ɹ� ����
	m_ctrTab.InsertItem(1, strOne);
	m_ctrTab.InsertItem(2, strTwo);
	m_ctrTab.InsertItem(3, strThree);

	CRect Rect;
	m_ctrTab.GetClientRect(&Rect);

	m_ctrlImage.Create(IDD_IMAGE_DIALOG, &m_ctrTab);
	m_ctrlImage.SetWindowPos(NULL, 5, 25,
		Rect.Width() - 12, Rect.Height() - 33,
		SWP_SHOWWINDOW | SWP_NOZORDER);
	m_pwndShow = &m_ctrlImage;

	m_ctrlTemplate.Create(IDD_TEMPLATE_DIALOG, &m_ctrTab);
	m_ctrlTemplate.SetWindowPos(NULL, 5, 25,    Rect.Width() -12, Rect.Height() - 33,    SWP_NOZORDER); 
	
	m_ctrlEdittap.Create(IDD_EDITTAP_DIALOG, &m_ctrTab);
	

	m_ctrlEdittap.SetWindowPos(NULL, 5, 25,
		Rect.Width() - 12, Rect.Height() - 33,
		SWP_NOZORDER);
	

	return TRUE;  // return TRUE unless you set the focus to a control
	// ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
}


void CEditorCtrl::OnTcnSelchangeTab(NMHDR *pNMHDR, LRESULT *pResult)
{
		if(m_pwndShow != NULL)    {
		m_pwndShow->ShowWindow(SW_HIDE);
		m_pwndShow = NULL;
	}

		int nIndex = m_ctrTab.GetCurSel(); 

		switch(nIndex)    {    case 0:
		m_ctrlImage.ShowWindow(SW_SHOW);
		m_pwndShow = &m_ctrlImage;


		break;
		case 1:
			m_ctrlTemplate.ShowWindow(SW_SHOW);
			m_pwndShow = &m_ctrlTemplate;
			break;
		case 2:
			m_ctrlEdittap.ShowWindow(SW_SHOW);
			m_pwndShow = &m_ctrlEdittap;
			break;
	}
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	*pResult = 0;
}
