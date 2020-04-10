#ifndef CHESS_QUEEN_HPP
#define CHESS_QUEEN_HPP

#include <iostream>
#include "AFigure.hpp"
#include "Game.hpp"

class Queen : public AFigure
{
public:
	Queen(const std::string &side, int posX, int posY);
	Queen(const Queen &src);
	Queen &operator=(const Queen &src);

	bool	validMove(int x, int y, const AFigure *fig);
	void	move(int x, int y);
};

#endif //CHESS_QUEEN_HPP
