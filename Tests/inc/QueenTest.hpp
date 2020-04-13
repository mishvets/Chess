#ifndef CHESS_QUEENTEST_HPP
#define CHESS_QUEENTEST_HPP

#include <iostream>
#include "../../inc/Queen.hpp"

class QueenTest
{
public:
	QueenTest();
	~QueenTest();
	void testValidMove();

	int getTestOk() const;
	int getTestKo() const;

private:
	Queen	*_queen;
	int		_testOK;
	int		_testKO;

};


#endif //CHESS_QUEENTEST_HPP
