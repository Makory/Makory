#pragma once


// CWaveDlg ��ȭ �����Դϴ�.

class CWaveDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CWaveDlg)

public:
	CWaveDlg(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CWaveDlg();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_WAVE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};
