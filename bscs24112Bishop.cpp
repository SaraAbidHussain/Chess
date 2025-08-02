#include "bscs24112Bishop.h"
Bishop::Bishop(int _ri, int _ci, Board* _b, COLOUR _clr)
	:Piece(_ri, _ci, _b, _clr)
{ }
void Bishop::Draw()
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
bool Bishop::isLegal(Position D)
{
	return isDiagonal(this->P, D) && isDiagonalPathClear(B, this->P, D);
}

void Bishop::_loadTexture()
{
	if (clr == PBLACK)
	{
		textureB = LoadTexture("bishop-B.png");
		textureB.height = 70;
		textureB.width = 60;
	}
	else
	{
		textureW = LoadTexture("bishop-W.png");
		textureW.height = 70;
		textureW.width = 60;
	}

}


