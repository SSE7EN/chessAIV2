/**
**************************
* @file    piece.cpp
* @author  SE7EN
* @date    2021-04-16
* @brief   
**************************
*/






/************************************* Includes *************************************/
#include <stdexcept>
#include "piece.hpp"
#include "move.hpp"
#include "board.hpp"


/************************************* Implementions *************************************/
Piece& PieceSet::operator[](int idx)
{


    if(idx >= 0 && idx < 16){
        return *(this->pieces[idx].get());
    }
    else throw std::invalid_argument( "received wrong idx" );

};
void Piece::setSpot(Spot *spot)
{
    if(this->spot != nullptr) this->spot->setPiece(nullptr);
    this->spot = spot;
    this->spot->setPiece(this);
}
void Pawn::move(Move &mv)
{
    this->isMoved = true;
    this->setSpot(&(mv.getNewSpot()));
    
}
std::unique_ptr<Move> Pawn::checkOneForward(Board &brd){
    std::unique_ptr<Move> move = nullptr;

    //start coordinates
    Coordinate cordX = spot->getCordX();
    Coordinate cordY = spot->getCordY();

    //end coordinates
    int endCordY = cordY.getCoordinate() + static_cast<int>(eColor);
    if(endCordY < 8 && endCordY >= 0){
        Spot *newSpot = brd(cordX.getCoordinate(), endCordY); 
        if(newSpot->getPiece() == nullptr)
        {
            move = std::make_unique<Move>(*this,*(this->spot), *(newSpot));
        }
    }

    return move;
}

std::unique_ptr<Move> Pawn::checkTwoForward(Board &brd){
    std::unique_ptr<Move> move = nullptr;

    //start coordinates
    Coordinate cordX = spot->getCordX();
    Coordinate cordY = spot->getCordY();

    //end coordinates
    int endCordY = cordY.getCoordinate() + 2*static_cast<int>(eColor);
    if(endCordY < 8 && endCordY >= 0){
        Spot *newSpot = brd(cordX.getCoordinate(), endCordY); 
        if(newSpot->getPiece() == nullptr){
            move = std::make_unique<Move>(*this,*(this->spot), *(newSpot));
        }
    }

    return move;
}

std::vector<std::unique_ptr<Move>> Pawn::getPossibleMoves()
{
    std::vector<std::unique_ptr<Move>> possibleMoves;

    Board &brd = spot->getBoard();
    possibleMoves.push_back(this->checkOneForward(brd));
    possibleMoves.push_back(this->checkTwoForward(brd));

    
    return possibleMoves;
};



