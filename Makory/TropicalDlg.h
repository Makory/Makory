#pragma once
#include "afxcmn.h"
#include "afxwin.h"



// CEdittapCtrl ��ȭ �����Դϴ�.

class CTropicalDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CTropicalDlg)

public:
	CTropicalDlg(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CTropicalDlg();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_TROPICAL };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnEnChangeEdit1();
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	CSliderCtrl mTropicalRedS;
	CSliderCtrl mTropicalGreenS;
	CSliderCtrl mTropicalBlueS;
	CSliderCtrl mTropicalVSlider;
	CSliderCtrl mTropicalHSlider;
	CEdit mTropicalRedValue;
	CEdit mTropicalGreenValue;
	CEdit mTropicalBlueValue;
	CEdit mTropicalVEdit;
	CEdit mTropicalHEdit;
	double dpos;
};
