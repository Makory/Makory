#pragma once



// CEdittapCtrl 대화 상자입니다.

class CFilmDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CFilmDlg)

public:
	CFilmDlg(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CFilmDlg();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_FILM };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEnChangeEdit1();
	afx_msg void OnEnChangeFilmBlueValue();

	virtual BOOL OnInitDialog();
	
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	
	double fpos;

	CSliderCtrl mFilmRedS;
	CEdit mFilmRedValue;

	CSliderCtrl mFilmGreenS;
	CEdit mFilmGreenValue;


	CSliderCtrl mFilmBlueS;
	CEdit mFilmBlueValue;

	CSliderCtrl mFilmScaleSlider;
	CEdit mFilmScaleEdit;
	
	afx_msg void OnEnUpdateFilmRedValue();
	afx_msg void OnEnUpdateFilmGreenValue();
	afx_msg void OnEnUpdateFilmBlueValue();
	afx_msg void OnEnUpdateFilmScaleEdit();
	
};
