#ifndef CHESS_PLAYER_HPP
#define CHESS_PLAYER_HPP

#include <iostream>
#include <vector>
//#include <bits/shared_ptr.h>
#include "AFigure.hpp"

class Player
{
public:
	Player(const std::string &side);
	~Player();

	const std::string &getSide() const;
	void	addFig(AFigure *fig);
private:
//	std::string _name;
	std::string				_side;
	std::vector<AFigure *>	_figVct;
	//std::shared_ptr
//	AFigure		_figVct[16];

};


#endif //CHESS_PLAYER_HPP
