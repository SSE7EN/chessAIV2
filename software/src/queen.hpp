#ifndef _QUEEN_HPP_
#define _QUEEN_HPP_
/**
**************************
* @file    queen.hpp
* @author  SE7EN
* @date    2021-05-09
* @brief   
**************************
*/






/************************************* Includes *************************************/
#include "linePiece.hpp"





/************************************* Classes *************************************/


class Queen: public LinePiece{
    public:
        Queen(EColor color):LinePiece{color,EPieceCode::QUEEN,'Q'}{};
        Queen(EColor color, int cordX, int cordY):LinePiece{color, cordX, cordY, 'Q', EPieceCode::QUEEN}{};
        void getPossibleMoves(std::vector<std::unique_ptr<Move>> &moves, MoveManager &moveM) override;
        virtual void fillAttackMatrix(int attackMatrix[8][8], MoveManager &moveM) override;

};








#endif