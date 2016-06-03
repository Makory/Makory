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

	afx_msg void OnEnUpdateCloudsRedValue();
	afx_msg void OnEnUpdateCloudsGreenValue();
	afx_msg void OnEnUpdateCloudsBlueValue();
	afx_msg void OnEnUpdateCloudsVEdit();
	afx_msg void OnEnUpdateCloudsHEdit();

	double dpos;
};
