/////////////////////////////////////////////////////////////////
//	File:					Globals.h
//	Application:	Lehasoft Dyna
//	Copyright:		Алексей Инкин, Lehasoft (1996-2002)
/////////////////////////////////////////////////////////////////

/*#include "StdAfx.h"
#include "Globals.h"*/

#include "StdAfx.h"
#include "Globals.h"

int DynaMessageBox(LPCTSTR strPrompt, UINT nFlags)
{
	return MessageBox(NULL, strPrompt, "Lehasoft Dyna", nFlags);
}