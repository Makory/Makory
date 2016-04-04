#pragma once
#include "editorctrl.h"


// CEditorPane

class CEditorPane : public CDockablePane
{
	DECLARE_DYNAMIC(CEditorPane)

public:
	CEditorPane();
	virtual ~CEditorPane();

protected:
	DECLARE_MESSAGE_MAP()
public:
	CEditorCtrl m_ctrlEditor;
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnSize(UINT nType, int cx, int cy);
};


