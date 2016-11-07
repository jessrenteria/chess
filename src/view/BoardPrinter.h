#include <string>
#include <unordered_map>

#include "model/Board.h"

class BoardPrinter {
    typedef std::unordered_map<int, std::string> lettermap;

private:
    lettermap m_;

public:
    BoardPrinter();

    void print(const Board& b) const;
};

