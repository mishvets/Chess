#include "../inc/QueenTest.hpp"

QueenTest::QueenTest() : _testKO(0), _testOK(0)
{
	_queen = new Queen("none", 0, 0);
}

void QueenTest::testValidMove()
{
	int	testOK = 0, testKO = 0;
	int posX = 4, posY = 4;
	int res[] = {1, 0, 1, 0, 1,
			     0, 1, 1, 1, 0,
			     1, 1,    1, 1,
				 0, 1, 1, 1, 0,
				 1, 0, 1, 0, 1};

	_queen->setPosX(posX);
	_queen->setPosY(posY);
	for (int yInp = 2, i = 0; yInp <= 6; ++yInp) {
		for (int xInp = 2; xInp <= 6; ++xInp) {
			if (yInp != 4 || xInp != 4)
			{
				if (res[i++] == _queen->validMove(xInp, yInp))
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

int QueenTest::getTestOk() const
{
	return _testOK;
}

int QueenTest::getTestKo() const
{
	return _testKO;
}

QueenTest::~QueenTest()
{
	delete _queen;
}

