#ifndef _SRC_PIECE_HPP_
#define _SRC_PIECE_HPP_
/**
 **************************
 * @file    piece.hpp
 * @author  SE7EN
 * @date    2021-04-02
 * @brief   simple pieces for chess
 **************************
 */


/*-------------------------------- Includes ---------------------- */
#include "enum.hpp"
#include <array>


class Spot;

class Move;



class Piece{
    public:
        Piece(EColor color): eColor(color){};
        Piece(EColor color, Spot &spot): eColor(color), spot(&spot){};
        virtual void move(Move &move) = 0;
        virtual ~Piece() = default;

    protected:
        void setPiece(Spot *spot){
            this->spot = spot;
        }


        EPieceCode ePieceCode;
        EColor eColor;
        Spot *spot;
};

class Pawn: public Piece{
    public:
        Pawn(EColor color);
        Pawn(EColor color, Spot &spot);
        void move(Move &move) override{};
};


class PieceSet{
    public:
        PieceSet(EColor eColor):eColor(eColor){};
        PieceSet() = delete;

    private:
        EColor eColor;
        std::array<Piece*, 1> pieces
        {
                {new Pawn(this->eColor)},
        };

};

#endif
