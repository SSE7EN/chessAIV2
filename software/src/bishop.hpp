#ifndef _BISHOP_HPP_
#define _BISHOP_HPP_
/**
**************************
* @file    bishop.hpp
* @author  SE7EN
* @date    2021-05-08
* @brief   
**************************
*/






/************************************* Includes *************************************/
#include "linePiece.hpp"





/************************************* Classes *************************************/


class Bishop: public LinePiece{
    public:
        Bishop(EColor color):LinePiece{color,EPieceCode::BISHOP, 'B'}{};
        Bishop(EColor color, int cordX, int cordY):LinePiece{color, cordX, cordY, 'B', EPieceCode::BISHOP}{};
        void getPossibleMoves(std::vector<std::unique_ptr<Move>> &moves, MoveManager &moveM) override;
        virtual void fillAttackMatrix(int attackMatrix[8][8], MoveManager &moveM) override;

};




#endif