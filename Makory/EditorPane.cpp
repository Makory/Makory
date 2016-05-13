// EditorPane.cpp : ���� �����Դϴ�.
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



// CEditorPane �޽��� ó�����Դϴ�.




int CEditorPane::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CDockablePane::OnCreate(lpCreateStruct) == -1)
		return -1;

	if(!m_ctrlEditor.Create(IDD_DIALOG_EDITOR,this)){
		TRACE0("Ű�е� �����츦 ������ ���߽��ϴ�.\n");
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
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
}
