#ifndef CHESS_PAWN_HPP
#define CHESS_PAWN_HPP

#include <iostream>
#include "AFigure.hpp"
#include "Game.hpp"

class Pawn : public AFigure
{
public:
	Pawn(const std::string &side, int posX, int posY);
	Pawn(const Pawn &src);
//	~Pawn();
	Pawn &operator=(const Pawn &src);

	bool validMove(int x, int y);
	void	move(int x, int y);
	bool	enPassant(int xNext);
};


#endif //CHESS_PAWN_HPP
