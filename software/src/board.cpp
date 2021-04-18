
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
#include <iostream>

void Coordinate::setCoordinate(int coordinate)
{
    if(coordinate >= 0 && coordinate <= 7){
        this->coordinate = coordinate;
    }
};

Spot* Board::operator()(int indexX, int indexY)
{
    Spot* result = nullptr;
    if(indexX >= 0 && indexX < 8 && indexY >= 0 && indexY < 8){
        int i = GET_BOARD_INDEX(indexX,indexY);
        result = &(this->board[i]);
    }
    return result;

};

Board::Board()
{
    this->initializeBoard();
    this->setPieces();

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
    //spot.setPiece(&piece);
    piece.setSpot(&spot);

}

void Board::setPieces()
{
    //set pieces
    for(int i = 0; i < 16; ++i){
        this->setPiece(this->board[i], this->whitePieces[i]);
        this->setPiece(this->board[BOARD_ARRAY_MAX_INDEX - i], this->blackPieces[i]);
        
    }
}
void Board::printLine(int posY, std::string color1, std::string color2)
{
    // Define the CELL variable here. 
   // It represents how many horizontal characters will form one squarite
   // The number of vertical characters will be CELL/2
   // You can change it to alter the size of the board 
   // (an odd number will make the squares look rectangular)
   int CELL = 6;

   // Since the width of the characters BLACK and WHITE is half of the height, 
   // we need to use two characters in a row.
   // So if we have CELL characters, we must have CELL/2 sublines
    for (int subLine = 0; subLine < CELL/2; subLine++)
    {
        // A sub-line is consisted of 8 cells, but we can group it
        // in 4 iPairs of black&white
        for (int iPair = 0; iPair < 4; iPair++)
        {
            // First cell of the pair
            for (int subColumn = 0; subColumn < CELL; subColumn++)
            {
                Piece *piece = (*this)(iPair *2, posY)->getPiece();

                if(subLine == 1 && subColumn == 3 && piece != nullptr)
                {
                    char character = piece->getCharacter();
                    std::cout<<((piece->eColor == EColor::WHITE) ? WHITE_PIECE_COLOR : BLACK_PIECE_COLOR)<<character;
                }
                else
                {
                    std::cout<<color1<<" ";
                }
            }

            // Second cell of the pair
            for (int subColumn = 0; subColumn < CELL; subColumn++)
            {
                Piece *piece = (*this)(iPair *2 + 1, posY)->getPiece();

                if(subLine == 1 && subColumn == 3 && piece != nullptr)
                {
                    
                    char character = piece->getCharacter();
                    std::cout<<((piece->eColor == EColor::BLACK) ? BLACK_PIECE_COLOR : WHITE_PIECE_COLOR)<<character;
                }
                else
                {
                    std::cout<<color2<<" ";
                }
            }
        }
        std::cout<<RESET<<std::endl;

    }

}

void Board::display()
{
    std::cout << "   A     B     C     D     E     F     G     H\n\n";

    for (int iLine = 7; iLine >= 0; iLine--)
    {
        if ( iLine%2 == 0)
        {
        // Line starting with BLACK
        printLine(iLine, BLACK_SQUARE, WHITE_SQUARE);
        }

        else
        {
        // Line starting with WHITE
        printLine(iLine, WHITE_SQUARE, BLACK_SQUARE);
        }
    }
}

void Board::test()
{
    Move *mv = nullptr;
    {
        std::vector<std::unique_ptr<Move>> test = whitePieces[9].getPossibleMoves();
        mv = test[0].get();
    }
    
}
