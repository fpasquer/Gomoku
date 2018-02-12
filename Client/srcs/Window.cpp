/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Window.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpasquer <fpasquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 22:37:45 by fpasquer          #+#    #+#             */
/*   Updated: 2018/02/12 10:05:29 by fpasquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Window.hpp"

t_color const				Window::m_color[] = {
	{1, COLOR_GREEN, COLOR_BLACK},
	{2, COLOR_RED, COLOR_BLACK}, 
	{0, 0, 0}
};

							Window::Window(void) : m_border(SIZE_GRID * 4 + 1, '-')
{
	unsigned int			i;

	initscr();
	curs_set(false);
	m_cols = COLS / 2;
	m_lines = LINES;
	try
	{
		if (m_cols < MIN_COLS)
			throw Error("Window not enough larg");
		else if (m_lines < MIN_LINES)
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
	char					c;
	unsigned int			x;
	unsigned int			y;
	unsigned int			start_x;
	unsigned int			decalage_x;
	unsigned int			mem_start_x;
	unsigned int			start_y;
	std::string				str;

	if (m_lines < MIN_LINES || m_cols < MIN_COLS)
		return (false);
	mem_start_x = start_x = (m_cols - SIZE_GRID * 4) / 2;
	start_y = (m_lines - (SIZE_GRID * 2 + 1)) / 2;
	wclear(m_win_left);
	box(m_win_left, ACS_VLINE, ACS_HLINE);
	str = m_border + "\n" + m_border;
	grid.getLastX();
	mvwprintw(m_win_left, start_y++, start_x, "%s", m_border.c_str());
	for (y = 0; y < SIZE_GRID; y++, start_y++)
	{
		for (str = "", x = 0, decalage_x = 0, start_x = mem_start_x; x < SIZE_GRID; x++)
		{
			if (grid.getValue(c, x, y) == false)
				break ;
			str += "|";
			if (player.getX() == x && player.getY() == y)
			{
				mvwprintw(m_win_left, start_y + y, start_x + decalage_x, "%s", str.c_str());
				start_x += str.size();
				wattron(m_win_left, A_REVERSE);
				mvwprintw(m_win_left, start_y + y, start_x + decalage_x, " %c ", c);
				decalage_x += 3;
				wattroff(m_win_left, A_REVERSE);
				str = "";
			}
			else if (grid.getLastX() == x && grid.getLastY() == y)
			{
				mvwprintw(m_win_left, start_y + y, start_x + decalage_x, "%s", str.c_str());
				start_x += str.size();
				wattron(m_win_left, A_UNDERLINE);
				mvwprintw(m_win_left, start_y + y, start_x + decalage_x, " %c ", c);
				decalage_x += 3;
				wattroff(m_win_left, A_UNDERLINE);
				str = "";
			}
			else
			{
				str += " ";
				str.push_back(c);
				str += " ";
			}
		}
		str += "|";
		mvwprintw(m_win_left, start_y + y, start_x + decalage_x, "%s", str.c_str());
		mvwprintw(m_win_left, start_y + y + 1, mem_start_x, "%s", m_border.c_str());
	}
	wrefresh(m_win_left);
	return (true);
}

bool						Window::show(Grid const &grid, Player_human const &player, std::string const &key)
{
	unsigned int			i;

	this->show_grid(grid, player);
	wclear(m_win_right);
	box(m_win_right, ACS_VLINE, ACS_HLINE);
	for (i = 0; i < SIZE_BUFF && key[i] != '\0'; i++)
		mvwprintw(m_win_right, i + 1, 1, "%d", key[i]);
	mvwprintw(m_win_right, 10, 1, "x = %d", player.getX());
	mvwprintw(m_win_right, 11, 1, "y = %d", player.getY());
	mvwprintw(m_win_right, 13, 1, "Time = %f", grid.get_time_spend());
	mvwprintw(m_win_right, 15, 1, "Deep = %u", player.getDeep());
	mvwprintw(m_win_right, 16, 1, "LINES = %d COLS %d", LINES, COLS);
	mvwprintw(m_win_right, 17, 1, "ONLINE %s", player.isOnline() != OFFLINE ? "Yes" : "No");
	mvwprintw(m_win_right, 18, 1, "Your turn %s", player.enable() == true ? "Yes" : "No");
	mvwprintw(m_win_right, 19, 1, "Socket player %d", player.getSockClient());
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