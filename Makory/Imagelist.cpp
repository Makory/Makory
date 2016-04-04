// Imagelist.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "Makory.h"
#include "Imagelist.h"

using namespace std;

// CImagelist

IMPLEMENT_DYNAMIC(CImagelist, CListCtrl)

	CImagelist::CImagelist()
{

}

CImagelist::~CImagelist()
{
}

string CImagelist::GetPathFor(int index) const
{
	map<int, string>::const_iterator iter;
	iter = mItemToPath.find(index);
	if (iter != mItemToPath.end())
	{
		return iter->second;
	}
	else
	{
		return "";
	}
}

BEGIN_MESSAGE_MAP(CImagelist, CListCtrl)
	ON_WM_DROPFILES()
END_MESSAGE_MAP()

// CImagelist 메시지 처리기입니다.


void CImagelist::OnDropFiles(HDROP hDropInfo)
{


	//파일 이름만나오는데 아이콘은 아직 설정을 안해서 주석처리함
	CHAR		szPath[1024];
	UINT		uiFileNum;
	static BOOL	bIsFirst = TRUE;
	int index;
	uiFileNum = DragQueryFile(hDropInfo, 0xffffffff, NULL, 0);

	for ( UINT i = 0 ; i < uiFileNum ; i++ )
	{
		DragQueryFile(hDropInfo, i, (LPTSTR)szPath, 1023);

		SHFILEINFO	shFileInfo;
		SHGetFileInfo(szPath, NULL, &shFileInfo, sizeof(SHFILEINFO), SHGFI_DISPLAYNAME | SHGFI_ICON);	//szPath여기서 경로값 받음
		
		char fileExt[_MAX_EXT];
		_splitpath(szPath, NULL, NULL, NULL, fileExt);		//확장자 추출
		CString str;
		str=CString(fileExt);
		//AfxMessageBox(str);

		if(str==".bmp"||str==".BMP"){		//현재 bmp 파일만 받아옴
		if ( bIsFirst )
		{
		//	SetImageList(&m_IconList, LVSIL_NORMAL);
			bIsFirst = FALSE;
		}

		LV_ITEM		lvitem;
		lvitem.iItem		= GetItemCount();
		lvitem.mask			= LVIF_TEXT | LVIF_IMAGE;
		lvitem.iSubItem		= 0;
		//lvitem.iImage		= m_IconList.Add(shFileInfo.hIcon);
		lvitem.pszText		= shFileInfo.szDisplayName;
		
		index=InsertItem(&lvitem);
		//SetItemData(index, 
		mItemToPath[index] = std::string(szPath);
	}
	}

	CListCtrl::OnDropFiles(hDropInfo);
	
}
