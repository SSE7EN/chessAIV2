#ifndef _DISPLAYBOARD_HPP_
#define _DISPLAYBOARD_HPP_
/**
**************************
* @file    displayBoard.hpp
* @author  SE7EN
* @date    2021-05-16
* @brief   
**************************
*/






/************************************* Includes *************************************/
#include <iostream>





/************************************* Defines *************************************/



#define WHITE_SQUARE "\033[47m"
#define BLACK_SQUARE "\033[40m"
#define WHITE_PIECE_COLOR "\033[96m"
#define BLACK_PIECE_COLOR "\033[31m"
#define RESET   "\033[0m"




/************************************* Classes *************************************/
class Board;

class DisplayBoard
{
    public:
        DisplayBoard(){};

        static void displayBoard(Board &board);

    private:
        static void printLine(Board &board,int posY, std::string color1, std::string color2);
};





#endif