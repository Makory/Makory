// TemplateCtrl.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "Makory.h"
#include "TemplateCtrl.h"
#include "afxdialogex.h"


// CTemplateCtrl ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CTemplateCtrl, CDialogEx)

	CTemplateCtrl::CTemplateCtrl(CWnd* pParent /*=NULL*/)
	: CDialogEx(CTemplateCtrl::IDD, pParent)
{

}

CTemplateCtrl::~CTemplateCtrl()
{
}

void CTemplateCtrl::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TREE, m_ctrlTree);
}


BEGIN_MESSAGE_MAP(CTemplateCtrl, CDialogEx)
	ON_NOTIFY(NM_DBLCLK, IDC_TREE, &CTemplateCtrl::OnDblclkTree)
END_MESSAGE_MAP()


// CTemplateCtrl �޽��� ó�����Դϴ�.


BOOL CTemplateCtrl::OnInitDialog()
{
		SelectTemplate2=1;
	CDialogEx::OnInitDialog();
	//1���� �ʱ�ȭ
	HTREEITEM  hRoot;
	CString Select;
	hRoot = m_ctrlTree.InsertItem("���ø�", 0, 0, TVI_ROOT, TVI_LAST);
	
	//2���� �ʱ�ȭ
	HTREEITEM  htemplate[6];
	CString TemplateName[] = {"���ⱸ", "�ʸ�", "Ocean", "Party", "����", "����"};
	for(int i=0; i<6; i++) {
		htemplate[i]=m_ctrlTree.InsertItem(TemplateName[i], 1, 1, hRoot, TVI_LAST);
	}

	//3���� �ʱ�ȭ
	CString HotAirBallon[] = {"Cloudy Light Rays", "Dark Stormy", "Full Moon", "Mountain", "Sunset", "Thick Clouds Water", "Tropical Sunny Day"};
	for(int i=0; i<7; i++) {
	m_ctrlTree.InsertItem(HotAirBallon[i], 2, 2, htemplate[0], TVI_LAST);
	}
	CString film[] = {"�����", "�ʸ�", "������Ʈ"};
	for(int i=0; i<3; i++) {
	m_ctrlTree.InsertItem(film[i], 2, 2, htemplate[1], TVI_LAST);
	}
	CString Ocean[] = {"�ĵ�", "�ٴټ�", "����"};
	for(int i=0; i<3; i++) {
	m_ctrlTree.InsertItem(Ocean[i], 2, 2, htemplate[2], TVI_LAST);
	}
	CString Party[] = {"�̷���", "����", "�Ǻ�"}; 
	for(int i=0; i<3; i++) {
	m_ctrlTree.InsertItem(Party[i], 2, 2, htemplate[3], TVI_LAST);
	}
	m_ctrlTree.InsertItem("����", 2, 2, htemplate[4], TVI_LAST);
	m_ctrlTree.InsertItem("����", 2, 2, htemplate[5], TVI_LAST);
	
	return TRUE;  // return TRUE unless you set the focus to a control
	// ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
}


void CTemplateCtrl::OnDblclkTree(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.

	CTreeCtrl *pTreeCtrl=(CTreeCtrl *)GetDlgItem(IDC_TREE);
     NM_TREEVIEW* pNMTreeView = (NM_TREEVIEW*)pNMHDR;

	std::string m_Select;

	HTREEITEM hItem = pTreeCtrl->GetSelectedItem();
	m_Select=m_ctrlTree.GetItemText(hItem);

	if(pTreeCtrl->ItemHasChildren(hItem)==0){
		std::string path(m_ctrlImagelist.GetTemplatePathFor(m_Select));
		theApp.GetTimelineWnd()->AddTemplate(m_ctrlTree.GetItemText(hItem), path);
		//MessageBox(m_Select.c_str());
	}
	

	*pResult = 0;
}
