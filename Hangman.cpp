#include <iostream>
#include "Game.h"
#include "HangmanGame.h"

int main()
{
    Game* game = new HangmanGame();
    game->play();
    delete game;
    return 0;
}