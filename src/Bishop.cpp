#include "../inc/Bishop.hpp"

Bishop::Bishop(const std::string &side, int posX, int posY) : AFigure(side, posX, posY)
{

}

Bishop::Bishop(const Bishop &src) : AFigure(src)
{

}

Bishop &Bishop::operator=(const Bishop &src)
{
	AFigure::operator=(src);
	return *this;
}

bool Bishop::validMove(int x, int y, const AFigure *fig)
{
	return (_posX - x == _posY - y || _posX - x == y - _posY);
}

void Bishop::move(int x, int y)
{
	_posX = x;
	_posY = y;
}