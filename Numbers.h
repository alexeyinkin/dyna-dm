/////////////////////////////////////////////////////////////////
//	File:					Numbers.h
//	Application:	Lehasoft Dyna
//	Copyright:		Алексей Инкин, Lehasoft (1996-2002)
/////////////////////////////////////////////////////////////////

class CNumbers
{
public:
	void				Load();
	void				Render(CDC				&dc,
										 CPoint			pt);

	CNumbers&		operator++();
	CNumbers		operator+ (CNumbers&);
	CNumbers		operator- (CNumbers&);
							operator int();

public:
	int					nNumber;
};