/**
**************************
* @file    util.cpp
* @author  SE7EN
* @date    2021-05-08
* @brief   
**************************
*/






/************************************* Includes *************************************/
#include "util.hpp"
#include "move.hpp"




/************************************* Implementions *************************************/
void Util::addSearchPossibleMoveResultToVector(std::vector<std::unique_ptr<Move>> &moves, SearchPossibleMoveResult &result)
{
    if(result.possible)
    {
        moves.push_back(std::move(result.move));
    }
}


