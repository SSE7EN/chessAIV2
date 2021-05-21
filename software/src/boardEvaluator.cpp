/**
**************************
* @file    boardEvaluator.cpp
* @author  SE7EN
* @date    2021-05-17
* @brief   
**************************
*/






/************************************* Includes *************************************/
#include "boardEvaluator.hpp"
#include "board.hpp"
#include "pieceSet.hpp"
#include "piece.hpp"




/************************************* Implementions *************************************/
const SValueMatrix& BoardEvaluator::getValueMatrix(Piece &piece)
{
    int indexY = 0;
    piece.getColor() == EColor::BLACK ? indexY = 0 : indexY = 1; 

    switch(piece.getPieceCode())
    {
        case EPieceCode::KING:
            return piecesValueMatrix[indexY][0];
        case EPieceCode::QUEEN:
            return piecesValueMatrix[indexY][1];
        case EPieceCode::BISHOP:
            return piecesValueMatrix[indexY][2];
        case EPieceCode::KNIGHT:
            return piecesValueMatrix[indexY][3];
        case EPieceCode::ROOK:
            return piecesValueMatrix[indexY][4];
        case EPieceCode::PAWN:
            return piecesValueMatrix[indexY][5];
    }



}

int BoardEvaluator::evaluate(Board &board)
{
    int boardValue = 0;

    PieceSet &whiteSet = board.getOpossiteSet(EColor::BLACK);
    PieceSet &blackSet = board.getOpossiteSet(EColor::WHITE);

    for(int i = 0; i < PIECE_COUNT; ++i)
    {
        boardValue += BoardEvaluator::pieceEvaluate(whiteSet[i]);
        boardValue -= BoardEvaluator::pieceEvaluate(blackSet[i]);
    }

}

int BoardEvaluator::pieceEvaluate(Piece &piece)
{
    if(!piece.getIsKilled()) return 0;

    int posValue = BoardEvaluator::getValueMatrix(piece).value[piece.getX()][piece.getY()];

    return pieceValue[static_cast<int>(piece.getPieceCode())] + posValue;
}