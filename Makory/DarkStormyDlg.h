#pragma once
#include "afxcmn.h"
#include "afxwin.h"



// CEdittapCtrl ��ȭ �����Դϴ�.

class CDarkStormyDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CDarkStormyDlg)

public:
	CDarkStormyDlg(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CDarkStormyDlg();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_DARKSTORMY };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	CSliderCtrl mDarkStormyRedS;
	CSliderCtrl mDarkStormyGreenS;
	CSliderCtrl mDarkStormyBlueS;
	CSliderCtrl mDarkStormyVSlider;
	CSliderCtrl mDarkStormyHSlider;
	CEdit mDarkStormyRedValue;
	CEdit mDarkStormyGreenValue;
	CEdit mDarkStormyBlueValue;
	CEdit mDarkStormyVEdit;
	CEdit mDarkStormyHEdit;



	double dpos;


	afx_msg void OnEnUpdateDarkStormyRedValue();
	afx_msg void OnEnUpdateDarkStormyGreenValue();
	afx_msg void OnEnUpdateDarkStormyBlueValue();
	afx_msg void OnEnUpdateDarkStormyVEdit();
	afx_msg void OnEnUpdateDarkStormyHEdit();
};
