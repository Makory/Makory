#pragma once
#include "afxcmn.h"
#include "afxwin.h"



// CEdittapCtrl 대화 상자입니다.

class CCloudsDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CCloudsDlg)

public:
	CCloudsDlg(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CCloudsDlg();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_CLOUDS };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnEnChangeEdit1();
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	CSliderCtrl mCloudsRedS;
	CSliderCtrl mCloudsGreenS;
	CSliderCtrl mCloudsBlueS;
	CSliderCtrl mCloudsVSlider;
	CSliderCtrl mCloudsHSlider;
	CEdit mCloudsRedValue;
	CEdit mCloudsGreenValue;
	CEdit mCloudsBlueValue;
	CEdit mCloudsVEdit;
	CEdit mCloudsHEdit;
	double dpos;
};
