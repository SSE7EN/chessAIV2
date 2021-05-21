/**
**************************
* @file    moveHistory.cpp
* @author  SE7EN
* @date    2021-05-05
* @brief   
**************************
*/






/************************************* Includes *************************************/
#include "moveHistory.hpp"
#include "move.hpp"






/************************************* Implementions *************************************/
Move* MoveHistory::getLastMove(){
    if(!this->moves.empty()){
        return this->moves.back().get();
    }
    else return nullptr;
}

std::unique_ptr<Move> MoveHistory::getAndUndoLastMoveUniquePtr(){

    std::unique_ptr<Move> lastMove = std::move(this->moves.back()); 
    this->moves.pop_back();
    
    return lastMove;
}


Move& MoveHistory::addMoveToHistory(std::unique_ptr<Move> &move)
{
    this->moves.push_back(std::move(move));
    return *(moves.back().get());   
}