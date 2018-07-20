#ifndef CHESSFUNCTION__
#define CHESSFUNCTION__

#include "chessboard.h"
#include <vector>

namespace ChessFunction
{
    std::vector<ChessBoard> getPosibleMoves(ChessBoard cb);
    bool ownPiece(ChessPiece cp, PlayerColour turn);
}

#endif
