
// MakoryView.cpp : CMakoryView Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
#ifndef SHARED_HANDLERS
#include "Makory.h"
#endif

#include "MakoryDoc.h"
#include "MakoryView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMakoryView

IMPLEMENT_DYNCREATE(CMakoryView, CView)

BEGIN_MESSAGE_MAP(CMakoryView, CView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CMakoryView ����/�Ҹ�

CMakoryView::CMakoryView()
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.

}

CMakoryView::~CMakoryView()
{
}

BOOL CMakoryView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return CView::PreCreateWindow(cs);
}

// CMakoryView �׸���

void CMakoryView::OnDraw(CDC* /*pDC*/)
{
	CMakoryDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: ���⿡ ���� �����Ϳ� ���� �׸��� �ڵ带 �߰��մϴ�.
}

void CMakoryView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMakoryView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMakoryView ����

#ifdef _DEBUG
void CMakoryView::AssertValid() const
{
	CView::AssertValid();
}

void CMakoryView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMakoryDoc* CMakoryView::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMakoryDoc)));
	return (CMakoryDoc*)m_pDocument;
}
#endif //_DEBUG


// CMakoryView �޽��� ó����
