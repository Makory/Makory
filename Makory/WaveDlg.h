#pragma once
#include "afxcmn.h"
#include "afxwin.h"


// CWaveDlg ��ȭ �����Դϴ�.

class CWaveDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CWaveDlg)

public:
	CWaveDlg(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CWaveDlg();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_WAVE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	CSliderCtrl mWaveS;
	CEdit mWaveEdit;
public:
	

	virtual BOOL OnInitDialog();
	
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	
	double fpos;
	afx_msg void OnEnUpdateWaveValue();
};
