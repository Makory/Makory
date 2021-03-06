
// MainFrm.h : CMainFrame 클래스의 인터페이스
//

#pragma once
#include "editorpane.h"
#include "timelinepane.h"
#include "BalloonDlg.h"
#include "HotAirBalloon.h"
#include "AVIGenerator.h"

class CMainFrame : public CFrameWndEx
{
	
protected: // serialization에서만 만들어집니다.
	DECLARE_DYNCREATE(CMainFrame)

// 특성입니다.
public:
	CMainFrame();

	CEditorCtrl* GetEditorCtrl();
	void ConnectTimelineToMainView();

	void FinishRecording();

public:

// 재정의입니다.
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual BOOL LoadFrame(UINT nIDResource, DWORD dwDefaultStyle = WS_OVERLAPPEDWINDOW | FWS_ADDTOTITLE, CWnd* pParentWnd = NULL, CCreateContext* pContext = NULL);

// 구현입니다.
public:
	virtual ~CMainFrame();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:  // 컨트롤 모음이 포함된 멤버입니다.
	CMFCMenuBar       m_wndMenuBar;
	CMFCToolBar       m_wndToolBar;
	CMFCStatusBar     m_wndStatusBar;
	CMFCToolBarImages m_UserImages;

// 생성된 메시지 맵 함수
protected:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnViewCustomize();
	afx_msg LRESULT OnToolbarCreateNew(WPARAM wp, LPARAM lp);
	DECLARE_MESSAGE_MAP();

	LPBITMAPINFOHEADER lpbih;
	BYTE* bmBits;	
	HRESULT hr;

public:
	CAVIGenerator AviGen;
	//CProgressBar Bar;
	CEditorPane m_paneEditor;
	CTimelinePane m_paneTimeline;
	
	afx_msg void OnExportToVideo();
	afx_msg void ReadingPixel();
};


