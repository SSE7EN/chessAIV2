#pragma once
/**
 **************************
 * @file    enum.hpp
 * @author  SE7EN
 * @date    2021-04-02
 * @brief   simple board for chess
 **************************
 */


/*-------------------------------- Includes ---------------------- */
#include <array>
#include "enum.hpp"
#include "piece.hpp"

class Coordinate{
    public:
        Coordinate(int coordinate){
            this->setCoordinate(coordinate);
        }
        Coordinate(){};
        int getCoordiante(){return this->coordinate;};
        void setCoordinate(int coordinate);



    
    private:
        int coordinate;
};


class Spot{
    public:
        Spot(Coordinate cordX, Coordinate cordY):cordX(cordX),cordY(cordY){};
        Spot(){};
        void setCoordinates(int x, int y){
            cordX.setCoordinate(x);
            cordY.setCoordinate(y);
        };
        void setPiece(Piece &piece){
            this->piece = &piece;
        };
        
        Piece* getPiece(){return this->piece;};

    private:
        Coordinate cordX;
        Coordinate cordY;
        Piece *piece;
};

class Board{
    public:
        Board();
        Spot& operator() (int indexX, int indexY);

    private:
        void initializeBoard();
        void initializePieces();


        PieceSet whitePieces();

        std::array<Spot, 64> board;
};


