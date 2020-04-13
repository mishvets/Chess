#include <iostream>
#include "../inc/QueenTest.hpp"
#include "../inc/PawnTest.hpp"
#include "../inc/RookTest.hpp"
#include "../inc/BishopTest.hpp"
#include "../inc/KnightTest.hpp"
#include "../inc/KingTest.hpp"
#include "../../inc/Game.hpp"

int main ()
{
	Game::getInstance();
	QueenTest	queenTest;
	PawnTest	pawnTest;
	RookTest	rookTest;
	BishopTest	bishopTest;
	KnightTest	knightTest;
	KingTest	kingTest;

	std::cout << "QueenTest" << std::endl;
	queenTest.testValidMove();
	std::cout << "PawnTest" << std::endl;
	pawnTest.testValidMove();
	std::cout << "RookTest" << std::endl;
	rookTest.testValidMove();
	std::cout << "BishopTest" << std::endl;
	bishopTest.testValidMove();
	std::cout << "KnightTest" << std::endl;
	knightTest.testValidMove();
	std::cout << "KingTest" << std::endl;
	kingTest.testValidMove();
	kingTest.testValidMoveCastling();

	delete Game::getInstance();
	return 0;
}