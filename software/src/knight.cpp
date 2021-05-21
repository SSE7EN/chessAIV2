/**
**************************
* @file    knight.cpp
* @author  SE7EN
* @date    2021-05-08
* @brief   
**************************
*/






/************************************* Includes *************************************/

#include <memory>

#include "knight.hpp"
#include "moveManager.hpp"
#include "util.hpp"


/************************************* Implementions *************************************/
SearchPossibleMoveResult Knight::getKnigthPossibleMove(MoveManager &moveM, int vectorX, int vectorY)
{
    SearchPossibleMoveResult result;
    int newX = this->cordX + vectorX;
    int newY = this->cordY + vectorY;

    if(moveM.validateMove(*this, newX, newY))
    {
        result.possible = true;
        result.move = moveM.createAnyMove(*this, newX, newY);
    }

    return result;
}

void Knight::getPossibleMoves(std::vector<std::unique_ptr<Move>> &moves, MoveManager &moveM)
{
    if(!this->isKilled)
    {

        SearchPossibleMoveResult result;

        //check 8 possible knight moves
        result = getKnigthPossibleMove(moveM, 1,2);
        Util::addSearchPossibleMoveResultToVector(moves,result);
        result = getKnigthPossibleMove(moveM, 1,-2);
        Util::addSearchPossibleMoveResultToVector(moves,result);
        result = getKnigthPossibleMove(moveM, -1,2);
        Util::addSearchPossibleMoveResultToVector(moves,result);
        result = getKnigthPossibleMove(moveM, -1,-2);
        Util::addSearchPossibleMoveResultToVector(moves,result);
        result = getKnigthPossibleMove(moveM, 2,1);
        Util::addSearchPossibleMoveResultToVector(moves,result);
        result = getKnigthPossibleMove(moveM, 2, -1);
        Util::addSearchPossibleMoveResultToVector(moves,result);
        result = getKnigthPossibleMove(moveM, -2,1);
        Util::addSearchPossibleMoveResultToVector(moves,result);
        result = getKnigthPossibleMove(moveM, -2,-1);
        Util::addSearchPossibleMoveResultToVector(moves,result);
    }


}

void Knight::fillAttackMatrix(int attackMatrix[8][8],MoveManager &moveM)
{
    if(!this->isKilled)
    {
        int tempX = this->cordX + 1;
        int tempY = this->cordY + 2;
        if(moveM.checkCoordinate(tempX, tempY)) attackMatrix[tempX][tempY] = 1;

        tempX = this->cordX + 1;
        tempY = this->cordY - 2;
        if(moveM.checkCoordinate(tempX, tempY)) attackMatrix[tempX][tempY] = 1;

        tempX = this->cordX - 1;
        tempY = this->cordY + 2;
        if(moveM.checkCoordinate(tempX, tempY)) attackMatrix[tempX][tempY] = 1;

        tempX = this->cordX - 1;
        tempY = this->cordY - 2;
        if(moveM.checkCoordinate(tempX, tempY)) attackMatrix[tempX][tempY] = 1;

        tempX = this->cordX + 2;
        tempY = this->cordY + 1;
        if(moveM.checkCoordinate(tempX, tempY)) attackMatrix[tempX][tempY] = 1;

        tempX = this->cordX + 2;
        tempY = this->cordY - 1;
        if(moveM.checkCoordinate(tempX, tempY)) attackMatrix[tempX][tempY] = 1;

        tempX = this->cordX - 2;
        tempY = this->cordY + 1;
        if(moveM.checkCoordinate(tempX, tempY)) attackMatrix[tempX][tempY] = 1;

        tempX = this->cordX - 2;
        tempY = this->cordY - 1;
        if(moveM.checkCoordinate(tempX, tempY)) attackMatrix[tempX][tempY] = 1;
    }


}
