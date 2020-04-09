#include "../inc/Game.hpp"

Game	*Game::_instance = nullptr;

Game *Game::getInstance()
{
	if(!_instance)
		_instance = new Game();
	return _instance;
}

Game::Game()
{
	//init players
//	_pl = new Player[2];
	_pl[0] = new Player("W");
	_pl[1] = new Player("B");

	// init board
	_board = new AFigure**[_ySizeBoard];
	for (int y = 0; y < _ySizeBoard; y++) {
		_board[y] = new AFigure*[_xSizeBoard];
		for (int x = 0; x < _xSizeBoard; x++) {
			_board[y][x] = nullptr; // !!!нужен ли такой указатель или автоматом выделяемое место указывает на 0?
		}
	}
	for (int i = 0; i < 16; ++i) {
		for (int j = 0; j < 2; ++j) {
			_board[_pl[j]._figArr[i].getPosY()][_pl[j]._figArr[i].getPosX()] = &_pl[j]._figArr[i];
		}
	}


}

Game::~Game()
{
	delete [] _pl;
	delete _instance;
	for (int y = 0; y < _ySizeBoard; y++) {
		delete _board[y];
	}
	std::cout << "* Game default destructor *" << std::endl;

}

AFigure *Game::getFig(int posX, int posY) const
{
	return _board[posY][posX];
}

void Game::setFig(AFigure *fig, int posX, int posY)
{
	fig->setPosX(posX);
	fig->setPosY(posY);
	_board[posY][posX] = fig;
}

const std::string &Game::getLastMove() const
{
	return _lastMove;
}
