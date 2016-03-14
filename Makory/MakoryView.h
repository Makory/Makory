
// MakoryView.h : CMakoryView Ŭ������ �������̽�
//

#pragma once


class CMakoryView : public CView
{
protected: // serialization������ ��������ϴ�.
	CMakoryView();
	DECLARE_DYNCREATE(CMakoryView)

// Ư���Դϴ�.
public:
	CMakoryDoc* GetDocument() const;

// �۾��Դϴ�.
public:

// �������Դϴ�.
public:
	virtual void OnDraw(CDC* pDC);  // �� �並 �׸��� ���� �����ǵǾ����ϴ�.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// �����Դϴ�.
public:
	virtual ~CMakoryView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ������ �޽��� �� �Լ�
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // MakoryView.cpp�� ����� ����
inline CMakoryDoc* CMakoryView::GetDocument() const
   { return reinterpret_cast<CMakoryDoc*>(m_pDocument); }
#endif
