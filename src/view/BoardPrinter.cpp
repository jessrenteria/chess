#include <iostream>

#include "view/BoardPrinter.h"
#include "model/Board.h"
#include "model/Location.h"
#include "model/Piece.h"

BoardPrinter::BoardPrinter() {
    m_ = lettermap({
        {0, "A"}, {1, "B"}, {2, "C"}, {3, "D"},
        {4, "E"}, {5, "F"}, {6, "G"}, {7, "H"}
    });
}

void BoardPrinter::print(const Board& b) const {
    using namespace std;

    for (int row = 0; row < 8; ++row) {
        cout << "  ";
        for (int i = 0; i < 8; ++i) {
            cout << "+ - ";
        }

        cout << "+" << endl;
        cout << 8 - row << " ";

        for (int col = 0; col < 8; ++col) {
            cout << "| ";
            Piece* p = b.getPieceAt(Location(7 - row, col));
            if (p != NULL) {
                cout << p->getGlyph() << " ";
            } else {
                cout << "  ";
            }
        }

        cout << "|" << endl;
    }

    cout << "  ";
    for (int i = 0; i < 8; ++i) {
        cout << "+ - ";
    }

    cout << "+" << endl;

    cout << "    ";

    for (int col = 0; col < 8; ++col) {
        cout << m_.find(col)->second << "   ";
    }

    cout << endl;
}

