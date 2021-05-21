#ifndef _SRC_MOVEMANAGER_HPP_
#define _SRC_MOVEMANAGER_HPP_
/**
**************************
* @file    moveManager.hpp
* @author  SE7EN
* @date    2021-05-05
* @brief   
**************************
*/






/************************************* Includes *************************************/
#include <memory>
#include "moveHistory.hpp"
#include "piece.hpp"




/************************************* Classes *************************************/
class Board;
class Move;
class TakeMove;
class CastleMove;
class PawnSpecialTakeMove;
class King;

struct SValidateContinousMove
{
    bool possible = false;
    bool continous = false;
};

struct SValidateContinousAttack
{
    bool canAttack = false;
    bool canCheckNext = false;
};


class MoveManager
{
    public:
        MoveManager(Board &board):board{board}{};
        std::unique_ptr<Move> createAnyMove(Piece &piece, int cordX, int cordY);
        std::unique_ptr<TakeMove> createTakeMove(Piece &piece, int cordX, int cordY);
        std::unique_ptr<PawnSpecialTakeMove> createSpecialPawnTakeMove(Piece &piece, int cordX, int cordY);

        std::unique_ptr<Move> createMove(Piece &piece, int cordX, int cordY);
        std::unique_ptr<CastleMove> createCastleMove(King &king, int newX, int rookOldX,int newRookX );
        SValidateContinousMove validateContinousMove(Piece &piece, int cordX, int cordY);
        SValidateContinousAttack validateContinousAttack(Piece &piece, int cordX, int cordY);
        bool validateMove(Piece &piece, int cordX, int cordY);
        bool validatePawnMove(Piece &piece, int cordX, int cordY);
        bool validatePawnSpecialAttack(Piece &piece, int newCordX, int newCordY);
        bool validateCastleMove(King &king, int rookX, int rookY);
        bool validateMoveForCheck(King &king);
        bool validateAttack(Piece &piece, int attackX, int attackY);
        bool validatePawnAttack(Piece &piece, int attackX, int attackY);
        bool checkCoordinate(int cordX, int cordY);

        
    
    private:
        bool checkIfSegmentIsEmpty(int startX, int startY, int vectorX, int vectorY, int endX, int endY);
        Board &board;

};

#endif