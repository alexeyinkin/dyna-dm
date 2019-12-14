/////////////////////////////////////////////////////////////////
//	File:					Dyna.cpp
//	Application:	Lehasoft Dyna
//	Copyright:		Алексей Инкин, Lehasoft (1996-2002)
/////////////////////////////////////////////////////////////////

/*#define welldone

#include "StdAfx.h"
#include "Globals.h"

#ifdef welldone

#include "Bitmap.cpp"
#include "MainFrm.h"

#endif

#include "Dyna.h"*/

#define welldone

#include "StdAfx.h"
#include "Bitmap.h"
//#include "DM.h"
#include "MainFrm.h"
//#include "Bitmap.h"
#include "Dyna.h"

BEGIN_MESSAGE_MAP(CDyna, CWinApp)
END_MESSAGE_MAP()

CDyna theDyna;

/////////////////////////////////////////////////////////////////
//
//	Function:			CDyna::InitInstance()
//
/////////////////////////////////////////////////////////////////

BOOL CDyna::InitInstance()
{
	CBrush				brush(RGB(0, 0, 0));
	CString				str;

	str = AfxRegisterWndClass(NULL, LoadStandardCursor(IDC_ARROW),
		(HBRUSH)brush, LoadIcon(IDI_MAIN));

#ifdef welldone

	//CMainFrame *pMainFrame = new CMainFrame;
	//m_pMainWnd = pMainFrame;
	SetRegistryKey("Lehasoft");
	m_pMainWnd = new CMainFrame;
	m_pMainWnd->CreateEx(
		0,
		str,
		"Lehasoft Dyna",
		//WS_OVERLAPPEDWINDOW | WS_CLIPCHILDREN,
		WS_POPUP,
		(::GetSystemMetrics(SM_CXSCREEN) - 800) / 2,
		(::GetSystemMetrics(SM_CYSCREEN) - 600) / 2,
		800, 600,
		NULL,
		NULL);

	//m_pMainWnd->ShowWindow(SW_SHOW);

#endif
	
	//m_pszRegistryKey = "HKEY_CURRENT_USER\\Software\\mycompany\\myapp\\thissection\\thisvalue";

	CWinApp::InitInstance();
	return 1;
}

/////////////////////////////////////////////////////////////////
//
//	Function:			CDyna::CDyna()
//
/////////////////////////////////////////////////////////////////

CDyna::CDyna()
{
	nLastMove = 0;
}

/////////////////////////////////////////////////////////////////
//
//	Function:			CDyna::~CDyna()
//
/////////////////////////////////////////////////////////////////

CDyna::~CDyna()
{
	//delete m_pMainWnd;
}

/////////////////////////////////////////////////////////////////
//
//	Function:			CDyna::OnIdle()
//
/////////////////////////////////////////////////////////////////

BOOL CDyna::OnIdle(LONG lCount)
{
	CWinApp::OnIdle(lCount);
	if (GetTickCount() > nLastMove + MoveStep)
	{
		nFPS = 1000 / (GetTickCount() - nLastMove);
		nLastMove = GetTickCount();

#ifdef welldone

		((CMainFrame*)m_pMainWnd)->Move();

#endif

	}
	//return CWinApp::OnIdle(lCount);
	return TRUE;
}

/////////////////////////////////////////////////////////////////
//
//	Function:			CDyna::ExitInstance()
//
/////////////////////////////////////////////////////////////////

BOOL CDyna::ExitInstance()
{
	delete m_pMainWnd;
	return CWinApp::ExitInstance();
}