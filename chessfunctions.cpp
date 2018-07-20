#include "chessfunctions.h"
#include "movetemplate.h"

void move(std::vector<ChessBoard> &result,const ChessBoard &cb,char file, int rank,
          const MoveTemplate& mt, bool canTake = true, bool canNotTake = true)
{
    char newFile;
    int newRank;

    for(auto direction = mt.begin(); direction != mt.end(); ++direction)
    {
        for(auto attempt = direction->begin(); attempt != direction->end(); ++attempt)
        {
            newFile = file + attempt->first;
            newRank = rank + attempt->second;
            if(newFile < 1 || newFile > 8 || newRank < 1 || newRank > 8)
            {
                break;
            }

            if(!cb.isEmpty(file+attempt->first,rank + attempt->second))
            {
                if(canTake && !ChessFunction::ownPiece(cb.getPiece(file,rank), cb.getTurn()))
                {
                    result.push_back(cb.move(file, rank, newFile, newRank));
                }
                break;
            }
            if(canNotTake)
            {
                result.push_back(cb.move(file, rank, newFile, newRank));
            }
        }
    }
}

// Regular functions

std::vector<ChessBoard> ChessFunction::getPosibleMoves(ChessBoard cb)
{
    std::vector<ChessBoard> result;

    PlayerColour turn = cb.getTurn();

    for(auto it = cb.begin(); it != cb.end();++it)
    {

        if(*it == ' ') continue;

        if(!ownPiece(*it,turn)) continue;

        int rank = it.getRank();
        char file = it.getFile();

        switch (*it) {
        case 'p':
            move(result,cb,file,rank,pawnWhiteMoveNotTake,false,true);
            move(result,cb,file,rank,pawnWhireMoveTake,true,false);
            break;
        case 'P':
            move(result,cb,file,rank,pawnBlackMoveNotTake,false,true);
            move(result,cb,file,rank,pawnBlackMoveTake,true,false);
            break;
        case 'b':

            break;
        default:
            break;
        }


    }

    return result;
}

bool ChessFunction::ownPiece(ChessPiece cp, PlayerColour turn)
{
    return (cp >= 'a' && cp <= 'z' && turn == WHITE);
}
