
// MainFrm.cpp : CMainFrame Ŭ������ ����
//

#include "stdafx.h"
#include "Makory.h"
#include "MainFrm.h"
#include "MakoryView.h"
#include "ImageTimelineCtrl.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
CDockablePane m_Panes[2];
// CMainFrame

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWndEx)

const int  iMaxUserToolbars = 10;
const UINT uiFirstUserToolBarId = AFX_IDW_CONTROLBAR_FIRST + 40;
const UINT uiLastUserToolBarId = uiFirstUserToolBarId + iMaxUserToolbars - 1;

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWndEx)
	ON_WM_CREATE()
	ON_COMMAND(ID_VIEW_CUSTOMIZE, &CMainFrame::OnViewCustomize)
	ON_REGISTERED_MESSAGE(AFX_WM_CREATETOOLBAR, &CMainFrame::OnToolbarCreateNew)
	ON_COMMAND(ID_EXPORT_TO_VIDEO, &CMainFrame::OnExportToVideo)
END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_SEPARATOR,           // ���� �� ǥ�ñ�
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};

// CMainFrame ����/�Ҹ�

CMainFrame::CMainFrame()
{
	// TODO: ���⿡ ��� �ʱ�ȭ �ڵ带 �߰��մϴ�.
	// retreiving size of image
	lpbih=AviGen.GetBitmapHeader();
	//bmBits=new BYTE[lpbih->biSizeImage];
	bmBits = nullptr;

}

CMainFrame::~CMainFrame()
{
	if (bmBits)
	{
		delete[] bmBits;
	}
}

CEditorCtrl* CMainFrame::GetEditorCtrl()
{
	return m_paneEditor.GetEditorCtrl();
}

void CMainFrame::ConnectTimelineToMainView()
{
	CMakoryView* pView = (CMakoryView*)GetActiveView();		//Viewȣ��
	pView->ImageTimeline = m_paneTimeline.GetTimelineCtrl();
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWndEx::OnCreate(lpCreateStruct) == -1)
		return -1;

	BOOL bNameValid;

	if (!m_wndMenuBar.Create(this))
	{
		TRACE0("�޴� ������ ������ ���߽��ϴ�.\n");
		return -1;      // ������ ���߽��ϴ�.
	}

	m_wndMenuBar.SetPaneStyle(m_wndMenuBar.GetPaneStyle() | CBRS_SIZE_DYNAMIC | CBRS_TOOLTIPS | CBRS_FLYBY);

	// �޴� ������ Ȱ��ȭ�ص� ��Ŀ���� �̵����� �ʰ� �մϴ�.
	CMFCPopupMenu::SetForceMenuFocus(FALSE);

	if (!m_wndToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_TOP | CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC) ||
		!m_wndToolBar.LoadToolBar(theApp.m_bHiColorIcons ? IDR_MAINFRAME_256 : IDR_MAINFRAME))
	{
		TRACE0("���� ������ ������ ���߽��ϴ�.\n");
		return -1;      // ������ ���߽��ϴ�.
	}

	CString strToolBarName;
	bNameValid = strToolBarName.LoadString(IDS_TOOLBAR_STANDARD);
	ASSERT(bNameValid);
	m_wndToolBar.SetWindowText(strToolBarName);

	CString strCustomize;
	bNameValid = strCustomize.LoadString(IDS_TOOLBAR_CUSTOMIZE);
	ASSERT(bNameValid);
	m_wndToolBar.EnableCustomizeButton(TRUE, ID_VIEW_CUSTOMIZE, strCustomize);

	// ����� ���� ���� ���� �۾��� ����մϴ�.
	InitUserToolbars(NULL, uiFirstUserToolBarId, uiLastUserToolBarId);

	if (!m_wndStatusBar.Create(this))
	{
		TRACE0("���� ǥ������ ������ ���߽��ϴ�.\n");
		return -1;      // ������ ���߽��ϴ�.
	}
	m_wndStatusBar.SetIndicators(indicators, sizeof(indicators)/sizeof(UINT));

	// TODO: ���� ���� �� �޴� ������ ��ŷ�� �� ���� �Ϸ��� �� �ټ� ���� �����Ͻʽÿ�.
	m_wndMenuBar.EnableDocking(CBRS_ALIGN_ANY);
	m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);
	EnableDocking(CBRS_ALIGN_ANY);
	DockPane(&m_wndMenuBar);
	DockPane(&m_wndToolBar);


	// Visual Studio 2005 ��Ÿ�� ��ŷ â ������ Ȱ��ȭ�մϴ�.
	CDockingManager::SetDockingMode(DT_SMART);
	// Visual Studio 2005 ��Ÿ�� ��ŷ â �ڵ� ���� ������ Ȱ��ȭ�մϴ�.
	EnableAutoHidePanes(CBRS_ALIGN_ANY);

	// ���� ���� �� ��ŷ â �޴� �ٲٱ⸦ Ȱ��ȭ�մϴ�.
	EnablePaneMenu(TRUE, ID_VIEW_CUSTOMIZE, strCustomize, ID_VIEW_TOOLBAR);

	// ����(<Alt> Ű�� ���� ä ����) ���� ���� ����� ������ Ȱ��ȭ�մϴ�.
	CMFCToolBar::EnableQuickCustomization();

	if (CMFCToolBar::GetUserImages() == NULL)
	{
		// ����� ���� ���� ���� �̹����� �ε��մϴ�.
		if (m_UserImages.Load(_T(".\\UserImages.bmp")))
		{
			CMFCToolBar::SetUserImages(&m_UserImages);
		}
	}

	// �޴� ���� ������ Ȱ��ȭ�մϴ�(���� �ֱٿ� ����� ���).
	// TODO: ������� �⺻ ����� �����Ͽ� �� Ǯ�ٿ� �޴��� �ϳ� �̻��� �⺻ ����� ���Խ�ŵ�ϴ�.
	CList<UINT, UINT> lstBasicCommands;

	lstBasicCommands.AddTail(ID_FILE_NEW);
	lstBasicCommands.AddTail(ID_FILE_OPEN);
	lstBasicCommands.AddTail(ID_FILE_SAVE);
	lstBasicCommands.AddTail(ID_FILE_PRINT);
	lstBasicCommands.AddTail(ID_APP_EXIT);
	lstBasicCommands.AddTail(ID_EDIT_CUT);
	lstBasicCommands.AddTail(ID_EDIT_PASTE);
	lstBasicCommands.AddTail(ID_EDIT_UNDO);
	lstBasicCommands.AddTail(ID_APP_ABOUT);
	lstBasicCommands.AddTail(ID_VIEW_STATUS_BAR);
	lstBasicCommands.AddTail(ID_VIEW_TOOLBAR);

	CMFCToolBar::SetBasicCommands(lstBasicCommands);

	//��ŷ
	//EDITOR
	if (!m_paneEditor.Create(_T("EDITOR"), this, CRect(0, 0, 200, 100), TRUE, 1005,
		WS_CHILD | WS_VISIBLE | WS_CLIPSIBLINGS |
		WS_CLIPCHILDREN | CBRS_RIGHT | CBRS_FLOAT_MULTI))
	{return FALSE;}

	//TIMELINE
	if (!m_paneTimeline.Create(_T("TIMELINE"), this, CRect(0, 0, 200, 100), TRUE, 1001,
		WS_CHILD | WS_VISIBLE | WS_CLIPSIBLINGS |
		WS_CLIPCHILDREN | CBRS_BOTTOM | CBRS_FLOAT_MULTI))
	{return FALSE;}

	m_paneEditor.EnableDocking(CBRS_ALIGN_ANY);
	m_paneTimeline.EnableDocking(CBRS_ALIGN_ANY);
	DockPane(&m_paneEditor);	// BOTTOM TIMELINE
	DockPane(&m_paneTimeline);	// LEFT EDITOR

	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWndEx::PreCreateWindow(cs) )
		return FALSE;
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return TRUE;
}

// CMainFrame ����

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CFrameWndEx::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CFrameWndEx::Dump(dc);
}
#endif //_DEBUG


// CMainFrame �޽��� ó����

void CMainFrame::OnViewCustomize()
{
	CMFCToolBarsCustomizeDialog* pDlgCust = new CMFCToolBarsCustomizeDialog(this, TRUE /* �޴��� �˻��մϴ�. */);
	pDlgCust->EnableUserDefinedToolbars();
	pDlgCust->Create();
}

LRESULT CMainFrame::OnToolbarCreateNew(WPARAM wp,LPARAM lp)
{
	LRESULT lres = CFrameWndEx::OnToolbarCreateNew(wp,lp);
	if (lres == 0)
	{
		return 0;
	}

	CMFCToolBar* pUserToolbar = (CMFCToolBar*)lres;
	ASSERT_VALID(pUserToolbar);

	BOOL bNameValid;
	CString strCustomize;
	bNameValid = strCustomize.LoadString(IDS_TOOLBAR_CUSTOMIZE);
	ASSERT(bNameValid);

	pUserToolbar->EnableCustomizeButton(TRUE, ID_VIEW_CUSTOMIZE, strCustomize);
	return lres;
}

BOOL CMainFrame::LoadFrame(UINT nIDResource, DWORD dwDefaultStyle, CWnd* pParentWnd, CCreateContext* pContext) 
{
	// �⺻ Ŭ������ ���� �۾��� �����մϴ�.

	if (!CFrameWndEx::LoadFrame(nIDResource, dwDefaultStyle, pParentWnd, pContext))
	{
		return FALSE;
	}


	// ��� ����� ���� ������ ����� ���� ���߸� Ȱ��ȭ�մϴ�.
	BOOL bNameValid;
	CString strCustomize;
	bNameValid = strCustomize.LoadString(IDS_TOOLBAR_CUSTOMIZE);
	ASSERT(bNameValid);

	for (int i = 0; i < iMaxUserToolbars; i ++)
	{
		CMFCToolBar* pUserToolbar = GetUserToolBarByIndex(i);
		if (pUserToolbar != NULL)
		{
			pUserToolbar->EnableCustomizeButton(TRUE, ID_VIEW_CUSTOMIZE, strCustomize);
		}
	}

	return TRUE;
}



void CMainFrame::OnExportToVideo()
{
	CMakoryView* pView = (CMakoryView*)GetActiveView();
	CImageTimelineCtrl & Timeline = m_paneTimeline.m_ctrlTimeline.m_ctrlImageTimeline;
	
	Timeline.InitiateRecording();

	BeginWaitCursor();

	// set 30fps
	AviGen.SetRate(30);
	
	// give info about bitmap
	AviGen.SetBitmapHeader(pView);		
	if (bmBits)
	{
		delete[] bmBits;
	}
	bmBits = new BYTE[lpbih->biWidth * lpbih->biHeight * 3];

	// set filename, extension ".avi" is appended if necessary
	AviGen.SetFileName(_T("Video"));
	
	// allocating memory

	hr=AviGen.InitEngine();
	if (hr==S_FALSE)
	{
			//AfxMessageBox( AviGen.GetLastErrorMessage());
			// releasing engine and memory
			AviGen.ReleaseEngine();
			//delete[] bmBits;

			glReadBuffer(GL_FRONT);

			EndWaitCursor();
	}
	else
	{
	
		// reading back buffer
	//glReadBuffer(GL_BACK);
	//for(i=0;i<nFrames;i++)
	//{
		// render frame
		Timeline.OnKeyDown(32, 1, 57);		//spacebar
	//}
	}

	pView->ExportNum=1;
}

void CMainFrame::FinishRecording()
{
	AviGen.ReleaseEngine();
	
	CMakoryView* pView = (CMakoryView*)GetActiveView();
	pView->ExportNum=0;

	EndWaitCursor();
}

void CMainFrame::ReadingPixel()
{
	//CImageTimelineCtrl & Timeline = m_paneTimeline.m_ctrlTimeline.m_ctrlImageTimeline;
		// render frame
		//Timeline.OnKeyDown(32, 1, 57);		//spacebar
		
		// Copy from OpenGL to buffer
		//bmBits = new unsigned char[lpbih->biWidth * lpbih->biHeight * 3];
		glReadPixels(0,0,lpbih->biWidth,lpbih->biHeight,GL_BGR_EXT,GL_UNSIGNED_BYTE,bmBits); 
		// send to avi engine
		hr=AviGen.AddFrame(bmBits);		//�ߴ�
		if (FAILED(hr))
		{
			AfxMessageBox( AviGen.GetLastErrorMessage());
			// releasing engine and memory
			AviGen.ReleaseEngine();
			//delete[] bmBits;

			glReadBuffer(GL_FRONT);

			EndWaitCursor();
		}
		//delete[] bmBits;
}
