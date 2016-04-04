#pragma once

#include <vector>

// CImageTimelineCtrl

class CImageTimelineCtrl : public CWnd
{
	DECLARE_DYNAMIC(CImageTimelineCtrl)

public:
	CImageTimelineCtrl();
	virtual ~CImageTimelineCtrl();

	void AddThumbnail(const std::string& path);

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

	struct ImageItem
	{
		std::string path;
		Gdiplus::Bitmap* bitmap;
	};
	std::vector<ImageItem> mUserImages;
	std::vector<ImageItem> mTemplateImages;
	int mHitUserItem;
	int mHitTemplateItem;
};


