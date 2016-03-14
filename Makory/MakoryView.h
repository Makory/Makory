
// MakoryView.h : CMakoryView 클래스의 인터페이스
//

#pragma once


class CMakoryView : public CView
{
protected: // serialization에서만 만들어집니다.
	CMakoryView();
	DECLARE_DYNCREATE(CMakoryView)

// 특성입니다.
public:
	CMakoryDoc* GetDocument() const;

// 작업입니다.
public:

// 재정의입니다.
public:
	virtual void OnDraw(CDC* pDC);  // 이 뷰를 그리기 위해 재정의되었습니다.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 구현입니다.
public:
	virtual ~CMakoryView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // MakoryView.cpp의 디버그 버전
inline CMakoryDoc* CMakoryView::GetDocument() const
   { return reinterpret_cast<CMakoryDoc*>(m_pDocument); }
#endif

