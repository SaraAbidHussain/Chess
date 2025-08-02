#include "bscs24112Piece.h"
#include "bscs24112Board.h"
using namespace std;

Piece::Piece(int _r, int _c, Board* _b, COLOUR _clr) :
	P{ _r,_c }, B(_b), clr(_clr)
{

}
Piece::Piece(const Piece& other)
{
	P = other.P;
	clr = other.clr;
	B = other.B;
}
void Piece::Draw()
{

}
void Piece::setPos(Position p)
{
	P = p;
}



Position Piece::getPos()const
{
	return P;
}
void Piece::Move(Position D)
{
	this->P = D;
}
COLOUR Piece::getColour() const
{
	return clr;
}
bool Piece::isLegal(Position P)
{
	return true;
}
bool Piece::isVertical(Position S, Position D)
{
	return S.ci == D.ci;
}
bool Piece::isHorizontal(Position S, Position D)
{
	return S.ri == D.ri;
}
bool Piece::isDiagonal(Position S, Position D)
{
	int dr = abs(S.ri - D.ri);
	int dc = abs(S.ci - D.ci);
	return dr == dc;
}

bool Piece::isVerticalPathClear(Board* b, Position S, Position D)
{
	if (S.ri < D.ri)
	{
		for (int r = S.ri + 1; r < D.ri; r++)          //change in one loop
		{
			if (b->pieceAt({ r,S.ci }) != nullptr)
			{
				return false;
			}
		}
	}
	else
	{
		for (int r = S.ri - 1; r > D.ri; r--)  //int r = D.ri + 1; r < S.ri; r++
		{
			if (b->pieceAt({ r,S.ci }) != nullptr)
			{
				return false;
			}
		}
	}
	return true;
}
bool Piece::isHorizonatalPathClear(Board* b, Position S, Position D)
{

	for (int r = S.ci + 1; r < D.ci; r++)
	{
		if (b->pieceAt({ S.ri, r }) != nullptr)
		{
			return false;
		}
	}
	for (int r = D.ri + 1; r < S.ri; r++)
	{
		if (b->pieceAt({ S.ri, r }) != nullptr)
		{
			return false;
		}
	}
	return true;
}
bool Piece::isDiagonalPathClear(Board* b, Position S, Position D)
{
	int dr = S.ri - D.ri;
	int dc = S.ci - D.ci;
	if (dr > 0 && dc > 0)
	{
		int d = abs(D.ri - S.ri ) - 1;
		for (int i = 1; i <=  d; i++)
		{
			if (b->pieceAt({ S.ri - i , S.ci - i }) != nullptr)
			{
				return false;
			}
		}
	}
	else if (dr < 0 && dc < 0)
	{
		int d = abs(D.ri - S.ri ) - 1;
		for (int i = 1; i <= d; i++)
		{
			if (b->pieceAt({ S.ri + i , S.ci + i }) != nullptr)
			{
				return false;
			}
		}
	}
	else if (dr > 0 && dc < 0)
	{
		int d = abs(D.ri - S.ri) - 1;
		for (int i = 1; i <= d; i++)
		{
			if (b->pieceAt({ S.ri - i , S.ci + i }) != nullptr)
			{
				return false;
			}
		}
	}
	else
	{
		int d = abs(D.ri - S.ri) - 1;
		for (int i = 1; i <= d; i++)
		{
			if (b->pieceAt({ S.ri + i , S.ci - i }) != nullptr)
			{
				return false;
			}
		}
	}
	return true;
}

