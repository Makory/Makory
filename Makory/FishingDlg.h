#pragma once
#include "afxcmn.h"
#include "afxwin.h"



// CEdittapCtrl ��ȭ �����Դϴ�.

class CFishingDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CFishingDlg)

public:
	CFishingDlg(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CFishingDlg();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_FISHING };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();

	
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	
	double fpos;

	CSliderCtrl mBoatRedS;
	CSliderCtrl mBoatGreenS;
	CSliderCtrl mBoatBlueS;
	CSliderCtrl mFishingRedS;
	CSliderCtrl mFishingGreenS;
	CSliderCtrl mFishingBlueS;
	CSliderCtrl mFishingPRedS;
	CSliderCtrl mFishingPGreenS;
	CSliderCtrl mFishingPBlueS;
	CEdit mBoatRedValue;
	CEdit mBoatGreenValue;
	CEdit mBoatBlueValue;
	CEdit mFishingRedValue;
	CEdit mFishingGreenValue;
	CEdit mFishingBlueValue;



	CEdit mFishingPRedValue;
	CEdit mFishingPGreenValue;
	CEdit mFishingPBlueValue;
	CSliderCtrl mLBoatRedS;
	CSliderCtrl mLBoatGreenS;
	CSliderCtrl mLBoatBlueS;
	CEdit mLBoatRedValue;
	CEdit mLBoatGreenValue;
	CEdit mLBoatBlueValue;
	CSliderCtrl mRBoatRedS;
	CSliderCtrl mRBoatGreenS;
	CSliderCtrl mRBoatBlueS;
	CEdit mRBoatRedValue;
	CEdit mRBoatGreenValue;
	CEdit mRBoatBlueValue;
	CComboBox mFishingCombo;


	
	afx_msg void OnEnUpdateBoatRedValue();
	afx_msg void OnEnUpdateBoatGreenValue();
	afx_msg void OnEnUpdateBoatBlueValue();
	afx_msg void OnEnUpdateLBoatRedValue();
	afx_msg void OnEnUpdateLBoatGreenValue();
	afx_msg void OnEnUpdateLBoatBlueValue();
	
	afx_msg void OnEnUpdateRBoatRedValue();
	afx_msg void OnEnUpdateRBoatGreenValue();
	afx_msg void OnEnUpdateRBoatBlueValue();

	
	
	afx_msg void OnEnUpdateFishingRedValue();
	afx_msg void OnEnUpdateFishingGreenValue();
	afx_msg void OnEnUpdateFishingBlueValue();

	afx_msg void OnEnUpdateFishingPRedValue();
	afx_msg void OnEnUpdateFishingPGreenValue();
	afx_msg void OnEnUpdateFishingPBlueValue();

	afx_msg void OnEnUpdateFishingVEdit();
	afx_msg void OnEnUpdateFishingHEdit();
	afx_msg void OnEnUpdateFishingScaleEdit();

	afx_msg void OnCbnSelchangeOceanCombo();

	CSliderCtrl mFishingVSlider;
	CSliderCtrl mFishingHSlider;
	CSliderCtrl mFishingScaleS;
	CEdit mFishingScaleEdit;
	CEdit mFishingVEdit;
	CEdit mFishingHEdit;
};
