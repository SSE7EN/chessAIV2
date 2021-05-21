#ifndef _PIECESET_HPP_
#define _PIECESET_HPP_
/**
**************************
* @file    pieceSet.hpp
* @author  SE7EN
* @date    2021-05-08
* @brief   
**************************
*/






/************************************* Includes *************************************/
#include <array>
#include <memory>
#include "enum.hpp"
#include "piece.hpp"
#include "pawn.hpp"
#include "rook.hpp"
#include "knight.hpp"
#include "bishop.hpp"
#include "queen.hpp"
#include "king.hpp"


#define PIECE_COUNT 16

/************************************* Classes *************************************/


class PieceSet{
    public:
        PieceSet(EColor eColor):eColor(eColor){};
        King& getKing(){return static_cast<King&>(*(this->pieces[3].get()));};
        Piece& operator[](int idx);
        EColor getColor(){return this->eColor;}

    private:
        EColor eColor;
        std::array<std::unique_ptr<Piece>, PIECE_COUNT> pieces
        {
                {
                    std::make_unique<Rook>(this->eColor),
                    std::make_unique<Knight>(this->eColor),
                    std::make_unique<Bishop>(this->eColor),
                    std::make_unique<King>(this->eColor),
                    std::make_unique<Queen>(this->eColor),
                    std::make_unique<Bishop>(this->eColor),
                    std::make_unique<Knight>(this->eColor),
                    std::make_unique<Rook>(this->eColor),
                    std::make_unique<Pawn>(this->eColor),
                    std::make_unique<Pawn>(this->eColor),
                    std::make_unique<Pawn>(this->eColor),
                    std::make_unique<Pawn>(this->eColor),
                    std::make_unique<Pawn>(this->eColor),
                    std::make_unique<Pawn>(this->eColor),
                    std::make_unique<Pawn>(this->eColor),
                    std::make_unique<Pawn>(this->eColor),
                }
        };

};


#endif