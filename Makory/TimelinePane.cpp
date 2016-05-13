// TimelinePane.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "Makory.h"
#include "TimelinePane.h"


// CTimelinePane

IMPLEMENT_DYNAMIC(CTimelinePane, CDockablePane)

CTimelinePane::CTimelinePane()
{

}

CTimelinePane::~CTimelinePane()
{
}

BEGIN_MESSAGE_MAP(CTimelinePane, CDockablePane)
	ON_WM_CREATE()
	ON_WM_SIZE()
END_MESSAGE_MAP()

CImageTimelineCtrl* CTimelinePane::GetTimelineCtrl()
{
	return m_ctrlTimeline.GetTimelineCtrl();
}

int CTimelinePane::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CDockablePane::OnCreate(lpCreateStruct) == -1)
		return -1;
	if(!m_ctrlTimeline.Create(IDD_DIALOG_TIMELINE,this)){
		TRACE0("키패드 윈도우를 만들지 못했습니다.\n");
		return -1;

	}
	m_ctrlTimeline.ShowWindow(SW_SHOW);
	// TODO:  여기에 특수화된 작성 코드를 추가합니다.

	return 0;
}


void CTimelinePane::OnSize(UINT nType, int cx, int cy)
{
	CDockablePane::OnSize(nType, cx, cy);

	if(m_ctrlTimeline.GetSafeHwnd()){
		m_ctrlTimeline.MoveWindow(0,0,cx,cy);
		m_ctrlTimeline.SetFocus();

	}
}
