#pragma once
#include "afxcmn.h"
#include "afxwin.h"



// CEdittapCtrl 대화 상자입니다.

class CImageEditDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CImageEditDlg)

public:
	CImageEditDlg(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CImageEditDlg();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_IMAGEEDIT };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	double fpos;
	afx_msg void OnEnChangeEdit1();
	CSliderCtrl mImageScaleSlider;
	CEdit mImageScaleValue;
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);

};
