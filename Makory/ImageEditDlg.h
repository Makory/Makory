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

	double scalecloudy;
	double scaledark;
	double scalefull;
	double scalesunset;
	double scalewater;
	double scaletropical;
	double scalemountain;

	double scaleproj;
	double scalefilm;
	double scaleslate;
	double scalewave;
	double scaleocean;
	double scalefishing;



	CSliderCtrl mcloudyImageScaleSlider;
	CSliderCtrl mdarkImageScaleSlider;
	CSliderCtrl mfullImageScaleSlider;
	CSliderCtrl mmountainImageScaleSlider;
	CSliderCtrl msunsetImageScaleSlider;
	CSliderCtrl mwaterImageScaleSlider;
	CSliderCtrl mtropicalImageScaleSlider;
	void ChangeImgTo(int imgType);

	CEdit mcloudyImageScaleValue;
	CEdit mdarkImageScaleValue;
	
	CEdit mfullImageScaleValue;
	CEdit mmountainImageScaleValue;
	
	CEdit msunsetImageScaleValue;
	CEdit mwaterImageScaleValue;
	CEdit mtropicalImageScaleValue;

	CSliderCtrl mfilmImageScaleSlider;
	CSliderCtrl mslateImageScaleSlider;
	CSliderCtrl mprojImageScaleSlider;
	CSliderCtrl moceanImageScaleSlider;
	CSliderCtrl mfishingImageScaleSlider;
	CSliderCtrl mwaveImageScaleSlider;

	CEdit mfilmImageScaleValue;
	CEdit mslateImageScaleValue;
	CEdit mprojImageScaleValue;
	
	CEdit moceanImageScaleValue;
	CEdit mfishingImageScaleValue;
	CEdit mwaveImageScaleValue;


	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);

	afx_msg void OnEnUpdatecloudyImageScaleValue();
	afx_msg void OnEnUpdatedarkImageScaleValue();
	afx_msg void OnEnUpdatefullImageScaleValue();
	afx_msg void OnEnUpdatemountainImageScaleValue();
	afx_msg void OnEnUpdatewaterImageScaleValue();
	afx_msg void OnEnUpdatesunsetImageScaleValue();
	afx_msg void OnEnUpdatetropicalImageScaleValue();

	afx_msg void OnEnUpdatefilmImageScaleValue();
	afx_msg void OnEnUpdateslateImageScaleValue();
	afx_msg void OnEnUpdateprojImageScaleValue();

		afx_msg void OnEnUpdatewaveImageScaleValue();
	afx_msg void OnEnUpdatefishingImageScaleValue();
	afx_msg void OnEnUpdateoceanImageScaleValue();

};
