#pragma once



// CEdittapCtrl ��ȭ �����Դϴ�.

class CFishingDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CFishingDlg)

public:
	CFishingDlg(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CFishingDlg();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_FISHING };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEnChangeEdit1();
};
