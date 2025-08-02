#pragma once
#include "bscs24112Piece.h"
#include "bscs24112Pawn.h"
#include "bscs24112Rook.h"
#include "bscs24112Knight.h"
#include "bscs24112Bishop.h"
#include "bscs24112King.h"
#include "bscs24112Queen.h"
#include<fstream>

class Board
{
private:
    Piece* Ps[8][8];
    COLOUR Turn;
    Position lastMoveFrom;
    Position lastMoveTo;
    bool enPassantPossible;

    // Castling tracking
    bool whiteKingMoved;
    bool whiteRookKingSideMoved;
    bool whiteRookQueenSideMoved;
    bool blackKingMoved;
    bool blackRookKingSideMoved;
    bool blackRookQueenSideMoved;

    const int Sq_size = 80;
    Piece* selectedPs;
    int selectedX, selectedY;

    char promotionChoice; 
    bool isPromoting;    
    Position promotionPos; 

public:
    Board();
    ~Board();
    void InitializeBoard();
    void DrawChessBoard();
    void playGUI();
    void play();
    void load_Board();
    void restart();
    bool wouldLeaveKingInCheck(Position from, Position to);

    bool temp[8][8];
    void displayBoard();
    Piece* pieceAt(Position P);
    void copyBoard(Board& CP);
    bool validSource(Position S) const;
    bool validDestination(Position D) const;
    void changeTurn();
    void move(Position S, Position D);
    void updateBoard(Position S, Position D);
    void Highlight(Position S);
    void unHighlight();
    void loadFromFile();
    void init();
    bool isCheck(COLOUR kingColor);
    bool isCheckmate(COLOUR kingColor);
    bool isStalemate(COLOUR playerColor);

    void handlePromotionInput();
    void drawPromotionMenu();    
    void PawnPromotion();

    Position findKing(COLOUR kingColor);
    bool hasLegalMoves(COLOUR playerColor);
    void handleEnPassant(Position S, Position D);
    bool handleCastling(Position S, Position D);
    bool isEnPassantPossible() const { return enPassantPossible; }

    // Castling status getters
    bool hasKingMoved(COLOUR c) const { return c == PWHITE ? whiteKingMoved : blackKingMoved; }
    bool hasRookMoved(COLOUR c, bool kingSide) const {
        return c == PWHITE ?
            (kingSide ? whiteRookKingSideMoved : whiteRookQueenSideMoved) :
            (kingSide ? blackRookKingSideMoved : blackRookQueenSideMoved);
    }

    Position getLastMoveFrom() const { return lastMoveFrom; }
    Position getLastMoveTo() const { return lastMoveTo; }
};