#ifndef CHESS_PLAYER_HPP
#define CHESS_PLAYER_HPP

#include <iostream>
#include "../inc/AFigure.hpp"

class Player
{
public:
	Player(const char &side);
	~Player();

private:
//	std::string _name;
	char		_side;
	AFigure		_figArr[16];

};


#endif //CHESS_PLAYER_HPP
