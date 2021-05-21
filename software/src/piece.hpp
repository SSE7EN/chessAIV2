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
#include <memory>
#include <vector>
#include <iostream>



class MoveManager;

class Spot;

class Move;

class Board;


class Piece{
    public:
        Piece(EColor color, EPieceCode pieceCode,char pieceCharacter): eColor{color},pieceCode{pieceCode}, pieceCharacter{pieceCharacter}{};
        Piece(EColor color, int cordX, int cordY, char pieceCharacter, EPieceCode pieceCode): eColor{color}, cordX{},cordY{cordY}, pieceCharacter{pieceCharacter}, pieceCode{pieceCode}{};
        virtual ~Piece() = default;
        
        char getCharacter(){return pieceCharacter;}
        EColor& getColor(){return eColor;}
        void setCoordinate(int cordX, int cordY)
        {
            this->cordX = cordX;
            this->cordY = cordY;
        }

        int getX(){return this->cordX;}
        int getY(){return this->cordY;}

        bool getIsKilled(){return this->isKilled;}
        
        virtual bool canTake(){return true;}
        EPieceCode getPieceCode(){return this->pieceCode;}
        virtual void getPossibleMoves(std::vector<std::unique_ptr<Move>> &moves, MoveManager &moveM) = 0;
        virtual void fillAttackMatrix(int attackMatrix[8][8], MoveManager &moveM) =0;

        
    private:
        friend class Board;
        void kill(){this->isKilled = true;}
        void revive(){this->isKilled = false;}
    
    
    protected:
        virtual void move(Move &move);
        virtual void undoMove(Move &move);


        EColor eColor;
        EPieceCode pieceCode;
        bool isKilled{false};
        char pieceCharacter;
        int cordX;
        int cordY;
};



#endif
