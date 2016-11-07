#include <iostream>

#include "model/Board.h"
#include "model/pieces/Pawn.h"

int Board::BOARD_SIZE = 8;

class Board::GridCell {
public:
    GridState gs_;
    Piece* p_;

    GridCell() : gs_(GridState::EMPTY), p_(NULL) {}
    GridCell(const GridCell& gc) {
        gs_ = gc.gs_;
        p_ = gc.p_ != NULL ? gc.p_->copy() : NULL;
    }
    GridCell(GridState gs, Piece* p) : gs_(gs), p_(p) {}

    void operator=(GridCell gc) {
        gs_ = gc.gs_;
        p_ = gc.p_;
    }
};

Board::Board() {
    b_ = std::vector<std::vector<GridCell>>(Board::BOARD_SIZE,
                                            std::vector<GridCell>(Board::BOARD_SIZE));

    for (int col = 0; col < Board::BOARD_SIZE; ++col) {
        b_[0][col] = GridCell();
        b_[Board::BOARD_SIZE - 1][col] = GridCell();

        for (int row = 2; row < Board::BOARD_SIZE - 2; ++row) {
            b_[row][col] = GridCell();
        }

        b_[1][col] = GridCell(GridState::WHITE, new Pawn(Color::WHITE, Location(1, col)));
        b_[6][col] = GridCell(GridState::BLACK, new Pawn(Color::BLACK, Location(6, col)));
    }
}

Board::Board(const Board& b) {
    b_ = std::vector<std::vector<GridCell>>(Board::BOARD_SIZE,
                                            std::vector<GridCell>(Board::BOARD_SIZE));

    for (int row = 0; row < Board::BOARD_SIZE; ++row) {
        for (int col = 0; col < Board::BOARD_SIZE; ++col) {
            b_[row][col] = GridCell(b.b_[row][col]);
        }
    }
}

Board::~Board() {
    for (int row = 0; row < Board::BOARD_SIZE; ++row) {
        for (int col = 0; col < Board::BOARD_SIZE; ++col) {
            if (b_[row][col].p_ != NULL) {
                delete b_[row][col].p_;
                b_[row][col].p_ = NULL;
            }
        }
    }
}

GridState Board::getGridStateAt(Location l) const {
    return b_[l.row()][l.col()].gs_;
}

Piece* Board::getPieceAt(Location l) const {
    return b_[l.row()][l.col()].p_;
}

bool Board::canMakeMove(Move m) const {
    Piece* p = getPieceAt(m.start());
    if (p == NULL) {
        std::cout << "Piece was null." << std::endl;
        return false;
    }
    moveset moves = p->validMoves(*this);
    return moves.find(m) != moves.end();
}

Board Board::makeMove(Move m) {
    if (!canMakeMove(m)) {
        std::cout << "Invalid move." << std::endl;
        return *this;
    }

    Board b = Board(*this);
    Location start = m.start();
    Location end = m.end();
    GridCell& gStart = b.b_[start.row()][start.col()];
    GridCell& gEnd = b.b_[end.row()][end.col()];

    if (gEnd.gs_ != GridState::EMPTY) {
        delete gEnd.p_;
    }

    gEnd.gs_ = gStart.gs_;
    gEnd.p_ = gStart.p_;
    gEnd.p_->move(m);
    gStart.gs_ = GridState::EMPTY;
    gStart.p_ = NULL;

    return b;
}

