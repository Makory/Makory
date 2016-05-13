#pragma once
#include "afxcmn.h"
#include "afxwin.h"



// CEdittapCtrl ��ȭ �����Դϴ�.

class CCloudsDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CCloudsDlg)

public:
	CCloudsDlg(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CCloudsDlg();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_CLOUDS };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

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
