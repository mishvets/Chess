#include "../inc/Knight.hpp"

Knight::Knight(const std::string &side, int posX, int posY) : AFigure(side + "N", posX, posY)
{

}

Knight::Knight(const Knight &src) : AFigure(src)
{

}

Knight &Knight::operator=(const Knight &src)
{
	AFigure::operator=(src);
	return *this;
}

bool Knight::validMove(int x, int y, const AFigure *fig)
{
	return false;
}

void Knight::move(int x, int y)
{
	_posX = x;
	_posY = y;
}