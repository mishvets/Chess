#include "../inc/AFigure.hpp"

AFigure::AFigure(const std::string &label, int posX, int posY) : _active(true), _label(label), _posX(posX), _posY(posY)
{
//	std::cout << "* AFigure constructor *" << std::endl;
}

AFigure::AFigure(const AFigure &src)
{
	std::cout << "* AFigure default copy constructor *" << std::endl;
	*this = src;
}

//AFigure::~AFigure()
//{
//	std::cout << "* AFigure default destructor *" << std::endl;
//}

AFigure &AFigure::operator=(const AFigure &src)
{
	if (this != &src)
	{
		_active = src._active;
		_posX = src._posX;
		_posY = src._posY;
		_label = src._label;
	}
	return *this;
}

bool AFigure::isActive() const
{
	return _active;
}

void AFigure::setActive(bool active)
{
	_active = active;
}

const std::string &AFigure::getLabel() const
{
	return _label;
}

int AFigure::getPosX() const
{
	return _posX;
}

void AFigure::setPosX(int posX)
{
	_posX = posX;
}

int AFigure::getPosY() const
{
	return _posY;
}

void AFigure::setPosY(int posY)
{
	_posY = posY;
}

void AFigure::setLabel(const std::string &label)
{
	_label = label;
}

