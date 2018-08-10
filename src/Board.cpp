#include "Figure.cpp"
#include <iostream>
#include <io.h>
#include <fcntl.h>
using namespace std;

class Board
{
  public:
    Board();

    const static int BOARD_SIZE = 8;
    Field prtFig[BOARD_SIZE][BOARD_SIZE];

    void initBoard();
    void printBoard();
    void pawnMove(int row, int col, bool pawnMove);

    //Figure **prtFig;
    const static wchar_t PAWN_WHITE = L'\u2659';
    const static wchar_t PAWN_BLACK = L'\u265F';

  private:
};

Board::Board()
{
    /* prtFig = new Figure *[BOARD_SIZE];
    for (int i = 0; i < BOARD_SIZE; ++i)
        prtFig[i] = new Figure[BOARD_SIZE];

    /*for (int i = 0; i < BOARD_SIZE; i++)
    {
        for (int j = 0; j < BOARD_SIZE; j++)
        {
           cout << board[i][j].identifier;
        }
    }
    cout << endl;*/
}

void Board::initBoard()
{
    //Pawns
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        prtFig[i][1].setIdentifier(L'\u2659', 0);
        prtFig[i][6].setIdentifier(L'\u265F', 1);
    }
    //Rocks
    prtFig[0][0].setIdentifier(L'\u2656', 0);
    prtFig[7][0].setIdentifier(L'\u2656', 0);
    prtFig[0][7].setIdentifier(L'\u265C', 1);
    prtFig[7][7].setIdentifier(L'\u265C', 1);
    //Bishop
    prtFig[2][0].setIdentifier(L'\u2657', 0);
    prtFig[5][0].setIdentifier(L'\u2657', 0);
    prtFig[2][7].setIdentifier(L'\u265D', 1);
    prtFig[5][7].setIdentifier(L'\u265D', 1);
    //Knight
    prtFig[1][0].setIdentifier(L'\u2658', 0);
    prtFig[6][0].setIdentifier(L'\u2658', 0);
    prtFig[1][7].setIdentifier(L'\u265E', 1);
    prtFig[6][7].setIdentifier(L'\u265E', 1);
    //Queen/King
    prtFig[3][0].setIdentifier(L'\u2655', 0);
    prtFig[4][0].setIdentifier(L'\u2654', 0);
    prtFig[3][7].setIdentifier(L'\u265B', 1);
    prtFig[4][7].setIdentifier(L'\u265A', 1);
}

void Board::printBoard()
//TODO: print row/col number
//TODO: Back/White
{
    /*wcout << L"♔" << endl;
    wcout << "dawdawsd";
    cout << "deafas";
    wchar_t test = L'\u2658';
    wcout << test << endl;
    wcout << L"\u2658" << endl;*/

    _setmode(_fileno(stdout), _O_U16TEXT);
    bool isWhite = false;
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        int ascii = i + 17;
        char asciiChar = '0' + ascii;
        wcout << asciiChar << "| ";
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            if (prtFig[i][j].getIdentifier() != 'x')
            {
                wcout << prtFig[i][j].getIdentifier();
            }
            else
            {
                if (isWhite)
                {
                    wcout << L'\u2589';
                }
                else
                {
                    wcout << " ";
                }
            }
            isWhite = !isWhite;
            wcout << ' ';
        }
        wcout << endl;
        isWhite = !isWhite;
    }
    wcout << "   ";
    for (int i = 1; i < BOARD_SIZE + 1; i++)
        wcout << "_ ";
    wcout << endl;
    wcout << "   ";
    for (int i = 1; i < BOARD_SIZE + 1; i++)
        wcout << i << " ";
    wcout << endl;
}

void Board::pawnMove(int row, int col, bool isWhite)
{
    Field* previosField ;
    if(isWhite)
        previosField = &prtFig[row][col - 1];
    else
        previosField = &prtFig[row][col + 1];

    wcout << "previous identifier " << previosField->getIdentifier() << endl;
    if (isWhite && previosField->getIdentifier() == PAWN_WHITE ||
        !isWhite && previosField->getIdentifier() == PAWN_BLACK)
    {
        wcout << &prtFig[row][col - 1] << endl;
        wcout << previosField << endl;
    }
    previosField->setIdentifier(L'\u0023', isWhite);
}