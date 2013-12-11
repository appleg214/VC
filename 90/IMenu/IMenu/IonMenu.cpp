#include "StdAfx.h"
#include "IonMenu.h"
#include "resource.h" 

CIonMenu::CIonMenu(void)
{
	m_index = 0;
	m_iconindex = 0;
	m_imagelist.Create(16,16,ILC_COLOR24|ILC_MASK,0,0);
	m_imagelist.Add(AfxGetApp()->LoadIcon(IDI_ICON1));
	m_imagelist.Add(AfxGetApp()->LoadIcon(IDI_ICON2));
	m_imagelist.Add(AfxGetApp()->LoadIcon(IDI_ICON3));
	m_imagelist.Add(AfxGetApp()->LoadIcon(IDI_ICON4));
	m_imagelist.Add(AfxGetApp()->LoadIcon(IDI_ICON5));
	m_imagelist.Add(AfxGetApp()->LoadIcon(IDI_ICON6));
	m_imagelist.Add(AfxGetApp()->LoadIcon(IDI_ICON7));
	m_imagelist.Add(AfxGetApp()->LoadIcon(IDI_ICON8));
	m_imagelist.Add(AfxGetApp()->LoadIcon(IDI_ICON9));
	m_imagelist.Add(AfxGetApp()->LoadIcon(IDI_ICON10));

}


CIonMenu::~CIonMenu(void)
{
}

BOOL CIonMenu::ChangeMenuItem(CMenu* m_menu, BOOL m_Toped)
{
	if(m_menu!=NULL)
	{
		int m_itemcount = m_menu->GetMenuItemCount();
		for (int i = 0; i< m_itemcount; i++)
		{
			m_menu->GetMenuString(i,m_ItemList[m_index].m_ItemText,MF_BYPOSITION);
			int m_itemID = m_menu->GetMenuItemID(i);
			if(m_itemID == -1 && m_Toped)
			{
				m_itemID = -2;//����˵�
			}
			m_itemID = m_ItemList[m_index].m_ItemID;
			if(m_itemID > 0)
			{
				m_ItemList[m_index].m_IconIndex = m_iconindex;
				m_iconindex += 1;
			}
			m_menu->ModifyMenu(i,MF_OWNERDRAW|MF_BYPOSITION|MF_STRING,m_ItemList[m_index].m_ItemID,(LPCTSTR)&(m_ItemList[m_index]));
			m_index += 1;
			CMenu* m_subMenu = m_menu->GetSubMenu(i);
			if(m_subMenu)
			{
				ChangeMenuItem(m_subMenu,FALSE);
			}
		}
	}
	return TRUE;
}

void CIonMenu::MeasureItem(LPMEASUREITEMSTRUCT lpStruct)
{
	if(lpStruct->CtlType == ODT_MENU)
	{
		lpStruct->itemHeight = ITEMHEIGHT;
		lpStruct->itemWidth = ITEMWIDTH;
		CMenuItemInfo* m_iteminfo;
		m_iteminfo = (CMenuItemInfo*)lpStruct->itemData;
		lpStruct->itemWidth = ((CMenuItemInfo*)lpStruct->itemData)->m_ItemText.GetLength()*10;
		switch(m_iteminfo->m_ItemID)
		{
		case 0: //�ָ���
			{
				lpStruct->itemHeight = 1;
				break;
			}
		}
	}
}

void CIonMenu::DrawItemText(CDC* m_pdc, LPCTSTR str, CRect m_rect)
{
	m_rect.DeflateRect(20,0);
	m_pdc->DrawText(str,m_rect,DT_SINGLELINE|DT_VCENTER|DT_LEFT);
}

void CIonMenu::DrawMenuIcon(CDC* m_pdc, CRect m_rect, int m_icon)
{
	m_imagelist.Draw(m_pdc, m_icon, CPoint(m_rect.left+2,m_rect.top+4),ILD_TRANSPARENT);
}

void CIonMenu::DrawSeparater(CDC* m_pdc, CRect m_rect)
{
	if(m_pdc!=NULL)
	{
		m_pdc->Draw3dRect(m_rect,RGB(255,0,0),RGB(0,0,255));
	}
}

void CIonMenu::DrawTopMenu(CDC* m_pdc, CRect m_rect, BOOL m_selected)
{
	if(m_selected)
	{
		m_pdc->SelectStockObject(BLACK_PEN);
		m_pdc->Rectangle(&m_rect);
		m_rect.DeflateRect(1,1);//��Сһ���
		m_pdc->FillSolidRect(m_rect,RGB(150,185,255));
	}
	else
	{
		CRect rect;
		AfxGetMainWnd()->GetClientRect(rect);
		rect.top = m_rect.top;
		rect.bottom = m_rect.bottom;
		rect.left = 360;
		rect.right += 4;
		m_pdc->FillSolidRect(&rect,RGB(200,187,255));
		m_pdc->FillSolidRect(&m_rect,RGB(200,187,255));
	}
}

void CIonMenu::DrawComMenu(CDC* m_pdc,CRect m_rect,COLORREF m_fromcolor,COLORREF m_tocolor, BOOL m_selected )
{
	if (m_selected)
	{

		m_pdc->Rectangle(m_rect);	 
		m_rect.DeflateRect(1,1);
		int r1,g1,b1; 
		//��ȡ����������ɫֵ
		r1 = GetRValue(m_fromcolor);
		g1 = GetGValue(m_fromcolor);
		b1 = GetBValue(m_fromcolor);
		int r2,g2,b2;


		//��ȡ�����յ����ɫֵ
		r2 = GetRValue(m_tocolor);
		g2 = GetGValue(m_tocolor);
		b2 = GetBValue(m_tocolor);

		float  r3,g3,b3;//�˵�����ˮƽ����ÿ����RGBֵӦ�ñ仯�Ķ�(��Χ)

		r3 = ((float)(r2-r1)) / (float)(m_rect.Height());
		g3 = (float)(g2-g1)/(float)(m_rect.Height());			
		b3 = (float)(b2-b1)/(float)(m_rect.Height());

		COLORREF r,g,b;//�˵�����ˮƽ����ÿ�������ɫֵ
		CPen* m_oldpen ;

		for (int i = m_rect.top;i<m_rect.bottom;i++)
		{
			r = r1+(int)r3*(i-m_rect.top);
			g = g1+(int)g3*(i-m_rect.top);
			b = b1+ (int)b3*(i-m_rect.top);

			CPen m_pen (PS_SOLID,1,RGB(r,g,b));
			m_oldpen = m_pdc->SelectObject(&m_pen);
			m_pdc->MoveTo(m_rect.left,i);
			m_pdc->LineTo(m_rect.right,i);
		}

		m_pdc->SelectObject(m_oldpen);
	}
	else
	{
		m_pdc->FillSolidRect(m_rect,RGB(0x000000F9, 0x000000F8, 0x000000F7));
	}
}

void CIonMenu::DrawItem( LPDRAWITEMSTRUCT lpStruct )
{
	if (lpStruct->CtlType==ODT_MENU)
	{
		if(lpStruct->itemData == NULL)	return;
		unsigned int m_state = lpStruct->itemState;
		CDC* m_dc = CDC::FromHandle(lpStruct->hDC);
		//m_dc.Attach(lpStruct->hDC);

		CString str =  ((CMenuItemInfo*)(lpStruct->itemData))->m_ItemText;
		LPCTSTR m_str = str.GetBuffer(str.GetLength());

		int m_itemID = ((CMenuItemInfo*)(lpStruct->itemData))->m_ItemID;
		int m_itemicon = ((CMenuItemInfo*)(lpStruct->itemData))->m_IconIndex;
		CRect m_rect = lpStruct->rcItem;

		m_dc->SetBkMode(TRANSPARENT);

		switch(m_itemID)
		{
		case -2:
			{

				DrawTopMenu(m_dc,m_rect,(m_state&ODS_SELECTED)||(m_state&0x0040)); //0x0040 ==ODS_HOTLIGHT

				DrawItemText(m_dc,m_str,m_rect);
				break;
			}
		case -1:
			{	
				DrawItemText(m_dc,m_str,m_rect);
				break;
			}
		case 0:
			{
				DrawSeparater(m_dc,m_rect);
				break;
			}
		default:
			{		
				DrawComMenu(m_dc,m_rect,0xfaa0,0xf00ff,m_state&ODS_SELECTED);
				DrawItemText(m_dc,m_str,m_rect);
				DrawMenuIcon(m_dc,m_rect,m_itemicon);
				break;
			}
		}
	}
}

BOOL CIonMenu::AttachMenu(HMENU m_hmenu)
{
	this->Attach(m_hmenu);
	return TRUE;
}