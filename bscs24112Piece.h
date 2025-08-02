#pragma once
#include "bscs24112Header.h"
#include <iostream>



using namespace std;
const int tileSize = 100;

class Board;
class Piece
{
protected:
	Position P;
	COLOUR clr;
	Board* B;
	Texture2D textureW;
	Texture2D textureB;


	static bool isVertical(Position S, Position D);
	static bool isHorizontal(Position S, Position D);
	static bool isDiagonal(Position S, Position D);

	bool isVerticalPathClear(Board* b, Position S, Position D);
	bool isHorizonatalPathClear(Board* b, Position S, Position D);
	bool isDiagonalPathClear(Board* b, Position S, Position D);
public:
	Piece(int _r, int _c, Board* _b, COLOUR _clr);
	Piece(const Piece& other);
	
	virtual void _loadTexture() = 0;
	void setPos(Position p);
	Position getPos()const;

	virtual void Draw() = 0;
	virtual bool isLegal(Position P) = 0;

	void Move(Position P);
	COLOUR getColour() const;

	void color(int k);

};

