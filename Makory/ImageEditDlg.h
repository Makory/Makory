#pragma once
#include "afxcmn.h"
#include "afxwin.h"



// CEdittapCtrl ��ȭ �����Դϴ�.

class CImageEditDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CImageEditDlg)

public:
	CImageEditDlg(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CImageEditDlg();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_IMAGEEDIT };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	double fpos;
	afx_msg void OnEnChangeEdit1();
	CSliderCtrl mImageScaleSlider;
	CEdit mImageScaleValue;
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);

};
