#pragma once
#include "afxcmn.h"
#include "afxwin.h"
#include "HotAirBalloon.h"


// CEdittapCtrl 대화 상자입니다.

class CBalloonDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CBalloonDlg)

public:
	CBalloonDlg(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CBalloonDlg();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_BALLOON };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.
	DECLARE_MESSAGE_MAP()

public:
	virtual BOOL OnInitDialog();
	void ChangeScaleTo(int balloonscale);
	
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	
	double fpos;

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
	
	afx_msg void OnEnUpdateBalloonRedValue();
	afx_msg void OnEnUpdateBalloonGreenValue();
	afx_msg void OnEnUpdateBalloonBlueValue();
	afx_msg void OnEnUpdateBalloonVEdit();
	afx_msg void OnEnUpdateBalloonHEdit();

};
