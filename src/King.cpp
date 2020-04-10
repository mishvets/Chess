#include "../inc/King.hpp"

King::King(const std::string &side, int posX, int posY) : AFigure(side + "K", posX, posY)
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
	return false;
}

void King::move(int x, int y)
{
	_posX = x;
	_posY = y;
}