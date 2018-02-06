/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Grid.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpasquer <fpasquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 21:33:00 by fpasquer          #+#    #+#             */
/*   Updated: 2018/02/06 14:43:44 by fpasquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Grid.hpp"

unsigned int				Grid::m_last_x = SIZE_GRID;
unsigned int				Grid::m_last_y = SIZE_GRID;

							Grid::Grid(void)  throw() : m_border(SIZE_GRID * 4 + 1, '-')
{
	unsigned int			x;
	unsigned int			y;

	try
	{
		for (x = 0; x < SIZE_GRID; x++)
			for (y = 0; y < SIZE_GRID; y++)
				if ((m_cell[x][y] = new Cell) == NULL)
					throw Error("Allocation Cell failled");
	}
	catch (std::exception const&e)
	{
		clear();
		printw("%s", e.what());
		getch();
		curs_set(true);
		endwin();
		exit(-1);
	}
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
			else if (m_last_x == x && m_last_y == y)
				wattron(win, A_UNDERLINE);
			mvwprintw(win, start_y + y, start_x + x * 4 + 1, " %s ", m_cell[x][y]->getVal().c_str());
			if (player.getX() == x && player.getY() == y)
				wattroff(win, A_REVERSE);
			else if (m_last_x == x && m_last_y == y)
				wattroff(win, A_UNDERLINE);
		}
		mvwprintw(win, start_y + y, start_x + x  * 4, "|");
		mvwprintw(win, start_y + y + 1, start_x, "%s", m_border.c_str());
	}
}

bool						Grid::play(Player const &player)
{
	if (m_cell[player.getX()][player.getY()]->setVal(player) == true)
	{
		m_last_x = player.getX();
		m_last_y = player.getY();
		return (true);
	}
	return (false);
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