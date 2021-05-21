/**
**************************
* @file    game.cpp
* @author  SE7EN
* @date    2021-05-18
* @brief   
**************************
*/






/************************************* Includes *************************************/
#include "game.hpp"
#include "displayBoard.hpp"
#include "aiEngine.hpp"




/************************************* Implementions *************************************/
void Game::gameLoop()
{
    while(this->status)
    {
        this->ai.move();
        DisplayBoard::displayBoard(this->board);
    }
}

void Game::start()
{
    this->status = true;

    this->gameLoop();
}