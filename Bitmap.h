/////////////////////////////////////////////////////////////////
//	File:					Bitmap.h
//	Application:	Lehasoft Dyna
//	Copyright:		Алексей Инкин, Lehasoft (1996-2002)
/////////////////////////////////////////////////////////////////

#ifndef Lehasoft_Dyna_CTransparentBitmap_included
#define Lehasoft_Dyna_CTransparentBitmap_included

class CTransparentBitmap
{
public:
	CTransparentBitmap();
	virtual ~CTransparentBitmap();

	bool						Load(UINT				nBmpMain,
											 UINT				nBmpMask,
											 CSize			sz,
											 CPoint			ptClit = CPoint(0, 0),
											 int				nMirrored = 0);

	bool						Mirror(CTransparentBitmap &bmp, int Kind);

	bool						Render(CDC				&dc,
												 CPoint			ptClip,
												 int				nMaskOnly = 0,
												 int				nMirror = 0);

public:
	CBitmap					m_bmpMain;
	CBitmap					m_bmpMask;
	CDC							m_dcMain;
	CDC							m_dcMask;
	CPoint					m_ptClip;
	CSize						m_szSize;

private:
	int							nCreated;
};

#endif