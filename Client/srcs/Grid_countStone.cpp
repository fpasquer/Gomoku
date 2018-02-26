/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Grid_countStone.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpasquer <fpasquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 20:17:29 by fpasquer          #+#    #+#             */
/*   Updated: 2018/02/26 12:33:09 by fpasquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Grid.hpp"

bool						Grid::countLeft(unsigned int const y, unsigned int const x, short const val, unsigned int &count) const
{
	return (CountWin::countLeft(m_cell, y, x, val, count));
}

bool						Grid::countRight(unsigned int const y, unsigned int const x, short const val, unsigned int &count) const
{
	return (CountWin::countRight(m_cell, y, x, val, count));
}

bool						Grid::countTop(unsigned int const y, unsigned int const x, short const val, unsigned int &count) const
{
	return (CountWin::countTop(m_cell, y, x, val, count));
}

bool						Grid::countBottom(unsigned int const y, unsigned int const x, short const val, unsigned int &count) const
{
	return (CountWin::countBottom(m_cell, y, x, val, count));
}

bool						Grid::countLeftTop(unsigned int const y, unsigned int const x, short const val, unsigned int &count) const
{
	return (CountWin::countLeftTop(m_cell, y, x, val, count));
}

bool						Grid::countRightBottom(unsigned int const y, unsigned int const x, short const val, unsigned int &count) const
{
	return (CountWin::countRightBottom(m_cell, y, x, val, count));
}

bool						Grid::countTopRight(unsigned int const y, unsigned int const x, short const val, unsigned int &count) const
{
	return (CountWin::countTopRight(m_cell, y, x, val, count));
}

bool						Grid::countBottomLeft(unsigned int const y, unsigned int const x, short const val, unsigned int &count) const
{
	return (CountWin::countBottomLeft(m_cell, y, x, val, count));
}

bool						Grid::getLineNbStone(unsigned int const y, unsigned int const x, short const val, unsigned int &count) const
/*
DESCRIPTION:
	count the number of stone aline of the player on the line
RETURN VALUES:
	return true if the next stone after on left and on right are empty, else false
*/
{
	bool					left_end;
	bool					right_end;
	unsigned int			count_left = 0;
	unsigned int			count_right = 0;

	left_end = this->countLeft(y, x, val, count_left);
	right_end = this->countRight(y, x, val, count_right);
	count = count_left + count_right + 1;
	return (left_end == true && right_end == true ? true : false);
}

bool						Grid::getColNbStone(unsigned int const y, unsigned int const x, short const val, unsigned int &count) const
/*
DESCRIPTION:
	count the number of stone aline of the player on the collumn
RETURN VALUES:
	return true if the next stone after the higher and the lower are empty, else false
*/
{
	bool					above_end;
	bool					below_end;
	unsigned int			count_above = 0;
	unsigned int			count_below = 0;

	above_end = this->countTop(y, x, val, count_above);
	below_end = this->countBottom(y, x, val, count_below);
	count = count_above + count_below + 1;
	return (above_end == true && below_end == true ? true : false);
}

bool						Grid::getDiagLeftTopRightBottomNbStone(unsigned int const y, unsigned int const x, short const val, unsigned int &count) const
{
	bool					left_end;
	bool					right_end;
	unsigned int			count_left = 0;
	unsigned int			count_right = 0;

	left_end = this->countLeftTop(y, x, val, count_left);
	right_end = this->countRightBottom(y, x, val, count_right);
	count = count_right + count_left + 1;
	return (left_end == true && right_end == true ? true : false);
}

bool						Grid::getDiagRightTopLeftBottomNbStone(unsigned int const y, unsigned int const x, short const val, unsigned int &count) const
{
	bool					left_end;
	bool					right_end;
	unsigned int			count_left = 0;
	unsigned int			count_right = 0;

	left_end = this->countBottomLeft(y, x, val, count_left);
	right_end = this->countTopRight(y, x, val, count_right);
	count = count_left + count_right + 1;
	return (left_end == true && right_end == true ? true : false);
}