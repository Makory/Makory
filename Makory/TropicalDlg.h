#pragma once
#include "afxcmn.h"
#include "afxwin.h"



// CEdittapCtrl 대화 상자입니다.

class CTropicalDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CTropicalDlg)

public:
	CTropicalDlg(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CTropicalDlg();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_TROPICAL };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	CSliderCtrl mTropicalRedS;
	CSliderCtrl mTropicalGreenS;
	CSliderCtrl mTropicalBlueS;
	CSliderCtrl mTropicalVSlider;
	CSliderCtrl mTropicalHSlider;
	CEdit mTropicalRedValue;
	CEdit mTropicalGreenValue;
	CEdit mTropicalBlueValue;
	CEdit mTropicalVEdit;
	CEdit mTropicalHEdit;

	afx_msg void OnEnUpdateTropicalRedValue();
	afx_msg void OnEnUpdateTropicalGreenValue();
	afx_msg void OnEnUpdateTropicalBlueValue();
	afx_msg void OnEnUpdateTropicalVEdit();
	afx_msg void OnEnUpdateTropicalHEdit();

	double dpos;
};
