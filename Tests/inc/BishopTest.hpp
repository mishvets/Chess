#ifndef CHESS_BISHOPTEST_HPP
#define CHESS_BISHOPTEST_HPP

#include <iostream>
#include "../../inc/Bishop.hpp"

class BishopTest
{
public:
	BishopTest();
	~BishopTest();
	void testValidMove();

	int getTestOk() const;
	int getTestKo() const;

private:
	Bishop	*_bishop;
	int		_testKO;
	int		_testOK;

};

#endif //CHESS_BISHOPTEST_HPP
