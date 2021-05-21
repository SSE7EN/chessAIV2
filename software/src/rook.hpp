#ifndef _ROOK_HPP_
#define _ROOK_HPP_
/**
**************************
* @file    rook.hpp
* @author  SE7EN
* @date    2021-05-08
* @brief   
**************************
*/






/************************************* Includes *************************************/
#include "linePiece.hpp"





/************************************* Classes *************************************/
class CastleMove;

class Rook: public LinePiece{
    public:
        Rook(EColor color):LinePiece{color,EPieceCode::ROOK, 'R'}{};
        Rook(EColor color, int cordX, int cordY):LinePiece{color, cordX, cordY, 'R', EPieceCode::ROOK}{};        
        void getPossibleMoves(std::vector<std::unique_ptr<Move>> &moves, MoveManager &moveM) override;

        bool getIsMoved(){return this->isMoved;}
        virtual void fillAttackMatrix(int attackMatrix[8][8], MoveManager &moveM) override;


    
    private:

        friend class Board;
        void recalculateIsMoved();
        void move(Move &move) override;
        void move(CastleMove &move);
        void undoMove(Move &move) override;   
        void undoMove(CastleMove &move); 
        void setIsMoved(bool status){this->isMoved = status;}

        bool isMoved{false};
        int moveCnt = 0;


};


#endif