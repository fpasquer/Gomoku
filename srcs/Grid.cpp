/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Grid.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpasquer <fpasquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 21:33:00 by fpasquer          #+#    #+#             */
/*   Updated: 2018/02/06 10:45:30 by fpasquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Grid.hpp"

							Grid::Grid(void) : m_border(SIZE_GRID * 4 + 1, '-')
{
	//
	unsigned int			x;
	unsigned int			y;

	for (x = 0; x < SIZE_GRID; x++)
		for (y = 0; y < SIZE_GRID; y++)
			m_cell[x][y] = new Cell;
}

void						Grid::show(WINDOW *win, unsigned int start_x, unsigned int start_y, Player const &player) const
{
	unsigned int			x;
	unsigned int			y;

	mvwprintw(win, start_y++, start_x, "%s", m_border.c_str());
	for (y = 0; y < SIZE_GRID; y++, start_y++)
	{
		for (x = 0; x < SIZE_GRID; x++)
		{
			mvwprintw(win, start_y + y, start_x + x * 4, "|");
			if (player.getX() == x && player.getY() == y)
				wattron(win, A_REVERSE);
			mvwprintw(win, start_y + y, start_x + x * 4 + 1, " %s ", m_cell[x][y]->getVal().c_str());
			if (player.getX() == x && player.getY() == y)
				wattroff(win, A_REVERSE);
		}
		mvwprintw(win, start_y + y, start_x + x  * 4, "|");
		mvwprintw(win, start_y + y + 1, start_x, "%s", m_border.c_str());
	}
}

bool						Grid::play(Player const &player)
{
	return (m_cell[player.getX()][player.getY()]->setVal(player));
}

							Grid::~Grid(void)
{
	unsigned int			x;
	unsigned int			y;

	for (x = 0; x < SIZE_GRID; x++)
		for (y = 0; y < SIZE_GRID; y++)
		{
			delete m_cell[x][y];
			m_cell[x][y] = NULL;
		}
}