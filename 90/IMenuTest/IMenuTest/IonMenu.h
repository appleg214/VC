#pragma once
#include "afxwin.h"

const int MAX_MENUCOUNT = 60,ITEMHEIGHT = 26,ITEMWIDTH= 120; //�˵�������

struct CMenuItemInfo
{
	CString m_ItemText;
	int m_IconIndex;
	int m_ItemID;
};

class CIonMenu :
	public CMenu
{
public:
	CIonMenu(void);
	virtual ~CIonMenu(void);
	CMenuItemInfo m_ItemList[MAX_MENUCOUNT]; //�˵�����Ϣ
	int m_index;//��ʱ����
	int m_iconindex;//�˵���ͼ������
	CImageList m_imagelist; //�洢�˵���ͼ��

	BOOL CIonMenu::AttachMenu(HMENU m_hmenu);
	BOOL CIonMenu::ChangeMenuItem(CMenu* m_menu, BOOL m_Toped);//�޸Ĳ˵�����Ϣ
	void CIonMenu::MeasureItem(LPMEASUREITEMSTRUCT lpStruct);//����˵����С
	void CIonMenu::DrawItemText(CDC* m_pdc, LPCTSTR str, CRect m_rect);//���Ʋ˵����ı�
	void CIonMenu::DrawMenuIcon(CDC* m_pdc, CRect m_rect, int m_icon);//���Ʋ˵���ͼ��
	void CIonMenu::DrawSeparater(CDC* m_pdc, CRect m_rect);//���Ʒָ���
	void CIonMenu::DrawTopMenu(CDC* m_pdc, CRect m_rect, BOOL m_selected);//���ƶ���˵�
	void CIonMenu::DrawComMenu(CDC* m_pdc,CRect m_rect,COLORREF m_fromcolor,COLORREF m_tocolor, BOOL m_selected);
	void CIonMenu::DrawItem(LPDRAWITEMSTRUCT lpStruct);
};

