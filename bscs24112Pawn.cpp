// bscs24112Pawn.cpp
#include "bscs24112Pawn.h"
#include "bscs24112Board.h"
Pawn::Pawn(int _ri, int _ci, Board* _b, COLOUR _clr)
    :Piece(_ri, _ci, _b, _clr)
{
}

void Pawn::Draw()
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

bool Pawn::isLegal(Position D)
{
    int dr = D.ri - this->P.ri;
    int dc = D.ci - this->P.ci;

    int direction = (this->getColour() == PWHITE) ? -1 : 1;

    // Normal move forward
    if (dc == 0 && dr == direction && B->pieceAt(D) == nullptr)
    {
        return isVerticalPathClear(B, this->P, D);
    }

    // Two-square initial move
    if (dc == 0 && dr == 2 * direction && B->pieceAt(D) == nullptr)
    {
        if ((this->getColour() == PWHITE && P.ri == 6) ||
            (this->getColour() == PBLACK && P.ri == 1))
        {
            return isVerticalPathClear(B, this->P, D);
        }
    }

    // Normal capture
    if (abs(dc) == 1 && dr == direction)
    {
        // Diagonal capture
        if (B->pieceAt(D) && B->pieceAt(D)->getColour() != this->getColour())
        {
            return true;
        }

        // En passant capture
        Position lastMoveTo = B->getLastMoveTo();
        if (B->pieceAt(D) == nullptr &&
            lastMoveTo.ri == P.ri &&
            lastMoveTo.ci == D.ci)
        {
            Position temp = { P.ri, D.ci };
            Piece* adjacentPawn = B->pieceAt(temp);
            if (adjacentPawn &&
                adjacentPawn->getColour() != this->getColour() &&
                dynamic_cast<Pawn*>(adjacentPawn))
            {
                Position lastMoveFrom = B->getLastMoveFrom();
                if (abs(lastMoveFrom.ri - lastMoveTo.ri) == 2)
                {
                    return true;
                }
            }
        }
    }

    return false;
}

void Pawn::_loadTexture()
{
    if (clr == PBLACK)
    {
        textureB = LoadTexture("pawn-B.png");
        textureB.height = 70;
        textureB.width = 60;
    }
    else
    {
        textureW = LoadTexture("pawn-W.png");
        textureW.height = 70;
        textureW.width = 60;
    }
}