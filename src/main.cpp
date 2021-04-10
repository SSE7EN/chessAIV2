/**
 **************************
 * @file    main.cpp
 * @author  SE7EN
 * @date    2021-04-08
 * @brief   simple main class for chess
 **************************
 */


/*-------------------------------- Includes ---------------------- */
#include <iostream>
#include <memory>
#include "board.hpp"

int main(){
    std::unique_ptr<Board> board = std::make_unique<Board>();
    

    return 0;
}