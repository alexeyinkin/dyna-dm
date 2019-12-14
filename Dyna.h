/////////////////////////////////////////////////////////////////
//	File:					Dyna.h
//	Application:	Lehasoft Dyna
//	Copyright:		Алексей Инкин, Lehasoft (1996-2002)
/////////////////////////////////////////////////////////////////

#ifndef Lehasoft_Dyna_CDyna_included
#define Lehasoft_Dyna_CDyna_included

#define				MoveStep					30//36

//int				nGameMode;

class CDyna : public CWinApp
{
public:
	CDyna();
	virtual ~CDyna();

	BOOL					ExitInstance();
	BOOL					InitInstance();
	BOOL					OnIdle(LONG lCount);

public:
	int						nTempFPS;
	int						nFPS;
	int						nLastMove;

	DECLARE_MESSAGE_MAP()
};

#endif