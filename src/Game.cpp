#include "../inc/Game.hpp"

Game	*Game::_instance = nullptr;

Game *Game::getInstance()
{
	if(!_instance)
		_instance = new Game();
	return _instance;
}

Game::Game() : _plIndx(0)
{
	//init players
	_pl[0] = new Player("White");
	_pl[1] = new Player("Black");

//	startGame();

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
//	delete _instance;
//	for (int y = 0; y < _ySizeBoard; y++) {
//		delete _board[y];
//	}
	std::cout << "* End Game *" << std::endl;
}

AFigure *Game::getFig(int posX, int posY) const
{
	return _board[posY][posX];
}

void Game::setFig(AFigure *fig, int posX, int posY)
{
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
	std::cout << "\t1. New game;" << std::endl;
	std::cout << "\t2. Load game;" << std::endl;
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

	std::getline(file, _lastMove);
	if (_lastMove == "0")
		_lastMove.clear();
	_crntMove.clear();
	file >> _plIndx;
	while (file)
	{
		file >> active;
		file >> label;
		file >> posX;
		file >> posY;
		numPl = label[0] == 'W'? 0 : 1;
//		if (active)
//		{
			fig = _pl[numPl]->addNewFig(label, posX, posY);
			setFig(fig, posX, posY);
//		}
	}
	return true;
}

void Game::printBoard()
{
	if (_errMsg.empty())
	{
		if (!_win.empty())
		{
			std::cout << _win << std::endl;
			return;
		}
		system("clear");
		std::cout << "                   W H I T E" << std::endl;
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
		std::cout << "                   B L A C K" << std::endl;
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

	else
	{
		std::cout << _errMsg << std::endl;
		_errMsg.clear();
	}

}

bool Game::userInput()
{
//	std::string userInp;
	std::string cmnd;
//	std::string from;
//	std::string to;

input:
	std::cout << "<" << _pl[_plIndx]->getSide() <<"> Enter command: ";
	std::getline(std::cin, cmnd);
	_crntMove = cmnd.substr(cmnd.find(' ') + 1);
	cmnd = cmnd.substr(0,cmnd.find(' '));
//	std::cin >> cmnd;
	for (int i = 0; i < cmnd.length(); ++i)
		cmnd[i] = ::tolower(cmnd[i]);
	if (cmnd == "-m" || cmnd == "-move")
	{
//		std::getline(std::cin, _crntMove);
		if (_crntMove.length() == 5)
			return true;
	}
	else if (cmnd == "-s" || cmnd == "-save")
	{
		saveGame();
		goto input;
	}
	else if (cmnd == "-r" || cmnd == "-restart")
	{
	confirmR:
		std::cout << "Are you sure you want to start a new game? Unsaved game will be lost." << std::endl;
		std::cout << "Enter (y/n):" << std::endl;
		std::getline(std::cin, cmnd);
		for (int i = 0; i < cmnd.length(); ++i)
			cmnd[i] = ::tolower(cmnd[i]);
		if (cmnd == "y" || cmnd == "yes")
		{
			startGame();
			goto input;
		}
		else if (cmnd == "n" || cmnd == "no")
			goto input;
		else
			goto confirmR;
	}
	else if (cmnd == "-q" || cmnd == "-quit")
	{
	confirmQ:
		std::cout << "Are you sure you want quit from game? Unsaved game will be lost." << std::endl;
		std::cout << "Enter (y/n):" << std::endl;
		std::getline(std::cin, cmnd);
		for (int i = 0; i < cmnd.length(); ++i)
			cmnd[i] = ::tolower(cmnd[i]);
		if (cmnd == "y" || cmnd == "yes")
			return false;
		else if (cmnd == "n" || cmnd == "no")
			goto input;
		else
			goto confirmQ;
	}
	printUsage();
	goto input;
}

void Game::printUsage()
{
	std::cout << "Usage : [COMMAND]" << std::endl;
	std::cout << "\t" << std::setw(45) << std::left << "-m [rowFrom][colFrom] [rowTo][colTo]" << "move figure;" << std::endl;
	std::cout << "\t" << std::setw(45) << std::left << "-s" << "save this game;" << std::endl;
	std::cout << "\t" << std::setw(45) << std::left << "-r" << "start new game;" << std::endl;
	std::cout << "\t" << std::setw(45) << std::left << "-q" << "quit from game;" << std::endl;
	std::cout << std::endl;
	std::cout << "Example : " << std::endl;
	std::cout << "\t-m a4 b5" << std::endl;
	std::cout << "\t-q" << std::endl;

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
	printBoard();
	printUsage();
}

void Game::saveGame()
{
	std::ofstream out("./GameBoard/load.game");
	if (!out)
	{
		std::cout << "Can`t save current game" << std::endl;
		return;
	}
	if (!_lastMove.empty())
		out << _lastMove << std::endl;
	else
		out << "0" << std::endl;
	out << _plIndx << std::endl;
	for (int y = 0; y < _ySizeBoard; ++y) {
		for (int x = 0; x < _xSizeBoard; ++x) {
			if (_board[y][x])
				out << "1 " << getFig(x, y)->getLabel() << " " << x << " " << y << std::endl;
		}
	}
	out.close();
}

void Game::runGame()
{
	while (_win.empty() && userInput())
	{
		updateGame();
		printBoard();
	}
}

void Game::updateGame()
{
	AFigure				*enemy;
	AFigure				*fig;
	std::stringstream	buff;
	int					xStep;
	int					yStep;

//	for (int i = 0; i < _crntMove.length(); ++i)
//		_crntMove[i] = ::tolower(_crntMove[i]);
	int crdMove[4] = {
			_crntMove[0] - 97,
			_crntMove[1] - 49 ,
			_crntMove[3] - 97,
			_crntMove[4] - 49
	};
//	int	xFrom = _crntMove[0] - 97;
//	int yFrom = _crntMove[1];
//	int	xTo = _crntMove[3] - 97;
//	int yTo = _crntMove[4];
	if (_crntMove[2] != ' ')
	{
		_errMsg = "Coordinates FROM and TO must be divided by space. Example: -m a4 b5";
		return;
	}
	if (crdMove[0] == crdMove[2] && crdMove[1] == crdMove[3])
	{
		_errMsg = "Coordinates FROM and TO must be various";
		return;
	}
	for (int j : crdMove) {
		if (j < 0 || j > 7)
		{
			_errMsg = "Bad coordinates: " + _crntMove;
			return;
		}
	}
	if (!(fig = getFig(crdMove[0], crdMove[1])))
	{
		_errMsg = "No figure on ceil: " + std::string(_crntMove, 0, 2);
		return;
	}
	if (fig->getLabel()[0] != _pl[_plIndx]->getSide()[0])
	{
		_errMsg = "You can not move your opponent's figures.";
		return;
	}
	if (!fig->validMove(crdMove[2], crdMove[3]))
	{
		_errMsg = "No valid move for " + fig->getLabel();
		return;
	}
	// check pass
	if (fig->getLabel()[1] != 'N')
	{
		xStep = figStep(crdMove[0], crdMove[2]);
		yStep = figStep(crdMove[1], crdMove[3]);
//		for (int y = crdMove[1]; y < crdMove[3]; y += yStep) {
		for (int x = crdMove[0] + xStep, y = crdMove[1] + yStep; x < crdMove[2] && y < crdMove[3]; x += xStep,  y += yStep) {
			if (getFig(x, y))
			{
				_errMsg = "Impossible move. On cell " + std::string(1, x + 97)
						+ std::string(1, y + 49) + " there is another figure.";
				return;
			}
		}
//		}
	}
//	if (!(enemy = getFig(crdMove[2], crdMove[3])))
//	{
//		moveFig(crdMove[0], crdMove[1], crdMove[2], crdMove[3]);
////		_lastMove = std::string(1, crdMove[0] + 49) + std::string(1, crdMove[0] + 49) + std::string(1, crdMove[0] + 49) + std::string(1, crdMove[0] + 49);
//		buff << crdMove[0] + 48 << crdMove[1] + 48 << " " << crdMove[2] + 48 << crdMove[3] + 48;
//	}
	enemy = getFig(crdMove[2], crdMove[3]);
	if (enemy && enemy->getLabel()[0] == fig->getLabel()[0])
	{
		_errMsg = "Impossible move. You can`t kick your own figure.";
		return;
	}
	else if (enemy && enemy->getLabel()[0] != fig->getLabel()[0])
	{
		enemy->setActive(false);
		if (enemy->getLabel()[1] == 'K')
		{
			_win = "Checkmate for ";
			_win += enemy->getLabel()[0] == 'B'? "Black" : "White";
			_win += " side";
		}
	}
	moveFig(crdMove[0], crdMove[1], crdMove[2], crdMove[3]);
	if ((fig->getLabel() == "WP" && crdMove[3] == 7) || (fig->getLabel() == "BP" && crdMove[3] == 0))
		promotion(fig);
	buff << (char)(crdMove[0] + 97) << crdMove[1] + 1 << " " << (char)(crdMove[2] + 97) << crdMove[3] + 1;
	std::getline(buff, _lastMove);
	_plIndx = (_plIndx + 1) % 2;
}

int Game::figStep(int from, int to)
{
	if (to == from)
		return 0;
	if (to < from)
		return -1;
	return 1;
}

void Game::moveFig(int xFrom, int yFrom, int xTo, int yTo)
{
	AFigure	*fig = getFig(xFrom, yFrom);
	fig->move(xTo, yTo);
	setFig(fig, xTo, yTo);
	setFig(nullptr, xFrom, yFrom);
}

void Game::promotion(AFigure *fig)
{
	std::string	inpt;
	AFigure		*newFig;
	std::cout << std::setw(5) << "Q" << "\tpromotion pawn to queen;" << std::endl;
	std::cout << std::setw(5) << "N" << "\tpromotion pawn to knight;" << std::endl;
	std::cout << std::setw(5) << "R" << "\tpromotion pawn to rook;" << std::endl;
	std::cout << std::setw(5) << "B" << "\tpromotion pawn to bishop." << std::endl;
choose:
	std::cout << "Promotion! Choose new figure:" << std::endl;
	std::getline(std::cin, inpt);
	inpt[0] = ::toupper(inpt[0]);
	if (inpt == "Q" || inpt == "N" || inpt == "R" || inpt == "B")
	{
		newFig = _pl[_plIndx]->addNewFig(fig->getLabel()[0] + inpt, fig->getPosX(), fig->getPosY());
		setFig(newFig, fig->getPosX(), fig->getPosY());
		fig->setActive(false);
	}
	else
	{
		std::cout << "Bad input. Try again." << std::endl;
		goto choose;
	}
}
