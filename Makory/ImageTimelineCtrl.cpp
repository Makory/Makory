// ImageTimelineCtrl.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "Makory.h"
#include "ImageTimelineCtrl.h"
#include "MainFrm.h"
#include "MakoryDoc.h"
#include "MakoryView.h"

using namespace Gdiplus;

static const int FIXED_WIDTH = 100;
static const int ICON_MARGIN = 5;
int AUTO_PLAY_TIMER= 1000;

IMPLEMENT_DYNAMIC(CImageTimelineCtrl, CWnd)

CImageTimelineCtrl::CImageTimelineCtrl()
{
	itemIndex=-1;
	mHotTemplateItem = -1;
	mHotUserItem = -1;
	NonTitle=0;
	mDragEntered = false;
	type="NULL";
}

CImageTimelineCtrl::~CImageTimelineCtrl()
{
}

void CImageTimelineCtrl::AddTempThumbnail(CString index, const std::string& path)
{
	USES_CONVERSION;
	Bitmap* thumbnail = new Bitmap(A2W(path.c_str()));

	TemplateItem temp;
	temp.index=index;
	temp.path = path;
	temp.bitmap = thumbnail;
	mTemplateImages.push_back(temp);

	UpdateScrollParameters();

	EnsureVisible(static_cast<int>(mTemplateImages.size()) - 1);

	Invalidate(FALSE);
}

void CImageTimelineCtrl::AddImgThumbnail(int index, const std::string& path)
{
	USES_CONVERSION;
	Bitmap* thumbnail = new Bitmap(A2W(path.c_str()));

	ImageItem item;
	item.index=index;
	item.path = path;
	item.bitmap = thumbnail;
	mUserImages.push_back(item);

	UpdateScrollParameters();

	EnsureVisible(static_cast<int>(mUserImages.size()) - 1);

	Invalidate(FALSE);
}

BEGIN_MESSAGE_MAP(CImageTimelineCtrl, CWnd)
	ON_WM_CREATE()
	ON_WM_SIZE()
	ON_WM_DESTROY()
	ON_WM_ERASEBKGND()
	ON_WM_PAINT()
	ON_WM_HSCROLL()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_CAPTURECHANGED()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONDBLCLK()
	ON_WM_KEYDOWN()
	ON_WM_TIMER()
END_MESSAGE_MAP()

int CImageTimelineCtrl::OnCreate(CREATESTRUCT* createStruct)
{
	CWnd::OnCreate(createStruct);

	return 0;
}

void CImageTimelineCtrl::OnDestroy()
{
	int numTempletes = (int)mTemplateImages.size();
	for (int i = 0; i < numTempletes; ++i)
	{
		delete mTemplateImages[i].bitmap;
	}
	int numImages = (int)mUserImages.size();
	for (int i = 0; i < numImages; ++i)
	{
		delete mUserImages[i].bitmap;
	}

	CWnd::OnDestroy();
}

bool CImageTimelineCtrl::UpdateHotItem(CPoint screenPoint)
{
	CPoint point(screenPoint);
	int xOffset = GetScrollPos(SB_HORZ);
	point.x += xOffset;

	CRect itemRect;

	int oldTemplate = mHotTemplateItem;
	int oldUser = mHotUserItem;
	mHotTemplateItem = -1;
	mHotUserItem = -1;

	CRect rect;
	GetClientRect(&rect);

	int availableHeight = rect.Height();
	availableHeight -= 3 * ICON_MARGIN;
	int halfHeight = availableHeight / 2;

	itemRect.left = ICON_MARGIN;							//윗줄 그림
	itemRect.top = ICON_MARGIN;
	itemRect.right = itemRect.left + FIXED_WIDTH;
	itemRect.bottom = itemRect.top + halfHeight;

	int numTempletes = (int)mTemplateImages.size();
	int numImages = (int)mUserImages.size();
	
	for (int i = 0; i < numTempletes; ++i)
	{
		if (itemRect.PtInRect(point))
		{
			mHotTemplateItem = i;
			return (oldTemplate != mHotTemplateItem || oldUser != mHotUserItem);
		}

		itemRect.OffsetRect(FIXED_WIDTH + ICON_MARGIN, 0);
	}

	itemRect.top = itemRect.bottom + ICON_MARGIN;			//아랫줄 그림
	//itemRect.left = ICON_MARGIN-ScrollWidth;					//ScrollWidth 추가하여 스크롤 후에도 제대로 선택 되함. 
	//원래는 스크롤 이동하면 선택 사각형이 스크롤만큼 이동을 안했음
	itemRect.left = ICON_MARGIN;

	itemRect.right = itemRect.left + FIXED_WIDTH;
	itemRect.bottom = itemRect.top + halfHeight;

	for (int i = 0; i < numImages; ++i)
	{
		if (itemRect.PtInRect(point))
		{
			mHotUserItem = i;
			return (oldTemplate != mHotTemplateItem || oldUser != mHotUserItem);
		}

		itemRect.OffsetRect(FIXED_WIDTH + ICON_MARGIN, 0);
	}

	return false;
}

void CImageTimelineCtrl::UpdateScrollParameters()
{
	CRect clientRect;
	GetClientRect(&clientRect);
	int viewWidth = clientRect.Width();

	int maxNum = std::max((int)mTemplateImages.size(), (int)mUserImages.size());
	int widthPerItem = FIXED_WIDTH + ICON_MARGIN;
	int worldWidth = widthPerItem * maxNum + ICON_MARGIN;
	SCROLLINFO scrollInfo;
	scrollInfo.cbSize = sizeof(scrollInfo);
	scrollInfo.fMask = SIF_RANGE | SIF_PAGE;
	scrollInfo.nMin = 0;
	scrollInfo.nMax = (viewWidth >= worldWidth) ? 0 : worldWidth;
	scrollInfo.nPage = viewWidth;
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
	case SB_LEFT:  si.nPos = si.nMin;      break;
	case SB_RIGHT:  si.nPos = si.nMax;      break;
	case SB_LINELEFT: si.nPos -= FIXED_WIDTH + ICON_MARGIN; break;
	case SB_LINERIGHT: si.nPos += FIXED_WIDTH + ICON_MARGIN; break;
	case SB_PAGELEFT: si.nPos -= si.nPage;     break;
	case SB_PAGERIGHT: si.nPos += si.nPage;     break;
	case SB_THUMBTRACK: si.nPos = si.nTrackPos;     break;
	}

	si.fMask = SIF_POS;
	SetScrollInfo(SB_HORZ, &si, TRUE);

	Invalidate();
}

void CImageTimelineCtrl::EnsureVisible(int index)
{
	int fixedItemWidth = FIXED_WIDTH + ICON_MARGIN;
	int itemStart = index * fixedItemWidth;
	int itemEnd = itemStart +  fixedItemWidth + ICON_MARGIN;

	CRect viewRect;
	GetClientRect(&viewRect);
	int viewStart = GetScrollPos(SB_HORZ);		// in world space
	int viewEnd = viewStart + viewRect.Width(); // in world space
	int scrollPos = 0;
	bool reposition = false;
	if (itemStart <= viewStart)
	{
		scrollPos = itemStart;
		reposition = true;
	}
	else if (itemEnd >= viewEnd)
	{
		scrollPos = itemEnd - viewRect.Width();
		reposition = true;
	}

	if (scrollPos < 0)
	{
		scrollPos = 0;
	}

	if (reposition)
	{
		SetScrollPos(SB_HORZ, scrollPos, TRUE);
	}
}

void CImageTimelineCtrl::StartDragging(CPoint point)
{
	mDragIcon.DeleteImageList();
	mDragIcon.Create(50, 50, ILC_MASK|ILC_COLORDDB, 1, 1);

	CString szPath;
	if (-1 != mHotTemplateItem)
	{
		szPath = mTemplateImages[mHotTemplateItem].path.c_str();
	}
	else
	{
		szPath = mUserImages[mHotUserItem].path.c_str();
	}

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

	mDragIcon.Add(&cBit, RGB(0, 0, 0));
}

void CImageTimelineCtrl::OnLButtonDown(UINT, CPoint point)		//왼쪽 클릭시 다시그리기
{
	SetFocus();			//키보드 펑션 받기 위해 꼭 필요

	UpdateHotItem(point);
	
	if (mHotUserItem != -1 || mHotTemplateItem != -1)
	{
		SetCapture();

		//RedrawWindow(nullptr, nullptr, RDW_INVALIDATE | RDW_UPDATENOW);

		StartDragging(point);
		
		mDragEntered = false;

		if(mHotUserItem != -1) {
			itemIndex=mHotUserItem;
			type = "Image";
		} else {
			itemIndex=mHotTemplateItem;
			type = "Templete";
		}
		//int itemIndex = (mHotUserItem != -1) ? mHotUserItem : mHotTemplateItem;
		EnsureVisible(itemIndex);
	}

	Invalidate(FALSE);
}

void CImageTimelineCtrl::OnMouseMove(UINT flags, CPoint point)
{
	if (GetCapture() == this)
	{
		if (mDragEntered == false)
		{
			mDragIcon.BeginDrag(0, CPoint(25, 25));

			ClientToScreen(&point);
			CImageList::DragEnter(0, point);

			mDragEntered = true;
		}
		else
		{
			ClientToScreen(&point);
			CImageList::DragMove(point);
		}
	}
}

void CImageTimelineCtrl::OnLButtonUp(UINT, CPoint screenPoint)
{
	if (GetCapture() == this)
	{
		OutputDebugStringA("OnLButtonUp\n");

		// calculate the column here
		CPoint point(screenPoint);
		point.x += GetScrollPos(SB_HORZ);

		int itemArea = FIXED_WIDTH + ICON_MARGIN;
		if (mHotTemplateItem != -1)
		{
			int numItems = static_cast<int>(mTemplateImages.size());
			int targetSlot = point.x / itemArea;
			if (targetSlot < 0)
			{
				targetSlot = 0;
			}
			else if (targetSlot >= numItems)
			{
				targetSlot = numItems - 1;
			}

			if (targetSlot != mHotTemplateItem)
			{
				TemplateItem saveItem;
				saveItem = mTemplateImages[mHotTemplateItem];

				mTemplateImages.erase(mTemplateImages.begin() + mHotTemplateItem);
				mTemplateImages.insert(mTemplateImages.begin() + targetSlot, 1, saveItem);

				mHotTemplateItem = targetSlot;
				EnsureVisible(targetSlot);
			}
		}
		else
		{
			int numItems = static_cast<int>(mUserImages.size());
			int targetSlot = point.x / itemArea;
			if (targetSlot < 0)
			{
				targetSlot = 0;
			}
			else if (targetSlot >= numItems)
			{
				targetSlot = numItems - 1;
			}

			if (targetSlot != mHotUserItem)
			{
				ImageItem saveItem;
				saveItem = mUserImages[mHotUserItem];

				mUserImages.erase(mUserImages.begin() + mHotUserItem);
				mUserImages.insert(mUserImages.begin() + targetSlot, 1, saveItem);

				mHotUserItem= targetSlot;
				EnsureVisible(targetSlot);
			}
		}

		ReleaseCapture();

		Invalidate(FALSE);
	}
}

void CImageTimelineCtrl::OnCaptureChanged(CWnd* capturingWnd)
{
	if (capturingWnd != this)
	{
		CImageList::DragLeave(0);
		CImageList::EndDrag();
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
		Gdiplus::Pen borderPen2(Gdiplus::Color(255, 0, 0), 10);	//선택색
		
		int availableHeight = rect.Height();
		availableHeight -= 3 * ICON_MARGIN;
		int halfHeight = availableHeight / 2;

		//탬플릿 들어가는 위쪽 배경색
		CDC* pDC1 = GetDC(); //DC 생성
		COLORREF mTopColor; //위에 내부를 채울 변수
		COLORREF mBottomColor;
		mTopColor = ARGB(0x6Efafafa); // top 색상 설정
		mBottomColor = ARGB(0x6Ebdbdbd); //bottom 색상 설정

		//Top 배경색
		int mtopX = 0;   //좌표
		int mtopY = 0;
		int mtopWidth = rect.Width();   //가로크기
		int mtopHeight = rect.Height()/2;  //세로크기

		graphics.SetSmoothingMode(SmoothingModeHighQuality);

		SolidBrush topbrush(mTopColor); //브러시 설정
		graphics.FillRectangle(&topbrush,mtopX,mtopY,mtopWidth,mtopHeight); //사각형을 그린다.

		//Bottom 배경색
		int mbottomX = 0;   //좌표
		int mbottomY = rect.Height()/2;
		int mbottomWidth = rect.Width();   //가로크기
		int mbottomHeight = rect.Height()/2;  //세로크기

		SolidBrush bottombrush(mBottomColor); 
		graphics.FillRectangle(&bottombrush,mbottomX,mbottomY,mbottomWidth,mbottomHeight); //사각형을 그린다.

		ReleaseDC(pDC1);
		//배경끝

		Gdiplus::Rect imageRect;
		Gdiplus::Rect BorderRect;

		imageRect.X = ICON_MARGIN;		//들어가는 윗줄 이미지
		imageRect.Y = ICON_MARGIN;
		imageRect.Height = halfHeight;
		//imageRect.Width = halfHeight/3*4;
		imageRect.Width = FIXED_WIDTH;
		//FIXED_WIDTH=imageRect.Width;
		//int fixedWidth = imageRect.Width;

		
		int numTempletes = (int)mTemplateImages.size();
		for (int i = 0; i < numTempletes; ++i)
		{
			Bitmap* bitmap = mTemplateImages[i].bitmap;

			graphics.DrawImage(bitmap, imageRect);

			if (i == mHotTemplateItem)
			{
				graphics.DrawRectangle(&borderPen, imageRect);		//윗줄 선택
			}
			imageRect.X += FIXED_WIDTH + ICON_MARGIN;
		}


		imageRect.X = ICON_MARGIN;							//들어가는 아랫줄 이미지
		imageRect.Y += imageRect.Height + ICON_MARGIN;
		imageRect.Height = halfHeight;
		int numImages = (int)mUserImages.size();
		
		BorderRect.X = ICON_MARGIN+FIXED_WIDTH;							//들어가는 아랫줄 선택
		BorderRect.Y += imageRect.Height + ICON_MARGIN;
		BorderRect.Height = halfHeight;
		BorderRect.Width = halfHeight/3*4;

		for (int i = 0; i < numImages; ++i)
		{
			Bitmap* bitmap = mUserImages[i].bitmap;
			graphics.DrawImage(bitmap, imageRect);

			if (i == mHotUserItem)
			{
				graphics.DrawRectangle(&borderPen2, imageRect);		//아랫줄 선택
			}

			imageRect.X += FIXED_WIDTH + ICON_MARGIN;
		}

		graphics.SetTransform(&mat);
	}
	 
	dc.BitBlt(0, 0, rect.Width(), rect.Height(), &dcMem, 0, 0, SRCCOPY);

	dcMem.SelectObject(oldSurface);
}

//타임라인 더블 클릭했을때 이벤트(경로값 받아오기)
void CImageTimelineCtrl::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	Invalidate();

	CMainFrame* pFrame = (CMainFrame*)AfxGetMainWnd();				//View호출
	CMakoryView* pView = (CMakoryView*)pFrame->GetActiveView();		//View호출
	CEditorCtrl* pEidt = pFrame->GetEditorCtrl();

	//Select=point;
	CRect itemRect;
	CRect tempRect;
	CRect imgRect;

	UpdateHotItem(point);

	int numTempletes = static_cast<int>(mTemplateImages.size());
	int numImages = static_cast<int>(mUserImages.size());
	//템플릿

	enum SelectionCase
	{
		SELECTION_CASE_NONE,
		SELECTION_CASE_TEMPLATE,
		SELECTION_CASE_USER
	};
	SelectionCase selectionCase = SELECTION_CASE_NONE;
	int pairedItem = -1;

	if (mHotTemplateItem != -1 ||
		mHotUserItem != -1)
	{
		if (mHotTemplateItem != -1)
		{
			selectionCase = SELECTION_CASE_TEMPLATE;
			if (mHotTemplateItem < numImages)
			{
				pairedItem = mHotTemplateItem;
			}
		}
		else
		{
			selectionCase = SELECTION_CASE_USER;
			if (mHotUserItem < numTempletes)
			{
				pairedItem = mHotUserItem;
			}
		}
	}

	if (SELECTION_CASE_TEMPLATE == selectionCase)
	{
		TEMPmessage=mTemplateImages[mHotTemplateItem].index; //메세지에 path받아옴
		if(TEMPmessage=="Cloudy Light Rays") {
			pView->SelectTemplate=1;
			pEidt->ChangeEditDlgTo(1);
		}else if(TEMPmessage=="Dark Stormy") {
			pView->SelectTemplate=2;
			pEidt->ChangeEditDlgTo(2);
		}else if(TEMPmessage=="Full Moon") {
			pView->SelectTemplate=3;
			//pEidt->ChangeEditDlgTo(3);
	
		}else if(TEMPmessage=="Mountain") {
			pView->SelectTemplate=4;
			pEidt->ChangeEditDlgTo(4);
		
		}else if(TEMPmessage=="Sunset") {
			pView->SelectTemplate=5;
			
		
		}else if(TEMPmessage=="Thick Clouds Water") {
			pView->SelectTemplate=6;
			
		}else if(TEMPmessage=="Tropical Sunny Day") {
			pView->SelectTemplate=7;
			
		}else if(TEMPmessage=="영사기") {
			pView->SelectTemplate=8;
			
		}else if(TEMPmessage=="필름") {
			pView->SelectTemplate=9;
			
		}else if(TEMPmessage=="슬레이트") {
			pView->SelectTemplate=10;
			
		}else if(TEMPmessage=="파도") {
			pView->SelectTemplate=11;
			
		}else if(TEMPmessage=="바다속") {
			pView->SelectTemplate=12;
			
		}else if(TEMPmessage=="낚시") {
			pView->SelectTemplate=13;
			
		}
		
	pView->IsItKey=0;
		if(pView->SelectTemplate>=1&&pView->SelectTemplate<=7) {
			pView->BallonStartAnimation();
		}else {
			pView->Initialization();
		}

		if (-1 == pairedItem)
		{
			pView->SelectImage="space/NoImage.bmp";
		}
		else
		{
			IMGmessage=mUserImages[pairedItem].path.c_str(); //메세지에 index 받아옴
			pView->SelectImage=IMGmessage;
		}

		pView->Invalidate(FALSE);
	}
	else if (SELECTION_CASE_USER == selectionCase)
	{
		IMGmessage=mUserImages[mHotUserItem].path.c_str(); //메세지에 index 받아옴
		pView->SelectImage=IMGmessage;

		if (-1 == pairedItem)
		{
			pView->SelectTemplate = -1;
			
		}
		else
		{
			TEMPmessage=mTemplateImages[pairedItem].index; //메세지에 path받아옴
			if(TEMPmessage=="Cloudy Light Rays") {
				pView->SelectTemplate=1;
			
			}else if(TEMPmessage=="Dark Stormy") {
				pView->SelectTemplate=2;
			}else if(TEMPmessage=="Full Moon") {
				pView->SelectTemplate=3;
			}else if(TEMPmessage=="Mountain") {
				pView->SelectTemplate=4;
			}else if(TEMPmessage=="Sunset") {
				pView->SelectTemplate=5;
			}else if(TEMPmessage=="Thick Clouds Water") {
				pView->SelectTemplate=6;
			}else if(TEMPmessage=="Tropical Sunny Day") {
				pView->SelectTemplate=7;
				
			}
		}
		pEidt->ChangeEditDlgTo(100);
		pEidt->Invalidate();
		pView->Invalidate(FALSE);
	}

#if 0
	if (selectedItem != -1)
	{
		TEMPmessage=mTemplateImages[selectedItem].index; //메세지에 path받아옴
		if(TEMPmessage=="Cloudy Light Rays") {
			pView->SelectTemplate=1;
			pEidt->Select=1;
		}else if(TEMPmessage=="Dark Stormy") {
			pView->SelectTemplate=2;
		}else if(TEMPmessage=="Full Moon") {
			pView->SelectTemplate=3;
		}else if(TEMPmessage=="Mountain") {
			pView->SelectTemplate=4;
		}else if(TEMPmessage=="Sunset") {
			pView->SelectTemplate=5;
		}else if(TEMPmessage=="Thick Clouds Water") {
			pView->SelectTemplate=6;
		}else if(TEMPmessage=="Tropical Sunny Day") {
			pView->SelectTemplate=7;
		}

	}

	for (int i = 0; i < std::min(numImages,numTempletes); ++i)					//템플릿 갯수=이미지 갯수
	{
		if (itemRect.PtInRect(point))
		{
			//---------------템플릿------------------
			mHotTemplateItem = i;
			TEMPmessage=mTemplateImages[i].index; //메세지에 path받아옴
			//MessageBox(TEMPmessage);
			if(TEMPmessage=="Cloudy Light Rays") {
				pView->SelectTemplate=1;
				pEidt->Select=1;
			}else if(TEMPmessage=="Dark Stormy") {
				pView->SelectTemplate=2;
			}else if(TEMPmessage=="Full Moon") {
				pView->SelectTemplate=3;
			}else if(TEMPmessage=="Mountain") {
				pView->SelectTemplate=4;
			}else if(TEMPmessage=="Sunset") {
				pView->SelectTemplate=5;
			}else if(TEMPmessage=="Thick Clouds Water") {
				pView->SelectTemplate=6;
			}else if(TEMPmessage=="Tropical Sunny Day") {
				pView->SelectTemplate=7;
			}
			
			
			//---------------이미지------------------
			mHotUserItem = i; //주석 푸르면 사각형 표시됨
			IMGmessage=mUserImages[i].path.c_str(); //메세지에 index 받아옴
				pView->SelectImage=IMGmessage;
			
			//CString IMGmessage;
			//IMGmessage.Format("%d" , IMGmessage0);	//포맷변경
			//MessageBox(IMGmessage);
			pView->Invalidate();
			return;
		}

		itemRect.OffsetRect(FIXED_WIDTH + ICON_MARGIN, 0);
	}

	if(numImages<numTempletes) {					//템플릿 갯수>이미지 갯수
		for (int i = 0; i < numTempletes; ++i)
		{
			if (tempRect.PtInRect(point))
			{
				//---------------템플릿------------------
				mHotTemplateItem = i;
				TEMPmessage=mTemplateImages[i].index; //메세지에 path받아옴
				//MessageBox(TEMPmessage);
				if(TEMPmessage=="Cloudy Light Rays") {
					pView->SelectTemplate=1;
				pEidt->Select=1;
				}else if(TEMPmessage=="Dark Stormy") {
					pView->SelectTemplate=2;
				}else if(TEMPmessage=="Full Moon") {
					pView->SelectTemplate=3;
				}else if(TEMPmessage=="Mountain") {
					pView->SelectTemplate=4;
				}else if(TEMPmessage=="Sunset") {
					pView->SelectTemplate=5;
				}else if(TEMPmessage=="Thick Clouds Water") {
					pView->SelectTemplate=6;
				}else if(TEMPmessage=="Tropical Sunny Day") {
					pView->SelectTemplate=7;
				}

				pView->SelectImage="space/NoImage.bmp";
				pView->Invalidate();
				return;
			}

			tempRect.OffsetRect(FIXED_WIDTH + ICON_MARGIN, 0);
		}
	}else if(numImages>numTempletes) {					//템플릿 갯수<이미지 갯수
		for (int i = 0; i < numImages; ++i)
		{
			if (imgRect.PtInRect(point))
			{
				//---------------이미지------------------
				mHotUserItem = i; //주석 푸르면 사각형 표시됨
				IMGmessage=mUserImages[i].path.c_str(); //메세지에 index 받아옴
				pView->SelectImage=IMGmessage;

				pView->SelectTemplate=-1;
				pView->Invalidate();
				return;

			}

			imgRect.OffsetRect(FIXED_WIDTH + ICON_MARGIN, 0);
		}

	}


	numTempletes = (int)mUserImages.size();
#endif

	CWnd::OnLButtonDblClk(nFlags, point);
}
void CImageTimelineCtrl::OnAnimationFinished()
{
	// current frame을 증가 시키고
	// 다시 start animation
	int numTemplates = static_cast<int>(mTemplateImages.size());
	int numUsers = static_cast<int>(mUserImages.size());
	int smaller = std::min(numTemplates, numUsers);
	mCurrentFrame++;
	if (mCurrentFrame < smaller)
	{
		CMainFrame* pFrame = (CMainFrame*)AfxGetMainWnd();				//View호출
		CMakoryView* pView = (CMakoryView*)pFrame->GetActiveView();		//View호출

		if(mCurrentFrame+1 >= smaller) {
			pView->IsItKey=0;
		}
		IMGmessage=mUserImages[mCurrentFrame].path.c_str(); //메세지에 index 받아옴
		pView->SelectImage=IMGmessage;

		TEMPmessage=mTemplateImages[mCurrentFrame].index; //메세지에 path받아옴
		if(TEMPmessage=="Cloudy Light Rays") {
			pView->SelectTemplate=1;
		}else if(TEMPmessage=="Dark Stormy") {
			pView->SelectTemplate=2;
		}else if(TEMPmessage=="Full Moon") {
			pView->SelectTemplate=3;
		}else if(TEMPmessage=="Mountain") {
			pView->SelectTemplate=4;
		}else if(TEMPmessage=="Sunset") {
			pView->SelectTemplate=5;
		}else if(TEMPmessage=="Thick Clouds Water") {
			pView->SelectTemplate=6;
		}else if(TEMPmessage=="Tropical Sunny Day") {
			pView->SelectTemplate=7;
		}else if(TEMPmessage=="영사기") {
			pView->SelectTemplate=8;
		}else if(TEMPmessage=="필름") {
			pView->SelectTemplate=9;
		}else if(TEMPmessage=="슬레이트") {
			pView->SelectTemplate=10;
		}else if(TEMPmessage=="파도") {
			pView->SelectTemplate=11;
		}else if(TEMPmessage=="바다속") {
			pView->SelectTemplate=12;
		}else if(TEMPmessage=="낚시") {
			pView->SelectTemplate=13;
		}
		if(pView->SelectTemplate>=1&&pView->SelectTemplate<=7) {
			pView->BallonStartAnimation();
		}else {
			pView->StartAnimation();
		}
	} else {
	}
}

void CImageTimelineCtrl::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
		//SetFocus();

		switch(nChar){
		case VK_BACK:		//backspace
			{
		case VK_DELETE:
			//MessageBox("Delete");
			if(type=="Templete") {
				mTemplateImages.erase(mTemplateImages.begin() + mHotTemplateItem);	//템플릿만 해당
			} if(type=="Image"){
				mUserImages.erase(mUserImages.begin() + mHotUserItem);		//이미지만 해당
			}
		break; 
			}

		case VK_SHIFT:
			{
			if(type=="Templete") {
				mCurrentFrame = mHotTemplateItem;
			} if(type=="Image") {
				mCurrentFrame = mHotUserItem;
			}

			CMainFrame* pFrame = (CMainFrame*)AfxGetMainWnd();				//View호출
			CMakoryView* pView = (CMakoryView*)pFrame->GetActiveView();		//View호출
			
		IMGmessage=mUserImages[mCurrentFrame].path.c_str(); //메세지에 index 받아옴
		pView->SelectImage=IMGmessage;

		TEMPmessage=mTemplateImages[mCurrentFrame].index; //메세지에 path받아옴
		if(TEMPmessage=="Cloudy Light Rays") {
			pView->SelectTemplate=1;
		}else if(TEMPmessage=="Dark Stormy") {
			pView->SelectTemplate=2;
		}else if(TEMPmessage=="Full Moon") {
			pView->SelectTemplate=3;
		}else if(TEMPmessage=="Mountain") {
			pView->SelectTemplate=4;
		}else if(TEMPmessage=="Sunset") {
			pView->SelectTemplate=5;
		}else if(TEMPmessage=="Thick Clouds Water") {
			pView->SelectTemplate=6;
		}else if(TEMPmessage=="Tropical Sunny Day") {
			pView->SelectTemplate=7;
		}else if(TEMPmessage=="영사기") {
			pView->SelectTemplate=8;
		}else if(TEMPmessage=="필름") {
			pView->SelectTemplate=9;
		}else if(TEMPmessage=="슬레이트") {
			pView->SelectTemplate=10;
		}else if(TEMPmessage=="파도") {
			pView->SelectTemplate=11;
		}else if(TEMPmessage=="바다속") {
			pView->SelectTemplate=12;
		}else if(TEMPmessage=="낚시") {
			pView->SelectTemplate=13;
		}
			pView->IsItKey=1;
		if(pView->SelectTemplate>=1&&pView->SelectTemplate<=7) {
			pView->BallonStartAnimation();
		}else {
			pView->StartAnimation();
		}
	   break;
		}
	   
	   case VK_SPACE :
		   {
				mCurrentFrame = 0;

			CMainFrame* pFrame = (CMainFrame*)AfxGetMainWnd();				//View호출
			CMakoryView* pView = (CMakoryView*)pFrame->GetActiveView();		//View호출
			
		IMGmessage=mUserImages[mCurrentFrame].path.c_str(); //메세지에 index 받아옴
		pView->SelectImage=IMGmessage;

		TEMPmessage=mTemplateImages[mCurrentFrame].index; //메세지에 path받아옴
		if(TEMPmessage=="Cloudy Light Rays") {
			pView->SelectTemplate=1;
		}else if(TEMPmessage=="Dark Stormy") {
			pView->SelectTemplate=2;
		}else if(TEMPmessage=="Full Moon") {
			pView->SelectTemplate=3;
		}else if(TEMPmessage=="Mountain") {
			pView->SelectTemplate=4;
		}else if(TEMPmessage=="Sunset") {
			pView->SelectTemplate=5;
		}else if(TEMPmessage=="Thick Clouds Water") {
			pView->SelectTemplate=6;
		}else if(TEMPmessage=="Tropical Sunny Day") {
			pView->SelectTemplate=7;
		}else if(TEMPmessage=="영사기") {
			pView->SelectTemplate=8;
		}else if(TEMPmessage=="필름") {
			pView->SelectTemplate=9;
		}else if(TEMPmessage=="슬레이트") {
			pView->SelectTemplate=10;
		}else if(TEMPmessage=="파도") {
			pView->SelectTemplate=11;
		}else if(TEMPmessage=="바다속") {
			pView->SelectTemplate=12;
		}else if(TEMPmessage=="낚시") {
			pView->SelectTemplate=13;
		}
			pView->IsItKey=1;
		if(pView->SelectTemplate>=1&&pView->SelectTemplate<=7) {
			pView->BallonStartAnimation();
		}else {
			pView->StartAnimation();
		}
			break;
		   }
	   

		}
		Invalidate();


	CWnd::OnKeyDown(nChar, nRepCnt, nFlags);
}


void CImageTimelineCtrl::OnTimer(UINT_PTR nIDEvent)
{
		int numTempletes = (int)mTemplateImages.size();
		int numImages = (int)mUserImages.size();
	
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	if (nIDEvent == AUTO_PLAY_TIMER)
     {
          mCurrentFrame++;
          if (mCurrentFrame >= std::min(numImages,numTempletes))
		  {
              KillTimer(AUTO_PLAY_TIMER);
		  }
	}
     else
     {
           CWnd::OnTimer(nIDEvent);
     }
}