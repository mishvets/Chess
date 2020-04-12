#ifndef CHESS_PLAYER_HPP
#define CHESS_PLAYER_HPP

#include <iostream>
#include <vector>
#include "AFigure.hpp"
#include "King.hpp"
#include "Bishop.hpp"
#include "Knight.hpp"
#include "Rook.hpp"
#include "Queen.hpp"
#include "Pawn.hpp"

class Player
{
public:
	Player(const std::string &side);
	~Player();

	const std::string &getSide() const;
	AFigure * addNewFig(const std::string &label, int posX, int posY);
private:
//	std::string _name;
	std::string				_side;
	std::vector<AFigure *>	_figVct;
	//std::shared_ptr
//	AFigure		_figVct[16];

};


#endif //CHESS_PLAYER_HPP
