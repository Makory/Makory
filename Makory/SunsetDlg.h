#pragma once
#include "afxcmn.h"
#include "afxwin.h"



// CEdittapCtrl ��ȭ �����Դϴ�.

class CSunsetDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CSunsetDlg)

public:
	CSunsetDlg(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CSunsetDlg();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_SUNSET };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnEnChangeEdit1();
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	CSliderCtrl mSunsetRedS;
	CSliderCtrl mSunsetGreenS;
	CSliderCtrl mSunsetBlueS;
	CSliderCtrl mSunsetVSlider;
	CSliderCtrl mSunsetHSlider;
	CEdit mSunsetRedValue;
	CEdit mSunsetGreenValue;
	CEdit mSunsetBlueValue;
	CEdit mSunsetVEdit;
	CEdit mSunsetHEdit;
	double dpos;
};
