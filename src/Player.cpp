#include "../inc/Player.hpp"

Player::Player(const std::string &side) : _side(side)
{
	int y = _side == "W" ? 1 : 6;
	for (int x = 0; x < 8; ++x) {
		_figArr[x] = new Pawn(_side, x, y);
	}
}

Player::~Player()
{
	delete []_figArr;
}
