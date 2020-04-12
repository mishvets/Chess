#ifndef CHESS_KING_HPP
#define CHESS_KING_HPP

#include <iostream>
#include "AFigure.hpp"
//#include "Game.hpp"

class King : public AFigure
{
public:
	King(const std::string &side, int posX, int posY);
	King(const King &src);
	King &operator=(const King &src);

	bool	validMove(int x, int y);
	void	move(int x, int y);

	unsigned int	getCastling() const;
	void 			setCastling(unsigned int castling);

private:
	unsigned int 	_castling;	//0b111

};


#endif //CHESS_KING_HPP
