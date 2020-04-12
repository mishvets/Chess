#include "../inc/Player.hpp"

Player::Player(const std::string &side) : _side(side)
{
//	std::shared_ptr<AFigure> ptr(p);
//	int y = _side == "W" ? 1 : 6;
//	for (int x = 0; x < 8; ++x) {
//		_figVct.push_back(new Pawn(_side, x, y));
//	}
}

Player::~Player()
{
	for (auto fig : _figVct)
		delete fig;
}

AFigure *Player::addNewFig(const std::string &label, int posX, int posY)
{
	AFigure	*fig;
	switch (label[1])
	{
		case 'P':
			fig = new Pawn(label, posX, posY);
			break;
		case 'R':
			fig = new Rook(label, posX, posY);
			break;
		case 'N':
			fig = new Knight(label, posX, posY);
			break;
		case 'B':
			fig = new Bishop(label, posX, posY);
			break;
		case 'Q':
			fig = new Queen(label, posX, posY);
			break;
		case 'K':
			fig = new King(label, posX, posY);
			break;
		default:
			std::cout << "Error: Bad label in file" << std::endl;
			return nullptr;
	}
	_figVct.push_back(fig);
	return fig;
}

const std::string &Player::getSide() const
{
	return _side;
}

