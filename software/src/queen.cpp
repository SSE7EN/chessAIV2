/**
**************************
* @file    queen.cpp
* @author  SE7EN
* @date    2021-05-09
* @brief   
**************************
*/






/************************************* Includes *************************************/
#include "queen.hpp"
#include "moveManager.hpp"
#include "move.hpp"





/************************************* Implementions *************************************/
void Queen::getPossibleMoves(std::vector<std::unique_ptr<Move>> &possibleMoves, MoveManager &moveM){

    if(!this->isKilled)
    {
        this->searchMovesInLine(moveM, possibleMoves, -1, -1);
        this->searchMovesInLine(moveM, possibleMoves, -1, 1);
        this->searchMovesInLine(moveM, possibleMoves, 1, 1);
        this->searchMovesInLine(moveM, possibleMoves, 1, -1);
        this->searchMovesInLine(moveM, possibleMoves, -1, 0);
        this->searchMovesInLine(moveM, possibleMoves, 1, 0);
        this->searchMovesInLine(moveM, possibleMoves, 0, 1);
        this->searchMovesInLine(moveM, possibleMoves, 0, -1);


    }

}

void Queen::fillAttackMatrix(int attackMatrix[8][8], MoveManager &moveM)
{
    if(!this->isKilled)
    {
        this->fillAttackMatrixInLine(attackMatrix,moveM, -1, -1);
        this->fillAttackMatrixInLine(attackMatrix,moveM, -1, 1);
        this->fillAttackMatrixInLine(attackMatrix,moveM, 1, 1);
        this->fillAttackMatrixInLine(attackMatrix, moveM, 1, -1);
        this->fillAttackMatrixInLine(attackMatrix,moveM, -1, 0);
        this->fillAttackMatrixInLine(attackMatrix,moveM, 1, 0);
        this->fillAttackMatrixInLine(attackMatrix,moveM, 0, 1);
        this->fillAttackMatrixInLine(attackMatrix, moveM, 0, -1);
    }
}