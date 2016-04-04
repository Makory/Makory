// ImageTimelineCtrl.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "Makory.h"
#include "ImageTimelineCtrl.h"

using namespace Gdiplus;

int FIXED_WIDTH = 100;
static const int ICON_MARGIN = 5;
int ScrollWidth =0;

IMPLEMENT_DYNAMIC(CImageTimelineCtrl, CWnd)

CImageTimelineCtrl::CImageTimelineCtrl()
{
	mHitUserItem = -1;
	mHitTemplateItem = -1;
}

CImageTimelineCtrl::~CImageTimelineCtrl()
{
}

void CImageTimelineCtrl::AddThumbnail(const std::string& path)
{
	USES_CONVERSION;
	Bitmap* thumbnail = new Bitmap(A2W(path.c_str()));
	if (mUserImages.size())
	{
		ImageItem item;
		item.path = path;
		item.bitmap = thumbnail;
		mTemplateImages.push_back(item);
	}
	else
	{
		ImageItem item;
		item.path = path;
		item.bitmap = thumbnail;
		mUserImages.push_back(item);
	}

	UpdateScrollParameters();

	Invalidate();
}

BEGIN_MESSAGE_MAP(CImageTimelineCtrl, CWnd)
	ON_WM_CREATE()
	ON_WM_SIZE()
	ON_WM_DESTROY()
	ON_WM_ERASEBKGND()
	ON_WM_PAINT()
	ON_WM_HSCROLL()
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

int CImageTimelineCtrl::OnCreate(CREATESTRUCT* createStruct)
{
	CWnd::OnCreate(createStruct);

	return 0;
}

void CImageTimelineCtrl::OnDestroy()
{
	int numImages = (int)mUserImages.size();
	for (int i = 0; i < numImages; ++i)
	{
		delete mUserImages[i].bitmap;
	}
	numImages = (int)mTemplateImages.size();
	for (int i = 0; i < numImages; ++i)
	{
		delete mTemplateImages[i].bitmap;
	}

	CWnd::OnDestroy();
}

void CImageTimelineCtrl::UpdateScrollParameters()
{
	CRect clientRect;
	GetClientRect(&clientRect);
	int viewWidth = clientRect.Width();

	int maxNum = std::max((int)mUserImages.size(), (int)mTemplateImages.size());
	int widthPerItem = FIXED_WIDTH + ICON_MARGIN;
	int worldWidth = widthPerItem * maxNum;
	SCROLLINFO scrollInfo;
	scrollInfo.cbSize = sizeof(scrollInfo);
	scrollInfo.fMask = SIF_RANGE;
	scrollInfo.nMin = 0;
	if (viewWidth >= worldWidth)
	{
		scrollInfo.nMax = 0;
	}
	else
	{
		scrollInfo.nMax = worldWidth - viewWidth;
	}
	SetScrollInfo(SB_HORZ, &scrollInfo, TRUE);
}

void CImageTimelineCtrl::OnSize(UINT type, int cx, int cy)
{
	UpdateScrollParameters();
}

void CImageTimelineCtrl::OnHScroll(UINT scrollCode, UINT, CScrollBar*)
{
	SCROLLINFO si;
	si.cbSize = sizeof(si);
	si.fMask = SIF_ALL;
	GetScrollInfo(SB_HORZ, &si);

	switch (scrollCode)
	{
		case SB_LEFT:		si.nPos = si.nMin;		break;
		case SB_RIGHT:		si.nPos = si.nMax;		break;
		case SB_LINELEFT:	si.nPos -= 1;			break;
		case SB_LINERIGHT:	si.nPos += 1;			break;
		case SB_PAGELEFT:	si.nPos -= 500;			break;
		case SB_PAGERIGHT:	si.nPos += 500;			break;
		case SB_THUMBTRACK:	si.nPos = si.nTrackPos;	break;
	}
	ScrollWidth=si.nPos;	//스크롤 정보 저장

	si.fMask = SIF_POS;
	SetScrollInfo(SB_HORZ, &si, TRUE);

	Invalidate();
}

void CImageTimelineCtrl::OnLButtonDown(UINT, CPoint point)		//왼쪽 클릭시 다시그리기
{
	Invalidate();

	CRect itemRect;

	mHitUserItem = -1;
	mHitTemplateItem = -1;

	CRect rect;
	GetClientRect(&rect);

	int availableHeight = rect.Height();
	availableHeight -= ICON_MARGIN;
	int halfHeight = availableHeight / 2;

	itemRect.left = ICON_MARGIN-ScrollWidth;							//윗줄 그림
	itemRect.top = ICON_MARGIN;
	itemRect.right = itemRect.left + FIXED_WIDTH;
	itemRect.bottom = itemRect.top + halfHeight;

	int numImages = (int)mUserImages.size();
	for (int i = 0; i < numImages; ++i)
	{
		if (itemRect.PtInRect(point))
		{
			mHitUserItem = i;
			return;
		}

		itemRect.OffsetRect(FIXED_WIDTH + ICON_MARGIN, 0);
	}

	itemRect.top = itemRect.bottom + ICON_MARGIN;			//아랫줄 그림
	itemRect.left = ICON_MARGIN-ScrollWidth;					//ScrollWidth 추가하여 스크롤 후에도 제대로 선택 되게끔 함. 원래는 스크롤 이동하면 선택 사각형이 스크롤만큼 이동을 안했음
	itemRect.right = itemRect.left + FIXED_WIDTH;
	itemRect.bottom = itemRect.top + halfHeight;

	numImages = (int)mTemplateImages.size();
	for (int i = 0; i < numImages; ++i)
	{
		if (itemRect.PtInRect(point))
		{
			mHitTemplateItem = i;
			return;
		}

		itemRect.OffsetRect(FIXED_WIDTH + ICON_MARGIN, 0);
	}
}

BOOL CImageTimelineCtrl::OnEraseBkgnd(CDC* dc)		//다시그리기
{
	return TRUE;
}

void CImageTimelineCtrl::OnPaint()
{
	CPaintDC dc(this);
	CRect rect;
	GetClientRect(&rect);

	CDC dcMem;
	dcMem.CreateCompatibleDC(&dc);

	CBitmap bmpMem;
	bmpMem.CreateCompatibleBitmap(&dc, rect.Width(), rect.Height());

	CBitmap* oldSurface = dcMem.SelectObject(&bmpMem);

	{
		Graphics graphics(dcMem);
		graphics.Clear(Gdiplus::Color(255, 255, 255));	//바탕색

		int horzPos = GetScrollPos(SB_HORZ);
		Gdiplus::Matrix mat;
		graphics.GetTransform(&mat);

		graphics.TranslateTransform((float)-horzPos, 0);

		Gdiplus::Pen borderPen(Gdiplus::Color(0, 0, 255), 10);	//선택색

		int availableHeight = rect.Height();
		availableHeight -= ICON_MARGIN;
		int halfHeight = availableHeight / 2;

		Gdiplus::Rect imageRect;
		Gdiplus::Rect BorderRect;

		imageRect.X = ICON_MARGIN;		//들어가는 윗줄 이미지
		imageRect.Y = ICON_MARGIN;
		imageRect.Height = halfHeight;
		imageRect.Width = halfHeight/3*4;
		FIXED_WIDTH=imageRect.Width;

		int numImages = (int)mUserImages.size();
		for (int i = 0; i < numImages; ++i)
		{
			Bitmap* bitmap = mUserImages[i].bitmap;
			graphics.DrawImage(bitmap, imageRect);

			if (i == mHitUserItem)
			{
				graphics.DrawRectangle(&borderPen, imageRect);		//윗줄 선택
			}

			imageRect.X += FIXED_WIDTH + ICON_MARGIN;
		}

		imageRect.X = ICON_MARGIN;							//들어가는 아랫줄 이미지
		imageRect.Y += imageRect.Height + ICON_MARGIN;
		imageRect.Height = halfHeight;
		numImages = (int)mTemplateImages.size();
		
		BorderRect.X = ICON_MARGIN+FIXED_WIDTH;							//들어가는 아랫줄 선택
		BorderRect.Y += imageRect.Height + ICON_MARGIN;
		BorderRect.Height = halfHeight;
		BorderRect.Width = halfHeight/3*4;

		for (int i = 0; i < numImages; ++i)
		{
			Bitmap* bitmap = mTemplateImages[i].bitmap;
			graphics.DrawImage(bitmap, imageRect);

			if (i == mHitTemplateItem)
			{
				graphics.DrawRectangle(&borderPen, imageRect);		//아랫줄 선택
			}

			imageRect.X += FIXED_WIDTH + ICON_MARGIN;
		}

		graphics.SetTransform(&mat);
	}

	dc.BitBlt(0, 0, rect.Width(), rect.Height(), &dcMem, 0, 0, SRCCOPY);

	dcMem.SelectObject(oldSurface);
}


// CImageTimelineCtrl 메시지 처리기입니다.


