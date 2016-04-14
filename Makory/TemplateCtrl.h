#pragma once
#include "afxcmn.h"
#include "imagelist.h"


// CTemplateCtrl 대화 상자입니다.

class CTemplateCtrl : public CDialogEx
{
	DECLARE_DYNAMIC(CTemplateCtrl)

public:
	CTemplateCtrl(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CTemplateCtrl();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_TEMPLATE_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	CTreeCtrl m_ctrlTree;
	virtual BOOL OnInitDialog();
	afx_msg void OnDblclkTree(NMHDR *pNMHDR, LRESULT *pResult);
	int SelectTemplate2;
	std::string GetTemplatePathFor(std::string index) const;
	CImagelist m_ctrlImagelist;

};
