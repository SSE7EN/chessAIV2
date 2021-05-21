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

#include "game.hpp"

int main(){
    Game game{};

    game.start();
    return 0;
}