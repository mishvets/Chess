#include "../inc/Pawn.hpp"

Pawn::Pawn(const std::string &side, int posX, int posY) : AFigure(side, posX, posY)
{

}

Pawn::Pawn(const Pawn &src) : AFigure(src)
{

}

Pawn &Pawn::operator=(const Pawn &src)
{
	AFigure::operator=(src);
	return *this;
}

bool Pawn::validMove(int x, int y, const AFigure *fig)
{
	int direct = this->_label[0] == 'W' ? 1 : -1;
	if (x == _posX && fig == nullptr)
	{
		if (y == _posY + direct) // 1 step
			return true;
		else if (y == _posY + direct * 2 && (_posY == 1 || _posY == 6)) // 2 step from start position
			return true;
	}
	else if ((x == _posX + 1 || x == _posX - 1) &&  y == _posY + direct) // diagonal kick
	{
		if (fig && fig->getLabel()[0] != this->_label[0])
			return true;
		else if (!fig)
			return (enPassant(x));
	}
	return false;
}

void Pawn::move(int x, int y)
{
	_posX = x;
	_posY = y;
}

bool Pawn::enPassant(int xNext)
{
	AFigure		*fig;
	std::string	lastMove;
	int 		xLastMvFrom;
	int 		yLastMvFrom;
	int 		xLastMvTo;
	int 		yLastMvTo;
	int			direct;

	if ((_label[0] == 'W' && _posY == 4) || (_label[0] == 'B' && _posY == 3))
	{
		lastMove = Game::getInstance()->getLastMove();
		xLastMvFrom = (int)lastMove[0] - 97;
		yLastMvFrom = (int)lastMove[1] - 49;
		xLastMvTo = (int)lastMove[3] - 97;
		yLastMvTo = (int)lastMove[4] - 49;
		if (xNext == xLastMvTo && _posY == yLastMvTo) //last move have been near current pawn
		{
			fig = Game::getInstance()->getFig(xNext, _posY);
			if (fig && fig->getLabel()[1] == 'P' && fig->getLabel()[0] != _label[0]) //The fig is opposite pawn
			{
				direct = fig->getLabel()[0] == 'W' ? 1 : -1;
				if (xLastMvTo == xLastMvFrom && yLastMvTo - yLastMvFrom == direct * 2) //The opposite pawn has moved two squares from its original square
				{
					fig->setActive(false);
					Game::getInstance()->setFig(nullptr, xLastMvTo, yLastMvTo); //Move opposite pawn from board
					return true;
				}
			}
		}
	}
	return false;
}
