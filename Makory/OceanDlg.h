#pragma once


// COceanDlg ��ȭ �����Դϴ�.

class COceanDlg : public CDialogEx
{
	DECLARE_DYNAMIC(COceanDlg)

public:
	COceanDlg(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~COceanDlg();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_OCEAN };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};
