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
};
