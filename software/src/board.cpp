
/**
 **************************
 * @file    enum.hpp
 * @author  SE7EN
 * @date    2021-04-02
 * @brief   simple board for chess
 **************************
 */

/*-------------------------------- Includes ---------------------- */

#include <iostream>
#include <vector>
#include <algorithm>
#include "board.hpp"
#include "move.hpp"



Spot& Board::operator()(int indexX, int indexY)
{

    int i = GET_BOARD_INDEX(indexX,indexY);

    return (this->board[i]);

};

Spot& Board::getSpot(int cordX, int cordY)
{
    int i = GET_BOARD_INDEX(cordX,cordY);

    return (this->board[i]);
}

Board::Board()
{
    this->initializeBoard();
    this->setPieces();

}

void Board::changeColor()
{
    (this->colorPlaying == EColor::WHITE) ? this->colorPlaying = EColor::BLACK : this->colorPlaying = EColor::WHITE;
}

PieceSet& Board::getOpossiteSet(EColor color)
{
    if(color == EColor::BLACK) return this->whitePieces;
    else return this->blackPieces;
}


PieceSet& Board::getPlayingSet()
{
    if(this->colorPlaying == EColor::WHITE) return this->whitePieces;
    else return this->blackPieces;
}

PieceSet& Board::getSetByColor(EColor color)
{
    if(color == EColor::WHITE) return this->whitePieces;
    else return this->blackPieces;
}

void Board::initializeBoard()
{
    for(int i = 0 ; i < 8 ; ++i){
        for(int j = 0; j < 8; ++j){
            int x = j;
            int y = i;
            int idx = GET_BOARD_INDEX(x,y);
            this->board[idx].setCoordinates(x,y);
        }
    }
};

void Board::setPiece(Spot &spot, Piece &piece)
{
    spot.setPiece(&piece);
    piece.setCoordinate(spot.getCordX(), spot.getCordY());

}

void Board::setPieces()
{
    //set pieces
    for(int i = 0; i < 16; ++i){
        this->setPiece(this->board[i], this->whitePieces[i]);
        this->setPiece(this->board[BOARD_ARRAY_MAX_INDEX - i], this->blackPieces[i]);
    }
    this->setPiece(this->board[3], this->whitePieces[4]);
    this->setPiece(this->board[4], this->whitePieces[3]);
}
void Board::movePiece(std::unique_ptr<Move> &move)
{
    Move &tmpMove = this->moveHistory.addMoveToHistory(move);

    switch(tmpMove.getMoveType())
    {
        case MoveType::Move:
            this->move(tmpMove);
            break;
        case MoveType::Take:
            this->move(static_cast<TakeMove&>(tmpMove));
            break;
        case MoveType::Castle:
            this->move(static_cast<CastleMove&>(tmpMove));
            break;
        case MoveType::SpecialPawnTake:
            this->move(static_cast<PawnSpecialTakeMove&>(tmpMove));
            break;
    }

}

void Board::move(Move &move)
{

    move.getOldSpot().setPiece(nullptr);
    move.getPieceMoved().move(move);
    move.getNewSpot().setPiece(&move.getPieceMoved());

    
    this->changeColor();
    
}
void Board::move(TakeMove &move)
{

    move.getOldSpot().setPiece(nullptr);
    move.getPieceMoved().move(move);
    move.getNewSpot().setPiece(&move.getPieceMoved());
    move.getPieceTaken().kill();

    this->changeColor();
}
void Board::move(PawnSpecialTakeMove &move)
{

    move.getOldSpot().setPiece(nullptr);
    move.getPieceMoved().move(move);
    move.getNewSpot().setPiece(&move.getPieceMoved());
    move.getPieceTaken().kill();
    move.getPieceTakenSpot().setPiece(nullptr);

    this->changeColor();
}
void Board::move(CastleMove &move)
{
    move.getOldSpot().setPiece(nullptr);
    move.getPieceMoved().move(move);
    move.getNewSpot().setPiece(&move.getPieceMoved());
    move.getRookOldSpot().setPiece(nullptr);
    move.getRookMoved().move(move);
    move.getRookNewSpot().setPiece(&move.getRookMoved());

    this->changeColor();
}
void Board::undoPieceMove(Move &move)
{
    if(move.getNewSpot().getCordX() == 0 && move.getNewSpot().getCordY() == 2 && move.getPieceMoved().getPieceCode() == EPieceCode::PAWN )
    {
        std::cout<<"";
    }
    switch(move.getMoveType())
    {
        case MoveType::Move:
            this->undoMove(move);
            break;
        case MoveType::Take:
            this->undoMove(static_cast<TakeMove&>(move));
            break;
        case MoveType::Castle:
            this->undoMove(static_cast<CastleMove&>(move));
            break;
        case MoveType::SpecialPawnTake:
            this->undoMove(static_cast<PawnSpecialTakeMove&>(move));
            break;
    }
    
}
std::unique_ptr<Move> Board::undoAndGetLastMove()
{
    std::unique_ptr<Move> lastMove = std::move(this->moveHistory.getAndUndoLastMoveUniquePtr());

    this->undoPieceMove(*lastMove.get());


    return lastMove;
}

void Board::undoLastMove()
{
    std::unique_ptr<Move> lastMove = std::move(this->moveHistory.getAndUndoLastMoveUniquePtr());
    this->undoPieceMove(*lastMove.get());

};

void Board::undoMove(Move &move)
{
    move.getPieceMoved().undoMove(move);
    move.getOldSpot().setPiece(&move.getPieceMoved());
    move.getNewSpot().setPiece(nullptr);

    this->changeColor();
}
void Board::undoMove(TakeMove &move)
{
    move.getPieceMoved().undoMove(move);
    move.getOldSpot().setPiece(&move.getPieceMoved());
    move.getPieceTaken().revive();
    move.getNewSpot().setPiece(&move.getPieceTaken());

    this->changeColor();

}
void Board::undoMove(PawnSpecialTakeMove &move)
{
    move.getPieceMoved().undoMove(move);
    move.getOldSpot().setPiece(&move.getPieceMoved());
    move.getNewSpot().setPiece(nullptr);
    move.getPieceTaken().revive();
    move.getPieceTakenSpot().setPiece(&move.getPieceTaken());

    this->changeColor();

}
void Board::undoMove(CastleMove &move)
{
    move.getPieceMoved().undoMove(move);
    move.getOldSpot().setPiece(&move.getPieceMoved());
    move.getNewSpot().setPiece(nullptr);
    move.getRookMoved().undoMove(move);
    move.getRookOldSpot().setPiece(&move.getRookMoved());
    move.getRookNewSpot().setPiece(nullptr);

    this->changeColor();
}

 void Board::getPossibleMoves(std::vector<std::unique_ptr<Move>> &possibleMoves)
{

    PieceSet& playingSet = this->getPlayingSet();

    for(int i = 0; i < PIECE_COUNT; ++i)
    {
        playingSet[i].getPossibleMoves(possibleMoves,this->moveManager);
    }

    std::sort(possibleMoves.begin(), possibleMoves.end());

}
