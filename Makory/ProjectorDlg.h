#pragma once


// CProjectorDlg ��ȭ �����Դϴ�.

class CProjectorDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CProjectorDlg)

public:
	CProjectorDlg(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CProjectorDlg();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_PROJECTOR };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};
