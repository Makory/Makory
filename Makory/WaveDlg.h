#pragma once
#include "afxcmn.h"
#include "afxwin.h"


// CWaveDlg 대화 상자입니다.

class CWaveDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CWaveDlg)

public:
	CWaveDlg(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CWaveDlg();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_WAVE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

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
