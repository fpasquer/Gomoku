/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FreeThree.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpasquer <fpasquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 13:23:16 by fpasquer          #+#    #+#             */
/*   Updated: 2018/02/27 15:32:24 by fpasquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/FreeThree.hpp"

FreeThree::t_checkFreet const
							FreeThree::m_func[] = {

	{&FreeThree::checkFTLeft},
	{&FreeThree::checkFTTopLeft},
	{&FreeThree::checkFTTop},
	{&FreeThree::checkFTTopRight},
	{&FreeThree::checkFTRight},
	{&FreeThree::checkFTBottomRight},
	{&FreeThree::checkFTBottom},
	{&FreeThree::checkFTBottomLeft},
	{NULL}
};

							FreeThree::FreeThree(Grid const &grid) : m_grid(grid)
{
	
}

bool						FreeThree::checkFTLeft(unsigned const int y_tmp, unsigned const int x_tmp, short const val) const
{
	short					c;
	unsigned int			y;
	unsigned int			x;
	unsigned int			count;

	y = y_tmp;
	x = x_tmp - 2;
	if (m_grid.getValue(c, x, y) == false || GET_VAL(c) != GET_VAL(val))
		return (false);
	count = 0;
	if (m_grid.countLeft(y_tmp, x_tmp, val, count) == true && count >= 2)
		return(!(this->checkFTRight(y_tmp, x_tmp, val)));
	if (m_grid.getValue(c, x + 1, y) == true && GET_VAL(c) == EMPTY_CELL &&
			m_grid.countLeft(y, x, val, count) == true && count >= 1)
		return(!(this->checkFTRight(y_tmp, x_tmp, val)));
	return (false);
}

bool						FreeThree::checkFTTopLeft(unsigned const int y_tmp, unsigned const int x_tmp, short const val) const
{
	short					c;
	unsigned int			y;
	unsigned int			x;
	unsigned int			count;

	y = y_tmp - 2;
	x = x_tmp - 2;
	if (m_grid.getValue(c, x, y) == false || GET_VAL(c) != GET_VAL(val))
		return (false);
	count = 0;
	if (m_grid.countLeftTop(y_tmp, x_tmp, val, count) == true && count >= 2)
		return (!(this->checkFTBottomRight(y_tmp, x_tmp, val)));
	if (m_grid.getValue(c, x + 1, y + 1) == true && GET_VAL(c) == EMPTY_CELL &&
			m_grid.countLeftTop(y, x, val, count) == true && count >= 1)
		return (!(this->checkFTBottomRight(y_tmp, x_tmp, val)));
	return (false);
}

bool						FreeThree::checkFTTop(unsigned const int y_tmp, unsigned const int x_tmp, short const val) const
{
	short					c;
	unsigned int			y;
	unsigned int			x;
	unsigned int			count;

	y = y_tmp - 2;
	x = x_tmp;
	if (m_grid.getValue(c, x, y) == false || GET_VAL(c) != GET_VAL(val))
		return (false);
	count = 0;
	if (m_grid.countTop(y_tmp, x_tmp, val, count) == true && count >= 2)
		return (!(this->checkFTBottom(y_tmp, x_tmp, val)));
	if (m_grid.getValue(c, x, y + 1) == true && GET_VAL(c) == EMPTY_CELL &&
			m_grid.countTop(y, x, val, count) == true && count >= 1)
		return (!(this->checkFTBottom(y_tmp, x_tmp, val)));
	return (false);
}

bool						FreeThree::checkFTTopRight(unsigned const int y_tmp, unsigned const int x_tmp, short const val) const
{
	short					c;
	unsigned int			y;
	unsigned int			x;
	unsigned int			count;

	y = y_tmp - 2;
	x = x_tmp + 2;
	if (m_grid.getValue(c, x, y) == false || GET_VAL(c) != GET_VAL(val))
		return (false);
	count = 0;
	if (m_grid.countTopRight(y_tmp, x_tmp, val, count) == true && count >= 2)
		return (true);
	if (m_grid.getValue(c, x - 1, y + 1) == true && GET_VAL(c) == EMPTY_CELL &&
			m_grid.countTopRight(y, x, val, count) ==true && count >= 1)
		return (true);
	return (false);
}

bool						FreeThree::checkFTRight(unsigned const int y_tmp, unsigned const int x_tmp, short const val) const
{
	short					c;
	unsigned int			y;
	unsigned int			x;
	unsigned int			count;

	y = y_tmp;
	x = x_tmp + 2;
	if (m_grid.getValue(c, x, y) == false || GET_VAL(c) != GET_VAL(val))
		return (false);
	count = 0;
	if (m_grid.countRight(y_tmp, x_tmp, val, count) == true && count >= 2)
		return (true);
	if (m_grid.getValue(c, x - 1, y) == true && GET_VAL(c) == EMPTY_CELL &&
			m_grid.countRight(y, x, val, count) == true && count >= 1)
		return (true);
	return (false);
}

bool						FreeThree::checkFTBottomRight(unsigned const int y_tmp, unsigned const int x_tmp, short const val) const
{
	short					c;
	unsigned int			y;
	unsigned int			x;
	unsigned int			count;

	y = y_tmp + 2;
	x = x_tmp + 2;
	if (m_grid.getValue(c, x, y) == false || GET_VAL(c) != GET_VAL(val))
		return (false);
	count = 0;
	if (m_grid.countRightBottom(y_tmp, x_tmp, val, count) == true && count >= 2)
		return (true);
	if (m_grid.getValue(c, x - 1, y - 1) == true && GET_VAL(c) == EMPTY_CELL &&
			m_grid.countRightBottom(y, x, val, count) == true && count >= 1)
		return (true);
	return (false);
}

bool						FreeThree::checkFTBottom(unsigned const int y_tmp, unsigned const int x_tmp, short const val) const
{
	short					c;
	unsigned int			y;
	unsigned int			x;
	unsigned int			count;

	y = y_tmp + 2;
	x = x_tmp;
	if (m_grid.getValue(c, x, y) == false || GET_VAL(c) != GET_VAL(val))
		return (false);
	count = 0;
	if (m_grid.countBottom(y_tmp, x_tmp, val, count) == true && count >= 2)
		return (true);
	if (m_grid.getValue(c, x, y - 1) == true && GET_VAL(c) == EMPTY_CELL &&
			m_grid.countBottom(y, x, val, count) == true && count >= 1)
		return (true);
	return (false);
}

bool						FreeThree::checkFTBottomLeft(unsigned const int y_tmp, unsigned const int x_tmp, short const val) const
{
	short					c;
	unsigned int			y;
	unsigned int			x;
	unsigned int			count;

	y = y_tmp + 2;
	x = x_tmp - 2;
	if (m_grid.getValue(c, x, y) == false || GET_VAL(c) != GET_VAL(val))
		return (false);
	count = 0;
	if (m_grid.countBottomLeft(y_tmp, x_tmp, val, count) == true && count >= 2)
		return (true);
	if (m_grid.getValue(c, x + 1, y - 1) == true && GET_VAL(c) == EMPTY_CELL &&
			m_grid.countBottomLeft(y, x, val, count) == true && count >= 1)
		return (true);
	return (false);
}



bool						FreeThree::checkFreeThree(unsigned int const y, unsigned int const x, short const val) const
{
	short					c;
	unsigned int			i;
	unsigned int			count;

	if (m_grid.getValue(c, x, y) == false || GET_VAL(c) != EMPTY_CELL)
		return (false);
	for (i = 0, count = 0; m_func[i].f != NULL; i++)
		if (((*this).*m_func[i].f)(y, x, val) == true)
			count++;
	return (count >= 2 ? true : false);
}

bool						FreeThree::updateFreeThree(unsigned int const y, unsigned int const x, short const val) const
{
	short					c;
	short					new_val;

	if (m_grid.getValue(c, x, y) == false || GET_VAL(c) != EMPTY_CELL || GET_PERM(c) == 0)
		return (false);
	new_val = SET_VAL(0, GET_VAL(val) == PLAYER1 ? PLAYER2 : PLAYER1);
	new_val = SET_PERM(new_val, (GET_PERM(val) == CAN_NOT_PLAY1) ? CAN_NOT_PLAY2 : CAN_NOT_PLAY1);
	if (((GET_PERM(c)) & (GET_PERM(new_val))) == 0)
		return (false);
	return (!(this->checkFreeThree(y, x, new_val)));
}