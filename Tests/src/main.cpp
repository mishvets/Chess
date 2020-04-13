#include <iostream>
#include "../inc/QueenTest.hpp"
#include "../inc/PawnTest.hpp"
#include "../inc/RookTest.hpp"

int main ()
{
	QueenTest	queenTest;
	PawnTest	pawnTest;
	RookTest	rookTest;

	std::cout << "QueenTest" << std::endl;
	queenTest.testValidMove();
	std::cout << "PawnTest" << std::endl;
	pawnTest.testValidMove();
	std::cout << "RookTest" << std::endl;
	rookTest.testValidMove();
	return 0;
}