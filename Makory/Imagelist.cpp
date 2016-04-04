// Imagelist.cpp : ���� �����Դϴ�.
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

// CImagelist �޽��� ó�����Դϴ�.


void CImagelist::OnDropFiles(HDROP hDropInfo)
{


	//���� �̸��������µ� �������� ���� ������ ���ؼ� �ּ�ó����
	CHAR		szPath[1024];
	UINT		uiFileNum;
	static BOOL	bIsFirst = TRUE;
	int index;
	uiFileNum = DragQueryFile(hDropInfo, 0xffffffff, NULL, 0);

	for ( UINT i = 0 ; i < uiFileNum ; i++ )
	{
		DragQueryFile(hDropInfo, i, (LPTSTR)szPath, 1023);

		SHFILEINFO	shFileInfo;
		SHGetFileInfo(szPath, NULL, &shFileInfo, sizeof(SHFILEINFO), SHGFI_DISPLAYNAME | SHGFI_ICON);	//szPath���⼭ ��ΰ� ����
		
		char fileExt[_MAX_EXT];
		_splitpath(szPath, NULL, NULL, NULL, fileExt);		//Ȯ���� ����
		CString str;
		str=CString(fileExt);
		//AfxMessageBox(str);

		if(str==".bmp"||str==".BMP"){		//���� bmp ���ϸ� �޾ƿ�
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
