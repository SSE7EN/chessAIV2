/**
**************************
* @file    rook.cpp
* @author  SE7EN
* @date    2021-05-08
* @brief   
**************************
*/






/************************************* Includes *************************************/
#include <vector>


#include "rook.hpp"
#include "moveManager.hpp"
#include "move.hpp"
#include "util.hpp"
#include "spot.hpp"



/************************************* Implementions *************************************/
void Rook::getPossibleMoves(std::vector<std::unique_ptr<Move>> &possibleMoves, MoveManager &moveM){
    
    if(!this->isKilled)
    {

    SearchPossibleMoveResult result;

    this->searchMovesInLine(moveM, possibleMoves, -1, 0);
    this->searchMovesInLine(moveM, possibleMoves, 1, 0);
    this->searchMovesInLine(moveM, possibleMoves, 0, 1);
    this->searchMovesInLine(moveM, possibleMoves, 0, -1);
    }

}

void Rook::fillAttackMatrix(int attackMatrix[8][8], MoveManager &moveM)
{
    if(!this->isKilled)
    {
        this->fillAttackMatrixInLine(attackMatrix,moveM, -1, 0);
        this->fillAttackMatrixInLine(attackMatrix,moveM, 1, 0);
        this->fillAttackMatrixInLine(attackMatrix,moveM, 0, 1);
        this->fillAttackMatrixInLine(attackMatrix, moveM, 0, -1);
    }
}

void Rook::recalculateIsMoved()
{
    if(this->moveCnt == 0) this->setIsMoved(false);
}


void Rook::move(Move &move)
{
    this->cordX = move.getNewSpot().getCordX();
    this->cordY = move.getNewSpot().getCordY();

    this->setIsMoved(true);
    this->moveCnt++;

}

void Rook::move(CastleMove &move)
{
    this->cordX = move.getRookNewSpot().getCordX();
    this->cordY = move.getRookNewSpot().getCordY();

    this->setIsMoved(true);
    this->moveCnt++;

}

void Rook::undoMove(Move &move)
{
    this->cordX = move.getOldSpot().getCordX();
    this->cordY = move.getOldSpot().getCordY();
    
    this->moveCnt--;
    this->recalculateIsMoved();

}

void Rook::undoMove(CastleMove &move)
{
    this->cordX = move.getRookOldSpot().getCordX();
    this->cordY = move.getRookOldSpot().getCordY();
    
    this->moveCnt--;
    this->recalculateIsMoved();

}