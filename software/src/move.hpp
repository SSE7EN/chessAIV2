


#ifndef _SRC_MOVE_HPP_
#define _SRC_MOVE_HPP_

/**
**************************
* @file    move.hpp
* @author  SE7EN
* @date    2021-04-16
* @brief   
**************************
*/






/************************************* Includes *************************************/
#include <vector>
#include "enum.hpp"
#include "mempool.hpp"




/************************************* Classes *************************************/
class Spot;

class Piece;
class Rook;
class TakeMove;
class PawnSpecialTakeMove;
class CastleMove;
class Move{
    public:
        Spot& getOldSpot(){return oldSpot;};
        Spot& getNewSpot(){return newSpot;};
        Piece& getPieceMoved(){return pieceMoved;};

        Move(Piece &pieceMoved,Spot &oldSpot,Spot &newSpot):pieceMoved{pieceMoved}, oldSpot{oldSpot}, newSpot{newSpot}{};
        bool operator < (const Move& mv) const
        {
            return (this->getValue() < mv.getValue());
        }

        virtual int getValue() const {return 1;}
        virtual MoveType getMoveType(){return MoveType::Move;}

        void * operator new(size_t size, MempoolManager<Move, TakeMove,CastleMove,PawnSpecialTakeMove> &mempool);
    protected:
        friend class MoveHistory;


        Spot &oldSpot;
        Spot &newSpot;
        Piece &pieceMoved;
};

class TakeMove: public Move{
    public:
        TakeMove(Piece &pieceMoved, Piece &pieceTaken,Spot &oldSpot,Spot &newSpot):Move{pieceMoved, oldSpot, newSpot}, pieceTaken{pieceTaken}{};
        Piece& getPieceTaken(){return this->pieceTaken;}
        int getValue() const override {return 2;}
        MoveType getMoveType() override {return MoveType::Take;}

        

    private:

    Piece &pieceTaken;

};

class PawnSpecialTakeMove: public Move{
    public:
        PawnSpecialTakeMove(Piece &pieceMoved, Piece &pieceTaken,Spot &oldSpot,Spot &newSpot, Spot &pieceTakenSpot):Move{pieceMoved, oldSpot, newSpot}, pieceTaken{pieceTaken}, pieceTakenSpot{pieceTakenSpot}{};
        Piece& getPieceTaken(){return this->pieceTaken;}
        int getValue() const override {return 3;}
        MoveType getMoveType() override {return MoveType::SpecialPawnTake;}
        Spot& getPieceTakenSpot(){return this->pieceTakenSpot;}

        

    private:

    Piece &pieceTaken;
    Spot &pieceTakenSpot;

};

class CastleMove: public Move
{
    public:
        CastleMove(Piece &king, Spot &oldSpot, Spot &newSpot, Rook& rook, Spot &rookOldSpot, Spot &rookNewSpot):Move{king, oldSpot, newSpot},rookMoved{rook},rookOldSpot{rookOldSpot}, rookNewSpot{rookNewSpot}{}; 
        
        Spot& getRookOldSpot(){return this->rookOldSpot;};
        Spot& getRookNewSpot(){return this->rookNewSpot;};
        Rook& getRookMoved(){return this->rookMoved;};
        int getValue() const override {return 4;}
        MoveType getMoveType() override {return MoveType::Castle;}


    private:


    Rook &rookMoved;
    Spot &rookOldSpot;
    Spot &rookNewSpot;
};





#endif