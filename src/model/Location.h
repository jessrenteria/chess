#ifndef LOCATION_H
#define LOCATION_H

class Location {
private:
    int row_;
    int col_;

public:
    Location(int row, int col);

    int row() const;
    int col() const;
};

bool operator==(const Location lhs, const Location rhs);

bool operator<(const Location lhs, const Location rhs);

#endif

