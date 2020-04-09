#ifndef CHESS_PLAYER_HPP
#define CHESS_PLAYER_HPP

#include <iostream>
#include "AFigure.hpp"
#include "Pawn.hpp"

class Player
{
public:
	Player(const std::string &side);
	~Player();

private:
//	std::string _name;
	std::string	_side;
	AFigure		_figArr[16];

};


#endif //CHESS_PLAYER_HPP
