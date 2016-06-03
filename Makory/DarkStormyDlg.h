#pragma once
#include "afxcmn.h"
#include "afxwin.h"



// CEdittapCtrl 대화 상자입니다.

class CDarkStormyDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CDarkStormyDlg)

public:
	CDarkStormyDlg(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CDarkStormyDlg();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_DARKSTORMY };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

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
