#ifndef CHESS_BISHOP_HPP
#define CHESS_BISHOP_HPP

#include <iostream>
#include "AFigure.hpp"

class Bishop : public AFigure
{
public:
	Bishop(const std::string &side, int posX, int posY);
	Bishop(const Bishop &src);
	Bishop &operator=(const Bishop &src);

	bool validMove(int x, int y);
	void	move(int x, int y);
};


#endif //CHESS_BISHOP_HPP
