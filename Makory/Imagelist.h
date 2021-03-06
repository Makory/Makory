#pragma once
#ifdef max
#undef max
#undef min
#endif   //max
// CImagelist

class CImagelist : public CListCtrl
{
	DECLARE_DYNAMIC(CImagelist)

public:
	CImagelist();
	virtual ~CImagelist();

	void Init();
	void AddItem(const CString& path);

	std::string GetImagePathFor(int index) const;
	std::string GetTemplatePathFor(std::string index) const;

protected:
	DECLARE_MESSAGE_MAP()

public:
	afx_msg void OnDropFiles(HDROP hDropInfo);

	std::map<int, std::string> mItemToPath;
	std::map<std::string, std::string> mTempToPath;

	CImageList* m_largeIcon;
	LV_ITEM		lvitem;
};