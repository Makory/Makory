#pragma once


// CLoadbuttonCtrl ��ȭ �����Դϴ�.

class CLoadbuttonCtrl : public CDialogEx
{
	DECLARE_DYNAMIC(CLoadbuttonCtrl)

public:
	CLoadbuttonCtrl(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CLoadbuttonCtrl();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_IMAGE_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};
