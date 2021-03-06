
// MakoryView.h : CMakoryView 클래스의 인터페이스
//

#pragma once

#include "HotAirBalloon.h"
#include "Film.h"
#include "Ocean.h"
#include "BmpToArray.h"
#include "ImageTimelineCtrl.h"

class CMainFrame;
class CMakoryDoc;

class CMakoryView : public CView
{
protected: // serialization에서만 만들어집니다.
	CMakoryView();
	DECLARE_DYNCREATE(CMakoryView)

public:
	HDC m_hDC; // GDI Device Context
	HGLRC m_hglRC;// Rendering Context

	void InitGL();
	void ReSizeGLScene(GLsizei width, GLsizei height);
	void DrawGLTitle(int SelectTemplate);
	void DrawGLScene(int SelectSky);
	void BalloonAnimation();
	void ProjectorAnimation();
	void FilmAnimation();
	void SlateAnimation();
	void WaveAnimation();
	void OceanAnimation();
	void FishingAnimation();
	BOOL SetPixelformat(HDC hdc);

	void StartAnimation();
	void BallonStartAnimation();
	void UpdateBalloonData();
	void Initialization();
	void BallonInitialization();

	// 카메라 변수 설정:
	GLfloat pos[3];
	GLfloat lookAt[3];
	GLfloat upVec[3];

	//카메라움직임 변수와 함수:
	GLfloat lookVec[3];
	void LookVec();

	GLfloat leftVec[3];
	void LeftVec();

	HotAirBalloon HotAirBalloon;
	Film Film;
	Ocean Ocean;
	BmpToArray BmpToArray;
	CImageTimelineCtrl* ImageTimeline;
	CMainFrame* MainFrm;
	
	int SelectTemplate;
	CString SelectImage;

	double x;
	double y;
	double y1;
	double z;
	double r;
	double r1;
	double time;

	double filmimgscale;
	double projimgscale;
	double slateimgscale;
	double spacescale;
	double fishingimgscale;
	int IsItKey;
	int ExportNum;

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
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

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
public:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnDestroy();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	public:

};

#ifndef _DEBUG  // MakoryView.cpp의 디버그 버전
inline CMakoryDoc* CMakoryView::GetDocument() const
   { return reinterpret_cast<CMakoryDoc*>(m_pDocument); }
#endif

