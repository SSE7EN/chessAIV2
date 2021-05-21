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
#include "moveManager.hpp"
#include "pieceSet.hpp"
#include "spot.hpp"

#define BOARD_ARRAY_MAX_INDEX 63 
#define GET_BOARD_INDEX(x,y) ((y * 8) + x)


class Move;
class TakeMove;
class CastleMove;
class PawnSpecialTakeMove;
class AIEngine;

class Board
{
    public:
    
        Board();
        Spot& operator() (int indexX, int indexY);
        Spot& getSpot(int cordX, int cordY);
        friend class Piece;

        MoveManager moveManager{*this};
        PieceSet& getOpossiteSet(EColor color);
        PieceSet& getPlayingSet();
        void getPossibleMoves(std::vector<std::unique_ptr<Move>>& possibleMoves);
        EColor getPlayingColor(){return this->colorPlaying;}

    private:
        void initializeBoard();
        void setPieces();
        void setPiece(Spot &spot,Piece &piece);
        void movePiece(std::unique_ptr<Move> &move);
        void move(Move &move);
        void move(TakeMove &move);
        void move(CastleMove &move);
        void move(PawnSpecialTakeMove &move);
        void undoPieceMove(Move &move);
        void undoMove(Move &move);
        void undoMove(TakeMove &move);
        void undoMove(CastleMove &move);
        void undoMove(PawnSpecialTakeMove &move);
        void undoLastMove();
        std::unique_ptr<Move> undoAndGetLastMove();

        void changeColor();

        

        friend class AIEngine;
        friend class MoveManager;

        PieceSet whitePieces{EColor::WHITE};
        PieceSet blackPieces{EColor::BLACK};

        EColor colorPlaying{EColor::WHITE};
        MoveHistory moveHistory;


        

        


        

        std::array<Spot, 64> board
        {
            {
                Spot{0,0},Spot{0,1},Spot{0,2},Spot{0,3},Spot{0,4},Spot{0,5},Spot{0, 6},Spot{0, 7},
                Spot{1,0},Spot{1,1},Spot{1,2},Spot{1,3},Spot{1,4},Spot{1,5},Spot{1, 6},Spot{1, 7},
                Spot{2,0},Spot{2,1},Spot{2,2},Spot{2,3},Spot{2,4},Spot{2,5},Spot{2, 6},Spot{2, 7},
                Spot{3,0},Spot{3,1},Spot{3,2},Spot{3,3},Spot{3,4},Spot{3,5},Spot{3, 6},Spot{3, 7},
                Spot{4,0},Spot{4,1},Spot{4,2},Spot{4,3},Spot{4,4},Spot{4,5},Spot{4, 6},Spot{4, 7},
                Spot{5,0},Spot{5,1},Spot{5,2},Spot{5,3},Spot{5,4},Spot{5,5},Spot{5, 6},Spot{5, 7},
                Spot{6,0},Spot{6,1},Spot{6,2},Spot{6,3},Spot{6,4},Spot{6,5},Spot{6, 6},Spot{6, 7},
                Spot{7,0},Spot{7,1},Spot{7,2},Spot{7,3},Spot{7,4},Spot{7,5},Spot{7, 6},Spot{7, 7},

            }
        };
};

#endif
