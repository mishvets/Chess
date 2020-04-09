#include "../inc/AFigure.hpp"

AFigure::AFigure(const std::string &label, int posX, int posY) : _active(true), _label(label), _posX(posX), _posY(posY)
{
	std::cout << "* AFigure default constructor *" << std::endl;
}

AFigure::AFigure(const AFigure &src)
{
	std::cout << "* AFigure default copy constructor *" << std::endl;
	*this = src;
}

AFigure::~AFigure()
{
	std::cout << "* AFigure default destructor *" << std::endl;
}

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

