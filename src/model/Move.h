#ifndef MOVE_H
#define MOVE_H

#include <set>

#include "model/Location.h"

class Move {
private:
    Location start_;
    Location end_;

public:
    Move(Location start, Location end);

    Location start() const;
    Location end() const;

};

bool operator==(const Move lhs, const Move rhs);
bool operator<(const Move lhs, const Move rhs);

typedef std::set<Move> moveset;

#endif

