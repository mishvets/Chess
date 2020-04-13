#include "../inc/Player.hpp"

Player::Player(const std::string &side) : _side(side), _check(false)
{

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
			_king = new King(label, posX, posY);
			fig = _king;
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

King *Player::getKing() const
{
	return _king;
}

bool Player::isCheck() const
{
	return _check;
}

void Player::setCheck(bool check)
{
	_check = check;
}


