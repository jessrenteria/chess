#ifndef BOARD_H
#define BOARD_H

#include <vector>

#include "model/Move.h"
#include "model/Location.h"
#include "model/GridState.h"
#include "model/Piece.h"

class Piece;

class Board {
private:
    class GridCell;

    std::vector<std::vector<GridCell>> b_;

public:
    static int BOARD_SIZE;

    Board();
    Board(const Board& b);
    ~Board();

    GridState getGridStateAt(Location l) const;
    Piece* getPieceAt(Location l) const;
    bool canMakeMove(Move m) const;
    Board makeMove(Move m);
};

#endif

