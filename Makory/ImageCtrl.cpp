// ImageCtrl.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "Makory.h"
#include "ImageCtrl.h"
#include "afxdialogex.h"
#include "TimelineCtrl.h"
#include "MainFrm.h"
#include "MakoryDoc.h"
#include "MakoryView.h"
#include "Imagelist.h"

// CImageCtrl 대화 상자입니다.

IMPLEMENT_DYNAMIC(CImageCtrl, CDialogEx)

CImageCtrl::CImageCtrl(CWnd* pParent /*=NULL*/)
	: CDialogEx(CImageCtrl::IDD, pParent)
{
	//이미지 아이콘 생성 
	m_largeIcon2 = new CImageList;
	//(50,50은 크기임)
	m_largeIcon2->Create(50, 50, ILC_MASK|ILC_COLORDDB, 5, 5);
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

BOOL CImageCtrl::OnInitDialog()
{
	BOOL ret = CDialogEx::OnInitDialog();

	m_ctrlImagelist.Init();

	return ret;
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
	//------------------1-----------------
	/*
	BROWSEINFO bInfo;
	bInfo.hwndOwner = GetSafeHwnd();
	bInfo.pidlRoot = NULL;
	bInfo.ulFlags = BIF_RETURNONLYFSDIRS;
	CString m_Filedir; //파일 경로 저장
	
	memset(&bInfo, 0, sizeof(bInfo));

	LPITEMIDLIST path;
	path = SHBrowseForFolder(&bInfo);    //폴더선택대화상자


	TCHAR szpathName[200];
	SHGetPathFromIDList( path, szpathName );    //선택폴더경로가져오기
	m_Filedir = szpathName;


	if (path != nullptr)

	{

		CoTaskMemFree(path);

	}
	CFileFind find;  
	CString FileName; //파일명
	CString PathName; //파일의 절대경로
	int ind;

	bool is_found = find.FindFile(m_Filedir+"\\*.bmp");     //일단 비트맵만

	//한번 해당 폴더에 파일 있는지 확인 후  
	//파일이 존재하면 폴더 내에 파일들을 전부다 확인할때까지 while 수행  
	while(is_found)  
	{         
		//다음 파일이 존재하느냐 정보 얻고  
		is_found = find.FindNextFile();  
		//. 또는 .. 인지 확인 후 그런건 넘기고  
 		if(find.IsDots()) continue;   

		PathName = find.GetFilePath(); //선택된 파일의 절대경로
		FileName = find.GetFileName(); //선택된 파일의 파일명,확장자
		CString fileExtension = find.GetFileName();
		ind = fileExtension.ReverseFind('bmp'); 

		m_ctrlImagelist.AddItem(PathName);


	} */
	//----------------------------------------------------------------------------------
	//--------------2--------------------------------------------------------------------


	//static TCHAR BASED_CODE szFilter[] = _T("이미지 파일(*.BMP, *.GIF, *.JPG) |	*.BMP;*.GIF;*.JPG;*.bmp;*.jpg;*.gif |모든파일(*.*)|*.*||");

	//비트맵 파일만 보이도록 함
	static TCHAR BASED_CODE szFilter[] = _T("이미지 파일(*.BMP) |*.BMP;|모든파일(*.*)|*.*||");
	CFileDialog dlg(TRUE,NULL, NULL, OFN_FILEMUSTEXIST||OFN_ALLOWMULTISELECT, szFilter);
	
	dlg.m_ofn.Flags |= OFN_NOCHANGEDIR;
	dlg.m_ofn.Flags |= OFN_ALLOWMULTISELECT;

	char fileBuffer[10000] = {0};
	int selectedCount=0;
	POSITION StartPosition;
	StartPosition = dlg.GetStartPosition();

	if(IDOK == dlg.DoModal())

	{
		while(StartPosition){
         
			CString pathName = dlg.GetNextPathName(StartPosition); //선택한 파일 경로얻어옴
			CString FileName = dlg.GetFileName();
			m_ctrlImagelist.AddItem(pathName);
		}
	}
	
	//------------------------------------------------------------------------------------------
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
