#include "bscs24112Knight.h"
Knight::Knight(int _ri, int _ci, Board* _b, COLOUR _clr)
	:Piece(_ri, _ci, _b, _clr)
{ }
void Knight::Draw()
{

	int x = P.ri * tileSize + (tileSize / 4);
	int y = P.ci * tileSize + (tileSize / 4);

	if (clr == PBLACK)
	{
		DrawTexture(textureB, y, x, RAYWHITE);
	}
	else
	{
		DrawTexture(textureW, y, x, RAYWHITE);
	}

}

bool Knight::isLegal(Position D)
{
	int dr = abs(this->P.ri - D.ri);
	int dc = abs(this->P.ci - D.ci);
	return (dr == 2 && dc == 1) || (dr == 1 && dc == 2);
}

void Knight::_loadTexture()
{
	if (clr == PBLACK)
	{
		textureB = LoadTexture("knight-B.png");
		textureB.height = 70;
		textureB.width = 60;
	}
	else
	{
		textureW = LoadTexture("knight-W.png");
		textureW.height = 70;
		textureW.width = 60;
	}
}
