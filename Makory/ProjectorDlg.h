#pragma once


// CProjectorDlg 대화 상자입니다.

class CProjectorDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CProjectorDlg)

public:
	CProjectorDlg(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CProjectorDlg();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_PROJECTOR };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
};
