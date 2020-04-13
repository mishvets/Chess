#ifndef CHESS_KINGTEST_HPP
#define CHESS_KINGTEST_HPP

#include <iostream>
#include "../../inc/King.hpp"

class KingTest
{
public:
	KingTest();
	~KingTest();
	void testValidMove();

	int getTestOk() const;
	int getTestKo() const;

private:
	King	*_king;
	int		_testKO;
	int		_testOK;

};


#endif //CHESS_KINGTEST_HPP
