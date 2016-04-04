#pragma once


// CLoadbuttonCtrl 대화 상자입니다.

class CLoadbuttonCtrl : public CDialogEx
{
	DECLARE_DYNAMIC(CLoadbuttonCtrl)

public:
	CLoadbuttonCtrl(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CLoadbuttonCtrl();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_IMAGE_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
};
