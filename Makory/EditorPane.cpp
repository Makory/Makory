// EditorPane.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "Makory.h"
#include "EditorPane.h"


// CEditorPane

IMPLEMENT_DYNAMIC(CEditorPane, CDockablePane)

CEditorPane::CEditorPane()
{

}

CEditorPane::~CEditorPane()
{
}

CEditorCtrl* CEditorPane::GetEditorCtrl()
{
	return &m_ctrlEditor;
}



BEGIN_MESSAGE_MAP(CEditorPane, CDockablePane)
	ON_WM_CREATE()
	ON_WM_SIZE()
END_MESSAGE_MAP()



// CEditorPane 메시지 처리기입니다.




int CEditorPane::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CDockablePane::OnCreate(lpCreateStruct) == -1)
		return -1;

	if(!m_ctrlEditor.Create(IDD_DIALOG_EDITOR,this)){
		TRACE0("키패드 윈도우를 만들지 못했습니다.\n");
		return -1;

	}
	m_ctrlEditor.ShowWindow(SW_SHOW);

	return 0;
}


void CEditorPane::OnSize(UINT nType, int cx, int cy)
{
	CDockablePane::OnSize(nType, cx, cy);
	if(m_ctrlEditor.GetSafeHwnd()){
		m_ctrlEditor.MoveWindow(0,0,cx,cy);
		m_ctrlEditor.SetFocus();

	}
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
}
