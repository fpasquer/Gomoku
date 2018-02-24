/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Window.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpasquer <fpasquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 22:37:45 by fpasquer          #+#    #+#             */
/*   Updated: 2018/02/24 11:03:31 by fpasquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Window.hpp"

t_color const				Window::m_color[] = {
	{1, COLOR_GREEN, COLOR_BLACK},
	{2, COLOR_BLACK, COLOR_RED}, 
	{0, 0, 0}
};

void						Window::write_title(void) const
{
	wclear(m_win_title);
	mvwprintw(m_win_title, 1, 0, "      ********    ********    ***  ***    ********    **    **    **    **\n      ********    ********    ********    ********    **   **     **    **\n      **    **    **    **    ** ** **    **    **    **  **      **    **\n      **          **    **    **    **    **    **    ** **       **    **\n      **  ****    **    **    **    **    **    **    ****        **    **\n      **  ****    **    **    **    **    **    **    ****        **    **\n      **    **    **    **    **    **    **    **    ** **       **    **\n      **    **    **    **    **    **    **    **    **  **      **    **\n      ********    ********    **    **    ********    **   **     ********\n      ********    ********    **    **    ********    **    **    ********");
	box(m_win_title, ACS_VLINE, ACS_HLINE);
	wrefresh(m_win_title);
}

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
		m_win_title = subwin(stdscr, HEIGHT_TITLE, MIN_COLS, 0, MIN_COLS);
		if ((m_win_right = subwin(stdscr, MIN_LINES - HEIGHT_TITLE, MIN_COLS, HEIGHT_TITLE, MIN_COLS)) == NULL || m_win_left == NULL)
			throw Error("Allocation window failled");
		if ((m_win_refresh_each_loop = subwin(stdscr, HEIGHT_TITLE, MIN_COLS, HEIGHT_TITLE, MIN_COLS)) == NULL)
			throw Error("Allocation window failled 2");
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
	wclear(m_win_refresh_each_loop);
	box(m_win_left, ACS_VLINE, ACS_HLINE);
	box(m_win_right, ACS_VLINE, ACS_HLINE);
	wrefresh(m_win_left);
	wrefresh(m_win_right);
	this->write_title();
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

void						Window::show_each_loop(Grid const &grid,Player_human const &player, std::string const &key) const
{
	char					buff[4];
	unsigned int			i;
	unsigned int			count_line;
	unsigned int			count_col;
	unsigned int			count_dlr;
	unsigned int			count_drl;
	std::string				keys = "";

	for (i = 0; i < SIZE_BUFF && key[i] != '\0'; i++)
	{
		snprintf(buff, sizeof(buff), "%d", key[i]);
		keys.push_back(' ');
		keys += buff;
	}
	count_line = (grid.getLineNbStone(player.getY(), player.getX(), player.getValue(), count_line) == false) ? 1 : count_line;
	count_col = (grid.getColNbStone(player.getY(), player.getX(), player.getValue(), count_col) == false) ? 1 : count_col;
	count_dlr = (grid.getDiagLeftTopRightBottomNbStone(player.getY(), player.getX(), player.getValue(), count_dlr) == false) ? 1 : count_dlr;
	count_drl = (grid.getDiagRightTopLeftBottomNbStone(player.getY(), player.getX(), player.getValue(), count_drl) == false) ? 1 : count_drl;
	mvwprintw(m_win_refresh_each_loop, 1, 1, "Player y : %3d\n Player x : %3d\n Turn     : %3c\n\n Number stone LINE : %5u\n Number stone COL  : %5u\n Number Stone DLR  : %5u\n Number Stone DRL  : %5u\n\n Key :%20s",
			player.getY(), player.getX(), GET_VAL(player.getValue()), count_line, count_col, count_dlr, count_drl, keys.c_str());
	box(m_win_refresh_each_loop, ACS_VLINE, ACS_HLINE);
	wrefresh(m_win_refresh_each_loop);

}

bool						Window::show(Grid const &grid, Player_human const &player, std::string const &key, Player_human const &player_oder)
{

	this->show_grid(grid, player);
	this->show_each_loop(grid, player, key);
	if (player.isOnline() == OFFLINE)
	{
		if (GET_VAL(player.getValue()) == PLAYER1)
			mvwprintw(m_win_right, 13, 1, "Time  : %9.5f\n Depth : %3u\n\n Playe1 Capture(s) : %10s\n Playe2 Capture(s) : %10s",
					grid.get_time_spend(), player.getDeep(), player.getCapture().c_str(), player_oder.getCapture().c_str());
		else
			mvwprintw(m_win_right, 13, 1, "Time  : %9.5f\n Depth : %3u\n\n Playe1 Capture(s) : %10s\n Playe2 Capture(s) : %10s",
					grid.get_time_spend(), player.getDeep(), player_oder.getCapture().c_str(), player.getCapture().c_str());
	}
	else
		mvwprintw(m_win_right, 13, 1, "Time  : %9.5f\n Depth : %3u\n\n Playe1 Capture(s) : %10s\n Playe2 Capture(s) : %10s",
			grid.get_time_spend(), player.getDeep(), player.getCapture().c_str(), grid.getCaptureIa().c_str());
	box(m_win_right, ACS_VLINE, ACS_HLINE);	
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
	free(m_win_title);
	free(m_win_refresh_each_loop);
	m_win_refresh_each_loop = NULL;
	m_win_title = NULL;
	m_win_left = NULL;
	m_win_right = NULL;
	curs_set(true);
	endwin();
}