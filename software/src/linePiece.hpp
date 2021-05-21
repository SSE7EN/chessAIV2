#ifndef _LINEPIECE_HPP_
#define _LINEPIECE_HPP_
/**
**************************
* @file    linePiece.hpp
* @author  SE7EN
* @date    2021-05-08
* @brief   
**************************
*/






/************************************* Includes *************************************/
#include "piece.hpp"





/************************************* Classes *************************************/

class LinePiece: public Piece
{
    public:
        LinePiece(EColor color, EPieceCode pieceCode, char pieceChar):Piece{color, pieceCode, pieceChar}{};
        LinePiece(EColor color, int cordX, int cordY, char pieceChar, EPieceCode pieceCode):Piece{color, cordX, cordY, pieceChar, pieceCode}{};

    protected:
        void searchMovesInLine(MoveManager &moveM, std::vector<std::unique_ptr<Move>> &moves, int vectorX, int vectorY);
        void fillAttackMatrixInLine(int attackMatrix[8][8], MoveManager &moveM, int vectorX, int vectorY);

};





#endif