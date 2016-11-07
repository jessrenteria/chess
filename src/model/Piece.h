#ifndef PIECE_H
#define PIECE_H

#include <string>

#include "model/Board.h"
#include "model/Move.h"

class Board;

class Piece {
public:
    virtual ~Piece() = 0;

    virtual Piece* copy() const = 0;
    virtual std::string getGlyph() const = 0;
    virtual moveset validMoves(const Board& b) const = 0;
    virtual void move(const Move m) = 0;
};

#endif

