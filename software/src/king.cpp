/**
**************************
* @file    king.cpp
* @author  SE7EN
* @date    2021-05-08
* @brief   
**************************
*/






/************************************* Includes *************************************/
#include "king.hpp"
#include "moveManager.hpp"
#include "move.hpp"
#include "util.hpp"
#include "spot.hpp"



/************************************* Implementions *************************************/
SearchPossibleMoveResult King::getPossibleKingMove(MoveManager &moveM, int vectorX, int vectorY)
{
    SearchPossibleMoveResult result;
    int newX = this->getX() + vectorX;
    int newY = this->getY() + vectorY;

    if(moveM.validateMove(*this, newX, newY))
    {
        result.possible = true;
        result.move = moveM.createAnyMove(*this, newX, newY);
    }

    return result;
}

void King::getPossibleCastle(MoveManager &moveM, std::vector<std::unique_ptr<Move>> &moves)
{   
    //check if king has moved;
    if(this->isMoved) return;

    int kingLongCastleX = 0;
    int rookLongCastleX = 0;
    int kingShortCastleX = 0;
    int rookShortCastleX = 0;

    if(this->eColor == EColor::WHITE)
    {
        kingLongCastleX = 2;
        kingShortCastleX = 6;
        rookLongCastleX = 3;
        rookShortCastleX = 5;
    }
    else
    {
        kingLongCastleX = 6;
        kingShortCastleX = 2;
        rookLongCastleX = 5;
        rookShortCastleX = 3;  
    }

    if(moveM.validateCastleMove(*this, 0, this->getY()))
    {
        moves.push_back(moveM.createCastleMove(*this, kingLongCastleX, 0, rookLongCastleX));
    }
    if(moveM.validateCastleMove(*this, 7, this->getY()))
    {
        moves.push_back(moveM.createCastleMove(*this, kingShortCastleX, 7, rookShortCastleX));

    }

};      

void King::getPossibleMoves(std::vector<std::unique_ptr<Move>> &possibleMoves, MoveManager &moveM)
{
    SearchPossibleMoveResult result;

    //check 8 king moves
    result = this->getPossibleKingMove(moveM,0,1);
    Util::addSearchPossibleMoveResultToVector(possibleMoves, result);
    result = this->getPossibleKingMove(moveM,1,1);
    Util::addSearchPossibleMoveResultToVector(possibleMoves, result);
    result = this->getPossibleKingMove(moveM,1,0);
    Util::addSearchPossibleMoveResultToVector(possibleMoves, result);
    result = this->getPossibleKingMove(moveM,0,-1);
    Util::addSearchPossibleMoveResultToVector(possibleMoves, result);
    result = this->getPossibleKingMove(moveM,-1,-1);
    Util::addSearchPossibleMoveResultToVector(possibleMoves, result);
    result = this->getPossibleKingMove(moveM,-1,0);
    Util::addSearchPossibleMoveResultToVector(possibleMoves, result);
    result = this->getPossibleKingMove(moveM,0,-1);
    Util::addSearchPossibleMoveResultToVector(possibleMoves, result);
    result = this->getPossibleKingMove(moveM,1,-1);
    Util::addSearchPossibleMoveResultToVector(possibleMoves, result);
    result = this->getPossibleKingMove(moveM,-1,1);
    Util::addSearchPossibleMoveResultToVector(possibleMoves, result);

    //check castle
    this->getPossibleCastle(moveM, possibleMoves);

};

void King::recalculateIsMoved()
{
    if(this->moveCnt == 0) this->setIsMoved(false);
}


void King::move(Move &move)
{
    this->cordX = move.getNewSpot().getCordX();
    this->cordY = move.getNewSpot().getCordY();

    this->setIsMoved(true);
    this->moveCnt++;

}

void King::undoMove(Move &move)
{
    this->cordX = move.getOldSpot().getCordX();
    this->cordY = move.getOldSpot().getCordY();
    
    this->moveCnt--;
    this->recalculateIsMoved();

}

void King::fillAttackMatrix(int attackMatrix[8][8],MoveManager &moveM)
{
    int tempX = this->cordX + 1;
    int tempY = this->cordY + 1;
    if(moveM.checkCoordinate(tempX, tempY)) attackMatrix[tempX][tempY] = 1;

    tempX = this->cordX - 1;
    tempY = this->cordY + 1;
    if(moveM.checkCoordinate(tempX, tempY)) attackMatrix[tempX][tempY] = 1;

    tempX = this->cordX - 1;
    tempY = this->cordY - 1;
    if(moveM.checkCoordinate(tempX, tempY)) attackMatrix[tempX][tempY] = 1;

    tempX = this->cordX - 1;
    tempY = this->cordY;
    if(moveM.checkCoordinate(tempX, tempY)) attackMatrix[tempX][tempY] = 1;

    tempX = this->cordX;
    tempY = this->cordY - 1;
    if(moveM.checkCoordinate(tempX, tempY)) attackMatrix[tempX][tempY] = 1;


    tempX = this->cordX;
    tempY = this->cordY + 1;
    if(moveM.checkCoordinate(tempX, tempY)) attackMatrix[tempX][tempY] = 1;

    tempX = this->cordX + 1;
    tempY = this->cordY;
    if(moveM.checkCoordinate(tempX, tempY)) attackMatrix[tempX][tempY] = 1;

    tempX = this->cordX + 1;
    tempY = this->cordY - 1;
    if(moveM.checkCoordinate(tempX, tempY)) attackMatrix[tempX][tempY] = 1;



}

