#include "model/Move.h"

Move::Move(Location start, Location end)
: start_(start), end_(end) {}

Location Move::start() const { return start_; }
Location Move::end() const { return end_; }

bool operator==(const Move lhs, const Move rhs) {
    return lhs.start() == rhs.start() && lhs.end() == rhs.end();
}

bool operator<(const Move lhs, const Move rhs) {
    return lhs.start() < rhs.start()
           || (lhs.start() == rhs.start() && lhs.end() < rhs.end());
}

