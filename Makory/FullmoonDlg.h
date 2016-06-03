#pragma once
#include "afxcmn.h"
#include "afxwin.h"



// CEdittapCtrl ��ȭ �����Դϴ�.

class CFullmoonDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CFullmoonDlg)

public:
	CFullmoonDlg(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CFullmoonDlg();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_FULLMOON };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	CSliderCtrl mFullmoonRedS;
	CSliderCtrl mFullmoonGreenS;
	CSliderCtrl mFullmoonBlueS;
	CSliderCtrl mFullmoonVSlider;
	CSliderCtrl mFullmoonHSlider;
	CEdit mFullmoonRedValue;
	CEdit mFullmoonGreenValue;
	CEdit mFullmoonBlueValue;
	CEdit mFullmoonVEdit;
	CEdit mFullmoonHEdit;

	afx_msg void OnEnUpdateFullmoonRedValue();
	afx_msg void OnEnUpdateFullmoonGreenValue();
	afx_msg void OnEnUpdateFullmoonBlueValue();
	afx_msg void OnEnUpdateFullmoonVEdit();
	afx_msg void OnEnUpdateFullmoonHEdit();

	double dpos;
};
