#pragma once


// DigBalloon ��ȭ �����Դϴ�.

class DigBalloon : public CDialogEx
{
	DECLARE_DYNAMIC(DigBalloon)

public:
	DigBalloon(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~DigBalloon();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_BALLOON };
	
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};
