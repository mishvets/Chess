#ifndef CHESS_AFIGURE_HPP
#define CHESS_AFIGURE_HPP

#include <iostream>

class AFigure
{
public:
    AFigure(const std::string &label, int posX, int posY);
    AFigure(const AFigure &src);
    virtual ~AFigure() = default;
    AFigure &operator=(const AFigure &src);

    virtual bool validMove(int x, int y) = 0;
    virtual void		move(int x, int y) = 0;
	bool				isActive() const;

	void				setActive(bool active);
	void				setPosX(int posX);
	void				setPosY(int posY);

	const std::string	&getLabel() const;
	int					getPosX() const;
	int					getPosY() const;

protected:
	bool		_active;
	std::string	_label;
	int 		_posX;
	int 		_posY;
};


#endif //CHESS_AFIGURE_HPP
