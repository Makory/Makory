// ImageCtrl.cpp : ���� �����Դϴ�.
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

// CImageCtrl ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CImageCtrl, CDialogEx)

CImageCtrl::CImageCtrl(CWnd* pParent /*=NULL*/)
	: CDialogEx(CImageCtrl::IDD, pParent)
{
	//�̹��� ������ ���� 
	m_largeIcon2 = new CImageList;
	//(50,50�� ũ����)
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


// CImageCtrl �޽��� ó�����Դϴ�.

//�ε��ư Ŭ���� �̺�Ʈ
void CImageCtrl::OnBnClickedLoadButton()
{
	//------------------1-----------------
	/*
	BROWSEINFO bInfo;
	bInfo.hwndOwner = GetSafeHwnd();
	bInfo.pidlRoot = NULL;
	bInfo.ulFlags = BIF_RETURNONLYFSDIRS;
	CString m_Filedir; //���� ��� ����
	
	memset(&bInfo, 0, sizeof(bInfo));

	LPITEMIDLIST path;
	path = SHBrowseForFolder(&bInfo);    //�������ô�ȭ����


	TCHAR szpathName[200];
	SHGetPathFromIDList( path, szpathName );    //����������ΰ�������
	m_Filedir = szpathName;


	if (path != nullptr)

	{

		CoTaskMemFree(path);

	}
	CFileFind find;  
	CString FileName; //���ϸ�
	CString PathName; //������ ������
	int ind;

	bool is_found = find.FindFile(m_Filedir+"\\*.bmp");     //�ϴ� ��Ʈ�ʸ�

	//�ѹ� �ش� ������ ���� �ִ��� Ȯ�� ��  
	//������ �����ϸ� ���� ���� ���ϵ��� ���δ� Ȯ���Ҷ����� while ����  
	while(is_found)  
	{         
		//���� ������ �����ϴ��� ���� ���  
		is_found = find.FindNextFile();  
		//. �Ǵ� .. ���� Ȯ�� �� �׷��� �ѱ��  
 		if(find.IsDots()) continue;   

		PathName = find.GetFilePath(); //���õ� ������ ������
		FileName = find.GetFileName(); //���õ� ������ ���ϸ�,Ȯ����
		CString fileExtension = find.GetFileName();
		ind = fileExtension.ReverseFind('bmp'); 

		m_ctrlImagelist.AddItem(PathName);


	} */
	//----------------------------------------------------------------------------------
	//--------------2--------------------------------------------------------------------


	//static TCHAR BASED_CODE szFilter[] = _T("�̹��� ����(*.BMP, *.GIF, *.JPG) |	*.BMP;*.GIF;*.JPG;*.bmp;*.jpg;*.gif |�������(*.*)|*.*||");

	//��Ʈ�� ���ϸ� ���̵��� ��
	static TCHAR BASED_CODE szFilter[] = _T("�̹��� ����(*.BMP) |*.BMP;|�������(*.*)|*.*||");
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
         
			CString pathName = dlg.GetNextPathName(StartPosition); //������ ���� ��ξ���
			CString FileName = dlg.GetFileName();
			m_ctrlImagelist.AddItem(pathName);
		}
	}
	
	//------------------------------------------------------------------------------------------
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
