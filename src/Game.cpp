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
	_pl[0] = new Player("W");
	_pl[1] = new Player("B");

	startGame();

//	printBoard();

	//нанесение на доску
//	for (int i = 0; i < 16; ++i) {
//		for (int j = 0; j < 2; ++j) {
//			_board[_pl[j]->_figVct[i]->getPosY()][_pl[j]->_figVct[i]->getPosX()] = _pl[j]->_figVct[i];
//		}
//	}


}

Game::~Game()
{
	delete _pl[0];
	delete _pl[1];
	delete _instance;
//	for (int y = 0; y < _ySizeBoard; y++) {
//		delete _board[y];
//	}
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

bool Game::loadGame()
{
	std::ifstream loadFile;
	std::string	str;
	std::string gameMod;
	system("clear");
tryAgain:
	std::cout << "Choose game: " << std::endl;
	std::cout << "1. New game;" << std::endl;
	std::cout << "2. Load game;" << std::endl;
	std::cout << "Game mod: " << std::endl;
	std::getline(std::cin, gameMod);
	for (int i = 0; i < gameMod.length(); ++i)
		gameMod[i] = ::tolower(gameMod[i]);
	if (gameMod == "1" || gameMod == "new game")
		loadFile.open("./GameBoard/new.game");
	else if (gameMod == "2" || gameMod == "load game")
	{
		loadFile.open("./GameBoard/load.game");
		if (!loadFile.is_open())
			loadFile.open("./GameBoard/new.game");
	}
	else
	{
		std::cout << "Incorrect input. Try again" << std::endl;
		goto tryAgain;
	}
	if (!loadFile.is_open() || !readFile(loadFile))
	{
		std::cout << "Problem with load file" << std::endl;
		loadFile.close();
		return false;
	}
	loadFile.close();
	return true;
}

bool Game::readFile(std::ifstream &file)
{
	int			active;
	std::string	label;
	int 		posX;
	int 		posY;
	int 		numPl;
	AFigure		*fig;

	while (file)
	{
		file >> active;
		file >> label;
		file >> posX;
		file >> posY;
		numPl = label[0] == 'W'? 0 : 1;
		if (active)
		{
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
					return false;
			}
			_pl[numPl]->addFig(fig);
			setFig(fig, posX, posY);
		}
	}
	return true;
}

void Game::printBoard()
{
	system("clear");
	std::cout << "   " ;
	for (int x = 0; x < _xSizeBoard; ++x) {
		std::cout << "   " << (char)(x + 97) << " ";
	}
	std::cout << std::endl;
	std::cout << "    ———— ———— ———— ———— ———— ———— ———— ———— " << std::endl;

	for (int y = 0; y < _ySizeBoard; ++y) {
		std::cout << " " << y + 1 <<  " |";
		for (int x = 0; x < _xSizeBoard; ++x) {
			if (_board[y][x])
				std::cout << " " << _board[y][x]->getLabel() << " |";
			else
				std::cout << "    |";
		}
		std::cout << " " << y + 1 << std::endl;
		std::cout << "    ———— ———— ———— ———— ———— ———— ———— ———— " << std::endl;
	}
	std::cout << "   " ;
	for (int x = 0; x < _xSizeBoard; ++x) {
		std::cout << "   " << (char)(x + 97) << " ";
	}
	std::cout << std::endl;
	std::cout << std::endl;
//	std::cout << std::endl;
//	std::cout << " -----------------------" << std::endl;
//	for (int y = 0; y < _ySizeBoard; ++y) {
//		std::cout << "|";
//		for (int x = 0; x < _xSizeBoard; ++x) {
//			if (_board[y][x])
//				std::cout << _board[y][x]->getLabel() << "|";
//			else
//				std::cout << "  |";
//		}
//		std::cout << std::endl;
//		std::cout << " -----------------------" << std::endl;
//	}
//	std::cout << std::endl;
//	std::cout << std::endl;
//	std::cout << " -------------------------------" << std::endl;
//	for (int y = 0; y < _ySizeBoard; ++y) {
//		std::cout << "|";
//		for (int x = 0; x < _xSizeBoard; ++x) {
//			if (_board[y][x])
//				std::cout << _board[y][x]->getLabel()[0] << " " << _board[y][x]->getLabel()[1] << "|";
//			else
//				std::cout << "   |";
//		}
//		std::cout << std::endl;
//		std::cout << " -------------------------------" << std::endl;
//	}
}

void Game::userInput()
{
//	std::string userInp;
	std::string cmnd;
	std::string from;
	std::string to;

input:
	std::cout << "Enter command: ";
//	std::getline(std::cin, cmnd);
	std::cin >> cmnd;
	for (int i = 0; i < cmnd.length(); ++i)
		cmnd[i] = ::tolower(cmnd[i]);
	if (cmnd == "-m" || cmnd == "-move")
	{
		std::getline(std::cin, _crntMove);
		return;
	}
	else if (cmnd == "-s" || cmnd == "-save")
	{
//		save();
	}
	else if (cmnd == "-r" || cmnd == "-restart")
	{
	confirm:
		std::cout << "Are you sure you want to start a new game? Unsaved game will be lost." << std::endl;
		std::cout << "Enter (y/n):" << std::endl;
		std::cin >> cmnd;
		for (int i = 0; i < cmnd.length(); ++i)
			cmnd[i] = ::tolower(cmnd[i]);
		if (cmnd == "y" || cmnd == "yes")
		{
			startGame();
			return;
		}
		else if (cmnd == "n" || cmnd == "no")
			goto input;
		else
			goto confirm;
	}
	else
	{
		printUsage();
		goto input;
	}
}

void Game::printUsage()
{
	std::cout << "Usage : [COMMAND]" << std::endl;
	std::cout << "/t" << std::setw(45) << std::right << "-m [rowFrom] [colFrom] [rowTo] [colTo]" << "move figure;" << std::endl;
	std::cout << "/t" << std::setw(45) << std::right << "-s" << "save this game;" << std::endl;
	std::cout << "/t" << std::setw(45) << std::right << "-r" << "start new game;" << std::endl;
	std::cout << "/t" << std::setw(45) << std::right << "-q" << "quit from game;" << std::endl;
	std::cout << std::endl;
	std::cout << "Example : " << std::endl;
	std::cout << "/t-m a4 b5" << std::endl;
	std::cout << "/t-q" << std::endl;

}

void Game::startGame()
{
	// init board
//	_board = new AFigure**[_ySizeBoard];
	for (int y = 0; y < _ySizeBoard; ++y) {
//		_board[y] = new AFigure*[_xSizeBoard];
		for (int x = 0; x < _xSizeBoard; ++x) {
			_board[y][x] = nullptr;
		}
	}

	//load game
	if (!loadGame())
		exit(1);
}

void Game::saveGame()
{
	std::ofstream out("./GameBoard/load.game");
	if (!out)
	{
		std::cout << "Can`t save current game" << std::endl;
		return;
	}
	for (int y = 0; y < _ySizeBoard; ++y) {
		for (int x = 0; x < _xSizeBoard; ++x) {
			if (_board[y][x])
				out << "1 " << getFig(x, y)->getLabel() << " " << x << " " << y << std::endl;
		}
	}
}
