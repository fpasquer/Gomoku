/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FreeThree.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpasquer <fpasquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 13:23:16 by fpasquer          #+#    #+#             */
/*   Updated: 2018/02/18 09:52:14 by fpasquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/FreeThree.hpp"

FreeThree::t_checkFreet const
							FreeThree::m_func[] = {
	{&FreeThree::checkFTTop},
	{&FreeThree::checkFTLeft},
	{&FreeThree::checkFTRight},
	{&FreeThree::checkFTBottom},
	{&FreeThree::checkFTTopLeft},
	{&FreeThree::checkFTTopRight},
	{&FreeThree::checkFTBottomRight},
	{&FreeThree::checkFTBottomLeft},
	{NULL}
};

							FreeThree::FreeThree(Grid const &grid, Player const &player) : m_grid(grid), m_player(player)
{
	
}

bool						FreeThree::checkFTLeft(void)
{
	short					val;
	short					c;
	unsigned int			y;
	unsigned int			x;
	unsigned int			count;

	y = m_player.getY();
	x = m_player.getX() - 2;
	val = m_player.getValue();
	if (m_grid.getValue(c, x, y) == false || c != val)
		return (false);
	//m_grid.getLineNbStone(m_player, count);
	// if (count >= NB_STONE_WIN)
	// 	return (false);
	count = 0;
	if (m_grid.countLeft(y, m_player.getX(), val, count) == true && count >= 2)
		return (!(this->checkFTRight()));
	if (m_grid.getValue(c, x + 1, y) == true && c == EMPTY_CELL &&
			m_grid.countLeft(y, x, val, count) == true && count >= 1)
		return (!(this->checkFTRight()));
	return (false);
}

bool						FreeThree::checkFTTopLeft(void)
{
	short					val;
	short					c;
	unsigned int			y;
	unsigned int			x;
	unsigned int			count;

	y = m_player.getY() - 2;
	x = m_player.getX() - 2;
	val = m_player.getValue();
	if (m_grid.getValue(c, x, y) == false || c != val)
		return (false);
	// m_grid.getDiagLeftTopRightBottomNbStone(m_player, count);
	// if (count >= NB_STONE_WIN)
	// 	return (false);
	count = 0;
	if (m_grid.countLeftTop(m_player.getY(), m_player.getX(), val, count) == true && count >= 2)
		return (true);
	if (m_grid.getValue(c, x + 1, y + 1) == true && c == EMPTY_CELL &&
			m_grid.countLeftTop(y, x, val, count) == true && count >= 1)
		return (true);
	return (false);
}

bool						FreeThree::checkFTTop(void)
{
	short					val;
	short					c;
	unsigned int			y;
	unsigned int			x;
	unsigned int			count;

	y = m_player.getY() - 2;
	x = m_player.getX();
	val = m_player.getValue();
	if (m_grid.getValue(c, x, y) == false || c != val)
		return (false);
	// m_grid.getColNbStone(m_player, count);
	// if (count >= NB_STONE_WIN)
	// 	return (false);
	count = 0;
	if (m_grid.countTop(m_player.getY(), x, val, count) == true && count >= 2)
		return (true);
	if (m_grid.getValue(c, x, y + 1) == true && c == EMPTY_CELL &&
			m_grid.countTop(y, x, val, count) == true && count >= 1)
		return (true);
	return (false);
}

bool						FreeThree::checkFTRight(void)
{
	short					val;
	short					c;
	unsigned int			y;
	unsigned int			x;
	unsigned int			count;

	y = m_player.getY();
	x = m_player.getX() + 2;
	val = m_player.getValue();
	if (m_grid.getValue(c, x, y) == false || c != val)
		return (false);
	// m_grid.getLineNbStone(m_player, count);
	// if (count >= NB_STONE_WIN)
	// 	return (false);
	count = 0;
	if (m_grid.countRight(y, m_player.getX(), val, count) == true && count >= 2)
		return (true);
	if (m_grid.getValue(c, x - 1, y) == true && c == EMPTY_CELL &&
			m_grid.countRight(y, x,val, count) == true && count >= 1)
		return (true);
	return (false);
}

bool						FreeThree::checkFTTopRight(void)
{
	short					val;
	short					c;
	unsigned int			y;
	unsigned int			x;
	unsigned int			count;

	y = m_player.getY() - 2;
	x = m_player.getX() + 2;
	val = m_player.getValue();
	if (m_grid.getValue(c, x, y) == false || c != val)
		return (false);
	// m_grid.getDiagRightTopLeftBottomNbStone(m_player, count);
	// if (count >= NB_STONE_WIN)
	// 	return (false);
	count = 0;
	if (m_grid.countTopRight(m_player.getY(), m_player.getX(), val, count) == true && count >= 2)
		return (true);
	if (m_grid.getValue(c, x - 1, y + 1) == true && c == EMPTY_CELL &&
			m_grid.countTopRight(y, x, val, count) ==true && count >= 1)
		return (true);
	return (false);
}

bool						FreeThree::checkFTBottom(void)
{
	short					val;
	short					c;
	unsigned int			y;
	unsigned int			x;
	unsigned int			count;

	y = m_player.getY() + 2;
	x = m_player.getX();
	val = m_player.getValue();
	if (m_grid.getValue(c, x, y) == false || c != val)
		return (false);
	// m_grid.getColNbStone(m_player, count);
	// if (count >= NB_STONE_WIN)
	// 	return (false);
	count = 0;
	if (m_grid.countBottom(m_player.getY(), x, val, count) == true && count >= 2)
		return (true);
	if (m_grid.getValue(c, x, y - 1) == true && c == EMPTY_CELL &&
			m_grid.countBottom(y, x, val, count) == true && count >= 1)
		return (true);
	return (false);
}

bool						FreeThree::checkFTBottomLeft(void)
{
	short					val;
	short					c;
	unsigned int			y;
	unsigned int			x;
	unsigned int			count;

	y = m_player.getY() + 2;
	x = m_player.getX() - 2;
	val = m_player.getValue();
	if (m_grid.getValue(c, x, y) == false || c != val)
		return (false);
	// m_grid.getDiagRightTopLeftBottomNbStone(m_player, count);
	// if (count >= NB_STONE_WIN)
	// 	return (false);
	count = 0;
	if (m_grid.countBottomLeft(m_player.getY(), m_player.getX(), val, count) == true && count >= 2)
		return (true);
	if (m_grid.getValue(c, x + 1, y - 1) == true && c == EMPTY_CELL &&
			m_grid.countBottomLeft(y, x, val, count) == true && count >= 1)
		return (true);
	return (false);
}

bool						FreeThree::checkFTBottomRight(void)
{
	short					val;
	short					c;
	unsigned int			y;
	unsigned int			x;
	unsigned int			count;

	y = m_player.getY() + 2;
	x = m_player.getX() + 2;
	val = m_player.getValue();
	if (m_grid.getValue(c, x, y) == false || c != val)
		return (false);
	// m_grid.getDiagLeftTopRightBottomNbStone(m_player, count);
	// if (count >= NB_STONE_WIN)
	// 	return (false);
	count = 0;
	if (m_grid.countRightBottom(m_player.getY(), m_player.getX(), val, count) == true && count >= 2)
		return (true);
	if (m_grid.getValue(c, x - 1, y - 1) == true && c == EMPTY_CELL &&
			m_grid.countRightBottom(y, x, val, count) == true && count >= 1)
		return (true);
	return (false);
}

bool						FreeThree::checkFreeThree(void)
{
	short					c;
	unsigned int			i;
	unsigned int			count;

	if (m_grid.getValue(c, m_player.getX(), m_player.getY()) == false ||
			c != EMPTY_CELL)
		return (false);
	for (i = 0, count = 0; m_func[i].f != NULL; i++)
		if (((*this).*m_func[i].f)() == true)
			count++;
	return (count >= 2 ? true : false);
}