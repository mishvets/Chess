#include "../inc/King.hpp"

King::King(const std::string &side, int posX, int posY) : AFigure(side, posX, posY)
{

}

King::King(const King &src) : AFigure(src)
{

}

King &King::operator=(const King &src)
{
	AFigure::operator=(src);
	return *this;
}

bool King::validMove(int x, int y, const AFigure *fig)
{
	return (x - _posX == 0 || x - _posX == 1 || x - _posX == -1) &&
		   (y - _posY == 0 || y - _posY == 1 || y - _posY == -1);
}

void King::move(int x, int y)
{
	_posX = x;
	_posY = y;
}