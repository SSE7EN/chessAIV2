/**
**************************
* @file    moveManager.cpp
* @author  SE7EN
* @date    2021-05-05
* @brief   
**************************
*/






/************************************* Includes *************************************/
#include "moveManager.hpp"
#include "move.hpp"
#include "board.hpp"
#include "king.hpp"
#include "spot.hpp"
#include "pieceSet.hpp"




/************************************ Implementions *************************************/
bool MoveManager::checkCoordinate(int cordX, int cordY){
    bool result = true;
    if(cordX < 0 || cordX > 7 || cordY < 0 || cordY > 7) result = false;
    
    return result;
}

bool MoveManager::validatePawnSpecialAttack(Piece &piece, int newCordX, int newCordY)
{
    // check if coordinates are correct can be removed
    if(!this->checkCoordinate(newCordX, newCordY)) return false;

    // check if last moved piece was a pawn
    Move *lastMove = this->board.moveHistory.getLastMove();
    if(lastMove == nullptr || lastMove->getPieceMoved().getPieceCode() != EPieceCode::PAWN) return false;

    // check if last move was a special pawn move
    int difference = abs(lastMove->getOldSpot().getCordY() - lastMove->getNewSpot().getCordY());
    if(difference != 2) return false;

    // check if move was on needed line
    if(lastMove->getPieceMoved().getX() == newCordX) return true;

    return false;
}

bool MoveManager::validateMove(Piece &piece, int cordX, int cordY)
{
    // check if coordinates are correct can be removed
    if(!this->checkCoordinate(cordX, cordY)) return false;

    //check if spot is free
    if(this->board(cordX, cordY).getPiece() == nullptr) return true;


    //check if can take
    if(this->board(cordX, cordY).getPiece()->getColor() != piece.getColor() && this->board(cordX, cordY).getPiece()->canTake()) return true;

    return false;

}
bool MoveManager::validatePawnMove(Piece &piece, int cordX, int cordY)
{
    // check if coordinates are correct can be removed
    if(!this->checkCoordinate(cordX, cordY)) return false;

    //check if spot is free
    if(this->board(cordX, cordY).getPiece() == nullptr) return true;


    return false;

}

SValidateContinousMove MoveManager::validateContinousMove(Piece &piece, int cordX, int cordY)
{
    // check if coordinates are correct can be removed
    if(!this->checkCoordinate(cordX, cordY)) return SValidateContinousMove{false, false};

    //check if spot is free
    if(this->board(cordX, cordY).getPiece() == nullptr) return SValidateContinousMove{true, true};

    //check if can take
    if(this->board(cordX, cordY).getPiece()->getColor() != piece.getColor() && this->board(cordX, cordY).getPiece()->canTake()) return SValidateContinousMove{true, false};

    return SValidateContinousMove{false, false};
}

SValidateContinousAttack MoveManager::validateContinousAttack(Piece &piece, int cordX, int cordY)
{
    // check if coordinates are correct can be removed
    if(!this->checkCoordinate(cordX, cordY)) return SValidateContinousAttack{false, false};

    //check if spot is free
    if(this->board(cordX, cordY).getPiece() == nullptr) return SValidateContinousAttack{true, true};

    //check if can take
    if(this->board(cordX, cordY).getPiece()->getColor() != piece.getColor() && this->board(cordX, cordY).getPiece()->canTake()) return SValidateContinousAttack{true, false};


    return SValidateContinousAttack{false, false};
}



bool MoveManager::checkIfSegmentIsEmpty(int startX, int startY, int vectorX, int vectorY, int endX, int endY)
{
    int tempX = startX + vectorX;
    int tempY = startY + vectorY;
    

    while(tempX != endX || tempY != endY)
    {
        Spot &spot = this->board(tempX, tempY);
        if(spot.getPiece() != nullptr)
        {
            return false;
        
        }

        tempX = tempX + vectorX;
        tempY = tempY + vectorY;
    }

    return true;
};

bool MoveManager::validateCastleMove(King &king, int rookX, int rookY)
{
    bool result = false;
    //check if rook has moved
    Spot &rookSpot = this->board(rookX, rookY);
    
    if(rookSpot.getPiece() != nullptr && rookSpot.getPiece()->getPieceCode() == EPieceCode::ROOK)
    {
        Rook *rook = static_cast<Rook*>(rookSpot.getPiece());
        if(!rook->getIsMoved())
        {
            int temp = rookX - king.getX();
            int vectorX = 1;

            temp > 0 ? vectorX = 1 : vectorX = -1; 
            
            if(checkIfSegmentIsEmpty(king.getX(), king.getY(), vectorX, 0, rookX, rookY))
            {
                result = true;
            }
        }

    }

    return result;
};

std::unique_ptr<CastleMove> MoveManager::createCastleMove(King &king, int newX, int rookOldX,int newRookX )
{
    Spot &newKingSpot = this->board(newX, king.getY());
    Spot &oldKingSpot = this->board(king.getX(), king.getY());
    Spot &oldRookSpot = this->board(rookOldX, king.getY());

    Spot &newRookSpot = this->board(newRookX, king.getY());
    Rook &rook = *(static_cast<Rook*>(oldRookSpot.getPiece()));

    return std::make_unique<CastleMove>(king, oldKingSpot, newKingSpot, rook, oldRookSpot, newRookSpot);

};


std::unique_ptr<Move> MoveManager::createMove(Piece &piece, int cordX, int cordY)
{
    
    Spot &newSpot = this->board(cordX, cordY);
    Spot &oldSpot = this->board(piece.getX(), piece.getY());

    return std::make_unique<Move>(piece, oldSpot, newSpot);

};

std::unique_ptr<TakeMove> MoveManager::createTakeMove(Piece &piece, int cordX, int cordY)
{
    Spot &newSpot = this->board(cordX, cordY);
    Spot &oldSpot = this->board(piece.getX(), piece.getY());
    Piece &pieceTaken = *(newSpot.getPiece());

    return std::make_unique<TakeMove>(piece, pieceTaken, oldSpot, newSpot);
}
std::unique_ptr<PawnSpecialTakeMove> MoveManager::createSpecialPawnTakeMove(Piece &piece, int cordX, int cordY)
{
    Spot &newSpot = this->board(cordX, cordY);
    Spot &oldSpot = this->board(piece.getX(), piece.getY());
    Piece &pieceTaken = this->board.moveHistory.getLastMove()->getPieceMoved();
    Spot &pieceTakenSpot = this->board(pieceTaken.getX(), pieceTaken.getY());

    return std::make_unique<PawnSpecialTakeMove>(piece, pieceTaken, oldSpot, newSpot, pieceTakenSpot);
}

std::unique_ptr<Move> MoveManager::createAnyMove(Piece &piece, int cordX, int cordY)
{
    std::unique_ptr<Move>move = nullptr;


    /**
     * Check if it's a attack move or normal
     * */
    Spot &moveToSpot = this->board(cordX, cordY);
    
    if(moveToSpot.getPiece() == nullptr)
    {
        move = this->createMove(piece, cordX, cordY);
    }
    else
    {
        move = this->createTakeMove(piece, cordX, cordY);
    }


    

    return move;

}

bool MoveManager::validateMoveForCheck(King &king)
{

    int attackMatrix[8][8] = {0};

    PieceSet &enemySet = this->board.getOpossiteSet(king.getColor());

    for(int i = 0; i < PIECE_COUNT; ++i)
    {
        enemySet[i].fillAttackMatrix(attackMatrix, *this);
        if(attackMatrix[king.getX()][king.getY()] == 1) return false;
    }

    return true;
}

bool MoveManager::validateAttack(Piece &piece, int attackX, int attackY)
{
    bool result = false;

    if(this->checkCoordinate(attackX, attackY))
    {
        Spot &spot = this->board(attackX, attackY);
        if(spot.getPiece() == nullptr || spot.getPiece()->getColor() != piece.getColor()) result = true;
    }

    return result;
}
bool MoveManager::validatePawnAttack(Piece &piece, int attackX, int attackY)
{
    bool result = false;

    if(this->checkCoordinate(attackX, attackY))
    {
        Spot &spot = this->board(attackX, attackY);
        if(spot.getPiece() != nullptr && spot.getPiece()->getColor() != piece.getColor()) result = true;
    }

    return result;
}