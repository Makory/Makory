#pragma once


// CTapCtrl ��ȭ �����Դϴ�.

class CTapCtrl : public CDialogEx
{
	DECLARE_DYNAMIC(CTapCtrl)

public:
	CTapCtrl(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CTapCtrl();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_DIALOG_EDITOR };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};
