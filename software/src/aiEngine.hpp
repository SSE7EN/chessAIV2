#ifndef _AIENGINE_HPP_
#define _AIENGINE_HPP_
/**
**************************
* @file    aiEngine.hpp
* @author  SE7EN
* @date    2021-05-18
* @brief   
**************************
*/






/************************************* Includes *************************************/
#include "enum.hpp"





/************************************* Defines *************************************/
#define INFINITY 99999999
#define DEPTH 5




/************************************* Classes *************************************/
class Board;

class AIEngine
{
    public:
        AIEngine(Board &board):board{board}{};
        void move();

    
    private:
        int minimax(Board &board, int depth, int alpha, int beta, EColor color);
        
        
        Board &board;

};





#endif