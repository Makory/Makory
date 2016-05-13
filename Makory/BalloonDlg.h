#pragma once
#include "afxcmn.h"
#include "afxwin.h"
#include "HotAirBalloon.h"


// CEdittapCtrl ��ȭ �����Դϴ�.

class CBalloonDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CBalloonDlg)

public:
	CBalloonDlg(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CBalloonDlg();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_BALLOON };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.
	DECLARE_MESSAGE_MAP()

public:
	virtual BOOL OnInitDialog();
	void ChangeColorTo(int balloonredcolor);
	

	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	
	double fpos;
	double fgpos;
	afx_msg void OnEnChangeBalloonRedValue();
	CSliderCtrl mBalloonRedS;
	CEdit mBalloonRedValue;

	CSliderCtrl mBalloonGreenS;
	CEdit mBalloonGreenValue;


	CSliderCtrl mBalloonBlueS;
	CEdit mBalloonBlueValue;

	CSliderCtrl mBalloonVSlider;
	CSliderCtrl mBalloonHSlider;

	CEdit mBalloonVEdit;
	CEdit mBalloonHEdit;
};