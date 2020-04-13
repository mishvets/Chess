#include "../inc/KnightTest.hpp"

KnightTest::KnightTest() : _testKO(0), _testOK(0)
{
	_knight = new Knight("none", 0, 0);
}

void KnightTest::testValidMove()
{
	int	testOK = 0, testKO = 0;
	int posX = 4, posY = 4;
	int res[] = {0, 1, 0, 1, 0,
				 1, 0, 0, 0, 1,
				 0, 0,    0, 0,
				 1, 0, 0, 0, 1,
				 0, 1, 0, 1, 0};

	_knight->setPosX(posX);
	_knight->setPosY(posY);
	for (int yInp = 2, i = 0; yInp <= 6; ++yInp) {
		for (int xInp = 2; xInp <= 6; ++xInp) {
			if (yInp != 4 || xInp != 4)
			{
				if (res[i++] == _knight->validMove(xInp, yInp))
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
	std::cout << std::endl;
	_testKO += testKO;
	_testOK += testOK;
}

int KnightTest::getTestOk() const
{
	return _testOK;
}

int KnightTest::getTestKo() const
{
	return _testKO;
}

KnightTest::~KnightTest()
{
	delete _knight;
}

