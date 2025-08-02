#include "bscs24112Rook.h"
Rook::Rook(int _ri, int _ci, Board* _b, COLOUR _clr)
	:Piece(_ri, _ci, _b, _clr)
{ }
void Rook::Draw()
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

bool Rook::isLegal(Position D)
{
	return((isVertical(this->P, D) && isVerticalPathClear(B, this->P, D)
		|| (isHorizontal(this->P, D) && isHorizonatalPathClear(B, this->P, D))));
}

void Rook::_loadTexture()
{
	if (clr == PBLACK)
	{
		textureB = LoadTexture("rook-B.png");
		textureB.height = 70;
		textureB.width = 60;
	}
	else
	{
		textureW = LoadTexture("rook-W.png");
		textureW.height = 70;
		textureW.width = 60;
	}
}
