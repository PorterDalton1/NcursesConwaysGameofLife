/////////////////////////////////////////////////////////////////
// Conways Game of Life   -> Not complete yet                  //
//                                                             //
// This program can be run by calling the declaring the class  //
// and calling the mainloop.                                   //
//                                                             //
// ConwaysGame x;                                              //
// x.mainloop();                                               //
//                                                             //
// Program made by:                                            //
//     Porter Dalton                                           //
//     Jan 25, 2021                                            //
/////////////////////////////////////////////////////////////////
#ifndef __CONWAY_H__
#define __CONWAY_H__

#include <ncurses.h>


//Class that recreates conways game of life
class ConwaysGame
{
    private:
        static const int size_x = 60;
        static const int size_y = 30;
        bool board[size_x][size_y] = {false}; //2-d array that will display true where a live cell will be 
        WINDOW * win;
        WINDOW * outline;
        int getNeighbors(int, int);
        void one_Cycle();
        void setup_Game();
        void end_Game(); //Calls endwin()

    public:
        ConwaysGame(); //init
        ConwaysGame(int, int); //Creates board size
        void mainloop();

};

#endif // __CONWAY_H__