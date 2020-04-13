#include "../inc/KingTest.hpp"
#include "../../inc/Game.hpp"

KingTest::KingTest() : _testKO(0), _testOK(0)
{
	_king = new King("none", 0, 0);
}

void KingTest::testValidMove()
{
	int	testOK = 0, testKO = 0;
	int posX = 4, posY = 4;
	int res[] = {0, 0, 0, 0, 0,
				 0, 1, 1, 1, 0,
				 0, 1,    1, 0,
				 0, 1, 1, 1, 0,
				 0, 0, 0, 0, 0};
	_king->setPosX(posX);
	_king->setPosY(posY);
	_king->setLabel("WK");
	_king->setStartCastling(0b000);
	for (int yInp = 2, i = 0; yInp <= 6; ++yInp) {
		for (int xInp = 2; xInp <= 6; ++xInp) {
			if (yInp != 4 || xInp != 4)
			{
				if (res[i++] == _king->validMove(xInp, yInp))
					testOK++;
				else
				{
					testKO++;
					std::cout << testKO << ". testValidMove (basic move) - KO: from - " << (char)(posX + 97) << posY + 1
							  << " to - " << (char)(xInp + 97) << yInp + 1 << std::endl;
				}
			}
		}
	}

	std::cout << "TestValidMove: OK - " << testOK << ", KO - " << testKO << std::endl;
	_testKO += testKO;
	_testOK += testOK;
}

void KingTest::testValidMoveCastling()
{
	int	testOK = 0, testKO = 0;
	int posX = 4, posY = 0;
	_king->setPosX(posX);
	_king->setPosY(posY);
	_king->setLabel("WK");
	Rook		r1("WR", 0, 0);
	Rook		r2("WR", 7, 0);
	unsigned int castling = 0b111;
	Game::getInstance()->cleanBoard();
	int res[] = {0, 0, 1, 1,    1, 1, 0,
				 0, 0, 0, 1, 1, 1, 0, 0};
	Game::getInstance()->setFig(&r1, 0, 0);
	Game::getInstance()->setFig(&r2, 7, 0);
	for (int yInp = 0, i = 0; yInp <= 1; ++yInp) {
		for (int xInp = 0; xInp <= 7; ++xInp) {
			_king->setStartCastling(castling);
			if (yInp != 0 || xInp != 4)
			{
				if (res[i++] == _king->validMove(xInp, yInp))
					testOK++;
				else
				{
					testKO++;
					std::cout << testKO << ". testValidMove (castling) - KO: from - " << (char)(posX + 97) << posY + 1
							  << " to - " << (char)(xInp + 97) << yInp + 1
							  << " castling - "<< std::bitset<4>(castling) << std::endl;
				}
			}
		}
	}
	castling = 0b011;
	res[2] = 0;
	for (int yInp = 0, i = 0; yInp <= 1; ++yInp) {
		for (int xInp = 0; xInp <= 7; ++xInp) {
			_king->setStartCastling(castling);
			if (yInp != 0 || xInp != 4)
			{
				if (res[i++] == _king->validMove(xInp, yInp))
					testOK++;
				else
				{
					testKO++;
					std::cout << testKO << ". testValidMove (castling) - KO: from - " << (char)(posX + 97) << posY + 1
							  << " to - " << (char)(xInp + 97) << yInp + 1
							  << " castling - "<< std::bitset<4>(castling) << std::endl;
				}
			}
		}
	}
	castling = 0b110;
	res[5] = 0;
	for (int yInp = 0, i = 0; yInp <= 1; ++yInp) {
		for (int xInp = 0; xInp <= 7; ++xInp) {
			_king->setStartCastling(castling);
			if (yInp != 0 || xInp != 4)
			{
				if (res[i++] == _king->validMove(xInp, yInp))
					testOK++;
				else
				{
					testKO++;
					std::cout << testKO << ". testValidMove (castling) - KO: from - " << (char)(posX + 97) << posY + 1
							  << " to - " << (char)(xInp + 97) << yInp + 1
							  << " castling - "<< std::bitset<4>(castling) << std::endl;
				}
			}
		}
	}
	std::cout << "TestValidMoveCastling: OK - " << testOK << ", KO - " << testKO << std::endl;
	_testKO += testKO;
	_testOK += testOK;
}

void KingTest::testCheck()
{
	int	testOK = 0, testKO = 0;
	int posX = 2, posY = 2;
	_king->setPosX(posX);
	_king->setPosY(posY);
	_king->setLabel("BK");
	_king->setStartCastling(0b000);
	Rook		r1("WR", 1, 4);
	Rook		r2("WR", 3, 1);
	Rook		r3("BR", 1, 5);
	Bishop		b("WB", 7, 2);
	Pawn		p("WP", 5, 1);
	Game::getInstance()->cleanBoard();
	Game::getInstance()->setFig(&r1, 1, 4);
	Game::getInstance()->setFig(&r2, 3, 1);
	Game::getInstance()->setFig(&r3, 1, 5);
	Game::getInstance()->setFig(&b, 7, 2);
	Game::getInstance()->setFig(&p, 5, 1);
	Game::getInstance()->setFig(_king, 2, 2);
	int res[] = {0, 1, 1, 0, 1,
				 0, 1, 0, 0, 1,
				 1, 1, 1, 1, 1,
				 0, 1, 1, 0, 0,
				 0, 1, 0, 0, 0};
	for (int yInp = 2, i = 0; yInp <= 6; ++yInp) {
		for (int xInp = 2; xInp <= 6; ++xInp) {
			Game::getInstance()->moveFig(_king->getPosX(), _king->getPosY(), xInp, yInp);
//			_king->setPosX(xInp);
//			_king->setPosY(yInp);
			if (res[i++] == Game::getInstance()->check(_king))
				testOK++;
			else
			{
				testKO++;
				std::cout << testKO << ". testCheck - KO: position - " << (char)(xInp + 97) << yInp + 1 << std::endl;
			}
		}
	}
	std::cout << "TestCheck: OK - " << testOK << ", KO - " << testKO << std::endl;
	_testKO += testKO;
	_testOK += testOK;
}

int KingTest::getTestOk() const
{
	return _testOK;
}

int KingTest::getTestKo() const
{
	return _testKO;
}

KingTest::~KingTest()
{
	delete _king;
}

