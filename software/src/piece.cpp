#include "piece.hpp"

Pawn::Pawn(EColor color):Piece{color}{
    this->ePieceCode = EPieceCode::PAWN;
};

Pawn::Pawn(EColor color, Spot &spot):Piece{color, spot}{
    this->ePieceCode = EPieceCode::PAWN;
};