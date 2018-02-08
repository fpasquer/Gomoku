/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Grid.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpasquer <fpasquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 21:33:00 by fpasquer          #+#    #+#             */
/*   Updated: 2018/02/08 08:35:57 by fpasquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Grid.hpp"

unsigned int				Grid::m_last_x = SIZE_GRID;
unsigned int				Grid::m_last_y = SIZE_GRID;

							Grid::Grid(void) : m_time_spend(0.0), m_player2()
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

bool						Grid::play_ia(Player const &ia)
{
	if (ia.getX() >= SIZE_GRID || ia.getY() >= SIZE_GRID)
		return (false);
	m_last_x = ia.getX();
	m_last_y = ia.getY();
	m_cell[m_last_y][m_last_x] = ia.getValue();
	return (true);
}

bool						Grid::play(Player const &player, Client const &client)
{
	unsigned int			x;
	unsigned int			y;
	unsigned int			deep;
	char					buff[SIZE_CMD + 1];

	if (player.getX() < SIZE_GRID && player.getY() < SIZE_GRID && m_cell[player.getY()][player.getX()] == EMPTY_CELL)
	{
		m_cell[player.getY()][player.getX()] = player.getValue();
		deep = player.getDeep();
		client.send_to_server(IA, SIZE_CMD);
		client.send_to_server(&deep, sizeof(deep));
		client.send_to_server(m_cell, sizeof(m_cell));
		memset(buff, 0, sizeof(buff));
		client.read_from_server(buff, SIZE_CMD);
		if (strcmp(buff, TIME_SPEND) == 0)
		{
			client.read_from_server(&m_time_spend, sizeof(m_time_spend));
			client.read_from_server(&y, sizeof(y));
			client.read_from_server(&x, sizeof(x));
			m_player2.setY(y);
			m_player2.setX(x);
			this->play_ia(m_player2);
		}
		return (true);
	}
	return (false);
}

double						Grid::get_time_spend(void) const
{
	return (m_time_spend);
}