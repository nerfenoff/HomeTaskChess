#ifndef CHESSBOARD__
#define CHESSBOARD__

#include <iterator>

enum PlayerColour
{
    WHITE,BLACK
};

typedef char ChessPiece;


class ChessBoard;

class ChessBoardIterator : public std::iterator<std::input_iterator_tag,ChessPiece>
{
    int rank,file;
    ChessBoard* cb;
public:
    ChessBoardIterator(const ChessBoardIterator& that);

    bool operator != (const ChessBoardIterator& that);
    bool operator == (const ChessBoardIterator& that);
    ChessBoardIterator::value_type operator*()const;
    ChessBoardIterator& operator++();

    int getRank() const;
    char getFile() const;

private:
    ChessBoardIterator(ChessBoard* cb_,int rank_,int file_);

    friend ChessBoard;
};



class ChessBoard
{
    ChessPiece board[8][8];
    PlayerColour turn;
public:
    ChessBoard();
    bool isCheckMate() const;
    bool isCheck() const;
    bool isEmpty(char file, int rank) const;
    void placePiece(char file,int rank,ChessPiece piece);
    ChessBoard move(char fileFrom,int rankfrom,char fileTo,int rankTo) const;
    ChessPiece getPiece(char file,int rank) const;
    PlayerColour getTurn() const;
    void debugPrint() const;

    ChessBoardIterator begin();
    ChessBoardIterator end();

    friend class ChessBoardIterator;
};

#endif

