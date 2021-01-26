#include <iostream>
#include <ncurses.h>
#include "conway.h"
#include <chrono>
#include <thread>

int main()
{
    std::cout << "Hello World" << std::endl;
    ConwaysGame game;
    game.mainloop();
    game.end_Game();
}

