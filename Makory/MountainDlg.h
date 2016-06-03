#pragma once
#include "afxcmn.h"
#include "afxwin.h"



// CEdittapCtrl 대화 상자입니다.

class CMountainDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CMountainDlg)

public:
	CMountainDlg(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CMountainDlg();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_MOUNTAIN };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	CSliderCtrl mMountainRedS;
	CSliderCtrl mMountainGreenS;
	CSliderCtrl mMountainBlueS;
	CSliderCtrl mMountainVSlider;
	CSliderCtrl mMountainHSlider;
	CEdit mMountainRedValue;
	CEdit mMountainGreenValue;
	CEdit mMountainBlueValue;
	CEdit mMountainVEdit;
	CEdit mMountainHEdit;

	
	afx_msg void OnEnUpdateMountainRedValue();
	afx_msg void OnEnUpdateMountainGreenValue();
	afx_msg void OnEnUpdateMountainBlueValue();
	afx_msg void OnEnUpdateMountainVEdit();
	afx_msg void OnEnUpdateMountainHEdit();


	double dpos;
};
