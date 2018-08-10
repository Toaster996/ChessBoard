#include "Board.cpp"
#include <iostream>
using namespace std;

class Game
{
  public:
    Game(string name);
    void initGame();
    void startGame();

  private:
    Board *prtBoard;
    string name;
    bool isWhite;
    int moveCounter;

    string getUserInput();
    void analyzeInput(string input);
    void analyzePawnMove(string input);
    //TODO: Timer (Thread)
};

Game::Game(string name)
{
    prtBoard = new Board();
    name = name;
    isWhite = true;
    moveCounter = 1;
}

void Game::initGame()
{
    prtBoard->initBoard();
    prtBoard->printBoard();
}

void Game::startGame()
{
    wcout << "Game is Running..." << endl;
    bool gameRuns = true;
    while (gameRuns)
    {
        string input = getUserInput();
        wcout << "Input was " << input.c_str() << endl;
        analyzeInput(input);
        wcout << endl;
        isWhite = !isWhite;
    }
}

string Game::getUserInput()
{
    if (isWhite)
    {
        wcout << "White move " << moveCounter << endl;
    }
    else
    {
        wcout << "Black move " << moveCounter << endl;
        moveCounter++;
    }

    string x;
    cin >> x;
    return x;
}

void Game::analyzeInput(string input)
{
    int inputLength = input.size();
    if (inputLength == 2)
    {
        analyzePawnMove(input);
    }
}

void Game::analyzePawnMove(string input)
{
    char row = input.at(0);
    char col = input.at(1) - 1;
    int arrayPosRow = row - 97;
    wcout << "Field at " << arrayPosRow << " / " << col << endl;
    if (arrayPosRow < prtBoard->BOARD_SIZE && arrayPosRow >= 0)
        prtBoard->pawnMove(arrayPosRow, col, isWhite);
}
