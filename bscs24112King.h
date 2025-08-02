#pragma once
#include "bscs24112Piece.h"
#include "bscs24112Rook.h"
#include "bscs24112Bishop.h"

class King : public Piece
{
public:
    King(int _ri, int _ci, Board* B, COLOUR _clr);
    void Draw() override;
    bool isLegal(Position D) override;
    void _loadTexture() override;
};