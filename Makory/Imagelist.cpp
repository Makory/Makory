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
	mTempToPath["Cloudy Light Rays"]="space/CloudyLightRays/left.bmp";
	mTempToPath["Dark Stormy"]="space/DarkStormy/front.bmp";
	mTempToPath["Full Moon"]="space/FullMoon/left.bmp";
	mTempToPath["Mountain"]="space/Mountain/front.bmp";
	mTempToPath["Sunset"]="space/SunSet/left.bmp";
	mTempToPath["Thick Clouds Water"]="space/ThickCloudsWater/right.bmp";
	mTempToPath["Tropical Sunny Day"]="space/TropicalSunnyDay/front.bmp";

	//�̹��� ������ ���� 
	m_largeIcon = new CImageList;
	//(50,50�� ũ����)
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

				//�����ܿ� ��Ʈ���̹��� ���̱�
		CBitmap cBit;

		HBITMAP hBmp = (HBITMAP)::LoadImage(AfxGetInstanceHandle(),
			szPath, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE ); //���õ� ��ηκ��� ��Ʈ�� ����

		//cBit.Attach((HBITMAP)::LoadImage( AfxGetInstanceHandle(), szPath, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE) );
		

		CClientDC dc(this);

		CDC memDC1, memDC2;
		memDC1.CreateCompatibleDC (&dc);
		memDC2.CreateCompatibleDC (&dc);
		memDC1.SelectObject (&hBmp);
		
	    HBITMAP holdbm = (HBITMAP)SelectObject(memDC1, hBmp);

		//�ҷ��� �̹��� ������ ���� ���ϱ�
		BITMAP bm;
		GetObject(hBmp, sizeof(BITMAP), &bm);
		
		CBitmap bitmap2; //���������ؼ� ���� ������ ��Ʈ��
		bitmap2.CreateCompatibleBitmap (&memDC1,50,50); //������ �̹��� ��, ����
		
		CBitmap *pOldBitmap=memDC2.SelectObject (&bitmap2);

		SetStretchBltMode(memDC2, HALFTONE);//��ҵ� �̹��� ����

		memDC2.StretchBlt (0, 0, 50, 50, &memDC1,0,0, bm.bmWidth, bm.bmHeight, SRCCOPY); //���
		memDC2.SelectObject(pOldBitmap); 
		
		cBit.Attach(bitmap2);


		if(str==".bmp"||str==".BMP"){		//���� bmp ���ϸ� �޾ƿ�
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
		cBit.DeleteObject();//cbit���� 
	}

	CListCtrl::OnDropFiles(hDropInfo);
	
}
