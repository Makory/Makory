#pragma once


// BmpToArray

class BmpToArray : public CWnd
{
	DECLARE_DYNAMIC(BmpToArray)

public:
	BmpToArray();
	virtual ~BmpToArray();
	void LoadBmp(LPCTSTR lpszPathName);

protected:
	DECLARE_MESSAGE_MAP()
};


