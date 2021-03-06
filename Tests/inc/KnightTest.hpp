#ifndef CHESS_KNIGHTTEST_HPP
#define CHESS_KNIGHTTEST_HPP

#include <iostream>
#include "../../inc/Knight.hpp"

class KnightTest
{
public:
	KnightTest();
	~KnightTest();
	void testValidMove();

	int getTestOk() const;
	int getTestKo() const;

private:
	Knight	*_knight;
	int		_testKO;
	int		_testOK;

};


#endif //CHESS_KNIGHTTEST_HPP
