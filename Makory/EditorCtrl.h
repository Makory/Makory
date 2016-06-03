#pragma once
#include "afxcmn.h"

#include "TemplateCtrl.h"
#include "ImageCtrl.h"
#include "EdittapCtrl.h"
#include "DigBalloon.h"
// CEditorCtrl ��ȭ �����Դϴ�.

class CEditorCtrl : public CDialogEx
{
	DECLARE_DYNAMIC(CEditorCtrl)

public:
	CEditorCtrl(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CEditorCtrl();

	void ChangeEditDlgTo(int templateType);
	void ChangeImgDlgTo(int imgType);

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_DIALOG_EDITOR };

	CTemplateCtrl  m_ctrlTemplate;
	CImageCtrl     m_ctrlImage;
	CEdittapCtrl    m_ctrlEdittap;
	CWnd*          m_pwndShow;

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.
		
	DECLARE_MESSAGE_MAP()
public:
	CTabCtrl m_ctrTab;
	int Select;
	virtual BOOL OnInitDialog();
	CRect Rect;
	
	afx_msg void OnTcnSelchangeTab(NMHDR *pNMHDR, LRESULT *pResult);
};
