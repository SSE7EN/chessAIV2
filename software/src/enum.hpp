#ifndef _SRC_ENUM_HPP_
#define _SRC_ENUM_HPP_

/**
 **************************
 * @file    enum.hpp
 * @author  SE7EN
 * @date    2021-02-02
 * @brief   simple enums for chess
 **************************
 */

enum class EPieceCode{PAWN = 0, ROOK = 1, BISHOP = 2, KNIGHT = 3, QUEEN = 4, KING = 5};
enum class EColor{WHITE = 1, BLACK = -1};
enum class MoveType{Move = 1, Take = 2, Castle = 3, SpecialPawnTake = 4};

#endif
