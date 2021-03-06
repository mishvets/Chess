#include "../inc/Rook.hpp"

Rook::Rook(const std::string &side, int posX, int posY) : AFigure(side, posX, posY)
{

}

Rook::Rook(const Rook&src) : AFigure(src)
{

}

Rook&Rook::operator=(const Rook&src)
{
	AFigure::operator=(src);
	return *this;
}

bool Rook::validMove(int x, int y)
{
	return (_posX == x || _posY == y);
}

void Rook::move(int x, int y)
{
	_posX = x;
	_posY = y;
}