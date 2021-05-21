#ifndef _GAME_HPP_
#define _GAME_HPP_
/**
**************************
* @file    game.hpp
* @author  SE7EN
* @date    2021-05-18
* @brief   
**************************
*/






/************************************* Includes *************************************/
#include "board.hpp"
#include "aiEngine.hpp"




/************************************* Defines *************************************/






/************************************* Classes *************************************/
class Game
{
    public:
        Game(){};
        void start();

    private:
        void gameLoop();

        Board board;
        AIEngine ai{board};

        bool status{false};

};





#endif