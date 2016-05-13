#pragma once
#include "afxcmn.h"
#include "afxwin.h"



// CEdittapCtrl ��ȭ �����Դϴ�.

class CMountainDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CMountainDlg)

public:
	CMountainDlg(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CMountainDlg();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_MOUNTAIN };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnEnChangeEdit1();
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
	double dpos;
};