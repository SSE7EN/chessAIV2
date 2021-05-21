#ifndef _SPOT_HPP_
#define _SPOT_HPP_
/**
**************************
* @file    spot.hpp
* @author  SE7EN
* @date    2021-05-14
* @brief   
**************************
*/






/************************************* Includes *************************************/
#include "piece.hpp"





/************************************* Classes *************************************/
class Spot
{
    public:
        Spot(int cordX, int cordY):cordX{cordX},cordY{cordY}{};
        void setCoordinates(int x, int y){
            cordX = x;
            cordY = y;
        };
        void setPiece(Piece *piece){
            this->piece = piece;
        };

        int getCordX(){return cordX;};
        int getCordY(){return cordY;};
        
        Piece* getPiece(){return this->piece;};


    private:
        int cordX;
        int cordY;
        Piece *piece = nullptr;
};






#endif