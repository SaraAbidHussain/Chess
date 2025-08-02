#include "bscs24112Queen.h"
Queen::Queen(int ri, int ci, Board* b, COLOUR clr)
    : Piece(ri, ci, b, clr), Rook(ri, ci, b, clr), Bishop(ri, ci, b, clr)  { }

void Queen::Draw() 
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

bool Queen::isLegal(Position D)
{
	return (Rook::isLegal(D) || Bishop::isLegal(D));
}

void Queen::_loadTexture()
{
	if (clr == PBLACK)
	{
		textureB = LoadTexture("queen-B.png");
		textureB.height = 70;
		textureB.width = 60;
	}
	else
	{
		textureW = LoadTexture("queen-W.png");
		textureW.height = 70;
		textureW.width = 60;
	}
}
