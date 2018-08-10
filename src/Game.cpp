#include "Board.cpp"
#include <iostream>
using namespace std;

class Game
{
  public:
    Game(string name);
    void initGame();

  private:
    Board *prtBoard;
    string name;
};

Game::Game(string name)
{
    prtBoard = new Board();
    name = name;
    cout << "Board is at " << prtBoard << endl;
    //test
    //prtBoard->initBoard();
}

void Game::initGame()
{
    cout << "Board is at " << prtBoard << endl;
    prtBoard->initBoard();
    prtBoard->printBoard();
}
