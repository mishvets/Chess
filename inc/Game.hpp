#ifndef CHESS_GAME_HPP
#define CHESS_GAME_HPP

#include <iostream>
#include "AFigure.hpp"

class Game
{
public:
	static const int _xSizeMap = 16;
	static const int _ySizeMap = 16;

	~Game();

	static Game	*getInstance();


private:
	static Game	*_instance;
	Player		*_pl;
	AFigure		***_map;

	Game();
};


#endif //CHESS_GAME_HPP
