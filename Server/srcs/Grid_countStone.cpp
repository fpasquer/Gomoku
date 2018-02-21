/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Grid_countStone.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpasquer <fpasquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 20:17:29 by fpasquer          #+#    #+#             */
/*   Updated: 2018/02/21 15:28:01 by amaindro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Grid.hpp"

bool						Grid::countLeft(unsigned int const y, unsigned int const x, short const val, unsigned int &count) const
{
	unsigned int			i;

	for (count = 0, i = 0; x - i - 1 < SIZE_GRID && GET_VAL(m_cell[y][x - i - 1]) == GET_VAL(val); i++)
		count ++;
	return (x - i - 1 < SIZE_GRID && GET_VAL(m_cell[y][x - i - 1]) == EMPTY_CELL ? true : false);
}

bool						Grid::countRight(unsigned int const y, unsigned int const x, short const val, unsigned int &count) const
{
	unsigned int			i;

	for (count = 0, i = 0; x + i + 1 < SIZE_GRID && GET_VAL(m_cell[y][x + i + 1]) == GET_VAL(val); i++)
		count ++;
	return (x + i + 1 < SIZE_GRID && GET_VAL(m_cell[y][x + i + 1]) == EMPTY_CELL ? true : false);
}

bool						Grid::countTop(unsigned int const y, unsigned int const x, short const val, unsigned int &count) const
{
	unsigned int			i;

	for (count = 0, i = 0; y - i - 1 < SIZE_GRID && m_cell[y - i - 1][x] == GET_VAL(val); i++)
		count ++;
	return (y - i - 1 < SIZE_GRID && GET_VAL(m_cell[y - i - 1][x]) == EMPTY_CELL ? true : false);
}

bool						Grid::countBottom(unsigned int const y, unsigned int const x, short const val, unsigned int &count) const
{
	unsigned int			i;

	for (count = 0, i = 0; y + i + 1 < SIZE_GRID && GET_VAL(m_cell[y + i + 1][x]) == GET_VAL(val); i++)
		count ++;
	return (y + i + 1 < SIZE_GRID && GET_VAL(m_cell[y + i + 1][x]) == EMPTY_CELL ? true : false);
}

bool						Grid::countLeftTop(unsigned int const y, unsigned int const x, short const val, unsigned int &count) const
{
	unsigned int			i;

	for (count = 0, i = 0; y - i - 1 < SIZE_GRID && x - i - 1 < SIZE_GRID && GET_VAL(m_cell[y - i - 1][x - i - 1]) == GET_VAL(val); i++)
		count ++;
	return (y - i - 1 < SIZE_GRID && x - i - 1 < SIZE_GRID && GET_VAL(m_cell[y - i - 1][x - i - 1]) == EMPTY_CELL ? true : false);
}

bool						Grid::countRightBottom(unsigned int const y, unsigned int const x, short const val, unsigned int &count) const
{
	unsigned int			i;

	for (count = 0, i = 0; y + i + 1 < SIZE_GRID && x + i + 1 < SIZE_GRID && GET_VAL(m_cell[y + i + 1][x + i + 1]) == GET_VAL(val); i++)
		count ++;
	return (y + i + 1 < SIZE_GRID && x + i + 1 < SIZE_GRID && GET_VAL(m_cell[y + i + 1][x + i + 1]) == EMPTY_CELL ? true : false);
}

bool						Grid::countTopRight(unsigned int const y, unsigned int const x, short const val, unsigned int &count) const
{
	unsigned int			i;

	for (count = 0, i = 0; y - i - 1 < SIZE_GRID && x + i + 1 < SIZE_GRID && GET_VAL(m_cell[y - i - 1][x + i + 1]) == GET_VAL(val); i++)
		count ++;
	return (y - i - 1 < SIZE_GRID && x + i + 1 < SIZE_GRID && GET_VAL(m_cell[y - i - 1][x + i + 1]) == EMPTY_CELL ? true : false);
}

bool						Grid::countBottomLeft(unsigned int const y, unsigned int const x, short const val, unsigned int &count) const
{
	unsigned int			i;

	for (count = 0, i = 0; y + i + 1 < SIZE_GRID && x - i - 1 < SIZE_GRID && GET_VAL(m_cell[y + i + 1][x - i - 1]) == GET_VAL(val); i++)
		count ++;
	return (y + i + 1 < SIZE_GRID && x - i - 1 < SIZE_GRID && GET_VAL(m_cell[y + i + 1][x - i - 1]) == EMPTY_CELL ? true : false);
}

bool						Grid::getLineNbStone(unsigned int const y, unsigned int const x, short const val, unsigned int &count) const
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
	return true if the next stone after the higer and the lower of the stone's player is empty, else false
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
