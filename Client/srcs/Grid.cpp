/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Grid.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpasquer <fpasquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 21:33:00 by fpasquer          #+#    #+#             */
/*   Updated: 2018/02/09 09:00:40 by fpasquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Grid.hpp"

unsigned int				Grid::m_last_x = SIZE_GRID;
unsigned int				Grid::m_last_y = SIZE_GRID;

							Grid::Grid(void) : m_time_spend(0.0), m_ia()
{
	unsigned int			x;
	unsigned int			y;

	for (y = 0; y < SIZE_GRID; y++)
		for (x = 0; x < SIZE_GRID; x++)
			m_cell[y][x] = EMPTY_CELL;
}

unsigned int				Grid::getLastY(void) const
{
	return (m_last_y);
}

unsigned int				Grid::getLastX(void) const
{
	return (m_last_x);
}

bool						Grid::getValue(char &val, unsigned int const x, unsigned int const y) const
{
	if (x >= SIZE_GRID || y >= SIZE_GRID)
		return (false);
	val = m_cell[y][x];
	return (true);
}

bool						Grid::play(Player_ia const &player)
{
	if (player.getX() < SIZE_GRID && player.getY() < SIZE_GRID && m_cell[player.getY()][player.getX()] == EMPTY_CELL)
	{
		m_last_x = player.getX();
		m_last_y = player.getY();
		m_cell[m_last_y][m_last_x] = player.getValue();
		return (true);
	}
	return (false);
}

bool						Grid::play(Player_human const &player)
{
	unsigned int			x;
	unsigned int			y;
	unsigned int			deep;
	char					buff[SIZE_CMD + 1];

	if (player.isEnable() == true && player.getX() < SIZE_GRID && player.getY() < SIZE_GRID && m_cell[player.getY()][player.getX()] == EMPTY_CELL)
	{
		m_cell[player.getY()][player.getX()] = player.getValue();
		if (player.isOnline() == true)
		{
			deep = player.getDeep();
			player.send_to_server(IA, SIZE_CMD);
			player.send_to_server(&deep, sizeof(deep));
			player.send_to_server(m_cell, sizeof(m_cell));
			memset(buff, 0, sizeof(buff));
			player.read_from_server(buff, SIZE_CMD);
			if (strcmp(buff, TIME_SPEND) != 0)
				return (false);
			player.read_from_server(&m_time_spend, sizeof(m_time_spend));
			player.read_from_server(&y, sizeof(y));
			player.read_from_server(&x, sizeof(x));
			m_ia.setY(y);
			m_ia.setX(x);
			this->play(m_ia);
		}
		return (true);
	}
	return (false);
}

double						Grid::get_time_spend(void) const
{
	return (m_time_spend);
}