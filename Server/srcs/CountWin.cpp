/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CountWin.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpasquer <fpasquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 12:01:14 by fpasquer          #+#    #+#             */
/*   Updated: 2018/02/26 12:35:58 by fpasquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/CountWin.hpp"

bool						CountWin::countLeft
		(short const grid[SIZE_GRID][SIZE_GRID], unsigned int const y, unsigned int const x, short const val, unsigned int &count)
/*
DESCRIPTION:
	count the number of stone on the left site with the value val
RETURN VALUES:
	return true if the next stone after the last on left is empty, else false
*/
{
	unsigned int			i;

	for (count = 0, i = 0; x - i - 1 < SIZE_GRID && GET_VAL(grid[y][x - i - 1]) == GET_VAL(val); i++)
		count ++;
	return (x - i - 1 < SIZE_GRID && GET_VAL(grid[y][x - i - 1]) == EMPTY_CELL ? true : false);
}

bool						CountWin::countRight
		(short const grid[SIZE_GRID][SIZE_GRID], unsigned int const y, unsigned int const x, short const val, unsigned int &count)
/*
DESCRIPTION:
	count the number of stone on the right site with the value val
RETURN VALUES:
	return true if the next stone after the last on right is empty, else false
*/
{
	unsigned int			i;

	for (count = 0, i = 0; x + i + 1 < SIZE_GRID && GET_VAL(grid[y][x + i + 1]) == GET_VAL(val); i++)
		count ++;
	return (x + i + 1 < SIZE_GRID && GET_VAL(grid[y][x + i + 1]) == EMPTY_CELL ? true : false);
}

bool						CountWin::countTop
		(short const grid[SIZE_GRID][SIZE_GRID], unsigned int const y, unsigned int const x, short const val, unsigned int &count)
/*
DESCRIPTION:
	count the number of stone on the top site with the value val
RETURN VALUES:
	return true if the next stone after higher is empty, else false
*/
{
	unsigned int			i;

	for (count = 0, i = 0; y - i - 1 < SIZE_GRID && grid[y - i - 1][x] == GET_VAL(val); i++)
		count ++;
	return (y - i - 1 < SIZE_GRID && GET_VAL(grid[y - i - 1][x]) == EMPTY_CELL ? true : false);
}

bool						CountWin::countBottom
		(short const grid[SIZE_GRID][SIZE_GRID], unsigned int const y, unsigned int const x, short const val, unsigned int &count)
/*
DESCRIPTION:
	count the number of stone on the bottom site with the value val
RETURN VALUES:
	return true if the next stone after lower is empty, else false
*/
{
	unsigned int			i;

	for (count = 0, i = 0; y + i + 1 < SIZE_GRID && GET_VAL(grid[y + i + 1][x]) == GET_VAL(val); i++)
		count ++;
	return (y + i + 1 < SIZE_GRID && GET_VAL(grid[y + i + 1][x]) == EMPTY_CELL ? true : false);
}

bool						CountWin::countLeftTop
		(short const grid[SIZE_GRID][SIZE_GRID], unsigned int const y, unsigned int const x, short const val, unsigned int &count)
/*
DESCRIPTION:
	count the number of stone on the left top site with the value val
RETURN VALUES:
	return true if the next stone after last one is empty, else false
*/
{
	unsigned int			i;

	for (count = 0, i = 0; y - i - 1 < SIZE_GRID && x - i - 1 < SIZE_GRID && GET_VAL(grid[y - i - 1][x - i - 1]) == GET_VAL(val); i++)
		count ++;
	return (y - i - 1 < SIZE_GRID && x - i - 1 < SIZE_GRID && GET_VAL(grid[y - i - 1][x - i - 1]) == EMPTY_CELL ? true : false);
}

bool						CountWin::countRightBottom
		(short const grid[SIZE_GRID][SIZE_GRID], unsigned int const y, unsigned int const x, short const val, unsigned int &count)
/*
DESCRIPTION:
	count the number of stone on the right bottom site with the value val
RETURN VALUES:
	return true if the next stone after last one is empty, else false
*/
{
	unsigned int			i;

	for (count = 0, i = 0; y + i + 1 < SIZE_GRID && x + i + 1 < SIZE_GRID && GET_VAL(grid[y + i + 1][x + i + 1]) == GET_VAL(val); i++)
		count ++;
	return (y + i + 1 < SIZE_GRID && x + i + 1 < SIZE_GRID && GET_VAL(grid[y + i + 1][x + i + 1]) == EMPTY_CELL ? true : false);
}

bool						CountWin::countTopRight
		(short const grid[SIZE_GRID][SIZE_GRID], unsigned int const y, unsigned int const x, short const val, unsigned int &count)
/*
DESCRIPTION:
	count the number of stone on the top right site with the value val
RETURN VALUES:
	return true if the next stone after last one is empty, else false
*/
{
	unsigned int			i;

	for (count = 0, i = 0; y - i - 1 < SIZE_GRID && x + i + 1 < SIZE_GRID && GET_VAL(grid[y - i - 1][x + i + 1]) == GET_VAL(val); i++)
		count ++;
	return (y - i - 1 < SIZE_GRID && x + i + 1 < SIZE_GRID && GET_VAL(grid[y - i - 1][x + i + 1]) == EMPTY_CELL ? true : false);
}

bool						CountWin::countBottomLeft
		(short const grid[SIZE_GRID][SIZE_GRID], unsigned int const y, unsigned int const x, short const val, unsigned int &count)
/*
DESCRIPTION:
	count the number of stone on the bottom left site with the value val
RETURN VALUES:
	return true if the next stone after last one is empty, else false
*/
{
	unsigned int			i;

	for (count = 0, i = 0; y + i + 1 < SIZE_GRID && x - i - 1 < SIZE_GRID && GET_VAL(grid[y + i + 1][x - i - 1]) == GET_VAL(val); i++)
		count ++;
	return (y + i + 1 < SIZE_GRID && x - i - 1 < SIZE_GRID && GET_VAL(grid[y + i + 1][x - i - 1]) == EMPTY_CELL ? true : false);
}