#include "../inc/PawnTest.hpp"
#include "../../inc/Game.hpp"

PawnTest::PawnTest() : _testKO(0), _testOK(0)
{
	_pawn = new Pawn("none", 0, 0);
}

void PawnTest::testValidMove()
{
	Pawn		p1("WP", 5, 5);
	Pawn		p2("WP", 4, 5);
	Pawn		p3("BP", 3, 5);
	AFigure		*fig;
	std::string	str;
	int	testOK = 0, testKO = 0;
	int posX = 4, posY = 6;
	_pawn->move(posX, posY);
	_pawn->setLabel("BP");
	Game::getInstance()->cleanBoard();
	int res[] = {0, 0, 1, 0, 0,
				 0, 0, 1, 0, 0,
				 0, 0,    0, 0,
				 0, 0, 0, 0, 0};

	for (int yInp = 4, i = 0; yInp <= 7; ++yInp) {
		for (int xInp = 2; xInp <= 6; ++xInp) {
			if (yInp != 6 || xInp != 4)
			{
				if (res[i++] == _pawn->validMove(xInp, yInp))
					testOK++;
				else
				{
					testKO++;
					std::cout << testKO << ". testValidMove(typical move) - KO: from - " << (char)(posX + 97) << posY + 1
										<< " to - " << (char)(xInp + 97) << yInp + 1 << " label - " << _pawn->getLabel()
										<< std::endl;
				}
			}
		}
	}
	res[2] = 0;
	res[6] = 1;
	res[7] = 0;
	Game::getInstance()->setFig(&p1, 3, 5);
	Game::getInstance()->setFig(&p2, 4, 4);
	Game::getInstance()->setFig(&p3, 5, 5);
	for (int yInp = 4, i = 0; yInp <= 7; ++yInp) {
		for (int xInp = 2; xInp <= 6; ++xInp) {
			if (yInp != 5 || xInp != 4)
			{
				if (res[i++] == _pawn->validMove(xInp, yInp))
					testOK++;
				else
				{
					testKO++;
					fig = Game::getInstance()->getFig(xInp, yInp);
					str = fig ? fig->getLabel() : "none";
					std::cout << testKO << ". testValidMove(kick move) - KO: from - " << (char)(posX + 97) << posY + 1
										<< " to - " << (char)(xInp + 97) << yInp + 1 << " label - " << _pawn->getLabel()
										<< " enemy - " << str << std::endl;
				}
			}
		}
	}
	res[6] = 0;
	res[8] = 0;
	res[7] = 0;
	res[16] = 1;
	_pawn->setLabel("WP");
	for (int yInp = 4, i = 0; yInp <= 7; ++yInp) {
		for (int xInp = 2; xInp <= 6; ++xInp) {
			if (yInp != 5 || xInp != 4) {
				if (res[i++] == _pawn->validMove(xInp, yInp))
					testOK++;
				else {
					testKO++;
					fig = Game::getInstance()->getFig(xInp, yInp);
					str = fig ? fig->getLabel() : "none";
					std::cout << testKO << ". testValidMove(kick move) - KO: from - " << (char) (posX + 97) << posY + 1
							  << " to - " << (char) (xInp + 97) << yInp + 1 << " label - " << _pawn->getLabel()
							  << " enemy - " << str << std::endl;
				}
			}
		}
	}
	std::cout << "TestValidMove: OK - " << testOK << ", KO - " << testKO << std::endl;
	_testKO += testKO;
	_testOK += testOK;
}

void PawnTest::testEnPassant()
{
	Pawn		p1("BP", 2, 4);
	Pawn		p2("BP", 2, 3);
	Pawn		p3("BP", 3, 4);
	AFigure		*fig;
	std::string	str;
	int	testOK = 0, testKO = 0;
	int posX = 3, posY = 4;
	_pawn->move(posX, posY);
	_pawn->setLabel("WP");
	Game::getInstance()->cleanBoard();
	Game::getInstance()->setLastMove("c7 c5");
	Game::getInstance()->setFig(&p1, 2, 4);
	Game::getInstance()->setFig(&p3, 3, 4);
	int res[] = {1, 0, 0};
	for (int xInp = 2, i = 0; xInp <= 4; ++xInp) {
		if (res[i++] == _pawn->enPassant(xInp))
			testOK++;
		else
		{
			testKO++;
			fig = Game::getInstance()->getFig(xInp, posY + 1);
			str = fig ? fig->getLabel() : "none";
			std::cout << testKO << ". testEnPassant - KO: from - " << (char)(posX + 97) << posY + 1
					  << " to - " << (char)(xInp + 97) << posY + 2 << " label - " << _pawn->getLabel()
					  << " enemy - " << str << std::endl;
		}
	}
	_pawn->setLabel("BP");
	Game::getInstance()->setFig(&p1, 2, 4);
	res[0] = 0;
	for (int xInp = 2, i = 0; xInp <= 4; ++xInp) {
		if (res[i++] == _pawn->enPassant(xInp))
			testOK++;
		else
		{
			testKO++;
			fig = Game::getInstance()->getFig(xInp, posY + 1);
			str = fig ? fig->getLabel() : "none";
			std::cout << testKO << ". testEnPassant - KO: from - " << (char)(posX + 97) << posY + 1
					  << " to - " << (char)(xInp + 97) << posY + 2 << " label - " << _pawn->getLabel()
					  << " enemy - " << str << std::endl;
		}
	}
	std::cout << "TestEnPassant: OK - " << testOK << ", KO - " << testKO << std::endl;
	_testKO += testKO;
	_testOK += testOK;
}

int PawnTest::getTestOk() const
{
	return _testOK;
}

int PawnTest::getTestKo() const
{
	return _testKO;
}

PawnTest::~PawnTest()
{
	delete _pawn;
}




