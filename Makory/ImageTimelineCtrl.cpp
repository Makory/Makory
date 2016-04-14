// ImageTimelineCtrl.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "Makory.h"
#include "ImageTimelineCtrl.h"
#include "MainFrm.h"
#include "MakoryDoc.h"
#include "MakoryView.h"

using namespace Gdiplus;

int FIXED_WIDTH = 100;
static const int ICON_MARGIN = 5;
int ScrollWidth =0;

IMPLEMENT_DYNAMIC(CImageTimelineCtrl, CWnd)

CImageTimelineCtrl::CImageTimelineCtrl()
{
	mHitTemplateItem = -1;
	mHitUserItem = -1;
	NonTitle=0;
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

	Invalidate();
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
	ON_WM_LBUTTONDBLCLK()
END_MESSAGE_MAP()

int CImageTimelineCtrl::OnCreate(CREATESTRUCT* createStruct)
{
	CWnd::OnCreate(createStruct);

	return 0;
}

void CImageTimelineCtrl::OnDestroy()
{
	int numImages = (int)mTemplateImages.size();
	for (int i = 0; i < numImages; ++i)
	{
		delete mTemplateImages[i].bitmap;
	}
	numImages = (int)mUserImages.size();
	for (int i = 0; i < numImages; ++i)
	{
		delete mUserImages[i].bitmap;
	}

	CWnd::OnDestroy();
}

void CImageTimelineCtrl::UpdateScrollParameters()
{
	CRect clientRect;
	GetClientRect(&clientRect);
	int viewWidth = clientRect.Width();

	int maxNum = std::max((int)mTemplateImages.size(), (int)mUserImages.size());
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
	ScrollWidth=si.nPos;	//��ũ�� ���� ����

	si.fMask = SIF_POS;
	SetScrollInfo(SB_HORZ, &si, TRUE);

	Invalidate();
}

void CImageTimelineCtrl::OnLButtonDown(UINT, CPoint point)		//���� Ŭ���� �ٽñ׸���
{
	
	Invalidate();

	CRect itemRect;

	mHitTemplateItem = -1;
	mHitUserItem = -1;

	CRect rect;
	GetClientRect(&rect);

	int availableHeight = rect.Height();
	availableHeight -= ICON_MARGIN;
	int halfHeight = availableHeight / 2;

	itemRect.left = ICON_MARGIN-ScrollWidth;							//���� �׸�
	itemRect.top = ICON_MARGIN;
	itemRect.right = itemRect.left + FIXED_WIDTH;
	itemRect.bottom = itemRect.top + halfHeight;

	int numImages = (int)mTemplateImages.size();
	for (int i = 0; i < numImages; ++i)
	{
		if (itemRect.PtInRect(point))
		{
			mHitTemplateItem = i;
			return;
		}

		itemRect.OffsetRect(FIXED_WIDTH + ICON_MARGIN, 0);
	}

	itemRect.top = itemRect.bottom + ICON_MARGIN;			//�Ʒ��� �׸�
	itemRect.left = ICON_MARGIN-ScrollWidth;					//ScrollWidth �߰��Ͽ� ��ũ�� �Ŀ��� ����� ���� �ǰԲ� ��. ������ ��ũ�� �̵��ϸ� ���� �簢���� ��ũ�Ѹ�ŭ �̵��� ������
	itemRect.right = itemRect.left + FIXED_WIDTH;
	itemRect.bottom = itemRect.top + halfHeight;

	numImages = (int)mUserImages.size();
	for (int i = 0; i < numImages; ++i)
	{
		if (itemRect.PtInRect(point))
		{
			mHitUserItem = i;
			return;
		}

		itemRect.OffsetRect(FIXED_WIDTH + ICON_MARGIN, 0);
	}
}

BOOL CImageTimelineCtrl::OnEraseBkgnd(CDC* dc)		//�ٽñ׸���
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
		graphics.Clear(Gdiplus::Color(255, 255, 255));	//������

		int horzPos = GetScrollPos(SB_HORZ);
		Gdiplus::Matrix mat;
		graphics.GetTransform(&mat);

		graphics.TranslateTransform((float)-horzPos, 0);

		Gdiplus::Pen borderPen(Gdiplus::Color(0, 0, 255), 10);	//���û�

		int availableHeight = rect.Height();
		availableHeight -= ICON_MARGIN;
		int halfHeight = availableHeight / 2;

		Gdiplus::Rect imageRect;
		Gdiplus::Rect BorderRect;

		imageRect.X = ICON_MARGIN;		//���� ���� �̹���
		imageRect.Y = ICON_MARGIN;
		imageRect.Height = halfHeight;
		imageRect.Width = halfHeight/3*4;
		FIXED_WIDTH=imageRect.Width;

		int numImages = (int)mTemplateImages.size();
		for (int i = 0; i < numImages; ++i)
		{
			Bitmap* bitmap = mTemplateImages[i].bitmap;

			graphics.DrawImage(bitmap, imageRect);

			if (i == mHitTemplateItem)
			{
				graphics.DrawRectangle(&borderPen, imageRect);		//���� ����
			}
			imageRect.X += FIXED_WIDTH + ICON_MARGIN;
		}


		imageRect.X = ICON_MARGIN;							//���� �Ʒ��� �̹���
		imageRect.Y += imageRect.Height + ICON_MARGIN;
		imageRect.Height = halfHeight;
		numImages = (int)mUserImages.size();
		
		BorderRect.X = ICON_MARGIN+FIXED_WIDTH;							//���� �Ʒ��� ����
		BorderRect.Y += imageRect.Height + ICON_MARGIN;
		BorderRect.Height = halfHeight;
		BorderRect.Width = halfHeight/3*4;

		for (int i = 0; i < numImages; ++i)
		{
			Bitmap* bitmap = mUserImages[i].bitmap;
			graphics.DrawImage(bitmap, imageRect);

			if (i == mHitUserItem)
			{
				graphics.DrawRectangle(&borderPen, imageRect);		//�Ʒ��� ����
			}

			imageRect.X += FIXED_WIDTH + ICON_MARGIN;
		}

		graphics.SetTransform(&mat);
	}
	 
	dc.BitBlt(0, 0, rect.Width(), rect.Height(), &dcMem, 0, 0, SRCCOPY);

	dcMem.SelectObject(oldSurface);
}

//Ÿ�Ӷ��� ���� Ŭ�������� �̺�Ʈ(��ΰ� �޾ƿ���)
void CImageTimelineCtrl::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	Invalidate();
	
	CMainFrame* pFrame = (CMainFrame*)AfxGetMainWnd();				//Viewȣ��
	CMakoryView* pView = (CMakoryView*)pFrame->GetActiveView();		//Viewȣ��

	CRect itemRect;

	mHitTemplateItem = -1;
	mHitUserItem = -1;
	NonTitle=1;

	CRect rect;
	GetClientRect(&rect);

	int availableHeight = rect.Height();
	availableHeight -= ICON_MARGIN;
	int halfHeight = availableHeight / 2;
	int numImages = (int)mTemplateImages.size();
	
	itemRect.left = ICON_MARGIN-ScrollWidth;							//���� �׸�
	itemRect.top = ICON_MARGIN;
	itemRect.right = itemRect.left + FIXED_WIDTH;
	itemRect.bottom = itemRect.top + halfHeight;

	//���ø�
	for (int i = 0; i < numImages; ++i)
	{
		if (itemRect.PtInRect(point))
		{
			mHitTemplateItem = i;
			TEMPmessage=mTemplateImages[i].index; //�޼����� path�޾ƿ�
			//MessageBox(TEMPmessage);
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
			pView->Invalidate();
			

			return;
		}

		itemRect.OffsetRect(FIXED_WIDTH + ICON_MARGIN, 0);
	}

	
	//�̹���
	itemRect.top = itemRect.bottom + ICON_MARGIN;			//�Ʒ��� �׸�
	itemRect.left = ICON_MARGIN-ScrollWidth;					//ScrollWidth �߰��Ͽ� ��ũ�� �Ŀ��� ����� ���� �ǰԲ� ��. ������ ��ũ�� �̵��ϸ� ���� �簢���� ��ũ�Ѹ�ŭ �̵��� ������
	itemRect.right = itemRect.left + FIXED_WIDTH;
	itemRect.bottom = itemRect.top + halfHeight;

	numImages = (int)mUserImages.size();

	for (int i = 0; i < numImages; ++i)
	{
		if (itemRect.PtInRect(point))
		{
			mHitUserItem = i; //�ּ� Ǫ���� �簢�� ǥ�õ�
			IMGmessage0=mUserImages[i].index; //�޼����� path�޾ƿ�
			CString IMGmessage;
			IMGmessage.Format("%d" , IMGmessage0);
			//MessageBox(IMGmessage);

			pView->SelectTemplate=1;
			pView->Invalidate();
			return;
		}

		itemRect.OffsetRect(FIXED_WIDTH + ICON_MARGIN, 0);
	}

	
	CWnd::OnLButtonDblClk(nFlags, point);
}
