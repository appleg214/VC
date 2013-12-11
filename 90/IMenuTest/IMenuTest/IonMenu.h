#pragma once
#include "afxwin.h"

const int MAX_MENUCOUNT = 60,ITEMHEIGHT = 26,ITEMWIDTH= 120; //菜单项数量

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
	CMenuItemInfo m_ItemList[MAX_MENUCOUNT]; //菜单项信息
	int m_index;//临时索引
	int m_iconindex;//菜单项图标索引
	CImageList m_imagelist; //存储菜单项图标

	BOOL CIonMenu::AttachMenu(HMENU m_hmenu);
	BOOL CIonMenu::ChangeMenuItem(CMenu* m_menu, BOOL m_Toped);//修改菜单项信息
	void CIonMenu::MeasureItem(LPMEASUREITEMSTRUCT lpStruct);//计算菜单项大小
	void CIonMenu::DrawItemText(CDC* m_pdc, LPCTSTR str, CRect m_rect);//绘制菜单项文本
	void CIonMenu::DrawMenuIcon(CDC* m_pdc, CRect m_rect, int m_icon);//绘制菜单项图标
	void CIonMenu::DrawSeparater(CDC* m_pdc, CRect m_rect);//绘制分隔符
	void CIonMenu::DrawTopMenu(CDC* m_pdc, CRect m_rect, BOOL m_selected);//绘制顶层菜单
	void CIonMenu::DrawComMenu(CDC* m_pdc,CRect m_rect,COLORREF m_fromcolor,COLORREF m_tocolor, BOOL m_selected);
	void CIonMenu::DrawItem(LPDRAWITEMSTRUCT lpStruct);
};

