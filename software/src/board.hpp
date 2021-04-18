#ifndef _SRC_BOARD_HPP_
#define _SRC_BOARD_HPP_
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
#include "move.hpp"

#define BOARD_ARRAY_MAX_INDEX 63 
#define GET_BOARD_INDEX(x,y) ((y * 8) + x)
#define WHITE_SQUARE "\033[47m"
#define BLACK_SQUARE "\033[40m"
#define WHITE_PIECE_COLOR "\033[96m"
#define BLACK_PIECE_COLOR "\033[31m"
#define RESET   "\033[0m"



class Coordinate{
    public:
        Coordinate(int coordinate){
            this->setCoordinate(coordinate);
        }
        Coordinate(){};
        int getCoordinate(){return this->coordinate;};
        void setCoordinate(int coordinate);



    
    private:
        int coordinate;
};


class Spot{
    public:
        Spot(Coordinate cordX, Coordinate cordY, Board &board):cordX{cordX},cordY{cordY}, board{board}{};
        Spot(Board &board):board{board}{};
        void setCoordinates(int x, int y){
            cordX.setCoordinate(x);
            cordY.setCoordinate(y);
        };
        void setPiece(Piece *piece){
            this->piece = piece;
        };

        Coordinate getCordX(){return cordX;};
        Coordinate getCordY(){return cordY;};
        
        Piece* getPiece(){return this->piece;};

        Board& getBoard(){return board;};

    private:
        Coordinate cordX;
        Coordinate cordY;
        Piece *piece;
        Board &board;
};


class Board{
    public:
        Board();
        Spot* operator() (int indexX, int indexY);
        void display();
        friend class Piece;

        void test();


    private:
        void initializeBoard();
        void setPieces();
        void setPiece(Spot &spot,Piece &piece);
        void printLine(int posY, std::string color1, std::string color2);
        
        PieceSet whitePieces{EColor::WHITE};
        PieceSet blackPieces{EColor::BLACK};
        MoveHistory moveHistory;
        

        


        

        std::array<Spot, 64> board
        {
            {
                Spot{*this},Spot{*this},Spot{*this},Spot{*this},Spot{*this},Spot{*this},Spot{*this},Spot{*this},
                Spot{*this},Spot{*this},Spot{*this},Spot{*this},Spot{*this},Spot{*this},Spot{*this},Spot{*this},
                Spot{*this},Spot{*this},Spot{*this},Spot{*this},Spot{*this},Spot{*this},Spot{*this},Spot{*this},
                Spot{*this},Spot{*this},Spot{*this},Spot{*this},Spot{*this},Spot{*this},Spot{*this},Spot{*this},
                Spot{*this},Spot{*this},Spot{*this},Spot{*this},Spot{*this},Spot{*this},Spot{*this},Spot{*this},
                Spot{*this},Spot{*this},Spot{*this},Spot{*this},Spot{*this},Spot{*this},Spot{*this},Spot{*this},
                Spot{*this},Spot{*this},Spot{*this},Spot{*this},Spot{*this},Spot{*this},Spot{*this},Spot{*this},
                Spot{*this},Spot{*this},Spot{*this},Spot{*this},Spot{*this},Spot{*this},Spot{*this},Spot{*this}
            }
        };
};

#endif
