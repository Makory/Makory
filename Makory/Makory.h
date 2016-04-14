
// Makory.h : Makory ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.
#include "TimelineCtrl.h"

// CMakoryApp:
// �� Ŭ������ ������ ���ؼ��� Makory.cpp�� �����Ͻʽÿ�.
//

class CMakoryApp : public CWinAppEx
{
public:
	CMakoryApp();

	void RegisterTimelineWnd(CTimelineCtrl* timelineWnd);
	CTimelineCtrl* GetTimelineWnd() const;

// �������Դϴ�.
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// �����Դϴ�.
	BOOL  m_bHiColorIcons;


	virtual void PreLoadState();
	virtual void LoadCustomState();
	virtual void SaveCustomState();

	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()

private:
	CTimelineCtrl* mTimelineWnd;
};

extern CMakoryApp theApp;
