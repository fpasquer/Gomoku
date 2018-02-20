/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Window.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpasquer <fpasquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 22:37:45 by fpasquer          #+#    #+#             */
/*   Updated: 2018/02/19 09:50:20 by fpasquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Window.hpp"

t_color const				Window::m_color[] = {
	{1, COLOR_GREEN, COLOR_BLACK},
	{2, COLOR_BLACK, COLOR_RED}, 
	{0, 0, 0}
};

							Window::Window(void) : m_border(SIZE_GRID * 4 + 1, '-')
{
	unsigned int			i;

	initscr();
	start_color();
	curs_set(false);
	m_cols = COLS / 2;
	m_lines = LINES;
	try
	{
		if (m_cols < MIN_COLS)
			throw Error("Window not enough larg");
		else if (m_lines < MIN_LINES)
			throw Error("Window not enough hight");
		m_win_left = subwin(stdscr, MIN_LINES, MIN_COLS, 0, 0);
		if ((m_win_right = subwin(stdscr, MIN_LINES, MIN_COLS, 0, MIN_COLS)) == NULL || m_win_left == NULL)
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

// bool						Window::show_grid(Grid const &grid, Player_human const &player)
// {
// 	char					c;
// 	unsigned int			start_x;
// 	unsigned int			start_y;
// 	unsigned int			x;
// 	unsigned int			y;

// 	if (m_lines < MIN_LINES || m_cols < MIN_COLS)
// 		return (false);
// 	start_x = (m_cols - SIZE_GRID * 4) / 2;
// 	start_y = (m_lines - (SIZE_GRID * 2 + 1)) / 2;
// 	wclear(m_win_left);
// 	box(m_win_left, ACS_VLINE, ACS_HLINE);
// 	mvwprintw(m_win_left, start_y++, start_x, "%s", m_border.c_str());
// 	for (y = 0; y < SIZE_GRID; y++, start_y++)
// 	{
// 		for (x = 0; x < SIZE_GRID; x++)
// 		{
// 			mvwprintw(m_win_left, start_y + y, start_x + x * 4, "|");
// 			if (player.getX() == x && player.getY() == y)
// 				wattron(m_win_left, A_REVERSE);
// 			else if (grid.getLastX() == x && grid.getLastY() == y)
// 				wattron(m_win_left, A_UNDERLINE);
// 			if (grid.getValue(c, x, y) == false)
// 				break ;
// 			mvwprintw(m_win_left, start_y + y, start_x + x * 4 + 1, " %c ", c);
// 			if (player.getX() == x && player.getY() == y)
// 				wattroff(m_win_left, A_REVERSE);
// 			else if (grid.getLastX() == x && grid.getLastY() == y)
// 				wattroff(m_win_left, A_UNDERLINE);
// 		}
// 		mvwprintw(m_win_left, start_y + y, start_x + x  * 4, "|");
// 		mvwprintw(m_win_left, start_y + y + 1, start_x, "%s", m_border.c_str());
// 	}
// 	wrefresh(m_win_left);
// 	return (true);
// }

bool						Window::show_grid(Grid const &grid, Player_human const &player)
{
	short					mem;
	short					c;
	unsigned int			x;
	unsigned int			y;
	unsigned int			start_x;
	unsigned int			start_y;
	std::string				str;

	if (m_lines < MIN_LINES || m_cols < MIN_COLS)
		return (false);
	start_x = (m_cols - SIZE_GRID * 4) / 2;
	start_y = (m_lines - (SIZE_GRID * 2 + 1)) / 2;
	start_x = 1;
	start_y = 1;
	std::string				space(start_x, ' ');
//	wclear(m_win_left); a voir si on clear ou pas
	str = m_border + "\n" + space;
	for (y = 0; y < SIZE_GRID; y++)
	{
		for (x = 0; x < SIZE_GRID; x++)
		{
			if (grid.getValue(c, x, y) == false)
				return (false);
			if (player.getX() == x && player.getY() == y)
			{
				str += "|";
				mvwprintw(m_win_left, start_y, start_x, "%s", str.c_str());
				wattron(m_win_left, (mem = (GET_PERM(c) & player.getUnpossible())) != 0 ? COLOR_PAIR(2) : A_REVERSE);
				start_y = start_y + y * 2 + 1;
				start_x = start_x + 1 + x * (3 + 1);
				mvwprintw(m_win_left, start_y, start_x, " %c ", GET_VAL(c));
				start_x += 3;
				wattroff(m_win_left, mem != 0 ? COLOR_PAIR(2) : A_REVERSE);
				str.erase();
			}
			else
			{
				str += "| ";
				str.push_back(GET_VAL(c));
				str += " ";
			}
		}
		str += "|\n" + space + m_border + "\n" + space;
	}
	mvwprintw(m_win_left, start_y, start_x, "%s", str.c_str());
	box(m_win_left, ACS_VLINE, ACS_HLINE);
	wrefresh(m_win_left);
	return (true);
}

bool						Window::show(Grid const &grid, Player_human const &player, std::string const &key)
{
	unsigned int			i;
	unsigned int			count;

	this->show_grid(grid, player);
	wclear(m_win_right);
	box(m_win_right, ACS_VLINE, ACS_HLINE);
	for (i = 0; i < SIZE_BUFF && key[i] != '\0'; i++)
		mvwprintw(m_win_right, i + 1, 1, "%d", key[i]);
	mvwprintw(m_win_right, 10, 1, "x = %d", player.getX());
	mvwprintw(m_win_right, 11, 1, "y = %d", player.getY());
	mvwprintw(m_win_right, 13, 1, "Time = %f", grid.get_time_spend());
	mvwprintw(m_win_right, 15, 1, "Deep = %u", player.getDeep());
	mvwprintw(m_win_right, 16, 1, "ONLINE %s", player.isOnline() != OFFLINE ? "Yes" : "No");
	mvwprintw(m_win_right, 18, 1, "Your turn %s", player.enable() == true ? "Yes" : "No");
	mvwprintw(m_win_right, 19, 1, "Playe1 Capture(s) : %s", player.getCapture().c_str());
	mvwprintw(m_win_right, 20, 1, "Playe2 Capture(s) : %s", grid.getCaptureIa().c_str());
	grid.getLineNbStone(player, count);
	mvwprintw(m_win_right, 21, 1, "Player aligne line : %u", count);
	grid.getColNbStone(player, count);
	mvwprintw(m_win_right, 22, 1, "Player aligne col : %u", count);
	grid.getDiagLeftTopRightBottomNbStone(player, count);
	mvwprintw(m_win_right, 23, 1, "Player Left top right bottom col : %u", count);
	grid.getDiagRightTopLeftBottomNbStone(player, count);
	mvwprintw(m_win_right, 24, 1, "Player Right top left bottom col : %u", count);
	wrefresh(m_win_right);
	return (true);
}

int							Window::disconnected(void) const
{
	clear();
	printw("Your Opponnent is go on. Press any key to leave the program");
	getch();
	return (0);
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