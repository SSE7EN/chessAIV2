#ifndef _KNIGHT_HPP_
#define _KNIGHT_HPP_
/**
**************************
* @file    knight.hpp
* @author  SE7EN
* @date    2021-05-08
* @brief   
**************************
*/






/************************************* Includes *************************************/
#include "piece.hpp"
#include "util.hpp"




/************************************* Classes *************************************/

class Knight: public Piece{
    public:
        Knight(EColor color):Piece{color, EPieceCode::KNIGHT,'N'}{};
        Knight(EColor color, int cordX, int cordY):Piece{color, cordX, cordY, 'N', EPieceCode::KNIGHT}{};
        void getPossibleMoves(std::vector<std::unique_ptr<Move>> &moves, MoveManager &moveM) override;
        virtual void fillAttackMatrix(int attackMatrix[8][8], MoveManager &moveM) override;

    private:
        SearchPossibleMoveResult getKnigthPossibleMove(MoveManager &moveM, int vectorX, int vectorY);

};




#endif