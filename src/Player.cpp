//
// Created by mshvets on 09.04.2020.
//

#include "Player.hpp"

Player::Player(const char &side) : _side(side)
{
//	int y;
	int y = _side == 'W' ? 1 : 6;
	for (int i = 0; i < 8; ++i) {
		//;
	}
}

Player::~Player()
{

}
