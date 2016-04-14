// ImageCtrl.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "Makory.h"
#include "ImageCtrl.h"
#include "afxdialogex.h"
#include "TimelineCtrl.h"

// CImageCtrl 대화 상자입니다.

IMPLEMENT_DYNAMIC(CImageCtrl, CDialogEx)

CImageCtrl::CImageCtrl(CWnd* pParent /*=NULL*/)
	: CDialogEx(CImageCtrl::IDD, pParent)
{

}

CImageCtrl::~CImageCtrl()
{
}

void CImageCtrl::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LOAD_BUTTON, m_ctrlLoadbutton);
	DDX_Control(pDX, IDC_IMAGELIST, m_ctrlImagelist);
}


BEGIN_MESSAGE_MAP(CImageCtrl, CDialogEx)
	ON_BN_CLICKED(IDC_LOAD_BUTTON, &CImageCtrl::OnBnClickedLoadButton)
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_IMAGE_LIST, &CImageCtrl::OnLvnItemchangedImageList)
	ON_NOTIFY(NM_DBLCLK, IDC_IMAGELIST, &CImageCtrl::OnDblclkImagelist)
END_MESSAGE_MAP()


// CImageCtrl 메시지 처리기입니다.

//로드버튼 클릭시 이벤트
void CImageCtrl::OnBnClickedLoadButton()
{
	//폴더 팝업 띄어서, 절대 경로 받아오기
	ITEMIDLIST  *pidlBrowse;
	LPWSTR        pszPathname[MAX_PATH];
	BROWSEINFO  BrInfo;
	CString m_SelectedFolder; 
	BrInfo.hwndOwner = GetSafeHwnd();
	BrInfo.pidlRoot = NULL;
	memset( &BrInfo, 0, sizeof(BrInfo) );

	BrInfo.pszDisplayName = (LPSTR)pszPathname;

	BrInfo.lpszTitle = "폴더를 선택해 주십시오.";
	BrInfo.ulFlags = BIF_RETURNONLYFSDIRS;

	// 다이얼로그 띄우기
	pidlBrowse = SHBrowseForFolder(&BrInfo);

	if( pidlBrowse != NULL)
	{
		// 선택한 폴더경로를 얻어옴
		BOOL bSuccess = ::SHGetPathFromIDListW(pidlBrowse, *pszPathname);

		if ( bSuccess )
		{
			m_SelectedFolder = (TCHAR)(pszPathname);   //<-- 여기서 값을 입력
			UpdateData(FALSE);
		}
		else
		{
			MessageBox("잘못된 폴더명입니다.", "", MB_OKCANCEL|MB_ICONASTERISK );
		}
	}
}


void CImageCtrl::OnLvnItemchangedImageList(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	*pResult = 0;
}


void CImageCtrl::OnDblclkImagelist(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.


	NM_LISTVIEW* pNMListView = (NM_LISTVIEW*)pNMHDR;
	int index = pNMItemActivate->iItem; // 클릭한 아이템의 인덱스 얻어옴

	std::string path(m_ctrlImagelist.GetImagePathFor(index));
	
	theApp.GetTimelineWnd()->AddImage(index, path);

	*pResult = 0;
}
