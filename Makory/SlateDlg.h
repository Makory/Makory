#pragma once


// CSlateDlg ��ȭ �����Դϴ�.

class CSlateDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CSlateDlg)

public:
	CSlateDlg(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CSlateDlg();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_SLATE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};
