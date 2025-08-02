#include "bscs24112King.h"
#include "bscs24112Board.h"

King::King(int _ri, int _ci, Board* _b, COLOUR _clr)
    :Piece(_ri, _ci, _b, _clr)
{
}

void King::Draw()
{
    int x = static_cast<int>(P.ri * tileSize + (tileSize / 4));
    int y = static_cast<int>(P.ci * tileSize + (tileSize / 4));

    if (clr == PBLACK)
    {
        DrawTexture(textureB, y, x, RAYWHITE);
    }
    else
    {
        DrawTexture(textureW, y, x, RAYWHITE);
    }
}

void King::_loadTexture()
{
    if (clr == PBLACK)
    {
        textureB = LoadTexture("king-B.png");
        textureB.height = 70;
        textureB.width = 60;
    }
    else
    {
        textureW = LoadTexture("king-W.png");
        textureW.height = 70;
        textureW.width = 60;
    }
}

bool King::isLegal(Position D)
{
    int dr = abs(this->P.ri - D.ri);
    int dc = abs(this->P.ci - D.ci);

    // Normal king move (one square in any direction)
    if ((dr <= 1 && dc <= 1) && !(dr == 0 && dc == 0))
    {
        return true;
    }

    // Castling move (king moves two squares horizontally)
    if (dr == 0 && abs(dc) == 2)
    {
        return true; // Actual castling validation is handled in Board::handleCastling
    }

    return false;
}