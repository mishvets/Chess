#include "../inc/Knight.hpp"

Knight::Knight(const std::string &side, int posX, int posY) : AFigure(side, posX, posY)
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

bool Knight::validMove(int x, int y)
{
	int var[][2] = {
			{1,-2}, {2,-1}, {2,1}, {1,2},
			{-1,2}, {-2,1}, {-2,-1}, {-1,-2}};
	for (int i = 0; i < 8; ++i) {
		if (_posX + var[i][0] == x && _posY + var[i][1] == y)
			return true;
	}
	return false;
}

void Knight::move(int x, int y)
{
	_posX = x;
	_posY = y;
}