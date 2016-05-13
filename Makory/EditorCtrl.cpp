// EditorCtrl.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "Makory.h"
#include "EditorCtrl.h"
#include "afxdialogex.h"
#include "ImageTimelineCtrl.h"
#include "MainFrm.h"
#include "MakoryDoc.h"
#include "MakoryView.h"
// CEditorCtrl 대화 상자입니다.

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


// CEditorCtrl 메시지 처리기입니다.


BOOL CEditorCtrl::OnInitDialog()
{
	CDialogEx::OnInitDialog();


	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	//에디터 텝 이름 설정
	CString    strOne = _T("이미지 선택");
	CString    strTwo = _T("템플릿 선택");
	CString    strThree = _T("편집창");

	
	//에디터 텝 추가 
	//m_ctrTab = 에디터 텝 맴버 변수
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
	// 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
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
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	*pResult = 0;
}
