/**
**************************
* @file    pawn.cpp
* @author  SE7EN
* @date    2021-05-08
* @brief   
**************************
*/






/************************************* Includes *************************************/
#include "pawn.hpp"
#include "moveManager.hpp"
#include "move.hpp"
#include "spot.hpp"





/************************************* Implementions *************************************/


void Pawn::recalculateIsMoved()
{
    if(this->moveCnt == 0) this->setIsMoved(false);
}


void Pawn::move(Move &move)
{
    this->cordX = move.getNewSpot().getCordX();
    this->cordY = move.getNewSpot().getCordY();

    this->setIsMoved(true);
    this->moveCnt++;

}

void Pawn::undoMove(Move &move)
{
    this->cordX = move.getOldSpot().getCordX();
    this->cordY = move.getOldSpot().getCordY();
    
    this->moveCnt--;
    this->recalculateIsMoved();

}

SearchPossibleMoveResult Pawn::getPossibleOneForward(MoveManager &moveM)
{
    SearchPossibleMoveResult result;

    //new Y cord
    int cordY = this->cordY + static_cast<int>(this->eColor);
    result.possible = moveM.validatePawnMove(*this, this->cordX, cordY); 
    if(result.possible)
    {
        result.move = moveM.createMove(*this, this->cordX, cordY);
    }
    return result;
}

SearchPossibleMoveResult Pawn::getPossibleAttack(MoveManager &moveM, int cordX, int cordY)
{
    SearchPossibleMoveResult result;
    result.possible =moveM.validatePawnAttack(*this, cordX, cordY);

    if(result.possible)
    {
        result.move = moveM.createTakeMove(*this, cordX, cordY);
    }
    return result;
}

SearchPossibleMoveResult Pawn::getPossibleTwoForward(MoveManager &moveM)
{  
    SearchPossibleMoveResult result;

    if(this->isMoved) return result;
    
    //new Y cord
    int cordY1 = this->cordY + static_cast<int>(this->eColor);
    int cordY2 = this->cordY + 2 * static_cast<int>(this->eColor);
    

    if(moveM.validatePawnMove(*this, this->cordX, cordY1) && moveM.validatePawnMove(*this, this->cordX, cordY2))
    {
        result.possible = true;
        result.move = moveM.createMove(*this,this->cordX, cordY2);
    }

    return result;
}

SearchPossibleMoveResult Pawn::getPossibleSpecialAttack(MoveManager &moveM)
{
    SearchPossibleMoveResult result;

    /**
     * The special attack is only possible if a white pawn is on cordY = 4
     * or black on cordY = 3
     * 
     **/
    if((this->eColor == EColor::WHITE && this->cordY == 4) || (this->eColor == EColor::BLACK && this->cordY == 3))
    {
        int newY = this->cordY + static_cast<int>(this->eColor);
        /**
         * check if pawn can go left(slant)
         **/
        int newX = this->cordX - 1;
        
        if(moveM.validatePawnSpecialAttack(*this, newX, newY))
        {
            result.possible = true;
            result.move = moveM.createSpecialPawnTakeMove(*this, newX, newY);
        }
        else
        {
            /**
             * check if pawn can go right(slant)
             **/
            newX = this->cordX + 1;
            
            if(moveM.validatePawnSpecialAttack(*this, newX, newY))
            {
                result.possible = true;
                result.move = moveM.createSpecialPawnTakeMove(*this, newX, newY);
            }

        }

    }

    return result;
}

void Pawn::getPossibleMoves(std::vector<std::unique_ptr<Move>> &possibleMoves, MoveManager &moveM)
{
    if(!this->isKilled)
    {
        SearchPossibleMoveResult result;



        result = this->getPossibleOneForward(moveM);
        Util::addSearchPossibleMoveResultToVector(possibleMoves, result);
        
        result = this->getPossibleTwoForward(moveM);
        Util::addSearchPossibleMoveResultToVector(possibleMoves, result);

        result = this->getPossibleSpecialAttack(moveM);
        Util::addSearchPossibleMoveResultToVector(possibleMoves, result);
        
        //check attack
        int attackY = this->cordY + static_cast<int>(this->eColor);
        int attackX = this->cordX - 1;
        result = this->getPossibleAttack(moveM, attackX, attackY);
        Util::addSearchPossibleMoveResultToVector(possibleMoves, result);

        //check second attack field
        attackX = this->cordX + 1;
        result = this->getPossibleAttack(moveM, attackX, attackY);
        Util::addSearchPossibleMoveResultToVector(possibleMoves, result);
        
    }


};

void Pawn::fillAttackMatrix(int attackMatrix[8][8],MoveManager &moveM)
{

    if(!this->isKilled)
    {
        int tempX = this->cordX + 1;
        int tempY = this->cordY + static_cast<int>(this->eColor);
        if(moveM.checkCoordinate(tempX, tempY)) attackMatrix[tempX][tempY] = 1;
        
        tempX = this->cordX - 1;
        if(moveM.checkCoordinate(tempX, tempY)) attackMatrix[tempX][tempY] = 1;


    }
}
