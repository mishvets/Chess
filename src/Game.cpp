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
	_pl = new Player[2];
	_pl[0] = new Player("white");
	_pl[1] = new Player("black");

	// init map
	_map = new AFigure**[_ySizeMap];
	for (int i = 0; i < _ySizeMap; i++) {
		_map[i] = new AFigure*[_xSizeMap];
		for (int j = 0; j < _xSizeMap; j++) {
			_map[i][j] = nullptr; // !!!нужен ли такой указатель или автоматом выделяемое место указывает на 0?
		}
	}


}

Game::~Game()
{
	delete [] _pl;
	delete _instance;
	for (int i = 0; i < _ySizeMap; i++) {
		delete _map[i];
	}
	std::cout << "* Game default destructor *" << std::endl;

}