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
	mTempToPath["Cloudy Light Rays"]="space/CloudyLightRays/left.bmp";
	mTempToPath["Dark Stormy"]="space/DarkStormy/front.bmp";
	mTempToPath["Full Moon"]="space/FullMoon/left.bmp";
	mTempToPath["Mountain"]="space/Mountain/front.bmp";
	mTempToPath["Sunset"]="space/SunSet/left.bmp";
	mTempToPath["Thick Clouds Water"]="space/ThickCloudsWater/right.bmp";
	mTempToPath["Tropical Sunny Day"]="space/TropicalSunnyDay/front.bmp";

	//이미지 아이콘 생성 
	m_largeIcon = new CImageList;
	//(50,50은 크기임)
	m_largeIcon->Create(50, 50, ILC_MASK|ILC_COLORDDB, 5, 5);
}

CImagelist::~CImagelist()
{
}

string CImagelist::GetImagePathFor(int index) const
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

string CImagelist::GetTemplatePathFor(std::string index) const
{
	map<string, string>::const_iterator iter2;
	iter2 = mTempToPath.find(index);
	if (iter2 != mTempToPath.end())
	{
		return iter2->second;
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

				//아이콘에 비트맵이미지 붙이기
		CBitmap cBit;

		HBITMAP hBmp = (HBITMAP)::LoadImage(AfxGetInstanceHandle(),
			szPath, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE ); //선택된 경로로부터 비트맵 생성

		//cBit.Attach((HBITMAP)::LoadImage( AfxGetInstanceHandle(), szPath, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE) );
		

		CClientDC dc(this);

		CDC memDC1, memDC2;
		memDC1.CreateCompatibleDC (&dc);
		memDC2.CreateCompatibleDC (&dc);
		memDC1.SelectObject (&hBmp);
		
	    HBITMAP holdbm = (HBITMAP)SelectObject(memDC1, hBmp);

		//불러온 이미지 사이즈 정보 구하기
		BITMAP bm;
		GetObject(hBmp, sizeof(BITMAP), &bm);
		
		CBitmap bitmap2; //리사이즈해서 새로 저장할 비트맵
		bitmap2.CreateCompatibleBitmap (&memDC1,50,50); //변경할 이미지 폭, 높이
		
		CBitmap *pOldBitmap=memDC2.SelectObject (&bitmap2);

		SetStretchBltMode(memDC2, HALFTONE);//축소된 이미지 보간

		memDC2.StretchBlt (0, 0, 50, 50, &memDC1,0,0, bm.bmWidth, bm.bmHeight, SRCCOPY); //축소
		memDC2.SelectObject(pOldBitmap); 
		
		cBit.Attach(bitmap2);


		if(str==".bmp"||str==".BMP"){		//현재 bmp 파일만 받아옴
		if ( bIsFirst )
		{
			SetImageList(m_largeIcon, LVSIL_NORMAL);
			bIsFirst = FALSE;
		}

		LV_ITEM		lvitem;
		lvitem.iItem		= GetItemCount();
		lvitem.mask			= LVIF_TEXT | LVIF_IMAGE;
		lvitem.iSubItem		= 0;
		lvitem.iImage		= m_largeIcon->Add(&cBit, RGB(0, 0, 0));
		lvitem.pszText		= shFileInfo.szDisplayName;
		
		index=InsertItem(&lvitem);
		//SetItemData(index, 
		mItemToPath[index] = std::string(szPath);
	}
		cBit.DeleteObject();//cbit해제 
	}

	CListCtrl::OnDropFiles(hDropInfo);
	
}
