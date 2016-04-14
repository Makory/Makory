// ImageCtrl.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "Makory.h"
#include "ImageCtrl.h"
#include "afxdialogex.h"
#include "TimelineCtrl.h"

// CImageCtrl ��ȭ �����Դϴ�.

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


// CImageCtrl �޽��� ó�����Դϴ�.

//�ε��ư Ŭ���� �̺�Ʈ
void CImageCtrl::OnBnClickedLoadButton()
{
	//���� �˾� ��, ���� ��� �޾ƿ���
	ITEMIDLIST  *pidlBrowse;
	LPWSTR        pszPathname[MAX_PATH];
	BROWSEINFO  BrInfo;
	CString m_SelectedFolder; 
	BrInfo.hwndOwner = GetSafeHwnd();
	BrInfo.pidlRoot = NULL;
	memset( &BrInfo, 0, sizeof(BrInfo) );

	BrInfo.pszDisplayName = (LPSTR)pszPathname;

	BrInfo.lpszTitle = "������ ������ �ֽʽÿ�.";
	BrInfo.ulFlags = BIF_RETURNONLYFSDIRS;

	// ���̾�α� ����
	pidlBrowse = SHBrowseForFolder(&BrInfo);

	if( pidlBrowse != NULL)
	{
		// ������ ������θ� ����
		BOOL bSuccess = ::SHGetPathFromIDListW(pidlBrowse, *pszPathname);

		if ( bSuccess )
		{
			m_SelectedFolder = (TCHAR)(pszPathname);   //<-- ���⼭ ���� �Է�
			UpdateData(FALSE);
		}
		else
		{
			MessageBox("�߸��� �������Դϴ�.", "", MB_OKCANCEL|MB_ICONASTERISK );
		}
	}
}


void CImageCtrl::OnLvnItemchangedImageList(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	*pResult = 0;
}


void CImageCtrl::OnDblclkImagelist(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.


	NM_LISTVIEW* pNMListView = (NM_LISTVIEW*)pNMHDR;
	int index = pNMItemActivate->iItem; // Ŭ���� �������� �ε��� ����

	std::string path(m_ctrlImagelist.GetImagePathFor(index));
	
	theApp.GetTimelineWnd()->AddImage(index, path);

	*pResult = 0;
}
