/////////////////////////////////////////////////////////////////
//	File:					Bitmap.cpp
//	Application:	Lehasoft Dyna
//	Copyright:		Алексей Инкин, Lehasoft (1996-2002)
/////////////////////////////////////////////////////////////////

/*#include "StdAfx.h"
//#include "Dyna.h"
#include "Globals.h"
#include "Bitmap.h"*/

#include "StdAfx.h"
#include "Bitmap.h"

/////////////////////////////////////////////////////////////////
//
//	Function:			CTransparentBitmap::CTransparentBitmap()
//
/////////////////////////////////////////////////////////////////

CTransparentBitmap::CTransparentBitmap()
{
	nCreated = 0;
}

/////////////////////////////////////////////////////////////////
//
//	Function:			CTransparentBitmap::~CTransparentBitmap()
//
/////////////////////////////////////////////////////////////////

CTransparentBitmap::~CTransparentBitmap()
{
}

/////////////////////////////////////////////////////////////////
//
//	Function:			CTransparentBitmap::Load()
//
/////////////////////////////////////////////////////////////////

bool CTransparentBitmap::Load(UINT			nBmpMain,
															UINT			nBmpMask,
															CSize			sz,
															CPoint		ptClip,
															int				nMirrored)
{
	//m_szSize = m_bmpMain.GetBitmapDimension();
	
	//m_bmpMain.CreateBitmap(m_szSize.cx, m_szSize.cy, 1, 24, NULL);
	//m_bmpMask.CreateBitmap(m_szSize.cx, m_szSize.cy, 1, 1, NULL);
	
	if (nCreated == 0)
	{
		m_dcMain.CreateCompatibleDC(AfxGetMainWnd()->GetWindowDC());
		m_dcMask.CreateCompatibleDC(AfxGetMainWnd()->GetWindowDC());
	}

	if (nCreated)
	{
		m_bmpMain.Detach();
		m_bmpMask.Detach();
		m_bmpMain.DeleteObject();
		m_bmpMask.DeleteObject();
	}

	if (nCreated == 0)
	{
		nCreated = 1;
		//m_bmpMain.Detach();
		//m_bmpMask.Detach();
	}
	//m_szSize = m_bmpMain.GetBitmapDimension();
	
	/*if (nCreated)
	{
		m_bmpMain.Detach();
		m_bmpMask.Detach();
	}*/

	if (!m_bmpMain.LoadBitmap(nBmpMain))
	{
		return false;
	}
	if (!m_bmpMask.LoadBitmap(nBmpMask))
	{
		return false;
	}
	m_dcMain.SelectObject(&m_bmpMain);
	m_dcMask.SelectObject(&m_bmpMask);
	
	//m_szSize = m_bmpMain.GetBitmapDimension();
	switch (nMirrored)
	{
	case 1:
		// horisontal
		m_dcMain.StretchBlt(sz.cx - 1, 0, -sz.cx, sz.cy, &m_dcMain,
			0, 0, sz.cx, sz.cy, SRCCOPY);
		m_dcMask.StretchBlt(sz.cx - 1, 0, -sz.cx, sz.cy, &m_dcMask,
			0, 0, sz.cx, sz.cy, SRCCOPY);
		break;
	case 2:
		// vertical
		m_dcMain.StretchBlt(0, sz.cy - 1, sz.cx, -sz.cy, &m_dcMain,
			0, 0, sz.cx, sz.cy, SRCCOPY);
		m_dcMask.StretchBlt(0, sz.cy - 1, sz.cx, -sz.cy, &m_dcMask,
			0, 0, sz.cx, sz.cy, SRCCOPY);
		break;
	}
	m_szSize = sz;
	m_ptClip = ptClip;
	return true;
}

/////////////////////////////////////////////////////////////////
//
//	Function:			CTransparentBitmap::Render()
//
/////////////////////////////////////////////////////////////////

bool CTransparentBitmap::Render(CDC			&dc,
																CPoint	ptClip,
																int			nMaskOnly,
																int			nMirror)
{
	switch (nMirror)
	{
	case 0:
		if (!dc.BitBlt(ptClip.x - m_ptClip.x, ptClip.y - m_ptClip.y,
			m_szSize.cx, m_szSize.cy, &m_dcMask, 0, 0, SRCAND))
		{
			return false;
		}
		if (nMaskOnly == 0)
		{
			if (!dc.BitBlt(ptClip.x - m_ptClip.x, ptClip.y - m_ptClip.y,
				m_szSize.cx, m_szSize.cy, &m_dcMain, 0, 0, SRCPAINT))
			{
				return false;
			}
		}
		break;
	case 1:		//	horizontal
		if (!dc.StretchBlt(ptClip.x - m_ptClip.x + m_szSize.cx - 1,
			ptClip.y - m_ptClip.y, -m_szSize.cx, m_szSize.cy,
			&m_dcMask, 0, 0, m_szSize.cx, m_szSize.cy, SRCAND))
		{
			return false;
		}
		if (nMaskOnly == 0)
		{
			if (!dc.StretchBlt(ptClip.x - m_ptClip.x + m_szSize.cx - 1,
				ptClip.y - m_ptClip.y, -m_szSize.cx, m_szSize.cy,
				&m_dcMain, 0, 0, m_szSize.cx, m_szSize.cy, SRCPAINT))
			{
				return false;
			}
		}
		break;
	case 2:		//	vertical
		if (!dc.StretchBlt(ptClip.x - m_ptClip.x,
			ptClip.y - m_ptClip.y + m_szSize.cy - 1, m_szSize.cx, -m_szSize.cy,
			&m_dcMask, 0, 0, m_szSize.cx, m_szSize.cy, SRCAND))
		{
			return false;
		}
		if (nMaskOnly == 0)
		{
			if (!dc.StretchBlt(ptClip.x - m_ptClip.x,
				ptClip.y - m_ptClip.y + m_szSize.cy - 1, m_szSize.cx, -m_szSize.cy,
				&m_dcMain, 0, 0, m_szSize.cx, m_szSize.cy, SRCPAINT))
			{
				return false;
			}
		}
		break;
	}
	return true;
}

/////////////////////////////////////////////////////////////////
//
//	Function:			CTransparentBitmap::Mirror()
//
/////////////////////////////////////////////////////////////////

bool CTransparentBitmap::Mirror(CTransparentBitmap &bmp, int Kind)
{
	Load(0, 0, bmp.m_szSize);
	switch (Kind)
	{
	case 1:
		if (!m_dcMain.StretchBlt(0, 0, m_szSize.cx, m_szSize.cy, &bmp.m_dcMain,
			0, 0, -m_szSize.cx, m_szSize.cy, SRCCOPY))
		{
			return false;
		}
		break;
	case 2:
		if (!m_dcMain.StretchBlt(0, 0, m_szSize.cx, m_szSize.cy, &bmp.m_dcMain,
			0, 0, m_szSize.cx, -m_szSize.cy, SRCCOPY))
		{
			return false;
		}
		break;
	default:
		return false;
	}
	return true;
}