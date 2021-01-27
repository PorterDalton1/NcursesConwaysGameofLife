#include <ncurses.h>
#include "conway.h"
#include <chrono>
#include <thread>

//Initializer for the class
ConwaysGame::ConwaysGame() 
{   

}

//Creates one full cycle for the game
void ConwaysGame::one_Cycle() 
{
    bool tmpBoard[size_x][size_y] = {false};

    for (int x = 0; x < size_x; x++)
    {
        for (int y = 0; y < size_y; y++)
        {
            
            //If there are 2 or 3 neighbors, the cell lives
            if (getNeighbors(x, y) == 2 && board[x][y])
                tmpBoard[x][y] = true;

            //If there are less than two or more than 3 neighbors and there is a live cell
            if ((getNeighbors(x, y) < 2 && board[x][y]) || (getNeighbors(x, y) > 3 && board[x][y]))
            {
                wmove(win, y, x); waddch(win, ' ' | A_NORMAL);
            }

            //If there are 3 live neighbors, come to life
            if (getNeighbors(x, y) == 3)
                tmpBoard[x][y] = true;
        }
    }

    for (int x = 0; x < size_x; x++)
    {
        for (int y = 0; y < size_y; y++)
        {
            board[x][y] = tmpBoard[x][y];
            if (board[x][y]) //If live cell, display it
            {
                wmove(win, y, x); waddch(win, ' ' | A_STANDOUT);
            }
        }
    }
}

//Returns the number of neighbors given the coord of a cell
int ConwaysGame::getNeighbors(int x, int y) 
{

    /////////////
    // 1  2  3 //
    // 4  *  5 //
    // 6  7  8 //
    /////////////

    //  x-1  x+1  y-1  y+1
    int xm1, xp1, ym1, yp1;

    //out of bounds checking
    if (x - 1 < 0)
        xm1 = size_x - 1;
    else
        xm1 = x-1;
    
    if (x + 1 == size_x)
        xp1 = 0;
    else
        xp1 = x+1;

    if (y - 1 < 0)
        ym1 = size_y - 1;
    else
        ym1 = y-1;
    
    if (y + 1 == size_y)
        yp1 = 0;
    else
        yp1 = y+1;
    
    


    short int neighbors;

    neighbors =
    board[xm1][ym1] + //Top-Left
    board[x][yp1]   + //Top-Middle
    board[xp1][ym1] + //Top-Right
    board[xm1][y]   + //Left
    board[xp1][y]   + //Right
    board[xm1][yp1] + //Bottom-Left
    board[x][ym1]   + //Bottom-Middle
    board[xp1][yp1];  //Bottom-Right

    return neighbors;
}

//Different from the initializer because it creates the board and displays it
void ConwaysGame::setup_Game() 
{
    initscr();
    curs_set(0);

    //Define outline window and display it
    outline = newwin(size_y + 2, size_x + 2, 0, 0);
    refresh();

    //Define main window and display it
    win = newwin(size_y, size_x, 1, 1);
    refresh();

    //make box on outline
    box(outline, 0, 0); //Creates outline around the gameboard
    wrefresh(outline);

}

//Brings the terminal back to normal mode
void ConwaysGame::end_Game() 
{
    endwin();
}

//loops each cycle of the game
void ConwaysGame::mainloop() 
{
    setup_Game();

    board[10][10] = true;
    board[10][11] = true;
    board[10][12] = true;
    board[11][12] = true;
    board[12][11] = true;
    for (int x = 0; x < size_x; x++)
    {
        for (int y = 0; y < size_y; y++)
        {
            if (board[x][y]) //If live cell, display it
            {
                wmove(win, y, x); waddch(win, ' ' | A_STANDOUT);
            }
        }
    }
    wrefresh(win);
    std::this_thread::sleep_for(std::chrono::milliseconds(3000));

    for (int i=0; i<20000; i++)
    {
        one_Cycle();
        wrefresh(win);
        std::this_thread::sleep_for(std::chrono::milliseconds(12));
    }
    end_Game();
}
