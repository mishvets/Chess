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

	const std::string	&getSide() const;
	King				*getKing() const;
	bool				isCheck() const;

	void 		setCheck(bool check);
	AFigure		*addNewFig(const std::string &label, int posX, int posY);

private:
//	std::string _name;
	std::string				_side;
	King					*_king;
	int						_castling; //0b111
	std::vector<AFigure *>	_figVct;
	bool 					_check;
	//std::shared_ptr
//	AFigure		_figVct[16];

};


#endif //CHESS_PLAYER_HPP
