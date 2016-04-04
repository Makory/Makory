#pragma once
#include "timelinectrl.h"


// CTimelinePane

class CTimelinePane : public CDockablePane
{
	DECLARE_DYNAMIC(CTimelinePane)

public:
	CTimelinePane();
	virtual ~CTimelinePane();

protected:
	DECLARE_MESSAGE_MAP()
public:
	CTimelineCtrl m_ctrlTimeline;
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnSize(UINT nType, int cx, int cy);
};


