#include <iostream>
#include <ncurses.h>
#include "conway.h"
#include <chrono>
#include <thread>


ConwaysGame::ConwaysGame() 
{   
    //win = newwin(size_x, size_y, 0, 0);
    for (int x = 0; x < size_x; x++)
    {
        for (int y = 0; y < size_y; y++)
        {
            board[x][y] = ' ';
        }
    }

}

void ConwaysGame::create_First_Lives() 
{
    live_cells.push_back({15, 20});
    live_cells.push_back({16, 20});
    live_cells.push_back({0, 0});
}

void ConwaysGame::one_Cycle() 
{
    for (int x = 1; x <= size_x; x++)
    {
        for (int y = 1; y <= size_y; y++)
        {
            wmove(stdscr, y, x); wgetch(stdscr);
        }
    }
}

void ConwaysGame::display_Cells() 
{
    for (int i=0; i<live_cells.size(); i++)
    {
        wmove(stdscr, live_cells.at(i)[1]+1, live_cells.at(i)[0]+1); waddch(stdscr, '#');
    }
    wrefresh(stdscr);
}

void ConwaysGame::setup_Game() 
{
    initscr();
    for (int top = 1; top <= size_x; top++)
    {
        wmove(stdscr, 0, top); waddch(stdscr, '-');
        wmove(stdscr, size_y + 1, top); waddch(stdscr, '-');
    }
    for (int sides = 1; sides <= size_y; sides++)
    {
        wmove(stdscr, sides, 0); waddch(stdscr, '|');
        wmove(stdscr, sides, size_x + 1); waddch(stdscr, '|');
    }
    

    for (int x = 1; x <= size_x; x++)
    {
        for (int y = 1; y <= size_y; y++)
        {
            wmove(stdscr, y, x); waddch(stdscr, ' ');
        }
    }
}

void ConwaysGame::end_Game() 
{
    endwin();
}

void ConwaysGame::mainloop() 
{
    setup_Game();
    create_First_Lives();
    display_Cells();
    for (int i=0; i<10; i++)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(2000));
        one_Cycle();
    }
}
