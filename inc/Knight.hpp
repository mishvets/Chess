#ifndef CHESS_KNIGHT_HPP
#define CHESS_KNIGHT_HPP

#include <iostream>
#include "AFigure.hpp"
//#include "Game.hpp"

class Knight : public AFigure
{
public:
	Knight(const std::string &side, int posX, int posY);
	Knight(const Knight &src);
	Knight &operator=(const Knight &src);

	bool validMove(int x, int y);
	void	move(int x, int y);
};

#endif //CHESS_KNIGHT_HPP
