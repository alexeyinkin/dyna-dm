/////////////////////////////////////////////////////////////////
//	File:					Globals.h
//	Application:	Lehasoft Dyna
//	Copyright:		Алексей Инкин, Lehasoft (1996-2002)
/////////////////////////////////////////////////////////////////

#ifndef Lehasoft_Dyna_Globals_included
#define Lehasoft_Dyna_Globals_included

#define				SnakeLen			6

struct Player
{
	int					BombCount;
	int					BombSet;
	int					FlameSize;
	int					FlameSize2;
	int					Scores;

	float				Done;
	CPoint			pt;
	int					Roll;
	float				Speed;
	int					Target;
	int					MoveTarget;
	int					Flying;
	int					Phase;
	int					nLife;
	int					nContinues;
	int					nKind;

	int					UpPressed;
	int					DownPressed;
	int					LeftPressed;
	int					RightPressed;
	int					BombPressed;
	int					BlowPressed;
	int					KeyTarget;

	char				UpKey;
	char				DownKey;
	char				LeftKey;
	char				RightKey;
	char				BombKey;
	char				BlowKey;
};

struct Cell
{
	int					nBlink;
	int					nBlink2;
	int					nTexture;
	int					nBrick;
	int					nFlamePhase;
	int					nFlameTarget;
	int					nExit;
	int					nExitVisible;
};

struct Bomb
{
	CPoint			pt;
	int					nTimeLeft;
	int					nSource;
	int					nFlameLen;
};

struct Monster
{
	CPoint			pt;
	int					nKind;
	int					nTarget;
	int					nPhase;
	float				fDone;
	float				fSpeed;
	int					nFlying;
	float				fTurn;
};

struct Pease
{
	CPoint			pt;
	int					nPhase;
};

struct Snake
{
	Monster			components[SnakeLen];
	int					nLifes[SnakeLen];
	int					nLive;
};

int						DynaMessageBox(LPCTSTR strPrompt,
														 UINT nFlags = MB_OK | MB_ICONINFORMATION);

#endif