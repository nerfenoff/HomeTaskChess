#ifndef MOVETEMPLATE_H
#define MOVETEMPLATE_H

#include <vector>

typedef std::vector<std::vector<std::pair<int,int>>> MoveTemplate;

MoveTemplate pawnWhiteMoveNotTake =
{
    { std::pair<int,int>(0,1) }
};

MoveTemplate pawnWhireMoveTake =
{
    { std::pair<int,int>(1,1),std::pair<int,int>(-1,1) }
};

MoveTemplate pawnBlackMoveNotTake =
{
    { std::pair<int,int>(0,-1) }
};

MoveTemplate pawnBlackMoveTake =
{
    { std::pair<int,int>(1,-1),std::pair<int,int>(-1,-1) }
};

#endif // MOVETEMPLATE_H
