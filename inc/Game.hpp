#ifndef CHESS_GAME_HPP
#define CHESS_GAME_HPP

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <fstream>
#include "AFigure.hpp"
#include "Player.hpp"
#include "King.hpp"
#include "Bishop.hpp"
#include "Knight.hpp"
#include "Rook.hpp"
#include "Queen.hpp"
#include "Pawn.hpp"

class Game
{
public:
	static const int _xSizeBoard = 8;
	static const int _ySizeBoard = 8;

	~Game();

//	save
	bool	loadGame();
	bool	readFile(std::ifstream &file);
	void 	printBoard();
	void 	printUsage();
	void 	userInput();
	void	startGame();
	void 	saveGame();

	void	setFig(AFigure *fig, int posX, int posY);

	static Game			*getInstance();
	AFigure				*getFig(int posX, int posY) const;
	const std::string	&getLastMove() const;

private:
	static Game	*_instance;
	Player		*_pl[2];
	AFigure		*_board[_ySizeBoard][_xSizeBoard];
//	std::array<Player *, 2>	_pl;
//	std::array<AFigure *, _ySizeBoard, _xSizeBoard>	_board[_ySizeBoard][_xSizeBoard];
	std::string _lastMove;
	std::string _crntMove;

	Game();
};


#endif //CHESS_GAME_HPP
