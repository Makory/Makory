// TimelineCtrl.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "Makory.h"
#include "TimelineCtrl.h"
#include "afxdialogex.h"


// CTimelineCtrl 대화 상자입니다.

IMPLEMENT_DYNAMIC(CTimelineCtrl, CDialogEx)

CTimelineCtrl::CTimelineCtrl(CWnd* pParent /*=NULL*/)
	: CDialogEx(CTimelineCtrl::IDD, pParent)
{
}

CTimelineCtrl::~CTimelineCtrl()
{
}

void CTimelineCtrl::AddImage(const std::string& path)
{
	m_ctrlImageTimeline.AddThumbnail(path);
}

void CTimelineCtrl::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CTimelineCtrl, CDialogEx)
	ON_WM_CREATE()
	ON_WM_SIZE()
	ON_LBN_SELCHANGE(IDC_LIST1, &CTimelineCtrl::OnLbnSelchangeList1)
END_MESSAGE_MAP()


int CTimelineCtrl::OnCreate(CREATESTRUCT* createStruct)
{
	CDialogEx::OnCreate(createStruct);
	
	theApp.RegisterTimelineWnd(this);

	return 0;
}

BOOL CTimelineCtrl::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	CRect clientRect;
	GetClientRect(&clientRect);

	clientRect.DeflateRect(10, 10);
	m_ctrlImageTimeline.Create(
		nullptr,
		nullptr,
		WS_CHILD | WS_VISIBLE | WS_HSCROLL | WS_CLIPCHILDREN | WS_CLIPSIBLINGS,
		clientRect,
		this,
		1);
		
	return TRUE;
}


void CTimelineCtrl::OnLbnSelchangeList1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}

void CTimelineCtrl::OnSize(UINT type, int cx, int cy)
{
	if (m_ctrlImageTimeline.GetSafeHwnd())
	{
		m_ctrlImageTimeline.SetWindowPos(
			nullptr,
			5, 5, cx - 10, cy - 10, SWP_NOZORDER | SWP_NOACTIVATE);
	}
}