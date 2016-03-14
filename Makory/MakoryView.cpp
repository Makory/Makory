
// MakoryView.cpp : CMakoryView 클래스의 구현
//

#include "stdafx.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
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

// CMakoryView 생성/소멸

CMakoryView::CMakoryView()
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CMakoryView::~CMakoryView()
{
}

BOOL CMakoryView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CMakoryView 그리기

void CMakoryView::OnDraw(CDC* /*pDC*/)
{
	CMakoryDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
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


// CMakoryView 진단

#ifdef _DEBUG
void CMakoryView::AssertValid() const
{
	CView::AssertValid();
}

void CMakoryView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMakoryDoc* CMakoryView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMakoryDoc)));
	return (CMakoryDoc*)m_pDocument;
}
#endif //_DEBUG


// CMakoryView 메시지 처리기
