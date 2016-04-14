#pragma once
#include "afxcmn.h"
#include "imagelist.h"


// CTemplateCtrl ��ȭ �����Դϴ�.

class CTemplateCtrl : public CDialogEx
{
	DECLARE_DYNAMIC(CTemplateCtrl)

public:
	CTemplateCtrl(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CTemplateCtrl();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_TEMPLATE_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	CTreeCtrl m_ctrlTree;
	virtual BOOL OnInitDialog();
	afx_msg void OnDblclkTree(NMHDR *pNMHDR, LRESULT *pResult);
	int SelectTemplate2;
	std::string GetTemplatePathFor(std::string index) const;
	CImagelist m_ctrlImagelist;

};
