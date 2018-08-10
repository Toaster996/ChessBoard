#include "Figure.cpp"
#include <iostream>
using namespace std;

class Board
{
  public:
    Board();
    void initBoard();
    void printBoard();
    const static int BOARD_SIZE = 8;
    Field prtFig [BOARD_SIZE][BOARD_SIZE];
    //Figure **prtFig;
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
        prtFig[i][1].setIdentifier('P', 0);
        prtFig[i][6].setIdentifier('P', 1);
    }
    //Rocks
    prtFig[0][0].setIdentifier('R', 0);
    prtFig[7][0].setIdentifier('R', 0);
    prtFig[0][7].setIdentifier('R', 1);
    prtFig[7][7].setIdentifier('R', 1);
    //Bishop
    prtFig[1][0].setIdentifier('B', 0);
    prtFig[6][0].setIdentifier('B', 0);
    prtFig[1][7].setIdentifier('B', 1);
    prtFig[6][7].setIdentifier('B', 1);
    //Knight
    prtFig[2][0].setIdentifier('N', 0);
    prtFig[5][0].setIdentifier('N', 0);
    prtFig[2][7].setIdentifier('N', 1);
    prtFig[5][7].setIdentifier('N', 1);
    //Queen/King
    prtFig[3][0].setIdentifier('Q', 0);
    prtFig[4][0].setIdentifier('K', 0);
    prtFig[3][7].setIdentifier('Q', 1);
    prtFig[4][7].setIdentifier('K', 1);
}

void Board::printBoard()
//TODO: print row/col number
//TODO: Back/White
{
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        int ascii = i + 17;
        char asciiChar = '0' + ascii;
        cout << asciiChar << "| ";
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            if (prtFig[i][j].getIdentifier() != ' ')
            {
                cout << prtFig[i][j].getIdentifier();
            }
            else
            {
                cout << 'x';
            }
            cout << ' ';
        }
        cout << endl;
    }
    cout << "   ";
    for(int i = 1; i < BOARD_SIZE+1; i++)
        cout << "_ ";
    cout << endl;
    cout << "   ";
    for(int i = 1; i < BOARD_SIZE+1; i++)
        cout << i << " ";
    cout << endl;
}