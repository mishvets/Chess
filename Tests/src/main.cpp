#include <iostream>
#include "../inc/QueenTest.hpp"
#include "../inc/PawnTest.hpp"

int main ()
{
	QueenTest	queenTest;
	PawnTest	pawnTest;

	std::cout << "QueenTest" << std::endl;
	queenTest.testValidMove();
	std::cout << "PawnTest" << std::endl;
	pawnTest.testValidMove();
	return 0;
}