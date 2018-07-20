#include <iostream>
#include "chessboard.h"
#include"chessfunctions.h"

using namespace std;

int main()
{
    ChessBoard cb;
    cb.placePiece('E',2,'p');
    cb.placePiece('D',3,'p');
    cb.placePiece('E',4,'P');
    cb.debugPrint();

    auto tmp = ChessFunction::getPosibleMoves(cb);

    std::cout << endl << "number of possible moves: " << tmp.size() << endl;
    for(auto it = tmp.begin(); it != tmp.end();++it)
    {
        it->debugPrint();
        std::cout << std::endl;
    }


    return 0;
}
