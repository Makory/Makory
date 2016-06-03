#pragma once
#include "afxcmn.h"

#include "TemplateCtrl.h"
#include "ImageCtrl.h"
#include "EdittapCtrl.h"
#include "DigBalloon.h"
// CEditorCtrl 대화 상자입니다.

class CEditorCtrl : public CDialogEx
{
	DECLARE_DYNAMIC(CEditorCtrl)

public:
	CEditorCtrl(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CEditorCtrl();

	void ChangeEditDlgTo(int templateType);
	void ChangeImgDlgTo(int imgType);

// 대화 상자 데이터입니다.
	enum { IDD = IDD_DIALOG_EDITOR };

	CTemplateCtrl  m_ctrlTemplate;
	CImageCtrl     m_ctrlImage;
	CEdittapCtrl    m_ctrlEdittap;
	CWnd*          m_pwndShow;

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.
		
	DECLARE_MESSAGE_MAP()
public:
	CTabCtrl m_ctrTab;
	int Select;
	virtual BOOL OnInitDialog();
	CRect Rect;
	
	afx_msg void OnTcnSelchangeTab(NMHDR *pNMHDR, LRESULT *pResult);
};
