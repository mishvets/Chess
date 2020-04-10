#ifndef CHESS_ROOK_HPP
#define CHESS_ROOK_HPP

#include <iostream>
#include "AFigure.hpp"
#include "Game.hpp"

class Rook : public AFigure
{
public:
	Rook(const std::string &side, int posX, int posY);
	Rook(const Rook &src);
	Rook &operator=(const Rook &src);

	bool	validMove(int x, int y, const AFigure *fig);
	void	move(int x, int y);
};


#endif //CHESS_ROOK_HPP
