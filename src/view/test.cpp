#include "model/Board.h"
#include "view/BoardPrinter.h"
#include "model/Move.h"
#include "model/Location.h"

int main() {
    Board b;
    BoardPrinter bp;

    bp.print(b);
    bp.print(b.makeMove(Move(Location(1, 0), Location(3, 0))));

    return 0;
}
