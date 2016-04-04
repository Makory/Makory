#pragma once


// CEdittapCtrl 대화 상자입니다.

class CEdittapCtrl : public CDialogEx
{
	DECLARE_DYNAMIC(CEdittapCtrl)

public:
	CEdittapCtrl(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CEdittapCtrl();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_EDITTAP_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEnChangeEdit1();
};
