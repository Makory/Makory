#pragma once
#include "afxwin.h"
#include "imagelist.h"


// CImageCtrl ��ȭ �����Դϴ�.

class CImageCtrl : public CDialogEx
{
	DECLARE_DYNAMIC(CImageCtrl)

public:
	CImageCtrl(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CImageCtrl();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_IMAGE_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	CButton m_ctrlLoadbutton;
	afx_msg void OnBnClickedLoadButton();
	afx_msg void OnLvnItemchangedImageList(NMHDR *pNMHDR, LRESULT *pResult);
	CImagelist m_ctrlImagelist;
	afx_msg void OnDblclkImagelist(NMHDR *pNMHDR, LRESULT *pResult);
};
