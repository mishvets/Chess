#include "../inc/King.hpp"
#include "../inc/Game.hpp"

King::King(const std::string &side, int posX, int posY) : AFigure(side, posX, posY), _castling(0b111)
{

}

King::King(const King &src) : AFigure(src), _castling(0b111)
{

}

King &King::operator=(const King &src)
{
	AFigure::operator=(src);
	return *this;
}

bool King::validMove(int x, int y)
{
	std::string label = getLabel()[0] == 'W' ? "WR" : "BR";
	if (x - _posX == 2 && y - _posY == 0 && (_castling & (uint8_t)0b010) && _castling % 2) // short castling K -> R
	{
		for (int i = _posX + 1; i < 7; ++i) {
			if (Game::getInstance()->getFig(i, _posY))
				return false;
		}
		return (Game::getInstance()->getFig(7, _posY)->getLabel() == label);
	}
	if (_posX - x == 2 && y - _posY == 0 && (_castling & (uint8_t)0b100) && _castling % 2) // long castling R <- K
	{
		for (int i = _posX - 1; i > 0; --i) {
			if (Game::getInstance()->getFig(i, _posY))
				return false;
		}
		return (Game::getInstance()->getFig(0, _posY)->getLabel() == label);
	}
	return (x - _posX == 0 || x - _posX == 1 || x - _posX == -1) &&
		   (y - _posY == 0 || y - _posY == 1 || y - _posY == -1);
}

void King::move(int x, int y)
{
	if (x - _posX == 2)
		Game::getInstance()->moveFig(7, _posY, 5, _posY); // short castling K -> R
	else if (_posX - x == 2)
		Game::getInstance()->moveFig(0, _posY, 3, _posY); // long castling R <- K
	_posX = x;
	_posY = y;
	setCastling(0b110);
}

unsigned int King::getCastling() const
{
	return _castling;
}

void King::setCastling(unsigned int castling)
{
	_castling &= castling;
}

void King::setStartCastling(unsigned int castling)
{
	_castling = castling;
}

