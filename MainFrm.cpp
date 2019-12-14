/////////////////////////////////////////////////////////////////
//	File:					MainFrm.cpp
//	Application:	Lehasoft Dyna
//	Copyright:		Алексей Инкин, Lehasoft (1996-2002)
/////////////////////////////////////////////////////////////////


#include "StdAfx.h"
#include "Bitmap.h"
#include "MainFrm.h"
#include "Dyna.h"

BEGIN_MESSAGE_MAP(CDM, CDialog)
	ON_WM_HSCROLL()		//	Будем реагировать на события горизонтальных полос прокрутки
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////
//
//	Function:			CDM::CDM()
//
/////////////////////////////////////////////////////////////////

CDM::CDM() : CDialog(CDM::IDD)
{
}

/////////////////////////////////////////////////////////////////
//
//	Function:			CDM::~CDM()
//
/////////////////////////////////////////////////////////////////

CDM::~CDM()
{
}

/////////////////////////////////////////////////////////////////
//
//	Function:			CDM::OnInitDialog()
//
/////////////////////////////////////////////////////////////////

BOOL CDM::OnInitDialog()
{
	CListBox			*lst;
	CScrollBar		*scrollbar;
	CButton				*checkbox;

	lst = (CListBox*)GetDlgItem(IDC_TEXTURES);
	
	lst->AddString("Трава");
	lst->AddString("Болото");
	lst->AddString("Лес");
	lst->AddString("Горы");
	lst->AddString("Доски");
	lst->AddString("Подвал");
	lst->AddString("Пустыня");
	lst->AddString("Техника");
	lst->AddString("Доллары");
	lst->AddString("Цветы");
	lst->AddString("Космос");
	lst->AddString("Шахматы");
	lst->AddString("Система");
	lst->AddString("Пляж");
	lst->AddString("Джунгли");
	lst->AddString("Море");
	lst->AddString("Lehasoft");
	lst->AddString("Карты");
	lst->AddString("Кубики");
	lst->AddString("Хвойный лес");
	lst->AddString("Кости");
	lst->AddString("Нью-Йорк");
	lst->AddString("Завтрак");
	lst->AddString("Поле");
	lst->AddString("Коровы");
	lst->AddString("Мухоморы");
	lst->AddString("Туалет");
	lst->AddString("Радиация");
	lst->AddString("Часы");
	lst->AddString("Травка");
	lst->AddString("(случайная)");
	
	lst->SetCurSel(mnTexture);

	scrollbar = (CScrollBar*)GetDlgItem(IDC_PRIZES);
	scrollbar->SetScrollRange(0, 100, false);
	scrollbar->SetScrollPos(mfPrizes * 100);

	scrollbar = (CScrollBar*)GetDlgItem(IDC_MONSTERS);
	scrollbar->SetScrollRange(0, 100, false);
	scrollbar->SetScrollPos(mfMonsters * 100);

	scrollbar = (CScrollBar*)GetDlgItem(IDC_FULLNESS);
	scrollbar->SetScrollRange(0, 80, false);
	scrollbar->SetScrollPos(mfFullness * 100);

	scrollbar = (CScrollBar*)GetDlgItem(IDC_PLAYERS);
	scrollbar->SetScrollRange(2, 4, false);
	scrollbar->SetScrollPos(mnPlayerCount);
	char str[2];
	str[0] = scrollbar->GetScrollPos() + 48;
	str[1] = 0;
	SetDlgItemText(IDC_PLAYERSOUT, str);

	checkbox = (CButton*)GetDlgItem(IDC_COMP);
	checkbox->SetCheck(mnComp);

	checkbox = (CButton*)GetDlgItem(IDC_SKULLS);
	checkbox->SetCheck(mnWithSkulls);

	return CDialog::OnInitDialog();
}

/////////////////////////////////////////////////////////////////
//
//	Function:			CDM::GetDMInfo()
//
/////////////////////////////////////////////////////////////////

bool CDM::GetDMInfo(int				&nTexture,
										float			&fPrizes,
										float			&fMonsters,
										float			&fFullness,
										int				&nPlayerCount,
										int				&nComp,
										int				&nWithSkulls/*,
										int				&nRandomTexture*/)
{
	mnTexture				= nTexture;
	mfPrizes				= fPrizes;
	mfMonsters			= fMonsters;
	mfFullness			= fFullness;
	mnPlayerCount		=	nPlayerCount;
	mnComp					= nComp;
	mnWithSkulls		= nWithSkulls;
	//mnRandomTexture	= nRandomTexture;
	
	if (DoModal() == IDCANCEL)
	{
		return false;
	}

	nTexture				= mnTexture;
	fPrizes					= mfPrizes;
	fMonsters				= mfMonsters;
	fFullness				= mfFullness;
	nPlayerCount		=	mnPlayerCount;
	nComp						= mnComp;
	nWithSkulls			= mnWithSkulls;
	//nRandomTexture	= mnRandomTexture;
	return true;
}

/////////////////////////////////////////////////////////////////
//
//	Function:			CDM::OnHScroll()
//
/////////////////////////////////////////////////////////////////

void CDM::OnHScroll(UINT				nSBCode,
										UINT				nPos,
										CScrollBar	*pScrollBar)
{
	CScrollBar		*scrollbar;
	//pScrollBar->SetScrollPos(nPos + pScrollBar->GetScrollPos());
	//scrollbar = (CScrollBar*)GetDlgItem(IDC_PLAYERS)
	switch (nSBCode)
	{
	case SB_LEFT:
		pScrollBar->SetScrollPos(0);
		break;
	case SB_LINELEFT:
		pScrollBar->SetScrollPos(pScrollBar->GetScrollPos() - 1);
		break;
	case SB_LINERIGHT:
		pScrollBar->SetScrollPos(pScrollBar->GetScrollPos() + 1);
		break;
	case SB_PAGELEFT:
		pScrollBar->SetScrollPos(pScrollBar->GetScrollPos() - 20);
		break;
	case SB_PAGERIGHT:
		pScrollBar->SetScrollPos(pScrollBar->GetScrollPos() + 20);
		break;
	case SB_RIGHT:
		pScrollBar->SetScrollPos(100);
		break;
	case SB_THUMBPOSITION:
	case SB_THUMBTRACK:
		pScrollBar->SetScrollPos(nPos);
		break;
	}
	
	scrollbar = (CScrollBar*)GetDlgItem(IDC_PLAYERS);
	char str[2];
	str[0] = scrollbar->GetScrollPos() + 48;
	str[1] = 0;
		
	SetDlgItemText(IDC_PLAYERSOUT, str);

	CDialog::OnHScroll(nSBCode, nPos, pScrollBar);
}

/////////////////////////////////////////////////////////////////
//
//	Function:			CDM::OnOK()
//
/////////////////////////////////////////////////////////////////

void CDM::OnOK()
{
	CListBox			*lst;
	CScrollBar		*scrollbar;
	CButton				*checkbox;

	lst = (CListBox*)GetDlgItem(IDC_TEXTURES);
	
	scrollbar = (CScrollBar*)GetDlgItem(IDC_PRIZES);
	mfPrizes = (float)scrollbar->GetScrollPos() / 100.0;

	scrollbar = (CScrollBar*)GetDlgItem(IDC_MONSTERS);
	mfMonsters = (float)scrollbar->GetScrollPos() / 100.0;

	scrollbar = (CScrollBar*)GetDlgItem(IDC_FULLNESS);
	mfFullness = (float)scrollbar->GetScrollPos() / 100.0;

	scrollbar = (CScrollBar*)GetDlgItem(IDC_PLAYERS);
	mnPlayerCount = scrollbar->GetScrollPos();

	checkbox = (CButton*)GetDlgItem(IDC_COMP);
	mnComp = checkbox->GetCheck();

	checkbox = (CButton*)GetDlgItem(IDC_SKULLS);
	mnWithSkulls = checkbox->GetCheck();
	
	mnTexture = lst->GetCurSel();
	CDialog::OnOK();
}







//#define		WithSnake

BEGIN_MESSAGE_MAP(CMainFrame, CWnd)//CWnd)
	ON_WM_CREATE()
	ON_WM_DESTROY()
	ON_WM_KEYDOWN()
	ON_WM_KEYUP()
	ON_WM_PAINT()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_WM_MOUSEWHEEL()
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////
//
//	Function:			CMainFrame::CMainFrame()
//
/////////////////////////////////////////////////////////////////

CMainFrame::CMainFrame()
{
	bmpLeft.LoadBitmap(IDB_LEFT);
	nBombPhase = 0;
	//nArrowPhase = 0;
	nCreated = 0;
	nWaterPhase = 0;
	nShowFPS = 0;
	nButtonID = 0;
	nButtonChanged = 0;
	//bmpRight.LoadBitmap(IDB_RIGHT);
}

/////////////////////////////////////////////////////////////////
//
//	Function:			CMainFrame::~CMainFrame()
//
/////////////////////////////////////////////////////////////////

CMainFrame::~CMainFrame()
{
}

/////////////////////////////////////////////////////////////////
//
//	Function:			CMainFrame::OnDestroy()
//
/////////////////////////////////////////////////////////////////

void CMainFrame::OnDestroy()
{
	CWinApp			*theApp;
	theApp = AfxGetApp();
	
	/*
	theApp->WriteProfileInt("1.0", "DM_Texture", nDMBackground);
	theApp->WriteProfileInt("1.0", "DM_Prizes", fDMPrizes * 100);
	theApp->WriteProfileInt("1.0", "DM_Monsters", fDMMonsters * 100);
	theApp->WriteProfileInt("1.0", "DM_Fullness", fDMFullness * 100);
	*/
	
	ChangeDisplaySettings(&devOld, 0);
	CWnd::OnDestroy();
	delete this;
	//delete (AfxGetApp())->m_pMainWnd;
}

/////////////////////////////////////////////////////////////////
//
//	Function:			CMainFrame::OnPaint()
//
/////////////////////////////////////////////////////////////////

void CMainFrame::OnPaint()
{
	CClientDC			dc(this);
	//CDC						*pdc;

	//pdc = GetWindowDC();
	dc.DrawState(0, 0, &bmpLeft, DST_BITMAP);
	//PaintGame();
	CWnd::OnPaint();
	if (nCreated == 0)
	{
		dcIndicatorPanel.BitBlt(0, 0, IndicatorWidth, IndicatorHeight,
			&dc, IndicatorLeft, IndicatorTop, SRCCOPY);
	}
	nCreated = 1;
}

/////////////////////////////////////////////////////////////////
//
//	Function:			CMainFrame::OnCreate()
//
/////////////////////////////////////////////////////////////////

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	int				i, j, k;
	int				nResult;
	CSize			msz;

	msz = CSize(CellSize, CellSize);
	nResult = CWnd::OnCreate(lpCreateStruct);

	BombInterval = 75;
	fPlayerSpeed = .1;
	nSlow = 0;


	//nExitPhase = 0;
	//nGameMode = MainMenu;
	/*if (!Restart())
	{
		PostQuitMessage(0);
		return 0;
	}*/

	EnumDisplaySettings(NULL, ENUM_REGISTRY_SETTINGS, &devOld);
	devNew = devOld;
	devNew.dmPelsWidth = 800;
	devNew.dmPelsHeight = 600;
	ChangeDisplaySettings(&devNew, 0);

	bmpHardWall.LoadBitmap(IDB_HARDWALL);
	bmpBomb.Load(5111, 5101, msz);
	
	bmpIndicatorPanelClear.LoadBitmap(IDB_INDICATORS);
	bmpMain.LoadBitmap(IDB_MAIN);

	//bmpIndicatorPanel.LoadBitmap(IDB_INDICATORS);

	bmpIndicatorPanel.CreateCompatibleBitmap(GetWindowDC(),
		IndicatorWidth, IndicatorHeight);
	dcIndicatorPanel.CreateCompatibleDC(GetWindowDC());
	dcIndicatorPanel.SelectObject(&bmpIndicatorPanel);

//#ifdef WithSnake
/*	for (i = 0; i < 3; i++)										//	part
	{
		for (j = 0; j < 3; j++)									//	color
		{

#ifdef WithSnake			

			for (k = 0; k < SnakePictures; k++)		//	phase
			{
				bmpSnake[1][i][j][k].Load(7710 + 100 * i + j * 10 + k,
					7700 + i * 100 + k, msz);
				bmpSnake[2][i][j][k].Load(7750 + 100 * i + j * 10 + k,
					7740 + i * 100 + k, msz);
				bmpSnake[0][i][j][k].Load(7750 + 100 * i + j * 10 + k,
					7740 + i * 100 + k, msz, CPoint(0, 0), 2);
				bmpSnake[3][i][j][k].Load(7710 + 100 * i + j * 10 + k,
					7700 + i * 100 + k, msz, CPoint(0, 0), 1);
			}

#else
			k = 0;
			bmpSnake[1][i][j][k].Load(7710 + 100 * i + j * 10 + k,
				7700 + i * 100 + k, msz);
			bmpSnake[2][i][j][k].Load(7750 + 100 * i + j * 10 + k,
				7740 + i * 100 + k, msz);
			bmpSnake[0][i][j][k].Load(7750 + 100 * i + j * 10 + k,
				7740 + i * 100 + k, msz, CPoint(0, 0), 2);
			bmpSnake[3][i][j][k].Load(7710 + 100 * i + j * 10 + k,
				7700 + i * 100 + k, msz, CPoint(0, 0), 1);

#endif

		}
	}
//#endif*/

	/*for (i = 0; i < WaterPhases; i++)
	{
		bmpWater[i].LoadBitmap(3900 + i);
	}*/

	for (i = 0; i < CaptionCount; i++)
	{
		bmpCaptions[i].LoadBitmap(5300 + i);
	}

	for (i = 0; i < PrizeCount; i++)
	{
		bmpPrizes[i].LoadBitmap(5200 + i);
	}

	/*for (i = 0; i < ArrowPictures; i++)
	{
		bmpArrows[i].Load(5110 + i, 5100 + i, msz);
	}*/

	for (i = 0; i < BackgroundCount; i++)
	{
		for (j = 0; j < TexturesCount; j++)
		{
			bmpTextures[i][j].LoadBitmap(2000 + 100 * i + j);
			bmpBricks[i][j].Load(2020 + 100 * i + j, 2010 + 100 * i + j,
				msz);
		}
	}

	/*for (i = 0; i < PlayerQuitsPhases; i++)
	{
		bmpPlayerQuits[i].Load(7510 + i % 10 + i / 10 * 100,
			7500 + i % 10 + i / 10 * 100, CSize(PlayerQuitsWidth, PlayerQuitsWidth),
			CPoint(CellSize / 2, 0));
	}*/

	for (i = 0; i < ButtonCount; i++)
	{
		for (j = 0; j < 2; j++)
		{
			bmpButtons[i][j].LoadBitmap(7400 + i * 10 + j);
		}
	}
	//nButtonID = 0;

	for (i = 0; i < PeasesCount; i++)
	{
		bmpPeases[i].Load(7310 + i, 7300 + i, CSize(PeasesSize, PeasesSize));
	}

	for (i = 0; i < MonsterCount; i++)
	{
		for (j = 0; j < MonsterPhases; j++)
		{
			bmpMonsters[i][j].Load(8010 + i * 100 + j, 8000 + i * 100 + j,
				CSize(CellSize, CellSize));
		}
	}
	/*for (i = 0; i < CycleMonsterCount; i++)
	{
		for (j = 0; j < MonsterCycle; j++)
		{
			bmpCycleMonsters[i][j].Load(8010 + i * 100 + j, 8000 + i * 100 + j,
				msz);
		}
	}
	for (i = 0; i < NoBackMonsterCount; i++)
	{
		for (j = 0; j < MonsterPhases; j++)
		{
			bmpNoBackMonsters[i][j].Load(11010 + i * 100 + j, 11000 + i * 100 + j,
				msz);
		}
	}*/

	/*for (i = 0; i < ExitCount; i++)
	{
		bmpExit[i].LoadBitmap(7200 + i);
	}

	for (i = 0; i < IndicatorCount; i++)
	{
		bmpIndicators[i].LoadBitmap(7100 + i);
	}*/
	for (i = 0; i < 10; i++)
	{
		//ASSERT(bmpNumbers[i].Load(7010 + i, 7000 + i, CPoint(NumberWidth, NumberHeight)));
		if (!bmpNumbers[i].Load(7010 + i, 7000 + i, CPoint(NumberWidth, NumberHeight)))
		{
			Fail(1);
		}
	}
	bmpNumbers[10].Load(7021, 7020, CSize(NumberWidth, NumberHeight));
	for (i = 0; i < FlameCount; i++)
	{
		if (!bmpFlame[0][i].Load(6110 + i, 6100 + i, CSize(FlameSize, FlameSize),
			CPoint(26, 36)))
		{
			Fail(1);
		}
		if (!bmpFlame[1][i].Load(6210 + i, 6200 + i, CSize(FlameSize, FlameSize),
			CPoint(26, 36)))
		{
			Fail(1);
		}
		/*if (!bmpFlame[2][i].Load(6110 + i, 6100 + i, CSize(FlameSize, FlameSize),
			CPoint(26, 36), 2))
		{
			Fail(1);
		}
		if (!bmpFlame[3][i].Load(6210 + i, 6200 + i, CSize(FlameSize, FlameSize),
			CPoint(26, 36), 1))
		{
			Fail(1);
		}*/
	}
	for (i = 0; i < FireCount; i++)
	{
		/*
		ASSERT(bmpFire[i].Load(5011 + i, 5001 + i, CSize(FireSize, FireSize),
			CPoint(9, 9)));
			*/
		if (!bmpFire[i].Load(5011 + i, 5001 + i, CSize(FireSize, FireSize),
			CPoint(9, 9)))
		{
			Fail(1);
		}
	}
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < PlayerPhases; j++)
		{
			for (k = 0; k < PlayerKinds; k++)
			{
				/*
				ASSERT(bmpPlayer[k][i][j].Load(1110 + i * 100 + j + 1 + k * 300,
					1100 + i * 100 + j + 1, CSize(CellSize, CellSize)));
					*/
				/*if (!bmpPlayer[k][i][j].Load(1110 + i * 100 + j + 1 + k * 300,
					1100 + i * 100 + j + 1, CSize(CellSize, CellSize)))
				{
					Fail(1);
				}*/
				if (!bmpPlayer[k][i][j].Load(1100 + k * 100 + i * 10 + j,
					1000 + i * 10 + j, msz))
				{
					Fail(1);
				}
			}
		}
	}
	/*
	for (i = 0; i < PlayerPhases; i++)
	{
		for (k = 0; k < PlayerKinds; k++)
		{
			if (!bmpPlayer[k][3][i].Load(1110 + k * 100 + i,
				1010 + i, msz, CPoint(0, 0), 1))
			{
				Fail(1);
			}
		}
	}*/
	
	/*cmdSingle.Create("", WS_VISIBLE | BS_OWNERDRAW, CRect(10, 10, 10, 10), this, 1000);
	cmdDM.Create("", WS_VISIBLE | BS_OWNERDRAW, CRect(100, 10, 10, 10), this, 1001);
	cmdSingle.LoadBitmaps(IDB_SINGLE, IDB_SINGLE_PUSHED);
	cmdDM.LoadBitmaps(IDB_DM, IDB_DM_PUSHED);
	cmd.Create("af!", WS_VISIBLE | WS_CHILD | BS_OWNERDRAW, CRect(10, 10, 10, 10), this, 1002);*/

	/*nLevel = 0;
	nRound = 0;
	LoadLevel(nLevel, nRound);

	Move();*/

	//AfxGetApp()->SetRegistryKey("Lehasoft");

	/*
	nDMBackground			=	GetProfileInt("1.0", "DM_Texture", 0);
	fDMPrizes					= (float)GetProfileInt("1.0", "DM_Prizes", 50) / 100.0;
	fDMMonsters				= (float)GetProfileInt("1.0", "DM_Monsters", 50) / 100.0;
	fDMFullness				= (float)GetProfileInt("1.0", "DM_Fullness", 30) / 100.0;
	*/

	AfxGetApp()->m_pMainWnd->ShowWindow(SW_MAXIMIZE);
	if (!Restart())
	{
		DestroyWindow();
		return 0;
		//::PostQuitMessage(0);
	}
	
	return nResult;
}

/////////////////////////////////////////////////////////////////
//
//	Function:			CMainFrame::CreatePlayer()
//
/////////////////////////////////////////////////////////////////

void CMainFrame::CreatePlayer(Player				&player,
															int						nID,
															int						nComp,
															CPoint				pt,
															int						Scores)
{
	switch (nID)
	{
	case 0:
		player.nUpKey					= 38;
		player.nDownKey				= 40;
		player.nLeftKey				= 37;
		player.nRightKey			= 39;
		player.nBombKey				= 17;
		player.nBlowKey				= 13;
		break;
	case 1:
		player.nUpKey					= 87;
		player.nDownKey				= 83;
		player.nLeftKey				= 65;
		player.nRightKey			= 68;
		player.nBombKey				= 192;
		player.nBlowKey				= 16;
		break;
	}

	player.nUpPressed			= 0;
	player.nDownPressed		= 0;
	player.nLeftPressed		= 0;
	player.nRightPressed	= 0;
	player.nBombPressed		= 0;
	player.nBlowPressed		= 0;
	player.nKeyDirection			= -1;

	player.pt							= pt;
	player.nMoveDirection	= -1;
	//player.Scores				= Scores;
	player.fDone					= 0;
	player.nRoll					= 3;
	player.nDirection			= -1;
	player.nFlying				= 0;
	player.fSpeed					= fPlayerSpeed;
	//player.fLastSpeed			= player.fSpeed;
	player.nPhase					= 2;
	player.nBombCount			= 1;
	//player.nLastBombCount	= player.nBombCount;
	player.nBombSet				= 0;
	player.nBombFlameSize	= 2;
	//player.nLastFlameSize	= player.nBombFlameSize;
	player.nLife					= 1;
	//player.nFrags					= 0;
	//player.nContinues			= 3;
	player.nKind					= nID;
	player.nEnter					= 0;
	player.nFuckBombs			= 0;
	player.nComp					= nComp;
	player.nIllness				= 0;
	//player.fDeepSpeed			= player.fSpeed;
	//player.nDeepBombCount	= player.nBombCount;
	//player.nDeepFlameSize	=	player.nBombFlameSize;
}

/////////////////////////////////////////////////////////////////
//
//	Function:			CMainFrame::LoadLevel()
//
/////////////////////////////////////////////////////////////////

void CMainFrame::LoadLevel(/*int nLevel, int nRound*/)
{
	int					i;
	//float				f;

	for (i = 0; i < nPlayerCount; i++)
	{
		players[i].pt = CPoint(0, 0);
		players[i].nDirection = -1;
		players[i].fDone = 0;
		players[i].nBombSet = 0;
		ptPlayers[i] = players[i].pt;
	}
	nDieTime = 0;
	nWinTime = 0;
	nBlowExitTime = 0;
	nLastWinner = -1;
	//nExitPhase = 0;

	srand(GetTickCount());
	//nExitAvialable = 0;

	for (i = 0; i < MaxBombCount; i++)
	{
		bombs[i].nTimeLeft = 0;
	}
	for (i = 0; i < MaxPeasesCount; i++)
	{
		peases[i].nPhase = -1;
		//numbers[i].nTimeLeft = 0;
	}

	//p1.BombSet = 0;
	nBombCount = 0;

	for (i = 0; i < MaxMonsterCount; i++)
	{
		monsters[i].nKind = -1;
	}
	for (i = 0; i < nPlayerCount; i++)
	{
		players[i].nLife = 1;
	}

	/*case 0:
	case 1:
	case 2:
	case 7:

	case 8:
	case 9:
	case 10:
	case 15:

	case 16:
	case 17:

	case 24:

		sz.cx = ScreenSize;
		sz.cy = ScreenSize;
		break;

	case 3:
	case 4:

	case 18:
	case 19:
	case 20:
	case 23:

	case 32:
	case 33:
	case 34:
	case 35:
	case 39:

	case 48:
	case 49:
	case 50:

		sz.cx = ScreenSize;
		sz.cy = ScreenSize * 2 - 1;
		break;

	case 5:
	case 6:

	case 21:
	case 22:

	case 36:
	case 37:
	case 38:

	case 51:
	case 52:
	case 53:
	case 54:
	case 55:

		sz.cx = ScreenSize;
		sz.cy = ScreenSize * 3;
		break;

	case 11:
	case 12:

	case 25:
	case 26:
	case 27:
	case 31:

	case 40:
	case 41:
	case 42:
	case 43:

	case 56:
	case 57:
	case 58:
	case 59:

		sz.cx = ScreenSize * 2 - 1;
		sz.cy = ScreenSize;
		break;

	case 13:
	case 14:

	case 28:
	case 29:
	case 30:

	case 44:
	case 45:
	case 46:
	case 47:

	case 60:
	case 61:
	case 62:

		sz.cx = ScreenSize * 3;
		sz.cy = ScreenSize;
		break;

	case 63:
		
		sz.cx = ScreenSize * 2 - 1;
		sz.cy = ScreenSize * 2 - 1;
		break;
	}*/

	if (nRandomTexture)
	{
		nBackgroundID = rand() * BackgroundCount / (RAND_MAX + 1);
	}
	GenerateLevel(fDMFullness);
	/*if (nLevel != -1)
	{
		AddPrize(1, 0);
	}*/

	/*switch (nLevel + nRound * LevelCount)
	{
	case -1:*/
	i = fDMMonsters * 100;
	while (i)
	{
		AddDMMonster(i);
	}
	for (i = 0; i < nBrickCount * fDMPrizes; i++)
	{
		if (!AddDMPrize())
		{
			break;
		}
	}
		/*break;
	case 0:								//	grass
		SetMonster(0);
		SetMonster(0);
		SetMonster(0);
		AddPrize(2, 1);
		break;
	case 1:
		SetMonster(0);
		SetMonster(0);
		SetMonster(1);
		AddPrize(3, 1);
		break;
	case 2:
		SetMonster(0);
		SetMonster(0);
		SetMonster(0);
		SetMonster(1);
		SetMonster(1);
		AddPrize(4, 1);
		break;
	case 3:
		SetMonster(0);
		SetMonster(0);
		SetMonster(1);
		SetMonster(1);
		SetMonster(3);
		AddPrize(7, 1);
		break;
	case 4:
		SetMonster(0);
		SetMonster(0);
		SetMonster(0);
		SetMonster(0);
		SetMonster(1);
		SetMonster(1);
		SetMonster(3);
		AddPrize(4, 1);
		break;
	case 5:
		SetMonster(0);
		SetMonster(0);
		SetMonster(0);
		SetMonster(1);
		SetMonster(1);
		SetMonster(1);
		SetMonster(3);
		SetMonster(3);
		AddPrize(8, 1);
		break;
	case 6:
		SetMonster(0);
		SetMonster(0);
		SetMonster(2);
		SetMonster(3);
		SetMonster(3);
		SetMonster(18);
		AddPrize(9, 1);
		break;
	case 7:
		SetMonster(-1);
		SetMonster(2);
		SetMonster(2);
		break;
	case 8:								//	bog
		SetMonster(3);
		SetMonster(14);
		SetMonster(14);
		SetMonster(15);
		SetMonster(15);
		AddPrize(2, 1);
		break;
	case 9:
		SetMonster(3);
		SetMonster(3);
		SetMonster(14);
		SetMonster(14);
		SetMonster(15);
		AddPrize(3, 1);
		break;
	case 10:
		SetMonster(3);
		SetMonster(3);
		SetMonster(3);
		SetMonster(14);
		SetMonster(14);
		SetMonster(15);
		SetMonster(15);
		AddPrize(3, 1);
		break;
	case 11:
		SetMonster(2);
		SetMonster(6);
		SetMonster(3);
		SetMonster(3);
		SetMonster(14);
		SetMonster(14);
		SetMonster(15);
		AddPrize(8, 1);
		break;
	case 12:
		SetMonster(3);
		SetMonster(2);
		SetMonster(2);
		SetMonster(6);
		SetMonster(6);
		SetMonster(14);
		SetMonster(14);
		SetMonster(14);
		SetMonster(18);
		AddPrize(9, 1);
		break;
	case 13:
		SetMonster(3);
		SetMonster(6);
		SetMonster(6);
		SetMonster(6);
		SetMonster(14);
		SetMonster(14);
		SetMonster(18);
		SetMonster(18);
		AddPrize(4, 1);
		break;
	case 14:
		SetMonster(3);
		SetMonster(3);
		SetMonster(2);
		SetMonster(6);
		SetMonster(6);
		SetMonster(6);
		SetMonster(6);
		SetMonster(18);
		SetMonster(18);
		AddPrize(6, 1);
		break;
	case 15:
		SetMonster(10);
		SetMonster(6);
		SetMonster(7);
		break;
	case 16:							//	water
		SetMonster(17);
		SetMonster(17);
		SetMonster(3);
		SetMonster(3);
		SetMonster(3);
		AddPrize(2, 1);
		break;
	case 17:
		SetMonster(17);
		SetMonster(17);
		SetMonster(3);
		SetMonster(16);
		SetMonster(16);
		AddPrize(3, 1);
		break;
	case 18:
		SetMonster(17);
		SetMonster(17);
		SetMonster(17);
		SetMonster(3);
		SetMonster(3);
		SetMonster(2);
		SetMonster(2);
		SetMonster(7);
		SetMonster(16);
		AddPrize(2, 1);
		break;
	case 19:
		SetMonster(17);
		SetMonster(17);
		SetMonster(3);
		SetMonster(3);
		SetMonster(3);
		SetMonster(2);
		SetMonster(2);
		SetMonster(7);
		SetMonster(7);
		SetMonster(18);
		SetMonster(16);
		AddPrize(4, 1);
		break;
	case 20:
		SetMonster(17);
		SetMonster(3);
		SetMonster(3);
		SetMonster(2);
		SetMonster(2);
		SetMonster(2);
		SetMonster(6);
		SetMonster(7);
		SetMonster(8);
		SetMonster(18);
		SetMonster(16);
		SetMonster(16);
		AddPrize(9, 1);
		break;
	case 21:
		SetMonster(3);
		SetMonster(3);
		SetMonster(3);
		SetMonster(2);
		SetMonster(2);
		SetMonster(2);
		SetMonster(2);
		SetMonster(5);
		SetMonster(6);
		SetMonster(7);
		SetMonster(18);
		SetMonster(18);
		SetMonster(16);
		AddPrize(6, 1);
		break;
	case 22:
		SetMonster(3);
		SetMonster(3);
		SetMonster(2);
		SetMonster(2);
		SetMonster(2);
		SetMonster(2);
		SetMonster(5);
		SetMonster(6);
		SetMonster(7);
		SetMonster(8);
		SetMonster(18);
		SetMonster(18);
		AddPrize(8, 1);
		break;
	case 23:
		SetMonster(-1);
		SetMonster(-1);
		SetMonster(2);
		break;
	case 24:								//	forest
		SetMonster(9);
		SetMonster(9);
		SetMonster(4);
		SetMonster(4);
		SetMonster(3);
		AddPrize(2, 1);
		break;
	case 25:
		SetMonster(9);
		SetMonster(9);
		SetMonster(4);
		SetMonster(4);
		SetMonster(4);
		SetMonster(2);
		SetMonster(3);
		SetMonster(3);
		AddPrize(3, 1);
		break;
	case 26:
		SetMonster(9);
		SetMonster(4);
		SetMonster(4);
		SetMonster(4);
		SetMonster(2);
		SetMonster(2);
		SetMonster(5);
		SetMonster(6);
		SetMonster(18);
		AddPrize(4, 1);
		break;
	case 27:
		SetMonster(9);
		SetMonster(4);
		SetMonster(4);
		SetMonster(4);
		SetMonster(2);
		SetMonster(5);
		SetMonster(18);
		SetMonster(-2);
		AddPrize(7, 1);
		break;
	case 28:
		SetMonster(4);
		SetMonster(4);
		SetMonster(2);
		SetMonster(2);
		SetMonster(5);
		SetMonster(6);
		SetMonster(7);
		SetMonster(18);
		SetMonster(-2);
		AddPrize(9, 1);
		break;
	case 29:
		SetMonster(4);
		SetMonster(2);
		SetMonster(5);
		SetMonster(6);
		SetMonster(7);
		SetMonster(18);
		SetMonster(18);
		SetMonster(-2);
		AddPrize(6, 1);
		break;
	case 30:
		SetMonster(4);
		SetMonster(2);
		SetMonster(2);
		SetMonster(2);
		SetMonster(5);
		SetMonster(6);
		SetMonster(18);
		SetMonster(18);
		SetMonster(-2);
		SetMonster(-2);
		AddPrize(8, 1);
		break;
	case 31:
		SetMonster(10);
		SetMonster(10);
		break;
	case 32:								//	mountains
		SetMonster(19);
		SetMonster(19);
		SetMonster(19);
		SetMonster(3);
		SetMonster(3);
		SetMonster(17);
		AddPrize(2, 1);
		break;
	case 33:
		SetMonster(19);
		SetMonster(19);
		SetMonster(19);
		SetMonster(3);
		SetMonster(2);
		SetMonster(2);
		SetMonster(2);
		AddPrize(3, 1);
		break;
	case 34:
		SetMonster(19);
		SetMonster(19);
		SetMonster(19);
		SetMonster(18);
		SetMonster(3);
		SetMonster(2);
		SetMonster(2);
		SetMonster(5);
		SetMonster(6);
		AddPrize(3, 1);
		break;
	case 35:
		SetMonster(19);
		SetMonster(19);
		SetMonster(19);
		SetMonster(18);
		SetMonster(18);
		SetMonster(2);
		SetMonster(2);
		SetMonster(2);
		SetMonster(5);
		SetMonster(6);
		SetMonster(7);
		AddPrize(7, 1);
	case 36:
		SetMonster(19);
		SetMonster(19);
		SetMonster(19);
		SetMonster(18);
		SetMonster(18);
		SetMonster(2);
		SetMonster(2);
		SetMonster(2);
		SetMonster(5);
		SetMonster(6);
		SetMonster(7);
		SetMonster(8);
		AddPrize(8, 1);
		break;
	case 37:
		SetMonster(19);
		SetMonster(19);
		SetMonster(18);
		SetMonster(18);
		SetMonster(18);
		SetMonster(-2);
		SetMonster(2);
		SetMonster(2);
		SetMonster(2);
		SetMonster(5);
		SetMonster(6);
		SetMonster(7);
		SetMonster(8);
		AddPrize(9, 1);
		break;
	case 38:
		SetMonster(19);
		SetMonster(18);
		SetMonster(18);
		SetMonster(18);
		SetMonster(-2);
		SetMonster(-2);
		SetMonster(2);
		SetMonster(2);
		SetMonster(2);
		SetMonster(2);
		SetMonster(5);
		SetMonster(6);
		SetMonster(7);
		AddPrize(7, 1);
		break;
	case 39:
		SetMonster(-1);
		SetMonster(-1);
		SetMonster(10);
		SetMonster(12);
		break;
	case 40:								//	basement
		SetMonster(-3);
		SetMonster(-3);
		SetMonster(-3);
		SetMonster(2);
		SetMonster(2);
		SetMonster(8);
		SetMonster(7);
		AddPrize(2, 1);
		break;
	case 41:
		SetMonster(-3);
		SetMonster(-3);
		SetMonster(-3);
		SetMonster(2);
		SetMonster(2);
		SetMonster(8);
		SetMonster(5);
		SetMonster(18);
		AddPrize(2, 1);
		break;
	case 42:
		SetMonster(-3);
		SetMonster(-3);
		SetMonster(-3);
		SetMonster(2);
		SetMonster(2);
		SetMonster(3);
		SetMonster(3);
		SetMonster(8);
		SetMonster(5);
		SetMonster(18);
		AddPrize(3, 1);
		break;
	case 43:
		SetMonster(-3);
		SetMonster(-3);
		SetMonster(-3);
		SetMonster(2);
		SetMonster(2);
		SetMonster(2);
		SetMonster(8);
		SetMonster(5);
		SetMonster(18);
		SetMonster(18);
		AddPrize(4, 1);
		break;
	case 44:
		SetMonster(-3);
		SetMonster(-3);
		SetMonster(-3);
		SetMonster(2);
		SetMonster(2);
		SetMonster(8);
		SetMonster(5);
		SetMonster(6);
		SetMonster(-2);
		SetMonster(18);
		SetMonster(18);
		AddPrize(2, 1);
		break;
	case 45:
		SetMonster(-3);
		SetMonster(-3);
		SetMonster(-3);
		SetMonster(2);
		SetMonster(2);
		SetMonster(2);
		SetMonster(8);
		SetMonster(5);
		SetMonster(6);
		SetMonster(-2);
		SetMonster(-2);
		SetMonster(18);
		SetMonster(18);
		AddPrize(6, 1);
		break;
	case 46:
		SetMonster(-3);
		SetMonster(-3);
		SetMonster(2);
		SetMonster(2);
		SetMonster(8);
		SetMonster(5);
		SetMonster(6);
		SetMonster(-2);
		SetMonster(-2);
		SetMonster(-2);
		SetMonster(18);
		SetMonster(18);
		AddPrize(8, 1);
		break;
	case 47:
		SetMonster(-1);
		SetMonster(-1);
		SetMonster(-1);
		SetMonster(10);
		SetMonster(11);
		break;
	case 48:							//	middle
		SetMonster(-4);
		SetMonster(-4);
		SetMonster(-4);
		SetMonster(2);
		SetMonster(2);
		SetMonster(2);
		SetMonster(8);
		SetMonster(5);
		AddPrize(2, 1);
		break;
	case 49:
		SetMonster(-4);
		SetMonster(-4);
		SetMonster(-4);
		SetMonster(2);
		SetMonster(2);
		SetMonster(2);
		SetMonster(8);
		SetMonster(6);
		SetMonster(7);
		SetMonster(18);
		AddPrize(3, 1);
		break;
	case 50:
		SetMonster(-4);
		SetMonster(-4);
		SetMonster(-4);
		SetMonster(2);
		SetMonster(2);
		SetMonster(8);
		SetMonster(5);
		SetMonster(6);
		SetMonster(7);
		SetMonster(18);
		SetMonster(18);
		AddPrize(4, 1);
		break;
	case 51:
		SetMonster(-4);
		SetMonster(-4);
		SetMonster(-4);
		SetMonster(2);
		SetMonster(2);
		SetMonster(2);
		SetMonster(8);
		SetMonster(5);
		SetMonster(6);
		SetMonster(7);
		SetMonster(18);
		SetMonster(18);
		SetMonster(-2);
		AddPrize(7, 1);
		break;
	case 52:
		SetMonster(-4);
		SetMonster(-4);
		SetMonster(-4);
		SetMonster(2);
		SetMonster(8);
		SetMonster(5);
		SetMonster(6);
		SetMonster(7);
		SetMonster(18);
		SetMonster(18);
		SetMonster(-2);
		SetMonster(-2);
		AddPrize(6, 1);
		break;
	case 53:
		SetMonster(-4);
		SetMonster(-4);
		SetMonster(-4);
		SetMonster(2);
		SetMonster(2);
		SetMonster(2);
		SetMonster(8);
		SetMonster(5);
		SetMonster(6);
		SetMonster(7);
		SetMonster(18);
		SetMonster(18);
		SetMonster(-2);
		SetMonster(-2);
		AddPrize(9, 1);
		break;
	case 54:
		SetMonster(-4);
		SetMonster(-4);
		SetMonster(-4);
		SetMonster(-4);
		SetMonster(2);
		SetMonster(2);
		SetMonster(2);
		SetMonster(8);
		SetMonster(5);
		SetMonster(6);
		SetMonster(7);
		SetMonster(18);
		SetMonster(18);
		SetMonster(18);
		SetMonster(-2);
		SetMonster(-2);
		AddPrize(8, 1);
		break;
	case 55:
		SetMonster(10);
		SetMonster(10);
		SetMonster(-1);
		SetMonster(-1);
		SetMonster(-1);
		break;
	case 56:								//	roof
		SetMonster(3);
		SetMonster(3);
		SetMonster(3);
		SetMonster(3);
		SetMonster(3);
		SetMonster(-2);
		SetMonster(-2);
		SetMonster(18);
		SetMonster(18);
		AddPrize(2, 1);
		break;
	case 57:
		SetMonster(14);
		SetMonster(14);
		SetMonster(14);
		SetMonster(2);
		SetMonster(2);
		SetMonster(-2);
		SetMonster(-2);
		SetMonster(18);
		SetMonster(18);
		AddPrize(3, 1);
		break;
	case 58:
		SetMonster(17);
		SetMonster(17);
		SetMonster(17);
		SetMonster(8);
		SetMonster(5);
		SetMonster(6);
		SetMonster(7);
		SetMonster(-2);
		SetMonster(-2);
		SetMonster(18);
		SetMonster(18);
		AddPrize(2, 1);
		break;
	case 59:
		SetMonster(9);
		SetMonster(9);
		SetMonster(4);
		SetMonster(4);
		SetMonster(2);
		SetMonster(2);
		SetMonster(2);
		SetMonster(6);
		SetMonster(5);
		SetMonster(-2);
		SetMonster(-2);
		SetMonster(-2);
		SetMonster(18);
		SetMonster(18);
		AddPrize(4, 1);
		break;
	case 60:
		SetMonster(19);
		SetMonster(19);
		SetMonster(19);
		SetMonster(19);
		SetMonster(2);
		SetMonster(2);
		SetMonster(5);
		SetMonster(6);
		SetMonster(7);
		SetMonster(-2);
		SetMonster(-2);
		SetMonster(-2);
		SetMonster(18);
		SetMonster(18);
		SetMonster(18);
		AddPrize(9, 1);
		break;
	case 61:
		SetMonster(-3);
		SetMonster(-3);
		SetMonster(-3);
		SetMonster(-3);
		SetMonster(2);
		SetMonster(2);
		SetMonster(5);
		SetMonster(6);
		SetMonster(7);
		SetMonster(8);
		SetMonster(-2);
		SetMonster(-2);
		SetMonster(-2);
		SetMonster(18);
		SetMonster(18);
		SetMonster(18);
		AddPrize(6, 1);
		break;
	case 62:
		SetMonster(-4);
		SetMonster(-4);
		SetMonster(-4);
		SetMonster(-4);
		SetMonster(2);
		SetMonster(2);
		SetMonster(2);
		SetMonster(5);
		SetMonster(6);
		SetMonster(7);
		SetMonster(8);
		SetMonster(-2);
		SetMonster(-2);
		SetMonster(-2);
		SetMonster(18);
		SetMonster(18);
		SetMonster(18);
		SetMonster(18);
		AddPrize(7, 1);
		AddPrize(8, 1);
		AddPrize(4, 1);
		AddPrize(9, 1);
		break;
	case 63:
		SetMonster(10);
		SetMonster(10);
		SetMonster(10);
		SetMonster(10);
		SetMonster(-1);
		break;
	}*/

	//CreatePlayer(players[0], 0);
	/*if (nLevel == -1)
	{*/
	switch (nPlayerCount)
	{
	case 4:
		CreatePlayer(players[3], 3, 1, CPoint(sz.cx - 1, 0));
	case 3:
		CreatePlayer(players[2], 2, 1, CPoint(0, sz.cy - 1));
	case 2:
		CreatePlayer(players[1], 1, nDMComp, CPoint(sz.cx - 1, sz.cy - 1));
		CreatePlayer(players[0], 0, 0);
		break;
	}
	/*}
	else
	{
		players[0].nLastBombCount		= players[0].nBombCount;
		players[0].nLastFlameSize		= players[0].nBombFlameSize;
		players[0].fLastSpeed				= players[0].fSpeed;
	}*/
	
	/*
	switch (nPlayerCount)
	{
	case 1:
		players[0].nLastBombCount		= players[0].nBombCount;
		players[0].nLastFlameSize		= players[0].nBombFlameSize;
		players[0].fLastSpeed				= players[0].fSpeed;
		break;
	case 2:
		CreatePlayer(players[0], 0, 0);
		CreatePlayer(players[1], 1, nDMComp, CPoint(sz.cx - 1, sz.cy - 1));
		break;
	}
	*/

	nTimeLeft = 4 * 60 * 25;
	//nTimeLeft = 5 * 25;
	//nExitAvialable = 1;
}

/////////////////////////////////////////////////////////////////
//
//	Function:			CMainFrame::GenerateLevel()
//
/////////////////////////////////////////////////////////////////

void CMainFrame::GenerateLevel(float Fullness)
{
	int				i, j, k, l;
	//int				nExit;
	sz.cx = 13;
	sz.cy = 13;
	j = sz.cx * sz.cy;
	Cell			*TempArea = new Cell[j];
	Cell			TempCell;

	if (Fullness >= 1)
	{
		//ASSERT(FALSE);
		return;
	}
	
	nBrickCount = 0;
	for (i = 0; i < MaxSize * MaxSize; i++)
	{
		ptBricks[i].x = -1;
	}

	
	for (i = 0; i < j; i++)
	{
		TempArea[i].nTexture = rand() * (TexturesCount - .001) / RAND_MAX;
		if (i < j * Fullness)
		{
			TempArea[i].nBrick = rand() * (TexturesCount - .001) / RAND_MAX + 1;
			/*ptBricks[nBrickCount].x = i % sz.cx;
			ptBricks[nBrickCount].y = i / sz.cx;
			nBrickCount++;*/
		}
		else
		{
			TempArea[i].nBrick = 0;
		}
		TempArea[i].nExit = 0;
	}
	//TempArea[0].nExit = 1;
	//nExit = 0;

	//srand(GetTickCount());
	for (i = 0; i < j; i++)
	{
		k = rand() * ((float)j - .001) / RAND_MAX;
		l = rand() * ((float)j - .001) / RAND_MAX;

		TempCell = TempArea[k];
		TempArea[k] = TempArea[l];
		TempArea[l] = TempCell;
		/*if (k == nExit)
		{
			nExit = l;
		}
		else
		{
			if (l == nExit)
			{
				nExit = k;
			}
		}*/
	}

	k = 0;
	l = 0;
	for (i = 0; i < j; i++, k++)
	{
		if (k >= sz.cx)
		{
			k = 0;
			l++;
		}
		Area[k][l] = TempArea[i];
	}
	
	switch (nPlayerCount)
	{
	case 4:
		Area[sz.cx - 1][0].nBrick = 0;
		Area[sz.cx - 2][0].nBrick = 0;
		Area[sz.cx - 1][1].nBrick = 0;
	case 3:
		Area[0][sz.cy - 1].nBrick = 0;
		Area[1][sz.cy - 1].nBrick = 0;
		Area[0][sz.cy - 2].nBrick = 0;
	case 2:
		Area[sz.cx - 1][sz.cy - 1].nBrick = 0;
		Area[sz.cx - 2][sz.cy - 1].nBrick = 0;
		Area[sz.cx - 1][sz.cy - 2].nBrick = 0;
	case 1:
		Area[0][0].nBrick = 0;
		Area[1][0].nBrick = 0;
		Area[0][1].nBrick = 0;
		break;
	}

	for (i = 0; i < sz.cx; i++)
	{
		for (k = 0; k < sz.cy; k++)
		{
			if (Area[i][k].nBrick)
			{
				ptBricks[nBrickCount].x = i;
				ptBricks[nBrickCount].y = k;
				nBrickCount++;
			}
		}
	}
	/*

	if (Area[0][0].nExit)
	{
		Area[0][0].nExit = 0;
		Area[2][2].nExit = 1;
		Area[2][2].nBrick = 1;
	}
	if (Area[1][0].nExit)
	{
		Area[1][0].nExit = 0;
		Area[3][2].nExit = 1;
		Area[3][2].nBrick = 2;
	}
	if (Area[0][1].nExit)
	{
		Area[0][1].nExit = 0;
		Area[2][3].nExit = 1;
		Area[2][3].nBrick = 3;
	}*/

	for (k = 1; k < sz.cx; k += 2)
	{
		for (l = 1; l < sz.cy; l += 2)
		{
			CleanBrick(CPoint(k, l));
			Area[k][l].nBrick = 777;
			/*
			Area[k][l].nBrick = 777;
			if (Area[k][l].nExit)
			{
				Area[k + 1][l].nExit = 1;
				Area[k][l].nExit = 0;
				Area[k + 1][l].nBrick = 2;
			}
			*/
		}
	}
	//AddPrize(1);

	for (k = 0; k < sz.cx; k++)
	{
		for (l = 0; l < sz.cy; l++)
		{
			Area[k][l].nFlamePhase		= 0;
			Area[k][l].nFlameDirection		= 0;
			//Area[k][l].nBlink					= 0;
			//Area[k][l].nExitVisible		= 0;
			//Area[k][l].nExit					= 0;
		}
	}
	//Area[1][0].nExit = 1;

	delete []TempArea;
}

/////////////////////////////////////////////////////////////////
//
//	Function:			CMainFrame::Move()
//
/////////////////////////////////////////////////////////////////

void CMainFrame::Move()
{
	int						i, j, k;
	//float					fDone;
	CPoint				pt;
	int						nMove = 0;
	
	//srand(GetTickCount());
	switch (nGameMode)
	{
	case PlayMode:
		nTimeLeft--;
		if (nTimeLeft == 0)
		{
			nDieTime = 20;
			/*switch (nLevel)
			{
			case -1:
				nDieTime = 20;
				break;
			default:
				for (i = 0; i < 8; i++)
				{
					SetMonster(-2);
				}
				break;
			}*/
		}

		for (i = 0; i < nPlayerCount; i++)
		{
			if (players[i].nLife)
			{
				for (j = 0; j < nPlayerCount; j++)
				{
					if (i != j && players[j].nLife)
					{
						if (players[i].pt == players[j].pt ||
							players[i].pt == MoveByDirection(players[j].pt, players[j].nDirection) ||
							MoveByDirection(players[i].pt, players[i].nDirection) == players[j].pt)
						{
							if (players[i].nIllness == 0 && players[j].nIllness != 0)
							{
								ChangeIllness(players[i], players[j].nIllness);
								players[i].nIllnessLeft = players[j].nIllnessLeft / 2;
							}
							if (players[i].nIllness != 0 && players[j].nIllness == 0)
							{
								ChangeIllness(players[j], players[i].nIllness);
								players[j].nIllnessLeft = players[i].nIllnessLeft / 2;
							}
						}
					}
				}

				if (players[i].fDone >= .7)
				{
					if (Area[MoveByDirection(players[i].pt, players[i].nDirection).x]
						[MoveByDirection(players[i].pt, players[i].nDirection).y].nBrick == 0)
					{
						switch (Area[MoveByDirection(players[i].pt, players[i].nDirection).x]
							[MoveByDirection(players[i].pt, players[i].nDirection).y].nExit)
						{
						/*case 1:			//	Exit
							if (nExitAvialable)
							{
								Win();
							}
							break;*/
						case 2:			//	Fire
							players[i].nBombFlameSize++;
							break;
						case 3:			//	Bomb
							players[i].nBombCount++;
							break;
						/*case 5:			//	Speed
							players[i].fSpeed *= 1.1;
							break;*/
						/*case 5:			//	USD
							players[i].nScores += 100;
							break;*/
						/*case 4:			//	Fuck bombs
							players[i].nFuckBombs = 1;
							break;*/
						/*case 7:			//	Life
							players[i].nLife++;
							break;
						case 8:			//	Enter
							players[i].nEnter = 1;
							break;*/
						/*case 6:			//	Wings
							players[i].nFlying = 1;
							break;*/
						case 4:		//	Skull
							ChangeIllness(players[i], -1);
							break;
						}
					}
					if (Area[MoveByDirection(players[i].pt, players[i].nDirection).x]
						[MoveByDirection(players[i].pt, players[i].nDirection).y].nExit > 1)
					{
						Area[MoveByDirection(players[i].pt, players[i].nDirection).x]
							[MoveByDirection(players[i].pt, players[i].nDirection).y].nExit = 0;
						sndPlaySound("prize.wav", 1);
					}
				}

				/*if (players[i].nComp &&
					(players[i].fDone <= players[i].fSpeed
					|| (!CanLocate(MoveByDirection(players[i].pt, players[i].nKeyDirection), players[i].nFlying) && players[i].nKeyDirection == players[i].nDirection)))*/
				/*if (players[i].nComp &&
					(players[i].fDone <= players[i].fSpeed))
					//|| (!CanLocate(MoveByDirection(players[i].pt, players[i].nKeyDirection), players[i].nFlying) && players[i].nKeyDirection == players[i].nDirection)))
				{
					MoveCompPlayer(players[i], i);
				}*/

				if (players[i].nIllness)
				{
					players[i].nIllnessLeft--;
					if (players[i].nIllnessLeft <= 0)
					{
						ChangeIllness(players[i], 0);
					}
				}

				if ((players[i].nBombPressed && players[i].nIllness != 4)
					|| players[i].nIllness == 3)
				{
					if (players[i].nBombSet < players[i].nBombCount)
					{
						if (players[i].nEnter)
						{
							k = -1;
						}
						else
						{
							k = BombInterval;
						}
						if (players[i].fDone < .5)
						{
							SetBomb(players[i].pt, i, players[i].nBombFlameSize, k);
						}
						else
						{
							SetBomb(MoveByDirection(players[i].pt, players[i].nDirection),
								i, players[i].nBombFlameSize, k);
						}
					}
					else
					{
						//ASSERT(FALSE);
					}
				}

				if (DirectionDiff(players[i].nDirection, players[i].nKeyDirection) == 2)
				{
					players[i].pt = MoveByDirection(players[i].pt, players[i].nDirection);
					players[i].nDirection = players[i].nKeyDirection;//WrapDirection(p1.Direction + 2);
					players[i].fDone = 1 - players[i].fDone;
					players[i].nMoveDirection = players[i].nDirection;
					//ptPlayers[i] = players[i].pt;
				}
				if (DirectionDiff(players[i].nDirection, players[i].nKeyDirection) == 1)
				{
					if (CanLocate(MoveByDirection(players[i].pt, players[i].nKeyDirection),
						players[i].nFlying)/* || (OnBomb(players[i].pt) &&
						players[i].Done < players[i].Speed)*/)
					{
						players[i].pt = MoveByDirection(players[i].pt, players[i].nDirection);
						players[i].nDirection = WrapDirection(players[i].nDirection + 2);//p1.KeyDirection;
						players[i].fDone = 1 - players[i].fDone;
						players[i].nMoveDirection = players[i].nDirection;
						if (players[i].fDone > 1 - players[i].fSpeed)
						{
							players[i].pt = MoveByDirection(players[i].pt, players[i].nDirection);
							players[i].fDone = 0;
							players[i].nDirection = players[i].nKeyDirection;
							players[i].nMoveDirection = players[i].nDirection;
						}
					}
				}
				if (players[i].nKeyDirection != -1)
				{
					pt = MoveByDirection(players[i].pt, players[i].nKeyDirection);
					if (CanLocate(pt, players[i].nFlying) ||
						(OnBomb(players[i].pt) && players[i].fDone > players[i].fSpeed &&
						Area[pt.x][pt.y].nBrick != 777
						&& players[i].nKeyDirection == players[i].nDirection))
					{
						nMove = 1;
						players[i].nMoveDirection = players[i].nKeyDirection;
						players[i].nDirection = players[i].nMoveDirection;
					}
					else
					{
						/*if (CanLocate(MoveByDirection(MoveByDirection(players[i].pt,
							players[i].Direction), players[i].KeyDirection),
							players[i].Flying) || (OnBomb(MoveByDirection(players[i].pt,
							players[i].Direction)) && players[i].Done < players[i].Speed))
							*/
						if ((CanLocate(MoveByDirection(MoveByDirection(players[i].pt,
							players[i].nDirection), players[i].nKeyDirection),
							players[i].nFlying) || (OnBomb(MoveByDirection(players[i].pt,
							players[i].nDirection)) && players[i].fDone < players[i].fSpeed))/* &&
							players[i].Direction != players[i].KeyDirection*/)
						{
							if (CanLocate(MoveByDirection(players[i].pt, players[i].nDirection),
								players[i].nFlying) ||
								OnBomb(MoveByDirection(players[i].pt, players[i].nDirection)) &&
								/*OnBomb(players[i].pt)*/players[i].fDone >= .5)
							{
								players[i].nMoveDirection = players[i].nDirection;
								nMove = 1;
							}
						}
						/*else
						{
							if (players[i].KeyDirection == players[i].Direction)
							{
								players[i].Direction = -1;
								players[i].Done = 0;
							}
						}*/
					}
				}
				if (nMove)
				{
					//sndPlaySound("walk.wav", SND_NOSTOP | 1);
					nMove = 0;
					players[i].fDone += players[i].fSpeed;
					if (players[i].nComp)
					{
						/*if (players[i].fDone > .5 - players[i].fSpeed &&
							players[i].fDone < .5 + players[i].fSpeed)
						{*/
							SubMovePlayer(players[i], i);
						//}
					}
					players[i].nPhase++;
					if (players[i].nPhase >= PlayerPhases)
					{
						players[i].nPhase = 0;
					}
					if (players[i].nMoveDirection > 0)
					{
						players[i].nRoll = players[i].nMoveDirection;
					}
					if (players[i].fDone >= 1)
					{
						players[i].pt = MoveByDirection(players[i].pt, players[i].nMoveDirection);
						players[i].fDone -= 1;

						if (players[i].nComp)
						{
							MoveCompPlayer(players[i], i);
						}
						/*if (Area[players[i].pt.x][players[i].pt.y].nExit == 1 && nExitAvialable)
						{
							Win();
						}*/
						if (!CanLocate(MoveByDirection(players[i].pt, players[i].nMoveDirection),
							players[i].nFlying))
						{
							players[i].nMoveDirection = -1;
							players[i].fDone = 0;
						}
						switch (Area[players[i].pt.x][players[i].pt.y].nExit)
						{
						/*case 1:			//	Exit
							if (nExitAvialable)
							{
								Win();
							}
							break;*/
						case 2:			//	Fire
							players[i].nBombFlameSize++;
							break;
						case 3:			//	Bomb
							players[i].nBombCount++;
							break;
						/*case 4:			//	Speed
							players[i].fSpeed *= 1.2;
							break;
						case 5:			//	USD
							players[i].nScores += 100;
							break;
						case 6:			//	Fuck bombs
							players[i].nFuckBombs = 1;
							break;
						case 7:			//	Life
							players[i].nLife++;
							break;
						case 8:			//	Enter
							players[i].nEnter = 1;
							break;
						case 9:			//	Wings
							players[i].nFlying = 1;
							break;
						case 10:		//	Skull
							ChangeIllness(players[i], -1);
							break;*/
						}
						if (Area[players[i].pt.x][players[i].pt.y].nExit > 1)
						{
							Area[players[i].pt.x][players[i].pt.y].nExit = 0;
						}
					}
				}
				else
				{
					players[i].nPhase = 1;
					if (players[i].nComp)
					{
						MoveCompPlayer(players[i], i);
					}
					/*if (players[i].nKeyDirection != -1)
					{
						players[i].fDone = 0;
					}*/
				}
				ptPlayers[i] = players[i].pt;

				if (players[i].nBlowPressed && players[i].nEnter)
				{
					k = -1;
					for (j = 0; j < MaxBombCount; j++)
					{
						if (bombs[j].nSource == i && bombs[j].nTimeLeft < 0)
						{
							if (k == -1 || bombs[j].nTimeLeft < bombs[k].nTimeLeft)
							{
								k = j;
							}
						}
					}
					if (k != -1)
					{
						bombs[k].nTimeLeft = 0;
						Blow(bombs[k]);
					}
				}
				players[i].nBlowPressed = 0;
			}
		}
	
		/*if (nPlayerCount == 1)
		{
			ptd.x = players[0].pt.x * CellSize - Width / 2;
			ptd.y = players[0].pt.y * CellSize - Height / 2;
			switch (players[0].nDirection)
			{
			case 1:
				ptd.y -= players[0].fDone * CellSize;
				break;
			case 2:
				ptd.x += players[0].fDone * CellSize;
				break;
			case 3:
				ptd.y += players[0].fDone * CellSize;
				break;
			case 4:
				ptd.x -= players[0].fDone * CellSize;
				break;
			}

			if (ptd.x < 0)
			{
				ptd.x = 0;
			}
			if (ptd.y < 0)
			{
				ptd.y = 0;
			}
			if (ptd.x > sz.cx * CellSize - Width + BorderWidth * 2)
			{
				ptd.x = sz.cx * CellSize - Width + BorderWidth * 2;
			}
			if (ptd.y > sz.cy * CellSize - Height + BorderWidth * 2)
			{
				ptd.y = sz.cy * CellSize - Height + BorderWidth * 2;
			}
		}
		else
		{
			ptd.x = 0;
			ptd.y = 0;
		}*/

		nBombPhase++;
		if (nBombPhase == FireCount)
		{
			nBombPhase = 0;
		}

		/*if (nExitAvialable)
		{
			nExitPhase++;
			if (nExitPhase == ExitCount)
			{
				nExitPhase = ExitCycle;
			}
		}
		
		nArrowPhase++;
		if (nArrowPhase == ArrowCount * 2)
		{
			nArrowPhase = 0;
		}*/

		for (i = 0; i < MaxMonsterCount; i++)
		{
			if (monsters[i].nKind != -1)
			{
				monsters[i].nPhase++;
				
				if (monsters[i].nPhase >= MonsterCompletePhases * 2)
				{
					monsters[i].nPhase = 0;
				}

				if (monsters[i].nDirection)
				{
					/*
					if (CanLocate(MoveByDirection(monsters[i].pt,
						monsters[i].nDirection), monsters[i].nFlying) || monsters[i].fDone >=.3)
					{
						monsters[i].fDone += monsters[i].fSpeed;
						CheckMonster(monsters[i]);
					}
					else
					{
						monsters[i].fDone = 0;
					}
					*/
					if (CanLocate(MoveByDirection(monsters[i].pt,
						monsters[i].nDirection), monsters[i].nFlying))
					{
						monsters[i].fDone += monsters[i].fSpeed;
						CheckMonster(monsters[i]);
					}
					else
					{
						if (monsters[i].fDone < .5)
							monsters[i].fDone = 0;
						else
						{
							monsters[i].fDone = 0;
							monsters[i].pt = MoveByDirection(monsters[i].pt, monsters[i].nDirection);
							OrderMonster(monsters[i]);
						}
					}
				}

				if (monsters[i].fDone >= 1)
				{
					monsters[i].fDone -= 1;
					monsters[i].pt = MoveByDirection(monsters[i].pt, monsters[i].nDirection);
				}
				
				if (monsters[i].fDone < monsters[i].fSpeed || monsters[i].nDirection == -1)
				{
					OrderMonster(monsters[i]);
					if (!CanLocate(MoveByDirection(monsters[i].pt, monsters[i].nDirection),
						monsters[i].nFlying))
					{
						monsters[i].nDirection = -1;
					}
				}
			}
			else
			{
				break;
			}
		}
		
		/*for (i = 0; i < MaxSnakeCount; i++)
		{
			if (snakes[i].nLive)
			{
				snakes[i].components[0].nPhase++;
				if (snakes[i].components[i].nPhase > SnakePhases - 1)
				{
					snakes[i].components[i].nPhase = 0;
				}
				
				if (snakes[i].components[0].nDirection != -1)
				{
					snakes[i].components[0].fDone += snakes[i].components[0].fSpeed;
					if (snakes[i].components[0].fDone >= 1)
					{
						snakes[i].components[0].fDone -= 1;
						for (j = SnakeLen - 1; j > 0; j--)
						{
							if (snakes[i].components[j].nDirection != -1)
							{
								snakes[i].components[j].nDirection =
									snakes[i].components[j - 1].nDirection;
								snakes[i].components[j].pt = 
									snakes[i].components[j - 1].pt;
								if (j < SnakeLen)
								{
									if (snakes[i].components[j + 1].nDirection == -1)
									{
										snakes[i].components[j + 1].nDirection = 
											GetDirection(snakes[i].components[j + 1].pt,
											snakes[i].components[j].pt);
									}
								}
							}
						}

						snakes[i].components[1].nDirection = snakes[i].components[0].nDirection;
						snakes[i].components[0].pt = MoveByDirection(
							snakes[i].components[0].pt, snakes[i].components[i].nDirection);
						snakes[i].components[0].nDirection = 
							FindPath(snakes[i].components[0].pt,
							ptPlayers, nPlayerCount, 2, 0, 0);
					}
				}
				else
				{
					snakes[i].components[0].nDirection = 
						FindPath(snakes[i].components[0].pt,
						ptPlayers, nPlayerCount, 2, 0, 0);
				}

			}
		}*/

		for (i = 0; i < sz.cx; i++)
		{
			for (j = 0; j < sz.cy; j++)
			{
				if (Area[i][j].nFlameDirection)
				{
					Area[i][j].nFlamePhase++;
					if (Area[i][j].nFlamePhase > 9)
					{
						//Area[i][j].nFlamePhase--;
						Area[i][j].nFlameDirection = 0;
					}
				}
			}
		}

		for (i = 0; i < MaxBombCount; i++)
		{
			if (bombs[i].nTimeLeft)
			{
				/*if (!ValidPt(bombs[i].pt))
					nGameMode = Pause;*/
				bombs[i].nTimeLeft--;
				bombs[i].nRealTimeLeft--;
				if (bombs[i].nRealTimeLeft == 0)
				{
					bombs[i].nTimeLeft = 0;
					Blow(bombs[i]);
				}
			}
		}
		
		for (i = 0; i < MaxPeasesCount; i++)
		{
			if (peases[i].nPhase != -1)
			{
				peases[i].nPhase++;
				if (peases[i].nPhase >= PeasesPhases)
				{
					peases[i].nPhase = -1;
					SortPeases();
				}
				//break;
			}
			/*else
			{
				break;
			}*/

			/*if (numbers[i].nTimeLeft)
			{
				numbers[i].nTimeLeft--;
				numbers[i].pt.x += 1;
				numbers[i].pt.y -= 1;
			}*/
		}

		if (nDieTime)
		{
			nDieTime--;
			switch (nDieTime)
			{
			case 1:
				LoadLevel();
				return;
				break;
			}
			/*
			if (nDieTime == 1)
			{
				LoadLevel();
				break;
			}
			*/
		}

		/*if (nBlowExitTime)
		{
			nBlowExitTime--;
			if (nBlowExitTime == 1)
			{
				BlowExit(ptBlowExit);
			}
		}*/

		nWaterPhase++;
		if (nWaterPhase == WaterPhases * 2)
		{
			nWaterPhase = 0;
		}

		if (nWinTime)
		{
			nWinTime--;
			switch (nWinTime)
			{
			case 1:
				LoadLevel();
				return;
				break;
			/*case 15:
				break;*/
			/*case 14:
				sndPlaySound("laugh3.wav", 1);*/
			}

			/*if (nWinTime == 1)
			{
				LoadLevel();
			}*/
		}

		break;
	}

	PaintGame();
}

/////////////////////////////////////////////////////////////////
//
//	Function:			CMainFrame::CanLocate()
//
/////////////////////////////////////////////////////////////////

bool CMainFrame::CanLocate(CPoint			pt,
													 int				nFlying)
{
	int				i;
	if (pt.x < 0 || pt.x >= sz.cx || pt.y < 0 || pt.y >= sz.cy)
	{
		return false;
	}
	if (Area[pt.x][pt.y].nBrick == 777)
	{
		return false;
	}
	/*if (Area[pt.x][pt.y].nTexture >= 0 && Area[pt.x][pt.y] < TexturesCount)
	{
		return true;
	}*/
	//if (nCrossBombs == 0)
	if (nFlying != 2)
	{
		for (i = 0; i < MaxBombCount; i++)
		{
			if (bombs[i].pt == pt && bombs[i].nTimeLeft)
			{
				return false;
			}
		}
	}
	if (Area[pt.x][pt.y].nBrick == 0)
	{
		return true;
	}
	else
	{
		//return (nFlying > 0) ? (true):(false);
		return nFlying;
	}
	//return nFlying;
}

/////////////////////////////////////////////////////////////////
//
//	Function:			CMainFrame::KeyDown()
//
/////////////////////////////////////////////////////////////////

void CMainFrame::OnKeyDown(UINT nChar, UINT, UINT)
{
	int				i, j;

	switch (nChar)
	{
	case 9:
		switch (nCountMode)
		{
		case SurvivingMode:
			nCountMode = FragMode;
			break;
		case FragMode:		//	frags
			nCountMode = SurvivingMode;
			break;
		}
		AfxGetApp()->WriteProfileInt("1.1", "CountMode", nCountMode);
		break;
	case 27:
		//nButtonID = 2;
		SetButtonID(2);
		switch (nGameMode)
		{
		case PlayMode:
			nGameMode = Pause;
			break;
		case Pause:
			nGameMode = PlayMode;
			break;
		}
		break;
	/*case 13:
		if (nDieTime == 0)
		{
			j = 0;
			for (i = 0; i < nPlayerCount; i++)
			{
				if (players[i].nLife && players[i].nComp == 0)
				{
					j++;
				}
			}
			if (j == 0)
			{
				while (true)
				{
					i = rand() * nPlayerCount / RAND_MAX;
					if (i == nPlayerCount)
					{
						nDieTime = 8;
						break;
					}
					if (players[i].nLife && players[i].nComp)
					{
						players[i].nScores++;
						nWinTime = 8;
						break;
					}
				}
			}
		}*/
		//}
		break;
	case 70:
		if (nShowFPS)
		{
			nShowFPS = 0;
		}
		else
		{
			nShowFPS = 1;
		}
		break;
	case 71:
		if (nSlow)
		{
			nSlow = 0;
			BombInterval /= 3;
			for (i = 0; i < MaxPlayerCount; i++)
			{
				if (players[i].nLife)
					players[i].fSpeed *= 3;
			}
			for (i = 0; i < MaxMonsterCount; i++)
			{
				if (monsters[i].nKind != -1)
					monsters[i].fSpeed *= 3;
			}
			fPlayerSpeed *= 3;
		}
		else
		{
			nSlow = 1;
			BombInterval *= 3;
			for (i = 0; i < MaxPlayerCount; i++)
			{
				if (players[i].nLife)
					players[i].fSpeed /= 3;
			}
			for (i = 0; i < MaxMonsterCount; i++)
			{
				if (monsters[i].nKind != -1)
					monsters[i].fSpeed /= 3;
			}
			fPlayerSpeed /= 3;
		}
	}

	for (i = 0; i < nPlayerCount; i++)
	{
		if (players[i].nComp == 0)
		{
			if (nChar == players[i].nUpKey)
			{
				players[i].nKeyDirection = 1;
				players[i].nUpPressed = 1;
			}
			if (nChar == players[i].nRightKey)
			{
				players[i].nKeyDirection = 2;
				players[i].nRightPressed = 1;
			}
			if (nChar == players[i].nDownKey)
			{
				players[i].nKeyDirection = 3;
				players[i].nDownPressed = 1;
			}
			if (nChar == players[i].nLeftKey)
			{
				players[i].nKeyDirection = 4;
				players[i].nLeftPressed = 1;
			}
			if (nChar == players[i].nBombKey)
			{
				players[i].nBombPressed = 1;
			}
			if (nChar == players[i].nBlowKey)
			{
				players[i].nBlowPressed = 1;
			}
		}
	}
}

/////////////////////////////////////////////////////////////////
//
//	Function:			CMainFrame::OnKeyUp()
//
/////////////////////////////////////////////////////////////////

void CMainFrame::OnKeyUp(UINT nChar, UINT, UINT)
{
	int				i;

	switch (nChar)
	{
	case 27:
		//nButtonID = 0;
		SetButtonID(0);
		break;
	}

	for (i = 0; i < nPlayerCount; i++)
	{
		if (players[i].nComp == 0)
		{
			if (nChar == players[i].nUpKey && players[i].nKeyDirection == 1)
			{
				players[i].nKeyDirection = -1;
				players[i].nUpPressed = 0;
			}
			if (nChar == players[i].nRightKey && players[i].nKeyDirection == 2)
			{
				players[i].nKeyDirection = -1;
				players[i].nRightPressed = 0;
			}
			if (nChar == players[i].nDownKey && players[i].nKeyDirection == 3)
			{
				players[i].nKeyDirection = -1;
				players[i].nDownPressed = 0;
			}
			if (nChar == players[i].nLeftKey && players[i].nKeyDirection == 4)
			{
				players[i].nKeyDirection = -1;
				players[i].nLeftPressed = 0;
			}
			if (nChar == players[i].nBombKey)
			{
				players[i].nBombPressed = 0;
			}
			if (nChar == players[i].nBlowKey)
			{
				players[i].nBlowPressed = 0;
			}
		}
	}
}

/////////////////////////////////////////////////////////////////
//
//	Function:			CMainFrame::MoveByDirection()
//
/////////////////////////////////////////////////////////////////

CPoint CMainFrame::MoveByDirection(CPoint		pt,
																	 int			Direction)
{
	CPoint			ptTemp;

	ptTemp = pt;

	switch (Direction)
	{
	case 1:
		ptTemp.y--;
		break;
	case 2:
		ptTemp.x++;
		break;
	case 3:
		ptTemp.y++;
		break;
	case 4:
		ptTemp.x--;
		break;
	}
	return ptTemp;
}

/////////////////////////////////////////////////////////////////
//
//	Function:			CMainFrame::WrapDirection()
//
/////////////////////////////////////////////////////////////////

int CMainFrame::WrapDirection(int Direction)
{
	if (Direction > 4)
	{
		return (Direction - 1) % 4 + 1;
	}
	if (Direction == 0)
	{
		return 4;
	}
	return Direction;
}

/////////////////////////////////////////////////////////////////
//
//	Function:			CMainFrame::DirectionDiff()
//
/////////////////////////////////////////////////////////////////

int CMainFrame::DirectionDiff(int		Direction1,
													 int		Direction2)
{
	int				i;
	if (Direction1 == -1 || Direction2 == -1)
	{
		return 0;
	}
	i = abs(Direction1 - Direction2) % 4;
	if (i == 3)
	{
		i = 1;
	}
	return i;//abs(Direction1 - Direction2) % 4;
}

/////////////////////////////////////////////////////////////////
//
//	Function:			CMainFrame::Repaint()
//
/////////////////////////////////////////////////////////////////

void CMainFrame::Repaint(CDC			&dc)
{
	//int					i, j, k;
	int					i, j;
	int					nStartX;
	int					nStartY;
	int					nEndX;
	int					nEndY;
	CPoint			pt;
	//CString			str;

	CString			strFPS;

	/*if (nGameMode == MainMenu)
	{
		dc.FillSolidRect(0, 0, Width, Height, 0);
		dc.DrawState(CPoint(BorderWidth, BorderWidth), CSize(0, 0), &bmpMain, DST_BITMAP);
		
		dc.DrawState(CPoint(ButtonMainX, ButtonMainY), CSize(0, 0),
			&bmpButtons[0][0], DST_BITMAP);
		dc.DrawState(CPoint(ButtonMainX + ButtonWidth + 5, ButtonMainY),
			CSize(0, 0), &bmpButtons[1][0], DST_BITMAP);

		switch (nButtonID)
		{
		case 1:
			dc.DrawState(CPoint(ButtonMainX, ButtonMainY), CSize(0, 0),
				&bmpButtons[0][1], DST_BITMAP);
			break;
		case 2:
			dc.DrawState(CPoint(ButtonMainX + ButtonWidth + 5, ButtonMainY),
				CSize(0, 0), &bmpButtons[1][1], DST_BITMAP);
			break;
		}

		return;
	}*/

	/*nStartX		= ptd.x / CellSize;
	nStartY		= ptd.y / CellSize;
	nEndX			= (ptd.x + Width - BorderWidth) / CellSize;
	nEndY			= (ptd.y + Height - BorderWidth) / CellSize;*/


	if (nDieTime && nDieTime < 5)
	{
		dc.FillSolidRect(0, 0, Width, Height, RGB(255, 0, 0));
		return;
	}

	if (nWinTime && nWinTime < 5)
	{
		dc.FillSolidRect(0, 0, Width, Height, RGB(0, 255, 0));
		return;
	}

	/*for (i = 0; i < Width; i += WallLen)
	{
		dc.DrawState(CPoint(i - ptd.x, -ptd.y), CSize(WallLen, BorderWidth),
			&bmpHWall, DST_BITMAP);
		dc.DrawState(CPoint(i - ptd.x, sz.cy * CellSize + BorderWidth - ptd.y),
			CSize(WallLen, BorderWidth), &bmpHWall, DST_BITMAP);
	}
	for (i = 0; i < Height; i += WallLen)
	{
		dc.DrawState(CPoint(-ptd.x, i - ptd.y), CSize(BorderWidth, WallLen),
			&bmpVWall, DST_BITMAP);
		dc.DrawState(CPoint(sz.cx * CellSize + BorderWidth - ptd.x, i - ptd.y),
			CSize(BorderWidth, WallLen), &bmpVWall, DST_BITMAP);
	}*/
	for (j = -1; j < ScreenSize + 1; j++)
	{
		for (i = -1; i < ScreenSize + 1; i++)
		{
			pt.x = i * CellSize + BorderWidth;
			pt.y = j * CellSize + BorderWidth;
			
			/*if (nArrowPhase >= ArrowPictures * 2)
			{
				k = ArrowCount - nArrowPhase / 2;
			}
			else
			{
				k = nArrowPhase / 2;
			}*/
			
			if (i < 0 || i >= sz.cx || j < 0 || j >= sz.cy)
			{
				dc.DrawState(pt, CSize(CellSize, CellSize),
					&bmpHardWall, DST_BITMAP);
			}
			else
			{
				if (Area[i][j].nTexture < 0 || Area[i][j].nTexture >= TexturesCount)
				{
					MessageBox("Задана Неправильная текстура");
					//ASSERT(FALSE);
				}

				if (Area[i][j].nBrick == 777)
				{
					dc.DrawState(pt, CSize(CellSize, CellSize),
						&bmpHardWall, DST_BITMAP);
				}
				else
				{
					if (nShowFPS)
					{
						switch (InDanger(CPoint(i, j), 1, 1))
						{
						case 0:
							dc.DrawState(pt, CSize(CellSize, CellSize),
								bmpTextures[3][Area[i][j].nTexture], DST_BITMAP);
							break;
						case 1:
							dc.DrawState(pt, CSize(CellSize, CellSize),
								bmpTextures[2][Area[i][j].nTexture], DST_BITMAP);
							break;
						case 2:
							dc.DrawState(pt, CSize(CellSize, CellSize),
								bmpTextures[6][Area[i][j].nTexture], DST_BITMAP);
							break;
						}
					}
					else
					{
						dc.DrawState(pt, CSize(CellSize, CellSize),
							bmpTextures[nBackgroundID][Area[i][j].nTexture], DST_BITMAP);
					}
					/*strFPS.Format("%i", GetSafetyArea(CPoint(i, j), 0, 0, 0, -1, 20));
					dc.TextOut(pt.x, pt.y, strFPS);*/

					if (Area[i][j].nBrick > 0 && Area[i][j].nBrick <= TexturesCount)
					{
						bmpBricks[nBackgroundID][Area[i][j].nBrick - 1].Render(dc, pt);
					}
					else
					{
						switch (Area[i][j].nExit)
						{
						case 2:
						case 3:
						case 4:
						case 5:
						case 6:
						case 7:
							dc.DrawState(pt, CSize(CellSize, CellSize),
								bmpPrizes[Area[i][j].nExit - 2], DST_BITMAP);
							break;
						}
						/*if (Area[i][j].nBrick > 0 && Area[i][j].nBrick <= TexturesCount)
						{
							bmpBricks[nBackgroundID][Area[i][j].nBrick - 1].Render(dc, pt);
						}*/
					}
				}
			}
		}
	}

	for (i = 0; i < MaxMonsterCount; i++)
	{
		if (monsters[i].nKind != -1)
		{
			PaintMonster(dc, /*ptd, */monsters[i].pt, monsters[i].nKind,
				monsters[i].nPhase, monsters[i].nDirection, monsters[i].fDone);
		}
		else
		{
			break;
		}
	}

	for (i = 0; i < MaxBombCount; i++)
	{
		if (bombs[i].nTimeLeft)
		{
			//ASSERT(bombs[i].nSource == 0);
			PaintBomb(dc, bombs[i]);
		}/*
		else
		{
			break;
		}*/
	}
	
	for (i = 0; i < nPlayerCount; i++)
	{
		if (players[i].nLife)
		{
			PaintPlayer(players[i], dc);
		}
	}

	for (i = 0; i < sz.cx; i++)
	{
		for (j = 0; j < sz.cy; j++)
		{
			if (Area[i][j].nFlameDirection > 0)
			{
				if (Area[i][j].nFlamePhase < FlameCount)
				{
					switch (Area[i][j].nFlameDirection)
					{
					case 1:
					case 2:
						bmpFlame[Area[i][j].nFlameDirection - 1][Area[i][j].nFlamePhase].Render(
							dc, CPoint(i * CellSize + BorderWidth,
							j * CellSize + BorderWidth));
						break;
					case 3:
						bmpFlame[0][Area[i][j].nFlamePhase].Render(
							dc, CPoint(i * CellSize + BorderWidth,
							j * CellSize + BorderWidth), 0, 2);
						break;
					case 4:
						bmpFlame[1][Area[i][j].nFlamePhase].Render(
							dc, CPoint(i * CellSize + BorderWidth,
							j * CellSize + BorderWidth), 0, 1);
					}
				}
			}
		}
	}

	for (i = 0; i < MaxPeasesCount; i++)
	{
		if (peases[i].nPhase != -1)
		{
			PaintPease(dc, peases[i].pt, min(peases[i].nPhase, PeasesCount - 1));
		}
		else
		{
			break;
		}
	}

	if (nShowFPS)
	{
		strFPS.Format("Вывод в режиме Дебага. Нажми 'f' для нормального вывода.  FPS: %i", ((CDyna*)AfxGetApp())->nFPS);
		dc.TextOut(0, 0, strFPS);
	}
	if (nSlow)
	{
		strFPS.Format("Дебаг-замедление включено. Для ускорения нажми 'g'");
		dc.TextOut(0, ScreenSize * CellSize + BorderWidth, strFPS);
	}
}

/////////////////////////////////////////////////////////////////
//
//	Function:			CMainFrame::PaintGame()
//
/////////////////////////////////////////////////////////////////

void CMainFrame::PaintGame()
{
	CBitmap			bmp;
	CDC					dc;
	CClientDC		dcThis(this);

	dc.CreateCompatibleDC(&dcThis);
	bmp.CreateCompatibleBitmap(&dcThis, Width, Height);
	dc.SelectObject(&bmp);

	//dc.SetBkMode(TRANSPARENT);
	Repaint(dc);
	PaintIndicators(dcIndicatorPanel, CPoint(IndicatorLeft, IndicatorTop));

	dcThis.BitBlt(GameX, GameY, Width, Height, &dc, 0, 0, SRCCOPY);
	dcThis.BitBlt(IndicatorLeft, IndicatorTop, IndicatorWidth,
		IndicatorHeight, &dcIndicatorPanel, 0, 0, SRCCOPY);
	
	if (nButtonChanged)
	{
		dcThis.DrawState(CPoint(Button1X, Button1Y), CSize(0, 0),
			bmpButtons[2][0], DST_BITMAP);
		dcThis.DrawState(CPoint(Button2X, Button2Y), CSize(0, 0),
			bmpButtons[3][0], DST_BITMAP);


		if (nButtonID == 1)
		{
			dcThis.DrawState(CPoint(Button1X, Button1Y), CSize(0, 0),
				bmpButtons[2][1], DST_BITMAP);
		}
		
		if (nButtonID == 2 || nGameMode == Pause)
		{
			dcThis.DrawState(CPoint(Button2X, Button2Y), CSize(0, 0),
				bmpButtons[3][1], DST_BITMAP);
		}
	}
	nButtonChanged = 0;

	//RenderNumber(1234567890, dcThis, CPoint(10, 400));

	//bmpFlame[0][0].Render(dcThis, CPoint(0, 0));
}

/////////////////////////////////////////////////////////////////
//
//	Function:			CMainFrame::PaintPlayer()
//
/////////////////////////////////////////////////////////////////

void CMainFrame::PaintPlayer(Player		&player,
														 CDC			&dc)
{
	float			x, y;
	if (player.nPhase >= 0 && player.nPhase < PlayerPhases)
	{
		if (player.nRoll > 0 && player.nRoll < 5)
		{
			if (player.nKind >= 0 && player.nKind < PlayerKinds)
			{
				switch (player.nDirection)
				{
				case -1:
					x = player.pt.x;
					y = player.pt.y;
					break;
				case 1:
					x = player.pt.x;
					y = player.pt.y - player.fDone;
					break;
				case 2:
					x = player.pt.x + player.fDone;
					y = player.pt.y;
					break;
				case 3:
					x = player.pt.x;
					y = player.pt.y + player.fDone;
					break;
				case 4:
					x = player.pt.x - player.fDone;
					y = player.pt.y;
					break;
				}
				x = x * CellSize + BorderWidth;
				y = y * CellSize + BorderWidth;
				/*x *= CellSize;
				y *= CellSize;
				x -= ptd.x;
				y -= ptd.y;*/
				/*if (player.nIllness && nTimeLeft % 10 > 6)
				{
					switch (player.Roll)
					{
					case 4:

						break;
					case 1:
					case 2:
					case 3:
						dc.BitBlt(x, y, CellSize, CellSize,
							&bmpPlayer[player.nKind][player.nRoll - 1][player.nPhase].m_dcMask,
							0, 0, SRCAND);
						break;
					}
				}
				else
				{
					switch ()
					bmpPlayer[player.nKind][player.nRoll - 1][player.nPhase].Render(dc,
						CPoint(x, y));
				}*/
				switch (player.nRoll)
				{
				case 1:
				case 2:
				case 3:
					bmpPlayer[player.nKind][player.nRoll - 1][player.nPhase].Render(dc, CPoint(x, y),
						(player.nIllness && nTimeLeft % 10 > 6));
					break;
				case 4:
					bmpPlayer[player.nKind][1][player.nPhase].Render(dc, CPoint(x, y),
						(player.nIllness && nTimeLeft % 10 > 6), 1);
					break;
				}
			}
		}
		/*else
		{
			ASSERT(FALSE);
		}*/
	}
	/*else
	{
		ASSERT(FALSE);
	}*/
}

/////////////////////////////////////////////////////////////////
//
//	Function:			CMainFrame::SetBomb()
//
/////////////////////////////////////////////////////////////////

int CMainFrame::SetBomb(CPoint			pt,
												int					nSource,
												int					nFlameLen,
												int					nTimeLeft)
{
	int				i, j = -1, k, l;
	CPoint		pt2;
	int				nBombTable[ScreenSize][ScreenSize];

	if (players[nSource].nIllness == 4)
		return -1;
	if (players[nSource].nBombCount <= players[nSource].nBombSet)
		return -1;

	for (i = 0; i < MaxBombCount; i++)
	{
		if (bombs[i].nTimeLeft == 0)
		{
			if (j == -1)
			{
				j = i;
			}
		}
		if (bombs[i].pt == pt && bombs[i].nTimeLeft)
		{
			return -1;
		}
	}
	if (j == -1)
	{
		return -1;
	}
	bombs[j].nTimeLeft			= nTimeLeft;
	bombs[j].pt							= pt;
	bombs[j].nSource				= nSource;
	bombs[j].nFlameLen			= nFlameLen;
	//nBombCount++;
 	players[nSource].nBombSet++;

	switch (players[nSource].nIllness)
	{
	case 5:
		bombs[j].nTimeLeft *= 3;
		break;
	case 6:
		bombs[j].nTimeLeft /= 2.5;
		break;
	}
	bombs[j].nRealTimeLeft = bombs[j].nTimeLeft;

	for (i = 0; i < ScreenSize; i++)
	{
		for (k = 0; k < ScreenSize; k++)
		{
			nBombTable[i][k] = 0;
		}
	}

	for (i = 0; i < MaxBombCount; i++)
	{
		if (bombs[i].nTimeLeft && i != j)
		{
			nBombTable[bombs[i].pt.x][bombs[i].pt.y] = i + 1;
		}
	}

	for (k = 1; k < 5; k++)
	{
		pt2 = pt;
		for (l = 1; ; l++)
		{
			pt2 = MoveByDirection(pt2, k);
			if (ValidPt(pt2))
			{
				if (nBombTable[pt2.x][pt2.y])
				{
					i = nBombTable[pt2.x][pt2.y] - 1;
					if (l <= bombs[i].nFlameLen)
					{
						if (bombs[i].nRealTimeLeft < bombs[j].nRealTimeLeft)
							bombs[j].nRealTimeLeft = bombs[i].nRealTimeLeft;
					}
				}
				if (Area[pt2.x][pt2.y].nBrick)
					break;
			}
			else
			{
				break;
			}
		}
	}

	return j;
}

/////////////////////////////////////////////////////////////////
//
//	Function:			CMainFrame::Blow()
//
/////////////////////////////////////////////////////////////////

void CMainFrame::Blow(Bomb		bomb/*,
											int			nNoSort*/)
{
	int				i, j;
	//int j;
	CPoint		pt;
	CString		str;
	
	/*if (!nNoSort)
		SortBombs();*/
	
	sndPlaySound("blow.wav", 1);
	AddPease(bomb.pt, 0, 0);

	switch (bomb.nSource)
	{
	case 0:
		players[0].nBombSet--;
		break;
	case 1:
		players[1].nBombSet--;
		break;
	case 2:
		players[2].nBombSet--;
		break;
	case 3:
		players[3].nBombSet--;
		break;
	default:
		return;
		break;
	}
	
	pt = bomb.pt;
	if (pt.x < 0 || pt.x >= sz.cx || pt.y < 0 || pt.y >= sz.cy)
	{
		MessageBox("Заданная точка за пределами карты");
		return;
		//ASSERT(FALSE);
	}
	/*Area[pt.x][pt.y].nFlamePhase = 0;
	Area[pt.x][pt.y].nFlameDirection = 1;*/
	//MessageBox("go up");
	AddFire(pt, 1, bomb.nSource);


	str.Format("Flame length %i", bomb.nFlameLen);
	for (i = 1; i < 5; i++)
	{
		str.Format("Starting by Direction %i", i);
		//MessageBox(str);
		pt = bomb.pt;
		for (j = 0; j < bomb.nFlameLen; j++)
		{
			str.Format("Trying to blow point: %i, %i, step %i", pt.x, pt.y, j);
			//MessageBox(str);
			pt = MoveByDirection(pt, i);
			if (!AddFire(pt, i, bomb.nSource))
			{
				str.Format("Blow finished at step %i", j);
				//MessageBox(str);
				break;
			}
			//MessageBox("Well done blow");
		}
		//MessageBox("Next Direction");
	}
}

/////////////////////////////////////////////////////////////////
//
//	Function:			CMainFrame::PaintBomb()
//
/////////////////////////////////////////////////////////////////

void CMainFrame::PaintBomb(CDC			&dc,
													 Bomb			&bomb)
{
	int					x, y;
	int					nBombInterval;


	switch (players[bomb.nSource].nIllness)
	{
	case 5:
		nBombInterval = BombInterval * 3;
		break;
	case 6:
		nBombInterval = BombInterval / 3;
		break;
	default:
		nBombInterval = BombInterval;
	}
	if (bomb.nTimeLeft > nBombInterval)
		nBombInterval = bomb.nTimeLeft;

	bmpBomb.Render(dc, CPoint(bomb.pt.x * CellSize + BorderWidth,
		bomb.pt.y * CellSize + BorderWidth));

	if (bomb.nTimeLeft >= 0)
	{
		x = bomb.pt.x * CellSize + BorderWidth +
			FireEndX - (FireEndX - FireStartX) * bomb.nTimeLeft / nBombInterval;
		y = bomb.pt.y * CellSize + BorderWidth +
			FireEndY - (FireEndY - FireStartY) * bomb.nTimeLeft / nBombInterval;
		if (nBombPhase >= 0 && nBombPhase < FireCount && bomb.nTimeLeft >= 0)
		{
			bmpFire[nBombPhase].Render(dc, CPoint(x, y));
		}
		else
		{
			MessageBox("Неверная фаза горения фитиля");
			//ASSERT(FALSE);
		}
	}
}

/////////////////////////////////////////////////////////////////
//
//	Function:			CMainFrame::AddFire()
//
/////////////////////////////////////////////////////////////////

bool CMainFrame::AddFire(CPoint				pt,
												 int					nDirection,
												 //int					nCenter,
												 int					nSource)
{
	bool				nAdd = true;
	bool				nResult;
	//CString			str;

	//int					i, j, k;
	int					i;

	//str.Format("Trying to locate at: %i, %i", pt.x, pt.y);
	//MessageBox(str);
	if (pt.x < 0 || pt.x >= sz.cx || pt.y < 0 || pt.y >= sz.cy)
	{
		//ASSERT(FALSE);
		//MessageBox("Out");
		return false;
	}
	if (CanLocate(pt, 0))
	{
		nAdd = true;
		nResult = true;
		Area[pt.x][pt.y].nExit = 0;
		//str.Format("Can locate: %i, %i", pt.x, pt.y);
		//MessageBox(str);
	}
	else
	{
		nResult = false;
		//str.Format("Can't locate: %i, %i", pt.x, pt.y);
		//MessageBox(str);
		/*if (Area[pt.x][pt.y].nBrick == 777)
		{
			nAdd = false;
		}
		else
		{
			Area[pt.x][pt.y].nBrick = 0;
		}*/
		switch (Area[pt.x][pt.y].nBrick)
		{
		case 777:
			//MessageBox("Hard wall");
			nAdd = false;
			break;
		case 1:
		case 2:
		case 3:
			//Area[pt.x][pt.y].nBrick = 0;
			//MessageBox("Wall");
			CleanBrick(pt);
			nAdd = true;
			break;
		default:
			//str.Format("Unknown brick:%i", Area[pt.x][pt.y]);
			//MessageBox(str);
			break;
		}
	}
	if (nAdd)
	{
		Area[pt.x][pt.y].nFlamePhase		= 0;
		Area[pt.x][pt.y].nFlameDirection		= nDirection;
	}
	
	for (i = 0; i < nPlayerCount; i++)
	{
		if (((pt == players[i].pt && players[i].fDone <= .75) ||
			(MoveByDirection(players[i].pt, players[i].nDirection) == pt &&
			players[i].fDone >= .25)) && players[i].nLife)
		{
			if (players[i].nFuckBombs == 0 || i != nSource)
			{
				Die(i, nSource);
			}
		}
	}

	/*
	for (i = 0; i < MaxBombCount; i++)
	{
		if (bombs[i].nTimeLeft)
		{
			if (bombs[i].pt == pt)
			{
				bombs[i].nTimeLeft = 0;
				Blow(bombs[i]);
			}
		}
	}
	*/

	for (i = 0; i < MaxMonsterCount; i++)
	{
		if (monsters[i].nKind != -1)
		{
			if ((monsters[i].pt == pt && monsters[i].fDone <= .75)
				|| (MoveByDirection(monsters[i].pt, monsters[i].nDirection) == pt &&
				monsters[i].fDone >= .25))
			{
				/*switch (monsters[i].nKind)
				{
				case 10:
					monsters[i].nKind = 11;
					break;
				case 11:
					monsters[i].nKind	= 12;
					break;
				default:*/
					//AddNumber(monsters[i].pt, monsters[i].nDirection, monsters[i].fDone, 10);
				/*if (nLevel != -1)
				{
					switch (monsters[i].nKind)
					{
					case -4:		//	spinner
						j = 6;
						break;
					case -3:		//	frog2
						j = 5;
						break;
					case -2:		//	coin
						j =	14;
						break;
					case 0:			//	orange
						j = 1;
						break;
					case 1:			//	plum
						j = 3;
						break;
					case 2:			//	broom
						j = 10;
						break;
					case 3:			//	frog
						j = 5;
						break;
					case 4:			//	ball
						j = 8;
						break;
					case 5:			//	deamon
					case 6:
					case 7:
					case 8:
						j = 13;
						break;
					case 9:			//	violet
						j = 4;
						break;
					case 12:		//	hare
						j = 50;
						break;
					case 13:		//	raspberry
						j = 2;
						break;
					case 14:		//	onion
						j = 4;
						break;
					case 15:		//	crocodile
						j = 2;
						break;
					case 16:		//	color frog
						j = 6;
						break;
					case 17:		//	jelly
						j = 5;
						break;
					case 18:		//	pig
						j = 11;
						break;
					case 19:		//	fire
						j = 4;
						break;
					}
					switch (nSource)
					{
					case 0:
					case 1:
					case 2:
					case 3:
						players[nSource].nScores += j;
						AddNumber(monsters[i].pt, monsters[i].nDirection, monsters[i].fDone, j);
						break;
					}
				}*/
				monsters[i].nKind = -1;
				AddPease(pt, monsters[i].nDirection, monsters[i].fDone);
				SortMonsters();
				//break;
				AddFire(pt, nDirection, nSource);
			}
		}
		else
		{
			break;
		}
	}

	/*if (nCenter)
	{
		for (i = 0; i < MaxSnakeCount; i++)
		{
			if (snakes[i].nLive)
			{
				for (j = 0; j < SnakeLen; j++)
				{
					if ((snakes[i].components[j].pt == pt &&
						snakes[i].components[0].fDone <= .75)
						|| (MoveByDirection(snakes[i].components[j].pt,
						snakes[i].components[j].nDirection) == pt &&
						snakes[i].components[j].fDone >= .25))
					{
						snakes[i].nLifes[j]--;
						if (snakes[i].nLifes[j] == 0)
						{
							snakes[i].nLive = 0;
							for (k = 0; k < SnakeLen; k++)
							{
								AddPease(snakes[i].components[k].pt,
									snakes[i].components[k].nDirection,
									snakes[i].components[k].fDone);
							}
							/*if (KilledAll() && nExitAvialable == 0 && nLevel != -1)
							{
								SetExitAvialable();
							}*/
						//}


						/*monsters[i].nKind = -1;
						AddPease(pt, monsters[i].nDirection, monsters[i].fDone);
						SortMonsters();
						if (monsters[0].nKind == -1)
						{
							nExitAvialable = 1;
							nExitPhase = 0;
						}
						AddFire(pt, nDirection);
					}
				}
			}
		}
	}*/


	return nResult;
}

/////////////////////////////////////////////////////////////////
//
//	Function:			CMainFrame::RenderNumber()
//
/////////////////////////////////////////////////////////////////

void CMainFrame::RenderNumber(CString	strNumber,
															CDC			&dc,
															CPoint	pt)
{
	int				i, j, k;
	//int				nNumber2;

	j = strNumber.GetLength();
	for (i = 0; i < j; i++, pt.x += NumberWidth)
	{
		k = strNumber.GetAt(i);
		if (k > 47 && k <58)
		{
			bmpNumbers[k - 48].Render(dc, pt);
		}
		if (k == 45)
			bmpNumbers[10].Render(dc, pt);
	}
	/*if (nNumber == 0)
	{
		bmpNumbers[0].Render(dc, pt);
	}

	nNumber2 = nNumber;

	if (nNumber < 0)
	{
		return;
	}
	for (i = 0, k = 0; nNumber > 0; nNumber /= 10, i++, k++)
	{
		//j = nNumber % 10;
		//bmpNumbers[0][j].Render(dc, pt);
		//pt.x += NumberWidth;
	}
	//dc.SetPixel(0, 0, 0);
	pt.x += NumberWidth * (k - 1);
	for (; k != 0; k--, nNumber2 /= 10)
	{
		j = nNumber2 % 10;
		
		ASSERT(j >= 0 && j < 10);
		
		if (!bmpNumbers[j].Render(dc, pt))
		{
			nGameMode = Pause;
		}
		pt.x -= NumberWidth;
	}*/
}

/////////////////////////////////////////////////////////////////
//
//	Function:			CMainFrame::PaintIndicators()
//
/////////////////////////////////////////////////////////////////

void CMainFrame::PaintIndicators(CDC			&dc,
																 CPoint		pt)
{
	CClientDC			dcThis(this);
	CString				str;
	
	dc.DrawState(CPoint(0, 0), CSize(IndicatorWidth, IndicatorHeight),
		&bmpIndicatorPanelClear, DST_BITMAP);

	switch (nGameMode)
	{
	case MainMenu:
		return;
	case Pause:
	case PlayMode:
		/*switch (nLevel)
		{
		case -1:*/
			//	time
		str.Format("%i", nTimeLeft / 25 / 60);
		RenderNumber(str, dc, CPoint(35
			, 35));
		str.Format("%.2i", nTimeLeft / 25 % 60);
		RenderNumber(str, dc, CPoint(70, 35));

		switch (nCountMode)
		{
		case SurvivingMode:
			switch (nPlayerCount)
			{
			case 4:
				str.Format("%i", players[3].nScores);
				RenderNumber(str, dc, CPoint(115, 100));
			case 3:
				str.Format("%i", players[2].nScores);
				RenderNumber(str, dc, CPoint(35, 150));
			case 2:
				str.Format("%i", players[1].nScores);
				RenderNumber(str, dc, CPoint(115, 150));

				str.Format("%i", players[0].nScores);
				RenderNumber(str, dc, CPoint(35, 100));
				break;
			}
			break;
		case FragMode:
			switch (nPlayerCount)
			{
			case 4:
				str.Format("%i", players[3].nFrags);
				RenderNumber(str, dc, CPoint(115, 100));
			case 3:
				str.Format("%i", players[2].nFrags);
				RenderNumber(str, dc, CPoint(35, 150));
			case 2:
				str.Format("%i", players[1].nFrags);
				RenderNumber(str, dc, CPoint(115, 150));

				str.Format("%i", players[0].nFrags);
				RenderNumber(str, dc, CPoint(35, 100));
				break;
			}
			break;
		}

		dc.DrawState(CPoint(20, 80), CSize(0, 0), &bmpCaptions[nCountMode], DST_BITMAP);

			/*break;
		default:
			//	time
			str.Format("%i", nTimeLeft / 25 / 60);
			RenderNumber(str, dc, CPoint(60, 35));
			str.Format("%0.2i", nTimeLeft / 25 % 60);
			RenderNumber(str, dc, CPoint(90, 35));

			//	life
			str.Format("%i", players[0].nLife);
			RenderNumber(str, dc, CPoint(60, 67));
			str.Format("%i", players[0].nContinues);
			RenderNumber(str, dc, CPoint(90, 67));

			//	scores
			str.Format("%i", players[0].nScores);
			RenderNumber(str, dc, CPoint(60, 100));

			//	level
			str.Format("%i", nLevel + 1);
			RenderNumber(str, dc, CPoint(60, 135));
			str.Format("%i", nRound + 1);
			RenderNumber(str, dc, CPoint(90, 135));

			//	flame
			str.Format("%i", players[0].nBombFlameSize, dc, CPoint(60, 167));
			RenderNumber(str, dc, CPoint(60, 167));

			//	bombs
			str.Format("%i", players[0].nBombCount);
			RenderNumber(str, dc, CPoint(60, 200));
			/*RenderNumber(nTimeLeft / 25 / 60, dc, CPoint(60, 35));
			RenderNumber(nTimeLeft / 25 % 60, dc, CPoint(90, 35));
			
			RenderNumber(players[0].nLife, dc, CPoint(60, 67));
			RenderNumber(players[0].nContinues, dc, CPoint(90, 67));

			RenderNumber(players[0].Scores, dc, CPoint(60, 100));

			RenderNumber(nLevel + 1, dc, CPoint(60, 135));
			RenderNumber(nRound + 1, dc, CPoint(90, 135));

			RenderNumber(players[0].FlameSize2, dc, CPoint(60, 167));

			RenderNumber(players[0].BombCount, dc, CPoint(60, 200));
			break;
		}
		break;*/
	}
}

/////////////////////////////////////////////////////////////////
//
//	Function:			CMainFrame::PaintMonster()
//
/////////////////////////////////////////////////////////////////

void CMainFrame::PaintMonster(CDC				&dc,
															//CPoint		ptd,
															CPoint		pt,
															int				nKind,
															int				nPhase,
															int				nDirection,
															float			fDone)
{
	CPoint				pt1;

	if (nKind < 0/*-1 - NoBackMonsterCount*/ || nKind >= MonsterCount ||
		nPhase < 0 || nPhase >= MonsterCompletePhases * 2)
	{
		MessageBox("Неверный тип или фаза монстра");
		//ASSERT(FALSE);
		return;
	}

	pt1.x = pt.x * CellSize + BorderWidth;
	pt1.y = pt.y * CellSize + BorderWidth;

	switch (nDirection)
	{
	case 1:
		pt1.y -= CellSize * fDone;
		break;
	case 2:
		pt1.x += CellSize * fDone;
		break;
	case 3:
		pt1.y += CellSize * fDone;
		break;
	case 4:
		pt1.x -= CellSize * fDone;
		break;
	}

	//dc.FillSolidRect(pt1.x, pt1.y, CellSize / 2, CellSize / 2, RGB(0, 255, 0));
	/*if (!bmpMonsters[nKind][nPhase / 2].Render(dc, pt1))
	{
		nGameMode = Pause;
	}*/
	/*if (nKind < 0)
	{
		bmpNoBackMonsters[-2 - nKind][nPhase / 2].Render(dc, pt1);
	}*/
	/*else
	{*/
		if (nPhase / 2 >= MonsterPhases)
		{
			nPhase = MonsterCompletePhases * 2 - nPhase;
		}
		//bmpCycleMonsters[nKind][nPhase / 2].Render(dc, pt1);
		bmpMonsters[nKind][nPhase / 2].Render(dc, pt1);
	//}
}

/////////////////////////////////////////////////////////////////
//
//	Function:			CMainFrame::SetMonster()
//
/////////////////////////////////////////////////////////////////

void CMainFrame::SetMonster(int				nKind,
														CPoint		pt)
{
	int						i, j;
	//CPoint				pt;
	//CString				str;
	
	if (nKind < 0 || nKind >= MonsterCount)
	{
		MessageBox("Неверный тип монстра");
		//ASSERT(0);
		return;
	}

	if (pt.x == -1)
	{
		/*while(!CanLocate(pt, 0) || pt.x + pt.y < 5 ||
			(nPlayerCount == 2 && pt.x + pt.y > sz.cx + sz.cy - 5))*/
		j = 1;
		while (j)
		{
			j = 0;
			pt.x = sz.cx * rand() / RAND_MAX;
			pt.y = sz.cy * rand() / RAND_MAX;
			
			switch (nPlayerCount)
			{
			case 4:
				if (sz.cx - 1 - pt.x + pt.y < 5)
				{
					j = 1;
					break;
				}
			case 3:
				if (sz.cy - 1 - pt.y + pt.x < 5)
				{
					j = 1;
					break;
				}
			case 2:
				if (/*pt.x + pt.y > sz.cx + sz.cy - 5*/sz.cy - 1 - pt.y + sz.cx - 1 - pt.x < 5)
				{
					j = 1;
					break;
				}
				if (pt.x + pt.y < 5)
				{
					j = 1;
					break;
				}
				break;
			}
			if (j == 0 && !CanLocate(pt, 0))
			{
				j = 1;
			}
		}
	}
	//nGameMode = Pause;
	
	//nExitAvialable = 0;
	//nExitPhase = 0;
	/*switch (nKind)
	{
	case -1:
		for (i = 0; i < MaxSnakeCount; i++)
		{
			if (snakes[i].nLive == 0)
			{
				snakes[i].nLive = 1;
				for (j = 0; j < SnakeLen; j++)
				{
					snakes[i].components[j].nKind =			0;
					snakes[i].components[j].fDone =			0;
					snakes[i].components[j].fSpeed =		PlayerSpeed;
					snakes[i].components[j].fTurn	=			0;
					snakes[i].components[j].nFlying =		2;
					snakes[i].components[j].nPhase =		0;
					snakes[i].components[j].nDirection =		-1;
					snakes[i].components[j].pt =				pt;
					snakes[i].nLifes[j] =								3;
				}
				snakes[i].components[0].nKind = 1;
				snakes[i].components[SnakeLen - 1].nKind = 2;
				break;
			}
		}
		break;
	default:*/
	for (i = 0; i < MaxMonsterCount; i++)
	{
		if (monsters[i].nKind == -1)
		{
			monsters[i].nKind			= nKind;
			monsters[i].nDirection		= 0;
			monsters[i].pt				= pt;
			monsters[i].nPhase		= MonsterPhases * rand() / RAND_MAX;
			monsters[i].fDone			= 0;
			switch (nKind)
			{
			/*case -4:
				//	spinner
				monsters[i].fSpeed		= 1.2 * PlayerSpeed;
				monsters[i].nFlying		= 0;
				monsters[i].fTurn			= .3;
				break;
			case -3:
				//	frog2
				monsters[i].fSpeed		= PlayerSpeed;
				monsters[i].nFlying		= 0;
				monsters[i].fTurn			= .2;
				break;
			case -2:
				//	coin
				monsters[i].fSpeed		= 1.2 * PlayerSpeed;
				monsters[i].nFlying		= 1;
				break;*/

			case 0:
				//	orange
				monsters[i].fSpeed		= .8 * fPlayerSpeed;
				monsters[i].nFlying		= 0;
				monsters[i].fTurn			= 0;
				break;
			case 1:
				//	plum
				monsters[i].fSpeed		= .8 * fPlayerSpeed;
				monsters[i].nFlying		= 0;
				monsters[i].fTurn			= .1;
				break;
			case 2:
				//	broom
				monsters[i].fSpeed		= .9 * fPlayerSpeed;
				monsters[i].nFlying		= 1;
				monsters[i].fTurn			= .25;
				break;
			case 3:
				//	frog
				monsters[i].fSpeed		= fPlayerSpeed;
				monsters[i].nFlying		= 0;
				monsters[i].fTurn			= .25;
				break;
			/*case 4:
				//	ball
				monsters[i].fSpeed		= 1.1 * PlayerSpeed;
				monsters[i].nFlying		= 0;
				monsters[i].fTurn			= .3;
				break;*/
			case 4:
			case 5:
			case 6:
			case 7:
				//	deamon
				monsters[i].fSpeed		= fPlayerSpeed;
				monsters[i].nFlying		= 1;
				monsters[i].fTurn			= .25;
				break;
			case 8:
				//	violet
				monsters[i].fSpeed		= .8 * fPlayerSpeed;
				monsters[i].nFlying		= 0;
				monsters[i].fTurn			= .1;
				break;
			/*case 10:
			case 11:
			case 12:
				//	hare
				monsters[i].fSpeed		= PlayerSpeed;
				monsters[i].nFlying		= 1;
				monsters[i].fTurn			= .25;
				break;
			case 13:
				//	raspbarry
				monsters[i].fSpeed		= .8 * PlayerSpeed;
				monsters[i].nFlying		= 0;
				monsters[i].fTurn			= .15;
				break;
			case 14:
				//	onion
				monsters[i].fSpeed		= .87 * PlayerSpeed;
				monsters[i].nFlying		= 0;
				monsters[i].fTurn			= .25;
				break;*/
			case 9:
				//	crocodile
				monsters[i].fSpeed		= .85 * fPlayerSpeed;
				monsters[i].nFlying		= 0;
				monsters[i].fTurn			= 0;
				break;
			/*case 16:
				//	color frog
				monsters[i].fSpeed		= PlayerSpeed;
				monsters[i].nFlying		= 0;
				monsters[i].fTurn			= .3;
				break;
			case 17:
				//	jelly
				monsters[i].fSpeed		= .8 * PlayerSpeed;
				monsters[i].nFlying		= 0;
				monsters[i].fTurn			= .3;
				break;
			case 18:
				//	pig
				monsters[i].fSpeed		= 2 * PlayerSpeed;
				monsters[i].nFlying		= 0;
				monsters[i].fTurn			= 0;
				break;*/
			case 10:
				//	fire
				monsters[i].fSpeed		= .9 * fPlayerSpeed;
				monsters[i].nFlying		= 0;
				monsters[i].fTurn			= .25;
				break;
			}
			break;
		}
	}
	/*
	break;
	}*/
	//ASSERT(monsters[0].pt != monsters[1].pt);
}

/////////////////////////////////////////////////////////////////
//
//	Function:			CMainFrame::SortMonsters()
//
/////////////////////////////////////////////////////////////////

void CMainFrame::SortMonsters()
{
	int				i, j;

	for (i = 0, j = 0; j < MaxMonsterCount; i++, j++)
	{
		while (monsters[j].nKind == -1)
		{
			j++;
			if (j == MaxMonsterCount)
			{
				return;
			}
		}
		monsters[i] = monsters[j];
		if (i != j)
		{
			monsters[j].nKind = -1;
		}
	}
}

/////////////////////////////////////////////////////////////////
//
//	Function:			CMainFrame::OrderMonster()
//
/////////////////////////////////////////////////////////////////

void CMainFrame::OrderMonster(Monster			&monster)
{
	int				i, j;
	
	//srand(GetTickCount());
	
	/*switch (monster.nKind)
	{
	case 0:		//	orange
	case 1:		//	plum
	case 2:		//	broom
	case 3:		//	frog
	case 4:
	case 5:
	case 6:
	case 7:		//	deamon
	case 8:		//	violet
	case 9:		//	violet
	case 13:	//	raspbarry
	case 14:	//	onion
	case 15:	//	crocodile
	case 16:	//	color frog
	case 17:	//	jelly
	case 19:	//	fire

	case -3:	//	frog2
	case -4:	//	spinner

		//	turnable*/

	/*if (monster.pt == CPoint(4, 10))
		ASSERT(0);*/
	if (!CanLocate(MoveByDirection(monster.pt, monster.nDirection), monster.nFlying) ||
		rand() / (float)RAND_MAX < monster.fTurn)
	{
		for (i = 0; i < 50; i++)
		{
			j = 1 + 4 * rand() / RAND_MAX;
			if (CanLocate(MoveByDirection(monster.pt, j), monster.nFlying))
			{
				monster.nDirection = WrapDirection(j);
				switch (monster.nKind)
				{
				case 4:	//	deamon
				case 5:
				case 6:
				case 7:
					monster.nKind = monster.nDirection + 3;
					//ASSERT(FALSE);
					break;
				}
				return;
			}
		}
		monster.nDirection = -1;
	}
	else
	{
		if (monster.nDirection > 0)
		{
			return;
		}
		
		monster.nDirection = 1 + 4 * rand() / RAND_MAX;
		OrderMonster(monster);
	}

		/*break;

	case -2:		//	coin
	case 18:	//	pig
		monster.nDirection = FindPath(monster.pt, ptPlayers, nPlayerCount,
			monster.nFlying, 0, 1);
		break;*/
	/*case 10:	//	hare
	case 11:
	case 12:
		if (InDanger(monster.pt, 1, 0))
		{
			monster.nDirection = KeepOut(monster.pt, monster.nFlying,
				5, 1, 0);
		}
		else
		{
			//monster.nDirection = -1;

			if (!CanLocate(MoveByDirection(monster.pt, monster.nDirection), monster.nFlying) ||
				rand() / (float)RAND_MAX < monster.fTurn)
			{
				for (i = 0; i < 50; i++)
				{
					j = 1 + 4 * rand() / RAND_MAX;
					if (CanLocate(MoveByDirection(monster.pt, j), monster.nFlying) &&
						!InDanger(monster.pt, 1, 0))
					{
						monster.nDirection = WrapDirection(j);
						break;
					}
				}
				if (i == 50)
				{
					monster.nDirection = -1;
				}
			}
			else
			{
				
				monster.nDirection = 1 + 4 * rand() / RAND_MAX;
				OrderMonster(monster);
			}
			if (InDanger(MoveByDirection(monster.pt, monster.nDirection), 1, 0))
			{
				monster.nDirection = -1;
			}
			else
			{
				if ((float)rand() / (float)RAND_MAX < .03)
				{
					SetMonster(13, monster.pt);
				}
			}
		
		
		}
		break;*/
	//}
}

/////////////////////////////////////////////////////////////////
//
//	Function:			CMainFrame::OrderMonster()
//
/////////////////////////////////////////////////////////////////

bool CMainFrame::OnBomb(CPoint				pt)
{
	int				i;
	for (i = 0; i < MaxBombCount; i++)
	{
		if (bombs[i].nTimeLeft)
		{
			if (bombs[i].pt == pt)
			{
				return true;
			}
		}
		/*else
		{
			return false;
		}*/
	}
	return false;
}

/*
/////////////////////////////////////////////////////////////////
//
//	Function:			CMainFrame::SortBombs()
//
/////////////////////////////////////////////////////////////////

void CMainFrame::SortBombs()
{
	int				i, j;

	for (i = 0, j = 0; j < MaxBombCount; i++, j++)
	{
		for (; bombs[j].nTimeLeft == 0; j++)
		{
			if (j == MaxBombCount)
			{
				bombs[i].nTimeLeft = 0;
				bombs[i].nRealTimeLeft = 0;
				return;
			}
		}
		if (i != j)
		{
			bombs[i] = bombs[j];
			bombs[j].nTimeLeft = 0;
			bombs[j].nRealTimeLeft = 0;
		}
	}
}
*/

/////////////////////////////////////////////////////////////////
//
//	Function:			CMainFrame::SortPeases()
//
/////////////////////////////////////////////////////////////////

void CMainFrame::SortPeases()
{
	int			i, j;

	for (i = 0, j = 0; j < MaxPeasesCount; i++, j++)
	{
		while (peases[j].nPhase == -1)
		{
			j++;
			if (j == MaxPeasesCount)
			{
				return;
			}
		}
		if (i != j)
		{
			peases[i] = peases[j];
			peases[j].nPhase = -1;
		}
	}
}

/////////////////////////////////////////////////////////////////
//
//	Function:			CMainFrame::AddPease()
//
/////////////////////////////////////////////////////////////////

void CMainFrame::AddPease(CPoint				pt,
													int						nDirection,
													float					fDone)
{
	int				i;
	int				x, y;

	x = pt.x * CellSize;
	y = pt.y * CellSize;
	switch (nDirection)
	{
	case 1:
		y -= CellSize * fDone;
		break;
	case 2:
		x += CellSize * fDone;
		break;
	case 3:
		y += CellSize * fDone;
		break;
	case 4:
		x -= CellSize * fDone;
		break;
	}
	
	for (i = 0; i < MaxPeasesCount; i++)
	{
		if (peases[i].nPhase == -1)
		{
			peases[i].nPhase = 0;
			peases[i].pt.x = x;
			peases[i].pt.y = y;
			break;
		}
	}
}

/////////////////////////////////////////////////////////////////
//
//	Function:			CMainFrame::PaintPease()
//
/////////////////////////////////////////////////////////////////

void CMainFrame::PaintPease(CDC				&dc,
														//CPoint		ptd,
														CPoint		pt,
														int				nPhase)
{
	if (nPhase >= 0 && nPhase < PeasesPhases)
	{
		bmpPeases[nPhase].Render(dc, pt);
	}
	else
	{
		MessageBox("Неверная фаза отлетающих кусков");
	}
}

/////////////////////////////////////////////////////////////////
//
//	Function:			CMainFrame::Die()
//
/////////////////////////////////////////////////////////////////

void CMainFrame::Die(int			nPlayerID,
										 int			nFrom)
{
	int					i, j, k;

	/*if (nWinTime)
	{
		if (nLevel != -1 || players[nPlayerID].nLife == 0)
		{
			return;
		}
	}*/

	if (nPlayerID < 0 || nPlayerID >= min(nPlayerCount, MaxPlayerCount))
	{
		return;
	}

	AddPease(players[nPlayerID].pt, players[nPlayerID].nDirection,
		players[nPlayerID].fDone);
	sndPlaySound("die.wav", 1);
	//OnKeyDown(13, 0, 0);
	/*switch (nLevel)
	{
	case -1:*/
	//nDieTime = 20;
	/*if (nPlayerID == nFrom || nFrom == -1)
		players[nPlayerID].nFrags--;
	else
		players[nFrom].nFrags++;*/
	if (nPlayerID != nFrom && nFrom != -1)
		players[nFrom].nFrags++;
	if (nFrom == -1)
		players[nPlayerID].nFrags--;

	players[nPlayerID].nLife = 0;
	j = 0;
	//	считаем количество живых игроков
	for (i = 0; i < nPlayerCount; i++)
	{
		if (players[i].nLife)
		{
			j++;
			k = i;
		}
	}
	//if (j == 1)
	switch (j)
	{
	case 1:
		//	остался только один - даём ему очко
		nWinTime = 20;		//	счастливый зелёный экран через 20 тиков

		if (nLastWinner != -1)
			players[nLastWinner].nScores--;		//	отнимаем очко у бывшего победителя

		players[k].nScores++;								//	даём очко новому

		nLastWinner = k;	//	запоминаем игрока - вдруг его зацепит последней бомбой,
											//	тогда это очко отнимем
		break;
	
	case 0:
		//	все погибли
		if (nLastWinner != -1)
			players[nLastWinner].nScores--;	//	так и получилось - отнимаем очко,
		nDieTime = 20;										//	красный экран через 20 тиков
		break;
	
	default:
		//	считаем количество "человеческих" игроков
		j = 0;
		for (i = 0; i < nPlayerCount; i++)
		{
			if (players[i].nComp == 0 && players[i].nLife)
			{
				j++;
			}
		}
		if (j == 0)
		{
			//	все люди померли - взрываем все оставшиеся не взорванными бомбы,
			//	вдруг зацепит ещё кого-нибудь
			/*for (i = 0; i < MaxBombCount; i++)
			{
				if (bombs[i].nTimeLeft)
				{
					bombs[i].nTimeLeft = 0;
					Blow(bombs[i]);
				}
			}*/

			//	снова сосчитаем, сколько там живых осталось
			j = 0;
			for (i = 0; i < nPlayerCount; i++)
			{
				if (players[i].nLife)
				{
					j++;
				}
			}
			
			//	если все сдохли,
			if (j == 0)
			{
				if (nLastWinner != -1)
					players[nLastWinner].nScores--;		//	отнимаем очко у того, кого ранее
																						//	считали победителем.
				nDieTime = 20;									//	красный экран через 20 тиков.
				return;												//	выходим.
			}

			//	определим победителя среди компьютеров случайным образом -
			//	геймеру будет скучно смотреть всю схватку до конца, если он уже сдох
			while (true)
			{
				i = rand() * nPlayerCount / (RAND_MAX + 1);

				if (players[i].nLife/* && players[i].nComp*/)
				{
					// нашли живого компьютерного игрока
					players[i].nScores++;								//	даём ему деньги
					if (nLastWinner != -1)
						players[nLastWinner].nScores--;		//	отнимаем их у бывшего победителя
					nLastWinner = i;										//	запоминаем игрока
					nWinTime = 20;											//	зелёный экран через 20 тиков
					break;
				}
			}
		}

	}
	/*default:
		nDieTime = 20;
		break;
	}*/
	//OnKeyDown(13, 0, 0);
	/*nDieTime = 20;
	nDeadPlayer = nPlayerID;*/
}

/////////////////////////////////////////////////////////////////
//
//	Function:			CMainFrame::Win()
//
/////////////////////////////////////////////////////////////////

void CMainFrame::Win()
{
	nWinTime = 40;
	ptPlayerQuits.x = players[0].pt.x * CellSize + BorderWidth;
	ptPlayerQuits.y = players[0].pt.y * CellSize + BorderWidth - 20;
}

/////////////////////////////////////////////////////////////////
//
//	Function:			CMainFrame::CheckMonster()
//
/////////////////////////////////////////////////////////////////

void CMainFrame::CheckMonster(Monster &monster)
{
	int						i;
	if (nDieTime)
	{
		return;
	}

	CPoint				ptMonsterDirection;
	CPoint				ptPlayerDirection;

	for (i = 0; i < nPlayerCount; i++)
	{
		if (players[i].nLife)
		{
			if (players[i].pt == monster.pt)
			{
				if (players[i].nDirection == monster.nDirection/* ||
					monster.nDirection == 0*/)
				{
					Die(i, -1);
					return;
				}
				else
				{
					if (players[i].fDone + monster.fDone < 1)
					{
						Die(i, -1);
						return;
					}
				}
			}

			ptMonsterDirection = MoveByDirection(monster.pt, monster.nDirection);
			ptPlayerDirection = MoveByDirection(players[i].pt, players[i].nDirection);

			if (ptMonsterDirection == ptPlayerDirection &&
				monster.fDone + players[i].fDone > 1.3/*.65*/)
			{
				Die(i, -1);
				return;
			}
			
			if (monster.pt == ptPlayerDirection && players[i].pt == ptMonsterDirection)
			{
				Die(i, -1);
				return;
			}

			if (monster.pt == ptPlayerDirection && players[i].fDone > monster.fDone + .3)
			{
				Die(i, -1);
				return;
			}

			if (players[i].pt == ptMonsterDirection &&
				monster.fDone > players[i].fDone + .3)
			{
				Die(i, -1);
				return;
			}
		}
	}
}

/////////////////////////////////////////////////////////////////
//
//	Function:			CMainFrame::Swap()
//
/////////////////////////////////////////////////////////////////

void CMainFrame::Swap(int		&a,
											int		&b)
{
	int			temp;

	temp = a;
	a = b;
	b = temp;
}

/////////////////////////////////////////////////////////////////
//
//	Function:			CMainFrame::FindPath()
//
/////////////////////////////////////////////////////////////////

int CMainFrame::FindPath(CPoint				ptStart,
												 CPoint				ptEnd[],
												 int					nEndCount,
												 int					nFlying,
												 int					nFindEx,
												 int					nRandomOnFail,
												 int					nMaxLen,
												 int					nObject,
												 int					nGetLen)
{
	int				i, j, k, l;
	int				nExitFlag = 0;
	//int				*nTempArea = new int[sz.cx * sz.cy];
	int				nMonsterTable[ScreenSize][ScreenSize];
	int				nTempArea[ScreenSize * ScreenSize];
	int				nStepFound = 1;
	int				nFound = 0;
	int				nDirections[4] = {1, 2, 3, 4};

	CPoint		pt;
	CPoint		pt2;
	CPoint		ptLastSteps[ScreenSize * 3];
	CPoint		ptCurrentSteps[ScreenSize * 3];
	
	for (i = 0; i < 3; i++)
	{
		Swap(
			nDirections[rand() * 4 / (RAND_MAX + 1)],
			nDirections[rand() * 4 / (RAND_MAX + 1)]);
	}

	for (i = 0; i < ScreenSize * 3; i++)
	{
		ptLastSteps[i].x = -1;
		ptLastSteps[i].y = -1;
		ptCurrentSteps[i].x = -1;
		ptCurrentSteps[i].y = -1;
	}
	for (i = 0; i < sz.cx * sz.cy; i++)
	{
		nTempArea[i] = 0;
	}
	
	ptCurrentSteps[0] = ptStart;
	i = 1;
	nTempArea[ptStart.x + ptStart.y * sz.cx] = 1;

	if (nGetLen)
	{
		for (i = 0; i < nEndCount; i++)
		{
			if (ptStart == ptEnd[i])
			{
				//delete [] nTempArea;
				return 0;
			}
		}
	}

	switch (nFindEx)
	{
	case 4:		// monster
		for (i = 0; i < ScreenSize; i++)
		{
			for (j = 0; j < ScreenSize; j++)
			{
				nMonsterTable[i][j] = 0;
			}
		}
		for (i = 0; i < MaxMonsterCount; i++)
		{
			if (monsters[i].nKind != -1)
			{
				nMonsterTable[monsters[i].pt.x][monsters[i].pt.y] = 1;
				pt = MoveByDirection(monsters[i].pt, monsters[i].nDirection);
				nMonsterTable[pt.x][pt.y] = 1;
			}
		}
		break;
	}

	i = 1;
	while (nExitFlag == 0)
	{
		i++;
		if (nMaxLen)
		{
			if (i > nMaxLen)
			{
				nExitFlag = 1;
			}
		}

		for (j = 0; j < min(nStepFound, ScreenSize * 3); j++)
		{
			ptLastSteps[j] = ptCurrentSteps[j];
		}
		for (; j < ScreenSize * 3; j++)
		{
			ptLastSteps[j].x = -1;
			ptLastSteps[j].y = -1;
		}

		nStepFound = 0;

		for (j = 0; j < ScreenSize * 3; j++)
		{
			if (ptLastSteps[j].x == -1)
			{
				break;
			}

			for (k = 1; k < 5; k++)
			{
				pt = MoveByDirection(ptLastSteps[j], nDirections[k - 1]);
				if (ValidPt(pt) && nTempArea[pt.x + pt.y * sz.cx] == 0)
				{
					if (CanLocate(pt, nFlying) || (nFindEx == 3 && CanLocate(pt, 1)))
					{
						nTempArea[pt.x + pt.y * sz.cx] = i;
						ptCurrentSteps[nStepFound] = pt;
						nStepFound++;
						switch (nFindEx)
						{
						case 1:		//	prize
							if (Area[pt.x][pt.y].nExit > 1 && Area[pt.x][pt.y ].nExit != 4)
							{
								pt2 = pt;
								nFound = 1;
								if (nGetLen)
								{
									//delete [] nTempArea;
									return i - 1;
								}
								goto found;
							}
							break;
						case 2:		//	prize or player
							for (l = 0; l < nPlayerCount; l++)
							{
								if (players[l].nLife && l != nObject)
								{
									if ((Area[pt.x][pt.y].nExit > 1 && Area[pt.x][pt.y].nExit != 4)
										|| ptEnd[l] == pt)
									{
										pt2 = pt;
										nFound = 1;
										if (nGetLen)
										{
											//delete [] nTempArea;
											return i - 1;
										}
										goto found;
									}
								}
							}
							break;
						case 3:		//	brick
							switch (Area[pt.x][pt.y].nBrick)
							{
							case 1:
							case 2:
							case 3:
								pt2 = pt;
								nFound = 1;
								if (nGetLen)
								{
									//delete [] nTempArea;
									return i - 1;
								}
								goto found;
								break;
							}
							break;
						case 4:		//	monster
							if (nMonsterTable[pt.x][pt.y])
							{
								pt2 = pt;
								nFound = 1;
								if (nGetLen)
								{
									//delete [] nTempArea;
									return i - 1;
								}
								goto found;
							}
						}
					}
				}
			}
		}

		if (nStepFound == 0)
		{
			nExitFlag = 1;
		}

		switch (nFindEx)
		{
		case 0:		//	none
			for (j = 0; j < nEndCount; j++)
			{
				if (nTempArea[ptEnd[j].x + ptEnd[j].y * sz.cx])
				{
					nFound = 1;
					if (nGetLen)
					{
						//delete [] nTempArea;
						return i - 1;
					}
					
					pt2 = ptEnd[j];
					break;

					/*
					for (k = i; k > 2; k--)
					{
						for (l = 1; l < 5; l++)
						{
							pt2 = MoveByDirection(pt, l);
							if (nTempArea[pt2.x + pt2.y * sz.cx] == k - 1)
							{
								pt = pt2;
								break;
							}
						}
					}
					*/

					/*delete []nTempArea;
					return GetDirection(ptStart, pt);*/
				}
			}
			break;
		/*case 1:		//	prize
			if (nTempArea)
			break;*/
		}
		if (nFound)
		{
found:
			//		found!
			for (k = i; k > 2; k--)
			{
				for (l = 1; l < 5; l++)
				{
					pt = MoveByDirection(pt2, nDirections[l - 1]);
					if (pt.x >= 0 && pt.x < sz.cx && pt.y >= 0 && pt.y < sz.cy)
					{
						if (nTempArea[pt.x + pt.y * sz.cx] == k - 1)
						{
							pt2 = pt;
							break;
						}
					}
				}
			}

			//delete [] nTempArea;
			return GetDirection(ptStart, pt2);

		}
	}
	
	//delete []nTempArea;
	
	if (nRandomOnFail)
	{
		for (i = 0; i < 50; i++)
		{
			i = 1 + 3.999 * rand() / RAND_MAX;

			if (CanLocate(MoveByDirection(ptStart, i), nFlying))
			{
				return i;
			}
		}
	}
	
	return -1;
}

/////////////////////////////////////////////////////////////////
//
//	Function:			CMainFrame::GetDirection()
//
/////////////////////////////////////////////////////////////////

int CMainFrame::GetDirection(CPoint			ptStart,
													CPoint			ptEnd)
{
	switch (ptEnd.x - ptStart.x)
	{
	case 1:
		return 2;
		break;
	case 0:
		switch (ptEnd.y - ptStart.y)
		{
		case 1:
			return 3;
			break;
		case 0:
			return -1;
			break;
		case -1:
			return 1;
			break;
		}
		break;
	case -1:
		return 4;
		break;
	}
	return 0;
}

/////////////////////////////////////////////////////////////////
//
//	Function:			CMainFrame::Restart()
//
/////////////////////////////////////////////////////////////////

bool CMainFrame::Restart(/*int			nPlayers*/)
{
	int				i;
	nGameMode = PlayMode;
	/*switch (nPlayers)
	{
	case 1:
		//nLevel = 7;
		//nRound = 1;
		nLevel = 0;
		nRound = 0;
		nPlayerCount = 1;
		players[0].nScores = 0;
		CreatePlayer(players[0], 0, 0);
		//players[0].fSpeed = .2;
		//players[0].nBombCount = 10;
		//players[0].nBombFlameSize = 5;
		break;
	default:*/
	CDM			dm;
	CWinApp	*theApp;

	theApp = AfxGetApp();

	nDMBackground			=	theApp->GetProfileInt("1.1", "DM_Texture", 0);
	fDMPrizes					= (float)theApp->GetProfileInt("1.1", "DM_Prizes", 50) / 100.0;
	fDMMonsters				= (float)theApp->GetProfileInt("1.1", "DM_Monsters", 50) / 100.0;
	fDMFullness				= (float)theApp->GetProfileInt("1.1", "DM_Fullness", 30) / 100.0;
	nDMComp						= theApp->GetProfileInt("1.1", "DM_Comp", 0);
	nDMWithSkulls			= theApp->GetProfileInt("1.1", "DM_Skulls", 1);
	nDMPlayerCount		= theApp->GetProfileInt("1.1", "DM_PlayerCount", 2);
	nRandomTexture		= theApp->GetProfileInt("1.1", "DM_RandomTexture", 1);
	nCountMode				= theApp->GetProfileInt("1.1", "CountMode", 1);

	if (nRandomTexture)
		nDMBackground = BackgroundCount;

	if (!dm.GetDMInfo(nDMBackground, fDMPrizes, fDMMonsters, fDMFullness,
		nDMPlayerCount, nDMComp, nDMWithSkulls))
	{
		//DestroyWindow();
		//::PostQuitMessage(0);
		return false;
	}

	nRandomTexture = (nDMBackground == BackgroundCount);
	/*if (nDMBackground == BackgroundCount)
	{
		nRandomTexture = 1;
	}
	else
	{
		nRandomTexture = 
	}*/

	theApp->WriteProfileInt("1.1", "DM_Texture", nDMBackground);
	theApp->WriteProfileInt("1.1", "DM_Prizes", fDMPrizes * 100);
	theApp->WriteProfileInt("1.1", "DM_Monsters", fDMMonsters * 100);
	theApp->WriteProfileInt("1.1", "DM_Fullness", fDMFullness * 100);
	theApp->WriteProfileInt("1.1", "DM_Comp", nDMComp);
	theApp->WriteProfileInt("1.1", "DM_Skulls", nDMWithSkulls);
	theApp->WriteProfileInt("1.1", "DM_PlayerCount", nDMPlayerCount);
	theApp->WriteProfileInt("1.1", "DM_RandomTexture", nRandomTexture);
	theApp->WriteProfileInt("1.1", "CountMode", nCountMode);

	//nLevel = -1;
	//nRound = 0;
	nBackgroundID = nDMBackground;
	nPlayerCount = nDMPlayerCount;
	for (i = 0; i < nPlayerCount; i++)
	{
		players[i].nScores	= 0;
		players[i].nFrags		= 0;
	}
	//break;
	//}
	LoadLevel(/*nLevel, nRound*/);
	return true;
}

/////////////////////////////////////////////////////////////////
//
//	Function:			CMainFrame::ValidPt()
//
/////////////////////////////////////////////////////////////////

bool CMainFrame::ValidPt(CPoint				pt)
{
	return (pt.x >= 0 && pt.x < sz.cx && pt.y >= 0 && pt.y < sz.cy);
}

/////////////////////////////////////////////////////////////////
//
//	Function:			CMainFrame::CleanBrick()
//
/////////////////////////////////////////////////////////////////

void CMainFrame::CleanBrick(CPoint		pt)
{
	int				i, j;

	for (i = 0; i < nBrickCount; i++)
	{
		if (ptBricks[i] == pt)
		{
			for (j = i; j < nBrickCount - 1; j++)
			{
				ptBricks[j] = ptBricks[j + 1];
			}
			ptBricks[j].x = -1;
			Area[pt.x][pt.y].nBrick = 0;
			//Area[pt.x][pt.y].nBlink = 0;
			nBrickCount--;
			/*if (Area[pt.x][pt.y].nExit == 1 && nBrickCount == 0)
			{
				AddPrize(5, 1);
			}*/
			break;
		}
	}
}

/////////////////////////////////////////////////////////////////
//
//	Function:			CMainFrame::AddPrize()
//
/////////////////////////////////////////////////////////////////

bool CMainFrame::AddPrize(int				nKind,
													int				nAlwaysVisible)
{
	int					i, j, k, l;
	if (nKind <= 0)
	{
		return false;
	}

	if (nBrickCount <= 0)
	{
		i = -1;
		while (i == -1 || !CanLocate(CPoint(i, j), 1) || Area[i][j].nExit != 0)
		{
			i = ((float)sz.cx - .001) * rand() / RAND_MAX;
			j = ((float)sz.cy - .001) * rand() / RAND_MAX;
		}
		Area[i][j].nExit = nKind;
		/*if (nAlwaysVisible)
		{
			Area[i][j].nExitVisible = 1;
		}
		else
		{
			Area[i][j].nExitVisible = 0;
		}*/
	}
	else
	{
		k = -1;
		l = 0;
		while (k == -1 || Area[i][j].nExit != 0)
		//for (l = 0; (k == -1 || Area[i][j].nExit != 0) && l < 1000; l++)
		{
			k = (nBrickCount - .001) * rand() / RAND_MAX;
			i = ptBricks[k].x;
			j = ptBricks[k].y;
			l++;
			if (l > 1000)
			{
				return false;
			}
		}
		Area[i][j].nExit = nKind;
		//Area[i][j].nExitVisible = 1;
	}
	return true;
}

/////////////////////////////////////////////////////////////////
//
//	Function:			CMainFrame::OnLButtonDown()
//
/////////////////////////////////////////////////////////////////

void CMainFrame::OnLButtonDown(UINT			nFlags,
															 CPoint		pt)
{
	CWnd::OnLButtonDown(nFlags, pt);

	/*if (PtInRect(CRect(ButtonMainX + GameX, ButtonMainY + GameY,
		ButtonMainX + ButtonWidth + GameX, ButtonMainY + ButtonHeight + GameY), pt))
	{
		nButtonID = 1;
	}

	if (PtInRect(CRect(
		ButtonMainX + ButtonWidth + 5 + GameX,
		ButtonMainY + GameY,
		ButtonMainX + ButtonWidth * 2 + 5 + GameX,
		ButtonMainY + ButtonHeight + GameY), pt))
	{
		nButtonID = 2;
	}*/

	if (PtInRect(CRect(
		Button1X,
		Button1Y,
		Button1X + ButtonWidth,
		Button1Y + ButtonHeight), pt))
	{
		//nButtonID = 3;
		Restart();
	}

	if (PtInRect(CRect(
		Button2X,
		Button2Y,
		Button2X + ButtonWidth,
		Button2Y + ButtonHeight), pt))
	{
		//nButtonID = 4;
		switch (nGameMode)
		{
		case PlayMode:
			nGameMode = Pause;
			break;
		case Pause:
			nGameMode = PlayMode;
			break;
		}
	}
}

/*
/////////////////////////////////////////////////////////////////
//
//	Function:			CMainFrame::OnLButtonUp()
//
/////////////////////////////////////////////////////////////////

void CMainFrame::OnLButtonUp(UINT				nFlags,
														 CPoint			pt)
{
	CFrameWnd::OnLButtonUp(nFlags, pt);
	
	switch (nButtonID)
	{
	case 3:
		Restart();
		break;
	case 4:
		switch (nGameMode)
		{
		case Pause:
			nGameMode = PlayMode;
			break;
		case PlayMode:
			nGameMode = Pause;
			break;
		}
	}

	nButtonID = 0;
}
*/
/////////////////////////////////////////////////////////////////
//
//	Function:			CMainFrame::OnMouseMove()
//
/////////////////////////////////////////////////////////////////

void CMainFrame::OnMouseMove(UINT				nFlags,
														 CPoint			pt)
{
	//nButtonID = 0;
	if (PtInRect(CRect(Button1X, Button1Y, Button1X + ButtonWidth, Button1Y + ButtonHeight), pt))
	{
		//nButtonID = 1;
		SetButtonID(1);
	}
	else
	{
		if (PtInRect(CRect(Button2X, Button2Y, Button2X + ButtonWidth, Button2Y + ButtonHeight), pt))
		{
			//nButtonID = 2;
			SetButtonID(2);
		}
		else
		{
			SetButtonID(0);
		}
	}
	CWnd::OnMouseMove(nFlags, pt);
}

/////////////////////////////////////////////////////////////////
//
//	Function:			CMainFrame::PaintSnake()
//
/////////////////////////////////////////////////////////////////

/*void CMainFrame::PaintSnake(Snake				snake,
														CDC					&dc,
														CPoint			ptd)
{
	int					i, j, k;
	CPoint			pt;
	CString			str;

	if (snake.components[0].nPhase > SnakePictures - 1)
	{
		k = SnakePhases - snake.components[0].nPhase;
	}
	else
	{
		k = snake.components[0].nPhase;
	}

	for (i = SnakeLen - 1; i >= 0; i--)
	{
		pt.x = snake.components[i].pt.x * CellSize - ptd.x + BorderWidth;
		pt.y = snake.components[i].pt.y * CellSize - ptd.y + BorderWidth;
		
		switch (snake.components[i].nDirection)
		{
		case 1:
			pt.y -= snake.components[0].fDone * CellSize;
			break;
		case 2:
			pt.x += snake.components[0].fDone * CellSize;
			break;
		case 3:
			pt.y += snake.components[0].fDone * CellSize;
			break;
		case 4:
			pt.x -= snake.components[0].fDone * CellSize;
			break;
		}

		/*str.Format("%i", snake.components[i].nDirection);
		MessageBox(str);
		if (snake.components[i].nDirection == -1)
		{
			j = 0;
		}
		else
		{
			j = snake.components[i].nDirection - 1;
		}
		
		/*if (snake.components[0].nPhase > SnakePictures + 1)
		{
			k = SnakePhases - snake.components[0].nPhase;
		}
		else
		{
			k = snake.components[0].nPhase;
		}

		str.Format("%i\n%i\n%i\n%i\n%i",
			j, snake.components[i].nKind, 3 - snake.nLifes[i],
			snake.components[0].nPhase, i);
		//MessageBox(str);
#ifdef WithSnake
		bmpSnake
			[j]
			[snake.components[i].nKind]
			[3 - snake.nLifes[i]]
			[k]
			.Render(dc, pt);
#else
		bmpSnake
			[j]
			[snake.components[i].nKind]
			[3 - snake.nLifes[i]]
			[0]
			.Render(dc, pt);
		//break;
		//dc.FillSolidRect(pt.x, pt.y, CellSize, CellSize, RGB(0, 255, 0));
#endif
	}
}
*/
/////////////////////////////////////////////////////////////////
//
//	Function:			CMainFrame::KilledAll()
//
/////////////////////////////////////////////////////////////////
/*
bool CMainFrame::KilledAll()
{
	int				i;
	
	for (i = 0; i < MaxSnakeCount; i++)
	{
		if (snakes[i].nLive)
		{
			return false;
		}
	}
	return (monsters[0].nKind == -1);
}
*/
/*/////////////////////////////////////////////////////////////////
//
//	Function:			CMainFrame::SetExitAvialable()
//
/////////////////////////////////////////////////////////////////

void CMainFrame::SetExitAvialable()
{
	int				i, j;

	nExitAvialable = 1;
	nExitPhase = 0;

	for (i = 0; i < sz.cx; i++)
	{
		for (j = 0; j < sz.cy; j++)
		{
			switch (Area[i][j].nExit)
			{
			case 0:
			case 1:
				break;
			default:
				Area[i][j].nBlink = 1;
			}
		}
	}

	for (i = 0; i < sz.cx; i++)
	{
		for (j = 0; j < sz.cy; j++)
		{
			if (Area[i][j].nExit == 1)
			{
				Area[i][j].nExitVisible = 1;
				return;
			}
		}
	}

	//AddPrize(1, 1);
}

/////////////////////////////////////////////////////////////////
//
//	Function:			CMainFrame::BlowExit()
//
/////////////////////////////////////////////////////////////////

void CMainFrame::BlowExit(CPoint			pt)
{
	int				i, j;
	CString		str;

	j = 1;
	while (j)
	{
		i = rand() * (MonsterCount - .001) / (float)RAND_MAX;
		switch (i)
		{
		case 10:
		case 11:
		case 12:
			break;
		default:
			j = 0;
		}
	}
	str.Format("%i", i);
	MessageBox(str);

	for (j = 0; j < 4; j++)
	{
		SetMonster(i, pt);
	}
}

/////////////////////////////////////////////////////////////////
//
//	Function:			CMainFrame::RevertPlayer()
//
/////////////////////////////////////////////////////////////////

void CMainFrame::RevertPlayer(Player		&player)
{
	player.nBombCount				= player.nLastBombCount;
	player.nBombFlameSize		=	player.nLastFlameSize;
	player.fSpeed						= player.fLastSpeed;
	player.nEnter						= 0;
	player.nFuckBombs				= 0;
	player.nFlying					= 0;
}

/////////////////////////////////////////////////////////////////
//
//	Function:			CMainFrame::AddNumber()
//
/////////////////////////////////////////////////////////////////

void CMainFrame::AddNumber(CPoint				pt,
													 int					nDirection,
													 float				fDone,
													 int					nNumber,
													 int					nTimeLeft)
{
	int				i;

	for (i = 0; i < MaxPeasesCount; i++)
	{
		if (numbers[i].nTimeLeft == 0)
		{
			switch (nDirection)
			{
			case -1:
				pt.x = pt.x * CellSize + BorderWidth;
				pt.y = pt.y * CellSize + BorderWidth;
				break;
			case 1:
				pt.x = pt.x * CellSize + BorderWidth;
				pt.y = (pt.y - fDone) * CellSize + BorderWidth;
				break;
			case 2:
				pt.x = (pt.x + fDone) * CellSize + BorderWidth;
				pt.y = pt.y * CellSize + BorderWidth;
				break;
			case 3:
				pt.x = pt.x * CellSize + BorderWidth;
				pt.y = (pt.y + fDone) * CellSize + BorderWidth;
				break;
			case 4:
				pt.x = (pt.x - fDone) * CellSize + BorderWidth;
				pt.y = pt.y * CellSize + BorderWidth;
				break;
			}
			numbers[i].nNumber		= nNumber;
			numbers[i].nTimeLeft	=	nTimeLeft;
			numbers[i].pt					= pt;
			break;
		}
	}
}
*/
/////////////////////////////////////////////////////////////////
//
//	Function:			CMainFrame::AddDMPrize()
//
/////////////////////////////////////////////////////////////////

bool CMainFrame::AddDMPrize()
{
	float			f;

	f = (float)rand() / (float)(RAND_MAX + 1);

	/*switch (nDMWithSkulls)
	{
	case 0:
		if (f < .39)
			return AddPrize(2, 1);					//	fire
		else
		{
			if (f < .77)
				return AddPrize(3, 1);				//	bomb
			else
			{
				if (f < .77)									//	fuck bombs
					return AddPrize(4, 1);
				else
				{
					if (f < .98)								//	speed
						return AddPrize(5, 1);
					else
						return AddPrize(6, 1);		//	flying
				}
			}
		}
		break;
	case 1:
		if (f < .29)
			return AddPrize(2, 1);					//	fire
		else
		{
			if (f < .57)
				return AddPrize(3, 1);				//	bomb
			else
			{
				if (f < .57)									//	fuck bombs
					return AddPrize(4, 1);
				else
				{
					if (f < .78)								//	speed
						return AddPrize(5, 1);
					else
					{
						if (f < .8)
							return AddPrize(6, 1);	//	flying
						else
							return AddPrize(7, 1);	//	skull
					}
				}
			}
		}*/
	switch (nDMWithSkulls)
	{
	case 0:
		if (f < .5)
		{
			return AddPrize(2, 1);
		}
		else
		{
			return AddPrize(3, 1);
		}
		break;
	case 1:
		if (f < .35)
		{
			return AddPrize(2, 1);
		}
		else
		{
			if (f < .7)
			{
				return AddPrize(3, 1);
			}
			else
			{
				return AddPrize(4, 1);
			}
		}
		break;
	}

	return false;
}

/////////////////////////////////////////////////////////////////
//
//	Function:			CMainFrame::AddDMMonster()
//
/////////////////////////////////////////////////////////////////

void CMainFrame::AddDMMonster(int			&nPoints)
{
	int				nMonsterPoints[/*CycleMonsterCount*/MonsterCount];
	int				i;

	nMonsterPoints[0]		= 1;			//	orange
	nMonsterPoints[1]		= 3;			//	plum
	nMonsterPoints[2]		= 10;			//	broom
	nMonsterPoints[3]		= 5;			//	frog
	//nMonsterPoints[4]		= 8;			//	ball
	nMonsterPoints[4]		= 15;			//	deamon
	nMonsterPoints[5]		= 15;
	nMonsterPoints[6]		= 15;
	nMonsterPoints[7]		= 15;
	nMonsterPoints[8]		= 6;			//	violet
	/*nMonsterPoints[10]	= 9999;		//	hare
	nMonsterPoints[11]	= 9999;
	nMonsterPoints[12]	= 9999;
	nMonsterPoints[13]	= 9999;		//	raspberry*/
	//nMonsterPoints[10]	= 4;			//	onion
	nMonsterPoints[9]	= 2;			//	crocodile
	//nMonsterPoints[12]	= 6;			//	color frog
	//nMonsterPoints[13]	=	4;			//	jelly
	//nMonsterPoints[18]	= 9999;		//	pig
	nMonsterPoints[10]	=	8;			//	fire

	i = rand() * ((float)MonsterCount - .001) / RAND_MAX;
	while (nPoints < nMonsterPoints[i])
	{
		i = rand() * ((float)MonsterCount - .001) / RAND_MAX;
	}
	nPoints -= nMonsterPoints[i];
	SetMonster(i);
	//SetMonster(-4);
}

/////////////////////////////////////////////////////////////////
//
//	Function:			CMainFrame::OnMouseWheel()
//
/////////////////////////////////////////////////////////////////

BOOL CMainFrame::OnMouseWheel(UINT				nFlags,
															short				zDelta,
															CPoint			pt)
{
	if (zDelta < 0)
	{
		nBackgroundID++;
		if (nBackgroundID >= BackgroundCount)
		{
			nBackgroundID = 0;
		}
	}
	if (zDelta > 0)
	{
		nBackgroundID--;
		if (nBackgroundID < 0)
		{
			nBackgroundID = BackgroundCount - 1;
		}
	}
	nDMBackground = nBackgroundID;
	return CWnd::OnMouseWheel(nFlags, zDelta, pt);
}

/////////////////////////////////////////////////////////////////
//
//	Function:			CMainFrame::KeepOut()
//
/////////////////////////////////////////////////////////////////

int CMainFrame::KeepOut(CPoint			pt,
												int					nFlying,
												int					nLen,
												int					nFromBombs,
												int					nFromMonsters,
												float				fSpeed,
												int					nExtra)
{
	int				nTempArea[MaxSize][MaxSize];
	CPoint		ptCurrent[MaxSize];
	CPoint		ptLast[MaxSize];
	CPoint		ptSafe[MaxSize];
	CPoint		ptTemp1;
	CPoint		ptTemp2;
	int				i, j, k;
	int				nSafetyArea;
	int				nSafetyPointID;
	int				nStepFound;
	int				nSafeFound = 0;
	int				nDirections[] = {1, 2, 3, 4};
	int				nTimeStep;
	int				nTime = 0;

	if (fSpeed == 0)
		nTimeStep = 0;
	else
	{
		nTimeStep = 1 / fSpeed + 1;
	}

	for (i = 0; i < 3; i++)
	{
		Swap(
			nDirections[rand() * 4 / (RAND_MAX + 1)],
			nDirections[rand() * 4 / (RAND_MAX + 1)]);
	}

	for (i = 0; i < MaxSize; i++)
	{
		for (j = 0; j < MaxSize; j++)
		{
			nTempArea[i][j] = 0;
		}
	}
	nTempArea[pt.x][pt.y] = 1;

	for (i = 1; i < MaxSize; i++)
	{
		ptLast[i].x = -1;
	}
	ptLast[0] = pt;

	nStepFound = 0;
	for (k = 2; k < nLen + 2; k++)
	{
		nTime += nTimeStep;
		for (i = 0; i < MaxSize; i++)
		{
			if (ptLast[i].x == -1)
			{
				break;
			}
			for (j = 1; j < 5; j++)
			{
				ptCurrent[nStepFound] = MoveByDirection(ptLast[i], nDirections[j - 1]);
				if (CanLocate(ptCurrent[nStepFound], nFlying) &&
					nTempArea[ptCurrent[nStepFound].x][ptCurrent[nStepFound].y] == 0)
				{
					switch (nExtra)
					{
					case 0:
						switch (InDanger(ptCurrent[nStepFound], nFromBombs, nFromMonsters, nTime))
						{
						case 0:
							ptSafe[nSafeFound] = ptCurrent[nStepFound];
							nSafeFound++;
							/*
							ptCurrent[0] = ptCurrent[nStepFound];
							for (; k != 2; k--)
							{
								for (j = 1; j < 5; j++)
								{
									ptCurrent[1] = MoveByDirection(ptCurrent[0], nDirections[j - 1]);
									if (nTempArea[ptCurrent[1].x][ptCurrent[1].y] == k - 1)
									{
										ptCurrent[0] = ptCurrent[1];
										break;
									}
								}
							}
							return GetDirection(pt, ptCurrent[0]);
							*/
							//break;
						case 1:
							nTempArea[ptCurrent[nStepFound].x][ptCurrent[nStepFound].y] = k;
							nStepFound++;
							break;
						}
						break;
					case 1:
						switch (InDanger(ptCurrent[nStepFound], nFromBombs, nFromMonsters, nTime))
						{
						case 1:
						case 0:
							ptSafe[nSafeFound] = ptCurrent[nStepFound];
							nSafeFound++;
							/*
							ptCurrent[0] = ptCurrent[nStepFound];
							for (; k != 2; k--)
							{
								for (j = 1; j < 5; j++)
								{
									ptCurrent[1] = MoveByDirection(ptCurrent[0], nDirections[j - 1]);
									if (nTempArea[ptCurrent[1].x][ptCurrent[1].y] == k - 1)
									{
										ptCurrent[0] = ptCurrent[1];
										break;
									}
								}
							}
							return GetDirection(pt, ptCurrent[0]);*/
							//break;
						case 2:
							nTempArea[ptCurrent[nStepFound].x][ptCurrent[nStepFound].y] = k;
							nStepFound++;
							break;
						}
					}
					/*
					if (!InDanger(ptCurrent[nStepFound], nFromBombs, nFromMonsters))
					{
						//	found!
						ptCurrent[0] = ptCurrent[nStepFound];
						for (; k != 2; k--)
						{
							for (j = 1; j < 5; j++)
							{
								ptCurrent[1] = MoveByDirection(ptCurrent[0], j);
								if (nTempArea[ptCurrent[1].x][ptCurrent[1].y] == k - 1)
								{
									ptCurrent[0] = ptCurrent[1];
									break;
								}
							}
						}
						return GetDirection(pt, ptCurrent[0]);
					}
					//nStepFound++;
					nTempArea[ptCurrent[nStepFound].x][ptCurrent[nStepFound].y] = k;
					nStepFound++;
					*/
				}
			}
		}

		if (nSafeFound)
			break;
		
		for (i = 0; i < nStepFound; i++)
		{
			ptLast[i] = ptCurrent[i];
		}
		ptLast[i].x = -1;
	}

	if (nSafeFound == 0)
		return -1;

	nSafetyArea = 0;
	nSafetyPointID = -1;
	for (i = 0; i < nSafeFound; i++)
	{
		j = GetSafetyArea(ptSafe[i], nTime, nFlying, fSpeed, -1, 20);
		if (j > nSafetyArea)
		{
			nSafetyArea = j;
			nSafetyPointID = i;
		}
	}

	ptTemp1 = ptSafe[nSafetyPointID];
	for (; k != 2; k--)
	{
		for (j = 1; j < 5; j++)
		{
			ptTemp2 = MoveByDirection(ptTemp1, nDirections[j - 1]);
			if (nTempArea[ptTemp2.x][ptTemp2.y] == k - 1)
			{
				ptTemp1 = ptTemp2;
				break;
			}
		}
	}

	return GetDirection(pt, ptTemp1);
	//nGameMode = Pause;
	//return -1;
	
}

/////////////////////////////////////////////////////////////////
//
//	Function:			CMainFrame::InDanger()
//
/////////////////////////////////////////////////////////////////

int CMainFrame::InDanger(CPoint			pt,
												 int				nFromBombs,
												 int				nFromMonsters,
												 int				nAfter)
{
	int					i, j, k;
	int					nTemp = 0;
	//int					nOnBomb;
	CPoint			ptTemp;
	CPoint			ptArray[1];

	if (nFromBombs)
	{
		for (i = 0; i < MaxBombCount; i++)
		{
			if (bombs[i].nTimeLeft/* && (bombs[i].nTimeLeft > nAfter || bombs[i].nTimeLeft < 0)*/)
			{
				if (pt == bombs[i].pt)
				{
					//return true;
					if (bombs[i].nRealTimeLeft < 15 + nAfter)
					{
						return 2;
					}
					else
					{
						if (InDanger(pt, 0, 1, nAfter) == 2)
							return 1;
						else
							return 2;
						//nTemp = 1;
					}
				}
				for (j = 1; j < 5; j++)
				{
					ptTemp = MoveByDirection(bombs[i].pt, j);
					for (k = 0; k < bombs[i].nFlameLen; k++)
					{
						//ptTemp = MoveByDirection(ptTemp, j);
						if (ptTemp == pt)
						{
							//return true;
							if (bombs[i].nRealTimeLeft < 15 + nAfter)
							{
								return 2;
							}
							else
							{
								//return 1;
								nTemp = 1;
							}
						}
						if (!CanLocate(ptTemp, 0))
						{
							break;
						}
						ptTemp = MoveByDirection(ptTemp, j);
					}
				}
			}
			/*else
			{
				break;
			}*/
		}
	}

	if (nFromMonsters)
	{
		ptArray[0] = pt;
		for (i = 0; i < MaxMonsterCount; i++)
		{
			if (monsters[i].nKind == -1)
			{
				break;
			}
			else
			{

				k = Abs(pt.x - monsters[i].pt.x) + Abs(pt.y - monsters[i].pt.y); // расстояние до монстра
				if (k < 3)
				{
					if (FindPath(monsters[i].pt, ptArray, 1, monsters[i].nFlying, 0, 0, 0, -1, 1) == k)
					{
						switch (k)
						{
						case 0:
							return 2;
							break;
						case 1:
							//return 1;
							return 2;
							break;
						case 2:
							//return 1;
							nTemp = 1;
							break;
						}
					}
				}
			}
		}
	}

	return nTemp;
}

/////////////////////////////////////////////////////////////////
//
//	Function:			CMainFrame::Abs()
//
/////////////////////////////////////////////////////////////////

int CMainFrame::Abs(int			a)
{
	if (a > 0)
		return a;
	else
		return -a;
}

/////////////////////////////////////////////////////////////////
//
//	Function:			CMainFrame::MoveCompPlayer()
//
/////////////////////////////////////////////////////////////////

void CMainFrame::MoveCompPlayer(Player			&player,
																int					nID)
{
	int				i, j;
	int				nDanger = 0;
	CPoint		pt;

	if (InDanger(player.pt, 1, 0))
	{
		// Если нам угрожают бомбы, то убегаем,
		// если угрожают сильно, бежим быстро.
		player.nKeyDirection = KeepOut(player.pt, player.nFlying, 6, 1, 1, player.fSpeed,
			InDanger(player.pt, 1, 1) - 1);
	}
	else
	{
		// Иначе, если нам угрожаю монстры...
		if (InDanger(player.pt, 0, 1))
		{
			if (player.nBombCount > player.nBombSet && player.nIllness != 4)
			{
				// пробуем поставить бомбу...
				j = SetBomb(player.pt, nID, player.nBombFlameSize, BombInterval);
				nDanger = InDanger(player.pt, 1, 1);
				if (nDanger &&
					KeepOut(player.pt, player.nFlying, 7, 1, 1, player.fSpeed, nDanger - 1/*InDanger(player.pt, 1, 1) - 1*/) == -1)
				{
					// если при этом не сможем убежать, то убираем её по-быстрому,
					// перерисовка не успеет произойти и геймер ничего не заметит...
					if (nDanger != 2)
					{
						bombs[/*i*/j].nTimeLeft = 0;
						player.nBombSet--;
					}
				}
			}
			// смываемся...
			player.nKeyDirection = KeepOut(player.pt, player.nFlying, 6, 1, 1, player.fSpeed, nDanger - 1);
			if (player.nKeyDirection == -1 && nDanger == 2)
			{
				// если драпать совсем некуда, и нам совсем плохо, ставим бомбу и молимся...
				SetBomb(player.pt, nID, player.nBombFlameSize, BombInterval);
			}
		}
		else
		{
			// всё в порядке, можно дальше искать неприятности,
			// ищем ближайшего игрока или приз (смотря, что ближе)...
			player.nKeyDirection = FindPath(player.pt, ptPlayers,
				0, player.nFlying, 2, 0, 0, nID);
			if (player.nKeyDirection == -1)
			{


				i = FindPath(player.pt, NULL, 0, player.nFlying, 4/*monster*/,
					0, 0, -1, 1);
				if (i < 7 && i != -1 && player.nBombCount > player.nBombSet && player.nIllness != 4)
				{
					// ищем монстра в ближайших 7 клетках
					player.nKeyDirection = FindPath(player.pt, NULL, 0, player.nFlying, 4, 0);
				}
				else
				{
					// если ничего не нашли, ищем ближайший кирпич...
					if (!player.nFlying)
					{
						player.nKeyDirection = FindPath(player.pt, NULL,
							0, player.nFlying, 3, 0, 0, nID);
						if (!CanLocate(MoveByDirection(player.pt, player.nKeyDirection), 0))
						{
							// нашли...
							if (player.nBombCount > player.nBombSet && player.nIllness != 4)
							{
								//SetBomb(player.pt, nID, player.nBombFlameSize, BombInterval);

								// и взрываем его...
								j = SetBomb(player.pt, nID, player.nBombFlameSize, BombInterval);
								if (InDanger(player.pt, 1, 1) &&
									KeepOut(player.pt, player.nFlying, 7, 1, 1, player.fSpeed) == -1)
								{
									// конечно же, если при этом мы не сможем смыться, опять
									// по-быстрому убираем бомбу
									if (nDanger != 2)
									{
										bombs[j].nTimeLeft = 0;
										player.nBombSet--;
									}
								}

							}
						}
					}
				}
			}
			else
			{
				// если нашли игрока или приз...
				for (i = 0; i < MaxPlayerCount; i++)
				{
					if (i != nID && players[i].nLife)
					{
						// если, конечно, этот игрок - не мы сами, и если он вообще жив...
						pt = MoveByDirection(player.pt, player.nKeyDirection);
						if (pt == players[i].pt ||
							pt == MoveByDirection(players[i].pt, players[i].nDirection))
						{
							// если он уже стоит прямо перед нами,
							if (player.nBombCount > player.nBombSet && player.nIllness != 4)
							{
								//SetBomb(player.pt, nID, player.nBombFlameSize, BombInterval);

								// взрываем его за такую наглость...
								j = SetBomb(player.pt, nID, player.nBombFlameSize, BombInterval);
								if (InDanger(player.pt, 1, 1) &&
									KeepOut(player.pt, player.nFlying, 7, 1, 1, player.fSpeed) == -1)
								{
									// опять же, если не сможем убежать, убираем бомбу,
									if (nDanger != 2)
									{
										bombs[j].nTimeLeft = 0;
										player.nBombSet--;
									}
								}

							}
							else
							{
								// а если не можем взорвать гада
								// (бомбы кончились, или захворали мы), то убегаем...
								player.nKeyDirection = KeepOut(player.pt, player.nFlying, 7, 1, 1, player.fSpeed);
							}
						}
					}
				}
			}
		}
	}
	// проверяем ещё раз, не угрожает ли нам чего...
	for (i = 0; i < MaxMonsterCount; i++)
	{
		if (monsters[i].nKind != -1 &&
			MoveByDirection(monsters[i].pt, monsters[i].nDirection) == player.pt)
		{
			SetBomb(player.pt, nID, player.nBombFlameSize, BombInterval);
		}
	}
	if (InDanger(MoveByDirection(player.pt, player.nKeyDirection), 1, 1) &&
		!InDanger(player.pt, 1, 1))
	{
		player.nKeyDirection = -1;
	}
	if (InDanger(player.pt, 1, 1))
	{
		player.nKeyDirection = KeepOut(player.pt, player.nFlying, 7, 1, 1, player.fSpeed);
	}
}

/////////////////////////////////////////////////////////////////
//
//	Function:			CMainFrame::SubMovePlayer()
//
/////////////////////////////////////////////////////////////////

void CMainFrame::SubMovePlayer(Player			&player,
															 int				nID)
{
	if (InDanger(MoveByDirection(player.pt, player.nMoveDirection), 1, 1) >
		InDanger(player.pt, 1, 1))
	{
		player.nKeyDirection = WrapDirection(player.nKeyDirection + 2);
	}
}

/////////////////////////////////////////////////////////////////
//
//	Function:			CMainFrame::ChangeIllness()
//
/////////////////////////////////////////////////////////////////

void CMainFrame::ChangeIllness(Player			&player,
															 int				nNewIllness)
{
	//	3 = bombs
	//	4 = no bombs
	switch (player.nIllness)
	{
	case 1:		//	speed
		player.fSpeed /= 5;
		break;
	case 2:		//	slow
		player.fSpeed *= 2;
		break;
	}
	if (nNewIllness == -1)
	{
		nNewIllness = (float)rand() * 5.99 / (float)RAND_MAX + 1;
	}
	switch (nNewIllness)
	{
	case 1:		//	speed
		player.fSpeed *= 5;
		break;
	case 2:		//	slow
		player.fSpeed /= 2;
		break;
	}
	player.nIllness = nNewIllness;
	if (nNewIllness != 0)
	{
		player.nIllnessLeft = 25 * 25;
	}
}

/////////////////////////////////////////////////////////////////
//
//	Function:			CMainFrame::Fail()
//
/////////////////////////////////////////////////////////////////

void CMainFrame::Fail(int				nCode)
{
	switch (nCode)
	{
	case 1:
		MessageBox("Невозможно загрузить картинку. Попробуй следующее:\n 1. Закрыть побольше программ.\n 2. Перезагрузить компьютер.\n 3. Попробовать на более мощьном компе.", "Lehasoft Dyna: Ошибка", MB_OK | MB_ICONSTOP);
		break;
	}
	DestroyWindow();
}

/////////////////////////////////////////////////////////////////
//
//	Function:			CMainFrame::DeepRevert()
//
/////////////////////////////////////////////////////////////////
/*
void CMainFrame::DeepRevert(Player		&player)
{
	player.fSpeed						= player.fDeepSpeed;
	player.nBombFlameSize		= player.nDeepFlameSize;
	player.nBombCount				= player.nDeepBombCount;
}*/

/////////////////////////////////////////////////////////////////
//
//	Function:			CMainFrame::SetButtonID()
//
/////////////////////////////////////////////////////////////////

void CMainFrame::SetButtonID(int			nID)
{
	if (nButtonID != nID)
	{
		nButtonChanged = 1;
	}
	nButtonID = nID;
}

/////////////////////////////////////////////////////////////////
//
//	Function:			CMainFrame::GetSafetyArea()
//
/////////////////////////////////////////////////////////////////

int CMainFrame::GetSafetyArea(CPoint		pt,
															int				nAfter,
															int				nFlying,
															float			fSpeed,
															int				nDanger,
															int				nMaxArea)
{
	int			i, j, k;
	int			nDangerTable[ScreenSize][ScreenSize];
	CPoint	ptCurrent[MaxSize];
	CPoint	ptLast[MaxSize];
	CPoint	ptTemp;
	int			nStepsFound;
	int			nTime;
	int			nTimeStep;
	int			nResult;

	ASSERT(ValidPt(pt));

	for (i = 0; i < ScreenSize; i++)
	{
		for (j = 0; j < ScreenSize; j++)
		{
			nDangerTable[i][j] = -1;
		}
	}

	for (i = 0; i < MaxSize; i++)
	{
		ptCurrent[i].x = -1;
		ptLast[i].x = -1;
	}

	nDangerTable[pt.x][pt.y] = InDanger(pt, 1, 1, nAfter);
	if (nDanger != -1 && nDangerTable[pt.x][pt.y] != nDanger)
		return 0;
	if (nDanger == -1)
		nDanger = nDangerTable[pt.x][pt.y];
	/*if (nDangerTable[pt.x][pt.y] != nDanger)
		return 0;*/

	if (fSpeed == 0)
		nTimeStep = 0;
	else
		nTimeStep = 1 / fSpeed + 1;

	nStepsFound = 1;
	k = 1;
	nResult = 0;
	nTime = 0;
	ptCurrent[0] = pt;

	while (nStepsFound)
	{
		k++;
		nTime += nTimeStep;

		for (i = 0; i < min(nStepsFound, MaxSize); i++)
		{
			ptLast[i] = ptCurrent[i];
		}
		if (i != MaxSize)
			ptLast[i].x = -1;

		nStepsFound = 0;
		for (i = 0; i < MaxSize; i++)
		{
			if (ptLast[i].x == -1)
				break;
			else
			{
				for (j = 1; j < 5; j++)
				{
					ptTemp = MoveByDirection(ptLast[i], j);
					if (ValidPt(ptTemp))
					{
						if (nDangerTable[ptTemp.x][ptTemp.y] == -1)
						{
							if (CanLocate(ptTemp, nFlying) && InDanger(ptTemp, 1, 1, nTime) == nDanger)
							{
								ptCurrent[nStepsFound] = ptTemp;
								nStepsFound++;
								nResult++;
								if (nMaxArea == nResult)
									return nResult;
								nDangerTable[ptTemp.x][ptTemp.y] = nDanger;
							}
						}
					}
				}
			}
		}
	}

	return nResult + 1;
}