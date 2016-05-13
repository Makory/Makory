#pragma once
#include "imagetimelinectrl.h"


// CTimelineCtrl 대화 상자입니다.

class CTimelineCtrl : public CDialogEx
{
	DECLARE_DYNAMIC(CTimelineCtrl)

public:
	CTimelineCtrl(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CTimelineCtrl();

	CImageTimelineCtrl* GetTimelineCtrl();

	void AddImage(int index, const std::string& path);
	void AddTemplate(CString index, const std::string& path);

// 대화 상자 데이터입니다.
	enum { IDD = IDD_DIALOG_TIMELINE };

	virtual BOOL OnInitDialog();

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLbnSelchangeList1();
	afx_msg int OnCreate(CREATESTRUCT* createStruct);
	afx_msg void OnSize(UINT type, int cx, int cy);
	CImageTimelineCtrl m_ctrlImageTimeline;
};
