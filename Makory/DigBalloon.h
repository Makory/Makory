#pragma once


// DigBalloon 대화 상자입니다.

class DigBalloon : public CDialogEx
{
	DECLARE_DYNAMIC(DigBalloon)

public:
	DigBalloon(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~DigBalloon();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_BALLOON };
	
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
};
