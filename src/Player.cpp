#include "../inc/Player.hpp"

Player::Player(const std::string &side) : _side(side)
{
//	std::shared_ptr<AFigure> ptr(p);
//	int y = _side == "W" ? 1 : 6;
//	for (int x = 0; x < 8; ++x) {
//		_figVct.push_back(new Pawn(_side, x, y));
//	}
}

Player::~Player()
{
	for (auto fig : _figVct)
		delete fig;
}

void Player::addFig(AFigure *fig)
{
	_figVct.push_back(fig);
}

