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
#include <memory>
#include <vector>

class Spot;

class Move;

class Board;

class Piece{
    public:
        Piece(EColor color, char pieceCharacter): eColor{color}, pieceCharacter{pieceCharacter}{};
        Piece(EColor color, Spot &spot, char pieceCharacter): eColor{color}, spot{&spot}, pieceCharacter{pieceCharacter}{};
        virtual ~Piece() = default;
        
        friend class Board;
        char getCharacter(){return pieceCharacter;};

    protected:
        virtual void move(Move &move) = 0;
        virtual std::vector<std::unique_ptr<Move>> getPossibleMoves() = 0;
        void setSpot(Spot *spot);


        EColor eColor;
        Spot *spot = nullptr;
        char pieceCharacter;
};

class Pawn: public Piece{
    public:
        Pawn(EColor color):Piece{color, 'P'}{};
        Pawn(EColor color, Spot &spot):Piece{color, spot, 'P'}{};

    private:
        void move(Move &move) override;
        std::vector<std::unique_ptr<Move>> getPossibleMoves() override;
        
        bool isMoved{false};
        std::unique_ptr<Move> checkOneForward(Board &brd);
        std::unique_ptr<Move> checkTwoForward(Board &brd);


    
};

class Rook: public Piece{
    public:
        Rook(EColor color):Piece{color, 'R'}{};
        Rook(EColor color, Spot &spot):Piece{color, spot, 'R'}{};
        void move(Move &move) override{};
        std::vector<std::unique_ptr<Move>> getPossibleMoves() override {}

};

class Knight: public Piece{
    public:
        Knight(EColor color):Piece{color, 'N'}{};
        Knight(EColor color, Spot &spot):Piece{color, spot, 'N'}{};
        void move(Move &move) override{};
        std::vector<std::unique_ptr<Move>> getPossibleMoves() override {}
};


class Bishop: public Piece{
    public:
        Bishop(EColor color):Piece{color, 'B'}{};
        Bishop(EColor color, Spot &spot):Piece{color, spot, 'B'}{};
        void move(Move &move) override{};
        std::vector<std::unique_ptr<Move>> getPossibleMoves() override {}
};

class King: public Piece{
    public:
        King(EColor color):Piece{color, 'K'}{};
        King(EColor color, Spot &spot):Piece{color, spot, 'K'}{};
        void move(Move &move) override{};
        std::vector<std::unique_ptr<Move>> getPossibleMoves() override {}
};

class Queen: public Piece{
    public:
        Queen(EColor color):Piece{color, 'Q'}{};
        Queen(EColor color, Spot &spot):Piece{color, spot, 'Q'}{};
        void move(Move &move) override{};
        std::vector<std::unique_ptr<Move>> getPossibleMoves() override {}
};


class PieceSet{
    public:
        PieceSet(EColor eColor):eColor(eColor){};
        King& getKing(){return static_cast<King&>(*(this->pieces[3].get()));};
        Piece& operator[](int idx);

    private:
        EColor eColor;
        std::array<std::unique_ptr<Piece>, 16> pieces
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
