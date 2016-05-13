#pragma once
#include "imagetimelinectrl.h"


// CTimelineCtrl ��ȭ �����Դϴ�.

class CTimelineCtrl : public CDialogEx
{
	DECLARE_DYNAMIC(CTimelineCtrl)

public:
	CTimelineCtrl(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CTimelineCtrl();

	CImageTimelineCtrl* GetTimelineCtrl();

	void AddImage(int index, const std::string& path);
	void AddTemplate(CString index, const std::string& path);

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_DIALOG_TIMELINE };

	virtual BOOL OnInitDialog();

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLbnSelchangeList1();
	afx_msg int OnCreate(CREATESTRUCT* createStruct);
	afx_msg void OnSize(UINT type, int cx, int cy);
	CImageTimelineCtrl m_ctrlImageTimeline;
};
