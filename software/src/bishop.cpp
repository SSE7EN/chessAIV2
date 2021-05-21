/**
**************************
* @file    bishop.cpp
* @author  SE7EN
* @date    2021-05-08
* @brief   
**************************
*/






/************************************* Includes *************************************/
#include <vector>

#include "bishop.hpp"
#include "moveManager.hpp"
#include "move.hpp"




/************************************* Implementions *************************************/
void Bishop::getPossibleMoves(std::vector<std::unique_ptr<Move>> &moves, MoveManager &moveM){

    if(!this->isKilled)
    {
        this->searchMovesInLine(moveM, moves, -1, -1);
        this->searchMovesInLine(moveM, moves, -1, 1);
        this->searchMovesInLine(moveM, moves, 1, 1);
        this->searchMovesInLine(moveM, moves, 1, -1);
    }

}

void Bishop::fillAttackMatrix(int attackMatrix[8][8], MoveManager &moveM)
{
    if(!this->isKilled)
    {
        this->fillAttackMatrixInLine(attackMatrix,moveM, -1, -1);
        this->fillAttackMatrixInLine(attackMatrix,moveM, -1, 1);
        this->fillAttackMatrixInLine(attackMatrix,moveM, 1, 1);
        this->fillAttackMatrixInLine(attackMatrix, moveM, 1, -1);
    }
}