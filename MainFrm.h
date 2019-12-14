/////////////////////////////////////////////////////////////////
//	File:					MainFrm.h
//	Application:	Lehasoft Dyna
//	Copyright:		Алексей Инкин, Lehasoft (1996-2002)
/////////////////////////////////////////////////////////////////

#ifndef Lehasoft_Dyna_MainFrame_included
#define Lehasoft_Dyna_MainFrame_included

//#define	Abs(a)		(a < 0) ? (-a) : (a)


class CDM : public CDialog
{
public:
	CDM();
	virtual ~CDM();

	bool				GetDMInfo(int					&nTexture,
												float				&fPrizes,
												float				&fMonsters,
												float				&fFullness,
												int					&nPlayerCount,
												int					&nComp,
												int					&nWithSkulls/*,
												int					&nRandomTexture*/);

	BOOL				OnInitDialog();

	void				OnHScroll(UINT				nSBCode,
												UINT				nPos,
												CScrollBar	*pScrollBar);

	void				OnOK();

public:
	enum {IDD = IDD_DEATHMATCH};

private:
	int				mnTexture;
	float			mfPrizes;
	float			mfMonsters;
	float			mfFullness;
	int				mnPlayerCount;
	int				mnComp;
	int				mnWithSkulls;
	//int				mnRandomTexture;


	DECLARE_MESSAGE_MAP()
};




#define				SnakeLen			6

struct Player
{
	int					nBombCount;
	int					nBombSet;
	int					nBombFlameSize;
	//int					nLastFlameSize;
	//int					nLastBombCount;
	//int					nDeepFlameSize;
	//int					nDeepBombCount;
	//float				fDeepSpeed;
	int					nScores;
	int					nComp;

	float				fDone;
	CPoint			pt;
	int					nRoll;
	float				fSpeed;
	//float				fLastSpeed;
	int					nDirection;
	int					nMoveDirection;
	int					nFlying;
	int					nPhase;
	int					nLife;
	int					nFrags;
	//int					nContinues;
	int					nKind;
	int					nEnter;
	int					nFuckBombs;
	int					nIllness;
	int					nIllnessLeft;

	int					nUpPressed;
	int					nDownPressed;
	int					nLeftPressed;
	int					nRightPressed;
	int					nBombPressed;
	int					nBlowPressed;
	int					nKeyDirection;

	int					nUpKey;
	int					nDownKey;
	int					nLeftKey;
	int					nRightKey;
	int					nBombKey;
	int					nBlowKey;
};

struct Cell
{
	int					nTexture;
	int					nBrick;
	int					nFlamePhase;
	int					nFlameDirection;
	int					nExit;
	//int					nExitVisible;
	//int					nBlink;
};

struct Bomb
{
	CPoint			pt;
	int					nTimeLeft;
	int					nRealTimeLeft;
	int					nSource;
	int					nFlameLen;
};

struct Monster
{
	CPoint			pt;
	int					nKind;
	int					nDirection;
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

/*struct FlyingNumber
{
	CPoint			pt;
	int					nTimeLeft;
	int					nNumber;
};*/

struct Snake
{
	Monster			components[SnakeLen];
	int					nLifes[SnakeLen];
	int					nLive;
};


#define				PlayMode						0
#define				Pause								1
#define				MainMenu						2

#define				SurvivingMode				0
#define				FragMode						1

#define				PlayerPhases				8
#define				PlayerKinds					4
#define				MaxPlayerCount			4

//#define				LevelCount					8
//#define				RoundCount					8

#define				ScreenSize					13
#define				CellSize						40
#define				FireSize						20
#define				FlameSize						92
#define				PeasesSize					80
#define				FireStartX					33
#define				FireEndX						19
#define				FireStartY					0
#define				FireEndY						10
#define				Width								560
#define				Height							560
#define				NumberWidth					16
#define				NumberHeight				24
//#define				PlayerQuitsWidth		80
#define				IndicatorWidth			167//180
#define				IndicatorHeight			209//260
#define				IndicatorLeft				28//10
#define				IndicatorTop				349//Height - IndicatorHeight
#define				GameX								220
#define				GameY								5
#define				BorderWidth					20
//#define				WallWidth						20
//#define				WallLen							65
#define				MaxSize							ScreenSize * 3

#define				Button1X						10
#define				Button1Y						249
#define				Button2X						106
#define				Button2Y						249
#define				ButtonWidth					86
#define				ButtonHeight				90

//#define				BombInterval				75

#define				BackgroundCount			30
#define				TexturesCount				3
#define				FireCount						3
#define				FlameCount					10
#define				WaterPhases					10
//#define				IndicatorCount			6
#define				MonsterCount				11
//#define				CycleMonsterCount		20
//#define				NoBackMonsterCount	3
#define				MonsterPhases				6
#define				MonsterCompletePhases			10
//#define				MonsterCycle				6
//#define				SnakePhases					10
//#define				SnakePictures				6
//#define				MaxSnakeCount				5
//#define				ExitCount						21
//#define				ExitCycle						7
#define				PeasesCount					6
#define				PeasesPhases				20
//#define				PlayerQuitsPhases		15
#define				ButtonCount					4
#define				CaptionCount				2
//#define				ArrowCount					10
//#define				ArrowPictures				6
#define				PrizeCount					3

#define				MaxBombCount				20
#define				MaxMonsterCount			30
#define				MaxPeasesCount			20

//#define				PlayerSpeed					0.1;

//#define				KilledAll()					monsters[0].nKind == -1


//int					nGameMode;

class CMainFrame : public CWnd//CWnd
{
public:
	CMainFrame();
	virtual ~CMainFrame();

	int										Abs(int								a);

	void									AddDMMonster(int			&nPoints);

	bool									AddDMPrize();

	bool									AddFire(CPoint				pt,
																int						nDirection,
																//int						nCenter,
																int						nSource);

	/*void									AddNumber(CPoint			pt,
																	int					nDirection,
																	float				fDone,
																	int					nNumber,
																	int					nTimeLeft = 25);*/

	void									AddPease(CPoint				pt,
																 int					nDirection,
																 float				fDone);

	bool									AddPrize(int					nKind,
																 int					nAlwaysWisible);

	void									Blow(Bomb							bomb/*,
														 int							nNoSort = 0*/);

	//void									BlowExit(CPoint				pt);

	bool									CanLocate(CPoint			pt,
																	int					nFlying);

	void									CheckMonster(Monster	&monster);

	void									ChangeIllness(Player	&player,
																			int			nNewIllness);

	void									CleanBrick(CPoint			pt);

	void									CreatePlayer(Player		&player,
																		 int			nID,
																		 int			nComp,
																		 CPoint		pt = CPoint(0, 0),
																		 int			Scores = 0);

	//void									DeepRevert(Player			&player);

	void									Die(int								nPlayerID,
														int								nFrom);

	BOOL									ExitInstance();

	void									Fail(int							nCode);

	int										FindPath(CPoint				ptStart,
																 CPoint				ptEnd[],
																 int					nEndCount,
																 int					nFlying,
																 int					nFindEx,
																 int					nRandomOnFail,
																 int					nMaxLen = 0,
																 int					nObject = -1,
																 int					nGetLen = 0);

	void									GenerateLevel(float		Fullness);

	int										GetDirection(CPoint		ptStart,
																		 CPoint		ptEnd);

	int										GetSafetyArea(CPoint	pt,
																			int			nAfter = 0,
																			int			nFlying = 0,
																			float		fSpeed = 0,
																			int			nDanger = -1,
																			int			nMaxArea = -1);

	int										InDanger(CPoint				pt,
																 int					nFromBombs,
																 int					nFromMonsters,
																 int					nAfter = 0);

	int										KeepOut(CPoint				pt,
																int						nFlying,
																int						nLen,
																int						nFromBombs,
																int						nFromMonsters,
																float					fSpeed,
																int						nExtra = 0);

	//bool									KilledAll();

	void									LoadLevel(/*int					nLevel,
																	int					nRound*/);

	void									Move();
	
	CPoint								MoveByDirection(CPoint	pt,
																				int			Direction);

	void									MoveCompPlayer(Player	&player,
																			 int		nID);

	bool									OnBomb(CPoint					pt);

	int										OnCreate(LPCREATESTRUCT);

	void									OnDestroy();

	void									OnKeyDown(UINT				nChar,
																	UINT				nRepCnt,
																	UINT				nFlags);

	void									OnKeyUp(UINT					nChar,
																UINT					nRepCnt,
																UINT					nFlags);

	void									OnLButtonDown(UINT		nFlags,
																			CPoint	pt);

/*	void									OnLButtonUp(UINT			nFlags,
																		CPoint		pt);*/

	void									OnMouseMove(UINT			nFlags,
																		CPoint		pt);

	BOOL									OnMouseWheel(UINT			nFlags,
																		 short		zDelta,
																		 CPoint		pt);

	void									OnPaint();

	void									OrderMonster(Monster	&monster);

	void									PaintBomb(CDC					&dc,
																	Bomb				&bomb);

	void									PaintGame();

	void									PaintIndicators(CDC		&dc,
																				CPoint);

	void									PaintMonster(CDC			&dc,
																		 //CPoint		ptd,
																		 CPoint		pt,
																		 int			nKind,
																		 int			nPhase,
																		 int			nDirection,
																		 float		fDone);

	void									PaintPease(CDC				&dc,
																	 //CPoint			ptd,
																	 CPoint			pt,
																	 int				nPhase);

	void									PaintPlayer(Player		&player,
																		CDC				&dc);

	/*void									PaintSnake(Snake			snake,
																	 CDC				&dc,
																	 CPoint			ptd);*/

	void									RenderNumber(CString	strNumber,
																		 CDC			&dc,
																		 CPoint		pt);

	void									Repaint(CDC						&dc);

	//void									RevertPlayer(Player		&player);

	bool									Restart(/*int						nPlayerCount*/);

	int										SetBomb(CPoint				pt,
																int						nSource,
																int						nFlameLen,
																int						nTimeLeft);

	void									SetButtonID(int				nID);

	//void									SetExitAvialable();

	void									SetMonster(int				nKind,
																	 CPoint			pt = CPoint(-1, -1));

	//void									SortBombs();

	void									SortMonsters();

	void									SortPeases();

	void									SubMovePlayer(Player	&player,
																			int			nID);

	void									Swap(int							&a,
														 int							&b);
	
	int										DirectionDiff(int			Direction1,
																	 int				Direction2);

	bool									ValidPt(CPoint				pt);

	void									Win();

	int										WrapDirection(int			Direction);

public:
	/*CBitmapButton					cmdSingle;
	CBitmapButton					cmdDM;
	CButton								cmd;*/

	CBitmap								bmpLeft;
	
	/*CBitmap								bmpHWall;
	CBitmap								bmpVWall;
	CBitmap								bmpTRWall;
	CBitmap								bmpTLWall;
	CBitmap								bmpBRWall;
	CBitmap								bmpBLWall;*/
	CBitmap								bmpHardWall;
	//CBitmap								bmpIndicators[IndicatorCount];
	//CBitmap								bmpExit[ExitCount];
	CBitmap								bmpIndicatorPanelClear;
	CBitmap								bmpMain;
	CBitmap								bmpButtons[ButtonCount][2];
	CBitmap								bmpPrizes[PrizeCount];
	CBitmap								bmpCaptions[CaptionCount];
	//CBitmap								bmpWater[WaterPhases];

	CBitmap								bmpTextures[BackgroundCount][TexturesCount];
	CTransparentBitmap		bmpBricks[BackgroundCount][TexturesCount];
	CTransparentBitmap		bmpBomb;
	CTransparentBitmap		bmpFire[FireCount];
	CTransparentBitmap		bmpFlame[2][FlameCount];
	CTransparentBitmap		bmpNumbers[10 + 1];
	CTransparentBitmap		bmpMonsters[MonsterCount][MonsterPhases];
	//CTransparentBitmap		bmpCycleMonsters[CycleMonsterCount][MonsterCycle];
	//CTransparentBitmap		bmpNoBackMonsters[NoBackMonsterCount][MonsterPhases];
	CTransparentBitmap		bmpPeases[PeasesCount];
	//CTransparentBitmap		bmpPlayerQuits[PlayerQuitsPhases];
	//CTransparentBitmap		bmpSnake[4][3][3][SnakePictures];	//	orientation, part, color, phase
	//CTransparentBitmap		bmpArrows[ArrowPictures];

	CDC										dcIndicatorPanel;
	CBitmap								bmpIndicatorPanel;

	Cell									Area[MaxSize][MaxSize];
	CSize									sz;
	//CPoint								ptd;
	CPoint								ptPlayers[MaxPlayerCount];
	CPoint								ptBricks[MaxSize * MaxSize];
	CPoint								ptPlayerQuits;
	CPoint								ptBlowExit;
	//int										nLevel;
	//int										nRound;
	int										nBackgroundID;
	int										nBombCount;
	int										nBombPhase;
	//int										nExitPhase;
	//int										nExitAvialable;
	//int										nArrowPhase;
	int										nCreated;
	int										nTimeLeft;
	int										nGameMode;
	int										nDieTime;
	int										nWinTime;
	int										nBlowExitTime;
	int										nPlayerCount;
	int										nBrickCount;
	int										nButtonID;
	int										nButtonChanged;
	int										nWins[MaxPlayerCount];
	int										nDeadPlayer;
	int										nWaterPhase;
	int										nLastWinner;
	int										nShowFPS;
	int										nRandomTexture;
	int										nCountMode;
	int										BombInterval;
	int										nSlow;
	//int										nMonsterTable[Width][Height];
	float									fPlayerSpeed;

	int										nDMBackground;
	float									fDMMonsters;
	float									fDMPrizes;
	float									fDMFullness;
	int										nDMComp;
	int										nDMWithSkulls;
	int										nDMPlayerCount;

	//Player								p1;
	Player								players[MaxPlayerCount];
	Bomb									bombs[MaxBombCount];
	Monster								monsters[MaxMonsterCount];
	//Snake									snakes[MaxSnakeCount];
	Pease									peases[MaxPeasesCount];
	//FlyingNumber					numbers[MaxPeasesCount];

	CTransparentBitmap		bmpPlayer[PlayerKinds][3][PlayerPhases];

	DEVMODE								devOld;
	DEVMODE								devNew;

	DECLARE_MESSAGE_MAP()
};

#endif