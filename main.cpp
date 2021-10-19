// To compile you need to have ncurses downloaded.
// ONLY works on linux
// Compiling using command:
// g++ -lncurses *.cpp -o out
#include "conway.h"

int main()
{
    ConwaysGame game;
    game.mainloop();
}

