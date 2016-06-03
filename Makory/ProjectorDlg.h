#pragma once


// CProjectorDlg 대화 상자입니다.

class CProjectorDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CProjectorDlg)

public:
	CProjectorDlg(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CProjectorDlg();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_PROJECTOR };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	void ChangeScaleTo(int balloonscale);
	
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	
	double fpos;

	CSliderCtrl mProjectorRedS;
	CEdit mProjectorRedValue;

	CSliderCtrl mProjectorGreenS;
	CEdit mProjectorGreenValue;


	CSliderCtrl mProjectorBlueS;
	CEdit mProjectorBlueValue;

	CSliderCtrl mProjectorVSlider;
	CSliderCtrl mProjectorHSlider;

	CEdit mProjectorVEdit;
	CEdit mProjectorHEdit;

	CSliderCtrl mProjectorScaleSlider;
	CEdit mProjectorScaleEdit;
	
	afx_msg void OnEnUpdateProjectorRedValue();
	afx_msg void OnEnUpdateProjectorGreenValue();
	afx_msg void OnEnUpdateProjectorBlueValue();
	afx_msg void OnEnUpdateProjectorVEdit();
	afx_msg void OnEnUpdateProjectorHEdit();
	afx_msg void OnEnUpdateProjectorScaleEdit();
};
