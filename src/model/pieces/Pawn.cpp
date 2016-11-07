#include "model/pieces/Pawn.h"
#include "model/Board.h"
#include "model/Location.h"
#include "model/Move.h"
#include "model/GridState.h"

Pawn::Pawn(Color color, Location position)
: color_(color), position_(position) {
    glyph_ = (color_ == Color::WHITE) ? "\u2659" : "\u265F";
}

Pawn::~Pawn() {}

Piece* Pawn::copy() const {
    return new Pawn(*this);
}

std::string Pawn::getGlyph() const { return glyph_; }

moveset Pawn::validMoves(const Board& b) const {
    moveset moves;

    if (color_ == Color::BLACK) {
        Location candidate = Location(position_.row() - 1, position_.col());

        if (b.getGridStateAt(candidate) == GridState::EMPTY) {
            moves.insert(Move(position_, candidate));

            candidate = Location(position_.row() - 2, position_.col());

            if (position_.row() == 6
                && b.getGridStateAt(candidate) == GridState::EMPTY) {
                moves.insert(Move(position_, candidate));
            }
        }

        candidate = Location(position_.row() - 1, position_.col() - 1);

        if (candidate.col() > 0
            && b.getGridStateAt(candidate) == GridState::WHITE) {
            moves.insert(Move(position_, candidate));
        }

        candidate = Location(position_.row() - 1, position_.col() + 1);

        if (candidate.col() < Board::BOARD_SIZE
            && b.getGridStateAt(candidate) == GridState::WHITE) {
            moves.insert(Move(position_, candidate));
        }
    } else {
        Location candidate = Location(position_.row() + 1, position_.col());

        if (b.getGridStateAt(candidate) == GridState::EMPTY) {
            moves.insert(Move(position_, candidate));

            candidate = Location(position_.row() + 2, position_.col());

            if (position_.row() == 1
                && b.getGridStateAt(candidate) == GridState::EMPTY) {
                moves.insert(Move(position_, candidate));
            }
        }

        candidate = Location(position_.row() + 1, position_.col() - 1);

        if (candidate.col() > 0
            && b.getGridStateAt(candidate) == GridState::BLACK) {
            moves.insert(Move(position_, candidate));
        }

        candidate = Location(position_.row() + 1, position_.col() + 1);

        if (candidate.col() < Board::BOARD_SIZE
            && b.getGridStateAt(candidate) == GridState::BLACK) {
            moves.insert(Move(position_, candidate));
        }
    }

    return moves;
}

void Pawn::move(const Move m) {
    position_ = m.end();
}

