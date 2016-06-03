#pragma once



// CEdittapCtrl ��ȭ �����Դϴ�.

class CFilmDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CFilmDlg)

public:
	CFilmDlg(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CFilmDlg();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_FILM };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

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
