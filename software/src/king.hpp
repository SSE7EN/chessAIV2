#ifndef _KING_HPP_
#define _KING_HPP_
/**
**************************
* @file    king.hpp
* @author  SE7EN
* @date    2021-05-08
* @brief   
**************************
*/






/************************************* Includes *************************************/
#include "piece.hpp"
#include "util.hpp"




/************************************* Classes *************************************/
class King: public Piece{
    public:
        King(EColor color):Piece{color, EPieceCode::KING,'K'}{};
        King(EColor color, int cordX, int cordY):Piece{color, cordX, cordY, 'K', EPieceCode::KING}{};
        void getPossibleMoves(std::vector<std::unique_ptr<Move>> &moves, MoveManager &moveM) override;
        bool canTake() override {return false;}
        virtual void fillAttackMatrix(int attackMatrix[8][8], MoveManager &moveM) override;

    
    private:
        SearchPossibleMoveResult getPossibleKingMove(MoveManager &moveM, int vectorX, int vectorY);
        void getPossibleCastle(MoveManager &moveM, std::vector<std::unique_ptr<Move>> &moves);
        void recalculateIsMoved();
        void move(Move &move) override;
        void undoMove(Move &move) override;    
        void setIsMoved(bool status){this->isMoved = status;}

        bool isMoved{false};
        int moveCnt = 0;  
};






#endif