#ifndef _UTIL_HPP_
#define _UTIL_HPP_
/**
**************************
* @file    util.hpp
* @author  SE7EN
* @date    2021-05-08
* @brief   
**************************
*/






/************************************* Includes *************************************/
#include <memory>
#include <vector>
#include "move.hpp"




/************************************* Classes *************************************/
class Move;
class MoveManager;

struct SearchPossibleMoveResult
{
    bool possible = false;
    std::unique_ptr<Move> move = nullptr;
};

class Util
{
    public:
        static void addSearchPossibleMoveResultToVector(std::vector<std::unique_ptr<Move>> &moves, SearchPossibleMoveResult &result);
};


#endif