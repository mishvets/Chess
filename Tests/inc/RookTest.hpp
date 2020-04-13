#ifndef CHESS_ROOKTEST_HPP
#define CHESS_ROOKTEST_HPP

#include <iostream>
#include "../../inc/Rook.hpp"

class RookTest
{
public:
	RookTest();
	~RookTest();
	void testValidMove();

	int getTestOk() const;
	int getTestKo() const;

private:
	Rook	*_rook;
	int		_testOK;
	int		_testKO;

};


#endif //CHESS_ROOKTEST_HPP
