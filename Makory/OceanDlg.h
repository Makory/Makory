#pragma once
#include "afxwin.h"
#include "afxcmn.h"


// CFishDlg 대화 상자입니다.

class COceanDlg : public CDialogEx
{
	DECLARE_DYNAMIC(COceanDlg)

public:
	COceanDlg(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~COceanDlg();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_OCEAN };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	
	double fpos;

	CSliderCtrl mFishRedS;
	CEdit mFishRedValue;
	CSliderCtrl mFishGreenS;
	CEdit mFishGreenValue;
	CSliderCtrl mFishBlueS;
	CEdit mFishBlueValue;
	CSliderCtrl mFishVSlider;
	CSliderCtrl mFishHSlider;
	CEdit mFishVEdit;
	CEdit mFishHEdit;
	CSliderCtrl mFishScaleSlider;
	CEdit mFishScaleEdit;
	
	afx_msg void OnEnUpdateFishRedValue();
	afx_msg void OnEnUpdateFishGreenValue();
	afx_msg void OnEnUpdateFishBlueValue();
	afx_msg void OnEnUpdateFishVEdit();
	afx_msg void OnEnUpdateFishHEdit();
	afx_msg void OnEnUpdateFishScaleEdit();

	afx_msg void OnEnUpdateStarRedValue();
	afx_msg void OnEnUpdateStarGreenValue();
	afx_msg void OnEnUpdateStarBlueValue();
	afx_msg void OnEnUpdateStarVEdit();
	afx_msg void OnEnUpdateStarHEdit();
	afx_msg void OnEnUpdateStarScaleEdit();

	afx_msg void OnEnUpdateSFishRedValue();
	afx_msg void OnEnUpdateSFishGreenValue();
	afx_msg void OnEnUpdateSFishBlueValue();
	afx_msg void OnEnUpdateSFishVEdit();
	afx_msg void OnEnUpdateSFishHEdit();
	afx_msg void OnEnUpdateSFishScaleEdit();

	afx_msg void OnEnUpdateSFishRedValue2();
	afx_msg void OnEnUpdateSFishGreenValue2();
	afx_msg void OnEnUpdateSFishBlueValue2();
	afx_msg void OnEnUpdateSFishVEdit2();
	afx_msg void OnEnUpdateSFishHEdit2();
	afx_msg void OnEnUpdateSFishScaleEdit2();


	afx_msg void OnCbnSelchangeOceanCombo();
	CComboBox mOceanCombo;

	CSliderCtrl mStarRedS;
	CSliderCtrl mStarGreenS;
	CSliderCtrl mStarBlueS;
	CSliderCtrl mStarScaleS;
	CSliderCtrl mStarVSlider;
	CSliderCtrl mStarHSlider;
	CEdit mStarRedValue;
	CEdit mStarGreenValue;
	CEdit mStarBlueValue;
	CEdit mStarScaleEdit;
	CEdit mStarVEdit;
	CEdit mStarHEdit;

	CSliderCtrl mSFishRedS;
	CSliderCtrl mSFishGreenS;
	CSliderCtrl mSFishBlueS;
	CSliderCtrl mSFishScaleS;
	CSliderCtrl mSFishVSlider;
	CSliderCtrl mSFishHSlider;
	CEdit mSFishRedValue;
	CEdit mSFishGreenValue;
	CEdit mSFishBlueValue;
	CEdit mSFishScaleEdit;
	CEdit mSFishVEdit;
	CEdit mSFishHEdit;
	CSliderCtrl mSFishRedS2;
	CSliderCtrl mSFishGreenS2;
	CSliderCtrl mSFishBlueS2;
	CSliderCtrl mSFishScaleS2;
	CSliderCtrl mSFishVSlider2;
	CSliderCtrl mSFishHSlider2;
	CEdit mSFishRedValue2;
	CEdit mSFishGreenValue2;
	CEdit mSFishBlueValue2;
	CEdit mSFishScaleEdit2;
	CEdit mSFishVEdit2;
	CEdit mSFishHEdit2;
};
