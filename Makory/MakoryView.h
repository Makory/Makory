
// MakoryView.h : CMakoryView Ŭ������ �������̽�
//

#pragma once

#include "HotAirBalloon.h"
#include "BmpToArray.h"
#include "ImageTimelineCtrl.h"

class CMakoryView : public CView
{
protected: // serialization������ ��������ϴ�.
	CMakoryView();
	DECLARE_DYNCREATE(CMakoryView)
	

	//����� ����
public:
	HDC m_hDC; // GDI Device Context
	HGLRC m_hglRC;// Rendering Context

	void InitGL();
	void ReSizeGLScene(GLsizei width, GLsizei height);
	void CMakoryView::DrawGLTitle();
	void CMakoryView::DrawGLScene(int SelectSky);
	BOOL SetPixelformat(HDC hdc);

	// ī�޶� ���� ����:
	GLfloat pos[3];
	GLfloat lookAt[3];
	GLfloat upVec[3];

	//ī�޶������ ������ �Լ�:
	GLfloat lookVec[3];
	void LookVec();

	GLfloat leftVec[3];
	void LeftVec();

	HotAirBalloon HotAirBalloon;
	BmpToArray BmpToArray;
	CImageTimelineCtrl* ImageTimeline;
	
	int SelectTemplate;

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
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

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
public:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnDestroy();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
};

#ifndef _DEBUG  // MakoryView.cpp�� ����� ����
inline CMakoryDoc* CMakoryView::GetDocument() const
   { return reinterpret_cast<CMakoryDoc*>(m_pDocument); }
#endif

