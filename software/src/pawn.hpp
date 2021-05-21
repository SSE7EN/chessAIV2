#ifndef _PAWN_HPP_
#define _PAWN_HPP_
/**
**************************
* @file    pawn.hpp
* @author  SE7EN
* @date    2021-05-08
* @brief   
**************************
*/






/************************************* Includes *************************************/
#include "piece.hpp"
#include "util.hpp"




/************************************* Classes *************************************/
class Pawn: public Piece{

    public:
        Pawn(EColor color):Piece{color, EPieceCode::PAWN,'P'}{};
        Pawn(EColor color, int cordX, int cordY):Piece{color, cordX, cordY, 'P', EPieceCode::PAWN}{};
        virtual void fillAttackMatrix(int attackMatrix[8][8], MoveManager &moveM) override;

    private:
        void recalculateIsMoved();
        void move(Move &move) override;
        void undoMove(Move &move) override;    
        void setIsMoved(bool status){this->isMoved = status;}
        void getPossibleMoves(std::vector<std::unique_ptr<Move>> &moves, MoveManager &moveM) override;
        SearchPossibleMoveResult getPossibleOneForward(MoveManager &moveM);
        SearchPossibleMoveResult getPossibleTwoForward(MoveManager &moveM);
        SearchPossibleMoveResult getPossibleSpecialAttack(MoveManager &moveM);
        SearchPossibleMoveResult getPossibleAttack(MoveManager &moveM, int cordX, int cordY);

        


        bool isMoved{false};
        //to check if pawn has moved
        int moveCnt = 0;
    
};

#endif