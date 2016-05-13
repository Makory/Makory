// TemplateCtrl.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "Makory.h"
#include "TemplateCtrl.h"
#include "afxdialogex.h"


// CTemplateCtrl 대화 상자입니다.

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


// CTemplateCtrl 메시지 처리기입니다.


BOOL CTemplateCtrl::OnInitDialog()
{
		SelectTemplate2=1;
	CDialogEx::OnInitDialog();
	//1레벨 초기화
	HTREEITEM  hRoot;
	CString Select;
	hRoot = m_ctrlTree.InsertItem("템플릿", 0, 0, TVI_ROOT, TVI_LAST);
	
	//2레벨 초기화
	HTREEITEM  htemplate[6];
	CString TemplateName[] = {"열기구", "필름", "Ocean", "Party", "낙서", "편지"};
	for(int i=0; i<6; i++) {
		htemplate[i]=m_ctrlTree.InsertItem(TemplateName[i], 1, 1, hRoot, TVI_LAST);
	}

	//3레벨 초기화
	CString HotAirBallon[] = {"Cloudy Light Rays", "Dark Stormy", "Full Moon", "Mountain", "Sunset", "Thick Clouds Water", "Tropical Sunny Day"};
	for(int i=0; i<7; i++) {
	m_ctrlTree.InsertItem(HotAirBallon[i], 2, 2, htemplate[0], TVI_LAST);
	}
	CString film[] = {"영사기", "필름", "슬레이트"};
	for(int i=0; i<3; i++) {
	m_ctrlTree.InsertItem(film[i], 2, 2, htemplate[1], TVI_LAST);
	}
	CString Ocean[] = {"파도", "바다속", "낚시"};
	for(int i=0; i<3; i++) {
	m_ctrlTree.InsertItem(Ocean[i], 2, 2, htemplate[2], TVI_LAST);
	}
	CString Party[] = {"미러볼", "음파", "악보"}; 
	for(int i=0; i<3; i++) {
	m_ctrlTree.InsertItem(Party[i], 2, 2, htemplate[3], TVI_LAST);
	}
	m_ctrlTree.InsertItem("낙서", 2, 2, htemplate[4], TVI_LAST);
	m_ctrlTree.InsertItem("편지", 2, 2, htemplate[5], TVI_LAST);
	
	return TRUE;  // return TRUE unless you set the focus to a control
	// 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}


void CTemplateCtrl::OnDblclkTree(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

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
