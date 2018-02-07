/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Grid.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpasquer <fpasquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 21:33:00 by fpasquer          #+#    #+#             */
/*   Updated: 2018/02/07 12:59:50 by fpasquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Grid.hpp"

unsigned int				Grid::m_last_x = SIZE_GRID;
unsigned int				Grid::m_last_y = SIZE_GRID;

							Grid::Grid(void)  throw() : m_border(SIZE_GRID * 4 + 1, '-'), m_time_spend(0.0), m_player2()
{
	unsigned int			x;
	unsigned int			y;

	try
	{
		for (y = 0; y < SIZE_GRID; y++)
			for (x = 0; x < SIZE_GRID; x++)
				if ((m_cell[y][x] = new Cell) == NULL)
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
			mvwprintw(win, start_y + y, start_x + x * 4 + 1, " %c ", m_cell[y][x]->getVal());
			if (player.getX() == x && player.getY() == y)
				wattroff(win, A_REVERSE);
			else if (m_last_x == x && m_last_y == y)
				wattroff(win, A_UNDERLINE);
		}
		mvwprintw(win, start_y + y, start_x + x  * 4, "|");
		mvwprintw(win, start_y + y + 1, start_x, "%s", m_border.c_str());
	}
}

bool						Grid::play_ia(Player const &ia)
{
	m_last_x = ia.getX();
	m_last_y = ia.getY();
	return (m_cell[ia.getY()][ia.getX()]->setVal(ia));
}

bool						Grid::play(Player const &player, Client const &client)
{
	unsigned int			x;
	unsigned int			y;
	unsigned int			deep;
	char					grid[SIZE_GRID][SIZE_GRID];
	char					buff[SIZE_CMD + 1];

	if (m_cell[player.getY()][player.getX()]->setVal(player) == true)
	{
		for (y = 0; y < SIZE_GRID; y++)
			for (x = 0; x < SIZE_GRID; x++)
				grid[y][x] = m_cell[y][x]->getVal();
		deep = player.getDeep();
		client.send_to_server(IA, SIZE_CMD);
		client.send_to_server(&deep, sizeof(deep));
		client.send_to_server(grid, sizeof(grid));
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

							Grid::~Grid(void)
{
	unsigned int			x;
	unsigned int			y;

	for (y = 0; y < SIZE_GRID; y++)
		for (x = 0; x < SIZE_GRID; x++)
		
		{
			delete m_cell[y][x];
			m_cell[y][x] = NULL;
		}
}