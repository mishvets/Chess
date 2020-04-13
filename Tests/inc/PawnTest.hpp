#ifndef CHESS_PAWNTEST_HPP
#define CHESS_PAWNTEST_HPP

#include "../../inc/Pawn.hpp"
#include <iostream>

class PawnTest
{
public:
	PawnTest();
	~PawnTest();
	void testValidMove();

	int getTestOk() const;
	int getTestKo() const;

private:
	Pawn	*_pawn;
	int		_testOK;
	int		_testKO;

};

#endif //CHESS_PAWNTEST_HPP
