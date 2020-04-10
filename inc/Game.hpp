#ifndef CHESS_GAME_HPP
#define CHESS_GAME_HPP

#include <iostream>
#include "AFigure.hpp"
#include "Player.hpp"

class Game
{
public:
	static const int _xSizeBoard = 8;
	static const int _ySizeBoard = 8;

	~Game();

//	save
//	load

	void				setFig(AFigure *fig, int posX, int posY);

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

	Game();
};


#endif //CHESS_GAME_HPP
