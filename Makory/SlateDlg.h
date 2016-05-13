#pragma once


// CSlateDlg 대화 상자입니다.

class CSlateDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CSlateDlg)

public:
	CSlateDlg(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CSlateDlg();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_SLATE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
};
