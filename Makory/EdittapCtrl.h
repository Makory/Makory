#pragma once


// CEdittapCtrl ��ȭ �����Դϴ�.

class CEdittapCtrl : public CDialogEx
{
	DECLARE_DYNAMIC(CEdittapCtrl)

public:
	CEdittapCtrl(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CEdittapCtrl();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_EDITTAP_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEnChangeEdit1();
};
