/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FreeThree.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpasquer <fpasquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 13:23:16 by fpasquer          #+#    #+#             */
/*   Updated: 2018/02/14 19:36:31 by fpasquer         ###   ########.fr       */
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
	char					val;
	char					c;
	unsigned int			y;
	unsigned int			x;

	y = m_player.getY();
	x = m_player.getX() - 2;
	val = m_player.getValue();
	if (m_grid.getValue(c, x, y) == false || c != val)
		return (false);
	if (
			(
				m_grid.getValue(c, x + 1, y) == true &&
				c == val &&
				m_grid.getValue(c, x - 1, y) == true &&
				(
					c == EMPTY_CELL ||
					c == val
				)
			)
			||
			(
				m_grid.getValue(c, x + 1, y) == true &&
				c == EMPTY_CELL &&
				m_grid.getValue(c, x - 1, y) == true &&
				c == val &&
				m_grid.getValue(c, x - 2, y) == true &&
				(
					c == EMPTY_CELL ||
					c == val
				)
			)
		)
		return (true);
	return (false);
}

bool						FreeThree::checkFTTopLeft(void)
{
	char					val;
	char					c;
	unsigned int			y;
	unsigned int			x;

	y = m_player.getY() - 2;
	x = m_player.getX() - 2;
	val = m_player.getValue();
	if (m_grid.getValue(c, x, y) == false || c != val)
		return (false);
	if (
			(
				m_grid.getValue(c, x + 1, y + 1) == true &&
				c == val &&
				m_grid.getValue(c, x - 1, y - 1) == true &&
				(
					c == EMPTY_CELL ||
					c == val
				)
			)
			||
			(
				m_grid.getValue(c, x + 1, y + 1) == true &&
				c == EMPTY_CELL &&
				m_grid.getValue(c, x - 1, y - 1) == true &&
				c == val &&
				m_grid.getValue(c, x - 2, y - 2) == true &&
				(
					c == EMPTY_CELL ||
					c == val
				)
			)
		)
		return (true);
	return (false);
}

bool						FreeThree::checkFTTop(void)
{
	char					val;
	char					c;
	unsigned int			y;
	unsigned int			x;

	y = m_player.getY() - 2;
	x = m_player.getX();
	val = m_player.getValue();
	if (m_grid.getValue(c, x, y) == false || c != val)
		return (false);
	if (
			(
				m_grid.getValue(c, x, y + 1) == true &&
				c == val &&
				m_grid.getValue(c, x, y - 1) == true &&
				(
					c == EMPTY_CELL ||
					c == val
				)
			)
			||
			(
				m_grid.getValue(c, x, y + 1) == true &&
				c == EMPTY_CELL &&
				m_grid.getValue(c, x, y - 1) == true &&
				c == val &&
				m_grid.getValue(c, x, y - 2) == true &&
				(
					c == EMPTY_CELL ||
					c == val
				)
			)
		)
		return (true);
	return (false);
}

bool						FreeThree::checkFTRight(void)
{
	char					val;
	char					c;
	unsigned int			y;
	unsigned int			x;

	y = m_player.getY();
	x = m_player.getX() + 2;
	val = m_player.getValue();
	if (m_grid.getValue(c, x, y) == false || c != val)
		return (false);
	if (
			(
				m_grid.getValue(c, x - 1, y) == true &&
				c == val &&
				m_grid.getValue(c, x + 1, y) == true &&
				(
					c == EMPTY_CELL ||
					c == val
				)
			)
			||
			(
				m_grid.getValue(c, x - 1, y) == true &&
				c == EMPTY_CELL &&
				m_grid.getValue(c, x + 1, y) == true &&
				c == val &&
				m_grid.getValue(c, x + 2, y) == true &&
				(
					c == EMPTY_CELL ||
					c == val
				)
			)
		)
		return (true);
	return (false);
}

bool						FreeThree::checkFTTopRight(void)
{
	char					val;
	char					c;
	unsigned int			y;
	unsigned int			x;

	y = m_player.getY() - 2;
	x = m_player.getX() + 2;
	val = m_player.getValue();
	if (m_grid.getValue(c, x, y) == false || c != val)
		return (false);
	if ((m_grid.getValue(c, x + 1, y - 1) == true && c == val) ||
			(m_grid.getValue(c, x - 1, y + 1) == true && c == val))
		return (true);
	return (false);
}

bool						FreeThree::checkFTBottom(void)
{
	char					val;
	char					c;
	unsigned int			y;
	unsigned int			x;

	y = m_player.getY() + 2;
	x = m_player.getX();
	val = m_player.getValue();
	if (m_grid.getValue(c, x, y) == false || c != val)
		return (false);
	if ((m_grid.getValue(c, x, y - 1) == true && c == val &&
			m_grid.getValue(c, x, y + 1) == true && c == EMPTY_CELL) ||
			(m_grid.getValue(c, x, y + 1) == true && c == val &&
			m_grid.getValue(c, x, y - 1) == true && c == EMPTY_CELL &&
			m_grid.getValue(c, x, y + 2) == true && c == EMPTY_CELL))
		return (true);
	return (false);
}

bool						FreeThree::checkFTBottomLeft(void)
{
	char					val;
	char					c;
	unsigned int			y;
	unsigned int			x;

	y = m_player.getY() + 2;
	x = m_player.getX() - 2;
	val = m_player.getValue();
	if (m_grid.getValue(c, x, y) == false || c != val)
		return (false);
	if ((m_grid.getValue(c, x + 1, y - 1) == true && c == val) ||
			(m_grid.getValue(c, x - 1, y + 1) == true && c == val))
		return (true);
	return (false);
}

bool						FreeThree::checkFTBottomRight(void)
{
	char					val;
	char					c;
	unsigned int			y;
	unsigned int			x;

	y = m_player.getY() + 2;
	x = m_player.getX() + 2;
	val = m_player.getValue();
	if (m_grid.getValue(c, x, y) == false || c != val)
		return (false);
	if ((m_grid.getValue(c, x - 1, y - 1) == true && c == val) ||
			(m_grid.getValue(c, x + 1, y + 1) == true && c == val))
		return (true);
	return (false);
}

bool						FreeThree::checkFreeThree(void)
{
	char					c;
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