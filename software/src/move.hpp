


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





/************************************* Classes *************************************/
class Spot;

class Piece;

class Move{
    public:
        Spot& getStartSpot(){return startSpot;};
        Spot& getNewSpot(){return newSpot;};
        Piece& getPiece(){return pieceMoved;};

        Move(Piece &pieceMoved,Spot &startSpot,Spot &newSpot):pieceMoved{pieceMoved}, startSpot{startSpot}, newSpot{newSpot}{};
    protected:
        void virtual undoMove(){};
        friend class MoveHistory;


        Spot &startSpot;
        Spot &newSpot;
        Piece &pieceMoved;
};

class TakeMove: public Move{
    public:

    private:
    void undoMove() override;

    Piece* pieceTaken;

};



class MoveHistory{
    public:
        MoveHistory(){};


    private:
    std::vector<Move> moves;
};


#endif