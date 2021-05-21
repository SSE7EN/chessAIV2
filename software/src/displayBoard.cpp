/**
**************************
* @file    displayBoard.cpp
* @author  SE7EN
* @date    2021-05-16
* @brief   
**************************
*/






/************************************* Includes *************************************/
#include "displayBoard.hpp"
#include "board.hpp"
#include <iostream>




/************************************* Implementions *************************************/
void DisplayBoard::printLine(Board &board,int posY, std::string color1, std::string color2)
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
                Piece *piece = board(iPair *2, posY).getPiece();

                if(subLine == 1 && subColumn == 3 && piece != nullptr)
                {
                    char character = piece->getCharacter();
                    std::cout<<((piece->getColor() == EColor::WHITE) ? WHITE_PIECE_COLOR : BLACK_PIECE_COLOR)<<character;
                }
                else
                {
                    std::cout<<color1<<" ";
                }
            }

            // Second cell of the pair
            for (int subColumn = 0; subColumn < CELL; subColumn++)
            {
                Piece *piece = board(iPair *2 + 1, posY).getPiece();

                if(subLine == 1 && subColumn == 3 && piece != nullptr)
                {
                    
                    char character = piece->getCharacter();
                    std::cout<<((piece->getColor() == EColor::BLACK) ? BLACK_PIECE_COLOR : WHITE_PIECE_COLOR)<<character;
                }
                else
                {
                    std::cout<<color2<<" ";
                }
            }
        }
        std::cout<<RESET<<posY<<std::endl;

    }
}

void DisplayBoard::displayBoard(Board &board)
{
    std::cout << "   A     B     C     D     E     F     G     H\n\n";

    for (int iLine = 7; iLine >= 0; iLine--)
    {
        if ( iLine%2 == 0)
        {
            // Line starting with BLACK
            printLine(board,iLine, BLACK_SQUARE, WHITE_SQUARE);
            
        }

        else
        {
            // Line starting with WHITE
            printLine(board,iLine, WHITE_SQUARE, BLACK_SQUARE);
            
        }
    }
}