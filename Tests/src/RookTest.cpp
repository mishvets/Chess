#include "../inc/RookTest.hpp"

RookTest::RookTest() : _testKO(0), _testOK(0)
{
	_rook = new Rook("none", 0, 0);
}

void RookTest::testValidMove()
{
	int	testOK = 0, testKO = 0;
	int posX = 4, posY = 4;
	int res[] = {0, 0, 1, 0, 0,
				 0, 0, 1, 0, 0,
				 1, 1,    1, 1,
				 0, 0, 1, 0, 0,
				 0, 0, 1, 0, 0};

	_rook->setPosX(posX);
	_rook->setPosY(posY);
	for (int yInp = 2, i = 0; yInp <= 6; ++yInp) {
		for (int xInp = 2; xInp <= 6; ++xInp) {
			if (yInp != 4 || xInp != 4)
			{
				if (res[i++] == _rook->validMove(xInp, yInp))
					testOK++;
				else
				{
					testKO++;
					std::cout << testKO << ". testValidMove - KO: from - " << (char)(posX + 97) << posY + 1
							  << " to - " << (char)(xInp + 97) << yInp + 1 << std::endl;
				}
			}
		}
	}
	std::cout << "TestValidMove: OK - " << testOK << ", KO - " << testKO << std::endl;
	_testKO += testKO;
	_testOK += testOK;
}

int RookTest::getTestOk() const
{
	return _testOK;
}

int RookTest::getTestKo() const
{
	return _testKO;
}

RookTest::~RookTest()
{
	delete _rook;
}

