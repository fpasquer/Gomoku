/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Grid_countStone.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpasquer <fpasquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 20:17:29 by fpasquer          #+#    #+#             */
/*   Updated: 2018/02/18 09:52:53 by fpasquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Grid.hpp"

bool						Grid::countLeft(unsigned int const y, unsigned int const x, short const val, unsigned int &count) const
{
	unsigned int			i;

	for (count = 0, i = 0; x - i - 1 < SIZE_GRID && m_cell[y][x - i - 1] == val; i++)
		count ++;
	return (x - i - 1 < SIZE_GRID && m_cell[y][x - i - 1] == EMPTY_CELL ? true : false);
}

bool						Grid::countLeft(Player const &player, unsigned int &count) const
/*
DESCRIPTION:
	count the number of stone on the left site of the player
RETURN VALUES:
	return true if the next stone after the last on left of the player is empty, else false
*/
{
	return (this->countLeft(player.getY(), player.getX(), player.getValue(), count));
}

bool						Grid::countRight(unsigned int const y, unsigned int const x, short const val, unsigned int &count) const
{
	unsigned int			i;

	for (count = 0, i = 0; x + i + 1 < SIZE_GRID && m_cell[y][x + i + 1] == val; i++)
		count ++;
	return (x + i + 1 < SIZE_GRID && m_cell[y][x + i + 1] == EMPTY_CELL ? true : false);
}

bool						Grid::countRight(Player const &player, unsigned int &count) const
/*
DESCRIPTION:
	count the number of stone on the right site of the player
RETURN VALUES:
	return true if the next stone after the last on right of the player is empty, else false
*/
{
	return (this->countRight(player.getY(), player.getX(), player.getValue(), count));
}

bool						Grid::countTop(unsigned int const y, unsigned int const x, short const val, unsigned int &count) const
{
	unsigned int			i;

	for (count = 0, i = 0; y - i - 1 < SIZE_GRID && m_cell[y - i - 1][x] == val; i++)
		count ++;
	return (y - i - 1 < SIZE_GRID && m_cell[y - i - 1][x] == EMPTY_CELL ? true : false);
}

bool						Grid::countTop(Player const &player, unsigned int &count) const
{
	return (this->countTop(player.getY(), player.getX(), player.getValue(), count));
}

bool						Grid::countBottom(unsigned int const y, unsigned int const x, short const val, unsigned int &count) const
{
	unsigned int			i;

	for (count = 0, i = 0; y + i + 1 < SIZE_GRID && m_cell[y + i + 1][x] == val; i++)
		count ++;
	return (y + i + 1 < SIZE_GRID && m_cell[y + i + 1][x] == EMPTY_CELL ? true : false);
}

bool						Grid::countBottom(Player const &player, unsigned int &count) const
{
	return (this->countBottom(player.getY(), player.getX(), player.getValue(), count));
}

bool						Grid::countLeftTop(unsigned int const y, unsigned int const x, short const val, unsigned int &count) const
{
	unsigned int			i;

	for (count = 0, i = 0; y - i - 1 < SIZE_GRID && x - i - 1 < SIZE_GRID && m_cell[y - i - 1][x - i - 1] == val; i++)
		count ++;
	return (y - i - 1 < SIZE_GRID && x - i - 1 < SIZE_GRID && m_cell[y - i - 1][x - i - 1] == EMPTY_CELL ? true : false);
}

bool						Grid::countLeftTop(Player const &player, unsigned int &count) const
{
	return (this->countLeftTop(player.getY(), player.getX(), player.getValue(), count));
}

bool						Grid::countRightBottom(unsigned int const y, unsigned int const x, short const val, unsigned int &count) const
{
	unsigned int			i;

	for (count = 0, i = 0; y + i + 1 < SIZE_GRID && x + i + 1 < SIZE_GRID && m_cell[y + i + 1][x + i + 1] == val; i++)
		count ++;
	return (y + i + 1 < SIZE_GRID && x + i + 1 < SIZE_GRID && m_cell[y + i + 1][x + i + 1] == EMPTY_CELL ? true : false);
}

bool						Grid::countRightBottom(Player const &player, unsigned int &count) const
{
	return (this->countRightBottom(player.getY(), player.getX(), player.getValue(), count));
}

bool						Grid::countTopRight(unsigned int const y, unsigned int const x, short const val, unsigned int &count) const
{
	unsigned int			i;

	for (count = 0, i = 0; y - i - 1 < SIZE_GRID && x + i + 1 < SIZE_GRID && m_cell[y - i - 1][x + i + 1] == val; i++)
		count ++;
	return (y - i - 1 < SIZE_GRID && x + i + 1 < SIZE_GRID && m_cell[y - i - 1][x + i + 1] == EMPTY_CELL ? true : false);
}

bool						Grid::countTopRight(Player const &player, unsigned int &count) const
{
	return (this->countTopRight(player.getY(), player.getX(), player.getValue(), count));
}

bool						Grid::countBottomLeft(unsigned int const y, unsigned int const x, short const val, unsigned int &count) const
{
	unsigned int			i;

	for (count = 0, i = 0; y + i + 1 < SIZE_GRID && x - i - 1 < SIZE_GRID && m_cell[y + i + 1][x - i - 1] == val; i++)
		count ++;
	return (y + i + 1 < SIZE_GRID && x - i - 1 < SIZE_GRID && m_cell[y + i + 1][x - i - 1] == EMPTY_CELL ? true : false);
}

bool						Grid::countBottomLeft(Player const &player, unsigned int &count) const
{
	return (this->countBottomLeft(player.getY(), player.getX(), player.getValue(), count));
}

bool						Grid::getLineNbStone(Player const &player, unsigned int &count) const
{
	bool					left_end;
	bool					right_end;
	unsigned int			count_left = 0;
	unsigned int			count_right = 0;

	left_end = this->countLeft(player, count_left);
	right_end = this->countRight(player, count_right);
	count = count_left + count_right + 1;
	return (left_end == true && right_end == true ? true : false);
}

bool						Grid::getColNbStone(Player const &player, unsigned int &count) const
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

	above_end = this->countTop(player, count_above);
	below_end = this->countBottom(player, count_below);
	count = count_above + count_below + 1;
	return (above_end == true && below_end == true ? true : false);
}

bool						Grid::getDiagLeftTopRightBottomNbStone(Player const &player, unsigned int &count) const
{
	bool					left_end;
	bool					right_end;
	unsigned int			count_left = 0;
	unsigned int			count_right = 0;

	left_end = this->countLeftTop(player, count_left);
	right_end = this->countRightBottom(player, count_right);
	count = count_right + count_left + 1;
	return (left_end == true && right_end == true ? true : false);
}

bool						Grid::getDiagRightTopLeftBottomNbStone(Player const &player, unsigned int &count) const
{
	bool					left_end;
	bool					right_end;
	unsigned int			count_left = 0;
	unsigned int			count_right = 0;

	left_end = this->countBottomLeft(player, count_left);
	right_end = this->countTopRight(player, count_right);
	count = count_left + count_right + 1;
	return (left_end == true && right_end == true ? true : false);
}