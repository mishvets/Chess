#include "../inc/Queen.hpp"

Queen::Queen(const std::string &side, int posX, int posY) : AFigure(side, posX, posY)
{

}

Queen::Queen(const Queen &src) : AFigure(src)
{

}

Queen &Queen::operator=(const Queen &src)
{
	AFigure::operator=(src);
	return *this;
}

bool Queen::validMove(int x, int y, const AFigure *fig)
{
	return false;
}

void Queen::move(int x, int y)
{
	_posX = x;
	_posY = y;
}