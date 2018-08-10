#include <iostream>
#include "Game.cpp"

int main()
{
    cout << "ChessDec Started!..." << endl;
    Game *prtGame = new Game("WDC");
    prtGame->initGame();
    return 0;
}
