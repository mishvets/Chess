#include <iostream>
#include "./inc/Game.hpp"

int main()
{
	Game	*chess = Game::getInstance();
	chess->printBoard();

	return 0;
}
