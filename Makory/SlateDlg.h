#pragma once
#include "afxwin.h"


// CSlateDlg ��ȭ �����Դϴ�.

class CSlateDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CSlateDlg)

public:
	CSlateDlg(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CSlateDlg();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_SLATE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

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
