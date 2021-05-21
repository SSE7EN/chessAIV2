/**
**************************
* @file    linePiece.cpp
* @author  SE7EN
* @date    2021-05-08
* @brief   
**************************
*/






/************************************* Includes *************************************/
#include "linePiece.hpp"
#include "moveManager.hpp"
#include "move.hpp"





/************************************* Implementions *************************************/
void LinePiece::searchMovesInLine(MoveManager &moveM, std::vector<std::unique_ptr<Move>> &moves, int vectorX, int vectorY)
{



    int tempX = this->cordX + vectorX;
    int tempY =  this->cordY + vectorY;

    SValidateContinousMove validate = {true, true};

    while (validate.continous)
    {
        validate = moveM.validateContinousMove(*this, tempX, tempY);
        if(validate.possible) moves.push_back(moveM.createAnyMove(*this, tempX, tempY));

        tempX = tempX + vectorX;
        tempY = tempY + vectorY;
    }
    
}

void LinePiece::fillAttackMatrixInLine(int attackMatrix[8][8], MoveManager &moveM, int vectorX, int vectorY)
{


    int tempX = this->cordX + vectorX;
    int tempY =  this->cordY + vectorY;

    SValidateContinousAttack validate = {true, true};

    while (validate.canCheckNext)
    {
        validate = moveM.validateContinousAttack(*this, tempX, tempY);
        if(validate.canAttack) attackMatrix[tempX][tempY] = 1;

        tempX = tempX + vectorX;
        tempY = tempY + vectorY;
    }

    



}


