
/**
 **************************
 * @file    enum.hpp
 * @author  SE7EN
 * @date    2021-04-02
 * @brief   simple board for chess
 **************************
 */

/*-------------------------------- Includes ---------------------- */

#include "board.hpp"


void Coordinate::setCoordinate(int coordinate){
    if(coordinate >= 0 && coordinate <= 7){
        this->coordinate = coordinate;
    }
};

Spot& Board::operator()(int indexX, int indexY){
    int i = indexY * 8 + indexX;
    return this->board[i];
};

Board::Board(){
    this->initializeBoard();
}

void Board::initializeBoard(){
    for(int i = 0 ; i < 8 ; ++i){
        for(int j = 0; j < 8; ++j){
            int x = j;
            int y = i;
            int indx = y * 8 + x;
            this->board[indx].setCoordinates(x,y);
        }
    }
};

void Board::initializePieces(){
    
}

