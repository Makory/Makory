#pragma once
#include "afxcmn.h"
#include "afxwin.h"



// CEdittapCtrl 대화 상자입니다.

class CFullmoonDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CFullmoonDlg)

public:
	CFullmoonDlg(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CFullmoonDlg();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_FULLMOON };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnEnChangeEdit1();
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	CSliderCtrl mFullmoonRedS;
	CSliderCtrl mFullmoonGreenS;
	CSliderCtrl mFullmoonBlueS;
	CSliderCtrl mFullmoonVSlider;
	CSliderCtrl mFullmoonHSlider;
	CEdit mFullmoonRedValue;
	CEdit mFullmoonGreenValue;
	CEdit mFullmoonBlueValue;
	CEdit mFullmoonVEdit;
	CEdit mFullmoonHEdit;
	double dpos;
};
