#pragma once

#include <vector>

// CImageTimelineCtrl

class CImageTimelineCtrl : public CWnd
{
	DECLARE_DYNAMIC(CImageTimelineCtrl)

public:
	CImageTimelineCtrl();
	virtual ~CImageTimelineCtrl();

	void AddImgThumbnail(int index, const std::string& path);
	void AddTempThumbnail(CString index, const std::string& path);

protected:
	DECLARE_MESSAGE_MAP()
	afx_msg int OnCreate(CREATESTRUCT* createStruct);
	afx_msg void OnSize(UINT type, int cx, int cy);
	afx_msg void OnDestroy();
	afx_msg void OnHScroll(UINT, UINT, CScrollBar*);
	afx_msg void OnLButtonDown(UINT, CPoint point);
	afx_msg BOOL OnEraseBkgnd(CDC* dc);
	afx_msg void OnPaint();

	void UpdateScrollParameters();

	struct TemplateItem
	{
		CString index;
		std::string path;
		Gdiplus::Bitmap* bitmap;

	};

	struct ImageItem
	{
		int index;
		std::string path;
		Gdiplus::Bitmap* bitmap;

	};


	std::vector<TemplateItem> mTemplateImages;
	std::vector<ImageItem> mUserImages;
	int mHitTemplateItem;
	int mHitUserItem;

public:
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	int IMGmessage0;
	CString TEMPmessage;
	int NonTitle;
};


