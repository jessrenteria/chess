#include "model/Location.h"

Location::Location(int row, int col)
: row_(row), col_(col) {}

int Location::row() const { return row_; }
int Location::col() const { return col_; }

bool operator==(const Location lhs, const Location rhs) {
    return lhs.col() == rhs.col() && lhs.row() == rhs.row();
}

bool operator<(const Location lhs, const Location rhs) {
    return lhs.row() < rhs.row()
           || (lhs.row() == rhs.row() && lhs.col() < rhs.col());
}

