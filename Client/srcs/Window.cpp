/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Window.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpasquer <fpasquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 22:37:45 by fpasquer          #+#    #+#             */
/*   Updated: 2018/02/06 14:35:33 by fpasquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Window.hpp"

t_color const				Window::m_color[] = {
	{1, COLOR_GREEN, COLOR_BLACK},
	{2, COLOR_RED, COLOR_BLACK}, 
	{0, 0, 0}
};

							Window::Window(void)
{
	unsigned int			i;

	initscr();
	curs_set(false);
	m_cols = COLS / 2;
	m_lines = LINES;
	try
	{
		if (COLS < MIN_COLS)
			throw Error("Window not enough larg");
		else if (LINES < MIN_LINES)
			throw Error("Window not enough hight");
		m_win_left = subwin(stdscr, LINES, COLS / 2, 0, 0);
		if ((m_win_right = subwin(stdscr, LINES, COLS / 2, 0, COLS / 2)) == NULL || m_win_left == NULL)
			throw Error("Allocation window failled");
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
	wclear(m_win_left);
	wclear(m_win_right);
	box(m_win_left, ACS_VLINE, ACS_HLINE);
	box(m_win_right, ACS_VLINE, ACS_HLINE);
	wrefresh(m_win_left);
	wrefresh(m_win_right);
	curs_set(false);
	for (i = 0; m_color[i].pair != 0; i++)
		init_pair(m_color[i].pair, m_color[i].font, m_color[i].background);
}

bool						Window::show_grid(Grid const &grid, Player const &player)
{
	unsigned int			x;
	unsigned int			y;

	if (m_lines < MIN_LINES || m_cols < MIN_COLS)
		return (false);
	x = (m_cols - SIZE_GRID * 4) / 2;
	y = (m_lines - (SIZE_GRID * 2 + 1)) / 2;
	wclear(m_win_left);
	box(m_win_left, ACS_VLINE, ACS_HLINE);
	grid.show(m_win_left, x, y, player);
	wrefresh(m_win_left);
	return (true);
	grid.show(m_win_left, x, y, player);
}

bool						Window::show(Grid const &grid, Player const &player, std::string const &key)
{
	unsigned int			i;

	this->show_grid(grid, player);
	wclear(m_win_right);
	box(m_win_right, ACS_VLINE, ACS_HLINE);
	for (i = 0; i < SIZE_BUFF && key[i] != '\0'; i++)
		mvwprintw(m_win_right, i + 1, 1, "%d", key[i]);

	mvwprintw(m_win_right, 10, 1, "x = %d", player.getX());
	mvwprintw(m_win_right, 11, 1, "y = %d", player.getY());
	wrefresh(m_win_right);
	return (true);
}

							Window::~Window(void)
{
	free(m_win_left);
	free(m_win_right);
	m_win_left = NULL;
	m_win_right = NULL;
	curs_set(true);
	endwin();
}