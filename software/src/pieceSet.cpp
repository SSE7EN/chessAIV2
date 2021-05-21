/**
**************************
* @file    pieceSet.cpp
* @author  SE7EN
* @date    2021-05-08
* @brief   
**************************
*/






/************************************* Includes *************************************/
#include "pieceSet.hpp"





/************************************* Implementions *************************************/
Piece& PieceSet::operator[](int idx)
{


    if(idx >= 0 && idx < 16){
        return *(this->pieces[idx].get());
    }
    else throw std::invalid_argument( "received wrong idx" );

};
