/**
**************************
* @file    move.cpp
* @author  SE7EN
* @date    2021-05-14
* @brief   
**************************
*/






/************************************* Includes *************************************/
#include "move.hpp"
#include "mempool.hpp"




/************************************* Implementions *************************************/


void * Move::operator new(size_t size, MempoolManager<Move, TakeMove,CastleMove,PawnSpecialTakeMove> &mempool)
{
    mempool.allocateBlock1();
}