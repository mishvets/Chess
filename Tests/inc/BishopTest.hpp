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
	int		_testOK;
	int		_testKO;

};

#endif //CHESS_BISHOPTEST_HPP
