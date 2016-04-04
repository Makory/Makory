#pragma once

// CImagelist

class CImagelist : public CListCtrl
{
	DECLARE_DYNAMIC(CImagelist)

public:
	CImagelist();
	virtual ~CImagelist();

	std::string GetPathFor(int index) const;

protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnDropFiles(HDROP hDropInfo);

	std::map<int, std::string> mItemToPath;
};


