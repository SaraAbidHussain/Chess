#pragma once
#include "bscs24112Piece.h"
class Knight : public Piece
{
public:
	Knight(int _ri, int _ci, Board* B, COLOUR _clr);
	void Draw() override;
	bool isLegal(Position P) override;
	void _loadTexture() override;

};
