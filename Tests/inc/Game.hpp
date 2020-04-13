#ifndef CHESS_GAME_HPP
#define CHESS_GAME_HPP

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <fstream>
//#include <bitset>
#include "AFigure.hpp"
#include "Player.hpp"

class Game
{
public:
	static const int _xSizeBoard = 8;
	static const int _ySizeBoard = 8;

	~Game();

	void	startGame();
	bool	loadGame();
	void	runGame();
	void 	saveGame();
	bool	userInput();
	void	updateGame();
	bool	readFile(std::ifstream &file);
	void 	printBoard();
	void 	printUsage();
	void	promotion(AFigure *fig);
	bool	check(AFigure *king);
	int 	figStep(int from, int to);
	void 	cleanBoard();

	void	setFig(AFigure *fig, int posX, int posY);
	void	moveFig(int xFrom, int yFrom, int xTo, int yTo);

	static Game			*getInstance();
	AFigure				*getFig(int posX, int posY) const;
	const std::string	&getLastMove() const;

private:
	static Game	*_instance;
	Player		*_pl[2];
	AFigure		*_board[_ySizeBoard][_xSizeBoard];
	std::string _lastMove;
	std::string _crntMove;
	std::string _errMsg;
	std::string _win;
	int 		_plIndx;

	Game();
};


#endif //CHESS_GAME_HPP
