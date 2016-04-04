#pragma once
#include "afxwin.h"
#include "imagelist.h"


// CImageCtrl 대화 상자입니다.

class CImageCtrl : public CDialogEx
{
	DECLARE_DYNAMIC(CImageCtrl)

public:
	CImageCtrl(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CImageCtrl();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_IMAGE_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	CButton m_ctrlLoadbutton;
	afx_msg void OnBnClickedLoadButton();
	afx_msg void OnLvnItemchangedImageList(NMHDR *pNMHDR, LRESULT *pResult);
	CImagelist m_ctrlImagelist;
	afx_msg void OnDblclkImagelist(NMHDR *pNMHDR, LRESULT *pResult);
};
