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
#include <vector>
#include <array>
#include <ncurses.h>


//Class that recreates conways game of life
class ConwaysGame
{
    private:
        static const int size_x = 60;
        static const int size_y = 30;
        //WINDOW * win;
        char board[size_x][size_y]; //2-d charactor array 
        std::vector<std::array<int, 2>> live_cells;

    public:
        ConwaysGame(); //init
        ConwaysGame(int, int); //Creates board size
        void create_First_Lives();
        void one_Cycle();
        void display_Cells();
        int getNeighbors(std::array<int, 2>);
        void setup_Game();
        void end_Game(); //Calls endwin()
        void mainloop();

};

#endif // __CONWAY_H__