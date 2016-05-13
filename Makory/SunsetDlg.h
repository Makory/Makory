#pragma once
#include "afxcmn.h"
#include "afxwin.h"



// CEdittapCtrl 대화 상자입니다.

class CSunsetDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CSunsetDlg)

public:
	CSunsetDlg(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CSunsetDlg();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_SUNSET };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

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
