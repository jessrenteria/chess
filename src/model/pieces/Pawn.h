#ifndef PAWN_H
#define PAWN_H

#include "model/Board.h"
#include "model/Piece.h"
#include "model/Move.h"
#include "model/Color.h"

class Pawn: public Piece {
private:
    Color color_;
    Location position_;
    std::string glyph_;

public:
    Pawn(Color color, Location position);
    ~Pawn();

    Piece* copy() const;
    std::string getGlyph() const;
    moveset validMoves(const Board& b) const;
    void move(const Move m);
};

#endif

