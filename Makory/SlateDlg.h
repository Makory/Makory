#pragma once
#include "afxwin.h"


// CSlateDlg 대화 상자입니다.

class CSlateDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CSlateDlg)

public:
	CSlateDlg(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CSlateDlg();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_SLATE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	void ChangeScaleTo(int balloonscale);
	
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	
	double fpos;

	CSliderCtrl mSlateRedS;
	CEdit mSlateRedValue;

	CSliderCtrl mSlateGreenS;
	CEdit mSlateGreenValue;


	CSliderCtrl mSlateBlueS;
	CEdit mSlateBlueValue;

	CSliderCtrl mSlateVSlider;
	CSliderCtrl mSlateHSlider;

	CEdit mSlateVEdit;
	CEdit mSlateHEdit;

	CSliderCtrl mSlateScaleSlider;
	CEdit mSlateScaleEdit;
	
	CSliderCtrl mSlateRedS2;
	CEdit mSlateRedValue2;

	CSliderCtrl mSlateGreenS2;
	CEdit mSlateGreenValue2;


	CSliderCtrl mSlateBlueS2;
	CEdit mSlateBlueValue2;

	afx_msg void OnEnUpdateSlateRedValue();
	afx_msg void OnEnUpdateSlateGreenValue();
	afx_msg void OnEnUpdateSlateBlueValue();
	afx_msg void OnEnUpdateSlateVEdit();
	afx_msg void OnEnUpdateSlateHEdit();
	afx_msg void OnEnUpdateSlateScaleEdit();
	
	afx_msg void OnCbnSelchangeSlateCombo();
	CComboBox mSlateCombo;

	afx_msg void OnEnUpdateSlateRedValue2();
	afx_msg void OnEnUpdateSlateGreenValue2();
	afx_msg void OnEnUpdateSlateBlueValue2();
};
