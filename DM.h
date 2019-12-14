/////////////////////////////////////////////////////////////////
//	File:					DM.h
//	Application:	Lehasoft Dyna
//	Copyright:		Алексей Инкин, Lehasoft (1996-2002)
/////////////////////////////////////////////////////////////////

class CDM : public CDialog
{
public:
	CDM();
	virtual ~CDM();

	void				GetDMInfo(int			&nTexture,
												float		&fPrizes,
												float		&fMonsters);

	BOOL				OnInitDialog();

	void				OnOK();

public:
	enum {IDD = IDD_DEATHMATCH};

private:
	int				mnTexture;
	float			mfPrizes;
	float			mfMonsters;

	DECLARE_MESSAGE_MAP()
};