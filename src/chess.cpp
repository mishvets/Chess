#include <iostream>
#include "../inc/Game.hpp"

int main()
{
	Game	*chess = Game::getInstance();
	chess->startGame();
	chess->runGame();

	delete chess;
	return 0;

}
