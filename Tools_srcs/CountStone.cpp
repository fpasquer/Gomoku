/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CountStone.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpasquer <fpasquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 09:24:16 by fpasquer          #+#    #+#             */
/*   Updated: 2018/03/06 10:25:55 by fpasquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Tools_incs/CountStone.hpp"

							CountStone::CountStone(void) : Cell()
{

}

							CountStone::CountStone(short const cell[SIZE_GRID][SIZE_GRID]) : Cell(cell)
{

}

bool						CountStone::countLeft
		(unsigned int const y, unsigned int const x, short const val, unsigned int &count) const
/*
DESCRIPTION:
	count the number of stone on the left site with the value val
RETURN VALUES:
	return true if the next stone after the last on left is empty, else false
*/
{
	unsigned int			i;

	for (count = 0, i = 0; x - i - 1 < SIZE_GRID && GET_VAL(m_cell[y][x - i - 1]) == GET_VAL(val); i++)
		count ++;
	return (x - i - 1 < SIZE_GRID && GET_VAL(m_cell[y][x - i - 1]) == EMPTY_CELL ? true : false);
}

bool						CountStone::countRight
		(unsigned int const y, unsigned int const x, short const val, unsigned int &count) const
/*
DESCRIPTION:
	count the number of stone on the right site with the value val
RETURN VALUES:
	return true if the next stone after the last on right is empty, else false
*/
{
	unsigned int			i;

	for (count = 0, i = 0; x + i + 1 < SIZE_GRID && GET_VAL(m_cell[y][x + i + 1]) == GET_VAL(val); i++)
		count ++;
	return (x + i + 1 < SIZE_GRID && GET_VAL(m_cell[y][x + i + 1]) == EMPTY_CELL ? true : false);
}

bool						CountStone::countTop
		(unsigned int const y, unsigned int const x, short const val, unsigned int &count) const
/*
DESCRIPTION:
	count the number of stone on the top site with the value val
RETURN VALUES:
	return true if the next stone after higher is empty, else false
*/
{
	unsigned int			i;

	for (count = 0, i = 0; y - i - 1 < SIZE_GRID && m_cell[y - i - 1][x] == GET_VAL(val); i++)
		count ++;
	return (y - i - 1 < SIZE_GRID && GET_VAL(m_cell[y - i - 1][x]) == EMPTY_CELL ? true : false);
}

bool						CountStone::countBottom
		(unsigned int const y, unsigned int const x, short const val, unsigned int &count) const
/*
DESCRIPTION:
	count the number of stone on the bottom site with the value val
RETURN VALUES:
	return true if the next stone after lower is empty, else false
*/
{
	unsigned int			i;

	for (count = 0, i = 0; y + i + 1 < SIZE_GRID && GET_VAL(m_cell[y + i + 1][x]) == GET_VAL(val); i++)
		count ++;
	return (y + i + 1 < SIZE_GRID && GET_VAL(m_cell[y + i + 1][x]) == EMPTY_CELL ? true : false);
}

bool						CountStone::countLeftTop
		(unsigned int const y, unsigned int const x, short const val, unsigned int &count) const
/*
DESCRIPTION:
	count the number of stone on the left top site with the value val
RETURN VALUES:
	return true if the next stone after last one is empty, else false
*/
{
	unsigned int			i;

	for (count = 0, i = 0; y - i - 1 < SIZE_GRID && x - i - 1 < SIZE_GRID && GET_VAL(m_cell[y - i - 1][x - i - 1]) == GET_VAL(val); i++)
		count ++;
	return (y - i - 1 < SIZE_GRID && x - i - 1 < SIZE_GRID && GET_VAL(m_cell[y - i - 1][x - i - 1]) == EMPTY_CELL ? true : false);
}

bool						CountStone::countRightBottom
		(unsigned int const y, unsigned int const x, short const val, unsigned int &count) const
/*
DESCRIPTION:
	count the number of stone on the right bottom site with the value val
RETURN VALUES:
	return true if the next stone after last one is empty, else false
*/
{
	unsigned int			i;

	for (count = 0, i = 0; y + i + 1 < SIZE_GRID && x + i + 1 < SIZE_GRID && GET_VAL(m_cell[y + i + 1][x + i + 1]) == GET_VAL(val); i++)
		count ++;
	return (y + i + 1 < SIZE_GRID && x + i + 1 < SIZE_GRID && GET_VAL(m_cell[y + i + 1][x + i + 1]) == EMPTY_CELL ? true : false);
}

bool						CountStone::countTopRight
		(unsigned int const y, unsigned int const x, short const val, unsigned int &count) const
/*
DESCRIPTION:
	count the number of stone on the top right site with the value val
RETURN VALUES:
	return true if the next stone after last one is empty, else false
*/
{
	unsigned int			i;

	for (count = 0, i = 0; y - i - 1 < SIZE_GRID && x + i + 1 < SIZE_GRID && GET_VAL(m_cell[y - i - 1][x + i + 1]) == GET_VAL(val); i++)
		count ++;
	return (y - i - 1 < SIZE_GRID && x + i + 1 < SIZE_GRID && GET_VAL(m_cell[y - i - 1][x + i + 1]) == EMPTY_CELL ? true : false);
}

bool						CountStone::countBottomLeft
		(unsigned int const y, unsigned int const x, short const val, unsigned int &count) const
/*
DESCRIPTION:
	count the number of stone on the bottom left site with the value val
RETURN VALUES:
	return true if the next stone after last one is empty, else false
*/
{
	unsigned int			i;

	for (count = 0, i = 0; y + i + 1 < SIZE_GRID && x - i - 1 < SIZE_GRID && GET_VAL(m_cell[y + i + 1][x - i - 1]) == GET_VAL(val); i++)
		count ++;
	return (y + i + 1 < SIZE_GRID && x - i - 1 < SIZE_GRID && GET_VAL(m_cell[y + i + 1][x - i - 1]) == EMPTY_CELL ? true : false);
}

bool						CountStone::getLineNbStone(unsigned int const y, unsigned int const x, short const val, unsigned int &count) const
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

bool						CountStone::getColNbStone(unsigned int const y, unsigned int const x, short const val, unsigned int &count) const
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

bool						CountStone::getDiagLeftTopRightBottomNbStone(unsigned int const y, unsigned int const x, short const val, unsigned int &count) const
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

bool						CountStone::getDiagRightTopLeftBottomNbStone(unsigned int const y, unsigned int const x, short const val, unsigned int &count) const
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