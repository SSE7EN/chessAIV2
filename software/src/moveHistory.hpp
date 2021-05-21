#ifndef _SRC_MOVEHISTORY_HPP_
#define _SRC_MOVEHISTORY_HPP_
/**
**************************
* @file    moveHistory.hpp
* @author  SE7EN
* @date    2021-05-05
* @brief   
**************************
*/






/************************************* Includes *************************************/
#include <vector>
#include <memory>






/************************************* Classes *************************************/
class Move;


class MoveHistory{
    public:
        MoveHistory(){};

        Move* getLastMove();
        Move& addMoveToHistory(std::unique_ptr<Move> &mv);
        std::unique_ptr<Move> getAndUndoLastMoveUniquePtr();

        


    private:
    std::vector<std::unique_ptr<Move>> moves;
};


#endif