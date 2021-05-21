/**
**************************
* @file    piece.cpp
* @author  SE7EN
* @date    2021-04-16
* @brief   
**************************
*/






/************************************* Includes *************************************/
#include "piece.hpp"
#include "move.hpp"
#include "spot.hpp"

/************************************* Implementions *************************************/
void Piece::move(Move &move)
{
    this->cordX = move.getNewSpot().getCordX();
    this->cordY = move.getNewSpot().getCordY();

}

void Piece::undoMove(Move &move)
{
    this->cordX = move.getOldSpot().getCordX();
    this->cordY = move.getOldSpot().getCordY();
}



