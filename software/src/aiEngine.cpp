/**
**************************
* @file    aiEngine.cpp
* @author  SE7EN
* @date    2021-05-18
* @brief   
**************************
*/






/************************************* Includes *************************************/
#include <vector>
#include <memory>
#include <algorithm>

#include "king.hpp"
#include "aiEngine.hpp"
#include "boardEvaluator.hpp"
#include "move.hpp"
#include "board.hpp"

#include "displayBoard.hpp"


/************************************* Implementions *************************************/
int AIEngine::minimax(Board &board, int depth, int alpha, int beta, EColor color, King& whiteKing, King& blackKing)
{
    if(depth == 0) //or game is over
    {
        return BoardEvaluator::evaluate(board);
    }

    int eval = 0;

    if(color == EColor::WHITE)
    {
        int maxEval = -INFINITY;
        std::vector<std::unique_ptr<Move>> possibleMoves; 
        board.getPossibleMoves(possibleMoves);
        for(int i = 0; i < possibleMoves.size(); ++i)
        {
            board.movePiece(possibleMoves[i]);
            if(board.moveManager.validateMoveForCheck(whiteKing))
            {
                eval = minimax(board, depth-1, alpha, beta, EColor::BLACK, whiteKing, blackKing);
                maxEval = std::max(maxEval, eval);
                alpha = std::max(alpha, eval);
            }
            board.undoLastMove();

            if(beta <= alpha)
             break;
        }
        return maxEval;
    }
    else
    {
        int minEval = INFINITY;
        std::vector<std::unique_ptr<Move>> possibleMoves; 
        board.getPossibleMoves(possibleMoves);
        for(int i = 0; i < possibleMoves.size(); ++i)
        {
            board.movePiece(possibleMoves[i]);
            if(board.moveManager.validateMoveForCheck(blackKing))
            {
                eval = minimax(board, depth-1, alpha, beta, EColor::WHITE, whiteKing, blackKing);
                minEval = std::min(minEval, eval);
                beta = std::min(beta, eval);
            }

            //DisplayBoard::displayBoard(board);
            board.undoLastMove();

            if(beta <= alpha)
             break;
        }
        return minEval;
    }


}

void AIEngine::move()
{
    std::vector<std::unique_ptr<Move>> possibleMoves; 
    std::unique_ptr<Move> bestMove;
    std::unique_ptr<Move> tmpMove;
    board.getPossibleMoves(possibleMoves);
    King &whiteKing = this->board.getSetByColor(EColor::WHITE).getKing();
    King &blackKing = this->board.getSetByColor(EColor::BLACK).getKing();

    if(this->board.getPlayingColor() == EColor::WHITE)
    {
        int maxVal = -INFINITY;
        int tempVal = -INFINITY;
        for(int i = 0; i < possibleMoves.size(); ++i)
        {

            this->board.movePiece(possibleMoves[i]);
            tempVal = this->minimax(this->board, DEPTH, -INFINITY, +INFINITY, EColor::BLACK, whiteKing, blackKing);
            tmpMove = std::move(this->board.undoAndGetLastMove());
            if(tempVal > maxVal) bestMove = std::move(tmpMove);
        }
    }
    else{
        int minVal = INFINITY;
        int tempVal = INFINITY;
        for(int i = 0; i < possibleMoves.size(); ++i)
        {
            this->board.movePiece(possibleMoves[i]);
            tempVal = this->minimax(this->board, DEPTH, -INFINITY, +INFINITY, EColor::WHITE, whiteKing, blackKing);
            tmpMove = std::move(this->board.undoAndGetLastMove());
            if(tempVal < minVal) bestMove = std::move(tmpMove);
        }
    }

    this->board.movePiece(bestMove);   
}
        