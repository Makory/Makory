#pragma once
#ifdef max
#undef max
#undef min
#endif   //max

#include <vector>

// CImageTimelineCtrl

class CImageTimelineCtrl : public CWnd
{
   DECLARE_DYNAMIC(CImageTimelineCtrl)

public:
   CImageTimelineCtrl();
   virtual ~CImageTimelineCtrl();

   void AddImgThumbnail(int index, const std::string& path);
   void AddTempThumbnail(CString index, const std::string& path);

   bool IsRecordable() const;
   bool InitiateRecording();
   void OnAnimationFinished();
   int smaller;

protected:
   DECLARE_MESSAGE_MAP()
   afx_msg int OnCreate(CREATESTRUCT* createStruct);
   afx_msg void OnSize(UINT type, int cx, int cy);
   afx_msg void OnDestroy();
   afx_msg void OnHScroll(UINT, UINT, CScrollBar*);
   afx_msg void OnLButtonDown(UINT, CPoint point);
   afx_msg void OnLButtonUp(UINT, CPoint point);
   afx_msg void OnCaptureChanged(CWnd* capturingWnd);
   afx_msg void OnMouseMove(UINT flags, CPoint point);
   afx_msg BOOL OnEraseBkgnd(CDC* dc);
   afx_msg void OnPaint();
   int worldWidth;

   void AnimateNextFrame();
   void SetupViewAnimationData();
   bool UpdateHotItem(CPoint point);
   void UpdateScrollParameters();

   struct TemplateItem
   {
      TemplateItem& operator=(const TemplateItem& templateItem)
      {
         index = templateItem.index;
         path = templateItem.path;
         bitmap = templateItem.bitmap;
         return *this;
      }

      CString index;
      std::string path;
      Gdiplus::Bitmap* bitmap;

   };

   struct ImageItem
   {
      ImageItem& operator=(const ImageItem& imageItem)
      {
         index = imageItem.index;
         path = imageItem.path;
         bitmap = imageItem.bitmap;
         return *this;
      }

      int index;
      std::string path;
      Gdiplus::Bitmap* bitmap;
   };
public:
   std::vector<TemplateItem> mTemplateImages;
   std::vector<ImageItem> mUserImages;
   int mHotTemplateItem;
   int itemIndex;
   int mHotUserItem;

public:
   afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
   CString IMGmessage;
   CString TEMPmessage;
   CString selectmessage;
   int NonTitle;
   int sel;
   float CurrentImage;
   int mCurrentFrame;

private:
   void StartDragging(CPoint point);
   void EnsureVisible(int index);
   CString type;
   CPoint Select;
   void PlayCurrentFrame();

   bool mDragEntered;
   CImageList mDragIcon;
public:
   afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
   afx_msg void OnTimer(UINT_PTR nIDEvent);
};

